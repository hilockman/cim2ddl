#include "qscriptstdmessagehandler_p.h"
#include <stdio.h>

QT_BEGIN_NAMESPACE
class QScriptStdMessageHandlerPrivate
{
public:
    QScriptStdMessageHandlerPrivate() {}
    ~QScriptStdMessageHandlerPrivate() {}
};

QScriptStdMessageHandler::QScriptStdMessageHandler()
    : d_ptr(new QScriptStdMessageHandlerPrivate)
{
}

QScriptStdMessageHandler::~QScriptStdMessageHandler()
{
}

void QScriptStdMessageHandler::message(QtMsgType type, const QString &text,
                                       const QString &fileName,
                                       int lineNumber, int columnNumber,
                                       const QVariant & )
{
    QString msg;
    if (!fileName.isEmpty() || (lineNumber != -1)) {
        if (!fileName.isEmpty())
            msg.append(fileName);
        else
            msg.append(QLatin1String("<noname>"));
        if (lineNumber != -1) {
            msg.append(QLatin1Char(':'));
            msg.append(QString::number(lineNumber));
            if (columnNumber != -1) {
                msg.append(QLatin1Char(':'));
                msg.append(QString::number(columnNumber));
            }
        }
        msg.append(QLatin1String(": "));
    }
    msg.append(text);

    FILE *fp = (type == QtDebugMsg) ? stdout : stderr;
    fprintf(fp, "%s\n", msg.toLatin1().constData());
    fflush(fp);
}

QT_END_NAMESPACE
