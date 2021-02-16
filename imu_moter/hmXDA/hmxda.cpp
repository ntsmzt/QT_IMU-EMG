#include "hmxda.h"
#include <QDebug>

static MetaTypeInitializer metaTypeInitializer; // 注册类型，使该类型可以在 SIGANL\SLOT 机制中传递

//------------------------------------------------------------------------------
// masterCallback
//------------------------------------------------------------------------------
std::set<XsDeviceId> masterCallback::getConnectedMTws()
{
    return m_connectedMTws;
}

void masterCallback::onConnectivityChanged(XsDevicePtr device, XsConnectivityState state)
{
    if (state == XCS_Wireless) {
        QMutexLocker locker(&m_mutex);
        m_connectedMTws.insert(device->deviceId());
    }
    else {
        QMutexLocker locker(&m_mutex);
        m_connectedMTws.erase(device->deviceId());
    }

    quint32 id = device->deviceId().toInt();
    switch (state)
    {
    case XCS_Disconnected:		// Sensor断开连接
        emit mtwDisconnected(id);
        break;
    case XCS_Rejected:			/*!< Device has been rejected and is disconnected, only limited informational functionality is available. */
        //emit mtwRejected(id);
        break;
    case XCS_PluggedIn:			/*!< Device is connected through a cable. */
        //emit mtwPluggedIn(device->deviceId());
        break;
    case XCS_Wireless:			// Sensor连接
        emit mtwWireless(id);
        break;
    case XCS_File:				/*!< Device is reading from a file. */
        //emit mtwFile(id);
        break;
    case XCS_Unknown:			/*!< Device is in an unknown state. */
        break;
    }
}

void masterCallback::onProgressUpdated(XsDevice* dev, int current, int total, const XsString *identifier)
{
    QString flag = QString(identifier->toStdString().c_str());
    if(flag=="Flushing")
        emit flushProgress(current,total);
    else if(identifier->endsWith(".mtb"))
        emit loadFileProgress(current,total);
}

void masterCallback::onDeviceStateChanged(XsDevicePtr device, XsDeviceState newState, XsDeviceState oldState)
{
    if(device->isMasterDevice())
        emit stateChanged(newState,oldState);
}



//------------------------------------------------------------------------------
// mtwCallback
//------------------------------------------------------------------------------
void mtwCallback::onLiveDataAvailable(XsDevicePtr dev, const XsDataPacket* packet)
{
    assert(dev != 0 && packet != 0);
    quint64 timestamp = packet->timeOfArrival().msTime();
    XsQuaternion quater = packet->orientationQuaternion();
    XsCalibratedData  d = packet->calibratedData();

    hmQuaternion Q;
    Q.q0 = quater.w();
    Q.q1 = quater.x();
    Q.q2 = quater.y();
    Q.q3 = quater.z();

    hmVector acc;
    XsVector3 a = d.m_acc;
    acc.x = a[0];
    acc.y = a[1];
    acc.z = a[2];

    hmVector gyr;
    XsVector3 g = d.m_gyr;
    gyr.x = g[0];
    gyr.y = g[1];
    gyr.z = g[2];

    hmVector mag;
    XsVector3 m = d.m_mag;
    mag.x = m[0];
    mag.y = m[1];
    mag.z = m[2];

    int rssi = packet->rssi();
    quint32 id = dev->deviceId().toInt();

    hmData data(id,Q,acc,gyr,mag,batteryLevel,rssi,timestamp);

    emit dataAvailable(data);
}

void mtwCallback::onInfoResponse(XsDevice* dev, XsInfoRequest request)
{
    assert(dev != 0);

    if (request == XIR_BatteryLevel)
        batteryLevel = dev->batteryLevel();
}

