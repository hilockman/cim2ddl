#include "qscriptdebuggercodefinderwidgetinterface_p.h"
#include "qscriptdebuggercodefinderwidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerCodeFinderWidgetInterfacePrivate::QScriptDebuggerCodeFinderWidgetInterfacePrivate()
{
}

QScriptDebuggerCodeFinderWidgetInterfacePrivate::~QScriptDebuggerCodeFinderWidgetInterfacePrivate()
{
}

QScriptDebuggerCodeFinderWidgetInterface::~QScriptDebuggerCodeFinderWidgetInterface()
{
}

QScriptDebuggerCodeFinderWidgetInterface::QScriptDebuggerCodeFinderWidgetInterface(
    QScriptDebuggerCodeFinderWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
