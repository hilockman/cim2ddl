#ifndef GRAPHSCENE_H
#define GRAPHSCENE_H

#include <QGraphicsScene>
#include <QtCore>
#include "Export.h" 
#include "BaseData.h"

class CGraphSvgReader;
class CScriptEngine;
class CGroupItem;
class CIconItem;
#ifdef QML
class CQmlEngine;
#endif

class DLL_CLASS  CGraphScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CGraphScene( QObject *parent = 0);
    virtual ~CGraphScene();
    virtual void    Reset();
    QList<QGraphicsItem *>      Items(const QPointF& pos,bool ifTopItem);
	QList<QGraphicsItem *>      Items(bool ifTopItem, bool ifSelected, int order = -1);//order: Qt::SortOrder, -1 meas no particular order
    QString	GetScript()				{return m_Script;};
    void	SetScript(const QString& script){m_Script=script;};

    QString	GetAlias()				{return m_Alias;};
    void	SetAlias(QString alias)	{m_Alias=alias;};
    void	SetWndPropFlags(int prop){m_WndPropFlag=prop;};
    int		GetWndPropFlags()		{return m_WndPropFlag;};
    int EmitSignal(const QString& signal,const QVariant& newPos);

    void    AddItem(QGraphicsItem* pItem,bool alltoscriptengine=true);
    void    AppendItemIdx(QGraphicsItem* pItem,bool alltoscriptengine=true);
	void    RemoveItemIdx(QGraphicsItem* pItem, bool alltoscriptengine = true);
signals:
    void ItemBeCreated(QObject* item);
public slots:

    /*!
    \brief like jquery_selectors <br>
    \param [QString] selector - jQuery selector, "*" ,"#id" ,".class" ,"[attribute]","[attribute=value]"
    */
    QObjectList Items(const QString& selector,QObject* parent=NULL,bool ifTopItem=false );

    int		GetBackColor()				{return	m_BackColor;};
    void	SetBackColor(int back_color)		{m_BackColor = back_color;};

    int		GetForeColor()				{return	m_ForeColor;};
    void	SetForeColor(int fore_color)		{m_ForeColor = fore_color;};

    int		GetBackPixmapFlag()			{return	m_BackPixmapFlag;};
    void	SetBackPixmapFlag( int back_pixmap_flag)	{m_BackPixmapFlag = back_pixmap_flag;};

    QString	GetBackPixmapName()			{return m_BackPixmapName;};
	void	SetBackPixmapName(QString back_pixmap_name);
	virtual int	GetPixmapShowWay()			{ return m_BackPixmapShowWay; };
    void	SetPixmapShowWay(char value)		{m_BackPixmapShowWay = value; };


    uint		GetRefreshInterval()			{return m_RefreshItv;};
    void	SetRefreshInterval(uint refresh_itv)		{m_RefreshItv = refresh_itv;};

    float	GetInitZoomFactor()			{return m_InitZoomFactor;};
    void	SetInitZoomFactor(float zoom_factor)	{m_InitZoomFactor = zoom_factor;};


    int		GetGraphFacID()				{return m_FacID;};
    void	SetGraphFacID(int fac_id)	{m_FacID=fac_id;};
    int		GetTopoFlag()				{return m_TopoFlag;};
    void	SetTopoFlag(int flag)		{m_TopoFlag=flag;};
    QString	GetWndTitle()	{return m_WndTitle;};
    void	SetWndTitle(const QString& title) {m_WndTitle=title;};

    QString	GetStationApp()	{return m_StationApp;};
    void	SetStationApp(const QString& station_app) {m_StationApp=station_app;};

    void	SetLayoutRect(const QRect& rect);
    QRect	GetLayoutRect()				{return m_LayoutRect;};

    void	SetGraphShowMode( int mode ){m_GraphShowMode = mode ;};
    int		GraphShowMode()			{return m_GraphShowMode;};
    int		WindowModality()		{ return m_WindowModality;};
    void	SetWindowModality(int flag)	{m_WindowModality=flag;};
    void	SetEnableScale(bool enable)	{m_EnableScale=enable;};
    bool	GetEnableScale()		{ return m_EnableScale;};
    void	SetMovable(bool enable)	{m_CanMove=enable;};
    bool	GetMovable()		{ return m_CanMove;};
    qreal	GetWindowOpacity()     {return m_Opacity;};
    void	SetWindowOpacity(qreal level){m_Opacity=level;};

	virtual int FileSave(const QString& fileName, bool isBinary = false);
	virtual int FileOpen(const QString& fileName, bool isBinary=false);

    virtual int LoadJsonModel(const QVariant& jsonobj );
    QString GetJsonModel();
    int     UpdateLayout(const QVariant&  jsonobj );


    int     IconSave(const QString& fileName);
    int     IconSaveToFile( CIconItem*  pIcon,const QString& fileName);
    int     IconLoad(const QString& fileName);
    static CIconItem* IconLoadFromFile(const QString& fileName, bool ifNotRefThenSkip=false);
    void	SetShowPlanes(const QBitArray& showPlanesMask);
    void	SetShowPlanes(const QString& show_planes);
    QBitArray GetShowPlanesMask() const {return m_ShowPlanesMask;};
    QString GetShowPlanesStr() ;
    int		GetCurPlane() const		{return m_currentPlane;};
    void	SetCurPlane(int plane);
    void	ShowPlane(int planeNo);
    void	HidePlane(int planeNo);
    void	DelPlane(int planeNo);
    void	MovePlane(int fromPlaneNo, int toPlaneNo);
    int 	GetFileType()               {return m_FileType;};
    void	SetFileType(int type)   {m_FileType=type;};
    int 	GetPlaneNums()               {return m_ShowPlanesMask.size();};
    void	SetPlaneNums(int planeNums);

    int 	GetStateNums()               {return m_StateNums;};
    void	SetStateNums(int nums)   {m_StateNums=nums;};
    void    SetPlaneNames(QString pNames){ m_planeNames = pNames; }	
    QString GetPlaneNames(){ return m_planeNames; }

    QString GetFileName()   {return m_filePathName;};
    void UpdateLinks(bool bypos=false);/////通过位置或者linkinfo更新连接关系///////

    QWidget* View();

    //QSA
    CScriptEngine*  GetScriptEngine()   {return m_pScriptEngine;};
    virtual void OnSelectionChanged();
