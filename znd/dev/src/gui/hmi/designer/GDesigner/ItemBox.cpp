
#include <QtCore>
#include <QtGui>
#include "ItemBox.h"
#include "CursorManager.h"
#include "IconMng.h"
#include "GFunc.h"
#include "DesignerWnd.h"

class TreeEntry
{
public:
    friend class ItemTreeModel;
    virtual bool SetValue(const QVariant& val,int role) = 0;
    virtual QVariant Value(int role) const = 0;
    virtual void Save(QXmlStreamWriter* xio) const = 0;

    virtual void AppendChild( TreeEntry* pItem);
    virtual void RemoveChild( int idx) {m_ChildList.removeAt(idx);};
    virtual int ChildCount() {return m_ChildList.size();};
    virtual TreeEntry* Parent() { return m_pParent; }
    virtual TreeEntry* ChildItem(int row) const;
    virtual int row() const;
    void clear()
    {
        foreach(TreeEntry* pEntry,m_ChildList)
            delete pEntry;
        m_ChildList.clear();
    };
protected:
    TreeEntry* m_pParent;
    QString m_name;
    int m_tp;
    QList<TreeEntry*> m_ChildList;
};

TreeEntry* TreeEntry::ChildItem(int row) const
{
    if (-1 < row && row < m_ChildList.size())
        return m_ChildList[row];
    else
        return NULL;
}
int TreeEntry::row() const
{
    if (m_pParent)
        return m_pParent->m_ChildList.indexOf(const_cast<TreeEntry*>(this));

    return 0;
}


class RootEntry:public TreeEntry
{
    friend class ItemTreeModel;
public :

    virtual bool SetValue(const QVariant& val,int role) {return false;};
    virtual QVariant Value(int role) const {return QVariant();};
    virtual void Save(QXmlStreamWriter* xio) const;
};
void RootEntry::Save(QXmlStreamWriter* xio) const
{
    foreach(TreeEntry* pEntry,m_ChildList)
        pEntry->Save(xio);
}

class GroupEntry:public TreeEntry
{
public:
    friend class ItemTreeModel;
    bool SetValue(const QVariant& val,int role);
    QVariant Value(int role) const;
    void Save(QXmlStreamWriter* xio) const;

private:
    GroupEntry(TreeEntry* parent = NULL);
    bool m_isEditable;
	bool m_isPinPlane;
    int m_pinNums;
    int m_statusNums;
    QString m_planes;
};

GroupEntry::GroupEntry(TreeEntry* parent)
{
    m_pParent = parent;
    if (m_pParent)
        m_pParent->AppendChild(this);
}
bool GroupEntry::SetValue(const QVariant& val,int role)
{
    if (role == Qt::DisplayRole)
        m_name = val.toString() ;
    else if ( ItemTreeModel::TypeRole == role )
        m_tp = val.toInt();
    else if ( ItemTreeModel::IsEditableRole == role )
        m_isEditable = val.toBool();
	else if (ItemTreeModel::IsPinPlaneRole == role)
		m_isPinPlane = val.toBool();
    else if ( ItemTreeModel::PinNumsRole == role )
        m_pinNums = val.toInt();
    else if ( ItemTreeModel::StatusNumsRole == role )
        m_statusNums = val.toInt();
    else if ( ItemTreeModel::PlanesRole == role )
        m_planes = val.toString();
    else
        return false;

    return true;
}
QVariant GroupEntry::Value(int role) const
{
    if (role == Qt::DisplayRole)
        return m_name;
    else if ( ItemTreeModel::TypeRole == role )
        return m_tp ;
    else if ( ItemTreeModel::IsEditableRole == role )
        return m_isEditable;
	else if (ItemTreeModel::IsPinPlaneRole == role)
		return m_isPinPlane;
    else if ( ItemTreeModel::PinNumsRole == role )
        return m_pinNums;
    else if ( ItemTreeModel::StatusNumsRole == role )
        return m_statusNums;
    else if ( ItemTreeModel::PlanesRole == role )
        return m_planes;
    else
        return QVariant();
}

