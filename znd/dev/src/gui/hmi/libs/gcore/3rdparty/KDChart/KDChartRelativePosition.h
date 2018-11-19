#ifndef KDCHARTRELATIVEPOSITION_H
#define KDCHARTRELATIVEPOSITION_H 

#include <QDebug>
#include <QMetaType>
#include <Qt>
#include <QPointF>
#include <QSizeF>
#include "KDChartGlobal.h"

namespace KDChart {

    class Position;
    class PositionPoints;
    class Measure;
class KDCHART_EXPORT RelativePosition
{
public:
    RelativePosition();
    RelativePosition( const RelativePosition& );

    RelativePosition & operator=( const RelativePosition & other );

    ~RelativePosition();
    void setReferenceArea( QObject* area );
    QObject* referenceArea() const;
    void setReferencePoints( const PositionPoints& points );
    const PositionPoints referencePoints() const;
    void setReferencePosition( Position position );
    void resetReferencePosition();
    Position referencePosition() const;
    void setAlignment( Qt::Alignment flags );
    Qt::Alignment alignment() const;
    void setHorizontalPadding( const Measure& padding );
    Measure horizontalPadding() const;
    void setVerticalPadding( const Measure& padding );
    Measure verticalPadding() const;

    void setRotation( qreal rot );
    qreal rotation() const;
    const QPointF referencePoint(qreal* polarDegrees=0) const;
    const QPointF calculatedPoint( const QSizeF& autoSize ) const;

    bool operator==( const RelativePosition& ) const;
    bool operator!=( const RelativePosition & other ) const;

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( RelativePosition )
};

inline bool RelativePosition::operator!=( const RelativePosition & other ) const { return !operator==( other ); }
}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::RelativePosition& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::RelativePosition )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::RelativePosition, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::RelativePosition )

#endif