//------------------------------------------------------------------------------
// hmXDA
//------------------------------------------------------------------------------
hmXDA::hmXDA(QObject *parent) : QObject(parent)
{
    state = Idle;
    connect(&wirelessMasterCallback,SIGNAL(mtwDisconnected(quint32)),this,SLOT(handleMtwDisconnected(quint32)));
    connect(&wirelessMasterCallback,SIGNAL(mtwWireless(quint32)),this,SLOT(handleMtwWireless(quint32)));
    connect(&wirelessMasterCallback,SIGNAL(stateChanged(XsDeviceState,XsDeviceState)),this,SLOT(handleMasterStateChanged(XsDeviceState,XsDeviceState)));
    connect(&wirelessMasterCallback,SIGNAL(flushProgress(int,int)),this,SLOT(handleFlushProgress(int,int)));
    connect(&wirelessMasterCallback,SIGNAL(loadFileProgress(int,int)),this,SLOT(handleLoadFileProgress(int,int)));

    connect(&batteryUpdateTimer,SIGNAL(timeout()),this,SLOT(handlebatteryUpdateTimer()));
}


bool hmXDA::connectMaster(int RadioChannel,bool trigEnabled)
{
    if(state!=Idle)
    {
        emit log("ERROR: System is not in IDLE state!");
        return false;
    }


    /***** 建立Xscontrol对象，需手动destruct  *****/
    this->control = XsControl::construct();//
    if (this->control == 0)
    {
        emit log( tr("ERROR: failed to construct XsControl instance!"));
        return false;
    }

    /***** 寻找并打开 Master 的端口,建立 Master(Master Device) 对象并连接，完成 Master 的设置   ****/
    //寻找端口
    XsPortInfoArray detectedDevices = XsScanner::scanPorts();
    XsPortInfoArray::const_iterator wirelessMasterPort = detectedDevices.begin();
    while (wirelessMasterPort != detectedDevices.end() && !wirelessMasterPort->deviceId().isWirelessMaster())
    {
        ++wirelessMasterPort;
    }
    if (wirelessMasterPort == detectedDevices.end())
    {
        emit log(tr("ERROR: No wireless masters found!"));
        return false;
    }
    emit log( tr(" Wireless master found @ ") + QString::fromStdString(wirelessMasterPort->portName().toStdString()));

    // 打开端口
    if (!this->control->openPort(wirelessMasterPort->portName().toStdString(), wirelessMasterPort->baudrate()))
    {
        emit log(tr("ERROR: Failed to open port "));
        return false;
    }

    //建立 Master(Master Device) 对象并连接，需要手动删除
    this->wirelessMasterDevice = this->control->device(wirelessMasterPort->deviceId());
    if (this->wirelessMasterDevice == 0)
    {
        emit log(tr("ERROR: Failed to construct XsDevice instance!"));
        return false;
    }

    // 设置为 config mode
    if (!this->wirelessMasterDevice->gotoConfig())
    {
        emit log(tr("Failed to goto config mode! "));
        return false;
    }

    // 设置 Master 的回调函数
    this->wirelessMasterDevice->addCallbackHandler(&(this->wirelessMasterCallback));

    // 设置触发
    XsSyncSettingArray xsl;
    if(trigEnabled)
    {
        XsSyncSetting xs1;
        xs1.m_line = XSL_In1;
        xs1.m_function = XSF_StartRecording;
        xs1.m_polarity = XSP_RisingEdge;

        XsSyncSetting xs2;
        xs2.m_line = XSL_In1;
        xs2.m_function = XSF_StopRecording;
        xs2.m_polarity = XSP_FallingEdge;

        xsl.push_back(xs1);
        xsl.push_back(xs2);
    }

    if(!wirelessMasterDevice->setSyncSettings(xsl))
    {
        emit log("ERROR: Failed set SyncSettings!");
        return false;
    }

    // 设置频道: 关闭之前的频道，打开新频道
    if (this->wirelessMasterDevice->isRadioEnabled())
    {
        if (!this->wirelessMasterDevice->disableRadio())
        {
            emit log(tr("ERROR: Failed to disable old radio channel!"));
            return false;
        }
    }
    if (!this->wirelessMasterDevice->enableRadio(RadioChannel))
    {
        emit log(tr("ERROR: Failed to set new radio channel"));
        return false;
    }
    emit log(tr("Setting radio channel to ") + QString::number(RadioChannel));

    setState(Searching); //手动改变状态

    return true;
}