void GroupEntry::Save(QXmlStreamWriter* xio) const
{
    xio->writeStartElement(m_name);
    xio->writeAttribute("type",QString("%1").arg(m_tp));
    xio->writeAttribute("is_editable",m_isEditable? "1" : "0");
	xio->writeAttribute("is_pinplane", m_isPinPlane ? "1" : "0");
    xio->writeAttribute("pin_nums",QString("%1").arg(m_pinNums) );
    xio->writeAttribute("status_nums",QString("%1").arg(m_statusNums));
    xio->writeAttribute("plane_info",m_planes);
    foreach(TreeEntry* pEntry,m_ChildList)
        pEntry->Save(xio);
    xio->writeEndElement();
}

class ItemEntry:public TreeEntry
{
public:
    friend class ItemTreeModel;
    bool SetValue(const QVariant& val,int role);
    QVariant Value(int role) const;
    void Save(QXmlStreamWriter* xio) const ;

private:
    ItemEntry(TreeEntry* parent = NULL);
    void SetParent(TreeEntry* parent);

    QString m_tpName;
    QPixmap m_icon;
    QString m_iconFileName;
    bool m_isCommon;
    QString m_disName;
};

ItemEntry::ItemEntry(TreeEntry* parent)
{
    m_pParent = parent;
    if (m_pParent)
        m_pParent->AppendChild(this);
}
void ItemEntry::SetParent(TreeEntry* parent)
{
    m_pParent = parent;
    if (m_pParent)
        m_pParent->AppendChild(this);
}

void ItemEntry::Save(QXmlStreamWriter* xio) const
{
    xio->writeStartElement(m_name);
    xio->writeAttribute("typeN",m_tpName);
    xio->writeAttribute("type",QString("%1").arg(m_tp));
    xio->writeAttribute("is_common",m_isCommon ? "1":"0");
    xio->writeAttribute("iconset",m_iconFileName);
    //xio->writeAttribute("disname",m_disName);
    xio->writeEndElement();
}


void TreeEntry::AppendChild( TreeEntry* pItem)
{
    m_ChildList.append(pItem);
    pItem->m_pParent = this;
}



bool ItemEntry::SetValue(const QVariant& val,int role)
{
    if (role == Qt::DisplayRole)
    {
        m_name = val.toString() ;
    }
    else if ( ItemTreeModel::TypeRole == role )
        m_tp = val.toInt();
    else if (ItemTreeModel::IsCommonRole == role)
        m_isCommon = val.toBool();
    else if (Qt::DecorationRole == role)
        m_icon = val.value<QPixmap>();
    else if (ItemTreeModel::TypeNameRole == role)
        m_tpName = val.toString();
    else if (ItemTreeModel::IconFileNameRole == role)
        m_iconFileName = val.toString();
    else
        return false;

    return true;
}
QVariant ItemEntry::Value(int role) const
{
    if (role == Qt::DisplayRole)
        return m_name;
    else if ( ItemTreeModel::TypeRole == role )
        return m_tp;
    else if (ItemTreeModel::IsCommonRole == role)
        return m_isCommon;
    else if (Qt::DecorationRole == role)
        return m_icon;
    else if (ItemTreeModel::TypeNameRole == role)
        return m_tpName;
	else if (ItemTreeModel::IconFileNameRole == role)
		return m_iconFileName;
    else
        return QVariant();
}



class SheetDelegate: public QItemDelegate
{
public:
    SheetDelegate(QTreeView *view, QWidget *parent);

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &opt, const QModelIndex &index) const;

private:
    QTreeView *m_view;
};



SheetDelegate::SheetDelegate(QTreeView *view, QWidget *parent)
    : QItemDelegate(parent),
      m_view(view)
{
}

void SheetDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const QAbstractItemModel *model = index.model();
    Q_ASSERT(model);

    if (model->parent(index).isValid())
    {
        QItemDelegate::paint(painter, option, index);
        return;
    }


    QStyleOptionButton buttonOption;
    buttonOption.state = option.state;
