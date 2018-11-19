


#include <QUndoView>
#include <QDialog>
#include <QDebug>
#include <QXmlStreamWriter>
#include <QDomDocument>
#include "DesignerScene.h"
#include "DrawManager.h"
#include "Commands.h"
#include "DrawTool.h"
#include "GraphSvgRW.h"
#include "ItemCreator.h"
#include "AnimateDriver.h"
#include "GFunc.h"
#include "IconDlg.h"
#include "NameManager.h"
#include "ActionManager.h"
#include "ReplaceDlg.h"
#include "CommunicatePluginMng.h"
#include "IconMng.h"
#include "ItemBox.h"
#include "ConstString.h"
#include "BaseData.h"
#include "WidgetItem.h"
#include "GroupItem.h"
#include "CGrid.h"
#include "CQScriptWrap.h"
#include "Mdi.h"
#include "DesignerWnd.h"
#include "DesignerView.h"
#include "qsvgtinydocument_p.h"

inline bool g_LeftScenePosLessThan(const QGraphicsItem* lhs, const QGraphicsItem* rhs)
{
    return lhs->sceneBoundingRect().left()<rhs->sceneBoundingRect().left();
}

inline bool g_TopScenePosLessThan(const QGraphicsItem* lhs, const QGraphicsItem* rhs)
{
    return lhs->sceneBoundingRect().top()<rhs->sceneBoundingRect().top();
}


CDesignerScene::CDesignerScene(QObject *parent)
    :CGraphScene( parent),
      m_undoStack(new QUndoStack(this))
{
    m_dragStartPos=QPoint(0,0);
    m_StateNums=1;
    //setBackgroundBrush(Qt::white);
    QObject::connect(this, SIGNAL(selectionChanged()), this, SLOT(OnSelectionChanged()));
    m_ifEditIcon = false;
    setProperty("sceneType","sceneType_editor");
    SetSceneType(Hmi::Designer);


    m_pasteNum = 0;
    m_beModified = false;
    m_readOnly=false;
}

CDesignerScene::~CDesignerScene()
{
}

void CDesignerScene::SetupUndoConnecting( QAction* undoAction, QAction* redoAction )
{
    QObject::connect(m_undoStack, SIGNAL(canUndoChanged(bool)), undoAction, SLOT(setEnabled(bool)));
    QObject::connect(m_undoStack, SIGNAL(canRedoChanged(bool)), redoAction, SLOT(setEnabled(bool)));
}

int CDesignerScene::FileImport(const QString& fileName)
{
    int ret=-1;
#ifdef GSVG
    UnqFunc()->TmRestart();
    UnqFunc()->TmDebug("----SvgTinyDocument::load--start");
    QSvgTinyDocument *doc = QSvgTinyDocument::load(fileName);
    UnqFunc()->TmDebug("----SvgTinyDocument::load--over");
    if (doc)
        ret=doc->ToGraphics(this);
    UnqFunc()->TmDebug("----SvgTinyDocument::ToGraphics--over");
#endif
    return ret;
}


int CDesignerScene::FileOpen(const QString& fileName, bool isBinary)
{
	int RET = CGraphScene::FileOpen(fileName, isBinary);
    QMap<QString,QGraphicsItem*> itemMap;
    foreach(QGraphicsItem* item, items())
    {
        int itype=item->type();
        item->setFlag(QGraphicsItem::ItemIsMovable, true);
        if(g_isPinItem(itype) ) item->setFlag(QGraphicsItem::ItemSendsScenePositionChanges, true);
        CBaseData* pdata=g_dataPtr(item);
        if (pdata == NULL)
            continue;
        QString name=pdata->GetName();
        itemMap[name]=item;

        if (!name.isEmpty() && item->parentItem()==NULL)
        {
            QGraphicsProxyWidget *pwidget = dynamic_cast<QGraphicsProxyWidget *>(item);
            if(pwidget)
            {
                GetScriptEngine()->AddObject(pwidget->widget(),name);
            }
            else
            {
                GetScriptEngine()->AddObject(pdata,name);
            }
        }
        if( GetSceneType()==Hmi::Designer && itype==Hmi::Icon)
            pdata->SetState(0);
    }

	/*
    foreach(QGraphicsItem* item, items())
    {
        CBaseData* pdata=g_dataPtr(item);
        if (pdata == NULL)
            continue;
        QString pName=pdata->ParentName();
        if(!pName.isEmpty())
            item->setParentItem(itemMap[pName]);

    }
	*/


#if 0
    if(fileName.endsWith(ICONSUFFIX))
    {
        foreach(QGraphicsItem* item,this->items())
        {
            if (!item->parentItem())
            {
                if (CGroupItem* gItem = dynamic_cast<CGroupItem*>(item))
                {
                    g_DestructGroupItem(gItem, this);
                }
                break;
            }
        }
    }
#endif

    return RET;
}



int CDesignerScene::FileSave(const QString& fileName, bool isBinary)
{

	CGraphScene::FileSave(fileName, isBinary);
	FileSaveChannelLink(fileName);

    return 0;
}

void CDesignerScene::UpdateScene()
{
    QList<QGraphicsItem*> itemsList = Items(true,false);
	int type = GetFileType();
	bool if_show = true;
    foreach(QGraphicsItem* item,itemsList)
    {
        CBaseData* pdata=g_dataPtr(item);
        if (pdata == NULL)
            continue;
        const short objPlane = pdata->GetPlane();
        if (objPlane >= m_ShowPlanesMask.size())
        {
            item->setVisible(false);
            continue;
        }
		if_show = m_ShowPlanesMask.at(objPlane);
		item->setEnabled(true);
        if( GetSceneType()!=Hmi::Iconer )
        {
			if (pdata->GetState() > 0)
				if_show = false;
        }
		if (if_show){
			if (item->type() != Hmi::Pin){
				if ( objPlane != m_currentPlane){
					item->setEnabled(false);
				}
			}
		}
		item->setVisible(if_show);
    }
}


int CDesignerScene::FileSaveChannelLink(const QString& fileName)
{

    QStringList tagNames;
    foreach (QGraphicsItem *item, items())
    {
        CBaseData* pdata=g_dataPtr(item);
    }



    UnqCommPluginMng()->SaveChannel(fileName,QVariant(tagNames));
    return 0;

}

