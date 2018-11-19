#include "Global.h"
#include "GFunc.h"
#include "GEApp.h"
#include "ExplorerWnd.h"
#include "ExplorerView.h"
#include "CQScriptWrap.h"
#include "CommunicatePluginMng.h"

#ifdef WEBVIEW
#include <QtWebSockets>
#include "qwebchannel.h"
#include "websocketclientwrapper.h"
#endif

#ifndef WIN32
#include <unistd.h>
#else
#include <windows.h>
#endif


CGEApp::CGEApp(int & argc, char ** argv) :CGApp ( argc, argv )
{
    m_pActiveExplorerWnd = NULL;
    UnqFunc()->LoadIconInfo();
#ifdef WEBVIEW
    m_pServer=NULL;
    m_pChannel=NULL;
    InitWebChannel();
#endif

}

CGEApp::~CGEApp()
{
#ifdef WEBVIEW
    if(m_pServer)
        delete m_pServer;
    if(m_pChannel)
        delete m_pChannel;
#endif
}

void CGEApp::Test(QString aaa)
{
    QMessageBox::warning(0,aaa,aaa);
}

//-99 mean self window; -1 mean all windows;0,1,2 mean
QVariant CGEApp::DoCmd(QString wnd_name, QString file_name, QString script_code, int wnd_idx)
{
    CGExplorerWnd* pwnd=(CGExplorerWnd*)GetActiveWnd();
    if( pwnd  )
    {
        return pwnd->DoCmd(wnd_name,file_name,script_code,wnd_idx);
    }
    return "";
}

 QObject* CGEApp::Open(const QString& file_name, const QString& wnd_tag , const QString& arg )
 {
     CGExplorerWnd* pwnd=(CGExplorerWnd*)GetActiveWnd();
     if(pwnd && pwnd->inherits("CGExplorerWnd"))
     {
         QJsonObject json =UnqFunc()->Str2Json(arg );
         pwnd->Open(file_name,  wnd_tag ,json);
     }
     return NULL;
 }

void CGEApp::InitWebChannel()
{
    if(m_ArgsMap.find("nobase")!=m_ArgsMap.end()){
         gInfo("--------nobase no need init WebSrv  -------- ");
        return;
    }
#ifdef WEBVIEW
    gInfo("--------init WebSrv  start -------- ");
    if(m_pServer)
        delete m_pServer;
    if(m_pChannel)
        delete m_pChannel;
 
    m_pServer= new QWebSocketServer(QStringLiteral("HmiWebSrv"), QWebSocketServer::NonSecureMode,this);
    if (!m_pServer->listen(QHostAddress::LocalHost, 12345)) {
        gInfo("---------Failed to open WebSrv socket ------.");
        return ;
    }
    WebSocketClientWrapper* clientWrapper=new WebSocketClientWrapper(m_pServer);
    m_pChannel=new QWebChannel(this);// setup the channel
    QObject::connect(clientWrapper, &WebSocketClientWrapper::clientConnected,m_pChannel, &QWebChannel::connectTo);
    m_pChannel->registerObject(QStringLiteral("qApp"), this);
	gInfo("--------init WebSrv  end -------- ");
#endif
}

void CGEApp::DeleteExplorerWnd(int graph_id)
{
    GExplorerWndMap::iterator pos;
    pos = m_pGExplorerWndMap.find(graph_id);
    if( pos != m_pGExplorerWndMap.end() )
        m_pGExplorerWndMap.erase(pos);

    if(m_pGExplorerWndMap.size()==0)
        m_pActiveExplorerWnd = NULL;
    else
        m_pActiveExplorerWnd = m_pGExplorerWndMap.begin()->second;

}

