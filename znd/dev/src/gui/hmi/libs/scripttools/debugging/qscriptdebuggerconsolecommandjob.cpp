#include "qscriptdebuggerconsolecommandjob_p.h"
#include "qscriptdebuggerconsolecommandjob_p_p.h"

#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QScriptDebuggerConsoleCommandJobPrivate::QScriptDebuggerConsoleCommandJobPrivate()
{
}

QScriptDebuggerConsoleCommandJobPrivate::~QScriptDebuggerConsoleCommandJobPrivate()
{
}

QScriptDebuggerConsoleCommandJob::QScriptDebuggerConsoleCommandJob(
    QScriptDebuggerConsole *console,
    QScriptMessageHandlerInterface *messageHandler,
    QScriptDebuggerCommandSchedulerInterface *scheduler)
    : QScriptDebuggerCommandSchedulerJob(*new QScriptDebuggerConsoleCommandJobPrivate,
                                         scheduler)
{
    Q_D(QScriptDebuggerConsoleCommandJob);
    d->console = console;
    d->messageHandler = messageHandler;
}

QScriptDebuggerConsoleCommandJob::~QScriptDebuggerConsoleCommandJob()
{
}

QScriptDebuggerConsoleCommandJob::QScriptDebuggerConsoleCommandJob(
    QScriptDebuggerConsoleCommandJobPrivate &dd,
    QScriptDebuggerConsole *console,
    QScriptMessageHandlerInterface *messageHandler,
    QScriptDebuggerCommandSchedulerInterface *scheduler)
    : QScriptDebuggerCommandSchedulerJob(dd, scheduler)
{
    Q_D(QScriptDebuggerConsoleCommandJob);
    d->console = console;
    d->messageHandler = messageHandler;
}

QT_END_NAMESPACE
