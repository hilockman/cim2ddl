#ifndef GRAPHITEM_H
#define GRAPHITEM_H


#include "Global.h"
#include "BaseData.h"
#include <QGraphicsSvgItem>
#include <QSet>

#define G_G(class) class* const G = static_cast<class*>(Item());//dataÀàÖÐÈ¡µÃ¶ÔÓ¦µÄitemÖ¸ÕëµÄºê£¬justÖ´ÐÐÇ¿ÖÆ×ª»»
#define g_getItemName(item)  (g_dataPtr(item)?g_dataPtr(item)->GetName():"")

////百分比动态填充/////
#define G_DECLARE_FILLPERCENT \
    public: \
    Q_PROPERTY(qreal fillPercent READ FillPercent WRITE SetFillPercent ) \
    Q_PROPERTY(int fillDir READ GetFillDir WRITE SetFillDir ) \
    void	SetFillPercent(qreal percent,int Vflag=-1) { \
                if(percent>1 ||percent<0)  m_FillPercent=1;  else  m_FillPercent=percent; \
                if(Vflag>=0) m_Vflag = Vflag; \
                Item()->update();} \
    qreal  FillPercent(){return m_FillPercent;}; \
    void   SetFillDir(int dir){m_Vflag= dir==1?true:false;}; \
    int    GetFillDir( ){return m_Vflag==true? 1:0;}; \
    double m_FillPercent; \
    bool m_Vflag;

/////特殊颜色/////
#define G_DECLARE_SHAPE_INTERFACE \
    virtual void 	SetLineColor(const QColor& color);\
    virtual QColor 	GetLineColor() const;\
    virtual void	SetFillColor(const QColor& color);	\
    virtual QColor	GetFillColor() const ;	\
    virtual Qt::BrushStyle	GetFillStyle() const ;\
    virtual void	SetFillStyle(Qt::BrushStyle style);\
    virtual Qt::PenStyle	GetLineStyle() const ;\
    virtual void	SetLineStyle(Qt::PenStyle style);\
	virtual qreal  		GetLineWidth() const; \
	virtual void  		SetLineWidth(qreal width);




using Hmi::ItemType;

DLL_CLASS inline bool g_isPinItem(int type)
{
    return Hmi::Pin == type || Hmi::Bus == type ;// || Hmi::Link == type ;
}

inline static bool zLessThan(const QGraphicsItem* item1,const QGraphicsItem* item2)
{
    return item1->zValue() < item2->zValue();
};

inline static void g_reOrder(QList<QGraphicsItem*>& ListItems)
{
    //qStableSort(ListItems.begin(),ListItems.end(),zLessThan);
};

bool g_ifExplorer(QGraphicsScene *pscene );
void g_SetData(QGraphicsItem* item,CBaseData* pdata);
void g_HighlightSelected(QGraphicsScene *pscene, QPainter *painter, const QStyleOptionGraphicsItem *option, const QVector<QPointF>& pointFVec, const qreal& corner_width = CORNER_RECTPAD, bool insideDraw = false, const QColor& rectColor = Qt::gray);
void g_PaintBoundingRect(QGraphicsScene *pscene, QPainter* painter, const QStyleOptionGraphicsItem *option, const QRectF& rect, const qreal& corner_width = CORNER_RECTPAD);
void g_PaintBackground(QGraphicsScene *pscene, QPainter* painter, const QStyleOptionGraphicsItem *option, const QPainterPath& path, const QString& color);

/************************************************************************/
/*                       CPolygonItem                                   */
/************************************************************************/
class CPolygonItem;
class QGradient;
class CPathAnimation;
class DLL_CLASS CPolygonData :public CBaseData
{
    Q_OBJECT
    G_DECLARE_FILLPERCENT
public slots:
    void SetArrowInfo(const QString &arrowinfo);
public:
    CPolygonData(QGraphicsItem* item);
    virtual ~CPolygonData(){};
    QGraphicsItem*	Clone();
    virtual void	Copy(const CBaseData*  srcData);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
private:
    QGradient* m_pGradient;
};

