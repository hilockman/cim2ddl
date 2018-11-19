#ifndef KDCHARTPLOTTER_H
#define KDCHARTPLOTTER_H 

#include "KDChartAbstractCartesianDiagram.h"

#include "KDChartLineAttributes.h"
#include "KDChartValueTrackerAttributes.h"

namespace KDChart {

    class ThreeDLineAttributes;




class KDCHART_EXPORT Plotter : public AbstractCartesianDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( Plotter )
    Q_ENUMS( CompressionMode )

    KDCHART_DECLARE_DERIVED_DIAGRAM( Plotter, CartesianCoordinatePlane )
    Q_PROPERTY( CompressionMode useDataCompression READ useDataCompression WRITE setUseDataCompression )
    Q_PROPERTY( qreal mergeRadiusPercentage READ mergeRadiusPercentage WRITE setMergeRadiusPercentage )

public:


    enum CompressionMode{ SLOPE, DISTANCE, BOTH, NONE };
    class PlotterType;
    friend class PlotterType;

    explicit Plotter( QWidget* parent = 0, CartesianCoordinatePlane* plane = 0 );
    virtual ~Plotter();

    virtual Plotter* clone() const;




    bool compare( const Plotter* other ) const;

    enum PlotType {
        Normal = 0,
        Percent
    };


    void setType( const PlotType type );
    PlotType type() const;

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

    void setModel( QAbstractItemModel *model );

    CompressionMode useDataCompression() const;
    void setUseDataCompression( CompressionMode value );

    qreal maxSlopeChange() const;
    void setMaxSlopeChange( qreal value );

    qreal mergeRadiusPercentage() const;
    void setMergeRadiusPercentage( qreal value );

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

    virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent ( QPaintEvent* );
    void resizeEvent ( QResizeEvent* );
protected Q_SLOTS:
    void setDataBoundariesDirty();
    void calcMergeRadius();
};

}

#endif
