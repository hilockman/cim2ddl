#include "qscriptdebuggercodewidgetinterface_p.h"
#include "qscriptdebuggercodewidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerCodeWidgetInterfacePrivate::QScriptDebuggerCodeWidgetInterfacePrivate()
{
}

QScriptDebuggerCodeWidgetInterfacePrivate::~QScriptDebuggerCodeWidgetInterfacePrivate()
{
}

QScriptDebuggerCodeWidgetInterface::~QScriptDebuggerCodeWidgetInterface()
{
}

QScriptDebuggerCodeWidgetInterface::QScriptDebuggerCodeWidgetInterface(
    QScriptDebuggerCodeWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
