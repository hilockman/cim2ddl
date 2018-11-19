#include "GroupItem.h"
#include "GraphSvgRW.h"
#include "GraphScene.h"
#include "Global.h"
#include "IconMng.h"
#include "ItemFactory.h"

int ICON_TYPE_BAY=299;

bool g_PaintOnIcon(QPainter& painter,const ItemPointerList& LstItems, const QPointF& offset = QPointF(0,0))
{
    QStyleOptionGraphicsItem style;
    foreach(QGraphicsItem* Item,LstItems)
    {
        if (CGroupItem* groupItem = dynamic_cast<CGroupItem*>(Item))
        {
            g_PaintOnIcon(painter,groupItem->childItems(),offset);
        }
        else
        {
			painter.setTransform(Item->sceneTransform()*QTransform::fromTranslate(offset.x(), offset.y()));
            painter.setOpacity(Item->opacity());
            g_dataPtr(Item)->PaintOnNail(&painter,&style,2/(painter.deviceTransform().m11() + painter.deviceTransform().m22()));
        }
    }
    return true;
}

CGroupData::CGroupData(QGraphicsItem* item):CAbstractScaleData(item)
{

}

bool CGroupData::IsIconContainer()
{
    if(Item()->type()==Hmi::Icon){
       int iconType=((CIconData*) g_dataPtr(Item()))->GetIconType();
       return iconType==ICON_TYPE_BAY? true:false;
    }
    foreach (QGraphicsItem *item, Item()->childItems())
    {
        if(item->type()==Hmi::Icon)
            return true;
    }
    return false;
}

void CGroupData::SaveSubProperty( CGraphSvgWriter* xio ) const
{
    QList<QGraphicsItem*> ListItems = Item()->childItems();
    g_reOrder(ListItems);
    QGraphicsItem* item;
    foreach(item,ListItems)
    {
        g_dataPtr(item)->Save(xio);
    }
}

void CGroupData::LoadSubProperty( CGraphSvgReader* xio )
{
    bool is_explorer=g_ifExplorer(Item()->scene());

    const QTransform tf = Item()->transform();
    Item()->resetTransform();

    while(xio->ReadNextStartElement() )
    {
        QString tpName;
        xio->ReadAttribute("type-name",tpName);
		if (tpName.isEmpty())
			tpName = xio->name().toString();
        QGraphicsItem* item=ItemFactory::CreateItem(tpName);
        if (item)
        {
            CBaseData* pdata=g_dataPtr(item);
            if (pdata)
            {
                pdata->Load(xio);
            }

            static_cast<QGraphicsItemGroup*>(m_pItem)->addToGroup(item);
            if(is_explorer) pdata->setParent(this);
        }
        else
        {
            xio->skipCurrentElement();
        }
    }

    Item()->setTransform(tf);

}

QGraphicsItem* CGroupData::Clone()
{
    CGroupItem* curItem=(CGroupItem*)Item();
    CGroupItem* newitem=new CGroupItem();
    foreach (QGraphicsItem *item, curItem->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        Q_ASSERT(d_ptr);
        QGraphicsItem* tempitem=d_ptr->Clone();
        newitem->addToGroup(tempitem);
    }
    g_dataPtr(newitem)->Copy(this);


    return newitem;
}

void CGroupData::SetUserData(const QString& userData)
{
    m_UserData=userData;
    if(userData=="")//////用于清空连库信息//////
    {
        foreach (QGraphicsItem *item, Item()->childItems())
        {
            CBaseData* d_ptr=g_dataPtr(item);
            if(d_ptr)
                d_ptr->SetUserData("");
        }
    }
}

