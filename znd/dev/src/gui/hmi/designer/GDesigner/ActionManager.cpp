

#include <QMenu>
#include <QSettings>
#include "ActionManager.h"
#include "GFunc.h"
#include "ConstString.h"
#include "DesignerScene.h"
#include "DesignerWnd.h"
#include "GraphItem.h"


namespace {
bool g_TestNeedZero(const QList<QGraphicsItem*>& itemList)
{
    return itemList.isEmpty();
}
bool g_TestNeedOne(const QList<QGraphicsItem*>& itemList)
{
    return itemList.count()==1;
}
bool g_TestNeedAny(const QList<QGraphicsItem*>& itemList)
{
    return itemList.count()>0;
}
bool g_TestNeedMoreThanOne(const QList<QGraphicsItem*>& itemList)
{
    return itemList.count()>1;
}
bool g_TestNeedNoCares(const QList<QGraphicsItem*>&)
{
    return true;
}
bool g_TestNeedSignlePolyItem(const QList<QGraphicsItem*>& itemList)
{
    if(itemList.count()!=1)
        return false;
    int type = itemList.first()->type();
    switch(type)
    {
    case Hmi::Polygon:
    case Hmi::Polyline:
    case Hmi::Path:
    case Hmi::ClosePath:
        return true;
    }
    return false;
}

bool g_TestNeedGroup(const QList<QGraphicsItem*>& itemList)
{
	if (itemList.count() == 1 && itemList.first()->type() == Hmi::Group)
		return true;
	else if (itemList.count() > 1)
		return true;

	return false;
}

bool g_TestNeedNoSingleGroup(const QList<QGraphicsItem*>& itemList)
{
    if(itemList.isEmpty())
        return false;
    else if(itemList.count() == 1)
        return itemList.first()->type() != Hmi::Group;
    else
        return true;
}
bool g_TestNeedNoSingleIcon(const QList<QGraphicsItem*>& itemList)
{
    if(itemList.isEmpty())
        return false;
    else if(itemList.count() == 1)
        return itemList.first()->type() != Hmi::Icon;
    else
        return true;
}

bool g_TestNeedSingleChartItem(const QList<QGraphicsItem*>& itemList)
{
    if(itemList.count() != 1)
        return false;
	return g_dataPtr(itemList.first())->Type() == Hmi::PieWidget || g_dataPtr(itemList.first())->Type() == Hmi::BarWidget;
}

enum SelectionNeededMode {NeedZero,
                          NeedOne,
                          NeedAny,
                          NeedMoreThanOne,
                          NeedNoCares,
                          NeedSignlePolyItem,
                          NeedGroupItem,
                          NeedNoSignleGroupItem,
                          NeedNoSignleIconItem,
                          NeedSignleChartItem,
                          TEST_CNT};
typedef bool (*g_TestFunc)(const QList<QGraphicsItem*>&);
const g_TestFunc testFuncArray[TEST_CNT] = { &g_TestNeedZero,
                                             &g_TestNeedOne,
                                             &g_TestNeedAny,
                                             &g_TestNeedMoreThanOne,
                                             &g_TestNeedNoCares,
                                             &g_TestNeedSignlePolyItem,
                                             &g_TestNeedGroup,
                                             &g_TestNeedNoSingleGroup,
                                             &g_TestNeedNoSingleIcon,
                                             &g_TestNeedSingleChartItem,
                                           };

};

struct ActionProperty
{
    short testFuncId;
    bool isShow;
    bool isSceneSlot;
};

Q_DECLARE_METATYPE(ActionProperty);

class ActionManagerPrivate
{
public:
    ActionManagerPrivate() : m_actIndexVec(ACTION_ORDERNUM) {};

    void ConnectWndSlot(QAction* action, ACTION_ORDER order, CDesignerWnd::_editFuncPtr slot, SelectionNeededMode testIndex = NeedNoCares, bool isShow = true)
    {
        m_actWndSlotHash[action] = slot;
        m_actIndexVec[order] = action;
        ActionProperty p;
        p.testFuncId = testIndex;
        p.isShow = isShow;
        p.isSceneSlot = false;
        action->setData(QVariant::fromValue(p));

    };

