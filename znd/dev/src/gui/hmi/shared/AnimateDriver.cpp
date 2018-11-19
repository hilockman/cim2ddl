

#include "AnimateDriver.h"
#include "GraphItem.h"
#include "GroupItem.h"
#include "WidgetItem.h"
#ifdef CHARTS
#include "GChartItem.h"
#endif
#include "GraphScene.h"
#include "CQScriptWrap.h"
#include "GFunc.h"

const QString STATUS_TAG="status";
const QString VALUE_TAG="value";

#define NORMAL_POWER -1

#define LIFECYCLE "recordset"
///自定义属性加上C_前缀，以免与外部脚本中重名///////
#define C_LIFECYCLE "C_recordset"
#define C_QCOLOR "C_qcolor"
#define C_VTID "C_vt_id"
#define C_VALUE "C_value"
#define C_COLOR "C_color"

int CTag::SetValue(const QVariant& val)
{
    //do nothing
    QString tag = ChannelName();
    return 0;
}



QVariant CTag::Value()
{
    return val;
}

int CTag::DoUpdate()
{
    return 0;
}

CAnimation::CAnimation(CBaseData* parent, short PropType)
{
    m_AnimateByValue = true;
    m_LoopCount = -1;
	m_Duration = 2000;
    m_pData = parent;
    m_PropType = PropType;
    m_Changed = false;
    m_AdvanceType = NO_ADVANCE;
    m_AdvanceStatus = 0;
    m_Status=-1;
    m_TagInfo.clear();
}
CAnimation::CAnimation(const CAnimation& anim)
{
    m_TagInfo.clear();
    m_AnimateByValue = anim.m_AnimateByValue;
    m_LoopCount = anim.m_LoopCount;
    m_Duration = anim.m_Duration;
    m_PropType = anim.m_PropType;
    m_TagInfo = anim.m_TagInfo;
    m_Script = anim.m_Script;
    m_Prop = anim.m_Prop;
    m_AdvanceType = anim.m_AdvanceType;
	m_AdvanceStatus=anim.m_AdvanceStatus;
	m_Status = anim.m_Status;
    m_pData = anim.m_pData;
	m_Changed=anim.m_Changed;
}

CAnimation &CAnimation::operator=(const CAnimation& anim)
{
    if (this != &anim)
    {
        m_TagInfo.clear();
        m_AnimateByValue = anim.m_AnimateByValue;
        m_LoopCount = anim.m_LoopCount;
        m_Duration = anim.m_Duration;
        m_PropType = anim.m_PropType;
        m_TagInfo = anim.m_TagInfo;
        m_Script = anim.m_Script;
        m_Prop = anim.m_Prop;
        m_AdvanceType = anim.m_AdvanceType;
		m_AdvanceStatus=anim.m_AdvanceStatus;
        m_Status=anim.m_Status;
        m_pData = anim.m_pData;
		m_Changed=anim.m_Changed;
    }
    return *this;
}

CAnimation::~CAnimation(void)
{

}

QString CAnimation::GetAnimDesc(int anim_type)
{
    QString desc = "";
    switch (anim_type)
    {
    case CAnimation::COLOR_CFG: return QObject::tr("animSetting");
    case CAnimation::VISIBLE: return QObject::tr("show/hide");
    case CAnimation::ENABLE: return QObject::tr("enable");
    case CAnimation::H_MOVE: return QObject::tr("h_move");
    case CAnimation::V_MOVE: return QObject::tr("v_move");
    case CAnimation::H_FILL_PERCENT: return QObject::tr("h_fill");
    case CAnimation::V_FILL_PERCENT: return QObject::tr("v_fill");
    case CAnimation::H_SCALE: return QObject::tr("h_scale");
    case CAnimation::V_SCALE: return QObject::tr("v_scale");
    case CAnimation::H_MOVE_OP: return QObject::tr("h_drag");
    case CAnimation::V_MOVE_OP: return QObject::tr("v_drag");
    case CAnimation::TEXT_OUT: return QObject::tr("textOut");
    case CAnimation::L_MOUSE_CLICK: return QObject::tr("lMouseClick");
    case CAnimation::L_MOUSE_DBCLICK: return QObject::tr("lMouseDBClick");
    case CAnimation::ROTATE: return QObject::tr("rotate");
    case CAnimation::ROTATE_OP: return QObject::tr("rotateCtl");
    case CAnimation::FRAME_CHG: return QObject::tr("frame");
    case CAnimation::RUN_PATH: return QObject::tr("runpath");
    default:
        break;
    }
    return "";
}

void CAnimation::SetItem(QGraphicsItem* item)
{
    m_pData = g_dataPtr(item);
}

void CAnimation::GetPropertyList(QList< QPair<QString, QVariant> >& property_list)
{
    if (m_PropType == VISIBLE)
    {
        QMap<QString, QVariant> tmpMap;
        tmpMap[QObject::tr("show")] = 0;
        tmpMap[QObject::tr("hide")] = 1;
        tmpMap["__CurrentValue"] = (int)m_Prop.flag;
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("expressTrue"), QVariant(tmpMap)));
        return;
    }
    if (m_PropType == ROTATE_OP || m_PropType == RUN_PATH)
    {
        QMap<QString, QVariant> tmpMap;
        tmpMap[QObject::tr("clockwise")] = 0;
        tmpMap[QObject::tr("Anti-clockwise")] = 1;
        tmpMap["__CurrentValue"] = (int)m_Prop.val1;
		property_list.push_back(QPair<QString, QVariant>(QObject::tr("value1"), QVariant((double)m_Prop.val1)));
		property_list.push_back(QPair<QString, QVariant>(QObject::tr("value2"), QVariant((double)m_Prop.val2)));
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("duration"), QVariant(m_Duration)));
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("loopCount"), QVariant(m_LoopCount)));
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("rotateDir"), QVariant(tmpMap)));
    }
    else
    {
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("pos1"), QVariant((int)m_Prop.pix1)));
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("pos2"), QVariant((int)m_Prop.pix2)));
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("value1"), QVariant((double)m_Prop.val1)));
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("value2"), QVariant((double)m_Prop.val2)));
    }
    if (m_PropType == ROTATE || m_PropType == ROTATE_OP)
    {
        property_list.push_back(QPair<QString, QVariant>(QObject::tr("rotateCenter"), QVariant((int)m_Prop.flag)));
    }

}

