#ifndef QSCRIPTDEBUGGERCODEWIDGET_P_H
#define QSCRIPTDEBUGGERCODEWIDGET_P_H 
#include "qscriptdebuggercodewidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerCodeWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCodeWidget:
    public QScriptDebuggerCodeWidgetInterface
{
    Q_OBJECT
public:
    QScriptDebuggerCodeWidget(QWidget *parent = 0);
    ~QScriptDebuggerCodeWidget();

    QScriptDebuggerScriptsModel *scriptsModel() const;
    void setScriptsModel(QScriptDebuggerScriptsModel *model);

    void setToolTipProvider(QScriptToolTipProviderInterface *toolTipProvider);

    qint64 currentScriptId() const;
    void setCurrentScript(qint64 scriptId);

    void invalidateExecutionLineNumbers();

    QScriptBreakpointsModel *breakpointsModel() const;
    void setBreakpointsModel(QScriptBreakpointsModel *model);

    QScriptDebuggerCodeViewInterface *currentView() const;

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCodeWidget)
    Q_DISABLE_COPY(QScriptDebuggerCodeWidget)

    Q_PRIVATE_SLOT(d_func(), void _q_onBreakpointToggleRequest(int,bool))
    Q_PRIVATE_SLOT(d_func(), void _q_onBreakpointEnableRequest(int,bool))
    Q_PRIVATE_SLOT(d_func(), void _q_onBreakpointsAboutToBeRemoved(const QModelIndex &,int,int))
    Q_PRIVATE_SLOT(d_func(), void _q_onBreakpointsInserted(const QModelIndex &,int,int))
    Q_PRIVATE_SLOT(d_func(), void _q_onBreakpointsDataChanged(const QModelIndex &, const QModelIndex &))
    Q_PRIVATE_SLOT(d_func(), void _q_onScriptsChanged())
    Q_PRIVATE_SLOT(d_func(), void _q_onToolTipRequest(const QPoint &, int, const QStringList &))
};

QT_END_NAMESPACE

#endif
