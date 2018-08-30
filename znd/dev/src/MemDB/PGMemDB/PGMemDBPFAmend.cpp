#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace PGMemDB 
{
	void	PGPfloCheckTran(tagPGBlock* pPGBlock)
	{
		int	nSub, nDev;

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			for (nDev=pPGBlock->m_SubstationArray[nSub].nTransformerWindingRange; nDev<pPGBlock->m_SubstationArray[nSub+1].nTransformerWindingRange; nDev++)
			{
				if (pPGBlock->m_TransformerWindingArray[nDev].nTapI > pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMax)
					pPGBlock->m_TransformerWindingArray[nDev].nTapI=pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMax;
				if (pPGBlock->m_TransformerWindingArray[nDev].nTapI < pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMin)
					pPGBlock->m_TransformerWindingArray[nDev].nTapI=pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerI].nTapMin;
				if (pPGBlock->m_TransformerWindingArray[nDev].nTapJ > pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMax)
					pPGBlock->m_TransformerWindingArray[nDev].nTapJ=pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMax;
				if (pPGBlock->m_TransformerWindingArray[nDev].nTapJ < pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMin)
					pPGBlock->m_TransformerWindingArray[nDev].nTapJ=pPGBlock->m_TapChangerArray[pPGBlock->m_TransformerWindingArray[nDev].nTapChangerJ].nTapMin;
			}
		}
	}

	void	PGPfloCheckUnit(tagPGBlock* pPGBlock)
	{
		int	nSub, nVolt, nDev;

		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			//if (pPGBlock->m_SubstationArray[nSub].st_type == st_type_Plant_Outnet)
			//	continue;
			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (nDev=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; nDev<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; nDev++)
				{
					if (pPGBlock->m_SynchronousMachineArray[nDev].bOutage != 0)
						continue;
					if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanP < 0.1 && pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ < 0.1)
						continue;

					if ((pPGBlock->m_SynchronousMachineArray[nDev].fPlanV > 1.2 || pPGBlock->m_SynchronousMachineArray[nDev].fPlanV < 0.8) && pPGBlock->m_SynchronousMachineArray[nDev].fPlanV != 0)
						pPGBlock->m_SynchronousMachineArray[nDev].fPlanV = 0;

					if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ > pPGBlock->m_SynchronousMachineArray[nDev].fQMax)
						pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ = pPGBlock->m_SynchronousMachineArray[nDev].fQMax;
					if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ < pPGBlock->m_SynchronousMachineArray[nDev].fQMin)
						pPGBlock->m_SynchronousMachineArray[nDev].fPlanQ = pPGBlock->m_SynchronousMachineArray[nDev].fQMin;
					if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanP > pPGBlock->m_SynchronousMachineArray[nDev].fPMax)
						pPGBlock->m_SynchronousMachineArray[nDev].fPlanP = pPGBlock->m_SynchronousMachineArray[nDev].fPMax;
					if (pPGBlock->m_SynchronousMachineArray[nDev].fPlanP < pPGBlock->m_SynchronousMachineArray[nDev].fPMin)
						pPGBlock->m_SynchronousMachineArray[nDev].fPlanP = pPGBlock->m_SynchronousMachineArray[nDev].fPMin;
				}
			}
		}
	}

	void	SetSlackUnit(tagPGBlock* pPGBlock, const int nCorp)
	{
		register int	i;
		int		nSub, nVolt;
		float	fMax;
		int		nMax;

		fMax=-1;
		nMax=-1;
		for (nSub=0; nSub<pPGBlock->m_nRecordNum[PG_SUBSTATION]; nSub++)
		{
			if (nCorp >= 0)
			{
				if (strcmp(pPGBlock->m_SubstationArray[nSub].szCompany, pPGBlock->m_CompanyArray[nCorp].szName) != 0)
					continue;
			}

			for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
			{
				for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
				{
					if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
						continue;
					if (pPGBlock->m_SynchronousMachineArray[i].bOutage != 0)
						continue;

					if (fMax < pPGBlock->m_SynchronousMachineArray[i].fPMax &&
						sqrt(pPGBlock->m_SynchronousMachineArray[i].fPlanP*pPGBlock->m_SynchronousMachineArray[i].fPlanP+pPGBlock->m_SynchronousMachineArray[i].fPlanQ*pPGBlock->m_SynchronousMachineArray[i].fPlanQ) > 1)
					{
						nMax=i;
						fMax=pPGBlock->m_SynchronousMachineArray[nMax].fPMax;
					}
				}
			}
		}
		if (nMax >= 0)
		{
			if (pPGBlock->m_SynchronousMachineArray[nMax].fPlanV < 0.5)
				pPGBlock->m_SynchronousMachineArray[nMax].fPlanV=1;
			if (nCorp >= 0)
			{
				strcpy(pPGBlock->m_CompanyArray[nCorp].szSlackSub, pPGBlock->m_SynchronousMachineArray[nMax].szSub);
				strcpy(pPGBlock->m_CompanyArray[nCorp].szSlackGen, pPGBlock->m_SynchronousMachineArray[nMax].szName);
			}
			else
			{
				strcpy(pPGBlock->m_System.szSlackSub, pPGBlock->m_SynchronousMachineArray[nMax].szSub);
				strcpy(pPGBlock->m_System.szSlackGen, pPGBlock->m_SynchronousMachineArray[nMax].szName);
			}
		}
	}

	int	PGMemDBPFAmend(tagPGBlock* pPGBlock)
	{
		register int	i;
		int				nCorp, nSub, nVolt, nUnit;
		char			szBuf[260];
		char			szMesg[1024];
		int				nPVNode;

		if (pPGBlock->m_System.fBasePower == 0)
			pPGBlock->m_System.fBasePower=100;

		PGPfloCheckTran(pPGBlock);	//	检查变压器分接头情况，防止变压器分接头越限
		PGPfloCheckUnit(pPGBlock);	//	检查发电机功率和PV值情况

		//	确保各个网内有PV节点
		for (nCorp=0; nCorp<pPGBlock->m_nRecordNum[PG_COMPANY]; nCorp++)
		{
			nSub=PGFindRecordbyKey(pPGBlock, PG_SUBSTATION, pPGBlock->m_CompanyArray[nCorp].szSlackSub);
			if (nSub < 0)	//	如果区域平衡机厂站不存在，则在全网中搜索最大发电厂
			{
				SetSlackUnit(pPGBlock, nCorp);
			}
			else		
			{
				nUnit=-1;
				for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
				{
					for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
					{
						if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
							continue;
						if (pPGBlock->m_SynchronousMachineArray[i].bOutage != 0)
							continue;

						if (strcmp(pPGBlock->m_CompanyArray[nCorp].szSlackGen, pPGBlock->m_SynchronousMachineArray[i].szName) == 0 &&
							pPGBlock->m_SynchronousMachineArray[i].fPlanP*pPGBlock->m_SynchronousMachineArray[i].fPlanP+pPGBlock->m_SynchronousMachineArray[i].fPlanQ*pPGBlock->m_SynchronousMachineArray[i].fPlanQ > 1)
						{
							nUnit=i;
							break;
						}
					}
					if (nUnit >= 0)
						break;
				}
				if (nUnit < 0)	//	在本厂内找最大的发电机
				{
					float	fSubMax=-1;
					int		nSubMax=-1;
					for (nVolt=pPGBlock->m_SubstationArray[nSub].nVoltageLevelRange; nVolt<pPGBlock->m_SubstationArray[nSub+1].nVoltageLevelRange; nVolt++)
					{
						for (i=pPGBlock->m_VoltageLevelArray[nVolt].nSynchronousMachineRange; i<pPGBlock->m_VoltageLevelArray[nVolt+1].nSynchronousMachineRange; i++)
						{
							if (pPGBlock->m_SynchronousMachineArray[i].nNode < 0)
								continue;
							if (pPGBlock->m_SynchronousMachineArray[i].bOutage != 0)
								continue;

							if (pPGBlock->m_SynchronousMachineArray[i].fPlanP*pPGBlock->m_SynchronousMachineArray[i].fPlanP+pPGBlock->m_SynchronousMachineArray[i].fPlanQ*pPGBlock->m_SynchronousMachineArray[i].fPlanQ <= 1 || pPGBlock->m_SynchronousMachineArray[i].fPMax < 100)
								continue;

							if (fSubMax < pPGBlock->m_SynchronousMachineArray[i].fPMax)
							{
								fSubMax=pPGBlock->m_SynchronousMachineArray[i].fPMax;
								nSubMax=i;
							}
						}
					}
					if (nSubMax >= 0)
					{
						strcpy(pPGBlock->m_CompanyArray[nCorp].szSlackSub, pPGBlock->m_SynchronousMachineArray[nSubMax].szSub);
						strcpy(pPGBlock->m_CompanyArray[nCorp].szSlackGen, pPGBlock->m_SynchronousMachineArray[nSubMax].szName);
						if (pPGBlock->m_SynchronousMachineArray[nSubMax].fPlanV < 0.5)
							pPGBlock->m_SynchronousMachineArray[nSubMax].fPlanV=1;
					}
					else	//	如果本厂全停，找本网最大发电机
					{
						SetSlackUnit(pPGBlock, nCorp);
					}
					//	如果区域平衡机发电机不存在，则在全网中搜索最大发电机
				}
				else
				{
					if (pPGBlock->m_SynchronousMachineArray[nUnit].fPlanV < 0.5)
						pPGBlock->m_SynchronousMachineArray[nUnit].fPlanV=1;
				}
			}
		}
		strcpy(pPGBlock->m_System.szSlackSub, pPGBlock->m_CompanyArray[0].szSlackSub);
		strcpy(pPGBlock->m_System.szSlackGen, pPGBlock->m_CompanyArray[0].szSlackGen);

		nPVNode=0;
		for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
		{
			if (pPGBlock->m_SynchronousMachineArray[i].fPlanV < 0.5)
				continue;

			if (pPGBlock->m_SynchronousMachineArray[i].fPlanV < 0.8 || pPGBlock->m_SynchronousMachineArray[i].fPlanV > 1.2)
			{
				sprintf(szBuf, "请检查发电机PV值: %s-%s\r\n", pPGBlock->m_SynchronousMachineArray[i].szSub, pPGBlock->m_SynchronousMachineArray[i].szName);
				strcat(szMesg, szBuf);
			}
			else
			{
				nPVNode++;
			}
		}
		if (nPVNode == 0)
		{
			for (i=0; i<pPGBlock->m_nRecordNum[PG_SYNCHRONOUSMACHINE]; i++)
			{
				if (pPGBlock->m_SynchronousMachineArray[i].fPMax > 100)
					pPGBlock->m_SynchronousMachineArray[i].fPlanV=1;
			}
		}

		int	nRet=(strlen(szMesg) > 0) ? 0 : 1;

		return nRet;
	}
}