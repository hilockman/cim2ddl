#ifndef QSCRIPTDEBUGGERCOMMANDSCHEDULERJOB_P_P_H
#define QSCRIPTDEBUGGERCOMMANDSCHEDULERJOB_P_P_H 
#include "qscriptdebuggerjob_p_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerCommandSchedulerInterface;

class QScriptDebuggerCommandSchedulerJob;
class QScriptDebuggerCommandSchedulerJobPrivate
    : public QScriptDebuggerJobPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerCommandSchedulerJob)
public:
    QScriptDebuggerCommandSchedulerJobPrivate();
    ~QScriptDebuggerCommandSchedulerJobPrivate();

    QScriptDebuggerCommandSchedulerInterface *commandScheduler;
};

QT_END_NAMESPACE

#endif
