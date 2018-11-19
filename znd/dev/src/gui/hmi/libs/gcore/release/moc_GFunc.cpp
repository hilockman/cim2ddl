/****************************************************************************
** Meta object code from reading C++ file 'GFunc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/GFunc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GFunc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CGFunc_t {
    QByteArrayData data[153];
    char stringdata0[1803];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CGFunc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CGFunc_t qt_meta_stringdata_CGFunc = {
    {
QT_MOC_LITERAL(0, 0, 6), // "CGFunc"
QT_MOC_LITERAL(1, 7, 15), // "SysExecFinished"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "programName"
QT_MOC_LITERAL(4, 36, 8), // "exitCode"
QT_MOC_LITERAL(5, 45, 10), // "exitStatus"
QT_MOC_LITERAL(6, 56, 6), // "QSleep"
QT_MOC_LITERAL(7, 63, 4), // "msec"
QT_MOC_LITERAL(8, 68, 9), // "TmRestart"
QT_MOC_LITERAL(9, 78, 7), // "TmDebug"
QT_MOC_LITERAL(10, 86, 3), // "log"
QT_MOC_LITERAL(11, 90, 6), // "SetVar"
QT_MOC_LITERAL(12, 97, 3), // "key"
QT_MOC_LITERAL(13, 101, 5), // "value"
QT_MOC_LITERAL(14, 107, 6), // "GetVar"
QT_MOC_LITERAL(15, 114, 3), // "def"
QT_MOC_LITERAL(16, 118, 5), // "bool*"
QT_MOC_LITERAL(17, 124, 2), // "ok"
QT_MOC_LITERAL(18, 127, 11), // "GetDateTime"
QT_MOC_LITERAL(19, 139, 6), // "format"
QT_MOC_LITERAL(20, 146, 9), // "SetMemVar"
QT_MOC_LITERAL(21, 156, 9), // "GetMemVar"
QT_MOC_LITERAL(22, 166, 7), // "ExitApp"
QT_MOC_LITERAL(23, 174, 9), // "EntryList"
QT_MOC_LITERAL(24, 184, 3), // "dir"
QT_MOC_LITERAL(25, 188, 11), // "nameFilters"
QT_MOC_LITERAL(26, 200, 7), // "filters"
QT_MOC_LITERAL(27, 208, 4), // "sort"
QT_MOC_LITERAL(28, 213, 13), // "EntryInfoList"
QT_MOC_LITERAL(29, 227, 10), // "FileExists"
QT_MOC_LITERAL(30, 238, 4), // "file"
QT_MOC_LITERAL(31, 243, 8), // "LoadFile"
QT_MOC_LITERAL(32, 252, 4), // "name"
QT_MOC_LITERAL(33, 257, 8), // "SaveFile"
QT_MOC_LITERAL(34, 266, 3), // "buf"
QT_MOC_LITERAL(35, 270, 14), // "LoadBinaryFile"
QT_MOC_LITERAL(36, 285, 8), // "filePath"
QT_MOC_LITERAL(37, 294, 14), // "SaveBinaryFile"
QT_MOC_LITERAL(38, 309, 7), // "fileStr"
QT_MOC_LITERAL(39, 317, 12), // "LoadIconInfo"
QT_MOC_LITERAL(40, 330, 9), // "CalcAngle"
QT_MOC_LITERAL(41, 340, 1), // "x"
QT_MOC_LITERAL(42, 342, 1), // "y"
QT_MOC_LITERAL(43, 344, 31), // "GetGraphCoreNameByGraphPathName"
QT_MOC_LITERAL(44, 376, 15), // "graph_path_name"
QT_MOC_LITERAL(45, 392, 8), // "QString&"
QT_MOC_LITERAL(46, 401, 15), // "graph_core_name"
QT_MOC_LITERAL(47, 417, 27), // "GetGraphNameByGraphPathName"
QT_MOC_LITERAL(48, 445, 10), // "graph_name"
QT_MOC_LITERAL(49, 456, 31), // "GetGraphNaviNameByGraphPathName"
QT_MOC_LITERAL(50, 488, 15), // "graph_navi_name"
QT_MOC_LITERAL(51, 504, 27), // "GetGraphCoreNameByGraphName"
QT_MOC_LITERAL(52, 532, 27), // "GetGraphPathNameByGraphName"
QT_MOC_LITERAL(53, 560, 14), // "is_case_status"
QT_MOC_LITERAL(54, 575, 29), // "GetIconNaviNameByIconPathName"
QT_MOC_LITERAL(55, 605, 14), // "icon_path_name"
QT_MOC_LITERAL(56, 620, 14), // "icon_navi_name"
QT_MOC_LITERAL(57, 635, 29), // "GetIconPathNameByIconCoreName"
QT_MOC_LITERAL(58, 665, 9), // "icon_name"
QT_MOC_LITERAL(59, 675, 23), // "GetIconIDByIconPathName"
QT_MOC_LITERAL(60, 699, 12), // "iconPahtName"
QT_MOC_LITERAL(61, 712, 6), // "iconID"
QT_MOC_LITERAL(62, 719, 6), // "GetDir"
QT_MOC_LITERAL(63, 726, 9), // "PATH_TYPE"
QT_MOC_LITERAL(64, 736, 8), // "pathType"
QT_MOC_LITERAL(65, 745, 15), // "GetFilePathName"
QT_MOC_LITERAL(66, 761, 9), // "path_type"
QT_MOC_LITERAL(67, 771, 9), // "file_name"
QT_MOC_LITERAL(68, 781, 14), // "file_path_name"
QT_MOC_LITERAL(69, 796, 21), // "GetNaviNameByPathName"
QT_MOC_LITERAL(70, 818, 9), // "path_name"
QT_MOC_LITERAL(71, 828, 9), // "navi_name"
QT_MOC_LITERAL(72, 838, 14), // "SetDisplayName"
QT_MOC_LITERAL(73, 853, 12), // "display_name"
QT_MOC_LITERAL(74, 866, 14), // "GetDisplayName"
QT_MOC_LITERAL(75, 881, 12), // "GetDisplayNo"
QT_MOC_LITERAL(76, 894, 19), // "GetAnotherDisplayNo"
QT_MOC_LITERAL(77, 914, 17), // "std::vector<int>*"
QT_MOC_LITERAL(78, 932, 16), // "allow_screen_vec"
QT_MOC_LITERAL(79, 949, 5), // "index"
QT_MOC_LITERAL(80, 955, 18), // "GetCmdRegisterName"
QT_MOC_LITERAL(81, 974, 3), // "cmd"
QT_MOC_LITERAL(82, 978, 13), // "register_name"
QT_MOC_LITERAL(83, 992, 13), // "GetScreenNums"
QT_MOC_LITERAL(84, 1006, 12), // "SetLocalDmId"
QT_MOC_LITERAL(85, 1019, 9), // "domain_id"
QT_MOC_LITERAL(86, 1029, 12), // "GetLocalDmId"
QT_MOC_LITERAL(87, 1042, 10), // "GetRegName"
QT_MOC_LITERAL(88, 1053, 14), // "GetProcessName"
QT_MOC_LITERAL(89, 1068, 11), // "SetPicPaths"
QT_MOC_LITERAL(90, 1080, 20), // "std::vector<QString>"
QT_MOC_LITERAL(91, 1101, 5), // "paths"
QT_MOC_LITERAL(92, 1107, 10), // "GetSysHome"
QT_MOC_LITERAL(93, 1118, 15), // "GetItemIconName"
QT_MOC_LITERAL(94, 1134, 8), // "iconName"
QT_MOC_LITERAL(95, 1143, 10), // "SetSysHome"
QT_MOC_LITERAL(96, 1154, 8), // "sys_home"
QT_MOC_LITERAL(97, 1163, 14), // "SetProjectHome"
QT_MOC_LITERAL(98, 1178, 12), // "project_home"
QT_MOC_LITERAL(99, 1191, 14), // "GetProjectHome"
QT_MOC_LITERAL(100, 1206, 6), // "SysCmd"
QT_MOC_LITERAL(101, 1213, 2), // "op"
QT_MOC_LITERAL(102, 1216, 7), // "srcfile"
QT_MOC_LITERAL(103, 1224, 7), // "desfile"
QT_MOC_LITERAL(104, 1232, 8), // "is_local"
QT_MOC_LITERAL(105, 1241, 12), // "machine_name"
QT_MOC_LITERAL(106, 1254, 7), // "SysExec"
QT_MOC_LITERAL(107, 1262, 7), // "command"
QT_MOC_LITERAL(108, 1270, 10), // "hasConsole"
QT_MOC_LITERAL(109, 1281, 20), // "waitForFinishedMsecs"
QT_MOC_LITERAL(110, 1302, 12), // "which_screen"
QT_MOC_LITERAL(111, 1315, 9), // "show_type"
QT_MOC_LITERAL(112, 1325, 17), // "GetBrushStyleText"
QT_MOC_LITERAL(113, 1343, 5), // "brush"
QT_MOC_LITERAL(114, 1349, 8), // "pic_name"
QT_MOC_LITERAL(115, 1358, 14), // "SetBrushByText"
QT_MOC_LITERAL(116, 1373, 4), // "text"
QT_MOC_LITERAL(117, 1378, 18), // "GetTextureFileName"
QT_MOC_LITERAL(118, 1397, 8), // "Selector"
QT_MOC_LITERAL(119, 1406, 11), // "QObjectList"
QT_MOC_LITERAL(120, 1418, 8), // "selector"
QT_MOC_LITERAL(121, 1427, 21), // "QList<QGraphicsItem*>"
QT_MOC_LITERAL(122, 1449, 5), // "items"
QT_MOC_LITERAL(123, 1455, 11), // "CreateArrow"
QT_MOC_LITERAL(124, 1467, 2), // "ps"
QT_MOC_LITERAL(125, 1470, 9), // "arrowType"
QT_MOC_LITERAL(126, 1480, 11), // "arrowHeight"
QT_MOC_LITERAL(127, 1492, 10), // "arrowWidth"
QT_MOC_LITERAL(128, 1503, 17), // "CreatePathAnimate"
QT_MOC_LITERAL(129, 1521, 15), // "CPathAnimation*"
QT_MOC_LITERAL(130, 1537, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(131, 1552, 8), // "pathitem"
QT_MOC_LITERAL(132, 1561, 6), // "direct"
QT_MOC_LITERAL(133, 1568, 8), // "duration"
QT_MOC_LITERAL(134, 1577, 4), // "loop"
QT_MOC_LITERAL(135, 1582, 13), // "CreateAnimate"
QT_MOC_LITERAL(136, 1596, 6), // "target"
QT_MOC_LITERAL(137, 1603, 12), // "propertyName"
QT_MOC_LITERAL(138, 1616, 8), // "startval"
QT_MOC_LITERAL(139, 1625, 6), // "endval"
QT_MOC_LITERAL(140, 1632, 14), // "DrawArrowPline"
QT_MOC_LITERAL(141, 1647, 9), // "QPainter*"
QT_MOC_LITERAL(142, 1657, 7), // "painter"
QT_MOC_LITERAL(143, 1665, 7), // "polygon"
QT_MOC_LITERAL(144, 1673, 11), // "arrow_type1"
QT_MOC_LITERAL(145, 1685, 11), // "arrow_size1"
QT_MOC_LITERAL(146, 1697, 11), // "arrow_type2"
QT_MOC_LITERAL(147, 1709, 11), // "arrow_size2"
QT_MOC_LITERAL(148, 1721, 31), // "const QStyleOptionGraphicsItem*"
QT_MOC_LITERAL(149, 1753, 6), // "option"
QT_MOC_LITERAL(150, 1760, 3), // "Awe"
QT_MOC_LITERAL(151, 1764, 17), // "OnSysExecFinished"
QT_MOC_LITERAL(152, 1782, 20) // "QProcess::ExitStatus"

    },
    "CGFunc\0SysExecFinished\0\0programName\0"
    "exitCode\0exitStatus\0QSleep\0msec\0"
    "TmRestart\0TmDebug\0log\0SetVar\0key\0value\0"
    "GetVar\0def\0bool*\0ok\0GetDateTime\0format\0"
    "SetMemVar\0GetMemVar\0ExitApp\0EntryList\0"
    "dir\0nameFilters\0filters\0sort\0EntryInfoList\0"
    "FileExists\0file\0LoadFile\0name\0SaveFile\0"
    "buf\0LoadBinaryFile\0filePath\0SaveBinaryFile\0"
    "fileStr\0LoadIconInfo\0CalcAngle\0x\0y\0"
    "GetGraphCoreNameByGraphPathName\0"
    "graph_path_name\0QString&\0graph_core_name\0"
    "GetGraphNameByGraphPathName\0graph_name\0"
    "GetGraphNaviNameByGraphPathName\0"
    "graph_navi_name\0GetGraphCoreNameByGraphName\0"
    "GetGraphPathNameByGraphName\0is_case_status\0"
    "GetIconNaviNameByIconPathName\0"
    "icon_path_name\0icon_navi_name\0"
    "GetIconPathNameByIconCoreName\0icon_name\0"
    "GetIconIDByIconPathName\0iconPahtName\0"
    "iconID\0GetDir\0PATH_TYPE\0pathType\0"
    "GetFilePathName\0path_type\0file_name\0"
    "file_path_name\0GetNaviNameByPathName\0"
    "path_name\0navi_name\0SetDisplayName\0"
    "display_name\0GetDisplayName\0GetDisplayNo\0"
    "GetAnotherDisplayNo\0std::vector<int>*\0"
    "allow_screen_vec\0index\0GetCmdRegisterName\0"
    "cmd\0register_name\0GetScreenNums\0"
    "SetLocalDmId\0domain_id\0GetLocalDmId\0"
    "GetRegName\0GetProcessName\0SetPicPaths\0"
    "std::vector<QString>\0paths\0GetSysHome\0"
    "GetItemIconName\0iconName\0SetSysHome\0"
    "sys_home\0SetProjectHome\0project_home\0"
    "GetProjectHome\0SysCmd\0op\0srcfile\0"
    "desfile\0is_local\0machine_name\0SysExec\0"
    "command\0hasConsole\0waitForFinishedMsecs\0"
    "which_screen\0show_type\0GetBrushStyleText\0"
    "brush\0pic_name\0SetBrushByText\0text\0"
    "GetTextureFileName\0Selector\0QObjectList\0"
    "selector\0QList<QGraphicsItem*>\0items\0"
    "CreateArrow\0ps\0arrowType\0arrowHeight\0"
    "arrowWidth\0CreatePathAnimate\0"
    "CPathAnimation*\0QGraphicsItem*\0pathitem\0"
    "direct\0duration\0loop\0CreateAnimate\0"
    "target\0propertyName\0startval\0endval\0"
    "DrawArrowPline\0QPainter*\0painter\0"
    "polygon\0arrow_type1\0arrow_size1\0"
    "arrow_type2\0arrow_size2\0"
    "const QStyleOptionGraphicsItem*\0option\0"
    "Awe\0OnSysExecFinished\0QProcess::ExitStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CGFunc[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      84,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  434,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  441,    2, 0x0a /* Public */,
       8,    0,  444,    2, 0x0a /* Public */,
       9,    1,  445,    2, 0x0a /* Public */,
      11,    2,  448,    2, 0x0a /* Public */,
      14,    3,  453,    2, 0x0a /* Public */,
      14,    2,  460,    2, 0x2a /* Public | MethodCloned */,
      14,    1,  465,    2, 0x2a /* Public | MethodCloned */,
      18,    1,  468,    2, 0x0a /* Public */,
      20,    2,  471,    2, 0x0a /* Public */,
      21,    3,  476,    2, 0x0a /* Public */,
      21,    2,  483,    2, 0x2a /* Public | MethodCloned */,
      21,    1,  488,    2, 0x2a /* Public | MethodCloned */,
      22,    0,  491,    2, 0x0a /* Public */,
      23,    4,  492,    2, 0x0a /* Public */,
      23,    3,  501,    2, 0x2a /* Public | MethodCloned */,
      23,    2,  508,    2, 0x2a /* Public | MethodCloned */,
      28,    4,  513,    2, 0x0a /* Public */,
      28,    3,  522,    2, 0x2a /* Public | MethodCloned */,
      28,    2,  529,    2, 0x2a /* Public | MethodCloned */,
      29,    1,  534,    2, 0x0a /* Public */,
      31,    1,  537,    2, 0x0a /* Public */,
      33,    2,  540,    2, 0x0a /* Public */,
      35,    1,  545,    2, 0x0a /* Public */,
      37,    2,  548,    2, 0x0a /* Public */,
      39,    0,  553,    2, 0x0a /* Public */,
      40,    2,  554,    2, 0x0a /* Public */,
      43,    2,  559,    2, 0x0a /* Public */,
      47,    2,  564,    2, 0x0a /* Public */,
      49,    2,  569,    2, 0x0a /* Public */,
      51,    2,  574,    2, 0x0a /* Public */,
      52,    3,  579,    2, 0x0a /* Public */,
      52,    2,  586,    2, 0x2a /* Public | MethodCloned */,
      54,    2,  591,    2, 0x0a /* Public */,
      57,    2,  596,    2, 0x0a /* Public */,
      59,    2,  601,    2, 0x0a /* Public */,
      62,    1,  606,    2, 0x0a /* Public */,
      65,    3,  609,    2, 0x0a /* Public */,
      69,    2,  616,    2, 0x0a /* Public */,
      72,    1,  621,    2, 0x0a /* Public */,
      74,    1,  624,    2, 0x0a /* Public */,
      75,    0,  627,    2, 0x0a /* Public */,
      76,    2,  628,    2, 0x0a /* Public */,
      76,    1,  633,    2, 0x2a /* Public | MethodCloned */,
      76,    0,  636,    2, 0x2a /* Public | MethodCloned */,
      80,    2,  637,    2, 0x0a /* Public */,
      83,    0,  642,    2, 0x0a /* Public */,
      84,    1,  643,    2, 0x0a /* Public */,
      86,    0,  646,    2, 0x0a /* Public */,
      87,    0,  647,    2, 0x0a /* Public */,
      88,    0,  648,    2, 0x0a /* Public */,
      89,    1,  649,    2, 0x0a /* Public */,
      92,    0,  652,    2, 0x0a /* Public */,
      93,    1,  653,    2, 0x0a /* Public */,
      95,    1,  656,    2, 0x0a /* Public */,
      97,    1,  659,    2, 0x0a /* Public */,
      99,    0,  662,    2, 0x0a /* Public */,
     100,    5,  663,    2, 0x0a /* Public */,
     100,    4,  674,    2, 0x2a /* Public | MethodCloned */,
     100,    3,  683,    2, 0x2a /* Public | MethodCloned */,
     100,    2,  690,    2, 0x2a /* Public | MethodCloned */,
     100,    1,  695,    2, 0x2a /* Public | MethodCloned */,
     106,    5,  698,    2, 0x0a /* Public */,
     106,    4,  709,    2, 0x2a /* Public | MethodCloned */,
     106,    3,  718,    2, 0x2a /* Public | MethodCloned */,
     106,    2,  725,    2, 0x2a /* Public | MethodCloned */,
     106,    1,  730,    2, 0x2a /* Public | MethodCloned */,
     112,    2,  733,    2, 0x0a /* Public */,
     112,    1,  738,    2, 0x2a /* Public | MethodCloned */,
     115,    1,  741,    2, 0x0a /* Public */,
     117,    1,  744,    2, 0x0a /* Public */,
     118,    2,  747,    2, 0x0a /* Public */,
     123,    4,  752,    2, 0x0a /* Public */,
     128,    4,  761,    2, 0x0a /* Public */,
     128,    3,  770,    2, 0x2a /* Public | MethodCloned */,
     128,    2,  777,    2, 0x2a /* Public | MethodCloned */,
     135,    6,  782,    2, 0x0a /* Public */,
     135,    5,  795,    2, 0x2a /* Public | MethodCloned */,
     135,    4,  806,    2, 0x2a /* Public | MethodCloned */,
     135,    3,  815,    2, 0x2a /* Public | MethodCloned */,
     135,    2,  822,    2, 0x2a /* Public | MethodCloned */,
     140,    7,  827,    2, 0x0a /* Public */,
     150,    0,  842,    2, 0x0a /* Public */,
     151,    2,  843,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   12,   13,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant, 0x80000000 | 16,   12,   15,   17,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant,   12,   15,
    QMetaType::QVariant, QMetaType::QString,   12,
    QMetaType::QString, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   12,   13,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant, 0x80000000 | 16,   12,   15,   17,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant,   12,   15,
    QMetaType::QVariant, QMetaType::QString,   12,
    QMetaType::Int,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,   24,   25,   26,   27,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   24,   25,   26,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QStringList,   24,   25,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QStringList, QMetaType::Int, QMetaType::Int,   24,   25,   26,   27,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QStringList, QMetaType::Int,   24,   25,   26,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QStringList,   24,   25,
    QMetaType::Bool, QMetaType::QString,   30,
    QMetaType::QString, QMetaType::QString,   32,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   32,   34,
    QMetaType::QString, QMetaType::QString,   36,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   36,   38,
    QMetaType::Int,
    QMetaType::Float, QMetaType::Float, QMetaType::Float,   41,   42,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   44,   46,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   44,   48,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   44,   50,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   48,   46,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45, QMetaType::Bool,   48,   44,   53,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   48,   44,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   55,   56,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   58,   55,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   60,   61,
    QMetaType::QString, 0x80000000 | 63,   64,
    QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   66,   67,   68,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   70,   71,
    QMetaType::Void, QMetaType::QString,   73,
    QMetaType::Int, 0x80000000 | 45,   73,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 77, QMetaType::Int,   78,   79,
    QMetaType::Int, 0x80000000 | 77,   78,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 45,   81,   82,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   85,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, 0x80000000 | 90,   91,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::Void, QMetaType::QString,   98,
    QMetaType::QString,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString,  101,  102,  103,  104,  105,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,  101,  102,  103,  104,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,  101,  102,  103,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,  101,  102,
    QMetaType::Int, QMetaType::QString,  101,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int,  107,  108,  109,  110,  111,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Int, QMetaType::Int,  107,  108,  109,  110,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Int,  107,  108,  109,
    QMetaType::QString, QMetaType::QString, QMetaType::Bool,  107,  108,
    QMetaType::QString, QMetaType::QString,  107,
    QMetaType::QString, QMetaType::QBrush, QMetaType::QString,  113,  114,
    QMetaType::QString, QMetaType::QBrush,  113,
    QMetaType::QBrush, QMetaType::QString,  116,
    QMetaType::QString, QMetaType::QString,  116,
    0x80000000 | 119, QMetaType::QString, 0x80000000 | 121,  120,  122,
    QMetaType::QPolygonF, QMetaType::QPointF, QMetaType::Int, QMetaType::Int, QMetaType::Int,  124,  125,  126,  127,
    0x80000000 | 129, 0x80000000 | 130, QMetaType::Int, QMetaType::Int, QMetaType::Int,  131,  132,  133,  134,
    0x80000000 | 129, 0x80000000 | 130, QMetaType::Int, QMetaType::Int,  131,  132,  133,
    0x80000000 | 129, 0x80000000 | 130, QMetaType::Int,  131,  132,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant, QMetaType::Int, QMetaType::Int,  136,  137,  138,  139,  133,  134,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant, QMetaType::Int,  136,  137,  138,  139,  133,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant,  136,  137,  138,  139,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant,  136,  137,  138,
    QMetaType::QObjectStar, QMetaType::QObjectStar, QMetaType::QString,  136,  137,
    QMetaType::Void, 0x80000000 | 141, QMetaType::QPolygonF, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 148,  142,  143,  144,  145,  146,  147,  149,
    QMetaType::QObjectStar,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 152,    2,    2,

       0        // eod
};

