

#ifndef CGExplorerView_H
#define CGExplorerView_H 

#include "Global.h"
#include "GraphView.h"
#include "GraphScene.h"
#include "GraphItem.h"
#include "GApp.h"

class CGExplorerScene;
class CGWnd;

/*!
\ingroup  hmi
\defgroup  Me Me
*/

class CGExplorerView : public CGraphView
{
    Q_OBJECT
public:
    CGExplorerView(CGWnd *w,CGraphScene* scence,QWidget *parent=0, const char *name=0 ,Qt::WindowFlags f = 0);
    ~CGExplorerView();

public:
    virtual void ShowTip(QPoint pos);
    virtual QObject * GetItemInfo(QPoint pos, QString& msg);
public:
    void ShowWhatsThis( QString whatsthis_string , QPoint pos );
    QRect GetViewRect();
    void SetViewSize(int width,int height);

    void Advance(long time_ms);

    CGExplorerScene* GetGraphScene() {return m_pScene;};
    unsigned int GetCurThreadId();
    int ProcessChangeData(CHG_DATA_MAP& chg_data_map );
    void ProcessAhref( QObject* curobj);
    void AddQSObject();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *event);
    void wheelEvent(QWheelEvent *event);
    virtual void	resizeEvent ( QResizeEvent *e );
    virtual void contextMenuEvent( QContextMenuEvent *event);
signals:
    /*!
    \brief   <br>
    */
    void ChgDataEvent(CHG_DATA_MAP& chg_data_map);
    /*!
    \brief   <br>
    */
    void OnLoad();
    /*!
    \brief   <br>
    */
    void OnClose();
    /*!
    \brief   <br>
    */
    void DragEvent(QString jsonstr);
    /*!
    \brief   <br>
    */
    void TokenMoved(QObject* tokenObj);
    /*!
    \brief   <br>
    */
	void TokenMoveBegin(QObject* tokenObj);
public slots:
    int FileOpen(const QString &fileName, const QString& replace_key="", int wnd_flags=0, QVariant args="");
    /*!
    \brief   <br>
    */
    void SetArgs(QVariant args) {setProperty("__args__",args);};
    /*!
    \brief   <br>
    */
    QVariant GetArgs() {return property("__args__");};
    /*!
    \brief   <br>
    */

    QString GetKeyInfo();
    /*!
    \brief   <br>
    */
    QObject * GetParent(){return parent();};
    /*!
    \brief   <br>
    */
    void Free();
    /*!
    \brief   <br>
    */
    void Hide();
    /*!
    \brief   <br>
    */
    void Show();
    /*!
    \brief   <br>
    */
    void ZoomAll();
    /*!
    \brief   <br>
    */
    QObjectList FindItemPtr(QString tagName);
    /*!
    \brief   <br>
    */
    QVariantMap FindItemPtrByDev(QString devTagName);


    void OnNaviViewPosChg(float x,float y);
    /*!
    \brief   <br>
    */
    QString GetWndTitle();

    void    SetViewMode(QString mode);//mode="opengl" or "normal"

    //Area select
	void SetAreaSelectFlag(bool has_area_select);

	bool GetAreaSelectFlag() { return m_hasAreaSelect; };

	//{"x":"100", "y":"120","width":"600","height":"400"}
	QString GetAreaSelectRect();

    int EnableShowTopo(){return Scene()->GetTopoFlag();};
private slots:
    void TimeOut(); 
    void Close();
public:
    QRect m_ZoomRect;

private:
    CGExplorerScene *m_pScene;
    CGWnd *m_pGraphWnd;
    QPixmap m_DrawPixmap;
    QRect m_DrawArea;
    QString m_CurFile;
    QTimer *m_pTimer;
    long m_TimerCount;
    QString m_Args;
    bool m_hasAreaSelect;
    QRectF m_AreaSelectRect;
    QString m_OldFileName;
    char m_RegistName[64];
    bool m_BlockSignal;
    QPoint m_StartPos;
	QPointF m_LastMovePos;
    QPoint m_GlobalStartPos;
    QGraphicsPathItem* m_pHotItem;
    QGraphicsItem* m_pHotSrcItem;
    float m_SrcOpacity;
	QRubberBand* m_rubberBand;
	CPolylineItem* m_tokenLine;
    QSize m_lastSize;
    bool m_lastOpIsMove;
};

#endif
