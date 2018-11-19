
#include "DesignerWnd.h"
#include "DesignerView.h"
#include "DesignerScene.h"
#include "ConstString.h"
#include "BaseData.h"
#include "propertyeditor.h"
#include "ItemBox.h"
#include "ActionManager.h"
#include "NameManager.h"
#include "ObjectInspector.h"
#include "IconDlg.h"
#include "ItemFactory.h"
#include "GroupItem.h"
#include "IconMng.h"
#include "ExplorerView.h"
#include "AnimationDlg.h"

#ifdef GSVG
#include "qsvgtinydocument_p.h"
#endif

static int g_dx = 0;
const int InsertTextButton = 10;

CDesignerWnd::CDesignerWnd( int wnd_id,const GDispInfo& disp_info, QWidget* parent, const char* name, Qt::WindowFlags fl)
    : CGWnd( wnd_id, Hmi::Designer, parent, fl )
{
    if ( !name )
        setWindowTitle( tr( "PowerHmi" ) );

    setObjectName("Window");

    m_bPatchCreate = false;
    m_iPatchCreateNum = 0;
    m_AnimatDlg=NULL;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    //animation->start();

    Mdi::SetWnd(this);

    setUnifiedTitleAndToolBarOnMac(true);


   // qDebug(" Setup NaviDialog ....");
    SetupNaviDialog();

   // qDebug(" Setup Toolbars ...... ");
    SetupToolbars();

   // qDebug(" Setup Menubar .....");
    SetupMenubar();

  //  qDebug(" Setup Toolbox ....");
    SetupItemBox();

  //  qDebug(" Setup PropertyEditor ....");
    SetupPropertyEditor();

  //  qDebug(" Setup obj...");
    SetUpObjectInspector();

 //   qDebug(" Setup undoView...");
    SetupUndoView();



   
	m_pWorkspace->setViewMode(QMdiArea::TabbedView);
    connect(m_pWorkspace,SIGNAL(subWindowActivated(QMdiSubWindow *)),this,SLOT(OnSubWindowActivated(QMdiSubWindow *)));
    showMaximized();
    EnableComponent("ObjectInspector",0);
    EnableComponent("CommandDockWidget",0);


}




CDesignerWnd::~CDesignerWnd()
{

}

void CDesignerWnd::ReadSettings()
{
    QSettings Settings("PHMI", "PHMI");
    Settings.beginGroup("FilePathName");
}

CMdiSubWindow* CDesignerWnd::CreateMdiChild()
{
    CMdiSubWindow *pSubWnd = new CMdiSubWindow(this);
    m_pWorkspace->addSubWindow(pSubWnd);
    CDesignerView *child = pSubWnd->GetView();

    //QObject::connect(child, SIGNAL(MouseRelease()), this, SLOT(UpdatePropertySheet()));
    if(CDesignerScene* scene = qobject_cast<CDesignerScene*>(child->scene()))
    {
        QObject::connect(scene, SIGNAL(selectionChanged()), UnqActMng(), SLOT(OnSceneSelectionChanged()));
        QObject::connect(scene,SIGNAL(MouseMoved(QPointF)),this,SLOT(OnUpdateStatus(QPointF)));
    }
    return pSubWnd;
}

CMdiSubWindow* CDesignerWnd::FindMdiChild(const QString &file_name,const QString& wnd_tag)
{
    QString tmpstr;
    QString fileName=file_name;


    foreach (QMdiSubWindow *window, m_pWorkspace->subWindowList())
    {
        CMdiSubWindow *pMdiChild = qobject_cast<CMdiSubWindow *>(window->widget());

        tmpstr=pMdiChild->windowTitle();
		if (!fileName.isEmpty() && (tmpstr == fileName || tmpstr == fileName + " *"))
            return pMdiChild;
    }

    return NULL;
}

CMdiSubWindow* CDesignerWnd::ActiveSubWindow()
{
    if (!m_pWorkspace->activeSubWindow())
        return NULL;

    CMdiSubWindow *window = qobject_cast<CMdiSubWindow *>(m_pWorkspace->activeSubWindow()->widget());
    return window;
}

void CDesignerWnd::SetActiveSubWindow(CMdiSubWindow *window)
{
    if (!window)
        return;
	m_pWorkspace->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window->parent()));
}

CDesignerView* CDesignerWnd::ActiveView() const
{
    CDesignerView* pView=NULL;
    QMdiSubWindow *window = m_pWorkspace->activeSubWindow();
    if(!window)
        window = m_pWorkspace->currentSubWindow();
    if ( window  )
    {
        CMdiSubWindow* pSubWnd=qobject_cast<CMdiSubWindow *>(window->widget());
        pView = pSubWnd->GetView() ;
    }

    return pView;
}

