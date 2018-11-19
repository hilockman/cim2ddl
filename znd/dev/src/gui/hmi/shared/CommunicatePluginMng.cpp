


#include "CommunicatePluginMng.h"
#include "GraphSvgRW.h"
#include "GFunc.h"

CommunicatePluginMng* UnqCommPluginMng()
{
    static CommunicatePluginMng _mng;
    return &_mng;
}

CommunicatePluginMng::CommunicatePluginMng(IHmiAppInterface* parient)
{
    m_App=parient;
}


CommunicatePluginMng::~CommunicatePluginMng()
{

}

void CommunicatePluginMng::Release()
{
    foreach (ICommunicateInterface* plugin, m_PlugIns)
    {
        plugin->Release();
    }
}

bool CommunicatePluginMng::LoadPlugins()
{
    QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_DLL);

    QDir pluginsDir(path);
    pluginsDir.cd("plugins");

    QStringList filters;
    filters << "*.dll" << "*.so" ;
    foreach (QString fileName, pluginsDir.entryList(filters))
    {
        QPluginLoader* loader=new QPluginLoader(pluginsDir.absoluteFilePath(fileName) );
        QObject *plugin = loader->instance();
        if (plugin) {
            ICommunicateInterface* appPlugIn = qobject_cast<ICommunicateInterface *>(plugin);
            if (appPlugIn)
            {
                bool ret=appPlugIn->Create( m_App);
                if(ret )
                {
                    QString name=appPlugIn->Name();
                    name=name.section(".",0,0);
                    m_PlugIns[name]=appPlugIn;
                }

            }
		}
		else
		{
			if (fileName.right(4) == ".dll" || fileName.right(3) == ".so")
                gError("-------load plugin error: %s -------- ", loader->errorString().toStdString().c_str());
		}
	}
    return true;

}
QStringList CommunicatePluginMng::Name()
{
    QStringList tmp;
    return tmp;
}

int CommunicatePluginMng::GetData(const QString& fileName)
{
    foreach (ICommunicateInterface* plugin, m_PlugIns)
    {

    }
    return -1;
}
int CommunicatePluginMng::GetData(const QString& tagName,DataNode & values)
{
    QString pluginName=tagName.section(".",0,0);
    if (Plugin(pluginName))
    {

    }
    return -1;
}
int CommunicatePluginMng::GetData(const QStringList& tags,QList<DataNode> &values)
{
    if (tags.size()==0)
    {
        return -1;
    }
    QString pluginName=tags[0].section(".",0,0);
    if (Plugin(pluginName))
    {

    }
    return -1;
}
int CommunicatePluginMng::SetData(const QString& tagName,const DataNode & values)
{
    QString pluginName=tagName.section(".",0,0);
    if (Plugin(pluginName))
    {

    }
    return -1;
}
ICommunicateInterface* CommunicatePluginMng::Plugin(const QString& name)
{
    QString tmp_str=name.section(".",0,0);
    if (m_PlugIns.contains(tmp_str))
        return m_PlugIns.value(tmp_str);
    return NULL;
}

int CommunicatePluginMng::LoadChannel(const QString& fileName)
{
    return 0;

}
int CommunicatePluginMng::SaveChannel(const QString& fileName,const QVariant& channel_info)
{
    return 0;
}
