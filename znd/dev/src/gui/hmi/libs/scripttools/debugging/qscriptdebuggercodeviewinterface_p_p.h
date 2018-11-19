#ifndef QSCRIPTDEBUGGERCODEVIEWINTERFACE_P_P_H
#define QSCRIPTDEBUGGERCODEVIEWINTERFACE_P_P_H 
#include <private/qwidget_p.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCodeViewInterface;
class QScriptDebuggerCodeViewInterfacePrivate
    : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerCodeViewInterface)
public:
    QScriptDebuggerCodeViewInterfacePrivate();
    ~QScriptDebuggerCodeViewInterfacePrivate();
};

QT_END_NAMESPACE

#endif
