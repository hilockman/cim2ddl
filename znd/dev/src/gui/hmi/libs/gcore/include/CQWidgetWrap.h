#ifndef CQWIDGETWRAP_H
#define CQWIDGETWRAP_H 

#include "Global.h"
#include "GFunc.h"
#include "BaseData.h"

#ifdef WEBVIEW
#include <QtWebEngineWidgets>
#endif
#ifdef QML
#include <QQuickView>
#endif

//////
class DLL_CLASS CGSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    CGSpinBox( QWidget * parent = 0) : QSpinBox(parent)    {
        connect(this,SIGNAL(valueChanged(const QString & )),this,SLOT(OnValueChanged(const QString &)));
    };
    ~CGSpinBox(){};
signals:
    void ValueChanged( QString text);
private slots:
    void OnValueChanged(const QString & text){emit ValueChanged(text);};
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
};

class DLL_CLASS CGDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    CGDoubleSpinBox(QWidget * parent = 0) : QDoubleSpinBox(parent) {
        connect(this, SIGNAL(valueChanged(const QString &)), this, SLOT(OnValueChanged(const QString &)));
    };
    ~CGDoubleSpinBox(){};
signals:
    void ValueChanged(QString text);
private slots:
    void OnValueChanged(const QString & text){ emit ValueChanged(text); };
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
};

class DLL_CLASS CGComboBox : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(QStringList itemList READ ItemList WRITE SetItemList)
public:
    CGComboBox( QWidget * parent = 0);
    ~CGComboBox(){     if(m_ContextMenu) delete m_ContextMenu; };
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public slots:
    QStringList ItemList() const  {
        QStringList l;
        for (int i = 0; i < count(); ++i)
            l << itemText(i);
        return l;
    }
    void SetItemList(const QStringList &l) {
        clear();
        insertItems(0, l);
    }
    void AddItem( const QString & text, QString userData ="" ) {addItem(text,userData);};
    void InsertItem( int index, const QString & text,QString userData ="") {insertItem(index,text,userData);};
    QString CurrentData() {return itemData(currentIndex()).toString();};
    int FindData(QVariant data, int role = Qt::UserRole) {return findData(data,role);};
    int FindText(QString text) {return findText(text);};

	void RemoveItem(int idx = -1){ if (idx == -1)removeItem(currentIndex()); else removeItem(idx); }
	/*menuArray  format is:
	menuArray = [{"text":"t1","data":"","icon":"","enable":1},
	{"text":"t2","data":"","icon":"","enable":1},
	{"text":"t3","data":"","icon":"","enable":1,"children":[{"text":"t4","data":"","icon":"","enable":1},{"text":"t5","data":"","icon":"","enable":1}]}];
	*/
	void ShowContextMenu(QVariant menuArray);

	void EnableCompleter(bool enabled = true);
	void SetShowAbove(bool above = true){ m_showAbove = above; }
	void SetViewHeight(int height){ m_viewHeight = height; };
signals:

    void CurrentIndexChanged(int index, QString text,QString data );
	void RequestContextMenu(int currentIndex, QString text, QString data);
	void ContextMenuClicked(QString menu_txt, QVariant act_info = "");

protected:
	void contextMenuEvent(QContextMenuEvent *event);
	void showPopup();
private slots:
    void OnItemChanged(int index)   {
        emit CurrentIndexChanged(index,currentText(),CurrentData());
    }
	void OnContextMenuClicked();
private:
	QPoint m_ContextMenuPos;
	QMenu* m_ContextMenu;
	bool m_showAbove;
	int m_viewHeight;
};


class CGListWidget : public QListWidget
{
    Q_OBJECT
    Q_PROPERTY(QStringList itemList READ ItemList WRITE InsertItems)
public:
    CGListWidget( QWidget * parent = 0);
    ~CGListWidget() ;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void OnContextMenuClicked();
    void OnItemClicked(QListWidgetItem* item){
        emit ItemClicked( item->text(),item->data(Qt::ToolTipRole).toString() );
    };
    void OnDBItemClicked(QListWidgetItem* item) {emit ItemDoubleClicked( item->text(),item->data(Qt::ToolTipRole).toString() );};
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};

