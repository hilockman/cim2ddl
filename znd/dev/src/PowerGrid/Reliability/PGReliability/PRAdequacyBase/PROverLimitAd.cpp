#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <float.h>
#include <math.h>
#include <algorithm>

using namespace std;
#include "PROverLimitAd.h"
#include "../../../../../include/ilog.h"
//extern	const	char*	g_lpszLogFile;
//extern	void	Log(const char* lpszLogFile, char* pformat, ...);
namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	CPROverLimitAd::CPROverLimitAd(void)
	{
	}

	CPROverLimitAd::~CPROverLimitAd(void)
	{
	}

	void CPROverLimitAd::InitAdjustParameter(tagPRBlock* pPRBlock)
	{
		register int	i;

		m_fBusGenAdjustArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]);
		for (i=0; i<(int)m_fBusGenAdjustArray.size(); i++)
			m_fBusGenAdjustArray[i] = 0;
	}

	void CPROverLimitAd::SorOvLmtAdFactorL2H(std::vector<tagOLmtAdjust>& dfArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		int nDn = nDn0;
		int nUp = nUp0;

		double fFactor=dfArray[(nDn0+nUp0)/2].fAdjFactor;
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && dfArray[nDn].fAdjFactor < fFactor)
				++nDn;								 
			while (nUp > nDn0 && dfArray[nUp].fAdjFactor > fFactor)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(dfArray[nDn], dfArray[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SorOvLmtAdFactorL2H(dfArray, nDn0, nUp);

		if (nDn < nUp0 )
			SorOvLmtAdFactorL2H(dfArray, nDn, nUp0);
	}

	void CPROverLimitAd::SorOvLmtAdFactorH2L(std::vector<tagOLmtAdjust>& dfArray, int nDn0, int nUp0)
	{
		if (nUp0 <= nDn0)
			return;

		int nDn = nDn0;
		int nUp = nUp0;

		double fFactor=dfArray[(nDn0+nUp0)/2].fAdjFactor;
		while (nDn <= nUp)
		{
			while (nDn < nUp0 && dfArray[nDn].fAdjFactor > fFactor)
				++nDn;								 
			while (nUp > nDn0 && dfArray[nUp].fAdjFactor < fFactor)
				--nUp;

			if (nDn <= nUp)
			{
				std::swap(dfArray[nDn], dfArray[nUp]);

				++nDn;
				--nUp;
			}
		}

		if (nDn0 < nUp)
			SorOvLmtAdFactorH2L(dfArray, nDn0, nUp);

		if (nDn < nUp0 )
			SorOvLmtAdFactorH2L(dfArray, nDn, nUp0);
	}


	int CPROverLimitAd::AdjustLineOverLimit(tagPRBlock* pPRBlock,
		const unsigned char bGenEOvl,
		const unsigned char bUPFCEOvl,
		const unsigned char bAuxLoadAdjust,
		const unsigned char bUPFCAdjustRC,
		const unsigned char bCheckGenAdjDirection,
		const int nFState,
		const int nLine,
		const double fOlmP,
		double& fLoadCut,
		std::vector<float>& fMatZArray)
	{
		std::vector<tagOLmtAdjust>	sGenAdArray, sLoadAdArray, sUPFCAdArray;

#ifdef	_DEBUG
		log_debug("  ������· %s Խ��ֵ = %f\n", pPRBlock->m_ACLineArray[nLine].szName, fOlmP);
#endif
		FormBranDFactor(pPRBlock, pPRBlock->m_ACLineArray[nLine].nIBus, pPRBlock->m_ACLineArray[nLine].nZBus, pPRBlock->m_ACLineArray[nLine].fX, pPRBlock->m_ACLineArray[nLine].nIsland, fMatZArray);

		// #ifdef	_DEBUG
		// 	Log(g_lpszLogFile, "        �ֲ�����\n");
		// 	for (int nBus=0; nBus<(int)m_BranDFactorArray.size(); nBus++)
		// 		Log(g_lpszLogFile, "            Bus=%s Factor=%g\n", pPRBlock->m_ACBusArray[m_BranDFactorArray[nBus].nBus].szName, m_BranDFactorArray[nBus].fDFactor);
		// #endif

		GetAdjustArray(pPRBlock, bAuxLoadAdjust, bUPFCAdjustRC, sGenAdArray, sLoadAdArray, sUPFCAdArray);
		if (sGenAdArray.empty() && sLoadAdArray.empty())
			return PRFState_AdResult_Unadjustable;
		return AdjustOverLimit(pPRBlock, bGenEOvl, bUPFCEOvl, bCheckGenAdjDirection, nFState, PR_ACLINE, nLine, fOlmP, fLoadCut, sGenAdArray, sLoadAdArray, sUPFCAdArray);
	}

	int CPROverLimitAd::AdjustTranOverLimit(tagPRBlock* pPRBlock,
		const unsigned char bGenEOvl,
		const unsigned char bUPFCEOvl,
		const unsigned char bAuxLoadAdjust,
		const unsigned char bUPFCAdjustRC,
		const unsigned char bCheckGenAdjDirection,
		const int nFState,
		const int nTran,
		const double fOlmP,
		double& fLoadCut,
		std::vector<float>& fMatZArray)
	{
		std::vector<tagOLmtAdjust>	sGenAdArray, sLoadAdArray, sUPFCAdArray;

#ifdef	_DEBUG
		log_debug("  ���ڱ�ѹ�� %s Խ��ֵ = %f\n", pPRBlock->m_WindArray[nTran].szName, fOlmP);
#endif
		FormBranDFactor(pPRBlock, pPRBlock->m_WindArray[nTran].nIBus, pPRBlock->m_WindArray[nTran].nZBus, pPRBlock->m_WindArray[nTran].fX, pPRBlock->m_WindArray[nTran].nIsland, fMatZArray);

		// #ifdef	_DEBUG
		// 	Log(g_lpszLogFile, "        �ֲ�����\n");
		// 	for (int nBus=0; nBus<(int)m_BranDFactorArray.size(); nBus++)
		// 		Log(g_lpszLogFile, "            Bus=%s Factor=%g\n", pPRBlock->m_ACBusArray[m_BranDFactorArray[nBus].nBus].szName, m_BranDFactorArray[nBus].fDFactor);
		// #endif
		GetAdjustArray(pPRBlock, bAuxLoadAdjust, bUPFCAdjustRC, sGenAdArray, sLoadAdArray, sUPFCAdArray);
		if (sGenAdArray.empty() && sLoadAdArray.empty())
			return PRFState_AdResult_Unadjustable;
		return AdjustOverLimit(pPRBlock, bGenEOvl, bUPFCEOvl, bCheckGenAdjDirection, nFState, PR_WIND, nTran, fOlmP, fLoadCut, sGenAdArray, sLoadAdArray, sUPFCAdArray);
	}

	void CPROverLimitAd::FormBranDFactor(tagPRBlock* pPRBlock, const int nBusI, const int nBusJ, const double fX, const int nIsland, std::vector<float> fMatZArray)
	{
		int		nBus;
		tagBusDFactor	dBuf;

		m_BranDFactorArray.clear();
		for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
		{
			if (pPRBlock->m_ACBusArray[nBus].nIsland != nIsland || pPRBlock->m_ACBusArray[nBus].bSlack)
				continue;
			if (pPRBlock->m_ACBusArray[nBus].bOutage)	continue;

			//dBuf.fDFactor=-(fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBus]-fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBus])/fX;
			dBuf.fDFactor=(fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusI+nBus]-fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*nBusJ+nBus])/fX;
			dBuf.nBus=nBus;
			m_BranDFactorArray.push_back(dBuf);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	//	֧·����Ϊ��Խ�ޣ�֧·������������Ϊ����ͬʱԽ�ޣ������������ǰ���������ٳ�����
	//	֧·����Ϊ��Խ�ޣ�֧·������������Ϊ����ͬʱԽ�ޣ������������ǰ����������ӳ�����
	//	�������Ǹ��ɷ���
	//	���������������PΪ��
	//	���������������PΪ��
	//	���ɽ����ʣ���PΪ��
	void CPROverLimitAd::GetAdjustArray(tagPRBlock* pPRBlock, const unsigned char bAuxLoadAdjust, const unsigned char bUPFCAdjustRC, std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray)
	{
		register int	i;
		int				nBus, nUpfc;
		tagOLmtAdjust	adjBuffer;

		sGenAdArray.clear();
		sLoadAdArray.clear();
		sUPFCAdArray.clear();

		//	������Ҫע����ǣ���Ϊ��������Թ���������Ϊע���������Ը�����Ҫȡ����

		memset(&adjBuffer, 0, sizeof(tagOLmtAdjust));
		for (i=0; i<(int)m_BranDFactorArray.size(); i++)	//�����������ɵ�������
		{
			nBus=m_BranDFactorArray[i].nBus;
			if (!pPRBlock->m_ACBusArray[nBus].bSrcBus)
				continue;

			adjBuffer.nBus=nBus;
			adjBuffer.fAdjFactor=m_BranDFactorArray[i].fDFactor;
			adjBuffer.fAvailAscP=pPRBlock->m_ACBusArray[nBus].fMaxGenP-(pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP);		//	������������ռ�
			adjBuffer.fAvailDescP=pPRBlock->m_ACBusArray[nBus].fGenP+pPRBlock->m_ACBusArray[nBus].fAdjGenP-pPRBlock->m_ACBusArray[nBus].fMinGenP;		//	������������ռ�
			if (adjBuffer.fAvailAscP > 1 || adjBuffer.fAvailDescP > 1)
				sGenAdArray.push_back(adjBuffer);
		}

		memset(&adjBuffer, 0, sizeof(tagOLmtAdjust));
		for (i=0; i<(int)m_BranDFactorArray.size(); i++)	//	���ɿɵ�������
		{
			nBus=m_BranDFactorArray[i].nBus;
			if (!bAuxLoadAdjust)
			{
				if (pPRBlock->m_ACBusArray[nBus].bSrcBus)	//	��ֹ�������õ�
					continue;
			}
			if (fabs(pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP) < 1)
				continue;

			adjBuffer.nBus=nBus;
			adjBuffer.fAdjFactor=-m_BranDFactorArray[i].fDFactor;
			adjBuffer.fAvailDescP=pPRBlock->m_ACBusArray[nBus].fLoadP+pPRBlock->m_ACBusArray[nBus].fAdjLoadP+pPRBlock->m_ACBusArray[nBus].fRadP+pPRBlock->m_ACBusArray[nBus].fAdjRadP-pPRBlock->m_ACBusArray[nBus].fMinLoadP;
			if (adjBuffer.fAvailDescP > 1)
				sLoadAdArray.push_back(adjBuffer);
		}

		if (!bUPFCAdjustRC)
		{
			for (nUpfc=0; nUpfc<pPRBlock->m_nRecordNum[PR_UPFC]; nUpfc++)
			{
				if (pPRBlock->m_UPFCArray[nUpfc].bOutage)
					continue;
				if (pPRBlock->m_UPFCArray[nUpfc].nACLine < 0)
					continue;
				if (pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].bOutage)
					continue;

				memset(&adjBuffer, 0, sizeof(tagOLmtAdjust));
				adjBuffer.nDevice = nUpfc;
				adjBuffer.nBus=pPRBlock->m_UPFCArray[nUpfc].nSeriesBus;
				adjBuffer.fAvailAscP =__min(pPRBlock->m_UPFCArray[nUpfc].fCapacity, pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated-(pPRBlock->m_UPFCArray[nUpfc].fPControl+pPRBlock->m_UPFCArray[nUpfc].fLinePse));		//	UPFC�������ռ�
				adjBuffer.fAvailDescP=__min(pPRBlock->m_UPFCArray[nUpfc].fCapacity, pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].fRated+(pPRBlock->m_UPFCArray[nUpfc].fPControl+pPRBlock->m_UPFCArray[nUpfc].fLinePse));		//	UPFC�������ռ�
				if (adjBuffer.fAvailAscP < 1 && adjBuffer.fAvailDescP < 1)
					continue;

				nBus=(pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].nIBus == pPRBlock->m_UPFCArray[nUpfc].nSeriesBus) ? pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].nZBus : pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[nUpfc].nACLine].nIBus;

				for (i=0; i<(int)m_BranDFactorArray.size(); i++)
				{
					if (pPRBlock->m_UPFCArray[nUpfc].nSeriesBus == m_BranDFactorArray[i].nBus)
					{
						adjBuffer.fAdjFactor = m_BranDFactorArray[i].fDFactor;
						break;
					}
				}
				if (pPRBlock->m_ACBusArray[pPRBlock->m_UPFCArray[nUpfc].nSeriesBus].nIsland == pPRBlock->m_ACBusArray[nBus].nIsland)
				{
					for (i=0; i<(int)m_BranDFactorArray.size(); i++)
					{
						if (nBus == m_BranDFactorArray[i].nBus)
						{
							adjBuffer.fAdjFactor -= m_BranDFactorArray[i].fDFactor;
							break;
						}
					}
				}

				if (fabs(adjBuffer.fAdjFactor) > 0.1)
				{
					//#ifdef _DEBUG
					log_debug("    UPFC��%s ����λ��ĸ��=%s������������=%f\n", pPRBlock->m_UPFCArray[nUpfc].szName, pPRBlock->m_UPFCArray[nUpfc].szSeriesBus, adjBuffer.fAdjFactor);
					for (i=0; i<(int)m_BranDFactorArray.size(); i++)
					{
						if (pPRBlock->m_UPFCArray[nUpfc].nSeriesBus == m_BranDFactorArray[i].nBus)
						{
							log_debug("        ����ĸ�ߵ��������� = %f Asc = %f Desc = %f \n", m_BranDFactorArray[i].fDFactor, adjBuffer.fAvailAscP, adjBuffer.fAvailDescP);
							break;
						}
					}
					//#endif // _DEBUG
					sUPFCAdArray.push_back(adjBuffer);
				}
			}
		}
	}

	int CPROverLimitAd::AdjustOverLimit_DecreaseFlow(tagPRBlock* pPRBlock, const unsigned char bGenEOvl, const unsigned char bUPFCEOvl, const unsigned char bCheckGenAdjDirection,
		const int nFState, const unsigned char nOvlDevTyp, const int nOvlDevIdx, const double fOlmP,
		std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray)
	{
		int		nUPFC, nDesGen, nInsGen, nDesLoad;
		double	fConP;	//	������
		double	fAdjP;	//	������
		double	fSens;	//	������
		int		nELResult;

		nELResult=PRFState_AdResult_OverLmt;
		fConP=0;

		//	���������ޣ���������������м�����������ؼ�����������ؼӳ���
		//	���������ޣ���������ؼ�����
		SorOvLmtAdFactorH2L(sGenAdArray, 0, (int)sGenAdArray.size()-1);		//	�Ӵ�С����
		SorOvLmtAdFactorH2L(sLoadAdArray, 0, (int)sLoadAdArray.size()-1);	//	�Ӵ�С����
		SorOvLmtAdFactorH2L(sUPFCAdArray, 0, (int)sUPFCAdArray.size()-1);	//	�Ӵ�С����

#ifdef	_DEBUG
		if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
		{
			log_debug("    DecreaseFlow-------------------------------------------------------------------------------- OlmP = %.2f\n", fOlmP);
			register int	i;
			for (i=0; i<(int)sGenAdArray.size(); i++)
				log_debug("    ����� %s �ֲ�����=%f ��������=(Dir=%d D=%f, I=%f)\n", pPRBlock->m_ACBusArray[sGenAdArray[i].nBus].szName, sGenAdArray[i].fAdjFactor,
				sGenAdArray[i].nAdDirect, sGenAdArray[i].fAvailDescP, sGenAdArray[i].fAvailAscP);
			for (i=0; i<(int)sLoadAdArray.size(); i++)
			{
				if (fabs(sLoadAdArray[i].fAdjFactor) > FLT_MIN && fabs(sLoadAdArray[i].fAvailDescP) > FLT_MIN)
					log_debug("    ���� %s �ֲ�����=%f ��������=%f\n", pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].szName, sLoadAdArray[i].fAdjFactor, sLoadAdArray[i].fAvailDescP);
			}
			for (i=0; i<(int)sUPFCAdArray.size(); i++)
				log_debug("    UPFC %s �ֲ�����=%f ��������=(D=%f, I=%f)\n", pPRBlock->m_ACBusArray[sUPFCAdArray[i].nBus].szName, sUPFCAdArray[i].fAdjFactor, sUPFCAdArray[i].fAvailDescP, sUPFCAdArray[i].fAvailAscP);
		}