void CGroupData::SetLineColor(const QColor& color)
{
    if(!color.isValid() ) return;
    foreach (QGraphicsItem *item, Item()->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetLineColor( color);
    }
}
QColor CGroupData::GetLineColor() const
{
    return QColor();
}
void CGroupData::SetFillColor(const QColor& color)
{
    if(!color.isValid() ) return;
    foreach (QGraphicsItem *item, Item()->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetFillColor( color);
    }
}
QColor CGroupData::GetFillColor() const
{
    return QColor();
}
Qt::BrushStyle CGroupData::GetFillStyle() const
{
    return Qt::NoBrush;
}
void CGroupData::SetFillStyle(Qt::BrushStyle style)
{
    if(Qt::NoBrush==style ) return;
    foreach (QGraphicsItem *item, Item()->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetFillStyle( style);
    }
}
Qt::PenStyle CGroupData::GetLineStyle() const
{
    return Qt::NoPen;
}
void CGroupData::SetLineStyle(Qt::PenStyle style)
{
    if(Qt::NoPen==style ) return;
    foreach (QGraphicsItem *item, Item()->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetLineStyle( style);
    }
}
qreal CGroupData::GetLineWidth() const
{
    return -1;
}
void CGroupData::SetLineWidth(qreal width)
{
    if(width<0 ) return;
    foreach (QGraphicsItem *item, Item()->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetLineWidth( width);
    }
}

void CGroupData::ResetColor(COLOR_TYPE type)
{   
    if(type==CBaseData::LINECOLOR && m_OrgLineColor.isValid()  )   {
        SetLineColor(m_OrgLineColor);
        return; /////已处理了线色///////
    }

    if(type==CBaseData::FILLCOLOR && m_OrgFillColor.isValid()  ) {
        SetFillColor(m_OrgFillColor);
        return;/////已处理了填充色///////
    }

    if(type==CBaseData::ALLCOLOR){
        if(m_OrgLineColor.isValid() && m_OrgFillColor.isValid()) {
            SetLineColor(m_OrgLineColor);
            SetFillColor(m_OrgFillColor);
            return;
        }
        if(m_OrgLineColor.isValid() && !m_OrgFillColor.isValid()) {
            SetLineColor(m_OrgLineColor);
            type=CBaseData::FILLCOLOR;   /////这时还需以子对象reset填充色///////
        }
        if(!m_OrgLineColor.isValid() && m_OrgFillColor.isValid()) {
            SetFillColor(m_OrgFillColor);
            type=CBaseData::LINECOLOR;  /////这时还需以子对象reset线色///////
        }
    }

    foreach (QGraphicsItem *item, Item()->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->ResetColor(type);
    }
}
///