public slots:
    void Init(int table_no,QString columns,int interval=-1){};
    QStringList ItemList() const  {
        QStringList l;
        for (int i = 0; i < count(); ++i)
            l << item(i)->text();
        return l;
    };
    void InsertItems(const QStringList &l,int row=0) { insertItems (row, l); };
    void InsertItem(int row, const QString & text, const QString & data = "", const QString & icon = "", const bool & checkable = false, const bool & checked = false);
    QString CurrentText() { return currentItem()? currentItem()->text():""; };
    QString CurrentData() { return currentItem() ? currentItem()->data(Qt::ToolTipRole).toString():""; };
    QStringList CheckedRows();
    QList< QVariant> ItemInfo(int row);
    void RemoveItem(int row =-1) {
        if (row==-1) row=currentRow () ;
        takeItem ( row );
    } ;
    void SetItemData(int row, int role, QVariant value);
    QVariant ItemData(int row, int role);
    void SetItem(int row, const QString & text,const QString & data) {
        if (row==-1) row=currentRow () ;
        if (item(row)==NULL) return;
        item(row)->setText(text);
        item(row)->setData(Qt::ToolTipRole,data);
    }
    void SetIconSize(int w,int h){setIconSize(QSize(w,h));};
    QObject* HorizontalScrollBar();
    QObject* VerticalScrollBar();
    void  ShowContextMenu(QVariant menu);
signals:
    void ItemClicked( QString text,QString data );
    void ItemDoubleClicked( QString text,QString data );
    void DragEvent(QString jsonstr);
    void RequestContextMenu(int index, QString text, QString data);
    void ContextMenuClicked(QString menu_txt, QVariant act_info = "");
private:
    QPoint m_StartPos;
    QPoint m_ContextMenuPos;
    QMenu* m_ContextMenu;
};
class CGTreeItemIndex:  public QObject
{
    Q_OBJECT
public:
    CGTreeItemIndex(QWidget * parent = 0):QObject(parent){};
    QTreeWidgetItem* m_pItem;
};

class DLL_CLASS CGTreeWidget : public QTreeWidget
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGTreeWidget( QWidget * parent = 0) ;
    ~CGTreeWidget(){if(m_ContextMenu) delete m_ContextMenu;};
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
	void contextMenuEvent(QContextMenuEvent *event);
