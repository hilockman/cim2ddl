#ifndef KDCHART_TEXT_AREA_H
#define KDCHART_TEXT_AREA_H 

#include <QObject>

#include "KDChartGlobal.h"
#include "KDChartAbstractAreaBase.h"
#include "KDChartLayoutItems.h"

namespace KDChart {
class KDCHART_EXPORT TextArea : public QObject, public AbstractAreaBase, public TextLayoutItem
{
    Q_OBJECT

    Q_DISABLE_COPY( TextArea )
    KDCHART_DECLARE_PRIVATE_DERIVED( TextArea )


public:
    virtual ~TextArea() ;
    virtual void paintIntoRect( QPainter& painter, const QRect& rect );





    void paintAll( QPainter& painter );

protected:
    TextArea();
    virtual QRect areaGeometry() const;
    virtual void positionHasChanged();

Q_SIGNALS:
    void positionChanged( TextArea * );


};

}
#endif
