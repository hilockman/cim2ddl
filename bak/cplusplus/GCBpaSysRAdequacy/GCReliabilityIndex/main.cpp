#include <Windows.h>
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
const	char*	g_lpszLogFile="GCReliabilityIndex.log";
extern	void	ClearLog(const char* lpszLogFile);
extern	void	Log(const char* lpszLogFile, char* pformat, ...);

tagPRBlock*			g_pPRBlock;
CPRMemDBInterface	g_PRMemDBInterface;

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

double ResolveDevELmtCutEnergy(tagPRBlock* pPRBlock, const int nDevType, const char* lpszDevName)
{
	register int	i;
	int				nFState;

	if (pPRBlock->m_System.fMCSSimTime < FLT_MIN)
		return 0;

	double	fOvlAdjElLoadEnergy = 0;
	for (nFState=0; nFState<pPRBlock->m_nRecordNum[PR_FSTATE]; nFState++)
	{
		if (pPRBlock->m_FStateArray[nFState].fELCutLoad <= FLT_MIN)
			continue;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]; i++)
		{
			if (pPRBlock->m_FStateOvlAdArray[i].nFStateNo < nFState)
				continue;
			if (pPRBlock->m_FStateOvlAdArray[i].nFStateNo > nFState)
				break;

			if (pPRBlock->m_FStateOvlAdArray[i].nOvlDevTyp != nDevType)
				continue;

			if (pPRBlock->m_FStateOvlAdArray[i].nOvlDevTyp == PR_ACLINE)
			{
				if (stricmp(pPRBlock->m_ACLineArray[pPRBlock->m_FStateOvlAdArray[i].nOvlDevIdx].szName, lpszDevName) != 0)
					continue;
			}
			else if (pPRBlock->m_FStateOvlAdArray[i].nOvlDevTyp == PR_WIND)
			{
				if (stricmp(pPRBlock->m_WindArray[pPRBlock->m_FStateOvlAdArray[i].nOvlDevIdx].szName, lpszDevName) != 0)
					continue;
			}

			if (pPRBlock->m_FStateOvlAdArray[i].nAdjDevTyp == PR_POWERLOAD)
				fOvlAdjElLoadEnergy += pPRBlock->m_FStateOvlAdArray[i].fAdValue*pPRBlock->m_FStateArray[nFState].fStateDur;
		}
	}

	return fOvlAdjElLoadEnergy*8760/pPRBlock->m_System.fMCSSimTime;
}

