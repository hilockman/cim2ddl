#include "GraphView.h"
#include "GraphScene.h"
#include "GFunc.h"
#include "CGrid.h"
#include "BaseData.h"
#include "CQScriptWrap.h"
#include "GraphItem.h"
#include "GroupItem.h"
#include "ItemFactory.h"

int MAX_ZOOM_FACTOR=50;

CGraphView::CGraphView(CGraphScene * scene, QWidget * parent  )
    :QGraphicsView(scene, parent)
{
    m_CasheMode=false;
    m_OldMatrix=matrix();
    m_FitMode=-1;
    m_FitRect=QRect(0,0,0,0);
	m_BackPixmapName = "";
	m_BackPixmapShowWay = -1;

    setCacheMode(QGraphicsView::CacheBackground);
    setRenderHint(QPainter::Antialiasing);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    //connect(horizontalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(EmitMatrixChg(int)));
    //connect(verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(EmitMatrixChg(int)));
    installEventFilter(this);
}

CGraphView::~CGraphView()
{
    m_Vars.clear();
}


int CGraphView::VerticalScroll()
{
    QPoint p_v1=mapFromScene(QPointF(100,100));
    QPointF p_v2 = matrix().map(QPointF(100,100));
    int dy=p_v2.ry()-p_v1.y();
    return dy;
}

int CGraphView::HorizontalScroll()
{
    QPoint p_v1=mapFromScene(QPointF(100,100));
    QPointF p_v2 = matrix().map(QPointF(100,100));
    int dx=p_v2.rx()-p_v1.x();
    return dx;
}


void CGraphView::paintEvent ( QPaintEvent * event )
{
    QGraphicsView::paintEvent(event);
}


CGraphScene * CGraphView::Scene()
{
    if ( scene() )
        return (CGraphScene *)scene();
    return NULL;
}

void CGraphView::EmitMatrixChg(int value)
{
    try
    {
        QMatrix moveMatrix;
        moveMatrix.translate(-HorizontalScroll(), -VerticalScroll());
        QMatrix painterMatrix = matrix()  * moveMatrix;
        emit MatrixChg(painterMatrix.m11(), painterMatrix.dx() , painterMatrix.dy() );
        /*
          if (m_OldMatrix != painterMatrix)
          {
              m_OldMatrix = painterMatrix;
              emit MatrixChg(painterMatrix.m11(), painterMatrix.dx() / kk, painterMatrix.dy() / kk);
          }*/
    }
    catch (...)
    {
        return;
    }
}

void CGraphView::FitInView(const QRectF &rect, Qt::AspectRatioMode aspectRadioMode  )
{
    QString mode= property("_fitInViewMode_").toString();
    if(mode=="IgnoreAspectRatio") aspectRadioMode=Qt::IgnoreAspectRatio;
    else if(mode=="KeepAspectRatio") aspectRadioMode=Qt::KeepAspectRatio;
    else if(mode=="KeepAspectRatioByExpanding") aspectRadioMode=Qt::KeepAspectRatioByExpanding;


    fitInView(rect, aspectRadioMode);
    EmitMatrixChg();
    return;
 /*   m_FitMode=aspectRatioMode;
    if(rect.isValid())
    {
        QMap<QString,QVariant> rcmap=rect.toMap();
        m_FitRect=QRect(rcmap["x"].toInt(),rcmap["y"].toInt(),rcmap["width"].toInt(),rcmap["height"].toInt());
    }*/
}

void CGraphView::resizeEvent ( QResizeEvent * event )
{  
    QGraphicsView::resizeEvent(event);
    //emit Resized(geometry().width(),geometry().height());
}

