#ifndef QSCRIPTDEBUGGERCONSOLECOMMANDJOB_P_P_H
#define QSCRIPTDEBUGGERCONSOLECOMMANDJOB_P_P_H 
#include "qscriptdebuggercommandschedulerjob_p_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerConsole;
class QScriptMessageHandlerInterface;

class QScriptDebuggerConsoleCommandJob;
class QScriptDebuggerConsoleCommandJobPrivate
    : public QScriptDebuggerCommandSchedulerJobPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerConsoleCommandJob)
public:
    QScriptDebuggerConsoleCommandJobPrivate();
    ~QScriptDebuggerConsoleCommandJobPrivate();

    QScriptDebuggerConsole *console;
    QScriptMessageHandlerInterface *messageHandler;
};

QT_END_NAMESPACE

#endif
