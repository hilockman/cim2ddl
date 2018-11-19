
#include "Global.h"
#include "GraphScene.h"
#include "GFunc.h"
#include "Colorbutton.h"
#include "widgets/qxtcheckcombobox.h"
#include "ItemFactory.h"
#include "CQScriptWrap.h"
#include "CQWidgetWrap.h"
#include "GraphSvgRW.h"
#include "IPluginWidget.h"
#include "WidgetItem.h"
#include <QUiLoader>
#ifdef CHARTS
#include <QtCharts/QLineSeries>
#include <QtCharts>
#endif
#ifdef KDCHART
#include "ChartWrap.h"
#include "widgets/ChartPropertyDlg.h"
#endif

#ifdef QML
#include <QQuickWidget>
#include <QQuickView>
#include <QQuickItem>
#endif

#ifdef WIN32
#include <QAxWidget>
#endif

#ifdef WEBVIEW
#include <QWebEngineView>
#endif


CWidgetData::CWidgetData(QGraphicsItem* item):CBaseData(item)
{
    SetItem(item);
}

void CWidgetData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CWidgetItem* pItem=(CWidgetItem*)Item();
    QWidget* pwidget= pItem->Widget();

	xio->WriteAttribute("xlink:href",pItem->m_PixmapName);
    xio->WriteAttribute("text",pItem->m_Text);
	xio->WriteAttribute("", pItem->Font(), Hmi::SVG);//font
    xio->WriteAttribute("ocx",pItem->m_OcxName);
    xio->WriteAttribute("rect",pItem->Rect().toRect());
    xio->WriteAttribute("float",pItem->m_IfFloat);
	xio->WriteAttribute("icon", pItem->m_Icon);
	xio->WriteAttribute("iconSize", pItem->m_IconSize);
    if (pItem->m_pPluginWidget)
    {
        QString str=pItem->m_pPluginWidget->GetObjJsonString();
        str.replace('"','!');
        xio->WriteAttribute("plugin-info",str);
    }

    foreach (const QString &propname, m_DirtyProp)
    {
		xio->writeAttribute("QT", propname, pwidget->property(propname.toLocal8Bit().data()).toString());
    }

    CBaseData::SaveBaseProperty(xio);
}

void CWidgetData::LoadBaseProperty(CGraphSvgReader* xio)
{
    QRectF rc;
    QString plugin_info;
	CWidgetItem* pItem=(CWidgetItem*)Item();
    xio->ReadAttribute("xlink:href",pItem->m_PixmapName);
    xio->ReadAttribute("text",pItem->m_Text);
	xio->ReadAttribute("", pItem->m_Font, Hmi::SVG); pItem->SetFont(pItem->m_Font);
    xio->ReadAttribute("ocx",pItem->m_OcxName);
    xio->ReadAttribute("rect",rc);
    xio->ReadAttribute("float",pItem->m_IfFloat);
    xio->ReadAttribute("plugin-info",plugin_info);
	QString tmpstr;
	xio->ReadAttribute("iconSize", tmpstr);
	if (!tmpstr.isEmpty())
	{
		QSize icSize = QSize(tmpstr.split(",").first().toInt(), tmpstr.split(",").last().toInt());
		pItem->SetIconSize(icSize);
	}
	tmpstr = "";
	xio->ReadAttribute("icon", tmpstr);
	pItem->SetIcon(tmpstr);

    CBaseData::LoadBaseProperty(xio);

    QWidget* pwidget= pItem->Widget();
	QVariantMap attrs = xio->ReadAttributes("QT");
    foreach (const QString &attrName, attrs.keys())
    {
		int ty = pwidget->property(attrName.toLocal8Bit().data()).type();
        /*QVariant vv = QVariant(attrs.value(attrName));
		if (vv.canConvert(ty))
		{
			pwidget->setProperty(attrName.toLocal8Bit().data(), vv.convert(ty));
            ty=vv.type();
            QString gg=vv.typeName();
        }*/

        if(attrName=="url"){
			QString surl = attrs.value(attrName).toString(); gInfo(surl.toLocal8Bit().data());
            if(surl.startsWith("file:")){
                QString fn;
                UnqFunc()->GetGraphNameByGraphPathName(surl,fn);
                surl="file:///"+UnqFunc()->GetDir(CGFunc::PATH_TYPE_DATA)+"html"+QDir::separator()+fn;
                surl.replace("\\","/");
            };
            gInfo(surl.toLocal8Bit().data());
            pwidget->setProperty(attrName.toLocal8Bit().data(),surl);
        }
        else if (ty == QVariant::Int)//enum type
            pwidget->setProperty(attrName.toLocal8Bit().data(),attrs.value(attrName).toInt());
        else
            pwidget->setProperty(attrName.toLocal8Bit().data(),attrs.value(attrName));


        if(attrName=="icon")
			pItem->SetIcon(attrs.value(attrName).toString());
        m_DirtyProp.insert(attrName);
    }


    pItem->InitSettings();
    if (pItem->m_OcxName.right(4)==".qml")
    {
       // pItem->SetIsQmlWidget(true);
    }

    pItem->setGeometry(rc);


    if (!plugin_info.isEmpty() && pItem->m_pPluginWidget)
    {
        plugin_info.replace('!', '"');
        pItem->m_pPluginWidget->SetObjJsonString(plugin_info);
    }
}