class DLL_CLASS CPolygonItem : public QGraphicsPolygonItem
{
public:
    CPolygonItem( QGraphicsItem *parent = 0, int type = Hmi::Polygon);
    CPolygonItem* Clone();
    virtual ~CPolygonItem();
public:
    int type() const { return m_type;};
    QRectF	boundingRect() const;
protected:
    void	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
protected:
    CPolygonData* m_pData;
    const int m_type;

};
/************************************************************************/
/*                       CPolylineItem                                  */
/************************************************************************/

class DLL_CLASS CPolylineItem : public CPolygonItem
{
public:
    friend class CPolygonData;
    CPolylineItem( QGraphicsItem *parent = 0, int type = Hmi::Polyline);
	CPolylineItem* Clone();
    virtual ~CPolylineItem(){};
    virtual QRectF boundingRect() const;
    virtual	QPainterPath shape() const;
    void   paintEx(QPainter *painter, const QPolygonF &polygon, const QStyleOptionGraphicsItem *option );
    void    SetArrowInfo(int arrow_start_type,int arrow_start_size,int arrow_end_type,int arrow_end_size);
protected:
    virtual void  paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QVariant    itemChange(GraphicsItemChange change, const QVariant &value);
    uchar         m_StartArrowType;   
    uchar         m_EndArrowType;     
    uchar         m_StartArrowSize;   
    uchar         m_EndArrowSize;    
};

/************************************************************************/
/*                       CLineItem                                      */
/************************************************************************/
class DLL_CLASS CLineData :public CBaseData
{
public:
    CLineData(QGraphicsItem* item):CBaseData(item){};
    virtual ~CLineData(){};
    virtual QGraphicsItem*	Clone();
    virtual void	Copy(const CBaseData*  srcData);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
    virtual void    SetTransformOrigin(float flag=0);
    G_DECLARE_SHAPE_INTERFACE
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
private:
};

class DLL_CLASS CLineItem : public QGraphicsLineItem
{
public:
    CLineItem(QGraphicsItem *parent = 0);
    CLineItem(const QLineF & line, QGraphicsItem * parent = 0 );
    virtual ~CLineItem();
    virtual QRectF			boundingRect() const;
    virtual	QPainterPath	shape() const;
    virtual	int				type() const	{return Hmi::Line;};
protected:
    virtual	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
public:
    CLineData* m_pData;
};