void CGraphView::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsView::drawBackground( painter, rect);
	QRectF repaintRect = rect.intersected(sceneRect());
	if (repaintRect.width() == 0 && repaintRect.height() == 0)
		return;
	if (!m_BackPixmapName.isEmpty() && m_BackPixmapName != "0")
	{
		QString pathStr;
		UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, m_BackPixmapName, pathStr);
		if (m_BackPixmapShowWay == 0)//tile
			painter->drawTiledPixmap(repaintRect, QPixmap(pathStr));
		else if (m_BackPixmapShowWay == 1)//zoom
			painter->drawPixmap(repaintRect.toRect(), QPixmap(pathStr));
		else //original
			painter->drawPixmap(repaintRect.topLeft(), QPixmap(pathStr));
	}
}

void CGraphView::wheelEvent(QWheelEvent *event)
{
    if (QApplication::keyboardModifiers() & Qt::ControlModifier || QApplication::mouseButtons() & Qt::MidButton)
    {

        double scaleFactor=pow((double)2, event->delta() / 240.0);
        double factor = matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
        if (factor < 0.07 || factor > MAX_ZOOM_FACTOR)
            return;

        Scale(scaleFactor, scaleFactor);
    }
    else
        QGraphicsView::wheelEvent(event);
}


void CGraphView::keyPressEvent ( QKeyEvent * event )
{
    double factor = matrix().mapRect(QRectF(0, 0, 1, 1)).width();
    QPointF pos= sceneRect().center();

    if(event->modifiers() == Qt::ShiftModifier)
        switch(event->key())
        {
        case Qt::Key_Z:
        {
            if ( factor > MAX_ZOOM_FACTOR)
                return;
            Scale(1.1,1.1);
            centerOn ( pos );
        }
            break;
        case Qt::Key_X:
        {
            if (factor < 0.07 )
                return;
            Scale(0.9,0.9);
            centerOn ( pos );
        }
            break;
        case Qt::Key_T:
        {
            scrollContentsBy(10,10);
            break;
        }

        /*case Qt::Key_R:
            rotate(5);
            break;
        case Qt::Key_H:
            shear(-0.1,0);
            break;
        case Qt::Key_G:
            shear(0.1,0);
            break;
        case Qt::Key_V:
            shear(0,-0.1);
            break;
        case Qt::Key_B:
            shear(0,0.1);
            break;*/
        case Qt::Key_Q:
            resetMatrix();
            break;
        default:
            break;
        }


    QGraphicsView::keyPressEvent(event);
}

QString CGraphView::GetShowPlane()
{
    QStringList show_list;
    QBitArray planeArray = Scene()->GetShowPlanesMask();
    for(int i=0;i<planeArray.size();i++)
        show_list << QString("%1").arg(planeArray[i]);
    return show_list.join(",");
}

void CGraphView::SetShowPlane(const QString& show_planes, bool refresh)
{
    Scene()->SetShowPlanes(show_planes);
    if (refresh)
    {
        viewport()->update();
    }
}

void CGraphView::SetShowPlaneIndexs(QString  show_indexs, bool refresh)
{
    QStringList tmplist=show_indexs.split(",");
    QList<int> showlist;
    for(int i=0;i<tmplist.size();i++){
        showlist.push_back(tmplist[i].toInt());
    }
    QBitArray planeArray = Scene()->GetShowPlanesMask();
    for(int i=0;i<planeArray.size();i++){
        planeArray[i]=showlist.indexOf( i )>=0 ? true:false;
    }
    Scene()->SetShowPlanes(planeArray);
}

QString CGraphView::CurrentFile( bool is_abs_path )
{
    QString graphpathname=Scene()->GetFileName();
    QString graph_name;
    if (is_abs_path)
        return graphpathname;
    else
        UnqFunc()->GetGraphNameByGraphPathName(graphpathname,graph_name);

    return graph_name;
}
void CGraphView::mouseDoubleClickEvent(QMouseEvent *e)
{
    QGraphicsView::mouseDoubleClickEvent(e);
    Qt::MouseButtons keystate=e->button();
    QPoint vp=e->pos();
    QPointF pos=mapToScene(vp);
    QString msg="";
    QObject* curobj=GetItemInfo( pos.toPoint(),msg);
    emit DoubleClicked(curobj, msg);
}
void CGraphView::mouseReleaseEvent(QMouseEvent * e)
{
	QGraphicsView::mouseReleaseEvent(e);

	emit MouseRelease();
}
void CGraphView::ShowTip(QPoint pos)
{
    QString msg="";
    QObject* curobj=GetItemInfo( pos,msg);
    setToolTip(msg);
}

