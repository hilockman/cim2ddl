#ifndef QSCRIPTDEBUGGERSCRIPTSWIDGETINTERFACE_P_H
#define QSCRIPTDEBUGGERSCRIPTSWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerScriptsModel;

class QScriptDebuggerScriptsWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerScriptsWidgetInterface:
    public QWidget
{
    Q_OBJECT
public:
    ~QScriptDebuggerScriptsWidgetInterface();

    virtual QScriptDebuggerScriptsModel *scriptsModel() const = 0;
    virtual void setScriptsModel(QScriptDebuggerScriptsModel *model) = 0;

    virtual qint64 currentScriptId() const = 0;
    virtual void setCurrentScript(qint64 id) = 0;

Q_SIGNALS:
    void currentScriptChanged(qint64 scriptId);
    void scriptLocationSelected(int lineNumber);

protected:
    QScriptDebuggerScriptsWidgetInterface(
        QScriptDebuggerScriptsWidgetInterfacePrivate &dd,
        QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerScriptsWidgetInterface)
    Q_DISABLE_COPY(QScriptDebuggerScriptsWidgetInterface)
};

QT_END_NAMESPACE

#endif
