#include "capp.h"
#include "elog.h"

#ifndef WIN32
#include <unistd.h>
#else
#include <fcntl.h> /*  _O_BINARY */
#include <windows.h>
#include <dbghelp.h>
#include <time.h>
#endif



static void dumpBacktrace( unsigned int depth )
{
    if ( depth == 0 )
        depth = 20;
#if defined(Q_OS_WIN)
    void **buffer = new void *[ depth ];

    SymSetOptions( SYMOPT_DEFERRED_LOADS | SYMOPT_INCLUDE_32BIT_MODULES | SYMOPT_UNDNAME );
    SymInitialize( GetCurrentProcess(), "http://msdl.microsoft.com/download/symbols;http://download.osgeo.org/osgeo4w/symstore", TRUE );

    unsigned short nFrames = CaptureStackBackTrace( 1, depth, buffer, NULL );
    SYMBOL_INFO *symbol = ( SYMBOL_INFO * ) malloc( sizeof( SYMBOL_INFO ) + 256 );
    symbol->MaxNameLen = 255;
    symbol->SizeOfStruct = sizeof( SYMBOL_INFO );

    for ( int i = 0; i < nFrames; i++ )
    {
        SymFromAddr( GetCurrentProcess(), ( DWORD64 )( buffer[ i ] ), 0, symbol );
        symbol->Name[ 255 ] = 0;
        gInfo( "%d: %s [%x]\n", i, symbol->Name, symbol->Address );
    }

    free( symbol );
#endif
}
/*
 * Hook into the qWarning/qFatal
 */
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg   )
{
    if ( msg.left(15)== "libpng warning:"  )
    {
        return;
    }

    switch ( type )
    {
    case QtDebugMsg:
        gDebug("--------Debug: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        gWarn("--------Critical: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        gWarn( "--------Warning: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
    {
        gError( "--------Fatal: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
        dumpBacktrace( 256 );
        abort();                    // deliberately dump core
    }
    }
}


QString  GetDir(QString  pathType)
{
    QString sys_home = qgetenv("SMARTSYS_HOME");
    if(sys_home.isEmpty())
    {
        QDir tmpdir=QCoreApplication::applicationFilePath();
        tmpdir.cd("../../");
        sys_home=tmpdir.absolutePath();

    }
    if(pathType=="home")
        return sys_home;
    if(pathType=="script")
        return sys_home+QDir::separator()+"data"+QDir::separator()+"script"+QDir::separator();
    if(pathType=="bin")
        return sys_home+QDir::separator()+"bin"+QDir::separator();

}
/////
CApp::CApp(int & argc, char ** argv) :QCoreApplication ( argc, argv )
{
    // Set up the custom qWarning/qDebug custom handler
    qInstallMessageHandler(myMessageOutput);
    m_exit = false;
    QString libpath= GetDir("bin")+"plugins";
    QCoreApplication::addLibraryPath ( libpath );
    setOrganizationName("sf");
    setApplicationName(tr("cmdjs"));

    m_pScriptEngine=new CScriptEngine(this) ;
    m_pScriptEngine->installTranslatorFunctions();

    LoadPlugins();
    AddQSObject();
    CheckArg( argc,  argv);
	
}

CApp::~CApp()
{
    if (m_pScriptEngine)
    {
        delete m_pScriptEngine;
    }
    m_pScriptEngine = NULL;

    foreach (ICommunicateInterface* plugin, m_PlugIns)
    {
        plugin->Release();
    }

    log_info("-------------cmdjs release end....!");
}

void CApp::CheckArg(int & argc, char ** argv)
{
    QString str;
    for (int i = 1; i< argc; i++)
    {
        log_info("----- argv[%d] is %s", i, argv[i]);
        str = QString::fromLocal8Bit(argv[i]);

        QString argv_str =str;
        if(argv_str.startsWith("-") && i+1<argc)
        {
            argv_str=argv_str.mid(1);
            QString argv_val = QString::fromLocal8Bit(argv[i+1]);
            m_ArgsMap[argv_str]=argv_val;
        }

    }
	//setCodecForLocale must put before CheckArg, otherwise when include("base.js") some chinese character will be wrong 
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    bool needreg=true;
    if (m_ArgsMap.find("reg")!=m_ArgsMap.end() )
    {
        QString reg =  m_ArgsMap["reg"].toString() ;
        if (reg=="no"){
            needreg=false;
        }
    }
    if(needreg){
        int type=EPROC_RESIDEN  ;
#ifdef CMDJS_GUI
        type=EPROC_DEFAULT;
#endif
        int er = EProc::InitAndReg(argc, argv, type);

        if (er < 0)
        {
            log_warn("EProc::InitAndReg failed.er:%d\n", er);
        }
    }


    if (m_ArgsMap.find("file")!=m_ArgsMap.end() )
    {
        QString sFile =  m_ArgsMap["file"].toString() ;
        if (!sFile.isEmpty()){
            LoadScript(sFile);
        }
		if (m_ArgsMap.contains("svg"))//////svg导入命令cmdjs -file svgimp.js -svg D:\svn\cs_platform\UTF8\smartsys_pg\modelfile\dms_black\tt.svg，执行后退出////////
			m_exit = true;
    }


    if (m_ArgsMap.find("lupdate")!=m_ArgsMap.end() )
    {
        QString lup = m_ArgsMap["lupdate"].toString();
        if (QDir::isRelativePath(lup))
            lup =  GetDir("script") +   lup;
        QFileInfo fInfo(lup);
        LoadScript("base.js");
        LoadScript("tr.js");
        if (fInfo.isFile())
        {
            //file
            Lupdate(lup);
        }
        else if(fInfo.isDir())
        {
            //dir
            LupdateBat(lup);
        }

        m_exit = true;
    }

}

int CApp::QSRegisterObj(QObject* object,QString alias_name)
{
    m_pScriptEngine->AddObject(object,alias_name );
    m_QsObject[alias_name]=object;
    return 0;
}
void CApp::AddQSObject()
{

    m_pScriptEngine->AddObject(this,"Me");
    m_pScriptEngine->AddObject(this,"Window");

    /*
    QMap<QString,QObject*> tmpmap=((CGApp*)qApp)->GetQSObject();
    QMap<QString, QObject*>::const_iterator i ;
    for(i = tmpmap.constBegin();i!=tmpmap.constEnd();i++)
    {
        m_pScriptEngine->AddObject(i.value(),i.key());
        //pQmlEngine->AddObject(i.value(),i.key());
    }*/
    //LoadScript("base.js");
}

void CApp::LoadScript(QString fn)
{
    m_pScriptEngine->LoadFile(fn);
}

bool CApp::LoadPlugins()
{
    QString path= GetDir("bin");

    QDir pluginsDir(path);
    pluginsDir.cd("plugins");

    QStringList filters;
    filters << "*.dll" << "*.so" ;
    foreach (QString fileName, pluginsDir.entryList(filters))
    {
        if(fileName.indexOf("base")<0)
            continue;
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            ICommunicateInterface* appPlugIn = qobject_cast<ICommunicateInterface *>(plugin);
            if (appPlugIn)
            {
                bool ret=appPlugIn->Create( this);
                if(ret )
                {
                    QString name=appPlugIn->Name();
                    name=name.section(".",0,0);
                    m_PlugIns[name]=appPlugIn;
                }

            }
        }
        else
        {
            if (fileName.right(4) == ".dll" || fileName.right(3) == ".so")
                log_error("-------load plugin error: %s -------- ", loader.errorString().toStdString().c_str());
        }
    }
    return true;

}





int CApp::Lupdate(QString file)
{
    file = file.replace("\\","/");
    QString jsStr = QString("Tr.loadProperties({\"name\":\"ge_script_zh_cn.properties\"}); Tr.lupdate(\"%1\");").arg(file);
    return m_pScriptEngine->Evaluate(jsStr).toInt();
}

int CApp::LupdateBat(QString dir)
{
    QDir qdir(dir);
    if (!qdir.exists())
    {
        log_error("	dir:%s not exist ", dir.toLocal8Bit().data());
        return -1;
    }

    int ret = 0;

    qdir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList list = qdir.entryInfoList();

    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.isFile())
        {
            ret += Lupdate(fileInfo.filePath());
        }
        else if (fileInfo.isDir())
        {
            QString childDir = fileInfo.absoluteFilePath();
            ret += LupdateBat(childDir);
        }
    }
    return ret;
}

