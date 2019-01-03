#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include "BpaDictSwiData.h"
#include "../../Common/StringCommon.h"
#include "../../Common/String2Double.hpp"

#include <float.h>
namespace	BpaMemDB
{

	void CBpaMemDBInterface::ParseDatAI(tagBpaBlock* pBpaBlock, std::vector<std::string> strLineArray, std::vector<tagBpaZone2Area>& z2aArray)
	{
		register int	i;
		int		nLine;
		char	szBuffer[MDB_CHARLEN_LONG];
		int		nBuffer, nCol, nArea;
		tagBpaZone2Area	z2aBuf;

		pBpaBlock->m_nRecordNum[BPA_DAT_AREA]=0;
		pBpaBlock->m_nRecordNum[BPA_DAT_I]=0;

		for (nLine=0; nLine<(int)strLineArray.size(); nLine++)
		{
			if (strLineArray[nLine][0] == 'A')
			{
				if (strLineArray[nLine][1] == ' ' || (strLineArray[nLine][1] == 'C' && strLineArray[nLine][2] != '+'))
				{
					z2aBuf.strZoneArray.clear();

					strcpy(pBpaBlock->m_BpaDat_AreaArray[pBpaBlock->m_nRecordNum[BPA_DAT_AREA]].szCardKey, "AC");

					memset(szBuffer, 0, MDB_CHARLEN_LONG);
					ExtractBpaField(4, 13, strLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					strcpy(pBpaBlock->m_BpaDat_AreaArray[pBpaBlock->m_nRecordNum[BPA_DAT_AREA]].szName, szBuffer);
					z2aBuf.strAreaName=szBuffer;

					memset(szBuffer, 0, MDB_CHARLEN_LONG);
					ExtractBpaField(14, 21, strLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					strcpy(pBpaBlock->m_BpaDat_AreaArray[pBpaBlock->m_nRecordNum[BPA_DAT_AREA]].szSlackBusName, szBuffer);

					memset(szBuffer, 0, MDB_CHARLEN_LONG);
					ExtractBpaField(22, 25, strLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					pBpaBlock->m_BpaDat_AreaArray[pBpaBlock->m_nRecordNum[BPA_DAT_AREA]].fSlackBuskV=StringToFloat(szBuffer);

					memset(szBuffer, 0, MDB_CHARLEN_LONG);
					ExtractBpaField(27, 34, strLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					pBpaBlock->m_BpaDat_AreaArray[pBpaBlock->m_nRecordNum[BPA_DAT_AREA]].fOutP=StringToFloat(szBuffer);

					pBpaBlock->m_nRecordNum[BPA_DAT_AREA]++;

					nCol=35;
					while (nCol < (int)strLineArray[nLine].length())
					{
						nBuffer=0;
						if (strLineArray[nLine][nCol] != ' ')
							szBuffer[nBuffer++]=strLineArray[nLine][nCol];
						nCol++;

						if (strLineArray[nLine][nCol] != ' ')
							szBuffer[nBuffer++]=strLineArray[nLine][nCol];
						nCol++;

						szBuffer[nBuffer++]='\0';

						nCol++;

						if (strlen(szBuffer) > 0)
							z2aBuf.strZoneArray.push_back(szBuffer);
					}
					z2aArray.push_back(z2aBuf);
				}
				else if (strLineArray[nLine][1] == 'C' && strLineArray[nLine][2] == '+')
				{
					memset(szBuffer, 0, MDB_CHARLEN_LONG);
					ExtractBpaField(4, 13, strLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);

					nArea=-1;
					for (i=0; i<(int)z2aArray.size(); i++)
					{
						if (stricmp(szBuffer, z2aArray[i].strAreaName.c_str()) == 0)
						{
							nArea=i;
							break;
						}
					}
					if (nArea >= 0)
					{
						nCol=35;
						while (nCol < (int)strLineArray[nLine].length())
						{
							nBuffer=0;
							if (strLineArray[nLine][nCol] != ' ')
								szBuffer[nBuffer++]=strLineArray[nLine][nCol];
							nCol++;

							if (strLineArray[nLine][nCol] != ' ')
								szBuffer[nBuffer++]=strLineArray[nLine][nCol];
							nCol++;

							szBuffer[nBuffer++]='\0';

							nCol++;

							if (strlen(szBuffer) > 0)
								z2aArray[nArea].strZoneArray.push_back(szBuffer);
						}
					}
				}
			}
			else if (strLineArray[nLine][0] == 'I')
			{
				strcpy(pBpaBlock->m_BpaDat_IArray[pBpaBlock->m_nRecordNum[BPA_DAT_I]].szCardKey, "I");

				memset(szBuffer, 0, MDB_CHARLEN_LONG);
				ExtractBpaField(4, 13, strLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				strcpy(pBpaBlock->m_BpaDat_IArray[pBpaBlock->m_nRecordNum[BPA_DAT_I]].szArea1, szBuffer);

				memset(szBuffer, 0, MDB_CHARLEN_LONG);
				ExtractBpaField(14, 24, strLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				strcpy(pBpaBlock->m_BpaDat_IArray[pBpaBlock->m_nRecordNum[BPA_DAT_I]].szArea2, szBuffer);

				memset(szBuffer, 0, MDB_CHARLEN_LONG);
				ExtractBpaField(27, 34, strLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				pBpaBlock->m_BpaDat_IArray[pBpaBlock->m_nRecordNum[BPA_DAT_I]].fOutP=StringToFloat(szBuffer);

				pBpaBlock->m_nRecordNum[BPA_DAT_I]++;
			}
		}
	}

	void CBpaMemDBInterface::ParseDatControl(tagBpaBlock* pBpaBlock, std::vector<std::string> strLineArray)
	{
		register int	i;
		int		nLine;
		char*	lpszToken;
		char	szLine[512];
		int		nSection;
		std::vector<std::string>	strEleArray;

		memset(&pBpaBlock->m_BpaDat_Case, 0, sizeof(tagBpaDat_Case));
		pBpaBlock->m_nRecordNum[BPA_DAT_CASE]=1;

		pBpaBlock->m_BpaDat_Case.fMVABase=100;
		pBpaBlock->m_BpaDat_Case.nDecoupledNum=20;
		pBpaBlock->m_BpaDat_Case.nNewtonNum=20;
		pBpaBlock->m_BpaDat_Case.fToleranceBusV=(float)0.005;
		pBpaBlock->m_BpaDat_Case.fToleranceAIPower=(float)0.005;
		pBpaBlock->m_BpaDat_Case.fToleranceTX=(float)0.005;
		pBpaBlock->m_BpaDat_Case.fToleranceQ=(float)0.005;
		pBpaBlock->m_BpaDat_Case.fToleranceOpcut=(float)0.0001;

		for (nLine=0; nLine<(int)strLineArray.size(); nLine++)
		{
			if (strLineArray[nLine][0] == '(')	//	һ������
			{
				nSection=-1;
				strcpy(szLine, strLineArray[nLine].c_str());

				strEleArray.clear();
				lpszToken=strtok(szLine, " =\t\n, ()");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, " =\t\n, ()");
				}
				for (i=0; i<(int)strEleArray.size(); i++)
				{
					if (stricmp(strEleArray[i].c_str(), "CASEID") == 0)
					{
						if ((int)strEleArray.size() > i+1)	strcpy(pBpaBlock->m_BpaDat_Case.szCaseID, strEleArray[i+1].c_str());
					}
					if (stricmp(strEleArray[i].c_str(), "PROJECT") == 0)
					{
						if ((int)strEleArray.size() > i+1)	strcpy(pBpaBlock->m_BpaDat_Case.szProject, strEleArray[i+1].c_str());
					}
				}
			}
			else if (strLineArray[nLine][0] == '/')	//	��������
			{
				strcpy(szLine, strLineArray[nLine].c_str());

				strEleArray.clear();
				lpszToken=strtok(szLine, " =\t\n, /\\");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, " =\t\n, /\\");
				}

				nSection=-1;
				for (i=0; i<(int)strEleArray.size(); i++)
				{
					if (stricmp(strEleArray[i].c_str(), "MVA_BASE") == 0 || stricmp(strEleArray[i].c_str(), "MVABASE") == 0)
					{
						if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.fMVABase=StringToFloat(strEleArray[i+1].c_str());
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "NEW_BASE") == 0 || stricmp(strEleArray[i].c_str(), "NEWBASE") == 0)
					{
						if ((int)strEleArray.size() > i+2)
						{
							if (stricmp(strEleArray[i+1].c_str(), "FILE") == 0)
								strcpy(pBpaBlock->m_BpaDat_Case.szNewBase, strEleArray[i+2].c_str());
						}
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "OLD_BASE") == 0 || stricmp(strEleArray[i].c_str(), "OLDBASE") == 0)
					{
						if ((int)strEleArray.size() > i+2)
						{
							if (stricmp(strEleArray[i+1].c_str(), "FILE") == 0)
								strcpy(pBpaBlock->m_BpaDat_Case.szOldBase, strEleArray[i+2].c_str());
						}
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "PF_MAP") == 0 || stricmp(strEleArray[i].c_str(), "PFMAP") == 0)
					{
						if ((int)strEleArray.size() > i+2)
						{
							if (stricmp(strEleArray[i+1].c_str(), "FILE") == 0)
								strcpy(pBpaBlock->m_BpaDat_Case.szMap, strEleArray[i+2].c_str());
						}
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "INCLUDE_CONTROL") == 0 || stricmp(strEleArray[i].c_str(), "INCLUDECONTROL") == 0)
					{
						if ((int)strEleArray.size() > i+2)
						{
							if (stricmp(strEleArray[i+1].c_str(), "FILE") == 0)
								strcpy(pBpaBlock->m_BpaDat_Case.szControl, strEleArray[i+2].c_str());
						}
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "BRANCH_DATA") == 0 || stricmp(strEleArray[i].c_str(), "BRANCHDATA") == 0)
					{
						if ((int)strEleArray.size() > i+2)
						{
							if (stricmp(strEleArray[i+1].c_str(), "FILE") == 0)
								strcpy(pBpaBlock->m_BpaDat_Case.szBranch, strEleArray[i+2].c_str());
						}
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "BUS_DATA") == 0 || stricmp(strEleArray[i].c_str(), "BUSDATA") == 0)
					{
						if ((int)strEleArray.size() > i+2)
						{
							if (stricmp(strEleArray[i+1].c_str(), "FILE") == 0)
								strcpy(pBpaBlock->m_BpaDat_Case.szBus, strEleArray[i+2].c_str());
						}
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "NETWORK_DATA") == 0 || stricmp(strEleArray[i].c_str(), "NETWORKDATA") == 0)
					{
						if ((int)strEleArray.size() > i+2)
						{
							if (stricmp(strEleArray[i+1].c_str(), "FILE") == 0)
								strcpy(pBpaBlock->m_BpaDat_Case.szNetwork, strEleArray[i+2].c_str());
						}
						break;
					}
					else if (stricmp(strEleArray[i].c_str(), "SOLUTION") == 0)
					{
						nSection=1;
					}
				}
			}
			else if (strLineArray[nLine][0] == '>')	//	��������
			{
				strcpy(szLine, strLineArray[nLine].c_str());

				strEleArray.clear();
				lpszToken=strtok(szLine, " =\t\n, <>");
				while (lpszToken != NULL)
				{
					strEleArray.push_back(lpszToken);
					lpszToken=strtok(NULL, " =\t\n, <>");
				}
				if (nSection == 1)
				{
					if (stricmp(strEleArray[0].c_str(), "AI_CONTROL") == 0 || stricmp(strEleArray[0].c_str(), "AICONTROL") == 0)
					{
						if (strEleArray.size() > 1)
						{
							pBpaBlock->m_BpaDat_Case.nAIControl=BpaGetFieldEnumValue(BPA_DAT_CASE, BPA_DAT_CASE_AICONTROL, strEleArray[1].c_str());
							if (pBpaBlock->m_BpaDat_Case.nAIControl < 0)
								pBpaBlock->m_BpaDat_Case.nAIControl=0;
							//for (j=0; j<BpaGetFieldEnumNum(BPA_DAT_CASE, BPA_DAT_CASE_AICONTROL); j++)
							//{
							//	if (stricmp(strEleArray[1].c_str(), BpaGetFieldEnumString(BPA_DAT_CASE, BPA_DAT_CASE_AICONTROL, j)) == 0)
							//	{
							//		pBpaBlock->m_BpaDat_Case.nAIControl=BpaGetFieldEnumValue(BPA_DAT_CASE, BPA_DAT_CASE_AICONTROL, strEleArray[1].c_str());
							//		break;
							//	}
							//}
						}
					}
					else if (stricmp(strEleArray[0].c_str(), "LTC") == 0)
					{
						if (strEleArray.size() > 1)
						{
							pBpaBlock->m_BpaDat_Case.nLTC=BpaGetFieldEnumValue(BPA_DAT_CASE, BPA_DAT_CASE_LTC, strEleArray[1].c_str());
							if (pBpaBlock->m_BpaDat_Case.nLTC < 0)
								pBpaBlock->m_BpaDat_Case.nLTC=0;
							//for (j=0; j<sizeof(g_BpaEnumCase_LTC)/sizeof(tagMemDBEnumPair); j++)
							//{
							//	if (stricmp(strEleArray[1].c_str(), g_BpaEnumCase_LTC[j].lpszEnumString) == 0)
							//	{
							//		pBpaBlock->m_BpaDat_Case.nLTC=j;
							//		break;
							//	}
							//}
						}
					}
					else if (stricmp(strEleArray[0].c_str(), "SOL_ITER") == 0 || stricmp(strEleArray[0].c_str(), "SOLITER") == 0)
					{
						for (i=0; i<(int)strEleArray.size(); i++)
						{
							if (stricmp(strEleArray[i].c_str(), "DECOUPLED") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.nDecoupledNum=(short)atoi(strEleArray[i+1].c_str());
							}
							else if (stricmp(strEleArray[i].c_str(), "CURRENT") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.nCurrentNum=(short)atoi(strEleArray[i+1].c_str());
							}
							else if (stricmp(strEleArray[i].c_str(), "NEWTON") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.nNewtonNum=(short)atoi(strEleArray[i+1].c_str());
							}
							else if (stricmp(strEleArray[i].c_str(), "OPTIM") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.nOptimNum=(short)atoi(strEleArray[i+1].c_str());
							}
						}
					}
					else if (stricmp(strEleArray[0].c_str(), "TOLERANCE") == 0)
					{
						for (i=0; i<(int)strEleArray.size(); i++)
						{
							if (stricmp(strEleArray[i].c_str(), "BUSV") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.fToleranceBusV=StringToFloat(strEleArray[i+1].c_str());
							}
							else if (stricmp(strEleArray[i].c_str(), "AIPOWER") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.fToleranceAIPower=StringToFloat(strEleArray[i+1].c_str());
							}
							else if (stricmp(strEleArray[i].c_str(), "TX") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.fToleranceTX=StringToFloat(strEleArray[i+1].c_str());
							}
							else if (stricmp(strEleArray[i].c_str(), "Q") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.fToleranceQ=StringToFloat(strEleArray[i+1].c_str());
							}
							else if (stricmp(strEleArray[i].c_str(), "OPCUT") == 0)
							{
								if ((int)strEleArray.size() > i+1)	pBpaBlock->m_BpaDat_Case.fToleranceOpcut=StringToFloat(strEleArray[i+1].c_str());
							}
						}
					}
				}
			}
		}
	}

	int CBpaMemDBInterface::BpaFiles2MemDB_Dat(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const double fZeroImpendance)
	{
		register int	i;
		int		nLine, nDictIni, nBpaTable, nRecord, nField;
		unsigned char	bFlag, bDataEndFlag;
		//float	fTPBuffer;
		std::string		strPrevKey;
		std::vector<std::string>	strDatLineArray;
		std::vector<tagBpaZone2Area>	z2aArray;
		z2aArray.clear();

		FILE*	fp;
		char	szFileName[260], szLine[1024], szKey[10];
		char	szField[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];
		//char	szRestValue[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<MAXMDBFIELDNUM; i++)
			memset(szField[i], 0, MDB_CHARLEN_LONG);

		for (i=0; i<BpaGetTableNum(); i++)
			pBpaBlock->m_nRecordNum[i]=0;

		strDatLineArray.clear();
		strPrevKey.clear();

		//	1.����BPA��DAT�ļ�������Ϣ
		if (lpszBpaDatFile)
		{
			strcpy(szFileName, lpszBpaDatFile);
			if (strstr(strupr(szFileName), ".DAT") == NULL)
				sprintf(szFileName, "%s.dat", lpszBpaDatFile);
			else
				strcpy(szFileName, lpszBpaDatFile);

			fp=fopen(szFileName, "r");
			if (fp != NULL)
			{
				while (!feof(fp))
				{
					memset(szLine, 0, 1024);
					fgets(szLine, 1024, fp);
					if (szLine[0] == ' ')
						szLine[0]='.';

					if (strstr(szLine, "��") != NULL)
					{
						std::string				strBuf=szLine;

						std::string				strRep="��";
						std::string::size_type	nSize=strRep.size();
						std::string::size_type	pos=0;

						while ((pos=strBuf.find(strRep, pos)) != std::string::npos)
						{
							strBuf.replace(pos, nSize, "  ");
							pos += nSize;
						}

						strcpy(szLine, strBuf.c_str());
					}

					TrimEnd(szLine);
					TrimLeft(szLine);
					TrimRight(szLine);
					if (szLine[0] != '.' && szLine[0] != 'C' && szLine[0] != 'c')
						strDatLineArray.push_back(szLine);
				}
				fclose(fp);
			}
		}

		if (strDatLineArray.empty())
			return 0;

		//	2.����BPA�ĳ���������Ϣ��
		ParseDatControl(pBpaBlock, strDatLineArray);
		ParseDatAI(pBpaBlock, strDatLineArray, z2aArray);

		//	3.����BPA�ĳ���������Ϣ��
		bDataEndFlag=0;
		for (nLine=0; nLine<(int)strDatLineArray.size(); nLine++)
		{
			if (strDatLineArray[nLine].length() <= 0)
				continue;

			if (bDataEndFlag != 0)
				continue;

			strcpy(szLine, strDatLineArray[nLine].c_str());
			if (strDatLineArray[nLine][0] == '.' || strDatLineArray[nLine][0] == 'C'  || strDatLineArray[nLine][0] == 'c' || strstr(strupr(szLine), "(END)") != NULL)
			{
				if (strstr(strupr(szLine), "(END)") != NULL)
					bDataEndFlag=1;
				continue;
			}
			if (strDatLineArray[nLine][0] == '(' || strDatLineArray[nLine][0] == '/' || strDatLineArray[nLine][0] == '>')
				continue;

			memset(szKey, 0, 10);
			BpaResolveLineKey(strDatLineArray[nLine].c_str(), szKey);

			if (BpaIsCardKeyAppend(BpaDatCategory_Dat, szKey))
			{
				strPrevKey = szKey;

				nDictIni=nBpaTable=-1;
				nDictIni=BpaGetTableDictIndex(szKey, BpaDatCategory_Dat);
				if (nDictIni >= 0)
					nBpaTable=BpaGetTableIndex(BpaGetDictTable(nDictIni));

				if (nDictIni < 0 || nBpaTable < 0)
				{
					Log(g_lpszLogFile, "BPA�����������޷�����: %s\n", strDatLineArray[nLine].c_str());
					continue;
				}

				BpaString2FieldArray(nBpaTable, nDictIni, strDatLineArray[nLine].c_str(), szField);
				BpaAppendRecord(pBpaBlock, MDB_NoNeedCheckData, nBpaTable, szField);
			}
			else
			{
#ifdef _DEBUG
				if (stricmp(szKey, "+") == 0)
					Log(g_lpszLogFile, "�����ڵ㿨Ϊ��������: %s\n", strDatLineArray[nLine].c_str());
#endif

				nDictIni=BpaGetTableDictIndex(szKey, BpaDatCategory_Dat);
				if (nDictIni >= 0)
					nBpaTable=BpaGetTableIndex(BpaGetDictTable(nDictIni));
				if (nDictIni < 0 || nBpaTable < 0)
				{
					Log(g_lpszLogFile, "BPA���������У����������޷�����: %s\n", strDatLineArray[nLine].c_str());
					continue;
				}

				BpaString2FieldArray(nBpaTable, nDictIni, strDatLineArray[nLine].c_str(), szField);

				//for (i=0; i<BpaGetTablePrimaryKeyNum(nBpaTable); i++)
				//	strcpy(szRestValue[i], szField[BpaGetTablePrimaryKey(nBpaTable, i)]);
				//nRecord=BpaFindRecordbyKey(pBpaBlock, nBpaTable, szRestValue);
				nRecord = pBpaBlock->m_nRecordNum[nBpaTable]-1;
				if (nRecord >= 0)
				{
					for (i=nDictIni; i<BpaGetDictNum(); i++)
					{
						if (stricmp(BpaGetDictCardKey(i), BpaGetDictCardKey(nDictIni)) != 0)
							break;

						if (!BpaGetDictModified(i))
							continue;

						nField=BpaGetFieldIndex(nBpaTable, BpaGetDictFieldName(i));
						if (nField < 0)
							continue;

						BpaSetRecordValue(pBpaBlock, nBpaTable, nField, nRecord, szField[nField]);
					}
				}
			}
		}

		//	5.����ĸ���γ�BPA�ķ�����
		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nRecord++)
		{
			bFlag=0;
			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ZONE]; i++)
			{
				if (stricmp(pBpaBlock->m_BpaDat_ACBusArray[nRecord].szZone, pBpaBlock->m_BpaDat_ZoneArray[i].szName) == 0)
				{
					bFlag=1;
					break;
				}
			}
			if (!bFlag)
				strcpy(pBpaBlock->m_BpaDat_ZoneArray[pBpaBlock->m_nRecordNum[BPA_DAT_ZONE]++].szName, pBpaBlock->m_BpaDat_ACBusArray[nRecord].szZone);
		}

		strDatLineArray.clear();

		BpaMaint(pBpaBlock, fZeroImpendance);

		//	6.�������
		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nRecord++)
		{
			if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nRecord].szZone) > 0)
				continue;

			for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; i++)
			{
				if (pBpaBlock->m_BpaDat_WindArray[i].nIBus < 0 || pBpaBlock->m_BpaDat_WindArray[i].nZBus < 0)
					continue;

				if (stricmp(pBpaBlock->m_BpaDat_WindArray[i].szBusI, pBpaBlock->m_BpaDat_ACBusArray[nRecord].szName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_WindArray[i].fkVI - pBpaBlock->m_BpaDat_ACBusArray[nRecord].fkV) < 0.1)
				{
					if (strlen(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szZone) > 0)
					{
						strcpy(pBpaBlock->m_BpaDat_ACBusArray[nRecord].szZone, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szZone);
						break;
					}
				}
				else if (stricmp(pBpaBlock->m_BpaDat_WindArray[i].szBusJ, pBpaBlock->m_BpaDat_ACBusArray[nRecord].szName) == 0 &&
					fabs(pBpaBlock->m_BpaDat_WindArray[i].fkVJ - pBpaBlock->m_BpaDat_ACBusArray[nRecord].fkV) < 0.1)
				{
					if (strlen(pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szZone) > 0)
					{
						strcpy(pBpaBlock->m_BpaDat_ACBusArray[nRecord].szZone, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szZone);
						break;
					}
				}
			}
		}

		//	7.�ɷ���������
		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_ZONE]; nRecord++)
		{
			bFlag=0;
			for (nLine=0; nLine<(int)z2aArray.size(); nLine++)
			{
				for (i=0; i<(int)z2aArray[nLine].strZoneArray.size(); i++)
				{
					if (stricmp(z2aArray[nLine].strZoneArray[i].c_str(), pBpaBlock->m_BpaDat_ZoneArray[nRecord].szName) == 0)
					{
						strcpy(pBpaBlock->m_BpaDat_ZoneArray[nRecord].szArea, z2aArray[nLine].strAreaName.c_str());
						bFlag=1;
						break;
					}
				}
				if (bFlag)
					break;
			}
		}
		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_ACLINE]; nRecord++)
		{
			strcpy(pBpaBlock->m_BpaDat_ACLineArray[nRecord].szIniBusI, pBpaBlock->m_BpaDat_ACLineArray[nRecord].szBusI);
			strcpy(pBpaBlock->m_BpaDat_ACLineArray[nRecord].szIniBusJ, pBpaBlock->m_BpaDat_ACLineArray[nRecord].szBusJ);
			pBpaBlock->m_BpaDat_ACLineArray[nRecord].fInikVI=pBpaBlock->m_BpaDat_ACLineArray[nRecord].fkVI;
			pBpaBlock->m_BpaDat_ACLineArray[nRecord].fInikVJ=pBpaBlock->m_BpaDat_ACLineArray[nRecord].fkVJ;
			pBpaBlock->m_BpaDat_ACLineArray[nRecord].cIniLoop=pBpaBlock->m_BpaDat_ACLineArray[nRecord].cLoop;
		}

		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_WIND]; nRecord++)
		{
			strcpy(pBpaBlock->m_BpaDat_WindArray[nRecord].szIniBusI, pBpaBlock->m_BpaDat_WindArray[nRecord].szBusI);
			strcpy(pBpaBlock->m_BpaDat_WindArray[nRecord].szIniBusJ, pBpaBlock->m_BpaDat_WindArray[nRecord].szBusJ);
			pBpaBlock->m_BpaDat_WindArray[nRecord].fInikVI=pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI;
			pBpaBlock->m_BpaDat_WindArray[nRecord].fInikVJ=pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ;
			pBpaBlock->m_BpaDat_WindArray[nRecord].cIniLoop=pBpaBlock->m_BpaDat_WindArray[nRecord].cLoop;

// 			if (fabs(pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI - pBpaBlock->m_BpaDat_WindArray[nRecord].fTPI) > pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI/5 &&
// 				fabs(pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ - pBpaBlock->m_BpaDat_WindArray[nRecord].fTPJ) > pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ/5)
// 			{
// 				fTPBuffer = pBpaBlock->m_BpaDat_WindArray[nRecord].fTPI;
// 				pBpaBlock->m_BpaDat_WindArray[nRecord].fTPI = pBpaBlock->m_BpaDat_WindArray[nRecord].fTPJ;
// 				pBpaBlock->m_BpaDat_WindArray[nRecord].fTPJ = fTPBuffer;
// 			}
			if (fabs(pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI - pBpaBlock->m_BpaDat_WindArray[nRecord].fTPI) > pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI/2.5)
				pBpaBlock->m_BpaDat_WindArray[nRecord].fTPI = pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI;
			if (fabs(pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ - pBpaBlock->m_BpaDat_WindArray[nRecord].fTPJ) > pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ/2.5)
				pBpaBlock->m_BpaDat_WindArray[nRecord].fTPJ = pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ;
		}

		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_LINEHG]; nRecord++)
		{
			strcpy(pBpaBlock->m_BpaDat_LineHGArray[nRecord].szIniBusI, pBpaBlock->m_BpaDat_LineHGArray[nRecord].szBusI);
			strcpy(pBpaBlock->m_BpaDat_LineHGArray[nRecord].szIniBusJ, pBpaBlock->m_BpaDat_LineHGArray[nRecord].szBusJ);
			pBpaBlock->m_BpaDat_LineHGArray[nRecord].fInikVI=pBpaBlock->m_BpaDat_LineHGArray[nRecord].fkVI;
			pBpaBlock->m_BpaDat_LineHGArray[nRecord].fInikVJ=pBpaBlock->m_BpaDat_LineHGArray[nRecord].fkVJ;
			pBpaBlock->m_BpaDat_LineHGArray[nRecord].cIniLoop=pBpaBlock->m_BpaDat_LineHGArray[nRecord].cLoop;
		}

		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nRecord++)
		{
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniPGen = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fPGen;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniQGen = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fQsched_Qmax;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniLoadP = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fLoadP;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniLoadQ = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fLoadQ;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniShuntP = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fShuntP;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniShuntQ = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fShuntQ;

			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniAddPGen = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fAddPGen;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniAddQGen = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fAddQGen;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniAddLoadP = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fAddLoadP;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniAddLoadQ = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fAddLoadQ;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniAddShuntP = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fAddShuntP;
			pBpaBlock->m_BpaDat_ACBusArray[nRecord].fIniAddShuntQ = pBpaBlock->m_BpaDat_ACBusArray[nRecord].fAddShuntQ;
		}

		for (nRecord=0; nRecord<pBpaBlock->m_nRecordNum[BPA_DAT_P]; nRecord++)
		{
			pBpaBlock->m_BpaDat_PArray[nRecord].fIniLoadPFactor = pBpaBlock->m_BpaDat_PArray[nRecord].fLoadPFactor;
			pBpaBlock->m_BpaDat_PArray[nRecord].fIniLoadQFactor = pBpaBlock->m_BpaDat_PArray[nRecord].fLoadQFactor;
			pBpaBlock->m_BpaDat_PArray[nRecord].fIniGenPFactor = pBpaBlock->m_BpaDat_PArray[nRecord].fGenPFactor;
			pBpaBlock->m_BpaDat_PArray[nRecord].fIniGenQFactor = pBpaBlock->m_BpaDat_PArray[nRecord].fGenQFactor;
		}

		return 1;
	}

	int CBpaMemDBInterface::BpaMemDB2Files_Dat(tagBpaBlock* pBpaBlock, FILE* fp)
	{
		fprintf(fp, "(POWERFLOW, CASEID=%s, PROJECT=%s)\n", pBpaBlock->m_BpaDat_Case.szCaseID, pBpaBlock->m_BpaDat_Case.szProject);
		fprintf(fp, "/NEW_BASE, FILE=%s\\\n", pBpaBlock->m_BpaDat_Case.szNewBase);
		fprintf(fp, "/MVA_BASE=%.0f\\\n", pBpaBlock->m_BpaDat_Case.fMVABase);			//	��׼����

		//	�����̿���
		//fprintf(fp, "/SOLUTION\\\n");					//	��������������������ݺ�����Ϊ�����������
		if (pBpaBlock->m_BpaDat_Case.nAIControl == Case_AIControl_CON)			fprintf(fp, "/AI_CONTROL=CON\\\n");			//	�����߿��ƣ�ȱʡ
		else if (pBpaBlock->m_BpaDat_Case.nAIControl == Case_AIControl_MON)		fprintf(fp, "/AI_CONTROL=MON\\\n");			//	�����߲����ƣ�����
		else																	fprintf(fp, "/AI_CONTROL=OFF\\\n");			//	�����߲�����

		fprintf(fp, "/SOL_ITER, DECOUPLED=%d, CURRENT=0, NEWTON=%d, OPITM=0\\\n",
			pBpaBlock->m_BpaDat_Case.nDecoupledNum, pBpaBlock->m_BpaDat_Case.nNewtonNum);
		fprintf(fp, "/TOLERANCE, BUSV=%f, AIPOWER=%f, TX=.005, Q=%f, OPCUT=.0001\\\n",
			pBpaBlock->m_BpaDat_Case.fToleranceBusV, pBpaBlock->m_BpaDat_Case.fToleranceAIPower, pBpaBlock->m_BpaDat_Case.fToleranceQ);

		//	ԭʼ���ݺͼ��������

		//	���򽻻����ʿ��Ƽ��������ѡ��
		fprintf(fp, "/AI_LIST=FULL\\\n");			//	ȫ�����

		//	�����ԭʼ�������ѡ��
		fprintf(fp, "./P_INPUT_LIST, NONE\\\n");		//	�����

		//	�������
		if (pBpaBlock->m_BpaDat_Case.nRptSort == 0)
			fprintf(fp, "/RPT_SORT=BUS\\\n");
		else if (pBpaBlock->m_BpaDat_Case.nRptSort == 1)
			fprintf(fp, "/RPT_SORT=ZONE\\\n");
		else if (pBpaBlock->m_BpaDat_Case.nRptSort == 2)
			fprintf(fp, "/RPT_SORT=AREA\\\n");

		//	���ѡ��
		fprintf(fp, "/P_OUTPUT_LIST, FULL\\\n");

		fprintf(fp, "/P_ANALYSIS_RPT, LEVEL=%d\\\n", pBpaBlock->m_BpaDat_Case.nAnalysisRpt);

		if (strlen(pBpaBlock->m_BpaDat_Case.szMap) > 0)
			fprintf(fp, "/PF_MAP, FILE=%s\\\n", pBpaBlock->m_BpaDat_Case.szMap);	//	�°�����ͼ��������

		fprintf(fp, "\n/NETWORK_DATA\\\n");

		register int	i;
		char	szLine[256], szLine1[256], szLine2[256], szLine3[256];
		char	szField[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];
		int		nDev, nTable, nDictIni;

		fprintf(fp, "\n.ĸ�����ݼ���\n");
		//Log(g_lpszLogFile, "ĸ�����ݼ���\n");
		nTable=BPA_DAT_ACBUS;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			if (!pBpaBlock->m_BpaDat_ACBusArray[nDev].bReduction)
				continue;

			if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nDev].szAddCode) > 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);
				BpaDataPtr2FieldArray(nTable, (char*)&pBpaBlock->m_BpaDat_ACBusArray[nDev], szField);
				BpaFieldArray2LineString(nTable, szField, szLine1, szLine2, szLine3);
				if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
				if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
				if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
				fprintf(fp, "\n");
				//Log(g_lpszLogFile, "BPAĸ������: [%s] [%s]\n", szLine1, szLine2);
			}
			else
			{
				for (i=0; i<255; i++)
					szLine[i]=' ';
				szLine[255]='\0';
				nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_ACBusArray[nDev].szCardKey, BpaDatCategory_Dat);
				if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_ACBusArray[nDev], szLine) <= 0)
					return 0;
				fprintf(fp, "%s\n", szLine);
			}
		}

		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			if (pBpaBlock->m_BpaDat_ACBusArray[nDev].bReduction)
				continue;

			if (strlen(pBpaBlock->m_BpaDat_ACBusArray[nDev].szAddCode) > 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);
				BpaDataPtr2FieldArray(nTable, (char*)&pBpaBlock->m_BpaDat_ACBusArray[nDev], szField);
				BpaFieldArray2LineString(nTable, szField, szLine1, szLine2, szLine3);
				if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
				if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
				if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
				fprintf(fp, "\n");
				//Log(g_lpszLogFile, "BPAĸ������: [%s] [%s]\n", szLine1, szLine2);
			}
			else
			{
				for (i=0; i<255; i++)
					szLine[i]=' ';
				szLine[255]='\0';

				nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_ACBusArray[nDev].szCardKey, BpaDatCategory_Dat);
				if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_ACBusArray[nDev], szLine) <= 0)
					return 0;

				fprintf(fp, "%s\n", szLine);
			}
		}

		fprintf(fp, "\n\n.������·���ݼ���\n");
		nTable=BPA_DAT_ACLINE;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_ACLineArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_ACLineArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}

		fprintf(fp, "\n\n.��ѹ�����ݼ���\n");
		nTable=BPA_DAT_WIND;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_WindArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_WindArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}

		fprintf(fp, "\n\n.�߿����ݼ���\n");
		nTable=BPA_DAT_LINEHG;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_LineHGArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_LineHGArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}

		fprintf(fp, "\n\n.ֱ��ĸ�����ݼ���\n");
		nTable=BPA_DAT_DCBUS;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_DCBusArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_DCBusArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}

		fprintf(fp, "\n\n.ֱ����·���ݼ���\n");
		nTable=BPA_DAT_DCLINE;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_DCLineArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_DCLineArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}

		fprintf(fp, "\n\n.��ѹ����װ�����ݼ���\n");
		nTable=BPA_DAT_R;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_RArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_RArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}

		fprintf(fp, "\n\n.�������ݼ���\n");
		nTable=BPA_DAT_RZ;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_RZArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_RZArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}

		fprintf(fp, "\n/CHANGES\\\n");
		nTable=BPA_DAT_P;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			for (i=0; i<255; i++)
				szLine[i]=' ';
			szLine[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaDat_PArray[nDev].szCardKey, BpaDatCategory_Dat);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaDat_PArray[nDev], szLine) <= 0)
				return 0;

			fprintf(fp, "%s\n", szLine);
		}
		fprintf(fp, "\n");

		fprintf(fp, "(END)\n");

		return 1;
	}
}