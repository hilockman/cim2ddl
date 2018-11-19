#include "qscriptdebuggerbackend_p.h"
#include "qscriptdebuggerbackend_p_p.h"
#include "qscriptdebuggeragent_p.h"
#include "qscriptdebuggercommandexecutor_p.h"
#include "qscriptdebuggerevent_p.h"
#include "qscriptdebuggervalue_p.h"
#include "qscriptscriptdata_p.h"
#include "qscriptbreakpointdata_p.h"
#include "qscriptobjectsnapshot_p.h"

#include <QtScript/qscriptengine.h>
#include <QtScript/qscriptcontextinfo.h>
#include <QtScript/qscriptvalueiterator.h>

#include <QtCore/qcoreapplication.h>
#include <QtCore/qdebug.h>

Q_DECLARE_METATYPE(QScriptDebuggerValue)
Q_DECLARE_METATYPE(QScriptDebuggerBackendPrivate*)

QT_BEGIN_NAMESPACE
class QScriptDebuggerBackendEventReceiver : public QObject
{
public:
    QScriptDebuggerBackendEventReceiver(QScriptDebuggerBackendPrivate *backend,
                                        QObject *parent = 0)
        : QObject(parent), m_backend(backend) {}
    ~QScriptDebuggerBackendEventReceiver() {}

    bool event(QEvent *e)
    {
        return m_backend->event(e);
    }

private:
    QScriptDebuggerBackendPrivate *m_backend;
};


QScriptDebuggerBackendPrivate::QScriptDebuggerBackendPrivate()
    : agent(0), commandExecutor(0),
        pendingEvaluateContextIndex(-1), pendingEvaluateLineNumber(-1),
        ignoreExceptions(false),
        nextScriptValueIteratorId(0), nextScriptObjectSnapshotId(0),
        eventReceiver(0),
        q_ptr(0)
{
}

QScriptDebuggerBackendPrivate::~QScriptDebuggerBackendPrivate()
{
    if (agent)
        agent->nullifyBackendPointer();
    delete commandExecutor;
    delete eventReceiver;
    qDeleteAll(scriptValueIterators);
    qDeleteAll(scriptObjectSnapshots);
}

void QScriptDebuggerBackendPrivate::postEvent(QEvent *e)
{
    if (!eventReceiver) {
        eventReceiver = new QScriptDebuggerBackendEventReceiver(this);
        Q_ASSERT(agent != 0);
        eventReceiver->moveToThread(agent->engine()->thread());
    }
    QCoreApplication::postEvent(eventReceiver, e);
}

bool QScriptDebuggerBackendPrivate::event(QEvent *e)
{
    if (e->type() == QEvent::User+1) {
        QScriptDebuggerEventEvent *de = static_cast<QScriptDebuggerEventEvent*>(e);
        q_func()->event(de->event());
        return true;
    }
    return false;
}

void QScriptDebuggerBackendPrivate::agentDestroyed(QScriptDebuggerAgent *ag)
{



    if (agent == ag)
        agent = 0;
}





void QScriptDebuggerBackendPrivate::stepped(qint64 scriptId,
                                            int lineNumber,
                                            int columnNumber,
                                            const QScriptValue &result)
{
    Q_Q(QScriptDebuggerBackend);
    QScriptDebuggerEvent e(QScriptDebuggerEvent::SteppingFinished,
                           scriptId, lineNumber, columnNumber);
    e.setFileName(agent->scriptData(scriptId).fileName());
    QScriptDebuggerValue value(result);
    e.setScriptValue(value);
    if (!result.isUndefined())
        e.setMessage(result.toString());
    q->event(e);
}





void QScriptDebuggerBackendPrivate::locationReached(qint64 scriptId,
                                                    int lineNumber,
                                                    int columnNumber)
{
    Q_Q(QScriptDebuggerBackend);
    QScriptDebuggerEvent e(QScriptDebuggerEvent::LocationReached,
                           scriptId, lineNumber, columnNumber);
    e.setFileName(agent->scriptData(scriptId).fileName());
    q->event(e);
}




void QScriptDebuggerBackendPrivate::interrupted(qint64 scriptId,
                                                int lineNumber,
                                                int columnNumber)
{
    Q_Q(QScriptDebuggerBackend);
    QScriptDebuggerEvent e(QScriptDebuggerEvent::Interrupted,
                           scriptId, lineNumber, columnNumber);
    e.setFileName(agent->scriptData(scriptId).fileName());
    q->event(e);
}




