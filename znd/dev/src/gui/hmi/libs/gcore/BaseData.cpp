
#include "Global.h"
#include "GraphSvgRW.h"
#include "GraphScene.h"
#include "ItemFactory.h"
#include "BaseData.h"
#include "GFunc.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>

#include "ItemFactory.h"
#include "WidgetItem.h"
#include "GroupItem.h"
#include "gloweffect.h"

bool CanLine(QGraphicsItem* item)
{
    return item->type()==Hmi::Text ? false:true;
}

int CanFill(QGraphicsItem* item)
{
    int type=item->type();
    if(type==Hmi::Text)
        return 1; //both pen and brush
    if (type == QGraphicsProxyWidget::Type || type == Hmi::Group || type == Hmi::Pixmap || type >= Hmi::QtChart)
		return -1;//no pen no brush
    if(dynamic_cast<QAbstractGraphicsShapeItem*>(item) && type!=Hmi::Link && type!=Hmi::Polyline  )
    {
        return 2; //both pen and gradient brush
    }
    return 0;//only pen
}

CBaseData::CBaseData(QGraphicsItem* item)
    :QObject(0),
      m_pItem(item),
      m_Plane(0),
      m_OrgLineWidth(1),
      m_OrgRotateAngle(0),
	  m_RotateAxis(Qt::ZAxis),
      m_OrgLineStyle(Qt::SolidLine),
      m_OrgCenter(0, 0),m_BackPixmapName(),m_NameString(),m_Script(),
      m_oldScaleX(1),m_oldScaleY(1),m_oldRotation(0),m_State(0),m_UserData()
{
    if(!item) return;
    item->setFlag(QGraphicsItem::ItemIsMovable, true);
    item->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if (tmpitem)
    {
        QPen pen = tmpitem->pen(); pen.setWidth(1);
        tmpitem->setPen(pen);
	}
	m_transformOrigin = -1;
}

CBaseData::~CBaseData()
{

}

void CBaseData::ResetColor(COLOR_TYPE type)
{
    switch (type) {
    case CBaseData::ALLCOLOR:
    {
		if (CanLine(m_pItem))
            SetLineColor(m_OrgLineColor);
		if (CanFill(m_pItem))
            SetFillColor(m_OrgFillColor);
        break;
    }
    case CBaseData::LINECOLOR:
		if (CanLine(m_pItem))
            SetLineColor(m_OrgLineColor);
        break;
    case CBaseData::FILLCOLOR:
		if (CanFill(m_pItem))
            SetFillColor(m_OrgFillColor);
        break;
    default:
        break;
    }
}

void CBaseData::Remove()
{
    QGraphicsScene* pscene=m_pItem->scene();
    if(pscene){
        pscene->removeItem(m_pItem);
        ((CGraphScene*)pscene)->RemoveItemIdx(m_pItem);
        //delete m_pItem;
    }
}
void CBaseData::PaintOnNail(QPainter *painter, const QStyleOptionGraphicsItem *option, const qreal lineWidth)
{
    QGraphicsItem* item = this->Clone();
    //QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
    //shadow->setBlurRadius(100.0);
    //item->setGraphicsEffect(shadow);

    CBaseData* pData = g_dataPtr(item);
    //QPen pen;
    //pen.setWidthF(lineWidth);
    //pData->SetPen(pen);
    item->paint(painter,option);
    delete item;
}
//for script
QObject* CBaseData::QClone()
{
	QGraphicsItem* item = this->Clone(); 
	CBaseData* pData = g_dataPtr(item);
	if (m_pItem->scene())
		m_pItem->scene()->addItem(item);
	return pData; 
}
//jQuery selector, "*" ,"#id" ,".class" ,"[attribute]","[attribute=value]","[attribute!=value]","[attribute$=value]"
QObjectList CBaseData::Items(const QString & selector)
{
	return UnqFunc()->Selector(selector, m_pItem->childItems());
}

void CBaseData::Copy(const CBaseData* srcData)
{  
    SetLineWidth(srcData->GetLineWidth());
    SetLineColor(srcData->GetLineColor());
	SetLineStyle(srcData->GetLineStyle());
    SetFillColor(srcData->GetFillColor());
    SetFillStyle(srcData->GetFillStyle());
    SetPlane(srcData->GetPlane());
    SetState(srcData->GetState());
    SetUserData(srcData->GetUserData());
	m_OrgFillColor = srcData->GetOrgFillColor();
	m_OrgLineColor = srcData->GetOrgLineColor();
	m_OrgFillStyle = srcData->m_OrgFillStyle;
	m_OrgLineStyle = srcData->m_OrgLineStyle;
    Item()->setOpacity(srcData->m_pItem->opacity());
    Item()->setTransform(srcData->GetTransform());
    m_Plane=srcData->GetPlane();
    foreach(QByteArray prop, srcData->dynamicPropertyNames())
        setProperty( prop.data() , srcData->property(prop.data()).toString());

}

int CBaseData::SetPen(const QPen& pen)
{
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        tmpitem->setPen( pen);
        return 0;
    }
    else
    {
        return -1;
    }
}

QPen CBaseData::Pen()
{
    QPen pen;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        pen=tmpitem->pen();
    }
    return pen;
}

int CBaseData::SetBrush(const QBrush& brush)
{
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        tmpitem->setBrush( brush);
        return 0;
    }
    else
    {
        return -1;
    }
}

