
#include "ExplorerView.h"
#include "GWnd.h"
#include "ExplorerScene.h"
#include "CQScriptWrap.h"
#include "GFunc.h"
#include "BaseData.h"
#include "GroupItem.h"
#include "AnimateDriver.h"
#include "CommunicatePluginMng.h"
#include "ExplorerWnd.h"
#include "elog.h"
#include "Global.h"
#include <set>
#include "gloweffect.h"

#ifdef GLUT
#include <QtOpenGL>
#endif


int DEFAULT_UPDATE_ITV=15;

CGExplorerView::CGExplorerView(CGWnd *w,CGraphScene* scene,QWidget *parent, const char *name,Qt::WindowFlags f)
    : CGraphView (scene,parent ),m_pGraphWnd(w)
{
    m_pScene = (CGExplorerScene *)scene;
    if (m_pScene==NULL)
    {
        m_pScene = new CGExplorerScene( 0);
        m_pScene->setSceneRect(QRectF(0, 0, 1000, 900));
        setScene(m_pScene);
    }
    m_pHotItem = NULL;
    m_pHotSrcItem=NULL;
    m_SrcOpacity=-1;
    m_pTimer = NULL;
	m_rubberBand = NULL;
	m_tokenLine = NULL;
    m_Args = "";
    m_OldFileName = "";
    m_ZoomRect = QRect(0,0,0,0);
	m_AreaSelectRect = QRect(0, 0, 0, 0);
    m_TimerCount = 0;
    m_BlockSignal =false;
    SetAreaSelectFlag(false);
    setStyleSheet(" border: 0px  ");
    setObjectName("Me");
    m_lastOpIsMove=false;

    viewport()->setMouseTracking(true);
   // viewport()->setBackgroundRole(QPalette::Dark);
    viewport()->setFocusPolicy(Qt::StrongFocus);
    viewport()->setAcceptDrops(true);

    installEventFilter( this );
	this->setAttribute(Qt::WA_DeleteOnClose);
    m_pGraphWnd->m_Views.append(this);

	m_pTimer = new QTimer( this);
    connect( m_pTimer, SIGNAL(timeout()), this, SLOT(TimeOut()) );
    m_pTimer->start( 500 );
}

CGExplorerView::~CGExplorerView()
{
    //m_pScene->GetScriptEngine()->Call("end()");
   // gInfo("~CGExplorerView--size=%d ",m_pGraphWnd->m_Views.size());
    m_pGraphWnd->m_Views.removeOne(this); //
    emit   OnClose();
    //((CGApp*)qApp)->EmitSignal("SigFileClose",m_CurFile);

    if (m_pTimer!=NULL)
    {
        delete m_pTimer;
        m_pTimer=NULL;
    }

    if(m_pScene != NULL)
    {
        delete m_pScene;
        m_pScene = NULL;
    }
}

void CGExplorerView::SetViewMode(QString mode)
{
#ifdef GLUT
    if(mode=="opengl")
    {
        QGLWidget* pGL=new QGLWidget(QGLFormat(QGL::SampleBuffers));
        pGL->makeCurrent();
        setViewport(pGL);
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    }
    else
    {
        setViewport(0);
        setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
    }
#endif
}

QObjectList CGExplorerView::FindItemPtr(QString tagName)
{
	QObjectList ret;
	QList<CBaseData*> dataList = m_pScene->GetAnimateDriver()->FindItem(tagName);
	foreach(CBaseData* pdata, dataList)
	{
		ret.append(pdata);
		m_pScene->GetScriptEngine()->AddObject(pdata, pdata->GetName());
	}
	return ret;
}

QVariantMap CGExplorerView::FindItemPtrByDev(QString devTagName)
{
    return m_pScene->GetAnimateDriver()->FindItemByDev(devTagName);
}


void CGExplorerView::Free()
{
	m_pScene->GetScriptEngine()->Call("end()");
    Hide();
    QTimer::singleShot(500, this, SLOT(Close()));
}

void CGExplorerView::Hide()
{
    hide();
    if (parent() && (parent()->inherits("QMdiSubWindow") || parent()->inherits("QDockWidget")) )
    {
        parentWidget()->hide();
    }
}

void CGExplorerView::Show()
{
    show();
    raise();
    if (parent() && (parent()->inherits("QMdiSubWindow") || parent()->inherits("QDockWidget")))
    {
        parentWidget()->show();
		parentWidget()->raise();
    }
}

