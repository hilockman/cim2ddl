#include "qscriptcompletiontaskinterface_p.h"
#include "qscriptcompletiontaskinterface_p_p.h"

#include "private/qobject_p.h"

QT_BEGIN_NAMESPACE

QScriptCompletionTaskInterfacePrivate::QScriptCompletionTaskInterfacePrivate()
{
    type = QScriptCompletionTaskInterface::NoCompletion;
}

QScriptCompletionTaskInterfacePrivate::~QScriptCompletionTaskInterfacePrivate()
{
}

QScriptCompletionTaskInterface::~QScriptCompletionTaskInterface()
{
}

QScriptCompletionTaskInterface::QScriptCompletionTaskInterface(
    QScriptCompletionTaskInterfacePrivate &dd, QObject *parent)
    : QObject(dd, parent)
{
}

QScriptCompletionTaskInterface::CompletionType QScriptCompletionTaskInterface::completionType() const
{
    Q_D(const QScriptCompletionTaskInterface);
    return static_cast<QScriptCompletionTaskInterface::CompletionType>(d->type);
}

int QScriptCompletionTaskInterface::resultCount() const
{
    Q_D(const QScriptCompletionTaskInterface);
    return d->results.size();
}

QString QScriptCompletionTaskInterface::resultAt(int index) const
{
    Q_D(const QScriptCompletionTaskInterface);
    return d->results.value(index);
}

void QScriptCompletionTaskInterface::addResult(const QString &result)
{
    Q_D(QScriptCompletionTaskInterface);
    d->results.append(result);
}

int QScriptCompletionTaskInterface::position() const
{
    Q_D(const QScriptCompletionTaskInterface);
    return d->position;
}

int QScriptCompletionTaskInterface::length() const
{
    Q_D(const QScriptCompletionTaskInterface);
    return d->length;
}

QString QScriptCompletionTaskInterface::appendix() const
{
    Q_D(const QScriptCompletionTaskInterface);
    return d->appendix;
}

QT_END_NAMESPACE
