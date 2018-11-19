#ifndef QSCRIPTDEBUGGERJOBSCHEDULERINTERFACE_P_H
#define QSCRIPTDEBUGGERJOBSCHEDULERINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerJob;

class Q_AUTOTEST_EXPORT QScriptDebuggerJobSchedulerInterface
{
public:
    virtual ~QScriptDebuggerJobSchedulerInterface() {}

    virtual int scheduleJob(QScriptDebuggerJob *job) = 0;
    virtual void finishJob(QScriptDebuggerJob *job) = 0;
    virtual void hibernateUntilEvaluateFinished(QScriptDebuggerJob *job) = 0;
};

QT_END_NAMESPACE

#endif
