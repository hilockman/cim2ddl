

#ifndef COMMANDS_H
#define COMMANDS_H 

#include <QUndoCommand>
#include <QPointF>
#include <QVector>
#include <QPolygonF>
class CGroupItem;
class QGraphicsScene;
class QGraphicsItem;
class QGraphicsPolygonItem;
class QGraphicsSvgItem;
class CLinkLineItem;
class CPinItem;
class CAbstractPathItem;
class CBusItem;
class CIconItem;

namespace CMD
{
enum CMD_ID
{
    AddShape=50,
    EditProperty,
    EditRotate=100 ,
    EditScale,
    EditShape,
    EditLineShape,
    EditRectShape,
    EditEllipseShape,
    EditPolygonShape,
    EditPathShape,
    EditLinkLineShape,
    EditWidgetShape,
    EditSvgShape
};
}



void g_ConstructGroupItem(QGraphicsItemGroup* groupItem, QGraphicsScene* scene, const QList<QGraphicsItem*>& childItemList);
void g_DestructGroupItem(QGraphicsItemGroup* groupItem, QGraphicsScene* scene);

template<typename TItem, typename TValue>
class EditOneItemCommand : public QUndoCommand
{
public:
    EditOneItemCommand(TItem* item, const TValue& oldValue, QUndoCommand* parent=0)
        :QUndoCommand(parent), m_item(item), m_oldValue(oldValue) {};
    const void* GetItem() const {return m_item;};

protected:
    TValue m_oldValue;
    TValue m_newValue;
    TItem* m_item;
};

template<typename TItem, typename TValue>
class SimpleShapeEditForItemCommand : public EditOneItemCommand<TItem, TValue>
{
public:
    typedef void (TItem::*_setValueFunc)(const TValue&);
    typedef TValue (TItem::*_getValueFunc)() const ;
    using EditOneItemCommand<TItem, TValue>::m_newValue;

    SimpleShapeEditForItemCommand(TItem* item,
                                  const TValue& oldValue,
                                  _setValueFunc setFunc,
                                  const TValue& newValue,
                                  const QString& text="Edit a item",
                                  QUndoCommand* parent=0)
        : EditOneItemCommand<TItem, TValue>(item, oldValue, parent), m_setFunc(setFunc)
    {
        m_newValue = newValue;
        setText(text);
    };
#if 0

    void undo () {(m_item->*m_setFunc)(m_oldValue);};
    void redo () {(m_item->*m_setFunc)(m_newValue);};
#endif

private:
    _setValueFunc m_setFunc;
};

template<typename TValue>
struct UndoStru
{
    UndoStru() : item(NULL), oldValue(), newValue() {};
    QGraphicsItem* item;
    TValue oldValue;
    TValue newValue;
};


template<typename TUndoStru>
class HandleMultiItemsCommand : public QUndoCommand
{
public:
    HandleMultiItemsCommand(QGraphicsScene* scene, const QList<TUndoStru>& itemsList, QUndoCommand* parent=0)
        :QUndoCommand(parent), m_scene(scene), m_struList(itemsList) {};

protected:
    QGraphicsScene* m_scene;
    QString m_itemName;
    QList<TUndoStru> m_struList;
};





class AddItemCommand : public QUndoCommand
{
public:
    AddItemCommand(QGraphicsItem* item, QUndoCommand* parent=0);
    int id() const {return CMD::AddShape;};
    void undo();
    void redo();
private:
    QGraphicsScene* m_scene;
    QGraphicsItem* m_item;
};

class PasteItemCommand : public HandleMultiItemsCommand<QGraphicsItem*>
{
public:
    PasteItemCommand(QGraphicsScene* scene, const QList<QGraphicsItem*>& itemsList, QUndoCommand* parent=0);
    void undo();
    void redo();
};


class DelItemCommand : public HandleMultiItemsCommand<QGraphicsItem*>
{
public:
    DelItemCommand(QGraphicsScene* scene, const QList<QGraphicsItem*>& itemsList, QUndoCommand* parent=0);
    void undo();
    void redo();

};


class EditGroupItemCommand : public QUndoCommand
{
public:
    EditGroupItemCommand(QGraphicsScene* scene, QUndoCommand* parent=0);
    void undo();
    void redo();

protected:
    QGraphicsScene* m_scene;

