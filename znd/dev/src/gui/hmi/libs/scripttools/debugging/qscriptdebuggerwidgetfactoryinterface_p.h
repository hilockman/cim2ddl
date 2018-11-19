#ifndef QSCRIPTDEBUGGERWIDGETFACTORYINTERFACE_P_H
#define QSCRIPTDEBUGGERWIDGETFACTORYINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptDebugOutputWidgetInterface;
class QScriptDebuggerConsoleWidgetInterface;
class QScriptErrorLogWidgetInterface;
class QScriptDebuggerCodeFinderWidgetInterface;
class QScriptDebuggerStackWidgetInterface;
class QScriptDebuggerScriptsWidgetInterface;
class QScriptDebuggerLocalsWidgetInterface;
class QScriptDebuggerCodeWidgetInterface;
class QScriptBreakpointsWidgetInterface;

class Q_AUTOTEST_EXPORT QScriptDebuggerWidgetFactoryInterface
{
public:
    virtual ~QScriptDebuggerWidgetFactoryInterface() {}

    virtual QScriptDebugOutputWidgetInterface *createDebugOutputWidget() = 0;
    virtual QScriptDebuggerConsoleWidgetInterface *createConsoleWidget() = 0;
    virtual QScriptErrorLogWidgetInterface *createErrorLogWidget() = 0;
    virtual QScriptDebuggerCodeFinderWidgetInterface *createCodeFinderWidget() = 0;
    virtual QScriptDebuggerStackWidgetInterface *createStackWidget() = 0;
    virtual QScriptDebuggerScriptsWidgetInterface *createScriptsWidget() = 0;
    virtual QScriptDebuggerLocalsWidgetInterface *createLocalsWidget() = 0;
    virtual QScriptDebuggerCodeWidgetInterface *createCodeWidget() = 0;
    virtual QScriptBreakpointsWidgetInterface *createBreakpointsWidget() = 0;
};

QT_END_NAMESPACE

#endif
