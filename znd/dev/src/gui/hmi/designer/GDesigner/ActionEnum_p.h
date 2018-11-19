

#ifndef ACTIONENUM_P_H
#define ACTIONENUM_P_H 


enum ACTION_ORDER
{
    FileNew,
    FileNewIcon,
    FileOpen,
	FileImport,
    FileSave,
    FileSaveAs,
	FileOpenBinary,
	FileSaveBinary,
    FilePrint,
    LoadIcons,
    NewExplorerWnd,
    NewDesignerWnd,
    NewNaviWnd,
    NormalView,
    SwitchMdiMode,
    ShowPropertyEditor,
    ShowToolbox,
    UpdateLink,
    NodeGenerate,
    ResetLink,
    AlignLeft,
    AlignRight,
    AlignTop,
    AlignBottom,
    AlignHorizontal,
    AlignVertical,
    AlignHorizontalSpacing,
    AlignVerticalSpacing,
    AlignHorizontalMirror,
    AlignVerticalMirror,
    EditUndo,
    EditRedo,
    EditDelete,
    EditCut,
    EditCopy,
    EditPaste,
    EditOnTop,
    EditOnBottom,
    EditLevelUp,
    EditLevelDown,
    EditGroup,
    EditUnGroup,
    EditIcon,
    EditUnIcon,
    EditShowPpt,
    EditReplace,
    EditSelectType,
	EditRefIcon,
    EditRotate,
    EditAddPoint,
    EditDelPoint,
    SelectAll,
    SwitchGrid,
    SwitchCatch,
    SwitchHv,
    PlaneSetCurrent,
    PlaneDelItems,
    PlaneCopyItems,
    ChartProperty,
    ACTION_ORDERNUM
};


enum ActionGroupOrder
{
    FileToolBar,
    WndToolBar,
    EditToolBar,
    AlignToolBar,
    StatusToolBar,
    PlaneOperate,
    TOOLBAR_ORDERNUM
};
#endif