    CGroupItem* m_groupItem;
    QList<QGraphicsItem*> m_childItems;
};

class EditUnIconItemCommand:public QUndoCommand
{
public:
    EditUnIconItemCommand(QGraphicsScene* scene, QUndoCommand* parent=0);
    void undo();
    void redo();
private:
    QGraphicsScene* m_scene;
    CGroupItem* m_IconItem;
    QList<QGraphicsItem*> m_childItems;
};

class EditUnGroupItemCommand : public QUndoCommand
{
public:
    EditUnGroupItemCommand(QGraphicsScene* scene, QGraphicsItemGroup* item, QUndoCommand* parent=0);
    void undo();
    void redo();

protected:
    QGraphicsScene* m_scene;
    QGraphicsItemGroup* m_groupItem;
    QList<QGraphicsItem*> m_childItems;
};


class EditIconItemCommand:public QUndoCommand
{
public:
    EditIconItemCommand(const QStringList& IconInfo,const QPixmap LstIcon, QGraphicsScene* scene, QUndoCommand* parent=0);
    void undo();
    void redo();
private:
    QStringList m_IconInfo;
    QString m_grpName;
    const QPixmap m_Icon;
    QGraphicsScene* m_scene;
    CIconItem* m_groupItem;
    QList<QGraphicsItem*> m_childItems;
};





class MoveItemCommand : public HandleMultiItemsCommand<UndoStru<QPointF> >
{
public:
    MoveItemCommand(QGraphicsScene* scene, const QList<UndoStru<QPointF> >& cmdStruList, QUndoCommand* parent=0);
    void undo();
    void redo();

};


class EditItemPropertyCommand : public EditOneItemCommand<QGraphicsItem, QVariant>
{
public:
    EditItemPropertyCommand(QGraphicsItem* item, const QVariant& newValue, const QString& pptName, QUndoCommand* parent=0);
    int id() const {return CMD::EditProperty;};
    void undo();
    void redo();

private:
    const QString m_propertyName;

};

class EditRotateItemCommand : public EditOneItemCommand<QGraphicsItem, qreal>
{
public:
    EditRotateItemCommand(QGraphicsItem* item, qreal lastAngle, qreal swapAngle, QUndoCommand* parent=0);
    int id() const {return CMD::EditRotate;};
    void undo();
    void redo();
    static void RotateItem(QGraphicsItem* item, qreal angle);
};

class EditTransformItemScaleCommand : public EditOneItemCommand<QGraphicsItem, QTransform>
{
public:
    EditTransformItemScaleCommand(QGraphicsItem* item, const QTransform& oldTransform, QUndoCommand* parent=0);

    void undo();
    void redo();

};

class EditTransformItemCommand : public HandleMultiItemsCommand<UndoStru<QTransform> >
{
public:
    EditTransformItemCommand(QGraphicsScene* scene, const QList<UndoStru<QTransform> >& transformList, QUndoCommand* parent=0);
    void undo();
    void redo();
};



class EditLevelItemCommand : public EditOneItemCommand<QGraphicsItem, qreal>
{
public:
    EditLevelItemCommand(QGraphicsScene* scene, QGraphicsItem* item, qreal newValue, QUndoCommand* parent=0);
    void undo();
    void redo();
};

class EditLevelMultiItemCommand : public  HandleMultiItemsCommand<UndoStru<qreal> >
{
public:
    EditLevelMultiItemCommand(QGraphicsScene* scene, const QList<UndoStru<qreal> >& cmdStruList, QUndoCommand* parent=0);
    void undo();
    void redo();
};


class AddLinkLineItemCommand : public QUndoCommand
{
public:
    AddLinkLineItemCommand(CLinkLineItem* item, QUndoCommand* parent=0);
    void undo();
    void redo();
private:
    CLinkLineItem* m_item;
    CPinItem* m_tailPinItem;
    CPinItem* m_headPinItem;
    QGraphicsScene* m_scene;
};


