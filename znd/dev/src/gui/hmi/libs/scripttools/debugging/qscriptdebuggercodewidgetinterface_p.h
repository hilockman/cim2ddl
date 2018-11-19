#ifndef QSCRIPTDEBUGGERCODEWIDGETINTERFACE_P_H
#define QSCRIPTDEBUGGERCODEWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerScriptsModel;
class QScriptBreakpointsModel;
class QScriptToolTipProviderInterface;

class QScriptDebuggerCodeViewInterface;

class QScriptDebuggerCodeWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCodeWidgetInterface:
    public QWidget
{
    Q_OBJECT
public:
    ~QScriptDebuggerCodeWidgetInterface();

    virtual QScriptDebuggerScriptsModel *scriptsModel() const = 0;
    virtual void setScriptsModel(QScriptDebuggerScriptsModel *model) = 0;

    virtual QScriptBreakpointsModel *breakpointsModel() const = 0;
    virtual void setBreakpointsModel(QScriptBreakpointsModel *model) = 0;

    virtual void setToolTipProvider(QScriptToolTipProviderInterface *toolTipProvider) = 0;

    virtual qint64 currentScriptId() const = 0;
    virtual void setCurrentScript(qint64 scriptId) = 0;

    virtual void invalidateExecutionLineNumbers() = 0;

    virtual QScriptDebuggerCodeViewInterface *currentView() const = 0;

protected:
    QScriptDebuggerCodeWidgetInterface(
        QScriptDebuggerCodeWidgetInterfacePrivate &dd,
        QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCodeWidgetInterface)
    Q_DISABLE_COPY(QScriptDebuggerCodeWidgetInterface)
};

QT_END_NAMESPACE

#endif
