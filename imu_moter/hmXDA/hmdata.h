#ifndef HMDATA
#define HMDATA

#include <QString>
#include <QDataStream>
#include <QTextStream>



class hmVector      //向量类
{
public:
    double x,y,z;
    hmVector();             //构造函数
    hmVector(double x,double y,double z);
    hmVector(const hmVector & V);
    double dot(hmVector& V);
    hmVector cross(hmVector &V);
    hmVector operator+(hmVector &V);
    hmVector operator-(hmVector &V);
    hmVector operator=(const hmVector &V);
    hmVector operator*(double k);
    double norm();
    QString toQString();
};

hmVector operator* (double k,hmVector &V);


class hmQuaternion         //四元数类
{
public:
    double q0, q1, q2, q3;
    hmQuaternion conjugate();   //求四元数共轭
    hmQuaternion operator*(  hmQuaternion &Q);   //运算符重载
    hmQuaternion(double q0,double q1,double q2,double q3);
    hmQuaternion();
    hmQuaternion(double q0,  hmVector &V);
    hmQuaternion(hmVector &V);
    hmQuaternion(double roll, double pitch, double yaw);
    hmQuaternion( const hmQuaternion &Q);
    hmVector getVector()  ;
    hmQuaternion operator=(const hmQuaternion &Q);
    hmQuaternion operator+(hmQuaternion &Q);
    hmQuaternion operator-(hmQuaternion &Q);
    hmQuaternion operator*(double k);
    hmQuaternion operator/(double k);
    hmQuaternion Inverseoperation();
    double getRad();
    hmVector getAxis();
    hmVector rotateVector(hmVector &V);
    hmVector toEularDeg(); //返回欧拉角(角度)
    QString toQString();   //转换为字符串
};

hmQuaternion operator* (double k,   hmQuaternion &Q);

QDataStream& operator>>(QDataStream& in, hmQuaternion& Q);
QDataStream& operator<<(QDataStream& out, hmQuaternion& Q);
QDataStream& operator>>(QDataStream& in, hmVector& V);
QDataStream& operator<<(QDataStream& out, hmVector& V);
QTextStream& operator<<(QTextStream& out, hmQuaternion& Q);
QTextStream& operator<<(QTextStream& out, hmVector& V);


class hmData
{
public:
    hmQuaternion q;
    hmVector acc;       //加速度
    hmVector gyr;
    hmVector mag;
    int batteryLevel;
    int rssi;
    quint64 timestamp;
    quint32 deviceId;
    hmData(quint32 deviceId, hmQuaternion q, hmVector acc, hmVector gyr, hmVector mag, int batteryLevel, int rssi, quint64 timestamp);
    hmData();
    hmData(const hmData& d);
    hmData operator=(const hmData &d);
    //~hmData();

};

#endif // HMDATA

