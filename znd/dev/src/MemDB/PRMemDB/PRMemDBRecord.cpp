#include "stdafx.h"
#include "PRMemDB.h"

namespace	PRMemDB
{
	int CPRMemDBInterface::PRGetRecordValue(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nRecord, char* lpszRetValue)
	{
		return MemDBBase::MDBGetRecordValue<tagPRBlock>(pPRBlock, nTable, nField, nRecord , lpszRetValue);
	}

	int CPRMemDBInterface::PRSetRecordValue(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue)
	{
		return MemDBBase::MDBSetRecordValue<tagPRBlock>(pPRBlock, nTable, nField, nRecord , lpszValue);
	}

	int CPRMemDBInterface::PRGetRecordRowValue(tagPRBlock* pPRBlock, const int nTable, const int nRecord, char lpszRetValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBGetRecordValue<tagPRBlock>(pPRBlock, nTable , nRecord, lpszRetValue);
	}

	int CPRMemDBInterface::PRGetRecordColValue(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBGetRecordColumnValue<tagPRBlock>(pPRBlock, nTable, nField, nIniRecord, nMaxCount, lpszRetValue);
	}

	int CPRMemDBInterface::PRSetRecordRowValue(tagPRBlock* pPRBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBSetRecordValue<tagPRBlock>(pPRBlock, nTable, nRecord, lpszValue);
	}

	int CPRMemDBInterface::PRGetRecordRow(tagPRBlock* pPRBlock, const int nTable, const int nRecord, char* lpszRetValue)
	{
		return MemDBBase::MDBGetRecordRow<tagPRBlock>(pPRBlock, nTable , nRecord, lpszRetValue);
	}

	int	CPRMemDBInterface::PRFindRecordbyField(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue)
	{
		return MemDBBase::MDBFindRecordBubble<tagPRBlock>(pPRBlock, nTable, nField, nIniRecord, lpszValue);
	}

	int	CPRMemDBInterface::PRFindRecordbyRow(tagPRBlock* pPRBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecord<tagPRBlock>(pPRBlock, nTable, lpszValue);
	}

