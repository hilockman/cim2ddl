/****************************************************************************
** Meta object code from reading C++ file 'GChartItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GChartItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GChartItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGChartData_t {
    QByteArrayData data[12];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGChartData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGChartData_t qt_meta_stringdata_CGChartData = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CGChartData"
QT_MOC_LITERAL(1, 12, 6), // "AddTag"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "tagInfo"
QT_MOC_LITERAL(4, 28, 5), // "Chart"
QT_MOC_LITERAL(5, 34, 11), // "SetProperty"
QT_MOC_LITERAL(6, 46, 8), // "propname"
QT_MOC_LITERAL(7, 55, 5), // "value"
QT_MOC_LITERAL(8, 61, 8), // "Property"
QT_MOC_LITERAL(9, 70, 4), // "name"
QT_MOC_LITERAL(10, 75, 7), // "allprop"
QT_MOC_LITERAL(11, 83, 20) // "GetHistorySampleTime"

    },
    "CGChartData\0AddTag\0\0tagInfo\0Chart\0"
    "SetProperty\0propname\0value\0Property\0"
    "name\0allprop\0GetHistorySampleTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGChartData[] = {

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
       5,    2,   48,    2, 0x0a /* Public */,
       8,    2,   53,    2, 0x0a /* Public */,
       8,    1,   58,    2, 0x2a /* Public | MethodCloned */,
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::QObjectStar,
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant,    6,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Bool,    9,   10,
    QMetaType::QVariant, QMetaType::QString,    9,
    QMetaType::QVariant,

       0        // eod
};