#endif

		if (bUPFCEOvl && !sUPFCAdArray.empty())
		{
			//////////////////////////////////////////////////////////////////////////
			nUPFC=0;								//	����أ�������ʹ��·�����½�
			while (nUPFC < (int)sUPFCAdArray.size())
			{
				if (sUPFCAdArray[nUPFC].fAdjFactor < 0.1)
					break;

				fSens=-sUPFCAdArray[nUPFC].fAdjFactor;
				fAdjP=sUPFCAdArray[nUPFC].fAvailDescP;
				if (fAdjP < 0.1)
				{
					nUPFC++;
					continue;
				}

				if (fConP+fAdjP*fSens+fOlmP <= 0)	//	����������Խ����
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP -= fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=-1;			//	����
					sUPFCAdArray[nUPFC].fAvailDescP -= fAdjP;
					sUPFCAdArray[nUPFC].fAvailAscP += fAdjP;

					nELResult=PRFState_AdResult_Normal;
					return nELResult;
					break;
				}
				else
				{
					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP -= fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=-1;	//	����
					sUPFCAdArray[nUPFC].fAvailDescP -= fAdjP;
					sUPFCAdArray[nUPFC].fAvailAscP += fAdjP;

					nUPFC++;
				}
			}

			nUPFC=(int)sUPFCAdArray.size()-1;					//	����أ�������ʹ��·�����½�
			while (nUPFC >= 0)
			{
				if (sUPFCAdArray[nUPFC].fAdjFactor > -0.1)
					break;
				fSens=sUPFCAdArray[nUPFC].fAdjFactor;
				fAdjP=sUPFCAdArray[nUPFC].fAvailAscP;
				if (fAdjP < 0.1)
				{
					nUPFC--;
					continue;
				}

				if (fConP+fAdjP*fSens+fOlmP <= 0)	//	����������Խ����
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP += fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=1;	//	����
					sUPFCAdArray[nUPFC].fAvailAscP -= fAdjP;
					sUPFCAdArray[nUPFC].fAvailDescP += fAdjP;

					nELResult=PRFState_AdResult_Normal;
					return nELResult;
					break;
				}
				else
				{
					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP += fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=1;	//	����
					sUPFCAdArray[nUPFC].fAvailAscP -= fAdjP;
					sUPFCAdArray[nUPFC].fAvailDescP += fAdjP;

					nUPFC--;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		if (bGenEOvl && fConP+fOlmP > 0.01 && !sGenAdArray.empty())	//	û�и���
		{
			nDesGen=0;								//	���������������
			nInsGen=(int)sGenAdArray.size()-1;		//	���������������
			while (nDesGen < (int)sGenAdArray.size() && nInsGen >= 0 && nDesGen < nInsGen)
			{
				if (sGenAdArray[nDesGen].nAdDirect > 0)	//	���ε��ڷ���������ӹ���
				{
					nDesGen++;
					continue;
				}
				if (sGenAdArray[nInsGen].nAdDirect < 0)
				{
					nInsGen--;
					continue;
				}
				if (bCheckGenAdjDirection && m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] > FLT_MIN) //	ȷ������������
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
					{
						log_debug("        DecreaseFlow ���������෴ ��������������� ������ %s �ֲ�����=%f  ��������=(%f, %f) AdjGen=%f\n",
							pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, sGenAdArray[nDesGen].fAdjFactor, sGenAdArray[nDesGen].fAvailAscP, sGenAdArray[nDesGen].fAvailDescP, pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].fAdjGenP);
					}
#endif
					nDesGen++;
					continue;
				}
				if (bCheckGenAdjDirection && m_fBusGenAdjustArray[sGenAdArray[nInsGen].nBus] < -FLT_MIN)	//	ȷ������������
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
					{
						log_debug("        DecreaseFlow ���������෴ ��������������� ������ %s �ֲ�����=%f  ��������=(%f, %f) AdjGen=%f\n",
							pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].szName, sGenAdArray[nInsGen].fAdjFactor, sGenAdArray[nInsGen].fAvailAscP, sGenAdArray[nInsGen].fAvailDescP, pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].fAdjGenP);
					}
