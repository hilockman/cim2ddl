

#include <qglobal.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include "DrawManager.h"
#include "CursorManager.h"
#include "DrawTool.h"
#include "ItemFactory.h"
#include "DesignerScene.h"
#include "DesignerWnd.h"
#include "CGrid.h"
CDrawManager::CDrawManager() : Mdi("drawManager"), m_drawToolHash(),
    m_isRotate(false),
    m_currentMode(MoveItem),
    m_currentTool(NULL),
    m_currentItem(NULL)
{
    IDrawTool::InitThis(m_drawToolHash, CurrentUndoStack());
}


void CDrawManager::OnSwitchScene()
{
    CDesignerScene* scene = (CDesignerScene*)CurrentScene();
    if(!scene)
        return;
    OnSelectionChanged(scene->Items(true,true));
    IDrawTool::SetUndoStack(CurrentUndoStack());
    UnqCursorMng()->SetCursor(m_currentMode,m_createTypeName);
}

CDrawManager::~CDrawManager()
{
    QHashIterator<int, IDrawTool*> it(m_drawToolHash);
    QSet<IDrawTool*> toolSet;
    while(it.hasNext())
    {
        it.next();
        IDrawTool* tool = it.value();
        if(toolSet.contains(tool))
            continue;

        toolSet<<tool;
        delete tool;
    }
}


void CDrawManager::OnChangeCreateType(const QString& typeName)
{
    if(!CurrentScene())
        return;

    int tp = ItemFactory::ItemType(typeName);

    Q_ASSERT(m_drawToolHash.contains(tp));

    m_createTypeName = typeName;
    SwitchMode(InsertItem);
    m_currentTool = m_drawToolHash[tp];

}

void CDrawManager::SwitchMode( SceneMode targetMode, bool isRevoked )
{
    UnqCursorMng()->SetCursor(targetMode,m_createTypeName);
    QGraphicsScene* scene = CurrentScene();
    if(InsertItem == targetMode)
    {
        if(EditItem == m_currentMode && m_currentTool)
        {
            m_currentTool->Revoke();
        }
        else if(InsertItem == m_currentMode)
        {
            scene->removeItem(m_currentItem);
        }
        m_currentItem = NULL;
        scene->clearSelection();
    }
    else if(EditItem == targetMode || RotateItem == targetMode)
    {
        Q_ASSERT(MoveItem == m_currentMode);
        m_currentItem->setSelected(true);

    }
    else if(MoveItem == targetMode )
    {
        if(isRevoked)
        {
			if (m_currentTool)
			{
				//m_currentTool->Revoke();
				m_currentTool->Reset();
			}
			if (scene)
                scene->clearSelection();
        }
        else if(m_currentTool)
        {
            if(RotateItem == m_currentMode)
                m_currentTool->RotateFinish();
            else if(EditItem == m_currentMode)
                m_currentTool->EditFinish();
            else if(InsertItem == m_currentMode)
            {
                m_currentTool->InsertFinish();
                if (m_currentItem) m_currentItem->setSelected(true);
                if (CurrentWnd()->getBePatchCreate())
                {
                    int createNum = CurrentWnd()->getPatchCreateNum();
                    if (createNum>1 && m_currentItem)
                    {
                        m_currentItem->setSelected(true);
                        this->CurrentScene()->OnEditCopy();

                        for (int r = 0; r < createNum-1; r++)
                        {
                            CurrentScene()->OnEditPaste();
                        }
                    }
                }
                m_createTypeName.clear();
            }
        }
    }
#if 0
    else if(AddItemPoint == targetMode || MoveItem == m_currentMode)
    {
        m_currentMode = AddItemPoint;
    }
    else if(DelItemPoint == targetMode || MoveItem == m_currentMode)
    {
        m_currentMode = DelItemPoint;
    }
#endif

    m_currentMode = targetMode;
}

void CDrawManager::OnMouseMoveResizing( const QPointF& pointF)
{
    if(m_currentItem && m_currentTool && m_currentTool->IsLastItem(m_currentItem))
    {
        m_currentItem->setSelected(true);
        m_currentTool->EditDrawing(pointF);
    }
}

