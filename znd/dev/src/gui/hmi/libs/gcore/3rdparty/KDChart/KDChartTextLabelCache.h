#ifndef KDCHARTTEXTLABELCACHE_H
#define KDCHARTTEXTLABELCACHE_H 

#include <QPixmap>
#include <QFont>
#include <QBrush>
#include <QPen>

#include "KDChartEnums.h"




class PrerenderedElement {
public:
    PrerenderedElement();
    virtual ~PrerenderedElement() {}




    virtual const QPixmap& pixmap() const = 0;



    virtual QPointF referencePointLocation( KDChartEnums::PositionValue ) const = 0;


    void setPosition( const QPointF& position );

    const QPointF& position() const;





    void setReferencePoint( KDChartEnums::PositionValue );

    KDChartEnums::PositionValue referencePoint() const;

protected:






    virtual void invalidate() const = 0;

private:
    QPointF m_position;
    KDChartEnums::PositionValue m_referencePoint;
};
class PrerenderedLabel : public PrerenderedElement
{
public:
    PrerenderedLabel();
    ~PrerenderedLabel();

    void setFont( const QFont& font );
    const QFont& font() const;

    void setText( const QString& text );
    const QString& text() const;

    void setBrush( const QBrush& brush );
    const QBrush& brush() const;

    void setPen( const QPen& );
    const QPen& pen() const;

    void setAngle( qreal angle );
    qreal angle() const;


    const QPixmap& pixmap() const;
    QPointF referencePointLocation( KDChartEnums::PositionValue position ) const;

    QPointF referencePointLocation() const;

protected:
    void invalidate() const;

private:



    void paint() const;


    mutable bool m_dirty;
    QFont m_font;
    QString m_text;
    QBrush m_brush;
    QPen m_pen;
    qreal m_angle;


    mutable QPixmap m_pixmap;
    mutable QPointF m_referenceBottomLeft;
    mutable QPointF m_textBaseLineVector;
    mutable QPointF m_textAscendVector;
};

#endif
