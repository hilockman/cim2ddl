
#include "Global.h"
#include "GraphItem.h"
#include "GraphSvgRW.h"
#include "ItemFactory.h"
#include "GraphScene.h"
#include "GFunc.h"
#include "IconMng.h"

#ifdef GLUT
#include <QtOpenGL>
#include "GL/glut.h"
#endif

int PATHSTROKER=5;
const ShapeStru CPinItem::s_shapeData = ShapeStru(Qt::black,1);
bool g_ifExplorer(QGraphicsScene *pscene )
{
    if(pscene && ((CGraphScene*)pscene)->GetSceneType()==Hmi::Explorer)
        return true;
    else
        return false;
}

void g_HighlightSelected(QGraphicsScene *pscene, QPainter *painter, const QStyleOptionGraphicsItem *option, const QVector<QPointF>& pointFVec, const qreal& corner_width, bool insideDraw, const QColor& rectColor)
{
    if(g_ifExplorer(pscene ))
            return;

    //painter->save();
	qreal cornerW = corner_width;
	if (corner_width > CORNER_RECTPAD)
		cornerW = CORNER_RECTPAD;
	QPointF CORNER_POINT(cornerW, cornerW);
	QSizeF BLUERECT_SIZE(cornerW * 2, cornerW * 2);
    painter->setBrush(QBrush(Qt::white));
    QPen pen(QColor(rectColor), 0, Qt::SolidLine );
    //pen.setCosmetic( true );
    pen.setWidthF( 0 );
    painter->setPen(pen);
	painter->setOpacity(painter->opacity()*0.7);
    QVarLengthArray<QRectF> cornerRectArr;
    if(!insideDraw)
    {
        for(int i=0; i<pointFVec.size(); ++i)
        {
			cornerRectArr.append(QRectF(pointFVec[i] - CORNER_POINT, pointFVec[i] + CORNER_POINT));
        }
    }
    else
    {
        cornerRectArr.append(QRectF(pointFVec[0], BLUERECT_SIZE));
		cornerRectArr.append(QRectF(pointFVec[1] - QPointF(cornerW * 2, 0), BLUERECT_SIZE));
		cornerRectArr.append(QRectF(pointFVec[2] - QPointF(0, cornerW * 2), BLUERECT_SIZE));
		cornerRectArr.append(QRectF(pointFVec[3] - QPointF(cornerW * 2, cornerW * 2), BLUERECT_SIZE));
		if (pointFVec.size() == 8){
			cornerRectArr.append(QRectF(pointFVec[4] - QPointF(cornerW, 0), BLUERECT_SIZE));
			cornerRectArr.append(QRectF(pointFVec[5] - QPointF(0, cornerW), BLUERECT_SIZE));
			cornerRectArr.append(QRectF(pointFVec[6] - QPointF(cornerW * 2, cornerW), BLUERECT_SIZE));
			cornerRectArr.append(QRectF(pointFVec[7] - QPointF(cornerW, cornerW * 2), BLUERECT_SIZE));
		}
    }
    painter->drawRects(cornerRectArr.data(), cornerRectArr.size());
}


void g_PaintBoundingRect(QGraphicsScene *pscene, QPainter* painter, const QStyleOptionGraphicsItem *option, const QRectF& rect, const qreal& corner_width)
{
    if(g_ifExplorer(pscene ))
            return;
    QRectF tmprc=rect;
	qreal cornerW = corner_width;
	if (corner_width > CORNER_RECTPAD)
		cornerW = CORNER_RECTPAD;
	tmprc.adjust(cornerW, cornerW, -cornerW, -cornerW);
	const QColor fgcolor = Qt::green;//option->palette.windowText().color();
    const QColor bgcolor(
                fgcolor.red() > 127 ? 0 : 255,
                fgcolor.green() > 127 ? 0 : 255,
                fgcolor.blue() > 127 ? 0 : 255);
    QPen pen(QColor(fgcolor), 0, Qt::DashLine );
    pen.setCosmetic( true );

    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(tmprc);
}

void g_PaintBackground(QGraphicsScene *pscene, QPainter* painter, const QStyleOptionGraphicsItem *option, const QPainterPath& path, const QString& color)
{
	if (!g_ifExplorer(pscene))
		return;
	QColor bgcolor = QColor(color);
	if (!bgcolor.isValid())
		return;
	QPen pen(QColor(bgcolor), 0, Qt::SolidLine);
	pen.setCosmetic(true);
	pen.setWidth(10);
	painter->setPen(pen);
    painter->setOpacity(painter->opacity()*0.3);
	painter->drawPath(path);
}

void g_SetData( QGraphicsItem* item,CBaseData* pdata )
{
    Q_ASSERT(pdata);
    QVariant Var;
    Var.setValue(pdata);
    item->setData(BASEKEY, Var);
}



CPolygonData::CPolygonData(QGraphicsItem* item):CBaseData(item)
{
    m_FillPercent=1;
    m_Vflag = true;
    m_pGradient = NULL;
}

void CPolygonData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CPolygonItem* pItem=(CPolygonItem*)Item();
    xio->WriteAttribute("points",pItem->polygon());
    CPolylineItem* pline=dynamic_cast<CPolylineItem*>(Item());
    if(pline)
    {
        if(pline->m_StartArrowType!=0 && pline->m_EndArrowType!=0)
        {
            QString arrInfo=QString("%1,%2,%3,%4").arg(pline->m_StartArrowType).arg(pline->m_EndArrowType).arg(pline->m_StartArrowSize).arg(pline->m_EndArrowSize);
            xio->WriteAttribute("arrow",arrInfo);
        }
		xio->WriteAttribute("fill", QString("none"));
    }
    CBaseData::SaveBaseProperty(xio);
}

void CPolygonData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CPolygonItem* pItem=(CPolygonItem*)Item();
    QPolygonF polygon;
    xio->ReadAttribute("points",polygon);
    pItem->setPolygon(polygon);
    CPolylineItem* pline=dynamic_cast<CPolylineItem*>(Item());
    if(pline)
    {
        QString arrInfo;
        xio->ReadAttribute("arrow",arrInfo);
        QStringList arrls=arrInfo.split(",");
        if(arrls.size()==4)
        {
            pline->m_StartArrowType =arrls[0].toInt();
            pline->m_EndArrowType =arrls[1].toInt();
            pline->m_StartArrowSize =arrls[2].toInt();
            pline->m_EndArrowSize =arrls[3].toInt();
            //pline->update();
        }
    }
    CBaseData::LoadBaseProperty(xio);
}

void CPolygonData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CBaseData::GetPropertyList( property_list);
    QPolygonF ps=((CPolygonItem*)Item())->polygon();
    QString points;
    QTextStream oss(&points);
    for(int i = 0;i < ps.size();i++)
    {
        if (i != 0) oss<<" ";
        oss<<ps[i].x()<<","<<ps[i].y();
    }
    property_list.push_back( qMakePair( CBaseData::tr("position") ,QVariant(oss.readAll()) ) );
	if (ps.size() == 2)
	{
		QPointF dp = ps[1] - ps[0];
        property_list.push_back(qMakePair(CBaseData::tr("length"), QVariant(dp.manhattanLength())));
	}
    CPolylineItem* pline=dynamic_cast<CPolylineItem*>(Item());
    if(pline)
    {
        QString arrInfo=QString("%1,%2,%3,%4").arg(pline->m_StartArrowType).arg(pline->m_EndArrowType).arg(pline->m_StartArrowSize).arg(pline->m_EndArrowSize);
        QMap<QString, QVariant> tmpMap;
        tmpMap[CBaseData::tr("ARROW_NULL")] = Hmi::ARROW_NULL;
        tmpMap[CBaseData::tr("ARROW_SOLID_ARROW")] = Hmi::ARROW_SOLID_ARROW;
        tmpMap[CBaseData::tr("ARROW_HOLLOW_ARROW")] = Hmi::ARROW_HOLLOW_ARROW;
        tmpMap[CBaseData::tr("ARROW_SOLID_BACKARROW")] = Hmi::ARROW_SOLID_BACKARROW;
       // tmpMap[CBaseData::tr("ARROW_SOLID_CIRCLE")] = Hmi::ARROW_SOLID_CIRCLE;
       // tmpMap[CBaseData::tr("ARROW_HOLLOW_CIRCLE")] = Hmi::ARROW_HOLLOW_CIRCLE;
        tmpMap[CBaseData::tr("ARROW_SOLID_DIAMOND")] = Hmi::ARROW_SOLID_DIAMOND;
        tmpMap[CBaseData::tr("ARROW_HOLLOW_DIAMOND")] = Hmi::ARROW_HOLLOW_DIAMOND;
        tmpMap[CBaseData::tr("ARROW_SOLID_RECT")] = Hmi::ARROW_SOLID_RECT;
        tmpMap[CBaseData::tr("ARROW_HOLLOW_RECT")] = Hmi::ARROW_HOLLOW_RECT;
        QMap<QString, QVariant> sizeMap;
        sizeMap[CBaseData::tr("SIZE_10_8")] = Hmi::ARROW_SIZE_10_8;
        sizeMap[CBaseData::tr("SIZE_10_10")] = Hmi::ARROW_SIZE_10_10;
        sizeMap[CBaseData::tr("SIZE_10_12")] = Hmi::ARROW_SIZE_10_12;
        tmpMap["__CurrentValue"] = (int)pline->m_StartArrowType;
        sizeMap["__CurrentValue"] = (int)pline->m_StartArrowSize;
        property_list.push_back(QPair<QString, QVariant>( CBaseData::tr("startArrowStyle"), QVariant(tmpMap)));
        property_list.push_back(QPair<QString, QVariant>(CBaseData::tr("startArrowSize"), QVariant(sizeMap)));
        tmpMap["__CurrentValue"] = (int)pline->m_EndArrowType;
        sizeMap["__CurrentValue"] = (int)pline->m_EndArrowSize;
        property_list.push_back(QPair<QString, QVariant>( CBaseData::tr("endArrowStyle"), QVariant(tmpMap)));
        property_list.push_back(QPair<QString, QVariant>(CBaseData::tr("endArrowSize"), QVariant(sizeMap)));
    }
}

bool CPolygonData::SetProperty(const QString& propname,const QVariant& value)
{
    CPolylineItem* pline=dynamic_cast<CPolylineItem*>(Item());
    if(pline)
    {
        if (propname == CBaseData::tr("startArrowStyle") || propname == "startArrowStyle") {
            pline->m_StartArrowType = value.toInt();
			pline->update();
        }
        else if (propname == CBaseData::tr("endArrowStyle") || propname == "endArrowStyle") {
            pline->m_EndArrowType = value.toInt();
			pline->update();
        }
        else if (propname == CBaseData::tr("startArrowSize") || propname == "startArrowSize") {
            pline->m_StartArrowSize = value.toInt();
			pline->update();
        }
        else if (propname == CBaseData::tr("endArrowSize") || propname == "endArrowSize") {
            pline->m_EndArrowSize = value.toInt();
			pline->update();
        }
        else if (propname == CBaseData::tr("length") || propname == "length")
        {
			QPolygonF ply = pline->polygon();
			if (ply.count() == 2)
			{
				QLineF line(ply[0], ply[1]);
				line.setLength(value.toReal());
				ply[1] = line.p2();
				pline->setPolygon(ply);
			}
        }
        else
            CBaseData::SetProperty(propname, value);
    }else
        CBaseData::SetProperty(propname, value);
    
    return false;
}

QGraphicsItem* CPolygonData::Clone()
{
	int type = m_pItem->type();
	if (type == Hmi::Polygon)
	{
		CPolygonItem* pGonItem = (dynamic_cast<CPolygonItem*>(m_pItem))->Clone();
		return pGonItem;
	}
	else if (type == Hmi::Polyline)
	{
		CPolylineItem* pLineItem = (dynamic_cast<CPolylineItem*>(m_pItem))->Clone();
		return pLineItem;
	}
	return NULL;
}

void CPolygonData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    G_G(CPolygonItem)
            CPolygonItem* psrcItem=(CPolygonItem*)(srcData->Item());
    G->setPolygon(psrcItem->polygon() );
    SetFillPercent(((CPolygonData*)srcData)->FillPercent());
}

void CPolygonData::SetArrowInfo(const QString& arrowinfo)
{
    if (m_pItem->type() == Hmi::Polyline)
    {
        QStringList tmplst=arrowinfo.split(",");
        if(tmplst.size()>=4)
            ((CPolylineItem*)m_pItem)->SetArrowInfo(tmplst[0].toInt(),tmplst[1].toInt(),tmplst[2].toInt(),tmplst[3].toInt());
    }
}

////
CPolygonItem::CPolygonItem(QGraphicsItem *parent, int type) : m_type(type), QGraphicsPolygonItem(parent)
{
    m_pData=new CPolygonData(this);
    g_SetData(this, m_pData);
}

CPolygonItem* CPolygonItem::Clone( )
{
    CPolygonItem* pgonItem = new CPolygonItem();
    pgonItem->setPolygon(polygon());
    g_dataPtr(pgonItem)->Copy(g_dataPtr(this));
    return pgonItem;
}

CPolygonItem::~CPolygonItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

void CPolygonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    QBrush fillbrush = brush();
    UnqFunc()->ProcessBrush(boundingRect(),fillbrush);
    painter->setBrush(fillbrush);
    if (m_pData->FillPercent()==1)
    {
        painter->drawPolygon( polygon(), fillRule());
    }
    else
    {
        painter->setBrush(Qt::NoBrush);
        painter->drawPolygon( polygon());
        painter->setBrush(brush());

        QRectF rect=QGraphicsPolygonItem::boundingRect();
        if (m_pData->GetFillDir()==1)
            rect.setTop(rect.bottom() - rect.height()*m_pData->FillPercent());
        else
            rect.setRight(rect.left() + rect.width()*m_pData->FillPercent());
        QPainterPath subject; subject.addPolygon(polygon());
        QPainterPath clip; clip.addRect(rect);
        QPainterPath dpath=subject.intersected(clip);
        painter->drawPath( dpath);
    }
    if  (option->state & (QStyle::State_Selected |QStyle::State_HasFocus))//QStyle::State_Selected |
    {
		g_HighlightSelected(scene(), painter, option, polygon(), pen().width());
		g_PaintBoundingRect(scene(), painter, option, boundingRect(), pen().width());
    }
}

QRectF CPolygonItem::boundingRect() const
{
	qreal cornerW = pen().width();
	return QGraphicsPolygonItem::boundingRect().adjusted(-cornerW, -cornerW, cornerW, cornerW);
}

CPolylineItem::CPolylineItem(QGraphicsItem *parent, int type) : CPolygonItem(parent,type)
{
    m_StartArrowType=Hmi::ARROW_NULL;
    m_EndArrowType=Hmi::ARROW_NULL;
    m_StartArrowSize=Hmi::ARROW_SIZE_10_8;
    m_EndArrowSize=Hmi::ARROW_SIZE_10_8;

}
CPolylineItem* CPolylineItem::Clone()
{
	CPolylineItem* pgonItem = new CPolylineItem();
	pgonItem->setPolygon(polygon());
	g_dataPtr(pgonItem)->Copy(g_dataPtr(this));
	return pgonItem;
}
QRectF CPolylineItem::boundingRect() const
{
	qreal cornerW = pen().width();
	return polygon().boundingRect().adjusted(-cornerW, -cornerW, cornerW, cornerW);
}

QVariant CPolylineItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    return QGraphicsItem::itemChange(change, value);
}

QPainterPath CPolylineItem::shape() const
{
    QPainterPath path;
    path.addPolygon(polygon());
    QPainterPathStroker strok;
    strok.setWidth(pen().widthF()*PATHSTROKER);
    return strok.createStroke(path);
}

void CPolylineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    paintEx( painter,polygon(), option );

}
void CPolylineItem::SetArrowInfo(int arrow_start_type, int arrow_start_size, int arrow_end_type, int arrow_end_size)
{
    if(arrow_start_type>=0) m_StartArrowType=arrow_start_type;
    if(arrow_start_size>=0) m_StartArrowSize=arrow_start_size;
    if(arrow_end_type>=0) m_EndArrowType=arrow_end_type;
    if(arrow_end_size>=0) m_EndArrowSize=arrow_end_size;
}

//arrow_pos1 pointAt first point,arrow_pos2 pointAt last point,
void CPolylineItem::paintEx(QPainter *painter, const QPolygonF &polygon,const QStyleOptionGraphicsItem *option   )
{
    QBrush fillbrush = brush();
    QPen curpen = pen();

    if(brush().style()==Qt::VerPattern)//flow effect
    {
        QPen pen1(Qt::black, curpen.widthF()+2);//,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin);
        QPen pen2(fillbrush.color(), curpen.widthF()-1 );
        painter->setPen(pen1);
        painter->drawPolyline( polygon );
        painter->setPen(pen2);
        painter->drawPolyline( polygon );
    }
    //curpen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(curpen );
    UnqFunc()->DrawArrowPline( painter,polygon, m_StartArrowType, m_StartArrowSize, m_EndArrowType,m_EndArrowSize, option);
    if (option->state & QStyle::State_Selected)
    {
		g_HighlightSelected(scene(), painter, option, polygon, pen().width());
        //g_PaintBoundingRect(scene(),painter, option, boundingRect());
		if (m_EndArrowType > 0 || m_StartArrowType > 0)
		{
			scene()->update();
		}
    }
}
////////////////////

