
#include "GraphScene.h"
#include "GraphView.h"
#include "GraphItem.h"
#include "GroupItem.h"
#include "ItemFactory.h"
#include "GFunc.h"
#include "CQScriptWrap.h"
#include "GraphSvgRW.h"
#include "IconMng.h"
#include "CGrid.h"
#include "WidgetItem.h"
#ifdef CHARTS
#include "GChartItem.h"
#endif

#ifdef QML
#include <QQuickView>
#endif
CGraphScene::CGraphScene(QObject *parent)
    : QGraphicsScene(parent),m_currentPlane(0),m_filePathName(),
      m_ShowPlanesMask(1, true),m_SceneType(Hmi::Explorer)
{
    m_pScriptEngine=NULL;

    Reset();
    setProperty("sceneType","sceneType_explorer");

}

CGraphScene::~CGraphScene()
{
	if (m_pScriptEngine)
	{
		delete m_pScriptEngine;
	}
	m_pScriptEngine = NULL;
#ifdef QML
    if (m_pQmlEngine)
	{
		delete m_pQmlEngine;
	}
	m_pQmlEngine = NULL;
#endif
}

void CGraphScene::Reset()
{
    clear();
    if (m_pScriptEngine)
    {
        delete m_pScriptEngine;
    }
    m_pScriptEngine = new CScriptEngine(this) ;
	m_pScriptEngine->installTranslatorFunctions();
#ifdef QML
    if(m_pQmlEngine)
    {
        delete m_pQmlEngine;
    }
    m_pQmlEngine=NULL;
    //m_pQmlEngine=new CQmlEngine(this);
#endif

    SetLayoutRect( QRect(0,0,1920,1080));
    m_ShowPlanesMask.resize(1);
    m_ShowPlanesMask.fill(true);
    m_currentPlane = 0;
    m_IsModified = false;
    m_WndPropFlag = Qt::WindowCloseButtonHint|Qt::WindowTitleHint|Qt::MSWindowsFixedSizeDialogHint;

    m_BackColor = QColor("white").rgb();
    m_ForeColor = 0;
    m_BackPixmapFlag = 0;
    m_BackPixmapName ="";
    m_BackPixmapShowWay = 0;

    m_RefreshItv = 0;
    m_InitZoomFactor = -1;
    m_TopoFlag = 0;

    m_Script			="";
    m_WndTitle			="";
    m_StationApp		="";
    m_WindowModality	=Qt::ApplicationModal;
    m_EnableScale		=false;
    m_currentPlane      = 0;
    m_FileType          = 0;

	m_planeNames        = "";
    m_FitViewMode       = 1;////全图显示//////
    m_GraphShowMode     = 0;
    m_LinkMode = Hmi::Normal;
    m_CanMove=false;
    m_Opacity=1;
    m_IfRef=true;
    m_NameItemMap.clear();
    m_NameItemModelMap.clear();


}
#ifdef QML
CQmlEngine*     CGraphScene::GetQmlEngine()
{
    if(!m_pQmlEngine)
        m_pQmlEngine= new CQmlEngine(this);

    return m_pQmlEngine;
}
#endif
void    CGraphScene::OnSelectionChanged()
{
    if (selectedItems().size()>0){
           /* for(int i=0;i<m_SortedItems.size();++i ){
                if (!m_SortedItems[i].isSelected())
                    m_SortedItems.removeAt(i);
            }*/
            QList<QGraphicsItem *>::iterator it = m_SortedItems.begin();
            while (it != m_SortedItems.end()) {
              if ( !(*it)->isSelected())
                it = m_SortedItems.erase(it);
              else
                ++it;
            }

            foreach (QGraphicsItem *item, selectedItems()){
                if (m_SortedItems.indexOf(item)<0)
                    m_SortedItems.append(item);
            }
    }
    else
            m_SortedItems.clear();
}

QList<QGraphicsItem *> CGraphScene::Items(bool ifTopItem, bool ifSelected, int order)
{
    if(ifSelected==true && order==2)///按选中顺序///
        return m_SortedItems;
    QList<QGraphicsItem*> ListItems ;
    if(ifSelected)
    {
		if (order < 0){
			if (ifTopItem )
			{
				foreach (QGraphicsItem *item, selectedItems())
				{
					if (item->parentItem()==0)
					{
						ListItems.append(item);
					}
				}
			}
			else
				return selectedItems();
		}
		else{
			
				Qt::SortOrder eOrder = (order == Qt::AscendingOrder ? Qt::AscendingOrder : Qt::DescendingOrder);
				foreach(QGraphicsItem *item, items(eOrder))
				{
					if (!item->isSelected())
						continue;

					if (ifTopItem)
					{
						if (item->parentItem() == 0)
							ListItems.append(item);
					}
					else
						ListItems.append(item);
				}
			
		}
    }
    else
    {
        if (ifTopItem )
        {
			Qt::SortOrder eOrder = (order == Qt::AscendingOrder ? Qt::AscendingOrder : Qt::DescendingOrder);
			foreach(QGraphicsItem *item, items(eOrder))
            {
                if (item->parentItem()==0)
                {
                    ListItems.append(item);
                }
            }
        }
        else
            return items();
    }
    return ListItems;
}

QList<QGraphicsItem *> CGraphScene::Items(const QPointF& pos,bool ifTopItem)
{
    QList<QGraphicsItem*> ListItems ;
    if (ifTopItem )
    {
        foreach (QGraphicsItem *item, items(pos))
        {
            if (item->parentItem()==0)
            {
                ListItems.append(item);
            }
        }
    }
    else
        return items();

    return ListItems;
}

QGraphicsItem * CGraphScene::GetElementById(QString id, bool ifcontain)
{
    //QScriptValue ret= GetScriptEngine()->globalObject().property(id);
    //QString gg= ret.toQObject()->objectName();
    QMap<QString,QGraphicsItem*>::iterator iter = m_NameItemMap.find(id);
    if(iter!=m_NameItemMap.end())
    {
        return iter.value();
    }

    if( !ifcontain)
        return NULL;

	/////contains id
	foreach(QGraphicsItem *item, items())
	{
		CBaseData* pdata = g_dataPtr(item);
		if (pdata && pdata->GetName().contains(id))
		{
			return item;
		}
	}
	return NULL;
}