CDesignerScene* CDesignerWnd::ActiveScene() const
{
    CDesignerScene* scene = ActiveView() ? (CDesignerScene*)(ActiveView()->scene()) : NULL;
    return scene;
}

void CDesignerWnd::ResentFileSelect(int index)
{
    if ( NeedSave( tr("Open") ) )
        return;
}

#define PNG_WIDTH 200
#define PNG_HEIGHT 200

int CDesignerWnd::NeedSave( const QString &action )
{
	CMdiSubWindow* win = ActiveSubWindow();
	if (win == NULL)
        return true;
	CDesignerScene* scene = (CDesignerScene*)(win->GetView()->scene());
	if (scene == NULL)
		return true;
	if (scene->GetModified())
    {
		QString fileName = win->windowTitle().split('/').last();

        QMessageBox mb(action, tr("Graph %1 already be modified!\n Want to save?").arg(fileName.left(fileName.length()-2)),
                       QMessageBox::Warning, QMessageBox::Save | QMessageBox::Default,QMessageBox::Discard,
                       QMessageBox::Cancel ,this);
        mb.setButtonText( QMessageBox::Save, tr("Save") );
        mb.setButtonText( QMessageBox::Discard, tr("Discard") );
        mb.setButtonText( QMessageBox::Cancel, tr("Cancel") );
        int retmb=mb.exec();
        switch( retmb)
        {
        case QMessageBox::Save:
        {
            OnFileSave();
        }
            break;
        case QMessageBox::Discard:
            return true;
        case QMessageBox::Cancel:
            return false;
        }
    }

    return true;

}

void CDesignerWnd::OnFileNewIcon()
{
    CMdiSubWindow* pSubWnd = CreateMdiChild();
	SetActiveSubWindow(pSubWnd);
    QString fileName = QObject::tr("%1untitle%2.ivg").arg(UnqFunc()->GetDir(CGFunc::PATH_TYPE_ICON)).arg(g_dx + 1);
    pSubWnd->FileNew( fileName);
    ++g_dx;
}

void CDesignerWnd::OnFileNew()
{
#if 0

    QMessageBox mb( tr("tip"), tr("Please make a choice"),QMessageBox::Warning, QMessageBox::Yes | QMessageBox::Default,QMessageBox::No,QMessageBox::Cancel | QMessageBox::Escape,0);
    mb.setButtonText( QMessageBox::Yes, tr("create pic") );
    mb.setButtonText( QMessageBox::No, tr("create icon") );
    mb.setButtonText( QMessageBox::Cancel, tr("cancel") );
    int retmb=mb.exec();
    int ret = 1;
    switch( retmb)
    {
    case QMessageBox::Yes:
        ret= 1;
        break;
    case QMessageBox::No:
        ret= 2;
        break;
    case QMessageBox::Cancel:
        return;
    }
#endif

    CMdiSubWindow* pSubWnd = CreateMdiChild();
	QString fileName = QString("%1untitle%2_tmp.svg").arg(UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC)).arg(g_dx + 1);
    pSubWnd->FileNew( fileName);
	SetActiveSubWindow(pSubWnd);
	if (g_dx == 0)
	{
		pSubWnd->adjustSize();
		pSubWnd->setCurrentIndex(1);
		pSubWnd->setCurrentIndex(0);
	}
    ++g_dx;
    return;

}
void CDesignerWnd::OnFileOpenBinary()
{
	if (!NeedSave(tr("Open")))
		return;

	QString path = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC);
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), path, QString("pic(*%1)").arg(PICBINARYSUFFIX));
	if (fileName.isEmpty())
		return;

	OnFileOpen(fileName,false,true);

}
void CDesignerWnd::OnFileOpen()
{
    if ( !NeedSave( tr("Open") ) )
        return;

    QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),path, QString("pic(*%1 *%2)").arg(ICONSUFFIX).arg(PICSUFFIX));

    if (fileName.isEmpty())
        return;

    if(CheckName(fileName)<0)
    {
        return;
    }

    OnFileOpen(fileName);

}

