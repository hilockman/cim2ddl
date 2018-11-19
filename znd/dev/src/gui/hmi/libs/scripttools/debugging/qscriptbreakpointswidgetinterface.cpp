#include "qscriptbreakpointswidgetinterface_p.h"
#include "qscriptbreakpointswidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptBreakpointsWidgetInterfacePrivate::QScriptBreakpointsWidgetInterfacePrivate()
{
}

QScriptBreakpointsWidgetInterfacePrivate::~QScriptBreakpointsWidgetInterfacePrivate()
{
}

QScriptBreakpointsWidgetInterface::~QScriptBreakpointsWidgetInterface()
{
}

QScriptBreakpointsWidgetInterface::QScriptBreakpointsWidgetInterface(
    QScriptBreakpointsWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
