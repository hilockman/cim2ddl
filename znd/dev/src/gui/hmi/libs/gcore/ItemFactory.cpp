

#include "Global.h"
#include "GraphItem.h"
#include "GroupItem.h"
#include "WidgetItem.h"
#include "ItemFactory.h"
#include "IconMng.h"
#ifdef CHARTS
#include "GChartItem.h"
#endif

const QMap<int,QString> ItemFactory::TypeNameMap = ItemFactory::InitTypeName();
const QMap<int,QString> ItemFactory::TypeSaveNameMap= ItemFactory::InitTypeSaveName();

QMap<int,QString> ItemFactory::InitTypeSaveName()
{
    QMap<int,QString> tmpMap;
    tmpMap[Hmi::Rect] = "rect";
    tmpMap[Hmi::Ellipse] = "ellipse";
    tmpMap[Hmi::Circle] = "circle";
    tmpMap[Hmi::Line] = "line";
    tmpMap[Hmi::Polygon] = "polygon";
    tmpMap[Hmi::Polyline] = "polyline";
    tmpMap[Hmi::Group] = "g";
    tmpMap[Hmi::Symbol] = "g";
    tmpMap[Hmi::Text] = "text";
    tmpMap[Hmi::GraphicsText] = "text";
    tmpMap[Hmi::Link] = "polyline";
    tmpMap[Hmi::Pin] = "rect";
    tmpMap[Hmi::Path] = "path";
    tmpMap[Hmi::ClosePath] = "path";
    tmpMap[Hmi::Bus] = "line";
	tmpMap[Hmi::QtChart] = "rect";
    return tmpMap;
}
QMap<int,QString> ItemFactory::InitTypeName()
{
    QMap<int,QString> tmpMap;
    tmpMap[Hmi::Rect] = "rect";
    tmpMap[Hmi::Ellipse] = "ellipse";
    tmpMap[Hmi::Circle] = "circle";
    tmpMap[Hmi::Line] = "line";
    tmpMap[Hmi::Polygon] = "polygon";
    tmpMap[Hmi::Polyline] = "polyline";
    tmpMap[Hmi::Group] = "g";
    tmpMap[Hmi::Symbol] = "g";
    tmpMap[Hmi::Icon] = "icon";
    tmpMap[Hmi::Text] = "text";
	tmpMap[Hmi::GraphicsText] = "graphicsText";
    tmpMap[Hmi::SvgItem] = "svgItem";
    tmpMap[Hmi::QtChart] = "qtChart";
    tmpMap[Hmi::PushButton] = "ui-pushButton";
    tmpMap[Hmi::LineEdit] = "ui-lineEdit";
    tmpMap[Hmi::ComboBox] = "ui-comboBox";
    tmpMap[Hmi::CheckBox] = "ui-checkBox";
    tmpMap[Hmi::RadioButton] = "ui-radioButton";
    tmpMap[Hmi::Label] = "ui-label";
    tmpMap[Hmi::ListWidget] = "ui-listWidget";
    tmpMap[Hmi::Slider] = "ui-slider";
    tmpMap[Hmi::ProgressBar] = "ui-progressBar";
    tmpMap[Hmi::Dial] = "ui-dial";
    tmpMap[Hmi::SpinBox] = "ui-spinBox";
    tmpMap[Hmi::DateEdit] = "ui-dateEdit";
    tmpMap[Hmi::TimeEdit] = "ui-timeEdit";
    tmpMap[Hmi::TreeWidget] = "ui-treeWidget";
    tmpMap[Hmi::TableWidget] = "ui-tableWidget";
    tmpMap[Hmi::CalendarWidget] = "ui-calendarWidget";
    tmpMap[Hmi::PieWidget] = "ui-pieWidget";
    tmpMap[Hmi::BarWidget] = "ui-barWidget";
    tmpMap[Hmi::StockWidget] = "ui-stockWidget";
    tmpMap[Hmi::polarWidget] = "ui-polarWidget";
    tmpMap[Hmi::AxWidget] = "ui-axWidget";
    tmpMap[Hmi::CustomWidget] = "ui-customWidget";
    tmpMap[Hmi::TextBrowser] = "ui-textBrowser";
    tmpMap[Hmi::WebView] = "ui-webView";
    tmpMap[Hmi::MenuBar] = "ui-menuBar";
    tmpMap[Hmi::IconTest] = "iconTest";
    tmpMap[Hmi::Link] = "link";
    tmpMap[Hmi::Pin] = "pin";
    tmpMap[Hmi::Path] = "path";
    tmpMap[Hmi::ClosePath] = "closepath";
    tmpMap[Hmi::Bus] = "bus";
    tmpMap[Hmi::Pixmap] = "image";
    tmpMap[Hmi::DoubleSpinBox] = "ui-doubleSpinBox";
    tmpMap[Hmi::TextEdit] = "ui-textEdit";
    tmpMap[Hmi::TabBar] = "ui-tabBar";
    tmpMap[Hmi::TabWidget] = "ui-tabWidget";
	tmpMap[Hmi::GroupBox] = "ui-groupBox";
	tmpMap[Hmi::ColorButton] = "ui-colorButton";
	tmpMap[Hmi::FontButton] = "ui-fontButton";
	tmpMap[Hmi::CheckCombobox] = "ui-checkCombobox";
    tmpMap[Hmi::SwitchButton] = "ui-switchButton";
    tmpMap[Hmi::TreeView] = "ui-treeView";
    return tmpMap;
}

