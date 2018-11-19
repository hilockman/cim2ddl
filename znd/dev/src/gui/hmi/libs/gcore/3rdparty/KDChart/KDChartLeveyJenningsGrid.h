#ifndef KDCHARTLEVEYJENNINGSGRID_H
#define KDCHARTLEVEYJENNINGSGRID_H 

#include "KDChartCartesianGrid.h"

namespace KDChart {

    class PaintContext;
    class LeveyJenningsGrid : public CartesianGrid
    {
    public:
        LeveyJenningsGrid() : CartesianGrid() {}
        virtual ~LeveyJenningsGrid() {}

        void drawGrid( PaintContext* context );

    private:
        DataDimensionsList calculateGrid( const DataDimensionsList& rawDataDimensions ) const;
        DataDimension calculateGridXY( const DataDimension& rawDataDimension,
                          Qt::Orientation orientation, bool adjustLower, bool adjustUpper ) const;
        void calculateStepWidth( qreal start_, qreal end_, const QList<qreal>& granularities, Qt::Orientation orientation,
                                 qreal& stepWidth, qreal& subStepWidth, bool adjustLower, bool adjustUpper ) const;
    };

}

#endif
