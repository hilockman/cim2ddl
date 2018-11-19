

#include "Global.h"
#include "GFunc.h"

#include "../ConstString.h"
#include "BaseData.h"
#include "ActionManager.h"
#include "DrawManager.h"
#include "NameManager.h"
#include "DesignerView.h"
#include "GWnd.h"
#include "DesignerScene.h"
#include "CommunicatePluginMng.h"
#include "IconMng.h"
#include "IconDlg.h"
#include "ItemBox.h"
#include "qscriptedit_p.h"
#include "CQScriptWrap.h"
#include "GDApp.h"
#include "DesignerWnd.h"
#include "AnimateDriver.h"

CDesignerView::CDesignerView(CGWnd *w, CGraphScene* scene, QWidget *parent, const char *name, Qt::WindowFlags f)
    : CGraphView (scene,parent ),m_pGraphWnd(w)
{
    setObjectName("Me");
    m_pScene=(CDesignerScene*)scene;
    if (m_pScene==NULL)
    {
        m_pScene = new CDesignerScene(this);
    }
    setScene(m_pScene);
    m_StopPaint = false;
    m_dragStartPos = QPoint();
    m_isScaleByMidButton = false;
    m_EditType=EDITPIC;
	m_actionItemInfo = "";
    viewport()->setBackgroundRole(QPalette::Dark);
    viewport()->setFocusPolicy(Qt::StrongFocus);
    viewport()->setMouseTracking(true);
    setAcceptDrops(true);
    setDragMode(QGraphicsView::RubberBandDrag);

    m_pGraphWnd->m_Views.append(this);
    AddQSObject();
    installEventFilter(this);
}

CDesignerView::~CDesignerView()
{
    m_pGraphWnd->m_Views.removeOne(this);
    QApplication::restoreOverrideCursor();
    if(m_pScene != NULL)
    {
        delete m_pScene;
        m_pScene = NULL;
    }

}

void CDesignerView::SetMainWindow(CGWnd *w)
{
    m_pGraphWnd = w;
    AddQSObject();
}


/*!
\brief 执行一段脚本命令 <br>
\param [in] script_code -  脚本内容
*/
QVariant CDesignerView::DoCmd(QString script_code) //执行脚本
{
    if (!Scene())
        return "No appoint scene";
    return Scene()->GetScriptEngine()->Evaluate(script_code) ;
}

void CDesignerView::AddQSObject()
{
    CScriptEngine* pScriptEngine=m_pScene->GetScriptEngine();
    pScriptEngine->AddObject(this,"Me");
    pScriptEngine->AddObject(m_pGraphWnd,"Window");

    QMap<QString,QObject*> tmpmap=((CGDApp*)qApp)->GetQSObject();
    QMap<QString, QObject*>::const_iterator i ;
    for(i = tmpmap.constBegin();i!=tmpmap.constEnd();++i)
    {
        pScriptEngine->AddObject(i.value(),i.key());
    }

    QVariantMap args=((CGDApp*)qApp)->GetArgs().toMap();
    QString script=args["js"].toString();
    if(script.length()<1)
        script="hmiEditor.js";


    pScriptEngine->LoadFile(script);

}

void CDesignerView::Repaint(QRect rect,bool erase)
{

    repaint(rect );
}
void CDesignerView::Repaint ( bool erase )
{
    viewport()->update();
}


void CDesignerView::OnNaviViewPosChg(float x,float y)
{
    QRectF sceneRect = m_pScene->sceneRect();
    float pos_x=x*sceneRect.width();
    float pos_y=y*sceneRect.width();
    QPoint pos=QPoint(pos_x,pos_y);
    centerOn(pos);
}

