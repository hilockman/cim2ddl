#ifndef QSCRIPTDEBUGGERCOMMANDSCHEDULERFRONTEND_P_H
#define QSCRIPTDEBUGGERCOMMANDSCHEDULERFRONTEND_P_H 
#include <QtCore/qobjectdefs.h>

#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCommandSchedulerInterface;
class QScriptDebuggerResponseHandlerInterface;
class QScriptDebuggerCommand;
class QScriptDebuggerValue;
class QScriptBreakpointData;

class Q_AUTOTEST_EXPORT QScriptDebuggerCommandSchedulerFrontend
{
public:
    QScriptDebuggerCommandSchedulerFrontend(
        QScriptDebuggerCommandSchedulerInterface *scheduler,
        QScriptDebuggerResponseHandlerInterface *responseHandler);
    ~QScriptDebuggerCommandSchedulerFrontend();


     int scheduleInterrupt();
     int scheduleContinue();
     int scheduleStepInto(int count = 1);
     int scheduleStepOver(int count = 1);
     int scheduleStepOut();
     int scheduleRunToLocation(const QString &fileName, int lineNumber);
     int scheduleRunToLocation(qint64 scriptId, int lineNumber);
     int scheduleForceReturn(int contextIndex, const QScriptDebuggerValue &value);


     int scheduleSetBreakpoint(const QString &fileName, int lineNumber);
     int scheduleSetBreakpoint(const QScriptBreakpointData &data);
     int scheduleDeleteBreakpoint(int id);
     int scheduleDeleteAllBreakpoints();
     int scheduleGetBreakpoints();
     int scheduleGetBreakpointData(int id);
     int scheduleSetBreakpointData(int id, const QScriptBreakpointData &data);


     int scheduleGetScripts();
     int scheduleGetScriptData(qint64 id);
     int scheduleScriptsCheckpoint();
     int scheduleGetScriptsDelta();
     int scheduleResolveScript(const QString &fileName);


     int scheduleGetBacktrace();
     int scheduleGetContextCount();
     int scheduleGetContextState(int contextIndex);
     int scheduleGetContextInfo(int contextIndex);
     int scheduleGetContextId(int contextIndex);
     int scheduleGetThisObject(int contextIndex);
     int scheduleGetActivationObject(int contextIndex);
     int scheduleGetScopeChain(int contextIndex);
     int scheduleContextsCheckpoint();
     int scheduleGetPropertyExpressionValue(int contextIndex, int lineNumber,
                                            const QStringList &path);
     int scheduleGetCompletions(int contextIndex, const QStringList &path);


     int scheduleNewScriptValueIterator(const QScriptDebuggerValue &object);
     int scheduleGetPropertiesByIterator(int id, int count);
     int scheduleDeleteScriptValueIterator(int id);


     int scheduleEvaluate(int contextIndex, const QString &program,
                          const QString &fileName = QString(),
                          int lineNumber = 1);

     int scheduleScriptValueToString(const QScriptDebuggerValue &value);
     int scheduleSetScriptValueProperty(const QScriptDebuggerValue &object,
                                        const QString &name,
                                        const QScriptDebuggerValue &value);

     int scheduleClearExceptions();

     int scheduleNewScriptObjectSnapshot();
     int scheduleScriptObjectSnapshotCapture(int id, const QScriptDebuggerValue &object);
     int scheduleDeleteScriptObjectSnapshot(int id);

private:
    int scheduleCommand(const QScriptDebuggerCommand &command);

    QScriptDebuggerCommandSchedulerInterface *m_scheduler;
    QScriptDebuggerResponseHandlerInterface *m_responseHandler;

    Q_DISABLE_COPY(QScriptDebuggerCommandSchedulerFrontend)
};

QT_END_NAMESPACE

#endif