#ifdef Q_WS_MAC
    buttonOption.state |= QStyle::State_Raised;
#endif
    buttonOption.state &= ~QStyle::State_HasFocus;

    buttonOption.rect = option.rect;
    buttonOption.palette = option.palette;
    buttonOption.features = QStyleOptionButton::None;
    m_view->style()->drawControl(QStyle::CE_TabBarTab, &buttonOption, painter, m_view);

    QStyleOption branchOption;
    static const int i = 9;
    QRect r = option.rect;
    branchOption.rect = QRect(r.left() + i/2, r.top() + (r.height() - i)/2, i, i);
    branchOption.palette = option.palette;
    branchOption.state = QStyle::State_Children;

    if (m_view->isExpanded(index))
        branchOption.state |= QStyle::State_Open;

    m_view->style()->drawPrimitive(QStyle::PE_IndicatorBranch, &branchOption, painter, m_view);


    QRect textrect = QRect(r.left() + i*2, r.top(), r.width() - ((5*i)/2), r.height());
    QString text = elidedText(option.fontMetrics, textrect.width(), Qt::ElideMiddle,
                              model->data(index, Qt::DisplayRole).toString());
    m_view->style()->drawItemText(painter, textrect, Qt::AlignLeft,
                                  option.palette, m_view->isEnabled(), text);


}

QSize SheetDelegate::sizeHint(const QStyleOptionViewItem &opt, const QModelIndex &index) const
{
    QStyleOptionViewItem option = opt;
    QSize sz = QItemDelegate::sizeHint(opt, index) + QSize(5, 5);
    return sz;
}




class CItemProxyModel:public QSortFilterProxyModel
{
public:
    virtual bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;
    void OnFilterChanged(const QString&);
private:
    QRegExp m_regExp;
};

bool CItemProxyModel::filterAcceptsRow(int source_row, const QModelIndex & source_parent) const
{
    if(!source_parent.isValid())
        return true;

    QModelIndex idx = sourceModel()->index(source_row,0,source_parent);
    return sourceModel()->data(idx,Qt::DisplayRole).toString().contains(m_regExp);
}

void CItemProxyModel::OnFilterChanged(const QString& str)
{
    m_regExp.setPattern(str);
    invalidateFilter();
}
QHash<QString, QIcon> ItemTreeModel::nameToIconHash;


ItemTreeModel* UnqItemMng()
{
    static ItemTreeModel model;
    return &model;
}

ItemTreeModel::ItemTreeModel(QObject * parent):QAbstractItemModel(parent)
{
    m_pRootEntry = new RootEntry;
    m_ToolBoxConfFile=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ETC)+"/gtoolbox.xml";
}

ItemTreeModel::~ItemTreeModel()
{
    delete m_pRootEntry;
}

bool ItemTreeModel::setData( const QModelIndex & index, const QVariant & value, int role )
{
    if (!index.isValid() || 0 != index.column())
        return false;

    ItemEntry* pItem = static_cast<ItemEntry*>(index.internalPointer());
    return pItem->SetValue(value,role);
    return true;
}

QVariant ItemTreeModel::data( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
        return QVariant();
    TreeEntry* pItem = static_cast<TreeEntry*>(index.internalPointer());
    return pItem->Value(role);
}

int ItemTreeModel::rowCount( const QModelIndex & parent ) const
{
    TreeEntry *parentItem;
    if (parent.column() > 0)
        return 0;
    if (!parent.isValid())
        parentItem = m_pRootEntry;
    else
        parentItem = static_cast<TreeEntry*>(parent.internalPointer());

    return parentItem->ChildCount();
}

