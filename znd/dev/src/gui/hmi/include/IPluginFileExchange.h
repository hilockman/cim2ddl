


#ifndef IPluginFileExchange_H
#define IPluginFileExchange_H 



class PluginFileExchangeInterface
{
public:
 virtual ~PluginFileExchangeInterface() {};

 virtual QList<QGraphicsItem*> Load(const QString& fileName)=0;
 virtual void Release() = 0;

};


Q_DECLARE_INTERFACE(PluginFileExchangeInterface,
                    "caih.PluginFileExchangeInterface/1.0")


#endif
