



#ifndef CGDESIGNERVIEW_H
#define CGDESIGNERVIEW_H 

#include "Global.h"
#include "GFunc.h"
#include "GDApp.h"
#include "GraphView.h"
#include "CGrid.h"
class CGWnd;
class CGraphScene;
class CDesignerScene;
class CActionManager;


class CDesignerView : public CGraphView
{
    Q_OBJECT
public:
    CDesignerView(CGWnd *w,CGraphScene* scence,QWidget *parent=0, const char *name=0 ,Qt::WindowFlags f = 0);
    ~CDesignerView();
    enum EDITTYPE{EDITPIC,EDITICON};

public :
    void SetMainWindow(CGWnd *w) ;
    void MoveChildTo(int x,int y);
    void MoveChild(int x,int y);
    virtual QObject* GetItemInfo(QPoint pos, QString& msg);
    virtual void ShowTip(QPoint pos);
    void AddQSObject();
public:
    void Repaint(QRect rc,bool erase=false );
    void Repaint( bool erase = true );
    void ShowWhatsThis( QString whatsthis_string , QPoint pos );
    void SetEditType(EDITTYPE type){m_EditType=type;};
    EDITTYPE GetEditType(){return m_EditType;};
signals:
    void ItemBeCreated(QObject* item);
    // void leftClicked(int item_count, QString obj_info);
    void doubleClicked(int item_count, QString obj_info);
	void contextMenuClicked(QString menu_txt, QString act_info);
public slots:
    //virtual QObject* CenterOn(QObject *item);
    virtual QObject* CenterOn(QString itemName);
    void OnNaviViewPosChg(float,float);
    //  void OnContextMenu();

    QString NodeGenerate();

    /*!
    \brief 执行一段脚本命令 <br>
    \param [in] script_code -  脚本内容
    */
    virtual QVariant DoCmd(QString script_code); //执行脚本
    QObject* FindChild(const QString& name);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void contextMenuEvent ( QContextMenuEvent * e );
    void wheelEvent(QWheelEvent* e);
    virtual void	keyPressEvent ( QKeyEvent * event ) ;

private:
    bool IsCursorBeyond(const QPointF& viewPos);
    CDesignerScene *m_pScene;

    bool m_StopPaint;
    QPoint m_dragStartPos;
    bool m_isScaleByMidButton;
    EDITTYPE m_EditType;
    CGWnd* m_pGraphWnd;
	QString m_actionItemInfo;
};


class QScriptEdit;
class CMdiSubWindow : public QTabWidget
{
    Q_OBJECT
public:
    CMdiSubWindow(CGWnd* pwnd,QWidget * parent = 0, Qt::WindowFlags flags = 0);
    ~CMdiSubWindow();
    CDesignerView *GetView(){ return m_pView; };
    void AddPlaneCtlBar(QStringList& ctls);
	void FileOpen(QString& fileName, bool isImport = false, bool isBinary = false);
	void FileNew( QString& fileName);
    int FileSave(QString& fileName, bool isBinary = false);
	bool IsValidPlaneName(const QString &name);
	void SetCurrentPlane(int index){ m_pTabBar->setCurrentIndex(index); };
public slots:
    void OnCurrentPlaneChanged(int index);
    void OnToolBarContextMenu(const QPoint & pos);
    void OnPlaneCtl(QAction *act);
    void OnPlaneChkChg(int);
    void OnPlaneMoved(int from, int to);
    void OnCodeChanged();

    void RemoveTab(int index){removeTab(index);};

protected:
    void closeEvent(QCloseEvent * e);
    void InitUI();
private:
    CDesignerView * m_pView;
    CDesignerScene* m_pScene;
    QTabBar * m_pTabBar;
    QScriptEdit * m_pCodeEdit;
    CDesignerWnd* m_pWnd;
    CGrid m_Grid;
};

#endif
