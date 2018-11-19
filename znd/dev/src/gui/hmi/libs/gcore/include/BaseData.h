

#ifndef BASEDATA_H
#define BASEDATA_H 

#include <QObject>
#include <QBitArray>
#include <QGraphicsItem>
#include "Export.h"


class CGraphSvgReader;
class CGraphSvgWriter;
class QPropertyAnimation;
class CBaseData;

#define BASEKEY 1

DLL_CLASS inline CBaseData* g_dataPtr(QGraphicsItem* item)
{
    return NULL==item ? NULL:item->data(BASEKEY).value<CBaseData*>();
};
DLL_CLASS inline const CBaseData* g_dataPtr(const QGraphicsItem* item)
{
    return NULL==item ? NULL:item->data(BASEKEY).value<CBaseData*>();
};

struct ShapeStru
{
    ShapeStru(QColor sColor = Qt::black,int swidth = 1,Qt::PenStyle pstyle = Qt::SolidLine,Qt::BrushStyle bstyle = Qt::NoBrush,QColor fColor = Qt::black)
    {
        strokeColor = sColor;
        strokeWidth = swidth ;
        penStyle = pstyle;
        brushStyle =bstyle;
        fillColor = fColor;
    };
    QColor strokeColor;
    qreal strokeWidth;
    Qt::PenStyle penStyle;
    Qt::BrushStyle brushStyle;
    QColor fillColor;
    QString flag;
};

/*!
\ingroup  hmi
\defgroup  BaseItem BaseItem
*/
/*!
\brief   BaseItem   is base calss  for all item <br>
\ingroup BaseItem
*/
class DLL_CLASS CBaseData :public QObject
{
    Q_OBJECT
    /*!
    \brief   <br>
    */
    Q_PROPERTY(QString name READ GetName WRITE SetName )
    Q_PROPERTY(short plane READ GetPlane WRITE SetPlane )
    Q_PROPERTY(short state READ GetState WRITE SetState )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(QColor fillColor READ GetFillColor WRITE SetFillColor )
    Q_PROPERTY(QColor fill READ GetFillColor WRITE SetFillColor )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(QColor lineColor READ GetLineColor WRITE SetLineColor )
    Q_PROPERTY(QColor stroke READ GetLineColor WRITE SetLineColor )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(qreal lineWidth READ GetLineWidth WRITE SetLineWidth )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(Qt::PenStyle lineStyle READ GetLineStyle WRITE SetLineStyle )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(Qt::BrushStyle fillMode READ GetFillStyle WRITE SetFillStyle )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(double rotate READ Rotation WRITE SetRotation )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(double x READ X WRITE SetX )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(double y READ Y WRITE SetY )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(qreal scale READ Scale WRITE SetScale )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(qreal opacity READ Opacity WRITE SetOpacity )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(int flags READ Flags WRITE SetFlags )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(bool visible READ IsVisible WRITE SetVisible )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(QString userData READ GetUserData WRITE SetUserData )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(QPointF pos READ Pos WRITE SetPos)
    /*!
    \brief   <br>
    */
    Q_PROPERTY(QString effect READ Effect WRITE SetEffect)
    /*!
    \brief   <br>
    */
    Q_PROPERTY(qreal dashOffset READ DashOffset WRITE SetDashOffset)
    /*!
    \brief   <br>
    */
    Q_PROPERTY(qreal scaleX READ ScaleX WRITE SetScaleX )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(qreal zValue READ ZValue WRITE SetZValue )
    /*!
    \brief   <br>
    */
    Q_PROPERTY(QString typeName READ TypeName )
    Q_PROPERTY(QString iconType READ IconType )
	Q_ENUMS(COLOR_TYPE)
    
public:
	enum COLOR_TYPE{ LINECOLOR,FILLCOLOR,ALLCOLOR};
    CBaseData(QGraphicsItem* item=0);
    virtual ~CBaseData();
    void showmat(QTransform abc);
    void Save(CGraphSvgWriter* xio) const;
    void Load(CGraphSvgReader* xio);
    void SetItem(QGraphicsItem* item) {m_pItem=item;};
    QGraphicsItem* Item() const {return m_pItem;} ;

public slots:
    /*!
    \brief   <br>
    */
    void Shear(float sx=0, float sy=0, float sz=0,float scale=1);
    /*!
    \brief   <br>
    */
    qreal DashOffset() ;
    /*!
    \brief   <br>
    */
    void SetDashOffset(qreal dashOffset) ;
    /*!
    \brief   <br>
    */
    void Remove();
    /*!
    \brief   <br>
    */
    virtual void ResetColor(COLOR_TYPE type=ALLCOLOR);
    /*!
    \brief   <br>
    */
    void SetParent(QObject * newParent);
    QString ParentName();
    /*!
    \brief   <br>
    */
    int Type() const;
    QString TypeName();
    int IconType();
    /*!
    \brief   <br>
    */
    virtual QVariant Property(QString name,bool allprop=true);
    /*!
    \brief   <br>
    */
    bool SetProperty(const QString& propname,const QVariant& value,bool allprop );
    virtual bool SetProperty(const QString& propname,const QVariant& value );
    /*!
    \brief   <br>
    */
    QVariantMap CustomPropertys();
    /*!
    \brief   <br>
    */
    QString Effect() const {return m_Effect;} ;
    /*!
    \brief   <br>
    */
    int SetEffect(const QString effect);
    /*!
    \brief   <br>
    */
    virtual void SetTransformOrigin(float flag=0);
	float GetTransformOrigin(){ return m_transformOrigin; }