/************************************************************************/
/*                       CRectItem                                      */
/************************************************************************/
class CRectData;
class DLL_CLASS CRectItem : public QGraphicsRectItem
{
public:
    CRectItem(QGraphicsItem *parent = 0);
    virtual ~CRectItem();
    virtual	int				type() const	{return Hmi::Rect;};
    virtual QRectF			boundingRect() const;
    virtual	QPainterPath shape() const;
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void    PaintGL( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
public:
    CRectData* m_pData;
};

class DLL_CLASS CRectData :public CBaseData
{
    Q_OBJECT
    G_DECLARE_FILLPERCENT
    friend class CRectItem;
    enum SHADOW_TYPE{NoShadow,ShadowUp,ShadowDown};
public:
    Q_PROPERTY(QRectF rect READ Rect WRITE SetRect )
    CRectData(QGraphicsItem* item):CBaseData(item),rx(0),ry(0),m_FillPercent(1),m_Vflag(true),m_ShadowType(0){};
    virtual ~CRectData(){};
    virtual QGraphicsItem*	Clone();
    virtual void	Copy(const CBaseData*  srcData);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
    virtual void SetRect(qreal x,qreal y,qreal width,qreal height){((CRectItem*)Item())->setRect(QRect(x,y,width,height));};
    QRectF	Rect(){return ((CRectItem*)Item())->rect() ;};
    void SetRect(QRectF rect){((CRectItem*)Item())->setRect(rect);};
    void	SetRx(double val){rx=val;};
    double  Rx()	{return rx;};
    void	SetRy(double val){ry=val;};
    double  Ry()	{return ry;};
    bool    IfVDirect(){return m_Vflag;}; 
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
private:
    qreal rx;
    qreal ry;  
    int m_ShadowType;
};

/************************************************************************/
/*                       CEllipseItem                                   */
/************************************************************************/
class CEllipseData;
class DLL_CLASS CEllipseItem : public QGraphicsEllipseItem
{
public:
    enum ShapeT{EllipseST,PieST,ArcST,ChordST};
    CEllipseItem(QGraphicsItem *parent = 0);
    virtual ~CEllipseItem();
    virtual	int		type() const	{return Hmi::Ellipse;};
    virtual QRectF	boundingRect() const;
    virtual	QPainterPath shape() const;
    void	SetShapeType(int type)	{m_ShapeType=type;};
    int		ShapeType( )			{return m_ShapeType;};
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
public:
    CEllipseData* m_pData;
    int m_ShapeType;
};
class DLL_CLASS CEllipseData :public CBaseData
{
    Q_OBJECT
    G_DECLARE_FILLPERCENT
public:
    Q_PROPERTY(QRectF rect READ Rect WRITE SetRect )
    CEllipseData(QGraphicsItem* item):CBaseData(item){ m_FillPercent=1; m_Vflag = true;};
    virtual ~CEllipseData(){};
    virtual QGraphicsItem*	Clone();
    virtual void	Copy(const CBaseData*  srcData);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
    virtual void SetRect(qreal x,qreal y,qreal width,qreal height){((CEllipseItem*)Item())->setRect(QRect(x,y,width,height));};
    void SetRect(QRectF rect){((CEllipseItem*)Item())->setRect(rect);};
    QRectF Rect(){return ((CEllipseItem*)Item())->rect();};
public slots:
    void   SetSpanAngle(int angle);
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
};

class CPinItem;
/************************************************************************/
/*                       CTextItem                                      */
/************************************************************************/
class CTextItem;
class DLL_CLASS CTextData :public CBaseData
{
    Q_OBJECT
public:
    Q_PROPERTY(QString text READ Text WRITE SetText)
    Q_PROPERTY(int direct READ GetTextDirect WRITE SetTextDirect)
    enum DISP_TYPE
    {
        D_DEFAULT=0,D_TRANS,/*D_STRING,*/D_INT,D_FLOAT,D_PERCENT,      //°Ù·Ö±È
        D_DATETIME,D_WEEK,//¹¤×÷ÈÕ
        D_YEAR_MONTH_DAY, //Äê/ÔÂ
        D_HOUR_MIN_SECOND,   //Ê±:·Ö
        D_YEAR,      //Äê·Ý
        D_MONTH,     //ÔÂ·Ý
        D_DAY,      //ÈÕÆÚ
        D_HOUR,      //Ð¡Ê±
        D_MINUTE,      //·ÖÖÓ
        D_SECOND     //Ãë
    };

    friend class CTextItem;
    CTextData(QGraphicsItem* item);
    virtual ~CTextData(){};
    virtual QGraphicsItem*	Clone();
    virtual void	Copy(const CBaseData*  srcData);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);

public slots:
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
    virtual void	SetFont(const QFont& f) ;
    virtual QFont	Font() const;
    virtual void	SetTextColor(const QColor& c);
	virtual qreal GetLineWidth() const;
    virtual void SetLineColor(const QColor& color);
    int     GetDispType(){return m_DisplayType;};
	int     GetDecimalDigits(){ return m_decimalDigits; };
	int     GetTimeFormat(){ return m_timeFormat; };
    QString GetPrefix(){ return m_prefix; };
    QString GetSuffix(){ return m_suffix; };
    virtual QString Text() ;
    virtual void    SetText(const QString& text);
	virtual void SetLineWidth(qreal width);
    void    SetTextDirect(int textDirect){ m_textDirect = textDirect; };
    int     GetTextDirect(){ return m_textDirect; };
    virtual void    SetOrgText(QString orgText);
    QString     GetOrgText(){ return m_orgText; };

protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
    virtual void    LoadSubProperty(CGraphSvgReader* xio);
    QString formatString();
public:
    int m_DisplayType;
    QString m_orgText;
    int m_textDirect;
	int m_decimalDigits;
	int m_timeFormat;
	QString m_prefix;
	QString m_suffix;
};

