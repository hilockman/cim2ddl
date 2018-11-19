#include "capp.h"
#include "GFunc.h"
#include "elog.h"
#include "qsvgtinydocument_p.h"

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

CApp::CApp(int & argc, char ** argv) :QApplication ( argc, argv )
{
    // Set up the custom qWarning/qDebug custom handler
    qInstallMessageHandler(myMessageOutput);
    m_exit = false;
    QString libpath=UnqFunc()->GetDir(CGFunc::PATH_TYPE_BIN)+QDir::separator()+"plugins";
    QCoreApplication::addLibraryPath ( libpath );
    setOrganizationName("HMI");
    setApplicationName(tr("smarthmi"));

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
	QTextCodec::setCodecForLocale(QTextCodec::codecForName(LOCAL_LANGUAGE));
    bool needreg=true;
    if (m_ArgsMap.find("reg")!=m_ArgsMap.end() )
    {
        QString reg =  m_ArgsMap["reg"].toString() ;
        if (reg=="no"){
            needreg=false;
        }
    }
    if(needreg){
		int er = EProc::InitAndReg(argc, argv, EPROC_DEFAULT);
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

    if (m_ArgsMap.find("import")!=m_ArgsMap.end() )
    {
        QString impDst = m_ArgsMap["import"].toString();
        if (QDir::isRelativePath(impDst))
            impDst = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC) + "../model/" + impDst;
        if (impDst.right(4) == PICSUFFIX)
        {
            //file
            QString inFile = impDst;
            QString outFile = "";
            UnqFunc()->GetGraphNameByGraphPathName(inFile, outFile);
            UnqFunc()->GetGraphPathNameByGraphName(outFile, outFile);
            QSvgTinyDocument::toSmartsys(inFile, outFile);
        }
        else
        {
            //dir
            QSvgTinyDocument::toSmartsysBat(impDst);
        }

        m_exit = true;
    }
    if (m_ArgsMap.find("lupdate")!=m_ArgsMap.end() )
    {
        QString lup = m_ArgsMap["lupdate"].toString();
        if (QDir::isRelativePath(lup))
            lup = UnqFunc()->GetDir(CGFunc::PATH_TYPE_DATA) + "script/" + lup;
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
    QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_DLL);

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


int CApp::FileConvert(const QString& filename,const QString& outfilename )
{
    return QSvgTinyDocument::toSmartsys(filename,outfilename,m_QsObject);

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
