#ifndef QSCRIPTBREAKPOINTSMODEL_P_H
#define QSCRIPTBREAKPOINTSMODEL_P_H 
#include <QtCore/qabstractitemmodel.h>

#include "qscriptbreakpointdata_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerJobSchedulerInterface;
class QScriptDebuggerCommandSchedulerInterface;

class QScriptBreakpointsModelPrivate;
class Q_AUTOTEST_EXPORT QScriptBreakpointsModel
    : public QAbstractItemModel
{
    Q_OBJECT
public:
    QScriptBreakpointsModel(QScriptDebuggerJobSchedulerInterface *jobScheduler,
                            QScriptDebuggerCommandSchedulerInterface *commandScheduler,
                            QObject *parent = 0);
    ~QScriptBreakpointsModel();

    void setBreakpoint(const QScriptBreakpointData &data);
    void setBreakpointData(int id, const QScriptBreakpointData &data);
    void deleteBreakpoint(int id);

    void addBreakpoint(int id, const QScriptBreakpointData &data);
    void modifyBreakpoint(int id, const QScriptBreakpointData &data);
    void removeBreakpoint(int id);

    int breakpointIdAt(int row) const;
    QScriptBreakpointData breakpointDataAt(int row) const;
    QScriptBreakpointData breakpointData(int id) const;

    int resolveBreakpoint(qint64 scriptId, int lineNumber) const;
    int resolveBreakpoint(const QString &fileName, int lineNumber) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    Q_DECLARE_PRIVATE(QScriptBreakpointsModel)
    Q_DISABLE_COPY(QScriptBreakpointsModel)
};

QT_END_NAMESPACE

#endif
