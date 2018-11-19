#ifndef QSCRIPTDEBUGGERVALUEPROPERTY_P_H
#define QSCRIPTDEBUGGERVALUEPROPERTY_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qlist.h>
#include <QtCore/private/qscopedpointer_p.h>
#include <QtScript/qscriptvalue.h>

QT_BEGIN_NAMESPACE

class QDataStream;
class QString;
class QScriptDebuggerValue;

class QScriptDebuggerValuePropertyPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerValueProperty
{
public:
    QScriptDebuggerValueProperty();
    QScriptDebuggerValueProperty(const QString &name,
                                 const QScriptDebuggerValue &value,
                                 const QString &valueAsString,
                                 QScriptValue::PropertyFlags flags);
    QScriptDebuggerValueProperty(const QScriptDebuggerValueProperty &other);
    ~QScriptDebuggerValueProperty();

    QScriptDebuggerValueProperty &operator=(const QScriptDebuggerValueProperty &other);

    QString name() const;
    QScriptDebuggerValue value() const;
    QString valueAsString() const;
    QScriptValue::PropertyFlags flags() const;

    bool isValid() const;

private:
    QScopedSharedPointer<QScriptDebuggerValuePropertyPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptDebuggerValueProperty)
};

typedef QList<QScriptDebuggerValueProperty> QScriptDebuggerValuePropertyList;

Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptDebuggerValueProperty &);
Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptDebuggerValueProperty &);

QT_END_NAMESPACE

#endif
