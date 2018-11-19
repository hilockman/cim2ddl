#ifndef QSCRIPTDEBUGOUTPUTWIDGET_P_H
#define QSCRIPTDEBUGOUTPUTWIDGET_P_H 
#include "qscriptdebugoutputwidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebugOutputWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptDebugOutputWidget:
    public QScriptDebugOutputWidgetInterface
{
    Q_OBJECT
public:
    QScriptDebugOutputWidget(QWidget *parent = 0);
    ~QScriptDebugOutputWidget();

    void message(QtMsgType type, const QString &text,
                 const QString &fileName = QString(),
                 int lineNumber = -1, int columnNumber = -1,
                 const QVariant &data = QVariant());

    void clear();

private:
    Q_DECLARE_PRIVATE(QScriptDebugOutputWidget)
    Q_DISABLE_COPY(QScriptDebugOutputWidget)
};

QT_END_NAMESPACE

#endif
