#include "qscriptdebuggervalueproperty_p.h"
#include "qscriptdebuggervalue_p.h"
#include "qscriptdebuggerobjectsnapshotdelta_p.h"

#include <QtCore/qshareddata.h>
#include <QtCore/qdatastream.h>
#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE






class QScriptDebuggerValuePropertyPrivate : public QSharedData
{
public:
    QScriptDebuggerValuePropertyPrivate();
    ~QScriptDebuggerValuePropertyPrivate();

    QString name;
    QScriptDebuggerValue value;
    QString valueAsString;
    QScriptValue::PropertyFlags flags;
};

QScriptDebuggerValuePropertyPrivate::QScriptDebuggerValuePropertyPrivate()
{
}

QScriptDebuggerValuePropertyPrivate::~QScriptDebuggerValuePropertyPrivate()
{
}




QScriptDebuggerValueProperty::QScriptDebuggerValueProperty()
    : d_ptr(0)
{
}





QScriptDebuggerValueProperty::QScriptDebuggerValueProperty(const QString &name,
                                                           const QScriptDebuggerValue &value,
                                                           const QString &valueAsString,
                                                           QScriptValue::PropertyFlags flags)
    : d_ptr(new QScriptDebuggerValuePropertyPrivate)
{
    d_ptr->name = name;
    d_ptr->value = value;
    d_ptr->valueAsString = valueAsString;
    d_ptr->flags = flags;
    d_ptr->ref.ref();
}




QScriptDebuggerValueProperty::QScriptDebuggerValueProperty(const QScriptDebuggerValueProperty &other)
    : d_ptr(other.d_ptr.data())
{
    if (d_ptr)
        d_ptr->ref.ref();
}




QScriptDebuggerValueProperty::~QScriptDebuggerValueProperty()
{
}




QScriptDebuggerValueProperty &QScriptDebuggerValueProperty::operator=(const QScriptDebuggerValueProperty &other)
{
    d_ptr.assign(other.d_ptr.data());
    return *this;
}




QString QScriptDebuggerValueProperty::name() const
{
    Q_D(const QScriptDebuggerValueProperty);
    if (!d)
        return QString();
    return d->name;
}




QScriptDebuggerValue QScriptDebuggerValueProperty::value() const
{
    Q_D(const QScriptDebuggerValueProperty);
    if (!d)
        return QScriptDebuggerValue();
    return d->value;
}

QString QScriptDebuggerValueProperty::valueAsString() const
{
    Q_D(const QScriptDebuggerValueProperty);
    if (!d)
        return QString();
    return d->valueAsString;
}




QScriptValue::PropertyFlags QScriptDebuggerValueProperty::flags() const
{
    Q_D(const QScriptDebuggerValueProperty);
    if (!d)
        return 0;
    return d->flags;
}





bool QScriptDebuggerValueProperty::isValid() const
{
    Q_D(const QScriptDebuggerValueProperty);
    return (d != 0);
}







QDataStream &operator<<(QDataStream &out, const QScriptDebuggerValueProperty &property)
{
    out << property.name();
    out << property.value();
    out << property.valueAsString();
    out << (quint32)property.flags();
    return out;
}
QDataStream &operator>>(QDataStream &in, QScriptDebuggerValueProperty &property)
{
    QString name;
    QScriptDebuggerValue value;
    QString valueAsString;
    quint32 flags;
    in >> name;
    in >> value;
    in >> valueAsString;
    in >> flags;
    property = QScriptDebuggerValueProperty(
        name, value, valueAsString, QScriptValue::PropertyFlags(flags));
    return in;
}

QDataStream &operator<<(QDataStream &out, const QScriptDebuggerObjectSnapshotDelta &delta)
{
    out << delta.removedProperties;
    out << delta.changedProperties;
    out << delta.addedProperties;
    return out;
}

QDataStream &operator>>(QDataStream &in, QScriptDebuggerObjectSnapshotDelta &delta)
{
    in >> delta.removedProperties;
    in >> delta.changedProperties;
    in >> delta.addedProperties;
    return in;
}

QT_END_NAMESPACE