QModelIndex ItemTreeModel::index( int row, int column, const QModelIndex & parent ) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeEntry *parentItem;

    if (!parent.isValid())
        parentItem = m_pRootEntry;

    else
        parentItem = static_cast<TreeEntry*>(parent.internalPointer());

    TreeEntry *childItem = parentItem->ChildItem(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex ItemTreeModel::parent( const QModelIndex & index ) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeEntry *childItem = static_cast<TreeEntry*>(index.internalPointer());
    TreeEntry *parentItem = childItem->Parent();

    if (parentItem == m_pRootEntry || NULL == parentItem )
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

bool ItemTreeModel::SetupModelData(const QString& confFile)
{
    m_pRootEntry->clear();
    m_ToolBoxConfFile=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ETC)+confFile;
    QFile file(m_ToolBoxConfFile);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(NULL, tr("tip"), tr("Cannot read file %1 ").arg(confFile.toLocal8Bit().data()) );
        return  false;
    }

    QStringList LstNames;
    QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ICON);

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&file);
    if(!xmlReader.readNextStartElement())
        return false;

    beginResetModel();
    QXmlStreamAttributes xmlAttrs;
    xmlAttrs = xmlReader.attributes();
    while(xmlReader.readNextStartElement())
    {
        xmlAttrs = xmlReader.attributes();
        GroupEntry* pGroupItem = new GroupEntry(m_pRootEntry);
        QString typeN = xmlReader.name().toString();
        QString status_nums = xmlAttrs.value("status_nums").toString();
        QString pin_nums = xmlAttrs.value("pin_nums").toString();
        QString type = xmlAttrs.value("type").toString();
        QString planes = xmlAttrs.value("plane_info").toString();
		QString isPinPlane = xmlAttrs.value("is_pinplane").toString();

		pGroupItem->SetValue(typeN, Qt::DisplayRole);
        pGroupItem->SetValue(xmlAttrs.value("is_editable").toString(),IsEditableRole);
		pGroupItem->SetValue(isPinPlane, IsPinPlaneRole);
        pGroupItem->SetValue(status_nums,StatusNumsRole);
        pGroupItem->SetValue(pin_nums,PinNumsRole);
        pGroupItem->SetValue(type,TypeRole);
        pGroupItem->SetValue(planes,PlanesRole);

        if(!type.isEmpty() && type.toInt()!=0 )
        {
			UnqIconMng()->InsertIconType(type.toInt(), typeN, pin_nums.toInt(), status_nums.toInt(), planes, isPinPlane);
        }

        while(xmlReader.readNextStartElement())
        {
			QString itemDisplayName = xmlReader.name().toString();
			
            ItemEntry* pItem = new ItemEntry();
            xmlAttrs = xmlReader.attributes();

            QString IconFileName = xmlAttrs.value("iconset").toString();
            QPixmap ItemIcon(ITEMICONSIZE,ITEMICONSIZE);
            QPixmap CursorIcon(CURSORICONSIZE,CURSORICONSIZE);
            if (!IconFileName.isEmpty() && QFile::exists(UnqFunc()->GetItemIconName(IconFileName)))
                CursorIcon = ItemIcon = QPixmap(UnqFunc()->GetItemIconName(IconFileName));

			QString itemName = xmlAttrs.value("typeN").toString();
			//check if the ivg file exists
			QString ivgFile = itemName;
			UnqFunc()->GetIconPathNameByIconCoreName(ivgFile.replace(ICONPREFIX, ""), ivgFile);
			if (!QFile(ivgFile).exists() && (!type.isEmpty() && type.toInt() != 0))
			{
				xmlReader.skipCurrentElement();
				continue;
			}
            UnqIconMng()->InsertIconName(typeN, itemName);
            int is_common = xmlAttrs.value("is_common").toString().toInt();


            if(qBinaryFind(LstNames.begin(),LstNames.end(),itemName) == LstNames.end())
                (LstNames << itemName).sort();
            else
            {
                xmlReader.skipCurrentElement();
                continue;
            }

            if(is_common == 0)
            {
                if(IconFileName.isEmpty() || !QFile::exists(UnqFunc()->GetItemIconName(IconFileName)))
                {
                    if(!UnqIconMng()->Icon(itemName) )
                    {
                        xmlReader.skipCurrentElement();
                        continue;
                    }
                    UnqIconMng()->Icon(itemName)->GetItemIcon(ItemIcon);
                    CursorIcon=ItemIcon;

                }
            }
        
            m_ItemTypeName[itemName]=itemDisplayName;

            pItem->SetValue(itemDisplayName,Qt::DisplayRole);
            pItem->SetValue(ItemIcon,Qt::DecorationRole);
            pItem->SetValue(xmlAttrs.value("type").toString().toInt(),TypeRole);
            pItem->SetValue(is_common,IsCommonRole);
            pItem->SetValue(itemName,TypeNameRole);
            pItem->SetValue(IconFileName,IconFileNameRole);
            pItem->SetParent(pGroupItem);

            UnqCursorMng()->InsertNewTp(itemName,UnqCursorMng()->MakeIconCrossCursor(CursorIcon));

            int type = ItemFactory::ItemType(itemName);
            ItemTreeModel::nameToIconHash.insert(itemName, ItemIcon);

            xmlReader.skipCurrentElement();
        }
    }
    endResetModel();
    file.close();
    ItemTreeModel::nameToIconHash.insert(ItemFactory::ItemTypeName(Hmi::Group), QPixmap(UnqFunc()->GetItemIconName("group.png")));
    return true;
}
bool ItemTreeModel::SaveModelData()
{

    QFile file(m_ToolBoxConfFile);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(NULL, tr("tip"), tr("Cannot read file  %1.").arg(m_ToolBoxConfFile.toLocal8Bit().data()));
        return false;
    }
    QXmlStreamWriter xio(&file);
    xio.setCodec( QTextCodec::codecForName(LOCAL_LANGUAGE));
    xio.setAutoFormatting(true);
    xio.writeStartDocument();
    xio.writeStartElement("powergraph");
    xio.writeAttribute("version","3.0");
    m_pRootEntry->Save(&xio);
    xio.writeEndElement();
    xio.writeEndDocument();
    return true;
}

