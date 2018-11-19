

#include "CQWidgetWrap.h"
#include "Global.h"
#include <QtPrintSupport>
#include "IconMng.h"
#include "widgets/qxtcheckcombobox.h"
#include "WidgetItem.h"

//
void  g_ShowContextMenu(QWidget* widget,QMenu* m_ContextMenu,QPoint& m_ContextMenuPos,QVariant showmenu,bool exec=true)
{
    m_ContextMenu->clear();
    QList<QVariant> tmplist = showmenu.toList();
    if (!tmplist.isEmpty())
    {
        for (int i = 0; i < tmplist.size(); i++)
        {
            QJsonObject obj;
            QVariant qPara = tmplist[i];
            if (qPara.type() == QVariant::Map)
            {
                obj = QJsonObject::fromVariantMap(qPara.toMap());
            }
            else
            {
                obj = UnqFunc()->Str2Json(qPara.toString());
            }
            if (obj.isEmpty())
            {
                m_ContextMenu->addSeparator();
                continue;
            }
            QString menu_txt = obj["text"].toString();
            QVariant menu_data = obj["data"].toVariant();
            QString iconFile = obj["icon"].toString();
            bool enable = obj["enable"].toInt();
            QString tip = obj["tip"].toString();
            QString pathName;
            UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, iconFile, pathName);// m_PathTypeNameMap[PATH_TYPE_ICONSET] = GetSysHome()+spt+"res"+spt+"ico"+spt;

            if (obj["children"].isNull())
            {
                QAction *act = m_ContextMenu->addAction(menu_txt, widget, SLOT(OnContextMenuClicked()));
                act->setData(menu_data);
                act->setEnabled(enable);
                act->setIcon(QIcon(pathName));
                act->setToolTip(tip);
            }
            else
            {
                QMenu* menu = new QMenu(menu_txt , exec?widget:0);
                menu->setIcon(QIcon(pathName));
                menu->setToolTip(tip);
                QList<QVariant> childMenus = obj["children"].toVariant().toList();
                for (int j = 0; j < childMenus.size(); j++)
                {
                    QJsonObject childObj;
                    QVariant childPara = childMenus[j];
                    if (childPara.type() == QVariant::Map)
                    {
                        childObj = QJsonObject::fromVariantMap(childPara.toMap());
                    }
                    else
                    {
                        childObj = UnqFunc()->Str2Json(childPara.toString());
                    }
                    if (childObj.isEmpty())
                    {
                        menu->addSeparator();
                        continue;
                    }
                    QString menu_txt = childObj["text"].toString();
                    QVariant menu_data = childObj["data"].toVariant();
                    QString iconFile = childObj["icon"].toString();
                    bool enable = childObj["enable"].toInt();
                    QString tip = childObj["tip"].toString();
                    QAction *childAct = menu->addAction(menu_txt, widget, SLOT(OnContextMenuClicked()));
                    childAct->setData(menu_data);
                    childAct->setEnabled(enable);
                    QString pathName;
                    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, iconFile, pathName);// m_PathTypeNameMap[PATH_TYPE_ICONSET] = GetSysHome()+spt+"res"+spt+"ico"+spt;
                    childAct->setIcon(QIcon(pathName));
                    childAct->setToolTip(tip);
                }
                m_ContextMenu->addMenu(menu);
            }
        }
    }
    if(!exec) return;

    QGraphicsProxyWidget* proxyWidget=widget->graphicsProxyWidget();

    //m_ContextMenu->popup(m_ContextMenuPos);
    //return ;
    if (proxyWidget)
    {
        QGraphicsView* pView = proxyWidget->scene()->views().first();

        m_ContextMenu->setParent(pView);
        m_ContextMenuPos += proxyWidget->scenePos().toPoint();
        if (pView->parent()->inherits("QDockWidget") || (pView->windowFlags() & Qt::Dialog) > 0)
            m_ContextMenuPos +=  QPoint(0, m_ContextMenu->height() / 2);
    }
    m_ContextMenu->popup(m_ContextMenuPos);
    if (proxyWidget)
    {
		m_ContextMenuPos -= proxyWidget->scenePos().toPoint();
		QGraphicsView* pView = proxyWidget->scene()->views().first();
		if (pView->parent()->inherits("QDockWidget") || (pView->windowFlags() & Qt::Dialog) > 0)
            m_ContextMenuPos -= QPoint(0, m_ContextMenu->height() / 2);
    }
}
//
CGComboBox::CGComboBox( QWidget * parent  ) : QComboBox(parent)
{
    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();
    setItemDelegate(itemDelegate);
    connect(this,SIGNAL(currentIndexChanged(int )),this,SLOT(OnItemChanged(int)));
	m_ContextMenu = new QMenu(this);
	m_ContextMenu->setToolTipsVisible(true);
	m_showAbove = false;
	m_viewHeight = -1;
}
void CGComboBox::ShowContextMenu(QVariant menu)
{
    g_ShowContextMenu(this, m_ContextMenu, m_ContextMenuPos,menu);  
}
void CGComboBox::contextMenuEvent(QContextMenuEvent *event)
{
	m_ContextMenuPos = event->pos();
    //m_ContextMenuPos = mapToGlobal(m_ContextMenuPos);
	emit RequestContextMenu(currentIndex(), currentText(), currentData().toString());
	QComboBox::contextMenuEvent(event);
}

void CGComboBox::OnContextMenuClicked()
{
	m_ContextMenu->hide();
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
	{
		QString menuStr = action->text();
		QVariant menuData = action->data();
		emit ContextMenuClicked(menuStr, menuData);
	}
}

void CGComboBox::EnableCompleter(bool enabled)
{
	if (enabled)
	{
		setEditable(true);
		this->completer()->setCompletionMode(QCompleter::PopupCompletion);
	}
	else
		setCompleter(0);
}

void CGComboBox::showPopup()
{	
	QComboBox::showPopup();
	
	QWidget *popup = this->findChild<QFrame*>();
	if (popup)
	{
		if (m_viewHeight > 0)
			popup->resize(QSize(popup->width(), m_viewHeight));

		if (m_showAbove)
			popup->move(popup->x(), popup->y() - this->height() - popup->height());
	}
}
//
CGListWidget::CGListWidget( QWidget * parent  ) : QListWidget(parent)
{
    if(graphicsProxyWidget()) graphicsProxyWidget()->setWindowFlags(Qt::BypassGraphicsProxyWidget);
    connect(this,SIGNAL(itemClicked(QListWidgetItem* )),this,SLOT(OnItemClicked(QListWidgetItem*)));
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem* )),this,SLOT(OnDBItemClicked(QListWidgetItem*)));
    m_ContextMenu = new QMenu(this);
    m_ContextMenu->setToolTipsVisible(true);
}
CGListWidget::~CGListWidget()
{
    if(m_ContextMenu)
        delete m_ContextMenu;
}
void CGListWidget::InsertItem(int row, const QString & text, const QString & data, const QString & icon, const bool & checkable, const bool & checked)
{
    QString iconPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON);
    QListWidgetItem* item=NULL;
    if (row<=-1)
    { item=new QListWidgetItem(text,this) ;
    }
    else
    {
        item=new QListWidgetItem(text,0) ;
        insertItem (row,item ) ;
    }
    if (this->viewMode() == QListView::IconMode)
        item->setTextAlignment(Qt::AlignHCenter);
    if(!data.isEmpty())item->setData(Qt::ToolTipRole,data);
    if (!icon.isEmpty() )
    {
        if (!icon.startsWith("{"))
        {
            if (icon.endsWith(".ivg"))
            {
                if (viewMode() == QListView::IconMode)
                    setGridSize(QSize(iconSize().width() + 30, iconSize().height() + 20));

                QPixmap ItemIcon(iconSize());
                const CIconItem* iconItem = UnqIconMng()->Icon(icon.left(icon.size() - 4));
                if (iconItem)
                {
                    iconItem->GetItemIcon(ItemIcon);
                    item->setIcon(ItemIcon);
                }
            }
            else
                item->setIcon(QPixmap(iconPath + icon));
        }
        else
        {
            if (viewMode() == QListView::IconMode)
                setGridSize(QSize(iconSize().width() + 30, iconSize().height() + 20));

            QJsonObject jobj = UnqFunc()->Str2Json(icon);
            QString iconName = jobj["icon"].toString();
            QString iconType = jobj["type"].toString();
            if (iconType.isEmpty())
                return ;

            if (iconType == "path" && !iconName.isEmpty())
            {
                QPixmap iconPmap(this->iconSize());
                iconPmap.fill(Qt::transparent);
                QPainter painter;
                painter.begin(&iconPmap);
                painter.setBackground(Qt::transparent);
                painter.setBackgroundMode(Qt::OpaqueMode);
                QPen pen;
                pen.setWidth(1);
                painter.setPen(pen);
                painter.drawPath(UnqIconMng()->GetPath(iconName));
                item->setIcon(iconPmap);
                painter.end();
            }
        }
    }
    if (checkable)
    {
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
    }
    else
        item->setFlags(item->flags() & ~Qt::ItemIsUserCheckable);
}

void CGListWidget::SetItemData(int row, int role,   QVariant  value)
{
    if (row==-1) row=currentRow () ;
    if (item(row) ){
        if(role==Qt::BackgroundRole||role==Qt::ForegroundRole)
            value=QColor(value.toString());
        item(row)->setData( role ,value);
    }
}

QVariant CGListWidget::ItemData(int row, int role)
{
    QVariant ret;
    if (row==-1) row=currentRow () ;
    if (item(row) ){
        ret=item(row)->data( role );
    }
    return ret;
}

QList< QVariant> CGListWidget::ItemInfo(int row)
{
    QList< QVariant> ret;
    QListWidgetItem* pitem=item(row);
    if(pitem)
    {
        ret.append(pitem->text());
        ret.append(pitem->data(Qt::ToolTipRole).toString());
    }
    else
        ret.append("Can find data of the row");
    return ret;
}

QStringList CGListWidget::CheckedRows()
{
    QStringList rowLst;
    for (int i = 0; i < count(); i++)
    {
        if (item(i)->checkState() == Qt::Checked)
            rowLst.append( QString::number(i));
    }
    return rowLst;
}

QObject* CGListWidget::HorizontalScrollBar()
{
    QScrollBar * hBar = horizontalScrollBar();
    if (hBar)
        return (QObject*)hBar;
    else
        return NULL;
}

QObject* CGListWidget::VerticalScrollBar()
{
    QScrollBar * vBar = verticalScrollBar();
    if (vBar)
        return (QObject*)vBar;
    else
        return NULL;
}