void CGExplorerView::ZoomAll()
{
    //parentWidget()->showMaximized();
    showMaximized();
    QRectF rc = Scene()->sceneRect();
    FitInView(rc,  Qt::IgnoreAspectRatio);//);KeepAspectRatio//Qt::AspectRatioMode:The effect of each value is the same

    return;
/*
    if(m_pScene->GraphShowMode()==1)
        return ;
    ResetMatrix();
    if (parent() && (parent()->inherits("QMdiSubWindow") ))
    {
        parentWidget()->showMaximized();
        QSize size=parentWidget()->size();
        if(parentWidget()->width()>0 && parentWidget()->height()>0)
        {
        float fw=sceneRect().width()/parentWidget()->width();
        float fh=sceneRect().height()/parentWidget()->height();
        float ff=fw>fh?fw:fh;
        scale(1/ff,1/ff);
        }
    }
    else
    {
        if(geometry().width()>0 && geometry().height()>0)
        {
        float fw=sceneRect().width()/geometry().width();
        float fh=sceneRect().height()/geometry().height();
        float ff=fw>fh?fw:fh;
        scale(1/ff,1/ff);
        }
    }
    */
}

void CGExplorerView::Close()
{
    //qDebug("------CGExplorerView::Close()--filename=%s-",CurrentFile().toLocal8Bit().data());
	if (parent())
	{
		if (parent()->inherits("QMdiSubWindow")){

		m_pGraphWnd->m_pWorkspace->removeSubWindow(parentWidget());
		parentWidget()->deleteLater();
	    }
		else if (parent()->inherits("QDockWidget"))
		{
			QDockWidget* dockWnd = (QDockWidget*)parentWidget();
			m_pGraphWnd->removeDockWidget(dockWnd);
			dockWnd->deleteLater();
		}
    }
    close();
}

void CGExplorerView::TimeOut()
{
    int ret=0;
    int update_itv=m_pScene->GetRefreshInterval();
    if (update_itv<=15)
    {
        update_itv=DEFAULT_UPDATE_ITV;
    }
    m_TimerCount = (m_TimerCount + 1 ) % 10000;

    Advance(m_TimerCount*500);
}

void CGExplorerView::Advance(long time_ms)
{
    m_pScene->GetAnimateDriver()->Advance(time_ms);
}

void CGExplorerView::closeEvent(QCloseEvent *event)
{
    if(true)
    {
        event->accept();
    } else
    {
        event->ignore();
    }
}

void CGExplorerView::AddQSObject()
{
    CScriptEngine* pScriptEngine=m_pScene->GetScriptEngine();
    //pScriptEngine->EnableDebug(true);
    pScriptEngine->AddObject(this,"Me");
    pScriptEngine->AddObject(m_pGraphWnd);

    //viewport()->setObjectName("Form");
    //pScriptEngine->AddObject(viewport(),"Form");
    //CQmlEngine* pQmlEngine=m_pScene->GetQmlEngine();
    //pQmlEngine->AddObject(this,"Me");

    QMap<QString,QObject*> tmpmap=((CGApp*)qApp)->GetQSObject();
    QMap<QString, QObject*>::const_iterator i ;
    for(i = tmpmap.constBegin();i!=tmpmap.constEnd();++i)
    {
        pScriptEngine->AddObject(i.value(),i.key());
        //pQmlEngine->AddObject(i.value(),i.key());
    }

    QVariantMap args=((CGApp*)qApp)->GetArgs().toMap();
    QString init_script=args["js"].toString();
    if(init_script.length()<1){
        init_script=m_pGraphWnd->property("__init_script__").toString();
        if(init_script.length()<1){
            init_script="hmiCommon.js";
            gInfo("----load --%s",init_script.toLocal8Bit().data());
        }
    }
    LoadScript(init_script);
}

QString CGExplorerView::GetKeyInfo()
{
    return m_pScene->GetAnimateDriver()->GetReplaceInfo();
}

