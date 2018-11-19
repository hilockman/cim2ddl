

#include <QGraphicsView>
#include "CursorManager.h"



QMap<QString,QCursor> CursorManager::s_MapTpCursor = QMap<QString,QCursor>();
CursorManager* UnqCursorMng()
{
    static CursorManager* pCursorMng;
    return pCursorMng;
}
CursorManager::CursorManager():Mdi("CursorManager"){}

void CursorManager::InsertNewTp(const QString& name,const QCursor& cursor)
{
    s_MapTpCursor[name] = cursor;
}
void CursorManager::RemoveTp(const QString& name)
{
    s_MapTpCursor.remove(name);
}
void CursorManager::SetCursor(CDrawManager::SceneMode mode,const QString& ItemTypeName,int pos )
{
    QGraphicsView* curView = CurrentView();
    if (CDrawManager::InsertItem == mode)
    {
        if(curView && s_MapTpCursor.contains(ItemTypeName))
        {
            curView->setCursor(s_MapTpCursor[ItemTypeName]);
        }
    }
    else if (CDrawManager::EditItem == mode)
    {
        if(curView)
            curView->setCursor(Qt::CrossCursor);
    }
    else if (CDrawManager::MoveItem == mode)
    {
        if( !curView)
            return;
        if (EditPoint == pos)
            curView->setCursor(Qt::CrossCursor);
        else if(InShape == pos )
            curView->setCursor(Qt::PointingHandCursor);
        else
            curView->setCursor(Qt::ArrowCursor);
    }
    else
    {
        if(curView)
            curView->unsetCursor();
        return;
    }
}
QCursor CursorManager::MakeIconCrossCursor(const QPixmap& orgpix)
{
    QPixmap pix(CURSORSIZE,CURSORSIZE);
    pix.fill(Qt::transparent);
    QPainter paint(&pix);
    paint.drawPixmap(16,16,CURSORICONSIZE,CURSORICONSIZE,orgpix);

    paint.drawLine(QPointF(12,0),QPointF(12,24));
    paint.drawLine(QPointF(0,12),QPointF(24,12));
    QCursor cursor( pix,12,12);
    return cursor;
}
