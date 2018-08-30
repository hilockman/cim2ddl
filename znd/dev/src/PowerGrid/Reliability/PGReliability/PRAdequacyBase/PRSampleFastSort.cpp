#include <float.h>
#include "PRSampleFastSort.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	CPRSampleFastSort::CPRSampleFastSort(void)
	{
	}

	CPRSampleFastSort::~CPRSampleFastSort(void)
	{
	}

	//	按从小到大排序
	void CPRSampleFastSort::SortFastSortTransient(std::vector<tagFastSortTransient>& tArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		int nDn = nDn0;
		int nUp = nUp0;

		double	fProb=tArray[(nDn0+nUp0)/2].fProb;
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && tArray[nDn].fProb < fProb)
				++nDn;
			while (nUp > nDn0 && tArray[nUp].fProb > fProb)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(tArray[nDn], tArray[nUp]);
				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SortFastSortTransient(tArray, nDn0, nUp);
		if (nDn < nUp0 )
			SortFastSortTransient(tArray, nDn, nUp0);
	}

	//	计算给的状态下的概率
	void CPRSampleFastSort::FastSortCalculateStateProbability(tagPRSampleState* pState)
	{
		register int	i;
		double	fTemp, fBuf;
		int		nComp;

		fTemp=1.0;
		for (i=0; i<(int)m_FSTransientArray.size(); i++)
		{
			if (m_FSTransientArray[i].fProb < FLT_MIN)
				continue;
			fTemp *= m_FSTransientArray[i].fProb;
		}

		for (i=0; i<(int)pState->nFCompArray.size(); i++)
		{
			nComp=pState->nFCompArray[i];
			fBuf=(1-m_FSTransientArray[nComp].fProb)/m_FSTransientArray[nComp].fProb;
			if (fBuf < FLT_MIN)
				continue;
			fTemp *= fBuf;
		}

		pState->fProbability=fTemp;
	}

	void CPRSampleFastSort::FastSortCalculateStateFrequency(tagPRBlock* pPRBlock, tagPRSampleState* pState)
	{
		register int	i;
		double	fTemp=0;
		int		nComp, nDev;

		//////////////////////////////////////////////////////////////////////////
		//	算法1
		//for(i=0; i<pPRBlock->m_nRecordNum[PR_RCOMP]; i++)
		//	fTemp += pPRBlock->m_RCompArray[i].fRerr;
		//for(i=0; i<(int)pState->nFCompArray.size(); i++)
		//{
		//	nComp=m_FSTransientArray[pState->nFCompArray[i]].nCompIndex;
		//	fTemp += (-pPRBlock->m_RCompArray[nComp].fRrep-pPRBlock->m_RCompArray[nComp].fRerr);
		//}
		//pState->fDuration = fTemp;

		//////////////////////////////////////////////////////////////////////////
		//	算法2
		// 	for(i=0; i<pPRBlock->m_nRecordNum[PR_RCOMP]; i++)
		// 		fTemp += pPRBlock->m_RCompArray[i].fRerr*pPRBlock->m_RCompArray[i].fGoodProb/pPRBlock->m_RCompArray[i].fFailProb;
		// 	for(i=0; i<(int)pState->nFCompArray.size(); i++)
		// 	{
		// 		nComp=m_FSTransientArray[pState->nFCompArray[i]].nCompIndex;
		// 		fTemp += (pPRBlock->m_RCompArray[nComp].fRrep-pPRBlock->m_RCompArray[nComp].fRerr)*pPRBlock->m_RCompArray[nComp].fGoodProb/pPRBlock->m_RCompArray[nComp].fFailProb;
		// 	}

		//////////////////////////////////////////////////////////////////////////
		//	算法2
		for (i=0; i<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; i++)
		{
			nComp=pPRBlock->m_R2StateCompArray[i].nIndex;
			switch (pPRBlock->m_R2StateCompArray[i].nType)
			{
			case	PR_ACBUS:
				fTemp += pPRBlock->m_ACBusArray[nComp].fRerr*pPRBlock->m_ACBusArray[nComp].fGoodProb/pPRBlock->m_ACBusArray[nComp].fFailProb;
				break;
			case	PR_ACLINE:
				fTemp += pPRBlock->m_ACLineArray[nComp].fRerr*pPRBlock->m_ACLineArray[nComp].fGoodProb/pPRBlock->m_ACLineArray[nComp].fFailProb;
				break;
			case	PR_WIND:
				fTemp += pPRBlock->m_WindArray[nComp].fRerr*pPRBlock->m_WindArray[nComp].fGoodProb/pPRBlock->m_WindArray[nComp].fFailProb;
				break;
			case	PR_GENERATOR:
				fTemp += pPRBlock->m_GeneratorArray[nComp].fRerr*pPRBlock->m_GeneratorArray[nComp].fGoodProb/pPRBlock->m_GeneratorArray[nComp].fFailProb;
				break;
			case	PR_POWERLOAD:
				fTemp += pPRBlock->m_PowerLoadArray[nComp].fRerr*pPRBlock->m_PowerLoadArray[nComp].fGoodProb/pPRBlock->m_PowerLoadArray[nComp].fFailProb;
				break;
			case	PR_HVDC:
				fTemp += pPRBlock->m_HVDCArray[nComp].fRerr*pPRBlock->m_HVDCArray[nComp].fGoodProb/pPRBlock->m_HVDCArray[nComp].fFailProb;
				break;
			case	PR_TCSC:
				fTemp += pPRBlock->m_TCSCArray[nComp].fRerr*pPRBlock->m_TCSCArray[nComp].fGoodProb/pPRBlock->m_TCSCArray[nComp].fFailProb;
				break;
			case	PR_UPFC:
				fTemp += pPRBlock->m_UPFCArray[nComp].fRerr*pPRBlock->m_UPFCArray[nComp].fGoodProb/pPRBlock->m_UPFCArray[nComp].fFailProb;
				break;
			case	PR_CONVERTER:
				fTemp += pPRBlock->m_ConverterArray[nComp].fRerr*pPRBlock->m_ConverterArray[nComp].fGoodProb/pPRBlock->m_ConverterArray[nComp].fFailProb;
				break;
			case	PR_DCLINE:
				fTemp += pPRBlock->m_DCLineArray[nComp].fRerr*pPRBlock->m_DCLineArray[nComp].fGoodProb/pPRBlock->m_DCLineArray[nComp].fFailProb;
				break;
			}
		}

		for(i=0; i<(int)pState->nFCompArray.size(); i++)
		{
			nComp=m_FSTransientArray[pState->nFCompArray[i]].nCompIndex;
			nDev=pPRBlock->m_R2StateCompArray[nComp].nIndex;
			switch (pPRBlock->m_R2StateCompArray[nComp].nType)
			{
			case	PR_ACBUS:
				fTemp += (pPRBlock->m_ACBusArray[nDev].fRrep-pPRBlock->m_ACBusArray[nDev].fRerr)*pPRBlock->m_ACBusArray[nDev].fGoodProb/pPRBlock->m_ACBusArray[nDev].fFailProb;
				break;
			case	PR_ACLINE:
				fTemp += (pPRBlock->m_ACLineArray[nDev].fRrep-pPRBlock->m_ACLineArray[nDev].fRerr)*pPRBlock->m_ACLineArray[nDev].fGoodProb/pPRBlock->m_ACLineArray[nDev].fFailProb;
				break;
			case	PR_WIND:
				fTemp += (pPRBlock->m_WindArray[nDev].fRrep-pPRBlock->m_WindArray[nDev].fRerr)*pPRBlock->m_WindArray[nDev].fGoodProb/pPRBlock->m_WindArray[nDev].fFailProb;
				break;
			case	PR_GENERATOR:
				fTemp += (pPRBlock->m_GeneratorArray[nDev].fRrep-pPRBlock->m_GeneratorArray[nDev].fRerr)*pPRBlock->m_GeneratorArray[nDev].fGoodProb/pPRBlock->m_GeneratorArray[nDev].fFailProb;
				break;
			case	PR_POWERLOAD:
				fTemp += (pPRBlock->m_PowerLoadArray[nDev].fRrep-pPRBlock->m_PowerLoadArray[nDev].fRerr)*pPRBlock->m_PowerLoadArray[nDev].fGoodProb/pPRBlock->m_PowerLoadArray[nDev].fFailProb;
				break;
			case	PR_HVDC:
				fTemp += (pPRBlock->m_HVDCArray[nDev].fRrep-pPRBlock->m_HVDCArray[nDev].fRerr)*pPRBlock->m_HVDCArray[nDev].fGoodProb/pPRBlock->m_HVDCArray[nDev].fFailProb;
				break;
			case	PR_TCSC:
				fTemp += (pPRBlock->m_TCSCArray[nDev].fRrep-pPRBlock->m_TCSCArray[nDev].fRerr)*pPRBlock->m_TCSCArray[nDev].fGoodProb/pPRBlock->m_TCSCArray[nDev].fFailProb;
				break;
			case	PR_UPFC:
				fTemp += (pPRBlock->m_UPFCArray[nDev].fRrep-pPRBlock->m_UPFCArray[nDev].fRerr)*pPRBlock->m_UPFCArray[nDev].fGoodProb/pPRBlock->m_UPFCArray[nDev].fFailProb;
				break;
			case	PR_CONVERTER:
				fTemp += (pPRBlock->m_ConverterArray[nDev].fRrep-pPRBlock->m_ConverterArray[nDev].fRerr)*pPRBlock->m_ConverterArray[nDev].fGoodProb/pPRBlock->m_ConverterArray[nDev].fFailProb;
				break;
			case	PR_DCLINE:
				fTemp += (pPRBlock->m_DCLineArray[nDev].fRrep-pPRBlock->m_DCLineArray[nDev].fRerr)*pPRBlock->m_DCLineArray[nDev].fGoodProb/pPRBlock->m_DCLineArray[nDev].fFailProb;
				break;
			}
		}
		pState->fDuration = 8760*pState->fProbability/fTemp;
	}

	void CPRSampleFastSort::FastSortExperiment(tagPRBlock* pPRBlock)
	{
		int	nDev;

		pPRBlock->m_nRecordNum[PR_R2STATECOMP]=0;

		nDev=0;
		memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_ACLINE;
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fGoodProb=0.99956;	//元件完好概率
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fFailProb=1-0.99956;	//元件故障概率
		pPRBlock->m_ACLineArray[nDev].fGoodProb=0.99956;		//元件完好概率
		pPRBlock->m_ACLineArray[nDev].fFailProb=1-0.99956;	//元件故障概率
		pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;

		nDev=0;
		memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_GENERATOR;
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fGoodProb=0.9;		//元件完好概率
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fFailProb=1-0.9;		//元件故障概率
		pPRBlock->m_GeneratorArray[nDev].fGoodProb=0.9;			//元件完好概率
		pPRBlock->m_GeneratorArray[nDev].fFailProb=1-0.9;			//元件故障概率
		pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;

		nDev=1;
		memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_GENERATOR;
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fGoodProb=0.9;		//元件完好概率
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fFailProb=1-0.9;		//元件故障概率
		pPRBlock->m_GeneratorArray[nDev].fGoodProb=0.9;			//元件完好概率
		pPRBlock->m_GeneratorArray[nDev].fFailProb=1-0.9;			//元件故障概率
		pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;

		nDev=2;
		memset(&pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]], 0, sizeof(tagPR2StateComp));
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nType=PR_GENERATOR;
		pPRBlock->m_R2StateCompArray[pPRBlock->m_nRecordNum[PR_R2STATECOMP]].nIndex=nDev;
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fGoodProb=0.88005;	//元件完好概率
		//pPRBlock->m_RCompArray[pPRBlock->m_nRecordNum[PR_RCOMP]].fFailProb=1-0.88005;	//元件故障概率
		pPRBlock->m_GeneratorArray[nDev].fGoodProb=0.88005;		//元件完好概率
		pPRBlock->m_GeneratorArray[nDev].fFailProb=1-0.88005;		//元件故障概率
		pPRBlock->m_nRecordNum[PR_R2STATECOMP]++;
	}

	int CPRSampleFastSort::Sample(tagPRBlock* pPRBlock, const double fProbPrecision, const int nMaxState, const int nMaxGenFault, const int nMaxBranFault, const double fStateProbThreshold)
	{
		register int	i;
		tagPRSampleState	stBuf, stAdd;
		int			nComp;
		double		fProb;
		clock_t		dBeg, dEnd;
		int			nDur;

		//FastSortExperiment(pPRBlock);

		pPRBlock->m_System.nSampleMethod=PRFState_SamplingMethod_FastSort;
		pPRBlock->m_System.nMaxBranFlt=nMaxBranFault;
		pPRBlock->m_System.nMaxGenFlt=nMaxGenFault;
		pPRBlock->m_System.fFSTCutProb=fProbPrecision;
		pPRBlock->m_System.nFSTMaxState=nMaxState;
		pPRBlock->m_System.fFSTMinProb=fStateProbThreshold;
		PrevSample(pPRBlock);

		dBeg=clock();

		m_fActualProbility=0;

		m_FSTransientArray.resize(pPRBlock->m_nRecordNum[PR_R2STATECOMP]);
		for (i=0; i<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; i++)
		{
			m_FSTransientArray[i].nCompIndex=i;
			//m_FSTransientArray[i].fProb=fProb=pPRBlock->m_RCompArray[i].fGoodProb;
			nComp=pPRBlock->m_R2StateCompArray[i].nIndex;
			switch (pPRBlock->m_R2StateCompArray[i].nType)
			{
			case	PR_ACBUS:
				m_FSTransientArray[i].fProb=pPRBlock->m_ACBusArray[nComp].fGoodProb;
				fProb=pPRBlock->m_ACBusArray[nComp].fGoodProb;
				break;
			case	PR_ACLINE:
				m_FSTransientArray[i].fProb=pPRBlock->m_ACLineArray[nComp].fGoodProb;
				fProb=pPRBlock->m_ACLineArray[nComp].fGoodProb;
				break;
			case	PR_WIND:
				m_FSTransientArray[i].fProb=pPRBlock->m_WindArray[nComp].fGoodProb;
				fProb=pPRBlock->m_WindArray[nComp].fGoodProb;
				break;
			case	PR_GENERATOR:
				m_FSTransientArray[i].fProb=pPRBlock->m_GeneratorArray[nComp].fGoodProb;
				fProb=pPRBlock->m_GeneratorArray[nComp].fGoodProb;
				break;
			case	PR_POWERLOAD:
				m_FSTransientArray[i].fProb=pPRBlock->m_PowerLoadArray[nComp].fGoodProb;
				fProb=pPRBlock->m_PowerLoadArray[nComp].fGoodProb;
				break;
			case	PR_HVDC:
				m_FSTransientArray[i].fProb=pPRBlock->m_HVDCArray[nComp].fGoodProb;
				fProb=pPRBlock->m_HVDCArray[nComp].fGoodProb;
				break;
			case	PR_TCSC:
				m_FSTransientArray[i].fProb=pPRBlock->m_TCSCArray[nComp].fGoodProb;
				fProb=pPRBlock->m_TCSCArray[nComp].fGoodProb;
				break;
			case	PR_UPFC:
				m_FSTransientArray[i].fProb=pPRBlock->m_UPFCArray[nComp].fGoodProb;
				fProb=pPRBlock->m_UPFCArray[nComp].fGoodProb;
				break;
			case	PR_CONVERTER:
				m_FSTransientArray[i].fProb=pPRBlock->m_ConverterArray[nComp].fGoodProb;
				fProb=pPRBlock->m_ConverterArray[nComp].fGoodProb;
				break;
			case	PR_DCLINE:
				m_FSTransientArray[i].fProb=pPRBlock->m_DCLineArray[nComp].fGoodProb;
				fProb=pPRBlock->m_DCLineArray[nComp].fGoodProb;
				break;
			default:
				break;
			}
			if (m_FSTransientArray[i].fProb < FLT_MIN)
				Log(g_lpszLogFile, "FastSort Comp=%s %d\n", g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_R2StateCompArray[i].nType), nComp);

			if (fProb >= 0.5)
			{
				m_FSTransientArray[i].nStatus=CompStatus_Good;
			}
			else
			{

				m_FSTransientArray[i].nStatus=CompStatus_Fail;
				//m_FSTransientArray[i].fProb=1-pPRBlock->m_RCompArray[i].fGoodProb;
				switch (pPRBlock->m_R2StateCompArray[i].nType)
				{
				case	PR_ACBUS:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_ACBusArray[nComp].fGoodProb;
					break;
				case	PR_ACLINE:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_ACLineArray[nComp].fGoodProb;
					break;
				case	PR_WIND:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_WindArray[nComp].fGoodProb;
					break;
				case	PR_GENERATOR:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_GeneratorArray[nComp].fGoodProb;
					break;
				case	PR_POWERLOAD:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_PowerLoadArray[nComp].fGoodProb;
					break;
				case	PR_HVDC:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_HVDCArray[nComp].fGoodProb;
					break;
				case	PR_TCSC:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_TCSCArray[nComp].fGoodProb;
					break;
				case	PR_UPFC:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_UPFCArray[nComp].fGoodProb;
					break;
				case	PR_CONVERTER:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_ConverterArray[nComp].fGoodProb;
					break;
				case	PR_DCLINE:
					m_FSTransientArray[i].fProb=1-pPRBlock->m_DCLineArray[nComp].fGoodProb;
					break;
				}

				if (m_FSTransientArray[i].fProb < FLT_MIN)
					Log(g_lpszLogFile, "FastSort CompFail=%s %d\n", g_PRMemDBInterface.PRGetTableDesp(pPRBlock->m_R2StateCompArray[i].nType), nComp);
			}
		}

		for (i=0; i<(int)m_FSTransientArray.size(); i++)
		{
			if (m_FSTransientArray[i].fProb < FLT_MIN)
				Log(g_lpszLogFile, "FastSort1 TransientProbError=%d\n", i);
		}
		SortFastSortTransient(m_FSTransientArray, 0, (int)m_FSTransientArray.size()-1);	//	将所有设备按概率从小到大排序
		for (i=0; i<(int)m_FSTransientArray.size(); i++)
		{
			if (m_FSTransientArray[i].fProb < FLT_MIN)
				Log(g_lpszLogFile, "FastSort2 TransientProbError=%d\n", i);
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FastSort，初始化完成耗时%d毫秒\n", nDur);

		m_FSStateArray.clear();

		m_FSNeighbourStateArray.clear();

		InitPRSampleState(pPRBlock, stBuf);
		FastSortCalculateStateProbability(&stBuf);											//	计算系统在该状态下的概率

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FastSort，初始状态概率=%g 耗时%d毫秒\n", stBuf.fProbability, nDur);

		int		nMode;
		double	fProbability=0;
		double	fPrevProb=0;															//	记录上个状态

		i=0;
		while (i < nMaxState)
		{
			dBeg=clock();

			nMode=0;
			if (fabs(fPrevProb-stBuf.fProbability) < FLT_MIN)							//	Mode=0无条件添加状态，Mode=1判断是否存在，不存在则加入状态，概率相同则判断加入状态
				nMode=1;

			if (stBuf.fProbability < fStateProbThreshold)
				break;

			FastSortCalculateStateFrequency(pPRBlock, &stBuf);

			nMode=FastSortAddState(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, nMode);							//	添加状态，1、直接添加；2、不存在才添加
			if (nMode == 2)																//	状态正常添加
			{
				fProbability += stBuf.fProbability;
				if ((i % (nMaxState/10)) == 0)
					//if ((i % 10) == 0)
				{
					Log(g_lpszLogFile, "    状态概率=%g 新增状态概率=%g 总状态数=%d\n", fProbability, stBuf.fProbability, m_FSStateArray.size(), m_FSStateArray.size(), nDur);
					if (!stBuf.nFCompArray.empty())
					{
						for (int nComp=0; nComp<(int)stBuf.nFCompArray.size(); nComp++)
						{
							Log(g_lpszLogFile, "        [%d/%d]=[%d]%d    ", nComp+1, stBuf.nFCompArray.size(), 
								pPRBlock->m_R2StateCompArray[m_FSTransientArray[stBuf.nFCompArray[nComp]].nCompIndex].nType, 
								pPRBlock->m_R2StateCompArray[m_FSTransientArray[stBuf.nFCompArray[nComp]].nCompIndex].nIndex);
						}
						Log(g_lpszLogFile, "\n");
					}
				}
				if (fProbability >= fProbPrecision-FLT_MIN)
					break;

				fPrevProb=stBuf.fProbability;
				ExpandNeighbourhood(&stBuf);
				i++;
			}

			if (m_FSNeighbourStateArray.empty())	//	没有相邻状态，标示所有可能状态搜索完毕
				break;

			SortPRStateProb(m_FSNeighbourStateArray, 0, (int)m_FSNeighbourStateArray.size()-1);
			CopyPRSampleState(&stBuf, &m_FSNeighbourStateArray[0]);
			m_FSNeighbourStateArray.erase(m_FSNeighbourStateArray.begin());				//	相邻状态集中概率最大的状态作为下一个工作状态
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "FastSort计算完成，总状态概率=%g 耗时%d毫秒\n", fProbability, nDur);

		m_fActualProbility=fProbability;

		int				nState;
		pPRBlock->m_nRecordNum[PR_FSTATE]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEFDEV]=0;
		for (nState=0; nState<(int)m_FSStateArray.size(); nState++)
		{
			if (pPRBlock->m_nRecordNum[PR_FSTATE] >= g_PRMemDBInterface.PRGetTableMax(PR_FSTATE)-1)
			{
				Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATE));
				continue;
			}
			memset(&pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]], 0, sizeof(tagPRFState));
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId=pPRBlock->m_nRecordNum[PR_FSTATE]+1;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nSampleType=PRFState_SamplingMethod_FastSort;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum=0;
			for (i=0; i<(int)m_FSStateArray[nState].nFCompArray.size(); i++)
			{
				int nComp=m_FSStateArray[nState].nFCompArray[i];

				if (pPRBlock->m_nRecordNum[PR_FSTATEFDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEFDEV)-1)
				{
					memset(&pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]], 0, sizeof(tagPRFStateFDev));
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateId=pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateNo=pPRBlock->m_nRecordNum[PR_FSTATE];
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp=pPRBlock->m_R2StateCompArray[nComp].nType;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevIdx=pPRBlock->m_R2StateCompArray[nComp].nIndex;
					pPRBlock->m_nRecordNum[PR_FSTATEFDEV]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEFDEV));

				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum++;
			}

			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateProb=m_FSStateArray[nState].fProbability;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateDur=m_FSStateArray[nState].fDuration;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nStateNum=m_FSStateArray[nState].nTotalNumber;
			pPRBlock->m_nRecordNum[PR_FSTATE]++;
		}

		PostSample(pPRBlock);

		return (int)m_FSStateArray.size();
	}

	void CPRSampleFastSort::ExpandNeighbourhood(tagPRSampleState* pState)
	{
		register int	i;
		unsigned char	bExist;

		tagPRSampleState stBuf;
		CopyPRSampleState(&stBuf, pState);

		for (i=0; i<(int)stBuf.nFCompArray.size()-1;i++)
		{
			if ((stBuf.nFCompArray[i]+1) != stBuf.nFCompArray[i+1])
			{
				stBuf.nFCompArray[i]++;
				FastSortCalculateStateProbability(&stBuf);
				FastSortAddNeighbourState(stBuf);
				stBuf.nFCompArray[i]--;
			}
		}

		if (!stBuf.nFCompArray.empty())
		{
			i=(int)stBuf.nFCompArray.size()-1;
			if ((stBuf.nFCompArray[i]+1) < (int)m_FSTransientArray.size())
			{
				stBuf.nFCompArray[i]++;
				FastSortCalculateStateProbability(&stBuf);
				FastSortAddNeighbourState(stBuf);
				stBuf.nFCompArray[i]--;
			}
		}

		if (stBuf.nFCompArray.size() < g_nMaxElement)
		{
			bExist=0;
			for (i=0; i<(int)stBuf.nFCompArray.size(); i++)
			{
				if (stBuf.nFCompArray[i] == 0)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
			{
				stBuf.nFCompArray.push_back(0);
				SortInteger(stBuf.nFCompArray, 0, (int)stBuf.nFCompArray.size()-1);
				FastSortCalculateStateProbability(&stBuf);
				FastSortAddNeighbourState(stBuf);
			}
		}

		//for (i=0; i<(int)m_FSNeighbourStateArray.size(); i++)
		//{
		//	Log(g_lpszLogFile, "        NeighbourState[%d/%d] Prob=%f\n", i+1, m_FSNeighbourStateArray.size(), m_FSNeighbourStateArray[i].fProbability);
		//	for (int nComp=0; nComp<m_FSNeighbourStateArray[i].nFCompArray.size(); nComp++)
		//	{
		//		Log(g_lpszLogFile, "                [%d/%d]=[%d]%d    ", nComp+1, m_FSNeighbourStateArray[i].nFCompArray.size(), 
		//			pPRBlock->m_RCompArray[m_FSTransientArray[m_FSNeighbourStateArray[i].nFCompArray[nComp]].nCompIndex].nType, 
		//			pPRBlock->m_RCompArray[m_FSTransientArray[m_FSNeighbourStateArray[i].nFCompArray[nComp]].nCompIndex].nIndex);
		//	}
		//	Log(g_lpszLogFile, "\n");
		//}
	}

	int CPRSampleFastSort::FastSortAddState(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMaxGenFault, const int nMaxBranFault, const int nMode)
	{
		register int	i, j;
		int				nComp, nGenFault, nBranFault;
		unsigned char	bNotSame;
		tagPRSampleState		stAdd;

		InitPRSampleState(pPRBlock, stAdd);
		for (i=0; i<(int)pState->nFCompArray.size(); i++)
		{
			nComp=m_FSTransientArray[pState->nFCompArray[i]].nCompIndex;
			stAdd.nFCompArray.push_back(nComp);
		}
		for (i=0; i<(int)m_FSTransientArray.size(); i++)
		{
			if (m_FSTransientArray[i].nStatus == CompStatus_Fail)
			{
				nComp=-1;
				for (j=0; j<(int)stAdd.nFCompArray.size(); j++)
				{
					if (stAdd.nFCompArray[j] == m_FSTransientArray[i].nCompIndex)
					{
						nComp=j;
						break;
					}
				}
				if (nComp >= 0)
				{
					stAdd.nFCompArray.erase(stAdd.nFCompArray.begin()+nComp);
				}
			}
		}

		nGenFault=nBranFault=0;
		for (i=0; i<(int)stAdd.nFCompArray.size(); i++)
		{
			if (pPRBlock->m_R2StateCompArray[stAdd.nFCompArray[i]].nType == PR_GENERATOR)
				nGenFault++;
			else if (pPRBlock->m_R2StateCompArray[stAdd.nFCompArray[i]].nType == PR_ACLINE || pPRBlock->m_R2StateCompArray[stAdd.nFCompArray[i]].nType == PR_WIND)
				nBranFault++;
		}

		if (nMaxGenFault > 0 && nMaxBranFault > 0)
		{
			if (nGenFault >= nMaxGenFault)
				return 0;
			if (nBranFault >= nMaxBranFault)
				return 0;
		}
		else
		{
			if (nGenFault+nBranFault >= nMaxGenFault+nMaxBranFault)
				return 0;
		}

		stAdd.fProbability=pState->fProbability;
		stAdd.fDuration=pState->fDuration;

		switch(nMode)
		{
		case 0:
			m_FSStateArray.push_back(stAdd);
			break;
		case 1:
			for (i=0; i<(int)m_FSStateArray.size(); i++)
			{
				bNotSame=0;
				if (stAdd.nFCompArray.size() == m_FSStateArray[i].nFCompArray.size())
				{
					for (j=0; j<(int)stAdd.nFCompArray.size(); j++)
					{
						if (stAdd.nFCompArray[j] != m_FSStateArray[i].nFCompArray[j])
						{
							bNotSame = 1;
							break;
						}
					}
				}
				else
				{
					bNotSame = 1;
				}

				if (!bNotSame)
				{
					m_FSStateArray[i].fDuration += stAdd.fDuration;
					m_FSStateArray[i].nTotalNumber += stAdd.nTotalNumber;
					//return (int)(m_FSStateArray[i].fSeqArray[0]);
					return 0;
				}
			}
			m_FSStateArray.push_back(stAdd);
			break;
		}
		return 2;
	}

	int CPRSampleFastSort::FastSortAddNeighbourState(tagPRSampleState& stAdd)
	{
		register int	i, j;
		unsigned char	bNotSame;

		for (i=0; i<(int)m_FSNeighbourStateArray.size(); i++)
		{
			bNotSame=0;
			if (stAdd.nFCompArray.size() == m_FSNeighbourStateArray[i].nFCompArray.size())
			{
				for (j=0; j<(int)stAdd.nFCompArray.size(); j++)
				{
					if (stAdd.nFCompArray[j] != m_FSNeighbourStateArray[i].nFCompArray[j])
					{
						bNotSame = 1;
						break;
					}
				}
			}
			else
			{
				bNotSame = 1;
			}

			if (!bNotSame)
			{
				m_FSNeighbourStateArray[i].fDuration += stAdd.fDuration;
				m_FSNeighbourStateArray[i].nTotalNumber += stAdd.nTotalNumber;
				//return (int)(m_FSNeighbourStateArray[i].fSeqArray[0]);
				return 0;
			}
		}
		m_FSNeighbourStateArray.push_back(stAdd);

		return 2;
	}

	//元件可靠性参数指数模型的公式：
	//B=ln(fRerrMin/fRerrMax)/(fMinIThredshold-fMaxIThredshold)
	//A=fRerrMin/exp(B*fMinIThredshold)  
	//d_Rerr=A*exp(B*fRtI)
	void CPRSampleFastSort::ModCompModel(tagPRBlock* pPRBlock)	//	计算实时故障率, 指数模型
	{
		register int	i;
		int		nComp;
		double  fRtI, fA, fB;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; i++)
		{
			nComp=pPRBlock->m_R2StateCompArray[i].nIndex;
			switch (pPRBlock->m_R2StateCompArray[i].nType)
			{
			case	PR_ACBUS:
				fRtI = pPRBlock->m_ACBusArray[i].fIRt;
				if (fRtI < pPRBlock->m_ACBusArray[i].fIMin)
				{
					pPRBlock->m_ACBusArray[i].fRerr = (float)pPRBlock->m_ACBusArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_ACBusArray[i].fIMax)
				{
					pPRBlock->m_ACBusArray[i].fRerr = (float)pPRBlock->m_ACBusArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_ACBusArray[i].fRerrMin/pPRBlock->m_ACBusArray[i].fRerrMax)/(pPRBlock->m_ACBusArray[i].fIMin-pPRBlock->m_ACBusArray[i].fIMax);
					fA = pPRBlock->m_ACBusArray[i].fRerrMin/exp(fB*pPRBlock->m_ACBusArray[i].fIMin);
					pPRBlock->m_ACBusArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_ACBusArray[i].fIRt));
					if (pPRBlock->m_ACBusArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_ACBusArray[i].fIMin-pPRBlock->m_ACBusArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_ACBusArray[i].fRerr = 0;
				}
				break;
			case	PR_ACLINE:
				fRtI = pPRBlock->m_ACLineArray[i].fIRt;
				if (fRtI < pPRBlock->m_ACLineArray[i].fIMin)
				{
					pPRBlock->m_ACLineArray[i].fRerr = (float)pPRBlock->m_ACLineArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_ACLineArray[i].fIMax)
				{
					pPRBlock->m_ACLineArray[i].fRerr = (float)pPRBlock->m_ACLineArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_ACLineArray[i].fRerrMin/pPRBlock->m_ACLineArray[i].fRerrMax)/(pPRBlock->m_ACLineArray[i].fIMin-pPRBlock->m_ACLineArray[i].fIMax);
					fA = pPRBlock->m_ACLineArray[i].fRerrMin/exp(fB*pPRBlock->m_ACLineArray[i].fIMin);
					pPRBlock->m_ACLineArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_ACLineArray[i].fIRt));
					if (pPRBlock->m_ACLineArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_ACLineArray[i].fIMin-pPRBlock->m_ACLineArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_ACLineArray[i].fRerr = 0;
				}
				break;
			case	PR_WIND:
				fRtI = pPRBlock->m_WindArray[i].fIRt;
				if (fRtI < pPRBlock->m_WindArray[i].fIMin)
				{
					pPRBlock->m_WindArray[i].fRerr = pPRBlock->m_WindArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_WindArray[i].fIMax)
				{
					pPRBlock->m_WindArray[i].fRerr = pPRBlock->m_WindArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_WindArray[i].fRerrMin/pPRBlock->m_WindArray[i].fRerrMax)/(pPRBlock->m_WindArray[i].fIMin-pPRBlock->m_WindArray[i].fIMax);
					fA = pPRBlock->m_WindArray[i].fRerrMin/exp(fB*pPRBlock->m_WindArray[i].fIMin);
					pPRBlock->m_WindArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_WindArray[i].fIRt));
					if (pPRBlock->m_WindArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_WindArray[i].fIMin-pPRBlock->m_WindArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_WindArray[i].fRerr = 0;
				}
				break;
			case	PR_GENERATOR:
				fRtI = pPRBlock->m_GeneratorArray[i].fIRt;
				if (fRtI < pPRBlock->m_GeneratorArray[i].fIMin)
				{
					pPRBlock->m_GeneratorArray[i].fRerr = (float)pPRBlock->m_GeneratorArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_GeneratorArray[i].fIMax)
				{
					pPRBlock->m_GeneratorArray[i].fRerr = (float)pPRBlock->m_GeneratorArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_GeneratorArray[i].fRerrMin/pPRBlock->m_GeneratorArray[i].fRerrMax)/(pPRBlock->m_GeneratorArray[i].fIMin-pPRBlock->m_GeneratorArray[i].fIMax);
					fA = pPRBlock->m_GeneratorArray[i].fRerrMin/exp(fB*pPRBlock->m_GeneratorArray[i].fIMin);
					pPRBlock->m_GeneratorArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_GeneratorArray[i].fIRt));
					if (pPRBlock->m_GeneratorArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_GeneratorArray[i].fIMin-pPRBlock->m_GeneratorArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_GeneratorArray[i].fRerr = 0;
				}
				break;
			case	PR_POWERLOAD:
				fRtI = pPRBlock->m_PowerLoadArray[i].fIRt;
				if (fRtI < pPRBlock->m_PowerLoadArray[i].fIMin)
				{
					pPRBlock->m_PowerLoadArray[i].fRerr = (float)pPRBlock->m_PowerLoadArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_PowerLoadArray[i].fIMax)
				{
					pPRBlock->m_PowerLoadArray[i].fRerr = (float)pPRBlock->m_PowerLoadArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_PowerLoadArray[i].fRerrMin/pPRBlock->m_PowerLoadArray[i].fRerrMax)/(pPRBlock->m_PowerLoadArray[i].fIMin-pPRBlock->m_PowerLoadArray[i].fIMax);
					fA = pPRBlock->m_PowerLoadArray[i].fRerrMin/exp(fB*pPRBlock->m_PowerLoadArray[i].fIMin);
					pPRBlock->m_PowerLoadArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_PowerLoadArray[i].fIRt));
					if (pPRBlock->m_PowerLoadArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_PowerLoadArray[i].fIMin-pPRBlock->m_PowerLoadArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_PowerLoadArray[i].fRerr = 0;
				}
				break;
			case	PR_HVDC:
				fRtI = pPRBlock->m_HVDCArray[i].fIRt;
				if (fRtI < pPRBlock->m_HVDCArray[i].fIMin)
				{
					pPRBlock->m_HVDCArray[i].fRerr = (float)pPRBlock->m_HVDCArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_HVDCArray[i].fIMax)
				{
					pPRBlock->m_HVDCArray[i].fRerr = (float)pPRBlock->m_HVDCArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_HVDCArray[i].fRerrMin/pPRBlock->m_HVDCArray[i].fRerrMax)/(pPRBlock->m_HVDCArray[i].fIMin-pPRBlock->m_HVDCArray[i].fIMax);
					fA = pPRBlock->m_HVDCArray[i].fRerrMin/exp(fB*pPRBlock->m_HVDCArray[i].fIMin);
					pPRBlock->m_HVDCArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_HVDCArray[i].fIRt));
					if (pPRBlock->m_HVDCArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_HVDCArray[i].fIMin-pPRBlock->m_HVDCArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_HVDCArray[i].fRerr = 0;
				}
				break;
			case	PR_TCSC:
				fRtI = pPRBlock->m_TCSCArray[i].fIRt;
				if (fRtI < pPRBlock->m_TCSCArray[i].fIMin)
				{
					pPRBlock->m_TCSCArray[i].fRerr = (float)pPRBlock->m_TCSCArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_TCSCArray[i].fIMax)
				{
					pPRBlock->m_TCSCArray[i].fRerr = (float)pPRBlock->m_TCSCArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_TCSCArray[i].fRerrMin/pPRBlock->m_TCSCArray[i].fRerrMax)/(pPRBlock->m_TCSCArray[i].fIMin-pPRBlock->m_TCSCArray[i].fIMax);
					fA = pPRBlock->m_TCSCArray[i].fRerrMin/exp(fB*pPRBlock->m_TCSCArray[i].fIMin);
					pPRBlock->m_TCSCArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_TCSCArray[i].fIRt));
					if (pPRBlock->m_TCSCArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_TCSCArray[i].fIMin-pPRBlock->m_TCSCArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_TCSCArray[i].fRerr = 0;
				}
				break;
			case	PR_UPFC:
				fRtI = pPRBlock->m_UPFCArray[i].fIRt;
				if (fRtI < pPRBlock->m_UPFCArray[i].fIMin)
				{
					pPRBlock->m_UPFCArray[i].fRerr = (float)pPRBlock->m_UPFCArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_UPFCArray[i].fIMax)
				{
					pPRBlock->m_UPFCArray[i].fRerr = (float)pPRBlock->m_UPFCArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_UPFCArray[i].fRerrMin/pPRBlock->m_UPFCArray[i].fRerrMax)/(pPRBlock->m_UPFCArray[i].fIMin-pPRBlock->m_UPFCArray[i].fIMax);
					fA = pPRBlock->m_UPFCArray[i].fRerrMin/exp(fB*pPRBlock->m_UPFCArray[i].fIMin);
					pPRBlock->m_UPFCArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_UPFCArray[i].fIRt));
					if (pPRBlock->m_UPFCArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_UPFCArray[i].fIMin-pPRBlock->m_UPFCArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_UPFCArray[i].fRerr = 0;
				}
				break;
			case	PR_CONVERTER:
				fRtI = pPRBlock->m_ConverterArray[i].fIRt;
				if (fRtI < pPRBlock->m_ConverterArray[i].fIMin)
				{
					pPRBlock->m_ConverterArray[i].fRerr = (float)pPRBlock->m_ConverterArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_ConverterArray[i].fIMax)
				{
					pPRBlock->m_ConverterArray[i].fRerr = (float)pPRBlock->m_ConverterArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_ConverterArray[i].fRerrMin/pPRBlock->m_ConverterArray[i].fRerrMax)/(pPRBlock->m_ConverterArray[i].fIMin-pPRBlock->m_ConverterArray[i].fIMax);
					fA = pPRBlock->m_ConverterArray[i].fRerrMin/exp(fB*pPRBlock->m_ConverterArray[i].fIMin);
					pPRBlock->m_ConverterArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_ConverterArray[i].fIRt));
					if (pPRBlock->m_ConverterArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_ConverterArray[i].fIMin-pPRBlock->m_ConverterArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_ConverterArray[i].fRerr = 0;
				}
				break;
			case	PR_DCLINE:
				fRtI = pPRBlock->m_DCLineArray[i].fIRt;
				if (fRtI < pPRBlock->m_DCLineArray[i].fIMin)
				{
					pPRBlock->m_DCLineArray[i].fRerr = (float)pPRBlock->m_DCLineArray[i].fRerrMin;
				}
				else if (fRtI > pPRBlock->m_DCLineArray[i].fIMax)
				{
					pPRBlock->m_DCLineArray[i].fRerr = (float)pPRBlock->m_DCLineArray[i].fRerrMax;
				}
				else
				{
					fB = log(pPRBlock->m_DCLineArray[i].fRerrMin/pPRBlock->m_DCLineArray[i].fRerrMax)/(pPRBlock->m_DCLineArray[i].fIMin-pPRBlock->m_DCLineArray[i].fIMax);
					fA = pPRBlock->m_DCLineArray[i].fRerrMin/exp(fB*pPRBlock->m_DCLineArray[i].fIMin);
					pPRBlock->m_DCLineArray[i].fRerr = (float)(fA*exp(fB*pPRBlock->m_DCLineArray[i].fIRt));
					if (pPRBlock->m_DCLineArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_DCLineArray[i].fIMin-pPRBlock->m_DCLineArray[i].fIMax) < FLT_MIN)
						pPRBlock->m_DCLineArray[i].fRerr = 0;
				}
				break;
			}

			//fRtI = pPRBlock->m_RCompArray[i].fIRt;
			//if (fRtI < pPRBlock->m_RCompArray[i].fIMin)
			//{
			//	pPRBlock->m_RCompArray[i].fRerr = pPRBlock->m_RCompArray[i].fRerrMin;
			//}
			//else if (fRtI > pPRBlock->m_RCompArray[i].fIMax)
			//{
			//	pPRBlock->m_RCompArray[i].fRerr = pPRBlock->m_RCompArray[i].fRerrMax;
			//}
			//else
			//{
			//	fB = log(pPRBlock->m_RCompArray[i].fRerrMin/pPRBlock->m_RCompArray[i].fRerrMax)/(pPRBlock->m_RCompArray[i].fIMin-pPRBlock->m_RCompArray[i].fIMax);
			//	fA = pPRBlock->m_RCompArray[i].fRerrMin/exp(fB*pPRBlock->m_RCompArray[i].fIMin);
			//	pPRBlock->m_RCompArray[i].fRerr = fA*exp(fB*pPRBlock->m_RCompArray[i].fIRt);
			//	if (pPRBlock->m_RCompArray[i].fRerrMax < FLT_MIN || (pPRBlock->m_RCompArray[i].fIMin-pPRBlock->m_RCompArray[i].fIMax) < FLT_MIN)
			//		pPRBlock->m_RCompArray[i].fRerr = 0;
			//}
		}
	}

	//	按从大到小排序
	void CPRSampleFastSort::SortPRStateProb(std::vector<tagPRSampleState>& tArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		int nDn = nDn0;
		int nUp = nUp0;

		double	fProb=tArray[(nDn0+nUp0)/2].fProbability;
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && tArray[nDn].fProbability > fProb)
				++nDn;
			while (nUp > nDn0 && tArray[nUp].fProbability < fProb)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(tArray[nDn], tArray[nUp]);
				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SortPRStateProb(tArray, nDn0, nUp);

		if (nDn < nUp0 )
			SortPRStateProb(tArray, nDn, nUp0);
	}
}
