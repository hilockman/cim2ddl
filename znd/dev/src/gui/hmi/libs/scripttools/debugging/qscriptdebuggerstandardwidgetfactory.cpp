#include "qscriptdebuggerstandardwidgetfactory_p.h"
#include "qscriptdebuggerconsolewidget_p.h"
#include "qscriptdebuggerstackwidget_p.h"
#include "qscriptdebuggerscriptswidget_p.h"
#include "qscriptdebuggerlocalswidget_p.h"
#include "qscriptdebuggercodewidget_p.h"
#include "qscriptdebuggercodefinderwidget_p.h"
#include "qscriptbreakpointswidget_p.h"
#include "qscriptdebugoutputwidget_p.h"
#include "qscripterrorlogwidget_p.h"

QT_BEGIN_NAMESPACE

QScriptDebuggerStandardWidgetFactory::QScriptDebuggerStandardWidgetFactory(QObject *parent)
    : QObject(parent)
{
}

QScriptDebuggerStandardWidgetFactory::~QScriptDebuggerStandardWidgetFactory()
{
}

QScriptDebugOutputWidgetInterface *QScriptDebuggerStandardWidgetFactory::createDebugOutputWidget()
{
    return new QScriptDebugOutputWidget();
}

QScriptDebuggerConsoleWidgetInterface *QScriptDebuggerStandardWidgetFactory::createConsoleWidget()
{
    return new QScriptDebuggerConsoleWidget();
}

QScriptErrorLogWidgetInterface *QScriptDebuggerStandardWidgetFactory::createErrorLogWidget()
{
    return new QScriptErrorLogWidget();
}

QScriptDebuggerCodeFinderWidgetInterface *QScriptDebuggerStandardWidgetFactory::createCodeFinderWidget()
{
    return new QScriptDebuggerCodeFinderWidget();
}

QScriptDebuggerStackWidgetInterface *QScriptDebuggerStandardWidgetFactory::createStackWidget()
{
    return new QScriptDebuggerStackWidget();
}

QScriptDebuggerScriptsWidgetInterface *QScriptDebuggerStandardWidgetFactory::createScriptsWidget()
{
    return new QScriptDebuggerScriptsWidget();
}

QScriptDebuggerLocalsWidgetInterface *QScriptDebuggerStandardWidgetFactory::createLocalsWidget()
{
    return new QScriptDebuggerLocalsWidget();
}

QScriptDebuggerCodeWidgetInterface *QScriptDebuggerStandardWidgetFactory::createCodeWidget()
{
    return new QScriptDebuggerCodeWidget();
}

QScriptBreakpointsWidgetInterface *QScriptDebuggerStandardWidgetFactory::createBreakpointsWidget()
{
    return new QScriptBreakpointsWidget();
}

QT_END_NAMESPACE