    void ConnectSceneSlot(QAction* action, ACTION_ORDER order, CDesignerScene::_editFuncPtr slot, SelectionNeededMode testIndex = NeedNoCares, bool isShow = true)
    {
        m_actSceneSlotHash[action] = slot;
        m_actIndexVec[order] = action;
        ActionProperty p;
        p.testFuncId = testIndex;
        p.isShow = isShow;
        p.isSceneSlot = true;
        action->setData(QVariant::fromValue(p));
    }

    int GetActionIndex(QAction* action) { return m_actIndexVec.indexOf(action);};

    QHash<QAction*, CDesignerScene::_editFuncPtr> m_actSceneSlotHash;
    QHash<QAction*, CDesignerWnd::_editFuncPtr> m_actWndSlotHash;
    QVector<QAction*> m_actIndexVec;

};


CActionManager::CActionManager()
    : QObject(NULL), Mdi("actionManager"),
      m_p(new ActionManagerPrivate)
{
    for(int order = FileToolBar; order<TOOLBAR_ORDERNUM; ++order)
        m_actionGroupArray[order] = new QActionGroup(this);

    m_actionGroupArray[StatusToolBar]->setExclusive(false);
    SetUpAction();

}

CActionManager::~CActionManager()
{
    for(int order = FileToolBar; order<TOOLBAR_ORDERNUM; ++order)
        delete m_actionGroupArray[order];

    delete m_p;
}

QAction* CActionManager::CreateAction( QActionGroup* actionGroup, QString description, const char* iconName , const char* shortCut )
{
    return CreateAction(actionGroup, description, iconName, QKeySequence(QString(shortCut)));
}


QAction* CActionManager::CreateAction(QActionGroup* actionGroup, QString description, const char* iconName, const QKeySequence& shortCut)
{
    static const QString actionIconPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON);
    QAction* action = new QAction(QPixmap(actionIconPath+iconName), description, this);
    action->setShortcut(shortCut);
    actionGroup->addAction(action);
    return action;
}