void CGListWidget::mousePressEvent(QMouseEvent *event)
{
	m_ContextMenu->hide();
    if (event->button() == Qt::LeftButton)
        m_StartPos = event->pos();
    QListWidget::mousePressEvent(event);
}
void CGListWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - m_StartPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        {
            QListWidgetItem *item = currentItem();
            if (dragDropMode() !=NoDragDrop&& item) {
                QString msg=item->text();
                emit DragEvent(msg);
                return;
            }
        }
    }
    QListWidget::mouseMoveEvent(event);
}

void CGListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    m_ContextMenuPos = event->pos();
    //m_ContextMenuPos = viewport()->mapToGlobal(m_ContextMenuPos);
    if (!currentItem()){
        emit RequestContextMenu(-1,  "", "");
    }
    else
        emit RequestContextMenu(currentRow(), currentItem()->text( ), currentItem()->data( Qt::ToolTipRole).toString());
    QListWidget::contextMenuEvent(event);
}


void  CGListWidget::ShowContextMenu(QVariant menu)
{
    g_ShowContextMenu(this, m_ContextMenu, m_ContextMenuPos,menu);

}

void CGListWidget::OnContextMenuClicked()
{
    m_ContextMenu->hide();
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString menuStr = action->text();
        QVariant menuData = action->data();
        emit ContextMenuClicked(  menuStr, menuData);
    }
}

////
CGTreeWidget::CGTreeWidget( QWidget * parent ) : QTreeWidget(parent)
{
    setSortingEnabled(true);
    setAlternatingRowColors(true);

    connect(this,SIGNAL(itemClicked(QTreeWidgetItem*,int )),this,SLOT(OnItemClicked(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemDoubleClicked(QTreeWidgetItem* ,int)),this,SLOT(OnDBItemClicked(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemExpanded ( QTreeWidgetItem *)),this,SLOT(OnItemExpanded ( QTreeWidgetItem *)));

	m_ContextMenu = new QMenu(this);
	m_ContextMenu->setToolTipsVisible(true);
    m_iconPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP);
}



void CGTreeWidget::AddItem(QString parent_name, const QStringList & strings,const QStringList & datas, bool has_indicator )
{
    QTreeWidgetItem * item=NULL;
    QList<QTreeWidgetItem *> tlist= findItems ( parent_name, Qt::MatchExactly|Qt::MatchRecursive, 0 ) ;
    if (tlist.size()>0)
    {
        item =new QTreeWidgetItem(tlist[0],strings);
        if(has_indicator)
            item->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
        else
            item->setChildIndicatorPolicy(QTreeWidgetItem::DontShowIndicatorWhenChildless);
        for(int i=0;i<datas.size();i++)
            if (item) item->setData(i,Qt::ToolTipRole,datas[i]);
		setCurrentItem(item);
    }

}
QObject* CGTreeWidget::AddItem( const QStringList & strings,const QStringList & datas,bool top_level , bool has_indicator )
{
    QTreeWidgetItem * item=NULL;
    if (top_level)
    {
        item =new QTreeWidgetItem(this,strings);
        item->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
    }
    else
    {
        if (currentItem())
        {
            item =new QTreeWidgetItem(currentItem(),strings);
            currentItem()->setExpanded(true);
            if(has_indicator)
                item->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
            else
                item->setChildIndicatorPolicy(QTreeWidgetItem::DontShowIndicatorWhenChildless);
        }
    }
    for(int i=0;i<datas.size();i++)
        if (item) item->setData(i,Qt::ToolTipRole,datas[i]);
	if (item)setCurrentItem(item);
    CGTreeItemIndex* idx=new CGTreeItemIndex(this);
    idx->m_pItem=item;
    return (QObject*)idx;

}

void CGTreeWidget::mousePressEvent(QMouseEvent *event)
{
	m_ContextMenu->hide();
    if (event->button() == Qt::LeftButton)
        m_StartPos = event->pos();

	if (itemAt(event->pos())==NULL){
		clearSelection();
		setCurrentItem(NULL);
	}
    QTreeWidget::mousePressEvent(event);
}
void CGTreeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - m_StartPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        {
            if (dragDropMode() !=NoDragDrop ) {
                QString msg = QString("%1,%2").arg(objectName()).arg(CurrentItemInfo().join(",")) ;
                emit DragEvent(msg);
            }
        }
    }
    QTreeWidget::mouseMoveEvent(event);
}

void CGTreeWidget::contextMenuEvent(QContextMenuEvent *event)
{
	m_ContextMenuPos = event->pos();	
   // m_ContextMenuPos = viewport()->mapToGlobal(m_ContextMenuPos);

	if (!currentItem()){
		emit RequestContextMenu(-1, -1, "", "");
	}
	else
	    emit RequestContextMenu(indexOfTopLevelItem(currentItem()), currentColumn(), currentItem()->text(currentColumn()), currentItem()->data(currentColumn(), Qt::ToolTipRole).toString());
	QTreeWidget::contextMenuEvent(event);
}

void CGTreeWidget::ShowContextMenu(QVariant menu)
{
    g_ShowContextMenu(this, m_ContextMenu, m_ContextMenuPos,menu);
}

void CGTreeWidget::OnContextMenuClicked()
{
	m_ContextMenu->hide();
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
	{
		QString menuStr = action->text();
		QVariant menuData = action->data();
		if (currentItem() == NULL)
			emit ContextMenuClicked(-1, -1, menuStr, menuData);
		else
		    emit ContextMenuClicked(indexOfTopLevelItem(currentItem()), currentColumn(),menuStr, menuData);
	}
}

void CGTreeWidget::Init(int table_no,QString columns,int interval)
{
    QStringList clos=columns.split(",",QString::SkipEmptyParts);
}

bool  CGTreeWidget::Load(const QVariant& data)
{
    QJsonValue jobj;
    if (data.type() == QVariant::Map)
        jobj=QJsonObject::fromVariantMap(data.toMap());
    else if(data.canConvert<QJsonValue>())
        jobj=data.toJsonValue() ;
    else if(data.type() == QVariant::List ){
       jobj= QJsonArray::fromVariantList(data.toList());
    }

    clear();
    parseJsonValue(jobj);
    return true;
}

void CGTreeWidget::LoadData(const QString& data, const QString& id,const QString& pid)
{
    clear();
    QJsonArray jsonArrays=UnqFunc()->Str2JsonArray(data);
    parseJsonValue(jsonArrays);
}

QString CGTreeWidget::Data()
{
	QJsonArray dataLst;
	for (int i = 0; i < topLevelItemCount(); i++)
	{
		dataLst.append(itemToData(topLevelItem(i)));
	}
	QString str = UnqFunc()->Json2Str(dataLst);
	return str;
}

QJsonObject CGTreeWidget::itemToData(QTreeWidgetItem * item)
{
	QJsonObject obj;
	if (item == NULL)
		return obj;
	obj["text"] = item->text(0);
	QString data = item->data(0, Qt::ToolTipRole).toString();
	if (!data.isEmpty())
		obj["data"] = data;
	QString icon = item->data(0, Qt::UserRole).toString();
	if (!icon.isEmpty())
		obj["icon"] = icon;

	if (item->childCount() > 0)
	{
		QJsonArray childList;
		for (int i = 0; i < item->childCount(); i++){
			QTreeWidgetItem * child = item->child(i);
			childList.append(itemToData(child));
		}
		obj["children"] = childList;
	}
	return obj;
}

void CGTreeWidget::SetCurrentItem(int topIdx, int column, int childIdx) {
	if (childIdx == -1)
	{
		setCurrentItem(topLevelItem(topIdx), column);
	}
	else
	{
		QTreeWidgetItem* par = this->topLevelItem(topIdx);
		if (par)
		{
			setCurrentItem(par->child(childIdx));
		}
	}
};

QStringList CGTreeWidget::CurrentItemInfo(int column )
{
    QStringList ret;
    if (!currentItem()) return ret;
    ret<<currentItem()->text(column)<<currentItem()->data(column,Qt::ToolTipRole).toString();
    return ret;
}
QList< QVariant> CGTreeWidget::SelectedItemInfo(int column )
{
    QList<QTreeWidgetItem *> tmplist=selectedItems();
    QList< QVariant> ret;
    int size=tmplist.size();
    ret.append(size);
    for(int i=0;i<size;i++)
    {
        QStringList slist;
        QTreeWidgetItem* pitem=tmplist[i] ;
        slist.append(pitem->text(column));
        slist.append(pitem->data(column,Qt::ToolTipRole).toString());
        ret.append(slist);
    }
    return ret;
}
void CGTreeWidget::SetItem(int row,int column, const QString & text,const QString & data,QString icon ,QString color )
{
    QTreeWidgetItem* pitem=NULL;
    if (row==-1 )
        pitem=currentItem();
    else
        pitem=topLevelItem ( row) ;
    if (column==-1) column=currentColumn();
    if (pitem==NULL)
    {
        QStringList ls;
        pitem =new QTreeWidgetItem(this,ls);
    }

    pitem->setText(column,text);
    pitem->setData(column,Qt::ToolTipRole,data);
    if (!icon.isEmpty())
    {
		pitem->setData(column, Qt::UserRole, icon);
		icon = m_iconPath + icon;
        pitem->setIcon(column,QIcon(icon));
		
    }
    if (color!="")
    {
        pitem->setBackground(column,QBrush(QColor(color)));
    }
}
QList< QVariant> CGTreeWidget::ItemInfo(int row,int column)
{ QList< QVariant> ret;
    QTreeWidgetItem* pitem=topLevelItem ( row) ;
    if(pitem)
    {
        ret.append(pitem->text(column));
        ret.append(pitem->data(column,Qt::ToolTipRole).toString());
    }
    else
        ret.append("Can find data of the row");
    return ret;
}
void CGTreeWidget::SetItemColor(int row,int column, QString icon ,QString color )
{
    QTreeWidgetItem* pitem=NULL;
    if (row==-1 )
        pitem=currentItem();
    else
        pitem=topLevelItem ( row) ;
    if (column==-1) column=currentColumn();
    if (pitem==NULL) return;

    if (!icon.isEmpty())
    {
		pitem->setData(column, Qt::UserRole, icon);
		icon = m_iconPath + icon;
        pitem->setIcon(column,QIcon(icon));
    }
    if (color!="")
    {
        pitem->setBackground(column,QBrush(QColor(color)));
    }
}

void CGTreeWidget::SetItemData(int row,int column, int role,  QVariant value)
{
    QTreeWidgetItem* pitem=NULL;
    if (row==-1 )
        pitem=currentItem();
    else
        pitem=topLevelItem ( row) ;
    if (column==-1) column=currentColumn();
    if (pitem ){
        if(role==Qt::BackgroundRole||role==Qt::ForegroundRole)
            value=QColor(value.toString());
        pitem->setData(column,role, value);
    }
}

QVariant CGTreeWidget::ItemData(int row,int column, int role)
{
    QVariant ret;
    QTreeWidgetItem* pitem=NULL;
    if (row==-1 )
        pitem=currentItem();
    else
        pitem=topLevelItem ( row) ;
    if (column==-1) column=currentColumn();
    if (pitem ){
        ret=pitem->data(column,role );
    }
    return ret;
}

