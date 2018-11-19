#ifndef QSCRIPTCOMPLETIONTASK_P_H
#define QSCRIPTCOMPLETIONTASK_P_H 
#include "qscriptcompletiontaskinterface_p.h"

#include <QtCore/qlist.h>
#include <QtCore/qmap.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCommandSchedulerInterface;
class QScriptDebuggerJobSchedulerInterface;
class QScriptDebuggerConsole;

class QScriptCompletionTaskPrivate;
class Q_AUTOTEST_EXPORT QScriptCompletionTask
    : public QScriptCompletionTaskInterface
{
    Q_OBJECT
public:
    QScriptCompletionTask(
        const QString &contents, int cursorPosition, int frameIndex,
        QScriptDebuggerCommandSchedulerInterface *commandScheduler,
        QScriptDebuggerJobSchedulerInterface *jobScheduler,
        QScriptDebuggerConsole *console,
        QObject *parent = 0);
    ~QScriptCompletionTask();

    void start();

private:
    Q_DECLARE_PRIVATE(QScriptCompletionTask)
    Q_DISABLE_COPY(QScriptCompletionTask)
};

QT_END_NAMESPACE

#endif
