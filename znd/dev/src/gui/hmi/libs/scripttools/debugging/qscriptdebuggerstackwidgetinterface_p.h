#ifndef QSCRIPTDEBUGGERSTACKWIDGETINTERFACE_P_H
#define QSCRIPTDEBUGGERSTACKWIDGETINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE

class QAbstractItemModel;

class QScriptDebuggerStackWidgetInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerStackWidgetInterface:
    public QWidget
{
    Q_OBJECT
public:
    ~QScriptDebuggerStackWidgetInterface();

    virtual QAbstractItemModel *stackModel() const = 0;
    virtual void setStackModel(QAbstractItemModel *model) = 0;

    virtual int currentFrameIndex() const = 0;
    virtual void setCurrentFrameIndex(int frameIndex) = 0;

Q_SIGNALS:
    void currentFrameChanged(int newFrameIndex);

protected:
    QScriptDebuggerStackWidgetInterface(
        QScriptDebuggerStackWidgetInterfacePrivate &dd,
        QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerStackWidgetInterface)
    Q_DISABLE_COPY(QScriptDebuggerStackWidgetInterface)
};

QT_END_NAMESPACE

#endif
