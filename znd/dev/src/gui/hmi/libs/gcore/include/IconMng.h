

#ifndef CSYMBOL_H
#define CSYMBOL_H 

#include "Export.h"
#include "ItemFactory.h"
#include <QFile>
#include "GroupItem.h"
#include <QPainterPath>

class CIconItem;
class QGraphicsScene;

class DLL_CLASS CIconMng : public QObject
{
    Q_OBJECT
public:
    CIconMng(QObject *parent = 0);
    ~CIconMng();
public:
    bool Init();
    int AddIcon(CIconItem* symbol, const QString& IconName = "");
    int AddIcon(const QString& fileNames);
    int DelIcon(const QString& symbolName);
    const CIconItem* Icon(const QString& symbolName);
    CIconItem* DupIcon(const QString& symbolName, QGraphicsScene *scene=NULL);
    bool IsVaildIconName(const QString& name);
    bool Init(const QStringList& IconNames);
	void InsertIconType(int type, QString typeName, int pinNum, int stateNum, QString planeInfo, QString isPinPlane);
    QMap<int, QStringList> GetIconType(){ return m_IconTypeMap; };
    void InsertIconName(QString groupName, QString typeName);
	int GetIconType(int type, QString& typeName, int& pinNum, int& stateNum, QString& planeInfo, QString& isPinPlane);
    QString GetRegIconName(QString tpName);
    int InitPathMap();
    QPainterPath GetPath(const QString& name);
	int IconRename(QString symbolName, QString newName);

public slots:
    QVariantMap getPathIconNames();
    QVariantMap GetIconGroups();


private:
    QMap<QString,CIconItem*> m_IconMap;
    QMap<int,QStringList> m_IconTypeMap;
    QMap<QString,QPainterPath> m_icnPathMap;
    QMap<QString, QStringList> m_IconGroupMap;
};

DLL_CLASS CIconMng * UnqIconMng();

#endif
