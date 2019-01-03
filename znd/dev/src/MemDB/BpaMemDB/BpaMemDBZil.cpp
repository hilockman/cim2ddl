#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	typedef	struct  _BpaZILConnBus_
	{
		std::string			strDestName;
		float				fDestkV;
		std::vector<int>	nBusArray;
	}	tagBpaZILConnBus;

	void CBpaMemDBInterface::BpaMergeZILLine(tagBpaBlock* pBpaBlock, const double fZIL)
	{
		register int	i, j;
		int		nDev, nBus, nLine;
		int		nBusNumOfLayer;
		unsigned char	bInMerge, bFlag;
		std::vector<int> nMidBusArray;
		std::vector<unsigned char>	bBusUnProcArray;
		std::vector<int>	nBusArray;

		tagBpaZILConnBus	ZILConnBuf;
		std::vector<tagBpaZILConnBus>	ZILConnArray;
		std::vector<unsigned char>	bBusMergProcArray;

		ZILConnArray.clear();
		pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]=0;

		bBusMergProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bBusMergProcArray.size(); i++)
			bBusMergProcArray[i]=0;

		//////////////////////////////////////////////////////////////////////////
		//	生成小阻抗支路母线集合，搜索小支路连通的节点集合
		//////////////////////////////////////////////////////////////////////////
		for (nLine=0; nLine<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nLine++)
		{
			if (fabs(pBpaBlock->m_BpaDat_ACLineArray[nLine].fX) > fZIL)
				continue;

			if (bBusMergProcArray[pBpaBlock->m_BpaDat_ACLineArray[nLine].nIBus])
				continue;

			bBusMergProcArray[pBpaBlock->m_BpaDat_ACLineArray[nLine].nIBus]=1;
			bBusMergProcArray[pBpaBlock->m_BpaDat_ACLineArray[nLine].nZBus]=1;
			ZILConnBuf.nBusArray.clear();

			bBusUnProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
				bBusUnProcArray[i]=1;

			ZILConnBuf.nBusArray.push_back(pBpaBlock->m_BpaDat_ACLineArray[nLine].nIBus);
			bBusUnProcArray[pBpaBlock->m_BpaDat_ACLineArray[nLine].nIBus]=0;
			nBusNumOfLayer=0;
			while (1)
			{
				nMidBusArray.clear();
				for (i=nBusNumOfLayer; i<(int)ZILConnBuf.nBusArray.size(); i++)
				{
					for (j=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].nEdgeACLineRange; j<pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]+1].nEdgeACLineRange; j++)
					{
						nDev=pBpaBlock->m_BpaDat_EdgeACLineArray[j].nACLinePtr;
						if (fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fX) > fZIL)
							continue;

						nBus=(ZILConnBuf.nBusArray[i] == pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus : pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus;
						if (bBusUnProcArray[nBus])
						{
							nMidBusArray.push_back(nBus);
							bBusUnProcArray[nBus]=0;
						}
					}
					for (j=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].nEdgeWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]+1].nEdgeWindRange; j++)
					{
						nDev=pBpaBlock->m_BpaDat_EdgeWindArray[j].nWindPtr;
						if (fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI - pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) > 0.15)
							continue;
						if (sqrt(pBpaBlock->m_BpaDat_WindArray[nDev].fR*pBpaBlock->m_BpaDat_WindArray[nDev].fR + pBpaBlock->m_BpaDat_WindArray[nDev].fX*pBpaBlock->m_BpaDat_WindArray[nDev].fX) > fZIL)
							continue;

						nBus=(ZILConnBuf.nBusArray[i] == pBpaBlock->m_BpaDat_WindArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
						if (bBusUnProcArray[nBus])
						{
							nMidBusArray.push_back(nBus);
							bBusUnProcArray[nBus]=0;
						}
					}
					if (!pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].bTMid)
					{
						for (j=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].nEdgeWindRange; j<pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]+1].nEdgeWindRange; j++)
						{
							nDev=pBpaBlock->m_BpaDat_EdgeWindArray[j].nWindPtr;
							if (sqrt(pBpaBlock->m_BpaDat_WindArray[nDev].fR*pBpaBlock->m_BpaDat_WindArray[nDev].fR + pBpaBlock->m_BpaDat_WindArray[nDev].fX*pBpaBlock->m_BpaDat_WindArray[nDev].fX) > fZIL)
								continue;
							if (fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI-pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) >= 0.15)	//	防止出现0.69和0.7的电压误差
								continue;

							nBus=(ZILConnBuf.nBusArray[i] == pBpaBlock->m_BpaDat_WindArray[nDev].nIBus) ? pBpaBlock->m_BpaDat_WindArray[nDev].nZBus : pBpaBlock->m_BpaDat_WindArray[nDev].nIBus;
							if (bBusUnProcArray[nBus])
							{
								nMidBusArray.push_back(nBus);
								bBusUnProcArray[nBus]=0;
							}
						}
					}
				}
				if (nMidBusArray.empty())
					break;
				nBusNumOfLayer=(int)ZILConnBuf.nBusArray.size();
				for (i=0; i<(int)nMidBusArray.size(); i++)
					ZILConnBuf.nBusArray.push_back(nMidBusArray[i]);
			}

			bInMerge=0;
			ZILConnBuf.strDestName=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[0]].szName;
			ZILConnBuf.fDestkV=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[0]].fkV;
			for (i=0; i<(int)ZILConnBuf.nBusArray.size(); i++)
			{
				if (pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].fPGen > 0.1 || pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].fPmax > 0.1)
				{
					ZILConnBuf.strDestName=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].szName;
					ZILConnBuf.fDestkV=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].fkV;
					bInMerge++;
				}
				else if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].szCardKey, "B") != 0)
				{
					ZILConnBuf.strDestName=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].szName;
					ZILConnBuf.fDestkV=pBpaBlock->m_BpaDat_ACBusArray[ZILConnBuf.nBusArray[i]].fkV;
					bInMerge++;
				}
			}
			if (bInMerge <= 1)
				ZILConnArray.push_back(ZILConnBuf);
			//else if (bInMerge == 100)
			//{
			//	Log("  小线路连接发电机母线[Merge=%d] %s[%g] %s[%g] %g %g\n", bInMerge,
			//		pBpaBlock->m_BpaDat_ACLineArray[nLine].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nLine].fkVI,
			//		pBpaBlock->m_BpaDat_ACLineArray[nLine].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nLine].fkVJ,
			//		pBpaBlock->m_BpaDat_ACLineArray[nLine].fR, pBpaBlock->m_BpaDat_ACLineArray[nLine].fX);
			//}
			//else
			//{
			//	Log("  小线路连接多个控制母线[Merge=%d] %s[%g] %s[%g] %g %g\n", bInMerge,
			//		pBpaBlock->m_BpaDat_ACLineArray[nLine].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nLine].fkVI,
			//		pBpaBlock->m_BpaDat_ACLineArray[nLine].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nLine].fkVJ,
			//		pBpaBlock->m_BpaDat_ACLineArray[nLine].fR, pBpaBlock->m_BpaDat_ACLineArray[nLine].fX);
			//}

			for (i=0; i<(int)ZILConnBuf.nBusArray.size(); i++)
				bBusMergProcArray[ZILConnBuf.nBusArray[i]]=1;

			nMidBusArray.clear();
			bBusUnProcArray.clear();
		}
		//////////////////////////////////////////////////////////////////////////
		//	生成小阻抗支路母线集合
		//////////////////////////////////////////////////////////////////////////

		//for (nBus=0; nBus<(int)ZILConnArray.size(); nBus++)
		//{
		//	if (ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
		//	{
		//		Log(g_lpszLogFile, "[%d/%d]将融合到的节点 %s[%g]\n", nBus, ZILConnArray.size(), ZILConnArray[nBus].strDestName.c_str(), ZILConnArray[nBus].fDestkV);
		//		for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
		//			Log(g_lpszLogFile, "    (%d/%d) %s[%g]\n", i, ZILConnArray[nBus].nBusArray.size(), pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].szName, pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fkV);
		//	}
		//}

		//////////////////////////////////////////////////////////////////////////
		//	修正设备母线
		//////////////////////////////////////////////////////////////////////////
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
			pBpaBlock->m_BpaDat_ACBusArray[i].nStatus=0;
		for (nBus=0; nBus<(int)ZILConnArray.size(); nBus++)
		{
			//if (ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
			//	Log(g_lpszLogFile, "目标节点 %s[%g] \n", ZILConnArray[nBus].strDestName.c_str(), ZILConnArray[nBus].fDestkV);

			nDev=-1;
			for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
			{
				if (stricmp(ZILConnArray[nBus].strDestName.c_str(), pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].szName) == 0 &&
					fabs(ZILConnArray[nBus].fDestkV-pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				{
					nDev=ZILConnArray[nBus].nBusArray[i];
					break;
				}
			}
			if (nDev >= 0)
			{
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (ZILConnArray[nBus].nBusArray[i] != nDev)
					{
						pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].nStatus=1;
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fPmax +=		pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fPmax;
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fPGen +=		pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fPGen;
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fQsched_Qmax +=pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fQsched_Qmax;
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fLoadP +=		pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fLoadP;
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fLoadQ +=		pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fLoadQ;
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fShuntP +=		pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fShuntP;
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fShuntQ +=		pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fShuntQ;

						pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fPGen=0;
						pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fQsched_Qmax=0;
						pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fLoadP=0;
						pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fLoadQ=0;
						pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fShuntP=0;
						pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fShuntQ=0;
					}
				}
			}

			for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nDev++)
			{
				if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nDev].szRBusName) > 0)
				{
					bInMerge=0;
					for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
					{
						if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[nDev].szRBusName, pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].szName) == 0 &&
							fabs(pBpaBlock->m_BpaDat_ACBusArray[nDev].fRBusVolt - pBpaBlock->m_BpaDat_ACBusArray[ZILConnArray[nBus].nBusArray[i]].fkV) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
						{
							bInMerge=1;
							break;
						}
					}
					if (bInMerge)
					{
						//Log("  修正母线远方控制节点 %s[%g] \n", pBpaBlock->m_BpaDat_ACBusArray[nDev].szRBusName, pBpaBlock->m_BpaDat_ACBusArray[nDev].fRBusVolt);
						strcpy(pBpaBlock->m_BpaDat_ACBusArray[nDev].szRBusName, ZILConnArray[nBus].strDestName.c_str());
						pBpaBlock->m_BpaDat_ACBusArray[nDev].fRBusVolt=ZILConnArray[nBus].fDestkV;
					}
				}
			}

			for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
			{
				bFlag=0;

				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nIBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					//if (ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
					//	Log(g_lpszLogFile, "        修正线路I(%s) %s[%g] %s[%g] %g %g\n", pBpaBlock->m_BpaDat_ACLineArray[nDev].szKeyName, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fR, pBpaBlock->m_BpaDat_ACLineArray[nDev].fX);
					strcpy(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI = ZILConnArray[nBus].fDestkV;
					pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop = ' ';
					bFlag=1;
				}

				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_ACLineArray[nDev].nZBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					//if (ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
					//	Log(g_lpszLogFile, "        修正线路J(%s) %s[%g] %s[%g] %g %g\n", pBpaBlock->m_BpaDat_ACLineArray[nDev].szKeyName, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fR, pBpaBlock->m_BpaDat_ACLineArray[nDev].fX);

					strcpy(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ = ZILConnArray[nBus].fDestkV;
					pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop = ' ';
					bFlag=1;
				}

				//if (bFlag && ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
				//	Log(g_lpszLogFile, "    修正后 %s[%g] %s[%g] %c\n", pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop);
			}

			for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
			{
				bFlag=0;

				if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard != 1)
				{
					bInMerge=0;
					for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
					{
						if (pBpaBlock->m_BpaDat_WindArray[nDev].nIBus == ZILConnArray[nBus].nBusArray[i])
						{
							bInMerge=1;
							break;
						}
					}
					if (bInMerge)
					{
						//if (ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
						//	Log(g_lpszLogFile, "        修正变压器I(%s) %s[%g] %s[%g] %g %g\n", pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ, pBpaBlock->m_BpaDat_WindArray[nDev].fR, pBpaBlock->m_BpaDat_WindArray[nDev].fX);
						strcpy(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, ZILConnArray[nBus].strDestName.c_str());
						pBpaBlock->m_BpaDat_WindArray[nDev].fkVI=ZILConnArray[nBus].fDestkV;
						pBpaBlock->m_BpaDat_WindArray[nDev].cLoop=' ';

						bFlag=1;
					}
				}

				if (pBpaBlock->m_BpaDat_WindArray[nDev].bRCard != 2)
				{
					bInMerge=0;
					for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
					{
						if (pBpaBlock->m_BpaDat_WindArray[nDev].nZBus == ZILConnArray[nBus].nBusArray[i])
						{
							bInMerge=1;
							break;
						}
					}
					if (bInMerge)
					{
						//if (ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
						//	Log(g_lpszLogFile, "        修正变压器J(%s) %s[%g] %s[%g] %g %g\n", pBpaBlock->m_BpaDat_WindArray[nDev].szKeyName, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ, pBpaBlock->m_BpaDat_WindArray[nDev].fR, pBpaBlock->m_BpaDat_WindArray[nDev].fX);
						strcpy(pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, ZILConnArray[nBus].strDestName.c_str());
						pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ=ZILConnArray[nBus].fDestkV;
						pBpaBlock->m_BpaDat_WindArray[nDev].cLoop=' ';

						bFlag=1;
					}
				}

				//if (bFlag && ZILConnArray[nBus].strDestName.find("新nls铝") != string::npos)
				//	Log(g_lpszLogFile, "    修正后 %s[%g] %s[%g] %c\n", pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ, pBpaBlock->m_BpaDat_WindArray[nDev].cLoop);
			}

			for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_R]; nDev++)
			{
				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_RArray[nDev].nIBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					strcpy(pBpaBlock->m_BpaDat_RArray[nDev].szBusI, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_RArray[nDev].fkVI=ZILConnArray[nBus].fDestkV;
				}
			}

			for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; nDev++)
			{
				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_LineHGArray[nDev].nIBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					strcpy(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI=ZILConnArray[nBus].fDestkV;
				}

				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_LineHGArray[nDev].nZBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					strcpy(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ=ZILConnArray[nBus].fDestkV;
				}
			}

			for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_RZ]; nDev++)
			{
				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_RZArray[nDev].nIBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					strcpy(pBpaBlock->m_BpaDat_RZArray[nDev].szBusI, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_RZArray[nDev].fkVI=ZILConnArray[nBus].fDestkV;
				}

				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_RZArray[nDev].nZBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					strcpy(pBpaBlock->m_BpaDat_RZArray[nDev].szBusJ, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_RZArray[nDev].fkVJ=ZILConnArray[nBus].fDestkV;
				}
			}

			for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; nDev++)
			{
				bInMerge=0;
				for (i=0; i<(int)ZILConnArray[nBus].nBusArray.size(); i++)
				{
					if (pBpaBlock->m_BpaDat_DCBusArray[nDev].nACBus == ZILConnArray[nBus].nBusArray[i])
					{
						bInMerge=1;
						break;
					}
				}
				if (bInMerge)
				{
					strcpy(pBpaBlock->m_BpaDat_DCBusArray[nDev].szACName, ZILConnArray[nBus].strDestName.c_str());
					pBpaBlock->m_BpaDat_DCBusArray[nDev].fACkV=ZILConnArray[nBus].fDestkV;
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
		//	修正设备母线
		//////////////////////////////////////////////////////////////////////////

		//	防止因小支路清除后出现的并联支路
		char	szParBusI[MDB_CHARLEN_BPABUS], szParBusJ[MDB_CHARLEN_BPABUS];
		float	fParBufI, fParBusJ;
		char	cLoop, cParLoop;
		unsigned char	bHasPal;
		std::vector<unsigned char>	bProcArray;

		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i]=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
		{
			if (bProcArray[nDev])
				continue;
			bProcArray[nDev]=1;
			if (stricmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				continue;

			bHasPal=0;
			for (i=nDev+1; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_ACLineArray[i].szBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[i].fkVI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
					continue;

				bFlag  = (	stricmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15 &&
					pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop == pBpaBlock->m_BpaDat_ACLineArray[i].cLoop);
				bFlag += (	stricmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15 &&
					pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop == pBpaBlock->m_BpaDat_ACLineArray[i].cLoop);

				if (bFlag)
				{
					bHasPal=1;
					break;
				}
			}
			if (bHasPal)
			{
				strcpy(szParBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI);
				strcpy(szParBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ);
				fParBufI=pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI;
				fParBusJ=pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ;
				cParLoop=pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop;

				Log(g_lpszLogFile, "  并列线路 %s[%g] %s[%g] %c\n", szParBusI, fParBufI, szParBusJ, fParBusJ, cParLoop);

				cLoop='1';
				for (i=nDev; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
				{

					bFlag  = (	stricmp(szParBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(fParBufI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15 &&
						stricmp(szParBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(fParBusJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15 &&
						cParLoop == pBpaBlock->m_BpaDat_ACLineArray[i].cLoop);
					bFlag += (	stricmp(szParBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(fParBufI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15 &&
						stricmp(szParBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(fParBusJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15 &&
						cParLoop == pBpaBlock->m_BpaDat_ACLineArray[i].cLoop);

					if (bFlag)
					{
						bProcArray[i]=1;
						pBpaBlock->m_BpaDat_ACLineArray[i].cLoop=cLoop++;
					}
				}
			}
		}

		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_WIND]);
		for (i=0; i<(int)bProcArray.size(); i++)
			bProcArray[i]=0;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
		{
			if (bProcArray[nDev])
				continue;
			bProcArray[nDev]=1;
			if (stricmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI - pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
				continue;

			bHasPal=0;
			for (i=nDev+1; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_WindArray[i].szBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[i].fkVI - pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
					continue;

				bFlag  = (	stricmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI - pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ - pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15 &&
					pBpaBlock->m_BpaDat_WindArray[nDev].cLoop == pBpaBlock->m_BpaDat_WindArray[i].cLoop);
				bFlag += (	stricmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI - pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ - pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15 &&
					pBpaBlock->m_BpaDat_WindArray[nDev].cLoop == pBpaBlock->m_BpaDat_WindArray[i].cLoop);

				if (bFlag)
				{
					bHasPal=1;
					break;
				}
			}
			if (bHasPal)
			{
				strcpy(szParBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI);
				strcpy(szParBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ);
				fParBufI=pBpaBlock->m_BpaDat_WindArray[nDev].fkVI;
				fParBusJ=pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ;
				cParLoop=pBpaBlock->m_BpaDat_WindArray[nDev].cLoop;

				//Log(g_lpszLogFile, "  并列主变 %s[%g] %s[%g] %c\n", szParBusI, fParBufI, szParBusJ, fParBusJ, cParLoop);

				cLoop='1';
				for (i=nDev; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
				{

					bFlag  = (	stricmp(szParBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(fParBufI - pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15 &&
						stricmp(szParBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(fParBusJ - pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15 &&
						cParLoop == pBpaBlock->m_BpaDat_WindArray[i].cLoop);
					bFlag += (	stricmp(szParBusI, pBpaBlock->m_BpaDat_WindArray[i].szBusJ) == 0 && fabs(fParBufI - pBpaBlock->m_BpaDat_WindArray[i].fkVJ) < 0.15 &&
						stricmp(szParBusJ, pBpaBlock->m_BpaDat_WindArray[i].szBusI) == 0 && fabs(fParBusJ - pBpaBlock->m_BpaDat_WindArray[i].fkVI) < 0.15 &&
						cParLoop == pBpaBlock->m_BpaDat_WindArray[i].cLoop);

					if (bFlag)
					{
						bProcArray[i]=1;
						pBpaBlock->m_BpaDat_WindArray[i].cLoop=cLoop++;
					}
				}
			}
		}

		//	这段有问题，因为高抗是跟线路走，所以高抗的并联支路号需要与线路一致。
		int	nHGLine;
		bProcArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]);
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
		{
			bProcArray[nDev]=0;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_LineHGArray[i].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[i].fkVI - pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[i].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ) < 0.15 &&
					pBpaBlock->m_BpaDat_LineHGArray[i].cLoop == pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop)
				{
					bProcArray[nDev] = 1;
					break;
				}
				else if (stricmp(pBpaBlock->m_BpaDat_LineHGArray[i].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[i].fkVI - pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_LineHGArray[i].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[i].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI) < 0.15 &&
					pBpaBlock->m_BpaDat_LineHGArray[i].cLoop == pBpaBlock->m_BpaDat_ACLineArray[nDev].cLoop)
				{
					bProcArray[nDev] = 1;
					break;
				}
			}
		}

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; nDev++)
		{
			nHGLine = -1;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15 &&
					pBpaBlock->m_BpaDat_LineHGArray[nDev].cLoop == pBpaBlock->m_BpaDat_ACLineArray[i].cLoop)
				{
					nHGLine = i;
					break;
				}
				else if (stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15 &&
					stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15 &&
					pBpaBlock->m_BpaDat_LineHGArray[nDev].cLoop == pBpaBlock->m_BpaDat_ACLineArray[i].cLoop)
				{
					nHGLine = i;
					break;
				}
			}
			if (nHGLine < 0)
			{
				for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; i++)
				{
					if (bProcArray[i])
						continue;

					if (stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15 &&
						stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15)
					{
						pBpaBlock->m_BpaDat_LineHGArray[nDev].cLoop=pBpaBlock->m_BpaDat_ACLineArray[i].cLoop;
						bProcArray[i] = 1;
						break;
					}
					else if (stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[i].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[i].fkVJ) < 0.15 &&
						stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[i].szBusI) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ - pBpaBlock->m_BpaDat_ACLineArray[i].fkVI) < 0.15)
					{
						pBpaBlock->m_BpaDat_LineHGArray[nDev].cLoop=pBpaBlock->m_BpaDat_ACLineArray[i].cLoop;
						bProcArray[i] = 1;
						break;
					}
				}
			}
		}

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nDev++)
			BpaFormTableKeyField(pBpaBlock, BPA_DAT_ACLINE, nDev);
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nDev++)
			BpaFormTableKeyField(pBpaBlock, BPA_DAT_WIND, nDev);
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; nDev++)
			BpaFormTableKeyField(pBpaBlock, BPA_DAT_LINEHG, nDev);

		nBus=0;
		while (nBus < pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS])
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].nStatus)
				BpaRemoveRecord(pBpaBlock, BPA_DAT_ACBUS, nBus);
			else
				nBus++;
		}

		nDev=0;
		while (nDev < pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE])
		{
			if (stricmp(pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI - pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
			{
				if (pBpaBlock->m_nRecordNum[BPA_DAT_ZIL] < BpaGetTableMax(BPA_DAT_ZIL))
				{
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szCardKey, pBpaBlock->m_BpaDat_ACLineArray[nDev].szCardKey);
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szIniBusI);
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].szIniBusJ);
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fkVI=pBpaBlock->m_BpaDat_ACLineArray[nDev].fInikVI;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fkVJ=pBpaBlock->m_BpaDat_ACLineArray[nDev].fInikVJ;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].cLoop=pBpaBlock->m_BpaDat_ACLineArray[nDev].cIniLoop;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fR=pBpaBlock->m_BpaDat_ACLineArray[nDev].fR;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fX=pBpaBlock->m_BpaDat_ACLineArray[nDev].fX;

					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szMBus, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI);
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fMkV=pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI;

					pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]++;
				}
				//Log("    融合线路 %s[%g] %s[%g] %g %g\n", pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI,
				//	pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ,
				//	pBpaBlock->m_BpaDat_ACLineArray[nDev].fR, pBpaBlock->m_BpaDat_ACLineArray[nDev].fX);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_ACLINE, nDev);
			}
			else
			{
				//if (fabs(pBpaBlock->m_BpaDat_ACLineArray[nDev].fX) <= fZIL)
				//	Log("    小阻抗线路没有融合 %s[%g] %s[%g]\n", pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVI, pBpaBlock->m_BpaDat_ACLineArray[nDev].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nDev].fkVJ);
				nDev++;
			}
		}

		nDev=0;
		while (nDev < pBpaBlock->m_nRecordNum[BPA_DAT_WIND])
		{
			if (stricmp(pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_WindArray[nDev].fkVI - pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
			{
				if (pBpaBlock->m_nRecordNum[BPA_DAT_ZIL] < BpaGetTableMax(BPA_DAT_ZIL))
				{
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szCardKey, pBpaBlock->m_BpaDat_WindArray[nDev].szCardKey);
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].szIniBusI);
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].szIniBusJ);
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fkVI=pBpaBlock->m_BpaDat_WindArray[nDev].fInikVI;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fkVJ=pBpaBlock->m_BpaDat_WindArray[nDev].fInikVJ;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].cLoop=pBpaBlock->m_BpaDat_WindArray[nDev].cIniLoop;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fR=pBpaBlock->m_BpaDat_WindArray[nDev].fR;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fX=pBpaBlock->m_BpaDat_WindArray[nDev].fX;

					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szMBus, pBpaBlock->m_BpaDat_WindArray[nDev].szBusI);
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fMkV=pBpaBlock->m_BpaDat_WindArray[nDev].fkVI;

					pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]++;
				}
				//Log("    融合变压器 %s[%g] %s[%g]\n", pBpaBlock->m_BpaDat_WindArray[nDev].szBusI, pBpaBlock->m_BpaDat_WindArray[nDev].fkVI, pBpaBlock->m_BpaDat_WindArray[nDev].szBusJ, pBpaBlock->m_BpaDat_WindArray[nDev].fkVJ);
				BpaRemoveRecord(pBpaBlock, BPA_DAT_WIND, nDev);
			}
			else
				nDev++;
		}

		nDev=0;
		while (nDev < pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG])
		{
			if (stricmp(pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ) == 0 && fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI - pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ) < 0.15)	//	防止出现诸如0.69和0.7之间的误差
			{
				if (pBpaBlock->m_nRecordNum[BPA_DAT_ZIL] < BpaGetTableMax(BPA_DAT_ZIL))
				{
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szCardKey, pBpaBlock->m_BpaDat_LineHGArray[nDev].szCardKey);
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szBusI, pBpaBlock->m_BpaDat_LineHGArray[nDev].szIniBusI);
					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szBusJ, pBpaBlock->m_BpaDat_LineHGArray[nDev].szIniBusJ);
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fkVI=pBpaBlock->m_BpaDat_LineHGArray[nDev].fInikVI;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fkVJ=pBpaBlock->m_BpaDat_LineHGArray[nDev].fInikVJ;
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].cLoop=pBpaBlock->m_BpaDat_LineHGArray[nDev].cIniLoop;

					strcpy(pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].szMBus, pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI);
					pBpaBlock->m_BpaDat_ZILArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]].fMkV=pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI;

					pBpaBlock->m_nRecordNum[BPA_DAT_ZIL]++;
				}
				BpaRemoveRecord(pBpaBlock, BPA_DAT_LINEHG, nDev);
			}
			else
			{
				//if (fabs(pBpaBlock->m_BpaDat_LineHGArray[nDev].fX) <= fZIL)
				//	Log("    小阻抗线路没有融合 %s[%g] %s[%g]\n", pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusI, pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVI, pBpaBlock->m_BpaDat_LineHGArray[nDev].szBusJ, pBpaBlock->m_BpaDat_LineHGArray[nDev].fkVJ);
				nDev++;
			}
		}

		BpaMaint(pBpaBlock, fZIL);
	}
}