void ItemTreeModel::InsertItem(QString itemName, QString itemType, QString classType, QString tip, QString fileIconName)
{
    QString isCommon="0";
    QPixmap itemPixmap(ITEMICONSIZE,ITEMICONSIZE);
    QPixmap cursorPixmap(CURSORICONSIZE,CURSORICONSIZE);

	QString itemTPName = itemName;
	itemTPName = UnqIconMng()->GetRegIconName(itemTPName);
	UnqIconMng()->Icon(itemTPName)->GetItemIcon(itemPixmap);
	cursorPixmap = itemPixmap;

    for (int i = 0 ;i< m_pRootEntry->ChildCount();i++)
    {
        if (m_pRootEntry->ChildItem(i)->Value(ItemTreeModel::TypeRole).toString() == classType)
        {
			for (int j = 0; j < m_pRootEntry->ChildItem(i)->ChildCount(); j++){
				QString dispname = m_pRootEntry->ChildItem(i)->ChildItem(j)->Value(Qt::DisplayRole).toString();
				if (dispname == itemName || dispname== tip)
                {
					QString fileIcon = data(index(j, 0, index(i, 0)), ItemTreeModel::IconFileNameRole).toString();
					if (fileIcon.isEmpty())
					{
						QVariant val;
						val.setValue(itemPixmap);
						setData(index(j, 0, index(i, 0)), val, Qt::DecorationRole);
					}				
                    return ;
                }
			}
               

            beginInsertRows(this->index(i,0),m_pRootEntry->ChildItem(i)->ChildCount(),m_pRootEntry->ChildItem(i)->ChildCount());
            ItemEntry* pItem = new ItemEntry(m_pRootEntry->ChildItem(i));
           
            if(tip.isEmpty())
                tip=itemName;
            pItem->SetValue(tip,Qt::DisplayRole);//itemName
            pItem->SetValue(itemTPName,ItemTreeModel::TypeNameRole);
            pItem->SetValue(itemType,ItemTreeModel::TypeRole);
			if (fileIconName.isEmpty())
                pItem->SetValue(itemPixmap,Qt::DecorationRole);
			else
			{
				QPixmap fileIcon;
				fileIcon.load(fileIconName);;
				pItem->SetValue(fileIcon, Qt::DecorationRole);
			}
			UnqFunc()->GetGraphNameByGraphPathName(fileIconName, fileIconName);
			pItem->SetValue(fileIconName, ItemTreeModel::IconFileNameRole);
            pItem->SetValue(isCommon,ItemTreeModel::IsCommonRole);
            //pItem->SetValue(tip,Qt::ToolTipRole) ;
			m_ItemTypeName[itemTPName] = tip;
            UnqCursorMng()->InsertNewTp(itemTPName,UnqCursorMng()->MakeIconCrossCursor(cursorPixmap));
            ItemTreeModel::nameToIconHash.insert(itemTPName, itemPixmap);
            endInsertRows();
        }
    }
}