int CGExplorerView::FileOpen(const QString &fileName,const QString& replace_info, int wnd_flags,QVariant args)
{
    int retcode=-1; 
    QString tmp_filename=fileName;
    CScriptEngine* pScriptEngine=m_pScene->GetScriptEngine();
    if (tmp_filename.isEmpty())
    {
        QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIC);
        tmp_filename = QFileDialog::getOpenFileName(NULL, tr("Open File"),path, tr("pic (*.svg)"));
    }
    if (tmp_filename.isEmpty())
        return -1;

    UnqFunc()->GetGraphPathNameByGraphName(tmp_filename,tmp_filename);
    //if(!QFile::exists(tmp_filename))     return -1;

    if(!m_CurFile.isEmpty())  pScriptEngine->Call("end()");
    m_CurFile=tmp_filename;

    SetArgs(args);
    m_BlockSignal=true;

    if(replace_info!="append") ////如果是append则追加内容，不清除原有内容/////
        m_pScene->Reset();
    /*QPen pen(Qt::green,2,Qt::DotLine);
    m_pHotItem = m_pScene->addPath(QPainterPath(), pen);
    */
    m_pHotSrcItem=NULL;
    m_tokenLine=NULL;

    pScriptEngine = m_pScene->GetScriptEngine();
    m_BlockSignal=false;

    ResetMatrix();
    if ( verticalScrollBar() )
        verticalScrollBar()->setSliderPosition( 0 );
    if ( horizontalScrollBar() )
        horizontalScrollBar()->setSliderPosition( 0 );

    UnqFunc()->TmDebug("--before m_pScene->FileOpen--"+m_CurFile);

    retcode = m_pScene->FileOpen(m_CurFile.toLocal8Bit().data(), replace_info);

    UnqFunc()->TmDebug("--end    m_pScene->FileOpen--");
	AddQSObject();
    UnqFunc()->TmDebug("--end    AddQSObject--");

    QString wnd_alias=m_pScene->GetAlias();
    int tmp_wnd_flags=m_pScene->GetWndPropFlags();
    int wnd_modal=m_pScene->WindowModality();
    if (!wnd_alias.isEmpty())
    {
        SetWndAlais(wnd_alias);
    }
    if (wnd_flags==Qt::Dialog)
    {
        int flags=Qt::Dialog|tmp_wnd_flags;
        if (tmp_wnd_flags & Qt::FramelessWindowHint ==0){
            flags=Qt::ToolTip| Qt::WindowStaysOnTopHint;
        }
        else
            flags |= Qt::CustomizeWindowHint;

        setWindowFlags((Qt::WindowFlags)flags );
        if (wnd_modal==Qt::ApplicationModal)
        {
            setWindowModality(Qt::WindowModal);//use Qt::WindowModal for hover out event to lose cursor
        }
        SetAreaSelectFlag(false);
        setWindowTitle(m_pScene->GetWndTitle());
		//setAttribute(Qt::WA_TranslucentBackground);//锟斤拷锟矫憋拷锟斤拷透锟斤拷
    }
    QString script=m_pScene->GetScript();
    if (!script.isEmpty() )
    {
        pScriptEngine->Evaluate(script );
    }

    UnqFunc()->TmDebug("--over pScriptEngine->Evaluate--");

#if 1
    if (!script.isEmpty() )
    {
        if (script.indexOf("begin()")!=-1)
            pScriptEngine->Call("begin()");
        else
            pScriptEngine->Call("g_begin()");
    }
    else
        pScriptEngine->Call("g_begin()");