CGroupItem::CGroupItem(QGraphicsItem *parent )
    :QGraphicsItemGroup(parent)
{
    m_pData=new CGroupData(this);
    g_SetData(this,m_pData);

    //setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

CGroupItem::~CGroupItem()
{

    foreach (QGraphicsItem *item, childItems())
    {
        delete item;
    }
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

void CGroupItem::SetChildItemFlag(QGraphicsItem::GraphicsItemFlag flag, bool enabled )
{
    return;
    if(scene() && ( "sceneType_explorer"==scene()->property("sceneType").toString()) )
    {
        return;
    }

    setHandlesChildEvents(true);
    foreach (QGraphicsItem *item,childItems())
    {
        item->setFlag(flag,enabled);
    }
}

QRectF CGroupItem::boundingRect() const
{
	return QGraphicsItemGroup::boundingRect();// .adjusted(4, 4, -4, -4);
}

void CGroupItem::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    Q_UNUSED(widget)
    if ( (option->state & QStyle::State_Selected)||!handlesChildEvents() )
    {
        QRectF rect = boundingRect();
		qreal cornerW = rect.width() > rect.height() ? rect.height() / 20 : rect.width() / 20;
		g_PaintBoundingRect(scene(), painter, option, rect, cornerW);
        QVector<QPointF> points;
        points.reserve(8);
		qreal w = rect.width();
		qreal h = rect.height();
		points << rect.topLeft() << rect.topRight() << rect.bottomLeft() << rect.bottomRight() << rect.topLeft() + QPointF(w / 2, 0) << rect.topLeft() + QPointF(0, h / 2) << rect.topRight() + QPointF(0, h / 2) << rect.bottomLeft() + QPointF(w / 2, 0);
        QColor cl=Qt::blue;//darkGreen;
        if(!handlesChildEvents())
            cl=Qt::red;
		g_HighlightSelected(scene(), painter, option, points, cornerW, true, cl);
    }
}

void CGroupItem::GetItemIcon(QPixmap& pic) const
{
    pic.fill(Qt::transparent);
    {
        QStyleOptionGraphicsItem style;
        QPainter painter;

        ItemPointerList ItemList = childItems();
        QRectF bRect;
        foreach(QGraphicsItem* item, ItemList)
        {
            bRect |= item->sceneBoundingRect();
        }

        int width = bRect.width() > bRect.height() ? bRect.width() : bRect.height();

        painter.begin(&pic);
        painter.setWindow(0, 0, width, width);
        painter.setViewport(0, 0, pic.size().width(), pic.size().height());
        painter.setBackground(Qt::transparent);
        painter.setBackgroundMode(Qt::OpaqueMode);
        g_PaintOnIcon(painter, ItemList, QPointF(width*0.5, width*0.5) - bRect.center());
        painter.end();

    }
}

void CGroupItem::focusOutEvent(QFocusEvent * event)
{

}

////
CIconData::CIconData(QGraphicsItem* item,const QString& name ):CGroupData(item),m_StateNums(1)
{
    G_G(CIconItem);
    m_ifRef=false;
    SetTemplateName(name);
}

QGraphicsItem* CIconData::Clone()
{
    CIconItem* curItem=dynamic_cast<CIconItem*>(Item());
    CIconItem* newitem=new CIconItem();
    foreach (QGraphicsItem *item, curItem->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        Q_ASSERT(d_ptr);
        QGraphicsItem* tempitem=d_ptr->Clone();
        newitem->addToGroup(tempitem);

    }
    g_dataPtr(newitem)->Copy(this);
    return newitem;
}

void CIconData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    CIconData* psrcdata=((CIconData*)srcData);
    SetIfRef(psrcdata->GetIfRef() );
    SetTemplateName(psrcdata->GetTemplateName());
    SetIconType(psrcdata->GetIconType());
    m_StateNums=psrcdata->m_StateNums;
    m_PlaneNums=psrcdata->m_PlaneNums;
}

void CIconData::SaveIconF(CGraphSvgWriter* xio) const
{
    xio->writeStartElement("g");
    SaveBaseProperty( xio);
    CGroupData::SaveSubProperty(xio);
    xio->writeEndElement();
}

void CIconData::LoadIconF(CGraphSvgReader* xio)
{
    LoadBaseProperty(xio);
    CGroupData::LoadSubProperty( xio );
    QList<QGraphicsItem*> items=Item()->childItems();///这里面只包含第一层的子图元，所以要往下再找一层pin/////

    /*
	foreach(QGraphicsItem* subitem, items)
	{
		if (subitem->type() == Hmi::Link)
            ((CLinkLineItem*)subitem)->UpdateLoadedConnection();//////还没有scene，这个接口没法重新建立关联，可用下面的方式//////
	}


    foreach(QGraphicsItem* subitem,items)
    {
        foreach(QGraphicsItem* tmpitem,subitem->childItems())
        {
            if(tmpitem->type()==Hmi::Pin)
                items.append(tmpitem);
        }
    }
    CLinkLineData::UpdateLinks(items);*/

}