void ItemTreeModel::InsertItem(const QStringList& ItemNameInfo,Hmi::ItemType tp,const QList<QPixmap>& icons,bool isCommon )
{

    for (int i = 0 ;i< m_pRootEntry->ChildCount();i++)
    {
        if (m_pRootEntry->ChildItem(i)->Value(ItemTreeModel::TypeRole).toString() == ItemNameInfo[1])
        {

            for(int j = 0;j<m_pRootEntry->ChildItem(i)->ChildCount();j++)
                if (m_pRootEntry->ChildItem(i)->ChildItem(j)->Value(Qt::DisplayRole).toString() == ItemNameInfo[0])
                {
                    return ;
                }

            beginInsertRows(this->index(i,0),m_pRootEntry->ChildItem(i)->ChildCount(),m_pRootEntry->ChildItem(i)->ChildCount());
            ItemEntry* pItem = new ItemEntry(m_pRootEntry->ChildItem(i));
            QString itemTPName = ItemNameInfo[0];
            itemTPName=UnqIconMng()->GetRegIconName(itemTPName);

            pItem->SetValue(ItemNameInfo[0],Qt::DisplayRole);
            pItem->SetValue(itemTPName,ItemTreeModel::TypeNameRole);
            pItem->SetValue(tp,ItemTreeModel::TypeRole);
            pItem->SetValue(icons[0],Qt::DecorationRole);
            pItem->SetValue(isCommon,ItemTreeModel::IsCommonRole);
            if(ItemNameInfo.size() > 2) pItem->SetValue(ItemNameInfo[2],Qt::ToolTipRole) ;
            UnqCursorMng()->InsertNewTp(itemTPName,UnqCursorMng()->MakeIconCrossCursor(icons[1]));
            ItemTreeModel::nameToIconHash.insert(itemTPName, icons[0]);
            endInsertRows();
        }
    }
}



bool ItemTreeModel::RemoveItem(const QStringList& ItemInfo)
{
    for (int i = 0 ;i< m_pRootEntry->ChildCount();i++)
    {
        if (m_pRootEntry->ChildItem(i)->Value(ItemTreeModel::TypeRole).toString() == ItemInfo[1])
        {
            for(int j = 0;j<m_pRootEntry->ChildItem(i)->ChildCount();j++)
                if (m_pRootEntry->ChildItem(i)->ChildItem(j)->Value(Qt::DisplayRole).toString() == ItemInfo[0])
                {
                    beginRemoveRows(this->index(i,0),j,j);
                    m_pRootEntry->ChildItem(i)->RemoveChild(j);
                    UnqCursorMng()->RemoveTp(ItemInfo[0]);
                    endRemoveRows();
                    return true;
                }
        }
    }
    return false;
}


QString ItemTreeModel::ItemDisplayName(QString type)
{
    if (m_ItemTypeName.find(type)!=m_ItemTypeName.end())
    {
        return m_ItemTypeName[type];
    }
    else
        return tr("icon");

}

const int INVALID_TYPE = -1;


CItemTree::CItemTree(QWidget* parent): QTreeView(parent)
{
    setFocusPolicy(Qt::NoFocus);
    //setIndentation(0);
    //setRootIsDecorated(false);
    header()->hide();
    header()->setSectionResizeMode(QHeaderView::Stretch);
     setTextElideMode(Qt::ElideMiddle);
     setVerticalScrollMode(ScrollPerPixel);
	setAlternatingRowColors(true);
    //setItemDelegate(new SheetDelegate(this, this));
     setIconSize(QSize(32, 32));
    QObject::connect(this, SIGNAL(clicked(const QModelIndex& )), this, SLOT(OnClicked ( const QModelIndex& )));
}

