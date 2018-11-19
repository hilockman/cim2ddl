

#ifndef CGroupItem_H
#define CGroupItem_H 

#include "Global.h"
#include "GraphItem.h"

typedef QList<QGraphicsItem *> ItemPointerList;

class DLL_CLASS CGroupData :public CAbstractScaleData
{
    Q_OBJECT
public:
    CGroupData(QGraphicsItem* item);
    virtual ~CGroupData(){};
    virtual QString GetSaveTagName() const {return "g";};
    void SetHref(const QString& href) {m_Href=href;};
    QString GetHref() const {return m_Href;};    
    QGraphicsItem* Clone();
    virtual void SetUserData(const QString& userData);
    G_DECLARE_SHAPE_INTERFACE
public slots:
    virtual void ResetColor(COLOR_TYPE type=ALLCOLOR);
    virtual bool IsIconContainer(); /////是否图元容器 比如间隔////
protected:
    virtual void SaveSubProperty(CGraphSvgWriter* xio) const ;
    virtual void LoadSubProperty(CGraphSvgReader* xio);
private:
    QString m_Href;
    ShapeStru m_shapeData;

};


class DLL_CLASS CGroupItem :public QGraphicsItemGroup
{
    friend class CGroupData;
public:
    CGroupItem(QGraphicsItem *parent =0 );
    virtual ~CGroupItem(void);
    int type() const {return Hmi::Group;} ;
    virtual QRectF boundingRect() const ;
    void SetChildItemFlag(QGraphicsItem::GraphicsItemFlag flag, bool enabled =true);
    void GetItemIcon(QPixmap& pic) const;
    virtual void focusOutEvent(QFocusEvent * event);
protected:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
private:
    CGroupData* m_pData;
};



class DLL_CLASS CIconData : public CGroupData
{
    Q_OBJECT
    Q_PROPERTY(int iconClass READ GetIconType  )
    Q_PROPERTY(QString templateName READ GetTemplateName  )
    Q_PROPERTY(bool ifRef READ GetIfRef WRITE  SetIfRef)
public:
    CIconData(QGraphicsItem* item,const QString& tpName = QString());
    virtual ~CIconData(){};
    virtual QString GetSaveTypeName() const;
    virtual QString GetSaveTagName() const {return "g";};
    virtual void SaveIconF(CGraphSvgWriter* xio) const ;
    virtual void LoadIconF(CGraphSvgReader* xio) ;
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool SetProperty(const QString& propname,const QVariant& value);
    virtual void 	SetLineColor(const QColor& color);
    virtual QColor 	GetLineColor() const {return m_LineColor;};
    QGraphicsItem* Clone();
    void Copy(const CBaseData* srcData);
public slots:
    QObjectList GetLinks(QString pid="");
    QObjectList GetNodes(QString pid="");
    void SetStateNums(short stateNums){m_StateNums=stateNums;};
    short GetStateNums(){return m_StateNums;};
    void SetPlaneNums(short nums){m_PlaneNums=nums;};
    short GetPlaneNums(){return m_PlaneNums;};
	bool IsNullPlane(short planeNo);
    virtual void SetState(short state);
   // virtual void SetPlane(const short& plane) ;

    QString GetTemplateName() const {return m_templateName;};
    int SetTemplateName(const QString& name, bool instance=false) ;
    void SetIfRef(bool ifRef) {m_ifRef=ifRef;};
    bool GetIfRef() const {return m_ifRef;};
    void SetIconType(int iType) {m_IconType=iType; };
    int GetIconType() const {return m_IconType;};
    bool IsPowerIcon() ;
    /*
    QMap<QString,QString> GetTagRefMap(){return m_TagRef;};
    void SetTagRefMap(QMap<QString,QString>& tagref);
    QMap<QString,QString> GetTxtRefMap(){return m_TxtRef;};
    void SetTxtRefMap(QMap<QString,QString>& txtref);
*/
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void SaveSubProperty(CGraphSvgWriter* xio) const;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);
    virtual void LoadSubProperty(CGraphSvgReader* xio) ;

private:
    //QMap<QString,QString> m_TagRef;
    //QMap<QString,QString> m_TxtRef;
    short m_StateNums;
    short m_PlaneNums;
    QString m_templateName;
    bool m_ifRef;
    int m_IconType;
    QColor m_LineColor;

};

class DLL_CLASS CIconItem :public CGroupItem
{
    friend class CIconData;
public:
    CIconItem(QGraphicsItem *parent =0 );
    virtual ~CIconItem(void);
    int type() const {return Hmi::Icon;} ;
	virtual QRectF boundingRect() const;
protected:
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
private:
    CIconData* m_pData;
};

///
class CLayoutItem : public QGraphicsLayoutItem
{

public:
    CLayoutItem(QGraphicsLayoutItem *parent = Q_NULLPTR, bool isLayout = false);
    ~CLayoutItem();
    void setZValue(qreal z)
    {
        m_Item->setZValue(z);
    }
    void setGeometry (const QRectF &rect) Q_DECL_OVERRIDE;
    void SetGraphicsItem(QGraphicsItem *item );
protected:
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const Q_DECL_OVERRIDE;
private:
    QGraphicsItem *m_Item;
    QRectF r;
};

class FlowLayout : public QGraphicsLayout
{
public:
    FlowLayout();
    inline void addItem(QGraphicsLayoutItem *item);
    void insertItem(int index, QGraphicsLayoutItem *item);
    void setSpacing(Qt::Orientations o, qreal spacing);
    qreal spacing(Qt::Orientation o) const;

    // inherited functions
    void setGeometry(const QRectF &geom) Q_DECL_OVERRIDE;

    int count() const Q_DECL_OVERRIDE;
    QGraphicsLayoutItem *itemAt(int index) const Q_DECL_OVERRIDE;
    void removeAt(int index) Q_DECL_OVERRIDE;

protected:
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const Q_DECL_OVERRIDE;

private:
    qreal doLayout(const QRectF &geom, bool applyNewGeometry) const;
    QSizeF minSize(const QSizeF &constraint) const;
    QSizeF prefSize() const;
    QSizeF maxSize() const;

    QList<QGraphicsLayoutItem*> m_items;
    qreal m_spacing[2];
};


inline void FlowLayout::addItem(QGraphicsLayoutItem *item)
{
    insertItem(-1, item);
}

#endif
