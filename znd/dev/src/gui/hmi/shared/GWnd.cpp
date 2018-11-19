#include "Global.h"
#include "GFunc.h"
#include "GApp.h"
#include "GraphView.h"
#include "GraphScene.h"
#include "GWnd.h"
#include "CQScriptWrap.h"
#include "CManhattanStyle.h"
#include "CQWidgetWrap.h"
#include <QPrintDialog>
#include <QPrinter>


const int CGWnd::MaxRecentFiles = 20;
const QString CGWnd::RecentFilesSettingTag = "recentFiles";
CGWnd::CGWnd(int wnd_id, int wnd_style,QWidget* parent, Qt::WindowFlags fl)
    :QMainWindow( parent, fl ), m_WndID(wnd_id), m_WndType(wnd_style),m_pGeometry(0)
{
    setObjectName("Window");
    Init();
    //StyleMotif();
	m_beUpdateLst = true;
	m_curViewPos = -1;
}

int CGWnd::LoadCss(const QString& filename)
{
    QFile file(UnqFunc()->GetDir(CGFunc::PATH_TYPE_CSS)+filename);
    if (file.open(QFile::ReadOnly))
    {
        QString qssStr = QString(file.readAll());
        qssStr.replace("@", UnqFunc()->GetSysHome().replace("\\","/"), Qt::CaseInsensitive);
        qApp->setStyleSheet(qssStr);
        return 1;
    }
    return -1;
}

int CGWnd::LoadCssString(const QString& css)
{
    QString qssStr=css;
    qssStr.replace("@", UnqFunc()->GetSysHome().replace("\\","/"), Qt::CaseInsensitive);
    qApp->setStyleSheet(qssStr);
    return 1;

}

int CGWnd::Init()
{
    m_debugger = NULL;
    m_WndFullScreen =false;
    m_FrameLess = false;
    m_pNaviDockWnd = NULL;
    m_nLastShowMode =0;    
    m_pWorkspace = new QMdiArea(this);
    m_pWorkspace->setObjectName("work_space");
    m_pWorkspace->setBackground(Qt::black);
    m_pWorkspace->setTabsClosable(true);
    m_pWorkspace->setTabsMovable(true);

    setCentralWidget(m_pWorkspace);

    m_pFileOpenAction = NULL;
	m_pFileOpenBinaryAction = NULL;

    m_recentFilesActions = new QAction*[CGWnd::MaxRecentFiles];
    SetupBaseActions();
    SetupBaseMenuBar();
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    QString iconbuf;
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, "com_open.png", iconbuf);
    QAction* m_pWinNewScriptDebuggerWinAction = new QAction(QPixmap(iconbuf), tr("ScriptDebugger"), this);
    connect( m_pWinNewScriptDebuggerWinAction, SIGNAL(triggered()), this, SLOT(OpenDebugWnd()));
    m_pFileMenu->addAction(m_pWinNewScriptDebuggerWinAction);
    return 0;
}

CGWnd::~CGWnd()
{
    if (m_debugger)
        m_debugger->detach();
    if ( m_pGeometry )
    {
        delete m_pGeometry;
        m_pGeometry = NULL;
    }
}


QVariant CGWnd::DoCmd(QString wnd_name, QString file_name, QString script_code, int wnd_idx)
{
    QVariant ret="";

        CGraphView *tmpView=FindMdiChild(file_name,wnd_name);
        if (tmpView==NULL)
        {
            ret="Can not find the view.";
        }
        else
        {
            ret=tmpView->DoCmd(script_code);
        }



    return ret;
}

CGraphView *CGWnd::FindMdiChild(const QString &file_name,const QString& wnd_tag)
{
    QString tmpstr;
    QString fileName;
    //UnqFunc()->GetGraphCoreNameByGraphPathName(file_name,fileName);

    for(int i=0;i<m_Views.size();i++)
    {
        CGraphView* pview= m_Views.at(i);
        if (!wnd_tag.isEmpty())
        {
            if (pview->GetWndAlais()==wnd_tag)
                return pview;
        }
        tmpstr=pview->CurrentFile(true);
		if (!file_name.isEmpty() && tmpstr.contains(file_name))
             return pview;
        /*
        UnqFunc()->GetGraphCoreNameByGraphPathName(tmpstr,tmpstr);
        if (!fileName.isEmpty() && (tmpstr==fileName))
            return pview;*/
    }
    return 0;
}

QObject* CGWnd::ContentWindow(QString winID,QString file_name)
{
    return FindMdiChild( file_name, winID);
}


QObject* CGWnd::ActiveWindow()
{
    CGraphView* pView=NULL;
    if (QMdiSubWindow *window = m_pWorkspace->activeSubWindow())
    {
        pView = window->widget()->findChild<CGraphView*>();
    }
    return pView;
}




void CGWnd::FileOpen(bool isBinary)
{

}

void CGWnd::FileOpenBinary()
{
	FileOpen(true);
}

QObject* CGWnd::AddDockWidget(QObject* obj,const QString& dockArea,QString title)
{
    if(!obj->inherits("QWidget"))
        return NULL;
    int  dockflag=0;
    if(dockArea=="left")
        dockflag=Qt::LeftDockWidgetArea;
    else if(dockArea=="right")
        dockflag=Qt::RightDockWidgetArea;
    else if(dockArea=="top")
        dockflag=Qt::TopDockWidgetArea;
    else if(dockArea=="bottom")
        dockflag=Qt::BottomDockWidgetArea;
    else if(dockArea=="all")
        dockflag=Qt::AllDockWidgetAreas;
    else if(dockArea=="no")
        dockflag=Qt::NoDockWidgetArea;

    QDockWidget * pDockWnd = new QDockWidget( title , this);
    pDockWnd->setObjectName(title);
    pDockWnd->setAllowedAreas(Qt::AllDockWidgetAreas);
    //setTabPosition((Qt::DockWidgetAreas)Qt::BottomDockWidgetArea, QTabWidget::North);

    pDockWnd->setWindowFlags(pDockWnd->windowFlags()|Qt::MSWindowsFixedSizeDialogHint);

    if(obj->inherits("CGraphView"))
    {
        CGraphView * pview = qobject_cast<CGraphView *>(obj) ;
        QMdiSubWindow* psubWin = qobject_cast<QMdiSubWindow *>(pview->parentWidget());
        pDockWnd->setWidget(qobject_cast<QWidget *>(obj));
        //pview->scene()->backgroundBrush();
        if (psubWin)
        {
            psubWin->setGeometry(0, 0, 0, 0);
            m_pWorkspace->removeSubWindow(psubWin);
            delete psubWin;
			ClearRecentFilesAction(pview->CurrentFile(true));
        }

        pview->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        if ( pview->verticalScrollBar() )
            pview->verticalScrollBar()->setSliderPosition( 0 );
        if ( pview->horizontalScrollBar() )
            pview->horizontalScrollBar()->setSliderPosition( 0 );

    }
    else
        pDockWnd->setWidget(qobject_cast<QWidget *>(obj));

    addDockWidget(Qt::DockWidgetArea(dockflag), pDockWnd);

    pDockWnd->setFloating(true);
    pDockWnd->setFloating(false);
    return pDockWnd;
}

