

#ifndef IDRAWTOOL_H
#define IDRAWTOOL_H 

#include <QTransform>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include "GraphItem.h"
#include "GroupItem.h"
#include "BaseData.h"
#include "Commands.h"
#ifdef CHARTS
#include "GChartItem.h"
#endif
class QGraphicsLineItem;
class QGraphicsPolygonItem;
class QPainter;
class QUndoStack;
class QUndoCommand;
class QStyleOptionGraphicsItem;
class QGraphicsProxyWidget;
class QGraphicsSvgItem;
class CLinkLineItem;
class CPinItem;
class CBusItem;
class CAbstractPathItem;
class QGraphicsScene;
class CPixmapItem;
#ifdef CHARTS
class CGChartItem;
#endif
extern const QPointF RESIZE_POINTF;

class IDrawTool
{
public:
    static void SwitchHvLockFlag() {s_lockFlag=!s_lockFlag;};
    static void SwitchCatchFlag() {s_catchFlag=!s_catchFlag;};
    static void SetGridWidth(int width){s_gridWidth = width;};
    static bool IsCatch() {return s_catchFlag;};
    static int GetGridWidth() {return s_gridWidth;};
    static void InitThis(QHash<int, IDrawTool*>& toolHash, QUndoStack* stack);
    static void SetUndoStack(QUndoStack* stack) {s_undoStack = stack;};
protected:
    inline static void PushUndoCommand(QUndoCommand* cmd,QUndoStack* stack=NULL);
    static QPointF LockPointTransform(const QPointF& scenePointF, const QPointF& referPointF);
private:
    static QUndoStack* s_undoStack;
    static bool s_lockFlag;
    static bool s_catchFlag;
    static int s_gridWidth;
public:
    enum EditClickMode {SingleClickMode, DoubleClickMode, MultiClickMode};
    IDrawTool();
    friend class CDrawManager;
    virtual ~IDrawTool() {};
    QGraphicsItem* CreateItem(QGraphicsScene* scene, const QString& createTypeName, const QPointF& pos);
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos) = 0;
    virtual void SetItem(QGraphicsItem* item) = 0;
    virtual void InsertDrawing(const QPointF& ) =0;
    virtual bool OnInsertDrawingClicked(const QPointF&) {return true;};
	virtual bool OnInsertDrawingDoubleClicked(const QPointF&) { return true; };
    virtual void InsertFinish() ;
    virtual bool MouseHint(const QPointF&) =0;
    virtual bool MouseRelease(const QPointF&) {return true;};
    virtual void EditDrawing(const QPointF&) = 0;
    virtual void EditFinish() = 0;
    virtual void Revoke() = 0;
    virtual void Reset() ;
    virtual EditClickMode GetClickEditMode() const = 0;
    void RotateFinish();
    void ApplyRotation(const QPointF& pointF) ;
    QPointF GetActiveScenePointF() const {return m_activeHintPointF;};
    bool IsLastItem(QGraphicsItem* item) const {return m_lastItem==item;};
protected:
    bool IsNewItem(QGraphicsItem* item);
    QPointF m_activeHintPointF;
    qreal m_lastRotateAngle;
    QGraphicsItem* m_lastItem;
};

template<typename LineShapeItem>
class CLineShapeDrawTool : public IDrawTool
{
public:
    virtual EditClickMode GetClickEditMode() const {return DoubleClickMode;};
    virtual void SetItem(QGraphicsItem* item);
    virtual bool MouseHint(const QPointF&) ;
    virtual void Reset();
    virtual void Revoke();
protected:
    enum ResizeTag {P0=-1, P1, P2};
    LineShapeItem* m_item;
    QLineF m_lastLineF;
    int m_resizeTag;
};

template<typename LineShapeItem>
void CLineShapeDrawTool<LineShapeItem>::SetItem( QGraphicsItem* item )
{
    if(IsNewItem(item))
    {
        Reset();
    }
    m_item = static_cast<LineShapeItem*>(item);
    Q_ASSERT(m_item);
}

template<typename LineShapeItem>
void CLineShapeDrawTool<LineShapeItem>::Reset()
{
    m_item = 0;
    m_lastLineF = QLineF();
    m_resizeTag = P0;
    IDrawTool::Reset();
}

