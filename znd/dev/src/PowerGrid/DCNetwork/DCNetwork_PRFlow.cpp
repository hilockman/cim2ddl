#include "DCNetwork.h"
#include "../../../include/ilog.h"
//extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	DCNetwork
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;
	
	int	CDCNetwork::PRDCNetwork_ReadData(tagPRBlock* pPRBlock, const unsigned char nUPFCControlMode, const int nIsland)
	{
		int		nCol, nDev;
		double	fX, fTotalLoad, fTotalGen, fTotalDCP;
		std::vector<float>	fBusLossArray;

		fBusLossArray.resize(pPRBlock->m_nRecordNum[PR_ACBUS]);
		for (nDev=0; nDev<(int)fBusLossArray.size(); nDev++)
			fBusLossArray[nDev]=0;
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].nIRadial != 0 || pPRBlock->m_ACLineArray[nDev].nZRadial != 0)
				continue;
			if (pPRBlock->m_ACLineArray[nDev].bOutage || pPRBlock->m_ACLineArray[nDev].nIsland != nIsland)
				continue;
			//if (pPRBlock->m_ACLineArray[nDev].fLossP < fabs(pPRBlock->m_ACLineArray[nDev].fRtPi)/20 && pPRBlock->m_ACLineArray[nDev].fLossP < fabs(pPRBlock->m_ACLineArray[nDev].fRtPz)/20)
			{
				fBusLossArray[pPRBlock->m_ACLineArray[nDev].nIBus] += pPRBlock->m_ACLineArray[nDev].fLossP/2;
				fBusLossArray[pPRBlock->m_ACLineArray[nDev].nZBus] += pPRBlock->m_ACLineArray[nDev].fLossP/2;
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage)
				continue;
			//if (pPRBlock->m_WindArray[nDev].fLossP < fabs(pPRBlock->m_WindArray[nDev].fRtPi)/20 && pPRBlock->m_WindArray[nDev].fLossP < fabs(pPRBlock->m_WindArray[nDev].fRtPz)/20)
			{
				fBusLossArray[pPRBlock->m_WindArray[nDev].nIBus] += pPRBlock->m_WindArray[nDev].fLossP/2;
				fBusLossArray[pPRBlock->m_WindArray[nDev].nZBus] += pPRBlock->m_WindArray[nDev].fLossP/2;
			}
		}

		fTotalLoad = fTotalGen = fTotalDCP = 0;
		//	��������
		m_nMaxBusNumber=0;
		m_nNumBus=0;

		m_nNumBra=0;
		m_nNumGen=0;
		m_nNumLoad=0;
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].nIRadial != 0 || pPRBlock->m_ACLineArray[nDev].nZRadial != 0)
				continue;
			if (pPRBlock->m_ACLineArray[nDev].bOutage)	//	��·ͣ��
				continue;

			if (nUPFCControlMode == UPFC_MODE_UPFC && pPRBlock->m_ACLineArray[nDev].nUPFCIndex >= 0)
			{
				if (pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nIBus].nIsland == nIsland)
					m_nNumGen++;
				if (pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nZBus].nIsland == nIsland)
					m_nNumGen++;
			}
			else
			{
				if (pPRBlock->m_ACLineArray[nDev].nIsland == nIsland)
				{
					m_nNumBra++;

					if (m_nMaxBusNumber < pPRBlock->m_ACLineArray[nDev].nIBus)	m_nMaxBusNumber=pPRBlock->m_ACLineArray[nDev].nIBus;
					if (m_nMaxBusNumber < pPRBlock->m_ACLineArray[nDev].nZBus)	m_nMaxBusNumber=pPRBlock->m_ACLineArray[nDev].nZBus;
				}
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].nIRadial != 0 || pPRBlock->m_WindArray[nDev].nZRadial != 0)
				continue;
			if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage)
				continue;
			m_nNumBra++;

			if (m_nMaxBusNumber < pPRBlock->m_WindArray[nDev].nIBus)	m_nMaxBusNumber=pPRBlock->m_WindArray[nDev].nIBus;
			if (m_nMaxBusNumber < pPRBlock->m_WindArray[nDev].nZBus)	m_nMaxBusNumber=pPRBlock->m_WindArray[nDev].nZBus;
		}

		for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
		{
			if (pPRBlock->m_ACBusArray[nDev].bOutage)
				continue;
			if (pPRBlock->m_ACBusArray[nDev].nRadial != 0)
				continue;
			if (pPRBlock->m_ACBusArray[nDev].nIsland != nIsland)
				continue;

			if (fabs(pPRBlock->m_ACBusArray[nDev].fGenP+pPRBlock->m_ACBusArray[nDev].fAdjGenP) > FLT_MIN)
				m_nNumGen++;
			if (fabs(pPRBlock->m_ACBusArray[nDev].fLoadP+fBusLossArray[nDev]+pPRBlock->m_ACBusArray[nDev].fAdjLoadP+pPRBlock->m_ACBusArray[nDev].fRadP+pPRBlock->m_ACBusArray[nDev].fAdjRadP) > FLT_MIN)
				m_nNumLoad++;
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			if (pPRBlock->m_HVDCArray[nDev].bOutage)
				continue;
			if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nIsland == nIsland && pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nRadial == 0)
			{
				if (fabs(pPRBlock->m_HVDCArray[nDev].fPr) > FLT_MIN)
					m_nNumLoad++;
			}
			if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nIsland == nIsland && pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nRadial == 0)
			{
				if (fabs(pPRBlock->m_HVDCArray[nDev].fPi) > FLT_MIN)
					m_nNumGen++;
			}
		}