void CIconData::LoadBaseProperty(CGraphSvgReader* xio)
{
    G_G(CIconItem);
    QString templateName,userData;
    bool ifRef=false;
    int iType;
    xio->ReadAttribute("template-name",templateName);
    xio->ReadAttribute("if-ref",ifRef);
    xio->ReadAttribute("icon-type",iType);
    xio->ReadAttribute("state-nums",m_StateNums);
    xio->ReadAttribute("plane-nums",m_PlaneNums);
    SetIfRef(ifRef);
    SetTemplateName(templateName);
    SetIconType(iType);
    CGroupData::LoadBaseProperty(xio);
    return;
}

void CIconData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    QString templateName=GetTemplateName();
    QStringRef fileName(&templateName,5,templateName.size()-5);
    xio->WriteAttribute("template-name",templateName);
    xio->WriteAttribute("if-ref",(int)(GetIfRef()));
    xio->WriteAttribute("icon-type",(int)GetIconType());
    xio->WriteAttribute("state-nums",m_StateNums);
    xio->WriteAttribute("plane-nums",m_PlaneNums);

    CGroupData::SaveBaseProperty(xio);
}

void CIconData::SaveSubProperty( CGraphSvgWriter* xio ) const
{
    CGroupData::SaveSubProperty( xio ) ;
    return;
}

int CIconData::SetTemplateName(const QString& name,bool instance)
{
    m_templateName = name;
    if(instance){
        G_G(CIconItem);
        CIconItem* item =(CIconItem*) (UnqIconMng()->DupIcon(m_templateName));
        if (item)
        {
            int gplane=GetPlane();
            foreach(QGraphicsItem* subitem,item->childItems())
            {
                CBaseData* pdata=g_dataPtr(subitem);
                pdata->SetPlane(gplane);
                pdata->SaveState();
                item->removeFromGroup(subitem);
                G->addToGroup(subitem);
            }
            delete item;
            return 1;
        }
    }
    return 0;
}
void CIconData::LoadSubProperty( CGraphSvgReader* xio )
{
    G_G(CIconItem);
    bool ifRef=GetIfRef();
    QString templateName=GetTemplateName();
    if(ifRef)
    {
        const QTransform tf = G->transform();
        G->resetTransform();        
        if(templateName.startsWith(ICONPREFIX))
        {
            int ret=SetTemplateName(templateName,true); //DupIcon
            if (ret==1)
            { //suceed
				xio->skipCurrentElement();
            }
            else
            {
                CGroupData::LoadSubProperty( xio );
            }
        }
        G->setTransform(tf);
        SetLineColor(GetLineColor()); /////重新设置颜色//////
    }
    else
    {
        CGroupData::LoadSubProperty( xio );
    }

    return;
}



QString CIconData::GetSaveTypeName() const
{
    return GetTemplateName();
}

//void CIconData::SetPlane(const short& plane)//modify all children plane, when clone this is error; plane--state is use on child item
//{
//    G_G(CIconItem);
//    foreach(QGraphicsItem *item, G->childItems())
//    {
//        CBaseData* d_ptr = g_dataPtr(item);
//		if (d_ptr)
//		{
//			int oldPlane = d_ptr->GetPlane();
//			d_ptr->SetPlane(plane);
//		}
//    }
//}
bool CIconData::IsPowerIcon()
{
    if(m_IconType>150 && m_IconType<250)
        return true;
    else
        return false;
}

