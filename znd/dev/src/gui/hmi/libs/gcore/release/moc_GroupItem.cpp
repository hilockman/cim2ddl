/****************************************************************************
** Meta object code from reading C++ file 'GroupItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GroupItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GroupItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGroupData_t {
    QByteArrayData data[6];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGroupData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGroupData_t qt_meta_stringdata_CGroupData = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGroupData"
QT_MOC_LITERAL(1, 11, 10), // "ResetColor"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "COLOR_TYPE"
QT_MOC_LITERAL(4, 34, 4), // "type"
QT_MOC_LITERAL(5, 39, 15) // "IsIconContainer"

    },
    "CGroupData\0ResetColor\0\0COLOR_TYPE\0"
    "type\0IsIconContainer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGroupData[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       1,    0,   32,    2, 0x2a /* Public | MethodCloned */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void CGroupData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGroupData *_t = static_cast<CGroupData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ResetColor((*reinterpret_cast< COLOR_TYPE(*)>(_a[1]))); break;
        case 1: _t->ResetColor(); break;
        case 2: { bool _r = _t->IsIconContainer();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGroupData::staticMetaObject = {
    { &CAbstractScaleData::staticMetaObject, qt_meta_stringdata_CGroupData.data,
      qt_meta_data_CGroupData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGroupData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGroupData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGroupData.stringdata0))
        return static_cast<void*>(this);
    return CAbstractScaleData::qt_metacast(_clname);
}

int CGroupData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CAbstractScaleData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CIconData_t {
    QByteArrayData data[29];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CIconData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CIconData_t qt_meta_stringdata_CIconData = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CIconData"
QT_MOC_LITERAL(1, 10, 8), // "GetLinks"
QT_MOC_LITERAL(2, 19, 11), // "QObjectList"
QT_MOC_LITERAL(3, 31, 0), // ""
QT_MOC_LITERAL(4, 32, 3), // "pid"
QT_MOC_LITERAL(5, 36, 8), // "GetNodes"
QT_MOC_LITERAL(6, 45, 12), // "SetStateNums"
QT_MOC_LITERAL(7, 58, 9), // "stateNums"
QT_MOC_LITERAL(8, 68, 12), // "GetStateNums"
QT_MOC_LITERAL(9, 81, 12), // "SetPlaneNums"
QT_MOC_LITERAL(10, 94, 4), // "nums"
QT_MOC_LITERAL(11, 99, 12), // "GetPlaneNums"
QT_MOC_LITERAL(12, 112, 11), // "IsNullPlane"
QT_MOC_LITERAL(13, 124, 7), // "planeNo"
QT_MOC_LITERAL(14, 132, 8), // "SetState"
QT_MOC_LITERAL(15, 141, 5), // "state"
QT_MOC_LITERAL(16, 147, 15), // "GetTemplateName"
QT_MOC_LITERAL(17, 163, 15), // "SetTemplateName"
QT_MOC_LITERAL(18, 179, 4), // "name"
QT_MOC_LITERAL(19, 184, 8), // "instance"
QT_MOC_LITERAL(20, 193, 8), // "SetIfRef"
QT_MOC_LITERAL(21, 202, 5), // "ifRef"
QT_MOC_LITERAL(22, 208, 8), // "GetIfRef"
QT_MOC_LITERAL(23, 217, 11), // "SetIconType"
QT_MOC_LITERAL(24, 229, 5), // "iType"
QT_MOC_LITERAL(25, 235, 11), // "GetIconType"
QT_MOC_LITERAL(26, 247, 11), // "IsPowerIcon"
QT_MOC_LITERAL(27, 259, 9), // "iconClass"
QT_MOC_LITERAL(28, 269, 12) // "templateName"

    },
    "CIconData\0GetLinks\0QObjectList\0\0pid\0"
    "GetNodes\0SetStateNums\0stateNums\0"
    "GetStateNums\0SetPlaneNums\0nums\0"
    "GetPlaneNums\0IsNullPlane\0planeNo\0"
    "SetState\0state\0GetTemplateName\0"
    "SetTemplateName\0name\0instance\0SetIfRef\0"
    "ifRef\0GetIfRef\0SetIconType\0iType\0"
    "GetIconType\0IsPowerIcon\0iconClass\0"
    "templateName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CIconData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       3,  144, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    3, 0x0a /* Public */,
       1,    0,  107,    3, 0x2a /* Public | MethodCloned */,
       5,    1,  108,    3, 0x0a /* Public */,
       5,    0,  111,    3, 0x2a /* Public | MethodCloned */,
       6,    1,  112,    3, 0x0a /* Public */,
       8,    0,  115,    3, 0x0a /* Public */,
       9,    1,  116,    3, 0x0a /* Public */,
      11,    0,  119,    3, 0x0a /* Public */,
      12,    1,  120,    3, 0x0a /* Public */,
      14,    1,  123,    3, 0x0a /* Public */,
      16,    0,  126,    3, 0x0a /* Public */,
      17,    2,  127,    3, 0x0a /* Public */,
      17,    1,  132,    3, 0x2a /* Public | MethodCloned */,
      20,    1,  135,    3, 0x0a /* Public */,
      22,    0,  138,    3, 0x0a /* Public */,
      23,    1,  139,    3, 0x0a /* Public */,
      25,    0,  142,    3, 0x0a /* Public */,
      26,    0,  143,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString,    4,
    0x80000000 | 2,
    0x80000000 | 2, QMetaType::QString,    4,
    0x80000000 | 2,
    QMetaType::Void, QMetaType::Short,    7,
    QMetaType::Short,
    QMetaType::Void, QMetaType::Short,   10,
    QMetaType::Short,
    QMetaType::Bool, QMetaType::Short,   13,
    QMetaType::Void, QMetaType::Short,   15,
    QMetaType::QString,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   18,   19,
    QMetaType::Int, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Int,
    QMetaType::Bool,

 // properties: name, type, flags
      27, QMetaType::Int, 0x00095001,
      28, QMetaType::QString, 0x00095001,
      21, QMetaType::Bool, 0x00095003,

       0        // eod
};

void CIconData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CIconData *_t = static_cast<CIconData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QObjectList _r = _t->GetLinks((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 1: { QObjectList _r = _t->GetLinks();
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 2: { QObjectList _r = _t->GetNodes((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 3: { QObjectList _r = _t->GetNodes();
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->SetStateNums((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 5: { short _r = _t->GetStateNums();
            if (_a[0]) *reinterpret_cast< short*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->SetPlaneNums((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 7: { short _r = _t->GetPlaneNums();
            if (_a[0]) *reinterpret_cast< short*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->IsNullPlane((*reinterpret_cast< short(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->SetState((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 10: { QString _r = _t->GetTemplateName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->SetTemplateName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->SetTemplateName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->SetIfRef((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: { bool _r = _t->GetIfRef();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->SetIconType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: { int _r = _t->GetIconType();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->IsPowerIcon();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CIconData *_t = static_cast<CIconData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->GetIconType(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->GetTemplateName(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->GetIfRef(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CIconData *_t = static_cast<CIconData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->SetIfRef(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CIconData::staticMetaObject = {
    { &CGroupData::staticMetaObject, qt_meta_stringdata_CIconData.data,
      qt_meta_data_CIconData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CIconData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CIconData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CIconData.stringdata0))
        return static_cast<void*>(this);
    return CGroupData::qt_metacast(_clname);
}

int CIconData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CGroupData::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