void CDesignerView::contextMenuEvent ( QContextMenuEvent * event)
{
    if(m_pScene->ReadOnly()) return;
	m_actionItemInfo = "";
    QPoint vp=event->pos();
    if(IsCursorBeyond(vp))
        return;

	if (!UnqDrawMng()->IsMoveMode())
	{
		UnqDrawMng()->contextMenuEvent(this, event);
		return;
	}

    QMenu contextMenu(this);
    UnqActMng()->CreateContextMenu(contextMenu);
    contextMenu.addSeparator();
    QPoint pos = event->pos() ;
    QString msg = "";
    QObject* curobj =GetItemInfo(pos,  msg);

    if (curobj && (curobj->inherits("CWidgetData") || curobj->inherits("CGChartData")))
    {
        //return QGraphicsView::contextMenuEvent(event);
    }

    QVariantList args;
    args.append( msg);
    QVariant ret = Scene()->GetScriptEngine()->Call("getContextMenu", args);
    if (ret.toString().indexOf("error:") == -1)
    {
        PopupContextMenu( ret,contextMenu);
    }
    contextMenu.exec(event->globalPos());
    QGraphicsView::contextMenuEvent(event);


}
 
void CDesignerView::mousePressEvent(QMouseEvent* e)
{
    if(m_pScene->ReadOnly()) return;
    QPointF pv=e->pos();
    QGraphicsView::mousePressEvent(e);

	if (e->button() == Qt::LeftButton)
	{
		QString msg = "";
        QObject* curobj = GetItemInfo(pv.toPoint(), msg);
        //
        QList<QGraphicsItem*> lst = this->items(pv.toPoint());
        QObjectList olst;
        for (int li = 0; li < lst.size(); li++)
        {
            CBaseData* pdata = g_dataPtr(lst.at(li));
            if(pdata) olst.append(pdata);
        }
        //
        emit LeftClicked(curobj, msg,olst);
	}

    if (e->button() == Qt::MidButton)
    {        
        m_isScaleByMidButton = true;
    }
    m_dragStartPos = pv.toPoint();
    //gInfo("---m_dragStartPos--%d,%d", m_dragStartPos.x(), m_dragStartPos.y());
}

void CDesignerView::mouseMoveEvent(QMouseEvent* e)
{
    if(m_pScene->ReadOnly()) return;
    if(e->buttons() & Qt::MidButton)
    {
        QScrollBar *hBar = horizontalScrollBar();
        QScrollBar *vBar = verticalScrollBar();
        QPoint delta = e->pos() - m_dragStartPos;
        hBar->setValue(hBar->value() - delta.x());
        vBar->setValue(vBar->value() - delta.y());
        setCursor(Qt::ClosedHandCursor);
        m_dragStartPos = e->pos();
        m_isScaleByMidButton = false;
        return;
    }
	QPoint vp = e->pos();
    //if (IsCursorBeyond(vp))  return;
	QGraphicsView::mouseMoveEvent(e);
}


void CDesignerView::mouseDoubleClickEvent(QMouseEvent* e)
{
    if(m_pScene->ReadOnly()) return;
    QPoint vp=e->pos();
    if(IsCursorBeyond(vp))
        return;
    QGraphicsView::mouseDoubleClickEvent(e);
}


void CDesignerView::mouseReleaseEvent(QMouseEvent * e)
{
    if(m_pScene->ReadOnly()) return;
    if(e->button() == Qt::MidButton)
    {
        unsetCursor();
        if(m_isScaleByMidButton)
            scale(1.25, 1.25);
        m_isScaleByMidButton = false;
        return;
    }

    QPoint vp=e->pos();
    CGraphView::mouseReleaseEvent(e);

    ((CDesignerWnd*)m_pGraphWnd)->UpdatePropertySheet();
}


void CDesignerView::wheelEvent( QWheelEvent* e )
{
    m_isScaleByMidButton = false;
    CGraphView::wheelEvent(e);
}

void CDesignerView::keyPressEvent ( QKeyEvent * e )
{
    if(m_pScene->ReadOnly()) return;
    CGraphView::keyPressEvent(e);
}

bool CDesignerView::IsCursorBeyond(const QPointF& viewPos)
{
    return false;
    return !scene()->sceneRect().contains(mapToScene(viewPos.toPoint()));
}

