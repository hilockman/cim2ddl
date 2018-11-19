#ifndef KDCHARTPOLARDIAGRAM_H
#define KDCHARTPOLARDIAGRAM_H 


#include "KDChartPosition.h"
#include "KDChartAbstractPolarDiagram.h"

QT_BEGIN_NAMESPACE
class QPolygonF;
QT_END_NAMESPACE

namespace KDChart {




class KDCHART_EXPORT PolarDiagram : public AbstractPolarDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( PolarDiagram )
    KDCHART_DECLARE_DERIVED_DIAGRAM( PolarDiagram, PolarCoordinatePlane )

public:
    explicit PolarDiagram(
        QWidget* parent = 0, PolarCoordinatePlane* plane = 0 );
    virtual ~PolarDiagram();

protected:


    virtual void paint ( PaintContext* paintContext );

public:

    virtual void resize ( const QSizeF& area );



    virtual qreal valueTotals () const;

    virtual qreal numberOfValuesPerDataset() const;

    virtual qreal numberOfGridRings() const;

    virtual PolarDiagram * clone() const;


    void setZeroDegreePosition( int degrees );

    int zeroDegreePosition() const;

    void setRotateCircularLabels( bool rotateCircularLabels );
    bool rotateCircularLabels() const;




    void setCloseDatasets( bool closeDatasets );
    bool closeDatasets() const;

    void setShowDelimitersAtPosition( Position position,
                                      bool showDelimiters );
    void setShowLabelsAtPosition( Position position,
                                  bool showLabels );

    bool showDelimitersAtPosition( Position position ) const;

    bool showLabelsAtPosition( Position position ) const;

    virtual void paint ( PaintContext* paintContext,
                         bool calculateListAndReturnScale,
                         qreal& newZoomX, qreal& newZoomY );

protected:

    virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent ( QPaintEvent* );
    void resizeEvent ( QResizeEvent* );
    virtual void paintPolarMarkers( PaintContext* ctx, const QPolygonF& polygon );

};

}


#endif
