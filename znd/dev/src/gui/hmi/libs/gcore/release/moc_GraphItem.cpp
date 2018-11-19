/****************************************************************************
** Meta object code from reading C++ file 'GraphItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GraphItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPolygonData_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPolygonData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPolygonData_t qt_meta_stringdata_CPolygonData = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CPolygonData"
QT_MOC_LITERAL(1, 13, 12), // "SetArrowInfo"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "arrowinfo"
QT_MOC_LITERAL(4, 37, 11), // "fillPercent"
QT_MOC_LITERAL(5, 49, 7) // "fillDir"

    },
    "CPolygonData\0SetArrowInfo\0\0arrowinfo\0"
    "fillPercent\0fillDir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPolygonData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       2,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // properties: name, type, flags
       4, QMetaType::QReal, 0x00095003,
       5, QMetaType::Int, 0x00095003,

       0        // eod
};

void CPolygonData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPolygonData *_t = static_cast<CPolygonData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetArrowInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CPolygonData *_t = static_cast<CPolygonData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->FillPercent(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->GetFillDir(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CPolygonData *_t = static_cast<CPolygonData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetFillPercent(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->SetFillDir(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CPolygonData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CPolygonData.data,
      qt_meta_data_CPolygonData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CPolygonData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPolygonData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPolygonData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CPolygonData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CRectData_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRectData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRectData_t qt_meta_stringdata_CRectData = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CRectData"
QT_MOC_LITERAL(1, 10, 11), // "fillPercent"
QT_MOC_LITERAL(2, 22, 7), // "fillDir"
QT_MOC_LITERAL(3, 30, 4) // "rect"

    },
    "CRectData\0fillPercent\0fillDir\0rect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRectData[] = {

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
       1, QMetaType::QReal, 0x00095003,
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::QRectF, 0x00095003,

       0        // eod
};

void CRectData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        CRectData *_t = static_cast<CRectData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->FillPercent(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->GetFillDir(); break;
        case 2: *reinterpret_cast< QRectF*>(_v) = _t->Rect(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CRectData *_t = static_cast<CRectData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetFillPercent(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->SetFillDir(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->SetRect(*reinterpret_cast< QRectF*>(_v)); break;
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

QT_INIT_METAOBJECT const QMetaObject CRectData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CRectData.data,
      qt_meta_data_CRectData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CRectData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRectData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CRectData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CRectData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CEllipseData_t {
    QByteArrayData data[7];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CEllipseData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CEllipseData_t qt_meta_stringdata_CEllipseData = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CEllipseData"
QT_MOC_LITERAL(1, 13, 12), // "SetSpanAngle"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "angle"
QT_MOC_LITERAL(4, 33, 11), // "fillPercent"
QT_MOC_LITERAL(5, 45, 7), // "fillDir"
QT_MOC_LITERAL(6, 53, 4) // "rect"

    },
    "CEllipseData\0SetSpanAngle\0\0angle\0"
    "fillPercent\0fillDir\0rect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CEllipseData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       3,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // properties: name, type, flags
       4, QMetaType::QReal, 0x00095003,
       5, QMetaType::Int, 0x00095003,
       6, QMetaType::QRectF, 0x00095003,

       0        // eod
};

void CEllipseData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CEllipseData *_t = static_cast<CEllipseData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetSpanAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CEllipseData *_t = static_cast<CEllipseData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->FillPercent(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->GetFillDir(); break;
        case 2: *reinterpret_cast< QRectF*>(_v) = _t->Rect(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CEllipseData *_t = static_cast<CEllipseData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetFillPercent(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->SetFillDir(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->SetRect(*reinterpret_cast< QRectF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CEllipseData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CEllipseData.data,
      qt_meta_data_CEllipseData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CEllipseData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CEllipseData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CEllipseData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CEllipseData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CTextData_t {
    QByteArrayData data[30];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTextData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTextData_t qt_meta_stringdata_CTextData = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CTextData"
QT_MOC_LITERAL(1, 10, 11), // "SetProperty"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "propname"
QT_MOC_LITERAL(4, 32, 5), // "value"
QT_MOC_LITERAL(5, 38, 7), // "SetFont"
QT_MOC_LITERAL(6, 46, 1), // "f"
QT_MOC_LITERAL(7, 48, 4), // "Font"
QT_MOC_LITERAL(8, 53, 12), // "SetTextColor"
QT_MOC_LITERAL(9, 66, 1), // "c"
QT_MOC_LITERAL(10, 68, 12), // "GetLineWidth"
QT_MOC_LITERAL(11, 81, 12), // "SetLineColor"
QT_MOC_LITERAL(12, 94, 5), // "color"
QT_MOC_LITERAL(13, 100, 11), // "GetDispType"
QT_MOC_LITERAL(14, 112, 16), // "GetDecimalDigits"
QT_MOC_LITERAL(15, 129, 14), // "GetTimeFormatA"
QT_MOC_LITERAL(16, 144, 9), // "GetPrefix"
QT_MOC_LITERAL(17, 154, 9), // "GetSuffix"
QT_MOC_LITERAL(18, 164, 4), // "Text"
QT_MOC_LITERAL(19, 169, 7), // "SetText"
QT_MOC_LITERAL(20, 177, 4), // "text"
QT_MOC_LITERAL(21, 182, 12), // "SetLineWidth"
QT_MOC_LITERAL(22, 195, 5), // "width"
QT_MOC_LITERAL(23, 201, 13), // "SetTextDirect"
QT_MOC_LITERAL(24, 215, 10), // "textDirect"
QT_MOC_LITERAL(25, 226, 13), // "GetTextDirect"
QT_MOC_LITERAL(26, 240, 10), // "SetOrgText"
QT_MOC_LITERAL(27, 251, 7), // "orgText"
QT_MOC_LITERAL(28, 259, 10), // "GetOrgText"
QT_MOC_LITERAL(29, 270, 6) // "direct"

    },
    "CTextData\0SetProperty\0\0propname\0value\0"
    "SetFont\0f\0Font\0SetTextColor\0c\0"
    "GetLineWidth\0SetLineColor\0color\0"
    "GetDispType\0GetDecimalDigits\0"
    "GetTimeFormatA\0GetPrefix\0GetSuffix\0"
    "Text\0SetText\0text\0SetLineWidth\0width\0"
    "SetTextDirect\0textDirect\0GetTextDirect\0"
    "SetOrgText\0orgText\0GetOrgText\0direct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTextData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       2,  140, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  104,    2, 0x0a /* Public */,
       5,    1,  109,    2, 0x0a /* Public */,
       7,    0,  112,    2, 0x0a /* Public */,
       8,    1,  113,    2, 0x0a /* Public */,
      10,    0,  116,    2, 0x0a /* Public */,
      11,    1,  117,    2, 0x0a /* Public */,
      13,    0,  120,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    0,  125,    2, 0x0a /* Public */,
      19,    1,  126,    2, 0x0a /* Public */,
      21,    1,  129,    2, 0x0a /* Public */,
      23,    1,  132,    2, 0x0a /* Public */,
      25,    0,  135,    2, 0x0a /* Public */,
      26,    1,  136,    2, 0x0a /* Public */,
      28,    0,  139,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QFont,    6,
    QMetaType::QFont,
    QMetaType::Void, QMetaType::QColor,    9,
    QMetaType::QReal,
    QMetaType::Void, QMetaType::QColor,   12,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QReal,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::QString,

 // properties: name, type, flags
      20, QMetaType::QString, 0x00095003,
      29, QMetaType::Int, 0x00095003,

       0        // eod
};