QGraphicsItem* CWidgetData::Clone()
{
    CWidgetItem* pitem=(CWidgetItem*)Item();
    CWidgetItem* pNewItem = new CWidgetItem(pitem->widgetType());
    g_dataPtr(pNewItem)->Copy( this);
    return pNewItem;
}

void CWidgetData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    CWidgetItem* pitem=(CWidgetItem*)Item();
    CWidgetItem* psrcitem=(CWidgetItem*)srcData->Item();
    pitem->SetControl(psrcitem->GetControl());
    pitem->resize(psrcitem->size());
    QWidget* pwidget= pitem->Widget();
    QWidget* psrcWidget= ((CWidgetItem*)srcData->Item())->Widget();

    foreach (const QString &prop, m_DirtyProp)
    {
        char* pname=prop.toLocal8Bit().data();
        pwidget->setProperty(pname , psrcWidget->property(pname));
    }

}

void CWidgetData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
   // CBaseData::GetPropertyList( property_list);
    CWidgetItem* pitem=(CWidgetItem*)Item();

    property_list.push_back( qMakePair( QString(CBaseData::tr("name")) ,QVariant(GetName()) ) );
    property_list.push_back( qMakePair( QString(CBaseData::tr("opacity")) ,QVariant(m_pItem->opacity() ) ) );
    property_list.push_back( qMakePair( QString(CBaseData::tr("postion")) ,QVariant(m_pItem->pos() ) ) );
    property_list.push_back( qMakePair( QString(CBaseData::tr("rotation")) ,QVariant(GetOrgRotation() ) ) );
    property_list.push_back( qMakePair( QString(CBaseData::tr("userData")) ,QVariant(GetUserData() ) ) );
    property_list.push_back( qMakePair( QString(CBaseData::tr("plane")) ,QVariant(GetPlane()) ) );

    property_list.push_back( qMakePair( CBaseData::tr("ocx"),QVariant(pitem->m_OcxName ) ));
    property_list.push_back( qMakePair( CBaseData::tr("width") ,QVariant(pitem->size().width() ) ));
    property_list.push_back( qMakePair( CBaseData::tr("height") ,QVariant(pitem->size().height() ) ));
// property_list.push_back( qMakePair( CBaseData::tr("text") ,QVariant(pitem->m_Text ) ));
    //property_list.push_back( qMakePair( CBaseData::tr("tip") ,QVariant(pitem->m_Tip) ));
    property_list.push_back( qMakePair( CBaseData::tr("float") ,QVariant(pitem->m_IfFloat) ));
    int objtype=pitem->widgetType();
/*    if (objtype==Hmi::PushButton ||objtype==Hmi::Label)
    {
        QWidget* tbtn= pitem->Widget();
        if(tbtn->inherits("QToolButton"))

        {
            property_list.push_back(qMakePair( CBaseData::tr("toolButtonStyle"),QVariant(((QToolButton*)tbtn)->toolButtonStyle()  )));
        }
        QString tempstr="QFile--"+pitem->m_Icon;
        property_list.push_back(qMakePair( CBaseData::tr("icon"),QVariant(tempstr) ));
        property_list.push_back(qMakePair( CBaseData::tr("iconSize"),QVariant(pitem->m_IconSize) ));
        property_list.push_back(qMakePair( CBaseData::tr("keys"),QVariant(pitem->m_ShortCut ) ));
    }*/
   /* if(objtype==Hmi::ComboBox ||objtype==Hmi::ListWidget)
    {
        property_list.push_back(qMakePair( CBaseData::tr("ds"),QVariant(pitem->m_Ds) ));
        property_list.push_back(qMakePair( CBaseData::tr("dsType"),QVariant(pitem->m_DsType) ));
    }*/
    if(pitem->m_pPluginWidget)
        pitem->m_pPluginWidget->GetPropertyList(property_list);

}

