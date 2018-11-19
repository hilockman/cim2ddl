#include "qscriptdebuggerlocalswidgetinterface_p.h"
#include "qscriptdebuggerlocalswidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerLocalsWidgetInterfacePrivate::QScriptDebuggerLocalsWidgetInterfacePrivate()
{
    completionProvider = 0;
}

QScriptDebuggerLocalsWidgetInterfacePrivate::~QScriptDebuggerLocalsWidgetInterfacePrivate()
{
}

QScriptDebuggerLocalsWidgetInterface::~QScriptDebuggerLocalsWidgetInterface()
{
}

QScriptDebuggerLocalsWidgetInterface::QScriptDebuggerLocalsWidgetInterface(
    QScriptDebuggerLocalsWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QScriptCompletionProviderInterface *QScriptDebuggerLocalsWidgetInterface::completionProvider() const
{
    Q_D(const QScriptDebuggerLocalsWidgetInterface);
    return d->completionProvider;
}

void QScriptDebuggerLocalsWidgetInterface::setCompletionProvider(QScriptCompletionProviderInterface *completionProvider)
{
    Q_D(QScriptDebuggerLocalsWidgetInterface);
    d->completionProvider = completionProvider;
}

QT_END_NAMESPACE