void CDesignerScene::OnEditLevelPrivate(ACTION_ORDER alignOrient)
{
    QList<QGraphicsItem *> lst=selectedItems();
    if(lst.size()==0) return;
    QList<UndoStru<qreal> >  cmdStruLst;
    QRectF rc=lst.first()->boundingRect();
    foreach (QGraphicsItem *item, lst)
    {
        //if(item->parentItem())
            //continue;
        UndoStru<qreal> cmdStru;
        cmdStru.item = item;
        cmdStru.oldValue = item->zValue();
        cmdStru.newValue = item->zValue();
        rc|=item->boundingRect();
        cmdStruLst.push_back(cmdStru);
    }

    if(cmdStruLst.size()==0)
        return;

	QList<QGraphicsItem *> overlapItems = Items(true, false); //items(rc);
	if (overlapItems.size() == 0) return;

	qreal newZValue = overlapItems.first()->zValue();
    bool isChange = false;
    foreach (QGraphicsItem *item, overlapItems)
    {
        if(item->parentItem())
            continue;
        if(EditLevelUp == alignOrient)
        {
            if (item->zValue() >= newZValue)
            {
                newZValue = item->zValue() + 0.1;
                isChange = true;
            }
        }
        else
        {
            if (item->zValue() <= newZValue)
            {
                newZValue = item->zValue() - 0.1;
                isChange = true;
            }
        }
    }

	for (int i = 0; i < cmdStruLst.size();++i)
    {
		cmdStruLst[i].newValue = cmdStruLst[i].oldValue / 1000 + newZValue;
    }


    if(isChange)
    {
#if 0
        m_undoStack->push(new SimpleEditForItemCommand<QGraphicsItem, qreal>
                          (tagItem, tagItem->zValue(),
                           &QGraphicsItem::setZValue,
                           newZValue,
                           "Edit item's Z value"));
#endif
        m_undoStack->push(new EditLevelMultiItemCommand(this, cmdStruLst));
        //m_undoStack->push(new EditLevelItemCommand(this, tagItem, newZValue));
    }
}
void CDesignerScene::SetModified(bool beModified)
{
    m_beModified = beModified;
    CMdiSubWindow* awnd = Mdi::CurrentWnd()->ActiveSubWindow();
    if (awnd == NULL)
        return;

    QString title = awnd->windowTitle();

    if (m_beModified)
    {
        if (title.right(2)!=" *")
            awnd->setWindowTitle(title + " *");
    }
    else
    {
        if (title.right(2) == " *")
            awnd->setWindowTitle(title.left(title.length() - 2));
    }
}
void CDesignerScene::OnEditDelete()
{
    m_undoStack->push(new DelItemCommand(this, Items(true,true)));
}

void CDesignerScene::OnEditCut()
{
	OnEditCopy();
	OnEditDelete();
}

void CDesignerScene::OnEditCopy()
{
    QBuffer buffer;
    if (!buffer.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, tr("Clipboard"), tr("Can not copy to Clipboard.\n Error: ")+buffer.errorString());
        return;
    }
    CGraphSvgWriter inStream(&buffer);
    inStream.Init();
	foreach(QGraphicsItem* item, Items(true, true, Qt::AscendingOrder))
    {
        CBaseData* pData = g_dataPtr(item);
        if(!pData)
            continue;

        pData->Save(&inStream);
    }

    QMimeData *mimeData = new QMimeData;
    QByteArray arr = buffer.data();
#if 1
    mimeData->setData("clipboard", buffer.data());
    QApplication::clipboard()->clear();
    QApplication::clipboard()->setMimeData(mimeData);
    m_pasteNum = 0;
#else
    QApplication::clipboard()->setText(QString(arr));
#endif

    buffer.close();

}

void CDesignerScene::OnEditPaste()
{
    QPointF pos(0,0);
    OnEditPaste(pos );
}

void CDesignerScene::OnEditPaste(QPointF dp,bool clearData)
{
#if 1
    const QMimeData* pMimeData = QApplication::clipboard()->mimeData();
    if(!pMimeData || pMimeData->data("clipboard").isNull())
        return;

    QBuffer buffer(&pMimeData->data("clipboard"));
#else
    QBuffer buffer(&QApplication::clipboard()->text().toLocal8Bit());
#endif
    if(!buffer.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, tr("Clipboard"), tr("Cannot open buffer for clipboard.\n Error: ")+buffer.errorString());
        return;
    }

    CGraphSvgReader outStream(&buffer);
    QList<QGraphicsItem*> itemsList = PasteRead(outStream);
    buffer.close();
    if(itemsList.empty())
        return;

    clearSelection();
    m_pasteNum++;

    if(dp==QPointF(0,0))
            dp=QPointF(50 * m_pasteNum, 0 * m_pasteNum);

    foreach(QGraphicsItem* item, itemsList)
    {        
        item->moveBy(dp.x(),dp.y());
        item->setSelected(true);
        if(clearData){
            CBaseData* pData = g_dataPtr(item);
            if(!pData){
                pData->SetUserData("");
            }
        }

    }

 

    m_undoStack->push(new PasteItemCommand(this, itemsList));
}

QList<QGraphicsItem*> CDesignerScene::PasteRead(CGraphSvgReader& outStream)
{
    QList<QGraphicsItem*> itemsList;
    QString itemName;

    if(outStream.ReadNextStartElement())
    {
        if (outStream.name() == "svg" )
        {
            while ( outStream.ReadNextStartElement() )
            {
                outStream.ReadAttribute("type-name",itemName);
                QGraphicsItem* item=ItemCreator::CreateItem(itemName,0,this);
                if (item)
                {
                    itemsList.push_back(item);
                    CBaseData* pdata=g_dataPtr(item);
                    if (pdata)
                    {
                        pdata->Load(&outStream);                        
                    }
                }
                else
                {
                    outStream.skipCurrentElement();
                }
            }
        }
        else
        {
            outStream.raiseError(QObject::tr("The file is not a svg file"));
            return itemsList;
        }
    }
    return itemsList;
}



void CDesignerScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    QPointF pt=e->scenePos();
    UnqGrid()->GetCatchPoint(pt);
    m_dragStartPos = pt;
    bool RET = UnqDrawMng()->MousePressEvent(this, e);
    if(!RET)
    {
        e->accept();
        return;
    }

    QGraphicsScene::mousePressEvent(e);
    m_moveCmdStruList.clear();
    if(e->button() == Qt::LeftButton && !selectedItems().empty())
    {
#if 0
        if(QApplication::keyboardModifiers() == Qt::AltModifier)
        {
            selectedItems().at(0)->setFlag(QGraphicsItem::ItemIsSelectable,false);
            QList<QGraphicsItem*> itemList = items(e->pos());


            if(itemList.size()>0)
            {
                clearSelection();
                itemList.at(0)->setSelected(true);
            }
        }
#endif

        foreach(QGraphicsItem* item, Items(true,true))
        {
            UndoStru<QPointF> cmdStru;
            cmdStru.item = item;
            cmdStru.oldValue = item->pos();
            cmdStru.newValue = item->pos();
            m_moveCmdStruList.push_back(cmdStru);
        }
    }

    if(selectedItems().empty() )
    {
        foreach(QGraphicsItem* item, items())
        {
            if(item->type()==Hmi::Group || item->type()==Hmi::Icon)
            {
                item->setHandlesChildEvents(true);
            }
        }
    }
}

void CDesignerScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    QPointF pt=e->scenePos();
    UnqGrid()->GetCatchPoint(pt);
    ////ctrl 拖拽可以复制////
    if (e->buttons() & Qt::LeftButton && QApplication::keyboardModifiers() == Qt::ControlModifier )
    {
        QList<QGraphicsItem *> slist= Items(true,true);
        int distance = (pt - m_dragStartPos).manhattanLength();
        if (slist.size()>0 && distance >= QApplication::startDragDistance())
        {
            QRectF bRect,irect;
            foreach(QGraphicsItem* item, slist)
            {
                if(!bRect.isValid() ) bRect = item->sceneBoundingRect();
                bRect |= item->sceneBoundingRect();
                if(!irect.isValid() ) irect = item->sceneBoundingRect();
                irect|=item->boundingRect();
            }
           // bRect =views().at(0)->mapFromScene(bRect);

			float kk = views().at(0)->matrix().m11();
            gInfo("----bRect-%f,%f,irect==%f,%f,kk=%f",bRect.x(),bRect.y(),irect.x(),irect.y(),kk);
			QPixmap pix(bRect.width()*kk, bRect.height()*kk);
            pix.fill(Qt::transparent);

			QStyleOptionGraphicsItem style;
			QPainter painter;
			painter.begin(&pix);
			int width = bRect.width() > bRect.height() ? bRect.width() : bRect.height();
			//painter.setWindow(0, 0, bRect.right(), bRect.bottom());
			//painter.setViewport(bRect.toRect());
			painter.setBackground(Qt::transparent);
			painter.setBackgroundMode(Qt::OpaqueMode);
			painter.scale(kk, kk);
            painter.translate(-irect.x() , -irect.y() );

			foreach(QGraphicsItem* item, slist)
			{
				item->paint(&painter, &style);
			}
			painter.end();

            QMimeData *mimeData = new QMimeData;
            mimeData->setText("items/copy");
            QDrag *drag = new QDrag(this);
            drag->setMimeData(mimeData);
            OnEditCopy();
            drag->setPixmap(pix);
            drag->setHotSpot(QPointF(m_dragStartPos-bRect.topLeft()).toPoint()*kk);

            int gg=drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
        }
        return;
    }

    emit MouseMoved(e->scenePos());
    bool RET = UnqDrawMng()->MouseMoveEvent(this, e);
    QGraphicsScene::mouseMoveEvent(e);

}

void CDesignerScene::dropEvent(QGraphicsSceneDragDropEvent * e)
{
    m_DropPoint= e->scenePos();
    UnqGrid()->GetCatchPoint(m_DropPoint);
    //
    if (e->mimeData()->hasText( ) && e->mimeData()->text()=="items/copy"){
        e->acceptProposedAction();
        gInfo("--111-m_DropPoint--%d,%d", m_DropPoint.x(), m_DropPoint.y());
        QPointF dp=m_DropPoint - m_dragStartPos;
        OnEditPaste(dp);
    }
    e->acceptProposedAction();
    QGraphicsScene::dropEvent(e);
}

QObject* CDesignerScene::CreateItem(const QString& jsonstr,int dx,int dy)
{
    QPointF pos1=m_DropPoint;
    QPointF pos2=m_DropPoint+QPoint(dx,dy);

    QGraphicsItem * existItem =itemAt(m_DropPoint,QTransform());
    if(existItem)
    {
        existItem->type();
    }
    QJsonObject jobj=UnqFunc()->Str2Json(jsonstr);
    QString iconName=jobj["icon"].toString();
    QString iconType=jobj["type"].toString();
    if(iconType.isEmpty())
        return NULL;

    if(iconType=="path" && !iconName.isEmpty())
    {
        CPathItem* pathitem = ItemCreator::CreateSpecifyItem<CPathItem>();
        CAbstractPathData* pdata = (CAbstractPathData*)(g_dataPtr(pathitem));
        pdata->SetSymbolName(iconName);
        addItem(pathitem);
        pathitem->setPos(pos2);
        return pdata;
    }

    UnqDrawMng()->OnChangeCreateType(iconType);
    UnqDrawMng()->MousePress(this,Qt::LeftButton, pos1);
    IDrawTool* ptool = UnqDrawMng()->CurrentDrawTool();

    if(ptool && (ptool->GetClickEditMode() != IDrawTool::SingleClickMode))
    {
        UnqDrawMng()->OnMouseMoveInitDrawing(pos2);
        UnqDrawMng()->MousePress(this,Qt::LeftButton, pos2);
    }
    UnqDrawMng()->MousePress(this,Qt::RightButton, pos2);
    QList<QGraphicsItem *> ilist=Items(true,true);
    if(ilist.size()>0)
        return g_dataPtr(ilist[0]);
    else
        return NULL;
}

void CDesignerScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent *e )
{
    QPointF pt=e->scenePos();
    UnqGrid()->GetCatchPoint(pt);

    bool RET = UnqDrawMng()->MouseDoubleClickEvent(this, e);
    if(RET)
        QGraphicsScene::mouseDoubleClickEvent(e);
    if(selectedItems().size()>0)
    {
        QGraphicsItem* item=selectedItems().at(0);
        if(item->type()==Hmi::Group || (item->type()==Hmi::Icon && ((CIconData*)g_dataPtr(item))->GetIfRef()==false))
        {
            item->setHandlesChildEvents(false);
        }
		else if (item->type() == Hmi::Text)
		{
			bool ok;
			CTextData* pdata = (CTextData*)g_dataPtr(item);
            QString text = QInputDialog::getMultiLineText(View(), QObject::tr("please input"),
                QObject::tr("please input:"), pdata->Text(), &ok);
			if (ok && !text.isEmpty())
				pdata->SetText(text);
		}
		if (item->type() == Hmi::Pixmap)
		{
			CPixmapData* pdata = (CPixmapData*)g_dataPtr(item);
            QString fileName = QFileDialog::getOpenFileName(View(), QObject::tr("Open File"),UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP),QObject::tr("Images (*.png *.gif *.jpg *.*)"));
            if(!fileName.isEmpty()) pdata->Load(fileName);
		}
        else if (item->type() == Hmi::SwitchButton)
        {
            CWidgetItem* pitem = (CWidgetItem*)(item);
            QSwitchButton* btn=(QSwitchButton*)pitem->widget();
            QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP);
            QString fileName = QFileDialog::getOpenFileName(View(), QObject::tr("Open File"),path,QObject::tr("Images (*.png *.gif *.jpg)"));
            fileName=fileName.right(fileName.length()-path.length());
            btn->SetBgPixmap(fileName);
        }
		else if (item->type() == Hmi::SvgItem)
		{
			QString fileName = QFileDialog::getOpenFileName(View(), QObject::tr("Open File"), UnqFunc()->GetDir(CGFunc::PATH_TYPE_DATA), QObject::tr("files (*.svg)"));
			if (!fileName.isEmpty()) ((CSvgItem*)item)->Load(fileName);
		}
		else
		{
			/*AnimationDlg dlg(View(), this);
			if (dlg.exec() == QDialog::Accepted)
				this->SetModified(true);*/
		}
    }

}

void CDesignerScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QPointF pt=e->scenePos();
    UnqGrid()->GetCatchPoint(pt);
    UnqDrawMng()->MouseReleaseEvent(this, e);
    QGraphicsScene::mouseReleaseEvent(e);

	QList<QGraphicsItem*> sList = Items(true, true);
	if (e->button() == Qt::LeftButton && !sList.empty() && sList.size() == m_moveCmdStruList.size())
    {
        for(int i=0; i<m_moveCmdStruList.size(); ++i)
        {
            if(sList[i] != m_moveCmdStruList[i].item || sList[i]->pos() == m_moveCmdStruList[i].oldValue)
                return;
            m_moveCmdStruList[i].newValue = sList[i]->pos();
        }
    }
    else
        m_moveCmdStruList.clear();

    if(!m_moveCmdStruList.empty())
    {
        m_undoStack->push(new MoveItemCommand(this, m_moveCmdStruList));
        m_moveCmdStruList.clear();
    }
}

void CDesignerScene::keyPressEvent( QKeyEvent * e )
{
    if(ReadOnly()) return;
    bool RET = UnqDrawMng()->KeyPressEvent(this, e);
    if(!selectedItems().empty())
    {
        int interval = UnqGrid()->GetGridSize();
        if (e->modifiers() & Qt::ControlModifier)
            interval = 1;
        int dx=0, dy=0;
        switch(e->key())
        {
        case Qt::Key_Up :
            dy = -interval; break;
        case Qt::Key_Left:
            dx = -interval; break;
        case Qt::Key_Down:
            dy = interval; break;
        case Qt::Key_Right:
            dx = interval; break;
        default:
            dx=dy=0; break;
        }
        if(dx||dy)
        {
			RET = false;
			QList<QGraphicsItem*> sItems = Items(true,true);
            QList<UndoStru<QPointF> > mvCmdStruList;
			QList<UndoStru<QPointF> > linkMvCmdStruList;
			foreach(QGraphicsItem* item, sItems)
			{
				UndoStru<QPointF> stru;
				stru.item = item;
				stru.oldValue = item->pos();
				stru.newValue = item->pos() + QPointF(dx, dy);
				if (item->type() == Hmi::Link)
					linkMvCmdStruList.push_back(stru);
				else
					mvCmdStruList.push_back(stru);
			}
			m_undoStack->push(new MoveItemCommand(this, linkMvCmdStruList));//must first move link,because when move icon, the linked link-pin is auto move, can make the link-pin move twice
			m_undoStack->push(new MoveItemCommand(this, mvCmdStruList));
        }
    }

    if(RET)
        QGraphicsScene::keyPressEvent(e);
}

void CDesignerScene::keyReleaseEvent( QKeyEvent * e )
{
    if(ReadOnly()) return;
    bool RET = UnqDrawMng()->KeyReleaseEvent(this, e);
    if(RET)
        QGraphicsScene::keyReleaseEvent(e);

}

void CDesignerScene::OnEditGroup()
{
    if (selectedItems().empty())
        return;

    m_undoStack->push(new EditGroupItemCommand(this));
}


void CDesignerScene::OnEditUnGroup()
{
	QList<QGraphicsItem*> items = selectedItems();
	if (items.size() == 1 && items.first()->type() != Hmi::Group)
		return;

	if (items.size() > 1)
	{
		if (QMessageBox::Ok == QMessageBox::information(0, tr("Tips"), tr("Sure to unGroup all?"), QMessageBox::Ok,	QMessageBox::Cancel	))
		{
			for (int i = 0; i < items.size(); i++)
			{
				QGraphicsItem* item = items.at(i);
				if (item->type() == Hmi::Group)
					m_undoStack->push(new EditUnGroupItemCommand(this, dynamic_cast<CGroupItem*>(items.at(i))));
			}
		}
	}
	else
		m_undoStack->push(new EditUnGroupItemCommand(this, dynamic_cast<CGroupItem*>(items.first())));
}


void CDesignerScene::OnEditAddPoint()
{
    if(!UnqDrawMng()->IsMoveMode())
        return;

    UnqDrawMng()->SwitchMode(CDrawManager::AddItemPoint);


}

void CDesignerScene::OnEditDelPoint()
{
    if(!UnqDrawMng()->IsMoveMode())
        return;

    UnqDrawMng()->SwitchMode(CDrawManager::DelItemPoint);
}

void CDesignerScene::OnBreakIcon()
{

    QList<QGraphicsItem *> list=selectedItems();
    if(list.size()>0 )
    {
        QGraphicsItem *iconItem=list[0];
        if (iconItem->type()==Hmi::Icon)
        {
            foreach (QGraphicsItem *item, iconItem->childItems())
            {
                ((QGraphicsItemGroup*)iconItem)->removeFromGroup(item);
                addItem(item);
                if(CBaseData* pdata = g_dataPtr(item))
                    pdata->SetName(UnqNameMng()->ItemGetName(item));
                item->setFlag(QGraphicsItem::ItemIsSelectable, true);
                item->setSelected(true);
            }
            removeItem(iconItem);
        }
    }

}

