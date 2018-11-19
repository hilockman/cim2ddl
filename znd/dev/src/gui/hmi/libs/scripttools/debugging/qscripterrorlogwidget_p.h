#ifndef QSCRIPTERRORLOGWIDGET_P_H
#define QSCRIPTERRORLOGWIDGET_P_H 
#include "qscripterrorlogwidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptErrorLogWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptErrorLogWidget:
    public QScriptErrorLogWidgetInterface
{
    Q_OBJECT
public:
    QScriptErrorLogWidget(QWidget *parent = 0);
    ~QScriptErrorLogWidget();

    void message(QtMsgType type, const QString &text,
                 const QString &fileName = QString(),
                 int lineNumber = -1, int columnNumber = -1,
                 const QVariant &data = QVariant());

    void clear();

private:
    Q_DECLARE_PRIVATE(QScriptErrorLogWidget)
    Q_DISABLE_COPY(QScriptErrorLogWidget)
};

QT_END_NAMESPACE

#endif
