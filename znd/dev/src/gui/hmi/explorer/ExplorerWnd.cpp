
#include "Global.h"
#include "GFunc.h"
#include "GApp.h"
#include "AnimateDriver.h"
#include "ExplorerView.h"
#include "ExplorerScene.h"
#include "ExplorerWnd.h"

#include "CQScriptWrap.h"
#ifdef WIN32_OCX
#include <QAxFactory>
#endif


CGExplorerWnd::CGExplorerWnd(int wnd_id, int wnd_style,QWidget* parent, Qt::WindowFlags fl)
    :CGWnd(wnd_id,wnd_style,parent,fl)
{
    setObjectName("Window");
    EnableToolBar(false);
    EnableMenuBar(false);
    EnableStatusBar(false);
    m_FrameLess		= true;
	EnableDragMove(false);
	EnableBoxZoom(true);
    setAcceptDrops(true);
    //showMaximized();

#ifdef WIN32_OCX
    if(QAxFactory::isServer()) ((CGEApp*)qApp)->m_pGExplorerWndMap[wnd_id]=this;
#endif

    connect(m_pWorkspace, SIGNAL(subWindowActivated(QMdiSubWindow *)), this, SLOT(OnSubWindowActivated(QMdiSubWindow *)));
    m_pWorkspace->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_pWorkspace->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_pWorkspace->setOption(QMdiArea::DontMaximizeSubWindowOnActivation,true);

    //setTabPosition((Qt::DockWidgetAreas)Qt::BottomDockWidgetArea, QTabWidget::North);
/*
    QRect wndrect =  geometry();
    QDesktopWidget *dw = QApplication::desktop();
    QRect scr_rect = dw->screenGeometry(this);
    //resize(QSize(scr_rect.width() - wndrect.x(), scr_rect.height() - wndrect.y()));
*/
}

CGExplorerWnd::~CGExplorerWnd()
{
    m_Views.clear();

}

void CGExplorerWnd::OnSubWindowActivated(QMdiSubWindow * window)
{
    if (window == NULL)
        return;
	QString fileName = ""; 
	CGExplorerView *mdiChild = qobject_cast<CGExplorerView *>(window->widget());
	if (mdiChild)
		fileName = mdiChild->CurrentFile(true);
    emit SubWindowActivated(fileName);
}

CGExplorerView *CGExplorerWnd::ActiveMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = m_pWorkspace->activeSubWindow())
        return qobject_cast<CGExplorerView *>(activeSubWindow->widget());
    return 0;
}

CGExplorerView *CGExplorerWnd::CreateMdiChild()
{
    CGExplorerView *child = new CGExplorerView(this,NULL,m_pWorkspace);
    Qt::WindowFlags flags = 0;
    if (m_FrameLess)
        flags=Qt::FramelessWindowHint;
    m_pWorkspace->addSubWindow(child,flags);
    int margin=-1;
    child->parentWidget()->setContentsMargins(margin,margin,margin,margin);

    return child;
}

void CGExplorerWnd::AddSubWindow(QWidget* child)
{
    Qt::WindowFlags flags = 0;
    if (m_FrameLess)
        flags=Qt::FramelessWindowHint;
    m_pWorkspace->addSubWindow(child,flags);
    int margin=-1;
    child->parentWidget()->setContentsMargins(margin,margin,margin,margin);

}


QObject* CGExplorerWnd::ContentWindow(QString winID,QString file_name)
{
    return FindMdiChild( file_name, winID);
}