void CLineData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    CLineItem* pItem=(CLineItem*)Item();
    CLineItem* psrcItem=(CLineItem*)(srcData->Item());
    pItem->setLine(psrcItem->line());
}
QGraphicsItem* CLineData::Clone()
{
    CLineItem* plItem = new CLineItem();
    g_dataPtr(plItem)->Copy( this);
    return plItem;
}
void CLineData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CLineItem* pItem=(CLineItem*)Item();
    QLineF line= pItem->line();
    xio->WriteAttribute("x1",line.x1());
    xio->WriteAttribute("y1",line.y1());
    xio->WriteAttribute("x2",line.x2());
    xio->WriteAttribute("y2",line.y2());
    CBaseData::SaveBaseProperty(xio);
}

void CLineData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CLineItem* pItem=(CLineItem*)Item();
    qreal x1,y1,x2,y2;
    xio->ReadAttribute("x1", x1);
    xio->ReadAttribute("y1", y1);
    xio->ReadAttribute("x2", x2);
    xio->ReadAttribute("y2", y2);
    pItem->setLine(QLineF(x1,y1,x2,y2));
    CBaseData::LoadBaseProperty(xio);
}

void CLineData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CBaseData::GetPropertyList(property_list);
    CLineItem* pItem = (CLineItem*)Item();

    property_list.push_back(qMakePair(CBaseData::tr("length"), QVariant(pItem->line().length())));
    property_list.push_back(qMakePair(CBaseData::tr("point1"), QVariant(pItem->line().p1())));
    property_list.push_back(qMakePair(CBaseData::tr("point2"), QVariant(pItem->line().p2())));
    property_list.push_back(qMakePair(CBaseData::tr("width"), QVariant(pItem->line().dx())));
    property_list.push_back(qMakePair(CBaseData::tr("height"), QVariant(pItem->line().dy())));
}

void CLineData::SetTransformOrigin(float flag)
{
    if(flag<0 || flag>1 ) return;
    CLineItem* pItem=(CLineItem*)Item();
    QLineF line= pItem->line();
    QPointF pos=line.pointAt(flag);
    Item()->setTransformOriginPoint(pos);
}

bool CLineData::SetProperty(const QString& propname,const QVariant& value)
{
    CLineItem* pItem = (CLineItem*)Item();
    if (propname == CBaseData::tr("length") || propname == "length")
    {
        QLineF line = pItem->line();
        line.setLength(value.toReal());
        pItem->setLine(line);
    }
    else if (propname == "width"||propname == CBaseData::tr("width")   )
    {
        QLineF line = pItem->line();
        QPointF p1=line.p1();
        QPointF p2=line.p2();
        qreal ww=value.toReal();
        if(p2.x()==p1.x())
            return false;
        else if(p2.x()>p1.x())
            p2.setX(p1.x()+ww);
        else
            p1.setX(p2.x()+ww);

        pItem->setLine(QLineF(p1,p2));
    }
    else if (propname == "height"||propname == CBaseData::tr("height")   )
    {
        QLineF line = pItem->line();
        QPointF p1=line.p1();
        QPointF p2=line.p2();
        qreal hh=value.toReal();
        if(p2.y()==p1.y())
            return false;
        else if(p2.y()>p1.y())
            p2.setY(p1.y()+hh);
        else
            p1.setY(p2.y()+hh);

        pItem->setLine(QLineF(p1,p2));
    }
    else if (propname == "point1"||propname == CBaseData::tr("point1")   )
    {
        QLineF line = pItem->line();
        line.setP1(value.toPointF());
        pItem->setLine(line);
    }
    else if (propname == "point2"||propname == CBaseData::tr("point2")   )
    {
        QLineF line = pItem->line();
        line.setP2(value.toPointF());
        pItem->setLine(line);
    }
    else
        return CBaseData::SetProperty( propname, value);
}

QColor CLineData::GetLineColor() const
{
    G_G(CLineItem)
            return G->pen().color();
}


void CLineData::SetFillColor(const QColor& color)
{
    return ;
}
QColor CLineData::GetFillColor() const
{
    return Qt::transparent;
}
Qt::BrushStyle CLineData::GetFillStyle() const
{
    return Qt::SolidPattern;
}
void CLineData::SetFillStyle(Qt::BrushStyle style)
{
    return;
}

Qt::PenStyle CLineData::GetLineStyle() const
{
    G_G(CLineItem);
    return G->pen().style();
}
void CLineData::SetLineStyle(Qt::PenStyle style)
{
    G_G(CLineItem);
    QPen tmp = G->pen();tmp.setStyle(style);
    G->setPen(tmp);
}
qreal CLineData::GetLineWidth() const
{
    G_G(CLineItem);
    return G->pen().widthF();
}
void CLineData::SetLineWidth(qreal width)
{
    G_G(CLineItem);
    QPen tmp = G->pen();
	tmp.setWidthF(width);
    G->setPen(tmp);
}
void CLineData::SetLineColor(const QColor& color)
{
    G_G(CLineItem);
    QPen tmp = G->pen();tmp.setColor(color);
    G->setPen(tmp);
}

CLineItem::CLineItem( QGraphicsItem *parent )
    :QGraphicsLineItem(parent)
{
    m_pData=new CLineData(this);
    g_SetData(this,m_pData);
}

CLineItem::CLineItem( const QLineF & line, QGraphicsItem * parent )
    :QGraphicsLineItem(line, parent)
{
    m_pData=new CLineData(this);
    g_SetData(this,m_pData);
}

CLineItem::~CLineItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

QRectF CLineItem::boundingRect() const
{
/*    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);*/

    const qreal x1 = line().p1().x();
    const qreal x2 = line().p2().x();
    const qreal y1 = line().p1().y();
    const qreal y2 = line().p2().y();
    qreal lx = qMin(x1, x2);
    qreal rx = qMax(x1, x2);
    qreal ty = qMin(y1, y2);
    qreal by = qMax(y1, y2);
	qreal cornerW = pen().width();
	return QRectF(lx, ty, rx - lx, by - ty).adjusted(-cornerW, -cornerW, cornerW, cornerW);//adjusted boundRect to refresh the area of g_HighlightSelected rect when move item
}

QPainterPath CLineItem::shape() const
{
    QPainterPath path;
    if (line().isNull())
        return path;
    path.moveTo(line().p1());
    path.lineTo(line().p2());
    QPainterPathStroker strok;
    strok.setWidth(pen().widthF()*PATHSTROKER);
    return strok.createStroke(path);
}

void CLineItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    Q_UNUSED(widget);
    painter->setPen(pen());
    painter->drawLine(line());
    if (option->state & QStyle::State_Selected)
    {
        QVector<QPointF> vec;
        vec<<line().p1()<<line().p2();
		g_HighlightSelected(scene(), painter, option, vec, pen().width());
    }
}
/////////CRectData
QGraphicsItem* CRectData::Clone()
{
    CRectItem* pItem = new CRectItem();
    g_dataPtr(pItem)->Copy(this);
    return pItem;
}
void CRectData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    CRectData* pSrcRc=(CRectData*)srcData;
    G_G(CRectItem)
            CRectItem* psrcItem=(CRectItem*)(srcData->Item());
    G->setRect(psrcItem->rect());
    SetRx(pSrcRc->Rx());
    SetRy(pSrcRc->Ry());
    m_ShadowType=pSrcRc->m_ShadowType;
}
void CRectData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CRectItem* pItem=(CRectItem*)Item();
    QRectF rc= pItem->rect();
    xio->WriteAttribute("x",rc.x());
    xio->WriteAttribute("y",rc.y());
    xio->WriteAttribute("width",rc.width());
    xio->WriteAttribute("height",rc.height());
    xio->WriteAttribute("rx",rx);
    xio->WriteAttribute("ry",ry);
    xio->WriteAttribute("shadow",m_ShadowType);
    CBaseData::SaveBaseProperty(xio);
}

void CRectData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CRectItem* pItem=(CRectItem*)Item();
    qreal x,y,width,height;
    xio->ReadAttribute("x", x);
    xio->ReadAttribute("y", y);
    xio->ReadAttribute("width", width);
    xio->ReadAttribute("height", height);
    xio->ReadAttribute("rx", rx);
    xio->ReadAttribute("ry", ry);
    xio->ReadAttribute("shadow",m_ShadowType);
    pItem->setRect(QRectF(x,y,width,height));
    CBaseData::LoadBaseProperty(xio);
}

void CRectData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CRectItem* pItem=(CRectItem*)Item();
    CBaseData::GetPropertyList( property_list);
    property_list.push_back(qMakePair(CBaseData::tr("width"), QVariant(pItem->rect().width())));
    property_list.push_back(qMakePair(CBaseData::tr("height"), QVariant(pItem->rect().height())));
    property_list.push_back( qMakePair( CBaseData::tr("r") ,QVariant(QSize(rx,ry)) ) );

    QMap<QString, QVariant> tmpMap;
    tmpMap[CBaseData::tr("flat")] = CRectData::NoShadow;
    tmpMap[CBaseData::tr("up")] = CRectData::ShadowUp;
    tmpMap[CBaseData::tr("down")] = CRectData::ShadowDown;
    tmpMap["__CurrentValue"] =  m_ShadowType;
    property_list.push_back(QPair<QString, QVariant>( CBaseData::tr("shadowType"), QVariant(tmpMap)));

}

bool CRectData::SetProperty(const QString& propname,const QVariant& value)
{
    CRectItem* pItem=(CRectItem*)Item();
    if (propname == "rect" || propname == CBaseData::tr("rect") )
    {
		QRectF rf = pItem->mapFromScene(value.toRectF()).boundingRect();
		pItem->setRect(rf);
    }
    else if (propname == "width" || propname == CBaseData::tr("width")  )
    {
        QRectF rct = pItem->rect();
        rct.setWidth(value.toFloat());
        pItem->setRect(rct);
    }
    else if (propname == "height" || propname == CBaseData::tr("height")  )
    {
        QRectF rct = pItem->rect();
        rct.setHeight(value.toFloat());
        pItem->setRect(rct);
    }
    else if (propname == "r" || propname == CBaseData::tr("r")  )
    {
        rx=value.toSizeF().rwidth();
        ry=value.toSizeF().rheight();
        pItem->update();
    }
    else if (propname == "shadowType" || propname == CBaseData::tr("shadowType"))
    {
        m_ShadowType=value.toInt();
    }
    else
        return CBaseData::SetProperty( propname, value);

    return true;
}
///
CRectItem::CRectItem( QGraphicsItem *parent )
    :QGraphicsRectItem(parent)
{
    m_pData=new CRectData(this);
    g_SetData(this,m_pData);
}

CRectItem::~CRectItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

QRectF CRectItem::boundingRect() const
{
	qreal cornerW = rect().width() > rect().height() ? rect().height() / 20 : rect().width() / 20;
	if (cornerW > CORNER_RECTPAD)
		cornerW = CORNER_RECTPAD;
	return QGraphicsRectItem::boundingRect().adjusted(-cornerW, -cornerW, cornerW, cornerW);
}

QPainterPath CRectItem::shape() const
{
    if(brush().style() == Qt::NoBrush){
        QPainterPath path;
        path.addRect(rect());
        QPainterPathStroker strok;
        strok.setWidth(pen().widthF()*PATHSTROKER);
        return strok.createStroke(path);
    }
    else
        return QGraphicsRectItem::shape();
}

void CRectItem::PaintGL( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
#ifdef GLUT
#endif
}

void CRectItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
/*  if (widget && widget->inherits("QGLWidget"))
    {
        PaintGL( painter,  option,  widget);
    }*/
	qreal cornerW = rect().width() > rect().height() ? rect().height() / 20 : rect().width() / 20;
    Q_UNUSED(widget);
    painter->setPen(pen());
    if (m_pData->FillPercent()==1)
    {
        QBrush fillbrush = brush();
        UnqFunc()->ProcessBrush(boundingRect(),fillbrush);
        painter->setBrush(fillbrush);
        painter->drawRoundedRect(rect(),m_pData->Rx(),m_pData->Ry());
    }
    else
    {
        painter->setBrush(Qt::NoBrush);
        painter->drawRoundedRect(rect(),m_pData->Rx(),m_pData->Ry());
        painter->setBrush(brush());

        QPainterPath path1,path2;
        path1.addRoundedRect( rect(),m_pData->Rx(),m_pData->Ry());
        QRectF drect=rect() ;
        if (m_pData->GetFillDir()==1)
            drect.setTop(drect.bottom() - drect.height()*m_pData->FillPercent());
        else
            drect.setRight(drect.left() + drect.width()*m_pData->FillPercent());
        path2.addRoundedRect(drect,m_pData->Rx(),m_pData->Ry());
        QPainterPath dpath=path1.intersected(path2);
        painter->drawPath(dpath);
    }
    //////画阴影效果////////
    if(m_pData->m_ShadowType != CRectData::NoShadow  && m_pData->Rx()==0 && m_pData->Ry()==0)
    {
        QRectF rc=rect();
        painter->setPen(Qt::NoPen);
        QBrush mybrush = brush();
        QPalette brushPal(brush().color());
        QPalette penPal(pen().color());
        QColor lightColor=brushPal.light().color();
        QColor shadowColor=brushPal.dark().color();
        if ( brush().style() == Qt::NoBrush){
            lightColor=penPal.light().color();
            shadowColor=penPal.shadow().color();//dark()
        }

        int line_width = pen().widthF();
        QPolygonF pointarray1, pointarray2;
        pointarray1<<QPointF(rc.x() - line_width / 2.0, rc.y() + rc.height()  + line_width / 2.0);
        pointarray1<<QPointF(rc.x() + line_width / 2.0, rc.y() + rc.height() - line_width / 2.0);
        pointarray1<<QPointF(rc.x() + line_width / 2.0, rc.y() + line_width / 2.0);
        pointarray1<<QPointF(rc.x() + rc.width() - line_width / 2.0, rc.y() + line_width / 2.0);
        pointarray1<<QPointF(rc.x() + rc.width() + line_width / 2.0, rc.y() - line_width / 2.0);
        pointarray1<<QPointF(rc.x() - line_width / 2.0, rc.y() - line_width / 2.0);

        pointarray2<<QPointF(rc.x() - line_width / 2.0, rc.y() + rc.height() + line_width / 2.0);
        pointarray2<<QPointF(rc.x() + line_width / 2.0, rc.y() + rc.height() - line_width / 2.0);
        pointarray2<<QPointF(rc.x() + rc.width() - line_width / 2.0,rc.y() + rc.height() - line_width / 2.0);
        pointarray2<<QPointF(rc.x() + rc.width() - line_width / 2.0, rc.y() + line_width / 2.0);
        pointarray2<<QPointF(rc.x() + rc.width() + line_width / 2.0, rc.y() - line_width / 2.0);
        pointarray2<<QPointF(rc.x() + rc.width() + line_width / 2.0, rc.y() + rc.height() + line_width / 2.0);

        mybrush.setStyle(Qt::SolidPattern);
        if (m_pData->m_ShadowType == CRectData::ShadowUp)
        {
            mybrush.setColor(lightColor);
            painter->setBrush(mybrush);
            painter->drawPolygon(pointarray1);

            mybrush.setColor(shadowColor);
            painter->setBrush(mybrush);
            painter->drawPolygon(pointarray2);

        }
        else if (m_pData->m_ShadowType == CRectData::ShadowDown)
        {
            mybrush.setColor(shadowColor);
            painter->setBrush(mybrush);
            painter->drawPolygon(pointarray1);

            mybrush.setColor(lightColor);
            painter->setBrush(mybrush);
            painter->drawPolygon(pointarray2);

        }
    }
    //
    if  (option->state & QStyle::State_Selected)
    {
        QVector<QPointF> vec;
		vec.reserve(8);
		qreal w = rect().width();
		qreal h = rect().height();
		vec << rect().topLeft() << rect().topRight() << rect().bottomLeft() << rect().bottomRight() << rect().topLeft() + QPointF(w / 2, 0) << rect().topLeft() + QPointF(0, h / 2) << rect().topRight() + QPointF(0, h / 2) << rect().bottomLeft() + QPointF(w / 2, 0);;
		g_PaintBoundingRect(scene(), painter, option, boundingRect(), cornerW);
		g_HighlightSelected(scene(), painter, option, vec, cornerW);
    }
}

QVariant CRectItem::itemChange(GraphicsItemChange change, const QVariant &value)
 {
     if (scene()&& change==ItemScenePositionHasChanged  ) {
         QPointF newPos = value.toPointF();
         ((CGraphScene*)scene())->EmitSignal("ItemPosChange",newPos);
     }
     return QGraphicsItem::itemChange(change, value);
 }
///////////
QGraphicsItem* CEllipseData::Clone()
{
    CEllipseItem* plItem = new CEllipseItem();
    g_dataPtr(plItem)->Copy( this);
    return plItem;
}
void CEllipseData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    G_G(CEllipseItem)
    CEllipseItem* psrcItem=(CEllipseItem*)(srcData->Item());
    G->setRect(psrcItem->rect());
    G->setStartAngle(psrcItem->startAngle());
    G->setSpanAngle(psrcItem->spanAngle());
    G->SetShapeType(psrcItem->ShapeType());
    SetFillPercent(((CEllipseData*)srcData)->FillPercent());
    SetFillDir(((CEllipseData*)srcData)->GetFillDir());
}

void  CEllipseData::SetSpanAngle(int angle)
{
    ((CEllipseItem*)Item())->setSpanAngle(angle);
}

