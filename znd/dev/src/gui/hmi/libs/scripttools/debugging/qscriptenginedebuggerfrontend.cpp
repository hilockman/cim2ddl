#include "qscriptenginedebuggerfrontend_p.h"
#include "qscriptdebuggerfrontend_p_p.h"
#include "qscriptdebuggerbackend_p.h"
#include "qscriptdebuggerbackend_p_p.h"
#include "qscriptdebuggerevent_p.h"
#include "qscriptdebuggercommandexecutor_p.h"
#include "qscriptdebuggerresponse_p.h"

#include <QtCore/qcoreapplication.h>
#include <QtCore/qeventloop.h>
#include <QtCore/qlist.h>
#include <QtScript/qscriptvalue.h>

QT_BEGIN_NAMESPACE
class QScriptDebuggerCommandEvent : public QEvent
{
public:
    QScriptDebuggerCommandEvent(int id, const QScriptDebuggerCommand &command)
        : QEvent(QEvent::Type(QEvent::User+3)), m_id(id), m_command(command) {}
    ~QScriptDebuggerCommandEvent() {}
    int id() const
        { return m_id; }
    const QScriptDebuggerCommand &command() const
        { return m_command; }
private:
    int m_id;
    QScriptDebuggerCommand m_command;
};

class QScriptDebuggerCommandFinishedEvent : public QEvent
{
public:
    QScriptDebuggerCommandFinishedEvent(int id, const QScriptDebuggerResponse &response)
        : QEvent(QEvent::Type(QEvent::User+4)), m_id(id), m_response(response) {}
    ~QScriptDebuggerCommandFinishedEvent() {}
    int id() const
        { return m_id; }
    const QScriptDebuggerResponse &response() const
        { return m_response; }
private:
    int m_id;
    QScriptDebuggerResponse m_response;
};

class QScriptEngineDebuggerBackendPrivate;
class QScriptEngineDebuggerBackend : public QScriptDebuggerBackend
{
public:
    QScriptEngineDebuggerBackend(QScriptEngineDebuggerFrontendPrivate *frontend);
    ~QScriptEngineDebuggerBackend();

    void processCommand(int id, const QScriptDebuggerCommand &command);
    void resume();

protected:
    void event(const QScriptDebuggerEvent &event);

private:
    Q_DECLARE_PRIVATE(QScriptEngineDebuggerBackend)
    Q_DISABLE_COPY(QScriptEngineDebuggerBackend)
};

class QScriptEngineDebuggerBackendPrivate
    : public QScriptDebuggerBackendPrivate
{
    Q_DECLARE_PUBLIC(QScriptEngineDebuggerBackend)
public:
    QScriptEngineDebuggerBackendPrivate();
    ~QScriptEngineDebuggerBackendPrivate();

    bool event(QEvent *e);

    QScriptEngineDebuggerFrontendPrivate *frontend;
    QList<QEventLoop*> eventLoopPool;
    QList<QEventLoop*> eventLoopStack;
};

class QScriptEngineDebuggerFrontendPrivate
    : public QScriptDebuggerFrontendPrivate
{
    Q_DECLARE_PUBLIC(QScriptEngineDebuggerFrontend)
public:
    QScriptEngineDebuggerFrontendPrivate();
    ~QScriptEngineDebuggerFrontendPrivate();

    void postCommandFinished(int id, const QScriptDebuggerResponse &response);
    bool event(QEvent *e);

    QScriptEngineDebuggerBackend *backend;
};

QScriptEngineDebuggerBackendPrivate::QScriptEngineDebuggerBackendPrivate()
{
    frontend = 0;
}

QScriptEngineDebuggerBackendPrivate::~QScriptEngineDebuggerBackendPrivate()
{
    eventLoopPool << eventLoopStack;
    eventLoopStack.clear();
    while (!eventLoopPool.isEmpty()) {
        QEventLoop *eventLoop = eventLoopPool.takeFirst();
        if (eventLoop->isRunning()) {
            eventLoop->quit();
            eventLoop->deleteLater();
        } else {
            delete eventLoop;
        }
    }
}




bool QScriptEngineDebuggerBackendPrivate::event(QEvent *e)
{
    Q_Q(QScriptEngineDebuggerBackend);
    if (e->type() == QEvent::User+3) {
        QScriptDebuggerCommandEvent *ce = static_cast<QScriptDebuggerCommandEvent*>(e);
        QScriptDebuggerCommandExecutor *executor = q->commandExecutor();
        QScriptDebuggerResponse response = executor->execute(q, ce->command());
        frontend->postCommandFinished(ce->id(), response);
        return true;
    }
    return QScriptDebuggerBackendPrivate::event(e);
}







