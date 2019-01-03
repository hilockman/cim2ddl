#pragma once
#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif
#include <Windows.h>

#include "../../../DCNetwork/DCNetwork.h"
using	namespace	DCNetwork;

#include "BpaPRDataDefine.h"
#include "PRAdequacyBaseExp.h"

namespace	PRAdequacyBase
{
	static const char*	g_lpszGenRResultFileName ="GenRAdequacyResult.xml";
	static const char*	g_lpszSysRResultFileName ="SysRAdequacyResult.xml";

	class PRADEQUACYBASE_EXP CPRAdequacyEstimate
	{
	public:
		CPRAdequacyEstimate(void);
		~CPRAdequacyEstimate(void);

	public:
		void	AdjustDeviceRated(tagPRBlock* pPRBlock, const double fDC2ACRatio, const unsigned char bUPFCAdjustRC);

	public:	//	后评估方法
		static CRITICAL_SECTION m_csLock;

	private:
		unsigned char	m_bEstimating;

		//////////////////////////////////////////////////////////////////////////
		//	状态后评估

	public:	//	发电系统可靠性评估	
		void InitAdequacyXmlFile(const char* lpszXmlFileName, const char* lpszRootTag);
		void ExitAdequacyXmlFile(const char* lpszXmlFileName, const char* lpszRootTag);
		void InitAdequacyEstimate(tagPRBlock* pPRBlock);
		void ExitAdequacyEstimate(tagPRBlock* pPRBlock, const double fAc2DcFactor, const char* lpszResultXmlFile);

		HANDLE GenAdequacyEstimate(tagPRBlock* pPRBlock,
			const unsigned char nMultiThread,
			const char* lpszResultFileName = NULL);	//	基于MCS的发电系统可靠性
		HANDLE SysAdequacyEstimate(tagPRBlock* pPRBlock,
			const unsigned char nMultiThread,
			const double fDC2ACRatio,
			const double fMinGLRatio,
			const unsigned char bLineEOvl,
			const unsigned char bTranEOvl,
			const unsigned char bGenPEOvl,
			const unsigned char bUPFCEOvl,
			const unsigned char bAuxLoadAdjust,
			const unsigned char	bEQGenAdjust,
			const unsigned char	bEQLoadAdjust,
			const unsigned char bUPFCAdjustRC,
			const char* lpszRResultFileName = NULL);//	发输电系统可靠性评估	

	private:
		void SaveAdequacyEstimateResult(tagPRBlock* pPRBlock, const char* lpszResultFileName);
		double ResolveDevELmtCutEnergy(tagPRBlock* pPRBlock, const int nDevType, const char* lpszDevName)	;	//{	return 0;	};	//形成设备越限消限电量

#ifdef _DEBUG
		void SaveCompPRParam(tagPRBlock* pPRBlock)	;//	{};	//	调试使用，目的是为了记录设备可靠性参数
#endif

	public:	//	指标文件输入和输出
		void WriteAdequacyResult(tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const int nDur);
	};
}
extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, char* pformat, ...);
