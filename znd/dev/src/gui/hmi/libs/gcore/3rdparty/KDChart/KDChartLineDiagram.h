#ifndef KDCHARTLINEDIAGRAM_H
#define KDCHARTLINEDIAGRAM_H 

#include "KDChartAbstractCartesianDiagram.h"
#include "KDChartLineAttributes.h"
#include "KDChartValueTrackerAttributes.h"

QT_BEGIN_NAMESPACE
class QPainter;
class QPolygonF;
QT_END_NAMESPACE

namespace KDChart {

    class ThreeDLineAttributes;






class KDCHART_EXPORT LineDiagram : public AbstractCartesianDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( LineDiagram )


    KDCHART_DECLARE_DERIVED_DIAGRAM( LineDiagram, CartesianCoordinatePlane )


public:
    class LineDiagramType;
    friend class LineDiagramType;

    explicit LineDiagram( QWidget* parent = 0, CartesianCoordinatePlane* plane = 0 );
    virtual ~LineDiagram();

    virtual LineDiagram * clone() const;




    bool compare( const LineDiagram* other ) const;

    enum LineType {
        Normal = 0,
        Stacked = 1,
        Percent = 2
    };


    void setType( const LineType type );
    LineType type() const;







    void setCenterDataPoints( bool center );

    bool centerDataPoints() const;






    void setReverseDatasetOrder( bool reverse );

    bool reverseDatasetOrder() const;

    void setLineAttributes( const LineAttributes & a );
    void setLineAttributes( int column, const LineAttributes & a );
    void setLineAttributes( const QModelIndex & index, const LineAttributes & a );
    void resetLineAttributes( int column );
    void resetLineAttributes( const QModelIndex & index );
    LineAttributes lineAttributes() const;
    LineAttributes lineAttributes( int column ) const;
    LineAttributes lineAttributes( const QModelIndex & index ) const;

    void setThreeDLineAttributes( const ThreeDLineAttributes & a );
    void setThreeDLineAttributes( int column, const ThreeDLineAttributes & a );
    void setThreeDLineAttributes( const QModelIndex & index,
                                  const ThreeDLineAttributes & a );




    ThreeDLineAttributes threeDLineAttributes() const;
    ThreeDLineAttributes threeDLineAttributes( int column ) const;
    ThreeDLineAttributes threeDLineAttributes( const QModelIndex & index ) const;

    void setValueTrackerAttributes( const QModelIndex & index,
                                    const ValueTrackerAttributes & a );
    ValueTrackerAttributes valueTrackerAttributes( const QModelIndex & index ) const;

#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)


    const int numberOfAbscissaSegments () const;

    const int numberOfOrdinateSegments () const;
#else


    int numberOfAbscissaSegments () const;

    int numberOfOrdinateSegments () const;
#endif

protected:
    void paint ( PaintContext* paintContext );

public:
    void resize ( const QSizeF& area );

protected:

    qreal valueForCellTesting( int row, int column,
                                bool& bOK,
                                bool showHiddenCellsAsInvalid = false ) const;
    LineAttributes::MissingValuesPolicy getCellValues(
        int row, int column,
        bool shiftCountedXValuesByHalfSection,
        qreal& valueX, qreal& valueY ) const;

    virtual qreal threeDItemDepth( const QModelIndex & index ) const;
    virtual qreal threeDItemDepth( int column ) const;

    virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent ( QPaintEvent* );
    void resizeEvent ( QResizeEvent* );
};

}

#endif