void CItemTree::OnClicked ( const QModelIndex& index )
{
    if (!index.parent().isValid())
        return;
	QString symbolName = model()->data(currentIndex(), ItemTreeModel::TypeNameRole).toString();
	if (isFileExist(symbolName)==0)
		return;
    UnqDrawMng()->OnChangeCreateType(model()->data(index, ItemTreeModel::TypeNameRole).toString());
}

void CItemTree::contextMenuEvent( QContextMenuEvent* e )
{
    if(!currentIndex().isValid())
        return;
	if (!currentIndex().parent().isValid())
		return;

	UnqDrawMng()->SwitchMode(CDrawManager::MoveItem, true);

	QString symbolName = model()->data(currentIndex(), ItemTreeModel::TypeNameRole).toString();
	if (isFileExist(symbolName)!=1)
		return;

	QMenu cMenu(this);
	cMenu.addAction(tr("delete Icon"), this, SLOT(OnContextMenuClicked()));
	cMenu.addAction(tr("rename Icon"), this, SLOT(OnContextMenuClicked()));
	cMenu.addAction(tr("edit Icon"), this, SLOT(OnContextMenuClicked()));
	cMenu.exec(e->globalPos());
}

void CItemTree::OnContextMenuClicked()
{
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
	{
		QString symbolName = model()->data(currentIndex(), ItemTreeModel::TypeNameRole).toString();
		symbolName = symbolName.replace(ICONPREFIX, "");
		QString iconFileName;
		UnqFunc()->GetIconPathNameByIconCoreName(symbolName, iconFileName);

		QString menuStr = action->text();
		if (menuStr == tr("delete Icon"))
		{
			if (QMessageBox::No == QMessageBox::information(this, tr("Tips"), tr("already instance icons in graph are not delete together, sure to delete ?"), QMessageBox::Yes, QMessageBox::No))
				return;
			if (false == Mdi::CurrentWnd()->CloseFile(iconFileName))
				return;
			QStringList iconInfo;
			iconInfo << model()->data(currentIndex(), Qt::DisplayRole).toString();
			iconInfo << model()->data(currentIndex().parent(), ItemTreeModel::TypeRole).toString();
			UnqItemMng()->RemoveItem(iconInfo);
			UnqIconMng()->DelIcon(symbolName);
			UnqItemMng()->SaveModelData();//update toolbox.xml

			Mdi::CurrentWnd()->SyncFile(iconFileName, true);
		}
		else if (menuStr == tr("rename Icon"))
		{
            QString descname = model()->data(currentIndex(), Qt::DisplayRole).toString();

            if (QMessageBox::No == QMessageBox::information(this, tr("Tips"), tr("already instance icons in graph are not rename together, sure to rename ?"), QMessageBox::Yes, QMessageBox::No))
                return;
            bool ok = false;
            QString newName = QInputDialog::getText(this, tr("rename Icon"), tr("icon name:"), QLineEdit::Normal, descname, &ok);
            if (ok)
            {//check name
                if (newName.isEmpty())
                {
                    QMessageBox::information(this, tr("Tips"), tr("icon name can not be null!"));
                }
                else{
                    if (CDesignerWnd::CheckName(newName, true, true) < 0)
                        return;
                    model()->setData(currentIndex(), newName, Qt::DisplayRole);//update tree
                    UnqItemMng()->SaveModelData();//update toolbox.xml
                }
            }

            /*
			if (QMessageBox::No == QMessageBox::information(this, tr("Tips"), tr("already instance icons in graph are not rename together, sure to rename ?"), QMessageBox::Yes, QMessageBox::No))
				return;
			if (false == Mdi::CurrentWnd()->CloseFile(iconFileName))
				return;

			bool ok = false;
			QString newName;
			while (!ok)
			{
				newName = QInputDialog::getText(this, tr("rename Icon"), tr("icon name:"), QLineEdit::Normal, symbolName, &ok);
				if (ok)
				{//check name
					if (newName.isEmpty())
					{
						QMessageBox::information(this, tr("Tips"), tr("icon name can not be null!"));
						ok = false;
					}
					else
					{
						QString path;
						UnqFunc()->GetIconPathNameByIconCoreName(newName, path);
                        int ret = CDesignerWnd::CheckName(path, true, false, newName);
						if (ret < 0)
							ok = false;
					}

				}
                else
				    return;
			}
			if (ok)
			{
				UnqIconMng()->IconRename(symbolName, newName);//update iconMap; save to file

				model()->setData(currentIndex(), newName, Qt::DisplayRole);//update tree
				model()->setData(currentIndex(), UnqIconMng()->GetRegIconName(newName), ItemTreeModel::TypeNameRole);

				UnqItemMng()->SaveModelData();//update toolbox.xml
				
				QString iconFileName;
				UnqFunc()->GetIconPathNameByIconCoreName(symbolName, iconFileName);
				Mdi::CurrentWnd()->SyncFile(iconFileName, true);
				UnqFunc()->QSleep(500);
				UnqFunc()->GetIconPathNameByIconCoreName(newName, iconFileName);
				Mdi::CurrentWnd()->SyncFile(iconFileName, false);
			}
            */
		}
		else if (menuStr == tr("edit Icon"))
		{
			CIconItem* item = (CIconItem*)(UnqIconMng()->Icon(UnqIconMng()->GetRegIconName(symbolName)));
			if (item)
			{
				Mdi::CurrentWnd()->OnFileOpen(iconFileName);
			}
		}
	}
}

