

#ifndef CCHARTTABLEMODEL_H
#define CCHARTTABLEMODEL_H 

#include <QVariant>
#include <QVector>
#include <QAbstractTableModel>
#include <QStringList>
#include "Export.h"

class DLL_CLASS CChartTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CChartTableModel(QObject * parent = 0 );
    ~CChartTableModel ();

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const ;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    int rowCount(const QModelIndex& parent = QModelIndex())const;
    int columnCount(const QModelIndex& parent = QModelIndex())const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
    const QString titleText() const { return m_titleText; };
    void setTitleText( const QString& txt){ m_titleText = txt; };
    QVector<QVector<qreal> >& DataVecVec() {return m_dataVecVec;};
    void clear();
    void setDataHasHorizontalHeaders( bool value) {m_dataHasHorizontalHeaders = value; };
    void setDataHasVerticalHeaders( bool value) {m_dataHasVerticalHeaders = value; };
    void setSupplyHeaderData( bool value) {m_supplyHeaderData = value; };
    bool loadFromCSV ( const QString& filename );
    void TestInit();
protected:

    QVector< QVector<qreal> > m_dataVecVec;

private:


    QStringList m_horizontalHeaderData;
    QStringList m_verticalHeaderData;
    QString m_titleText;
    bool m_dataHasHorizontalHeaders;
    bool m_dataHasVerticalHeaders;
    bool m_supplyHeaderData;
};


#endif
