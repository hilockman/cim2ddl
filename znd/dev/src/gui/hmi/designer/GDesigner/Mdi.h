

#ifndef MDI_H
#define MDI_H 

#include <QMap>

class CDesignerWnd;
class CDesignerScene;
class QGraphicsScene;
class QGraphicsView;

class QUndoStack;

class Mdi
{
public:
    static void SetWnd(CDesignerWnd* wnd) {m_wnd = wnd;};
    static void OnSceneActived(CDesignerScene* scene);
    static CDesignerWnd* CurrentWnd() { return m_wnd;};

protected:
    Mdi(const QString& name) {m_instanceMap.insert(this, name);};
    static CDesignerScene* CurrentScene();
    static QGraphicsView* CurrentView();
    static QUndoStack* CurrentUndoStack();
    void SceneVerify() const {Q_ASSERT(CurrentScene());};

    virtual void OnSwitchScene() = 0;

private:
    static CDesignerWnd* m_wnd;
    static CDesignerScene* m_scene;
    static QMap<Mdi*, QString> m_instanceMap;
};

#endif