void CEllipseData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    G_G(CEllipseItem)
    QRectF rc= G->rect();
    xio->WriteAttribute("cx",rc.center().x());
    xio->WriteAttribute("cy",rc.center().y());
    xio->WriteAttribute("rx",rc.width()/2);
    xio->WriteAttribute("ry",rc.height()/2);
    if(G->startAngle()!=0)          xio->WriteAttribute("start-angle",G->startAngle());
    if(G->spanAngle()!=5760)        xio->WriteAttribute("span-angle",G->spanAngle());
    if(G->m_ShapeType!=CEllipseItem::EllipseST)   xio->WriteAttribute("shape-type",G->m_ShapeType);
    CBaseData::SaveBaseProperty(xio);
}

void CEllipseData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CEllipseItem* pItem=(CEllipseItem*)Item();
    qreal cx=0,cy=0,rx=0,ry=0;
    int startAngle=0,spanAngle=0;
    xio->ReadAttribute("cx", cx);
    xio->ReadAttribute("cy", cy);
    xio->ReadAttribute("rx", rx);
    xio->ReadAttribute("ry", ry);
    if(xio->ReadAttribute("start-angle", startAngle )>=0)   pItem->setStartAngle(startAngle);
    if(xio->ReadAttribute("span-angle", spanAngle )>=0)     pItem->setSpanAngle(spanAngle);
    xio->ReadAttribute("shape-type",pItem->m_ShapeType);
    pItem->setRect(QRectF(cx-rx,cy-ry,rx*2,ry*2));    

    CBaseData::LoadBaseProperty(xio);
}

void CEllipseData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CEllipseItem* pItem=(CEllipseItem*)Item();
    CBaseData::GetPropertyList( property_list);
    QMap<QString, QVariant> ShapeType;
    ShapeType[CBaseData::tr("EllipseST")] =CEllipseItem::EllipseST;
    ShapeType[CBaseData::tr("PieST")] =CEllipseItem::PieST;
    ShapeType[CBaseData::tr("ArcST")] =CEllipseItem::ArcST;
    ShapeType[CBaseData::tr("ChordST")] =CEllipseItem::ChordST;
    ShapeType[ "__CurrentValue" ]=pItem->m_ShapeType;
    property_list.push_back(qMakePair(CBaseData::tr("width"), QVariant(pItem->rect().width())));
    property_list.push_back(qMakePair(CBaseData::tr("height"), QVariant(pItem->rect().height())));
    //property_list.push_back( qMakePair( CBaseData::tr("rect") ,QVariant(pItem->mapRectToScene(pItem->rect())) ) );

	QVariantList angleLst;
	angleLst.append(pItem->startAngle() / 16);//value
	QJsonObject angleLimit;
    angleLimit["minimum"] = -360;
	angleLimit["maximum"] = 360;
	angleLst.append(angleLimit);//inputlimit
    property_list.push_back(qMakePair(CBaseData::tr("startAngle"), QVariant(angleLst)));
	angleLst[0] = pItem->spanAngle() / 16;
    property_list.push_back(qMakePair(CBaseData::tr("spanAngle"), QVariant(angleLst)));
    property_list.push_back( qMakePair(CBaseData::tr("shapeType"), QVariant(ShapeType)));
    /*QVariantList percentLst;
    percentLst.append( FillPercent());//value
	QJsonObject percentLimit;
	percentLimit["minimum"] = 0;
	percentLimit["maximum"] = 1;
	percentLst.append(percentLimit);//inputlimit
    property_list.push_back(qMakePair(CBaseData::tr("fillPercent"), QVariant(percentLst)));*/
}

bool CEllipseData::SetProperty(const QString& propname,const QVariant& value)
{
    CEllipseItem* pItem=(CEllipseItem*)Item();
    if (propname == CBaseData::tr("rect") || propname == "rect")
    {
		QRectF rf = pItem->mapFromScene(value.toRectF()).boundingRect();
        pItem->setRect(value.toRectF());
    }
    else if (propname == CBaseData::tr("width") || propname == "width")
    {
        QRectF rct = pItem->rect();
        rct.setWidth(value.toInt());
        pItem->setRect(rct);
    }
    else if (propname == CBaseData::tr("height") || propname == "height")
    {
        QRectF rct = pItem->rect();
        rct.setHeight(value.toInt());
        pItem->setRect(rct);
    }
    else if (propname == CBaseData::tr("startAngle") || propname == "startAngle")
    {
        pItem->setStartAngle(value.toInt()*16);
    }
    else if (propname == CBaseData::tr("spanAngle") || propname == "spanAngle")
    {
        pItem->setSpanAngle(value.toInt()*16);
    }
    else if (propname == CBaseData::tr("shapeType") || propname == "shapeType")
    {
        pItem->m_ShapeType=value.toInt();
        pItem->update();
    }
    else
        return CBaseData::SetProperty( propname, value);

    return true;

}
///
CEllipseItem::CEllipseItem( QGraphicsItem *parent )
    :QGraphicsEllipseItem(parent)
{
    m_ShapeType=EllipseST;
    m_pData=new CEllipseData(this);
    g_SetData(this,m_pData);
}

CEllipseItem::~CEllipseItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

QRectF CEllipseItem::boundingRect() const
{
	qreal cornerW = rect().width() > rect().height() ? rect().height() / 20 : rect().width() / 20;
	if (cornerW > CORNER_RECTPAD)
		cornerW = CORNER_RECTPAD;
	return QGraphicsEllipseItem::boundingRect().adjusted(-cornerW, -cornerW, cornerW, cornerW);
}

QPainterPath CEllipseItem::shape() const
{
    if(brush().style() == Qt::NoBrush){
        QPainterPath path;
        path.addEllipse( rect());
        QPainterPathStroker strok;
        strok.setWidth(pen().widthF()*PATHSTROKER);
        return strok.createStroke(path);
    }
    else
        return QGraphicsEllipseItem::shape();
}

void CEllipseItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
	qreal cornerW = rect().width() > rect().height() ? rect().height() / 20 : rect().width() / 20;
    painter->setPen(pen());
    QBrush fillbrush = brush();
    UnqFunc()->ProcessBrush(boundingRect(),fillbrush);
    painter->setBrush(fillbrush);
    if (m_ShapeType==EllipseST && ( spanAngle() != 0) && (qAbs( spanAngle()) % (360 * 16) == 0))
    {
        if (m_pData->FillPercent()==1)
        {
            painter->drawEllipse( rect());
        }
        else
        {
            painter->setBrush(Qt::NoBrush);
            painter->drawEllipse( rect());
            painter->setBrush( brush());
            QPainterPath path1,path2;
            path1.addEllipse( rect());
            QRectF drect=rect() ;
            if (m_pData->GetFillDir()==1)
                drect.setTop(drect.bottom()-drect.height()*m_pData->FillPercent());
            else
                drect.setRight(drect.left() + drect.width()*m_pData->FillPercent());
            path2.addRect(drect);
            QPainterPath dpath=path1.intersected(path2);
            painter->drawPath(dpath);
        }
    }
    else if(m_ShapeType==PieST)
    {
        painter->drawPie( rect(), startAngle(), spanAngle());
    }
    else if (m_ShapeType==ArcST)
    {
        painter->drawArc( rect(), startAngle(), spanAngle());
    }
    else if (m_ShapeType==ChordST)
    {
        painter->drawChord( rect(),startAngle(),spanAngle());
    }
    else
    {
        QGraphicsEllipseItem::paint(painter, option, widget);
    }

    if (option->state & QStyle::State_Selected)
    {
        QVector<QPointF> vec;
		vec.reserve(8);
		qreal w = rect().width();
		qreal  h = rect().height();
		vec << rect().topLeft() << rect().topRight() << rect().bottomLeft() << rect().bottomRight() << rect().topLeft() + QPointF(w / 2, 0) << rect().topLeft() + QPointF(0, h / 2) << rect().topRight() + QPointF(0, h / 2) << rect().bottomLeft() + QPointF(w / 2, 0);;
		g_PaintBoundingRect(scene(), painter, option, boundingRect(), cornerW);

		g_HighlightSelected(scene(), painter, option, vec, cornerW);
    }
}
//////////
/// \brief CTextData
///
CTextData::CTextData(QGraphicsItem* item) :CBaseData(item), m_DisplayType(D_DEFAULT)
{
    m_textDirect = 0;
    m_orgText="0.00";
    m_decimalDigits = 2;
	m_timeFormat = -1;
	m_prefix = "";
	m_suffix = "";
    //SetOrgText("0.0");
    //SetFont(QFont("Arial", 9, QFont::Normal));
}

void CTextData::Copy(const CBaseData* srcData)
{
    CTextData* psrcda=((CTextData*)srcData);
    CBaseData::Copy(srcData);
    SetFont(psrcda->Font());
    SetTextDirect(psrcda->GetTextDirect());
    m_DisplayType=psrcda->m_DisplayType;
	m_decimalDigits = psrcda->m_decimalDigits;
	m_timeFormat = psrcda->m_timeFormat;
	m_prefix = psrcda->m_prefix;
	m_suffix = psrcda->m_suffix;
    SetOrgText(psrcda->GetOrgText());
}
QGraphicsItem* CTextData::Clone()
{
    CTextItem* pItem = new CTextItem();
    g_dataPtr(pItem)->Copy(this);
    return pItem;
}
void CTextData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    QFont ft=Font();
    xio->WriteAttribute("",ft , Hmi::SVG);
    int dySize =ft.pointSize() <= 0 ? ft.pixelSize() : (ft.pointSize()*1.5);
    xio->WriteAttribute("y", QString::number(dySize));//WEB text pos is leftbottom point, need +y, use pxizlSize=1.5*pointSize
    if(m_textDirect!=0)                 xio->WriteAttribute("direct", m_textDirect);
    //xio->WriteAttribute("txt", m_orgText);

    if(!GetUserData().isEmpty())
    {
        if(m_DisplayType!=D_DEFAULT)    xio->WriteAttribute("disp-type", m_DisplayType);
        if(m_decimalDigits!=2)          xio->WriteAttribute("decimal-digits", m_decimalDigits);
        if(m_timeFormat!=-1)            xio->WriteAttribute("time-format", m_timeFormat);
        if(!m_prefix.isEmpty())         xio->WriteAttribute("prefix", m_prefix);
        if(!m_suffix.isEmpty())         xio->WriteAttribute("suffix", m_suffix);
    }
    CBaseData::SaveBaseProperty(xio);
    xio->writeCharacters(m_orgText);
}

void CTextData::LoadBaseProperty(CGraphSvgReader* xio)
{
    QString text;
    float x=0,y=0;
    if( xio->ReadAttribute("x", x)>=0 && xio->ReadAttribute("y", y)>=0)
        SetPos(QPoint(x,y));

    CBaseData::LoadBaseProperty(xio);
    QFont font;
    QString textDirect;
    if(xio->ReadAttribute("", font, Hmi::SVG)>=0)   SetFont(font);
    if(xio->ReadAttribute("direct", textDirect)>=0) SetTextDirect(textDirect.toInt());
    if(!GetUserData().isEmpty())
    {
        xio->ReadAttribute("disp-type", m_DisplayType);
		xio->ReadAttribute("decimal-digits", m_decimalDigits);
		xio->ReadAttribute("time-format", m_timeFormat);
		xio->ReadAttribute("prefix", m_prefix);
		xio->ReadAttribute("suffix", m_suffix);
    }
    if(xio->ReadAttribute("txt", text)>=0)          SetOrgText(text);
}

void CTextData::LoadSubProperty(CGraphSvgReader* xio)
{
    QString text=xio->readElementText();
    if(!text.isEmpty())
        SetOrgText(text);
}

void CTextData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CBaseData::GetPropertyList( property_list);
    property_list.push_back( qMakePair( CBaseData::tr("font") ,QVariant(Font()) ) );

    QMap<QString, QVariant> textDirectType;
    textDirectType[CBaseData::tr("Horizontal")] = 0;
    textDirectType[CBaseData::tr("Vertical")] = 1;
    textDirectType["__CurrentValue"] =  GetTextDirect();
    property_list.push_back(qMakePair(CBaseData::tr("textDirect"), QVariant(textDirectType)));
    property_list.push_back(qMakePair(CBaseData::tr("text"), QVariant(GetOrgText())));
    if(!GetUserData().isEmpty())
    {
        QMap<QString, QVariant> dispType;
        dispType[CBaseData::tr("D_DEFAULT")] = D_DEFAULT;
        dispType[CBaseData::tr("D_TRANS")] = D_TRANS;
        dispType[CBaseData::tr("D_INT")] = D_INT;
        dispType[CBaseData::tr("D_FLOAT")] = D_FLOAT;
        dispType[CBaseData::tr("D_PERCENT")] = D_PERCENT;
        dispType[CBaseData::tr("D_DATETIME")] = D_DATETIME;
        dispType["__CurrentValue"] = m_DisplayType;
        property_list.push_back( qMakePair( CBaseData::tr("disp-type") ,QVariant(dispType) ) );
        property_list.push_back(qMakePair(CBaseData::tr("decimal-digits"), m_decimalDigits));
		QMap<QString, QVariant> timeFormat;
        timeFormat["yyyy-MM-dd hh:mm:ss"] = D_DATETIME;
		//timeFormat[tr("MMMM")] = D_WEEK;
        timeFormat["yyyy-MM-dd"] = D_YEAR_MONTH_DAY;
        timeFormat["hh:mm:ss"] = D_HOUR_MIN_SECOND;
		timeFormat["__CurrentValue"] = m_timeFormat;
        property_list.push_back(qMakePair(CBaseData::tr("time-format"), QVariant(timeFormat)));
        property_list.push_back(qMakePair(CBaseData::tr("prefix"), m_prefix));
        property_list.push_back(qMakePair(CBaseData::tr("suffix"), m_suffix));
    }
}

bool CTextData::SetProperty(const QString& propname,const QVariant& value)
{
    if (propname==CBaseData::tr("text")|| propname== "text" )
    {
        SetOrgText(value.toString());
        Item()->update();
    }
    else if (propname == CBaseData::tr("font") || propname == "font")
    {
        SetFont(value.value<QFont>());
    }
    else if (propname == CBaseData::tr("textDirect") || propname == "textDirect")
    {
        SetTextDirect( value.toInt() );
		((CTextItem*)Item())->setText(formatString());
    }
    else if (propname == CBaseData::tr("disp-type") || propname == "disp-type")
    {
        m_DisplayType=value.toInt();
    }
    else if (propname == CBaseData::tr("decimal-digits") || propname == "decimal-digits")
	{
		m_decimalDigits = value.toInt();
	}
    else if (propname == CBaseData::tr("time-format") || propname == "time-format")
	{
		m_timeFormat = value.toInt();
	}
    else if (propname == CBaseData::tr("prefix") || propname == "prefix")
	{
		m_prefix = value.toString();
	}
    else if (propname == CBaseData::tr("suffix") || propname == "suffix")
	{
		m_suffix = value.toString();
	}
    else
        return CBaseData::SetProperty( propname, value);

    return true;
}
void CTextData::SetFont(const QFont& f)
{
	((CTextItem*)Item())->setFont(f);
}
QFont CTextData::Font() const
{
    return ((CTextItem*)Item())->font() ;
}
void CTextData::SetTextColor( const QColor& c )
{
    ((CTextItem*)Item())->setPen(QPen(c));
}

QString CTextData::Text()
{
    return GetOrgText( );
}
void CTextData::SetText(const QString& text)
{
    SetOrgText(text);
}
void CTextData::SetLineWidth(qreal width)
{
	QPen pen =((CTextItem*)Item())->pen();
	if (width > 0)
	{
		pen.setStyle(Qt::SolidLine);
		pen.setWidthF(width);
	}
	else
	{
		pen.setStyle(Qt::NoPen);
	}
	((CTextItem*)Item())->setPen(pen);
}
qreal CTextData::GetLineWidth() const
{
	QPen pen = ((CTextItem*)Item())->pen();
	if (pen.style() == Qt::NoPen)
		return 0;
	return pen.widthF();
}

void CTextData::SetLineColor(const QColor& color)
{
    CTextItem* pitem=(CTextItem*)Item();
    QBrush brush=pitem->brush();
    brush.setColor(color);
    pitem->setBrush( brush);
}

void CTextData::SetOrgText(QString curValue)//,int disType);
{
    QString prefix =  GetPrefix();
    QString suffix =  GetSuffix();
    int disType =  GetDispType();
    QString nStr=curValue;
    switch (disType)
    {
    case CTextData::D_INT:
    {
        nStr = prefix + QString::number(curValue.toDouble(), 'f', 0) + suffix;
    }
        break;
    case CTextData::D_FLOAT:
    {
        int decimalDig = GetDecimalDigits();
        nStr=prefix + QString::number(curValue.toDouble(), 'f', decimalDig) + suffix;
    }
        break;
    case CTextData::D_PERCENT:
    {
        int decimalDig = GetDecimalDigits();
        QString orgTxt = QString::number(curValue.toDouble() * 100, 'f', decimalDig);
        nStr=prefix + orgTxt + "%" + suffix;
    }
        break;
    case CTextData::D_DATETIME:
    {
        int timeFormat = GetTimeFormat();
        QString formatStr = "yyyy-MM-dd hh:mm:ss";
        if (timeFormat == CTextData::D_YEAR_MONTH_DAY)
            formatStr = "yyyy-MM-dd";
        else if (timeFormat == CTextData::D_HOUR_MIN_SECOND)
            formatStr = "hh:mm:ss";

        QDateTime dt;
        dt.setTime_t(curValue.toUInt());
        nStr=prefix + dt.toString(formatStr) + suffix;
    }
        break;
    case CTextData::D_DEFAULT:
    case CTextData::D_TRANS:
    default:
        {
        nStr=prefix + curValue  + suffix;
        }
        break;
    }
    m_orgText = nStr;

    int type = Item()->type();
    if (type ==  Hmi::Text)
        ((CTextItem*)Item())->setText(formatString());
    else if (type ==  Hmi::GraphicsText)
        ((CGraphicsTextItem*)Item())->setPlainText(formatString());
}

