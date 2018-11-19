#include "qscriptvalueproperty_p.h"

#include <QtCore/qshareddata.h>
#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE

class QScriptValuePropertyPrivate : public QSharedData
{
public:
    QScriptValuePropertyPrivate();
    ~QScriptValuePropertyPrivate();

    QString name;
    QScriptValue value;
    QScriptValue::PropertyFlags flags;
};

QScriptValuePropertyPrivate::QScriptValuePropertyPrivate()
{
}

QScriptValuePropertyPrivate::~QScriptValuePropertyPrivate()
{
}




QScriptValueProperty::QScriptValueProperty()
    : d_ptr(0)
{
}





QScriptValueProperty::QScriptValueProperty(const QString &name,
                                           const QScriptValue &value,
                                           QScriptValue::PropertyFlags flags)
    : d_ptr(new QScriptValuePropertyPrivate)
{
    d_ptr->name = name;
    d_ptr->value = value;
    d_ptr->flags = flags;
    d_ptr->ref.ref();
}




QScriptValueProperty::QScriptValueProperty(const QScriptValueProperty &other)
    : d_ptr(other.d_ptr.data())
{
    if (d_ptr)
        d_ptr->ref.ref();
}




QScriptValueProperty::~QScriptValueProperty()
{
}




QScriptValueProperty &QScriptValueProperty::operator=(const QScriptValueProperty &other)
{
    d_ptr.assign(other.d_ptr.data());
    return *this;
}




QString QScriptValueProperty::name() const
{
    Q_D(const QScriptValueProperty);
    if (!d)
        return QString();
    return d->name;
}




QScriptValue QScriptValueProperty::value() const
{
    Q_D(const QScriptValueProperty);
    if (!d)
        return QScriptValue();
    return d->value;
}




QScriptValue::PropertyFlags QScriptValueProperty::flags() const
{
    Q_D(const QScriptValueProperty);
    if (!d)
        return 0;
    return d->flags;
}





bool QScriptValueProperty::isValid() const
{
    Q_D(const QScriptValueProperty);
    return (d != 0);
}

QT_END_NAMESPACE