bool CAnimation::SetProperty(const QString& propname, const QVariant& value)
{
    if (propname == QObject::tr("colorCfg"))
    {
        m_Prop.color_cfg = value.toString();
    }
    else if (propname == QObject::tr("pos1"))
    {
        m_Prop.pix1 = value.toInt();
    }
    else if (propname == QObject::tr("pos2"))
    {
        m_Prop.pix2 = value.toInt();
    }
    else if (propname == QObject::tr("value1"))
    {
        m_Prop.val1 = value.toInt();
    }
    else if (propname == QObject::tr("value2"))
    {
        m_Prop.val2 = value.toInt();
    }
    else if (propname == QObject::tr("animateByValue"))
    {
        m_AnimateByValue = value.toBool();
    }
    else if (propname == QObject::tr("duration"))
    {
        m_Duration = value.toInt();
    }
    else if (propname == QObject::tr("loopCount"))
    {
        m_LoopCount = value.toInt();
    }
    else if (propname == QObject::tr("rotateCenter"))
    {
        m_Prop.flag = value.toInt();
    }
    else if (propname == QObject::tr("rotateDir"))
    {
        m_Prop.val1 = value.toInt();
    }
    else if (propname == QObject::tr("expressTrue"))
    {
        m_Prop.flag = value.toInt();
    }

    return true;
}

int CAnimation::SetValue(const QString& tagName, const QVariant& val)
{
    if (m_TagInfo.isEmpty())
    {
        return -1;
    }
    bool ifChanged = false;
    int status=-1;
    bool find=false;

    ///
    int pos=tagName.lastIndexOf(".");
    QString columntag=tagName.right(tagName.length()-pos-1);
    if(columntag==LIFECYCLE|| columntag=="vt_id" || columntag=="qcolor" )
    {
        columntag="C_"+columntag; /////加前缀//////
        int ivalue=-1;
        QStringList vslist = val.toStringList();
        if (vslist.size() >0 )
        {
            ivalue=vslist[0].toInt();
            QVariant tmp=m_pData->property(columntag.toLocal8Bit().data());
            if(!tmp.isValid() ||(tmp.isValid()&& tmp.toInt()!=ivalue))
            {
                m_pData->setProperty(columntag.toLocal8Bit().data(),ivalue);
                ifChanged = true;
            }
        }
        return ifChanged;
    }
    ///
    QVector<CTag>::iterator it = m_TagInfo.begin();
    for (it; it != m_TagInfo.end(); ++it)
    {
        if (it->ChannelName() == tagName)
        {
            find=true;
            QStringList vslist = val.toStringList();
            QString value;
            if(vslist.size() == 1)
            {
                value = vslist[0];
            }
            if (vslist.size() == 2)
            {
                value = vslist[0];
                status = vslist[1].toInt();                
            }

            if (it->val != value)
            {
                it->val = value;
                ifChanged = true;
            }
            if (status>=0 && it->status != status)
            {
                it->status = status;
                m_Status = status;   //the status of tag.value
                ifChanged = true;
            }
            break;
        }
    }
    if(!find)
    {
        QString tag=tagName.right(7);
        if ( (tag=="_"+STATUS_TAG) ||  (tag=="."+STATUS_TAG) )
        {
            QStringList vslist = val.toStringList();
            if(vslist.size() >= 1)
            {
                int status = vslist[0].toInt();
                if (status>=0 && m_Status != status)
                {
                    m_Status = status;
                    ifChanged = true;
                }
            }
        }
    }
    return ifChanged;
}


QJsonObject CAnimation::ToJsonObj()
{
    QJsonObject jsonObj;
    QStringList tags;
    for (int i = 0; i < m_TagInfo.size(); i++)
    {
        tags.append(m_TagInfo[i].ChannelName());
    }
    QString arrStr=QString("%1,%2,%3,%4,%5,%6").arg(m_Prop.pix1).arg(m_Prop.pix2).arg(m_Prop.val1).arg(m_Prop.val2).arg(m_Duration).arg(m_LoopCount);

    jsonObj["attrType"]=m_PropType;
    jsonObj["byValue"]=int(m_AnimateByValue);
    if(m_PropType>COLOR_CFG)
    {
        jsonObj["attr"]=arrStr;
        jsonObj["flag"]=m_Prop.flag;
    }
    if(!m_Script.isEmpty())
        jsonObj["script"]=m_Script;
    jsonObj["colorcfg"]=m_Prop.color_cfg;    
    jsonObj["tags"]=tags.join(",");
    return jsonObj;
}

void CAnimation::FromJsonObj(QJsonObject& jsonObj)
{
    QString arrStr;
    m_PropType=jsonObj["attrType"].toInt();
    m_AnimateByValue=jsonObj["byValue"].toInt();
    arrStr=jsonObj["attr"].toString();
    QStringList alist=arrStr.split(",");
    if(alist.size()>=6)
    {
        m_Prop.pix1=alist[0].toInt();
        m_Prop.pix2=alist[1].toInt();
        m_Prop.val1=alist[2].toDouble();
        m_Prop.val2=alist[3].toDouble();
        m_Duration=alist[4].toInt();
        m_LoopCount=alist[5].toInt();
    }
    m_Script=jsonObj["script"].toString();
    m_Prop.color_cfg=jsonObj["colorcfg"].toString();
    m_Prop.flag=jsonObj["flag"].toInt();
    QString tags=jsonObj["tags"].toString();
    QStringList taglist= tags.split(",",QString::SkipEmptyParts);
    for (int i = 0; i < taglist.size(); i++)
    {
        CTag tag;
        tag.SetChannelName(taglist[i]);
        m_TagInfo.push_back(tag);
    }
	if ((m_PropType == CAnimation::ROTATE || m_PropType == CAnimation::ROTATE_OP) && m_pData)
    {
        QRectF rc = m_pData->Item()->boundingRect();
        QPointF pos;
        if (m_Prop.flag == 0)
        {
            pos = rc.center();
        }
        else if (m_Prop.flag == 1)
        {
            pos = rc.topLeft();
        }
        else if (m_Prop.flag == 2)
        {
            pos = rc.topRight();
        }
        else if (m_Prop.flag == 3)
        {
            pos = rc.bottomRight();
        }
        else if (m_Prop.flag == 4)
        {
            pos = rc.bottomLeft();
        }
        m_pData->Item()->setTransformOriginPoint(pos);
    }
}

