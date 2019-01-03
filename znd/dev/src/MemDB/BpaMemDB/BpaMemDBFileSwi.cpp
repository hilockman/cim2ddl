#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include "BpaDictSwiData.h"
#include "../../Common/StringCommon.h"
#include "../../Common/String2Double.hpp"

#include <float.h>
namespace	BpaMemDB
{
	void CBpaMemDBInterface::BpaDictLineString2FieldArray(const int nBpaTable, const int nDictFieldNum, tagBpa_Dict dictArray[], const char* lpszBpaLine, char szField[][MDB_CHARLEN_LONG])
	{
		int		nField;
		for (nField=0; nField<nDictFieldNum; nField++)
		{
			ExtractBpaField(dictArray[nField].nFieldStart, dictArray[nField].nFieldEnd, lpszBpaLine, szField[nField]);
			if (dictArray[nField].nFieldType == MDB_FLOAT && strlen(szField[nField]) > 0)
				CheckDecimal(szField[nField], dictArray[nField].nFieldDecimal);
			Trim(szField[nField]);
		}

		BpaFormTableKeyField(nBpaTable, szField);
	}

	int	CBpaMemDBInterface::BpaDictFieldArray2LineString(const int nBpaTable, const int nDictFieldNum, tagBpa_Dict dictFieldArray[], const char szField[][MDB_CHARLEN_LONG], char* lpszRetLine)
	{
		register int	i;
		int		nField, nIni, nEnd, nDecimal, nDataLen;
		char	szValue[MDB_CHARLEN];

		if (nDictFieldNum <= 0)
			return 0;

		for (i=0; i<MDB_CHARLEN_LONG-1; i++)
			lpszRetLine[i]=' ';

		for (nField=0; nField<nDictFieldNum; nField++)
		{
			nIni=		dictFieldArray[nField].nFieldStart;
			nEnd=		dictFieldArray[nField].nFieldEnd;
			nDataLen=	dictFieldArray[nField].nFieldLen;
			nDecimal=	dictFieldArray[nField].nFieldDecimal;
			if (nIni <= 0 || nDataLen <= 0)
				continue;

			strcpy(szValue, szField[nField]);

			for (i=0; i<nDataLen; i++)
				lpszRetLine[i+nIni-1]=' ';
			switch (BpaGetFieldType(nBpaTable, nField))
			{
			case MDB_FLOAT:
				if (fabs(StringToFloat(szValue)) > 0.00000001)
				{
					if (strstr(szValue, ".") == NULL)
					{
						if (nDecimal == 0)
						{
							for (i=0; i<strlen(szValue); i++)
								lpszRetLine[nEnd-1-i]=szValue[strlen(szValue)-1-i];
						}
						else
						{
							strcat(szValue, ".");
							BpaFormatDecimalChar(nBpaTable, nField, szValue, nDataLen, nDecimal);
							for (i=0; i<strlen(szValue); i++)
								lpszRetLine[nEnd-1-i]=szValue[strlen(szValue)-1-i];
						}
					}
					else
					{
						BpaFormatDecimalChar(nBpaTable, nField, szValue, nDataLen, nDecimal);
						for (i=0; i<strlen(szValue); i++)
							lpszRetLine[nEnd-1-i]=szValue[strlen(szValue)-1-i];
						//for (i=0; i<nDataLen; i++)
						//{
						//	if (szValue[i] == ' ' || szValue[i] == '\t' || szValue[i] == '\n' || szValue[i] == '\r' || szValue[i] == '\0')
						//		break;
						//	lpszRetLine[i+nIni-1]=szValue[i];
						//}
					}
				}
				break;
			case MDB_STRING:
				for (i=0; i<nDataLen; i++)
				{
					if (szValue[i] == ' ' || szValue[i] == '\t' || szValue[i] == '\n' || szValue[i] == '\r' || szValue[i] == '\0')
						break;
					lpszRetLine[i+nIni-1]=szValue[i];
				}
				break;
			case MDB_INT:
			case MDB_BIT:
			case MDB_SHORT:
				if (atoi(szValue) != 0)
				{
					for (i=0; i<nDataLen; i++)
					{
						if (szValue[i] == ' ' || szValue[i] == '\t' || szValue[i] == '\n' || szValue[i] == '\r' || szValue[i] == '\0')
							break;
						lpszRetLine[i+nIni-1]=szValue[i];
					}
				}
				break;
			case MDB_CHAR:
				if (szValue[0] != ' ' && szValue[0] != '\t' && szValue[0] != '\n' && szValue[0] != '\r' && szValue[0] != '\0')
					lpszRetLine[nIni-1]=szValue[0];
				break;
			}
		}

		TrimRight(lpszRetLine);

		return (int)strlen(lpszRetLine);
	}

	int CBpaMemDBInterface::ParseSwiControl(tagBpaBlock* pBpaBlock, const char* lpszKey, const char* lpszLineString)
	{
		int		nTable, nField;
		char	szField[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];

		for (nField=0; nField<MAXMDBFIELDNUM; nField++)
			memset(szField[nField], 0, MDB_CHARLEN_LONG);
		if (stricmp(lpszKey, "CASE") == 0)	//	������ƿ�
		{
			nTable=BPA_SWI_CASE;
			pBpaBlock->m_nRecordNum[nTable]=0;
			BpaDictLineString2FieldArray(nTable, sizeof(m_BpaSwiCaseDictArray)/sizeof(tagBpa_Dict), m_BpaSwiCaseDictArray, lpszLineString, szField);
			BpaAppendRecord(pBpaBlock, MDB_NoNeedCheckData, nTable, szField);
		}
		else if (stricmp(lpszKey, "F0") == 0)	//	������ƿ�
		{
			nTable=BPA_SWI_F0;
			pBpaBlock->m_nRecordNum[nTable]=0;
			BpaDictLineString2FieldArray(nTable, sizeof(m_BpaSwiF0DictArray)/sizeof(tagBpa_Dict), m_BpaSwiF0DictArray, lpszLineString, szField);
			BpaAppendRecord(pBpaBlock, MDB_NoNeedCheckData, nTable, szField);
		}
		else if (stricmp(lpszKey, "F1") == 0)	//	������ƿ�
		{
			nTable=BPA_SWI_F1;
			pBpaBlock->m_nRecordNum[nTable]=0;
			BpaDictLineString2FieldArray(nTable, sizeof(m_BpaSwiF1DictArray)/sizeof(tagBpa_Dict), m_BpaSwiF1DictArray, lpszLineString, szField);
			BpaAppendRecord(pBpaBlock, MDB_NoNeedCheckData, nTable, szField);
		}
		else if (stricmp(lpszKey, "FF") == 0)	//	������ƿ�
		{
			nTable=BPA_SWI_FF;
			pBpaBlock->m_nRecordNum[nTable]=0;
			BpaDictLineString2FieldArray(nTable, sizeof(m_BpaSwiFFDictArray)/sizeof(tagBpa_Dict), m_BpaSwiFFDictArray, lpszLineString, szField);
			BpaAppendRecord(pBpaBlock, MDB_NoNeedCheckData, nTable, szField);
		}

		return 1;
	}