QObject* CDesignerView::GetItemInfo(QPoint pos, QString& msg)
{
    QObject* pobj=CGraphView::GetItemInfo( pos,  msg);
	if (!pobj || (pobj && !pobj->inherits("CBaseData")))
        return NULL;
	QString tagInfo;
	if (pobj)
	{
		tagInfo = CAnimation::GetTagInfo(((CBaseData*)pobj)->Item());
	}		

    QJsonObject jsonObj=UnqFunc()->Str2Json(msg);
    jsonObj["taginfo"] =tagInfo;
    msg=UnqFunc()->Json2Str(jsonObj);
    return pobj;
}

void CDesignerView::ShowTip(QPoint pos)
{
    QString msg;
    QObject* curobj =GetItemInfo( pos, msg);
    setToolTip(msg);
    setCursor(Qt::ArrowCursor);
    emit TipEvent(curobj,msg);

}

QString CDesignerView::NodeGenerate()
{
    return m_pScene->NodeGenerate();
}

QObject*  CDesignerView::CenterOn(QString itemName)
{
    QObject* obj=CGraphView::CenterOn(itemName);
    CDesignerWnd* pwnd=(CDesignerWnd*)(m_pGraphWnd);
    if(pwnd) pwnd->UpdatePropertySheet();
    return obj;
}

QObject* CDesignerView::FindChild(const QString& name)
{
    if(name== "codePage" ){
        //CMdiSubWindow* psWnd=dynamic_cast<CMdiSubWindow*>(parent());
    }else if(name== "parent" ){
        CMdiSubWindow* psWnd=dynamic_cast<CMdiSubWindow*>(parent());
        return psWnd;
    };
    QObject *dw =  findChild<QObject *>(name,Qt::FindChildrenRecursively);
    if(dw==NULL)
    {
         gError( "cannot find this Component" );
         return NULL;
    }
    return dw;
}

//
int ICON_SIZE = 50;
CMdiSubWindow::CMdiSubWindow(CGWnd* pwnd,QWidget *parent, Qt::WindowFlags flags)
    : QTabWidget(parent)
{
    m_pWnd=(CDesignerWnd*)pwnd;
    QWidget *pPage1 = new QWidget(this);
    QVBoxLayout *verticalLayout = new QVBoxLayout(pPage1);
    verticalLayout->setSpacing(1);
    verticalLayout->setContentsMargins(1,1,1,1);
    m_pTabBar = new QTabBar(pPage1);
    m_pTabBar->setExpanding(false);
    m_pTabBar->setMovable(true);
    m_pTabBar->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_pTabBar, SIGNAL(customContextMenuRequested(const QPoint &)), this,SLOT(OnToolBarContextMenu(const QPoint &)));
    connect(m_pTabBar, SIGNAL(currentChanged(int)), this, SLOT(OnCurrentPlaneChanged(int)));
    connect(m_pTabBar, SIGNAL(tabMoved(int, int)), this, SLOT(OnPlaneMoved(int, int)));

    verticalLayout->addWidget(m_pTabBar);
    m_pScene =new CDesignerScene(NULL);
    m_pView =new CDesignerView(m_pWnd,m_pScene, this);

    verticalLayout->addWidget(m_pView);
    m_pCodeEdit=new QScriptEdit();
    m_pCodeEdit->setObjectName("codePage");

    addTab(pPage1,tr("canvas"));
    if(m_pWnd->property("_disable_script_page_").toBool()==true)
        m_pCodeEdit->hide();
    else
        addTab(m_pCodeEdit,tr("code"));

    setTabPosition(QTabWidget::South);

}

CMdiSubWindow::~CMdiSubWindow()
{
}