void CIconData::SetState(short state)
{
    G_G(CIconItem);

    QString typeName,planeInfo,isPinPlane;
    int pinNum,stateNum;
    int ret=UnqIconMng()->GetIconType(m_IconType, typeName, pinNum, stateNum, planeInfo, isPinPlane);
	if (ret >= 0){
		//m_StateNums = stateNum;
		if (state >= stateNum || state < 0) {
			//state = 0;
			gInfo("-----IconData::SetState:%d,> stateNum:%d", state, stateNum);
		}
	}
    

    if (state <0) state = 0;

    m_State=state;
    foreach(QGraphicsItem *item, G->childItems())
    {
        CBaseData* d_ptr = g_dataPtr(item);
        int itemState = d_ptr->GetState();
        //if (m_StateNums==1 || m_State == itemState)
		if ( m_State == itemState)
        {
            item->setVisible(true);
        }
        else
        {
            item->setVisible(false);
        }
    }
}
/*
void CIconData::SetTagRefMap(QMap<QString,QString>& tagref)
{
}

void CIconData::SetTxtRefMap(QMap<QString,QString>& txtref)
{
    QMap<QString,QString> oldRef=m_TxtRef;
    QMapIterator<QString, QString> i(oldRef);
    while (i.hasNext())
    {
        i.next();
        QString gg=i.key();
        gg=i.value() ;
    }

    m_TxtRef=txtref;
    foreach (QGraphicsItem *item, Item()->childItems())
    {
        if (item->type()==Hmi::Text)
        {
            QString tmp=((QGraphicsSimpleTextItem*)item)->text();
            QString key=oldRef.key(tmp);
            if (m_TxtRef.find(key)!=m_TxtRef.end())
            {
                ((QGraphicsSimpleTextItem*)item)->setText(m_TxtRef[key]);
            }
        }
    }
}
*/
void CIconData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
	CGroupData::GetPropertyList(property_list);
    property_list.push_back(qMakePair(CBaseData::tr("ifRef"), QVariant(GetIfRef())));
    property_list.push_back(qMakePair(CBaseData::tr("templateName"), QVariant(GetTemplateName())));
    property_list.push_back(qMakePair(CBaseData::tr("iconClass"), QVariant(GetIconType())));
}

bool CIconData::SetProperty( const QString& propname,const QVariant& value )
{
    QPointF lockPoint;
    const QRectF rectF = Item()->boundingRect();
    if (propname ==CBaseData::tr("ifRef") || propname == "ifRef")
    {
        SetIfRef(value.toBool());
    }
    else if (propname == CBaseData::tr("templateName") || propname == "templateName")
    {
        SetTemplateName(value.toString());
    }
    else
		return CGroupData::SetProperty(propname, value);

    return true;
}

QObjectList CIconData::GetLinks(QString pid)
{
    G_G(CIconItem)
    QObjectList ret;
    foreach(QGraphicsItem *item, G->childItems())
    {
        CBaseData* d_ptr = g_dataPtr(item);
        QString name=d_ptr->GetName();
        if (item->type()==Hmi::Pin && (pid=="" || pid==name))
        {
            QSet<CLinkLineItem*> links=((CPinItem*)item)->LinkLineItems();
            foreach (CLinkLineItem * lit, links)
                ret.push_back(g_dataPtr(lit));
        }
    }
    return ret;
}

QObjectList CIconData::GetNodes(QString pid)
{
    QObjectList ret;
    return ret;
}

bool CIconData::IsNullPlane(short planeNo)
{
	G_G(CIconItem);
	foreach(QGraphicsItem *item, G->childItems())
	{
		CBaseData* d_ptr = g_dataPtr(item);
		short pNo = d_ptr->GetPlane();
		if (pNo == planeNo)
		{
			return false;
		}
	}
	return true;
}

void CIconData::SetLineColor(const QColor& color)
{
    m_LineColor=color;
    CGroupData::SetLineColor( color);
}

///////////////////////////////////
CIconItem::CIconItem(QGraphicsItem *parent )
    :CGroupItem(parent)
{
    m_pData=new CIconData(this);
    g_SetData(this,m_pData);
}