QWidget* CGTreeWidget::HorizontalScrollBar()
{
    QScrollBar * hBar = horizontalScrollBar();
    if (hBar)
        return (QWidget*)hBar;
    else
        return NULL;
}

QWidget* CGTreeWidget::VerticalScrollBar()
{
    QScrollBar * vBar = verticalScrollBar();
    if (vBar)
        return (QWidget*)vBar;
    else
        return NULL;
}

void CGTreeWidget::SetItemWidget(QObject* idx, int column, QObject *widget,bool columnSpanned)
{
    QTreeWidgetItem* tmpitem=NULL;//(QTreeWidgetItem*)item;
    bool gg=idx->inherits("CGTreeItemIndex");
    if(idx && idx->inherits("CGTreeItemIndex") )
        tmpitem=((CGTreeItemIndex*)idx)->m_pItem;
    else
        tmpitem=  currentItem() ;
    //QComboBox* pp=new QComboBox(this);
    //pp->setAutoFillBackground(true);
    setItemWidget(tmpitem,  column,(QWidget*)widget);
    tmpitem->setFirstColumnSpanned(columnSpanned);
}

void CGTreeWidget::SetItemExpanded(int index, bool expand)
{
	QTreeWidgetItem* pitem = NULL;
	if (index == -1)
		pitem = currentItem();
	else
		pitem = topLevelItem(index);

	if (pitem == NULL) return;
	pitem->setExpanded(expand);
}

void CGTreeWidget::SetItemFlags(int index, int column, int flags, bool checked)
{
	QTreeWidgetItem *pitem;
	if (index < 0 || column < 0)
		pitem = this->currentItem();
	else
		pitem = this->topLevelItem(index);
	if (pitem)
	{
		pitem->setFlags((Qt::ItemFlags) flags);
		if ((flags & Qt::ItemIsUserCheckable) > 0)
			pitem->setCheckState(column, checked ? Qt::Checked : Qt::Unchecked);
	}
}

int CGTreeWidget::ItemChecked(int index, int column)
{
	QTreeWidgetItem *pitem;
	if (index < 0 || column < 0)
		pitem = this->currentItem();
	else
		pitem = this->topLevelItem(index);
	
	if (pitem)
	{
		if ((pitem->flags() | Qt::ItemIsUserCheckable) > 0)
			return pitem->checkState(column);
	}
	return -1;
}

QList< int> CGTreeWidget::FindItem(QString text, int column)
{
	QList< int> idxList;
	if (column < 0)
		return idxList;
	QList<QTreeWidgetItem *> items = findItems(text, Qt::MatchFixedString, column);
	for (int i = 0; i < items.size();i++)
	{
		int idx = indexOfTopLevelItem(items[i]);
		if (idx >= 0)
			idxList.append(idx);
	}
	return idxList;
}

void  CGTreeWidget::parseObject(const QJsonObject &object,int column, QTreeWidgetItem *parent)
{
  QTreeWidgetItem *child;
    if (parent == NULL)
      child = new QTreeWidgetItem(this);
    else
      child = new QTreeWidgetItem(parent);

    if(!object["text"].isString())
        return;
    child->setText(column, object["text"].toString());
    if(object["id"].isString())
        child->setData(column,Qt::ToolTipRole,object["id"].toString());
    if(object["expanded"].isString())
        child->setExpanded(object["expanded"].toString().toInt());
    if(object["data"].isString())
        child->setData(column,Qt::ToolTipRole,object["data"].toString());
    if(object["icon"].isString())
    {
		child->setData(column, Qt::UserRole, object["icon"].toString());
		QString icon = m_iconPath + object["icon"].toString();
        //pitem->setIcon(column,QIcon(icon));
        child->setData(column,Qt::DecorationRole,QPixmap(icon));
    }
    if(object["checked"].isString())
    {
        child->setFlags(child->flags()|Qt::ItemIsUserCheckable);
        child->setCheckState(column,(Qt::CheckState)object["checked"].toString().toInt());
    }
	else if (object["checked"].isUndefined()==false)
	{
		child->setFlags(child->flags() | Qt::ItemIsUserCheckable);
		child->setCheckState(column, (Qt::CheckState)object["checked"].toInt());
	}
    QJsonValue value = object["children"];
    if(value.isArray())
        parseJsonValue(value,column, child);

}

void  CGTreeWidget::parseJsonValue(const QJsonValue &jsonValue, int column, QTreeWidgetItem *node)
{
  QJsonArray  array;
  switch (jsonValue.type()) {
  case QJsonValue::Null:
    //qDebug() << "NULL Json Value, check your request";
    break;
  case QJsonValue::Undefined:
   // qDebug() << "Undefined Json Value, check your request";
    break;
  case QJsonValue::Array:// Array used Key(array.at(i)) ：null
    array = jsonValue.toArray();
    for (int i = 0; i < array.size(); i++) {
        parseJsonValue(array[i], 0, node);// new QTreeWidgetItem(node));
    }
    break;
  case QJsonValue::Object:
    parseObject(jsonValue.toObject(),column, node);
    break;
  default:
    //qDebug() << "what's the fucking in parseJsonValue default";
    break;
  }
}

void CGTreeWidget::SetIconPath(QString pathType)
{
	if (pathType == "action")
	{
        m_iconPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ACTIONICON);
	}
	else if (pathType == "images")
	{
        m_iconPath = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP);
	}
}
/////////////////////
CGTableDelegate::CGTableDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *CGTableDelegate::createEditor(QWidget *parent,const QStyleOptionViewItem & option ,const QModelIndex &index ) const
{
    int item_type = index.model()->data(index,Qt::UserRole).toInt() ;
    if ( item_type == CGTableDelegate::combox )
    {
        QMap<QString, QVariant> menu=index.model()->data(index,Qt::UserRole+1).toMap();
        QComboBox *editor = new QComboBox( parent);
		QMap<QString, QVariant>::iterator itr;
		for (itr = menu.begin(); itr != menu.end(); ++itr)
		{
			editor->addItem(itr.key(), itr.value());
		}
		return editor;
    }
	else if (item_type == CGTableDelegate::checkcombobox)
	{
		QMap<QString, QVariant> menu = index.model()->data(index, Qt::UserRole + 1).toMap();
        QxtCheckComboBox *editor = new QxtCheckComboBox( parent );
		QMap<QString, QVariant>::iterator itr;
		for (itr = menu.begin(); itr != menu.end();++itr)
		{
			editor->addItem(itr.key(),itr.value());
			editor->setItemCheckState(editor->count() - 1, Qt::Unchecked);
		}
		return editor;
	}
	else if (item_type == CGTableDelegate::colordlg)
	{
		QColorDialog *editor = new QColorDialog(/*parent*/);
		return editor;
	}
	else if (item_type == CGTableDelegate::filedlg)
	{
		QFileDialog *editor = new QFileDialog(/*parent*/);
		return editor;
	}
    else if ( item_type == CGTableDelegate::spinbox )
    {
        QSpinBox *editor = new QSpinBox( parent);
        return editor;
    }
    else
    {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }

}

void CGTableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int item_type = index.model()->data(index,Qt::UserRole).toInt() ;
	if ( item_type == CGTableDelegate::combox )
    {
        QComboBox *ComboBox = static_cast<QComboBox*>(editor);
		QVariant data = index.model()->data(index, Qt::WhatsThisRole);
		int idx;
		if (data.isValid())
			idx = ComboBox->findData(data);
		else
			idx = ComboBox->findText(index.model()->data(index, Qt::DisplayRole).toString());
		ComboBox->setCurrentIndex(idx);
    }
	else if (item_type == CGTableDelegate::checkcombobox)
	{
		QxtCheckComboBox *CheckcomboBox = static_cast<QxtCheckComboBox*>(editor);
		QVariant vdata = index.model()->data(index, Qt::WhatsThisRole);
		if (vdata.type() == QVariant::String)
		{
			QStringList lst = vdata.toString().split("", QString::SkipEmptyParts);
			for (int i = 0; i < lst.size(); i++)
			{
				if(lst[i].toInt()==0)
					CheckcomboBox->setItemCheckState(i, Qt::Unchecked);
				else
					CheckcomboBox->setItemCheckState(i, Qt::Checked);
			}		
		}
		else if (vdata.type() == QVariant::Int || vdata.type() == QVariant::UInt)
		{
			uint val = vdata.toUInt();
			int idx = 0;
			if (val)
			{
				while (val)
				{
					if (val & 0x01)
					{
						if (idx<CheckcomboBox->count())
							CheckcomboBox->setItemCheckState(idx, Qt::Checked);
					}
					val >>= 1;
					idx++;
				}
			}
		}
	}
	else if (item_type == CGTableDelegate::colordlg)
	{
		QColorDialog *edit = static_cast<QColorDialog *>(editor);
		if (edit)
		{
			QString colorName = index.model()->data(index, Qt::UserRole + 1).toString();
			QColor selColor(colorName);
			edit->setCurrentColor(selColor);
		}
	}
	else if (item_type == CGTableDelegate::filedlg)
	{
		QFileDialog *edit = static_cast<QFileDialog *>(editor);
		if (edit)
		{
			edit->setGeometry(QRect(400,400,600,500));
			QString filePath = index.model()->data(index, Qt::UserRole + 1).toString();
			edit->setDirectory(filePath);
			//edit->setFilter();
		}
	}
    else if (item_type == CGTableDelegate::spinbox)
    {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(index.model()->data(index,Qt::DisplayRole).toInt());
    }
    else
    {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void CGTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const
{
    int item_type = index.model()->data(index,Qt::UserRole).toInt() ;
    if ( item_type == CGTableDelegate::combox )
    {
        QMap<QString, QVariant> menu=index.model()->data(index,Qt::UserRole+1).toMap();
        QComboBox *ComboBox = static_cast<QComboBox*>(editor);
        QString cur_txt=ComboBox->currentText();  

        QString user_data=menu[cur_txt].toString();
        if (!user_data.isEmpty())
        {
            model->setData(index,user_data,Qt::WhatsThisRole) ;
        }
		model->setData(index, cur_txt);
    }
	else  if (item_type == CGTableDelegate::checkcombobox)
	{
		QMap<QString, QVariant> menu = index.model()->data(index, Qt::UserRole + 1).toMap();
		QxtCheckComboBox *CheckcomboBox = static_cast<QxtCheckComboBox*>(editor);
		QVariant vdata = model->data(index, Qt::WhatsThisRole);
		if (vdata.type() == QVariant::String)
		{
			QString data;
			for (int i = 0; i< CheckcomboBox->count(); i++)
			{
				Qt::CheckState iii = CheckcomboBox->itemCheckState(i);
				if (CheckcomboBox->itemCheckState(i) == Qt::Checked)
					data.append("1");
				else
					data.append("0");
			}
			model->setData(index, data, Qt::WhatsThisRole);
		}
		else
		{
			int data = 0;
			for (int i = 0; i< CheckcomboBox->count(); i++)
			{
				Qt::CheckState iii = CheckcomboBox->itemCheckState(i);
				if (CheckcomboBox->itemCheckState(i) == Qt::Checked)
					data += CheckcomboBox->itemData(i).toInt();
			}
			model->setData(index, data, Qt::WhatsThisRole);
		}

		QString cur_txt = CheckcomboBox->currentText();
		model->setData(index, cur_txt);

	}
	else if (item_type == CGTableDelegate::colordlg)
	{
		QColorDialog *edit = static_cast<QColorDialog *>(editor);
		if (edit)
		{
			QColor selColor = edit->currentColor();
			model->setData(index, selColor.name(), Qt::WhatsThisRole);
			model->setData(index, selColor.name(), Qt::UserRole + 1);
			model->setData(index, selColor.name());
		}
	}
	else if (item_type == CGTableDelegate::filedlg)
	{
		QFileDialog *edit = static_cast<QFileDialog *>(editor);
		if (edit)
		{
			QStringList fileNames = edit->selectedFiles();
			if (fileNames.size() == 0)
				return;
			QString text = fileNames[0].replace(edit->directory().absolutePath(),"");
			model->setData(index, text, Qt::WhatsThisRole);
			//model->setData(index, fileNames[0], Qt::UserRole + 1);
			model->setData(index, text);
		}
	}
    else if(item_type == CGTableDelegate::spinbox){
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value);
    }
    else
    {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void CGTableDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option,const QModelIndex & index ) const
{
	int item_type = index.model()->data(index, Qt::UserRole).toInt();
	if (item_type == CGTableDelegate::colordlg)
	{
		QString colorName = index.model()->data(index, Qt::UserRole + 1).toString();
		QColor selCor(colorName);
		if (option.state & QStyle::State_Selected)
		{
			//draw focus
			QStyleOptionViewItemV4 opt = option;
			QPalette::ColorGroup cg = QPalette::Normal;
			QColor cor = option.palette.color(cg, QPalette::Highlight);
			painter->fillRect(opt.rect, cor);
		}
		else
			painter->fillRect(option.rect, selCor);
	}
	else
		QStyledItemDelegate::paint( painter, option, index);
}

void CGTableDelegate::updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QStyledItemDelegate::updateEditorGeometry(editor, option, index);
}

