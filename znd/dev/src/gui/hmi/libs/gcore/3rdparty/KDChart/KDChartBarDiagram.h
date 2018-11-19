#ifndef KDCHARTBARDIAGRAM_H
#define KDCHARTBARDIAGRAM_H 

#include "KDChartAbstractCartesianDiagram.h"
#include "KDChartBarAttributes.h"

QT_BEGIN_NAMESPACE
class QPainter;
QT_END_NAMESPACE

namespace KDChart {

    class ThreeDBarAttributes;






class KDCHART_EXPORT BarDiagram : public AbstractCartesianDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( BarDiagram )

    KDCHART_DECLARE_DERIVED_DIAGRAM( BarDiagram, CartesianCoordinatePlane )

public:
    class BarDiagramType;
    friend class BarDiagramType;

    explicit BarDiagram(
        QWidget* parent = 0, CartesianCoordinatePlane* plane = 0 );
    virtual ~BarDiagram();

    virtual BarDiagram * clone() const;



    bool compare( const BarDiagram* other ) const;

    enum BarType { Normal,
                   Stacked,
                   Percent,
                   Rows
                 };

    void setType( const BarType type );
    BarType type() const;

    void setOrientation( Qt::Orientation orientation );
    Qt::Orientation orientation() const;

    void setBarAttributes( const BarAttributes & a );
    void setBarAttributes( int column, const BarAttributes & a );
    void setBarAttributes( const QModelIndex & index, const BarAttributes & a );

    BarAttributes barAttributes() const;
    BarAttributes barAttributes( int column ) const;
    BarAttributes barAttributes( const QModelIndex & index ) const;

    void setThreeDBarAttributes( const ThreeDBarAttributes & a );
    void setThreeDBarAttributes( int column, const ThreeDBarAttributes & a );
    void setThreeDBarAttributes( const QModelIndex & index,
                                  const ThreeDBarAttributes & a );
    ThreeDBarAttributes threeDBarAttributes() const;
    ThreeDBarAttributes threeDBarAttributes( int column ) const;
    ThreeDBarAttributes threeDBarAttributes( const QModelIndex & index ) const;

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
    virtual qreal threeDItemDepth( const QModelIndex & index ) const;
    virtual qreal threeDItemDepth( int column ) const;

    const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent ( QPaintEvent* );
    void resizeEvent ( QResizeEvent* );
private:

    void calculateValueAndGapWidths( int rowCount, int colCount,
                                     qreal groupWidth,
                                     qreal& barWidth,
                                     qreal& spaceBetweenBars,
                                     qreal& spaceBetweenGroups );
};

}

#endif
