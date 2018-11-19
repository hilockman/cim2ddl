#ifndef KDCHART_POLAR_COORDINATEPLANE_H
#define KDCHART_POLAR_COORDINATEPLANE_H 

#include "KDChartAbstractCoordinatePlane.h"

namespace KDChart {

    class Chart;
    class PaintContext;




    class KDCHART_EXPORT PolarCoordinatePlane : public AbstractCoordinatePlane
    {
        Q_OBJECT

        Q_DISABLE_COPY( PolarCoordinatePlane )
        KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( PolarCoordinatePlane, Chart* )

    public:
        struct CoordinateTransformation;
        typedef QList<CoordinateTransformation> CoordinateTransformationList;

        explicit PolarCoordinatePlane ( Chart* parent = 0 );
        ~PolarCoordinatePlane();

        void addDiagram ( AbstractDiagram* diagram );

        const QPointF translate ( const QPointF& diagramPoint ) const;
        const QPointF translatePolar ( const QPointF& diagramPoint ) const;
        void setStartPosition( qreal degrees );



        qreal startPosition() const;

        virtual qreal zoomFactorX() const;
        virtual qreal zoomFactorY() const;

        virtual void setZoomFactors( qreal factorX, qreal factorY );
        virtual void setZoomFactorX( qreal factor );
        virtual void setZoomFactorY( qreal factor );

        virtual QPointF zoomCenter() const;

        virtual void setZoomCenter( const QPointF& center );
        void setGridAttributes( bool circular, const GridAttributes & );
        void resetGridAttributes( bool circular );
        const GridAttributes gridAttributes( bool circular ) const;
        bool hasOwnGridAttributes( bool circular ) const;

        qreal angleUnit() const;
        qreal radiusUnit() const;


        virtual void paint( QPainter* );

    protected:
        virtual DataDimensionsList getDataDimensionsList() const;
        void paintEvent ( QPaintEvent* );
        void resizeEvent ( QResizeEvent* );

        void layoutDiagrams();
    protected Q_SLOTS:
        void slotLayoutChanged( AbstractDiagram* diagram );
        void adjustZoomAndRepaint();

    private:
        void setHasOwnGridAttributes( bool circular, bool on );
    };

}

#endif
