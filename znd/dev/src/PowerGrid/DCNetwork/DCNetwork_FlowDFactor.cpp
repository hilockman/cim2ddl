#include "StdAfx.h"
#include "DCNetwork.h"

//	潮流法分布因子计算，计算方法上没有问题，速度比较慢，模块暂时无用，分布因子计算采用阻抗法。
namespace	DCNetwork
{
	void CDCNetwork::PRFlowIslandDFactor(tagPRBlock* pPRBlock, const int nIsland)
	{
		PRDCNetwork_ReadData(pPRBlock, nIsland);
		if (m_nNumBra <= 0)
			return;

		int		nDev, nBus;
		int		nBusI, nBusJ;
		double	fDltD;
		//tagBusDFactor	dfBuf;

		DCNetwork_Rename();
		DCNetwork_Admitance();
		DCNetwork_CholeskyDecompose();

		for (nBus=1; nBus<=m_nNumBus-1; nBus++)
		{
			//dfBuf.nBus=m_nBusOld[nBus];
			//if (fabs(pPRBlock->m_ACBusArray[dfBuf.nBus].fLoadP) < FLT_MIN)
			//	continue;

			PRFlowDFactorFBIterate(nBus);
			for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
			{
				if (pPRBlock->m_ACLineArray[nDev].nIsland != nIsland || pPRBlock->m_ACLineArray[nDev].bOutage)
					continue;

				//if (stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B1680[230]-B1716[230]") != 0 &&
				//	stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B506[363]-B258[363]") != 0 &&
				//	stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B532[363]-B533[363]@1") != 0 &&
				//	stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B25[800]-B31[800]@1") != 0)
				//	continue;

				nBusI=m_nBusNew[pPRBlock->m_ACLineArray[nDev].nIBus];
				nBusJ=m_nBusNew[pPRBlock->m_ACLineArray[nDev].nZBus];
				fDltD=m_fBusD[nBusI]-m_fBusD[nBusJ];
				//dfBuf.fFactor=fDltD/pPRBlock->m_ACLineArray[nDev].fX;
				//if (fabs(dfBuf.fFactor) > 0.00001)
				//{
				//	m_LineDFArray[nDev].BusDFArray.push_back(dfBuf);
				//}
			}
			for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
			{
				if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage)
					continue;

				nBusI=m_nBusNew[pPRBlock->m_WindArray[nDev].nIBus];
				nBusJ=m_nBusNew[pPRBlock->m_WindArray[nDev].nZBus];
				fDltD=m_fBusD[nBusI]-m_fBusD[nBusJ];
				//dfBuf.fFactor=fDltD/pPRBlock->m_WindArray[nDev].fX;
				//if (fabs(dfBuf.fFactor) > 0.00001)
				//{
				//	m_TranDFArray[nDev].BusDFArray.push_back(dfBuf);
				//}
			}
		}

		for (nBus=1; nBus<=m_nNumBus-1; nBus++)
		{
			//dfBuf.nBus=m_nBusOld[nBus];
			//if (fabs(pPRBlock->m_ACBusArray[dfBuf.nBus].fGenP) < FLT_MIN)
			//	continue;

			PRFlowDFactorFBIterate(nBus);
			for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nDev++)
			{
				if (pPRBlock->m_ACLineArray[nDev].nIsland != nIsland || pPRBlock->m_ACLineArray[nDev].bOutage)
					continue;

				//if (stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B1680[230]-B1716[230]") != 0 &&
				//	stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B506[363]-B258[363]") != 0 &&
				//	stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B532[363]-B533[363]@1") != 0 &&
				//	stricmp(pPRBlock->m_ACLineArray[nDev].szName, "B25[800]-B31[800]@1") != 0)
				//	continue;

				nBusI=m_nBusNew[pPRBlock->m_ACLineArray[nDev].nIBus];
				nBusJ=m_nBusNew[pPRBlock->m_ACLineArray[nDev].nZBus];
				fDltD=m_fBusD[nBusI]-m_fBusD[nBusJ];
				//dfBuf.fFactor=fDltD/pPRBlock->m_ACLineArray[nDev].fX;
				//if (fabs(dfBuf.fFactor) > 0.00001)
				//	m_LineDFArray[nDev].BusDFArray.push_back(dfBuf);
			}
			for (nDev=0; nDev<(int)pPRBlock->m_nRecordNum[PR_WIND]; nDev++)
			{
				if (pPRBlock->m_WindArray[nDev].nIsland != nIsland || pPRBlock->m_WindArray[nDev].bOutage)
					continue;

				nBusI=m_nBusNew[pPRBlock->m_WindArray[nDev].nIBus];
				nBusJ=m_nBusNew[pPRBlock->m_WindArray[nDev].nZBus];
				fDltD=m_fBusD[nBusI]-m_fBusD[nBusJ];
				//dfBuf.fFactor=fDltD/pPRBlock->m_WindArray[nDev].fX;
				//if (fabs(dfBuf.fFactor) > 0.00001)
				//	m_TranDFArray[nDev].BusDFArray.push_back(dfBuf);
			}
		}
	}

	void	CDCNetwork::PRFlowDFactorFBIterate(const int nBus)
	{
		register int	i;
		int	nRow,nCol,nWorkRow;
		int	nIndex;

		for (i=0; i<m_fBusD.size(); i++)
			m_fBusD[i]=0;
		m_fBusD[nBus] = -1;

		//y(nRow)=b(nRow)-l(nRow,nWorkRow)*y(nWorkRow)	(k=1,i-1)
		for (nRow=2; nRow<=m_nNumBus-1; nRow++)
		{
			nIndex=0;
			for (nWorkRow=1; nWorkRow<=nRow-1; nWorkRow++)
			{
				for (i=1; i<=m_nNumFD[nWorkRow]; i++)
				{
					nCol=m_nMatrixIU[nIndex+i];
					if (nCol == nRow)
						m_fBusD[nRow] -= m_fBusD[nWorkRow]*m_fMatrixU[nIndex+i];
				}
				nIndex += m_nNumFD[nWorkRow];
			}
		}

		//x(nRow)=y(nRow)/d(nRow)-u(nRow, nWorkRow)*x(nWorkRow)	(k=nRow+1,nTotalRow)
		m_fBusD[m_nNumBus-1]=m_fBusD[m_nNumBus-1]*m_fMatrixD[m_nNumBus-1];
		for (nRow=m_nNumBus-2; nRow>=1; nRow--)
		{
			m_fBusD[nRow]=m_fBusD[nRow]*m_fMatrixD[nRow];
			nIndex=0;
			for (i=1; i<nRow; i++)
				nIndex += m_nNumFD[i];

			for (nWorkRow=m_nNumBus-1; nWorkRow>=nRow+1; nWorkRow--)
			{
				for (i=1; i<=m_nNumFD[nRow]; i++)
				{
					nCol=m_nMatrixIU[nIndex+i];
					if (nCol == nWorkRow)
						m_fBusD[nRow] = m_fBusD[nRow]-m_fMatrixU[nIndex+i]*m_fBusD[nWorkRow];
				}
			}
		}
		m_fBusD[m_nBusNew[m_nSlackBus]]=0;
	}
}
