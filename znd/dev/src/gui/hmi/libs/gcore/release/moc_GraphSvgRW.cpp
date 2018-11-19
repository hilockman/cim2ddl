/****************************************************************************
** Meta object code from reading C++ file 'GraphSvgRW.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GraphSvgRW.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphSvgRW.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGraphSvgReader_t {
    QByteArrayData data[12];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGraphSvgReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGraphSvgReader_t qt_meta_stringdata_CGraphSvgReader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CGraphSvgReader"
QT_MOC_LITERAL(1, 16, 4), // "Open"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "absPathFile"
QT_MOC_LITERAL(4, 34, 20), // "ReadNextStartElement"
QT_MOC_LITERAL(5, 55, 13), // "ReadAttribute"
QT_MOC_LITERAL(6, 69, 13), // "qualifiedName"
QT_MOC_LITERAL(7, 83, 14), // "ReadAttributes"
QT_MOC_LITERAL(8, 98, 12), // "namespaceUri"
QT_MOC_LITERAL(9, 111, 4), // "Name"
QT_MOC_LITERAL(10, 116, 18), // "SkipCurrentElement"
QT_MOC_LITERAL(11, 135, 15) // "ReadElementText"

    },
    "CGraphSvgReader\0Open\0\0absPathFile\0"
    "ReadNextStartElement\0ReadAttribute\0"
    "qualifiedName\0ReadAttributes\0namespaceUri\0"
    "Name\0SkipCurrentElement\0ReadElementText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGraphSvgReader[] = {

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
       1,    1,   49,    2, 0x0a /* Public */,
       4,    0,   52,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Int,
    QMetaType::QVariant, QMetaType::QString,    6,
    QMetaType::QVariantMap, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void CGraphSvgReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGraphSvgReader *_t = static_cast<CGraphSvgReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->Open((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->ReadNextStartElement();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariant _r = _t->ReadAttribute((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 3: { QVariantMap _r = _t->ReadAttributes((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->Name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->SkipCurrentElement(); break;
        case 6: { QString _r = _t->ReadElementText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGraphSvgReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CGraphSvgReader.data,
      qt_meta_data_CGraphSvgReader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGraphSvgReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGraphSvgReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGraphSvgReader.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QXmlStreamReader"))
        return static_cast< QXmlStreamReader*>(this);
    return QObject::qt_metacast(_clname);
}

int CGraphSvgReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_CGraphSvgWriter_t {
    QByteArrayData data[21];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGraphSvgWriter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGraphSvgWriter_t qt_meta_stringdata_CGraphSvgWriter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CGraphSvgWriter"
QT_MOC_LITERAL(1, 16, 4), // "Open"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "absPathFile"
QT_MOC_LITERAL(4, 34, 18), // "WriteStartDocument"
QT_MOC_LITERAL(5, 53, 7), // "version"
QT_MOC_LITERAL(6, 61, 10), // "standalone"
QT_MOC_LITERAL(7, 72, 16), // "WriteEndDocument"
QT_MOC_LITERAL(8, 89, 17), // "WriteStartElement"
QT_MOC_LITERAL(9, 107, 13), // "qualifiedName"
QT_MOC_LITERAL(10, 121, 15), // "WriteEndElement"
QT_MOC_LITERAL(11, 137, 14), // "WriteNamespace"
QT_MOC_LITERAL(12, 152, 12), // "namespaceUri"
QT_MOC_LITERAL(13, 165, 6), // "prefix"
QT_MOC_LITERAL(14, 172, 14), // "WriteAttribute"
QT_MOC_LITERAL(15, 187, 8), // "AttrName"
QT_MOC_LITERAL(16, 196, 7), // "variant"
QT_MOC_LITERAL(17, 204, 13), // "Hmi::SaveType"
QT_MOC_LITERAL(18, 218, 4), // "type"
QT_MOC_LITERAL(19, 223, 15), // "WriteCharacters"
QT_MOC_LITERAL(20, 239, 4) // "text"

    },
    "CGraphSvgWriter\0Open\0\0absPathFile\0"
    "WriteStartDocument\0version\0standalone\0"
    "WriteEndDocument\0WriteStartElement\0"
    "qualifiedName\0WriteEndElement\0"
    "WriteNamespace\0namespaceUri\0prefix\0"
    "WriteAttribute\0AttrName\0variant\0"
    "Hmi::SaveType\0type\0WriteCharacters\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGraphSvgWriter[] = {

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
       4,    2,   77,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   85,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   86,    2, 0x0a /* Public */,
       8,    1,   87,    2, 0x0a /* Public */,
      10,    0,   90,    2, 0x0a /* Public */,
      11,    2,   91,    2, 0x0a /* Public */,
      11,    1,   96,    2, 0x2a /* Public | MethodCloned */,
      14,    3,   99,    2, 0x0a /* Public */,
      14,    2,  106,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  111,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, 0x80000000 | 17,   15,   16,   18,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString,   20,

       0        // eod
};

void CGraphSvgWriter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGraphSvgWriter *_t = static_cast<CGraphSvgWriter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->Open((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->WriteStartDocument((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->WriteStartDocument((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->WriteStartDocument(); break;
        case 4: _t->WriteEndDocument(); break;
        case 5: _t->WriteStartElement((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->WriteEndElement(); break;
        case 7: _t->WriteNamespace((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->WriteNamespace((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: { int _r = _t->WriteAttribute((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< Hmi::SaveType(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->WriteAttribute((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->WriteCharacters((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGraphSvgWriter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CGraphSvgWriter.data,
      qt_meta_data_CGraphSvgWriter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGraphSvgWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGraphSvgWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGraphSvgWriter.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QXmlStreamWriter"))
        return static_cast< QXmlStreamWriter*>(this);
    return QObject::qt_metacast(_clname);
}

int CGraphSvgWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
