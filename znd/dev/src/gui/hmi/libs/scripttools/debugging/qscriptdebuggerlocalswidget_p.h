#ifndef QSCRIPTDEBUGGERLOCALSWIDGET_P_H
#define QSCRIPTDEBUGGERLOCALSWIDGET_P_H 
#include "qscriptdebuggerlocalswidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerLocalsWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerLocalsWidget:
    public QScriptDebuggerLocalsWidgetInterface
{
    Q_OBJECT
public:
    QScriptDebuggerLocalsWidget(QWidget *parent = 0);
    ~QScriptDebuggerLocalsWidget();

    QScriptDebuggerLocalsModel *localsModel() const;
    void setLocalsModel(QScriptDebuggerLocalsModel *model);

    void expand(const QModelIndex &index);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerLocalsWidget)
    Q_DISABLE_COPY(QScriptDebuggerLocalsWidget)

    Q_PRIVATE_SLOT(d_func(), void _q_onCompletionTaskFinished())
    Q_PRIVATE_SLOT(d_func(), void _q_insertCompletion(const QString &))
    Q_PRIVATE_SLOT(d_func(), void _q_expandIndex(const QModelIndex &))
};

QT_END_NAMESPACE

#endif
