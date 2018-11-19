#ifndef KDCHARTLAYOUTITEMS_H
#define KDCHARTLAYOUTITEMS_H 

#include <QBrush>
#include <QFont>
#include <QFontMetricsF>
#include <QLayout>
#include <QLayoutItem>
#include <QPen>

#include "KDChartTextAttributes.h"
#include "KDChartMarkerAttributes.h"

QT_BEGIN_NAMESPACE
class QPainter;
class KDTextDocument;
QT_END_NAMESPACE


QRectF rotatedRect( const QRectF& pt, qreal rotation );

namespace KDChart {
    class AbstractDiagram;
    class PaintContext;





    class KDCHART_EXPORT AbstractLayoutItem : public QLayoutItem
    {
    public:
        AbstractLayoutItem( Qt::Alignment itemAlignment = 0 ) :
            QLayoutItem( itemAlignment ),
            mParent( 0 ),
            mParentLayout( 0 ) {}







        virtual void paintAll( QPainter& painter );

        virtual void paint( QPainter* ) = 0;

        virtual void paintCtx( PaintContext* context );
        virtual void setParentWidget( QWidget* widget );
        virtual void sizeHintChanged() const;

        void setParentLayout( QLayout* lay )
        {
            mParentLayout = lay;
        }
        QLayout* parentLayout()
        {
            return mParentLayout;
        }
        void removeFromParentLayout()
        {
            if ( mParentLayout ) {
                if ( widget() )
                    mParentLayout->removeWidget( widget() );
                else
                    mParentLayout->removeItem( this );
            }
        }
    protected:
        QWidget* mParent;
        QLayout* mParentLayout;
    };





    class KDCHART_EXPORT TextLayoutItem : public AbstractLayoutItem
    {
    public:
        TextLayoutItem();
        TextLayoutItem( const QString& text,
                        const TextAttributes& attributes,
                        const QObject* autoReferenceArea,
                        KDChartEnums::MeasureOrientation autoReferenceOrientation,
                        Qt::Alignment alignment = 0 );

        void setAutoReferenceArea( const QObject* area );
        const QObject* autoReferenceArea() const;

        void setText(const QString & text);
        QString text() const;

        void setTextAlignment( Qt::Alignment );
        Qt::Alignment textAlignment() const;

        void setTextAttributes( const TextAttributes& a );
        TextAttributes textAttributes() const;


        virtual bool isEmpty() const;

        virtual Qt::Orientations expandingDirections() const;

        virtual QSize maximumSize() const;

        virtual QSize minimumSize() const;

        virtual QSize sizeHint() const;

        virtual void setGeometry( const QRect& r );

        virtual QRect geometry() const;

        virtual int marginWidth() const;

        virtual QSize sizeHintUnrotated() const;

        virtual bool intersects( const TextLayoutItem& other, const QPointF& myPos, const QPointF& otherPos ) const;
        virtual bool intersects( const TextLayoutItem& other, const QPoint& myPos, const QPoint& otherPos ) const;

        virtual qreal realFontSize() const;
        virtual QFont realFont() const;

        virtual void paint( QPainter* );

        QPolygon boundingPolygon() const;
    private:
        bool maybeUpdateRealFont() const;
        QSize unrotatedSizeHint( const QFont& fnt = QFont() ) const;
        QSize unrotatedTextSize( QFont fnt = QFont() ) const;
        QSize calcSizeHint( const QFont& font ) const;
        int marginWidth( const QSize& textSize ) const;

        qreal fitFontSizeToGeometry() const;

        QRect mRect;
        QString mText;
        Qt::Alignment mTextAlignment;
        TextAttributes mAttributes;
        const QObject* mAutoReferenceArea;
        KDChartEnums::MeasureOrientation mAutoReferenceOrientation;
        mutable QSize cachedSizeHint;
        mutable QPolygon mCachedBoundingPolygon;
        mutable qreal cachedFontSize;
        mutable QFont cachedFont;
    };

    class KDCHART_EXPORT TextBubbleLayoutItem : public AbstractLayoutItem
    {
    public:
        TextBubbleLayoutItem();
        TextBubbleLayoutItem( const QString& text,
                              const TextAttributes& attributes,
                              const QObject* autoReferenceArea,
                              KDChartEnums::MeasureOrientation autoReferenceOrientation,
                              Qt::Alignment alignment = 0 );

        ~TextBubbleLayoutItem();

        void setAutoReferenceArea( const QObject* area );
        const QObject* autoReferenceArea() const;

        void setText(const QString & text);
        QString text() const;

        void setTextAttributes( const TextAttributes& a );
        TextAttributes textAttributes() const;


        virtual bool isEmpty() const;

        virtual Qt::Orientations expandingDirections() const;

        virtual QSize maximumSize() const;

        virtual QSize minimumSize() const;

        virtual QSize sizeHint() const;

        virtual void setGeometry( const QRect& r );

        virtual QRect geometry() const;

        virtual void paint( QPainter* painter );

    protected:
        int borderWidth() const;

    private:
        TextLayoutItem* const m_text;
    };





