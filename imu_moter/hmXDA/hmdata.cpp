#include "hmdata.h"
#include <math.h>

hmQuaternion::hmQuaternion(double q0, double q1, double q2, double q3):q0(q0),q1(q1),q2(q2),q3(q3)
{
}

hmQuaternion::hmQuaternion():q0(1),q1(0),q2(0),q3(0)
{
}

hmQuaternion::hmQuaternion(double q0, hmVector &V):q0(q0),q1(V.x),q2(V.y),q3(V.z)
{
}
//构造函数  由向量转化四元数
hmQuaternion::hmQuaternion(hmVector &V)
{
    double phi = V.x*acos(-1.0)/180/2;
    double theta = V.y*acos(-1.0)/180/2;
    double psi = V.z*acos(-1.0)/180/2;
    q0 = cos(phi)*cos(theta)*cos(psi) + sin(phi)*sin(theta)*sin(psi);
    q1 = sin(phi)*cos(theta)*cos(psi) - cos(phi)*sin(theta)*sin(psi);
    q2 = cos(phi)*sin(theta)*cos(psi) + sin(phi)*cos(theta)*sin(psi);
    q3 = cos(phi)*cos(theta)*sin(psi) - sin(phi)*sin(theta)*cos(psi);
}
//输入rpy欧拉角(deg)构造四元数 构造函数
hmQuaternion::hmQuaternion(double roll, double pitch, double yaw)
{
    double phi = roll*acos(-1.0)/180/2;
    double theta = pitch*acos(-1.0)/180/2;
    double psi = yaw*acos(-1.0)/180/2;
    q0 = cos(phi)*cos(theta)*cos(psi) + sin(phi)*sin(theta)*sin(psi);
    q1 = sin(phi)*cos(theta)*cos(psi) - cos(phi)*sin(theta)*sin(psi);
    q2 = cos(phi)*sin(theta)*cos(psi) + sin(phi)*cos(theta)*sin(psi);
    q3 = cos(phi)*cos(theta)*sin(psi) - sin(phi)*sin(theta)*cos(psi);
}
//用四元数构造四元数
hmQuaternion::hmQuaternion( const hmQuaternion &Q):q0(Q.q0),q1(Q.q1),q2(Q.q2),q3(Q.q3)
{
}

//转出四元数V向量
hmVector hmQuaternion::getVector()
{
    return hmVector(q1,q2,q3);
}
//求四元数共轭
hmQuaternion hmQuaternion::conjugate()
{
    return hmQuaternion(q0,-q1,-q2,-q3);
}
//四元数乘法
hmQuaternion hmQuaternion::operator *( hmQuaternion &Q)
{
    hmVector v1 = this->getVector();
    hmVector v2 = Q.getVector();
    double w = q0*Q.q0 - v1.dot(v2);
//    hmVector v = q0*v2 + Q.q0*v1 + v1.cross(v2);
    hmVector vt1 = Q.q0*v1;
    hmVector vt2 = v1.cross(v2);
    hmVector v = q0*v2 + vt1 + vt2;
    return hmQuaternion(w,v);
}


hmQuaternion hmQuaternion::operator =(const hmQuaternion &Q)
{
    q0 = Q.q0;
    q1 = Q.q1;
    q2 = Q.q2;
    q3 = Q.q3;
    return *this;
}

//运算符重载
hmQuaternion hmQuaternion::operator+(hmQuaternion &Q)
{
    return hmQuaternion(q0+Q.q0, q1+Q.q1, q2+Q.q2, q3+Q.q3);
}

hmQuaternion hmQuaternion::operator-(hmQuaternion &Q)
{
    return hmQuaternion(q0-Q.q0, q1-Q.q1, q2-Q.q2, q3-Q.q3);
}

hmQuaternion hmQuaternion::operator/(double k)
{
    return hmQuaternion(q0/k, q1/k, q2/k, q3/k);
}

hmQuaternion hmQuaternion::operator*(double k)
{
    return hmQuaternion(q0*k, q1*k, q2*k, q3*k);
}

hmQuaternion operator* (double k,   hmQuaternion &Q)
{
    return Q*k;
}
//求四元数逆运算
hmQuaternion hmQuaternion::Inverseoperation()
{
    return this->conjugate()/(q0*q0+q1*q1+q2*q2+q3*q3);
}
//
hmVector hmQuaternion::rotateVector( hmVector &V)
{
    hmQuaternion w = hmQuaternion(0,V);
//    hmQuaternion u = (*this)*w*(this->conjugate());

    hmQuaternion c = this->conjugate();
    hmQuaternion u = (*this)*w*c;
    return u.getVector();
}