int CItemTree::isFileExist(QString symbolName)
{
	if (!symbolName.startsWith(ICONPREFIX))
		return -1;
	QString iconFileName = symbolName.replace(ICONPREFIX, "");
	UnqFunc()->GetIconPathNameByIconCoreName(iconFileName, iconFileName);
	QFile file(iconFileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::warning(0, tr("File"), tr("Open Icon file failed! To update icon now."));
		if (!UnqItemMng()->SetupModelData("gtoolbox.xml"))
		{
			QMessageBox::warning(this, tr("QXmlStream Bookmarks"), tr("Parse error in file"));
		}
		return 0;
	}
	return 1;
}

CItemBox::CItemBox(QWidget* parent):QWidget(parent)
{
    m_ifEditIcon=false;
    if(!UnqItemMng()->SetupModelData("gtoolbox.xml"))
    {
        QMessageBox::warning(this, tr("QXmlStream Bookmarks"), tr("Parse error in file"));
        return;
    }
    m_proxyModel = new CItemProxyModel();
    m_proxyModel->setSourceModel(UnqItemMng());

    QVBoxLayout* pVboxLayout = new QVBoxLayout(this);
    pVboxLayout->setMargin(0);

    QLineEdit* pFilterEdit = new QLineEdit(this);

    pVboxLayout->addWidget(pFilterEdit);

    m_pItemTree = new CItemTree(this);
    m_pItemTree->setModel(m_proxyModel);
    //m_pItemTree->setExpanded(m_pItemTree->model()->index(0,0),true);
    //m_pItemTree->setExpanded(m_pItemTree->model()->index(3,0),true);

    pVboxLayout->addWidget(m_pItemTree);

    setLayout(pVboxLayout);


    connect(pFilterEdit, SIGNAL(textChanged(const QString&)), this, SLOT(OnFilterChanged(const QString&)));
}

void CItemBox::SetScene(bool editIcon)
{
    if(editIcon){

    }
}

void CItemBox::OnFilterChanged(const QString& str)
{
    if (!str.isEmpty())
    {
        for (int i = 0;i<UnqItemMng()->rowCount(QModelIndex());i++)
        {
            m_pItemTree->setExpanded(m_pItemTree->model()->index(i,0),true);
        }
    }
    m_proxyModel->OnFilterChanged(str);
}
