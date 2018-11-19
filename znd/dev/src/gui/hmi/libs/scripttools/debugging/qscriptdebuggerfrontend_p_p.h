#ifndef QSCRIPTDEBUGGERFRONTEND_P_P_H
#define QSCRIPTDEBUGGERFRONTEND_P_P_H 
#include <QtCore/qobjectdefs.h>

#include <QtCore/qlist.h>
#include <QtCore/qhash.h>

#include "qscriptdebuggercommand_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerEventHandlerInterface;
class QScriptDebuggerResponseHandlerInterface;
class QEvent;

class QScriptDebuggerFrontend;
class QScriptDebuggerFrontendPrivate
{
    Q_DECLARE_PUBLIC(QScriptDebuggerFrontend)
public:
    QScriptDebuggerFrontendPrivate();
    virtual ~QScriptDebuggerFrontendPrivate();

    void postEvent(QEvent *e);
    virtual bool event(QEvent *);
    void processCommands();

    QScriptDebuggerEventHandlerInterface *eventHandler;
    QList<QScriptDebuggerCommand> pendingCommands;
    QList<int> pendingCommandIds;
    QHash<int, QScriptDebuggerResponseHandlerInterface*> responseHandlers;
    int nextCommandId;
    QObject *eventReceiver;

    QScriptDebuggerFrontend *q_ptr;
};

QT_END_NAMESPACE

#endif
