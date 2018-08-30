#pragma once

#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using namespace PRMemDB;

namespace	PRAdequacyBase
{
	const	int		g_nConstMaxAdjustTimes = 8;

	typedef	struct _PRBusDisFactor
	{
		int		nBus;
		double	fDFactor;
		double	fGDeltP;	//	因节点发电机TRIP而导致的支路功率变化量
		double	fLDeltP;	//	因节点发电机TRIP而导致的支路功率变化量
	}	tagBusDFactor;

	typedef	struct _PRBranDisFactor
	{
		int		nBran;
		double	fFactor;
		double	fDeltP;	//	因支路TRIP而导致的支路功率变化量
	}	tagBranDFactor;

	typedef	struct	_OLmtAdjust_
	{
		int				nBus;			//	调节母线
		double			fAdjFactor;		//	分布因子，与支路潮流正相关为正，负相关为负。
		double			fAvailAscP;		//	向上可调能力
		double			fAvailDescP;	//	向下可调能力
		double			fOprAdjP;		//	调整量
		short			nAdDirect;		//	调整方向，=0未知，=1表示调整方向为增大，=-1表示调整方向减少
		int				nDevice;		//	设备索引
	}	tagOLmtAdjust;

	class CPROverLimitAd
	{
	public:
		CPROverLimitAd(void);
		~CPROverLimitAd(void);

	public:
		void	InitAdjustParameter(tagPRBlock* pPRBlock);

		int		AdjustLineOverLimit(tagPRBlock* pPRBlock,
			const unsigned char bGenEOvl,
			const unsigned char bUPFCEOvl,
			const unsigned char bAuxLoadAdjust,
			const unsigned char bUPFCAdjustRC,
			const unsigned char bCheckGenAdjDirection,
			const int nFState,
			const int nLine,
			const double fOlmP,
			double& fLoadCut,
			std::vector<float>& fMatZArray);
		int		AdjustTranOverLimit(tagPRBlock* pPRBlock,
			const unsigned char bGenEOvl,
			const unsigned char bUPFCEOvl,
			const unsigned char bAuxLoadAdjust,
			const unsigned char bUPFCAdjustRC,
			const unsigned char bCheckGenAdjDirection,
			const int nFState,
			const int nTran,
			const double fOlmP,
			double& fLoadCut,
			std::vector<float>& fMatZArray);

		int		AdjustRadialLineOverLimit(tagPRBlock* pPRBlock, const int nRadial, const int nFState, const int nLine, const double fOlmP, double& fLoadCut, std::vector<float>& fMatZArray);
		int		AdjustRadialTranOverLimit(tagPRBlock* pPRBlock, const int nRadial, const int nFState, const int nTran, const double fOlmP, double& fLoadCut, std::vector<float>& fMatZArray);

	private:
		void	SorOvLmtAdFactorL2H(std::vector<tagOLmtAdjust>& dfArray, int nDn0, int nUp0);
		void	SorOvLmtAdFactorH2L(std::vector<tagOLmtAdjust>& dfArray, int nDn0, int nUp0);

	private:
		void	FormBranDFactor(tagPRBlock* pPRBlock, const int nBusI, const int nBusJ, const double fX, const int nIsland, std::vector<float> fMatZArray);
		void	GetAdjustArray(tagPRBlock* pPRBlock, const unsigned char bAuxLoadAdjust, const unsigned char bUPFCAdjustRC, std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray);

		int		AdjustOverLimit(tagPRBlock* pPRBlock, const unsigned char bGenEOvl, const unsigned char bUPFCEOvl, const unsigned char bCheckGenAdjDirection,
			const int nFState, const unsigned char nOvlDevTyp, const int nOvlDevIdx, const double fOlmP, double& fLoadCut,
			std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray);

		int		AdjustOverLimit_DecreaseFlow(tagPRBlock* pPRBlock, const unsigned char bGenEOvl, const unsigned char bUPFCEOvl, const unsigned char bCheckGenAdjDirection,
			const int nFState, const unsigned char nOvlDevTyp, const int nOvlDevIdx, const double fOlmP,
			std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray);

		int		AdjustOverLimit_IncreaseFlow(tagPRBlock* pPRBlock, const unsigned char bGenEOvl, const unsigned char bUPFCEOvl, const unsigned char bCheckGenAdjDirection,
			const int nFState, const unsigned char nOvlDevTyp, const int nOvlDevIdx, const double fOlmP,
			std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray);

		void	FormRadialBranDFactor(tagPRBlock* pPRBlock, const int nRadial, const int nBusI, const int nBusJ, const double fX, const int nIsland, std::vector<float> fMatZArray);
		void	GetRadialAdjustArray(tagPRBlock* pPRBlock, const int nRadial, const double fOlmP, std::vector<tagOLmtAdjust>& GenAdArray, std::vector<tagOLmtAdjust>& LoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray);

	private:
		std::vector<tagBusDFactor>	m_BranDFactorArray;
		std::vector<double>			m_fBusGenAdjustArray;
	};
}
