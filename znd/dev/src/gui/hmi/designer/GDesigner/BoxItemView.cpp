

#include "BoxItemView.h"



#include <QtDesigner/QDesignerFormEditorInterface>
#include <QtDesigner/QDesignerWidgetDataBaseInterface>

#include <QtXml>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>

static const char *widgetElementC = "widget";
static const char *nameAttributeC = "name";
static const char *uiOpeningTagC = "<ui>";
static const char *uiClosingTagC = "</ui>";



enum { FilterRole = Qt::UserRole + 11 };

static QString domToString(const QDomElement &elt)
{
    QString result;
    QTextStream stream(&result, QIODevice::WriteOnly);
    elt.save(stream, 2);
    stream.flush();
    return result;
}

static QDomDocument stringToDom(const QString &xml)
{
    QDomDocument result;
    result.setContent(xml);
    return result;
}




#if 0
struct WidgetBoxCategoryEntry {
    WidgetBoxCategoryEntry();
    explicit WidgetBoxCategoryEntry(const Widget &widget,
                                    const QString &filter,
                                    const QIcon &icon,
                                    bool editable);

    Widget widget;
    QString toolTip;
    QString whatsThis;
    QString filter;
    QIcon icon;
    bool editable;
};


WidgetBoxCategoryEntry::WidgetBoxCategoryEntry() :
    editable(false)
{
}

WidgetBoxCategoryEntry::WidgetBoxCategoryEntry(const Widget &w,
                                               const QString &filterIn,
                                               const QIcon &i, bool e) :
    widget(w),
    filter(filterIn),
    icon(i),
    editable(e)
{
}
#endif





class WidgetBoxCategoryModel : public QAbstractListModel {
public:
    explicit WidgetBoxCategoryModel( QObject *parent = 0);


    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags (const QModelIndex & index ) const;
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());


    QListView::ViewMode viewMode() const;
    void setViewMode(QListView::ViewMode vm);

    void addWidget(const WidgetBoxCategoryEntry &widget);

    WidgetBoxCategoryEntry widgetAt(const QModelIndex & index) const;
    WidgetBoxCategoryEntry widgetAt(int row) const;

    int indexOfWidget(const QString &name);




private:

    QRegExp m_classNameRegExp;

    WidgetBoxCategoryEntrys m_items;
    QListView::ViewMode m_viewMode;
};

WidgetBoxCategoryModel::WidgetBoxCategoryModel(QObject *parent) :
    QAbstractListModel(parent),
    m_classNameRegExp(QLatin1String("<widget +class *= *\"([^\"]+)\"")),
    m_viewMode(QListView::ListMode)
{
    Q_ASSERT(m_classNameRegExp.isValid());
}

QListView::ViewMode WidgetBoxCategoryModel::viewMode() const
{
    return m_viewMode;
}

void WidgetBoxCategoryModel::setViewMode(QListView::ViewMode vm)
{
    if (m_viewMode == vm)
        return;
    m_viewMode = vm;
    if (!m_items.empty())
    {

        beginResetModel();
        endResetModel();
    }
}

int WidgetBoxCategoryModel::indexOfWidget(const QString &name)
{
    const int count = m_items.size();
    for (int i = 0; i < count; i++)
        if (m_items.at(i).Name() == name)
            return i;
    return -1;
}
#if 0
Category WidgetBoxCategoryModel::category() const
{
    Category rc;
    const WidgetBoxCategoryEntrys::const_iterator cend = m_items.constEnd();
    for (WidgetBoxCategoryEntrys::const_iterator it = m_items.constBegin(); it != cend; ++it)
        rc.addWidget(it->widget);
    return rc;
}


bool WidgetBoxCategoryModel::removeCustomWidgets()
{


    bool changed = false;
    for (WidgetBoxCategoryEntrys::iterator it = m_items.begin(); it != m_items.end(); )
        if (it->widget.type() == Widget::Custom) {
            it = m_items.erase(it);
            changed = true;
        } else {
            ++it;
        }
    if (changed)
        reset();
    return changed;
}
#endif
void WidgetBoxCategoryModel::addWidget(const WidgetBoxCategoryEntry &widget)
{
#if 0


    QString filter = widget.name();
    if (!filter.contains(QLatin1String("Layout")) && m_classNameRegExp.indexIn(widget.domXml()) != -1) {
        const QString className = m_classNameRegExp.cap(1);
        if (!filter.contains(className))
            filter += className;
    }
    WidgetBoxCategoryEntry item(widget, filter, icon, editable);


    if (dbIndex != -1) {
        const QDesignerWidgetDataBaseItemInterface *dbItem = db->item(dbIndex);
        const QString toolTip = dbItem->toolTip();
        if (!toolTip.isEmpty())
            item.toolTip = toolTip;
        const QString whatsThis = dbItem->whatsThis();
        if (!whatsThis.isEmpty())
            item.whatsThis = whatsThis;
    }
#endif

    const int row = m_items.size();
    beginInsertRows(QModelIndex(), row, row);
    m_items.push_back(widget);
    endInsertRows();
}

