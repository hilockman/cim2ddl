#include "qscriptdebuggerconsolecommand_p.h"
#include "qscriptdebuggerconsolecommand_p_p.h"

#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE
QScriptDebuggerConsoleCommandPrivate::QScriptDebuggerConsoleCommandPrivate()
{
}

QScriptDebuggerConsoleCommandPrivate::~QScriptDebuggerConsoleCommandPrivate()
{
}

QScriptDebuggerConsoleCommand::QScriptDebuggerConsoleCommand()
    : d_ptr(new QScriptDebuggerConsoleCommandPrivate)
{
    d_ptr->q_ptr = this;
}

QScriptDebuggerConsoleCommand::~QScriptDebuggerConsoleCommand()
{
}

QScriptDebuggerConsoleCommand::QScriptDebuggerConsoleCommand(QScriptDebuggerConsoleCommandPrivate &dd)
    : d_ptr(&dd)
{
    d_ptr->q_ptr = this;
}
QStringList QScriptDebuggerConsoleCommand::seeAlso() const
{
    return QStringList();
}




QStringList QScriptDebuggerConsoleCommand::aliases() const
{
    return QStringList();
}

QStringList QScriptDebuggerConsoleCommand::argumentTypes() const
{
    return QStringList();
}

QStringList QScriptDebuggerConsoleCommand::subCommands() const
{
    return QStringList();
}

QT_END_NAMESPACE
