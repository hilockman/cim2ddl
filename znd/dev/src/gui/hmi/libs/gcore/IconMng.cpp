

#include "GFunc.h"
#include "GraphSvgRW.h"
#include "IconMng.h"
#include "GroupItem.h"
#include "ItemFactory.h"
#include "GraphScene.h"

CIconMng* UnqIconMng()
{
    static CIconMng _instance;
    return &_instance;
}


CIconMng::CIconMng(QObject * parent) : QObject(parent)
{
}

bool CIconMng::Init()
{
    QString IconName;
    QString icon_path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ICON);

    QDir IconDir(icon_path);
    QString filter="*"+ICONSUFFIX;
    QFileInfoList FileList = IconDir.entryInfoList(QStringList(filter));

    for (int i=0;i<FileList.size();i++)
    {
        IconName=FileList[i].absoluteFilePath();
        AddIcon(IconName);
    }

    InitPathMap();
    return true;
}

bool CIconMng::Init(const QStringList& IconNames)
{
    foreach(QString name,IconNames)
    {
        AddIcon(name);
    }
    return true;
}

CIconMng::~CIconMng()
{
    QMap<QString,CIconItem*>::iterator it;
    for (it=m_IconMap.begin();it!=m_IconMap.end();++it)
    {

    }
    m_IconMap.clear();
}

QString CIconMng::GetRegIconName(QString tpName)
{
    if (tpName.left(5)!=ICONPREFIX)
    {
        tpName=ICONPREFIX+tpName;
    }
    return tpName;
}

int CIconMng::DelIcon(const QString& symbolName)
{
    QString tpName = symbolName;
    tpName=GetRegIconName(tpName);

    QMap<QString,CIconItem*>::iterator it = m_IconMap.find(tpName);
    if (it  == m_IconMap.end() )
    {
        QMessageBox::warning(NULL,QObject::tr("Warning"),QObject::tr("No find the symbol"));
    }
    delete m_IconMap[tpName];
    m_IconMap.erase(it);
    return 0;
}

int CIconMng::AddIcon(CIconItem* symbol,const QString& iconName)
{
    QString tpName = iconName;
    CIconData* pdata=(CIconData*)g_dataPtr(symbol);
    if (iconName.isEmpty())
    {
        tpName= pdata->GetTemplateName();
    }
    tpName=GetRegIconName(tpName);
    QMap<QString,CIconItem*>::iterator it=m_IconMap.find(tpName);
    if (it!=m_IconMap.end())
    {
        delete it.value();
    }
    m_IconMap[tpName]=dynamic_cast<CIconItem*>(pdata->Clone());
    m_IconMap[tpName]->setTransform(QTransform());

    return 0;
}
int CIconMng::AddIcon(const QString& fileName)
{
    bool ifNotRefThenSkip=true;
    CIconItem* SymbolItem = CGraphScene::IconLoadFromFile(fileName,ifNotRefThenSkip);
    if (SymbolItem)
    {
        QString iconName;
        UnqFunc()->GetGraphCoreNameByGraphPathName(fileName,iconName);
        AddIcon(SymbolItem,iconName);
        delete SymbolItem;
        return 0;
    }
    return -1;
}


const CIconItem* CIconMng::Icon(const QString& symbolName)
{
    QString tpName = symbolName;
    tpName=GetRegIconName(tpName);
    if (m_IconMap.find(tpName)!=m_IconMap.end())
        return m_IconMap[tpName];
    else
        return NULL;
}
CIconItem* CIconMng::DupIcon(const QString& tpName,QGraphicsScene* scene)
{
    if (m_IconMap.find(tpName)!=m_IconMap.end())
    {
        CIconItem* item=NULL;
        CIconItem* tempitem=m_IconMap[tpName];
        CIconData* pdata=(CIconData*)g_dataPtr(tempitem);
        if(scene && pdata->GetIfRef()==false)// if scene and not reference icon then load from file
        {
            QString fn=tpName;
            fn=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ICON)+fn.remove("icon-")+ICONSUFFIX;
            item = CGraphScene::IconLoadFromFile(fn);
        }
        else
        {
            item = (CIconItem*)(pdata->Clone());
        }
        return item;
    }
    else
        return NULL;
}

bool CIconMng::IsVaildIconName(const QString& name)
{
    if (m_IconMap.find(name)!=m_IconMap.end())
    {
        return false;
    }
    else
        return true;
}