void CApp::Exit()
{
    QTimer::singleShot(500,  this,  SLOT(quit()));
}

QObject* CApp::Create(QString objname,const QVariant& args )
{
    if(objname=="Timer"){
        CGTimer * pTimer=new CGTimer(this);
        return pTimer;
    }
    else
        return NULL;
}

void CApp::QSleep(int msec)
{
#ifdef WIN32
        Sleep(msec);
#else
        sleep(msec/1000);
#endif
}

QString CApp::LoadFile(const QString &name )
{
    QString file_path_name=name;
    if(!QDir::isAbsolutePath(name))
    {
        file_path_name=GetDir("pic")+ name;
    }
    QFile file( file_path_name );
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug( "Can't open file %s",file_path_name.toLocal8Bit().data() );
        return QString();
    }
    QTextStream str( &file );
    return str.readAll();
}

int CApp::SaveFile(const QString &name,const QString& buf )
{
    QString file_path_name=name;
    if(!QDir::isAbsolutePath(name))
    {
        qDebug( "---------- pls use AbsolutePath---" );
        return -1;
    }
    QFile file( file_path_name );
    if (!file.open(QIODevice::ReadWrite))
    {
        qDebug( "Can't open file %s",file_path_name.data() );
        return -1;
    }
    file.resize(0);
    QTextStream out( &file );
    out << buf;
    file.close();
    return 1;
}

