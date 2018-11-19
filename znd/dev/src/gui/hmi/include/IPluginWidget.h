#ifndef PLUGINWIDGETIF_H
#define PLUGINWIDGETIF_H 


class IPluginWidget
{
public:
    virtual void Release() = 0;
    virtual void SetObjJsonString(const QString& jsonString)=0;
    virtual QString GetObjJsonString()=0;
    virtual QString GetObjName()= 0;
    virtual void GetPropertyList(QList< QPair<QString,QVariant> > &property_list)=0;
    virtual bool SetProperty(const QString& propname,const QVariant &value)=0;
};

class PluginWidgetFactoryInterface
{
public:
    virtual ~PluginWidgetFactoryInterface() {}
    virtual bool CreateWidget(QWidget *parent,QWidget** pwidget,IPluginWidget** piwidget,std::vector<void*> ptr_vect,bool if_edit_mode=false) = 0;
    virtual void Release() = 0;

};

#define PluginWidgetFactoryInterface_iid "org.powerhmi.PluginWidgetFactoryInterface"
Q_DECLARE_INTERFACE(PluginWidgetFactoryInterface, PluginWidgetFactoryInterface_iid)



#endif
