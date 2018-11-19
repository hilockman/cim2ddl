#include "Global.h"
#include "GFunc.h"
#include "ConstString.h"
#include "GDApp.h"
#include "GWnd.h"
#include "DesignerWnd.h"
#include "DesignerView.h"
#include "GraphScene.h"
#include "CQScriptWrap.h"

#include "CommunicatePluginMng.h"
#include "CManhattanStyle.h"

#ifdef GSVG
#include "qsvgtinydocument_p.h"
#endif

#ifndef WIN32
#include <unistd.h>
#else
#include <windows.h>
#endif


CGDApp::CGDApp(int & argc, char ** argv) :CGApp ( argc, argv )
{
    QString baseName = qApp->style()->objectName();
	m_pActiveDesignerWnd=NULL;
   // qApp->setStyle( new ManhattanStyle( baseName ) );

    UnqFunc()->LoadIconInfo();
    setApplicationName( tr("gd") );
}

CGDApp::~CGDApp()
{

}

void CGDApp::NewGraphWindow(GDispInfo & graph_disp_info)
{
#ifdef GSVG
    if (!graph_disp_info.import_path_name.isEmpty())
	{
		if (graph_disp_info.import_path_name.right(4) == PICSUFFIX)
		{
			//file
			QString inFile = graph_disp_info.import_path_name;
			QString outFile = "";
			UnqFunc()->GetGraphNameByGraphPathName(inFile, outFile);
			UnqFunc()->GetGraphPathNameByGraphName(outFile, outFile);
			QSvgTinyDocument::toSmartsys(inFile, outFile);
		}
		else 
		{
			//dir
			QSvgTinyDocument::toSmartsysBat(graph_disp_info.import_path_name);
		}
		return;
	}
#endif

	m_pActiveDesignerWnd = new CDesignerWnd(m_pCurMaxGraphID, graph_disp_info);
    QString graph_path_name;
    graph_path_name = graph_disp_info.graph_path_name;
	m_pActiveDesignerWnd->showMaximized();
	if (graph_path_name.isEmpty())
		m_pActiveDesignerWnd->OnFileNew();
	else
	{
		m_pActiveDesignerWnd->OnFileOpen(graph_path_name);
	}
}

void CGDApp::ChangeLanguage(const QString& language,bool update)
{
    CGApp::ChangeLanguage( language, update);
    if(update)
        m_pActiveDesignerWnd->retranslateUi();

}
