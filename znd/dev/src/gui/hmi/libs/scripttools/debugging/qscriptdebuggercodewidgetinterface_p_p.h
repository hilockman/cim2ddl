#ifndef QSCRIPTDEBUGGERCODEWIDGETINTERFACE_P_P_H
#define QSCRIPTDEBUGGERCODEWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCodeWidgetInterface;
class QScriptDebuggerCodeWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerCodeWidgetInterface)
public:
    QScriptDebuggerCodeWidgetInterfacePrivate();
    ~QScriptDebuggerCodeWidgetInterfacePrivate();
};

QT_END_NAMESPACE

#endif
