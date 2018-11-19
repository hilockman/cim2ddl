/****************************************************************************
** Meta object code from reading C++ file 'GraphView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GraphView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGTimer_t {
    QByteArrayData data[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGTimer_t qt_meta_stringdata_CGTimer = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CGTimer"
QT_MOC_LITERAL(1, 8, 7) // "timerId"

    },
    "CGTimer\0timerId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGTimer[] = {

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

void CGTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        CGTimer *_t = static_cast<CGTimer *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject CGTimer::staticMetaObject = {
    { &QTimer::staticMetaObject, qt_meta_stringdata_CGTimer.data,
      qt_meta_data_CGTimer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGTimer.stringdata0))
        return static_cast<void*>(this);
    return QTimer::qt_metacast(_clname);
}

int CGTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_CGraphView_t {
    QByteArrayData data[134];
    char stringdata0[1264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGraphView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGraphView_t qt_meta_stringdata_CGraphView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CGraphView"
QT_MOC_LITERAL(1, 11, 11), // "CustomEvent"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "signal"
QT_MOC_LITERAL(4, 31, 5), // "value"
QT_MOC_LITERAL(5, 37, 10), // "ItemChange"
QT_MOC_LITERAL(6, 48, 9), // "DropEvent"
QT_MOC_LITERAL(7, 58, 6), // "curobj"
QT_MOC_LITERAL(8, 65, 8), // "obj_info"
QT_MOC_LITERAL(9, 74, 9), // "MatrixChg"
QT_MOC_LITERAL(10, 84, 5), // "scale"
QT_MOC_LITERAL(11, 90, 2), // "dx"
QT_MOC_LITERAL(12, 93, 2), // "dy"
QT_MOC_LITERAL(13, 96, 7), // "Resized"
QT_MOC_LITERAL(14, 104, 1), // "w"
QT_MOC_LITERAL(15, 106, 1), // "h"
QT_MOC_LITERAL(16, 108, 13), // "DoubleClicked"
QT_MOC_LITERAL(17, 122, 11), // "LeftClicked"
QT_MOC_LITERAL(18, 134, 11), // "QObjectList"
QT_MOC_LITERAL(19, 146, 4), // "olst"
QT_MOC_LITERAL(20, 151, 13), // "FocusOutEvent"
QT_MOC_LITERAL(21, 165, 8), // "TipEvent"
QT_MOC_LITERAL(22, 174, 3), // "obj"
QT_MOC_LITERAL(23, 178, 10), // "MouseEvent"
QT_MOC_LITERAL(24, 189, 4), // "info"
QT_MOC_LITERAL(25, 194, 12), // "MouseRelease"
QT_MOC_LITERAL(26, 207, 18), // "ContextMenuClicked"
QT_MOC_LITERAL(27, 226, 8), // "menu_txt"
QT_MOC_LITERAL(28, 235, 8), // "act_info"
QT_MOC_LITERAL(29, 244, 4), // "Emit"
QT_MOC_LITERAL(30, 249, 10), // "SetToolTip"
QT_MOC_LITERAL(31, 260, 3), // "tip"
QT_MOC_LITERAL(32, 264, 11), // "SetGeometry"
QT_MOC_LITERAL(33, 276, 1), // "x"
QT_MOC_LITERAL(34, 278, 1), // "y"
QT_MOC_LITERAL(35, 280, 16), // "PopupContextMenu"
QT_MOC_LITERAL(36, 297, 8), // "menuinfo"
QT_MOC_LITERAL(37, 306, 6), // "QMenu&"
QT_MOC_LITERAL(38, 313, 11), // "contextMenu"
QT_MOC_LITERAL(39, 325, 5), // "Model"
QT_MOC_LITERAL(40, 331, 9), // "FitInView"
QT_MOC_LITERAL(41, 341, 4), // "rect"
QT_MOC_LITERAL(42, 346, 19), // "Qt::AspectRatioMode"
QT_MOC_LITERAL(43, 366, 15), // "aspectRadioMode"
QT_MOC_LITERAL(44, 382, 12), // "GetFitInMode"
QT_MOC_LITERAL(45, 395, 4), // "Self"
QT_MOC_LITERAL(46, 400, 11), // "CurrentFile"
QT_MOC_LITERAL(47, 412, 11), // "is_abs_path"
QT_MOC_LITERAL(48, 424, 11), // "GetWndAlais"
QT_MOC_LITERAL(49, 436, 11), // "SetWndAlais"
QT_MOC_LITERAL(50, 448, 5), // "alais"
QT_MOC_LITERAL(51, 454, 5), // "Scale"
QT_MOC_LITERAL(52, 460, 2), // "sx"
QT_MOC_LITERAL(53, 463, 2), // "sy"
QT_MOC_LITERAL(54, 466, 5), // "Shear"
QT_MOC_LITERAL(55, 472, 2), // "sz"
QT_MOC_LITERAL(56, 475, 6), // "Rotate"
QT_MOC_LITERAL(57, 482, 5), // "angle"
QT_MOC_LITERAL(58, 488, 9), // "Translate"
QT_MOC_LITERAL(59, 498, 11), // "ResetMatrix"
QT_MOC_LITERAL(60, 510, 12), // "SetShowPlane"
QT_MOC_LITERAL(61, 523, 11), // "show_planes"
QT_MOC_LITERAL(62, 535, 7), // "refresh"
QT_MOC_LITERAL(63, 543, 18), // "SetShowPlaneIndexs"
QT_MOC_LITERAL(64, 562, 11), // "show_indexs"
QT_MOC_LITERAL(65, 574, 12), // "GetShowPlane"
QT_MOC_LITERAL(66, 587, 10), // "LoadScript"
QT_MOC_LITERAL(67, 598, 2), // "fn"
QT_MOC_LITERAL(68, 601, 9), // "AddPixmap"
QT_MOC_LITERAL(69, 611, 7), // "objName"
QT_MOC_LITERAL(70, 619, 7), // "pixName"
QT_MOC_LITERAL(71, 627, 8), // "userData"
QT_MOC_LITERAL(72, 636, 10), // "AddPolygon"
QT_MOC_LITERAL(73, 647, 6), // "points"
QT_MOC_LITERAL(74, 654, 7), // "AddText"
QT_MOC_LITERAL(75, 662, 4), // "text"
QT_MOC_LITERAL(76, 667, 7), // "AddItem"
QT_MOC_LITERAL(77, 675, 7), // "jsonobj"
QT_MOC_LITERAL(78, 683, 6), // "parent"
QT_MOC_LITERAL(79, 690, 10), // "AddItemObj"
QT_MOC_LITERAL(80, 701, 7), // "dataPtr"
QT_MOC_LITERAL(81, 709, 10), // "RemoveItem"
QT_MOC_LITERAL(82, 720, 3), // "Set"
QT_MOC_LITERAL(83, 724, 3), // "key"
QT_MOC_LITERAL(84, 728, 3), // "Get"
QT_MOC_LITERAL(85, 732, 5), // "DoCmd"
QT_MOC_LITERAL(86, 738, 11), // "script_code"
QT_MOC_LITERAL(87, 750, 5), // "Items"
QT_MOC_LITERAL(88, 756, 8), // "selector"
QT_MOC_LITERAL(89, 765, 9), // "ifTopItem"
QT_MOC_LITERAL(90, 775, 13), // "SelectedItems"
QT_MOC_LITERAL(91, 789, 15), // "QList<QObject*>"
QT_MOC_LITERAL(92, 805, 10), // "ifSelected"
QT_MOC_LITERAL(93, 816, 5), // "order"
QT_MOC_LITERAL(94, 822, 22), // "SetCurrentItemProperty"
QT_MOC_LITERAL(95, 845, 8), // "propname"
QT_MOC_LITERAL(96, 854, 22), // "GetCurrentItemProperty"
QT_MOC_LITERAL(97, 877, 11), // "EnableDebug"
QT_MOC_LITERAL(98, 889, 6), // "enable"
QT_MOC_LITERAL(99, 896, 15), // "GetScriptEngine"
QT_MOC_LITERAL(100, 912, 10), // "GetElement"
QT_MOC_LITERAL(101, 923, 2), // "id"
QT_MOC_LITERAL(102, 926, 20), // "GetElementByScriptId"
QT_MOC_LITERAL(103, 947, 12), // "QScriptValue"
QT_MOC_LITERAL(104, 960, 14), // "GetElementById"
QT_MOC_LITERAL(105, 975, 16), // "FindItemPtrByKey"
QT_MOC_LITERAL(106, 992, 8), // "CenterOn"
QT_MOC_LITERAL(107, 1001, 8), // "itemName"
QT_MOC_LITERAL(108, 1010, 15), // "CreateAnimation"
QT_MOC_LITERAL(109, 1026, 6), // "target"
QT_MOC_LITERAL(110, 1033, 12), // "propertyName"
QT_MOC_LITERAL(111, 1046, 8), // "startval"
QT_MOC_LITERAL(112, 1055, 6), // "endval"
QT_MOC_LITERAL(113, 1062, 8), // "duration"
QT_MOC_LITERAL(114, 1071, 4), // "loop"
QT_MOC_LITERAL(115, 1076, 18), // "SetBackgroundImage"
QT_MOC_LITERAL(116, 1095, 9), // "imageName"
QT_MOC_LITERAL(117, 1105, 4), // "mode"
QT_MOC_LITERAL(118, 1110, 6), // "onView"
QT_MOC_LITERAL(119, 1117, 18), // "SetBackgroundColor"
QT_MOC_LITERAL(120, 1136, 5), // "color"
QT_MOC_LITERAL(121, 1142, 9), // "StartDrag"
QT_MOC_LITERAL(122, 1152, 3), // "msg"
QT_MOC_LITERAL(123, 1156, 13), // "EmitMatrixChg"
QT_MOC_LITERAL(124, 1170, 15), // "CustomPropertys"
QT_MOC_LITERAL(125, 1186, 11), // "SetProperty"
QT_MOC_LITERAL(126, 1198, 8), // "Property"
QT_MOC_LITERAL(127, 1207, 4), // "name"
QT_MOC_LITERAL(128, 1212, 7), // "allprop"
QT_MOC_LITERAL(129, 1220, 9), // "GetScript"
QT_MOC_LITERAL(130, 1230, 6), // "Create"
QT_MOC_LITERAL(131, 1237, 7), // "objname"
QT_MOC_LITERAL(132, 1245, 4), // "args"
QT_MOC_LITERAL(133, 1250, 13) // "OnContextMenu"

    },
    "CGraphView\0CustomEvent\0\0signal\0value\0"
    "ItemChange\0DropEvent\0curobj\0obj_info\0"
    "MatrixChg\0scale\0dx\0dy\0Resized\0w\0h\0"
    "DoubleClicked\0LeftClicked\0QObjectList\0"
    "olst\0FocusOutEvent\0TipEvent\0obj\0"
    "MouseEvent\0info\0MouseRelease\0"
    "ContextMenuClicked\0menu_txt\0act_info\0"
    "Emit\0SetToolTip\0tip\0SetGeometry\0x\0y\0"
    "PopupContextMenu\0menuinfo\0QMenu&\0"
    "contextMenu\0Model\0FitInView\0rect\0"
    "Qt::AspectRatioMode\0aspectRadioMode\0"
    "GetFitInMode\0Self\0CurrentFile\0is_abs_path\0"
    "GetWndAlais\0SetWndAlais\0alais\0Scale\0"
    "sx\0sy\0Shear\0sz\0Rotate\0angle\0Translate\0"
    "ResetMatrix\0SetShowPlane\0show_planes\0"
    "refresh\0SetShowPlaneIndexs\0show_indexs\0"
    "GetShowPlane\0LoadScript\0fn\0AddPixmap\0"
    "objName\0pixName\0userData\0AddPolygon\0"
    "points\0AddText\0text\0AddItem\0jsonobj\0"
    "parent\0AddItemObj\0dataPtr\0RemoveItem\0"
    "Set\0key\0Get\0DoCmd\0script_code\0Items\0"
    "selector\0ifTopItem\0SelectedItems\0"
    "QList<QObject*>\0ifSelected\0order\0"
    "SetCurrentItemProperty\0propname\0"
    "GetCurrentItemProperty\0EnableDebug\0"
    "enable\0GetScriptEngine\0GetElement\0id\0"
    "GetElementByScriptId\0QScriptValue\0"
    "GetElementById\0FindItemPtrByKey\0"
    "CenterOn\0itemName\0CreateAnimation\0"
    "target\0propertyName\0startval\0endval\0"
    "duration\0loop\0SetBackgroundImage\0"
    "imageName\0mode\0onView\0SetBackgroundColor\0"
    "color\0StartDrag\0msg\0EmitMatrixChg\0"
    "CustomPropertys\0SetProperty\0Property\0"
    "name\0allprop\0GetScript\0Create\0objname\0"
    "args\0OnContextMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGraphView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      90,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  464,    2, 0x06 /* Public */,
       5,    2,  469,    2, 0x06 /* Public */,
       6,    2,  474,    2, 0x06 /* Public */,
       9,    3,  479,    2, 0x06 /* Public */,
      13,    2,  486,    2, 0x06 /* Public */,
      16,    2,  491,    2, 0x06 /* Public */,
      17,    3,  496,    2, 0x06 /* Public */,
      20,    0,  503,    2, 0x06 /* Public */,
      21,    2,  504,    2, 0x06 /* Public */,
      23,    2,  509,    2, 0x06 /* Public */,
      25,    0,  514,    2, 0x06 /* Public */,
      26,    2,  515,    2, 0x06 /* Public */,
      26,    1,  520,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      29,    2,  523,    2, 0x0a /* Public */,
      30,    1,  528,    2, 0x0a /* Public */,
      32,    4,  531,    2, 0x0a /* Public */,
      35,    2,  540,    2, 0x0a /* Public */,
      39,    0,  545,    2, 0x0a /* Public */,
      40,    2,  546,    2, 0x0a /* Public */,
      40,    1,  551,    2, 0x2a /* Public | MethodCloned */,
      44,    0,  554,    2, 0x0a /* Public */,
      45,    0,  555,    2, 0x0a /* Public */,
      46,    1,  556,    2, 0x0a /* Public */,
      46,    0,  559,    2, 0x2a /* Public | MethodCloned */,
      48,    0,  560,    2, 0x0a /* Public */,
      49,    1,  561,    2, 0x0a /* Public */,
      51,    2,  564,    2, 0x0a /* Public */,
      51,    0,  569,    2, 0x0a /* Public */,
      54,    3,  570,    2, 0x0a /* Public */,
      56,    1,  577,    2, 0x0a /* Public */,
      58,    2,  580,    2, 0x0a /* Public */,
      59,    0,  585,    2, 0x0a /* Public */,
      60,    2,  586,    2, 0x0a /* Public */,
      60,    1,  591,    2, 0x2a /* Public | MethodCloned */,
      63,    2,  594,    2, 0x0a /* Public */,
      63,    1,  599,    2, 0x2a /* Public | MethodCloned */,
      65,    0,  602,    2, 0x0a /* Public */,
      66,    1,  603,    2, 0x0a /* Public */,
      68,    5,  606,    2, 0x0a /* Public */,
      68,    4,  617,    2, 0x2a /* Public | MethodCloned */,
      72,    3,  626,    2, 0x0a /* Public */,
      72,    2,  633,    2, 0x2a /* Public | MethodCloned */,
      74,    5,  638,    2, 0x0a /* Public */,
      74,    4,  649,    2, 0x2a /* Public | MethodCloned */,
      76,    4,  658,    2, 0x0a /* Public */,
      76,    3,  667,    2, 0x2a /* Public | MethodCloned */,
      76,    2,  674,    2, 0x2a /* Public | MethodCloned */,
      76,    1,  679,    2, 0x2a /* Public | MethodCloned */,
      79,    1,  682,    2, 0x0a /* Public */,
      81,    1,  685,    2, 0x0a /* Public */,
      82,    2,  688,    2, 0x0a /* Public */,
      84,    1,  693,    2, 0x0a /* Public */,
      85,    1,  696,    2, 0x0a /* Public */,
      87,    3,  699,    2, 0x0a /* Public */,
      87,    2,  706,    2, 0x2a /* Public | MethodCloned */,
      87,    1,  711,    2, 0x2a /* Public | MethodCloned */,
      90,    0,  714,    2, 0x0a /* Public */,
      87,    3,  715,    2, 0x0a /* Public */,
      87,    2,  722,    2, 0x2a /* Public | MethodCloned */,
      87,    1,  727,    2, 0x2a /* Public | MethodCloned */,
      87,    0,  730,    2, 0x2a /* Public | MethodCloned */,
      94,    2,  731,    2, 0x0a /* Public */,
      96,    1,  736,    2, 0x0a /* Public */,
      97,    1,  739,    2, 0x0a /* Public */,
      99,    0,  742,    2, 0x0a /* Public */,
     100,    1,  743,    2, 0x0a /* Public */,
     102,    1,  746,    2, 0x0a /* Public */,
     104,    1,  749,    2, 0x0a /* Public */,
     105,    1,  752,    2, 0x0a /* Public */,
     106,    1,  755,    2, 0x0a /* Public */,
     108,    6,  758,    2, 0x0a /* Public */,
     108,    5,  771,    2, 0x2a /* Public | MethodCloned */,
     108,    4,  782,    2, 0x2a /* Public | MethodCloned */,
     108,    3,  791,    2, 0x2a /* Public | MethodCloned */,
     108,    2,  798,    2, 0x2a /* Public | MethodCloned */,
     115,    3,  803,    2, 0x0a /* Public */,
     115,    2,  810,    2, 0x2a /* Public | MethodCloned */,
     115,    1,  815,    2, 0x2a /* Public | MethodCloned */,
     119,    1,  818,    2, 0x0a /* Public */,
     121,    2,  821,    2, 0x0a /* Public */,
     123,    1,  826,    2, 0x0a /* Public */,
     123,    0,  829,    2, 0x2a /* Public | MethodCloned */,
     124,    0,  830,    2, 0x0a /* Public */,
     125,    2,  831,    2, 0x0a /* Public */,
     126,    2,  836,    2, 0x0a /* Public */,
     126,    1,  841,    2, 0x2a /* Public | MethodCloned */,
     129,    0,  844,    2, 0x0a /* Public */,
     130,    2,  845,    2, 0x0a /* Public */,
     130,    1,  850,    2, 0x2a /* Public | MethodCloned */,
     133,    0,  853,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::Float, QMetaType::Int, QMetaType::Int,   10,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QVariant, 0x80000000 | 18,    7,    8,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString,   22,    8,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QVariant,    7,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   27,   28,
    QMetaType::Void, QMetaType::QString,   27,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   33,   34,   14,   15,
    QMetaType::Void, QMetaType::QVariant, 0x80000000 | 37,   36,   38,
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::QRectF, 0x80000000 | 42,   41,   43,
    QMetaType::Void, QMetaType::QRectF,   41,
    QMetaType::Int,
    QMetaType::QObjectStar,
    QMetaType::QString, QMetaType::Bool,   47,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   52,   53,
    QMetaType::QReal,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   52,   53,   55,
    QMetaType::Void, QMetaType::Float,   57,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   61,   62,
    QMetaType::Void, QMetaType::QString,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   64,   62,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString, QMetaType::QReal, QMetaType::QReal, QMetaType::QString,   69,   70,   33,   34,   71,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString, QMetaType::QReal, QMetaType::QReal,   69,   70,   33,   34,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString, QMetaType::QString,   69,   73,   71,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString,   69,   73,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString,   69,   75,   33,   34,   71,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,   69,   75,   33,   34,
    QMetaType::QObjectStar, QMetaType::QVariantMap, QMetaType::Int, QMetaType::Int, QMetaType::QObjectStar,   77,   33,   34,   78,
    QMetaType::QObjectStar, QMetaType::QVariantMap, QMetaType::Int, QMetaType::Int,   77,   33,   34,
    QMetaType::QObjectStar, QMetaType::QVariantMap, QMetaType::Int,   77,   33,
    QMetaType::QObjectStar, QMetaType::QVariantMap,   77,
    QMetaType::Void, QMetaType::QObjectStar,   80,
    QMetaType::Void, QMetaType::QObjectStar,   80,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   83,    4,
    QMetaType::QString, QMetaType::QString,   83,
    QMetaType::QVariant, QMetaType::QString,   86,
    0x80000000 | 18, QMetaType::QString, QMetaType::QObjectStar, QMetaType::Bool,   88,   78,   89,
    0x80000000 | 18, QMetaType::QString, QMetaType::QObjectStar,   88,   78,
    0x80000000 | 18, QMetaType::QString,   88,
    0x80000000 | 91,
    0x80000000 | 18, QMetaType::Bool, QMetaType::Bool, QMetaType::Int,   89,   92,   93,
    0x80000000 | 18, QMetaType::Bool, QMetaType::Bool,   89,   92,
    0x80000000 | 18, QMetaType::Bool,   89,
    0x80000000 | 18,
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant,   95,    4,
    QMetaType::QVariant, QMetaType::QString,   95,
    QMetaType::Void, QMetaType::Bool,   98,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar, QMetaType::QString,  101,
    0x80000000 | 103, QMetaType::QString,  101,
    QMetaType::QObjectStar, QMetaType::QString,  101,
    0x80000000 | 18, QMetaType::QString,   83,
    QMetaType::QObjectStar, QMetaType::QString,  107,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant, QMetaType::Int, QMetaType::Int,  109,  110,  111,  112,  113,  114,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant, QMetaType::Int,  109,  110,  111,  112,  113,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant,  109,  110,  111,  112,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant,  109,  110,  111,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString,  109,  110,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,  116,  117,  118,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,  116,  117,
    QMetaType::Void, QMetaType::QString,  116,
    QMetaType::Void, QMetaType::QString,  120,
    QMetaType::Bool, QMetaType::QObjectStar, QMetaType::QString,   22,  122,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::QVariantMap,
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant,   95,    4,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Bool,  127,  128,
    QMetaType::QVariant, QMetaType::QString,  127,
    QMetaType::QString,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant,  131,  132,
    QMetaType::QObjectStar, QMetaType::QString,  131,
    QMetaType::Void,

       0        // eod
};