bool CGTableDelegate::eventFilter(QObject *object, QEvent *event)
{
	if (object->inherits("QComboBox"))
    {
		QComboBox * comboBox = dynamic_cast<QComboBox*>(object);
		if (comboBox && event->type() == QEvent::MouseButtonRelease)
        {
            comboBox->showPopup();
            return true;
        }
    }
	else
    {
        return QStyledItemDelegate::eventFilter( object, event );
    }
    return false;
}

CGTableWidget::CGTableWidget( QWidget * parent ) : QTableWidget(parent)
{
    setColumnCount(5);
    setRowCount ( 5);
    m_ContextMenu = new QMenu(this);
	m_ContextMenu->setToolTipsVisible(true);

    m_pTableDelegate = new CGTableDelegate(this);
    setItemDelegate(m_pTableDelegate);
    setAlternatingRowColors(true);
    //SetHeaderResizeMode(1);//

    SetShowRowHeader(false);
    horizontalHeader()->setSortIndicatorShown(true);
    horizontalHeader()->setStretchLastSection(true);

    connect(this,SIGNAL(itemClicked(QTableWidgetItem* )),this,SLOT(OnItemClicked(QTableWidgetItem* )));
    connect(this,SIGNAL(itemDoubleClicked(QTableWidgetItem* )),this,SLOT(OnDBItemClicked(QTableWidgetItem* )));
    SetRowHeight(25);
}
CGTableWidget::~CGTableWidget()
{
	if (m_pTableDelegate)
	{
		delete m_pTableDelegate;
		m_pTableDelegate = NULL;
	}
	for (int i = 0; i < rowCount();i++)
	{
		for (int j = 0; j < columnCount(); j++)
		{
			QWidget* wgt = cellWidget(i, j);
			if (wgt)
			{
				delete wgt;
				wgt = NULL;
			}
		}
	}
	this->clear();
	if (m_ContextMenu)
	{
        delete m_ContextMenu ;
	}
}

void CGTableWidget::mousePressEvent(QMouseEvent *event)
{
	m_ContextMenu->hide();
    if (event->button() == Qt::LeftButton)
        m_StartPos = event->pos();
    QTableWidget::mousePressEvent(event);
}
void CGTableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - m_StartPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        {
            if (dragDropMode() !=NoDragDrop ) {
                QString msg = QString("%1,%2,%3").arg(objectName()).arg(currentRow()).arg(currentColumn());
                emit DragEvent(msg);
            }
        }
    }
    QTableWidget::mouseMoveEvent(event);
}
int CGTableWidget::SetAllItems( int nRows, int nCols, const QList<QVariant> & txtList, const QList<QVariant> & strList)
{
    clearContents();
    nRows=txtList.size();
    if(nRows<1)
        return -1;
	if (nCols<1)
        nCols=txtList.at(0).toStringList().size();
    setColumnCount(nCols);
    setRowCount(nRows);
    if ( (strList.size() != 0 ) && ( strList.size() != txtList.size() ))
        return 3;

    int curRow, rowLoop, curCol, colLoop;
    rowLoop = colLoop = 0;
    for ( curRow = 0; curRow < nRows; curRow++ )
    {
        QStringList record=txtList.at(curRow).toStringList();
        QStringList datarecord;
        if(strList.size()>0)
            datarecord=strList.at(curRow).toStringList();

        for ( curCol = 0 ; curCol < record.size(); curCol++ )
        {
            QTableWidgetItem *pitem=item( curRow, curCol ) ;
            if ( pitem==NULL)
            {
                pitem = new QTableWidgetItem(record[curCol]);
                setItem( curRow, curCol,pitem);
            }
            else
            {
                pitem->setData(Qt::DisplayRole, record[curCol]);
            }

            if(datarecord.size()>curCol)
            {
                pitem->setData(Qt::WhatsThisRole,datarecord[curCol]);
            }
            //pitem->setTextAlignment(Qt::AlignCenter);
        }
    }
    return 0;
}
void CGTableWidget::SetItemData(int row,int column, int role,  QVariant  value)
{
    if (!IsValid(row,column))
    {
        return ;
    }
    QTableWidgetItem *pitem=item( row, column ) ;
    if ( pitem==NULL)
    {
        pitem = new QTableWidgetItem();
		setItem(row, column, pitem);
    }
    if(role==Qt::BackgroundRole||role==Qt::ForegroundRole)
        value=QColor(value.toString());
    pitem->setData(role, value);
}

QVariant CGTableWidget::ItemData(int row,int column, int role)
{
    QVariant ret;
    if (!IsValid(row,column))
        return ret;
    QTableWidgetItem *pitem=item( row, column ) ;
    if ( pitem==NULL)
    {
        pitem = new QTableWidgetItem();
        return "";
    }
    ret=pitem->data(role);
    return ret;
}
void CGTableWidget::SetItem(int row, int column, const QVariant &txt, const QVariant &usr_data, const QString & iconFile)
{
    if (!IsValid(row,column))
    {
        return ;
    }
	QString iconPath;
	UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ICONSET, iconFile, iconPath);
    QTableWidgetItem *pitem=item( row, column ) ;
    QVariant dis_txt=txt;
    if ( pitem==NULL)
    {
        pitem = new QTableWidgetItem();
		setItem(row, column, pitem);
    }

    int item_type = pitem->data(Qt::UserRole).toInt() ;
    if ( item_type == CGTableDelegate::combox )
    {
        QMap<QString, QVariant> menu=pitem->data(Qt::UserRole+1).toMap();
        if (dis_txt=="")
        {
            QString key=menu.key(usr_data) ;
            dis_txt=key;
        }
    }
    pitem->setData(Qt::DisplayRole,dis_txt);
    pitem->setData(Qt::WhatsThisRole,usr_data);
    pitem->setTextAlignment(Qt::AlignCenter);
	pitem->setIcon(QIcon(iconPath));
}

void CGTableWidget::SetCellMenu(int row, int column, const QMap<QString, QVariant>& menu, bool multiSelect)
{
	if (!IsValid(0, column))
	{
		return;
	}
	if (menu.size() < 2)
	{
		return;
	}
	int widgetType = CGTableDelegate::combox;
	if (multiSelect)
		widgetType = CGTableDelegate::checkcombobox;

	SetCellWidget(row, column, widgetType, menu);
}

void CGTableWidget::SetCellWidget(int row, int column, QVariant widgetType, QVariant data)
{
    int itype=0;
    if(widgetType.type()==QMetaType::Int)
        itype=widgetType.toInt();
    else{
        QString str=widgetType.toString();//combox, multicombox, colordlg, filedlg ,checkbox,spinbox
        if(str=="combox")
            itype=CGTableDelegate::combox;
        else if(str.contains("multicombox"))
            itype=CGTableDelegate::checkcombobox;
        else if(str.contains("color"))
            itype=CGTableDelegate::colordlg;
        else if(str.contains("file"))
            itype=CGTableDelegate::filedlg;
        else if(str.contains("checkbox"))
            itype=CGTableDelegate::checkbox;
        else if(str.contains("spin"))
            itype=CGTableDelegate::spinbox;
    }
    QTableWidgetSelectionRange range = GetOpRange( row, column );
    for (int i = range.topRow(); i<range.bottomRow(); i++)
    {
        for (int j = range.leftColumn(); j < range.rightColumn(); j++)
        {
            QTableWidgetItem *item1 = item(i, j);
            if (item1 == NULL)
                item1 = new QTableWidgetItem;

            item1->setData(Qt::UserRole + 1, data);
            item1->setTextAlignment(Qt::AlignCenter);
            if (itype == CGTableDelegate::checkbox){
                item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
                item1->setCheckState(data.toBool() ? Qt::Checked : Qt::Unchecked);
            }
            else
            {
                item1->setData(Qt::UserRole, itype);
                item1->setData(Qt::DisplayRole, data);
            }

            setItem(i, j, item1);
        }
    }

}

void CGTableWidget::Clear( int row ,int column )
{
    if (row==-1 && column==-1)
        clear();
    else if(row> -1 && column> -1)
        takeItem(row ,column);
    else if(row>-1 && column==-1)
        removeRow(row);
    else if(row==-1 && column>-1)
        removeColumn(column);
}