QVariant WidgetBoxCategoryModel::data(const QModelIndex &index, int role) const
{
    const int row = index.row();
    if (row < 0 || row >= m_items.size())
        return QVariant();

    const WidgetBoxCategoryEntry &item = m_items.at(row);
    switch (role) {
    case Qt::DisplayRole:

        return QVariant(m_viewMode == QListView::ListMode ? item.Name() : QString());
    case Qt::DecorationRole:
        return QVariant(item.Icon());
    case Qt::EditRole:
        return QVariant(item.Name());
    case Qt::ToolTipRole: {
        if (m_viewMode == QListView::ListMode)
            return QVariant(item.ToolTip());

        QString tt = item.Name();
        if (!item.ToolTip().isEmpty()) {
            tt += QLatin1Char('\n');
            tt += item.ToolTip();
        }
        return QVariant(tt);

    }

    case FilterRole:
        return item.Filter();
    }
    return QVariant();
}

bool WidgetBoxCategoryModel::setData(const QModelIndex &index, const QVariant& value, int role)
{
    return false;
#if 0
    const int row = index.row();
    if (role != Qt::EditRole || row < 0 || row >= m_items.size() || value.type() != QVariant::String)
        return false;

    WidgetBoxCategoryEntry &item = m_items[row];
    const QString newName = value.toString();
    item.widget.setName(newName);

    const QDomDocument doc = stringToDom(WidgetBoxCategoryListView::widgetDomXml(item.widget));
    QDomElement widget_elt = doc.firstChildElement(QLatin1String(widgetElementC));
    if (!widget_elt.isNull()) {
        widget_elt.setAttribute(QLatin1String(nameAttributeC), newName);
        item.widget.setDomXml(domToString(widget_elt));
    }
    emit dataChanged(index, index);
    return true;
#endif
}

Qt::ItemFlags WidgetBoxCategoryModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags rc = Qt::ItemIsEnabled;
#if 0
    const int row = index.row();
    if (row >= 0 && row < m_items.size())
        if (m_items.at(row).editable) {
            rc |= Qt::ItemIsSelectable;

            if (m_viewMode == QListView::ListMode)
                rc |= Qt::ItemIsEditable;
        }
#endif
    return rc;
}

int WidgetBoxCategoryModel::rowCount(const QModelIndex & ) const
{
    return m_items.size();
}

bool WidgetBoxCategoryModel::removeRows(int row, int count, const QModelIndex & parent)
{
    if (row < 0 || count < 1)
        return false;
    const int size = m_items.size();
    const int last = row + count - 1;
    if (row >= size || last >= size)
        return false;
    beginRemoveRows(parent, row, last);
    for (int r = last; r >= row; r--)
        m_items.removeAt(r);
    endRemoveRows();
    return true;
}

WidgetBoxCategoryEntry WidgetBoxCategoryModel::widgetAt(const QModelIndex & index) const
{
    return widgetAt(index.row());
}

WidgetBoxCategoryEntry WidgetBoxCategoryModel::widgetAt(int row) const
{
    if (row < 0 || row >= m_items.size())
        return WidgetBoxCategoryEntry();
    return m_items.at(row);
}



class WidgetBoxCategoryEntryDelegate : public QItemDelegate
{
public:
    explicit WidgetBoxCategoryEntryDelegate(QWidget *parent = 0) : QItemDelegate(parent) {}
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
};

QWidget *WidgetBoxCategoryEntryDelegate::createEditor(QWidget *parent,
                                                      const QStyleOptionViewItem &option,
                                                      const QModelIndex &index) const
{
    QWidget *result = QItemDelegate::createEditor(parent, option, index);
    if (QLineEdit *line_edit = qobject_cast<QLineEdit*>(result)) {
        const QRegExp re = QRegExp(QLatin1String("[_a-zA-Z][_a-zA-Z0-9]*"));
        Q_ASSERT(re.isValid());
        line_edit->setValidator(new QRegExpValidator(re, line_edit));
    }
    return result;
}



