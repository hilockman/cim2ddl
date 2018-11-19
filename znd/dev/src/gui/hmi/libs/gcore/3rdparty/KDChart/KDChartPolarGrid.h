#ifndef KDCHARTPOLARGrid_H
#define KDCHARTPOLARGrid_H 

#include "KDChartPolarCoordinatePlane.h"
#include "KDChartAbstractGrid.h"

namespace KDChart {

    class PaintContext;
    class PolarCoordinatePlane;
    class PolarGrid : public AbstractGrid
    {
    public:
        PolarGrid() : AbstractGrid() {}
        virtual ~PolarGrid() {}

        virtual void drawGrid( PaintContext* context );

    private:
        virtual DataDimensionsList calculateGrid(
            const DataDimensionsList& rawDataDimensions ) const;
    };

}

#endif
