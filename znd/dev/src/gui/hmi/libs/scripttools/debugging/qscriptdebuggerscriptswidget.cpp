#include "qscriptdebuggerscriptswidget_p.h"
#include "qscriptdebuggerscriptswidgetinterface_p_p.h"
#include "qscriptdebuggerscriptsmodel_p.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qheaderview.h>
#include <QtWidgets/qtreeview.h>
#include <QtWidgets/qboxlayout.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerScriptsWidgetPrivate
    : public QScriptDebuggerScriptsWidgetInterfacePrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerScriptsWidget)
public:
    QScriptDebuggerScriptsWidgetPrivate();
    ~QScriptDebuggerScriptsWidgetPrivate();


    void _q_onCurrentChanged(const QModelIndex &index);

    QTreeView *view;
    qint64 currentScriptId;
};

QScriptDebuggerScriptsWidgetPrivate::QScriptDebuggerScriptsWidgetPrivate()
{
    currentScriptId = -1;
}

QScriptDebuggerScriptsWidgetPrivate::~QScriptDebuggerScriptsWidgetPrivate()
{
}

void QScriptDebuggerScriptsWidgetPrivate::_q_onCurrentChanged(const QModelIndex &index)
{
    Q_Q(QScriptDebuggerScriptsWidget);
    if (!index.isValid())
        return;
    qint64 sid = q->scriptsModel()->scriptIdFromIndex(index);
    if (sid != -1) {
        if (currentScriptId != sid) {
            currentScriptId = sid;
            emit q->currentScriptChanged(sid);
        }
    } else {
        qint64 sid = q->scriptsModel()->scriptIdFromIndex(index.parent());
        Q_ASSERT(sid != -1);
        currentScriptId = sid;
        emit q->currentScriptChanged(sid);
        QPair<QString, int> info = q->scriptsModel()->scriptFunctionInfoFromIndex(index);
        emit q->scriptLocationSelected(info.second);
    }
}

QScriptDebuggerScriptsWidget::QScriptDebuggerScriptsWidget(QWidget *parent)
    : QScriptDebuggerScriptsWidgetInterface(*new QScriptDebuggerScriptsWidgetPrivate, parent, 0)
{
    Q_D(QScriptDebuggerScriptsWidget);
    d->view = new QTreeView();
    d->view->setEditTriggers(QAbstractItemView::NoEditTriggers);


    d->view->setSelectionBehavior(QAbstractItemView::SelectRows);
    d->view->header()->hide();



    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setMargin(0);
    vbox->addWidget(d->view);
}

QScriptDebuggerScriptsWidget::~QScriptDebuggerScriptsWidget()
{
}




QScriptDebuggerScriptsModel *QScriptDebuggerScriptsWidget::scriptsModel() const
{
    Q_D(const QScriptDebuggerScriptsWidget);
    return qobject_cast<QScriptDebuggerScriptsModel*>(d->view->model());
}




void QScriptDebuggerScriptsWidget::setScriptsModel(QScriptDebuggerScriptsModel *model)
{
    Q_D(QScriptDebuggerScriptsWidget);
    d->view->setModel(model);
    QObject::connect(d->view->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)),
                     this, SLOT(_q_onCurrentChanged(QModelIndex)));
}

qint64 QScriptDebuggerScriptsWidget::currentScriptId() const
{
    Q_D(const QScriptDebuggerScriptsWidget);
    return scriptsModel()->scriptIdFromIndex(d->view->currentIndex());
}

void QScriptDebuggerScriptsWidget::setCurrentScript(qint64 id)
{
    Q_D(QScriptDebuggerScriptsWidget);
    d->view->setCurrentIndex(scriptsModel()->indexFromScriptId(id));
}

QT_END_NAMESPACE

#include "moc_qscriptdebuggerscriptswidget_p.cpp"