void CGTableWidget::SetTextAlignment(int row,int column,int align_type)
{
    int i=0;
    int j=0;
    QTableWidgetSelectionRange range = GetOpRange( row, column );
    for ( i = range.topRow(); i<range.bottomRow(); i++)
    {
        for ( j = range.leftColumn(); j < range.rightColumn(); j++)
        {
            QTableWidgetItem *pitem=item( i, j ) ;
            if ( pitem==NULL)
            {
                pitem = new QTableWidgetItem();
                setItem(i,j, pitem);
            }
            pitem->setTextAlignment(align_type);
        }
    }
}

QStringList CGTableWidget::SelectedRanges()
{
    QStringList ret;
    QList<QTableWidgetSelectionRange> range=selectedRanges();
    if(range.size()>0)
    {
        ret<<QString("%1").arg(range[0].topRow())<<QString("%1").arg(range[0].bottomRow())
                <<QString("%1").arg(range[0].leftColumn())<<QString("%1").arg(range[0].rightColumn());
    }
    return ret;
}

QTableWidgetSelectionRange CGTableWidget::GetOpRange( int row , int column)
{
    if ( row >= rowCount() || column >= columnCount() )
    {
        return QTableWidgetSelectionRange();
    }
    int top, bottom, left,right;
    top = -1;
    bottom = -1;
    left = -1;
    right=-1;

    if ( row < 0 )
    {
        top = 0;
        bottom = rowCount();
        if ( column < 0 )
        {
            left = 0;
            right = columnCount();
        }
        else
        {
            left = column;
            right = left+1;
        }
    }
    else
    {

        top = row;
        bottom = top+1;

        if ( column < 0 )
        {
            left = 0;
            right = columnCount();
        }
        else
        {
            left = column;
            right = left+1;
        }
    }
    return QTableWidgetSelectionRange( top, left, bottom, right );
}

void CGTableWidget::SetItemFlags(int row, int column, int flags, bool checked)
{
    int i = 0;
    int j = 0;
    QTableWidgetSelectionRange range = GetOpRange( row, column );
    for ( i = range.topRow(); i<range.bottomRow(); i++)
    {
        for ( j = range.leftColumn(); j < range.rightColumn(); j++)
        {
            QTableWidgetItem *pitem=item( i, j ) ;
            if ( pitem==NULL)
            {
                pitem = new QTableWidgetItem();
                setItem(i,j, pitem);
            }
            /*int tmp = (int)pitem->flags();
            if ( flags < 0 )
            {
                tmp &= ~(abs( flags ));
            }
            else if ( flags == 0 )
                tmp = 0;
            else
                tmp |= flags;*/
			
			pitem->setFlags((Qt::ItemFlags) flags);
			if ((flags & Qt::ItemIsUserCheckable) > 0)
				pitem->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
        }
    }
}

QStringList CGTableWidget::ItemData(int row,int column)
{
    QStringList ret;
    if(row==-1) row=currentRow();
    if(column==-1) column=currentColumn();
    if (!IsValid(row,column))
    {
        return ret;
    }
    QTableWidgetItem *pitem=item( row,column );
    if (pitem)
    {
        QString txt=pitem->data(Qt::DisplayRole).toString();
        ret.append(txt);
        QString user_data=pitem->data(Qt::WhatsThisRole).toString();
        ret.append(user_data);
    }
    return ret;
}
int CGTableWidget::ItemChecked(int row, int column)
{
	if (row == -1) row = currentRow();
	if (column == -1) column = currentColumn();
	if (!IsValid(row, column))
	{
		return -1;
	}
	QTableWidgetItem *pitem = item(row, column);
	if (pitem)
	{
		QVariant val = pitem->data(Qt::CheckStateRole);
		if (val.isValid())
			return val.toInt();
	}

	return -1;
}
void CGTableWidget::OnItemClicked(QTableWidgetItem* item )
{
    int row=item->row();
    int column=item->column();
    QStringList valist=ItemData(row,column);
    emit ItemClicked(row,column,valist[0],valist[1]);
}

void CGTableWidget::OnDBItemClicked(QTableWidgetItem* item )
{
    int row=item->row();
    int column=item->column();
    QStringList valist=ItemData(row,column);
    emit ItemDoubleClicked(row,column,valist[0],valist[1]);
}

void  CGTableWidget::ShowContextMenu(QVariant menu)
{
    g_ShowContextMenu(this, m_ContextMenu, m_ContextMenuPos,menu);
}
void CGTableWidget::contextMenuEvent(QContextMenuEvent *event)
{
	m_ContextMenuPos = event->pos();
    //m_ContextMenuPos = viewport()->mapToGlobal(m_ContextMenuPos);
    emit RequestContextMenu(currentRow(), currentColumn());
	QTableWidget::contextMenuEvent(event);
}

void CGTableWidget::OnContextMenuClicked()
{
	m_ContextMenu->hide();
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
	{
		QString menuStr = action->text();
		QVariant menuData = action->data();
		emit ContextMenuClicked(menuStr, menuData);
	}

}

bool CGTableWidget::IsValid(int row,int column)
{
    if ( row>=rowCount() || row<0 || column>=columnCount()||column<0 )
        return false;
    else
        return true;
}

