#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include "BpaDictSwiData.h"
#include "../../Common/StringCommon.h"
#include "../../Common/String2Double.hpp"

#include <float.h>
namespace	BpaMemDB
{
	int	CBpaMemDBInterface::PfoFindACBusIndex(tagBpaBlock* pBpaBlock, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		{
			if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[i].szName, lpszBusName) == 0 && fabs(pBpaBlock->m_BpaDat_ACBusArray[i].fkV-fBuskV) < 0.15)
				return i;
		}
		return -1;
	}

	int	CBpaMemDBInterface::PfoFindDCBusIndex(tagBpaBlock* pBpaBlock, const char* lpszBusName, const float fBuskV)
	{
		register int	i;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_DCBUS]; i++)
		{
			if (stricmp(pBpaBlock->m_BpaDat_DCBusArray[i].szName, lpszBusName) == 0 && fabs(pBpaBlock->m_BpaDat_DCBusArray[i].fkV-fBuskV) < 0.15)
				return i;
		}
		return -1;
	}

	int	CBpaMemDBInterface::IsPfoShuntLine(const char* lpszLine)
	{
		register int	i;

		if (strstr(lpszLine, "并联无功") == NULL || strstr(lpszLine, "安排无功") == NULL)
			return 0;

		for (i=0; i<50; i++)
		{
			if (lpszLine[i] != ' ' && lpszLine[i] != '\t')
				return 0;
		}

		return 1;
	}

	int	CBpaMemDBInterface::IsPfoNetLine(const char* lpszLine)
	{
		register int	i;

		if (strstr(lpszLine, "PNET") == NULL || strstr(lpszLine, "QNET") == NULL)
			return 0;

		for (i=0; i<36; i++)
		{
			if (lpszLine[i] != ' ' && lpszLine[i] != '\t')
				return 0;
		}

		return 1;
	}

	void CBpaMemDBInterface::SplitStringBySpace(const char* lpszString, std::vector<std::string>& strEleArray)
	{
		char	szLine[1024];

		strEleArray.clear();
		strcpy(szLine, lpszString);
		char*	lpszToken=strtok(szLine, " /\t\n");
		while (lpszToken != NULL)
		{
			strEleArray.push_back(lpszToken);
			lpszToken=strtok(NULL, " /\t\n");
		}
	}

	void CBpaMemDBInterface::ResolveNumericString(const char* lpszString, char* lpszRetString)
	{
		register int	i;
		int	nChar=0;

		i=0;
		while (i < (int)strlen(lpszString))
		{
			if (isascii(lpszString[i]))
			{
				if (isdigit(lpszString[i]) || lpszString[i] == '.' || lpszString[i] == '+' || lpszString[i] == '-')
					lpszRetString[nChar++]=lpszString[i];

				i++;
			}
			else
			{
				i++;
				i++;
			}
		}
		lpszRetString[nChar++]='\0';
	}

	int	CBpaMemDBInterface::ParseBpaPfoBusLine(tagBpaBlock* pBpaBlock, const char* lpszLine, const char* lpszLineExt, int& nBusIndex, unsigned char& bDCBus)
	{
		int		nItem;
		char	szBuf[MDB_CHARLEN_SHORT], szLine[1024], szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		std::vector<std::string>	strEleArray;

		strcpy(szLine, lpszLine);

		nBusIndex=-1;
		bDCBus=0;

		strEleArray.clear();
		char*	lpszToken=strtok(szLine, " /\t\n");
		while (lpszToken != NULL)
		{
			if (strEleArray.empty())
			{
				if (strlen(lpszToken) > 8)
				{
					memset(szBuf, 0, MDB_CHARLEN_SHORT);
					strncpy(szBuf, lpszToken, 8);	strEleArray.push_back(szBuf);
					strcpy(szBuf, lpszToken+8);		strEleArray.push_back(szBuf);
				}
				else
				{
					strEleArray.push_back(lpszToken);
				}
			}
			else
			{
				strEleArray.push_back(lpszToken);
			}
			lpszToken=strtok(NULL, " /\t\n");
		}


		if (strEleArray.size() < 3)
			return 0;

		strcpy(szRest[0], strEleArray[0].c_str());
		strcpy(szRest[1], strEleArray[1].c_str());

		nBusIndex=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, szRest);
		if (nBusIndex < 0)
			nBusIndex=PfoFindACBusIndex(pBpaBlock, strEleArray[0].c_str(), StringToFloat(strEleArray[1].c_str()));
		if (nBusIndex >= 0)
		{
			nItem=2;
			if ((int)strEleArray.size() > nItem)	{	ResolveNumericString(strEleArray[nItem++].c_str(), szLine);	pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].fV=StringToFloat(szLine);	}
			if ((int)strEleArray.size() > nItem)	{	ResolveNumericString(strEleArray[nItem++].c_str(), szLine);	pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].fD=StringToFloat(szLine);	}

			nItem=4;
			while (nItem < (int)strEleArray.size())
			{
				if (strstr(strEleArray[nItem].c_str(), "有功出力") != NULL)
				{
					ResolveNumericString(strEleArray[nItem].c_str(), szLine);
					if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].szCardKey, "BS") == 0)
						pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].fPGen=StringToFloat(szLine);
					pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].fPfoPGen=StringToFloat(szLine);
				}
				if (strstr(strEleArray[nItem].c_str(), "无功出力") != NULL)
				{
					ResolveNumericString(strEleArray[nItem].c_str(), szLine);
					pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].fPfoQGen=StringToFloat(szLine);
				}
				if (strstr(strEleArray[nItem].c_str(), "有功负荷") != NULL)
				{
					ResolveNumericString(strEleArray[nItem].c_str(), szLine);
					pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].fPfoPLoad=StringToFloat(szLine);
				}
				if (strstr(strEleArray[nItem].c_str(), "无功负荷") != NULL)
				{
					ResolveNumericString(strEleArray[nItem].c_str(), szLine);
					pBpaBlock->m_BpaDat_ACBusArray[nBusIndex].fPfoQLoad=StringToFloat(szLine);
				}
				nItem++;
			}

			return 1;
		}
		else
		{
			nBusIndex=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szRest);
			if (nBusIndex < 0)
				nBusIndex=PfoFindDCBusIndex(pBpaBlock, strEleArray[0].c_str(), StringToFloat(strEleArray[1].c_str()));
			if (nBusIndex >= 0)
			{
				bDCBus=1;

				if (strEleArray.size() > 2)	{	ResolveNumericString(strEleArray[2].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fDCV=StringToFloat(szLine);	}
				if (strEleArray.size() > 3)	{	ResolveNumericString(strEleArray[3].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fDCD=StringToFloat(szLine);	}
				if (strEleArray.size() > 5)	{	ResolveNumericString(strEleArray[5].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fDCP=StringToFloat(szLine);	}
				if (strEleArray.size() > 6)	{	ResolveNumericString(strEleArray[6].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fDCI=StringToFloat(szLine);	}
				if (strEleArray.size() > 7)	{	ResolveNumericString(strEleArray[7].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fLossP=StringToFloat(szLine);	}
				if (strEleArray.size() > 8)	{	ResolveNumericString(strEleArray[8].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fLossQ=StringToFloat(szLine);	}

				strcpy(szLine, lpszLineExt);
				strEleArray.clear();
				char*	lpszToken=strtok(szLine, " /\t\n");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, " /\t\n");

					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fACV=StringToFloat(szLine);		}
					if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_DCBusArray[nBusIndex].fAngle=StringToFloat(szLine);	}
				}

				return 2;
			}
			else
			{
				Log(g_lpszLogFile, "ParseBpaPfoBusLine 解析PFO母线 [%s, %s]错误[%s]\n", szRest[0], szRest[1], lpszLine);
			}
		}

		return 0;
	}

	int	CBpaMemDBInterface::ParseBpaPfoShunt(tagBpaBlock* pBpaBlock, const int nBus, const char* lpszLine)
	{
		int		nItem;
// 		char	szBuf[MDB_CHARLEN_SHORT], szLine[1024];
		char	szLine[1024];
		std::vector<std::string>	strEleArray;

		strcpy(szLine, lpszLine);

		strEleArray.clear();
		char*	lpszToken=strtok(szLine, " /\t\n");
		while (lpszToken != NULL)
		{
			strEleArray.push_back(lpszToken);
// 			if (strEleArray.empty())
// 			{
// 				if (strlen(lpszToken) > 8)
// 				{
// 					memset(szBuf, 0, MDB_CHARLEN_SHORT);
// 					strncpy(szBuf, lpszToken, 8);	strEleArray.push_back(szBuf);
// 					strcpy(szBuf, lpszToken+8);		strEleArray.push_back(szBuf);
// 				}
// 				else
// 				{
// 					strEleArray.push_back(lpszToken);
// 				}
// 			}
// 			else
// 			{
// 				strEleArray.push_back(lpszToken);
// 			}
			lpszToken=strtok(NULL, " /\t\n");
		}

		if (strEleArray.size() < 2)
			return 0;

		nItem=0;
		while (nItem < (int)strEleArray.size())
		{
			if (strstr(strEleArray[nItem].c_str(), "并联无功") != NULL)
			{
				ResolveNumericString(strEleArray[nItem].c_str(), szLine);
				pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoQShunt=StringToFloat(szLine);
			}
			if (strstr(strEleArray[nItem].c_str(), "安排无功") != NULL)
			{
				ResolveNumericString(strEleArray[nItem].c_str(), szLine);
				pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoQShunt=StringToFloat(szLine);
			}
			nItem++;
		}

		return 1;
	}

	int CBpaMemDBInterface::ParseBpaPfoNet(tagBpaBlock* pBpaBlock, const int nBus, const char* lpszLine)
	{
		int		nItem;
// 		char	szBuf[MDB_CHARLEN_SHORT], szLine[1024];
		char	szLine[1024];
		std::vector<std::string>	strEleArray;

		strcpy(szLine, lpszLine);

		strEleArray.clear();
		char*	lpszToken=strtok(szLine, " /\t\n");
		while (lpszToken != NULL)
		{
			strEleArray.push_back(lpszToken);
// 			if (strEleArray.empty())
// 			{
// 				if (strlen(lpszToken) > 4)
// 				{
// 					memset(szBuf, 0, MDB_CHARLEN_SHORT);
// 					strncpy(szBuf, lpszToken, 4);	strEleArray.push_back(szBuf);
// 					strcpy(szBuf, lpszToken+4);		strEleArray.push_back(szBuf);
// 				}
// 				else
// 				{
// 					strEleArray.push_back(lpszToken);
// 				}
// 			}
// 			else
// 			{
// 				strEleArray.push_back(lpszToken);
// 			}
			lpszToken=strtok(NULL, " /\t\n");
		}

		if (strEleArray.size() < 2)
			return 0;

		nItem=0;
		while (nItem < (int)strEleArray.size())
		{
			if (strstr(strEleArray[nItem].c_str(), "PNET") != NULL)
			{
				ResolveNumericString(strEleArray[nItem].c_str(), szLine);
				pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoPNet=StringToFloat(szLine);
			}
			if (strstr(strEleArray[nItem].c_str(), "QNET") != NULL)
			{
				ResolveNumericString(strEleArray[nItem].c_str(), szLine);
				pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoQNet=StringToFloat(szLine);
			}
			nItem++;
		}

		return 1;
	}

	void CBpaMemDBInterface::ParseBpaPfoACLine(tagBpaBlock* pBpaBlock, const int nFrBus, const char* lpszLine)
	{
		register int	i;
		int		nChar;
		char	szKeyName[MDB_CHARLEN_LONG], szBusName[MDB_CHARLEN_LONG], szBusVolt[MDB_CHARLEN_LONG];
		char	szBuf[MDB_CHARLEN_SHORT], szLine[1024];
		std::vector<std::string>	strEleArray;

		if (strstr(lpszLine, "被控节点") != NULL && strstr(lpszLine, "的电压是") != NULL)
			return;

		nChar=0;
		for (i=7; i<34; i++)
			szLine[nChar++]=lpszLine[i];
		szLine[nChar++]='\0';
		TrimLeft(szLine);

		strEleArray.clear();
		char*	lpszToken=strtok(szLine, " \t\n");
		while (lpszToken != NULL)
		{
			if (strEleArray.empty())
			{
				if (strlen(lpszToken) > 8)
				{
					memset(szBuf, 0, MDB_CHARLEN_SHORT);
					strncpy(szBuf, lpszToken, 8);	strEleArray.push_back(szBuf);
					strcpy(szBuf, lpszToken+8);		strEleArray.push_back(szBuf);
				}
				else
				{
					strEleArray.push_back(lpszToken);
				}
			}
			else
			{
				strEleArray.push_back(lpszToken);
			}
			lpszToken=strtok(NULL, " \t\n");
		}

		int	nBus, nDev;
		unsigned char	bTran=0;
		unsigned char	bPDir=0;
		unsigned char	bToDCBus=0;

		if (strEleArray.size() < 2)
		{
			for (i=0; i<8; i++)
				szBusName[i] = szLine[i];
			szBusName[8] = '\0';

			for (i=0; i<8; i++)
				szBusVolt[i] = szLine[8+i];
			szBusVolt[8] = '\0';

			Trim(szBusName);
			Trim(szBusVolt);
		}
		else
		{
			strcpy(szBusName, strEleArray[0].c_str());
			strcpy(szBusVolt, strEleArray[1].c_str());
		}

		bToDCBus=0;
		nBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, szBusName, szBusVolt);
		if (nBus < 0)
			nBus=PfoFindACBusIndex(pBpaBlock, szBusName, StringToFloat(szBusVolt));
		if (nBus < 0)
		{
			bToDCBus=1;

			nBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nBus < 0)
				nBus=PfoFindDCBusIndex(pBpaBlock, szBusName, StringToFloat(szBusVolt));
			if (nBus < 0)
			{
				Log(g_lpszLogFile, "ParseBpaPfoACLine 解析PFO母线 [%s, %s]错误 [%s]\n", szBusName, szBusVolt, lpszLine);
				return;
			}
		}

		bTran=0;
		if (strEleArray.size() > 2)
		{
			if (bToDCBus)
			{
				bPDir=1;
				sprintf(szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV,
					pBpaBlock->m_BpaDat_DCBusArray[nBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV,
					strEleArray[2][0]);
				nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
				if (nDev < 0)
				{
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
					if (nDev >= 0)
					{
						bTran=1;
					}
				}

				if (nDev < 0)
				{
					bPDir=0;
					sprintf(szKeyName, "%s%.0f-%s%.0f@%c",
						pBpaBlock->m_BpaDat_DCBusArray[nBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV,
						pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV,
						strEleArray[2][0]);
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
					if (nDev < 0)
					{
						nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
						if (nDev >= 0)
							bTran=1;
					}
				}
			}
			else
			{
				bPDir=1;
				sprintf(szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV,
					pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV,
					strEleArray[2][0]);
				nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
				if (nDev < 0)
				{
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
					if (nDev >= 0)
						bTran=1;
				}

				if (nDev < 0)
				{
					bPDir=0;
					sprintf(szKeyName, "%s%.0f-%s%.0f@%c",
						pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV,
						pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV,
						strEleArray[2][0]);
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
					if (nDev < 0)
					{
						nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
						if (nDev >= 0)
							bTran=1;
					}
				}
			}
		}
		else
		{
			if (bToDCBus)
			{
				bPDir=1;
				sprintf(szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV,
					pBpaBlock->m_BpaDat_DCBusArray[nBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV);
				nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
				if (nDev < 0)
				{
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
					if (nDev >= 0)
						bTran=1;
				}

				if (nDev < 0)
				{
					bPDir=0;
					sprintf(szKeyName, "%s%.0f-%s%.0f",
						pBpaBlock->m_BpaDat_DCBusArray[nBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV,
						pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV);
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
					if (nDev < 0)
					{
						nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
						if (nDev >= 0)
							bTran=1;
					}
				}
			}
			else
			{
				bPDir=1;
				sprintf(szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV,
					pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
				nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
				if (nDev < 0)
				{
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
					if (nDev >= 0)
						bTran=1;
				}

				if (nDev < 0)
				{
					bPDir=0;
					sprintf(szKeyName, "%s%.0f-%s%.0f",
						pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV,
						pBpaBlock->m_BpaDat_ACBusArray[nFrBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nFrBus].fkV);
					nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACLINE, szKeyName);
					if (nDev < 0)
					{
						nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
						if (nDev >= 0)
							bTran=1;
					}
				}
			}
		}

		if (nDev >= 0)
		{
			memset(szLine, 0, 1024);
			strcpy(szLine, lpszLine+37);

			strEleArray.clear();
			char*	lpszToken=strtok(szLine, " /\t\n");
			while (lpszToken != NULL)
			{
				strEleArray.push_back(lpszToken);
				lpszToken=strtok(NULL, " /\t\n");
			}
			if (bTran == 0)
			{
				if (bPDir != 0)
				{
					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_ACLineArray[nDev].fPi=StringToFloat(szLine);			}
					if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_ACLineArray[nDev].fQi=StringToFloat(szLine);			}
					if (strEleArray.size() > 2)	{	ResolveNumericString(strEleArray[2].c_str(), szLine);	pBpaBlock->m_BpaDat_ACLineArray[nDev].fLossP=StringToFloat(szLine);		}
					if (strEleArray.size() > 3)	{	ResolveNumericString(strEleArray[3].c_str(), szLine);	pBpaBlock->m_BpaDat_ACLineArray[nDev].fLossQ=StringToFloat(szLine);		}
				}
				else
				{
					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_ACLineArray[nDev].fPz=StringToFloat(szLine);		}
					if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_ACLineArray[nDev].fQz=StringToFloat(szLine);		}
				}
			}
			else
			{
				if (bPDir != 0)
				{
					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fPi=StringToFloat(szLine);		}
					if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fQi=StringToFloat(szLine);		}
					if (strEleArray.size() > 2)	{	ResolveNumericString(strEleArray[2].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fLossP=StringToFloat(szLine);		}
					if (strEleArray.size() > 3)	{	ResolveNumericString(strEleArray[3].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fLossQ=StringToFloat(szLine);		}
				}
				else
				{
					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fPz=StringToFloat(szLine);		}
					if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fQz=StringToFloat(szLine);		}
				}
			}
		}
	}

	void CBpaMemDBInterface::ParseBpaPfoDCLine(tagBpaBlock* pBpaBlock, const int nFrDCBus, const char* lpszLine)
	{
		register int	i;
		int		nChar;
		unsigned char	bPDir=0;
		char	szKeyName[MDB_CHARLEN_LONG], szBusName[MDB_CHARLEN_LONG], szBusVolt[MDB_CHARLEN_LONG];
		char	szLine[1024];
		std::vector<std::string>	strEleArray;

		nChar=0;
		for (i=7; i<34; i++)
			szLine[nChar++]=lpszLine[i];
		szLine[nChar++]='\0';
		TrimLeft(szLine);

		strEleArray.clear();
		char*	lpszToken=strtok(szLine, " \t\n");
		while (lpszToken != NULL)
		{
			strEleArray.push_back(lpszToken);
			lpszToken=strtok(NULL, " \t\n");
		}

		int	nBus, nDev;
		unsigned char	bRCard=0;

		//if (stricmp(pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, "青州P") == 0)
		//	Log(g_lpszLogFile, "ParseBpaPfoDCLine Line = [%s]\n", szLine);

		if (strEleArray.size() < 2)
		{
			for (i=0; i<8; i++)
				szBusName[i] = szLine[i];
			szBusName[8] = '\0';

			for (i=0; i<8; i++)
				szBusVolt[i] = szLine[8+i];
			szBusVolt[8] = '\0';

			Trim(szBusName);
			Trim(szBusVolt);
		}
		else
		{
			strcpy(szBusName, strEleArray[0].c_str());
			strcpy(szBusVolt, strEleArray[1].c_str());
		}

		bRCard=0;
		nBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, szBusName, szBusVolt);
		if (nBus < 0)
			nBus=PfoFindACBusIndex(pBpaBlock, szBusName, StringToFloat(szBusVolt));
		if (nBus >= 0)
		{
			bRCard=1;
		}
		else
		{
			nBus=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nBus < 0)
				nBus=PfoFindDCBusIndex(pBpaBlock, szBusName, StringToFloat(szBusVolt));
			if (nBus < 0)
			{
				Log(g_lpszLogFile, "ParseBpaPfoDCLine 解析PFO母线 [%s, %s]错误 [%s]\n", szBusName, szBusVolt, lpszLine);
				return;
			}
		}
			
		memset(szLine, 0, 1024);
		strcpy(szLine, lpszLine+37);

		strEleArray.clear();
		lpszToken=strtok(szLine, " /\t\n");
		while (lpszToken != NULL)
		{
			strEleArray.push_back(lpszToken);
			lpszToken=strtok(NULL, " /\t\n");
		}

		if (bRCard)
		{
			bPDir=1;
			sprintf(szKeyName, "%s%.0f-%s%.0f",
				pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].fkV,
				pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV);
			nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
			if (nDev < 0)
			{
				bPDir=0;
				sprintf(szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_ACBusArray[nBus].szName, pBpaBlock->m_BpaDat_ACBusArray[nBus].fkV,
					pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].fkV);
				nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, szKeyName);
			}
			//if (stricmp(pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, "青州P") == 0)
			//	Log(g_lpszLogFile, "R Find Wind [%s] [Dir=%d]\n", szKeyName, pBpaBlock->m_BpaDat_WindArray[nDev].fPi, bPDir);

			if (nDev >= 0)
			{
				if (bPDir != 0)
				{
					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fPi=StringToFloat(szLine);	}
					if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fQi=StringToFloat(szLine);	}
					if (strEleArray.size() > 2)	{	ResolveNumericString(strEleArray[2].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fLossP=StringToFloat(szLine);	}
					if (strEleArray.size() > 3)	{	ResolveNumericString(strEleArray[3].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fLossQ=StringToFloat(szLine);	}
					//if (stricmp(pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, "青州P") == 0)
					//	Log(g_lpszLogFile, "R SetWindPQ [I] = %.2f %.2f\n", pBpaBlock->m_BpaDat_WindArray[nDev].fPi, pBpaBlock->m_BpaDat_WindArray[nDev].fQi);
				}
				else
				{
					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fPz=StringToFloat(szLine);	}
					if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_WindArray[nDev].fQz=StringToFloat(szLine);	}
					//if (stricmp(pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, "青州P") == 0)
					//	Log(g_lpszLogFile, "R SetWindPQ [Z] = %.2f %.2f\n", pBpaBlock->m_BpaDat_WindArray[nDev].fPz, pBpaBlock->m_BpaDat_WindArray[nDev].fQz);
				}
			}
		}
		else
		{
			sprintf(szKeyName, "%s%.0f-%s%.0f",
				pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].fkV,
				pBpaBlock->m_BpaDat_DCBusArray[nBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV);
			nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCLINE, szKeyName);
			if (nDev >= 0)
			{
				if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_DCLineArray[nDev].fPr=StringToFloat(szLine);		}
				if (strEleArray.size() > 1)	{	ResolveNumericString(strEleArray[1].c_str(), szLine);	pBpaBlock->m_BpaDat_DCLineArray[nDev].fLossP=StringToFloat(szLine);	}
				//if (stricmp(pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, "青州P") == 0)
				//	Log(g_lpszLogFile, "Find Line [%s] [Pz=%g]\n", szKeyName, pBpaBlock->m_BpaDat_DCLineArray[nDev].fPr);
			}
			else
			{
				sprintf(szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_DCBusArray[nBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nBus].fkV,
					pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].fkV);
				nDev=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCLINE, szKeyName);
				if (nDev >= 0)
				{
					if (strEleArray.size() > 0)	{	ResolveNumericString(strEleArray[0].c_str(), szLine);	pBpaBlock->m_BpaDat_DCLineArray[nDev].fPi=StringToFloat(szLine);		}
					//if (stricmp(pBpaBlock->m_BpaDat_DCBusArray[nFrDCBus].szName, "青州P") == 0)
					//	Log(g_lpszLogFile, "Find Line [%s] [Pi=%g]\n", szKeyName, pBpaBlock->m_BpaDat_DCLineArray[nDev].fPi);
				}
			}
		}
	}

	int CBpaMemDBInterface::BpaParsePfoFile(tagBpaBlock* pBpaBlock, const char* lpszBpaPfoFile)
	{
		FILE*	fp;
		int		nSub, nBus, nLine, nTotLine;
		unsigned char	bPfoSection;		//	表示是详细输出信息
		unsigned char	bBpaVersion2;		//	=1表示是中国版2.0，=0表示是中国版4.0
		unsigned char	bDCBus=0;
		unsigned char	bConvergency, bDetailedOutputList;
		char	szFileName[260], szLine[512];
		std::vector<std::string>	strEleArray;

		std::vector<std::string>	strPfoLineArray;
		strPfoLineArray.clear();

		if (!lpszBpaPfoFile)
			return -1;

		strcpy(szFileName, lpszBpaPfoFile);
		if (strstr(strupr(szFileName), ".PFO") == NULL)
			sprintf(szFileName, "%s.pfo", lpszBpaPfoFile);
		else
			strcpy(szFileName, lpszBpaPfoFile);

		fp=fopen(szFileName, "r");
		if (fp == NULL)
			return -1;

		pBpaBlock->m_BpaDat_Case.fTotGenP=0;
		pBpaBlock->m_BpaDat_Case.fTotGenQ=0;
		pBpaBlock->m_BpaDat_Case.fTotLoadP=0;
		pBpaBlock->m_BpaDat_Case.fTotLoadQ=0;
		pBpaBlock->m_BpaDat_Case.fTotLineCap=0;
		pBpaBlock->m_BpaDat_Case.fTotLossP=0;
		pBpaBlock->m_BpaDat_Case.fTotLossQ=0;
		pBpaBlock->m_BpaDat_Case.fTotDCLoss=0;

		bBpaVersion2=0;
		bConvergency=0;
		bDetailedOutputList=0;
		while (!feof(fp))
		{
			memset(szLine, 0, 512);
			fgets(szLine, 512, fp);

			if (strstr(szLine, "SUCCESSFUL SOLUTION REACHED") != NULL || strstr(szLine, "计算结果收敛") != NULL)
				bConvergency=1;

			if (strstr(szLine, "COMPLETE OUTPUT LISTING OF ALL BUSSES WILL BE GIVEN") != NULL)
			{
				bBpaVersion2=1;
				bDetailedOutputList=1;
			}

			if (strstr(szLine, "DETAILED OUTPUT LISTING") != NULL || strstr(szLine, "详细的输出列表") != NULL)
				bDetailedOutputList=1;

			if (strlen(szLine) > 0)
			{
				strPfoLineArray.push_back(szLine);
			}
		}

		fclose(fp);

		if (!bDetailedOutputList)
			return -2;

		bPfoSection=0;
		nBus=-1;

		nLine=0;
		while (nLine < (int)strPfoLineArray.size())
		{
			if (strPfoLineArray[nLine].find("PWRFLO case:") != string::npos || strPfoLineArray[nLine].find("潮流方式名:") != string::npos)
			{
				if (strPfoLineArray[nLine].find("DETAILED OUTPUT LISTING") != string::npos || strPfoLineArray[nLine].find("详细的输出列表") != string::npos)
					bPfoSection=1;
				else
					bPfoSection=0;

				goto _Cyc;
			}

			if (bPfoSection)
			{
				if (strPfoLineArray[nLine].find("*** WARNING") != string::npos)
					goto _Cyc;
				if (strPfoLineArray[nLine].find("分区数据总结") != string::npos)
				{
					nLine += 3;
					goto _Cyc;
				}

				if (strPfoLineArray[nLine].find("整个系统的数据总结") != string::npos)
				{
					//Log(g_lpszLogFile, "%s\n", strPfoLineArray[nLine].c_str());
					nTotLine=1;
					while (nTotLine <= 13)
					{
						//Log(g_lpszLogFile, "Line=%d String=%s\n", nTotLine, strPfoLineArray[nLine+nTotLine].c_str());

						if (strPfoLineArray[nLine+nTotLine].find("系统注入") != string::npos)				{	}
						else if (strPfoLineArray[nLine+nTotLine].find("发电机出力") != string::npos)
						{
							SplitStringBySpace(strPfoLineArray[nLine+nTotLine].c_str(), strEleArray);
							if (strEleArray.size() == 3)
							{
								pBpaBlock->m_BpaDat_Case.fTotGenP=StringToFloat(strEleArray[1].c_str());
								pBpaBlock->m_BpaDat_Case.fTotGenQ=StringToFloat(strEleArray[2].c_str());
							}
						}
						else if (strPfoLineArray[nLine+nTotLine].find("负荷") != string::npos)
						{
							SplitStringBySpace(strPfoLineArray[nLine+nTotLine].c_str(), strEleArray);
							if (strEleArray.size() == 3)
							{
								pBpaBlock->m_BpaDat_Case.fTotLoadP=-StringToFloat(strEleArray[1].c_str());
								pBpaBlock->m_BpaDat_Case.fTotLoadQ=-StringToFloat(strEleArray[2].c_str());
							}
						}
						else if (strPfoLineArray[nLine+nTotLine].find("节点并联导纳") != string::npos)		{	}
						else if (strPfoLineArray[nLine+nTotLine].find("未安排的电源") != string::npos)		{	}
						else if (strPfoLineArray[nLine+nTotLine].find("小结（注入）") != string::npos)		{	}
						else if (strPfoLineArray[nLine+nTotLine].find("系统损耗") != string::npos)			{	}
						else if (strPfoLineArray[nLine+nTotLine].find("等值并联导纳") != string::npos)		{	}
						else if (strPfoLineArray[nLine+nTotLine].find("线路和变压器损耗") != string::npos)
						{
							SplitStringBySpace(strPfoLineArray[nLine+nTotLine].c_str(), strEleArray);
							if (strEleArray.size() == 3)
							{
								pBpaBlock->m_BpaDat_Case.fTotLossP=-StringToFloat(strEleArray[1].c_str());
								pBpaBlock->m_BpaDat_Case.fTotLossQ=-StringToFloat(strEleArray[2].c_str());
							}
						}
						else if (strPfoLineArray[nLine+nTotLine].find("线路充电功率") != string::npos)
						{
							SplitStringBySpace(strPfoLineArray[nLine+nTotLine].c_str(), strEleArray);
							if (strEleArray.size() == 2)
							{
								pBpaBlock->m_BpaDat_Case.fTotLineCap=StringToFloat(strEleArray[1].c_str());
							}
						}
						else if (strPfoLineArray[nLine+nTotLine].find("直流换流器损耗") != string::npos)
						{
							SplitStringBySpace(strPfoLineArray[nLine+nTotLine].c_str(), strEleArray);
							if (strEleArray.size() >= 2)
							{
								pBpaBlock->m_BpaDat_Case.fTotDCLoss=-StringToFloat(strEleArray[1].c_str());
							}
						}
						else if (strPfoLineArray[nLine+nTotLine].find("小结（损耗）") != string::npos)		{	}
						else if (strPfoLineArray[nLine+nTotLine].find("系统净输出功率") != string::npos)	{	}

						nTotLine++;
					}
					nLine += nTotLine;
					goto _Cyc;
				}

				if (bBpaVersion2)
				{
					if (strPfoLineArray[nLine][1] != ' ')
					{
						if (ParseBpaPfoBusLine(pBpaBlock, strPfoLineArray[nLine].c_str()+1, strPfoLineArray[nLine+1].c_str()+1, nBus, bDCBus) == 2)	//	返回2表示直流母线
							nLine++;
					}
					else if (nBus >= 0)
					{
						if (bDCBus)
						{
							ParseBpaPfoDCLine(pBpaBlock, nBus, strPfoLineArray[nLine].c_str()+1);
						}
						else
						{
							if (IsPfoShuntLine(strPfoLineArray[nLine].c_str()))
							{
								ParseBpaPfoShunt(pBpaBlock, nBus, strPfoLineArray[nLine].c_str()+1);
							}
							else if (IsPfoNetLine(strPfoLineArray[nLine].c_str()))
							{
								ParseBpaPfoNet(pBpaBlock, nBus, strPfoLineArray[nLine].c_str()+1);
							}
							else
							{
								ParseBpaPfoACLine(pBpaBlock, nBus, strPfoLineArray[nLine].c_str()+1);
							}
						}
					}
				}
				else
				{
					if (strPfoLineArray[nLine][0] != ' ')
					{
						if (ParseBpaPfoBusLine(pBpaBlock, strPfoLineArray[nLine].c_str(), strPfoLineArray[nLine+1].c_str(), nBus, bDCBus) == 2)	//	返回2表示直流母线
							nLine++;
					}
					else if (nBus >= 0)
					{
						if (bDCBus)
						{
							ParseBpaPfoDCLine(pBpaBlock, nBus, strPfoLineArray[nLine].c_str());
						}
						else
						{
							if (IsPfoShuntLine(strPfoLineArray[nLine].c_str()))
							{
								ParseBpaPfoShunt(pBpaBlock, nBus, strPfoLineArray[nLine].c_str());
							}
							else if (IsPfoNetLine(strPfoLineArray[nLine].c_str()))
							{
								ParseBpaPfoNet(pBpaBlock, nBus, strPfoLineArray[nLine].c_str());
							}
							else
							{
								ParseBpaPfoACLine(pBpaBlock, nBus, strPfoLineArray[nLine].c_str());
							}
						}
					}
				}
			}
_Cyc:		nLine++;
		}

		for (nSub=0; nSub<pBpaBlock->m_nRecordNum[BPA_DAT_SUB]; nSub++)
		{
			pBpaBlock->m_BpaDat_SubArray[nSub].fGenP = 0;
			pBpaBlock->m_BpaDat_SubArray[nSub].fGenQ = 0;
			pBpaBlock->m_BpaDat_SubArray[nSub].fLoadP = 0;
			pBpaBlock->m_BpaDat_SubArray[nSub].fLoadQ = 0;
			pBpaBlock->m_BpaDat_SubArray[nSub].fShuntQ = 0;
		}

		for (nBus=0; nBus<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nBus++)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr < 0)
				continue;

			pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr].fGenP += pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoPGen;
			pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr].fGenQ += pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoQGen;
			pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr].fLoadP += pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoPLoad;
			pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr].fLoadQ += pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoQLoad;
			pBpaBlock->m_BpaDat_SubArray[pBpaBlock->m_BpaDat_ACBusArray[nBus].nSubPtr].fShuntQ += pBpaBlock->m_BpaDat_ACBusArray[nBus].fPfoQShunt;
		}

		for (nLine=0; nLine<pBpaBlock->m_nRecordNum[BPA_DAT_R]; nLine++)
		{
			int nWind = BpaFindRecordbyKey(pBpaBlock, BPA_DAT_WIND, pBpaBlock->m_BpaDat_RArray[nLine].szKeyName);
			if (nWind >= 0)
			{
				if (pBpaBlock->m_BpaDat_WindArray[nWind].bRCard == 1)
				{
					pBpaBlock->m_BpaDat_RArray[nLine].fP=pBpaBlock->m_BpaDat_WindArray[nWind].fPz;
					pBpaBlock->m_BpaDat_RArray[nLine].fP=pBpaBlock->m_BpaDat_WindArray[nWind].fPz;
					pBpaBlock->m_BpaDat_RArray[nLine].fLossP=pBpaBlock->m_BpaDat_WindArray[nWind].fLossP;
					pBpaBlock->m_BpaDat_RArray[nLine].fLossQ=pBpaBlock->m_BpaDat_WindArray[nWind].fLossQ;
				}
				else
				{
					pBpaBlock->m_BpaDat_RArray[nLine].fP=pBpaBlock->m_BpaDat_WindArray[nWind].fPi;
					pBpaBlock->m_BpaDat_RArray[nLine].fP=pBpaBlock->m_BpaDat_WindArray[nWind].fPi;
					pBpaBlock->m_BpaDat_RArray[nLine].fLossP=pBpaBlock->m_BpaDat_WindArray[nWind].fLossP;
					pBpaBlock->m_BpaDat_RArray[nLine].fLossQ=pBpaBlock->m_BpaDat_WindArray[nWind].fLossQ;
				}
			}
		}
		return bConvergency;
	}
}