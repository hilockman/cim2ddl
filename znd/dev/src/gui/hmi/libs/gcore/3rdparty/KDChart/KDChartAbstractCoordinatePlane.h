#ifndef KDCHARTABSTRACTCOORDINATEPLANE_H
#define KDCHARTABSTRACTCOORDINATEPLANE_H 

#include <QObject>
#include <QList>

#include "KDChartAbstractArea.h"
#include "KDChartAbstractDiagram.h"
#include "KDChartEnums.h"

namespace KDChart {

    class Chart;
    class GridAttributes;
    class DataDimension;

    typedef QList<DataDimension> DataDimensionsList;




    class KDCHART_EXPORT AbstractCoordinatePlane : public AbstractArea
    {
        Q_OBJECT

        KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( AbstractCoordinatePlane, Chart* )

    friend class AbstractGrid;

    public:
        enum AxesCalcMode { Linear, Logarithmic };

    protected:
        explicit AbstractCoordinatePlane ( Chart* parent = 0 );

    public:
        virtual ~AbstractCoordinatePlane();







        virtual void addDiagram ( AbstractDiagram* diagram );
        virtual void replaceDiagram ( AbstractDiagram* diagram, AbstractDiagram* oldDiagram = 0 );
        virtual void takeDiagram( AbstractDiagram* diagram );




        AbstractDiagram* diagram();




        AbstractDiagramList diagrams();




        ConstAbstractDiagramList diagrams() const;




        virtual void layoutDiagrams() = 0;







        virtual const QPointF translate ( const QPointF& diagramPoint ) const = 0;




        bool isRubberBandZoomingEnabled() const;




        void setRubberBandZoomingEnabled( bool enable );





        virtual qreal zoomFactorX() const { return 1.0; }





        virtual qreal zoomFactorY() const { return 1.0; }





        virtual void setZoomFactors( qreal factorX, qreal factorY ) { Q_UNUSED( factorX ); Q_UNUSED( factorY ); }






        virtual void setZoomFactorX( qreal factor ) { Q_UNUSED( factor ); }






        virtual void setZoomFactorY( qreal factor ) { Q_UNUSED( factor ); }





        virtual QPointF zoomCenter() const { return QPointF(0.0, 0.0); }






        virtual void setZoomCenter( const QPointF& center ) { Q_UNUSED( center ); }
        void setGlobalGridAttributes( const GridAttributes & );






        GridAttributes globalGridAttributes() const;
        DataDimensionsList gridDimensionsList();
        void setReferenceCoordinatePlane( AbstractCoordinatePlane * plane );
        AbstractCoordinatePlane * referenceCoordinatePlane() const;





        bool isCornerSpacersEnabled() const;




        void setCornerSpacersEnabled( bool enable );

        virtual AbstractCoordinatePlane* sharedAxisMasterPlane( QPainter* p = 0 );



        virtual bool isEmpty() const;

        virtual Qt::Orientations expandingDirections() const;

        virtual QSize maximumSize() const;

        virtual QSize minimumSize() const;

        virtual QSize sizeHint() const;






        virtual void setGeometry( const QRect& r );

        virtual QRect geometry() const;

        virtual void mousePressEvent( QMouseEvent* event );
        virtual void mouseDoubleClickEvent( QMouseEvent* event );
        virtual void mouseMoveEvent( QMouseEvent* event );
        virtual void mouseReleaseEvent( QMouseEvent* event );




        void setParent( Chart* parent );
        Chart* parent();
        const Chart* parent() const;






#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)
        const bool isVisiblePoint( const QPointF& point ) const;
#else
        bool isVisiblePoint( const QPointF& point ) const;
#endif

    public Q_SLOTS:



        void update();



        void relayout();



        void layoutPlanes();



        void setGridNeedsRecalculate();

    Q_SIGNALS:

        void destroyedCoordinatePlane( AbstractCoordinatePlane* );


        void needUpdate();


        void needRelayout();


        void needLayoutPlanes();


        void propertiesChanged();

        void boundariesChanged();






        void geometryChanged( QRect, QRect );

    private:
    Q_SIGNALS:



        void internal_geometryChanged( QRect, QRect );

        void viewportCoordinateSystemChanged();

    protected:
        virtual DataDimensionsList getDataDimensionsList() const = 0;


    };
    class DataDimension{
    public:
        DataDimension()
            : start( 1.0 )
            , end( 10.0 )
            , isCalculated( false )
            , calcMode( AbstractCoordinatePlane::Linear )
            , sequence( KDChartEnums::GranularitySequence_10_20 )
            , stepWidth( 1.0 )
            , subStepWidth( 0.0 )
        {}
        DataDimension( qreal start_,
                       qreal end_,
                       bool isCalculated_,
                       AbstractCoordinatePlane::AxesCalcMode calcMode_,
                       KDChartEnums::GranularitySequence sequence_,
                       qreal stepWidth_=0.0,
                       qreal subStepWidth_=0.0 )
            : start( start_ )
            , end( end_ )
            , isCalculated( isCalculated_ )
            , calcMode( calcMode_ )
            , sequence( sequence_ )
            , stepWidth( stepWidth_ )
            , subStepWidth( subStepWidth_ )
        {}







        qreal distance() const
        {
            return end-start;
        }

        bool operator==( const DataDimension& r ) const
        {
            return
                (start == r.start) &&
                (end == r.end) &&
                (sequence == r.sequence) &&
                (isCalculated == r.isCalculated) &&
                (calcMode == r.calcMode) &&
                (stepWidth == r.stepWidth) &&
                (subStepWidth == r.subStepWidth);
        }

        bool operator!=( const DataDimension& other ) const
        { return !operator==( other ); }


        qreal start;
        qreal end;
        bool isCalculated;
        AbstractCoordinatePlane::AxesCalcMode calcMode;
        KDChartEnums::GranularitySequence sequence;
        qreal stepWidth;
        qreal subStepWidth;
    };

#if !defined(QT_NO_DEBUG_STREAM)
    QDebug operator<<( QDebug stream, const DataDimension& r );
#endif

}
#endif
