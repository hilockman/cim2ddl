


#include <math.h>
#include "DrawTool.h"
#include "ItemFactory.h"
#include "ItemCreator.h"
#include "GroupItem.h"
#include "WidgetItem.h"
#include <QGraphicsScale>
#include <QUndoStack>
#include "Commands.h"
#include "Global.h"
#include "NameManager.h"
#include "IconMng.h"
#ifdef CHARTS
#include "GChartItem.h"
#endif
#include "GraphScene.h"
#include "DesignerScene.h"

bool IDrawTool::s_lockFlag = true;
bool IDrawTool::s_catchFlag = false;
int IDrawTool::s_gridWidth = 10;
QUndoStack* IDrawTool::s_undoStack = NULL;

const QPointF RESIZE_POINTF(ACTIVE_RECTPAD, ACTIVE_RECTPAD);
static void debugTransform(const QTransform& trs)
{
}

static bool g_IsPointFEqual(const QPointF& lhs, const QPointF& rhs)
{
    return qAbs(lhs.x()-rhs.x())<ACTIVE_RECTPAD
            && qAbs(lhs.y()-rhs.y())<ACTIVE_RECTPAD;
}




void IDrawTool::InitThis( QHash<int, IDrawTool*>& toolHash, QUndoStack* stack )
{
    SetUndoStack(stack);

    toolHash[Hmi::Rect] = new CRectDrawTool;
    toolHash[Hmi::Ellipse] = new CEllipseDrawTool;
    toolHash[Hmi::Circle] = toolHash[Hmi::Ellipse];
    toolHash[Hmi::Line] = new CLineDrawTool;
    toolHash[Hmi::Polygon] = new CPolygonDrawTool;
    toolHash[Hmi::Polyline] = new CPolyLineDrawTool;
    toolHash[Hmi::Group] = new CGroupDrawTool;
    toolHash[Hmi::Symbol] = toolHash[Hmi::Group];
    toolHash[Hmi::Icon] = new CIconDrawTool;
    toolHash[Hmi::IconTest] = toolHash[Hmi::Group];
    toolHash[Hmi::Link] = new CLinkDrawTool;
    toolHash[Hmi::Pin] = new CPinDrawTool;
    toolHash[Hmi::Bus] = new CBusDrawTool;
    toolHash[Hmi::SvgItem] = new CSvgDrawTool;
#ifdef CHARTS
    toolHash[Hmi::QtChart] = new CChartDrawTool;
#endif
    toolHash[Hmi::Text] = new CTextDrawTool;
	toolHash[Hmi::GraphicsText] = new CGraphicsTextDrawTool;
    toolHash[Hmi::Path] = new CAbstractPathDrawTool;
    toolHash[Hmi::ClosePath]= toolHash[Hmi::Path];
    toolHash[Hmi::Pixmap] = new CPixmapDrawTool;

    CWidgetDrawTool* tool = new CWidgetDrawTool;
    for(int i=Hmi::PushButton; i<Hmi::_END; ++i)
        toolHash[i] = tool;

}

IDrawTool::IDrawTool()
{
    m_lastItem = NULL;
    m_lastRotateAngle = 0.0;
    m_activeHintPointF = QPointF();
};

bool IDrawTool::IsNewItem( QGraphicsItem* item )
{

    if(m_lastItem)
    {
        if(m_lastItem == item)
            return false;
        else
        {
            m_lastItem = item;
            return true;
        }
    }
    else
    {
        m_lastItem = item;
        return true;
    }
}

void IDrawTool::Reset()
{
    m_lastRotateAngle = 0.0;
    m_activeHintPointF = QPointF();
}

QPointF IDrawTool::LockPointTransform(const QPointF& scenePointF, const QPointF& referPointF)
{
    if(!s_lockFlag)
        return scenePointF;

    qreal dx = scenePointF.x()-referPointF.x();
    qreal dy = scenePointF.y()-referPointF.y();
    qreal deltaX = fabs(dx), deltaY=fabs(dy);
    if(deltaY>deltaX*0.5 && deltaY<deltaX*1.5)
        return referPointF+QPointF(dx, dy>0?deltaX:-deltaX);
    else if(deltaY<=deltaX/2)
        return referPointF+QPointF(dx, 0);
    else
        return referPointF+QPointF(0, dy);
}

void IDrawTool::PushUndoCommand(QUndoCommand* cmd , QUndoStack *stack)
{
    if(stack && stack!=s_undoStack)
        gInfo("---PushUndoCommand--QUndoStack!=s_undoStack-- ");
    if(stack)
        stack->push(cmd);
    else
        s_undoStack->push(cmd);
}

void IDrawTool::ApplyRotation(const QPointF& pointF)
{
    QPointF center = m_lastItem->sceneBoundingRect().center();
    m_lastRotateAngle = QLineF(center, pointF).angleTo(QLineF(center, GetActiveScenePointF()));

    debugTransform(m_lastItem->transform());
    debugTransform(m_lastItem->sceneTransform());
    EditRotateItemCommand::RotateItem(m_lastItem, g_dataPtr(m_lastItem)->GetOrgRotation()+m_lastRotateAngle);
}

void IDrawTool::RotateFinish()
{
    CBaseData* pdata = g_dataPtr(m_lastItem);
    IDrawTool::PushUndoCommand(new EditRotateItemCommand(m_lastItem, pdata->GetOrgRotation(), m_lastRotateAngle));
    pdata->SetOrgRotation(pdata->GetOrgRotation()+m_lastRotateAngle);
    m_lastRotateAngle = 0;

}

void IDrawTool::InsertFinish()
{
    if (m_lastItem){
        QUndoStack * stack=NULL;
        if( m_lastItem->scene())
            stack= ((CDesignerScene*)m_lastItem->scene())->GetUndoStack();
        IDrawTool::PushUndoCommand(new AddItemCommand(m_lastItem),stack);
    }

}

