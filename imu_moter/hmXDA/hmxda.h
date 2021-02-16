#ifndef HMXDA
#define HMXDA

#include <xsensdeviceapi.h> // The Xsens device API header
#include <QMutex>
#include <QMutexLocker>
#include <set>          
#include <map>
#include <vector>
#include <QTimer>

#include "hmdata.h"


//------------------------------------------------------------------------------
// masterCallback
//------------------------------------------------------------------------------
class masterCallback : public QObject, public XsCallback
{
    Q_OBJECT
public:
    std::set<XsDeviceId> getConnectedMTws();
signals:
    void mtwDisconnected(quint32 deviceId);
    void mtwWireless(quint32 deviceId);
    void flushFinished();
    void flushProgress(int current, int total);
    void trigRecording();
    void waitForRecording();
    void loadFileProgress(int current, int total);
    void stateChanged(XsDeviceState newState, XsDeviceState oldState);

protected:
    virtual void onConnectivityChanged(XsDevicePtr, XsConnectivityState);
    virtual void onProgressUpdated(XsDevice* dev, int current, int total, const XsString *identifier);
    virtual void onDeviceStateChanged(XsDevicePtr, XsDeviceState, XsDeviceState);

private:
    mutable QMutex m_mutex;
    std::set<XsDeviceId> m_connectedMTws;
};

//------------------------------------------------------------------------------
// mtwCallback
//------------------------------------------------------------------------------
class mtwCallback : public QObject, public XsCallback
{
    Q_OBJECT
private:
    int batteryLevel;
signals:
    void dataAvailable(hmData data);
protected:
    virtual void onLiveDataAvailable(XsDevicePtr, const XsDataPacket* packet);
    virtual void onInfoResponse(XsDevice* dev, XsInfoRequest request);
public:

};


//------------------------------------------------------------------------------
// hmXDA
//------------------------------------------------------------------------------
enum hmXDA_state { Idle, Searching, Preparing, Measuring, WaitRecord, Recording, Reading, Flushing, Open};

class hmXDA : public QObject
{
    Q_OBJECT
public:
    explicit hmXDA(QObject *parent = 0);

    //--- State Change ---
    bool connectMaster(int RadioChannel, bool trigEnabled);
    bool connectMTws();
    bool disconnectMTws();
    bool disconnectMaster();
    bool startMeasurement(int UpdateRate);
    bool stopMeasurement();
    bool startRecord(QString file);    //开始记录
    bool stopRecord();                 //停止记录
    bool loadLogFile(QString file);    //加载log文件
    bool clearLoadLog();

    //--- data functions ---
    int getDataPacketCount(quint32 deviceId);
    std::vector<int> getSupportUpdateRate();
    hmData getDataPacketByIndex(quint32 deviceId, int index);
    int getLogFileUpdateRate();
    hmXDA_state getState();

private:
    QTimer batteryUpdateTimer;
    std::set<XsDeviceId>::const_iterator m_nextDeviceId;
    hmXDA_state state;
    XsControl* control;
    XsDevice* wirelessMasterDevice;
    masterCallback wirelessMasterCallback;
    std::set<XsDeviceId> mtwDeviceIds;
    std::set<mtwCallback*> mtwCallbacks;
    mutable QMutex m_mutex;
    void setState(hmXDA_state newState);
    void setState(hmXDA_state newState, hmXDA_state oldState);

private slots:
    void handleMtwDisconnected(quint32 deviceId);
    void handleMtwWireless(quint32 deviceId);
    void handlebatteryUpdateTimer();
    void handleDataAvailable(hmData data);
    void handleFlushProgress(int current, int total);
    void handleLoadFileProgress(int current, int total);
    void handleMasterStateChanged(XsDeviceState newState, XsDeviceState oldState);

signals:
    void log(const QString& info);
    void mtwDisconnected(quint32 deviceId);
    void mtwWireless(quint32 deviceId);
    void dataAvailable(hmData data);
    void stateChanged(hmXDA_state newState, hmXDA_state oldState);

    void flushProgress(int current, int total);
    void loadFileProgress(int current, int total);
};


// 注册类型，使该类型可以在 SIGANL\SLOT 机制中传递
Q_DECLARE_METATYPE(hmData)
Q_DECLARE_METATYPE(XsDeviceState)
Q_DECLARE_METATYPE(hmXDA_state)
class MetaTypeInitializer {
public:
    MetaTypeInitializer()
    {
        qRegisterMetaType<hmData>("hmData");
        qRegisterMetaType<XsDeviceState>("XsDeviceState");
        qRegisterMetaType<hmXDA_state>("hmXDA_state");
    }
};


#endif // HMXDA

