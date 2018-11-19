#ifndef KDCHARTDATASETPROXYMODEL_H
#define KDCHARTDATASETPROXYMODEL_H 

#include <QVector>
#include <QSortFilterProxyModel>

#include "kdchart_export.h"

namespace KDChart {

    class IndexOutOfBoundsException;

    typedef QVector<int> DatasetDescriptionVector;
    class KDCHART_EXPORT DatasetProxyModel : public QSortFilterProxyModel
    {
        Q_OBJECT
    public:




        explicit DatasetProxyModel ( QObject* parent = 0 );

        QModelIndex buddy( const QModelIndex& index ) const;

        Qt::ItemFlags flags( const QModelIndex& index ) const;

        QModelIndex index( int row, int column,
                           const QModelIndex &parent = QModelIndex() ) const;
        QModelIndex parent(const QModelIndex &child ) const;


        QModelIndex mapFromSource ( const QModelIndex & sourceIndex ) const;


        QModelIndex mapToSource ( const QModelIndex& proxyIndex ) const;


        QVariant data(const QModelIndex &index, int role) const;


        bool setData( const QModelIndex& index, const QVariant& value, int role );


        QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;


        void setSourceModel(QAbstractItemModel *sourceModel);



        void setSourceRootIndex(const QModelIndex& rootIdx);


    public Q_SLOTS:




        void resetDatasetDescriptions();





        void setDatasetColumnDescriptionVector ( const DatasetDescriptionVector& columnConfig );





        void setDatasetRowDescriptionVector ( const DatasetDescriptionVector& rowConfig );


        void setDatasetDescriptionVectors (
            const DatasetDescriptionVector& rowConfig,
            const DatasetDescriptionVector& columnConfig );




    protected:

        bool filterAcceptsColumn ( int sourceColumn,
                                   const QModelIndex & ) const;



        bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;

    private:


        int mapProxyColumnToSource ( const int& proxyColumn ) const;


        int mapSourceColumnToProxy ( const int& sourceColumn ) const;


        int mapProxyRowToSource ( const int& proxyRow ) const;


        int mapSourceRowToProxy ( const int& sourceRow ) const;
        void initializeDatasetDecriptors (
            const DatasetDescriptionVector& inConfiguration,
            int sourceCount,
            DatasetDescriptionVector& outSourceToProxyMap,
            DatasetDescriptionVector& outProxyToSourceMap );

        DatasetDescriptionVector mColSrcToProxyMap;
        DatasetDescriptionVector mColProxyToSrcMap;
        DatasetDescriptionVector mRowSrcToProxyMap;
        DatasetDescriptionVector mRowProxyToSrcMap;

        int mProxyRowCount;
        int mProxyColumnCount;
        QModelIndex mRootIndex;
    };

}


#endif
