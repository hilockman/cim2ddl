#ifndef KDCHARTABSTRACTAXIS_H
#define KDCHARTABSTRACTAXIS_H 





#include "kdchart_export.h"
#include "KDChartGlobal.h"
#include "KDChartAbstractArea.h"
#include "KDChartTextAttributes.h"
#include "KDChartRulerAttributes.h"

QT_BEGIN_NAMESPACE
class QPainter;
class QSizeF;
QT_END_NAMESPACE


namespace KDChart {

    class Area;
    class AbstractCoordinatePlane;
    class PaintContext;
    class AbstractDiagram;
    class KDCHART_EXPORT AbstractAxis : public AbstractArea
    {
        Q_OBJECT

        Q_DISABLE_COPY( AbstractAxis )
        KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( AbstractAxis, AbstractDiagram* )

    public:
        explicit AbstractAxis( AbstractDiagram* diagram = 0 );
        virtual ~AbstractAxis();
        virtual const QString customizedLabel( const QString& label ) const;




        bool compare( const AbstractAxis* other ) const;
        void createObserver( AbstractDiagram* diagram );
        void deleteObserver( AbstractDiagram* diagram );
        const AbstractDiagram* diagram() const;
        bool observedBy( AbstractDiagram* diagram ) const;
        virtual void connectSignals();
        void setTextAttributes( const TextAttributes &a );






        TextAttributes textAttributes() const;
        void setRulerAttributes( const RulerAttributes &a );






        RulerAttributes rulerAttributes() const;
        void setLabels( const QStringList& list );






        QStringList labels() const;
        void setShortLabels( const QStringList& list );
        QStringList shortLabels() const;

        virtual void setGeometry( const QRect& rect ) = 0;
        virtual QRect geometry() const = 0;






        const AbstractCoordinatePlane* coordinatePlane() const;

    protected Q_SLOTS:

        virtual void delayedInit();

    public Q_SLOTS:
        void update();

    Q_SIGNALS:
        void coordinateSystemChanged();
    };
}

#endif