void CMdiSubWindow::FileNew( QString& fileName)
{
    int ret =-1;
    if (fileName.isEmpty())
        return ;

    QStringList planelist;
    planelist<<tr("plane")+"0";
    if(fileName.right(4)==ICONSUFFIX)
    {
        m_pScene->SetSceneType(Hmi::Iconer);
        QStringList iconInfo;
        QPixmap fileIcon;
        IconSetDlg dlg(fileIcon,iconInfo,this);
        dlg.Init();
        if (dlg.exec()== QDialog::Rejected)
        {
			parentWidget()->close();
            return;
        }
        QString iconName=iconInfo[0];
        int type=iconInfo[1].toInt();
        UnqFunc()->GetIconPathNameByIconCoreName(iconName,fileName);

		QString typeName, planeInfo, isPinPlane;
        int pinNum, stateNum;
		UnqIconMng()->GetIconType(type, typeName, pinNum, stateNum, planeInfo, isPinPlane);
        m_pScene->SetFileType(type);
        planelist=planeInfo.split(",");

		m_pScene->SetIconInfo(iconInfo[3], iconInfo[2]);
    }
	else
    {
        m_pScene->SetSceneType(Hmi::Designer);
		m_pScene->SetPlaneNames(planelist.join(","));
    }

    QString fn;
    UnqFunc()->GetGraphNameByGraphPathName(fileName,fn);
    setWindowTitle(fileName);

    AddPlaneCtlBar(planelist);
    InitUI();
    showMaximized();
    m_pScene->SetModified(true);
}

void CMdiSubWindow::InitUI()
{
    QVariantMap settings=m_pWnd->GetDrawSettings();
    QString bgcolor=settings["bgcolor"].toString();
    if(!bgcolor.isEmpty())
    {
        m_pScene->setBackgroundBrush(QColor(bgcolor));
    }
    if (m_pScene->GetSceneType()==Hmi::Iconer)
    {
		m_pScene->SetLayoutRect(QRect(0, 0, ICON_SIZE, ICON_SIZE));
		qreal kk = 10;// abs(800 / ICON_SIZE);
		m_pView->scale(kk,kk);
		m_pTabBar->setMovable(false);
		m_pTabBar->setContextMenuPolicy(Qt::NoContextMenu);
    }
}

void CMdiSubWindow::FileOpen(QString& fileName, bool isImport, bool isBinary)
{
    int ret =-1;
    if (fileName.isEmpty())
        return ;
	
    if(fileName.right(4)==ICONSUFFIX)
    {
        m_pScene->SetSceneType(Hmi::Iconer);
    }
	InitUI();

	if (isImport)
		m_pScene->FileImport(fileName);
	else
		m_pScene->FileOpen(fileName, isBinary);

    int fType=m_pScene->GetFileType();
    int planes=m_pScene->GetPlaneNums();
    int states=m_pScene->GetStateNums();

    QString fn;
    UnqFunc()->GetGraphNameByGraphPathName(fileName,fn);
    setWindowTitle(fileName);

	QString typeName, planeInfo, isPinPlane;
    int pinNum, stateNum;
    QStringList list;
    if (m_pScene->GetSceneType()==Hmi::Iconer)
    {
		UnqIconMng()->GetIconType(fType, typeName, pinNum, stateNum, planeInfo, isPinPlane);
        list =planeInfo.split(",");
        if(states>list.size())
        {
            for(int i=list.size();i<states;i++)
                list<<QString("plane%1").arg(i);
        }
		m_pScene->SetIconInfo("", UnqItemMng()->ItemDisplayName(UnqIconMng()->GetRegIconName(fn.replace(ICONSUFFIX,""))));
        QRect rc = m_pScene->GetLayoutRect();
        if(rc.width()==0 || rc.height()==0)
            rc=rc| QRect(0, 0, ICON_SIZE, ICON_SIZE);
		m_pScene->SetLayoutRect( rc);
		qreal kk = (qreal)700 / (rc.width()>rc.height() ? rc.width() : rc.height());
		m_pView->resetMatrix();
		m_pView->scale(kk,kk);

    }
    else
    {
		list = m_pScene->GetPlaneNames().split(",");
		if (list.size()<planes)
		{
			for (int i = list.size(); i < planes; i++)
				list << QString("plane%1").arg(i);
		}
		
    }
    AddPlaneCtlBar(list);
    m_pCodeEdit->setPlainText(m_pScene->GetScript());
    connect(m_pCodeEdit, SIGNAL(textChanged()), this, SLOT(OnCodeChanged()));
    showMaximized();
	m_pView->verticalScrollBar()->setValue(0);
}

void CMdiSubWindow::OnCodeChanged()
{
    m_pScene->SetModified(true);
}


