#ifndef QSCRIPTDEBUGGERCONSOLEGLOBALOBJECT_P_H
#define QSCRIPTDEBUGGERCONSOLEGLOBALOBJECT_P_H 
#include <QtCore/qobject.h>

#include <QtCore/qstringlist.h>

#include "qscriptdebuggerconsolecommandgroupdata_p.h"
#include "qscriptdebuggerconsolecommand_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerCommandSchedulerInterface;
class QScriptMessageHandlerInterface;
class QScriptDebuggerResponseHandlerInterface;
class QScriptDebuggerConsole;
class QScriptDebuggerValue;
class QScriptDebuggerCommand;
class QScriptBreakpointData;

class QScriptDebuggerConsoleGlobalObjectPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleGlobalObject
    : public QObject
{
    Q_OBJECT
public:
    QScriptDebuggerConsoleGlobalObject(QObject *parent = 0);
    ~QScriptDebuggerConsoleGlobalObject();

    QScriptDebuggerCommandSchedulerInterface *scheduler() const;
    void setScheduler(QScriptDebuggerCommandSchedulerInterface *scheduler);

    QScriptDebuggerResponseHandlerInterface *responseHandler() const;
    void setResponseHandler(QScriptDebuggerResponseHandlerInterface *responseHandler);

    QScriptMessageHandlerInterface *messageHandler() const;
    void setMessageHandler(QScriptMessageHandlerInterface *messageHandler);

    QScriptDebuggerConsole *console() const;
    void setConsole(QScriptDebuggerConsole *console);

public Q_SLOTS:

    int scheduleInterrupt();
    int scheduleContinue();
    int scheduleStepInto(int count = 1);
    int scheduleStepOver(int count = 1);
    int scheduleStepOut();
    int scheduleRunToLocation(const QString &fileName, int lineNumber);
    int scheduleRunToLocation(qint64 scriptId, int lineNumber);
    int scheduleForceReturn(int contextIndex, const QScriptDebuggerValue &value);

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
    int scheduleGetThisObject(int contextIndex);
    int scheduleGetActivationObject(int contextIndex);
    int scheduleGetContextCount();
    int scheduleGetContextInfo(int contextIndex);

    int scheduleNewScriptValueIterator(const QScriptDebuggerValue &object);
    int scheduleGetPropertiesByIterator(int id, int count);
    int scheduleDeleteScriptValueIterator(int id);

    int scheduleEvaluate(int contextIndex, const QString &program,
                         const QString &fileName = QString(),
                         int lineNumber = 1);

    int scheduleScriptValueToString(const QScriptDebuggerValue &value);

    int scheduleClearExceptions();

    int scheduleCommand(const QScriptDebuggerCommand &command);


    void message(const QString &text, const QString &fileName = QString(),
                 int lineNumber = -1, int columnNumber = -1);
    void warning(const QString &text, const QString &fileName = QString(),
                 int lineNumber = -1, int columnNumber = -1);
    void error(const QString &text, const QString &fileName = QString(),
               int lineNumber = -1, int columnNumber = -1);


    int getCurrentFrameIndex() const;
    void setCurrentFrameIndex(int index);
    qint64 getCurrentScriptId() const;
    void setCurrentScriptId(qint64 id);
    qint64 getSessionId() const;
    int getCurrentLineNumber() const;
    void setCurrentLineNumber(int lineNumber);


    QScriptDebuggerConsoleCommandGroupMap getCommandGroups() const;
    QScriptDebuggerConsoleCommand *findCommand(const QString &command) const;
    QScriptDebuggerConsoleCommandList getCommandsInGroup(const QString &name) const;
    QStringList getCommandCompletions(const QString &prefix) const;

    bool checkSyntax(const QString &program);

    void setEvaluateAction(int action);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerConsoleGlobalObject)
    Q_DISABLE_COPY(QScriptDebuggerConsoleGlobalObject)
};

QT_END_NAMESPACE

#endif