#endif
    UnqFunc()->TmDebug("--over call g_begin--");

    QRect grect=m_pScene->GetLayoutRect();

    QRect wndrect = m_pGraphWnd->geometry() ;
    QDesktopWidget *dw = QApplication::desktop();
    QRect viewport_rect = m_pGraphWnd->m_pWorkspace->viewport()->rect();////
	viewport_rect = m_pGraphWnd->centralWidget()->geometry();//dw->screenGeometry( m_pGraphWnd );

    QJsonObject jobj;
    if (args.type() == QVariant::Map)
        jobj = QJsonObject::fromVariantMap(args.toMap());
    else if (args.canConvert<QJsonObject>())
        jobj = args.toJsonObject();

    if (wnd_flags==Qt::Dialog || wnd_flags==Qt::Sheet )
    {
        QRectF argRect(0,0,0,0);
        QPoint pos = viewport_rect.center();
#ifdef WIN32
		pos = wndrect.center();
#endif;
		if (!jobj.isEmpty()){
            QStringList  lst=jobj["rect"].toString().split(",");
            if(lst.size()==2){ //ignore x ,y ,center the dialog
                argRect = QRect(0,0, lst[0].toFloat(), lst[1].toFloat());
            }
            else if(lst.size()==4) {
				argRect = QRect(lst[0].toFloat(), lst[1].toFloat(), lst[2].toFloat(), lst[3].toFloat());                
                pos = argRect.center().toPoint();
            }
            if(argRect.width()>10  && argRect.height()>10){
                float fw=(float)argRect.width()/grect.width();
                float fh=(float)argRect.height()/grect.height();
                float ff=fw>fh?fh:fw;
                if(ff!=1.0){
                    scale(ff,ff);
                }
                grect=argRect.toRect();
            }
        }
        if(grect.width()>wndrect.width()) grect.setWidth(wndrect.width());
        if(grect.height()>wndrect.height()) grect.setHeight(wndrect.height()-50);
        int x=pos.x()-grect.width()/2;
        int y=pos.y()-grect.height()/2;
		setGeometry(QRect(x,y, grect.width(),grect.height()));
#ifndef WIN32
        if (tmp_wnd_flags & Qt::MSWindowsFixedSizeDialogHint  ){
            setFixedSize(grect.size());
        }
#endif

    }
    else
    {
        if ( m_pGraphWnd->m_pWorkspace->verticalScrollBar() )
            m_pGraphWnd->m_pWorkspace->verticalScrollBar()->setSliderPosition( 0 );
        if ( m_pGraphWnd->m_pWorkspace->horizontalScrollBar() )
            m_pGraphWnd->m_pWorkspace->horizontalScrollBar()->setSliderPosition( 0 );
        
        int show_mode = m_pScene->FitViewMode();//m_pScene->GraphShowMode();//是否自适应
        if(!jobj["fitInViewMode"].isUndefined())
            setProperty("_fitInViewMode_",jobj["fitInViewMode"].toString());

        m_pGraphWnd->m_nLastShowMode = show_mode; 
        
        QRect workspace_rect = grect ;
#if 1
        if ( show_mode==2) /////相对位置分辨率自适应/////
        {
            int d_width=0,d_height=0;
            QVariant design_resolution=m_pGraphWnd->property("resolution");
            if(design_resolution.isValid()){
                QString tmp=design_resolution.toString();
                d_width=tmp.section(",",0,0).toInt();
                d_height=tmp.section(",",1).toInt();
            }
            else{
                d_width=grect.width();
                d_height=grect.height();
            }

            if(d_width>1000 && d_width<9000 && d_height>600 && d_height<6000){
                float fw=(float)d_width/viewport_rect.width();
                float fh=(float)d_height/viewport_rect.height();
                float ff=fw>fh?fw:fh;
                if(ff!=1.0){
                    scale(1/ff,1/ff);
                    QMatrix matrix;
                    matrix.scale(1/ff, 1/ff);
                    workspace_rect=matrix.mapRect(grect);
                    workspace_rect.setWidth(viewport_rect.width());
                    //setGeometry(workspace_rect);
                    //resize(workspace_rect.width(),workspace_rect.height());
                }
            }

        }
        else if(show_mode==1)////填充画布,充满屏幕全图显示////
        {
            ZoomAll();
        }
#endif
                       
        int wnd_width   = wndrect.width();//viewport_rect.width();////屏幕宽度
        int wnd_height  =viewport_rect.height();//   wndrect.height();/////可视区高度
        if ( workspace_rect.height() > wnd_height )
        {
            //workspace_rect.setHeight( wnd_height );
        }
        if ( workspace_rect.width() > wnd_width)
        {
            //workspace_rect.setWidth( wnd_width );
        }

        QMdiSubWindow* parentSW=qobject_cast<QMdiSubWindow *>(parent());
        if(parentSW)
        {
            if(tmp_wnd_flags & Qt::WindowStaysOnTopHint   )
            {
                parentSW->setWindowFlags(parentSW->windowFlags()| Qt::WindowStaysOnTopHint);
            }
            if ( show_mode!=1)
            {
                parentSW->setGeometry( workspace_rect );
                parentSW->show();
            }
		}
        else if (parent() )//&& (parent()!=m_pGraphWnd))
		{
            ((QWidget *)parent())->setGeometry(workspace_rect);
            ((QWidget *)parent())->show();
        }
		m_pGraphWnd->UpdateRecentFiles(tmp_filename);
    }


    QColor color=m_pScene->backgroundBrush().color();
    if(color.isValid())
        viewport()->setStyleSheet("background-color:"+color.name());
    //qreal opacity = m_pScene->GetWindowOpacity();
    //setWindowOpacity(opacity);
    show();

    m_TimerCount=0;
	emit OnLoad();
    UnqFunc()->TmDebug("--over view::fileopen--");
    return 0;
}

QObject * CGExplorerView::GetItemInfo(QPoint pos, QString& msg)
{
    QObject* pobj=CGraphView::GetItemInfo( pos,  msg);
    if(pobj && !pobj->inherits("CBaseData"))
        return NULL;
	QString tagInfo;
	if (pobj)
	{
		tagInfo = CAnimation::GetTagInfo(((CBaseData*)pobj)->Item());
	}		
    QJsonObject jsonObj=UnqFunc()->Str2Json(msg);
    jsonObj["taginfo"] =tagInfo;
    jsonObj["pic"] =m_pScene->GetFileName();
    msg=UnqFunc()->Json2Str(jsonObj);
    return pobj;
 }