int CMdiSubWindow::FileSave(QString& fileName, bool isBinary )
{
    if(m_pScene->ReadOnly()){
        QMessageBox::warning(this, tr("tip"), tr("this file is read only,Can not save this file. ") );
        return -1;
    }
    int scenetype=m_pScene->GetSceneType();
    int ftype=m_pScene->GetFileType();
    if ( fileName.isEmpty() || fileName.indexOf("untitle")>=0)
    {
        QString title = QObject::tr("Save");
        QString path;
        if (fileName.right(4) == ICONSUFFIX || scenetype==Hmi::Iconer)
        {
            path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ICON);
            //fileName = QFileDialog::getSaveFileName(this, title,path,QString("pic(*%1)").arg(ICONSUFFIX));
			int ret = -1;
			while (ret < 0)
			{
				QFileDialog* dlg = new QFileDialog(this, title, fileName.isEmpty() ? path : fileName, QString("pic(*%1)").arg(ICONSUFFIX));
				dlg->setAcceptMode(QFileDialog::AcceptSave);
				if (dlg->exec() == QDialog::Accepted)
				{
					fileName = dlg->selectedFiles().at(0);
					ret = m_pWnd->CheckName(fileName);
				}
				else
                    return -1;
			}			
			m_pScene->SetIconInfo("","");
        }
        else
        {
            path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC);
			QString filterStr = PICSUFFIX;
			if (isBinary)
				filterStr = PICBINARYSUFFIX;
			fileName = fileName.replace("_tmp", "");
			int ret = -1;
			while (ret < 0)
			{
				QFileDialog* dlg = new QFileDialog(this, title, fileName.isEmpty()?path:fileName, QString("pic(*%1)").arg(filterStr));
				dlg->setAcceptMode(QFileDialog::AcceptSave);
				if (dlg->exec() == QDialog::Accepted)
				{
					fileName = dlg->selectedFiles().at(0);
					ret = m_pWnd->CheckName(fileName);
				}
				else
                    return -1;
			}
        }

	}
	else
	{
		if (isBinary)
			fileName = fileName.replace(PICSUFFIX, PICBINARYSUFFIX );
		else
			fileName = fileName.replace(PICBINARYSUFFIX, PICSUFFIX);
	}
	/*int ret = m_pWnd->CheckName(fileName);
    if(ret<0)
        return;*/

    m_pScene->SetScript(m_pCodeEdit->toPlainText());
    if(scenetype==Hmi::Iconer)
    {
        m_pScene->SaveIconByScene( fileName,QString("%1").arg(ftype));
    }
    else
    {
		m_pScene->FileSave(fileName, isBinary);
    }

    setWindowTitle(fileName);
	m_pWnd->SyncFile(fileName);
    return 0;
}

void CMdiSubWindow::AddPlaneCtlBar(QStringList& ctls)
{
    int index=m_pTabBar->count();
    foreach (const QString &str, ctls) {
        m_pTabBar->addTab(str);
        if (m_pScene->GetPlaneNums() < index + 1)
        {
            m_pScene->SetPlaneNums(index+1);
            QBitArray planes = m_pScene->GetShowPlanesMask();
            planes.resize(index + 1);
            planes.fill(true);
            m_pScene->SetShowPlanes(planes);
        }

        QCheckBox* chkBox=new QCheckBox();
        chkBox->setChecked( (m_pScene->GetShowPlanesMask())[index] );
        chkBox->setToolTip(QString("%1").arg(index));
        m_pTabBar->setTabButton(index, QTabBar::LeftSide, chkBox);
        connect(chkBox,SIGNAL(stateChanged(int)),this,SLOT(OnPlaneChkChg(int)));
        index++;
    }
}

void CMdiSubWindow::OnCurrentPlaneChanged(int index)
{
    m_pScene->SetCurPlane(index);
	m_pScene->clearSelection();

}

void CMdiSubWindow::OnPlaneChkChg(int chkState)
{
    QCheckBox *chkBox = (QCheckBox*) sender();
    int planeIdx=chkBox->toolTip().toInt() ;
    QBitArray planeArray=m_pScene->GetShowPlanesMask();
    if(chkState==Qt::Checked)
        planeArray.setBit(planeIdx,1);
    else
        planeArray.setBit(planeIdx,0);
    m_pScene->SetShowPlanes(planeArray);
    m_pScene->UpdateScene();
}