void CDesignerScene::SaveIconByScene(const QString& fileName, const QString& iType)
{
    QString iconName,iconCoreName ;
    QString iconType=iType;
    QString typeName,planeInfo,isPinPlane;
    int pinNum, stateNum;

	UnqFunc()->GetGraphCoreNameByGraphPathName(fileName, iconCoreName);
	UnqIconMng()->GetIconType(iType.toInt(), typeName, pinNum, stateNum, planeInfo, isPinPlane);
    if(stateNum>1) stateNum=GetPlaneNums();
	iconName = UnqIconMng()->GetRegIconName(iconCoreName);
    CIconItem* piconItem = ItemCreator::CreateSpecifyItem<CIconItem>();

	QMap<short, CBaseData*> pinsMap;//planeNo->pinData*
	bool beOk = true;
    foreach (QGraphicsItem *item, items())
    {
        CBaseData* ptmpdata = g_dataPtr(item) ;
        short plane= ptmpdata->GetPlane();
		if (stateNum>1)
			ptmpdata->SetState(plane);
		else
			ptmpdata->SetState(0);//just like transformer which has 5 planes,but 1 state
        piconItem->addToGroup(item);
		
		if (isPinPlane.toInt()==1 && ptmpdata->Type() == Hmi::Pin)//just like transformer
		{
			if (pinsMap.find(plane) != pinsMap.end())
			{
				beOk = false;
			}
			else
				pinsMap.insert(plane, ptmpdata);
		}
    }

	if (isPinPlane.toInt() == 1)//just like transformer
	{
		if (!beOk  || pinsMap.size() != pinNum)
		{
			QMessageBox::information(0, tr("Tips"), tr("Every plane must have only one pin, please modify!"));
			//return;
		}
		else{
			//rename pin
			QMap<short, CBaseData*>::iterator itr;
			for (itr = pinsMap.begin(); itr != pinsMap.end(); ++itr)
			{
				int planeNo = itr.key();
				CBaseData* pPin = itr.value();
				pPin->SetName("pin_" + QString::number(planeNo));
			}
		}
	}

    addItem(piconItem);
    CIconData* pdata = (CIconData*)g_dataPtr(piconItem);
    pdata->SetTemplateName(iconName);
    pdata->SetIconType(iType.toInt());
    pdata->SetIfRef(GetIfRef());
   // pdata->SetName(UnqNameMng()->ItemGetName(piconItem));
    pdata->SetUserData(GetUserData());
    pdata->SetStateNums(stateNum);
	pdata->SetPlaneNums(GetPlaneNums());
	 
    m_StateNums=stateNum;
    UnqIconMng()->AddIcon(piconItem,iconName);

    IconSaveToFile(piconItem,fileName);
    destroyItemGroup(piconItem);
    UnqNameMng()->UpdateModel();
	UnqItemMng()->InsertItem(iconCoreName, iconType, iconType, m_iconTip, m_fileIconName);
    UnqItemMng()->SaveModelData();
    UnqActMng()->GetAction(EditIcon)->setEnabled(false);
}

void CDesignerScene::SaveIconBySelected(QString& iName, QString& iType, QString& tip)
{
    QString iconName=iName;
    QString iconType=iType;
    iconName=UnqIconMng()->GetRegIconName(iconName);
    CIconItem* piconItem = ItemCreator::CreateSpecifyItem<CIconItem>();
    addItem(piconItem);
    foreach (QGraphicsItem *item, Items(true,true))
    {
        item->setSelected(false);

        piconItem->addToGroup(item);
    }
    CIconData* pdata = (CIconData*)g_dataPtr(piconItem);
    pdata->SetTemplateName(iconName);
    pdata->SetIfRef(false);
    SetIfRef(false);
    pdata->SetIconType(iType.toInt());

    pdata->SetName(UnqNameMng()->ItemGetName(piconItem));
    pdata->SetStateNums(m_StateNums);
    pdata->SetPlaneNums(1);

    UnqIconMng()->AddIcon(piconItem,iconName);
    QString fileName;
    UnqFunc()->GetIconPathNameByIconCoreName(iName,fileName);

    IconSaveToFile(piconItem,fileName);

    UnqNameMng()->UpdateModel();

	UnqItemMng()->InsertItem(iName, iconType, iconType, tip, m_fileIconName);
    UnqItemMng()->SaveModelData();
    UnqActMng()->GetAction(EditIcon)->setEnabled(false);
}



void CDesignerScene::OnRotate()
{
    UnqDrawMng()->SetRotate();
}

void CDesignerScene::OnSwitchHvLock()
{
    IDrawTool::SwitchHvLockFlag();
}

void CDesignerScene::OnSwitchCatch()
{
    UnqGrid()->SetAdhere(!UnqGrid()->Adhere());
    IDrawTool::SwitchCatchFlag();
}

void CDesignerScene::OnSetGridWidth( int width )
{
    IDrawTool::SetGridWidth(width);
}

void CDesignerScene::OnSelectAll( )
{
    foreach(QGraphicsItem * item,items())
    {
        item->setSelected(true);
    }
}