int CGraphScene::FileOpen(const QString& fileName, bool isBinary)
{
    UnqFunc()->TmRestart();
    UnqFunc()->TmDebug("----graph::FileOpen  --start");
    if(fileName.right(4)==ICONSUFFIX)
    {
        IconLoad( fileName);
        return 0;
    }
	CGraphSvgReader* xio;
	QFile file(fileName);
		
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::warning(0, tr("File"), tr("Open file failed! Please sure is file exised and has authority."));
		return -1;
	}
	xio = new CGraphSvgReader(&file);
	
    m_filePathName = fileName;
	if (xio == NULL)
		return -1;
    UnqFunc()->TmDebug("--graph::StartElement--");
    if(xio->ReadNextStartElement())
    {
		if (xio->name() == "svg")
        {
            QList<CLinkLineItem*> lstLinkItem;
            qreal x,y,width,height;
            //////
            /////
			xio->ReadAttribute("linkMode", m_LinkMode);
			xio->ReadAttribute("ftype", m_FileType);
            int  planes=1;
            xio->ReadAttribute("planes", planes);
            SetPlaneNums(planes);
            QString showPlane;
			xio->ReadAttribute("show-planes", showPlane);
			xio->ReadAttribute("plane-names", m_planeNames);
			xio->ReadAttribute("os-bit", m_SysOsBit);
			xio->ReadAttribute("byte-seq", m_SysByteSeq);
			xio->ReadAttribute("alias", m_Alias);
			if (xio->ReadAttribute("x", x) != 0) x = 0;
			if (xio->ReadAttribute("y", y) != 0) y = 0;
			if (xio->ReadAttribute("w", width) != 0){ if (xio->ReadAttribute("width", width) != 0)width = 1280; }
			if (xio->ReadAttribute("h", height) != 0) { if (xio->ReadAttribute("height", height) != 0)height = 1024; }
            QRect rect(x,y,width,height);
            SetLayoutRect(rect);
            QString tmpstr;
			xio->ReadAttribute("bg-brush", tmpstr);
            setBackgroundBrush(UnqFunc()->SetBrushByText(tmpstr));
			m_BackPixmapName = UnqFunc()->GetTextureFileName(tmpstr);
			xio->ReadAttribute("bgPixmapStyle", m_BackPixmapShowWay);
			xio->ReadAttribute("init-scale", m_InitZoomFactor);
			xio->ReadAttribute("enable-scale", m_EnableScale);
			xio->ReadAttribute("wnd-flag", m_WndPropFlag);
			xio->ReadAttribute("wnd-modal", m_WindowModality);
			xio->ReadAttribute("wnd-title", m_WndTitle);
			xio->ReadAttribute("refresh-freq", m_RefreshItv);
			xio->ReadAttribute("station-app", m_StationApp);
			xio->ReadAttribute("topo-flag", m_TopoFlag);
			xio->ReadAttribute("fit-view", m_FitViewMode);
			xio->ReadAttribute("show_mode", m_GraphShowMode);
			xio->ReadAttribute("movable", m_CanMove);
			xio->ReadAttribute("opacity", m_Opacity);
			QVariantMap attrs = xio->ReadAttributes(CUSTOMURI);
            foreach (const QString &attrName, attrs.keys())
				setProperty(attrName.toLocal8Bit().data(), attrs.value(attrName).toString());

            while (xio->ReadNextStartElement())
            {
                QString typeName;
				if ("script" == xio->name())
                {
					QString script = xio->readElementText();
					if (isBinary)
						script = QByteArray::fromBase64(script.toLocal8Bit());
                    SetScript(script);
                    continue;
                }
				xio->ReadAttribute("type-name", typeName);
                if(typeName.isEmpty())
					typeName = xio->name().toString();

                
                QGraphicsItem* pItem = ItemFactory::CreateItem(typeName,0,this);
                if (pItem)
                {
                    CBaseData* pdata=g_dataPtr(pItem);
                    pdata->Load(xio);
                    AddItem(pItem);

                }
                else
                {
					xio->skipCurrentElement();
                }
            }
            UnqFunc()->TmDebug("--graph::read over----");
            UpdateLinks();
            /*foreach(CLinkLineItem* pItem,lstLinkItem)
                pItem->UpdateLoadedConnection();*/
            UnqFunc()->TmDebug("--graph::up connect---");
            SetShowPlanes(showPlane);
            UnqFunc()->TmDebug("--graph::showplane----");
        }
        else
        {
			xio->raiseError(QObject::tr("The file is not a svg file"));
            return -1;
        }
    }
    return 0;
}

void CGraphScene::AddItem(QGraphicsItem* pItem,bool alltoscriptengine )
{
    addItem(pItem);
    AppendItemIdx(pItem);
}

void CGraphScene::AppendItemIdx(QGraphicsItem* pItem,bool alltoscriptengine)
{
    CBaseData* pdata=g_dataPtr(pItem);
    QString name=pdata->GetName();
    int type=pItem->type();
    if (!name.isEmpty() )
    {
        if(type==QGraphicsProxyWidget::Type)
        {
            CWidgetItem *pwidget = dynamic_cast<CWidgetItem *>(pItem);
            if(pwidget) m_pScriptEngine->AddObject(pwidget->Widget(),name);
        }
        else if (type==Hmi::QtChart)
        {
#ifdef CHARTS
            m_pScriptEngine->AddObject((CGChartItem*)pItem, name);
#endif
        }
        else if(alltoscriptengine)
        {
            m_pScriptEngine->AddObject(pdata,name);
        }
        m_NameItemMap[name]=pItem;
    }

    if(pdata && pdata->IsIconContainer()){
        foreach(QGraphicsItem* subitem,pItem->childItems()){
            AppendItemIdx(subitem,true);
        }
    }

}

void CGraphScene::RemoveItemIdx(QGraphicsItem* pItem, bool alltoscriptengine)
{
	CBaseData* pdata = g_dataPtr(pItem);
	QString name = pdata->GetName();
	int type = pItem->type();
	if (!name.isEmpty())
	{
		if (alltoscriptengine)
		{
			m_pScriptEngine->AddObject(NULL, name);
		}
		m_NameItemMap.remove(name);
	}

    if (pdata && pdata->IsIconContainer()){
		foreach(QGraphicsItem* subitem, pItem->childItems()){
			RemoveItemIdx(subitem, true);
		}
	}
}

