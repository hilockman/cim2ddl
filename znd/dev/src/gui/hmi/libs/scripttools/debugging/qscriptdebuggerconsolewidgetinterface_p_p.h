#ifndef QSCRIPTDEBUGGERCONSOLEWIDGETINTERFACE_P_P_H
#define QSCRIPTDEBUGGERCONSOLEWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerConsoleHistorianInterface;
class QScriptCompletionProviderInterface;

class QScriptDebuggerConsoleWidgetInterface;
class QScriptDebuggerConsoleWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerConsoleWidgetInterface)
public:
    QScriptDebuggerConsoleWidgetInterfacePrivate();
    ~QScriptDebuggerConsoleWidgetInterfacePrivate();

    QScriptDebuggerConsoleHistorianInterface *historian;
    QScriptCompletionProviderInterface *completionProvider;
};

QT_END_NAMESPACE

#endif
