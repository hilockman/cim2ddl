#include "qscriptdebuggerconsolecommandmanager_p.h"
#include "qscriptdebuggerconsolecommand_p.h"
#include "qscriptdebuggerconsolecommandgroupdata_p.h"

#include <QtCore/qlist.h>
#include <QtCore/qstringlist.h>

#include <algorithm>

QT_BEGIN_NAMESPACE
class QScriptDebuggerConsoleCommandManagerPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerConsoleCommandManager)
public:
    QScriptDebuggerConsoleCommandManagerPrivate();
    ~QScriptDebuggerConsoleCommandManagerPrivate();

    QList<QScriptDebuggerConsoleCommand*> commands;
    QMap<QString, QScriptDebuggerConsoleCommandGroupData> groups;

    QScriptDebuggerConsoleCommandManager *q_ptr;
};

QScriptDebuggerConsoleCommandManagerPrivate::QScriptDebuggerConsoleCommandManagerPrivate()
{
    groups[QLatin1String("breakpoints")] =
        QScriptDebuggerConsoleCommandGroupData(QLatin1String("Making program stop at certain points"),
                                               QLatin1String(""));
    groups[QLatin1String("files")] =
        QScriptDebuggerConsoleCommandGroupData(QLatin1String("Examining files"),
                                               QLatin1String(""));
    groups[QLatin1String("stack")] =
        QScriptDebuggerConsoleCommandGroupData(QLatin1String("Examining the stack"),
                                               QLatin1String(""));
    groups[QLatin1String("running")] =
        QScriptDebuggerConsoleCommandGroupData(QLatin1String("Running the program"),
                                               QLatin1String(""));
    groups[QLatin1String("status")] =
        QScriptDebuggerConsoleCommandGroupData(QLatin1String("Status inquiries"),
                                               QLatin1String(""));
    groups[QLatin1String("void")] =
        QScriptDebuggerConsoleCommandGroupData(QLatin1String("No such group"),
                                               QLatin1String("It's a secret to everyone"));
}

QScriptDebuggerConsoleCommandManagerPrivate::~QScriptDebuggerConsoleCommandManagerPrivate()
{
    qDeleteAll(commands);
}

QScriptDebuggerConsoleCommandManager::QScriptDebuggerConsoleCommandManager()
    : d_ptr(new QScriptDebuggerConsoleCommandManagerPrivate)
{
    d_ptr->q_ptr = this;
}

QScriptDebuggerConsoleCommandManager::~QScriptDebuggerConsoleCommandManager()
{
}





void QScriptDebuggerConsoleCommandManager::addCommand(QScriptDebuggerConsoleCommand *command)
{
    Q_D(QScriptDebuggerConsoleCommandManager);
    Q_ASSERT(command != 0);
    if (command->name().isEmpty()) {
        qWarning("addCommand(): nameless command ignored");
        return;
    }
    if (command->group().isEmpty()) {
        qWarning("addCommand(): groupless command '%s' ignored",
                 qPrintable(command->name()));
        return;
    }
    if (findCommand(command->name()) != 0) {
        qWarning("addCommand(): duplicate command '%s' (group '%s') ignored",
                 qPrintable(command->name()), qPrintable(command->group()));
        return;
    }
    if (!d->groups.contains(command->group())) {
        qWarning("addCommand(): group '%s' for command '%s' is unknown!",
                 qPrintable(command->group()), qPrintable(command->name()));
    }
    d->commands.append(command);
}




void QScriptDebuggerConsoleCommandManager::addCommandGroup(
    const QString &name, const QScriptDebuggerConsoleCommandGroupData &data)
{
    Q_D(QScriptDebuggerConsoleCommandManager);
    if (name.isEmpty()) {
        qWarning("addCommandGroup(): nameless group ignored");
        return;
    }
    if (d->groups.contains(name)) {
        qWarning("addCommandGroup(): group '%s' already defined",
                 qPrintable(name));
        return;
    }
    d->groups[name] = data;
}





QScriptDebuggerConsoleCommand *QScriptDebuggerConsoleCommandManager::findCommand(const QString &name) const
{
    Q_D(const QScriptDebuggerConsoleCommandManager);
    for (int i = 0; i < d->commands.size(); ++i) {
        QScriptDebuggerConsoleCommand *cmd = d->commands.at(i);
        if (cmd->name() == name)
            return cmd;
        else if (cmd->aliases().contains(name))
            return cmd;
    }
    return 0;
}




QMap<QString, QList<QScriptDebuggerConsoleCommand*> > QScriptDebuggerConsoleCommandManager::commands() const
{
    Q_D(const QScriptDebuggerConsoleCommandManager);
    QMap<QString, QList<QScriptDebuggerConsoleCommand*> > result;
    for (int i = 0; i < d->commands.size(); ++i) {
        QScriptDebuggerConsoleCommand *cmd = d->commands.at(i);
        result[cmd->group()].append(cmd);
    }
    return result;
}




QScriptDebuggerConsoleCommandList QScriptDebuggerConsoleCommandManager::commandsInGroup(const QString &name) const
{
    Q_D(const QScriptDebuggerConsoleCommandManager);
    QScriptDebuggerConsoleCommandList result;
    for (int i = 0; i < d->commands.size(); ++i) {
        QScriptDebuggerConsoleCommand *cmd = d->commands.at(i);
        if (cmd->group() == name)
            result.append(cmd);
    }
    return result;
}




QScriptDebuggerConsoleCommandGroupData QScriptDebuggerConsoleCommandManager::commandGroupData(const QString &name) const
{
    Q_D(const QScriptDebuggerConsoleCommandManager);
    return d->groups.value(name);
}




QMap<QString, QScriptDebuggerConsoleCommandGroupData> QScriptDebuggerConsoleCommandManager::commandGroups() const
{
    Q_D(const QScriptDebuggerConsoleCommandManager);
    return d->groups;
}




QStringList QScriptDebuggerConsoleCommandManager::completions(const QString &prefix) const
{
    Q_D(const QScriptDebuggerConsoleCommandManager);
    QStringList result;
    for (int i = 0; i < d->commands.size(); ++i) {
        QScriptDebuggerConsoleCommand *cmd = d->commands.at(i);
        QStringList names;
        names.append(cmd->name());

        for (int j = 0; j < names.size(); ++j) {
            const QString &name = names.at(j);
            if ((name.length() > prefix.length()) && name.startsWith(prefix))
                result.append(name);
        }
    }
    std::stable_sort(result.begin(), result.end());
    return result;
}

QT_END_NAMESPACE