int CDesignerWnd::OnFileOpen(QString fileName, bool isImprot, bool isBinary)
{
    int ret =-1;
    if (fileName.isEmpty())
        return ret;
	
	QFile dir;
	if (!dir.exists(fileName))
	{
		QMessageBox::warning(this, tr("Tips"), tr("Can not find file: ") + fileName);
		return ret;
	}

    CMdiSubWindow* pSubWnd = FindMdiChild(fileName);
    if (!pSubWnd)
    {
        pSubWnd=CreateMdiChild();
		pSubWnd->FileOpen(fileName, isImprot, isBinary);
		if (!isImprot)
           UpdateRecentFiles(fileName);
        UnqActMng()->InitFileMenu(GetBaseMenu(FILEMENU));
    }

    SetActiveSubWindow(pSubWnd);
    UnqNameMng()->OnSwitchScene();
	Emit("fileOpen", fileName);
    return ret;
}

void CDesignerWnd::OnFileImport()
{
	if (!NeedSave(tr("Open")))
		return;

	QString path = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC) + "/../model/";
	QString fileName = QFileDialog::getOpenFileName(this, tr("Import File"), path, QString("file(*)"));
	//qDebug("name:");
	//qDebug(fileName.toLocal8Bit().data());
	//qDebug("path:");
	//qDebug(path.toLocal8Bit().data());

	if (fileName.isEmpty())
		return;

	OnFileOpen(fileName, true);

}


QObject* CDesignerWnd::Open(const QString& fn, const QString& wnd_tag, const QVariant& jobjArgs )
{
    QString file_name=fn;
    if (file_name.isEmpty())
        return NULL;
    if (file_name.right(4)!=PICSUFFIX)
    {
        file_name+=PICSUFFIX;
    }
    if ( !QDir::isAbsolutePath( file_name ) )
        UnqFunc()->GetGraphPathNameByGraphName(file_name,file_name);
    QFile dir;
    if(! dir.exists ( file_name ))
    {
		QMessageBox::warning(this, tr("Tips"), tr("Can not find file: ") + file_name);
        return NULL;
    }

    QVariantMap jobj=jobjArgs.toMap();
    QString scenetype =jobj["scenetype"].toString();
    QString wndflag =jobj["wndflag"].toString();
    QString replace_key =jobj["rkey"].toString();
    QString args =jobj["args"].toString();

    if (!jobjArgs.isValid())
        scenetype = "edit";

    int ret=-1;
    QObject* retObj=NULL;
    if(scenetype=="edit")
    {
        OnFileOpen( file_name);
        retObj=(QObject*)ActiveView();
    }
    else
    {
        CGraphView*child = CGWnd::FindMdiChild(file_name);
        if ( child)
        {
            child->show();
            //if(child->parent()) child->parent()->show();
            return child;
        }

        child = CGWnd::FindMdiChild("",wnd_tag);

        if (child==NULL)
        {
            if (wndflag.contains("dialog",Qt::CaseInsensitive) || wndflag.contains("dock",Qt::CaseInsensitive))
            {
                child = new CGExplorerView(this,NULL,this,0);
            }
            else
                child=NULL;
        }

        if(child && child->inherits("CGExplorerView"))
        {
            int flag=Qt::Dialog;
            if(wndflag.contains("dock",Qt::CaseInsensitive))
                flag=Qt::Sheet;

            CGExplorerView* pview=(CGExplorerView*)child;
            pview->FileOpen(file_name,replace_key,flag,jobjArgs);
            pview->show();
            QObject *pp=pview->parent();
            if(pp->inherits("QDockWidget"))
            {
                ((QDockWidget*)pp)->setFloating(true);
                 ((QDockWidget*)pp)->setFloating(false);
            }
            QMdiSubWindow* parent=qobject_cast<QMdiSubWindow *>(pview->parent());
            if(parent)
            {
                parent->show();
                parent->setWindowTitle(file_name);
            }
            retObj=(QObject*)pview;
        }
    }

    if (!wnd_tag.isEmpty()&& retObj)
        ((CGraphView*)retObj)->SetWndAlais(wnd_tag);

    return retObj;
}

void CDesignerWnd::OnFileSaveBinary()
{
	CMdiSubWindow* pSubWnd = ActiveSubWindow();
	if (pSubWnd == NULL)
		return;
	ActiveScene()->SetModified(false);
	QString fileName = pSubWnd->windowTitle();
	pSubWnd->FileSave(fileName,true);
	fileName = pSubWnd->windowTitle();
	UpdateRecentFiles(fileName);
	UnqActMng()->InitFileMenu(GetBaseMenu(FILEMENU));
}

void CDesignerWnd::OnLoadIcons()
{
	QVariantMap args = GetArgs().toMap();
	if(args["wnd"] == "lsd")
		LoadToolBox("toolbox_lsd.xml");
	else
	    LoadToolBox("gtoolbox.xml");
}

