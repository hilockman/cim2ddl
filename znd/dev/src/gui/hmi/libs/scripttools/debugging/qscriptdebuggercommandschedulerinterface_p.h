#ifndef QSCRIPTDEBUGGERCOMMANDSCHEDULERINTERFACE_P_H
#define QSCRIPTDEBUGGERCOMMANDSCHEDULERINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCommand;
class QScriptDebuggerResponseHandlerInterface;

class Q_AUTOTEST_EXPORT QScriptDebuggerCommandSchedulerInterface
{
public:
    virtual ~QScriptDebuggerCommandSchedulerInterface() {}

    virtual int scheduleCommand(
        const QScriptDebuggerCommand &command,
        QScriptDebuggerResponseHandlerInterface *responseHandler) = 0;
};

QT_END_NAMESPACE

#endif