void CGTableWidget::CreateHtmlTableFromModel()
{

    QString htmlFileName = UnqFunc()->GetSysHome()+"/data/CGTable.html";
    QFile file(htmlFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return ;
    }
    QTextStream out(&file);
    int rowCount = this->model()->rowCount();
    int columnCount = this->model()->columnCount();
    out << "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << QString("<title>%1</title>\n").arg("aa")
        << "</head>\n"
        << "<style>\n"
           ".font{font-size:12px}\n"
           "</style>\n"

           "<body  bgcolor=#ffffff link=#5000A0>\n"
           "<table border=1 cellspacing=0 cellpadding=2>\n";

    out << "<tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!this->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(this->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr>\n";
    file.flush();

    for (int row = 0; row < rowCount; row++)
    { out << "<tr>";
        for (int column = 0; column < columnCount; column++)
        { if (! this->isColumnHidden(column))
            { QString data = this->model()->data(this->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out << "</table>\n"
           "</body>\n"
           "</html>\n";
    file.close();

}

void CGTableWidget::Print()
{
    CreateHtmlTableFromModel();
    QTextBrowser *editor = new QTextBrowser(this);
    QString htmlFileName = UnqFunc()->GetSysHome()+"/data/CGTable.html";
    editor->setSource(QUrl(htmlFileName));
    editor->openLinks();
    QFile file(htmlFileName);
    if (file.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        in.setCodec(LOCAL_LANGUAGE);
        editor->setText(in.readAll());
        file.close();
    }


    QPrinter printer;
    QPrintDialog * dlg = new QPrintDialog(&printer,this);
    if(dlg->exec() != QDialog::Accepted)
        return;


    QTextDocument *document=editor->document();
    QFont Font;
    Font.setFamily("Song");
    Font.setPointSize(16);
    document->setDefaultFont(Font);


    document->print(&printer);
    delete dlg;
    delete editor;


}

QObject* CGTableWidget::HorizontalScrollBar()
{
    QScrollBar * hBar = horizontalScrollBar();
    if (hBar)
        return (QObject*)hBar;
    else
        return NULL;
}

QObject* CGTableWidget::VerticalScrollBar()
{
    QScrollBar * vBar = verticalScrollBar();
    if (vBar)
        return (QObject*)vBar;
    else
        return NULL;
}

void CGTableWidget::SetColumns(const QVariant& columnsInfo )
{
    if (columnsInfo.type() == QVariant::String)
        m_ColumnsInfo=UnqFunc()->Str2JsonArray(columnsInfo.toString());
	else if (columnsInfo.type() == QVariant::List)
		m_ColumnsInfo = QJsonArray::fromVariantList(columnsInfo.toList());
	else
        m_ColumnsInfo = columnsInfo.toJsonArray();


    setColumnCount(m_ColumnsInfo.size());
    QStringList headers;
    int idx=0;
    foreach(QJsonValue jsonv, m_ColumnsInfo)
    {
        if(jsonv.isObject())
        {
            QJsonObject jobj = jsonv.toObject();
            if(jobj["text"].isString()  )
            {
                headers<<jobj["text"].toString();
                if(jobj["field"].isUndefined())
                    m_ColIdxMap[idx]=jobj["text"].toString();
                else
                    m_ColIdxMap[idx]=jobj["field"].toString();
                if(!jobj["width"].isUndefined()) setColumnWidth(idx, jobj["width"].toInt());
                idx++;
            }
        }
    }
	SetHorizontalHeaderLabels(headers);
}

QVariantList CGTableWidget::Data()//dataJsonarray
{
	QVariantList dataLst;
	for (int i = 0; i < rowCount(); i++)
	{
		QVariantMap obj;
		for (int j = 0; j < columnCount(); j++)
		{
			QString colName = QString::number(j);
			if (m_ColIdxMap.size()>j)
				colName = m_ColIdxMap[j];
			else
				colName = horizontalHeaderItem(j)->text();
			QString val = "";
			if (item(i, j))
			{
				val = item(i, j)->data(Qt::DisplayRole).toString();
				QVariant checkVal= item(i, j)->data(Qt::CheckStateRole);
				if (checkVal.isValid())
				{
					val = QString::number(checkVal.toInt()>0?1:0);
				}
			}
			obj[colName] = val;
		}
		dataLst << obj;
	}
	return dataLst;
}

int CGTableWidget::LoadData(const QString& data)
{
    QJsonArray jdata=UnqFunc()->Str2JsonArray(data);
    int nRows=jdata.size();
    if(nRows<1)
        return -1;
    int nCols=m_ColIdxMap.size();
    if(nCols==0)
        nCols=jdata[0].toObject().size();
    setColumnCount(nCols);
    setRowCount(nRows);

    for ( int i = 0; i < nRows; i++ )
    {
        QJsonObject record=jdata[i].toObject();
        for ( int j = 0 ; j < nCols; j++ )
        {
            QTableWidgetItem *pitem=item( i, j ) ;
			QString colname = "";
			QVariant value = "";
			if (m_ColIdxMap.size() > j)
				colname = m_ColIdxMap[j];
			else		
				colname = record.keys().at(j);
			
			value = record[colname].toVariant();
			
            if ( pitem==NULL)
            {
				pitem = new QTableWidgetItem(value.toString());
                setItem( i, j,pitem);
            }
            else
            {
                pitem->setData(Qt::DisplayRole,value);
            }

            pitem->setTextAlignment(Qt::AlignCenter);
        }
    }
    return 0;
}

void CGTableWidget::SetHeaderResizeMode(int mode, QString header, int idx)
{
	QHeaderView * headView = NULL;
	if (header == "h")
		headView = horizontalHeader();
	else if (header == "v")
		headView = verticalHeader();

	if (headView)
	{
		if (idx < 0)
			headView->setSectionResizeMode((QHeaderView::ResizeMode)mode);
		else
			headView->setSectionResizeMode(idx, (QHeaderView::ResizeMode)mode);
	}
}
//////////////////
void CGTextBrowser::SetSource(QString url)
{

    if (url.left(5)=="file:")
    {
        url=url.right(url.length()-5);
        QFile file(url);
        if (file.open(QIODevice::Text | QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            in.setCodec(LOCAL_LANGUAGE);
            setText(in.readAll());
            file.close();
        }
    }
    else
        setSource(QUrl(url));
}

void CGTextBrowser::Print()
{

    QPrinter printer;
    QPrintDialog * dlg = new QPrintDialog(&printer,this);
    if(dlg->exec() != QDialog::Accepted)
        return;
    QTextDocument *document=this->document();
    document->print(&printer);
}

///////////////
CGLabel::CGLabel(const QString& text, QWidget * parent , Qt::WindowFlags f ):QLabel(text, parent,f)
{
    m_pMovie=NULL;
    installEventFilter(this);
}
void CGLabel::SetPixmap(const QString &pixname)
{
    m_pixmapName=pixname;
    QString path_name = pixname;
    if (!path_name.contains(":"))
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_PIXMAP,pixname,path_name);

    if (m_pMovie) m_pMovie->stop();
    if (pixname.indexOf(".gif")>0)
    {
        if (m_pMovie==NULL)
        {
            m_pMovie=new QMovie();
        }
        if (m_pMovie)
        {
            m_pMovie->setFileName(path_name);
            setMovie(m_pMovie);
            m_pMovie->start();
        }
    }
 /*   else if(pixname.lastIndexOf("fa-")>0){
        QString iconname;
        UnqFunc()->GetGraphCoreNameByGraphPathName(pixname,iconname);
        setPixmap(UnqAwe()->icon(iconname));
    }*/
    else
    {
        setPixmap(path_name);
    }
}
bool CGLabel::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == this)
    {
        switch(e->type())
        {

        case QEvent::MouseButtonRelease:
            emit Clicked( text(),m_Data );
            break;
        case QEvent::MouseButtonDblClick:
            emit DBClicked( text(),m_Data );
            break;
        default:
            break;
        }
    }
    return QLabel::eventFilter(obj, e);
}


#ifdef WEBVIEW
/////////////////////////
/// \brief CGWebView::CGWebView
/// \param parent
CGWebView::CGWebView( QWidget * parent)
    :  QWebEngineView(parent)
{
   // QUrl l_url("about:blank" );
    //setUrl( l_url );
}

void CGWebView::Print()
{
 /*   QPrinter printer;
    QPrintDialog * dlg = new QPrintDialog(&printer,this);
    if(dlg->exec() != QDialog::Accepted)
        return;
    print(&printer);*/

}
#endif

#ifdef QML
void CQuickView::mouseDoubleClickEvent(QMouseEvent * event)
{
    QVariant ret;
    QObject *root_obj = (QObject *)this->rootObject();
    if (root_obj)
    {
        bool isOK = QMetaObject::invokeMethod(root_obj, "chartConfig", Q_RETURN_ARG(QVariant, ret));
        if (!isOK)
            return;
    }
}

QVariant CQuickView::Call(QString funcName, QVariant val0,
                          QVariant val1, QVariant val2, QVariant val3,
                          QVariant val4, QVariant val5, QVariant val6,
                          QVariant val7, QVariant val8, QVariant val9)
{
    QVariant ret;
    QObject *root_obj = (QObject *)this->rootObject();
    if (root_obj)
    {
        bool isOK = QMetaObject::invokeMethod(root_obj, funcName.toLocal8Bit().data(), Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, val0));
        if (!isOK)
            return QVariant();
    }
    return ret;
}
#endif

CGMenuBar::CGMenuBar(QWidget * parent ):QMenuBar( parent )
{
}

int CGMenuBar::AddMenu(QMap<QString, QVariant> menuActionsMap)
{


    for (QMap<QString, QVariant>::const_iterator itr = menuActionsMap.begin(); itr != menuActionsMap.end(); ++itr)
    {
        QMenu* menu = addMenu(itr.key());
        QMap<QString, QVariant> actionMap = itr.value().toMap();
        for (QMap<QString, QVariant>::const_iterator actionItr = actionMap.begin(); actionItr != actionMap.end(); ++actionItr)
        {
            QString iconFile = actionItr.value().toString();
            QAction* action = menu->addAction( actionItr.key());
            connect(action, SIGNAL(triggered()), this, SLOT(onActionTriggered()));
        }
    }
    return 0;
}

void CGMenuBar::onActionTriggered()
{
    QString actionName = ((QAction*)sender())->text();
    emit actionTriggered( actionName );

}


CGPushButton::CGPushButton(QString text, QWidget * parent) :QToolButton(parent)
{
    setText(text);
    setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_pMovie = NULL;
}

void CGPushButton::SetIcon(QString iconfilePath, QString pathType)
{
    if (m_pMovie)
        m_pMovie->stop();
    if (iconfilePath.isEmpty())
        return;

	int  path = CGFunc::PATH_TYPE_PIXMAP;
	if (pathType == "action")
	{
		path = CGFunc::PATH_TYPE_ACTIONICON;
	}
	if (QDir::isRelativePath(iconfilePath))
		UnqFunc()->GetFilePathName(path, iconfilePath, iconfilePath);

    if (iconfilePath.indexOf(".gif") > 0)
    {
        if (m_pMovie == NULL)
            m_pMovie = new QMovie(iconfilePath, QByteArray(), this);
        else
            m_pMovie->setFileName(iconfilePath);

        connect(m_pMovie, SIGNAL(frameChanged(int)), this, SLOT(iconChged(int)));
        m_pMovie->start();
    }
    else if(iconfilePath.lastIndexOf("fa-")>0){
        QString iconname;
        UnqFunc()->GetGraphCoreNameByGraphPathName(iconfilePath,iconname);
        setIcon(UnqAwe()->icon(iconname));
    }
    else
        setIcon(QIcon(iconfilePath));
}

void CGPushButton::iconChged(int){
    setIcon(m_pMovie->currentPixmap());
}

QObject* CGPushButton::SetMenu(QVariant menuinfo)
{
    QPoint pos;
    QMenu *pMenu=new QMenu;
    g_ShowContextMenu(this, pMenu, pos,menuinfo,false);
    setMenu(pMenu);
    connect(pMenu, SIGNAL(triggered(QAction *)), this, SLOT(OnMenuTriggered(QAction *)));
    return pMenu;
}
void CGPushButton::OnMenuTriggered(QAction * action)
{
     emit MenuTriggered(action->text(),action->data().toString());
}

////
CGTabBar::CGTabBar(QWidget * parent  ):QTabBar(parent)
{
    addTab("tab1");
    addTab("tab2");
    addTab("tab3");
}
int CGTabBar::AddTab(const QString & text,const QString & iconName  )
{
    int ret=0;
    if(iconName.isEmpty())
        ret=addTab(text);
    else
    {
        QString icon=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP)+iconName;
        ret=addTab(QIcon(icon),text);
    }
    return ret;
}

void CGTabBar::RemoveTab(int index )
{
    if(index<0)
    {
        for(int i=0;i<count();i++)
        {
            removeTab(i);
        }
    }
    else
    {
        removeTab(index);
    }
}

//
CGTabWidget::CGTabWidget(QWidget * parent  ):QTabWidget(parent)
{
    addTab(new QPushButton(),"tab1");
    addTab(new QWidget(),"tab2");

}
int CGTabWidget::AddTab(QObject* widget,const QString & text,const QString & iconName  )
{
    int ret=0;
    if(widget->inherits("QWidget")==false)
        return -1;
    if(iconName.isEmpty())
        ret=addTab((QWidget*)widget,text);
    else
    {
        QString icon=UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP)+iconName;
        ret=addTab((QWidget*)widget,QIcon(icon),text);
    }
    setCurrentIndex(ret);
    return ret;
}

void CGTabWidget::RemoveTab(int index )
{
    if(index<0)
    {
        clear();
    }
    else
    {
        removeTab(index);
    }
}

QWidget *	CGTabWidget::Widget(int index )
{
    return index<0? currentWidget(): widget(index);
}

void CGTabWidget::dropEvent(QDropEvent * event)
{
    QWidget::dropEvent(event);
}

void CGTabWidget::contextMenuEvent(QContextMenuEvent * event)
{
    QPoint pos=event->pos();

    QMenu menu(this);
    menu.addAction(tr("insert"));
    menu.addAction(tr("close"));
   // connect(&menu, SIGNAL(triggered(QAction *)), this, SLOT(OnPlaneCtl(QAction *)));

    QPoint pos1 =  mapToGlobal(pos);
    menu.exec(pos);
}

///
void CGDateEdit::SetDate(const QString &date, const QString & format)
{
	QDate dateVal;
	if (date.isEmpty() && format.isEmpty())
	{
		dateVal = QDate::currentDate();
	}
	else
	{
		this->setDisplayFormat(format);
		dateVal = QDate::fromString(date, format);
	}
	this->setDate(dateVal);
}

void CGTimeEdit::SetTime(const QString &time, const QString & format)
{
	QTime timeVal;
	if (time.isEmpty() && format.isEmpty())
	{
		timeVal = QTime::currentTime();
	}
	else
	{
		this->setDisplayFormat(format);
		timeVal = QTime::fromString(time, format);
	}
	this->setTime(timeVal);
}

void CGCalendarWidget::dateChanged()
{
	QDate currentDate = selectedDate();
	emit SelectionChanged(currentDate.year(), currentDate.month(), currentDate.day());
}

CGProgressBar::CGProgressBar(QWidget * parent):QProgressBar(parent)
{
	setMaximum(100);
	setMinimum(0);
	setValue(35);
	setFormat("%v/%m");
	setAlignment(Qt::AlignCenter);

}
QString CGProgressBar::GetTag()
{
	if (graphicsProxyWidget())
	{
		CWidgetItem* cgItem = (CWidgetItem*)graphicsProxyWidget();
		QString userData = g_dataPtr(cgItem)->GetUserData();
		QJsonArray lst = UnqFunc()->Str2JsonArray(userData);
		if (lst.size() == 0)
			return "";
		return lst[0].toObject()["tags"].toString();
	}
	return "";
}

CGTextEdit::CGTextEdit(QWidget * parent) :QTextEdit(parent)
{
	m_maxLength = -1;
	connect(this, SIGNAL(textChanged()),this, SLOT(TextChanged()));
}

CGTextEdit::~CGTextEdit()
{
    //setVisible(false);
    //setDisabled(false);
}

