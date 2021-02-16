/****************************************************************************
** Meta object code from reading C++ file 'hmxda.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../imu_moter/hmXDA/hmxda.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hmxda.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_masterCallback_t {
    QByteArrayData data[16];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_masterCallback_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_masterCallback_t qt_meta_stringdata_masterCallback = {
    {
QT_MOC_LITERAL(0, 0, 14), // "masterCallback"
QT_MOC_LITERAL(1, 15, 15), // "mtwDisconnected"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "deviceId"
QT_MOC_LITERAL(4, 41, 11), // "mtwWireless"
QT_MOC_LITERAL(5, 53, 13), // "flushFinished"
QT_MOC_LITERAL(6, 67, 13), // "flushProgress"
QT_MOC_LITERAL(7, 81, 7), // "current"
QT_MOC_LITERAL(8, 89, 5), // "total"
QT_MOC_LITERAL(9, 95, 13), // "trigRecording"
QT_MOC_LITERAL(10, 109, 16), // "waitForRecording"
QT_MOC_LITERAL(11, 126, 16), // "loadFileProgress"
QT_MOC_LITERAL(12, 143, 12), // "stateChanged"
QT_MOC_LITERAL(13, 156, 13), // "XsDeviceState"
QT_MOC_LITERAL(14, 170, 8), // "newState"
QT_MOC_LITERAL(15, 179, 8) // "oldState"

    },
    "masterCallback\0mtwDisconnected\0\0"
    "deviceId\0mtwWireless\0flushFinished\0"
    "flushProgress\0current\0total\0trigRecording\0"
    "waitForRecording\0loadFileProgress\0"
    "stateChanged\0XsDeviceState\0newState\0"
    "oldState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_masterCallback[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    0,   60,    2, 0x06 /* Public */,
       6,    2,   61,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,
      10,    0,   67,    2, 0x06 /* Public */,
      11,    2,   68,    2, 0x06 /* Public */,
      12,    2,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13,   14,   15,

       0        // eod
};

