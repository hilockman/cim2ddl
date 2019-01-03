#include "stdafx.h"
#include "PRMemDB.h"
#include "PRMemDBExtern.h"

#include "../MemDBBase/MemDBHash.h"

namespace	PRMemDB
{
	void	CPRMemDBInterface::FormDerivedDevice(tagPRBlock* pPRBlock)
	{
		clock_t	dBeg, dEnd;
		int		nDur;

		register int	i, j;
		int		la_1, la_2;

		pPRBlock->m_nRecordNum[PR_ACLINEEDGE]=0;
		pPRBlock->m_nRecordNum[PR_WINDEDGE]=0;

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			strcpy(pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].szBus,	pPRBlock->m_ACLineArray[i].szBusI);
			pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].fkV				=pPRBlock->m_ACLineArray[i].fkVI;
			strcpy(pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].szLine,	pPRBlock->m_ACLineArray[i].szName);
			pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].nLine=i;
			pPRBlock->m_nRecordNum[PR_ACLINEEDGE]++;

			strcpy(pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].szBus,	pPRBlock->m_ACLineArray[i].szBusJ);
			pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].fkV				=pPRBlock->m_ACLineArray[i].fkVJ;
			strcpy(pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].szLine,	pPRBlock->m_ACLineArray[i].szName);
			pPRBlock->m_ACLineEdgeArray[pPRBlock->m_nRecordNum[PR_ACLINEEDGE]].nLine=i;
			pPRBlock->m_nRecordNum[PR_ACLINEEDGE]++;
		}
		MemDBBase::MDBSort<tagPRBlock>(pPRBlock, PR_ACLINEEDGE);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("AC母线线路关联关系生成完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			strcpy(pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].szBus,	pPRBlock->m_WindArray[i].szBusI);
			pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].fkV				=pPRBlock->m_WindArray[i].fkVI;
			strcpy(pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].szTran,	pPRBlock->m_WindArray[i].szName);
			pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].nTran=i;
			pPRBlock->m_nRecordNum[PR_WINDEDGE]++;

			strcpy(pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].szBus,	pPRBlock->m_WindArray[i].szBusJ);
			pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].fkV				=pPRBlock->m_WindArray[i].fkVJ;
			strcpy(pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].szTran,	pPRBlock->m_WindArray[i].szName);
			pPRBlock->m_ACWindEdgeArray[pPRBlock->m_nRecordNum[PR_WINDEDGE]].nTran=i;
			pPRBlock->m_nRecordNum[PR_WINDEDGE]++;
		}
		MemDBBase::MDBSort<tagPRBlock>(pPRBlock, PR_WINDEDGE);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("AC母线变压器关联关系生成完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		la_1 = 0;
		la_2 = 0;
		pPRBlock->m_ACBusArray[0].nLineRange = la_1;
		pPRBlock->m_ACBusArray[0].nTranRange = la_2;
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			for (j=la_1; j<pPRBlock->m_nRecordNum[PR_ACLINEEDGE]; j++)
			{
				if (strcmp(pPRBlock->m_ACBusArray[i].szName, pPRBlock->m_ACLineEdgeArray[j].szBus) == 0 &&
					fabs(pPRBlock->m_ACBusArray[i].fkV - pPRBlock->m_ACLineEdgeArray[j].fkV) < 0.1)
				{
					la_1 += 1;
				}
				else
				{
					goto ACLineEdge;
				}
			}
ACLineEdge:			pPRBlock->m_ACBusArray[i+1].nLineRange = la_1;

			for (j=la_2; j<pPRBlock->m_nRecordNum[PR_WINDEDGE]; j++)
			{
				if (strcmp(pPRBlock->m_ACBusArray[i].szName, pPRBlock->m_ACWindEdgeArray[j].szBus) == 0 &&
					fabs(pPRBlock->m_ACBusArray[i].fkV - pPRBlock->m_ACWindEdgeArray[j].fkV) < 0.1)
				{
					la_2 += 1;
				}
				else
				{
					goto WindEdge;
				}
			}
WindEdge:			pPRBlock->m_ACBusArray[i+1].nTranRange = la_2;
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("AC母线设备关联关系计算完毕，耗时%d毫秒\n", nDur);

		if (pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nLineRange != pPRBlock->m_nRecordNum[PR_ACLINEEDGE])
			PRMemDBLog("AC母线线路关联关系错误 最大索引=%d 母线数=%d\n", pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nLineRange, pPRBlock->m_nRecordNum[PR_ACLINEEDGE]);
		if (pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nTranRange != pPRBlock->m_nRecordNum[PR_WINDEDGE])
			PRMemDBLog("AC母线变压器关联关系错误 最大索引=%d 母线数=%d\n", pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nTranRange, pPRBlock->m_nRecordNum[PR_WINDEDGE]);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("增广设备信息计算完毕，耗时%d毫秒\n", nDur);
	}

	void	CPRMemDBInterface::PRMaint(tagPRBlock* pPRBlock)
	{
		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();
		MemDBBase::MDBSort<tagPRBlock>(pPRBlock, -1);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("MDBSort完毕，耗时%d毫秒\n", nDur);

		register int	i;
		char	szVolt[MDB_CHARLEN_SHORT];

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=1; i<pPRBlock->m_nRecordNum[PR_RADIAL]; i++)
		{
			pPRBlock->m_RadialArray[i].nRingBoundBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_RadialArray[i].szRingBus, szVolt);
			if (pPRBlock->m_RadialArray[i].nRingBoundBus <= 0)
				PRMemDBLog("环辐网母线错误，[%d/%d] = %s\n", i, pPRBlock->m_nRecordNum[PR_RADIAL], pPRBlock->m_RadialArray[i].szRingBus);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("辐射网环网母线索引计算完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_GeneratorArray[i].fkV);
			pPRBlock->m_GeneratorArray[i].nBusIndex=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_GeneratorArray[i].szBus, szVolt);
			if (pPRBlock->m_GeneratorArray[i].nBusIndex <= 0)
				PRMemDBLog("发电机母线错误，[%d/%d] = %s\n", i, pPRBlock->m_nRecordNum[PR_GENERATOR], pPRBlock->m_GeneratorArray[i].szName);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_POWERLOAD]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_PowerLoadArray[i].fkV);
			pPRBlock->m_PowerLoadArray[i].nBusIndex=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_PowerLoadArray[i].szBus, szVolt);
			if (pPRBlock->m_PowerLoadArray[i].nBusIndex <= 0)
				PRMemDBLog("负荷母线错误，[%d/%d] = %s\n", i, pPRBlock->m_nRecordNum[PR_POWERLOAD], pPRBlock->m_PowerLoadArray[i].szName);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_ACLineArray[i].fkVI);
			pPRBlock->m_ACLineArray[i].nIBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_ACLineArray[i].szBusI, szVolt);
			if (pPRBlock->m_ACLineArray[i].nIBus <= 0)
				PRMemDBLog("AC线路I母线错误， %s - %s\n", pPRBlock->m_ACLineArray[i].szName, pPRBlock->m_ACLineArray[i].szBusI);

			sprintf	(szVolt, "%f", pPRBlock->m_ACLineArray[i].fkVJ);
			pPRBlock->m_ACLineArray[i].nZBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_ACLineArray[i].szBusJ, szVolt);
			if (pPRBlock->m_ACLineArray[i].nIBus <= 0)
				PRMemDBLog("AC线路Z母线错误， %s - %s\n", pPRBlock->m_ACLineArray[i].szName, pPRBlock->m_ACLineArray[i].szBusJ);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_WindArray[i].fkVI);
			pPRBlock->m_WindArray[i].nIBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_WindArray[i].szBusI, szVolt);
			if (pPRBlock->m_WindArray[i].nIBus <= 0)
				PRMemDBLog("变压器I母线错误， %s - %s\n", pPRBlock->m_WindArray[i].szName, pPRBlock->m_WindArray[i].szBusI);

			sprintf	(szVolt, "%f", pPRBlock->m_WindArray[i].fkVJ);
			pPRBlock->m_WindArray[i].nZBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_WindArray[i].szBusJ, szVolt);
			if (pPRBlock->m_WindArray[i].nZBus <= 0)
				PRMemDBLog("变压器Z母线错误， %s - %s\n", pPRBlock->m_WindArray[i].szName, pPRBlock->m_WindArray[i].szBusJ);
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_HVDCArray[i].fkVR);
			pPRBlock->m_HVDCArray[i].nRBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_HVDCArray[i].szACBusR, szVolt);
			if (pPRBlock->m_HVDCArray[i].nRBus <= 0)
				PRMemDBLog("直流系统整流母线错误， %s - %s\n", pPRBlock->m_HVDCArray[i].szName, pPRBlock->m_HVDCArray[i].szACBusR);

			sprintf	(szVolt, "%f", pPRBlock->m_HVDCArray[i].fkVI);
			pPRBlock->m_HVDCArray[i].nIBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_HVDCArray[i].szACBusI, szVolt);
			if (pPRBlock->m_HVDCArray[i].nIBus <= 0)
				PRMemDBLog("直流系统逆变母线错误， %s - %s\n", pPRBlock->m_HVDCArray[i].szName, pPRBlock->m_HVDCArray[i].szACBusI);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("设备的母线索引计算完毕，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=0; i<pPRBlock->m_nRecordNum[PR_DEVMSTATE]; i++)
		{
			pPRBlock->m_DevMStateArray[i].nIndex=-1;
			switch (pPRBlock->m_DevMStateArray[i].nType)
			{
			case	PR_HVDC:
			case	PR_GENERATOR:
			case	PR_POWERLOAD:
				pPRBlock->m_DevMStateArray[i].nIndex=PRFindRecordbyKey(pPRBlock, pPRBlock->m_DevMStateArray[i].nType, pPRBlock->m_DevMStateArray[i].szName);
				break;
			}
			if (pPRBlock->m_DevMStateArray[i].nIndex < 0)
				PRMemDBLog("多状态模型设备索引错误，[%d/%d] = Type=%d Name=%s\n", i, pPRBlock->m_nRecordNum[PR_DEVMSTATE], pPRBlock->m_DevMStateArray[i].nType, pPRBlock->m_DevMStateArray[i].szName);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("多状态模型设备索引计算完毕，耗时%d毫秒\n", nDur);

		FormDerivedDevice(pPRBlock);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("故障状态信息关联关系计算完毕，耗时%d毫秒\n", nDur);
	}
}