	void CBpaMemDBInterface::ParseSwiLn(tagBpaBlock* pBpaBlock, std::vector<std::string> strSwiLineArray)
	{
		int		nLine;
		char	szBuffer[MDB_CHARLEN];

		pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]=0;
		for (nLine=0; nLine<(int)strSwiLineArray.size(); nLine++)
		{
			if ((strSwiLineArray[nLine][0] == 'L' || strSwiLineArray[nLine][0] == 'l') &&
				(strSwiLineArray[nLine][1] == 'N' || strSwiLineArray[nLine][1] == 'n'))
			{
				//Log("Find LN=%s\n", strSwiLineArray[nLine].c_str());
				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(4, 11, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				if (strlen(szBuffer) > 0)
				{
					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szBus_Name, szBuffer);

					memset(szBuffer, 0, MDB_CHARLEN);
					ExtractBpaField(12, 15, strSwiLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].fBus_kV=StringToFloat(szBuffer);

					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szCardKey, "LN");
					pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]++;
				}

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(19, 26, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				if (strlen(szBuffer) > 0)
				{
					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szBus_Name, szBuffer);

					memset(szBuffer, 0, MDB_CHARLEN);
					ExtractBpaField(37, 30, strSwiLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].fBus_kV=StringToFloat(szBuffer);

					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szCardKey, "LN");
					pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]++;
				}

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(34, 41, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				if (strlen(szBuffer) > 0)
				{
					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szBus_Name, szBuffer);

					memset(szBuffer, 0, MDB_CHARLEN);
					ExtractBpaField(42, 45, strSwiLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].fBus_kV=StringToFloat(szBuffer);

					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szCardKey, "LN");
					pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]++;
				}

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(49, 56, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				if (strlen(szBuffer) > 0)
				{
					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szBus_Name, szBuffer);

					memset(szBuffer, 0, MDB_CHARLEN);
					ExtractBpaField(57, 60, strSwiLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].fBus_kV=StringToFloat(szBuffer);

					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szCardKey, "LN");
					pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]++;
				}

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(64, 71, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				if (strlen(szBuffer) > 0)
				{
					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szBus_Name, szBuffer);

					memset(szBuffer, 0, MDB_CHARLEN);
					ExtractBpaField(72, 75, strSwiLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].fBus_kV=StringToFloat(szBuffer);

					strcpy(pBpaBlock->m_BpaSwi_GenLnArray[pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]].szCardKey, "LN");
					pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]++;
				}
				//Log("    LNNum=%d\n", pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]);
			}
		}
	}

	void CBpaMemDBInterface::ParseSwiLOZ(tagBpaBlock* pBpaBlock, std::vector<std::string> strSwiLineArray)
	{
		register int	i;
		int		nLine, nZone;
		char	szBuffer[MDB_CHARLEN];
		float	fKG0 ;									//	51	55	F5.4	��·����絼���������絼�ı���
		float	fKB0 ;									//	56	60	F5.4	��·������������������ɵı���
		float	fKGC0;									//	61	65	F5.4	��·�Ե�֧·����絼����ڶԵ�֧·����絼�ı���
		float	fKBC0;									//	66	70	F5.4	��·�Ե�֧·�����������ڶԵ�֧·������ɵı���
		float	fVMIN;									//	71	75	F5.1	��ѹ�ȼ�������Сֵ
		float	fVMAX;									//	76	80	F5.1	��ѹ�ȼ��������ֵ

		for (nLine=0; nLine<(int)strSwiLineArray.size(); nLine++)
		{
			if ((strSwiLineArray[nLine][0] == 'L' || strSwiLineArray[nLine][0] == 'l') &&
				(strSwiLineArray[nLine][1] == 'O' || strSwiLineArray[nLine][1] == 'o') &&
				(strSwiLineArray[nLine][3] == 'Z' || strSwiLineArray[nLine][3] == 'z'))
			{
				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(51, 55, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				fKG0=StringToFloat(szBuffer);

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(56, 60, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				fKB0=StringToFloat(szBuffer);

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(61, 65, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				fKGC0=StringToFloat(szBuffer);

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(66, 70, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				fKBC0=StringToFloat(szBuffer);

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(71, 75, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				fVMIN=StringToFloat(szBuffer);

				memset(szBuffer, 0, MDB_CHARLEN);
				ExtractBpaField(76, 80, strSwiLineArray[nLine].c_str(), szBuffer);
				TrimLeft(szBuffer);
				TrimRight(szBuffer);
				fVMAX=StringToFloat(szBuffer);

				for (nZone=0; nZone<15; nZone++)
				{
					memset(szBuffer, 0, MDB_CHARLEN);
					ExtractBpaField(3*nZone+6, 3*nZone+6+1, strSwiLineArray[nLine].c_str(), szBuffer);
					TrimLeft(szBuffer);
					TrimRight(szBuffer);
					if (strlen(szBuffer) > 0)
					{
						for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ZONE]; i++)
						{
							if (stricmp(szBuffer, pBpaBlock->m_BpaDat_ZoneArray[i].szName) == 0)
							{
								pBpaBlock->m_BpaDat_ZoneArray[i].fKG0 =fKG0 ;
								pBpaBlock->m_BpaDat_ZoneArray[i].fKB0 =fKB0 ;
								pBpaBlock->m_BpaDat_ZoneArray[i].fKGC0=fKGC0;
								pBpaBlock->m_BpaDat_ZoneArray[i].fKBC0=fKBC0;
								pBpaBlock->m_BpaDat_ZoneArray[i].fVMIN=fVMIN;
								pBpaBlock->m_BpaDat_ZoneArray[i].fVMAX=fVMAX;

								break;
							}
						}
					}
				}
			}
		}
	}

	int	CBpaMemDBInterface::BpaFiles2MemDB_Swi(tagBpaBlock* pBpaBlock, const char* lpszBpaSwiFile)
	{
		register int	i;
		int		nLine, nDictIni, nBpaTable, nRecord, nField;
		unsigned char	bCategory, bDataEndFlag, bConFlag;
		std::vector<std::string>	strSwiLineArray;
		std::string					strPrevKey;

		FILE*	fp;
		char	szFileName[260], szLine[1024], szKey[10];
		char	szField[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];
		//char	szRestValue[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];

		strPrevKey.clear();
		strSwiLineArray.clear();
		//	1.����BPA��SWI�ļ�������Ϣ
		if (lpszBpaSwiFile)
		{
			strcpy(szFileName, lpszBpaSwiFile);
			if (strstr(strupr(szFileName), ".SWI") == NULL)
				sprintf(szFileName, "%s.swi", lpszBpaSwiFile);
			else
				strcpy(szFileName, lpszBpaSwiFile);

			fp=fopen(szFileName, "r");
			if (fp != NULL)
			{
				while (!feof(fp))
				{
					memset(szLine, 0, 1024);
					fgets(szLine, 1024, fp);
					TrimEnd(szLine);
					TrimLeft(szLine);
					TrimEnd(szLine);

					if (szLine[0] != '.' && strlen(szLine) > 0)
						strSwiLineArray.push_back(szLine);
				}
				fclose(fp);
			}
		}

		if (strSwiLineArray.empty())
			return 0;

		//	2.����BPA���ȶ�������Ϣ��
		bDataEndFlag=0;
		bConFlag=0;
		for (nLine=0; nLine<(int)strSwiLineArray.size(); nLine++)
		{
			if (strSwiLineArray[nLine].length() <= 0)
				continue;

			if (bDataEndFlag)
				continue;

			if (strSwiLineArray[nLine][0] == '.' || strSwiLineArray[nLine][0] == '/' || strSwiLineArray[nLine][0] == 'C' || strSwiLineArray[nLine][0] == 'c')
			{
				memset(szKey, 0, 10);
				strncpy(szKey, strSwiLineArray[nLine].c_str(), 4);
				if (stricmp(strupr(szKey), "CASE") != 0)
					continue;
				else if (strSwiLineArray[nLine][1] == ' ' || strSwiLineArray[nLine][1] == '/')
					continue;
			}
			memset(szKey, 0, 10);
			BpaResolveLineKey(strSwiLineArray[nLine].c_str(), szKey);

			bCategory=BpaSwiCategory_Dat;
			nDictIni=nBpaTable=-1;
			if (stricmp(szKey, "CASE") == 0 || stricmp(szKey, "F0") == 0 || stricmp(szKey, "F1") == 0)	//	������ƿ�
			{
				ParseSwiControl(pBpaBlock, szKey, strSwiLineArray[nLine].c_str());
				bConFlag=1;
				bCategory=BpaSwiCategory_Con;
				continue;
			}
			if (stricmp(szKey, "FF") == 0 && strSwiLineArray[nLine][3] == ' ')	//	������ƿ�
			{
				ParseSwiControl(pBpaBlock, szKey, strSwiLineArray[nLine].c_str());
				bConFlag=1;
				bCategory=BpaSwiCategory_Con;
				continue;
			}
			if (stricmp(szKey, "90") == 0)	//	�����ʼ��
			{
				bDataEndFlag=1;
				continue;
			}
			if (stricmp(szKey, "LN") == 0)
				continue;

			if (BpaIsCardKeyAppend(bCategory, szKey))
			{
				nDictIni=BpaGetTableDictIndex(szKey, bCategory);
				if (nDictIni >= 0)
					nBpaTable=BpaGetTableIndex(BpaGetDictTable(nDictIni));
				if (nDictIni < 0 || nBpaTable < 0)
				{
					Log(g_lpszLogFile, "BPA�ȶ��������޷�����: %s\n", strSwiLineArray[nLine].c_str());
					continue;
				}

				strPrevKey = szKey;
				BpaString2FieldArray(nBpaTable, nDictIni, strSwiLineArray[nLine].c_str(), szField);
				BpaAppendRecord(pBpaBlock, MDB_NoNeedCheckData, nBpaTable, szField);
			}
			else
			{
				if (stricmp(szKey, "F+") == 0)
					BpaBpaCardKey2DictKeyFx(szKey, strSwiLineArray[nLine].c_str());
				else
					BpaBpaCardKey2DictKey(szKey, strPrevKey.c_str());

				nDictIni=BpaGetTableDictIndex(szKey, bCategory);
				if (nDictIni >= 0)
					nBpaTable=BpaGetTableIndex(BpaGetDictTable(nDictIni));
				if (nDictIni < 0 || nBpaTable < 0)
				{
					Log(g_lpszLogFile, "BPA�ȶ������У����������޷�����: %s\n", strSwiLineArray[nLine].c_str());
					continue;
				}
				BpaString2FieldArray(nBpaTable, nDictIni, strSwiLineArray[nLine].c_str(), szField);

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

		ParseSwiLn(pBpaBlock, strSwiLineArray);
		ParseSwiLOZ(pBpaBlock, strSwiLineArray);
		strSwiLineArray.clear();

		BpaMaint(pBpaBlock);

		return 1;
	}

	int CBpaMemDBInterface::BpaMemDB2Files_Swi(tagBpaBlock* pBpaBlock, FILE* fp)
	{
		register int	i;
		int		nDev, nTable, nDictIni, nRecord;
		char	szLine1[256], szLine2[256], szLine3[256];
		char	szField[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];
		char	szBusName[MDB_CHARLEN_LONG], szBusVolt[MDB_CHARLEN_LONG];
		int		nExcModel, nPssModel, nGovModel, nMovModel;
		int		nGenIndex, nDampIndex, nExcIndex, nPssIndex, nGovIndex, nSvoIndex, nMovIndex;
		tagBpaSwi_GenLn	lnBuf;

		std::vector<unsigned char>	bBusLNOutArray;

		bBusLNOutArray.resize(pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]);
		for (i=0; i<(int)bBusLNOutArray.size(); i++)
			bBusLNOutArray[i]=0;

		memset(szLine1, 0, 256);

		//////////////////////////////////////////////////////////////////////////
		//	������ƿ�
		nTable=BPA_SWI_CASE;
		if (BpaSwi2LineString(nTable, (char*)&pBpaBlock->m_BpaSwi_Case, szLine1) <= 0)
			return 0;
		fprintf(fp, "%s\n", szLine1);
		fprintf(fp, "\n\n");

		//////////////////////////////////////////////////////////////////////////
		//	����Դģ��
		nTable=BPA_SWI_WGEGEN;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".GE���ģ��\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			if (pBpaBlock->m_BpaSwi_WGEGenArray[nDev].nGenBus < 0)
				continue;
			bBusLNOutArray[pBpaBlock->m_BpaSwi_WGEGenArray[nDev].nGenBus]=1;

			for (i=0; i<255; i++)
				szLine1[i]=' ';
			szLine1[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_WGEGenArray[nDev].szCardKey, -1);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_WGEGenArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);

			strcpy(szBusName, pBpaBlock->m_BpaSwi_WGEGenArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_WGEGenArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_RE, szBusName, szBusVolt);
			if (nRecord >= 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);
				BpaDataPtr2FieldArray(BPA_SWI_RE, (char*)&pBpaBlock->m_BpaSwi_REArray[nRecord], szField);
				BpaFieldArray2LineString(BPA_SWI_RE, szField, szLine1, szLine2, szLine3);
				if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
				if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
				if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
				fprintf(fp, "\n");
			}
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_WGWGEN;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".�����ģ��\n");
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			if (pBpaBlock->m_BpaSwi_WGWGenArray[nDev].nGenBus < 0)
				continue;
			bBusLNOutArray[pBpaBlock->m_BpaSwi_WGWGenArray[nDev].nGenBus]=1;

			for (i=0; i<255; i++)
				szLine1[i]=' ';
			szLine1[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_WGWGenArray[nDev].szCardKey, -1);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_WGWGenArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);

			strcpy(szBusName, pBpaBlock->m_BpaSwi_WGWGenArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_WGWGenArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_RE, szBusName, szBusVolt);
			if (nRecord >= 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);
				BpaDataPtr2FieldArray(BPA_SWI_RE, (char*)&pBpaBlock->m_BpaSwi_REArray[nRecord], szField);
				BpaFieldArray2LineString(BPA_SWI_RE, szField, szLine1, szLine2, szLine3);
				if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
				if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
				if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
				fprintf(fp, "\n");
			}
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_PV;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".���ģ��\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			if (pBpaBlock->m_BpaSwi_PVArray[nDev].nGenBus < 0)
				continue;
			bBusLNOutArray[pBpaBlock->m_BpaSwi_PVArray[nDev].nGenBus]=1;

			for (i=0; i<255; i++)
				szLine1[i]=' ';
			szLine1[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_PVArray[nDev].szCardKey, -1);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_PVArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);
		}
		fprintf(fp, "\n\n");

		//////////////////////////////////////////////////////////////////////////
		//	������������ϵͳģ��
		fprintf(fp, ".������������ϵͳģ��\n");
		nTable=BPA_SWI_GEN;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_GEN]; nDev++)
		{
			if (pBpaBlock->m_BpaSwi_GenArray[nDev].nGenBus < 0)
				continue;
			bBusLNOutArray[pBpaBlock->m_BpaSwi_GenArray[nDev].nGenBus]=1;

			BpaResolveGenModel(pBpaBlock, pBpaBlock->m_BpaSwi_GenArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_GenArray[nDev].fBus_kV, pBpaBlock->m_BpaSwi_GenArray[nDev].cID, nGenIndex, nDampIndex,
				nExcModel, nExcIndex, nPssModel, nPssIndex, nGovModel, nGovIndex, nSvoIndex, nMovModel, nMovIndex);
			Log(g_lpszLogFile, "Gen[%s %g] Model=%d %d %d %d %d  %d %d %d %d %d\n", pBpaBlock->m_BpaSwi_GenArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_GenArray[nDev].fBus_kV, nGenIndex,
				nExcModel, nExcIndex, nPssModel, nPssIndex, nGovModel, nGovIndex, nSvoIndex, nMovModel, nMovIndex);

			memset(szLine1, 0, 256);
			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_GenArray[nDev].szCardKey, -1);
			if (nDictIni < 0)
				continue;
			if (BpaDataPtr2LineString(BPA_SWI_GEN, nDictIni, (char*)&pBpaBlock->m_BpaSwi_GenArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);

			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_DAMP, pBpaBlock->m_BpaSwi_GenArray[nDev].szKeyName);
			if (nRecord >= 0)
			{
				memset(szLine1, 0, 256);
				nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_DampArray[nRecord].szCardKey, -1);
				if (nDictIni >= 0)
				{
					if (BpaDataPtr2LineString(BPA_SWI_DAMP, nDictIni, (char*)&pBpaBlock->m_BpaSwi_DampArray[nRecord], szLine1) > 0)
						fprintf(fp, "%s\n", szLine1);
				}
			}

			if (nExcIndex >= 0)
			{
				if (nExcModel == BPA_SWI_EXCITX)
				{
					memset(szLine1, 0, 256);
					memset(szLine2, 0, 256);
					memset(szLine3, 0, 256);
					for (i=0; i<MAXMDBFIELDNUM; i++)
						memset(szField[i], 0, MDB_CHARLEN_LONG);
					BpaDataPtr2FieldArray(nExcModel, (char*)&pBpaBlock->m_BpaSwi_ExcXArray[nExcIndex], szField);
					BpaFieldArray2LineString(nExcModel, szField, szLine1, szLine2, szLine3);
					fprintf(fp, "%s\n", szLine1);
					fprintf(fp, "%s\n", szLine2);
				}
				else
				{
					memset(szLine1, 0, 256);
					switch (nExcModel)
					{
					case BPA_SWI_EXCIT68:
						nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_Exc68Array[nExcIndex].szCardKey, -1);
						if (nDictIni >= 0)
						{
							if (BpaDataPtr2LineString(nExcModel, nDictIni, (char*)&pBpaBlock->m_BpaSwi_Exc68Array[nExcIndex], szLine1) > 0)
								fprintf(fp, "%s\n", szLine1);
						}
						break;
					case BPA_SWI_EXCIT81:
						nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_Exc81Array[nExcIndex].szCardKey, -1);
						if (nDictIni >= 0)
						{
							if (BpaDataPtr2LineString(nExcModel, nDictIni, (char*)&pBpaBlock->m_BpaSwi_Exc81Array[nExcIndex], szLine1) > 0)
								fprintf(fp, "%s\n", szLine1);
						}

						nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_FZ, pBpaBlock->m_BpaSwi_Exc81Array[nExcIndex].szKeyName);
						if (nRecord >= 0)
						{
							memset(szLine1, 0, 256);
							nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_FZArray[nRecord].szCardKey, -1);
							if (nDictIni >= 0)
							{
								if (BpaDataPtr2LineString(BPA_SWI_FZ, nDictIni, (char*)&pBpaBlock->m_BpaSwi_FZArray[nRecord], szLine1) > 0)
									fprintf(fp, "%s\n", szLine1);
							}
						}
						break;
					case BPA_SWI_EXCITMV:
						nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_ExcMVArray[nExcIndex].szCardKey, -1);
						if (nDictIni >= 0)
						{
							if (BpaDataPtr2LineString(nExcModel, nDictIni, (char*)&pBpaBlock->m_BpaSwi_ExcMVArray[nExcIndex], szLine1) > 0)
								fprintf(fp, "%s\n", szLine1);
						}

						nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_FCA, pBpaBlock->m_BpaSwi_ExcMVArray[nExcIndex].szKeyName);
						if (nRecord >= 0)
						{
							memset(szLine1, 0, 256);
							nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_FCAArray[nRecord].szCardKey, -1);
							if (nDictIni >= 0)
							{
								if (BpaDataPtr2LineString(BPA_SWI_FCA, nDictIni, (char*)&pBpaBlock->m_BpaSwi_FCAArray[nRecord], szLine1) > 0)
									fprintf(fp, "%s\n", szLine1);
							}
						}

						nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_FCB, pBpaBlock->m_BpaSwi_ExcMVArray[nExcIndex].szKeyName);
						if (nRecord >= 0)
						{
							memset(szLine1, 0, 256);
							nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_FCBArray[nRecord].szCardKey, -1);
							if (nDictIni >= 0)
							{
								if (BpaDataPtr2LineString(BPA_SWI_FCB, nDictIni, (char*)&pBpaBlock->m_BpaSwi_FCBArray[nRecord], szLine1) > 0)
									fprintf(fp, "%s\n", szLine1);
							}
						}
						break;
					}
				}
			}

			if (nPssIndex >= 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);
				switch (nPssModel)
				{
				case BPA_SWI_PSSS:		BpaDataPtr2FieldArray(nPssModel, (char*)&pBpaBlock->m_BpaSwi_PssSArray[nPssIndex], szField);	break;
				case BPA_SWI_PSSSA:		BpaDataPtr2FieldArray(nPssModel, (char*)&pBpaBlock->m_BpaSwi_PssSAArray[nPssIndex], szField);	break;
				case BPA_SWI_PSSST:		BpaDataPtr2FieldArray(nPssModel, (char*)&pBpaBlock->m_BpaSwi_PssSTArray[nPssIndex], szField);	break;
				case BPA_SWI_PSSSB:		BpaDataPtr2FieldArray(nPssModel, (char*)&pBpaBlock->m_BpaSwi_PssSBArray[nPssIndex], szField);	break;
				case BPA_SWI_PSSSH:		BpaDataPtr2FieldArray(nPssModel, (char*)&pBpaBlock->m_BpaSwi_PssSHArray[nPssIndex], szField);	break;
				case BPA_SWI_PSSSI:		BpaDataPtr2FieldArray(nPssModel, (char*)&pBpaBlock->m_BpaSwi_PssSIArray[nPssIndex], szField);	break;
				}
				BpaFieldArray2LineString(nPssModel, szField, szLine1, szLine2, szLine3);


				if (nPssModel == BPA_SWI_PSSS || nPssModel == BPA_SWI_PSSSA || nPssModel == BPA_SWI_PSSST)
				{
					fprintf(fp, "%s\n", szLine1);
				}
				else
				{
					fprintf(fp, "%s\n", szLine1);
					fprintf(fp, "%s\n", szLine2);
				}
			}

			if (nGovIndex >= 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);
				switch (nGovModel)
				{
				case BPA_SWI_GA:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GAArray[nGovIndex], szField);	break;
				case BPA_SWI_GG:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GGArray[nGovIndex], szField);	break;
				case BPA_SWI_GH:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GHArray[nGovIndex], szField);	break;
				case BPA_SWI_GC:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GCArray[nGovIndex], szField);	break;
				case BPA_SWI_GS:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GSArray[nGovIndex], szField);	break;
				case BPA_SWI_GL:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GLArray[nGovIndex], szField);	break;
				case BPA_SWI_GW:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GWArray[nGovIndex], szField);	break;
				case BPA_SWI_GI:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GIArray[nGovIndex], szField);	break;
				case BPA_SWI_GJ:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GJArray[nGovIndex], szField);	break;
				case BPA_SWI_GK:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GKArray[nGovIndex], szField);	break;
				case BPA_SWI_GM:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GMArray[nGovIndex], szField);	break;
				case BPA_SWI_GD:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GDArray[nGovIndex], szField);	break;
				case BPA_SWI_GZ:	BpaDataPtr2FieldArray(nGovModel, (char*)&pBpaBlock->m_BpaSwi_GZArray[nGovIndex], szField);	break;
				}
				BpaFieldArray2LineString(nGovModel, szField, szLine1, szLine2, szLine3);

				if (nGovModel == BPA_SWI_GA)	//	һ���
				{
					fprintf(fp, "%s\n", szLine1);
					if (pBpaBlock->m_BpaSwi_GAArray[nGovIndex].fPGV_Delay > FLT_MIN)
						fprintf(fp, "%s\n", szLine2);
				}
				else if (nPssModel == BPA_SWI_GJ)	//	һ���
				{
					fprintf(fp, "%s\n", szLine1);
					if (pBpaBlock->m_BpaSwi_GJArray[nGovIndex].fTW_DELAY > FLT_MIN || pBpaBlock->m_BpaSwi_GJArray[nGovIndex].fTP_DELAY > FLT_MIN)
						fprintf(fp, "%s\n", szLine2);
				}
				else if (nGovModel == BPA_SWI_GI || nPssModel == BPA_SWI_GM)
				{
					if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
					if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
				}
				else
				{
					if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
				}
			}

			if (nSvoIndex >= 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);

				BpaDataPtr2FieldArray(BPA_SWI_GA, (char*)&pBpaBlock->m_BpaSwi_GAArray[nSvoIndex], szField);
				BpaFieldArray2LineString(BPA_SWI_GA, szField, szLine1, szLine2, szLine3);
				if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
				if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
				if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
			}

			if (nMovIndex >= 0)
			{
				memset(szLine1, 0, 256);
				memset(szLine2, 0, 256);
				memset(szLine3, 0, 256);
				for (i=0; i<MAXMDBFIELDNUM; i++)
					memset(szField[i], 0, MDB_CHARLEN_LONG);
				switch (nMovModel)
				{
				case BPA_SWI_TA:	BpaDataPtr2FieldArray(nMovModel, (char*)&pBpaBlock->m_BpaSwi_TAArray[nMovIndex], szField);	break;
				case BPA_SWI_TB:	BpaDataPtr2FieldArray(nMovModel, (char*)&pBpaBlock->m_BpaSwi_TBArray[nMovIndex], szField);	break;
				case BPA_SWI_TC:	BpaDataPtr2FieldArray(nMovModel, (char*)&pBpaBlock->m_BpaSwi_TCArray[nMovIndex], szField);	break;
				case BPA_SWI_TD:	BpaDataPtr2FieldArray(nMovModel, (char*)&pBpaBlock->m_BpaSwi_TDArray[nMovIndex], szField);	break;
				case BPA_SWI_TE:	BpaDataPtr2FieldArray(nMovModel, (char*)&pBpaBlock->m_BpaSwi_TEArray[nMovIndex], szField);	break;
				case BPA_SWI_TF:	BpaDataPtr2FieldArray(nMovModel, (char*)&pBpaBlock->m_BpaSwi_TFArray[nMovIndex], szField);	break;
				case BPA_SWI_TW:	BpaDataPtr2FieldArray(nMovModel, (char*)&pBpaBlock->m_BpaSwi_TWArray[nMovIndex], szField);	break;
				}
				BpaFieldArray2LineString(nMovModel, szField, szLine1, szLine2, szLine3);
				if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n\n");

		//////////////////////////////////////////////////////////////////////////
		//	��������װ��ģ��
		// 		fprintf(fp, ".SVCģ��\n");
		// 		nTable=BPA_SWI_V;
		// 		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_V]; nDev++)
		// 		{
		// 			if (pBpaBlock->m_BpaSwi_VArray[nDev].fBPMin != pBpaBlock->m_BpaSwi_VArray[nDev].fBMin)
		// 			{
		// 				if (pBpaBlock->m_BpaSwi_VArray[nDev].fBMin > FLT_MIN)
		// 					pBpaBlock->m_BpaSwi_VArray[nDev].fBPMin=pBpaBlock->m_BpaSwi_VArray[nDev].fBMin;
		// 				else if (pBpaBlock->m_BpaSwi_VArray[nDev].fBPMin > FLT_MIN)
		// 					pBpaBlock->m_BpaSwi_VArray[nDev].fBMin=pBpaBlock->m_BpaSwi_VArray[nDev].fBPMin;
		// 			}
		// 			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_VArray[nDev].szCardKey, BpaSwiCategory_Dat);
		// 			if (BpaDataPtr2LineString(BPA_SWI_V, nDictIni, (char*)&pBpaBlock->m_BpaSwi_VArray[nDev], szLine1) <= 0)
		// 				continue;
		// 			fprintf(fp, "%s\n", szLine1);
		// 		}
		// 		fprintf(fp, "\n\n");

		//////////////////////////////////////////////////////////////////////////
		//	����ģ��
		nTable=BPA_SWI_MI;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".����ģ��\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_MI]; nDev++)
		{
			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_MIArray[nDev].szCardKey, BpaSwiCategory_Dat);
			if (BpaDataPtr2LineString(BPA_SWI_MI, nDictIni, (char*)&pBpaBlock->m_BpaSwi_MIArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_ML;
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_ML]; nDev++)
		{
			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_MLArray[nDev].szCardKey, BpaSwiCategory_Dat);
			if (BpaDataPtr2LineString(BPA_SWI_ML, nDictIni, (char*)&pBpaBlock->m_BpaSwi_MLArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);
		}
		fprintf(fp, "\n\n");

		//////////////////////////////////////////////////////////////////////////
		//	�����ģ��
		nTable=BPA_SWI_XO;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��ѹ���������\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_XOArray[nDev].szCardKey, -1);
			if (nDictIni >= 0)
			{
				if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_XOArray[nDev], szLine1) > 0)
					fprintf(fp, "%s\n", szLine1);
			}
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_LO;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��·�������\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_LOArray[nDev].szCardKey, -1);
			if (nDictIni >= 0)
			{
				if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_LOArray[nDev], szLine1) > 0)
					fprintf(fp, "%s\n", szLine1);
			}
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_LOHG;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��·�����翹�������\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_LOHGArray[nDev].szCardKey, -1);
			if (nDictIni >= 0)
			{
				if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_LOHGArray[nDev], szLine1) > 0)
					fprintf(fp, "%s\n", szLine1);
			}
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_XR;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".�Ե�֧·����ģ��\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[nTable]; nDev++)
		{
			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_XRArray[nDev].szCardKey, -1);
			if (nDictIni >= 0)
			{
				if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_XRArray[nDev], szLine1) > 0)
					fprintf(fp, "%s\n", szLine1);
			}
		}
		fprintf(fp, "\n\n");

		//////////////////////////////////////////////////////////////////////////
		//	ֱ��ϵͳģ��
		nTable=BPA_SWI_D;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".ֱ������ϵͳD\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_D]; nDev++)
		{
			strcpy(szBusName, pBpaBlock->m_BpaSwi_DArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_DArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nRecord < 0)
			{
				Log(g_lpszLogFile, "���D ֱ��ĸ��: %s %g ������\n", pBpaBlock->m_BpaSwi_DArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_DArray[nDev].fBus_kV);
				continue;
			}

			for (i=0; i<255; i++)
				szLine1[i]=' ';
			szLine1[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_DArray[nDev].szCardKey, -1);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_DArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_DT;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��ֱ������ϵͳDT\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_DT]; nDev++)
		{
			strcpy(szBusName, pBpaBlock->m_BpaSwi_DTArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_DTArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nRecord < 0)
			{
				Log(g_lpszLogFile, "���DT ֱ��ĸ��: %s %g ������\n", pBpaBlock->m_BpaSwi_DTArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_DTArray[nDev].fBus_kV);
				continue;
			}

			for (i=0; i<255; i++)
				szLine1[i]=' ';
			szLine1[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_DTArray[nDev].szCardKey, -1);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_DTArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_DF;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".����ֱ������ʧ��ģ��DF\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_DF]; nDev++)
		{
			strcpy(szBusName, pBpaBlock->m_BpaSwi_DFArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_DFArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nRecord < 0)
			{
				Log(g_lpszLogFile, "���DF ֱ��ĸ��: %s %g ������\n", pBpaBlock->m_BpaSwi_DMArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_DMArray[nDev].fBus_kV);
				continue;
			}

			for (i=0; i<255; i++)
				szLine1[i]=' ';
			szLine1[255]='\0';

			nDictIni=BpaGetTableDictIndex(pBpaBlock->m_BpaSwi_DFArray[nDev].szCardKey, -1);
			if (BpaDataPtr2LineString(nTable, nDictIni, (char*)&pBpaBlock->m_BpaSwi_DFArray[nDev], szLine1) <= 0)
				continue;
			fprintf(fp, "%s\n", szLine1);
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_DM;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��ֱ������ϵͳDM\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_DM]; nDev++)
		{
			strcpy(szBusName, pBpaBlock->m_BpaSwi_DMArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_DMArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nRecord < 0)
			{
				Log(g_lpszLogFile, "���DM ֱ��ĸ��: %s %g ������\n", pBpaBlock->m_BpaSwi_DMArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_DMArray[nDev].fBus_kV);
				continue;
			}

			memset(szLine1, 0, 256);
			memset(szLine2, 0, 256);
			memset(szLine3, 0, 256);
			for (i=0; i<MAXMDBFIELDNUM; i++)
				memset(szField[i], 0, MDB_CHARLEN_LONG);

			BpaDataPtr2FieldArray(nTable, (char*)&pBpaBlock->m_BpaSwi_DMArray[nDev], szField);
			BpaFieldArray2LineString(nTable, szField, szLine1, szLine2, szLine3);
			if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
			if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
			if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_DN;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��ֱ������ϵͳDN\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_DN]; nDev++)
		{
			strcpy(szBusName, pBpaBlock->m_BpaSwi_DNArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_DNArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nRecord < 0)
			{
				Log(g_lpszLogFile, "���DN ֱ��ĸ��: %s %g ������\n", pBpaBlock->m_BpaSwi_DNArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_DNArray[nDev].fBus_kV);
				continue;
			}

			memset(szLine1, 0, 256);
			memset(szLine2, 0, 256);
			memset(szLine3, 0, 256);
			for (i=0; i<MAXMDBFIELDNUM; i++)
				memset(szField[i], 0, MDB_CHARLEN_LONG);

			BpaDataPtr2FieldArray(nTable, (char*)&pBpaBlock->m_BpaSwi_DNArray[nDev], szField);
			BpaFieldArray2LineString(nTable, szField, szLine1, szLine2, szLine3);
			if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
			if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
			if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_DA;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��ֱ������ϵͳDA\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_DA]; nDev++)
		{
			strcpy(szBusName, pBpaBlock->m_BpaSwi_DAArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_DAArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			if (nRecord < 0)
			{
				Log(g_lpszLogFile, "���DA ֱ��ĸ��: %s %g ������\n", pBpaBlock->m_BpaSwi_DAArray[nDev].szBus_Name, pBpaBlock->m_BpaSwi_DAArray[nDev].fBus_kV);
				continue;
			}

			memset(szLine1, 0, 256);
			memset(szLine2, 0, 256);
			memset(szLine3, 0, 256);
			for (i=0; i<MAXMDBFIELDNUM; i++)
				memset(szField[i], 0, MDB_CHARLEN_LONG);

			BpaDataPtr2FieldArray(nTable, (char*)&pBpaBlock->m_BpaSwi_DAArray[nDev], szField);
			BpaFieldArray2LineString(nTable, szField, szLine1, szLine2, szLine3);
			if (strlen(szLine1) > 0)	fprintf(fp, "%s\n", szLine1);
			if (strlen(szLine2) > 0)	fprintf(fp, "%s\n", szLine2);
			if (strlen(szLine3) > 0)	fprintf(fp, "%s\n", szLine3);
		}
		fprintf(fp, "\n\n");

		//////////////////////////////////////////////////////////////////////////
		//	
		nTable=BPA_SWI_GENLN;
		if (pBpaBlock->m_nRecordNum[nTable] > 0)	fprintf(fp, ".��ֵ���������\n");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_SWI_GENLN]; nDev++)
		{
			strcpy(szBusName, pBpaBlock->m_BpaSwi_GenLnArray[nDev].szBus_Name);
			sprintf(szBusVolt, "%f", pBpaBlock->m_BpaSwi_GenLnArray[nDev].fBus_kV);
			nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_ACBUS, szBusName, szBusVolt);
			if (nRecord < 0)
			{
				nRecord=BpaFindRecordbyKey(pBpaBlock, BPA_DAT_DCBUS, szBusName, szBusVolt);
			}
			else
			{
				bBusLNOutArray[nRecord]=1;
			}
			if (nRecord < 0)
				continue;

			for (i=0; i<255; i++)
				szLine1[i]=' ';
			szLine1[255]='\0';

			BpaSwi2LineString(nTable, (char*)&pBpaBlock->m_BpaSwi_GenLnArray[nDev], szLine1);
			fprintf(fp, "%s\n", szLine1);
		}

		fprintf(fp, "\n");
		memset(&lnBuf, 0, sizeof(tagBpaSwi_GenLn));
		strcpy(lnBuf.szCardKey, "LN");
		for (nDev=0; nDev<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; nDev++)
		{
			if ((pBpaBlock->m_BpaDat_ACBusArray[nDev].fPGen > 0.001 || pBpaBlock->m_BpaDat_ACBusArray[nDev].fQsched_Qmax > 0.001) && !bBusLNOutArray[nDev])
			{
				strcpy(lnBuf.szBus_Name, pBpaBlock->m_BpaDat_ACBusArray[nDev].szName);
				lnBuf.fBus_kV=pBpaBlock->m_BpaDat_ACBusArray[nDev].fkV;
				BpaSwi2LineString(nTable, (char*)&lnBuf, szLine1);
				fprintf(fp, "%s\n", szLine1);
			}
		}
		fprintf(fp, "\n\n");

		nTable=BPA_SWI_F0;
		BpaSwi2LineString(nTable, (char*)&pBpaBlock->m_BpaSwi_F0Array[0], szLine1);
		fprintf(fp, "%s\n", szLine1);

		nTable=BPA_SWI_F1;
		BpaSwi2LineString(nTable, (char*)&pBpaBlock->m_BpaSwi_F1Array[0], szLine1);
		fprintf(fp, "%s\n", szLine1);

		nTable=BPA_SWI_FF;
		BpaSwi2LineString(nTable, (char*)&pBpaBlock->m_BpaSwi_FFArray[0], szLine1);
		fprintf(fp, "%s\n", szLine1);

		fprintf(fp, "90\n");
		fprintf(fp, "\n\n");

		fprintf(fp, "99\n");
		fprintf(fp, "\n\n");

		return 1;
	}

	int CBpaMemDBInterface::BpaSwi2LineString(const int nBpaTable, const char* lpszDataPtr, char* lpszRetLine)
	{
		register int	i;
		char	szField[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];
		for (i=0; i<MAXMDBFIELDNUM; i++)
			memset(szField[i], 0, MDB_CHARLEN_LONG);

		BpaDataPtr2FieldArray(nBpaTable, lpszDataPtr, szField);
		switch (nBpaTable)
		{
		case	BPA_SWI_CASE:
			BpaDictFieldArray2LineString(nBpaTable, sizeof(m_BpaSwiCaseDictArray)/sizeof(tagBpa_Dict), m_BpaSwiCaseDictArray, szField, lpszRetLine);
			break;
		case	BPA_SWI_F0:
			BpaDictFieldArray2LineString(nBpaTable, sizeof(m_BpaSwiF0DictArray)/sizeof(tagBpa_Dict), m_BpaSwiF0DictArray, szField, lpszRetLine);
			break;
		case	BPA_SWI_F1:
			BpaDictFieldArray2LineString(nBpaTable, sizeof(m_BpaSwiF1DictArray)/sizeof(tagBpa_Dict), m_BpaSwiF1DictArray, szField, lpszRetLine);
			break;
		case	BPA_SWI_FF:
			BpaDictFieldArray2LineString(nBpaTable, sizeof(m_BpaSwiFFDictArray)/sizeof(tagBpa_Dict), m_BpaSwiFFDictArray, szField, lpszRetLine);
			break;
		case	BPA_SWI_GENLN:
			BpaDictFieldArray2LineString(nBpaTable, sizeof(m_BpaSwiLNDictArray)/sizeof(tagBpa_Dict), m_BpaSwiLNDictArray, szField, lpszRetLine);
			break;
		default:
			break;
		}

		return 1;
	}

}