#endif
					nInsGen--;
					continue;
				}

				fSens=sGenAdArray[nInsGen].fAdjFactor - sGenAdArray[nDesGen].fAdjFactor;
				if (fabs(fSens) < 0.01)
					break;
				fAdjP=min(sGenAdArray[nDesGen].fAvailDescP, sGenAdArray[nInsGen].fAvailAscP);
				if (fAdjP < 0.1)
				{
					if (sGenAdArray[nInsGen].fAvailAscP > sGenAdArray[nDesGen].fAvailDescP)		//	������ֵ���ڽ�����ֵ���򰴽�����ֵ���õ�����
					{
						nDesGen++;
					}
					else if (sGenAdArray[nInsGen].fAvailAscP < sGenAdArray[nDesGen].fAvailDescP)//	������ֵС�ڽ�����ֵ����������ֵ���õ�����
					{
						nInsGen--;
					}
					else
					{
						nDesGen++;
						nInsGen--;
					}
					continue;
				}


				if (fConP+fAdjP*fSens+fOlmP <= FLT_MIN)	//	����������Խ����
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nInsGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nInsGen].fOprAdjP += fAdjP;
					sGenAdArray[nInsGen].nAdDirect=1;	//	����
					sGenAdArray[nInsGen].fAvailAscP -= fAdjP;
					sGenAdArray[nInsGen].fAvailDescP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nInsGen].nBus] += fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;
					pPRBlock->m_FStateArray[nFState].fELInsGen += (float)fAdjP;