QString CTextData::formatString()
{
    QString m_formatString;
    QString strContent = m_orgText;
    if (m_textDirect != 1 )
    {
        m_formatString = strContent;
    }
    else
    {
        QChar cr('\n');
        QChar sp(32);
        strContent = strContent.simplified();
        int cnt = strContent.count();
        QChar prev;
        m_formatString.clear();
        for (int i = 0; i < cnt; i++)
        {
            QChar cur(strContent.at(i));
            if (cur == sp)
            {
                m_formatString.append(cr);
            }
            else if (cur.isDigit())
            {
                if (!prev.isNull() && !prev.isDigit() && prev != sp)
                    m_formatString.append(cr);
                m_formatString.append(cur);
            }
            else if (cur >= QChar(0x4e00) && cur <= QChar(0x9ea5))
            {
                if (!prev.isNull() && prev != sp)
                    m_formatString.append(cr);
                m_formatString.append(cur);
            }
            else if (cur.isLower())
            {
                if (!prev.isNull() && !prev.isLower() && !prev.isUpper() && prev != sp)
                    m_formatString.append(cr);
                m_formatString.append(cur);
            }
            else if (cur.isUpper())
            {
                if (!prev.isNull() && !prev.isUpper() && !prev.isLower() && prev != sp)
                    m_formatString.append(cr);
                m_formatString.append(cur);
            }
            else if (cur == QChar(46))
            {
                m_formatString.append(cur);
                continue;
            }
            else
                m_formatString.append(cur);
            prev = cur;
        }
    }
    return m_formatString;
}


////
CTextItem::CTextItem( QGraphicsItem *parent )
    :QGraphicsSimpleTextItem(parent )
{
    m_pData=new CTextData(this);
	g_SetData(this, m_pData);
    setText("0.00");
    setFont(QFont("Arial", 9, QFont::Normal));
	m_pData->SetLineWidth(0);
}

CTextItem::~CTextItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

void CTextItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    if (g_ifExplorer( scene())){
        QStyleOptionGraphicsItem op;
        QGraphicsSimpleTextItem::paint(painter, &op, widget);
    }
    else
        QGraphicsSimpleTextItem::paint(painter, option, widget);
	/*if (option->state & QStyle::State_Selected)
	{
		QRectF bound = boundingRect();
		bound.adjust(-4, -4, 4, 4);
		g_PaintBoundingRect(scene(), painter, option, bound);
	}*/
}
///////////
QGraphicsItem* CGraphicsTextData::Clone()
{
	CGraphicsTextItem* pItem = new CGraphicsTextItem();
	g_dataPtr(pItem)->Copy(this);
	return pItem;
}

void CGraphicsTextData::SetFont(const QFont& f)
{
	((CGraphicsTextItem*)Item())->setFont(f);
}
QFont CGraphicsTextData::Font( ) const
{
    return ((CGraphicsTextItem*)Item())->font();
}
void CGraphicsTextData::SetTextColor(const QColor& c)
{
	((CGraphicsTextItem*)Item())->setDefaultTextColor(c);
}

void CGraphicsTextData::SetLineWidth(qreal width)
{
	((CGraphicsTextItem*)Item())->setTextWidth(width);
}
qreal CGraphicsTextData::GetLineWidth() const
{
	return ((CGraphicsTextItem*)Item())->textWidth();
}
Qt::PenStyle CGraphicsTextData::GetLineStyle() const
{
	return  Qt::NoPen;
}
void CGraphicsTextData::SetLineStyle(Qt::PenStyle style)
{
}
void CGraphicsTextData::SetLineColor(const QColor& color)
{
	((CGraphicsTextItem*)Item())->setDefaultTextColor(color);
}

QColor CGraphicsTextData::GetLineColor() const
{
	return ((CGraphicsTextItem*)Item())->defaultTextColor();
}
QBrush CGraphicsTextData::Brush() const
{
	QBrush brush(Qt::SolidPattern);
	return brush;
}
void CGraphicsTextData::SetFillColor(const QColor& color)
{
	SetLineColor(color);
}

QColor CGraphicsTextData::GetFillColor() const
{
	return GetLineColor();
}

///
CGraphicsTextItem::CGraphicsTextItem(QGraphicsItem *parent)
:QGraphicsTextItem(parent)
{
	m_pData = new CGraphicsTextData(this);
	g_SetData(this, m_pData);
    setPlainText("0.0");
    setFont(QFont("Arial", 9, QFont::Normal));
	setDefaultTextColor(Qt::black);
}

CGraphicsTextItem::~CGraphicsTextItem()
{
	if (m_pData)
	{
		delete m_pData;
		m_pData = NULL;
	}
}

void CGraphicsTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsTextItem::paint(painter, option, widget);
	/*if (option->state & QStyle::State_Selected)
	{
		QRectF bound = boundingRect();
		bound.adjust(-4, -4, 4, 4);
		g_PaintBoundingRect(scene(), painter, option, bound);
	}*/
}

void CGraphicsTextItem::focusOutEvent(QFocusEvent *event)
{
    if (g_ifExplorer( scene()))
	{
		QGraphicsTextItem::focusOutEvent(event);
		return;
	}
	setTextInteractionFlags(Qt::NoTextInteraction);
	QTextCursor cursor = this->textCursor();
	cursor.clearSelection();
	setTextCursor(cursor);

	if (this->toPlainText().isEmpty()) {
        m_pData->Remove();
		this->deleteLater();
	}
	else
        ((CGraphicsTextData*)m_pData)->SetOrgText(toPlainText());

	QGraphicsTextItem::focusOutEvent(event);
}

void CGraphicsTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if (g_ifExplorer( scene()))
	{
		QGraphicsTextItem::mouseDoubleClickEvent(event);
		return;
	}
	if (textInteractionFlags() == Qt::NoTextInteraction)
		setTextInteractionFlags(Qt::TextEditorInteraction);
	this->setFocus();
	QGraphicsTextItem::mouseDoubleClickEvent(event);
}

void CAbstractScaleData::SaveBaseProperty( CGraphSvgWriter* xio ) const
{
    xio->WriteAttribute("scaleX", GetOrgScaleX());
    xio->WriteAttribute("scaleY", GetOrgScaleY());
    CBaseData::SaveBaseProperty(xio);
}

void CAbstractScaleData::LoadBaseProperty( CGraphSvgReader* xio )
{
    qreal scaleX, scaleY;
    xio->ReadAttribute("scaleX", scaleX);
    xio->ReadAttribute("scaleY", scaleY);
    SetOrgScaleX(scaleX);
    SetOrgScaleY(scaleY);
    CBaseData::LoadBaseProperty(xio);
}

void CAbstractScaleData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
    CBaseData::GetPropertyList( property_list);
	
	QVariantList scaleLst;
	scaleLst.append(GetOrgScaleX());//value
	QJsonObject limit;
	limit["minimum"] = 0;
	scaleLst.append(limit);//inputlimit
    property_list.push_back(qMakePair(CBaseData::tr("scaleX"), QVariant(scaleLst)));
	scaleLst[0] = GetOrgScaleY();
    property_list.push_back(qMakePair(CBaseData::tr("scaleY"), QVariant(scaleLst)));
	property_list.push_back(qMakePair(CBaseData::tr("width"), QVariant(GetOrgScaleX()*Item()->boundingRect().width())));
	property_list.push_back(qMakePair(CBaseData::tr("height"), QVariant(GetOrgScaleY()*Item()->boundingRect().height())));

}

bool CAbstractScaleData::SetProperty( const QString& propname,const QVariant& value )
{
    QPointF lockPoint;
    const QRectF rectF = Item()->boundingRect();
    if (propname == CBaseData::tr("scaleX") || propname == "scaleX")
    {
        SetOrgScaleX(value.toFloat());
        lockPoint = rectF.topLeft();
    }
    else if (propname == CBaseData::tr("scaleY") || propname == "scaleY")
    {
        SetOrgScaleY(value.toFloat());
        lockPoint = rectF.topLeft();
    }
	else if (propname == "width" || propname == CBaseData::tr("width"))
	{
		qreal width = value.toFloat();
		qreal dScale = width / (Item()->boundingRect().width());
		SetProperty("scaleX", dScale);
		return true;
	}
	else if (propname == "height" || propname == CBaseData::tr("height"))
	{
		qreal height = value.toFloat();
		qreal dScale = height / (Item()->boundingRect().height());
		SetProperty("scaleY", dScale);
		return true;
	}
    else
        return CBaseData::SetProperty( propname, value);

    CBaseData::ApplyScaleProperty(Item(), GetOrgRotation(), GetOrgScaleX(), GetOrgScaleY(), lockPoint);
    return true;
}




CPixmapData::CPixmapData( QGraphicsItem* item)
    :CAbstractScaleData(item)
{
    m_IsMovie=false;
    m_pMovie=NULL;
    m_ConvertBGTransparency=false;
}

CPixmapData::~CPixmapData()
{
    if (m_pMovie)
    {
        m_pMovie->stop();
        delete m_pMovie;
    }
}

void CPixmapData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    CPixmapData* psrcData=(CPixmapData*)srcData;
    m_IsMovie=psrcData->m_IsMovie;
    m_fileNameList=psrcData->m_fileNameList;
    m_ConvertBGTransparency=psrcData->m_ConvertBGTransparency;
    QString filePathName;
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, m_fileNameList.empty()?QString():m_fileNameList[0], filePathName);
    Load(filePathName);

}

QGraphicsItem* CPixmapData::Clone()
{
    CPixmapItem* pItem = new CPixmapItem();
    g_dataPtr(pItem)->Copy(this);
    return pItem;
}
void CPixmapData::SaveBaseProperty(CGraphSvgWriter* xio) const
{

    xio->WriteAttribute("xlink:href", m_fileNameList.join(QString(';')));

    QString fileStr;
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, m_fileNameList.empty() ? QString() : m_fileNameList[0], fileStr);
    QPixmap pix(fileStr);

    if (!pix.isNull())
    {
        xio->WriteAttribute("width", pix.width());
        xio->WriteAttribute("height", pix.height());
    }
    xio->WriteAttribute("bgtrsp", m_ConvertBGTransparency);


    CAbstractScaleData::SaveBaseProperty(xio);
}

void CPixmapData::LoadBaseProperty(CGraphSvgReader* xio)
{
    QString fileStr;
    xio->ReadAttribute("xlink:href", fileStr);
    m_fileNameList = fileStr.split(';');
    CAbstractScaleData::LoadBaseProperty(xio);
    xio->ReadAttribute("bgtrsp", m_ConvertBGTransparency);

    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, m_fileNameList.empty()?QString():m_fileNameList[0], fileStr);
    Load(fileStr);
}

void CPixmapData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CAbstractScaleData::GetPropertyList( property_list);
    property_list<<qMakePair( CBaseData::tr("xlink:href"), QVariant(m_fileNameList.join(QString(';'))) );
    property_list<<qMakePair( CBaseData::tr("bgtrsp"), QVariant(m_ConvertBGTransparency) );
}

bool CPixmapData::SetProperty(const QString& propname,const QVariant& value)
{
    CPixmapItem* pItem=(CPixmapItem*)Item();
    if (propname==CBaseData::tr("xlink:href") || propname== "xlink:href" )
    {
        QStringList fileLst =value.toStringList();
		for (int i = 0; i < fileLst.size(); i++)
		{
			if (!fileLst[i].contains("."))
			{
                QMessageBox::warning(0, CBaseData::tr("Tips"), CBaseData::tr("please input the suffix of image!"));
				return false;
			}
		}
		m_fileNameList = fileLst;
        QString filePathName;
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, m_fileNameList.empty()?QString():m_fileNameList[0], filePathName);
        return Load(filePathName);
    }
    else if(propname==CBaseData::tr("bgtrsp") || propname== "bgtrsp"){
        m_ConvertBGTransparency=value.toBool();
        QString filePathName;
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, m_fileNameList.empty()?QString():m_fileNameList[0], filePathName);
        return Load(filePathName);
    }
    else
        return CAbstractScaleData::SetProperty( propname, value);

    return true;
}

bool CPixmapData::LoadFromData( const QVariant& data, QString format  , QString flags )
{
    CPixmapItem* pItem=(CPixmapItem*)Item();
    QPixmap pix ;
    QByteArray gg = data.toByteArray();
    int ret=pix.loadFromData(gg );
    pItem->setPixmap(pix);
    /*if(ret)
        pItem->setPixmap(pix);
    else
        pItem->setPixmap( GetNoPixmap());*/

    return ret;
}

bool CPixmapData::Load( const QString& filename )
{
	QString fName;
    int length=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP).length();
	fName = filename.right(filename.length() - length);//

    //UnqFunc()->GetGraphNameByGraphPathName(filename, fName);
	m_fileNameList = QStringList(fName);

    CPixmapItem* pItem=(CPixmapItem*)Item();
    QString tmp=filename.right(4);

    if (tmp==".mng" || tmp==".gif" )
    {
        if(m_pMovie==NULL)
        {
            m_pMovie=new QMovie();
            connect(m_pMovie,SIGNAL(updated ( const QRect& )),this,SLOT(movieUpdated(const QRect&)));
            m_pMovie->setCacheMode(QMovie::CacheAll);
            m_pMovie->setBackgroundColor(QColor(0,0,0));
        }
        m_pMovie->setFileName(filename);
        m_pMovie->stop();
        m_pMovie->start();
        pItem->setPixmap( m_pMovie->currentPixmap());
        m_IsMovie = true;
        return true;
    }
    else
    {
		if (m_pMovie)
        {
            m_pMovie->stop();
            m_IsMovie = false;
        }

        QPixmap pix;
        if(m_ConvertBGTransparency) ////白色转透明背景/////
            pix=QPixmap::fromImage(UnqFunc()->ConvertColor(filename));
        else
            pix.load(filename);

        if(pix.isNull())
            pItem->setPixmap( GetNoPixmap());
        else
            pItem->setPixmap(pix);

        return !pix.isNull();
    }
}

void CPixmapData::movieUpdated(const QRect& area)
{
    CPixmapItem* pItem=(CPixmapItem*)Item();

    if ( !m_IsMovie || m_pMovie->state()==QMovie::NotRunning)
    {
        return;
    }
    pItem->setPixmap( m_pMovie->currentPixmap());
}

QPixmap CPixmapData::GetNoPixmap()
{
    static QPixmap _pix;
    if(_pix.isNull())
    {
        _pix = QPixmap(100, 100);
        _pix.fill(Qt::white);
    }
    return _pix;
}

CPixmapItem::CPixmapItem( QGraphicsItem *parent )
    :QGraphicsPixmapItem(parent)
{
    m_pData=new CPixmapData(this);
    g_SetData(this,m_pData);
    QPixmap pix(100, 100);
    pix.fill(Qt::white);
    setPixmap(pix);
}

CPixmapItem::~CPixmapItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

void CPixmapItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    Q_UNUSED(widget);

    QPixmap pix = pixmap();
    painter->drawPixmap(QRect(offset().toPoint(), pix.size()), pix);

    if(option->state & QStyle::State_Selected)
    {
        QVector<QPointF> vec;
		vec.reserve(8);        
		QRectF rect = boundingRect(); 
		qreal w = rect.width(); 
		qreal h = rect.height();
		vec << rect.topLeft() << rect.topRight() << rect.bottomLeft() << rect.bottomRight() << rect.topLeft() + QPointF(w / 2, 0) << rect.topLeft() + QPointF(0, h / 2) << rect.topRight() + QPointF(0, h / 2) << rect.bottomLeft() + QPointF(w / 2, 0);;
		g_HighlightSelected(scene(),painter, option, vec, CORNER_RECTPAD ,true);
        g_PaintBoundingRect(scene(),painter, option, rect);

    }
}

QRectF CPixmapItem::boundingRect() const
{
	return QGraphicsPixmapItem::boundingRect().adjusted(-ACTIVE_RECTPAD, -ACTIVE_RECTPAD, ACTIVE_RECTPAD, ACTIVE_RECTPAD);
}

void CPixmapItem::ApplyRect( const QSize& size )
{
    prepareGeometryChange();
    m_size = size;

}

void CSvgData::Copy(const CBaseData* srcData)
{
	CBaseData::Copy(srcData);
	CSvgData* psrcData = (CSvgData*)srcData;
}

QGraphicsItem* CSvgData::Clone()
{
	CSvgItem* pItem = new CSvgItem();
	g_dataPtr(pItem)->Copy(this);
	return pItem;
}
void CSvgData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CSvgItem* pItem=(CSvgItem*)Item();
    xio->WriteAttribute("url", pItem->GetFileName());
    CAbstractScaleData::SaveBaseProperty(xio);
}

void CSvgData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CSvgItem* pItem=(CSvgItem*)Item();
    QString fileName;
    xio->ReadAttribute("url", fileName);
    pItem->Load(fileName);
    CAbstractScaleData::LoadBaseProperty(xio);
}

void CSvgData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CSvgItem* pItem=(CSvgItem*)Item();
    CAbstractScaleData::GetPropertyList( property_list);
    property_list.push_back( qMakePair( CBaseData::tr("svg") ,QVariant(pItem->GetFileName()) ) );
}

bool CSvgData::SetProperty(const QString& propname,const QVariant& value)
{
    CSvgItem* pItem=(CSvgItem*)Item();
    if (propname == CBaseData::tr("svg") || propname == "svg")
    {
		pItem->Load(value.toString());
    }
    else
        return CAbstractScaleData::SetProperty( propname, value);

    return true;
}


