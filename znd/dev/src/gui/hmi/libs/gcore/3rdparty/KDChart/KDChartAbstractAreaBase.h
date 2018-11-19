#ifndef KDCHARTABSTRACTAREABASE_H
#define KDCHARTABSTRACTAREABASE_H 

#include <QPointF>
#include <QSizeF>
#include <QRectF>

#include "KDChartGlobal.h"
#include "KDChartLayoutItems.h"
#include "KDChartRelativePosition.h"
#include "KDChartAbstractAreaBase.h"


QT_BEGIN_NAMESPACE
class QPainter;
class QString;
QT_END_NAMESPACE

namespace KDChart {
    class TextAttributes;
    class BackgroundAttributes;
    class FrameAttributes;
    class PaintContext;
class KDCHART_EXPORT AbstractAreaBase
{
    Q_DISABLE_COPY( AbstractAreaBase )
    KDCHART_DECLARE_PRIVATE_BASE_POLYMORPHIC( AbstractAreaBase )

protected:
    AbstractAreaBase();
    virtual ~AbstractAreaBase() ;

public:





    bool compare( const AbstractAreaBase* other ) const;

    void alignToReferencePoint( const RelativePosition& position );

    void setFrameAttributes( const FrameAttributes &a );
    FrameAttributes frameAttributes() const;

    void setBackgroundAttributes( const BackgroundAttributes &a );
    BackgroundAttributes backgroundAttributes() const;

    virtual void paintBackground( QPainter& painter, const QRect& rectangle );
    virtual void paintFrame( QPainter& painter, const QRect& rectangle );

    static void paintBackgroundAttributes( QPainter& painter, const QRect& rectangle,
        const KDChart::BackgroundAttributes& attributes );
    static void paintFrameAttributes( QPainter& painter, const QRect& rectangle,
        const KDChart::FrameAttributes& attributes );






    void getFrameLeadings(int& left, int& top, int& right, int& bottom ) const;


protected:





    QRect innerRect() const;






    virtual QRect areaGeometry() const = 0;







    virtual void positionHasChanged();

};

}
#endif
