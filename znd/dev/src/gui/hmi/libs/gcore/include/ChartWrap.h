

#ifndef CHARTWRAP_H
#define CHARTWRAP_H 

#include <KDChartChart>
#include <KDChartAbstractCoordinatePlane>
#include "BaseData.h"
#include "WidgetItem.h"


namespace KDChart
{
class PieDiagram;
class BarDiagram;
class StockDiagram;
class PolarDiagram;
class AbstractDiagram;
class DataValueAttributes;
};

class QItemSelectionModel;

class DLL_CLASS CBaseChartData :public CWidgetData
{
public:
    friend class CBaseChartWidget;
    CBaseChartData(QGraphicsItem* item);
    virtual ~CBaseChartData() {};

    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool SetProperty(const QString& propname,const QVariant& value);

    virtual bool GetIsShow3D() const = 0;
    virtual void SetShow3D(bool show) = 0;

    virtual KDChart::AbstractDiagram* GetDiagram() const = 0;
    virtual bool GetIsShowData() const ;
    virtual void SetShowData(bool show);

    virtual QFont GetDataFont() const ;
    virtual void SetDataFont(const QFont& f);

    virtual QColor GetDataColor() const ;
    virtual void SetDataColor(const QColor& c);
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual void SaveSubProperty(CGraphSvgWriter* xio) const;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);
    virtual void LoadSubProperty(CGraphSvgReader* xio);
};

class CChartTableModel;
class CBaseChartWidget : public KDChart::Chart
{
    Q_OBJECT

public:
    CBaseChartWidget();
    ~CBaseChartWidget();

protected slots:
    void OnItemClicked(const QModelIndex& index);

protected:
    CChartTableModel* m_model;
    QItemSelectionModel* m_selectModel;
};

class CPieChartWidget : public CBaseChartWidget
{
    Q_OBJECT

    friend class CPieChartData;
public:
    CPieChartWidget();

private:
    KDChart::PieDiagram* m_pieDiagram;
};

class DLL_CLASS CPieChartData :public CBaseChartData
{
public:
    CPieChartData(QGraphicsItem* item);
    virtual ~CPieChartData() {};
    virtual QGraphicsItem* Clone();
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool SetProperty(const QString& propname,const QVariant& value);

    virtual bool GetIsShow3D() const;
    virtual void SetShow3D(bool show);

    bool GetIsExplode() const;
    void SetExplode(bool explode);

    virtual KDChart::AbstractDiagram* GetDiagram() const {return m_pieWidget->coordinatePlane()->diagram();};

    void SetChartWidget(CPieChartWidget* w) {m_pieWidget = w;};
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);
private:
    CPieChartWidget* m_pieWidget;
};

class CBarChartWidget : public CBaseChartWidget
{
    Q_OBJECT

    friend class CBarChartData;
public:
    CBarChartWidget();

private:
    KDChart::BarDiagram* m_barDiagram;
};

class DLL_CLASS CBarChartData :public CBaseChartData
{
public:
    friend class CBarChartWidget;
    CBarChartData(QGraphicsItem* item);
    virtual ~CBarChartData() {};
    virtual QGraphicsItem* Clone();
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool SetProperty(const QString& propname,const QVariant& value);
    void SetChartWidget(CBarChartWidget* w) {m_barWidget = w;};

    virtual bool GetIsShow3D() const;
    virtual void SetShow3D(bool show);

    bool GetIsShowAxis() const;
    void SetShowAxis(bool show);

    void SetAxisTextColor(const QColor& f);
    QColor GetAxisTextColor() const ;

    void SetAxisTextFont(const QFont& f);
    QFont GetAxisTextFont() const ;

    void SetBarWidth(qreal width);
    qreal GetBarWidth() const;

    void SetBarOrientation(int orientation);
    QMap<QString, QVariant> GetBarOrientation() const;

    virtual KDChart::AbstractDiagram* GetDiagram() const {return m_barWidget->coordinatePlane()->diagram();};
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);

private:
    CBarChartWidget* m_barWidget;

};

class CStockChartWidget : public CBaseChartWidget
{
    Q_OBJECT

    friend class CStockChartData;
public:
    CStockChartWidget();
    void SetDataModel(const QString &filename = QString());
private:
    KDChart::StockDiagram* m_stockDiagram;
};

class DLL_CLASS CStockChartData :public CBaseChartData
{
public:
    CStockChartData(QGraphicsItem* item);
    virtual ~CStockChartData() {};
    virtual QGraphicsItem* Clone();
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool SetProperty(const QString& propname,const QVariant& value);

    virtual bool GetIsShow3D() const;
    virtual void SetShow3D(bool show);

    int GetStockChartType() const;
    void SetStockChartType(const int &text);

    int GetPerspectiveAngle() const;
    void SetPerspectiveAngle(const int &angle);

    double GetPerspectiveDepth() const;
    void SetPerspectiveDepth(const int &depth);

    bool GetIsUseShadowColors() const;
    void SetUseShadowColors(const bool useShadowColors);


    virtual KDChart::AbstractDiagram* GetDiagram() const {return m_stockWidget->coordinatePlane()->diagram();};

    void SetChartWidget(CStockChartWidget* w) {m_stockWidget = w;};
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);
private:
    CStockChartWidget* m_stockWidget;
};

#if 0
class CPolarChartWidget:CBaseChartWidget
{
    Q_OBJECT
    friend class CPolarChartData;
public:
    CPolarChartWidget();
private:
    KDChart::PolarDiagram* m_polarDiagram;
};

class DLL_CLASS CPolarChartData:public CBaseChartData
{
public:
    CPolarChartData(QGraphicsItem* item);
    virtual ~CPolarChartData() {};
    virtual QGraphicsItem * Clone();
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool SetProperty(const QString& propname,const QVariant& value);

    virtual bool GetIsShow3D() const;
    virtual void SetShow3D(bool show);

    QString GetBackGroundBrush() const;
    void SetBackGroundBrush(int r,int g,int b,int a = 255);
    void SetBackGroundBrush(const QColor & color);
    void SetBackGroundBrush(const QBrush & brush);
    void SetBackGroundBrush(const QString & brush);

    bool GetMarkerState() const;
    void SetMarkerState(const bool mark);

    int GetMarkerStyle() const;
    void SetMarkerStyle(const int style);

    QSize GetMarkerSize() const;
    void SetMarkerSize(const QSize size);
    void SetMarkerSize(const int w,const int h);

    int GetReferencePosition() const;
    void SetReferencePostion(const int pos);

    int GetAlignment() const;
    void SetAlignment(const int align);

    int GetStartPosition() const;
    void SetStartPosition(const double angle);

    virtual KDChart::AbstractDiagram* GetDiagram() const {return m_polarWidget->coordinatePlane()->diagram();};

    void SetChartWidget(CPolarChartWidget* w) {m_polarWidget = w;};
protected:
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const ;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);
private:
    void SetDataValueAtrributes(const DataValueAttributes *dva);
    CPolarChartWidget* m_polarWidget;
};
#endif
#endif
