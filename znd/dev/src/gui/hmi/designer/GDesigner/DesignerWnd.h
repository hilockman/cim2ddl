


#ifndef DESIGNERWINDOW_H
#define DESIGNERWINDOW_H 

#include "GWnd.h"
#include "GlobalToolBar.h"

class CGraphView;
class CDesignerView;
class CGraphScene;
class CDesignerScene;
class CNaviDialog;
class PropertyEditor;
class QUndoView;
class CGroupItem;
class CObjectInspector;
class CItemBox;
class CMdiSubWindow;
class AnimationDlg;

class CDesignerWnd : public CGWnd
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{C4F58AA2-9765-4c14-8D71-89D7ADFAB8E1}")
    Q_CLASSINFO("InterfaceID", "{551CF8F7-87D3-4df7-B0FC-71AEF06A13A5}")
    Q_CLASSINFO("EventsID", "{B6DFC664-6E39-4405-959D-B7A83CE57298}")
private:
    enum SaveType
    {
        save,
        saveas
    };
public:
    CDesignerWnd(int wnd_id, const GDispInfo& disp_info=GDispInfo(), QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0);
    ~CDesignerWnd();

    typedef void (CDesignerWnd::*_editFuncPtr)();
    void ReadSettings();
    CMdiSubWindow* CreateMdiChild();
    CMdiSubWindow* FindMdiChild( const QString &file_name,const QString& wnd_tag=QString::null);
    CMdiSubWindow* ActiveSubWindow();
    void SetActiveSubWindow(CMdiSubWindow *window);
    CDesignerScene* ActiveScene() const ;
    CDesignerView* ActiveView() const;
    void OnPatchCreateChanged(bool checked, int patchCreateNum);
    bool getBePatchCreate(){ return m_bPatchCreate; }
    int getPatchCreateNum(){ return m_iPatchCreateNum; }
    int NeedSave(const QString & action);
    static int CheckName(QString fName, bool isIcon = false, bool askCover = false, QString iconTip = "");
	void SyncFile(QString fileName, bool isDel = false){ emit FileSave(QDir::cleanPath(fileName), isDel); };
	bool CloseFile(const QString &file_name);
signals:
	void FileSave(QString fileName, bool isDel);

public slots:
    virtual QObject* ActiveWindow(){return (QObject*)ActiveView();};

    virtual QObject* Open(const QString& file_name, const QString& wnd_tag="", const QVariant& jobjArgs=QVariant());
    int FileConvert(const QString& filename,const QString& outfilename );

    void OnFileNew();
    void OnFileNewIcon();
    void OnFileOpen();
	int OnFileOpen(QString fileName, bool isImport = false, bool isBinary = false);
	void OnFileImport();
    void OnFileSave();
    void OnFileSaveAs();
	void OnFileOpenBinary();
	void OnFileSaveBinary();
	void OnLoadIcons();
    void OnCreateIcon();
    void OnNormalView();
    void OnNewDesignerWnd();
    void OnNewExplorerWnd();
    void OnNewNavigation();

    void OnShowToolbox();
    void OnShowPropertyEditor();
    void OnUpdateLink();
    void OnResetLink() {};
    void OnNodeGenerate();
    void UpdatePropertySheet(bool beSameType = false);
    void LoadToolBox(QString filename);
    void SetDrawSettings(const QVariantMap& setttings);
    QVariantMap GetDrawSettings();
    void OnEditShowPpt();
    virtual QObject*  FindChild(const QString& componentName );
    virtual void retranslateUi();
protected:
    void closeEvent ( QCloseEvent * e );

private:
    void FileAutoCut();
    void ShowAllLink();
    void DeleteLink();
    void ResentFileSelect(int index);
    void ResetDynamic();

    void SetupToolbars();
    void SetupMenubar();
    void SetUpObjectInspector();
    void SetupUndoView();
    void SetupItemBox();
    void SetupPropertyEditor();
    void SetupNaviDialog();
AnimationDlg* GetAnimDlg();

private slots:
    void OnSubWindowActivated(QMdiSubWindow* window);
    void OnSetProperty(const QString &groupName, const QString &name, const QVariant& value, bool enableSubPropertyHandling);
    void OnUpdateStatus(const QPointF& pos);
    void OnObjectInspectorItemClicked(QGraphicsItem*);
    void OnSceneScaleChanged(const QString &scale);
    void OnPlaneMaskChanged(const QBitArray&);
    void OnCurPlaneChanged(int);


private:

    QDockWidget* m_pPropertyDockWnd;
    QDockWidget* m_pToolsDockWnd;
    QDockWidget* m_pNaviDockWnd;
    QDockWidget* m_pObjectInspectorDock;

    QToolBar* m_pFileToolBar;
    QToolBar* m_pWndToolBar;
    QToolBar* m_pEditToolBar;
    QToolBar* m_pEnvToolBar;
    QToolBar* m_pAlignToolBar;

    PropertyEditor* m_propertyEditor;
    CItemBox* m_itemBox;
    QUndoView* m_undoView;
    CObjectInspector* m_inspector;

    QLabel* m_TimeLabel;
    QLabel* m_ScaleLabel;
	QComboBox* m_sceneScaleCombo;
    bool m_bPatchCreate;
    int m_iPatchCreateNum;
    GlobalToolBarCreator* m_gtbar;
    QVariantMap m_DrawSettings;
    AnimationDlg* m_AnimatDlg;
};

#endif