void CGraphView::Shear(float sx, float sy, float sz)
{
    setTransform(transform()
                 .translate(sceneRect().width() / 2, sceneRect().height() / 2)
                 .rotate(sx, Qt::XAxis)
                 .rotate(sy, Qt::YAxis)
                 .rotate(sz, Qt::ZAxis)
                 //.scale(1 + 1.5 * step, 1 + 1.5 * step)
                 .translate(-sceneRect().width() / 2, -sceneRect().height() / 2)
                 );
    //shear(sh,sv);
}

QObject *CGraphView::GetItemInfo(QPoint pos, QString& msg)
{
    QString retStr;
    QString symbolName,tagInfo;
	int iconType = -1;
    QGraphicsItem * item = NULL;// = itemAt(pos);
    QList<QGraphicsItem*> lst = this->items(pos);
    bool valid=false;
    if(lst.size()==0)
        return NULL;

    for (int li = 0; li < lst.size(); li++)
    {
        item = lst.at(li);
        CBaseData* pdata = g_dataPtr(item);
		if (NULL == pdata)
			continue;
        if ( pdata->GetName().startsWith("token") || pdata->GetUserData().isEmpty()==false ||  pdata->Property("ahref",false).isValid())
        {
            valid=true;
            break;
        }
    }
	if (!valid)
	{
		foreach(QGraphicsItem *pItem, lst)
		{
			if (pItem->type() == Hmi::Icon)
			{
				item = pItem;
				valid = true;
				break;
			}
		}
	}
	if (!valid)
	{
		foreach(QGraphicsItem *pItem, lst)
		{
			if (pItem->parentItem() == 0)
			{
				item = pItem;
				break;
			}
		}
	}

    CBaseData* pdata=g_dataPtr(item);
    if (NULL==pdata)
    {
        return NULL;
    }
    if(item->type()==Hmi::Icon)
    {
        symbolName = ((CIconData*)pdata)->GetTemplateName();
        iconType = ((CIconData*)pdata)->GetIconType();
    }
    //tagInfo= CAnimation::GetTagInfo(item);

    QJsonObject jsonObj;
	jsonObj["itemtype"] = pdata->Type();
    jsonObj["itemname"] = pdata->GetName();
    jsonObj["typename"] = pdata->TypeName();
    jsonObj["iconType"] = iconType;
    jsonObj["symbol"] =symbolName;
    jsonObj["pic"] =Scene()->GetFileName();
    msg=UnqFunc()->Json2Str(jsonObj);
    return pdata;
}

void CGraphView::SetGeometry(int x, int y, int w, int h)
{
    if(x<0 && y<0)
        resize(w,h);
    else
        setGeometry(x, y, w, h);
    if (parent() && (parent()->inherits("QMdiSubWindow") || parent()->inherits("QDockWidget")) )
    {
        if(x<0 && y<0)
            parentWidget()->resize(w,h);
        else
            parentWidget()->setGeometry(x, y, w, h);
    }
}