QGraphicsItem* IDrawTool::CreateItem( QGraphicsScene* scene, const QString& createTypeName, const QPointF& pos )
{
    Reset();
    CreateNew(scene,createTypeName, pos);
	if (createTypeName!="link")
        scene->addItem(m_lastItem);
    /////如果是间隔需要重新调用GlobalSet 做一遍重新建立连接关�?/////
    if( m_lastItem && (m_lastItem->type()==Hmi::Icon) && (((CIconData*)g_dataPtr(m_lastItem))->GetIfRef()==false))
        ItemCreator::GlobalSet(m_lastItem,false);
    return m_lastItem;
}

void CPinDrawTool::SetItem( QGraphicsItem* item )
{
    if(IsNewItem(item))
    {
        Reset();
    }
    m_item = dynamic_cast<CPinItem*>(item);
    Q_ASSERT(m_item);
}

void CPinDrawTool::Reset()
{
    m_item = 0;
    IDrawTool::Reset();
}

void CPinDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    m_item = ItemCreator::CreateSpecifyItem<CPinItem>();
    m_lastItem = m_item;
    m_item->setPos(pos);

    CBaseData* pdata = g_dataPtr(m_item);
    if(!pdata)
        return;
}



void CPolygonDrawTool::SetItem( QGraphicsItem* item )
{
    if(IsNewItem(item))
    {
        Reset();
    }
    m_item = dynamic_cast<QGraphicsPolygonItem*>(item);
    Q_ASSERT(m_item);
    m_lastPolygonF = m_item->polygon();
}

void CPolygonDrawTool::InsertDrawing(const QPointF& pointF)
{
    QPolygonF polygonF = m_item->polygon();
#if 1
    polygonF[polygonF.size()-2] = LockPointTransform(pointF, polygonF[polygonF.size()-3]);
    m_item->setPolygon(polygonF);
#else

    polygonF.last() = pointF;
    polygonF<<polygonF.first();
    m_item->setPolygon(polygonF);
#endif
}

bool CPolygonDrawTool::MouseHint( const QPointF& pointF)
{
    QPointF tmp;
    const QPolygonF polygonF = m_item->polygon();
    int size = m_item->polygon().size();
    for(int resizePointId=0; resizePointId<size; ++resizePointId)
    {
        tmp = m_item->mapToScene(polygonF[resizePointId]);
        if(QRectF(tmp-RESIZE_POINTF, tmp+RESIZE_POINTF).contains(pointF))
        {
            if(resizePointId == size-1 && m_item->type() == Hmi::Polygon)
            {
                m_activePointId = 0;
            }
            else
                m_activePointId = resizePointId;

            m_activeHintPointF = tmp;

            return true;
        }
    }

    m_activePointId = -1;
    return false;
}

void CPolygonDrawTool::EditDrawing( const QPointF& pointF)
{
    Q_ASSERT(m_activePointId>=0);

    QPolygonF polygonF = m_item->polygon();
    if(m_activePointId == 0)
        polygonF.first() = polygonF.last() = LockPointTransform(m_item->mapFromScene(pointF), polygonF[polygonF.size()-2]);
    else
        polygonF[m_activePointId] = LockPointTransform(m_item->mapFromScene(pointF), polygonF[m_activePointId-1]);

    m_item->setPolygon(polygonF);

}

bool CPolygonDrawTool::OnInsertDrawingClicked(const QPointF& pointF)
{
    QPolygonF polygonF = m_item->polygon();


    polygonF.last() = pointF;
    polygonF.push_back(polygonF.first());
    m_item->setPolygon(polygonF);
    return false;
}

bool CPolygonDrawTool::OnInsertDrawingDoubleClicked(const QPointF& pointF)
{
    QPolygonF polygonF = m_item->polygon();
    if(g_IsPointFEqual(polygonF[polygonF.size()-3], polygonF[polygonF.size()-2]))
    {
        polygonF.pop_back();
        polygonF.last() = polygonF.first();
        m_item->setPolygon(polygonF);
    }
	return true;
}

void CPolygonDrawTool::EditFinish()
{
    IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<QGraphicsPolygonItem, QPolygonF>
                               (m_item, m_lastPolygonF,
                                &QGraphicsPolygonItem::setPolygon,
                                m_item->polygon(),
                                "Edit a polygon"));
    m_lastPolygonF = m_item->polygon();
}

void CPolygonDrawTool::Revoke()
{
    m_item->setPolygon(m_lastPolygonF);
}

void CPolygonDrawTool::Reset()
{
    m_item = 0;
    m_activePointId = -1;
    m_lastPolygonF = QPolygonF();
    IDrawTool::Reset();
}

void CPolygonDrawTool::AddPoint( const QPointF& pointF )
{
    QPolygonF poly = m_item->polygon();
    poly.last() = m_item->mapFromScene(pointF);
    poly<<poly.first();
    m_item->setPolygon(poly);
    IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<QGraphicsPolygonItem, QPolygonF>
                               (m_item, m_lastPolygonF,
                                &QGraphicsPolygonItem::setPolygon,
                                m_item->polygon(),
                                "Add a polygon point"));
    m_lastPolygonF = poly;
}

void CPolygonDrawTool::DelPoint()
{
    QPolygonF poly = m_item->polygon();
    poly.remove(m_activePointId);
    poly.last() = poly.first();
    m_item->setPolygon(poly);
    IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<QGraphicsPolygonItem, QPolygonF>
                               (m_item, m_lastPolygonF,
                                &QGraphicsPolygonItem::setPolygon,
                                m_item->polygon(),
                                "Del a polygon point"));
    m_lastPolygonF = poly;
}

void CPolygonDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    m_item = ItemCreator::CreateSpecifyItem<CPolygonItem>();
    m_item->setPolygon(QPolygonF(QVector<QPointF>(3, pos)));
    m_lastItem = m_item;

}