public slots:
/* data format is string of jsonArray:
"[{
"text":"","data":"", "id":"","expanded":"","icon":"","checked":"","children":[{"text":"","data":"", "id":"","expanded":"","icon":"","checked":""}]
},
{"text":"","data":"", "id":"","expanded":"","icon":"","checked":""}]"
*/
    void LoadData(const QString& data, const QString& id,const QString& pid);
    bool Load(const QVariant& data);

	QString Data();//jsonArray to str
    void Init(int table_no,QString columns,int interval=-1);
    void SetHeaderLabels( const QStringList & labels ) { setHeaderLabels ( labels ); };
    void SetColumnWidth(int column, int width)  {setColumnWidth(  column,   width);};

    void SetChildIndicatorPolicy(int type){
        if (currentItem())
            currentItem()->setChildIndicatorPolicy( (QTreeWidgetItem::ChildIndicatorPolicy)type);
    };
    QObject* AddItem( const QStringList & strings,const QStringList & datas,bool top_level=true, bool has_indicator=true);

    void AddItem(QString parent_name, const QStringList & strings,const QStringList & datas, bool has_indicator=true);

    int ChildCount() const
    {
        if (currentItem())
            return currentItem()->childCount();
        return 0;
    };

	QString CurrentText(int column = 0) { if (currentItem())return currentItem()->text(column); else return ""; };

    QStringList CurrentItemInfo(int column=0);
    QList< QVariant> SelectedItemInfo(int column=0);
    void TakeChildren() { if (currentItem()) currentItem()->takeChildren(); };
    void RemoveItem ( int row =-1)    {
        if (row==-1 && currentItem()!=NULL)
            row=indexOfTopLevelItem(currentItem());
        takeTopLevelItem( row);
    } ;

	void RemoveCurrentItem(){
		if (currentItem() == NULL)
			return;
		if (currentItem()->parent() == NULL)
			RemoveItem();
		else
			currentItem()->parent()->takeChild(currentIndex().row());
	};
    int CurrentColumn() {return currentColumn();};
    void SetItem(int row,int column, const QString & text,const QString & data,QString icon="",QString color="");
    void SetItemColor(int row,int column, QString icon="",QString color="");
    QList< QVariant> ItemInfo(int row,int column);
    void SortByColumn ( int column, int order ) {sortByColumn(column,(Qt::SortOrder)order);};	
    void SetCurrentItem(int topIdx, int column, int childIdx = -1 );
    QWidget* HorizontalScrollBar();
    QWidget* VerticalScrollBar();
    void SetItemWidget(QObject* idx, int column, QObject * widget,bool columnSpanned=true);
	void SetItemExpanded(int index, bool expand);
	//Note that checkable items need to be given both a suitable set of flags and an initial state, indicating whether the item is checked or not. 
	void SetItemFlags(int index = -1, int column = -1, int flags = Qt::NoItemFlags, bool checked = false);
	int ItemChecked(int index = -1, int column = -1);
	QList< int> FindItem(QString text, int column = 0);
	void ShowContextMenu(QVariant menuArray);
    void SetItemData(int row, int column, int role, QVariant value);
    QVariant ItemData(int row,int column, int role);
	/*
	pathType = "action" = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON ) = "/res/ico/actions/"
	pathType = "images" = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP) = "/data/images/"
	*/
	void SetIconPath(QString pathType);
signals:
    void ItemClicked( int index,int column,QString text,QString data );
    void ItemDoubleClicked(int index,int column, QString text,QString data );
    void ItemExpanded(int index,  QString text,QString data );
    void DragEvent(QString jsonstr);
	void RequestContextMenu(int index, int column, QString text, QString data);
	void ContextMenuClicked(int index, int column, QString menu_txt, QVariant act_info = "");

private slots:
    void OnItemClicked(QTreeWidgetItem* item,int column){
        setCurrentItem(item);
        emit ItemClicked(indexOfTopLevelItem(item), column,item->text(column),item->data(column,Qt::ToolTipRole).toString() );
    };
    void OnDBItemClicked(QTreeWidgetItem* item,int column) {emit ItemDoubleClicked(indexOfTopLevelItem(item),column, item->text(column),item->data(column,Qt::ToolTipRole).toString() );};
    void OnItemExpanded ( QTreeWidgetItem * item ) {
		if (indexOfTopLevelItem(item) >= 0)
		{
			setCurrentItem(item);
			emit ItemExpanded(indexOfTopLevelItem(item), item->text(0), item->data(0, Qt::ToolTipRole).toString());
		}
	};
	void OnContextMenuClicked();
private:
    void  parseObject(const QJsonObject &object,int column=0, QTreeWidgetItem *parent=NULL);
    void  parseJsonValue(const QJsonValue &jsonValue, int column=0, QTreeWidgetItem *node=NULL);
	QJsonObject itemToData(QTreeWidgetItem * item);
    QPoint m_StartPos;
	QPoint m_ContextMenuPos;
	QMenu* m_ContextMenu;
	QString m_iconPath;
};

