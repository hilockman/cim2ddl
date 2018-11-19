/****************************************************************************
** Meta object code from reading C++ file 'GraphScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GraphScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGraphScene_t {
    QByteArrayData data[139];
    char stringdata0[1643];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGraphScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGraphScene_t qt_meta_stringdata_CGraphScene = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CGraphScene"
QT_MOC_LITERAL(1, 12, 13), // "ItemBeCreated"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "item"
QT_MOC_LITERAL(4, 32, 5), // "Items"
QT_MOC_LITERAL(5, 38, 11), // "QObjectList"
QT_MOC_LITERAL(6, 50, 8), // "selector"
QT_MOC_LITERAL(7, 59, 6), // "parent"
QT_MOC_LITERAL(8, 66, 9), // "ifTopItem"
QT_MOC_LITERAL(9, 76, 12), // "GetBackColor"
QT_MOC_LITERAL(10, 89, 12), // "SetBackColor"
QT_MOC_LITERAL(11, 102, 10), // "back_color"
QT_MOC_LITERAL(12, 113, 12), // "GetForeColor"
QT_MOC_LITERAL(13, 126, 12), // "SetForeColor"
QT_MOC_LITERAL(14, 139, 10), // "fore_color"
QT_MOC_LITERAL(15, 150, 17), // "GetBackPixmapFlag"
QT_MOC_LITERAL(16, 168, 17), // "SetBackPixmapFlag"
QT_MOC_LITERAL(17, 186, 16), // "back_pixmap_flag"
QT_MOC_LITERAL(18, 203, 17), // "GetBackPixmapName"
QT_MOC_LITERAL(19, 221, 17), // "SetBackPixmapName"
QT_MOC_LITERAL(20, 239, 16), // "back_pixmap_name"
QT_MOC_LITERAL(21, 256, 16), // "GetPixmapShowWay"
QT_MOC_LITERAL(22, 273, 16), // "SetPixmapShowWay"
QT_MOC_LITERAL(23, 290, 5), // "value"
QT_MOC_LITERAL(24, 296, 18), // "GetRefreshInterval"
QT_MOC_LITERAL(25, 315, 18), // "SetRefreshInterval"
QT_MOC_LITERAL(26, 334, 11), // "refresh_itv"
QT_MOC_LITERAL(27, 346, 17), // "GetInitZoomFactor"
QT_MOC_LITERAL(28, 364, 17), // "SetInitZoomFactor"
QT_MOC_LITERAL(29, 382, 11), // "zoom_factor"
QT_MOC_LITERAL(30, 394, 13), // "GetGraphFacID"
QT_MOC_LITERAL(31, 408, 13), // "SetGraphFacID"
QT_MOC_LITERAL(32, 422, 6), // "fac_id"
QT_MOC_LITERAL(33, 429, 11), // "GetTopoFlag"
QT_MOC_LITERAL(34, 441, 11), // "SetTopoFlag"
QT_MOC_LITERAL(35, 453, 4), // "flag"
QT_MOC_LITERAL(36, 458, 11), // "GetWndTitle"
QT_MOC_LITERAL(37, 470, 11), // "SetWndTitle"
QT_MOC_LITERAL(38, 482, 5), // "title"
QT_MOC_LITERAL(39, 488, 13), // "GetStationApp"
QT_MOC_LITERAL(40, 502, 13), // "SetStationApp"
QT_MOC_LITERAL(41, 516, 11), // "station_app"
QT_MOC_LITERAL(42, 528, 13), // "SetLayoutRect"
QT_MOC_LITERAL(43, 542, 4), // "rect"
QT_MOC_LITERAL(44, 547, 13), // "GetLayoutRect"
QT_MOC_LITERAL(45, 561, 16), // "SetGraphShowMode"
QT_MOC_LITERAL(46, 578, 4), // "mode"
QT_MOC_LITERAL(47, 583, 13), // "GraphShowMode"
QT_MOC_LITERAL(48, 597, 14), // "WindowModality"
QT_MOC_LITERAL(49, 612, 17), // "SetWindowModality"
QT_MOC_LITERAL(50, 630, 14), // "SetEnableScale"
QT_MOC_LITERAL(51, 645, 6), // "enable"
QT_MOC_LITERAL(52, 652, 14), // "GetEnableScale"
QT_MOC_LITERAL(53, 667, 10), // "SetMovable"
QT_MOC_LITERAL(54, 678, 10), // "GetMovable"
QT_MOC_LITERAL(55, 689, 16), // "GetWindowOpacity"
QT_MOC_LITERAL(56, 706, 16), // "SetWindowOpacity"
QT_MOC_LITERAL(57, 723, 5), // "level"
QT_MOC_LITERAL(58, 729, 8), // "FileSave"
QT_MOC_LITERAL(59, 738, 8), // "fileName"
QT_MOC_LITERAL(60, 747, 8), // "isBinary"
QT_MOC_LITERAL(61, 756, 8), // "FileOpen"
QT_MOC_LITERAL(62, 765, 13), // "LoadJsonModel"
QT_MOC_LITERAL(63, 779, 7), // "jsonobj"
QT_MOC_LITERAL(64, 787, 12), // "GetJsonModel"
QT_MOC_LITERAL(65, 800, 12), // "UpdateLayout"
QT_MOC_LITERAL(66, 813, 8), // "IconSave"
QT_MOC_LITERAL(67, 822, 14), // "IconSaveToFile"
QT_MOC_LITERAL(68, 837, 10), // "CIconItem*"
QT_MOC_LITERAL(69, 848, 5), // "pIcon"
QT_MOC_LITERAL(70, 854, 8), // "IconLoad"
QT_MOC_LITERAL(71, 863, 16), // "IconLoadFromFile"
QT_MOC_LITERAL(72, 880, 16), // "ifNotRefThenSkip"
QT_MOC_LITERAL(73, 897, 13), // "SetShowPlanes"
QT_MOC_LITERAL(74, 911, 14), // "showPlanesMask"
QT_MOC_LITERAL(75, 926, 11), // "show_planes"
QT_MOC_LITERAL(76, 938, 17), // "GetShowPlanesMask"
QT_MOC_LITERAL(77, 956, 16), // "GetShowPlanesStr"
QT_MOC_LITERAL(78, 973, 11), // "GetCurPlane"
QT_MOC_LITERAL(79, 985, 11), // "SetCurPlane"
QT_MOC_LITERAL(80, 997, 5), // "plane"
QT_MOC_LITERAL(81, 1003, 9), // "ShowPlane"
QT_MOC_LITERAL(82, 1013, 7), // "planeNo"
QT_MOC_LITERAL(83, 1021, 9), // "HidePlane"
QT_MOC_LITERAL(84, 1031, 8), // "DelPlane"
QT_MOC_LITERAL(85, 1040, 9), // "MovePlane"
QT_MOC_LITERAL(86, 1050, 11), // "fromPlaneNo"
QT_MOC_LITERAL(87, 1062, 9), // "toPlaneNo"
QT_MOC_LITERAL(88, 1072, 11), // "GetFileType"
QT_MOC_LITERAL(89, 1084, 11), // "SetFileType"
QT_MOC_LITERAL(90, 1096, 4), // "type"
QT_MOC_LITERAL(91, 1101, 12), // "GetPlaneNums"
QT_MOC_LITERAL(92, 1114, 12), // "SetPlaneNums"
QT_MOC_LITERAL(93, 1127, 9), // "planeNums"
QT_MOC_LITERAL(94, 1137, 12), // "GetStateNums"
QT_MOC_LITERAL(95, 1150, 12), // "SetStateNums"
QT_MOC_LITERAL(96, 1163, 4), // "nums"
QT_MOC_LITERAL(97, 1168, 13), // "SetPlaneNames"
QT_MOC_LITERAL(98, 1182, 6), // "pNames"
QT_MOC_LITERAL(99, 1189, 13), // "GetPlaneNames"
QT_MOC_LITERAL(100, 1203, 11), // "GetFileName"
QT_MOC_LITERAL(101, 1215, 11), // "UpdateLinks"
QT_MOC_LITERAL(102, 1227, 5), // "bypos"
QT_MOC_LITERAL(103, 1233, 4), // "View"
QT_MOC_LITERAL(104, 1238, 8), // "QWidget*"
QT_MOC_LITERAL(105, 1247, 15), // "GetScriptEngine"
QT_MOC_LITERAL(106, 1263, 14), // "CScriptEngine*"
QT_MOC_LITERAL(107, 1278, 18), // "OnSelectionChanged"
QT_MOC_LITERAL(108, 1297, 14), // "GetElementById"
QT_MOC_LITERAL(109, 1312, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(110, 1327, 2), // "id"
QT_MOC_LITERAL(111, 1330, 9), // "ifcontain"
QT_MOC_LITERAL(112, 1340, 15), // "GetPropertyList"
QT_MOC_LITERAL(113, 1356, 32), // "QList<QPair<QString,QVariant> >&"
QT_MOC_LITERAL(114, 1389, 13), // "property_list"
QT_MOC_LITERAL(115, 1403, 11), // "SetProperty"
QT_MOC_LITERAL(116, 1415, 13), // "property_name"
QT_MOC_LITERAL(117, 1429, 7), // "allprop"
QT_MOC_LITERAL(118, 1437, 15), // "CustomPropertys"
QT_MOC_LITERAL(119, 1453, 8), // "Property"
QT_MOC_LITERAL(120, 1462, 4), // "name"
QT_MOC_LITERAL(121, 1467, 11), // "UpdateScene"
QT_MOC_LITERAL(122, 1479, 11), // "GetUserData"
QT_MOC_LITERAL(123, 1491, 11), // "SetUserData"
QT_MOC_LITERAL(124, 1503, 8), // "userData"
QT_MOC_LITERAL(125, 1512, 10), // "CreateItem"
QT_MOC_LITERAL(126, 1523, 7), // "jsonstr"
QT_MOC_LITERAL(127, 1531, 2), // "dx"
QT_MOC_LITERAL(128, 1534, 2), // "dy"
QT_MOC_LITERAL(129, 1537, 11), // "FitViewMode"
QT_MOC_LITERAL(130, 1549, 14), // "SetFitViewMode"
QT_MOC_LITERAL(131, 1564, 7), // "fitmode"
QT_MOC_LITERAL(132, 1572, 8), // "LinkMode"
QT_MOC_LITERAL(133, 1581, 11), // "SetLinkMode"
QT_MOC_LITERAL(134, 1593, 8), // "SetIfRef"
QT_MOC_LITERAL(135, 1602, 5), // "ifref"
QT_MOC_LITERAL(136, 1608, 8), // "GetIfRef"
QT_MOC_LITERAL(137, 1617, 12), // "GetSceneType"
QT_MOC_LITERAL(138, 1630, 12) // "SetSceneType"

    },
    "CGraphScene\0ItemBeCreated\0\0item\0Items\0"
    "QObjectList\0selector\0parent\0ifTopItem\0"
    "GetBackColor\0SetBackColor\0back_color\0"
    "GetForeColor\0SetForeColor\0fore_color\0"
    "GetBackPixmapFlag\0SetBackPixmapFlag\0"
    "back_pixmap_flag\0GetBackPixmapName\0"
    "SetBackPixmapName\0back_pixmap_name\0"
    "GetPixmapShowWay\0SetPixmapShowWay\0"
    "value\0GetRefreshInterval\0SetRefreshInterval\0"
    "refresh_itv\0GetInitZoomFactor\0"
    "SetInitZoomFactor\0zoom_factor\0"
    "GetGraphFacID\0SetGraphFacID\0fac_id\0"
    "GetTopoFlag\0SetTopoFlag\0flag\0GetWndTitle\0"
    "SetWndTitle\0title\0GetStationApp\0"
    "SetStationApp\0station_app\0SetLayoutRect\0"
    "rect\0GetLayoutRect\0SetGraphShowMode\0"
    "mode\0GraphShowMode\0WindowModality\0"
    "SetWindowModality\0SetEnableScale\0"
    "enable\0GetEnableScale\0SetMovable\0"
    "GetMovable\0GetWindowOpacity\0"
    "SetWindowOpacity\0level\0FileSave\0"
    "fileName\0isBinary\0FileOpen\0LoadJsonModel\0"
    "jsonobj\0GetJsonModel\0UpdateLayout\0"
    "IconSave\0IconSaveToFile\0CIconItem*\0"
    "pIcon\0IconLoad\0IconLoadFromFile\0"
    "ifNotRefThenSkip\0SetShowPlanes\0"
    "showPlanesMask\0show_planes\0GetShowPlanesMask\0"
    "GetShowPlanesStr\0GetCurPlane\0SetCurPlane\0"
    "plane\0ShowPlane\0planeNo\0HidePlane\0"
    "DelPlane\0MovePlane\0fromPlaneNo\0toPlaneNo\0"
    "GetFileType\0SetFileType\0type\0GetPlaneNums\0"
    "SetPlaneNums\0planeNums\0GetStateNums\0"
    "SetStateNums\0nums\0SetPlaneNames\0pNames\0"
    "GetPlaneNames\0GetFileName\0UpdateLinks\0"
    "bypos\0View\0QWidget*\0GetScriptEngine\0"
    "CScriptEngine*\0OnSelectionChanged\0"
    "GetElementById\0QGraphicsItem*\0id\0"
    "ifcontain\0GetPropertyList\0"
    "QList<QPair<QString,QVariant> >&\0"
    "property_list\0SetProperty\0property_name\0"
    "allprop\0CustomPropertys\0Property\0name\0"
    "UpdateScene\0GetUserData\0SetUserData\0"
    "userData\0CreateItem\0jsonstr\0dx\0dy\0"
    "FitViewMode\0SetFitViewMode\0fitmode\0"
    "LinkMode\0SetLinkMode\0SetIfRef\0ifref\0"
    "GetIfRef\0GetSceneType\0SetSceneType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGraphScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      96,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  494,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,  497,    2, 0x0a /* Public */,
       4,    2,  504,    2, 0x2a /* Public | MethodCloned */,
       4,    1,  509,    2, 0x2a /* Public | MethodCloned */,
       9,    0,  512,    2, 0x0a /* Public */,
      10,    1,  513,    2, 0x0a /* Public */,
      12,    0,  516,    2, 0x0a /* Public */,
      13,    1,  517,    2, 0x0a /* Public */,
      15,    0,  520,    2, 0x0a /* Public */,
      16,    1,  521,    2, 0x0a /* Public */,
      18,    0,  524,    2, 0x0a /* Public */,
      19,    1,  525,    2, 0x0a /* Public */,
      21,    0,  528,    2, 0x0a /* Public */,
      22,    1,  529,    2, 0x0a /* Public */,
      24,    0,  532,    2, 0x0a /* Public */,
      25,    1,  533,    2, 0x0a /* Public */,
      27,    0,  536,    2, 0x0a /* Public */,
      28,    1,  537,    2, 0x0a /* Public */,
      30,    0,  540,    2, 0x0a /* Public */,
      31,    1,  541,    2, 0x0a /* Public */,
      33,    0,  544,    2, 0x0a /* Public */,
      34,    1,  545,    2, 0x0a /* Public */,
      36,    0,  548,    2, 0x0a /* Public */,
      37,    1,  549,    2, 0x0a /* Public */,
      39,    0,  552,    2, 0x0a /* Public */,
      40,    1,  553,    2, 0x0a /* Public */,
      42,    1,  556,    2, 0x0a /* Public */,
      44,    0,  559,    2, 0x0a /* Public */,
      45,    1,  560,    2, 0x0a /* Public */,
      47,    0,  563,    2, 0x0a /* Public */,
      48,    0,  564,    2, 0x0a /* Public */,
      49,    1,  565,    2, 0x0a /* Public */,
      50,    1,  568,    2, 0x0a /* Public */,
      52,    0,  571,    2, 0x0a /* Public */,
      53,    1,  572,    2, 0x0a /* Public */,
      54,    0,  575,    2, 0x0a /* Public */,
      55,    0,  576,    2, 0x0a /* Public */,
      56,    1,  577,    2, 0x0a /* Public */,
      58,    2,  580,    2, 0x0a /* Public */,
      58,    1,  585,    2, 0x2a /* Public | MethodCloned */,
      61,    2,  588,    2, 0x0a /* Public */,
      61,    1,  593,    2, 0x2a /* Public | MethodCloned */,
      62,    1,  596,    2, 0x0a /* Public */,
      64,    0,  599,    2, 0x0a /* Public */,
      65,    1,  600,    2, 0x0a /* Public */,
      66,    1,  603,    2, 0x0a /* Public */,
      67,    2,  606,    2, 0x0a /* Public */,
      70,    1,  611,    2, 0x0a /* Public */,
      71,    2,  614,    2, 0x0a /* Public */,
      71,    1,  619,    2, 0x2a /* Public | MethodCloned */,
      73,    1,  622,    2, 0x0a /* Public */,
      73,    1,  625,    2, 0x0a /* Public */,
      76,    0,  628,    2, 0x0a /* Public */,
      77,    0,  629,    2, 0x0a /* Public */,
      78,    0,  630,    2, 0x0a /* Public */,
      79,    1,  631,    2, 0x0a /* Public */,
      81,    1,  634,    2, 0x0a /* Public */,
      83,    1,  637,    2, 0x0a /* Public */,
      84,    1,  640,    2, 0x0a /* Public */,
      85,    2,  643,    2, 0x0a /* Public */,
      88,    0,  648,    2, 0x0a /* Public */,
      89,    1,  649,    2, 0x0a /* Public */,
      91,    0,  652,    2, 0x0a /* Public */,
      92,    1,  653,    2, 0x0a /* Public */,
      94,    0,  656,    2, 0x0a /* Public */,
      95,    1,  657,    2, 0x0a /* Public */,
      97,    1,  660,    2, 0x0a /* Public */,
      99,    0,  663,    2, 0x0a /* Public */,
     100,    0,  664,    2, 0x0a /* Public */,
     101,    1,  665,    2, 0x0a /* Public */,
     101,    0,  668,    2, 0x2a /* Public | MethodCloned */,
     103,    0,  669,    2, 0x0a /* Public */,
     105,    0,  670,    2, 0x0a /* Public */,
     107,    0,  671,    2, 0x0a /* Public */,
     108,    2,  672,    2, 0x0a /* Public */,
     108,    1,  677,    2, 0x2a /* Public | MethodCloned */,
     112,    1,  680,    2, 0x0a /* Public */,
     115,    3,  683,    2, 0x0a /* Public */,
     115,    2,  690,    2, 0x2a /* Public | MethodCloned */,
     118,    0,  695,    2, 0x0a /* Public */,
     119,    2,  696,    2, 0x0a /* Public */,
     119,    1,  701,    2, 0x2a /* Public | MethodCloned */,
     121,    0,  704,    2, 0x0a /* Public */,
     122,    0,  705,    2, 0x0a /* Public */,
     123,    1,  706,    2, 0x0a /* Public */,
     125,    3,  709,    2, 0x0a /* Public */,
     125,    2,  716,    2, 0x2a /* Public | MethodCloned */,
     125,    1,  721,    2, 0x2a /* Public | MethodCloned */,
     129,    0,  724,    2, 0x0a /* Public */,
     130,    1,  725,    2, 0x0a /* Public */,
     132,    0,  728,    2, 0x0a /* Public */,
     133,    1,  729,    2, 0x0a /* Public */,
     134,    1,  732,    2, 0x0a /* Public */,
     136,    0,  735,    2, 0x0a /* Public */,
     137,    0,  736,    2, 0x0a /* Public */,
     138,    1,  737,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar,    3,

 // slots: parameters
    0x80000000 | 5, QMetaType::QString, QMetaType::QObjectStar, QMetaType::Bool,    6,    7,    8,
    0x80000000 | 5, QMetaType::QString, QMetaType::QObjectStar,    6,    7,
    0x80000000 | 5, QMetaType::QString,    6,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Char,   23,
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt,   26,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Float,   29,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QRect,   43,
    QMetaType::QRect,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Bool,
    QMetaType::QReal,
    QMetaType::Void, QMetaType::QReal,   57,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   59,   60,
    QMetaType::Int, QMetaType::QString,   59,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   59,   60,
    QMetaType::Int, QMetaType::QString,   59,
    QMetaType::Int, QMetaType::QVariant,   63,
    QMetaType::QString,
    QMetaType::Int, QMetaType::QVariant,   63,
    QMetaType::Int, QMetaType::QString,   59,
    QMetaType::Int, 0x80000000 | 68, QMetaType::QString,   69,   59,
    QMetaType::Int, QMetaType::QString,   59,
    0x80000000 | 68, QMetaType::QString, QMetaType::Bool,   59,   72,
    0x80000000 | 68, QMetaType::QString,   59,
    QMetaType::Void, QMetaType::QBitArray,   74,
    QMetaType::Void, QMetaType::QString,   75,
    QMetaType::QBitArray,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   80,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Void, QMetaType::Int,   82,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   86,   87,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   90,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   93,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   96,
    QMetaType::Void, QMetaType::QString,   98,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Bool,  102,
    QMetaType::Void,
    0x80000000 | 104,
    0x80000000 | 106,
    QMetaType::Void,
    0x80000000 | 109, QMetaType::QString, QMetaType::Bool,  110,  111,
    0x80000000 | 109, QMetaType::QString,  110,
    QMetaType::Void, 0x80000000 | 113,  114,
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant, QMetaType::Bool,  116,   23,  117,
    QMetaType::Bool, QMetaType::QString, QMetaType::QVariant,  116,   23,
    QMetaType::QVariantMap,
    QMetaType::QVariant, QMetaType::QString, QMetaType::Bool,  120,  117,
    QMetaType::QVariant, QMetaType::QString,  120,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,  124,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::Int, QMetaType::Int,  126,  127,  128,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::Int,  126,  127,
    QMetaType::QObjectStar, QMetaType::QString,  126,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,  131,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   90,
    QMetaType::Void, QMetaType::Bool,  135,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   90,

       0        // eod
};

void CGraphScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGraphScene *_t = static_cast<CGraphScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ItemBeCreated((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: { QObjectList _r = _t->Items((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 2: { QObjectList _r = _t->Items((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 3: { QObjectList _r = _t->Items((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->GetBackColor();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->SetBackColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { int _r = _t->GetForeColor();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->SetForeColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { int _r = _t->GetBackPixmapFlag();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->SetBackPixmapFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: { QString _r = _t->GetBackPixmapName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->SetBackPixmapName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: { int _r = _t->GetPixmapShowWay();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->SetPixmapShowWay((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 14: { uint _r = _t->GetRefreshInterval();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->SetRefreshInterval((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 16: { float _r = _t->GetInitZoomFactor();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->SetInitZoomFactor((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 18: { int _r = _t->GetGraphFacID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->SetGraphFacID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: { int _r = _t->GetTopoFlag();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->SetTopoFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: { QString _r = _t->GetWndTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->SetWndTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: { QString _r = _t->GetStationApp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->SetStationApp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->SetLayoutRect((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 27: { QRect _r = _t->GetLayoutRect();
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->SetGraphShowMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: { int _r = _t->GraphShowMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: { int _r = _t->WindowModality();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->SetWindowModality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->SetEnableScale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: { bool _r = _t->GetEnableScale();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->SetMovable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: { bool _r = _t->GetMovable();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 36: { qreal _r = _t->GetWindowOpacity();
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->SetWindowOpacity((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 38: { int _r = _t->FileSave((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 39: { int _r = _t->FileSave((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: { int _r = _t->FileOpen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 41: { int _r = _t->FileOpen((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 42: { int _r = _t->LoadJsonModel((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 43: { QString _r = _t->GetJsonModel();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 44: { int _r = _t->UpdateLayout((*reinterpret_cast< const QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 45: { int _r = _t->IconSave((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 46: { int _r = _t->IconSaveToFile((*reinterpret_cast< CIconItem*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 47: { int _r = _t->IconLoad((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 48: { CIconItem* _r = _t->IconLoadFromFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< CIconItem**>(_a[0]) = std::move(_r); }  break;
        case 49: { CIconItem* _r = _t->IconLoadFromFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< CIconItem**>(_a[0]) = std::move(_r); }  break;
        case 50: _t->SetShowPlanes((*reinterpret_cast< const QBitArray(*)>(_a[1]))); break;
        case 51: _t->SetShowPlanes((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 52: { QBitArray _r = _t->GetShowPlanesMask();
            if (_a[0]) *reinterpret_cast< QBitArray*>(_a[0]) = std::move(_r); }  break;
        case 53: { QString _r = _t->GetShowPlanesStr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 54: { int _r = _t->GetCurPlane();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 55: _t->SetCurPlane((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->ShowPlane((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->HidePlane((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->DelPlane((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->MovePlane((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 60: { int _r = _t->GetFileType();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 61: _t->SetFileType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: { int _r = _t->GetPlaneNums();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 63: _t->SetPlaneNums((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 64: { int _r = _t->GetStateNums();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 65: _t->SetStateNums((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->SetPlaneNames((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 67: { QString _r = _t->GetPlaneNames();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 68: { QString _r = _t->GetFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 69: _t->UpdateLinks((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 70: _t->UpdateLinks(); break;
        case 71: { QWidget* _r = _t->View();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 72: { CScriptEngine* _r = _t->GetScriptEngine();
            if (_a[0]) *reinterpret_cast< CScriptEngine**>(_a[0]) = std::move(_r); }  break;
        case 73: _t->OnSelectionChanged(); break;
        case 74: { QGraphicsItem* _r = _t->GetElementById((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QGraphicsItem**>(_a[0]) = std::move(_r); }  break;
        case 75: { QGraphicsItem* _r = _t->GetElementById((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QGraphicsItem**>(_a[0]) = std::move(_r); }  break;
        case 76: _t->GetPropertyList((*reinterpret_cast< QList<QPair<QString,QVariant> >(*)>(_a[1]))); break;
        case 77: { bool _r = _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 78: { bool _r = _t->SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 79: { QVariantMap _r = _t->CustomPropertys();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 80: { QVariant _r = _t->Property((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 81: { QVariant _r = _t->Property((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 82: _t->UpdateScene(); break;
        case 83: { QString _r = _t->GetUserData();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 84: _t->SetUserData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 85: { QObject* _r = _t->CreateItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 86: { QObject* _r = _t->CreateItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 87: { QObject* _r = _t->CreateItem((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 88: { int _r = _t->FitViewMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 89: _t->SetFitViewMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 90: { int _r = _t->LinkMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 91: _t->SetLinkMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 92: _t->SetIfRef((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 93: { bool _r = _t->GetIfRef();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 94: { int _r = _t->GetSceneType();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 95: _t->SetSceneType((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGraphScene::*)(QObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGraphScene::ItemBeCreated)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGraphScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_CGraphScene.data,
      qt_meta_data_CGraphScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGraphScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGraphScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGraphScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int CGraphScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 96)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 96;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 96)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 96;
    }
    return _id;
}

// SIGNAL 0
void CGraphScene::ItemBeCreated(QObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