#ifdef QML
    CQmlEngine*     GetQmlEngine() ;
#endif
    QGraphicsItem * GetElementById(QString id,bool ifcontain=false);

    virtual void	GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    virtual bool	SetProperty(const QString &property_name,const QVariant& value,bool allprop=true);
    QVariantMap CustomPropertys();
    QVariant Property(QString name,bool allprop=true);
    virtual void	UpdateScene();
    // json format
    QString GetUserData() const                 {return m_UserData; };
    void    SetUserData(const QString& userData){m_UserData=userData; };

    virtual QObject* CreateItem(const QString& jsonstr,int dx=0,int dy=0);
    int FitViewMode(){return m_FitViewMode;};
    void SetFitViewMode(int fitmode){  m_FitViewMode=fitmode;};
	int LinkMode(){ return m_LinkMode; };
	void SetLinkMode(int type){ m_LinkMode = type; };

    void    SetIfRef(bool ifref){m_IfRef=ifref;};
	bool    GetIfRef( ){ return m_IfRef ; };

    int GetSceneType()  {return m_SceneType;};
    void SetSceneType(int type) {m_SceneType=type;};

protected:
    int     AddNodes(const QJsonArray& nodes, QString jsontype );
    int     AddEdges(const QJsonArray& edges );
    int     UpdateItem(QGraphicsItem* item);
    virtual void drawBackground(QPainter* painter, const QRectF& rect);
    //void	CheckLink(QList<CLinkLineItem*> lstpLinkLineItem) const;
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent* e);
    virtual void dropEvent(QGraphicsSceneDragDropEvent * e);
public:
    CScriptEngine* m_pScriptEngine;
#ifdef QML
    CQmlEngine* m_pQmlEngine;
#endif
    bool	m_IsModified;
    bool	m_Visiable;

    uint	m_RefreshItv;
    float	m_InitZoomFactor;
    QString	m_Alias;
    QString	m_BackPixmapName;
    QString	m_filePathName;
    int		m_FacID;
    int     m_TopoFlag;
    int     m_BackPixmapShowWay;
    int		m_BackColor;
    int		m_ForeColor;
    int		m_BackPixmapFlag;
    QBrush  m_BGBrush;

    QBitArray	m_ShowPlanesMask;
    int		m_currentPlane;
    bool	m_IsDefaultCenter;
    QString	m_WndTitle;
    int		m_WndPropFlag;
    int		m_GraphShowMode;
    QString	m_StationApp;
    int  	m_WindowModality;			//  0 modal  ,1 no modal ,2 app modal
    bool	m_EnableScale;
    bool	m_FullScreen;
    QPoint	m_IconAlignCenter;
    QRect	m_LayoutRect;
    char	m_PosFlag;
    QString m_Script;
    int     m_FileType;
    int     m_StateNums;//
	QString m_planeNames;

    char		m_SysOsBit;
    char		m_SysByteSeq;
    QString     m_UserData;// json data
    int    m_FitViewMode;
	int     m_LinkMode;
    bool    m_CanMove;
    qreal   m_Opacity;
    bool m_IfRef;
    QJsonObject m_JsonModel;
    QMap<QString,QGraphicsItem*> m_NameItemMap;
    QMap<QString,QGraphicsItem*> m_NameItemModelMap;
    int m_SceneType;
    QString m_Layout;
    QList<QGraphicsItem*> m_SortedItems;

};


#endif