class CGTableDelegate:public QStyledItemDelegate
{
    Q_OBJECT
public:
    enum ITEM_TYPE{ defaule = 0, combox, checkcombobox, colordlg, filedlg ,checkbox,spinbox};
    CGTableDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,  const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const;
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
	void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const;
protected:
    virtual  bool eventFilter(QObject *object, QEvent *event);
};

class CGTableWidget : public QTableWidget
{
    Q_OBJECT
    Q_PROPERTY(bool showRowHeader READ GetShowRowHeader WRITE SetShowRowHeader)
    Q_PROPERTY(bool showColumnHeader READ GetShowColumnHeader WRITE SetShowColumnHeader)
    Q_PROPERTY(int rowHeight READ GetRowHeight WRITE SetRowHeight)
    Q_PROPERTY(int defaultAlignment READ GetDefaultAlignment WRITE SetDefaultAlignment)
    Q_PROPERTY(QString horizontalLabels READ GetHorizontalLabels WRITE SetHorizontalLabels)
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGTableWidget( QWidget * parent = 0);
    ~CGTableWidget();
    bool GetShowRowHeader(){return  verticalHeader()->isVisible();};
    void SetShowRowHeader(bool show){verticalHeader()->setVisible(show);};
    bool GetShowColumnHeader(){return  horizontalHeader()->isVisible();};
    void SetShowColumnHeader(bool show){horizontalHeader()->setVisible(show);};
    int  GetRowHeight(){return verticalHeader()->defaultSectionSize();};
    void SetRowHeight(int rowheight){verticalHeader()->setDefaultSectionSize(rowheight);};
    int  GetDefaultAlignment(){return horizontalHeader()->defaultAlignment();};
    void SetDefaultAlignment(int rowheight){horizontalHeader()->setDefaultAlignment(Qt::Alignment(rowheight));};

public slots:
    /* columnsInfoJsonarray format is:
      [{"field":"loginname", "width":"120","headerAlign":"center","allowSort":"true","text":"loginname"},
      {"field":"age", "width":"120","headerAlign":"center","allowSort":"true","text":"age"}]
    */
    void SetColumns(const QVariant& columnsInfo);
	void SortByColumn(int column, int order = Qt::AscendingOrder) { this->sortItems(column, (Qt::SortOrder)order); };
	QVariantList Data();//dataJsObjarray
    int LoadData(const QString& dataJsonarray);
    int SetAllItems( int nRows, int nCols, const QList<QVariant> & txtList, const QList<QVariant> & strList=QList<QVariant>());

    QObject* HorizontalHeader() { return horizontalHeader();};
    QObject* VerticalHeader()  { return verticalHeader();};