void CGWnd::FileNewGEWin()
{
    QString file_path_name="";
    FileNewWindow(file_path_name,Hmi::Explorer);
}

void CGWnd::FileNewGDWin()
{
	QString file_path_name = "";
	CGraphView* pView = (CGraphView*)ActiveWindow();
	if (pView)
		file_path_name = pView->CurrentFile();
    FileNewWindow(file_path_name,Hmi::Designer);
}


QString CGWnd::GetScreenIndex()
{
    QDesktopWidget *dwWidget = QApplication::desktop();
    int nScreenIndex = dwWidget->screenNumber( this );
    return QString::number( nScreenIndex );
}

QString CGWnd::GetScreenCount()
{
    QDesktopWidget *dwWidget = QApplication::desktop();
    int nScreenCount = dwWidget->numScreens();
    return QString::number( nScreenCount );
}

void CGWnd::SetupBaseActions()
{
    QString iconbuf;
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, "com_open.png", iconbuf);
    m_pFileOpenAction = new QAction(QPixmap( iconbuf ), tr( "Open" ),this);
    m_pFileOpenAction->setShortcut( tr( "Ctrl+O" ) );
    connect( m_pFileOpenAction, SIGNAL( triggered() ), this, SLOT( FileOpen() ) );

	m_pFileOpenBinaryAction = new QAction(QPixmap(iconbuf), tr("OpenBinary"), this);
	m_pFileOpenBinaryAction->setShortcut(tr("Ctrl+O+B"));
	connect(m_pFileOpenBinaryAction, SIGNAL(triggered()), this, SLOT(FileOpenBinary()));

    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, "com_open.png", iconbuf);
    m_pWinNewGDWinAction = new QAction(QPixmap( iconbuf ), tr( "New Creator" ),this);

    m_pWinNewGDWinAction->setShortcut( tr( "Ctrl+D" ) );

    connect( m_pWinNewGDWinAction, SIGNAL( triggered() ), this, SLOT( FileNewGDWin() ) );


    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, "com_open.png", iconbuf);
    m_pWinNewGEWinAction = new QAction(QPixmap( iconbuf ), tr( "New Viewer" ),this);
    m_pWinNewGEWinAction->setShortcut( tr( "Ctrl+V" ) );
    connect( m_pWinNewGEWinAction, SIGNAL( triggered() ), this, SLOT( FileNewGEWin() ) );

    tileAct = new QAction(tr("Tile"), this);
    tileAct->setStatusTip(tr("Tile the windows"));
	tileAct->setCheckable(true);

    cascadeAct = new QAction(tr("Cascade"), this);
    cascadeAct->setStatusTip(tr("Cascade the windows"));
	cascadeAct->setCheckable(true);

	tabbedAct = new QAction(tr("Tabbed"), this);
	tabbedAct->setStatusTip(tr("Tabbed the windows"));
	tabbedAct->setCheckable(true);
	tabbedAct->setChecked(true);

	m_pViewActions = new QActionGroup(this);
	m_pViewActions->addAction(tileAct);
	m_pViewActions->addAction(cascadeAct);
	m_pViewActions->addAction(tabbedAct);
	
	connect(m_pViewActions, SIGNAL(triggered(QAction*)), this, SLOT(OnViewWindows(QAction*)));

    nextAct = new QAction(tr("Next"), this);
    nextAct->setStatusTip(tr("Move the focus to the next window"));
    connect(nextAct, SIGNAL(triggered()), m_pWorkspace, SLOT(activateNextSubWindow()));

    previousAct = new QAction(tr("Previous"), this);
    previousAct->setStatusTip(tr("Move the focus to the previous window"));
    connect(previousAct, SIGNAL(triggered()),m_pWorkspace, SLOT(activatePreviousSubWindow()));

    closeAct = new QAction(tr("Close"), this);
    closeAct->setStatusTip(tr("Close the active window"));
    connect(closeAct, SIGNAL(triggered()),m_pWorkspace, SLOT(closeActiveSubWindow()));

    closeAllAct = new QAction(tr("Close All"), this);
    closeAllAct->setStatusTip(tr("Close all the windows"));
    connect(closeAllAct, SIGNAL(triggered()), m_pWorkspace, SLOT(closeAllSubWindows()));

    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, "com_print.png", iconbuf);
    m_pFilePrintAction = new QAction(QPixmap(iconbuf),tr("FilePrint"), this);
    m_pFilePrintAction->setStatusTip(tr("FilePrint"));
    connect(m_pFilePrintAction, SIGNAL(triggered()), this, SLOT(FilePrint()));


    m_pHelpAboutGraphAction = new QAction( this);
    m_pHelpAboutGraphAction->setText( tr( "About" ) );
    connect( m_pHelpAboutGraphAction, SIGNAL( triggered() ), this, SLOT( HelpAboutGraph() ) );

    m_pHelpWhatsThisAction = new QAction( this);
    m_pHelpWhatsThisAction->setText( tr( "WhatsThis" ) );

    m_pActionGroupTools = new QActionGroup( this );
    m_pActionGroupTools->setExclusive( true );


    for (int i = 0; i<CGWnd::MaxRecentFiles; ++i)
    {
        m_recentFilesActions[i] = new QAction(this);
        m_recentFilesActions[i]->setVisible(false);
        connect(m_recentFilesActions[i], SIGNAL(triggered()), this, SLOT(OnOpenRecentFile()));
    }

}
void CGWnd::OnViewWindows(QAction* act)
{
	act->setChecked(true);
	if (act == tabbedAct)
	{
		m_pWorkspace->setViewMode(QMdiArea::TabbedView);
	}
	else if (act == tileAct)
	{
		m_pWorkspace->setViewMode(QMdiArea::SubWindowView);
		m_pWorkspace->tileSubWindows();
	}	
	else if (act == cascadeAct)
	{
		m_pWorkspace->setViewMode(QMdiArea::SubWindowView);
		m_pWorkspace->cascadeSubWindows();
	}
}
void CGWnd::OnStyleChanged(QAction* act)
{
	act->setChecked(true);
	QString name = act->text();
	if (name == "Windows")
	{
		qApp->setStyleSheet("");
		StyleWindows();
	}
	else if (name == "Motif")
	{
		qApp->setStyleSheet("");
		StyleMotif();
	}
	else if (name == "Fusion")
	{
		qApp->setStyleSheet("");
		StyleWin7();
	}
	else if (name == "Vista")
	{	
		qApp->setStyleSheet("");
		StyleVista();
	}
	else if (name == "Mac")
	{
		qApp->setStyleSheet("");
		StyleMac();
	}
	else if (name == tr("Custom"))
	{
		emit CustomStyle();
	}
}
void CGWnd::SetupBaseMenuBar()
{
    m_pFileMenu = menuBar()->addMenu(tr( "File(&F)" ));
    m_pFileMenu->addAction(m_pFileOpenAction);
	m_pFileMenu->addAction(m_pFileOpenBinaryAction);
    m_pFileMenu->addAction(m_pWinNewGDWinAction);
    m_pFileMenu->addAction(m_pWinNewGEWinAction);
    m_pFileMenu->addAction(m_pFilePrintAction);
    m_pFileMenu->addSeparator();

    m_pWndMenu = menuBar()->addMenu(tr("Window(&V)"));
    m_pWndMenu->addAction(tileAct);
    m_pWndMenu->addAction(cascadeAct);
	m_pWndMenu->addAction(tabbedAct);
    m_pWndMenu->addSeparator();
    m_pWndMenu->addAction(nextAct);
    m_pWndMenu->addAction(previousAct);
    m_pWndMenu->addAction(closeAct);
    m_pWndMenu->addAction(closeAllAct);

    m_pHelpMenu = menuBar()->addMenu( tr("Help(&H)" ));
    m_pHelpMenu->addAction(m_pHelpAboutGraphAction);
    m_pHelpMenu->addAction(m_pHelpWhatsThisAction);

    m_pStyleMenu = menuBar()->addMenu(tr("Wnd Style(&S)"));

	m_pStyleActions = new QActionGroup(this);

	QAction* winAct = new QAction(("Windows"), this);
	winAct->setCheckable(true);
	QAction* motifAct = new QAction(("Motif"), this);
	motifAct->setCheckable(true);
	QAction* fusionAct = new QAction(("Fusion"), this);
	fusionAct->setCheckable(true);
	QAction* vistaAct = new QAction(("Vista"), this);
	vistaAct->setCheckable(true);
	QAction* macAct = new QAction(("Mac"), this);
	macAct->setCheckable(true);

	QAction* customAct = new QAction(tr("Custom"), this);
	customAct->setCheckable(true);
	customAct->setChecked(true);

	m_pStyleActions->addAction(winAct);
	m_pStyleActions->addAction(motifAct);
	m_pStyleActions->addAction(fusionAct);
	m_pStyleActions->addAction(vistaAct);
	m_pStyleActions->addAction(macAct);
	m_pStyleActions->addAction(customAct);

	connect(m_pStyleActions, SIGNAL(triggered(QAction*)), this, SLOT(OnStyleChanged(QAction*)));
	m_pStyleMenu->addAction(winAct);
	m_pStyleMenu->addAction(motifAct);
	m_pStyleMenu->addAction(fusionAct);
	m_pStyleMenu->addAction(vistaAct);
	m_pStyleMenu->addAction(macAct);
	m_pStyleMenu->addAction(customAct);
	m_pStyleMenu->addSeparator();
	
	QAction* fullScrnAct = new QAction(tr("FullScreen"), this);
	fullScrnAct->setCheckable(true);
	connect(fullScrnAct, SIGNAL(triggered()), this, SLOT(StyleFullScreen()));
	m_pStyleMenu->addAction(fullScrnAct);

}