CSvgItem::CSvgItem( QGraphicsItem *parent )
    :QGraphicsSvgItem(parent )
{
    m_IsValide=true;
    m_pRenderer = new QSvgRenderer();
    setSharedRenderer(m_pRenderer);

    QByteArray txt="<?xml version=\"1.0\" ?> <svg width=\"200\" height=\"200\" viewBox=\"0 0 200 200\" > <text x=\"50\" y=\"50\" style=\"font-family:Verdana;font-size:24\">powerhmi</text> </svg>";
    m_IsValide=renderer()->load(txt);
    setSharedRenderer(m_pRenderer);

    m_FileName="";

    m_pData=new CSvgData(this);
    g_SetData(this,m_pData);
    setFlags(this->flags() | QGraphicsItem::ItemClipsToShape);
    setCacheMode(QGraphicsItem::NoCache);
}

CSvgItem::~CSvgItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
    delete m_pRenderer;
}

int CSvgItem::Load(const QString& fileName)
{
	if (fileName.isEmpty())
	{
		QByteArray txt = "<?xml version=\"1.0\" ?> <svg width=\"200\" height=\"200\" viewBox=\"0 0 200 200\" > <text x=\"50\" y=\"50\" style=\"font-family:Verdana;font-size:24\">powerhmi</text> </svg>";
		m_IsValide = renderer()->load(txt);
		setSharedRenderer(m_pRenderer);
	}
	else
	{
		m_FileName = QDir::toNativeSeparators(fileName);
		if (QDir::isAbsolutePath(fileName))
		{
			m_IsValide = renderer()->load(fileName);
            m_FileName = m_FileName.replace(UnqFunc()->GetDir(CGFunc::PATH_TYPE_DATA), "");
		}
		else
		{
            m_IsValide = renderer()->load(UnqFunc()->GetDir(CGFunc::PATH_TYPE_DATA) + m_FileName);
		}
		setSharedRenderer(m_pRenderer);
		
	}
    return m_IsValide;
}

QRectF CSvgItem::boundingRect() const
{
	return QGraphicsSvgItem::boundingRect() .adjusted(-ACTIVE_RECTPAD, -ACTIVE_RECTPAD, ACTIVE_RECTPAD, ACTIVE_RECTPAD);
}

QRectF CSvgItem::Rect()
{
    return QGraphicsSvgItem::boundingRect();
}

void CSvgItem::SetRect(const QRectF& rect)
{
    QRectF orgRc=Rect();
    if (orgRc.width()<1)
    {
        return;
    }
    double scale=rect.width()/orgRc.width();
    setScale(scale);
    QPointF dpoint=rect.center()-orgRc.center();


}

void CSvgItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    Q_UNUSED(widget);
	if (m_IsValide)
	    QGraphicsSvgItem::paint(painter, option, widget);
      
	if (option->state & QStyle::State_Selected)
	{
		QVector<QPointF> vec;
		vec.reserve(8);        
		QRectF rect = boundingRect();
		qreal w = rect.width();
		qreal h = rect.height();
		vec << rect.topLeft() << rect.topRight() << rect.bottomLeft() << rect.bottomRight() << rect.topLeft() + QPointF(w / 2, 0) << rect.topLeft() + QPointF(0, h / 2) << rect.topRight() + QPointF(0, h / 2) << rect.bottomLeft() + QPointF(w / 2, 0);;
		g_HighlightSelected(scene(), painter, option, vec, CORNER_RECTPAD, true);
		g_PaintBoundingRect(scene(), painter, option, rect);

	}
}


QGraphicsItem* CPinData::Clone()
{
    CPinItem* item = new CPinItem();
    g_dataPtr(item)->Copy(this);
    return item;
}
void CPinData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    SetName(srcData->GetName());

    G_G(CPinItem)
            CPinItem* psrcItem=(CPinItem*)(srcData->Item());
    G->m_linkItemNames = psrcItem->m_linkItemNames;
    G->m_linkItemSet = psrcItem->m_linkItemSet;
}

void CPinData::SetLineColor(const QColor& color)
{
    return;
}
QColor CPinData::GetLineColor() const
{
    G_G(CPinItem)
            return G->s_shapeData.strokeColor ;
}
void CPinData::SetFillColor(const QColor& color)
{
    return;
}
QColor CPinData::GetFillColor() const
{
    G_G(CPinItem)
            return G->s_shapeData.fillColor ;
}
Qt::BrushStyle CPinData::GetFillStyle() const
{
    G_G(CPinItem)
            return G->s_shapeData.brushStyle;
}
void CPinData::SetFillStyle(Qt::BrushStyle style)
{


    return;
}
Qt::PenStyle CPinData::GetLineStyle() const
{
    G_G(CPinItem)
            return G->s_shapeData.penStyle;
}
void CPinData::SetLineStyle(Qt::PenStyle style)
{


    return;
}
qreal CPinData::GetLineWidth() const
{
    G_G(CPinItem)
            return G->s_shapeData.strokeWidth;
}
void CPinData::SetLineWidth(qreal width)
{
    Q_UNUSED( width);


    return;
}
void CPinData::SaveBaseProperty( CGraphSvgWriter* xio ) const
{
    G_G(CPinItem);
    QStringList linkItemNames = G->m_linkItemNames;
    QString names;
    for (int i = 0;i<linkItemNames.size();i++)
    {
        if (i != 0)
            names += ",";
        names += linkItemNames[i];
    }
    xio->WriteAttribute("linkedOfItems",names);

    xio->WriteAttribute("display",QString("none"));
    xio->WriteAttribute("x",CPinItem::cs_rectF.x());
    xio->WriteAttribute("y",CPinItem::cs_rectF.y());
    xio->WriteAttribute("width",CPinItem::cs_rectF.width());
    xio->WriteAttribute("height",CPinItem::cs_rectF.height());

    CBaseData::SaveBaseProperty(xio);
}

void CPinData::LoadBaseProperty( CGraphSvgReader* xio )
{
    G_G(CPinItem);
    QString names;
    xio->ReadAttribute("linkedOfItems",names);
    G->m_linkItemNames = names.split(",");
    CBaseData::LoadBaseProperty(xio);
}

void CPinData::GetPropertyList( QList< QPair<QString,QVariant> >& property_list )
{
    CBaseData::GetPropertyList(property_list);
    return;
}

bool CPinData::SetProperty( const QString& propname,const QVariant& value )
{
	CBaseData::SetProperty(propname,value);
    return true;

}
QObjectList CPinData::GetLinkItems(){
	G_G(CPinItem);
	QObjectList ret;
	foreach(CLinkLineItem* item, G->m_linkItemSet){
		if (item && g_dataPtr(item))
			ret.append(g_dataPtr(item));
	}
	return ret;
}

class CPinIdGenerator
{
public:
    friend CPinIdGenerator& UnqPinIdGenerator();
    ~CPinIdGenerator(){};

    void CreatePin(CPinItem* item)
    {
        m_pinVec<<item;
        item->SetPinId(m_pinVec.size()-1);
    };
    void DeletePin(const CPinItem* item)
    {
        int index = item->GetPinId();
        Q_ASSERT(index!=-1);
        m_pinVec[index] = m_pinVec.back();
        m_pinVec[index]->SetPinId(index);
        m_pinVec.pop_back();
    };

private:
    CPinIdGenerator(){};
    QVector<CPinItem*> m_pinVec;
};

CPinIdGenerator& UnqPinIdGenerator()
{
    static CPinIdGenerator _idGen;
    return _idGen;
}

const QRectF CPinItem::cs_rectF = QRectF(-CORNER_RECTPAD, -CORNER_RECTPAD, 2*CORNER_RECTPAD, 2*CORNER_RECTPAD);
CPinItem::CPinItem(QGraphicsItem* parent) : QGraphicsItem(parent), m_id(-1)
{
    m_data = new CPinData(this);
    g_SetData(this, m_data);
    UnqPinIdGenerator().CreatePin(this);
    setAcceptHoverEvents(true);
    //setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
    //setFlag(QGraphicsItem::ItemIsSelectable, true);
    //setFlag(QGraphicsItem::ItemIsMovable, true);
}

CPinItem::~CPinItem()
{
    UnqPinIdGenerator().DeletePin(this);
}

QRectF CPinItem::boundingRect() const
{
    return cs_rectF.adjusted(-ACTIVE_RECTPAD, -ACTIVE_RECTPAD, ACTIVE_RECTPAD, ACTIVE_RECTPAD);
}

void CPinItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if(g_ifExplorer( scene()))
        return;

    QPen p(s_shapeData.strokeColor);
    p.setWidth(s_shapeData.strokeWidth);
    painter->setPen(p);
    painter->drawEllipse(cs_rectF);
    //painter->drawRect(cs_rectF);

    if (option->state & QStyle::State_Selected)
    {
        g_PaintBoundingRect(scene(),painter, option, boundingRect());
    }
}

bool CPinItem::IsInitConnected()
{
    return m_linkItemSet.size() == m_linkItemNames.size();
}

////////获取pin的有效父icon图元,如果没有父设备图元，则返回pin自己////////////
QGraphicsItem* CPinItem::GetParentIcon()
{
    QGraphicsItem* pitem= parentItem(); ////////pin的有效父item应该是图元不能是组合和间隔(299)/////
    QGraphicsItem* tmpItem= (pitem && pitem->type()==Hmi::Icon && !((CIconData*)g_dataPtr(pitem))->IsIconContainer() )? pitem : this;
    return tmpItem;
}

#if 0
void CPinItem::hoverEnterEvent( QGraphicsSceneHoverEvent* e )
{
    m_parentItem->SetActivePin(m_id);
}

void CPinItem::hoverLeaveEvent( QGraphicsSceneHoverEvent* e )
{
    m_parentItem->SetActivePin(m_id);
}

void CPinItem::hoverMoveEvent( QGraphicsSceneHoverEvent* e )
{
    qDebug("in CPinItem::hoverMoveEvent");
}

#endif
QVariant CPinItem::itemChange( GraphicsItemChange change, const QVariant& value )
{
    bool ifge=g_ifExplorer(scene());
    if (ifge)
		return QGraphicsItem::itemChange(change, value);

	if(ItemScenePositionHasChanged == change)
    {
        bool allselected=true;
        foreach(CLinkLineItem* litem, m_linkItemSet)
        {
            if(!litem->isSelected())
                allselected=false;
        }
        if(allselected)
            return QGraphicsItem::itemChange(change, value);
/*
            QList<QGraphicsItem *> selectItems=((CGraphScene*)scene())->Items(true,true);
            foreach(QGraphicsItem* item, selectItems){///如果含有连接线就不处理了///
                if(item->type()==Hmi::Link)
                    return QGraphicsItem::itemChange(change, value);
            }

            /*if(selectItems.size()>2) ///如果是批量移动就不处理了///
                return QGraphicsItem::itemChange(change, value);*/

        QPointF scenePos = value.toPointF();
        QList<QGraphicsItem*> cItems = collidingItems();
        foreach(CLinkLineItem* item, m_linkItemSet)
        {
            if(item->isSelected()) ///////如果关联的连接线一起被选中移动则不用处理/////////////
                continue;

            QPointF pos = item->mapFromScene(scenePos);
            QPolygonF polygon = item->polygon();
            if(item->IsHeadPinItem(this))
            {
                polygon.first()=pos;
            }
            else
            {
                polygon.last()=pos;
            }
            item->setPolygon(polygon);
            cItems.removeOne(item);
			item->SetInitPos(false);
        }
        if(parentItem()&&m_linkItemSet.size()>0)
            return "";
        if (!cItems.empty())
        {
            foreach(QGraphicsItem* item, cItems)
            {
                if (item->type()!=Hmi::Link)
                    continue;
                CLinkLineItem* linkItem = static_cast<CLinkLineItem*>(item);
                if (contains(mapFromItem(linkItem, linkItem->polygon().last())) && !linkItem->HasEnd())
                {
                    AddLink(linkItem, QPointF());
                    linkItem->SetLink(this, false);
                }
                else if(contains(mapFromItem(linkItem, linkItem->polygon().first())) && !linkItem->HasBegin())
                {
                    AddLink(linkItem, QPointF());
                    linkItem->SetLink(this, true);
                }
            }
        }
    }
    else if(ItemSceneHasChanged == change)//ItemSceneChanged
    {
        QGraphicsScene* newscene = value.value<QGraphicsScene*>();
        if(newscene){
            if(!ifge){ //////如果是编辑态则发送pos变化/////////
                setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
            }
            return value;
        }


        foreach(CLinkLineItem* item, m_linkItemSet)
        {
            item->DelLink(this);
            /*if(scene())
                scene()->removeItem(item);*/
        }

    }
    return value;
}

void CPinItem::FreshPos()
{
    itemChange(ItemScenePositionHasChanged, qVariantFromValue<QPointF>(pos()));
}

/////////根据linkinfo更新连接关系/////////////
void CLinkLineData::UpdateLinks(const QList<QGraphicsItem *>& ListItems)
{
    QMap<QString,CPinItem*> itemsMap;
    QList<CLinkLineItem*> lstLinkItem;
    for  (int i=0;i< ListItems.size();i++)
    {
        QGraphicsItem *item=ListItems[i];
        CBaseData* pdata=g_dataPtr(item);

        if (CPinItem* pPinItem = dynamic_cast<CPinItem*>(item))
        {
            QString name=pdata->GetName();
            QGraphicsItem* parent=pPinItem->GetParentIcon();
			CBaseData* parentdata = g_dataPtr(parent);
			if (parentdata)
				name = parentdata->GetName() + "," + name;

            itemsMap[name]=pPinItem;
        }
        else if (CLinkLineItem* pLinkItem = dynamic_cast<CLinkLineItem*>(item))
        {
            lstLinkItem.append(pLinkItem);
        }
    }
    foreach(CLinkLineItem* pItem,lstLinkItem){
        QStringList linkinfo=((CLinkLineData*)g_dataPtr(pItem))->GetLinkInfo();
        if(linkinfo.size()!=4)
            continue;
        QString p0=linkinfo[0]+","+linkinfo[1];
        QString p1=linkinfo[2]+","+linkinfo[3];
        CPinItem* headItem=itemsMap[p0];
        CPinItem* tailItem=itemsMap[p1];
        if(headItem||tailItem )
            pItem->SetLink(headItem,  tailItem);
    }
}
///
QGraphicsItem* CLinkLineData::Clone()
{
    G_G(CLinkLineItem)
            CLinkLineItem* pItem = new CLinkLineItem();
    if(pItem->m_head) pItem->m_head = (CPinItem*)((g_dataPtr(G->m_head)->Clone())) ;
    if(pItem->m_tail) pItem->m_tail = (CPinItem*)((g_dataPtr(G->m_tail)->Clone())) ;

    pItem->setPolygon(G->polygon());
    g_dataPtr(pItem)->Copy(this);
    return pItem;
}

void CLinkLineData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    G_G(CLinkLineItem)
            CBaseData *pHead,*pTail;
    pHead = g_dataPtr(G->m_head);
    pTail = g_dataPtr(G->m_tail);
    QString pitem0=G->GetPinLinkItem(0)?g_dataPtr(G->GetPinLinkItem(0))->GetName():"";
    QString pitem1=G->GetPinLinkItem(1)?g_dataPtr(G->GetPinLinkItem(1))->GetName():"";
    QString pname0=pHead?pHead->GetName() : "";
    QString pname1=pTail ? pTail->GetName():"";
    QString tmp=QString("%1,%2,%3,%4").arg(pitem0).arg(pname0).arg(pitem1).arg(pname1);
    xio->WriteAttribute("link-info",tmp );
    CPolygonData::SaveBaseProperty(xio);
}


void CLinkLineData::LoadBaseProperty(CGraphSvgReader* xio)
{
    G_G(CLinkLineItem)
            QString linkinfo;
    xio->ReadAttribute("link-info",m_Linkinfo);
   /* QPolygonF polygon;
    xio->ReadAttribute("points",polygon);
    G->setPolygon(polygon);
    QString arrInfo;
    xio->ReadAttribute("arrow", arrInfo);
    QStringList arrls = arrInfo.split(",");*/
	CPolygonData::LoadBaseProperty(xio);
}

void CLinkLineData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    G_G(CLinkLineItem)
    property_list.push_back( qMakePair( CBaseData::tr("item1") ,QVariant(g_getItemName(G->GetPinLinkItem(0)) ) ));
    property_list.push_back( qMakePair( CBaseData::tr("item2") ,QVariant(g_getItemName(G->GetPinLinkItem(1)) ) ));
    CPolygonData::GetPropertyList(property_list);
}

void CLinkLineData::SetRunningFlag(int value)
{
    G_G(CLinkLineItem)
            G->SetRunningFlag(value);
}

QObjectList CLinkLineData::GetNodes(QString pid)
{
    G_G(CLinkLineItem)
    QObjectList ret;
    QGraphicsItem* item=NULL;
    if(pid=="" || pid=="from" || pid=="0"){
        item=G->GetPinLinkItem(0);
        if(item)
            ret.push_back(g_dataPtr(item));
    }

    if(pid=="" || pid=="to" || pid=="1"){
        item=G->GetPinLinkItem(1);
        if(item)
            ret.push_back(g_dataPtr(item));
    }
    return ret;
}

#define myColor Qt::black
#define mySelectedColor  Qt::blue
#define m_bStartFirstHalf false

