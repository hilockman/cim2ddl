#ifndef QSCRIPTDEBUGGERSTANDARDWIDGETFACTORY_P_H
#define QSCRIPTDEBUGGERSTANDARDWIDGETFACTORY_P_H 
#include <QtCore/qobject.h>

#include "qscriptdebuggerwidgetfactoryinterface_p.h"

QT_BEGIN_NAMESPACE

class Q_AUTOTEST_EXPORT QScriptDebuggerStandardWidgetFactory
    : public QObject, public QScriptDebuggerWidgetFactoryInterface
{
public:
    QScriptDebuggerStandardWidgetFactory(QObject *parent = 0);
    virtual ~QScriptDebuggerStandardWidgetFactory();

    QScriptDebugOutputWidgetInterface *createDebugOutputWidget();
    QScriptDebuggerConsoleWidgetInterface *createConsoleWidget();
    QScriptErrorLogWidgetInterface *createErrorLogWidget();
    QScriptDebuggerCodeFinderWidgetInterface *createCodeFinderWidget();
    QScriptDebuggerStackWidgetInterface *createStackWidget();
    QScriptDebuggerScriptsWidgetInterface *createScriptsWidget();
    QScriptDebuggerLocalsWidgetInterface *createLocalsWidget();
    QScriptDebuggerCodeWidgetInterface *createCodeWidget();
    QScriptBreakpointsWidgetInterface *createBreakpointsWidget();

private:
    Q_DISABLE_COPY(QScriptDebuggerStandardWidgetFactory)
};

QT_END_NAMESPACE

#endif