void CIconMng::InsertIconType(int type, QString typeName, int pinNum, int stateNum, QString planeInfo, QString isPinPlane)
{
    QStringList info;
	info << typeName << QString("%1").arg(pinNum) << QString("%1").arg(stateNum) << planeInfo << isPinPlane;
    m_IconTypeMap[type]=info;
}
int CIconMng::GetIconType(int type, QString& typeName, int& pinNum, int& stateNum, QString& planeInfo, QString& isPinPlane)
{
    QStringList info;
    info=m_IconTypeMap[type];
    if (info.size()==5)
    {
        typeName=info[0];
        pinNum=info[1].toInt();
        stateNum=info[2].toInt();
        planeInfo=info[3];
		isPinPlane = info[4];
        return 0;
    }
    else
        return -1;
}

void CIconMng::InsertIconName(QString groupName, QString typeName)
{
    QMap<QString, QStringList>::iterator it = m_IconGroupMap.find(groupName);
    if (it != m_IconGroupMap.end())
        it.value().append(typeName);
    else
        m_IconGroupMap.insert(groupName, QStringList() << typeName);
}

int CIconMng::InitPathMap()
{
    m_icnPathMap.clear();
    QString IconName;
    QString icon_path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ICON);

    QDir IconDir(icon_path);
    QString filter="*.icn";
    QFileInfoList FileList = IconDir.entryInfoList(QStringList(filter));

    QString icnName;
    bool ifok=false;

    for (int i=0;i<FileList.size();i++)
    {
        QString buf=UnqFunc()->LoadFile(FileList[i].absoluteFilePath());
        QJsonObject obj= UnqFunc()->Str2Json(buf);
        if(!obj.isEmpty())
        {
            QString libname=obj["libname"].toString();
            QJsonObject tmpobj = obj["libinfo"].toObject();
            QJsonObject::iterator it=tmpobj.begin();
            for(it;it!=tmpobj.end();++it)
            {
                icnName=libname+"_"+it.key();
                QPainterPath path;
                ifok=UnqFunc()->ParsePathData(&it.value().toString(),path);
                m_icnPathMap[icnName]= path;
            }
        }
    }
    return 0;
}

QPainterPath CIconMng::GetPath(const QString& name)
{
    QPainterPath path;
    QMap<QString,QPainterPath>::iterator it=m_icnPathMap.find(name);
    if(it!=m_icnPathMap.end())
    {
        return m_icnPathMap[name];
    }
    else
    {
        path.addText(5,5,QFont(),"can not find icn");
        return path;
    }
}

QVariantMap CIconMng::getPathIconNames()
{
    QMap<QString, QVariant> nameMap;
    QMap<QString, QPainterPath>::iterator it;
    for (it = m_icnPathMap.begin(); it != m_icnPathMap.end(); ++it)
    {
        QStringList iconInfo = it.key().split("_");
        if (iconInfo.size() != 2)
            continue;
        if (nameMap.contains(iconInfo[0]))
        {
            nameMap[iconInfo[0]] = nameMap[iconInfo[0]].toStringList() << iconInfo[1];
        }
        else
        {
            nameMap.insert(iconInfo[0], QStringList() << iconInfo[1] );
        }
    }
    return QVariantMap(nameMap);
}

QVariantMap CIconMng::GetIconGroups()
{
    QMap<QString, QVariant> typeNameMap;
    QMap<QString, QStringList>::iterator it;
    for (it = m_IconGroupMap.begin(); it != m_IconGroupMap.end(); ++it)
    {
        typeNameMap.insert( it.key(), QVariant(it.value()));
    }
    return typeNameMap;
}

int CIconMng::IconRename(QString symbolName, QString newName)
{
	CIconItem* iconItem = (CIconItem*)(Icon(symbolName));
	if (!iconItem)
		return -1;
    CIconData* pidata = dynamic_cast<CIconData*>(g_dataPtr(iconItem));
    pidata->SetTemplateName(GetRegIconName(newName));
	AddIcon(iconItem);

	QString newPath;
	UnqFunc()->GetIconPathNameByIconCoreName(newName, newPath);
	QFile file(newPath);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return -1;
    int iType = pidata->GetIconType();

	CGraphSvgWriter xio(&file);
	xio.Init();
	xio.WriteAttribute("ftype", iType);

	pidata->SaveIconF(&xio);

	return 0;
}
