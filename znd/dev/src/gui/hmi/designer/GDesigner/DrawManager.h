

#ifndef CDRAWMANAGER_H
#define CDRAWMANAGER_H 

#include <QtCore/QObject>
#include <QtCore/QHash>
#include "Mdi.h"

class CLineDrawTool;
class CPolygonDrawTool;
class IDrawTool;
class QGraphicsItem;
class QPointF;
class QGraphicsScene;
class QKeyEvent;
class QGraphicsSceneMouseEvent;
class QUndoStack;

class CDrawManager : public Mdi
{

    friend CDrawManager* UnqDrawMng();
    friend class CDesignerScene;
public:
    enum SceneMode { InsertItem, MoveItem, EditItem, RotateItem, AddItemPoint, DelItemPoint };
    CDrawManager();
    ~CDrawManager();


    bool IsMoveMode() const {return m_currentMode == MoveItem;};
    void OnChangeCreateType(const QString& typeName);
    virtual void OnSwitchScene();
    IDrawTool* CurrentDrawTool(){return m_currentTool;};
    QGraphicsItem* CurrentDrawItem(){return m_currentItem;};


    void SwitchMode(SceneMode mode, bool isRevoked=false);// true means finish drawtool
    bool MousePressEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent* e);
    bool MousePress(QGraphicsScene* scene, int pressBtn, const QPointF& scenePoint );
    bool MouseMoveEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent* e);
    bool MouseReleaseEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent *e);
	bool contextMenuEvent(QGraphicsView* scene, QContextMenuEvent * e);
    bool KeyPressEvent( QGraphicsScene* scene, QKeyEvent* e);
    bool KeyReleaseEvent( QGraphicsScene* scene, QKeyEvent* e);
    bool MouseDoubleClickEvent(QGraphicsScene* scene, QGraphicsSceneMouseEvent* e);
    void OnSelectionChanged(const QList<QGraphicsItem*>& itemList);
    void SetRotate() {m_isRotate = true;};
    void OnMouseMoveResizing(const QPointF& pointF);
    void OnMouseMoveInitDrawing(const QPointF& pointF);
    bool OnMouseMoveMouseHint(const QPointF& pointF);

    bool Finish(const QPointF& scenePos);
private:
    QHash<int, IDrawTool*> m_drawToolHash;
    IDrawTool* m_currentTool;
    QGraphicsItem* m_currentItem;
    SceneMode m_currentMode;
    QString m_createTypeName;
    bool m_isRotate;


};


CDrawManager* UnqDrawMng();

#endif