void QScriptDebuggerBackendPrivate::breakpoint(qint64 scriptId,
                                               int lineNumber,
                                               int columnNumber,
                                               int breakpointId)
{
    Q_Q(QScriptDebuggerBackend);
    QScriptDebuggerEvent e(QScriptDebuggerEvent::Breakpoint,
                           scriptId, lineNumber, columnNumber);
    e.setFileName(agent->scriptData(scriptId).fileName());
    e.setBreakpointId(breakpointId);
    q->event(e);
}





void QScriptDebuggerBackendPrivate::exception(qint64 scriptId,
                                              const QScriptValue &exception,
                                              bool hasHandler)
{
    Q_Q(QScriptDebuggerBackend);
    if (ignoreExceptions) {

        return;
    }
    QScriptDebuggerEvent e(QScriptDebuggerEvent::Exception);
    e.setScriptId(scriptId);
    e.setFileName(agent->scriptData(scriptId).fileName());
    e.setMessage(exception.toString());
    e.setHasExceptionHandler(hasHandler);
    int lineNumber = -1;
    QString fileName;
    if (exception.property(QLatin1String("lineNumber")).isNumber())
        lineNumber = exception.property(QLatin1String("lineNumber")).toInt32();
    if (exception.property(QLatin1String("fileName")).isString())
        fileName = exception.property(QLatin1String("fileName")).toString();
    if (lineNumber == -1) {
        QScriptContextInfo info(q->engine()->currentContext());
        lineNumber = info.lineNumber();
        fileName = info.fileName();
    }
    if (lineNumber != -1)
        e.setLineNumber(lineNumber);
    if (!fileName.isEmpty())
        e.setFileName(fileName);
    QScriptDebuggerValue value(exception);
    e.setScriptValue(value);
    q->event(e);
}

QScriptValue QScriptDebuggerBackendPrivate::trace(QScriptContext *context,
                                                  QScriptEngine *engine)
{
    QScriptValue data = context->callee().data();
    QScriptDebuggerBackendPrivate *self = qscriptvalue_cast<QScriptDebuggerBackendPrivate*>(data);
    if (!self)
        return engine->undefinedValue();
    QString str;
    for (int i = 0; i < context->argumentCount(); ++i) {
        if (i > 0)
            str.append(QLatin1Char(' '));
        str.append(context->argument(i).toString());
    }
    QScriptDebuggerEvent e(QScriptDebuggerEvent::Trace);
    e.setMessage(str);
    self->q_func()->event(e);
    return engine->undefinedValue();
}

QScriptValue QScriptDebuggerBackendPrivate::qsassert(QScriptContext *context,
                                                     QScriptEngine *engine)
{
    QScriptValue arg = context->argument(0);
    if (arg.toBoolean())
        return arg;
    QScriptContextInfo info(context->parentContext());
    QString msg;
    QString fileName = info.fileName();
    if (fileName.isEmpty())
        fileName = QString::fromLatin1("<anonymous script, id=%0>").arg(info.scriptId());
    msg.append(fileName);
    msg.append(QLatin1Char(':'));
    msg.append(QString::number(info.lineNumber()));
    msg.append(QString::fromLatin1(": Assertion failed"));
    for (int i = 1; i < context->argumentCount(); ++i) {
        if (i == 1)
            msg.append(QLatin1Char(':'));
        msg.append(QLatin1Char(' '));
        msg.append(context->argument(i).toString());
    }
    QScriptValue err = context->throwError(msg);
    err.setProperty(QString::fromLatin1("name"), QScriptValue(engine, QString::fromLatin1("AssertionError")));
    return err;
}

QScriptValue QScriptDebuggerBackendPrivate::fileName(QScriptContext *context,
                                                     QScriptEngine *engine)
{
    QScriptContextInfo info(context->parentContext());
    QString fn = info.fileName();
    if (fn.isEmpty())
        return engine->undefinedValue();
    return QScriptValue(engine, fn);
}

QScriptValue QScriptDebuggerBackendPrivate::lineNumber(QScriptContext *context,
                                                       QScriptEngine *engine)
{
    QScriptContextInfo info(context->parentContext());
    return QScriptValue(engine, info.lineNumber());
}





void QScriptDebuggerBackendPrivate::debuggerInvocationRequest(
    qint64 scriptId, int lineNumber, int columnNumber)
{
    Q_Q(QScriptDebuggerBackend);
    QScriptDebuggerEvent e(QScriptDebuggerEvent::DebuggerInvocationRequest,
                           scriptId, lineNumber, columnNumber);
    e.setFileName(agent->scriptData(scriptId).fileName());
    q->event(e);
}

