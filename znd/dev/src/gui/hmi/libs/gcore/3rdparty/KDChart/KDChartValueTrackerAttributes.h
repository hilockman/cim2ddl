#ifndef KDCHARTVALUETRACKERATTRIBUTES_H
#define KDCHARTVALUETRACKERATTRIBUTES_H 

#include <QDebug>
#include <QMetaType>
#include "KDChartGlobal.h"

namespace KDChart {
    class KDCHART_EXPORT ValueTrackerAttributes
    {
        public:
            ValueTrackerAttributes();
            ValueTrackerAttributes( const ValueTrackerAttributes& );
            ValueTrackerAttributes &operator= ( const ValueTrackerAttributes& );

            ~ValueTrackerAttributes();




            void setPen( const QPen& pen );




            QPen pen() const;

            void setLinePen( const QPen &pen );
            QPen linePen() const;

            void setMarkerPen( const QPen &pen );
            QPen markerPen() const;

            void setMarkerBrush( const QBrush &brush );
            QBrush markerBrush() const;

            void setArrowBrush( const QBrush &brush );
            QBrush arrowBrush() const;






            void setAreaBrush( const QBrush& brush );




            QBrush areaBrush() const;





            void setMarkerSize( const QSizeF& size );




            QSizeF markerSize() const;





            Qt::Orientations orientations() const;




            void setOrientations( Qt::Orientations orientations );





            void setEnabled( bool enabled );




            bool isEnabled() const;

            bool operator==( const ValueTrackerAttributes& ) const;
            inline bool operator!=( const ValueTrackerAttributes& other ) const { return !operator==(other); }

        private:
            KDCHART_DECLARE_PRIVATE_BASE_VALUE( ValueTrackerAttributes )
    };

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::ValueTrackerAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::ValueTrackerAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::ValueTrackerAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::ValueTrackerAttributes )

#endif
