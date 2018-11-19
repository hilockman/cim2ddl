#ifndef KDCHARTPIEDIAGRAM_H
#define KDCHARTPIEDIAGRAM_H 

#include "KDChartAbstractPieDiagram.h"

namespace KDChart {

    class LabelPaintCache;




class KDCHART_EXPORT PieDiagram : public AbstractPieDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( PieDiagram )
    KDCHART_DECLARE_DERIVED_DIAGRAM( PieDiagram, PolarCoordinatePlane )

public:
    explicit PieDiagram(
        QWidget* parent = 0, PolarCoordinatePlane* plane = 0 );
    virtual ~PieDiagram();

protected:


    virtual void paint( PaintContext* paintContext );

public:



    enum LabelDecoration {
        NoDecoration = 0,
        FrameDecoration = 1,
        LineFromSliceDecoration = 2
    };
    Q_DECLARE_FLAGS( LabelDecorations, LabelDecoration )

    void setLabelDecorations( LabelDecorations decorations );

    LabelDecorations labelDecorations() const;


    void setLabelCollisionAvoidanceEnabled( bool enabled );

    bool isLabelCollisionAvoidanceEnabled() const;


    virtual void resize ( const QSizeF& area );



    virtual qreal valueTotals () const;

    virtual qreal numberOfValuesPerDataset() const;

    virtual qreal numberOfGridRings() const;

    virtual PieDiagram * clone() const;

protected:

    virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent( QPaintEvent* );
    void resizeEvent( QResizeEvent* );

private:

    void placeLabels( PaintContext* paintContext );

    void shuffleLabels( QRectF* textBoundingRect );
    void paintInternal( PaintContext* paintContext );
    void drawSlice( QPainter* painter, const QRectF& drawPosition, uint slice );
    void drawSliceSurface( QPainter* painter, const QRectF& drawPosition, uint slice );
    void addSliceLabel( LabelPaintCache* lpc, const QRectF& drawPosition, uint slice );
    void draw3DEffect( QPainter* painter, const QRectF& drawPosition, uint slice );
    void draw3dCutSurface( QPainter* painter,
        const QRectF& rect,
        qreal threeDHeight,
        qreal angle );
    void draw3dOuterRim( QPainter* painter,
        const QRectF& rect,
        qreal threeDHeight,
        qreal startAngle,
        qreal endAngle );
    void calcSliceAngles();
    void calcPieSize( const QRectF &contentsRect );
    QRectF twoDPieRect( const QRectF &contentsRect, const ThreeDPieAttributes& threeDAttrs ) const;
    QRectF explodedDrawPosition( const QRectF& drawPosition, uint slice ) const;
    uint findSliceAt( qreal angle, int columnCount );
    uint findLeftSlice( uint slice, int columnCount );
    uint findRightSlice( uint slice, int columnCount );
    QPointF pointOnEllipse( const QRectF& boundingBox, qreal angle );
};

Q_DECLARE_OPERATORS_FOR_FLAGS( PieDiagram::LabelDecorations )

}
#endif
