#ifndef QSCRIPTDEBUGGERSTACKWIDGET_P_H
#define QSCRIPTDEBUGGERSTACKWIDGET_P_H 
#include "qscriptdebuggerstackwidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerStackWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerStackWidget:
    public QScriptDebuggerStackWidgetInterface
{
    Q_OBJECT
public:
    QScriptDebuggerStackWidget(QWidget *parent = 0);
    ~QScriptDebuggerStackWidget();

    QAbstractItemModel *stackModel() const;
    void setStackModel(QAbstractItemModel *model);

    int currentFrameIndex() const;
    void setCurrentFrameIndex(int frameIndex);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerStackWidget)
    Q_DISABLE_COPY(QScriptDebuggerStackWidget)

    Q_PRIVATE_SLOT(d_func(), void _q_onCurrentChanged(const QModelIndex &))
};

QT_END_NAMESPACE

#endif