void CGraphScene::UpdateLinks(bool bypos)
{  
    if(bypos)//////通过位置更新连接关系//////
    {
        foreach(QGraphicsItem *item, items())
        {
            if (item->type() == Hmi::Link)
            {
                ((CLinkLineItem*)item)->UpdateLoadedConnection();
            }
			else if (g_dataPtr(item) && g_dataPtr(item)->IsIconContainer())
            {
                foreach (QGraphicsItem *subitem, item->childItems())
                {
                    if (subitem->type() == Hmi::Link)/////如果是组合或间隔还要更新连接关系//////////
                        ((CLinkLineItem*)subitem)->UpdateLoadedConnection();

                }
            }

        }
    }
    else
        CLinkLineData::UpdateLinks(items());////通过linkinfo更新连接关系//////

}

int CGraphScene::FileSave(const QString& fileName, bool isBinary)
{
    if(fileName.right(4)==ICONSUFFIX)
    {
        IconSave( fileName);
        return 0;
    }

    UpdateLinks(true);//////更新连接关系////////

    if (fileName.contains("\\"))
    {
        QString pathName;
        int idx = fileName.lastIndexOf("\\");
        pathName = fileName.left(idx);
        if (fileName.mid(idx).contains("/"))
            pathName = fileName.left(fileName.lastIndexOf("/"));
        QDir().mkpath(pathName);
    }
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return -1;
    CGraphSvgWriter xio(&file);
    xio.Init();///////初始化//////////

    QRect rect=GetLayoutRect();
    xio.WriteAttribute("os-bit",(int)m_SysOsBit);
    xio.WriteAttribute("byte-seq",(int)m_SysByteSeq);
    xio.WriteAttribute("linkMode", m_LinkMode);
    xio.WriteAttribute("ftype",m_FileType) ;
    xio.WriteAttribute("planes",GetPlaneNums()) ;
    xio.WriteAttribute("show-planes", GetShowPlanesStr());
	xio.WriteAttribute("plane-names", m_planeNames);
    xio.WriteAttribute("alias",m_Alias);
    xio.WriteAttribute("x",rect.x());
    xio.WriteAttribute("y",rect.y());
    xio.WriteAttribute("w",rect.width());
    xio.WriteAttribute("h",rect.height());
	xio.WriteAttribute("viewBox", QString("%1,%2,%3,%4").arg(rect.x()).arg(rect.y()).arg(rect.width()).arg(rect.height()));
    xio.WriteAttribute("bg-brush",UnqFunc()->GetBrushStyleText(backgroundBrush(),m_BackPixmapName));
	xio.WriteAttribute("bgPixmapStyle", m_BackPixmapShowWay);
    //xio.WriteAttribute("backpixmap_flag",m_BackPixmapFlag);
    //xio.WriteAttribute("backpixmap_name",m_BackPixmapName);
    xio.WriteAttribute("init-scale",m_InitZoomFactor);
    xio.WriteAttribute("enable-scale",m_EnableScale);
    xio.WriteAttribute("wnd-flag",m_WndPropFlag);
    xio.WriteAttribute("wnd-modal",m_WindowModality);
    xio.WriteAttribute("wnd-title",m_WndTitle);
    xio.WriteAttribute("refresh-freq",m_RefreshItv);
    xio.WriteAttribute("station-app",m_StationApp);
    xio.WriteAttribute("topo-flag",  m_TopoFlag);
    xio.WriteAttribute("fit-view", m_FitViewMode);
    xio.WriteAttribute("show_mode", m_GraphShowMode);
    xio.WriteAttribute("movable", m_CanMove);
    xio.WriteAttribute("opacity", m_Opacity);
    foreach(QByteArray barray, dynamicPropertyNames())
    {
        if(barray!="sceneType")
            xio.writeAttribute(CUSTOMURI,QString(barray),property(barray.data()).toString());
    }

    QList<QGraphicsItem*> ListItems = items(Qt::AscendingOrder);
    foreach (QGraphicsItem *item, ListItems)
    {
        if (item->parentItem() == 0 ||
                !( item->parentItem()->type() == Hmi::Symbol ||
                   item->parentItem()->type() == Hmi::Icon ||
                   item->parentItem()->type() == Hmi::Group ))
        {
            CBaseData* pdata=g_dataPtr(item);
            if (pdata)
            {
                pdata->Save(&xio);
            }
        }
    }

    xio.writeStartElement("script");
	QString scriptStr = GetScript();
	if (isBinary)
		scriptStr = GetScript().toLocal8Bit().toBase64();
	xio.writeCDATA(scriptStr);
    xio.writeEndElement();


	m_filePathName = fileName;
	
	QScriptSyntaxCheckResult ret = QScriptEngine::checkSyntax(GetScript());
    if (ret.state() != QScriptSyntaxCheckResult::Valid)
        QMessageBox::warning(0, tr("Error"), tr("Script error line_number = %1, Error_message = %2 !").arg(ret.errorLineNumber()).arg(ret.errorMessage()));

    return 0;
}


///
int CGraphScene::AddEdges(const QJsonArray& edges )
{
    for (int i = 0; i < edges.size(); i++)
    {
        QJsonObject edge = edges[i].toObject();
        QString name=edge["id"].toString();
        if(name.isEmpty())
            name=QString("_edge_%1").arg(i);

        CPathItem* pathitem=dynamic_cast<CPathItem*>(m_NameItemModelMap[name]);
        if(!pathitem){
            pathitem = (CPathItem*)(ItemFactory::CreateItem("path",0,this));
            CBaseData* pdata=g_dataPtr(pathitem);
            pdata->SetName(name);
            m_NameItemModelMap[name]=pathitem;
            pathitem->setZValue(-1);
            addItem(pathitem);
        }

        QString pathstr=edge["d"].toString() ;
        QPainterPath path;
        bool ifok=UnqFunc()->ParsePathData(&pathstr,path);
        pathitem->setPath(path);
    }
    return 0;
}