void CAnimation::SetTag(QVector<CTag> & tag)
{
    m_TagInfo.clear();
    m_TagInfo = tag;
}

QString CAnimation::GetTagInfo()
{
    QString tagInfo="";
    QStringList taglist;
    for(int j=0;j<m_TagInfo.size();j++)
    {
        taglist<<m_TagInfo[j].ChannelName();
    }
    tagInfo=taglist.join(",");
    return tagInfo;
}

QString CAnimation::GetTagInfo( QGraphicsItem* itemobj)
{
    QString tagInfo="";
    CBaseData* pdata=const_cast<CBaseData*>(g_dataPtr(itemobj));
    if(pdata )
    {
        tagInfo=pdata->GetUserData();
        QStringList taglist;
        QVector<CAnimation > anims = CAnimation::ParseJsonStr(tagInfo,pdata);
        for(int i=0;i<anims.size();i++)
        {
            QVector<CTag>& tags=anims[i].GetTag();
            for(int j=0;j<tags.size();j++)
            {
                taglist<<tags[j].ChannelName();
            }
        }
        tagInfo=taglist.join(",");
    }
    return tagInfo;
}

QVector<CAnimation > CAnimation::ParseJsonStr(const QString& jsonStr,CBaseData* parent)
{
    QVector<CAnimation > anims;
    anims.clear();
    if(jsonStr.isEmpty())
        return anims;

    QString str=jsonStr;
    str.replace('!','"');

    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8(), &error);
    if (error.error == QJsonParseError::NoError) {
        if (!(jsonDoc.isNull() || jsonDoc.isEmpty())) {
            if (jsonDoc.isObject())
            {
                QJsonObject jobj = jsonDoc.object();
                CAnimation anim(parent);
                anim.FromJsonObj(jobj);
                anims.append(anim);
            }
            else if (jsonDoc.isArray())
            {
                QJsonArray jsonArrays = jsonDoc.array();                
                foreach(QJsonValue jsonv, jsonArrays)
                {
					CAnimation anim(parent);
                    QJsonObject jobj = jsonv.toObject();
                    anim.FromJsonObj(jobj);
                    anims.append(anim);
                }
            }
        }
    }
    else {

    }
    return anims;
}



QMap<QString,QMap<float,COLOR_CONFIG> > CAnimateDriver::m_ColorCfgMap;



CAnimateDriver::CAnimateDriver(CGraphScene* scene):QObject(0)
{
    setObjectName("Driver");
    m_BaseColor= QColor; ///基础着色///
    m_PlusColor= DevStatus;///叠加着色///
    m_app="";
    m_pScene = scene;
    m_AdvanceStatus = 0;
    m_EnableDoColor=true;
    m_EnableTopoColor=true; //diable topo color
    int size1=m_ColorCfgMap.size();
    if(size1 == 0)
        LoadColorCfg();
}
CAnimateDriver::~CAnimateDriver(void)
{
    Reset();
}

void CAnimateDriver::Reset()
{
    m_Animations.clear();
    m_AnimateMultiHash.clear();
    m_QColorItemsMHash.clear();
    m_NeedTrans.clear();
	m_app = "";
    m_AdvanceStatus = 0;
    m_EnableDoColor=true;
    m_EnableTopoColor=true; //diable topo color
}

void CAnimateDriver::SetReplaceInfo(const QString& replaceStr)
{
    m_ReplaceInfo=replaceStr;

}

bool isDev(const QString & tagName)
{
    QStringList tagls=tagName.split(".");  //if(tagls[2].startsWith("pnt_"))
    if (tagls.size() == 5)
    {
        QString key=tagls[3];
        if(key.startsWith("1021") && key.length() ==14)
            return true;
    }
    return false;
}

void CAnimateDriver::InitDriver(const QString& fileName ,QString app,QString replaceTag )
{
    if(m_pScene->views().size()>0)
        setParent(m_pScene->views().first());

    Reset();
    foreach(QGraphicsItem *item, m_pScene->items())
    {
        CBaseData* pdata = g_dataPtr(item);
        if (pdata)
        {            
            QVector<CAnimation> anims=FormatTag(pdata,app,replaceTag);// replace app or keytag
            if(anims.size()<1)
                continue;
            m_Animations +=anims;	
        }
    }
	if (!app.isEmpty() && m_app != app)
	{
		m_app = app;
	}
    QVector<CAnimation>::iterator it = m_Animations.begin();
    QString tagName;
    for (it; it != m_Animations.end(); ++it)
    {
		CBaseData* pdata = it->GetBaseData();
		int type = pdata->Type();
        QVector<CTag> tagvect = it->GetTag();
        for (int i = 0; i<tagvect.size(); i++)
        {
            tagName=tagvect[i].ChannelName();
            m_AnimateMultiHash.insert(tagName, it);
            QString columnstr=tagName.right(6);
            if(columnstr=="_"+VALUE_TAG || columnstr=="."+VALUE_TAG)////  _value or  .value，关联值域的要追加获取status /////
            {
                m_AnimateMultiHash.insert(tagName.left(tagName.length()-5)+STATUS_TAG, it);
            }

            if(i==0)
            {
                if (type== Hmi::Text || type== Hmi::GraphicsText)
                {
                    int distype=((CTextData*)pdata)->GetDispType();
                    if(distype==CTextData::D_TRANS  )
                    {
                        QString tag=it->GetTagInfo();
                        m_NeedTrans[tag]=pdata;
                    }
                }
                else
                {
                    if(isDev(tagName)){ ////关联设备的还要追加 .recordset .vt_id .qcolor///////
                        QString tag = tagName.left(tagName.lastIndexOf("."));
                        m_AnimateMultiHash.insert(tag+"."+LIFECYCLE, it);//recordset
                        if(tagvect.size()==1)//temporary scheme, tersformer don't use vt_color
                            m_AnimateMultiHash.insert(tag+".vt_id", it);

                        //if(m_EnableTopoColor)
                            m_AnimateMultiHash.insert(tag+".qcolor", it);
                    }

                }
            }
        }
    }
}

