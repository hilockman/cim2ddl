#ifndef KDCHARTCARTESIANGRID_H
#define KDCHARTCARTESIANGRID_H 

#include "KDChartCartesianCoordinatePlane.h"
#include "KDChartAbstractGrid.h"

namespace KDChart {

    class PaintContext;
    class CartesianCoordinatePlane;
    class CartesianGrid : public AbstractGrid
    {
    public:
        CartesianGrid();
        virtual ~CartesianGrid();

        int minimalSteps() const;
        void setMinimalSteps(int minsteps);

        int maximalSteps() const;
        void setMaximalSteps(int maxsteps);

        void drawGrid( PaintContext* context );

    private:
        int m_minsteps;
        int m_maxsteps;

        DataDimensionsList calculateGrid(
            const DataDimensionsList& rawDataDimensions ) const;
        virtual DataDimension calculateGridXY(
            const DataDimension& rawDataDimension,
            Qt::Orientation orientation,
            bool adjustLower, bool adjustUpper ) const;
        virtual void calculateStepWidth(
            qreal start, qreal end,
            const QList<qreal>& granularities,
            Qt::Orientation orientation,
            qreal& stepWidth, qreal& subStepWidth,
            bool adjustLower, bool adjustUpper ) const;
    };

}

#endif
