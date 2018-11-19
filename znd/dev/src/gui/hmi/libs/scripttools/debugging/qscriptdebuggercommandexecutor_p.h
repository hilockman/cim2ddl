#ifndef QSCRIPTDEBUGGERCOMMANDEXECUTOR_P_H
#define QSCRIPTDEBUGGERCOMMANDEXECUTOR_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerBackend;
class QScriptDebuggerCommand;
class QScriptDebuggerResponse;

class QScriptDebuggerCommandExecutorPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCommandExecutor
{
public:
    QScriptDebuggerCommandExecutor();
    virtual ~QScriptDebuggerCommandExecutor();

    virtual QScriptDebuggerResponse execute(
        QScriptDebuggerBackend *backend,
        const QScriptDebuggerCommand &command);

protected:
    QScriptDebuggerCommandExecutor(QScriptDebuggerCommandExecutorPrivate &dd);
    QScopedPointer<QScriptDebuggerCommandExecutorPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCommandExecutor)
    Q_DISABLE_COPY(QScriptDebuggerCommandExecutor)
};

QT_END_NAMESPACE

#endif