void CGraphView::PopupContextMenu(const QVariant& menuinfo,QMenu&  contextMenu)
{
    contextMenu.setToolTipsVisible(true);
    QList<QVariant> tmplist = menuinfo.toList();
    if (!tmplist.isEmpty())
    {
        for (int i = 0; i < tmplist.size(); i++)
        {
            QJsonObject obj;

            QVariant qPara = tmplist[i];
            if (qPara.type() == QVariant::Map)
            {
                obj = QJsonObject::fromVariantMap(qPara.toMap());
            }
            else
            {
                obj = UnqFunc()->Str2Json(qPara.toString());
            }
            if (obj.isEmpty())
            {
                contextMenu.addSeparator();
                continue;
            }

            QString menu_txt = obj["text"].toString();
			QVariant menu_data = obj["data"].toVariant();
            QString iconFile = obj["icon"].toString();
            bool enable = obj["enable"].toInt();
            QString tip = obj["tip"].toString();
            QString pathName;
            UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, iconFile, pathName);// m_PathTypeNameMap[PATH_TYPE_ICONSET] = GetSysHome()+spt+"res"+spt+"ico"+spt;

            if (obj["children"].isNull())
            {
                QAction *act = contextMenu.addAction(menu_txt, this, SLOT(OnContextMenu()));
                act->setData(menu_data);
                act->setEnabled(enable);
                act->setIcon(QIcon(pathName));
                act->setToolTip(tip);
            }
            else
            {
                QMenu* menu = new QMenu(menu_txt,this);
                menu->setIcon(QIcon(pathName));
                menu->setToolTip(tip);

                QList<QVariant> childMenus = obj["children"].toVariant().toList();
                for (int j = 0; j < childMenus.size(); j++)
                {
                    QJsonObject childObj;
                    QVariant childPara = childMenus[j];
                    if (childPara.type() == QVariant::Map)
                    {
                        childObj = QJsonObject::fromVariantMap(childPara.toMap());
                    }
                    else
                    {
                        childObj = UnqFunc()->Str2Json(childPara.toString());
                    }
                    if (childObj.isEmpty())
                    {
                        menu->addSeparator();
                        continue;
                    }
                    QString menu_txt = childObj["text"].toString();
					QVariant menu_data = childObj["data"].toVariant();
                    QString iconFile = childObj["icon"].toString();
                    bool enable = childObj["enable"].toInt();
                    QString tip = childObj["tip"].toString();
                    QAction *childAct = menu->addAction(menu_txt, this, SLOT(OnContextMenu()));
                    childAct->setData(menu_data);
                    childAct->setEnabled(enable);
                    QString pathName;
                    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, iconFile, pathName);// m_PathTypeNameMap[PATH_TYPE_ICONSET] = GetSysHome()+spt+"res"+spt+"ico"+spt;
                    childAct->setIcon(QIcon(pathName));
                    childAct->setToolTip(tip);
                }
                contextMenu.addMenu(menu);
            }
        }
    }

}

void CGraphView::contextMenuEvent( QContextMenuEvent *event)
{
    QMenu contextMenu(this);
    QPoint pos = event->pos() ;
    QString msg = "";
    QObject* curobj =GetItemInfo(pos,  msg);

    if (curobj && (curobj->inherits("CWidgetData") || curobj->inherits("CGChartData")))
    {
        return QGraphicsView::contextMenuEvent(event);
    }

    QVariantList args;
    args.append( msg);
    QVariant ret = Scene()->GetScriptEngine()->Call("getContextMenu", args);
    if (ret.toString().indexOf("error:") == -1)
    {
        PopupContextMenu( ret,contextMenu);
    }
	if (!contextMenu.isEmpty())
        contextMenu.exec(event->globalPos());
    QGraphicsView::contextMenuEvent(event);
}

void CGraphView::ShowContextMenu(QPoint pos,QPoint global_pos){
    QMenu contextMenu(this);
    QString msg = "";
    QObject* curobj =GetItemInfo(pos,  msg);

    if (curobj && (curobj->inherits("CWidgetData") || curobj->inherits("CGChartData")))
    {
        return  ;
    }

    QVariantList args;
    args.append( msg);
    QVariant ret = Scene()->GetScriptEngine()->Call("getContextMenu", args);
    if (ret.toString().indexOf("error:") == -1)
    {
        PopupContextMenu( ret,contextMenu);
    }
    if (!contextMenu.isEmpty())
        contextMenu.exec(global_pos);

}
void CGraphView::OnContextMenu()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString menuStr = action->text();
        QVariant menuData = action->data();
        emit ContextMenuClicked(menuStr, menuData);
    }
}

