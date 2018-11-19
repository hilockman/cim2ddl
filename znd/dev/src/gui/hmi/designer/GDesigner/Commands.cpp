
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "Commands.h"
#include "GroupItem.h"
#include "GraphItem.h"
#include "DrawManager.h"
#include "ItemCreator.h"
#include "ItemFactory.h"
#include "IconMng.h"
#include "GFunc.h"
#include "ItemBox.h"
#include "NameManager.h"
#include "GraphScene.h"
#include "DesignerScene.h"
#include "DesignerWnd.h"
#include "Mdi.h"

#define NAME_UPDATE (UnqNameMng()->UpdateModel())

AddItemCommand::AddItemCommand(QGraphicsItem* item, QUndoCommand* parent )
    : QUndoCommand(parent)
{
    m_scene=item->scene();
    m_item=item;
    ((CDesignerScene*)m_scene)->SetModified(true);
    setText( QString("Add a %1 item").arg(ItemFactory::ItemTypeName(item->type())) );
}

void AddItemCommand::undo()
{
    m_scene->removeItem(m_item);
    NAME_UPDATE;
}

void AddItemCommand::redo()
{
    if(m_item->scene() != m_scene)
        m_scene->addItem(m_item);

    NAME_UPDATE;
}


DelItemCommand::DelItemCommand( QGraphicsScene* scene, const QList<QGraphicsItem*>& itemsList, QUndoCommand* parent )
    : HandleMultiItemsCommand<QGraphicsItem*>(scene, itemsList, parent)
{
    ((CDesignerScene*)m_scene)->SetModified(true);
    setText(QString("Del %1 items").arg(itemsList.size()));
}

void DelItemCommand::undo()
{
	QList<CLinkLineItem*> lstLinkItem;
    foreach(QGraphicsItem* item, m_struList)
    {
        m_scene->addItem(item);
		((CGraphScene*)m_scene)->AppendItemIdx(item);
		if ( item->type()==Hmi::Link)
		{
			if(CLinkLineItem* pLinkItem = dynamic_cast<CLinkLineItem*>(item))
			    lstLinkItem.append(pLinkItem);
		}
    }
	foreach(CLinkLineItem* pItem, lstLinkItem)
		pItem->UpdateLoadedConnection();

    m_scene->update();
    NAME_UPDATE;
}

void DelItemCommand::redo()
{
	foreach(QGraphicsItem* item, m_struList)
	{
		m_scene->removeItem(item);
		((CGraphScene*)m_scene)->RemoveItemIdx(item);
	}
    m_scene->update();
    NAME_UPDATE;
}

PasteItemCommand::PasteItemCommand( QGraphicsScene* scene, const QList<QGraphicsItem*>& itemsList, QUndoCommand* parent )
    : HandleMultiItemsCommand<QGraphicsItem*>(scene, itemsList, parent)
{
    ((CDesignerScene*)m_scene)->SetModified(true);
    setText(QString("Paste %1 items").arg(itemsList.size()));
}

void PasteItemCommand::undo()
{
    foreach(QGraphicsItem* item, m_struList)
        m_scene->removeItem(item);
    m_scene->update();
    NAME_UPDATE;
}

void PasteItemCommand::redo()
{
    foreach(QGraphicsItem* item, m_struList)
    {
        m_scene->addItem(item);
        /////如果是一批图元复制，则加到scene后才能得到正确的唯一name，所以在这里要在设置一边name////////////////
        ItemCreator::GlobalSet(item,false);
/*
        if(item->type()==Hmi::Group || item->type()==Hmi::Icon )
        {/////如果是组合或间隔还要更新连接关系//////////
            foreach(QGraphicsItem* clditem, item->childItems())
            {
                if (clditem->type() == Hmi::Link)
                    ((CLinkLineItem*)clditem)->UpdateLoadedConnection();
            }
        }
        //
        if (item->type() == Hmi::Link)
            ((CLinkLineItem* )item)->UpdateLoadedConnection();
*/
    }
    m_scene->update();
    NAME_UPDATE;
}