WidgetBoxCategoryListView::WidgetBoxCategoryListView(QWidget *parent) :
    QListView(parent),
    m_proxyModel(new QSortFilterProxyModel(this)),
    m_model(new WidgetBoxCategoryModel(this))
{
    setFocusPolicy(Qt::NoFocus);
    setFrameShape(QFrame::NoFrame);
    setIconSize(QSize(22, 22));
    setSpacing(1);
    setTextElideMode(Qt::ElideMiddle);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setResizeMode(QListView::Adjust);
    setUniformItemSizes(true);

    setItemDelegate(new WidgetBoxCategoryEntryDelegate(this));

    connect(this, SIGNAL(pressed(QModelIndex)), this, SLOT(slotPressed(QModelIndex)));
    setEditTriggers(QAbstractItemView::AnyKeyPressed);

    m_proxyModel->setSourceModel(m_model);
    m_proxyModel->setFilterRole(FilterRole);
    setModel(m_proxyModel);
    connect(m_model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SIGNAL(scratchPadChanged()));
}

void WidgetBoxCategoryListView::setViewMode(ViewMode vm)
{
    QListView::setViewMode(vm);
    m_model->setViewMode(vm);
}

void WidgetBoxCategoryListView::setCurrentItem(AccessMode am, int row)
{
    const QModelIndex index = am == FilteredAccess ?
                m_proxyModel->index(row, 0) :
                m_proxyModel->mapFromSource(m_model->index(row, 0));

    if (index.isValid())
        setCurrentIndex(index);
}

void WidgetBoxCategoryListView::slotPressed(const QModelIndex &index)
{
    const WidgetBoxCategoryEntry wgt = m_model->widgetAt(m_proxyModel->mapToSource(index));
    if (wgt.isNull())
        return;

}

void WidgetBoxCategoryListView::removeCurrentItem()
{
    const QModelIndex index = currentIndex();
    if (!index.isValid() || !m_proxyModel->removeRow(index.row()))
        return;



    if (m_model->rowCount()) {
        emit itemRemoved();
    } else {
        emit lastItemRemoved();
    }
}

void WidgetBoxCategoryListView::editCurrentItem()
{
    const QModelIndex index = currentIndex();
    if (index.isValid())
        edit(index);
}

int WidgetBoxCategoryListView::count(AccessMode am) const
{
    return am == FilteredAccess ? m_proxyModel->rowCount() : m_model->rowCount();
}

int WidgetBoxCategoryListView::mapRowToSource(int filterRow) const
{
    const QModelIndex filterIndex = m_proxyModel->index(filterRow, 0);
    return m_proxyModel->mapToSource(filterIndex).row();
}

WidgetBoxCategoryEntry WidgetBoxCategoryListView::widgetAt(AccessMode am, const QModelIndex & index) const
{
    const QModelIndex unfilteredIndex = am == FilteredAccess ? m_proxyModel->mapToSource(index) : index;
    return m_model->widgetAt(unfilteredIndex);
}

WidgetBoxCategoryEntry WidgetBoxCategoryListView::widgetAt(AccessMode am, int row) const
{
    return m_model->widgetAt(am == UnfilteredAccess ? row : mapRowToSource(row));
}

void WidgetBoxCategoryListView::removeRow(AccessMode am, int row)
{
    m_model->removeRow(am == UnfilteredAccess ? row : mapRowToSource(row));
}

bool WidgetBoxCategoryListView::containsWidget(const QString &name)
{
    return m_model->indexOfWidget(name) != -1;
}

void WidgetBoxCategoryListView::addWidget(const WidgetBoxCategoryEntry &widget)
{
    m_model->addWidget(widget);
}
#if 0
QString WidgetBoxCategoryListView::widgetDomXml(const WidgetBoxCategoryEntry &widget)
{
    QString domXml = widget.domXml();

    if (domXml.isEmpty()) {
        domXml = QLatin1String(uiOpeningTagC);
        domXml += QLatin1String("<widget class=\"");
        domXml += widget.name();
        domXml += QLatin1String("\"/>");
        domXml += QLatin1String(uiClosingTagC);
    }
    return domXml;
}
#endif

void WidgetBoxCategoryListView::filter(const QRegExp &re)
{
    m_proxyModel->setFilterRegExp(re);
}
