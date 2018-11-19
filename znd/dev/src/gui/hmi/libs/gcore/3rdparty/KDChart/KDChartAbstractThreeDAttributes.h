#ifndef KDCHARTABSTRACTTHREEDATTRIBUTES_H
#define KDCHARTABSTRACTTHREEDATTRIBUTES_H 

#include <QMetaType>
#include "KDChartGlobal.h"

namespace KDChart {




class KDCHART_EXPORT AbstractThreeDAttributes
{
public:
    AbstractThreeDAttributes();
    AbstractThreeDAttributes( const AbstractThreeDAttributes& );
    AbstractThreeDAttributes &operator= ( const AbstractThreeDAttributes& );

    virtual ~AbstractThreeDAttributes() = 0;

    void setEnabled( bool enabled );
    bool isEnabled() const;

    void setDepth( qreal depth );
    qreal depth() const;


    qreal validDepth() const;

    bool isThreeDBrushEnabled() const;
    void setThreeDBrushEnabled( bool enabled );
    virtual QBrush threeDBrush( const QBrush& brush, const QRectF& rect ) const;

    bool operator==( const AbstractThreeDAttributes& ) const;
    inline bool operator!=( const AbstractThreeDAttributes& other ) const { return !operator==(other); }

    KDCHART_DECLARE_PRIVATE_BASE_POLYMORPHIC(AbstractThreeDAttributes)

    KDCHART_DECLARE_SWAP_BASE(AbstractThreeDAttributes)

};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::AbstractThreeDAttributes& );
#endif



#endif
