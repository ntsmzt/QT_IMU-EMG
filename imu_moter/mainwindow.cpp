#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

//qstring转16进制字符串
char ConvertHexChar(char ch)
{
if((ch >= '0') && (ch <= '9'))
return ch-0x30;
else if((ch >= 'A') && (ch <= 'F'))
return ch-'A'+10;
else if((ch >= 'a') && (ch <= 'f'))
return ch-'a'+10;
else return (-1);
}

QByteArray QString2Hex(QString str)
{
QByteArray senddata;
int hexdata,lowhexdata;
int hexdatalen = 0;
int len = str.length();
senddata.resize(len/2);
char lstr,hstr;
for(int i=0; i<len; )
{
hstr=str[i].toLatin1();
if(hstr == ' ')
{
i++;
continue;
}
i++;
if(i >= len)
break;
lstr = str[i].toLatin1();
hexdata = ConvertHexChar(hstr);
lowhexdata = ConvertHexChar(lstr);
if((hexdata == 16) || (lowhexdata == 16))
break;
else
hexdata = hexdata*16+lowhexdata;
i++;
senddata[hexdatalen] = (char)hexdata;
hexdatalen++;
}
senddata.resize(hexdatalen);
return senddata;
}
/**********************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    xda = new hmXDA(this);  //实例化Xsens
     
    //自动寻找可用串口
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
            {
              QSerialPort serial;
              serial.setPort(info);
                 if(serial.open(QIODevice::ReadWrite))
                    {
                       ui->PortBox->addItem(serial.portName());
                       serial.close();
                     }
                 }

     //设置波特率下拉菜单默认显示第0项
     ui->BaudBox->setCurrentIndex(0);
     ui->BitBox->setFixedSize(70,20);

    //连接信号与槽
    connect(xda,SIGNAL(log(QString)),this,SLOT(log(QString)));
    connect(xda,SIGNAL(mtwWireless(quint32)),this,SLOT(handleMTwConnect(quint32)));
    connect(xda,SIGNAL(dataAvailable(hmData)),this,SLOT(handleHasNewImuData(hmData)));
}
//析构
MainWindow::~MainWindow()
{
    delete ui;
}
//
void MainWindow::log(const QString &info)
{
    ui->textBrowser->append(info);
}
//
void MainWindow::handleHasNewImuData(hmData data)   //新数据接收完毕  打印IMU数据
{
    qDebug()<<data.deviceId<<data.q.q0<<data.q.q1<<data.q.q2<<data.q.q3;
    ui->lcdNumber->display(data.batteryLevel);
}
//
void MainWindow::handleMTwConnect(quint32 id)
{
    ui->textBrowser->append(QString("Sensor %1 connect").arg(id));
}
//“连接主机”按钮槽函数
void MainWindow::on_pushButton_connectMaster_clicked()
{
    if(ui->pushButton_connectMaster->text()=="Connect Master")
    {
        xda->connectMaster(11, false);
        ui->pushButton_connectMaster->setText("Disconnect Master");
    }
    else
    {
        xda->disconnectMaster();   //断开传感器主机连接
        ui->pushButton_connectMaster->setText("Connect Master");
    }
}
//连接传感器
void MainWindow::on_pushButton_connectSensors_clicked()
{
    xda->connectMTws();
    if(ui->pushButton_connectSensors->text()=="Connect Sensors")
    {
        xda->connectMTws();
        ui->pushButton_connectSensors->setText("Disconnect Sensors");
    }
    else
    {
        xda->disconnectMTws();
        ui->pushButton_connectSensors->setText("Connect Sensors");
    }
}

void MainWindow::on_pushButton_startMeasurement_clicked()
{
    if(ui->pushButton_startMeasurement->text()=="Start Measurement")
    {
        xda->startMeasurement(100);
        ui->pushButton_startMeasurement->setText("Stop Measurement");
    }
    else
    {
        xda->stopMeasurement();
        ui->pushButton_startMeasurement->setText("Start Measurement");
    }
}
/*******************************/
//串口相关函数
void MainWindow::on_OpenSerialButton_clicked()    //打开串口按钮
{
    if(ui->OpenSerialButton->text() == tr("打开串口"))
    {
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(ui->PortBox->currentText());
         //打开串口
        serial->open(QIODevice::ReadWrite);
         //设置波特率
      //  serial->setBaudRate(QSerialPort::Baud9600);//设置波特率为115200
        bool ok;
        QString str = ui->BaudBox->currentText();
        int baud =str.toInt(&ok);
        serial->setBaudRate(baud);//设置波特率为115200
         //设置数据位数
        switch (ui->BitBox->currentIndex())
         {
            case 8:
                serial->setDataBits(QSerialPort::Data8);//设置数据位8
                break;
            default:
                break;
         }
          //设置校验位
         switch (ui->ParityBox->currentIndex())
         {
         case 0 :
             serial->setParity(QSerialPort::NoParity);
             break;
         default:
             break;
         }
         //设置停止位
         switch (ui->StopBitBox->currentIndex())
         {
             case 1:
                 serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
                 break;
             case 2:
                 serial->setStopBits(QSerialPort::TwoStop);
                 break;
             default:
                 break;
         }
         //设置流控制
         serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制
         //关闭设置菜单使能
         ui->PortBox->setEnabled(false);
         ui->BaudBox->setEnabled(false);
         ui->BitBox->setEnabled(false);
         ui->ParityBox->setEnabled(false);
         ui->StopBitBox->setEnabled(false);
         ui->OpenSerialButton->setText(tr("关闭串口"));
         //连接信号槽
         connect(serial,&QSerialPort::readyRead,this,&MainWindow::ReadData);
    }
    else
    {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();
        //恢复设置使能
        ui->PortBox->setEnabled(true);
        ui->BaudBox->setEnabled(true);
        ui->BitBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->StopBitBox->setEnabled(true);
        ui->OpenSerialButton->setText(tr("打开串口"));
    }
}

void MainWindow::ReadData()   //串口读取数据
{

    QByteArray buf;
    buf = serial->readAll();
    QString str = "/t";
    if(!buf.isEmpty())   //判断非空
    {
       //QString str = ui->textEdit->toPlainText();
       //str+=tr(buf);
       ui->textEdit->clear();
       ui->textEdit->append(buf.toHex());
       //ui->textEdit->append(str);
    }
    buf.clear();
}

//发送按钮槽函数
void MainWindow::on_SendButton_clicked()
{
    serial->write(QString2Hex(ui->textEdit_2->toPlainText().toLatin1()));
    //serial->write(ui->textEdit_2->toPlainText().toLatin1());
}

//Ping舵机
void MainWindow::on_Ping_clicked()
{
    //serial->write();
}

//清除接收区
void MainWindow::on_Clean_clicked()
{
   ui->textEdit->clear();
}


//四元数乘法测试函数
void MainWindow::on_test_clicked()
{
    hmQuaternion Q01(1,1,0,0);
    hmQuaternion Q02;
    hmQuaternion Q03;
    Q02 = Q01.Inverseoperation();
    Q03 = Q01*Q02;
    //Q01 = Q01.Inverseoperation();
    qDebug()<<Q03.q0<<Q03.q1<<Q03.q2<<Q03.q3;
    //qDebug()<<Q01.q0<<Q01.q1<<Q01.q2<<Q01.q3;
}
