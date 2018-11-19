#include "Global.h"
#include "GFunc.h"
#include "GApp.h"
#include "CQScriptWrap.h"
#include "elog.h"
#include "CommunicatePluginMng.h"
#include "CManhattanStyle.h"

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
#ifdef _ELOG
  switch ( type )
  {
    case QtDebugMsg:
	  gDebug("--------Debug: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
      break;
    case QtCriticalMsg:
	  gWarn("--------Critical: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
      break;
    case QtWarningMsg:
      gDebug( "--------Warning: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
      break;
    case QtFatalMsg:
    {
      gError( "--------Fatal: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
      dumpBacktrace( 256 );
      abort();                    // deliberately dump core
    }
  }
#else
	fprintf(stderr, "myMessageOutput: %s (%s:%u, %s)\n", msg.toLocal8Bit().data(), context.file, context.line, context.function);
	if (type == QtFatalMsg){
		dumpBacktrace(256);
		abort();                    // deliberately dump core
	}
#endif

}

CGApp::CGApp(int & argc, char ** argv) :QApplication ( argc, argv )
{
    // Set up the custom qWarning/qDebug custom handler
    qInstallMessageHandler(myMessageOutput);
    setOrganizationName("HMI");
    setApplicationName(tr("smarthmi"));

    m_TimerCount = 0 ;
    m_InitWndRect = QRect(0,0,QApplication::desktop()->width(),QApplication::desktop()->height());
    m_nHaveRepository = 1;
    m_NeedBroadcast = 1;
    m_ForceRequery =false;
    CheckArg( argc, argv);
    QString libpath=UnqFunc()->GetDir(CGFunc::PATH_TYPE_BIN)+QDir::separator()+"plugins";
    QApplication::addLibraryPath ( libpath );

	//setCodecForLocale must put before CheckArg, otherwise when include("base.js") some chinese character will be wrong 
	QTextCodec::setCodecForLocale(QTextCodec::codecForName(LOCAL_LANGUAGE));
    UnqCommPluginMng()->SetParent(this);
    if(m_ArgsMap.find("nobase")==m_ArgsMap.end())
        UnqCommPluginMng()->LoadPlugins();


}

CGApp::~CGApp()
{
    UnqCommPluginMng()->Release();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->clear(QClipboard::Clipboard);
    killTimer(m_TimeID);

    gInfo("-------------HMI---GApp Release End....!");
#ifndef WIN32
    _exit(0);
#endif
}

void CGApp::RunApp( QString register_name)
{
    QFile file(UnqFunc()->GetSysHome()+"/data/css/guistyle.css");
    if (file.open(QFile::ReadOnly))
    {
        QString qssStr = QString(file.readAll());
        qssStr.replace("@", UnqFunc()->GetSysHome().replace("\\", "/"), Qt::CaseInsensitive);
        setStyleSheet(qssStr);
    }

    ChangeLanguage("");

    m_pCurMaxGraphID= 0;

    if(m_graph_disp_info.wnd_type != 0)
    {
        NewGraphWindow(m_graph_disp_info);
        gInfo("------------NewGraphWindow--ok--------");
    }
    m_TimeID = startTimer(50);
    QObject::connect(this, SIGNAL(lastWindowClosed()),this, SLOT(quit()));
}

void CGApp::CheckArg(int & argc, char ** argv)
{
    QStringList argv_strlist; 
    for(int i=1; i< argc;i++ )
    {
        gInfo("----- argv[%d] is %s", i, argv[i]);
		QString argv_str = QString::fromLocal8Bit(argv[i]);
        argv_strlist.push_back(argv_str);
        if(argv_str.startsWith("-") && i+1<argc)
        {
            argv_str=argv_str.mid(1);
            QString argv_val = QString::fromLocal8Bit(argv[i+1]);
            m_ArgsMap[argv_str]=argv_val;
        }
    }
    if(m_ArgsMap["syshome"].isValid()){
            QDir tmpdir=QCoreApplication::applicationFilePath();
            tmpdir.cd("../../");
            UnqFunc()->SetSysHome(tmpdir.absolutePath());
    }

    CheckDispArg(argc,argv_strlist, m_graph_disp_info);

}

void CGApp::CheckDispArg(int & argc, const QStringList &argv, GDispInfo & graph_disp_info)
{
    char wnd_type[60];
    char app_style[60];
    int app_id = -1;
    bool is_print = false;
    bool is_find = false;
    QString app_key_string;
    QString replace_key_str;
    QString wndflags;
    QString lang="";
    wnd_type[0] = 0;
    app_style[0] = 0;

    QString str;
    QStringList::const_iterator it = argv.begin();
    while (it!=argv.end())
    {
        str = *it;
        if(strcmp(str.toLocal8Bit().data(),"-pic") == 0)
        {

            ++it;
            if(it != argv.end())
            {
                str = *it;
                UnqFunc()->GetGraphPathNameByGraphName(str, graph_disp_info.graph_path_name);
                ++ it;
                continue;
            }
            else
            {
                fprintf(stderr,
                        "Usage(command line):-plane <plane_parament>\n");
                break;
            }
        }
		if (strcmp(str.toLocal8Bit().data(), "-import") == 0)
		{

			++it;
			if (it != argv.end())
			{
				str = *it;
				if (str.right(4) == PICSUFFIX && QDir::isRelativePath(str))
					graph_disp_info.import_path_name = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC) + "/../model/" + str;
				else
					graph_disp_info.import_path_name = str;
				++it;
				continue;
			}
			else
			{
				fprintf(stderr,
					"Usage(command line):-plane <plane_parament>\n");
				break;
			}
		}

        if(strcmp(str.toLocal8Bit().data(), "-wnd" ) == 0)
        {
            ++ it ;
            if(it != argv.end())
            {
                str = *it;
                strcpy(wnd_type,str.toLocal8Bit().data());
                ++ it;
                continue;
            }
            else
            {
                fprintf(stderr,"Usage(command line):-wnd <wnd_type(designer/explorer/icon/bay/lsd>\n");
                break;
            }
        }
        if(strcmp(str.toLocal8Bit().data(), "-lang" ) == 0)
        {
            ++ it ;
            if(it != argv.end())
            {
                lang = *it;
                ++ it;
                continue;
            }
            else
            {
                fprintf(stderr, "Usage(command line):-lang <(eng/zh_CN/>\n");
                break;
            }
        }
        if(strncmp(str.toLocal8Bit().data(),"-appstyle",9) == 0)
        {
            ++ it ;
            if(it != argv.end())
            {
                str = *it;
                strcpy(app_style, str.toLocal8Bit().data());
                ++it;
                continue;
            }
            else
            {
                fprintf(stderr, "Usage(command line):-appstyle <cde/motif/motifplus/window/metal/wood>\n");
                break;
            }
        }
        if(strncmp(str.toLocal8Bit().data(),"-app_key_id",11) == 0)
        {
            ++ it ;
            if(it != argv.end())
            {
                app_key_string = *it;
                ++it;
                continue;
            }
            else
            {
                fprintf(stderr, "Usage(command line):-app_key_id <app_id/recored_id/column_id>\n");
                break;
            }
        }
        if(strncmp(str.toLocal8Bit().data(),"-wndflag",8) == 0)
        {
            ++ it ;
            if(it != argv.end())
            {
                str = *it;
                wndflags = str;
                ++it;
                continue;
            }
            else
            {
                fprintf(stderr,"Usage(command line):-wndflag <dlg/replace/cover>\n");
                break;
            }
        }
        if(strncmp(str.toLocal8Bit().data(),"-args",5) == 0)
        {
            ++ it ;
            if(it != argv.end())
            {
                str = *it;
                graph_disp_info.args = str;
                ++it;
                continue;
            }
            else
            {
                fprintf(stderr,"Usage(command line):-args <args>\n");
                break;
            }
        }

        if(strncmp(str.toLocal8Bit().data(),"-replace_key",12) == 0)
        {
            ++ it ;
            if(it != argv.end())
            {
                str = *it;
                replace_key_str = str ;
                ++it;
                continue;
            }
            else
            {
                fprintf(stderr,"Usage(command line):-replace_key <app_id/recored_id/column_id>\n");
                break;
            }
        }
        if(strcmp(str.toLocal8Bit().data(),"-print") == 0)
        {
            is_print = true;
        }
        if(strcmp(str.toLocal8Bit().data(),"-find") == 0)
        {
            is_find = true;
        }
        if(strcmp(str.toLocal8Bit().data(),"-newwnd") == 0)
        {
            graph_disp_info.new_wnd = true;
        }
        ++it;
    }

    if (strcmp(wnd_type, "explorer")==0)
    {
        graph_disp_info.wnd_type = Hmi::Explorer;
    }
    else if (strcmp(wnd_type, "designer")==0)
    {
        graph_disp_info.wnd_type = Hmi::Designer;
    }
    else if (strcmp(wnd_type, "icon")==0)
    {
        graph_disp_info.wnd_type = Hmi::Iconer;
    }
    else
    {
        graph_disp_info.wnd_type = 0;
    }
    graph_disp_info.wnd = wnd_type;

    if (wndflags== "dlg")
    {
        graph_disp_info.wnd_style = Qt::Dialog;
        graph_disp_info.new_wnd = false;
    }
    else if (wndflags== "win")
    {
        graph_disp_info.wnd_style = Qt::Window;
    }
    else
    {

    }


    if (is_find && !app_key_string.isEmpty())
    {
        graph_disp_info.is_find = true;
    }


    graph_disp_info.wnd_type = Hmi::Explorer;
    graph_disp_info.is_print = is_print;
    graph_disp_info.app_id = app_id;
    graph_disp_info.lang = lang;
}

void CGApp::timerEvent(QTimerEvent *e)
{

}

int CGApp::QSRegisterObj(QObject* object,QString alias_name)
{
    m_QsObject[alias_name]=object;
    return 0;
}

void CGApp::OnValueChanged(const QString& tag, const QVariant& value)
{

}


void CGApp::SetData(const QString& jsonStr,bool reflash)
{
    PutData(jsonStr);
    if(reflash)
        ProcessChangeData();

}

int CGApp::PutData(const QString& tagName,const DataNode& val )
{
    AddChgData(tagName,val.value);
    return 0;
}


int CGApp::PutData(const QString& jsonStr)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (!(jsonDoc.isNull() || jsonDoc.isEmpty())) {
            if (jsonDoc.isObject())
            {

            }
            else if (jsonDoc.isArray())
            {
                QJsonArray jsonArrays = jsonDoc.array();
                CHG_DATA_MAP chgdata;
                foreach(QJsonValue jsonv, jsonArrays)
                {
                    QJsonObject jobj = jsonv.toObject();
                    QStringList vs;
                    vs << jobj["v"].toString() << jobj["s"].toString();
                    chgdata.insert(jobj["tag"].toString(), vs);
                }
                AddChgData(chgdata);
            }
        }
    }
    else {

    }

    return 0;
}