class DLL_CLASS CTextItem : public QGraphicsSimpleTextItem
{
public:
    CTextItem(QGraphicsItem *parent = 0);
    virtual ~CTextItem();
    virtual	int				type() const	{return Hmi::Text;};
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
public:
    CTextData* m_pData;
};
/************************************************************************/
/*                       CGraphicsTextItem                                      */
/************************************************************************/
class DLL_CLASS CGraphicsTextData :public CTextData
{
	Q_OBJECT
public: 
	friend class CGraphicsTextItem;
    CGraphicsTextData(QGraphicsItem* item) :CTextData(item) {};
	virtual ~CGraphicsTextData(){};
    virtual	QString GetSaveTagName() const {return "text";};
    virtual QGraphicsItem*	Clone();
public slots:
    virtual void	SetFont(const QFont& f);
    virtual QFont	Font()  const;
	virtual void	SetTextColor(const QColor& c);
	virtual void SetLineWidth(qreal width);
	virtual qreal GetLineWidth() const;
	virtual void SetLineStyle(Qt::PenStyle style);
	virtual Qt::PenStyle GetLineStyle() const;
	virtual void SetLineColor(const QColor& color);
	virtual QColor GetLineColor() const;
	virtual QBrush Brush() const;
	virtual void SetFillColor(const QColor& color);
	virtual QColor GetFillColor() const;
};

class DLL_CLASS CGraphicsTextItem : public QGraphicsTextItem
{
public:
	CGraphicsTextItem(QGraphicsItem *parent = 0);
	virtual ~CGraphicsTextItem();
	enum { Type = Hmi::GraphicsText };
	virtual	int				type() const	{ return Hmi::GraphicsText; };

protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	virtual void focusOutEvent(QFocusEvent *event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
public:
    CGraphicsTextData* m_pData ;
};

/************************************************************************/
/*                       CPixmapItem                                     */
/************************************************************************/
class DLL_CLASS CAbstractScaleData : public CBaseData
{
    Q_OBJECT
public:
    CAbstractScaleData(QGraphicsItem* item) : CBaseData(item) {};
    virtual ~CAbstractScaleData() {};
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
};


class DLL_CLASS CPixmapData :public CAbstractScaleData
{
    Q_OBJECT
public:
    CPixmapData(QGraphicsItem* item);
    virtual ~CPixmapData();
    QGraphicsItem*	Clone();
    void	Copy(const CBaseData*  srcData);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
public slots:
    bool    Load(const QString& fileName);
    bool    LoadFromData(const QVariant &data, QString format="0", QString flags="" );
	QString GetFileName() { return m_fileNameList.first(); };
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
private:
    static QPixmap GetNoPixmap();
private slots:
    void  movieUpdated(const QRect& area);
public:
    bool m_IsMovie;
    QMovie *m_pMovie;
    QStringList m_fileNameList;
    bool m_ConvertBGTransparency;
};

class DLL_CLASS CPixmapItem : public QGraphicsPixmapItem
{
public:
    CPixmapItem(QGraphicsItem *parent = 0);
    //CPixmapItem(const CPixmapItem& rectItem);
    //CPixmapItem& operator = (const CPixmapItem& rectItem);
    virtual ~CPixmapItem();
    void	ApplyRect(const QSize& size);
    virtual	int				type() const	{return Hmi::Pixmap;};
    virtual QRectF			boundingRect() const;
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
private:
    CPixmapData* m_pData;
    QSize m_size;
};

/************************************************************************/
/*                       CSvgItem                                       */
/************************************************************************/
class QSvgRenderer;
class DLL_CLASS CSvgData :public CAbstractScaleData
{
public:
    CSvgData(QGraphicsItem* item):CAbstractScaleData(item){};
    virtual ~CSvgData(){};
    QGraphicsItem*	Clone();
	void	Copy(const CBaseData*  srcData);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);

};