void CActionManager::SetUpAction()
{
    QAction* action=NULL;
    QString iconbuf;

    QActionGroup* actGroup = m_actionGroupArray[FileToolBar];


    action = CreateAction(actGroup, QObject::tr(G_STR_file_new), "fileNew.png", "Ctrl+N");
    action->setObjectName(G_STR_file_new);
    m_p->ConnectWndSlot(action, FileNew, &CDesignerWnd::OnFileNew);

	action = CreateAction(actGroup, QObject::tr(G_STR_icon_new), "fileNewIcon.png", "Ctrl+Shift+N");
    action->setObjectName(G_STR_icon_new);
    m_p->ConnectWndSlot(action, FileNewIcon, &CDesignerWnd::OnFileNewIcon);

	action = CreateAction(actGroup, QObject::tr(G_STR_file_open), "fileOpen.png", "Ctrl+O");
    action->setObjectName(G_STR_file_open);
    m_p->ConnectWndSlot(action, FileOpen, &CDesignerWnd::OnFileOpen);

	action = CreateAction(actGroup, QObject::tr(G_STR_file_import), "folder.png", "");
    action->setObjectName(G_STR_file_import);
    m_p->ConnectWndSlot(action, FileImport, &CDesignerWnd::OnFileImport,NeedNoCares,false);

	action = CreateAction(actGroup, QObject::tr(G_STR_file_save), "save.png", "Ctrl+S");
    action->setObjectName(G_STR_file_save);
    m_p->ConnectWndSlot(action, FileSave, &CDesignerWnd::OnFileSave);

	action = CreateAction(actGroup, QObject::tr(G_STR_file_save_as), "saveAs.png");
    action->setObjectName(G_STR_file_save_as);
    m_p->ConnectWndSlot(action, FileSaveAs, &CDesignerWnd::OnFileSaveAs,NeedNoCares,false);

	action = CreateAction(actGroup, QObject::tr(G_STR_file_open_binary), "openBinary.png", "");
    action->setObjectName(G_STR_file_open_binary);
    m_p->ConnectWndSlot(action, FileOpenBinary, &CDesignerWnd::OnFileOpenBinary,NeedNoCares,false);

	action = CreateAction(actGroup, QObject::tr(G_STR_file_save_binary), "saveBinary.png", "");
    action->setObjectName(G_STR_file_save_binary);
    m_p->ConnectWndSlot(action, FileSaveBinary, &CDesignerWnd::OnFileSaveBinary,NeedNoCares,false);

	action = CreateAction(actGroup, QObject::tr(G_STR_file_load_icons), "Update.png", "");
    action->setObjectName(G_STR_file_load_icons);
    m_p->ConnectWndSlot(action, LoadIcons, &CDesignerWnd::OnLoadIcons,NeedNoCares,false);

    actGroup = m_actionGroupArray[WndToolBar];
	
	action = CreateAction(actGroup, QObject::tr(G_STR_wnd_new_ge), "newExplorer.png");
    action->setObjectName(G_STR_wnd_new_ge);
    m_p->ConnectWndSlot(action, NewExplorerWnd, &CDesignerWnd::OnNewExplorerWnd);

	/*action = CreateAction(actGroup, QObject::tr(G_STR_wnd_new_ge), "newNavigation.png", false);
    m_p->ConnectWndSlot(action, NewNaviWnd, &CDesignerWnd::OnNewNavigation);
    action->setCheckable(true);*/

	action = CreateAction(actGroup, QObject::tr(G_STR_wnd_toolbox), "showToolBox.png", false);
    action->setObjectName(G_STR_wnd_toolbox);
    m_p->ConnectWndSlot(action, ShowToolbox, &CDesignerWnd::OnShowToolbox,NeedNoCares,false);

	action = CreateAction(actGroup, QObject::tr(G_STR_property_editor), "showPropertyEditor.png", false);
    action->setObjectName(G_STR_property_editor);
    m_p->ConnectWndSlot(action, ShowPropertyEditor, &CDesignerWnd::OnShowPropertyEditor,NeedNoCares,false);

	action = CreateAction(actGroup, QObject::tr(G_STR_input_netdb), "nodeGenerate.png");
    action->setObjectName(G_STR_input_netdb);
    m_p->ConnectWndSlot(action, NodeGenerate, &CDesignerWnd::OnNodeGenerate,NeedNoCares,false);

	/*action = CreateAction(actGroup, tr("resetLink"), "resetLink.png");
    m_p->ConnectWndSlot(action, ResetLink, &CDesignerWnd::OnResetLink);*/



    actGroup = m_actionGroupArray[AlignToolBar];

	action = CreateAction(actGroup, QObject::tr(G_STR_rotate), "rotate.png");
    action->setObjectName(G_STR_rotate);
    m_p->ConnectSceneSlot(action, EditRotate, &CDesignerScene::OnRotate, NeedOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_align_left), "alignLeft.png");
    action->setObjectName(G_STR_align_left);
    m_p->ConnectSceneSlot(action, AlignLeft, &CDesignerScene::OnAlignLeft, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_align_right), "alignRight.png");
    action->setObjectName(G_STR_align_right);
    m_p->ConnectSceneSlot(action, AlignRight, &CDesignerScene::OnAlignRight, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_align_top), "alignTop.png");
    action->setObjectName(G_STR_align_top);
    m_p->ConnectSceneSlot(action, AlignTop, &CDesignerScene::OnAlignTop, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_align_bottom), "alignBottom.png");
    action->setObjectName(G_STR_align_bottom);
    m_p->ConnectSceneSlot(action, AlignBottom, &CDesignerScene::OnAlignBottom, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_align_horizontal), "horizontalCenter.png");
    action->setObjectName(G_STR_align_horizontal);
    m_p->ConnectSceneSlot(action, AlignHorizontal, &CDesignerScene::OnAlignHorizontal, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_align_vertical), "verticalCenter.png");
    action->setObjectName(G_STR_align_vertical);
    m_p->ConnectSceneSlot(action, AlignVertical, &CDesignerScene::OnAlignVertical, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_horizontal_spacing), "horizontalSpacing.png");
    action->setObjectName(G_STR_horizontal_spacing);
    m_p->ConnectSceneSlot(action, AlignHorizontalSpacing, &CDesignerScene::OnAlignHorizontalSpacing, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_vertical_spacing), "verticalSapcing.png");
    action->setObjectName(G_STR_vertical_spacing);
    m_p->ConnectSceneSlot(action, AlignVerticalSpacing, &CDesignerScene::OnAlignVerticalSpacing, NeedMoreThanOne);

	action = CreateAction(actGroup, QObject::tr(G_STR_horizontal_mirror), "horizontalMirror.png");
    action->setObjectName(G_STR_horizontal_mirror);
    m_p->ConnectSceneSlot(action, AlignHorizontalMirror, &CDesignerScene::OnHorizontalMirror, NeedAny);

	action = CreateAction(actGroup, QObject::tr(G_STR_vertical_mirror), "verticalMirror.png");
    action->setObjectName(G_STR_vertical_mirror);
    m_p->ConnectSceneSlot(action, AlignVerticalMirror, &CDesignerScene::OnVerticalMirror, NeedAny);


    actGroup = m_actionGroupArray[EditToolBar];


	action = CreateAction(actGroup, QObject::tr(G_STR_edit_undo), "undo.png", QKeySequence::Undo);
    action->setObjectName(G_STR_edit_undo);
    m_p->ConnectSceneSlot(action, EditUndo, &CDesignerScene::OnEditUndo, NeedNoCares);
    action->setEnabled(false);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_redo), "redo.png", QKeySequence::Redo);
    action->setObjectName(G_STR_edit_redo);
    m_p->ConnectSceneSlot(action, EditRedo, &CDesignerScene::OnEditRedo, NeedNoCares);
    action->setEnabled(false);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_delete), "delete.png", QKeySequence::Delete);
    action->setObjectName(G_STR_edit_delete);
    m_p->ConnectSceneSlot(action, EditDelete, &CDesignerScene::OnEditDelete, NeedAny);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_cut), "cut.png", QKeySequence::Cut);
    action->setObjectName(G_STR_edit_cut);
    m_p->ConnectSceneSlot(action, EditCut, &CDesignerScene::OnEditCut, NeedAny);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_copy), "copy.png", QKeySequence::Copy);
    action->setObjectName(G_STR_edit_copy);
    m_p->ConnectSceneSlot(action, EditCopy, &CDesignerScene::OnEditCopy, NeedAny);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_pasteclip), "paste.png", QKeySequence::Paste);
    action->setObjectName(G_STR_edit_pasteclip);
    m_p->ConnectSceneSlot(action, EditPaste, &CDesignerScene::OnEditPaste, NeedNoCares);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_forward), "levelUp.png", "Ctrl+K");
    action->setObjectName(G_STR_edit_forward);
    m_p->ConnectSceneSlot(action, EditLevelUp, &CDesignerScene::OnEditLevelUp, NeedAny);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_back), "levelDown.png", "Ctrl+B");
    action->setObjectName(G_STR_edit_back);
    m_p->ConnectSceneSlot(action, EditLevelDown, &CDesignerScene::OnEditLevelDown, NeedAny);


	action = CreateAction(actGroup, QObject::tr(G_STR_edit_group), "group.png");
    action->setObjectName(G_STR_edit_group);
    m_p->ConnectSceneSlot(action, EditGroup, &CDesignerScene::OnEditGroup, NeedAny);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_ungroup), "unGroup.png");
    action->setObjectName(G_STR_edit_ungroup);
    m_p->ConnectSceneSlot(action, EditUnGroup, &CDesignerScene::OnEditUnGroup, NeedGroupItem);

	action = CreateAction(actGroup, tr("addPoint"), "add.png");
    action->setObjectName("addPoint");
    m_p->ConnectSceneSlot(action, EditAddPoint, &CDesignerScene::OnEditAddPoint, NeedSignlePolyItem);

	action = CreateAction(actGroup, tr("delPoint"), "del.png");
    action->setObjectName("delPoint");
    m_p->ConnectSceneSlot(action, EditDelPoint, &CDesignerScene::OnEditDelPoint, NeedSignlePolyItem);

	action = CreateAction(actGroup, tr("ShowPp"), "property.png");
    action->setObjectName("ShowPp");
    m_p->ConnectWndSlot(action, EditShowPpt, &CDesignerWnd::OnEditShowPpt, NeedNoCares);

	action = CreateAction(actGroup, tr("replace"), "replace.png");
    action->setObjectName("replace");
    m_p->ConnectSceneSlot(action, EditReplace, &CDesignerScene::OnEditReplace, NeedAny);

	action = CreateAction(actGroup, tr("selectType"), "selecttype.png");
    action->setObjectName("selectType");
    m_p->ConnectSceneSlot(action, EditSelectType, &CDesignerScene::OnEditSelectType, NeedOne);

	action = CreateAction(actGroup, tr("editRefIcon"), "editRefIcon.png");
    action->setObjectName("editRefIcon");
	m_p->ConnectSceneSlot(action, EditRefIcon, &CDesignerScene::OnEditRefIcon, NeedOne,false);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_icon), "editIcon.png");
    action->setObjectName(G_STR_edit_icon);
    m_p->ConnectWndSlot(action, EditIcon, &CDesignerWnd::OnCreateIcon, NeedAny);

	action = CreateAction(actGroup, QObject::tr(G_STR_edit_unicon), "editunIcon.png");
    action->setObjectName(G_STR_edit_unicon);
    m_p->ConnectSceneSlot(action, EditUnIcon, &CDesignerScene::OnBreakIcon, NeedOne);

    action = CreateAction(actGroup, tr("selectAll"), "selectAll.png", QKeySequence::SelectAll);
    action->setObjectName("selectAll");
    m_p->ConnectSceneSlot(action, SelectAll, &CDesignerScene::OnSelectAll, NeedNoCares);



    actGroup = m_actionGroupArray[StatusToolBar];
    action = CreateAction(actGroup, tr("showGrid"));
    action->setObjectName("showGrid");
    m_p->ConnectSceneSlot(action, SwitchGrid, &CDesignerScene::OnSwitchGridShow, NeedNoCares);
    action->setCheckable(true);
    action->setChecked(false);

    action = CreateAction(actGroup, tr("catch"));
    action->setObjectName("catch");
    m_p->ConnectSceneSlot(action, SwitchCatch, &CDesignerScene::OnSwitchCatch, NeedNoCares);
    action->setCheckable(true);
    action->setChecked(false);

    action = CreateAction(actGroup, tr("hvLock"));
    action->setObjectName("hvLock");
    m_p->ConnectSceneSlot(action, SwitchHv, &CDesignerScene::OnSwitchHvLock, NeedNoCares);
    action->setCheckable(true);
    action->setChecked(true);

    for(int i=FileToolBar; i<TOOLBAR_ORDERNUM; ++i)
        QObject::connect(m_actionGroupArray[i], SIGNAL(triggered(QAction*)), this, SLOT(OnActionTriggered(QAction*)));
}

