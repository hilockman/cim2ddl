#include <io.h>
#include <process.h>
#include "PRAdequacyEstimate.h"
#include "../../../../Common/TinyXML/tinyxml.h"

namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	void CPRAdequacyEstimate::InitAdequacyXmlFile(const char* lpszXmlFileName, const char* lpszRootTag)
	{
		if (!lpszXmlFileName)
			return;
		if (strlen(lpszXmlFileName) <= 0)
			return;

		FILE*	fp=fopen(lpszXmlFileName, "w");
		if (fp != NULL)
		{
			TiXmlDeclaration*	pDeclare = new TiXmlDeclaration("1.0", "gb2312", "no");
			pDeclare->Print(fp, 0);
			delete pDeclare;

			fprintf(fp, "\n<%s>\n", lpszRootTag);
			fflush(fp);
			fclose(fp);
		}
	}

	void CPRAdequacyEstimate::ExitAdequacyXmlFile(const char* lpszXmlFileName, const char* lpszRootTag)
	{
		if (!lpszXmlFileName)
			return;
		if (strlen(lpszXmlFileName) <= 0)
			return;

		FILE*	fp=fopen(lpszXmlFileName, "a");
		if (fp != NULL)
		{
			fprintf(fp, "</%s>\n", lpszRootTag);
			fflush(fp);
			fclose(fp);
		}
	}

	void CPRAdequacyEstimate::SaveAdequacyEstimateResult(tagPRBlock* pPRBlock, const char* lpszResultFileName)
	{
		register int	i;
		TiXmlElement*	pSysElement;
		TiXmlElement*	pSubElement;

		if (!lpszResultFileName)
			return;
		if (strlen(lpszResultFileName) <= 0)
			return;

		pSysElement = new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_SYSTEM));

		pSysElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_MAXFLTDEV),				pPRBlock->m_System.nMaxFltDev);
		pSysElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_CUTLOADSTATENUM),			pPRBlock->m_System.nCutLoadState);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_PLC),				pPRBlock->m_System.fPLC);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_EFLC),				pPRBlock->m_System.fEFLC);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_EDLC),				pPRBlock->m_System.fEDLC);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_ADLC),				pPRBlock->m_System.fADLC);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_ELC),				pPRBlock->m_System.fELC);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_EENS),				pPRBlock->m_System.fEENS);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_BPII),				pPRBlock->m_System.fBPII);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_BPECI),				pPRBlock->m_System.fBPECI);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_SI),					pPRBlock->m_System.fSI);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_LOLE),				pPRBlock->m_System.fLOLE);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_PLOS),				pPRBlock->m_System.fPLOS);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_FLOS),				pPRBlock->m_System.fFLOS);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_MTTIS),				pPRBlock->m_System.fMTTIS);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_MIEENS),				pPRBlock->m_System.fMIslandEENS);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_AGCEENS),			pPRBlock->m_System.fLossGenEENS);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_ELEENS),				pPRBlock->m_System.fERLimitEENS);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_FLTGRADE0PROB),		pPRBlock->m_System.fFltGrade0Prob);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_FLTGRADE1PROB),		pPRBlock->m_System.fFltGrade1Prob);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_FLTGRADE2PROB),		pPRBlock->m_System.fFltGrade2Prob);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_FLTGRADE3PROB),		pPRBlock->m_System.fFltGrade3Prob);
		pSysElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_SYSTEM, PR_SYSTEM_FLTGRADE4PROB),		pPRBlock->m_System.fFltGrade4Prob);

		for (i=0; i<pPRBlock->m_nRecordNum[PR_ZONE]; i++)
		{
			pSubElement = new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_ZONE));
			pSysElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ZONE, PR_ZONE_NAME),						pPRBlock->m_ZoneArray[i].szName);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ZONE, PR_ZONE_TOTGENP),			pPRBlock->m_ZoneArray[i].fTotGenP);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ZONE, PR_ZONE_TOTLOADP),			pPRBlock->m_ZoneArray[i].fTotLoadP);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ZONE, PR_ZONE_CUTLOADP),			pPRBlock->m_ZoneArray[i].fCutLoadP);
		}

		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			pSubElement = new TiXmlElement(g_PRMemDBInterface.PRGetTableName(PR_ACBUS));
			pSysElement->LinkEndChild(pSubElement);

			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_NAME),					pPRBlock->m_ACBusArray[i].szName);
			pSubElement->SetAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_ZONE),					pPRBlock->m_ACBusArray[i].szZone);

			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_GENP),				pPRBlock->m_ACBusArray[i].fGenP);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_GENQ),				pPRBlock->m_ACBusArray[i].fGenQ);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_LOADP),			pPRBlock->m_ACBusArray[i].fLoadP);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_LOADQ),			pPRBlock->m_ACBusArray[i].fLoadQ);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_RADP),				pPRBlock->m_ACBusArray[i].fRadP);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_SHUNTQ),			pPRBlock->m_ACBusArray[i].fShuntQ);

			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_PLC),				pPRBlock->m_ACBusArray[i].fPLC);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_EFLC),				pPRBlock->m_ACBusArray[i].fEFLC);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_EDLC),				pPRBlock->m_ACBusArray[i].fEDLC);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_ADLC),				pPRBlock->m_ACBusArray[i].fADLC);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_ELC),				pPRBlock->m_ACBusArray[i].fELC);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_EENS),				pPRBlock->m_ACBusArray[i].fEENS);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_BPII),				pPRBlock->m_ACBusArray[i].fBPECI);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_BPECI),			pPRBlock->m_ACBusArray[i].fBPII);
			pSubElement->SetDoubleAttribute(g_PRMemDBInterface.PRGetFieldName(PR_ACBUS, PR_ACBUS_SI),				pPRBlock->m_ACBusArray[i].fSI);
		}

		if (access(lpszResultFileName, 0) == 0)
		{
			FILE*	fp=fopen(lpszResultFileName, "a");
			if (fp != NULL)
			{
				pSysElement->Print(fp, 1);
				fprintf(fp, "\n");
				fflush(fp);
				fclose(fp);
			}
		}

		pSysElement->Clear();
		delete pSysElement;
	}

	void CPRAdequacyEstimate::WriteAdequacyResult(tagPRBlock* pPRBlock, const char* lpszFileName, const char* lpszCaseName, const char* lpszRaiFile, const char* lpszDatFile, const char* lpszSwiFile, const char* lpszRmlFile, const int nDur)
	{
		register int	i;

		FILE*	fp=fopen(lpszFileName, "w");
		fprintf(fp, "*Version 2014\n");
		fprintf(fp, "//版本信息\n\n");

		fprintf(fp, "*Compell information:	%s\n", lpszRaiFile);
		fprintf(fp, "*Powerflow File:		%s\n", lpszDatFile);
		fprintf(fp, "*Stable File:			%s\n", lpszSwiFile);
		fprintf(fp, "*Reliability File:		%s\n", lpszRmlFile);
		fprintf(fp, "//输入文件信息\n\n");

		fprintf(fp, "*<CASE %s>\n", lpszCaseName);
		fprintf(fp, "//计算控制信息\n\n");

		fprintf(fp, "*Outage Information\n");
		fprintf(fp, "//故障信息列表\n");
		fprintf(fp, "//故障重数，状态数，概率和，故障数，故障概率和\n");

		int		nStateNum, nFaultNum;
		double	fStateProb, fFaultProb;
		for (int nFlt=0; nFlt<=pPRBlock->m_System.nMaxFltDev; nFlt++)
		{
			nStateNum=nFaultNum=0;
			fStateProb=fFaultProb=0;
			for (i=0; i<pPRBlock->m_nRecordNum[PR_FSTATE]; i++)
			{
				if (pPRBlock->m_FStateArray[i].nFDevNum == nFlt)
				{
					nStateNum++;
					fStateProb += pPRBlock->m_FStateArray[i].fStateProb;

					if (pPRBlock->m_FStateArray[i].fMIOutLoad > FLT_MIN || pPRBlock->m_FStateArray[i].fEnsCutLoad > FLT_MIN || pPRBlock->m_FStateArray[i].fELCutLoad > FLT_MIN)
					{
						nFaultNum++;
						fFaultProb += pPRBlock->m_FStateArray[i].fStateProb;
					}
				}
			}
			fprintf(fp, "%d, %d, %f, %d, %f\n", nFlt, nStateNum, fStateProb, nFaultNum, fFaultProb);
		}
		fprintf(fp, "\n");

		fprintf(fp, "*System Reliability Index\n");
		fprintf(fp, "//全系统可靠性计算结果\n");
		//fprintf(fp, "//状态总数, 总概率, 切负荷概率PLC, 切负荷频率EFLC, 负荷切除期望值ELC, 电量不足期望值EENS, 系统削减电量指标, 系统停电指标, 严重程度指标\n");
		//fprintf(fp, "//                                  (次/年)        (MW/年)             (MWh/年)       (MWh/MW.年)     (MW/MW.年)   (系统分/年)\n");
		fprintf(fp, "//状态总数, 总概率, 切负荷概率PLC, 负荷切除期望值ELC, 电量不足期望值EENS, 系统削减电量指标, 系统停电指标, 严重程度指标\n");
		fprintf(fp, "//                                 (MW/年)             (MWh/年)       (MWh/MW.年)     (MW/MW.年)   (系统分/年)\n");
		fprintf(fp, "%d, ", pPRBlock->m_nRecordNum[PR_FSTATE]);
		fprintf(fp, "1.0, ");
		fprintf(fp, "%f, ", pPRBlock->m_System.fPLC);
		fprintf(fp, "%f, ", pPRBlock->m_System.fELC);
		fprintf(fp, "%f, ", pPRBlock->m_System.fEENS);
		fprintf(fp, "%f, ", pPRBlock->m_System.fBPECI);
		fprintf(fp, "%f, ", pPRBlock->m_System.fBPII);
		fprintf(fp, "%f, ", pPRBlock->m_System.fSI);
		fprintf(fp, "\n");
		fprintf(fp, "\n");

		fprintf(fp, "*Zone Reliability Index\n");
		//fprintf(fp, "//'分区名称', 状态总数, 总概率, 切负荷概率PLC, 切负荷频率EFLC, 负荷切除期望值ELC, 电量不足期望值EENS, 负荷不足期望LOLE, 电力不足期望EDNS, 误差PLCmax, EENSmax\n");
		//fprintf(fp, "//                                        (次/yr)        (MW/yr)             (MWh/yr)           (/h)            (MW/yr)         (/h)   (MW/yr)\n");
		//fprintf(fp, "//'分区名称', 状态总数, 总概率, 切负荷概率PLC, 负荷切除期望值ELC, 电量不足期望值EENS, 负荷不足期望LOLE, 电力不足期望EDNS, 误差PLCmax, EENSmax\n");
		//fprintf(fp, "//                                         (MW/yr)             (MWh/yr)           (/h)            (MW/yr)         (/h)   (MW/yr)\n");
		fprintf(fp, "//'分区名称', 电量不足期望值EENS\n");
		fprintf(fp, "//           (MWh/yr)\n");

		int		nZone;
		unsigned char	bExist;
		std::vector<std::string>	strZoneArray;
		double	fEns;
		strZoneArray.clear();
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			if (strlen(pPRBlock->m_ACBusArray[i].szZone) <= 0)
				continue;

			bExist=0;
			for (nZone=0; nZone<(int)strZoneArray.size(); nZone++)
			{
				if (stricmp(strZoneArray[nZone].c_str(), pPRBlock->m_ACBusArray[i].szZone) == 0)
				{
					bExist=1;
					break;
				}
			}
			if (!bExist)
				strZoneArray.push_back(pPRBlock->m_ACBusArray[i].szZone);
		}
		for (nZone=0; nZone<(int)strZoneArray.size(); nZone++)
		{
			fEns=0;
			for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
			{
				if (stricmp(pPRBlock->m_ACBusArray[i].szZone, strZoneArray[nZone].c_str()) != 0)
					continue;

				fEns += pPRBlock->m_ACBusArray[i].fEENS;
			}
			fprintf(fp, "%s, ", strZoneArray[nZone].c_str());
			fprintf(fp, "%f, ", fEns);
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n");

		fprintf(fp, "*Bus Reliability Index\n");
		fprintf(fp, "//BusName       BaseKv     EENS\n");
		for (i=1; i<pPRBlock->m_nRecordNum[PR_ACBUS]; i++)
		{
			fprintf(fp, "%s, ", pPRBlock->m_ACBusArray[i].szName);
			fprintf(fp, "%f, ", pPRBlock->m_ACBusArray[i].fkV);
			fprintf(fp, "%f, ", pPRBlock->m_ACBusArray[i].fEENS);
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n");

		fprintf(fp, "*Calculate Time: %f\n", nDur/1000.0);

		fflush(fp);
		fclose(fp);
	}
}
