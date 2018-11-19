#ifndef QSCRIPTDEBUGGERSCRIPTEDCONSOLECOMMAND_P_H
#define QSCRIPTDEBUGGERSCRIPTEDCONSOLECOMMAND_P_H 
#include "qscriptdebuggerconsolecommand_p.h"

QT_BEGIN_NAMESPACE

class QScriptEngine;
class QScriptValue;

class QScriptDebuggerScriptedConsoleCommandPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerScriptedConsoleCommand
    : public QScriptDebuggerConsoleCommand
{
protected:
    QScriptDebuggerScriptedConsoleCommand(const QString &name,
                                          const QString &group,
                                          const QString &shortDescription,
                                          const QString &longDescription,
                                          const QStringList &aliases,
                                          const QStringList &seeAlso,
                                          const QStringList &argumentTypes,
                                          const QStringList &subCommands,
                                          const QScriptValue &globalObject,
                                          const QScriptValue &execFunction,
                                          const QScriptValue &responseFunction);
public:
    ~QScriptDebuggerScriptedConsoleCommand();

    static QScriptDebuggerScriptedConsoleCommand *parse(
        const QString &program, const QString &fileName,
        QScriptEngine *engine, QScriptMessageHandlerInterface *messageHandler);

    QString name() const;
    QString group() const;
    QString shortDescription() const;
    QString longDescription() const;
    QStringList aliases() const;
    QStringList seeAlso() const;
    QStringList argumentTypes() const;
    QStringList subCommands() const;

    QScriptDebuggerConsoleCommandJob *createJob(
        const QStringList &arguments,
        QScriptDebuggerConsole *console,
        QScriptMessageHandlerInterface *messageHandler,
        QScriptDebuggerCommandSchedulerInterface *commandScheduler);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerScriptedConsoleCommand)
    Q_DISABLE_COPY(QScriptDebuggerScriptedConsoleCommand)
};

QT_END_NAMESPACE

#endif
