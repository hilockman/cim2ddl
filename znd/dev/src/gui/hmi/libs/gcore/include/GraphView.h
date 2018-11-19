
#if !defined G_CGRAPHVIEW_H 
#define G_CGRAPHVIEW_H

#include "Export.h"
#include <QMap>
#include <QGraphicsView>
#include <QtScript>
#include "BaseData.h"
class CGraphScene;


/*!
\ingroup  hmi   
\defgroup  Me Me 
*/


/*!
\brief  Me ����<br>
\brief ����ֱ�ӵ�������(Properties)����(Slots)���ź�(Signals)<br>   
\ingroup Me
*/

class CGTimer : public QTimer
{
    Q_OBJECT
    Q_PROPERTY(int timerId READ timerId  )
public:
    CGTimer(QObject * parent = 0) : QTimer(parent) {}
    ~CGTimer(){}

};

class  DLL_CLASS CGraphView : public QGraphicsView  
{
    Q_OBJECT
public:
    CGraphView(CGraphScene * scene, QWidget * parent = 0 );
    virtual ~CGraphView();
public:
    CGraphScene * Scene()	;
    int	VerticalScroll();
    int	HorizontalScroll();
public:
    virtual void    ShowTip(QPoint pos);
    virtual QObject*   GetItemInfo(QPoint pos, QString& msg);
    int EmitSignal(const QString& signal,const QVariant& value);
	void  ShowContextMenu(QPoint pos,QPoint global_pos);
protected:
    bool	eventFilter(QObject *obj, QEvent *ev);
	void    mouseDoubleClickEvent(QMouseEvent *e);
	void    mouseReleaseEvent(QMouseEvent* e);
    virtual void	paintEvent ( QPaintEvent * event );
    virtual void	keyPressEvent ( QKeyEvent * event ) ;
    virtual void	wheelEvent(QWheelEvent *event);
    virtual void	drawBackground(QPainter *painter, const QRectF &rect);
    virtual void	resizeEvent ( QResizeEvent *e );
    virtual void dropEvent(QDropEvent * event);
    virtual void contextMenuEvent( QContextMenuEvent *event);

signals:
    /*!
    \brief <br>
    */
    void    CustomEvent(QString signal, QVariant value);
    void    ItemChange(QString signal, QVariant value);
    void    DropEvent(QObject* curobj, QString obj_info);
    void    MatrixChg(float scale,int dx,int dy);
    /*!
    \brief <br>
    */
    void    Resized(int w,int h);
    /*!
    \brief DoubleClicked<br>
    \param [in] item_count -
    \param [in] obj_info -  :obj_type,icon_name,domain_id,app_id,record_id,column_id,val||extra_db;
    */
    void        DoubleClicked(QObject* curobj, QString obj_info);
    /*!
    \brief <br>
    */
    void        LeftClicked(QObject* curobj, QVariant obj_info,QObjectList olst);
    void	FocusOutEvent();
    /*!
    \brief  TipEvent<br>
    \param [in] obj_info -   :obj_type,icon_name,domain_id,app_id,record_id,column_id,val||extra_db;
    */
    void	TipEvent(QObject* obj,QString obj_info);
    /*!
    \brief <br>
    */
    void    MouseEvent( QObject* curobj, QVariant info);
	void    MouseRelease();
    /*!
    \brief <br>
    */
    void    ContextMenuClicked(QString menu_txt, QVariant act_info = "");
public slots:
    void Emit(const QString& signal,const QVariant& value){emit CustomEvent(signal,value);};
    /*!
    \brief <br>
    */
    void SetToolTip(const QString& tip){ if (!tip.isEmpty()) setToolTip(tip);};
    /*!
    \brief <br>
    */
    void SetGeometry(int x, int y, int w, int h) ;
    /*!
    \brief <br>
    */
    void PopupContextMenu(const QVariant& menuinfo,QMenu&  contextMenu);
    /*!
    \brief <br>
    */
    QObject* Model(){return (QObject *)(scene());};
    /*!
    \brief <br>
    */
    void    FitInView(const QRectF &rect, Qt::AspectRatioMode aspectRadioMode = Qt::IgnoreAspectRatio) ;
	int    GetFitInMode(){ return this->m_FitMode; }

    QObject* Self(){return this;};
    /*!
    \brief ��ǰ�����ļ���<br>
    */
    QString		CurrentFile( bool  is_abs_path = false );
    /*!
    \brief ���ڱ�ʶ<br>
    */
    QString		GetWndAlais()	{return m_WndAlais;};
    /*!
    \brief <br>
    */
    void		SetWndAlais(const QString& alais)	{m_WndAlais=alais;};
    /*!
    \brief ��������<br>
    \param [in] sx -  �������ű���
    \param [in] sy -  �������ű���
    */
    void	Scale(float sx, float sy)	{ scale(sx, sy);  EmitMatrixChg();};
    qreal	Scale()                     { return transform().m11();};
    /*!
    \brief �������<br>
    \param [in] sx -  ������α���
    \param [in] sy -  ������α���
    \param [in] sz -  z���α���
    */
    void	Shear(float sx, float sy, float sz) ;
    /*!
    \brief ������ת<br>
    \param [in] angle -  ������ת�Ƕ�
    */
    void	Rotate(float angle)	{ rotate(angle);};
    /*!
    \brief �����ƶ�<br>
    \param [in] dx -  �����ƶ�ƫ����
    \param [in] dy -  �����ƶ�ƫ����
    */
    void	Translate(float dx, float dy){ translate(dx,dy);};
    /*!
    \brief ����ָ���ʼ״̬<br>
    */
    void	ResetMatrix()		{resetMatrix();};
    /*!
    \brief ������ʾƽ��<br>
    \param [in] show_planes -  ��ʾƽ�� ����:show_planes="1,0,1,0" ��ʾ��0,2ƽ����ʾ;1,3����
    */
    void	SetShowPlane(const QString& show_planes, bool refresh=false);
    void    SetShowPlaneIndexs(QString  show_indexs, bool refresh=false);
    /*!
    \brief ��ȡ��ǰ��ʾ��ƽ��<br>
    \return  QString   ���ص�ǰ��ʾ��ƽ�� ����:"1,0,1,0" ��ʾ��0,2ƽ����ʾ;1,3����
    */
    QString GetShowPlane();
    /*!
    \brief ����QScript�ļ�<br>
    \param [in] fn �ļ��� ����data/scriptĿ¼��
    */
    virtual void    LoadScript(QString fn);
    /*!
    \brief <br>
    */

