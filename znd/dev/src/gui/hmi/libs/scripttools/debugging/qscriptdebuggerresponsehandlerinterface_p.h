#ifndef QSCRIPTDEBUGGERRESPONSEHANDLERINTERFACE_P_H
#define QSCRIPTDEBUGGERRESPONSEHANDLERINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerResponse;

class Q_AUTOTEST_EXPORT QScriptDebuggerResponseHandlerInterface
{
public:
    virtual ~QScriptDebuggerResponseHandlerInterface() {}

    virtual void handleResponse(const QScriptDebuggerResponse &response,
                                int commandId) = 0;
};

QT_END_NAMESPACE

#endif
