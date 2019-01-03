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
		PRMemDBLog("ACĸ����·������ϵ������ϣ���ʱ%d����\n", nDur);

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
		PRMemDBLog("ACĸ�߱�ѹ��������ϵ������ϣ���ʱ%d����\n", nDur);

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
		PRMemDBLog("ACĸ���豸������ϵ������ϣ���ʱ%d����\n", nDur);

		if (pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nLineRange != pPRBlock->m_nRecordNum[PR_ACLINEEDGE])
			PRMemDBLog("ACĸ����·������ϵ���� �������=%d ĸ����=%d\n", pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nLineRange, pPRBlock->m_nRecordNum[PR_ACLINEEDGE]);
		if (pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nTranRange != pPRBlock->m_nRecordNum[PR_WINDEDGE])
			PRMemDBLog("ACĸ�߱�ѹ��������ϵ���� �������=%d ĸ����=%d\n", pPRBlock->m_ACBusArray[pPRBlock->m_nRecordNum[PR_ACBUS]].nTranRange, pPRBlock->m_nRecordNum[PR_WINDEDGE]);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("�����豸��Ϣ������ϣ���ʱ%d����\n", nDur);
	}

	void	CPRMemDBInterface::PRMaint(tagPRBlock* pPRBlock)
	{
		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();
		MemDBBase::MDBSort<tagPRBlock>(pPRBlock, -1);
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("MDBSort��ϣ���ʱ%d����\n", nDur);

		register int	i;
		char	szVolt[MDB_CHARLEN_SHORT];

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=1; i<pPRBlock->m_nRecordNum[PR_RADIAL]; i++)
		{
			pPRBlock->m_RadialArray[i].nRingBoundBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_RadialArray[i].szRingBus, szVolt);
			if (pPRBlock->m_RadialArray[i].nRingBoundBus <= 0)
				PRMemDBLog("������ĸ�ߴ���[%d/%d] = %s\n", i, pPRBlock->m_nRecordNum[PR_RADIAL], pPRBlock->m_RadialArray[i].szRingBus);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("����������ĸ������������ϣ���ʱ%d����\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		dBeg=clock();
		for (i=0; i<pPRBlock->m_nRecordNum[PR_GENERATOR]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_GeneratorArray[i].fkV);
			pPRBlock->m_GeneratorArray[i].nBusIndex=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_GeneratorArray[i].szBus, szVolt);
			if (pPRBlock->m_GeneratorArray[i].nBusIndex <= 0)
				PRMemDBLog("�����ĸ�ߴ���[%d/%d] = %s\n", i, pPRBlock->m_nRecordNum[PR_GENERATOR], pPRBlock->m_GeneratorArray[i].szName);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_POWERLOAD]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_PowerLoadArray[i].fkV);
			pPRBlock->m_PowerLoadArray[i].nBusIndex=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_PowerLoadArray[i].szBus, szVolt);
			if (pPRBlock->m_PowerLoadArray[i].nBusIndex <= 0)
				PRMemDBLog("����ĸ�ߴ���[%d/%d] = %s\n", i, pPRBlock->m_nRecordNum[PR_POWERLOAD], pPRBlock->m_PowerLoadArray[i].szName);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_ACLineArray[i].fkVI);
			pPRBlock->m_ACLineArray[i].nIBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_ACLineArray[i].szBusI, szVolt);
			if (pPRBlock->m_ACLineArray[i].nIBus <= 0)
				PRMemDBLog("AC��·Iĸ�ߴ��� %s - %s\n", pPRBlock->m_ACLineArray[i].szName, pPRBlock->m_ACLineArray[i].szBusI);

			sprintf	(szVolt, "%f", pPRBlock->m_ACLineArray[i].fkVJ);
			pPRBlock->m_ACLineArray[i].nZBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_ACLineArray[i].szBusJ, szVolt);
			if (pPRBlock->m_ACLineArray[i].nIBus <= 0)
				PRMemDBLog("AC��·Zĸ�ߴ��� %s - %s\n", pPRBlock->m_ACLineArray[i].szName, pPRBlock->m_ACLineArray[i].szBusJ);
		}
		for (i=0; i<pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_WindArray[i].fkVI);
			pPRBlock->m_WindArray[i].nIBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_WindArray[i].szBusI, szVolt);
			if (pPRBlock->m_WindArray[i].nIBus <= 0)
				PRMemDBLog("��ѹ��Iĸ�ߴ��� %s - %s\n", pPRBlock->m_WindArray[i].szName, pPRBlock->m_WindArray[i].szBusI);

			sprintf	(szVolt, "%f", pPRBlock->m_WindArray[i].fkVJ);
			pPRBlock->m_WindArray[i].nZBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_WindArray[i].szBusJ, szVolt);
			if (pPRBlock->m_WindArray[i].nZBus <= 0)
				PRMemDBLog("��ѹ��Zĸ�ߴ��� %s - %s\n", pPRBlock->m_WindArray[i].szName, pPRBlock->m_WindArray[i].szBusJ);
		}

		for (i=0; i<pPRBlock->m_nRecordNum[PR_HVDC]; i++)
		{
			sprintf	(szVolt, "%f", pPRBlock->m_HVDCArray[i].fkVR);
			pPRBlock->m_HVDCArray[i].nRBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_HVDCArray[i].szACBusR, szVolt);
			if (pPRBlock->m_HVDCArray[i].nRBus <= 0)
				PRMemDBLog("ֱ��ϵͳ����ĸ�ߴ��� %s - %s\n", pPRBlock->m_HVDCArray[i].szName, pPRBlock->m_HVDCArray[i].szACBusR);

			sprintf	(szVolt, "%f", pPRBlock->m_HVDCArray[i].fkVI);
			pPRBlock->m_HVDCArray[i].nIBus=PRFindRecordbyKey(pPRBlock, PR_ACBUS, pPRBlock->m_HVDCArray[i].szACBusI, szVolt);
			if (pPRBlock->m_HVDCArray[i].nIBus <= 0)
				PRMemDBLog("ֱ��ϵͳ���ĸ�ߴ��� %s - %s\n", pPRBlock->m_HVDCArray[i].szName, pPRBlock->m_HVDCArray[i].szACBusI);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("�豸��ĸ������������ϣ���ʱ%d����\n", nDur);

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
				PRMemDBLog("��״̬ģ���豸��������[%d/%d] = Type=%d Name=%s\n", i, pPRBlock->m_nRecordNum[PR_DEVMSTATE], pPRBlock->m_DevMStateArray[i].nType, pPRBlock->m_DevMStateArray[i].szName);
		}
		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("��״̬ģ���豸����������ϣ���ʱ%d����\n", nDur);

		FormDerivedDevice(pPRBlock);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		PRMemDBLog("����״̬��Ϣ������ϵ������ϣ���ʱ%d����\n", nDur);
	}
}