void g_ConstructGroupItem(QGraphicsItemGroup* groupItem, QGraphicsScene* scene, const QList<QGraphicsItem*>& childItemList)
{
    scene->addItem(groupItem);
    foreach (QGraphicsItem *item, childItemList)
    {
        groupItem->addToGroup(item);
    }
    if(CBaseData* pdata = g_dataPtr(groupItem))
        pdata->SetName(UnqNameMng()->ItemGetName(groupItem));

	scene->clearSelection();
    groupItem->setSelected(true);
	Mdi::CurrentWnd()->UpdatePropertySheet();
    NAME_UPDATE;
}

void g_DestructGroupItem(QGraphicsItemGroup* groupItem, QGraphicsScene* scene)
{


    foreach (QGraphicsItem *item, groupItem->childItems())
    {
        groupItem->removeFromGroup(item);
        //scene->addItem(item);

        item->setSelected(true);
    }
    scene->removeItem(groupItem);
    NAME_UPDATE;
}

EditGroupItemCommand::EditGroupItemCommand( QGraphicsScene* scene, QUndoCommand* parent )
    : QUndoCommand(parent)
{
    m_scene = scene;
    m_childItems = ((CGraphScene*)scene)->Items(true,true);
    m_groupItem = ItemCreator::CreateSpecifyItem<CGroupItem>();
    setText(QString("group %1 items").arg(m_childItems.size()));
    ((CDesignerScene*)m_scene)->SetModified(true);
}

void EditGroupItemCommand::undo()
{
    g_DestructGroupItem(m_groupItem, m_scene);
}


void EditGroupItemCommand::redo()
{
    g_ConstructGroupItem(m_groupItem, m_scene, m_childItems);
}


EditIconItemCommand::EditIconItemCommand(const QStringList& IconInfo,const QPixmap icon, QGraphicsScene* scene, QUndoCommand* parent)
    :QUndoCommand(parent),m_IconInfo(IconInfo),m_Icon(icon)
{
    m_scene = scene;
    m_childItems = scene->selectedItems();
    m_groupItem = ItemCreator::CreateSpecifyItem<CIconItem>();
    setText(QString("group %1 items").arg(m_childItems.size()));
    ((CDesignerScene*)m_scene)->SetModified(true);
}

void EditIconItemCommand::undo()
{
    UnqItemMng()->RemoveItem(m_IconInfo);
    UnqIconMng()->DelIcon(m_IconInfo[0]);

    g_dataPtr(m_groupItem)->SetName(m_grpName);
    g_DestructGroupItem(m_groupItem, m_scene);
}

void EditIconItemCommand::redo()
{
    QString iconName=UnqIconMng()->GetRegIconName(m_IconInfo[0]);
    QString iconType=m_IconInfo[1];

    CIconData*pdata= (CIconData*)g_dataPtr(m_groupItem) ;
    pdata->SetTemplateName(iconName);
    g_ConstructGroupItem(m_groupItem, m_scene, m_childItems);

    m_grpName = pdata->GetName();
    pdata->SetName(iconName);

    UnqIconMng()->AddIcon(m_groupItem,iconName);
	UnqItemMng()->InsertItem(m_IconInfo[0], iconType, iconType);
}

EditUnIconItemCommand::EditUnIconItemCommand(QGraphicsScene* scene, QUndoCommand* parent):QUndoCommand(parent)
{
    m_scene = scene;
    Q_ASSERT( 1 == m_scene->selectedItems().size() );
    m_IconItem = dynamic_cast<CIconItem*>(m_scene->selectedItems()[0]);
    m_childItems = m_IconItem->childItems();
    Q_ASSERT(m_IconItem);
    ((CDesignerScene*)m_scene)->SetModified(true);
}
void EditUnIconItemCommand::undo()
{
    g_ConstructGroupItem(m_IconItem,m_scene,m_childItems);
}
void EditUnIconItemCommand::redo()
{
    g_DestructGroupItem(m_IconItem,m_scene);
}

EditUnGroupItemCommand::EditUnGroupItemCommand( QGraphicsScene* scene, QGraphicsItemGroup* item, QUndoCommand* parent )
    : QUndoCommand(parent)
{
    m_scene = scene;
    m_groupItem = item;
    m_childItems = m_groupItem->childItems();
    setText(QString("ungroup items with %1 children").arg(m_childItems.size()));
    ((CDesignerScene*)m_scene)->SetModified(true);
}

void EditUnGroupItemCommand::undo()
{
    g_ConstructGroupItem(m_groupItem, m_scene, m_childItems);
}

