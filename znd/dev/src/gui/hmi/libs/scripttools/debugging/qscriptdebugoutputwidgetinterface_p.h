#ifndef QSCRIPTDEBUGOUTPUTWIDGETINTERFACE_P_H
#define QSCRIPTDEBUGOUTPUTWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

#include "qscriptmessagehandlerinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebugOutputWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebugOutputWidgetInterface:
    public QWidget,
    public QScriptMessageHandlerInterface
{
    Q_OBJECT
public:
    ~QScriptDebugOutputWidgetInterface();

    virtual void clear() = 0;

protected:
    QScriptDebugOutputWidgetInterface(QScriptDebugOutputWidgetInterfacePrivate &dd,
                                          QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebugOutputWidgetInterface)
    Q_DISABLE_COPY(QScriptDebugOutputWidgetInterface)
};

QT_END_NAMESPACE

#endif
