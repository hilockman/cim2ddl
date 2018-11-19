#ifndef QSCRIPTDEBUGGERJOB_P_P_H
#define QSCRIPTDEBUGGERJOB_P_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerJobSchedulerInterface;

class QScriptDebuggerJob;
class QScriptDebuggerJobPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerJob)
public:
    QScriptDebuggerJobPrivate();
    virtual ~QScriptDebuggerJobPrivate();

    static QScriptDebuggerJobPrivate *get(QScriptDebuggerJob *q);

    QScriptDebuggerJobSchedulerInterface *jobScheduler;
    QScriptDebuggerJob *q_ptr;
};

QT_END_NAMESPACE

#endif
