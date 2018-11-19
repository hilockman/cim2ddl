#ifndef QSCRIPTDEBUGGERCODEFINDERWIDGETINTERFACE_P_P_H
#define QSCRIPTDEBUGGERCODEFINDERWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCodeFinderWidgetInterface;
class QScriptDebuggerCodeFinderWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerCodeFinderWidgetInterface)
public:
    QScriptDebuggerCodeFinderWidgetInterfacePrivate();
    ~QScriptDebuggerCodeFinderWidgetInterfacePrivate();
};

QT_END_NAMESPACE

#endif