//返回rpy角， x-roll, y-pitch, z-yaw
hmVector hmQuaternion::toEularDeg()
{
    double roll, pitch, yaw;
    roll = atan2(2*q2*q3 + 2*q0*q1, 2*q0*q0 + 2*q3*q3 - 1);
    pitch = - asin(2*q1*q3 - 2*q0*q2);
    yaw = atan2(2*q1*q2 + 2*q0*q3, 2*q0*q0 + 2*q1*q1 -1);
    double x,y,z;
    x = roll / acos(-1) *180;
    y = pitch / acos(-1) *180;
    z = yaw / acos(-1) *180;
    return hmVector(x,y,z);
}

//返回弧度，范围为0~2*pi
double hmQuaternion::getRad()
{
    double sin_half = sqrt(q1*q1+q2*q2+q3*q3);
    return 2*atan2(sin_half,q0);
}
//单位化
hmVector hmQuaternion::getAxis()
{
    double norm = sqrt(q1*q1+q2*q2+q3*q3);
    return hmVector(q1/norm,q2/norm,q3/norm);
}
//将四元数转化为字符串
QString hmQuaternion::toQString()
{
    QString a = "["+QString::number(q0)+", "+QString::number(q1)+", "+QString::number(q2)+", "+QString::number(q3)+"] ";
    return a;
}



/*****   -------------------------------------------------   *****/

hmVector::hmVector(double x, double y, double z):x(x),y(y),z(z)
{
}

hmVector::hmVector():x(0),y(0),z(0)
{
}

hmVector::hmVector(const hmVector &V)
{
    this->x = V.x;
    this->y = V.y;
    this->z = V.z;
}
//向量点积
double hmVector::dot( hmVector &V)
{
    double dot = x*V.x + y*V.y + z*V.z;
    return dot;
}
//向量叉积
hmVector hmVector::cross( hmVector &V)
{
    double xc, yc, zc;
    xc = y*V.z - z*V.y;
    yc = z*V.x - x*V.z;
    zc = x*V.y - y*V.x;
    return hmVector(xc,yc,zc);
}

hmVector hmVector::operator *(double k)
{
    return hmVector(k*x,k*y,k*z);
}
//
double hmVector::norm()
{
    return sqrt(x*x+y*y+z*z);
}

hmVector operator* (double k, hmVector &V)
{
    return V*k;
}

hmVector hmVector::operator +(hmVector &V)
{
    return hmVector(x+V.x,y+V.y,z+V.z);
}

hmVector hmVector::operator -(hmVector &V)
{
    return hmVector(x-V.x,y-V.y,z-V.z);
}

hmVector hmVector::operator =(const hmVector &V)
{
    this->x = V.x;
    this->y = V.y;
    this->z = V.z;
    return *this;
}

QString hmVector::toQString()
{
    QString a = "("+QString::number(x)+", "+QString::number(y)+", "+QString::number(z)+") ";
    return a;
}

QDataStream& operator>>(QDataStream& in, hmQuaternion& Q)
{
    in >> Q.q0 >> Q.q1 >> Q.q2 >> Q.q3;
    return in;
}
QDataStream& operator<<(QDataStream& out, hmQuaternion& Q)
{
    out << Q.q0 << Q.q1 << Q.q2 << Q.q3;
    return out;
}

QDataStream& operator>>(QDataStream& in, hmVector& V)
{
    in >> V.x >> V.y >> V.z;
    return in;
}
QDataStream& operator<<(QDataStream& out, hmVector& V)
{
    out << V.x << V.y << V.z;
    return out;
}

QTextStream &operator<<(QTextStream &out, hmQuaternion &Q)
{
    out << Q.q0 << '\t' << Q.q1 << '\t' << Q.q2 << '\t' << Q.q3 << '\t';
    return out;
}

QTextStream &operator<<(QTextStream &out, hmVector &V)
{
    out << V.x << '\t' << V.y << '\t' << V.z << '\t';
    return out;
}

hmData::hmData(quint32 deviceId, hmQuaternion q, hmVector acc, hmVector gyr, hmVector mag, int batteryLevel, int rssi, quint64 timestamp)
    :deviceId(deviceId),
      q(q),
      acc(acc),
      gyr(gyr),
      mag(mag),
      batteryLevel(batteryLevel),
      rssi(rssi),
      timestamp(timestamp)
{
}

hmData::hmData()
    :deviceId(0),
      batteryLevel(0),
      rssi(0),
      timestamp(0)
{
}

hmData::hmData(const hmData &d)
{
    this->deviceId = d.deviceId;
    this->q = d.q;
    this->acc = d.acc;
    this->gyr = d.gyr;
    this->mag = d.mag;
    this->batteryLevel = d.batteryLevel;
    this->rssi = d.rssi;
    this->timestamp = d.timestamp;
}

hmData hmData::operator=(const hmData &d)
{
    q = d.q;
    acc = d.acc;
    gyr = d.gyr;
    mag = d.mag;
    batteryLevel = d.batteryLevel;
    rssi = d.rssi;
    timestamp = d.timestamp;
    deviceId = d.deviceId;
    return *this;
}