	/*
	// mode: QHeaderView::ResizeMode  
QHeaderView::Interactive	0	
QHeaderView::Fixed	2	
QHeaderView::Stretch	1	
QHeaderView::ResizeToContents 3
	// header: h or v,
	*/
	void SetHeaderResizeMode(int mode, QString header="h", int idx=-1 );
    void SetHorizontalLabels( const QString & labels ){SetHorizontalHeaderLabels(labels.split(","));m_HLabels=labels;};
    void SetHorizontalHeaderLabels( const QStringList & labels ) { setHorizontalHeaderLabels ( labels );};
    QString  GetHorizontalLabels(  ) {return m_HLabels;};
    void SetVerticalHeaderLabels( const QStringList & labels ) { setVerticalHeaderLabels ( labels );};
    void SetColumnWidth( int column, int width) { setColumnWidth ( column,width);};
    void SetRowHeight( int row, int height ) { setRowHeight ( row, height );};
	//iconPath is SMARTSYS_HOME/res/ico/
    void SetItem(int row, int column,const QVariant &txt,const QVariant &usr_data="", const QString & iconFile = "");
    void SetCellMenu( int row,int column,const QMap<QString, QVariant>& menu, bool multiSelect = false);
	//enum   CGTableDelegate::ITEM_TYPE{ defaule = 0, combox, checkcombobox, colordlg };
    void SetCellWidget(int row, int column, QVariant ItemType, QVariant data="");
    QStringList ItemData(int row=-1,int column=-1);
    int GetCurrentRow(){ return currentRow();};
    int GetCurrentColumn(){ return currentColumn();};
    void SetTextAlignment(int row=-1,int column=-1,int align_type=Qt::AlignCenter);
	//Note that checkable items need to be given both a suitable set of flags and an initial state, indicating whether the item is checked or not. 
    void SetItemFlags(int row=-1,int column=-1,int flags=Qt::NoItemFlags, bool checked = false);
	int ItemChecked(int row = -1, int column = -1);
    void Clear( int row=-1,int column=-1);
    void CreateHtmlTableFromModel();
    void Print();
    QObject* HorizontalScrollBar();
    QObject* VerticalScrollBar();
	/*menuArray  format is:
	menuArray = [{"text":"t1","data":"","icon":"","enable":1},
	 {"text":"t2","data":"","icon":"","enable":1},
	 {"text":"t3","data":"","icon":"","enable":1,"children":[{"text":"t4","data":"","icon":"","enable":1},{"text":"t5","data":"","icon":"","enable":1}]}];
	*/
	void ShowContextMenu(QVariant menuArray);
    void SetItemData(int row, int column, int role, QVariant value);
    QVariant ItemData(int row,int column, int role);//text role is 0--Qt::DisplayRole, data role is 5--Qt::WhatsThisRole
    QStringList SelectedRanges();

signals:
    void ItemClicked( int row,int column,QString text,QString data );
    void ItemDoubleClicked(int row,int column, QString text,QString data );
    void DragEvent(QString jsonstr);
	void RequestContextMenu(int rowNo, int columnNo);
	void ContextMenuClicked(QString menu_txt, QVariant act_info = "");
protected:
	void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void OnItemClicked(QTableWidgetItem* item );
    void OnDBItemClicked(QTableWidgetItem* item );
	void OnContextMenuClicked();
private:
    CGTableDelegate * m_pTableDelegate;
    bool IsValid(int row,int column);
    QTableWidgetSelectionRange GetOpRange( int row , int column);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    QPoint m_StartPos;
    QJsonArray m_ColumnsInfo;
    QMap<int,QString> m_ColIdxMap;
	QPoint m_ContextMenuPos;
	QMenu* m_ContextMenu;
    QString  m_HLabels;
};

//////
class CGTextBrowser : public QTextBrowser
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGTextBrowser( QWidget * parent = 0): QTextBrowser(parent){};
    ~CGTextBrowser(){};
public slots:
    void SetSource(QString url);
    void Print();
};
///
class DLL_CLASS CGLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QString data READ GetData WRITE SetData)
    Q_PROPERTY(QString pixmapName READ GetPixmap WRITE SetPixmap)
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGLabel (const QString& text, QWidget * parent = 0, Qt::WindowFlags f = 0 );
    ~CGLabel(){};
    QString m_Data;
    QMovie *m_pMovie;
protected:
    bool eventFilter(QObject *obj, QEvent *e);
public slots:
    QString GetPixmap(){return m_pixmapName;};
    void SetPixmap(const QString &pixname);
    void SetData(const QString &data1){m_Data=data1;};
    QString GetData(){return m_Data;};
signals:
    void Clicked( QString text,QString data );
    void DBClicked( QString text,QString data );
private:
    QString m_pixmapName;
};


#ifdef WEBVIEW
////////////
/// \brief The CGWebView class
class CGWebPage : public  QWebEnginePage
{
    Q_OBJECT
public:
    CGWebPage( QObject * parent = 0):QWebEnginePage(parent){};
    ~CGWebPage(){};
public slots:
};

class CGWebView : public  QWebEngineView
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGWebView( QWidget * parent = 0);
    ~CGWebView(){};