void CGTextEdit::SetMaxLength(int maxLength)
{
	m_maxLength = maxLength;
}
void CGTextEdit::TextChanged()
{
	if (m_maxLength <0)
	{
		return;
	}
		
	QString textContent = this->toPlainText();
	int length = textContent.count();
	if (length>m_maxLength)
	{
		int position = this->textCursor().position();          
		QTextCursor textCursor = this->textCursor();          
		textContent.remove(position - (length - m_maxLength), length - m_maxLength);
		this->setText(textContent);          
		textCursor.setPosition(position - (length - m_maxLength));
		this->setTextCursor(textCursor);
	}
}

CGLineEdit::CGLineEdit(QWidget * parent) :QLineEdit(parent)
{
	m_pasteEnable = true;
}
CGLineEdit::~CGLineEdit(){}

void CGLineEdit::SetPasteEnabled(bool beEnable)
{
	m_pasteEnable = beEnable;
	if (!m_pasteEnable)
		this->setContextMenuPolicy(Qt::NoContextMenu);
}
void CGLineEdit::keyPressEvent(QKeyEvent *event)
{
	if (!m_pasteEnable)
	{
		if (event->matches(QKeySequence::SelectAll) || event->matches(QKeySequence::Copy) || event->matches(QKeySequence::Paste))
		{
			return;
		}
	}
	
	QLineEdit::keyPressEvent(event);
}


CGFontEditWidget::CGFontEditWidget(QWidget *parent) :
QWidget(parent),
m_pixmapLabel(new QLabel),
m_label(new QLabel),
m_button(new QToolButton)
{
	QHBoxLayout *lt = new QHBoxLayout(this);
	//setupTreeViewEditorMargin(lt);
	enum { DecorationMargin = 4 };
	if (QApplication::layoutDirection() == Qt::LeftToRight)
		lt->setContentsMargins(DecorationMargin, 0, 0, 0);
	else
		lt->setContentsMargins(0, 0, DecorationMargin, 0);

	lt->setSpacing(0);
	lt->addWidget(m_pixmapLabel);
	lt->addWidget(m_label);
	lt->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));

	m_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Ignored);
	m_button->setFixedWidth(20);
	setFocusProxy(m_button);
	setFocusPolicy(m_button->focusPolicy());
	m_button->setText(tr("..."));
	m_button->installEventFilter(this);
	connect(m_button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
	lt->addWidget(m_button);
	m_pixmapLabel->setPixmap(fontValuePixmap(m_font));
	m_label->setText(fontValueText(m_font));
}

void CGFontEditWidget::setValue(const QFont &f)
{
	if (m_font != f)
	{
		m_font = f;
		m_pixmapLabel->setPixmap(fontValuePixmap(f));
		m_label->setText(fontValueText(f));
	}
}

void CGFontEditWidget::buttonClicked()
{
	bool ok = false;
	QFont newFont = QFontDialog::getFont(&ok, m_font, 0, tr("Select Font"));
	if (ok && newFont != m_font)
	{
		QFont f = m_font;

		if (m_font.family() != newFont.family())
		{
			f.setFamily(newFont.family());
		}
		if (m_font.pointSize() != newFont.pointSize())
		{
			f.setPointSize(newFont.pointSize());
		}
		if (m_font.bold() != newFont.bold())
		{
			f.setBold(newFont.bold());
		}
		if (m_font.italic() != newFont.italic())
		{
			f.setItalic(newFont.italic());
		}
		if (m_font.underline() != newFont.underline())
		{
			f.setUnderline(newFont.underline());
		}
		if (m_font.strikeOut() != newFont.strikeOut())
		{
			f.setStrikeOut(newFont.strikeOut());
		}
		setValue(f);
		emit valueChanged(m_font);
	}
}

bool CGFontEditWidget::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == m_button)
	{
		switch (ev->type())
		{
		case QEvent::KeyPress:
		case QEvent::KeyRelease:

		{
								   switch (static_cast<const QKeyEvent *>(ev)->key())
								   {
								   case Qt::Key_Escape:
								   case Qt::Key_Enter:
								   case Qt::Key_Return:
									   ev->ignore();
									   return true;
								   default:
									   break;
								   }
		}
			break;
		default:
			break;
		}
	}
	return QWidget::eventFilter(obj, ev);
}

QPixmap CGFontEditWidget::fontValuePixmap(const QFont &font)
{
	QFont f = font;
	QImage img(16, 16, QImage::Format_ARGB32_Premultiplied);
	img.fill(0);
	QPainter p(&img);
	p.setRenderHint(QPainter::TextAntialiasing, true);
	p.setRenderHint(QPainter::Antialiasing, true);
	f.setPointSize(13);
	p.setFont(f);
	QTextOption t;
	t.setAlignment(Qt::AlignCenter);
	p.drawText(QRect(0, 0, 16, 16), QString(QLatin1Char('A')), t);
	return QPixmap::fromImage(img);
}

QIcon CGFontEditWidget::fontValueIcon(const QFont &f)
{
	return QIcon(fontValuePixmap(f));
}

QString CGFontEditWidget::fontValueText(const QFont &f)
{
	return QApplication::translate("QtPropertyBrowserUtils", "[%1, %2]", 0)
		.arg(f.family())
		.arg(f.pointSize());
}

///
QSwitchButton::QSwitchButton(QWidget *parent /*= 0*/) :   QAbstractButton(parent)
{
    animation=NULL;
    SetCheckedStyle(0);
    setCheckable(true);
    connect(this, SIGNAL(clicked(bool)), this, SLOT(animate(bool)));
    setAutoFillBackground(false);
    setAttribute(Qt::WA_NoSystemBackground);
    //
    pos=0.0;
    m_opacity =1.0;

}

QSwitchButton::~QSwitchButton()
{
    if(animation) delete animation;
}

void QSwitchButton::SetBgPixmap(QString png)
{
    m_pixmapBgPath=png;
    m_pixmapBg.load(UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP)+png);
    if(m_pixmapBg.width()>5&& m_pixmapBg.height()>5)
        resize(m_pixmapBg.size());
}

void QSwitchButton::SetForePixmap(QString png)
{
    m_pixmapForePath=png;
    m_pixmapFore.load(UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP)+png);
    if(isChecked())
        setInitState(true);
}

void QSwitchButton::SetCheckedStyle(int style)
{
    m_CheckedStyle=style;
    if(!animation && style!=QSwitchButton::NORMAL) {
        animation=new QPropertyAnimation(this);
        connect( animation, SIGNAL(finished()), this, SLOT(update()));
        animation->setTargetObject(this);
    }
    if(style==QSwitchButton::TWINKLE){
        animation->setPropertyName("opacity");
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InOutExpo);
    }
    else if(style==QSwitchButton::SLIDEH ||style==QSwitchButton::SLIDEV){
        animation->setPropertyName("position");
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->setDuration(300);
        animation->setEasingCurve(QEasingCurve::InOutExpo);
    }
}

void QSwitchButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if(m_CheckedStyle==CHECK_TYPE::NORMAL){
        if(isChecked())
            painter.drawPixmap(rect() ,  m_pixmapBg);
        else
            painter.drawPixmap(rect() ,  m_pixmapFore);
    }
    else
        drawSlider(&painter);
}

void QSwitchButton::setInitState(bool checked)
{
    if(checked){
        pos=1.0;
    }
}

void QSwitchButton::setPosition(qreal value)
{
    pos = value;
    repaint();
}

void QSwitchButton::animate(bool checked)
{
    if(animation){
        animation->setDirection(checked ? QPropertyAnimation::Forward : QPropertyAnimation::Backward);
        animation->start();
    }
}

void QSwitchButton::drawSlider(QPainter *painter)
{
    QRectF r = rect();//.adjusted(0, 0, -1, -1);

    if(!m_pixmapFore.isNull()){
        if(m_pixmapBg.width()>0) sliderShape.setWidth(r.width()/m_pixmapBg.width() *m_pixmapFore.width());
        if(m_pixmapBg.height()>0) sliderShape.setHeight(r.height()/m_pixmapBg.height() *m_pixmapFore.height());
    }

    qreal dx = (r.width() - sliderShape.width()) * pos;
    QRectF sliderRect = sliderShape.translated(dx, 0);
    if(! m_pixmapBg.isNull())
    {
        painter->drawPixmap(r.toRect(), m_pixmapBg);
        painter->drawPixmap(sliderRect.toRect(), m_pixmapFore);
    }
    else
    {

    }
}

void QSwitchButton::resizeEvent(QResizeEvent *e)
{
    repaint();
}

QSize QSwitchButton::sizeHint() const
{
    return QSize(48, 28);
}

bool QSwitchButton::hitButton(const QPoint& p) const
{
    return rect().contains(p);
}

////

class CTreeEntry
{
public:
    CTreeEntry(CTreeEntry* parent = NULL){SetParent( parent);};
    void SetParent(CTreeEntry* parent){
        m_pParent = parent;
        if (m_pParent)
            m_pParent->AppendChild(this);
    }
    CTreeEntry* Parent() { return m_pParent; }
    bool setCols(QStringList slist){ return setData(Qt::StatusTipRole,slist );};
    bool setData(int role,const QVariant& val  ){m_vmap[role]=val; return true;};
    QVariant data(int role,int column) const {
        if(role==Qt::DisplayRole && m_vmap[Qt::StatusTipRole].isValid()){
           QStringList slist= m_vmap[Qt::StatusTipRole].toStringList();
           if(slist.size()>column)
               return slist[column];
        }
        return m_vmap[role];
    };

    virtual void AppendChild( CTreeEntry* pItem){
            m_ChildList.append(pItem);
            pItem->m_pParent = this;
    }
    virtual void RemoveChild( int idx) {m_ChildList.removeAt(idx);};
    int ChildCount() {return m_ChildList.size();};
    int ColumnCount(){
        if( m_vmap[Qt::StatusTipRole].isValid()){
           QStringList slist= m_vmap[Qt::StatusTipRole].toStringList();
           return slist.size();
        }
        return 1;
    }

    virtual CTreeEntry* ChildItem(int row) const  {
        if (-1 < row && row < m_ChildList.size())
            return m_ChildList[row];
        else
            return NULL;
    }
    virtual int row() const{
        if (m_pParent)
            return m_pParent->m_ChildList.indexOf(const_cast<CTreeEntry*>(this));
        return 0;
    }
    void clear()    {
        foreach(CTreeEntry* pEntry,m_ChildList)
            delete pEntry;
        m_ChildList.clear();
    }

protected:
    CTreeEntry* m_pParent;
    QList<CTreeEntry*> m_ChildList;
    QMap<int,QVariant> m_vmap;
};


