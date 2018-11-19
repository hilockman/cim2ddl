#ifndef KDCHARTABSTRACTCARTESIANDIAGRAM_H
#define KDCHARTABSTRACTCARTESIANDIAGRAM_H 

#include "KDChartCartesianCoordinatePlane.h"
#include "KDChartAbstractDiagram.h"
#include "KDChartCartesianAxis.h"

namespace KDChart {

    class GridAttributes;
    class KDCHART_EXPORT AbstractCartesianDiagram : public AbstractDiagram
    {
        Q_OBJECT
        Q_DISABLE_COPY( AbstractCartesianDiagram )
        KDCHART_DECLARE_DERIVED_DIAGRAM( AbstractCartesianDiagram, CartesianCoordinatePlane )

    public:
        explicit AbstractCartesianDiagram ( QWidget* parent = 0, CartesianCoordinatePlane* plane = 0 );
        virtual ~AbstractCartesianDiagram();




        bool compare( const AbstractCartesianDiagram* other ) const;

#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)
        virtual const int numberOfAbscissaSegments () const = 0;
        virtual const int numberOfOrdinateSegments () const = 0;
#else
        virtual int numberOfAbscissaSegments () const = 0;
        virtual int numberOfOrdinateSegments () const = 0;
#endif
        virtual void addAxis( CartesianAxis * axis );
        virtual void takeAxis( CartesianAxis * axis );



        virtual KDChart::CartesianAxisList axes () const;





        virtual void layoutPlanes();

        virtual void setCoordinatePlane( AbstractCoordinatePlane* plane );
        virtual void setReferenceDiagram( AbstractCartesianDiagram* diagram, const QPointF& offset = QPointF() );




        virtual AbstractCartesianDiagram* referenceDiagram() const;




        virtual QPointF referenceDiagramOffset() const;


        void setModel( QAbstractItemModel* model );

        void setRootIndex( const QModelIndex& index );

        void setAttributesModel( AttributesModel* model );

    protected:

        virtual qreal threeDItemDepth( const QModelIndex& index ) const = 0;

        virtual qreal threeDItemDepth( int column ) const = 0;
    };

}

#endif