void CMdiSubWindow::OnPlaneCtl(QAction *act)
{
    QString icon_name, icon_path;
    QString name;
    QString action_name = act->text();

    int nums = m_pScene->GetPlaneNums();

    if (action_name == tr("add plane"))
    {
        m_pScene->SetPlaneNums(nums + 1);

        QBitArray showPlane = m_pScene->GetShowPlanesMask();
        showPlane.resize(nums + 1);
        showPlane.setBit(nums, true);
        m_pScene->SetShowPlanes(showPlane);

        name = QString(tr("plane%1").arg(nums));
		while (!IsValidPlaneName(name))
		{
			name = QString(tr("plane%1").arg(++nums));
		}
        QStringList ctls=(QStringList() << name);
        AddPlaneCtlBar(ctls);
    }
    else if (action_name == tr("delete plane"))
    {
        if (nums == 1)
        {
			QMessageBox::information(this,tr("Tips"),tr("at least one layer, can not to delete!"));
            return;
        }

        int delIdx = m_pTabBar->currentIndex();
        m_pScene->DelPlane(delIdx);

        for (int i = delIdx + 1; i < nums; i++)
        {
            ((QCheckBox*)m_pTabBar->tabButton(i, QTabBar::LeftSide))->setToolTip(QString("%1").arg(i - 1));
        }

        m_pTabBar->removeTab( delIdx );
    }
    else if (action_name == tr("rename plane"))
    {
		bool ok;
		QString text = QInputDialog::getText(this, tr("rename plane"),
			tr("Plane name:"), QLineEdit::Normal,
			m_pTabBar->tabText(m_pTabBar->currentIndex()), &ok);
		if (ok && !text.isEmpty())
		{
			if (!IsValidPlaneName(text))
			{
				QMessageBox::information(this, tr("Tips"), tr("plane name already been used, rename failed!"));
				return;
			}
			m_pTabBar->setTabText(m_pTabBar->currentIndex(), text);
		}
    }
	QStringList names;
	for (int j = 0; j < m_pTabBar->count(); j++)
		names.append(m_pTabBar->tabText(j));
	m_pScene->SetPlaneNames(names.join(","));
}

bool CMdiSubWindow::IsValidPlaneName(const QString &name)
{
	QStringList lst = m_pScene->GetPlaneNames().split(",");
	if (lst.contains(name))
		return false;
	return true;
}

void CMdiSubWindow::OnToolBarContextMenu(const QPoint & pos)
{
    int posIdx = m_pTabBar->tabAt(pos);
    if (posIdx >= 0 && posIdx < m_pTabBar->count())
        m_pTabBar->setCurrentIndex(posIdx);

    QMenu menu(m_pTabBar);
    menu.addAction(tr("add plane"));
    menu.addAction(tr("delete plane"));
	menu.addAction(tr("rename plane"));
    connect(&menu, SIGNAL(triggered(QAction *)), this, SLOT(OnPlaneCtl(QAction *)));

    QPoint pos1 = m_pTabBar->mapToGlobal(pos);
    menu.exec(pos1);
}

void CMdiSubWindow::OnPlaneMoved(int from, int to)
{
    m_pScene->MovePlane(from, to);

    if (from > to)
    {
        int tmp = from;
        from = to;
        to = tmp;
    }
    for (int i = from; i <= to; i++)
    {
        ((QCheckBox*)m_pTabBar->tabButton(i, QTabBar::LeftSide))->setToolTip(QString("%1").arg(i));
    }
	QStringList names;
	for (int j = 0; j < m_pTabBar->count(); j++)
		names.append(m_pTabBar->tabText(j));
	m_pScene->SetPlaneNames(names.join(","));
}

void CMdiSubWindow::closeEvent(QCloseEvent * e)
{
    if (m_pWnd->NeedSave(tr("Close")))
    {

        e->accept();
    }
    else
        e->ignore();
}
