#include "qscriptbreakpointsmodel_p.h"
#include "qscriptdebuggerjobschedulerinterface_p.h"
#include "qscriptdebuggercommandschedulerjob_p.h"
#include "qscriptdebuggercommandschedulerfrontend_p.h"

#include "private/qabstractitemmodel_p.h"

#include <QtCore/qpair.h>
#include <QtCore/qcoreapplication.h>
#include <QtGui/qicon.h>
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE







class QScriptBreakpointsModelPrivate
    : public QAbstractItemModelPrivate
{
    Q_DECLARE_PUBLIC(QScriptBreakpointsModel)
public:
    QScriptBreakpointsModelPrivate();
    ~QScriptBreakpointsModelPrivate();

    QScriptDebuggerJobSchedulerInterface *jobScheduler;
    QScriptDebuggerCommandSchedulerInterface *commandScheduler;
    QList<QPair<int, QScriptBreakpointData> > breakpoints;
};

QScriptBreakpointsModelPrivate::QScriptBreakpointsModelPrivate()
{
}

QScriptBreakpointsModelPrivate::~QScriptBreakpointsModelPrivate()
{
}

QScriptBreakpointsModel::QScriptBreakpointsModel(
    QScriptDebuggerJobSchedulerInterface *jobScheduler,
    QScriptDebuggerCommandSchedulerInterface *commandScheduler,
    QObject *parent)
    : QAbstractItemModel(*new QScriptBreakpointsModelPrivate, parent)
{
    Q_D(QScriptBreakpointsModel);
    d->jobScheduler = jobScheduler;
    d->commandScheduler = commandScheduler;
}

QScriptBreakpointsModel::~QScriptBreakpointsModel()
{
}

namespace
{

class SetBreakpointJob : public QScriptDebuggerCommandSchedulerJob
{
public:
    SetBreakpointJob(const QScriptBreakpointData &data,
                     QScriptDebuggerCommandSchedulerInterface *scheduler)
        : QScriptDebuggerCommandSchedulerJob(scheduler),
          m_data(data)
    { }

    void start()
    {
        QScriptDebuggerCommandSchedulerFrontend frontend(commandScheduler(), this);
        frontend.scheduleSetBreakpoint(m_data);
    }

    void handleResponse(const QScriptDebuggerResponse &, int)
    {
        finish();
    }

private:
    QScriptBreakpointData m_data;
};

}






void QScriptBreakpointsModel::setBreakpoint(const QScriptBreakpointData &data)
{
    Q_D(QScriptBreakpointsModel);
    QScriptDebuggerJob *job = new SetBreakpointJob(data, d->commandScheduler);
    d->jobScheduler->scheduleJob(job);
}

namespace
{

class SetBreakpointDataJob : public QScriptDebuggerCommandSchedulerJob
{
public:
    SetBreakpointDataJob(int id, const QScriptBreakpointData &data,
                         QScriptDebuggerCommandSchedulerInterface *scheduler)
        : QScriptDebuggerCommandSchedulerJob(scheduler),
          m_id(id), m_data(data)
    { }

    void start()
    {
        QScriptDebuggerCommandSchedulerFrontend frontend(commandScheduler(), this);
        frontend.scheduleSetBreakpointData(m_id, m_data);
    }

    void handleResponse(const QScriptDebuggerResponse &, int)
    {
        finish();
    }

private:
    int m_id;
    QScriptBreakpointData m_data;
};

}






void QScriptBreakpointsModel::setBreakpointData(int id, const QScriptBreakpointData &data)
{
    Q_D(QScriptBreakpointsModel);
    QScriptDebuggerJob *job = new SetBreakpointDataJob(id, data, d->commandScheduler);
    d->jobScheduler->scheduleJob(job);
}

namespace
{

class DeleteBreakpointJob : public QScriptDebuggerCommandSchedulerJob
{
public:
    DeleteBreakpointJob(int id, QScriptDebuggerCommandSchedulerInterface *scheduler)
        : QScriptDebuggerCommandSchedulerJob(scheduler),
          m_id(id)
    { }

