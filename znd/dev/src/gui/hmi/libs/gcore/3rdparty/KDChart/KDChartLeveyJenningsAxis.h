#ifndef KDCHARTLEVEYJENNINGSAXIS_H
#define KDCHARTLEVEYJENNINGSAXIS_H 

#include <QList>

#include "KDChartCartesianAxis.h"

#include "KDChartLeveyJenningsGridAttributes.h"

namespace KDChart {

    class LeveyJenningsDiagram;
    class KDCHART_EXPORT LeveyJenningsAxis : public CartesianAxis
    {
        Q_OBJECT

        Q_DISABLE_COPY( LeveyJenningsAxis )
        KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( LeveyJenningsAxis, AbstractDiagram* )

    public:
        explicit LeveyJenningsAxis ( LeveyJenningsDiagram* diagram = 0 );
        ~LeveyJenningsAxis();

        LeveyJenningsGridAttributes::GridType type() const;
        void setType( LeveyJenningsGridAttributes::GridType type );

        Qt::DateFormat dateFormat() const;
        void setDateFormat( Qt::DateFormat format );




        bool compare( const LeveyJenningsAxis* other ) const;


        void paintCtx( PaintContext* );

    protected:
        virtual void paintAsOrdinate( PaintContext* );

        virtual void paintAsAbscissa( PaintContext* );
    };

    typedef QList<LeveyJenningsAxis*> LeveyJenningsAxisList;
}

#endif
