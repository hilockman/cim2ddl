

#ifndef OBJECINSPECTOR_H
#define OBJECINSPECTOR_H 

#include <QWidget>
#include <QAbstractListModel>

class QListView;
class QTreeView;
class QLineEdit;
class QVBoxLayout;
class QModelIndex;
class QGraphicsItem;
class QGraphicsScene;
class CObjectFilterModel;


class CObjectModel : public QAbstractListModel
{
    Q_OBJECT

    friend class CNameManager;
public:
    CObjectModel(QObject* parent=0) : QAbstractListModel(parent) {};
    ~CObjectModel() {};
    int rowCount(const QModelIndex &parent = QModelIndex()) const {Q_UNUSED(parent); return m_itemList.size();};
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
    bool setData(const QModelIndex &index, const QVariant& value, int role = Qt::EditRole);
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;


    bool insertRow(int row, const QModelIndex &parent = QModelIndex());
    bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    void Clear() {removeRows(0, rowCount());};
    QList<QGraphicsItem*>& ItemsList() {return m_itemList;};

private:
    QList<QGraphicsItem*> m_itemList;
};


class CObjectInspector : public QWidget
{
    Q_OBJECT
public:
    CObjectInspector(CObjectModel* sourceModel, QWidget* parent=0) ;
    ~CObjectInspector();

public slots:
    void OnUpdateModel();
signals:
    void SIGItemClicked(QGraphicsItem*);
private slots:
    void OnFilting(const QString& objName);
    void OnTreeViewClicked(const QModelIndex& index);

protected:
    void contextMenuEvent(QContextMenuEvent* e);

private:
    QListView* m_objView;
    QLineEdit* m_filterEdit;
    QVBoxLayout* m_vboxLayout;
    CObjectFilterModel* m_proxyModel;
    CObjectModel* m_sourceModel;
};
#endif
