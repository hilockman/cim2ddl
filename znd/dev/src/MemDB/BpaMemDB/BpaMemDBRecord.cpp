#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"

namespace	BpaMemDB
{
	int CBpaMemDBInterface::BpaGetRecordValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nRecord, char* lpszRetValue)
	{
		return MemDBBase::MDBGetRecordValue<tagBpaBlock>(pBpaBlock, nTable, nField, nRecord, lpszRetValue);
	}

	int CBpaMemDBInterface::BpaSetRecordValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue)
	{
		return MemDBBase::MDBSetRecordValue<tagBpaBlock>(pBpaBlock, nTable, nField, nRecord, lpszValue);
	}

	int CBpaMemDBInterface::BpaGetRecordRowValue(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, char lpszRetValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBGetRecordValue<tagBpaBlock>(pBpaBlock, nTable, nRecord, lpszRetValue);
	}

	int CBpaMemDBInterface::BpaGetRecordColValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBGetRecordColumnValue<tagBpaBlock>(pBpaBlock, nTable, nField, nIniRecord, nMaxCount, lpszRetValue);
	}

	int CBpaMemDBInterface::BpaSetRecordRowValue(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBSetRecordValue<tagBpaBlock>(pBpaBlock, nTable, nRecord, lpszValue);
	}

	int CBpaMemDBInterface::BpaGetRecordRow(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, char* lpszRetValue)
	{
		return MemDBBase::MDBGetRecordRow<tagBpaBlock>(pBpaBlock, nTable , nRecord, lpszRetValue);
	}

	int CBpaMemDBInterface::BpaInsertRecord(tagBpaBlock* pBpaBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBInsertRecord<tagBpaBlock>(pBpaBlock, nTable, lpszRecArray);
	}

	int CBpaMemDBInterface::BpaAppendRecord(tagBpaBlock* pBpaBlock, const int bCheckData, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBAppendRecord<tagBpaBlock>(pBpaBlock, bCheckData, nTable, lpszRecArray);
	}

	int CBpaMemDBInterface::BpaAppendRecordByRow(tagBpaBlock* pBpaBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser)
	{
		return MemDBBase::MDBAppendRecordByRow<tagBpaBlock>(pBpaBlock, bNeedCheck, nTable, nFieldIndex, lpszParser);
	}

	int CBpaMemDBInterface::BpaUpdateRecord(tagBpaBlock* pBpaBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBUpdateRecord<tagBpaBlock>(pBpaBlock, nTable, lpszRecArray);
	}

	int CBpaMemDBInterface::BpaRemoveRecord(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord)
	{
		return MemDBBase::MDBRemoveRecord<tagBpaBlock>(pBpaBlock, nTable, nRecord);
	}

	int CBpaMemDBInterface::BpaFindRecordbyField(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue)
	{
		return MemDBBase::MDBFindRecordBubble<tagBpaBlock>(pBpaBlock, nTable, nField, nIniRecord, lpszValue);
	}

	int CBpaMemDBInterface::BpaFindRecordbyRow(tagBpaBlock* pBpaBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecord<tagBpaBlock>(pBpaBlock, nTable, lpszValue);
	}

	int CBpaMemDBInterface::BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char lpszKeyValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecordQuick<tagBpaBlock>(pBpaBlock, nTable, 0, pBpaBlock->m_nRecordNum[nTable]-1, lpszKeyValue);
	}

	int CBpaMemDBInterface::BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1)
	{
		if (BpaGetTablePrimaryKeyNum(nTable) != 1)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<BpaGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		return BpaFindRecordbyKey(pBpaBlock, nTable, szRest);
	}

	int CBpaMemDBInterface::BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2)
	{
		if (BpaGetTablePrimaryKeyNum(nTable) != 2)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<BpaGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		return BpaFindRecordbyKey(pBpaBlock, nTable, szRest);
	}

	int CBpaMemDBInterface::BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3)
	{
		if (BpaGetTablePrimaryKeyNum(nTable) != 3)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<BpaGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		strcpy(szRest[2], lpszKeyValue3);
		return BpaFindRecordbyKey(pBpaBlock, nTable, szRest);
	}

	int CBpaMemDBInterface::BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3, const char* lpszKeyValue4)
	{
		if (BpaGetTablePrimaryKeyNum(nTable) != 4)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<BpaGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		strcpy(szRest[2], lpszKeyValue3);
		strcpy(szRest[3], lpszKeyValue4);
		return BpaFindRecordbyKey(pBpaBlock, nTable, szRest);
	}

	int CBpaMemDBInterface::BpaFindRecordFuzzy(tagBpaBlock* pBpaBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecordFuzzy<tagBpaBlock>(pBpaBlock, nTable, lpszValue);
	}

	int CBpaMemDBInterface::BpaGetFilteredIndexArray(tagBpaBlock* pBpaBlock, const int bAndOr, const int nTable,
		const int nFilterField1, const char* lpszFilterKey1Array,
		const int nFilterField2, const char* lpszFilterKey2Array,
		const int nFilterField3, const char* lpszFilterKey3Array,
		const int nFilterField4, const char* lpszFilterKey4Array,
		const int nIndexCapacity, int nIndexArray[])
	{
		return MemDBBase::MDBGetFilterIndexArray<tagBpaBlock>(pBpaBlock, bAndOr, nTable,
			nFilterField1, lpszFilterKey1Array, nFilterField2, lpszFilterKey2Array,
			nFilterField3, lpszFilterKey3Array, nFilterField4, lpszFilterKey4Array,
			nIndexCapacity, nIndexArray);
	}

	int	isInBpaZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strZoneArray, const char* lpszZone)
	{
		if (strZoneArray.empty())
			return 1;

		register int	i;
		for (i=0; i<(int)strZoneArray.size(); i++)
		{
			if (STRICMP(lpszZone, strZoneArray[i].c_str()) == 0)
				return 1;
		}
		return 0;
	}

	int	isBpaSubInBpaZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strZoneArray, const char* lpszSub)
	{
		if (strZoneArray.empty())
			return 1;

		register int	i;
		for (i=0; i<pBpaBlock->m_nRecordNum[BPA_DAT_ACBUS]; i++)
		{
			if (strcmp(pBpaBlock->m_BpaDat_ACBusArray[i].szBpaSub, lpszSub) != 0)
				continue;

			if (isInBpaZone(pBpaBlock, strZoneArray, pBpaBlock->m_BpaDat_ACBusArray[i].szZone))
				return 1;
		}
		return 0;
	}

	int CBpaMemDBInterface::BpaGetZoneFilteredIndexArray(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszFilterZoneArray, const int nIndexCapacity, int nIndexArray[])
	{
		register int	i;
		int		nField, nRecord;
		char	szValue[MDB_CHARLEN_LONG];
		std::vector<std::string>	strFilterArray;

		strFilterArray.clear();
		int	nChar=0;
		for (i=0; i<(int)strlen(lpszFilterZoneArray); i++)
		{
			if (lpszFilterZoneArray[i] == '\\' || lpszFilterZoneArray[i] == '\r' || lpszFilterZoneArray[i] == '\n')
			{
				szValue[nChar++]='\0';
				strFilterArray.push_back(szValue);
				nChar=0;
			}
			else
			{
				szValue[nChar++]=lpszFilterZoneArray[i];
			}
		}

		if (lpszFilterZoneArray == NULL || strFilterArray.empty())
		{
			//Log("BpaGetZoneFilteredIndexArray lpszFilterZoneArray == NULL || strFilterArray.empty\n");
			//Log("        lpszFilterZoneArray=%s\n", lpszFilterZoneArray);
			//for (i=0; i<strFilterArray.size(); i++)
			//	Log("            Filter[%d/%d]=%s\n", i, strFilterArray.size(), strFilterArray[i].c_str());

			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
				nIndexArray[i]=i;

			return pBpaBlock->m_nRecordNum[nTable];
		}

		int		nRowNum=0;
		switch (nTable)
		{
		case 	BPA_DAT_ZONE:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ZoneArray[i].szName))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case 	BPA_DAT_SUB:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isBpaSubInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_SubArray[i].szName))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_ACBUS:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[i].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_ACLINE:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[i].nIBus].szZone) ||
					isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_ACLineArray[i].nZBus].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_LINEHG:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_LineHGArray[i].nIBus].szZone) ||
					isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_LineHGArray[i].nZBus].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_WIND:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nIBus].szZone) ||
					isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_WindArray[i].nZBus].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_DCBUS:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_DCBusArray[i].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_DCLINE:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_DCLineArray[i].nRBus].szZone) ||
					isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_DCBusArray[pBpaBlock->m_BpaDat_DCLineArray[i].nIBus].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_R:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_RArray[i].nIBus].szZone) ||
					isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_RArray[i].nZBus].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_DAT_RZ:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_RZArray[i].nIBus].szZone) ||
					isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[pBpaBlock->m_BpaDat_RZArray[i].nZBus].szZone))
					nIndexArray[nRowNum++]=i;
			}
			break;
		case	BPA_SWI_GEN:
		case	BPA_SWI_EXCIT68:
		case	BPA_SWI_EXCIT81:
		case	BPA_SWI_EXCITMV:
		case	BPA_SWI_EXCITX:
			//case	BPA_SWI_EXCITEX:
		case	BPA_SWI_PSSS:
		case	BPA_SWI_PSSST:
		case	BPA_SWI_PSSSH:
// 		case	BPA_SWI_PSSSH1:
// 		case	BPA_SWI_PSSSH2:
		case	BPA_SWI_PSSSI:
		case	BPA_SWI_PSSSA:
		case	BPA_SWI_GG:
		case	BPA_SWI_GH:
		case	BPA_SWI_GC:
		case	BPA_SWI_GS:
		case	BPA_SWI_GL:
		case	BPA_SWI_GW:
		case	BPA_SWI_GA:
		case	BPA_SWI_GI:
		case	BPA_SWI_GJ:
		case	BPA_SWI_GK:
		case	BPA_SWI_GM:
		case	BPA_SWI_GD:
		case	BPA_SWI_GZ:
		case	BPA_SWI_TA:
		case	BPA_SWI_TB:
		case	BPA_SWI_TD:
		case	BPA_SWI_TE:
		case	BPA_SWI_TC:
		case	BPA_SWI_TF:
		case	BPA_SWI_TW:
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
			{
				nField=BpaGetFieldIndex(nTable, "BusPtr");
				BpaGetRecordValue(pBpaBlock, nTable, nField, i, szValue);
				nRecord=atoi(szValue);
				if (nRecord >= 0)
				{
					if (isInBpaZone(pBpaBlock, strFilterArray, pBpaBlock->m_BpaDat_ACBusArray[nRecord].szZone))
						nIndexArray[nRowNum++]=i;
				}
			}
			break;
		default:
			nRowNum=pBpaBlock->m_nRecordNum[nTable];
			for (i=0; i<pBpaBlock->m_nRecordNum[nTable]; i++)
				nIndexArray[i]=i;
			break;
		}
		return nRowNum;
	}
}
