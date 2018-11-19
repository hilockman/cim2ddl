#include <QtWidgets>
#include <QtScript>
#include <QtScriptTools>


int main(int argv, char **args)
{
    QApplication app(argv, args);

     QString fileName("helloscript.qs");
     QFile scriptFile(fileName);
     scriptFile.open(QIODevice::ReadOnly);
     QTextStream stream(&scriptFile);
     QString contents = stream.readAll();
     scriptFile.close();

    QScriptEngine *engine = new QScriptEngine();

    QScriptEngineDebugger *debugger = new QScriptEngineDebugger();
    debugger->attachTo(engine);


    QWidget *widget = new QWidget;

    QWidget *codeWindow = debugger->widget(QScriptEngineDebugger::CodeWidget);
    QWidget *stackWidget = debugger->widget(QScriptEngineDebugger::StackWidget);

    QLayout *layout = new QHBoxLayout;
    layout->addWidget(codeWindow);
    layout->addWidget(stackWidget);



    QAction *continueAction = debugger->action(QScriptEngineDebugger::ContinueAction);
    QAction *stepOverAction = debugger->action(QScriptEngineDebugger::StepOverAction);
    QAction *stepIntoAction = debugger->action(QScriptEngineDebugger::StepIntoAction);

    QToolBar *toolBar = new QToolBar;
    toolBar->addAction(continueAction);

    toolBar->addAction(stepOverAction);
    toolBar->addAction(stepIntoAction);

    layout->addWidget(toolBar);
    continueAction->setIcon(QIcon("copy.png"));

    debugger->setAutoShowStandardWindow(false);

    widget->setLayout(layout);
    widget->show();

     QPushButton button;
     QScriptValue scriptButton = engine->newQObject(&button);
     engine->globalObject().setProperty("button", scriptButton);


     debugger->action(QScriptEngineDebugger::InterruptAction)->trigger();
     engine->evaluate(contents, fileName);


    return app.exec();
}
