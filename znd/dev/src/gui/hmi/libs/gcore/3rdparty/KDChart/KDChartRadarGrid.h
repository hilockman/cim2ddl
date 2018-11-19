#ifndef KDCHARTRADARGrid_H
#define KDCHARTRADARGrid_H 


#include "KDChartAbstractGrid.h"

namespace KDChart {

    class PaintContext;
    class RadarCoordinatePlane;
    class RadarGrid : public AbstractGrid
    {
    public:
        RadarGrid() : AbstractGrid() {}
        virtual ~RadarGrid() {}

        virtual void drawGrid( PaintContext* context );

    private:
        virtual DataDimensionsList calculateGrid(
            const DataDimensionsList& rawDataDimensions ) const;
    };

}

#endif
