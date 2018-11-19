#ifndef QSCRIPTDEBUGGERCONSOLEWIDGETINTERFACE_P_H
#define QSCRIPTDEBUGGERCONSOLEWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

#include "qscriptmessagehandlerinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerConsoleHistorianInterface;
class QScriptCompletionProviderInterface;

class QScriptDebuggerConsoleWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleWidgetInterface:
    public QWidget,
    public QScriptMessageHandlerInterface
{
    Q_OBJECT
public:
    enum InputMode {
        NormalInputMode,
        PartialInputMode
    };

    ~QScriptDebuggerConsoleWidgetInterface();

    QScriptDebuggerConsoleHistorianInterface *commandHistorian() const;
    void setCommandHistorian(QScriptDebuggerConsoleHistorianInterface *historian);

    QScriptCompletionProviderInterface *completionProvider() const;
    void setCompletionProvider(QScriptCompletionProviderInterface *completionProvider);

    virtual void setLineContinuationMode(bool enabled) = 0;

    virtual void clear() = 0;

Q_SIGNALS:
    void lineEntered(const QString &contents);

protected:
    QScriptDebuggerConsoleWidgetInterface(QScriptDebuggerConsoleWidgetInterfacePrivate &dd,
                                          QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerConsoleWidgetInterface)
    Q_DISABLE_COPY(QScriptDebuggerConsoleWidgetInterface)
};

QT_END_NAMESPACE

#endif
