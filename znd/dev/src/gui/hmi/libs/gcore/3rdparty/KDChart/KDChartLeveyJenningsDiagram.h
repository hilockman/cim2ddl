#ifndef KDCHARTLEVEYJENNINGSDIAGRAM_H
#define KDCHARTLEVEYJENNINGSDIAGRAM_H 

#include "KDChartLineDiagram.h"
#include "KDChartLeveyJenningsCoordinatePlane.h"

QT_BEGIN_NAMESPACE
class QPainter;
class QPolygonF;
class QSvgRenderer;
QT_END_NAMESPACE

namespace KDChart {

    class ThreeDLineAttributes;






class KDCHART_EXPORT LeveyJenningsDiagram : public LineDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( LeveyJenningsDiagram )


    KDCHART_DECLARE_DERIVED_DIAGRAM( LeveyJenningsDiagram, LeveyJenningsCoordinatePlane )


public:
    explicit LeveyJenningsDiagram( QWidget* parent = 0, LeveyJenningsCoordinatePlane* plane = 0 );
    virtual ~LeveyJenningsDiagram();

    virtual LineDiagram * clone() const;

    enum Symbol
    {
        OkDataPoint,
        NotOkDataPoint,
        LotChanged,
        SensorChanged,
        FluidicsPackChanged
    };




    bool compare( const LeveyJenningsDiagram* other ) const;

    void setLotChangedSymbolPosition( Qt::Alignment pos );
    Qt::Alignment lotChangedSymbolPosition() const;

    void setFluidicsPackChangedSymbolPosition( Qt::Alignment pos );
    Qt::Alignment fluidicsPackChangedSymbolPosition() const;

    void setSensorChangedSymbolPosition( Qt::Alignment pos );
    Qt::Alignment sensorChangedSymbolPosition() const;

    void setExpectedMeanValue( float meanValue );
    float expectedMeanValue() const;

    void setExpectedStandardDeviation( float sd );
    float expectedStandardDeviation() const;

    float calculatedMeanValue() const;
    float calculatedStandardDeviation() const;

    void setFluidicsPackChanges( const QVector< QDateTime >& changes );
    QVector< QDateTime > fluidicsPackChanges() const;

    void setSensorChanges( const QVector< QDateTime >& changes );
    QVector< QDateTime > sensorChanges() const;

    void setScanLinePen( const QPen& pen );
    QPen scanLinePen() const;

    void setSymbol( Symbol symbol, const QString& filename );
    QString symbol( Symbol symbol ) const;


    void setModel( QAbstractItemModel* model );

    QPair< QDateTime, QDateTime > timeRange() const;
    void setTimeRange( const QPair< QDateTime, QDateTime >& timeRange );

protected:
    void paint( PaintContext* paintContext );
    void drawChanges( PaintContext* paintContext );

    virtual void drawDataPointSymbol( PaintContext* paintContext, const QPointF& pos, bool ok );
    virtual void drawLotChangeSymbol( PaintContext* paintContext, const QPointF& pos );
    virtual void drawSensorChangedSymbol( PaintContext* paintContext, const QPointF& pos );
    virtual void drawFluidicsPackChangedSymbol( PaintContext* paintContext, const QPointF& pos );

    virtual QRectF iconRect() const;

    QSvgRenderer* iconRenderer( Symbol symbol );


    const QPair<QPointF, QPointF> calculateDataBoundaries() const;

protected Q_SLOTS:
    void calculateMeanAndStandardDeviation() const;
};

}

#endif