/////
void  parseJsonValue(const QJsonValue &jsonValue, int column, CTreeEntry *node);
void  parseObject(const QJsonObject &object,int column, CTreeEntry *parent)
{
    CTreeEntry *child =new CTreeEntry(parent);
 /*   if(!object["text"].isString())
        return;*/

    child->setData(Qt::DisplayRole, object["text"].toString());
    if(object["id"].isString())
        child->setData(Qt::UserRole,object["id"].toString());
    //if(object["expanded"].isString())
        //child->setExpanded(object["expanded"].toString().toInt());
    if(object["data"].isString())
        child->setData(Qt::WhatsThisRole,object["data"].toString());
    if(object["cols"].isArray())
        child->setData(Qt::StatusTipRole,object["cols"].toArray());

    if(object["icon"].isString())
    {
        QString icon=object["icon"].toString();
        if(icon.startsWith("fa-")){

            child->setData(Qt::DecorationRole,UnqAwe()->icon(icon.right(icon.length()-3) ));
        }
        else{
            icon = UnqFunc()->GetDir(CGFunc::PATH_TYPE_PIXMAP)+ icon;
            child->setData(Qt::DecorationRole,QPixmap(icon));
        }
    }
    if(object["checked"].isString())
    {
        //child->setFlags(child->flags()|Qt::ItemIsUserCheckable);
        //child->setCheckState(column,(Qt::CheckState)object["checked"].toString().toInt());
    }
    else if (object["checked"].isUndefined()==false)
    {
        //child->setFlags(child->flags() | Qt::ItemIsUserCheckable);
        //child->setCheckState(column, (Qt::CheckState)object["checked"].toInt());
    }
    QJsonValue value = object["children"];
    if(value.isArray())
        parseJsonValue(value,column, child);
}

void  parseJsonValue(const QJsonValue &jsonValue, int column, CTreeEntry *node)
{
  QJsonArray  array;
  switch (jsonValue.type()) {
  case QJsonValue::Null:
    //qDebug() << "NULL Json Value, check your request";
    break;
  case QJsonValue::Undefined:
   // qDebug() << "Undefined Json Value, check your request";
    break;
  case QJsonValue::Array:// Array used Key(array.at(i)) ：null
    array = jsonValue.toArray();
    for (int i = 0; i < array.size(); i++) {
        parseJsonValue(array[i], 0, node);// new QTreeWidgetItem(node));
    }
    break;
  case QJsonValue::Object:
    parseObject(jsonValue.toObject(),column, node);
    break;
  default:
    //qDebug() << "what's the fucking in parseJsonValue default";
    break;
  }
}

CGTreeModel::CGTreeModel(QObject * parent):QAbstractItemModel(parent)
{
    m_pRootEntry = new CTreeEntry();
    m_pRootEntry->clear();
}

CGTreeModel::~CGTreeModel()
{
    delete m_pRootEntry;
}

void CGTreeModel::SetHeader(QStringList slist)
{
    m_pRootEntry->setCols(slist);
}

QVariant CGTreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return m_pRootEntry->data(role,section);

    return QVariant();
}

bool CGTreeModel::setData( const QModelIndex & index, const QVariant & value, int role )
{
    if (!index.isValid() || 0 != index.column())
        return false;

    CTreeEntry* pItem = static_cast<CTreeEntry*>(index.internalPointer());
    return pItem->setData(role,value );
}

QVariant CGTreeModel::data( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
        return QVariant();
    CTreeEntry* pItem = static_cast<CTreeEntry*>(index.internalPointer());
    return pItem->data(role,index.column());
}

int CGTreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<CTreeEntry*>(parent.internalPointer())->ColumnCount();
    else
        return m_pRootEntry->ColumnCount();
}
int CGTreeModel::rowCount( const QModelIndex & parent ) const
{
    CTreeEntry *parentItem;
    if (parent.column() > 0)
        return 0;
    if (!parent.isValid())
        parentItem = m_pRootEntry;
    else
        parentItem = static_cast<CTreeEntry*>(parent.internalPointer());

    return parentItem->ChildCount();
}

QModelIndex CGTreeModel::index( int row, int column, const QModelIndex & parent ) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    CTreeEntry *parentItem;
    if (!parent.isValid())
        parentItem = m_pRootEntry;

    else
        parentItem = static_cast<CTreeEntry*>(parent.internalPointer());

    CTreeEntry *childItem = parentItem->ChildItem(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex CGTreeModel::parent( const QModelIndex & index ) const
{
    if (!index.isValid())
        return QModelIndex();

    CTreeEntry *childItem = static_cast<CTreeEntry*>(index.internalPointer());
    CTreeEntry *parentItem = childItem->Parent();
    if (parentItem == m_pRootEntry || NULL == parentItem )
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}


bool CGTreeModel::Load(const QVariant& data)
{
    QJsonValue jobj;
    if (data.type() == QVariant::Map)
        jobj=QJsonObject::fromVariantMap(data.toMap());
    else if(data.canConvert<QJsonValue>())
        jobj=data.toJsonValue() ;
    else if(data.type() == QVariant::List ){
       jobj= QJsonArray::fromVariantList(data.toList());
    }

    m_pRootEntry->clear();
    beginResetModel();

    parseJsonValue(jobj,0,m_pRootEntry);

    endResetModel();

    return true;
}

void CGTreeModel::InsertItem(QString itemName, QString itemType, QString classType, QString tip, QString fileIconName)
{

}


class CTreeProxyModel:public QSortFilterProxyModel
{
public:
    virtual bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;
    void OnFilterChanged(const QString&);

private:
    QRegExp m_regExp;
};

bool CTreeProxyModel::filterAcceptsRow(int source_row, const QModelIndex & source_parent) const
{
    QModelIndex idx = sourceModel()->index(source_row,0,source_parent);
	QString pinyinStr(CGFunc::getPinyinFromUTF8(sourceModel()->data(idx, Qt::DisplayRole).toString().toUtf8()).c_str());
	//printf("pinyin value is:%s\n", pinyinStr.toStdString().c_str());
    bool accept=sourceModel()->data(idx, Qt::DisplayRole).toString().contains(m_regExp) || pinyinStr.contains(m_regExp);
    if(accept)
        return true;
    else{
        // check all decendant's
        //QModelIndex source_index = sourceModel()->index(source_row, 0, source_parent);
        for (int k=0; k<sourceModel()->rowCount(idx); k++)
        {
            if (filterAcceptsRow(k, idx))
            {
                return true;
            }
        }
    }
    return false;
}

void CTreeProxyModel::OnFilterChanged(const QString& str)
{
    m_regExp.setPattern(str);
    invalidateFilter();
}


CGTreeView::CGTreeView(QWidget* parent): QTreeView(parent)
{
    setFocusPolicy(Qt::NoFocus);
    //setIndentation(0);
    //setRootIsDecorated(false);
    //header()->hide();
    header()->setSectionResizeMode(QHeaderView::Stretch);
     setTextElideMode(Qt::ElideMiddle);
     setVerticalScrollMode(ScrollPerPixel);
    setAlternatingRowColors(true);
    //setItemDelegate(new SheetDelegate(this, this));
     setIconSize(QSize(32, 32));

     m_proxyModel = new CTreeProxyModel();
     m_proxyModel->setSourceModel(&m_sourceModel);
     setModel(m_proxyModel);
     //m_pItemTree->setExpanded(m_pItemTree->model()->index(0,0),true);
     //m_pItemTree->setExpanded(m_pItemTree->model()->index(3,0),true);

    QObject::connect(this, SIGNAL(doubleClicked(const QModelIndex& )), this, SLOT(OnDbClicked ( const QModelIndex& )));
    QObject::connect(this, SIGNAL(clicked(const QModelIndex& )), this, SLOT(OnClicked ( const QModelIndex& )));

    m_ContextMenu = new QMenu(this);
    m_ContextMenu->setToolTipsVisible(true);
}


void CGTreeView::OnClicked ( const QModelIndex& index )
{
    //if (!index.parent().isValid())
        //return;
    QString text = model()->data(currentIndex(), Qt::DisplayRole).toString();
    QString data = model()->data(currentIndex(), Qt::WhatsThisRole).toString();

    emit ItemClicked(0,0,  text, data );
}
void CGTreeView::OnDbClicked ( const QModelIndex& index )
{
    //if (!index.parent().isValid())
        //return;
    QString text = model()->data(currentIndex(), Qt::DisplayRole).toString();
    QString data = model()->data(currentIndex(), Qt::WhatsThisRole).toString();

    emit ItemDoubleClicked(0,0,  text, data );
}
void CGTreeView::contextMenuEvent( QContextMenuEvent* event )
{
    if(!currentIndex().isValid())
        return;

   // QString symbolName = model()->data(currentIndex(), ItemTreeModel::TypeNameRole).toString();
  /*  QMenu cMenu(this);
    cMenu.addAction(tr("delete Icon"), this, SLOT(OnContextMenuClicked()));
    cMenu.addAction(tr("rename Icon"), this, SLOT(OnContextMenuClicked()));
    cMenu.addAction(tr("edit Icon"), this, SLOT(OnContextMenuClicked()));
    cMenu.exec(e->globalPos());*/


    QString txt=model()->data(currentIndex(),Qt::DisplayRole).toString();
    QString data=model()->data(currentIndex(),Qt::WhatsThisRole).toString();
    m_ContextMenuPos = event->pos();

    if (currentIndex().isValid()){
        emit RequestContextMenu(-1,-1, txt, data);
    }
    else
        emit RequestContextMenu(-1, -1, "", "");

    QTreeView::contextMenuEvent(event);

}


void CGTreeView::mousePressEvent(QMouseEvent *event)
{
    m_ContextMenu->hide();
    QTreeView::mousePressEvent(event);
}

void CGTreeView::ShowContextMenu(QVariant menu)
{
    g_ShowContextMenu(this, m_ContextMenu, m_ContextMenuPos,menu);
}

void CGTreeView::OnContextMenuClicked()
{
    m_ContextMenu->hide();
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString menuStr = action->text();
        QVariant menuData = action->data();

        QString txt=model()->data(currentIndex(),Qt::DisplayRole).toString();
        QString data=model()->data(currentIndex(),Qt::WhatsThisRole).toString();

        if (currentIndex().isValid())
            emit ContextMenuClicked(-1, -1, menuStr, menuData);
        else
            emit ContextMenuClicked(-1, -1,menuStr, menuData);
    }
}



void CGTreeView::OnFilterChanged(const QString& str)
{
    if (!str.isEmpty())
    {
        for (int i = 0;i< model()->rowCount(QModelIndex());i++)
        {
             setExpanded( model()->index(i,0),true);
        }
    }
    m_proxyModel->OnFilterChanged(str);
}
void CGCheckBox::SetIcon(QString iconFile, QString pathType)
{
	int  path = CGFunc::PATH_TYPE_ACTIONICON;
	if (pathType == "images")
	{
		path = CGFunc::PATH_TYPE_PIXMAP;
	}
	UnqFunc()->GetFilePathName(path, iconFile, iconFile);
	this->setIcon(QIcon(iconFile));
}
void CGCheckBox::SetIconSize(int w, int h)
{
	this->setIconSize(QSize(w,h));
}
