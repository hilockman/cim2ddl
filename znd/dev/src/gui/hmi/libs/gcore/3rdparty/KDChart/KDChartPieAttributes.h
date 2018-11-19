#ifndef KDCHART_PIE_ATTRIBUTES_H
#define KDCHART_PIE_ATTRIBUTES_H 

#include <QMetaType>
#include "KDChartAbstractThreeDAttributes.h"
#include "KDChartGlobal.h"

namespace KDChart {




class KDCHART_EXPORT PieAttributes
{
public:
    PieAttributes();
    PieAttributes( const PieAttributes& );
    PieAttributes &operator= ( const PieAttributes& );

    ~PieAttributes();
    void setExplode( bool explode );


    bool explode() const;







    void setExplodeFactor( qreal factor );


    qreal explodeFactor() const;

    void setGapFactor( bool circular, qreal factor );
    qreal gapFactor( bool circular ) const;

    bool operator==( const PieAttributes& ) const;
    inline bool operator!=( const PieAttributes& other ) const { return !operator==(other); }

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( PieAttributes )
};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::PieAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::PieAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::PieAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::PieAttributes )

#endif
