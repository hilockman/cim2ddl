#ifndef QSCRIPTDEBUGGERCODEFINDERWIDGETINTERFACE_P_H
#define QSCRIPTDEBUGGERCODEFINDERWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

#include <QtGui/qtextdocument.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCodeFinderWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCodeFinderWidgetInterface:
    public QWidget
{
    Q_OBJECT
public:
    ~QScriptDebuggerCodeFinderWidgetInterface();

    virtual int findOptions() const = 0;

    virtual QString text() const = 0;
    virtual void setText(const QString &text) = 0;

    virtual void setOK(bool ok) = 0;
    virtual void setWrapped(bool wrapped) = 0;

Q_SIGNALS:
    void findRequest(const QString &exp, int options);

protected:
    QScriptDebuggerCodeFinderWidgetInterface(
        QScriptDebuggerCodeFinderWidgetInterfacePrivate &dd,
        QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCodeFinderWidgetInterface)
    Q_DISABLE_COPY(QScriptDebuggerCodeFinderWidgetInterface)
};

QT_END_NAMESPACE

#endif