QScriptEngineDebuggerBackend::QScriptEngineDebuggerBackend(
    QScriptEngineDebuggerFrontendPrivate *frontend)
    : QScriptDebuggerBackend(*new QScriptEngineDebuggerBackendPrivate)
{
    Q_D(QScriptEngineDebuggerBackend);
    d->frontend = frontend;
}

QScriptEngineDebuggerBackend::~QScriptEngineDebuggerBackend()
{
}

void QScriptEngineDebuggerBackend::processCommand(int id, const QScriptDebuggerCommand &command)
{
    Q_D(QScriptEngineDebuggerBackend);
    if (d->agent)
        d->postEvent(new QScriptDebuggerCommandEvent(id, command));
}




void QScriptEngineDebuggerBackend::event(const QScriptDebuggerEvent &event)
{
    Q_D(QScriptEngineDebuggerBackend);
    if (d->eventLoopPool.isEmpty())
        d->eventLoopPool.append(new QEventLoop());
    QEventLoop *eventLoop = d->eventLoopPool.takeFirst();
    Q_ASSERT(!eventLoop->isRunning());
    d->eventLoopStack.prepend(eventLoop);

    d->frontend->postEvent(new QScriptDebuggerEventEvent(event));




    eventLoop->exec();

    if (!d->eventLoopStack.isEmpty()) {

        d->eventLoopStack.takeFirst();
    }
    d->eventLoopPool.append(eventLoop);
    doPendingEvaluate( false);
}




void QScriptEngineDebuggerBackend::resume()
{
    Q_D(QScriptEngineDebuggerBackend);

    while (!d->eventLoopStack.isEmpty()) {
        QEventLoop *eventLoop = d->eventLoopStack.takeFirst();
        if (eventLoop->isRunning())
            eventLoop->quit();
    }
}

QScriptEngineDebuggerFrontendPrivate::QScriptEngineDebuggerFrontendPrivate()
{
    backend = 0;
}

QScriptEngineDebuggerFrontendPrivate::~QScriptEngineDebuggerFrontendPrivate()
{
    delete backend;
}

void QScriptEngineDebuggerFrontendPrivate::postCommandFinished(
    int id, const QScriptDebuggerResponse &response)
{
    postEvent(new QScriptDebuggerCommandFinishedEvent(id, response));
}




bool QScriptEngineDebuggerFrontendPrivate::event(QEvent *e)
{
    Q_Q(QScriptEngineDebuggerFrontend);
    if (e->type() == QEvent::User+4) {
        QScriptDebuggerCommandFinishedEvent *fe = static_cast<QScriptDebuggerCommandFinishedEvent*>(e);
        q->notifyCommandFinished(fe->id(), fe->response());
        return true;
    }
    return QScriptDebuggerFrontendPrivate::event(e);
}

QScriptEngineDebuggerFrontend::QScriptEngineDebuggerFrontend()
    : QScriptDebuggerFrontend(*new QScriptEngineDebuggerFrontendPrivate)
{
}

QScriptEngineDebuggerFrontend::~QScriptEngineDebuggerFrontend()
{
    detach();
}




void QScriptEngineDebuggerFrontend::attachTo(QScriptEngine *engine)
{
    Q_D(QScriptEngineDebuggerFrontend);
    if (d->backend)
        d->backend->detach();
    else
        d->backend = new QScriptEngineDebuggerBackend(d);
    d->backend->attachTo(engine);
}




void QScriptEngineDebuggerFrontend::detach()
{
    Q_D(QScriptEngineDebuggerFrontend);
    if (d->backend)
        d->backend->detach();
}

QScriptValue QScriptEngineDebuggerFrontend::traceFunction() const
{
    Q_D(const QScriptEngineDebuggerFrontend);
    if (d->backend)
        d->backend->traceFunction();
    return QScriptValue();
}

QScriptDebuggerBackend *QScriptEngineDebuggerFrontend::backend() const
{
    Q_D(const QScriptEngineDebuggerFrontend);
    return d->backend;
}




void QScriptEngineDebuggerFrontend::processCommand(int id, const QScriptDebuggerCommand &command)
{
    Q_D(QScriptEngineDebuggerFrontend);
    Q_ASSERT(d->backend != 0);
    d->backend->processCommand(id, command);
}

QT_END_NAMESPACE