QBrush CBaseData::Brush() const
{
    QBrush brush;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        brush=tmpitem->brush();
    }
    return brush;
}

void CBaseData::SetLineStyle(Qt::PenStyle style )
{
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        QPen pen=tmpitem->pen();
        pen.setStyle(style);
        tmpitem->setPen( pen);
    }
 /*   foreach (QGraphicsItem *item, m_pItem->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetLineStyle( style);
    }*/
}

void CBaseData::SetLineDashpattern(QString pattern)
{
	QAbstractGraphicsShapeItem* tmpitem = dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
	if (tmpitem)
	{
		QVector<qreal> vecPattern;
		QStringList lst = pattern.split(" ");
		for (int i = 0; i < lst.size(); i++)
			vecPattern.push_back(lst.at(i).toFloat());

		QPen pen = tmpitem->pen();
		pen.setStyle(Qt::CustomDashLine);
		pen.setDashPattern(vecPattern);
		pen.setCapStyle(Qt::FlatCap);
		tmpitem->setPen(pen);
	}
}

Qt::PenStyle CBaseData::GetLineStyle() const
{
    Qt::PenStyle ret;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        ret=tmpitem->pen().style();
	}
    return ret;
}
QString CBaseData::GetLineDashpattern() const
{
	QString ret="";
	QAbstractGraphicsShapeItem* tmpitem = dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
	if (tmpitem)
	{
		QVector<qreal> pattern = tmpitem->pen().dashPattern();
		for (int i = 0; i < pattern.size();i++)
		{
			ret.append(QString::number(pattern.at(i))+" ");
		}
		ret = ret.left(ret.length()-1);
	}
	return ret;
}


qreal CBaseData::DashOffset()
{
    qreal ret;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        ret=tmpitem->pen().dashOffset();
    }
    return ret;
}

void CBaseData::SetDashOffset(qreal dashOffset)
{
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        QPen pen=tmpitem->pen();
        pen.setDashOffset(dashOffset);
        tmpitem->setPen( pen);
    }
 /*   foreach (QGraphicsItem *item, m_pItem->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetDashOffset( dashOffset);
    }*/
}

void d_setColor(QGraphicsItem *item,const QColor& color)
{
    if(!color.isValid()) return;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(item);
    if(tmpitem)
    {
        QPen tmppen=tmpitem->pen();
        tmppen.setColor(color);
        tmpitem->setPen( tmppen );
	}
    else if(item->type()==Hmi::Line){
        CLineItem* litem=(CLineItem*)item;
        QPen tmp = litem->pen();
        tmp.setColor(color);
        litem->setPen(tmp);
    }

    foreach (QGraphicsItem *subitem, item->childItems())
    {
        d_setColor(subitem,color);
    }
}

void CBaseData::SetLineColor(const QColor& color)
{
    //d_setColor(m_pItem,color);
    if(!color.isValid()) return;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        QPen tmppen=tmpitem->pen();
        tmppen.setColor(color);
        tmpitem->setPen( tmppen );
    }
}

QColor CBaseData::GetLineColor() const
{
    QColor ret;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        ret=tmpitem->pen().color();
	}
    return ret;
}


void d_setWidth(QGraphicsItem *item,qreal width)
{
   QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(item);
    if(tmpitem)
    {
		if (width<0) return;
        QPen tmppen=tmpitem->pen();
        tmppen.setWidthF(width);
		if (width == 0)
			tmppen.setStyle(Qt::NoPen);
        tmpitem->setPen( tmppen );
	}
    foreach (QGraphicsItem *subitem, item->childItems())
    {
        d_setWidth(subitem,width);
    }
}

void CBaseData::SetLineWidth(qreal width)
{
    //d_setWidth(m_pItem,width);
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
     if(tmpitem)
     {
         if (width<0) return;
         QPen tmppen=tmpitem->pen();
         tmppen.setWidthF(width);
         if (width == 0)
             tmppen.setStyle(Qt::NoPen);
         tmpitem->setPen( tmppen );
     }
}

qreal CBaseData::GetLineWidth() const
{
	qreal ret = -1;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
	if (tmpitem)
		ret = tmpitem->pen().widthF();
    return ret;
}

void CBaseData::SetFillColor(const QColor& color)
{
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        QBrush brush=tmpitem->brush();
        brush.setColor(color);
        tmpitem->setBrush( brush);
    }
 /*   foreach (QGraphicsItem *item, m_pItem->childItems())
    {
        CBaseData* d_ptr=g_dataPtr(item);
        if(d_ptr)
            d_ptr->SetFillColor(color);
    }*/
}

QColor CBaseData::GetFillColor() const
{
    QColor ret;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        ret=tmpitem->brush().color();
    }
    return ret;
}

void CBaseData::SetFillStyle(Qt::BrushStyle style )
{
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
	if (tmpitem && style<Qt::LinearGradientPattern)
    {
        QBrush brush=tmpitem->brush();
        brush.setStyle(style);
        tmpitem->setBrush( brush);
    }

}

Qt::BrushStyle CBaseData::GetFillStyle() const
{
    Qt::BrushStyle ret;
    QAbstractGraphicsShapeItem* tmpitem=dynamic_cast<QAbstractGraphicsShapeItem*>(m_pItem);
    if(tmpitem)
    {
        ret=tmpitem->brush().style();
    }
    return ret;
}

