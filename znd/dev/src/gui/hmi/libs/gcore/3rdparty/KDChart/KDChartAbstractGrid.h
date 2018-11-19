#ifndef KDCHARTABSTRACTGRID_H
#define KDCHARTABSTRACTGRID_H 

#include <QPair>

#include "KDChartAbstractCoordinatePlane.h"
#include "KDChartGridAttributes.h"
#include "KDChartAbstractDiagram.h"
#include "KDChartCartesianAxis.h"

namespace KDChart {

    class PaintContext;
    class AbstractGrid
    {
    public:
        virtual ~AbstractGrid();
    protected:
        AbstractGrid ();


    public:





        DataDimensionsList updateData( AbstractCoordinatePlane* plane );
        virtual void drawGrid( PaintContext* context ) = 0;







        void setNeedRecalculate();







        static bool isBoundariesValid(const QRectF& r );







        static bool isBoundariesValid(const QPair<QPointF,QPointF>& b );
        static bool isBoundariesValid(const DataDimensionsList& l );




        static bool isValueValid(const qreal& r );





        static void adjustLowerUpperRange(
                qreal& start, qreal& end,
                qreal stepWidth,
                bool adjustLower, bool adjustUpper );







        static const DataDimension adjustedLowerUpperRange(
                const DataDimension& dim,
                bool adjustLower, bool adjustUpper );

        GridAttributes gridAttributes;

    protected:
        DataDimensionsList mDataDimensions;
        AbstractCoordinatePlane* mPlane;

    private:
        virtual DataDimensionsList calculateGrid( const DataDimensionsList& rawDataDimensions ) const = 0;
        DataDimensionsList mCachedRawDataDimensions;
    };

}

#endif
