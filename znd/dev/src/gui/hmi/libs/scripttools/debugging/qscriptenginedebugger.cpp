#include "qscriptenginedebugger.h"
#include "qscriptdebugger_p.h"
#include "qscriptenginedebuggerfrontend_p.h"
#include "qscriptdebuggerstandardwidgetfactory_p.h"
#include <private/qobject_p.h>

#include <QtCore/qsettings.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qdockwidget.h>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qboxlayout.h>


static void initScriptEngineDebuggerResources()
{
    Q_INIT_RESOURCE(scripttools_debugging);
}

QT_BEGIN_NAMESPACE

class QtScriptDebuggerResourceInitializer
{
public:
    QtScriptDebuggerResourceInitializer() {

        initScriptEngineDebuggerResources();
    }
};
class QScriptEngineDebuggerPrivate
    : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QScriptEngineDebugger)
public:
    QScriptEngineDebuggerPrivate();
    ~QScriptEngineDebuggerPrivate();


    void _q_showStandardWindow();

    void createDebugger();

    QScriptDebugger *debugger;
    QScriptEngineDebuggerFrontend *frontend;
#ifndef QT_NO_MAINWINDOW
    QMainWindow *standardWindow;
#endif
    bool autoShow;

    static QtScriptDebuggerResourceInitializer resourceInitializer;
};

namespace {

class WidgetClosedNotifier : public QObject
{
    Q_OBJECT
public:
    WidgetClosedNotifier(QWidget *w, QObject *parent = 0)
        : QObject(parent), widget(w)
    {
        w->installEventFilter(this);
    }

    bool eventFilter(QObject *watched, QEvent *e)
    {
        if (watched != widget)
            return false;
        if (e->type() != QEvent::Close)
            return false;
        emit widgetClosed();
        return true;
    }

Q_SIGNALS:
    void widgetClosed();

private:
    QWidget *widget;
};

}

QtScriptDebuggerResourceInitializer QScriptEngineDebuggerPrivate::resourceInitializer;

QScriptEngineDebuggerPrivate::QScriptEngineDebuggerPrivate()
{
    debugger = 0;
    frontend = 0;
#ifndef QT_NO_MAINWINDOW
    standardWindow = 0;
#endif
    autoShow = true;
}

QScriptEngineDebuggerPrivate::~QScriptEngineDebuggerPrivate()
{
    delete debugger;
    delete frontend;
#ifndef QT_NO_MAINWINDOW
    if (standardWindow) {
        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        QByteArray geometry = standardWindow->saveGeometry();
        settings.setValue(QLatin1String("Qt/scripttools/debugging/mainWindowGeometry"), geometry);
        QByteArray state = standardWindow->saveState();
        settings.setValue(QLatin1String("Qt/scripttools/debugging/mainWindowState"), state);
        if (standardWindow->parent() == 0)
            delete standardWindow;
    }
#endif
}

#ifndef QT_NO_MAINWINDOW
void QScriptEngineDebuggerPrivate::_q_showStandardWindow()
{
    Q_Q(QScriptEngineDebugger);
    (void)q->standardWindow();
    standardWindow->show();
}
#endif

void QScriptEngineDebuggerPrivate::createDebugger()
{
    Q_Q(QScriptEngineDebugger);
    if (!debugger) {
        debugger = new QScriptDebugger();
        debugger->setWidgetFactory(new QScriptDebuggerStandardWidgetFactory(q));
        QObject::connect(debugger, SIGNAL(started()),
                         q, SIGNAL(evaluationResumed()));
        QObject::connect(debugger, SIGNAL(stopped()),
                         q, SIGNAL(evaluationSuspended()));
        if (autoShow) {
            QObject::connect(q, SIGNAL(evaluationSuspended()),
                             q, SLOT(_q_showStandardWindow()));
        }
    }
}
QScriptEngineDebugger::QScriptEngineDebugger(QObject *parent)
    : QObject(*new QScriptEngineDebuggerPrivate, parent)
{
}




QScriptEngineDebugger::~QScriptEngineDebugger()
{
}
void QScriptEngineDebugger::attachTo(QScriptEngine *engine)
{
    Q_D(QScriptEngineDebugger);
    if (!engine) {
        detach();
        return;
    }
    d->createDebugger();
    if (!d->frontend)
        d->frontend = new QScriptEngineDebuggerFrontend();
    d->frontend->attachTo(engine);
    d->debugger->setFrontend(d->frontend);
}






