#ifndef QSCRIPTDEBUGGERFRONTEND_P_H
#define QSCRIPTDEBUGGERFRONTEND_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qstring.h>

#include "qscriptdebuggercommandschedulerinterface_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerEventHandlerInterface;
class QScriptDebuggerCommand;
class QScriptDebuggerEvent;
class QScriptDebuggerResponse;

class QScriptDebuggerFrontendPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerFrontend
    : public QScriptDebuggerCommandSchedulerInterface
{
public:
    QScriptDebuggerFrontend();
    virtual ~QScriptDebuggerFrontend();

    QScriptDebuggerEventHandlerInterface *eventHandler() const;
    void setEventHandler(QScriptDebuggerEventHandlerInterface *eventHandler);

    int scheduleCommand(const QScriptDebuggerCommand &command,
                        QScriptDebuggerResponseHandlerInterface *responseHandler);

    int scheduledCommandCount() const;

protected:
    void notifyCommandFinished(int id, const QScriptDebuggerResponse &response);
    bool notifyEvent(const QScriptDebuggerEvent &event);

    virtual void processCommand(int id, const QScriptDebuggerCommand &command) = 0;

protected:
    QScriptDebuggerFrontend(QScriptDebuggerFrontendPrivate &dd);
    QScopedPointer<QScriptDebuggerFrontendPrivate> d_ptr;

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerFrontend)
    Q_DISABLE_COPY(QScriptDebuggerFrontend)
};

QT_END_NAMESPACE

#endif
