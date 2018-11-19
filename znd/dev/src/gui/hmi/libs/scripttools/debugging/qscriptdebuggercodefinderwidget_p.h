#ifndef QSCRIPTDEBUGGERCODEFINDERWIDGET_P_H
#define QSCRIPTDEBUGGERCODEFINDERWIDGET_P_H 
#include "qscriptdebuggercodefinderwidgetinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerCodeFinderWidgetPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCodeFinderWidget:
    public QScriptDebuggerCodeFinderWidgetInterface
{
    Q_OBJECT
public:
    QScriptDebuggerCodeFinderWidget(QWidget *parent = 0);
    ~QScriptDebuggerCodeFinderWidget();

    int findOptions() const;

    QString text() const;
    void setText(const QString &text);

    void setOK(bool ok);
    void setWrapped(bool wrapped);

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCodeFinderWidget)
    Q_DISABLE_COPY(QScriptDebuggerCodeFinderWidget)

    Q_PRIVATE_SLOT(d_func(), void _q_updateButtons())
    Q_PRIVATE_SLOT(d_func(), void _q_onTextChanged(const QString &))
    Q_PRIVATE_SLOT(d_func(), void _q_next())
    Q_PRIVATE_SLOT(d_func(), void _q_previous())
};

QT_END_NAMESPACE

#endif
