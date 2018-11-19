/****************************************************************************
** Meta object code from reading C++ file 'CManhattanStyle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/CManhattanStyle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CManhattanStyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StyleAnimator_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StyleAnimator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StyleAnimator_t qt_meta_stringdata_StyleAnimator = {
    {
QT_MOC_LITERAL(0, 0, 13) // "StyleAnimator"

    },
    "StyleAnimator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StyleAnimator[] = {

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

void StyleAnimator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject StyleAnimator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StyleAnimator.data,
      qt_meta_data_StyleAnimator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StyleAnimator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StyleAnimator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StyleAnimator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int StyleAnimator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Theme_t {
    QByteArrayData data[122];
    char stringdata0[3335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Theme_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Theme_t qt_meta_stringdata_Theme = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Theme"
QT_MOC_LITERAL(1, 6, 5), // "Color"
QT_MOC_LITERAL(2, 12, 24), // "BackgroundColorAlternate"
QT_MOC_LITERAL(3, 37, 19), // "BackgroundColorDark"
QT_MOC_LITERAL(4, 57, 20), // "BackgroundColorHover"
QT_MOC_LITERAL(5, 78, 21), // "BackgroundColorNormal"
QT_MOC_LITERAL(6, 100, 23), // "BackgroundColorSelected"
QT_MOC_LITERAL(7, 124, 32), // "BadgeLabelBackgroundColorChecked"
QT_MOC_LITERAL(8, 157, 34), // "BadgeLabelBackgroundColorUnch..."
QT_MOC_LITERAL(9, 192, 26), // "BadgeLabelTextColorChecked"
QT_MOC_LITERAL(10, 219, 28), // "BadgeLabelTextColorUnchecked"
QT_MOC_LITERAL(11, 248, 23), // "CanceledSearchTextColor"
QT_MOC_LITERAL(12, 272, 18), // "ComboBoxArrowColor"
QT_MOC_LITERAL(13, 291, 26), // "ComboBoxArrowColorDisabled"
QT_MOC_LITERAL(14, 318, 17), // "ComboBoxTextColor"
QT_MOC_LITERAL(15, 336, 28), // "DetailsWidgetBackgroundColor"
QT_MOC_LITERAL(16, 365, 33), // "DetailsButtonBackgroundColorH..."
QT_MOC_LITERAL(17, 399, 27), // "DockWidgetResizeHandleColor"
QT_MOC_LITERAL(18, 427, 42), // "DoubleTabWidget1stEmptyAreaBa..."
QT_MOC_LITERAL(19, 470, 32), // "DoubleTabWidget1stSeparatorColor"
QT_MOC_LITERAL(20, 503, 32), // "DoubleTabWidget2ndSeparatorColor"
QT_MOC_LITERAL(21, 536, 36), // "DoubleTabWidget1stTabBackgrou..."
QT_MOC_LITERAL(22, 573, 36), // "DoubleTabWidget2ndTabBackgrou..."
QT_MOC_LITERAL(23, 610, 36), // "DoubleTabWidget1stTabActiveTe..."
QT_MOC_LITERAL(24, 647, 38), // "DoubleTabWidget1stTabInactive..."
QT_MOC_LITERAL(25, 686, 36), // "DoubleTabWidget2ndTabActiveTe..."
QT_MOC_LITERAL(26, 723, 38), // "DoubleTabWidget2ndTabInactive..."
QT_MOC_LITERAL(27, 762, 22), // "EditorPlaceholderColor"
QT_MOC_LITERAL(28, 785, 26), // "FancyTabBarBackgroundColor"
QT_MOC_LITERAL(29, 812, 38), // "FancyTabWidgetEnabledSelected..."
QT_MOC_LITERAL(30, 851, 40), // "FancyTabWidgetEnabledUnselect..."
QT_MOC_LITERAL(31, 892, 39), // "FancyTabWidgetDisabledSelecte..."
QT_MOC_LITERAL(32, 932, 41), // "FancyTabWidgetDisabledUnselec..."
QT_MOC_LITERAL(33, 974, 25), // "FancyToolButtonHoverColor"
QT_MOC_LITERAL(34, 1000, 28), // "FancyToolButtonSelectedColor"
QT_MOC_LITERAL(35, 1029, 29), // "FutureProgressBackgroundColor"
QT_MOC_LITERAL(36, 1059, 31), // "MenuBarEmptyAreaBackgroundColor"
QT_MOC_LITERAL(37, 1091, 26), // "MenuBarItemBackgroundColor"
QT_MOC_LITERAL(38, 1118, 28), // "MenuBarItemTextColorDisabled"
QT_MOC_LITERAL(39, 1147, 26), // "MenuBarItemTextColorNormal"
QT_MOC_LITERAL(40, 1174, 40), // "MiniProjectTargetSelectorBack..."
QT_MOC_LITERAL(41, 1215, 36), // "MiniProjectTargetSelectorBord..."
QT_MOC_LITERAL(42, 1252, 47), // "MiniProjectTargetSelectorSumm..."
QT_MOC_LITERAL(43, 1300, 34), // "MiniProjectTargetSelectorText..."
QT_MOC_LITERAL(44, 1335, 26), // "OutputPaneButtonFlashColor"
QT_MOC_LITERAL(45, 1362, 38), // "OutputPaneToggleButtonTextCol..."
QT_MOC_LITERAL(46, 1401, 40), // "OutputPaneToggleButtonTextCol..."
QT_MOC_LITERAL(47, 1442, 35), // "PanelButtonToolBackgroundColo..."
QT_MOC_LITERAL(48, 1478, 19), // "PanelTextColorLight"
QT_MOC_LITERAL(49, 1498, 18), // "PanelTextColorDark"
QT_MOC_LITERAL(50, 1517, 30), // "PanelsWidgetSeparatorLineColor"
QT_MOC_LITERAL(51, 1548, 29), // "PanelStatusBarBackgroundColor"
QT_MOC_LITERAL(52, 1578, 21), // "ProgressBarTitleColor"
QT_MOC_LITERAL(53, 1600, 21), // "ProgressBarColorError"
QT_MOC_LITERAL(54, 1622, 24), // "ProgressBarColorFinished"
QT_MOC_LITERAL(55, 1647, 22), // "ProgressBarColorNormal"
QT_MOC_LITERAL(56, 1670, 17), // "InfoBarBackground"
QT_MOC_LITERAL(57, 1688, 11), // "InfoBarText"
QT_MOC_LITERAL(58, 1700, 17), // "TextColorDisabled"
QT_MOC_LITERAL(59, 1718, 18), // "TextColorHighlight"
QT_MOC_LITERAL(60, 1737, 15), // "TextColorNormal"
QT_MOC_LITERAL(61, 1753, 17), // "TodoItemTextColor"
QT_MOC_LITERAL(62, 1771, 27), // "ToggleButtonBackgroundColor"
QT_MOC_LITERAL(63, 1799, 22), // "ToolBarBackgroundColor"
QT_MOC_LITERAL(64, 1822, 24), // "TreeViewArrowColorNormal"
QT_MOC_LITERAL(65, 1847, 26), // "TreeViewArrowColorSelected"
QT_MOC_LITERAL(66, 1874, 38), // "OutputFormatter_NormalMessage..."
QT_MOC_LITERAL(67, 1913, 37), // "OutputFormatter_ErrorMessageT..."
QT_MOC_LITERAL(68, 1951, 31), // "OutputFormatter_StdOutTextColor"
QT_MOC_LITERAL(69, 1983, 31), // "OutputFormatter_StdErrTextColor"
QT_MOC_LITERAL(70, 2015, 30), // "OutputFormatter_DebugTextColor"
QT_MOC_LITERAL(71, 2046, 31), // "QtOutputFormatter_LinkTextColor"
QT_MOC_LITERAL(72, 2078, 23), // "Welcome_TextColorNormal"
QT_MOC_LITERAL(73, 2102, 24), // "Welcome_TextColorHeading"
QT_MOC_LITERAL(74, 2127, 29), // "Welcome_BackgroundColorNormal"
QT_MOC_LITERAL(75, 2157, 20), // "Welcome_DividerColor"
QT_MOC_LITERAL(76, 2178, 32), // "Welcome_Button_BorderColorNormal"
QT_MOC_LITERAL(77, 2211, 33), // "Welcome_Button_BorderColorPre..."
QT_MOC_LITERAL(78, 2245, 30), // "Welcome_Button_TextColorNormal"
QT_MOC_LITERAL(79, 2276, 31), // "Welcome_Button_TextColorPressed"
QT_MOC_LITERAL(80, 2308, 28), // "Welcome_Link_TextColorNormal"
QT_MOC_LITERAL(81, 2337, 28), // "Welcome_Link_TextColorActive"
QT_MOC_LITERAL(82, 2366, 28), // "Welcome_Link_BackgroundColor"
QT_MOC_LITERAL(83, 2395, 31), // "Welcome_Caption_TextColorNormal"
QT_MOC_LITERAL(84, 2427, 31), // "Welcome_SideBar_BackgroundColor"
QT_MOC_LITERAL(85, 2459, 37), // "Welcome_ProjectItem_TextColor..."
QT_MOC_LITERAL(86, 2497, 40), // "Welcome_ProjectItem_Backgroun..."
QT_MOC_LITERAL(87, 2538, 41), // "Welcome_SessionItem_Backgroun..."
QT_MOC_LITERAL(88, 2580, 40), // "Welcome_SessionItem_Backgroun..."
QT_MOC_LITERAL(89, 2621, 49), // "Welcome_SessionItemExpanded_B..."
QT_MOC_LITERAL(90, 2671, 48), // "Welcome_SessionItemExpanded_B..."
QT_MOC_LITERAL(91, 2720, 8), // "Gradient"
QT_MOC_LITERAL(92, 2729, 27), // "DetailsWidgetHeaderGradient"
QT_MOC_LITERAL(93, 2757, 29), // "Welcome_Button_GradientNormal"
QT_MOC_LITERAL(94, 2787, 30), // "Welcome_Button_GradientPressed"
QT_MOC_LITERAL(95, 2818, 9), // "ImageFile"
QT_MOC_LITERAL(96, 2828, 21), // "ProjectExplorerHeader"
QT_MOC_LITERAL(97, 2850, 21), // "ProjectExplorerSource"
QT_MOC_LITERAL(98, 2872, 19), // "ProjectExplorerForm"
QT_MOC_LITERAL(99, 2892, 23), // "ProjectExplorerResource"
QT_MOC_LITERAL(100, 2916, 18), // "ProjectExplorerQML"
QT_MOC_LITERAL(101, 2935, 25), // "ProjectExplorerOtherFiles"
QT_MOC_LITERAL(102, 2961, 15), // "ProjectFileIcon"
QT_MOC_LITERAL(103, 2977, 18), // "IconOverlayCSource"
QT_MOC_LITERAL(104, 2996, 20), // "IconOverlayCppHeader"
QT_MOC_LITERAL(105, 3017, 20), // "IconOverlayCppSource"
QT_MOC_LITERAL(106, 3038, 14), // "IconOverlayPri"
QT_MOC_LITERAL(107, 3053, 14), // "IconOverlayPrf"
QT_MOC_LITERAL(108, 3068, 14), // "IconOverlayPro"
QT_MOC_LITERAL(109, 3083, 22), // "StandardPixmapFileIcon"
QT_MOC_LITERAL(110, 3106, 21), // "StandardPixmapDirIcon"
QT_MOC_LITERAL(111, 3128, 4), // "Flag"
QT_MOC_LITERAL(112, 3133, 24), // "DrawTargetSelectorBottom"
QT_MOC_LITERAL(113, 3158, 27), // "DrawSearchResultWidgetFrame"
QT_MOC_LITERAL(114, 3186, 21), // "DrawProgressBarSunken"
QT_MOC_LITERAL(115, 3208, 19), // "DrawIndicatorBranch"
QT_MOC_LITERAL(116, 3228, 22), // "ComboBoxDrawTextShadow"
QT_MOC_LITERAL(117, 3251, 22), // "DerivePaletteFromTheme"
QT_MOC_LITERAL(118, 3274, 25), // "ApplyThemePaletteGlobally"
QT_MOC_LITERAL(119, 3300, 11), // "WidgetStyle"
QT_MOC_LITERAL(120, 3312, 12), // "StyleDefault"
QT_MOC_LITERAL(121, 3325, 9) // "StyleFlat"

    },
    "Theme\0Color\0BackgroundColorAlternate\0"
    "BackgroundColorDark\0BackgroundColorHover\0"
    "BackgroundColorNormal\0BackgroundColorSelected\0"
    "BadgeLabelBackgroundColorChecked\0"
    "BadgeLabelBackgroundColorUnchecked\0"
    "BadgeLabelTextColorChecked\0"
    "BadgeLabelTextColorUnchecked\0"
    "CanceledSearchTextColor\0ComboBoxArrowColor\0"
    "ComboBoxArrowColorDisabled\0ComboBoxTextColor\0"
    "DetailsWidgetBackgroundColor\0"
    "DetailsButtonBackgroundColorHover\0"
    "DockWidgetResizeHandleColor\0"
    "DoubleTabWidget1stEmptyAreaBackgroundColor\0"
    "DoubleTabWidget1stSeparatorColor\0"
    "DoubleTabWidget2ndSeparatorColor\0"
    "DoubleTabWidget1stTabBackgroundColor\0"
    "DoubleTabWidget2ndTabBackgroundColor\0"
    "DoubleTabWidget1stTabActiveTextColor\0"
    "DoubleTabWidget1stTabInactiveTextColor\0"
    "DoubleTabWidget2ndTabActiveTextColor\0"
    "DoubleTabWidget2ndTabInactiveTextColor\0"
    "EditorPlaceholderColor\0"
    "FancyTabBarBackgroundColor\0"
    "FancyTabWidgetEnabledSelectedTextColor\0"
    "FancyTabWidgetEnabledUnselectedTextColor\0"
    "FancyTabWidgetDisabledSelectedTextColor\0"
    "FancyTabWidgetDisabledUnselectedTextColor\0"
    "FancyToolButtonHoverColor\0"
    "FancyToolButtonSelectedColor\0"
    "FutureProgressBackgroundColor\0"
    "MenuBarEmptyAreaBackgroundColor\0"
    "MenuBarItemBackgroundColor\0"
    "MenuBarItemTextColorDisabled\0"
    "MenuBarItemTextColorNormal\0"
    "MiniProjectTargetSelectorBackgroundColor\0"
    "MiniProjectTargetSelectorBorderColor\0"
    "MiniProjectTargetSelectorSummaryBackgroundColor\0"
    "MiniProjectTargetSelectorTextColor\0"
    "OutputPaneButtonFlashColor\0"
    "OutputPaneToggleButtonTextColorChecked\0"
    "OutputPaneToggleButtonTextColorUnchecked\0"
    "PanelButtonToolBackgroundColorHover\0"
    "PanelTextColorLight\0PanelTextColorDark\0"
    "PanelsWidgetSeparatorLineColor\0"
    "PanelStatusBarBackgroundColor\0"
    "ProgressBarTitleColor\0ProgressBarColorError\0"
    "ProgressBarColorFinished\0"
    "ProgressBarColorNormal\0InfoBarBackground\0"
    "InfoBarText\0TextColorDisabled\0"
    "TextColorHighlight\0TextColorNormal\0"
    "TodoItemTextColor\0ToggleButtonBackgroundColor\0"
    "ToolBarBackgroundColor\0TreeViewArrowColorNormal\0"
    "TreeViewArrowColorSelected\0"
    "OutputFormatter_NormalMessageTextColor\0"
    "OutputFormatter_ErrorMessageTextColor\0"
    "OutputFormatter_StdOutTextColor\0"
    "OutputFormatter_StdErrTextColor\0"
    "OutputFormatter_DebugTextColor\0"
    "QtOutputFormatter_LinkTextColor\0"
    "Welcome_TextColorNormal\0"
    "Welcome_TextColorHeading\0"
    "Welcome_BackgroundColorNormal\0"
    "Welcome_DividerColor\0"
    "Welcome_Button_BorderColorNormal\0"
    "Welcome_Button_BorderColorPressed\0"
    "Welcome_Button_TextColorNormal\0"
    "Welcome_Button_TextColorPressed\0"
    "Welcome_Link_TextColorNormal\0"
    "Welcome_Link_TextColorActive\0"
    "Welcome_Link_BackgroundColor\0"
    "Welcome_Caption_TextColorNormal\0"
    "Welcome_SideBar_BackgroundColor\0"
    "Welcome_ProjectItem_TextColorFilepath\0"
    "Welcome_ProjectItem_BackgroundColorHover\0"
    "Welcome_SessionItem_BackgroundColorNormal\0"
    "Welcome_SessionItem_BackgroundColorHover\0"
    "Welcome_SessionItemExpanded_BackgroundColorNormal\0"
    "Welcome_SessionItemExpanded_BackgroundColorHover\0"
    "Gradient\0DetailsWidgetHeaderGradient\0"
    "Welcome_Button_GradientNormal\0"
    "Welcome_Button_GradientPressed\0ImageFile\0"
    "ProjectExplorerHeader\0ProjectExplorerSource\0"
    "ProjectExplorerForm\0ProjectExplorerResource\0"
    "ProjectExplorerQML\0ProjectExplorerOtherFiles\0"
    "ProjectFileIcon\0IconOverlayCSource\0"
    "IconOverlayCppHeader\0IconOverlayCppSource\0"
    "IconOverlayPri\0IconOverlayPrf\0"
    "IconOverlayPro\0StandardPixmapFileIcon\0"
    "StandardPixmapDirIcon\0Flag\0"
    "DrawTargetSelectorBottom\0"
    "DrawSearchResultWidgetFrame\0"
    "DrawProgressBarSunken\0DrawIndicatorBranch\0"
    "ComboBoxDrawTextShadow\0DerivePaletteFromTheme\0"
    "ApplyThemePaletteGlobally\0WidgetStyle\0"
    "StyleDefault\0StyleFlat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Theme[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       5,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,   89,   34,
      91, 0x0,    3,  212,
      95, 0x0,   15,  218,
     111, 0x0,    7,  248,
     119, 0x0,    2,  262,

 // enum data: key, value
       2, uint(Theme::BackgroundColorAlternate),
       3, uint(Theme::BackgroundColorDark),
       4, uint(Theme::BackgroundColorHover),
       5, uint(Theme::BackgroundColorNormal),
       6, uint(Theme::BackgroundColorSelected),
       7, uint(Theme::BadgeLabelBackgroundColorChecked),
       8, uint(Theme::BadgeLabelBackgroundColorUnchecked),
       9, uint(Theme::BadgeLabelTextColorChecked),
      10, uint(Theme::BadgeLabelTextColorUnchecked),
      11, uint(Theme::CanceledSearchTextColor),
      12, uint(Theme::ComboBoxArrowColor),
      13, uint(Theme::ComboBoxArrowColorDisabled),
      14, uint(Theme::ComboBoxTextColor),
      15, uint(Theme::DetailsWidgetBackgroundColor),
      16, uint(Theme::DetailsButtonBackgroundColorHover),
      17, uint(Theme::DockWidgetResizeHandleColor),
      18, uint(Theme::DoubleTabWidget1stEmptyAreaBackgroundColor),
      19, uint(Theme::DoubleTabWidget1stSeparatorColor),
      20, uint(Theme::DoubleTabWidget2ndSeparatorColor),
      21, uint(Theme::DoubleTabWidget1stTabBackgroundColor),
      22, uint(Theme::DoubleTabWidget2ndTabBackgroundColor),
      23, uint(Theme::DoubleTabWidget1stTabActiveTextColor),
      24, uint(Theme::DoubleTabWidget1stTabInactiveTextColor),
      25, uint(Theme::DoubleTabWidget2ndTabActiveTextColor),
      26, uint(Theme::DoubleTabWidget2ndTabInactiveTextColor),
      27, uint(Theme::EditorPlaceholderColor),
      28, uint(Theme::FancyTabBarBackgroundColor),
      29, uint(Theme::FancyTabWidgetEnabledSelectedTextColor),
      30, uint(Theme::FancyTabWidgetEnabledUnselectedTextColor),
      31, uint(Theme::FancyTabWidgetDisabledSelectedTextColor),
      32, uint(Theme::FancyTabWidgetDisabledUnselectedTextColor),
      33, uint(Theme::FancyToolButtonHoverColor),
      34, uint(Theme::FancyToolButtonSelectedColor),
      35, uint(Theme::FutureProgressBackgroundColor),
      36, uint(Theme::MenuBarEmptyAreaBackgroundColor),
      37, uint(Theme::MenuBarItemBackgroundColor),
      38, uint(Theme::MenuBarItemTextColorDisabled),
      39, uint(Theme::MenuBarItemTextColorNormal),
      40, uint(Theme::MiniProjectTargetSelectorBackgroundColor),
      41, uint(Theme::MiniProjectTargetSelectorBorderColor),
      42, uint(Theme::MiniProjectTargetSelectorSummaryBackgroundColor),
      43, uint(Theme::MiniProjectTargetSelectorTextColor),
      44, uint(Theme::OutputPaneButtonFlashColor),
      45, uint(Theme::OutputPaneToggleButtonTextColorChecked),
      46, uint(Theme::OutputPaneToggleButtonTextColorUnchecked),
      47, uint(Theme::PanelButtonToolBackgroundColorHover),
      48, uint(Theme::PanelTextColorLight),
      49, uint(Theme::PanelTextColorDark),
      50, uint(Theme::PanelsWidgetSeparatorLineColor),
      51, uint(Theme::PanelStatusBarBackgroundColor),
      52, uint(Theme::ProgressBarTitleColor),
      53, uint(Theme::ProgressBarColorError),
      54, uint(Theme::ProgressBarColorFinished),
      55, uint(Theme::ProgressBarColorNormal),
      56, uint(Theme::InfoBarBackground),
      57, uint(Theme::InfoBarText),
      58, uint(Theme::TextColorDisabled),
      59, uint(Theme::TextColorHighlight),
      60, uint(Theme::TextColorNormal),
      61, uint(Theme::TodoItemTextColor),
      62, uint(Theme::ToggleButtonBackgroundColor),
      63, uint(Theme::ToolBarBackgroundColor),
      64, uint(Theme::TreeViewArrowColorNormal),
      65, uint(Theme::TreeViewArrowColorSelected),
      66, uint(Theme::OutputFormatter_NormalMessageTextColor),
      67, uint(Theme::OutputFormatter_ErrorMessageTextColor),
      68, uint(Theme::OutputFormatter_StdOutTextColor),
      69, uint(Theme::OutputFormatter_StdErrTextColor),
      70, uint(Theme::OutputFormatter_DebugTextColor),
      71, uint(Theme::QtOutputFormatter_LinkTextColor),
      72, uint(Theme::Welcome_TextColorNormal),
      73, uint(Theme::Welcome_TextColorHeading),
      74, uint(Theme::Welcome_BackgroundColorNormal),
      75, uint(Theme::Welcome_DividerColor),
      76, uint(Theme::Welcome_Button_BorderColorNormal),
      77, uint(Theme::Welcome_Button_BorderColorPressed),
      78, uint(Theme::Welcome_Button_TextColorNormal),
      79, uint(Theme::Welcome_Button_TextColorPressed),
      80, uint(Theme::Welcome_Link_TextColorNormal),
      81, uint(Theme::Welcome_Link_TextColorActive),
      82, uint(Theme::Welcome_Link_BackgroundColor),
      83, uint(Theme::Welcome_Caption_TextColorNormal),
      84, uint(Theme::Welcome_SideBar_BackgroundColor),
      85, uint(Theme::Welcome_ProjectItem_TextColorFilepath),
      86, uint(Theme::Welcome_ProjectItem_BackgroundColorHover),
      87, uint(Theme::Welcome_SessionItem_BackgroundColorNormal),
      88, uint(Theme::Welcome_SessionItem_BackgroundColorHover),
      89, uint(Theme::Welcome_SessionItemExpanded_BackgroundColorNormal),
      90, uint(Theme::Welcome_SessionItemExpanded_BackgroundColorHover),
      92, uint(Theme::DetailsWidgetHeaderGradient),
      93, uint(Theme::Welcome_Button_GradientNormal),
      94, uint(Theme::Welcome_Button_GradientPressed),
      96, uint(Theme::ProjectExplorerHeader),
      97, uint(Theme::ProjectExplorerSource),
      98, uint(Theme::ProjectExplorerForm),
      99, uint(Theme::ProjectExplorerResource),
     100, uint(Theme::ProjectExplorerQML),
     101, uint(Theme::ProjectExplorerOtherFiles),
     102, uint(Theme::ProjectFileIcon),
     103, uint(Theme::IconOverlayCSource),
     104, uint(Theme::IconOverlayCppHeader),
     105, uint(Theme::IconOverlayCppSource),
     106, uint(Theme::IconOverlayPri),
     107, uint(Theme::IconOverlayPrf),
     108, uint(Theme::IconOverlayPro),
     109, uint(Theme::StandardPixmapFileIcon),
     110, uint(Theme::StandardPixmapDirIcon),
     112, uint(Theme::DrawTargetSelectorBottom),
     113, uint(Theme::DrawSearchResultWidgetFrame),
     114, uint(Theme::DrawProgressBarSunken),
     115, uint(Theme::DrawIndicatorBranch),
     116, uint(Theme::ComboBoxDrawTextShadow),
     117, uint(Theme::DerivePaletteFromTheme),
     118, uint(Theme::ApplyThemePaletteGlobally),
     120, uint(Theme::StyleDefault),
     121, uint(Theme::StyleFlat),

       0        // eod
};

void Theme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Theme::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Theme.data,
      qt_meta_data_Theme,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Theme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Theme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Theme.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Theme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ManhattanStyle_t {
    QByteArrayData data[9];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManhattanStyle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManhattanStyle_t qt_meta_stringdata_ManhattanStyle = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ManhattanStyle"
QT_MOC_LITERAL(1, 15, 26), // "standardIconImplementation"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 14), // "StandardPixmap"
QT_MOC_LITERAL(4, 58, 12), // "standardIcon"
QT_MOC_LITERAL(5, 71, 19), // "const QStyleOption*"
QT_MOC_LITERAL(6, 91, 6), // "option"
QT_MOC_LITERAL(7, 98, 14), // "const QWidget*"
QT_MOC_LITERAL(8, 113, 6) // "widget"

    },
    "ManhattanStyle\0standardIconImplementation\0"
    "\0StandardPixmap\0standardIcon\0"
    "const QStyleOption*\0option\0const QWidget*\0"
    "widget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManhattanStyle[] = {

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
       1,    3,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::QIcon, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,

       0        // eod
};

void ManhattanStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManhattanStyle *_t = static_cast<ManhattanStyle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QIcon _r = _t->standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])),(*reinterpret_cast< const QStyleOption*(*)>(_a[2])),(*reinterpret_cast< const QWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManhattanStyle::staticMetaObject = {
    { &QProxyStyle::staticMetaObject, qt_meta_stringdata_ManhattanStyle.data,
      qt_meta_data_ManhattanStyle,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ManhattanStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManhattanStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManhattanStyle.stringdata0))
        return static_cast<void*>(this);
    return QProxyStyle::qt_metacast(_clname);
}

int ManhattanStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProxyStyle::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