void CWidgetData::GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList)
{
    QList< QPair<QString,QVariant> > propertylist;
    CWidgetItem* pitem=(CWidgetItem*)Item();
	int type = pitem->widgetType();
    GetPropertyList(propertylist);
    QString splitname=ItemFactory::ItemTypeName( type);

    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >(splitname,propertylist));
    propertylist.clear();
    const QMetaObject* metaobject = pitem->Widget()->metaObject();
    propertylist.push_back( qMakePair( QString("font") ,QVariant(pitem->m_Font ) ));
    int count = metaobject->propertyCount();

    for (int i=0; i<count; ++i)
    {
        QMetaProperty metaproperty = metaobject->property(i);
        const char* name = metaproperty.name();
        if( QWidget::staticMetaObject.indexOfProperty(name)<0|| strcmp(name,"styleSheet")==0)
        {
			propertylist << qMakePair(name, pitem->Widget()->property(name));
        }
    }
    QString className=metaobject->className();
    if(className.left(2)=="CG")
        className.remove(0, 2);
    else if(className.left(1)=="Q")
        className.remove(0, 1);
    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >(className,propertylist));
    propertylist.clear();
	foreach(QByteArray barray, pitem->Widget()->dynamicPropertyNames())
		propertylist << qMakePair(QString(barray), pitem->Widget()->property(barray.data()));

    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >("custom property",propertylist));

}
bool CWidgetData::SetProperty(const QString& propname,const QVariant& value)
{
    bool ret=false;
    CWidgetItem* pitem=(CWidgetItem*)Item();
    QWidget* pwidget= pitem->Widget();

    if (propname == "size" || propname == CBaseData::tr("size")  )
    {
        pitem->Widget()->resize(value.toSize());
    }
    else if ( propname == "width" || propname == CBaseData::tr("width")  )
    {
        QSize size=pitem->Widget()->size();
        size.setWidth(value.toFloat());
        pitem->Widget()->resize(size);
    }
    else if ( propname == "height" || propname == CBaseData::tr("height")  )
    {
        QSize size=pitem->Widget()->size();
        size.setHeight(value.toFloat());
        pitem->Widget()->resize(size);
    }
    else if (propname==CBaseData::tr("text")||propname== "text" )
    {
        pitem->SetText(value.toString());
    }
    else if (propname == CBaseData::tr("font") || propname == "font")
    {
        QFont font = qvariant_cast<QFont>(value);
        pitem->SetFont(font);
    }
    else if (propname == CBaseData::tr("ocx") || propname == "ocx")
    {
        pitem->SetControl(value.toString());
    }
    else if (propname == CBaseData::tr("css") || propname == "css")
    {
        pitem->SetStyleSheet(value.toString());
    }
    else if (propname == CBaseData::tr("tip") || propname == "tip")
    {
        pitem->SetTip(value.toString());
    }
    else if (propname == CBaseData::tr("iconSize") || propname == "iconSize")
    {
        QSize size = qvariant_cast<QSize>(value);
        pitem->SetIconSize(size);
    }
    else if (propname == CBaseData::tr("icon") || propname == "icon")
    {
        pitem->SetIcon(value.toString());
    }
    else if (propname == CBaseData::tr("keys") || propname == "keys")
    {
        pitem->SetShortCut(value.toString());
    }
    else if (propname == CBaseData::tr("fillColor") || propname == "fillColor")
    {
        QColor color = qvariant_cast<QColor>(value);
        int tempcolor=color.rgb();

        int temcolor1;
        pitem->SetStyleColor(tempcolor,temcolor1);
    }
    else if (propname == CBaseData::tr("lineColor") || propname == "lineColor")
    {
        QColor color = qvariant_cast<QColor>(value);
        // 		m_pShape->SetLineColor(tempcolor1);
        // 		int temcolor=m_pShape->GetFillColor();
        // 		m_pShape->SetStyleColor(temcolor,tempcolor1);
    }
    else if (propname == CBaseData::tr("fillStyle") || propname == "fillStyle")
    {
        QBrush brush = qvariant_cast<QBrush>(value);
    }
    /*else if (propname == CBaseData::tr("ds") || propname == "ds")
    {
        pitem->m_Ds = value.toString();
    }
    else if (propname == CBaseData::tr("dsType") || propname == "dsType")
    {
        pitem->m_DsType = value.toInt();
    }*/
    else if (propname == CBaseData::tr("float") || propname == "float")
    {
        pitem->m_IfFloat = value.toBool();
    }
    else if (propname==CBaseData::tr("opacity")||propname== "opacity" )
    {
        pitem->setOpacity(value.toReal());
    }
    else if (propname==CBaseData::tr("postion")||propname== "postion" )
    {
        pitem->setPos(value.toPointF());
    }
    else if (propname==CBaseData::tr("rotation")||propname== "rotation" )
    {
        SetOrgRotation(value.toReal());
        ApplyScaleProperty(pitem, value.toReal(), GetOrgScaleX(), GetOrgScaleY(), m_pItem->boundingRect().center());
    }
    else if (propname==CBaseData::tr("plane")||propname== "plane" )
    {
        SetPlane(value.toInt());
    }
    else if (propname==CBaseData::tr("name")||propname== "name" )
    {
        QString name=value.toString();
        name.replace("-","");
        SetName(name);
    }
    else
    {
        if(pitem->m_pPluginWidget)
        {
            ret=pitem->m_pPluginWidget->SetProperty(propname, value);
        }

        if(!ret)
        {
            ret=pwidget->setProperty( propname.toLocal8Bit().data(), value);
            m_DirtyProp.insert(propname);
        }
    }



    return true;
}