void CGExplorerView::mousePressEvent(QMouseEvent* e)
{
    QGraphicsView::mousePressEvent(e);
    m_StartPos = e->pos();
    m_GlobalStartPos=e->globalPos()-  pos();
	if (e->button() == Qt::LeftButton )
	{
		QString msg = "";
		QObject* curobj = GetItemInfo(e->pos(), msg);
        //
        QList<QGraphicsItem*> lst = this->items(e->pos());
        QObjectList olst;
        for (int li = 0; li < lst.size(); li++)
        {
            CBaseData* pdata = g_dataPtr(lst.at(li));
            if(pdata) olst.append(pdata);
        }
        //
        emit LeftClicked(curobj, msg,olst);
		if ((CBaseData*)curobj && ((CBaseData*)curobj)->GetName().startsWith("token^"))//only token can be moved 
		{
			m_LastMovePos = ((CBaseData*)curobj)->Pos();
			emit TokenMoveBegin(curobj);
			if (m_tokenLine == NULL){
				m_tokenLine = new CPolylineItem();
				m_tokenLine->setPos(m_StartPos);
				m_pScene->addItem(m_tokenLine);
				m_tokenLine->setFlag(QGraphicsItem::ItemIsMovable,false);
				m_tokenLine->setFlag(QGraphicsItem::ItemIsSelectable, false);
				g_dataPtr(m_tokenLine)->SetLineColor(Qt::green);
				g_dataPtr(m_tokenLine)->SetLineStyle(Qt::DashDotDotLine);
			}
			m_tokenLine->show();
		}
        else if (((CGExplorerWnd*)m_pGraphWnd)->GetEnableBoxZoom()&& m_pScene->GetEnableScale())
		{
			if (m_rubberBand == NULL)
				m_rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
			m_rubberBand->setGeometry(QRect(m_StartPos, QSize()));
			m_rubberBand->show();
		}
	}
    else if (e->button() == Qt::MiddleButton)
	{
		////////原图1:1不缩放/////////////////
		parentWidget()->showMaximized();
		ResetMatrix();
	}
	//m_pScene->setSelectionArea(QPainterPath());
    QVariantMap info;
    info["type"]="MousePress";
    info["button"]=e->button();
    info["x"]=e->pos().x();
    info["y"]=e->pos().y();
    //emit MouseEvent(pdata,info);
}

void CGExplorerView::mouseDoubleClickEvent(QMouseEvent* e)
{
    QGraphicsView::mouseDoubleClickEvent(e);
    Qt::MouseButtons keystate=e->button();
    QPoint vp=e->pos();
    QString msg="";
    QObject* curobj=GetItemInfo( vp,msg);
    emit DoubleClicked(curobj,msg);
}

int  VMINSIZE=10;

void CGExplorerView::mouseReleaseEvent(QMouseEvent * e)
{
    if (m_tokenLine)
        m_tokenLine->hide();

	if (m_hasAreaSelect)
	{
		m_AreaSelectRect = m_pScene->selectionArea().boundingRect();
	}
	else
		m_AreaSelectRect = QRect(0, 0, 0, 0);
	int distance = (e->pos() - m_StartPos).manhattanLength();	
    if (e->button()==Qt::LeftButton)
    {
        if (m_pScene->GetEnableScale() && ((CGExplorerWnd*)m_pGraphWnd)->GetEnableBoxZoom() )
		{
			if (m_rubberBand && m_rubberBand->isVisible() && !m_rubberBand->size().isEmpty())
			{
				m_rubberBand->hide();
				QPoint rubberEnd = e->pos();
                QRectF zoomRectInScene = QRectF(mapToScene(m_StartPos), mapToScene(rubberEnd));
                if(m_pScene->sceneRect().width()>0){
                    qreal k=1920/m_pScene->sceneRect().width() ;
                    qreal curScale=transform().m11();
                    if(curScale>k/5 && curScale<k*50)  ////缩放比例范围/////
                    {
                        if (zoomRectInScene.width()>VMINSIZE && zoomRectInScene.height()>VMINSIZE) //zoomin
                            FitInView(zoomRectInScene, Qt::KeepAspectRatio);
                        else if (zoomRectInScene.width()< (0-VMINSIZE) && zoomRectInScene.height()<(0-VMINSIZE))//zoomout
                        {
                            QRectF outRct = QRectF(m_StartPos, rubberEnd).normalized();
                            parentWidget()->showMaximized();
                            {
                                QSize psize = parentWidget()->size();
                                if (psize.width()>0 && psize.height()>0)
                                {
                                    float fw = outRct.width() / psize.width();
                                    float fh = outRct.height() / psize.height();
                                    float ff = fw>fh ? fw : fh;
                                    if(curScale*ff>k/5)
                                        Scale(ff, ff);
                                }
                            }
                        }
                    }
                }
				QGraphicsView::mouseReleaseEvent(e);
				return;
			}
		}

        QString msg;
        CBaseData* pdata = (CBaseData*)GetItemInfo(e->pos(), msg);
        if (pdata == NULL && m_tokenLine)
        {
            QPoint e(m_LastMovePos.rx(), m_LastMovePos.ry());
            pdata = (CBaseData*)GetItemInfo(e, msg);
        }
        if(pdata){
            if (pdata->GetName().startsWith("token^"))//only token can be moved
            {
                if (m_pScene->GetLayoutRect().contains(e->pos(),true))
                    emit TokenMoved(pdata);
                else
                    pdata->Item()->setPos(m_LastMovePos);
            }
            else
            {
                ProcessAhref(pdata);

            }
        }
    }
	else if(e->button()==Qt::RightButton){ ////该在右键弹起时调用右键菜单,以便区分右键拖动的功能////
        if(!m_lastOpIsMove){
            ShowContextMenu(e->pos(),e->globalPos());
            m_lastOpIsMove=false;
        }
        m_lastOpIsMove=false;
    }
	CGraphView::mouseReleaseEvent(e);

	if (m_rubberBand)
		m_rubberBand->hide();
}