CLinkLineItem::CLinkLineItem(QGraphicsItem* parent )
    : CPolylineItem(parent, Hmi::Link), m_head(NULL), m_tail(NULL)
{
    m_pData = new CLinkLineData(this);
    g_SetData(this,m_pData);

    setFlag(QGraphicsItem::ItemIsSelectable, true);
    memset(m_hintItemArray, 0, sizeof(QGraphicsItem*)*2);
    m_runningDirection = 0;
    m_pProAnimation = NULL;
    m_pAnimteitem = NULL;
    //
    m_bRemoved=false ;
    m_bInDragMode=false;
    m_nCursorType=0;
    m_bInDragArea=false;
    m_OffsetX=m_OffsetY=0;
    m_bInitPos=true;
    m_nConnType = Conn_NoInit;

    setAcceptHoverEvents(true);

}
CLinkLineItem::~CLinkLineItem()
{
    if (m_pProAnimation)
    {
        m_pProAnimation->stop();
        delete m_pProAnimation;
        m_pProAnimation = NULL;
    }
}
QGraphicsItem* CLinkLineItem::GetPinLinkItem(int terminate)
{
    QGraphicsItem* tmpItem=NULL;
    CPinItem * pinItem = (terminate==0)?HeadPinItem():TailPinItem();
    if(pinItem)
    {
        tmpItem=pinItem->GetParentIcon(); ////////pin的有效父item应该是图元不能是组合和间隔(299)/////
    }
    return tmpItem;
}

void CLinkLineItem::UpdateLoadedConnection()
{
    if(!this->scene())
        return;

    TestHintItem(0);
    TestHintItem(polygon().size()-1);
    SetLink(dynamic_cast<CPinItem*>(m_hintItemArray[0]), dynamic_cast<CPinItem*>(m_hintItemArray[1]));
    return ;
    //qDebug()<<"headname: "<<m_loadedHeadName<<"tailName: "<<m_loadedTailName;
    UpdatePin(m_head,m_loadedHeadName,true);
    UpdatePin(m_tail,m_loadedTailName,false);

}
void CLinkLineItem::UpdatePin(CPinItem*& pPinItem,const QString& name,bool ishead)
{
    QGraphicsScene* pScene = NULL;
    Q_ASSERT(pScene = scene());
    if ( (pPinItem && g_dataPtr(pPinItem)->GetName() != name ) || (pPinItem == NULL && !name.isEmpty()))
    {
        QPointF pt;
        if (ishead)
            pt = this->polygon().first();
        else
            pt = this->polygon().last();
        pt = this->mapToScene(pt);
        QRectF rect = QRectF(pt.x() -CORNER_RECTPAD,pt.y()-CORNER_RECTPAD,2*CORNER_RECTPAD,2*CORNER_RECTPAD);
        QList<QGraphicsItem*> lstpItems = pScene->items(rect,Qt::IntersectsItemBoundingRect,Qt::AscendingOrder);
        foreach(QGraphicsItem* pItem,lstpItems)
        {
            CBaseData* pData;
            if(pData = g_dataPtr(pItem))
            {
                if(pData->GetName() == name)
                {
                    CPinItem* tmp = dynamic_cast<CPinItem*>(pItem);
                    if (tmp)
                    {
                        pPinItem = tmp;
                        break;
                    }
                }
            }
        }
    }

    Q_ASSERT(pPinItem ? g_dataPtr(pPinItem)->GetName() == name : name == "");
}

void CLinkLineItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    int drawtype=Hmi::Normal;
    if (scene())
        drawtype=((CGraphScene*)scene())->LinkMode();

    QPolygonF  vialdpg=polygon();
    if((drawtype==Hmi::Draw2Mergin) && polygon().count()>=2)
    {
        QLineF centerLine(polygon().last(),polygon().at(polygon().count()-2));
        QPointF p1 ;
        QPointF p2;
        QPointF intersectPoint;
        QLineF polyLine;
        QGraphicsItem* ptailItem=GetPinLinkItem(Tail);
        if(ptailItem)
        {
            QPolygonF box=ptailItem->mapRectToScene(ptailItem->boundingRect());
            p1=box.at(0);
            for (int i = 1; i < box.count(); ++i) {
                p2 = box.at(i)  ;
                polyLine = QLineF(p1, p2);
                QLineF::IntersectType intersectType = polyLine.intersect(centerLine, &intersectPoint);
                if (intersectType == QLineF::BoundedIntersection)
                    break;
                p1 = p2;
            }
            if(!intersectPoint.isNull() && centerLine.length()>0)
            {
                vialdpg.pop_back();
                vialdpg.append(intersectPoint);
            }
        }
    }

    ///
    if (g_ifExplorer( scene()))
	{
        CPolylineItem::paintEx(painter,vialdpg, option  );
        QVariant bgcolor=m_pData->property("bgColor");
        if (bgcolor.isValid())
            g_PaintBackground(scene(), painter, option, QPainterPath(shape()), bgcolor.toString());
		return;
	}

    if (drawtype!= Hmi::Normal && drawtype!= Hmi::Draw2Mergin)
	{
        if (!m_bInitPos)//init draw link
        {
            CalPolygon(painter, option);
            vialdpg=polygon();
        }
	}

    CPolylineItem::paintEx(painter,vialdpg, option );

    painter->save();
    Q_UNUSED(widget);
    float ww = pen().width() * 1;//2;
	if (ww > CORNER_RECTPAD)
		ww = CORNER_RECTPAD;

	QPointF CORNER_POINT(ww, ww);
    bool headActive = m_hintItemArray[Head]!=NULL;
    bool tailActive = m_hintItemArray[Tail]!=NULL;

    QBrush b;
    QPen pen(Qt::gray, 0, Qt::SolidLine );
    pen.setWidthF( 0 );
    b.setColor(tailActive?Qt::green : Qt::red);
    b.setStyle(Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(b);
    QPointF node = polygon().last();
    QRectF nodeRectF(node-CORNER_POINT, node+CORNER_POINT);
    painter->drawRect(nodeRectF);

    b.setColor(headActive ? Qt::green : Qt::red);
    painter->setBrush(b);
    node = polygon().first();
    nodeRectF = QRectF(node-CORNER_POINT, node+CORNER_POINT);
    painter->drawRect(nodeRectF);

    painter->restore();

}

void CLinkLineItem::CalPolygon(QPainter *painter, const QStyleOptionGraphicsItem *option )
{
    if (m_head == NULL || m_tail == NULL || m_bRemoved)//??m_bRemoved
	{
        //CPolylineItem::paint(painter, option, widget);
		return;
	}
    if (m_head->collidesWithItem(m_tail))
    {
        //qDebug("Colliding?!");
        return;
    }

	int nMode = ((CGraphScene*)scene())->LinkMode();

    QPen myPen = pen();
    myPen.setColor(myColor);
    qreal arrowSize = 10;
    //QColor mySelectedColor = Qt::blue;
    if (isSelected())
    {
        painter->setPen(QPen(mySelectedColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->setBrush(mySelectedColor);
    }
    else
    {
        painter->setPen(myPen);
        painter->setBrush(myColor);
    }
    QLineF curLine;
    QPointF p = mapFromItem(m_head->parentItem(), m_head->pos());
    QPointF p_ = mapFromItem(m_tail->parentItem(), m_tail->pos());

	QPolygonF lineps;

	if (nMode == Hmi::Left2Right)
	{

		qreal xMin = p.x() > p_.x() ? p_.x() : p.x();
		qreal xMax = p.x() > p_.x() ? p.x() : p_.x();
		qreal yMin = p.y() > p_.y() ? p_.y() : p.y();
		qreal yMax = p.y() > p_.y() ? p.y() : p_.y();

		QLineF centerLine(p, p_);

		QPolygonF endPolygon = m_tail->boundingRect();
		QPointF p1 = endPolygon.first() + p_;
		QPointF p2;
		QPointF intersectPoint(0, 0);
		QLineF polyLine;
		for (int i = 1; i < endPolygon.count(); ++i)
		{
			p2 = endPolygon.at(i) + p_;
			polyLine = QLineF(p1, p2);
			QLineF::IntersectType intersectType =
				polyLine.intersect(centerLine, &intersectPoint);
			if (intersectType == QLineF::BoundedIntersection)
			{
				break;
			}
			p1 = p2;
		}

		QPointF s1, s2;
		qreal distance = intersectPoint.rx() - p.rx();
		QLineF curLine;
		int nLineSize = polygon().size() - 1;
		
	//	setPolygon(QPolygon(0));

		if (distance >= 0)
		{
			if (m_nConnType != Conn_Normal)
			{
				m_VerticalPos = (p.rx() + p_.rx()) / 2;
				m_nConnType = Conn_NoInit;
				m_OffsetX = 0;
			}
			s1.setX(m_VerticalPos + m_OffsetX);
			s1.setY(p.ry());
			if (m_nConnType == Conn_Normal && !m_bInDragMode)
			{
				if ((m_VerticalPos + m_OffsetX) < xMin || (m_VerticalPos + m_OffsetX) > xMax)
				{
					m_nConnType = Conn_NoInit;
					m_VerticalPos = (p.rx() + p_.rx()) / 2;
					m_OffsetX = 0;
					s1.setX(m_VerticalPos + m_OffsetX);
				}
			}
			s2.setX(m_VerticalPos + m_OffsetX);
			s2.setY(p_.ry());

			lineps.append(p);
			lineps.append(s1);
			lineps.append(s2);
			lineps.append(p_);
		}
		else
        {
            if (m_nConnType != Conn_Reverse)
            {
                m_HorizontalPos = (p.ry() + p_.ry()) / 2;
                m_OffsetY = 0;
                m_nConnType = Conn_NoInit;
            }
            s1.setX(p.rx() + 30);
            s1.setY(p.ry());
            lineps.append(p);
            lineps.append(s1);

            s2.setX(p.rx() + 30);
            s2.setY(m_HorizontalPos + m_OffsetY);
            if (m_nConnType == Conn_Reverse && !m_bInDragMode)
            {
                if ((m_HorizontalPos + m_OffsetY) < yMin || (m_HorizontalPos + m_OffsetY) > yMax)
                {
                    m_nConnType = Conn_NoInit;
                    m_HorizontalPos = (p.ry() + p_.ry()) / 2;
                    m_OffsetY = 0;
                    s2.setY(m_HorizontalPos + m_OffsetY);
                }
            }

            lineps.append(s2);

            s1.setX(p_.rx() - 30);
            s1.setY(m_HorizontalPos + m_OffsetY);

            lineps.append(s1);

            s2.setX(p_.rx() - 30);
            s2.setY(p_.ry());

            lineps.append(s2);

            s1.setX(p_.rx() - arrowSize * 0.5);
            s1.setY(p_.ry());

			lineps.append(s1);
        }
    }
	else if (nMode == Hmi::One90angle)
    {
        QPointF p2 ;
        if (m_nConnType == Conn_NoInit)
        {
            if (p.ry() < p_.ry())
            {
                m_nConnType = Conn_Reverse;
            }
            else
            {
                m_nConnType = Conn_Normal;
            }
        }
        if (m_nConnType == Conn_Normal)
        {
            p2 = QPointF(p_.rx(), p.ry());
        }
        else
        {
            p2 = QPointF(p.rx(), p_.ry());
        }

		lineps.append(p);
		lineps.append(p2);
		lineps.append(p_);

    }
    else
    {
        QLineF curLine;
		int nLineSize = polygon().size() - 1;

		//setPolygon(QPolygon(0));
		
        if (p.x() == p_.x() || p.y() == p_.y())
        {
			lineps.append(p);
			lineps.append(p_);
        }
        else
        {
            qreal xMin = p.x() > p_.x() ? p_.x() : p.x();
            qreal xMax = p.x() > p_.x() ? p.x() : p_.x();
            qreal yMin = p.y() > p_.y() ? p_.y() : p.y();
            qreal yMax = p.y() > p_.y() ? p.y() : p_.y();
            QPointF s1, s2;
            qreal distance = p_.ry() - p.ry();
            if (distance >= 0)
            {
                if ( m_nConnType != Conn_Normal)
                {
                    m_HorizontalPos = (p.ry() + p_.ry()) / 2;
                    m_nConnType = Conn_NoInit;
                    m_OffsetY = 0;
                }
                s1.setY(m_HorizontalPos + m_OffsetY);
                s1.setX(p.rx());
                if (m_nConnType == Conn_Normal && !m_bInDragMode)
                {
                    if ((m_HorizontalPos + m_OffsetY) < yMin || (m_HorizontalPos + m_OffsetY) > yMax)
                    {
                        m_nConnType = Conn_NoInit;
                        m_HorizontalPos = (p.ry() + p_.ry()) / 2;
                        m_OffsetY = 0;
                        s1.setY(m_HorizontalPos + m_OffsetY);
                    }
                }
                s2.setY(m_HorizontalPos + m_OffsetY);
                s2.setX(p_.rx());

				lineps.append(p);
				lineps.append(s1);
				lineps.append(s2);
				lineps.append(p_);
            }
            else
            {
                if (m_nConnType != Conn_Reverse)
                {
                    if (m_bStartFirstHalf)
                    {
                        m_VerticalPos = qMin(p.rx(), p_.rx()) - 50;
                    }
                    else
                    {
                        m_VerticalPos = qMax(p.rx(), p_.rx()) + 50;
                    }
                    m_OffsetX = 0;
                    m_nConnType = Conn_NoInit;
                }
                s1.setX(p.rx() );
                s1.setY(p.ry() + 30);

				lineps.append(p);
				lineps.append(s1);
				
                s2.setX(m_VerticalPos + m_OffsetX);
                s2.setY(p.ry() + 30);
                
				lineps.append(s2);

                s1.setX(m_VerticalPos + m_OffsetX);
                s1.setY(p_.ry() - 30);

				lineps.append(s1);

                s2.setY(p_.ry() - 30);
                s2.setX(p_.rx());

				lineps.append(s2);
				lineps.append(p_);
            }
        }
    }

	if (lineps.size() > 0)
	{
		setPolygon(lineps);
	}


}

QVariant CLinkLineItem::itemChange( GraphicsItemChange change, const QVariant& value )
{
    if ( g_ifExplorer(scene()))
		return QGraphicsItem::itemChange(change, value);

    if (change == ItemParentHasChanged)
    {
    }

    if (change == ItemSceneHasChanged)
    {
        QGraphicsScene* scene = value.value<QGraphicsScene*>();
        if(scene)
        {
            QList<QGraphicsItem*> collidList = collidingItems();
            if(collidList.empty())
                return value;
            foreach(QGraphicsItem* item, collidList)
            {
                if(item->type() == Hmi::Pin)
                {
                    if(item->contains(item->mapFromItem(this, polygon().first())))
                    {
                        m_hintItemArray[0]=item;
                    }
                    else if(item->contains(item->mapFromItem(this,polygon().last())))
                    {
                        m_hintItemArray[1]=item;
                    }
                    break;
                }
                else if(item->type() == Hmi::Link)
                {


                    break;
                }
            }
        }
        else
        {
            if(m_head)
                m_head->DelLink(this);
            if(m_tail)
                m_tail->DelLink(this);
        }
    }

    return value;
}

void CLinkLineItem::AdjustNodes()
{
    QPolygonF poly = polygon();
	if (m_tail)
		poly.last() = m_tail->scenePos();
	if (m_head)
		poly.first() = m_head->scenePos();

    setPolygon(poly);
}

static bool g_PinOverLinkSortFunc(const QGraphicsItem* lhs, const QGraphicsItem* rhs)
{
    return g_isPinItem(lhs->type());
}


QGraphicsItem* CLinkLineItem::TestHintItem(int pointId)
{
	if (polygon().size() == 0)
		return NULL;

    if(pointId!=0 && pointId!=polygon().size()-1)
         return NULL;

     int id = !!pointId;
     CPinItem*& activePin = (pointId==0 ? m_head : m_tail);
     const QPointF pointF = polygon()[pointId];
     const QRectF r = QRectF(pointF-QPointF(1, 1), QSize(3, 3));
     QList<QGraphicsItem*> collidList = scene()->items(mapRectToScene(r), Qt::IntersectsItemShape, Qt::AscendingOrder);
     collidList.removeOne(this);
     if(collidList.empty())
     {
 #if 0
         activePin->DelLink(this);
         activePin = NULL;
 #else
         m_hintItemArray[id] = NULL;
 #endif
         return NULL;
     }

     qSort(collidList.begin(), collidList.end(), g_PinOverLinkSortFunc);
     bool isHint=false;
     foreach(QGraphicsItem* item, collidList)
     {
         if(g_isPinItem(item->type()))
         {
             isHint = true;
             if(activePin!=item)
             {
                 m_hintItemArray[id] = item;
                 return item;
             }
         }
         else if(!isHint && Hmi::Link == item->type() && this != item)
         {
             m_hintItemArray[id] = item;
             return item;
         }
     }

     if(!isHint )
     {
         m_hintItemArray[id] = NULL;
     }

     return NULL;
}

static qreal g_CalDistance(const QPointF& tagP, const QPointF& lineP1, const QPointF& lineP2)
{
    qreal A= lineP2.y()-lineP1.y();
    qreal B= lineP1.x()-lineP2.x();
    qreal C= lineP2.x()*lineP1.y()-lineP1.x()*lineP2.y();
    return (fabs(A*tagP.x()+B*tagP.y()+C)/sqrt(A*A+B*B));
}
QPointF CLinkLineItem::Split( const CLinkLineItem* sectItem, int activePointId, QPolygonF& section1, QPolygonF& section2 )
{
    const QLineF sectLine =
            (activePointId==0) ? QLineF(sectItem->polygon()[1], sectItem->polygon().first())
        :QLineF(sectItem->polygon()[sectItem->polygon().size()-2], sectItem->polygon().last());
    QPointF p = mapFromScene(sectLine.p2());
    const QPolygonF poly = polygon();
    if(poly.empty())
        return QPointF();
    int i;
    for(i=0; i<poly.size()-1; ++i)
    {
        qreal d = g_CalDistance(p, poly[i], poly[i+1]);
        //qDebug("distance for %d: %f", i, d);
        if(d < ACTIVE_RECTPAD+2)
            break;
    }

    if(i == poly.size()-1)
        return QPointF();

    QPointF sectPoint;
    QLineF(poly[i], poly[i+1]).intersect(sectItem->itemTransform(this).map(sectLine), &sectPoint);
    if(sectPoint.isNull())
        return sectPoint;

    section1 = poly.mid(0, i+1);
    section1.push_back(sectPoint);
    section2.push_back(sectPoint);
    section2+=poly.mid(i+1, -1);
    //qDebug("section1 len: %d, section2 len: %d, sectPoint: %d, %d", section1.size(), section2.size(), sectPoint.x(), sectPoint.y());
    return mapToScene(sectPoint);
}

QPointF CLinkLineItem::Split( QPointF pos ,int blockLength , QPolygonF& section1, QPolygonF& section2 )
{
    QPointF sectPoint;
    QPointF p = mapFromScene(pos);
    const QPolygonF poly = polygon();
    if(poly.empty())
        return sectPoint;
    int i;
    for(i=0; i<poly.size()-1; ++i)
    {
        qreal d = g_CalDistance(p, poly[i], poly[i+1]);
        //qDebug("distance for %d: %f", i, d);
        if(d < ACTIVE_RECTPAD+2)
            break;
    }
    if(i == poly.size()-1)
        return sectPoint;


    qreal kk=QLineF(poly[i],p).length()/QLineF(poly[i],poly[i+1]).length();
    if(kk<0.05 || kk>0.95)
        return sectPoint;
    sectPoint=QLineF(poly[i],poly[i+1]).pointAt(kk);
    QPointF sectPoint1=sectPoint;
    QPointF sectPoint2=sectPoint;
    if(blockLength>0)
    {
        qreal kk1=(QLineF(poly[i],sectPoint).length()-blockLength/2)/QLineF(poly[i],poly[i+1]).length();
        qreal kk2=(QLineF(poly[i],sectPoint).length()+blockLength/2)/QLineF(poly[i],poly[i+1]).length();
        sectPoint1=QLineF(poly[i],poly[i+1]).pointAt(kk1);
        sectPoint2=QLineF(poly[i],poly[i+1]).pointAt(kk2);
    }

    section1 = poly.mid(0, i+1);
    section1.push_back(sectPoint1);
    section2.push_back(sectPoint2);
    section2+=poly.mid(i+1, -1);
    //qDebug("section1 len: %d, section2 len: %d, sectPoint: %d, %d", section1.size(), section2.size(), sectPoint.x(), sectPoint.y());
   // return sectPoint;
    return mapToScene(sectPoint);
}

bool CLinkLineItem::IsInitConnected()
{
    return m_head != NULL && m_tail != NULL;
}

void CLinkLineItem::SetRunningFlag(QVariant tagValue)
{
    double val = tagValue.toDouble();
    int tmpDret = 0;
    if (val > 0)
        tmpDret = 0;
    else
        tmpDret = 1;

    if (m_pProAnimation == NULL)
    {
        m_runningDirection = tmpDret;
        m_pProAnimation=UnqFunc()->CreatePathAnimate(this, m_runningDirection );
    }
    else if (m_runningDirection != tmpDret){
        m_runningDirection = tmpDret;
        m_pProAnimation->stop();

        QVector<QPointF> points;
        for (int i = 0; i < polygon().size(); i++)
        {
            points.push_back( m_runningDirection == 0 ? polygon().at(i) : polygon().at(polygon().size() - 1 - i) );
        }
        QPainterPath path = QPainterPath();
        path.addPolygon(points);

        m_pProAnimation->SetPath(path);
        m_pProAnimation->start();
    }

}

void CLinkLineItem::DoRunning()
{
}

void CLinkLineItem::DelLink( CPinItem* item )
{
    if(!item)
        return;
    item->DelLink(this);
    if(m_head == item)
        m_head = NULL;
    else if(m_tail == item)
        m_tail = NULL;
}

void CLinkLineItem::SetLink( CPinItem* item, bool isHead )
{
    if(isHead)
    {
        if(m_head)
            m_head->DelLink(this);
        m_head = item;
		if (m_head && polygon().size()>0)
            m_head->AddLink(this, m_head->mapFromItem(this, polygon().first()));
        m_hintItemArray[Head] = item;
    }
    else
    {
        if(m_tail)
            m_tail->DelLink(this);
        m_tail = item;
		if (m_tail && polygon().size()>0)
            m_tail->AddLink(this, m_tail->mapFromItem(this, polygon().last()));
        m_hintItemArray[Tail] = item;
    }
    //update();
}

void CLinkLineItem::SetLink( CPinItem* headItem, CPinItem* tailItem )
{
    if(m_head)
        m_head->DelLink(this);
    m_head = headItem;
	if (m_head && polygon().size()>0)
        m_head->AddLink(this, m_head->mapFromItem(this, polygon().first()));
    m_hintItemArray[Head] = m_head;

    if(m_tail)
        m_tail->DelLink(this);
    m_tail = tailItem;
	if (m_tail && polygon().size()>0)
        m_tail->AddLink(this, m_tail->mapFromItem(this, polygon().last()));
    m_hintItemArray[Tail] = m_tail;
    //update();
}


void CLinkLineItem::PassLink( bool isHead, CLinkLineItem* refLinkItem, bool isRefHead )
{
    CPinItem*& pin1 = isHead?m_head:m_tail;
    CPinItem*& pin2 = isRefHead?refLinkItem->m_head:refLinkItem->m_tail;
    refLinkItem->SetLink(pin1, isRefHead);
    if(pin1)
    {
        pin1->DelLink(this);

    }
    pin1 = NULL;
    SetLink(NULL, isHead);
}

void CLinkLineItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
	int nMode = ((CGraphScene*)scene())->LinkMode();
	if (scene() && (g_ifExplorer(scene()) || nMode == Hmi::Normal))
	{
		return;
	}
	
	qreal extra = (pen().width() + 10) / 2.0;
	int nSetCursorType = 0;
	QLineF lineM;
	if (polygon().size() == 4)
	{
		lineM = QLineF(polygon().at(1), polygon().at(2));
		QRectF rect = QRectF(lineM.p1(), lineM.p2()).normalized().adjusted(-extra, -extra, extra, extra);
		if (rect.contains(event->pos()))
		{
			if (nMode == Hmi::Left2Right)
			{
				nSetCursorType = 1;
			}
			else
			{
				nSetCursorType = 2;
			}
		}
	}
	else if (polygon().size() > 4)
	{
		lineM = QLineF(polygon().at(2), polygon().at(3));// m_connLines.at(2);
		QRectF rect = QRectF(lineM.p1(), lineM.p2()).normalized().adjusted(-extra, -extra, extra, extra);
		if (rect.contains(event->pos()))
		{
			if (nMode == Hmi::Left2Right)
			{
				nSetCursorType = 2;
			}
			else
			{
				nSetCursorType = 1;
			}
		}
	}

	if (nSetCursorType != m_nCursorType)
	{
		switch (nSetCursorType)
		{
		case 1:
			{
				setCursor(Qt::SplitHCursor);
				if (m_bInitPos)
					m_VerticalPos = lineM.p1().rx();
			}
			break;
		case 2:
			{
				setCursor(Qt::SplitVCursor);
				if (m_bInitPos)
					m_HorizontalPos = lineM.p1().ry();
			}
			break;
		default:
			unsetCursor();
			break;
		}
		m_nCursorType = nSetCursorType;
	}
	m_bInDragArea = (nSetCursorType != 0);
	QGraphicsPolygonItem::hoverMoveEvent(event);
}

void CLinkLineItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (scene() && (g_ifExplorer( scene()) || ((CGraphScene*)scene())->LinkMode() == Hmi::Normal))
	{
		return;
	}
	if (m_nCursorType != 0)
	{
		unsetCursor();
		m_nCursorType = 0;
		m_bInDragArea = false;
	}
	QGraphicsPolygonItem::hoverLeaveEvent(event);
}

void CLinkLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (scene() && (g_ifExplorer( scene())|| ((CGraphScene*)scene())->LinkMode() == Hmi::Normal))
	{
		return;
	}	
	if (m_bInDragArea)
	{
		m_bInDragMode = true;
		m_OrgPoint = event->pos();

		m_nConnType = Conn_Normal;
		if (polygon().size() == 6)
		{
			m_nConnType = Conn_Reverse;
		}
	}

	QGraphicsPolygonItem::mousePressEvent(event);
}

void CLinkLineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	m_bInitPos = false;
	if (m_bInDragMode)
	{
		if (boundingRect().contains(event->pos()))
		{	
			m_OffsetX = event->pos().x() - m_OrgPoint.x();
			m_OffsetY = event->pos().y() - m_OrgPoint.y();
		}
	}
	QGraphicsPolygonItem::mouseMoveEvent(event);
}

void CLinkLineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (m_bInDragMode)
	{
		m_VerticalPos += m_OffsetX;
		m_HorizontalPos += m_OffsetY;
		m_OffsetX = 0;
		m_OffsetY = 0;
	}
	m_bInDragMode = false;
	QGraphicsPolygonItem::mouseReleaseEvent(event);
}

QGraphicsItem* CBusData::Clone()
{
    CBusItem* pLineItem = new CBusItem(NULL);
    pLineItem->setLine(((CBusItem*)m_pItem)->line());
    g_dataPtr(pLineItem)->Copy(g_dataPtr(m_pItem));

    return pLineItem;
}

void CBusData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    G_G(CBusItem)
            QLineF line= G->line();
    xio->WriteAttribute("x1",line.x1());
    xio->WriteAttribute("y1",line.y1());
    xio->WriteAttribute("x2",line.x2());
    xio->WriteAttribute("y2",line.y2());
    QStringList linkItemNames = G->m_linkItemNames;
    QString names;
    for (int i = 0;i<linkItemNames.size();i++)
    {
        if (i != 0)
            names += ",";
        names += linkItemNames[i];
    }
    xio->WriteAttribute("linkedOfItems",names);
    CBaseData::SaveBaseProperty(xio);
}

void CBusData::LoadBaseProperty(CGraphSvgReader* xio)
{
    G_G(CBusItem)
            qreal x1,y1,x2,y2;
    xio->ReadAttribute("x1", x1);
    xio->ReadAttribute("y1", y1);
    xio->ReadAttribute("x2", x2);
    xio->ReadAttribute("y2", y2);
    QString names;
    xio->ReadAttribute("linkedOfItems",names);
    G->m_linkItemNames = names.split(",");
    G->setLine(QLineF(x1,y1,x2,y2));
    CBaseData::LoadBaseProperty(xio);
}

QVariantList	CBusData::Points()  {
    QVariantList ret;
    G_G(CBusItem)
            QLineF line= G->line();
    QVariantList pnt;
    pnt<<line.x1()<<line.y1();
    ret.append(pnt);
    pnt<<line.x2()<<line.y2();
    ret.append(pnt);
    return ret;
}

void	CBusData::SetPoints(const QVariantList& pnts){
    G_G(CBusItem)
            qreal x1,y1,x2,y2;
    if(pnts.size()!=2) {
        gDebug("CBusData::SetPoints----error ,size!=2--");
        return ;
    }
    QVariantList pnt1= pnts[0].toList();
    QVariantList pnt2= pnts[0].toList();
    if(pnt1.size()==2 && pnt2.size()==2)
        G->setLine(QLineF(pnt1[0].toFloat(),pnt1[1].toFloat(),pnt2[0].toFloat(),pnt2[1].toFloat()));
    else
        gDebug("CBusData::SetPoints---point-error ,size!=2");
}

void CBusData::GetPropertyList(QList< QPair<QString, QVariant> >& property_list)
{
    CBaseData::GetPropertyList(property_list);
    CBusItem* pItem = (CBusItem*)Item();
    property_list.push_back(qMakePair(CBaseData::tr("length"), QVariant(pItem->line().length())));
}

bool CBusData::SetProperty(const QString& propname, const QVariant& value)
{
    CBusItem* pItem = (CBusItem*)Item();
    if (propname == CBaseData::tr("length") || propname == "length")
    {
        QLineF line = pItem->line();
        line.setLength(value.toReal());
        pItem->setLine(line);
    }
    else
        return CBaseData::SetProperty(propname, value);
}
void CBusData::SetLineColor(const QColor& color)
{
    G_G(CBusItem)
            G->m_shapeData.strokeColor = color;
    G->update();
}
QColor CBusData::GetLineColor() const
{
    G_G(CBusItem)
            return G->m_shapeData.strokeColor;
}
void CBusData::SetFillColor(const QColor& color)
{
    G_G(CBusItem)
            G->m_shapeData.fillColor = color;
}
QColor CBusData::GetFillColor() const
{
    G_G(CBusItem)
            return G->m_shapeData.fillColor;
}
Qt::BrushStyle CBusData::GetFillStyle() const
{
    G_G(CBusItem)
            return G->m_shapeData.brushStyle;
}
void CBusData::SetFillStyle(Qt::BrushStyle style)
{
    G_G(CBusItem)
            G->m_shapeData.brushStyle = style;
}
Qt::PenStyle CBusData::GetLineStyle() const
{
    G_G(CBusItem)
            return G->m_shapeData.penStyle;
}
void CBusData::SetLineStyle(Qt::PenStyle style)
{
    G_G(CBusItem)
            G->m_shapeData.penStyle = style;
}
qreal CBusData::GetLineWidth() const
{
    G_G(CBusItem)
            return G->m_shapeData.strokeWidth;
}
void CBusData::SetLineWidth(qreal width)
{
    G_G(CBusItem)
            G->m_shapeData.strokeWidth = width;
}
CBusItem::CBusItem( QGraphicsItem* parent ) : CPinItem(parent)
{
    m_data = new CBusData(this);
    m_shapeData.strokeColor = Qt::red;
    m_shapeData.strokeWidth = 5;
    g_SetData(this, m_data);
}

CBusItem::~CBusItem()
{
    delete m_data;
}

QPainterPath CBusItem::shape() const
{
    QPainterPath path;
    path.moveTo(m_line.p1());
    path.lineTo(m_line.p2());
    QPainterPathStroker strok;
    strok.setWidth(m_shapeData.strokeWidth*2);
    return strok.createStroke(path);
}
QRectF CBusItem::boundingRect() const
{
    return shape().controlPointRect();
}

void CBusItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    Q_UNUSED(widget);

    QPen p(m_shapeData.strokeColor,m_shapeData.strokeWidth);
    painter->setPen(p);
    painter->drawLine(m_line);

    if (option->state & QStyle::State_Selected)
		g_PaintBoundingRect(scene(), painter, option, boundingRect());

    QString sceneType;
    if(g_ifExplorer( scene()))
    {
        QVariant bgcolor=m_data->property("bgColor");
        if (bgcolor.isValid())
            g_PaintBackground(scene(), painter, option, QPainterPath(shape()), bgcolor.toString());
        return;
    }
    QVarLengthArray<QRectF, 10> rectsArray(m_linkPointMap.size());
    QMapIterator<CLinkLineItem*, QPointF> i(m_linkPointMap);
    int num=0;
    int mergin=1;//CORNER_RECTPAD
    while(i.hasNext())
    {
        i.next();
        rectsArray[num++] = QRectF(i.value()-QPointF(mergin, mergin), i.value()+QPointF(mergin, mergin));
    }
    static const QBrush b(Qt::magenta);
    painter->setBrush(b);
    painter->drawRects(rectsArray.constData(), num);

}

QVariant CBusItem::itemChange( GraphicsItemChange change, const QVariant& value )
{
    bool ifge=g_ifExplorer(scene());
    if (ifge)
		return QGraphicsItem::itemChange(change, value);

    if(ItemScenePositionHasChanged == change)
    {
        if(!ifge){
            QList<QGraphicsItem *> selectItems=((CGraphScene*)scene())->Items(true,true);
            if(selectItems.size()>2) ///如果是批量移动就不处理了///
                return QGraphicsItem::itemChange(change, value);
        }

        QPointF scenePos = value.toPointF();
        QList<QGraphicsItem*> cItems = collidingItems();
        QMapIterator<CLinkLineItem*, QPointF> i(m_linkPointMap);
        while(i.hasNext())
        {
            i.next();
            CLinkLineItem* item = i.key();
            const QPointF p = i.value();
            QPointF pos = item->mapFromItem(this, p);
            QPolygonF poly = item->polygon();
            if(item->IsHeadPinItem(this))
            {
                poly.first()=pos;
            }
            else
            {
                //qDebug()<<"last: "<<poly.last()<<" first: "<<poly.first()<<" pos: "<<pos;
                poly.last()=pos;
            }
            item->setPolygon(poly);
            item->setToolTip("item chg");
            cItems.removeOne(item);
        }
        if (!cItems.empty())
        {
            foreach(QGraphicsItem* item, cItems)
            {
                if (item->type()!=Hmi::Link)
                    continue;
                CLinkLineItem* linkItem = static_cast<CLinkLineItem*>(item);
                if (contains(mapFromItem(linkItem, linkItem->polygon().last())) && !linkItem->HasEnd())
                {
                    AddLink(linkItem, mapFromItem(linkItem, linkItem->polygon().last()));
                    linkItem->SetLink(this, false);
                }
                else if(contains(mapFromItem(linkItem, linkItem->polygon().first())) && !linkItem->HasBegin())
                {
                    AddLink(linkItem, mapFromItem(linkItem, linkItem->polygon().first()));
                    linkItem->SetLink(this, true);
                }
            }
        }
    }
    else if(ItemSceneHasChanged == change)
    {
        QGraphicsScene* scene = value.value<QGraphicsScene*>();
        if(scene)
            return value;


        QMapIterator<CLinkLineItem*, QPointF> i(m_linkPointMap);
        while(i.hasNext())
        {
            i.next();
            i.key()->DelLink(this);
        }

    }
    return value;
}