void CGWnd::SetUpRecentFilesAction()
{
    /*QSettings settings;
    QStringList files = settings.value(CGWnd::RecentFilesSettingTag).toStringList();*/

	const int numRecentFiles = qMin(m_recentFiles.size(), CGWnd::MaxRecentFiles);
    for (int i = 0; i<numRecentFiles; ++i)
    {
		QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(m_recentFiles[i]).fileName());
        QAction* action = getRecentFilesActions()[i];
        action->setText(text);
		action->setData(m_recentFiles[i]);
        action->setVisible(true);
    }
    for (int j = numRecentFiles; j <CGWnd::MaxRecentFiles; ++j)
        getRecentFilesActions()[j]->setVisible(false);

}

void CGWnd::ClearRecentFilesAction(QString fileName)
{
	//QSettings settings;
	if (fileName == "")
		//settings.setValue(CGWnd::RecentFilesSettingTag, QStringList());
		m_recentFiles.clear();
	else
	{
		//QStringList files = settings.value(CGWnd::RecentFilesSettingTag).toStringList();
		m_recentFiles.removeAll(fileName);
		//settings.setValue(CGWnd::RecentFilesSettingTag, files);
	}
	SetUpRecentFilesAction();
}

void CGWnd::OnOpenRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (!action)
        return;
    QString fileName = action->data().toString();
    if (!QDir::isAbsolutePath(fileName))
        UnqFunc()->GetGraphPathNameByGraphName(fileName, fileName);
    QFileInfo info(fileName);
    if (!info.exists() || !info.isFile())
    {
        QMessageBox::warning(this, "Open", "File is not exist!");
        return;
    }
    if (!info.isReadable())
    {
        QMessageBox::warning(this, "Open", "Can not open file!");
        return;
    }
    this->Open(fileName);
    //OnFileOpen(fileName);
}

void CGWnd::UpdateRecentFiles(QString fileName)
{
	if (!m_beUpdateLst || fileName.endsWith(ICONSUFFIX))
		return;
    /*QSettings settings;
    QStringList files = settings.value(CGWnd::RecentFilesSettingTag).toStringList();*/
	if (m_curViewPos < 0 ){//for designer
		m_recentFiles.removeAll(fileName);
		m_recentFiles.prepend(fileName);
	}
	else
	{
		int pos = m_curViewPos;//m_recentFiles.indexOf(m_CurFile);
		int len = m_recentFiles.size();
		for (int i = 0; i<pos; i++)
		{
			m_recentFiles.removeAt(0);
		}
		m_recentFiles.prepend(fileName);
	}
	m_curViewPos = -1;
	while (m_recentFiles.size() > CGWnd::MaxRecentFiles)
		m_recentFiles.removeLast();
    //settings.setValue(CGWnd::RecentFilesSettingTag, files);

    SetUpRecentFilesAction();
}

QMenu* CGWnd::GetBaseMenu(BASE_MENU_TYPE menuType)
{
    if(menuType== FILEMENU)
        return m_pFileMenu;
    else if(menuType==WNDMENU)
        return m_pWndMenu;
    else if(menuType==STYLEMENU)
        return m_pStyleMenu;
    else if(menuType==HELPMENU)
        return m_pHelpMenu;
    else
        return NULL;
}

