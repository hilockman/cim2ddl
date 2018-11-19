#ifndef QSCRIPTDEBUGGERCODEVIEWINTERFACE_P_H
#define QSCRIPTDEBUGGERCODEVIEWINTERFACE_P_H 
#include <QtWidgets/qwidget.h>

QT_BEGIN_NAMESPACE

class QPoint;
class QStringList;

class QScriptDebuggerCodeViewInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCodeViewInterface:
    public QWidget
{
    Q_OBJECT
public:
    ~QScriptDebuggerCodeViewInterface();

    virtual QString text() const = 0;
    virtual void setText(const QString &text) = 0;

    virtual int cursorLineNumber() const = 0;
    virtual void gotoLine(int lineNumber) = 0;

    virtual int find(const QString &exp, int options = 0) = 0;

    virtual void setExecutionLineNumber(int lineNumber, bool error) = 0;
    virtual void setExecutableLineNumbers(const QSet<int> &lineNumbers) = 0;

    virtual int baseLineNumber() const = 0;
    virtual void setBaseLineNumber(int lineNumber) = 0;

    virtual void setBreakpoint(int lineNumber) = 0;
    virtual void deleteBreakpoint(int lineNumber) = 0;
    virtual void setBreakpointEnabled(int lineNumber, bool enable) = 0;

Q_SIGNALS:
    void breakpointToggleRequest(int lineNumber, bool on);
    void breakpointEnableRequest(int lineNumber, bool enable);
    void toolTipRequest(const QPoint &pos, int lineNumber, const QStringList &path);

protected:
    QScriptDebuggerCodeViewInterface(
        QScriptDebuggerCodeViewInterfacePrivate &dd,
        QWidget *parent, Qt::WindowFlags flags);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCodeViewInterface)
    Q_DISABLE_COPY(QScriptDebuggerCodeViewInterface)
};

QT_END_NAMESPACE

#endif
