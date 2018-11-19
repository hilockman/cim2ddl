#ifndef QSCRIPTVALUEPROPERTY_P_H
#define QSCRIPTVALUEPROPERTY_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qlist.h>
#include <QtCore/private/qscopedpointer_p.h>
#include <QtScript/qscriptvalue.h>

QT_BEGIN_NAMESPACE

class QString;

class QScriptValuePropertyPrivate;
class Q_AUTOTEST_EXPORT QScriptValueProperty
{
public:
    QScriptValueProperty();
    QScriptValueProperty(const QString &name,
                         const QScriptValue &value,
                         QScriptValue::PropertyFlags flags);
    QScriptValueProperty(const QScriptValueProperty &other);
    ~QScriptValueProperty();

    QScriptValueProperty &operator=(const QScriptValueProperty &other);

    QString name() const;
    QScriptValue value() const;
    QScriptValue::PropertyFlags flags() const;

    bool isValid() const;

private:
    QScopedSharedPointer<QScriptValuePropertyPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptValueProperty)
};

typedef QList<QScriptValueProperty> QScriptValuePropertyList;

QT_END_NAMESPACE

#endif