int CGraphScene::AddNodes(const QJsonArray& nodes, QString jsontype )
{
    if(nodes.size()<=0)
        return 0;
    m_Layout = m_JsonModel["layout"].toString();
    FlowLayout *layout=NULL;//
    QGraphicsWidget *w=NULL;
    //QGraphicsLinearLayout* layout;
    if(!m_Layout.isEmpty()){
        layout = new FlowLayout();//QGraphicsLinearLayout(Qt::Vertical);
        w = new QGraphicsWidget(0, Qt::Window|Qt::WindowCloseButtonHint  );
        QString geometry=m_JsonModel["geometry"].toString();
        QStringList geo=geometry.split(",");
        QRect rc=QRect(20,20,200,200);
        if(geo.size()==4){
            rc=QRect(geo[0].toInt(),geo[1].toInt(),geo[2].toInt(),geo[3].toInt());
        }
        w->setPos(rc.topLeft());
        w->setMinimumSize(20, 20);
        w->setPreferredSize(rc.size());
        //w->setWindowTitle(QApplication::translate("simpleanchorlayout", "QGraphicsAnchorLayout"));
    }

    for (int i = 0; i < nodes.size(); i++)
    {
        QJsonObject node = nodes[i].toObject();
        QString name=node["id"].toString();
        if(name.isEmpty())
            name=jsontype+QString("_%1").arg(i);
        QString type=node["type"].toString();

        QString group=node["group"].toString();
        QGraphicsItem* parent=group.isEmpty()? NULL:m_NameItemModelMap[group];
        QGraphicsItem* pItem=m_NameItemModelMap[name];
        if(!pItem)
        {
            pItem = ItemFactory::CreateItem(type,0,this);
            m_NameItemModelMap[name]=pItem;

            CBaseData* pdata=g_dataPtr(pItem);
            pdata->SetName(name);
            if(pItem->type()==Hmi::Icon)
                ((CIconData*)pdata)->SetTemplateName(type,true);

            QStringList whlst=node["size"].toString().split(",");
            if(whlst.size()==2){
                pdata->SetProperty("width",whlst[0].toInt());
                pdata->SetProperty("height",whlst[1].toInt());
            }

            QString tag=node["tag"].toString();
            pdata->SetProperty("userData","[{!tags!:!" + tag + "!}]");
            QString stroke=node["stroke"].toString();
            if(!stroke.isEmpty())
                pdata->SetLineColor(QColor(stroke));
            QString fill=node["fill"].toString();
            if(!fill.isEmpty()){
                pdata->SetFillStyle(Qt::SolidPattern);
                pdata->SetFillColor(QColor(fill));
            }
            //label
            QString label=node["label"].toString();
            if(!label.isEmpty()){
                CTextItem* plabel=new CTextItem();
                plabel->setParentItem(pItem);
                plabel->setText(label);
                plabel->setFlag(QGraphicsItem::ItemIgnoresTransformations,true);
                //plabel->setPos(pos);
                if(!stroke.isEmpty())
                    plabel->setPen( QColor(stroke));

            }

            if(!m_Layout.isEmpty())
            {
                CLayoutItem* li=new CLayoutItem(w);
                li->SetGraphicsItem(pItem);
                layout->addItem(li);
                //layout->setStretchFactor(li, 1);
            }
            else
                addItem(pItem);

            //group
            if(parent)
            {
                pItem->setParentItem(parent);
            }
        }

        QStringList poslst=node["pos"].toString().split(",");
        if(parent && parent->type()==Hmi::Path)
        {
            qreal pp=poslst[0].toFloat();
            QPainterPath parh=((CPathItem*)parent)->path();
            QPointF pt = parh.pointAtPercent(pp);
            double angel = parh.angleAtPercent(pp);
            pItem->setPos(pt);
            pItem->setRotation(angel);
        }
        else
        {
            QPoint pos;
            if(poslst.size()==2){
                pos=QPoint(poslst[0].toInt(),poslst[1].toInt());
                pItem->setPos(pos);
            }
            pItem->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
        }

    }

    if(!m_Layout.isEmpty()){
        w->setLayout(layout);
        addItem(w);
    }
    return 0;
}

int CGraphScene::LoadJsonModel(const QVariant& jsonobj )
{  
    if(jsonobj.canConvert<QJsonObject>())
        m_JsonModel=jsonobj.toJsonObject();
    else if (jsonobj.type() == QVariant::Map)
    {
        m_JsonModel = QJsonObject::fromVariantMap(jsonobj.toMap());
    }

    m_Layout = m_JsonModel["layout"].toString();

    QJsonArray nodes = m_JsonModel["nodes"].toArray();
    AddNodes(nodes,"_node");

    QJsonArray edges = m_JsonModel["edges"].toArray();
    AddEdges( edges );   

    QJsonArray edge_attachs = m_JsonModel["edge_attachs"].toArray();
    AddNodes(edge_attachs,"_edge_attach");
    return 0;
}

QString CGraphScene::GetJsonModel( )
{
    QJsonArray nodes = m_JsonModel["nodes"].toArray();
    for (int i = 0; i < nodes.size(); i++)
    {
        QJsonObject node = nodes[i].toObject();
        QString group=node["group"].toString();
        QString name=node["id"].toString();
        if(!name.isEmpty() && group.isEmpty())
        {
            QGraphicsItem* item=m_NameItemModelMap[name];
            if(item)
            {
                QPointF pos=item->pos();
                node["pos"]=QString("%1,%2").arg(pos.x()).arg(pos.y());
            }
            nodes[i]=node;
        }
    }
    m_JsonModel["nodes"]=nodes;
    return UnqFunc()->Json2Str(m_JsonModel);

}

int CGraphScene::UpdateLayout(const QVariant&  jsonobj )
{
    QJsonObject jmodel;
    if(jsonobj.canConvert<QJsonObject>())
        jmodel=jsonobj.toJsonObject();

    QJsonArray edges = jmodel["edges"].toArray();
    AddEdges( edges );
    //
    QJsonArray edge_attachs = jmodel["edge_attachs"].toArray();
    AddNodes(edge_attachs,"_edge_attach");

    return 0;
}

