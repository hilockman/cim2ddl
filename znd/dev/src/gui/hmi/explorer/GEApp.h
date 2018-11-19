
#ifndef _GEAPP_H
#define _GEAPP_H 

#include "Global.h"
#include "GApp.h"
#include "IHmiAppInterface.h"
#include "GFunc.h"

#ifdef WEBVIEW
class QWebSocketServer;
class QWebChannel;
#endif

class CGExplorerWnd;
typedef std::map<long, CGExplorerWnd*> GExplorerWndMap;


class CGEApp : public CGApp
{
    Q_OBJECT
public:
    CGEApp(int & argc, char ** argv);
    virtual ~CGEApp();
public slots:
    QObject*  GetActiveWnd();
    void Test(QString aaa);
    void InitWebChannel();
    //-99 mean self window; -1 mean all windows;0,1,2 mean
    QVariant DoCmd(QString wnd_name, QString file_name, QString script_code, int wnd_idx = -99);
    QObject* Open(const QString& file_name, const QString& wnd_tag="", const QString &arg="") ;
    QObject* NewWindow(const QVariant& arg);
public:
    virtual int ProcessChangeData();

public:
    virtual void NewGraphWindow(GDispInfo & graph_disp_info);
    void NewExplorerWnd(GDispInfo & graph_disp_info);
	void NewDesignerWnd(GDispInfo & graph_disp_info);
    void DeleteExplorerWnd(int graph_id);
    GExplorerWndMap *GetGEWndMap(void){return &m_pGExplorerWndMap;};

protected:
    virtual void timerEvent ( QTimerEvent* e );
public:
    int ProcessChangeData(const QString & tag,const QVariant& val);
    int GEWndInPosition( GDispInfo & graph_disp_info, QRect & rect , long wndid );

public:

    GExplorerWndMap m_pGExplorerWndMap;
    CGExplorerWnd *m_pActiveExplorerWnd;
#ifdef WEBVIEW
    QWebSocketServer* m_pServer;
    QWebChannel* m_pChannel;
#endif

};





class DaemonThread : public QThread
{
public:
    DaemonThread(CGEApp* app):QThread(),hmi_app(app)
    {
    };
    void run();
private:
    CGEApp* hmi_app;
};
#endif