void CPolyLineDrawTool::InsertDrawing( const QPointF& pointF)
{
    QPolygonF polygonF = m_item->polygon();
    polygonF.last() = LockPointTransform(pointF, polygonF[polygonF.size()-2]);
    m_item->setPolygon(polygonF);
    m_item->setToolTip("item chg");
}

bool CPolyLineDrawTool::OnInsertDrawingClicked(const QPointF& pointF)
{
	QPolygonF polygonF = m_item->polygon();
	if (polygonF.size() < 2)
		return false;
	if (pointF != polygonF.at(polygonF.size()-2))
	{
		polygonF.push_back(pointF);
		m_item->setPolygon(polygonF);
		m_item->setToolTip("item chg");
		m_lastClickPoint = pointF;
	}
    return false;
}

bool CPolyLineDrawTool::OnInsertDrawingDoubleClicked(const QPointF& pointF)
{
	if (!m_item)
		return false;
    QPolygonF polygonF = m_item->polygon();
    polygonF.removeLast();    
	if (polygonF.size() < 2){
		return false;
	}
	m_item->setPolygon(polygonF);
    if(g_IsPointFEqual(polygonF[polygonF.size()-2], polygonF.last()))
    {
        polygonF.pop_back();
        m_item->setPolygon(polygonF);
        m_item->setToolTip("item chg");
    }
	return true;
}

void CPolyLineDrawTool::EditDrawing( const QPointF& pointF)
{
    Q_ASSERT(m_activePointId>=0);

    QPolygonF polygonF = m_item->polygon();
	if (polygonF.size()>1)
		polygonF[m_activePointId] = LockPointTransform(m_item->mapFromScene(pointF), polygonF[m_activePointId ? m_activePointId - 1 : m_activePointId + 1]);
    m_item->setPolygon(polygonF);
    m_item->setToolTip("item chg");
}

void CPolyLineDrawTool::AddPoint( const QPointF& pointF )
{
    QPolygonF poly = m_item->polygon();
    poly<<m_item->mapFromScene(pointF);
    m_item->setPolygon(poly);
    m_item->setToolTip("item chg");
    IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<QGraphicsPolygonItem, QPolygonF>
                               (m_item, m_lastPolygonF,
                                &QGraphicsPolygonItem::setPolygon,
                                m_item->polygon(),
                                "Add a polyline point"));
    m_lastPolygonF = poly;
}

void CPolyLineDrawTool::DelPoint()
{
    QPolygonF poly = m_item->polygon();
    poly.remove(m_activePointId);
    m_item->setPolygon(poly);
    m_item->setToolTip("item chg");
    IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<QGraphicsPolygonItem, QPolygonF>
                               (m_item, m_lastPolygonF,
                                &QGraphicsPolygonItem::setPolygon,
                                m_item->polygon(),
                                "Del a polyline point"));
    m_lastPolygonF = poly;
}

void CPolyLineDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    m_item = ItemCreator::CreateSpecifyItem<CPolylineItem>();
    m_item->setPolygon(QPolygonF(QVector<QPointF>(2, pos)));
    m_lastItem = m_item;
    m_item->setToolTip("item chg");
}



void CLinkDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    m_linkItem = ItemCreator::CreateSpecifyItem<CLinkLineItem>();
    m_linkItem->setPolygon(QPolygonF(QVector<QPointF>(2, pos)));
    m_lastItem = m_item = m_linkItem;
    scene->addItem(m_lastItem);
    QGraphicsItem* hintedItem=m_linkItem->TestHintItem(0);
    m_activePointId=0;
	if (hintedItem && ((CGraphScene*)scene)->LinkMode() == Hmi::Normal) TestHintOtherLinkItem(false);

}

void CLinkDrawTool::SetItem(QGraphicsItem* item)
{
    CPolyLineDrawTool::SetItem(item);
    m_linkItem = dynamic_cast<CLinkLineItem*>(m_item);
    Q_ASSERT(m_linkItem);
    m_intersectLinkItem = NULL;
    m_lastPolygonF = m_linkItem->polygon();
    m_oldHeadPin = m_linkItem->HeadPinItem();
    m_oldTailPin = m_linkItem->TailPinItem();
}

void CLinkDrawTool::InsertDrawing( const QPointF& pointF)
{
    static bool once = false;
    CPolyLineDrawTool::InsertDrawing(pointF);
	QGraphicsItem* hintedItem = m_linkItem->TestHintItem(m_linkItem->polygon().size() - 1);
	//m_activePointId = m_linkItem->polygon().size() - 1;
	//if (hintedItem && ((CGraphScene*)m_linkItem->scene())->LinkMode() == Hmi::Normal) TestHintOtherLinkItem(false);
}

static QPointF g_CalIntersectPoint(const QPolygonF& lhsPoly, const QLineF& rhsLine)
{
    const QLineF lhsLine(lhsPoly[lhsPoly.size()-2], lhsPoly.last());
    QPointF inter;
    lhsLine.intersect(rhsLine, &inter);
    return inter;
}

bool CLinkDrawTool::OnInsertDrawingClicked( const QPointF& pointF )
{
    if(!m_linkItem->GetHintItemArray()[CLinkLineItem::Tail])
        return CPolyLineDrawTool::OnInsertDrawingClicked(pointF);
    else
        return true;
#if 0
    {
        if(hintItem->type() == Hmi::Link)
        {
            CLinkLineItem* hintLinkItem = dynamic_cast<CLinkLineItem*>(hintItem);
            QPolygonF section1, section2;
            const QPointF intersectP = hintLinkItem->Split(m_linkItem, m_activePointId, section1, section2);
            if(section2.size()<2)
                return false;

            PushUndoCommand(new LinkLineHintLinkLineItemCommand(m_linkItem, hintLinkItem, intersectP, section1, section2));
        }
        else if(g_isPinItem(hintItem->type()))
        {

            AdjustLinkLine(m_linkItem, false, hintItem);
            PushUndoCommand(new EditLinkLineItemCommand(m_linkItem, LinkUndoValue(m_lastPolygonF, m_oldHeadPin, m_oldTailPin)));
        }
        return true;
    }
    else
    return CPolyLineDrawTool::OnInsertDrawingClicked(pointF);
#endif
}

