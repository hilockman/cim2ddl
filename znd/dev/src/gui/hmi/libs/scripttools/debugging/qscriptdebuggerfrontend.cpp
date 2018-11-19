#include "qscriptdebuggerfrontend_p.h"
#include "qscriptdebuggerfrontend_p_p.h"
#include "qscriptdebuggercommand_p.h"
#include "qscriptdebuggerevent_p.h"
#include "qscriptdebuggerresponse_p.h"
#include "qscriptdebuggereventhandlerinterface_p.h"
#include "qscriptdebuggerresponsehandlerinterface_p.h"

#include <QtCore/qcoreevent.h>
#include <QtCore/qcoreapplication.h>

QT_BEGIN_NAMESPACE
class QScriptDebuggerFrontendEventReceiver : public QObject
{
public:
    QScriptDebuggerFrontendEventReceiver(QScriptDebuggerFrontendPrivate *frontend,
                                         QObject *parent = 0);
    ~QScriptDebuggerFrontendEventReceiver();

    bool event(QEvent *);

private:
    QScriptDebuggerFrontendPrivate *m_frontend;
};

QScriptDebuggerFrontendEventReceiver::QScriptDebuggerFrontendEventReceiver(
    QScriptDebuggerFrontendPrivate *frontend, QObject *parent)
    : QObject(parent), m_frontend(frontend)
{
}

QScriptDebuggerFrontendEventReceiver::~QScriptDebuggerFrontendEventReceiver()
{
}

bool QScriptDebuggerFrontendEventReceiver::event(QEvent *e)
{
    return m_frontend->event(e);
}


QScriptDebuggerFrontendPrivate::QScriptDebuggerFrontendPrivate()
{
    eventHandler = 0;
    nextCommandId = 0;
    eventReceiver = new QScriptDebuggerFrontendEventReceiver(this);
}

QScriptDebuggerFrontendPrivate::~QScriptDebuggerFrontendPrivate()
{
    delete eventReceiver;
}

void QScriptDebuggerFrontendPrivate::postEvent(QEvent *e)
{
    QCoreApplication::postEvent(eventReceiver, e);
}

bool QScriptDebuggerFrontendPrivate::event(QEvent *e)
{
    Q_Q(QScriptDebuggerFrontend);
    if (e->type() == QEvent::User+1) {
        QScriptDebuggerEventEvent *de = static_cast<QScriptDebuggerEventEvent*>(e);
        bool handled = q->notifyEvent(de->event());
        if (handled) {
            q->scheduleCommand(QScriptDebuggerCommand::resumeCommand(),
                                                   0);
        }
        return true;
    } else if (e->type() == QEvent::User+2) {
        processCommands();
        return true;
    }
    return false;
}

void QScriptDebuggerFrontendPrivate::processCommands()
{
    Q_Q(QScriptDebuggerFrontend);
    while (!pendingCommands.isEmpty()) {
        QScriptDebuggerCommand command(pendingCommands.takeFirst());
        int id = pendingCommandIds.takeFirst();
        q->processCommand(id, command);
    }
}

QScriptDebuggerFrontend::QScriptDebuggerFrontend()
    : d_ptr(new QScriptDebuggerFrontendPrivate())
{
    d_ptr->q_ptr = this;
}

QScriptDebuggerFrontend::~QScriptDebuggerFrontend()
{
}

QScriptDebuggerFrontend::QScriptDebuggerFrontend(QScriptDebuggerFrontendPrivate &dd)
    : d_ptr(&dd)
{
    d_ptr->q_ptr = this;
}

QScriptDebuggerEventHandlerInterface *QScriptDebuggerFrontend::eventHandler() const
{
    Q_D(const QScriptDebuggerFrontend);
    return d->eventHandler;
}

void QScriptDebuggerFrontend::setEventHandler(QScriptDebuggerEventHandlerInterface *eventHandler)
{
    Q_D(QScriptDebuggerFrontend);
    d->eventHandler = eventHandler;
}
int QScriptDebuggerFrontend::scheduleCommand(
    const QScriptDebuggerCommand &command,
    QScriptDebuggerResponseHandlerInterface *responseHandler)
{
    Q_D(QScriptDebuggerFrontend);
    int id = ++d->nextCommandId;
    d->pendingCommands.append(command);
    d->pendingCommandIds.append(id);
    if (responseHandler)
        d->responseHandlers.insert(id, responseHandler);
    if (d->pendingCommands.size() == 1) {
        QEvent *e = new QEvent(QEvent::Type(QEvent::User+2));
        d->postEvent(e);
    }
    return id;
}







void QScriptDebuggerFrontend::notifyCommandFinished(int id, const QScriptDebuggerResponse &response)
{
    Q_D(QScriptDebuggerFrontend);
    if (d->responseHandlers.contains(id)) {
        QScriptDebuggerResponseHandlerInterface *handler = d->responseHandlers.take(id);
        Q_ASSERT(handler != 0);
        handler->handleResponse(response, id);
    }
}







bool QScriptDebuggerFrontend::notifyEvent(const QScriptDebuggerEvent &event)
{
    Q_D(QScriptDebuggerFrontend);
    if (d->eventHandler)
        return d->eventHandler->debuggerEvent(event);
    return false;
}

int QScriptDebuggerFrontend::scheduledCommandCount() const
{
    Q_D(const QScriptDebuggerFrontend);
    return d->nextCommandId;
}
QT_END_NAMESPACE
