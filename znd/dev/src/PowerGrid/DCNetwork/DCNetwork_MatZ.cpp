#include "DCNetwork.h"

extern	const	char*	g_lpszLogFile;
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
namespace	DCNetwork
{
	void CDCNetwork::PRCheckMatZ(tagPRBlock* pPRBlock, const int nIsland)
	{
		int		nBran, nDev, nCheck, nBusI, nBusJ, nBusM, nBusN;
		double	fBuf1, fBuf2, fFactor;
		double	fZMI, fZMJ, fZNI, fZNJ;
		double	fZMM, fZNN, fZMN;

		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
		{
			if (pPRBlock->m_ACLineArray[nDev].nIsland != nIsland || pPRBlock->m_ACLineArray[nDev].bOutage)
				continue;

			//	nDev=计算支路k
			nBusI=m_nBusNew[pPRBlock->m_ACLineArray[nDev].nIBus];
			nBusJ=m_nBusNew[pPRBlock->m_ACLineArray[nDev].nZBus];

			//	nBran=开断支路l
			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			{
				if (nDev == nBran)
					continue;
				if (pPRBlock->m_ACLineArray[nBran].nIsland != nIsland)
					continue;
				if (pPRBlock->m_ACLineArray[nBran].bTrMIsland)
					continue;

				nBusM=m_nBusNew[pPRBlock->m_ACLineArray[nBran].nIBus];
				nBusN=m_nBusNew[pPRBlock->m_ACLineArray[nBran].nZBus];

				fZMI=m_fMatZ[m_nNumBus*nBusM+nBusI];
				fZMJ=m_fMatZ[m_nNumBus*nBusM+nBusJ];
				fZNI=m_fMatZ[m_nNumBus*nBusN+nBusI];
				fZNJ=m_fMatZ[m_nNumBus*nBusN+nBusJ];
				fBuf1=((fZMI-fZMJ)-(fZNI-fZNJ))/pPRBlock->m_ACLineArray[nDev].fX;

				fZMM=m_fMatZ[m_nNumBus*nBusM+nBusM];
				fZNN=m_fMatZ[m_nNumBus*nBusN+nBusN];
				fZMN=m_fMatZ[m_nNumBus*nBusM+nBusN];
				fBuf2=1.0-(fZMM+fZNN-2*fZMN)/pPRBlock->m_ACLineArray[nBran].fX;
				fFactor=fBuf1/fBuf2;

				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN ||
					nCheck == _FPCLASS_QNAN ||
					nCheck == _FPCLASS_NINF ||
					nCheck == _FPCLASS_PINF)
					Log(g_lpszDCNetworkLogFile, "    MatZFPClassError    CalcLine=%s TripLine=%s\n", pPRBlock->m_ACLineArray[nDev].szName, pPRBlock->m_ACLineArray[nBran].szName);
			}
			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			{
				if (pPRBlock->m_WindArray[nBran].nIsland != nIsland)
					continue;
				if (pPRBlock->m_WindArray[nBran].bTrMIsland)
					continue;

				nBusM=m_nBusNew[pPRBlock->m_WindArray[nBran].nIBus];
				nBusN=m_nBusNew[pPRBlock->m_WindArray[nBran].nZBus];

				fZMI=m_fMatZ[m_nNumBus*nBusM+nBusI];
				fZMJ=m_fMatZ[m_nNumBus*nBusM+nBusJ];
				fZNI=m_fMatZ[m_nNumBus*nBusN+nBusI];
				fZNJ=m_fMatZ[m_nNumBus*nBusN+nBusJ];
				fBuf1=((fZMI-fZMJ)-(fZNI-fZNJ))/pPRBlock->m_ACLineArray[nDev].fX;

				fZMM=m_fMatZ[m_nNumBus*nBusM+nBusM];
				fZNN=m_fMatZ[m_nNumBus*nBusN+nBusN];
				fZMN=m_fMatZ[m_nNumBus*nBusM+nBusN];
				fBuf2=1.0-(fZMM+fZNN-2*fZMN)/pPRBlock->m_WindArray[nBran].fX;
				fFactor=fBuf1/fBuf2;

				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN ||
					nCheck == _FPCLASS_QNAN ||
					nCheck == _FPCLASS_NINF ||
					nCheck == _FPCLASS_PINF)
					Log(g_lpszDCNetworkLogFile, "    MatZFPClassError    CalcLine=%s TripTran=%s\n", pPRBlock->m_ACLineArray[nDev].szName, pPRBlock->m_WindArray[nBran].szName);
			}
		}
		for (nDev=0; nDev<pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
		{
			if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage || pPRBlock->m_WindArray[nDev].bTrMIsland)
				continue;

			nBusI=m_nBusNew[pPRBlock->m_WindArray[nDev].nIBus];
			nBusJ=m_nBusNew[pPRBlock->m_WindArray[nDev].nZBus];
			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			{
				if (pPRBlock->m_ACLineArray[nBran].nIsland != nIsland)
					continue;
				if (pPRBlock->m_ACLineArray[nBran].bTrMIsland)
					continue;

				nBusM=m_nBusNew[pPRBlock->m_ACLineArray[nBran].nIBus];
				nBusN=m_nBusNew[pPRBlock->m_ACLineArray[nBran].nZBus];

				fZMI=m_fMatZ[m_nNumBus*nBusM+nBusI];
				fZMJ=m_fMatZ[m_nNumBus*nBusM+nBusJ];
				fZNI=m_fMatZ[m_nNumBus*nBusN+nBusI];
				fZNJ=m_fMatZ[m_nNumBus*nBusN+nBusJ];
				fBuf1=((fZMI-fZMJ)-(fZNI-fZNJ))/pPRBlock->m_ACLineArray[nDev].fX;

				fZMM=m_fMatZ[m_nNumBus*nBusM+nBusM];
				fZNN=m_fMatZ[m_nNumBus*nBusN+nBusN];
				fZMN=m_fMatZ[m_nNumBus*nBusM+nBusN];
				fBuf2=1.0-(fZMM+fZNN-2*fZMN)/pPRBlock->m_WindArray[nBran].fX;
				fFactor=fBuf1/fBuf2;

				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN ||
					nCheck == _FPCLASS_QNAN ||
					nCheck == _FPCLASS_NINF ||
					nCheck == _FPCLASS_PINF)
					Log(g_lpszDCNetworkLogFile, "    MatZFPClassError    CalcTran=%s TripLine=%s\n", pPRBlock->m_WindArray[nDev].szName, pPRBlock->m_ACLineArray[nBran].szName);
			}
			for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			{
				if (nDev == nBran)
					continue;
				if (pPRBlock->m_WindArray[nBran].nIsland != nIsland)
					continue;
				if (pPRBlock->m_WindArray[nBran].bTrMIsland)
					continue;

				nBusM=m_nBusNew[pPRBlock->m_WindArray[nBran].nIBus];
				nBusN=m_nBusNew[pPRBlock->m_WindArray[nBran].nZBus];

				fZMI=m_fMatZ[m_nNumBus*nBusM+nBusI];
				fZMJ=m_fMatZ[m_nNumBus*nBusM+nBusJ];
				fZNI=m_fMatZ[m_nNumBus*nBusN+nBusI];
				fZNJ=m_fMatZ[m_nNumBus*nBusN+nBusJ];
				fBuf1=((fZMI-fZMJ)-(fZNI-fZNJ))/pPRBlock->m_ACLineArray[nDev].fX;

				fZMM=m_fMatZ[m_nNumBus*nBusM+nBusM];
				fZNN=m_fMatZ[m_nNumBus*nBusN+nBusN];
				fZMN=m_fMatZ[m_nNumBus*nBusM+nBusN];
				fBuf2=1.0-(fZMM+fZNN-2*fZMN)/pPRBlock->m_WindArray[nBran].fX;
				fFactor=fBuf1/fBuf2;

				nCheck=_fpclass(fFactor);
				if (nCheck == _FPCLASS_SNAN ||
					nCheck == _FPCLASS_QNAN ||
					nCheck == _FPCLASS_NINF ||
					nCheck == _FPCLASS_PINF)
					Log(g_lpszDCNetworkLogFile, "    MatZFPClassError    CalcTran=%s TripTran=%s\n", pPRBlock->m_WindArray[nDev].szName, pPRBlock->m_WindArray[nBran].szName);
			}
		}
	}

	void CDCNetwork::PRDCMatZ(tagPRBlock* pPRBlock, const int nRadial, std::vector<float>& fMatZArray)
	{
		int		nRow, nCol, nIsland;

		if (nRadial == 0)
		{
			for (nIsland=1; nIsland<pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
			{
				PRIslandMatZ(pPRBlock, nIsland);

				//for (nRow=1; nRow<=m_nNumBus-1; nRow++)
				//{
				//	for (nCol=nRow; nCol<=m_nNumBus-1; nCol++)
				//	{
				//		Log(g_lpszDCNetworkLogFile, "MatZ[%s, %s]=%f\n", pPRBlock->m_ACBusArray[m_nBusOld[nRow]].szName, pPRBlock->m_ACBusArray[m_nBusOld[nCol]].szName, m_fMatZ[m_nNumBus*nRow+nCol]);
				//	}
				//}

				for (nRow=1; nRow<=m_nNumBus-1; nRow++)
				{
					fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*m_nBusOld[nRow]+m_nBusOld[nRow]]=m_fMatZ[m_nNumBus*nRow+nRow];
					for (nCol=nRow+1; nCol<=m_nNumBus-1; nCol++)
					{
						fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*m_nBusOld[nRow]+m_nBusOld[nCol]]=
							fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*m_nBusOld[nCol]+m_nBusOld[nRow]]=m_fMatZ[m_nNumBus*nRow+nCol];
					}
				}

				//PRCheckMatZ(pPRBlock, nIsland);
				m_fMatZ.clear();
			}
		}
		else
		{
			PRRadialMatZ(pPRBlock, nRadial);
			for (nRow=1; nRow<=m_nNumBus-1; nRow++)
			{
				fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*m_nBusOld[nRow]+m_nBusOld[nRow]]=m_fMatZ[m_nNumBus*nRow+nRow];
				for (nCol=nRow+1; nCol<=m_nNumBus-1; nCol++)
				{
					fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*m_nBusOld[nRow]+m_nBusOld[nCol]]=
						fMatZArray[pPRBlock->m_nRecordNum[PR_ACBUS]*m_nBusOld[nCol]+m_nBusOld[nRow]]=m_fMatZ[m_nNumBus*nRow+nCol];
				}
			}
			m_fMatZ.clear();
		}
	}

	void CDCNetwork::PRIslandMatZ(tagPRBlock* pPRBlock, const int nIsland)
	{
		PRDCNetwork_ReadData(pPRBlock, 0, nIsland);
		if (m_nNumBra <= 0)
			return;

		DCNetwork_Rename();
		DCNetwork_Admitance();
		DCNetwork_InvEliminate();
		DCNetwork_InvImpedance();
	}

	void CDCNetwork::PRRadialMatZ(tagPRBlock* pPRBlock, const int nRadial)
	{
		PRDCNetwork_ReadRadial(pPRBlock, nRadial);
		if (m_nNumBra <= 0)
			return;

		DCNetwork_Rename();
		DCNetwork_Admitance();
		DCNetwork_InvEliminate();
		DCNetwork_InvImpedance();
	}
}