#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
					{
						log_debug("            >Decrease ȫ����----GD[%s] ��������=(%.3f, %.3f) GI[%s] ��������=(%.3f, %.3f)\n",
							pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, sGenAdArray[nDesGen].fAvailAscP, sGenAdArray[nDesGen].fAvailDescP, 
							pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].szName, sGenAdArray[nInsGen].fAvailAscP, sGenAdArray[nInsGen].fAvailDescP);
					}
#endif

					nELResult=PRFState_AdResult_Normal;
					return nELResult;
					break;
				}
				else
				{
					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nInsGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nInsGen].fOprAdjP += fAdjP;
					sGenAdArray[nInsGen].nAdDirect=1;	//	����
					sGenAdArray[nInsGen].fAvailAscP -= fAdjP;
					sGenAdArray[nInsGen].fAvailDescP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nInsGen].nBus] += fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;
					pPRBlock->m_FStateArray[nFState].fELInsGen += (float)fAdjP;

#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
					{
						log_debug("            >Decrease ���ֵ���----GD[%s, %.3f] GI[%s, %.3f] �����������=%.3f ����������=%.3f �ܵ�����=%.3f\n",
							pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, sGenAdArray[nDesGen].fAvailDescP,
							pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].szName, sGenAdArray[nInsGen].fAvailAscP,
							fAdjP, fAdjP*fSens, fConP);
					}