void CGFunc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CGFunc *_t = static_cast<CGFunc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SysExecFinished((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->QSleep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->TmRestart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->TmDebug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->SetVar((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 5: { QVariant _r = _t->GetVar((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< bool*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariant _r = _t->GetVar((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariant _r = _t->GetVar((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->GetDateTime((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->SetMemVar((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 10: { QVariant _r = _t->GetMemVar((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< bool*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 11: { QVariant _r = _t->GetMemVar((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 12: { QVariant _r = _t->GetMemVar((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->ExitApp();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { QStringList _r = _t->EntryList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 15: { QStringList _r = _t->EntryList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 16: { QStringList _r = _t->EntryList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 17: { QVariantList _r = _t->EntryInfoList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 18: { QVariantList _r = _t->EntryInfoList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 19: { QVariantList _r = _t->EntryInfoList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->FileExists((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->LoadFile((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->SaveFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->LoadBinaryFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { int _r = _t->SaveBinaryFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { int _r = _t->LoadIconInfo();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 26: { float _r = _t->CalcAngle((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 27: { int _r = _t->GetGraphCoreNameByGraphPathName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: { int _r = _t->GetGraphNameByGraphPathName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 29: { int _r = _t->GetGraphNaviNameByGraphPathName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: { int _r = _t->GetGraphCoreNameByGraphName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: { int _r = _t->GetGraphPathNameByGraphName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 32: { int _r = _t->GetGraphPathNameByGraphName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: { int _r = _t->GetIconNaviNameByIconPathName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 34: { int _r = _t->GetIconPathNameByIconCoreName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 35: { int _r = _t->GetIconIDByIconPathName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { QString _r = _t->GetDir((*reinterpret_cast< PATH_TYPE(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 37: { int _r = _t->GetFilePathName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 38: { int _r = _t->GetNaviNameByPathName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 39: _t->SetDisplayName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: { int _r = _t->GetDisplayName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 41: { int _r = _t->GetDisplayNo();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 42: { int _r = _t->GetAnotherDisplayNo((*reinterpret_cast< std::vector<int>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 43: { int _r = _t->GetAnotherDisplayNo((*reinterpret_cast< std::vector<int>*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 44: { int _r = _t->GetAnotherDisplayNo();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 45: { int _r = _t->GetCmdRegisterName((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 46: { int _r = _t->GetScreenNums();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 47: _t->SetLocalDmId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: { int _r = _t->GetLocalDmId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 49: { QString _r = _t->GetRegName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 50: { QString _r = _t->GetProcessName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->SetPicPaths((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 52: { QString _r = _t->GetSysHome();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 53: { QString _r = _t->GetItemIconName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->SetSysHome((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 55: _t->SetProjectHome((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 56: { QString _r = _t->GetProjectHome();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 57: { int _r = _t->SysCmd((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 58: { int _r = _t->SysCmd((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 59: { int _r = _t->SysCmd((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 60: { int _r = _t->SysCmd((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 61: { int _r = _t->SysCmd((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 62: { QString _r = _t->SysExec((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 63: { QString _r = _t->SysExec((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 64: { QString _r = _t->SysExec((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 65: { QString _r = _t->SysExec((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 66: { QString _r = _t->SysExec((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 67: { QString _r = _t->GetBrushStyleText((*reinterpret_cast< const QBrush(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 68: { QString _r = _t->GetBrushStyleText((*reinterpret_cast< const QBrush(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 69: { QBrush _r = _t->SetBrushByText((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QBrush*>(_a[0]) = std::move(_r); }  break;
        case 70: { QString _r = _t->GetTextureFileName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 71: { QObjectList _r = _t->Selector((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QList<QGraphicsItem*>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObjectList*>(_a[0]) = std::move(_r); }  break;
        case 72: { QPolygonF _r = _t->CreateArrow((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QPolygonF*>(_a[0]) = std::move(_r); }  break;
        case 73: { CPathAnimation* _r = _t->CreatePathAnimate((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< CPathAnimation**>(_a[0]) = std::move(_r); }  break;
        case 74: { CPathAnimation* _r = _t->CreatePathAnimate((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< CPathAnimation**>(_a[0]) = std::move(_r); }  break;
        case 75: { CPathAnimation* _r = _t->CreatePathAnimate((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< CPathAnimation**>(_a[0]) = std::move(_r); }  break;
        case 76: { QObject* _r = _t->CreateAnimate((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 77: { QObject* _r = _t->CreateAnimate((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 78: { QObject* _r = _t->CreateAnimate((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 79: { QObject* _r = _t->CreateAnimate((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 80: { QObject* _r = _t->CreateAnimate((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 81: _t->DrawArrowPline((*reinterpret_cast< QPainter*(*)>(_a[1])),(*reinterpret_cast< const QPolygonF(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< const QStyleOptionGraphicsItem*(*)>(_a[7]))); break;
        case 82: { QObject* _r = _t->Awe();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 83: _t->OnSysExecFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 71:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QGraphicsItem*> >(); break;
            }
            break;
        case 73:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 74:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 75:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CGFunc::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CGFunc::SysExecFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CGFunc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CGFunc.data,
      qt_meta_data_CGFunc,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CGFunc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CGFunc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CGFunc.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CGFunc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 84)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 84;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 84)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 84;
    }
    return _id;
}

// SIGNAL 0
void CGFunc::SysExecFinished(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
