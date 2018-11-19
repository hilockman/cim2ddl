#include "qscriptdebuggercommandschedulerfrontend_p.h"
#include "qscriptdebuggercommandschedulerinterface_p.h"
#include "qscriptdebuggercommand_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerCommandSchedulerFrontend::QScriptDebuggerCommandSchedulerFrontend(
    QScriptDebuggerCommandSchedulerInterface *scheduler,
    QScriptDebuggerResponseHandlerInterface *responseHandler)
    : m_scheduler(scheduler), m_responseHandler(responseHandler)
{
}

QScriptDebuggerCommandSchedulerFrontend::~QScriptDebuggerCommandSchedulerFrontend()
{
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleCommand(const QScriptDebuggerCommand &command)
{
    return m_scheduler->scheduleCommand(command, m_responseHandler);
}
int QScriptDebuggerCommandSchedulerFrontend::scheduleInterrupt()
{
    return scheduleCommand(QScriptDebuggerCommand::interruptCommand());
}







int QScriptDebuggerCommandSchedulerFrontend::scheduleContinue()
{
    return scheduleCommand(QScriptDebuggerCommand::continueCommand());
}
int QScriptDebuggerCommandSchedulerFrontend::scheduleStepInto(int count)
{
    return scheduleCommand(QScriptDebuggerCommand::stepIntoCommand(count));
}
int QScriptDebuggerCommandSchedulerFrontend::scheduleStepOver(int count)
{
    return scheduleCommand(QScriptDebuggerCommand::stepOverCommand(count));
}
int QScriptDebuggerCommandSchedulerFrontend::scheduleStepOut()
{
    return scheduleCommand(QScriptDebuggerCommand::stepOutCommand());
}





int QScriptDebuggerCommandSchedulerFrontend::scheduleRunToLocation(const QString &fileName, int lineNumber)
{
    return scheduleCommand(QScriptDebuggerCommand::runToLocationCommand(fileName, lineNumber));
}





int QScriptDebuggerCommandSchedulerFrontend::scheduleRunToLocation(qint64 scriptId, int lineNumber)
{
    return scheduleCommand(QScriptDebuggerCommand::runToLocationCommand(scriptId, lineNumber));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleForceReturn(int contextIndex, const QScriptDebuggerValue &value)
{
    return scheduleCommand(QScriptDebuggerCommand::forceReturnCommand(contextIndex, value));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleSetBreakpoint(const QString &fileName, int lineNumber)
{
    return scheduleCommand(QScriptDebuggerCommand::setBreakpointCommand(fileName, lineNumber));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleSetBreakpoint(const QScriptBreakpointData &data)
{
    return scheduleCommand(QScriptDebuggerCommand::setBreakpointCommand(data));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleDeleteBreakpoint(int id)
{
    return scheduleCommand(QScriptDebuggerCommand::deleteBreakpointCommand(id));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleDeleteAllBreakpoints()
{
    return scheduleCommand(QScriptDebuggerCommand::deleteAllBreakpointsCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetBreakpoints()
{
    return scheduleCommand(QScriptDebuggerCommand::getBreakpointsCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetBreakpointData(int id)
{
    return scheduleCommand(QScriptDebuggerCommand::getBreakpointDataCommand(id));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleSetBreakpointData(int id, const QScriptBreakpointData &data)
{
    return scheduleCommand(QScriptDebuggerCommand::setBreakpointDataCommand(id, data));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetScripts()
{
    return scheduleCommand(QScriptDebuggerCommand::getScriptsCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetScriptData(qint64 id)
{
    return scheduleCommand(QScriptDebuggerCommand::getScriptDataCommand(id));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleScriptsCheckpoint()
{
    return scheduleCommand(QScriptDebuggerCommand::scriptsCheckpointCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetScriptsDelta()
{
    return scheduleCommand(QScriptDebuggerCommand::getScriptsDeltaCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleResolveScript(const QString &fileName)
{
    return scheduleCommand(QScriptDebuggerCommand::resolveScriptCommand(fileName));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetBacktrace()
{
    return scheduleCommand(QScriptDebuggerCommand::getBacktraceCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetContextCount()
{
    return scheduleCommand(QScriptDebuggerCommand::getContextCountCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetContextState(int contextIndex)
{
    return scheduleCommand(QScriptDebuggerCommand::getContextStateCommand(contextIndex));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetContextInfo(int contextIndex)
{
    return scheduleCommand(QScriptDebuggerCommand::getContextInfoCommand(contextIndex));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetContextId(int contextIndex)
{
    return scheduleCommand(QScriptDebuggerCommand::getContextIdCommand(contextIndex));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetThisObject(int contextIndex)
{
    return scheduleCommand(QScriptDebuggerCommand::getThisObjectCommand(contextIndex));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetActivationObject(int contextIndex)
{
    return scheduleCommand(QScriptDebuggerCommand::getActivationObjectCommand(contextIndex));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetScopeChain(int contextIndex)
{
    return scheduleCommand(QScriptDebuggerCommand::getScopeChainCommand(contextIndex));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleContextsCheckpoint()
{
    return scheduleCommand(QScriptDebuggerCommand::contextsCheckpoint());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetPropertyExpressionValue(
    int contextIndex, int lineNumber, const QStringList &path)
{
    return scheduleCommand(QScriptDebuggerCommand::getPropertyExpressionValue(contextIndex, lineNumber, path));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetCompletions(int contextIndex, const QStringList &path)
{
    return scheduleCommand(QScriptDebuggerCommand::getCompletions(contextIndex, path));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleEvaluate(int contextIndex,
                                              const QString &program,
                                              const QString &fileName,
                                              int lineNumber)
{
    return scheduleCommand(QScriptDebuggerCommand::evaluateCommand(contextIndex, program, fileName, lineNumber));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleNewScriptValueIterator(const QScriptDebuggerValue &object)
{
    return scheduleCommand(QScriptDebuggerCommand::newScriptValueIteratorCommand(object));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleGetPropertiesByIterator(int id, int count)
{
    return scheduleCommand(QScriptDebuggerCommand::getPropertiesByIteratorCommand(id, count));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleDeleteScriptValueIterator(int id)
{
    return scheduleCommand(QScriptDebuggerCommand::deleteScriptValueIteratorCommand(id));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleScriptValueToString(const QScriptDebuggerValue &value)
{
    return scheduleCommand(QScriptDebuggerCommand::scriptValueToStringCommand(value));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleSetScriptValueProperty(const QScriptDebuggerValue &object,
                                                            const QString &name,
                                                            const QScriptDebuggerValue &value)
{
    return scheduleCommand(QScriptDebuggerCommand::setScriptValuePropertyCommand(object, name, value));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleClearExceptions()
{
    return scheduleCommand(QScriptDebuggerCommand::clearExceptionsCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleNewScriptObjectSnapshot()
{
    return scheduleCommand(QScriptDebuggerCommand::newScriptObjectSnapshotCommand());
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleScriptObjectSnapshotCapture(int id, const QScriptDebuggerValue &object)
{
    return scheduleCommand(QScriptDebuggerCommand::scriptObjectSnapshotCaptureCommand(id, object));
}

int QScriptDebuggerCommandSchedulerFrontend::scheduleDeleteScriptObjectSnapshot(int id)
{
    return scheduleCommand(QScriptDebuggerCommand::deleteScriptObjectSnapshotCommand(id));
}

QT_END_NAMESPACE
