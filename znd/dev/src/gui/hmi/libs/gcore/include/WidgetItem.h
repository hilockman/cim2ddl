


#ifndef WIDGETITEM_H
#define WIDGETITEM_H 



#include "Global.h"
#include "GraphItem.h"
#include "Export.h"
#include "CQWidgetWrap.h"


class CWidgetItem;
class IPluginWidget;


class DLL_CLASS CWidgetData :public CBaseData
{
    Q_OBJECT
public:
    friend class CWidgetItem;
    CWidgetData(QGraphicsItem* item);
    virtual ~CWidgetData(){};
    virtual QGraphicsItem* Clone();
    virtual void Copy(const CBaseData* srcData);
    virtual void GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList);
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool SetProperty(const QString& propname,const QVariant& value);
	virtual QVariant Property(QString name, bool allprop = true);
    virtual void SetName(const QString& newName);
public slots:
    void    SetWidget(QObject *widget, int wndflag=-1);
	QObject* Widget();
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);
    QSet<QString> m_DirtyProp;
};

class DLL_CLASS CWidgetItem : public QGraphicsProxyWidget
{
    Q_OBJECT
public:

    CWidgetItem(int type, QGraphicsItem *parent = 0,QGraphicsScene * scene=0, Qt::WindowFlags wFlags = 0);
    virtual ~CWidgetItem();
    void Init(QGraphicsItem *parent = 0,QGraphicsScene * scene=0, Qt::WindowFlags wFlags = 0);
public:
	//CWidgetItem::type() must use QGraphicsProxyWidget::Type for squish-6.0.1-qt55x-win64-msvc12
	int widgetType() const { return m_type; }
    QRectF boundingRect() const;
    void mousePressEvent ( QGraphicsSceneMouseEvent * event );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * event );
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

protected:
    void highlightSelected( QPainter *painter, const QStyleOptionGraphicsItem *option);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);


public:
    void SetPixmap(const QString & name);
    void SetText(const QString & text);
    void SetStyleSheet(const QString & sheet);
    void SetIcon(const QString & icon);
    void SetIconSize(const QSize & size);
    void SetTip(const QString & tip);
    void SetFont(const QFont &font);
	QFont Font(){ return m_Font; }
    void SetStyleColor(int color1,int color2);
    void SetShortCut(QString key);
    void SetObjName(const QString& name);
    void SetControl(QString ocx_name);
    QString GetControl(){ return  m_OcxName;};
    void InitSettings();
    void SetIgnoreEvent(bool ignore) {m_IfIgnoreEvent=ignore;};
    bool IsIgnoreEvent() {return m_IfIgnoreEvent;};
    QRectF Rect();
    QWidget* Widget() {return m_widget;};
    void SetShapeGeometry(QRectF& rect);
    //void SetIsQmlWidget(bool isQmlWidget){ m_isQmlWidget = isQmlWidget; }
    //bool GetIsQmlWidget(){ return m_isQmlWidget; }
private:
    QWidget* CreateCustomWidget(QString name);
    bool IfDesigner();
    void SetWidget(QWidget *widget);
private:
    int m_type;
    QWidget* m_widget;
    QWidget* m_pParent;
    QGraphicsScene * m_pScene;

    CWidgetData* m_pData;
    QString m_PixmapName;
    QString m_Text;
    QString m_OcxName;
    QString m_StyleSheet;
    IPluginWidget* m_pPluginWidget;
    QString m_Tip;
    QString m_Icon;
    QSize m_IconSize;
    QString m_ShortCut;
    bool m_InitShow;
    QFont m_Font;
    bool m_Font_flag;
    bool m_IfIgnoreEvent;
    /*QString m_Ds;
    short m_DsType;*/
    QRectF m_OldRect;
    bool m_IfDesigner;
    bool m_IfFloat;
public:
    friend class CWidgetData;

};


#ifdef WIN32
class QAxWidget;
class DLL_CLASS CAxWidgetData :public CBaseData
{
public:
    CAxWidgetData(QGraphicsItem* item);
    virtual ~CAxWidgetData(){};
    QGraphicsItem* Clone();
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);

public:
    QAxWidget * m_AxWidget;

};

class DLL_CLASS CAxWidgetItem : public QGraphicsWidget
{
    Q_OBJECT
public:
    CAxWidgetItem( QGraphicsItem *parent = 0);
    virtual ~CAxWidgetItem();
protected:
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
private:
    CAxWidgetData* m_pData;

};
#endif


#endif