#endif

					if (sGenAdArray[nInsGen].fAvailAscP > sGenAdArray[nDesGen].fAvailDescP)		//	������ֵ���ڽ�����ֵ���򰴽�����ֵ���õ�����
					{
						nDesGen++;
					}
					else if (sGenAdArray[nInsGen].fAvailAscP < sGenAdArray[nDesGen].fAvailDescP)//	������ֵС�ڽ�����ֵ����������ֵ���õ�����
					{
						nInsGen--;
					}
					else
					{
						nInsGen--;
						nDesGen++;
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	�����������ͬʱ�и��ɸ���(��������)
		if (fConP+fOlmP > 0.01 && !sGenAdArray.empty() && !sLoadAdArray.empty())
		{
			nDesGen=nDesLoad=0;
			while (nDesGen < (int)sGenAdArray.size() && nDesLoad < (int)sLoadAdArray.size())
			{
				if (sGenAdArray[nDesGen].nAdDirect > 0)	//	��Ա�Խ���豸�ĵ�����������Ѿ������������������ȷ���������
				{
					nDesGen++;
					continue;
				}
				if (bCheckGenAdjDirection && m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] > FLT_MIN)	//	��������������̣�����������������������ˡ�
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
					{
						log_debug("        DecreaseFlow ���������෴ �����������ͬʱ�и��ɸ��� %s �ֲ�����=%f  ��������=(%f, %f) AdjGen=%f\n",
							pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, sGenAdArray[nDesGen].fAdjFactor, sGenAdArray[nDesGen].fAvailAscP, sGenAdArray[nDesGen].fAvailDescP, pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].fAdjGenP);
					}
#endif
					nDesGen++;
					continue;
				}

				fSens= -sLoadAdArray[nDesLoad].fAdjFactor-sGenAdArray[nDesGen].fAdjFactor;
				if (fabs(fSens) < 0.01)
					break;

				fAdjP=min(sGenAdArray[nDesGen].fAvailDescP, sLoadAdArray[nDesLoad].fAvailDescP);	//	����С������
				if (fAdjP < 0.1)
				{
					if (sLoadAdArray[nDesLoad].fAvailDescP > sGenAdArray[nDesGen].fAvailDescP)		//	���ɵ����������ڵ��ڷ������������
					{
						nDesGen++;
					}
					else if (sLoadAdArray[nDesLoad].fAvailDescP < sGenAdArray[nDesGen].fAvailDescP)	//	���ɵ�������С�ڷ������������
					{
						nDesLoad++;
					}
					else
					{
						nDesGen++;
						nDesLoad++;
					}
					continue;
				}

				if (fConP+fAdjP*fSens+fOlmP <= FLT_MIN)	//	����������Խ����
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        ---->Decrease ȫ����----GD[%s]-LD[%s] ����=%f �ܵ�����=%f\n", pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].szName, fAdjP, fConP);
#endif

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_debug("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_POWERLOAD;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sLoadAdArray[nDesLoad].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sLoadAdArray[nDesLoad].fOprAdjP -= fAdjP;
					sLoadAdArray[nDesLoad].fAvailDescP -= fAdjP;

					if (nFState >= 0)
					{
						pPRBlock->m_FStateArray[nFState].bELCutLoad=1;
						pPRBlock->m_FStateArray[nFState].fELCutLoad += (float)fAdjP;
						pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;

						if (pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone].fCutLoadP += (float)fAdjP;
					}

					nELResult=PRFState_AdResult_Normal;
					return nELResult;
					break;
				}
				else
				{
					fConP += fAdjP*fSens;
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        ---->Decrease ���ֵ���----GD[%s]-LD[%s] ����=%f �ܵ�����=%f\n", pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].szName, fAdjP, fConP);
#endif

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_POWERLOAD;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sLoadAdArray[nDesLoad].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sLoadAdArray[nDesLoad].fOprAdjP -= fAdjP;
					sLoadAdArray[nDesLoad].fAvailDescP -= fAdjP;

					if (nFState >= 0)
					{
						pPRBlock->m_FStateArray[nFState].bELCutLoad=1;
						pPRBlock->m_FStateArray[nFState].fELCutLoad += (float)fAdjP;
						pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;

						if (pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone].fCutLoadP += (float)fAdjP;
					}

					if (sLoadAdArray[nDesLoad].fAvailDescP > sGenAdArray[nDesGen].fAvailDescP)		//	���ɵ����������ڵ��ڷ������������
					{
						nDesGen++;
					}
					else if (sLoadAdArray[nDesLoad].fAvailDescP < sGenAdArray[nDesGen].fAvailDescP)	//	���ɵ�������С�ڷ������������
					{
						nDesLoad++;
					}
					else
					{
						nDesGen++;
						nDesLoad++;
					}
				}
			}
		}

		return nELResult;
	}

	//	֧·��������Խ�ޣ���Ҫ�����������ӳ���
	int CPROverLimitAd::AdjustOverLimit_IncreaseFlow(tagPRBlock* pPRBlock, const unsigned char bGenEOvl, const unsigned char bUPFCEOvl, const unsigned char bCheckGenAdjDirection,
		const int nFState, const unsigned char nOvlDevTyp, const int nOvlDevIdx, const double fOlmP,
		std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray)
	{
		int		nUPFC, nDesGen, nInsGen, nDesLoad;
		double	fConP;	//	������
		double	fAdjP;	//	������
		double	fSens;	//	������
		int		nELResult;

		nELResult=PRFState_AdResult_OverLmt;
		fConP=0;

		//	���������ޣ���������������м�����������ؼ�����������ؼӳ���
		//	���������ޣ����ɸ���ؼ�����
		SorOvLmtAdFactorL2H(sGenAdArray, 0, (int)sGenAdArray.size()-1);		//	��С��������
		SorOvLmtAdFactorL2H(sLoadAdArray, 0, (int)sLoadAdArray.size()-1);	//	�Ӵ�С����
		SorOvLmtAdFactorL2H(sUPFCAdArray, 0, (int)sUPFCAdArray.size()-1);	//	��С��������

#ifdef	_DEBUG
		if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
		{
			log_debug("    IncreaseFlow ����������---------------------------------------------------------------------- OlmP = %.2f\n", fOlmP);
			register int	i;
			for (i=0; i<(int)sGenAdArray.size(); i++)
				log_debug("    ����� %s �ֲ�����=%f ��������=(D=%f, I=%f)\n", pPRBlock->m_ACBusArray[sGenAdArray[i].nBus].szName, sGenAdArray[i].fAdjFactor, sGenAdArray[i].fAvailDescP, sGenAdArray[i].fAvailAscP);
			for (i=0; i<(int)sLoadAdArray.size(); i++)
			{
				if (fabs(sLoadAdArray[i].fAdjFactor) > FLT_MIN && fabs(sLoadAdArray[i].fAvailDescP) > FLT_MIN)
					log_debug("    ���� %s �ֲ�����=%f ��������=%f\n", pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].szName, sLoadAdArray[i].fAdjFactor, sLoadAdArray[i].fAvailDescP);
			}
			for (i=0; i<(int)sUPFCAdArray.size(); i++)
				log_debug("    UPFC %s �ֲ�����=%f ��������=(D=%f, I=%f)\n", pPRBlock->m_ACBusArray[sUPFCAdArray[i].nBus].szName, sUPFCAdArray[i].fAdjFactor, sUPFCAdArray[i].fAvailDescP, sUPFCAdArray[i].fAvailAscP);
		}
