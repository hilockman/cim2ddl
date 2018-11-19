

#ifndef GCHARTITEM_H
#define GCHARTITEM_H 

#include "Global.h"
#include "GraphItem.h"
#include "GraphSvgRW.h"
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QLineSeries>
#include "QtCharts/qchart.h"
#include "QtCharts/qabstractaxis.h"
#include "QtCharts/qabstractbarseries.h"
#include "CQScriptWrap.h"
#include "CQWidgetWrap.h"
#include <QDateTime> 

using namespace QT_CHARTS_NAMESPACE;

class DLL_CLASS CGChartData : public CBaseData
{
	Q_OBJECT
public:
	enum Chart_TYPE
	{
		RealTime = 0,
		History
	};

    CGChartData(QGraphicsItem* item);
    virtual ~CGChartData() {};
    virtual QGraphicsItem* Clone() ;
    virtual void Copy(const CBaseData* srcData){};
    virtual void GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList);
    virtual void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual void SaveBaseProperty(CGraphSvgWriter* xio) const;
    virtual void LoadBaseProperty(CGraphSvgReader* xio);
	virtual	QString GetSaveTagName() const { return "rect"; };
	int GetChartType(){ return m_chartType; }
	bool IsAxisYAdapte(){ return m_axisYAdapte; }
public slots:
    QObject* Chart();
    virtual bool SetProperty(const QString& propname, const QVariant& value);
	virtual QVariant Property(QString name, bool allprop = true);
	//return QVariantMap: startTime(time_t),endTime(time_t),timeSpace(s)
	QVariant GetHistorySampleTime();
signals:
	void AddTag(QString tagInfo);
private:
    QString newCategoryLabels;
	int m_chartType;
	uint m_timeSpace;//history curve sample time space, unit: s
	QString m_categoryValues;
	bool m_showCurve;
	bool m_axisYAdapte;
	int m_sampleMode;//0-START,1-MIDDLE,2-END,3-MAX,4-MIN,5-AVERAGE
};

class DLL_CLASS CGChartItem : public QChart
{
    Q_OBJECT

public:
    CGChartItem(QGraphicsItem *parent = 0,QGraphicsScene* scene=0, Qt::WindowFlags wFlags = 0);
    ~CGChartItem(){ };
    enum { Type = Hmi::QtChart };

    int type() const { return Hmi::QtChart; };

signals:
    void TagsValChanged();

public slots :
    void RemoveAllSeries(QStringList tagInfo=QStringList());
    void RemoveAllAxes();
    void CreateDefaultAxes();
    void Resize(qreal w, qreal h);
    void SetMargins(int left, int top, int right, int bottom);
    qreal PlotAreaWidth();
    void Scroll(qreal dx, qreal dy);
    void SetTheme(int themeType);







    void SetAnimationOptions(int options);
    QObject* Legend();


    void SetLegendAlign(QString alignment);

    void ZoomIn();
    void ZoomOut();

	void ZoomIn(qreal x, qreal y, qreal width, qreal height);
    void Zoom(qreal factor);
    void ZoomReset();
    bool IsZoomed();

    QObject* AddSeries(int seriesType);
	void AppendPoint(QObject* seriesObj, qreal x, qreal y, bool adapeY=true);
	void AppendTimePoint(QObject* seriesObj, QString timeStr, QString timeFormatStr, qreal y, bool adapeY=true);
	void AppendTimePoint(QObject* seriesObj, uint timeT, qreal y, bool adapeY=true);
	void AppendTimePoint(QObject* seriesObj, QVariantMap points);//points<time_t, real>
	void ExtremeValue(bool isShow = true);
	void RemoveExtreme(QStringList tagInfo = QStringList());

    QObject* AppendPieSlice(QObject* pieSeriesObj, QString label, qreal value);
    QObject* AppendBarSet(QObject* barSeriesObj, QString label, QStringList values);
    void SetXYSeriesColor(QObject* seriesObj, QString color);
    QString GetXYSeriesColor(QObject* seriesObj);
    void SeriesClear(QObject* seriesObj);
	void SetSeriesName(QObject* seriesObj,QString name);
	void RomoveSeries(QObject* seriesObj);

    QObject* AddAxis(int axisType, QString alignment="bottom");
    void SetLinePenColor(QObject* axisObj, QString color);
    void SetGridLineColor(QObject* axisObj, QString color);
    bool AttachAxis(QObject* seriesObj, QObject* axisObj);
    void BarAxisAppendCategery(QObject* axisObj, QStringList categories);
    void CategoryAxisAppend(QObject* axisObj, QStringList categories, QStringList categoryEndValue);

    QVariant GetTagsVal(){ return (QVariant)m_tagsVal; }

	void ReplaceTagInfo(QString oldTagName,QString tagName);

	QStringList GetAllTags();
	QObject* GetChartByTag(QString tag);

	QObject* GetChartData(){ return (QObject*)m_pData; }

	int GetBarSetCount(QObject* barSetObj);
	void ReplaceBarSetValue(QObject* barSetObj, int index, qreal value);
	void ShowCurve(bool showCurve);

	/*extend:true , to make value is visiable
	* extend:false ,do not care value, to calc the max and min of all series
	*/
	void AxisYAdape(qreal value, bool extend = true);
private slots :
    void OnTagsValChanged();
    void HandleMarkerClicked();
	void ShowPieSliceHighlight(bool);
	void ShowBarHovered(bool status, int index);
	void ShowCurveTooltip(QPointF point, bool state);
public:
	void SetTagsValue(QMap<QString, QVariant> tagsVal){ m_tagsVal = tagsVal; if (m_pData->GetChartType() ==0 )emit TagsValChanged(); };
    void SetSeriesType(int type);
    int GetSeriesType(){ return m_seriesType; }
    bool IfDesigner();
    QMap<QString, QObject*> GetTagsChart(){ return m_tagsChart; }
    void InsertTagChart(QString tag, QObject* chart){ m_tagsChart.insert(tag, chart); };
    QList<QAbstractAxis*> GetAddAxes(){ return m_addAxes;}
    void InsertAdditionalAxis(QAbstractAxis* axis, int index = -1);
    void RemoveAdditionalAxis(int retainCount);
    void ConnectMarkers();
	
	void CorsorVisible(bool show){
		if (m_tipVLine != NULL){
			m_tipVLine->setVisible(show);
		}
	};
	QDateTime getDateTime(const QString &value, const QString &format);
protected:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
private:
    CGChartData* m_pData;
    int m_seriesType;
    QMap<QString, QObject*> m_tagsChart;
    QMap<QString, QVariant> m_tagsVal;
    QList<QAbstractAxis*> m_addAxes;
	QGraphicsTextItem * m_tooltip;
	QGraphicsLineItem * m_tipVLine;
	QPointF m_startPos;
	QRubberBand* m_rubberBand;
	bool m_isMoving;
	QMap<QString, QObject*> m_tagsExtremeTips;
};

#endif