static qreal i_width=0;
static qreal i_height=0;
int CGraphScene::IconLoad(const QString& fileName)
{
    i_width=0;
    i_height=0;
    CIconItem* pIcon=IconLoadFromFile(fileName);
	if (!pIcon)
		return -1;
    Q_ASSERT(pIcon);
    addItem(pIcon);
    CIconData *pid = ((CIconData*)g_dataPtr(pIcon));
    m_filePathName = fileName;
    m_FileType=pid->GetIconType();
    m_UserData=pid->GetUserData();

    int states = pid->GetStateNums();
	if (states<0 || states>50)
		states = 1;
    SetStateNums(states);
    SetPlaneNums(states);
    QBitArray showPlane(states, true);
    SetShowPlanes(showPlane);
	QRectF rc=pIcon->boundingRect();

    if(i_width>0 && i_height>0)
        SetLayoutRect(QRect(0,0,i_width,i_height));
    else
        SetLayoutRect( QRect(0, 0,  rc.right(), rc.bottom()));

    QVariantMap cpmap=pid->CustomPropertys();
    QVariantMap::const_iterator i = cpmap.constBegin();
    while (i != cpmap.constEnd()) {
        setProperty(i.key().toLocal8Bit().data(),i.value());
        ++i;
    }
    m_IfRef=pid->GetIfRef();
    destroyItemGroup(pIcon);
    return 0;
}

CIconItem* CGraphScene::IconLoadFromFile(const QString& fileName,bool ifNotRefThenSkip)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return NULL;
    CIconItem* pIcon=NULL;
    CGraphSvgReader xio(&file);
    if(xio.ReadNextStartElement())
    {
        if (xio.name() == "svg" )
        {
            xio.ReadAttribute("width", i_width) ;
            xio.ReadAttribute("height", i_height) ;

            if ( xio.ReadNextStartElement() )
            {
                QString itemName=xio.name().toString ();
                Q_ASSERT(itemName == "g");
                QString tpName;
                bool if_ref;
                int icon_type;
                xio.ReadAttribute("type-name", tpName);
                xio.ReadAttribute("if-ref", if_ref);
                xio.ReadAttribute("icon-type", icon_type);
                QGraphicsItem* item=ItemFactory::CreateItem(tpName );

                if (item && item->type()==Hmi::Icon)
                {
                    CIconData* pdata= (CIconData*)(g_dataPtr(item));
                    if (pdata)
                    {
                        pdata->SetIfRef(if_ref);
                        if(icon_type==400 && if_ref==false && ifNotRefThenSkip) //
                        {
                            //临时方案，==400，否者加载图元时会实例化很多插件
                        }
                        else
                        {
                            pdata->LoadIconF(&xio);
                        }
                    }
                    return (CIconItem*)(item) ;

                }

            }
        }
        else
        {
            xio.raiseError(QObject::tr("The file is not a svg file"));
            return NULL;
        }
    }
    return NULL;
}

int CGraphScene::IconSave(const QString& fileName)
{
    return 0;
}

int CGraphScene::IconSaveToFile(CIconItem * pIcon, const QString& fileName)
{
    if (!pIcon)
        return -1;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return -1;
    CIconData* pidata= dynamic_cast<CIconData*>(g_dataPtr(pIcon));
    int iType=pidata->GetIconType();

    CGraphSvgWriter xio(&file);
    QRect rect=GetLayoutRect();
    xio.Init();
    xio.WriteAttribute("ftype",iType) ;
    xio.WriteAttribute("width",  rect.width()) ;
    xio.WriteAttribute("height", rect.height()) ;

    QVariantMap cpmap= CustomPropertys();
    QVariantMap::const_iterator i = cpmap.constBegin();
    while (i != cpmap.constEnd()) {
        pidata->setProperty(i.key().toLocal8Bit().data(),i.value());
        ++i;
    }

    pidata->SaveIconF(&xio);
    return 0;
}

QVariantMap CGraphScene::CustomPropertys()
{
    QVariantMap attrs;
    foreach(QByteArray barray, dynamicPropertyNames())
    {
        QString propname=QString(barray);
        if(propname!="sceneType")
            attrs[propname]=property(barray.data()) ;
    }
    return attrs;
}

QVariant CGraphScene::Property(QString name,bool allprop )
{
    QVariant ret;
    ret=property(name.toLocal8Bit().data());
    if(ret.isValid()){
        return ret;
    }
    if(!allprop)
        return ret;
    QList< QPair<QString,QVariant> > property_list;
    GetPropertyList( property_list);
    for (int i=0;i<property_list.size();i++)
    {
        if (property_list.at(i).first == CBaseData::tr(name.toStdString().data()))
        {
            QVariant val= property_list.at(i).second;
            QVariantList lst=val.toList();
            if(!lst.isEmpty())
                val=lst.at(0);
            return val;
        }
    }

    return ret;
}

void CGraphScene::UpdateScene()
{
	QList<QGraphicsItem*> itemsList = Items(true,false);
    foreach(QGraphicsItem* item,itemsList)
    {
        CBaseData* pdata=g_dataPtr(item);
        if (pdata == NULL)
            continue;
        const short objPlane = pdata->GetPlane();
        bool if_show_plane=m_ShowPlanesMask.at(objPlane) ;

        item->setVisible(if_show_plane);

        UpdateItem( item);
    }
}

int CGraphScene::UpdateItem(QGraphicsItem* item)
{

    return 0;
}

void CGraphScene::SetCurPlane( int plane )
{
    Q_ASSERT(plane >= 0);
    m_currentPlane = plane;
    UpdateScene();
}

void CGraphScene::SetPlaneNums(int planeNums)
{
	if (planeNums > 0 && planeNums < 100){
		int oldps = m_ShowPlanesMask.size();
		m_ShowPlanesMask.resize(planeNums);
		if (planeNums>oldps)
			m_ShowPlanesMask.fill(true, oldps, planeNums);
	}
    else
        gWarn("---CGraphScene::SetPlaneNums--invalid nums:%d",planeNums);
}

void CGraphScene::SetShowPlanes(const QBitArray& showPlanesMask)
{
    m_ShowPlanesMask = showPlanesMask;
    UpdateScene();
}

void CGraphScene::SetShowPlanes(const QString& show_planes)
{

	int planes = GetPlaneNums();
    if (show_planes.isEmpty())
    {
		m_ShowPlanesMask.resize(planes);
        m_ShowPlanesMask.fill(true);
    }
    else
    {
        QStringList tmplist = show_planes.split(',', QString::SkipEmptyParts);
 
		for (int i = 0; i<tmplist.size(); i++)
        {
			if (i<m_ShowPlanesMask.size())
				m_ShowPlanesMask[i] = tmplist[i].toInt();
        }
    }

    UpdateScene();
}

