#ifndef KDCHARTABSTRACTPIEDIAGRAM_H
#define KDCHARTABSTRACTPIEDIAGRAM_H 

#include "KDChartAbstractPolarDiagram.h"

namespace KDChart {
    class PieAttributes;
    class ThreeDPieAttributes;




class KDCHART_EXPORT AbstractPieDiagram : public AbstractPolarDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( AbstractPieDiagram )
    KDCHART_DECLARE_DERIVED_DIAGRAM( AbstractPieDiagram, PolarCoordinatePlane )

public:
    explicit AbstractPieDiagram(
        QWidget* parent = 0, PolarCoordinatePlane* plane = 0 );
    virtual ~AbstractPieDiagram();




    bool compare( const AbstractPieDiagram* other ) const;






    void setGranularity( qreal value );


    qreal granularity() const;


    void setStartPosition( int degrees );

    int startPosition() const;




    void setAutoRotateLabels( bool autoRotate );


    bool autoRotateLabels() const;

    void setPieAttributes( const PieAttributes & a );
    void setPieAttributes( int column,
                           const PieAttributes & a );
    void setPieAttributes( const QModelIndex & index,
                           const PieAttributes & a );
    PieAttributes pieAttributes() const;
    PieAttributes pieAttributes( int column ) const;
    PieAttributes pieAttributes( const QModelIndex & index ) const;

    void setThreeDPieAttributes( const ThreeDPieAttributes & a );
    void setThreeDPieAttributes( int column,
                                 const ThreeDPieAttributes & a );
    void setThreeDPieAttributes( const QModelIndex & index,
                                 const ThreeDPieAttributes & a );
    ThreeDPieAttributes threeDPieAttributes() const;
    ThreeDPieAttributes threeDPieAttributes( int column ) const;
    ThreeDPieAttributes threeDPieAttributes( const QModelIndex & index ) const;
};

}

#endif
