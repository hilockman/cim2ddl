#ifndef KDCHARTRADARDIAGRAM_H
#define KDCHARTRADARDIAGRAM_H 


#include "KDChartPosition.h"
#include "KDChartPolarDiagram.h"
#include "KDChartRadarCoordinatePlane.h"

QT_BEGIN_NAMESPACE
class QPolygonF;
QT_END_NAMESPACE

namespace KDChart {




class KDCHART_EXPORT RadarDiagram : public AbstractPolarDiagram
{
  Q_OBJECT

  Q_DISABLE_COPY( RadarDiagram )
  KDCHART_DECLARE_DERIVED_DIAGRAM( RadarDiagram, RadarCoordinatePlane )

public:
    explicit RadarDiagram(
        QWidget* parent = 0, RadarCoordinatePlane* plane = 0 );
    virtual ~RadarDiagram();

    virtual void paint ( PaintContext* paintContext,
                         bool calculateListAndReturnScale,
                         qreal& newZoomX, qreal& newZoomY );

    virtual void resize ( const QSizeF& area );


    virtual qreal valueTotals () const;

    virtual qreal numberOfValuesPerDataset() const;

    virtual qreal numberOfGridRings() const;




    void setReverseData( bool val );
    bool reverseData();

    virtual RadarDiagram * clone() const;





    void setCloseDatasets( bool closeDatasets );
    bool closeDatasets() const;
    qreal fillAlpha() const;
    void setFillAlpha(qreal alphaF);

protected:

    virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent ( QPaintEvent* );
    void resizeEvent ( QResizeEvent* );
    virtual void paint ( PaintContext* paintContext );

};

}

#endif