#endif

		if (bUPFCEOvl && !sUPFCAdArray.empty())
		{
			nUPFC=0;								//	����أ�������
			while (nUPFC < (int)sUPFCAdArray.size())
			{
				if (sUPFCAdArray[nUPFC].fAdjFactor < 0.1)
					break;

				fSens=sUPFCAdArray[nUPFC].fAdjFactor;
				fAdjP=sUPFCAdArray[nUPFC].fAvailAscP;
				if (fAdjP < 0.1)
				{
					nUPFC++;
					continue;
				}

				if (fConP+fAdjP*fSens+fOlmP >= 0)	//	����������Խ����
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP += fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=1;
					sUPFCAdArray[nUPFC].fAvailDescP += fAdjP;
					sUPFCAdArray[nUPFC].fAvailAscP -= fAdjP;

					nELResult=PRFState_AdResult_Normal;
					return nELResult;
					break;
				}
				else
				{
					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP += fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=1;
					sUPFCAdArray[nUPFC].fAvailDescP += fAdjP;
					sUPFCAdArray[nUPFC].fAvailAscP -= fAdjP;

					nUPFC++;
				}
			}

			nUPFC=(int)sUPFCAdArray.size()-1;								//	����أ�������
			while (nUPFC >= 0)
			{
				if (sUPFCAdArray[nUPFC].fAdjFactor > -0.1)
					break;
				fSens=-sUPFCAdArray[nUPFC].fAdjFactor;
				fAdjP=sUPFCAdArray[nUPFC].fAvailDescP;
				if (fAdjP < 0.1)
				{
					nUPFC--;
					continue;
				}

				if (fConP+fAdjP*fSens+fOlmP >= 0)	//	����������Խ����
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP -= fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=-1;
					sUPFCAdArray[nUPFC].fAvailAscP += fAdjP;
					sUPFCAdArray[nUPFC].fAvailDescP -= fAdjP;

					nELResult=PRFState_AdResult_Normal;
					return nELResult;
					break;
				}
				else
				{
					fConP += fAdjP*fSens;
					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_UPFC;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sUPFCAdArray[nUPFC].nDevice;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sUPFCAdArray[nUPFC].fOprAdjP -= fAdjP;
					sUPFCAdArray[nUPFC].nAdDirect=-1;
					sUPFCAdArray[nUPFC].fAvailAscP += fAdjP;
					sUPFCAdArray[nUPFC].fAvailDescP -= fAdjP;

					nUPFC--;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		if (bGenEOvl && fOlmP+fConP < -0.01 && !sGenAdArray.empty())
		{
			nDesGen=0;								//	���������������
			nInsGen=(int)sGenAdArray.size()-1;		//	���������������
			while (nDesGen < (int)sGenAdArray.size() && nInsGen >= 0 && nDesGen < nInsGen)
			{
				if (sGenAdArray[nDesGen].nAdDirect > 0)	//	��������ε���Ϊ������
				{
					nDesGen++;
					continue;
				}
				if (sGenAdArray[nInsGen].nAdDirect < 0)
				{
					nInsGen--;
					continue;
				}
				if (bCheckGenAdjDirection && m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] > FLT_MIN)
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        IncreaseFlow ���������෴ ��������������� ������ %s �ֲ�����=%f  ��������=(%f, %f) AdjGen=%f\n",
						pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, sGenAdArray[nDesGen].fAdjFactor, sGenAdArray[nDesGen].fAvailAscP, sGenAdArray[nDesGen].fAvailDescP, pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].fAdjGenP);
#endif
					nDesGen++;
					continue;
				}
				if (bCheckGenAdjDirection && m_fBusGenAdjustArray[sGenAdArray[nInsGen].nBus] < -FLT_MIN)
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        IncreaseFlow ���������෴ ��������������� ������ %s �ֲ�����=%f  ��������=(%f, %f) AdjGen=%f\n",
						pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].szName, sGenAdArray[nInsGen].fAdjFactor, sGenAdArray[nInsGen].fAvailAscP, sGenAdArray[nInsGen].fAvailDescP, pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].fAdjGenP);
#endif
					nInsGen--;
					continue;
				}

				fSens=sGenAdArray[nInsGen].fAdjFactor - sGenAdArray[nDesGen].fAdjFactor;
				if (fSens <= 0.01)
					break;

				fAdjP=min(sGenAdArray[nDesGen].fAvailDescP, sGenAdArray[nInsGen].fAvailAscP);
				if (fAdjP < 0.1)
				{
					if (sGenAdArray[nInsGen].fAvailAscP > sGenAdArray[nDesGen].fAvailDescP)		//	������ֵ���ڽ�����ֵ���򰴽�����ֵ���õ�����
					{
						nDesGen++;
					}
					else if (sGenAdArray[nInsGen].fAvailAscP < sGenAdArray[nDesGen].fAvailDescP)//	������ֵС�ڽ�����ֵ����������ֵ���õ�����
					{
						nInsGen--;
					}
					else
					{
						nDesGen++;
						nInsGen--;
					}
					continue;
				}

				if (fConP+fAdjP*fSens+fOlmP >= FLT_MIN)	//	����������������Ҫ��
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        ----<Increase ȫ����----GD[%s]-GI[%s] ������=%f �Ѿ�������=%f Խ��ֵ=%f\n",
						pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].szName, fAdjP, fConP, fOlmP);
#endif

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nInsGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nInsGen].fOprAdjP += fAdjP;
					sGenAdArray[nInsGen].nAdDirect=1;	//	����
					sGenAdArray[nInsGen].fAvailAscP -= fAdjP;
					sGenAdArray[nInsGen].fAvailDescP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nInsGen].nBus] += fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;
					pPRBlock->m_FStateArray[nFState].fELInsGen += (float)fAdjP;

					nELResult=PRFState_AdResult_Normal;
					break;
				}
				else
				{
					fConP += fAdjP*fSens;	//	fConP ��Ҫ���޵��� fAdjP ��Ҫ��������
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        ----<Increase ���ֵ���----GD[%s]-GI[%s] ������=%f �Ѿ�������=%f Խ��ֵ=%f\n",
						pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, pPRBlock->m_ACBusArray[sGenAdArray[nInsGen].nBus].szName, fAdjP, fConP, fOlmP);
