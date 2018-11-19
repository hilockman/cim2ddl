#ifndef KDCHARTPOSITION_H
#define KDCHARTPOSITION_H 

#include <QDebug>
#include <Qt>
#include <QMetaType>
#include <QCoreApplication>
#include "KDChartGlobal.h"
#include "KDChartEnums.h"

QT_BEGIN_NAMESPACE
class QStringList;
class QByteArray;
template <typename T> class QList;
QT_END_NAMESPACE

namespace KDChart {
class KDCHART_EXPORT Position
{
    Q_DECLARE_TR_FUNCTIONS( Position )
    Position( int value );
public:
    Position();
    Position( KDChartEnums::PositionValue value );

    KDChartEnums::PositionValue value() const;

    const char *name() const;
    QString printableName() const;

    bool isUnknown() const;

    bool isWestSide() const;
    bool isNorthSide() const;
    bool isEastSide() const;
    bool isSouthSide() const;

    bool isCorner() const;
    bool isPole() const;

    bool isFloating() const;

    static const Position& Unknown;
    static const Position& Center;
    static const Position& NorthWest;
    static const Position& North;
    static const Position& NorthEast;
    static const Position& East;
    static const Position& SouthEast;
    static const Position& South;
    static const Position& SouthWest;
    static const Position& West;

    static const Position& Floating;


    enum Option {
        IncludeCenter = 0x1,
        IncludeFloating = 0x2 };
    Q_DECLARE_FLAGS( Options, Option )





    static QList<QByteArray> names( Options options = Options(IncludeCenter | IncludeFloating) );
    static QStringList printableNames( Options options = Options(IncludeCenter | IncludeFloating) );

    static Position fromName(const char * name);
    static Position fromName(const QByteArray & name);

    bool operator==( const Position& ) const;
    bool operator==( int ) const;
    bool operator!=( const Position& ) const;
    bool operator!=( int ) const;

private:
    int m_value;
};

inline bool Position::operator!=( const Position & other ) const { return !operator==( other ); }
inline bool Position::operator!=( int other ) const { return !operator==( other ); }





class KDCHART_EXPORT PositionPoints
{
  public:
    PositionPoints() {}

    PositionPoints(
        QPointF center,
        QPointF northWest,
        QPointF north,
        QPointF northEast,
        QPointF east,
        QPointF southEast,
        QPointF south,
        QPointF southWest,
        QPointF west )
      : mPositionCenter( center )
      , mPositionNorthWest( northWest )
      , mPositionNorth( north )
      , mPositionNorthEast( northEast )
      , mPositionEast( east )
      , mPositionSouthEast( southEast )
      , mPositionSouth( south )
      , mPositionSouthWest( southWest )
      , mPositionWest( west )
        {}
    PositionPoints(
        const QPointF& onePointForAllPositions )
      : mPositionCenter( onePointForAllPositions )
      , mPositionNorthWest( onePointForAllPositions )
      , mPositionNorth( onePointForAllPositions )
      , mPositionNorthEast( onePointForAllPositions )
      , mPositionEast( onePointForAllPositions )
      , mPositionSouthEast( onePointForAllPositions )
      , mPositionSouth( onePointForAllPositions )
      , mPositionSouthWest( onePointForAllPositions )
      , mPositionWest( onePointForAllPositions )
        {}
    PositionPoints(
        const QRectF& rect )
    {
        const QRectF r( rect.normalized() );
        mPositionCenter = r.center();
        mPositionNorthWest = r.topLeft();
        mPositionNorth = QPointF(r.center().x(), r.top());
        mPositionNorthEast = r.topRight();
        mPositionEast = QPointF(r.right(), r.center().y());
        mPositionSouthEast = r.bottomRight();
        mPositionSouth = QPointF(r.center().x(), r.bottom());
        mPositionSouthWest = r.bottomLeft();
        mPositionWest = QPointF(r.left(), r.center().y());
    }
    PositionPoints(
        QPointF northWest,
        QPointF northEast,
        QPointF southEast,
        QPointF southWest )
      : mPositionCenter( (northWest + southEast) / 2.0 )
      , mPositionNorthWest( northWest )
      , mPositionNorth( (northWest + northEast) / 2.0 )
      , mPositionNorthEast( northEast )
      , mPositionEast( (northEast + southEast) / 2.0 )
      , mPositionSouthEast( southEast )
      , mPositionSouth( (southWest + southEast) / 2.0 )
      , mPositionSouthWest( southWest )
      , mPositionWest( (northWest + southWest) / 2.0 )
        {}

    void setDegrees( KDChartEnums::PositionValue pos, qreal degrees )
    {
        mapOfDegrees[pos] = degrees;
    }

#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)
    const qreal degrees( KDChartEnums::PositionValue pos ) const
#else
    qreal degrees( KDChartEnums::PositionValue pos ) const
#endif
    {
        if ( mapOfDegrees.contains(pos) )
            return mapOfDegrees[pos];
        return 0.0;
    }

#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)
    const QPointF point( Position position ) const
#else
    QPointF point( Position position ) const
#endif
    {

      if ( position == Position::Center)
        return mPositionCenter;
      if ( position == Position::NorthWest)
        return mPositionNorthWest;
      if ( position == Position::North)
        return mPositionNorth;
      if ( position == Position::NorthEast)
        return mPositionNorthEast;
      if ( position == Position::East)
        return mPositionEast;
      if ( position == Position::SouthEast)
        return mPositionSouthEast;
      if ( position == Position::South)
        return mPositionSouth;
      if ( position == Position::SouthWest)
        return mPositionSouthWest;
      if ( position == Position::West)
        return mPositionWest;
      return mPositionUnknown;
    }

    bool isNull() const
    {
        return
            mPositionUnknown.isNull() &&
            mPositionCenter.isNull() &&
            mPositionNorthWest.isNull() &&
            mPositionNorth.isNull() &&
            mPositionNorthEast.isNull() &&
            mPositionEast.isNull() &&
            mPositionSouthEast.isNull() &&
            mPositionSouth.isNull() &&
            mPositionSouthWest.isNull() &&
            mPositionWest.isNull();
    }

    QPointF mPositionUnknown;
    QPointF mPositionCenter;
    QPointF mPositionNorthWest;
    QPointF mPositionNorth;
    QPointF mPositionNorthEast;
    QPointF mPositionEast;
    QPointF mPositionSouthEast;
    QPointF mPositionSouth;
    QPointF mPositionSouthWest;
    QPointF mPositionWest;
    QMap<KDChartEnums::PositionValue, qreal> mapOfDegrees;

};


}


#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::Position& );
#endif

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::Position, Q_MOVABLE_TYPE );
Q_DECLARE_OPERATORS_FOR_FLAGS( KDChart::Position::Options )
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::Position )

#endif