bool CLinkDrawTool::OnInsertDrawingDoubleClicked(const QPointF& pointF)
{
    return CPolyLineDrawTool::OnInsertDrawingDoubleClicked(pointF);
}

void CLinkDrawTool::EditDrawing( const QPointF& pointF)
{
    CPolyLineDrawTool::EditDrawing(pointF);
    m_linkItem->TestHintItem(m_activePointId);
}

void CLinkDrawTool::AdjustLinkLine(CLinkLineItem* linkItem, bool isHead, QGraphicsItem* hintItem)
{
    if(!hintItem)
        return;
    QPolygonF poly = linkItem->polygon();
    if(hintItem->type() == Hmi::Pin)
    {
        if(isHead)
            poly.first() = linkItem->mapFromScene(hintItem->scenePos());
        else
            poly.last() = linkItem->mapFromScene(hintItem->scenePos());
    }
    else if(hintItem->type() == Hmi::Bus)
    {
        QPointF p;
        CBusItem* busItem = dynamic_cast<CBusItem*>(hintItem);
        Q_ASSERT(busItem);
		if (poly.size() < 2) 
			return;
        if(isHead)
        {
            QLineF(poly[0], poly[1]).intersect(busItem->itemTransform(linkItem).map(busItem->line()), &p);
            poly.first() = p;
        }
        else
        {
            QLineF(poly[poly.size()-2], poly.last()).intersect(busItem->itemTransform(linkItem).map(busItem->line()), &p);
            poly.last() = p;
        }
    }
    linkItem->setPolygon(poly);
}

void CLinkDrawTool::EditFinish()
{
    if(m_activePointId==0 || m_activePointId==m_linkItem->polygon().size()-1)
    {
        QGraphicsItem* hintItem = m_linkItem->GetHintItemArray()[!!m_activePointId];
        if(hintItem)
        {
            if(hintItem->type() == Hmi::Link)
            {
				if (((CGraphScene*)m_linkItem->scene())->LinkMode() == Hmi::Normal)
                   TestHintOtherLinkItem(true);
                return;
            }
            else if(g_isPinItem(hintItem->type()))
                AdjustLinkLine(m_linkItem, m_activePointId==0, hintItem);
		}
		else{
			if (m_activePointId == 0 && m_linkItem->HeadPinItem())
				AdjustLinkLine(m_linkItem, true, m_linkItem->HeadPinItem());
			else if (m_activePointId != 0 && m_linkItem->TailPinItem())
				AdjustLinkLine(m_linkItem, false, m_linkItem->TailPinItem());
		}
    }


    PushUndoCommand(new EditLinkLineItemCommand(m_linkItem, LinkUndoValue(m_lastPolygonF, m_oldHeadPin, m_oldTailPin)));

    m_lastPolygonF = m_linkItem->polygon();
    m_oldHeadPin = m_linkItem->HeadPinItem();
    m_oldTailPin = m_linkItem->TailPinItem();
}

bool CLinkDrawTool::TestHintOtherLinkItem(bool isEdit)
{
    if(m_activePointId!=0 && m_activePointId!=m_linkItem->polygon().size()-1)
        return false;
    QGraphicsItem* hintItem = m_linkItem->GetHintItemArray()[!!m_activePointId];

    QPointF pos1=m_linkItem->polygon().at(m_activePointId);
    if(hintItem && hintItem->type() == Hmi::Link)
    {
        CLinkLineItem* hintLinkItem = dynamic_cast<CLinkLineItem*>(hintItem);
        QPointF p1=hintLinkItem->polygon().first();
        QPointF p2=hintLinkItem->polygon().last();
        QRectF rc1=QRectF(p1.x()-CORNER_RECTPAD,p1.y()-CORNER_RECTPAD,CORNER_RECTPAD*2,CORNER_RECTPAD*2);
        QRectF rc2=QRectF(p2.x()-CORNER_RECTPAD,p2.y()-CORNER_RECTPAD,CORNER_RECTPAD*2,CORNER_RECTPAD*2);
        if(rc1.contains(pos1)||rc2.contains(pos1))
        {
            bool isHintItemHead=rc1.contains(pos1) ? true:false;
            bool isHead = (m_activePointId==0) ? true:false;
            PushUndoCommand(new LinkLineHintLinkLineItemJoinCommand(m_linkItem,isHead,hintLinkItem, isHintItemHead ));
        }
        else
        {
            QPolygonF section1, section2;
            const QPointF intersectP = hintLinkItem->Split(m_linkItem, m_activePointId, section1, section2);
            if(section2.size()<2)
                return false ;
            if(isEdit)
            {
                PushUndoCommand(new LinkLineHintLinkLineItemCommand(m_linkItem, hintLinkItem, m_lastPolygonF, m_activePointId, intersectP, section1, section2));
            }
            else
            {
                QUndoCommand* cmd = new QUndoCommand;
                QUndoCommand* cmd1 = new AddLinkLineItemCommand(m_linkItem, cmd);
                QUndoCommand* cmd2 = new LinkLineHintLinkLineItemCommand(m_linkItem, hintLinkItem, intersectP, section1, section2, cmd);
                cmd->setText("add a linkline and hint another linkline~~");
                PushUndoCommand(cmd);
            }
        }
    }
    return true;
}