QString CGraphScene::GetShowPlanesStr()
{
    QStringList show_list;
    QBitArray planeArray = GetShowPlanesMask();
    for (int i = 0; i<planeArray.size(); i++)
        show_list << QString("%1").arg(planeArray[i]);
    return show_list.join(",");
}

void CGraphScene::ShowPlane(int planeNo)
{

    UpdateScene();
}

void CGraphScene::HidePlane(int planeNo)
{

    UpdateScene();
}

void CGraphScene::DelPlane(int planeNo)
{
    if (planeNo < 0 || planeNo >= GetPlaneNums())
        return;
    QBitArray planes = GetShowPlanesMask();


    foreach(QGraphicsItem *item, Items(true,false))
    {
        CBaseData* pdata = g_dataPtr(item);
        if (pdata)
        {
            int oldPlane = pdata->Property(QObject::tr("plane")).toInt();
            if (oldPlane == planeNo)
                removeItem(item);
            else if (oldPlane > planeNo)
                pdata->SetProperty(QObject::tr("plane"), oldPlane - 1);

        }
    }


    for (int i = planeNo; i < ( planes.size()-1 ); i++)
    {
        planes[i] = planes[i + 1];
    }
    planes.resize(GetPlaneNums() - 1);
    SetShowPlanes(planes);
	SetPlaneNums(planes.size());
}

void CGraphScene::MovePlane(int from, int to)
{
    if (from < 0 || from >= GetPlaneNums() || to < 0 || to >= GetPlaneNums())
        return;


    QList<QGraphicsItem*> fromItems;
    foreach(QGraphicsItem *item, items())
    {
        CBaseData* pdata = g_dataPtr(item);
        if (pdata)
        {
            QString planeStr = pdata->Property(QObject::tr("plane")).toString();
            if (planeStr.contains("tmp"))
                continue;
            int oldPlane = planeStr.toInt();
            if (oldPlane == from)
            {
                pdata->SetProperty(QObject::tr("plane"), "tmp" + to);
                fromItems << item;
            }
            else if (from<to && (oldPlane>from && oldPlane <= to))
                pdata->SetProperty(QObject::tr("plane"), oldPlane - 1);
            else if (from>to && (oldPlane<from && oldPlane >= to))
                pdata->SetProperty(QObject::tr("plane"), oldPlane + 1);
        }
    }
    foreach(QGraphicsItem *item, fromItems)
    {
        CBaseData* pdata = g_dataPtr(item);
        pdata->SetProperty(QObject::tr("plane"), to);
    }


    QBitArray planes = GetShowPlanesMask();
    QBitArray newPlanes;
    newPlanes.resize(planes.size());
    for (int i = 0; i < planes.size(); i++)
    {
        if (i == to)
        {
            newPlanes[i] = planes[from];
        }
        else if (from<to && (i >= from && i < to))
            newPlanes[i] = planes[i + 1];
        else if (from>to && (i <= from && i > to))
            newPlanes[i] = planes[i - 1];
        else
            newPlanes[i] = planes[i];
    }
    SetShowPlanes(newPlanes);

}


void CGraphScene::SetLayoutRect(const QRect& rect)
{
    m_LayoutRect=rect;
    setSceneRect(0,0,rect.width(),rect.height());
}

QWidget* CGraphScene::View()
{
    return views().size() ? views().first()->viewport() : NULL;
}

void CGraphScene::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    property_list.push_back( qMakePair( QString(QObject::tr("layoutRect")) ,QVariant(GetLayoutRect()) ) );

    QColor backcolor(GetBackColor());
    QColor frontcolor(GetForeColor());
    //QRect show_rect=Scene()->GetGraphRect();
    QMap<QString, QVariant>  rainbow_way;
    rainbow_way[tr("Tile")]=0;
    rainbow_way[tr("Zoom")]=1;
    rainbow_way[ "__CurrentValue" ]=m_BackPixmapShowWay;
    property_list.push_back( qMakePair( QString(QObject::tr("bgColor")) ,QVariant(backgroundBrush() )));
  //property_list.push_back(qMakePair(tr("bgPixmapStyle"),QVariant(rainbow_way)));

    QMap<QString, QVariant> tmpMap;
    tmpMap[tr("Normal")] = Hmi::Normal;
    tmpMap[tr("Top2Bottom")] = Hmi::Top2Bottom;
    tmpMap[tr("Left2Right")] = Hmi::Left2Right;
    tmpMap[tr("One90angle")] = Hmi::One90angle;
    tmpMap[tr("Draw2Mergin")] = Hmi::Draw2Mergin;
    tmpMap["__CurrentValue"] = m_LinkMode;
    property_list.push_back(qMakePair(tr("linkMode"), QVariant(tmpMap)));

    property_list.push_back(qMakePair(tr("wndTitle"),QVariant(GetWndTitle() )));
    property_list.push_back(qMakePair(tr("enableScale"),QVariant(GetEnableScale())));
    property_list.push_back(qMakePair(tr("showTopo"),QVariant((bool)GetTopoFlag())));//ÔÊÐíÍØÆË
    property_list.push_back(qMakePair(tr("wndAlias"),QVariant( GetAlias() )));//´°¿Ú±êÊ¶

    tmpMap.clear();
    tmpMap[tr("fixview")] = 0;
    tmpMap[tr("relativeview")] = 2;
    tmpMap[tr("fitview")] = 1;
    //tmpMap[tr("KeepAspectRatioByExpanding")] = Qt::KeepAspectRatioByExpanding;
    tmpMap["__CurrentValue"] = m_FitViewMode;//Qt::AspectRatioMode:The effect of each value is the same 

    property_list.push_back(qMakePair(tr("fitView"),QVariant( tmpMap)));

    int wndFlags=GetWndPropFlags();
    bool has_ctlbtn=false,fix_size=false,has_border=false;
    if (wndFlags == 0)
    {
        has_border=false;
        has_ctlbtn=false;
    }
    if ((wndFlags & Qt::WindowCloseButtonHint) != 0)
    {
        has_ctlbtn=true;
    }
    if ((wndFlags & Qt::FramelessWindowHint) == 0)
    {
        has_border=true;
    }
    if ((wndFlags & Qt::MSWindowsFixedSizeDialogHint) != 0)
    {
        fix_size=true;
    }
    bool stayOnTop=false;
    if ((wndFlags &  Qt::WindowStaysOnTopHint) != 0)
    {
        stayOnTop=true;
    }

    bool is_modal=true;
    if(WindowModality()==Qt::NonModal) is_modal=false;

    property_list.push_back(qMakePair(tr("showPlane"), QVariant(GetShowPlanesStr())));
    property_list.push_back(qMakePair(tr("ctlbtn"),QVariant(has_ctlbtn)));
    property_list.push_back(qMakePair(tr("fixSize"),QVariant(fix_size)));
    property_list.push_back(qMakePair(tr("hasBorder"),QVariant(has_border)));
    property_list.push_back(qMakePair(tr("stationApp"),QVariant(GetStationApp())));
  //  property_list.push_back(qMakePair(tr("showMode"),QVariant((bool)GraphShowMode())));
    property_list.push_back(qMakePair(tr("ifModal"),QVariant(is_modal)));
    property_list.push_back(qMakePair(tr("stayOnTop"),QVariant(stayOnTop)));
    property_list.push_back(qMakePair(tr("canMove"),QVariant(m_CanMove)));
	QVariantList lst;
	lst.append(GetWindowOpacity());//value
	QJsonObject inputLimit;
	inputLimit["minimum"] = 0;
	inputLimit["maximum"] = 1;
	lst.append(inputLimit);//inputlimit
	property_list.push_back(qMakePair(tr("windowOpacity"), QVariant(lst)));
    property_list.push_back(qMakePair(tr("refreshInterval"),QVariant(GetRefreshInterval())));
    property_list.push_back(qMakePair(tr("ifref"),QVariant(m_IfRef)));

}