void CDesignerScene::OnAlignPrivate( ACTION_ORDER alignOrient )
{
    if(alignOrient > AlignVerticalSpacing)
        return;

    QList<UndoStru<QPointF> > mvCmdStruList;
    QList<QGraphicsItem*> sItems = Items(true,true);
    if(AlignLeft == alignOrient)
    {
        qreal leftX = sItems.first()->sceneBoundingRect().left();
        foreach(QGraphicsItem* item, sItems)
        {
            qreal curX = item->sceneBoundingRect().left();
            if(leftX>curX)
                leftX=curX;
        }

        foreach(QGraphicsItem* item, sItems)
        {
            qreal curX = item->sceneBoundingRect().left();
            UndoStru<QPointF> stru;
            stru.item = item;
            stru.oldValue = item->pos();
            stru.newValue = item->pos()+QPointF(leftX-curX, 0);
            mvCmdStruList.push_back(stru);
        }
    }
    else if(AlignRight == alignOrient)
    {
        qreal rightX = sItems.first()->sceneBoundingRect().right();
        foreach(QGraphicsItem* item, sItems)
        {
            qreal curX = item->sceneBoundingRect().right();
            if(rightX<curX)
                rightX=curX;
        }
        foreach(QGraphicsItem* item, sItems)
        {
            qreal curX = item->sceneBoundingRect().right();
            UndoStru<QPointF> stru;
            stru.item = item;
            stru.oldValue = item->pos();
            stru.newValue = item->pos()+QPointF(rightX-curX, 0);
            mvCmdStruList.push_back(stru);
        }
    }
    else if(AlignTop == alignOrient)
    {
        qreal topY = sItems.first()->sceneBoundingRect().top();
        foreach(QGraphicsItem* item, sItems)
        {
            qreal curY = item->sceneBoundingRect().top();
            if(topY>curY)
                topY=curY;
        }
        foreach(QGraphicsItem* item, sItems)
        {
            qreal curY = item->sceneBoundingRect().top();
            UndoStru<QPointF> stru;
            stru.item = item;
            stru.oldValue = item->pos();
            stru.newValue = item->pos()+QPointF(0, topY-curY);
            mvCmdStruList.push_back(stru);
        }
    }
    else if(AlignBottom == alignOrient)
    {
        qreal bottomY = sItems.first()->sceneBoundingRect().bottom();
        foreach(QGraphicsItem* item, sItems)
        {
            qreal curY = item->sceneBoundingRect().bottom();
            if(bottomY<curY)
                bottomY=curY;
        }
        foreach(QGraphicsItem* item, sItems)
        {
            qreal curY = item->sceneBoundingRect().bottom();
            UndoStru<QPointF> stru;
            stru.item = item;
            stru.oldValue = item->pos();
            stru.newValue = item->pos()+QPointF(0, bottomY-curY);
            mvCmdStruList.push_back(stru);
        }
    }
    else if(AlignHorizontal == alignOrient || AlignVertical == alignOrient)
    {
        QRectF totalRectF;
        foreach(QGraphicsItem* item, sItems)
        {
            totalRectF |= item->sceneBoundingRect();
        }

        foreach(QGraphicsItem* item, sItems)
        {
            UndoStru<QPointF> stru;
            qreal dx = totalRectF.center().x()-item->sceneBoundingRect().center().x();
            qreal dy = totalRectF.center().y()-item->sceneBoundingRect().center().y();
            stru.item = item;
            stru.oldValue = item->pos();
            if(AlignHorizontal == alignOrient)
                stru.newValue = item->pos()+QPointF(0, dy);
            else
                stru.newValue = item->pos()+QPointF(dx, 0);
            mvCmdStruList.push_back(stru);
        }
    }
    else if(AlignHorizontalSpacing == alignOrient || AlignVerticalSpacing == alignOrient)
    {
		//equal spaceing
        QList<QGraphicsItem*> sortItems(sItems);
        if(AlignHorizontalSpacing == alignOrient)
            qStableSort(sortItems.begin(), sortItems.end(), g_LeftScenePosLessThan);
        else
            qStableSort(sortItems.begin(), sortItems.end(), g_TopScenePosLessThan);

		qreal tolx, toly;
		QGraphicsItem* previousItem = NULL;
		foreach(QGraphicsItem* item, sortItems)
		{
			if (previousItem == NULL){
				previousItem = item;
				continue;
			}
			tolx += item->sceneBoundingRect().left() - previousItem->sceneBoundingRect().right();
			toly += item->sceneBoundingRect().top() - previousItem->sceneBoundingRect().bottom();
			
			previousItem = item;
		}
		qreal itvx = tolx / (sItems.size() - 1);
		qreal itvy = toly / (sItems.size() - 1);

		qreal prevDx = 0.0, prevDy = 0.0;
		previousItem = NULL;
		foreach(QGraphicsItem* item, sortItems)
		{
			UndoStru<QPointF> stru;
			qreal dx = previousItem ? previousItem->sceneBoundingRect().right() - item->sceneBoundingRect().left() : 0.0;
			qreal dy = previousItem ? previousItem->sceneBoundingRect().bottom() - item->sceneBoundingRect().top() : 0.0;
			stru.item = previousItem = item;
			stru.oldValue = item->pos();
			if (AlignHorizontalSpacing == alignOrient)
			{
				stru.newValue = item->pos() + QPointF(dx + prevDx, 0);
				prevDx += dx + itvx;
			}
			else
			{
				stru.newValue = item->pos() + QPointF(0, dy + prevDy);
				prevDy += dy + itvy;
			}
			mvCmdStruList.push_back(stru);
		}

		/* input interval to set space
		bool ok = false;
		qreal itv = QInputDialog::getInt(0, tr("SpaceSetting"), tr("Spacing value"), 0, 0, 1000, 1, &ok);
		if (!ok || itv<0)
			return;

		QList<QGraphicsItem*> sortItems(sItems);
		if (AlignHorizontalSpacing == alignOrient)
			qStableSort(sortItems.begin(), sortItems.end(), g_LeftScenePosLessThan);
		else
			qStableSort(sortItems.begin(), sortItems.end(), g_TopScenePosLessThan);

		qreal prevDx = 0.0, prevDy = 0.0;
		QGraphicsItem* previousItem = NULL;
		foreach(QGraphicsItem* item, sortItems)
		{
			UndoStru<QPointF> stru;
			qreal dx = previousItem ? previousItem->sceneBoundingRect().right() - item->sceneBoundingRect().left() : 0.0;
			qreal dy = previousItem ? previousItem->sceneBoundingRect().bottom() - item->sceneBoundingRect().top() : 0.0;
			stru.item = previousItem = item;
			stru.oldValue = item->pos();
			if (AlignHorizontalSpacing == alignOrient)
			{
				stru.newValue = item->pos() + QPointF(dx + prevDx, 0);
				prevDx += dx + itv;
			}
			else
			{
				stru.newValue = item->pos() + QPointF(0, dy + prevDy);
				prevDy += dy + itv;
			}

			mvCmdStruList.push_back(stru);
		}*/
    }

    if (!mvCmdStruList.empty())
    {
        m_undoStack->push(new MoveItemCommand(this, mvCmdStruList));
    }

}

