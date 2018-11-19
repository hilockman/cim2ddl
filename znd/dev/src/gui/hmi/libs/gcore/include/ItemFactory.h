

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H 

#include "Export.h"
#include "Global.h"


class QGraphicsScene;
class QGraphicsItem;
class DLL_CLASS ItemFactory
{
public:
    ItemFactory(){};
    virtual ~ItemFactory(){};

    static QGraphicsItem* CreateItem(int tp, QGraphicsItem * parent = 0,QGraphicsScene * scene=0);
    static QGraphicsItem* CreateItem(const QString& itemName, QGraphicsItem * parent = 0,QGraphicsScene * scene=0);
    static QString ItemTypeName(int type);
    static QString ItemTypeSaveName(int type);
    static int ItemType(const QString& typeName);
    static const QMap<int,QString> TypeNameMap;
    static const QMap<int,QString> TypeSaveNameMap;
private:
    static QMap<int,QString> InitTypeName();
    static QMap<int,QString> InitTypeSaveName();

};







#endif
