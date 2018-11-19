#ifndef QSCRIPTDEBUGGERLOCALSWIDGETINTERFACE_P_H
#define QSCRIPTDEBUGGERLOCALSWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerLocalsModel;
class QModelIndex;
class QScriptCompletionProviderInterface;

class QScriptDebuggerLocalsWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerLocalsWidgetInterface:
    public QWidget
{
    Q_OBJECT
public:
    ~QScriptDebuggerLocalsWidgetInterface();

    QScriptCompletionProviderInterface *completionProvider() const;
    void setCompletionProvider(QScriptCompletionProviderInterface *completionProvider);

    virtual QScriptDebuggerLocalsModel *localsModel() const = 0;
    virtual void setLocalsModel(QScriptDebuggerLocalsModel *model) = 0;

    virtual void expand(const QModelIndex &index) = 0;

protected:
    QScriptDebuggerLocalsWidgetInterface(
        QScriptDebuggerLocalsWidgetInterfacePrivate &dd,
        QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerLocalsWidgetInterface)
    Q_DISABLE_COPY(QScriptDebuggerLocalsWidgetInterface)
};

QT_END_NAMESPACE

#endif
