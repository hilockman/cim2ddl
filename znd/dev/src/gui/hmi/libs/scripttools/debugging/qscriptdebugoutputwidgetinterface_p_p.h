#ifndef QSCRIPTDEBUGOUTPUTWIDGETINTERFACE_P_P_H
#define QSCRIPTDEBUGOUTPUTWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptDebugOutputWidgetInterface;
class QScriptDebugOutputWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebugOutputWidgetInterface)
public:
    QScriptDebugOutputWidgetInterfacePrivate();
    ~QScriptDebugOutputWidgetInterfacePrivate();
};

QT_END_NAMESPACE

#endif