	QObject* AddPixmap(QString objName, QString pixName, qreal x, qreal y, QString userData = "");
    /*!
    \brief <br>
    */
    QObject* AddPolygon(QString objName, QString points,QString userData="");
    /*!
    \brief <br>
    */
    QObject* AddText(QString objName,QString text,int x,int y,QString userData="");
    /*!
    \brief  add a new item <br>
    \param [QVariantMap] jsonstr - the item para. { type-name:"g",template-name:"icon-dail",name:"obj1"}
    \param [in] x -  x,default is 0
    \param [in] y -  y,default is 0
    \param [QObject] parent -  parent item, default is null
    \return  QObject   return the new item
    */
    QObject* AddItem(QVariantMap jsonobj, int x=0, int y=0, QObject * parent=NULL);
	void AddItemObj(QObject* dataPtr);
    /*!
    \brief <br>
    */
	void RemoveItem(QObject* dataPtr);
    /*!
    \brief ���ô�����ʱ�������뵱ǰ��������������ͬ<br>
    \param [in] key -  ��������
    \param [in] value -  ����ֵ
    */
    void	Set(const QString & key, const QString & value) ;
    /*!
    \brief ��ȡ������ʱ���� <br>
    \param [in] key -  ��������
    \return  QString   ���ظñ���ֵ
    */
    QString Get( const QString & key );
    /*!
    \brief ִ��һ�νű����� <br>
    \param [in] script_code -  �ű�����
    */
    virtual QVariant DoCmd(QString script_code); //ִ�нű�

    /*!
    \brief like jquery_selectors <br>
    \param [QString] selector - jQuery selector, "*" ,"#id" ,".class" ,"[attribute]","[attribute=value]"
    */
    QObjectList Items(const QString& selector,QObject* parent=NULL,bool ifTopItem=false );
    /*!
    \brief ѡ�еĶ��� <br>
    \param [in] script_code -
    */
    QList<QObject*>	SelectedItems(); //
    /*!
    \brief �������еĶ��� <br>
    \param [in] order: Qt::SortOrder, -1 meas no particular order,0 AscendingOrder;1 desc ,2 ///��ѡ��˳��///
    */
    QObjectList Items(bool ifTopItem = false, bool ifSelected = false,int order=-1);
    /*!
    \brief ��ѡ�еĶ������û����������� <br>
    \param [in] propname - ������
    \param [in] value -    ����ֵ
    */
    bool SetCurrentItemProperty(const QString& propname, const QVariant& value);
    /*!
    \brief ��ȡѡ�еĶ��������ֵ <br>
    \param [in] propname - ������
    \return  QVariant   ���ظ�����ֵ
    */
    QVariant GetCurrentItemProperty(QString propname);
    /*!
    \brief ��ȡScriptEngine <br>
    \return  QObject   ���ظö���
    */
    void    EnableDebug(bool enable);
    virtual QObject* GetScriptEngine();
    /*!
    \brief ����id��ȡ���� <br>
    \return  QObject   ���ظö���
    */
    QObject* GetElement(QString id);
    QScriptValue  GetElementByScriptId(QString id);
    QObject* GetElementById(QString id);
	QObjectList FindItemPtrByKey(const QString& key);
    virtual QObject* CenterOn(QString itemName);
    /*!
    \brief ������������ <br>
    \return  QObject   ���ظö���
    */
    QObject* CreateAnimation(QObject * target, const QString & propertyName,const QVariant& startval="",const QVariant& endval="",int duration=-1,int loop=-1 );
    /*!
    \brief <br>
    */

    void    SetBackgroundImage(const QString& imageName, int mode = -1, bool onView=true);//mode:-1 original, 0 tile, 1 zoom ; onView: false: draw on scene background, true: draw on view background   
    /*!
    \brief <br>
    */
    void    SetBackgroundColor(const QString& color);
    /*!
    \brief <br>
    */
    bool    StartDrag(QObject* obj,const QString& msg);

    void	EmitMatrixChg(int value=0);
    /*!
    \brief <br>
    */

	QVariantMap CustomPropertys();
    /*!
    \brief <br>
    */
    bool SetProperty(const QString& propname,const QVariant& value);
    QVariant Property(QString name,bool allprop=true) ;

	QString	GetScript();

    QObject* Create(QString objname,const QVariant& args="");
private slots:
    void OnContextMenu();

public:

    QPixmap m_DrawPixmap;
    QPainter* m_Painter;
    bool	m_CasheMode;
    QMatrix	m_OldMatrix;

    QMap<QString, QString>   m_Vars; //���ڱ���
    QString m_WndAlais;//wndtag
    QRect m_FitRect;
    int m_FitMode;
	QString m_BackPixmapName ;
	int m_BackPixmapShowWay;
};

#endif // !defined(G_CGRAPHVIEW_H)