void CActionManager::InitToolBar( QToolBar* bar, ActionGroupOrder order )
{
    Q_ASSERT(order<TOOLBAR_ORDERNUM);
    foreach(QAction* action, m_actionGroupArray[order]->actions())
    {
        if(action->data().value<ActionProperty>().isShow)
            bar->addAction(action);
    }
}

void CActionManager::OnSceneSelectionChanged()
{
    QGraphicsScene* scene = CurrentScene();
    if(!scene)
        return;
    const QList<QGraphicsItem*> itemList = scene->selectedItems();

    for(int order = AlignToolBar; order>=EditToolBar; --order)
    {
        foreach(QAction* action, m_actionGroupArray[order]->actions())
        {
            int funcId = action->data().value<ActionProperty>().testFuncId;
            action->setEnabled(testFuncArray[funcId](itemList));
        }
    }

}

void CActionManager::OnSwitchScene()
{
    CDesignerScene* scene = CurrentScene();

    QAction* undoAction = GetAction(EditUndo);
    QAction* redoAction = GetAction(EditRedo);
    QObject::disconnect(undoAction, SLOT(setEnabled(bool)));
    QObject::disconnect(redoAction, SLOT(setEnabled(bool)));

    if(!scene)
    {
        foreach(QAction* action, m_actionGroupArray[AlignToolBar]->actions())
            action->setEnabled(false);
        foreach(QAction* action, m_actionGroupArray[EditToolBar]->actions())
            action->setEnabled(false);
        return;
    }

    OnSceneSelectionChanged();



    undoAction->setEnabled(scene->GetUndoStack()->canUndo());
    redoAction->setEnabled(scene->GetUndoStack()->canRedo());

    QObject::connect(scene->GetUndoStack(), SIGNAL(canUndoChanged(bool)), undoAction, SLOT(setEnabled(bool)));
    QObject::connect(scene->GetUndoStack(), SIGNAL(canRedoChanged(bool)), redoAction, SLOT(setEnabled(bool)));
}


