


#ifndef GEXPLORERWINDOW_H
#define GEXPLORERWINDOW_H 

#include "Global.h"
#include "GEApp.h"
#include "GWnd.h"
#include <QMdiArea>

class CGExplorerView;
class CGraphScene;
class CExplorerScene;
class CNaviDialog;
class CGExplorerWnd : public CGWnd
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{EB6E82C0-03FC-4c9d-9BEA-0E79BFA7B50F}")
    Q_CLASSINFO("InterfaceID", "{F63F8306-625B-41ff-B9D3-B03642EE2516}")
    Q_CLASSINFO("EventsID", "{E5A5D73C-15B4-40d6-826B-E8B7F21E0C00}")
public:
    CGExplorerWnd(int wnd_id=0, int wnd_style=Hmi::NORMAL_STYLE, QWidget* parent = 0, Qt::WindowFlags fl = 0 );
    virtual ~CGExplorerWnd();
    CGExplorerView *CreateMdiChild();
    void AddSubWindow(QWidget* child);
    CGExplorerView *ActiveMdiChild();
	bool GetEnableDragMove(){ return m_canDragMoveView; }
	bool GetEnableBoxZoom(){ return m_canBoxZoom; }
    int PutData(const QVariant &jsonStr, CHG_DATA_MAP& chgdata);
public slots:
    QObject* QApp() {return qApp;};
    virtual QObject *EnableComponent(const QString& componentName, int ifvisiable =-1 );
    virtual QObject* ActiveWindow(){ return (QObject*)ActiveMdiChild(); };
    QObject* FileOpen(const QString& file_name, QString wnd_tag, int wnd_flags=0, QString replace_key="", QVariant args="");


    virtual QObject* Open(const QString& file_name, const QString& wnd_tag="", const QVariant& jobjArgs=QVariant());

    //-99 mean self window; -1 mean all windows;0,1,2 mean
    virtual QVariant DoCmd(QString wnd_name, QString file_name, QString script_code, int wnd_idx = -99);


    virtual QObject* ContentWindow(QString winID,QString file_name="");
    /*!
    \brief ������ʾ��������,�������±���Ӧ�������� <br>
    \param [in] file_list -  �򿪻�������������
    \param [in] screen_width -  ��Ļ����
    \param [in] mode -  �����ֶ�,������Ч
    \return - ����ID������,ʧ��ʱΪ������
    */
    QVariant OpenMultiScreen( QStringList file_list,int screen_width = 1280, int mode = 0 );
    int GEWinInPosition( const QString & file_name, int x, int y, int width, int height, int newwin = 1 );


    void SetData(const QVariant &jsonStr, bool reflash=false);
	///////加载图形到scene，不添加到view,返回对象数组，[0]是scene:scene对象, 之后是所有图元的CBaseData对象 ///////
	QObjectList Load(QString file_name);

	void EnableDragMove(bool enable);
	void EnableBoxZoom(bool enable);
public slots:

    void FileOpen(bool isBinary = false);
    void FileNewScriptDebuggerWin();
    void OnSubWindowActivated(QMdiSubWindow * window);

    
signals:
    void    DropEvent(QObject* curobj, QString obj_info);
protected:
    void closeEvent ( QCloseEvent * e );
    void dragEnterEvent(QDragEnterEvent * event);
    void dropEvent(QDropEvent * event);
private:
	//m_canDragMoveView and m_canBoxZoom are mutually exclusive.
	bool m_canDragMoveView;
	bool m_canBoxZoom;

};


#endif
