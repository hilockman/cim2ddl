#ifndef QSCRIPTDEBUGGERCODEVIEW_P_H
#define QSCRIPTDEBUGGERCODEVIEW_P_H 
#include "qscriptdebuggercodeviewinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerCodeViewPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerCodeView:
    public QScriptDebuggerCodeViewInterface
{
    Q_OBJECT
public:
    QScriptDebuggerCodeView(QWidget *parent = 0);
    ~QScriptDebuggerCodeView();

    QString text() const;
    void setText(const QString &text);

    int cursorLineNumber() const;
    void gotoLine(int lineNumber);

    int find(const QString &exp, int options = 0);

    void setExecutionLineNumber(int lineNumber, bool error);
    void setExecutableLineNumbers(const QSet<int> &lineNumbers);

    int baseLineNumber() const;
    void setBaseLineNumber(int lineNumber);

    void setBreakpoint(int lineNumber);
    void deleteBreakpoint(int lineNumber);
    void setBreakpointEnabled(int lineNumber, bool enable);

    bool event(QEvent *e);

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerCodeView)
    Q_DISABLE_COPY(QScriptDebuggerCodeView)
};

QT_END_NAMESPACE

#endif
