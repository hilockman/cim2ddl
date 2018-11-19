#ifndef KDCHARTTERNARYGRID_H
#define KDCHARTTERNARYGRID_H 

#include <QList>

#include "KDChartAbstractGrid.h"
#include "KDChartTextLabelCache.h"

namespace KDChart {

    struct TickInfo {
        TickInfo( qreal percentage = 0, int depth = 0 );
        qreal percentage;
        int depth;
    };

    bool operator==(const TickInfo&, const TickInfo& );

    class PaintContext;


    class TernaryGrid : public AbstractGrid
    {
    public:
        TernaryGrid();

        virtual ~TernaryGrid();

        void drawGrid( PaintContext* context );
        DataDimensionsList calculateGrid( const DataDimensionsList& rawDataDimensions ) const;
        QPair<QSizeF, QSizeF> requiredMargins() const;





        const QVector<TickInfo>& tickInfo() const;
    private:
        QVector<TickInfo> m_tickInfo;

    };

}

#endif