void CDesignerWnd::OnFileSave()
{
    CMdiSubWindow* pSubWnd=ActiveSubWindow();
    if (pSubWnd == NULL)
        return;
    ActiveScene()->SetModified(false);
    QString fileName=pSubWnd->windowTitle();
    pSubWnd->FileSave(fileName);
    fileName=pSubWnd->windowTitle();
    UpdateRecentFiles(fileName);
    UnqActMng()->InitFileMenu(GetBaseMenu(FILEMENU));
}
void CDesignerWnd::OnFileSaveAs()
{
    CMdiSubWindow* pSubWnd=ActiveSubWindow();
    if (pSubWnd == NULL)
        return;
    QString title = QObject::tr("Save as");

    QString fileName ="";

    int ret=pSubWnd->FileSave(fileName);
    if(ret <0 ) return ;
    fileName=pSubWnd->windowTitle();
    UpdateRecentFiles(fileName);
    UnqActMng()->InitFileMenu(GetBaseMenu(FILEMENU));

}
bool CDesignerWnd::CloseFile(const QString &file_name)
{
	CMdiSubWindow* swin = FindMdiChild(file_name);
	if (swin){
		if (swin->parentWidget()){
			return swin->parentWidget()->close();//setTabsClosable(true), not need m_pWorkspace->removeSubWindow(swin->parentWidget());
		}		
		else
			return swin->close();	
	}
	return true;
}

void CDesignerWnd::OnUpdateStatus( const QPointF& pos )
{
    const int contentlength = 14;
    QString cor = QString().
            append("position:").
            append("(%1,%2)").arg(pos.x()).arg(pos.y());

    m_TimeLabel->setText(tr( (cor+=QString(contentlength-cor.size(),' ')).toLocal8Bit().data() ));
}


void CDesignerWnd::OnNewExplorerWnd()
{
    QString tmpstr = "ge";
	CMdiSubWindow* win = ActiveSubWindow();
	if (win != NULL && NeedSave(tr("Run")))
    {
		QString fileName = win->windowTitle();
		QString file_path_name;
		UnqFunc()->GetGraphPathNameByGraphName(fileName, file_path_name);
        tmpstr = "ge -pic " + fileName;
    }
    UnqFunc()->SysExec(tmpstr);
}

void CDesignerWnd::OnNewDesignerWnd()
{
    QString fileName=ActiveSubWindow()->windowTitle();
    QString file_path_name;

    UnqFunc()->GetGraphPathNameByGraphName(fileName,file_path_name);

    QString tmpstr="\"C:\\Program Files\\Internet Explorer\\iexplore.exe\"";
    QStringList gg;gg<<file_path_name;
    QProcess::startDetached(tmpstr,gg);


}

void CDesignerWnd::OnNewNavigation()
{
}

void CDesignerWnd::OnCreateIcon()
{
    if (!ActiveScene() || ActiveScene()->selectedItems().empty())
        return;

    if(ActiveScene()->selectedItems().size()==1 && ActiveScene()->selectedItems().at(0)->type()==Hmi::Icon)
    {
        CIconItem* iocnItem=(CIconItem*)ActiveScene()->selectedItems().at(0);
        if ( QMessageBox::warning(this, tr("Tips"),tr("do you want update the symbol to Symbol library ?")  ,QMessageBox::Ok,QMessageBox::Cancel)== QMessageBox::Cancel)
            return;

        QString iName=((CIconData*)g_dataPtr(iocnItem))->GetTemplateName();
        UnqIconMng()->AddIcon(iocnItem,iName);
        QString fileName;
        if (iName.left(5)==ICONPREFIX)
        {
            iName=iName.right(iName.length()-5);
        }
        UnqFunc()->GetIconPathNameByIconCoreName(iName,fileName);
        ActiveScene()->IconSaveToFile(iocnItem,fileName);
        return;
    }
    QStringList iconInfo;
    QPixmap fileIcon;
    IconSetDlg dlg(fileIcon,iconInfo,this);
    if (dlg.Init())
    {
        int ret = dlg.exec();
        if (ret == QDialog::Rejected)
        {
            return;
        }
    }
    else
    {
        return;
    }
	ActiveScene()->SetIconInfo(iconInfo[3], iconInfo[2]);
	ActiveScene()->SaveIconBySelected(iconInfo[0], iconInfo[1], iconInfo[2]);
}

