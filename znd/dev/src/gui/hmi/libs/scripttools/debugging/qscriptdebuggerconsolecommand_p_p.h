#ifndef QSCRIPTDEBUGGERCONSOLECOMMAND_P_P_H
#define QSCRIPTDEBUGGERCONSOLECOMMAND_P_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerConsoleCommand;
class QScriptDebuggerConsoleCommandPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerConsoleCommand)
public:
    QScriptDebuggerConsoleCommandPrivate();
    virtual ~QScriptDebuggerConsoleCommandPrivate();

    QScriptDebuggerConsoleCommand *q_ptr;
};

QT_END_NAMESPACE

#endif
