

#ifndef CommunicatePluginMng_H
#define CommunicatePluginMng_H 

//#include "Global.h"
#include "IHmiAppInterface.h"

class CGraphApp;

class CommunicatePluginMng
{
public:
    CommunicatePluginMng(IHmiAppInterface* parient = 0);
    virtual ~CommunicatePluginMng( );
    void SetParent(IHmiAppInterface* parient){ m_App = parient; };
    bool LoadPlugins();
    QStringList Name();
    int GetData(const QString& fileName);
    int GetData(const QString& tagName,DataNode & values);
    int GetData(const QStringList& tags,QList<DataNode> &values);
    int SetData(const QString& tagName,const DataNode & values);
    ICommunicateInterface* Plugin(const QString& name);
    int LoadChannel(const QString& fileName);
    int SaveChannel(const QString& fileName,const QVariant& channel_info);
    void Release();

private:
    QHash<QString,ICommunicateInterface*> m_PlugIns;
    IHmiAppInterface* m_App;
};

CommunicatePluginMng* UnqCommPluginMng();
#endif