public slots:
    void Load(const QString& url)   {load(QUrl(url));};
    QWebEnginePage *	Page() const {return page();};
    void DoCmd(const QString & scriptSource){page()->runJavaScript( scriptSource);};
    void Print();
};
#endif

#ifdef QML
class DLL_CLASS CQuickView : public QQuickView
{
    Q_OBJECT
public:
    CQuickView(QWindow *parent = 0) :QQuickView(parent) { setResizeMode(QQuickView::SizeRootObjectToView); };
    CQuickView(QQmlEngine * engine, QWindow *parent = 0) :QQuickView(engine, parent) { setResizeMode(QQuickView::SizeRootObjectToView); };
    ~CQuickView() {};
protected:
    void mouseDoubleClickEvent(QMouseEvent * event);
public slots:
    QVariant Call(QString funcName,QVariant val0 = QVariant(),QVariant val1 = QVariant(),
                  QVariant val2 = QVariant(),QVariant val3 = QVariant(),QVariant val4 = QVariant(),
                  QVariant val5 = QVariant(),QVariant val6 = QVariant(),QVariant val7 = QVariant(),
                  QVariant val8 = QVariant(),QVariant val9 = QVariant());

};
#endif

class DLL_CLASS CGMenuBar : public QMenuBar
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGMenuBar(QWidget * parent = 0);
    ~CGMenuBar() {};
public slots:
    int AddMenu(QMap<QString, QVariant> menuActionsMap);
    void onActionTriggered();
signals:
    void actionTriggered(QString actionName);
};

class DLL_CLASS CGPushButton : public QToolButton
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
	void SetIcon(QString iconfilePath, QString pathType = "images");
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
    QObject* SetMenu(QVariant menuinfo);
public:
    CGPushButton(QString text="", QWidget * parent = 0);
    ~CGPushButton() {};
signals:
    void MenuTriggered(QString text,QString data);
private slots:
    void iconChged(int);
    void OnMenuTriggered(QAction * action);
private:
    QMovie* m_pMovie;
};

class DLL_CLASS CGToolBar : public QToolBar
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
    void Clear(){clear();};
    QObject* AddAction(const QVariant & args){
        QJsonObject jobj;
        if (args.type() == QVariant::Map)
            jobj = QJsonObject::fromVariantMap(args.toMap());
        else if (args.canConvert<QJsonObject>())
            jobj = args.toJsonObject();
        QAction* act =addAction(QPixmap(UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON)+jobj["icon"].toString()),jobj["text"].toString());
        act->setData(args);
        act->setToolTip(jobj["tip"].toString());
        return act;
    };
    void AddWidget(QWidget *widget) {addWidget( widget);};
public:
    CGToolBar(QString title="", QWidget * parent = 0):QToolBar(title,parent){};
    ~CGToolBar() {};
};

class DLL_CLASS CGTabBar : public QTabBar
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGTabBar(QWidget * parent = 0) ;
	~CGTabBar() {};
public slots:
    int AddTab(const QString & text,const QString & iconName=""  );
    void RemoveTab(int index=-1);

};

class DLL_CLASS CGTabWidget : public QTabWidget
{
    Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
    CGTabWidget(QWidget * parent = 0) ;
    ~CGTabWidget() {};
    virtual void dropEvent(QDropEvent * event);
    virtual void contextMenuEvent(QContextMenuEvent * event);
public slots:
    int AddTab(QObject* widget,const QString & text,const QString & iconName=""  );
    void RemoveTab(int index=-1);
    QWidget *	Widget(int index=-1);
};

class DLL_CLASS CGDateEdit : public QDateEdit
{
	Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
	CGDateEdit(QWidget * parent = 0){};
	~CGDateEdit() {};
public slots:
	void SetDate(const QString &date = "", const QString & format = "");
	QString GetDate(){ return date().toString(displayFormat()); }
};

