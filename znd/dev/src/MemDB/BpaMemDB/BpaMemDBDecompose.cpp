#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	std::vector<tagBpaRadiate>	m_RadiateArray;
	void	FormRadiate(tagBpaBlock* pBpaBlock, const double fOpenRingVolt, const double fTinyGenMva, const int nBoundBus, tagBpaRadiate& bndBuffer)
	{
		register int	i;
		int		nBus;
		double	fIslandGen;
		std::vector<unsigned char>	bProcArray;
		int		nBusNum, *nBusArray;

		nBusArray=(int*)malloc(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]*sizeof(int));
		if (nBusArray == NULL)
			return;

		bndBuffer.nBoundBus=nBoundBus;
		bndBuffer.fGenP=0;
		bndBuffer.fLoadP=0;
		bndBuffer.fLoadQ=0;
		bndBuffer.nBusArray.clear();

		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bProcArray.size(); i++)
		{
			bProcArray[i]=0;
			if (pBpaBlock->m_BpaDat_ACBusArray[i].nACIsland == 0)
				bProcArray[i]=1;
		}

		pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].nStatus=1;

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (nBus == nBoundBus || bProcArray[nBus])
				continue;

			BpaTraverseNet(pBpaBlock, nBus, 0, nBusNum, nBusArray);

			fIslandGen=0;
			for (i=0; i<nBusNum; i++)
			{
				bProcArray[nBusArray[i]]=1;
				if (pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fkV > fOpenRingVolt)
				{
					if (pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bGenerator != 0 &&
						(pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fPmax > fTinyGenMva || pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fPGen > fTinyGenMva))
						fIslandGen += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fPGen;
					if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].szCardKey, "BS") == 0 || pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].bDCBound != 0)
						fIslandGen += 1000;
					//else if (pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]+1].pRHG-pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].pRHG > 0)
					//fIslandGen += 100;
				}

				if (fIslandGen > FLT_MIN)
					break;
			}

			if (fIslandGen < FLT_MIN)
			{
				for (i=0; i<nBusNum; i++)
				{
					if (nBusArray[i] == nBoundBus)
						continue;
					bndBuffer.fLoadP += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadP;
					bndBuffer.fLoadQ += pBpaBlock->m_BpaDat_ACBusArray[nBusArray[i]].fLoadQ;
					bndBuffer.nBusArray.push_back(nBusArray[i]);
				}
			}
		}

		pBpaBlock->m_BpaDat_ACBusArray[nBoundBus].nStatus=0;

		if (nBusArray)
		{
			free(nBusArray);
			nBusArray=NULL;
		}
	}

	int InRadiate(tagBpaBlock* pBpaBlock, const int nCheckBus)
	{
		register int	i;
		int	nRadiate;

		for (nRadiate=0; nRadiate<(int)m_RadiateArray.size(); nRadiate++)
		{
			for (i=0; i<(int)m_RadiateArray[nRadiate].nBusArray.size(); i++)
			{
				if (m_RadiateArray[nRadiate].nBusArray[i] == nCheckBus)
					return 1;
			}
		}
		return 0;
	}

	void BpaRingRadDecompose(tagBpaBlock* pBpaBlock, const double fOpenRingVolt, const double fTinyGenMva)
	{
		register int	i, j;
		int				nBus;
		unsigned char	bFlag;
		tagBpaRadiate	rBuffer;
		std::vector<unsigned char>	bProcArray;

		clock_t	dBeg, dEnd;
		int		nDur;

		dBeg=clock();

		m_RadiateArray.clear();

		BpaIsland(pBpaBlock);

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "电岛完成，耗时%d毫秒\n",  nDur);

		//////////////////////////////////////////////////////////////////////////
		//	辐射网判断流程
		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i]=0;
		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV <= fOpenRingVolt)
				continue;

			//if (nBus % 1000 == 0)
			//{
			//	dEnd=clock();
			//	nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
			//	Log(g_lpszLogFile, "辐射网判断[%d/%d]完成，耗时%d毫秒\n", nBus, pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS], nDur);
			//}

			if (bProcArray[nBus])
				continue;
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nACLineRange-pBpaBlock->m_BpaDat_ACBusArray[nBus].nACLineRange+pBpaBlock->m_BpaDat_ACBusArray[nBus+1].nWindRange-pBpaBlock->m_BpaDat_ACBusArray[nBus].nWindRange <= 1)
				continue;
			if (InRadiate(pBpaBlock, nBus))
				continue;

			FormRadiate(pBpaBlock, fOpenRingVolt, fTinyGenMva, nBus, rBuffer);
			if (!rBuffer.nBusArray.empty())
			{
				m_RadiateArray.push_back(rBuffer);
				for (i=0; i<(int)rBuffer.nBusArray.size(); i++)
					bProcArray[rBuffer.nBusArray[i]]=1;
			}
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "辐射网判断完成，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	辐射网合并流程
		nBus=0;
		while (nBus < (int)m_RadiateArray.size())
		{
			bFlag=0;
			for (i=nBus+1; i<(int)m_RadiateArray.size(); i++)
			{
				for (j=0; j<(int)m_RadiateArray[i].nBusArray.size(); j++)
				{
					if (m_RadiateArray[nBus].nBoundBus == m_RadiateArray[i].nBusArray[j])
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					break;
			}

			if (bFlag)
				m_RadiateArray.erase(m_RadiateArray.begin()+nBus);
			else
				nBus++;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "Decompose分析耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	形成辐射网设备
		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
			pBpaBlock->m_BpaDat_ACBusArray[nBus].bInRing=1;
		for (nBus=0; nBus<(int)m_RadiateArray.size(); nBus++)
		{
			m_RadiateArray[nBus].nLineArray.clear();
			m_RadiateArray[nBus].nWindArray.clear();

			for (i=0; i<(int)m_RadiateArray[nBus].nBusArray.size(); i++)
			{
				if (m_RadiateArray[nBus].nBusArray[i] == m_RadiateArray[nBus].nBoundBus)
					continue;

				for (j=pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]].nACLineRange; j<pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]+1].nACLineRange; j++)
					m_RadiateArray[nBus].nLineArray.push_back(pBpaBlock->m_BpaDat_EdgeLineArray[j].iRLine);
				for (j=pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]].nWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]+1].nWindRange; j++)
					m_RadiateArray[nBus].nWindArray.push_back(pBpaBlock->m_BpaDat_EdgeWindArray[j].iRWind);
				pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]].bInRing=0;
			}
			pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBoundBus].bInRing=2;

			i=0;
			while (i < (int)m_RadiateArray[nBus].nLineArray.size())
			{
				bFlag=0;
				for (j=i+1; j<(int)m_RadiateArray[nBus].nLineArray.size(); j++)
				{
					if (m_RadiateArray[nBus].nLineArray[i] == m_RadiateArray[nBus].nLineArray[j])
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					m_RadiateArray[nBus].nLineArray.erase(m_RadiateArray[nBus].nLineArray.begin()+i);
				else
					i++;
			}

			i=0;
			while (i < (int)m_RadiateArray[nBus].nWindArray.size())
			{
				bFlag=0;
				for (j=i+1; j<(int)m_RadiateArray[nBus].nWindArray.size(); j++)
				{
					if (m_RadiateArray[nBus].nWindArray[i] == m_RadiateArray[nBus].nWindArray[j])
					{
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					m_RadiateArray[nBus].nWindArray.erase(m_RadiateArray[nBus].nWindArray.begin()+i);
				else
					i++;
			}
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "合并辐射网完成，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	形成环网信息
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
		{
			pBpaBlock->m_BpaDat_ACLineArray[i].bInRing=0;
			if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[i].nIBus].bInRing && pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[i].nZBus].bInRing)
				pBpaBlock->m_BpaDat_ACLineArray[i].bInRing=1;
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		{
			pBpaBlock->m_BpaDat_WindArray[i].bInRing=0;
			if (pBpaBlock->m_BpaDat_WindArray[i].bRCard || (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].bInRing && pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].bInRing))
				pBpaBlock->m_BpaDat_WindArray[i].bInRing=1;
		}

		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
		{
			pBpaBlock->m_BpaDat_LineHGArray[i].bInRing=0;
			if (pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_LineHGArray[i].nIBus].bInRing && pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_LineHGArray[i].nZBus].bInRing)
				pBpaBlock->m_BpaDat_LineHGArray[i].bInRing=1;
		}

		//////////////////////////////////////////////////////////////////////////
		//	辐射网填库
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].nRadiate=0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			pBpaBlock->m_BpaDat_ACLineArray[i].nRadiate=0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			pBpaBlock->m_BpaDat_WindArray[i].nRadiate=0;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
			pBpaBlock->m_BpaDat_LineHGArray[i].nRadiate=0;

		int&	nRadiate=pBpaBlock->m_nRecordNum[BPA_DAT_RADIATE];
		nRadiate=0;
		strcpy(pBpaBlock->m_BpaDat_RadiateArray[nRadiate].szBoundBusName, "        ");

		nRadiate++;
		for (nBus=0; nBus<(int)m_RadiateArray.size(); nBus++)
		{
			strcpy(pBpaBlock->m_BpaDat_RadiateArray[nRadiate].szBoundBusName, pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBoundBus].szName);
			pBpaBlock->m_BpaDat_RadiateArray[nRadiate].fBoundBuskV=pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBoundBus].fkV;
			pBpaBlock->m_BpaDat_RadiateArray[nRadiate].fGenP=m_RadiateArray[nBus].fGenP;
			pBpaBlock->m_BpaDat_RadiateArray[nRadiate].fLoadP=m_RadiateArray[nBus].fLoadP;
			pBpaBlock->m_BpaDat_RadiateArray[nRadiate].fLoadQ=m_RadiateArray[nBus].fLoadQ;
			pBpaBlock->m_BpaDat_RadiateArray[nRadiate].nBoundBus=m_RadiateArray[nBus].nBoundBus;

			for (i=0; i<(int)m_RadiateArray[nBus].nBusArray.size(); i++)
			{
				pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]].nRadiate=nRadiate;
				for (j=pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]].nLineHGRange; j<pBpaBlock->m_BpaDat_ACBusArray[m_RadiateArray[nBus].nBusArray[i]+1].nLineHGRange; j++)
					pBpaBlock->m_BpaDat_LineHGArray[pBpaBlock->m_BpaDat_EdgeLineHGArray[j].nLineHG].nRadiate=nRadiate;
			}
			for (i=0; i<(int)m_RadiateArray[nBus].nLineArray.size(); i++)
				pBpaBlock->m_BpaDat_ACLineArray[m_RadiateArray[nBus].nLineArray[i]].nRadiate=nRadiate;
			for (i=0; i<(int)m_RadiateArray[nBus].nWindArray.size(); i++)
				pBpaBlock->m_BpaDat_WindArray[m_RadiateArray[nBus].nWindArray[i]].nRadiate=nRadiate;
			nRadiate++;
		}

		dEnd=clock();
		nDur=(int)((1000.0*(double)(dEnd-dBeg))/CLOCKS_PER_SEC);
		Log(g_lpszLogFile, "数据库操作完成，耗时%d毫秒\n", nDur);

		//////////////////////////////////////////////////////////////////////////
		//	以下用于查错
		// 	for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		// 	{
		// 		if (pBpaBlock->m_BpaDat_ACBusArray[i].bInRing && pBpaBlock->m_BpaDat_ACBusArray[i].nRadiate != 0)
		// 			ASSERT(FALSE);
		// 		if (!pBpaBlock->m_BpaDat_ACBusArray[i].bInRing && pBpaBlock->m_BpaDat_ACBusArray[i].nRadiate == 0)
		// 			ASSERT(FALSE);
		// 	}
		// 	for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
		// 	{
		// 		if (pBpaBlock->m_BpaDat_ACLineArray[i].bInRing && pBpaBlock->m_BpaDat_ACLineArray[i].nRadiate != 0)
		// 			ASSERT(FALSE);
		// 		if (!pBpaBlock->m_BpaDat_ACLineArray[i].bInRing && pBpaBlock->m_BpaDat_ACLineArray[i].nRadiate == 0)
		// 			ASSERT(FALSE);
		// 	}
		// 	for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
		// 	{
		// 		if (pBpaBlock->m_BpaDat_WindArray[i].bInRing && pBpaBlock->m_BpaDat_WindArray[i].nRadiate != 0)
		// 			ASSERT(FALSE);
		// 		if (!pBpaBlock->m_BpaDat_WindArray[i].bInRing && pBpaBlock->m_BpaDat_WindArray[i].nRadiate == 0)
		// 			ASSERT(FALSE);
		// 	}
		// 	for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
		// 	{
		// 		if (pBpaBlock->m_BpaDat_LineHGArray[i].bInRing && pBpaBlock->m_BpaDat_LineHGArray[i].nRadiate != 0)
		// 			ASSERT(FALSE);
		// 		if (!pBpaBlock->m_BpaDat_LineHGArray[i].bInRing && pBpaBlock->m_BpaDat_LineHGArray[i].nRadiate == 0)
		// 			ASSERT(FALSE);
		// 	}
	}
}
