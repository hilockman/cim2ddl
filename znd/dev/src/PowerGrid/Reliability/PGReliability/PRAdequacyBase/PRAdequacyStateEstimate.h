#pragma once
#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif
#include <Windows.h>
#include "../../../DCNetwork/DCNetwork.h"
using namespace DCNetwork;
#include "PROverLimitAd.h"
#include "PRAdequacyBaseExp.h"
namespace	PRAdequacyBase
{
#ifndef TM_ESTIMATEBEG
#	define	TM_ESTIMATEBEG	WM_APP+1001
#endif
#ifndef TM_ESTIMATING
#	define	TM_ESTIMATING	WM_APP+1002
#endif
#ifndef TM_ESTIMATEEND
#	define	TM_ESTIMATEEND	WM_APP+1003
#endif

	static	const char*	g_lpszRResultSemaphore = "ReliabilityAdequacyResultSemphore";

	class PRADEQUACYBASE_EXP CPRAdequacyStateEstimate
	{
	public:
		CPRAdequacyStateEstimate(void);
		~CPRAdequacyStateEstimate(void);

	public:
		void PrepareSysStateEstimate(tagPRBlock* pPRBlock, const unsigned char bUPFCAdjustRC);
		void PrepareGenStateEstimate(tagPRBlock* pPRBlock);
		void SysStateEstimate(tagPRBlock* pPRBlock,
			const int nEstimateState,
			const double fAc2DcFactor,
			const double fMinGLRatio,
			const unsigned char bLineEOvl,
			const unsigned char bTranEOvl,
			const unsigned char bGenPEOvl,
			const unsigned char bUPFCEOvl,
			const unsigned char bAuxLoadAdjust,
			const unsigned char bEQGenAdjust,
			const unsigned char bEQLoadAdjust,
			const unsigned char bUPFCAdjustRC,
			const char* lpszRResultFileName = NULL);

		void GenStateEstimate(tagPRBlock* pPRBlock, const int nEstimateState, const char* lpszRResultFileName);

	private:
		void InitAdequacyEstimateState(tagPRBlock* pPRBlock, const int nFState);
		void ExitAdequacyEstimateState(tagPRBlock* pPRBlock, const int nFState);
		void SaveAdequacyStateXml(tagPRBlock* pPRBlock, const int nEstimateState, const char* lpszResultFileName);

		void CalculateBusPQ(tagPRBlock* pPRBlock, const unsigned char bAuxLoadAdjust=0, const unsigned char bEQGenAdjust=1, const unsigned char bEQLoadAdjust=1);
		void BalanceGenTrip(tagPRBlock* pPRBlock, const int nFState, const double fUnbalanceP);
		void BalanceLoadTrip(tagPRBlock* pPRBlock, const int nFState, const double fUnbalanceP);
		void BalanceIsland(tagPRBlock* pPRBlock, const double fMinGLRatio, const int nFState);

		void BalanceLossGen (tagPRBlock* pPRBlock, const unsigned char bMIslandBalance, const int nFState, const double fLossGenP, const int nIsland, const char* lpszZone);
		void BalanceLossLoad(tagPRBlock* pPRBlock, const unsigned char bMIslandBalance, const int nFState, const double fLossLoadP, const int nIsland, const char* lpszZone);

		void BalanceCommonFault(tagPRBlock* pPRBlock, const int nFState, const int nCommonFault);

	private:

		int CheckFState(tagPRBlock* pPRBlock,
			const double fDC2ACRatio,
			const int nRadial,
			const int nFState,
			const unsigned char bOvLmtLog,
			const unsigned char bLineEOvl,
			const unsigned char bTranEOvl,
			const unsigned char bUPFCAdjustRC,
			int& nOLmtLine,
			int& nOLmtTran,
			double& fOLmtP);

		void AdjustRadial(tagPRBlock* pPRBlock, const int nFState, const int nRadial, const double fDC2ACRatio, const unsigned char bLineEL, const unsigned char bTranEL);
		void AdjustSystem(tagPRBlock* pPRBlock,
			const int nFState,
			const double fDC2ACRatio,
			const unsigned char bLTFault,
			const unsigned char bLineEOvl,
			const unsigned char bTranEOvl,
			const unsigned char bGenPEOvl,
			const unsigned char bUPFCEOvl,
			const unsigned char bAuxLoadAdjust,
			const unsigned char bUPFCAdjustRC);
		void SaveIsland(tagPRBlock* pPRBlock);
		void LoadIsland(tagPRBlock* pPRBlock);

		//////////////////////////////////////////////////////////////////////////
		//	计算可靠性指标
	private:
		void Zone599Estimate(tagPRBlock* pPRBlock, const int nFState);
		void UPFCInitial(tagPRBlock* pPRBlock,
			const double fDc2AcRatio,
			const int nFState,
			const unsigned char bLTFault,
			const unsigned char bGenEOvl, const unsigned char bAuxLoadAdjust,const unsigned char bLineEOvl, double& fLoadCut);
		void UPFCControl(tagPRBlock* pPRBlock, const double fDc2AcFactor);

	private:
		CDCNetwork			m_NetAll;
		CDCNetwork			m_NetFlt;
		CPROverLimitAd		m_PROvLmtAd;

		std::vector<unsigned char>	m_bLineAdjustable;
		std::vector<unsigned char>	m_bTranAdjustable;

	private:
		std::vector<float>	m_fMatZSysArray;
		std::vector<float>	m_fMatZFltArray;

	private:
		int					m_nIslandNum;
		std::vector<short>	m_nBusIslandArray, m_nLineIslandArray, m_nTranIslandArray;
	};
}