void CGraphView::LoadScript(QString fn)
{
    Scene()->GetScriptEngine()->LoadFile(fn);
}

QObject* CGraphView::AddPixmap(QString objName, QString pixName, qreal x, qreal y, QString userData)
{
    QString fn;
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP, pixName, fn);
    QGraphicsItem* item=ItemFactory::CreateItem("image");
    if (item == NULL)
        return NULL;
    CPixmapData *pData=(CPixmapData *)g_dataPtr(item);
	pData->SetName(objName);
    pData->Load(fn);
    item->setPos(x, y);
    item->setVisible(true);

    int key_type = 100;
    item->setData(key_type, userData);
    QString data = item->data(key_type).toString();

    Scene()->AddItem(item);
    gInfo("-------------------Scene()->addItem(token); %f,%f",x,y);

    //Scene()->GetScriptEngine()->AddObject(pData,objName);
    return pData;
}

QObject* CGraphView::AddPolygon(QString objName, QString points,QString userData)
{
    return NULL;
}

QObject* CGraphView::AddText(QString objName,QString text,int x,int y,QString userData)
{
    return NULL;
}

QObject* CGraphView::AddItem(QVariantMap jsonobj,int x,int y,QObject * parent)
{
    CBaseData* pdata=NULL;
    QString iconName=jsonobj["template-name"].toString();
    QString typeName=jsonobj["type-name"].toString();
    QString objName=jsonobj["name"].toString();
    if(typeName.isEmpty())
        return NULL;

    QGraphicsItem* parentItem=NULL;
    QPointF pos;
    if(parent && parent->inherits("CBaseData"))
    {
        parentItem=((CBaseData*)parent)->Item();
        pos=parentItem->boundingRect().center();       
    }
    QGraphicsItem* pItem = ItemFactory::CreateItem(typeName,parentItem,Scene());
    if(!pItem)
        return NULL;
    pdata=g_dataPtr(pItem);
    if(!objName.isEmpty())
        pdata->SetName(objName);

    if(pItem->type()==Hmi::Icon)
        ((CIconData*)pdata)->SetTemplateName(iconName,true);

    else if(typeName=="path" && !iconName.isEmpty())
    {
        ((CAbstractPathData*)pdata)->SetSymbolName(iconName);
    }

    pItem->setPos(pos.x()+x,pos.y()+y);
    if(parent==NULL)
        Scene()->AddItem(pItem);

    //Scene()->GetScriptEngine()->AddObject(pdata,objName );

    return pdata;
}

void CGraphView::AddItemObj(QObject* dataPtr)
{
	CBaseData* ptr = (CBaseData*)dataPtr;
	if (ptr && ptr->Item())
	{
        Scene()->AddItem(ptr->Item());
	}
}

void CGraphView::RemoveItem(QObject* dataPtr)
{
	CBaseData* ptr = (CBaseData*)dataPtr;
	if (ptr && ptr->Item())
	{
		Scene()->removeItem(ptr->Item());
		Scene()->RemoveItemIdx(ptr->Item());
		delete dataPtr;
	}
}

void CGraphView::Set(const QString & key, const QString & value)
{
    m_Vars[key]=value;
}

QString CGraphView::Get( const QString & key )
{
    return m_Vars[key];
}
QVariant	CGraphView::DoCmd(QString script_code) //执行脚本
{
    if (!Scene())
        return "No appoint scene";
    return Scene()->GetScriptEngine()->Evaluate(script_code);

}
//jQuery selector, "*" ,"#id" ,".class" ,"[attribute]","[attribute=value]","[attribute!=value]","[attribute$=value]"
QObjectList CGraphView::Items(const QString& selector,QObject* parent ,bool ifTopItem )
{  
    return Scene()->Items( selector, parent , ifTopItem );
}