QWidget* CGWnd::AddMenu(const QStringList& info)
{
    QMenu * pMenu=NULL;
    QString iconPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON);
    if(info.size()>0)
    {
        pMenu = menuBar()->addMenu(info.at(0));
        for(int i=1;i<info.size();i++)
        {
            QStringList slist= info.at(i).split(",");
            if (slist.size()>1)
            {
                QAction* act=pMenu->addAction(QPixmap(iconPath + slist[1]), slist[0]);
                if(slist.size()>2)
                    act->setData(slist[2]);
            }
            else
                pMenu->addSeparator();
        }
        connect(pMenu,SIGNAL(triggered(QAction * )),this,SLOT(OnMenuTriggered(QAction *)));
    }
    EnableMenuBar(true);
    return  pMenu;
}

QWidget* CGWnd::AddActicons(QString type,const QVariant& args)
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

    QString menu_txt = obj["text"].toString();
    QVariant menu_data = obj["data"].toVariant();
    QString iconFile = obj["icon"].toString();
    bool enable = true;
    if (obj.contains("enable"))
        enable = obj["enable"].toInt();
    QString tip = obj["tip"].toString();
    QString pathName = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON);

    QWidget * pMenu = NULL;

    if(type=="menu"){
        pMenu =  findChild<QMenu *>(menu_txt,Qt::FindChildrenRecursively);
        if(!pMenu)
            pMenu = menuBar()->addMenu(menu_txt);
		if (!iconFile.isEmpty())
			((QMenu *)pMenu)->setIcon(QIcon(pathName + iconFile));
    }
    else if(type=="toolbar"){
        pMenu =  findChild<QToolBar *>(menu_txt,Qt::FindChildrenRecursively);
        if(!pMenu)
            pMenu = new CGToolBar(menu_txt,this);
    }
    pMenu->setObjectName(menu_txt);
    pMenu->setEnabled(enable);
    pMenu->setToolTip(tip);
    QString ver = obj["ver"].toString(); ////菜单结构版本////
    QActionGroup * pgActions =NULL;
    if(!obj["group"].isNull()){
        pgActions = new QActionGroup(this);
    }

    if (!obj["children"].isNull())
    {
        QList<QVariant> childMenus = obj["children"].toVariant().toList();
        for (int j = 0; j < childMenus.size(); j++)
        {
            QJsonObject childObj;
            QVariant childPara = childMenus[j];
            if (childPara.type() == QVariant::Map)
                childObj = QJsonObject::fromVariantMap(childPara.toMap());
            else if (args.canConvert<QJsonObject>())
                childObj = args.toJsonObject();
            if (childObj.isEmpty())
            {
                //pMenu->addSeparator();
                continue;
            }
            QString menu_txt = childObj["text"].toString();
            QVariant menu_data = childObj["data"].toVariant();
            QString iconFile = childObj["icon"].toString();
            QIcon tmpicon;
            if(iconFile.startsWith("fa-")){
                 tmpicon=UnqAwe()->icon(iconFile.right(iconFile.length()-3) );
            }
            else{
                tmpicon=QPixmap(pathName+ iconFile);
            }

            bool enable = true;
            if (childObj.contains("enable"))
                enable = childObj["enable"].toInt();
            QString tip = childObj["tip"].toString();

            if(ver=="1.0"){
                menu_data=childPara;
            }            

            QAction *childAct = NULL;
            if(type=="menu")
                childAct = ((QMenu *)pMenu)->addAction(tmpicon, menu_txt);
            else if(type=="toolbar"){
                menu_data=childPara;
                childAct = ((QToolBar *)pMenu)->addAction(tmpicon, menu_txt);
            }
            childAct->setData(menu_data);
            childAct->setEnabled(enable);
            childAct->setToolTip(tip);
			if (childObj.contains("checked")){
				childAct->setCheckable(true);
				childAct->setChecked(childObj["checked"].toInt());
			}
            if(pgActions){
                childAct->setCheckable(true);
                pgActions->addAction(childAct);
            }
        }
    }
    if(type=="menu")
        connect(pMenu, SIGNAL(triggered(QAction *)), this, SLOT(OnMenuTriggered(QAction *)));
    else if(type=="toolbar")
        connect(pMenu, SIGNAL(actionTriggered(QAction *)), this, SLOT(OnMenuTriggered(QAction *)));
    return pMenu;
}

void CGWnd::AddMenuList(const QVariantList& menuList)
{
	for (int i = 0; i < menuList.size(); i++)
	{
		QVariant qPara = menuList[i];
        QMenu * pMenu = (QMenu *)AddActicons("menu",qPara);
	}
	EnableMenuBar(true);
}

void CGWnd::OnMenuTriggered(QAction * action)
{
    emit MenuTriggered(action->text(),action->data(),action);
}

QWidget* CGWnd::AddToolBar(const QVariant& args )
{
    QJsonObject jobj;
    if (args.type() == QVariant::Map)
        jobj = QJsonObject::fromVariantMap(args.toMap());
    else if (args.canConvert<QJsonObject>())
        jobj = args.toJsonObject();

    QString  toolbarArea=jobj["toolbarArea"].toString();
    int layoutDirection=jobj["layoutDirection"].isNull() ? Qt::LayoutDirectionAuto : jobj["layoutDirection"].toInt();
    bool ifbreak=jobj["break"].toBool(false);

    Qt::ToolBarArea area = Qt::TopToolBarArea;
    if (toolbarArea.contains("left",Qt::CaseInsensitive))
        area = Qt::LeftToolBarArea;
    else if(toolbarArea.contains("right",Qt::CaseInsensitive))
        area = Qt::RightToolBarArea;
    else if(toolbarArea.contains("top",Qt::CaseInsensitive))
        area = Qt::TopToolBarArea;
    else if(toolbarArea.contains("bottom",Qt::CaseInsensitive))
        area = Qt::BottomToolBarArea;
    else if(toolbarArea.contains("all",Qt::CaseInsensitive))
        area = Qt::AllToolBarAreas;
    else if(toolbarArea.contains("no",Qt::CaseInsensitive))
        area = Qt::NoToolBarArea;

    if(ifbreak) addToolBarBreak(area);
    QToolBar * ptoolbar = (QToolBar *)AddActicons("toolbar",args);
    if(!ptoolbar) return 0;
    ptoolbar->setAllowedAreas( Qt::AllToolBarAreas);
    ptoolbar->setLayoutDirection((Qt::LayoutDirection)layoutDirection);
    ptoolbar->setMovable(true);
    addToolBar(area, ptoolbar);
    m_allToolBars.append((QObject*)ptoolbar);
    return ptoolbar;

}

