#pragma once
#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif

#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using namespace PRMemDB;

namespace	PRAdequacyBase
{
	const	double	S_ERR_MAX = 8760.00;  //故障率上限值，如果大于上限值的话，元件一直处于故障状态，故障概率设为1.0
	const	double	SET_I_SPEC = 0.8;
	const	double	SET_I_TRIP = 1.2;
	const	double	SET_RERR_MAX = 200.0;

	const	int		SystemSate_Max=1000000;

	//故障上限
	const	int		g_nMaxElement=20;
	const	int		g_nMaxSequence=5;

	//////////////////////////////////////////////////////////////////////////
	//	可靠性设备
	enum	_PReliableEnum_CompStatus_
	{
		CompStatus_Fail=0,	//	故障状态
		CompStatus_Good,	//	完好状态
		CompStatus_MState,	//	多状态
	};

	//////////////////////////////////////////////////////////////////////////
	//	抽样状态
	typedef	struct	_PRState_
	{
		int			nTimeSeries;
		std::vector<int>	nFCompArray;				//	故障设备集合

		unsigned char	bMState;						//	表示是多状态设备状态变化还是2状态设备状态变化
		std::vector<double>	fMSCompPoutArray;			//	多状态设备状态

		int			nTotalNumber;						//	出现次数
		double		fProbability;						//	故障概率
		double		fDuration;							//	持续时间
	}	tagPRSampleState;

	class CPRSampleBase
	{
	public:
		CPRSampleBase(void);
		~CPRSampleBase(void);

	public:
		void SetPRSampleStateMState(tagPRBlock* pPRBlock, tagPRSampleState& stBuffer);

		void InitPRSampleState(tagPRBlock* pPRBlock, tagPRSampleState& stBuffer);
		void SortPRSampleState(std::vector<tagPRSampleState>& stArray, int nDn0, int nUp0);
		void CopyPRSampleState(tagPRSampleState* pDestState, tagPRSampleState* pFromState);
		int ComparePRSampleState(tagPRSampleState& stA, tagPRSampleState& stB);

		void SortPRSampleStateCompSize(std::vector<tagPRSampleState>& stArray, int nDn0, int nUp0);
		void SortInteger(std::vector<int>& nArray, int nDn0, int nUp0);

	public:
		void PrevSample(tagPRBlock* pPRBlock);
		void PostSample(tagPRBlock* pPRBlock);
	};
}
