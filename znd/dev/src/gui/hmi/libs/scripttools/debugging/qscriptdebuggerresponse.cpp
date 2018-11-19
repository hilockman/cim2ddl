#include "qscriptdebuggerresponse_p.h"
#include "qscriptdebuggervalue_p.h"

#include <QtScript/qscriptcontextinfo.h>
#include <QtCore/qdatastream.h>

Q_DECLARE_METATYPE(QScriptBreakpointData)
Q_DECLARE_METATYPE(QScriptBreakpointMap)
Q_DECLARE_METATYPE(QScriptScriptData)
Q_DECLARE_METATYPE(QScriptScriptMap)
Q_DECLARE_METATYPE(QScriptDebuggerValue)
Q_DECLARE_METATYPE(QScriptDebuggerValueList)
Q_DECLARE_METATYPE(QScriptDebuggerValueProperty)
Q_DECLARE_METATYPE(QScriptDebuggerValuePropertyList)
Q_DECLARE_METATYPE(QScriptContextInfo)

QT_BEGIN_NAMESPACE
class QScriptDebuggerResponsePrivate
{
public:
    QScriptDebuggerResponsePrivate();
    ~QScriptDebuggerResponsePrivate();

    QScriptDebuggerResponse::Error error;
    QVariant result;
    bool async;
};

QScriptDebuggerResponsePrivate::QScriptDebuggerResponsePrivate()
{
    error = QScriptDebuggerResponse::NoError;
    async = false;
}

QScriptDebuggerResponsePrivate::~QScriptDebuggerResponsePrivate()
{
}

QScriptDebuggerResponse::QScriptDebuggerResponse()
    : d_ptr(new QScriptDebuggerResponsePrivate)
{
}

QScriptDebuggerResponse::QScriptDebuggerResponse(const QScriptDebuggerResponse &other)
    : d_ptr(new QScriptDebuggerResponsePrivate)
{
    *d_ptr = *other.d_ptr;
}

QScriptDebuggerResponse::~QScriptDebuggerResponse()
{
}

QScriptDebuggerResponse &QScriptDebuggerResponse::operator=(const QScriptDebuggerResponse &other)
{
    *d_ptr = *other.d_ptr;
    return *this;
}




QScriptDebuggerResponse::Error QScriptDebuggerResponse::error() const
{
    Q_D(const QScriptDebuggerResponse);
    return d->error;
}




void QScriptDebuggerResponse::setError(Error error)
{
    Q_D(QScriptDebuggerResponse);
    d->error = error;
}





QVariant QScriptDebuggerResponse::result() const
{
    Q_D(const QScriptDebuggerResponse);
    return d->result;
}





void QScriptDebuggerResponse::setResult(const QVariant &value)
{
    Q_D(QScriptDebuggerResponse);
    d->result = value;
}

void QScriptDebuggerResponse::setResult(int value)
{
    Q_D(QScriptDebuggerResponse);
    d->result = value;
}

void QScriptDebuggerResponse::setResult(const QString &value)
{
    Q_D(QScriptDebuggerResponse);
    d->result = value;
}

void QScriptDebuggerResponse::setResult(const QScriptBreakpointData &data)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(data);
}

void QScriptDebuggerResponse::setResult(const QScriptBreakpointMap &breakpoints)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(breakpoints);
}

void QScriptDebuggerResponse::setResult(const QScriptScriptMap &scripts)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(scripts);
}

void QScriptDebuggerResponse::setResult(const QScriptScriptData &data)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(data);
}

void QScriptDebuggerResponse::setResult(const QScriptDebuggerValue &value)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(value);
}

void QScriptDebuggerResponse::setResult(const QScriptDebuggerValueList &values)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(values);
}

void QScriptDebuggerResponse::setResult(const QScriptDebuggerValuePropertyList &props)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(props);
}

void QScriptDebuggerResponse::setResult(const QScriptContextInfo &info)
{
    Q_D(QScriptDebuggerResponse);
    d->result = QVariant::fromValue(info);
}

int QScriptDebuggerResponse::resultAsInt() const
{
    Q_D(const QScriptDebuggerResponse);
    return d->result.toInt();
}

qint64 QScriptDebuggerResponse::resultAsLongLong() const
{
    Q_D(const QScriptDebuggerResponse);
    return d->result.toLongLong();
}

QString QScriptDebuggerResponse::resultAsString() const
{
    Q_D(const QScriptDebuggerResponse);
    return d->result.toString();
}

QScriptBreakpointData QScriptDebuggerResponse::resultAsBreakpointData() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptBreakpointData>(d->result);
}

QScriptBreakpointMap QScriptDebuggerResponse::resultAsBreakpoints() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptBreakpointMap>(d->result);
}

QScriptScriptMap QScriptDebuggerResponse::resultAsScripts() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptScriptMap>(d->result);
}

QScriptScriptData QScriptDebuggerResponse::resultAsScriptData() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptScriptData>(d->result);
}

QScriptDebuggerValue QScriptDebuggerResponse::resultAsScriptValue() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptDebuggerValue>(d->result);
}

QScriptDebuggerValueList QScriptDebuggerResponse::resultAsScriptValueList() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptDebuggerValueList>(d->result);
}

QScriptDebuggerValuePropertyList QScriptDebuggerResponse::resultAsScriptValuePropertyList() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptDebuggerValuePropertyList>(d->result);
}

QScriptContextInfo QScriptDebuggerResponse::resultAsContextInfo() const
{
    Q_D(const QScriptDebuggerResponse);
    return qvariant_cast<QScriptContextInfo>(d->result);
}

bool QScriptDebuggerResponse::async() const
{
    Q_D(const QScriptDebuggerResponse);
    return d->async;
}

void QScriptDebuggerResponse::setAsync(bool async)
{
    Q_D(QScriptDebuggerResponse);
    d->async = async;
}





bool QScriptDebuggerResponse::operator==(const QScriptDebuggerResponse &other) const
{
    Q_D(const QScriptDebuggerResponse);
    const QScriptDebuggerResponsePrivate *od = other.d_func();
    if (d == od)
        return true;
    if (!d || !od)
        return false;
    return ((d->error == od->error)
            && (d->result == od->result)
            && (d->async == od->async));
}





bool QScriptDebuggerResponse::operator!=(const QScriptDebuggerResponse &other) const
{
    return !(*this == other);
}







QDataStream &operator<<(QDataStream &out, const QScriptDebuggerResponse &response)
{
    const QScriptDebuggerResponsePrivate *d = response.d_ptr.data();
    out << (quint32)d->error;
    out << d->result;
    out << d->async;
    return out;
}
QDataStream &operator>>(QDataStream &in, QScriptDebuggerResponse &response)
{
    QScriptDebuggerResponsePrivate *d = response.d_ptr.data();

    quint32 error;
    in >> error;
    d->error = QScriptDebuggerResponse::Error(error);
    in >> d->result;
    in >> d->async;

    return in;
}

QT_END_NAMESPACE
