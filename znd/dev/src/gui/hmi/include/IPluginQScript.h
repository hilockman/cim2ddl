


#ifndef IPluginQScript_H
#define IPluginQScript_H 



class PluginQScriptInterface
{
public:
 virtual ~PluginQScriptInterface() {};




 virtual bool Create(QObject** pluginObj,std::vector<void*> ptr_vect,QObject *parent=0) = 0;
 virtual void Release() = 0;

};


Q_DECLARE_INTERFACE(PluginQScriptInterface,
                    "caih.PluginQScriptInterface/1.0")


#endif
