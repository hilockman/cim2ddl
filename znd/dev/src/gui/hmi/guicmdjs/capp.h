#ifndef CAPP_H
#define CAPP_H

#include <QCoreApplication>
#include "IHmiAppInterface.h"
#include "CQScriptWrap.h"
#include "eproc.h"
#include "sysrun.h"


class CGTimer : public QTimer
{
    Q_OBJECT
    Q_PROPERTY(int timerId READ timerId  )
public:
    CGTimer(QObject * parent = 0) : QTimer(parent) {}
    ~CGTimer(){}

};

#ifdef CMDJS_GUI
class CApp : public QApplication,public IHmiAppInterface
#else
class CApp : public QCoreApplication,public IHmiAppInterface
#endif
{
    Q_OBJECT
public:
    CApp(int & argc, char ** argv);
    virtual ~CApp();

public:
    virtual QString GetRegName(){ return "comjs"; };
    virtual int PutData(const QString& tagName, const DataNode& val){return 0;};
    virtual int PutData(const QString& jsonStr){return 0;};
    virtual int ProcessChangeData( ){ return 0;};
    virtual int QSRegisterObj(QObject* object, QString alias_name = QString());
    virtual QObject* QApp(){ return this; };
	bool m_exit;
public slots:
    void LoadScript(QString fn);
    virtual QObject* GetScriptEngine(){return (QObject*)m_pScriptEngine;};
    QString CurrentFile(){return "";};
    void AddQSObject();
    bool LoadPlugins();
    int FileConvert(const QString& filename,const QString& outfilename );
    void Exit();
    QVariant  GetArgs(){return m_ArgsMap;};
    void SetProperty(QString name,QVariant value){setProperty(name.toLocal8Bit().data(),value);};
    QVariant Property(QString name){return property(name.toLocal8Bit().data());};
    QObject* Create(QString objname,const QVariant& args="");
private:
    void CheckArg(int & argc, char ** argv);
	int Lupdate(QString file);
	int LupdateBat(QString dir);
    QMap<QString,QObject*> m_QsObject;
    QHash<QString,ICommunicateInterface*> m_PlugIns;
    CScriptEngine * m_pScriptEngine;
    QVariantMap m_ArgsMap;
};

#endif // CAPP_H
