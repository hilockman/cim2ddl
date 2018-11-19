

#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H 

#include <QtCore/QObject>
#include "ActionEnum_p.h"
#include "Mdi.h"
#include "GWnd.h"

class QAction;
class QToolBar;
class QGraphicsItem;
class QActionGroup;
class QKeySequence;
class QMenu;
class ActionManagerPrivate;


class CActionManager : public QObject, Mdi
{
    Q_OBJECT

    friend CActionManager* UnqActMng();
public:
    ~CActionManager();

    void InitToolBar(QToolBar* bar, ActionGroupOrder order);
    void InitFileMenu(QMenu* fileMenu);
    void InitWndMenu(QMenu* wndMenu);
    void InitPlaneMenu(QMenu* planeMenu);

    void CreateContextMenu(QMenu& menu);
    QAction* GetAction(ACTION_ORDER id);
    virtual void OnSwitchScene();
    void retranslateUi();

public slots:
    void OnSceneSelectionChanged();

private slots:
    void OnActionTriggered(QAction* action);

private:
    CActionManager();
    void SetUpAction();
    QAction* CreateAction(QActionGroup* actionGroup, QString description, const char* iconName = "", const char* shortCut = "");
    QAction* CreateAction(QActionGroup* actionGroup, QString description, const char* iconName, const QKeySequence& shortCut);
    void FindItem(const QString& name, bool forward);

    QActionGroup* m_actionGroupArray[TOOLBAR_ORDERNUM];

    ActionManagerPrivate* m_p;

};

CActionManager* UnqActMng();

#endif