void QScriptDebuggerBackendPrivate::forcedReturn(
    qint64 scriptId, int lineNumber, int columnNumber,
    const QScriptValue &value)
{
    Q_Q(QScriptDebuggerBackend);
    QScriptDebuggerEvent e(QScriptDebuggerEvent::ForcedReturn,
                           scriptId, lineNumber, columnNumber);
    e.setFileName(agent->scriptData(scriptId).fileName());
    e.setScriptValue(QScriptDebuggerValue(value));
    q->event(e);
}




QScriptDebuggerBackend::QScriptDebuggerBackend()
    : d_ptr(new QScriptDebuggerBackendPrivate)
{
    d_ptr->q_ptr = this;
}




QScriptDebuggerBackend::~QScriptDebuggerBackend()
{
    detach();
}




QScriptDebuggerBackend::QScriptDebuggerBackend(QScriptDebuggerBackendPrivate &dd)
    : d_ptr(&dd)
{
    d_ptr->q_ptr = this;
}
void QScriptDebuggerBackend::attachTo(QScriptEngine *engine)
{
    Q_D(QScriptDebuggerBackend);
    detach();
    d->agent = new QScriptDebuggerAgent(d, engine);
    QScriptValue global = engine->globalObject();
    d->origTraceFunction = global.property(QString::fromLatin1("print"));
    global.setProperty(QString::fromLatin1("print"), traceFunction());

    d->origFileNameFunction = global.property(QString::fromLatin1("__FILE__"));
    global.setProperty(QString::fromLatin1("__FILE__"), fileNameFunction(),
                       QScriptValue::PropertyGetter | QScriptValue::ReadOnly);
    d->origLineNumberFunction = global.property(QString::fromLatin1("__LINE__"));
    global.setProperty(QString::fromLatin1("__LINE__"), lineNumberFunction(),
                       QScriptValue::PropertyGetter | QScriptValue::ReadOnly);
    engine->setAgent(d->agent);
}
void QScriptDebuggerBackend::detach()
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        QScriptEngine *eng = d->agent->engine();
        if (eng && eng->agent() == d->agent) {
            eng->setAgent(0);
            QScriptValue global = eng->globalObject();
            global.setProperty(QString::fromLatin1("print"), d->origTraceFunction);
            d->origTraceFunction = QScriptValue();

            global.setProperty(QString::fromLatin1("__FILE__"), QScriptValue(),
                               QScriptValue::PropertyGetter);
            global.setProperty(QString::fromLatin1("__FILE__"), d->origFileNameFunction);
            d->origFileNameFunction = QScriptValue();
            global.setProperty(QString::fromLatin1("__LINE__"), QScriptValue(),
                               QScriptValue::PropertyGetter);
            global.setProperty(QString::fromLatin1("__LINE__"), d->origLineNumberFunction);
            d->origLineNumberFunction = QScriptValue();
            d->agent->nullifyBackendPointer();
            d->agent = 0;
        }
    }

    d->pendingEvaluateLineNumber = -1;
    d->ignoreExceptions = false;
    d->nextScriptValueIteratorId = 0;
    qDeleteAll(d->scriptValueIterators);
    d->scriptValueIterators.clear();
    qDeleteAll(d->scriptObjectSnapshots);
    d->scriptObjectSnapshots.clear();
}







QScriptEngine *QScriptDebuggerBackend::engine() const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return 0;
    return d->agent->engine();
}





void QScriptDebuggerBackend::stepInto(int count)
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        d->agent->enterStepIntoMode(count);
        resume();
    }
}





void QScriptDebuggerBackend::stepOver(int count)
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        d->agent->enterStepOverMode(count);
        resume();
    }
}





void QScriptDebuggerBackend::stepOut()
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        d->agent->enterStepOutMode();
        resume();
    }
}







void QScriptDebuggerBackend::continueEvalution()
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        d->agent->enterContinueMode();
        resume();
    }
}





void QScriptDebuggerBackend::interruptEvaluation()
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent)
        d->agent->enterInterruptMode();
}






void QScriptDebuggerBackend::runToLocation(const QString &fileName, int lineNumber)
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        d->agent->enterRunToLocationMode(fileName, lineNumber);
        resume();
    }
}






void QScriptDebuggerBackend::runToLocation(qint64 scriptId, int lineNumber)
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        d->agent->enterRunToLocationMode(scriptId, lineNumber);
        resume();
    }
}

void QScriptDebuggerBackend::returnToCaller(int contextIndex, const QScriptValue &value)
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent) {
        d->agent->enterReturnByForceMode(contextIndex, value);
        resume();
    }
}





