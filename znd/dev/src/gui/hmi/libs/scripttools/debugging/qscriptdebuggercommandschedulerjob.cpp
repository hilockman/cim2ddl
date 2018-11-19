#include "qscriptdebuggercommandschedulerjob_p.h"
#include "qscriptdebuggercommandschedulerjob_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerCommandSchedulerJobPrivate::QScriptDebuggerCommandSchedulerJobPrivate()
{
}

QScriptDebuggerCommandSchedulerJobPrivate::~QScriptDebuggerCommandSchedulerJobPrivate()
{
}

QScriptDebuggerCommandSchedulerJob::QScriptDebuggerCommandSchedulerJob(
    QScriptDebuggerCommandSchedulerInterface *commandScheduler)
    : QScriptDebuggerJob(*new QScriptDebuggerCommandSchedulerJobPrivate)
{
    Q_D(QScriptDebuggerCommandSchedulerJob);
    d->commandScheduler = commandScheduler;
}

QScriptDebuggerCommandSchedulerJob::~QScriptDebuggerCommandSchedulerJob()
{
}

QScriptDebuggerCommandSchedulerJob::QScriptDebuggerCommandSchedulerJob(
    QScriptDebuggerCommandSchedulerJobPrivate &dd,
    QScriptDebuggerCommandSchedulerInterface *commandScheduler)
    : QScriptDebuggerJob(dd)
{
    Q_D(QScriptDebuggerCommandSchedulerJob);
    d->commandScheduler = commandScheduler;
}

QScriptDebuggerCommandSchedulerInterface *QScriptDebuggerCommandSchedulerJob::commandScheduler() const
{
    Q_D(const QScriptDebuggerCommandSchedulerJob);
    return d->commandScheduler;
}

QT_END_NAMESPACE