QVector<CAnimation> CAnimateDriver::FormatTag(CBaseData* pdata,QString currentApp,QString replaceTag)
{
    QVector<CAnimation > anims;
    QString  orgStr=pdata->GetUserData();
    if(orgStr.isEmpty())
         return anims;
    bool appchged=false;
    if (!currentApp.isEmpty() && m_app != currentApp)
    {
        appchged=true;
    }
    
    bool changed=false;
    QStringList rtaglist = replaceTag.split(".");
    if (orgStr != "")
    {
        orgStr.replace('!', '"');
        QJsonParseError error;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(orgStr.toUtf8(), &error);
        if (error.error == QJsonParseError::NoError) {
            if (!(jsonDoc.isNull() || jsonDoc.isEmpty())) {
                if (jsonDoc.isArray())
                {
                    QJsonArray jsonArrays = jsonDoc.array();
                    for (int i = 0; i < jsonArrays.size(); i++)
                    {
                        QJsonObject jobj = jsonArrays[i].toObject();
                        if(appchged || !replaceTag.isEmpty()) // need replace
                        {
                            QString tags = jobj["tags"].toString();
                            QStringList taglist = tags.split(",", QString::SkipEmptyParts);
                            for (int j = 0; j < taglist.size(); j++)
                            {
                                QStringList tlst = taglist[j].split(".");
                                if (tlst.length()>4)
                                {
                                    if (!replaceTag.isEmpty() && rtaglist.length() >= tlst.length())
                                    {
                                        for (int k = 0; k < tlst.size(); k++)
                                        {
                                            if (tlst[k].contains("*") )
                                            {
                                                tlst[k].replace("*",rtaglist[k]);
                                                changed=true;
                                            }
                                        }
                                    }
                                    if (appchged )//&& tlst[1].compare("public",Qt::CaseInsensitive)!=0)
                                    {// replace app
                                        tlst[1]=currentApp;
                                        changed=true;
                                    }
                                    taglist[j]=tlst.join(".");
                                }
                            }
                            jobj["tags"] = taglist.join(",");
                            jsonArrays[i] = jobj;
                        }
                        CAnimation anim(pdata);
                        anim.FromJsonObj(jobj);
                        anims.append(anim);
                    }
                    if(changed )
                    {
                        orgStr = QString(QJsonDocument(jsonArrays).toJson().data());
                        pdata->SetUserData(orgStr);
                    }
                }
            }
        }       
    }    
    return anims;
}

QStringList CAnimateDriver::GetTags()
{
    return m_AnimateMultiHash.uniqueKeys();
}

QStringList CAnimateDriver::GetNeedTransTag()
{
    return m_NeedTrans.uniqueKeys();
}

void CAnimateDriver::SetTransModel(const QVariantMap& tmodel)
{
    QMap<QString,CBaseData*>::iterator it=m_NeedTrans.begin();
    for(it;it!=m_NeedTrans.end();++it)
    {

        QString dispName=tmodel[it.key()].toString();
        if (!dispName.isEmpty())
        {
            CTextData *pitem = (CTextData *)(it.value());
            if(pitem)
            {
                pitem->SetOrgText(dispName);
            }
        }
    }
}

QList<CBaseData*> CAnimateDriver::FindItem(const QString& tagName)
{
	QList<CBaseData*> dataLsit;
	QMultiHash<QString, CAnimation*>::iterator i = m_AnimateMultiHash.find(tagName);
	while (i != m_AnimateMultiHash.end() && i.key() == tagName)
	{
		dataLsit.append(i.value()->GetBaseData());
		++i;
	}
	return dataLsit;
}

QVariantMap CAnimateDriver::FindItemByDev(const QString& devName)
{
	QVariantMap dataMap;
	QVector<CAnimation>::iterator it = m_Animations.begin();
	
	for (it; it != m_Animations.end(); ++it)
	{
		QVector<CTag> tagvect = it->GetTag();
		for (int i = 0; i<tagvect.size(); ++i)
		{
			QString tagName = tagvect[i].ChannelName();
			if (tagName.contains(devName))
			{
				CBaseData* dataPtr = it->GetBaseData();
                dataMap.insert(dataPtr->GetName(), tagName);
			}
		}
	}
	return dataMap;
}


//vt_id
int CAnimateDriver::Render(const QVariantMap& chg_data_map)
{
    if (chg_data_map.size() == 0)
    {
        return 0;
    }
    if (m_AnimateMultiHash.size() == 0)
    {
        return 0;
    }

    QMultiHash<QString, CAnimation*>::iterator it = m_AnimateMultiHash.begin();
    QVariant val;

    QSet<CAnimation*> tmp_dv_set;
    QVariantMap::const_iterator chg_data_it = chg_data_map.begin();


    for (chg_data_it; chg_data_it != chg_data_map.end(); ++chg_data_it)
    {
        QString tagName = chg_data_it.key();
        val = chg_data_it.value();
        QMultiHash<QString, CAnimation*>::iterator i = m_AnimateMultiHash.find(tagName);
        while (i != m_AnimateMultiHash.end() && i.key() == tagName)
        {
            bool ifchged = false;
            CAnimation* pAnimate=i.value();
            ifchged = pAnimate->SetValue(tagName, val);
            if (ifchged) tmp_dv_set.insert(pAnimate);
            ++i;
        }
    }

	if (tmp_dv_set.size() == 0)
        return 0;

    for (QSet<CAnimation*>::iterator tmpit = tmp_dv_set.begin(); tmpit != tmp_dv_set.end(); ++tmpit)
    {
        Render(*tmpit);
    }

    QList<CLinkLineItem* > llist;
    foreach(QGraphicsItem *item, m_pScene->items())
    {
        if(item->type()==Hmi::Link)
        {
            if(g_dataPtr(item)->GetUserData().isEmpty())
                llist.append((CLinkLineItem*)item);
        }
    }

    if(m_EnableDoColor)///如果m_EnableDoColor=false,连接线放在外部脚本来着色////
    {
        int loop=2;
        RenderLinkLineColor(llist,loop);
    }
    return 1;
}

void CAnimateDriver::EnableDoColor(bool enable)
{
    bool chged=false;
    if(m_EnableDoColor!=enable) chged=true;

    m_EnableDoColor=enable;
    if(enable && chged) UpdateRender();
}

void CAnimateDriver::SetBaseColor(int type)
{
    bool chged=false;
    if(m_BaseColor!=type) chged=true;

    m_BaseColor=type;
    if( chged) UpdateRender();
}

void CAnimateDriver::SetPlusColor(int type)
{
    bool chged=false;
    if(m_PlusColor!=type) chged=true;

    m_PlusColor=type;
    if( chged) UpdateRender();
}

