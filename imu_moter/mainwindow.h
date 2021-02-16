#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hmdata.h"
#include "hmxda.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr); //构造函数
    ~MainWindow();  //析构函数
    hmXDA* xda;     //实例化xsens对象

private slots:      //槽函数
    void log(const QString& info);
    void handleHasNewImuData(hmData data);
    void handleMTwConnect(quint32 id);
    void on_pushButton_connectMaster_clicked();  //连接主机按钮槽函数

    void on_pushButton_connectSensors_clicked();  //连接传感器按钮槽函数

    void on_pushButton_startMeasurement_clicked(); //开始测量按钮槽函数

    //串口相关槽函数
    void on_OpenSerialButton_clicked();  //打开串口
    void ReadData();                     //读取数据
    void on_SendButton_clicked();        //发送数据
    //ping舵机
    void on_Ping_clicked();
    void on_Clean_clicked();
    void on_test_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort *serial;  //实例化全局串口对象
};
#endif // MAINWINDOW_H
