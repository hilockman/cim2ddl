#ifndef QSCRIPTERRORLOGWIDGETINTERFACE_P_H
#define QSCRIPTERRORLOGWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

#include "qscriptmessagehandlerinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptErrorLogWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptErrorLogWidgetInterface:
    public QWidget,
    public QScriptMessageHandlerInterface
{
    Q_OBJECT
public:
    ~QScriptErrorLogWidgetInterface();

    virtual void clear() = 0;

protected:
    QScriptErrorLogWidgetInterface(QScriptErrorLogWidgetInterfacePrivate &dd,
                                   QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptErrorLogWidgetInterface)
    Q_DISABLE_COPY(QScriptErrorLogWidgetInterface)
};

QT_END_NAMESPACE

#endif
