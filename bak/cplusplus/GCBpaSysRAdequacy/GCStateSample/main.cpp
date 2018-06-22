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
const	char*	g_lpszLogFile="GCStateSample.log";
extern	void	ClearLog(const char* lpszLogFile);
extern	void	Log(const char* lpszLogFile, char* pformat, ...);

tagPRBlock*				g_pPRBlock;
CPRMemDBInterface		g_PRMemDBInterface;
CPRAdequacyStateSample	m_StateSample;

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
	char	szRunDir[260];
	tagBpaPRAdequacySetting	sBpaPRSetting;
	clock_t	dBeg, dEnd;
	int		nDur;

	ClearLog(g_lpszLogFile);
	GetCurrentDirectory(260, szRunDir);
	InitBpaPRAdequacySetting(&sBpaPRSetting);
	ClearLog(g_lpszLogFile);

	int	nEle=1;
	if (argc > nEle)	strcpy(szRunDir, argv[nEle++]);								else	{	Log(g_lpszLogFile, "Error Arg RunDir\n");			return 0;	}
	if (argc > nEle)	sBpaPRSetting.nPRSampleObject = atoi(argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg SampleMethod\n");		return 0;	}
	if (argc > nEle)	sBpaPRSetting.nPRSampleMethod = atoi(argv[nEle++]);			else	{	Log(g_lpszLogFile, "Error Arg Sample Object\n");	return 0;	}
	if (argc > nEle)	sBpaPRSetting.nMaxGenFault = atoi(argv[nEle++]);			
	if (argc > nEle)	sBpaPRSetting.nMaxBranFault = atoi(argv[nEle++]);			
	if (argc > nEle)	sBpaPRSetting.nMCSSimulateTime = atoi(argv[nEle++]);		
	if (argc > nEle)	sBpaPRSetting.fMCSMinStateProb = atof(argv[nEle++]);		
	if (argc > nEle)	sBpaPRSetting.fFSTMaxCumuProb = atof(argv[nEle++]);			
	if (argc > nEle)	sBpaPRSetting.fFSTMinStateProb = atof(argv[nEle++]);		
	if (argc > nEle)	sBpaPRSetting.nFSTMaxStateNum = atoi(argv[nEle++]);		
	if (argc > nEle)	sBpaPRSetting.nSTSMaxStateNum = atoi(argv[nEle++]);		
	if (argc > nEle)	sBpaPRSetting.fANAMinStateProb = atof(argv[nEle++]);

	for (nEle=0; nEle<argc; nEle++)
		Log(g_lpszLogFile, "Argc[%d] = %s\n", nEle+1, argv[nEle]);

// 	unsigned char	nPRSampleObject;		//	抽样对象类型，0全部；1支路；2发电机
// 	unsigned char	nPRSampleMethod;		//	抽样类型
// 	int				nMaxGenFault;			//	MCS, FST, STS, ANA 抽样最大发电机故障重数
// 	int				nMaxBranFault;			//	MCS, FST, STS, ANA 抽样最大支路故障重数
// 	int				nMCSSimulateTime;		//	MCS最大抽样仿真时长
// 	double			fMCSMinStateProb;		//	MCS[蒙特卡罗]设备故障概率门槛值
// 	double			fFSTMaxCumuProb;		//	FST[快速排序]累积概率
// 	double			fFSTMinStateProb;		//	FST[快速排序]设备故障概率门槛值
// 	int				nFSTMaxStateNum;		//	FST[快速排序]最大状态数
// 	int				nSTSMaxStateNum;		//	STS[状态抽样]最大状态数
// 	double			fANAMinStateProb;		//	ANA[ 解析法 ]设备故障概率门槛值

	dBeg=clock();

	{
		g_pPRBlock=(tagPRBlock*)g_PRMemDBInterface.Init_PRBlock();
		if (!g_pPRBlock)
		{
			PrintMessage("获取PR内存库错误\n");
			return FALSE;
		}
	}

	int	nStateNum=m_StateSample.Sample(g_pPRBlock, sBpaPRSetting.nPRSampleObject, sBpaPRSetting.nPRSampleMethod, &sBpaPRSetting);


	dEnd=clock();
	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
	PrintMessage("状态抽样完毕，耗时%d毫秒 状态数=%d\n",nDur, nStateNum);
}
