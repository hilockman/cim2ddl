#ifndef QSCRIPTDEBUGGERJOB_P_H
#define QSCRIPTDEBUGGERJOB_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerJobSchedulerInterface;
class QScriptDebuggerValue;

class QScriptDebuggerJobPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerJob
{
public:
    QScriptDebuggerJob();
    virtual ~QScriptDebuggerJob();

    virtual void start() = 0;

    void finish();

    void hibernateUntilEvaluateFinished();
    virtual void evaluateFinished(const QScriptDebuggerValue &result);

protected:
    QScriptDebuggerJob(QScriptDebuggerJobPrivate &dd);
    QScopedPointer<QScriptDebuggerJobPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerJob)
    Q_DISABLE_COPY(QScriptDebuggerJob)
};

QT_END_NAMESPACE

#endif
