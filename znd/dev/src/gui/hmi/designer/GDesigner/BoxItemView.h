



#ifndef WIDGETBOXCATEGORYLISTVIEW_H
#define WIDGETBOXCATEGORYLISTVIEW_H 



#include <QtGui>
#include <QtCore>
#include <QtWidgets>

class WidgetBoxCategoryEntry {
public:
    WidgetBoxCategoryEntry(const QString &aname=QString() , const QPixmap& icon = QPixmap()
            , int type=0, int is_common =0,const QString& atooltip=QString())
        : m_name(aname) , m_icon(icon),m_type(type),m_is_common(is_common), m_tooltip(atooltip){}
    inline QString Name() const { return m_name; }
    inline QString ToolTip() const {return m_tooltip;}
    inline QIcon Icon() const {return m_icon;}
    inline QString Filter() const {return m_filter;}
    inline int Type() const { return m_type; }

    inline void SetFilter(const QString& filter) {m_filter = filter;}
    inline void SetName(const QString& name) { m_name = name; }
    inline void SetType(const int atype) { m_type = atype; }
    inline void SetTypeName(const QString& aTypeName) { m_typeName = aTypeName; }
    inline void SetIcon(const QIcon& icon){ m_icon = icon;}

    inline bool isNull() const { return m_name.isEmpty(); }
private:
    QString m_name;
    QString m_typeName;
    QString m_tooltip;
    QIcon m_icon;
    QString m_filter;
    int m_type;
    int m_is_common;
};
typedef QList<WidgetBoxCategoryEntry> WidgetBoxCategoryEntrys;

class Category {
public:
    enum Type { Default, Scratchpad };

    Category(const QString &aname = QString(), Type atype = Default)
        : m_name(aname), m_type(atype) {}

    QString name() const { return m_name; }
    void setName(const QString &aname) { m_name = aname; }
    int widgetCount() const { return m_widget_list.size(); }
    WidgetBoxCategoryEntry widget(int idx) const { return m_widget_list.at(idx); }
    void removeWidget(int idx) { m_widget_list.removeAt(idx); }
    void addWidget(const WidgetBoxCategoryEntry &awidget) { m_widget_list.append(awidget); }
    Type type() const { return m_type; }
    void setType(Type atype) { m_type = atype; }

    bool isNull() const { return m_name.isEmpty(); }

private:
    QString m_name;
    Type m_type;
    QList<WidgetBoxCategoryEntry> m_widget_list;
};
typedef QList<Category> CategoryList;

class QSortFilterProxyModel;
class QRegExp;



class WidgetBoxCategoryModel;



class WidgetBoxCategoryListView : public QListView
{
    Q_OBJECT
public:

    enum AccessMode { FilteredAccess, UnfilteredAccess };

    explicit WidgetBoxCategoryListView( QWidget *parent = 0);
    void setViewMode(ViewMode vm);



    using QListView::contentsSize;


    int count(AccessMode am) const;
    WidgetBoxCategoryEntry widgetAt(AccessMode am, const QModelIndex &index) const;
    WidgetBoxCategoryEntry widgetAt(AccessMode am, int row) const;
    void removeRow(AccessMode am, int row);
    void setCurrentItem(AccessMode am, int row);


    void addWidget(const WidgetBoxCategoryEntry &widget);
    bool containsWidget(const QString &name);
    Category category() const;
    bool removeCustomWidgets();




signals:
    void scratchPadChanged();
    void pressed(const QString &name, const QString &xml, const QPoint &globalPos);
    void itemRemoved();
    void lastItemRemoved();

public slots:
    void filter(const QRegExp &re);

private slots:
    void slotPressed(const QModelIndex &index);
    void removeCurrentItem();
    void editCurrentItem();

private:
    int mapRowToSource(int filterRow) const;
    QSortFilterProxyModel *m_proxyModel;
    WidgetBoxCategoryModel *m_model;
};




#endif