QVariant CWidgetData::Property(QString name, bool allprop)
{
	QVariant val = CBaseData::Property(name, allprop);
	if (!val.isValid())
	{
		CWidgetItem* pitem = (CWidgetItem*)Item();
		if (pitem->widget())
			return pitem->widget()->property(name.toLocal8Bit().data());
	}
	return val;
}

void CWidgetData::SetName(const QString& newName)
{
    CWidgetItem* pItem = (CWidgetItem*)Item();
    pItem->SetObjName(newName);
    CBaseData::SetName( newName );
}

void CWidgetData::SetWidget(QObject *widget,int wndflag)
{
    CWidgetItem* pItem = (CWidgetItem*)Item();
    if(wndflag>0)
        pItem->setWindowFlags((Qt::WindowFlags) wndflag);

    pItem->SetWidget((QWidget*)widget);
}

QObject* CWidgetData::Widget()
{
	CWidgetItem* pItem = (CWidgetItem*)Item();
	return pItem->widget();
}

CWidgetItem::CWidgetItem(int type, QGraphicsItem *parent,QGraphicsScene * scene , Qt::WindowFlags wFlags )
    : QGraphicsProxyWidget(parent, wFlags), m_type(type), m_pScene(scene)
{
    m_pScene=scene;
    m_IfDesigner=IfDesigner();
    m_IfFloat=false;
    SetIgnoreEvent(m_IfDesigner);
    setAcceptDrops(true);
    Init(parent , scene , wFlags);

}

