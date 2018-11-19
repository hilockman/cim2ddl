#ifndef __KDCHARTWIDGET_H__
#define __KDCHARTWIDGET_H__ 

#include "KDChartGlobal.h"

#include <QWidget>

#include "KDChartEnums.h"
#include "KDChartHeaderFooter.h"

QT_BEGIN_NAMESPACE
template <typename T> class QVector;
template <typename T1, typename T2> struct QPair;
QT_END_NAMESPACE

namespace KDChart {


    class AbstractDiagram;
    class Chart;
    class AbstractCoordinatePlane;
    class TableModel;
    class BarDiagram;
    class LineDiagram;
    class Plotter;
    class PieDiagram;
    class RingDiagram;
    class PolarDiagram;
    class Legend;
    class Position;







    class KDCHART_EXPORT Widget : public QWidget
    {
        Q_OBJECT

        Q_DISABLE_COPY( Widget )
        KDCHART_DECLARE_PRIVATE_BASE_POLYMORPHIC_QWIDGET( Widget )

    public:







        explicit Widget( QWidget* parent = 0 );


        ~Widget();

        void setDataset( int column, const QVector< qreal > & data, const QString& title = QString() );


        void setDataset( int column, const QVector< QPair< qreal, qreal > > & data, const QString& title = QString() );

        void setDataCell( int row, int column, qreal data );

        void setDataCell( int row, int column, QPair< qreal, qreal > data );

        void resetData();

    public Q_SLOTS:

        void setGlobalLeading( int left, int top, int right, int bottom );

        void setGlobalLeadingLeft( int leading );

        void setGlobalLeadingTop( int leading );

        void setGlobalLeadingRight( int leading );

        void setGlobalLeadingBottom( int leading );

    public:

        int globalLeadingLeft() const;

        int globalLeadingTop() const;

        int globalLeadingRight() const;

        int globalLeadingBottom() const;


        HeaderFooter* firstHeaderFooter();

        QList<HeaderFooter*> allHeadersFooters();


        void addHeaderFooter( const QString& text,
                              HeaderFooter::HeaderFooterType type,
                              Position position );





        void addHeaderFooter( HeaderFooter* header );
        void replaceHeaderFooter( HeaderFooter* header,
                                  HeaderFooter* oldHeader = 0 );
        void takeHeaderFooter( HeaderFooter* header );


        Legend* legend();

        QList<Legend*> allLegends();


        void addLegend( Position position );

        void addLegend (Legend* legend );

        void replaceLegend( Legend* legend, Legend* oldLegend = 0 );
        void takeLegend( Legend* legend );



        AbstractDiagram* diagram();




        BarDiagram* barDiagram();



        LineDiagram* lineDiagram();







        Plotter* plotter();



        PieDiagram* pieDiagram();



        RingDiagram* ringDiagram();



        PolarDiagram* polarDiagram();


        AbstractCoordinatePlane* coordinatePlane();


        enum ChartType { NoType, Bar, Line, Plot, Pie, Ring, Polar };


        ChartType type() const;


        enum SubType { Normal, Stacked, Percent, Rows };


        SubType subType() const;

    public Q_SLOTS:

        void setType( ChartType chartType, SubType subType=Normal );
        void setSubType( SubType subType );

    private:

        void justifyModelSize( int rows, int columns );

        bool checkDatasetWidth( int width );
    };
}

#endif
