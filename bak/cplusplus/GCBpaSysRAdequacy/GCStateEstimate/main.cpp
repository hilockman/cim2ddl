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

#include "../../../../DCNetwork/DCNetwork.h"
using	namespace	DCNetwork;
#if (!defined(WIN64))
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib/libDCNetworkMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib/libDCNetworkMD.lib")
#	endif
#	pragma message("Link LibX86 DCNetwork.lib")
#else
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib_x64/libDCNetworkMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib_x64/libDCNetworkMD.lib")
#	endif
#	pragma message("Link LibX64 DCNetwork.lib")
#endif

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
const	char*	g_lpszLogFile="GCStateEstimate.log";
extern	void	ClearLog(const char* lpszLogFile);
extern	void	Log(const char* lpszLogFile, char* pformat, ...);
extern	int		StartProcess(char* lpszCmd, const char* lpszPath, WORD swType);

tagPRBlock*				g_pPRBlock;
CPRMemDBInterface		g_PRMemDBInterface;
CPRAdequacyEstimate		g_PRAdeEstimate;

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
	char	szRunDir[260], szRResultFile[260];
	tagBpaPRAdequacySetting	sPRAdeSetting;
	clock_t	dBeg, dEnd;
	int		nDur;

	ClearLog(g_lpszLogFile);
	GetCurrentDirectory(260, szRunDir);
	InitBpaPRAdequacySetting(&sPRAdeSetting);
	memset(szRResultFile, 0, 260);

	int	nEle=1;
	if (argc > nEle)	strcpy(szRunDir, argv[nEle++]);							else	{	Log(g_lpszLogFile, "Error Arg RunDir\n");			return 0;	}
	if (argc > nEle)	sPRAdeSetting.fDc2AcFactor = atof(argv[nEle++]);		else	{	Log(g_lpszLogFile, "Error Arg Dc2AcFactor\n");		return 0;	}
	if (argc > nEle)	sPRAdeSetting.bLineELimit = atoi(argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg LineELimit\n");		return 0;	}
	if (argc > nEle)	sPRAdeSetting.bTranELimit = atoi(argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg TranELimit\n");		return 0;	}
	if (argc > nEle)	sPRAdeSetting.bGenPELimit = atoi(argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg GenPELimit\n");		return 0;	}
	if (argc > nEle)	sPRAdeSetting.bUPFCELimit = atoi(argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg UPFCELimit\n");		return 0;	}
	if (argc > nEle)	sPRAdeSetting.bAuxLoadAdjust = atoi(argv[nEle++]);		else	{	Log(g_lpszLogFile, "Error Arg AuxLoadAdjust\n");	return 0;	}
	if (argc > nEle)	sPRAdeSetting.bEQGenAdjust = atoi(argv[nEle++]);		else	{	Log(g_lpszLogFile, "Error Arg EQGenAdjust\n");		return 0;	}
	if (argc > nEle)	sPRAdeSetting.bEQLoadAdjust = atoi(argv[nEle++]);		else	{	Log(g_lpszLogFile, "Error Arg EQLoadAdjust\n");		return 0;	}
	if (argc > nEle)	sPRAdeSetting.fMinIslandGLRatio = atoi(argv[nEle++]);	else	{	Log(g_lpszLogFile, "Error Arg MinIslandGLRatio\n");	return 0;	}
	if (argc > nEle)	sPRAdeSetting.bUPFCAdjustRC = atoi(argv[nEle++]);		else	{	Log(g_lpszLogFile, "Error Arg UPFCAdjustRC\n");		return 0;	}
	if (argc > nEle)	strcpy(szRResultFile, argv[nEle++]);

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

	{

		{
// 			//////////////////////////////////////////////////////////////////////////
// 			//	调整限值
// 			PRMemDBIsland(g_pPRBlock);
// 			CDCNetwork*	pDCNetwork=new CDCNetwork();
// 
// 			pDCNetwork->PRDCFlow(g_pPRBlock);
// 			delete pDCNetwork;
// 
// 			register int	i;
// 			for (i=0; i<g_pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
// 			{
// 				if (g_pPRBlock->m_ACLineArray[i].fRated > FLT_MIN && 1.01*fDC2ACRatio*fabs(g_pPRBlock->m_ACLineArray[i].fPfPi) > g_pPRBlock->m_ACLineArray[i].fRated)
// 					g_pPRBlock->m_ACLineArray[i].fRated=(float)(1.01*fDC2ACRatio*fabs(g_pPRBlock->m_ACLineArray[i].fPfPi));
// 			}
// 			for (i=0; i<g_pPRBlock->m_nRecordNum[PR_WIND]; i++)
// 			{
// 				if (g_pPRBlock->m_WindArray[i].fRated > FLT_MIN && 1.01*fDC2ACRatio*fabs(g_pPRBlock->m_WindArray[i].fPfPi) > g_pPRBlock->m_WindArray[i].fRated)
// 					g_pPRBlock->m_WindArray[i].fRated=(float)(1.01*fDC2ACRatio*fabs(g_pPRBlock->m_WindArray[i].fPfPi));
// 			}
// 			//	调整限值
// 			//////////////////////////////////////////////////////////////////////////

		}

		{
			unsigned int	nChildThreadID;
			tagAdequacyThreadInfo*	pInfo=(tagAdequacyThreadInfo*)malloc(sizeof(tagAdequacyThreadInfo));
			pInfo->pPRBlock = g_pPRBlock;
			pInfo->nParentThreadID = GetCurrentThreadId();
			pInfo->fAC2DCFactor = sPRAdeSetting.fDc2AcFactor;
			pInfo->bLineEOvl = sPRAdeSetting.bLineELimit;
			pInfo->bTranEOvl = sPRAdeSetting.bTranELimit;
			pInfo->bGenEOvl  = sPRAdeSetting.bGenPELimit ;
			pInfo->bUPFCEOvl = sPRAdeSetting.bUPFCELimit;
			pInfo->bAuxLoadAdjust = sPRAdeSetting.bAuxLoadAdjust;
			pInfo->bEQGenAdjust = sPRAdeSetting.bEQGenAdjust;
			pInfo->bEQLoadAdjust = sPRAdeSetting.bEQLoadAdjust;
			pInfo->bUPFCAdjustRC = sPRAdeSetting.bUPFCAdjustRC;
			pInfo->fMinGLRatio = sPRAdeSetting.fMinIslandGLRatio;
			pInfo->bMultiThread = 1;
			strcpy(pInfo->szResultXmlFile, szRResultFile);
			HANDLE hControl = (HANDLE)_beginthreadex(NULL, 0, SysAdequacyEstimateConThreaad, (void*)pInfo, 0, &nChildThreadID);
			DWORD dwRet=WaitForSingleObject(hControl, INFINITE);

			if (dwRet == WAIT_OBJECT_0)
				Log(g_lpszLogFile, "        发输电系统可靠性评估计算进程完成\n");
			else
				Log(g_lpszLogFile, "        发输电系统可靠性评估计算进程错误 RetCode = %d\n", dwRet);
			if (hControl != INVALID_HANDLE_VALUE)
				CloseHandle(hControl);
		}
	}

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	PrintMessage("发输电系统可靠性评估计算完成，耗时 %d 毫秒", nDur);
}