int main(int argc, char** argv, char** envp)
{
	char	szRunDir[260];
	clock_t	dBeg, dEnd;
	int		nDur;

	double	fAc2DcFactor = 1.15;

	ClearLog(g_lpszLogFile);
	GetCurrentDirectory(260, szRunDir);

	int	nEle=1;
	if (argc > nEle)	strcpy(szRunDir, argv[nEle++]);							else	return 0;
	if (argc > nEle)	fAc2DcFactor = atof(argv[nEle++]);

	for (nEle=0; nEle<argc; nEle++)
		Log(g_lpszLogFile, "Argc[%d] = %s\n", nEle+1, argv[nEle]);

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
		register int	i;
		double			fLoadCut;

		g_PRMemDBInterface.PRMaint(g_pPRBlock);	//	因为调限等数据库记录需要排序

		g_pPRBlock->m_System.fPLC		=0;
		g_pPRBlock->m_System.fEFLC		=0;
		g_pPRBlock->m_System.fEDLC		=0;
		g_pPRBlock->m_System.fADLC		=0;
		g_pPRBlock->m_System.fELC		=0;
		g_pPRBlock->m_System.fEENS		=0;
		g_pPRBlock->m_System.fBPECI		=0;
		g_pPRBlock->m_System.fBPII		=0;
		g_pPRBlock->m_System.fSI		=0;
		g_pPRBlock->m_System.fLOLP		=0;
		g_pPRBlock->m_System.fLOLF		=0;
		g_pPRBlock->m_System.fLOLE		=0;
		g_pPRBlock->m_System.nCutLoadState	=0;
		g_pPRBlock->m_System.fMIslandEENS	=0;
		g_pPRBlock->m_System.fLossGenEENS	=0;
		g_pPRBlock->m_System.fERLimitEENS	=0;
		g_pPRBlock->m_System.fFltGrade0Prob	=0;
		g_pPRBlock->m_System.fFltGrade1Prob	=0;
		g_pPRBlock->m_System.fFltGrade2Prob	=0;
		g_pPRBlock->m_System.fFltGrade3Prob	=0;
		g_pPRBlock->m_System.fFltGrade4Prob	=0;

		for (i=0; i<g_pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
		{
			fLoadCut=g_pPRBlock->m_FStateArray[i].fELCutLoad + g_pPRBlock->m_FStateArray[i].fEnsCutLoad + g_pPRBlock->m_FStateArray[i].fMIOutLoad;
			if (fLoadCut > FLT_MIN)
			{
				g_pPRBlock->m_System.fPLC += g_pPRBlock->m_FStateArray[i].fStateProb;	//	没有问题
				g_pPRBlock->m_System.fELC += fLoadCut;
				g_pPRBlock->m_System.fEENS += fLoadCut*g_pPRBlock->m_FStateArray[i].fStateDur;
				g_pPRBlock->m_System.fEFLC += g_pPRBlock->m_FStateArray[i].nStateNum;	//g_pPRBlock->m_FStateArray[i].nStateNum;

				if (g_pPRBlock->m_FStateArray[i].fMIOutLoad > FLT_MIN)	g_pPRBlock->m_System.fMIslandEENS += g_pPRBlock->m_FStateArray[i].fMIOutLoad*g_pPRBlock->m_FStateArray[i].fStateDur;
				if (g_pPRBlock->m_FStateArray[i].fEnsCutLoad > FLT_MIN)	g_pPRBlock->m_System.fLossGenEENS += g_pPRBlock->m_FStateArray[i].fEnsCutLoad*g_pPRBlock->m_FStateArray[i].fStateDur;
				if (g_pPRBlock->m_FStateArray[i].fELCutLoad > FLT_MIN)	g_pPRBlock->m_System.fERLimitEENS += g_pPRBlock->m_FStateArray[i].fELCutLoad*g_pPRBlock->m_FStateArray[i].fStateDur;
				if (g_pPRBlock->m_FStateArray[i].fEnsCutLoad > FLT_MIN)
				{
					g_pPRBlock->m_System.fLOLP += g_pPRBlock->m_FStateArray[i].fStateProb*g_pPRBlock->m_FStateArray[i].fStateDur;
					g_pPRBlock->m_System.fLOLF += g_pPRBlock->m_FStateArray[i].fStateProb;
					g_pPRBlock->m_System.fLOLE += g_pPRBlock->m_FStateArray[i].fStateDur;
				}
			}
			if (g_pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_0)		g_pPRBlock->m_System.fFltGrade0Prob += g_pPRBlock->m_FStateArray[i].fStateProb;
			else if (g_pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_1)	g_pPRBlock->m_System.fFltGrade1Prob += g_pPRBlock->m_FStateArray[i].fStateProb;
			else if (g_pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_2)	g_pPRBlock->m_System.fFltGrade2Prob += g_pPRBlock->m_FStateArray[i].fStateProb;
			else if (g_pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_3)	g_pPRBlock->m_System.fFltGrade3Prob += g_pPRBlock->m_FStateArray[i].fStateProb;
			else if (g_pPRBlock->m_FStateArray[i].nFaultGrade == PRFState_FaultGrade_4)	g_pPRBlock->m_System.fFltGrade4Prob += g_pPRBlock->m_FStateArray[i].fStateProb;
		}

		if (g_pPRBlock->m_System.nSampleMethod == PRFState_SamplingMethod_MonteCarlo)
		{
			g_pPRBlock->m_System.fEFLC=0;
			for (i=0; i<g_pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
			{
				fLoadCut=g_pPRBlock->m_FStateArray[i].fELCutLoad + g_pPRBlock->m_FStateArray[i].fEnsCutLoad + g_pPRBlock->m_FStateArray[i].fMIOutLoad;
				if (fLoadCut > FLT_MIN)
				{
					g_pPRBlock->m_System.nCutLoadState += g_pPRBlock->m_FStateArray[i].nStateNum;
					g_pPRBlock->m_System.fEFLC += g_pPRBlock->m_FStateArray[i].nStateNum;
				}
			}


// 			for (i=0; i<g_pPRBlock->m_nRecordNum[PR_MCSAMPLESTATE]; i++)
// 			{
// 				g_pPRBlock->m_MCSampleStateArray[i].bCutLoad=0;
// 				fLoadCut=g_pPRBlock->m_FStateArray[g_pPRBlock->m_MCSampleStateArray[i].nFStateNo].fELCutLoad + g_pPRBlock->m_FStateArray[g_pPRBlock->m_MCSampleStateArray[i].nFStateNo].fEnsCutLoad + g_pPRBlock->m_FStateArray[g_pPRBlock->m_MCSampleStateArray[i].nFStateNo].fMIOutLoad;
// 				if (fLoadCut > FLT_MIN)
// 				{
// 					g_pPRBlock->m_MCSampleStateArray[i].bCutLoad=1;
// 					g_pPRBlock->m_System.nCutLoadState++;
// 				}
// 			}
// 
// 			for (i=1; i<g_pPRBlock->m_nRecordNum[PR_MCSAMPLESTATE]; i++)
// 			{
// 				if (g_pPRBlock->m_MCSampleStateArray[i].bCutLoad != 0 && g_pPRBlock->m_MCSampleStateArray[i-1].bCutLoad == 0)
// 					g_pPRBlock->m_System.fEFLC++;
// 			}
		}

		if (g_pPRBlock->m_System.fMCSSimTime > FLT_MIN)	g_pPRBlock->m_System.fEFLC = 8760*g_pPRBlock->m_System.fEFLC/g_pPRBlock->m_System.fMCSSimTime;
		g_pPRBlock->m_System.fEDLC = 8760*g_pPRBlock->m_System.fPLC;
		if (g_pPRBlock->m_System.fEFLC > FLT_MIN)			g_pPRBlock->m_System.fADLC = g_pPRBlock->m_System.fEDLC/g_pPRBlock->m_System.fEFLC;
		if (g_pPRBlock->m_System.fMCSSimTime > FLT_MIN)		g_pPRBlock->m_System.fELC = 8760*g_pPRBlock->m_System.fELC/g_pPRBlock->m_System.fMCSSimTime;
		if (g_pPRBlock->m_System.fMCSSimTime > FLT_MIN)		g_pPRBlock->m_System.fEENS = 8760*g_pPRBlock->m_System.fEENS/g_pPRBlock->m_System.fMCSSimTime;
		if (g_pPRBlock->m_System.fSysMaxLoadP > FLT_MIN)	g_pPRBlock->m_System.fBPII = g_pPRBlock->m_System.fELC/g_pPRBlock->m_System.fSysMaxLoadP;
		if (g_pPRBlock->m_System.fSysMaxLoadP > FLT_MIN)	g_pPRBlock->m_System.fBPECI = g_pPRBlock->m_System.fEENS/g_pPRBlock->m_System.fSysMaxLoadP;
		g_pPRBlock->m_System.fSI = g_pPRBlock->m_System.fBPECI*60;

		if (g_pPRBlock->m_System.fMCSSimTime > FLT_MIN)
		{
			g_pPRBlock->m_System.fMIslandEENS *= 8760/g_pPRBlock->m_System.fMCSSimTime;
			g_pPRBlock->m_System.fLossGenEENS *= 8760/g_pPRBlock->m_System.fMCSSimTime;
			g_pPRBlock->m_System.fERLimitEENS *= 8760/g_pPRBlock->m_System.fMCSSimTime;
		}

		for (i=1; i<g_pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			if (g_pPRBlock->m_System.fMCSSimTime > FLT_MIN)	g_pPRBlock->m_ACBusArray[i].fEFLC = 8760*g_pPRBlock->m_ACBusArray[i].fEFLC/g_pPRBlock->m_System.fMCSSimTime;
			g_pPRBlock->m_ACBusArray[i].fEDLC = 8760*g_pPRBlock->m_ACBusArray[i].fPLC;
			if (g_pPRBlock->m_ACBusArray[i].fEFLC > FLT_MIN)	g_pPRBlock->m_ACBusArray[i].fADLC = g_pPRBlock->m_ACBusArray[i].fEDLC/g_pPRBlock->m_ACBusArray[i].fEFLC;
			if (g_pPRBlock->m_System.fMCSSimTime > FLT_MIN)	g_pPRBlock->m_ACBusArray[i].fELC = 8760*g_pPRBlock->m_ACBusArray[i].fELC/g_pPRBlock->m_System.fMCSSimTime;
			if (g_pPRBlock->m_System.fMCSSimTime > FLT_MIN)	g_pPRBlock->m_ACBusArray[i].fEENS = 8760*g_pPRBlock->m_ACBusArray[i].fEENS/g_pPRBlock->m_System.fMCSSimTime;
			if (g_pPRBlock->m_ACBusArray[i].fLoadP > FLT_MIN)	g_pPRBlock->m_ACBusArray[i].fBPII = g_pPRBlock->m_ACBusArray[i].fELC/g_pPRBlock->m_ACBusArray[i].fLoadP;
			if (g_pPRBlock->m_ACBusArray[i].fLoadP > FLT_MIN)	g_pPRBlock->m_ACBusArray[i].fBPECI = g_pPRBlock->m_ACBusArray[i].fEENS/g_pPRBlock->m_ACBusArray[i].fLoadP;
			g_pPRBlock->m_ACBusArray[i].fSI = g_pPRBlock->m_ACBusArray[i].fBPECI*60;
		}

		for (i=0; i<g_pPRBlock->m_nRecordNum[PR_FSTATEOVLDEV]; i++)
		{
			switch (g_pPRBlock->m_FStateOvlDevArray[i].nDevTyp)
			{
			case	PR_ACLINE:
				g_pPRBlock->m_ACLineArray[g_pPRBlock->m_FStateOvlDevArray[i].nDevIdx].nOLmtFreq++;
				g_pPRBlock->m_ACLineArray[g_pPRBlock->m_FStateOvlDevArray[i].nDevIdx].fOLmtValue += fabs(fabs(fAc2DcFactor*g_pPRBlock->m_FStateOvlDevArray[i].fOvLmtP)-g_pPRBlock->m_FStateOvlDevArray[i].fRated);
				break;
			case	PR_WIND:
				g_pPRBlock->m_WindArray[g_pPRBlock->m_FStateOvlDevArray[i].nDevIdx].nOLmtFreq++;
				g_pPRBlock->m_WindArray[g_pPRBlock->m_FStateOvlDevArray[i].nDevIdx].fOLmtValue += fabs(fabs(fAc2DcFactor*g_pPRBlock->m_FStateOvlDevArray[i].fOvLmtP)-g_pPRBlock->m_FStateOvlDevArray[i].fRated);
				break;
			}
		}

		for (i=0; i<g_pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			if (g_pPRBlock->m_ACLineArray[i].nOLmtFreq <= 0)
				continue;

			g_pPRBlock->m_ACLineArray[i].fOLmtValue /= g_pPRBlock->m_ACLineArray[i].nOLmtFreq;
			g_pPRBlock->m_ACLineArray[i].fELmtCutEnergy = ResolveDevELmtCutEnergy(g_pPRBlock, PR_ACLINE, g_pPRBlock->m_ACLineArray[i].szName);
		}

		for (i=0; i<g_pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			if (g_pPRBlock->m_WindArray[i].nOLmtFreq <= 0)
				continue;

			g_pPRBlock->m_WindArray[i].fOLmtValue /= g_pPRBlock->m_WindArray[i].nOLmtFreq;
			g_pPRBlock->m_WindArray[i].fELmtCutEnergy = ResolveDevELmtCutEnergy(g_pPRBlock, PR_WIND, g_pPRBlock->m_WindArray[i].szName);
		}
	}

	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	PrintMessage("发输电系统可靠性指标计算完成，耗时 %d 毫秒", nDur);
}
