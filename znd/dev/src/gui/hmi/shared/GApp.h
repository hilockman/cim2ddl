

#ifndef _GAPP_H
#define _GAPP_H 

#include "Global.h"
#include "IHmiAppInterface.h"
#include "GFunc.h"


typedef QVariantMap CHG_DATA_MAP;

struct GDispInfo
{
    int wnd_type;
    int wnd_style;
    QString app_style;
    QString graph_path_name;
    bool is_print;
    bool is_poke_invoke;
    int app_id;
    bool is_find;
    float zoom_factor;
    QPoint start_pos;
    QString args;
    bool new_wnd;
    QString lang;
	QString import_path_name;
    QString wnd;

    GDispInfo()
    {
        graph_path_name = QString::null;
        wnd_type = -1;
        wnd_style = -1;
        app_style = QString::null;
        is_print = false;
        app_id = -1;
        is_find = false;
        is_poke_invoke = false;
        zoom_factor = -1;
        start_pos = QPoint(0,0);
        args = QString::null;
        new_wnd = true;
        lang ="";
		import_path_name = "";
    }
};


class CGApp : public QApplication,public IHmiAppInterface
{
    Q_OBJECT
public:
    CGApp(int & argc, char ** argv);
    virtual ~CGApp();

public:
    virtual QString GetRegName(){ return UnqFunc()->GetRegName(); };
    virtual int PutData(const QString& tagName, const DataNode& val);
    //publish topic.rds  '[{"tag":"tag1.rdb","v":"0","s":"0"}]'
    virtual int PutData(const QString& jsonStr) ;
    virtual int ProcessChangeData( ){ return 0;};
    virtual int QSRegisterObj(QObject* object, QString alias_name = QString());
    virtual QObject* QApp(){ return this; };
public:
    virtual void RunApp( QString register_name);
    virtual void NewGraphWindow(GDispInfo & disp_info){Q_UNUSED(disp_info)};
    void CheckArg(int & argc, char ** argv);
    void CheckDispArg(int & argc, const QStringList &argv, GDispInfo & user_login_info);
    long GetActiveGraphID(void);
    QString GetGraphPathName(void){return m_GraphPathName;};
    QString GetRegisterName() {return m_RegisterName;};
    float GetInitScaleX() {return m_InitScaleX;};
    float GetInitScaleY() {return m_InitScaleY;};

    void AddChgData(const QString& tagName,const QVariant& val);
    void AddChgData(const CHG_DATA_MAP& valmap);
    CHG_DATA_MAP& GetChgDataMap();
    int ResetChgDataMap();

public slots:
    QVariant  GetArgs()  {return m_ArgsMap ;};
    void OnValueChanged(const QString& tag, const QVariant& value);
    void OnDownIcon(bool need_clear=false);
    QStringList StyleFactory(){return QStyleFactory::keys();};
    void SetStyle(const QString & style);
    void SetProperty(QString name,QVariant value){setProperty(name.toLocal8Bit().data(),value);};
    QVariant Property(QString name){return property(name.toLocal8Bit().data());};
    void Emit(const QString& signal,const QVariant& value){emit CustomEvent(signal,value);};
    void SetData(const QString& jsonStr,bool reflash=false);
    virtual void ChangeLanguage(const QString& language,bool update=false);
    bool LoadPlugins(const QString& pluginName);
protected:
    virtual void timerEvent ( QTimerEvent* e );

public:

    int IsNeedBroadCast() {return m_NeedBroadcast; };
    int GetData(const QStringList& tags,QList<DataNode>& values);
    void EmitSignal(QString signal,QString arg);
    QMap<QString,QObject*> GetQSObject(){return m_QsObject;};
signals:
    void CustomEvent(QString signal, QVariant value);
    void SigFileOpen(QString fileName);
    void SigFileClose(QString fileName);
public:
    GDispInfo m_graph_disp_info;
    QString m_RegisterName;
    long m_pCurMaxGraphID;
    QString m_GraphPathName;
    int m_TimeID;
    int m_TimerCount;
    QRect m_InitWndRect;
    float m_InitScaleX;
    float m_InitScaleY;
    int m_nHaveRepository;
    int m_NeedBroadcast;
    bool m_ForceRequery;
    QMap<QString,QObject*> m_QsObject;
    CHG_DATA_MAP m_DataPool;
    QVariantMap m_ArgsMap;

};




#endif
