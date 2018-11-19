#ifndef QSCRIPTDEBUGGERCOMMANDSCHEDULERJOB_P_H
#define QSCRIPTDEBUGGERCOMMANDSCHEDULERJOB_P_H 
#include "qscriptdebuggerjob_p.h"

#include "qscriptdebuggerresponsehandlerinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerCommandSchedulerInterface;

class QScriptDebuggerCommandSchedulerJobPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCommandSchedulerJob
    : public QScriptDebuggerJob,
      public QScriptDebuggerResponseHandlerInterface
{
public:
    QScriptDebuggerCommandSchedulerJob(QScriptDebuggerCommandSchedulerInterface *commandScheduler);
    ~QScriptDebuggerCommandSchedulerJob();

    QScriptDebuggerCommandSchedulerInterface *commandScheduler() const;

protected:
    QScriptDebuggerCommandSchedulerJob(
        QScriptDebuggerCommandSchedulerJobPrivate &dd,
        QScriptDebuggerCommandSchedulerInterface *commandScheduler);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCommandSchedulerJob)
    Q_DISABLE_COPY(QScriptDebuggerCommandSchedulerJob)
};

QT_END_NAMESPACE

#endif
