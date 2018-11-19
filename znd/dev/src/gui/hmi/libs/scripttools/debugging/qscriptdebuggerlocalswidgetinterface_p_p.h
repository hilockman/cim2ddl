#ifndef QSCRIPTDEBUGGERLOCALSWIDGETINTERFACE_P_P_H
#define QSCRIPTDEBUGGERLOCALSWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptCompletionProviderInterface;

class QScriptDebuggerLocalsWidgetInterface;
class QScriptDebuggerLocalsWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerLocalsWidgetInterface)
public:
    QScriptDebuggerLocalsWidgetInterfacePrivate();
    ~QScriptDebuggerLocalsWidgetInterfacePrivate();

    QScriptCompletionProviderInterface *completionProvider;
};

QT_END_NAMESPACE

#endif
