#ifndef QSCRIPTDEBUGGERCONSOLEHISTORIANINTERFACE_P_H
#define QSCRIPTDEBUGGERCONSOLEHISTORIANINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QString;

class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleHistorianInterface
{
public:
    virtual ~QScriptDebuggerConsoleHistorianInterface() {}

    virtual int historyCount() const = 0;
    virtual QString historyAt(int index) const = 0;
    virtual void changeHistoryAt(int index, const QString &newHistory) = 0;
};

QT_END_NAMESPACE

#endif
