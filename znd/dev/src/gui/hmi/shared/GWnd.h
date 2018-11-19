


#ifndef GWINDOW_H
#define GWINDOW_H 

#include "Global.h"
#include "GApp.h"
#include "qscriptenginedebugger.h"
#include "CQScriptWrap.h"
#include <QMdiArea>
class CGraphView;
class CGraphScene;
struct GDispInfo;

const QString g_InvalideStr="<>@\"&%$:,;?={}|^~[]\'`\\*. ()";

/*!
\ingroup  hmi
\defgroup  Window Window
*/
/*!
\brief   Window   is base calss  for Window <br>
\ingroup Window
*/

class CGWnd : public QMainWindow
{
    Q_OBJECT
public:
    enum BASE_MENU_TYPE
    {
        FILEMENU,WNDMENU,STYLEMENU,HELPMENU
    };
    CGWnd(int wnd_id=0, int wnd_style=Hmi::NORMAL_STYLE, QWidget* parent = 0, Qt::WindowFlags fl = 0 );
    virtual ~CGWnd();
    int Init();
    int GetWndStyle() {return m_WndStyle;};

    bool RestoreWndGeometry();
    void SaveWndGeometry();
    int NeedModSize();

    static const int MaxRecentFiles ;
    static const QString RecentFilesSettingTag;
    QAction** getRecentFilesActions(){ return m_recentFilesActions; }
    void SetUpRecentFilesAction();
	void ClearRecentFilesAction(QString fileName="");
	void UpdateRecentFiles(QString fileName);
signals:
    void CustomEvent(QString signal, QVariant value);
    void SubWindowActivated(QString);
    /*!
    \brief  <br>
    */
    void MenuTriggered(QString text,QVariant data,QObject* action );
	void CustomStyle();
public slots:
    void Emit(const QString& signal,const QVariant& value){emit CustomEvent(signal,value);};
    void SetProperty(QString name,QVariant value){setProperty(name.toLocal8Bit().data(),value);};
    QVariant Property(QString name){return property(name.toLocal8Bit().data());};
    /*!
    \brief  <br>
    */
    int LoadCss(const QString& filename);
    /*!
    \brief  <br>
    */
    int LoadCssString(const QString& css);
    //-99 mean self window; -1 mean all windows;0,1,2 mean
    /*!
    \brief  <br>
    */
    virtual QVariant DoCmd(QString wnd_name, QString file_name, QString script_code, int wnd_idx = -99);    
    /*!
    \brief  <br>
    */
    virtual QObject* Open(const QString& file_name, const QString& wnd_tag="", const QVariant& jobj=QVariant())=0;

    void ShowNaviDialog(bool show);

	void Navigate(int  nextorpre, const QString &targetWndTag = "");
    /*!
    \brief  <br>
    */
    void SetShowStyle(int style);
    virtual QObject*  FindChild(const QString& componentName );
    /*!
    \brief  <br>
    */
    //ifvisiable =-1 mean auto switch, 0 mean hide,1 mean show
    virtual QObject *EnableComponent(const QString& componentName, int ifvisiable =-1 );
    /*!
    \brief  <br>
    */
    void FilePrint(bool invert=false);
    void FilePrintVector();
    void FilePrintVectorPart();
    void FilePrintVectorSplit();
    void ReversePrintColor(bool is_reverse_color);
    void SelfDefinePrintColor(bool is_self_define);
    void FilePrintByScript(QString myrect);
    /*!
    \brief  <br>
    */

    void Exit(bool allwnd=false) ;
    /*!
    \brief  <br>
    */
    void SetArgs(QVariant args) {setProperty("__args__",args);};
    /*!
    \brief   <br>
    */
    QVariant GetArgs() {return property("__args__");};
    /*!
    \brief  <br>
    */

    QString GetWndTitle(const QString & wnd_name);
    /*!
    \brief  <br>
    */

    QString GetScreenCount();
    /*!
    \brief  <br>
    */
    QString GetScreenIndex();
    /*!
    \brief  <br>
    */
    QObject* AddDockWidget(QObject* obj, const QString& dockArea , QString title="");
    /*!
    \brief  <br>
    */
    void SetViewMode(int mode){m_pWorkspace->setViewMode((QMdiArea::ViewMode)(mode));};
    /*!
    \brief  <br>
    */
    QWidget* AddMenu(const QStringList& menuinfo);
	/*!
	\menuList ls array of JSON object  <br>
	*/
    QWidget* AddActicons(QString type,const QVariant& args);
	void AddMenuList(const QVariantList& menuList);
    /*!
    \brief  <br>
    */
    QWidget* AddToolBar(const QVariant& args );
    QWidget* AddToolBar(const QStringList& info, const QString &toolbarArea = "top", int layoutDirection=Qt::LeftToRight);
    /*!
    \brief  <br>
    */
    QObject* AddMenuBarWidget(const QString& widgetType, bool attopright = true);
    /*!
    \brief  <br>
    */
    QObject* AddToolBarWidget(const QStringList& info, const QString &toolbarArea = "top", int layoutDirection=Qt::LeftToRight);
    /*!
    \brief  <br>
    */
    QObjectList GetToolBars()
    {
        return m_allToolBars;
    };
    /*!
    \brief  <br>
    */

    void SetToolBarIconSize(const int& width, const int& height);
    /*!
    \brief  <br>
    */

    QObject* GetStatusBar();
    /*!
    \brief  <br>
    */

	QObject* AddStatusBarWidget(const QString& widgetType, bool beLeft = true, int stretch = 0);
    /*!
    \brief  <br>
    */