void CWidgetItem::Init(QGraphicsItem *parent,QGraphicsScene* scene , Qt::WindowFlags wFlags )
{
    m_pData=NULL;
    m_pParent = NULL;
    m_widget = NULL;
    m_StyleSheet="";
    m_pPluginWidget=NULL;
    m_IconSize=QSize(30,30);
    m_Font_flag=true;
    QWidget* tmpWidget=NULL;
    switch (m_type) {
    case Hmi::PushButton:
        tmpWidget=new CGPushButton("OK");
        tmpWidget->resize(75,23);
        break;
    case Hmi::LineEdit:
        tmpWidget=new CGLineEdit();
        break;
    case Hmi::TextEdit:
        tmpWidget = new CGTextEdit();
        break;
    case Hmi::ComboBox:
        tmpWidget=new CGComboBox();
        break;
    case Hmi::CheckBox:
        tmpWidget=new QCheckBox("CheckBox");
        break;
    case Hmi::RadioButton:
        tmpWidget=new QRadioButton("Radio");
        break;
    case Hmi::Label:
        tmpWidget=new CGLabel("label");
        break;
    case Hmi::ListWidget:
        tmpWidget=new CGListWidget();
        break;
    case Hmi::Slider:
        tmpWidget=new QSlider(Qt::Horizontal);
        break;
	case Hmi::ProgressBar:
		tmpWidget = new CGProgressBar();
		break;
    case Hmi::Dial:
        tmpWidget=new QDial();
        break;
    case Hmi::SpinBox:
        tmpWidget=new CGSpinBox();
        break;
    case Hmi::DoubleSpinBox:
        tmpWidget = new CGDoubleSpinBox();
        break;
    case Hmi::DateEdit:
        tmpWidget=new CGDateEdit();
        break;
    case Hmi::TimeEdit:
		tmpWidget = new CGTimeEdit();
        break;
    case Hmi::TreeWidget:
        tmpWidget=new CGTreeWidget();
        break;
    case Hmi::TableWidget:
        tmpWidget=new CGTableWidget();
        break;
    case Hmi::CalendarWidget:
		tmpWidget = new CGCalendarWidget();
        break;
    case Hmi::MenuBar:
        tmpWidget=new CGMenuBar();
        break;
    case Hmi::CustomWidget:
        tmpWidget=CreateCustomWidget("QPushButton");
        break;
    case Hmi::TextBrowser:
        tmpWidget=new CGTextBrowser();
        break;
    case Hmi::TabBar:
        tmpWidget=new CGTabBar();
        break;
    case Hmi::TabWidget:
        tmpWidget=new CGTabWidget();
        break;
	case Hmi::GroupBox:
	    tmpWidget = new QGroupBox("GroupBox");
	    break;
	case Hmi::ColorButton:
		tmpWidget = new ColorButton();
		break;
	case Hmi::FontButton:
		tmpWidget = new CGFontEditWidget();
		break;
	case Hmi::CheckCombobox:
		tmpWidget = new QxtCheckComboBox();
		break;
    case Hmi::SwitchButton:
        tmpWidget = new QSwitchButton();
        break;
    case Hmi::TreeView:
        tmpWidget = new CGTreeView();
        break;
#ifdef WIN32
    case Hmi::AxWidget:
    {
        tmpWidget=new QAxWidget();
        break;
    }
#endif
#ifdef WEBVIEW
    case Hmi::WebView:
    {
        tmpWidget=new CGWebView();
        break;
    }
#endif
#ifdef KDCHART
    case Hmi::PieWidget:
    {
        CPieChartWidget* w =new CPieChartWidget();
        CPieChartData* d = new CPieChartData(this);
        d->SetChartWidget(w);
        m_pData = d;
        tmpWidget = w;
        break;
    }
    case Hmi::BarWidget:
    {
        CBarChartWidget* w =new CBarChartWidget();
        CBarChartData* d = new CBarChartData(this);
        d->SetChartWidget(w);
        m_pData = d;
        tmpWidget = w;
    }
        break;
    case Hmi::StockWidget:
    {
        CStockChartWidget* w =new CStockChartWidget();
        CStockChartData* d = new CStockChartData(this);
        d->SetChartWidget(w);
        m_pData = d;
        tmpWidget = w;
    }
        break;
#endif

    default:
        tmpWidget=new CGPushButton();
        tmpWidget->setCursor(Qt::PointingHandCursor);
        m_type=Hmi::PushButton;
        break;
    }

    tmpWidget->setAttribute(Qt::WA_SetCursor, false);
    SetWidget(tmpWidget);

    if(!m_pData)
    {
        m_pData=new CWidgetData(this);
    }
    g_SetData(this,m_pData);
    setAcceptDrops(true);
	m_widget->setMinimumSize(0,0);
    setMinimumSize(0, 0);
	m_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
CWidgetItem::~CWidgetItem()
{
    m_widget->setVisible(false); //这句话非常重要，否者findFocusChild有些异常
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }

    if(!m_IfDesigner && (m_type==Hmi::WebView ||   m_IfFloat ) && m_widget   )
    {
		try{
			delete m_widget;
			m_widget=NULL;
		}
		catch (...)
		{
			m_widget = NULL;
            gError("---------CWidgetItem::~CWidgetItem- %s--error",m_OcxName.toLocal8Bit().data());
		}       
    }
}

bool CWidgetItem::IfDesigner()
{
    bool if_edit_mode=true;
    m_pScene =( scene() == NULL ? m_pScene : scene());
    if (m_pScene && ((CGraphScene*)m_pScene)->GetSceneType()==Hmi::Explorer )//("sceneType_explorer" == m_pScene->property("sceneType").toString()))
    {
        if_edit_mode=false;
    }
    return if_edit_mode;
}

QRectF CWidgetItem::boundingRect() const
{
    return QGraphicsProxyWidget::boundingRect().adjusted(-CORNER_RECTPAD, -CORNER_RECTPAD, CORNER_RECTPAD, CORNER_RECTPAD);
}

void CWidgetItem::highlightSelected( QPainter *painter, const QStyleOptionGraphicsItem *option)
{
    QPointF CORNER_POINT(CORNER_RECTPAD, CORNER_RECTPAD);
    QBrush b(QColor(Qt::blue), Qt::SolidPattern);
    QPen p(b, 1, Qt::SolidLine);
    painter->setBrush(b);
    painter->setPen(p);
    QPolygon points(QGraphicsProxyWidget::boundingRect().toRect());
    for(int i=0; i<points.size(); ++i)
    {
        painter->drawRect(QRectF(points[i]-CORNER_POINT, points[i]+CORNER_POINT));
    }

}
void CWidgetItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsProxyWidget::paint(painter, option, widget);

    QRectF tmprect = painter->worldMatrix().mapRect(rect());

    SetShapeGeometry( tmprect);
    if (m_IfDesigner&&(option->state & QStyle::State_Selected))
    {
        QVector<QPointF> vec;
		vec.reserve(8);
		qreal w = rect().width();
		qreal h = rect().height();
		vec << rect().topLeft() << rect().topRight() << rect().bottomLeft() << rect().bottomRight() << rect().topLeft() + QPointF(w / 2, 0) << rect().topLeft() + QPointF(0, h / 2) << rect().topRight() + QPointF(0, h / 2) << rect().bottomLeft() + QPointF(w / 2, 0);
        g_PaintBoundingRect(scene(),painter, option, boundingRect());
        g_HighlightSelected(scene(),painter, option,vec,CORNER_RECTPAD, false, Qt::cyan);
    }

}