void CBaseData::showmat(QTransform abc)
{
    qDebug("%s",QString("%1,%2,%3").arg(abc.m11()).arg(abc.m12()).arg(abc.m13()).toLocal8Bit().data());
    qDebug("%s",QString("%1,%2,%3").arg(abc.m21()).arg(abc.m22()).arg(abc.m23()).toLocal8Bit().data());
    qDebug("%s",QString("%1,%2,%3").arg(abc.m31()).arg(abc.m32()).arg(abc.m33()).toLocal8Bit().data());
}

void CBaseData::Save(CGraphSvgWriter* xio ) const
{
    xio->writeStartElement(GetSaveTagName());
    SaveBaseProperty(xio);
    SaveSubProperty(xio);
    xio->writeEndElement();
}

QString Encode(const QString& str)
{
    QString ret=str;
    return ret.replace('"','!');
}

QString Decode(const QString& str)
{
    QString ret=str;    
    //ret.replace(QRegExp("!tags!(.+?)\."),"!tags!:!zone1.");/////统一tag的sysid///////
    return ret.replace('!','"');
}

void CBaseData::SetScaleX(qreal factor)
{
    QTransform m= Item()->transform();
  // m.scale(factor,1);
    // m.rotate(factor,  Qt::YAxis);
   /*QRectF r =  Item()->mapRectToScene(Item()->boundingRect());//Item()->boundingRect();
   Item()->setTransform(QTransform().translate(m_OrgCenter.x(), m_OrgCenter.y())
                    .rotate(factor, Qt::YAxis)
                    .translate(-m_OrgCenter.x(), -m_OrgCenter.y()));*/

   QRectF r = Item()->sceneBoundingRect();
     r =  Item()->mapRectToScene(Item()->boundingRect());
   Item()->setTransform(QTransform().translate(r.center().x(), r.center().y())
                    .rotate(factor, Qt::YAxis).translate(-r.center().x(), -r.center().y()));
     //m.translate(m.dx(),m.dy()).rotate(factor, Qt::YAxis).translate(-m.dx(),-m.dy());
    // Item()->setTransform(m);// .translate(r.center().x(), r.center().y()).rotate(factor, Qt::YAxis).translate(-r.center().x(), -r.center().y()) );
}

qreal CBaseData::ScaleX()
{
    return Item()->transform().m11() ;
}

void CBaseData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    xio->WriteAttribute("id",GetName());
    xio->WriteAttribute("type-name", GetSaveTypeName());
    if(m_pItem->opacity()!=1)       xio->WriteAttribute("opacity",m_pItem->opacity());
    if(m_pItem->zValue()!=0)        xio->WriteAttribute("z-value",m_pItem->zValue());
    if(m_Plane!=0)                  xio->WriteAttribute("plane",m_Plane);
    xio->WriteAttribute("transform",GetTransform());
    if(GetOrgRotation()!=0)         xio->WriteAttribute("rotation", GetOrgRotation());
    if(GetRotateAxis()!=Qt::ZAxis)  xio->WriteAttribute("rotateAxis", GetRotateAxis());
    if(m_transformOrigin!=-1)       xio->WriteAttribute("transformOrigin", m_transformOrigin);
    if(GetState()!=0)               xio->WriteAttribute("state", GetState());
    if(!GetUserData().isEmpty())    xio->WriteAttribute("user-data", Encode(GetUserData()));
    if(!Effect().isEmpty())         xio->WriteAttribute("effect", Effect());

    int canfill=CanFill(m_pItem);
	if (canfill >= 0)
	{
        if(CanLine(m_pItem))
        {
			qreal linewidth = GetLineWidth();
            int linestyle=GetLineStyle();
            QString linedash=GetLineDashpattern();
            xio->WriteAttribute("stroke", GetLineColor());
            xio->WriteAttribute("stroke-width", linewidth);
            if(linestyle!=Qt::SolidLine)    xio->WriteAttribute("line-style", linestyle);
            if(!linedash.isEmpty())         xio->WriteAttribute("stroke-dasharray",linedash);
        }
		if (canfill > 0){
			QBrush FillBrush = Brush();
			int fillOpacity = 1;
			if (FillBrush.style() == Qt::NoBrush)
			{
				fillOpacity = 0;
			}
			xio->WriteAttribute("fill", GetFillColor());
            if(fillOpacity==0)          xio->WriteAttribute("fill-opacity", fillOpacity);
            if (canfill > 1)            xio->WriteAttribute("fill-pattern", UnqFunc()->GetBrushStyleText(FillBrush, GetBackPixmapName()));
		}
	}
    foreach(QByteArray barray, dynamicPropertyNames())
        xio->writeAttribute(CUSTOMURI,QString(barray),property(barray.data()).toString());
}

QTransform CBaseData::GetTransform() const
{
    QTransform QTTransMatrix;
    if (!Item()->parentItem())
    {
        QTTransMatrix = Item()->sceneTransform();
    }
    else
    {
        QTTransMatrix = Item()->itemTransform(Item()->parentItem());
    }
    return QTTransMatrix;
}

void CBaseData::Load(CGraphSvgReader* xio)
{
    LoadBaseProperty(xio);
    LoadSubProperty(xio);
}