bool CGraphScene::SetProperty(const QString &property_name, const QVariant& value,bool allprop )
{
    int wndFlags=GetWndPropFlags();
    QString prop_name=property_name ;

	if (property_name == tr("layoutRect") || property_name == "layoutRect")
    {
        SetLayoutRect(value.toRect());
    }
	else if (prop_name == tr("default display coefficient") || prop_name == "default display coefficient")
    {
        float val = value.toDouble();
    }
	else if (prop_name == tr("area display settings") || prop_name == "area display settings")
    {
        //CGRect rect(value.toRect());
    }
	else if ((prop_name == tr("plane Nums")) || prop_name == "plane Nums")
    {
        int plane_nums=0;
        plane_nums= value.toUInt();
        if (plane_nums<1)
            plane_nums=1;
        //Scene()->ChangePlaneNum(plane_nums);

    }
	else if ((prop_name == tr("level Nums")) || (prop_name == tr("state Nums")) || prop_name == "level Nums" || prop_name == "state Nums")
    {
        int n=0;
        n= value.toUInt();
        // 		if (n<1)
        // 			return ;
        // 		Scene()->SetLevelNum(n);

    }
	else if (prop_name == tr("bgColor") || prop_name == "bgColor")
    {
        m_BGBrush=UnqFunc()->SetBrushByText(value.value<QString>());
        setBackgroundBrush(m_BGBrush);
		m_BackPixmapName = UnqFunc()->GetTextureFileName(value.value<QString>());
    }

  /*  else if(prop_name==tr("bgPixmap11"))
    {
        int c=0;
        c= qvariant_cast<QColor>(value).rgb();
        SetForeColor(c);

    }*/
	else if (prop_name == tr("refreshInterval") || prop_name == "refreshInterval")
    {
        int n=0;
        n= value.toUInt();
        if (n>0 && n<=15)
            n=15;
        if (n<0)
            n=-1;
        SetRefreshInterval(n);
    }
	else if (prop_name == tr("wndAlias") || prop_name == "wndAlias")
    {
        QString name=value.toString() ;
        SetAlias(name);
    }
   /* else if(prop_name==tr("bgPixmap"))
    {
        QString name="HMI";
        QString str=value.toString();
        str = str.section( '/', -1 );

        SetBackPixmapName(str.replace("QFile--",""));
        SetBackPixmapFlag(true);
        QString back_pix_name=str;
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP,back_pix_name,back_pix_name);
        //setCacheMode(QGraphicsView::CacheBackground);
        setBackgroundBrush(QPixmap(back_pix_name));
    }*/
	else if (prop_name == tr("bgPixmapStyle") || prop_name == "bgPixmapStyle")
    {
        SetPixmapShowWay(value.toUInt());
    }
	else if (prop_name == tr("amplification factor") || prop_name == tr("amplification factor(%)") || prop_name == "amplification factor" || prop_name == "amplification factor(%)")
    {

    }
	else if (prop_name == tr("script") || prop_name == "script")
    {
        QString script=value.toString();

        SetScript(script.toLocal8Bit().data());
    }
	else if (prop_name == tr("plane") || prop_name == "plane")
    {
        SetCurPlane(value.toInt());
    }
	else if (prop_name == tr("wndTitle") || prop_name == "wndTitle")
    {
        SetWndTitle(value.toString().toLocal8Bit().data());
    }
	else if (prop_name == tr("showPlane") || prop_name == "showPlane")
    {
        SetShowPlanes(value.toString());
    }
	else if (prop_name == tr("ctlbtn") || prop_name == "ctlbtn")
    {
        bool val=value.toBool();
        if (val)
        {
            wndFlags|=Qt::WindowCloseButtonHint;
            //wndFlags|=Qt::WindowTitleHint;
            wndFlags&= (~Qt::FramelessWindowHint);
        }
        else
        {
            wndFlags&= (~Qt::WindowCloseButtonHint);
        }
        SetWndPropFlags(wndFlags);
    }
	else if (prop_name == tr("hasBorder") || prop_name == "hasBorder")
    {
        bool val=value.toBool();
        if (val)
        {
            //wndFlags|=Qt::WindowTitleHint;
            wndFlags&= (~Qt::FramelessWindowHint);
        }
        else
        {
            wndFlags=Qt::FramelessWindowHint;


        }
        SetWndPropFlags(wndFlags);
    }
	else if (prop_name == tr("fixSize") || prop_name == "fixSize")
    {
        bool val=value.toBool();
        if (val)
        {
            wndFlags|=Qt::MSWindowsFixedSizeDialogHint;
        }
        else
        {
            wndFlags &= (~Qt::MSWindowsFixedSizeDialogHint);
        }
        SetWndPropFlags(wndFlags);
    }
	else if (prop_name == tr("stayOnTop") || prop_name == "stayOnTop")
    {
        bool val=value.toBool();
        if (val)
        {
            wndFlags|=Qt::WindowStaysOnTopHint;
        }
        else
        {
            wndFlags &= (~Qt::WindowStaysOnTopHint);
        }
        SetWndPropFlags(wndFlags);
    }

	else if (prop_name == tr("stationApp") || prop_name == "stationApp")
    {
        SetStationApp(value.toString());
    }

	else if (prop_name == tr("showMode") || prop_name == "showMode")
    {
        int val = value.toUInt();
        SetGraphShowMode( val );
    }
	else if (prop_name == tr("ifModal") || prop_name == "ifModal")
    {
        bool val=value.toBool();
        if (val)
            SetWindowModality( Qt::ApplicationModal );
        else
            SetWindowModality( Qt::NonModal);
    }
	else if (prop_name == tr("enableScale") || prop_name == "enableScale")
    {
        SetEnableScale(value.toBool());
    }
	else if (prop_name == tr("showTopo") || prop_name == "showTopo")
    {
        SetTopoFlag(value.toBool());
    }
    else if (prop_name == tr("fitView") || prop_name == "fitView")
    {
        SetFitViewMode(value.toInt());
    }
	else if (prop_name == tr("canMove") || prop_name == "canMove")
    {
        m_CanMove=value.toBool();
    }
	else if (prop_name == tr("linkMode") || prop_name == "linkMode")
    {
        SetLinkMode(value.toInt());
    }
	else if (prop_name == tr("windowOpacity") || prop_name == "windowOpacity")
    {
        SetWindowOpacity(value.toFloat());
    }
    else if (prop_name == tr("ifref") || prop_name == "ifref")
    {
        m_IfRef=value.toBool();
    }
    else
    {
        return setProperty(prop_name.toLocal8Bit().data(), value);
    }
    return true;
}