	int	CPRMemDBInterface::PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char lpszKeyValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecordQuick<tagPRBlock>(pPRBlock, nTable, 0, pPRBlock->m_nRecordNum[nTable]-1, lpszKeyValue);
	}

	int CPRMemDBInterface::PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1)
	{
		if (PRGetTablePrimaryKeyNum(nTable) != 1)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PRGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		return PRFindRecordbyKey(pPRBlock, nTable, szRest);
	}

	int CPRMemDBInterface::PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2)
	{
		if (PRGetTablePrimaryKeyNum(nTable) != 2)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PRGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		return PRFindRecordbyKey(pPRBlock, nTable, szRest);
	}

	int CPRMemDBInterface::PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3)
	{
		if (PRGetTablePrimaryKeyNum(nTable) != 3)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PRGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		strcpy(szRest[2], lpszKeyValue3);
		return PRFindRecordbyKey(pPRBlock, nTable, szRest);
	}

	int CPRMemDBInterface::PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3, const char* lpszKeyValue4)
	{
		if (PRGetTablePrimaryKeyNum(nTable) != 4)
			return -1;

		register int	i;
		char	szRest[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<PRGetTablePrimaryKeyNum(nTable); i++)
			memset(szRest[i], 0, MDB_CHARLEN_LONG);

		strcpy(szRest[0], lpszKeyValue1);
		strcpy(szRest[1], lpszKeyValue2);
		strcpy(szRest[2], lpszKeyValue3);
		strcpy(szRest[3], lpszKeyValue4);
		return PRFindRecordbyKey(pPRBlock, nTable, szRest);
	}


	int	CPRMemDBInterface::PRFindRecordFuzzy(tagPRBlock* pPRBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBFindRecordFuzzy<tagPRBlock>(pPRBlock, nTable, lpszValue);
	}

	int	CPRMemDBInterface::PRInsertRecord(tagPRBlock* pPRBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBInsertRecord<tagPRBlock>(pPRBlock, nTable, lpszRecArray);
	}

	int	CPRMemDBInterface::PRAppendRecord(tagPRBlock* pPRBlock, const int bNeedCheck, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBAppendRecord<tagPRBlock>(pPRBlock, bNeedCheck, nTable, lpszRecArray);
	}

	int	CPRMemDBInterface::PRAppendRecordByRow(tagPRBlock* pPRBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser)
	{
		return MemDBBase::MDBAppendRecordByRow<tagPRBlock>(pPRBlock, bNeedCheck, nTable, nFieldIndex, lpszParser);
	}

	int	CPRMemDBInterface::PRUpdateRecord(tagPRBlock* pPRBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		return MemDBBase::MDBUpdateRecord<tagPRBlock>(pPRBlock, nTable, lpszRecArray);
	}

	int	CPRMemDBInterface::PRRemoveRecord(tagPRBlock* pPRBlock, const int nTable, const int nRecord)
	{
		return MemDBBase::MDBRemoveRecord<tagPRBlock>(pPRBlock, nTable, nRecord);
	}

	int	CPRMemDBInterface::PRGetFilteredIndexArray(tagPRBlock* pPRBlock, const int bAndOr, const int nTable, 
		const int nFilterField1, const char* lpszFilterKey1Array, 
		const int nFilterField2, const char* lpszFilterKey2Array, 
		const int nFilterField3, const char* lpszFilterKey3Array, 
		const int nFilterField4, const char* lpszFilterKey4Array, 
		const int nIndexCapacity, int nIndexArray[])
	{
		return MemDBBase::MDBGetFilterIndexArray<tagPRBlock>(pPRBlock, bAndOr, nTable, 
			nFilterField1, lpszFilterKey1Array, nFilterField2, lpszFilterKey2Array, 
			nFilterField3, lpszFilterKey3Array, nFilterField4, lpszFilterKey4Array, 
			nIndexCapacity, nIndexArray);
	}


	int	CPRMemDBInterface::PRGetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszDataPtr, OUT char* lpszRetValue)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nLen, nFieldLen;

		if (nTable < 0 || nTable >= PRGetTableNum())
			return 0;

		if (nField < 0 || nField >= PRGetTableFieldNum(nTable))
			return 0;

		nFieldLen=PRGetFieldLen(nTable, nField);
		for (i=0; i<nField; i++)
			lpszDataPtr += PRGetFieldLen(nTable, i);

		switch (PRGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			nLen=(int)strlen(lpszDataPtr);
			if (nLen >= nFieldLen)
				nLen=(isascii(lpszDataPtr[nFieldLen-1])) ? nFieldLen-1 : nFieldLen-2;
			for (i=0; i<nLen; i++)
				lpszRetValue[i]=(char)lpszDataPtr[i];
			lpszRetValue[i]='\0';
			break;
		case	MDB_DOUBLE:
			memcpy(&dBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%lf", dBuf);
			break;
		case	MDB_FLOAT:
			memcpy(&fBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%f", fBuf);
			break;
		case	MDB_INT:
			memcpy(&nBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%d", nBuf);
			break;
		case	MDB_SHORT:
			memcpy(&sBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%d", sBuf);
			break;
		case	MDB_BIT:
			memcpy(&uBuf, lpszDataPtr, nFieldLen);
			sprintf(lpszRetValue, "%d", uBuf);
			break;
		case	MDB_CHAR:
			lpszRetValue[0]=(char)lpszDataPtr[0];
			break;
		default:
			return 0;
			break;
		}
		return 1;
	}

	int	CPRMemDBInterface::PRSetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszSetValue, OUT char* lpszDataPtr)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nLen, nFieldLen;

		if (nTable < 0 || nTable >= PRGetTableNum())
			return 0;

		if (nField < 0 || nField >= PRGetTableFieldNum(nTable))
			return 0;

		for (i=0; i<nField; i++)
			lpszDataPtr += PRGetFieldLen(nTable, i);;
		switch (PRGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			nFieldLen=PRGetFieldLen(nTable, nField);
			nLen=(int)strlen(lpszSetValue);
			if (nLen >= nFieldLen)
				nLen=(isascii(lpszSetValue[nFieldLen-1])) ? nFieldLen-1 : nFieldLen-2;
			for (i=0; i<nLen; i++)
				lpszDataPtr[i]=lpszSetValue[i];
			lpszDataPtr[i]='\0';
			break;
		case	MDB_DOUBLE:
			dBuf=atof(lpszSetValue);
			memcpy(lpszDataPtr, &dBuf, sizeof(double));
			break;
		case	MDB_FLOAT:
			fBuf=(float)atof(lpszSetValue);
			memcpy(lpszDataPtr, &fBuf, sizeof(float));
			break;
		case	MDB_INT:
			nBuf=atoi(lpszSetValue);
			memcpy(lpszDataPtr, &nBuf, sizeof(int));
			break;
		case	MDB_SHORT:
			sBuf=(short)atoi(lpszSetValue);
			memcpy(lpszDataPtr, &sBuf, sizeof(short));
			break;
		case	MDB_BIT:
			uBuf=(unsigned char)atoi(lpszSetValue);
			memcpy(lpszDataPtr, &uBuf, sizeof(unsigned char));
			break;
		case	MDB_CHAR:
			lpszDataPtr[0]=lpszSetValue[0];
			break;
		default:
			return 0;
			break;
		}
		return 1;
	}
}