void CBaseData::LoadBaseProperty(CGraphSvgReader* xio)
{
    qreal Opacity=1.0, z, rot;
    QString name,userData,bstr;
    short rAxis,plane=0;
    QTransform Mat;
    int size=0,state=0,lineStyle=1;
	qreal intval = 1;
    QColor color;

    if (xio->ReadAttribute("id",name)>=0)              SetName(name);
    if (xio->ReadAttribute("opacity",Opacity)>=0)      m_pItem->setOpacity(Opacity);
    if (xio->ReadAttribute("z-value",z)>=0)            m_pItem->setZValue(z);
    if (xio->ReadAttribute("plane",plane)>=0)          m_Plane=plane;
    if (xio->ReadAttribute("transform",Mat)>=0)        m_pItem->setTransform(Mat,true);
    if (xio->ReadAttribute("rotation", rot)>=0)        SetOrgRotation(rot);
    if (xio->ReadAttribute("rotateAxis", rAxis)>=0)    SetRotateAxis(rAxis);
    if (xio->ReadAttribute("transformOrigin", m_transformOrigin)>=0)SetTransformOrigin(m_transformOrigin);
    if (xio->ReadAttribute("state", state)>=0)         SetState(state);
    if (xio->ReadAttribute("user-data", userData)>=0 && !userData.isEmpty()) SetUserData(Decode(userData));
    if (xio->ReadAttribute("effect",bstr)>=0 && !bstr.isEmpty()) SetEffect(bstr);

	int canfill = CanFill(m_pItem);
	if (canfill >= 0)
	{
        ShapeStru style;
        int hasstyle=UnqGConfig()->GetShapeStyle(m_pItem->type(),style);
        if(hasstyle>=0 && style.flag.contains("IgnoresTransform"))
            m_pItem->setFlag(QGraphicsItem::ItemIgnoresTransformations);////设置忽略缩放/////

        if(CanLine(m_pItem))
        {
            if (xio->ReadAttribute("stroke", color) == 0) {
                m_OrgLineColor=color;
                SetLineColor(color);
            }

            if (xio->ReadAttribute("stroke-width", intval) == 0){
                if(hasstyle>=0 && style.strokeWidth>=0 && intval>0) /////如果有统一定义则以其为准/////
                    SetLineWidth(style.strokeWidth);
                else
                    SetLineWidth(intval);
            }


            if (xio->ReadAttribute("line-style", lineStyle) == 0) SetLineStyle(Qt::PenStyle(lineStyle));
            if (lineStyle == Qt::CustomDashLine)
            {
                QString pattern;
                if (xio->ReadAttribute("stroke-dashpattern", pattern) == 0) SetLineDashpattern(pattern);//////兼容 之前的属性名stroke-dashpattern,标准svg属性名为stroke-dasharray//////
				if (xio->ReadAttribute("stroke-dasharray", pattern) == 0) SetLineDashpattern(pattern);
            }
        }
		if (canfill > 0)
		{
			int fillOpacity = 1;
            if (xio->ReadAttribute("fill", color) == 0) {
                m_OrgFillColor=color;
                SetFillColor(color);
            }
			if (xio->ReadAttribute("fill-opacity", fillOpacity) == 0)
			{
				if (fillOpacity == 0) SetFillStyle(Qt::NoBrush);
			}
			if (canfill > 1 && xio->ReadAttribute("fill-pattern", bstr) == 0)
			{
				SetBrush(UnqFunc()->SetBrushByText(bstr));
				SetBackPixmapName(UnqFunc()->GetTextureFileName(bstr));
			}
		}
	}

    m_OrgCenter=Item()->boundingRect().center();
    m_OrgCenter=Item()->mapToParent(m_OrgCenter);



    QVariantMap attrs=xio->ReadAttributes(CUSTOMURI);
    foreach (const QString &attrName, attrs.keys())
        setProperty(attrName.toLocal8Bit().data(),attrs.value(attrName).toString());

}

QVariantMap CBaseData::CustomPropertys()
{
    QVariantMap attrs;
    foreach(QByteArray barray, dynamicPropertyNames())
        attrs[QString(barray)]=property(barray.data()) ;
    return attrs;
}

int CBaseData::SetEffect(const QString effect)
{
    if(m_Effect==effect)
        return 0;
    m_Effect=effect;
    QGraphicsEffect* ef=NULL;
    if(effect=="BlurEffect" || effect==tr("BlurEffect"))
    {
        ef=new QGraphicsBlurEffect();
    }
    else if(effect=="DropShadowEffect" || effect== tr("DropShadowEffect"))
    {
        ef=new QGraphicsDropShadowEffect();
    }
    else if(effect=="ColorizeEffect" || effect== tr("ColorizeEffect"))
    {
        ef=new QGraphicsColorizeEffect();
    }
    else if(effect=="OpacityEffect" || effect== tr("OpacityEffect"))
    {
        ef=new QGraphicsOpacityEffect();
    }
    else if (effect=="GlowEffect" || effect == tr("GlowEffect"))
	{
        GlowShadowEffect *eff = new GlowShadowEffect();
		eff->setBlurRadius(8.0);
		eff->setDistance(8.0);
		eff->setColor(Qt::green);
		ef = eff;
	}
	
    Item()->setGraphicsEffect(ef);
    return 0;
}

