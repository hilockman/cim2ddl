#ifndef QSCRIPTOBJECTSNAPSHOT_P_H
#define QSCRIPTOBJECTSNAPSHOT_P_H 
#include <QtCore/qobjectdefs.h>

#include <QtCore/qstringlist.h>
#include "qscriptvalueproperty_p.h"

QT_BEGIN_NAMESPACE

class Q_AUTOTEST_EXPORT QScriptObjectSnapshot
{
public:
    struct Delta {
        QStringList removedProperties;
        QScriptValuePropertyList changedProperties;
        QScriptValuePropertyList addedProperties;
    };

    QScriptObjectSnapshot();
    ~QScriptObjectSnapshot();

    Delta capture(const QScriptValue &object);
    QScriptValuePropertyList properties() const;

    QScriptValueProperty findProperty(const QString &name) const;

private:
    QScriptValuePropertyList m_properties;
};

QT_END_NAMESPACE

#endif