class DLL_CLASS CGTimeEdit : public QTimeEdit
{
	Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
	CGTimeEdit(QWidget * parent = 0){};
	~CGTimeEdit() {};
public slots:
    void SetTime(const QString &time="", const QString & format="");
	QString GetTime(){ return time().toString( displayFormat() ); }
};

class DLL_CLASS CGCalendarWidget : public QCalendarWidget
{
	Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
	CGCalendarWidget(QWidget * parent = 0){ connect(this, SIGNAL(selectionChanged()), this, SLOT(dateChanged())); }
	~CGCalendarWidget() {};
signals:
    void	SelectionChanged(int year, int month, int day);
private slots:
    void dateChanged();
};

class DLL_CLASS CGProgressBar : public QProgressBar
{
	Q_OBJECT
public:
	CGProgressBar(QWidget * parent = 0);
	~CGProgressBar() {};
public slots:   
    QString GetTag();
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
};

class DLL_CLASS CGTextEdit : public QTextEdit
{
	Q_OBJECT
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};
public:
	CGTextEdit(QWidget * parent = 0);
    ~CGTextEdit() ;
public slots:
	void SetMaxLength(int maxLength);
private slots:
	void TextChanged();
private:
	int m_maxLength;
};

class DLL_CLASS CGLineEdit : public QLineEdit
{
	Q_OBJECT
public slots:
	CBaseData* Q() { return  g_dataPtr(graphicsProxyWidget()); }
	void SetProperty(const QString&  name, const QVariant & value){ setProperty(name.toLocal8Bit().data(), value); };
	QVariant  Property(const QString&  name) { return property(name.toLocal8Bit().data()); };
public:
	CGLineEdit(QWidget * parent = 0);
	~CGLineEdit();
protected:
	void keyPressEvent(QKeyEvent * event);
public slots:
	void SetPasteEnabled(bool beEnable);
private:
	bool m_pasteEnable;
};

class DLL_CLASS CGFontEditWidget : public QWidget
{
	Q_OBJECT
public:
	CGFontEditWidget(QWidget *parent = 0);
	bool eventFilter(QObject *obj, QEvent *ev);
public slots:
	//for script
QString GetFontString(){ return m_font.toString(); }
void SetFont(QString fontString){
	QFont f;
	if (f.fromString(fontString))
		setValue(f);
}

public Q_SLOTS:
	void setValue(const QFont &value);
private Q_SLOTS:
	void buttonClicked();
Q_SIGNALS:
	void valueChanged(const QFont &value);
private:
	QString fontValueText(const QFont &f);
	QIcon fontValueIcon(const QFont &f);
	QPixmap fontValuePixmap(const QFont &font);
	QFont m_font;
	QLabel *m_pixmapLabel;
	QLabel *m_label;
	QToolButton *m_button;
};
//
class DLL_CLASS QSwitchButton : 	public QAbstractButton
{
    Q_OBJECT
    Q_PROPERTY(qreal position READ position WRITE setPosition)
    //Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY(int checkedStyle READ GetCheckedStyle WRITE SetCheckedStyle)
    Q_PROPERTY(QString bgPixmap READ GetBgPixmap WRITE SetBgPixmap)
    Q_PROPERTY(QString forePixmap READ GetForePixmap WRITE SetForePixmap)       

    enum CHECK_TYPE
    {
        NORMAL = 0,SLIDEH,SLIDEV,TWINKLE
    };
public slots:
    CBaseData* Q() {   return  g_dataPtr(graphicsProxyWidget()) ; }
    void SetProperty(const QString&  name, const QVariant & value){setProperty( name.toLocal8Bit().data(),  value);};
    QVariant  Property(const QString&  name) {return property( name.toLocal8Bit().data() );};

public:
    QSwitchButton(QWidget *parent = 0);
    ~QSwitchButton();
    QSize sizeHint() const;
    QString GetBgPixmap(){return m_pixmapBgPath;};
    void SetBgPixmap(QString png) ;
    QString GetForePixmap(){return m_pixmapForePath;};
    void SetForePixmap(QString png) ;
    int GetCheckedStyle(){return m_CheckedStyle; };
    void SetCheckedStyle(int style) ;
    qreal position() const {return pos;};
    void drawSlider(QPainter *painter);
    void setInitState(bool checked);

