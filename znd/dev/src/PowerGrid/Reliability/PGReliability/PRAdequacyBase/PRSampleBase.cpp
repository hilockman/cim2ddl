#include "PRSampleBase.h"

namespace	PRAdequacyBase
{
	CPRSampleBase::CPRSampleBase(void)
	{
	}

	CPRSampleBase::~CPRSampleBase(void)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	//	状态抽样公用的函数

	void CPRSampleBase::SetPRSampleStateMState(tagPRBlock* pPRBlock, tagPRSampleState& stBuffer)
	{
		register int	i;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_RMSTATECOMP]; i++)
		{
			switch (pPRBlock->m_RMStateCompArray[i].nType)
			{
			case	PR_GENERATOR:
				stBuffer.fMSCompPoutArray[i]=pPRBlock->m_GeneratorArray[pPRBlock->m_RMStateCompArray[i].nIndex].fMSPout;
				break;
			case	PR_POWERLOAD:
				stBuffer.fMSCompPoutArray[i]=pPRBlock->m_PowerLoadArray[pPRBlock->m_RMStateCompArray[i].nIndex].fMSPout;
				break;
			case	PR_HVDC:
				stBuffer.fMSCompPoutArray[i]=pPRBlock->m_HVDCArray[pPRBlock->m_RMStateCompArray[i].nIndex].fMSPout;
				break;
			default:
				stBuffer.fMSCompPoutArray[i]=0;
			}
		}
	}

	void CPRSampleBase::InitPRSampleState(tagPRBlock* pPRBlock, tagPRSampleState& stBuffer)
	{
		stBuffer.nTimeSeries=0;
		stBuffer.nFCompArray.clear();

		stBuffer.fProbability=0.0;
		stBuffer.nTotalNumber=1;
		stBuffer.fDuration=0.0;

		stBuffer.bMState=0;
		stBuffer.fMSCompPoutArray.resize(pPRBlock->m_nRecordNum[PR_RMSTATECOMP]);

		SetPRSampleStateMState(pPRBlock, stBuffer);
	}

	void CPRSampleBase::SortPRSampleState(std::vector<tagPRSampleState>& stArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		tagPRSampleState	stMid;
		int nDn = nDn0;
		int nUp = nUp0;

		CopyPRSampleState(&stMid, &stArray[(nDn0+nUp0)/2]);
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && ComparePRSampleState(stArray[nDn], stMid) < 0)
				++nDn;							 
			while (nUp > nDn0 && ComparePRSampleState(stArray[nUp], stMid) > 0)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(stArray[nDn], stArray[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SortPRSampleState(stArray, nDn0, nUp);

		if (nDn < nUp0 )
			SortPRSampleState(stArray, nDn, nUp0);
	}

	void CPRSampleBase::CopyPRSampleState(tagPRSampleState* pDestState, tagPRSampleState* pFromState)
	{
		pDestState->nTimeSeries		=pFromState->nTimeSeries;
		pDestState->nFCompArray.assign(pFromState->nFCompArray.begin(), pFromState->nFCompArray.end());
		pDestState->nTotalNumber	=pFromState->nTotalNumber;
		pDestState->fProbability	=pFromState->fProbability;
		pDestState->fDuration		=pFromState->fDuration;
		pDestState->bMState			=pFromState->bMState;
		pDestState->fMSCompPoutArray.assign(pFromState->fMSCompPoutArray.begin(), pFromState->fMSCompPoutArray.end());
	}

	int CPRSampleBase::ComparePRSampleState(tagPRSampleState& stA, tagPRSampleState& stB)
	{
		//	多状态模型排序靠后
		if (stA.nFCompArray.size() < stB.nFCompArray.size())
			return -1;
		else if (stA.nFCompArray.size() > stB.nFCompArray.size())
			return 1;

		register int	i;
		for (i=0; i<(int)stA.nFCompArray.size(); i++)
		{
			if (stA.nFCompArray[i] < stB.nFCompArray[i])
				return -1;
			else if (stA.nFCompArray[i] > stB.nFCompArray[i])
				return 1;
		}

		for (i=0; i<(int)stA.fMSCompPoutArray.size(); i++)
		{
			if (stA.fMSCompPoutArray[i] < stB.fMSCompPoutArray[i])
				return -1;
			else if (stA.fMSCompPoutArray[i] > stB.fMSCompPoutArray[i])
				return 1;
		}

		return 0;
	}

	void CPRSampleBase::SortPRSampleStateCompSize(std::vector<tagPRSampleState>& stArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		int nDn = nDn0;
		int nUp = nUp0;

		int nMid=(int)stArray[(nDn0+nUp0)/2].nFCompArray.size();
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && (int)stArray[nDn].nFCompArray.size() < nMid)
				++nDn;
			while (nUp > nDn0 && (int)stArray[nUp].nFCompArray.size() > nMid)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(stArray[nDn], stArray[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SortPRSampleStateCompSize(stArray, nDn0, nUp);

		if (nDn < nUp0 )
			SortPRSampleStateCompSize(stArray, nDn, nUp0);
	}

	void CPRSampleBase::SortInteger(std::vector<int>& nArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		int nDn = nDn0;
		int nUp = nUp0;

		int nMid=nArray[(nDn0+nUp0)/2];
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && nArray[nDn] < nMid)
				++nDn;						
			while (nUp > nDn0 && nArray[nUp] > nMid)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(nArray[nDn], nArray[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SortInteger(nArray, nDn0, nUp);

		if (nDn < nUp0 )
			SortInteger(nArray, nDn, nUp0);
	}


	void CPRSampleBase::PrevSample(tagPRBlock* pPRBlock)
	{
		register int	i;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			pPRBlock->m_ACBusArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
			pPRBlock->m_GeneratorArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_POWERLOAD]; i++)
			pPRBlock->m_PowerLoadArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
			pPRBlock->m_ACLineArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
			pPRBlock->m_WindArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_DCLINE]; i++)
			pPRBlock->m_DCLineArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_HVDC]; i++)
			pPRBlock->m_HVDCArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_TCSC]; i++)
			pPRBlock->m_TCSCArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
			pPRBlock->m_UPFCArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_CONVERTER]; i++)
			pPRBlock->m_ConverterArray[i].nFaultFreq=0;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_DCLINE]; i++)
			pPRBlock->m_DCLineArray[i].nFaultFreq=0;
	}

	void CPRSampleBase::PostSample(tagPRBlock* pPRBlock)
	{
		register int	i;

		for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; i++)
		{
			switch (pPRBlock->m_FStateFDevArray[i].nFDevTyp)
			{
			case	PR_ACBUS:
				pPRBlock->m_ACBusArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_GENERATOR:
				pPRBlock->m_GeneratorArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_POWERLOAD:
				pPRBlock->m_PowerLoadArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_ACLINE:
				pPRBlock->m_ACLineArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_WIND:
				pPRBlock->m_WindArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_HVDC:
				pPRBlock->m_HVDCArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_TCSC:
				pPRBlock->m_TCSCArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_UPFC:
				pPRBlock->m_UPFCArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_CONVERTER:
				pPRBlock->m_ConverterArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			case	PR_DCLINE:
				pPRBlock->m_DCLineArray[pPRBlock->m_FStateFDevArray[i].nFDevIdx].nFaultFreq++;
				break;
			}
		}
	}
}