QObject* CBaseData::SetAnimation(const QString & propertyName,const QVariant& startval ,const QVariant& endval ,int duration ,int loop)
{
    QObject* animate=NULL;
    if(propertyName=="path" )
    {
        animate=UnqFunc()->CreatePathAnimate(Item(),startval.toInt(),duration,loop);
    }
    else
    {
        animate=UnqFunc()->CreateAnimate(this, propertyName,startval,endval,duration,loop);
    }
    animate->setParent(this);
    return animate;
}

QPropertyAnimation* CBaseData::GetAnimation(const QString & propertyName)
{
    QList<QPropertyAnimation *> alls = findChildren<QPropertyAnimation *>();
    QString tmpName=propertyName;
    if(tmpName=="path")
        tmpName="pos";
    for(int i=0;i<alls.size();i++)
    {
        if(alls.at(i)->propertyName()==tmpName)
            return alls.at(i);

    }
    return NULL;
}

QVariant CBaseData::ItemPos()
{
	QVariantMap tmpmap;
	QPointF pos = Item()->pos();
	tmpmap["x"] = pos.x();
	tmpmap["y"] = pos.y();
	return  tmpmap;
}

QVariant CBaseData::Center()
{
    QVariantMap tmpmap;
    QPointF pos=Item()->boundingRect().center();//sceneTransform().map(QPointF(0, 0))
    tmpmap["x"]=pos.x();
    tmpmap["y"]=pos.y();
    return  tmpmap ;
}

QVariant  CBaseData::RoundBox()
{
	QVariantMap tmpmap;
	if (Type() == Hmi::Link)
	{
		QPointF cursorPos;
		QPolygonF ply = ((CLinkLineItem*)Item())->polygon();
		if (ply.size() == 2){
			cursorPos = Item()->mapToScene(QPointF((ply.last() + ply.first()).x() / 2, (ply.last() + ply.first()).y() / 2));
		}
		else if (ply.size() > 2)
			cursorPos = Item()->mapToScene(ply.at(ply.size() / 2));
		tmpmap["x"] = cursorPos.x();
		tmpmap["y"] = cursorPos.y();
		tmpmap["width"] = 0;
		tmpmap["height"] = 0;
	}
	else if (Type() == Hmi::Path)
	{
		QPointF cursorPos;
		QPainterPath ply = ((CPathItem*)Item())->path();
		cursorPos = ply.pointAtPercent(0.5);
		tmpmap["x"] = cursorPos.x();
		tmpmap["y"] = cursorPos.y();
		tmpmap["width"] = 0;
		tmpmap["height"] = 0;
	}
	else
	{		
        //QRectF rect=Item()->mapRectToScene(Item()->boundingRect());//sceneTransform().map(QPointF(0, 0))
        QRectF rect=Item()->mapRectToParent(Item()->boundingRect());
		tmpmap["x"] = rect.x();
		tmpmap["y"] = rect.y();
		tmpmap["width"]=rect.width();
		tmpmap["height"]=rect.height();
	}
    return tmpmap;
}

void CBaseData::SetPos(qreal x,qreal y)
{
    QPointF pos;
    QGraphicsItem* parentItem=m_pItem->parentItem();
    if(parentItem)
    {
        pos= parentItem->boundingRect().center();
    }
    m_pItem->setPos(pos.x()+x,pos.y()+y);
}

void CBaseData::SetFlag(QString flag, bool enabled  )
{
    int gflag=0;
    if(flag.contains("mov",Qt::CaseInsensitive))
        gflag=QGraphicsItem::ItemIsMovable ;
    else if(flag.contains("select",Qt::CaseInsensitive))
        gflag=QGraphicsItem::ItemIsSelectable ;

    m_pItem->setFlag((QGraphicsItem::GraphicsItemFlag)gflag,enabled);

}

QObjectList CBaseData::ChildItems(QString itemType)
{
    QObjectList retlist;
    QList<QGraphicsItem *> items=Item()->childItems( );
    foreach(QGraphicsItem * item,items)
    {
        retlist.append(g_dataPtr(item));
    }
    return retlist;
}

void CBaseData::SetTransformOrigin(float flag)
{
	m_transformOrigin = flag;
    if(flag<0)
        return;
    QRectF rc = Item()->boundingRect();
    QPointF pos;
    switch ((int)flag) {
    case 0:
        pos = rc.center();
        break;
    case 1:
        pos = rc.topLeft();
        break;
    case 2:
        pos = rc.topRight();
        break;
    case 3:
        pos = rc.bottomRight();
        break;
    case 4:
        pos = rc.bottomLeft();
        break;
    default:
        break;
    }
    Item()->setTransformOriginPoint(pos);
}

void CBaseData::Shear(float sx, float sy, float sz,float scale)
{
    if(sx==0 && sy==0 && sz==0 && scale==0)
    {
        m_pItem->resetTransform();
        return;
    }
    QRectF r = m_pItem->boundingRect();
    m_pItem->setTransform(QTransform()
                 .translate(r.width() / 2, r.height() / 2)
                 .rotate(sx, Qt::XAxis)
                 .rotate(sy, Qt::YAxis)
                 .rotate(sz, Qt::ZAxis)
                 .scale(1 + scale, 1 + scale)
                 .translate(-r.width() / 2, -r.height() / 2));
}

