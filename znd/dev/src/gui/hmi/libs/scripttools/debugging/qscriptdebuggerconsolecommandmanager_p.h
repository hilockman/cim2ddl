#ifndef QSCRIPTDEBUGGERCONSOLECOMMANDMANAGER_P_H
#define QSCRIPTDEBUGGERCONSOLECOMMANDMANAGER_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qmap.h>
#include <QtCore/qlist.h>

#include "qscriptdebuggerconsolecommandgroupdata_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerConsoleCommand;
class QStringList;

class QScriptDebuggerConsoleCommandManagerPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleCommandManager
{
public:
    QScriptDebuggerConsoleCommandManager();
    ~QScriptDebuggerConsoleCommandManager();

    void addCommand(QScriptDebuggerConsoleCommand *command);
    void addCommandGroup(const QString &name,
                         const QScriptDebuggerConsoleCommandGroupData &data);

    QScriptDebuggerConsoleCommand *findCommand(const QString &name) const;
    QMap<QString, QList<QScriptDebuggerConsoleCommand*> > commands() const;
    QList<QScriptDebuggerConsoleCommand*> commandsInGroup(const QString &name) const;

    QScriptDebuggerConsoleCommandGroupData commandGroupData(const QString &name) const;
    QScriptDebuggerConsoleCommandGroupMap commandGroups() const;

    QStringList completions(const QString &prefix) const;

private:
    QScopedPointer<QScriptDebuggerConsoleCommandManagerPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptDebuggerConsoleCommandManager)
};

QT_END_NAMESPACE

#endif
