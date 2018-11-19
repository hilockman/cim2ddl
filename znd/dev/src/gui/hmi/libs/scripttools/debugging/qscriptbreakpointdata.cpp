#include "qscriptbreakpointdata_p.h"

#include <QtCore/qdatastream.h>
#include <QtCore/qstring.h>
#include <QtCore/qvariant.h>

QT_BEGIN_NAMESPACE
class QScriptBreakpointDataPrivate
{
public:
    QScriptBreakpointDataPrivate();
    ~QScriptBreakpointDataPrivate();

    void init(int ln);

    qint64 scriptId;
    QString fileName;
    int lineNumber;
    bool enabled;
    bool singleShot;
    int ignoreCount;
    QString condition;
    QVariant data;
    int hitCount;
};

QScriptBreakpointDataPrivate::QScriptBreakpointDataPrivate()
{
}

QScriptBreakpointDataPrivate::~QScriptBreakpointDataPrivate()
{
}

void QScriptBreakpointDataPrivate::init(int ln)
{
    scriptId = -1;
    lineNumber = ln;
    enabled = true;
    singleShot = false;
    ignoreCount = 0;
    hitCount = 0;
}




QScriptBreakpointData::QScriptBreakpointData()
    : d_ptr(new QScriptBreakpointDataPrivate)
{
    d_ptr->init( -1);
}



QScriptBreakpointData::QScriptBreakpointData(qint64 scriptId, int lineNumber)
    : d_ptr(new QScriptBreakpointDataPrivate)
{
    d_ptr->init(lineNumber);
    d_ptr->scriptId = scriptId;
}




QScriptBreakpointData::QScriptBreakpointData(const QString &fileName, int lineNumber)
    : d_ptr(new QScriptBreakpointDataPrivate)
{
    d_ptr->init(lineNumber);
    d_ptr->fileName = fileName;
}




QScriptBreakpointData::QScriptBreakpointData(const QScriptBreakpointData &other)
    : d_ptr(new QScriptBreakpointDataPrivate)
{
    Q_ASSERT(other.d_ptr != 0);
    *d_ptr = *other.d_ptr;
}




QScriptBreakpointData::~QScriptBreakpointData()
{
}




QScriptBreakpointData &QScriptBreakpointData::operator=(const QScriptBreakpointData &other)
{
    Q_ASSERT(d_ptr != 0);
    Q_ASSERT(other.d_ptr != 0);
    *d_ptr = *other.d_ptr;
    return *this;
}

qint64 QScriptBreakpointData::scriptId() const
{
    Q_D(const QScriptBreakpointData);
    return d->scriptId;
}

void QScriptBreakpointData::setScriptId(qint64 id)
{
    Q_D(QScriptBreakpointData);
    d->scriptId = id;
}

QString QScriptBreakpointData::fileName() const
{
    Q_D(const QScriptBreakpointData);
    return d->fileName;
}

void QScriptBreakpointData::setFileName(const QString &fileName)
{
    Q_D(QScriptBreakpointData);
    d->fileName = fileName;
}




int QScriptBreakpointData::lineNumber() const
{
    Q_D(const QScriptBreakpointData);
    return d->lineNumber;
}




void QScriptBreakpointData::setLineNumber(int lineNumber)
{
    Q_D(QScriptBreakpointData);
    d->lineNumber = lineNumber;
}




bool QScriptBreakpointData::isEnabled() const
{
    Q_D(const QScriptBreakpointData);
    return d->enabled;
}




void QScriptBreakpointData::setEnabled(bool enabled)
{
    Q_D(QScriptBreakpointData);
    d->enabled = enabled;
}




bool QScriptBreakpointData::isSingleShot() const
{
    Q_D(const QScriptBreakpointData);
    return d->singleShot;
}




void QScriptBreakpointData::setSingleShot(bool singleShot)
{
    Q_D(QScriptBreakpointData);
    d->singleShot = singleShot;
}




int QScriptBreakpointData::ignoreCount() const
{
    Q_D(const QScriptBreakpointData);
    return d->ignoreCount;
}




void QScriptBreakpointData::setIgnoreCount(int count)
{
    Q_D(QScriptBreakpointData);
    d->ignoreCount = count;
}






bool QScriptBreakpointData::hit()
{
    Q_D(QScriptBreakpointData);
    if (d->ignoreCount == 0) {
        ++d->hitCount;
        return true;
    }
    --d->ignoreCount;
    return false;
}





int QScriptBreakpointData::hitCount() const
{
    Q_D(const QScriptBreakpointData);
    return d->hitCount;
}




QString QScriptBreakpointData::condition() const
{
    Q_D(const QScriptBreakpointData);
    return d->condition;
}




void QScriptBreakpointData::setCondition(const QString &condition)
{
    Q_D(QScriptBreakpointData);
    d->condition = condition;
}




QVariant QScriptBreakpointData::data() const
{
    Q_D(const QScriptBreakpointData);
    return d->data;
}




void QScriptBreakpointData::setData(const QVariant &data)
{
    Q_D(QScriptBreakpointData);
    d->data = data;
}

bool QScriptBreakpointData::isValid() const
{
    Q_D(const QScriptBreakpointData);
    return (((d->scriptId != -1) || !d->fileName.isEmpty())
            && (d->lineNumber != -1));
}





bool QScriptBreakpointData::operator==(const QScriptBreakpointData &other) const
{
    Q_D(const QScriptBreakpointData);
    const QScriptBreakpointDataPrivate *od = other.d_func();
    if (d == od)
        return true;
    if (!d || !od)
        return false;
    return ((d->scriptId == od->scriptId)
            && (d->fileName == od->fileName)
            && (d->lineNumber == od->lineNumber)
            && (d->enabled == od->enabled)
            && (d->singleShot == od->singleShot)
            && (d->condition == od->condition)
            && (d->ignoreCount == od->ignoreCount)
            && (d->data == od->data)
            && (d->hitCount == od->hitCount));
}





bool QScriptBreakpointData::operator!=(const QScriptBreakpointData &other) const
{
    return !(*this == other);
}







QDataStream &operator<<(QDataStream &out, const QScriptBreakpointData &data)
{
    const QScriptBreakpointDataPrivate *d = data.d_ptr.data();
    out << d->scriptId;
    out << d->fileName;
    out << d->lineNumber;
    out << d->enabled;
    out << d->singleShot;
    out << d->ignoreCount;
    out << d->condition;
    out << d->data;
    out << d->hitCount;
    return out;
}
QDataStream &operator>>(QDataStream &in, QScriptBreakpointData &data)
{
    QScriptBreakpointDataPrivate *d = data.d_ptr.data();
    in >> d->scriptId;
    in >> d->fileName;
    in >> d->lineNumber;
    in >> d->enabled;
    in >> d->singleShot;
    in >> d->ignoreCount;
    in >> d->condition;
    in >> d->data;
    in >> d->hitCount;
    return in;
}

QT_END_NAMESPACE