bool hmXDA::disconnectMaster()
{
    if(state!= Searching)
    {
        emit log("ERROR: System is not in SEARCHING state!");
        return false;
    }

    if (!this->wirelessMasterDevice->gotoConfig())
    {
        emit log(tr("ERROR: Failed to goto config mode"));
        return false;
    }

    wirelessMasterDevice->clearCallbackHandlers();

    if (!this->wirelessMasterDevice->disableRadio())
    {
        emit log(tr("ERROR: Failed to disable radio"));
        return false;
    }
    control->destruct(); //删除control，释放内存
    emit log(tr("Master has disconnected."));

    setState(Idle); //手动改变状态
    return true;
}


bool hmXDA::connectMTws()
{
    if(state!=Searching)
    {
        emit log("ERROR: System is not in SEARCHING state!");
        return false;
    }
    /*****   设置MTw的模式，建立索引   *****/

    QMutexLocker locker(&m_mutex);

    mtwDeviceIds = wirelessMasterCallback.getConnectedMTws();
    mtwCallbacks.clear();
    //创建 MTw sensors 实例, 添加callBack函数
    for (std::set<XsDeviceId>::const_iterator i = mtwDeviceIds.begin(); i != mtwDeviceIds.end(); ++i)
    {
        XsDevicePtr mtwDevice = this->control->device(*i);
        mtwCallback* mc = new mtwCallback();
        mtwDevice->addCallbackHandler(mc);
        mtwCallbacks.insert(mc);
        connect(mc,SIGNAL(dataAvailable(hmData)),this,SLOT(handleDataAvailable(hmData)));
    }

    emit log(tr("Senosor's number is ")+QString::number(mtwDeviceIds.size()));

    m_nextDeviceId = mtwDeviceIds.begin();//电量查询开始
    batteryUpdateTimer.start(100);

    emit log(tr("All sensors have connected successfully."));
    setState(Preparing); //手动改变状态
    return true;
}

bool hmXDA::disconnectMTws()
{
    if(state!=Preparing)
    {
        emit log("ERROR: System is not in Preparing state!");
        return false;
    }

    QMutexLocker locker(&m_mutex);

    batteryUpdateTimer.stop();//停止电量查询
    // Detach callback handlers
    for (std::set<XsDeviceId>::const_iterator i = mtwDeviceIds.begin(); i != mtwDeviceIds.end(); ++i)
    {
        XsDevicePtr mtwDevice = this->control->device(*i);
        mtwDevice->clearCallbackHandlers();
    }
    for (std::set<mtwCallback*>::const_iterator i = mtwCallbacks.begin(); i != mtwCallbacks.end(); ++i)
    {
        disconnect((*i),SIGNAL(dataAvailable(hmData)),this,SLOT(handleDataAvailable(hmData)));
        delete (*i);
    }
    mtwCallbacks.clear();
    mtwDeviceIds.clear();

    setState(Searching); //手动改变状态
    return true;
}

bool hmXDA::startMeasurement(int UpdateRate)
{
    if(state!=Preparing)
    {
        emit log("ERROR: System is not in PREPARING state!");
        return false;
    }

    // 设置频率
    if (!this->wirelessMasterDevice->setUpdateRate(UpdateRate))
    {
        emit log(tr("ERROR: Failed to set update rate!"));
        return false;
    }
    emit log(tr("Setting update rate to ")+ QString::number(UpdateRate) +tr(" Hz") );

    if (!this->wirelessMasterDevice->gotoMeasurement())
    {
        emit log(tr("ERROR: Failed to goto Measurement mode"));
        return false;
    }

    return true;

}

bool hmXDA::stopMeasurement()
{
    if(state!=Measuring)
    {
        emit log("ERROR: System is not in MEASURING state!");
        return false;
    }

    if (!this->wirelessMasterDevice->gotoConfig())
    {
        emit log(tr("ERROR: Failed to goto Config mode"));
        return false;
    }

    return true;
}

