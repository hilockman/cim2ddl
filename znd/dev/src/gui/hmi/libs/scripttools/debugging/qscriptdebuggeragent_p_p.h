#ifndef QSCRIPTDEBUGGERAGENT_P_P_H
#define QSCRIPTDEBUGGERAGENT_P_P_H 
#include <QtScript/qscriptvalue.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qhash.h>
#include <QtCore/qmap.h>
#include <QtCore/qlist.h>

#include "qscriptscriptdata_p.h"
#include "qscriptbreakpointdata_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerAgent;
class QScriptDebuggerAgentPrivate
{
public:
    enum State {
        NoState,
        SteppingIntoState,
        SteppedIntoState,
        SteppingOverState,
        SteppedOverState,
        SteppingOutState,
        SteppedOutState,
        RunningToLocationState,
        ReachedLocationState,
        InterruptingState,
        InterruptedState,
        BreakpointState,
        ReturningByForceState,
        ReturnedByForceState
    };

    QScriptDebuggerAgentPrivate();
    ~QScriptDebuggerAgentPrivate();

    static QScriptDebuggerAgentPrivate *get(QScriptDebuggerAgent *);

    State state;
    int stepDepth;
    int stepCount;
    int targetScriptId;
    QString targetFileName;
    int targetLineNumber;
    QScriptValue stepResult;
    int returnCounter;
    QScriptValue returnValue;

    int nextBreakpointId;
    QHash<qint64, QList<int> > resolvedBreakpoints;
    QHash<QString, QList<int> > unresolvedBreakpoints;
    QScriptBreakpointMap breakpoints;
    int hitBreakpointId;

    QScriptScriptMap scripts;
    QScriptScriptMap checkpointScripts;
    QScriptScriptMap previousCheckpointScripts;
    QList<QList<qint64> > scriptIdStack;

    QList<qint64> contextIdStack;
    QList<qint64> checkpointContextIdStack;
    qint64 nextContextId;

    QTime processEventsTimer;
    int statementCounter;

    QScriptDebuggerBackendPrivate *backend;
};

QT_END_NAMESPACE

#endif
