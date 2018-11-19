#ifndef KDCHARTCARTESIANAXIS_H
#define KDCHARTCARTESIANAXIS_H 

#include <QList>

#include "KDChartAbstractAxis.h"

namespace KDChart {

    class AbstractCartesianDiagram;
    class KDCHART_EXPORT CartesianAxis : public AbstractAxis
    {
        Q_OBJECT

        Q_DISABLE_COPY( CartesianAxis )
        KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( CartesianAxis, AbstractDiagram* )

    public:
        enum Position {
            Bottom,
            Top,
            Right,
            Left
        };
        explicit CartesianAxis ( AbstractCartesianDiagram* diagram = 0 );
        ~CartesianAxis();




        bool compare( const CartesianAxis* other ) const;


        virtual void paint( QPainter* );

        virtual void paintCtx( PaintContext* );




        void setTitleText( const QString& text );
        QString titleText() const;






        void setTitleSpace( qreal value );
        qreal titleSpace() const;




        void setTitleSize(qreal value);
        qreal titleSize() const;

        void setTitleTextAttributes( const TextAttributes &a );







        TextAttributes titleTextAttributes() const;






        void resetTitleTextAttributes();
        bool hasDefaultTitleTextAttributes() const;

        virtual void setPosition ( Position p );
#if QT_VERSION < 0x040400 || defined(Q_COMPILER_MANGLES_RETURN_TYPE)
        virtual const Position position () const;
#else
        virtual Position position () const;
#endif

        virtual void layoutPlanes();

        virtual bool isAbscissa() const;
        virtual bool isOrdinate() const;
        void setAnnotations( const QMap< qreal, QString >& annotations );



        QMap< qreal, QString > annotations() const;





        void setCustomTicks( const QList< qreal >& ticksPostions );



        QList< qreal > customTicks() const;




        void setCustomTickLength(int value);



        int customTickLength() const;


        virtual bool isEmpty() const;

        virtual Qt::Orientations expandingDirections() const;

        virtual QSize maximumSize() const;

        virtual QSize minimumSize() const;

        virtual QSize sizeHint() const;

        virtual void setGeometry( const QRect& r );

        virtual QRect geometry() const;

    public Q_SLOTS:
        void setCachedSizeDirty() const;

        virtual int tickLength( bool subUnitTicks = false ) const;
    private Q_SLOTS:
        void coordinateSystemChanged();
    private:
        friend class TickIterator;
    };

    typedef QList<CartesianAxis*> CartesianAxisList;
}

#endif