void QScriptDebuggerBackend::evaluate(int contextIndex, const QString &program,
                                      const QString &fileName, int lineNumber)
{
    Q_D(QScriptDebuggerBackend);
    d->pendingEvaluateContextIndex = contextIndex;
    d->pendingEvaluateProgram = program;
    d->pendingEvaluateFileName = fileName;
    d->pendingEvaluateLineNumber = lineNumber;
    if (!engine()->isEvaluating())
        doPendingEvaluate( true);
    else
        resume();
}




void QScriptDebuggerBackend::doPendingEvaluate(bool postEvent)
{
    Q_D(QScriptDebuggerBackend);
    QString program = d->pendingEvaluateProgram;
    if (program.isEmpty())
        return;
    int contextIndex = d->pendingEvaluateContextIndex;
    QScriptContext *ctx = context(contextIndex);
    Q_ASSERT(ctx != 0);
    QString fileName = d->pendingEvaluateFileName;
    int lineNumber = d->pendingEvaluateLineNumber;
    d->pendingEvaluateProgram = QString();
    d->pendingEvaluateFileName = QString();
    d->pendingEvaluateLineNumber = -1;
    d->pendingEvaluateContextIndex = -1;


    {
        QScriptContext *evalContext = engine()->pushContext();
        QScriptValueList scopeChain = ctx->scopeChain();
        if (scopeChain.isEmpty())
            scopeChain.append(engine()->globalObject());
        while (!scopeChain.isEmpty())
            evalContext->pushScope(scopeChain.takeLast());
        evalContext->setActivationObject(ctx->activationObject());
        evalContext->setThisObject(ctx->thisObject());
    }

    d->agent->enterContinueMode();


    d->ignoreExceptions = true;
    bool hadException = engine()->hasUncaughtException();
    QScriptValue ret = engine()->evaluate(program, fileName, lineNumber);
    d->ignoreExceptions = false;
    if (!hadException && engine()->hasUncaughtException())
        engine()->clearExceptions();
    engine()->popContext();

    QScriptDebuggerValue retret(ret);
    QScriptDebuggerEvent e(QScriptDebuggerEvent::InlineEvalFinished);
    e.setScriptValue(retret);
    if (!ret.isUndefined())
        e.setMessage(ret.toString());

    e.setNestedEvaluate(engine()->isEvaluating());

    if (postEvent) {
        QScriptDebuggerEventEvent *de = new QScriptDebuggerEventEvent(e);
        d->postEvent(de);
    } else {
        event(e);
    }
}
int QScriptDebuggerBackend::setBreakpoint(const QScriptBreakpointData &data)
{
    Q_D(QScriptDebuggerBackend);
    if (!d->agent)
        return -1;
    if (!data.isValid())
        return -1;
    return d->agent->setBreakpoint(data);
}
bool QScriptDebuggerBackend::deleteBreakpoint(int id)
{
    Q_D(QScriptDebuggerBackend);
    if (!d->agent)
        return false;
    return d->agent->deleteBreakpoint(id);
}




void QScriptDebuggerBackend::deleteAllBreakpoints()
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent)
        d->agent->deleteAllBreakpoints();
}





QScriptBreakpointData QScriptDebuggerBackend::breakpointData(int id) const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return QScriptBreakpointData();
    return d->agent->breakpointData(id);
}





bool QScriptDebuggerBackend::setBreakpointData(int id, const QScriptBreakpointData &data)
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent)
        return d->agent->setBreakpointData(id, data);
    return false;
}






QScriptBreakpointMap QScriptDebuggerBackend::breakpoints() const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return QScriptBreakpointMap();
    return d->agent->breakpoints();
}






QScriptScriptMap QScriptDebuggerBackend::scripts() const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return QScriptScriptMap();
    return d->agent->scripts();
}






QScriptScriptData QScriptDebuggerBackend::scriptData(qint64 id) const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return QScriptScriptData();
    return d->agent->scriptData(id);
}






void QScriptDebuggerBackend::scriptsCheckpoint()
{
    Q_D(QScriptDebuggerBackend);
    if (d->agent)
        d->agent->scriptsCheckpoint();
}
QScriptScriptsDelta QScriptDebuggerBackend::scriptsDelta() const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return QPair<QList<qint64>, QList<qint64> >();
    return d->agent->scriptsDelta();
}

qint64 QScriptDebuggerBackend::resolveScript(const QString &fileName) const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return -1;
    return d->agent->resolveScript(fileName);
}




int QScriptDebuggerBackend::contextCount() const
{
    if (!engine())
        return 0;
    return contextIds().count();
}