// 		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_CONVERTER]; nDev++)
// 		{
// 			if (pPRBlock->m_ConverterArray[nDev].bOutage)
// 				continue;
// 			if (pPRBlock->m_ConverterArray[nDev].nACBus <= 0)
// 				continue;
// 			if (fabs(pPRBlock->m_ConverterArray[nDev].fConverterPower) < FLT_MIN)
// 				continue;
// 			if (pPRBlock->m_ACBusArray[pPRBlock->m_ConverterArray[nDev].nACBus].nIsland == nIsland && pPRBlock->m_ACBusArray[pPRBlock->m_ConverterArray[nDev].nACBus].nRadial == 0)
// 			{
// 				if (pPRBlock->m_ConverterArray[nDev].nType == PRConverter_Type_Rectifier)	//	����
// 					m_nNumLoad++;
// 				else
// 					m_nNumGen++;
// 			}
// 		}
		AllocDataBuffer(m_nMaxBusNumber);

		m_nNumBra=0;
		m_nNumGen=0;
		m_nNumLoad=0;
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].nIRadial != 0 || pPRBlock->m_ACLineArray[nDev].nZRadial != 0)
				continue;
			if (pPRBlock->m_ACLineArray[nDev].bOutage)
				continue;

			fX = pPRBlock->m_ACLineArray[nDev].fX;
			if (pPRBlock->m_ACLineArray[nDev].nTCSCIndex >= 0)
			{
				if (!pPRBlock->m_TCSCArray[pPRBlock->m_ACLineArray[nDev].nTCSCIndex].bOutage)
					fX += pPRBlock->m_TCSCArray[pPRBlock->m_ACLineArray[nDev].nTCSCIndex].fX;
			}

			if (nUPFCControlMode == UPFC_MODE_UPFC && pPRBlock->m_ACLineArray[nDev].nUPFCIndex >= 0)
			{
				if (pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nIBus].nIsland == nIsland)
				{
					m_fGenArray[3*m_nNumGen+0]=pPRBlock->m_ACLineArray[nDev].nIBus;
					if (pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].nSeriesBus == pPRBlock->m_ACLineArray[nDev].nIBus)	//	I���ǰ�װλ�ã���˴������Pȡ��
						m_fGenArray[3*m_nNumGen+1]= (pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse)/pPRBlock->m_System.fMvaBase;
					else
						m_fGenArray[3*m_nNumGen+1]=-(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse)/pPRBlock->m_System.fMvaBase;
					m_fGenArray[3*m_nNumGen+2]=(double)pPRBlock->m_ACLineArray[nDev].nUPFCIndex;

					fTotalGen += m_fGenArray[3*m_nNumGen+1];
					m_nNumGen++;
				}
				if (pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nZBus].nIsland == nIsland)
				{
					m_fGenArray[3*m_nNumGen+0]=pPRBlock->m_ACLineArray[nDev].nZBus;
					if (pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].nSeriesBus == pPRBlock->m_ACLineArray[nDev].nIBus)
						m_fGenArray[3*m_nNumGen+1]=-(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse)/pPRBlock->m_System.fMvaBase;
					else
						m_fGenArray[3*m_nNumGen+1]= (pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse)/pPRBlock->m_System.fMvaBase;
					m_fGenArray[3*m_nNumGen+2]=(double)pPRBlock->m_ACLineArray[nDev].nUPFCIndex;

					fTotalGen += m_fGenArray[3*m_nNumGen+1];
					m_nNumGen++;
				}
			}
			else
			{
				if (pPRBlock->m_ACLineArray[nDev].nIsland == nIsland)
				{
					nCol=0;
					m_fZArray[4*m_nNumBra+nCol++]=(double)pPRBlock->m_ACLineArray[nDev].nIBus;
					m_fZArray[4*m_nNumBra+nCol++]=(double)pPRBlock->m_ACLineArray[nDev].nZBus;
					m_fZArray[4*m_nNumBra+nCol++]=fX;
					m_fZArray[4*m_nNumBra+nCol++]=(double)nDev;
					m_nNumBra++;
				}
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].nIRadial != 0 || pPRBlock->m_WindArray[nDev].nZRadial != 0)
				continue;
			if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage)
				continue;

			nCol=0;
			m_fZArray[4*m_nNumBra+nCol++]=(double)pPRBlock->m_WindArray[nDev].nIBus;
			m_fZArray[4*m_nNumBra+nCol++]=-(double)pPRBlock->m_WindArray[nDev].nZBus;
			m_fZArray[4*m_nNumBra+nCol++]=pPRBlock->m_WindArray[nDev].fX;
			m_fZArray[4*m_nNumBra+nCol++]=(double)nDev;
			m_nNumBra++;
		}

		m_nSlackBus=0;
		for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
		{
			if (pPRBlock->m_ACBusArray[nDev].bOutage)
				continue;
			if (pPRBlock->m_ACBusArray[nDev].nRadial != 0)
				continue;
			if (pPRBlock->m_ACBusArray[nDev].nIsland != nIsland)
				continue;

			if (pPRBlock->m_ACBusArray[nDev].bSlack)
				m_nSlackBus=nDev;
		}

		int nMax=0;
		for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
		{
			if (pPRBlock->m_ACBusArray[nDev].bOutage)
				continue;
			if (pPRBlock->m_ACBusArray[nDev].nRadial != 0)
				continue;
			if (pPRBlock->m_ACBusArray[nDev].nIsland != nIsland)
				continue;

			if (fabs(pPRBlock->m_ACBusArray[nDev].fGenP+pPRBlock->m_ACBusArray[nDev].fAdjGenP) > FLT_MIN)
			{
				m_fGenArray[3*m_nNumGen+0]=(double)nDev;
				m_fGenArray[3*m_nNumGen+1]=(pPRBlock->m_ACBusArray[nDev].fGenP+pPRBlock->m_ACBusArray[nDev].fAdjGenP)/pPRBlock->m_System.fMvaBase;
				m_fGenArray[3*m_nNumGen+2]=(double)nDev;
				fTotalGen += m_fGenArray[3*m_nNumGen+1];

				//if (nIsland == 2)
				//	Log(g_lpszLogFile, "            �絺[%d] ���ӷ��� %g [%f %f]\n", nIsland, m_fGenArray[3*m_nNumGen+1]*pPRBlock->m_System.fMvaBase, pPRBlock->m_ACBusArray[nDev].fGenP, pPRBlock->m_ACBusArray[nDev].fAdjGenP);
				m_nNumGen++;
			}
			if (fabs(pPRBlock->m_ACBusArray[nDev].fLoadP+pPRBlock->m_ACBusArray[nDev].fAdjLoadP+pPRBlock->m_ACBusArray[nDev].fRadP+pPRBlock->m_ACBusArray[nDev].fAdjRadP+fBusLossArray[nDev]) > FLT_MIN)
			{
				m_fLoadArray[3*m_nNumLoad+0]=(double)nDev;
				m_fLoadArray[3*m_nNumLoad+1]=(pPRBlock->m_ACBusArray[nDev].fLoadP+pPRBlock->m_ACBusArray[nDev].fAdjLoadP+pPRBlock->m_ACBusArray[nDev].fRadP+pPRBlock->m_ACBusArray[nDev].fAdjRadP+fBusLossArray[nDev])/pPRBlock->m_System.fMvaBase;
				m_fLoadArray[3*m_nNumLoad+2]=(double)nDev;
				fTotalLoad += m_fLoadArray[3*m_nNumLoad+1];
				//if (nIsland == 2)
				//	Log(g_lpszLogFile, "            �絺[%d] ���Ӹ��� %g [Loss = %f]\n", nIsland, m_fLoadArray[3*m_nNumLoad+1]*pPRBlock->m_System.fMvaBase, fBusLossArray[nDev]);
				m_nNumLoad++;
			}

			if (m_nSlackBus <= 0)
			{
				if (nMax < (pPRBlock->m_ACBusArray[nDev+1].nLineRange-pPRBlock->m_ACBusArray[nDev].nLineRange+pPRBlock->m_ACBusArray[nDev+1].nTranRange-pPRBlock->m_ACBusArray[nDev].nTranRange))
				{
					m_nSlackBus=nDev;
					nMax=(pPRBlock->m_ACBusArray[nDev+1].nLineRange-pPRBlock->m_ACBusArray[nDev].nLineRange+pPRBlock->m_ACBusArray[nDev+1].nTranRange-pPRBlock->m_ACBusArray[nDev].nTranRange);
				}
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
		{
			if (pPRBlock->m_HVDCArray[nDev].bOutage)
				continue;
			if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nIsland == nIsland && pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nRBus].nRadial == 0)
			{
				if (fabs(pPRBlock->m_HVDCArray[nDev].fPr) > FLT_MIN)
				{
					m_fLoadArray[3*m_nNumLoad+0]=(double)pPRBlock->m_HVDCArray[nDev].nRBus;
					m_fLoadArray[3*m_nNumLoad+1]=fabs(pPRBlock->m_HVDCArray[nDev].fPr)/pPRBlock->m_System.fMvaBase;
					m_fLoadArray[3*m_nNumLoad+2]=(double)nDev;
					fTotalDCP += m_fLoadArray[3*m_nNumLoad+1];
					//Log(g_lpszLogFile, "        ֱ��[%s] ������ [%d] ���Ӹ��� %g\n", pPRBlock->m_HVDCArray[nDev].szName, pPRBlock->m_HVDCArray[nDev].nRBus, pPRBlock->m_HVDCArray[nDev].fPr);
					m_nNumLoad++;
				}
			}
			if (pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nIsland == nIsland && pPRBlock->m_ACBusArray[pPRBlock->m_HVDCArray[nDev].nIBus].nRadial == 0)
			{
				if (fabs(pPRBlock->m_HVDCArray[nDev].fPi) > FLT_MIN)
				{
					m_fGenArray[3*m_nNumGen+0]=(double)pPRBlock->m_HVDCArray[nDev].nIBus;
					m_fGenArray[3*m_nNumGen+1]=fabs(pPRBlock->m_HVDCArray[nDev].fPi)/pPRBlock->m_System.fMvaBase;
					m_fGenArray[3*m_nNumGen+2]=(double)nDev;
					fTotalDCP += m_fGenArray[3*m_nNumGen+1];
					//Log(g_lpszLogFile, "        ֱ��[%s] ���� [%d] ���ӷ��� %g\n", pPRBlock->m_HVDCArray[nDev].szName, pPRBlock->m_HVDCArray[nDev].nIBus, pPRBlock->m_HVDCArray[nDev].fPi);
					m_nNumGen++;
				}
			}
		}
