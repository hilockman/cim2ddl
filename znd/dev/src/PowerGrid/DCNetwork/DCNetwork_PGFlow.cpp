#include "DCNetwork.h"

namespace	DCNetwork
{
	int	CDCNetwork::PGDCNetwork_ReadData(tagPGBlock* pPGBlock, const int nIsland)
	{
		int		nCol;
		int		nDev;

		//	输入数据
		m_nMaxBusNumber=0;
		m_nNumBus=0;

		m_nNumBra=0;
		m_nNumGen=0;
		m_nNumLoad=0;
		for (nDev=0; nDev<(int)pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (pPGBlock->m_ACLineSegmentArray[nDev].nIsland != nIsland || pPGBlock->m_ACLineSegmentArray[nDev].bOpen || pPGBlock->m_ACLineSegmentArray[nDev].bOutage)
				continue;
			m_nNumBra++;

			if (m_nMaxBusNumber < pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusI)	m_nMaxBusNumber=pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusI;
			if (m_nMaxBusNumber < pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusJ)	m_nMaxBusNumber=pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusJ;
		}
		for (nDev=0; nDev<(int)pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			if (pPGBlock->m_TransformerWindingArray[nDev].nIsland != nIsland || pPGBlock->m_TransformerWindingArray[nDev].bOpen || pPGBlock->m_TransformerWindingArray[nDev].bOutage)
				continue;
			m_nNumBra++;

			if (m_nMaxBusNumber < pPGBlock->m_TransformerWindingArray[nDev].nTopoBusI)	m_nMaxBusNumber=pPGBlock->m_TransformerWindingArray[nDev].nTopoBusI;
			if (m_nMaxBusNumber < pPGBlock->m_TransformerWindingArray[nDev].nTopoBusJ)	m_nMaxBusNumber=pPGBlock->m_TransformerWindingArray[nDev].nTopoBusJ;
		}

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].nIsland != nIsland)
				continue;
			if (pPGBlock->m_SynchronousMachineArray[nDev].bOutage)
				continue;
			if (fabs(pPGBlock->m_SynchronousMachineArray[nDev].fPlanP) > FLT_MIN)
				m_nNumGen++;
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
		{
			if (pPGBlock->m_EnergyConsumerArray[nDev].nIsland != nIsland)
				continue;
			m_nNumLoad++;
		}
		AllocDataBuffer(m_nMaxBusNumber);

		m_nNumBra=0;
		m_nNumGen=0;
		m_nNumLoad=0;
		for (nDev=0; nDev<(int)pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (pPGBlock->m_ACLineSegmentArray[nDev].nIsland != nIsland || pPGBlock->m_ACLineSegmentArray[nDev].bOpen || pPGBlock->m_ACLineSegmentArray[nDev].bOutage)
				continue;

			nCol=0;
			m_fZArray[4*m_nNumBra+nCol++]=(double)pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusI;
			m_fZArray[4*m_nNumBra+nCol++]=(double)pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusJ;
			m_fZArray[4*m_nNumBra+nCol++]=pPGBlock->m_ACLineSegmentArray[nDev].fX;
			m_fZArray[4*m_nNumBra+nCol++]=(double)nDev;
			m_nNumBra++;
		}
		for (nDev=0; nDev<(int)pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			if (pPGBlock->m_TransformerWindingArray[nDev].nIsland != nIsland || pPGBlock->m_TransformerWindingArray[nDev].bOpen || pPGBlock->m_TransformerWindingArray[nDev].bOutage)
				continue;

			nCol=0;
			m_fZArray[4*m_nNumBra+nCol++]=(double)pPGBlock->m_TransformerWindingArray[nDev].nTopoBusI;
			m_fZArray[4*m_nNumBra+nCol++]=-(double)pPGBlock->m_TransformerWindingArray[nDev].nTopoBusJ;
			m_fZArray[4*m_nNumBra+nCol++]=pPGBlock->m_TransformerWindingArray[nDev].fX;
			m_fZArray[4*m_nNumBra+nCol++]=(double)nDev;
			m_nNumBra++;
		}

		m_nSlackBus=0;
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; nDev++)
		{
			if (pPGBlock->m_SynchronousMachineArray[nDev].nIsland != nIsland)
				continue;
			if (pPGBlock->m_SynchronousMachineArray[nDev].bOutage)
				continue;

			if (fabs(pPGBlock->m_SynchronousMachineArray[nDev].fPlanP) > FLT_MIN)
			{
				m_fGenArray[3*m_nNumGen+0]=(double)nDev;
				m_fGenArray[3*m_nNumGen+1]=pPGBlock->m_SynchronousMachineArray[nDev].fPlanP/pPGBlock->m_System.fBasePower;
				m_fGenArray[3*m_nNumGen+2]=(double)nDev;
				m_nNumGen++;
			}

			if (strcmp(pPGBlock->m_SynchronousMachineArray[nDev].szSub, pPGBlock->m_IslandArray[nIsland].szSlackSub) == 0 &&
				strcmp(pPGBlock->m_SynchronousMachineArray[nDev].szName, pPGBlock->m_IslandArray[nIsland].szSlackGen) == 0)
				m_nSlackBus=pPGBlock->m_SynchronousMachineArray[nDev].nTopoBus;
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; nDev++)
		{
			if (pPGBlock->m_EnergyConsumerArray[nDev].nIsland != nIsland)
				continue;

			m_fLoadArray[3*m_nNumLoad+0]=(double)nDev;
			m_fLoadArray[3*m_nNumLoad+1]=pPGBlock->m_EnergyConsumerArray[nDev].fPlanP/pPGBlock->m_System.fBasePower;
			m_fLoadArray[3*m_nNumLoad+2]=(double)nDev;
			m_nNumLoad++;
		}


		return 1;
	}

	void CDCNetwork::PGDCFlow(tagPGBlock* pPGBlock)							//	面向电网数据库的
	{
		register int	i;
		int		nIsland;

		for (i=0; i<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; i++)
			pPGBlock->m_ACLineSegmentArray[i].bOpen=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; i++)
			pPGBlock->m_TransformerWindingArray[i].bOpen=0;

		PGMemDBTopo(pPGBlock);
		PGMemDBStatus(pPGBlock, 1);

		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			if (pPGBlock->m_IslandArray[nIsland].bDead)
				continue;

			PGDCNetwork_ReadData(pPGBlock, nIsland);
			if (m_nNumBra <= 0)
				continue;

			DCNetwork_Rename();
			DCNetwork_Admitance();			
			DCNetwork_CholeskyDecompose();	
			DCNetwork_Injection();			
			DCNetwork_BackwardSubstitution();			
			PGDCIslandFlowOut(pPGBlock, nIsland, 0);
		}
	}

	void	CDCNetwork::PGDCIslandFlowOut(tagPGBlock* pPGBlock, const int nIsland, const unsigned char bTripFlow)
	{
		int		nBus, nDev;
		double	fDltD;

		for (nBus=1; nBus<=m_nNumBus; nBus++)
			pPGBlock->m_TopoBusArray[m_nBusOld[nBus]].fD=m_fBusD[nBus];
		pPGBlock->m_TopoBusArray[m_nSlackBus].fD=0;

		pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP=pPGBlock->m_TopoBusArray[m_nSlackBus].fLoadP;
		for (nDev=0; nDev<(int)pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (pPGBlock->m_ACLineSegmentArray[nDev].nIsland != nIsland)
				continue;

			fDltD=pPGBlock->m_TopoBusArray[pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusI].fD-pPGBlock->m_TopoBusArray[pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusJ].fD;
			if (!bTripFlow)
			{
				pPGBlock->m_ACLineSegmentArray[nDev].fPi=pPGBlock->m_ACLineSegmentArray[nDev].fPz=0;
				if (pPGBlock->m_ACLineSegmentArray[nDev].nIsland > 0 && !pPGBlock->m_ACLineSegmentArray[nDev].bOpen && !pPGBlock->m_ACLineSegmentArray[nDev].bOutage)
				{
					pPGBlock->m_ACLineSegmentArray[nDev].fPi=(float)( pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_ACLineSegmentArray[nDev].fX);
					pPGBlock->m_ACLineSegmentArray[nDev].fPz=(float)(-pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_ACLineSegmentArray[nDev].fX);

					if (pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusI == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_ACLineSegmentArray[nDev].fPi;
					else if (pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusJ == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_ACLineSegmentArray[nDev].fPz;
				}
			}
			else
			{
				pPGBlock->m_ACLineSegmentArray[nDev].fPi=pPGBlock->m_ACLineSegmentArray[nDev].fPz=0;
				if (pPGBlock->m_ACLineSegmentArray[nDev].nIsland > 0 && !pPGBlock->m_ACLineSegmentArray[nDev].bOpen && !pPGBlock->m_ACLineSegmentArray[nDev].bOutage)
				{
					pPGBlock->m_ACLineSegmentArray[nDev].fPi=(float)( pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_ACLineSegmentArray[nDev].fX);
					pPGBlock->m_ACLineSegmentArray[nDev].fPz=(float)(-pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_ACLineSegmentArray[nDev].fX);

					if (pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusI == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_ACLineSegmentArray[nDev].fPi;
					else if (pPGBlock->m_ACLineSegmentArray[nDev].nTopoBusJ == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_ACLineSegmentArray[nDev].fPz;
				}
			}
		}

		for (nDev=0; nDev<(int)pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			if (pPGBlock->m_TransformerWindingArray[nDev].nIsland != nIsland)
				continue;

			fDltD=pPGBlock->m_TopoBusArray[pPGBlock->m_TransformerWindingArray[nDev].nTopoBusI].fD-pPGBlock->m_TopoBusArray[pPGBlock->m_TransformerWindingArray[nDev].nTopoBusJ].fD;
			if (!bTripFlow)
			{
				pPGBlock->m_TransformerWindingArray[nDev].fPi=pPGBlock->m_TransformerWindingArray[nDev].fPz=0;
				if (pPGBlock->m_TransformerWindingArray[nDev].nIsland > 0 && !pPGBlock->m_TransformerWindingArray[nDev].bOpen && !pPGBlock->m_TransformerWindingArray[nDev].bOutage)
				{
					pPGBlock->m_TransformerWindingArray[nDev].fPi=(float)( pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_TransformerWindingArray[nDev].fX);
					pPGBlock->m_TransformerWindingArray[nDev].fPz=(float)(-pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_TransformerWindingArray[nDev].fX);

					if (pPGBlock->m_TransformerWindingArray[nDev].nTopoBusI == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_TransformerWindingArray[nDev].fPi;
					else if (pPGBlock->m_TransformerWindingArray[nDev].nTopoBusJ == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_TransformerWindingArray[nDev].fPz;
				}
			}
			else
			{
				pPGBlock->m_TransformerWindingArray[nDev].fPi=pPGBlock->m_TransformerWindingArray[nDev].fPz=0;
				if (pPGBlock->m_TransformerWindingArray[nDev].nIsland > 0 && !pPGBlock->m_TransformerWindingArray[nDev].bOpen && !pPGBlock->m_TransformerWindingArray[nDev].bOutage)
				{
					pPGBlock->m_TransformerWindingArray[nDev].fPi=(float)( pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_TransformerWindingArray[nDev].fX);
					pPGBlock->m_TransformerWindingArray[nDev].fPz=(float)(-pPGBlock->m_System.fBasePower*fDltD/pPGBlock->m_TransformerWindingArray[nDev].fX);

					if (pPGBlock->m_TransformerWindingArray[nDev].nTopoBusI == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_TransformerWindingArray[nDev].fPi;
					else if (pPGBlock->m_TransformerWindingArray[nDev].nTopoBusJ == m_nSlackBus)
						pPGBlock->m_TopoBusArray[m_nSlackBus].fGenP += pPGBlock->m_TransformerWindingArray[nDev].fPz;
				}
			}
		}
	}
}
