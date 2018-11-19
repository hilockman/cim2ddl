#ifndef KDCHARTCHART_H
#define KDCHARTCHART_H 

#include <QWidget>

#include "kdchart_export.h"
#include "KDChartGlobal.h"
namespace KDChart {

    class BackgroundAttributes;
    class FrameAttributes;
    class AbstractDiagram;
    class AbstractCoordinatePlane;
    class HeaderFooter;
    class Legend;

    typedef QList<AbstractCoordinatePlane*> CoordinatePlaneList;
    typedef QList<HeaderFooter*> HeaderFooterList;
    typedef QList<Legend*> LegendList;
    class KDCHART_EXPORT Chart : public QWidget
    {
        Q_OBJECT

        Q_PROPERTY( int globalLeadingTop READ globalLeadingTop WRITE setGlobalLeadingTop )
        Q_PROPERTY( int globalLeadingBottom READ globalLeadingBottom WRITE setGlobalLeadingBottom )
        Q_PROPERTY( int globalLeadingLeft READ globalLeadingLeft WRITE setGlobalLeadingLeft )
        Q_PROPERTY( int globalLeadingRight READ globalLeadingRight WRITE setGlobalLeadingRight )
        Q_PROPERTY( bool useNewLayoutSystem READ useNewLayoutSystem WRITE setUseNewLayoutSystem )

        KDCHART_DECLARE_PRIVATE_BASE_POLYMORPHIC_QWIDGET( Chart )

    public:
        explicit Chart ( QWidget* parent = 0 );
        ~Chart();
        bool useNewLayoutSystem() const;
        void setUseNewLayoutSystem( bool value );
        void setFrameAttributes( const FrameAttributes &a );
        FrameAttributes frameAttributes() const;
        void setBackgroundAttributes( const BackgroundAttributes &a );
        BackgroundAttributes backgroundAttributes() const;
        AbstractCoordinatePlane* coordinatePlane();





        CoordinatePlaneList coordinatePlanes();







        void addCoordinatePlane( AbstractCoordinatePlane* plane );
  void insertCoordinatePlane( int index, AbstractCoordinatePlane* plane );
        void replaceCoordinatePlane( AbstractCoordinatePlane* plane,
                                     AbstractCoordinatePlane* oldPlane = 0 );
        void takeCoordinatePlane( AbstractCoordinatePlane* plane );






        void setCoordinatePlaneLayout( QLayout * layout );
        QLayout* coordinatePlaneLayout();






        HeaderFooter* headerFooter();





        HeaderFooterList headerFooters();







        void addHeaderFooter( HeaderFooter* headerFooter );
        void replaceHeaderFooter ( HeaderFooter* headerFooter,
                                   HeaderFooter* oldHeaderFooter = 0 );
        void takeHeaderFooter( HeaderFooter* headerFooter );





        Legend* legend();





        LegendList legends();







        void addLegend( Legend* legend );
        void replaceLegend ( Legend* legend, Legend* oldLegend = 0 );
        void takeLegend( Legend* legend );
        void setGlobalLeading( int left, int top, int right, int bottom );
        void setGlobalLeadingLeft( int leading );
        int globalLeadingLeft() const;
        void setGlobalLeadingTop( int leading );
        int globalLeadingTop() const;
        void setGlobalLeadingRight( int leading );
        int globalLeadingRight() const;
        void setGlobalLeadingBottom( int leading );
        int globalLeadingBottom() const;
        void paint( QPainter* painter, const QRect& target );

        void reLayoutFloatingLegends();

    Q_SIGNALS:

        void propertiesChanged();
        void finishedDrawing();

    protected:



                    void resizeEvent ( QResizeEvent * event );
                    void paintEvent( QPaintEvent* event );


        void mousePressEvent( QMouseEvent* event );

        void mouseDoubleClickEvent( QMouseEvent* event );

        void mouseMoveEvent( QMouseEvent* event );

        void mouseReleaseEvent( QMouseEvent* event );

        bool event( QEvent* event );

    private:

        void addLegendInternal( Legend *legend, bool setMeasures );
    };
}
#endif