class DLL_CLASS CSvgItem : public QGraphicsSvgItem
{
public:
    CSvgItem(QGraphicsItem *parent = 0);
    virtual ~CSvgItem();
    virtual	int				type() const	{return Hmi::SvgItem;};
    virtual QRectF			boundingRect() const;
    QString GetFileName()	{return m_FileName;};
    int		Load(const QString& fileName);
    QRectF  Rect();
    void	SetRect(const QRectF& rect);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
public:
    CSvgData* m_pData;
    QString m_FileName;
    QSvgRenderer * m_pRenderer;
    bool	m_IsValide;
};

/************************************************************************/
/*                       CLinkLineItem                                  */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
//link, CLinkLine
class DLL_CLASS CLinkLineData:public CPolygonData
{
    Q_OBJECT
public slots:
    void SetRunningFlag(int value) ;
    QObjectList GetNodes(QString pid="");
    QStringList GetLinkInfo(){ return m_Linkinfo.split(",");};
public:
    CLinkLineData(QGraphicsItem* item):CPolygonData(item){m_Linkinfo="";};
    virtual ~CLinkLineData(){};
    QGraphicsItem*	Clone();
    virtual	QString GetSaveTagName() const {return "polyline";};
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    static  void  UpdateLinks(const QList<QGraphicsItem*>& ListItems);
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
    QString m_Linkinfo;
};
class DLL_CLASS CLinkLineItem : public CPolylineItem 
{
public:
    enum NodeID	{None=-1, Head, Tail};
    enum LineConnectionType {Conn_NoInit = 0, Conn_Normal, Conn_Reverse};
    //friend class CPinItem;
    friend class CLinkLineData;
    CLinkLineItem(QGraphicsItem* parent=0);
    virtual ~CLinkLineItem();
    virtual	int				type() const	{return Hmi::Link;};
    bool		HasEnd()		const		{return m_tail!=NULL;};
    bool		HasBegin()		const		{return m_head!=NULL;};
    CPinItem*	HeadPinItem()	const		{return m_head;};
    CPinItem*	TailPinItem()	const		{return m_tail;};
    QGraphicsItem*   GetPinLinkItem(int terminate)  ;//»ñÈ¡Á½¶ËÁ¬½ÓµÄÊµ¼Ê¶ÔÏó £¬Í¨¹ýËùÁ¬µÄpinÕÒµ½pinµÄ¸¸¶ÔÏó
    void UpdateLoadedConnection();

    void		DelLink(CPinItem* item);
    void		SetLink(CPinItem* item, bool isHead);
    void		SetLink(CPinItem* headItem, CPinItem* tailItem);
    void		PassLink(bool isHead, CLinkLineItem* refLinkItem, bool isRefHead);

    void	AdjustNodes();
    bool	IsHeadPinItem(CPinItem* item) const {return m_head == item;};
    QPointF Split(const CLinkLineItem* sectItem, int activePointId, QPolygonF& section1, QPolygonF& section2);
    //·Ö¶Îº¯Êý£¬pos·Ö¶ÎÂäµã£¬blockLength ¶Ï¿ª³¤¶È£¬section1£¬section2·µ»ØÁ½¶ÎÏß¶Î£¬·µ»ØÖµÊÇ·Ö¶Îµã
    QPointF Split( QPointF pos ,int blockLength , QPolygonF& section1, QPolygonF& section2 );
    QGraphicsItem* TestHintItem(int pointId);		//³¢ÊÔÌ½²âÄ³Ò»¶ËpointId¿ÉÁ¬½ÓµÄ¶ÔÏó²¢·µ»Ø¸Ã¶ÔÏó£¨ pin»ò ÆäËûlinkItem£©
    QGraphicsItem**  GetHintItemArray()  {return m_hintItemArray;};

    bool IsInitConnected();
    void SetRunningFlag(QVariant tagValue);
    void DoRunning();

	void SetInitPos(bool beInsert){ m_bInitPos = beInsert; }
protected:
    void    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void    CalPolygon(QPainter *painter, const QStyleOptionGraphicsItem *option);