void EditUnGroupItemCommand::redo()
{
    g_DestructGroupItem(m_groupItem, m_scene);
}

MoveItemCommand::MoveItemCommand( QGraphicsScene* scene, const QList<UndoStru<QPointF> >& cmdStruList, QUndoCommand* parent)
    : HandleMultiItemsCommand<UndoStru<QPointF> >(scene, cmdStruList, parent)
{
    //qDebug("MoveItemCommand create");
    setText(QString("Move %1 items").arg(m_struList.size()));
    ((CDesignerScene*)m_scene)->SetModified(true);
}

void MoveItemCommand::undo()
{
    foreach(const UndoStru<QPointF>& stru, m_struList)
    {
		stru.item->setPos(stru.oldValue);
    }
    m_scene->update();
}
void MoveItemCommand::redo()
{
    foreach(const UndoStru<QPointF>& stru, m_struList)
    {
		stru.item->setPos(stru.newValue);

    }
    m_scene->update();
}


EditTransformItemCommand::EditTransformItemCommand(QGraphicsScene* scene, const QList<UndoStru<QTransform> >& transformList, QUndoCommand* parent)
    : HandleMultiItemsCommand<UndoStru<QTransform> >(scene, transformList, parent)
{
    setText(QString("edit %1 items transformation").arg(transformList.size()));
    ((CDesignerScene*)m_scene)->SetModified(true);
}

void EditTransformItemCommand::undo()
{
    foreach(const UndoStru<QTransform>& stru, m_struList)
    {
        stru.item->setTransform(stru.oldValue);
    }
    m_scene->update();
}

void EditTransformItemCommand::redo()
{
    foreach(const UndoStru<QTransform>& stru, m_struList)
    {
        stru.item->setTransform(stru.newValue);
    }
    m_scene->update();
}
//
EditRotateItemCommand::EditRotateItemCommand( QGraphicsItem* item, qreal lastAngle, qreal swapAngle, QUndoCommand* parent)
    : EditOneItemCommand<QGraphicsItem, qreal>(item, lastAngle, parent)
{
    m_newValue = m_oldValue + swapAngle;
    setText(QString("item rotation,  %1+%2=%3 in dgree").arg(lastAngle, 0, 'f', 1)
            .arg(swapAngle, 0, 'f', 1)
            .arg(lastAngle+swapAngle, 0, 'f', 1));
    ((CDesignerScene*)(item->scene()))->SetModified(true);
}

void EditRotateItemCommand::undo()
{
    RotateItem(m_item, m_oldValue);
}

void EditRotateItemCommand::redo()
{
    RotateItem(m_item, m_newValue);
}

void EditRotateItemCommand::RotateItem( QGraphicsItem* item, qreal angle )
{
    const QRectF rectF = item->boundingRect();
    CBaseData* pdata = g_dataPtr(item);
    const QPointF center = rectF.center();

    CBaseData::ApplyScaleProperty(item, angle,
                                  pdata->GetOrgScaleX(), pdata->GetOrgScaleY(),
								  center, (Qt::Axis)pdata->GetRotateAxis());
}

EditTransformItemScaleCommand::EditTransformItemScaleCommand( QGraphicsItem* item, const QTransform& oldTransform, QUndoCommand* parent )
    : EditOneItemCommand<QGraphicsItem, QTransform>(item, oldTransform, parent)
{
    setText("Edit item transformation");
    m_newValue = item->transform();
    ((CDesignerScene*)(item->scene()))->SetModified(true);
}

void EditTransformItemScaleCommand::undo()
{
    m_item->setTransform(m_oldValue, false);
}

void EditTransformItemScaleCommand::redo()
{
    m_item->setTransform(m_newValue, false);
}


EditLevelItemCommand::EditLevelItemCommand( QGraphicsScene* scene, QGraphicsItem* item, qreal newValue, QUndoCommand* parent )
    : EditOneItemCommand<QGraphicsItem, qreal>(item, item->zValue(), parent)
{
    m_newValue = newValue;
    setText(QString("edit level ")+(m_oldValue>m_newValue ? QString("down") : QString("up")));
    ((CDesignerScene*)(item->scene()))->SetModified(true);
}

void EditLevelItemCommand::undo()
{
    m_item->setZValue(m_oldValue);
}

void EditLevelItemCommand::redo()
{
    m_item->setZValue(m_newValue);
}

