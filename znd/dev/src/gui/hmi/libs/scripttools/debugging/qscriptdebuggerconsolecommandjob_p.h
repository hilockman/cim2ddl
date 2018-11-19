#ifndef QSCRIPTDEBUGGERCONSOLECOMMANDJOB_P_H
#define QSCRIPTDEBUGGERCONSOLECOMMANDJOB_P_H 
#include "qscriptdebuggercommandschedulerjob_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerConsole;
class QScriptMessageHandlerInterface;

class QScriptDebuggerConsoleCommandJobPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleCommandJob
    : public QScriptDebuggerCommandSchedulerJob
{
public:
    QScriptDebuggerConsoleCommandJob(QScriptDebuggerConsole *console,
                                     QScriptMessageHandlerInterface *messageHandler,
                                     QScriptDebuggerCommandSchedulerInterface *scheduler);
    ~QScriptDebuggerConsoleCommandJob();

protected:
    QScriptDebuggerConsoleCommandJob(QScriptDebuggerConsoleCommandJobPrivate &dd,
                                     QScriptDebuggerConsole *console,
                                     QScriptMessageHandlerInterface *messageHandler,
                                     QScriptDebuggerCommandSchedulerInterface *scheduler);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerConsoleCommandJob)
    Q_DISABLE_COPY(QScriptDebuggerConsoleCommandJob)
};

QT_END_NAMESPACE

#endif