QWidget* CWidgetItem::CreateCustomWidget(QString name)
{
    m_pScene = (scene() == NULL ? m_pScene : scene());
    if(!m_pScene)
    {
       //return new QPushButton("Load error!",m_pParent);
    }
    if(name=="QPushButton") {
        return new QPushButton("Load QPushButton!",NULL);
    }

	QString path = UnqFunc()->GetDir(CGFunc::PATH_TYPE_DLL);
    if (name.right(3) == ".ui" || name.right(4) == ".sui")
    {
        QUiLoader loader;
        QString tmpfn;
        UnqFunc()->GetGraphPathNameByGraphName(name, tmpfn);
        QFile file(tmpfn);
        file.open(QFile::ReadOnly);
        QWidget *customWidget = loader.load(&file, m_pParent);
        file.close();
        if (customWidget == NULL)
        {
            customWidget = new QPushButton("No find custom widget!", m_pParent);
        }
        return customWidget;
    }
#ifdef QML
    else if (name.right(4) == ".qml" || name.right(4) == ".sml")
    {

        m_IfFloat=true;
        UnqFunc()->GetGraphPathNameByGraphName(name, path);

        CQmlEngine* pQmlEngine =( m_pScene==NULL ? 0 : ((CGraphScene*)m_pScene)->GetQmlEngine() );
        QQuickWidget* qmlwidget=new QQuickWidget(pQmlEngine,0);
        if (m_pScene)
        {
            m_pScene->addItem(this);
        }
        qmlwidget->setSource(QUrl::fromLocalFile(path));
        qmlwidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
        setSelected(true);
        return qmlwidget;
    }
#endif

	QString fileName = name;
#ifndef WIN32
	if (name.contains(QRegExp("^lib")))
		fileName = name;
	else
	{
		name.replace(".dll", ".so");
		fileName = "lib" + name;
	}
#endif

	QWidget* customWidget = NULL;
    try
    {
		QString pluginsFile = path + QDir::separator() + fileName;
        m_pParent=NULL;
		QPluginLoader loader(pluginsFile);
        QObject *plugin = loader.instance();
        if (plugin)
        {
            PluginWidgetFactoryInterface *m_pPlugInInterface = qobject_cast<PluginWidgetFactoryInterface *>(plugin);
            if (m_pPlugInInterface)
            {
                std::vector<void*> ptr_vect;

                QWidget* parent=0;
                //if(m_pScene)
                    //parent= m_pScene->views().first();
                bool ret=m_pPlugInInterface->CreateWidget(parent,&customWidget,&m_pPluginWidget,ptr_vect,m_IfDesigner);
				if (!ret)
				{
                    gInfo("CWidgetItem::CreateWidget fail.pluginsFile:%s", pluginsFile.toLocal8Bit().data());
				}
				else
				{
                    gInfo("CWidgetItem::CreateWidget success.pluginsFile:%s", pluginsFile.toLocal8Bit().data());
				}

            }
			else
			{
                gInfo("CWidgetItem::CreateWidget fail.m_pPlugInInterface is null.pluginsFile:%s", pluginsFile.toLocal8Bit().data());
			}
        }
        else
        {
            gInfo("CWidgetItem::CreateCustomWidget fail.plugin is null. pluginsFile:%s", pluginsFile.toLocal8Bit().data());
        }

        if (!customWidget)
        {
            customWidget=new QPushButton("No find custom widget!",m_pParent);
            //log_printf(LOG_ERROR, 23002,"---CWidgetShape::CreateCustomWidget()--error--%s",fileName.toLocal8Bit().data());
        }
        return customWidget;
    }
    catch (...)
    {
        customWidget=new QPushButton("Load error!",m_pParent);
        //log_printf(LOG_ERROR, 23003,"---CWidgetShape::CreateCustomWidget()--try catch error--%s",fileName.toLocal8Bit().data());
        return customWidget;
    }
}

void CWidgetItem::InitSettings()
{
    SetPixmap(m_PixmapName);
    SetText(m_Text);
    SetControl(m_OcxName);
    SetIcon(m_Icon);
    SetIconSize(m_IconSize);
    SetTip(m_Tip);
    SetStyleSheet(m_StyleSheet);
}