CIconItem::~CIconItem()
{
    foreach (QGraphicsItem *item, childItems())
    {
        delete item;
    }
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}
QRectF CIconItem::boundingRect() const
{
	QRectF box = CGroupItem::boundingRect();
	qreal cornerW = box.width() > box.height() ? box.height() / 20 : box.width() / 20;
	if (cornerW > CORNER_RECTPAD)
		cornerW = CORNER_RECTPAD;
	int minl = m_pData->property("minL").toInt();
	int mint = m_pData->property("minT").toInt();
	int metaw = m_pData->property("MetaW").toInt();
	int metah = m_pData->property("MetaH").toInt();
	if (minl > 0 || mint > 0)
		box = box.adjusted(minl - box.x() - cornerW, mint - box.y() - cornerW, cornerW, cornerW);
	if (metaw > 0 && metah > 0)
		box.setSize(QSize(metaw + cornerW * 2, metah + cornerW * 2));

	return box;
}
void CIconItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	CGroupItem::paint(painter, option, widget);
    if(scene() && ((CGraphScene*)scene())->GetSceneType()==Hmi::Explorer)
	{
        QVariant bgcolor=m_pData->property("bgColor");
        if (bgcolor.isValid())
		{
			QPainterPath ipath;
			QRectF box = boundingRect();
			qreal d = box.width() > box.height() ? box.height() / 20 : box.width() / 20;
			if (d > CORNER_RECTPAD)
				d = CORNER_RECTPAD;
			QRectF rc = box.adjusted(d, d, -d, -d);
			ipath.addRect(rc);
            g_PaintBackground(scene(), painter, option, ipath, bgcolor.toString());
		}
	}
}

///////////////
CLayoutItem::CLayoutItem(QGraphicsLayoutItem *parent  , bool isLayout )
    : QGraphicsLayoutItem( parent , isLayout )
{
    //SetGraphicsItem (new QGraphicsRectItem(0,0,50,50) );
}

CLayoutItem::~CLayoutItem()
{
    setGraphicsItem(0);
    delete m_Item;
}

void CLayoutItem::SetGraphicsItem (QGraphicsItem *item )
{
    m_Item = item;
    setGraphicsItem(m_Item);
    m_Item->show();
    //r = QRectF(QPointF(0, 0), pix.size());
}

void CLayoutItem::setGeometry (const QRectF &rect)
{
    if(!m_Item)
        return QGraphicsLayoutItem::setGeometry(rect);
    //m_Item->setTransform(QTransform::fromScale(rect.width() / r.width(),rect.height() / r.height()), true);
	QRectF rc = m_Item->boundingRect();
	QPointF pos=  rc.topLeft() ;
	//pos = m_Item->mapToScene(pos);
	pos = rect.topLeft() - pos;
	m_Item->setPos(pos); 
    r = rect;
}