EditLevelMultiItemCommand::EditLevelMultiItemCommand( QGraphicsScene* scene, const QList<UndoStru<qreal> >& cmdStruList, QUndoCommand* parent )
    : HandleMultiItemsCommand<UndoStru<qreal > >(scene, cmdStruList, parent)
{
    if(scene) ((CDesignerScene*)scene)->SetModified(true);
    setText(QString("edit multi level %1 items").arg(cmdStruList.size()));
}

void EditLevelMultiItemCommand::undo()
{
    foreach(const UndoStru<qreal>& stru,  m_struList)
    {
        stru.item->setZValue(stru.oldValue);
    }
}

void EditLevelMultiItemCommand::redo()
{
    foreach(const UndoStru<qreal>& stru,  m_struList)
    {
        stru.item->setZValue(stru.newValue);
    }
}
//
EditLinkLineItemCommand::EditLinkLineItemCommand( CLinkLineItem* item, const LinkUndoValue& oldValue, QUndoCommand* parent)
    : EditOneItemCommand<CLinkLineItem, LinkUndoValue>(item, oldValue, parent)
{

    m_newValue.poly = item->polygon();
	m_newValue.headItem = dynamic_cast<CPinItem*>(item->GetHintItemArray()[0]);// HeadPinItem());
	m_newValue.tailItem = dynamic_cast<CPinItem*>(item->GetHintItemArray()[1]); //item->TailPinItem());
    setText(QString("edit a linkLine~"));
    ((CDesignerScene*)(item->scene()))->SetModified(true);
}

void EditLinkLineItemCommand::undo()
{
    m_item->setPolygon(m_oldValue.poly);
    m_item->SetLink(m_oldValue.headItem, true);
    m_item->SetLink(m_oldValue.tailItem, false);

}

void EditLinkLineItemCommand::redo()
{
    m_item->setPolygon(m_newValue.poly);
    m_item->SetLink(m_newValue.headItem, true);
    m_item->SetLink(m_newValue.tailItem, false);
}


AddLinkLineItemCommand::AddLinkLineItemCommand( CLinkLineItem* item, QUndoCommand* parent )
    : QUndoCommand(parent), m_item(item)
{
    m_scene = m_item->scene();
	m_headPinItem = dynamic_cast<CPinItem*>(m_item->GetHintItemArray()[0]); //HeadPinItem());
	m_tailPinItem = dynamic_cast<CPinItem*>(m_item->GetHintItemArray()[1]); //TailPinItem());
    setText("add a linkline item~~~");
	if (m_scene)
	((CDesignerScene*)m_scene)->SetModified(true);
}

void AddLinkLineItemCommand::undo()
{
    m_item->DelLink(m_headPinItem);
    m_item->DelLink(m_tailPinItem);
    m_scene->removeItem(m_item);
    NAME_UPDATE;
}

void AddLinkLineItemCommand::redo()
{
    if(m_item->scene() != m_scene)
        m_scene->addItem(m_item);

    m_item->SetLink(m_headPinItem, m_tailPinItem);
    NAME_UPDATE;
}

LinkLineHintLinkLineItemCommand::LinkLineHintLinkLineItemCommand( CLinkLineItem* editItem, CLinkLineItem* hintItem, const QPolygonF& editOldShape, int activeId, const QPointF& hintScenePos, const QPolygonF& section1, const QPolygonF& section2, QUndoCommand* parent)
    : QUndoCommand(parent),
      m_editItem(editItem),
      m_hintItem(hintItem),
      m_editOldShape(editOldShape),
      m_editId(activeId),
      m_hintScenePos(hintScenePos),
      m_section1(section1),
      m_section2(section2),
      m_addPinItem(NULL),
      m_addLinkItem(NULL)
{
    m_addPinItem = ItemCreator::CreateSpecifyItem<CPinItem>();
    m_addLinkItem = ItemCreator::CreateSpecifyItem<CLinkLineItem>();
    m_editNewShape = m_editItem->polygon();
    if(m_editId == 0)
        m_editNewShape.first() = m_editItem->mapFromScene(hintScenePos);
    else
        m_editNewShape.last() = m_editItem->mapFromScene(hintScenePos);

    m_hintOldShape = m_hintItem->polygon();
    m_editOldHeadItem = m_editItem->HeadPinItem();
    m_editOldTailItem = m_editItem->TailPinItem();

    m_hintOldHeadItem = m_hintItem->HeadPinItem();
    m_hintOldTailItem = m_hintItem->TailPinItem();
    setText(QString("linkLine hint a linkLine~"));
    ((CDesignerScene*)(editItem->scene()))->SetModified(true);
}

