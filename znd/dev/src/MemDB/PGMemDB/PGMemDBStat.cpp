#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace	PGMemDB
{
	void	PGMemDBStatistic(tagPGBlock* pPGBlock, const int nLossFlag)
	{
		register int	i, j;
		int		nSub, nVolt, nDev;
		float	fAuxP, fAuxQ, fAuxPCon, fAuxPVar, fAuxCoef;
		int		nLine, nSubI, nSubJ, nCorpI, nCorpJ;
		float	fSum, fPBuffer, fQBuffer;
		int		nDiv, nDivI, nDivJ, nIsland;

		//////////////////////////////////////////////////////////////////////////
		//	统计量初始化
		pPGBlock->m_System.fTotalGenP=pPGBlock->m_System.fTotalGenQ=
			pPGBlock->m_System.fTotalLoadP=pPGBlock->m_System.fTotalLoadQ=
			pPGBlock->m_System.fTotalCap=pPGBlock->m_System.fTotalReac=0;

		pPGBlock->m_System.fRunningGenP=pPGBlock->m_System.fRunningGenQ=
			pPGBlock->m_System.fRunningLoadP=pPGBlock->m_System.fRunningLoadQ=
			pPGBlock->m_System.fRunningCap=pPGBlock->m_System.fRunningReac=0;

		pPGBlock->m_System.fLossP=pPGBlock->m_System.fLossQ=
			pPGBlock->m_System.fDeadIslandLoadP=pPGBlock->m_System.fDeadIslandLoadQ=0;

		pPGBlock->m_System.nLineOverLoad=pPGBlock->m_System.nTranOverLoad=0;
		pPGBlock->m_System.fLineOverLoadIdx=pPGBlock->m_System.fTranOverLoadIdx=0;

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nDev++)
		{
			pPGBlock->m_SubstationArray[nDev].fTotalGenP=pPGBlock->m_SubstationArray[nDev].fTotalGenQ=
				pPGBlock->m_SubstationArray[nDev].fTotalLoadP=pPGBlock->m_SubstationArray[nDev].fTotalLoadQ=
				pPGBlock->m_SubstationArray[nDev].fTotalCap=pPGBlock->m_SubstationArray[nDev].fTotalReac=0;

			pPGBlock->m_SubstationArray[nDev].fRunningGenP=pPGBlock->m_SubstationArray[nDev].fRunningGenQ=
				pPGBlock->m_SubstationArray[nDev].fRunningLoadP=pPGBlock->m_SubstationArray[nDev].fRunningLoadQ=
				pPGBlock->m_SubstationArray[nDev].fRunningCap=pPGBlock->m_SubstationArray[nDev].fRunningReac=0;
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nDev++)
		{
			pPGBlock->m_SubcontrolAreaArray[nDev].fTotalGenP=pPGBlock->m_SubcontrolAreaArray[nDev].fTotalGenQ=
				pPGBlock->m_SubcontrolAreaArray[nDev].fTotalLoadP=pPGBlock->m_SubcontrolAreaArray[nDev].fTotalLoadQ=
				pPGBlock->m_SubcontrolAreaArray[nDev].fTotalCap=pPGBlock->m_SubcontrolAreaArray[nDev].fTotalReac=0;

			pPGBlock->m_SubcontrolAreaArray[nDev].fRunningGenP=pPGBlock->m_SubcontrolAreaArray[nDev].fRunningGenQ=
				pPGBlock->m_SubcontrolAreaArray[nDev].fRunningLoadP=pPGBlock->m_SubcontrolAreaArray[nDev].fRunningLoadQ=
				pPGBlock->m_SubcontrolAreaArray[nDev].fRunningCap=pPGBlock->m_SubcontrolAreaArray[nDev].fRunningReac=0;

			pPGBlock->m_SubcontrolAreaArray[nDev].fLossP=pPGBlock->m_SubcontrolAreaArray[nDev].fLossQ=0;
		}
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_COMPANY]; nDev++)
		{
			pPGBlock->m_CompanyArray[nDev].fTotalGenP=pPGBlock->m_CompanyArray[nDev].fTotalGenQ=
				pPGBlock->m_CompanyArray[nDev].fTotalLoadP=pPGBlock->m_CompanyArray[nDev].fTotalLoadQ=
				pPGBlock->m_CompanyArray[nDev].fTotalCap=pPGBlock->m_CompanyArray[nDev].fTotalReac=0;

			pPGBlock->m_CompanyArray[nDev].fRunningGenP=pPGBlock->m_CompanyArray[nDev].fRunningGenQ=
				pPGBlock->m_CompanyArray[nDev].fRunningLoadP=pPGBlock->m_CompanyArray[nDev].fRunningLoadQ=
				pPGBlock->m_CompanyArray[nDev].fRunningCap=pPGBlock->m_CompanyArray[nDev].fRunningReac=0;

			pPGBlock->m_CompanyArray[nDev].fLossP=pPGBlock->m_CompanyArray[nDev].fLossQ=0;
		}

		//////////////////////////////////////////////////////////////////////////
		//	统计静态量
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0)
						continue;

					fAuxP=fAuxQ=0;
					fAuxPCon=pPGBlock->m_SynchronousMachineArray[nDev].fAuxPca;
					fAuxPVar=pPGBlock->m_SynchronousMachineArray[nDev].fAuxPva;
					fAuxCoef=0.8f;
					if (pPGBlock->m_SynchronousMachineArray[nDev].fAuxFactor > 0.5)
						fAuxCoef=pPGBlock->m_SynchronousMachineArray[nDev].fAuxFactor;

					if (fAuxPCon > 0.001 || fAuxPVar > 0.001)
					{
						fAuxP=pPGBlock->m_SynchronousMachineArray[nDev].fPMax*fAuxPCon+pPGBlock->m_SynchronousMachineArray[nDev].fPlanP*fAuxPVar;
						fAuxQ=(float)(fAuxP*sqrt(1-fAuxCoef*fAuxCoef)/fAuxCoef);
					}

					pPGBlock->m_SubstationArray[nSub].fTotalGenP += pPGBlock->m_SynchronousMachineArray[nDev].fPlanP;
					pPGBlock->m_SubstationArray[nSub].fTotalGenQ += pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ;

					pPGBlock->m_SubstationArray[nSub].fTotalLoadP += fAuxP;
					pPGBlock->m_SubstationArray[nSub].fTotalLoadQ += fAuxQ;
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
				{
					if (pPGBlock->m_EnergyConsumerArray[nDev].nNode < 0)
						continue;
					if (pPGBlock->m_EnergyConsumerArray[nDev].bOutage != 0)
						continue;

					pPGBlock->m_SubstationArray[nSub].fTotalLoadP += pPGBlock->m_EnergyConsumerArray[nDev].fPlanP;
					pPGBlock->m_SubstationArray[nSub].fTotalLoadQ += pPGBlock->m_EnergyConsumerArray[nDev].fPlanQ;
				}
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
				{
					if (pPGBlock->m_ShuntCompensatorArray[nDev].bOutage != 0)
						continue;
					if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode < 0)
						continue;

					if (pPGBlock->m_ShuntCompensatorArray[nDev].fCap > 0)
						pPGBlock->m_SubstationArray[nSub].fTotalCap += pPGBlock->m_ShuntCompensatorArray[nDev].fCap;
					else
						pPGBlock->m_SubstationArray[nSub].fTotalReac += pPGBlock->m_ShuntCompensatorArray[nDev].fCap;
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDiv=0; nDiv<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nDiv++)
			{
				if (strcmp(pPGBlock->m_SubcontrolAreaArray[nDiv].szName, pPGBlock->m_SubstationArray[nSub].szSubcontrolArea) == 0)
				{
					pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalGenP	+=pPGBlock->m_SubstationArray[nSub].fTotalGenP;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalGenQ	+=pPGBlock->m_SubstationArray[nSub].fTotalGenQ;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalLoadP	+=pPGBlock->m_SubstationArray[nSub].fTotalLoadP;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalLoadQ	+=pPGBlock->m_SubstationArray[nSub].fTotalLoadQ;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalCap		+=pPGBlock->m_SubstationArray[nSub].fTotalCap;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalReac	+=pPGBlock->m_SubstationArray[nSub].fTotalReac;
					break;
				}
			}
		}
		for (nDiv=0; nDiv<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nDiv++)
		{
			for (i=0; i<pPGBlock->m_nRecordNum[PG_COMPANY]; i++)
			{
				if (strcmp(pPGBlock->m_CompanyArray[i].szName, pPGBlock->m_SubcontrolAreaArray[nDiv].szCompany) == 0)
				{
					pPGBlock->m_CompanyArray[i].fTotalGenP		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalGenP;
					pPGBlock->m_CompanyArray[i].fTotalGenQ		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalGenQ;
					pPGBlock->m_CompanyArray[i].fTotalLoadP		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalLoadP;
					pPGBlock->m_CompanyArray[i].fTotalLoadQ		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalLoadQ;
					pPGBlock->m_CompanyArray[i].fTotalCap		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalCap;
					pPGBlock->m_CompanyArray[i].fTotalReac		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fTotalReac;
					break;
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			pPGBlock->m_System.fTotalGenP	+=pPGBlock->m_SubstationArray[nSub].fTotalGenP;
			pPGBlock->m_System.fTotalGenQ	+=pPGBlock->m_SubstationArray[nSub].fTotalGenQ;
			pPGBlock->m_System.fTotalLoadP	+=pPGBlock->m_SubstationArray[nSub].fTotalLoadP;
			pPGBlock->m_System.fTotalLoadQ	+=pPGBlock->m_SubstationArray[nSub].fTotalLoadQ;
			pPGBlock->m_System.fTotalCap	+=pPGBlock->m_SubstationArray[nSub].fTotalCap;
			pPGBlock->m_System.fTotalReac	+=pPGBlock->m_SubstationArray[nSub].fTotalReac;
		}
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	统计运行量
		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			if (pPGBlock->m_IslandArray[nIsland].bDead)
				continue;

			for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
			{
				for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
				{
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
					{
						if (pPGBlock->m_SynchronousMachineArray[nDev].nNode < 0)
							continue;
						if (pPGBlock->m_SynchronousMachineArray[nDev].nIsland != nIsland)
							continue;

						fAuxP=fAuxQ=0;
						fAuxPCon=pPGBlock->m_SynchronousMachineArray[nDev].fAuxPca;
						fAuxPVar=pPGBlock->m_SynchronousMachineArray[nDev].fAuxPva;
						fAuxCoef=0.8f;
						if (pPGBlock->m_SynchronousMachineArray[nDev].fAuxFactor > 0.5)
							fAuxCoef=pPGBlock->m_SynchronousMachineArray[nDev].fAuxFactor;

						if (fAuxPCon > 0.001 || fAuxPVar > 0.001)
						{
							fAuxP=pPGBlock->m_SynchronousMachineArray[nDev].fPMax*fAuxPCon+pPGBlock->m_SynchronousMachineArray[nDev].fPlanP*fAuxPVar;
							fAuxQ=(float)(fAuxP*sqrt(1-fAuxCoef*fAuxCoef)/fAuxCoef);
						}

						pPGBlock->m_SubstationArray[nSub].fRunningGenP += pPGBlock->m_SynchronousMachineArray[nDev].fP;
						pPGBlock->m_SubstationArray[nSub].fRunningGenQ += pPGBlock->m_SynchronousMachineArray[nDev].fQ;

						pPGBlock->m_SubstationArray[nSub].fRunningLoadP += fAuxP;
						pPGBlock->m_SubstationArray[nSub].fRunningLoadQ += fAuxQ;
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nEnergyConsumerRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nEnergyConsumerRange; nDev++)
					{
						if (pPGBlock->m_EnergyConsumerArray[nDev].nNode < 0)
							continue;
						if (pPGBlock->m_EnergyConsumerArray[nDev].nIsland != nIsland)
							continue;

						pPGBlock->m_SubstationArray[nSub].fRunningLoadP += pPGBlock->m_EnergyConsumerArray[nDev].fP;
						pPGBlock->m_SubstationArray[nSub].fRunningLoadQ += pPGBlock->m_EnergyConsumerArray[nDev].fQ;
					}
					for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nShuntCompensatorRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nShuntCompensatorRange; nDev++)
					{
						if (pPGBlock->m_ShuntCompensatorArray[nDev].nIsland != nIsland)
							continue;
						if (pPGBlock->m_ShuntCompensatorArray[nDev].nNode < 0)
							continue;

						if (pPGBlock->m_ShuntCompensatorArray[nDev].fCap > 0)
							pPGBlock->m_SubstationArray[nSub].fRunningCap += pPGBlock->m_ShuntCompensatorArray[nDev].fQ;
						else
							pPGBlock->m_SubstationArray[nSub].fRunningReac += pPGBlock->m_ShuntCompensatorArray[nDev].fQ;
					}
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDiv=0; nDiv<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nDiv++)
			{
				if (strcmp(pPGBlock->m_SubcontrolAreaArray[nDiv].szName, pPGBlock->m_SubstationArray[nSub].szSubcontrolArea) == 0)
				{
					pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningGenP	+=pPGBlock->m_SubstationArray[nSub].fRunningGenP;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningGenQ	+=pPGBlock->m_SubstationArray[nSub].fRunningGenQ;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningLoadP	+=pPGBlock->m_SubstationArray[nSub].fRunningLoadP;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningLoadQ	+=pPGBlock->m_SubstationArray[nSub].fRunningLoadQ;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningCap	+=pPGBlock->m_SubstationArray[nSub].fRunningCap;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningReac	+=pPGBlock->m_SubstationArray[nSub].fRunningReac;
					break;
				}
			}
		}
		for (nDiv=0; nDiv<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nDiv++)
		{
			for (i=0; i<pPGBlock->m_nRecordNum[PG_COMPANY]; i++)
			{
				if (strcmp(pPGBlock->m_CompanyArray[i].szName, pPGBlock->m_SubcontrolAreaArray[nDiv].szCompany) == 0)
				{
					pPGBlock->m_CompanyArray[i].fRunningGenP		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningGenP;
					pPGBlock->m_CompanyArray[i].fRunningGenQ		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningGenQ;
					pPGBlock->m_CompanyArray[i].fRunningLoadP		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningLoadP;
					pPGBlock->m_CompanyArray[i].fRunningLoadQ		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningLoadQ;
					pPGBlock->m_CompanyArray[i].fRunningCap			+=pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningCap;
					pPGBlock->m_CompanyArray[i].fRunningReac		+=pPGBlock->m_SubcontrolAreaArray[nDiv].fRunningReac;
					break;
				}
			}
		}

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			pPGBlock->m_System.fRunningGenP		+=pPGBlock->m_SubstationArray[nSub].fRunningGenP;
			pPGBlock->m_System.fRunningGenQ		+=pPGBlock->m_SubstationArray[nSub].fRunningGenQ;
			pPGBlock->m_System.fRunningLoadP	+=pPGBlock->m_SubstationArray[nSub].fRunningLoadP;
			pPGBlock->m_System.fRunningLoadQ	+=pPGBlock->m_SubstationArray[nSub].fRunningLoadQ;
			pPGBlock->m_System.fRunningCap		+=pPGBlock->m_SubstationArray[nSub].fRunningCap;
			pPGBlock->m_System.fRunningReac		+=pPGBlock->m_SubstationArray[nSub].fRunningReac;
		}

		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////
		//	联络线交换功率
		if (pPGBlock->m_nRecordNum[PG_COMPANY] >= 2)
		{
			for (i=0; i<pPGBlock->m_nRecordNum[PG_TIELINE]; i++)
			{
				nLine=nSubI=nSubJ=nCorpI=nCorpJ=-1;

				for (j=0; j<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; j++)
				{
					if (strcmp(pPGBlock->m_ACLineSegmentArray[j].szName, pPGBlock->m_TielineArray[i].szName) == 0)
					{
						nLine=j;
						break;
					}
				}
				for (j=0; j<pPGBlock->m_nRecordNum[PG_COMPANY]; j++)
				{
					if (strcmp(pPGBlock->m_TielineArray[i].szCompanyI, pPGBlock->m_CompanyArray[j].szName) == 0)
					{
						nCorpI=j;
						break;
					}
				}

				for (j=0; j<pPGBlock->m_nRecordNum[PG_COMPANY]; j++)
				{
					if (strcmp(pPGBlock->m_TielineArray[i].szCompanyZ, pPGBlock->m_CompanyArray[j].szName) == 0)
					{
						nCorpJ=j;
						break;
					}
				}

				nSubI=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[nLine].szSubI);
				nSubJ=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[nLine].szSubJ);
				if (nLine < 0 || nSubI < 0 || nSubJ < 0 || nCorpI < 0 || nCorpJ < 0)
				{
					continue;
				}

				if (strcmp(pPGBlock->m_CompanyArray[nCorpI].szName, pPGBlock->m_SubstationArray[nSubI].szCompany) == 0)
				{
					pPGBlock->m_CompanyArray[nCorpI].fTieP += pPGBlock->m_ACLineSegmentArray[nLine].fPi;
					pPGBlock->m_CompanyArray[nCorpJ].fTieP += pPGBlock->m_ACLineSegmentArray[nLine].fPi;
				}
				else
				{
					pPGBlock->m_CompanyArray[nCorpJ].fTieP += pPGBlock->m_ACLineSegmentArray[nLine].fPz;
					pPGBlock->m_CompanyArray[nCorpI].fTieP += pPGBlock->m_ACLineSegmentArray[nLine].fPz;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	网损计算
		if (nLossFlag == 0)
		{
			for (i=0; i<pPGBlock->m_nRecordNum[PG_COMPANY]; i++)
			{
				for (j=0; j<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; j++)
				{
					pPGBlock->m_SubcontrolAreaArray[j].fLossP = pPGBlock->m_SubcontrolAreaArray[j].fRunningGenP-pPGBlock->m_SubcontrolAreaArray[j].fRunningLoadP;
					pPGBlock->m_SubcontrolAreaArray[j].fLossQ = pPGBlock->m_SubcontrolAreaArray[j].fRunningGenQ-pPGBlock->m_SubcontrolAreaArray[j].fRunningLoadQ+pPGBlock->m_SubcontrolAreaArray[j].fRunningCap+pPGBlock->m_SubcontrolAreaArray[j].fRunningReac;
				}
				pPGBlock->m_CompanyArray[i].fLossP = pPGBlock->m_CompanyArray[i].fRunningGenP-pPGBlock->m_CompanyArray[i].fRunningLoadP;
				pPGBlock->m_CompanyArray[i].fLossQ = pPGBlock->m_CompanyArray[i].fRunningGenQ-pPGBlock->m_CompanyArray[i].fRunningLoadQ+pPGBlock->m_CompanyArray[i].fRunningCap+pPGBlock->m_CompanyArray[i].fRunningReac;
			}
			pPGBlock->m_System.fLossP = pPGBlock->m_System.fRunningGenP-pPGBlock->m_System.fRunningLoadP;
			pPGBlock->m_System.fLossQ = pPGBlock->m_System.fRunningGenQ-pPGBlock->m_System.fRunningLoadQ+pPGBlock->m_System.fRunningCap+pPGBlock->m_System.fRunningReac;
		}
		else
		{
			for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
			{
				if (pPGBlock->m_ACLineSegmentArray[nDev].bOutage != 0)
					continue;

				fPBuffer=pPGBlock->m_ACLineSegmentArray[nDev].fPi+pPGBlock->m_ACLineSegmentArray[nDev].fPz;
				fQBuffer=pPGBlock->m_ACLineSegmentArray[nDev].fQi+pPGBlock->m_ACLineSegmentArray[nDev].fQz;
				if (fabs(fPBuffer) > 100 || fabs(fQBuffer) > 1000)
					fPBuffer=fQBuffer=0;

				nDivI=nDivJ=-1;
				nSub=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[nDev].szSubI);
				if (nSub >= 0)
				{
					for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; i++)
					{
						if (strcmp(pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubstationArray[nSub].szSubcontrolArea) == 0)
						{
							nDivI=i;
							break;
						}
					}
				}

				nSub=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_ACLineSegmentArray[nDev].szSubJ);
				if (nSub >= 0)
				{
					for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; i++)
					{
						if (strcmp(pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubstationArray[nSub].szSubcontrolArea) == 0)
						{
							nDivJ=i;
							break;
						}
					}
				}

				if (nDivI < 0 || nDivJ < 0)
					continue;
				if (nDivI != nDivJ)
				{
					pPGBlock->m_SubcontrolAreaArray[nDivI].fLossP += fPBuffer/2;
					pPGBlock->m_SubcontrolAreaArray[nDivI].fLossQ += fQBuffer/2;
					pPGBlock->m_SubcontrolAreaArray[nDivJ].fLossP += fPBuffer/2;
					pPGBlock->m_SubcontrolAreaArray[nDivJ].fLossQ += fQBuffer/2;
				}
				else
				{
					pPGBlock->m_SubcontrolAreaArray[nDivI].fLossP += fPBuffer;
					pPGBlock->m_SubcontrolAreaArray[nDivI].fLossQ += fQBuffer;
				}
			}
			for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
			{
				if (pPGBlock->m_TransformerWindingArray[nDev].bOutage != 0)
					continue;

				fPBuffer=pPGBlock->m_TransformerWindingArray[nDev].fPi+pPGBlock->m_TransformerWindingArray[nDev].fPz;
				fQBuffer=pPGBlock->m_TransformerWindingArray[nDev].fQi+pPGBlock->m_TransformerWindingArray[nDev].fQz;
				if (fabs(fPBuffer) > 100 || fabs(fQBuffer) > 1000)
					fPBuffer=fQBuffer=0;

				nDiv=nSub=-1;
				nSub=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_TransformerWindingArray[nDev].szSub);
				if (nSub >= 0)
				{
					for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; i++)
					{
						if (strcmp(pPGBlock->m_SubcontrolAreaArray[i].szName, pPGBlock->m_SubstationArray[nSub].szSubcontrolArea) == 0)
						{
							nDiv=i;
							break;
						}
					}
				}
				if (nDiv >= 0)
				{
					pPGBlock->m_SubcontrolAreaArray[nDiv].fLossP += fPBuffer;
					pPGBlock->m_SubcontrolAreaArray[nDiv].fLossQ += fQBuffer;
				}
			}
			for (i=0; i<pPGBlock->m_nRecordNum[PG_COMPANY]; i++)
			{
				for (nDiv=0; nDiv<pPGBlock->m_nRecordNum[PG_SUBCONTROLAREA]; nDiv++)
				{
					if (strcmp(pPGBlock->m_SubcontrolAreaArray[nDiv].szCompany, pPGBlock->m_CompanyArray[i].szName) == 0)
					{
						pPGBlock->m_CompanyArray[i].fLossP += pPGBlock->m_SubcontrolAreaArray[nDiv].fLossP;
						pPGBlock->m_CompanyArray[i].fLossQ += pPGBlock->m_SubcontrolAreaArray[nDiv].fLossQ;
					}
				}
				pPGBlock->m_System.fLossP += pPGBlock->m_CompanyArray[i].fLossP;
				pPGBlock->m_System.fLossQ += pPGBlock->m_CompanyArray[i].fLossQ;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//	网损统计量计算中由BPA直接获得
		fPBuffer = fQBuffer = 0;
		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			if (pPGBlock->m_IslandArray[nIsland].bDead)
				continue;

			fPBuffer += pPGBlock->m_IslandArray[nIsland].fLossP;
			fQBuffer += pPGBlock->m_IslandArray[nIsland].fLossQ;
		}
		if (fPBuffer > FLT_MIN)
		{
			pPGBlock->m_System.fLossP = fPBuffer;
			pPGBlock->m_System.fLossQ = fQBuffer;
		}
		if (pPGBlock->m_System.fRunningLoadP > FLT_MIN)	pPGBlock->m_System.fLossRate = 100*pPGBlock->m_System.fLossP/pPGBlock->m_System.fRunningLoadP;
		//////////////////////////////////////////////////////////////////////////
		//	发电统计量计算中由BPA直接获得
		fPBuffer = fQBuffer = 0;
		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			if (pPGBlock->m_IslandArray[nIsland].bDead)
				continue;

			fPBuffer += pPGBlock->m_IslandArray[nIsland].fUnitP;
			fQBuffer += pPGBlock->m_IslandArray[nIsland].fUnitQ;
		}
		if (fPBuffer > FLT_MIN)
		{
			pPGBlock->m_System.fRunningGenP = fPBuffer;
			pPGBlock->m_System.fRunningGenQ = fQBuffer;
		}
		//////////////////////////////////////////////////////////////////////////
		//	负荷统计量计算中由BPA直接获得
		fPBuffer = fQBuffer = 0;
		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			if (pPGBlock->m_IslandArray[nIsland].bDead)
				continue;

			fPBuffer += pPGBlock->m_IslandArray[nIsland].fLoadP;
			fQBuffer += pPGBlock->m_IslandArray[nIsland].fLoadQ;
		}
		if (fPBuffer > FLT_MIN)
		{
			pPGBlock->m_System.fRunningLoadP = fPBuffer;
			pPGBlock->m_System.fRunningLoadQ = fQBuffer;
		}
		//////////////////////////////////////////////////////////////////////////
		//	补偿统计量计算中由BPA直接获得
		fPBuffer = fQBuffer = 0;
		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			if (pPGBlock->m_IslandArray[nIsland].bDead)
				continue;

			fQBuffer += pPGBlock->m_IslandArray[nIsland].fShuntQ;
		}
		if (fPBuffer > FLT_MIN)
			pPGBlock->m_System.fRunningCap = fQBuffer;
		else if (fQBuffer < -FLT_MIN)
			pPGBlock->m_System.fRunningReac = fQBuffer;

		//////////////////////////////////////////////////////////////////////////
		//	计算功率因数
		for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
		{
			if (pPGBlock->m_EnergyConsumerArray[i].nNode < 0)
				continue;

			fSum=(float)sqrt(pow(pPGBlock->m_EnergyConsumerArray[i].fP, 2)+pow(pPGBlock->m_EnergyConsumerArray[i].fQ, 2));
			if (fabs(fSum) < 0.01)
				pPGBlock->m_EnergyConsumerArray[i].fFactor=0;
			else
				pPGBlock->m_EnergyConsumerArray[i].fFactor=(pPGBlock->m_EnergyConsumerArray[i].fP/fSum);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
		{
			if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
				continue;

			fSum=(float)sqrt(pow(pPGBlock->m_SynchronousMachineArray[i].fP, 2)+pow(pPGBlock->m_SynchronousMachineArray[i].fQ, 2));
			if (fabs(fSum) < 0.01)
				pPGBlock->m_SynchronousMachineArray[i].fFactor=0;
			else
				pPGBlock->m_SynchronousMachineArray[i].fFactor=(pPGBlock->m_SynchronousMachineArray[i].fP/fSum);
		}
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SUBSTATION]; i++)
		{
			fSum=(float)sqrt(pow(pPGBlock->m_SubstationArray[i].fRunningLoadP, 2)+pow(pPGBlock->m_SubstationArray[i].fRunningLoadQ, 2));
			if (fabs(fSum) < 0.01)
				pPGBlock->m_SubstationArray[i].fLoadFatctor=0;
			else
				pPGBlock->m_SubstationArray[i].fLoadFatctor=(pPGBlock->m_SubstationArray[i].fRunningLoadP/fSum);

			fSum=(float)sqrt(pow(pPGBlock->m_SubstationArray[i].fRunningGenP, 2)+pow(pPGBlock->m_SubstationArray[i].fRunningGenQ, 2));
			if (fabs(fSum) < 0.01)
				pPGBlock->m_SubstationArray[i].fGenFatctor=0;
			else
				pPGBlock->m_SubstationArray[i].fGenFatctor=(pPGBlock->m_SubstationArray[i].fRunningGenP/fSum);
		}

		//////////////////////////////////////////////////////////////////////////
		//	计算死岛负荷
		pPGBlock->m_System.fDeadIslandLoadP=pPGBlock->m_System.fDeadIslandLoadQ=0;
		for (nIsland=0; nIsland<pPGBlock->m_nRecordNum[PG_ISLAND]; nIsland++)
		{
			if (!pPGBlock->m_IslandArray[nIsland].bDead)
				continue;

			for (i=0; i<pPGBlock->m_nRecordNum[PG_ENERGYCONSUMER]; i++)
			{
				if (pPGBlock->m_EnergyConsumerArray[i].nIsland != nIsland)
					continue;
			}
			pPGBlock->m_System.fDeadIslandLoadP += pPGBlock->m_EnergyConsumerArray[i].fPlanP;
			pPGBlock->m_System.fDeadIslandLoadQ += pPGBlock->m_EnergyConsumerArray[i].fPlanQ;
		}

		//////////////////////////////////////////////////////////////////////////
		//	越限计算
		pPGBlock->m_System.nLineOverLoad = 0;
		pPGBlock->m_System.nLineRate100 = 0;
		pPGBlock->m_System.nLineRate80 = 0;
		pPGBlock->m_System.nLineRate60 = 0;
		pPGBlock->m_System.nLineRate40 = 0;
		pPGBlock->m_System.nLineRate20 = 0;
		pPGBlock->m_System.nLineRate0 = 0;

		pPGBlock->m_System.nTranOverLoad = 0;
		pPGBlock->m_System.nTranRate100 = 0;
		pPGBlock->m_System.nTranRate80 = 0;
		pPGBlock->m_System.nTranRate60 = 0;
		pPGBlock->m_System.nTranRate40 = 0;
		pPGBlock->m_System.nTranRate20 = 0;
		pPGBlock->m_System.nTranRate0 = 0;

		pPGBlock->m_System.fLineOverLoadIdx = pPGBlock->m_System.fTranOverLoadIdx = 0;

		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_ACLINESEGMENT]; nDev++)
		{
			if (pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur < FLT_MIN)
				continue;

			if (pPGBlock->m_ACLineSegmentArray[nDev].fA > pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur)
			{
				pPGBlock->m_System.fLineOverLoadIdx += (pPGBlock->m_ACLineSegmentArray[nDev].fA-pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur)/pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur;
				pPGBlock->m_System.nLineOverLoad++;
			}
			else if (0.8*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur < pPGBlock->m_ACLineSegmentArray[nDev].fA && pPGBlock->m_ACLineSegmentArray[nDev].fA <= pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur)
			{
				pPGBlock->m_System.nLineRate100++;
			}
			else if (0.6*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur < pPGBlock->m_ACLineSegmentArray[nDev].fA && pPGBlock->m_ACLineSegmentArray[nDev].fA <= 0.8*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur)
			{
				pPGBlock->m_System.nLineRate80++;
			}
			else if (0.4*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur < pPGBlock->m_ACLineSegmentArray[nDev].fA && pPGBlock->m_ACLineSegmentArray[nDev].fA <= 0.6*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur)
			{
				pPGBlock->m_System.nLineRate60++;
			}
			else if (0.2*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur < pPGBlock->m_ACLineSegmentArray[nDev].fA && pPGBlock->m_ACLineSegmentArray[nDev].fA <= 0.4*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur)
			{
				pPGBlock->m_System.nLineRate40++;
			}
			else if (FLT_MIN < pPGBlock->m_ACLineSegmentArray[nDev].fA && pPGBlock->m_ACLineSegmentArray[nDev].fA <= 0.2*pPGBlock->m_ACLineSegmentArray[nDev].fRatedCur)
			{
				pPGBlock->m_System.nLineRate20++;
			}
			else
			{
				pPGBlock->m_System.nLineRate0++;
			}
		}
		double	fTranPower;
		
		for (nDev=0; nDev<pPGBlock->m_nRecordNum[PG_TRANSFORMERWINDING]; nDev++)
		{
			if (pPGBlock->m_TransformerWindingArray[nDev].fRatedMva < FLT_MIN)
				continue;
			fTranPower = sqrt(pow(pPGBlock->m_TransformerWindingArray[nDev].fPi, 2)+pow(pPGBlock->m_TransformerWindingArray[nDev].fQi, 2));
			if (fTranPower > pPGBlock->m_TransformerWindingArray[nDev].fRatedMva)
			{
				pPGBlock->m_System.fTranOverLoadIdx += (fTranPower-pPGBlock->m_TransformerWindingArray[nDev].fRatedMva)/pPGBlock->m_TransformerWindingArray[nDev].fRatedMva;
				pPGBlock->m_System.nTranOverLoad++;
			}
			else if (0.8*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva < fTranPower && fTranPower <= pPGBlock->m_TransformerWindingArray[nDev].fRatedMva)
			{
				pPGBlock->m_System.nTranRate100++;
			}
			else if (0.6*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva < fTranPower && fTranPower <= 0.8*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva)
			{
				pPGBlock->m_System.nTranRate80++;
			}
			else if (0.4*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva < fTranPower && fTranPower <= 0.6*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva)
			{
				pPGBlock->m_System.nTranRate60++;
			}
			else if (0.2*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva < fTranPower && fTranPower <= 0.4*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva)
			{
				pPGBlock->m_System.nTranRate40++;
			}
			else if (FLT_MIN < fTranPower && fTranPower <= 0.2*pPGBlock->m_TransformerWindingArray[nDev].fRatedMva)
			{
				pPGBlock->m_System.nTranRate20++;
			}
			else
			{
				pPGBlock->m_System.nTranRate0++;
			}
		}
	}
}
