#ifndef QSCRIPTSTDMESSAGEHANDLER_P_H
#define QSCRIPTSTDMESSAGEHANDLER_P_H 
#include <QtCore/qscopedpointer.h>

#include "qscriptmessagehandlerinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptStdMessageHandlerPrivate;
class Q_AUTOTEST_EXPORT QScriptStdMessageHandler
    : public QScriptMessageHandlerInterface
{
public:
    QScriptStdMessageHandler();
    ~QScriptStdMessageHandler();

    void message(QtMsgType type, const QString &text,
                 const QString &fileName = QString(),
                 int lineNumber = -1, int columnNumber = -1,
                 const QVariant &data = QVariant());

private:
    QScopedPointer<QScriptStdMessageHandlerPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(QScriptStdMessageHandler)
    Q_DISABLE_COPY(QScriptStdMessageHandler)
};

QT_END_NAMESPACE

#endif
