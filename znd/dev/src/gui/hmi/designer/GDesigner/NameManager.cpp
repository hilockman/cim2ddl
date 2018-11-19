

#include <QSet>
#include <QGraphicsScene>

#include "NameManager.h"
#include "GroupItem.h"
#include "DesignerScene.h"
#include "BaseData.h"
#include "ItemFactory.h"
#include "ObjectInspector.h"

CNameManager* UnqNameMng()
{
    static CNameManager _mng;
    return &_mng;
}
static const int OFF_SET = Hmi::_START+1;
static const int ITEM_CNT = Hmi::_END-OFF_SET;


CNameManager::CNameManager()
    :Mdi("nameManager"), m_baseNameVec(CNameManager::ConstructVec()),
      m_nameModel(new CObjectModel)
{
}


CNameManager::~CNameManager()
{
    delete m_nameModel;
}

QVector<QString> CNameManager::ConstructVec()
{
    QVector<QString> vec(ITEM_CNT);
    QMapIterator<int, QString> it(ItemFactory::TypeNameMap);
    while(it.hasNext())
    {
        it.next();
        QString name = it.value();
        if(name.startsWith("qt"))
            name=name.mid(2);
        else if(name.startsWith("ui-"))
            name=name.mid(3);

        vec[it.key()-OFF_SET] = name;
    }
    return vec;
}



QString CNameManager::ItemGetName(QGraphicsItem* item)
{
    SceneVerify();
    int type=g_dataPtr(item)->Type();
    QString baseName;
    Q_ASSERT(type>Hmi::_START && type < Hmi::_END);
    if (Hmi::Icon == type)
        baseName = ((CIconData*)g_dataPtr(item))->GetTemplateName().remove(0, 5);
    else
    {
        int index = type - OFF_SET;
        baseName = m_baseNameVec[index];
    }
    UnifyName(baseName, item);

    return baseName;
}

void CNameManager::Clear()
{
}

void CNameManager::OnSwitchScene()
{
    QList<QGraphicsItem*>& modelList = m_nameModel->ItemsList();
    modelList.clear();
    if(CurrentScene())
    {
        QList<QGraphicsItem*> itemList = CurrentScene()->items();
        foreach(QGraphicsItem* item, itemList)
        {
            if(item->parentItem())        continue;
            CBaseData* p=g_dataPtr(item);
            if(p && p->GetPlane()==CurrentScene()->GetCurPlane())
                modelList<<item;
        }
    }

    emit SIGUpdateModel();
}

void CNameManager::ItemRename( QGraphicsItem* item )
{
    CBaseData* pdata = g_dataPtr(item);
    Q_ASSERT(pdata);
    QString s = pdata->GetName();
    if(UnifyName(s, item ))
        pdata->SetName(s);

    emit SIGUpdateModel();
}

bool CNameManager::UnifyName(QString& name, QGraphicsItem* selfItem)
{
    typedef QSet<QString> StringSet;
    StringSet existingNames;
    typedef QList<QGraphicsItem*> QItemList;
    if(!CurrentScene()) return false;
    QItemList itemList = CurrentScene()->items();
    QItemList& modelList = m_nameModel->ItemsList();
    modelList.clear();

    modelList<<selfItem;
    foreach(QGraphicsItem* item, itemList)
    {

        if( item == selfItem)
            continue;
        CBaseData* p = g_dataPtr(item);
        if (p == NULL)
            continue;
        existingNames<<p->GetName();
        if(p->GetPlane()==CurrentScene()->GetCurPlane())
            modelList<<item;
    }

    const StringSet::const_iterator enEnd = existingNames.constEnd();
    if (existingNames.constFind(name) == enEnd)
        return false;


    qlonglong num = 0;
    qlonglong factor = 1;
    int idx = name.length()-1;
    static const ushort zeroUnicode = QLatin1Char('0').unicode();
    for(; idx>0 && name.at(idx).isDigit(); --idx)
    {
        num += (name.at(idx).unicode() - zeroUnicode) * factor;
        factor *= 10;
    }

    static const QChar underscore = QLatin1Char('_');
    if (idx>=0 && name.at(idx)==underscore)
    {
        ++idx;
    }
    else
    {
        num = 0;
        name += underscore;
        idx = name.length();
    }

    for (++num; ;++num)
    {
        name.truncate(idx);
        name += QString::number(num);
        if (existingNames.constFind(name) == enEnd)
            break;
    }

    return true;
}
