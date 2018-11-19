#ifndef KDCHARTABSTRACTAREAWIDGET_H
#define KDCHARTABSTRACTAREAWIDGET_H 

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include "KDChartAbstractAreaBase.h"

namespace KDChart {
class KDCHART_EXPORT AbstractAreaWidget : public QWidget, public AbstractAreaBase
{
    Q_OBJECT

    Q_DISABLE_COPY( AbstractAreaWidget )
    KDCHART_DECLARE_PRIVATE_DERIVED_QWIDGET( AbstractAreaWidget )

public:
    explicit AbstractAreaWidget( QWidget* parent = 0 );
    virtual void paintEvent( QPaintEvent* event );







    virtual void paintIntoRect( QPainter& painter, const QRect& rect );
    virtual void paint( QPainter* painter ) = 0;





    void paintAll( QPainter& painter );




    virtual void forceRebuild();






    virtual void needSizeHint();

    virtual void resizeLayout( const QSize& );

protected:
    virtual ~AbstractAreaWidget() ;
    virtual QRect areaGeometry() const;
    virtual void positionHasChanged();


public:


Q_SIGNALS:
    void positionChanged( AbstractAreaWidget * );

};

}
#endif
