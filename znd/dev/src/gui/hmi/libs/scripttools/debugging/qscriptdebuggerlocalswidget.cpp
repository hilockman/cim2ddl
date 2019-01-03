#include "qscriptdebuggerlocalswidget_p.h"
#include "qscriptdebuggerlocalswidgetinterface_p_p.h"
#include "qscriptdebuggerlocalsmodel_p.h"
#include "qscriptcompletionproviderinterface_p.h"
#include "qscriptcompletiontaskinterface_p.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qheaderview.h>
#include <QtWidgets/qcompleter.h>
#include <QtCore/qstringlistmodel.h>
#include <QtWidgets/qtreeview.h>
#include <QtWidgets/qboxlayout.h>
#include <QtCore/qsortfilterproxymodel.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qstyleditemdelegate.h>
#include <QtGui/qevent.h>
#include <QtWidgets/qmessagebox.h>
#include <QtScript/qscriptengine.h>

QT_BEGIN_NAMESPACE

namespace {

class CustomProxyModel : public QSortFilterProxyModel
{
public:
    CustomProxyModel(QObject *parent = 0)
        : QSortFilterProxyModel(parent) {}

    bool hasChildren(const QModelIndex &parent) const
    {
        if (!sourceModel())
            return false;
        QModelIndex sourceParent = mapToSource(parent);
        if (parent.isValid() && !sourceParent.isValid())
            return false;
        return sourceModel()->hasChildren(sourceParent);
    }
};

}

class QScriptDebuggerLocalsWidgetPrivate
    : public QScriptDebuggerLocalsWidgetInterfacePrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerLocalsWidget)
public:
    QScriptDebuggerLocalsWidgetPrivate();
    ~QScriptDebuggerLocalsWidgetPrivate();

    void complete(QLineEdit *le);


    void _q_onCompletionTaskFinished();
    void _q_insertCompletion(const QString &text);
    void _q_expandIndex(const QModelIndex &index);

    QTreeView *view;
    QPointer<QLineEdit> completingEditor;
    QCompleter *completer;
    CustomProxyModel *proxy;
};

QScriptDebuggerLocalsWidgetPrivate::QScriptDebuggerLocalsWidgetPrivate()
{
    completingEditor = 0;
    completer = 0;
    proxy = 0;
}

QScriptDebuggerLocalsWidgetPrivate::~QScriptDebuggerLocalsWidgetPrivate()
{
}

void QScriptDebuggerLocalsWidgetPrivate::complete(QLineEdit *le)
{
    Q_Q(QScriptDebuggerLocalsWidget);
    QScriptCompletionTaskInterface *task = 0;

    task = completionProvider->createCompletionTask(
        le->text(), le->cursorPosition(),
        q->localsModel()->frameIndex(), 0);
    QObject::connect(task, SIGNAL(finished()),
                     q, SLOT(_q_onCompletionTaskFinished()));
    completingEditor = le;
    task->start();
}

void QScriptDebuggerLocalsWidgetPrivate::_q_onCompletionTaskFinished()
{
    Q_Q(QScriptDebuggerLocalsWidget);
    QScriptCompletionTaskInterface *task = 0;
    task = qobject_cast<QScriptCompletionTaskInterface*>(q_func()->sender());
    if (!completingEditor) {
        task->deleteLater();
        return;
    }

    if (task->resultCount() == 1) {

        QString completion = task->resultAt(0);
        completion.append(task->appendix());
        QString tmp = completingEditor->text();
        tmp.remove(task->position(), task->length());
        tmp.insert(task->position(), completion);
        completingEditor->setText(tmp);
        completingEditor = 0;
    } else if (task->resultCount() > 1) {

        if (!completer) {
            completer = new QCompleter(q);
            completer->setCompletionMode(QCompleter::PopupCompletion);
            completer->setCaseSensitivity(Qt::CaseSensitive);
            completer->setWrapAround(false);
            QObject::connect(completer, SIGNAL(activated(QString)),
                             q, SLOT(_q_insertCompletion(QString)));
        }
#ifndef QT_NO_STRINGLISTMODEL
        QStringListModel *model = qobject_cast<QStringListModel*>(completer->model());
        if (!model) {
            model = new QStringListModel(q);
            completer->setModel(model);
        }
        QStringList strings;
        for (int i = 0; i < task->resultCount(); ++i)
            strings.append(task->resultAt(i));
        model->setStringList(strings);
#endif
        QString prefix = completingEditor->text().mid(task->position(), task->length());
        completer->setCompletionPrefix(prefix);
        completingEditor->setCompleter(completer);

        QObject::disconnect(completer, 0, completingEditor, 0);
        completer->complete();
    }
    task->deleteLater();
}

