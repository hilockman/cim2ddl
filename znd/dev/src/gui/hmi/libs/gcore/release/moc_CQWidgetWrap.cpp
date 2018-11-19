/****************************************************************************
** Meta object code from reading C++ file 'CQWidgetWrap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/CQWidgetWrap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQWidgetWrap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGSpinBox_t {
    QByteArrayData data[11];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGSpinBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGSpinBox_t qt_meta_stringdata_CGSpinBox = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CGSpinBox"
QT_MOC_LITERAL(1, 10, 12), // "ValueChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "text"
QT_MOC_LITERAL(4, 29, 14), // "OnValueChanged"
QT_MOC_LITERAL(5, 44, 1), // "Q"
QT_MOC_LITERAL(6, 46, 10), // "CBaseData*"
QT_MOC_LITERAL(7, 57, 11), // "SetProperty"
QT_MOC_LITERAL(8, 69, 4), // "name"
QT_MOC_LITERAL(9, 74, 5), // "value"
QT_MOC_LITERAL(10, 80, 8) // "Property"

    },
    "CGSpinBox\0ValueChanged\0\0text\0"
    "OnValueChanged\0Q\0CBaseData*\0SetProperty\0"
    "name\0value\0Property"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGSpinBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       5,    0,   45,    2, 0x0a /* Public */,
       7,    2,   46,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    0x80000000 | 6,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    8,    9,
    QMetaType::QVariant, QMetaType::QString,    8,

       0        // eod
};

void CGSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGSpinBox *_t = static_cast<CGSpinBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ValueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OnValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 4: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGSpinBox::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGSpinBox::ValueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGSpinBox::staticMetaObject = {
    { &QSpinBox::staticMetaObject, qt_meta_stringdata_CGSpinBox.data,
      qt_meta_data_CGSpinBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGSpinBox.stringdata0))
        return static_cast<void*>(this);
    return QSpinBox::qt_metacast(_clname);
}

int CGSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CGSpinBox::ValueChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CGDoubleSpinBox_t {
    QByteArrayData data[11];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGDoubleSpinBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGDoubleSpinBox_t qt_meta_stringdata_CGDoubleSpinBox = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CGDoubleSpinBox"
QT_MOC_LITERAL(1, 16, 12), // "ValueChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "text"
QT_MOC_LITERAL(4, 35, 14), // "OnValueChanged"
QT_MOC_LITERAL(5, 50, 1), // "Q"
QT_MOC_LITERAL(6, 52, 10), // "CBaseData*"
QT_MOC_LITERAL(7, 63, 11), // "SetProperty"
QT_MOC_LITERAL(8, 75, 4), // "name"
QT_MOC_LITERAL(9, 80, 5), // "value"
QT_MOC_LITERAL(10, 86, 8) // "Property"

    },
    "CGDoubleSpinBox\0ValueChanged\0\0text\0"
    "OnValueChanged\0Q\0CBaseData*\0SetProperty\0"
    "name\0value\0Property"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGDoubleSpinBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x08 /* Private */,
       5,    0,   45,    2, 0x0a /* Public */,
       7,    2,   46,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    0x80000000 | 6,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    8,    9,
    QMetaType::QVariant, QMetaType::QString,    8,

       0        // eod
};

void CGDoubleSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGDoubleSpinBox *_t = static_cast<CGDoubleSpinBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ValueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OnValueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 4: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGDoubleSpinBox::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGDoubleSpinBox::ValueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGDoubleSpinBox::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_CGDoubleSpinBox.data,
      qt_meta_data_CGDoubleSpinBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGDoubleSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGDoubleSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGDoubleSpinBox.stringdata0))
        return static_cast<void*>(this);
    return QDoubleSpinBox::qt_metacast(_clname);
}

int CGDoubleSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CGDoubleSpinBox::ValueChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CGComboBox_t {
    QByteArrayData data[40];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGComboBox_t qt_meta_stringdata_CGComboBox = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGComboBox"
QT_MOC_LITERAL(1, 11, 19), // "CurrentIndexChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "index"
QT_MOC_LITERAL(4, 38, 4), // "text"
QT_MOC_LITERAL(5, 43, 4), // "data"
QT_MOC_LITERAL(6, 48, 18), // "RequestContextMenu"
QT_MOC_LITERAL(7, 67, 12), // "currentIndex"
QT_MOC_LITERAL(8, 80, 18), // "ContextMenuClicked"
QT_MOC_LITERAL(9, 99, 8), // "menu_txt"
QT_MOC_LITERAL(10, 108, 8), // "act_info"
QT_MOC_LITERAL(11, 117, 1), // "Q"
QT_MOC_LITERAL(12, 119, 10), // "CBaseData*"
QT_MOC_LITERAL(13, 130, 11), // "SetProperty"
QT_MOC_LITERAL(14, 142, 4), // "name"
QT_MOC_LITERAL(15, 147, 5), // "value"
QT_MOC_LITERAL(16, 153, 8), // "Property"
QT_MOC_LITERAL(17, 162, 8), // "ItemList"
QT_MOC_LITERAL(18, 171, 11), // "SetItemList"
QT_MOC_LITERAL(19, 183, 1), // "l"
QT_MOC_LITERAL(20, 185, 7), // "AddItem"
QT_MOC_LITERAL(21, 193, 8), // "userData"
QT_MOC_LITERAL(22, 202, 10), // "InsertItem"
QT_MOC_LITERAL(23, 213, 11), // "CurrentData"
QT_MOC_LITERAL(24, 225, 8), // "FindData"
QT_MOC_LITERAL(25, 234, 4), // "role"
QT_MOC_LITERAL(26, 239, 8), // "FindText"
QT_MOC_LITERAL(27, 248, 10), // "RemoveItem"
QT_MOC_LITERAL(28, 259, 3), // "idx"
QT_MOC_LITERAL(29, 263, 15), // "ShowContextMenu"
QT_MOC_LITERAL(30, 279, 9), // "menuArray"
QT_MOC_LITERAL(31, 289, 15), // "EnableCompleter"
QT_MOC_LITERAL(32, 305, 7), // "enabled"
QT_MOC_LITERAL(33, 313, 12), // "SetShowAbove"
QT_MOC_LITERAL(34, 326, 5), // "above"
QT_MOC_LITERAL(35, 332, 13), // "SetViewHeight"
QT_MOC_LITERAL(36, 346, 6), // "height"
QT_MOC_LITERAL(37, 353, 13), // "OnItemChanged"
QT_MOC_LITERAL(38, 367, 20), // "OnContextMenuClicked"
QT_MOC_LITERAL(39, 388, 8) // "itemList"

    },
    "CGComboBox\0CurrentIndexChanged\0\0index\0"
    "text\0data\0RequestContextMenu\0currentIndex\0"
    "ContextMenuClicked\0menu_txt\0act_info\0"
    "Q\0CBaseData*\0SetProperty\0name\0value\0"
    "Property\0ItemList\0SetItemList\0l\0AddItem\0"
    "userData\0InsertItem\0CurrentData\0"
    "FindData\0role\0FindText\0RemoveItem\0idx\0"
    "ShowContextMenu\0menuArray\0EnableCompleter\0"
    "enabled\0SetShowAbove\0above\0SetViewHeight\0"
    "height\0OnItemChanged\0OnContextMenuClicked\0"
    "itemList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       1,  238, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  149,    2, 0x06 /* Public */,
       6,    3,  156,    2, 0x06 /* Public */,
       8,    2,  163,    2, 0x06 /* Public */,
       8,    1,  168,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  171,    2, 0x0a /* Public */,
      13,    2,  172,    2, 0x0a /* Public */,
      16,    1,  177,    2, 0x0a /* Public */,
      17,    0,  180,    2, 0x0a /* Public */,
      18,    1,  181,    2, 0x0a /* Public */,
      20,    2,  184,    2, 0x0a /* Public */,
      20,    1,  189,    2, 0x2a /* Public | MethodCloned */,
      22,    3,  192,    2, 0x0a /* Public */,
      22,    2,  199,    2, 0x2a /* Public | MethodCloned */,
      23,    0,  204,    2, 0x0a /* Public */,
      24,    2,  205,    2, 0x0a /* Public */,
      24,    1,  210,    2, 0x2a /* Public | MethodCloned */,
      26,    1,  213,    2, 0x0a /* Public */,
      27,    1,  216,    2, 0x0a /* Public */,
      27,    0,  219,    2, 0x2a /* Public | MethodCloned */,
      29,    1,  220,    2, 0x0a /* Public */,
      31,    1,  223,    2, 0x0a /* Public */,
      31,    0,  226,    2, 0x2a /* Public | MethodCloned */,
      33,    1,  227,    2, 0x0a /* Public */,
      33,    0,  230,    2, 0x2a /* Public | MethodCloned */,
      35,    1,  231,    2, 0x0a /* Public */,
      37,    1,  234,    2, 0x08 /* Private */,
      38,    0,  237,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    7,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    0x80000000 | 12,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   14,   15,
    QMetaType::QVariant, QMetaType::QString,   14,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,   21,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::QString,
    QMetaType::Int, QMetaType::QVariant, QMetaType::Int,    5,   25,
    QMetaType::Int, QMetaType::QVariant,    5,
    QMetaType::Int, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,   30,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // properties: name, type, flags
      39, QMetaType::QStringList, 0x00095003,

       0        // eod
};

void CGComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGComboBox *_t = static_cast<CGComboBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->RequestContextMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 5: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 6: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 7: { QStringList _r = _t->ItemList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->SetItemList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 9: _t->AddItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->AddItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->InsertItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 12: _t->InsertItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: { QString _r = _t->CurrentData();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->FindData((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->FindData((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->FindText((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->RemoveItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->RemoveItem(); break;
        case 19: _t->ShowContextMenu((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 20: _t->EnableCompleter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->EnableCompleter(); break;
        case 22: _t->SetShowAbove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->SetShowAbove(); break;
        case 24: _t->SetViewHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->OnItemChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->OnContextMenuClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGComboBox::*)(int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGComboBox::CurrentIndexChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CGComboBox::*)(int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGComboBox::RequestContextMenu)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CGComboBox::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGComboBox::ContextMenuClicked)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CGComboBox *_t = static_cast<CGComboBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->ItemList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CGComboBox *_t = static_cast<CGComboBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetItemList(*reinterpret_cast< QStringList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CGComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_CGComboBox.data,
      qt_meta_data_CGComboBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int CGComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 27;
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

// SIGNAL 0
void CGComboBox::CurrentIndexChanged(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGComboBox::RequestContextMenu(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CGComboBox::ContextMenuClicked(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_CGListWidget_t {
    QByteArrayData data[53];
    char stringdata0[518];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGListWidget_t qt_meta_stringdata_CGListWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CGListWidget"
QT_MOC_LITERAL(1, 13, 11), // "ItemClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "text"
QT_MOC_LITERAL(4, 31, 4), // "data"
QT_MOC_LITERAL(5, 36, 17), // "ItemDoubleClicked"
QT_MOC_LITERAL(6, 54, 9), // "DragEvent"
QT_MOC_LITERAL(7, 64, 7), // "jsonstr"
QT_MOC_LITERAL(8, 72, 18), // "RequestContextMenu"
QT_MOC_LITERAL(9, 91, 5), // "index"
QT_MOC_LITERAL(10, 97, 18), // "ContextMenuClicked"
QT_MOC_LITERAL(11, 116, 8), // "menu_txt"
QT_MOC_LITERAL(12, 125, 8), // "act_info"
QT_MOC_LITERAL(13, 134, 20), // "OnContextMenuClicked"
QT_MOC_LITERAL(14, 155, 13), // "OnItemClicked"
QT_MOC_LITERAL(15, 169, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(16, 186, 4), // "item"
QT_MOC_LITERAL(17, 191, 15), // "OnDBItemClicked"
QT_MOC_LITERAL(18, 207, 1), // "Q"
QT_MOC_LITERAL(19, 209, 10), // "CBaseData*"
QT_MOC_LITERAL(20, 220, 11), // "SetProperty"
QT_MOC_LITERAL(21, 232, 4), // "name"
QT_MOC_LITERAL(22, 237, 5), // "value"
QT_MOC_LITERAL(23, 243, 8), // "Property"
QT_MOC_LITERAL(24, 252, 4), // "Init"
QT_MOC_LITERAL(25, 257, 8), // "table_no"
QT_MOC_LITERAL(26, 266, 7), // "columns"
QT_MOC_LITERAL(27, 274, 8), // "interval"
QT_MOC_LITERAL(28, 283, 8), // "ItemList"
QT_MOC_LITERAL(29, 292, 11), // "InsertItems"
QT_MOC_LITERAL(30, 304, 1), // "l"
QT_MOC_LITERAL(31, 306, 3), // "row"
QT_MOC_LITERAL(32, 310, 10), // "InsertItem"
QT_MOC_LITERAL(33, 321, 4), // "icon"
QT_MOC_LITERAL(34, 326, 9), // "checkable"
QT_MOC_LITERAL(35, 336, 7), // "checked"
QT_MOC_LITERAL(36, 344, 11), // "CurrentText"
QT_MOC_LITERAL(37, 356, 11), // "CurrentData"
QT_MOC_LITERAL(38, 368, 11), // "CheckedRows"
QT_MOC_LITERAL(39, 380, 8), // "ItemInfo"
QT_MOC_LITERAL(40, 389, 10), // "RemoveItem"
QT_MOC_LITERAL(41, 400, 11), // "SetItemData"
QT_MOC_LITERAL(42, 412, 4), // "role"
QT_MOC_LITERAL(43, 417, 8), // "ItemData"
QT_MOC_LITERAL(44, 426, 7), // "SetItem"
QT_MOC_LITERAL(45, 434, 11), // "SetIconSize"
QT_MOC_LITERAL(46, 446, 1), // "w"
QT_MOC_LITERAL(47, 448, 1), // "h"
QT_MOC_LITERAL(48, 450, 19), // "HorizontalScrollBar"
QT_MOC_LITERAL(49, 470, 17), // "VerticalScrollBar"
QT_MOC_LITERAL(50, 488, 15), // "ShowContextMenu"
QT_MOC_LITERAL(51, 504, 4), // "menu"
QT_MOC_LITERAL(52, 509, 8) // "itemList"

    },
    "CGListWidget\0ItemClicked\0\0text\0data\0"
    "ItemDoubleClicked\0DragEvent\0jsonstr\0"
    "RequestContextMenu\0index\0ContextMenuClicked\0"
    "menu_txt\0act_info\0OnContextMenuClicked\0"
    "OnItemClicked\0QListWidgetItem*\0item\0"
    "OnDBItemClicked\0Q\0CBaseData*\0SetProperty\0"
    "name\0value\0Property\0Init\0table_no\0"
    "columns\0interval\0ItemList\0InsertItems\0"
    "l\0row\0InsertItem\0icon\0checkable\0checked\0"
    "CurrentText\0CurrentData\0CheckedRows\0"
    "ItemInfo\0RemoveItem\0SetItemData\0role\0"
    "ItemData\0SetItem\0SetIconSize\0w\0h\0"
    "HorizontalScrollBar\0VerticalScrollBar\0"
    "ShowContextMenu\0menu\0itemList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       1,  338, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  189,    2, 0x06 /* Public */,
       5,    2,  194,    2, 0x06 /* Public */,
       6,    1,  199,    2, 0x06 /* Public */,
       8,    3,  202,    2, 0x06 /* Public */,
      10,    2,  209,    2, 0x06 /* Public */,
      10,    1,  214,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  217,    2, 0x08 /* Private */,
      14,    1,  218,    2, 0x08 /* Private */,
      17,    1,  221,    2, 0x08 /* Private */,
      18,    0,  224,    2, 0x0a /* Public */,
      20,    2,  225,    2, 0x0a /* Public */,
      23,    1,  230,    2, 0x0a /* Public */,
      24,    3,  233,    2, 0x0a /* Public */,
      24,    2,  240,    2, 0x2a /* Public | MethodCloned */,
      28,    0,  245,    2, 0x0a /* Public */,
      29,    2,  246,    2, 0x0a /* Public */,
      29,    1,  251,    2, 0x2a /* Public | MethodCloned */,
      32,    6,  254,    2, 0x0a /* Public */,
      32,    5,  267,    2, 0x2a /* Public | MethodCloned */,
      32,    4,  278,    2, 0x2a /* Public | MethodCloned */,
      32,    3,  287,    2, 0x2a /* Public | MethodCloned */,
      32,    2,  294,    2, 0x2a /* Public | MethodCloned */,
      36,    0,  299,    2, 0x0a /* Public */,
      37,    0,  300,    2, 0x0a /* Public */,
      38,    0,  301,    2, 0x0a /* Public */,
      39,    1,  302,    2, 0x0a /* Public */,
      40,    1,  305,    2, 0x0a /* Public */,
      40,    0,  308,    2, 0x2a /* Public | MethodCloned */,
      41,    3,  309,    2, 0x0a /* Public */,
      43,    2,  316,    2, 0x0a /* Public */,
      44,    3,  321,    2, 0x0a /* Public */,
      45,    2,  328,    2, 0x0a /* Public */,
      48,    0,  333,    2, 0x0a /* Public */,
      49,    0,  334,    2, 0x0a /* Public */,
      50,    1,  335,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    9,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   11,   12,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,
    0x80000000 | 19,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   21,   22,
    QMetaType::QVariant, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,   25,   26,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   25,   26,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,   30,   31,
    QMetaType::Void, QMetaType::QStringList,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   31,    3,    4,   33,   34,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   31,    3,    4,   33,   34,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   31,    3,    4,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   31,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   31,    3,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QStringList,
    QMetaType::QVariantList, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,   31,   42,   22,
    QMetaType::QVariant, QMetaType::Int, QMetaType::Int,   31,   42,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   31,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   46,   47,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::QVariant,   51,

 // properties: name, type, flags
      52, QMetaType::QStringList, 0x00095003,

       0        // eod
};

void CGListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGListWidget *_t = static_cast<CGListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ItemClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->ItemDoubleClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->DragEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->RequestContextMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 5: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->OnContextMenuClicked(); break;
        case 7: _t->OnItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->OnDBItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 10: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 11: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->Init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->Init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: { QStringList _r = _t->ItemList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->InsertItems((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->InsertItems((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 17: _t->InsertItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const bool(*)>(_a[5])),(*reinterpret_cast< const bool(*)>(_a[6]))); break;
        case 18: _t->InsertItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const bool(*)>(_a[5]))); break;
        case 19: _t->InsertItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 20: _t->InsertItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 21: _t->InsertItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 22: { QString _r = _t->CurrentText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->CurrentData();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QStringList _r = _t->CheckedRows();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 25: { QList<QVariant> _r = _t->ItemInfo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QVariant>*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->RemoveItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->RemoveItem(); break;
        case 28: _t->SetItemData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3]))); break;
        case 29: { QVariant _r = _t->ItemData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->SetItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 31: _t->SetIconSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: { QObject* _r = _t->HorizontalScrollBar();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 33: { QObject* _r = _t->VerticalScrollBar();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 34: _t->ShowContextMenu((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGListWidget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGListWidget::ItemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CGListWidget::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGListWidget::ItemDoubleClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CGListWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGListWidget::DragEvent)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CGListWidget::*)(int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGListWidget::RequestContextMenu)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CGListWidget::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGListWidget::ContextMenuClicked)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CGListWidget *_t = static_cast<CGListWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->ItemList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CGListWidget *_t = static_cast<CGListWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->InsertItems(*reinterpret_cast< QStringList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CGListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_CGListWidget.data,
      qt_meta_data_CGListWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGListWidget.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int CGListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
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

// SIGNAL 0
void CGListWidget::ItemClicked(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGListWidget::ItemDoubleClicked(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CGListWidget::DragEvent(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CGListWidget::RequestContextMenu(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CGListWidget::ContextMenuClicked(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_CGTreeItemIndex_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTreeItemIndex_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTreeItemIndex_t qt_meta_stringdata_CGTreeItemIndex = {
    {
QT_MOC_LITERAL(0, 0, 15) // "CGTreeItemIndex"

    },
    "CGTreeItemIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTreeItemIndex[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CGTreeItemIndex::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CGTreeItemIndex::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CGTreeItemIndex.data,
      qt_meta_data_CGTreeItemIndex,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTreeItemIndex::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTreeItemIndex::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTreeItemIndex.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CGTreeItemIndex::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CGTreeWidget_t {
    QByteArrayData data[89];
    char stringdata0[923];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTreeWidget_t qt_meta_stringdata_CGTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CGTreeWidget"
QT_MOC_LITERAL(1, 13, 11), // "ItemClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "index"
QT_MOC_LITERAL(4, 32, 6), // "column"
QT_MOC_LITERAL(5, 39, 4), // "text"
QT_MOC_LITERAL(6, 44, 4), // "data"
QT_MOC_LITERAL(7, 49, 17), // "ItemDoubleClicked"
QT_MOC_LITERAL(8, 67, 12), // "ItemExpanded"
QT_MOC_LITERAL(9, 80, 9), // "DragEvent"
QT_MOC_LITERAL(10, 90, 7), // "jsonstr"
QT_MOC_LITERAL(11, 98, 18), // "RequestContextMenu"
QT_MOC_LITERAL(12, 117, 18), // "ContextMenuClicked"
QT_MOC_LITERAL(13, 136, 8), // "menu_txt"
QT_MOC_LITERAL(14, 145, 8), // "act_info"
QT_MOC_LITERAL(15, 154, 1), // "Q"
QT_MOC_LITERAL(16, 156, 10), // "CBaseData*"
QT_MOC_LITERAL(17, 167, 11), // "SetProperty"
QT_MOC_LITERAL(18, 179, 4), // "name"
QT_MOC_LITERAL(19, 184, 5), // "value"
QT_MOC_LITERAL(20, 190, 8), // "Property"
QT_MOC_LITERAL(21, 199, 8), // "LoadData"
QT_MOC_LITERAL(22, 208, 2), // "id"
QT_MOC_LITERAL(23, 211, 3), // "pid"
QT_MOC_LITERAL(24, 215, 4), // "Load"
QT_MOC_LITERAL(25, 220, 4), // "Data"
QT_MOC_LITERAL(26, 225, 4), // "Init"
QT_MOC_LITERAL(27, 230, 8), // "table_no"
QT_MOC_LITERAL(28, 239, 7), // "columns"
QT_MOC_LITERAL(29, 247, 8), // "interval"
QT_MOC_LITERAL(30, 256, 15), // "SetHeaderLabels"
QT_MOC_LITERAL(31, 272, 6), // "labels"
QT_MOC_LITERAL(32, 279, 14), // "SetColumnWidth"
QT_MOC_LITERAL(33, 294, 5), // "width"
QT_MOC_LITERAL(34, 300, 23), // "SetChildIndicatorPolicy"
QT_MOC_LITERAL(35, 324, 4), // "type"
QT_MOC_LITERAL(36, 329, 7), // "AddItem"
QT_MOC_LITERAL(37, 337, 7), // "strings"
QT_MOC_LITERAL(38, 345, 5), // "datas"
QT_MOC_LITERAL(39, 351, 9), // "top_level"
QT_MOC_LITERAL(40, 361, 13), // "has_indicator"
QT_MOC_LITERAL(41, 375, 11), // "parent_name"
QT_MOC_LITERAL(42, 387, 10), // "ChildCount"
QT_MOC_LITERAL(43, 398, 11), // "CurrentText"
QT_MOC_LITERAL(44, 410, 15), // "CurrentItemInfo"
QT_MOC_LITERAL(45, 426, 16), // "SelectedItemInfo"
QT_MOC_LITERAL(46, 443, 12), // "TakeChildren"
QT_MOC_LITERAL(47, 456, 10), // "RemoveItem"
QT_MOC_LITERAL(48, 467, 3), // "row"
QT_MOC_LITERAL(49, 471, 17), // "RemoveCurrentItem"
QT_MOC_LITERAL(50, 489, 13), // "CurrentColumn"
QT_MOC_LITERAL(51, 503, 7), // "SetItem"
QT_MOC_LITERAL(52, 511, 4), // "icon"
QT_MOC_LITERAL(53, 516, 5), // "color"
QT_MOC_LITERAL(54, 522, 12), // "SetItemColor"
QT_MOC_LITERAL(55, 535, 8), // "ItemInfo"
QT_MOC_LITERAL(56, 544, 12), // "SortByColumn"
QT_MOC_LITERAL(57, 557, 5), // "order"
QT_MOC_LITERAL(58, 563, 14), // "SetCurrentItem"
QT_MOC_LITERAL(59, 578, 6), // "topIdx"
QT_MOC_LITERAL(60, 585, 8), // "childIdx"
QT_MOC_LITERAL(61, 594, 19), // "HorizontalScrollBar"
QT_MOC_LITERAL(62, 614, 8), // "QWidget*"
QT_MOC_LITERAL(63, 623, 17), // "VerticalScrollBar"
QT_MOC_LITERAL(64, 641, 13), // "SetItemWidget"
QT_MOC_LITERAL(65, 655, 3), // "idx"
QT_MOC_LITERAL(66, 659, 6), // "widget"
QT_MOC_LITERAL(67, 666, 13), // "columnSpanned"
QT_MOC_LITERAL(68, 680, 15), // "SetItemExpanded"
QT_MOC_LITERAL(69, 696, 6), // "expand"
QT_MOC_LITERAL(70, 703, 12), // "SetItemFlags"
QT_MOC_LITERAL(71, 716, 5), // "flags"
QT_MOC_LITERAL(72, 722, 7), // "checked"
QT_MOC_LITERAL(73, 730, 11), // "ItemChecked"
QT_MOC_LITERAL(74, 742, 8), // "FindItem"
QT_MOC_LITERAL(75, 751, 10), // "QList<int>"
QT_MOC_LITERAL(76, 762, 15), // "ShowContextMenu"
QT_MOC_LITERAL(77, 778, 9), // "menuArray"
QT_MOC_LITERAL(78, 788, 11), // "SetItemData"
QT_MOC_LITERAL(79, 800, 4), // "role"
QT_MOC_LITERAL(80, 805, 8), // "ItemData"
QT_MOC_LITERAL(81, 814, 11), // "SetIconPath"
QT_MOC_LITERAL(82, 826, 8), // "pathType"
QT_MOC_LITERAL(83, 835, 13), // "OnItemClicked"
QT_MOC_LITERAL(84, 849, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(85, 866, 4), // "item"
QT_MOC_LITERAL(86, 871, 15), // "OnDBItemClicked"
QT_MOC_LITERAL(87, 887, 14), // "OnItemExpanded"
QT_MOC_LITERAL(88, 902, 20) // "OnContextMenuClicked"

    },
    "CGTreeWidget\0ItemClicked\0\0index\0column\0"
    "text\0data\0ItemDoubleClicked\0ItemExpanded\0"
    "DragEvent\0jsonstr\0RequestContextMenu\0"
    "ContextMenuClicked\0menu_txt\0act_info\0"
    "Q\0CBaseData*\0SetProperty\0name\0value\0"
    "Property\0LoadData\0id\0pid\0Load\0Data\0"
    "Init\0table_no\0columns\0interval\0"
    "SetHeaderLabels\0labels\0SetColumnWidth\0"
    "width\0SetChildIndicatorPolicy\0type\0"
    "AddItem\0strings\0datas\0top_level\0"
    "has_indicator\0parent_name\0ChildCount\0"
    "CurrentText\0CurrentItemInfo\0"
    "SelectedItemInfo\0TakeChildren\0RemoveItem\0"
    "row\0RemoveCurrentItem\0CurrentColumn\0"
    "SetItem\0icon\0color\0SetItemColor\0"
    "ItemInfo\0SortByColumn\0order\0SetCurrentItem\0"
    "topIdx\0childIdx\0HorizontalScrollBar\0"
    "QWidget*\0VerticalScrollBar\0SetItemWidget\0"
    "idx\0widget\0columnSpanned\0SetItemExpanded\0"
    "expand\0SetItemFlags\0flags\0checked\0"
    "ItemChecked\0FindItem\0QList<int>\0"
    "ShowContextMenu\0menuArray\0SetItemData\0"
    "role\0ItemData\0SetIconPath\0pathType\0"
    "OnItemClicked\0QTreeWidgetItem*\0item\0"
    "OnDBItemClicked\0OnItemExpanded\0"
    "OnContextMenuClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      68,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  354,    2, 0x06 /* Public */,
       7,    4,  363,    2, 0x06 /* Public */,
       8,    3,  372,    2, 0x06 /* Public */,
       9,    1,  379,    2, 0x06 /* Public */,
      11,    4,  382,    2, 0x06 /* Public */,
      12,    4,  391,    2, 0x06 /* Public */,
      12,    3,  400,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  407,    2, 0x0a /* Public */,
      17,    2,  408,    2, 0x0a /* Public */,
      20,    1,  413,    2, 0x0a /* Public */,
      21,    3,  416,    2, 0x0a /* Public */,
      24,    1,  423,    2, 0x0a /* Public */,
      25,    0,  426,    2, 0x0a /* Public */,
      26,    3,  427,    2, 0x0a /* Public */,
      26,    2,  434,    2, 0x2a /* Public | MethodCloned */,
      30,    1,  439,    2, 0x0a /* Public */,
      32,    2,  442,    2, 0x0a /* Public */,
      34,    1,  447,    2, 0x0a /* Public */,
      36,    4,  450,    2, 0x0a /* Public */,
      36,    3,  459,    2, 0x2a /* Public | MethodCloned */,
      36,    2,  466,    2, 0x2a /* Public | MethodCloned */,
      36,    4,  471,    2, 0x0a /* Public */,
      36,    3,  480,    2, 0x2a /* Public | MethodCloned */,
      42,    0,  487,    2, 0x0a /* Public */,
      43,    1,  488,    2, 0x0a /* Public */,
      43,    0,  491,    2, 0x2a /* Public | MethodCloned */,
      44,    1,  492,    2, 0x0a /* Public */,
      44,    0,  495,    2, 0x2a /* Public | MethodCloned */,
      45,    1,  496,    2, 0x0a /* Public */,
      45,    0,  499,    2, 0x2a /* Public | MethodCloned */,
      46,    0,  500,    2, 0x0a /* Public */,
      47,    1,  501,    2, 0x0a /* Public */,
      47,    0,  504,    2, 0x2a /* Public | MethodCloned */,
      49,    0,  505,    2, 0x0a /* Public */,
      50,    0,  506,    2, 0x0a /* Public */,
      51,    6,  507,    2, 0x0a /* Public */,
      51,    5,  520,    2, 0x2a /* Public | MethodCloned */,
      51,    4,  531,    2, 0x2a /* Public | MethodCloned */,
      54,    4,  540,    2, 0x0a /* Public */,
      54,    3,  549,    2, 0x2a /* Public | MethodCloned */,
      54,    2,  556,    2, 0x2a /* Public | MethodCloned */,
      55,    2,  561,    2, 0x0a /* Public */,
      56,    2,  566,    2, 0x0a /* Public */,
      58,    3,  571,    2, 0x0a /* Public */,
      58,    2,  578,    2, 0x2a /* Public | MethodCloned */,
      61,    0,  583,    2, 0x0a /* Public */,
      63,    0,  584,    2, 0x0a /* Public */,
      64,    4,  585,    2, 0x0a /* Public */,
      64,    3,  594,    2, 0x2a /* Public | MethodCloned */,
      68,    2,  601,    2, 0x0a /* Public */,
      70,    4,  606,    2, 0x0a /* Public */,
      70,    3,  615,    2, 0x2a /* Public | MethodCloned */,
      70,    2,  622,    2, 0x2a /* Public | MethodCloned */,
      70,    1,  627,    2, 0x2a /* Public | MethodCloned */,
      70,    0,  630,    2, 0x2a /* Public | MethodCloned */,
      73,    2,  631,    2, 0x0a /* Public */,
      73,    1,  636,    2, 0x2a /* Public | MethodCloned */,
      73,    0,  639,    2, 0x2a /* Public | MethodCloned */,
      74,    2,  640,    2, 0x0a /* Public */,
      74,    1,  645,    2, 0x2a /* Public | MethodCloned */,
      76,    1,  648,    2, 0x0a /* Public */,
      78,    4,  651,    2, 0x0a /* Public */,
      80,    3,  660,    2, 0x0a /* Public */,
      81,    1,  667,    2, 0x0a /* Public */,
      83,    2,  670,    2, 0x08 /* Private */,
      86,    2,  675,    2, 0x08 /* Private */,
      87,    1,  680,    2, 0x08 /* Private */,
      88,    0,  683,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    5,    6,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QVariant,    3,    4,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    4,   13,

 // slots: parameters
    0x80000000 | 16,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   18,   19,
    QMetaType::QVariant, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,   22,   23,
    QMetaType::Bool, QMetaType::QVariant,    6,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,   27,   28,   29,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   27,   28,
    QMetaType::Void, QMetaType::QStringList,   31,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,   33,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::QObjectStar, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool, QMetaType::Bool,   37,   38,   39,   40,
    QMetaType::QObjectStar, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool,   37,   38,   39,
    QMetaType::QObjectStar, QMetaType::QStringList, QMetaType::QStringList,   37,   38,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::QStringList, QMetaType::Bool,   41,   37,   38,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList, QMetaType::QStringList,   41,   37,   38,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    4,
    QMetaType::QString,
    QMetaType::QStringList, QMetaType::Int,    4,
    QMetaType::QStringList,
    QMetaType::QVariantList, QMetaType::Int,    4,
    QMetaType::QVariantList,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   48,    4,    5,    6,   52,   53,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   48,    4,    5,    6,   52,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   48,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   48,    4,   52,   53,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   48,    4,   52,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   48,    4,
    QMetaType::QVariantList, QMetaType::Int, QMetaType::Int,   48,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,   57,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   59,    4,   60,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   59,    4,
    0x80000000 | 62,
    0x80000000 | 62,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::Int, QMetaType::QObjectStar, QMetaType::Bool,   65,    4,   66,   67,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::Int, QMetaType::QObjectStar,   65,    4,   66,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   69,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    3,    4,   71,   72,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   71,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Int,
    0x80000000 | 75, QMetaType::QString, QMetaType::Int,    5,    4,
    0x80000000 | 75, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QVariant,   77,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,   48,    4,   79,   19,
    QMetaType::QVariant, QMetaType::Int, QMetaType::Int, QMetaType::Int,   48,    4,   79,
    QMetaType::Void, QMetaType::QString,   82,
    QMetaType::Void, 0x80000000 | 84, QMetaType::Int,   85,    4,
    QMetaType::Void, 0x80000000 | 84, QMetaType::Int,   85,    4,
    QMetaType::Void, 0x80000000 | 84,   85,
    QMetaType::Void,

       0        // eod
};

void CGTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTreeWidget *_t = static_cast<CGTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ItemClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->ItemDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->ItemExpanded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->DragEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->RequestContextMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 5: _t->ContextMenuClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4]))); break;
        case 6: _t->ContextMenuClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 8: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 9: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->LoadData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 11: { bool _r = _t->Load((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->Data();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->Init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->Init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->SetHeaderLabels((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 16: _t->SetColumnWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->SetChildIndicatorPolicy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: { QObject* _r = _t->AddItem((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 19: { QObject* _r = _t->AddItem((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 20: { QObject* _r = _t->AddItem((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 21: _t->AddItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 22: _t->AddItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3]))); break;
        case 23: { int _r = _t->ChildCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->CurrentText((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->CurrentText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QStringList _r = _t->CurrentItemInfo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 27: { QStringList _r = _t->CurrentItemInfo();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 28: { QList<QVariant> _r = _t->SelectedItemInfo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QVariant>*>(_a[0]) = std::move(_r); }  break;
        case 29: { QList<QVariant> _r = _t->SelectedItemInfo();
            if (_a[0]) *reinterpret_cast< QList<QVariant>*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->TakeChildren(); break;
        case 31: _t->RemoveItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->RemoveItem(); break;
        case 33: _t->RemoveCurrentItem(); break;
        case 34: { int _r = _t->CurrentColumn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 35: _t->SetItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 36: _t->SetItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 37: _t->SetItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 38: _t->SetItemColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 39: _t->SetItemColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 40: _t->SetItemColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: { QList<QVariant> _r = _t->ItemInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QVariant>*>(_a[0]) = std::move(_r); }  break;
        case 42: _t->SortByColumn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 43: _t->SetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 44: _t->SetCurrentItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 45: { QWidget* _r = _t->HorizontalScrollBar();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 46: { QWidget* _r = _t->VerticalScrollBar();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 47: _t->SetItemWidget((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QObject*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 48: _t->SetItemWidget((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QObject*(*)>(_a[3]))); break;
        case 49: _t->SetItemExpanded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 50: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 51: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 52: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 53: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->SetItemFlags(); break;
        case 55: { int _r = _t->ItemChecked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 56: { int _r = _t->ItemChecked((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 57: { int _r = _t->ItemChecked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 58: { QList<int> _r = _t->FindItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 59: { QList<int> _r = _t->FindItem((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 60: _t->ShowContextMenu((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 61: _t->SetItemData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4]))); break;
        case 62: { QVariant _r = _t->ItemData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 63: _t->SetIconPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 64: _t->OnItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 65: _t->OnDBItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 66: _t->OnItemExpanded((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 67: _t->OnContextMenuClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGTreeWidget::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeWidget::ItemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CGTreeWidget::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeWidget::ItemDoubleClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CGTreeWidget::*)(int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeWidget::ItemExpanded)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CGTreeWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeWidget::DragEvent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CGTreeWidget::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeWidget::RequestContextMenu)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CGTreeWidget::*)(int , int , QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeWidget::ContextMenuClicked)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_CGTreeWidget.data,
      qt_meta_data_CGTreeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTreeWidget.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int CGTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 68)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 68;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 68)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 68;
    }
    return _id;
}

// SIGNAL 0
void CGTreeWidget::ItemClicked(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGTreeWidget::ItemDoubleClicked(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CGTreeWidget::ItemExpanded(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CGTreeWidget::DragEvent(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CGTreeWidget::RequestContextMenu(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CGTreeWidget::ContextMenuClicked(int _t1, int _t2, QString _t3, QVariant _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_CGTableDelegate_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTableDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTableDelegate_t qt_meta_stringdata_CGTableDelegate = {
    {
QT_MOC_LITERAL(0, 0, 15) // "CGTableDelegate"

    },
    "CGTableDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTableDelegate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CGTableDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CGTableDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_CGTableDelegate.data,
      qt_meta_data_CGTableDelegate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTableDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTableDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTableDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int CGTableDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CGTableWidget_t {
    QByteArrayData data[87];
    char stringdata0[987];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTableWidget_t qt_meta_stringdata_CGTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CGTableWidget"
QT_MOC_LITERAL(1, 14, 11), // "ItemClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "row"
QT_MOC_LITERAL(4, 31, 6), // "column"
QT_MOC_LITERAL(5, 38, 4), // "text"
QT_MOC_LITERAL(6, 43, 4), // "data"
QT_MOC_LITERAL(7, 48, 17), // "ItemDoubleClicked"
QT_MOC_LITERAL(8, 66, 9), // "DragEvent"
QT_MOC_LITERAL(9, 76, 7), // "jsonstr"
QT_MOC_LITERAL(10, 84, 18), // "RequestContextMenu"
QT_MOC_LITERAL(11, 103, 5), // "rowNo"
QT_MOC_LITERAL(12, 109, 8), // "columnNo"
QT_MOC_LITERAL(13, 118, 18), // "ContextMenuClicked"
QT_MOC_LITERAL(14, 137, 8), // "menu_txt"
QT_MOC_LITERAL(15, 146, 8), // "act_info"
QT_MOC_LITERAL(16, 155, 1), // "Q"
QT_MOC_LITERAL(17, 157, 10), // "CBaseData*"
QT_MOC_LITERAL(18, 168, 11), // "SetProperty"
QT_MOC_LITERAL(19, 180, 4), // "name"
QT_MOC_LITERAL(20, 185, 5), // "value"
QT_MOC_LITERAL(21, 191, 8), // "Property"
QT_MOC_LITERAL(22, 200, 10), // "SetColumns"
QT_MOC_LITERAL(23, 211, 11), // "columnsInfo"
QT_MOC_LITERAL(24, 223, 12), // "SortByColumn"
QT_MOC_LITERAL(25, 236, 5), // "order"
QT_MOC_LITERAL(26, 242, 4), // "Data"
QT_MOC_LITERAL(27, 247, 8), // "LoadData"
QT_MOC_LITERAL(28, 256, 13), // "dataJsonarray"
QT_MOC_LITERAL(29, 270, 11), // "SetAllItems"
QT_MOC_LITERAL(30, 282, 5), // "nRows"
QT_MOC_LITERAL(31, 288, 5), // "nCols"
QT_MOC_LITERAL(32, 294, 7), // "txtList"
QT_MOC_LITERAL(33, 302, 7), // "strList"
QT_MOC_LITERAL(34, 310, 16), // "HorizontalHeader"
QT_MOC_LITERAL(35, 327, 14), // "VerticalHeader"
QT_MOC_LITERAL(36, 342, 19), // "SetHeaderResizeMode"
QT_MOC_LITERAL(37, 362, 4), // "mode"
QT_MOC_LITERAL(38, 367, 6), // "header"
QT_MOC_LITERAL(39, 374, 3), // "idx"
QT_MOC_LITERAL(40, 378, 19), // "SetHorizontalLabels"
QT_MOC_LITERAL(41, 398, 6), // "labels"
QT_MOC_LITERAL(42, 405, 25), // "SetHorizontalHeaderLabels"
QT_MOC_LITERAL(43, 431, 19), // "GetHorizontalLabels"
QT_MOC_LITERAL(44, 451, 23), // "SetVerticalHeaderLabels"
QT_MOC_LITERAL(45, 475, 14), // "SetColumnWidth"
QT_MOC_LITERAL(46, 490, 5), // "width"
QT_MOC_LITERAL(47, 496, 12), // "SetRowHeight"
QT_MOC_LITERAL(48, 509, 6), // "height"
QT_MOC_LITERAL(49, 516, 7), // "SetItem"
QT_MOC_LITERAL(50, 524, 3), // "txt"
QT_MOC_LITERAL(51, 528, 8), // "usr_data"
QT_MOC_LITERAL(52, 537, 8), // "iconFile"
QT_MOC_LITERAL(53, 546, 11), // "SetCellMenu"
QT_MOC_LITERAL(54, 558, 4), // "menu"
QT_MOC_LITERAL(55, 563, 11), // "multiSelect"
QT_MOC_LITERAL(56, 575, 13), // "SetCellWidget"
QT_MOC_LITERAL(57, 589, 8), // "ItemType"
QT_MOC_LITERAL(58, 598, 8), // "ItemData"
QT_MOC_LITERAL(59, 607, 13), // "GetCurrentRow"
QT_MOC_LITERAL(60, 621, 16), // "GetCurrentColumn"
QT_MOC_LITERAL(61, 638, 16), // "SetTextAlignment"
QT_MOC_LITERAL(62, 655, 10), // "align_type"
QT_MOC_LITERAL(63, 666, 12), // "SetItemFlags"
QT_MOC_LITERAL(64, 679, 5), // "flags"
QT_MOC_LITERAL(65, 685, 7), // "checked"
QT_MOC_LITERAL(66, 693, 11), // "ItemChecked"
QT_MOC_LITERAL(67, 705, 5), // "Clear"
QT_MOC_LITERAL(68, 711, 24), // "CreateHtmlTableFromModel"
QT_MOC_LITERAL(69, 736, 5), // "Print"
QT_MOC_LITERAL(70, 742, 19), // "HorizontalScrollBar"
QT_MOC_LITERAL(71, 762, 17), // "VerticalScrollBar"
QT_MOC_LITERAL(72, 780, 15), // "ShowContextMenu"
QT_MOC_LITERAL(73, 796, 9), // "menuArray"
QT_MOC_LITERAL(74, 806, 11), // "SetItemData"
QT_MOC_LITERAL(75, 818, 4), // "role"
QT_MOC_LITERAL(76, 823, 14), // "SelectedRanges"
QT_MOC_LITERAL(77, 838, 13), // "OnItemClicked"
QT_MOC_LITERAL(78, 852, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(79, 870, 4), // "item"
QT_MOC_LITERAL(80, 875, 15), // "OnDBItemClicked"
QT_MOC_LITERAL(81, 891, 20), // "OnContextMenuClicked"
QT_MOC_LITERAL(82, 912, 13), // "showRowHeader"
QT_MOC_LITERAL(83, 926, 16), // "showColumnHeader"
QT_MOC_LITERAL(84, 943, 9), // "rowHeight"
QT_MOC_LITERAL(85, 953, 16), // "defaultAlignment"
QT_MOC_LITERAL(86, 970, 16) // "horizontalLabels"

    },
    "CGTableWidget\0ItemClicked\0\0row\0column\0"
    "text\0data\0ItemDoubleClicked\0DragEvent\0"
    "jsonstr\0RequestContextMenu\0rowNo\0"
    "columnNo\0ContextMenuClicked\0menu_txt\0"
    "act_info\0Q\0CBaseData*\0SetProperty\0"
    "name\0value\0Property\0SetColumns\0"
    "columnsInfo\0SortByColumn\0order\0Data\0"
    "LoadData\0dataJsonarray\0SetAllItems\0"
    "nRows\0nCols\0txtList\0strList\0"
    "HorizontalHeader\0VerticalHeader\0"
    "SetHeaderResizeMode\0mode\0header\0idx\0"
    "SetHorizontalLabels\0labels\0"
    "SetHorizontalHeaderLabels\0GetHorizontalLabels\0"
    "SetVerticalHeaderLabels\0SetColumnWidth\0"
    "width\0SetRowHeight\0height\0SetItem\0txt\0"
    "usr_data\0iconFile\0SetCellMenu\0menu\0"
    "multiSelect\0SetCellWidget\0ItemType\0"
    "ItemData\0GetCurrentRow\0GetCurrentColumn\0"
    "SetTextAlignment\0align_type\0SetItemFlags\0"
    "flags\0checked\0ItemChecked\0Clear\0"
    "CreateHtmlTableFromModel\0Print\0"
    "HorizontalScrollBar\0VerticalScrollBar\0"
    "ShowContextMenu\0menuArray\0SetItemData\0"
    "role\0SelectedRanges\0OnItemClicked\0"
    "QTableWidgetItem*\0item\0OnDBItemClicked\0"
    "OnContextMenuClicked\0showRowHeader\0"
    "showColumnHeader\0rowHeight\0defaultAlignment\0"
    "horizontalLabels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      65,   14, // methods
       5,  610, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  339,    2, 0x06 /* Public */,
       7,    4,  348,    2, 0x06 /* Public */,
       8,    1,  357,    2, 0x06 /* Public */,
      10,    2,  360,    2, 0x06 /* Public */,
      13,    2,  365,    2, 0x06 /* Public */,
      13,    1,  370,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      16,    0,  373,    2, 0x0a /* Public */,
      18,    2,  374,    2, 0x0a /* Public */,
      21,    1,  379,    2, 0x0a /* Public */,
      22,    1,  382,    2, 0x0a /* Public */,
      24,    2,  385,    2, 0x0a /* Public */,
      24,    1,  390,    2, 0x2a /* Public | MethodCloned */,
      26,    0,  393,    2, 0x0a /* Public */,
      27,    1,  394,    2, 0x0a /* Public */,
      29,    4,  397,    2, 0x0a /* Public */,
      29,    3,  406,    2, 0x2a /* Public | MethodCloned */,
      34,    0,  413,    2, 0x0a /* Public */,
      35,    0,  414,    2, 0x0a /* Public */,
      36,    3,  415,    2, 0x0a /* Public */,
      36,    2,  422,    2, 0x2a /* Public | MethodCloned */,
      36,    1,  427,    2, 0x2a /* Public | MethodCloned */,
      40,    1,  430,    2, 0x0a /* Public */,
      42,    1,  433,    2, 0x0a /* Public */,
      43,    0,  436,    2, 0x0a /* Public */,
      44,    1,  437,    2, 0x0a /* Public */,
      45,    2,  440,    2, 0x0a /* Public */,
      47,    2,  445,    2, 0x0a /* Public */,
      49,    5,  450,    2, 0x0a /* Public */,
      49,    4,  461,    2, 0x2a /* Public | MethodCloned */,
      49,    3,  470,    2, 0x2a /* Public | MethodCloned */,
      53,    4,  477,    2, 0x0a /* Public */,
      53,    3,  486,    2, 0x2a /* Public | MethodCloned */,
      56,    4,  493,    2, 0x0a /* Public */,
      56,    3,  502,    2, 0x2a /* Public | MethodCloned */,
      58,    2,  509,    2, 0x0a /* Public */,
      58,    1,  514,    2, 0x2a /* Public | MethodCloned */,
      58,    0,  517,    2, 0x2a /* Public | MethodCloned */,
      59,    0,  518,    2, 0x0a /* Public */,
      60,    0,  519,    2, 0x0a /* Public */,
      61,    3,  520,    2, 0x0a /* Public */,
      61,    2,  527,    2, 0x2a /* Public | MethodCloned */,
      61,    1,  532,    2, 0x2a /* Public | MethodCloned */,
      61,    0,  535,    2, 0x2a /* Public | MethodCloned */,
      63,    4,  536,    2, 0x0a /* Public */,
      63,    3,  545,    2, 0x2a /* Public | MethodCloned */,
      63,    2,  552,    2, 0x2a /* Public | MethodCloned */,
      63,    1,  557,    2, 0x2a /* Public | MethodCloned */,
      63,    0,  560,    2, 0x2a /* Public | MethodCloned */,
      66,    2,  561,    2, 0x0a /* Public */,
      66,    1,  566,    2, 0x2a /* Public | MethodCloned */,
      66,    0,  569,    2, 0x2a /* Public | MethodCloned */,
      67,    2,  570,    2, 0x0a /* Public */,
      67,    1,  575,    2, 0x2a /* Public | MethodCloned */,
      67,    0,  578,    2, 0x2a /* Public | MethodCloned */,
      68,    0,  579,    2, 0x0a /* Public */,
      69,    0,  580,    2, 0x0a /* Public */,
      70,    0,  581,    2, 0x0a /* Public */,
      71,    0,  582,    2, 0x0a /* Public */,
      72,    1,  583,    2, 0x0a /* Public */,
      74,    4,  586,    2, 0x0a /* Public */,
      58,    3,  595,    2, 0x0a /* Public */,
      76,    0,  602,    2, 0x0a /* Public */,
      77,    1,  603,    2, 0x08 /* Private */,
      80,    1,  606,    2, 0x08 /* Private */,
      81,    0,  609,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   14,   15,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    0x80000000 | 17,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   19,   20,
    QMetaType::QVariant, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QVariant,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,   25,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::QVariantList,
    QMetaType::Int, QMetaType::QString,   28,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QVariantList, QMetaType::QVariantList,   30,   31,   32,   33,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QVariantList,   30,   31,   32,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,   37,   38,   39,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   37,   38,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QStringList,   41,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QStringList,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QString,    3,    4,   50,   51,   52,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariant, QMetaType::QVariant,    3,    4,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,    3,    4,   50,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariantMap, QMetaType::Bool,    3,    4,   54,   55,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariantMap,    3,    4,   54,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariant, QMetaType::QVariant,    3,    4,   57,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,    3,    4,   57,
    QMetaType::QStringList, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::QStringList, QMetaType::Int,    3,
    QMetaType::QStringList,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   62,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    3,    4,   64,   65,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   64,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::QVariant,   73,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QVariant,    3,    4,   75,   20,
    QMetaType::QVariant, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   75,
    QMetaType::QStringList,
    QMetaType::Void, 0x80000000 | 78,   79,
    QMetaType::Void, 0x80000000 | 78,   79,
    QMetaType::Void,

 // properties: name, type, flags
      82, QMetaType::Bool, 0x00095003,
      83, QMetaType::Bool, 0x00095003,
      84, QMetaType::Int, 0x00095003,
      85, QMetaType::Int, 0x00095003,
      86, QMetaType::QString, 0x00095003,

       0        // eod
};

void CGTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTableWidget *_t = static_cast<CGTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ItemClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->ItemDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->DragEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->RequestContextMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 5: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 8: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->SetColumns((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 10: _t->SortByColumn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->SortByColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { QVariantList _r = _t->Data();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->LoadData((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->SetAllItems((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QList<QVariant>(*)>(_a[3])),(*reinterpret_cast< const QList<QVariant>(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->SetAllItems((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QList<QVariant>(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { QObject* _r = _t->HorizontalHeader();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 17: { QObject* _r = _t->VerticalHeader();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 18: _t->SetHeaderResizeMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 19: _t->SetHeaderResizeMode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 20: _t->SetHeaderResizeMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->SetHorizontalLabels((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->SetHorizontalHeaderLabels((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 23: { QString _r = _t->GetHorizontalLabels();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->SetVerticalHeaderLabels((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 25: _t->SetColumnWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->SetRowHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 27: _t->SetItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5]))); break;
        case 28: _t->SetItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4]))); break;
        case 29: _t->SetItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 30: _t->SetCellMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QMap<QString,QVariant>(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 31: _t->SetCellMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QMap<QString,QVariant>(*)>(_a[3]))); break;
        case 32: _t->SetCellWidget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4]))); break;
        case 33: _t->SetCellWidget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3]))); break;
        case 34: { QStringList _r = _t->ItemData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 35: { QStringList _r = _t->ItemData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 36: { QStringList _r = _t->ItemData();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 37: { int _r = _t->GetCurrentRow();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 38: { int _r = _t->GetCurrentColumn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->SetTextAlignment((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 40: _t->SetTextAlignment((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: _t->SetTextAlignment((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->SetTextAlignment(); break;
        case 43: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 44: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 45: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 46: _t->SetItemFlags((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->SetItemFlags(); break;
        case 48: { int _r = _t->ItemChecked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 49: { int _r = _t->ItemChecked((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 50: { int _r = _t->ItemChecked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->Clear((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 52: _t->Clear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->Clear(); break;
        case 54: _t->CreateHtmlTableFromModel(); break;
        case 55: _t->Print(); break;
        case 56: { QObject* _r = _t->HorizontalScrollBar();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 57: { QObject* _r = _t->VerticalScrollBar();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 58: _t->ShowContextMenu((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 59: _t->SetItemData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4]))); break;
        case 60: { QVariant _r = _t->ItemData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 61: { QStringList _r = _t->SelectedRanges();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 62: _t->OnItemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 63: _t->OnDBItemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 64: _t->OnContextMenuClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGTableWidget::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTableWidget::ItemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CGTableWidget::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTableWidget::ItemDoubleClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CGTableWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTableWidget::DragEvent)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CGTableWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTableWidget::RequestContextMenu)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CGTableWidget::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTableWidget::ContextMenuClicked)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CGTableWidget *_t = static_cast<CGTableWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->GetShowRowHeader(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->GetShowColumnHeader(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->GetRowHeight(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->GetDefaultAlignment(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->GetHorizontalLabels(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CGTableWidget *_t = static_cast<CGTableWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetShowRowHeader(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->SetShowColumnHeader(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->SetRowHeight(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->SetDefaultAlignment(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->SetHorizontalLabels(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CGTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_CGTableWidget.data,
      qt_meta_data_CGTableWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int CGTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 65;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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

// SIGNAL 0
void CGTableWidget::ItemClicked(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGTableWidget::ItemDoubleClicked(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CGTableWidget::DragEvent(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CGTableWidget::RequestContextMenu(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CGTableWidget::ContextMenuClicked(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_CGTextBrowser_t {
    QByteArrayData data[11];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTextBrowser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTextBrowser_t qt_meta_stringdata_CGTextBrowser = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CGTextBrowser"
QT_MOC_LITERAL(1, 14, 1), // "Q"
QT_MOC_LITERAL(2, 16, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 27, 0), // ""
QT_MOC_LITERAL(4, 28, 11), // "SetProperty"
QT_MOC_LITERAL(5, 40, 4), // "name"
QT_MOC_LITERAL(6, 45, 5), // "value"
QT_MOC_LITERAL(7, 51, 8), // "Property"
QT_MOC_LITERAL(8, 60, 9), // "SetSource"
QT_MOC_LITERAL(9, 70, 3), // "url"
QT_MOC_LITERAL(10, 74, 5) // "Print"

    },
    "CGTextBrowser\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0SetSource\0url\0"
    "Print"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTextBrowser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    3, 0x0a /* Public */,
       4,    2,   40,    3, 0x0a /* Public */,
       7,    1,   45,    3, 0x0a /* Public */,
       8,    1,   48,    3, 0x0a /* Public */,
      10,    0,   51,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void CGTextBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTextBrowser *_t = static_cast<CGTextBrowser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetSource((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Print(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTextBrowser::staticMetaObject = {
    { &QTextBrowser::staticMetaObject, qt_meta_stringdata_CGTextBrowser.data,
      qt_meta_data_CGTextBrowser,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTextBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTextBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTextBrowser.stringdata0))
        return static_cast<void*>(this);
    return QTextBrowser::qt_metacast(_clname);
}

int CGTextBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextBrowser::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
struct qt_meta_stringdata_CGLabel_t {
    QByteArrayData data[19];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGLabel_t qt_meta_stringdata_CGLabel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CGLabel"
QT_MOC_LITERAL(1, 8, 7), // "Clicked"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "text"
QT_MOC_LITERAL(4, 22, 4), // "data"
QT_MOC_LITERAL(5, 27, 9), // "DBClicked"
QT_MOC_LITERAL(6, 37, 1), // "Q"
QT_MOC_LITERAL(7, 39, 10), // "CBaseData*"
QT_MOC_LITERAL(8, 50, 11), // "SetProperty"
QT_MOC_LITERAL(9, 62, 4), // "name"
QT_MOC_LITERAL(10, 67, 5), // "value"
QT_MOC_LITERAL(11, 73, 8), // "Property"
QT_MOC_LITERAL(12, 82, 9), // "GetPixmap"
QT_MOC_LITERAL(13, 92, 9), // "SetPixmap"
QT_MOC_LITERAL(14, 102, 7), // "pixname"
QT_MOC_LITERAL(15, 110, 7), // "SetData"
QT_MOC_LITERAL(16, 118, 5), // "data1"
QT_MOC_LITERAL(17, 124, 7), // "GetData"
QT_MOC_LITERAL(18, 132, 10) // "pixmapName"

    },
    "CGLabel\0Clicked\0\0text\0data\0DBClicked\0"
    "Q\0CBaseData*\0SetProperty\0name\0value\0"
    "Property\0GetPixmap\0SetPixmap\0pixname\0"
    "SetData\0data1\0GetData\0pixmapName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       5,    2,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   69,    2, 0x0a /* Public */,
       8,    2,   70,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,
      12,    0,   78,    2, 0x0a /* Public */,
      13,    1,   79,    2, 0x0a /* Public */,
      15,    1,   82,    2, 0x0a /* Public */,
      17,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    0x80000000 | 7,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    9,   10,
    QMetaType::QVariant, QMetaType::QString,    9,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::QString,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00095003,
      18, QMetaType::QString, 0x00095003,

       0        // eod
};

void CGLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGLabel *_t = static_cast<CGLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Clicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->DBClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 4: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->GetPixmap();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->SetPixmap((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->SetData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { QString _r = _t->GetData();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGLabel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGLabel::Clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CGLabel::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGLabel::DBClicked)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CGLabel *_t = static_cast<CGLabel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->GetData(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->GetPixmap(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CGLabel *_t = static_cast<CGLabel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetData(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->SetPixmap(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CGLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_CGLabel.data,
      qt_meta_data_CGLabel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int CGLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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

// SIGNAL 0
void CGLabel::Clicked(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGLabel::DBClicked(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CGWebPage_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGWebPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGWebPage_t qt_meta_stringdata_CGWebPage = {
    {
QT_MOC_LITERAL(0, 0, 9) // "CGWebPage"

    },
    "CGWebPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGWebPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CGWebPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CGWebPage::staticMetaObject = {
    { &QWebEnginePage::staticMetaObject, qt_meta_stringdata_CGWebPage.data,
      qt_meta_data_CGWebPage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGWebPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGWebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGWebPage.stringdata0))
        return static_cast<void*>(this);
    return QWebEnginePage::qt_metacast(_clname);
}

int CGWebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebEnginePage::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CGWebView_t {
    QByteArrayData data[15];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGWebView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGWebView_t qt_meta_stringdata_CGWebView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CGWebView"
QT_MOC_LITERAL(1, 10, 1), // "Q"
QT_MOC_LITERAL(2, 12, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 23, 0), // ""
QT_MOC_LITERAL(4, 24, 11), // "SetProperty"
QT_MOC_LITERAL(5, 36, 4), // "name"
QT_MOC_LITERAL(6, 41, 5), // "value"
QT_MOC_LITERAL(7, 47, 8), // "Property"
QT_MOC_LITERAL(8, 56, 4), // "Load"
QT_MOC_LITERAL(9, 61, 3), // "url"
QT_MOC_LITERAL(10, 65, 4), // "Page"
QT_MOC_LITERAL(11, 70, 15), // "QWebEnginePage*"
QT_MOC_LITERAL(12, 86, 5), // "DoCmd"
QT_MOC_LITERAL(13, 92, 12), // "scriptSource"
QT_MOC_LITERAL(14, 105, 5) // "Print"

    },
    "CGWebView\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0Load\0url\0Page\0"
    "QWebEnginePage*\0DoCmd\0scriptSource\0"
    "Print"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGWebView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    3, 0x0a /* Public */,
       4,    2,   50,    3, 0x0a /* Public */,
       7,    1,   55,    3, 0x0a /* Public */,
       8,    1,   58,    3, 0x0a /* Public */,
      10,    0,   61,    3, 0x0a /* Public */,
      12,    1,   62,    3, 0x0a /* Public */,
      14,    0,   65,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    9,
    0x80000000 | 11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,

       0        // eod
};

void CGWebView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGWebView *_t = static_cast<CGWebView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->Load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { QWebEnginePage* _r = _t->Page();
            if (_a[0]) *reinterpret_cast< QWebEnginePage**>(_a[0]) = std::move(_r); }  break;
        case 5: _t->DoCmd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->Print(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGWebView::staticMetaObject = {
    { &QWebEngineView::staticMetaObject, qt_meta_stringdata_CGWebView.data,
      qt_meta_data_CGWebView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGWebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGWebView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGWebView.stringdata0))
        return static_cast<void*>(this);
    return QWebEngineView::qt_metacast(_clname);
}

int CGWebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebEngineView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_CGMenuBar_t {
    QByteArrayData data[13];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGMenuBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGMenuBar_t qt_meta_stringdata_CGMenuBar = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CGMenuBar"
QT_MOC_LITERAL(1, 10, 15), // "actionTriggered"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "actionName"
QT_MOC_LITERAL(4, 38, 1), // "Q"
QT_MOC_LITERAL(5, 40, 10), // "CBaseData*"
QT_MOC_LITERAL(6, 51, 11), // "SetProperty"
QT_MOC_LITERAL(7, 63, 4), // "name"
QT_MOC_LITERAL(8, 68, 5), // "value"
QT_MOC_LITERAL(9, 74, 8), // "Property"
QT_MOC_LITERAL(10, 83, 7), // "AddMenu"
QT_MOC_LITERAL(11, 91, 14), // "menuActionsMap"
QT_MOC_LITERAL(12, 106, 17) // "onActionTriggered"

    },
    "CGMenuBar\0actionTriggered\0\0actionName\0"
    "Q\0CBaseData*\0SetProperty\0name\0value\0"
    "Property\0AddMenu\0menuActionsMap\0"
    "onActionTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGMenuBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x0a /* Public */,
       6,    2,   48,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      12,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    0x80000000 | 5,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    7,    8,
    QMetaType::QVariant, QMetaType::QString,    7,
    QMetaType::Int, QMetaType::QVariantMap,   11,
    QMetaType::Void,

       0        // eod
};

void CGMenuBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGMenuBar *_t = static_cast<CGMenuBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionTriggered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 3: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->AddMenu((*reinterpret_cast< QMap<QString,QVariant>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->onActionTriggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGMenuBar::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGMenuBar::actionTriggered)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGMenuBar::staticMetaObject = {
    { &QMenuBar::staticMetaObject, qt_meta_stringdata_CGMenuBar.data,
      qt_meta_data_CGMenuBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGMenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGMenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGMenuBar.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int CGMenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CGMenuBar::actionTriggered(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CGPushButton_t {
    QByteArrayData data[20];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGPushButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGPushButton_t qt_meta_stringdata_CGPushButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CGPushButton"
QT_MOC_LITERAL(1, 13, 13), // "MenuTriggered"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "text"
QT_MOC_LITERAL(4, 33, 4), // "data"
QT_MOC_LITERAL(5, 38, 1), // "Q"
QT_MOC_LITERAL(6, 40, 10), // "CBaseData*"
QT_MOC_LITERAL(7, 51, 7), // "SetIcon"
QT_MOC_LITERAL(8, 59, 12), // "iconfilePath"
QT_MOC_LITERAL(9, 72, 8), // "pathType"
QT_MOC_LITERAL(10, 81, 11), // "SetProperty"
QT_MOC_LITERAL(11, 93, 4), // "name"
QT_MOC_LITERAL(12, 98, 5), // "value"
QT_MOC_LITERAL(13, 104, 8), // "Property"
QT_MOC_LITERAL(14, 113, 7), // "SetMenu"
QT_MOC_LITERAL(15, 121, 8), // "menuinfo"
QT_MOC_LITERAL(16, 130, 9), // "iconChged"
QT_MOC_LITERAL(17, 140, 15), // "OnMenuTriggered"
QT_MOC_LITERAL(18, 156, 8), // "QAction*"
QT_MOC_LITERAL(19, 165, 6) // "action"

    },
    "CGPushButton\0MenuTriggered\0\0text\0data\0"
    "Q\0CBaseData*\0SetIcon\0iconfilePath\0"
    "pathType\0SetProperty\0name\0value\0"
    "Property\0SetMenu\0menuinfo\0iconChged\0"
    "OnMenuTriggered\0QAction*\0action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGPushButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   64,    2, 0x0a /* Public */,
       7,    2,   65,    2, 0x0a /* Public */,
       7,    1,   70,    2, 0x2a /* Public | MethodCloned */,
      10,    2,   73,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,
      16,    1,   84,    2, 0x08 /* Private */,
      17,    1,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    0x80000000 | 6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   11,   12,
    QMetaType::QVariant, QMetaType::QString,   11,
    QMetaType::QObjectStar, QMetaType::QVariant,   15,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void CGPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGPushButton *_t = static_cast<CGPushButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MenuTriggered((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->SetIcon((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->SetIcon((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 5: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QObject* _r = _t->SetMenu((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->iconChged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->OnMenuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGPushButton::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGPushButton::MenuTriggered)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGPushButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_CGPushButton.data,
      qt_meta_data_CGPushButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGPushButton.stringdata0))
        return static_cast<void*>(this);
    return QToolButton::qt_metacast(_clname);
}

int CGPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CGPushButton::MenuTriggered(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CGToolBar_t {
    QByteArrayData data[14];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGToolBar_t qt_meta_stringdata_CGToolBar = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CGToolBar"
QT_MOC_LITERAL(1, 10, 1), // "Q"
QT_MOC_LITERAL(2, 12, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 23, 0), // ""
QT_MOC_LITERAL(4, 24, 11), // "SetProperty"
QT_MOC_LITERAL(5, 36, 4), // "name"
QT_MOC_LITERAL(6, 41, 5), // "value"
QT_MOC_LITERAL(7, 47, 8), // "Property"
QT_MOC_LITERAL(8, 56, 5), // "Clear"
QT_MOC_LITERAL(9, 62, 9), // "AddAction"
QT_MOC_LITERAL(10, 72, 4), // "args"
QT_MOC_LITERAL(11, 77, 9), // "AddWidget"
QT_MOC_LITERAL(12, 87, 8), // "QWidget*"
QT_MOC_LITERAL(13, 96, 6) // "widget"

    },
    "CGToolBar\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0Clear\0AddAction\0"
    "args\0AddWidget\0QWidget*\0widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    3, 0x0a /* Public */,
       4,    2,   45,    3, 0x0a /* Public */,
       7,    1,   50,    3, 0x0a /* Public */,
       8,    0,   53,    3, 0x0a /* Public */,
       9,    1,   54,    3, 0x0a /* Public */,
      11,    1,   57,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::QObjectStar, QMetaType::QVariant,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void CGToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGToolBar *_t = static_cast<CGToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->Clear(); break;
        case 4: { QObject* _r = _t->AddAction((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 5: _t->AddWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_CGToolBar.data,
      qt_meta_data_CGToolBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGToolBar.stringdata0))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int CGToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_CGTabBar_t {
    QByteArrayData data[13];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTabBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTabBar_t qt_meta_stringdata_CGTabBar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CGTabBar"
QT_MOC_LITERAL(1, 9, 1), // "Q"
QT_MOC_LITERAL(2, 11, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 22, 0), // ""
QT_MOC_LITERAL(4, 23, 11), // "SetProperty"
QT_MOC_LITERAL(5, 35, 4), // "name"
QT_MOC_LITERAL(6, 40, 5), // "value"
QT_MOC_LITERAL(7, 46, 8), // "Property"
QT_MOC_LITERAL(8, 55, 6), // "AddTab"
QT_MOC_LITERAL(9, 62, 4), // "text"
QT_MOC_LITERAL(10, 67, 8), // "iconName"
QT_MOC_LITERAL(11, 76, 9), // "RemoveTab"
QT_MOC_LITERAL(12, 86, 5) // "index"

    },
    "CGTabBar\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0AddTab\0text\0"
    "iconName\0RemoveTab\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTabBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    3, 0x0a /* Public */,
       4,    2,   50,    3, 0x0a /* Public */,
       7,    1,   55,    3, 0x0a /* Public */,
       8,    2,   58,    3, 0x0a /* Public */,
       8,    1,   63,    3, 0x2a /* Public | MethodCloned */,
      11,    1,   66,    3, 0x0a /* Public */,
      11,    0,   69,    3, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Int, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

void CGTabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTabBar *_t = static_cast<CGTabBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->AddTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->AddTab((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->RemoveTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->RemoveTab(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTabBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_CGTabBar.data,
      qt_meta_data_CGTabBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTabBar.stringdata0))
        return static_cast<void*>(this);
    return QTabBar::qt_metacast(_clname);
}

int CGTabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_CGTabWidget_t {
    QByteArrayData data[16];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTabWidget_t qt_meta_stringdata_CGTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CGTabWidget"
QT_MOC_LITERAL(1, 12, 1), // "Q"
QT_MOC_LITERAL(2, 14, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 25, 0), // ""
QT_MOC_LITERAL(4, 26, 11), // "SetProperty"
QT_MOC_LITERAL(5, 38, 4), // "name"
QT_MOC_LITERAL(6, 43, 5), // "value"
QT_MOC_LITERAL(7, 49, 8), // "Property"
QT_MOC_LITERAL(8, 58, 6), // "AddTab"
QT_MOC_LITERAL(9, 65, 6), // "widget"
QT_MOC_LITERAL(10, 72, 4), // "text"
QT_MOC_LITERAL(11, 77, 8), // "iconName"
QT_MOC_LITERAL(12, 86, 9), // "RemoveTab"
QT_MOC_LITERAL(13, 96, 5), // "index"
QT_MOC_LITERAL(14, 102, 6), // "Widget"
QT_MOC_LITERAL(15, 109, 8) // "QWidget*"

    },
    "CGTabWidget\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0AddTab\0widget\0"
    "text\0iconName\0RemoveTab\0index\0Widget\0"
    "QWidget*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    3, 0x0a /* Public */,
       4,    2,   60,    3, 0x0a /* Public */,
       7,    1,   65,    3, 0x0a /* Public */,
       8,    3,   68,    3, 0x0a /* Public */,
       8,    2,   75,    3, 0x2a /* Public | MethodCloned */,
      12,    1,   80,    3, 0x0a /* Public */,
      12,    0,   83,    3, 0x2a /* Public | MethodCloned */,
      14,    1,   84,    3, 0x0a /* Public */,
      14,    0,   87,    3, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Int, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString,    9,   10,   11,
    QMetaType::Int, QMetaType::QObjectStar, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    0x80000000 | 15, QMetaType::Int,   13,
    0x80000000 | 15,

       0        // eod
};

void CGTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTabWidget *_t = static_cast<CGTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->AddTab((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->AddTab((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->RemoveTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->RemoveTab(); break;
        case 7: { QWidget* _r = _t->Widget((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 8: { QWidget* _r = _t->Widget();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_CGTabWidget.data,
      qt_meta_data_CGTabWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int CGTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
struct qt_meta_stringdata_CGDateEdit_t {
    QByteArrayData data[12];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGDateEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGDateEdit_t qt_meta_stringdata_CGDateEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGDateEdit"
QT_MOC_LITERAL(1, 11, 1), // "Q"
QT_MOC_LITERAL(2, 13, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 24, 0), // ""
QT_MOC_LITERAL(4, 25, 11), // "SetProperty"
QT_MOC_LITERAL(5, 37, 4), // "name"
QT_MOC_LITERAL(6, 42, 5), // "value"
QT_MOC_LITERAL(7, 48, 8), // "Property"
QT_MOC_LITERAL(8, 57, 7), // "SetDate"
QT_MOC_LITERAL(9, 65, 4), // "date"
QT_MOC_LITERAL(10, 70, 6), // "format"
QT_MOC_LITERAL(11, 77, 7) // "GetDate"

    },
    "CGDateEdit\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0SetDate\0date\0"
    "format\0GetDate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGDateEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    3, 0x0a /* Public */,
       4,    2,   50,    3, 0x0a /* Public */,
       7,    1,   55,    3, 0x0a /* Public */,
       8,    2,   58,    3, 0x0a /* Public */,
       8,    1,   63,    3, 0x2a /* Public | MethodCloned */,
       8,    0,   66,    3, 0x2a /* Public | MethodCloned */,
      11,    0,   67,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void CGDateEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGDateEdit *_t = static_cast<CGDateEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetDate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->SetDate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->SetDate(); break;
        case 6: { QString _r = _t->GetDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGDateEdit::staticMetaObject = {
    { &QDateEdit::staticMetaObject, qt_meta_stringdata_CGDateEdit.data,
      qt_meta_data_CGDateEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGDateEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGDateEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGDateEdit.stringdata0))
        return static_cast<void*>(this);
    return QDateEdit::qt_metacast(_clname);
}

int CGDateEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDateEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_CGTimeEdit_t {
    QByteArrayData data[12];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTimeEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTimeEdit_t qt_meta_stringdata_CGTimeEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGTimeEdit"
QT_MOC_LITERAL(1, 11, 1), // "Q"
QT_MOC_LITERAL(2, 13, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 24, 0), // ""
QT_MOC_LITERAL(4, 25, 11), // "SetProperty"
QT_MOC_LITERAL(5, 37, 4), // "name"
QT_MOC_LITERAL(6, 42, 5), // "value"
QT_MOC_LITERAL(7, 48, 8), // "Property"
QT_MOC_LITERAL(8, 57, 7), // "SetTime"
QT_MOC_LITERAL(9, 65, 4), // "time"
QT_MOC_LITERAL(10, 70, 6), // "format"
QT_MOC_LITERAL(11, 77, 7) // "GetTime"

    },
    "CGTimeEdit\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0SetTime\0time\0"
    "format\0GetTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTimeEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    3, 0x0a /* Public */,
       4,    2,   50,    3, 0x0a /* Public */,
       7,    1,   55,    3, 0x0a /* Public */,
       8,    2,   58,    3, 0x0a /* Public */,
       8,    1,   63,    3, 0x2a /* Public | MethodCloned */,
       8,    0,   66,    3, 0x2a /* Public | MethodCloned */,
      11,    0,   67,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void CGTimeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTimeEdit *_t = static_cast<CGTimeEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetTime((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->SetTime((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->SetTime(); break;
        case 6: { QString _r = _t->GetTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTimeEdit::staticMetaObject = {
    { &QTimeEdit::staticMetaObject, qt_meta_stringdata_CGTimeEdit.data,
      qt_meta_data_CGTimeEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTimeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTimeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTimeEdit.stringdata0))
        return static_cast<void*>(this);
    return QTimeEdit::qt_metacast(_clname);
}

int CGTimeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimeEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_CGCalendarWidget_t {
    QByteArrayData data[13];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGCalendarWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGCalendarWidget_t qt_meta_stringdata_CGCalendarWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CGCalendarWidget"
QT_MOC_LITERAL(1, 17, 16), // "SelectionChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "year"
QT_MOC_LITERAL(4, 40, 5), // "month"
QT_MOC_LITERAL(5, 46, 3), // "day"
QT_MOC_LITERAL(6, 50, 1), // "Q"
QT_MOC_LITERAL(7, 52, 10), // "CBaseData*"
QT_MOC_LITERAL(8, 63, 11), // "SetProperty"
QT_MOC_LITERAL(9, 75, 4), // "name"
QT_MOC_LITERAL(10, 80, 5), // "value"
QT_MOC_LITERAL(11, 86, 8), // "Property"
QT_MOC_LITERAL(12, 95, 11) // "dateChanged"

    },
    "CGCalendarWidget\0SelectionChanged\0\0"
    "year\0month\0day\0Q\0CBaseData*\0SetProperty\0"
    "name\0value\0Property\0dateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGCalendarWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   46,    2, 0x0a /* Public */,
       8,    2,   47,    2, 0x0a /* Public */,
      11,    1,   52,    2, 0x0a /* Public */,
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    0x80000000 | 7,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    9,   10,
    QMetaType::QVariant, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void CGCalendarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGCalendarWidget *_t = static_cast<CGCalendarWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SelectionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 3: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->dateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGCalendarWidget::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGCalendarWidget::SelectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGCalendarWidget::staticMetaObject = {
    { &QCalendarWidget::staticMetaObject, qt_meta_stringdata_CGCalendarWidget.data,
      qt_meta_data_CGCalendarWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGCalendarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGCalendarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGCalendarWidget.stringdata0))
        return static_cast<void*>(this);
    return QCalendarWidget::qt_metacast(_clname);
}

int CGCalendarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCalendarWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CGCalendarWidget::SelectionChanged(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CGProgressBar_t {
    QByteArrayData data[9];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGProgressBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGProgressBar_t qt_meta_stringdata_CGProgressBar = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CGProgressBar"
QT_MOC_LITERAL(1, 14, 6), // "GetTag"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 1), // "Q"
QT_MOC_LITERAL(4, 24, 10), // "CBaseData*"
QT_MOC_LITERAL(5, 35, 11), // "SetProperty"
QT_MOC_LITERAL(6, 47, 4), // "name"
QT_MOC_LITERAL(7, 52, 5), // "value"
QT_MOC_LITERAL(8, 58, 8) // "Property"

    },
    "CGProgressBar\0GetTag\0\0Q\0CBaseData*\0"
    "SetProperty\0name\0value\0Property"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGProgressBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       5,    2,   36,    2, 0x0a /* Public */,
       8,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    0x80000000 | 4,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    6,    7,
    QMetaType::QVariant, QMetaType::QString,    6,

       0        // eod
};

void CGProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGProgressBar *_t = static_cast<CGProgressBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->GetTag();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 3: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGProgressBar::staticMetaObject = {
    { &QProgressBar::staticMetaObject, qt_meta_stringdata_CGProgressBar.data,
      qt_meta_data_CGProgressBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGProgressBar.stringdata0))
        return static_cast<void*>(this);
    return QProgressBar::qt_metacast(_clname);
}

int CGProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProgressBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_CGTextEdit_t {
    QByteArrayData data[11];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTextEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTextEdit_t qt_meta_stringdata_CGTextEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGTextEdit"
QT_MOC_LITERAL(1, 11, 1), // "Q"
QT_MOC_LITERAL(2, 13, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 24, 0), // ""
QT_MOC_LITERAL(4, 25, 11), // "SetProperty"
QT_MOC_LITERAL(5, 37, 4), // "name"
QT_MOC_LITERAL(6, 42, 5), // "value"
QT_MOC_LITERAL(7, 48, 8), // "Property"
QT_MOC_LITERAL(8, 57, 12), // "SetMaxLength"
QT_MOC_LITERAL(9, 70, 9), // "maxLength"
QT_MOC_LITERAL(10, 80, 11) // "TextChanged"

    },
    "CGTextEdit\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0SetMaxLength\0"
    "maxLength\0TextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    3, 0x0a /* Public */,
       4,    2,   40,    3, 0x0a /* Public */,
       7,    1,   45,    3, 0x0a /* Public */,
       8,    1,   48,    3, 0x0a /* Public */,
      10,    0,   51,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void CGTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTextEdit *_t = static_cast<CGTextEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetMaxLength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->TextChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_CGTextEdit.data,
      qt_meta_data_CGTextEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTextEdit.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int CGTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
struct qt_meta_stringdata_CGLineEdit_t {
    QByteArrayData data[10];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGLineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGLineEdit_t qt_meta_stringdata_CGLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGLineEdit"
QT_MOC_LITERAL(1, 11, 1), // "Q"
QT_MOC_LITERAL(2, 13, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 24, 0), // ""
QT_MOC_LITERAL(4, 25, 11), // "SetProperty"
QT_MOC_LITERAL(5, 37, 4), // "name"
QT_MOC_LITERAL(6, 42, 5), // "value"
QT_MOC_LITERAL(7, 48, 8), // "Property"
QT_MOC_LITERAL(8, 57, 15), // "SetPasteEnabled"
QT_MOC_LITERAL(9, 73, 8) // "beEnable"

    },
    "CGLineEdit\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0SetPasteEnabled\0"
    "beEnable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGLineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    3, 0x0a /* Public */,
       4,    2,   35,    3, 0x0a /* Public */,
       7,    1,   40,    3, 0x0a /* Public */,
       8,    1,   43,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void CGLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGLineEdit *_t = static_cast<CGLineEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetPasteEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_CGLineEdit.data,
      qt_meta_data_CGLineEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGLineEdit.stringdata0))
        return static_cast<void*>(this);
    return QLineEdit::qt_metacast(_clname);
}

int CGLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_CGFontEditWidget_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGFontEditWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGFontEditWidget_t qt_meta_stringdata_CGFontEditWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CGFontEditWidget"
QT_MOC_LITERAL(1, 17, 12), // "valueChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "value"
QT_MOC_LITERAL(4, 37, 13), // "GetFontString"
QT_MOC_LITERAL(5, 51, 7), // "SetFont"
QT_MOC_LITERAL(6, 59, 10), // "fontString"
QT_MOC_LITERAL(7, 70, 8), // "setValue"
QT_MOC_LITERAL(8, 79, 13) // "buttonClicked"

    },
    "CGFontEditWidget\0valueChanged\0\0value\0"
    "GetFontString\0SetFont\0fontString\0"
    "setValue\0buttonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGFontEditWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QFont,    3,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QFont,    3,
    QMetaType::Void,

       0        // eod
};

void CGFontEditWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGFontEditWidget *_t = static_cast<CGFontEditWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 1: { QString _r = _t->GetFontString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->SetFont((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setValue((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 4: _t->buttonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGFontEditWidget::*)(const QFont & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGFontEditWidget::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGFontEditWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CGFontEditWidget.data,
      qt_meta_data_CGFontEditWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGFontEditWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGFontEditWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGFontEditWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CGFontEditWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CGFontEditWidget::valueChanged(const QFont & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QSwitchButton_t {
    QByteArrayData data[14];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSwitchButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSwitchButton_t qt_meta_stringdata_QSwitchButton = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSwitchButton"
QT_MOC_LITERAL(1, 14, 1), // "Q"
QT_MOC_LITERAL(2, 16, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 27, 0), // ""
QT_MOC_LITERAL(4, 28, 11), // "SetProperty"
QT_MOC_LITERAL(5, 40, 4), // "name"
QT_MOC_LITERAL(6, 45, 5), // "value"
QT_MOC_LITERAL(7, 51, 8), // "Property"
QT_MOC_LITERAL(8, 60, 7), // "animate"
QT_MOC_LITERAL(9, 68, 11), // "setPosition"
QT_MOC_LITERAL(10, 80, 8), // "position"
QT_MOC_LITERAL(11, 89, 12), // "checkedStyle"
QT_MOC_LITERAL(12, 102, 8), // "bgPixmap"
QT_MOC_LITERAL(13, 111, 10) // "forePixmap"

    },
    "QSwitchButton\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0animate\0setPosition\0"
    "position\0checkedStyle\0bgPixmap\0"
    "forePixmap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSwitchButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       4,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    3, 0x0a /* Public */,
       4,    2,   40,    3, 0x0a /* Public */,
       7,    1,   45,    3, 0x0a /* Public */,
       8,    1,   48,    3, 0x0a /* Public */,
       9,    1,   51,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QReal,    6,

 // properties: name, type, flags
      10, QMetaType::QReal, 0x00095103,
      11, QMetaType::Int, 0x00095003,
      12, QMetaType::QString, 0x00095003,
      13, QMetaType::QString, 0x00095003,

       0        // eod
};

void QSwitchButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSwitchButton *_t = static_cast<QSwitchButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->animate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setPosition((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QSwitchButton *_t = static_cast<QSwitchButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->position(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->GetCheckedStyle(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->GetBgPixmap(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->GetForePixmap(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QSwitchButton *_t = static_cast<QSwitchButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPosition(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->SetCheckedStyle(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->SetBgPixmap(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->SetForePixmap(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QSwitchButton::staticMetaObject = {
    { &QAbstractButton::staticMetaObject, qt_meta_stringdata_QSwitchButton.data,
      qt_meta_data_QSwitchButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QSwitchButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSwitchButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSwitchButton.stringdata0))
        return static_cast<void*>(this);
    return QAbstractButton::qt_metacast(_clname);
}

int QSwitchButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
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
struct qt_meta_stringdata_CGTreeModel_t {
    QByteArrayData data[12];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTreeModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTreeModel_t qt_meta_stringdata_CGTreeModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CGTreeModel"
QT_MOC_LITERAL(1, 12, 9), // "SetHeader"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "slist"
QT_MOC_LITERAL(4, 29, 10), // "InsertItem"
QT_MOC_LITERAL(5, 40, 8), // "itemName"
QT_MOC_LITERAL(6, 49, 8), // "itemType"
QT_MOC_LITERAL(7, 58, 9), // "classType"
QT_MOC_LITERAL(8, 68, 3), // "tip"
QT_MOC_LITERAL(9, 72, 12), // "fileIconName"
QT_MOC_LITERAL(10, 85, 4), // "Load"
QT_MOC_LITERAL(11, 90, 4) // "data"

    },
    "CGTreeModel\0SetHeader\0\0slist\0InsertItem\0"
    "itemName\0itemType\0classType\0tip\0"
    "fileIconName\0Load\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTreeModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    5,   42,    2, 0x0a /* Public */,
       4,    4,   53,    2, 0x2a /* Public | MethodCloned */,
       4,    3,   62,    2, 0x2a /* Public | MethodCloned */,
      10,    1,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Bool, QMetaType::QVariant,   11,

       0        // eod
};

void CGTreeModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTreeModel *_t = static_cast<CGTreeModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetHeader((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->InsertItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 2: _t->InsertItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->InsertItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: { bool _r = _t->Load((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTreeModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_CGTreeModel.data,
      qt_meta_data_CGTreeModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTreeModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTreeModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTreeModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int CGTreeModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
struct qt_meta_stringdata_CGTreeView_t {
    QByteArrayData data[32];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTreeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTreeView_t qt_meta_stringdata_CGTreeView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGTreeView"
QT_MOC_LITERAL(1, 11, 15), // "SIGItemSelected"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "itemName"
QT_MOC_LITERAL(4, 37, 4), // "type"
QT_MOC_LITERAL(5, 42, 11), // "ItemClicked"
QT_MOC_LITERAL(6, 54, 5), // "index"
QT_MOC_LITERAL(7, 60, 6), // "column"
QT_MOC_LITERAL(8, 67, 4), // "text"
QT_MOC_LITERAL(9, 72, 4), // "data"
QT_MOC_LITERAL(10, 77, 17), // "ItemDoubleClicked"
QT_MOC_LITERAL(11, 95, 12), // "ItemExpanded"
QT_MOC_LITERAL(12, 108, 9), // "DragEvent"
QT_MOC_LITERAL(13, 118, 7), // "jsonstr"
QT_MOC_LITERAL(14, 126, 18), // "RequestContextMenu"
QT_MOC_LITERAL(15, 145, 18), // "ContextMenuClicked"
QT_MOC_LITERAL(16, 164, 8), // "menu_txt"
QT_MOC_LITERAL(17, 173, 8), // "act_info"
QT_MOC_LITERAL(18, 182, 5), // "Model"
QT_MOC_LITERAL(19, 188, 15), // "OnFilterChanged"
QT_MOC_LITERAL(20, 204, 3), // "str"
QT_MOC_LITERAL(21, 208, 15), // "SetHeaderLabels"
QT_MOC_LITERAL(22, 224, 6), // "labels"
QT_MOC_LITERAL(23, 231, 14), // "SetColumnWidth"
QT_MOC_LITERAL(24, 246, 5), // "width"
QT_MOC_LITERAL(25, 252, 4), // "Load"
QT_MOC_LITERAL(26, 257, 15), // "ShowContextMenu"
QT_MOC_LITERAL(27, 273, 9), // "menuArray"
QT_MOC_LITERAL(28, 283, 9), // "OnClicked"
QT_MOC_LITERAL(29, 293, 11), // "QModelIndex"
QT_MOC_LITERAL(30, 305, 11), // "OnDbClicked"
QT_MOC_LITERAL(31, 317, 20) // "OnContextMenuClicked"

    },
    "CGTreeView\0SIGItemSelected\0\0itemName\0"
    "type\0ItemClicked\0index\0column\0text\0"
    "data\0ItemDoubleClicked\0ItemExpanded\0"
    "DragEvent\0jsonstr\0RequestContextMenu\0"
    "ContextMenuClicked\0menu_txt\0act_info\0"
    "Model\0OnFilterChanged\0str\0SetHeaderLabels\0"
    "labels\0SetColumnWidth\0width\0Load\0"
    "ShowContextMenu\0menuArray\0OnClicked\0"
    "QModelIndex\0OnDbClicked\0OnContextMenuClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       5,    4,  104,    2, 0x06 /* Public */,
      10,    4,  113,    2, 0x06 /* Public */,
      11,    3,  122,    2, 0x06 /* Public */,
      12,    1,  129,    2, 0x06 /* Public */,
      14,    4,  132,    2, 0x06 /* Public */,
      15,    4,  141,    2, 0x06 /* Public */,
      15,    3,  150,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  157,    2, 0x0a /* Public */,
      19,    1,  158,    2, 0x0a /* Public */,
      21,    1,  161,    2, 0x0a /* Public */,
      23,    2,  164,    2, 0x0a /* Public */,
      25,    1,  169,    2, 0x0a /* Public */,
      26,    1,  172,    2, 0x0a /* Public */,
      28,    1,  175,    2, 0x08 /* Private */,
      30,    1,  178,    2, 0x08 /* Private */,
      31,    0,  181,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    8,    9,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QVariant,    6,    7,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    6,    7,   16,

 // slots: parameters
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QStringList,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,   24,
    QMetaType::Bool, QMetaType::QVariant,    9,
    QMetaType::Void, QMetaType::QVariant,   27,
    QMetaType::Void, 0x80000000 | 29,    6,
    QMetaType::Void, 0x80000000 | 29,    6,
    QMetaType::Void,

       0        // eod
};

void CGTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGTreeView *_t = static_cast<CGTreeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIGItemSelected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->ItemClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->ItemDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->ItemExpanded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->DragEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->RequestContextMenu((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 6: _t->ContextMenuClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4]))); break;
        case 7: _t->ContextMenuClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: { QObject* _r = _t->Model();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->OnFilterChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->SetHeaderLabels((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 11: _t->SetColumnWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: { bool _r = _t->Load((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->ShowContextMenu((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 14: _t->OnClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->OnDbClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 16: _t->OnContextMenuClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGTreeView::*)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeView::SIGItemSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CGTreeView::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeView::ItemClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CGTreeView::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeView::ItemDoubleClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CGTreeView::*)(int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeView::ItemExpanded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CGTreeView::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeView::DragEvent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CGTreeView::*)(int , int , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeView::RequestContextMenu)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CGTreeView::*)(int , int , QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGTreeView::ContextMenuClicked)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_CGTreeView.data,
      qt_meta_data_CGTreeView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTreeView.stringdata0))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int CGTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void CGTreeView::SIGItemSelected(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGTreeView::ItemClicked(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CGTreeView::ItemDoubleClicked(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CGTreeView::ItemExpanded(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CGTreeView::DragEvent(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CGTreeView::RequestContextMenu(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CGTreeView::ContextMenuClicked(int _t1, int _t2, QString _t3, QVariant _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_CGCheckBox_t {
    QByteArrayData data[14];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGCheckBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGCheckBox_t qt_meta_stringdata_CGCheckBox = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGCheckBox"
QT_MOC_LITERAL(1, 11, 1), // "Q"
QT_MOC_LITERAL(2, 13, 10), // "CBaseData*"
QT_MOC_LITERAL(3, 24, 0), // ""
QT_MOC_LITERAL(4, 25, 11), // "SetProperty"
QT_MOC_LITERAL(5, 37, 4), // "name"
QT_MOC_LITERAL(6, 42, 5), // "value"
QT_MOC_LITERAL(7, 48, 8), // "Property"
QT_MOC_LITERAL(8, 57, 7), // "SetIcon"
QT_MOC_LITERAL(9, 65, 8), // "iconFile"
QT_MOC_LITERAL(10, 74, 8), // "pathType"
QT_MOC_LITERAL(11, 83, 11), // "SetIconSize"
QT_MOC_LITERAL(12, 95, 1), // "w"
QT_MOC_LITERAL(13, 97, 1) // "h"

    },
    "CGCheckBox\0Q\0CBaseData*\0\0SetProperty\0"
    "name\0value\0Property\0SetIcon\0iconFile\0"
    "pathType\0SetIconSize\0w\0h"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGCheckBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    3, 0x0a /* Public */,
       4,    2,   45,    3, 0x0a /* Public */,
       7,    1,   50,    3, 0x0a /* Public */,
       8,    2,   53,    3, 0x0a /* Public */,
       8,    1,   58,    3, 0x2a /* Public | MethodCloned */,
      11,    2,   61,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,

       0        // eod
};

void CGCheckBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGCheckBox *_t = static_cast<CGCheckBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { CBaseData* _r = _t->Q();
            if (_a[0]) *reinterpret_cast< CBaseData**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 2: { QVariant _r = _t->Property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetIcon((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->SetIcon((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->SetIconSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGCheckBox::staticMetaObject = {
    { &QCheckBox::staticMetaObject, qt_meta_stringdata_CGCheckBox.data,
      qt_meta_data_CGCheckBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGCheckBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGCheckBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGCheckBox.stringdata0))
        return static_cast<void*>(this);
    return QCheckBox::qt_metacast(_clname);
}

int CGCheckBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCheckBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