void CLinkDrawTool::InsertFinish()
{
	if (m_linkItem->HeadPinItem() == NULL || m_linkItem->TailPinItem() == NULL)
		m_linkItem->UpdateLoadedConnection();
	
	AdjustLinkLine(m_linkItem, true, m_linkItem->GetHintItemArray()[CLinkLineItem::Head]);
    QGraphicsItem* hintItem = m_linkItem->GetHintItemArray()[CLinkLineItem::Tail];
    if(!hintItem)//just pin
    {
		hintItem = m_linkItem->TestHintItem(m_linkItem->polygon().size() - 1);
		if (!hintItem){//pin or link
			QUndoStack * stack = NULL;
			if (m_linkItem->scene())
				stack = ((CDesignerScene*)m_linkItem->scene())->GetUndoStack();
			PushUndoCommand(new AddLinkLineItemCommand(m_linkItem), stack);
		    return;
		}
    }
    if(g_isPinItem(hintItem->type()))
    {

        AdjustLinkLine(m_linkItem, false, hintItem);
		QUndoStack * stack = NULL;
		if (m_linkItem->scene())
			stack = ((CDesignerScene*)m_linkItem->scene())->GetUndoStack();
		PushUndoCommand(new AddLinkLineItemCommand(m_linkItem), stack);
    }
    else if(hintItem->type() == Hmi::Link)
    {
        m_activePointId=m_linkItem->polygon().size()-1;
		if (((CGraphScene*)m_linkItem->scene())->LinkMode() == Hmi::Normal)
            TestHintOtherLinkItem(false);
    }
	m_linkItem->SetInitPos(false);
}

bool CLinkDrawTool::MouseHint(const QPointF& pos)
{
    m_linkItem->TestHintItem(0);
	m_linkItem->TestHintItem(m_linkItem->polygon().size() - 1);
    return CPolygonDrawTool::MouseHint( pos);
}

bool CLinkDrawTool::MouseRelease(const QPointF& pos)
{

    MouseHint( pos);
    int oldpointId=m_activePointId;
    m_activePointId=0 ;
    EditFinish();
    m_activePointId=m_linkItem->polygon().size()-1;
    EditFinish();
    m_activePointId=oldpointId;
    return true;
}



void CTextDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    m_item = ItemCreator::CreateSpecifyItem<CTextItem>();
    SetPos(pos);
	QPen pen = m_item->pen();
	pen.setStyle(Qt::NoPen);
	m_item->setPen(pen);
    m_lastItem = m_item;
}

void CGraphicsTextDrawTool::CreateNew(QGraphicsScene* scene, const QString& createTypeName, const QPointF& pos)
{
	m_item = ItemCreator::CreateSpecifyItem<CGraphicsTextItem>();
	SetPos(pos);
	m_lastItem = m_item;
}



void CLineDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos )
{
    m_item = ItemCreator::CreateSpecifyItem<CLineItem>();
    m_item->setLine(QLineF(pos, pos));
    m_lastItem = m_item;
}

void CLineDrawTool::EditDrawing( const QPointF& pointF)
{
    Q_ASSERT(m_resizeTag != P0);
    if(P1 == m_resizeTag)
        m_item->setLine(QLineF(LockPointTransform(m_item->mapFromScene(pointF), m_item->line().p2()), m_item->line().p2()) );
    else if(P2 == m_resizeTag)
        m_item->setLine(QLineF(m_item->line().p1(), LockPointTransform(m_item->mapFromScene(pointF), m_item->line().p1())) );
}

void CLineDrawTool::InsertDrawing( const QPointF& pointF)
{
    m_item->setSelected(false);
    m_item->setLine(QLineF(m_item->line().p1(), LockPointTransform(pointF, m_item->line().p1())));
}

void CLineDrawTool::EditFinish()
{
    IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<QGraphicsLineItem, QLineF>
                               (m_item, m_lastLineF,
                                &QGraphicsLineItem::setLine,
                                m_item->line(),
                                "Edit a line"));
    m_lastLineF = m_item->line();
}

void CBusDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos )
{
    m_item = ItemCreator::CreateSpecifyItem<CBusItem>();
    m_item->setLine(QLineF(pos, pos));
    m_lastItem = m_item;
}

void CBusDrawTool::InsertDrawing( const QPointF& pointF)
{
    m_item->setLine(QLineF(m_item->line().p1(), LockPointTransform(pointF, m_item->line().p1())));
}

void CBusDrawTool::EditDrawing( const QPointF& pointF)
{
    Q_ASSERT(m_resizeTag != P0);
    if(P1 == m_resizeTag)
        m_item->setLine(QLineF(LockPointTransform(m_item->mapFromScene(pointF), m_item->line().p2()), m_item->line().p2()) );
    else if(P2 == m_resizeTag)
        m_item->setLine(QLineF(m_item->line().p1(), LockPointTransform(m_item->mapFromScene(pointF), m_item->line().p1())) );
}

void CBusDrawTool::EditFinish()
{
    IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<CBusItem, QLineF>
                               (m_item, m_lastLineF,
                                &CBusItem::setLine,
                                m_item->line(),
                                "Edit a bus"));
    m_lastLineF = m_item->line();
}



void CRectDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos )
{
    m_item = ItemCreator::CreateSpecifyItem<CRectItem>();
    ApplyRect(QRectF(pos,pos));
    m_lastItem = m_item;
}

QRectF CRectDrawTool::GetRect()
{
    return m_item->rect();
}

void CRectDrawTool::ApplyRect( const QRectF& rectF )
{
    m_item->setRect(rectF);
}

void CRectDrawTool::EditFinish()
{

    IDrawTool::PushUndoCommand( new SimpleShapeEditForItemCommand<QGraphicsRectItem, QRectF>
                                (m_item, m_lastRectF,
                                 &QGraphicsRectItem::setRect,
                                 m_item->rect(),
                                 "edit a rect item's shape "));
    m_lastRectF = m_item->rect();
}

void CEllipseDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos )
{
    m_item = ItemCreator::CreateSpecifyItem<CEllipseItem>();
    m_item->setRect(QRectF(pos,pos));
    m_lastItem = m_item;
}

QRectF CEllipseDrawTool::GetRect()
{
    return m_item->rect();
}

void CEllipseDrawTool::ApplyRect( const QRectF& rect )
{
    m_item->setRect(rect);
}

