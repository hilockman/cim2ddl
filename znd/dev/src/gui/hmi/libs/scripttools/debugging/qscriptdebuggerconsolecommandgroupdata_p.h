#ifndef QSCRIPTDEBUGGERCONSOLECOMMANDGROUPDATA_P_H
#define QSCRIPTDEBUGGERCONSOLECOMMANDGROUPDATA_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/private/qscopedpointer_p.h>
#include <QtCore/qmap.h>

QT_BEGIN_NAMESPACE

class QString;

class QScriptDebuggerConsoleCommandGroupDataPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleCommandGroupData
{
public:
    QScriptDebuggerConsoleCommandGroupData();
    QScriptDebuggerConsoleCommandGroupData(
        const QString &shortDescription,
        const QString &longDescription);
    QScriptDebuggerConsoleCommandGroupData(
        const QScriptDebuggerConsoleCommandGroupData &other);
    ~QScriptDebuggerConsoleCommandGroupData();

    QString shortDescription() const;
    QString longDescription() const;

    bool isValid() const;

    QScriptDebuggerConsoleCommandGroupData &operator=(
        const QScriptDebuggerConsoleCommandGroupData &other);

private:
    QScopedSharedPointer<QScriptDebuggerConsoleCommandGroupDataPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerConsoleCommandGroupData)
};

typedef QMap<QString, QScriptDebuggerConsoleCommandGroupData> QScriptDebuggerConsoleCommandGroupMap;

QT_END_NAMESPACE

#endif
