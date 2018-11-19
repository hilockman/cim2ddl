#ifndef KDCHART_RADAR_COORDINATEPLANE_H
#define KDCHART_RADAR_COORDINATEPLANE_H 

#include "KDChartPolarCoordinatePlane.h"

namespace KDChart {

    class Chart;




    class KDCHART_EXPORT RadarCoordinatePlane : public PolarCoordinatePlane
    {
        Q_OBJECT

        Q_DISABLE_COPY( RadarCoordinatePlane )
        KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( RadarCoordinatePlane, Chart* )

    public:

        explicit RadarCoordinatePlane ( Chart* parent = 0 );
        ~RadarCoordinatePlane();
        void setTextAttributes( const TextAttributes & attr );
        const TextAttributes textAttributes() const;

    };

}

#endif