template<typename LineShapeItem>
bool CLineShapeDrawTool<LineShapeItem>::MouseHint( const QPointF& pointF)
{
    QPointF tmp;
    tmp = m_item->mapToScene(m_item->line().p1());
    if(QRectF(tmp-RESIZE_POINTF, tmp+RESIZE_POINTF).contains(pointF))
    {
        m_resizeTag = P1;
        m_activeHintPointF = tmp;
        m_lastLineF = m_item->line();
        return true;
    }
    tmp = m_item->mapToScene(m_item->line().p2());

    if(QRectF(tmp-RESIZE_POINTF, tmp+RESIZE_POINTF).contains(pointF))
    {
        m_resizeTag = P2;
        m_activeHintPointF = tmp;
        m_lastLineF = m_item->line();
        return true;
    }
    return false;
}

template<typename LineShapeItem>
void CLineShapeDrawTool<LineShapeItem>::Revoke()
{
    m_item->setLine(m_lastLineF);
}

class CLineDrawTool : public CLineShapeDrawTool<QGraphicsLineItem>
{
public:
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual void InsertDrawing(const QPointF&);
    virtual void EditDrawing(const QPointF&) ;
    virtual void EditFinish();
};

class CBusDrawTool : public CLineShapeDrawTool<CBusItem>
{
public:
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual void InsertDrawing(const QPointF&);
    virtual void EditDrawing(const QPointF&) ;
    virtual void EditFinish();
};

enum ResizeTag { TopLeft, TopRight, BottomLeft, BottomRight, Top, Bottom, Left, Right, NoneResize };
template<typename RectShapeItem>
class IRectShapeDrawTool : public IDrawTool
{
public:
    virtual void SetItem(QGraphicsItem* item);
    virtual void Reset();
    void SetPos(const QPointF& pos);
protected:
    RectShapeItem* m_item;
    int m_resizeTag;
};

template<typename RectShapeItem>
void IRectShapeDrawTool<RectShapeItem>::SetPos( const QPointF& pos )
{
    if(GetClickEditMode() == IDrawTool::SingleClickMode)
        m_item->setPos(pos-QPointF(m_item->boundingRect().width()/2, m_item->boundingRect().height()/2));
    else
        m_item->setPos(pos);

    //qDebug()<<"pos: "<<pos<<"itemPos:"<<m_item->pos();
}

template<typename RectShapeItem>
void IRectShapeDrawTool<RectShapeItem>::SetItem( QGraphicsItem* item )
{
    if(IsNewItem(item))
    {
        Reset();
    }
    m_item = static_cast<RectShapeItem*>(item);
    Q_ASSERT(m_item);
}

template<typename RectShapeItem>
void IRectShapeDrawTool<RectShapeItem>::Reset()
{
    m_item = 0;
    m_resizeTag = NoneResize;
    IDrawTool::Reset();
}

template<typename RectShapeItem>
class IResizeRectShapeDrawTool : public IRectShapeDrawTool<RectShapeItem>
{
public:
    using IRectShapeDrawTool<RectShapeItem>::m_item;
    using IRectShapeDrawTool<RectShapeItem>::m_resizeTag;
    using IRectShapeDrawTool<RectShapeItem>::m_activeHintPointF;
    virtual void SetItem(QGraphicsItem* item)
    {
        IRectShapeDrawTool<RectShapeItem>::SetItem(item);
        m_lastRectF = GetRect();
    };

