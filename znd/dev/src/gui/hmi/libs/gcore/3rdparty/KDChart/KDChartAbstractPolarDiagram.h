#ifndef KDCHARTABSTRACTPOLARDIAGRAM_H
#define KDCHARTABSTRACTPOLARDIAGRAM_H 

#include "KDChartPolarCoordinatePlane.h"
#include "KDChartAbstractDiagram.h"

namespace KDChart {

    class GridAttributes;




    class KDCHART_EXPORT AbstractPolarDiagram : public AbstractDiagram
    {
        Q_OBJECT
        Q_DISABLE_COPY( AbstractPolarDiagram )
        KDCHART_DECLARE_DERIVED_DIAGRAM( AbstractPolarDiagram, PolarCoordinatePlane )

    public:
        explicit AbstractPolarDiagram (
            QWidget* parent = 0, PolarCoordinatePlane* plane = 0 );
        virtual ~AbstractPolarDiagram() {}

        virtual qreal valueTotals () const = 0;
        virtual qreal numberOfValuesPerDataset() const = 0;
        virtual qreal numberOfDatasets() const { return 1; };
        virtual qreal numberOfGridRings() const = 0;

        const PolarCoordinatePlane * polarCoordinatePlane() const;

        int columnCount() const;
        int rowCount() const;
    };

}

#endif
