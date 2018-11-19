

#ifndef CGExplorerScene_H
#define CGExplorerScene_H 

#if _MSC_VER > 1000

#endif

#include "Global.h"
#include "GraphView.h"
#include "GraphScene.h"

class CAnimateDriver;

class CGExplorerScene :public CGraphScene
{
    Q_OBJECT
public:
    CGExplorerScene(QObject *parent);
    virtual ~CGExplorerScene();
public:
    void Reset();
	int FileOpen(const QString& fileName, QString replace_info = "" , QString currentApp = "");
    CAnimateDriver* GetAnimateDriver(){ return m_Driver; };
	bool ChangeApp(QString currentApp = "");

public slots:
	void SetCurApp(QString currentApp){ m_app = currentApp; }

public:
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
private:
	QString m_app;
    CAnimateDriver* m_Driver;
    int Advance(long time_ms=0);
};

#endif