void CGApp::OnDownIcon(bool need_clear )
{

}

int CGApp::GetData(const QStringList& tags,QList<DataNode>& values)
{
    return UnqCommPluginMng()->GetData(tags,values);
}
void CGApp::EmitSignal(QString signal,QString arg)
{
    if (signal=="SigFileOpen")
    {
        emit SigFileOpen(arg);
    }
    else if (signal=="SigFileClose")
    {
        emit SigFileClose(arg);
    }
}

void CGApp::AddChgData(const QString& tagName,const QVariant& val)
{
    m_DataPool.insert(tagName,val);
}
void CGApp::AddChgData(const CHG_DATA_MAP& valmap)
{
    m_DataPool.unite(valmap);
}
CHG_DATA_MAP& CGApp::GetChgDataMap()
{
    return m_DataPool;
}

int CGApp::ResetChgDataMap()
{
    m_DataPool.clear();
    return 0;
}

void CGApp::SetStyle(const QString & style)
{
    QStringList styles= QStyleFactory::keys();
    if(styles.contains(style,Qt::CaseInsensitive))
    {
        qApp->setStyle( style);
    }
    else if(style.contains("manhattan",Qt::CaseInsensitive))
    {
        QString baseName = qApp->style()->objectName();
        qApp->setStyle( new ManhattanStyle( baseName ) );
    }


}

bool CGApp::LoadPlugins(const QString& pluginName)
{
    UnqCommPluginMng()->LoadPlugins();
    return true;
}

void CGApp::ChangeLanguage(const QString& language,bool update)
{
    QString langPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_RES) + QString("/lang/");
    QString lang = language;
    if (lang.length() == 0)
        lang = QLocale::system().name();

    QDir dir(langPath);
    QStringList strList = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    for (int nLoop = 0; nLoop < strList.count(); ++nLoop)
    {
        QString strFile = strList.at(nLoop);
        if (strFile.endsWith(lang+ ".qm", Qt::CaseInsensitive))
        {
            strFile.chop(3);
            QTranslator *pTranslator = new QTranslator(this);
            bool bOk = pTranslator->load(strFile, langPath);
			gInfo("---load lang file error %s", strFile.toLocal8Bit().data());
            installTranslator(pTranslator);
        }
    }
    if(update){
        foreach (QWidget *widget, QApplication::topLevelWidgets()) {
            //if (widget->inherits("QMainWindow"))
              //  widget->show();
        }
    }
}