QVariant CBaseData::Property(QString name,bool allprop )
{
    QVariant ret;
    if(name=="fill")
        return GetFillColor();
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

void CBaseData::GetBasePropertyLists(QList< QPair<QString, QList<QPair<QString, QVariant> > > >& pptList)
{
    QList< QPair<QString, QVariant> > propertylist;
    CBaseData::GetPropertyList(propertylist);
    pptList.append(QPair<QString, QList<QPair<QString, QVariant> > >(CBaseData::tr("base property:"), propertylist));
}

void CBaseData::GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList)
{
    QList< QPair<QString,QVariant> > propertylist;
	int type = this->Type();
    GetPropertyList(propertylist);
    QString splitname=ItemFactory::ItemTypeName( type);

    if (type==Hmi::Group)
    {
        splitname = CBaseData::tr("group");
    }
    else if (type==Hmi::Icon)
    {
        splitname = CBaseData::tr("symbol");
    }
	else if (type==Hmi::QtChart)
    {
        splitname = CBaseData::tr("chart");
    }
    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >(splitname,propertylist));
    propertylist.clear();
    foreach(QByteArray barray, dynamicPropertyNames())
        propertylist<<qMakePair(QString(barray),property(barray.data()));

    pptList.append(QPair<QString, QList<QPair<QString, QVariant> > >(CBaseData::tr("custom property"), propertylist));
}

void CBaseData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
#if 1
    QPen tmppen=QPen(GetLineStyle());
    property_list.push_back( qMakePair( QString(CBaseData::tr("name")) ,QVariant(GetName()) ) );
    if(CanLine(m_pItem))
    {
        property_list.push_back( qMakePair( QString(CBaseData::tr("stroke")) ,QVariant(GetLineColor()) ) );
        QVariantList lineWidthLst;
        lineWidthLst.append(GetLineWidth());//value
        QJsonObject lineWidthLimit;
        lineWidthLimit["minimum"] = 0;
        lineWidthLst.append(lineWidthLimit);//inputlimit
        property_list.push_back(qMakePair(QString(CBaseData::tr("stroke-width")), QVariant(lineWidthLst)));
        property_list.push_back( qMakePair( QString(CBaseData::tr("line-style")) ,QVariant(tmppen) ) );
    }
    if(CanFill(m_pItem))
    {
        //property_list.push_back( qMakePair( QString(CBaseData::tr("fillColor")) ,QVariant(GetFillColor()) ) );
        property_list.push_back( qMakePair( QString(CBaseData::tr("fill-pattern")) ,QVariant(Brush()) ) );
    }
	QVariantList lst;
	lst.append(m_pItem->opacity());//value
	QJsonObject inputLimit;
	inputLimit["minimum"] = 0;
	inputLimit["maximum"] = 1;
	lst.append(inputLimit);//inputlimit
    property_list.push_back(qMakePair(QString(CBaseData::tr("opacity")), QVariant(lst)));
	QVariantMap vMap = RoundBox().toMap();
    property_list.push_back(qMakePair(QString(CBaseData::tr("postion")), QVariant(QPointF(vMap["x"].toInt() + ACTIVE_RECTPAD, vMap["y"].toInt() + ACTIVE_RECTPAD))));
    
	QMap<QString, QVariant> axisMap;
	axisMap[tr("X")] = Qt::XAxis;
	axisMap[tr("Y")] = Qt::YAxis;
	axisMap[tr("Z")] = Qt::ZAxis;
	axisMap["__CurrentValue"] = GetRotateAxis();
    property_list.push_back(qMakePair(QString(CBaseData::tr("rotateAxis")), QVariant(axisMap)));
	QMap<QString, QVariant> originMap;
	originMap[tr("center")] = 0;
	originMap[tr("topLeft")] = 1;
	originMap[tr("topRight")] = 2;
	originMap[tr("bottomRight")] = 3;
	originMap[tr("bottomLeft")] = 4;
	originMap["__CurrentValue"] = (int)GetTransformOrigin();
    property_list.push_back(qMakePair(QString(CBaseData::tr("transformOrigin")), QVariant(originMap)));

	QVariantList rtlst;
	rtlst.append(GetOrgRotation());//value
	QJsonObject rtInputLimit;
	rtInputLimit["minimum"] = 0;
	rtInputLimit["maximum"] = 360;
	rtlst.append(rtInputLimit);//inputlimit
    property_list.push_back(qMakePair(QString(CBaseData::tr("rotation")), QVariant(rtlst)));
    property_list.push_back( qMakePair( QString(CBaseData::tr("user-data")) ,QVariant(GetUserData() ) ) );

	QVariantList planelst;
	planelst.append(GetPlane());//value
	QJsonObject planeInputLimit;
	planeInputLimit["minimum"] = 0;
	if (m_pItem->scene())
		planeInputLimit["maximum"] = ((CGraphScene*)(m_pItem->scene()))->GetPlaneNums()-1;
	planelst.append(planeInputLimit);//inputlimit
    property_list.push_back(qMakePair(QString(CBaseData::tr("plane")), QVariant(planelst)));

    QMap<QString, QVariant> tmpMap;
	tmpMap[tr("")] = -1;
	tmpMap[tr("BlurEffect")] = Hmi::EFFECT_BlurEffect;
	tmpMap[tr("DropShadowEffect")] = Hmi::EFFECT_DropShadowEffect;
	tmpMap[tr("ColorizeEffect")] = Hmi::EFFECT_ColorizeEffect;
	tmpMap[tr("OpacityEffect")] = Hmi::EFFECT_OpacityEffect;
	tmpMap[tr("GlowEffect")] = Hmi::EFFECT_GlowEffect;

    QMap<QString, QVariant> tmpMap1;
    tmpMap1[ "" ] = -1;
    tmpMap1[ "BlurEffect" ] = Hmi::EFFECT_BlurEffect;
    tmpMap1[ "DropShadowEffect" ] = Hmi::EFFECT_DropShadowEffect;
    tmpMap1[ "ColorizeEffect" ] = Hmi::EFFECT_ColorizeEffect;
    tmpMap1[ "OpacityEffect" ] = Hmi::EFFECT_OpacityEffect;
    tmpMap1[ "GlowEffect" ] = Hmi::EFFECT_GlowEffect;

    tmpMap["__CurrentValue"] = Effect().isEmpty() ? -1 : tmpMap1.value( Effect() );

    property_list.push_back( qMakePair( QString(CBaseData::tr("effect")) ,QVariant(tmpMap) ) );
    QPolygonF gg=m_pItem->mapToScene(m_pItem->boundingRect());
	