    QPropertyAnimation* GetAnimation(const QString & propertyName);
    /*!
    \brief   <br>
    */
    QObject* SetAnimation(const QString & propertyName,const QVariant& startval="",const QVariant& endval="",int duration=10000,int loop=-1 );
    /*!
    \brief   <br>
    */
    QVariant Center();
    /*!
    \brief   <br>
    */
    QObjectList ChildItems(QString itemType="");
    /*!
    \brief   <br>
    */
    QVariant RoundBox();
    /*!
    \brief   <br>
    */
    virtual void SetRect(qreal x,qreal y,qreal width,qreal height){};
    /*!
    \brief   <br>
    */
    void SetPos(qreal x,qreal y)  ;
    /*!
    \brief   <br>
    */
	QVariant ItemPos();
    /*!
    \brief   <br>
    */
    void SetFlag(QString flag, bool enabled = true);
	/*!
	\brief   <br>
	*/
	QObject* QClone();
	/*!
	\brief   <br>
	*/
	QObjectList Items(const QString & filter);
    void SetBackgroundColor(QString color) {m_BGColor=QColor(color);};
    QColor GetBackgroundColor(){return m_BGColor;};
    virtual bool IsIconContainer(){return false;}; /////是否图元容器，比如间隔/////
public:
    void GetBasePropertyLists(QList< QPair<QString, QList<QPair<QString, QVariant> > > >& pptList);
    virtual void GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList);
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);

    virtual QGraphicsItem* Clone() = 0;
    virtual void Copy(const CBaseData* srcData);
    virtual QString GetSaveTagName() const;
    virtual QString GetSaveTypeName() const;
    ///Vflag,-1无效,0 水平；1垂直方向///
    virtual void SetFillPercent(double percent,int Vflag=-1){Q_UNUSED(percent);Q_UNUSED(Vflag)};

