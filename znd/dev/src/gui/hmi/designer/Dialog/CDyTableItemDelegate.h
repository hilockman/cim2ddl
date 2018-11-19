

#ifndef _C_DYTABLE_DELGATE_H
#define _C_DYTABLE_DELGATE_H 

#include <QItemDelegate>


class GCNoEditorDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    GCNoEditorDelegate(QWidget *parent = 0) : QItemDelegate(parent) {};
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void insertColumn( int col );
private:
    QVector<int> m_ReadOnlyCols;
};
class CDyTableDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    CDyTableDelegate(QWidget *parent = 0) : QItemDelegate(parent) {};

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
};

#endif
