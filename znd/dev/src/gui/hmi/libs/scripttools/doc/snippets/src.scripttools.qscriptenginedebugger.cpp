    QScriptEngine engine;
    QScriptEngineDebugger debugger;
    debugger.attachTo(&engine);



    engine.evaluate("debugger");
