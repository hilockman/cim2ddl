

#include <QtGui>

#include "ObjectInspector.h"
#include "ActionManager.h"
#include "ItemFactory.h"
#include "ItemBox.h"
#include "BaseData.h"

namespace Qt
{
enum{ItemValueRole = Qt::UserRole+1};
};

class CObjectFilterModel : public QSortFilterProxyModel
{
public:
    CObjectFilterModel(QObject* parent = 0) : m_filterName() {};
    void OnChangeFilterName(const QString& name) {m_filterName = name; invalidateFilter();};

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
    {
        QModelIndex nameIndex = sourceModel()->index(sourceRow, 0, sourceParent);
        return sourceModel()->data(nameIndex).toString().contains(m_filterName, Qt::CaseInsensitive);
    };

private:
    QString m_filterName;
};

QVariant CObjectModel::data( const QModelIndex &index, int role ) const
{
    if(!index.isValid() || index.row()>rowCount() || index.column()>0)
        return QVariant();
    if (!m_itemList[index.row()] || !g_dataPtr(m_itemList[index.row()]))
        return QVariant();
    if(Qt::DisplayRole == role)
        return g_dataPtr(m_itemList[index.row()])->GetName();
    else if(Qt::ItemValueRole == role)
        return QVariant::fromValue(m_itemList[index.row()]);
    else if(Qt::DecorationRole == role)
    {
        int idx=index.row();
        QString tpName = g_dataPtr(m_itemList[idx])->GetSaveTypeName();
        return ItemTreeModel::nameToIconHash[tpName];
    }
    return QVariant();
}

bool CObjectModel::setData( const QModelIndex &index, const QVariant& value, int role )
{
    if(!index.isValid() || index.row()>rowCount() || index.column()>0)
        return false;

    if(Qt::DisplayRole == role)
    {
        g_dataPtr(m_itemList[index.row()])->SetName(value.toString());
        emit dataChanged(index, index);
        return true;
    }

    else if(Qt::ItemValueRole == role)
    {
        m_itemList[index.row()] = value.value<QGraphicsItem*>();
        return true;
    }

    return false;
}

QVariant CObjectModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if(section == 0 && orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return QObject::tr("Object");

    return QVariant();
}
bool CObjectModel::insertRows( int row, int count, const QModelIndex &parent )
{
    if (count < 1 || row > rowCount(parent))
        return false;

    beginInsertRows(QModelIndex(), row, row + count - 1);
    for (int r = row; r < row + count; ++r)
    {
        m_itemList.push_front(NULL);
    }
    endInsertRows();

    return true;

}

bool CObjectModel::removeRows( int row, int count, const QModelIndex &parent )
{
    if (count < 1 || row > rowCount(parent))
        return false;

    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for (int r = row; r < row + count; ++r)
    {
        m_itemList.removeAt(r);
    }
    endRemoveRows();

    return true;
}

bool CObjectModel::insertRow( int row, const QModelIndex &parent )
{
    if (row < 0 || row > rowCount(parent))
        return false;

    beginInsertRows(QModelIndex(), row, row);
    m_itemList.push_front(NULL);
    endInsertRows();

    return true;

}

bool CObjectModel::removeRow( int row, const QModelIndex &parent )
{
    if (row < 0 || row > rowCount(parent))
        return false;

    beginRemoveRows(QModelIndex(), row, row);
    m_itemList.removeAt(row);
    endRemoveRows();

    return true;
}



CObjectInspector::CObjectInspector(CObjectModel* sourceModel, QWidget* parent )
    : QWidget(parent)
{
    m_proxyModel = new CObjectFilterModel(this);
    m_proxyModel->setSourceModel(sourceModel);
    m_proxyModel->setDynamicSortFilter(true);

    m_vboxLayout = new QVBoxLayout(this);
    m_vboxLayout->setMargin(0);

    m_filterEdit = new QLineEdit(this);
    connect(m_filterEdit, SIGNAL(textChanged(const QString&)), this, SLOT(OnFilting(const QString&)));
    m_vboxLayout->addWidget(m_filterEdit);

    m_objView = new QListView(this);
    m_objView->setIconSize(QSize(36, 36));
    m_objView->setAlternatingRowColors(true);
    m_objView->setModel(m_proxyModel);
    m_vboxLayout->addWidget(m_objView);

    QObject::connect(m_objView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(OnTreeViewClicked(const QModelIndex&)));
    setLayout(m_vboxLayout);
}

CObjectInspector::~CObjectInspector()
{

}

void CObjectInspector::OnFilting( const QString& objName )
{
    m_proxyModel->OnChangeFilterName(objName);
}

void CObjectInspector::OnTreeViewClicked( const QModelIndex& index )
{
    Qt::MouseButtons btn = QApplication::mouseButtons();
    QModelIndex mapIndex = m_proxyModel->mapToSource(index);

    QGraphicsItem* item = m_proxyModel->sourceModel()->data(mapIndex, Qt::ItemValueRole).value<QGraphicsItem*>();
    Q_ASSERT(item);

    emit SIGItemClicked(item);
}

void CObjectInspector::contextMenuEvent( QContextMenuEvent* e )
{
    if(!m_objView->currentIndex().isValid())
        return;

    QMenu menu;
    UnqActMng()->CreateContextMenu(menu);
    menu.exec(QCursor::pos());
}

void CObjectInspector::OnUpdateModel()
{
    m_proxyModel->invalidate();
}
