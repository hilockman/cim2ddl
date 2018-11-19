

#include "Mdi.h"
#include "DesignerScene.h"
#include "DesignerWnd.h"

CDesignerScene* Mdi::m_scene = NULL;
CDesignerWnd* Mdi::m_wnd = NULL;
QMap<Mdi*, QString> Mdi::m_instanceMap;

CDesignerScene* Mdi::CurrentScene()
{
	m_scene = NULL;
    if(m_wnd)
        m_scene=m_wnd->ActiveScene();
    return m_scene;
}

QUndoStack* Mdi::CurrentUndoStack()
{
    if(m_scene)
        return m_scene->GetUndoStack();
    else
        return NULL;
}


void Mdi::OnSceneActived( CDesignerScene* scene )
{
    //qDebug("In Mdi::OnSceneActived, scene: %p, m_scene: %p", scene, m_scene);
    if(scene==NULL)
        return;

    if(scene == m_scene)
        return;
    m_scene = scene;
    QMapIterator<Mdi*, QString> it(m_instanceMap);
    while(it.hasNext())
    {
        it.next();

        it.key()->OnSwitchScene();
    }
}

QGraphicsView* Mdi::CurrentView()
{
    return (QGraphicsView *)(m_wnd->ActiveView());






}