    void start()
    {
        QScriptDebuggerCommandSchedulerFrontend frontend(commandScheduler(), this);
        frontend.scheduleDeleteBreakpoint(m_id);
    }

    void handleResponse(const QScriptDebuggerResponse &, int)
    {
        finish();
    }

private:
    int m_id;
};

}






void QScriptBreakpointsModel::deleteBreakpoint(int id)
{
    Q_D(QScriptBreakpointsModel);
    QScriptDebuggerJob *job = new DeleteBreakpointJob(id, d->commandScheduler);
    d->jobScheduler->scheduleJob(job);
}





void QScriptBreakpointsModel::addBreakpoint(int id, const QScriptBreakpointData &data)
{
    Q_D(QScriptBreakpointsModel);
    int rowIndex = d->breakpoints.size();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    d->breakpoints.append(qMakePair(id, data));
    endInsertRows();
}




void QScriptBreakpointsModel::modifyBreakpoint(int id, const QScriptBreakpointData &data)
{
    Q_D(QScriptBreakpointsModel);
    for (int i = 0; i < d->breakpoints.size(); ++i) {
        if (d->breakpoints.at(i).first == id) {
            d->breakpoints[i] = qMakePair(id, data);
            emit dataChanged(createIndex(i, 0), createIndex(i, columnCount()-1));
            break;
        }
    }
}






void QScriptBreakpointsModel::removeBreakpoint(int id)
{
    Q_D(QScriptBreakpointsModel);
    for (int i = 0; i < d->breakpoints.size(); ++i) {
        if (d->breakpoints.at(i).first == id) {
            beginRemoveRows(QModelIndex(), i, i);
            d->breakpoints.removeAt(i);
            endRemoveRows();
            break;
        }
    }
}




int QScriptBreakpointsModel::breakpointIdAt(int row) const
{
    Q_D(const QScriptBreakpointsModel);
    return d->breakpoints.at(row).first;
}




QScriptBreakpointData QScriptBreakpointsModel::breakpointDataAt(int row) const
{
    Q_D(const QScriptBreakpointsModel);
    return d->breakpoints.at(row).second;
}

QScriptBreakpointData QScriptBreakpointsModel::breakpointData(int id) const
{
    Q_D(const QScriptBreakpointsModel);
    for (int i = 0; i < d->breakpoints.size(); ++i) {
        if (d->breakpoints.at(i).first == id)
            return d->breakpoints.at(i).second;
    }
    return QScriptBreakpointData();
}






int QScriptBreakpointsModel::resolveBreakpoint(qint64 scriptId, int lineNumber) const
{
    Q_D(const QScriptBreakpointsModel);
    for (int i = 0; i < d->breakpoints.size(); ++i) {
        if ((d->breakpoints.at(i).second.scriptId() == scriptId)
            && (d->breakpoints.at(i).second.lineNumber() == lineNumber)) {
            return d->breakpoints.at(i).first;
        }
    }
    return -1;
}

int QScriptBreakpointsModel::resolveBreakpoint(const QString &fileName, int lineNumber) const
{
    Q_D(const QScriptBreakpointsModel);
    for (int i = 0; i < d->breakpoints.size(); ++i) {
        if ((d->breakpoints.at(i).second.fileName() == fileName)
            && (d->breakpoints.at(i).second.lineNumber() == lineNumber)) {
            return d->breakpoints.at(i).first;
        }
    }
    return -1;
}




QModelIndex QScriptBreakpointsModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_D(const QScriptBreakpointsModel);
    if (parent.isValid())
        return QModelIndex();
    if ((row < 0) || (row >= d->breakpoints.size()))
        return QModelIndex();
    if ((column < 0) || (column >= columnCount()))
        return QModelIndex();
    return createIndex(row, column);
}




QModelIndex QScriptBreakpointsModel::parent(const QModelIndex &) const
{
    return QModelIndex();
}




int QScriptBreakpointsModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 6;
    return 0;
}




int QScriptBreakpointsModel::rowCount(const QModelIndex &parent) const
{
    Q_D(const QScriptBreakpointsModel);
    if (!parent.isValid())
        return d->breakpoints.size();
    return 0;
}