QGraphicsItem* ItemFactory::CreateItem(int tp, QGraphicsItem * parent ,QGraphicsScene * scene)
{
    if (tp >= Hmi::_END || tp <= Hmi::_START)
    {
        return NULL;
    }

    QGraphicsItem* item=NULL;
    switch (tp) {
    case Hmi::Line:
        item=new CLineItem(parent);
        break;
    case Hmi::Rect:
        item=new CRectItem(parent);
        break;
    case Hmi::Ellipse:
        item=new CEllipseItem(parent);
        break;
    case Hmi::Polyline:
        item=new CPolylineItem(parent);
        break;
    case Hmi::Polygon:
        item=new CPolygonItem(parent);
        break;
    case Hmi::Text:
        item=new CTextItem(parent);
        break;
	case Hmi::GraphicsText:
		item = new CGraphicsTextItem(parent);
		break;
    case Hmi::Group:
        item=new CGroupItem(parent);
        break;
    case Hmi::Pin:
        item=new CPinItem(parent);
        break;
    case Hmi::Bus:
        item=new CBusItem(parent);
        break;
    case Hmi::Link:
        item=new CLinkLineItem(parent);
        break;
    case Hmi::Path:
        item=new CPathItem(parent);
        break;
    case Hmi::ClosePath:
        item=new CClosePathItem(parent);
        break;
    case Hmi::Pixmap:
        item=new CPixmapItem(parent);
        break;
    case Hmi::SvgItem:
        item=new CSvgItem(parent);
        break;
    case Hmi::QtChart:
#ifdef CHARTS
        item = new CGChartItem(parent,scene);
#endif
        break;
    case Hmi::Icon:
        item = new CIconItem();
        break;
    default:
        if(Hmi::PushButton <= tp && tp < Hmi:: _END)
        {
            item=new CWidgetItem(tp,parent,scene);
        }
        break;
    }

    return item;

}

QGraphicsItem* ItemFactory::CreateItem(const QString& itemName, QGraphicsItem * parent ,QGraphicsScene * scene)
{
    QGraphicsItem* item=NULL;
    {
        int type=ItemFactory::ItemType(itemName);
        if (type>=0)
        {
            item = CreateItem(type, parent , scene);
        }
    }

    if (item)
    {



    }

    return item;
}


QString ItemFactory::ItemTypeName(int type)
{
    QString typeName;
    typeName=TypeNameMap[type];
    return typeName;
}
QString ItemFactory::ItemTypeSaveName(int type)
{
    QString typeName;
    typeName=TypeSaveNameMap[type];
    return typeName;
}

int ItemFactory::ItemType(const QString& typeName)
{

    if (typeName.startsWith(ICONPREFIX))
        return Hmi::Icon;
    else
        return TypeNameMap.key(typeName,-1);
}