bool CAnimateDriver::UpdateRender()
{
    QVector<CAnimation>::iterator it = m_Animations.begin();
    for (it; it != m_Animations.end(); ++it)
    {
        Render(it);
    }
    QList<CLinkLineItem* > llist;
    foreach(QGraphicsItem *item, m_pScene->items())
    {
        if(item->type()==Hmi::Link)
        {
            if(g_dataPtr(item)->GetUserData().isEmpty())
                llist.append((CLinkLineItem*)item);
        }
    }

    if(m_EnableDoColor)///如果m_EnableDoColor=false,连接线放在外部脚本来着色////
    {
        int loop=2;
        RenderLinkLineColor(llist,loop);
    }
    return true;
}

// for linkitem qcolor
int CAnimateDriver::RenderLinkLineColor(const QList<CLinkLineItem* >& llist,int& loop)
{
    if(llist.size()==0|| loop==0)
        return 0;

    QList<CLinkLineItem* > sublist;
    foreach(CLinkLineItem *item, llist)
    {
        int qcolor1=-1,qcolor2=-1;
        int vl_id1=-1,vl_id2=-1;
        // linkitem qcorlor depend on two terminal item
        QGraphicsItem* linkeditem1=((CLinkLineItem*)item )->GetPinLinkItem(0);//getlinkedObj((CLinkLineItem*)item,0);
        QGraphicsItem* linkeditem2=((CLinkLineItem*)item )->GetPinLinkItem(1);
		CBaseData* plinkdata = g_dataPtr(item);
		if (linkeditem1 == NULL && linkeditem2 == NULL)
		{	
			//for import graph
            QString linkStr = plinkdata->Property("link",false).toString();
			if (linkStr.isEmpty())
				continue;
			QStringList linkLst = linkStr.split(",");
			QList<QGraphicsItem*> liks;
			foreach (QString lik, linkLst)
			{
				QGraphicsItem* likItem = m_pScene->GetElementById(lik);
				if (likItem == NULL)
					continue;
				CBaseData* likData = g_dataPtr(likItem);
				if (likData && (likData->TypeName() == "link" || !likData->GetUserData().isEmpty()))
					liks.append(likItem);
			}
			if (liks.size() == 0)
				continue;
			linkeditem1 = liks[0];
			if (liks.size() > 1)
				linkeditem2 = liks[1];
			//end : for import graph 
		}


        QString lcolor="";
        CBaseData* pdata = g_dataPtr(linkeditem1);
        if (pdata)
        {
            QVariant qcolor=pdata->property(C_COLOR);
            if(qcolor.isValid()) lcolor=qcolor.toString();
        }

        pdata = g_dataPtr(linkeditem2);
        if (pdata)
        {
            QVariant qcolor=pdata->property(C_COLOR);
            if(qcolor.isValid()) lcolor=qcolor.toString();
        }


        if(linkeditem1 && linkeditem1->type()==Hmi::Pin)
        {
            if(!lcolor.isEmpty()) g_dataPtr(linkeditem1)->setProperty(C_COLOR,lcolor);

        }
        if(linkeditem2 && linkeditem2->type()==Hmi::Pin)
        {
            if(!lcolor.isEmpty()) g_dataPtr(linkeditem2)->setProperty(C_COLOR,lcolor);
        }



        if(!lcolor.isEmpty())
        {
            plinkdata->SetLineColor(lcolor);
            plinkdata->setProperty(C_COLOR,lcolor);
        }
        else
        {
            sublist.append(item);
            plinkdata->ResetColor(CBaseData::LINECOLOR);
        }
    };
    loop--;
    RenderLinkLineColor(sublist,loop );
    return 0;
}