void CDesignerWnd::OnShowToolbox()
{
    bool check = m_pToolsDockWnd->isVisible();
	check = !check;
    m_pToolsDockWnd->setVisible(check);
}

void CDesignerWnd::OnShowPropertyEditor()
{
    bool check = m_pPropertyDockWnd->isVisible();
    check = !check;
    m_pPropertyDockWnd->setVisible(check);

}

void CDesignerWnd::OnNormalView()
{
    if (ActiveView())
    {
        ActiveView()->ResetMatrix();
        ActiveView()->EmitMatrixChg();
    }

}

void CDesignerWnd::FileAutoCut()
{

}

void CDesignerWnd::ShowAllLink()
{
}

void CDesignerWnd::DeleteLink()
{

}

void CDesignerWnd::OnUpdateLink()
{
}

void CDesignerWnd::closeEvent ( QCloseEvent * e )
{
    QList<QMdiSubWindow *> subWnd = m_pWorkspace->subWindowList();
    if (subWnd.size() == 0)
        e->accept();

    bool beClose = true;
    for (int i = 0; i < subWnd.size(); i++)
    {
        m_pWorkspace->setActiveSubWindow(subWnd[i]);
        if (NeedSave(tr("Close")))
            continue;
        else
        {
            beClose = false;
            break;
        }
    }

    if (beClose)
        e->accept();
    else
        e->ignore();
}


void CDesignerWnd::SetUpObjectInspector()
{
    m_pObjectInspectorDock = new QDockWidget( tr( "ObjectInspector" ), this );
    m_pObjectInspectorDock->setObjectName("ObjectInspector");
    m_pObjectInspectorDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget( Qt::RightDockWidgetArea, m_pObjectInspectorDock);
    m_inspector = new CObjectInspector(UnqNameMng()->GetNameModel(), this);
    QObject::connect(m_inspector, SIGNAL(SIGItemClicked(QGraphicsItem*)), this, SLOT(OnObjectInspectorItemClicked(QGraphicsItem*)));
    QObject::connect(UnqNameMng(), SIGNAL(SIGUpdateModel()), m_inspector, SLOT(OnUpdateModel()));
    m_pObjectInspectorDock->setWidget(m_inspector);
}

void CDesignerWnd::SetupToolbars()
{
    QString iconbuf;

	m_pFileToolBar = addToolBar(QObject::tr(G_STR_file_operation));
    m_pFileToolBar->setObjectName("File");
	m_pWndToolBar = addToolBar(QObject::tr(G_STR_wnd_operation));
    m_pWndToolBar->setObjectName("Windows");
	m_pEditToolBar = addToolBar(QObject::tr(G_STR_graph_edit));
    m_pEditToolBar->setObjectName("Edit");
    //addToolBarBreak();
	m_pAlignToolBar = addToolBar(QObject::tr(G_STR_align_tool));
    m_pAlignToolBar->setObjectName("Position");
    UnqActMng()->InitToolBar(m_pFileToolBar, FileToolBar);
    UnqActMng()->InitToolBar(m_pWndToolBar, WndToolBar);
    UnqActMng()->InitToolBar(m_pEditToolBar, EditToolBar);
    UnqActMng()->InitToolBar(m_pAlignToolBar, AlignToolBar);

    QToolBar* scaleBar = addToolBar(tr("Scale"));
    scaleBar->setObjectName("scalebar");
	m_sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%")<< tr("300%");
	m_sceneScaleCombo->addItems(scales);
	m_sceneScaleCombo->setCurrentIndex(2);
	m_sceneScaleCombo->setEditable(true);
	connect(m_sceneScaleCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(OnSceneScaleChanged(const QString&)));
	scaleBar->addWidget(m_sceneScaleCombo);

    m_gtbar=new GlobalToolBarCreator(this);

    QToolBar * m_StatusToolBar= new QToolBar(this);

    UnqActMng()->InitToolBar(m_StatusToolBar, StatusToolBar);

    statusBar()->addPermanentWidget(m_StatusToolBar);
    m_ScaleLabel=new QLabel(this);
    m_ScaleLabel->setFixedWidth(50);
    m_ScaleLabel->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    m_ScaleLabel->setFrameShape(QFrame::Panel);
    m_ScaleLabel->setFrameShadow(QFrame::Sunken);
    statusBar()->addPermanentWidget(m_ScaleLabel, 0);

    m_TimeLabel=new QLabel(this);
    m_TimeLabel->setText(tr("position/time"));
    m_TimeLabel->setFrameShape(QFrame::Panel);
    m_TimeLabel->setFrameShadow(QFrame::Sunken);
    statusBar()->addPermanentWidget(m_TimeLabel);

}

