
#ifndef IHmiAppInterface_H
#define IHmiAppInterface_H 

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtCore/QVariant>
class DataNode
{
public:
 QVariant value;
 int status;
};

class IHmiAppInterface
{
public:
 virtual QString GetRegName()=0;
 virtual int PutData(const QString& tagName,const DataNode& val )=0;
 virtual int PutData(const QString& jsonStr) = 0;
        virtual int ProcessChangeData()=0;
 virtual int QSRegisterObj(QObject* object,QString alias_name=QString())=0;

};

//动态加载的插件接口
class ICommunicateInterface
{

public:
 virtual bool Create(IHmiAppInterface *hmi_app) = 0;
 virtual void Release()= 0;
 virtual QString Name()= 0;
};

#define CommunicateInterface_iid "org.powerhmi.CommunicateInterface"
Q_DECLARE_INTERFACE(ICommunicateInterface, CommunicateInterface_iid)


#endif