void CEllipseDrawTool::EditFinish()
{
    IDrawTool::PushUndoCommand( new SimpleShapeEditForItemCommand<QGraphicsEllipseItem, QRectF>
                                (m_item, m_lastRectF,
                                 &QGraphicsEllipseItem::setRect,
                                 m_item->rect(),
                                 "edit a ecllipse item's shape "));
    m_lastRectF = GetRect();
}

void CWidgetDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos )
{
    Q_ASSERT(createTypeName.startsWith("ui-"));
    m_item = dynamic_cast<QGraphicsProxyWidget*>(ItemCreator::CreateItem(createTypeName));
    SetPos(pos);
    m_lastItem = m_item;
}

QRectF CWidgetDrawTool::GetRect()
{

    return m_item->rect();
}

void CWidgetDrawTool::ApplyRect( const QRectF& rect )
{
#if 1
    QPointF deltaMove = rect.topLeft()-m_item->rect().topLeft();
    if(rect.size().height() <= m_item->minimumHeight())
        deltaMove.ry() = 0;
    if(rect.size().width() <= m_item->minimumWidth())
        deltaMove.rx() = 0;
    QRectF newGeometry(m_item->pos()+deltaMove, rect.size());
    m_item->setGeometry(newGeometry);
#else
    m_item->moveBy(deltaMove.x(), deltaMove.y());

    QRectF oldRect = m_item->rect();
    m_item->moveBy(deltaMove.x(), deltaMove.y());

    return;
    QRectF oldGeometry = m_item->geometry();
    QRectF newGeometry;
    QPointF lastBottomRight = m_item->mapToScene(oldGeometry.bottomRight());

    QPointF newBottomRight = m_item->mapToScene(newGeometry.bottomRight());
#endif
}

void CWidgetDrawTool::EditFinish()
{
    QRectF curRect = m_item->rect();
    QPointF deltaMove = m_lastRectF.topLeft()-curRect.topLeft();
    m_lastRectF.moveTopLeft(m_item->pos()+deltaMove);
    curRect.moveTopLeft(m_item->pos()-deltaMove);
    IDrawTool::PushUndoCommand( new SimpleShapeEditForItemCommand<QGraphicsProxyWidget, QRectF>
                                (m_item, m_lastRectF,
                                 &QGraphicsProxyWidget::setGeometry,
                                 curRect,
                                 QString("edit a %1's shape ").arg(ItemFactory::ItemTypeName(g_dataPtr(m_item)->Type()))));
    m_lastRectF = GetRect();
}



void CGroupDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    m_lastItem = ItemCreator::CreateItem(createTypeName);
    Q_ASSERT(NULL != m_lastItem);
    m_item = dynamic_cast<CGroupItem*>(m_lastItem);
    Q_ASSERT(Hmi::Icon == m_item->type());


    //this->SetPos(pos-m_lastItem->boundingRect().topLeft());
    SetPos(pos);



}

void CIconDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    m_lastItem = ItemCreator::CreateIconFromIconMap(createTypeName,0, scene);
    Q_ASSERT(NULL != m_lastItem);
    if (!m_lastItem)
        return;
    m_item = dynamic_cast<CIconItem*>(m_lastItem);


	this->SetPos(pos - m_lastItem->mapToScene(m_lastItem->boundingRect().topLeft()));
    //if the group only has one child,then dismiss this group
	CIconData *pdata = (CIconData*)g_dataPtr(m_item);
    if(!pdata->IsPowerIcon() && pdata->GetIfRef()==false && m_item->childItems().size()==1)
    {
        QGraphicsItem *item=m_item->childItems().first();
        m_item->removeFromGroup(item);
        m_lastItem=item;
        ItemCreator::GlobalSet(m_lastItem,false);
        //m_pScene->removeItem(m_item);
        return;
    }
	if (((CGraphScene*)scene)->LinkMode() == Hmi::Normal)
        TestHintOtherLinkItem( pos);
}

bool CIconDrawTool::TestHintOtherLinkItem(const QPointF& pos)
{
	if (m_item->scene()==NULL)
		return false;

    const QRectF r = QRectF(pos-QPointF(1, 1), QSize(4, 4));
	QList<QGraphicsItem*> collidList = m_item->scene()->items(r, Qt::IntersectsItemShape, Qt::AscendingOrder);
    bool isHint=false;
    QGraphicsItem* hintItem=NULL;
    foreach(QGraphicsItem* item, collidList)
    {
        if(item->type()==Hmi::Link)
        {
            hintItem = item;
            break;
        }
    }
    if(!hintItem )
        return false;
    QVector<QPointF> pins;
    foreach(QGraphicsItem* item, m_item->childItems())
    {
        if(item->type()==Hmi::Pin)
        {
			if (((CPinItem*)item)->LinkLineItems().size() > 0)
				continue;
            pins<< item->pos();
        }
    }
    if(pins.size()!=2) return false;
    QPointF pinCenter=QLineF(pins[0],pins[1]).pointAt(0.5);
    qreal pinAngle=QLineF(pins[0],pins[1]).angle();

    QPointF dp=(m_item->boundingRect().center()-pinCenter);
    m_item->moveBy(dp.x() ,dp.y() );
    int blockLength=QLineF(pins[0],pins[1]).length();

    CLinkLineItem* hintLinkItem = dynamic_cast<CLinkLineItem*>(hintItem);
    QPointF p1=hintLinkItem->polygon().first();
    QPointF p2=hintLinkItem->polygon().last();
    QRectF rc1=QRectF(p1.x()-CORNER_RECTPAD,p1.y()-CORNER_RECTPAD,CORNER_RECTPAD*2,CORNER_RECTPAD*2);
    QRectF rc2=QRectF(p2.x()-CORNER_RECTPAD,p2.y()-CORNER_RECTPAD,CORNER_RECTPAD*2,CORNER_RECTPAD*2);

    QPolygonF section1, section2;
    QPointF pos1=pos;
    const QPointF intersectP = hintLinkItem->Split(pos1, blockLength, section1, section2);
    if(section2.size()<2)
        return false ;

    qreal angle=pinAngle-QLineF(section1.last(),section2.first()).angle()+180;
    m_item->setTransformOriginPoint(pinCenter);
    m_item->setRotation(angle);

    QUndoCommand* cmd = new QUndoCommand;

    QUndoCommand* cmd2 = new IconItemHintLinkLineItemCommand(m_item, hintLinkItem, intersectP, section1, section2, cmd);
    cmd->setText("add a linkline and hint another linkline~~");
    PushUndoCommand(cmd);

    return true;
}

