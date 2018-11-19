#include "qscriptdebuggerstackwidget_p.h"
#include "qscriptdebuggerstackwidgetinterface_p_p.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qheaderview.h>
#include <QtWidgets/qtreeview.h>
#include <QtWidgets/qboxlayout.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerStackWidgetPrivate
    : public QScriptDebuggerStackWidgetInterfacePrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerStackWidget)
public:
    QScriptDebuggerStackWidgetPrivate();
    ~QScriptDebuggerStackWidgetPrivate();


    void _q_onCurrentChanged(const QModelIndex &index);

    QTreeView *view;
};

QScriptDebuggerStackWidgetPrivate::QScriptDebuggerStackWidgetPrivate()
{
}

QScriptDebuggerStackWidgetPrivate::~QScriptDebuggerStackWidgetPrivate()
{
}

void QScriptDebuggerStackWidgetPrivate::_q_onCurrentChanged(const QModelIndex &index)
{
    Q_Q(QScriptDebuggerStackWidget);
    emit q->currentFrameChanged(index.row());
}

QScriptDebuggerStackWidget::QScriptDebuggerStackWidget(QWidget *parent)
    : QScriptDebuggerStackWidgetInterface(*new QScriptDebuggerStackWidgetPrivate, parent, 0)
{
    Q_D(QScriptDebuggerStackWidget);
    d->view = new QTreeView();
    d->view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    d->view->setAlternatingRowColors(true);
    d->view->setRootIsDecorated(false);
    d->view->setSelectionBehavior(QAbstractItemView::SelectRows);
    d->view->header()->setDefaultAlignment(Qt::AlignLeft);


    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setMargin(0);
    vbox->addWidget(d->view);
}

QScriptDebuggerStackWidget::~QScriptDebuggerStackWidget()
{
}




QAbstractItemModel *QScriptDebuggerStackWidget::stackModel() const
{
    Q_D(const QScriptDebuggerStackWidget);
    return d->view->model();
}




void QScriptDebuggerStackWidget::setStackModel(QAbstractItemModel *model)
{
    Q_D(QScriptDebuggerStackWidget);
    d->view->setModel(model);
    QObject::connect(d->view->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)),
                     this, SLOT(_q_onCurrentChanged(QModelIndex)));
    d->view->header()->resizeSection(0, 50);
}




int QScriptDebuggerStackWidget::currentFrameIndex() const
{
    Q_D(const QScriptDebuggerStackWidget);
    return d->view->currentIndex().row();
}




void QScriptDebuggerStackWidget::setCurrentFrameIndex(int frameIndex)
{
    Q_D(QScriptDebuggerStackWidget);
    d->view->setCurrentIndex(d->view->model()->index(frameIndex, 0));
}

QT_END_NAMESPACE

#include "moc_qscriptdebuggerstackwidget_p.cpp"
