#ifndef QSCRIPTDEBUGGEREVENT_P_H
#define QSCRIPTDEBUGGEREVENT_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qhash.h>
#include <QtCore/qvariant.h>
#include <QtCore/qscopedpointer.h>

QT_BEGIN_NAMESPACE

class QDataStream;
class QScriptDebuggerValue;

class QScriptDebuggerEventPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerEvent
{
public:
    friend Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptDebuggerEvent &);
    friend Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptDebuggerEvent &);

    enum Type {
        None,
        Interrupted,
        SteppingFinished,
        LocationReached,
        Breakpoint,
        Exception,
        Trace,
        InlineEvalFinished,
        DebuggerInvocationRequest,
        ForcedReturn,
        UserEvent = 1000,
        MaxUserEvent = 32767
    };

    enum Attribute {
        ScriptID,
        FileName,
        BreakpointID,
        LineNumber,
        ColumnNumber,
        Value,
        Message,
        IsNestedEvaluate,
        HasExceptionHandler,
        UserAttribute = 1000,
        MaxUserAttribute = 32767
    };

    QScriptDebuggerEvent();
    QScriptDebuggerEvent(Type type);
    QScriptDebuggerEvent(Type type, qint64 scriptId, int lineNumber, int columnNumber);
    QScriptDebuggerEvent(const QScriptDebuggerEvent &other);
    ~QScriptDebuggerEvent();

    Type type() const;

    QVariant attribute(Attribute attribute,
                       const QVariant &defaultValue = QVariant()) const;
    void setAttribute(Attribute attribute, const QVariant &value);
    QHash<Attribute, QVariant> attributes() const;

    qint64 scriptId() const;
    void setScriptId(qint64 id);
    QString fileName() const;
    void setFileName(const QString &fileName);
    int lineNumber() const;
    void setLineNumber(int lineNumber);
    int columnNumber() const;
    void setColumnNumber(int columnNumber);
    int breakpointId() const;
    void setBreakpointId(int id);
    QString message() const;
    void setMessage(const QString &message);
    QScriptDebuggerValue scriptValue() const;
    void setScriptValue(const QScriptDebuggerValue &value);
    void setNestedEvaluate(bool nested);
    bool isNestedEvaluate() const;
    void setHasExceptionHandler(bool hasHandler);
    bool hasExceptionHandler() const;

    QScriptDebuggerEvent &operator=(const QScriptDebuggerEvent &other);

    bool operator==(const QScriptDebuggerEvent &other) const;
    bool operator!=(const QScriptDebuggerEvent &other) const;

private:
    QScopedPointer<QScriptDebuggerEventPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptDebuggerEvent)
};

Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptDebuggerEvent &);
Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptDebuggerEvent &);


class QScriptDebuggerEventEvent : public QEvent
{
public:
    QScriptDebuggerEventEvent(const QScriptDebuggerEvent &event)
        : QEvent(QEvent::Type(QEvent::User+1)), m_event(event) {}
    ~QScriptDebuggerEventEvent() {}
    const QScriptDebuggerEvent &event() const
        { return m_event; }
private:
    QScriptDebuggerEvent m_event;
};

QT_END_NAMESPACE

#endif
