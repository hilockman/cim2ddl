#ifndef KDCHARTABSTRACTAREA_H
#define KDCHARTABSTRACTAREA_H 

#include <QObject>

#include "KDChartGlobal.h"
#include "KDChartAbstractAreaBase.h"
#include "KDChartLayoutItems.h"

namespace KDChart {
class KDCHART_EXPORT AbstractArea : public QObject,
                                    public AbstractAreaBase,
                                    public AbstractLayoutItem
{
    Q_OBJECT

    Q_DISABLE_COPY( AbstractArea )
    KDCHART_DECLARE_PRIVATE_DERIVED( AbstractArea )

public:
    virtual ~AbstractArea() ;







    virtual void paintIntoRect( QPainter& painter, const QRect& rect );





    virtual void paintAll( QPainter& painter );
    virtual int leftOverlap( bool doNotRecalculate=false ) const;
    virtual int rightOverlap( bool doNotRecalculate=false ) const;
    virtual int topOverlap( bool doNotRecalculate=false ) const;
    virtual int bottomOverlap( bool doNotRecalculate=false ) const;

protected:
    AbstractArea();
    virtual QRect areaGeometry() const;
    virtual void positionHasChanged();

Q_SIGNALS:
    void positionChanged( AbstractArea * );
};

}
#endif
