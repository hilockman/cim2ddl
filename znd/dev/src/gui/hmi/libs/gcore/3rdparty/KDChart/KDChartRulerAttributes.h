#ifndef KDCHARTRULERATTRIBUTES_H
#define KDCHARTRULERATTRIBUTES_H 

#include <QMetaType>
#include "KDChartGlobal.h"
#include "KDChartEnums.h"

QT_BEGIN_NAMESPACE
class QPen;
QT_END_NAMESPACE

namespace KDChart {




class KDCHART_EXPORT RulerAttributes
{
public:
 RulerAttributes();
 RulerAttributes( const RulerAttributes& );
 RulerAttributes &operator= ( const RulerAttributes& );

    ~RulerAttributes();




    void setTickMarkPen( const QPen& pen );
    QPen tickMarkPen() const;




    void setMajorTickMarkPen( const QPen& pen );
    bool majorTickMarkPenIsSet() const;
    QPen majorTickMarkPen() const;




    void setMinorTickMarkPen( const QPen& pen );
    bool minorTickMarkPenIsSet() const;
    QPen minorTickMarkPen() const;







    void setTickMarkPen( qreal value, const QPen& pen );
    QPen tickMarkPen( qreal value ) const;
    typedef QMap<qreal, QPen> TickMarkerPensMap;
    TickMarkerPensMap tickMarkPens() const;

    bool hasTickMarkPenAt( qreal value) const;




    void setTickMarkColor( const QColor& color );
    QColor tickMarkColor() const;




    void setShowMinorTickMarks( bool show );
    bool showMinorTickMarks() const;

    void setShowRulerLine( bool show );
    bool showRulerLine() const;




    void setShowMajorTickMarks( bool show );
    bool showMajorTickMarks() const;




    void setMajorTickMarkLength( int length );
    int majorTickMarkLength() const;
    bool majorTickMarkLengthIsSet() const;




    void setMinorTickMarkLength( int length );
    int minorTickMarkLength() const;
    bool minorTickMarkLengthIsSet() const;






    void setLabelMargin(int margin);
    int labelMargin() const;





    void setShowFirstTick( bool show );
    bool showFirstTick() const;

    bool operator==( const RulerAttributes& ) const;
    inline bool operator!=( const RulerAttributes& other ) const { return !operator==(other); }

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( RulerAttributes )
};

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::RulerAttributes& );
#endif

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::RulerAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::RulerAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::RulerAttributes )

#endif