QScriptContext *QScriptDebuggerBackend::context(int index) const
{
    if (index < 0)
        return 0;
    QScriptContext *ctx = engine()->currentContext();
    while (ctx) {
        if (index == 0)
            return ctx;
        ctx = ctx->parentContext();
        --index;
    }
    return 0;
}




QStringList QScriptDebuggerBackend::backtrace() const
{
    if (!engine())
        return QStringList();
    return engine()->currentContext()->backtrace();
}

QList<qint64> QScriptDebuggerBackend::contextIds() const
{
    Q_D(const QScriptDebuggerBackend);
    if (!d->agent)
        return QList<qint64>();
    return d->agent->contextIds();
}

QScriptContextsDelta QScriptDebuggerBackend::contextsCheckpoint()
{
    Q_D(QScriptDebuggerBackend);
    if (!d->agent)
        return QScriptContextsDelta();
    return d->agent->contextsCheckpoint();
}

int QScriptDebuggerBackend::newScriptObjectSnapshot()
{
    Q_D(QScriptDebuggerBackend);
    int id = d->nextScriptObjectSnapshotId;
    ++d->nextScriptObjectSnapshotId;
    d->scriptObjectSnapshots[id] = new QScriptObjectSnapshot();
    return id;
}

QScriptObjectSnapshot *QScriptDebuggerBackend::scriptObjectSnapshot(int id) const
{
    Q_D(const QScriptDebuggerBackend);
    return d->scriptObjectSnapshots.value(id);
}

void QScriptDebuggerBackend::deleteScriptObjectSnapshot(int id)
{
    Q_D(QScriptDebuggerBackend);
    QScriptObjectSnapshot *snap = d->scriptObjectSnapshots.take(id);
    delete snap;
}

int QScriptDebuggerBackend::newScriptValueIterator(const QScriptValue &object)
{
    Q_D(QScriptDebuggerBackend);
    int id = d->nextScriptValueIteratorId;
    ++d->nextScriptValueIteratorId;
    d->scriptValueIterators[id] = new QScriptValueIterator(object);
    return id;
}

QScriptValueIterator *QScriptDebuggerBackend::scriptValueIterator(int id) const
{
    Q_D(const QScriptDebuggerBackend);
    return d->scriptValueIterators.value(id);
}

void QScriptDebuggerBackend::deleteScriptValueIterator(int id)
{
    Q_D(QScriptDebuggerBackend);
    QScriptValueIterator *it = d->scriptValueIterators.take(id);
    delete it;
}

bool QScriptDebuggerBackend::ignoreExceptions() const
{
    Q_D(const QScriptDebuggerBackend);
    return d->ignoreExceptions;
}

void QScriptDebuggerBackend::setIgnoreExceptions(bool ignore)
{
    Q_D(QScriptDebuggerBackend);
    d->ignoreExceptions = ignore;
}






QScriptValue QScriptDebuggerBackend::traceFunction() const
{
    Q_D(const QScriptDebuggerBackend);
    if (!engine())
        return QScriptValue();
    QScriptValue fun = engine()->newFunction(QScriptDebuggerBackendPrivate::trace);
    fun.setData(qScriptValueFromValue(engine(), const_cast<QScriptDebuggerBackendPrivate*>(d)));
    return fun;
}

QScriptValue QScriptDebuggerBackend::assertFunction() const
{
    if (!engine())
        return QScriptValue();
    QScriptValue fun = engine()->newFunction(QScriptDebuggerBackendPrivate::qsassert);
    return fun;
}

QScriptValue QScriptDebuggerBackend::fileNameFunction() const
{
    if (!engine())
        return QScriptValue();
    QScriptValue fun = engine()->newFunction(QScriptDebuggerBackendPrivate::fileName);
    return fun;
}

QScriptValue QScriptDebuggerBackend::lineNumberFunction() const
{
    if (!engine())
        return QScriptValue();
    QScriptValue fun = engine()->newFunction(QScriptDebuggerBackendPrivate::lineNumber);
    return fun;
}

QScriptDebuggerCommandExecutor *QScriptDebuggerBackend::commandExecutor() const
{
    Q_D(const QScriptDebuggerBackend);
    if (d->commandExecutor)
        return d->commandExecutor;
    QScriptDebuggerBackendPrivate *dd = const_cast<QScriptDebuggerBackendPrivate*>(d);
    dd->commandExecutor = new QScriptDebuggerCommandExecutor();
    return dd->commandExecutor;
}

void QScriptDebuggerBackend::setCommandExecutor(QScriptDebuggerCommandExecutor *executor)
{
    Q_D(QScriptDebuggerBackend);
    d->commandExecutor = executor;
}
QT_END_NAMESPACE
