

#include <QtGui/QColor>
#include <QtGui/QFont>
#include "ItemCreator.h"
#include "ItemFactory.h"
#include "NameManager.h"
#include "Mdi.h"
#include "BaseData.h"
#include "DesignerScene.h"
#include "DesignerView.h"
#include "IconMng.h"
#include "WidgetItem.h"

QColor ItemCreator::s_defaultTextColor = Qt::black;
QColor ItemCreator::s_defaultLineColor = Qt::black;
QColor ItemCreator::s_defaultFillColor = Qt::black;
QFont ItemCreator::s_defaultFont = QFont("Arial", 12, QFont::Normal);

void ItemCreator::SetDefaultTextColor(const QColor& c) {s_defaultTextColor = c;};
void ItemCreator::SetDefaultFillColor(const QColor& c) {s_defaultFillColor = c;};
void ItemCreator::SetDefaultLineColor(const QColor& c) {s_defaultLineColor = c;};
void ItemCreator::SetDefaultFont(const QFont& f) {s_defaultFont = f;};


QGraphicsItem* ItemCreator::CreateItem(int type, QGraphicsItem* parent, QGraphicsScene* scene)
{
    QGraphicsItem* item = ItemFactory::CreateItem(type, parent, scene);
    GlobalSet(item);

    return item;
}

QGraphicsItem* ItemCreator::CreateItem( const QString& itemName, QGraphicsItem* parent , QGraphicsScene* scene )
{
    QGraphicsItem* item = ItemFactory::CreateItem(itemName, parent, scene);
    GlobalSet(item);

    return item;
}

CIconItem* ItemCreator::CreateIconFromIconMap(const QString& itemName, QGraphicsItem* parent , QGraphicsScene* scene )
{
    CIconItem* item = UnqIconMng()->DupIcon(itemName,scene);
    GlobalSet(item,false);
    return item;
}
void ItemCreator::GlobalSet( QGraphicsItem* item,bool withdeFaultColor )
{
    CDesignerScene* pScene = CurrentScene();
    CBaseData* pdata = g_dataPtr(item);
    if(!pdata)
        return;
    if(withdeFaultColor)
    {
		if (item->type() == Hmi::Text)
		{
		    //if (s_defaultTextColor.isValid()) pdata->SetTextColor(s_defaultTextColor);//CanLine(text)==false
			if (s_defaultFillColor.isValid()) pdata->SetFillColor(s_defaultFillColor);
		}
		else{
			if (s_defaultLineColor.isValid()) pdata->SetLineColor(s_defaultLineColor);
			if (s_defaultFillColor.isValid()) pdata->SetFillColor(s_defaultFillColor);
		}
        pdata->SetFont(s_defaultFont);
        
    }

    if (dynamic_cast<CWidgetItem*>(item))
    {
        //((CWidgetItem*)item)->SetIgnoreEvent(true);
    }

	if (pScene)
	{
		pdata->SetPlane(pScene->GetCurPlane());
		pdata->SetState(0);
		pdata->SetName(UnqNameMng()->ItemGetName(item));
        bool isIconContainer=pdata->IsIconContainer();

        if(isIconContainer)/////如果是组合或间隔还需要设置每个子图元的名字/////
        {
            foreach (QGraphicsItem *subitem, item->childItems())
            {
                g_dataPtr(subitem)->SetName(UnqNameMng()->ItemGetName(subitem));
                g_dataPtr(subitem)->SetState(0);
                g_dataPtr(subitem)->SetPlane(pScene->GetCurPlane());
				if (subitem->type() == Hmi::Link)/////如果是组合或间隔还要更新连接关系//////////
					((CLinkLineItem*)subitem)->UpdateLoadedConnection();

            }
        }
        if (item->type() == Hmi::Link)
            ((CLinkLineItem* )item)->UpdateLoadedConnection();

        pScene->AppendItemIdx(item);
		emit((CDesignerView*)CurrentView())->ItemBeCreated(pdata);
	}
}

#if 0
QGraphicsItem* ItemCreator::CreateRawItem( int type, QGraphicsItem* parent , QGraphicsScene* scene )
{
    QGraphicsItem* item = CreateItem(type, parent, scene);
    GlobalSet(item);

    return item;
}

#endif
