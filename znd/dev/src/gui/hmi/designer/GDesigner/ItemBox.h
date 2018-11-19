

#ifndef ITEMBOX_H
#define ITEMBOX_H 

#include "Global.h"

const int ITEMICONSIZE = 32;
class RootEntry;
class ItemTreeModel:public QAbstractItemModel
{

public:
    enum ItemBoxRole{
        TypeRole = Qt::UserRole+1,
        IsCommonRole ,
        TypeNameRole ,
        IconFileNameRole,
        IsEditableRole,
        PinNumsRole,
        StatusNumsRole,
        PlanesRole,
		IsPinPlaneRole
    };
    ItemTreeModel(QObject * parent = 0);
    ~ItemTreeModel();
    virtual bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    virtual QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const ;
    virtual int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
    virtual QModelIndex parent ( const QModelIndex & index ) const ;
    virtual int columnCount ( const QModelIndex & parent = QModelIndex() ) const {return 1;};

    static QHash<QString, QIcon> nameToIconHash;

	void InsertItem(QString itemName, QString itemType, QString classType, QString tip = QString(""), QString fileIconName = "");



    void InsertItem(const QStringList& ItemInfo,Hmi::ItemType tp,const QList<QPixmap>& icons,bool isCommon = false);
    bool RemoveItem(const QStringList& ItemInfo);
    bool SetupModelData(const QString &confFile);
    bool SaveModelData();
    QString ItemDisplayName(QString type);
	QMap<QString, QString> GetAllTypeDef(){ return m_ItemTypeName; };
private:
    RootEntry* m_pRootEntry;

    QMap<QString,QString> m_ItemTypeName;
    QString m_ToolBoxConfFile;

};
ItemTreeModel* UnqItemMng();




class CItemTree : public QTreeView
{
    Q_OBJECT

public:
    CItemTree(QWidget* parent =0);
    ~CItemTree() {}

signals:
    void SIGItemSelected(const QString& itemName, int type);
protected:
    void contextMenuEvent(QContextMenuEvent* e);
private slots:
    void OnClicked ( const QModelIndex& index );
	void OnContextMenuClicked();
private:
    bool m_iconMode;
	
	int isFileExist(QString symbolName);
};

class CItemProxyModel;
class CItemBox:public QWidget
{
    Q_OBJECT
public:
    CItemBox(QWidget* parent);
    void SetScene(bool editIcon);
private slots:
    void OnFilterChanged(const QString&);
private:
    CItemTree* m_pItemTree;
    CItemProxyModel* m_proxyModel;
    bool m_ifEditIcon;
};



#endif