void CGChartData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGChartData *_t = static_cast<CGChartData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddTag((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { QObject* _r = _t->Chart();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { QVariant _r = _t->Property((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVariant _r = _t->Property((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 5: { QVariant _r = _t->GetHistorySampleTime();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGChartData::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGChartData::AddTag)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGChartData::staticMetaObject = {
    { &CBaseData::staticMetaObject, qt_meta_stringdata_CGChartData.data,
      qt_meta_data_CGChartData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGChartData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGChartData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGChartData.stringdata0))
        return static_cast<void*>(this);
    return CBaseData::qt_metacast(_clname);
}

int CGChartData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CBaseData::qt_metacall(_c, _id, _a);
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
void CGChartData::AddTag(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CGChartItem_t {
    QByteArrayData data[97];
    char stringdata0[1012];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGChartItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGChartItem_t qt_meta_stringdata_CGChartItem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CGChartItem"
QT_MOC_LITERAL(1, 12, 14), // "TagsValChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "RemoveAllSeries"
QT_MOC_LITERAL(4, 44, 7), // "tagInfo"
QT_MOC_LITERAL(5, 52, 13), // "RemoveAllAxes"
QT_MOC_LITERAL(6, 66, 17), // "CreateDefaultAxes"
QT_MOC_LITERAL(7, 84, 6), // "Resize"
QT_MOC_LITERAL(8, 91, 1), // "w"
QT_MOC_LITERAL(9, 93, 1), // "h"
QT_MOC_LITERAL(10, 95, 10), // "SetMargins"
QT_MOC_LITERAL(11, 106, 4), // "left"
QT_MOC_LITERAL(12, 111, 3), // "top"
QT_MOC_LITERAL(13, 115, 5), // "right"
QT_MOC_LITERAL(14, 121, 6), // "bottom"
QT_MOC_LITERAL(15, 128, 13), // "PlotAreaWidth"
QT_MOC_LITERAL(16, 142, 6), // "Scroll"
QT_MOC_LITERAL(17, 149, 2), // "dx"
QT_MOC_LITERAL(18, 152, 2), // "dy"
QT_MOC_LITERAL(19, 155, 8), // "SetTheme"
QT_MOC_LITERAL(20, 164, 9), // "themeType"
QT_MOC_LITERAL(21, 174, 19), // "SetAnimationOptions"
QT_MOC_LITERAL(22, 194, 7), // "options"
QT_MOC_LITERAL(23, 202, 6), // "Legend"
QT_MOC_LITERAL(24, 209, 14), // "SetLegendAlign"
QT_MOC_LITERAL(25, 224, 9), // "alignment"
QT_MOC_LITERAL(26, 234, 6), // "ZoomIn"
QT_MOC_LITERAL(27, 241, 7), // "ZoomOut"
QT_MOC_LITERAL(28, 249, 1), // "x"
QT_MOC_LITERAL(29, 251, 1), // "y"
QT_MOC_LITERAL(30, 253, 5), // "width"
QT_MOC_LITERAL(31, 259, 6), // "height"
QT_MOC_LITERAL(32, 266, 4), // "Zoom"
QT_MOC_LITERAL(33, 271, 6), // "factor"
QT_MOC_LITERAL(34, 278, 9), // "ZoomReset"
QT_MOC_LITERAL(35, 288, 8), // "IsZoomed"
QT_MOC_LITERAL(36, 297, 9), // "AddSeries"
QT_MOC_LITERAL(37, 307, 10), // "seriesType"
QT_MOC_LITERAL(38, 318, 11), // "AppendPoint"
QT_MOC_LITERAL(39, 330, 9), // "seriesObj"
QT_MOC_LITERAL(40, 340, 6), // "adapeY"
QT_MOC_LITERAL(41, 347, 15), // "AppendTimePoint"
QT_MOC_LITERAL(42, 363, 7), // "timeStr"
QT_MOC_LITERAL(43, 371, 13), // "timeFormatStr"
QT_MOC_LITERAL(44, 385, 5), // "timeT"
QT_MOC_LITERAL(45, 391, 6), // "points"
QT_MOC_LITERAL(46, 398, 12), // "ExtremeValue"
QT_MOC_LITERAL(47, 411, 6), // "isShow"
QT_MOC_LITERAL(48, 418, 13), // "RemoveExtreme"
QT_MOC_LITERAL(49, 432, 14), // "AppendPieSlice"
QT_MOC_LITERAL(50, 447, 12), // "pieSeriesObj"
QT_MOC_LITERAL(51, 460, 5), // "label"
QT_MOC_LITERAL(52, 466, 5), // "value"
QT_MOC_LITERAL(53, 472, 12), // "AppendBarSet"
QT_MOC_LITERAL(54, 485, 12), // "barSeriesObj"
QT_MOC_LITERAL(55, 498, 6), // "values"
QT_MOC_LITERAL(56, 505, 16), // "SetXYSeriesColor"
QT_MOC_LITERAL(57, 522, 5), // "color"
QT_MOC_LITERAL(58, 528, 16), // "GetXYSeriesColor"
QT_MOC_LITERAL(59, 545, 11), // "SeriesClear"
QT_MOC_LITERAL(60, 557, 13), // "SetSeriesName"
QT_MOC_LITERAL(61, 571, 4), // "name"
QT_MOC_LITERAL(62, 576, 12), // "RomoveSeries"
QT_MOC_LITERAL(63, 589, 7), // "AddAxis"
QT_MOC_LITERAL(64, 597, 8), // "axisType"
QT_MOC_LITERAL(65, 606, 15), // "SetLinePenColor"
QT_MOC_LITERAL(66, 622, 7), // "axisObj"
QT_MOC_LITERAL(67, 630, 16), // "SetGridLineColor"
QT_MOC_LITERAL(68, 647, 10), // "AttachAxis"
QT_MOC_LITERAL(69, 658, 21), // "BarAxisAppendCategery"
QT_MOC_LITERAL(70, 680, 10), // "categories"
QT_MOC_LITERAL(71, 691, 18), // "CategoryAxisAppend"
QT_MOC_LITERAL(72, 710, 16), // "categoryEndValue"
QT_MOC_LITERAL(73, 727, 10), // "GetTagsVal"
QT_MOC_LITERAL(74, 738, 14), // "ReplaceTagInfo"
QT_MOC_LITERAL(75, 753, 10), // "oldTagName"
QT_MOC_LITERAL(76, 764, 7), // "tagName"
QT_MOC_LITERAL(77, 772, 10), // "GetAllTags"
QT_MOC_LITERAL(78, 783, 13), // "GetChartByTag"
QT_MOC_LITERAL(79, 797, 3), // "tag"
QT_MOC_LITERAL(80, 801, 12), // "GetChartData"
QT_MOC_LITERAL(81, 814, 14), // "GetBarSetCount"
QT_MOC_LITERAL(82, 829, 9), // "barSetObj"
QT_MOC_LITERAL(83, 839, 18), // "ReplaceBarSetValue"
QT_MOC_LITERAL(84, 858, 5), // "index"
QT_MOC_LITERAL(85, 864, 9), // "ShowCurve"
QT_MOC_LITERAL(86, 874, 9), // "showCurve"
QT_MOC_LITERAL(87, 884, 10), // "AxisYAdape"
QT_MOC_LITERAL(88, 895, 6), // "extend"
QT_MOC_LITERAL(89, 902, 16), // "OnTagsValChanged"
QT_MOC_LITERAL(90, 919, 19), // "HandleMarkerClicked"
QT_MOC_LITERAL(91, 939, 21), // "ShowPieSliceHighlight"
QT_MOC_LITERAL(92, 961, 14), // "ShowBarHovered"
QT_MOC_LITERAL(93, 976, 6), // "status"
QT_MOC_LITERAL(94, 983, 16), // "ShowCurveTooltip"
QT_MOC_LITERAL(95, 1000, 5), // "point"
QT_MOC_LITERAL(96, 1006, 5) // "state"

    },
    "CGChartItem\0TagsValChanged\0\0RemoveAllSeries\0"
    "tagInfo\0RemoveAllAxes\0CreateDefaultAxes\0"
    "Resize\0w\0h\0SetMargins\0left\0top\0right\0"
    "bottom\0PlotAreaWidth\0Scroll\0dx\0dy\0"
    "SetTheme\0themeType\0SetAnimationOptions\0"
    "options\0Legend\0SetLegendAlign\0alignment\0"
    "ZoomIn\0ZoomOut\0x\0y\0width\0height\0Zoom\0"
    "factor\0ZoomReset\0IsZoomed\0AddSeries\0"
    "seriesType\0AppendPoint\0seriesObj\0"
    "adapeY\0AppendTimePoint\0timeStr\0"
    "timeFormatStr\0timeT\0points\0ExtremeValue\0"
    "isShow\0RemoveExtreme\0AppendPieSlice\0"
    "pieSeriesObj\0label\0value\0AppendBarSet\0"
    "barSeriesObj\0values\0SetXYSeriesColor\0"
    "color\0GetXYSeriesColor\0SeriesClear\0"
    "SetSeriesName\0name\0RomoveSeries\0AddAxis\0"
    "axisType\0SetLinePenColor\0axisObj\0"
    "SetGridLineColor\0AttachAxis\0"
    "BarAxisAppendCategery\0categories\0"
    "CategoryAxisAppend\0categoryEndValue\0"
    "GetTagsVal\0ReplaceTagInfo\0oldTagName\0"
    "tagName\0GetAllTags\0GetChartByTag\0tag\0"
    "GetChartData\0GetBarSetCount\0barSetObj\0"
    "ReplaceBarSetValue\0index\0ShowCurve\0"
    "showCurve\0AxisYAdape\0extend\0"
    "OnTagsValChanged\0HandleMarkerClicked\0"
    "ShowPieSliceHighlight\0ShowBarHovered\0"
    "status\0ShowCurveTooltip\0point\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGChartItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  314,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  315,    2, 0x0a /* Public */,
       3,    0,  318,    2, 0x2a /* Public | MethodCloned */,
       5,    0,  319,    2, 0x0a /* Public */,
       6,    0,  320,    2, 0x0a /* Public */,
       7,    2,  321,    2, 0x0a /* Public */,
      10,    4,  326,    2, 0x0a /* Public */,
      15,    0,  335,    2, 0x0a /* Public */,
      16,    2,  336,    2, 0x0a /* Public */,
      19,    1,  341,    2, 0x0a /* Public */,
      21,    1,  344,    2, 0x0a /* Public */,
      23,    0,  347,    2, 0x0a /* Public */,
      24,    1,  348,    2, 0x0a /* Public */,
      26,    0,  351,    2, 0x0a /* Public */,
      27,    0,  352,    2, 0x0a /* Public */,
      26,    4,  353,    2, 0x0a /* Public */,
      32,    1,  362,    2, 0x0a /* Public */,
      34,    0,  365,    2, 0x0a /* Public */,
      35,    0,  366,    2, 0x0a /* Public */,
      36,    1,  367,    2, 0x0a /* Public */,
      38,    4,  370,    2, 0x0a /* Public */,
      38,    3,  379,    2, 0x2a /* Public | MethodCloned */,
      41,    5,  386,    2, 0x0a /* Public */,
      41,    4,  397,    2, 0x2a /* Public | MethodCloned */,
      41,    4,  406,    2, 0x0a /* Public */,
      41,    3,  415,    2, 0x2a /* Public | MethodCloned */,
      41,    2,  422,    2, 0x0a /* Public */,
      46,    1,  427,    2, 0x0a /* Public */,
      46,    0,  430,    2, 0x2a /* Public | MethodCloned */,
      48,    1,  431,    2, 0x0a /* Public */,
      48,    0,  434,    2, 0x2a /* Public | MethodCloned */,
      49,    3,  435,    2, 0x0a /* Public */,
      53,    3,  442,    2, 0x0a /* Public */,
      56,    2,  449,    2, 0x0a /* Public */,
      58,    1,  454,    2, 0x0a /* Public */,
      59,    1,  457,    2, 0x0a /* Public */,
      60,    2,  460,    2, 0x0a /* Public */,
      62,    1,  465,    2, 0x0a /* Public */,
      63,    2,  468,    2, 0x0a /* Public */,
      63,    1,  473,    2, 0x2a /* Public | MethodCloned */,
      65,    2,  476,    2, 0x0a /* Public */,
      67,    2,  481,    2, 0x0a /* Public */,
      68,    2,  486,    2, 0x0a /* Public */,
      69,    2,  491,    2, 0x0a /* Public */,
      71,    3,  496,    2, 0x0a /* Public */,
      73,    0,  503,    2, 0x0a /* Public */,
      74,    2,  504,    2, 0x0a /* Public */,
      77,    0,  509,    2, 0x0a /* Public */,
      78,    1,  510,    2, 0x0a /* Public */,
      80,    0,  513,    2, 0x0a /* Public */,
      81,    1,  514,    2, 0x0a /* Public */,
      83,    3,  517,    2, 0x0a /* Public */,
      85,    1,  524,    2, 0x0a /* Public */,
      87,    2,  527,    2, 0x0a /* Public */,
      87,    1,  532,    2, 0x2a /* Public | MethodCloned */,
      89,    0,  535,    2, 0x08 /* Private */,
      90,    0,  536,    2, 0x08 /* Private */,
      91,    1,  537,    2, 0x08 /* Private */,
      92,    2,  540,    2, 0x08 /* Private */,
      94,    2,  545,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,
    QMetaType::QReal,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal,   28,   29,   30,   31,
    QMetaType::Void, QMetaType::QReal,   33,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::QObjectStar, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QReal, QMetaType::QReal, QMetaType::Bool,   39,   28,   29,   40,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QReal, QMetaType::QReal,   39,   28,   29,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString, QMetaType::QReal, QMetaType::Bool,   39,   42,   43,   29,   40,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString, QMetaType::QReal,   39,   42,   43,   29,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::UInt, QMetaType::QReal, QMetaType::Bool,   39,   44,   29,   40,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::UInt, QMetaType::QReal,   39,   44,   29,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QVariantMap,   39,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QReal,   50,   51,   52,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QStringList,   54,   51,   55,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,   39,   57,
    QMetaType::QString, QMetaType::QObjectStar,   39,
    QMetaType::Void, QMetaType::QObjectStar,   39,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,   39,   61,
    QMetaType::Void, QMetaType::QObjectStar,   39,
    QMetaType::QObjectStar, QMetaType::Int, QMetaType::QString,   64,   25,
    QMetaType::QObjectStar, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,   66,   57,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,   66,   57,
    QMetaType::Bool, QMetaType::QObjectStar, QMetaType::QObjectStar,   39,   66,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QStringList,   66,   70,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QStringList, QMetaType::QStringList,   66,   70,   72,
    QMetaType::QVariant,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   75,   76,
    QMetaType::QStringList,
    QMetaType::QObjectStar, QMetaType::QString,   79,
    QMetaType::QObjectStar,
    QMetaType::Int, QMetaType::QObjectStar,   82,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::Int, QMetaType::QReal,   82,   84,   52,
    QMetaType::Void, QMetaType::Bool,   86,
    QMetaType::Void, QMetaType::QReal, QMetaType::Bool,   52,   88,
    QMetaType::Void, QMetaType::QReal,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   93,   84,
    QMetaType::Void, QMetaType::QPointF, QMetaType::Bool,   95,   96,

       0        // eod
};

void CGChartItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGChartItem *_t = static_cast<CGChartItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TagsValChanged(); break;
        case 1: _t->RemoveAllSeries((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->RemoveAllSeries(); break;
        case 3: _t->RemoveAllAxes(); break;
        case 4: _t->CreateDefaultAxes(); break;
        case 5: _t->Resize((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 6: _t->SetMargins((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: { qreal _r = _t->PlotAreaWidth();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->Scroll((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 9: _t->SetTheme((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->SetAnimationOptions((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: { QObject* _r = _t->Legend();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 12: _t->SetLegendAlign((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->ZoomIn(); break;
        case 14: _t->ZoomOut(); break;
        case 15: _t->ZoomIn((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 16: _t->Zoom((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 17: _t->ZoomReset(); break;
        case 18: { bool _r = _t->IsZoomed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { QObject* _r = _t->AddSeries((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 20: _t->AppendPoint((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 21: _t->AppendPoint((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 22: _t->AppendTimePoint((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 23: _t->AppendTimePoint((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 24: _t->AppendTimePoint((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 25: _t->AppendTimePoint((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 26: _t->AppendTimePoint((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 27: _t->ExtremeValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->ExtremeValue(); break;
        case 29: _t->RemoveExtreme((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 30: _t->RemoveExtreme(); break;
        case 31: { QObject* _r = _t->AppendPieSlice((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 32: { QObject* _r = _t->AppendBarSet((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 33: _t->SetXYSeriesColor((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 34: { QString _r = _t->GetXYSeriesColor((*reinterpret_cast< QObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 35: _t->SeriesClear((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 36: _t->SetSeriesName((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 37: _t->RomoveSeries((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 38: { QObject* _r = _t->AddAxis((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 39: { QObject* _r = _t->AddAxis((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 40: _t->SetLinePenColor((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 41: _t->SetGridLineColor((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 42: { bool _r = _t->AttachAxis((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 43: _t->BarAxisAppendCategery((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 44: _t->CategoryAxisAppend((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 45: { QVariant _r = _t->GetTagsVal();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 46: _t->ReplaceTagInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 47: { QStringList _r = _t->GetAllTags();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 48: { QObject* _r = _t->GetChartByTag((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 49: { QObject* _r = _t->GetChartData();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 50: { int _r = _t->GetBarSetCount((*reinterpret_cast< QObject*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->ReplaceBarSetValue((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 52: _t->ShowCurve((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->AxisYAdape((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 54: _t->AxisYAdape((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 55: _t->OnTagsValChanged(); break;
        case 56: _t->HandleMarkerClicked(); break;
        case 57: _t->ShowPieSliceHighlight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 58: _t->ShowBarHovered((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 59: _t->ShowCurveTooltip((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGChartItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGChartItem::TagsValChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGChartItem::staticMetaObject = {
    { &QChart::staticMetaObject, qt_meta_stringdata_CGChartItem.data,
      qt_meta_data_CGChartItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGChartItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGChartItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGChartItem.stringdata0))
        return static_cast<void*>(this);
    return QChart::qt_metacast(_clname);
}

int CGChartItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QChart::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 60)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 60;
    }
    return _id;
}

// SIGNAL 0
void CGChartItem::TagsValChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