void CGraphScene::drawBackground( QPainter* painter, const QRectF& rect )
{
    QGraphicsScene::drawBackground(  painter,  rect );
	/**********drawPixmap is  not smooth, use QGraphScene::drawBackground, but only tile
	QRectF repaintRect = rect.intersected(sceneRect());
	if (repaintRect.width() == 0 && repaintRect.height() == 0)
		return;
	QString back_pix_name = GetBackPixmapName();
	if (!back_pix_name.isEmpty() && back_pix_name != "0")
	{
		UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, back_pix_name, back_pix_name);
		if (GetPixmapShowWay() == 0)//tile
		    painter->drawTiledPixmap(repaintRect, QPixmap(back_pix_name));
		else if (GetPixmapShowWay() == 1)//zoom
			painter->drawPixmap(repaintRect.toRect(), QPixmap(back_pix_name));
		else //original
			painter->drawPixmap(repaintRect.topLeft(), QPixmap(back_pix_name));
	}*/
}
void	CGraphScene::SetBackPixmapName(QString back_pixmap_name)
{
	m_BackPixmapName = back_pixmap_name;
	UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, m_BackPixmapName, back_pixmap_name);
	this->setBackgroundBrush(QBrush(QPixmap(back_pixmap_name)));

};
QObject* CGraphScene::CreateItem(const QString& jsonstr,int dx,int dy)
{
    CBaseData* pdata=NULL;
    QString typeName=jsonstr;
    QString iconName;
    QJsonObject jobj=UnqFunc()->Str2Json(jsonstr);
    if(!jobj.isEmpty()){
        iconName=jobj["icon"].toString();
        typeName=jobj["type"].toString();
    }
    if(typeName.isEmpty())
        return NULL;

    QGraphicsItem* pItem = ItemFactory::CreateItem(typeName,0,this);
    if (pItem)
    {
        pdata=g_dataPtr(pItem);
        if(typeName=="path" && !iconName.isEmpty())
        {
            CAbstractPathData* pathdata = (CAbstractPathData*)(pdata);
            pathdata->SetSymbolName(iconName);
        }
        addItem(pItem);
    }
    return pdata;
}

void CGraphScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{

    event->accept();

}
void CGraphScene::dragMoveEvent( QGraphicsSceneDragDropEvent * e )
{
    clearSelection();
    QList<QGraphicsItem *> items =Items(e->scenePos(),true );
    if(items.size()>0)
    {
        items[0]->setSelected(true);
    }
    return;
}

void CGraphScene::dropEvent(QGraphicsSceneDragDropEvent * e)
{
    e->acceptProposedAction();

    QGraphicsScene::dropEvent(e);
}

int CGraphScene::EmitSignal(const QString& signal,const QVariant& newPos)
{
    if(signal.indexOf("item"))
    {
        CGraphView *view=dynamic_cast<CGraphView *>(views().at(0));
        if(view)
            view->EmitSignal( signal, newPos);
    }
    return 0;
}

//jQuery selector, "*" ,"selected","#id" ,".class" ,"[attribute]","[attribute=value]","[attribute!=value]","[attribute$=value]"
QObjectList CGraphScene::Items(const QString& selector,QObject* parent ,bool ifTopItem )
{
    QList<QObject*> ret;
    QList<QGraphicsItem *> items;

    if(selector =="*" || selector =="selected"){
        bool ifSelected=false;
        if(selector =="selected") ifSelected=true;
        QList<QObject*> retlist;
        foreach(QGraphicsItem *item,  Items(ifTopItem,ifSelected))
        {
            CBaseData* pdata = g_dataPtr(item);
            if (pdata)
                retlist.append((QObject*)pdata);
        }
        return retlist;
    }
    if(selector =="this" &&  selectedItems().size()>0)
    {
        ret.append(g_dataPtr(  selectedItems().at(0) ));
        return ret;
    }

    if(parent!=NULL && parent->inherits("CBaseData"))
    {
        items=((CBaseData*)parent)->Item()->childItems();
    }
    else
    {
        items=  Items(ifTopItem,false);
    }

    return UnqFunc()->Selector(selector, items);

}
