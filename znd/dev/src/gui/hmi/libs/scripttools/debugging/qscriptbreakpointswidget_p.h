#ifndef QSCRIPTBREAKPOINTSWIDGET_P_H
#define QSCRIPTBREAKPOINTSWIDGET_P_H 
#include "qscriptbreakpointswidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptBreakpointsWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptBreakpointsWidget:
    public QScriptBreakpointsWidgetInterface
{
    Q_OBJECT
public:
    QScriptBreakpointsWidget(QWidget *parent = 0);
    ~QScriptBreakpointsWidget();

    QScriptBreakpointsModel *breakpointsModel() const;
    void setBreakpointsModel(QScriptBreakpointsModel *model);

    QScriptDebuggerScriptsModel *scriptsModel() const;
    void setScriptsModel(QScriptDebuggerScriptsModel *model);

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Q_PRIVATE_SLOT(d_func(), void _q_newBreakpoint())
    Q_PRIVATE_SLOT(d_func(), void _q_deleteBreakpoint())
    Q_PRIVATE_SLOT(d_func(), void _q_onCurrentChanged(const QModelIndex &))
    Q_PRIVATE_SLOT(d_func(), void _q_onNewBreakpointRequest(const QString &, int))

    Q_DECLARE_PRIVATE(QScriptBreakpointsWidget)
    Q_DISABLE_COPY(QScriptBreakpointsWidget)
};

QT_END_NAMESPACE

#endif