void masterCallback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<masterCallback *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mtwDisconnected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->mtwWireless((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->flushFinished(); break;
        case 3: _t->flushProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->trigRecording(); break;
        case 5: _t->waitForRecording(); break;
        case 6: _t->loadFileProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->stateChanged((*reinterpret_cast< XsDeviceState(*)>(_a[1])),(*reinterpret_cast< XsDeviceState(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< XsDeviceState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (masterCallback::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::mtwDisconnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (masterCallback::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::mtwWireless)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (masterCallback::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::flushFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (masterCallback::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::flushProgress)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (masterCallback::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::trigRecording)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (masterCallback::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::waitForRecording)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (masterCallback::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::loadFileProgress)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (masterCallback::*)(XsDeviceState , XsDeviceState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&masterCallback::stateChanged)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject masterCallback::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_masterCallback.data,
    qt_meta_data_masterCallback,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *masterCallback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *masterCallback::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_masterCallback.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "XsCallback"))
        return static_cast< XsCallback*>(this);
    return QObject::qt_metacast(_clname);
}

int masterCallback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void masterCallback::mtwDisconnected(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void masterCallback::mtwWireless(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void masterCallback::flushFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void masterCallback::flushProgress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void masterCallback::trigRecording()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void masterCallback::waitForRecording()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void masterCallback::loadFileProgress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void masterCallback::stateChanged(XsDeviceState _t1, XsDeviceState _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
struct qt_meta_stringdata_mtwCallback_t {
    QByteArrayData data[5];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mtwCallback_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mtwCallback_t qt_meta_stringdata_mtwCallback = {
    {
QT_MOC_LITERAL(0, 0, 11), // "mtwCallback"
QT_MOC_LITERAL(1, 12, 13), // "dataAvailable"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "hmData"
QT_MOC_LITERAL(4, 34, 4) // "data"

    },
    "mtwCallback\0dataAvailable\0\0hmData\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mtwCallback[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void mtwCallback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mtwCallback *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataAvailable((*reinterpret_cast< hmData(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hmData >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mtwCallback::*)(hmData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mtwCallback::dataAvailable)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mtwCallback::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_mtwCallback.data,
    qt_meta_data_mtwCallback,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mtwCallback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mtwCallback::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mtwCallback.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "XsCallback"))
        return static_cast< XsCallback*>(this);
    return QObject::qt_metacast(_clname);
}

int mtwCallback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void mtwCallback::dataAvailable(hmData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_hmXDA_t {
    QByteArrayData data[26];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hmXDA_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hmXDA_t qt_meta_stringdata_hmXDA = {
    {
QT_MOC_LITERAL(0, 0, 5), // "hmXDA"
QT_MOC_LITERAL(1, 6, 3), // "log"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 4), // "info"
QT_MOC_LITERAL(4, 16, 15), // "mtwDisconnected"
QT_MOC_LITERAL(5, 32, 8), // "deviceId"
QT_MOC_LITERAL(6, 41, 11), // "mtwWireless"
QT_MOC_LITERAL(7, 53, 13), // "dataAvailable"
QT_MOC_LITERAL(8, 67, 6), // "hmData"
QT_MOC_LITERAL(9, 74, 4), // "data"
QT_MOC_LITERAL(10, 79, 12), // "stateChanged"
QT_MOC_LITERAL(11, 92, 11), // "hmXDA_state"
QT_MOC_LITERAL(12, 104, 8), // "newState"
QT_MOC_LITERAL(13, 113, 8), // "oldState"
QT_MOC_LITERAL(14, 122, 13), // "flushProgress"
QT_MOC_LITERAL(15, 136, 7), // "current"
QT_MOC_LITERAL(16, 144, 5), // "total"
QT_MOC_LITERAL(17, 150, 16), // "loadFileProgress"
QT_MOC_LITERAL(18, 167, 21), // "handleMtwDisconnected"
QT_MOC_LITERAL(19, 189, 17), // "handleMtwWireless"
QT_MOC_LITERAL(20, 207, 24), // "handlebatteryUpdateTimer"
QT_MOC_LITERAL(21, 232, 19), // "handleDataAvailable"
QT_MOC_LITERAL(22, 252, 19), // "handleFlushProgress"
QT_MOC_LITERAL(23, 272, 22), // "handleLoadFileProgress"
QT_MOC_LITERAL(24, 295, 24), // "handleMasterStateChanged"
QT_MOC_LITERAL(25, 320, 13) // "XsDeviceState"

    },
    "hmXDA\0log\0\0info\0mtwDisconnected\0"
    "deviceId\0mtwWireless\0dataAvailable\0"
    "hmData\0data\0stateChanged\0hmXDA_state\0"
    "newState\0oldState\0flushProgress\0current\0"
    "total\0loadFileProgress\0handleMtwDisconnected\0"
    "handleMtwWireless\0handlebatteryUpdateTimer\0"
    "handleDataAvailable\0handleFlushProgress\0"
    "handleLoadFileProgress\0handleMasterStateChanged\0"
    "XsDeviceState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hmXDA[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       7,    1,   93,    2, 0x06 /* Public */,
      10,    2,   96,    2, 0x06 /* Public */,
      14,    2,  101,    2, 0x06 /* Public */,
      17,    2,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  111,    2, 0x08 /* Private */,
      19,    1,  114,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,
      21,    1,  118,    2, 0x08 /* Private */,
      22,    2,  121,    2, 0x08 /* Private */,
      23,    2,  126,    2, 0x08 /* Private */,
      24,    2,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, 0x80000000 | 25, 0x80000000 | 25,   12,   13,

       0        // eod
};

void hmXDA::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hmXDA *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->mtwDisconnected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->mtwWireless((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 3: _t->dataAvailable((*reinterpret_cast< hmData(*)>(_a[1]))); break;
        case 4: _t->stateChanged((*reinterpret_cast< hmXDA_state(*)>(_a[1])),(*reinterpret_cast< hmXDA_state(*)>(_a[2]))); break;
        case 5: _t->flushProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->loadFileProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->handleMtwDisconnected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 8: _t->handleMtwWireless((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 9: _t->handlebatteryUpdateTimer(); break;
        case 10: _t->handleDataAvailable((*reinterpret_cast< hmData(*)>(_a[1]))); break;
        case 11: _t->handleFlushProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->handleLoadFileProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->handleMasterStateChanged((*reinterpret_cast< XsDeviceState(*)>(_a[1])),(*reinterpret_cast< XsDeviceState(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hmData >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hmXDA_state >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< hmData >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< XsDeviceState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hmXDA::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hmXDA::log)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hmXDA::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hmXDA::mtwDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (hmXDA::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hmXDA::mtwWireless)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (hmXDA::*)(hmData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hmXDA::dataAvailable)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (hmXDA::*)(hmXDA_state , hmXDA_state );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hmXDA::stateChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (hmXDA::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hmXDA::flushProgress)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (hmXDA::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hmXDA::loadFileProgress)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hmXDA::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_hmXDA.data,
    qt_meta_data_hmXDA,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *hmXDA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hmXDA::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hmXDA.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int hmXDA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void hmXDA::log(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hmXDA::mtwDisconnected(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void hmXDA::mtwWireless(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void hmXDA::dataAvailable(hmData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void hmXDA::stateChanged(hmXDA_state _t1, hmXDA_state _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void hmXDA::flushProgress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void hmXDA::loadFileProgress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
