#ifndef QSCRIPTDEBUGGERSCRIPTSWIDGETINTERFACE_P_P_H
#define QSCRIPTDEBUGGERSCRIPTSWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerScriptsWidgetInterface;
class QScriptDebuggerScriptsWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerScriptsWidgetInterface)
public:
    QScriptDebuggerScriptsWidgetInterfacePrivate();
    ~QScriptDebuggerScriptsWidgetInterfacePrivate();
};

QT_END_NAMESPACE

#endif
