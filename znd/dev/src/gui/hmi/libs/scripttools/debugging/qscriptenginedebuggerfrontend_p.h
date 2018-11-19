#ifndef QSCRIPTENGINEDEBUGGERFRONTEND_P_H
#define QSCRIPTENGINEDEBUGGERFRONTEND_P_H 
#include "qscriptdebuggerfrontend_p.h"

QT_BEGIN_NAMESPACE

class QScriptEngine;
class QScriptValue;
class QScriptDebuggerBackend;

class QScriptEngineDebuggerFrontendPrivate;
class Q_AUTOTEST_EXPORT QScriptEngineDebuggerFrontend
    : public QScriptDebuggerFrontend
{
public:
    QScriptEngineDebuggerFrontend();
    ~QScriptEngineDebuggerFrontend();

    void attachTo(QScriptEngine *engine);
    void detach();

    QScriptValue traceFunction() const;

    QScriptDebuggerBackend *backend() const;

protected:
    void processCommand(int id, const QScriptDebuggerCommand &command);

private:
    Q_DECLARE_PRIVATE(QScriptEngineDebuggerFrontend)
    Q_DISABLE_COPY(QScriptEngineDebuggerFrontend)
};

QT_END_NAMESPACE

#endif
