#ifndef KDCHARTLINEATTRIBUTES_H
#define KDCHARTLINEATTRIBUTES_H 

#include <QMetaType>
#include "KDChartGlobal.h"

namespace KDChart {




class KDCHART_EXPORT LineAttributes
{
public:
    enum MissingValuesPolicy {
        MissingValuesAreBridged,
        MissingValuesHideSegments,
        MissingValuesShownAsZero,
        MissingValuesPolicyIgnored };

    LineAttributes();
    LineAttributes( const LineAttributes& );
    LineAttributes &operator= ( const LineAttributes& );

    ~LineAttributes();


    void setMissingValuesPolicy( MissingValuesPolicy policy );
    MissingValuesPolicy missingValuesPolicy() const;
    void setAreaBoundingDataset( int dataset );
    int areaBoundingDataset() const;

    void setDisplayArea( bool display );
    bool displayArea() const;

    void setTransparency( uint alpha );
    uint transparency() const;

    bool operator==( const LineAttributes& ) const;
    inline bool operator!=( const LineAttributes& other ) const { return !operator==(other); }

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( LineAttributes )
};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::LineAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::LineAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::LineAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::LineAttributes )

#endif