void CTextData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTextData *_t = static_cast<CTextData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 2: { QFont _r = _t->Font();
            if (_a[0]) *reinterpret_cast< QFont*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->SetTextColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: { qreal _r = _t->GetLineWidth();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->SetLineColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 6: { int _r = _t->GetDispType();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->GetDecimalDigits();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->GetTimeFormatA();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->GetPrefix();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->GetSuffix();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->Text();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->SetText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->SetLineWidth((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 14: _t->SetTextDirect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: { int _r = _t->GetTextDirect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->SetOrgText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: { QString _r = _t->GetOrgText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CTextData *_t = static_cast<CTextData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->Text(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->GetTextDirect(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CTextData *_t = static_cast<CTextData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->SetTextDirect(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CTextData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CTextData.data,
      qt_meta_data_CTextData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CTextData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTextData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CTextData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CTextData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CGraphicsTextData_t {
    QByteArrayData data[20];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGraphicsTextData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGraphicsTextData_t qt_meta_stringdata_CGraphicsTextData = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CGraphicsTextData"
QT_MOC_LITERAL(1, 18, 7), // "SetFont"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 1), // "f"
QT_MOC_LITERAL(4, 29, 4), // "Font"
QT_MOC_LITERAL(5, 34, 12), // "SetTextColor"
QT_MOC_LITERAL(6, 47, 1), // "c"
QT_MOC_LITERAL(7, 49, 12), // "SetLineWidth"
QT_MOC_LITERAL(8, 62, 5), // "width"
QT_MOC_LITERAL(9, 68, 12), // "GetLineWidth"
QT_MOC_LITERAL(10, 81, 12), // "SetLineStyle"
QT_MOC_LITERAL(11, 94, 12), // "Qt::PenStyle"
QT_MOC_LITERAL(12, 107, 5), // "style"
QT_MOC_LITERAL(13, 113, 12), // "GetLineStyle"
QT_MOC_LITERAL(14, 126, 12), // "SetLineColor"
QT_MOC_LITERAL(15, 139, 5), // "color"
QT_MOC_LITERAL(16, 145, 12), // "GetLineColor"
QT_MOC_LITERAL(17, 158, 5), // "Brush"
QT_MOC_LITERAL(18, 164, 12), // "SetFillColor"
QT_MOC_LITERAL(19, 177, 12) // "GetFillColor"

    },
    "CGraphicsTextData\0SetFont\0\0f\0Font\0"
    "SetTextColor\0c\0SetLineWidth\0width\0"
    "GetLineWidth\0SetLineStyle\0Qt::PenStyle\0"
    "style\0GetLineStyle\0SetLineColor\0color\0"
    "GetLineColor\0Brush\0SetFillColor\0"
    "GetFillColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGraphicsTextData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    0,   77,    2, 0x0a /* Public */,
       5,    1,   78,    2, 0x0a /* Public */,
       7,    1,   81,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    1,   89,    2, 0x0a /* Public */,
      16,    0,   92,    2, 0x0a /* Public */,
      17,    0,   93,    2, 0x0a /* Public */,
      18,    1,   94,    2, 0x0a /* Public */,
      19,    0,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QFont,    3,
    QMetaType::QFont,
    QMetaType::Void, QMetaType::QColor,    6,
    QMetaType::Void, QMetaType::QReal,    8,
    QMetaType::QReal,
    QMetaType::Void, 0x80000000 | 11,   12,
    0x80000000 | 11,
    QMetaType::Void, QMetaType::QColor,   15,
    QMetaType::QColor,
    QMetaType::QBrush,
    QMetaType::Void, QMetaType::QColor,   15,
    QMetaType::QColor,

       0        // eod
};

void CGraphicsTextData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGraphicsTextData *_t = static_cast<CGraphicsTextData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 1: { QFont _r = _t->Font();
            if (_a[0]) *reinterpret_cast< QFont*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->SetTextColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->SetLineWidth((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 4: { qreal _r = _t->GetLineWidth();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->SetLineStyle((*reinterpret_cast< Qt::PenStyle(*)>(_a[1]))); break;
        case 6: { Qt::PenStyle _r = _t->GetLineStyle();
            if (_a[0]) *reinterpret_cast< Qt::PenStyle*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->SetLineColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 8: { QColor _r = _t->GetLineColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 9: { QBrush _r = _t->Brush();
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->SetFillColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 11: { QColor _r = _t->GetFillColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGraphicsTextData::staticMetaObject = {
    { &CTextData::staticMetaObject, qt_meta_stringdata_CGraphicsTextData.data,
      qt_meta_data_CGraphicsTextData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGraphicsTextData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGraphicsTextData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGraphicsTextData.stringdata0))
        return static_cast<void*>(this);
    return CTextData::qt_metacast(_clname);
}

int CGraphicsTextData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CTextData::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
struct qt_meta_stringdata_CAbstractScaleData_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAbstractScaleData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAbstractScaleData_t qt_meta_stringdata_CAbstractScaleData = {
    {
QT_MOC_LITERAL(0, 0, 18) // "CAbstractScaleData"

    },
    "CAbstractScaleData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAbstractScaleData[] = {

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

void CAbstractScaleData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CAbstractScaleData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CAbstractScaleData.data,
      qt_meta_data_CAbstractScaleData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CAbstractScaleData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAbstractScaleData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAbstractScaleData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CAbstractScaleData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CPixmapData_t {
    QByteArrayData data[11];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPixmapData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPixmapData_t qt_meta_stringdata_CPixmapData = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CPixmapData"
QT_MOC_LITERAL(1, 12, 4), // "Load"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "fileName"
QT_MOC_LITERAL(4, 27, 12), // "LoadFromData"
QT_MOC_LITERAL(5, 40, 4), // "data"
QT_MOC_LITERAL(6, 45, 6), // "format"
QT_MOC_LITERAL(7, 52, 5), // "flags"
QT_MOC_LITERAL(8, 58, 11), // "GetFileName"
QT_MOC_LITERAL(9, 70, 12), // "movieUpdated"
QT_MOC_LITERAL(10, 83, 4) // "area"

    },
    "CPixmapData\0Load\0\0fileName\0LoadFromData\0"
    "data\0format\0flags\0GetFileName\0"
    "movieUpdated\0area"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPixmapData[] = {

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
       1,    1,   44,    2, 0x0a /* Public */,
       4,    3,   47,    2, 0x0a /* Public */,
       4,    2,   54,    2, 0x2a /* Public | MethodCloned */,
       4,    1,   59,    2, 0x2a /* Public | MethodCloned */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    5,    6,    7,
    QMetaType::Bool, QMetaType::QVariant, QMetaType::QString,    5,    6,
    QMetaType::Bool, QMetaType::QVariant,    5,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QRect,   10,

       0        // eod
};

void CPixmapData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPixmapData *_t = static_cast<CPixmapData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->Load((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->LoadFromData((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->LoadFromData((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->LoadFromData((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->GetFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->movieUpdated((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CPixmapData::staticMetaObject = {
    { &CAbstractScaleData::staticMetaObject, qt_meta_stringdata_CPixmapData.data,
      qt_meta_data_CPixmapData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CPixmapData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPixmapData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPixmapData.stringdata0))
        return static_cast<void*>(this);
    return CAbstractScaleData::qt_metacast(_clname);
}

int CPixmapData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CAbstractScaleData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CLinkLineData_t {
    QByteArrayData data[8];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLinkLineData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLinkLineData_t qt_meta_stringdata_CLinkLineData = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CLinkLineData"
QT_MOC_LITERAL(1, 14, 14), // "SetRunningFlag"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "value"
QT_MOC_LITERAL(4, 36, 8), // "GetNodes"
QT_MOC_LITERAL(5, 45, 11), // "QObjectList"
QT_MOC_LITERAL(6, 57, 3), // "pid"
QT_MOC_LITERAL(7, 61, 11) // "GetLinkInfo"

    },
    "CLinkLineData\0SetRunningFlag\0\0value\0"
    "GetNodes\0QObjectList\0pid\0GetLinkInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLinkLineData[] = {

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
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       4,    0,   40,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    0x80000000 | 5, QMetaType::QString,    6,
    0x80000000 | 5,
    QMetaType::QStringList,

       0        // eod
};

void CLinkLineData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CLinkLineData *_t = static_cast<CLinkLineData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SetRunningFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { QObjectList _r = _t->GetNodes((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 2: { QObjectList _r = _t->GetNodes();
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 3: { QStringList _r = _t->GetLinkInfo();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CLinkLineData::staticMetaObject = {
    { &CPolygonData::staticMetaObject, qt_meta_stringdata_CLinkLineData.data,
      qt_meta_data_CLinkLineData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CLinkLineData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLinkLineData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLinkLineData.stringdata0))
        return static_cast<void*>(this);
    return CPolygonData::qt_metacast(_clname);
}

int CLinkLineData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CPolygonData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CPinData_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPinData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPinData_t qt_meta_stringdata_CPinData = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CPinData"
QT_MOC_LITERAL(1, 9, 12), // "GetLinkItems"
QT_MOC_LITERAL(2, 22, 11), // "QObjectList"
QT_MOC_LITERAL(3, 34, 0) // ""

    },
    "CPinData\0GetLinkItems\0QObjectList\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPinData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,

       0        // eod
};

void CPinData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPinData *_t = static_cast<CPinData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QObjectList _r = _t->GetLinkItems();
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CPinData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CPinData.data,
      qt_meta_data_CPinData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CPinData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPinData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPinData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CPinData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CBusData_t {
    QByteArrayData data[12];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CBusData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CBusData_t qt_meta_stringdata_CBusData = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CBusData"
QT_MOC_LITERAL(1, 9, 6), // "Points"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 9), // "SetPoints"
QT_MOC_LITERAL(4, 27, 4), // "line"
QT_MOC_LITERAL(5, 32, 9), // "fillColor"
QT_MOC_LITERAL(6, 42, 9), // "lineColor"
QT_MOC_LITERAL(7, 52, 9), // "lineWidth"
QT_MOC_LITERAL(8, 62, 9), // "lineStyle"
QT_MOC_LITERAL(9, 72, 12), // "Qt::PenStyle"
QT_MOC_LITERAL(10, 85, 8), // "fillMode"
QT_MOC_LITERAL(11, 94, 14) // "Qt::BrushStyle"

    },
    "CBusData\0Points\0\0SetPoints\0line\0"
    "fillColor\0lineColor\0lineWidth\0lineStyle\0"
    "Qt::PenStyle\0fillMode\0Qt::BrushStyle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CBusData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       5,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QVariantList,
    QMetaType::Void, QMetaType::QVariantList,    4,

 // properties: name, type, flags
       5, QMetaType::QColor, 0x00095003,
       6, QMetaType::QColor, 0x00095003,
       7, QMetaType::QReal, 0x00095003,
       8, 0x80000000 | 9, 0x0009500b,
      10, 0x80000000 | 11, 0x0009500b,

       0        // eod
};

void CBusData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CBusData *_t = static_cast<CBusData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariantList _r = _t->Points();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SetPoints((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CBusData *_t = static_cast<CBusData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->GetFillColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->GetLineColor(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->GetLineWidth(); break;
        case 3: *reinterpret_cast< Qt::PenStyle*>(_v) = _t->GetLineStyle(); break;
        case 4: *reinterpret_cast< Qt::BrushStyle*>(_v) = _t->GetFillStyle(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        CBusData *_t = static_cast<CBusData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->SetFillColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->SetLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->SetLineWidth(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->SetLineStyle(*reinterpret_cast< Qt::PenStyle*>(_v)); break;
        case 4: _t->SetFillStyle(*reinterpret_cast< Qt::BrushStyle*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CBusData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CBusData.data,
      qt_meta_data_CBusData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CBusData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CBusData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CBusData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CBusData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
