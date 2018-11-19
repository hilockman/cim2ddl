/****************************************************************************
** Meta object code from reading C++ file 'qxtcheckcombobox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widgets/qxtcheckcombobox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxtcheckcombobox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QxtCheckComboBoxPrivate_t {
    QByteArrayData data[5];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QxtCheckComboBoxPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QxtCheckComboBoxPrivate_t qt_meta_stringdata_QxtCheckComboBoxPrivate = {
    {
QT_MOC_LITERAL(0, 0, 23), // "QxtCheckComboBoxPrivate"
QT_MOC_LITERAL(1, 24, 18), // "updateCheckedItems"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 16), // "toggleCheckState"
QT_MOC_LITERAL(4, 61, 5) // "index"

    },
    "QxtCheckComboBoxPrivate\0updateCheckedItems\0"
    "\0toggleCheckState\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QxtCheckComboBoxPrivate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void QxtCheckComboBoxPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QxtCheckComboBoxPrivate *_t = static_cast<QxtCheckComboBoxPrivate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateCheckedItems(); break;
        case 1: _t->toggleCheckState((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QxtCheckComboBoxPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QxtCheckComboBoxPrivate.data,
      qt_meta_data_QxtCheckComboBoxPrivate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QxtCheckComboBoxPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtCheckComboBoxPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QxtCheckComboBoxPrivate.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QxtPrivate<QxtCheckComboBox>"))
        return static_cast< QxtPrivate<QxtCheckComboBox>*>(this);
    return QObject::qt_metacast(_clname);
}

int QxtCheckComboBoxPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_QxtCheckComboBox_t {
    QByteArrayData data[13];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QxtCheckComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QxtCheckComboBox_t qt_meta_stringdata_QxtCheckComboBox = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QxtCheckComboBox"
QT_MOC_LITERAL(1, 17, 19), // "checkedItemsChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "items"
QT_MOC_LITERAL(4, 44, 15), // "setCheckedItems"
QT_MOC_LITERAL(5, 60, 8), // "ItemList"
QT_MOC_LITERAL(6, 69, 11), // "SetItemList"
QT_MOC_LITERAL(7, 81, 1), // "l"
QT_MOC_LITERAL(8, 83, 9), // "separator"
QT_MOC_LITERAL(9, 93, 11), // "defaultText"
QT_MOC_LITERAL(10, 105, 12), // "checkedItems"
QT_MOC_LITERAL(11, 118, 11), // "checkIndexs"
QT_MOC_LITERAL(12, 130, 8) // "itemList"

    },
    "QxtCheckComboBox\0checkedItemsChanged\0"
    "\0items\0setCheckedItems\0ItemList\0"
    "SetItemList\0l\0separator\0defaultText\0"
    "checkedItems\0checkIndexs\0itemList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QxtCheckComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       5,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       5,    0,   40,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QStringList,    7,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00095103,
       9, QMetaType::QString, 0x00095103,
      10, QMetaType::QStringList, 0x00095103,
      11, QMetaType::QStringList, 0x00095103,
      12, QMetaType::QStringList, 0x00095003,

       0        // eod
};

void QxtCheckComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QxtCheckComboBox *_t = static_cast<QxtCheckComboBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkedItemsChanged((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->setCheckedItems((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: { QStringList _r = _t->ItemList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetItemList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QxtCheckComboBox::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QxtCheckComboBox::checkedItemsChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QxtCheckComboBox *_t = static_cast<QxtCheckComboBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->separator(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->defaultText(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->checkedItems(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = _t->checkIndexs(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = _t->ItemList(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QxtCheckComboBox *_t = static_cast<QxtCheckComboBox *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSeparator(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDefaultText(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCheckedItems(*reinterpret_cast< QStringList*>(_v)); break;
        case 3: _t->setCheckIndexs(*reinterpret_cast< QStringList*>(_v)); break;
        case 4: _t->SetItemList(*reinterpret_cast< QStringList*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QxtCheckComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_QxtCheckComboBox.data,
      qt_meta_data_QxtCheckComboBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QxtCheckComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtCheckComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QxtCheckComboBox.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int QxtCheckComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
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
void QxtCheckComboBox::checkedItemsChanged(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QxtCheckComboModel_t {
    QByteArrayData data[3];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QxtCheckComboModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QxtCheckComboModel_t qt_meta_stringdata_QxtCheckComboModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QxtCheckComboModel"
QT_MOC_LITERAL(1, 19, 17), // "checkStateChanged"
QT_MOC_LITERAL(2, 37, 0) // ""

    },
    "QxtCheckComboModel\0checkStateChanged\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QxtCheckComboModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void QxtCheckComboModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QxtCheckComboModel *_t = static_cast<QxtCheckComboModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkStateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QxtCheckComboModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QxtCheckComboModel::checkStateChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QxtCheckComboModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_QxtCheckComboModel.data,
      qt_meta_data_QxtCheckComboModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QxtCheckComboModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QxtCheckComboModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QxtCheckComboModel.stringdata0))
        return static_cast<void*>(this);
    return QStandardItemModel::qt_metacast(_clname);
}

int QxtCheckComboModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QxtCheckComboModel::checkStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