void CGraphView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGraphView *_t = static_cast<CGraphView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CustomEvent((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: _t->ItemChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 2: _t->DropEvent((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->MatrixChg((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->Resized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->DoubleClicked((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->LeftClicked((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QObjectList(*)>(_a[3]))); break;
        case 7: _t->FocusOutEvent(); break;
        case 8: _t->TipEvent((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->MouseEvent((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 10: _t->MouseRelease(); break;
        case 11: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 12: _t->ContextMenuClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->Emit((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 14: _t->SetToolTip((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->SetGeometry((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 16: _t->PopupContextMenu((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< QMenu(*)>(_a[2]))); break;
        case 17: { QObject* _r = _t->Model();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 18: _t->FitInView((*reinterpret_cast< const QRectF(*)>(_a[1])),(*reinterpret_cast< Qt::AspectRatioMode(*)>(_a[2]))); break;
        case 19: _t->FitInView((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 20: { int _r = _t->GetFitInMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { QObject* _r = _t->Self();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->CurrentFile((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->CurrentFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->GetWndAlais();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->SetWndAlais((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->Scale((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 27: { qreal _r = _t->Scale();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->Shear((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 29: _t->Rotate((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 30: _t->Translate((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 31: _t->ResetMatrix(); break;
        case 32: _t->SetShowPlane((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 33: _t->SetShowPlane((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->SetShowPlaneIndexs((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 35: _t->SetShowPlaneIndexs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 36: { QString _r = _t->GetShowPlane();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->LoadScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 38: { QObject* _r = _t->AddPixmap((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 39: { QObject* _r = _t->AddPixmap((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 40: { QObject* _r = _t->AddPolygon((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 41: { QObject* _r = _t->AddPolygon((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 42: { QObject* _r = _t->AddText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 43: { QObject* _r = _t->AddText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 44: { QObject* _r = _t->AddItem((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QObject*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 45: { QObject* _r = _t->AddItem((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 46: { QObject* _r = _t->AddItem((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 47: { QObject* _r = _t->AddItem((*reinterpret_cast< QVariantMap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 48: _t->AddItemObj((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 49: _t->RemoveItem((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 50: _t->Set((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 51: { QString _r = _t->Get((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 52: { QVariant _r = _t->DoCmd((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 53: { QObjectList _r = _t->Items((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 54: { QObjectList _r = _t->Items((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 55: { QObjectList _r = _t->Items((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 56: { QList<QObject*> _r = _t->SelectedItems();
            if (_a[0]) *reinterpret_cast< QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 57: { QObjectList _r = _t->Items((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 58: { QObjectList _r = _t->Items((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 59: { QObjectList _r = _t->Items((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 60: { QObjectList _r = _t->Items();
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 61: { bool _r = _t->SetCurrentItemProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 62: { QVariant _r = _t->GetCurrentItemProperty((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 63: _t->EnableDebug((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 64: { QObject* _r = _t->GetScriptEngine();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 65: { QObject* _r = _t->GetElement((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 66: { QScriptValue _r = _t->GetElementByScriptId((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = std::move(_r); }  break;
        case 67: { QObject* _r = _t->GetElementById((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 68: { QObjectList _r = _t->FindItemPtrByKey((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 69: { QObject* _r = _t->CenterOn((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 70: { QObject* _r = _t->CreateAnimation((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 71: { QObject* _r = _t->CreateAnimation((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 72: { QObject* _r = _t->CreateAnimation((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 73: { QObject* _r = _t->CreateAnimation((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 74: { QObject* _r = _t->CreateAnimation((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 75: _t->SetBackgroundImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 76: _t->SetBackgroundImage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 77: _t->SetBackgroundImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 78: _t->SetBackgroundColor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 79: { bool _r = _t->StartDrag((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 80: _t->EmitMatrixChg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->EmitMatrixChg(); break;
        case 82: { QVariantMap _r = _t->CustomPropertys();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 83: { bool _r = _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 84: { QVariant _r = _t->Property((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 85: { QVariant _r = _t->Property((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 86: { QString _r = _t->GetScript();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 87: { QObject* _r = _t->Create((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 88: { QObject* _r = _t->Create((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 89: _t->OnContextMenu(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGraphView::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::CustomEvent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::ItemChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(QObject * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::DropEvent)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(float , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::MatrixChg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::Resized)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(QObject * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::DoubleClicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(QObject * , QVariant , QObjectList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::LeftClicked)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::FocusOutEvent)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(QObject * , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::TipEvent)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(QObject * , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::MouseEvent)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::MouseRelease)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CGraphView::*)(QString , QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphView::ContextMenuClicked)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGraphView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_CGraphView.data,
      qt_meta_data_CGraphView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGraphView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGraphView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGraphView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int CGraphView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 90)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 90;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 90)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 90;
    }
    return _id;
}

// SIGNAL 0
void CGraphView::CustomEvent(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGraphView::ItemChange(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CGraphView::DropEvent(QObject * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CGraphView::MatrixChg(float _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CGraphView::Resized(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CGraphView::DoubleClicked(QObject * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CGraphView::LeftClicked(QObject * _t1, QVariant _t2, QObjectList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CGraphView::FocusOutEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void CGraphView::TipEvent(QObject * _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CGraphView::MouseEvent(QObject * _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CGraphView::MouseRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void CGraphView::ContextMenuClicked(QString _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
