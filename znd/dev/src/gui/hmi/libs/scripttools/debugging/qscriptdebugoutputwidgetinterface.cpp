#include "qscriptdebugoutputwidgetinterface_p.h"
#include "qscriptdebugoutputwidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebugOutputWidgetInterfacePrivate::QScriptDebugOutputWidgetInterfacePrivate()
{
}

QScriptDebugOutputWidgetInterfacePrivate::~QScriptDebugOutputWidgetInterfacePrivate()
{
}

QScriptDebugOutputWidgetInterface::~QScriptDebugOutputWidgetInterface()
{
}

QScriptDebugOutputWidgetInterface::QScriptDebugOutputWidgetInterface(
    QScriptDebugOutputWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
