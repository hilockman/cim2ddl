#include "qscripterrorlogwidgetinterface_p.h"
#include "qscripterrorlogwidgetinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptErrorLogWidgetInterfacePrivate::QScriptErrorLogWidgetInterfacePrivate()
{
}

QScriptErrorLogWidgetInterfacePrivate::~QScriptErrorLogWidgetInterfacePrivate()
{
}

QScriptErrorLogWidgetInterface::~QScriptErrorLogWidgetInterface()
{
}

QScriptErrorLogWidgetInterface::QScriptErrorLogWidgetInterface(
    QScriptErrorLogWidgetInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