QSizeF CLayoutItem::sizeHint(Qt::SizeHint which, const QSizeF &constraint  ) const
{
    Q_UNUSED(constraint);
    if(!m_Item)
        return QSizeF(0, 0);
    QSizeF sh;
    switch (which) {
    case Qt::MinimumSize:
        sh = QSizeF(0, 0);
        break;
    case Qt::PreferredSize:
        sh = QSizeF(m_Item->boundingRect().width() , m_Item->boundingRect().height()) ;
        break;
    case Qt::MaximumSize:
        sh = QSizeF(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        break;
    default:
        break;
    }
    return sh;
}

///

FlowLayout::FlowLayout():QGraphicsLayout()
{
    m_spacing[0] = 6;
    m_spacing[1] = 6;
    QSizePolicy sp = sizePolicy();
    sp.setHeightForWidth(true);
    setSizePolicy(sp);
}

void FlowLayout::insertItem(int index, QGraphicsLayoutItem *item)
{
    item->setParentLayoutItem(this);
    if (uint(index) > uint(m_items.count()))
        index = m_items.count();
    m_items.insert(index, item);
    invalidate();
}

int FlowLayout::count() const
{
    return m_items.count();
}

QGraphicsLayoutItem *FlowLayout::itemAt(int index) const
{
    return m_items.value(index);
}

void FlowLayout::removeAt(int index)
{
    m_items.removeAt(index);
    invalidate();
}

qreal FlowLayout::spacing(Qt::Orientation o) const
{
    return m_spacing[int(o) - 1];
}

void FlowLayout::setSpacing(Qt::Orientations o, qreal spacing)
{
    if (o & Qt::Horizontal)
        m_spacing[0] = spacing;
    if (o & Qt::Vertical)
        m_spacing[1] = spacing;
}

void FlowLayout::setGeometry(const QRectF &geom)
{
    QGraphicsLayout::setGeometry(geom);
    doLayout(geom, true);
}

qreal FlowLayout::doLayout(const QRectF &geom, bool applyNewGeometry) const
{
    qreal left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    const qreal maxw = geom.width() - left - right;

    qreal x = 0;
    qreal y = 0;
    qreal maxRowHeight = 0;
    QSizeF pref;
    for (int i = 0; i < m_items.count(); ++i) {
        QGraphicsLayoutItem *item = m_items.at(i);
        pref = item->effectiveSizeHint(Qt::PreferredSize);
        maxRowHeight = qMax(maxRowHeight, pref.height());

        qreal next_x;
        next_x = x + pref.width();
        if (next_x > maxw) {
            if (x == 0) {
                pref.setWidth(maxw);
            } else {
                x = 0;
                next_x = pref.width();
            }
            y += maxRowHeight + spacing(Qt::Vertical);
            maxRowHeight = 0;
        }

        if (applyNewGeometry)
            item->setGeometry(QRectF(QPointF(left + x, top + y), pref));
        x = next_x + spacing(Qt::Horizontal);
    }
    maxRowHeight = qMax(maxRowHeight, pref.height());
    return top + y + maxRowHeight + bottom;
}

QSizeF FlowLayout::minSize(const QSizeF &constraint) const
{
    QSizeF size(0, 0);
    qreal left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    if (constraint.width() >= 0) {   // height for width
        const qreal height = doLayout(QRectF(QPointF(0,0), constraint), false);
        size = QSizeF(constraint.width(), height);
    } else if (constraint.height() >= 0) {  // width for height?
        // not supported
    } else {
        QGraphicsLayoutItem *item;
        foreach (item, m_items)
            size = size.expandedTo(item->effectiveSizeHint(Qt::MinimumSize));
        size += QSize(left + right, top + bottom);
    }
    return size;
}

QSizeF FlowLayout::prefSize() const
{
    qreal left, right;
    getContentsMargins(&left, 0, &right, 0);

    QGraphicsLayoutItem *item;
    qreal maxh = 0;
    qreal totalWidth = 0;
    foreach (item, m_items) {
        if (totalWidth > 0)
            totalWidth += spacing(Qt::Horizontal);
        QSizeF pref = item->effectiveSizeHint(Qt::PreferredSize);
        totalWidth += pref.width();
        maxh = qMax(maxh, pref.height());
    }
    maxh += spacing(Qt::Vertical);

    const qreal goldenAspectRatio = 1.61803399;
    qreal w = qSqrt(totalWidth * maxh * goldenAspectRatio) + left + right;

    return minSize(QSizeF(w, -1));
}

QSizeF FlowLayout::maxSize() const
{
    QGraphicsLayoutItem *item;
    qreal totalWidth = 0;
    qreal totalHeight = 0;
    foreach (item, m_items) {
        if (totalWidth > 0)
            totalWidth += spacing(Qt::Horizontal);
        if (totalHeight > 0)
            totalHeight += spacing(Qt::Vertical);
        QSizeF pref = item->effectiveSizeHint(Qt::PreferredSize);
        totalWidth += pref.width();
        totalHeight += pref.height();
    }

    qreal left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    return QSizeF(left + totalWidth + right, top + totalHeight + bottom);
}

QSizeF FlowLayout::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    QSizeF sh = constraint;
    switch (which) {
    case Qt::PreferredSize:
        sh = prefSize();
        break;
    case Qt::MinimumSize:
        sh = minSize(constraint);
        break;
    case Qt::MaximumSize:
        sh = maxSize();
        break;
    default:
        break;
    }
    return sh;
}


