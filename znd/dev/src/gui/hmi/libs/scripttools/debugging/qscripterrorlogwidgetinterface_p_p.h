#ifndef QSCRIPTERRORLOGWIDGETINTERFACE_P_P_H
#define QSCRIPTERRORLOGWIDGETINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptErrorLogWidgetInterface;
class QScriptErrorLogWidgetInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptErrorLogWidgetInterface)
public:
    QScriptErrorLogWidgetInterfacePrivate();
    ~QScriptErrorLogWidgetInterfacePrivate();
};

QT_END_NAMESPACE

#endif
