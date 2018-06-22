#include <Windows.h>
#include <io.h>
#include <vector>
using namespace std;
#include <crtdbg.h>
#include <float.h>
#include <process.h>

#include "../../../../../MemDB/BpaMemDB/BpaMemDB.h"
#if (!defined(WIN64))
#	pragma comment(lib, "../../../../../lib/BpaMemDB.lib")
#	pragma message("Link LibX86 BpaMemDB.lib")
#else
#	pragma comment(lib, "../../../../../lib_x64/BpaMemDB.lib")
#	pragma message("Link LibX64 BpaMemDB.lib")
#endif
using	namespace	BpaMemDB;

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
const	char*	g_lpszLogFile="GCBpa2PR.log";
extern	void	ClearLog(const char* lpszLogFile);
extern	void	Log(const char* lpszLogFile, char* pformat, ...);

tagBpaBlock*		g_pBpaBlock;
tagPRBlock*			g_pPRBlock;
CPRMemDBInterface	g_PRMemDBInterface;
CBpaPRParam			g_BpaPRParam;

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
	char	szRunDir[260], szBpaDatFile[260], szBpaSwiFile[260], szBpaRParamFile[260];
	clock_t	dBeg, dEnd;
	int		nDur;

	GetCurrentDirectory(260, szRunDir);
	ClearLog(g_lpszLogFile);

	int	nEle=1;
	if (argc > nEle)	strcpy(szRunDir, argv[nEle++]);				else	{	Log(g_lpszLogFile, "Error Arg RunDir\n");			return 0;	}
	if (argc > nEle)	strcpy(szBpaDatFile, argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg BpaDatFile\n");		return 0;	}
	if (argc > nEle)	strcpy(szBpaSwiFile, argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg BpaSwiFile\n");		return 0;	}
	if (argc > nEle)	strcpy(szBpaRParamFile, argv[nEle++]);		else	{	Log(g_lpszLogFile, "Error Arg BpaRParamFile\n");	return 0;	}

	for (nEle=0; nEle<argc; nEle++)
		Log(g_lpszLogFile, "Argc[%d] = %s\n", nEle+1, argv[nEle]);

	dBeg=clock();

	{
		g_pBpaBlock=(tagBpaBlock*)Init_BpaBlock();
		if (!g_pBpaBlock)
		{
			PrintMessage("获取Bpa内存库错误");
			return FALSE;
		}

		g_pPRBlock=(tagPRBlock*)g_PRMemDBInterface.Init_PRBlock();
		if (!g_pPRBlock)
		{
			PrintMessage("获取PR内存库错误");
			return FALSE;
		}
	}

	{
		BpaMemDB2PRMemDB(g_pBpaBlock, g_pPRBlock, szBpaDatFile, szBpaSwiFile, 1);	//	读全网数据
		g_BpaPRParam.ReadBpaPRParam(szBpaRParamFile, g_pPRBlock);
	}

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	PrintMessage("由BPA生成可靠性计算数据库和装载可靠性参数完成，耗时 %d 毫秒", nDur);
}