    virtual void Reset()
    {
        IRectShapeDrawTool<RectShapeItem>::Reset();
        m_lastRectF = QRectF();
    };
    void InsertDrawing(const QPointF& pointF)
    {
        const QPointF tl = GetRect().topLeft();
        if(pointF.x() < tl.x() || pointF.y() < tl.y())
            return;
        QPointF ss = m_item->mapFromScene(pointF);
        //ss=LockPointTransform(ss, tl);
        ApplyRect(QRectF(tl, ss));
    };
    virtual void EditDrawing(const QPointF& pointF)
    {

        Q_ASSERT(m_resizeTag != NoneResize);

        QPointF ss = m_item->mapFromScene(pointF);
        QRectF rectF = GetRect();
		if (TopLeft == m_resizeTag)
		{			
			const QPointF br = GetRect().bottomRight();
			if (ss.x() > br.x() || ss.y() > br.y())
				return;	
            //ss = LockPointTransform(ss, br);
			rectF.setTopLeft(ss);
		}          
		else if (TopRight == m_resizeTag)
		{
			const QPointF bl = GetRect().bottomLeft();
			if (ss.x() < bl.x() || ss.y() > bl.y())
				return;
            //ss = LockPointTransform(ss, bl);
			rectF.setTopRight(ss);
		}
        else if(BottomLeft == m_resizeTag)
		{
			const QPointF tr = GetRect().topRight();
			if (ss.x() > tr.x() || ss.y() < tr.y())
				return;
            //ss = LockPointTransform(ss, tr);
			rectF.setBottomLeft(ss);
		}
		else if (BottomRight == m_resizeTag)
		{
			const QPointF tl = GetRect().topLeft();
			if (ss.x() < tl.x() || ss.y() < tl.y())
				return;
            //ss = LockPointTransform(ss, tl);
			rectF.setBottomRight(ss);
		}
        else if(Top == m_resizeTag)
		{
			const qreal bm = GetRect().bottom();
			if (ss.y() > bm)
				return;
			ss = LockPointTransform(ss, QPointF(GetRect().left() + GetRect().width() / 2, GetRect().bottom()));
			rectF.setTop(ss.y());
		}
		else if (Bottom == m_resizeTag)
		{
			const qreal tp = GetRect().top();
			if (ss.y() < tp)
				return;
			ss = LockPointTransform(ss, QPointF(GetRect().left() + GetRect().width() / 2, GetRect().top()));
			rectF.setBottom(ss.y());
		}
		else if (Left == m_resizeTag)
		{
			const qreal rt = GetRect().right();
			if (ss.x() > rt)
				return;
			ss = LockPointTransform(ss, QPointF(GetRect().right(), GetRect().top() + GetRect().height() / 2));
			rectF.setLeft(ss.x());
		}
		else if (Right == m_resizeTag)
		{
			const qreal lt = GetRect().left();
			if (ss.x() < lt)
				return;
			ss = LockPointTransform(ss, QPointF(GetRect().left(), GetRect().top() + GetRect().height() / 2));
			rectF.setRight(ss.x());
		}

        ApplyRect(rectF);
    };

    virtual bool MouseHint( const QPointF& pointF)
    {
        const QRectF rect = GetRect();
        QPointF tmp;
        QVector<QPointF> resizePointVec(NoneResize);
        resizePointVec[TopLeft] = rect.topLeft();
        resizePointVec[TopRight] = rect.topRight();
        resizePointVec[BottomLeft] = rect.bottomLeft();
        resizePointVec[BottomRight] = rect.bottomRight();
		resizePointVec[Top] = QPointF(rect.left()+rect.width()/2, rect.top());
		resizePointVec[Bottom] = QPointF(rect.left() + rect.width() / 2, rect.bottom());
		resizePointVec[Left] = QPointF(rect.left(),rect.top() + rect.height() / 2);
		resizePointVec[Right] = QPointF(rect.right(), rect.top() + rect.height() / 2);

        for(int resizeTag=TopLeft; resizeTag<NoneResize; ++resizeTag)
        {
            tmp = m_item->mapToScene(resizePointVec[resizeTag]);
            if(QRectF(tmp-RESIZE_POINTF, tmp+RESIZE_POINTF).contains(pointF))
            {
                m_resizeTag = resizeTag;
                m_lastRectF = rect;
                m_activeHintPointF = tmp;
                return true;
            }
        }
        m_resizeTag = NoneResize;
        return false;
    };

    virtual void Revoke() { ApplyRect(m_lastRectF);};

    virtual QRectF GetRect() = 0;
    virtual void ApplyRect(const QRectF& rect) = 0;
protected:
    QRectF m_lastRectF;
};

class CRectDrawTool : public IResizeRectShapeDrawTool<QGraphicsRectItem>
{
public:
    virtual IDrawTool::EditClickMode GetClickEditMode() const {return IDrawTool::DoubleClickMode;};
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual QRectF GetRect();
    virtual void ApplyRect(const QRectF& rect);
    virtual void EditFinish();
};

class CEllipseDrawTool : public IResizeRectShapeDrawTool<QGraphicsEllipseItem>
{
public:
    virtual IDrawTool::EditClickMode GetClickEditMode() const {return IDrawTool::DoubleClickMode;};
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual QRectF GetRect();
    virtual void ApplyRect(const QRectF& rect);
    virtual void EditFinish();
};

