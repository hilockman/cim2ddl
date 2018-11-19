

#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H 

#include "Mdi.h"

class QColor;
class QFont;
class QGraphicsItem;
class QGraphicsScene;
class CIconItem;

class ItemCreator : public Mdi
{
public:
    static QGraphicsItem* CreateItem(int type, QGraphicsItem* parent=0, QGraphicsScene* scene=0);
    static QGraphicsItem* CreateItem(const QString& itemName, QGraphicsItem* parent=0, QGraphicsScene* scene=0);
    static CIconItem* CreateIconFromIconMap(const QString& itemName, QGraphicsItem* parent=0, QGraphicsScene* scene=0);
    static void SetDefaultTextColor(const QColor& c);
    static void SetDefaultFillColor(const QColor& c);
    static void SetDefaultLineColor(const QColor& c);
    static void SetDefaultFont(const QFont& f);
    static void GlobalSet(QGraphicsItem* item,bool withdeFaultColor=true );

    template<typename CItem> static CItem * CreateSpecifyItem()
    {
        CItem* item = new CItem;
        GlobalSet(item);
        return item;
    };

private:
    static QColor s_defaultTextColor;
    static QColor s_defaultLineColor;
    static QColor s_defaultFillColor;
    static QFont s_defaultFont;
};


#endif
