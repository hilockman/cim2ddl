#include "stdafx.h"
#include "PGMemDB.h"

namespace	PGMemDB
{
	int PGGetRecordRow(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char* lpszRetValue)
	{
		return MemDBBase::MDBGetRecordRow<tagPGBlock>(pPGBlock, nTable , nRecord, lpszRetValue);
	}

	int PGGetRecordValue(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nRecord, char* lpszRetValue)
	{
		return MemDBBase::MDBGetRecordValue<tagPGBlock>(pPGBlock, nTable, nField, nRecord , lpszRetValue);
	}

	int PGSetRecordValue(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue)
	{
		return MemDBBase::MDBSetRecordValue<tagPGBlock>(pPGBlock, nTable, nField, nRecord , lpszValue);
	}

	int PGGetRecordRowValue(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char lpszRetValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBGetRecordValue<tagPGBlock>(pPGBlock, nTable , nRecord, lpszRetValue);
	}

	int PGGetRecordColValue(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBGetRecordColumnValue<tagPGBlock>(pPGBlock, nTable, nField, nIniRecord, nMaxCount, lpszRetValue);
	}

	int PGCheckRecordPrimarykey(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBCheckNull<tagPGBlock>(pPGBlock, nTable, lpszValue);
	}

	int PGCheckRecordContainer(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBCheckContainer<tagPGBlock>(pPGBlock, nTable, lpszValue);
	}

	int PGCheckRecordExist(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBCheckExist<tagPGBlock>(pPGBlock, nTable, -1, lpszValue);
	}

	int		PGGetRecordKeyString(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char* lpszRetValue)
	{
		register int	i;
		char	szField[MDB_CHARLEN_LONG];
		std::string	strBuffer;

		if (PGGetTablePrimaryKeyNum(nTable) <= 0)
			return 0;

		strBuffer.clear();
		for (i=PGGetTablePrimaryKeyNum(nTable)-1; i>=0; i--)
		{
			memset(szField, 0, MDB_CHARLEN_LONG);
			PGGetRecordValue(pPGBlock, nTable, PGGetTablePrimaryKey(nTable, i), nRecord, szField);
			if (i != PGGetTablePrimaryKeyNum(nTable)-1)
				strBuffer.append("@");
			strBuffer.append(szField);
		}

		strcpy(lpszRetValue, strBuffer.c_str());
		return 1;
	}

	int PGSetRecordRowValue(tagPGBlock* pPGBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBSetRecordValue<tagPGBlock>(pPGBlock, nTable, nRecord, lpszValue);
	}

	int	PGFindRecordbyField(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue)
	{
		return MemDBBase::MDBFindRecordBubble<tagPGBlock>(pPGBlock, nTable, nField, nIniRecord, lpszValue);
	}

	int	PGFindRecordbyRow(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecord<tagPGBlock>(pPGBlock, nTable, lpszValue);
	}

	int	PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char lpszKeyValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecordQuick<tagPGBlock>(pPGBlock, nTable, 0, pPGBlock->m_nRecordNum[nTable]-1, lpszKeyValue);
	}

	int		PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1)
	{
		if (PGGetTablePrimaryKeyNum(nTable) != 1)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PGGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		return PGFindRecordbyKey(pPGBlock, nTable, szRest);
	}

	int		PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2)
	{
		if (PGGetTablePrimaryKeyNum(nTable) != 2)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PGGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		return PGFindRecordbyKey(pPGBlock, nTable, szRest);
	}

	int		PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3)
	{
		if (PGGetTablePrimaryKeyNum(nTable) != 3)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PGGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		strcpy(szRest[2], lpszKeyValue3);
		return PGFindRecordbyKey(pPGBlock, nTable, szRest);
	}

	int		PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3, const char* lpszKeyValue4)
	{
		if (PGGetTablePrimaryKeyNum(nTable) != 4)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PGGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		strcpy(szRest[2], lpszKeyValue3);
		strcpy(szRest[3], lpszKeyValue4);
		return PGFindRecordbyKey(pPGBlock, nTable, szRest);
	}

	int	PGFindRecordFuzzy(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecordFuzzy<tagPGBlock>(pPGBlock, nTable, lpszValue);
	}

	int	PGInsertRecord(tagPGBlock* pPGBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBInsertRecord<tagPGBlock>(pPGBlock, nTable, lpszRecArray);
	}

	int	PGAppendRecord(tagPGBlock* pPGBlock, const int bNeedCheck, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBAppendRecord<tagPGBlock>(pPGBlock, bNeedCheck, nTable, lpszRecArray);
	}

	int	PGUpdateRecord(tagPGBlock* pPGBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBUpdateRecord<tagPGBlock>(pPGBlock, nTable, lpszRecArray);
	}

	int	PGRemoveRecord(tagPGBlock* pPGBlock, const int nTable, const int nRecord)
	{
		return MemDBBase::MDBRemoveRecord<tagPGBlock>(pPGBlock, nTable, nRecord);
	}

	int	PGAppendRecordByRow(tagPGBlock* pPGBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser)
	{
		return MemDBBase::MDBAppendRecordByRow<tagPGBlock>(pPGBlock, bNeedCheck, nTable, nFieldIndex, lpszParser);
	}

	int	PGGetFilteredIndexArray(tagPGBlock* pPGBlock, const int bAndOr, const int nTable, 
		const int nFilterField1, const char* lpszFilterKey1Array, 
		const int nFilterField2, const char* lpszFilterKey2Array, 
		const int nFilterField3, const char* lpszFilterKey3Array, 
		const int nFilterField4, const char* lpszFilterKey4Array, 
		const int nIndexCapacity, int nIndexArray[])
	{
		return MemDBBase::MDBGetFilterIndexArray<tagPGBlock>(pPGBlock, bAndOr, nTable, 
			nFilterField1, lpszFilterKey1Array, nFilterField2, lpszFilterKey2Array, 
			nFilterField3, lpszFilterKey3Array, nFilterField4, lpszFilterKey4Array, 
			nIndexCapacity, nIndexArray);
	}
}