int CAnimateDriver::Render(CAnimation* pAobj)
{
    CBaseData* pBData = pAobj->GetBaseData();

    if (pBData->Type() == Hmi::QtChart)
    {
#ifdef CHARTS
        QMap<QString, QVariant> tagval;
        QVector<CTag> vecTagInfo = pAobj->GetTag();
        for (int i = 0; i < vecTagInfo.size(); i++)
        {
            tagval.insert(vecTagInfo[i].tag_name, vecTagInfo[i].val);
        }
        CGChartItem* pChartItem = dynamic_cast<CGChartItem*>(pBData->Item());
        pChartItem->SetTagsValue( tagval);
#endif
    }
	else if (pBData->Type() == Hmi::ProgressBar)
	{
		QVariant curValue = CalValue(pAobj);
		CWidgetItem* pProxyWidget = dynamic_cast<CWidgetItem*>(pBData->Item());
		if (pProxyWidget)
		{
			CGProgressBar* pBarItem = dynamic_cast<CGProgressBar*>(pProxyWidget->widget());
			if (pBarItem)
				pBarItem->setValue(curValue.toReal());
		}
	}
	else if (pBData->Type() == Hmi::CustomWidget && pBData->Property("ocx").toString().right(4) == ".qml")
    {

        QMap<QString, QVariant> tagval;
        QVector<CTag> vecTagInfo = pAobj->GetTag();
        for (int i = 0; i < vecTagInfo.size(); i++)
        {
            tagval.insert(vecTagInfo[i].tag_name, vecTagInfo[i].val);
        }

        CWidgetItem* pProxyWidget = dynamic_cast<CWidgetItem*>(pBData->Item());
        //pProxyWidget->qmlview->Call("setValue", QVariant(tagval));

    }
    else{
        QVariant curValue = CalValue(pAobj);
        pBData->setProperty(C_VALUE,curValue); //store the value for script

        double curPix = 0;
        int propType = pAobj->type();
        bool valid = false;
        int itemType = 0;
        Property* prop = pAobj->GetProp();
        if (prop->val2 != prop->val1)
        {
            valid = true;
            curPix = (prop->pix2 - prop->pix1) / (prop->val2 - prop->val1) * (curValue.toDouble() - prop->val1) + prop->pix1;
        }

		itemType = pBData->Type();
        if (itemType == Hmi::Text || itemType == Hmi::GraphicsText)
        {
            ((CTextData *)pBData)->SetOrgText( curValue.toString() );
        }

       /* if (itemType == Hmi::Link)
        {
            CLinkLineItem *pitem = (CLinkLineItem *)(pBData->Item());
            pitem->SetRunningFlag( curValue );
        }*/
        switch (propType)
        {
        case CAnimation::COLOR_CFG:
        {
            DoColor(pAobj, curValue);
            break;
        }
        case CAnimation::VISIBLE:
        {
            if (curValue.toInt() != (int)prop->flag)
            {
                pBData->Item()->show();
            }
            else
                pBData->Item()->hide();
            break;
        }
        case CAnimation::H_MOVE:
        case CAnimation::H_MOVE_OP:
        {
            if (valid)
                pBData->Item()->setX(curPix);
            break;
        }
        case CAnimation::V_MOVE:
        case CAnimation::V_MOVE_OP:
        {
            if (valid)
                pBData->Item()->setY(curPix);
            break;
        }
            break;
        case CAnimation::H_FILL_PERCENT:
        {
            if (valid)
                pBData->SetFillPercent(curPix, 0);
            break;
        }
        case CAnimation::V_FILL_PERCENT:
        {
            if (valid)
                pBData->SetFillPercent(curPix, 1);
            break;
        }
        case CAnimation::TEXT_OUT:
        {

            break;
        }
        case CAnimation::ROTATE:
        {
            if (valid)
            {
                if( itemType == Hmi::Ellipse)
                {
                    CEllipseItem* eitem=(CEllipseItem*) pBData->Item();
                    int shape=eitem->ShapeType();
                    if(shape!=CEllipseItem::EllipseST)
                    {
                        eitem->setSpanAngle(curPix*16);
                        break;
                    }
                }
                pBData->SetTransformOrigin((int)prop->flag);
                pBData->SetRotation(curPix);
            }
            break;
        }
        case CAnimation::ROTATE_OP:
        case CAnimation::RUN_PATH:
        {
            QString animtype="rotate";
            if(propType==CAnimation::RUN_PATH)
                animtype="path";
            QPropertyAnimation* panim=pBData->GetAnimation(animtype);
			if (panim == NULL){
                panim=(QPropertyAnimation* )pBData->SetAnimation(animtype,0,360,pAobj->m_Duration,pAobj->m_LoopCount);
			}
			float dval = curValue.toDouble() - prop->val1;
			float k = 1;
			if (dval != 0) {
				k = abs((prop->val2 - prop->val1) /  dval);
				panim->setDuration(pAobj->m_Duration*k);
				panim->setDirection(dval>0 ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
				panim->start();
			}
			else
				panim->stop();
 

            break;
        }
        case CAnimation::H_SCALE:
        case CAnimation::V_SCALE:
        {
            if (valid)
            {
                pBData->Item()->setTransformOriginPoint(pBData->Item()->boundingRect().center());
                pBData->Item()->setScale(curPix);
            }
            break;
        }
        default:
            break;
        }

    }
    return 0;
}

QVariant CAnimateDriver::RunScript(CAnimation* pAobj)
{
    CBaseData* pBData = pAobj->GetBaseData();
    QVector<CTag> tagInfo = pAobj->GetTag();
    QString script = pAobj->GetScript();
    if (script.isEmpty()) return -1;
    QVariantList args;
    for (int i = 0; i < tagInfo.size(); i++)
    {
        args.append(tagInfo[i].val.toFloat());
    }
    return m_pScene->GetScriptEngine()->Call(script, args, pBData);
}
QVariant CAnimateDriver::CalValue(CAnimation* pAobj)
{
    QVector<CTag> tagInfo = pAobj->GetTag();
    QString script = pAobj->GetScript();
    QVariant ret;
    if (tagInfo.size() == 0)
    {
        return ret;
    }
    if (script.isEmpty())
    {
        ret = tagInfo[0].val;
    }
    else
    {

        ret = RunScript(pAobj);
    }
    return ret;
}

int CAnimateDriver::DoColor(CAnimation* pAobj, QVariant& val )
{
    CBaseData* pBData = pAobj->GetBaseData();    
	int itemType = pBData->Type();
    Property* prop = pAobj->GetProp();
    int status=-1;
    double curVal = val.toDouble();
    COLOR_CONFIG cfg,vlcfg;
    QVector<CTag> tagInfo=pAobj->GetTag();
    if(tagInfo.size()>0) status=pAobj->m_Status;

    QString lcolor="";
    QString fcolor="";
    int icon_showplane=-1;////图元显示平面////

    int vl_id=-1;
    //vlcolor
    if(m_BaseColor==VolColor  )
    {
        QVariant tmp=pBData->property(C_VTID);
        if(tmp.isValid()){
            vl_id=tmp.toInt();
            GetColorCfg("vl_color", vl_id, -1,vlcfg);
            lcolor=vlcfg.line_color;
            fcolor=vlcfg.fill_color;
        }
    }
    ///qcolor
    if(m_BaseColor==QColor)
    {
        QVariant qtmp=pBData->property(C_QCOLOR);
        int qcolor=-1;
        if(qtmp.isValid())
        {
            qcolor=qtmp.toInt();
        }
        if (qcolor>=0 && qcolor != NORMAL_POWER)
        {
            COLOR_CONFIG qcfg;
            int ret = GetColorCfg("qcolor", qcolor, 0,qcfg);
            if (ret >= 0)
            {
                lcolor= qcfg.line_color!=""?qcfg.line_color:lcolor;
                fcolor= qcfg.fill_color!=""?qcfg.fill_color:fcolor;
            }
        }
    }

    //status color
    if ( !prop->color_cfg.isEmpty() && prop->color_cfg != "<null>" && prop->color_cfg != "qcolor")
    {
        QString status_lc="";
        QString status_fc="";
        int ret = GetColorCfg(prop->color_cfg, (int)curVal, status,cfg);
		if (ret >= 0)
        {
            status_lc=cfg.line_color;
            status_fc=cfg.fill_color;

            if(m_PlusColor==DevStatus ){  /////叠加设备状态颜色//////////
                lcolor= cfg.line_color!=""?cfg.line_color:lcolor;
                fcolor= cfg.fill_color!=""?cfg.fill_color:fcolor;
            }

            icon_showplane=cfg.icon_plane;  ////图元显示平面////

            if(pAobj->AdvanceType() && cfg.if_twinking==false)
                pBData->Item()->setOpacity(1);

            pAobj->SetAdvanceType(cfg.if_twinking);

			/*if (fcolor != "" && pBData->GetFillStyle() == Qt::NoBrush)
                pBData->SetFillStyle(Qt::SolidPattern);*/

            if (!cfg.text.isEmpty() && (itemType == Hmi::Text || itemType == Hmi::GraphicsText))
            {
                ((CTextData *) pBData )->SetOrgText(cfg.text);
            }
            if(cfg.run_flg>-999)
            {
                QPropertyAnimation* runAnimation=pBData->GetAnimation("path");
                if(cfg.run_flg==0 && runAnimation)
                    runAnimation->stop();
				else{
					if(cfg.run_flg>0)
					{
						if(!runAnimation)
							pBData->SetAnimation("path");
						else{
							if (runAnimation->direction() == QAbstractAnimation::Backward){
								runAnimation->stop();
								runAnimation->setDirection(QAbstractAnimation::Forward);
								runAnimation->start();
							}
							else
								runAnimation->start();
						}
					}
					else
					{
						if (!runAnimation)
							pBData->SetAnimation("path",-1);
						else{
							if (runAnimation->direction() == QAbstractAnimation::Forward){
								runAnimation->stop();
								runAnimation->setDirection(QAbstractAnimation::Backward);
								runAnimation->start();
							}
							else
								runAnimation->start();
						}
					}
				}
            }///end of run_flg
            //if(!cfg.jarg.isEmpty())
        }
        pBData->setProperty("C_sta_lc",status_lc);
        pBData->setProperty("C_sta_fc",status_fc);

    }

    ////图元显示平面////
    if (itemType == Hmi::Icon && pAobj->AnimationFlag() == true)
    {
        float f = val.toFloat();
        if(icon_showplane<0)
            icon_showplane=(short)f;
        ((CIconData *)pBData)->SetState(icon_showplane);
    }

    ////图元着色,文字对象始终按ai_color来着色////
    if(itemType!=Hmi::Text && m_EnableDoColor==false) //diable do any color
        return 0;


    ////叠加投运状态颜色////////
    /// \brief tmplifecycle
    if(m_PlusColor==LifeCycle){
        QVariant tmplifecycle=pBData->property(C_LIFECYCLE);
        qint64 lifecycle=-1;
        if(tmplifecycle.isValid())
        {
            COLOR_CONFIG  cfg;
            lifecycle=tmplifecycle.toLongLong();
            int ret = GetColorCfg("lifecycle", lifecycle, -1, cfg);
            if(ret>=0){
                lcolor= cfg.line_color!=""?cfg.line_color:lcolor;
                fcolor= cfg.fill_color!=""?cfg.fill_color:fcolor;
                //icon_showplane=cfg.icon_plane;  ////图元显示平面////
            }
        }
    }
    //
    if(fcolor!="")
    {
        pBData->SetFillColor(fcolor);
    }
    else
    {
        pBData->ResetColor(CBaseData::FILLCOLOR);
    }

    if(lcolor!="")
    {
        pBData->SetLineColor(lcolor);
        pBData->setProperty(C_COLOR,lcolor);
    }
    else
    {
        pBData->ResetColor(CBaseData::LINECOLOR);
    }
    return -1;
}

void CAnimateDriver::Operate(QGraphicsItem * item, QGraphicsSceneMouseEvent * e)
{
    if (!item) return;
    CBaseData* pdata = g_dataPtr(item);
    if (!pdata)
        return;
    QVector<CAnimation> animations = CAnimation::ParseJsonStr(pdata->GetUserData(),pdata);
    QVector<CAnimation>::iterator it1 = animations.begin();
    for (it1; it1 != animations.end(); ++it1)
    {
        CAnimation* pAobj = it1;
        int eventType = e->type();
        CBaseData* pBData = pAobj->GetBaseData();
        int propType = pAobj->type();
        Property* prop = pAobj->GetProp();
        QVector<CTag> tagInfo = pAobj->GetTag();
        switch (eventType)
        {
        case QEvent::GraphicsSceneMousePress:
        {
            if (propType == CAnimation::L_MOUSE_CLICK)
            {
                RunScript(pAobj);
            }
            break;
        }
        case QEvent::GraphicsSceneMouseDoubleClick:
        {
            if (propType == CAnimation::L_MOUSE_DBCLICK)
            {
                RunScript(pAobj);
            }
            break;
        }
        case QEvent::GraphicsSceneMouseMove:
        {
            if (propType != CAnimation::H_MOVE_OP && propType != CAnimation::V_MOVE_OP)
            {
                return;
            }
            double curVal = 0, orgVal = 0;
            QPointF pos1 = e->scenePos();
            QPointF pos2 = e->buttonDownScenePos(Qt::LeftButton);
            if (propType == CAnimation::H_MOVE_OP)
            {
                e->setScenePos(QPointF(pos1.x(), 0));
                e->setButtonDownScenePos(Qt::LeftButton, QPointF(pos2.x(), 0));
                orgVal = pBData->m_OrgCenter.x();
                if ((pos1.x() - orgVal) > prop->pix2 || (pos1.x() - orgVal) < prop->pix1)
                {
                    return;
                }
                curVal = pos1.x();
            }
            else if (propType == CAnimation::V_MOVE_OP)
            {
                e->setScenePos(QPointF(0, pos1.y()));
                e->setButtonDownScenePos(Qt::LeftButton, QPointF(0, pos2.y()));
                orgVal = pBData->m_OrgCenter.y();
                if ((pos1.y() - orgVal) > prop->pix2 || (pos1.y() - orgVal)<prop->pix1)
                {
                    return;
                }
                curVal = pos1.y();
            }
            double val = (curVal - prop->pix1 - orgVal)*(prop->val2 - prop->val1) / (prop->pix2 - prop->pix1) + prop->val1;
            if (tagInfo.size()>0) tagInfo[0].SetValue(val);
        }
            break;
        default:
            break;

        }
    };
}

int CAnimateDriver::Advance( int phase)
{
    QVector<CAnimation>::iterator it= m_Animations.begin();
    for (it;it!=m_Animations.end();++it)
    {
        Advance( it, phase);
    }
    m_AdvanceStatus = !m_AdvanceStatus;
    return 0;
}

int CAnimateDriver::Advance(CAnimation* pAobj, int phase)
{
    char advanceType = pAobj->AdvanceType();
    CBaseData* pBData = pAobj->GetBaseData();
    Property* prop = pAobj->GetProp();

    int status=-1;
    QVector<CTag> tagInfo=pAobj->GetTag();
	if (tagInfo.size() > 0) status = pAobj->m_Status;//tagInfo[0].status;


    if (advanceType == CAnimation::TWINKLING)
    {
        QVariant curValue = CalValue(pAobj);
        double curVal = curValue.toDouble();
        COLOR_CONFIG cfg;
        int ret = GetColorCfg(prop->color_cfg, curVal,status, cfg);
        if (ret >= 0)
        {
            QString lcolor, fcolor;
            if (m_AdvanceStatus == 1)
            {
                pBData->Item()->setOpacity(1);
                lcolor = cfg.line_color;
                fcolor = cfg.fill_color;
            }
            else
            {
                lcolor = cfg.line_dn_color;
                fcolor = cfg.fill_dn_color;
                if (lcolor == "" && fcolor == "")
                {
                    pBData->Item()->setOpacity(0.3);
                }
            }

            if (fcolor != "") pBData->SetFillColor(fcolor);
            if (lcolor != "") pBData->SetLineColor(lcolor);
        }
    }
    return 0;
}

void CAnimateDriver::StartAnimation()
{
}

int CAnimateDriver::LoadColorCfg(QString fileName)
{

    fileName=UnqFunc()->GetDir(CGFunc::PATH_TYPE_ETC)+"/colorCfg.js" ;
    QString buf=UnqFunc()->LoadFile(fileName);
    QJsonObject jCfgObj=UnqFunc()->Str2Json(buf);
    for(QJsonObject::iterator it=jCfgObj.begin();it!=jCfgObj.end();++it)
    {
        QString itemName=it.key();
        QJsonArray jarray=it.value().toArray();
        QMap<float,COLOR_CONFIG> itemmap;
        COLOR_CONFIG color_config;
        for(int i=0;i<jarray.size();++i)
        {
            QJsonObject jval=jarray[i].toObject();
            color_config.value      = jval["value"].toDouble();
            color_config.line_color = jval["line_color"].toString();
            color_config.fill_color = jval["fill_color"].toString();
            color_config.line_on_color= jval["line_on_color"].toString();
            color_config.fill_on_color= jval["fill_on_color"].toString();
            color_config.line_dn_color= jval["line_dn_color"].toString();
            color_config.fill_dn_color= jval["fill_dn_color"].toString();
            color_config.fill_mode  = jval["fill_mode"].toInt();
            color_config.icon_plane = jval["icon_plane"].toInt();
            color_config.if_twinking= jval["if_twinking"].toInt();
            color_config.freq       = jval["freq"].toString().toInt();
            color_config.priority   = jval["priority"].toInt();
            color_config.text       = jval["text"].toString();
            color_config.if_show    = jval["if_show"].toInt();
            color_config.description= jval["description"].toString();
            color_config.run_flg    = jval["run_flg"].toInt();
            color_config.jarg       = jval["jarg"].toString();
            itemmap[color_config.value]=color_config;
        }
        m_ColorCfgMap[itemName]=itemmap;
    }

    return 0;
}

int CAnimateDriver::SaveColorCfg(QString fileName)
{
    QMap<QString,QMap<float,COLOR_CONFIG> >::iterator it=m_ColorCfgMap.begin();
    QJsonObject jCfgObj;
    for(it;it!=m_ColorCfgMap.end();++it)
    {
        QJsonArray jarray;
        QMap<float,COLOR_CONFIG>::iterator it1=it.value().begin();
        for(it1;it1!=it.value().end();++it1)
        {
            QJsonObject jobj;
            jobj["value"]       =it1.value().value;
            jobj["description"] =it1.value().description;
            jobj["line_color"]  =it1.value().line_color;
            jobj["fill_color"]  =it1.value().fill_color;
            jobj["line_dn_color"]=it1.value().line_dn_color;
            jobj["fill_dn_color"]=it1.value().fill_dn_color;
            jobj["fill_mode"]   =it1.value().fill_mode;
            jobj["icon_plane"]  =it1.value().icon_plane;
            jobj["if_twinking"] =it1.value().if_twinking;
            jobj["priority"]    =it1.value().priority;
            jobj["text"]        =it1.value().text;
            jobj["if_show"]     =it1.value().if_show;
            jobj["run_flg"]     =it1.value().run_flg;
            jobj["jarg"]        =it1.value().jarg;
            jarray.append(jobj);
        }
        jCfgObj[it.key()]=jarray;
    }
    QString buf=UnqFunc()->Json2Str(jCfgObj,QJsonDocument::JsonFormat::Indented);
    UnqFunc()->SaveFile(UnqFunc()->GetDir(CGFunc::PATH_TYPE_ETC)+"/colorCfg.js",buf);
    return 0;
}

int CAnimateDriver::GetColorCfg(const QString& cfgName,float value,int status,COLOR_CONFIG& cfg)
{
    ////处理特殊状态着色////
    if(cfgName=="di_color" || cfgName=="ai_color" ||cfgName=="dev_color")
    {
        uint bitArray = (uint)status;
        int idx = 0;
        int priority = -1000000;
        if (bitArray)
        {
            int find=-1;
            while (bitArray)
            {
                if (bitArray & 0x01)
                {
                    QMap<QString, QMap<float, COLOR_CONFIG> >::iterator it = m_ColorCfgMap.find(cfgName);
                    if (it != m_ColorCfgMap.end())
                    {
                        QMap<float, COLOR_CONFIG>::iterator it1 = it.value().find(idx);
                        if (it1 != it.value().end())
                        {
                            if (it1.value().priority > priority)
                            {
                                priority = it1.value().priority;
                                cfg = it1.value();
                                find=1;
                            }
                        }
                    }
                }
                bitArray >>= 1;
                idx++;
            }
            return find;
        }
        else
        {
            QMap<QString, QMap<float, COLOR_CONFIG> >::iterator it = m_ColorCfgMap.find(cfgName);
            if (it != m_ColorCfgMap.end())
            {
                QMap<float, COLOR_CONFIG>::iterator it1 = it.value().find(value);
                if (it1 != it.value().end())
                {
                    cfg = it1.value();
                    return 0;
                }
            }
        }
        return -1;
    }

    /////其他合成值着色/////
    QMap<QString,QMap<float,COLOR_CONFIG> >::iterator it= m_ColorCfgMap.find(cfgName);
    if (it!=m_ColorCfgMap.end())
    {
        QMap<float,COLOR_CONFIG>::iterator it1= it.value().find(value);
        if (it1!=it.value().end())
        {
            cfg=it1.value();
            return 0;
        }
    }
    return -1;
}
