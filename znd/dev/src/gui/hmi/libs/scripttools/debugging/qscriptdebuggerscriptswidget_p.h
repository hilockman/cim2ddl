#ifndef QSCRIPTDEBUGGERSCRIPTSWIDGET_P_H
#define QSCRIPTDEBUGGERSCRIPTSWIDGET_P_H 
#include "qscriptdebuggerscriptswidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerScriptsWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerScriptsWidget:
    public QScriptDebuggerScriptsWidgetInterface
{
    Q_OBJECT
public:
    QScriptDebuggerScriptsWidget(QWidget *parent = 0);
    ~QScriptDebuggerScriptsWidget();

    QScriptDebuggerScriptsModel *scriptsModel() const;
    void setScriptsModel(QScriptDebuggerScriptsModel *model);

    qint64 currentScriptId() const;
    void setCurrentScript(qint64 id);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerScriptsWidget)
    Q_DISABLE_COPY(QScriptDebuggerScriptsWidget)

    Q_PRIVATE_SLOT(d_func(), void _q_onCurrentChanged(const QModelIndex &))
};

QT_END_NAMESPACE

#endif