QString CApp::LoadBinaryFile(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        gError("Cannot open %s for writing", filePath.toStdString().c_str());
        return "";
    }
    QByteArray fileData;
    while (!file.atEnd())
    {
        fileData.append(file.readLine());
    }
    if (fileData.size() != file.size())
    {
        gError("Read filesize is not equal with original file size");
        return "";
    }
    return fileData.toBase64();
}

int CApp::SaveBinaryFile(QString filePath, QString fileStr)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        gError("Cannot open %s for writing", filePath.toStdString().c_str());
        return -1;
    }

    QByteArray fileData = QByteArray::fromBase64(fileStr.toUtf8());
    qint64 length = file.write(fileData);
    if (length != fileData.size())
    {
        gError("Failed to write all data to %s", filePath.toStdString().c_str());
        return -2;
    }
    return 0;
}


///
///
QScriptValue toQScriptValue( QScriptEngine* eng,const QVariant& qvar)
{
    switch(qvar.type())
    {
    case QVariant::Bool:
    case QVariant::Char:
    case QVariant::Int:
    case QVariant::UInt:
        return QScriptValue(eng,qvar.toInt());
    case QVariant::Double:
        return QScriptValue(eng,qvar.toDouble());
    case QVariant::String:
        return QScriptValue(eng,qvar.toString());
    default:
        return QScriptValue(eng,qvar.toString());
    }
}
///
QScriptValue Include(QScriptContext *context,QScriptEngine *engine)
{
    QString fileName = context->argument(0).toString();
    QFile file( fileName );
    if(!file.exists())
    {
        QString file_path_name= GetDir("script")+fileName;
        file.setFileName(file_path_name);
    }
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        QString err=file.errorString();
        gInfo(  "Can not load script file %s,err:%s",fileName.toLocal8Bit().data(),err.toLocal8Bit().data());
        return QString();
    }
    QTextStream str( &file );
    QString code=str.readAll();
    //set ScriptContext
    QScriptContext *context1 = engine->currentContext();
    QScriptContext *parent = context1->parentContext();
    if (parent != 0)
    {
        context1->setActivationObject(context1->parentContext()->activationObject());
        context1->setThisObject(context1->parentContext()->thisObject());
    }

    QString  errfileName = fileName;
    int startlineNumber=1;
    int line_number = 0;
    try
    {
        QScriptValue a= engine->evaluate(code,errfileName,startlineNumber);
        if ( engine->hasUncaughtException() )
        {
            line_number = engine->uncaughtExceptionLineNumber();
            QString error=engine->uncaughtException().toString();
            QStringList btrace=engine->uncaughtExceptionBacktrace();
            QString msg = QString::fromLatin1("-------Evaluate exception:%0 ,file:%1,line:%2;trace:%3").arg(error).arg(fileName).arg(line_number).arg(btrace.join(","));
            gWarn(msg.toLocal8Bit().data());
        }
        return QScriptValue();

    }
    catch(...)
    {
        return QScriptValue();
    }

}