void CDesignerWnd::SetupMenubar()
{
    GetBaseMenu(FILEMENU)->clear();
    UnqActMng()->InitFileMenu(GetBaseMenu(FILEMENU));
    UnqActMng()->InitWndMenu(GetBaseMenu(WNDMENU));
}


void CDesignerWnd::SetupPropertyEditor()
{
	m_pPropertyDockWnd = new QDockWidget(QObject::tr(G_STR_property_editor), this);
    m_pPropertyDockWnd->setObjectName("PropertyDockWidget");
    m_pPropertyDockWnd->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, m_pPropertyDockWnd);

    m_propertyEditor = new PropertyEditor(this);
    m_propertyEditor->setObjectName("PropertyEditor");

    QStringList headLabels;
    headLabels<<QObject::tr("Property")<<QObject::tr("Value");
    m_propertyEditor->SetHeaderLabels(headLabels);
    //m_pPropertyDockWnd->setMinimumSize(260,300);
    m_pPropertyDockWnd->setWidget( m_propertyEditor );
    connect(m_propertyEditor, SIGNAL(propertyValueChanged(const QString&,const QString&, const QVariant&,bool)),
            this, SLOT(OnSetProperty(const QString&,const QString&, const QVariant&,bool)));



}

void CDesignerWnd::OnSetProperty(const QString& groupName,const QString& name, const QVariant& value, bool fromSubProperty)
{
    if (fromSubProperty)
        return;
    CDesignerScene* scene = ActiveScene();
    if(!scene)
        return;
	QList<QGraphicsItem*> lst = scene->selectedItems();
	if (lst.empty())
    {
        ActiveScene()->SetProperty(name, value,groupName);
    }
    else
    {
        scene->ApplySetProperty(name, value,groupName);
		//setCurrentPlane to make item can modify plane more than one, like plane0 to plane2
		if (name == QObject::tr("plane") || name == "plane")
		{
			ActiveSubWindow()->SetCurrentPlane(value.toInt());
			foreach(QGraphicsItem *item, lst)
			{
				item->setSelected(true);
			}
		}
    }

}

void CDesignerWnd::UpdatePropertySheet(bool beSameType)
{

    if (ActiveScene() == NULL)
    {
        return;
    }
    int count = ActiveScene()->selectedItems().size();

    QList<PPTGroupPair> pptList;
    QList<QPair<QString, QVariant> > propertylist;

    QString window_name = QObject::tr(G_STR_property_editor);

    QString propertyname;
    QVariant propertyvalue;
    QString splitname;

    QGraphicsItem* item = NULL;
    QString tagname;

    static QGraphicsItem* lastItem = NULL;
    static int lastCnt = 0;
    if (count == 0)
    {
        ActiveScene()->GetPropertyLists(pptList);
        lastItem = NULL;
    }
    else if (count == 1)
    {
        item = ActiveScene()->selectedItems().first();
        if (CBaseData* dataPtr = g_dataPtr(item))
        {
            int type = item->type();
            dataPtr->GetPropertyLists(pptList);
        }
        lastItem = item;
    }
    else if (beSameType)
    {
        foreach(QGraphicsItem* pItem, ActiveScene()->Items(true, true))
        {
            if (CBaseData* dataPtr = g_dataPtr(pItem))
            {
                dataPtr->GetPropertyLists(pptList);
                break;
            }
        }
    }
    else
    {
        beSameType = true;
        int type = -1;
        CBaseData* dataPtr = NULL;
        foreach(QGraphicsItem* pItem, ActiveScene()->Items(true, true))
        {

            if (dataPtr == NULL)
            {
                dataPtr = g_dataPtr(pItem);
            }

            if (type == -1)
				type = dataPtr->Type();
			else if (dataPtr->Type() != type)
            {
                beSameType = false;
                break;
            }
        }
        if (dataPtr)
        {
            if (beSameType)
            {
                dataPtr->GetPropertyLists(pptList);
            }
            else
            {

                dataPtr->GetBasePropertyLists(pptList);
            }
        }

    }
    lastCnt = count;
    m_propertyEditor->CreatePropertySheet(pptList);
    if (count > 1)
    {
        m_propertyEditor->SetEnabled(QObject::tr("name"), false);
        m_propertyEditor->SetEnabled(QObject::tr("scenePos"), false);
        m_propertyEditor->SetEnabled(QObject::tr("postion"), false);
    }
	if (count == 0)
	{
		m_propertyEditor->SetEnabled(QObject::tr("showPlane"), false);
	}
	
    GetAnimDlg()->UpdateDlg(ActiveScene());
    Emit("_UpdatePropWnd","");
}

