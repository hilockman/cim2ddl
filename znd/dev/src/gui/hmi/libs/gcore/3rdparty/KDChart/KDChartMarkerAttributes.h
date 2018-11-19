#ifndef KDCHARTMARKERATTRIBUTES_H
#define KDCHARTMARKERATTRIBUTES_H 

#include <QMetaType>
#include "KDChartGlobal.h"

QT_BEGIN_NAMESPACE
class QColor;
class QSizeF;
class QPen;
class QPainterPath;
class QDebug;
template <typename T, typename K> class QMap;
QT_END_NAMESPACE

namespace KDChart {




    class KDCHART_EXPORT MarkerAttributes
    {
    public:
        MarkerAttributes();
        MarkerAttributes( const MarkerAttributes& );
        MarkerAttributes &operator= ( const MarkerAttributes& );

        ~MarkerAttributes();

        enum MarkerStyle { MarkerCircle = 0,
                           MarkerSquare = 1,
                           MarkerDiamond = 2,
                           Marker1Pixel = 3,
                           Marker4Pixels = 4,
                           MarkerRing = 5,
                           MarkerCross = 6,
                           MarkerFastCross = 7,
                           NoMarker = 8,
                           PainterPathMarker = 9,
                           StartCustomMarkers = 10 };

        void setVisible( bool visible );
        bool isVisible() const;

        typedef QMap<uint, uint> MarkerStylesMap;
        void setMarkerStylesMap( const MarkerStylesMap & map );
        MarkerStylesMap markerStylesMap() const;

        void setThreeD( bool value );
        bool threeD() const;
        void setMarkerStyle( uint style );
        uint markerStyle() const;
        void setMarkerSize( const QSizeF& size );
        QSizeF markerSize() const;

        void setMarkerColor( const QColor& color );
        QColor markerColor() const;

        void setCustomMarkerPath( const QPainterPath& path );
        QPainterPath customMarkerPath() const;

        void setPen( const QPen& pen );
        QPen pen() const;

        bool operator==( const MarkerAttributes& ) const;
        bool operator!=( const MarkerAttributes& ) const;

    private:
        KDCHART_DECLARE_PRIVATE_BASE_VALUE( MarkerAttributes )
    };

    inline bool MarkerAttributes::operator!=( const MarkerAttributes & other ) const { return !operator==( other ); }
}

#ifndef QT_NO_DEBUG_STREAM
KDCHART_EXPORT QDebug operator<<( QDebug, const KDChart::MarkerAttributes & );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::MarkerAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::MarkerAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::MarkerAttributes )

#endif
