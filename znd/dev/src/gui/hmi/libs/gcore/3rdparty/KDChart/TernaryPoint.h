#ifndef TERNARYPOINT_H
#define TERNARYPOINT_H 

#include <QtDebug>
#include <QPointF>





class TernaryPoint
{
public:
    TernaryPoint();
    TernaryPoint( qreal a, qreal b );

    qreal a() const { return m_a; }
    qreal b() const { return m_b; }
    qreal c() const { return 1.0 - m_a - m_b; }

    void set( qreal a, qreal b );

    bool isValid() const;

private:
    qreal m_a;
    qreal m_b;
};

QDebug operator<<( QDebug stream, const TernaryPoint& point );

QPointF translate( const TernaryPoint& );

#endif
