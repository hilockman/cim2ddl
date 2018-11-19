#ifndef QSCRIPTDEBUGGEROBJECTSNAPSHOTDELTA_P_H
#define QSCRIPTDEBUGGEROBJECTSNAPSHOTDELTA_P_H 
#include <QtCore/qobjectdefs.h>

#include <QtCore/qstringlist.h>
#include "qscriptdebuggervalueproperty_p.h"

QT_BEGIN_NAMESPACE

class QDataStream;

class Q_AUTOTEST_EXPORT QScriptDebuggerObjectSnapshotDelta
{
public:
    QStringList removedProperties;
    QScriptDebuggerValuePropertyList changedProperties;
    QScriptDebuggerValuePropertyList addedProperties;
};

Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptDebuggerObjectSnapshotDelta &);
Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptDebuggerObjectSnapshotDelta &);

QT_END_NAMESPACE

#endif