QList<QObject*> CGraphView::SelectedItems()
{
    QList<QObject*> ret;
    foreach(QGraphicsItem* item,Scene()->selectedItems())
    {
        CBaseData* pdata=g_dataPtr(item);
        if (pdata)
        {
            ret.append(pdata);
        }
    }
    return ret;
}

QObjectList CGraphView::Items(bool ifTopItem, bool ifSelected, int order)
{
	QList<QObject*> retlist;
    foreach(QGraphicsItem *item, Scene()->Items(ifTopItem,ifSelected,order))
    {
        CBaseData* pdata = g_dataPtr(item);
        if (pdata)
        {
			retlist.append((QObject*)pdata);
        }
    }
    return retlist;
}

bool CGraphView::SetCurrentItemProperty(const QString& propname, const QVariant& value)
{
    QList<QObject*> selItems = SelectedItems();
    if (selItems.size() != 1)
        return false;
    CBaseData* data = dynamic_cast<CBaseData*>(selItems[0]);
    return data->SetProperty(propname, value);
}

QVariant CGraphView::GetCurrentItemProperty(QString propname)
{
    QList<QObject*> selItems = SelectedItems();
    if (selItems.size() != 1)
        return QVariant();
    CBaseData* data = dynamic_cast<CBaseData*>(selItems[0]);
    return data->Property( propname );
}

QObject* CGraphView::GetScriptEngine()
{
    return Scene()->GetScriptEngine();
}

void    CGraphView::EnableDebug(bool enable)
{
    Scene()->GetScriptEngine()->EnableDebug(enable);
}

QObject* CGraphView::GetElement(QString id)
{
    QGraphicsItem* pitem=Scene()->GetElementById(id);
	if (!pitem)
		return NULL;
    CBaseData* pdata = g_dataPtr(pitem);
	if (!pdata)
		return NULL;
    QGraphicsProxyWidget *pwidget = dynamic_cast<QGraphicsProxyWidget *>(pitem);
    if(pwidget)
    {
        return pwidget->widget();
    }
    else
    {
        return pdata;
    }
}

QObject* CGraphView::GetElementById(QString id)
{
    return GetElement(  id);
}

QScriptValue  CGraphView::GetElementByScriptId(QString id)
{
    return Scene()->GetScriptEngine()->globalObject().property(id); ////gd有时出问题,也许和返回类型有关/////

}
QObjectList CGraphView::FindItemPtrByKey(const QString& key)
{
	QList<QObject*> retlist;
	foreach(QGraphicsItem *item, Scene()->Items(true, false))
	{
		CBaseData* pdata = g_dataPtr(item);
		if (pdata)
		{
			if (pdata->m_UserData.contains(key))
				retlist.append((QObject*)pdata);
		}
	}
	return retlist;
}
QObject* CGraphView::CenterOn(QString itemName)
{
    QObject* itemObj = GetElement(itemName);
    if (!itemObj)
        return NULL;
    QGraphicsItem* item=NULL;
    if (itemObj->inherits("CBaseData"))
    {
        CBaseData* itemData = (CBaseData*)itemObj;
        item = itemData->Item();
    }
    else if (itemObj->inherits("QWidget"))
    {
        QWidget* itemWidget = (QWidget*)itemObj;
        item = itemWidget->graphicsProxyWidget();
    }

    Scene()->clearSelection();
    if (item)
    {
        centerOn(item);
        item->setFlag(QGraphicsItem::ItemIsSelectable, true);
        item->setSelected(true);
    }
    return itemObj;
}

QObject* CGraphView::CreateAnimation(QObject * target, const QString & propertyName,const QVariant& startval,const QVariant& endval,int duration,int loop)
{
    QPropertyAnimation *animation = new QPropertyAnimation(target,propertyName.toLocal8Bit(),this);
    animation->setDuration(duration);
    animation->setStartValue(startval);
    animation->setEndValue(endval);
    animation->setLoopCount(loop);

    animation->start();
    return animation;
}