void QScriptEngineDebugger::detach()
{
    Q_D(QScriptEngineDebugger);
    if (d->frontend)
        d->frontend->detach();
    if (d->debugger)
        d->debugger->setFrontend(0);
}
QScriptEngineDebugger::DebuggerState QScriptEngineDebugger::state() const
{
    Q_D(const QScriptEngineDebugger);
    return !d->debugger || !d->debugger->isInteractive() ? SuspendedState : RunningState;
}
QWidget *QScriptEngineDebugger::widget(DebuggerWidget widget) const
{
    Q_D(const QScriptEngineDebugger);
    const_cast<QScriptEngineDebuggerPrivate*>(d)->createDebugger();
    return d->debugger->widget(static_cast<QScriptDebugger::DebuggerWidget>(static_cast<int>(widget)));
}
QAction *QScriptEngineDebugger::action(DebuggerAction action) const
{
    Q_D(const QScriptEngineDebugger);
    QScriptEngineDebugger *that = const_cast<QScriptEngineDebugger*>(this);
    that->d_func()->createDebugger();
    return d->debugger->action(static_cast<QScriptDebugger::DebuggerAction>(static_cast<int>(action)), that);
}







bool QScriptEngineDebugger::autoShowStandardWindow() const
{
    Q_D(const QScriptEngineDebugger);
    return d->autoShow;
}






void QScriptEngineDebugger::setAutoShowStandardWindow(bool autoShow)
{
    Q_D(QScriptEngineDebugger);
    if (autoShow == d->autoShow)
        return;
    if (autoShow) {
        QObject::connect(this, SIGNAL(evaluationSuspended()),
                         this, SLOT(_q_showStandardWindow()));
    } else {
        QObject::disconnect(this, SIGNAL(evaluationSuspended()),
                            this, SLOT(_q_showStandardWindow()));
    }
    d->autoShow = autoShow;
}







