#ifndef KDCHARTGRIDATTRIBUTES_H
#define KDCHARTGRIDATTRIBUTES_H 

#include <QMetaType>
#include "KDChartGlobal.h"
#include "KDChartEnums.h"

QT_BEGIN_NAMESPACE
class QPen;
QT_END_NAMESPACE

namespace KDChart {




class KDCHART_EXPORT GridAttributes
{
public:
    GridAttributes();
    GridAttributes( const GridAttributes& );
    GridAttributes &operator= ( const GridAttributes& );

    ~GridAttributes();

    void setGridVisible( bool visible );
    bool isGridVisible() const;


    void setGridStepWidth( qreal stepWidth=0.0 );
    qreal gridStepWidth() const;

    void setGridSubStepWidth( qreal subStepWidth=0.0 );
    qreal gridSubStepWidth() const;
    void setGridGranularitySequence( KDChartEnums::GranularitySequence sequence );
    KDChartEnums::GranularitySequence gridGranularitySequence() const;
    void setAdjustBoundsToGrid( bool adjustLower, bool adjustUpper );
    bool adjustLowerBoundToGrid() const;
    bool adjustUpperBoundToGrid() const;


    void setGridPen( const QPen & pen );
    QPen gridPen() const;


    void setSubGridVisible( bool visible );
    bool isSubGridVisible() const;

    void setSubGridPen( const QPen & pen );
    QPen subGridPen() const;


    void setOuterLinesVisible( bool visible );
    bool isOuterLinesVisible() const;


    void setZeroLinePen( const QPen & pen );
    QPen zeroLinePen() const;

    bool operator==( const GridAttributes& ) const;
    inline bool operator!=( const GridAttributes& other ) const { return !operator==(other); }

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( GridAttributes )
};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::GridAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::GridAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::GridAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::GridAttributes )

#endif