public:
    QString GetName() const {return m_NameString;};
    virtual void SetName(const QString& newName);
    QString GetScript() const {return m_Script;};
    void SetScript(const QString& script){ m_Script=script;};
    short GetPlane() const {return m_Plane;};
    virtual void SetPlane(const short& plane) {m_Plane=plane;};
    virtual void SetState(short state) {m_State=state;};
    short GetState() const {return m_State;};
    QString GetUserData() const {return m_UserData; };
    virtual void SetUserData(const QString& userData){m_UserData=userData; };

    QTransform GetTransform() const;
    virtual int SetPen(const QPen& pen);
    virtual QPen Pen();
    virtual int SetBrush(const QBrush& brush);
    virtual QBrush Brush() const;
    virtual QColor GetLineColor() const;
    virtual QColor GetFillColor() const;
    virtual Qt::BrushStyle GetFillStyle() const ;
    virtual Qt::PenStyle GetLineStyle() const ;
	virtual QString GetLineDashpattern() const;
	virtual qreal GetLineWidth() const;
    virtual void SetLineColor(const QColor& color);
	virtual void SetLineWidth(qreal width);
    virtual void SetLineStyle(Qt::PenStyle style );
	virtual void SetLineDashpattern(QString pattern);
    virtual void SetFillStyle(Qt::BrushStyle style );
    virtual void SetFillColor(const QColor& color);
    virtual void SetFont(const QFont& f) { };
    virtual void SetTextColor(const QColor& c) {Q_UNUSED(c);};
    virtual QString GetBackPixmapName() const {return m_BackPixmapName;};
    virtual void SetBackPixmapName(QString back_pixmap_name) {m_BackPixmapName=back_pixmap_name;};

    void SetRotation(double angle) {SetProperty("rotation", angle);	};
    double Rotation() {	return GetOrgRotation();};
    void SetX(double value) {m_pItem->setX(value);};
    double X() {return m_pItem->x();};
    void SetY(double value) {m_pItem->setY(value);};
    double Y() {return m_pItem->y();};
    void SetZValue(qreal zvalue)    { m_pItem->setZValue(zvalue); };
    qreal ZValue()                  {return m_pItem->zValue() ;} ;
    void SetZaxis(short zaxis) { m_pItem->setZValue(zaxis); };
    void SetScale(qreal factor) {m_pItem->setScale(factor);};
    qreal Scale() const {return m_pItem->scale();};

    void SetScaleX(qreal factor) ;
    qreal ScaleX() ;

    int Flags() const {return m_pItem->flags();};
    void SetFlags(int flags) {m_pItem->setFlags((QGraphicsItem::GraphicsItemFlags)flags);};
    void SetVisible(bool visible) {m_pItem->setVisible(visible);};
    bool IsVisible() const {return m_pItem->isVisible();};
    void SetPos(QPointF pos) { m_pItem->setPos(pos); };
    QPointF Pos() { return m_pItem->pos(); };
    void SetOpacity(qreal opacity) {m_pItem->setOpacity(opacity);};
    qreal Opacity() {return m_pItem->opacity();};

    qreal GetOrgRotation() const {return m_oldRotation;};
	short GetRotateAxis()const { return m_RotateAxis; }
    qreal GetOrgScaleX() const {return m_oldScaleX;};
    qreal GetOrgScaleY() const {return m_oldScaleY;};
    void SetOrgRotation(qreal rot) {m_oldRotation = rot;};
	void SetRotateAxis(short axis) { m_RotateAxis = axis; };
    void SetOrgScaleX(qreal scale) {m_oldScaleX = scale;};
    void SetOrgScaleY(qreal scale) {m_oldScaleY = scale;};

    QColor GetOrgLineColor() const {return m_OrgLineColor;};
    QColor GetOrgFillColor() const {return m_OrgFillColor;};

    void SaveState();
public:
    virtual void PaintOnNail(QPainter *painter, const QStyleOptionGraphicsItem *option, const qreal linewidth);
	static void ApplyScaleProperty(QGraphicsItem* item, qreal rotation, qreal scaleX, qreal scaleY, const QPointF& lockPoint, Qt::Axis rotateAxis=Qt::ZAxis);
    friend void g_SetData(QGraphicsItem*, CBaseData*);
protected:

    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void SaveSubProperty(CGraphSvgWriter* xio) const {Q_UNUSED(xio)};

    virtual void LoadBaseProperty(CGraphSvgReader* xio);
    virtual void LoadSubProperty(CGraphSvgReader* xio);

public:
    short m_Plane;
    short m_State;

    QColor m_OrgLineColor;
    QColor m_OrgFillColor;
    short m_OrgLineWidth;
    short m_OrgRotateAngle;
    short m_RotateAxis;
    char m_OrgLineStyle;
    char m_OrgFillStyle;
    QPointF m_OrgCenter;
    qreal m_oldRotation;
    qreal m_oldScaleX;
    qreal m_oldScaleY;

    QString m_BackPixmapName;
    QString m_NameString;
    QString m_Script;
    QGraphicsItem* m_pItem;
    QString m_UserData;
    QString m_Effect;
	float m_transformOrigin;
    QColor m_BGColor;

};


Q_DECLARE_METATYPE(CBaseData*);

///
/// \brief The CGConfig class
///
class DLL_CLASS CGConfig : QObject
{
    Q_OBJECT
public:
    CGConfig();
    void InitConfig();
    int  GetShapeStyle(int shape_type,ShapeStru& style);
private:
    QMap<int,ShapeStru> m_StyleMap;
};
DLL_CLASS CGConfig * UnqGConfig();
#endif
