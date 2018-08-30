#include "stdafx.h"
#include "BpaMemDB.h"
#include "BpaMemDBExtern.h"
#include "../../Common/String2Double.hpp"
#include "../../Common/StringCommon.h"

namespace	BpaMemDB
{
	void	BpaDataPtr2FieldArray(const int nTable, const char* lpszDataPtr, char szField[][MDB_CHARLEN_LONG])
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		int		nField;

		if (nTable < 0 || nTable >= BpaGetTableNum())
			return;

		for (i=0; i<MAXMDBFIELDNUM; i++)
			memset(szField[i], 0, MDB_CHARLEN_LONG);

		for (nField=0; nField<BpaGetTableFieldNum(nTable); nField++)
		{
			switch (BpaGetFieldType(nTable, nField))
			{
			case	MDB_STRING:
				for (i=0; i<(int)strlen(lpszDataPtr); i++)
					szField[nField][i]=(char)lpszDataPtr[i];
				szField[nField][i]='\0';
				break;
			case	MDB_DOUBLE:
				memcpy(&dBuf, lpszDataPtr, BpaGetFieldLen(nTable, nField));
				{
					std::stringstream os;
					os << dBuf;
					std::string sf = os.str();
					if (sf.find("e") == string::npos)
						strcpy(szField[nField], sf.c_str());
					else
						sprintf(szField[nField], "%lf", dBuf);
				}
				//sprintf(szField[nField], "%f", dBuf);
				break;
			case	MDB_FLOAT:
				memcpy(&fBuf, lpszDataPtr, BpaGetFieldLen(nTable, nField));
				{
					std::stringstream os;
					os << fBuf;
					std::string sf = os.str();
					if (sf.find("e") == string::npos)
						strcpy(szField[nField], sf.c_str());
					else
						sprintf(szField[nField], "%f", fBuf);
				}
				//sprintf(szField[nField], "%f", fBuf);
				break;
			case	MDB_INT:
				memcpy(&nBuf, lpszDataPtr, BpaGetFieldLen(nTable, nField));
				sprintf(szField[nField], "%d", nBuf);
				break;
			case	MDB_SHORT:
				memcpy(&sBuf, lpszDataPtr, BpaGetFieldLen(nTable, nField));
				sprintf(szField[nField], "%d", sBuf);
				break;
			case	MDB_BIT:
				memcpy(&uBuf, lpszDataPtr, BpaGetFieldLen(nTable, nField));
				sprintf(szField[nField], "%d", uBuf);
				break;
			case	MDB_CHAR:
				szField[nField][0]=(char)lpszDataPtr[0];
				break;
			}
			lpszDataPtr += BpaGetFieldLen(nTable, nField);
		}
	}

	void	BpaFieldArray2DataPtr(const int nTable, const char szField[][MDB_CHARLEN_LONG], char* lpszDataPtr)
	{
		register int	i;
		int		nField;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;
		char*	lpszAddr;

		if (nTable < 0 || nTable >= BpaGetTableNum())
			return;

		for (nField=0; nField<BpaGetTableFieldNum(nTable); nField++)
		{
			lpszAddr=lpszDataPtr;
			for (i=0; i<nField; i++)
				lpszAddr += BpaGetFieldLen(nTable, i);

			switch (BpaGetFieldType(nTable, nField))
			{
			case	MDB_STRING:
				for (i=0; i<(int)strlen(szField[nField]); i++)
					lpszAddr[i]=szField[nField][i];
				lpszAddr[i]='\0';
				break;
			case	MDB_DOUBLE:
				dBuf=atof(szField[nField]);
				memcpy(lpszAddr, &dBuf, sizeof(double));
				break;
			case	MDB_FLOAT:
				fBuf=StringToFloat(szField[nField]);
				memcpy(lpszAddr, &fBuf, sizeof(float));
				break;
			case	MDB_INT:
				nBuf=atoi(szField[nField]);
				memcpy(lpszAddr, &nBuf, sizeof(int));
				break;
			case	MDB_SHORT:
				sBuf=(short)atoi(szField[nField]);
				memcpy(lpszAddr, &sBuf, sizeof(short));
				break;
			case	MDB_BIT:
				uBuf=(unsigned char)atoi(szField[nField]);
				memcpy(lpszAddr, &uBuf, sizeof(unsigned char));
				break;
			case	MDB_CHAR:
				lpszAddr[0]=szField[nField][0];
				break;
			}
		}
	}

	void	BpaGetDataPtrFieldValue(const int nTable, const int nField, const char* lpszDataPtr, char* lpszRetValue)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;

		if (nTable < 0 || nTable >= BpaGetTableNum())
			return;

		if (nField < 0 || nField >= BpaGetTableFieldNum(nTable))
			return;

		int		nFieldPos=0;
		for (i=0; i<nField; i++)
			nFieldPos += BpaGetFieldLen(nTable, i);

		int		nFieldLen=BpaGetFieldLen(nTable, nField);
		switch (BpaGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			for (i=0; i<nFieldLen; i++)
			{
				if ((lpszDataPtr+nFieldPos)[i] == '\0')
					break;

				lpszRetValue[i]=(char)(lpszDataPtr+nFieldPos)[i];
			}
			lpszRetValue[i]='\0';
			break;
		case	MDB_DOUBLE:
			memcpy(&dBuf, lpszDataPtr+nFieldPos, nFieldLen);
			{
				std::stringstream os;
				os << dBuf;
				std::string sf = os.str();
				if (sf.find("e") == string::npos)
					strcpy(lpszRetValue, sf.c_str());
				else
					sprintf(lpszRetValue, "%lf", dBuf);
			}
			//sprintf(lpszRetValue, "%f", dBuf);
			break;
		case	MDB_FLOAT:
			memcpy(&fBuf, lpszDataPtr+nFieldPos, nFieldLen);
			{
				std::stringstream os;
				os << fBuf;
				std::string sf = os.str();
				if (sf.find("e") == string::npos)
					strcpy(lpszRetValue, sf.c_str());
				else
					sprintf(lpszRetValue, "%f", fBuf);
			}
			//sprintf(lpszRetValue, "%f", fBuf);
			break;
		case	MDB_INT:
			memcpy(&nBuf, lpszDataPtr+nFieldPos, nFieldLen);
			sprintf(lpszRetValue, "%d", nBuf);
			break;
		case	MDB_SHORT:
			memcpy(&sBuf, lpszDataPtr+nFieldPos, nFieldLen);
			sprintf(lpszRetValue, "%d", sBuf);
			break;
		case	MDB_BIT:
			memcpy(&uBuf, lpszDataPtr+nFieldPos, nFieldLen);
			sprintf(lpszRetValue, "%d", uBuf);
			break;
		case	MDB_CHAR:
			lpszRetValue[0]=(char)(lpszDataPtr+nFieldPos)[0];
			break;
		}
	}

	void	BpaSetDataPtrFieldValue(const int nTable, const int nField, const char* lpszFieldValue, char* lpszDataPtr)
	{
		register int	i;
		double	dBuf;
		float	fBuf;
		int		nBuf;
		short	sBuf;
		unsigned char	uBuf;

		if (nTable < 0 || nTable >= BpaGetTableNum())
			return;

		if (nField < 0 || nField >= BpaGetTableFieldNum(nTable))
			return;

		for (i=0; i<nField; i++)
			lpszDataPtr += BpaGetFieldLen(nTable, i);

		switch (BpaGetFieldType(nTable, nField))
		{
		case	MDB_STRING:
			for (i=0; i<(int)strlen(lpszFieldValue); i++)
				lpszDataPtr[i]=lpszFieldValue[i];
			lpszDataPtr[i]='\0';
			break;
		case	MDB_DOUBLE:
			//String2Double(dBuf, lpszFieldValue);
			dBuf=StringToFloat(lpszFieldValue);
			memcpy(lpszDataPtr, &dBuf, sizeof(double));
			break;
		case	MDB_FLOAT:
			//String2Double(fBuf, lpszFieldValue);
			fBuf=StringToFloat(lpszFieldValue);
			memcpy(lpszDataPtr, &fBuf, sizeof(float));
			break;
		case	MDB_INT:
			nBuf=atoi(lpszFieldValue);
			memcpy(lpszDataPtr, &nBuf, sizeof(int));
			break;
		case	MDB_SHORT:
			sBuf=(short)atoi(lpszFieldValue);
			memcpy(lpszDataPtr, &sBuf, sizeof(short));
			break;
		case	MDB_BIT:
			uBuf=(unsigned char)atoi(lpszFieldValue);
			memcpy(lpszDataPtr, &uBuf, sizeof(unsigned char));
			break;
		case	MDB_CHAR:
			lpszDataPtr[0]=lpszFieldValue[0];
			break;
		}
	}

	int	BpaFieldArray2LineString(const int nBpaTable, const int nDictIni, const char szField[][MDB_CHARLEN_LONG], char* lpszRetLine)
	{
		register int	i;
		int		nBpaField, nIni, nEnd, nDecimal, nDataLen;
		char	szValue[MDB_CHARLEN];

		if (nDictIni < 0)
			return 0;

		for (i=0; i<MDB_CHARLEN_LONG-1; i++)
			lpszRetLine[i]=' ';

		for (nBpaField=0; nBpaField<BpaGetTableFieldNum(nBpaTable); nBpaField++)
		{
			int	nDictField=BpaGetFieldDictIndex(nDictIni, BpaGetFieldName(nBpaTable, nBpaField));
			if (nDictField < 0)
				continue;
			nIni=		BpaGetDictFieldStart	(nDictField);
			nEnd=		BpaGetDictFieldEnd		(nDictField);
			nDataLen=	BpaGetDictFieldLen		(nDictField);
			nDecimal=	BpaGetDictFieldDecimal	(nDictField);
			if (nIni <= 0 || nDataLen <= 0)
				continue;

			strcpy(szValue, szField[nBpaField]);
			if (stricmp(BpaGetFieldName(nBpaTable, nBpaField), "CardKey") == 0)
			{
				strcpy(szValue, BpaGetDictCardKey(nDictField));
				BpaDictKey2BpaCardKey(szValue);
			}

			for (i=0; i<nDataLen; i++)
				lpszRetLine[i+nIni-1]=' ';
			switch (BpaGetFieldType(nBpaTable, nBpaField))
			{
			case MDB_DOUBLE:
			case MDB_FLOAT:
				if (fabs(atof(szValue)) > FLT_MIN)
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
							FormularBpaDecimalChar(szValue, nDataLen);
							for (i=0; i<strlen(szValue); i++)
								lpszRetLine[nEnd-1-i]=szValue[strlen(szValue)-1-i];
						}
					}
					else
					{
						FormularBpaDecimalChar(szValue, nDataLen);
						for (i=0; i<strlen(szValue); i++)
							lpszRetLine[nEnd-1-i]=szValue[strlen(szValue)-1-i];
// 						for (i=0; i<nDataLen; i++)
// 						{
// 							if (szValue[i] == ' ' || szValue[i] == '\t' || szValue[i] == '\n' || szValue[i] == '\r' || szValue[i] == '\0')
// 								break;
// 							lpszRetLine[i+nIni-1]=szValue[i];
// 						}
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

	int	BpaDataPtr2LineString(const int nBpaTable, const int nDictIni, const char* lpszDataPtr, char* lpszRetLine)
	{
		register int	i;
		char	szField[MAXMDBFIELDNUM][MDB_CHARLEN_LONG];
		for (i=0; i<MAXMDBFIELDNUM; i++)
			memset(szField[i], 0, MDB_CHARLEN_LONG);

		BpaDataPtr2FieldArray(nBpaTable, lpszDataPtr, szField);
		return BpaFieldArray2LineString(nBpaTable, nDictIni, szField, lpszRetLine);
	}

	int	BpaFieldArray2LineString(const int nBpaTable, const char szField[][MDB_CHARLEN_LONG], char* lpszRetMString, char* lpszRetEString, char* lpszRetAString)
	{
		register int	i;
		int		nComb, nDictIni, nKeyField;

		nKeyField=BpaGetFieldIndex(nBpaTable, "CardKey");
		if (nKeyField < 0)
			return 0;

		nComb=-1;
		for (i=0; i<sizeof(g_BpaCardCombArray)/sizeof(tagBpaCardComb); i++)
		{
			if (stricmp(g_BpaCardCombArray[i].szMainCard, szField[nKeyField]) == 0)
			{
				nComb=i;
				break;
			}
		}

		if (nComb < 0)
		{
			nDictIni=BpaGetTableDictIndex(szField[nKeyField], -1);
			if (nDictIni < 0)
				return 0;

			return BpaFieldArray2LineString(nBpaTable, nDictIni, szField, lpszRetMString);
		}
		else
		{
			if (strlen(g_BpaCardCombArray[nComb].szMainCard) > 0)
			{
				nDictIni=BpaGetTableDictIndex(g_BpaCardCombArray[nComb].szMainCard, g_BpaCardCombArray[nComb].nMainCate);
				BpaFieldArray2LineString(nBpaTable, nDictIni, szField, lpszRetMString);

				if (strlen(g_BpaCardCombArray[nComb].szExCard) > 0)
				{
					nDictIni=BpaGetTableDictIndex(g_BpaCardCombArray[nComb].szExCard, g_BpaCardCombArray[nComb].nExCate);
					BpaFieldArray2LineString(nBpaTable, nDictIni, szField, lpszRetEString);
				}

				if (strlen(g_BpaCardCombArray[nComb].szAugCard) > 0)
				{
					nDictIni=BpaGetTableDictIndex(g_BpaCardCombArray[nComb].szAugCard, g_BpaCardCombArray[nComb].nAugCate);
					BpaFieldArray2LineString(nBpaTable, nDictIni, szField, lpszRetAString);
				}
			}
		}
		return 1;
	}

	void BpaFormTableKeyField(const int nTable, char szField[][MDB_CHARLEN_LONG])
	{
		if (nTable == BPA_DAT_ACLINE)
		{
			if (szField[BPA_DAT_ACLINE_LOOP][0] != ' ' && szField[BPA_DAT_ACLINE_LOOP][0] != '\0')
			{
				sprintf(szField[BPA_DAT_ACLINE_KEYNAME], "%s%.0f-%s%.0f@%c",
					szField[BPA_DAT_ACLINE_BUSI], StringToFloat(szField[BPA_DAT_ACLINE_KVI]),
					szField[BPA_DAT_ACLINE_BUSJ], StringToFloat(szField[BPA_DAT_ACLINE_KVJ]),
					szField[BPA_DAT_ACLINE_LOOP][0]);
			}
			else
			{
				sprintf(szField[BPA_DAT_ACLINE_KEYNAME], "%s%.0f-%s%.0f",
					szField[BPA_DAT_ACLINE_BUSI], StringToFloat(szField[BPA_DAT_ACLINE_KVI]),
					szField[BPA_DAT_ACLINE_BUSJ], StringToFloat(szField[BPA_DAT_ACLINE_KVJ]));
			}
		}
		else if (nTable == BPA_DAT_WIND)
		{
			if (szField[BPA_DAT_WIND_LOOP][0] != ' ' && szField[BPA_DAT_WIND_LOOP][0] != '\0')
			{
				sprintf(szField[BPA_DAT_WIND_KEYNAME], "%s%.0f-%s%.0f@%c",
					szField[BPA_DAT_WIND_BUSI], StringToFloat(szField[BPA_DAT_WIND_KVI]),
					szField[BPA_DAT_WIND_BUSJ], StringToFloat(szField[BPA_DAT_WIND_KVJ]),
					szField[BPA_DAT_WIND_LOOP][0]);
			}
			else
			{
				sprintf(szField[BPA_DAT_WIND_KEYNAME], "%s%.0f-%s%.0f",
					szField[BPA_DAT_WIND_BUSI], StringToFloat(szField[BPA_DAT_WIND_KVI]),
					szField[BPA_DAT_WIND_BUSJ], StringToFloat(szField[BPA_DAT_WIND_KVJ]));
			}
		}
		else if (nTable == BPA_DAT_LINEHG)
		{
			if (szField[BPA_DAT_LINEHG_LOOP][0] != ' ' && szField[BPA_DAT_LINEHG_LOOP][0] != '\0')
			{
				sprintf(szField[BPA_DAT_LINEHG_KEYNAME], "%s%.0f-%s%.0f@%c",
					szField[BPA_DAT_LINEHG_BUSI], StringToFloat(szField[BPA_DAT_LINEHG_KVI]),
					szField[BPA_DAT_LINEHG_BUSJ], StringToFloat(szField[BPA_DAT_LINEHG_KVJ]),
					szField[BPA_DAT_LINEHG_LOOP][0]);
			}
			else
			{
				sprintf(szField[BPA_DAT_LINEHG_KEYNAME], "%s%.0f-%s%.0f",
					szField[BPA_DAT_LINEHG_BUSI], StringToFloat(szField[BPA_DAT_LINEHG_KVI]),
					szField[BPA_DAT_LINEHG_BUSJ], StringToFloat(szField[BPA_DAT_LINEHG_KVJ]));
			}
		}
		if (nTable == BPA_SWI_LO)
		{
			if (szField[BPA_SWI_LO_LOOP][0] != ' ' && szField[BPA_SWI_LO_LOOP][0] != '\0')
			{
				sprintf(szField[BPA_SWI_LO_KEYNAME], "%s%.0f-%s%.0f@%c",
					szField[BPA_SWI_LO_BUSI], StringToFloat(szField[BPA_SWI_LO_KVI]),
					szField[BPA_SWI_LO_BUSJ], StringToFloat(szField[BPA_SWI_LO_KVJ]),
					szField[BPA_SWI_LO_LOOP][0]);
			}
			else
			{
				sprintf(szField[BPA_SWI_LO_KEYNAME], "%s%.0f-%s%.0f",
					szField[BPA_SWI_LO_BUSI], StringToFloat(szField[BPA_SWI_LO_KVI]),
					szField[BPA_SWI_LO_BUSJ], StringToFloat(szField[BPA_SWI_LO_KVJ]));
			}
		}
		else if (nTable == BPA_SWI_XO)
		{
			if (szField[BPA_SWI_XO_LOOP][0] != ' ' && szField[BPA_SWI_XO_LOOP][0] != '\0')
			{
				sprintf(szField[BPA_SWI_XO_KEYNAME], "%s%.0f-%s%.0f@%c",
					szField[BPA_SWI_XO_BUSI], StringToFloat(szField[BPA_SWI_XO_KVI]),
					szField[BPA_SWI_XO_BUSJ], StringToFloat(szField[BPA_SWI_XO_KVJ]),
					szField[BPA_SWI_XO_LOOP][0]);
			}
			else
			{
				sprintf(szField[BPA_SWI_XO_KEYNAME], "%s%.0f-%s%.0f",
					szField[BPA_SWI_XO_BUSI], StringToFloat(szField[BPA_SWI_XO_KVI]),
					szField[BPA_SWI_XO_BUSJ], StringToFloat(szField[BPA_SWI_XO_KVJ]));
			}
		}
		else if (nTable == BPA_SWI_LOHG)
		{
			if (szField[BPA_SWI_LOHG_LOOP][0] != ' ' && szField[BPA_SWI_LOHG_LOOP][0] != '\0')
			{
				sprintf(szField[BPA_SWI_LOHG_KEYNAME], "%s%.0f-%s%.0f@%c",
					szField[BPA_SWI_LOHG_BUSI], StringToFloat(szField[BPA_SWI_LOHG_KVI]),
					szField[BPA_SWI_LOHG_BUSJ], StringToFloat(szField[BPA_SWI_LOHG_KVJ]),
					szField[BPA_SWI_LOHG_LOOP][0]);
			}
			else
			{
				sprintf(szField[BPA_SWI_LOHG_KEYNAME], "%s%.0f-%s%.0f",
					szField[BPA_SWI_LOHG_BUSI], StringToFloat(szField[BPA_SWI_LOHG_KVI]),
					szField[BPA_SWI_LOHG_BUSJ], StringToFloat(szField[BPA_SWI_LOHG_KVJ]));
			}
		}
		else if (nTable == BPA_DAT_DCLINE)
		{
			sprintf(szField[BPA_DAT_DCLINE_KEYNAME], "%s%.0f-%s%.0f",
				szField[BPA_DAT_DCLINE_BUSR], StringToFloat(szField[BPA_DAT_DCLINE_KVR]),
				szField[BPA_DAT_DCLINE_BUSI], StringToFloat(szField[BPA_DAT_DCLINE_KVI]));
		}
		else if (nTable == BPA_DAT_R)
		{
			sprintf(szField[BPA_DAT_R_KEYNAME], "%s%.0f-%s%.0f",
				szField[BPA_DAT_R_BUSI], StringToFloat(szField[BPA_DAT_R_KVI]),
				szField[BPA_DAT_R_BUSJ], StringToFloat(szField[BPA_DAT_R_KVJ]));
		}
		else if (nTable == BPA_DAT_RZ)
		{
			if (szField[BPA_DAT_RZ_LOOP][0] != ' ')
				sprintf(szField[BPA_DAT_RZ_KEYNAME], "%s%.0f-%s%.0f@%c",
				szField[BPA_DAT_RZ_BUSI], StringToFloat(szField[BPA_DAT_RZ_KVI]),
				szField[BPA_DAT_RZ_BUSJ], StringToFloat(szField[BPA_DAT_RZ_KVJ]),
				szField[BPA_DAT_RZ_LOOP][0]);
			else
				sprintf(szField[BPA_DAT_RZ_KEYNAME], "%s%.0f-%s%.0f",
				szField[BPA_DAT_RZ_BUSI], StringToFloat(szField[BPA_DAT_RZ_KVI]),
				szField[BPA_DAT_RZ_BUSJ], StringToFloat(szField[BPA_DAT_RZ_KVJ]));
		}
		else if (nTable == BPA_SWI_GEN)
		{
			if (szField[BPA_SWI_GEN_ID][0] != ' ' && szField[BPA_SWI_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GEN_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GEN_BUS_NAME], StringToFloat(szField[BPA_SWI_GEN_BUS_KV]), szField[BPA_SWI_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GEN_KEYNAME], "%s%.0f", szField[BPA_SWI_GEN_BUS_NAME], StringToFloat(szField[BPA_SWI_GEN_BUS_KV]));
		}
		else if (nTable == BPA_SWI_DAMP)
		{
			if (szField[BPA_SWI_DAMP_ID][0] != ' ' && szField[BPA_SWI_DAMP_ID][0] != '\0')
				sprintf(szField[BPA_SWI_DAMP_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_DAMP_BUS_NAME], StringToFloat(szField[BPA_SWI_DAMP_BUS_KV]), szField[BPA_SWI_DAMP_ID][0]);
			else
				sprintf(szField[BPA_SWI_DAMP_KEYNAME], "%s%.0f", szField[BPA_SWI_DAMP_BUS_NAME], StringToFloat(szField[BPA_SWI_DAMP_BUS_KV]));
		}
		else if (nTable == BPA_SWI_WGEGEN)
		{
			if (szField[BPA_SWI_WGEGEN_ID][0] != ' ' && szField[BPA_SWI_WGEGEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_WGEGEN_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_WGEGEN_BUS_NAME], StringToFloat(szField[BPA_SWI_WGEGEN_BUS_KV]), szField[BPA_SWI_WGEGEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_WGEGEN_KEYNAME], "%s%.0f", szField[BPA_SWI_WGEGEN_BUS_NAME], StringToFloat(szField[BPA_SWI_WGEGEN_BUS_KV]));
		}
		else if (nTable == BPA_SWI_EXCIT68)
		{
			if (szField[BPA_SWI_EXCIT68_GEN_ID][0] != ' ' && szField[BPA_SWI_EXCIT68_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_EXCIT68_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_EXCIT68_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCIT68_BUS_KV]), szField[BPA_SWI_EXCIT68_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_EXCIT68_KEYNAME], "%s%.0f", szField[BPA_SWI_EXCIT68_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCIT68_BUS_KV]));
		}
		else if (nTable == BPA_SWI_EXCIT81)
		{
			if (szField[BPA_SWI_EXCIT81_GEN_ID][0] != ' ' && szField[BPA_SWI_EXCIT81_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_EXCIT81_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_EXCIT81_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCIT81_BUS_KV]), szField[BPA_SWI_EXCIT81_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_EXCIT81_KEYNAME], "%s%.0f", szField[BPA_SWI_EXCIT81_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCIT81_BUS_KV]));
		}
		else if (nTable == BPA_SWI_EXCITMV)
		{
			if (szField[BPA_SWI_EXCITMV_GEN_ID][0] != ' ' && szField[BPA_SWI_EXCITMV_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_EXCITMV_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_EXCITMV_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITMV_BUS_KV]), szField[BPA_SWI_EXCITMV_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_EXCITMV_KEYNAME], "%s%.0f", szField[BPA_SWI_EXCITMV_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITMV_BUS_KV]));
		}
		else if (nTable == BPA_SWI_FZ)
		{
			if (szField[BPA_SWI_FZ_GEN_ID][0] != ' ' && szField[BPA_SWI_FZ_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_FZ_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_FZ_BUS_NAME], StringToFloat(szField[BPA_SWI_FZ_BUS_KV]), szField[BPA_SWI_FZ_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_FZ_KEYNAME], "%s%.0f", szField[BPA_SWI_FZ_BUS_NAME], StringToFloat(szField[BPA_SWI_FZ_BUS_KV]));
		}
		else if (nTable == BPA_SWI_FCA)
		{
			if (szField[BPA_SWI_FCA_GEN_ID][0] != ' ' && szField[BPA_SWI_FCA_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_FCA_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_FCA_BUS_NAME], StringToFloat(szField[BPA_SWI_FCA_BUS_KV]), szField[BPA_SWI_FCA_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_FCA_KEYNAME], "%s%.0f", szField[BPA_SWI_FCA_BUS_NAME], StringToFloat(szField[BPA_SWI_FCA_BUS_KV]));
		}
		else if (nTable == BPA_SWI_FCB)
		{
			if (szField[BPA_SWI_FCB_GEN_ID][0] != ' ' && szField[BPA_SWI_FCB_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_FCB_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_FCB_BUS_NAME], StringToFloat(szField[BPA_SWI_FCB_BUS_KV]), szField[BPA_SWI_FCB_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_FCB_KEYNAME], "%s%.0f", szField[BPA_SWI_FCB_BUS_NAME], StringToFloat(szField[BPA_SWI_FCB_BUS_KV]));
		}
		else if (nTable == BPA_SWI_EXCITX)
		{
			if (szField[BPA_SWI_EXCITX_GEN_ID][0] != ' ' && szField[BPA_SWI_EXCITX_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_EXCITX_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_EXCITX_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITX_BUS_KV]), szField[BPA_SWI_EXCITX_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_EXCITX_KEYNAME], "%s%.0f", szField[BPA_SWI_EXCITX_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITX_BUS_KV]));
		}
		else if (nTable == BPA_SWI_PSSS)
		{
			if (szField[BPA_SWI_PSSS_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSS_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_PSSS_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSS_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSS_BUS_KV]), szField[BPA_SWI_PSSS_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_PSSS_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSS_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSS_BUS_KV]));
		}
		else if (nTable == BPA_SWI_PSSSH)
		{
			if (szField[BPA_SWI_PSSSH_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSH_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_PSSSH_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSH_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSH_BUS_KV]), szField[BPA_SWI_PSSSH_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_PSSSH_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSH_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSH_BUS_KV]));
		}
		else if (nTable == BPA_SWI_PSSSI)
		{
			if (szField[BPA_SWI_PSSSI_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSI_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_PSSSI_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSI_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSI_BUS_KV]), szField[BPA_SWI_PSSSI_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_PSSSI_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSI_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSI_BUS_KV]));
		}
		else if (nTable == BPA_SWI_PSSSA)
		{
			if (szField[BPA_SWI_PSSSA_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSA_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_PSSSA_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSA_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSA_BUS_KV]), szField[BPA_SWI_PSSSA_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_PSSSA_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSA_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSA_BUS_KV]));
		}
		else if (nTable == BPA_SWI_PSSSB)
		{
			if (szField[BPA_SWI_PSSSB_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSB_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_PSSSB_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSB_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSB_BUS_KV]), szField[BPA_SWI_PSSSB_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_PSSSB_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSB_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSB_BUS_KV]));
		}
		else if (nTable == BPA_SWI_PSSST)
		{
			if (szField[BPA_SWI_PSSST_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSST_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_PSSST_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSST_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSST_BUS_KV]), szField[BPA_SWI_PSSST_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_PSSST_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSST_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSST_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GG)
		{
			if (szField[BPA_SWI_GG_GEN_ID][0] != ' ' && szField[BPA_SWI_GG_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GG_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GG_BUS_NAME], StringToFloat(szField[BPA_SWI_GG_BUS_KV]), szField[BPA_SWI_GG_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GG_KEYNAME], "%s%.0f", szField[BPA_SWI_GG_BUS_NAME], StringToFloat(szField[BPA_SWI_GG_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GH)
		{
			if (szField[BPA_SWI_GH_GEN_ID][0] != ' ' && szField[BPA_SWI_GH_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GH_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GH_BUS_NAME], StringToFloat(szField[BPA_SWI_GH_BUS_KV]), szField[BPA_SWI_GH_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GH_KEYNAME], "%s%.0f", szField[BPA_SWI_GH_BUS_NAME], StringToFloat(szField[BPA_SWI_GH_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GC)
		{
			if (szField[BPA_SWI_GC_GEN_ID][0] != ' ' && szField[BPA_SWI_GC_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GC_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GC_BUS_NAME], StringToFloat(szField[BPA_SWI_GC_BUS_KV]), szField[BPA_SWI_GC_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GC_KEYNAME], "%s%.0f", szField[BPA_SWI_GC_BUS_NAME], StringToFloat(szField[BPA_SWI_GC_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GS)
		{
			if (szField[BPA_SWI_GS_GEN_ID][0] != ' ' && szField[BPA_SWI_GS_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GS_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GS_BUS_NAME], StringToFloat(szField[BPA_SWI_GS_BUS_KV]), szField[BPA_SWI_GS_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GS_KEYNAME], "%s%.0f", szField[BPA_SWI_GS_BUS_NAME], StringToFloat(szField[BPA_SWI_GS_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GL)
		{
			if (szField[BPA_SWI_GL_GEN_ID][0] != ' ' && szField[BPA_SWI_GL_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GL_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GL_BUS_NAME], StringToFloat(szField[BPA_SWI_GL_BUS_KV]), szField[BPA_SWI_GL_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GL_KEYNAME], "%s%.0f", szField[BPA_SWI_GL_BUS_NAME], StringToFloat(szField[BPA_SWI_GL_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GW)
		{
			if (szField[BPA_SWI_GW_GEN_ID][0] != ' ' && szField[BPA_SWI_GW_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GW_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GW_BUS_NAME], StringToFloat(szField[BPA_SWI_GW_BUS_KV]), szField[BPA_SWI_GW_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GW_KEYNAME], "%s%.0f", szField[BPA_SWI_GW_BUS_NAME], StringToFloat(szField[BPA_SWI_GW_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GA)
		{
			if (szField[BPA_SWI_GA_GEN_ID][0] != ' ' && szField[BPA_SWI_GA_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GA_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GA_BUS_NAME], StringToFloat(szField[BPA_SWI_GA_BUS_KV]), szField[BPA_SWI_GA_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GA_KEYNAME], "%s%.0f", szField[BPA_SWI_GA_BUS_NAME], StringToFloat(szField[BPA_SWI_GA_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GI)
		{
			if (szField[BPA_SWI_GI_GEN_ID][0] != ' ' && szField[BPA_SWI_GI_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GI_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GI_BUS_NAME], StringToFloat(szField[BPA_SWI_GI_BUS_KV]), szField[BPA_SWI_GI_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GI_KEYNAME], "%s%.0f", szField[BPA_SWI_GI_BUS_NAME], StringToFloat(szField[BPA_SWI_GI_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GJ)
		{
			if (szField[BPA_SWI_GJ_GEN_ID][0] != ' ' && szField[BPA_SWI_GJ_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GJ_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GJ_BUS_NAME], StringToFloat(szField[BPA_SWI_GJ_BUS_KV]), szField[BPA_SWI_GJ_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GJ_KEYNAME], "%s%.0f", szField[BPA_SWI_GJ_BUS_NAME], StringToFloat(szField[BPA_SWI_GJ_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GK)
		{
			if (szField[BPA_SWI_GK_GEN_ID][0] != ' ' && szField[BPA_SWI_GK_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GK_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GK_BUS_NAME], StringToFloat(szField[BPA_SWI_GK_BUS_KV]), szField[BPA_SWI_GK_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GK_KEYNAME], "%s%.0f", szField[BPA_SWI_GK_BUS_NAME], StringToFloat(szField[BPA_SWI_GK_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GM)
		{
			if (szField[BPA_SWI_GM_GEN_ID][0] != ' ' && szField[BPA_SWI_GM_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GM_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GM_BUS_NAME], StringToFloat(szField[BPA_SWI_GM_BUS_KV]), szField[BPA_SWI_GM_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GM_KEYNAME], "%s%.0f", szField[BPA_SWI_GM_BUS_NAME], StringToFloat(szField[BPA_SWI_GM_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GD)
		{
			if (szField[BPA_SWI_GD_GEN_ID][0] != ' ' && szField[BPA_SWI_GD_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GD_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GD_BUS_NAME], StringToFloat(szField[BPA_SWI_GD_BUS_KV]), szField[BPA_SWI_GD_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GD_KEYNAME], "%s%.0f", szField[BPA_SWI_GD_BUS_NAME], StringToFloat(szField[BPA_SWI_GD_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GZ)
		{
			if (szField[BPA_SWI_GZ_GEN_ID][0] != ' ' && szField[BPA_SWI_GZ_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GZ_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GZ_BUS_NAME], StringToFloat(szField[BPA_SWI_GZ_BUS_KV]), szField[BPA_SWI_GZ_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GZ_KEYNAME], "%s%.0f", szField[BPA_SWI_GZ_BUS_NAME], StringToFloat(szField[BPA_SWI_GZ_BUS_KV]));
		}
		else if (nTable == BPA_SWI_TA)
		{
			if (szField[BPA_SWI_TA_GEN_ID][0] != ' ' && szField[BPA_SWI_TA_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_TA_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TA_BUS_NAME], StringToFloat(szField[BPA_SWI_TA_BUS_KV]), szField[BPA_SWI_TA_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_TA_KEYNAME], "%s%.0f", szField[BPA_SWI_TA_BUS_NAME], StringToFloat(szField[BPA_SWI_TA_BUS_KV]));
		}
		else if (nTable == BPA_SWI_TB)
		{
			if (szField[BPA_SWI_TB_GEN_ID][0] != ' ' && szField[BPA_SWI_TB_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_TB_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TB_BUS_NAME], StringToFloat(szField[BPA_SWI_TB_BUS_KV]), szField[BPA_SWI_TB_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_TB_KEYNAME], "%s%.0f", szField[BPA_SWI_TB_BUS_NAME], StringToFloat(szField[BPA_SWI_TB_BUS_KV]));
		}
		else if (nTable == BPA_SWI_TC)
		{
			if (szField[BPA_SWI_TC_GEN_ID][0] != ' ' && szField[BPA_SWI_TC_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_TC_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TC_BUS_NAME], StringToFloat(szField[BPA_SWI_TC_BUS_KV]), szField[BPA_SWI_TC_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_TC_KEYNAME], "%s%.0f", szField[BPA_SWI_TC_BUS_NAME], StringToFloat(szField[BPA_SWI_TC_BUS_KV]));
		}
		else if (nTable == BPA_SWI_TD)
		{
			if (szField[BPA_SWI_TD_GEN_ID][0] != ' ' && szField[BPA_SWI_TD_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_TD_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TD_BUS_NAME], StringToFloat(szField[BPA_SWI_TD_BUS_KV]), szField[BPA_SWI_TD_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_TD_KEYNAME], "%s%.0f", szField[BPA_SWI_TD_BUS_NAME], StringToFloat(szField[BPA_SWI_TD_BUS_KV]));
		}
		else if (nTable == BPA_SWI_TE)
		{
			if (szField[BPA_SWI_TE_GEN_ID][0] != ' ' && szField[BPA_SWI_TE_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_TE_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TE_BUS_NAME], StringToFloat(szField[BPA_SWI_TE_BUS_KV]), szField[BPA_SWI_TE_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_TE_KEYNAME], "%s%.0f", szField[BPA_SWI_TE_BUS_NAME], StringToFloat(szField[BPA_SWI_TE_BUS_KV]));
		}
		else if (nTable == BPA_SWI_TF)
		{
			if (szField[BPA_SWI_TF_GEN_ID][0] != ' ' && szField[BPA_SWI_TF_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_TF_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TF_BUS_NAME], StringToFloat(szField[BPA_SWI_TF_BUS_KV]), szField[BPA_SWI_TF_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_TF_KEYNAME], "%s%.0f", szField[BPA_SWI_TF_BUS_NAME], StringToFloat(szField[BPA_SWI_TF_BUS_KV]));
		}
		else if (nTable == BPA_SWI_TW)
		{
			if (szField[BPA_SWI_TW_GEN_ID][0] != ' ' && szField[BPA_SWI_TW_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_TW_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TW_BUS_NAME], StringToFloat(szField[BPA_SWI_TW_BUS_KV]), szField[BPA_SWI_TW_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_TW_KEYNAME], "%s%.0f", szField[BPA_SWI_TW_BUS_NAME], StringToFloat(szField[BPA_SWI_TW_BUS_KV]));
		}
		else if (nTable == BPA_SWI_GX)
		{
			if (szField[BPA_SWI_GX_GEN_ID][0] != ' ' && szField[BPA_SWI_GX_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_GX_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GX_BUS_NAME], StringToFloat(szField[BPA_SWI_GX_BUS_KV]), szField[BPA_SWI_GX_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_GX_KEYNAME], "%s%.0f", szField[BPA_SWI_GX_BUS_NAME], StringToFloat(szField[BPA_SWI_GX_BUS_KV]));
		}
		else if (nTable == BPA_SWI_IGV)
		{
			if (szField[BPA_SWI_IGV_GEN_ID][0] != ' ' && szField[BPA_SWI_IGV_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_IGV_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_IGV_BUS_NAME], StringToFloat(szField[BPA_SWI_IGV_BUS_KV]), szField[BPA_SWI_IGV_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_IGV_KEYNAME], "%s%.0f", szField[BPA_SWI_IGV_BUS_NAME], StringToFloat(szField[BPA_SWI_IGV_BUS_KV]));
		}
		else if (nTable == BPA_SWI_FGV)
		{
			if (szField[BPA_SWI_FGV_GEN_ID][0] != ' ' && szField[BPA_SWI_FGV_GEN_ID][0] != '\0')
				sprintf(szField[BPA_SWI_FGV_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_FGV_BUS_NAME], StringToFloat(szField[BPA_SWI_FGV_BUS_KV]), szField[BPA_SWI_FGV_GEN_ID][0]);
			else
				sprintf(szField[BPA_SWI_FGV_KEYNAME], "%s%.0f", szField[BPA_SWI_FGV_BUS_NAME], StringToFloat(szField[BPA_SWI_FGV_BUS_KV]));
		}
		else if (nTable == BPA_SWI_D)
		{
			sprintf(szField[BPA_SWI_D_KEYNAME], "%s%.0f", szField[BPA_SWI_D_BUS_NAME], StringToFloat(szField[BPA_SWI_D_BUS_KV]));
		}
		else if (nTable == BPA_SWI_V)
		{
			if (atoi(szField[BPA_SWI_V_ID]) != 0)
				sprintf(szField[BPA_SWI_V_KEYNAME], "%s%.0f@%d", szField[BPA_SWI_V_BUS_NAME], StringToFloat(szField[BPA_SWI_V_BUS_KV]), atoi(szField[BPA_SWI_V_ID]));
			else
				sprintf(szField[BPA_SWI_V_KEYNAME], "%s%.0f", szField[BPA_SWI_V_BUS_NAME], StringToFloat(szField[BPA_SWI_V_BUS_KV]));
		}
		else if (nTable == BPA_SWI_VG)
		{
			sprintf(szField[BPA_SWI_VG_KEYNAME], "%s%.0f", szField[BPA_SWI_VG_BUS_NAME], StringToFloat(szField[BPA_SWI_VG_BUS_KV]));
		}
// 		else if (nTable == BPA_SWI_LM)
// 		{
// 			sprintf(szField[BPA_SWI_LM_KEYNAME], "%s%.0f-%s%.0f",
// 				szField[BPA_SWI_LM_BUS1_I],
// 				StringToFloat(szField[BPA_SWI_LM_KV1_I]),
// 				szField[BPA_SWI_LM_BUS1_J],
// 				StringToFloat(szField[BPA_SWI_LM_KV1_J]));
// 		}
	}

	void BpaFormTableKeyField(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord)
	{
		if (nTable == BPA_DAT_ACLINE)
		{
			memset(pBpaBlock->m_BpaDat_ACLineArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_DAT_ACLINE_KEYNAME));
			if (pBpaBlock->m_BpaDat_ACLineArray[nRecord].cLoop != ' ' && pBpaBlock->m_BpaDat_ACLineArray[nRecord].cLoop != '\0')
			{
				sprintf(pBpaBlock->m_BpaDat_ACLineArray[nRecord].szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaDat_ACLineArray[nRecord].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_ACLineArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nRecord].fkVJ,
					pBpaBlock->m_BpaDat_ACLineArray[nRecord].cLoop);
			}
			else
			{
				sprintf(pBpaBlock->m_BpaDat_ACLineArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_ACLineArray[nRecord].szBusI, pBpaBlock->m_BpaDat_ACLineArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_ACLineArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_ACLineArray[nRecord].fkVJ);
			}
		}
		else if (nTable == BPA_DAT_WIND)
		{
			memset(pBpaBlock->m_BpaDat_WindArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_DAT_WIND_KEYNAME));
			if (pBpaBlock->m_BpaDat_WindArray[nRecord].cLoop != ' ' && pBpaBlock->m_BpaDat_WindArray[nRecord].cLoop != '\0')
			{
				sprintf(pBpaBlock->m_BpaDat_WindArray[nRecord].szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaDat_WindArray[nRecord].szBusI, pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_WindArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ,
					pBpaBlock->m_BpaDat_WindArray[nRecord].cLoop);
			}
			else
			{
				sprintf(pBpaBlock->m_BpaDat_WindArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_WindArray[nRecord].szBusI, pBpaBlock->m_BpaDat_WindArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_WindArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_WindArray[nRecord].fkVJ);
			}
		}
		else if (nTable == BPA_DAT_LINEHG)
		{
			memset(pBpaBlock->m_BpaDat_LineHGArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_DAT_LINEHG_KEYNAME));
			if (pBpaBlock->m_BpaDat_LineHGArray[nRecord].cLoop != ' ' && pBpaBlock->m_BpaDat_LineHGArray[nRecord].cLoop != '\0')
			{
				sprintf(pBpaBlock->m_BpaDat_LineHGArray[nRecord].szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaDat_LineHGArray[nRecord].szBusI, pBpaBlock->m_BpaDat_LineHGArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_LineHGArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_LineHGArray[nRecord].fkVJ,
					pBpaBlock->m_BpaDat_LineHGArray[nRecord].cLoop);
			}
			else
			{
				sprintf(pBpaBlock->m_BpaDat_LineHGArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_LineHGArray[nRecord].szBusI, pBpaBlock->m_BpaDat_LineHGArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_LineHGArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_LineHGArray[nRecord].fkVJ);
			}
		}
		else if (nTable == BPA_SWI_LO)
		{
			memset(pBpaBlock->m_BpaSwi_LOArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_SWI_LO_KEYNAME));
			if (pBpaBlock->m_BpaSwi_LOArray[nRecord].cLoop != ' ' && pBpaBlock->m_BpaSwi_LOArray[nRecord].cLoop != '\0')
			{
				sprintf(pBpaBlock->m_BpaSwi_LOArray[nRecord].szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaSwi_LOArray[nRecord].szBusI, pBpaBlock->m_BpaSwi_LOArray[nRecord].fkVI,
					pBpaBlock->m_BpaSwi_LOArray[nRecord].szBusJ, pBpaBlock->m_BpaSwi_LOArray[nRecord].fkVJ,
					pBpaBlock->m_BpaSwi_LOArray[nRecord].cLoop);
			}
			else
			{
				sprintf(pBpaBlock->m_BpaSwi_LOArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaSwi_LOArray[nRecord].szBusI, pBpaBlock->m_BpaSwi_LOArray[nRecord].fkVI,
					pBpaBlock->m_BpaSwi_LOArray[nRecord].szBusJ, pBpaBlock->m_BpaSwi_LOArray[nRecord].fkVJ);
			}
		}
		else if (nTable == BPA_SWI_XO)
		{
			memset(pBpaBlock->m_BpaSwi_XOArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_SWI_XO_KEYNAME));
			if (pBpaBlock->m_BpaSwi_XOArray[nRecord].cLoop != ' ' && pBpaBlock->m_BpaSwi_XOArray[nRecord].cLoop != '\0')
			{
				sprintf(pBpaBlock->m_BpaSwi_XOArray[nRecord].szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaSwi_XOArray[nRecord].szBusI, pBpaBlock->m_BpaSwi_XOArray[nRecord].fkVI,
					pBpaBlock->m_BpaSwi_XOArray[nRecord].szBusJ, pBpaBlock->m_BpaSwi_XOArray[nRecord].fkVJ,
					pBpaBlock->m_BpaSwi_XOArray[nRecord].cLoop);
			}
			else
			{
				sprintf(pBpaBlock->m_BpaSwi_XOArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaSwi_XOArray[nRecord].szBusI, pBpaBlock->m_BpaSwi_XOArray[nRecord].fkVI,
					pBpaBlock->m_BpaSwi_XOArray[nRecord].szBusJ, pBpaBlock->m_BpaSwi_XOArray[nRecord].fkVJ);
			}
		}
		else if (nTable == BPA_SWI_LOHG)
		{
			memset(pBpaBlock->m_BpaSwi_LOHGArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_SWI_LOHG_KEYNAME));
			if (pBpaBlock->m_BpaSwi_LOHGArray[nRecord].cLoop != ' ' && pBpaBlock->m_BpaSwi_LOHGArray[nRecord].cLoop != '\0')
			{
				sprintf(pBpaBlock->m_BpaSwi_LOHGArray[nRecord].szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaSwi_LOHGArray[nRecord].szBusI, pBpaBlock->m_BpaSwi_LOHGArray[nRecord].fkVI,
					pBpaBlock->m_BpaSwi_LOHGArray[nRecord].szBusJ, pBpaBlock->m_BpaSwi_LOHGArray[nRecord].fkVJ,
					pBpaBlock->m_BpaSwi_LOHGArray[nRecord].cLoop);
			}
			else
			{
				sprintf(pBpaBlock->m_BpaSwi_LOHGArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaSwi_LOHGArray[nRecord].szBusI, pBpaBlock->m_BpaSwi_LOHGArray[nRecord].fkVI,
					pBpaBlock->m_BpaSwi_LOHGArray[nRecord].szBusJ, pBpaBlock->m_BpaSwi_LOHGArray[nRecord].fkVJ);
			}
		}
		else if (nTable == BPA_DAT_DCLINE)
		{
			memset(pBpaBlock->m_BpaDat_DCLineArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_DAT_DCLINE_KEYNAME));
			sprintf(pBpaBlock->m_BpaDat_DCLineArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
				pBpaBlock->m_BpaDat_DCLineArray[nRecord].szBusR, pBpaBlock->m_BpaDat_DCLineArray[nRecord].fkVR,
				pBpaBlock->m_BpaDat_DCLineArray[nRecord].szBusI, pBpaBlock->m_BpaDat_DCLineArray[nRecord].fkVI);
		}
		else if (nTable == BPA_DAT_R)
		{
			memset(pBpaBlock->m_BpaDat_RArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_DAT_R_KEYNAME));
			sprintf(pBpaBlock->m_BpaDat_RArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
				pBpaBlock->m_BpaDat_RArray[nRecord].szBusI, pBpaBlock->m_BpaDat_RArray[nRecord].fkVI,
				pBpaBlock->m_BpaDat_RArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_RArray[nRecord].fkVJ);
		}
		else if (nTable == BPA_DAT_RZ)
		{
			memset(pBpaBlock->m_BpaDat_RZArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_DAT_RZ_KEYNAME));
			if (pBpaBlock->m_BpaDat_RZArray[nRecord].cLoop != ' ')
			{
				sprintf(pBpaBlock->m_BpaDat_RZArray[nRecord].szKeyName, "%s%.0f-%s%.0f@%c",
					pBpaBlock->m_BpaDat_RZArray[nRecord].szBusI, pBpaBlock->m_BpaDat_RZArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_RZArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_RZArray[nRecord].fkVJ,
					pBpaBlock->m_BpaDat_RZArray[nRecord].cLoop);
			}
			else
			{
				sprintf(pBpaBlock->m_BpaDat_RZArray[nRecord].szKeyName, "%s%.0f-%s%.0f",
					pBpaBlock->m_BpaDat_RZArray[nRecord].szBusI, pBpaBlock->m_BpaDat_RZArray[nRecord].fkVI,
					pBpaBlock->m_BpaDat_RZArray[nRecord].szBusJ, pBpaBlock->m_BpaDat_RZArray[nRecord].fkVJ);
			}
		}
		else if (nTable == BPA_SWI_GEN)
		{
			memset(pBpaBlock->m_BpaSwi_GenArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_SWI_GEN_KEYNAME));
			if (pBpaBlock->m_BpaSwi_GenArray[nRecord].cID != ' ' && pBpaBlock->m_BpaSwi_GenArray[nRecord].cID != '\0')
				sprintf(pBpaBlock->m_BpaSwi_GenArray[nRecord].szKeyName, "%s%.0f@%c", pBpaBlock->m_BpaSwi_GenArray[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_GenArray[nRecord].fBus_kV, pBpaBlock->m_BpaSwi_GenArray[nRecord].cID);
			else
				sprintf(pBpaBlock->m_BpaSwi_GenArray[nRecord].szKeyName, "%s%.0f", pBpaBlock->m_BpaSwi_GenArray[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_GenArray[nRecord].fBus_kV);
		}
		else if (nTable == BPA_SWI_DAMP)
		{
			memset(pBpaBlock->m_BpaSwi_DampArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_SWI_DAMP_KEYNAME));
			if (pBpaBlock->m_BpaSwi_DampArray[nRecord].cID != ' ' && pBpaBlock->m_BpaSwi_DampArray[nRecord].cID != '\0')
				sprintf(pBpaBlock->m_BpaSwi_DampArray[nRecord].szKeyName, "%s%.0f@%c", pBpaBlock->m_BpaSwi_DampArray[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_DampArray[nRecord].fBus_kV, pBpaBlock->m_BpaSwi_DampArray[nRecord].cID);
			else
				sprintf(pBpaBlock->m_BpaSwi_DampArray[nRecord].szKeyName, "%s%.0f", pBpaBlock->m_BpaSwi_DampArray[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_DampArray[nRecord].fBus_kV);
		}
		else if (nTable == BPA_SWI_WGEGEN)
		{
			memset(pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_SWI_WGEGEN_KEYNAME));
			if (pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].cID != ' ' && pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].cID != '\0')
				sprintf(pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].szKeyName, "%s%.0f@%c", pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].fBus_kV, pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].cID);
			else
				sprintf(pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].szKeyName, "%s%.0f", pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_WGEGenArray[nRecord].fBus_kV);
		}
		else if (nTable == BPA_SWI_EXCIT68)
		{
			memset(pBpaBlock->m_BpaSwi_Exc68Array[nRecord].szKeyName, 0, BpaGetFieldLen(nTable, BPA_SWI_EXCIT68_KEYNAME));
			if (pBpaBlock->m_BpaSwi_Exc68Array[nRecord].cGen_ID != ' ' && pBpaBlock->m_BpaSwi_Exc68Array[nRecord].cGen_ID != '\0')
				sprintf(pBpaBlock->m_BpaSwi_Exc68Array[nRecord].szKeyName, "%s%.0f@%c", pBpaBlock->m_BpaSwi_Exc68Array[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_Exc68Array[nRecord].fBus_kV, pBpaBlock->m_BpaSwi_Exc68Array[nRecord].cGen_ID);
			else
				sprintf(pBpaBlock->m_BpaSwi_Exc68Array[nRecord].szKeyName, "%s%.0f", pBpaBlock->m_BpaSwi_Exc68Array[nRecord].szBus_Name, pBpaBlock->m_BpaSwi_Exc68Array[nRecord].fBus_kV);
		}
// 		else if (nTable == BPA_SWI_EXCIT81)
// 		{
// 			if (szField[BPA_SWI_EXCIT81_GEN_ID][0] != ' ' && szField[BPA_SWI_EXCIT81_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_EXCIT81_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_EXCIT81_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCIT81_BUS_KV]), szField[BPA_SWI_EXCIT81_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_EXCIT81_KEYNAME], "%s%.0f", szField[BPA_SWI_EXCIT81_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCIT81_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_EXCITMV)
// 		{
// 			if (szField[BPA_SWI_EXCITMV_GEN_ID][0] != ' ' && szField[BPA_SWI_EXCITMV_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_EXCITMV_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_EXCITMV_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITMV_BUS_KV]), szField[BPA_SWI_EXCITMV_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_EXCITMV_KEYNAME], "%s%.0f", szField[BPA_SWI_EXCITMV_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITMV_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_EXCITX)
// 		{
// 			if (szField[BPA_SWI_EXCITX_GEN_ID][0] != ' ' && szField[BPA_SWI_EXCITX_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_EXCITX_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_EXCITX_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITX_BUS_KV]), szField[BPA_SWI_EXCITX_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_EXCITX_KEYNAME], "%s%.0f", szField[BPA_SWI_EXCITX_BUS_NAME], StringToFloat(szField[BPA_SWI_EXCITX_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_PSSS)
// 		{
// 			if (szField[BPA_SWI_PSSS_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSS_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_PSSS_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSS_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSS_BUS_KV]), szField[BPA_SWI_PSSS_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_PSSS_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSS_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSS_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_PSSSH1)
// 		{
// 			if (szField[BPA_SWI_PSSSH1_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSH1_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_PSSSH1_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSH1_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSH1_BUS_KV]), szField[BPA_SWI_PSSSH1_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_PSSSH1_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSH1_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSH1_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_PSSSH2)
// 		{
// 			if (szField[BPA_SWI_PSSSH2_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSH2_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_PSSSH2_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSH2_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSH2_BUS_KV]), szField[BPA_SWI_PSSSH2_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_PSSSH2_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSH2_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSH2_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_PSSSI)
// 		{
// 			if (szField[BPA_SWI_PSSSI_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSI_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_PSSSI_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSI_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSI_BUS_KV]), szField[BPA_SWI_PSSSI_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_PSSSI_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSI_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSI_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_PSSSA)
// 		{
// 			if (szField[BPA_SWI_PSSSA_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSA_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_PSSSA_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSA_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSA_BUS_KV]), szField[BPA_SWI_PSSSA_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_PSSSA_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSA_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSA_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_PSSSB)
// 		{
// 			if (szField[BPA_SWI_PSSSB_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSSB_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_PSSSB_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSSB_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSB_BUS_KV]), szField[BPA_SWI_PSSSB_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_PSSSB_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSSB_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSSB_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_PSSST)
// 		{
// 			if (szField[BPA_SWI_PSSST_GEN_ID][0] != ' ' && szField[BPA_SWI_PSSST_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_PSSST_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_PSSST_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSST_BUS_KV]), szField[BPA_SWI_PSSST_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_PSSST_KEYNAME], "%s%.0f", szField[BPA_SWI_PSSST_BUS_NAME], StringToFloat(szField[BPA_SWI_PSSST_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GG)
// 		{
// 			if (szField[BPA_SWI_GG_GEN_ID][0] != ' ' && szField[BPA_SWI_GG_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GG_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GG_BUS_NAME], StringToFloat(szField[BPA_SWI_GG_BUS_KV]), szField[BPA_SWI_GG_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GG_KEYNAME], "%s%.0f", szField[BPA_SWI_GG_BUS_NAME], StringToFloat(szField[BPA_SWI_GG_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GH)
// 		{
// 			if (szField[BPA_SWI_GH_GEN_ID][0] != ' ' && szField[BPA_SWI_GH_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GH_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GH_BUS_NAME], StringToFloat(szField[BPA_SWI_GH_BUS_KV]), szField[BPA_SWI_GH_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GH_KEYNAME], "%s%.0f", szField[BPA_SWI_GH_BUS_NAME], StringToFloat(szField[BPA_SWI_GH_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GC)
// 		{
// 			if (szField[BPA_SWI_GC_GEN_ID][0] != ' ' && szField[BPA_SWI_GC_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GC_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GC_BUS_NAME], StringToFloat(szField[BPA_SWI_GC_BUS_KV]), szField[BPA_SWI_GC_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GC_KEYNAME], "%s%.0f", szField[BPA_SWI_GC_BUS_NAME], StringToFloat(szField[BPA_SWI_GC_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GS)
// 		{
// 			if (szField[BPA_SWI_GS_GEN_ID][0] != ' ' && szField[BPA_SWI_GS_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GS_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GS_BUS_NAME], StringToFloat(szField[BPA_SWI_GS_BUS_KV]), szField[BPA_SWI_GS_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GS_KEYNAME], "%s%.0f", szField[BPA_SWI_GS_BUS_NAME], StringToFloat(szField[BPA_SWI_GS_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GL)
// 		{
// 			if (szField[BPA_SWI_GL_GEN_ID][0] != ' ' && szField[BPA_SWI_GL_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GL_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GL_BUS_NAME], StringToFloat(szField[BPA_SWI_GL_BUS_KV]), szField[BPA_SWI_GL_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GL_KEYNAME], "%s%.0f", szField[BPA_SWI_GL_BUS_NAME], StringToFloat(szField[BPA_SWI_GL_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GW)
// 		{
// 			if (szField[BPA_SWI_GW_GEN_ID][0] != ' ' && szField[BPA_SWI_GW_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GW_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GW_BUS_NAME], StringToFloat(szField[BPA_SWI_GW_BUS_KV]), szField[BPA_SWI_GW_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GW_KEYNAME], "%s%.0f", szField[BPA_SWI_GW_BUS_NAME], StringToFloat(szField[BPA_SWI_GW_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GA)
// 		{
// 			if (szField[BPA_SWI_GA_GEN_ID][0] != ' ' && szField[BPA_SWI_GA_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GA_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GA_BUS_NAME], StringToFloat(szField[BPA_SWI_GA_BUS_KV]), szField[BPA_SWI_GA_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GA_KEYNAME], "%s%.0f", szField[BPA_SWI_GA_BUS_NAME], StringToFloat(szField[BPA_SWI_GA_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GI)
// 		{
// 			if (szField[BPA_SWI_GI_GEN_ID][0] != ' ' && szField[BPA_SWI_GI_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GI_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GI_BUS_NAME], StringToFloat(szField[BPA_SWI_GI_BUS_KV]), szField[BPA_SWI_GI_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GI_KEYNAME], "%s%.0f", szField[BPA_SWI_GI_BUS_NAME], StringToFloat(szField[BPA_SWI_GI_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GJ)
// 		{
// 			if (szField[BPA_SWI_GJ_GEN_ID][0] != ' ' && szField[BPA_SWI_GJ_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GJ_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GJ_BUS_NAME], StringToFloat(szField[BPA_SWI_GJ_BUS_KV]), szField[BPA_SWI_GJ_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GJ_KEYNAME], "%s%.0f", szField[BPA_SWI_GJ_BUS_NAME], StringToFloat(szField[BPA_SWI_GJ_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GK)
// 		{
// 			if (szField[BPA_SWI_GK_GEN_ID][0] != ' ' && szField[BPA_SWI_GK_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GK_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GK_BUS_NAME], StringToFloat(szField[BPA_SWI_GK_BUS_KV]), szField[BPA_SWI_GK_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GK_KEYNAME], "%s%.0f", szField[BPA_SWI_GK_BUS_NAME], StringToFloat(szField[BPA_SWI_GK_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GM)
// 		{
// 			if (szField[BPA_SWI_GM_GEN_ID][0] != ' ' && szField[BPA_SWI_GM_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GM_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GM_BUS_NAME], StringToFloat(szField[BPA_SWI_GM_BUS_KV]), szField[BPA_SWI_GM_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GM_KEYNAME], "%s%.0f", szField[BPA_SWI_GM_BUS_NAME], StringToFloat(szField[BPA_SWI_GM_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GD)
// 		{
// 			if (szField[BPA_SWI_GD_GEN_ID][0] != ' ' && szField[BPA_SWI_GD_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GD_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GD_BUS_NAME], StringToFloat(szField[BPA_SWI_GD_BUS_KV]), szField[BPA_SWI_GD_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GD_KEYNAME], "%s%.0f", szField[BPA_SWI_GD_BUS_NAME], StringToFloat(szField[BPA_SWI_GD_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GZ)
// 		{
// 			if (szField[BPA_SWI_GZ_GEN_ID][0] != ' ' && szField[BPA_SWI_GZ_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GZ_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GZ_BUS_NAME], StringToFloat(szField[BPA_SWI_GZ_BUS_KV]), szField[BPA_SWI_GZ_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GZ_KEYNAME], "%s%.0f", szField[BPA_SWI_GZ_BUS_NAME], StringToFloat(szField[BPA_SWI_GZ_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_TA)
// 		{
// 			if (szField[BPA_SWI_TA_GEN_ID][0] != ' ' && szField[BPA_SWI_TA_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_TA_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TA_BUS_NAME], StringToFloat(szField[BPA_SWI_TA_BUS_KV]), szField[BPA_SWI_TA_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_TA_KEYNAME], "%s%.0f", szField[BPA_SWI_TA_BUS_NAME], StringToFloat(szField[BPA_SWI_TA_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_TB)
// 		{
// 			if (szField[BPA_SWI_TB_GEN_ID][0] != ' ' && szField[BPA_SWI_TB_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_TB_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TB_BUS_NAME], StringToFloat(szField[BPA_SWI_TB_BUS_KV]), szField[BPA_SWI_TB_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_TB_KEYNAME], "%s%.0f", szField[BPA_SWI_TB_BUS_NAME], StringToFloat(szField[BPA_SWI_TB_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_TC)
// 		{
// 			if (szField[BPA_SWI_TC_GEN_ID][0] != ' ' && szField[BPA_SWI_TC_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_TC_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TC_BUS_NAME], StringToFloat(szField[BPA_SWI_TC_BUS_KV]), szField[BPA_SWI_TC_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_TC_KEYNAME], "%s%.0f", szField[BPA_SWI_TC_BUS_NAME], StringToFloat(szField[BPA_SWI_TC_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_TD)
// 		{
// 			if (szField[BPA_SWI_TD_GEN_ID][0] != ' ' && szField[BPA_SWI_TD_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_TD_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TD_BUS_NAME], StringToFloat(szField[BPA_SWI_TD_BUS_KV]), szField[BPA_SWI_TD_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_TD_KEYNAME], "%s%.0f", szField[BPA_SWI_TD_BUS_NAME], StringToFloat(szField[BPA_SWI_TD_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_TE)
// 		{
// 			if (szField[BPA_SWI_TE_GEN_ID][0] != ' ' && szField[BPA_SWI_TE_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_TE_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TE_BUS_NAME], StringToFloat(szField[BPA_SWI_TE_BUS_KV]), szField[BPA_SWI_TE_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_TE_KEYNAME], "%s%.0f", szField[BPA_SWI_TE_BUS_NAME], StringToFloat(szField[BPA_SWI_TE_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_TF)
// 		{
// 			if (szField[BPA_SWI_TF_GEN_ID][0] != ' ' && szField[BPA_SWI_TF_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_TF_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TF_BUS_NAME], StringToFloat(szField[BPA_SWI_TF_BUS_KV]), szField[BPA_SWI_TF_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_TF_KEYNAME], "%s%.0f", szField[BPA_SWI_TF_BUS_NAME], StringToFloat(szField[BPA_SWI_TF_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_TW)
// 		{
// 			if (szField[BPA_SWI_TW_GEN_ID][0] != ' ' && szField[BPA_SWI_TW_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_TW_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_TW_BUS_NAME], StringToFloat(szField[BPA_SWI_TW_BUS_KV]), szField[BPA_SWI_TW_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_TW_KEYNAME], "%s%.0f", szField[BPA_SWI_TW_BUS_NAME], StringToFloat(szField[BPA_SWI_TW_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_GX)
// 		{
// 			if (szField[BPA_SWI_GX_GEN_ID][0] != ' ' && szField[BPA_SWI_GX_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_GX_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_GX_BUS_NAME], StringToFloat(szField[BPA_SWI_GX_BUS_KV]), szField[BPA_SWI_GX_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_GX_KEYNAME], "%s%.0f", szField[BPA_SWI_GX_BUS_NAME], StringToFloat(szField[BPA_SWI_GX_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_IGV)
// 		{
// 			if (szField[BPA_SWI_IGV_GEN_ID][0] != ' ' && szField[BPA_SWI_IGV_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_IGV_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_IGV_BUS_NAME], StringToFloat(szField[BPA_SWI_IGV_BUS_KV]), szField[BPA_SWI_IGV_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_IGV_KEYNAME], "%s%.0f", szField[BPA_SWI_IGV_BUS_NAME], StringToFloat(szField[BPA_SWI_IGV_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_FGV)
// 		{
// 			if (szField[BPA_SWI_FGV_GEN_ID][0] != ' ' && szField[BPA_SWI_FGV_GEN_ID][0] != '\0')
// 				sprintf(szField[BPA_SWI_FGV_KEYNAME], "%s%.0f@%c", szField[BPA_SWI_FGV_BUS_NAME], StringToFloat(szField[BPA_SWI_FGV_BUS_KV]), szField[BPA_SWI_FGV_GEN_ID][0]);
// 			else
// 				sprintf(szField[BPA_SWI_FGV_KEYNAME], "%s%.0f", szField[BPA_SWI_FGV_BUS_NAME], StringToFloat(szField[BPA_SWI_FGV_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_D)
// 		{
// 			sprintf(szField[BPA_SWI_D_KEYNAME], "%s%.0f", szField[BPA_SWI_D_BUS_NAME], StringToFloat(szField[BPA_SWI_D_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_V)
// 		{
// 			if (atoi(szField[BPA_SWI_V_ID]) != 0)
// 				sprintf(szField[BPA_SWI_V_KEYNAME], "%s%.0f@%d", szField[BPA_SWI_V_BUS_NAME], StringToFloat(szField[BPA_SWI_V_BUS_KV]), atoi(szField[BPA_SWI_V_ID]));
// 			else
// 				sprintf(szField[BPA_SWI_V_KEYNAME], "%s%.0f", szField[BPA_SWI_V_BUS_NAME], StringToFloat(szField[BPA_SWI_V_BUS_KV]));
// 		}
// 		else if (nTable == BPA_SWI_VG)
// 		{
// 			sprintf(szField[BPA_SWI_VG_KEYNAME], "%s%.0f", szField[BPA_SWI_VG_BUS_NAME], StringToFloat(szField[BPA_SWI_VG_BUS_KV]));
// 		}
// 		// 		else if (nTable == BPA_SWI_LM)
// 		// 		{
// 		// 			sprintf(szField[BPA_SWI_LM_KEYNAME], "%s%.0f-%s%.0f",
// 		// 				szField[BPA_SWI_LM_BUS1_I],
// 		// 				StringToFloat(szField[BPA_SWI_LM_KV1_I]),
// 		// 				szField[BPA_SWI_LM_BUS1_J],
// 		// 				StringToFloat(szField[BPA_SWI_LM_KV1_J]));
// 		// 		}
	}

	void BpaResolveGenModel(tagBpaBlock* pBpaBlock, const char* lpszBusName, const float fBuskV, const char cGenID, int& nGenIndex, int& nDampIndex,
		int& nExcModel, int& nExcIndex, int& nPssModel, int& nPssIndex,
		int& nGovModel, int& nGovIndex, int& nSvoIndex, int& nMovModel, int& nMovIndex)
	{
		register int	i;
		char	szKeyName[MDB_CHARLEN_LONG];

		nExcModel=nPssModel=nGovModel=nMovModel=-1;
		nExcIndex=nPssIndex=nGovIndex=nSvoIndex=nMovIndex=-1;

		if (cGenID != ' ' && cGenID != '\0')
			sprintf(szKeyName, "%s%.0f@%c", lpszBusName, fBuskV, cGenID);
		else
			sprintf(szKeyName, "%s%.0f", lpszBusName, fBuskV);

		nGenIndex=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_GEN, szKeyName);
		if (nGenIndex < 0)
		{
			Log(g_lpszLogFile, "查找发电机[%s]错误 \n", szKeyName);
			return;
		}

		nDampIndex=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_DAMP, szKeyName);

		for (i=0; i<sizeof(g_nBpaExcTables)/sizeof(int); i++)
		{
			nExcIndex=BpaFindRecordbyKey(pBpaBlock, g_nBpaExcTables[i], szKeyName);
			if (nExcIndex >= 0)
			{
				nExcModel=g_nBpaExcTables[i];
				break;
			}
		}

		for (i=0; i<sizeof(g_nBpaPssTables)/sizeof(int); i++)
		{
			nPssIndex=BpaFindRecordbyKey(pBpaBlock, g_nBpaPssTables[i], szKeyName);
			if (nPssIndex >= 0)
			{
				nPssModel=g_nBpaPssTables[i];
				break;
			}
		}

		for (i=0; i<sizeof(g_nBpaGovTables)/sizeof(int); i++)
		{
			nGovIndex=BpaFindRecordbyKey(pBpaBlock, g_nBpaGovTables[i], szKeyName);
			if (nGovIndex >= 0)
			{
				nGovModel=g_nBpaGovTables[i];
				break;
			}
		}
		nSvoIndex=BpaFindRecordbyKey(pBpaBlock, BPA_SWI_GA, szKeyName);

		for (i=0; i<sizeof(g_nBpaMovTables)/sizeof(int); i++)
		{
			nMovIndex=BpaFindRecordbyKey(pBpaBlock, g_nBpaMovTables[i], szKeyName);
			if (nMovIndex >= 0)
			{
				nMovModel=g_nBpaMovTables[i];
				break;
			}
		}
	}
}