class CWidgetDrawTool : public IResizeRectShapeDrawTool<QGraphicsProxyWidget>
{
public:
    virtual IDrawTool::EditClickMode GetClickEditMode() const {return IDrawTool::SingleClickMode;};
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual void InsertDrawing(const QPointF& ) { };
    virtual QRectF GetRect();
    virtual void ApplyRect(const QRectF& rect);
    virtual void EditFinish();
};


template<typename RectShapeItem>
class IScaleRectShapeDrawTool : public IRectShapeDrawTool<RectShapeItem>
{
public:
    using IRectShapeDrawTool<RectShapeItem>::m_item;
    using IRectShapeDrawTool<RectShapeItem>::m_resizeTag;

    using IRectShapeDrawTool<RectShapeItem>::m_activeHintPointF;
    IDrawTool::EditClickMode GetClickEditMode() const {return IDrawTool::SingleClickMode;};
    virtual void SetItem(QGraphicsItem* item)
    {
        IRectShapeDrawTool<RectShapeItem>::SetItem(item);
        m_lastTransform = GetTransform();
    };

    virtual void Reset()
    {
        IRectShapeDrawTool<RectShapeItem>::Reset();
        m_lastTransform = QTransform();

    };
    void InsertDrawing(const QPointF& ) { };
    virtual bool MouseHint( const QPointF& pointF)
    {
        const QRectF boundRectF = m_item->boundingRect();
        const QPointF mappedPointF = m_item->mapFromScene(pointF);
        QVector<QPointF> resizePointVec(NoneResize);
        resizePointVec[TopLeft] = boundRectF.topLeft();
		qreal cornerW = boundRectF.width() > boundRectF.height() ? boundRectF.height() / 20 : boundRectF.width() / 20;
		if (cornerW > ACTIVE_RECTPAD)
			cornerW = ACTIVE_RECTPAD;
		resizePointVec[TopRight] = boundRectF.topRight() + QPointF(-cornerW * 2, 0);
		resizePointVec[BottomLeft] = boundRectF.bottomLeft() + QPointF(0, -cornerW * 2);
		resizePointVec[BottomRight] = boundRectF.bottomRight() + QPointF(-cornerW * 2, -cornerW * 2);
		resizePointVec[Top] = QPointF(boundRectF.left() + boundRectF.width() / 2 - cornerW, boundRectF.top());
		resizePointVec[Bottom] = QPointF(boundRectF.left() + boundRectF.width() / 2 - cornerW, boundRectF.bottom() - cornerW * 2);
		resizePointVec[Left] = QPointF(boundRectF.left(), boundRectF.top() + boundRectF.height() / 2 - cornerW);
		resizePointVec[Right] = QPointF(boundRectF.right() - cornerW * 2, boundRectF.top() + boundRectF.height() / 2 - cornerW);

        for(int resizeTag=TopLeft; resizeTag<NoneResize; ++resizeTag)
        {
			if (QRectF(resizePointVec[resizeTag], QSizeF(cornerW * 2, cornerW * 2)).contains(mappedPointF))
            {
                m_resizeTag = resizeTag;
                m_activeHintPointF = m_item->mapToScene(resizePointVec[resizeTag]);
                m_lastTransform = GetTransform();
                return true;
            }
        }
        m_resizeTag = NoneResize;
        return false;
    };

