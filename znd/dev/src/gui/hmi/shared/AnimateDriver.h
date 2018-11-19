

#ifndef CAnimateDriver_H
#define CAnimateDriver_H 

#include "Global.h"

#pragma once


class CAnimation;
class CGraphScene;
class CBaseData;
class CLinkLineItem;

struct COLOR_CONFIG
{
    float value;
    QString line_color;
	QString fill_color;
	QString line_on_color;
	QString fill_on_color;
	QString line_dn_color;
	QString fill_dn_color;
    int fill_mode;
    short icon_plane;
    short if_twinking;
    short freq;
    short priority;
    QString text;
    int if_show;
    QString pix_name;
    float contrast;
    float gray;
    QString description;
    int run_flg;
    QString jarg;
    COLOR_CONFIG()
    {
        value=-9999;
        line_color="";
        fill_color="";
        line_on_color="";
        fill_on_color="";
        line_dn_color="";
        fill_dn_color="";
        fill_mode=-1;
        icon_plane=-1;
        if_twinking=false;
        freq=-1;
        priority=0;
        text="";
        if_show=true;
        pix_name="";
        run_flg=-999;
		contrast=-1;
		gray=-1;
        jarg="";
    }
};

class Property
{
public:
    Property()
    {
        color_cfg=QString::null;
        flag=0;
        pix1=0;
        pix2=0;
        val1=0;
        val2=1;
    }
    QString color_cfg;
    char flag;
    int pix1;
    int pix2;
    float val1;
    float val2;
};

class CTag
{
public:
    CTag():type("rdb"),status(0){};
    virtual ~CTag(){};
    QString type;
    QString tag_name;
    QString id_info;
    QVariant val;
    int status;
	inline QString ChannelName() { return tag_name; }
	inline void SetChannelName(const QString& name) { tag_name = name; }

    inline int SetValue(const QVariant& val);
    inline QVariant Value();
    int DoUpdate();
};

class CAnimation
{
public:
    enum AnimationType { COLOR_CFG,VISIBLE,ENABLE,H_MOVE, V_MOVE,H_FILL_PERCENT,V_FILL_PERCENT,H_SCALE,V_SCALE,H_MOVE_OP,V_MOVE_OP,TEXT_OUT,L_MOUSE_CLICK,L_MOUSE_DBCLICK,ROTATE,ROTATE_OP,FRAME_CHG,RUN_PATH};
    enum AdvanceType { NO_ADVANCE,TWINKLING,RUNING};
    CAnimation(CBaseData* parent=NULL,short PropType=-1);
    CAnimation(const CAnimation& anim);
    CAnimation &operator=(const CAnimation&);
    virtual ~CAnimation(void);
public:
    Property* GetProp(){ return &m_Prop; };
    void SetItem(QGraphicsItem* item);
    int SetValue(const QString& tagName, const QVariant& val );
    QJsonObject ToJsonObj();
    void FromJsonObj(QJsonObject& jsonObj);
    char AdvanceType(){ return m_AdvanceType; };
    void SetAdvanceType(char type){ m_AdvanceType = type; };
public:
    bool Changed(){return false;};
    void SetType(int type){m_PropType=type;}
    int type() { return m_PropType;}
    void GetPropertyList(QList< QPair<QString,QVariant> >& property_list);
    bool SetProperty(const QString& propname,const QVariant& value);
    bool AnimationFlag(){return m_AnimateByValue;};
    void SetAnimationFlag(bool flag){ m_AnimateByValue= flag;};
    QVector<CTag>& GetTag(){return m_TagInfo;};
    QString GetTagInfo();
    void SetTag(QVector<CTag> & tag);
    QString GetColorCfg(){return m_Prop.color_cfg;};
    QString GetScript(){return m_Script;};
    void SetScript(const QString& code){ m_Script=code;};
    static QString GetAnimDesc(int anim_type);
    CBaseData* GetBaseData(){ return m_pData; };
    static QVector<CAnimation > ParseJsonStr(const QString& jsonStr,CBaseData* parent=0);
    static QString GetTagInfo( QGraphicsItem* itemobj);

public:
    short m_PropType;
    QVector<CTag> m_TagInfo;
    QString m_Script;
    Property m_Prop;
    CBaseData* m_pData;
    bool m_Changed;
    int m_LoopCount;
    int m_Duration;
    bool m_AnimateByValue;
    char m_AdvanceType;
    short m_AdvanceStatus;
    int m_Status;

};


class CAnimateDriver :public QObject
{
    Q_OBJECT
enum BaseColorType {
    QColor,
    VolColor,
    DrawColor
    };

enum PlusColorType {
    NullPlus,
    DevStatus,
    LifeCycle
    };
public:
    CAnimateDriver(CGraphScene* scene);
    virtual ~CAnimateDriver(void);

public slots:
    QStringList GetTags();
    int Render(const QVariantMap& chg_data_map);
    int RenderLinkLineColor(const QList<CLinkLineItem* >& llist, int &loop);
    int Advance( int phase);
    void Operate(QGraphicsItem * item, QGraphicsSceneMouseEvent * e);
    void StartAnimation();
    void Reset();
    void InitDriver(const QString& fileName , QString app="", QString replaceTag="");
    static int LoadColorCfg(QString fileName="");
    static int SaveColorCfg(QString fileName="");
    static QMap<QString,QMap<float,COLOR_CONFIG> >* GetColorConfig(){return &m_ColorCfgMap;};
    int GetColorCfg(const QString& cfgName,float value,int status,COLOR_CONFIG& cfg);
	QList<CBaseData*> FindItem(const QString& tagName);
	QVariantMap FindItemByDev(const QString& devName);
    void SetReplaceInfo(const QString& replaceStr);
    QString GetReplaceInfo(){return m_ReplaceInfo;};
    QStringList GetNeedTransTag();
    void SetTransModel(const QVariantMap& tmodel);
    void EnableTopoColor(bool enable){m_EnableTopoColor=enable; if(enable) UpdateRender();};
    void EnableDoColor(bool enable) ;
    bool UpdateRender();
    void SetBaseColor(int type) ;
    void SetPlusColor(int type) ;
private:
    int Advance(CAnimation* pAobj, int phase);
    int Render(CAnimation* pAobj);
    QVariant CalValue(CAnimation* pAobj);
    QVariant RunScript(CAnimation* pAobj);
    int DoColor(CAnimation* pAobj, QVariant& val);
    bool m_EnableDoColor;
    bool m_EnableTopoColor;
    QVector<CAnimation> FormatTag(CBaseData* pdata,QString currentApp="",QString replaceTag="");
private:

    QVector<CAnimation> m_Animations;
    QMultiHash<QString, CAnimation*> m_AnimateMultiHash;
    QMultiHash<QString, CBaseData*> m_QColorItemsMHash; //need power qcolor items
    static QMap<QString,QMap<float,COLOR_CONFIG> > m_ColorCfgMap;
    CGraphScene* m_pScene;
    short m_AdvanceStatus;
    QString m_ReplaceInfo;
    QMap<QString,CBaseData*> m_NeedTrans;

    static QMap<QString,QMap<int,QString>> m_TransModel;
    QString m_app;
    int m_BaseColor;
    int m_PlusColor;
};


#endif
