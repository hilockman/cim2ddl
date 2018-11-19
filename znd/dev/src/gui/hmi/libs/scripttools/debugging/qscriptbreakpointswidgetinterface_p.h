#ifndef QSCRIPTBREAKPOINTSWIDGETINTERFACE_P_H
#define QSCRIPTBREAKPOINTSWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE

class QScriptBreakpointsModel;
class QScriptDebuggerScriptsModel;

class QScriptBreakpointsWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptBreakpointsWidgetInterface:
    public QWidget
{
    Q_OBJECT
public:
    ~QScriptBreakpointsWidgetInterface();

    virtual QScriptBreakpointsModel *breakpointsModel() const = 0;
    virtual void setBreakpointsModel(QScriptBreakpointsModel *model) = 0;

    virtual QScriptDebuggerScriptsModel *scriptsModel() const = 0;
    virtual void setScriptsModel(QScriptDebuggerScriptsModel *model) = 0;

Q_SIGNALS:
    void currentScriptChanged(qint64 scriptId);

protected:
    QScriptBreakpointsWidgetInterface(
        QScriptBreakpointsWidgetInterfacePrivate &dd,
        QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptBreakpointsWidgetInterface)
    Q_DISABLE_COPY(QScriptBreakpointsWidgetInterface)
};

QT_END_NAMESPACE

#endif