    void SetCorner(QString corner, QString area);
    /*!
    \brief  <br>
    */
    void TabifyDockWidget(QObject * first, QObject * second);
    /*!
    \brief  <br>
    */

    void EnableToolBar(bool enable);
    /*!
    \brief  <br>
    */
    void EnableMenuBar(bool enable);
    /*!
    \brief  <br>
    */
    void EnableStatusBar(bool enable);
    /*!
    \brief  <br>
	\menuType : enum BASE_MENU_TYPE
    */
	void EnableBaseMenu(bool enable,int menuType = -1);
    /*!
    \brief  <br>
    */

	void ClearMenuBar();
    /*!
    \brief  <br>
    */
	void ClearToolBar();
    /*!
    \brief  <br>
    */
	void RemoveStatusBarWidget(QObject* widget);
    /*!
    \brief  <br>
    */

    virtual QObject* ActiveWindow() ;
    /*!
    \brief  <br>
    */
    QObject* ContentWindow(QString winID,QString file_name="");
    /*!
    \brief  <br>
    */

    void SetGeometry(int x, int y, int w, int h)
        {
            setGeometry(x, y, w, h);
            //move(x,y);
        };

    void CloseAll(QString fileName = "");
    /*!
    \brief  <br>
    */
    void SetTabPosition(QString dockWidgetAreas, QString tabPosition);
    /*!
    \brief  <br>
    */
    void OpenDebugWnd();
    /*!
    \brief  <br>
    */
	void SetWndIcon(QString iconName);
public:

    QVector<CGraphView*> GetGraphViews() ;
    void SetWndType(int wnd_type) {m_WndType=wnd_type;};
    int GetWndType() {return m_WndType;};
    int GetWndID() {return m_WndID;};
    void FileExportAs();
    void SetGraphPathName(const QString& file_name){ m_GraphPathName=file_name;};
    QString GetGraphPathName() { return m_GraphPathName;};
    QString GetCurGraphName();
    int FileExportAs(const QString& graph_path_name,int file_type,const QRect& rect,const QString& outfile_path_name,bool is_real=false);
    int FileNewWindow(QString graph_path_name,int wnd_type);

public slots:
    CGraphView *FindMdiChild( const QString &file_name,const QString& wnd_tag=QString::null);
	virtual void FileOpen(bool isBinary = false);
	void FileOpenBinary();
    void FileNewGEWin();
    void FileNewGDWin();
    void FileExportGraph();

    /*!
    \brief  <br>
    */
    void SetStyle(const QString & style);
    void StyleWindows();
    void StyleMotif();
    void StyleMac();
    void StyleWin7();
    void StyleVista();
    void StyleFullScreen();
    /*!
    \brief  <br>
    */
    void ShowFullScreen();
    void About();
    void HelpAboutGraph();
    void ChangeStyle(const QString &styleName);
    /*!
    \brief  <br>
    */
    void OnMenuTriggered(QAction * action);
    /*!
    \brief  <br>
    */
    void OnOpenRecentFile();
    /*!
    \brief  <br>
    */
	void OnViewWindows(QAction* act);
	/*!
	\brief  <br>
	*/
	void OnStyleChanged(QAction* act);
    virtual void retranslateUi();
protected:
    void keyPressEvent ( QKeyEvent * event ) ;
	bool m_beUpdateLst;

private:
    void SetupBaseActions();
    void SetupBaseMenuBar();
public:
    bool m_FrameLess;
    int m_nLastShowMode ;
    QMdiArea* m_pWorkspace;
    GDispInfo m_GDispInfo;

    QMenu* m_pStyleMenu;
    QMenu* m_pHelpMenu;
    QMenu* m_pWndMenu;
    QMenu* m_pFileMenu;
    QMenu* GetBaseMenu(BASE_MENU_TYPE menuType);
    QList<CGraphView*> m_Views;
    
private:
    QDockWidget* m_pNaviDockWnd;
    QAction* m_pFileOpenWinAction;
    QAction* m_pFilePrintAction;
    QAction* m_pFilePrintPartAction;
    QAction* m_pFilePrintSplitAction;
    QAction* m_pReverseColorPrintAction;
    QAction* m_pSelfDefinePrintTimeAction;
    QAction* m_pFileExitAction;
    QAction* m_pCloseAllAction;
    QAction* m_pFileExportAction;

    QAction* m_pWinNewGDWinAction;
    QAction* m_pWinNewGEWinAction;
    QAction* m_pWinOpenNaviAction;
    QAction* m_pPlaneChangeAction;

    QAction* tileAct;
    QAction* cascadeAct;
	QAction* tabbedAct;
	QActionGroup* m_pViewActions;

	QActionGroup* m_pStyleActions;

    QAction* nextAct;
    QAction* previousAct;
    QAction* closeAct;
    QAction* closeAllAct;
    QAction* m_pActionSelectAreaTool;
    QActionGroup* m_pActionGroupTools;

    QAction* m_pFileOpenAction;
	QAction* m_pFileOpenBinaryAction;
    QAction* m_pHelpAboutGraphAction;
    QAction* m_pHelpWhatsThisAction;



    int m_WndStyle;
    int m_WndType;
    int m_WndID;
    QString m_GraphPathName;
    QByteArray* m_pGeometry;
    QAction** m_recentFilesActions;
	QStringList m_recentFiles;
    QList<QObject*> m_allToolBars;
    bool m_WndFullScreen;

    QScriptEngineDebugger* m_debugger;
    QMainWindow *m_debugWindow;
	int m_curViewPos;

};

#endif