CScriptEngine::CScriptEngine(QObject *parent)
    : QScriptEngine(parent)
{


    QScriptValue func1 = newFunction(Include);
    globalObject().setProperty("include", func1);

    AddObject(qApp,"qApp");

}

CScriptEngine::~CScriptEngine()
{
    abortEvaluation();
}
int CScriptEngine::AddObject(QObject* object,QString alias_name)
{

    if (object==NULL)
    {
        return -1;
    }

    if (alias_name.isEmpty())
    {
        alias_name=object->objectName();
    }
    QScriptValue objectValue = newQObject(object);
    globalObject().setProperty(alias_name, objectValue);
    return 0;
}

QVariant CScriptEngine::Call(const QString & fun_name, const QVariantList & args , QObject * context)
{
    QVariant ret;
    QScriptValue fun;
    if (fun_name.left(8)=="function")
    {
        QString tmp_str="("+fun_name+")";
        fun = evaluate(tmp_str);
    }
    else
        fun=globalObject().property(fun_name);

    if (fun.isFunction())
    {
        QScriptValueList arguments;
        for (int i=0;i<args.size();i++)
        {
            arguments << toQScriptValue(this,args[i]);
        }
        ret=fun.call(globalObject(),arguments).toVariant();
    }
    else
        ret=Evaluate(fun_name);

    return ret;
}

QVariant CScriptEngine::Evaluate( const QString & code ,const QString & errfileName, int startlineNumber)
{

    int line_number = 0;
    try
    {
        QScriptValue a= evaluate(code,errfileName,startlineNumber);
        if ( hasUncaughtException() )
        {
            line_number = uncaughtExceptionLineNumber();
            QString error=uncaughtException().toString();
            QStringList btrace=uncaughtExceptionBacktrace();
            QString msg = QString::fromLatin1("-------Evaluate exception:%0 ,file:%1,line:%2;trace:%3").arg(error).arg(errfileName).arg(line_number).arg(btrace.join(","));
            gWarn(msg.toLocal8Bit().data());

        }
        return a.toVariant();

    }
    catch(...)
    {
        return -1;
    }
}

int CScriptEngine::Clear()
{

    return 0;
}

QVariant CScriptEngine::LoadFile( QString fileName )
{
    QFile file( fileName );
    if(!file.exists())
    {
        QString file_path_name=GetDir("script")+fileName ;
        file.setFileName(file_path_name);
    }
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        QString err=file.errorString();
        gInfo(  "Can not load script file %s,err:%s",fileName.toLocal8Bit().data(),err.toLocal8Bit().data());
        return QString();
    }
    QTextStream str( &file );
    QString code=str.readAll();
    //set ScriptContext
    QScriptContext *context = currentContext();
    QScriptContext *parent = context->parentContext();
    if (parent != 0)
    {
        context->setActivationObject(context->parentContext()->activationObject());
        context->setThisObject(context->parentContext()->thisObject());
    }

    return Evaluate(code,fileName);
}


void CScriptEngine::EnableDebug(bool enable)
{
    if(enable==false && agent())
    {
        setAgent(0);
    }
    if(enable && !agent())
    {
        setAgent(new CScriptDebugger(this));
    }

}
////////////////


void CScriptDebugger::errorMessage(const QString &text)
{

}
void CScriptDebugger::exceptionCatch(qint64 scriptId,const QScriptValue &exception)
{
    exceptionThrow(scriptId ,  exception, true);
}

void CScriptDebugger::exceptionThrow(qint64  scriptId , const QScriptValue &exception, bool hasHandler)
{
    if (!hasHandler) {
        QScriptContext *ctx = engine()->currentContext();
        QScriptContextInfo info( ctx);
        int lineNumber = info.lineNumber();
        QString fileName = info.fileName();
        QString functionName = info.functionName()+"()";

        QString msg = QString::fromLatin1("uncaught exception: [ %1 ] at %2::%3 :line %4").arg(exception.toString()).arg(fileName).arg(functionName).arg(lineNumber);
        gError(msg.toLocal8Bit().data());
    }
}