void CGraphView::SetBackgroundImage(const QString& imageName, int mode, bool onView)
{
	if (onView)
	{
		m_BackPixmapName = imageName;
		m_BackPixmapShowWay = mode;

	}
	else
	{
		Scene()->SetPixmapShowWay(mode);
		Scene()->SetBackPixmapName(imageName);
	}
    resetCachedContent();
}

void CGraphView::SetBackgroundColor(const QString& color)
{
    QBrush brush( QColor(color),Qt::SolidPattern );
    QColor oldcolor=Scene()->backgroundBrush().color() ;
    QString back_pix_name = Scene()->GetBackPixmapName();

    if(oldcolor==QColor(255,255,255) && (back_pix_name.isEmpty() || back_pix_name=="0"))
    {
		Scene()->setBackgroundBrush(brush);
        //viewport()->setStyleSheet( " background-color: "+color  );
        setStyleSheet( "QGraphicsView {background-color: "+color+" }" );
        //viewport()->setBackgroundRole(QColor(color));
    }
}

bool    CGraphView::StartDrag(QObject* obj,const QString& msg)
{
    QMimeData *mimeData = new QMimeData;
    mimeData->setText(msg);
    QDrag *drag = new QDrag(obj);
    drag->setMimeData(mimeData);
    int gg=drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
    if(gg==Qt::CopyAction)
        return true;
    return false;
}

void CGraphView::dropEvent(QDropEvent * event)
{
    QPointF pos=mapToScene(event->pos());
    QString src_msg=event->mimeData()->text();
    QStringList formats=event->mimeData()->formats();

    Scene()->clearSelection();
    QList<QGraphicsItem *> items =Scene()->Items(pos,true );
    if(items.size()>0)
    {
        items[0]->setSelected(true);
    }

    event->acceptProposedAction();
    QGraphicsView::dropEvent(event);

    QString des_msg="";
    QObject* curobj=GetItemInfo( pos.toPoint(),des_msg);

    QJsonObject jsonObj=UnqFunc()->Str2Json(des_msg);
    jsonObj["src_msg"] =src_msg;
    QString msg=UnqFunc()->Json2Str(jsonObj);


    emit DropEvent(curobj, msg);
}

bool CGraphView::eventFilter(QObject *obj, QEvent *event)
{
    switch(event->type())
    {
    case QEvent::FocusIn:

        break;
    case QEvent::FocusOut:


        break;

    case QEvent::WindowDeactivate:
        emit FocusOutEvent();
        break;

    case QEvent::ToolTip:
    {
        QHelpEvent *helpEvent = static_cast<QHelpEvent *>(event);
        ShowTip(helpEvent->pos());
        break;
    }
    default:
        break;
    }
    return QGraphicsView::eventFilter(obj, event);
}

QVariantMap CGraphView::CustomPropertys()
{
    QVariantMap attrs;
	foreach(QByteArray barray, scene()->dynamicPropertyNames())
	{
		attrs[QString(barray)] = scene()->property(barray.data());
	}
	return attrs;
}
bool CGraphView::SetProperty(const QString& propname,const QVariant& value)
{
    return Scene()->SetProperty(propname, value);
}

QVariant CGraphView::Property(QString name,bool allprop )
{
    return Scene()->Property(name, allprop);
}

QString CGraphView::GetScript()
{ 
	return Scene()->GetScript(); 
}

int CGraphView::EmitSignal(const QString& signal,const QVariant& value)
{
    emit ItemChange( signal, value);

    return 0;
}

QObject* CGraphView::Create(QString objname,const QVariant& args )
{
    if(objname=="Timer"){
        CGTimer * pTimer=new CGTimer(this);
        return pTimer;
    }
    else
        return NULL;
}