bool hmXDA::startRecord(QString file)
{
    if(state!=Measuring)
    {
        emit log("ERROR: System is not in Measuring state!");
        return false;
    }

    if(wirelessMasterDevice->createLogFile(file.toStdString().c_str()) != XRV_OK)
    {
        emit log("ERROR: Failed to create logFile!");
        return false;
    }

    if(!wirelessMasterDevice->startRecording()) // 触发onDeviceStateChanged， 根据设置，进入recording 或 WaitRecording
    {
        emit log("ERROR: Failed to start record!");
        return false;
    }

    return true;
}

bool hmXDA::stopRecord()
{
    if(state!=Recording)
    {
        emit log("ERROR: System is not in record state!");
        return false;
    }
    if(!wirelessMasterDevice->stopRecording())
    {
        emit log("ERROR: Failed to stop record!");
        return false;
    }

    return true;
}


bool hmXDA::loadLogFile(QString file)
{
    if(state!=Idle)
    {
        emit log("ERROR: System must be in Idle state!");
        return false;
    }
    control = XsControl::construct();

    if(!control->openLogFile(file.toStdString().c_str()))
    {
        emit log("ERROR: Fail to open logFile!");
        return false;
    }
    XsDeviceIdArray deviceIds = control->mainDeviceIds();
    XsDeviceId masterId = deviceIds[0];
    wirelessMasterDevice = control->device(masterId);
    wirelessMasterDevice->addCallbackHandler(&wirelessMasterCallback);
    wirelessMasterDevice->setOptions(XsOption::XSO_RetainRecordingData, XsOption::XSO_None);//开始读取数据

    if(!wirelessMasterDevice->loadLogFile()) // 将导致一个 onProgressUpdated()
    {
        emit log("ERROR: Fail to load logFile!");
        return false;
    }
    setState(Reading);

    return true;
}

bool hmXDA::clearLoadLog()
{
    if(state!=Open)
    {
        emit log("ERROR: System is not in Open state!");
        return false;
    }
    control->destruct(); //删除control，释放内存
    emit log(tr("Loaded data has cleared."));

    setState(Idle);
    return true;
}


//----- 用于读取mtb文件-----
int hmXDA::getDataPacketCount(quint32 deviceId)
{
    if(state!=Open)
        return -1;

    XsDevice* imu = wirelessMasterDevice->findDevice(XsDeviceId(deviceId));
    if(!imu)
        return -1;
    return imu->getDataPacketCount();
}

hmData hmXDA::getDataPacketByIndex(quint32 deviceId, int index)
{
    if(state!=Open)
        return hmData();
    XsDevice* imu = wirelessMasterDevice->findDevice(XsDeviceId(deviceId));
    if(!imu)
        return hmData();
    int n = imu->getDataPacketCount();
    if( (index>=n)||(index<0) )
        return hmData();

    XsDataPacket packet = imu->getDataPacketByIndex(index);

    quint64 timestamp = packet.timeOfArrival().msTime();
    XsQuaternion quater = packet.orientationQuaternion();
    XsCalibratedData  d = packet.calibratedData();

    hmQuaternion Q;
    Q.q0 = quater.w();
    Q.q1 = quater.x();
    Q.q2 = quater.y();
    Q.q3 = quater.z();

    hmVector acc;
    XsVector3 a = d.m_acc;
    acc.x = a[0];
    acc.y = a[1];
    acc.z = a[2];

    hmVector gyr;
    XsVector3 g = d.m_gyr;
    gyr.x = g[0];
    gyr.y = g[1];
    gyr.z = g[2];

    hmVector mag;
    XsVector3 m = d.m_mag;
    mag.x = m[0];
    mag.y = m[1];
    mag.z = m[2];

    int rssi = packet.rssi();
    quint32 id = imu->deviceId().toInt();
    int counter = packet.packetCounter();

    return hmData(id,Q,acc,gyr,mag,counter,rssi,timestamp);
}