#endif

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nInsGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nInsGen].fOprAdjP += fAdjP;
					sGenAdArray[nInsGen].nAdDirect=1;	//	����
					sGenAdArray[nInsGen].fAvailAscP -= fAdjP;
					sGenAdArray[nInsGen].fAvailDescP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nInsGen].nBus] += fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;
					pPRBlock->m_FStateArray[nFState].fELInsGen += (float)fAdjP;

					if (sGenAdArray[nInsGen].fAvailAscP > sGenAdArray[nDesGen].fAvailDescP)	//	������ֵ���ڽ�����ֵ���򰴽�����ֵ���õ�����
					{
						nDesGen++;
					}
					else if (sGenAdArray[nInsGen].fAvailAscP < sGenAdArray[nDesGen].fAvailDescP)	//	������ֵС�ڽ�����ֵ����������ֵ���õ�����
					{
						nInsGen--;
					}
					else
					{
						nDesGen++;
						nInsGen--;
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	�����������ͬʱ�и��ɸ���(��������)
		if (fOlmP+fConP < -0.01 && !sGenAdArray.empty() && !sLoadAdArray.empty())
		{
			nDesGen=nDesLoad=0;
			while (nDesGen < (int)sGenAdArray.size() && nDesLoad < (int)sLoadAdArray.size())
			{
				if (sGenAdArray[nDesGen].nAdDirect > 0)	//	��������ε���Ϊ������
				{
					nDesGen++;
					continue;
				}
				if (bCheckGenAdjDirection && m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] > FLT_MIN)
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        IncreaseFlow ���������෴ �����������ͬʱ�и��ɸ��� %s �ֲ�����=%f  ��������=(%f, %f) AdjGen=%f\n",
						pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, sGenAdArray[nDesGen].fAdjFactor, sGenAdArray[nDesGen].fAvailAscP, sGenAdArray[nDesGen].fAvailDescP, pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].fAdjGenP);
#endif
					nDesGen++;
					continue;
				}

				fSens=-sGenAdArray[nDesGen].fAdjFactor-sLoadAdArray[nDesLoad].fAdjFactor;
				if (fSens <= 0.01)
					break;

				fAdjP=min(sGenAdArray[nDesGen].fAvailDescP, sLoadAdArray[nDesLoad].fAvailDescP);				//	����С������
				if (fAdjP < 0.1)
				{
					if (sLoadAdArray[nDesLoad].fAvailDescP > sGenAdArray[nDesGen].fAvailDescP)		//	���ɵ����������ڵ��ڷ������������
					{
						nDesGen++;
					}
					else if (sLoadAdArray[nDesLoad].fAvailDescP < sGenAdArray[nDesGen].fAvailDescP)	//	���ɵ�������С�ڷ������������
					{
						nDesLoad++;
					}
					else
					{
						nDesGen++;
						nDesLoad++;
					}
					continue;
				}

				if (fConP+fAdjP*fSens+fOlmP >= FLT_MIN)	//	����������Խ����
				{
					fAdjP=-(fOlmP+fConP)/fSens;
					if (fAdjP < 0.001)
						fAdjP=0;

					fConP += fAdjP*fSens;
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        ----<Increase ȫ����----GD[%s]-LD[%s] ������=%f �Ѿ�������=%f Խ��ֵ=%f\n",
						pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].szName, fAdjP, fConP, fOlmP);
#endif

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_POWERLOAD;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sLoadAdArray[nDesLoad].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sLoadAdArray[nDesLoad].fOprAdjP -= fAdjP;
					sLoadAdArray[nDesLoad].fAvailDescP -= fAdjP;

					if (nFState >= 0)
					{
						pPRBlock->m_FStateArray[nFState].bELCutLoad=1;
						pPRBlock->m_FStateArray[nFState].fELCutLoad += (float)fAdjP;
						pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;

						if (pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone].fCutLoadP += (float)fAdjP;
					}

					nELResult=PRFState_AdResult_Normal;

					break;
				}
				else
				{
					fConP += fAdjP*fSens;
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("        ----<Increase ���ֵ���----GD[%s]-LD[%s] ������=%f �Ѿ�������=%f Խ��ֵ=%f\n",
						pPRBlock->m_ACBusArray[sGenAdArray[nDesGen].nBus].szName, pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].szName, fAdjP, fConP, fOlmP);
