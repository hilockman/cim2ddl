#ifndef QSCRIPTDEBUGGERLOCALSMODEL_P_H
#define QSCRIPTDEBUGGERLOCALSMODEL_P_H 
#include <QtCore/qabstractitemmodel.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerValue;
class QScriptDebuggerJobSchedulerInterface;
class QScriptDebuggerCommandSchedulerInterface;

class QScriptDebuggerLocalsModelPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerLocalsModel
    : public QAbstractItemModel
{
    Q_OBJECT
public:
    QScriptDebuggerLocalsModel(QScriptDebuggerJobSchedulerInterface *jobScheduler,
                               QScriptDebuggerCommandSchedulerInterface *commandScheduler,
                               QObject *parent = 0);
    ~QScriptDebuggerLocalsModel();

    void init(int frameIndex);
    void sync(int frameIndex);

    int frameIndex() const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool hasChildren(const QModelIndex &parent) const;
    bool canFetchMore(const QModelIndex &parent) const;
    void fetchMore(const QModelIndex &parent);

Q_SIGNALS:
    void scopeObjectAvailable(const QModelIndex &index);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerLocalsModel)
    Q_DISABLE_COPY(QScriptDebuggerLocalsModel)
};

QT_END_NAMESPACE

#endif
