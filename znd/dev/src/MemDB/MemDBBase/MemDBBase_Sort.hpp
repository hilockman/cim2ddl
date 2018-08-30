#include "MemDBBase.h"
#include "MemDBBaseExtern.h"
#include "../../Common/String2Double.hpp"

namespace	MemDBBase
{
	template<typename T>	char*	MDBGetFieldRecordAddr(T* pBlock, const int nTable, const int nField, const int nRecord)
	{
		register int	i;

		char*	lpszAddr=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nRecord;
		for (i=0; i<nField; i++)
			lpszAddr += pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[i].nDataLen;
		return lpszAddr;
	}

	template<typename T>	int		MDBCompareFieldValue(T* pBlock, const int nTable, const int nField, const char* lpszRef, const char* lpszCmp)
	{
		//MDBLog("数据比较: 表=%s 字段=%s 字段类型=%d\n", 
		//	pBlock->m_MDBSummary.sMDBTableArray[nTable].szName, 
		//	pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szName, 
		//	pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType);

		if (strlen(lpszCmp) <= 0)	//	应用于模糊查询
		{
			//MDBLog("模糊查询[Table=%s Field=%s] %s %s\n", 
			//	pBlock->m_MDBSummary.sMDBTableArray[nTable].szName, 
			//	pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].szName, 
			//	lpszRef, 
			//	lpszCmp);
			return 0;
		}

		if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_STRING)
		{
			if (strcmp(lpszRef, lpszCmp) < 0)
				return -1;
			else if (strcmp(lpszRef, lpszCmp) == 0)
				return 0;
			else if (strcmp(lpszRef, lpszCmp) > 0)
				return 1;
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_DOUBLE)
		{
			double fRef, fCmp, fCompare;
			memcpy(&fRef, lpszRef, sizeof(double));
			fCmp=atof(lpszCmp);
			fCompare=fRef-fCmp;
			if (fCompare < -0.000000001)
				return -1;
			else if (-0.000000001 <= fCompare && fCompare <= 0.000000001)
				return 0;
			else if (fCompare > 0.000000001)
				return 1;
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_FLOAT)
		{
			float fRef, fCmp, fCompare;
			memcpy(&fRef, lpszRef, sizeof(float));
			fCmp=(float)atof(lpszCmp);
			fCompare=fRef-fCmp;
			if (fCompare < -0.0000001)
				return -1;
			else if (-0.0000001 <= fCompare && fCompare <= 0.0000001)
				return 0;
			else if (fCompare > 0.0000001)
				return 1;
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_INT)
		{
			int nRef, nCmp, nCompare;
			memcpy(&nRef, lpszRef, sizeof(int));
			nCmp=(int)atoi(lpszCmp);
			nCompare=nRef-nCmp;
			if (nCompare < 0)
				return -1;
			else if (nCompare == 0)
				return 0;
			else if (nCompare > 0)
				return 1;
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_SHORT)
		{
			short nRef, nCmp, nCompare;
			memcpy(&nRef, lpszRef, sizeof(short));
			nCmp=(short)atoi(lpszCmp);
			nCompare=nRef-nCmp;
			if (nCompare < 0)
				return -1;
			else if (nCompare == 0)
				return 0;
			else if (nCompare > 0)
				return 1;
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_BIT)
		{
			unsigned char nRef, nCmp, nCompare;
			memcpy(&nRef, lpszRef, sizeof(unsigned char));
			nCmp=(unsigned char)atoi(lpszCmp);
			nCompare=nRef-nCmp;
			if (nCompare < 0)
				return -1;
			else if (nCompare == 0)
				return 0;
			else if (nCompare > 0)
				return 1;
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_CHAR)
		{
			char cRef, cCmp;
			int	nCompare;

			cRef=lpszRef[0];
			cCmp=lpszCmp[0];
			nCompare=cRef-cCmp;
			if (nCompare < 0)
				return -1;
			else if (nCompare == 0)
				return 0;
			else if (nCompare > 0)
				return 1;
		}
		return 0;
	}

	template<typename T>	int		MDBCompareFieldValue(T* pBlock, const int nTable, const int nField, const int nRecord, const char* lpszRec)
	{
		char*	pRef=MDBGetFieldRecordAddr(pBlock, nTable, nField, nRecord);
		return MDBCompareFieldValue(pBlock, nTable, nField, pRef, lpszRec);
	}

	template<typename T>	int		MDBCompareRestrictArray(T* pBlock, const int nTable, char* pRef[g_nConstMaxPrimaryKey], char* pCmp[g_nConstMaxPrimaryKey])
	{
		switch (pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum)
		{
		case	1:
			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) < 0)
			{
				return -1;
			}
			else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0)
			{
				return 0;
			}
			else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) > 0)
			{
				return 1;
			}
			break;
		case	2:
			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) < 0 ||
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) < 0)
			{
				return -1;
			}
			else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0)
			{
				return 0;
			}
			else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) > 0 ||
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) > 0)
			{
				return 1;
			}
			break;
		case	3:
			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) < 0 ||
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) < 0 ||
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) < 0)
			{
				return -1;
			}
			else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) == 0)
			{
				return 0;
			}
			else if (
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) > 0 ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) > 0) ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) > 0))
			{
				return 1;
			}
			break;
		case	4:
// 			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) < 0)
// 				return -1;
// 			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) > 0)
// 				return 1;
// 			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0)
// 			{
// 				if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) < 0)
// 					return -1;
// 				if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) > 0)
// 					return 1;
// 			}
// 			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
// 				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0)
// 			{
// 				if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) < 0)
// 					return -1;
// 				else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) > 0)
// 					return 1;
// 			}
// 			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
// 				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
// 				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) == 0)
// 			{
// 				if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[3], pRef[3], pCmp[3]) < 0)
// 					return -1;
// 				else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[3], pRef[3], pCmp[3]) > 0)
// 					return 1;
// 			}
// 			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
// 				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
// 				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) == 0 &&
// 				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[3], pRef[3], pCmp[3]) == 0)
// 			{
// 				return 0;
// 			}




			if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) < 0 ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) < 0) ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) < 0) ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[3], pRef[3], pCmp[3]) < 0))
			{
				return -1;
			}
			else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[3], pRef[3], pCmp[3]) == 0)
			{
				return 0;
			}
			else if (MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) > 0 ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) > 0) ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) > 0) ||
				(MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[0], pRef[0], pCmp[0]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[1], pRef[1], pCmp[1]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[2], pRef[2], pCmp[2]) == 0 &&
				MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[3], pRef[3], pCmp[3]) > 0))
			{
				return 1;
			}
			break;
		default:
			break;
		}

		return 0;
	}

	template<typename T>	int		MDBCompareRestrict(T* pBlock, const int nTable, const int nRecord, std::vector<std::string>& strRestFieldArray)
	{
		register int	i;
		char	*pRef[g_nConstMaxPrimaryKey], *pCmp[g_nConstMaxPrimaryKey];

		for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
		{
			pRef[i]=MDBGetFieldRecordAddr(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i], nRecord);
			pCmp[i]=(char*)strRestFieldArray[i].c_str();
		}
		return MDBCompareRestrictArray(pBlock, nTable, pRef, pCmp);
	}

	template<typename T>	int		MDBCompareRestrict(T* pBlock, const int nTable, const int nRecord, const char lpszRestFieldArray[][MDB_CHARLEN_LONG])
	{
		register int	i;
		char	*pRef[g_nConstMaxPrimaryKey], *pCmp[g_nConstMaxPrimaryKey];

		for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
		{
			pRef[i]=MDBGetFieldRecordAddr(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i], nRecord);
			pCmp[i]=(char*)lpszRestFieldArray[i];
		}
		return MDBCompareRestrictArray(pBlock, nTable, pRef, pCmp);
	}

	template<typename T>	int		MDBCompareRestrict(T* pBlock, const int nTable, const int nBaseRec, const int nCompRec)
	{
		register int	i;
		char	*pRef[g_nConstMaxPrimaryKey], *pCmp[g_nConstMaxPrimaryKey];

		for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
		{
			pRef[i]=MDBGetFieldRecordAddr(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i], nBaseRec);
			pCmp[i]=MDBGetFieldRecordAddr(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i], nCompRec);
		}
		return MDBCompareRestrictArray(pBlock, nTable, pRef, pCmp);
	}

	template<typename T>	void	getTableRest(T* pBlock, const int nTable, const int nRecord, std::vector<std::string>& strRecArray)
	{
		int		nRest, nField;
		char	szRec[MDB_CHARLEN_LONG];
		for (nRest=0; nRest<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; nRest++)
		{
			nField=pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[nRest];
			MDBGetRecordValue(pBlock, nTable, nField, nRecord, szRec);
			strRecArray[nRest]=szRec;
		}
	}

	template<typename T>	void	swap(T* pBlock, const int nTable, const int nSwA, const int nSwB)
	{
		char	*pAddrA, *pAddrB;

		void*	pBuf=(void*)malloc(pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen);
		if (pBuf != NULL)
		{
			pAddrA=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nSwA;
			pAddrB=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nSwB;

			memcpy(pBuf,	pAddrA,	pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen);
			memcpy(pAddrA,	pAddrB,	pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen);
			memcpy(pAddrB,	pBuf,	pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen);

			free(pBuf);
		}
		else
		{
			MDBLog("Error in malloc %d when swap[%d %d]\n", nTable, nSwA, nSwB);
		}
	}

	template<typename T>	void	quickSort(T* pBlock, const int nTable, int nDn0, int nUp0)
	{
		int nDn = nDn0;
		int nUp = nUp0;

		if (nUp0 <= nDn0)
			return;

		//char	szRec[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		std::vector<std::string>	strRecArray;
		strRecArray.resize(pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum);
		getTableRest(pBlock, nTable, (nDn0+nUp0)/2, strRecArray);

		while (nDn <= nUp)
		{
			while (nDn < nUp0 && MDBCompareRestrict(pBlock, nTable, nDn, strRecArray) < 0)
				++nDn;
			while (nUp > nDn0 && MDBCompareRestrict(pBlock, nTable, nUp, strRecArray) > 0)
				--nUp;

			if (nDn <= nUp)
			{
				swap(pBlock, nTable, nDn, nUp);
				++nDn;
				--nUp;
			}
		}
		strRecArray.clear();

		if (nDn0 < nUp)
			quickSort(pBlock, nTable, nDn0, nUp);
		if (nDn < nUp0 )
			quickSort(pBlock, nTable, nDn, nUp0);
	}

	// 需要注意的是除了System表外的其他表的排序不对最后一行记录排序。这一点需要注意
	template<typename T>	void	MDBSort(T* pBlock, const int nSortTable)
	{
		int		nTable;
		for (nTable=0; nTable<pBlock->m_MDBSummary.nTableNum; nTable++)
		{
			if (nSortTable >= 0 && nTable != nSortTable)
				continue;
			if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum <= 0)
				continue;

			quickSort(pBlock, nTable, 0, pBlock->m_nRecordNum[nTable]-1);
		}
	}
}