void CDesignerWnd::OnEditShowPpt()
{
    GetAnimDlg()->show();
    GetAnimDlg()->UpdateDlg(ActiveScene());
    
}

AnimationDlg* CDesignerWnd::GetAnimDlg()
{
    if(!m_AnimatDlg){
         m_AnimatDlg=new AnimationDlg(this, 0);
         m_AnimatDlg->hide();
    }
    return m_AnimatDlg;
}

void CDesignerWnd::SetupNaviDialog()
{
}


void CDesignerWnd::ResetDynamic( )
{

    QMessageBox::information(this, tr("Tips"),tr("ResetDBConnect done."));
}




void CDesignerWnd::SetupUndoView()
{
    QDockWidget* dock = new QDockWidget(tr("CommandDockWidget"), this);
    dock->setObjectName("CommandDockWidget");
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    m_undoView = new QUndoView;
    m_undoView->setWindowTitle(tr("Command List"));
    m_undoView->setMaximumHeight(200);
    m_undoView->setAttribute(Qt::WA_QuitOnClose, false);
    dock->setWidget(m_undoView);
}

void CDesignerWnd::SetupItemBox()
{
    m_pToolsDockWnd = new QDockWidget( tr( "ToolBoxDockWidget" ), this );
    m_pToolsDockWnd->setObjectName("ToolBoxDockWidget");
    m_pToolsDockWnd->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget( Qt::LeftDockWidgetArea, m_pToolsDockWnd);
    m_itemBox = new CItemBox(this);
    m_pToolsDockWnd->setWidget(m_itemBox);

}

void CDesignerWnd::LoadToolBox(QString filename)
{
    UnqItemMng()->SetupModelData(filename);
}

void CDesignerWnd::OnSubWindowActivated( QMdiSubWindow * window )
{
   // qDebug("In CGDesignerWnd::OnSubWindowActivated");

    static CDesignerScene* lastScene = NULL;
    CDesignerScene* scene = NULL;
    if (window )
        scene = (CDesignerScene*)((CMdiSubWindow*)window->widget())->GetView()->scene();

    if(lastScene == scene)
        return;

    Mdi::OnSceneActived(scene);

    if(scene)
    {
		QMatrix m = ((CMdiSubWindow*)window->widget())->GetView()->matrix();
		m_sceneScaleCombo->setCurrentText(QString("%1").arg(int(m.m11() * 100)) + "%");
        m_undoView->setStack(scene->GetUndoStack());
        lastScene = scene;
    }
    else
    {
        m_undoView->setStack(NULL);
    }

}

void CDesignerWnd::OnNodeGenerate()
{
    CDesignerScene* currentScene = ActiveScene();
    Q_ASSERT(currentScene);

    QString topoFileName = currentScene->NodeGenerate();
    if(topoFileName.isEmpty())
        return;

    QFile topoFile(topoFileName);
    if (!topoFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, tr("information"), tr("Can not open file!"));
        return;
    }

    QTextStream out(&topoFile);
    out.readLine();
    out.readLine();
    out.readLine();
    out.readLine();
    out.readLine();
    QString line = out.readLine();
    int stationId = line.split(' ').back().toInt();
    //qDebug("stationId: %d\n", stationId);
    out.readLine();
    out.readLine();
    out.readLine();

    QString linklineName, iconName1, iconName2;
    int pin1, keyId1, pin2, keyId2;
    QTextStream lineOut;
    do
    {
        line = out.readLine();
        if (line[0] !='#')
        {
            lineOut.setString(&line, QIODevice::ReadOnly);
            lineOut >> linklineName >> pin1 >> iconName1 >> keyId1 >> pin2 >> iconName2 >> keyId2;
            //qDebug()<<linklineName << pin1 << iconName1 << keyId1 << pin2 << iconName2 << keyId2;


        }

    } while (!line.isNull());

    topoFile.close();
}

void CDesignerWnd::OnSceneScaleChanged(const QString &scale)
{
    if(NULL==ActiveView())
        return;
    double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
    QMatrix oldMatrix = ActiveView()->matrix();
    ActiveView()->resetMatrix();
    ActiveView()->translate(oldMatrix.dx(), oldMatrix.dy());
    ActiveView()->scale(newScale, newScale);
}

void CDesignerWnd::OnObjectInspectorItemClicked(QGraphicsItem* item)
{
    ActiveScene()->clearSelection();
    item->setSelected(true);
    UpdatePropertySheet();
}