#else
    const QMetaObject* metaobject = metaObject();
    int count = metaobject->propertyCount();
    for (int i=0; i<count; ++i)
    {
        QMetaProperty metaproperty = metaobject->property(i);
        const char* name = metaproperty.name();
        property_list<<qMakePair(tr(name), property(name));
    }

#endif
}

bool CBaseData::SetProperty(const QString& propname,const QVariant& value ,bool allprop )
{
    if(allprop==false)////设为动态属性////
       return setProperty(propname.toLocal8Bit().data(), value);
    else
       return SetProperty( propname, value   );
}

bool CBaseData::SetProperty(const QString& propname,const QVariant& value   )
{
    if ( propname== "stroke" ||propname== "lineColor" || propname==CBaseData::tr("stroke") )
    {
        if (value.type() == QVariant::String)
            SetLineColor(QColor(value.toString()));
        else
            SetLineColor(value.value<QColor>());
    }
    else if (propname=="stroke-width" ||propname== "lineWidth" || propname==CBaseData::tr("stroke-width")  )
    {
        SetLineWidth(value.toReal());
    }
    else if (propname== "line-style" || propname=="lineStyle" || propname==CBaseData::tr("line-style"))
    {
		QVariant::Type ty = value.type();
		if (ty == QVariant::Pen)
		{
			QPen p = value.value<QPen>();
			SetLineStyle((Qt::PenStyle)(p.style()));
		}
		else if (ty == QVariant::Int)
		{
			SetLineStyle((Qt::PenStyle)(value.toInt()));
		}
       
    }
    else if (propname== "fill" || propname== "fillColor" || propname==CBaseData::tr("fill") )
    {
        SetFillColor(value.value<QColor>());
    }
    else if ( propname=="fill-pattern" ||propname== "fillStyle" || propname==CBaseData::tr("fill-pattern") )
    {

        SetBrush(UnqFunc()->SetBrushByText( value.value<QString>() ));
		SetBackPixmapName(UnqFunc()->GetTextureFileName(value.value<QString>()));

    }
    else if (propname== "opacity" || propname==CBaseData::tr("opacity") )
    {
        m_pItem->setOpacity(value.toReal());
    }
    else if (propname==CBaseData::tr("postion")||propname== "postion" )
    {
		QVariantMap vMap = RoundBox().toMap();
		QPointF oldTL = QPointF(vMap["x"].toReal(), vMap["y"].toReal());
		QPointF dP = value.toPointF() - oldTL - QPointF(ACTIVE_RECTPAD, ACTIVE_RECTPAD);
		m_pItem->moveBy(dP.x(), dP.y());
    }
    else if (propname==CBaseData::tr("rotation")||propname== "rotation" )
    {
		if (m_transformOrigin == -1)
			SetTransformOrigin(0);
		SetOrgRotation(value.toReal());
        ApplyScaleProperty(m_pItem, value.toReal(), GetOrgScaleX(), GetOrgScaleY(), m_pItem->transformOriginPoint(),(Qt::Axis)GetRotateAxis());
    }
    else if (propname == CBaseData::tr("rotateAxis") || propname == "rotateAxis")
	{
		if (m_transformOrigin == -1)
			SetTransformOrigin(0);
		SetRotateAxis(value.toInt());
		ApplyScaleProperty(m_pItem, GetOrgRotation(), GetOrgScaleX(), GetOrgScaleY(), m_pItem->transformOriginPoint(), (Qt::Axis)value.toInt());
	}
    else if (propname == CBaseData::tr("transformOrigin") || propname == "transformOrigin")
	{
		SetTransformOrigin(value.toInt());
		//ApplyScaleProperty(m_pItem, GetOrgRotation(), GetOrgScaleX(), GetOrgScaleY(), m_pItem->transformOriginPoint(), (Qt::Axis)GetRotateAxis());
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
    else if (propname==CBaseData::tr("fillPercent")||propname== "fillPercent" )
    {
        SetFillPercent(value.toDouble(),1);
    }
    else if (propname == "user-data" || propname == "userData" || propname == CBaseData::tr("user-data"))
    {
        SetUserData(value.toString());
    }
    else if (propname==CBaseData::tr("effect")||propname== "effect" )
    {
        QMap<QString, QVariant> tmpMap;
        tmpMap[""] = -1;
        tmpMap["BlurEffect"] = Hmi::EFFECT_BlurEffect;
        tmpMap["DropShadowEffect"] = Hmi::EFFECT_DropShadowEffect;
        tmpMap["ColorizeEffect"] = Hmi::EFFECT_ColorizeEffect;
        tmpMap["OpacityEffect"] = Hmi::EFFECT_OpacityEffect;
        tmpMap["GlowEffect"] = Hmi::EFFECT_GlowEffect;
		SetEffect(tmpMap.key(value.toInt(), ""));
    }
    else
    {
        bool ret=setProperty(propname.toLocal8Bit().data(), value);
        return false;
    }

    return true;
}

void CBaseData::SetName( const QString& newName )
{
    m_NameString = newName;
    setObjectName(newName);
}

QString CBaseData::GetSaveTagName() const
{
	return ItemFactory::ItemTypeName(Type());
}

QString CBaseData::GetSaveTypeName() const
{
   return ItemFactory::ItemTypeName(Type());
}

void CBaseData::LoadSubProperty( CGraphSvgReader* xio )
{
    xio->skipCurrentElement();
}

void CBaseData::ApplyScaleProperty(QGraphicsItem* item, qreal rotation, qreal scaleX, qreal scaleY, const QPointF& lockPoint, Qt::Axis rotateAxis)
{
    const QPointF center = item->boundingRect().center();
    const QPointF oldPos = item->mapToScene(lockPoint);
	QTransform tf = QTransform()
            .translate(center.x(), center.y())
			.rotate(rotation, rotateAxis)
            .translate(lockPoint.x()-center.x(), lockPoint.y()-center.y())
            .scale(scaleX, scaleY)
            .translate(-lockPoint.x(), -lockPoint.y());

    item->setTransform(tf, false);
    QPointF newPos = item->mapToScene(lockPoint);
    item->moveBy(oldPos.x()-newPos.x(), oldPos.y()-newPos.y());
}

void CBaseData::SetParent(QObject * newParent)
{
    if(newParent==0)
        m_pItem->setParentItem(0);
    else
    {
        CBaseData* pdata=dynamic_cast<CBaseData*>(newParent);
        if(pdata)
            m_pItem->setParentItem(pdata->Item());
    }
}

QString CBaseData::ParentName()
{
    QString retStr="";
    QGraphicsItem* parent=m_pItem->parentItem();
    CBaseData* d_ptr=g_dataPtr(parent);
    if(d_ptr)
        retStr=d_ptr->GetName();

    return retStr;
}
int CBaseData::Type() const 
{
	int type = m_pItem->type();
	if (type == QGraphicsProxyWidget::Type)
	{
		CWidgetItem* pItem = (CWidgetItem*)m_pItem;
		type = pItem->widgetType();
	}
	return type;
};
QString CBaseData::TypeName()
{
    return ItemFactory::ItemTypeName(Type());
}

int CBaseData::IconType()
{
    int type = m_pItem->type();
    if (type == Hmi::Icon)
    {
        return ((CIconData*)this)->GetIconType() ;
    }
    return -1;
}

void CBaseData::SaveState()
{
    m_OrgCenter=Item()->boundingRect().center();
    m_OrgCenter=Item()->mapToParent(m_OrgCenter);
    m_OrgLineColor=GetLineColor();
    m_OrgFillColor=GetFillColor();

}

///
CGConfig * UnqGConfig()
{
    static CGConfig _CGConfig_instance;
    return &_CGConfig_instance;
}

CGConfig::CGConfig()
{
   InitConfig();
}
void CGConfig::InitConfig()
{
    QString fn=UnqFunc()->GetDir(CGFunc::PATH_TYPE_SCRIPT)+"gconfig.cfg";
    QString str=UnqFunc()->LoadFile(fn);
    if(!str.isEmpty()){
        QJsonObject jobj=UnqFunc()->Str2Json(str);
        QJsonArray jarr= jobj["shapeStyle"].toArray();
        for(int i=0;i<jarr.size();++i){
            QJsonObject jitem=jarr[i].toObject();
            QString typeName = jitem["shape"].toString();
            int itemType=ItemFactory::ItemType(typeName);
            QJsonObject style=jitem["style"].toObject();
            ShapeStru shape(QColor(),-1);
            if(!style["stroke"].isUndefined()) shape.strokeColor=QColor(style["stroke"].toString());
            if(!style["stroke-width"].isUndefined()) shape.strokeWidth=style["stroke-width"].toDouble();
            if(!style["line-style"].isUndefined()) shape.penStyle=(Qt::PenStyle)style["line-style"].toInt();
            if(!style["fill-style"].isUndefined()) shape.brushStyle=(Qt::BrushStyle)style["fill-style"].toInt();
            if(!style["fill"].isUndefined()) shape.fillColor=QColor(style["fill"].toString());
			if (!style["flag"].isUndefined()) shape.flag =  style["flag"].toString() ;
            m_StyleMap[itemType]=shape;
        }
    }
}

int  CGConfig::GetShapeStyle(int shape_type,ShapeStru& style)
{
    if(m_StyleMap.find(shape_type)!=m_StyleMap.end()){
        style=m_StyleMap[shape_type];
        return 0;
    }
    else
        return -1;
}
