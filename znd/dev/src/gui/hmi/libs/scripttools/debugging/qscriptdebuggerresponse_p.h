#ifndef QSCRIPTDEBUGGERRESPONSE_P_H
#define QSCRIPTDEBUGGERRESPONSE_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qmap.h>
#include <QtCore/qvariant.h>

#include "qscriptbreakpointdata_p.h"
#include "qscriptscriptdata_p.h"
#include "qscriptdebuggervalue_p.h"
#include "qscriptdebuggervalueproperty_p.h"

QT_BEGIN_NAMESPACE

class QDataStream;
class QScriptContextInfo;

class QScriptDebuggerResponsePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerResponse
{
public:
    friend Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptDebuggerResponse &);
    friend Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptDebuggerResponse &);

    enum Error {
        NoError,
        InvalidContextIndex,
        InvalidArgumentIndex,
        InvalidScriptID,
        InvalidBreakpointID,
        UserError = 1000,
        MaxUserError = 32767
    };

    QScriptDebuggerResponse();
    QScriptDebuggerResponse(const QScriptDebuggerResponse &other);
    ~QScriptDebuggerResponse();

    Error error() const;
    void setError(Error error);

    QVariant result() const;
    void setResult(const QVariant &value);

    void setResult(int value);
    void setResult(const QString &value);
    void setResult(const QScriptBreakpointData &data);
    void setResult(const QScriptBreakpointMap &breakpoints);
    void setResult(const QScriptScriptMap &scripts);
    void setResult(const QScriptScriptData &data);
    void setResult(const QScriptDebuggerValue &value);
    void setResult(const QScriptDebuggerValueList &value);
    void setResult(const QScriptDebuggerValuePropertyList &props);
    void setResult(const QScriptContextInfo &info);

    int resultAsInt() const;
    qint64 resultAsLongLong() const;
    QString resultAsString() const;
    QScriptBreakpointData resultAsBreakpointData() const;
    QScriptBreakpointMap resultAsBreakpoints() const;
    QScriptScriptMap resultAsScripts() const;
    QScriptScriptData resultAsScriptData() const;
    QScriptDebuggerValue resultAsScriptValue() const;
    QScriptDebuggerValueList resultAsScriptValueList() const;
    QScriptDebuggerValuePropertyList resultAsScriptValuePropertyList() const;
    QScriptContextInfo resultAsContextInfo() const;

    bool async() const;
    void setAsync(bool async);

    QScriptDebuggerResponse &operator=(const QScriptDebuggerResponse &other);

    bool operator==(const QScriptDebuggerResponse &other) const;
    bool operator!=(const QScriptDebuggerResponse &other) const;

private:
    QScopedPointer<QScriptDebuggerResponsePrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptDebuggerResponse)
};

Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptDebuggerResponse &);
Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptDebuggerResponse &);

QT_END_NAMESPACE

#endif