void CActionManager::CreateContextMenu( QMenu& menu )
{
    QGraphicsScene* scene = CurrentScene();
    if(!scene)
        return;
    QList<QGraphicsItem*> items = scene->selectedItems();
    int selectedCnt = items.size();
    if(selectedCnt > 0)
    {
        menu.addAction(GetAction(EditCopy));
        menu.addAction(GetAction(EditDelete));
        menu.addAction(GetAction(EditIcon));
		menu.addAction(GetAction(EditReplace));
        menu.addAction(GetAction(EditLevelUp));
        menu.addAction(GetAction(EditLevelDown));
        menu.addSeparator();
        menu.addAction(GetAction(AlignHorizontalMirror));
        menu.addAction(GetAction(AlignVerticalMirror));

        if(selectedCnt == 1)
        {
			menu.addAction(GetAction(EditUnGroup));
            if(g_TestNeedSingleChartItem(items))
                menu.addAction(GetAction(ChartProperty));
            if(g_TestNeedSignlePolyItem(items))
            {
                menu.addAction(GetAction(EditAddPoint));
                menu.addAction(GetAction(EditDelPoint));
            }
            menu.addSeparator();

            menu.addAction(GetAction(EditShowPpt));
            menu.addAction(GetAction(EditReplace));
            menu.addAction(GetAction(EditSelectType));
			if (items[0]->type() == Hmi::Icon)
				menu.addAction(GetAction(EditRefIcon));
        }
        else if(selectedCnt > 1)
        {
            menu.addSeparator();
            menu.addAction(GetAction(EditGroup));
			menu.addAction(GetAction(EditUnGroup));
            menu.addSeparator();
            menu.addAction(GetAction(AlignTop));
            menu.addAction(GetAction(AlignBottom));
            menu.addAction(GetAction(AlignVertical));
            menu.addAction(GetAction(AlignHorizontal));
            menu.addAction(GetAction(AlignLeft));
            menu.addAction(GetAction(AlignRight));
            menu.addAction(GetAction(AlignVerticalSpacing));
            menu.addAction(GetAction(AlignHorizontalSpacing));
        }
    }
    else
    {
        menu.addAction(GetAction(EditPaste));
        menu.addAction(GetAction(EditShowPpt));
    }

}

