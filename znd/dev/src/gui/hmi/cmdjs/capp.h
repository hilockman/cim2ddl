#ifndef CAPP_H
#define CAPP_H

#include <QtCore>
#include <QtScript>
#include <QCoreApplication>
#include "IHmiAppInterface.h"
#include "eproc.h"
#include "sysrun.h"

#define  gDebug     log_debug
#define  gInfo      log_info
#define  gWarn      log_warn
#define  gError     log_error
#define  gSensor    log_sensor

class CGTimer : public QTimer
{
    Q_OBJECT
    Q_PROPERTY(int timerId READ timerId  )
public:
    CGTimer(QObject * parent = 0) : QTimer(parent) {}
    ~CGTimer(){}

};


class CScriptDebugger:public QScriptEngineAgent
{
public:
    CScriptDebugger( QScriptEngine *engine):QScriptEngineAgent(engine){};
    ~CScriptDebugger(){};
    void exceptionThrow(qint64 scriptId,const QScriptValue &exception,bool hasHandler);
    void exceptionCatch(qint64 scriptId,const QScriptValue &exception);
    void errorMessage(const QString &text);
};

///
/// \brief The CScriptEngine class
///
class  CScriptEngine :public QScriptEngine
{

public:
    CScriptEngine(QObject * parent = 0 );
    virtual ~CScriptEngine();
public:
    void EnableDebug(bool enable);
    int AddObject(QObject* object,QString alias_name=QString());
    QVariant Call( const QString & function, const QVariantList & args =QVariantList() ,QObject * context = 0 );
    QVariant Evaluate(const QString & code, const QString & errfileName=QString(), int startlineNumber=1);
    QVariant LoadFile(QString fileName);
    int Clear();


};


class CApp : public QCoreApplication,public IHmiAppInterface
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

    void QSleep(int msec);
    void LoadScript(QString fn);
    virtual QObject* GetScriptEngine(){return (QObject*)m_pScriptEngine;};
    QString CurrentFile(){return "";};
    void AddQSObject();
    bool LoadPlugins();

    void Exit();
    QVariant  GetArgs(){return m_ArgsMap;};
    void SetProperty(QString name,QVariant value){setProperty(name.toLocal8Bit().data(),value);};
    QVariant Property(QString name){return property(name.toLocal8Bit().data());};
    QObject* Create(QString objname,const QVariant& args="");

    QString LoadFile(const QString &name );
    int SaveFile(const QString &name,const QString& buf );
    QString LoadBinaryFile(QString filePath);
    int SaveBinaryFile(QString filePath, QString fileStr);

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
