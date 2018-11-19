#ifndef KDCHARTABSTRACTPROXYMODEL_H
#define KDCHARTABSTRACTPROXYMODEL_H 

#include <QAbstractProxyModel>

#include "KDChartGlobal.h"

namespace KDChart
{




    class KDCHART_EXPORT AbstractProxyModel : public QAbstractProxyModel
    {
        Q_OBJECT
    public:
        explicit AbstractProxyModel( QObject* parent = 0 );


        QModelIndex mapFromSource( const QModelIndex & sourceIndex ) const;

        QModelIndex mapToSource( const QModelIndex &proxyIndex ) const;


        QModelIndex index( int row, int col, const QModelIndex& index ) const;

        QModelIndex parent( const QModelIndex& index ) const;
    };
}

#endif