bool CIconDrawTool::MouseHint(const QPointF& pointF)
{
	return IScaleRectShapeDrawTool<CIconItem>::MouseHint(pointF);
}

bool CIconDrawTool::MouseRelease(const QPointF& pos)
{
	CGraphScene* pscene = (CGraphScene*)(m_item->scene());
	if (pscene && pscene->LinkMode() == Hmi::Normal)
	    return TestHintOtherLinkItem(pos);
	return true;
}

void CSvgDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos )
{
    m_item = ItemCreator::CreateSpecifyItem<CSvgItem>();
    SetPos(pos);
    m_lastItem = m_item;
	if (scene)
	{
		CSvgData* pdata = (CSvgData*)g_dataPtr(m_item);
		QString fileName = QFileDialog::getOpenFileName(scene->views().first(), QObject::tr("Open File"), UnqFunc()->GetDir(CGFunc::PATH_TYPE_DATA), QObject::tr("files (*.svg)"));
		if (!fileName.isEmpty()) m_item->Load(fileName);
	}
}
#ifdef CHARTS
void CChartDrawTool::CreateNew(QGraphicsScene* scene, const QString& createTypeName, const QPointF& pos)
{
    m_item = ItemCreator::CreateSpecifyItem<CGChartItem>();
	SetPos(pos);
   // ApplyRect(QRectF(pos, pos));
    m_lastItem = m_item;
}

QRectF CChartDrawTool::GetRect()
{
	QRectF rc = ((CGChartItem*)m_item)->rect();
	//rc = m_item->mapToScene(rc).boundingRect();
    return rc;
}

void CChartDrawTool::ApplyRect(const QRectF& rectF)
{
    //SetPos(m_item->mapToScene(rectF.topLeft()));
	QPointF deltaMove = rectF.topLeft() - m_item->rect().topLeft();
	if (rectF.size().height() <= m_item->minimumHeight())
		deltaMove.ry() = 0;
	if (rectF.size().width() <= m_item->minimumWidth())
		deltaMove.rx() = 0;
	QRectF newGeometry(m_item->pos() + deltaMove, rectF.size());
	//m_item->setGeometry(newGeometry);

    ((CGChartItem*)m_item)->setGeometry(newGeometry );
}

void CChartDrawTool::EditFinish()
{
	QRectF curRect = m_item->rect();
	QPointF deltaMove = m_lastRectF.topLeft() - curRect.topLeft();
	m_lastRectF.moveTopLeft(m_item->pos() + deltaMove);
	curRect.moveTopLeft(m_item->pos() - deltaMove);
	IDrawTool::PushUndoCommand(new SimpleShapeEditForItemCommand<QGraphicsWidget, QRectF>
		(m_item, m_lastRectF,
		&QGraphicsWidget::setGeometry,
		curRect,
		QString("edit a %1's shape ").arg(ItemFactory::ItemTypeName(g_dataPtr(m_item)->Type()))));
	m_lastRectF = GetRect();
 
}
#endif
void CPixmapDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos )
{
    m_item = ItemCreator::CreateSpecifyItem<CPixmapItem>();
    SetPos(pos);
    m_lastItem = m_item;

    if(scene)
    {
        UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP);
        CPixmapData* pdata = (CPixmapData*)g_dataPtr(m_item);
        QString fileName = QFileDialog::getOpenFileName(scene->views().first(), QObject::tr("Open File"),UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP),QObject::tr("Images (*.png *.gif *.jpg *.*)"));
        if(!fileName.isEmpty()) pdata->Load(fileName);
    }
}

void CAbstractPathDrawTool::SetItem( QGraphicsItem* item )
{
    if(IsNewItem(item))
        Reset();

    m_item = dynamic_cast<CAbstractPathItem*>(item);
    Q_ASSERT(m_item);
    m_lastPointVec = m_item->GetInflexionVec();
}

void CAbstractPathDrawTool::InsertDrawing( const QPointF& pointF )
{
    m_item->SetTailInflexion(pointF);
}

