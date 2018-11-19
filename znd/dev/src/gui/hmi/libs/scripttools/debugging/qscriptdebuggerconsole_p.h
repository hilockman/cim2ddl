#ifndef QSCRIPTDEBUGGERCONSOLE_P_H
#define QSCRIPTDEBUGGERCONSOLE_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>

#include "qscriptdebuggerconsolehistorianinterface_p.h"

QT_BEGIN_NAMESPACE

class QString;
class QScriptDebuggerConsoleCommandJob;
class QScriptMessageHandlerInterface;
class QScriptDebuggerCommandSchedulerInterface;
class QScriptDebuggerConsoleCommandManager;

class QScriptDebuggerConsolePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsole
    : public QScriptDebuggerConsoleHistorianInterface
{
public:
    QScriptDebuggerConsole();
    ~QScriptDebuggerConsole();

    void loadScriptedCommands(const QString &scriptsPath,
                              QScriptMessageHandlerInterface *messageHandler);

    void showDebuggerInfoMessage(QScriptMessageHandlerInterface *messageHandler);

    QScriptDebuggerConsoleCommandManager *commandManager() const;

    QScriptDebuggerConsoleCommandJob *consumeInput(
        const QString &input,
        QScriptMessageHandlerInterface *messageHandler,
        QScriptDebuggerCommandSchedulerInterface *commandScheduler);
    bool hasIncompleteInput() const;
    QString incompleteInput() const;
    void setIncompleteInput(const QString &input);
    QString commandPrefix() const;

    int historyCount() const;
    QString historyAt(int index) const;
    void changeHistoryAt(int index, const QString &newHistory);

    int currentFrameIndex() const;
    void setCurrentFrameIndex(int index);

    qint64 currentScriptId() const;
    void setCurrentScriptId(qint64 id);

    int currentLineNumber() const;
    void setCurrentLineNumber(int lineNumber);

    int evaluateAction() const;
    void setEvaluateAction(int action);

    qint64 sessionId() const;
    void bumpSessionId();

private:
    QScopedPointer<QScriptDebuggerConsolePrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptDebuggerConsole)
    Q_DISABLE_COPY(QScriptDebuggerConsole)
};

QT_END_NAMESPACE

#endif