QWidget* CGWnd::AddToolBar(const QStringList& info,const QString&   toolbarArea,int layoutDirection)
{
    QToolBar * ptoolbar=NULL;
    Qt::ToolBarArea area = Qt::TopToolBarArea;
    if (toolbarArea.contains("left",Qt::CaseInsensitive))
        area = Qt::LeftToolBarArea;
    else if(toolbarArea.contains("right",Qt::CaseInsensitive))
        area = Qt::RightToolBarArea;
    else if(toolbarArea.contains("top",Qt::CaseInsensitive))
        area = Qt::TopToolBarArea;
    else if(toolbarArea.contains("bottom",Qt::CaseInsensitive))
        area = Qt::BottomToolBarArea;
    else if(toolbarArea.contains("all",Qt::CaseInsensitive))
        area = Qt::AllToolBarAreas;
    else if(toolbarArea.contains("no",Qt::CaseInsensitive))
        area = Qt::NoToolBarArea;

    QString iconPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON);
    if(info.size()>0)
    {
        ptoolbar = new QToolBar(info.at(0),this);
        ptoolbar->setObjectName(info.at(0));
        ptoolbar->setAllowedAreas( Qt::AllToolBarAreas);
        ptoolbar->setLayoutDirection((Qt::LayoutDirection)layoutDirection);
        ptoolbar->setMovable(true);
        addToolBar(area, ptoolbar);

        //ptoolbar->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        //ptoolbar->show();
        for(int i=1;i<info.size();i++)
        {
            QStringList slist= info.at(i).split(",");
            if (slist.size()>1)
            {
                QAction* act=ptoolbar->addAction(QPixmap(iconPath + slist[1]), slist[0]);
                if(slist.size()>2)
                    act->setData(slist[2]);
                if(slist.size()>3)
                    act->setCheckable(slist[3].toInt());
            }
            else
                ptoolbar->addSeparator();
        }
        m_allToolBars.append((QObject*)ptoolbar);
        connect(ptoolbar, SIGNAL(actionTriggered(QAction *)), this, SLOT(OnMenuTriggered(QAction *)));
    }
    return ptoolbar;
}

QWidget* CreateWidget(const QString& widgetType)
{
    QWidget* widget=NULL;
    if (widgetType.contains( "pushButton",Qt::CaseInsensitive))
    {
		widget = new CGPushButton();
    }
    else if (widgetType.contains("spinBox",Qt::CaseInsensitive))
    {
        widget = new CGSpinBox();
    }
    else if (widgetType.contains("doubleSpinBox",Qt::CaseInsensitive))
    {
        widget = new CGDoubleSpinBox();
    }
    else if (widgetType.contains("comboBox",Qt::CaseInsensitive))
    {
        widget = new CGComboBox();
    }
    else if (widgetType.contains("label",Qt::CaseInsensitive))
    {
        widget = new CGLabel("");
    }
	else if (widgetType.contains("checkBox", Qt::CaseInsensitive))
	{
		widget = new CGCheckBox();
	}

    return widget;
}

QObject* CGWnd::AddToolBarWidget(const QStringList& info,const QString& toolbarArea,int layoutDirection )
{
    if (info.size() == 2 )
    {
        Qt::ToolBarArea area = Qt::TopToolBarArea;

        if (toolbarArea.contains("left",Qt::CaseInsensitive))
            area = Qt::LeftToolBarArea;
        else if(toolbarArea.contains("right",Qt::CaseInsensitive))
            area = Qt::RightToolBarArea;
        else if(toolbarArea.contains("top",Qt::CaseInsensitive))
            area = Qt::TopToolBarArea;
        else if(toolbarArea.contains("bottom",Qt::CaseInsensitive))
            area = Qt::BottomToolBarArea;
        else if(toolbarArea.contains("all",Qt::CaseInsensitive))
            area = Qt::AllToolBarAreas;
        else if(toolbarArea.contains("no",Qt::CaseInsensitive))
            area = Qt::NoToolBarArea;

          //QToolBar * ptoolbar = new QToolBar(info.at(0));
        QToolBar *ptoolbar =  findChild<QToolBar *>(info.at(0),Qt::FindChildrenRecursively);
        if(!ptoolbar)
        {
            ptoolbar = new QToolBar(info.at(0));
            ptoolbar->setObjectName(info.at(0));
            ptoolbar->setAllowedAreas(Qt::AllToolBarAreas);
            ptoolbar->setLayoutDirection((Qt::LayoutDirection)layoutDirection);
            addToolBar(area, ptoolbar);
            m_allToolBars.append((QObject*)ptoolbar);
        }
        QString widgetType = info.at(1);
        QWidget* widget=CreateWidget( widgetType);
        ptoolbar->addWidget(widget);
        return (QObject*)widget;
    }
    return NULL;
}


QObject* CGWnd::AddMenuBarWidget(const QString& widgetType, bool attopright )
{
    QWidget* cornerw=menuBar()->cornerWidget((Qt::Corner)attopright);
    if(cornerw==NULL)
    {
        cornerw= new QGroupBox();
        QHBoxLayout *hbox = new QHBoxLayout(cornerw);
        hbox->setContentsMargins(0,0,0,0);
        hbox->setSpacing(2);
        ((QGroupBox*)cornerw)->setFlat(true);
        cornerw->setStyleSheet( " border: 0px solid;" );
        menuBar()->setCornerWidget(cornerw,(Qt::Corner)attopright);
    }
    Q_ASSERT(cornerw->layout());
    QWidget* widget=CreateWidget( widgetType);
    if(widget) cornerw->layout()->addWidget(widget);
    return (QObject*)widget;
}

void CGWnd::SetToolBarIconSize(const int& width, const int& height)
{
    for (int i = 0; i < m_allToolBars.size(); i++)
    {
        QString qss = QString("min-height: %1px;").arg(height);
        ((QToolBar*)m_allToolBars[i])->setStyleSheet(qss);
        ((QToolBar*)m_allToolBars[i])->setIconSize(QSize(width, height));
    }
}

QObject* CGWnd::GetStatusBar()
{
    return (QObject*)statusBar();
}

QObject* CGWnd::AddStatusBarWidget(const QString& widgetType, bool beLeft, int stretch)
{
    QStatusBar * pStatusbar = statusBar();
    QWidget* widget=CreateWidget( widgetType);
    if(widget==NULL)
        return NULL;

    if (beLeft)
		pStatusbar->addWidget(widget, stretch);
    else
		pStatusbar->addPermanentWidget(widget, stretch);
    return (QObject*)widget;
}

void CGWnd::SetCorner(QString corner, QString area)
{
    Qt::Corner cornerType;
    if(corner.contains("TopLeft",Qt::CaseInsensitive))
    {
         cornerType=Qt::TopLeftCorner;
    }
    else if(corner.contains("TopRight",Qt::CaseInsensitive))
    {
         cornerType=Qt::TopRightCorner;
    }
    else if(corner.contains("BottomLeft",Qt::CaseInsensitive))
    {
         cornerType=Qt::BottomLeftCorner;
    }
    else if(corner.contains("BottomRight",Qt::CaseInsensitive))
    {
         cornerType=Qt::BottomRightCorner;
    }

    Qt::DockWidgetArea areaType;
    if(area.contains("LeftDock",Qt::CaseInsensitive))
    {
         areaType=Qt::LeftDockWidgetArea;
    }
    else if(area.contains("RightDock",Qt::CaseInsensitive))
    {
         areaType=Qt::RightDockWidgetArea;
    }
    else if(area.contains("TopDock",Qt::CaseInsensitive))
    {
         areaType=Qt::TopDockWidgetArea;
    }
    else if(area.contains("BottomDock",Qt::CaseInsensitive))
    {
         areaType=Qt::BottomDockWidgetArea;
    }
    setCorner(cornerType, areaType);
}