    QVariant itemChange(GraphicsItemChange change, const QVariant& value);
	virtual	void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
	virtual	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	virtual	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	virtual	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	virtual	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    void	UpdatePin(CPinItem*& pPinItem,const QString& name,bool ishead);

    CPinItem*	m_head;
    CPinItem*	m_tail;
    QString m_loadedHeadName;
    QString m_loadedTailName;
    int m_runningDirection;
    CPathAnimation* m_pProAnimation;
    CPolygonItem* m_pAnimteitem;
    QGraphicsItem*	m_hintItemArray[2];
    //
    qreal m_VerticalPos;
    qreal m_HorizontalPos;
    LineConnectionType m_nConnType;
	QPointF m_OrgPoint;
    qreal m_OffsetY;
    qreal m_OffsetX;
    bool m_bRemoved;   
    bool m_bInDragMode;
    bool m_bInDragArea;
    int m_nCursorType;
    bool m_bInitPos;
};

/************************************************************************/
/*                       CPinitem										*/
/************************************************************************/

class DLL_CLASS CPinData :public CBaseData
{
	Q_OBJECT
public:
    CPinData(QGraphicsItem* item):CBaseData(item){};
    virtual ~CPinData(){};
    virtual QGraphicsItem*	Clone();
    virtual void	Copy(const CBaseData*  srcData);
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
public slots:
    QObjectList GetLinkItems();
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual	QString GetSaveTagName() const {return "rect";};

    G_DECLARE_SHAPE_INTERFACE
};
class DLL_CLASS CPinItem : public QGraphicsItem
{
public:
    friend class CPinIdGenerator;
    friend class CPinData;
    CPinItem(QGraphicsItem* parent = 0);
    ~CPinItem();
    virtual int type() const {return Hmi::Pin;};
    QRectF boundingRect() const;
    virtual void	AddLink(CLinkLineItem* linkItem, const QPointF& nodePointF) {Q_UNUSED(nodePointF);m_linkItemSet<<linkItem;};
    virtual void	DelLink(CLinkLineItem* linkItem) {m_linkItemSet.remove(linkItem);};
    void	FreshPos();
    int	 GetPinId() const					{return m_id;};
    bool	IsInitConnected();
    QSet<CLinkLineItem*> LinkLineItems(){return m_linkItemSet;};
    QGraphicsItem* GetParentIcon();
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QVariant itemChange(GraphicsItemChange change, const QVariant& value);
    QStringList m_linkItemNames;
private:
    void SetPinId(int id)					{m_id = id;};
    int				m_id;
    static const QRectF	cs_rectF;
    QSet<CLinkLineItem*> m_linkItemSet;
    CPinData* m_data;
    const static ShapeStru s_shapeData;// = ShapeStru(Qt::magenta,2);
};

class DLL_CLASS CBusData : public CBaseData
{
    Q_OBJECT
    Q_PROPERTY(QColor fillColor READ GetFillColor WRITE SetFillColor )
    Q_PROPERTY(QColor lineColor READ GetLineColor WRITE SetLineColor )
	Q_PROPERTY(qreal lineWidth READ GetLineWidth WRITE SetLineWidth)
    Q_PROPERTY(Qt::PenStyle lineStyle READ GetLineStyle WRITE SetLineStyle )
    Q_PROPERTY(Qt::BrushStyle fillMode READ GetFillStyle WRITE SetFillStyle )

public slots:
    QVariantList	Points()  ;
    void	SetPoints(const QVariantList& line);
public:
    CBusData(QGraphicsItem* item):CBaseData(item){};
    virtual ~CBusData(){};
    QGraphicsItem*	Clone();
    virtual	int				type() const	{return Hmi::Bus;};
    virtual	QString GetSaveTagName() const {return "line";};
    virtual void	GetPropertyList(QList< QPair<QString, QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname, const QVariant& value);
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);

    G_DECLARE_SHAPE_INTERFACE
    private:

};