void QScriptDebuggerLocalsWidgetPrivate::_q_insertCompletion(const QString &text)
{
    Q_ASSERT(completingEditor != 0);
    QString tmp = completingEditor->text();
    tmp.insert(completingEditor->cursorPosition(), text.mid(completer->completionPrefix().length()));
    completingEditor->setText(tmp);
    completingEditor = 0;
}

void QScriptDebuggerLocalsWidgetPrivate::_q_expandIndex(const QModelIndex &index)
{
    if (view->model() == index.model())
        view->expand(proxy->mapFromSource(index));
}

class QScriptDebuggerLocalsItemDelegate
    : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QScriptDebuggerLocalsItemDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    bool eventFilter(QObject *watched, QEvent *event);

private Q_SLOTS:
    void validateInput(const QString &text)
    {
        QWidget *editor = qobject_cast<QWidget*>(sender());
        QPalette pal = editor->palette();
        QColor col;
        bool ok = (QScriptEngine::checkSyntax(text).state() == QScriptSyntaxCheckResult::Valid);
        if (ok) {
            col = Qt::white;
        } else {
            QScriptSyntaxCheckResult result = QScriptEngine::checkSyntax(
                text + QLatin1Char('\n'));
            if (result.state() == QScriptSyntaxCheckResult::Intermediate)
                col = QColor(255, 240, 192);
            else
                col = QColor(255, 102, 102);
        }
        pal.setColor(QPalette::Active, QPalette::Base, col);
        editor->setPalette(pal);
    }

private:
    static const QWidget *widget(const QStyleOptionViewItem &option)
    {
        if (const QStyleOptionViewItemV3 *v3 = qstyleoption_cast<const QStyleOptionViewItemV3 *>(&option))
            return v3->widget;
        return 0;
    }
};

QScriptDebuggerLocalsItemDelegate::QScriptDebuggerLocalsItemDelegate(
    QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *QScriptDebuggerLocalsItemDelegate::createEditor(
    QWidget *parent, const QStyleOptionViewItem &option,
    const QModelIndex &index) const
{
    QWidget *editor = QStyledItemDelegate::createEditor(parent, option, index);
    if (index.column() == 1) {

        QLineEdit *le = qobject_cast<QLineEdit*>(editor);
        if (le) {
            QObject::connect(le, SIGNAL(textEdited(QString)),
                             this, SLOT(validateInput(QString)));
        }
    }
    return editor;
}

bool QScriptDebuggerLocalsItemDelegate::eventFilter(QObject *watched, QEvent *event)
{
    QLineEdit *le = qobject_cast<QLineEdit*>(watched);
    if (!le)
        return QStyledItemDelegate::eventFilter(watched, event);

    QScriptDebuggerLocalsWidget *localsWidget = qobject_cast<QScriptDebuggerLocalsWidget*>(parent());
    Q_ASSERT(localsWidget != 0);
    QScriptDebuggerLocalsWidgetPrivate *lvp =
        reinterpret_cast<QScriptDebuggerLocalsWidgetPrivate*>(
            QScriptDebuggerLocalsWidgetPrivate::get(localsWidget));

    if ((event->type() == QEvent::FocusIn) && lvp->completingEditor) {

        return true;
    }

    if (event->type() != QEvent::KeyPress)
        return QStyledItemDelegate::eventFilter(watched, event);
    QKeyEvent *ke = static_cast<QKeyEvent*>(event);
    if ((ke->key() == Qt::Key_Enter) || (ke->key() == Qt::Key_Return)) {
        if (QScriptEngine::checkSyntax(le->text()).state() != QScriptSyntaxCheckResult::Valid) {

            return true;
        }
    }
    if (ke->key() != Qt::Key_Tab)
        return QStyledItemDelegate::eventFilter(watched, event);


    lvp->complete(le);
    return true;
}

void QScriptDebuggerLocalsItemDelegate::setModelData(
    QWidget *editor, QAbstractItemModel *model,
    const QModelIndex &index) const
{
    if (index.column() == 1) {

        QString expression = qobject_cast<QLineEdit*>(editor)->text();
        if (QScriptEngine::checkSyntax(expression).state() != QScriptSyntaxCheckResult::Valid)
            return;
    }
    QStyledItemDelegate::setModelData(editor, model, index);
}

void QScriptDebuggerLocalsItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                                              const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
#if 0
    QModelIndex parent = index.parent();
    if (parent.isValid()) {
        QStyledItemDelegate::paint(painter, option, index);
    } else {

        const QTreeView *view = qobject_cast<const QTreeView*>(widget(option));
        Q_ASSERT(view != 0);

        QStyleOptionButton buttonOption;

        buttonOption.state = option.state;
#ifdef Q_WS_MAC
        buttonOption.state |= QStyle::State_Raised;
#endif
        buttonOption.state &= ~QStyle::State_HasFocus;

        buttonOption.rect = option.rect;
        buttonOption.palette = option.palette;
        buttonOption.features = QStyleOptionButton::None;
        view->style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter, view);

        QStyleOption branchOption;
        static const int i = 9;
        QRect r = option.rect;
        branchOption.rect = QRect(r.left() + i/2, r.top() + (r.height() - i)/2, i, i);
        branchOption.palette = option.palette;
        branchOption.state = QStyle::State_Children;

        if (view->isExpanded(index))
            branchOption.state |= QStyle::State_Open;

        view->style()->drawPrimitive(QStyle::PE_IndicatorBranch, &branchOption, painter, view);


        QRect textrect = QRect(r.left() + i*2, r.top(), r.width() - ((5*i)/2), r.height());
        QString text = elidedText(option.fontMetrics, textrect.width(), Qt::ElideMiddle,
            index.data(Qt::DisplayRole).toString());
        view->style()->drawItemText(painter, textrect, Qt::AlignCenter,
                                    option.palette, view->isEnabled(), text);
    }
