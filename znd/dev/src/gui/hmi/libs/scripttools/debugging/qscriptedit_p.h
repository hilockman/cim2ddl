#ifndef QSCRIPTEDIT_P_H
#define QSCRIPTEDIT_P_H 
#include <QtWidgets/qplaintextedit.h>
#include <QtCore/qhash.h>
#include <QtCore/qset.h>
#include <QtScript/qtscriptglobal.h>
QT_BEGIN_NAMESPACE

class QScriptEditExtraArea;

class Q_SCRIPTTOOLS_EXPORT QScriptEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    QScriptEdit(QWidget *parent = 0);
    ~QScriptEdit();

    int baseLineNumber() const;
    void setBaseLineNumber(int base);

    int executionLineNumber() const;
    void setExecutionLineNumber(int lineNumber, bool error);
    void setExecutableLineNumbers(const QSet<int> &lineNumbers);
    bool isExecutableLine(int lineNumber) const;

    int currentLineNumber() const;
    void gotoLine(int lineNumber);

    void setBreakpoint(int lineNumber);
    void setBreakpointEnabled(int lineNumber, bool enable);
    void deleteBreakpoint(int lineNumber);

    int extraAreaWidth() const;

signals:
    void breakpointToggleRequest(int lineNumber, bool on);
    void breakpointEnableRequest(int lineNumber, bool enable);

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

    void extraAreaPaintEvent(QPaintEvent *e);
    void extraAreaMouseEvent(QMouseEvent *e);
    bool extraAreaEvent(QEvent *e);

private slots:
    void updateExtraAreaWidth();
    void updateExtraArea(const QRect &, int);
    void highlightCurrentLine();

private:
    QTextEdit::ExtraSelection currentLineSelection() const;
    QTextEdit::ExtraSelection currentExecutionLineSelection() const;
    void updateExtraSelections();

private:
    QScriptEditExtraArea *m_extraArea;
    int m_baseLineNumber;
    int m_executionLineNumber;
    QSet<int> m_executableLineNumbers;
    bool m_executionLineNumberHasError;
    int m_extraAreaToggleBlockNumber;

    struct BreakpointData {
        BreakpointData() : enabled(true) {}
        bool enabled;
    };
    QHash<int, BreakpointData> m_breakpoints;

private:
    Q_DISABLE_COPY(QScriptEdit)
    friend class QScriptEditExtraArea;
};

QT_END_NAMESPACE

#endif