QVariant QScriptBreakpointsModel::data(const QModelIndex &index, int role) const
{
    Q_D(const QScriptBreakpointsModel);
    if (!index.isValid() || (index.row() >= d->breakpoints.size()))
        return QVariant();
    const QPair<int, QScriptBreakpointData> &item = d->breakpoints.at(index.row());
    if (role == Qt::DisplayRole) {
        if (index.column() == 0)
            return item.first;
        else if (index.column() == 1) {
            QString loc = item.second.fileName();
            if (loc.isEmpty())
                loc = QString::fromLatin1("<anonymous script, id=%0>").arg(item.second.scriptId());
            loc.append(QString::fromLatin1(":%0").arg(item.second.lineNumber()));
            return loc;
        } else if (index.column() == 2) {
            if (!item.second.condition().isEmpty())
                return item.second.condition();
        } else if (index.column() == 3) {
            if (item.second.ignoreCount() != 0)
                return item.second.ignoreCount();
        } else if (index.column() == 5) {
            return item.second.hitCount();
        }
    } else if (role == Qt::CheckStateRole) {
        if (index.column() == 0) {
            return item.second.isEnabled() ? Qt::Checked : Qt::Unchecked;
        } else if (index.column() == 4) {
            return item.second.isSingleShot() ? Qt::Checked : Qt::Unchecked;
        }
    } else if (role == Qt::EditRole) {
        if (index.column() == 2)
            return item.second.condition();
        else if (index.column() == 3)
            return item.second.ignoreCount();
    }
    return QVariant();
}




bool QScriptBreakpointsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_D(QScriptBreakpointsModel);
    if (!index.isValid() || (index.row() >= d->breakpoints.size()))
        return false;
    const QPair<int, QScriptBreakpointData> &item = d->breakpoints.at(index.row());
    QScriptBreakpointData modifiedData;
    int col = index.column();
    if ((col == 0) || (col == 4)) {
        if (role == Qt::CheckStateRole) {
            modifiedData = item.second;
            if (col == 0)
                modifiedData.setEnabled(value.toInt() == Qt::Checked);
            else
                modifiedData.setSingleShot(value.toInt() == Qt::Checked);
        }
    } else if (col == 2) {
        if (role == Qt::EditRole) {
            modifiedData = item.second;
            modifiedData.setCondition(value.toString());
        }
    } else if (col == 3) {
        if (role == Qt::EditRole) {
            modifiedData = item.second;
            modifiedData.setIgnoreCount(value.toInt());
        }
    }
    if (!modifiedData.isValid())
        return false;
    QScriptDebuggerJob *job = new SetBreakpointDataJob(item.first, modifiedData, d->commandScheduler);
    d->jobScheduler->scheduleJob(job);
    return true;
}




QVariant QScriptBreakpointsModel::headerData(int section, Qt::Orientation orient, int role) const
{
    if (orient == Qt::Horizontal) {
        if (role == Qt::DisplayRole) {
            if (section == 0)
                return QCoreApplication::translate("QScriptBreakpointsModel", "ID");
            else if (section == 1)
                return QCoreApplication::translate("QScriptBreakpointsModel", "Location");
            else if (section == 2)
                return QCoreApplication::translate("QScriptBreakpointsModel", "Condition");
            else if (section == 3)
                return QCoreApplication::translate("QScriptBreakpointsModel", "Ignore-count");
            else if (section == 4)
                return QCoreApplication::translate("QScriptBreakpointsModel", "Single-shot");
            else if (section == 5)
                return QCoreApplication::translate("QScriptBreakpointsModel", "Hit-count");
        }
    }
    return QVariant();
}




Qt::ItemFlags QScriptBreakpointsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    Qt::ItemFlags ret = QAbstractItemModel::flags(index);
    switch (index.column()) {
    case 0:
        ret |= Qt::ItemIsUserCheckable;
        break;
    case 1:
        break;
    case 2:
        ret |= Qt::ItemIsEditable;
        break;
    case 3:
        ret |= Qt::ItemIsEditable;
        break;
    case 4:
        ret |= Qt::ItemIsUserCheckable;
        break;
    }
    return ret;
}

QT_END_NAMESPACE
