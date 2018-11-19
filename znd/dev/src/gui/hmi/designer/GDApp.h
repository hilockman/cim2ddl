

#ifndef _GDAPP_H
#define _GDAPP_H 

#include "Global.h"
#include "GApp.h"
#include "IHmiAppInterface.h"
#include "GFunc.h"

class CGraphWnd;
class CDesignerWnd;
class CommunicatePluginMng;


class CGDApp : public CGApp
{
    Q_OBJECT
public:
    CGDApp(int & argc, char ** argv);
    virtual ~CGDApp();
public slots:
    virtual void NewGraphWindow(GDispInfo & graph_disp_info);
    virtual void ChangeLanguage(const QString& language,bool update=false);
public:
    CDesignerWnd* m_pActiveDesignerWnd;
};


#endif
