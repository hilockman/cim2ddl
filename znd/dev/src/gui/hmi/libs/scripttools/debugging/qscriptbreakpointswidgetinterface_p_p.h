#ifndef QSCRIPTBREAKPOINTSWIDGETINTERFACE_P_P_H
#define QSCRIPTBREAKPOINTSWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptBreakpointsWidgetInterface;
class QScriptBreakpointsWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptBreakpointsWidgetInterface)
public:
    QScriptBreakpointsWidgetInterfacePrivate();
    ~QScriptBreakpointsWidgetInterfacePrivate();
};

QT_END_NAMESPACE

#endif
