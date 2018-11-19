#ifndef QSCRIPTDEBUGGERSTACKWIDGETINTERFACE_P_P_H
#define QSCRIPTDEBUGGERSTACKWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerStackWidgetInterface;
class QScriptDebuggerStackWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerStackWidgetInterface)
public:
    QScriptDebuggerStackWidgetInterfacePrivate();
    ~QScriptDebuggerStackWidgetInterfacePrivate();
};

QT_END_NAMESPACE

#endif