int CGEApp::GEWndInPosition( GDispInfo & graph_disp_info, QRect & rect , long wnd_id)
{

    if (graph_disp_info.new_wnd)
    {
        m_pActiveExplorerWnd = NULL;
        m_pCurMaxGraphID++;
        int wnd_flags=Qt::Window;
        m_pActiveExplorerWnd = new CGExplorerWnd(m_pCurMaxGraphID,graph_disp_info.wnd_style,0,(Qt::WindowFlags)wnd_flags);
        int real_wid=m_pActiveExplorerWnd->GetWndID();
        m_pGExplorerWndMap[real_wid] = m_pActiveExplorerWnd;

    }
    else
    {
        if ( wnd_id >= 0 )
        {
            GExplorerWndMap::iterator it = m_pGExplorerWndMap.find( wnd_id );
            if ( it != m_pGExplorerWndMap.end() )
            {
                m_pActiveExplorerWnd = it->second;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }

    }
    QDesktopWidget *dw = QApplication::desktop();
    if ( rect.isNull() )
        m_pActiveExplorerWnd->showMaximized();
    else
    {
        if ( dw->screenGeometry( m_pActiveExplorerWnd ) == rect )
        {
            m_pActiveExplorerWnd->showMaximized();
        }
        else
        {
            m_pActiveExplorerWnd->resize( rect.size() );
            m_pActiveExplorerWnd->move( rect.topLeft() );
            m_pActiveExplorerWnd->show();
            m_pActiveExplorerWnd->SaveWndGeometry();
        }

    }

    if( !graph_disp_info.graph_path_name.isEmpty())
    {
        QStringList files=graph_disp_info.graph_path_name.split(',');
        for(int i=0;i<files.size();i++)
            m_pActiveExplorerWnd->FileOpen(files[i], "",graph_disp_info.wnd_style,"",graph_disp_info.args);
    }

    m_pActiveExplorerWnd->raise();
    QRect cur_rect = dw->screenGeometry( m_pActiveExplorerWnd );

    return m_pActiveExplorerWnd->GetWndID();
}

void CGEApp::NewGraphWindow(GDispInfo & graph_disp_info)
{
    switch(graph_disp_info.wnd_type)
    {
    case Hmi::Explorer:
        NewExplorerWnd(graph_disp_info);
        break;
	case Hmi::Designer:
		NewDesignerWnd(graph_disp_info);
		break;
    default:
        return;
    }
}

QObject* CGEApp::NewWindow(const QVariant& args)
{
    QJsonObject obj;
    if (args.type() == QVariant::Map)
        obj = QJsonObject::fromVariantMap(args.toMap());
    else if (args.canConvert<QJsonObject>())
        obj = args.toJsonObject();

    if (obj.isEmpty())
    {
        return NULL;
    }

    m_pActiveExplorerWnd = NULL;
    m_pCurMaxGraphID++;
    int wnd_flags=-1;

    m_pActiveExplorerWnd = new CGExplorerWnd(m_pCurMaxGraphID,wnd_flags,0);
    m_pActiveExplorerWnd->SetArgs(args);
    int real_wid=m_pActiveExplorerWnd->GetWndID();
    m_pGExplorerWndMap[real_wid] = m_pActiveExplorerWnd;

    if (wnd_flags== Qt::FramelessWindowHint)
    {
        m_pActiveExplorerWnd->ShowFullScreen();
    }
    else
    {
        m_pActiveExplorerWnd->show();
    }


    if( !obj["file"].isUndefined())
    {
        QStringList files=obj["file"].toString().split(',');
        for(int i=0;i<files.size();i++)
            m_pActiveExplorerWnd->FileOpen(files[i], "",0,"",args);
    }
    m_pActiveExplorerWnd->raise();
    return m_pActiveExplorerWnd;
}

void CGEApp::NewExplorerWnd(GDispInfo & graph_disp_info)
{
    if (graph_disp_info.new_wnd)
    {
        m_pActiveExplorerWnd = NULL;
        m_pCurMaxGraphID++;
        int wnd_flags=graph_disp_info.wnd_style;

        m_pActiveExplorerWnd = new CGExplorerWnd(m_pCurMaxGraphID,graph_disp_info.wnd_style,0);
        int real_wid=m_pActiveExplorerWnd->GetWndID();
        m_pGExplorerWndMap[real_wid] = m_pActiveExplorerWnd;

        if (wnd_flags== Qt::FramelessWindowHint)
        {
            m_pActiveExplorerWnd->ShowFullScreen();
        }
        else
        {
            m_pActiveExplorerWnd->showMaximized();
            QDesktopWidget *dw = QApplication::desktop();
            QRect wndrect =  m_pActiveExplorerWnd->geometry();
            QRect scr_rect = dw->screenGeometry(m_pActiveExplorerWnd);
            //m_pActiveExplorerWnd->resize(QSize(scr_rect.width() - wndrect.x(), scr_rect.height() - wndrect.y()));

        }
    }

    if( !graph_disp_info.graph_path_name.isEmpty())
    {
        QStringList files=graph_disp_info.graph_path_name.split(',');
        for(int i=0;i<files.size();i++)
            m_pActiveExplorerWnd->FileOpen(files[i], "",graph_disp_info.wnd_style,"",graph_disp_info.args);
    }
    m_pActiveExplorerWnd->raise();
}

void CGEApp::NewDesignerWnd(GDispInfo & graph_disp_info)
{
	if (graph_disp_info.wnd_type == Hmi::Designer)
	{
        QString exePath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_BIN) + "gd.exe";
		if (!graph_disp_info.graph_path_name.isEmpty())
		{
			exePath.append(QString(" -pic %1").arg(graph_disp_info.graph_path_name));
		}
		UnqFunc()->SysExec(exePath);
	}
}