#endif

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_GENERATOR;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sGenAdArray[nDesGen].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sGenAdArray[nDesGen].fOprAdjP -= fAdjP;
					sGenAdArray[nDesGen].nAdDirect=-1;	//	����
					sGenAdArray[nDesGen].fAvailDescP -= fAdjP;
					sGenAdArray[nDesGen].fAvailAscP += fAdjP;

					m_fBusGenAdjustArray[sGenAdArray[nDesGen].nBus] -= fAdjP;	//	��¼ĸ�����޵���״̬����ֹ���޵�����

					if (pPRBlock->m_nRecordNum[PR_FSTATEOVLAD] < g_PRMemDBInterface.PRGetTableMax(PR_FSTATEOVLAD)-1)
					{
						memset(&pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]], 0, sizeof(tagPRFStateOvlAd));
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateId=pPRBlock->m_FStateArray[nFState].nFStateId;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nFStateNo=nFState;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevTyp=nOvlDevTyp;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nOvlDevIdx=nOvlDevIdx;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].fAdValue=(float)-fAdjP;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevTyp=PR_POWERLOAD;
						pPRBlock->m_FStateOvlAdArray[pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]].nAdjDevIdx=sLoadAdArray[nDesLoad].nBus;
						pPRBlock->m_nRecordNum[PR_FSTATEOVLAD]++;
					}
					else
						log_error("        ********** %s ���ݿⳬ��\n", g_PRMemDBInterface.PRGetTableDesp(PR_FSTATEOVLAD));

					sLoadAdArray[nDesLoad].fOprAdjP -= fAdjP;
					sLoadAdArray[nDesLoad].fAvailDescP -= fAdjP;

					if (nFState >= 0)
					{
						pPRBlock->m_FStateArray[nFState].bELCutLoad=1;
						pPRBlock->m_FStateArray[nFState].fELCutLoad += (float)fAdjP;
						pPRBlock->m_FStateArray[nFState].fELCutGen += (float)fAdjP;

						if (pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone >= 0)	pPRBlock->m_ZoneArray[pPRBlock->m_ACBusArray[sLoadAdArray[nDesLoad].nBus].nZone].fCutLoadP += (float)fAdjP;
					}

					if (sLoadAdArray[nDesLoad].fAvailDescP > sGenAdArray[nDesGen].fAvailDescP)		//	���ɵ����������ڵ��ڷ������������
					{
						nDesGen++;
					}
					else if (sLoadAdArray[nDesLoad].fAvailDescP < sGenAdArray[nDesGen].fAvailDescP)//	���ɵ�������С�ڷ������������
					{
						nDesLoad++;
					}
					else
					{
						nDesGen++;
						nDesLoad++;
					}
				}
			}
		}

		return nELResult;
	}

	int CPROverLimitAd::AdjustOverLimit(tagPRBlock* pPRBlock, const unsigned char bGenEOvl, const unsigned char bUPFCEOvl, const unsigned char bCheckGenAdjDirection,
		const int nFState, const unsigned char nOvlDevTyp, const int nOvlDevIdx, const double fOlmP,
		double& fLoadCut, std::vector<tagOLmtAdjust>& sGenAdArray, std::vector<tagOLmtAdjust>& sLoadAdArray, std::vector<tagOLmtAdjust>& sUPFCAdArray)
	{
		register int	i;
		int		nELResult=PRFState_AdResult_OverLmt;
		if (fOlmP > 0)															//	��·����Խ�ޣ���Ҫ��������ط�������������Ӹ���ط������������Ҫ��С����ظ��ɹ���
			nELResult = AdjustOverLimit_DecreaseFlow(pPRBlock, bGenEOvl, bUPFCEOvl, bCheckGenAdjDirection, nFState, nOvlDevTyp, nOvlDevIdx, fOlmP, sGenAdArray, sLoadAdArray, sUPFCAdArray);
		else
			nELResult = AdjustOverLimit_IncreaseFlow(pPRBlock, bGenEOvl, bUPFCEOvl, bCheckGenAdjDirection, nFState, nOvlDevTyp, nOvlDevIdx, fOlmP, sGenAdArray, sLoadAdArray, sUPFCAdArray);

#ifdef	_DEBUG
		if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
		{
			log_debug("            |���յ������------------------------------------------------------------------------------|\n");
			for (i=0; i<(int)sGenAdArray.size(); i++)
			{
				if (fabs(sGenAdArray[i].fOprAdjP) < FLT_MIN)
					continue;
				log_debug("                ����� %s �ֲ�����=%f �����仯��=%f\n", pPRBlock->m_ACBusArray[sGenAdArray[i].nBus].szName, sGenAdArray[i].fAdjFactor, sGenAdArray[i].fOprAdjP);
			}
			for (i=0; i<(int)sLoadAdArray.size(); i++)
			{
				if (fabs(sLoadAdArray[i].fOprAdjP) < FLT_MIN)
					continue;
				log_debug("                ���� %s �ֲ�����=%f ���ʱ仯��=%f\n", pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].szName, sLoadAdArray[i].fAdjFactor, sLoadAdArray[i].fOprAdjP);
			}
			for (i=0; i<(int)sUPFCAdArray.size(); i++)
			{
				if (fabs(sUPFCAdArray[i].fOprAdjP) < FLT_MIN)
					continue;
				log_debug("                UPFC %s �ֲ�����=%f �����仯��=%f\n", pPRBlock->m_ACBusArray[sUPFCAdArray[i].nBus].szName, sUPFCAdArray[i].fAdjFactor, sUPFCAdArray[i].fOprAdjP);
			}
			log_debug("            |------------------------------------------------------------------------------------------|\n");
		}
#endif

		for (i=0; i<(int)sGenAdArray.size(); i++)
		{
			if (fabs(sGenAdArray[i].fOprAdjP) < FLT_MIN)
				continue;

			pPRBlock->m_ACBusArray[sGenAdArray[i].nBus].fAdjGenP += sGenAdArray[i].fOprAdjP;
		}
		for (i=0; i<(int)sLoadAdArray.size(); i++)
		{
			if (fabs(sLoadAdArray[i].fOprAdjP) < FLT_MIN)
				continue;

			if (pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].bRingBound)
			{
				if (sLoadAdArray[i].fOprAdjP + pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fRadP+pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fAdjRadP > 0)
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("                ���� %s ������������=%.3f ����������=0\n", pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].szName, sLoadAdArray[i].fOprAdjP);
#endif
					pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fAdjRadP += sLoadAdArray[i].fOprAdjP;
				}
				else
				{
#ifdef	_DEBUG
					if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
						log_debug("                ���� %s ������������=%.3f ����������=%.3f\n", pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].szName, -pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fRadP, sLoadAdArray[i].fOprAdjP + pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fRadP + pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fAdjRadP);
#endif
					pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fAdjLoadP += (sLoadAdArray[i].fOprAdjP+pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fRadP+pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fAdjRadP);
					pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fAdjRadP=-pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fRadP;
				}
			}
			else
			{
#ifdef	_DEBUG
				if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
					log_debug("                ���� %s ������=%.3f\n", pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].szName, sLoadAdArray[i].fOprAdjP);
#endif
				pPRBlock->m_ACBusArray[sLoadAdArray[i].nBus].fAdjLoadP += sLoadAdArray[i].fOprAdjP;
			}

			fLoadCut += sLoadAdArray[i].fOprAdjP;
		}

		for (i=0; i<(int)sUPFCAdArray.size(); i++)
		{
			if (fabs(sUPFCAdArray[i].fOprAdjP) < FLT_MIN)
				continue;

			pPRBlock->m_UPFCArray[sUPFCAdArray[i].nDevice].fPControl += sUPFCAdArray[i].fOprAdjP;
#ifdef	_DEBUG
			if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
				log_debug("                UPFC %s ������=%.3f\n", pPRBlock->m_UPFCArray[sUPFCAdArray[i].nDevice].szName, sUPFCAdArray[i].fOprAdjP);
#endif
		}
#ifdef	_DEBUG
		if (nOvlDevTyp == PR_ACLINE && _stricmp(pPRBlock->m_ACLineArray[nOvlDevIdx].szName, "���¹�__230-����ׯ__230@1") == 0)
			log_debug("            |------------------------------------------------------------------------------------------|\n");
#endif

		return nELResult;
	}
}