void CDesignerScene::OnMirrorPrivate( ACTION_ORDER alignOrient )
{
    if (AlignVerticalMirror!=alignOrient && AlignHorizontalMirror!=alignOrient)
        return;

    QList<QGraphicsItem*> sItems = selectedItems();
    int revertScale = (AlignHorizontalMirror==alignOrient) ? -1 : 1;

    QList<UndoStru<QTransform> > trfCmdStruList;
    foreach(QGraphicsItem* item, sItems)
    {
        UndoStru<QTransform> stru;
        QPointF center = item->boundingRect().center();
		CBaseData* pdata = g_dataPtr(item);
		qreal angle = pdata->GetOrgRotation();
		qreal scalex = pdata->GetOrgScaleX();
		qreal scaley = pdata->GetOrgScaleY();
        stru.item = item;
        stru.oldValue = item->transform();
		
		pdata->SetOrgRotation(-angle/**(revertScale)*/);
		pdata->SetOrgScaleX(scalex*revertScale);
		pdata->SetOrgScaleY(scaley*(-revertScale));
		CBaseData::ApplyScaleProperty(item, pdata->GetOrgRotation(), pdata->GetOrgScaleX(), pdata->GetOrgScaleY(), center);
		
		stru.newValue = item->transform();
		
		trfCmdStruList.push_back(stru);
    }
    if (!trfCmdStruList.empty())
    {
        m_undoStack->push(new EditTransformItemCommand(this, trfCmdStruList));
    }

}

void CDesignerScene::drawBackground( QPainter* painter, const QRectF& rect )
{
	QRectF tmpRect=sceneRect();
	int tmpd = tmpRect.height()/200;
	QRectF rightShadow(tmpRect.right(), tmpRect.top() + tmpd, tmpd, tmpRect.height());
	QRectF bottomShadow(tmpRect.left() + tmpd, tmpRect.bottom(), tmpRect.width(), tmpd);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    QRectF repaintRect = rect.intersected(sceneRect());
    if (repaintRect.width() == 0 && repaintRect.height() == 0)
        return;
	/**********drawPixmap is  not smooth, use QGraphScene::drawBackground, but only tile
    QString back_pix_name = GetBackPixmapName();
    if(back_pix_name.isEmpty() || back_pix_name=="0")
    {
        if (!repaintRect.isEmpty())
            painter->fillRect(repaintRect, backgroundBrush());
    }
    else
    {
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP,back_pix_name,back_pix_name);
        if (GetPixmapShowWay() == 0)//tile
			painter->drawTiledPixmap(repaintRect, QPixmap(back_pix_name));
		else if (GetPixmapShowWay() == 1)//zoom
			painter->drawPixmap(repaintRect.toRect(), QPixmap(back_pix_name));
		else //original
			painter->drawPixmap(repaintRect.topLeft(), QPixmap(back_pix_name));
    }   */
	CGraphScene::drawBackground(painter, repaintRect);
    UnqGrid()->Draw( painter,sceneRect());
}

void CDesignerScene::OnSwitchGridShow()
{
    UnqGrid()->SetVisible(!UnqGrid()->Visible());
	views().first()->invalidateScene(sceneRect(), QGraphicsScene::BackgroundLayer);
}

void CDesignerScene::OnEditReplace()
{
    ReplaceDlg dlg(View(), this);
	if (dlg.exec() == QDialog::Accepted)
		this->SetModified(true);
}

void CDesignerScene::OnEditSelectType()
{
    QList<QGraphicsItem *> selectitems=Items(true,true);
    if(selectitems.size()>0)
    {
        int type=g_dataPtr(selectitems.at(0))->Type();
		foreach(QGraphicsItem * item, Items(true, false))
		{
			if (g_dataPtr(item) && g_dataPtr(item)->Type() == type)
			{
				if (type != Hmi::Icon)
					item->setSelected(true);
				else{
                    int iconClass = ((CIconData*)g_dataPtr(selectitems.at(0)))->GetIconType();
                    if (((CIconData*)g_dataPtr(item))->GetIconType() == iconClass)
						item->setSelected(true);
				}
			}
					
		}
        Mdi::CurrentWnd()->UpdatePropertySheet(true);
    }
}

void CDesignerScene::OnEditRefIcon()
{
	QList<QGraphicsItem *> selectitems = Items(true, true);
	if (selectitems.size()>0)
	{
		int type = selectitems.at(0)->type();
		if (type == Hmi::Icon)
		{
			CIconItem* item = (CIconItem*)selectitems.at(0);
			if (item)
			{
                QString iconName = ((CIconData*)g_dataPtr(item))->GetTemplateName().replace(ICONPREFIX, "");
				UnqFunc()->GetIconPathNameByIconCoreName(iconName, iconName);
				Mdi::CurrentWnd()->OnFileOpen(iconName); 
			}
		}
	}
}

void CDesignerScene::OnSelectionChanged()
{
    UnqDrawMng()->OnSelectionChanged(Items(true,true));
    CGraphScene::OnSelectionChanged();
}

void CDesignerScene::ApplySetProperty( const QString& name, const QVariant& value, const QString &groupName )
{
    foreach (QGraphicsItem *item, selectedItems())
    {
        CBaseData* pdata=g_dataPtr(item);
        if(!pdata)
            continue;
        if(name == QObject::tr("name"))
        {
            QString valName = value.toString();
            if (valName[0] == '#' || valName.contains(' '))
                return;
            pdata->SetName(value.toString());
            UnqNameMng()->ItemRename(item);
            return;
        }
		else
		{
			pdata->SetProperty(name, value);
			SetModified(true);
		}
    }

}

void CDesignerScene::GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList)
{
    QList< QPair<QString,QVariant> > propertylist;
    if (m_ifEditIcon)
    {
        QMap<QString, QVariant> typeProperty;
        QMap<int, QStringList> iconType = UnqIconMng()->GetIconType();
        foreach(int type, iconType.keys())
        {
            QStringList typeinfo = iconType.value(type);
            if (typeinfo.length() > 0)
            {
                typeProperty[typeinfo[0] + QString("-%1").arg(type)] = type;
            }
        }
        typeProperty["__CurrentValue"] = GetFileType();
        propertylist.push_back(qMakePair(tr("iconType"), QVariant(typeProperty)));
        propertylist.push_back(qMakePair(tr("stateNums"), QVariant(m_StateNums)));
    }
    CGraphScene::GetPropertyList(propertylist);
    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >( tr("canvas"),propertylist));

    propertylist.clear();

    foreach(QByteArray barray, dynamicPropertyNames())
    {
        if(barray!="sceneType")
            propertylist<<qMakePair(QString(barray),property(barray.data()));
    }

    pptList.append(QPair<QString, QList<QPair<QString,QVariant> > >( tr("custom property"),propertylist));

}
bool CDesignerScene::SetProperty(const QString &property_name, const QVariant& value,const QString & groupName)
{
    QString prop_name=property_name ;
	if (property_name == tr("iconType") || property_name == "iconType")
	{
		SetFileType( value.toInt());
	}
	else if (property_name == tr("stateNums") || property_name == "stateNums")
    {
        m_StateNums=value.toInt();
    }
    else 
		CGraphScene::SetProperty(property_name, value);
	SetModified(true);
    return true;
}