#endif
}

QScriptDebuggerLocalsWidget::QScriptDebuggerLocalsWidget(QWidget *parent)
    : QScriptDebuggerLocalsWidgetInterface(*new QScriptDebuggerLocalsWidgetPrivate, parent, 0)
{
    Q_D(QScriptDebuggerLocalsWidget);
    d->view = new QTreeView();
    d->view->setItemDelegate(new QScriptDebuggerLocalsItemDelegate(this));
    d->view->setEditTriggers(QAbstractItemView::DoubleClicked);

    d->view->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    d->view->setAlternatingRowColors(true);
    d->view->setSelectionBehavior(QAbstractItemView::SelectRows);
    d->view->setSortingEnabled(true);
    d->view->header()->setDefaultAlignment(Qt::AlignLeft);



    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setMargin(0);
    vbox->addWidget(d->view);
}

QScriptDebuggerLocalsWidget::~QScriptDebuggerLocalsWidget()
{
}




QScriptDebuggerLocalsModel *QScriptDebuggerLocalsWidget::localsModel() const
{
    Q_D(const QScriptDebuggerLocalsWidget);
    if (!d->proxy)
        return 0;
    return qobject_cast<QScriptDebuggerLocalsModel*>(d->proxy->sourceModel());
}




void QScriptDebuggerLocalsWidget::setLocalsModel(QScriptDebuggerLocalsModel *model)
{
    Q_D(QScriptDebuggerLocalsWidget);
    if (localsModel()) {
        QObject::disconnect(localsModel(), 0, d->view, 0);
    }
    if (model) {
        QObject::connect(model, SIGNAL(scopeObjectAvailable(QModelIndex)),
                         this, SLOT(_q_expandIndex(QModelIndex)));
    }
    if (!d->proxy) {
        d->proxy = new CustomProxyModel(this);
        d->view->sortByColumn(0, Qt::AscendingOrder);
    }
    d->proxy->setSourceModel(model);
    d->view->setModel(d->proxy);
}




void QScriptDebuggerLocalsWidget::expand(const QModelIndex &index)
{
    Q_D(QScriptDebuggerLocalsWidget);
    d->view->expand(index);
    d->view->setFirstColumnSpanned(index.row(), QModelIndex(), true);
}

QT_END_NAMESPACE

#include "qscriptdebuggerlocalswidget.moc"

#include "moc_qscriptdebuggerlocalswidget_p.cpp"