void CDesignerWnd::OnPlaneMaskChanged( const QBitArray& showPlaneMask)
{
    CGraphScene* scene = ActiveScene();
    Q_ASSERT(scene);

    scene->SetShowPlanes(showPlaneMask);
}

void CDesignerWnd::OnCurPlaneChanged(int curPlane)
{
    CGraphScene* scene = ActiveScene();
    Q_ASSERT(scene);
    scene->SetCurPlane(curPlane);
    UnqNameMng()->UpdateModel();

}

void CDesignerWnd::OnPatchCreateChanged(bool checked, int patchCreateNum)
{
    m_bPatchCreate = checked;
    m_iPatchCreateNum = patchCreateNum;
}

void CDesignerWnd::SetDrawSettings(const QVariantMap& setttings)
{
    m_DrawSettings=setttings;
    m_gtbar->setDrawSettings(m_DrawSettings);
}

QVariantMap CDesignerWnd::GetDrawSettings()
{
    return m_DrawSettings;
}


int CDesignerWnd::FileConvert(const QString& filename,const QString& outfilename )
{
#ifdef GSVG
    return QSvgTinyDocument::toSmartsys(filename,outfilename);
#endif
    return 0;

}

int CDesignerWnd::CheckName(QString fName, bool isIcon, bool askNameCover, QString iconTip)
{
	if (fName.isEmpty())
		return -1;
	
	QString core_name;
	UnqFunc()->GetGraphCoreNameByGraphPathName(fName, core_name);
	QString invalideStr = "<>@\"&%$:,;?={}|^~[]\'`\\* ()";
	if (isIcon)
	{
		core_name = core_name.replace(ICONSUFFIX, "");
		if (!UnqIconMng()->IsVaildIconName(core_name) || UnqItemMng()->GetAllTypeDef().keys().contains(core_name))
		{
			if (askNameCover)
			{
                if (QMessageBox::warning(0, tr("Tips"), tr("The icon name already been used, click Ok if still to use."), QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Cancel)
					return -1;
			}
			else
			{
                QMessageBox::information(0, tr("Tips"), tr("icon name already been used!"));
				return -1;
			}
		}

		if (!iconTip.isEmpty())
		{
			if (UnqItemMng()->GetAllTypeDef().values().contains(iconTip))
			{
                QMessageBox::information(0, tr("Tips"), tr("icon displayName already been used!"));
				return -1;
			}
		}
		core_name = core_name.replace(ICONPREFIX, "");
		invalideStr = "<>@#\"&%$:,;?={}|^~[]\'`\\* ()";// can not use # in xml : gtoolbox.xml
	}

	if (core_name.length() > FILENAME_MAX_LENGTH)
	{
        QMessageBox::warning(0, tr("Tips"), tr("File name length must not exceed %1 characters ").arg(FILENAME_MAX_LENGTH));
		return -1;
	}

	
	for (int i = 0; i<invalideStr.length(); i++)
	{
		if (core_name.indexOf(invalideStr[i]) != -1)
		{
            QMessageBox::warning(0, QObject::tr("warn"), QString(tr("The file name has invalid char:  %1").arg(invalideStr)));
			return -1;
		}
	}
	if (isIcon)
	{
		if ((core_name.at(0) >= QChar('0')) && (core_name.at(0) <= QChar('9')))
		{
            QMessageBox::warning(0, QObject::tr("warn"), tr("The file name cannot start with a number!"));// can not start with a number in xml
			return -1;
		}
	}

	return 0;
}

QObject* CDesignerWnd::FindChild(const QString& componentName )
{
    if(componentName.startsWith("_act_")){
        int idx=componentName.right(componentName.length()-5).toInt();
        if(idx>=0 && idx<ACTION_ORDERNUM){
            QAction* act=UnqActMng()->GetAction((ACTION_ORDER)idx);
            //act->setVisible(false);
            return act;
        }
    }

    return CGWnd::FindChild(componentName);
}

void CDesignerWnd::retranslateUi()
{
    UnqActMng()->retranslateUi();
    m_pToolsDockWnd->setWindowTitle(tr( "ToolBoxDockWidget" ));
    m_pPropertyDockWnd->setWindowTitle(QObject::tr(G_STR_property_editor));
    QStringList headLabels;
    headLabels<<QObject::tr("Property")<<QObject::tr("Value");
    m_propertyEditor->SetHeaderLabels(headLabels);

    CGWnd::retranslateUi();
}