    virtual void EditDrawing(const QPointF& pointF)
    {
        Q_ASSERT(m_resizeTag != NoneResize);
        qreal m11=0.0, m22=0.0;
        QRectF rectF = m_item->boundingRect();
        QPointF localPointF = m_item->mapFromScene(pointF);
        QPointF lockPoint;
        if(TopLeft == m_resizeTag)
        {
            m11 = (rectF.right()-localPointF.x())/rectF.width();
            m22 = (rectF.bottom()-localPointF.y())/rectF.height();
            lockPoint = rectF.bottomRight();
        }
        else if(TopRight == m_resizeTag)
        {
            m11 = (localPointF.x()-rectF.left())/rectF.width();
            m22 = (rectF.bottom()-localPointF.y())/rectF.height();
            lockPoint = rectF.bottomLeft();
        }
        else if(BottomLeft == m_resizeTag)
        {
            m11 = (rectF.right()-localPointF.x())/rectF.width();
            m22 = (localPointF.y()-rectF.top())/rectF.height();
            lockPoint = rectF.topRight();

        }
        else if(BottomRight == m_resizeTag)
        {
            m11 = (localPointF.x()-rectF.left())/rectF.width();
            m22 = (localPointF.y()-rectF.top())/rectF.height();
            lockPoint = rectF.topLeft();
        }
		else if (Top == m_resizeTag)
		{
			m11 = 1;
			m22 = (rectF.bottom() - localPointF.y()) / rectF.height();
			lockPoint = QPointF(rectF.left()+rectF.width()/2,rectF.bottom());
		}
		else if (Bottom == m_resizeTag)
		{
			m11 = 1;
			m22 = (localPointF.y() - rectF.top()) / rectF.height();
			lockPoint = QPointF(rectF.left() + rectF.width() / 2, rectF.top());
		}
		else if (Left == m_resizeTag)
		{
			m11 = (rectF.right() - localPointF.x()) / rectF.width();
			m22 = 1;
			lockPoint = QPointF(rectF.right(),rectF.top() + rectF.height() / 2);
		}
		else if (Right == m_resizeTag)
		{
			m11 = (localPointF.x() - rectF.left()) / rectF.width();
			m22 = 1;
			lockPoint = QPointF(rectF.left(), rectF.top() + rectF.height() / 2);
		}
        CBaseData* pdata = g_dataPtr(m_item);
        pdata->SetOrgScaleX(pdata->GetOrgScaleX()*m11);
        pdata->SetOrgScaleY(pdata->GetOrgScaleY()*m22);
        CBaseData::ApplyScaleProperty(m_item, pdata->GetOrgRotation(),pdata->GetOrgScaleX(), pdata->GetOrgScaleY(),lockPoint);
    };
    virtual void EditFinish()
    {
        IDrawTool::PushUndoCommand( new EditTransformItemScaleCommand(m_item, m_lastTransform));
        m_lastTransform = GetTransform();
    };
    virtual QRectF GetRect() {return m_item->boundingRect();};
    QTransform GetTransform() {return m_item->transform();};
    void ApplyTransform(const QTransform& transform) {m_item->setTransform(transform, false);};
    virtual void Revoke() {};
protected:
    QTransform m_lastTransform;
};

class CSvgItem;
class CSvgDrawTool : public IScaleRectShapeDrawTool<CSvgItem>
{
public:
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
};
#ifdef CHARTS
class CChartDrawTool : public IResizeRectShapeDrawTool<CGChartItem>
{
public:
    virtual IDrawTool::EditClickMode GetClickEditMode() const { return IDrawTool::SingleClickMode; };
    virtual void CreateNew(QGraphicsScene* scene, const QString& createTypeName, const QPointF& pos);
    virtual QRectF GetRect();
    virtual void ApplyRect(const QRectF& rect);
    virtual void EditFinish();
};
#endif
class CPixmapItem;
class CPixmapDrawTool : public IScaleRectShapeDrawTool<CPixmapItem>
{
public:
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
};

class CGroupItem;
class CGroupDrawTool : public IScaleRectShapeDrawTool<CGroupItem>
{
public:
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
};

class CIconItem;
class CIconDrawTool : public IScaleRectShapeDrawTool<CIconItem>
{
public:
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
	bool MouseHint(const QPointF& pointF);
	bool MouseRelease(const QPointF&);
    bool TestHintOtherLinkItem(const QPointF& pos);
};

class CTextDrawTool : public IScaleRectShapeDrawTool<QGraphicsSimpleTextItem>
{
public:
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    bool MouseHint( const QPointF& pointF) { return false; };
    void EditDrawing( const QPointF& pointF) {};
    void EditFinish() {};
    void Revoke() {} ;
//    void Reset() {};

};

class CGraphicsTextDrawTool : public IScaleRectShapeDrawTool<QGraphicsTextItem>
{
public:
	virtual void CreateNew(QGraphicsScene* scene, const QString& createTypeName, const QPointF& pos);
	bool MouseHint(const QPointF& pointF) { return false; };
	void EditDrawing(const QPointF& pointF) {};
	void EditFinish() {};
	void Revoke() {};
//	void Reset() {};

};