class DLL_CLASS CBusItem : public CPinItem
{
public:
    CBusItem(QGraphicsItem* parent=NULL);
    ~CBusItem();
    friend class CBusData;
    virtual void	AddLink(CLinkLineItem* linkItem, const QPointF& nodePointF) {m_linkPointMap[linkItem] = nodePointF;};
    virtual void	DelLink(CLinkLineItem* linkItem) {m_linkPointMap.take(linkItem);};
    virtual int type() const {return Hmi::Bus;};
    QRectF boundingRect() const;
    QPainterPath shape() const;
    QLineF	line() const {return m_line;};
    void	setLine(const QLineF& line);		//Ð¡Ð´ÎªÁËÄ£°å
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QVariant itemChange(GraphicsItemChange change, const QVariant& value);
private:
    CBusData* m_data;
    QLineF	m_line;
    ShapeStru m_shapeData;
    QMap<CLinkLineItem*, QPointF> m_linkPointMap;
};


/*CPathItem*/
//const int MAX_PATH_CB= 50;
class DLL_CLASS CAbstractPathData :public CBaseData
{
public:
    CAbstractPathData(QGraphicsItem* item):CBaseData(item),m_Symbol(""),m_PathFlag(0){};
    virtual ~CAbstractPathData(){};
    virtual QGraphicsItem*	Clone();
    virtual void	Copy(const CBaseData*  srcData);
    virtual	QString GetSaveTagName() const {return "path";};
    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString& propname,const QVariant& value);
    void    SetPath(const QPainterPath & path);
    int     SetSymbolName(const QString name);
    QString GetSymbolName(){return m_Symbol;};
protected:
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
private:
    QString m_Symbol;
    char m_PathFlag; //0 private parse,1 simaple ,2 standard parse
};
/*class DLL_CLASS CPathData :public CAbstractPathData
{
public:
    CPathData(QGraphicsItem* item):CAbstractPathData(item){};
    virtual ~CPathData(){};
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio);
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
};
class DLL_CLASS CClosePathData :public CAbstractPathData
{
public:
    CClosePathData(QGraphicsItem* item):CAbstractPathData(item){};
    virtual ~CClosePathData(){};
    virtual void	SaveBaseProperty(CGraphSvgWriter* xio);
    virtual void	LoadBaseProperty(CGraphSvgReader* xio);
};*/

template<class T, int Prealloc>
class QVarLengthArray;
class DLL_CLASS CAbstractPathItem : public QGraphicsPathItem
{
public:
    friend class CAbstractPathData;
    CAbstractPathItem(QGraphicsItem *parent = 0, int type = Hmi::Path);
    virtual		~CAbstractPathItem();
    QRectF		boundingRect() const;
    int			type() const {return m_type;};
    /////////////////////////////// ///////////////////////////////////////
    void		AppendInflexion(const QPointF& inflexion, bool refresh = true);		//
    void		SetInflexion(int id, const QPointF& inflexion);	//
    void		SetTailInflexion(const QPointF& inflexion);	//
    void		ApplyInflexionVec(const QVector<QPointF>& vec);
    QVector<QPointF> GetInflexionVec() const {return m_inflexionVec;};
    //
    int			GetInflexionSize() const {return m_inflexionVec.size();};
    QPointF		GetInflexion(int id) const {return mapToScene(m_inflexionVec[id]);};
protected:
    virtual QPainterPath CreatePath() = 0;
    virtual inline QVarLengthArray<QPointF, 30> CreateCBezier()= 0;
    const int m_type;
    CAbstractPathData* m_pData;
    QVector<QPointF> m_inflexionVec;
};

class DLL_CLASS CPathItem : public CAbstractPathItem
{
public:
    CPathItem(QGraphicsItem* parent=0) : CAbstractPathItem(parent, Hmi::Path) {};
    QPainterPath shape() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
protected:
    virtual QPainterPath CreatePath();
    virtual inline QVarLengthArray<QPointF, 30> CreateCBezier();
};

class DLL_CLASS CClosePathItem : public CAbstractPathItem
{
public:
    CClosePathItem(QGraphicsItem* parent=0) : CAbstractPathItem(parent, Hmi::ClosePath) {};
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
protected:
    virtual QPainterPath CreatePath();
    virtual inline QVarLengthArray<QPointF, 30> CreateCBezier();
};



#endif