QAction* CActionManager::GetAction( ACTION_ORDER id )
{
    return m_p->m_actIndexVec[id];
}

void CActionManager::retranslateUi()
{
    for(int i=0;i<m_p->m_actIndexVec.size();i++){
        QAction* act=m_p->m_actIndexVec[i];
        if(act){
            QString txt=act->objectName();
            act->setText(QObject::tr(txt.toLocal8Bit().data()));
        }
    }
}

void CActionManager::InitFileMenu( QMenu* fileMenu )
{
    fileMenu->addAction(GetAction(FileNew));
    fileMenu->addAction(GetAction(FileNewIcon));
    fileMenu->addAction(GetAction(FileOpen));
	fileMenu->addAction(GetAction(FileImport));
    fileMenu->addAction(GetAction(FileSave));
    fileMenu->addAction(GetAction(FileSaveAs));
	fileMenu->addAction(GetAction(FileOpenBinary));
	fileMenu->addAction(GetAction(FileSaveBinary));
	fileMenu->addSeparator();
	fileMenu->addAction(GetAction(LoadIcons));
    fileMenu->addSeparator();
    //fileMenu->addAction(GetAction(FilePrint));
    fileMenu->addSeparator();
    for (int i = 0; i<CGWnd::MaxRecentFiles; ++i)
        fileMenu->addAction( CurrentWnd()->getRecentFilesActions()[i] );
}

void CActionManager::InitWndMenu( QMenu* wndMenu )
{
    wndMenu->addAction(GetAction(NewExplorerWnd));
    wndMenu->addAction(GetAction(NewDesignerWnd));
    wndMenu->addSeparator();
    wndMenu->addAction(GetAction(ShowPropertyEditor));
    wndMenu->addAction(GetAction(ShowToolbox));
}

void CActionManager::OnActionTriggered( QAction* action )
{
    if(action->data().value<ActionProperty>().isSceneSlot)
    {
        if(!CurrentScene())
            return;
        CDesignerScene::_editFuncPtr func = m_p->m_actSceneSlotHash[action];
        (CurrentScene()->*func)();
    }
    else
    {
        CDesignerWnd::_editFuncPtr func = m_p->m_actWndSlotHash[action];
        (CurrentWnd()->*func)();
    }
    int idx=m_p->GetActionIndex(action);
    if(CurrentWnd())
        CurrentWnd()->Emit("_action_triggered_",idx);

}

void CActionManager::InitPlaneMenu( QMenu* planeMenu )
{
    planeMenu->addAction(GetAction(PlaneDelItems));
    planeMenu->addAction(GetAction(PlaneCopyItems));
}

CActionManager* UnqActMng()
{
    static CActionManager _actMng;
    return &_actMng;
}