void CWidgetItem::SetObjName(const QString& name)
{
    if (m_widget)
    {
        m_widget->setObjectName(name );
        if (m_widget->inherits("QAbstractButton"))
        {

        }
    }
}

void CWidgetItem::SetPixmap ( const QString & name)
{
    if (m_widget)
    {

    }
}
void CWidgetItem::SetText ( const QString & text)
{
    m_Text=text;
    if (m_widget)
    {
        if(m_Font_flag)
            m_widget->setFont(m_Font);
        if (text.isEmpty())
			return;
        if(m_widget->inherits("QComboBox"))
        {
            QComboBox* pcombox=(QComboBox*)m_widget;
            QStringList strlist=text.split(';');
            pcombox->clear();
            if (!text.isEmpty())
                pcombox->insertItems(0,strlist);
        }
        else if (m_widget->inherits("QListWidget"))
        {
            QListWidget* plistbox=(QListWidget*)m_widget;
            QStringList strlist=text.split(';');
            plistbox->clear();
            if (!text.isEmpty())
                plistbox->addItems(strlist);
        }
        else if (m_widget->inherits("QLineEdit"))
        {
            ((QLineEdit*)m_widget)->setText(text);
        }
        else if (m_widget->inherits("QTextEdit"))
        {
            ((QTextEdit*)m_widget)->setText(text);
        }
        else if (m_widget->inherits("QLabel"))
        {
            ((QLabel*)m_widget)->setText(text);
        }
        else if (m_widget->inherits("QAbstractButton"))
        {
            ((QAbstractButton*)m_widget)->setText(text);
        }
  
    }
}

void CWidgetItem::SetStyleSheet(const QString & sheet)
{
    m_StyleSheet=sheet;
    if (m_widget && !sheet.isEmpty())
        m_widget->setStyleSheet(sheet);
}

QRectF CWidgetItem::Rect()
{
    QRectF rc=subWidgetRect( Widget());
    return rc;
}

void CWidgetItem::SetWidget(QWidget *widget)
{
    if(m_widget==widget)
        return;
    QWidget *oldwidget=m_widget;
    m_widget=widget;
    if ((m_IfFloat || m_type==Hmi::WebView) && (!m_IfDesigner) && m_widget )
    {
        QWidget *parent = (QWidget *)(((QAbstractScrollArea *)m_pScene->views().first())->viewport());
        m_widget->setParent(parent);
        m_widget->show();
        setWidget(0);
    }
    else
    {
        setWidget(widget);
    }

    if (oldwidget)
    {
        delete oldwidget;
    }
}

void CWidgetItem::SetControl(QString ocx_name)
{
    m_OcxName=ocx_name;
#ifdef WIN32
	if (m_type == Hmi::AxWidget)
    {
        ((QAxWidget*)m_widget)->setControl(ocx_name);
    }
#endif
	if (m_type == Hmi::CustomWidget)
    {
        SetWidget(CreateCustomWidget(ocx_name));
    }
	else if (m_type == Hmi::PushButton || m_type == Hmi::Label)
    {
        SetIcon(ocx_name);
    }

}

void CWidgetItem::SetShapeGeometry( QRectF& rect)
{
	if ((m_IfFloat || m_type == Hmi::WebView) && !m_IfDesigner)
    {
        if (rect.width() == 0)
            rect = this->geometry();

        if (m_OldRect.size() == rect.size())
            return;

        m_widget->setGeometry( rect.toRect());
        m_OldRect=rect;
    }
}


void CWidgetItem::SetIcon(const QString & icon)
{
    if (icon.isEmpty())
        return;

    m_Icon=icon;
    if (m_widget )
    {
        QString iconbuf;
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, icon, iconbuf);
        if(m_widget->inherits("CGPushButton"))
        {
            ((CGPushButton*)m_widget)->SetIcon( iconbuf );
        }
        else if (m_widget->inherits("QLabel"))
        {
            if (icon.isEmpty())
                ((CGLabel*)m_widget)->setText(m_Text);
            else
                ((CGLabel*)m_widget)->SetPixmap(iconbuf);
		}
		else if(m_widget->inherits("QAbstractButton"))
			((QAbstractButton*)m_widget)->setIcon(QIcon(iconbuf));
	}
}
void CWidgetItem::SetIconSize(const QSize & size)
{
    m_IconSize=size;
    if (m_widget)
    {
        if(m_widget->inherits("QAbstractButton"))
        {
            ((QAbstractButton*)m_widget)->setIconSize(size);
        }
    }
}

