

#ifndef NAMEMANAGER_H
#define NAMEMANAGER_H 

#include <QObject>
#include <QVector>
#include "Mdi.h"

class QGraphicsScene;
class CObjectModel;
class QGraphicsItem;

class CNameManager : public QObject, Mdi
{
    Q_OBJECT

public:
    friend CNameManager* UnqNameMng();
    ~CNameManager();

    virtual void OnSwitchScene();
    QString ItemGetName(QGraphicsItem* item);
    void ItemRename(QGraphicsItem* item);
    void UpdateModel() {OnSwitchScene();};
    CObjectModel* GetNameModel() const {return m_nameModel;};
signals:
    void SIGUpdateModel();

private:
    bool UnifyName(QString& name, QGraphicsItem* item);
    CNameManager();
    void Clear();
    QRegExp GetDefaultReg(int type);
    QRegExp ConstructAllReg();
    static QVector<QString> ConstructVec();

public:
    const QVector<QString> m_baseNameVec;
    CObjectModel* m_nameModel;
};

CNameManager* UnqNameMng();


#endif