QObject* CGExplorerWnd::FileOpen(const QString& file_name, QString wnd_tag, int wnd_flags, QString replace_key, QVariant args)
{
    UnqFunc()->TmRestart();
    int ret=-1;
    CGExplorerView *child=NULL;
    QString file_path_name=file_name;
    if (file_name.isEmpty())
        return NULL;
	if (file_name.right(4) != PICSUFFIX && file_name.right(4) != PICBINARYSUFFIX)
    {
        file_path_name=file_name+PICSUFFIX;
    }
    if ( !QDir::isAbsolutePath( file_path_name ) )
        UnqFunc()->GetGraphPathNameByGraphName(file_path_name,file_path_name);

    if(! QFile::exists ( file_path_name ))
    {
        gInfo("HMI--Wnd--FileOpen can't find %s", file_path_name.toLocal8Bit().data());
        return NULL;
    }
    child = (CGExplorerView *)FindMdiChild(file_name);
	if (wnd_tag != "_blank"&& child)
	{
		child->show();
		((QWidget*)child->parent())->show();
		if (child->GetGraphScene()->GetLayoutRect().isEmpty())
		{
			m_pWorkspace->removeSubWindow((QMdiSubWindow *)child->parent());
		    child->setParent(this);
	    }
		else
			m_pWorkspace->setActiveSubWindow((QMdiSubWindow *)child->parent());
        return child;
    }


    if (wnd_flags==Qt::Dialog  )
    {
        child = new CGExplorerView(this,NULL,this,0);
    }
    else if (wnd_flags ==Qt::Sheet)
    {
        QDockWidget * pDockWnd = new QDockWidget( tr( " " ), this );
        pDockWnd->setAllowedAreas(Qt::NoDockWidgetArea);
        addDockWidget(Qt::LeftDockWidgetArea, pDockWnd);
        child = new CGExplorerView(this,NULL,this,0);
        pDockWnd->setWidget( child );
        pDockWnd->setFloating(true);
        pDockWnd->setWindowFlags(pDockWnd->windowFlags()|Qt::MSWindowsFixedSizeDialogHint);
    }
    else
    {
        if (!wnd_tag.isEmpty())
        {
            if(wnd_tag=="_blank")
            {
                child = CreateMdiChild();
            }
            else
            {
                child = (CGExplorerView *)FindMdiChild("",wnd_tag);
                if (!child)
                {
                    child = CreateMdiChild();
                }
                else
                    m_pWorkspace->setActiveSubWindow((QMdiSubWindow *)child->parent());
            }
        }
        else
        {
            child = (CGExplorerView *)FindMdiChild(file_name);
			if (child)
			{
				if (child->GetGraphScene()->GetLayoutRect().isEmpty())
				{
					m_pWorkspace->removeSubWindow((QMdiSubWindow *)child->parent());
				    child->setParent(this);
			    }
				else
					m_pWorkspace->setActiveSubWindow((QMdiSubWindow *)child->parent());
				
                return child;
            }
            child = CreateMdiChild();
        }
    }

    UnqFunc()->TmDebug("----start Wnd::FileOpen--"+file_name);
    ret=child->FileOpen(file_path_name,replace_key,wnd_flags,args);
    if (!wnd_tag.isEmpty() && child->GetWndAlais().isEmpty()) //child->FileOpen(file_name,replace_key,wnd_flags,args); already  SetWndAlais
        child->SetWndAlais(wnd_tag);
    child->show();
    QMdiSubWindow* parent=qobject_cast<QMdiSubWindow *>(child->parent());
    if(parent)
    {
        parent->show();
		if (args.toMap().value("wndTitle").isValid())
			parent->setWindowTitle(args.toMap().value("wndTitle").toString());
        else{
            QString g_core_name;
            UnqFunc()->GetGraphCoreNameByGraphPathName(file_path_name,g_core_name);
            parent->setWindowTitle(g_core_name);
        }
		if (child->GetGraphScene()->GetLayoutRect().isEmpty())
		{
			m_pWorkspace->removeSubWindow(parent);
			child->setParent(this);
            ClearRecentFilesAction(file_path_name);
		}
    }

    UnqFunc()->TmDebug("--end Wnd::FileOpen--");
    return child;
}

