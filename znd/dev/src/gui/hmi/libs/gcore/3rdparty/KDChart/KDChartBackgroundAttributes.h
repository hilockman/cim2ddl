#ifndef KDCHARTBACKGROUNDATTRIBUTES_H
#define KDCHARTBACKGROUNDATTRIBUTES_H 

#include <QDebug>
#include <QMetaType>
#include <QBrush>
#include "KDChartGlobal.h"

namespace KDChart {




class KDCHART_EXPORT BackgroundAttributes
{
public:
    BackgroundAttributes();
    BackgroundAttributes( const BackgroundAttributes& );
    BackgroundAttributes &operator= ( const BackgroundAttributes& );

    ~BackgroundAttributes();

    enum BackgroundPixmapMode { BackgroundPixmapModeNone,
                                BackgroundPixmapModeCentered,
                                BackgroundPixmapModeScaled,
                                BackgroundPixmapModeStretched };

    void setVisible( bool visible );
    bool isVisible() const;

    void setBrush( const QBrush &brush );
    QBrush brush() const;

    void setPixmapMode( BackgroundPixmapMode mode );
    BackgroundPixmapMode pixmapMode() const;

    void setPixmap( const QPixmap &backPixmap );
    QPixmap pixmap() const;

    bool operator==( const BackgroundAttributes& ) const;
    inline bool operator!=( const BackgroundAttributes& other ) const { return !operator==(other); }

    bool isEqualTo( const BackgroundAttributes& other, bool ignorePixmap=false ) const;

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( BackgroundAttributes )
};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::BackgroundAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::BackgroundAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::BackgroundAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::BackgroundAttributes )

#endif