bool CAbstractPathDrawTool::MouseHint(const QPointF& pointF)
{
    if (((CAbstractPathData*)g_dataPtr(m_item))->GetSymbolName().isEmpty())
    {

        QPointF tmp;
        const int size = m_item->GetInflexionSize();
        for (int i = 0; i < size; ++i)
        {
            tmp = m_item->GetInflexion(i);
            if (QRectF(tmp - RESIZE_POINTF, tmp + RESIZE_POINTF).contains(pointF))
            {
                m_activeInflexionId = i;
                m_activeHintPointF = tmp;
                return true;
            }
        }
    }
    else
    {
        const QRectF boundRectF = m_item->boundingRect();
        const QPointF mappedPointF = m_item->mapFromScene(pointF);
        QVector<QPointF> resizePointVec(NoneResize);
        resizePointVec[TopLeft] = boundRectF.topLeft();
        resizePointVec[TopRight] = boundRectF.topRight() + QPointF(-ACTIVE_RECTPAD * 2, 0);
        resizePointVec[BottomLeft] = boundRectF.bottomLeft() + QPointF(0, -ACTIVE_RECTPAD * 2);
        resizePointVec[BottomRight] = boundRectF.bottomRight() + QPointF(-ACTIVE_RECTPAD * 2, -ACTIVE_RECTPAD * 2);
		resizePointVec[Top] = QPointF(boundRectF.left() + boundRectF.width() / 2 - ACTIVE_RECTPAD, boundRectF.top());
		resizePointVec[Bottom] = QPointF(boundRectF.left() + boundRectF.width() / 2 - ACTIVE_RECTPAD, boundRectF.bottom() - ACTIVE_RECTPAD * 2);
		resizePointVec[Left] = QPointF(boundRectF.left(), boundRectF.top() + boundRectF.height() / 2 - ACTIVE_RECTPAD);
		resizePointVec[Right] = QPointF(boundRectF.right() - ACTIVE_RECTPAD * 2, boundRectF.top() + boundRectF.height() / 2 - ACTIVE_RECTPAD);

        m_item->ApplyInflexionVec(resizePointVec);
        for (int resizeTag = TopLeft; resizeTag<NoneResize; ++resizeTag)
        {
            if (QRectF(resizePointVec[resizeTag], QSize(ACTIVE_RECTPAD * 2, ACTIVE_RECTPAD * 2)).contains(mappedPointF))
            {
                m_resizeTag = resizeTag;
                m_activeInflexionId = resizeTag;
                m_activeHintPointF = m_item->mapToScene(resizePointVec[resizeTag]);
                return true;
            }
        }
        m_resizeTag = NoneResize;
    }
    return false;
}

void CAbstractPathDrawTool::EditDrawing( const QPointF& pointF )
{
    if (((CAbstractPathData*)g_dataPtr(m_item))->GetSymbolName().isEmpty())
        m_item->SetInflexion(m_activeInflexionId, pointF);
    else
    {
        QRectF rectF = m_item->sceneBoundingRect();
        qreal factor=1;
		if (TopLeft == m_resizeTag)
            factor = (rectF.bottomRight() - pointF).manhattanLength() / (rectF.bottomRight() - rectF.topLeft()).manhattanLength();
		else if (TopRight == m_resizeTag)
            factor = (rectF.bottomLeft() - pointF).manhattanLength() / (rectF.bottomLeft() - rectF.topRight()).manhattanLength();
        else if (BottomLeft == m_resizeTag)
            factor = (rectF.topRight() - pointF).manhattanLength() / (rectF.topRight() - rectF.bottomLeft()).manhattanLength();
		else if (BottomRight == m_resizeTag)
            factor = (rectF.topLeft() - pointF).manhattanLength() / (rectF.topLeft() - rectF.bottomRight()).manhattanLength();
		g_dataPtr(m_item)->SetTransformOrigin(0);
        g_dataPtr(m_item)->SetScale( m_item->scale()*factor );
    }
}

void CAbstractPathDrawTool::EditFinish()
{
    IDrawTool::PushUndoCommand( new SimpleShapeEditForItemCommand<CAbstractPathItem, QVector<QPointF> >
                                (m_item, m_lastPointVec,
                                 &CAbstractPathItem::ApplyInflexionVec,
                                 m_item->GetInflexionVec(),
                                 "Edit a abstract path "));
    m_lastPointVec = m_item->GetInflexionVec();
    m_item->setSelected(true);
}

void CAbstractPathDrawTool::Revoke()
{
    m_item->ApplyInflexionVec(m_lastPointVec);
}

void CAbstractPathDrawTool::Reset()
{
    m_item = 0;
    m_lastPointVec.clear();
    m_activeInflexionId = -1;
    IDrawTool::Reset();
}

bool CAbstractPathDrawTool::OnInsertDrawingClicked( const QPointF& pointF )
{
	if ( m_item) m_item->AppendInflexion(pointF);
    return false;
}

bool CAbstractPathDrawTool::OnInsertDrawingDoubleClicked(const QPointF&)
{
	if (!m_item)
		return false;
    QVector<QPointF> inflexionVec = m_item->GetInflexionVec();
    if(g_IsPointFEqual(inflexionVec[inflexionVec.size()-2], inflexionVec.last()))
    {
        inflexionVec.pop_back();
        m_item->ApplyInflexionVec(inflexionVec);
    }
	return true;
}

void CAbstractPathDrawTool::DelPoint()
{
    QVector<QPointF> vec = m_item->GetInflexionVec();
    vec.remove(m_activeInflexionId);
    m_item->ApplyInflexionVec(vec);
    IDrawTool::PushUndoCommand( new SimpleShapeEditForItemCommand<CAbstractPathItem, QVector<QPointF> >
                                (m_item, m_lastPointVec,
                                 &CAbstractPathItem::ApplyInflexionVec,
                                 m_item->GetInflexionVec(),
                                 "Del a abstract path point"));
    m_lastPointVec = vec;
}

void CAbstractPathDrawTool::AddPoint(const QPointF& pointF)
{
    QVector<QPointF> vec = m_item->GetInflexionVec();
    vec<<m_item->mapFromScene(pointF);
    m_item->ApplyInflexionVec(vec);
    IDrawTool::PushUndoCommand( new SimpleShapeEditForItemCommand<CAbstractPathItem, QVector<QPointF> >
                                (m_item, m_lastPointVec,
                                 &CAbstractPathItem::ApplyInflexionVec,
                                 m_item->GetInflexionVec(),
                                 "Add a abstract path point"));
    m_lastPointVec = vec;

}

void CAbstractPathDrawTool::CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos)
{
    if(createTypeName == "closepath")
    {
        m_item = ItemCreator::CreateSpecifyItem<CClosePathItem>();
        m_item->ApplyInflexionVec(QVector<QPointF>(2, pos));
    }
    else if(createTypeName == "path")
    {
        m_item = ItemCreator::CreateSpecifyItem<CPathItem>();
        m_item->ApplyInflexionVec(QVector<QPointF>(2, pos));
    }
    else
    {
        Q_ASSERT_X(false, "CAbstractPathDrawTool::CreateItem", "createTypeName is invalid!!");
    }
    m_lastItem = m_item;

}
