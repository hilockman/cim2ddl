#ifndef KDCHARTRINGDIAGRAM_H
#define KDCHARTRINGDIAGRAM_H 

#include "KDChartAbstractPieDiagram.h"

namespace KDChart {




class KDCHART_EXPORT RingDiagram : public AbstractPieDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( RingDiagram )
    KDCHART_DECLARE_DERIVED_DIAGRAM( RingDiagram, PolarCoordinatePlane )

public:
    explicit RingDiagram(
        QWidget* parent = 0, PolarCoordinatePlane* plane = 0 );
    virtual ~RingDiagram();

protected:


    virtual void paint( PaintContext* paintContext );
public:

    virtual void resize( const QSizeF& area );



    virtual qreal valueTotals() const;

    virtual qreal numberOfValuesPerDataset() const;
    virtual qreal numberOfDatasets() const;

    virtual qreal numberOfGridRings() const;

    qreal valueTotals( int dataset ) const;

    virtual RingDiagram * clone() const;




    bool compare( const RingDiagram* other ) const;

    void setRelativeThickness( bool relativeThickness );
    bool relativeThickness() const;

    virtual void setExpandWhenExploded( bool expand );
    virtual bool expandWhenExploded() const;

protected:

    virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent( QPaintEvent* );
    void resizeEvent( QResizeEvent* );

private:
    void drawOneSlice( QPainter* painter, uint dataset, uint slice, qreal granularity );
    void drawPieSurface( QPainter* painter, uint dataset, uint slice, qreal granularity );
    QPointF pointOnEllipse( const QRectF& rect, int dataset, int slice, bool outer, qreal angle,
                            qreal totalGapFactor, qreal totalExplodeFactor );
};

}

#endif
