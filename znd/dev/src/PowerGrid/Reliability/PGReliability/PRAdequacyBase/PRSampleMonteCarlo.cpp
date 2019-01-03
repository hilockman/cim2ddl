#include <float.h>
#include <assert.h>
#include "PRSampleMonteCarlo.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface				g_PRMemDBInterface;
	extern	std::vector<tagPRMCSampleState>	g_PRMCSSampleStateArray;

	CPRSampleMonteCarlo::CPRSampleMonteCarlo(void)
	{
	}

	CPRSampleMonteCarlo::~CPRSampleMonteCarlo(void)
	{
	}

	void CPRSampleMonteCarlo::MCSDevStateDuration_Sort(std::vector<tagMCSDevState>& evtArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;	

		int nDn = nDn0;
		int nUp = nUp0;

		double	fEvtTime=evtArray[(nDn0+nUp0)/2].fEvtTime;
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && evtArray[nDn].fEvtTime < fEvtTime)
				++nDn;								 
			while (nUp > nDn0 && evtArray[nUp].fEvtTime > fEvtTime)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(evtArray[nDn], evtArray[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			MCSDevStateDuration_Sort(evtArray, nDn0, nUp);

		if (nDn < nUp0 )
			MCSDevStateDuration_Sort(evtArray, nDn, nUp0);
	}


	int CPRSampleMonteCarlo::MonteCarlo2StateAddFDev(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMaxGenFault, const int nMaxBranFault, const int nFDev)
	{
		if ((int)pState->nFCompArray.size() >= nMaxBranFault+nMaxGenFault)
			return 0;

		register int	i;
		for (i=0; i<(int)pState->nFCompArray.size(); i++)
		{
			if (pState->nFCompArray[i] == nFDev)
				return 2;
		}

		int	nGenFault, nBranFault;
		nGenFault=nBranFault=0;
		for (i=0; i<(int)pState->nFCompArray.size(); i++)
		{
			if (pPRBlock->m_R2StateCompArray[pState->nFCompArray[i]].nType == PR_GENERATOR)
				nGenFault++;
			else if (pPRBlock->m_R2StateCompArray[pState->nFCompArray[i]].nType == PR_ACLINE ||
				pPRBlock->m_R2StateCompArray[pState->nFCompArray[i]].nType == PR_WIND)
				nBranFault++;
		}

		if (nGenFault >= nMaxGenFault)
			return 0;
		if (nBranFault >= nMaxBranFault)
			return 0;

		pState->nFCompArray.push_back(nFDev);

		return 1;
	}

	void CPRSampleMonteCarlo::MonteCarlo2StateDelFDev(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nFDev)
	{
		register int	i;
		i=0;
		while (i < (int)pState->nFCompArray.size())
		{
			if (pState->nFCompArray[i] == nFDev)
				pState->nFCompArray.erase(pState->nFCompArray.begin()+i);
			else
				i++;
		}
	}

	int CPRSampleMonteCarlo::Sample(tagPRBlock* pPRBlock, const double fSimTime, const int nMaxGenFault, const int nMaxBranFault, const double fProbThreshold)
	{
		register int	i;
		int		nComp;

		clock_t	dBeg, dEnd;
		int		nDur;

		tagMCSDevState	sDevStBuffer;

		pPRBlock->m_System.nSampleMethod=PRFState_SamplingMethod_MonteCarlo;
		pPRBlock->m_System.fMCSSimTime=fSimTime;
		pPRBlock->m_System.fMCSMinProb=fProbThreshold;
		pPRBlock->m_System.nMaxBranFlt=nMaxBranFault;
		pPRBlock->m_System.nMaxGenFlt=nMaxGenFault;
		PrevSample(pPRBlock);

		srand(1);
		dBeg=clock();

		//////////////////////////////////////////////////////////////////////////
		//	��״̬�ɿ����豸����״̬����ʱ�����
		m_MCSDevStateArray.clear();
		for (i=0; i<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; i++)
		{
			memset(&sDevStBuffer, 0, sizeof(tagMCSDevState));
			sDevStBuffer.nCompIndex=i;	//	��CompArray�е����
			sDevStBuffer.bMState=0;

			nComp=pPRBlock->m_R2StateCompArray[i].nIndex;
			switch (pPRBlock->m_R2StateCompArray[i].nType)
			{
			case	PR_ACBUS:
				sDevStBuffer.fRerr=pPRBlock->m_ACBusArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_ACBusArray[nComp].fRrep;
				break;
			case	PR_ACLINE:
				sDevStBuffer.fRerr=pPRBlock->m_ACLineArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_ACLineArray[nComp].fRrep;
				break;
			case	PR_WIND:
				sDevStBuffer.fRerr=pPRBlock->m_WindArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_WindArray[nComp].fRrep;
				break;
			case	PR_GENERATOR:
				sDevStBuffer.fRerr=pPRBlock->m_GeneratorArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_GeneratorArray[nComp].fRrep;
				break;
			case	PR_POWERLOAD:
				sDevStBuffer.fRerr=pPRBlock->m_PowerLoadArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_PowerLoadArray[nComp].fRrep;
				break;
			case	PR_HVDC:
				sDevStBuffer.fRerr=pPRBlock->m_HVDCArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_HVDCArray[nComp].fRrep;
				break;
			case	PR_TCSC:
				sDevStBuffer.fRerr=pPRBlock->m_TCSCArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_TCSCArray[nComp].fRrep;
				break;
			case	PR_UPFC:
				sDevStBuffer.fRerr=pPRBlock->m_UPFCArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_UPFCArray[nComp].fRrep;
				break;
			case	PR_CONVERTER:
				sDevStBuffer.fRerr=pPRBlock->m_ConverterArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_ConverterArray[nComp].fRrep;
				break;
			case	PR_DCLINE:
				sDevStBuffer.fRerr=pPRBlock->m_DCLineArray[nComp].fRerr;
				sDevStBuffer.fRrep=pPRBlock->m_DCLineArray[nComp].fRrep;
				break;
			}
			sDevStBuffer.nStatus=CompStatus_Good;
			sDevStBuffer.fEvtTime=0;
			MCSDev2StateDuration_Calc(&sDevStBuffer);	//	��̬������״̬ΪGOOD����һ״̬ΪFAIL������GOOD״̬����ʱ��

			m_MCSDevStateArray.push_back(sDevStBuffer);
		}

		//////////////////////////////////////////////////////////////////////////
		//	��״̬�ɿ����豸����״̬����ʱ�����
		for (i=0; i<pPRBlock->m_nRecordNum[PR_RMSTATECOMP]; i++)
		{
			memset(&sDevStBuffer, 0, sizeof(tagMCSDevState));
			sDevStBuffer.nCompIndex=i;	//	��CompArray�е����
			sDevStBuffer.bMState=1;
			sDevStBuffer.fEvtTime=0;
			MCSDevMStateDuration_Calc(pPRBlock, &sDevStBuffer);

			m_MCSDevStateArray.push_back(sDevStBuffer);
		}

		//////////////////////////////////////////////////////////////////////////
		//	��״̬����ʱ���������
		MCSDevStateDuration_Sort(m_MCSDevStateArray, 0, (int)m_MCSDevStateArray.size()-1);

		m_MCSSysStateArray.clear();
		pPRBlock->m_nRecordNum[PR_FSTATE]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEFDEV]=0;

		double	fTime, fCurTime=0;
		tagPRSampleState stBuf;
		InitPRSampleState(pPRBlock, stBuf);

		//	��̬
		stBuf.fDuration=m_MCSDevStateArray[0].fEvtTime;
		m_MCSSysStateArray.push_back(stBuf);

		for(;;)
		{
			fCurTime = m_MCSDevStateArray[0].fEvtTime;

			if ( fCurTime >= pPRBlock->m_System.fMCSSimTime ) break;

			for (i=0; i<(int)m_MCSDevStateArray.size(); i++)
			{
				if (fabs(m_MCSDevStateArray[i].fEvtTime-fCurTime) <= FLT_MIN)	//	�豸��״̬����ʱ�䵽�ˣ���Ҫ����״̬��ת
				{
					if (!m_MCSDevStateArray[i].bMState)
					{
						stBuf.bMState=0;
						if (m_MCSDevStateArray[i].nStatus == CompStatus_Good)		//	���豸��һ״̬ΪGOOD�����豸�ӹ����豸�б���ɾ��
							MonteCarlo2StateDelFDev(pPRBlock, &stBuf, m_MCSDevStateArray[i].nCompIndex);
						else														//	���豸��һ״̬ΪFAIL�����豸��ӵ������豸�б���
							MonteCarlo2StateAddFDev(pPRBlock, &stBuf, pPRBlock->m_System.nMaxGenFlt, pPRBlock->m_System.nMaxBranFlt, m_MCSDevStateArray[i].nCompIndex);

						MCSDev2StateDuration_Calc(&m_MCSDevStateArray[i]);			//	�豸״̬�����˷�ת�������´η�ת�ĳ���ʱ��
					}
					else
					{
						stBuf.bMState=1;
						MonteCarloMState(pPRBlock, &stBuf, m_MCSDevStateArray[i].nCompIndex);
						SetPRSampleStateMState(pPRBlock, stBuf);
						MCSDevMStateDuration_Calc(pPRBlock, &m_MCSDevStateArray[i]);			//	�豸״̬�����˷�ת�������´η�ת�ĳ���ʱ��
					}
				}
				else
				{
					break;
				}
			}

			MCSDevStateDuration_Sort(m_MCSDevStateArray, 0, (int)m_MCSDevStateArray.size()-1);
			fTime = m_MCSDevStateArray[0].fEvtTime;
			if (fTime > pPRBlock->m_System.fMCSSimTime)	fTime=pPRBlock->m_System.fMCSSimTime;

			stBuf.fDuration=fTime-fCurTime;
			m_MCSSysStateArray.push_back(stBuf);
			stBuf.nTimeSeries++;
		}

		//////////////////////////////////////////////////////////////////////////
		//	��MCS״̬��¼����Ϊ��ʱ�������������ݿ⸺��
		g_PRMCSSampleStateArray.resize(m_MCSSysStateArray.size());
		for (i=0; i<(int)g_PRMCSSampleStateArray.size(); i++)
			memset(&g_PRMCSSampleStateArray[i], 0, sizeof(tagPRMCSampleState));
		//pPRBlock->m_nRecordNum[PR_MCSAMPLESTATE]=(int)m_MCSSysStateArray.size();
		//for (i=0; i<pPRBlock->m_nRecordNum[PR_MCSAMPLESTATE]; i++)
		//	memset(&pPRBlock->m_MCSampleStateArray[i], 0, sizeof(tagPRMCSampleState));
		//	��MCS״̬��¼����Ϊ��ʱ�������������ݿ⸺��
		//////////////////////////////////////////////////////////////////////////

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "״̬������ɣ�״̬��=%d ��ʱ %d ����\n", m_MCSSysStateArray.size(), nDur);
		printf("״̬������ɣ���ʱ %d ����\n", nDur);

		// #ifdef	_DEBUG
		// 	for (nComp=0; nComp<(int)m_MCSSysStateArray.size(); nComp++)
		// 	{
		// 		Log(g_lpszLogFile, "MCState[%d/%d]����������=%d ����ʱ��=%f    MState", nComp+1, m_MCSSysStateArray.size(), m_MCSSysStateArray[nComp].nFCompArray.size(), m_MCSSysStateArray[nComp].fDuration);
		// 		for (i=0; i<(int)m_MCSSysStateArray[i].fMSCompPoutArray.size(); i++)
		// 			Log(g_lpszLogFile, "    [%d/%d]=%f", i+1, m_MCSSysStateArray[nComp].fMSCompPoutArray.size(), m_MCSSysStateArray[nComp].fMSCompPoutArray[i]);
		// 		Log(g_lpszLogFile, "\n");
		// 	}
		// #endif

		for (i=0; i<(int)m_MCSSysStateArray.size(); i++)
			SortInteger(m_MCSSysStateArray[i].nFCompArray, 0, (int)m_MCSSysStateArray[i].nFCompArray.size()-1);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "״̬������ɣ���ʱ %d ����\n", nDur);
		printf("״̬������ɣ���ʱ %d ����\n", nDur);

		SortPRSampleState(m_MCSSysStateArray, 0, (int)m_MCSSysStateArray.size()-1);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "SortPRState��ɣ�״̬��=%d������������=%d ��ʱ %d ����\n", m_MCSSysStateArray.size(), m_MCSSysStateArray[m_MCSSysStateArray.size()-1].nFCompArray.size(), nDur);
		printf("SortPRState��ɣ�״̬��=%d������������=%d ��ʱ %d ����\n", m_MCSSysStateArray.size(), m_MCSSysStateArray[m_MCSSysStateArray.size()-1].nFCompArray.size(), nDur);
		pPRBlock->m_System.nMaxFltDev=(int)m_MCSSysStateArray[m_MCSSysStateArray.size()-1].nFCompArray.size();

		std::vector<tagPRSampleState>	sSampleStateArray, sMStateArray;
		sSampleStateArray.clear();
		sMStateArray.clear();

		int	nState=0;
		while (nState < (int)m_MCSSysStateArray.size())
		{
			//////////////////////////////////////////////////////////////////////////
			//	��MCS״̬��¼����Ϊ��ʱ�������������ݿ⸺��
			g_PRMCSSampleStateArray[m_MCSSysStateArray[nState].nTimeSeries].nFStateNo=(int)sSampleStateArray.size();
			//pPRBlock->m_MCSampleStateArray[m_MCSSysStateArray[nState].nTimeSeries].nFStateNo=(int)sSampleStateArray.size();
			//	��MCS״̬��¼����Ϊ��ʱ�������������ݿ⸺��
			//////////////////////////////////////////////////////////////////////////

			i=nState+1;
			while (i < (int)m_MCSSysStateArray.size())
			{
				if (ComparePRSampleState(m_MCSSysStateArray[nState], m_MCSSysStateArray[i]) == 0)
				{
					m_MCSSysStateArray[nState].nTotalNumber += m_MCSSysStateArray[i].nTotalNumber;
					m_MCSSysStateArray[nState].fDuration += m_MCSSysStateArray[i].fDuration;

					//////////////////////////////////////////////////////////////////////////
					//	��MCS״̬��¼����Ϊ��ʱ�������������ݿ⸺��
					g_PRMCSSampleStateArray[m_MCSSysStateArray[i].nTimeSeries].nFStateNo=(int)sSampleStateArray.size();
					//pPRBlock->m_MCSampleStateArray[m_MCSSysStateArray[i].nTimeSeries].nFStateNo=(int)sSampleStateArray.size();
					//	��MCS״̬��¼����Ϊ��ʱ�������������ݿ⸺��
					//////////////////////////////////////////////////////////////////////////
				}
				else
					break;

				i++;
			}
			sSampleStateArray.push_back(m_MCSSysStateArray[nState]);
			nState=i;
		}
		m_MCSSysStateArray.assign(sSampleStateArray.begin(), sSampleStateArray.end());

		if (pPRBlock->m_nRecordNum[PR_RMSTATECOMP] > 0)
		{
			SortPRSampleMStatePout(sSampleStateArray, 0, (int)sSampleStateArray.size()-1);
			nState=0;
			while (nState < (int)sSampleStateArray.size())
			{
				i=nState+1;
				while (i < (int)sSampleStateArray.size())
				{
					if (ComparePRSampleMStatePout(sSampleStateArray[nState], sSampleStateArray[i]) == 0)
					{
					}
					else
						break;

					i++;
				}
				sMStateArray.push_back(sSampleStateArray[nState]);
				nState=i;
			}
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "�ϲ�״̬��ɣ�״̬��=%d����ʱ %d ����\n", m_MCSSysStateArray.size(), nDur);
		printf( "�ϲ�״̬��ɣ�״̬��=%d����ʱ %d ����\n", m_MCSSysStateArray.size(), nDur);

		for (nState=0; nState<(int)m_MCSSysStateArray.size(); nState++)
			m_MCSSysStateArray[nState].fProbability=m_MCSSysStateArray[nState].fDuration/pPRBlock->m_System.fMCSSimTime;
		sSampleStateArray.clear();
		if (pPRBlock->m_System.fMCSMinProb > FLT_MIN)
		{
			for (i=0; i<(int)m_MCSSysStateArray.size();i++)
			{
				if (m_MCSSysStateArray[i].fProbability > pPRBlock->m_System.fMCSMinProb)
					sSampleStateArray.push_back(m_MCSSysStateArray[i]);
			}

			Log(g_lpszLogFile, "����͸����¼���ɣ�״̬��=%d -> %d ��ʱ %d ����\n", m_MCSSysStateArray.size(), sSampleStateArray.size(), nDur);
			printf("����͸����¼���ɣ�״̬��=%d -> %d����ʱ %d ����\n", m_MCSSysStateArray.size(), sSampleStateArray.size(), nDur);

			m_MCSSysStateArray.assign(sSampleStateArray.begin(), sSampleStateArray.end());
			sSampleStateArray.clear();
		}

		pPRBlock->m_nRecordNum[PR_FSTATE]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEFDEV]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]=0;

		for (nState=0; nState<(int)sMStateArray.size(); nState++)
		{
			for (i=0; i<pPRBlock->m_nRecordNum[PR_RMSTATECOMP]; i++)
			{
				if (pPRBlock->m_nRecordNum[PR_FSTATEMSTATE] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEMSTATE)-1)
				{
					memset(&pPRBlock->m_FStateMStateArray[pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]], 0, sizeof(tagPRFStateMState));
					pPRBlock->m_FStateMStateArray[pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]].nMSDevType=pPRBlock->m_RMStateCompArray[i].nType;
					pPRBlock->m_FStateMStateArray[pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]].nMSDevIdx=pPRBlock->m_RMStateCompArray[i].nIndex;
					pPRBlock->m_FStateMStateArray[pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]].fStatePout=sMStateArray[nState].fMSCompPoutArray[i];
					pPRBlock->m_nRecordNum[PR_FSTATEMSTATE]++;
				}
				else
				{
					Log(g_lpszLogFile, "        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEMSTATE));
				}
			}
		}

		for (nState=0; nState<(int)m_MCSSysStateArray.size(); nState++)
		{
			if (pPRBlock->m_nRecordNum[PR_FSTATE] >= g_PRMemDBInterface.PRGetTableMax(PR_FSTATE)-1)
			{
				Log(g_lpszLogFile, "        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATE));
				continue;
			}

			memset(&pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]], 0, sizeof(tagPRFState));
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId=pPRBlock->m_nRecordNum[PR_FSTATE]+1;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nSampleType=PRFState_SamplingMethod_MonteCarlo;

			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum=0;
			for (i=0; i<(int)m_MCSSysStateArray[nState].nFCompArray.size(); i++)
			{
				if (pPRBlock->m_nRecordNum[PR_FSTATEFDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEFDEV)-1)
				{
					memset(&pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]], 0, sizeof(tagPRFStateFDev));
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateId=pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateNo=pPRBlock->m_nRecordNum[PR_FSTATE];
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp=pPRBlock->m_R2StateCompArray[m_MCSSysStateArray[nState].nFCompArray[i]].nType;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevIdx=pPRBlock->m_R2StateCompArray[m_MCSSysStateArray[nState].nFCompArray[i]].nIndex;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nDFltTyp=(pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp == PR_GENERATOR) ? PRFState_FaultType_Trip : PRFState_FaultType_ThreePhase;
					pPRBlock->m_nRecordNum[PR_FSTATEFDEV]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEFDEV));

				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum++;
			}

			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateProb=m_MCSSysStateArray[nState].fProbability;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateDur=m_MCSSysStateArray[nState].fDuration;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nStateNum=m_MCSSysStateArray[nState].nTotalNumber;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nMSoutIndex=FindPRSampleMStatePout(sMStateArray, 0, (int)sMStateArray.size()-1, m_MCSSysStateArray[nState]);
			pPRBlock->m_nRecordNum[PR_FSTATE]++;
		}

		sMStateArray.clear();

		PostSample(pPRBlock);

		// 	//	������
		// 	pPRBlock->m_nRecordNum[PR_FSTATE]=2;
		// 	pPRBlock->m_nRecordNum[PR_FSTATEFDEV]=0;
		// 	memset(&pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]], 0, sizeof(tagPRFStateFDev));
		// 	pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateNo=1;
		// 	pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp=PR_ACLINE;
		// 	for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		// 	{
		// 		if (stricmp(pPRBlock->m_ACLineArray[i].szName, "����ׯ__230-������__230@1") == 0)
		// 		{
		// 			pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevIdx=i;
		// 			break;
		// 		}
		// 	}
		// 	pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nDFltTyp=PRFState_FaultType_Trip;
		// 	pPRBlock->m_nRecordNum[PR_FSTATEFDEV]++;
		// 	return 2;
		// 	//	������

		return (int)m_MCSSysStateArray.size();
	}

	void CPRSampleMonteCarlo::MCSDev2StateDuration_Calc(tagMCSDevState* pDevState)
	{
		double fTimeLap = 0.0f;

		unsigned short nRandom = (unsigned short)((rand())%1000);
		if (nRandom < 1 || nRandom > 999)		
		{
		}
		double fRandom = nRandom/1000.0;
		fRandom = log(1-fRandom);	//fRandom = (float)log(fRandom);

		if (pDevState->nStatus == CompStatus_Good) 
		{
			pDevState->nStatus = CompStatus_Fail;
			if (pDevState->fRerr < FLT_MIN)
				fTimeLap = 999999999.9;
			else if (pDevState->fRerr > 8760)
				fTimeLap=0.01;
			else
				fTimeLap = -fRandom * (8760.0/pDevState->fRerr);
		}
		else 
		{
			_ASSERT( pDevState->nStatus==CompStatus_Fail );
			pDevState->nStatus = CompStatus_Good;
			if (pDevState->fRrep < FLT_MIN)
				fTimeLap = 999999999.9;
			else
				fTimeLap = -fRandom * (8760.0/pDevState->fRrep);
		}
		pDevState->fEvtTime += fTimeLap;

		//Log(g_lpszLogFile, "MCSDev2StateDuration_Calc TimeLap=%f\n", fTimeLap);
	}

	//////////////////////////////////////////////////////////////////////////
	//	1����ȡ��ǰ״̬ -- nMState��
	//	2��������ȥ�� -- �õ���һ״̬
	//	3�����ù���
	void CPRSampleMonteCarlo::MonteCarloMState(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMStateDev)
	{
		register int	i;
		int		nComp, nMState, nDevMState;
		double	*pfFreq, *pfRate, fDiagDep, fDRate, fNextP, fBuffer;
		unsigned short nRandom = (unsigned short)((rand())%1000);
		double fRandom = nRandom/1000.0;

		nComp=pPRBlock->m_RMStateCompArray[nMStateDev].nIndex;

		fNextP=0;

		nDevMState=-1;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
		{
			if (pPRBlock->m_DevMStateArray[i].nIndex == nComp && pPRBlock->m_DevMStateArray[i].nType == pPRBlock->m_RMStateCompArray[nMStateDev].nType)
			{
				nDevMState=i;
				break;
			}
		}
		if (nDevMState < 0)
		{
			assert(0);
			return;
		}

		pfRate=&pPRBlock->m_DevMStateArray[nDevMState].fState1Rate;
		pfFreq=&pPRBlock->m_DevMStateArray[nDevMState].fState1Freq1;
		nMState=0;

		switch (pPRBlock->m_RMStateCompArray[nMStateDev].nType)
		{
		case	PR_GENERATOR:
			//	ͨ�������õ���ǰ״̬
			for (i=pPRBlock->m_DevMStateArray[nDevMState].nStateNum-1; i>=0; i--)	//	���������Ǵ�С�������Է�����ѭ��
			{
				if (pfRate[i]*pPRBlock->m_GeneratorArray[nComp].fPMax <= pPRBlock->m_GeneratorArray[nComp].fMSPout)
				{
					nMState=i;
					break;
				}
			}

			//	��ǰ״̬�µĶԽ�Ԫ
			fDiagDep=-1;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] < 0)
				{
					fDiagDep=-pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i];
					break;
				}
			}
			if (fDiagDep < 0)	//	�Խ�Ԫ
			{
				assert(0);
				return;
			}

			//Log(g_lpszLogFile, "        Random=%f  ��ǰ״̬=%d[%f]    ", fRandom, nMState, pPRBlock->m_GeneratorArray[nComp].fMSPout);

			//////////////////////////////////////////////////////////////////////////
			//	�õ���ȥ��
			fDRate=0;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] <= FLT_MIN)
					continue;

				fBuffer=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/fDiagDep;
				//Log(g_lpszLogFile, "%d[%f %f] ", i, fDRate, fDRate+fBuffer);
				fDRate += fBuffer;
			}
			//Log(g_lpszLogFile, "\n");
			//	�������
			//////////////////////////////////////////////////////////////////////////

			fDRate=0;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] <= FLT_MIN)
					continue;

				fBuffer=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/fDiagDep;
				if (fDRate < fRandom && fRandom <= fDRate+fBuffer)	//	��һ״̬
				{
					nMState=i;
					break;
				}
				fDRate += fBuffer;
			}
			//////////////////////////////////////////////////////////////////////////

			if (nMState < pPRBlock->m_DevMStateArray[nDevMState].nStateNum)
				fNextP=pPRBlock->m_GeneratorArray[nComp].fMSPout=pfRate[nMState]*pPRBlock->m_GeneratorArray[nComp].fPMax;

			break;
		case	PR_POWERLOAD:
			//	ͨ�������õ���ǰ״̬
			for (i=pPRBlock->m_DevMStateArray[nDevMState].nStateNum-1; i>=0; i--)
			{
				if (pfRate[i]*pPRBlock->m_PowerLoadArray[nComp].fPMax <= pPRBlock->m_PowerLoadArray[nComp].fMSPout)
				{
					nMState=i;
					break;
				}
			}

			//	��ǰ״̬�µĶԽ�Ԫ
			fDiagDep=-1;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] < 0)
				{
					fDiagDep=-pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i];
					break;
				}
			}
			if (fDiagDep < 0)	//	�Խ�Ԫ
			{
				assert(0);
				return;
			}

			Log(g_lpszLogFile, "        Random=%f  ��ǰ״̬=%d[%f]    ", fRandom, nMState, pPRBlock->m_PowerLoadArray[nComp].fMSPout);

			//	�õ���ȥ��
			fDRate=0;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] <= FLT_MIN)
					continue;

				fBuffer=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/fDiagDep;
				Log(g_lpszLogFile, "%d[%f %f] ", i, fDRate, fDRate+fBuffer);
				fDRate += fBuffer;
			}
			Log(g_lpszLogFile, "\n");

			fDRate=0;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] <= FLT_MIN)
					continue;

				fBuffer=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/fDiagDep;
				if (fDRate < fRandom && fRandom <= fDRate+fBuffer)	//	��һ״̬
				{
					nMState=i;
					break;
				}
				fDRate += fBuffer;
			}

			if (nMState < pPRBlock->m_DevMStateArray[nDevMState].nStateNum)
				fNextP=pPRBlock->m_PowerLoadArray[nComp].fMSPout=pfRate[nMState]*pPRBlock->m_PowerLoadArray[nComp].fPMax;

			break;
		case	PR_HVDC:
			for (i=pPRBlock->m_DevMStateArray[nDevMState].nStateNum-1; i>=0; i--)
			{
				if (pfRate[i]*pPRBlock->m_HVDCArray[nComp].fRatedP <= pPRBlock->m_HVDCArray[nComp].fMSPout)
				{
					nMState=i;
					break;
				}
			}

			//	��ǰ״̬�µĶԽ�Ԫ
			fDiagDep=-1;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] < 0)
				{
					fDiagDep=-pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i];
					break;
				}
			}
			if (fDiagDep < 0)	//	�Խ�Ԫ
			{
				assert(0);
				return;
			}

			Log(g_lpszLogFile, "        Random=%f  ��ǰ״̬=%d[%f]    ", fRandom, nMState, pPRBlock->m_HVDCArray[nComp].fMSPout);

			//	�õ���ȥ��
			fDRate=0;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] <= FLT_MIN)
					continue;

				fBuffer=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/fDiagDep;
				Log(g_lpszLogFile, "%d[%f %f] ", i, fDRate, fDRate+fBuffer);
				fDRate += fBuffer;
			}
			Log(g_lpszLogFile, "\n");

			fDRate=0;
			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] <= FLT_MIN)
					continue;

				fBuffer=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/fDiagDep;
				if (fDRate < fRandom && fRandom <= fDRate+fBuffer)	//	��һ״̬
				{
					nMState=i;
					break;
				}
				fDRate += fBuffer;
			}

			if (nMState < pPRBlock->m_DevMStateArray[nDevMState].nStateNum)
				fNextP=pPRBlock->m_HVDCArray[nComp].fMSPout=pfRate[nMState]*pPRBlock->m_HVDCArray[nComp].fRatedP;

			break;
		}

		Log(g_lpszLogFile, "MonteCarloMState NextMState=%d[%f]\n", nMState, fNextP);
	}

	//////////////////////////////////////////////////////////////////////////
	//	1����ȡ��ǰ״̬��
	//	2��������ȥ��
	void CPRSampleMonteCarlo::MCSDevMStateDuration_Calc(tagPRBlock* pPRBlock, tagMCSDevState* pDevState)
	{
		_ASSERT( pDevState->bMState );

		register int	i;
		double fTimeLap = 0.0f, *pfFreq, *pfRate, *pfProb, fDRate, fPout;
		unsigned short nRandom = (unsigned short)((rand())%1000);
		double fRandom = nRandom/1000.0;

		int nComp=pPRBlock->m_RMStateCompArray[pDevState->nCompIndex].nIndex;
		int	nDevMState, nMState=-1;

		nDevMState=nMState=-1;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
		{
			if (pPRBlock->m_DevMStateArray[i].nIndex == nComp && pPRBlock->m_DevMStateArray[i].nType == pPRBlock->m_RMStateCompArray[pDevState->nCompIndex].nType)
			{
				nDevMState=i;
				break;
			}
		}
		if (nDevMState < 0)
		{
			assert(0);
			return;
		}

		pfRate=&pPRBlock->m_DevMStateArray[nDevMState].fState1Rate;
		pfProb=&pPRBlock->m_DevMStateArray[nDevMState].fState1Prob;
		pfFreq=&pPRBlock->m_DevMStateArray[nDevMState].fState1Freq1;

		fTimeLap=8760;
		fPout=0;
		switch (pPRBlock->m_RMStateCompArray[pDevState->nCompIndex].nType)
		{
		case	PR_GENERATOR:
			fPout=pPRBlock->m_GeneratorArray[nComp].fMSPout;
			for (i=pPRBlock->m_DevMStateArray[nDevMState].nStateNum-1; i>=0; i--)
			{
				if (pPRBlock->m_GeneratorArray[nComp].fMSPout >= pfRate[i]*pPRBlock->m_GeneratorArray[nComp].fPMax)
				{
					nMState=i;
					break;
				}
			}
			if (nMState < 0)
			{
				assert(0);
				return;
			}

			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] < 0)
				{
					fDRate=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/pfProb[nMState];
					if (fabs(fDRate) > FLT_MIN)	fTimeLap=8760*log(fRandom)/fDRate;
					break;
				}
			}

			break;
		case	PR_POWERLOAD:
			fPout=pPRBlock->m_PowerLoadArray[nComp].fMSPout;
			for (i=pPRBlock->m_DevMStateArray[nDevMState].nStateNum-1; i>=0; i--)
			{
				if (pPRBlock->m_PowerLoadArray[nComp].fMSPout >= pfRate[i]*pPRBlock->m_PowerLoadArray[nComp].fPMax)
				{
					nMState=i;
					break;
				}
			}
			if (nMState < 0)
			{
				assert(0);
				return;
			}

			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] < 0)
				{
					fDRate=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/pfProb[nMState];
					if (fabs(fDRate) > FLT_MIN)	fTimeLap=8760*log(fRandom)/fDRate;
					break;
				}
			}

			break;
		case	PR_HVDC:
			fPout=pPRBlock->m_HVDCArray[nComp].fMSPout;
			for (i=pPRBlock->m_DevMStateArray[nDevMState].nStateNum-1; i>=0; i--)
			{
				if (pPRBlock->m_HVDCArray[nComp].fMSPout >= pfRate[i]*pPRBlock->m_HVDCArray[nComp].fRatedP)
				{
					nMState=i;
					break;
				}
			}
			if (nMState < 0)
			{
				assert(0);
				return;
			}

			for (i=0; i<pPRBlock->m_DevMStateArray[nDevMState].nStateNum; i++)
			{
				if (pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i] < 0)
				{
					fDRate=pfFreq[nMState*pPRBlock->m_DevMStateArray[nDevMState].nStateNum+i]/pfProb[nMState];
					if (fabs(fDRate) > FLT_MIN)	fTimeLap=8760*log(fRandom)/fDRate;
					break;
				}
			}

			break;
		}

		pDevState->fEvtTime += fTimeLap;

		Log(g_lpszLogFile, "MCSDevMStateDuration_Calc MState=%d[%f] TimeLap=%f\n\n", nMState, fPout, fTimeLap);
	}


	int CPRSampleMonteCarlo::ComparePRSampleMStatePout(tagPRSampleState& stA, tagPRSampleState& stB)
	{
		register int	i;
		//	��״̬ģ�����򿿺�
		for (i=0; i<(int)stA.fMSCompPoutArray.size(); i++)
		{
			if (stA.fMSCompPoutArray[i] < stB.fMSCompPoutArray[i])
				return -1;
			else if (stA.fMSCompPoutArray[i] > stB.fMSCompPoutArray[i])
				return 1;
		}

		return 0;
	}

	void CPRSampleMonteCarlo::SortPRSampleMStatePout(std::vector<tagPRSampleState>& stArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		tagPRSampleState	stMid;
		int nDn = nDn0;
		int nUp = nUp0;

		CopyPRSampleState(&stMid, &stArray[(nDn0+nUp0)/2]);
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && ComparePRSampleMStatePout(stArray[nDn], stMid) < 0)
				++nDn;							 
			while (nUp > nDn0 && ComparePRSampleMStatePout(stArray[nUp], stMid) > 0)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(stArray[nDn], stArray[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SortPRSampleMStatePout(stArray, nDn0, nUp);

		if (nDn < nUp0 )
			SortPRSampleMStatePout(stArray, nDn, nUp0);
	}

	int CPRSampleMonteCarlo::FindPRSampleMStatePout(std::vector<tagPRSampleState>& stArray, int nLeft, int nRight, tagPRSampleState& stBuf)
	{
		if (nLeft <= nRight)
		{
			int	nMid = (nLeft+nRight)/2;
			if (ComparePRSampleMStatePout(stArray[nMid], stBuf) == 0)
			{
				return nMid;
			}
			else
			{
				if (ComparePRSampleMStatePout(stArray[nMid], stBuf) > 0)
					return FindPRSampleMStatePout(stArray, nLeft, nMid-1, stBuf);
				else
					return FindPRSampleMStatePout(stArray, nMid+1, nRight, stBuf);
			}
		}
		else
		{
			return -1;
		}
	}
}