QObject* CGExplorerWnd::Open(const QString& file_name, const QString& wnd_tag, const QVariant& jobjArgs )
{
    QJsonObject jobj;
    if (jobjArgs.type() == QVariant::Map)
        jobj=QJsonObject::fromVariantMap(jobjArgs.toMap());
    else if(jobjArgs.canConvert<QJsonObject>())
        jobj=jobjArgs.toJsonObject();

    //QString scenetype =jobj["scenetype"].toString();
    QString wndflag =jobj["wndflag"].toString();
    QString replace_key =jobj["rkey"].toString();
    //QString args =jobj["args"].toString();

    int wnd_idx =-99;
	if (jobj.find("wndidx")!=jobj.end())
        wnd_idx =jobj["wndidx"].toInt();

    int wnd_flags=0;
    if(wndflag=="dialog")
        wnd_flags=Qt::Dialog;
    else if(wndflag=="widget")
        wnd_flags=Qt::Widget;


    QObject* ret=NULL;

    gInfo( "HMI--Wnd--FileOpen %s",file_name.toLocal8Bit().data());
    if ( wnd_idx >=-1 && wnd_idx <10)
    {
        GExplorerWndMap *pMap = ((CGEApp*)qApp)->GetGEWndMap();
        GExplorerWndMap::const_iterator pIter;
        for ( pIter = pMap->begin(); pIter != pMap->end(); ++pIter )
        {
            CGExplorerWnd *pWnd = pIter->second;
            int sidx=pWnd->GetScreenIndex().toInt();
            if(wnd_idx==sidx || wnd_idx==-1)
            {
                ret=pWnd->FileOpen( file_name, wnd_tag,wnd_flags,replace_key,jobjArgs);
            }
        }
    }
    else
    {
        ret=FileOpen( file_name, wnd_tag,wnd_flags,replace_key,jobjArgs);
    }

    return ret;

}

void CGExplorerWnd::FileOpen(bool isBinary)
{
    QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC);
	QString filter = PICSUFFIX;
	if (isBinary)
		filter = PICBINARYSUFFIX;
	
    QString fileName = QFileDialog::getOpenFileName(NULL, tr("open File"),
		path, QString("pic(*%1)").arg(filter));


    if (!fileName.isEmpty())
    {
        FileOpen(fileName,"");
        return;
    }
    return;

}

QObjectList CGExplorerWnd::Load(QString file_name)
{
	QList<QObject*> retLst;
	if (file_name.isEmpty())
		return retLst;
	if (file_name.right(4) != PICSUFFIX && file_name.right(4) != PICBINARYSUFFIX)
	{
		file_name += PICSUFFIX;
	}
	if (!QDir::isAbsolutePath(file_name))
		UnqFunc()->GetGraphPathNameByGraphName(file_name, file_name);
	QFile dir;
	if (!dir.exists(file_name))
	{
		gInfo("HMI--Wnd--FileOpen can't find %s", file_name.toLocal8Bit().data());
		return retLst;
	}
	CGExplorerScene* pScene = new CGExplorerScene(0);
	retLst.append((QObject*)pScene);
	
	pScene->FileOpen(file_name);	
	foreach(QGraphicsItem *item, pScene->Items(true, false))
	{
		CBaseData* pdata = g_dataPtr(item);
		if (pdata)
		{
			retLst.append((QObject*)pdata);
		}
	}
	return retLst;
}

