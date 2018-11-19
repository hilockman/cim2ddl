#ifndef QSCRIPTDEBUGGERCONSOLECOMMAND_P_H
#define QSCRIPTDEBUGGERCONSOLECOMMAND_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qlist.h>

QT_BEGIN_NAMESPACE

class QString;
class QStringList;
class QScriptDebuggerConsole;
class QScriptDebuggerConsoleCommandJob;
class QScriptMessageHandlerInterface;
class QScriptDebuggerCommandSchedulerInterface;

class QScriptDebuggerConsoleCommandPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleCommand
{
public:
    QScriptDebuggerConsoleCommand();
    virtual ~QScriptDebuggerConsoleCommand();

    virtual QString name() const = 0;
    virtual QString group() const = 0;
    virtual QString shortDescription() const = 0;
    virtual QString longDescription() const = 0;
    virtual QStringList seeAlso() const;
    virtual QStringList aliases() const;

    virtual QStringList argumentTypes() const;

    virtual QStringList subCommands() const;
    virtual QScriptDebuggerConsoleCommandJob *createJob(
        const QStringList &arguments,
        QScriptDebuggerConsole *console,
        QScriptMessageHandlerInterface *messageHandler,
        QScriptDebuggerCommandSchedulerInterface *scheduler) = 0;

protected:
    QScriptDebuggerConsoleCommand(QScriptDebuggerConsoleCommandPrivate &dd);
    QScopedPointer<QScriptDebuggerConsoleCommandPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerConsoleCommand)
    Q_DISABLE_COPY(QScriptDebuggerConsoleCommand)
};

typedef QList<QScriptDebuggerConsoleCommand*> QScriptDebuggerConsoleCommandList;

QT_END_NAMESPACE

#endif
