#include "qscriptdebugoutputwidget_p.h"
#include "qscriptdebugoutputwidgetinterface_p_p.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qplaintextedit.h>
#include <QtWidgets/qscrollbar.h>

QT_BEGIN_NAMESPACE

namespace {

class QScriptDebugOutputWidgetOutputEdit : public QPlainTextEdit
{
public:
    QScriptDebugOutputWidgetOutputEdit(QWidget *parent = 0)
        : QPlainTextEdit(parent)
    {
        setReadOnly(true);

        setMaximumBlockCount(2500);
    }

    void scrollToBottom()
    {
        QScrollBar *bar = verticalScrollBar();
        bar->setValue(bar->maximum());
    }

    int charactersPerLine() const
    {
        QFontMetrics fm(font());
        return width() / fm.maxWidth();
    }
};

}

class QScriptDebugOutputWidgetPrivate
    : public QScriptDebugOutputWidgetInterfacePrivate
{
    Q_DECLARE_PUBLIC(QScriptDebugOutputWidget)
public:
    QScriptDebugOutputWidgetPrivate();
    ~QScriptDebugOutputWidgetPrivate();

    QScriptDebugOutputWidgetOutputEdit *outputEdit;
};

QScriptDebugOutputWidgetPrivate::QScriptDebugOutputWidgetPrivate()
{
}

QScriptDebugOutputWidgetPrivate::~QScriptDebugOutputWidgetPrivate()
{
}

QScriptDebugOutputWidget::QScriptDebugOutputWidget(QWidget *parent)
    : QScriptDebugOutputWidgetInterface(*new QScriptDebugOutputWidgetPrivate, parent, 0)
{
    Q_D(QScriptDebugOutputWidget);
    d->outputEdit = new QScriptDebugOutputWidgetOutputEdit();
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setMargin(0);
    vbox->setSpacing(0);
    vbox->addWidget(d->outputEdit);

#ifndef QT_NO_STYLE_STYLESHEET
    QString sheet = QString::fromLatin1("font-size: 14px; font-family: \"Monospace\";");
    setStyleSheet(sheet);
#endif
}

QScriptDebugOutputWidget::~QScriptDebugOutputWidget()
{
}

void QScriptDebugOutputWidget::message(
    QtMsgType type, const QString &text, const QString &fileName,
    int lineNumber, int columnNumber, const QVariant & )
{

    Q_D(QScriptDebugOutputWidget);
    QString msg;
    if (!fileName.isEmpty() || (lineNumber != -1)) {
        if (!fileName.isEmpty())
            msg.append(fileName);
        else
            msg.append(QLatin1String("<noname>"));
        if (lineNumber != -1) {
            msg.append(QLatin1Char(':'));
            msg.append(QString::number(lineNumber));
            if (columnNumber != -1) {
                msg.append(QLatin1Char(':'));
                msg.append(QString::number(columnNumber));
            }
        }
        msg.append(QLatin1String(": "));
    }
    msg.append(text);
    QTextCharFormat oldFmt = d->outputEdit->currentCharFormat();
    QTextCharFormat fmt(oldFmt);
    if (type == QtCriticalMsg) {
        fmt.setForeground(Qt::red);
        d->outputEdit->setCurrentCharFormat(fmt);
    }
    d->outputEdit->appendPlainText(msg);
    d->outputEdit->setCurrentCharFormat(oldFmt);
    d->outputEdit->scrollToBottom();
}

void QScriptDebugOutputWidget::clear()
{
    Q_D(QScriptDebugOutputWidget);
    d->outputEdit->clear();
}

QT_END_NAMESPACE
