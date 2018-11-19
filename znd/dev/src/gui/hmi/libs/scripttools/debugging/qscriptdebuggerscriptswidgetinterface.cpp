#include "qscriptdebuggerscriptswidgetinterface_p.h"
#include "qscriptdebuggerscriptswidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerScriptsWidgetInterfacePrivate::QScriptDebuggerScriptsWidgetInterfacePrivate()
{
}

QScriptDebuggerScriptsWidgetInterfacePrivate::~QScriptDebuggerScriptsWidgetInterfacePrivate()
{
}

QScriptDebuggerScriptsWidgetInterface::~QScriptDebuggerScriptsWidgetInterface()
{
}

QScriptDebuggerScriptsWidgetInterface::QScriptDebuggerScriptsWidgetInterface(
    QScriptDebuggerScriptsWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
