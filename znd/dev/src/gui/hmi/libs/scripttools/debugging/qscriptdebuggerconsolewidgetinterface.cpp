#include "qscriptdebuggerconsolewidgetinterface_p.h"
#include "qscriptdebuggerconsolewidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerConsoleWidgetInterfacePrivate::QScriptDebuggerConsoleWidgetInterfacePrivate()
{
    historian = 0;
    completionProvider = 0;
}

QScriptDebuggerConsoleWidgetInterfacePrivate::~QScriptDebuggerConsoleWidgetInterfacePrivate()
{
}

QScriptDebuggerConsoleWidgetInterface::~QScriptDebuggerConsoleWidgetInterface()
{
}

QScriptDebuggerConsoleWidgetInterface::QScriptDebuggerConsoleWidgetInterface(
    QScriptDebuggerConsoleWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QScriptDebuggerConsoleHistorianInterface *QScriptDebuggerConsoleWidgetInterface::commandHistorian() const
{
    Q_D(const QScriptDebuggerConsoleWidgetInterface);
    return d->historian;
}

void QScriptDebuggerConsoleWidgetInterface::setCommandHistorian(
    QScriptDebuggerConsoleHistorianInterface *historian)
{
    Q_D(QScriptDebuggerConsoleWidgetInterface);
    d->historian = historian;
}

QScriptCompletionProviderInterface *QScriptDebuggerConsoleWidgetInterface::completionProvider() const
{
    Q_D(const QScriptDebuggerConsoleWidgetInterface);
    return d->completionProvider;
}

void QScriptDebuggerConsoleWidgetInterface::setCompletionProvider(
    QScriptCompletionProviderInterface *completionProvider)
{
    Q_D(QScriptDebuggerConsoleWidgetInterface);
    d->completionProvider = completionProvider;
}

QT_END_NAMESPACE
