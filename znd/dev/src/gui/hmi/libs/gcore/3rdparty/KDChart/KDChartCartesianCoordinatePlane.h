#ifndef KDCHARTCARTESIANCOORDINATEPLANE_H
#define KDCHARTCARTESIANCOORDINATEPLANE_H 

#include "KDChartAbstractCoordinatePlane.h"

namespace KDChart {

    class Chart;
    class PaintContext;
    class AbstractDiagram;
    class CartesianAxis;
    class CartesianGrid;




    class KDCHART_EXPORT CartesianCoordinatePlane : public AbstractCoordinatePlane
    {
        Q_OBJECT

        Q_DISABLE_COPY( CartesianCoordinatePlane )
        KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( CartesianCoordinatePlane, Chart* )

    friend class CartesianAxis;
    friend class CartesianGrid;

    public:
        explicit CartesianCoordinatePlane ( Chart* parent = 0 );
        ~CartesianCoordinatePlane();

        void addDiagram ( AbstractDiagram* diagram );






        void setIsometricScaling ( bool onOff );

        bool doesIsometricScaling() const;

        const QPointF translate ( const QPointF& diagramPoint ) const;




        virtual qreal zoomFactorX() const;



        virtual qreal zoomFactorY() const;




        virtual void setZoomFactors( qreal factorX, qreal factorY );



        virtual void setZoomFactorX( qreal factor );



        virtual void setZoomFactorY( qreal factor );




        virtual QPointF zoomCenter() const;




        virtual void setZoomCenter( const QPointF& center );
        void setFixedDataCoordinateSpaceRelation( bool fixed );
        bool hasFixedDataCoordinateSpaceRelation() const;
        void setXAxisStartAtZero(bool fixedStart);
        bool xAxisStartAtZero() const;
        void setHorizontalRange( const QPair<qreal, qreal> & range );
        void setVerticalRange( const QPair<qreal, qreal> & range );
        QPair<qreal, qreal> horizontalRange() const;
        QPair<qreal, qreal> verticalRange() const;
        void setAutoAdjustHorizontalRangeToData( unsigned int percentEmpty = 67 );
        void setAutoAdjustVerticalRangeToData( unsigned int percentEmpty = 67 );
        unsigned int autoAdjustHorizontalRangeToData() const;
        unsigned int autoAdjustVerticalRangeToData() const;
        void setGridAttributes( Qt::Orientation orientation, const GridAttributes & );
        void resetGridAttributes( Qt::Orientation orientation );
        const GridAttributes gridAttributes( Qt::Orientation orientation ) const;
        bool hasOwnGridAttributes( Qt::Orientation orientation ) const;
        void setAutoAdjustGridToZoom( bool autoAdjust );






#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)
        const bool autoAdjustGridToZoom() const;
#else
        bool autoAdjustGridToZoom() const;
#endif

        AxesCalcMode axesCalcModeY() const;
        AxesCalcMode axesCalcModeX() const;


        void setAxesCalcModes( AxesCalcMode mode );

        void setAxesCalcModeY( AxesCalcMode mode );

        void setAxesCalcModeX( AxesCalcMode mode );


        virtual void paint( QPainter* );


        AbstractCoordinatePlane* sharedAxisMasterPlane( QPainter* p = 0 );





        QRectF visibleDataRange() const;





        QRectF logicalArea() const;
        QRectF diagramArea() const;






        QRectF visibleDiagramArea() const;







        void setHorizontalRangeReversed( bool reverse );




        bool isHorizontalRangeReversed() const;







        void setVerticalRangeReversed( bool reverse );




        bool isVerticalRangeReversed() const;




        void setGeometry( const QRect& r );


        Qt::Orientations expandingDirections() const;


    public Q_SLOTS:
        void adjustRangesToData();





        void adjustHorizontalRangeToData();





        void adjustVerticalRangeToData();

    protected:
        QRectF getRawDataBoundingRectFromDiagrams() const;
        QRectF adjustedToMaxEmptyInnerPercentage(
                const QRectF& r, unsigned int percentX, unsigned int percentY ) const;
        virtual QRectF calculateRawDataBoundingRect() const;
        virtual DataDimensionsList getDataDimensionsList() const;


        virtual QRectF drawingArea() const;
    public:
        const QPointF translateBack( const QPointF& screenPoint ) const;
    protected:
        void paintEvent ( QPaintEvent* );
        void layoutDiagrams();

        bool doneSetZoomFactorX( qreal factor );
        bool doneSetZoomFactorY( qreal factor );
        bool doneSetZoomCenter( const QPointF& center );

        void handleFixedDataCoordinateSpaceRelation( const QRectF& geometry );


        bool hasHeightForWidth() const;
        int heightForWidth( int w ) const;
        QSize sizeHint() const;

    protected Q_SLOTS:
        void slotLayoutChanged( AbstractDiagram* );

    private:
        void setHasOwnGridAttributes(
            Qt::Orientation orientation, bool on );
    };

}

#endif