void CDesignerScene::onGlobalSetChanged(QString propertyName, QVariant value)
{
    if (selectedItems().size() == 0)
        return;
    foreach(QGraphicsItem* item, selectedItems() )
    {
        g_dataPtr(item)->SetProperty(propertyName, value);
		if (propertyName == QObject::tr("fillColor") && g_dataPtr(item)->GetFillStyle() == Qt::NoBrush)
            g_dataPtr(item)->SetFillStyle(Qt::SolidPattern);
		else if (propertyName == QObject::tr("font"))
			g_dataPtr(item)->SetFont(value.value<QFont>());
    }
}

QString CDesignerScene::NodeGenerate()
{
    if(m_filePathName.isEmpty())
    {
        QMessageBox::information(0, tr("information"), tr("pls save pic first!"));
        return QString();
    }
    QFileInfo fileInfo(m_filePathName);
	if (!fileInfo.isFile()){
		QMessageBox::information(0, tr("information"), tr("file can not open! ") + m_filePathName);
		return QString();
	}

    QString topoFileName = m_filePathName;
    QFile topoFile(topoFileName.replace(PICSUFFIX, ".topod"));
    if (!topoFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(0, tr("information"), tr("file can not open! ")+topoFileName);
        return QString();
    }

    QTextStream in(&topoFile);

    in<<"###################################################################################"<<endl;
    in<<QObject::tr("WARNING! All changes made in this file will be lost when renodeGenerate!")<<endl;
    in<<"###################################################################################"<<endl;
    in<<QObject::tr("facInfo:   ")<<GetStationApp()<<endl;
    in<<QObject::tr("time:    ")<<QDateTime::currentDateTime().toString()<<endl;

    in.setFieldAlignment(QTextStream::AlignLeft);

    in<<qSetFieldWidth(30)<<left<<QObject::tr("node,link,tag")
     <<qSetFieldWidth(30)<<QObject::tr("pinNo,itemname,tag")
    <<qSetFieldWidth(0) <<QObject::tr("pinNo,itemname,tag")<<endl;
    QList<QGraphicsItem*> allItems = items(Qt::AscendingOrder);

    QJsonObject jObj;
    jObj["fac"]=GetStationApp();
    jObj["time"]=QDateTime::currentDateTime().toString();

    QJsonObject jGraphInfo;
    foreach(QByteArray barray, dynamicPropertyNames())
        jGraphInfo[QString(barray)]=property(barray.data()).toString();

    jObj["graphInfo"]=jGraphInfo;

    QJsonArray nodeDataArray;
    QJsonArray linkDataArray;

#define SEP QChar(',')
    QString tagInfo;
    int node=1;
    foreach(QGraphicsItem* item, allItems)
    {
        int itype=item->type();
        if(itype == Hmi::Link)
        {
            CLinkLineItem* linkItem = dynamic_cast<CLinkLineItem*>(item);
            QString linkItemTagInfo=CAnimation::GetTagInfo(linkItem);
            Q_ASSERT(linkItem);
            QStringList pinInfoList[2];
            for(int i=0;i<2;++i)
            {
                const CPinItem* pinItem = (i==0 ? linkItem->HeadPinItem() : linkItem->TailPinItem());
                if(pinItem)
                {
                    pinInfoList[i]<<g_getItemName(pinItem);
					QGraphicsItem* plinkedItem = linkItem->GetPinLinkItem(i);
                    pinInfoList[i]<< g_getItemName(plinkedItem);
                    tagInfo=CAnimation::GetTagInfo(const_cast<QGraphicsItem*>(plinkedItem));
                    pinInfoList[i]<<tagInfo;
                }
            }
            QString tmp=QString("%1").arg(node)+SEP+g_getItemName(linkItem)+SEP+linkItemTagInfo;
            in<<qSetFieldWidth(30)<<tmp<<qSetFieldWidth(30)<<pinInfoList[0].join(SEP)<<qSetFieldWidth(0)<<pinInfoList[1].join(SEP)<<endl;

            QJsonObject tmpjobj;
            tmpjobj["link"]=tmp;
            tmpjobj["from"]=pinInfoList[0].join(SEP);
            tmpjobj["to"]=pinInfoList[1].join(SEP);
            linkDataArray.append(tmpjobj);
            node++;
        }
        else if(itype == Hmi::Group || itype == Hmi::Icon)
        {
            CBaseData* pdata=g_dataPtr(item);
            QJsonObject tmpNode;
            tmpNode["id"]=pdata->GetName();
            tmpNode["type-name"]=pdata->TypeName();
            foreach(QByteArray prop, pdata->dynamicPropertyNames())
                tmpNode[QString(prop.data())]=pdata->property(prop.data()).toString();

            QJsonArray pinsInfo;
            foreach(QGraphicsItem* clditem, item->childItems())
            {
                if(clditem->type()==Hmi::Pin)
                {
                    QJsonObject tmpPin;
                    CBaseData* pclddata=g_dataPtr(clditem);
                    tmpPin["id"]=pclddata->GetName();
                    foreach(QByteArray prop, pclddata->dynamicPropertyNames())
                        tmpPin[QString(prop.data())]=pclddata->property(prop.data()).toString();
                    pinsInfo.append(tmpPin);
                }
            }
            tmpNode["pinArray"]=pinsInfo;
            nodeDataArray.append(tmpNode);

        }
    }
    topoFile.close();

    jObj["nodeDataArray"]=nodeDataArray;
    jObj["linkDataArray"]=linkDataArray;
    QString topoFileName1 = m_filePathName;
    QFile topoFile1(topoFileName1.replace(PICSUFFIX, TOPOSUFFIX));
    if (!topoFile1.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(0, tr("information"), tr("file can not open! ")+topoFileName1);
        return QString();
    }
    QTextStream jsin(&topoFile1);
    QJsonDocument jdoc(jObj);
    jsin<<jdoc.toJson(QJsonDocument::Indented)<<endl;
    topoFile1.close();


    return topoFileName1;
}
