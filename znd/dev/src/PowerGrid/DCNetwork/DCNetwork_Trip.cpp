#include "StdAfx.h"
#include "DCNetwork.h"

namespace	DCNetwork
{
	void CDCNetwork::PRDCTrip(tagPRBlock* pPRBlock, const int nDevType, const char* lpszDevName)
	{
		// TODO: 在此添加控件通知处理程序代码
		register int	i;
		int		nReturn,nBran;
		int		nIsland;
		unsigned char	bTriped;
		double	fTrRate;

		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			pPRBlock->m_ACLineArray[nBran].bOutage=0;
		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			pPRBlock->m_WindArray[nBran].bOutage=0;

		bTriped=0;
		switch (nDevType)
		{
		case	0:
			for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
			{
				if (stricmp(pPRBlock->m_ACLineArray[i].szName, lpszDevName) == 0)
				{
					pPRBlock->m_ACLineArray[i].bOutage=1;
					bTriped=1;
					Log(g_lpszLogFile, "开断[%d/%d]    %s\n", i+1, pPRBlock->m_nRecordNum[PR_ACLINE], pPRBlock->m_ACLineArray[i].szName);
					break;
				}
			}
			break;
		case	1:
			for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
			{
				if (stricmp(pPRBlock->m_WindArray[i].szName, lpszDevName) == 0)
				{
					pPRBlock->m_WindArray[i].bOutage=1;
					bTriped=1;
					Log(g_lpszLogFile, "开断[%d/%d]    %s\n", i+1, pPRBlock->m_nRecordNum[PR_WIND], pPRBlock->m_WindArray[i].szName);
					break;
				}
			}
			break;
		default:
			return;
		}

		if (!bTriped)
			return;

		PRMemDBIsland(pPRBlock);
		for (nIsland=1; nIsland<pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
		{
			if (pPRBlock->m_ACIslandArray[nIsland].bDead)
				continue;
			PRDCFlow(pPRBlock, 0, nIsland);
		}
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			if (pPRBlock->m_ACBusArray[i].nIsland == 0)
				continue;
			nReturn=_fpclass(pPRBlock->m_ACBusArray[i].fPfD);
			if (nReturn == _FPCLASS_SNAN ||
				nReturn == _FPCLASS_QNAN ||
				nReturn == _FPCLASS_NINF ||
				nReturn == _FPCLASS_PINF)
				Log(g_lpszLogFile, "        %s %f\n",pPRBlock->m_ACBusArray[i].szName, pPRBlock->m_ACBusArray[i].fPfD);
		}

		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; i++)
		{
			if (pPRBlock->m_ACLineArray[i].nIsland == 0 || pPRBlock->m_ACLineArray[i].bOutage)
				continue;

			fTrRate=0;
			if (fabs(pPRBlock->m_ACLineArray[i].fRated) > 0)
				fTrRate=120*fabs(pPRBlock->m_ACLineArray[i].fTrPi)/pPRBlock->m_ACLineArray[i].fRated;
			if (fTrRate >= 100)
				Log(g_lpszLogFile, "        过负荷%s %f\n",pPRBlock->m_ACLineArray[i].szName, fTrRate);
		}
		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_WIND]; i++)
		{
			if (pPRBlock->m_WindArray[i].nIsland == 0 || pPRBlock->m_WindArray[i].bOutage)
				continue;
			if (pPRBlock->m_WindArray[i].bGenTran)
				continue;

			fTrRate=0;
			if (fabs(pPRBlock->m_WindArray[i].fRated) > 0)
				fTrRate=120*fabs(pPRBlock->m_WindArray[i].fTrPi)/pPRBlock->m_WindArray[i].fRated;

			if (fTrRate >= 100)
				Log(g_lpszLogFile, "        过负荷%s %f\n",pPRBlock->m_WindArray[i].szName, fTrRate);
		}
		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			pPRBlock->m_ACLineArray[nBran].bOutage=0;
		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			pPRBlock->m_WindArray[nBran].bOutage=0;
	}

	void CDCNetwork::PRDCTrip(tagPRBlock* pPRBlock, const int nDevType, const int nDevIndex)
	{
		// TODO: 在此添加控件通知处理程序代码
		register int	i;
		int		nReturn,nBran;
		int		nIsland;

		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			pPRBlock->m_ACLineArray[nBran].bOutage=0;
		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			pPRBlock->m_WindArray[nBran].bOutage=0;

		switch (nDevType)
		{
		case	0:
			pPRBlock->m_ACLineArray[nDevIndex].bOutage=1;
			Log(g_lpszLogFile, "开断[%d/%d]    %s\n", nDevIndex+1, pPRBlock->m_nRecordNum[PR_ACLINE], pPRBlock->m_ACLineArray[nDevIndex].szName);
			break;
		case	1:
			pPRBlock->m_WindArray[nDevIndex].bOutage=1;
			Log(g_lpszLogFile, "开断[%d/%d]    %s\n", nDevIndex+1, pPRBlock->m_nRecordNum[PR_WIND], pPRBlock->m_WindArray[nDevIndex].szName);
			break;
		default:
			return;
		}

		PRMemDBIsland(pPRBlock);
		for (nIsland=1; nIsland<pPRBlock->m_nRecordNum[PR_ACISLAND]; nIsland++)
			PRDCFlow(pPRBlock, 0, nIsland);

		for (i=0; i<(int)pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			if (pPRBlock->m_ACBusArray[i].nIsland == 0)
				continue;
			nReturn=_fpclass(pPRBlock->m_ACBusArray[i].fPfD);
			if (nReturn == _FPCLASS_SNAN ||
				nReturn == _FPCLASS_QNAN ||
				nReturn == _FPCLASS_NINF ||
				nReturn == _FPCLASS_PINF)
				Log(g_lpszLogFile, "        %s %f\n",pPRBlock->m_ACBusArray[i].szName, pPRBlock->m_ACBusArray[i].fPfD);
		}

		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_ACLINE]; nBran++)
			pPRBlock->m_ACLineArray[nBran].bOutage=0;
		for (nBran=0; nBran<(int)pPRBlock->m_nRecordNum[PR_WIND]; nBran++)
			pPRBlock->m_WindArray[nBran].bOutage=0;
	}
}
