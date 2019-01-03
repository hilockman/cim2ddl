#include "MemDBBaseExtern.h"
#include "../../Common/StringCommon.h"
#include <float.h>
#include <assert.h>
#include <iostream>

namespace	MemDBBase
{
	template<typename T>	int MDBGetRecordValue(T* pBlock, const int nTable, const int nField, const int nRecord, char* lpszRet)
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return 0;

		if (nField < 0 || nField >= pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum)
			return 0;

		//	不能加记录判断，因为APPEND等方法往往采用最后添加模式
		//if (nRecord < 0 || nRecord >= pBlock->m_nRecordNum[nTable])
		//	return 0;
		char*	lpszFieldAddr=MDBGetFieldRecordAddr(pBlock, nTable, nField, nRecord);
		if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_STRING)
		{
			register int	i;
			for (i=0; i<(int)strlen(lpszFieldAddr); i++)
			{
				if (i >= pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen-1)
					break;
				lpszRet[i]=lpszFieldAddr[i];
			}
			lpszRet[i]='\0';
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_DOUBLE)
		{
			double fValue;
			memcpy(&fValue,	lpszFieldAddr,	sizeof(double));
			//strcpy(lpszRet, DoubleToString(fValue).c_str());

			std::stringstream os;
			os << fValue;
			std::string sf = os.str();

			//modify by wangheng 2018/1/10
			//strcpy(lpszRet, sf.c_str());
			if (sf.find("e") == string::npos && sf.find("E") == string::npos) {
				strcpy(lpszRet, sf.c_str());
			} else {
				sprintf(lpszRet, "%lf", fValue);
			}
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_FLOAT)
		{
			float fValue;
			memcpy(&fValue,	lpszFieldAddr,	sizeof(float));
			//strcpy(lpszRet, DoubleToString(fValue).c_str());

			std::stringstream os;
			os << fValue;
			std::string sf = os.str();

            //modify by wangheng 2018/1/10
			//strcpy(lpszRet, sf.c_str());
			if (sf.find("e") == string::npos && sf.find("E") == string::npos) {
				strcpy(lpszRet, sf.c_str());
			} else {
				sprintf(lpszRet, "%f", fValue);
			}
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_INT)
		{
			int nValue;
			memcpy(&nValue,	lpszFieldAddr,	sizeof(int));
			sprintf(lpszRet, "%d", nValue);
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_SHORT)
		{
			short nValue;
			memcpy(&nValue,	lpszFieldAddr,	sizeof(short));
			sprintf(lpszRet, "%d", nValue);
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_BIT)
		{
			unsigned char nValue;
			memcpy(&nValue,	lpszFieldAddr,	sizeof(unsigned char));
			sprintf(lpszRet, "%d", nValue);
		}
		else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_CHAR)
		{
			lpszRet[0]=lpszFieldAddr[0];
			lpszRet[1]='\0';
		}

		return 1;
	}

	template<typename T>	int MDBSetRecordValue(T* pBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		char*	lpAddr;

		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return 0;

		if (nField < 0 || nField >= pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum)
			return 0;

		//	不能加记录判断，因为APPEND等方法往往采用最后添加模式
		//if (nRecord < 0 || nRecord >= pBlock->m_nRecordNum[nTable])
		//	return 0;

		lpAddr=MDBGetFieldRecordAddr(pBlock, nTable, nField, nRecord);
		switch (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType)
		{
		case	MDB_STRING:
			for (i=0; i<(int)strlen(lpszValue); i++)
			{
				if (i >= pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen-1)
					break;
				lpAddr[i]=lpszValue[i];
			}
			lpAddr[i]='\0';
			break;
		case	MDB_DOUBLE:
			dBuf=atof(lpszValue);
			//if (fabs(dBuf) > DBL_MAX)
			//	dBuf=0;
			memcpy(lpAddr, &dBuf, sizeof(double));
			break;
		case	MDB_FLOAT:
			fBuf=StringToFloat(lpszValue);
			//if (fabs(fBuf) > FLT_MAX)
			//	fBuf=0;
			memcpy(lpAddr, &fBuf, sizeof(float));
			break;
		case	MDB_INT:
			nBuf=atoi(lpszValue);
			//if (abs(nBuf) > INT_MAX)
			//	nBuf=0;
			memcpy(lpAddr, &nBuf, sizeof(int));
			break;
		case	MDB_SHORT:
			sBuf=(short)atoi(lpszValue);
			//if (abs(sBuf) > SHRT_MAX)
			//	sBuf=0;
			memcpy(lpAddr, &sBuf, sizeof(short));
			break;
		case	MDB_BIT:
			uBuf=(unsigned char)atoi(lpszValue);
			//if (uBuf > 256 || uBuf < 0)
			//	uBuf=0;
			memcpy(lpAddr, &uBuf, sizeof(unsigned char));
			break;
		case	MDB_CHAR:
			lpAddr[0]=lpszValue[0];
			break;
		}

		return 1;
	}

	template<typename T>	int MDBGetRecordValue(T* pBlock, const int nTable, const int nRecord, char lpszRetArray[][MDB_CHARLEN_LONG])
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
		{
			MDBLog("MDBGetRecordValue(Row) Table=%d 错误(%d)", nTable, pBlock->m_MDBSummary.nTableNum);
			return 0;
		}

		//	不能加记录判断，因为APPEND等方法往往采用最后添加模式
		//if (nRecord < 0 || nRecord >= pBlock->m_nRecordNum[nTable])
		//	return 0;

		register int	i;

		char*	lpszFieldAddr=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nRecord;
		for (int nField=0; nField<pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum; nField++)
		{
			if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_STRING)
			{
				for (i=0; i<(int)strlen(lpszFieldAddr); i++)
				{
					if (i >= pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen-1)
						break;
					lpszRetArray[nField][i]=lpszFieldAddr[i];
				}
				lpszRetArray[nField][i]='\0';
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_DOUBLE)
			{
				double fValue;
				memcpy(&fValue,	lpszFieldAddr,	sizeof(double));

				std::stringstream os;
				os << fValue;
				std::string sf = os.str();

//modify by wangheng 2018/1/10
				//strcpy(lpszRetArray[nField], sf.c_str());
				if (sf.find("e") == string::npos)
					strcpy(lpszRetArray[nField], sf.c_str());
				else
					sprintf(lpszRetArray[nField], "%lf", fValue);

				//if (fValue < 1e-6 && fValue > FLT_MIN)
				//	sprintf(lpszRetArray[nField], "%.14f", fValue);
				//else
				//	sprintf(lpszRetArray[nField], "%f", fValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_FLOAT)
			{
				float fValue;
				memcpy(&fValue,	lpszFieldAddr,	sizeof(float));

				std::stringstream os;
				os << fValue;
				std::string sf = os.str();

//modify by wangheng 2018/1/10
				//strcpy(lpszRetArray[nField], sf.c_str());
				if (sf.find("e") == string::npos)
					strcpy(lpszRetArray[nField], sf.c_str());
				else
					sprintf(lpszRetArray[nField], "%f", fValue);

				//sprintf(lpszRetArray[nField], "%f", fValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_INT)
			{
				int nValue;
				memcpy(&nValue,	lpszFieldAddr,	sizeof(int));
				sprintf(lpszRetArray[nField], "%d", nValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_SHORT)
			{
				short nValue;
				memcpy(&nValue,	lpszFieldAddr,	sizeof(short));
				sprintf(lpszRetArray[nField], "%d", nValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_BIT)
			{
				unsigned char nValue;
				memcpy(&nValue,	lpszFieldAddr,	sizeof(unsigned char));
				sprintf(lpszRetArray[nField], "%d", nValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_CHAR)
			{
				lpszRetArray[nField][0]=lpszFieldAddr[0];
				lpszRetArray[nField][1]='\0';
			}
			lpszFieldAddr += pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen;
		}

		return 1;
	}

	template<typename T>	int MDBGetRecordColumnValue(T* pBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetArray[][MDB_CHARLEN_LONG])
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
		{
			MDBLog("MDBGetRecordValue(Row) Table=%d 错误(%d)", nTable, pBlock->m_MDBSummary.nTableNum);
			return 0;
		}

		//	不能加记录判断，因为APPEND等方法往往采用最后添加模式
		if (nIniRecord < 0 || nIniRecord > pBlock->m_nRecordNum[nTable])
			return 0;

		register int	i;
		char*	lpszFieldAddr=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nIniRecord;
		for (i=0; i<nField; i++)
			lpszFieldAddr += pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[i].nDataLen;

		int		nRecord=0;
		while (nRecord < nMaxCount && nRecord+nIniRecord < pBlock->m_nRecordNum[nTable])
		{
			if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_STRING)
			{
				for (i=0; i<(int)strlen(lpszFieldAddr); i++)
				{
					if (i >= pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen-1)
						break;
					lpszRetArray[nRecord][i]=lpszFieldAddr[i];
				}
				lpszRetArray[nRecord][i]='\0';
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_DOUBLE)
			{
				double fValue;
				memcpy(&fValue,	lpszFieldAddr,	sizeof(double));

				std::stringstream os;
				os << fValue;
				std::string sf = os.str();
				if (sf.find("e") == string::npos)
					strcpy(lpszRetArray[nRecord], sf.c_str());
				else
					sprintf(lpszRetArray[nRecord], "%lf", fValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_FLOAT)
			{
				float fValue;
				memcpy(&fValue,	lpszFieldAddr,	sizeof(float));

				std::stringstream os;
				os << fValue;
				std::string sf = os.str();
				if (sf.find("e") == string::npos)
					strcpy(lpszRetArray[nRecord], sf.c_str());
				else
					sprintf(lpszRetArray[nRecord], "%f", fValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_INT)
			{
				int nValue;
				memcpy(&nValue,	lpszFieldAddr,	sizeof(int));
				sprintf(lpszRetArray[nRecord], "%d", nValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_SHORT)
			{
				short nValue;
				memcpy(&nValue,	lpszFieldAddr,	sizeof(short));
				sprintf(lpszRetArray[nRecord], "%d", nValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_BIT)
			{
				unsigned char nValue;
				memcpy(&nValue,	lpszFieldAddr,	sizeof(unsigned char));
				sprintf(lpszRetArray[nRecord], "%d", nValue);
			}
			else if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType == MDB_CHAR)
			{
				lpszRetArray[nRecord][0]=lpszFieldAddr[0];
				lpszRetArray[nRecord][1]='\0';
			}

			lpszFieldAddr += pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen;
			nRecord++;
		}

		return nRecord;
	}

	template<typename T>	int MDBSetRecordValue(T* pBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		char*	lpAddr;
		int		nField;

		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return 0;

		//	不能加判断，因为APPEND等方法往往在最后设置记录信息
// 		if (nRecord < 0 || nRecord >= pBlock->m_nRecordNum[nTable])
// 			return 0;

		lpAddr=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nRecord;
		for (nField=0; nField<pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum; nField++)
		{
			switch (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType)
			{
			case	MDB_STRING:
				for (i=0; i<(int)strlen(lpszValue[nField]); i++)
				{
					if (i >= pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen-1)
						break;
					lpAddr[i]=lpszValue[nField][i];
				}
				lpAddr[i]='\0';
				break;
			case	MDB_DOUBLE:
				dBuf=atof(lpszValue[nField]);
				//if (fabs(dBuf) > DBL_MAX)
				//	dBuf=0;
				memcpy(lpAddr, &dBuf, sizeof(double));
				break;
			case	MDB_FLOAT:
				fBuf=StringToFloat(lpszValue[nField]);
				//if (fabs(fBuf) > FLT_MAX)
				//	fBuf=0;
				memcpy(lpAddr, &fBuf, sizeof(float));
				break;
			case	MDB_INT:
				nBuf=atoi(lpszValue[nField]);
				//if (abs(nBuf) > INT_MAX)
				//	nBuf=0;
				memcpy(lpAddr, &nBuf, sizeof(int));
				break;
			case	MDB_SHORT:
				sBuf=(short)atoi(lpszValue[nField]);
				//if (abs(sBuf) > SHRT_MAX)
				//	sBuf=0;
				memcpy(lpAddr, &sBuf, sizeof(short));
				break;
			case	MDB_BIT:
				uBuf=(unsigned char)atoi(lpszValue[nField]);
				//if (uBuf > 256 || uBuf < 0)
				//	uBuf=0;
				memcpy(lpAddr, &uBuf, sizeof(unsigned char));
				break;
			case	MDB_CHAR:
				lpAddr[0]=lpszValue[nField][0];
				break;
			}
			lpAddr += pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen;
		}

		return 1;
	}

	template<typename T>	int MDBGetRecordRow(T* pBlock, const int nTable, const int nRecord, char* lpszValueArray)
	{
		int		nCol;
		char	szValue[MDB_CHARLEN_LONG];
		std::string	strBuf;

		strBuf.clear();
		for (nCol=0; nCol<pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum; nCol++)
		{
			memset(szValue, 0, MDB_CHARLEN_LONG);
			MDBGetRecordValue(pBlock, nTable, nCol, nRecord, szValue);
			if (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nCol].nDataType == MDB_STRING)
			{
				strBuf.append("\"");
				strBuf.append(szValue);
				strBuf.append("\"");
			}
			else
			{
				strBuf.append(szValue);
			}
			strBuf.append("\\");
		}
		strcpy(lpszValueArray, strBuf.c_str());
		return 1;
	}

	template<typename T>	int	MDBFindRecordBubble(T* pBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue)
	{
		register int	i;
		char	szData[MDB_CHARLEN_LONG];
		int		nRecord=nIniRecord;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		char*	lpAddr;

		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return -1;

		if (nField < 0 || nField >= pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum)
			return -1;


		int	nLoop=1;
		while (nLoop)
		{
			lpAddr=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nRecord;
			for (i=0; i<nField; i++)
				lpAddr += pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[i].nDataLen;
			switch (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType)
			{
			case	MDB_STRING:
				memcpy(szData, lpAddr, pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen);
				if (strstr(szData, lpszValue) != NULL)
					return nRecord;
				break;
			case	MDB_DOUBLE:
				memcpy(&dBuf, lpAddr, sizeof(double));
				if (fabs(dBuf-atof(lpszValue)) < 0.000001)
					return nRecord;
				break;
			case	MDB_FLOAT:
				memcpy(&fBuf, lpAddr, sizeof(float));
				if (fabs(fBuf-StringToFloat(lpszValue)) < 0.000001)
					return nRecord;
				break;
			case	MDB_INT:
				memcpy(&nBuf, lpAddr, sizeof(int));
				if (nBuf == atoi(lpszValue))
					return nRecord;
				break;
			case	MDB_SHORT:
				memcpy(&sBuf, lpAddr, sizeof(short));
				if (sBuf == atoi(lpszValue))
					return nRecord;
				break;
			case	MDB_BIT:
				memcpy(&uBuf, lpAddr, sizeof(unsigned char));
				if (uBuf == atoi(lpszValue))
					return nRecord;
				break;
			case	MDB_CHAR:
				if (lpAddr[0] == lpszValue[0])
					return nRecord;
				break;
			default:
				break;
			}

			nRecord++;
			if (nRecord >= pBlock->m_nRecordNum[nTable])
			{
				nRecord=0;
				break;
			}
		}
		return nRecord;
	}

	template<typename T>	int	MDBFindRecordBubble(T* pBlock, const int nTable, const int nIniRecord, const char lpszRestArray[][MDB_CHARLEN_LONG])
	{
		unsigned char	bFind;
		int		nCompare;

		for (int nRecord=nIniRecord; nRecord<pBlock->m_nRecordNum[nTable]; nRecord++)
		{
			bFind=0;
			for (int nRest=0; nRest<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; nRest++)
			{
				if (strlen(lpszRestArray[nRest]) <= 0)
				{
					bFind++;
					continue;
				}

				nCompare=MDBCompareFieldValue(pBlock, nTable, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[nRest], nRecord, lpszRestArray[nRest]);
				if (nCompare < 0)
				{
					 break;
				}
				else if (nCompare == 0)
				{
					bFind++;
				}
				else if (nRest < pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum-1 && nCompare > 0)
				{
					return -1;
				}
			}
			if (bFind == pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum)
				return nRecord;
		}
		return -1;
	}

	template<typename T>	int	MDBFindRecordQuick(T* pBlock, const int nTable, int nLeft, int nRight, const char lpszRestValue[][MDB_CHARLEN_LONG])
	{
		if (nLeft <= nRight)
		{
			int	nMid = (nLeft+nRight)/2;
			int	nCompare=MDBCompareRestrict(pBlock, nTable, nMid, lpszRestValue);
			if (nCompare == 0)	//	if (SubArray[nMid].nObjID == nSubID)
			{
				return nMid;
			}
			else
			{
				if (nCompare > 0)
					return MDBFindRecordQuick(pBlock, nTable, nLeft, nMid-1, lpszRestValue);
				else
					return MDBFindRecordQuick(pBlock, nTable, nMid+1, nRight, lpszRestValue);
			}
		}
		else
		{
			return -1;
		}
	}

	template<typename T>	int	MDBFindRecord(T* pBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return -1;

		register int	i;
		char	szRestArray[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
			strcpy(szRestArray[i], lpszValue[pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i]]);
		return MDBFindRecordQuick(pBlock, nTable, 0, pBlock->m_nRecordNum[nTable]-1, szRestArray);
	}

	template<typename T>	int	MDBFindRecordFuzzy(T* pBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG])
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return -1;

		register int	i;
		int		nFind;
		unsigned char	bCanQuick;
		char	szRestArray[g_nConstMaxPrimaryKey][MDB_CHARLEN_LONG];
		for (i=0; i<g_nConstMaxPrimaryKey; i++)
			memset(szRestArray[i], 0, MDB_CHARLEN_LONG);

		bCanQuick=1;
		for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
		{
			strcpy(szRestArray[i], lpszValue[pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i]]);
			if (strlen(szRestArray[i]) <= 0)
				bCanQuick=0;
		}

		nFind=-1;
		if (bCanQuick)
			nFind=MDBFindRecordQuick(pBlock, nTable, 0, pBlock->m_nRecordNum[nTable]-1, szRestArray);
		else
			nFind=MDBFindRecordBubble(pBlock, nTable, 0, szRestArray);

// 		MDBLog("MDBFindRecordFuzzy = %d bCanQuick=%d\n", nFind, bCanQuick);
// 		for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
// 			MDBLog("    Rest[%d/%d]=%s Len=%d\n", i, pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum, szRestArray[i], strlen(szRestArray[i]));

		return nFind;
	}

	template<typename T>	int	MDBInsertRecord(T* pBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return 0;
		if (pBlock->m_nRecordNum[nTable] >= pBlock->m_MDBSummary.sMDBTableArray[nTable].nRecordMax)
			return 0;

		if (MDBCheckRecord(pBlock, nTable, -1, MDB_CheckNull, MDB_CheckExist, MDB_CheckContainer, lpszRecArray))
		{
			MDBAppendRecord(pBlock, MDB_NoNeedCheckData, nTable, lpszRecArray);
			MDBSort(pBlock, nTable);
			return 1;
		}
		return 0;
	}

	template<typename T>	int	MDBAppendRecord(T* pBlock, const int bNeedCheck, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return 0;
		if (pBlock->m_nRecordNum[nTable] >= pBlock->m_MDBSummary.sMDBTableArray[nTable].nRecordMax)
			return 0;

		//MDBLog("MDBAppendRecord: StrLen=%d %d RecNum=%d %d\n", sizeof(lpszRecArray), sizeof(lpszRecArray[0]), sizeof(lpszRecArray)/sizeof(char*), sizeof(lpszRecArray)/MDB_CHARLEN_LONG);
		if (bNeedCheck)
		{
			if (!MDBCheckRecord(pBlock, nTable, -1, MDB_CheckNull, MDB_CheckExist, MDB_NoCheckContainer, lpszRecArray))
			{
				register int	i;
				MDBLog("MDBAppendRecord错误：表[%s] CheckRecord Error 记录: ", pBlock->m_MDBSummary.sMDBTableArray[nTable].szDesp);
				for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
					MDBLog("[%s] ", lpszRecArray[pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i]]);
				MDBLog("\n");
				return 0;
			}
		}

		MDBSetRecordValue(pBlock, nTable, pBlock->m_nRecordNum[nTable], lpszRecArray);
		pBlock->m_nRecordNum[nTable]++;

		return 1;
	}

	template<typename T>	int	MDBUpdateRecord(T* pBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG])
	{
		register int	i;
		int		nField;
		char*	lpAddr;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		unsigned char	bRestrict;


		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
		{
			MDBLog("MDBUpdateRecord(1) Table=%d 错误", nTable);
			return 0;
		}

		int		nRecord=MDBFindRecord(pBlock, nTable, lpszRecArray);
		if (nRecord < 0)
		{
			MDBLog("MDBUpdateRecord(2) Table=%d 错误", nTable);
			return 0;
		}

		lpAddr=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nRecord;
		for (nField=0; nField<pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldNum; nField++)
		{
			bRestrict=0;
			for (i=0; i<pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyNum; i++)
			{
				if (nField == pBlock->m_MDBSummary.sMDBTableArray[nTable].sPrimaryKey.nPrimaryKeyId[i])
				{
					bRestrict=1;
					break;
				}
			}
			if (!bRestrict)
			{
				switch (pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataType)
				{
				case	MDB_STRING:
					for (i=0; i<(int)strlen(lpszRecArray[nField]); i++)
					{
						if (i >= pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen-1)
							break;
						lpAddr[i]=(char)lpszRecArray[nField][i];
					}
					lpAddr[i]='\0';
					break;
				case	MDB_DOUBLE:
					//String2Double(dBuf, lpszRecArray[nCol]);	//dBuf=atof(lpszRecArray[nCol]);
					dBuf=atof(lpszRecArray[nField]);
					memcpy(lpAddr, &dBuf, sizeof(double));
					break;
				case	MDB_FLOAT:
					fBuf=StringToFloat(lpszRecArray[nField]);
					memcpy(lpAddr, &fBuf, sizeof(float));
					break;
				case	MDB_INT:
					nBuf=atoi(lpszRecArray[nField]);
					memcpy(lpAddr, &nBuf, sizeof(int));
					break;
				case	MDB_SHORT:
					sBuf=(short)atoi(lpszRecArray[nField]);
					memcpy(lpAddr, &sBuf, sizeof(short));
					break;
				case	MDB_BIT:
					uBuf=(unsigned char)atoi(lpszRecArray[nField]);
					memcpy(lpAddr, &uBuf, sizeof(unsigned char));
					break;
				case	MDB_CHAR:
					lpAddr[0]=lpszRecArray[nField][0];
					break;
				}
			}
			lpAddr += pBlock->m_MDBSummary.sMDBTableArray[nTable].sFieldArray[nField].nDataLen;
		}

		return 1;
	}

	template<typename T>	int	MDBRemoveRecord(T* pBlock, const int nTable, const int nRecord)
	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
		{
			MDBLog("        MDBRemoveRecord Table=%d Record=%d 表错误(TableNum=%d)\n", nTable, nRecord, pBlock->m_MDBSummary.nTableNum);
			return 0;
		}

		if (nRecord < 0 || nRecord >= pBlock->m_nRecordNum[nTable])
		{
			MDBLog("        MDBRemoveRecord Table=%d Record=%d 记录错误(RecordNum=%d)\n", nTable, nRecord, pBlock->m_nRecordNum[nTable]);
			return 0;
		}

		MDBLog("        MDBRemoveRecord Table=%d Record=%d\n", nTable, nRecord);
		register int	i;
		char	*lpDst, *lpSrc;
		for (i=nRecord; i<pBlock->m_nRecordNum[nTable]-1; i++)
		{
			lpDst=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*i;		//	记录i的首地址
			lpSrc=lpDst+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen;																//	记录i的首地址
			memcpy(lpDst, lpSrc, pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen);
		}

		// lpAddr1=(char*)pBlock+pBlock->m_MDBSummary.sMDBTableArray[nTable].nOffSet+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen*nRecord;		//	记录i的首地址
		// memcpy(lpAddr1, 
		// 	lpAddr1+pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen, 
		// 	(pBlock->m_nRecordNum[nTable]-nRecord-1)*pBlock->m_MDBSummary.sMDBTableArray[nTable].nFieldLen);

		if (pBlock->m_nRecordNum[nTable] > 0)
			pBlock->m_nRecordNum[nTable]--;

		return 1;
	}

	template<typename T>	int	MDBGetFilterIndexArray(T* pBlock, const int bAndOr, const int nTable, 
		const int nFilterField1, const char* lpszFilterKey1Array, 
		const int nFilterField2, const char* lpszFilterKey2Array, 
		const int nFilterField3, const char* lpszFilterKey3Array, 
		const int nFilterField4, const char* lpszFilterKey4Array, 
		const int nIndexCapacity, int nIndexArray[])

	{
		if (nTable < 0 || nTable >= pBlock->m_MDBSummary.nTableNum)
			return 0;

		register int	i;
		int		nChar, nRecord, nIndex;
		unsigned char	bMatched;
		std::vector<std::string>	strKey1Array;
		std::vector<std::string>	strKey2Array;
		std::vector<std::string>	strKey3Array;
		std::vector<std::string>	strKey4Array;
		char	szField[MDB_CHARLEN_LONG];
		memset(szField, 0, MDB_CHARLEN_LONG);

		strKey1Array.clear();
		strKey2Array.clear();
		strKey3Array.clear();
		strKey4Array.clear();

		if (lpszFilterKey1Array != NULL)
		{
			nChar=0;
			for (i=0; i<(int)strlen(lpszFilterKey1Array); i++)
			{
				//if (lpszFilterKey1Array[i] == ' ' || lpszFilterKey1Array[i] == '\t')
				//	continue;

				if (lpszFilterKey1Array[i] == '\\' || lpszFilterKey1Array[i] == '\r' || lpszFilterKey1Array[i] == '\n')
				{
					szField[nChar++]='\0';
					strKey1Array.push_back(szField);
					nChar=0;
				}
				else
				{
					szField[nChar++]=lpszFilterKey1Array[i];
				}
			}
		}
		if (lpszFilterKey2Array != NULL)
		{
			nChar=0;
			for (i=0; i<(int)strlen(lpszFilterKey2Array); i++)
			{
				//if (lpszFilterKey2Array[i] == ' ' || lpszFilterKey2Array[i] == '\t')
				//	continue;

				if (lpszFilterKey2Array[i] == '\\' || lpszFilterKey2Array[i] == '\r' || lpszFilterKey2Array[i] == '\n')
				{
					szField[nChar++]='\0';
					strKey2Array.push_back(szField);
					nChar=0;
				}
				else
				{
					szField[nChar++]=lpszFilterKey2Array[i];
				}
			}
		}
		if (lpszFilterKey3Array != NULL)
		{
			nChar=0;
			for (i=0; i<(int)strlen(lpszFilterKey3Array); i++)
			{
				//if (lpszFilterKey3Array[i] == ' ' || lpszFilterKey3Array[i] == '\t')
				//	continue;

				if (lpszFilterKey3Array[i] == '\\' || lpszFilterKey3Array[i] == '\r' || lpszFilterKey3Array[i] == '\n')
				{
					szField[nChar++]='\0';
					strKey3Array.push_back(szField);
					nChar=0;
				}
				else
				{
					szField[nChar++]=lpszFilterKey3Array[i];
				}
			}
		}
		if (lpszFilterKey4Array != NULL)
		{
			nChar=0;
			for (i=0; i<(int)strlen(lpszFilterKey4Array); i++)
			{
				//if (lpszFilterKey4Array[i] == ' ' || lpszFilterKey4Array[i] == '\t')
				//	continue;

				if (lpszFilterKey4Array[i] == '\\' || lpszFilterKey4Array[i] == '\r' || lpszFilterKey4Array[i] == '\n')
				{
					szField[nChar++]='\0';
					strKey4Array.push_back(szField);
					nChar=0;
				}
				else
				{
					szField[nChar++]=lpszFilterKey4Array[i];
				}
			}
		}

		nIndex=0;
		for (nRecord=0; nRecord<pBlock->m_nRecordNum[nTable]; nRecord++)
		{
			if (bAndOr == 0)	//	与
			{
				bMatched=1;
				if (bMatched && nFilterField1 >= 0 && !strKey1Array.empty())
				{
					bMatched=0;
					memset(szField, 0, MDB_CHARLEN_LONG);
					MDBGetRecordValue(pBlock, nTable, nFilterField1, nRecord, szField);
					for (i=0; i<(int)strKey1Array.size(); i++)
					{
						if (STRICMP(strKey1Array[i].c_str(), szField) == 0)
						{
							bMatched=1;
							break;
						}
					}
				}
				if (bMatched && nFilterField2 >= 0 && !strKey2Array.empty())
				{
					bMatched=0;
					memset(szField, 0, MDB_CHARLEN_LONG);
					MDBGetRecordValue(pBlock, nTable, nFilterField2, nRecord, szField);
					for (i=0; i<(int)strKey2Array.size(); i++)
					{
						if (STRICMP(strKey2Array[i].c_str(), szField) == 0)
						{
							bMatched=1;
							break;
						}
					}
				}
				if (bMatched && nFilterField3 >= 0 && !strKey3Array.empty())
				{
					bMatched=0;
					memset(szField, 0, MDB_CHARLEN_LONG);
					MDBGetRecordValue(pBlock, nTable, nFilterField3, nRecord, szField);
					for (i=0; i<(int)strKey3Array.size(); i++)
					{
						if (STRICMP(strKey3Array[i].c_str(), szField) == 0)
						{
							bMatched=1;
							break;
						}
					}
				}
				if (bMatched && nFilterField4 >= 0 && !strKey4Array.empty())
				{
					bMatched=0;
					memset(szField, 0, MDB_CHARLEN_LONG);
					MDBGetRecordValue(pBlock, nTable, nFilterField4, nRecord, szField);
					for (i=0; i<(int)strKey4Array.size(); i++)
					{
						if (STRICMP(strKey4Array[i].c_str(), szField) == 0)
						{
							bMatched=1;
							break;
						}
					}
				}
			}
			else	//	或
			{
				bMatched=0;
				if (!bMatched && nFilterField1 >= 0)
				{
					if (lpszFilterKey1Array == NULL || strKey1Array.empty())
						bMatched=1;
					else
					{
						memset(szField, 0, MDB_CHARLEN_LONG);
						MDBGetRecordValue(pBlock, nTable, nFilterField1, nRecord, szField);
						for (i=0; i<(int)strKey1Array.size(); i++)
						{
							if (STRICMP(strKey1Array[i].c_str(), szField) == 0)
							{
								bMatched=1;
								break;
							}
						}
					}
				}
				if (!bMatched && nFilterField2 >= 0)
				{
					if (lpszFilterKey2Array == NULL || strKey2Array.empty())
						bMatched=1;
					else
					{
						memset(szField, 0, MDB_CHARLEN_LONG);
						MDBGetRecordValue(pBlock, nTable, nFilterField2, nRecord, szField);
						for (i=0; i<(int)strKey2Array.size(); i++)
						{
							if (STRICMP(strKey2Array[i].c_str(), szField) == 0)
							{
								bMatched=1;
								break;
							}
						}
					}
				}
				if (!bMatched && nFilterField3 >= 0)
				{
					if (lpszFilterKey3Array == NULL || strKey3Array.empty())
						bMatched=1;
					else
					{
						memset(szField, 0, MDB_CHARLEN_LONG);
						MDBGetRecordValue(pBlock, nTable, nFilterField3, nRecord, szField);
						for (i=0; i<(int)strKey3Array.size(); i++)
						{
							if (STRICMP(strKey3Array[i].c_str(), szField) == 0)
							{
								bMatched=1;
								break;
							}
						}
					}
				}
				if (!bMatched && nFilterField4 >= 0)
				{
					if (lpszFilterKey4Array == NULL || strKey4Array.empty())
						bMatched=1;
					else
					{
						memset(szField, 0, MDB_CHARLEN_LONG);
						MDBGetRecordValue(pBlock, nTable, nFilterField4, nRecord, szField);
						for (i=0; i<(int)strKey4Array.size(); i++)
						{
							if (STRICMP(strKey4Array[i].c_str(), szField) == 0)
							{
								bMatched=1;
								break;
							}
						}
					}
				}
			}
			if (bMatched && nIndex < nIndexCapacity)
				nIndexArray[nIndex++]=nRecord;
		}
		return nIndex;
	}

	template<typename T>	int MDBAppendRecordByRow(T* pBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser)
	{
		register int	i;
		int		nCol, nChar;
		unsigned char	bStringSection;
		char	szRecArray[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];

		for (i=0; i<MAXMDBFIELDNUM; i++)
			memset(szRecArray[i], 0, MDB_CHARLEN_LONG);

		bStringSection=0;
		nCol=nChar=0;
		const int nCharLen=(int)strlen(lpszParser);
		for (i=0; i<nCharLen; i++)
		{
			if (bStringSection)
			{
				if (lpszParser[i] == '\"' || lpszParser[i] == '\'')
				{
					if (nFieldIndex[nCol] >= 0)	szRecArray[nFieldIndex[nCol]][nChar++]='\0';
					bStringSection=0;
				}
				else
				{
					if (nFieldIndex[nCol] >= 0)
						szRecArray[nFieldIndex[nCol]][nChar++]=lpszParser[i];
				}
			}
			else
			{
				if (lpszParser[i] == '\"' || lpszParser[i] == '\'')
				{
					bStringSection=1;
					nChar=0;
				}
				else
				{
					if (lpszParser[i] == '\\' || lpszParser[i] == ',' || lpszParser[i] == '\r' || lpszParser[i] == '\n')
					{
						if (nFieldIndex[nCol] >= 0)	szRecArray[nFieldIndex[nCol]][nChar++]='\0';
						nCol++;

						nChar=0;
					}
					else
					{
						//if (nFieldIndex[nCol] >= 0)
						if (nFieldIndex[nCol] >= 0 && lpszParser[i] != ' ' && lpszParser[i] != '\t')
							szRecArray[nFieldIndex[nCol]][nChar++]=lpszParser[i];
					}
				}
			}
		}

		return MDBAppendRecord(pBlock, bNeedCheck, nTable, szRecArray);
	}
}