void CBusItem::setLine( const QLineF& line )
{
    prepareGeometryChange();
    m_line = line;
}




QGraphicsItem* CAbstractPathData::Clone()
{
    if (dynamic_cast<CPathItem*>(m_pItem))
    {
        CPathItem* pItem = new CPathItem();
        g_dataPtr(pItem)->Copy( this);
        return pItem;
    }
    else
    {
        CClosePathItem* pItem = new CClosePathItem();
        g_dataPtr(pItem)->Copy( this);
        return pItem;
    }
}

void CAbstractPathData::Copy(const CBaseData* srcData)
{
    CBaseData::Copy(srcData);
    m_Symbol=((CAbstractPathData*)srcData)->GetSymbolName();
    if (dynamic_cast<CPathItem*>(m_pItem))
    {
        G_G(CPathItem)
                CPathItem* psrcItem=(CPathItem*)(srcData->Item());
        G->setPath(psrcItem->path());
        G->ApplyInflexionVec(psrcItem->m_inflexionVec);
    }
    else
    {
        G_G(CClosePathItem)
                CClosePathItem* psrcItem=(CClosePathItem*)(srcData->Item());
        G->setPath(psrcItem->path());
        G->ApplyInflexionVec(psrcItem->m_inflexionVec);
    }
}

void CAbstractPathData::SaveBaseProperty(CGraphSvgWriter* xio) const
{
    CAbstractPathItem* pAbsPathItem = dynamic_cast<CAbstractPathItem*>(m_pItem);
    Q_ASSERT(pAbsPathItem);

    xio->WriteAttribute("path-flag",(int)m_PathFlag);
    if(!m_Symbol.isEmpty())
        xio->WriteAttribute("symbol",m_Symbol);
    else
    {
		QString CBpath;	
		QPainterPath path = pAbsPathItem->path();
		if (path.elementCount()>0)
			CBpath = QString("M %1,%2 ").arg(path.elementAt(0).x).arg(path.elementAt(0).y);
		for (int i = 1; i < path.elementCount(); i++)
		{
			QPainterPath::Element ele = path.elementAt(i);
			if (ele.isMoveTo())
			{
				CBpath += QString("M %1,%2 ").arg(ele.x).arg(ele.y);
			}
			else if (ele.isLineTo())
			{
				CBpath += QString("L %1,%2 ").arg(ele.x).arg(ele.y);
			}
			else if (ele.isCurveTo())
			{
				CBpath += QString("C %1,%2 %3,%4 %5,%6 ")
					.arg(ele.x).arg(ele.y)
					.arg(path.elementAt(i + 1).x).arg(path.elementAt(i + 1).y)
					.arg(path.elementAt(i + 2).x).arg(path.elementAt(i + 2).y);
				i += 2;
			}
		}
	/*
	else
	{
			QVarLengthArray<QPointF, 30> bezierArray = pAbsPathItem->CreateCBezier();
			CBpath = QString("M %1,%2 ").arg(bezierArray[0].x()).arg(bezierArray[0].y());
			for (int i = 0; i<(bezierArray.size() - 1) / 3; ++i)
			{
				CBpath += QString("C %1,%2 %3,%4 %5,%6 ").
					arg(bezierArray[3 * i + 1].x()).
					arg(bezierArray[3 * i + 1].y()).
					arg(bezierArray[3 * i + 2].x()).
					arg(bezierArray[3 * i + 2].y()).
					arg(bezierArray[3 * i + 3].x()).
					arg(bezierArray[3 * i + 3].y());
			}
		}*/
        xio->WriteAttribute("d",CBpath);
    }
    CBaseData::SaveBaseProperty(xio);
}

void CAbstractPathData::LoadBaseProperty(CGraphSvgReader* xio)
{
    CAbstractPathItem* pItem=(CAbstractPathItem*)Item();
    QString pathSvg;

    int  flag=0;
    int ret=xio->ReadAttribute("path-flag",flag);
    if(ret<0)
       m_PathFlag=2;
    else
       m_PathFlag=flag;

    xio->ReadAttribute("symbol",m_Symbol);
    SetSymbolName(m_Symbol);
    if(m_Symbol.isEmpty())
    {
        xio->ReadAttribute("d",pathSvg);
        if(m_PathFlag==2)
        {
            QPainterPath path;
            bool ifok=UnqFunc()->ParsePathData(&pathSvg,path);
            pItem->setPath(path);
            CBaseData::LoadBaseProperty(xio);
            return;
        }
        QStringList LstPathEle = pathSvg.split(" ",QString::SkipEmptyParts);
		if (LstPathEle.size() > 0)
		{
			if (LstPathEle.contains("L"))//import
			{
				QPainterPath path;
				QStringList LststartPt = LstPathEle[1].split(",");
				const QPointF startP(LststartPt[0].toFloat(), LststartPt[1].toFloat());
				pItem->m_inflexionVec.clear();
				pItem->m_inflexionVec.append(startP);
				path.moveTo(startP);
				for (int i = 2; i<LstPathEle.size(); ++i)
				{
					if (LstPathEle[i] == "M")
					{
						QStringList LststartPt = LstPathEle[i + 1].split(",");
						const QPointF P1(LststartPt[0].toFloat(), LststartPt[1].toFloat());
						pItem->m_inflexionVec.append(P1);
						path.moveTo(P1);
						i += 1;
					}
					else if (LstPathEle[i] == "L")
					{
						QStringList LststartPt = LstPathEle[i + 1].split(",");
						const QPointF P1(LststartPt[0].toFloat(), LststartPt[1].toFloat());
						pItem->m_inflexionVec.append(P1);
						path.lineTo(P1);
						i += 1;
					}
					else if (LstPathEle[i] == "C")
					{
						QStringList LststartPt = LstPathEle[i + 1].split(",");
						const QPointF P1(LststartPt[0].toFloat(), LststartPt[1].toFloat());
						QStringList LststartPt2 = LstPathEle[i + 2].split(",");
						const QPointF P2(LststartPt2[0].toFloat(), LststartPt2[1].toFloat());
						QStringList LststartPt3 = LstPathEle[i + 3].split(",");
						const QPointF P3(LststartPt3[0].toFloat(), LststartPt3[1].toFloat());
						pItem->m_inflexionVec.append(P1);
						pItem->m_inflexionVec.append(P2);
						pItem->m_inflexionVec.append(P3);
						path.cubicTo(P1, P2, P3);
						i += 3;
					}
				}
				if (Hmi::ClosePath == pItem->type())
				{
					pItem->m_inflexionVec.pop_back();
				}
				pItem->setPath(path);
			}
			else
			{
				QStringList LststartPt = LstPathEle[1].split(",");
				const QPointF startP(LststartPt[0].toFloat(), LststartPt[1].toFloat());
				pItem->m_inflexionVec.clear();
				pItem->m_inflexionVec.append(startP);
				QPainterPath path;
				path.moveTo(startP);
				const int moveToLen = 2;
				const int CurveLen = 4;
				for (int i = 0; i<(LstPathEle.size() - moveToLen) / CurveLen; i++)
				{
					pItem->m_inflexionVec.append(QPointF(LstPathEle[moveToLen + CurveLen*i + 3].split(",")[0].toFloat(), LstPathEle[moveToLen + CurveLen*i + 3].split(",")[1].toFloat()));
				}
				if (Hmi::ClosePath == pItem->type())
				{
					pItem->m_inflexionVec.pop_back();
				}
				pItem->setPath(pItem->CreatePath());
			}
		}
    }

    CBaseData::LoadBaseProperty(xio);
}

void CAbstractPathData::SetPath(const QPainterPath & path)
{
    CAbstractPathItem* pItem=(CAbstractPathItem*)Item();
    pItem->setPath(path);
}

int CAbstractPathData::SetSymbolName(const QString name)
{
    if(name.isEmpty())
        return -1;
    QPainterPath path=UnqIconMng()->GetPath(name);
    if(!path.isEmpty())
    {
        SetPath(path);
    }
    m_Symbol=name;
    return 0;
}

void CAbstractPathData::GetPropertyList(QList< QPair<QString,QVariant> >& property_list)
{
    CAbstractPathItem* pItem=(CAbstractPathItem*)Item();
    CBaseData::GetPropertyList( property_list);
}

bool CAbstractPathData::SetProperty(const QString& propname,const QVariant& value)
{
    return CBaseData::SetProperty( propname, value);
}


CAbstractPathItem::CAbstractPathItem( QGraphicsItem *parent , int type)
    :QGraphicsPathItem(parent), m_type(type)
{
    m_pData=new CAbstractPathData(this);
    g_SetData(this,m_pData);
}

CAbstractPathItem::~CAbstractPathItem()
{
    if (m_pData)
    {
        delete m_pData;
        m_pData=NULL;
    }
}

QRectF CAbstractPathItem::boundingRect() const
{
    QPainterPathStroker strok;
    strok.setWidth(pen().width());
	qreal cornerW = pen().width();
	return strok.createStroke(path()).boundingRect().adjusted(-cornerW, -cornerW, cornerW, cornerW);
}

void CAbstractPathItem::AppendInflexion( const QPointF& inflexion, bool refresh)
{
	if (m_pData->GetSymbolName().isEmpty() && refresh)
    {
        setPath(CreatePath());
    }

    m_inflexionVec<<mapFromScene(inflexion);
}

void CAbstractPathItem::SetInflexion( int id, const QPointF& inflexion )
{
    Q_ASSERT(id<m_inflexionVec.size() && id>=0);
    m_inflexionVec[id] = mapFromScene(inflexion);
    if(m_pData->GetSymbolName().isEmpty())
    {
        setPath(CreatePath());
    }
}

void CAbstractPathItem::SetTailInflexion( const QPointF& inflexion )
{
    m_inflexionVec.back() = mapFromScene(inflexion);
    if(m_pData->GetSymbolName().isEmpty())
    {
        setPath(CreatePath());
    }
}


void CAbstractPathItem::ApplyInflexionVec( const QVector<QPointF>& vec )
{
    if(m_inflexionVec == vec)
        return;

    m_inflexionVec = vec;
    if(m_pData->GetSymbolName().isEmpty())
    {
        setPath(CreatePath());
    }
}

static inline int roundr(qreal x)
{
    return (int)floorf(x + 0.5);
}

static void g_CalCurveBezierEndp(const QPointF& endp, const QPointF& adjp, QPointF& outp, qreal tension)
{
    outp.rx() = roundr(tension*(adjp.x()-endp.x()) + endp.x());
    outp.ry() = roundr(tension*(adjp.y()-endp.y()) + endp.y());
}

static void g_CalCurveBezier(const QPointF* pts, qreal tension, QPointF& outp1, QPointF& outp2)
{
    qreal xdiff, ydiff;
    xdiff = pts[2].x() - pts[0].x();
    ydiff = pts[2].y() - pts[0].y();
    outp1.rx() = pts[1].x() - tension * xdiff;
    outp1.ry() = pts[1].y() - tension * ydiff;
    outp2.rx() = pts[1].x() + tension * xdiff;
    outp2.ry() = pts[1].y() + tension * ydiff;
}

QPainterPath CPathItem::CreatePath()
{
    const int cnt = m_inflexionVec.size();
	if (cnt <= 1)
		return QPainterPath();
   /* Q_ASSERT(cnt>1);*/
#if 1
    QVarLengthArray<QPointF, 30> bezierArray = CreateCBezier();
#else

#endif

    QPainterPath path;
    path.moveTo(bezierArray[0]);
    for(int i=0; i<cnt-1; ++i)
    {
        path.cubicTo(bezierArray[3*i+1], bezierArray[3*i+2], bezierArray[3*i+3]);
    }
    return path;
}

QVarLengthArray<QPointF, 30> CPathItem::CreateCBezier()
{
    int cnt = m_inflexionVec.size();	
    const int bezierArrayLen = cnt*3 - 2;
    QVarLengthArray<QPointF, 30> bezierArray(bezierArrayLen);
#define TENSION_CONST 0.3;
    const qreal tension = 0.5*TENSION_CONST;
    QPointF p1, p2;
    g_CalCurveBezierEndp(m_inflexionVec[0], m_inflexionVec[1], p1, tension);
    bezierArray[0] = m_inflexionVec[0];
    bezierArray[1] = p1;
    for(int i=0; i<cnt-2; ++i)
    {
        g_CalCurveBezier(&(m_inflexionVec[i]), tension, p1, p2);
        bezierArray[3*i+2] = p1;
        bezierArray[3*i+3] = m_inflexionVec[i+1];
        bezierArray[3*i+4] = p2;
    }
    g_CalCurveBezierEndp(m_inflexionVec[cnt-1], m_inflexionVec[cnt-2], p1, tension);
    bezierArray[bezierArrayLen-2] = p1;
    bezierArray[bezierArrayLen-1] = m_inflexionVec[cnt-1];
    return bezierArray;
}

void CPathItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    //if(g_ifExplorer(scene() )) option->state = option->state&(~QStyle::State_Selected);
    //QGraphicsPathItem::paint(painter, option, widget);
    painter->setPen( pen());
    painter->setBrush( brush());
    painter->drawPath( path());
    if (option->state & QStyle::State_Selected)
    {
        QRectF rect = boundingRect();
		qreal cornerW = pen().width();
		g_PaintBoundingRect(scene(), painter, option, rect, cornerW);

        if (!m_pData->GetSymbolName().isEmpty())
        {
            QVector<QPointF> points;
			points.reserve(4);   
			points << rect.topLeft() << rect.topRight() << rect.bottomLeft() << rect.bottomRight();
			g_HighlightSelected(scene(), painter, option, points, cornerW, true, Qt::darkGreen);
        }else
			g_HighlightSelected(scene(), painter, option, m_inflexionVec, cornerW);
    }
}

QPainterPath CPathItem::shape() const
{
    if( brush().style()==Qt::NoBrush){
        QPainterPathStroker strok;
        strok.setWidth(pen().widthF()*PATHSTROKER);
        return strok.createStroke(path());
    }
    else
        return QGraphicsPathItem::shape();
}

static void g_CalClosedCurveTangents(const QVector<QPointF>& points, qreal tension, QVector<QPointF>& tangents)
{
    float coefficient = tension/3.0;
    const int count = points.size();
    if(count<2)
        return;

    tangents.resize(count);
    for(int i=0; i<count; ++i)
    {
        int r=i+1;
        int s=i-1;

        if(r>=count) r-=count;
        if(s<0) s+=count;

        tangents[i].rx() = (coefficient*(points[r].x() - points[s].x()));
        tangents[i].ry() = (coefficient*(points[r].y() - points[s].y()));
    }
}

QPainterPath CClosePathItem::CreatePath()
{
    const int CNT = m_inflexionVec.size();
    Q_ASSERT(CNT>=2);
#if 1
    QVarLengthArray<QPointF, 30> bezierArray = CreateCBezier();
#else

#endif

    QPainterPath path;
    path.moveTo(bezierArray[0]);
    for(int i=0; i<CNT; ++i)
    {
        path.cubicTo(bezierArray[3*i+1], bezierArray[3*i+2], bezierArray[3*i+3]);
    }
    return path;
}

QVarLengthArray<QPointF, 30> CClosePathItem::CreateCBezier()
{
    int count = m_inflexionVec.size();
    QVarLengthArray<QPointF, 30> bezierArray(3*count + 1);
    QVector<QPointF> tangents;
    g_CalClosedCurveTangents(m_inflexionVec, 0.5, tangents);
    int arrayIndex=0;
    bezierArray[arrayIndex++] = m_inflexionVec[0];
    QPointF p;
    int i;
    for(i=0; i<count-1; ++i)
    {
        int j=i+1;
        p.rx() = m_inflexionVec[i].x() + tangents[i].x();
        p.ry() = m_inflexionVec[i].y() + tangents[i].y();
        bezierArray[arrayIndex++] = p;

        p.rx() = m_inflexionVec[j].x() - tangents[j].x();
        p.ry() = m_inflexionVec[j].y() - tangents[j].y();
        bezierArray[arrayIndex++] = p;

        bezierArray[arrayIndex++] = m_inflexionVec[j];
    }

    p.rx() = m_inflexionVec[i].x() + tangents[i].x();
    p.ry() = m_inflexionVec[i].y() + tangents[i].y();
    bezierArray[arrayIndex++] = p;

    p.rx() = m_inflexionVec[0].x() - tangents[0].x();
    p.ry() = m_inflexionVec[0].y() - tangents[0].y();
    bezierArray[arrayIndex++] = p;

    bezierArray[arrayIndex++] = m_inflexionVec[0];
    return bezierArray;
}
void CClosePathItem::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    QBrush fillbrush = brush();
    UnqFunc()->ProcessBrush(boundingRect(),fillbrush);
    painter->setPen(pen());
    painter->setBrush(fillbrush);
    painter->drawPath(path());
    painter->fillPath(path(),fillbrush);

    if (option->state & QStyle::State_Selected)
    {
		qreal cornerW = pen().width();
		g_HighlightSelected(scene(), painter, option, m_inflexionVec, cornerW);
		g_PaintBoundingRect(scene(), painter, option, boundingRect(), cornerW);
    }
}