LinkLineHintLinkLineItemCommand::LinkLineHintLinkLineItemCommand( CLinkLineItem* editItem, CLinkLineItem* hintItem, const QPointF& hintScenePos, const QPolygonF& section1, const QPolygonF& section2, QUndoCommand* parent)
    : QUndoCommand(parent),
      m_editItem(editItem),
      m_hintItem(hintItem),
      m_hintScenePos(hintScenePos),
      m_section1(section1),
      m_section2(section2),
      m_addPinItem(NULL),
      m_addLinkItem(NULL)
{
    m_addPinItem = ItemCreator::CreateSpecifyItem<CPinItem>();
    //m_addLinkItem = ItemCreator::CreateSpecifyItem<CLinkLineItem>();
    m_addLinkItem = (CLinkLineItem*)(g_dataPtr(m_editItem)->Clone());
	if (CBaseData* pdata = g_dataPtr(m_addLinkItem))
		pdata->SetName(UnqNameMng()->ItemGetName(m_addLinkItem));

    m_editNewShape = m_editItem->polygon();
    m_editNewShape.last() = m_editItem->mapFromScene(hintScenePos);

    m_editOldShape.clear();
    m_hintOldShape = m_hintItem->polygon();
    m_editId = m_hintOldShape.size()-1;
    m_hintOldHeadItem = m_hintItem->HeadPinItem();
    m_hintOldTailItem = m_hintItem->TailPinItem();
	m_editOldHeadItem=NULL;
	m_editOldTailItem=NULL;
    setText(QString("insert a linkLine~"));
    ((CDesignerScene*)(editItem->scene()))->SetModified(true);
}
void LinkLineHintLinkLineItemCommand::undo()
{
    QGraphicsScene* s = m_editItem->scene();

    s->removeItem(m_addPinItem);
    s->removeItem(m_addLinkItem);
    m_hintItem->setPolygon(m_hintOldShape);
    m_hintItem->SetLink(m_hintOldHeadItem, m_hintOldTailItem);

    if(!m_editOldShape.empty())
    {
        m_editItem->setPolygon(m_editOldShape);
        m_editItem->SetLink(m_editOldHeadItem, m_editOldTailItem);
    }
    NAME_UPDATE;
}

void LinkLineHintLinkLineItemCommand::redo()
{
    QGraphicsScene* s = m_editItem->scene();

    s->addItem(m_addLinkItem);
    m_addLinkItem->setTransform(m_hintItem->transform());
    m_addLinkItem->setPos(m_hintItem->pos());
    m_addLinkItem->setPolygon(m_section2);
    m_hintItem->PassLink(false, m_addLinkItem, false);
    
    m_hintItem->setPolygon(m_section1);
    m_editItem->setPolygon(m_editNewShape);

    s->addItem(m_addPinItem);
    m_addPinItem->setPos(m_hintScenePos);
    m_addPinItem->FreshPos();

    m_addPinItem->AddLink(m_editItem, QPointF());
    m_editItem->SetLink(m_addPinItem, m_editId==0);

    NAME_UPDATE;
}

LinkLineHintLinkLineItemJoinCommand::LinkLineHintLinkLineItemJoinCommand(CLinkLineItem* editItem,bool isHead,CLinkLineItem* hintItem, bool isHintItemHead,QUndoCommand* parent )
    : QUndoCommand(parent),m_editItem(editItem), m_hintItem(hintItem),m_isHead(isHead),m_isHintHead(isHintItemHead)
{
    m_addPinItem = ItemCreator::CreateSpecifyItem<CPinItem>();
    m_editNewShape = m_editItem->polygon();

    m_editOldShape.clear();
    m_hintOldShape = m_hintItem->polygon();
    m_hintOldHeadItem = m_hintItem->HeadPinItem();
    m_hintOldTailItem = m_hintItem->TailPinItem();
	m_editOldHeadItem=NULL;
	m_editOldTailItem=NULL;
    setText(QString("insert a linkLine~"));
    ((CDesignerScene*)(editItem->scene()))->SetModified(true);
}
void LinkLineHintLinkLineItemJoinCommand::undo()
{
    QGraphicsScene* s = m_editItem->scene();
    s->removeItem(m_addPinItem);

    m_hintItem->SetLink(m_hintOldHeadItem, m_hintOldTailItem);
    if(!m_editOldShape.empty())
    {
        m_editItem->setPolygon(m_editOldShape);
        m_editItem->SetLink(m_editOldHeadItem, m_editOldTailItem);
    }
    NAME_UPDATE;
}

