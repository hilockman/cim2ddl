#ifndef QSCRIPTMESSAGEHANDLERINTERFACE_P_H
#define QSCRIPTMESSAGEHANDLERINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

#include <QtCore/qvariant.h>

QT_BEGIN_NAMESPACE

class Q_AUTOTEST_EXPORT QScriptMessageHandlerInterface
{
public:
    virtual ~QScriptMessageHandlerInterface() {}

    virtual void message(QtMsgType type, const QString &text,
                         const QString &fileName = QString(),
                         int lineNumber = -1, int columnNumber = -1,
                         const QVariant &data = QVariant()) = 0;
};

QT_END_NAMESPACE

#endif