    qreal opacity() const {return m_opacity;};
    void setOpacity(qreal opacity){m_opacity= opacity;};

public slots:
    void animate(bool);
    void setPosition(qreal value);

protected:
    bool hitButton(const QPoint& p) const;
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

public:
    QString     m_pixmapBgPath;
    QString     m_pixmapForePath;
    QPixmap     m_pixmapBg;
    QPixmap     m_pixmapFore;
    int         m_CheckedStyle;
    QPropertyAnimation *animation;

    qreal pos;
    QRectF sliderShape;
    qreal m_opacity;

};


class CTreeEntry;
class CGTreeModel:public QAbstractItemModel
{
    Q_OBJECT
public:
    enum ItemBoxRole{
        TypeRole = Qt::UserRole+1,
        IsCommonRole ,
        TypeNameRole
    };
    CGTreeModel(QObject * parent = 0);
    ~CGTreeModel();
    virtual bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const ;
    virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
    virtual QModelIndex parent ( const QModelIndex & index ) const ;
    virtual int columnCount ( const QModelIndex & parent = QModelIndex() )  const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
public slots:
    void SetHeader(QStringList slist);
   // void SetCurData(int column,int role ,QVariant& data);
    void InsertItem(QString itemName, QString itemType, QString classType, QString tip = QString(""), QString fileIconName = "");
    bool Load(const QVariant& data);

private:
    CTreeEntry* m_pRootEntry;

};

class CTreeProxyModel;
class CGTreeView : public QTreeView
{
    Q_OBJECT
public:
    CGTreeView(QWidget* parent =0);
    ~CGTreeView() {};
public slots:
    QObject* Model(){return &m_sourceModel;};
    void  OnFilterChanged(const QString& str);
    void SetHeaderLabels( const QStringList & labels )  { m_sourceModel.SetHeader( labels ); };
    void SetColumnWidth(int column, int width)          {setColumnWidth(  column,   width);};
    bool Load(const QVariant& data)                     {return m_sourceModel.Load(data);};
    void ShowContextMenu(QVariant menuArray);
signals:
    void SIGItemSelected(const QString& itemName, int type);
    void ItemClicked( int index,int column,QString text,QString data );
    void ItemDoubleClicked(int index,int column, QString text,QString data );
    void ItemExpanded(int index,  QString text,QString data );
    void DragEvent(QString jsonstr);
    void RequestContextMenu(int index, int column, QString text, QString data);
    void ContextMenuClicked(int index, int column, QString menu_txt, QVariant act_info = "");
protected:
    void contextMenuEvent(QContextMenuEvent* event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void OnClicked ( const QModelIndex& index );
    void OnDbClicked ( const QModelIndex& index );
    void OnContextMenuClicked();
private:
    bool m_iconMode;
    int isFileExist(QString symbolName);
    CTreeProxyModel* m_proxyModel;
    CGTreeModel m_sourceModel;
    QPoint m_StartPos;
    QPoint m_ContextMenuPos;
    QMenu* m_ContextMenu;
};

class DLL_CLASS CGCheckBox : public QCheckBox
{
	Q_OBJECT
	public slots:
	CBaseData* Q() { return  g_dataPtr(graphicsProxyWidget()); }
	void SetProperty(const QString&  name, const QVariant & value){ setProperty(name.toLocal8Bit().data(), value); };
	QVariant  Property(const QString&  name) { return property(name.toLocal8Bit().data()); };
public:
	CGCheckBox(QWidget * parent = 0){};
	~CGCheckBox() {};
public slots:
void SetIcon(QString iconFile, QString pathType = "action");
	void SetIconSize(int w, int h);
};


#endif