void CWidgetItem::SetShortCut(QString key)
{
    m_ShortCut=key;
    if (m_widget)
    {
        if(m_widget->inherits("QAbstractButton"))
        {
            ((QAbstractButton*)m_widget)->setShortcut(key);
        }
    }
}

void CWidgetItem::SetTip(const QString & tip)
{
    m_Tip=tip;
    QString tmpstr=tip;
    if (m_widget && !tip.isEmpty())
    {
        m_widget->setToolTip(tmpstr);
    }
}

void CWidgetItem::SetStyleColor(int color1,int color2)
{
    QColor c1=QColor(color1);
    QColor c2=QColor(color2);
    QString style=QString("background-color:rgb(%1,%2,%3);\n").arg(c1.red()).arg(c1.green()).arg(c1.blue());
    style=style+QString("color:rgb(%1,%2,%3);").arg(c2.red()).arg(c2.green()).arg(c2.blue());
    m_widget->setStyleSheet(style);
}

void CWidgetItem::SetFont(const QFont & font)
{
    m_Font=font;
	if (m_widget && !m_Font.family().isEmpty())
	{
		if (m_Font_flag)
			m_widget->setFont(m_Font);
	}
}

void CWidgetItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if(IsIgnoreEvent())
        QGraphicsItem::contextMenuEvent(event);
    else
        QGraphicsProxyWidget::contextMenuEvent(event);
}

void CWidgetItem::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    if(IsIgnoreEvent())
        QGraphicsItem::mousePressEvent(event);
    else
        QGraphicsProxyWidget::mousePressEvent(event);
}

void CWidgetItem::mouseMoveEvent( QGraphicsSceneMouseEvent * event )
{
    if(IsIgnoreEvent())
        QGraphicsItem::mouseMoveEvent(event);
    else
        QGraphicsProxyWidget::mouseMoveEvent(event);
}

void CWidgetItem::mouseReleaseEvent( QGraphicsSceneMouseEvent * event )
{
    if(IsIgnoreEvent())
    {
        QGraphicsItem::mouseReleaseEvent(event);
    }
    else
        QGraphicsProxyWidget::mouseReleaseEvent(event);

}

void CWidgetItem::hoverMoveEvent( QGraphicsSceneHoverEvent *event )
{
    if(IsIgnoreEvent())
        QGraphicsItem::hoverMoveEvent(event);
    else
        QGraphicsProxyWidget::hoverMoveEvent(event);
}

void CWidgetItem::mouseDoubleClickEvent( QGraphicsSceneMouseEvent *event )
{
    if(IsIgnoreEvent())
    {

        if(m_widget->inherits("QQuickWidget"))
        {
#ifdef QML
            QVariant ret;
            QObject *root_obj = ((QQuickWidget* )(m_widget))->rootObject() ;
            if (root_obj)
            {
                bool isOK = QMetaObject::invokeMethod(root_obj, "chartConfig", Q_RETURN_ARG(QVariant, ret));
                if (!isOK)
                    return;
            }
#endif
        }
        else
        {
            QGraphicsItem::mouseDoubleClickEvent(event);
            if(!scene()) return ;
#ifdef KDCHART
            if(m_type==Hmi::PieWidget || m_type==Hmi::BarWidget ||m_type==Hmi::polarWidget ||m_type==Hmi::StockWidget)
            {
                CChartPropertyDialog dlg(this, scene()->views().first() );
                int RET = dlg.exec();
                if(RET == QDialog::Rejected)
                    return;
                dlg.Apply();
            }
#endif
        }
    }
    else
        QGraphicsProxyWidget::mouseDoubleClickEvent(event);
}

#ifdef WIN32
CAxWidgetData::CAxWidgetData(QGraphicsItem* item):CBaseData(item)
{
    m_AxWidget=new QAxWidget();
}

QGraphicsItem* CAxWidgetData::Clone()
{
    return 0;
}
void CAxWidgetData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CBaseData::SaveBaseProperty(xio);
}

void CAxWidgetData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CBaseData::LoadBaseProperty(xio);
}

void CAxWidgetData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CBaseData::GetPropertyList( property_list);
}

CAxWidgetItem::CAxWidgetItem(QGraphicsItem *parent)
    : QGraphicsWidget(parent)
{
    m_pData=new CAxWidgetData(this);
    g_SetData(this,m_pData);
}

CAxWidgetItem::~CAxWidgetItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

QRectF CAxWidgetItem::boundingRect() const
{
    return QRectF();
}

void CAxWidgetItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)

    QRect rc=option->exposedRect.toRect();
    m_pData->m_AxWidget->render(painter,QPoint(0,0),option->exposedRect.toRect());

}


#endif