struct LinkUndoValue
{
    LinkUndoValue(const QPolygonF& polygonF, CPinItem* item1, CPinItem* item2):poly(polygonF), headItem(item1), tailItem(item2) {};
    LinkUndoValue() {poly = QPolygonF(); headItem=NULL;tailItem=NULL;};
    QPolygonF poly;
    CPinItem* headItem;
    CPinItem* tailItem;
};

class EditLinkLineItemCommand : public EditOneItemCommand<CLinkLineItem, LinkUndoValue>
{
public:
    EditLinkLineItemCommand(CLinkLineItem* item, const LinkUndoValue& oldShape, QUndoCommand* parent=0);
    int id() const {return CMD::EditLinkLineShape;};
    void undo();
    void redo();
private:
};

class LinkLineHintLinkLineItemCommand : public QUndoCommand
{
public:
    LinkLineHintLinkLineItemCommand(CLinkLineItem* editItem,
                                    CLinkLineItem* hintItem,
                                    const QPolygonF& editOldShape,
                                    int activeId,
                                    const QPointF& hintScenePos,
                                    const QPolygonF& section1,
                                    const QPolygonF& section2,
                                    QUndoCommand* parent=0);

    LinkLineHintLinkLineItemCommand(CLinkLineItem* editItem,
                                    CLinkLineItem* hintItem,
                                    const QPointF& hintScenePos,
                                    const QPolygonF& section1,
                                    const QPolygonF& section2,
                                    QUndoCommand* parent=0);

    void undo();
    void redo();
private:
    CLinkLineItem* m_editItem;
    QPolygonF m_editOldShape;
    QPolygonF m_editNewShape;
    CPinItem* m_editOldHeadItem;
    CPinItem* m_editOldTailItem;
    int m_editId;

    CLinkLineItem* m_hintItem;
    QPolygonF m_hintOldShape;
    QPolygonF m_section1;
    CPinItem* m_hintOldHeadItem;
    CPinItem* m_hintOldTailItem;

    CLinkLineItem* m_addLinkItem;
    QPolygonF m_section2;

    QPointF m_hintScenePos;
    CPinItem* m_addPinItem;
};

class LinkLineHintLinkLineItemJoinCommand : public QUndoCommand
{
public:
    LinkLineHintLinkLineItemJoinCommand(CLinkLineItem* editItem,bool isHead,CLinkLineItem* hintItem, bool isHintItemHead,QUndoCommand* parent=0);
    void undo();
    void redo();
private:
    CLinkLineItem* m_editItem;
    QPolygonF m_editOldShape;
    QPolygonF m_editNewShape;
    CPinItem* m_editOldHeadItem;
    CPinItem* m_editOldTailItem;
    bool m_isHead;
    bool m_isHintHead;

    CLinkLineItem* m_hintItem;
    QPolygonF m_hintOldShape;
    QPolygonF m_section1;
    CPinItem* m_hintOldHeadItem;
    CPinItem* m_hintOldTailItem;
    QPointF m_hintScenePos;
    CPinItem* m_addPinItem;
};

class IconItemHintLinkLineItemCommand : public QUndoCommand
{
public:
    IconItemHintLinkLineItemCommand(CIconItem* editItem,CLinkLineItem* hintItem,const QPointF& hintScenePos,const QPolygonF& section1,const QPolygonF& section2,QUndoCommand* parent=0);
    void undo();
    void redo();
private:
    CIconItem* m_editItem;
    QPolygonF m_editOldShape;
    QPolygonF m_editNewShape;
    CPinItem* m_editOldHeadItem;
    CPinItem* m_editOldTailItem;
    int m_editId;
    CLinkLineItem* m_hintItem;
    QPolygonF m_hintOldShape;
    QPolygonF m_section1;
    CPinItem* m_hintOldHeadItem;
    CPinItem* m_hintOldTailItem;
    CLinkLineItem* m_addLinkItem;
    QPolygonF m_section2;
    QPointF m_hintScenePos;
};

class PlaneOperateItemCommand : public HandleMultiItemsCommand<UndoStru<QBitArray> >
{
public:
    PlaneOperateItemCommand(QGraphicsScene* scene, const QList<UndoStru<QBitArray> >& itemsList, QUndoCommand* parent=0);
    void undo();
    void redo();
};
#endif