QVariant CGExplorerWnd::DoCmd(QString wnd_name, QString file_name, QString script_code, int wnd_idx)
{
    QVariant ret="";
    if ( wnd_idx >=-1 && wnd_idx <10)
    {
        GExplorerWndMap *pMap = ((CGEApp*)qApp)->GetGEWndMap();
        GExplorerWndMap::const_iterator pIter;
        for ( pIter = pMap->begin(); pIter != pMap->end(); ++pIter )
        {
            CGExplorerWnd *pWnd = pIter->second;
            int sidx=pWnd->GetScreenIndex().toInt();
            if(wnd_idx==sidx || wnd_idx==-1)
            {
                CGraphView *tmpView=pWnd->FindMdiChild(file_name,wnd_name);
                if (tmpView==NULL)
                {
					gError("Wnd::DoCmd Can not find the view %s, in cur screen index=%d", file_name.toLocal8Bit().data(), sidx);
                }
                else
                {
                    ret=tmpView->DoCmd(script_code);
                }
            }
            //gInfo(  "HMI--Wnd--DoCmd-ret=%s",ret.toLocal8Bit().data());
        }
    }
    else
    {
        if(wnd_name=="allviews")
        {
            for(int i=0;i<m_Views.size();i++)
            {
                ret=m_Views.at(i)->DoCmd(script_code);
            }
        }
        else
        {
            CGraphView *tmpView=FindMdiChild(file_name,wnd_name);
            if (tmpView==NULL)
            {
                gError("Wnd::DoCmd Can not find the self view  " );
            }
            else
            {
                ret=tmpView->DoCmd(script_code);
            }
        }

    }


    return ret;
}

void CGExplorerWnd::FileNewScriptDebuggerWin()
{
 /*   if (ActiveMdiChild() == NULL)
        return;

    if (!m_debugger) {
        m_debugger = new QScriptEngineDebugger(this);
        m_debugWindow = m_debugger->standardWindow();
        m_debugWindow->setWindowModality(Qt::NonModal);
        m_debugWindow->resize(1280, 704);
    }
    CScriptEngine* pse=ActiveMdiChild()->Scene()->GetScriptEngine();
    //pse->reset();
    m_debugger->attachTo((QScriptEngine*)(pse));
    m_debugger->action(QScriptEngineDebugger::InterruptAction)->trigger();

    pse->LoadFile(QString("hmiCommon.js"));
    QString code = ActiveMdiChild()->Scene()->GetScript();
    if (!code.isEmpty() )
    {        
        pse->Evaluate(code);
    }
    */
}

void CGExplorerWnd::closeEvent ( QCloseEvent * e )
{
    m_pWorkspace->closeAllSubWindows();
    if (ActiveMdiChild())
    {
        e->ignore();
    } else {

        e->accept();
    }

    ((CGEApp*)qApp)->DeleteExplorerWnd( GetWndID() );
    delete this;
}


QVariant CGExplorerWnd::OpenMultiScreen( QStringList file_list, int screen_width , int mode )
{
    QList<QVariant> result;
    int graph_nums = file_list.size();

    if ( graph_nums == 0 )
    {
        return result;
    }

    QDesktopWidget *dwWidget = QApplication::desktop();
    int total_scr = graph_nums;
    int numScrs = dwWidget->numScreens();

    if ( graph_nums > numScrs )
        total_scr = numScrs;
    QRect rect;

    int need_new_win = 1;
    int nWndIndex = dwWidget->screenNumber( this );

    QRect own_rect = dwWidget->screenGeometry( this );

    for ( int n = 0 ; n < total_scr; n++ )
    {

        rect = dwWidget->screenGeometry( n );

        int rx = rect.topLeft().x();
        int ry = rect.topLeft().y();
        int width = rect.width();
        int height = rect.height();

        if ( nWndIndex == n )
            need_new_win = 0;
        else
            need_new_win = 1;

        if ( mode )
        {
            int winid = GEWinInPosition( file_list[n], rx, ry, width, height, need_new_win);
            if ( winid > 0 )
            {
                result.push_back( winid );
            }
        }
        else
        {
            int single_scr = rect.width()%screen_width;
            if ( rect.width() == screen_width )
            {
                single_scr=1;
            }
            int log_scrs = single_scr?1:(rect.width()/screen_width);
            for ( int loop = 0; loop < log_scrs; ++loop)
            {
                int winid = -1;
                if ( single_scr ==1 )
                {
                    winid = GEWinInPosition( file_list[n], rx, ry, width, height, need_new_win);

                }
                else
                {
                    rx += loop*screen_width;
                    width = screen_width;

                    winid = GEWinInPosition( file_list[n], rx, ry, width, height, need_new_win);
                }
                if ( winid > 0 )
                {
                    result.push_back( winid );
                }
                need_new_win=1;
            }
        }
    }
    return result;
}