class CPinDrawTool : public IDrawTool
{
public:
	CPinDrawTool() : IDrawTool(){ m_item = NULL; };
    virtual EditClickMode GetClickEditMode() const {return SingleClickMode;};
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual void SetItem(QGraphicsItem* item);
    virtual void InsertDrawing(const QPointF& ){};
    virtual bool MouseHint(const QPointF&) {return false;};
    virtual void EditDrawing(const QPointF&) {};
    virtual void EditFinish() {};
    virtual void Revoke() {};
    virtual void Reset();
private:
    CPinItem* m_item;

};

class CPolygonDrawTool : public IDrawTool
{
public:
	CPolygonDrawTool() : IDrawTool() { m_item = NULL;m_activePointId=-1; };
    virtual EditClickMode GetClickEditMode() const {return MultiClickMode;};
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual bool OnInsertDrawingClicked(const QPointF& pointF);
	virtual bool OnInsertDrawingDoubleClicked(const QPointF&);
    virtual void SetItem(QGraphicsItem* item);
    virtual void InsertDrawing(const QPointF& );
    virtual bool MouseHint(const QPointF&);
    virtual void EditDrawing(const QPointF&);
    virtual void EditFinish();
    virtual void Revoke();
    virtual void Reset();
public:
    virtual void AddPoint(const QPointF& pointF);
    virtual void DelPoint();
protected:
    QGraphicsPolygonItem* m_item;
    QPolygonF m_lastPolygonF;
    int m_activePointId;
};

class CPolyLineDrawTool : public CPolygonDrawTool
{
public:
    CPolyLineDrawTool() : CPolygonDrawTool() {};
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual bool OnInsertDrawingClicked(const QPointF& pointF);
	virtual bool OnInsertDrawingDoubleClicked(const QPointF&);
    virtual void InsertDrawing(const QPointF& );
    virtual void EditDrawing(const QPointF&);
public:
    virtual void AddPoint(const QPointF& pointF);
    virtual void DelPoint();
protected:
    QPointF m_lastClickPoint;
};

class CLinkDrawTool : public CPolyLineDrawTool
{
public:

    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual void SetItem(QGraphicsItem* item);
    virtual bool OnInsertDrawingClicked(const QPointF& pointF);
	virtual bool OnInsertDrawingDoubleClicked(const QPointF&);
    virtual void InsertDrawing(const QPointF& );
    virtual void EditDrawing(const QPointF&);
    virtual void EditFinish();
    virtual void InsertFinish();
    virtual bool MouseHint(const QPointF&);
    virtual bool MouseRelease(const QPointF&) ;
    bool TestHintOtherLinkItem(bool isEdit);
public:
    virtual void AddPoint(const QPointF& pointF) {Q_UNUSED(pointF);};
    virtual void DelPoint() {};
protected:

    static void AdjustLinkLine(CLinkLineItem* linkItem, bool isHead, QGraphicsItem* hintItem);
    CLinkLineItem* m_linkItem;
    CLinkLineItem* m_intersectLinkItem;
    CPinItem* m_oldHeadPin;
    CPinItem* m_oldTailPin;
};

class CAbstractPathDrawTool : public IDrawTool
{
public:
    CAbstractPathDrawTool() : IDrawTool(), m_item(NULL),m_activeInflexionId(-1),m_resizeTag(NoneResize) {};
    virtual EditClickMode GetClickEditMode() const {return MultiClickMode;};
    virtual void CreateNew(QGraphicsScene* scene,const QString& createTypeName, const QPointF& pos);
    virtual void SetItem(QGraphicsItem* item);
    virtual void InsertDrawing(const QPointF& pointF);
    virtual bool OnInsertDrawingClicked(const QPointF& pointF);
	virtual bool OnInsertDrawingDoubleClicked(const QPointF&);
    virtual bool MouseHint(const QPointF& pointF);
    virtual void EditDrawing(const QPointF& pointF);
    virtual void EditFinish();
    virtual void Revoke();
    virtual void Reset();
public:
    void AddPoint(const QPointF& pointF);
    void DelPoint();
private:
    CAbstractPathItem* m_item;
    QVector<QPointF> m_lastPointVec;
    int m_activeInflexionId;
    int m_resizeTag;
};


#endif
