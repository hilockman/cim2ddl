#ifndef __KDCHART_ATTRIBUTES_MODEL_H__
#define __KDCHART_ATTRIBUTES_MODEL_H__ 

#include "KDChartAbstractProxyModel.h"
#include <QMap>
#include <QVariant>

#include "KDChartGlobal.h"

namespace KDChart {
class KDCHART_EXPORT AttributesModel : public AbstractProxyModel
{
    Q_OBJECT
    KDCHART_DECLARE_PRIVATE_BASE_POLYMORPHIC( AttributesModel )
public:
    enum PaletteType {
        PaletteTypeDefault = 0,
        PaletteTypeRainbow = 1,
        PaletteTypeSubdued = 2
    };

    explicit AttributesModel( QAbstractItemModel* model, QObject * parent = 0 );
    ~AttributesModel();




    void initFrom( const AttributesModel* other );




    bool compare( const AttributesModel* other ) const;

    bool compareAttributes( int role, const QVariant& a, const QVariant& b ) const;


    bool setModelData( const QVariant value, int role );
    QVariant modelData( int role ) const;



    bool isKnownAttributesRole( int role ) const;


    void setPaletteType( PaletteType type );
    PaletteType paletteType() const;




    QVariant data(int role) const;




    QVariant data(int column, int role) const;


    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

    int rowCount(const QModelIndex& ) const;

    int columnCount(const QModelIndex& ) const;

    QVariant data(const QModelIndex&, int role = Qt::DisplayRole) const;

    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::DisplayRole);

    bool resetData ( const QModelIndex & index, int role = Qt::DisplayRole);

    bool setHeaderData ( int section, Qt::Orientation orientation, const QVariant & value,
                         int role = Qt::DisplayRole);

    virtual QVariant defaultHeaderData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

    bool resetHeaderData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole);

    void setSourceModel ( QAbstractItemModel* sourceModel );



    void setDefaultForRole( int role, const QVariant& value );


    void setDatasetDimension( int dimension );
    int datasetDimension() const;

Q_SIGNALS:
    void attributesChanged( const QModelIndex&, const QModelIndex& );

private Q_SLOTS:
    void slotRowsAboutToBeInserted( const QModelIndex& parent, int start, int end );
    void slotColumnsAboutToBeInserted( const QModelIndex& parent, int start, int end );
    void slotRowsInserted( const QModelIndex& parent, int start, int end );
    void slotColumnsInserted( const QModelIndex& parent, int start, int end );

    void slotRowsAboutToBeRemoved( const QModelIndex& parent, int start, int end );
    void slotColumnsAboutToBeRemoved( const QModelIndex& parent, int start, int end );
    void slotRowsRemoved( const QModelIndex& parent, int start, int end );
    void slotColumnsRemoved( const QModelIndex& parent, int start, int end );

    void slotDataChanged( const QModelIndex& topLeft, const QModelIndex& bottomRight );

private:

    QVariant defaultsForRole( int role ) const;
    bool compareHeaderDataMaps( const QMap< int, QMap< int, QVariant > >& mapA,
                                const QMap< int, QMap< int, QVariant > >& mapB ) const;

    void removeEntriesFromDataMap( int start, int end );
    void removeEntriesFromDirectionDataMaps( Qt::Orientation dir, int start, int end );
};

}

#endif
