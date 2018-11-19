#include "qscriptdebuggerstackwidgetinterface_p.h"
#include "qscriptdebuggerstackwidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerStackWidgetInterfacePrivate::QScriptDebuggerStackWidgetInterfacePrivate()
{
}

QScriptDebuggerStackWidgetInterfacePrivate::~QScriptDebuggerStackWidgetInterfacePrivate()
{
}

QScriptDebuggerStackWidgetInterface::~QScriptDebuggerStackWidgetInterface()
{
}

QScriptDebuggerStackWidgetInterface::QScriptDebuggerStackWidgetInterface(
    QScriptDebuggerStackWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
