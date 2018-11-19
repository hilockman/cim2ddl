#ifndef QSCRIPTDEBUGGEREVENTHANDLERINTERFACE_P_H
#define QSCRIPTDEBUGGEREVENTHANDLERINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerEvent;

class Q_AUTOTEST_EXPORT QScriptDebuggerEventHandlerInterface
{
public:
    virtual ~QScriptDebuggerEventHandlerInterface() {}

    virtual bool debuggerEvent(const QScriptDebuggerEvent &event) = 0;
};

QT_END_NAMESPACE

#endif
