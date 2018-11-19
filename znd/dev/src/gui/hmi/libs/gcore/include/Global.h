#ifndef _GLOBAL_H
#define _GLOBAL_H 

#include "Export.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "elog.h"

#define LOCAL_LANGUAGE "UTF-8"

const QString SYS_HOME = "SMARTSYS_HOME";


namespace Hmi
{
        enum ItemType {
        _START=QGraphicsItem::UserType,
        Group,
        Rect,
        Circle,
        Ellipse,
        Line,
        Polygon,
        Polyline,
        Symbol,
        Pin,
        Bus,
        Link,
        Icon,
        IconTest,
        Text,
		GraphicsText,
        Pixmap,
        Path,
        ClosePath,
        SvgItem,
        QtChart,
        PushButton,LineEdit,ComboBox,CheckBox,RadioButton,Label,ListWidget,
		Slider,ProgressBar,Dial,SpinBox,DateEdit,TimeEdit,
        CalendarWidget,AxWidget,CustomWidget,TreeWidget,TableWidget,TextBrowser,WebView,
		PieWidget, BarWidget, StockWidget, polarWidget, MenuBar, DoubleSpinBox, TextEdit, TabBar, TabWidget, GroupBox,
        ColorButton,FontButton,CheckCombobox,SwitchButton,TreeView,

        _END,
        };
		enum LINK_MODE
		{
			Normal = 0,
			Left2Right,//add 2 point at x middle
			Top2Bottom,//add 2 point at y middle
            One90angle, // add 1 point, 90 angle corner
            Draw2Mergin
		};

		enum SCENE_TYPE
		{
			Iconer = 1,
			Designer ,
			Explorer
		};
		enum WND_STYLE
		{
			NORMAL_STYLE = 0,
			TEMPLATE_STYLE ,
			FIXSIZE_STYLE ,
			GISEXCHANGE_STYLE ,
			BAYWND_STYLE ,
			CURVEWND_STYLE ,
			SIMPLE_STYLE
		};

		enum WND_PROP
		{
			WND_FIXSIZE=1,
			WND_FULLSCREEN=2,
			WND_NOBORDER=8,
			WND_ALLCTLBTN=16,
			WND_NOCTLBTN=32
		};

		enum ALIGN_STYLE
		{
			ALIGN_TOP = 1,
			ALIGN_BOTTOM ,
			ALIGN_LEFT ,
			ALIGN_RIGHT ,
			ALIGN_HORIZONTAL ,
			ALIGN_VERTICAL ,
			ALIGN_HORIZONTAL_SPACING ,
			ALIGN_VERTICAL_SPACING ,
			HORIZONTAL_MIRROR ,
			VERTICAL_MIRROR
		};

		enum CHANGE_POS_STYLE
		{
			CHANGE_POS_TOP = 1,
			CHANGE_POS_BOTTOM ,
			CHANGE_POS_UP ,
			CHANGE_POS_DOWN
		};

		enum MOVE_STYLE
		{
			MOVE_LEFT =0,
			MOVE_RIGHT ,
			MOVE_UP ,
			MOVE_DOWN ,
		};

		enum SELECT_STYLE
		{
			NO_TOOL = 0,
			SELECT_TOOL = 200,
			SELECTAREA_TOOL = 201,
			SELECTALL_TOOL = 202,
			SELECTALL_P_TOOL = 203,
			SELECTALL_Q_TOOL = 204,
			SELECTALL_I_TOOL = 205,
			SELECT_ALL_SAMETYPE = 206
		};

		enum SaveType{
			SVG = 0,
			PowerHmi
		};

		enum ARROW_STYLE
		{
			ARROW_NULL =0,
			ARROW_SOLID_ARROW,
			ARROW_HOLLOW_ARROW,
			ARROW_SOLID_BACKARROW,
			//ARROW_SOLID_CIRCLE,
			//ARROW_HOLLOW_CIRCLE ,
			ARROW_SOLID_DIAMOND,
			ARROW_HOLLOW_DIAMOND,
			ARROW_SOLID_RECT,
			ARROW_HOLLOW_RECT
		};
		enum ARROW_SIZE
		{
			ARROW_SIZE_10_8 =0,
			ARROW_SIZE_10_10,
			ARROW_SIZE_10_12,
		};
		enum ITEM_EFFECT
		{
			EFFECT_BlurEffect = 0,
			EFFECT_DropShadowEffect,
			EFFECT_ColorizeEffect,
			EFFECT_OpacityEffect,
			EFFECT_GlowEffect
		};
}



const int OSBIT_32 = 32;
const int OSBIT_64 = 64;

const char BYTE_HIGHTOLOW = 1;
const char BYTE_LOWTOHIGH = 0;

static char Sys_OsBit = OSBIT_32;

static char Sys_HighEndSeq = BYTE_LOWTOHIGH;

const float CORNER_RECTPAD = 2.5;

const int ACTIVE_RECTPAD = 2;

const int PLANE_COUNT = 32;

const int FILENAME_MAX_LENGTH = 32;


const QString PICSUFFIX =".svg";
const QString TOPOSUFFIX =".topo";
const QString ICONSUFFIX =".ivg";
const QString ICONPREFIX = "icon-";
const QString UIPREFIX = "ui-";
const QString PICBINARYSUFFIX = ".pic";


#ifdef _ELOG
    #define  gDebug     log_debug
    #define  gInfo      log_info
    #define  gWarn      log_warn
    #define  gError     log_error
    #define  gSensor    log_sensor
#else
    #define  gDebug     qDebug
    #define  gInfo      qInfo
    #define  gWarn      qDebug
    #define  gError     qCritical
    #define  gSensor    qDebug
#endif



#endif
