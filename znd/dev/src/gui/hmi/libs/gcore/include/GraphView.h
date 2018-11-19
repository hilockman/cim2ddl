
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
\brief  Me 对象<br>
\brief 允许直接调用属性(Properties)、槽(Slots)、信号(Signals)<br>   
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
    \brief 当前画面文件名<br>
    */
    QString		CurrentFile( bool  is_abs_path = false );
    /*!
    \brief 窗口标识<br>
    */
    QString		GetWndAlais()	{return m_WndAlais;};
    /*!
    \brief <br>
    */
    void		SetWndAlais(const QString& alais)	{m_WndAlais=alais;};
    /*!
    \brief 画面缩放<br>
    \param [in] sx -  横向缩放比例
    \param [in] sy -  纵向缩放比例
    */
    void	Scale(float sx, float sy)	{ scale(sx, sy);  EmitMatrixChg();};
    qreal	Scale()                     { return transform().m11();};
    /*!
    \brief 画面变形<br>
    \param [in] sx -  横向变形比例
    \param [in] sy -  纵向变形比例
    \param [in] sz -  z变形比例
    */
    void	Shear(float sx, float sy, float sz) ;
    /*!
    \brief 画面旋转<br>
    \param [in] angle -  画面旋转角度
    */
    void	Rotate(float angle)	{ rotate(angle);};
    /*!
    \brief 画面移动<br>
    \param [in] dx -  横向移动偏移量
    \param [in] dy -  纵向移动偏移量
    */
    void	Translate(float dx, float dy){ translate(dx,dy);};
    /*!
    \brief 画面恢复初始状态<br>
    */
    void	ResetMatrix()		{resetMatrix();};
    /*!
    \brief 画面显示平面<br>
    \param [in] show_planes -  显示平面 例如:show_planes="1,0,1,0" 表示第0,2平面显示;1,3隐藏
    */
    void	SetShowPlane(const QString& show_planes, bool refresh=false);
    void    SetShowPlaneIndexs(QString  show_indexs, bool refresh=false);
    /*!
    \brief 获取当前显示的平面<br>
    \return  QString   返回当前显示的平面 例如:"1,0,1,0" 表示第0,2平面显示;1,3隐藏
    */
    QString GetShowPlane();
    /*!
    \brief 加载QScript文件<br>
    \param [in] fn 文件名 放在data/script目录下
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
    \brief 设置窗口临时变量，与当前画面生命周期相同<br>
    \param [in] key -  变量名称
    \param [in] value -  变量值
    */
    void	Set(const QString & key, const QString & value) ;
    /*!
    \brief 获取窗口临时变量 <br>
    \param [in] key -  变量名称
    \return  QString   返回该变量值
    */
    QString Get( const QString & key );
    /*!
    \brief 执行一段脚本命令 <br>
    \param [in] script_code -  脚本内容
    */
    virtual QVariant DoCmd(QString script_code); //执行脚本

    /*!
    \brief like jquery_selectors <br>
    \param [QString] selector - jQuery selector, "*" ,"#id" ,".class" ,"[attribute]","[attribute=value]"
    */
    QObjectList Items(const QString& selector,QObject* parent=NULL,bool ifTopItem=false );
    /*!
    \brief 选中的对象 <br>
    \param [in] script_code -
    */
    QList<QObject*>	SelectedItems(); //
    /*!
    \brief 返回所有的对象 <br>
    \param [in] order: Qt::SortOrder, -1 meas no particular order,0 AscendingOrder;1 desc ,2 ///按选中顺序///
    */
    QObjectList Items(bool ifTopItem = false, bool ifSelected = false,int order=-1);
    /*!
    \brief 给选中的对象设置或者增加属性 <br>
    \param [in] propname - 属性名
    \param [in] value -    属性值
    */
    bool SetCurrentItemProperty(const QString& propname, const QVariant& value);
    /*!
    \brief 获取选中的对象的属性值 <br>
    \param [in] propname - 属性名
    \return  QVariant   返回该属性值
    */
    QVariant GetCurrentItemProperty(QString propname);
    /*!
    \brief 获取ScriptEngine <br>
    \return  QObject   返回该对象
    */
    void    EnableDebug(bool enable);
    virtual QObject* GetScriptEngine();
    /*!
    \brief 根据id获取对象 <br>
    \return  QObject   返回该对象
    */
    QObject* GetElement(QString id);
    QScriptValue  GetElementByScriptId(QString id);
    QObject* GetElementById(QString id);
	QObjectList FindItemPtrByKey(const QString& key);
    virtual QObject* CenterOn(QString itemName);
    /*!
    \brief 创建动画对象 <br>
    \return  QObject   返回该对象
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

    QMap<QString, QString>   m_Vars; //窗口变量
    QString m_WndAlais;//wndtag
    QRect m_FitRect;
    int m_FitMode;
	QString m_BackPixmapName ;
	int m_BackPixmapShowWay;
};

#endif // !defined(G_CGRAPHVIEW_H)