void CGExplorerView::mouseMoveEvent(QMouseEvent* e)
{
	QGraphicsView::mouseMoveEvent(e);
	
    if (m_BlockSignal)
    {
        return;
    }
    QObject* curobj=NULL;
    if(e->buttons() & Qt::RightButton){
        m_lastOpIsMove=true;
        QScrollBar *hBar = horizontalScrollBar();
        QScrollBar *vBar = verticalScrollBar();
        QPoint delta = e->pos() - m_StartPos;
        hBar->setValue(hBar->value() - delta.x());
        vBar->setValue(vBar->value() - delta.y());
        m_StartPos = e->pos();
        this->cursor().setShape(Qt::ClosedHandCursor);
    }
    //
	if ((e->buttons() & Qt::LeftButton))
    {
        int distance = (e->pos() - m_StartPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        {
			if (QApplication::keyboardModifiers() == Qt::ControlModifier){//drag the taginfo
				QString msg = "";
				QObject* curobj = GetItemInfo(m_StartPos, msg);

				if ((CBaseData*)curobj && !((CBaseData*)curobj)->GetName().startsWith("token^"))//only token can be moved 
				{
					if (!((CBaseData*)curobj)->GetUserData().isEmpty())
					{
						QMimeData *mimeData = new QMimeData;
						mimeData->setText(msg);
						QDrag *drag = new QDrag(this);


						drag->setMimeData(mimeData);
						int gg = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
						if (gg == Qt::CopyAction)
						{
							emit DragEvent(msg);
						}
					}
				}
				return;
			}

			QString msg = "";
			QObject* curobj = GetItemInfo(e->pos(), msg);
			CBaseData* pIData = (CBaseData*)curobj;
			if (pIData && pIData->GetName().startsWith("token^"))//limit the token move range
			{
				//if (!m_rubberBand || !m_rubberBand->isVisible())//when drag rubber band , do not show m_tokenLine
				{
					QString itemXY = pIData->Property("itemPos",false).toString();
					qreal moveRangeR = pIData->Property("moveRangeR", false).toFloat();
					QStringList xyLst = itemXY.split(",");
					if (xyLst.size() == 2)
					{
						qreal itemX = xyLst[0].toFloat();
						qreal itemY = xyLst[1].toFloat();
						QRectF range = QRectF(itemX - moveRangeR, itemY - moveRangeR, moveRangeR * 2, moveRangeR * 2);
						QPointF cPos = pIData->Pos();
						if (!range.contains(cPos))
							pIData->SetPos(m_LastMovePos);
						else
							m_LastMovePos = cPos;//m_LastMovePos = e->pos();
						if (m_tokenLine) m_tokenLine->setPos(QPointF(itemX, itemY));
						QPolygonF ply;
						ply << QPointF(0, 0) << pIData->Pos() + QPointF(pIData->Item()->boundingRect().width() / 2, pIData->Item()->boundingRect().height() / 2) - QPointF(itemX, itemY);
						if (m_tokenLine) m_tokenLine->setPolygon(ply);
						//m_tokenLine->SetArrowInfo(Hmi::ARROW_HOLLOW_ARROW, Hmi::ARROW_SIZE_10_12, -1, -1);
						//m_tokenLine->show();
						return;
					}
				}
			}
			if (((CGExplorerWnd*)m_pGraphWnd)->GetEnableDragMove())
			{
				if (!pIData || !pIData->GetName().startsWith("token^"))//only token can be moved
				{
					QScrollBar *hBar = horizontalScrollBar();
					QScrollBar *vBar = verticalScrollBar();
					QPoint delta = e->pos() - m_StartPos;
					hBar->setValue(hBar->value() - delta.x());
					vBar->setValue(vBar->value() - delta.y());
					m_StartPos = e->pos();
					this->cursor().setShape(Qt::ClosedHandCursor);
				}
			}
			if (((CGExplorerWnd*)m_pGraphWnd)->GetEnableBoxZoom() )
			{
				if (m_rubberBand)
				{
					m_rubberBand->setGeometry(QRect(m_StartPos, e->pos()).normalized());
					//m_rubberBand->show();
					return;
				}
			}
            //
			if (dragMode() != NoDrag )
            {
                qreal angle=QLineF(m_StartPos,e->pos()).angle();
                QString msg = "";
                QJsonObject json;
                curobj=GetItemInfo(m_StartPos, msg);
                json=UnqFunc()->Str2Json(msg);
                if(!msg.isEmpty() && json["taginfo"].toString()!="")
                {
                    if(angle>315 ||angle <90)
                    {
                        json["align"] = "right";
                    }
                    else if(angle>90 && angle <225)
                    {
                        json["align"] = "left";
                    }
                    else if(angle>225 && angle <315)
                    {
                        json["align"] = "bottom";
                    }
                    QRect vrect=mapFromScene(m_AreaSelectRect).boundingRect();
                    json["select_rect"] = QString("%1,%2,%3,%4").arg(vrect.x()).arg(vrect.y()).arg(vrect.width()).arg(vrect.height());
                    msg=UnqFunc()->Json2Str(json);
                    QMimeData *mimeData = new QMimeData;

                    mimeData->setText(msg);
                    QDrag *drag = new QDrag(this);
                    drag->setMimeData(mimeData);

                    QPixmap pix(vrect.width(), vrect.height());
                    QPainter painter(&pix);
                    painter.setOpacity(0.5);
                    render(&painter,QRectF(0, 0,vrect.width(), vrect.height() ),vrect);
                    drag->setPixmap(pix);

                    int gg=drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
                    if ( gg== Qt::CopyAction)
                    {
                        emit DragEvent(msg);
                    }
                }
            }
        }

        //Qt::WindowFlags flags=windowFlags( );
        //if(flags & (Qt::Dialog|Qt::FramelessWindowHint))//&& parent()
		if (m_pScene->GetMovable())
        {
            QMdiSubWindow* parentSW=qobject_cast<QMdiSubWindow *>(parent());
            if(parentSW)
            {
                parentSW->move(e->globalPos() - m_GlobalStartPos);
                parentSW->setWindowOpacity(m_pScene->GetWindowOpacity());
            }
            else{
                move(e->globalPos() - m_GlobalStartPos);
            }
        }
    }

    Qt::MouseButtons keystate=e->button();
    QPoint vp=e->pos();

    setCursor(Qt::ArrowCursor);
    bool show_pointhand=false;
    CBaseData* pdata=NULL;
    QList<QGraphicsItem*> ListItems = items(vp);

    if( m_pHotSrcItem && m_SrcOpacity>0) m_pHotSrcItem->setOpacity(m_SrcOpacity);
	//token first
	bool hasToken = false;
	foreach(QGraphicsItem *item, ListItems)
	{
		pdata = g_dataPtr(item);
		if (pdata && pdata->GetName().startsWith("token^"))
		{
			setCursor(Qt::PointingHandCursor);
			m_pHotSrcItem = item;
			m_SrcOpacity = item->opacity();
			m_pHotSrcItem->setOpacity(m_SrcOpacity*0.7);
			hasToken = true;
			break;
		}
	}
	//then item has ahref or userdata
	if (!hasToken)
	{
		foreach (QGraphicsItem *item, ListItems)
		{
			pdata=g_dataPtr(item);
			if (pdata && (!pdata->GetUserData().isEmpty() || pdata->Property("ahref",false).isValid()))
			{
				if (pdata->Type() == Hmi::QtChart || pdata->inherits("CWidgetData"))
					continue;
				setCursor(Qt::PointingHandCursor);
				m_pHotSrcItem=item;
				m_SrcOpacity=item->opacity();
				m_pHotSrcItem->setOpacity(m_SrcOpacity*0.7);

				break;
			}
		}
	}

    QVariantMap info;
    info["type"]="MouseMove";
    info["button"]=e->button();
    info["x"]=vp.x();
    info["y"]=vp.y();

    emit MouseEvent(pdata,info);

}

void CGExplorerView::contextMenuEvent( QContextMenuEvent *event)
{
    QGraphicsView::contextMenuEvent(event);
}

QRect CGExplorerView::GetViewRect()
{
    int x=0,y=0,w=1,h=1;
    QRect rc(x,y,w,h);
    return rc ;
}
//////处理超链接////////
void CGExplorerView::ProcessAhref( QObject* curobj)
{
    if(!curobj) return;
    QString ahrefVal = ((CBaseData*)curobj)->Property("ahref").toString();
    if (ahrefVal.isEmpty())
    {
        return;
    }
    if (ahrefVal.startsWith("Graph:"))
    {
        QString strPara = ahrefVal.mid(6);
        QJsonObject objPara = UnqFunc()->Str2Json(strPara);
        QString fileName = objPara["fileName"].toString();
        QString openType = objPara["openType"].toString();
        QString args = objPara["args"].toString();
        QString showPlane = objPara["showPlane"].toString();
        QJsonObject viewPara;
        viewPara["args"] = args;
        QString wnd_tag = "";
        CGExplorerView* view = NULL;
        if (openType == "view")
        {
            wnd_tag = this->GetWndAlais();
            view = (CGExplorerView *)m_pGraphWnd->FindMdiChild(fileName);
            if(view){
                m_pGraphWnd->m_pWorkspace->setActiveSubWindow((QMdiSubWindow *)view->parent());
            }
            else{
                UnqFunc()->GetGraphPathNameByGraphName(fileName,fileName);
                if(QFile::exists(fileName)){
                    if (this->FileOpen(fileName, "", 0, args) >= 0)
                        view = this;
                }
            }
        }
        else if (openType == "dialog")
        {
            viewPara["wndflag"] = "dialog";
            view = (CGExplorerView*)m_pGraphWnd->Open(fileName, wnd_tag, viewPara);
        }
        else
        {
            wnd_tag=openType;
            view = (CGExplorerView*)m_pGraphWnd->Open(fileName, wnd_tag, viewPara);
        }
        if (view && !showPlane.isEmpty())
            view->SetShowPlaneIndexs(showPlane );
    }
    else if (ahrefVal.startsWith("ChgPlane:"))
    {
        QString plane = ahrefVal.section(":",1);
        if(!plane.isEmpty())
            SetShowPlaneIndexs(plane );
    }
    else if (ahrefVal.startsWith("Previous:"))
    {
        m_pGraphWnd->Navigate(-1);
    }
    else if (ahrefVal.startsWith("Exe:"))
    {
        QString exePath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_BIN) + ahrefVal.mid(4);
        UnqFunc()->SysExec(exePath);
    }
    else if (ahrefVal.startsWith("Script:"))
    {
        //eval script
        QString scriptStr = ahrefVal.mid(7);
        CScriptEngine* pScriptEngine = m_pScene->GetScriptEngine();
        if (!scriptStr.isEmpty())
        {
            QScriptSyntaxCheckResult ret = QScriptEngine::checkSyntax(scriptStr);
            if (ret.state() != QScriptSyntaxCheckResult::Valid)
                QMessageBox::warning(0, tr("Error"), tr("Script error line_number = %1, Error_message = %2 !").arg(ret.errorLineNumber()).arg(ret.errorMessage()));

            pScriptEngine->Evaluate(scriptStr);
        }
    }
}