#ifndef QT_NO_MAINWINDOW
QMainWindow *QScriptEngineDebugger::standardWindow() const
{
    Q_D(const QScriptEngineDebugger);
    if (d->standardWindow)
        return d->standardWindow;
    if (!QApplication::instance())
        return 0;
    QScriptEngineDebugger *that = const_cast<QScriptEngineDebugger*>(this);

    QMainWindow *win = new QMainWindow();
#ifndef QT_NO_DOCKWIDGET
    QDockWidget *scriptsDock = new QDockWidget(win);
    scriptsDock->setObjectName(QLatin1String("qtscriptdebugger_scriptsDockWidget"));
    scriptsDock->setWindowTitle(tr("Loaded Scripts"));
    scriptsDock->setWidget(widget(ScriptsWidget));
    win->addDockWidget(Qt::LeftDockWidgetArea, scriptsDock);

    QDockWidget *breakpointsDock = new QDockWidget(win);
    breakpointsDock->setObjectName(QLatin1String("qtscriptdebugger_breakpointsDockWidget"));
    breakpointsDock->setWindowTitle(tr("Breakpoints"));
    breakpointsDock->setWidget(widget(BreakpointsWidget));
    win->addDockWidget(Qt::LeftDockWidgetArea, breakpointsDock);

    QDockWidget *stackDock = new QDockWidget(win);
    stackDock->setObjectName(QLatin1String("qtscriptdebugger_stackDockWidget"));
    stackDock->setWindowTitle(tr("Stack"));
    stackDock->setWidget(widget(StackWidget));
    win->addDockWidget(Qt::RightDockWidgetArea, stackDock);

    QDockWidget *localsDock = new QDockWidget(win);
    localsDock->setObjectName(QLatin1String("qtscriptdebugger_localsDockWidget"));
    localsDock->setWindowTitle(tr("Locals"));
    localsDock->setWidget(widget(LocalsWidget));
    win->addDockWidget(Qt::RightDockWidgetArea, localsDock);

    QDockWidget *consoleDock = new QDockWidget(win);
    consoleDock->setObjectName(QLatin1String("qtscriptdebugger_consoleDockWidget"));
    consoleDock->setWindowTitle(tr("Console"));
    consoleDock->setWidget(widget(ConsoleWidget));
    win->addDockWidget(Qt::BottomDockWidgetArea, consoleDock);

    QDockWidget *debugOutputDock = new QDockWidget(win);
    debugOutputDock->setObjectName(QLatin1String("qtscriptdebugger_debugOutputDockWidget"));
    debugOutputDock->setWindowTitle(tr("Debug Output"));
    debugOutputDock->setWidget(widget(DebugOutputWidget));
    win->addDockWidget(Qt::BottomDockWidgetArea, debugOutputDock);

    QDockWidget *errorLogDock = new QDockWidget(win);
    errorLogDock->setObjectName(QLatin1String("qtscriptdebugger_errorLogDockWidget"));
    errorLogDock->setWindowTitle(tr("Error Log"));
    errorLogDock->setWidget(widget(ErrorLogWidget));
    win->addDockWidget(Qt::BottomDockWidgetArea, errorLogDock);

    win->tabifyDockWidget(errorLogDock, debugOutputDock);
    win->tabifyDockWidget(debugOutputDock, consoleDock);
#endif

#ifndef QT_NO_TOOLBAR
    win->addToolBar(Qt::TopToolBarArea, that->createStandardToolBar());
#endif

#ifndef QT_NO_MENUBAR
    win->menuBar()->addMenu(that->createStandardMenu(win));

    QMenu *editMenu = win->menuBar()->addMenu(tr("Search"));
    editMenu->addAction(action(FindInScriptAction));
    editMenu->addAction(action(FindNextInScriptAction));
    editMenu->addAction(action(FindPreviousInScriptAction));
    editMenu->addSeparator();
    editMenu->addAction(action(GoToLineAction));

#ifndef QT_NO_DOCKWIDGET
    QMenu *viewMenu = win->menuBar()->addMenu(tr("View"));
    viewMenu->addAction(scriptsDock->toggleViewAction());
    viewMenu->addAction(breakpointsDock->toggleViewAction());
    viewMenu->addAction(stackDock->toggleViewAction());
    viewMenu->addAction(localsDock->toggleViewAction());
    viewMenu->addAction(consoleDock->toggleViewAction());
    viewMenu->addAction(debugOutputDock->toggleViewAction());
    viewMenu->addAction(errorLogDock->toggleViewAction());
#endif
#endif

    QWidget *central = new QWidget();
    QVBoxLayout *vbox = new QVBoxLayout(central);
    vbox->setMargin(0);
    vbox->addWidget(widget(CodeWidget));
    vbox->addWidget(widget(CodeFinderWidget));
    widget(CodeFinderWidget)->hide();
    win->setCentralWidget(central);

    win->setWindowTitle(tr("Qt Script Debugger"));
#ifndef QT_NO_TOOLBAR
    win->setUnifiedTitleAndToolBarOnMac(true);
#endif

    QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
    QVariant geometry = settings.value(QLatin1String("Qt/scripttools/debugging/mainWindowGeometry"));
    if (geometry.isValid())
        win->restoreGeometry(geometry.toByteArray());
    QVariant state = settings.value(QLatin1String("Qt/scripttools/debugging/mainWindowState"));
    if (state.isValid())
        win->restoreState(state.toByteArray());

    WidgetClosedNotifier *closedNotifier = new WidgetClosedNotifier(win, that);
    QObject::connect(closedNotifier, SIGNAL(widgetClosed()),
                     action(ContinueAction), SLOT(trigger()));

    const_cast<QScriptEngineDebuggerPrivate*>(d)->standardWindow = win;
    return win;
}
#endif







QMenu *QScriptEngineDebugger::createStandardMenu(QWidget *parent)
{
    Q_D(QScriptEngineDebugger);
    d->createDebugger();
    return d->debugger->createStandardMenu(parent, this);
}







#ifndef QT_NO_TOOLBAR
QToolBar *QScriptEngineDebugger::createStandardToolBar(QWidget *parent)
{
    Q_D(QScriptEngineDebugger);
    d->createDebugger();
    return d->debugger->createStandardToolBar(parent, this);
}
#endif
QT_END_NAMESPACE

#include "qscriptenginedebugger.moc"

#include "moc_qscriptenginedebugger.cpp"
