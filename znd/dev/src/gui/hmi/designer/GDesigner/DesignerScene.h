
#ifndef DESIGNERSCENE_H
#define DESIGNERSCENE_H 

#if _MSC_VER > 1000

#endif

#include "GraphScene.h"
#include "ActionEnum_p.h"

#include <QUndoStack>

template<typename TValue> struct UndoStru;
class CTextItem;
class CGroupItem;
class CIconItem;
class QVariant;


class CDesignerScene : public CGraphScene
{
    Q_OBJECT
public:
    CDesignerScene(QObject *parent);
    virtual ~CDesignerScene();
    QUndoStack* GetUndoStack() const {return m_undoStack;};
    typedef void (CDesignerScene::*_editFuncPtr)();
    void SetupUndoConnecting(QAction* undoAction, QAction* redoAction);
    bool GetModified(){ return m_beModified; }
    void SetModified(bool beModified);
	void SetIconInfo(QString picFile, QString tip=""){ m_fileIconName = picFile; m_iconTip = tip; };

public slots:
    int FileImport(const QString& fileName);
	int FileOpen(const QString& fileName, bool isBinary = false);
	int FileSave(const QString& fileName, bool isBinary = false);
    virtual void UpdateScene();

    void GetPropertyLists(QList< QPair<QString, QList<QPair<QString,QVariant> > > >& pptList);
    bool SetProperty(const QString &property_name, const QVariant& value, const QString &groupName=QString(""));

    void ApplySetProperty(const QString& name, const QVariant& value, const QString &groupName=QString(""));
    void OnEditUndo() {m_undoStack->undo();};
    void OnEditRedo() {m_undoStack->redo();};
    void OnRotate();
    void OnEditCut();
    void OnEditCopy();
    void OnEditPaste();
    void OnEditPaste(QPointF dp, bool clearData=true);
    void OnEditSelectType();
	void OnEditRefIcon();
    void OnEditReplace();
    void OnEditDelete();
    void OnEditGroup();
    void OnEditUnGroup();
    void OnEditAddPoint();
    void OnEditDelPoint();

	void SaveIconByScene(const QString& fileName, const QString& iType);
	void SaveIconBySelected(QString& iName, QString& iType, QString &tip);
    QString NodeGenerate();
    void OnBreakIcon();

    void OnEditLevelUp() {OnEditLevelPrivate(EditLevelUp);};
    void OnEditLevelDown() {OnEditLevelPrivate(EditLevelDown);};
    void OnAlignLeft() {OnAlignPrivate(AlignLeft);};
    void OnAlignRight() {OnAlignPrivate(AlignRight);};
    void OnAlignTop() {OnAlignPrivate(AlignTop);};
    void OnAlignBottom() {OnAlignPrivate(AlignBottom);};
    void OnAlignHorizontal() {OnAlignPrivate(AlignHorizontal);};
    void OnAlignVertical() {OnAlignPrivate(AlignVertical);};
    void OnAlignHorizontalSpacing() {OnAlignPrivate(AlignHorizontalSpacing);};
    void OnAlignVerticalSpacing() {OnAlignPrivate(AlignVerticalSpacing);};
    void OnHorizontalMirror() {OnMirrorPrivate(AlignHorizontalMirror);};
    void OnVerticalMirror() {OnMirrorPrivate(AlignVerticalMirror);};
    void OnSelectAll();

    void OnSwitchGridShow();
    void OnSwitchCatch();
    void OnSwitchHvLock();
    void OnSetGridWidth(int width);

    void onGlobalSetChanged(QString propertyName, QVariant value);
    virtual QObject* CreateItem(const QString& jsonstr,int dx=0,int dy=0);
    virtual void OnSelectionChanged();
    bool ReadOnly(){return m_readOnly;};
    void SetReadOnly(bool readonly){  m_readOnly=readonly;};
protected:
    void drawBackground(QPainter* painter, const QRectF& rect);
    void mousePressEvent(QGraphicsSceneMouseEvent* e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* e);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* e);

    void dropEvent(QGraphicsSceneDragDropEvent * e);
    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);

signals:
    void MouseMoved(const QPointF& pos);
    void DropEvent(const QString& msg);



private:
    void OnAlignPrivate(ACTION_ORDER alginOrient);
    void OnMirrorPrivate(ACTION_ORDER alginOrient);
    void OnEditLevelPrivate(ACTION_ORDER alginOrient);
    QList<QGraphicsItem*> PasteRead(CGraphSvgReader& outStream);
    int FileSaveChannelLink(const QString& fileName);

    QUndoStack* m_undoStack;
    QList<UndoStru<QPointF> > m_moveCmdStruList;
    bool m_ifEditIcon;
    short m_StateNums;

    int m_pasteNum;
    QPointF m_dragStartPos;
    QPointF m_DropPoint;
    bool m_beModified;

	QString m_fileIconName;
	QString m_iconTip;
    bool m_readOnly;
};

#endif