int CGExplorerView::ProcessChangeData(CHG_DATA_MAP& chg_data_map )
{
    m_pScene->GetAnimateDriver()->Render(chg_data_map);

    return 0;
}

void CGExplorerView::OnNaviViewPosChg(float x,float y)
{


}

void CGExplorerView::wheelEvent(QWheelEvent *event)
{
    if (m_pScene->GetEnableScale())
			CGraphView::wheelEvent(event);
	else
        QGraphicsView::wheelEvent(event);
}

void CGExplorerView::ShowTip(QPoint pos)
{
    QString msg;
    setToolTip("");
    QObject* curobj=GetItemInfo( pos,msg);

    //setCursor(Qt::ArrowCursor);
    emit TipEvent(curobj,msg);
}

QString CGExplorerView::GetWndTitle()
{

    return "";
}
void CGExplorerView::SetAreaSelectFlag(bool has_area_select)
{
	m_hasAreaSelect = has_area_select;
	if (m_hasAreaSelect)
		setDragMode(QGraphicsView::RubberBandDrag);
	else
		setDragMode(QGraphicsView::NoDrag);
}
QString CGExplorerView::GetAreaSelectRect()
{
	QJsonObject jsonObj;
	jsonObj["x"] = m_AreaSelectRect.x();
	jsonObj["y"] = m_AreaSelectRect.y();
	jsonObj["width"] = m_AreaSelectRect.width();
	jsonObj["height"] = m_AreaSelectRect.height();

	return QJsonDocument(jsonObj).toJson().data();
}

void CGExplorerView::resizeEvent ( QResizeEvent * event )
{   
    bool enableScale=Scene()->GetEnableScale();
    int fit_mode = Scene()->FitViewMode();
    if(fit_mode>0 && !enableScale )
    {
        gInfo("----resize-- fit---%s--",CurrentFile().toLocal8Bit().data());
        QRectF rc =   Scene()->sceneRect();
        FitInView(rc, Qt::IgnoreAspectRatio);//Qt::AspectRatioMode:The effect of each value is the same
    }
    QGraphicsView::resizeEvent(event);
	//QSize size = geometry().size();
    if(m_lastSize.width()!=geometry().width() || m_lastSize.height()!=geometry().height()){
        m_lastSize=geometry().size();
        emit Resized(geometry().width(),geometry().height());
    }
}