void LinkLineHintLinkLineItemJoinCommand::redo()
{
    QGraphicsScene* s = m_editItem->scene();
    QPointF pos=m_isHintHead ? m_hintItem->polygon().first(): m_hintItem->polygon().last();
    pos=m_hintItem->mapToScene(pos);
    m_editItem->setPolygon(m_editNewShape);

    s->addItem(m_addPinItem);
    m_addPinItem->setPos(pos);
    m_addPinItem->FreshPos();
    m_addPinItem->AddLink(m_editItem, QPointF());
    m_addPinItem->AddLink(m_hintItem, QPointF());
    m_hintItem->SetLink(m_addPinItem, m_isHintHead);
    m_editItem->SetLink(m_addPinItem, m_isHead);

    NAME_UPDATE;
}


IconItemHintLinkLineItemCommand::IconItemHintLinkLineItemCommand( CIconItem* editItem,CLinkLineItem* hintItem, const QPointF& hintScenePos, const QPolygonF& section1, const QPolygonF& section2, QUndoCommand* parent)
    : QUndoCommand(parent), m_editItem(editItem),m_hintItem(hintItem),m_hintScenePos(hintScenePos),m_section1(section1),m_section2(section2),m_addLinkItem(NULL)
{
    m_addLinkItem = ItemCreator::CreateSpecifyItem<CLinkLineItem>();
    m_editOldShape.clear();
    m_hintOldShape = m_hintItem->polygon();
    m_editId = m_hintOldShape.size()-1;
    m_hintOldHeadItem = m_hintItem->HeadPinItem();
    m_hintOldTailItem = m_hintItem->TailPinItem();
	m_editOldHeadItem=NULL;
	m_editOldTailItem=NULL;
    ((CDesignerScene*)(hintItem->scene()))->SetModified(true);
}
void IconItemHintLinkLineItemCommand::undo()
{
    QGraphicsScene* s = m_hintItem->scene();
    s->removeItem(m_addLinkItem);
    m_hintItem->setPolygon(m_hintOldShape);
    m_hintItem->SetLink(m_hintOldHeadItem, m_hintOldTailItem);

    if(!m_editOldShape.empty())
    {


    }
    NAME_UPDATE;
}

void IconItemHintLinkLineItemCommand::redo()
{
    QVector<CPinItem* > pins;
    foreach(QGraphicsItem* item,m_editItem->childItems())
    {
        if(item->type()==Hmi::Pin)
        {
            pins.push_back((CPinItem* )item);
        }
    }
    if(pins.size()<2) return;
    CPinItem* pin1,*pin2;
    QPointF p1=pins[0]->mapToScene(0,0);
    pin1= (QLineF(p1,m_section1.last()).length()<QLineF(p1,m_section2.first()).length())?pins[0]:pins[1];
    pin2= (pin1==pins[0])?pins[1]:pins[0];

    QGraphicsScene* s = m_hintItem->scene();

    s->addItem(m_addLinkItem);
    m_addLinkItem->setPolygon(m_section2);
    m_addLinkItem->setTransform(m_hintItem->transform());
    m_addLinkItem->setPos(m_hintItem->pos());
    m_addLinkItem->SetLink(pin2, true);	
	m_addLinkItem->SetLink(m_hintItem->TailPinItem(), false);

    m_hintItem->setPolygon(m_section1);
    m_hintItem->SetLink(pin1, false);

	QPointF pinCenter = QLineF(pin1->pos(), pin2->pos()).pointAt(0.5);
	pinCenter = m_editItem->mapToScene(pinCenter);
	QPointF dp = (m_hintScenePos - pinCenter);
	m_editItem->moveBy(dp.x(), dp.y());
	

    NAME_UPDATE;
}