void CGEApp::timerEvent(QTimerEvent *e)
{
    m_TimerCount = (m_TimerCount + 1 ) % 1000000;
    if (m_TimerCount % 18 == 0)
    {
        ProcessChangeData();
    }

}

int CGEApp::ProcessChangeData(const QString & tag,const QVariant& val)
{
    CHG_DATA_MAP chg_val;
    chg_val[tag]=val;
    GExplorerWndMap::iterator wnd_it;
    CGExplorerWnd* ptmpWnd;
    QVector<CGraphView*> views;
    for(wnd_it = m_pGExplorerWndMap.begin(); wnd_it!= m_pGExplorerWndMap.end(); ++wnd_it)
    {
        ptmpWnd = wnd_it->second;
        views=ptmpWnd->GetGraphViews();
        foreach (CGraphView *pview, views)
        {
            if (pview->isVisible())
                ((CGExplorerView*)pview)->ProcessChangeData( chg_val );
        }

    }
    return 0;
}

int CGEApp::ProcessChangeData()
{
    GExplorerWndMap::iterator wnd_it;
    CGExplorerWnd* ptmpWnd;
    QVector<CGraphView*> views;
    CHG_DATA_MAP chg_val=GetChgDataMap();
    ResetChgDataMap();

    if (chg_val.size()==0 )
    {

        return 0;
    }

    for(wnd_it = m_pGExplorerWndMap.begin(); wnd_it!= m_pGExplorerWndMap.end(); ++wnd_it)
    {
        ptmpWnd = wnd_it->second;
        views=ptmpWnd->GetGraphViews();
        foreach (CGraphView *pview, views)
        {
            if (pview->isVisible())
                ((CGExplorerView*)pview)->ProcessChangeData( chg_val );
        }
    }
    return 0;
}

QObject* CGEApp::GetActiveWnd()
{
    if(activeWindow()&& activeWindow()->inherits("CGExplorerWnd") )
        return (QObject*)activeWindow();
    else if (m_pGExplorerWndMap.size()>0)
    {
        return m_pGExplorerWndMap.begin()->second;
    }
    else
        return NULL;
}


void DaemonThread::run()
{
    return;
   // gInfo("---------------- HMI--DaemonThread LoadIconInfo start--  ");
   // UnqFunc()->LoadIconInfo();
   // gInfo("---------------- HMI--DaemonThread LoadIconInfo end--  ");

    long loop=0;
    while(true)
    {
        loop = (loop + 1 ) % 1000000;

        if (loop % 18 == 0)
        {

        }
        if (loop % 40 == 0)
        {

        }
        msleep(50);

    }

}
