#include "qscriptdebuggerjob_p.h"
#include "qscriptdebuggerjob_p_p.h"
#include "qscriptdebuggerjobschedulerinterface_p.h"

#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE
QScriptDebuggerJobPrivate::QScriptDebuggerJobPrivate()
{
}

QScriptDebuggerJobPrivate::~QScriptDebuggerJobPrivate()
{
}

QScriptDebuggerJobPrivate *QScriptDebuggerJobPrivate::get(QScriptDebuggerJob *q)
{
    return q->d_func();
}

QScriptDebuggerJob::QScriptDebuggerJob()
    : d_ptr(new QScriptDebuggerJobPrivate)
{
    d_ptr->q_ptr = this;
    d_ptr->jobScheduler = 0;
}

QScriptDebuggerJob::QScriptDebuggerJob(QScriptDebuggerJobPrivate &dd)
    : d_ptr(&dd)
{
    d_ptr->q_ptr = this;
    d_ptr->jobScheduler = 0;
}

QScriptDebuggerJob::~QScriptDebuggerJob()
{
}

void QScriptDebuggerJob::finish()
{
    Q_D(QScriptDebuggerJob);
    Q_ASSERT(d->jobScheduler != 0);
    d->jobScheduler->finishJob(this);
}

void QScriptDebuggerJob::hibernateUntilEvaluateFinished()
{
    Q_D(QScriptDebuggerJob);
    Q_ASSERT(d->jobScheduler != 0);
    d->jobScheduler->hibernateUntilEvaluateFinished(this);
}

void QScriptDebuggerJob::evaluateFinished(const QScriptDebuggerValue &)
{
    Q_ASSERT_X(false, "QScriptDebuggerJob::evaluateFinished()",
               "implement if hibernateUntilEvaluateFinished() is called");
}

QT_END_NAMESPACE