void CGWnd::TabifyDockWidget(QObject * first, QObject * second)
{
    if(first->inherits("QDockWidget")&& second->inherits("QDockWidget"))
        tabifyDockWidget((QDockWidget *)first, (QDockWidget *) second);
}

void CGWnd:: EnableToolBar(bool enable)
{

}
void CGWnd::EnableMenuBar(bool enable)
{
    if (enable)
        menuBar()->show();
    else
        menuBar()->hide();
}

void CGWnd::EnableBaseMenu(bool enable, int menuType)
{
	if (menuType < 0)
	{
		if (m_pStyleMenu)
			m_pStyleMenu->menuAction()->setVisible(enable);
		if (m_pHelpMenu)
			m_pHelpMenu->menuAction()->setVisible(enable);
		if (m_pWndMenu)
			m_pWndMenu->menuAction()->setVisible(enable);
		if (m_pFileMenu)
			m_pFileMenu->menuAction()->setVisible(enable);
	}
	else{
		QMenu* menu = GetBaseMenu((BASE_MENU_TYPE)menuType);
		if (menu)
			menu->menuAction()->setVisible(enable);
	}
}

void CGWnd::EnableStatusBar(bool enable)
{
	
}

void CGWnd::ClearMenuBar()
{
	menuBar()->clear();
}

void CGWnd::ClearToolBar()
{
	for (int i = 0; i < m_allToolBars.size(); i++)
	{
		QToolBar* bar = (QToolBar*)m_allToolBars[i];
		if (bar)
		{
			this->removeToolBar(bar);
			bar->deleteLater();
		}	
	}
	m_allToolBars.clear();
}

void CGWnd::RemoveStatusBarWidget(QObject* widget)
{
	QWidget* wnd = (QWidget*)widget;
	if (wnd)
	{
		statusBar()->removeWidget(wnd);
		wnd->deleteLater();
	}
}

void CGWnd::ShowNaviDialog(bool show)
{
}

void CGWnd::Navigate(int  nextorpre, const QString& targetWndTag)
{
	QString fileName;
	nextorpre = nextorpre>0 ? 1 : -1;
	int idx = -1;
	/*QSettings settings;
	QStringList files = settings.value(CGWnd::RecentFilesSettingTag).toStringList();*/
	CGraphView* mdiChild = (CGraphView*)ActiveWindow();
	if (mdiChild)
	{
		fileName = mdiChild->CurrentFile(true);
		idx = m_recentFiles.indexOf(fileName);
	}

	if (idx == 0 && nextorpre == 1)
		QMessageBox::information(this, tr("Tips"), tr("This is the last one!"));
	else if (idx == (m_recentFiles.size() - 1) && nextorpre == -1)
		QMessageBox::information(this, tr("Tips"), tr("This is the first one!"));
	else
	{
		if (idx<0)
			idx = 1;
		int nextIdx = (idx - nextorpre);
		m_curViewPos = nextIdx;
		if (nextIdx<0)
			nextIdx = 0;
		if (nextIdx>m_recentFiles.size() - 1)
			nextIdx = m_recentFiles.size() - 1;

		m_beUpdateLst = false;
		fileName = m_recentFiles.at(nextIdx);
		if (targetWndTag.isEmpty() && mdiChild )
			this->Open(fileName, mdiChild->GetWndAlais());
		else
			this->Open(fileName, targetWndTag);
		m_beUpdateLst = true;
	}

}

void CGWnd::keyPressEvent ( QKeyEvent * event )
{
    if(event->modifiers() == Qt::ControlModifier)
        switch(event->key())
        {
        case Qt::Key_O:
        {
            FileOpen();
        }
            break;
        case Qt::Key_M:
        {
            bool showflag=true;
            if(menuBar()->isVisible())
                showflag=false;
            EnableMenuBar(showflag);
        }
        break;
        case Qt::Key_D:
        {
            FileNewGDWin();
        }
        break;
        case Qt::Key_B:
        {
            OpenDebugWnd();
        }
        break;
        default:
            break;
        }
    QMainWindow::keyPressEvent(event);
}


void CGWnd::SaveWndGeometry()
{
    if ( m_pGeometry != NULL )
    {
        *m_pGeometry = saveGeometry();
    }
    else
    {
        m_pGeometry = new QByteArray();
        *m_pGeometry = saveGeometry();
    }
}

bool CGWnd::RestoreWndGeometry()
{
    if ( m_pGeometry != NULL )
        return restoreGeometry( *m_pGeometry );
    return false;
}

int CGWnd::NeedModSize()
{
    if ( m_pGeometry != NULL )
        return 1;
    return 0;
}

void CGWnd::SetShowStyle(int style)
{
    QVector<CGraphView*> views=GetGraphViews();
    for(int i=0;i<views.size();i++)
    {

        {


        }

    }
}

QString CGWnd::GetWndTitle(const QString & wnd_name)
{
    QString ret="";
    return ret;
}

QVector<CGraphView*> CGWnd::GetGraphViews()
{
    QVector<CGraphView*> views;

    QList<CGraphView* > allPopChilds = findChildren<CGraphView*>();
    for (int i=0;i<allPopChilds.size();i++)
    {
        CGraphView *mdiChild=allPopChilds[i];
        views.push_back(mdiChild);
    }
    return views;
}

void CGWnd::SetStyle(const QString & style)
{
    ((CGApp*)qApp)->SetStyle( style);
}

void CGWnd::StyleMotif()
{
    QString baseName = qApp->style()->objectName();
    qApp->setStyle( new ManhattanStyle( baseName ) );
}

void CGWnd::StyleMac()
{
    qApp->setStyle( QStyleFactory::create("macintosh"));
}
void CGWnd::StyleVista()
{
    qApp->setStyle( QStyleFactory::create("windowsvista"));
}
void CGWnd::StyleWindows()
{
    qApp->setStyle( QStyleFactory::create("windows"));
}

void CGWnd::StyleWin7()
{
    qApp->setStyle( QStyleFactory::create("fusion"));
}

void CGWnd::ShowFullScreen()
{
    m_WndFullScreen=true;
    showFullScreen();
    setGeometry(geometry().adjusted(0,0,1,1)); //becasue QWebView QQmlView  have some bugs when fullscreen ,so need setGeometry
}

