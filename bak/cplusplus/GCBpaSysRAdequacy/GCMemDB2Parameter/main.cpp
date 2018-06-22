#include <process.h>
#include <io.h>
#include <vector>
using namespace std;
#include <crtdbg.h>
#include <float.h>

#include "../../../../../MemDB/PRMemDB/PRMemDB.h"
#if (!defined(WIN64))
#	pragma comment(lib, "../../../../../lib/PRMemDB.lib")
#else
#	pragma comment(lib, "../../../../../lib_x64/PRMemDB.lib")
#endif
using	namespace	PRMemDB;

#include "../../PRAdequacyBase/PRAdequacyBase.h"
using	namespace	PRAdequacyBase;
#if (!defined(WIN64))
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib/libPRAdequacyBaseMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib/libPRAdequacyBaseMD.lib")
#	endif
#	pragma message("Link LibX86 PRAdequacyBase.lib")
#else
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib_x64/libPRAdequacyBaseMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib_x64/libPRAdequacyBaseMD.lib")
#	endif
#	pragma message("Link LibX64 PRAdequacyBase.lib")
#endif

#include "../../../../../Common/TinyXML/tinyxml.h"
//using	namespace	TinyXML;
#if (!defined(WIN64))
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib/libTinyXmlMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib/libTinyXmlMD.lib")
#	endif
#	pragma message("Link LibX86 TinyXml.lib")
#else
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib_x64/libTinyXmlMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib_x64/libTinyXmlMD.lib")
#	endif
#	pragma message("Link LibX64 TinyXml.lib")
#endif


#ifndef	_MAIN_
#	define _MAIN_
#endif
#undef	_MAIN_

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 唯一的应用程序对象
const	char*	g_lpszLogFile="GCMemDB2Parameter.log";
extern	void	ClearLog(const char* lpszLogFile);
extern	void	Log(const char* lpszLogFile, char* pformat, ...);

tagPRBlock*			g_pPRBlock;
CPRMemDBInterface	g_PRMemDBInterface;
CBpaPRParam			m_PRParam;

void PrintMessage(const char* pformat, ...)
{
	va_list args;
	va_start( args, pformat );

	char	szMesg[1024];

	vsprintf(szMesg, pformat, args);
	vfprintf(stdout, pformat, args);
	fprintf(stdout, "\n");

	Log(g_lpszLogFile, szMesg);

	va_end(args);
}

int main(int argc, char** argv, char** envp)
{
	char	szRunDir[260], szParameterFile[260];
	clock_t	dBeg, dEnd;
	int		nDur;

	ClearLog(g_lpszLogFile);
	GetCurrentDirectory(260, szRunDir);
	memset(szParameterFile, 0, 260);

	int	nEle=1;
	if (argc > nEle)	strcpy(szRunDir, argv[nEle++]);				else	{	Log(g_lpszLogFile, "Error Arg RunDir\n");			return 0;	}
	if (argc > nEle)	strcpy(szParameterFile, argv[nEle++]);		else	{	Log(g_lpszLogFile, "Error Arg ParameterFile\n");	return 0;	}

	for (nEle=0; nEle<argc; nEle++)
		Log(g_lpszLogFile, "Argc[%d] = %s\n", nEle+1, argv[nEle]);

	ClearLog(g_lpszLogFile);
	dBeg=clock();

	{
		g_pPRBlock=(tagPRBlock*)g_PRMemDBInterface.Init_PRBlock();
		if (!g_pPRBlock)
		{
			PrintMessage("获取PR内存库错误\n");
			return FALSE;
		}
	}

	m_PRParam.SaveBpaPRParam(szParameterFile, g_pPRBlock);

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	PrintMessage("读取可靠性参数文件完成，耗时 %d 毫秒", nDur);
}
