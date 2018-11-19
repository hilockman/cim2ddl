#include "qscriptdebuggercodeviewinterface_p.h"
#include "qscriptdebuggercodeviewinterface_p_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerCodeViewInterfacePrivate::QScriptDebuggerCodeViewInterfacePrivate()
{
}

QScriptDebuggerCodeViewInterfacePrivate::~QScriptDebuggerCodeViewInterfacePrivate()
{
}

QScriptDebuggerCodeViewInterface::~QScriptDebuggerCodeViewInterface()
{
}

QScriptDebuggerCodeViewInterface::QScriptDebuggerCodeViewInterface(
    QScriptDebuggerCodeViewInterfacePrivate &dd,
    QWidget *parent, Qt::WindowFlags flags)
    : QWidget(dd, parent, flags)
{
}

QT_END_NAMESPACE
