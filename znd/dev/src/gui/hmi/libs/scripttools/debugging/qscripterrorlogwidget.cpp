#include "qscripterrorlogwidget_p.h"
#include "qscripterrorlogwidgetinterface_p_p.h"

#include <QtCore/qdatetime.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qtextedit.h>
#include <QtWidgets/qscrollbar.h>
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

namespace {

class QScriptErrorLogWidgetOutputEdit : public QTextEdit
{
public:
    QScriptErrorLogWidgetOutputEdit(QWidget *parent = 0)
        : QTextEdit(parent)
    {
        setReadOnly(true);

        document()->setMaximumBlockCount(255);
    }

    void scrollToBottom()
    {
        QScrollBar *bar = verticalScrollBar();
        bar->setValue(bar->maximum());
    }
};

}

class QScriptErrorLogWidgetPrivate
    : public QScriptErrorLogWidgetInterfacePrivate
{
    Q_DECLARE_PUBLIC(QScriptErrorLogWidget)
public:
    QScriptErrorLogWidgetPrivate();
    ~QScriptErrorLogWidgetPrivate();

    QScriptErrorLogWidgetOutputEdit *outputEdit;
};

QScriptErrorLogWidgetPrivate::QScriptErrorLogWidgetPrivate()
{
}

QScriptErrorLogWidgetPrivate::~QScriptErrorLogWidgetPrivate()
{
}

QScriptErrorLogWidget::QScriptErrorLogWidget(QWidget *parent)
    : QScriptErrorLogWidgetInterface(*new QScriptErrorLogWidgetPrivate, parent, 0)
{
    Q_D(QScriptErrorLogWidget);
    d->outputEdit = new QScriptErrorLogWidgetOutputEdit();
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setMargin(0);
    vbox->setSpacing(0);
    vbox->addWidget(d->outputEdit);



}

QScriptErrorLogWidget::~QScriptErrorLogWidget()
{
}

void QScriptErrorLogWidget::message(
    QtMsgType type, const QString &text, const QString &fileName,
    int lineNumber, int columnNumber, const QVariant & )
{

    Q_UNUSED(type);
    Q_UNUSED(fileName);
    Q_UNUSED(lineNumber);
    Q_UNUSED(columnNumber);
    Q_D(QScriptErrorLogWidget);
    QString html;
    html.append(QString::fromLatin1("<b>%0</b> %1<br>")
                .arg(QDateTime::currentDateTime().toString()).arg(text.toHtmlEscaped()));
    d->outputEdit->insertHtml(html);
    d->outputEdit->scrollToBottom();
}

void QScriptErrorLogWidget::clear()
{
    Q_D(QScriptErrorLogWidget);
    d->outputEdit->clear();
}

QT_END_NAMESPACE