#ifdef	_DEBUG
		log_debug("        Island=%d BranNum=%d ƽ��ڵ�=%d [%s] GenP=%.3f\n",
			nIsland, m_nNumBra, m_nSlackBus,
			pPRBlock->m_ACBusArray[m_nSlackBus].szName,
			pPRBlock->m_ACBusArray[m_nSlackBus].fGenP+pPRBlock->m_ACBusArray[m_nSlackBus].fAdjGenP);
#endif

		fBusLossArray.clear();

		//Log(g_lpszLogFile, "    �絺��%d�� ϵͳ����=%g ϵͳ����=%g ֱ������=%g\n", nIsland, fTotalGen*pPRBlock->m_System.fMvaBase, fTotalLoad*pPRBlock->m_System.fMvaBase, fTotalDCP*pPRBlock->m_System.fMvaBase);

#ifdef	_DEBUG
// 		time_t		now;
// 		struct tm	when;
// 		time(&now);
// 		when = *localtime( &now );
// 
// 		char	szFileName[260];
// 		sprintf(szFileName, "Data%.2d%.2d.txt", when.tm_min, when.tm_sec);
// 		FILE*	fp=fopen(szFileName, "w");
// 		if (fp != NULL)
// 		{
// 			fprintf(fp, "G=%d L=%d B=%d\n\n", m_nNumGen, m_nNumLoad, m_nNumBra);
// 			for (nDev=0; nDev<m_nNumGen; nDev++)
// 				fprintf(fp, "G %.0f %.2f %.0f\n", m_fGenArray[3*nDev+0], m_fGenArray[3*nDev+1], m_fGenArray[3*nDev+2]);
// 			fprintf(fp, "\n\n");
// 
// 			for (nDev=0; nDev<m_nNumLoad; nDev++)
// 				fprintf(fp, "L %.0f %.2f %.0f\n", m_fLoadArray[3*nDev+0], m_fLoadArray[3*nDev+1], m_fLoadArray[3*nDev+2]);
// 			fprintf(fp, "\n\n");
// 
// 			for (nDev=0; nDev<m_nNumBra; nDev++)
// 				fprintf(fp, "B %.0f %.0f %.2f %.0f\n", m_fZArray[4*nDev+0], m_fZArray[4*nDev+1], m_fZArray[4*nDev+2], m_fZArray[4*nDev+3]);
// 			fprintf(fp, "\n\n");
// 
// 			fflush(fp);
// 			fclose(fp);
// 		}
#endif

		return 1;
	}

	int	CDCNetwork::PRDCNetwork_ReadRadial(tagPRBlock* pPRBlock, const int nRadial)
	{
		int		nBus, nDev, nBran, nCol;

		//	��������
		m_nMaxBusNumber=0;
		m_nNumBus=0;
		m_nNumBra=0;
		m_nNumGen=0;
		m_nNumLoad=0;

		int		nRBusNum;
		int		nRBusArray[1000];
		g_PRMemDBInterface.PRTraverseRadial(pPRBlock, nRadial, nRBusNum, nRBusArray);

		//Log(g_lpszDCNetworkLogFile, "������ĸ�� ����=%d ʵ��=%d\n", nRBusNum, pPRBlock->m_RadialArray[nRadial+1].pRBus-pPRBlock->m_RadialArray[nRadial].pRBus);

		std::vector<unsigned char>	bLineProcArray;
		std::vector<unsigned char>	bTranProcArray;
		bLineProcArray.resize(pPRBlock->m_nRecordNum[PR_ACLINE]);
		bTranProcArray.resize(pPRBlock->m_nRecordNum[PR_WIND]);
		for (nDev=0; nDev<(int)bLineProcArray.size(); nDev++)
			bLineProcArray[nDev]=0;
		for (nDev=0; nDev<(int)bTranProcArray.size(); nDev++)
			bTranProcArray[nDev]=0;

		m_nSlackBus=pPRBlock->m_RadialArray[nRadial].nRingBoundBus;
		for (nBus=0; nBus<nRBusNum; nBus++)
		{
			if (m_nSlackBus == nRBusArray[nBus])
				continue;
			for (nDev=pPRBlock->m_ACBusArray[nRBusArray[nBus]].nLineRange; nDev<pPRBlock->m_ACBusArray[nRBusArray[nBus]+1].nLineRange; nDev++)
			{
				nBran=pPRBlock->m_ACLineEdgeArray[nDev].nLine;
				if (bLineProcArray[nBran])
					continue;
				if (pPRBlock->m_ACLineArray[nBran].nIRadial != nRadial && pPRBlock->m_ACLineArray[nBran].nZRadial != nRadial)
					continue;
				if (pPRBlock->m_ACLineArray[nBran].bOutage)
					continue;

				bLineProcArray[nBran]=1;

				nCol=0;
				m_fZArray[4*m_nNumBra+nCol++]=(double)pPRBlock->m_ACLineArray[nBran].nIBus;
				m_fZArray[4*m_nNumBra+nCol++]=(double)pPRBlock->m_ACLineArray[nBran].nZBus;
				m_fZArray[4*m_nNumBra+nCol++]=pPRBlock->m_ACLineArray[nBran].fX;
				m_fZArray[4*m_nNumBra+nCol++]=(double)nBran;
				m_nNumBra++;

#ifdef	_DEBUG
				Log(g_lpszDCNetworkLogFile, "������·[%d] [%s] Bus=[%d, %d] %f Radial=[%d    %d, %d]\n", m_nNumBra, 
					pPRBlock->m_ACLineArray[nBran].szName, pPRBlock->m_ACLineArray[nBran].nIBus, 
					pPRBlock->m_ACLineArray[nBran].nZBus, pPRBlock->m_ACLineArray[nBran].fX, 
					nRadial, pPRBlock->m_ACLineArray[nBran].nIRadial, pPRBlock->m_ACLineArray[nBran].nZRadial);
#endif
			}
			for (nDev=pPRBlock->m_ACBusArray[nRBusArray[nBus]].nTranRange; nDev<pPRBlock->m_ACBusArray[nRBusArray[nBus]+1].nTranRange; nDev++)
			{
				nBran=pPRBlock->m_ACWindEdgeArray[nDev].nTran;
				if (bTranProcArray[nBran])
					continue;
				if (pPRBlock->m_WindArray[nBran].nIRadial != nRadial && pPRBlock->m_WindArray[nBran].nZRadial != nRadial)
					continue;
				if (pPRBlock->m_WindArray[nBran].bOutage)
					continue;

				bTranProcArray[nBran]=1;

				nCol=0;
				m_fZArray[4*m_nNumBra+nCol++]=(double)pPRBlock->m_WindArray[nBran].nIBus;
				m_fZArray[4*m_nNumBra+nCol++]=(double)pPRBlock->m_WindArray[nBran].nZBus;
				m_fZArray[4*m_nNumBra+nCol++]=pPRBlock->m_WindArray[nBran].fX;
				m_fZArray[4*m_nNumBra+nCol++]=(double)nBran;
				m_nNumBra++;

#ifdef	_DEBUG
				Log(g_lpszDCNetworkLogFile, "�����ѹ��[%d] [%s] Bus=[%d, %d] %f Radial=[%d    %d, %d]\n", m_nNumBra, 
					pPRBlock->m_WindArray[nBran].szName, pPRBlock->m_WindArray[nBran].nIBus, 
					pPRBlock->m_WindArray[nBran].nZBus, pPRBlock->m_WindArray[nBran].fX, 
					nRadial, pPRBlock->m_WindArray[nBran].nIRadial, pPRBlock->m_WindArray[nBran].nZRadial);
#endif
			}

			if (pPRBlock->m_ACBusArray[nRBusArray[nBus]].bRingBound)
			{
				m_fGenArray[3*m_nNumGen+0]=(double)nRBusArray[nBus];
				m_fGenArray[3*m_nNumGen+1]=(pPRBlock->m_ACBusArray[nRBusArray[nBus]].fGenP+pPRBlock->m_ACBusArray[nRBusArray[nBus]].fAdjGenP)/pPRBlock->m_System.fMvaBase;
				m_fGenArray[3*m_nNumGen+2]=(double)nRBusArray[nBus];
				m_nNumGen++;

#ifdef	_DEBUG
				Log(g_lpszDCNetworkLogFile, "���뷢���[%d] [%s] %d %f\n", m_nNumGen, pPRBlock->m_ACBusArray[nRBusArray[nBus]].szName, nRBusArray[nBus], (pPRBlock->m_ACBusArray[nRBusArray[nBus]].fGenP+pPRBlock->m_ACBusArray[nRBusArray[nBus]].fAdjGenP));
#endif
			}
			if (fabs(pPRBlock->m_ACBusArray[nRBusArray[nBus]].fLoadP+pPRBlock->m_ACBusArray[nRBusArray[nBus]].fAdjLoadP) > FLT_MIN)
			{
				m_fLoadArray[3*m_nNumLoad+0]=(double)nRBusArray[nBus];
				m_fLoadArray[3*m_nNumLoad+1]=(pPRBlock->m_ACBusArray[nRBusArray[nBus]].fLoadP+pPRBlock->m_ACBusArray[nRBusArray[nBus]].fAdjLoadP)/pPRBlock->m_System.fMvaBase;
				m_fLoadArray[3*m_nNumLoad+2]=(double)nRBusArray[nBus];
				m_nNumLoad++;

#ifdef	_DEBUG
				Log(g_lpszDCNetworkLogFile, "���븺��[%d] [%s] %d %f\n", m_nNumLoad, pPRBlock->m_ACBusArray[nRBusArray[nBus]].szName, nRBusArray[nBus], (pPRBlock->m_ACBusArray[nRBusArray[nBus]].fLoadP+pPRBlock->m_ACBusArray[nRBusArray[nBus]].fAdjLoadP));
#endif
			}
		}
		bLineProcArray.clear();
		bTranProcArray.clear();

		for (nDev=0; nDev<m_nNumBra; nDev++)
		{
			if (m_nMaxBusNumber < m_fZArray[4*nDev])
				m_nMaxBusNumber=(int)m_fZArray[4*nDev];
			if (m_nMaxBusNumber < fabs(m_fZArray[4*nDev+1]))
				m_nMaxBusNumber=(int)fabs(m_fZArray[4*nDev+1]);
		}

		return 1;
	}

	void CDCNetwork::PRDCFlowSolve(tagPRBlock* pPRBlock)
	{
		register int	i;

		for (i=0; i<=m_nNumBus; i++)
			m_fBusD[i]=0;
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			if (pPRBlock->m_ACBusArray[i].bOutage)
				continue;
			if (pPRBlock->m_ACBusArray[i].nRadial != 0)
				continue;

			if (fabs(pPRBlock->m_ACBusArray[i].fGenP+pPRBlock->m_ACBusArray[i].fAdjGenP) > FLT_MIN)
				m_fBusD[m_nBusNew[i]] += (pPRBlock->m_ACBusArray[i].fGenP+pPRBlock->m_ACBusArray[i].fAdjGenP)/pPRBlock->m_System.fMvaBase;

			if (fabs(pPRBlock->m_ACBusArray[i].fLoadP+pPRBlock->m_ACBusArray[i].fAdjLoadP+pPRBlock->m_ACBusArray[i].fRadP+pPRBlock->m_ACBusArray[i].fAdjRadP) > FLT_MIN)
				m_fBusD[m_nBusNew[i]] -= (pPRBlock->m_ACBusArray[i].fLoadP+pPRBlock->m_ACBusArray[i].fAdjLoadP+pPRBlock->m_ACBusArray[i].fRadP+pPRBlock->m_ACBusArray[i].fAdjRadP)/pPRBlock->m_System.fMvaBase;
		}

		DCNetwork_BackwardSubstitution();
		PRDCIslandFlowOut(pPRBlock, UPFC_MODE_NO, 1);
	}

	void CDCNetwork::PRDCFlow(tagPRBlock* pPRBlock, const unsigned char nUPFCControlMode, const int nRadial)
	{
		register int	i;
		int		nDev, nIsland;

#ifdef	_DEBUG
		log_debug("PRDCFlow UPFControl=%d Radial=%d\n", nUPFCControlMode, nRadial);
#endif
		if (nRadial == 0)
		{
			std::vector<int>	nUpfcLineArray;
			nUpfcLineArray.clear();
			if (nUPFCControlMode == UPFC_MODE_UPFC)
			{
				for (i=0; i<pPRBlock->m_nRecordNum[PR_UPFC]; i++)
				{
					if (pPRBlock->m_UPFCArray[i].bOutage)
						continue;
					if (pPRBlock->m_UPFCArray[i].nACLine < 0)
						continue;
					if (pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].bOutage)
						continue;
					if (pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].nIRadial != 0 || pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].nZRadial != 0)
						continue;

					pPRBlock->m_ACLineArray[pPRBlock->m_UPFCArray[i].nACLine].bOutage=1;
					nUpfcLineArray.push_back(pPRBlock->m_UPFCArray[i].nACLine);
				}
			}
			g_PRMemDBInterface.PRMemDBIsland(pPRBlock);
			for (i=0; i<(int)nUpfcLineArray.size(); i++)
				pPRBlock->m_ACLineArray[nUpfcLineArray[i]].bOutage=0;
			nUpfcLineArray.clear();

			for (nIsland=1; nIsland<pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
			{
				if (pPRBlock->m_ACIslandArray[nIsland].bDead)
					continue;

				PRDCNetwork_ReadData(pPRBlock, nUPFCControlMode, nIsland);

				if (m_nNumBra <= 0)
					continue;

				DCNetwork_Rename();
				DCNetwork_Admitance();			
				DCNetwork_CholeskyDecompose();	
				DCNetwork_Injection();
				DCNetwork_BackwardSubstitution();
				PRDCIslandFlowOut(pPRBlock, nUPFCControlMode, nIsland, 0);
			}

			pPRBlock->m_System.fSysGenP=0;
			pPRBlock->m_System.fSysLoadP=0;
			pPRBlock->m_System.fSysDCP=0;
			pPRBlock->m_System.fSysAvailGenP=0;
			pPRBlock->m_System.fSysMaxLoadP=0;
			for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_ACBUS]; nDev++)
			{
				pPRBlock->m_ACBusArray[nDev].fMaxGenP=0;
				pPRBlock->m_ACBusArray[nDev].fMinGenP=0;

				pPRBlock->m_System.fSysGenP  += (float)(pPRBlock->m_ACBusArray[nDev].fGenP );
				pPRBlock->m_System.fSysLoadP += (float)(pPRBlock->m_ACBusArray[nDev].fLoadP);
			}
			for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_GENERATOR]; nDev++)
			{
				if (pPRBlock->m_GeneratorArray[nDev].nBusIndex < 0)
					continue;

				if (!pPRBlock->m_GeneratorArray[nDev].bMSModel)
				{
					pPRBlock->m_ACBusArray[pPRBlock->m_GeneratorArray[nDev].nBusIndex].fMaxGenP += pPRBlock->m_GeneratorArray[nDev].fPMax;
					pPRBlock->m_ACBusArray[pPRBlock->m_GeneratorArray[nDev].nBusIndex].fMinGenP += pPRBlock->m_GeneratorArray[nDev].fPMin;
					pPRBlock->m_System.fSysAvailGenP += pPRBlock->m_GeneratorArray[nDev].fPMax;
				}
				else	//	��״̬ģ�Ͳ��ɵ���
				{
					pPRBlock->m_ACBusArray[pPRBlock->m_GeneratorArray[nDev].nBusIndex].fMaxGenP += pPRBlock->m_GeneratorArray[nDev].fMSPout;
					pPRBlock->m_ACBusArray[pPRBlock->m_GeneratorArray[nDev].nBusIndex].fMinGenP += pPRBlock->m_GeneratorArray[nDev].fMSPout;
					pPRBlock->m_System.fSysAvailGenP += pPRBlock->m_GeneratorArray[nDev].fMSPout;
				}

			}
			for (nDev=1; nDev<pPRBlock->m_nRecordNum[PR_HVDC]; nDev++)
			{
				pPRBlock->m_System.fSysDCP += pPRBlock->m_HVDCArray[nDev].fDCPower;
			}
			pPRBlock->m_System.fSysMaxLoadP=pPRBlock->m_System.fSysLoadP;
		}
		else
		{
			PRDCNetwork_ReadRadial(pPRBlock, nRadial);
			if (m_nNumBra <= 0)
				return;

			DCNetwork_Rename();
			DCNetwork_Admitance();			
			DCNetwork_CholeskyDecompose();	
			DCNetwork_Injection();
			DCNetwork_BackwardSubstitution();			
			PRDCRadialFlowOut(pPRBlock, nRadial);
		}
	}

	void	CDCNetwork::PRDCIslandFlowOut(tagPRBlock* pPRBlock, const unsigned char nUPFCControlMode, const int nIsland, const unsigned char bTripFlow)
	{
		int		nBus, nDev;
		double	fDltD;

		for (nBus=1; nBus<=m_nNumBus; nBus++)
			pPRBlock->m_ACBusArray[m_nBusOld[nBus]].fPfD=m_fBusD[nBus];
		pPRBlock->m_ACBusArray[m_nSlackBus].fPfD=0;

		pPRBlock->m_ACBusArray[m_nSlackBus].fGenP=pPRBlock->m_ACBusArray[m_nSlackBus].fLoadP;
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].nIRadial != 0 || pPRBlock->m_ACLineArray[nDev].nZRadial != 0)
				continue;

			if (nUPFCControlMode == UPFC_MODE_UPFC && pPRBlock->m_ACLineArray[nDev].nUPFCIndex >= 0)
			{
				if (!bTripFlow)
				{
					pPRBlock->m_ACLineArray[nDev].fPfPi=pPRBlock->m_ACLineArray[nDev].fPfPz=0;
					if (!pPRBlock->m_ACLineArray[nDev].bOutage)
					{
						if (pPRBlock->m_ACLineArray[nDev].nIBus == pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].nSeriesBus)
						{
							pPRBlock->m_ACLineArray[nDev].fPfPi=(float)( (pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
							pPRBlock->m_ACLineArray[nDev].fPfPz=(float)(-(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
						}
						else
						{
							pPRBlock->m_ACLineArray[nDev].fPfPi=(float)(-(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
							pPRBlock->m_ACLineArray[nDev].fPfPz=(float)( (pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
						}

#ifdef	_DEBUG
						if (nDev == 1401 || nDev == 1402)
							log_debug("        1 Line[%s] = [Pi=%.2f Pz=%.2f]\n", pPRBlock->m_ACLineArray[nDev].szName, pPRBlock->m_ACLineArray[nDev].fPfPi, pPRBlock->m_ACLineArray[nDev].fPfPz);
#endif
						if (pPRBlock->m_ACLineArray[nDev].nIBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fPfPi;
						else if (pPRBlock->m_ACLineArray[nDev].nZBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fPfPz;
					}
				}
				else
				{
					pPRBlock->m_ACLineArray[nDev].fTrPi=pPRBlock->m_ACLineArray[nDev].fTrPz=0;
					if (!pPRBlock->m_ACLineArray[nDev].bOutage)
					{
						if (pPRBlock->m_ACLineArray[nDev].nIBus == pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].nSeriesBus)
						{
							pPRBlock->m_ACLineArray[nDev].fTrPi=(float)( pPRBlock->m_System.fMvaBase*(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
							pPRBlock->m_ACLineArray[nDev].fTrPz=(float)(-pPRBlock->m_System.fMvaBase*(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
						}
						else
						{
							pPRBlock->m_ACLineArray[nDev].fTrPi=(float)(-pPRBlock->m_System.fMvaBase*(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
							pPRBlock->m_ACLineArray[nDev].fTrPz=(float)( pPRBlock->m_System.fMvaBase*(pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fPControl+pPRBlock->m_UPFCArray[pPRBlock->m_ACLineArray[nDev].nUPFCIndex].fLinePse));
						}

						if (pPRBlock->m_ACLineArray[nDev].nIBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fTrPi;
						else if (pPRBlock->m_ACLineArray[nDev].nZBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fTrPz;
					}
				}
			}
			else
			{
				if (pPRBlock->m_ACLineArray[nDev].nIsland != nIsland)
					continue;

				fDltD=pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nIBus].fPfD-pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nZBus].fPfD;
				if (!bTripFlow)
				{
					pPRBlock->m_ACLineArray[nDev].fPfPi=pPRBlock->m_ACLineArray[nDev].fPfPz=0;
					if (pPRBlock->m_ACLineArray[nDev].nIsland > 0 && !pPRBlock->m_ACLineArray[nDev].bOutage)
					{
						pPRBlock->m_ACLineArray[nDev].fPfPi=(float)( pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_ACLineArray[nDev].fX);
						pPRBlock->m_ACLineArray[nDev].fPfPz=(float)(-pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_ACLineArray[nDev].fX);

						if (pPRBlock->m_ACLineArray[nDev].nIBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fPfPi;
						else if (pPRBlock->m_ACLineArray[nDev].nZBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fPfPz;
					}
#ifdef	_DEBUG
					if (nDev == 1401 || nDev == 1402)
					{
						log_debug("        2 Line[%s Bus=%d %d D=%.3f %.3f] = [Pi=%.2f Pz=%.2f]\n", pPRBlock->m_ACLineArray[nDev].szName,
							pPRBlock->m_ACLineArray[nDev].nIBus, pPRBlock->m_ACLineArray[nDev].nZBus,
							pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nIBus].fPfD,
							pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[nDev].nZBus].fPfD,
							pPRBlock->m_ACLineArray[nDev].fPfPi, pPRBlock->m_ACLineArray[nDev].fPfPz);
					}
#endif
				}
				else
				{
					pPRBlock->m_ACLineArray[nDev].fTrPi=pPRBlock->m_ACLineArray[nDev].fTrPz=0;
					if (pPRBlock->m_ACLineArray[nDev].nIsland > 0 && !pPRBlock->m_ACLineArray[nDev].bOutage)
					{
						pPRBlock->m_ACLineArray[nDev].fTrPi=(float)( pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_ACLineArray[nDev].fX);
						pPRBlock->m_ACLineArray[nDev].fTrPz=(float)(-pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_ACLineArray[nDev].fX);

						if (pPRBlock->m_ACLineArray[nDev].nIBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fTrPi;
						else if (pPRBlock->m_ACLineArray[nDev].nZBus == m_nSlackBus)
							pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_ACLineArray[nDev].fTrPz;
					}
				}
			}
		}

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].nIRadial != 0 || pPRBlock->m_WindArray[nDev].nZRadial != 0)
				continue;
			if (pPRBlock->m_WindArray[nDev].nIsland != nIsland)
				continue;

			fDltD=pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDev].nIBus].fPfD-pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[nDev].nZBus].fPfD;
			if (!bTripFlow)
			{
				pPRBlock->m_WindArray[nDev].fPfPi=pPRBlock->m_WindArray[nDev].fPfPz=0;
				if (pPRBlock->m_WindArray[nDev].nIsland > 0 && !pPRBlock->m_WindArray[nDev].bOutage)
				{
					pPRBlock->m_WindArray[nDev].fPfPi=(float)( pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_WindArray[nDev].fX);
					pPRBlock->m_WindArray[nDev].fPfPz=(float)(-pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_WindArray[nDev].fX);

					if (pPRBlock->m_WindArray[nDev].nIBus == m_nSlackBus)
						pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_WindArray[nDev].fPfPi;
					else if (pPRBlock->m_WindArray[nDev].nZBus == m_nSlackBus)
						pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_WindArray[nDev].fPfPz;
				}
			}
			else
			{
				pPRBlock->m_WindArray[nDev].fTrPi=pPRBlock->m_WindArray[nDev].fTrPz=0;
				if (pPRBlock->m_WindArray[nDev].nIsland > 0 && !pPRBlock->m_WindArray[nDev].bOutage)
				{
					pPRBlock->m_WindArray[nDev].fTrPi=(float)( pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_WindArray[nDev].fX);
					pPRBlock->m_WindArray[nDev].fTrPz=(float)(-pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_WindArray[nDev].fX);

					if (pPRBlock->m_WindArray[nDev].nIBus == m_nSlackBus)
						pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_WindArray[nDev].fTrPi;
					else if (pPRBlock->m_WindArray[nDev].nZBus == m_nSlackBus)
						pPRBlock->m_ACBusArray[m_nSlackBus].fGenP += pPRBlock->m_WindArray[nDev].fTrPz;
				}
			}
		}
	}

	void	CDCNetwork::PRDCRadialFlowOut(tagPRBlock* pPRBlock, const int nRadial)
	{
		int		nBus, nDev;
		double	fDltD;

		for (nBus=1; nBus<=m_nNumBus; nBus++)
			pPRBlock->m_ACBusArray[m_nBusOld[nBus]].fPfD=m_fBusD[nBus];
		pPRBlock->m_ACBusArray[m_nSlackBus].fPfD=0;

		//for (nBus=pPRBlock->m_RadialArray[nRadial].nACBusRange; nBus<pPRBlock->m_RadialArray[nRadial+1].nACBusRange; nBus++)
		for (nBus=1; nBus<pPRBlock->m_nRecordNum[PR_ACBUS]; nBus++)
		{
			if (pPRBlock->m_ACBusArray[nBus].bOutage)
				continue;
			if (pPRBlock->m_ACBusArray[nBus].nRadial != nRadial)
				continue;

			for (nDev=pPRBlock->m_ACBusArray[nBus].nLineRange; nDev<pPRBlock->m_ACBusArray[nBus+1].nLineRange; nDev++)
			{
				if (pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].nIRadial != nRadial &&
					pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].nZRadial != nRadial)
					continue;

				fDltD=pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].nIBus].fPfD-pPRBlock->m_ACBusArray[pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].nZBus].fPfD;
				pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].fPfPi=(float)( pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].fX);
				pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].fPfPz=(float)(-pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_ACLineArray[pPRBlock->m_ACLineEdgeArray[nDev].nLine].fX);
			}
			for (nDev=pPRBlock->m_ACBusArray[nBus].nTranRange; nDev<pPRBlock->m_ACBusArray[nBus+1].nTranRange; nDev++)
			{
				if (pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].nIRadial != nRadial && pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].nZRadial != nRadial)
					continue;

				fDltD=pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].nIBus].fPfD-pPRBlock->m_ACBusArray[pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].nZBus].fPfD;
				pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].fPfPi=(float)( pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].fX);
				pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].fPfPz=(float)(-pPRBlock->m_System.fMvaBase*fDltD/pPRBlock->m_WindArray[pPRBlock->m_ACWindEdgeArray[nDev].nTran].fX);
			}
		}
	}
}