int CGExplorerWnd::GEWinInPosition( const QString & file_name, int x, int y, int width, int height, int newwin)
{
    QRect rect( x,y,width,height);
    if ( !rect.isValid() )
        return -1;
    GDispInfo graph_disp_info;
    graph_disp_info.graph_path_name=file_name;
    graph_disp_info.app_id = m_GDispInfo.app_id ;
    long wnd_id = -1;
    if ( newwin == 0 )
    {
        graph_disp_info.new_wnd = false;
        wnd_id = GetWndID();
    }

    int retcode = ((CGEApp*)qApp)->GEWndInPosition(graph_disp_info, rect, wnd_id );
    return retcode;
}

int CGExplorerWnd::PutData(const QVariant& jsonStr,CHG_DATA_MAP& chgdata)
{
    QJsonArray jsonArrays;
    if(jsonStr.type() == QVariant::String){
        QJsonParseError error;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toString().toUtf8(), &error);
        if (error.error == QJsonParseError::NoError) {
            if (!(jsonDoc.isNull() || jsonDoc.isEmpty())) {
                if (jsonDoc.isObject()) {
                    gInfo("--pls use QJsonArray---") ;
                    return -1;
                }
                else if (jsonDoc.isArray()){
                    jsonArrays = jsonDoc.array();

                }
            }
        }
        else {
            gInfo("--PutData --QJsonParseError:%s-",error.errorString().toLocal8Bit().data()) ;
            return -1;
        }
    }
    else if(jsonStr.type() == QVariant::List ){
        jsonArrays= QJsonArray::fromVariantList(jsonStr.toList());
    }

    foreach(QJsonValue jsonv, jsonArrays)
    {
        QJsonObject jobj = jsonv.toObject();
        QStringList vs;
        vs << jobj["v"].toString() << jobj["s"].toString();
        chgdata.insert(jobj["tag"].toString(), vs);
    }

    return 0;
}


void CGExplorerWnd::SetData(const QVariant& jsonStr,bool reflash)
{
    CHG_DATA_MAP  chg_val;
    PutData( jsonStr, chg_val);
    QVector<CGraphView*> views= GetGraphViews();
    foreach (CGraphView *pview, views)
    {
        if (pview->isVisible())
            ((CGExplorerView*)pview)->ProcessChangeData( chg_val );
    }
}

void CGExplorerWnd::dragEnterEvent(QDragEnterEvent * event)
{
    event->accept();
}

void CGExplorerWnd::dropEvent(QDropEvent * event)
{
    QPoint pos=event->pos();
    QString msg=event->mimeData()->text();
    QStringList formats=event->mimeData()->formats();

    event->acceptProposedAction();
    QMainWindow::dropEvent(event);

    emit DropEvent(0, msg);
}

QObject* CGExplorerWnd::EnableComponent(const QString& componentName, int ifvisiable )
{
    if(componentName.contains("websrv",Qt::CaseInsensitive))
    {
        ((CGEApp*)qApp)->InitWebChannel();
        return NULL;
    }
    else
    {
        CGWnd::EnableComponent(componentName,   ifvisiable);
    }
}

void CGExplorerWnd::EnableDragMove(bool enable)
{
	m_canDragMoveView = enable;
	if (m_canBoxZoom)
		m_canBoxZoom = !enable;
}
void CGExplorerWnd::EnableBoxZoom(bool enable)
{
	m_canBoxZoom = enable;
	if (m_canDragMoveView)
		m_canDragMoveView = !enable;
}
