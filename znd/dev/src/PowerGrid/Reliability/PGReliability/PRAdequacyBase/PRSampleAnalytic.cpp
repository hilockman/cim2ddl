#include <float.h>
#include "PRSampleAnalytic.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	CPRSampleAnalytic::CPRSampleAnalytic(void)
	{
	}

	CPRSampleAnalytic::~CPRSampleAnalytic(void)
	{
	}

	int CPRSampleAnalytic::StateAnalyticalCalculateStateProbability(tagPRBlock* pPRBlock, tagPRSampleState* pState, const int nMaxGenFault, const int nMaxBranFault, const double fMinStateProb)
	{
		register int	i;
		double	fTemp, fBuf;
		int		nComp;
		int		nGenFault, nBranFault;

		nGenFault=nBranFault=0;
		for (i=0; i<(int)pState->nFCompArray.size(); i++)
		{
			switch (pPRBlock->m_R2StateCompArray[pState->nFCompArray[i]].nType)
			{
			case	PR_ACBUS:		nBranFault++;	break;
			case	PR_GENERATOR:			nGenFault++;	break;
			case	PR_POWERLOAD:		nGenFault++;	break;
			case	PR_ACLINE:		nBranFault++;	break;
			case	PR_WIND:		nBranFault++;	break;
			case	PR_HVDC:		nBranFault++;	break;
			case	PR_TCSC:		nBranFault++;	break;
			case	PR_UPFC:		nBranFault++;	break;
			case	PR_CONVERTER:	nBranFault++;	break;
			case	PR_DCLINE:		nBranFault++;	break;
			}
		}
		if (nGenFault > nMaxGenFault || nBranFault > nMaxBranFault)
			return 0;

		fTemp=m_fSysProb;
		for (i=0; i<(int)pState->nFCompArray.size(); i++)
		{
			nComp=pState->nFCompArray[i];
			switch (pPRBlock->m_R2StateCompArray[nComp].nType)
			{
			case	PR_GENERATOR:
				fBuf=(1-pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_POWERLOAD:
				fBuf=(1-pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_ACBUS:
				fBuf=(1-pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_ACLINE:
				fBuf=(1-pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_WIND:
				fBuf=(1-pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_HVDC:
				fBuf=(1-pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_TCSC:
				fBuf=(1-pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_UPFC:
				fBuf=(1-pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_CONVERTER:
				fBuf=(1-pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			case	PR_DCLINE:
				fBuf=(1-pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb)/pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nComp].nIndex].fGoodProb;
				break;
			}
			if (fBuf < FLT_MIN)
				return 0;

			fTemp *= fBuf;
		}

		if (fMinStateProb > FLT_MIN && fTemp < fMinStateProb)
			return 0;

		pState->fProbability=fTemp;

		return 1;
	}

	int	CPRSampleAnalytic::Sample(tagPRBlock* pPRBlock, const int nMaxGenFault, const int nMaxBranFault, const double fMinStateProb)
	{
		register int	i;
		int		nState;
		unsigned char	bFlag;
		int		nFlt1, nFlt2, nFlt3, nFlt4, nFlt5, nFlt6, nFlt7, nFlt8, nFlt9, nFlt10, nFlt11, nFlt12;

		tagPRSampleState	stBuf;
		InitPRSampleState(pPRBlock, stBuf);
		stBuf.nTotalNumber=1;

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		pPRBlock->m_System.nSampleMethod=PRFState_SamplingMethod_Analytical;
		pPRBlock->m_System.nMaxBranFlt=nMaxBranFault;
		pPRBlock->m_System.nMaxGenFlt=nMaxGenFault;
		PrevSample(pPRBlock);

		m_SAStateArray.clear();

		m_fSysProb=1.0;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; i++)
		{
			switch (pPRBlock->m_R2StateCompArray[i].nType)
			{
			case	PR_ACBUS:
				if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_ACLINE:
				if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_WIND:
				if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_GENERATOR:
				if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_POWERLOAD:
				if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_HVDC:
				if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_TCSC:
				if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_UPFC:
				if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_CONVERTER:
				if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			case	PR_DCLINE:
				if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[i].nIndex].fFailProb > FLT_MIN)	m_fSysProb *= pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[i].nIndex].fGoodProb;
				break;
			}
		}

		for (nFlt1=0; nFlt1<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt1++)
		{
			bFlag=1;
			switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
			{
			case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
			case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
			case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
			case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
			case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
			case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
			case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
			case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
			case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
			case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt1].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
			}
			if (bFlag)	continue;

			stBuf.nFCompArray.clear();
			stBuf.nFCompArray.push_back(nFlt1);
			if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
				m_SAStateArray.push_back(stBuf);

			for (nFlt2=nFlt1+1; nFlt2<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt2++)
			{
				bFlag=1;
				switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
				{
				case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
				case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
				case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
				case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
				case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
				case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
				case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
				case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
				case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
				case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt2].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
				}
				if (bFlag)	continue;

				stBuf.nFCompArray.clear();
				stBuf.nFCompArray.push_back(nFlt1);
				stBuf.nFCompArray.push_back(nFlt2);
				if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
					m_SAStateArray.push_back(stBuf);

				for (nFlt3=nFlt2+1; nFlt3<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt3++)
				{
					bFlag=1;
					switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
					{
					case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
					case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
					case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
					case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
					case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
					case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
					case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
					case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
					case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
					case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt3].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
					}
					if (bFlag)	continue;

					stBuf.nFCompArray.clear();
					stBuf.nFCompArray.push_back(nFlt1);
					stBuf.nFCompArray.push_back(nFlt2);
					stBuf.nFCompArray.push_back(nFlt3);
					if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
						m_SAStateArray.push_back(stBuf);

					for (nFlt4=nFlt3+1; nFlt4<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt4++)
					{
						bFlag=1;
						switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
						{
						case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
						case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
						case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
						case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
						case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
						case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
						case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
						case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
						case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
						case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt4].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
						}
						if (bFlag)	continue;

						stBuf.nFCompArray.clear();
						stBuf.nFCompArray.push_back(nFlt1);
						stBuf.nFCompArray.push_back(nFlt2);
						stBuf.nFCompArray.push_back(nFlt3);
						stBuf.nFCompArray.push_back(nFlt4);
						if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
							m_SAStateArray.push_back(stBuf);

						for (nFlt5=nFlt4+1; nFlt5<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt5++)
						{
							if (nMaxGenFault+nMaxBranFault < 5)
								break;

							bFlag=1;
							switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
							{
							case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
							case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
							case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
							case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
							case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
							case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
							case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
							case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
							case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
							case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt5].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
							}
							if (bFlag)	continue;

							stBuf.nFCompArray.clear();
							stBuf.nFCompArray.push_back(nFlt1);
							stBuf.nFCompArray.push_back(nFlt2);
							stBuf.nFCompArray.push_back(nFlt3);
							stBuf.nFCompArray.push_back(nFlt4);
							stBuf.nFCompArray.push_back(nFlt5);
							if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
								m_SAStateArray.push_back(stBuf);

							for (nFlt6=nFlt5+1; nFlt6<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt6++)
							{
								if (nMaxGenFault+nMaxBranFault < 6)
									break;

								bFlag=1;
								switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
								{
								case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
								case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
								case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
								case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
								case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
								case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
								case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
								case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
								case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
								case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt6].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
								}
								if (bFlag)	continue;

								stBuf.nFCompArray.clear();
								stBuf.nFCompArray.push_back(nFlt1);
								stBuf.nFCompArray.push_back(nFlt2);
								stBuf.nFCompArray.push_back(nFlt3);
								stBuf.nFCompArray.push_back(nFlt4);
								stBuf.nFCompArray.push_back(nFlt5);
								stBuf.nFCompArray.push_back(nFlt6);
								if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
									m_SAStateArray.push_back(stBuf);

								for (nFlt7=nFlt6+1; nFlt7<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt7++)
								{
									if (nMaxGenFault+nMaxBranFault < 7)
										break;

									bFlag=1;
									switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
									{
									case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
									case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
									case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
									case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
									case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
									case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
									case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
									case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
									case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
									case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt7].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
									}
									if (bFlag)	continue;

									stBuf.nFCompArray.clear();
									stBuf.nFCompArray.push_back(nFlt1);
									stBuf.nFCompArray.push_back(nFlt2);
									stBuf.nFCompArray.push_back(nFlt3);
									stBuf.nFCompArray.push_back(nFlt4);
									stBuf.nFCompArray.push_back(nFlt5);
									stBuf.nFCompArray.push_back(nFlt6);
									stBuf.nFCompArray.push_back(nFlt7);
									if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
										m_SAStateArray.push_back(stBuf);

									for (nFlt8=nFlt7+1; nFlt8<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt8++)
									{
										if (nMaxGenFault+nMaxBranFault < 8)
											break;

										bFlag=1;
										switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
										{
										case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
										case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
										case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
										case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
										case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
										case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
										case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
										case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
										case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
										case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt8].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
										}
										if (bFlag)	continue;

										stBuf.nFCompArray.clear();
										stBuf.nFCompArray.push_back(nFlt1);
										stBuf.nFCompArray.push_back(nFlt2);
										stBuf.nFCompArray.push_back(nFlt3);
										stBuf.nFCompArray.push_back(nFlt4);
										stBuf.nFCompArray.push_back(nFlt5);
										stBuf.nFCompArray.push_back(nFlt6);
										stBuf.nFCompArray.push_back(nFlt7);
										stBuf.nFCompArray.push_back(nFlt8);
										if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
											m_SAStateArray.push_back(stBuf);

										for (nFlt9=nFlt8+1; nFlt9<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt9++)
										{
											if (nMaxGenFault+nMaxBranFault < 9)
												break;

											bFlag=1;
											switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
											{
											case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
											case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
											case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
											case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
											case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
											case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
											case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
											case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
											case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
											case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt9].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
											}
											if (bFlag)	continue;

											stBuf.nFCompArray.clear();
											stBuf.nFCompArray.push_back(nFlt1);
											stBuf.nFCompArray.push_back(nFlt2);
											stBuf.nFCompArray.push_back(nFlt3);
											stBuf.nFCompArray.push_back(nFlt4);
											stBuf.nFCompArray.push_back(nFlt5);
											stBuf.nFCompArray.push_back(nFlt6);
											stBuf.nFCompArray.push_back(nFlt7);
											stBuf.nFCompArray.push_back(nFlt8);
											stBuf.nFCompArray.push_back(nFlt9);
											if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
												m_SAStateArray.push_back(stBuf);

											for (nFlt10=nFlt9+1; nFlt10<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt10++)
											{
												if (nMaxGenFault+nMaxBranFault < 10)
													break;

												bFlag=1;
												switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
												{
												case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
												case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
												case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
												case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
												case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
												case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
												case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
												case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
												case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
												case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt10].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
												}
												if (bFlag)	continue;

												stBuf.nFCompArray.clear();
												stBuf.nFCompArray.push_back(nFlt1);
												stBuf.nFCompArray.push_back(nFlt2);
												stBuf.nFCompArray.push_back(nFlt3);
												stBuf.nFCompArray.push_back(nFlt4);
												stBuf.nFCompArray.push_back(nFlt5);
												stBuf.nFCompArray.push_back(nFlt6);
												stBuf.nFCompArray.push_back(nFlt7);
												stBuf.nFCompArray.push_back(nFlt8);
												stBuf.nFCompArray.push_back(nFlt9);
												stBuf.nFCompArray.push_back(nFlt10);
												if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
													m_SAStateArray.push_back(stBuf);

												for (nFlt11=nFlt10+1; nFlt11<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt11++)
												{
													if (nMaxGenFault+nMaxBranFault < 11)
														break;

													bFlag=1;
													switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
													{
													case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
													case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
													case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
													case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
													case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
													case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
													case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
													case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
													case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
													case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt11].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
													}
													if (bFlag)	continue;

													stBuf.nFCompArray.clear();
													stBuf.nFCompArray.push_back(nFlt1);
													stBuf.nFCompArray.push_back(nFlt2);
													stBuf.nFCompArray.push_back(nFlt3);
													stBuf.nFCompArray.push_back(nFlt4);
													stBuf.nFCompArray.push_back(nFlt5);
													stBuf.nFCompArray.push_back(nFlt6);
													stBuf.nFCompArray.push_back(nFlt7);
													stBuf.nFCompArray.push_back(nFlt8);
													stBuf.nFCompArray.push_back(nFlt9);
													stBuf.nFCompArray.push_back(nFlt10);
													stBuf.nFCompArray.push_back(nFlt11);
													if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
														m_SAStateArray.push_back(stBuf);

													for (nFlt12=nFlt11+1; nFlt12<pPRBlock->m_nRecordNum[PR_R2STATECOMP]; nFlt12++)
													{
														if (nMaxGenFault+nMaxBranFault < 12)
															break;

														bFlag=1;
														switch (pPRBlock->m_R2StateCompArray[nFlt1].nType)
														{
														case	PR_ACBUS:		if (pPRBlock->m_ACBusArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
														case	PR_ACLINE:		if (pPRBlock->m_ACLineArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
														case	PR_WIND:		if (pPRBlock->m_WindArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
														case	PR_GENERATOR:			if (pPRBlock->m_GeneratorArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
														case	PR_POWERLOAD:		if (pPRBlock->m_PowerLoadArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
														case	PR_HVDC:		if (pPRBlock->m_HVDCArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
														case	PR_TCSC:		if (pPRBlock->m_TCSCArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
														case	PR_UPFC:		if (pPRBlock->m_UPFCArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)			bFlag=0;	break;
														case	PR_CONVERTER:	if (pPRBlock->m_ConverterArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)	bFlag=0;	break;
														case	PR_DCLINE:		if (pPRBlock->m_DCLineArray[pPRBlock->m_R2StateCompArray[nFlt12].nIndex].fFailProb > FLT_MIN)		bFlag=0;	break;
														}
														if (bFlag)	continue;

														stBuf.nFCompArray.clear();
														stBuf.nFCompArray.push_back(nFlt1);
														stBuf.nFCompArray.push_back(nFlt2);
														stBuf.nFCompArray.push_back(nFlt3);
														stBuf.nFCompArray.push_back(nFlt4);
														stBuf.nFCompArray.push_back(nFlt5);
														stBuf.nFCompArray.push_back(nFlt6);
														stBuf.nFCompArray.push_back(nFlt7);
														stBuf.nFCompArray.push_back(nFlt8);
														stBuf.nFCompArray.push_back(nFlt9);
														stBuf.nFCompArray.push_back(nFlt10);
														stBuf.nFCompArray.push_back(nFlt11);
														stBuf.nFCompArray.push_back(nFlt12);
														if (StateAnalyticalCalculateStateProbability(pPRBlock, &stBuf, nMaxGenFault, nMaxBranFault, fMinStateProb))
															m_SAStateArray.push_back(stBuf);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}


		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "状态枚举完成，耗时 %d 毫秒\n", nDur);

		SortPRSampleStateCompSize(m_SAStateArray, 0, (int)m_SAStateArray.size()-1);
		for (i=0; i<(int)m_SAStateArray.size(); i++)
			SortInteger(m_SAStateArray[i].nFCompArray, 0, (int)m_SAStateArray[i].nFCompArray.size()-1);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "状态排序完成，耗时 %d 毫秒\n", nDur);

		SortPRSampleState(m_SAStateArray, 0, (int)m_SAStateArray.size()-1);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "SortPRState完成，状态数=%d，最大故障重数=%d 耗时 %d 毫秒\n", m_SAStateArray.size(), m_SAStateArray[m_SAStateArray.size()-1].nFCompArray.size(), nDur);
		pPRBlock->m_System.nMaxFltDev=(int)m_SAStateArray[m_SAStateArray.size()-1].nFCompArray.size();

		pPRBlock->m_nRecordNum[PR_FSTATE]=0;
		pPRBlock->m_nRecordNum[PR_FSTATEFDEV]=0;
		for (nState=0; nState<(int)m_SAStateArray.size(); nState++)
		{
			if (pPRBlock->m_nRecordNum[PR_FSTATE] >= g_PRMemDBInterface.PRGetTableMax(PR_FSTATE)-1)
			{
				Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATE));
				continue;
			}
			memset(&pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]], 0, sizeof(tagPRFState));
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId=pPRBlock->m_nRecordNum[PR_FSTATE]+1;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nSampleType=PRFState_SamplingMethod_Analytical;

			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum=0;
			for (i=0; i<(int)m_SAStateArray[nState].nFCompArray.size(); i++)
			{
				if (pPRBlock->m_nRecordNum[PR_FSTATEFDEV] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEFDEV)-1)
				{
					memset(&pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]], 0, sizeof(tagPRFStateFDev));
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateId=pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFStateId;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFStateNo=pPRBlock->m_nRecordNum[PR_FSTATE];
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp=pPRBlock->m_R2StateCompArray[m_SAStateArray[nState].nFCompArray[i]].nType;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevIdx=pPRBlock->m_R2StateCompArray[m_SAStateArray[nState].nFCompArray[i]].nIndex;
					pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nDFltTyp=(pPRBlock->m_FStateFDevArray[pPRBlock->m_nRecordNum[PR_FSTATEFDEV]].nFDevTyp == PR_GENERATOR) ? PRFState_FaultType_Trip : PRFState_FaultType_ThreePhase;
					pPRBlock->m_nRecordNum[PR_FSTATEFDEV]++;
				}
				else
					Log(g_lpszLogFile, "        ********** %s 数据库超限\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEFDEV));

				pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nFDevNum++;
			}

			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateProb=m_SAStateArray[nState].fProbability;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].fStateDur=m_SAStateArray[nState].fDuration;
			pPRBlock->m_FStateArray[pPRBlock->m_nRecordNum[PR_FSTATE]].nStateNum=m_SAStateArray[nState].nTotalNumber;
			pPRBlock->m_nRecordNum[PR_FSTATE]++;
		}

		PostSample(pPRBlock);

		return (int)m_SAStateArray.size();
	}
}
