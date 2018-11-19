/****************************************************************************
** Meta object code from reading C++ file 'CQScriptWrap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/CQScriptWrap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQScriptWrap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSTimer_t {
    QByteArrayData data[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSTimer_t qt_meta_stringdata_QSTimer = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QSTimer"
QT_MOC_LITERAL(1, 8, 7) // "timerId"

    },
    "QSTimer\0timerId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSTimer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095001,

       0        // eod
};

void QSTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSTimer *_t = static_cast<QSTimer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->timerId(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSTimer::staticMetaObject = {
    { &QTimer::staticMetaObject, qt_meta_stringdata_QSTimer.data,
      qt_meta_data_QSTimer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSTimer.stringdata0))
        return static_cast<void*>(this);
    return QTimer::qt_metacast(_clname);
}

int QSTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSInput_t {
    QByteArrayData data[17];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSInput_t qt_meta_stringdata_QSInput = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QSInput"
QT_MOC_LITERAL(1, 8, 7), // "getText"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "label"
QT_MOC_LITERAL(4, 23, 4), // "text"
QT_MOC_LITERAL(5, 28, 5), // "title"
QT_MOC_LITERAL(6, 34, 8), // "QWidget*"
QT_MOC_LITERAL(7, 43, 6), // "parent"
QT_MOC_LITERAL(8, 50, 9), // "getNumber"
QT_MOC_LITERAL(9, 60, 5), // "value"
QT_MOC_LITERAL(10, 66, 8), // "decimals"
QT_MOC_LITERAL(11, 75, 8), // "minValue"
QT_MOC_LITERAL(12, 84, 8), // "maxValue"
QT_MOC_LITERAL(13, 93, 7), // "getItem"
QT_MOC_LITERAL(14, 101, 8), // "itemList"
QT_MOC_LITERAL(15, 110, 11), // "currentItem"
QT_MOC_LITERAL(16, 122, 8) // "editable"

    },
    "QSInput\0getText\0\0label\0text\0title\0"
    "QWidget*\0parent\0getNumber\0value\0"
    "decimals\0minValue\0maxValue\0getItem\0"
    "itemList\0currentItem\0editable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,  124,    2, 0x0a /* Public */,
       1,    3,  133,    2, 0x2a /* Public | MethodCloned */,
       1,    2,  140,    2, 0x2a /* Public | MethodCloned */,
       1,    1,  145,    2, 0x2a /* Public | MethodCloned */,
       1,    0,  148,    2, 0x2a /* Public | MethodCloned */,
       8,    7,  149,    2, 0x0a /* Public */,
       8,    6,  164,    2, 0x2a /* Public | MethodCloned */,
       8,    5,  177,    2, 0x2a /* Public | MethodCloned */,
       8,    4,  188,    2, 0x2a /* Public | MethodCloned */,
       8,    3,  197,    2, 0x2a /* Public | MethodCloned */,
       8,    2,  204,    2, 0x2a /* Public | MethodCloned */,
       8,    1,  209,    2, 0x2a /* Public | MethodCloned */,
       8,    0,  212,    2, 0x2a /* Public | MethodCloned */,
      13,    6,  213,    2, 0x0a /* Public */,
      13,    5,  226,    2, 0x2a /* Public | MethodCloned */,
      13,    4,  237,    2, 0x2a /* Public | MethodCloned */,
      13,    3,  246,    2, 0x2a /* Public | MethodCloned */,
      13,    2,  253,    2, 0x2a /* Public | MethodCloned */,
      13,    4,  258,    2, 0x0a /* Public */,
      13,    3,  267,    2, 0x2a /* Public | MethodCloned */,
      13,    2,  274,    2, 0x2a /* Public | MethodCloned */,
      13,    1,  279,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6,    3,    4,    5,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::QVariant, QMetaType::QString,    3,
    QMetaType::QVariant,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::QString, 0x80000000 | 6,    3,    9,   10,   11,   12,    5,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::QString,    3,    9,   10,   11,   12,    5,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double,    3,    9,   10,   11,   12,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Double, QMetaType::Int, QMetaType::Double,    3,    9,   10,   11,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Double, QMetaType::Int,    3,    9,   10,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Double,    3,    9,
    QMetaType::QVariant, QMetaType::QString,    3,
    QMetaType::QVariant,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool, QMetaType::QString, 0x80000000 | 6,    3,   14,   15,   16,    5,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    3,   14,   15,   16,    5,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool,    3,   14,   15,   16,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QStringList, QMetaType::QString,    3,   14,   15,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QStringList,    3,   14,
    QMetaType::QVariant, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool, 0x80000000 | 6,   14,   15,   16,    7,
    QMetaType::QVariant, QMetaType::QStringList, QMetaType::QString, QMetaType::Bool,   14,   15,   16,
    QMetaType::QVariant, QMetaType::QStringList, QMetaType::QString,   14,   15,
    QMetaType::QVariant, QMetaType::QStringList,   14,

       0        // eod
};

void QSInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSInput *_t = static_cast<QSInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->getText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< QWidget*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 1: { QVariant _r = _t->getText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariant _r = _t->getText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { QVariant _r = _t->getText((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVariant _r = _t->getText();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 5: { QVariant _r = _t->getNumber((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< QWidget*(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariant _r = _t->getNumber((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariant _r = _t->getNumber((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 8: { QVariant _r = _t->getNumber((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 9: { QVariant _r = _t->getNumber((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 10: { QVariant _r = _t->getNumber((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 11: { QVariant _r = _t->getNumber((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 12: { QVariant _r = _t->getNumber();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 13: { QVariant _r = _t->getItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< QWidget*(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 14: { QVariant _r = _t->getItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 15: { QVariant _r = _t->getItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 16: { QVariant _r = _t->getItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 17: { QVariant _r = _t->getItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 18: { QVariant _r = _t->getItem((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QWidget*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 19: { QVariant _r = _t->getItem((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 20: { QVariant _r = _t->getItem((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 21: { QVariant _r = _t->getItem((*reinterpret_cast< const QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 6:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSInput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSInput.data,
      qt_meta_data_QSInput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSInput.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
struct qt_meta_stringdata_QSFileDialog_t {
    QByteArrayData data[11];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSFileDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSFileDialog_t qt_meta_stringdata_QSFileDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QSFileDialog"
QT_MOC_LITERAL(1, 13, 15), // "getOpenFileName"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "dir"
QT_MOC_LITERAL(4, 34, 6), // "filter"
QT_MOC_LITERAL(5, 41, 5), // "title"
QT_MOC_LITERAL(6, 47, 8), // "QWidget*"
QT_MOC_LITERAL(7, 56, 6), // "parent"
QT_MOC_LITERAL(8, 63, 15), // "getSaveFileName"
QT_MOC_LITERAL(9, 79, 20), // "getExistingDirectory"
QT_MOC_LITERAL(10, 100, 16) // "getOpenFileNames"

    },
    "QSFileDialog\0getOpenFileName\0\0dir\0"
    "filter\0title\0QWidget*\0parent\0"
    "getSaveFileName\0getExistingDirectory\0"
    "getOpenFileNames"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSFileDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,  104,    2, 0x0a /* Public */,
       1,    3,  113,    2, 0x2a /* Public | MethodCloned */,
       1,    2,  120,    2, 0x2a /* Public | MethodCloned */,
       1,    1,  125,    2, 0x2a /* Public | MethodCloned */,
       1,    0,  128,    2, 0x2a /* Public | MethodCloned */,
       8,    3,  129,    2, 0x0a /* Public */,
       8,    2,  136,    2, 0x2a /* Public | MethodCloned */,
       8,    1,  141,    2, 0x2a /* Public | MethodCloned */,
       8,    0,  144,    2, 0x2a /* Public | MethodCloned */,
       9,    3,  145,    2, 0x0a /* Public */,
       9,    2,  152,    2, 0x2a /* Public | MethodCloned */,
       9,    1,  157,    2, 0x2a /* Public | MethodCloned */,
       9,    0,  160,    2, 0x2a /* Public | MethodCloned */,
      10,    4,  161,    2, 0x0a /* Public */,
      10,    3,  170,    2, 0x2a /* Public | MethodCloned */,
      10,    2,  177,    2, 0x2a /* Public | MethodCloned */,
      10,    1,  182,    2, 0x2a /* Public | MethodCloned */,
      10,    0,  185,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6,    3,    4,    5,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::QVariant, QMetaType::QString,    3,
    QMetaType::QVariant,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::QVariant, QMetaType::QString,    4,
    QMetaType::QVariant,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString, 0x80000000 | 6,    3,    5,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    3,    5,
    QMetaType::QVariant, QMetaType::QString,    3,
    QMetaType::QVariant,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 6,    3,    4,    5,    7,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::QStringList, QMetaType::QString,    3,
    QMetaType::QStringList,

       0        // eod
};

void QSFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSFileDialog *_t = static_cast<QSFileDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->getOpenFileName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< QWidget*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 1: { QVariant _r = _t->getOpenFileName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariant _r = _t->getOpenFileName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { QVariant _r = _t->getOpenFileName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVariant _r = _t->getOpenFileName();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 5: { QVariant _r = _t->getSaveFileName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariant _r = _t->getSaveFileName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariant _r = _t->getSaveFileName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 8: { QVariant _r = _t->getSaveFileName();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 9: { QVariant _r = _t->getExistingDirectory((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 10: { QVariant _r = _t->getExistingDirectory((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 11: { QVariant _r = _t->getExistingDirectory((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 12: { QVariant _r = _t->getExistingDirectory();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 13: { QStringList _r = _t->getOpenFileNames((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< QWidget*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 14: { QStringList _r = _t->getOpenFileNames((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 15: { QStringList _r = _t->getOpenFileNames((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 16: { QStringList _r = _t->getOpenFileNames((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 17: { QStringList _r = _t->getOpenFileNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSFileDialog::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSFileDialog.data,
      qt_meta_data_QSFileDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSFileDialog.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
struct qt_meta_stringdata_QSMessageBox_t {
    QByteArrayData data[21];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSMessageBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSMessageBox_t qt_meta_stringdata_QSMessageBox = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QSMessageBox"
QT_MOC_LITERAL(1, 13, 11), // "information"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "text"
QT_MOC_LITERAL(4, 31, 10), // "ButtonType"
QT_MOC_LITERAL(5, 42, 7), // "button0"
QT_MOC_LITERAL(6, 50, 7), // "button1"
QT_MOC_LITERAL(7, 58, 7), // "button2"
QT_MOC_LITERAL(8, 66, 5), // "title"
QT_MOC_LITERAL(9, 72, 8), // "QWidget*"
QT_MOC_LITERAL(10, 81, 6), // "parent"
QT_MOC_LITERAL(11, 88, 7), // "warning"
QT_MOC_LITERAL(12, 96, 8), // "critical"
QT_MOC_LITERAL(13, 105, 8), // "NoButton"
QT_MOC_LITERAL(14, 114, 2), // "Ok"
QT_MOC_LITERAL(15, 117, 6), // "Cancel"
QT_MOC_LITERAL(16, 124, 3), // "Yes"
QT_MOC_LITERAL(17, 128, 2), // "No"
QT_MOC_LITERAL(18, 131, 5), // "Abort"
QT_MOC_LITERAL(19, 137, 5), // "Retry"
QT_MOC_LITERAL(20, 143, 6) // "Ignore"

    },
    "QSMessageBox\0information\0\0text\0"
    "ButtonType\0button0\0button1\0button2\0"
    "title\0QWidget*\0parent\0warning\0critical\0"
    "NoButton\0Ok\0Cancel\0Yes\0No\0Abort\0Retry\0"
    "Ignore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSMessageBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       1,  248, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    6,  104,    2, 0x0a /* Public */,
       1,    5,  117,    2, 0x2a /* Public | MethodCloned */,
       1,    4,  128,    2, 0x2a /* Public | MethodCloned */,
       1,    3,  137,    2, 0x2a /* Public | MethodCloned */,
       1,    2,  144,    2, 0x2a /* Public | MethodCloned */,
       1,    1,  149,    2, 0x2a /* Public | MethodCloned */,
      11,    6,  152,    2, 0x0a /* Public */,
      11,    5,  165,    2, 0x2a /* Public | MethodCloned */,
      11,    4,  176,    2, 0x2a /* Public | MethodCloned */,
      11,    3,  185,    2, 0x2a /* Public | MethodCloned */,
      11,    2,  192,    2, 0x2a /* Public | MethodCloned */,
      11,    1,  197,    2, 0x2a /* Public | MethodCloned */,
      12,    6,  200,    2, 0x0a /* Public */,
      12,    5,  213,    2, 0x2a /* Public | MethodCloned */,
      12,    4,  224,    2, 0x2a /* Public | MethodCloned */,
      12,    3,  233,    2, 0x2a /* Public | MethodCloned */,
      12,    2,  240,    2, 0x2a /* Public | MethodCloned */,
      12,    1,  245,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 9,    3,    5,    6,    7,    8,   10,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString,    3,    5,    6,    7,    8,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,    7,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 9,    3,    5,    6,    7,    8,   10,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString,    3,    5,    6,    7,    8,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,    7,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 9,    3,    5,    6,    7,    8,   10,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString,    3,    5,    6,    7,    8,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,    7,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Int, QMetaType::QString,    3,

 // enums: name, flags, count, data
       4, 0x0,    8,  252,

 // enum data: key, value
      13, uint(QSMessageBox::NoButton),
      14, uint(QSMessageBox::Ok),
      15, uint(QSMessageBox::Cancel),
      16, uint(QSMessageBox::Yes),
      17, uint(QSMessageBox::No),
      18, uint(QSMessageBox::Abort),
      19, uint(QSMessageBox::Retry),
      20, uint(QSMessageBox::Ignore),

       0        // eod
};

void QSMessageBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSMessageBox *_t = static_cast<QSMessageBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->information((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< QWidget*(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->information((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->information((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->information((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->information((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->information((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->warning((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< QWidget*(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->warning((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->warning((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->warning((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->warning((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->warning((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->critical((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< QWidget*(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->critical((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->critical((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])),(*reinterpret_cast< ButtonType(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->critical((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])),(*reinterpret_cast< ButtonType(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->critical((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< ButtonType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: { int _r = _t->critical((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSMessageBox::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSMessageBox.data,
      qt_meta_data_QSMessageBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSMessageBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSMessageBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSMessageBox.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSMessageBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
struct qt_meta_stringdata_QSWidget_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSWidget_t qt_meta_stringdata_QSWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QSWidget"
QT_MOC_LITERAL(1, 9, 9), // "whatsThis"
QT_MOC_LITERAL(2, 19, 7) // "toolTip"

    },
    "QSWidget\0whatsThis\0toolTip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::QString, 0x00095103,

       0        // eod
};

void QSWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSWidget *_t = static_cast<QSWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->whatsThis(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->toolTip(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSWidget *_t = static_cast<QSWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWhatsThis(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setToolTip(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSWidget::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSWidget.data,
      qt_meta_data_QSWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSWidget.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSLabel_t {
    QByteArrayData data[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSLabel_t qt_meta_stringdata_QSLabel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QSLabel"
QT_MOC_LITERAL(1, 8, 4) // "text"

    },
    "QSLabel\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,

       0        // eod
};

void QSLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSLabel *_t = static_cast<QSLabel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSLabel *_t = static_cast<QSLabel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSLabel::staticMetaObject = {
    { &QSWidget::staticMetaObject, qt_meta_stringdata_QSLabel.data,
      qt_meta_data_QSLabel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSLabel.stringdata0))
        return static_cast<void*>(this);
    return QSWidget::qt_metacast(_clname);
}

int QSLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSLabeled_t {
    QByteArrayData data[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSLabeled_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSLabeled_t qt_meta_stringdata_QSLabeled = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QSLabeled"
QT_MOC_LITERAL(1, 10, 5) // "label"

    },
    "QSLabeled\0label"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSLabeled[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,

       0        // eod
};

void QSLabeled::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSLabeled *_t = static_cast<QSLabeled *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->label(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSLabeled *_t = static_cast<QSLabeled *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLabel(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSLabeled::staticMetaObject = {
    { &QSWidget::staticMetaObject, qt_meta_stringdata_QSLabeled.data,
      qt_meta_data_QSLabeled,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSLabeled::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSLabeled::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSLabeled.stringdata0))
        return static_cast<void*>(this);
    return QSWidget::qt_metacast(_clname);
}

int QSLabeled::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSLineEdit_t {
    QByteArrayData data[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSLineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSLineEdit_t qt_meta_stringdata_QSLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSLineEdit"
QT_MOC_LITERAL(1, 11, 4) // "text"

    },
    "QSLineEdit\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSLineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,

       0        // eod
};

void QSLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSLineEdit *_t = static_cast<QSLineEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSLineEdit *_t = static_cast<QSLineEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSLineEdit::staticMetaObject = {
    { &QSLabeled::staticMetaObject, qt_meta_stringdata_QSLineEdit.data,
      qt_meta_data_QSLineEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSLineEdit.stringdata0))
        return static_cast<void*>(this);
    return QSLabeled::qt_metacast(_clname);
}

int QSLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLabeled::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSNumberEdit_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSNumberEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSNumberEdit_t qt_meta_stringdata_QSNumberEdit = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QSNumberEdit"
QT_MOC_LITERAL(1, 13, 5), // "value"
QT_MOC_LITERAL(2, 19, 8), // "decimals"
QT_MOC_LITERAL(3, 28, 7), // "minimum"
QT_MOC_LITERAL(4, 36, 7) // "maximum"

    },
    "QSNumberEdit\0value\0decimals\0minimum\0"
    "maximum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSNumberEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Double, 0x00095103,
       2, QMetaType::Double, 0x00095103,
       3, QMetaType::Double, 0x00095103,
       4, QMetaType::Double, 0x00095103,

       0        // eod
};

void QSNumberEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSNumberEdit *_t = static_cast<QSNumberEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->decimals(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->minimum(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->maximum(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSNumberEdit *_t = static_cast<QSNumberEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setDecimals(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setMinimum(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setMaximum(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSNumberEdit::staticMetaObject = {
    { &QSLabeled::staticMetaObject, qt_meta_stringdata_QSNumberEdit.data,
      qt_meta_data_QSNumberEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSNumberEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSNumberEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSNumberEdit.stringdata0))
        return static_cast<void*>(this);
    return QSLabeled::qt_metacast(_clname);
}

int QSNumberEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLabeled::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSDateEditEnums_t {
    QByteArrayData data[6];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSDateEditEnums_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSDateEditEnums_t qt_meta_stringdata_QSDateEditEnums = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QSDateEditEnums"
QT_MOC_LITERAL(1, 16, 5), // "Order"
QT_MOC_LITERAL(2, 22, 3), // "DMY"
QT_MOC_LITERAL(3, 26, 3), // "MDY"
QT_MOC_LITERAL(4, 30, 3), // "YMD"
QT_MOC_LITERAL(5, 34, 3) // "YDM"

    },
    "QSDateEditEnums\0Order\0DMY\0MDY\0YMD\0YDM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSDateEditEnums[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    4,   18,

 // enum data: key, value
       2, uint(QSDateEditEnums::DMY),
       3, uint(QSDateEditEnums::MDY),
       4, uint(QSDateEditEnums::YMD),
       5, uint(QSDateEditEnums::YDM),

       0        // eod
};

void QSDateEditEnums::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSDateEditEnums::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSDateEditEnums.data,
      qt_meta_data_QSDateEditEnums,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSDateEditEnums::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSDateEditEnums::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSDateEditEnums.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSDateEditEnums::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_QSDateEdit_t {
    QByteArrayData data[10];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSDateEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSDateEdit_t qt_meta_stringdata_QSDateEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSDateEdit"
QT_MOC_LITERAL(1, 11, 5), // "order"
QT_MOC_LITERAL(2, 17, 4), // "date"
QT_MOC_LITERAL(3, 22, 7), // "minimum"
QT_MOC_LITERAL(4, 30, 7), // "maximum"
QT_MOC_LITERAL(5, 38, 5), // "Order"
QT_MOC_LITERAL(6, 44, 3), // "DMY"
QT_MOC_LITERAL(7, 48, 3), // "MDY"
QT_MOC_LITERAL(8, 52, 3), // "YMD"
QT_MOC_LITERAL(9, 56, 3) // "YDM"

    },
    "QSDateEdit\0order\0date\0minimum\0maximum\0"
    "Order\0DMY\0MDY\0YMD\0YDM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSDateEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       4,   14, // properties
       1,   26, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095103,
       2, QMetaType::QDate, 0x00095103,
       3, QMetaType::QDate, 0x00095103,
       4, QMetaType::QDate, 0x00095103,

 // enums: name, flags, count, data
       5, 0x0,    4,   30,

 // enum data: key, value
       6, uint(QSDateEdit::DMY),
       7, uint(QSDateEdit::MDY),
       8, uint(QSDateEdit::YMD),
       9, uint(QSDateEdit::YDM),

       0        // eod
};

void QSDateEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSDateEdit *_t = static_cast<QSDateEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->order(); break;
        case 1: *reinterpret_cast< QDate*>(_v) = _t->date(); break;
        case 2: *reinterpret_cast< QDate*>(_v) = _t->minimum(); break;
        case 3: *reinterpret_cast< QDate*>(_v) = _t->maximum(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSDateEdit *_t = static_cast<QSDateEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOrder(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setDate(*reinterpret_cast< QDate*>(_v)); break;
        case 2: _t->setMinimum(*reinterpret_cast< QDate*>(_v)); break;
        case 3: _t->setMaximum(*reinterpret_cast< QDate*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSDateEdit::staticMetaObject = {
    { &QSLabeled::staticMetaObject, qt_meta_stringdata_QSDateEdit.data,
      qt_meta_data_QSDateEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSDateEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSDateEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSDateEdit.stringdata0))
        return static_cast<void*>(this);
    return QSLabeled::qt_metacast(_clname);
}

int QSDateEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLabeled::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSTimeEdit_t {
    QByteArrayData data[6];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSTimeEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSTimeEdit_t qt_meta_stringdata_QSTimeEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSTimeEdit"
QT_MOC_LITERAL(1, 11, 11), // "showSeconds"
QT_MOC_LITERAL(2, 23, 8), // "showAMPM"
QT_MOC_LITERAL(3, 32, 4), // "time"
QT_MOC_LITERAL(4, 37, 7), // "minimum"
QT_MOC_LITERAL(5, 45, 7) // "maximum"

    },
    "QSTimeEdit\0showSeconds\0showAMPM\0time\0"
    "minimum\0maximum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSTimeEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Bool, 0x00095003,
       2, QMetaType::Bool, 0x00095003,
       3, QMetaType::QTime, 0x00095103,
       4, QMetaType::QTime, 0x00095103,
       5, QMetaType::QTime, 0x00095103,

       0        // eod
};

void QSTimeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSTimeEdit *_t = static_cast<QSTimeEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->seconds(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->ampm(); break;
        case 2: *reinterpret_cast< QTime*>(_v) = _t->time(); break;
        case 3: *reinterpret_cast< QTime*>(_v) = _t->minimum(); break;
        case 4: *reinterpret_cast< QTime*>(_v) = _t->maximum(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSTimeEdit *_t = static_cast<QSTimeEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSeconds(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setAmpm(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setTime(*reinterpret_cast< QTime*>(_v)); break;
        case 3: _t->setMinimum(*reinterpret_cast< QTime*>(_v)); break;
        case 4: _t->setMaximum(*reinterpret_cast< QTime*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSTimeEdit::staticMetaObject = {
    { &QSLabeled::staticMetaObject, qt_meta_stringdata_QSTimeEdit.data,
      qt_meta_data_QSTimeEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSTimeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSTimeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSTimeEdit.stringdata0))
        return static_cast<void*>(this);
    return QSLabeled::qt_metacast(_clname);
}

int QSTimeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLabeled::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSTextEdit_t {
    QByteArrayData data[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSTextEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSTextEdit_t qt_meta_stringdata_QSTextEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSTextEdit"
QT_MOC_LITERAL(1, 11, 4) // "text"

    },
    "QSTextEdit\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSTextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,

       0        // eod
};

void QSTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSTextEdit *_t = static_cast<QSTextEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSTextEdit *_t = static_cast<QSTextEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSTextEdit::staticMetaObject = {
    { &QSWidget::staticMetaObject, qt_meta_stringdata_QSTextEdit.data,
      qt_meta_data_QSTextEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSTextEdit.stringdata0))
        return static_cast<void*>(this);
    return QSWidget::qt_metacast(_clname);
}

int QSTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSSpinBox_t {
    QByteArrayData data[4];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSSpinBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSSpinBox_t qt_meta_stringdata_QSSpinBox = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QSSpinBox"
QT_MOC_LITERAL(1, 10, 5), // "value"
QT_MOC_LITERAL(2, 16, 7), // "minimum"
QT_MOC_LITERAL(3, 24, 7) // "maximum"

    },
    "QSSpinBox\0value\0minimum\0maximum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSSpinBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095103,
       2, QMetaType::Int, 0x00095103,
       3, QMetaType::Int, 0x00095103,

       0        // eod
};

void QSSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSSpinBox *_t = static_cast<QSSpinBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->minimum(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->maximum(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSSpinBox *_t = static_cast<QSSpinBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setMinimum(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setMaximum(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSSpinBox::staticMetaObject = {
    { &QSLabeled::staticMetaObject, qt_meta_stringdata_QSSpinBox.data,
      qt_meta_data_QSSpinBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSSpinBox.stringdata0))
        return static_cast<void*>(this);
    return QSLabeled::qt_metacast(_clname);
}

int QSSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLabeled::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSCheckBox_t {
    QByteArrayData data[3];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSCheckBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSCheckBox_t qt_meta_stringdata_QSCheckBox = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSCheckBox"
QT_MOC_LITERAL(1, 11, 4), // "text"
QT_MOC_LITERAL(2, 16, 7) // "checked"

    },
    "QSCheckBox\0text\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSCheckBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::Bool, 0x00095103,

       0        // eod
};

void QSCheckBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSCheckBox *_t = static_cast<QSCheckBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isChecked(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSCheckBox *_t = static_cast<QSCheckBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setChecked(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSCheckBox::staticMetaObject = {
    { &QSWidget::staticMetaObject, qt_meta_stringdata_QSCheckBox.data,
      qt_meta_data_QSCheckBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSCheckBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSCheckBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSCheckBox.stringdata0))
        return static_cast<void*>(this);
    return QSWidget::qt_metacast(_clname);
}

int QSCheckBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSRadioButton_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSRadioButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSRadioButton_t qt_meta_stringdata_QSRadioButton = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSRadioButton"
QT_MOC_LITERAL(1, 14, 4), // "text"
QT_MOC_LITERAL(2, 19, 7) // "checked"

    },
    "QSRadioButton\0text\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSRadioButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::Bool, 0x00095103,

       0        // eod
};

void QSRadioButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSRadioButton *_t = static_cast<QSRadioButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isChecked(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSRadioButton *_t = static_cast<QSRadioButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setChecked(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSRadioButton::staticMetaObject = {
    { &QSWidget::staticMetaObject, qt_meta_stringdata_QSRadioButton.data,
      qt_meta_data_QSRadioButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSRadioButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSRadioButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSRadioButton.stringdata0))
        return static_cast<void*>(this);
    return QSWidget::qt_metacast(_clname);
}

int QSRadioButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSComboBox_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSComboBox_t qt_meta_stringdata_QSComboBox = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSComboBox"
QT_MOC_LITERAL(1, 11, 8), // "itemList"
QT_MOC_LITERAL(2, 20, 11), // "currentItem"
QT_MOC_LITERAL(3, 32, 8) // "editable"

    },
    "QSComboBox\0itemList\0currentItem\0"
    "editable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       3,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QStringList, 0x00095103,
       2, QMetaType::QString, 0x00095103,
       3, QMetaType::Bool, 0x00095103,

       0        // eod
};

void QSComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QSComboBox *_t = static_cast<QSComboBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->itemList(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentItem(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isEditable(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSComboBox *_t = static_cast<QSComboBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setItemList(*reinterpret_cast< QStringList*>(_v)); break;
        case 1: _t->setCurrentItem(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setEditable(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QSComboBox::staticMetaObject = {
    { &QSLabeled::staticMetaObject, qt_meta_stringdata_QSComboBox.data,
      qt_meta_data_QSComboBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSComboBox.stringdata0))
        return static_cast<void*>(this);
    return QSLabeled::qt_metacast(_clname);
}

int QSComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSLabeled::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSGroupBox_t {
    QByteArrayData data[9];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSGroupBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSGroupBox_t qt_meta_stringdata_QSGroupBox = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QSGroupBox"
QT_MOC_LITERAL(1, 11, 3), // "add"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 9), // "QSWidget*"
QT_MOC_LITERAL(4, 26, 6), // "widget"
QT_MOC_LITERAL(5, 33, 9), // "newColumn"
QT_MOC_LITERAL(6, 43, 8), // "addSpace"
QT_MOC_LITERAL(7, 52, 5), // "space"
QT_MOC_LITERAL(8, 58, 5) // "title"

    },
    "QSGroupBox\0add\0\0QSWidget*\0widget\0"
    "newColumn\0addSpace\0space\0title"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSGroupBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   36, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    1,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00095103,

       0        // eod
};

void QSGroupBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSGroupBox *_t = static_cast<QSGroupBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add((*reinterpret_cast< QSWidget*(*)>(_a[1]))); break;
        case 1: _t->newColumn(); break;
        case 2: _t->addSpace((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSWidget* >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QSGroupBox *_t = static_cast<QSGroupBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSGroupBox *_t = static_cast<QSGroupBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QSGroupBox::staticMetaObject = {
    { &QSWidget::staticMetaObject, qt_meta_stringdata_QSGroupBox.data,
      qt_meta_data_QSGroupBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSGroupBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSGroupBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSGroupBox.stringdata0))
        return static_cast<void*>(this);
    return QSWidget::qt_metacast(_clname);
}

int QSGroupBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSDialog_t {
    QByteArrayData data[15];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSDialog_t qt_meta_stringdata_QSDialog = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QSDialog"
QT_MOC_LITERAL(1, 9, 6), // "newTab"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "label"
QT_MOC_LITERAL(4, 23, 9), // "newColumn"
QT_MOC_LITERAL(5, 33, 8), // "addSpace"
QT_MOC_LITERAL(6, 42, 5), // "space"
QT_MOC_LITERAL(7, 48, 3), // "add"
QT_MOC_LITERAL(8, 52, 9), // "QSWidget*"
QT_MOC_LITERAL(9, 62, 6), // "widget"
QT_MOC_LITERAL(10, 69, 4), // "exec"
QT_MOC_LITERAL(11, 74, 5), // "title"
QT_MOC_LITERAL(12, 80, 5), // "width"
QT_MOC_LITERAL(13, 86, 12), // "okButtonText"
QT_MOC_LITERAL(14, 99, 16) // "cancelButtonText"

    },
    "QSDialog\0newTab\0\0label\0newColumn\0"
    "addSpace\0space\0add\0QSWidget*\0widget\0"
    "exec\0title\0width\0okButtonText\0"
    "cancelButtonText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Bool,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::Int, 0x00095103,
      13, QMetaType::QString, 0x00095103,
      14, QMetaType::QString, 0x00095103,

       0        // eod
};

void QSDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSDialog *_t = static_cast<QSDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newTab((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->newColumn(); break;
        case 2: _t->addSpace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->add((*reinterpret_cast< QSWidget*(*)>(_a[1]))); break;
        case 4: { bool _r = _t->exec();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSWidget* >(); break;
            }
            break;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QSDialog *_t = static_cast<QSDialog *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->width(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->okButtonText(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->cancelButtonText(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSDialog *_t = static_cast<QSDialog *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setWidth(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setOkButtonText(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCancelButtonText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QSDialog::staticMetaObject = {
    { &QSWidget::staticMetaObject, qt_meta_stringdata_QSDialog.data,
      qt_meta_data_QSDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSDialog.stringdata0))
        return static_cast<void*>(this);
    return QSWidget::qt_metacast(_clname);
}

int QSDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_QSButtonGroup_t {
    QByteArrayData data[17];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSButtonGroup_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSButtonGroup_t qt_meta_stringdata_QSButtonGroup = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSButtonGroup"
QT_MOC_LITERAL(1, 14, 13), // "ButtonToggled"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "id"
QT_MOC_LITERAL(4, 32, 7), // "checked"
QT_MOC_LITERAL(5, 40, 13), // "ButtonClicked"
QT_MOC_LITERAL(6, 54, 13), // "ButtonPressed"
QT_MOC_LITERAL(7, 68, 14), // "ButtonReleased"
QT_MOC_LITERAL(8, 83, 11), // "addQSButton"
QT_MOC_LITERAL(9, 95, 16), // "QAbstractButton*"
QT_MOC_LITERAL(10, 112, 6), // "widget"
QT_MOC_LITERAL(11, 119, 9), // "CheckedID"
QT_MOC_LITERAL(12, 129, 5), // "BtnID"
QT_MOC_LITERAL(13, 135, 6), // "button"
QT_MOC_LITERAL(14, 142, 3), // "Btn"
QT_MOC_LITERAL(15, 146, 12), // "RemoveButton"
QT_MOC_LITERAL(16, 159, 8) // "SetBtnID"

    },
    "QSButtonGroup\0ButtonToggled\0\0id\0checked\0"
    "ButtonClicked\0ButtonPressed\0ButtonReleased\0"
    "addQSButton\0QAbstractButton*\0widget\0"
    "CheckedID\0BtnID\0button\0Btn\0RemoveButton\0"
    "SetBtnID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSButtonGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       6,    1,   77,    2, 0x06 /* Public */,
       7,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   83,    2, 0x0a /* Public */,
       8,    2,   86,    2, 0x0a /* Public */,
      11,    0,   91,    2, 0x0a /* Public */,
      12,    1,   92,    2, 0x0a /* Public */,
      14,    1,   95,    2, 0x0a /* Public */,
      15,    1,   98,    2, 0x0a /* Public */,
      16,    2,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,    3,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 9,   13,
    QMetaType::QObjectStar, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 9,   13,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   13,    3,

       0        // eod
};

void QSButtonGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSButtonGroup *_t = static_cast<QSButtonGroup *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ButtonToggled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->ButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ButtonReleased((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->addQSButton((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 5: _t->addQSButton((*reinterpret_cast< QAbstractButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: { int _r = _t->CheckedID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->BtnID((*reinterpret_cast< QAbstractButton*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { QObject* _r = _t->Btn((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->RemoveButton((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 10: _t->SetBtnID((*reinterpret_cast< QAbstractButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSButtonGroup::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSButtonGroup::ButtonToggled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QSButtonGroup::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSButtonGroup::ButtonClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QSButtonGroup::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSButtonGroup::ButtonPressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QSButtonGroup::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSButtonGroup::ButtonReleased)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSButtonGroup::staticMetaObject = {
    { &QButtonGroup::staticMetaObject, qt_meta_stringdata_QSButtonGroup.data,
      qt_meta_data_QSButtonGroup,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSButtonGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSButtonGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSButtonGroup.stringdata0))
        return static_cast<void*>(this);
    return QButtonGroup::qt_metacast(_clname);
}

int QSButtonGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QButtonGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QSButtonGroup::ButtonToggled(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSButtonGroup::ButtonClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSButtonGroup::ButtonPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QSButtonGroup::ButtonReleased(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_File_t {
    QByteArrayData data[15];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_File_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_File_t qt_meta_stringdata_File = {
    {
QT_MOC_LITERAL(0, 0, 4), // "File"
QT_MOC_LITERAL(1, 5, 4), // "Read"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 4), // "type"
QT_MOC_LITERAL(4, 16, 5), // "Write"
QT_MOC_LITERAL(5, 22, 3), // "val"
QT_MOC_LITERAL(6, 26, 4), // "Open"
QT_MOC_LITERAL(7, 31, 8), // "fileName"
QT_MOC_LITERAL(8, 40, 4), // "mode"
QT_MOC_LITERAL(9, 45, 12), // "SetByteOrder"
QT_MOC_LITERAL(10, 58, 2), // "bo"
QT_MOC_LITERAL(11, 61, 5), // "Close"
QT_MOC_LITERAL(12, 67, 5), // "Clear"
QT_MOC_LITERAL(13, 73, 14), // "Utf8codecArray"
QT_MOC_LITERAL(14, 88, 3) // "str"

    },
    "File\0Read\0\0type\0Write\0val\0Open\0fileName\0"
    "mode\0SetByteOrder\0bo\0Close\0Clear\0"
    "Utf8codecArray\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_File[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    2,   57,    2, 0x0a /* Public */,
       6,    2,   62,    2, 0x0a /* Public */,
       6,    1,   67,    2, 0x2a /* Public | MethodCloned */,
       9,    1,   70,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,
      12,    0,   74,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QString,    3,
    QMetaType::Int, QMetaType::QString, QMetaType::QVariant,    3,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QStringList, QMetaType::QString,   14,

       0        // eod
};

void File::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        File *_t = static_cast<File *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->Read((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->Write((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->Open((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->Open((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->SetByteOrder((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->Close(); break;
        case 6: _t->Clear(); break;
        case 7: { QStringList _r = _t->Utf8codecArray((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject File::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_File.data,
      qt_meta_data_File,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *File::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *File::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_File.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int File::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
struct qt_meta_stringdata_QSManager_t {
    QByteArrayData data[9];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSManager_t qt_meta_stringdata_QSManager = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QSManager"
QT_MOC_LITERAL(1, 10, 7), // "LoadDLL"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "dllName"
QT_MOC_LITERAL(4, 27, 7), // "ObjName"
QT_MOC_LITERAL(5, 35, 6), // "Create"
QT_MOC_LITERAL(6, 42, 7), // "context"
QT_MOC_LITERAL(7, 50, 7), // "Include"
QT_MOC_LITERAL(8, 58, 12) // "filePathName"

    },
    "QSManager\0LoadDLL\0\0dllName\0ObjName\0"
    "Create\0context\0Include\0filePathName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       5,    1,   34,    2, 0x0a /* Public */,
       7,    1,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QString,    8,

       0        // eod
};

void QSManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSManager *_t = static_cast<QSManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->LoadDLL((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->Create((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->Include((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSManager.data,
      qt_meta_data_QSManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
