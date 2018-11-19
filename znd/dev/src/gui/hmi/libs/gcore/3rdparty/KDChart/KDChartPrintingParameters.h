#ifndef PRINTINGPARAMETERS_H
#define PRINTINGPARAMETERS_H 

#include <QPen>
#include <QDebug>
namespace KDChart {





    class PrintingParameters {
    public:
        static void setScaleFactor( const qreal scaleFactor );
        static void resetScaleFactor();
        static QPen scalePen( const QPen& pen );

    private:
        PrintingParameters();
        static PrintingParameters* instance();

        qreal scaleFactor;
    };
}

#endif
