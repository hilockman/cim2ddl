#ifndef KDCHARTFRAMEATTRIBUTES_H
#define KDCHARTFRAMEATTRIBUTES_H 

#include <QDebug>
#include <QMetaType>
#include <QPen>
#include "KDChartGlobal.h"

namespace KDChart {




class KDCHART_EXPORT FrameAttributes
{
public:
    FrameAttributes();
    FrameAttributes( const FrameAttributes& );
    FrameAttributes &operator= ( const FrameAttributes& );

    ~FrameAttributes();

    void setVisible( bool visible );
    bool isVisible() const;

    void setPen( const QPen & pen );
    QPen pen() const;

    void setCornerRadius( qreal radius );
    qreal cornerRadius() const;

    void setPadding( int padding );
    int padding() const;

    bool operator==( const FrameAttributes& ) const;
    inline bool operator!=( const FrameAttributes& other ) const { return !operator==(other); }

private:

    KDCHART_DECLARE_PRIVATE_BASE_VALUE( FrameAttributes )
};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::FrameAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::FrameAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::FrameAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::FrameAttributes )

#endif