void CGWnd::StyleFullScreen()
{
    m_WndFullScreen=!m_WndFullScreen;
    //Qt::WindowStates state=windowState();
    if(m_WndFullScreen)
    {
        showFullScreen();
        setGeometry(geometry().adjusted(0,0,1,1));
    }
    else
    {
        showFullScreen();
        //setWindowState( windowState() & ~(Qt::WindowFullScreen));
        showMaximized();
    }
}

void CGWnd::About()
{

}

void CGWnd::FileExportAs()
{
    int ww=1280;
    int hh=1024;
    if (ww>6000)
    {
        hh=hh*0.05;
        ww=ww*0.05;
        if (ww>1000)
        {
            hh=hh*1000/ww;
            ww=1000;
        }
    }
    else
    {
        hh=hh*200/ww;
        ww=200;
    }

    QRect rc(0,0,ww,hh);
    QString fn;
    UnqFunc()->GetGraphNaviNameByGraphPathName(m_GraphPathName, fn);
    FileExportAs(m_GraphPathName,0,rc,fn);
}

int CGWnd::FileExportAs(const QString& graph_path_name,int file_type,const QRect& rect,const QString& outfile_path_name,bool is_real)
{
    return 0;
}

int CGWnd::FileNewWindow(QString graph_path_name,int wnd_type)
{
    GDispInfo graph_disp_info;
    graph_disp_info.graph_path_name=graph_path_name;
    graph_disp_info.wnd_type=wnd_type;

    QString graph_name="";
    if (graph_path_name.length()!=0)
        UnqFunc()->GetGraphNameByGraphPathName(graph_path_name,graph_name);

    ((CGApp*)qApp)->NewGraphWindow(graph_disp_info);

    return 0;
}

void CGWnd::HelpAboutGraph()
{
    return;
}

void CGWnd::ChangeStyle(const QString &styleName)
{
    QApplication::setStyle(QStyleFactory::create(styleName));
}

void CGWnd::CloseAll(QString fileName)
{
	QVector<CGraphView*> views;

	if (fileName.isEmpty())
	    views = GetGraphViews();
	else
	{
		CGraphView* view = FindMdiChild(fileName);
		if (view) views.append(view);
	}
	for (int i = 0; i < views.size(); i++)
	{
		if (views.at(i))
		{
			QWidget* pWgt = views.at(i)->parentWidget();
			if (pWgt)
			{
				if (views.at(i)->parent()->inherits("QMdiSubWindow")){
					m_pWorkspace->removeSubWindow(pWgt);
					views.at(i)->close();
				}
				else if (views.at(i)->parent()->inherits("QDockWidget")){
					removeDockWidget((QDockWidget*)pWgt);
					views.at(i)->close();
				}
				delete pWgt;
				pWgt = NULL;
			}
			else if (views.at(i))
				views.at(i)->close();
		}
	}
}

void CGWnd::SetTabPosition(QString dockWidgetAreas, QString tabPosition)
{
    QTabWidget::TabPosition tpos=QTabWidget::South;
    if(tabPosition.contains("north",Qt::CaseInsensitive))
    {
        tpos=QTabWidget::North;
    }
    else if(tabPosition.contains("west",Qt::CaseInsensitive))
    {
        tpos=QTabWidget::West;
    }
    else if(tabPosition.contains("east",Qt::CaseInsensitive))
    {
        tpos=QTabWidget::East;
    }

    Qt::DockWidgetAreas area=Qt::AllDockWidgetAreas;

    if(dockWidgetAreas.contains("leftdock",Qt::CaseInsensitive))
    {
        area=Qt::LeftDockWidgetArea ;
    }
    else if(dockWidgetAreas.contains("rightdock",Qt::CaseInsensitive))
    {
        area=Qt::RightDockWidgetArea ;
    }
    else if(dockWidgetAreas.contains("topdock",Qt::CaseInsensitive))
    {
        area=Qt::TopDockWidgetArea ;
    }
    else if(dockWidgetAreas.contains("bottomdock",Qt::CaseInsensitive))
    {
        area=Qt::BottomDockWidgetArea ;
    }
    setTabPosition(area, tpos);
}

QObject* CGWnd::FindChild(const QString& componentName )
{
    if(componentName=="menuBar") return menuBar();
    if(componentName=="statusBar") return statusBar();

    QObject *dw =  findChild<QObject *>(componentName,Qt::FindChildrenRecursively);
    if(dw==NULL)
    {
         gError( "cannot find this Component" );
         return NULL;
    }
    return dw;
}

QObject* CGWnd::EnableComponent(const QString& componentName, int ifvisiable )
{

    QWidget *dw =  findChild<QWidget *>(componentName,Qt::FindChildrenRecursively);
    if(dw==NULL)
    {
         gError( "cannot find this Component" );
         return NULL;
    }
    bool cur=dw->isVisible();
    if(dw->inherits("QDockWidget"))
    {
        QAction * dwa=((QDockWidget*)dw)->toggleViewAction() ;

        if(ifvisiable!=(int)cur)
            dwa->trigger();
    }
    else
    {
        if(ifvisiable<0)
            ifvisiable=!cur;

        if(ifvisiable==1)
            dw->show();
        else if(ifvisiable==0)
            dw->hide();

    }
    return dw;
}