    class KDCHART_EXPORT MarkerLayoutItem : public AbstractLayoutItem
    {
        public:
            MarkerLayoutItem( AbstractDiagram* diagram,
                              const MarkerAttributes& marker,
                              const QBrush& brush,
                              const QPen& pen,
                              Qt::Alignment alignment = 0 );

            virtual Qt::Orientations expandingDirections() const;
            virtual QRect geometry() const;
            virtual bool isEmpty() const;
            virtual QSize maximumSize() const;
            virtual QSize minimumSize() const;
            virtual void setGeometry( const QRect& r );
            virtual QSize sizeHint() const;

            virtual void paint( QPainter* );

            static void paintIntoRect(
                    QPainter* painter,
                    const QRect& rect,
                    AbstractDiagram* diagram,
                    const MarkerAttributes& marker,
                    const QBrush& brush,
                    const QPen& pen );

        private:
            AbstractDiagram* mDiagram;
            QRect mRect;
            MarkerAttributes mMarker;
            QBrush mBrush;
            QPen mPen;
    };





    class KDCHART_EXPORT LineLayoutItem : public AbstractLayoutItem
    {
        public:
            LineLayoutItem( AbstractDiagram* diagram,
                            int length,
                            const QPen& pen,
                            Qt::Alignment mLegendLineSymbolAlignment,
                            Qt::Alignment alignment = 0 );

            virtual Qt::Orientations expandingDirections() const;
            virtual QRect geometry() const;
            virtual bool isEmpty() const;
            virtual QSize maximumSize() const;
            virtual QSize minimumSize() const;
            virtual void setGeometry( const QRect& r );
            virtual QSize sizeHint() const;

            void setLegendLineSymbolAlignment(Qt::Alignment legendLineSymbolAlignment);
            virtual Qt::Alignment legendLineSymbolAlignment() const;

            virtual void paint( QPainter* );

            static void paintIntoRect(
                    QPainter* painter,
                    const QRect& rect,
                    const QPen& pen,
                    Qt::Alignment lineAlignment);

        private:
            AbstractDiagram* mDiagram;
            int mLength;
            QPen mPen;
            QRect mRect;
            Qt::Alignment mLegendLineSymbolAlignment;
    };





    class KDCHART_EXPORT LineWithMarkerLayoutItem : public AbstractLayoutItem
    {
        public:
            LineWithMarkerLayoutItem( AbstractDiagram* diagram,
                                      int lineLength,
                                      const QPen& linePen,
                                      int markerOffs,
                                      const MarkerAttributes& marker,
                                      const QBrush& markerBrush,
                                      const QPen& markerPen,
                                      Qt::Alignment alignment = 0 );

            virtual Qt::Orientations expandingDirections() const;
            virtual QRect geometry() const;
            virtual bool isEmpty() const;
            virtual QSize maximumSize() const;
            virtual QSize minimumSize() const;
            virtual void setGeometry( const QRect& r );
            virtual QSize sizeHint() const;

            virtual void paint( QPainter* );

        private:
            AbstractDiagram* mDiagram;
            QRect mRect;
            int mLineLength;
            QPen mLinePen;
            int mMarkerOffs;
            MarkerAttributes mMarker;
            QBrush mMarkerBrush;
            QPen mMarkerPen;
    };






    class KDCHART_EXPORT HorizontalLineLayoutItem : public AbstractLayoutItem
    {
    public:
        HorizontalLineLayoutItem();

        virtual Qt::Orientations expandingDirections() const;
        virtual QRect geometry() const;
        virtual bool isEmpty() const;
        virtual QSize maximumSize() const;
        virtual QSize minimumSize() const;
        virtual void setGeometry( const QRect& r );
        virtual QSize sizeHint() const;

        virtual void paint( QPainter* );

    private:
        QRect mRect;
    };





    class KDCHART_EXPORT VerticalLineLayoutItem : public AbstractLayoutItem
    {
        public:
            VerticalLineLayoutItem();

            virtual Qt::Orientations expandingDirections() const;
            virtual QRect geometry() const;
            virtual bool isEmpty() const;
            virtual QSize maximumSize() const;
            virtual QSize minimumSize() const;
            virtual void setGeometry( const QRect& r );
            virtual QSize sizeHint() const;

            virtual void paint( QPainter* );

        private:
            QRect mRect;
    };
    class KDCHART_EXPORT AutoSpacerLayoutItem : public AbstractLayoutItem
    {
        public:
            AutoSpacerLayoutItem(
                    bool layoutIsAtTopPosition, QHBoxLayout *rightLeftLayout,
                    bool layoutIsAtLeftPosition, QVBoxLayout *topBottomLayout );

            virtual Qt::Orientations expandingDirections() const;
            virtual QRect geometry() const;
            virtual bool isEmpty() const;
            virtual QSize maximumSize() const;
            virtual QSize minimumSize() const;
            virtual void setGeometry( const QRect& r );
            virtual QSize sizeHint() const;

            virtual void paint( QPainter* );

        private:
            QRect mRect;
            bool mLayoutIsAtTopPosition;
            QHBoxLayout *mRightLeftLayout;
            bool mLayoutIsAtLeftPosition;
            QVBoxLayout *mTopBottomLayout;

            mutable QBrush mCommonBrush;
            mutable QSize mCachedSize;
    };

}

#endif