int hmXDA::getLogFileUpdateRate()
{
    if(state!=Open)
        return -1;
    return wirelessMasterDevice->updateRate();
}

// 获取当前状态下的支持频率,输出有大到小排列
std::vector<int> hmXDA::getSupportUpdateRate()
{
    // 得到当前状态下的支持频率
    std::vector<int> allowList;
    XsIntArray supportedRates =  wirelessMasterDevice->supportedUpdateRates();
    int maxUpdateRate = wirelessMasterDevice->maximumUpdateRate();
    for (XsIntArray::const_iterator i = supportedRates.begin(); i != supportedRates.end() && *i <= maxUpdateRate; ++i)
    {
        // This is an allowed update rate, so add it to the list.
        allowList.push_back(*i);
    }
    return allowList;
}

hmXDA_state hmXDA::getState()
{
    return state;
}

// 改变状态，并触发一个 stateChanged SIGANL
void hmXDA::setState(hmXDA_state newState)
{
    hmXDA_state oldState = state;
    state = newState;
    emit stateChanged(newState,oldState);
}

void hmXDA::setState(hmXDA_state newState, hmXDA_state oldState)
{
    state = newState;
    emit stateChanged(newState,oldState);
}


void hmXDA::handleMtwDisconnected(quint32 deviceId)
{
    emit mtwDisconnected(deviceId);
}

void hmXDA::handleMtwWireless(quint32 deviceId)
{
    emit mtwWireless(deviceId);
}

void hmXDA::handlebatteryUpdateTimer()
{
    QMutexLocker locker(&m_mutex);

    // It is impossible to request battery status for all MTWs at once. So cycle between them

    if(m_nextDeviceId == mtwDeviceIds.end())
    {
        m_nextDeviceId = mtwDeviceIds.begin();
    }
    if(m_nextDeviceId != mtwDeviceIds.end())
    {
        XsDevicePtr mtwDevice = this->control->device(*m_nextDeviceId);
        mtwDevice->requestBatteryLevel();
        ++m_nextDeviceId;
    }
}

void hmXDA::handleDataAvailable(hmData data)
{
    emit dataAvailable(data);
}

void hmXDA::handleFlushProgress(int current, int total)
{
    emit flushProgress(current, total);
}

void hmXDA::handleLoadFileProgress(int current, int total)
{
    if(current==total)
    {
        setState(Open,Reading);
        wirelessMasterDevice->closeLogFile();
    }
    emit loadFileProgress(current,total);
}


void hmXDA::handleMasterStateChanged(XsDeviceState newState, XsDeviceState oldState)
{
    if( (newState==XDS_Measurement)&&(oldState==XDS_Config ) ) // Preparing -->> Measuring
        emit setState(Measuring,Preparing);

    else if( (newState==XDS_Config)&&(oldState==XDS_Measurement ) ) // Measuring -->> Preparing
        emit setState(Preparing,Measuring);

    else if( (newState==XDS_Recording)&&(oldState==XDS_Measurement ) ) // Measuring -->> Recording
        emit setState(Recording,Measuring);

    else if( (newState==XDS_WaitingForRecordingStart)&&(oldState==XDS_Measurement ) ) // Measuring -->> WaitRecording
        emit setState(WaitRecord,Measuring);

    else if( (newState==XDS_Measurement)&&(oldState==XDS_WaitingForRecordingStart ) ) // WaitRecording -->> Measuring
        emit setState(Measuring,WaitRecord);

    else if( (newState==XDS_Recording)&&(oldState==XDS_WaitingForRecordingStart ) ) // WaitRecording -->> Recording
        emit setState(Recording,WaitRecord);

    else if( (newState==XDS_FlushingData)&&(oldState==XDS_Recording) ) // Recording -->> Flushing
        emit setState(Flushing,Recording);

    else if( (newState==XDS_Measurement)&&(oldState==XDS_FlushingData) ) // Flush -->> Measuring
    {
        wirelessMasterDevice->closeLogFile();
        emit setState(Measuring,Flushing);
    }
}