bool CDrawManager::OnMouseMoveMouseHint(const QPointF& pointF )
{
    if(m_currentItem && m_currentTool)
    {
        m_currentTool->SetItem(m_currentItem);
        return m_currentTool->MouseHint(pointF);
    }

    return false;
}

void CDrawManager::OnMouseMoveInitDrawing( const QPointF& pointF )
{
    if(m_currentTool) m_currentTool->InsertDrawing(pointF);
}

bool CDrawManager::MousePressEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent* e )
{
    return MousePress( scene,e->button(),e->scenePos() );
}

bool CDrawManager::MousePress(QGraphicsScene* scene, int pressBtn, const QPointF& scenePoint )
{
    QPointF catchpt=scenePoint;
    UnqGrid()->GetCatchPoint(catchpt);


    if (pressBtn == Qt::LeftButton)
    {
        if(MoveItem == m_currentMode) ////旋转操作////
        {
            if(scene->selectedItems().size()==1 && OnMouseMoveMouseHint(scenePoint))
            {
                SwitchMode(m_isRotate? RotateItem : EditItem);
                m_isRotate = false;
                return false;
            }
            return true;
        }
        else if(InsertItem == m_currentMode)
        {
            if(!m_currentTool) return false;
            if(m_currentItem)
            {
                if(m_currentTool->OnInsertDrawingClicked(catchpt))
                    SwitchMode(MoveItem);
            }
            else
            {
                m_currentItem = m_currentTool->CreateItem(scene, m_createTypeName, catchpt);
                if (m_currentItem && m_currentTool->GetClickEditMode() == IDrawTool::SingleClickMode)
                {
					SwitchMode(MoveItem);
                    m_currentItem->setSelected(true);
                    //m_currentItem =0;//????? caih delete
                }
            }
            return false;
        }
        else if(EditItem == m_currentMode)
        {
            SwitchMode(MoveItem);
            return false;
        }
        else if(RotateItem == m_currentMode)
        {
            SwitchMode(MoveItem);
            return false;
        }
        else if(DelItemPoint == m_currentMode)
        {
            if(scene->selectedItems().size()==1 && OnMouseMoveMouseHint(scenePoint))
            {
                if(CAbstractPathDrawTool* pathDrawTool = dynamic_cast<CAbstractPathDrawTool*>(m_currentTool))
                {
                    pathDrawTool->DelPoint();
                }
                else if(CPolygonDrawTool* polygonDrawTool = dynamic_cast<CPolygonDrawTool*>(m_currentTool))
                {
                    polygonDrawTool->DelPoint();
                }
            }
            SwitchMode(MoveItem);
            return false;
        }
        else if(AddItemPoint == m_currentMode)
        {
            if(scene->selectedItems().size()==1)
            {
                if(CAbstractPathDrawTool* pathDrawTool = dynamic_cast<CAbstractPathDrawTool*>(m_currentTool))
                {
                    pathDrawTool->AddPoint(catchpt);
                }
                else if(CPolygonDrawTool* polygonDrawTool = dynamic_cast<CPolygonDrawTool*>(m_currentTool))
                {
                    polygonDrawTool->AddPoint(catchpt);
                }
            }
            SwitchMode(MoveItem);
            return false;
        }

    }
    else if(pressBtn == Qt::MidButton)
    {

    }

    return true;
}

bool CDrawManager::contextMenuEvent(QGraphicsView* view, QContextMenuEvent * e)
{
	if (MoveItem == m_currentMode || !m_currentTool)
		return true;
	else if (InsertItem == m_currentMode)
	{
        /*if(m_currentTool){
            bool ret=m_currentTool->OnInsertDrawingDoubleClicked(view->mapToScene(e->pos()));
            if (!ret){
                SwitchMode(InsertItem);
                return false;
            }
        }
        SwitchMode(MoveItem,true); //true means finish drawtool,when contextMenu
        */
        Finish(view->mapToScene(e->pos()));
		if (m_currentItem)
		{
			m_currentItem->setFlag(QGraphicsItem::ItemIsSelectable, true);
			m_currentItem->setSelected(true);
		}
		return true;
	}
	else if (EditItem == m_currentMode)
	{
        SwitchMode(MoveItem, true); //true means finish drawtool
	}
	return false;
}