void CGWnd::FilePrint(bool invert)
{
    CGraphView * aw=(CGraphView *)ActiveWindow();

    if(!aw) return;
    QString fn=aw->CurrentFile();



    UnqFunc()->GetGraphCoreNameByGraphPathName(fn,fn);
    QString title=fn +" " +QDateTime::currentDateTime().toString(Qt::ISODate);
    QPrinter printer( QPrinter::HighResolution );
    printer.setOrientation(QPrinter::Landscape);
    printer.setFullPage(true);
    printer.setDocName(fn);
    QRectF rect=printer.paperRect();

    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);

        if(invert){
            painter.save();
            painter.setCompositionMode(QPainter::CompositionMode_Source);
            painter.fillRect(rect, Qt::white);
            painter.restore();
            painter.save();
            painter.setCompositionMode(QPainter::RasterOp_NotSource);
            aw->render(&painter);
            painter.restore();

        }
        else
            aw->render(&painter);

        painter.setPen(Qt::black);
        painter.drawText(rect,  Qt::AlignBottom | Qt::TextWordWrap,title);
        painter.end();
    }

    //FilePrintVector();
   /*
    QVector<CGraphView*> views = GetGraphViews();
    for (int i = 0; i < views.size(); i++)
    {
        if (views[i]->isVisible())
        {
            m_PrintScene = views[i]->Scene();
            QRect   back_rect = m_PrintScene->GetLayoutRect();
            gw = back_rect.width();
        }
    }
    QRect rc(0, 0, gw, gh);
    QPixmap pix(rc.size());
    pix.fill(this, rc.topLeft());

    //
    QPrinter printer( QPrinter::HighResolution );
    printer.setOrientation(QPrinter::Landscape);
    printer.setFullPage(true);
    QPainter painter(&printer);
    QPrintDialog dialog(&printer, this);
    if (dialog.exec())
    {
        int page = 1;
        if(aw) aw->render(&painter);
 /*
        QMatrix mymatrix, oldmatrix;

        //int dpiy = printer.logicalDpiY();
        int margin = 20; //(int) ( (2/2.54)*dpiy ); // 2 cm margins
        //f(gw>1280) margin=10;
        int width = printer.width();
        int height = printer.height();
        int marginx = margin;
        int marginy = margin;
        //float scaleradio = (float)width / gw ;
        QFont tmp_font( font() );
        tmp_font.setPointSize( 10 ); // we define 10pt to be a nice base size for printing

        //////打印的范围//////
        QRect print_rect( margin, margin, width - 2 * margin, height - 2 * margin);

        int page = 1;
        p.setFont( tmp_font );

        if (printer.orientation () == QPrinter::Portrait)
        {
            /////打印的范围//////


        }
        else
        {
            ///////居中打印///////
            float f_tmp1, f_tmp2, f_tmp;
            if (gw > 1280)
            {
                f_tmp1 = (print_rect.Width() * 0.98) / gw;
                f_tmp2 = (print_rect.Height() * 0.98) / gh;
            }
            else
            {
                f_tmp1 = (print_rect.Width() * 1.0) / gw;
                f_tmp2 = (print_rect.Height() * 1.0) / gh;
            }
            int delta_x = 0;
            int delta_y = 0;
            ///////可打印的区域过宽，图形区域右移/////
            if (f_tmp1 >= f_tmp2)
            {
                f_tmp = f_tmp2;
                marginx += (print_rect.Width() - f_tmp2 * gw) / 2;
            }
            else//////可打印的区域过高，图形区域下移////
            {
                f_tmp = f_tmp1;
                marginy += (print_rect.Height() - f_tmp1 * gh) / 2;
            }
            delta_x = -marginx;
            delta_y = -marginy;

            for (int i = 0; i < views.size(); i++)
            {
                if (views[i]->isVisible())
                {
                    m_PrintScene = views[i]->Scene();
                    int back_color = m_PrintScene->GetBackColor();
                    //CGString back_pix_name= m_PrintScene->GetCurGraphHead()->GetBackPixmapName();
                    QRect   back_rect  = m_PrintScene->GetLayoutRect();
                    QBrush mybrush;
                    mybrush.setColor(back_color);
                    mybrush.setStyle(SOLID_PATTERN);
                    p.save();
                    p.scale(f_tmp, f_tmp);
                    p.translate(margin, 0);
                    p.fillRect(back_rect , mybrush);
                    p.restore();

                    p.save();
                    p.scale(f_tmp, f_tmp);
                    p.translate(back_rect.x() + margin, back_rect.y());
                    m_PrintScene->Draw(&p);
                    p.restore();
                }

            }
        }

        p.translate( 0 , -print_rect.Height() );

        printer.newPage();
        page++;
    }*/
}


void CGWnd::FilePrintVector()
{
    CGraphView * aw=(CGraphView *)ActiveWindow();

    if(!aw) return;
    QString fn=aw->CurrentFile();
    UnqFunc()->GetGraphCoreNameByGraphPathName(fn,fn);
    QPrinter printer( QPrinter::HighResolution );
    printer.setOrientation(QPrinter::Landscape);
    printer.setFullPage(true);
    printer.setDocName(fn);
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        aw->render(&painter);


            QPainter p(&printer);
            p.setCompositionMode(QPainter::CompositionMode_Difference);
            p.fillRect(aw->Scene()->GetLayoutRect(), Qt::white);
            p.end();

    }
 /*
    QBrush mybrush("white");

                        painter.save();
                        painter.setCompositionMode(QPainter::CompositionMode_Source); //
                        p.scale(f_tmp, f_tmp);
                        p.translate(margin, 0);
                        p.fillRect(back_rect.ToQRect(), mybrush);
                        p.restore();
                        p.setCompositionMode(QPainter::RasterOp_NotSource);
                        p.save();
                        p.scale(f_tmp, f_tmp);
                        p.translate(back_rect.X1() + margin, back_rect.Y1());
                        m_PrintScene->Draw(&p);
                        p.restore();*/
}

void CGWnd::FilePrintVectorPart()
{
}

void CGWnd::FilePrintVectorSplit()
{
}

void CGWnd::FilePrintByScript(QString myrect)
{
}
void CGWnd::FileExportGraph()
{

}

void CGWnd::ReversePrintColor(bool is_reverse_color)
{

}

void CGWnd::SelfDefinePrintColor(bool is_self_define)
{

}

void CGWnd::OpenDebugWnd()
{
    if (ActiveWindow() == NULL)
        return;

    if (!m_debugger) {
        m_debugger = new QScriptEngineDebugger(this);
        m_debugWindow = m_debugger->standardWindow();
        m_debugWindow->setWindowModality(Qt::NonModal);
        m_debugWindow->resize(1280, 704);
    }
    QStringList items;
    CGraphView* pview=NULL;
    for(int i=0;i<m_Views.size();i++)
    {
        pview= m_Views.at(i);
        QString tmpstr=pview->CurrentFile();
        UnqFunc()->GetGraphCoreNameByGraphPathName(tmpstr,tmpstr);
        items<<tmpstr;
    }

    bool ok;
    QString item = QInputDialog::getItem(this, tr("please choice file for debug"),
                                         tr("file:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
    {
        pview=FindMdiChild(item,"");
        if(pview)
        {
            CScriptEngine* pse=pview->Scene()->GetScriptEngine();
            //pse->reset();
            m_debugger->attachTo((QScriptEngine*)(pse));
            m_debugger->action(QScriptEngineDebugger::InterruptAction)->trigger();
            pse->LoadFile(QString("hmiCommon.js"));
            QString code = pview->Scene()->GetScript();
            if (!code.isEmpty() )
            {
                pse->Evaluate(code);
            }
        }
    }
}

void CGWnd::SetWndIcon(QString iconName)
{
	QString icon = iconName;
	UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, iconName, icon);
	this->setWindowIcon(QIcon(icon));

}
void CGWnd::Exit(bool allwnd)
{
    hide();
    if(allwnd)
        QTimer::singleShot(500,  qApp,  SLOT(quit()));
    else
        QTimer::singleShot(500, this, SLOT(close()));
}

void CGWnd::retranslateUi()
{
    m_pStyleMenu->setTitle(tr( "File(&F)" ));
    m_pHelpMenu->setTitle(tr( "Window(&V)" ));
    m_pWndMenu->setTitle(tr( "Help(&H)" ));
    m_pFileMenu->setTitle(tr( "Wnd Style(&S)" ));
}
