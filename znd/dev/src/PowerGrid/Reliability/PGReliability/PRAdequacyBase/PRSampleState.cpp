#include "PRSampleState.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	CPRSampleState::CPRSampleState(void)
	{
	}

	CPRSampleState::~CPRSampleState(void)
	{
	}

	int	CPRSampleState::Sample(tagPRBlock* pPRBlock, const int nMaxState)
	{
		register int	i;
		int				nDevice;
		unsigned short	nRandom;
		double			fRandom;

		tagPRSampleState		stBuf;
		InitPRSampleState(pPRBlock, stBuf);

		clock_t	dBeg, dEnd;
		int		nDur;

		pPRBlock->m_System.nSampleMethod=PRFState_SamplingMethod_StateSample;
		PrevSample(pPRBlock);

		srand(1);
		dBeg=clock();

		m_StateArray.clear();
		while (1)
		{
			stBuf.nFCompArray.clear();
			for (nDevice=0; nDevice<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nDevice++)
			{
				nRandom = (unsigned short)((rand())%1000);
				fRandom = nRandom/1000.0;

				switch (pPRBlock->m_R2StateCompArray[nDevice].nType)
				{
				case	PR_ACLINE:
					if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_WIND:
					if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_GENERATOR:
					if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_POWERLOAD:
					if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_HVDC:
					if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_TCSC:
					if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_UPFC:
					if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_CONVERTER:
					if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				case	PR_DCLINE:
					if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nDevice].nIndex].fFailProb >= fRandom)
						stBuf.nFCompArray.push_back(nDevice);
					break;
				}
			}
			nRandom = (unsigned short)((rand())%1000);
			fRandom = nRandom/1000.0;

			m_StateArray.push_back(stBuf);

			if ((int)m_StateArray.size() >= nMaxState)
				break;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "状态抽样完成，耗时 %d 毫秒\n", nDur);

		SortPRSampleStateCompSize(m_StateArray, 0, (int)m_StateArray.size()-1);
		for (i=0; i<(int)m_StateArray.size(); i++)
			SortInteger(m_StateArray[i].nFCompArray, 0, (int)m_StateArray[i].nFCompArray.size()-1);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "状态排序完成，耗时 %d 毫秒\n", nDur);

		SortPRSampleState(m_StateArray, 0, (int)m_StateArray.size()-1);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "SortPRState完成，状态数=%d，最大故障重数=%d 耗时 %d 毫秒\n", m_StateArray.size(), m_StateArray[m_StateArray.size()-1].nFCompArray.size(), nDur);
		pPRBlock->m_System.nMaxFltDev=(int)m_StateArray[m_StateArray.size()-1].nFCompArray.size();

		std::vector<tagPRSampleState>	stArray;
		stArray.clear();

		int	nState=0;
		while (nState < (int)m_StateArray.size())
		{
			i=nState+1;
			while (i < (int)m_StateArray.size())
			{
				if (ComparePRSampleState(m_StateArray[nState], m_StateArray[i]) == 0)
				{
					m_StateArray[nState].nTotalNumber += m_StateArray[i].nTotalNumber;
					m_StateArray[nState].fDuration += m_StateArray[i].fDuration;
				}
				else
					break;

				i++;
			}
			stArray.push_back(m_StateArray[nState]);
			nState=i;
		}

		m_StateArray.assign(stArray.begin(), stArray.end());
		stArray.clear();

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "合并状态完成，状态数=%d，耗时 %d 毫秒\n", m_StateArray.size(), nDur);

		for (nState=0; nState<(int)m_StateArray.size(); nState++)
			m_StateArray[nState].fProbability=(double)m_StateArray[nState].nTotalNumber/nMaxState;

		pPRBlock->m_nRecordNum[PR_FSTATE]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEFDEV]=0;
		for (nState=0; nState<(int)m_StateArray.size(); nState++)
		{
			if (pPRBlock->m_nRecordNum[PR_FSTATE] >= g_PRMemDBInterface.PRGetTableMax(PR_FSTATE)-1)
			{
				Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATE));
				continue;
			}
			memset(&pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]], 0, sizeof(tagPRFState));
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId=pPRBlock->m_nRecordNum[PR_FSTATE]+1;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nSampleType=PRFState_SamplingMethod_StateSample;

			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum=0;
			for (i=0; i<(int)m_StateArray[nState].nFCompArray.size(); i++)
			{
				if (pPRBlock->m_nRecordNum[PR_FSTATEFDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEFDEV)-1)
				{
					memset(&pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]], 0, sizeof(tagPRFStateFDev));
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateId=pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateNo=pPRBlock->m_nRecordNum[PR_FSTATE];
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp=pPRBlock->m_R2StateCompArray[m_StateArray[nState].nFCompArray[i]].nType;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevIdx=pPRBlock->m_R2StateCompArray[m_StateArray[nState].nFCompArray[i]].nIndex;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nDFltTyp=(pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp == PR_GENERATOR) ? PRFState_FaultType_Trip : PRFState_FaultType_ThreePhase;
					pPRBlock->m_nRecordNum[PR_FSTATEFDEV]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEFDEV));

				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum++;
			}

			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateProb=m_StateArray[nState].fProbability;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateDur=m_StateArray[nState].fDuration;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nStateNum=m_StateArray[nState].nTotalNumber;
			pPRBlock->m_nRecordNum[PR_FSTATE]++;
		}

		PostSample(pPRBlock);

		return (int)m_StateArray.size();
	}
}
