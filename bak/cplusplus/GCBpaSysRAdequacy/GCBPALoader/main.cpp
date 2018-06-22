#include <Windows.h>
#include <process.h>
#include <io.h>
#include <vector>
using namespace std;
#include <crtdbg.h>
#include <float.h>

#include "../../../../../MemDB/BpaMemDB/BpaMemDB.h"
#if (!defined(WIN64))
#	pragma comment(lib, "../../../../../lib/BpaMemDB.lib")
#	pragma message("Link LibX86 BpaMemDB.lib")
#else
#	pragma comment(lib, "../../../../../lib_x64/BpaMemDB.lib")
#	pragma message("Link LibX64 BpaMemDB.lib")
#endif
using namespace BpaMemDB;

#ifndef	_MAIN_
#	define _MAIN_
#endif
#undef	_MAIN_

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 唯一的应用程序对象
extern	void	ClearLog(const char* lpszLogFile);
extern	void	Log(const char* lpszLogFile, char* pformat, ...);

tagBpaBlock*	g_pBpaBlock;

static	const	char*	g_lpszLogFile = "GCBPALoader.log";

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
	char	szRunDir[260], szBpaDatFile[260], szBpaSwiFile[260];
	clock_t	dBeg, dEnd;
	int		nDur;

	ClearLog(g_lpszLogFile);
	GetCurrentDirectory(260, szRunDir);

	int	nEle=1;
	if (argc > nEle)	strcpy(szRunDir, argv[nEle++]);				else	{	Log(g_lpszLogFile, "Error Arg RunDir\n");			return 0;	}
	if (argc > nEle)	strcpy(szBpaDatFile, argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg BpaDatFile\n");		return 0;	}
	if (argc > nEle)	strcpy(szBpaSwiFile, argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg BpaSwiFile\n");		return 0;	}

	for (nEle=0; nEle<argc; nEle++)
		Log(g_lpszLogFile, "Argc[%d] = %s\n", nEle+1, argv[nEle]);

	dBeg=clock();

	g_pBpaBlock=(tagBpaBlock*)Init_BpaBlock();
	if (!g_pBpaBlock)
	{
		PrintMessage("获取Bpa内存库错误");
		return FALSE;
	}

	BpaFiles2MemDB(g_pBpaBlock, szBpaDatFile, szBpaSwiFile, 0);

	char	drive[260], dir[260], fname[260], ext[260];
	char	szFileName[260];
	_splitpath(szBpaDatFile, drive, dir, fname, ext);
	_makepath(szFileName, drive, dir, fname, ".pfo");
	if (_access(szFileName, 0) == 0)
		BpaParsePfoFile(g_pBpaBlock, szFileName);

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	PrintMessage("BPA文件加载完成，耗时 %d 毫秒", nDur);
}