bool CDrawManager::MouseMoveEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent* e )
{
    QPointF pointF= e->scenePos();
    QPointF catchpt=pointF;
    UnqGrid()->GetCatchPoint(catchpt);
    if (m_currentMode == InsertItem && m_currentItem)
    {
        OnMouseMoveInitDrawing(catchpt);
        return false;
    }
    if(m_currentMode == EditItem)
    {
        OnMouseMoveResizing(catchpt);
        return false;
    }
    if(m_currentMode == RotateItem)
    {
        if(m_currentItem && m_currentTool )
        {
            m_currentTool->ApplyRotation(pointF);
            return false;
        }
    }
    else if (m_currentMode == MoveItem)
    {
        if (scene->selectedItems().size() == 1 && OnMouseMoveMouseHint(pointF))
			UnqCursorMng()->SetCursor(m_currentMode, m_createTypeName, CursorManager::EditPoint);
		else
			UnqCursorMng()->SetCursor(m_currentMode, m_createTypeName, CursorManager::OtherPos);
        
        return true;
    }
    else if(DelItemPoint == m_currentMode)
    {
        if(scene->selectedItems().size()==1 && OnMouseMoveMouseHint(pointF))
            UnqCursorMng()->SetCursor(m_currentMode,m_createTypeName,CursorManager::EditPoint);
        else
            UnqCursorMng()->SetCursor(m_currentMode,m_createTypeName,CursorManager::OtherPos);
        return true;
    }
    return true;

}

bool CDrawManager::MouseReleaseEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent *e)
{
    CDesignerScene* pScene = (CDesignerScene*)scene;
    QPointF pointF = e->scenePos();
    if (e->button() == Qt::LeftButton && m_currentMode == MoveItem)
    {
        if (pScene->Items(true,true).size() == 1)
        {
            if(m_currentTool) m_currentTool->MouseRelease(pointF);
        }
        else
        {
            QList<QGraphicsItem*> selItems = pScene->Items(true, true);
            for (int i = 0; i < selItems.size(); i++)
            {
                m_currentTool = m_drawToolHash[g_dataPtr(selItems[i])->Type()];
                if(m_currentTool){
                    m_currentTool->SetItem(selItems[i]);
                    m_currentTool->MouseRelease(pointF);
                }
            }
        }
    }
    return true;
}

bool CDrawManager::MouseDoubleClickEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent* e )
{
    Finish(e->scenePos());

    if(e->button() != Qt::LeftButton)
        return true;

    return true;

}

bool CDrawManager::Finish(const QPointF& scenePos)
{
    if(m_currentTool){
        bool ret=m_currentTool->OnInsertDrawingDoubleClicked(scenePos);
        SwitchMode(MoveItem,true);
    }
    return true;
}

void CDrawManager::OnSelectionChanged(const QList<QGraphicsItem*>& itemList)
{
    if(MoveItem != m_currentMode)
        return;

    if(itemList.size()==1)
    {
        m_currentItem = itemList.first();
        int type = g_dataPtr(m_currentItem)->Type();
        Q_ASSERT(m_currentItem && m_drawToolHash.contains(type));
        m_currentTool = m_drawToolHash[type];
        m_currentTool->SetItem(m_currentItem);
    }
    else
    {
        m_currentItem = NULL;
        m_currentTool = NULL;
    }
}

static bool sg_isShiftPressed = false;
bool CDrawManager::KeyPressEvent(QGraphicsScene* , QKeyEvent* e )
{
    if(e->key() == Qt::Key_Shift)
    {
        sg_isShiftPressed = true;
        IDrawTool::SwitchHvLockFlag();
    }

    return true;
}

bool CDrawManager::KeyReleaseEvent(QGraphicsScene*, QKeyEvent* e )
{
    switch(e->key())
    {
    case Qt::Key_Shift:
        if(sg_isShiftPressed)
        {
            sg_isShiftPressed = false;
            IDrawTool::SwitchHvLockFlag();
        }
        break;
    case Qt::Key_Escape:
        SwitchMode(MoveItem,true);
        break;
    default:
        return true;
    }

    return true;

}



CDrawManager* UnqDrawMng()
{
    static CDrawManager _instance;
    return &_instance;
}
