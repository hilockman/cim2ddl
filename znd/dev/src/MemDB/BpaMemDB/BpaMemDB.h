#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define	 _CRT_SECURE_NO_WARNINGS
#endif

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include <time.h>
#include <sstream>

#if (!defined(_WIN32) && !defined(__WIN32__) && !defined(WIN32) && !defined(_WIN64) && !defined(__WIN64__) && !defined(WIN64))
#	define BPAMEMDB_EXPORTS
#else
#	ifdef _BPAMEMDB_EXPORTS_
#		define BPAMEMDB_EXPORTS	__declspec(dllexport)
#	else
#		define BPAMEMDB_EXPORTS	__declspec(dllimport)
#	endif
#endif

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
#	ifndef	STRICMP
#		define	STRICMP		stricmp
#		define	STRNICMP	strnicmp
#	endif
// #	pragma warning (disable:4251)
// #	pragma warning (disable:4018)
// #	pragma warning (disable:4996)
// #	pragma	warning(disable:4819)
// #	pragma	warning(disable:4100)
#else
#	include <sys/types.h>
#	include <sys/ipc.h>
#	include <sys/shm.h>
#	ifndef	STRICMP
#		define	STRICMP		strcasecmp
#		define	STRNICMP	strncasecmp
#	endif
#endif

#include "BpaMemDBBlock.h"

namespace	BpaMemDB
{
#ifndef		BpaMemDBIncluded
#	define	BpaMemDBIncluded
#endif

	const unsigned int	g_nBpaBlockKey=140;
	const static char*	g_lpszBpaMemDBEntry="MemDB.Bpa";
	const static char*	g_lpszCnBpaMemDBEntry="BPA数据库";

	typedef	struct	_BpaRadiate_
	{
		int					nBoundBus;	//	边界母线，该母线是环网和辐射网的边界母线，同时该母线为环网母线
		std::vector<int>	nBusArray;
		std::vector<int>	nLineArray;
		std::vector<int>	nWindArray;
		float				fGenP;
		float				fLoadP;
		float				fLoadQ;
	}	tagBpaRadiate;

	//	数据库功能
	BPAMEMDB_EXPORTS	char*	Init_BpaBlock(const int nBpaBlockKey=0, const int bCreateMem=0, const int bClearBaseLog=0);
	BPAMEMDB_EXPORTS	void	Exit_BpaBlock(char* lpszBlockMap, const int nBpaBlockKey=0);

	//	数据库表功能
	BPAMEMDB_EXPORTS	int		BpaGetTableIndex(const char* lpszTableName);
	BPAMEMDB_EXPORTS	int		BpaGetTableName(const int nTable, char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaGetTableDesp(const int nTable, char* lpszRetString);
	BPAMEMDB_EXPORTS	const char*	BpaGetTableName(const int nTable);
	BPAMEMDB_EXPORTS	const char*	BpaGetTableDesp(const int nTable);
	BPAMEMDB_EXPORTS	int		BpaGetTableCategory(const int nTable);
	BPAMEMDB_EXPORTS	int		BpaGetTableNum();
	BPAMEMDB_EXPORTS	int		BpaGetTableMax(const int nTable);
	BPAMEMDB_EXPORTS	int		BpaGetTableFieldNum(const int nTable);

	BPAMEMDB_EXPORTS	int		BpaGetTablePrimaryKeyNum(const int nTable);
	BPAMEMDB_EXPORTS	int		BpaGetTablePrimaryKey(const int nTable, const int nRest);

	//	数据库字段功能
	BPAMEMDB_EXPORTS	int		BpaGetFieldIndex(const int nTable, const char* lpszFieldName);
	BPAMEMDB_EXPORTS	int		BpaGetFieldName(const int nTable, const int nField, char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaGetFieldDesp(const int nTable, const int nField, char* lpszRetString);
	BPAMEMDB_EXPORTS	const char*	BpaGetFieldName(const int nTable, const int nField);
	BPAMEMDB_EXPORTS	const char*	BpaGetFieldDesp(const int nTable, const int nField);
	BPAMEMDB_EXPORTS	int		BpaGetFieldLen(const int nTable, const int nField);
	BPAMEMDB_EXPORTS	int		BpaGetFieldType(const int nTable, const int nField);
	BPAMEMDB_EXPORTS	int		BpaGetFieldCategory(const int nTable, const int nField);

	BPAMEMDB_EXPORTS	int		BpaGetFieldNameArray(const int nTable, char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaGetFieldDespArray(const int nTable, char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaGetFieldCategoryArray(const int nTable, char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaGetFieldTypeArray(const int nTable, char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaGetFieldLenArray(const int nTable, char* lpszRetString);

	BPAMEMDB_EXPORTS	int		BpaGetFieldEnumNum(const int nTable, const int nField);
	BPAMEMDB_EXPORTS	int		BpaGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName);
	BPAMEMDB_EXPORTS	int		BpaGetFieldEnumString(const int nTable, const int nField, const int nEnumValue, char* lpszRetString);
	BPAMEMDB_EXPORTS	const char*	BpaGetFieldEnumString(const int nTable, const int nField, const int nEnumValue);
	BPAMEMDB_EXPORTS	int		BpaGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char lpszEnumArray[][MDB_CHARLEN]);

	//	数据库记录检索功能
	BPAMEMDB_EXPORTS	int		BpaFindRecordbyField(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue);
	BPAMEMDB_EXPORTS	int		BpaFindRecordbyRow(tagBpaBlock* pBpaBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char lpszKeyValue[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1);
	BPAMEMDB_EXPORTS	int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2);
	BPAMEMDB_EXPORTS	int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3);
	BPAMEMDB_EXPORTS	int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3, const char* lpszKeyValue4);
	BPAMEMDB_EXPORTS	int		BpaFindRecordFuzzy(tagBpaBlock* pBpaBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	int		BpaGetFilteredIndexArray(tagBpaBlock* pBpaBlock, const int bAndOr, const int nTable,
									const int nFilterField1, const char* lpszFilterKey1Array,
									const int nFilterField2, const char* lpszFilterKey2Array,
									const int nFilterField3, const char* lpszFilterKey3Array,
									const int nFilterField4, const char* lpszFilterKey4Array,
									const int nIndexCapacity, int nIndexArray[]);
	BPAMEMDB_EXPORTS	int		BpaGetZoneFilteredIndexArray(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszFilterZoneArray, const int nIndexCapacity, int nIndexArray[]);

	//	数据库记录值功能
	BPAMEMDB_EXPORTS	int		BpaGetRecordValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nRecord, char* lpszRetValue);
	BPAMEMDB_EXPORTS	int		BpaSetRecordValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue);
	BPAMEMDB_EXPORTS	int		BpaGetRecordRowValue(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, char lpszRetValue[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	int		BpaSetRecordRowValue(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	int		BpaGetRecordRow(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, char* lpszRetValue);
	BPAMEMDB_EXPORTS	int		BpaGetRecordColValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetValue[][MDB_CHARLEN_LONG]);

	BPAMEMDB_EXPORTS	int		BpaInsertRecord(tagBpaBlock* pBpaBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	int		BpaAppendRecord(tagBpaBlock* pBpaBlock, const int bCheckData, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	int		BpaRemoveRecord(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord);
	BPAMEMDB_EXPORTS	int		BpaUpdateRecord(tagBpaBlock* pBpaBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);

	BPAMEMDB_EXPORTS	int		BpaAppendRecordByRow(tagBpaBlock* pBpaBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser);

	//	数据库维护功能
	BPAMEMDB_EXPORTS	void	BpaMaint(tagBpaBlock* pBpaBlock, const double fZIL=0);		//	形成表中辅助信息，包括指针和派生表
	BPAMEMDB_EXPORTS	void	BpaIsland(tagBpaBlock* pBpaBlock);							//	BPA电岛分析

	//	Bpa数据结构和数据字段的操作
	BPAMEMDB_EXPORTS	void	BpaDataPtr2FieldArray(const int nTable, const char* lpszDataPtr, char szField[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	void	BpaFieldArray2DataPtr(const int nTable, const char szField[][MDB_CHARLEN_LONG], char* lpszDataPtr);

	BPAMEMDB_EXPORTS	void	BpaGetDataPtrFieldValue(const int nTable, const int nField, const char* lpszDataPtr, char* lpszRetValue);
	BPAMEMDB_EXPORTS	void	BpaSetDataPtrFieldValue(const int nTable, const int nField, const char* lpszSetValue, char* lpszDataPtr);

	//	以下三个函数比较混乱，主要原因在于BPA与实时数据接口部分暂时不动造成。目前先搁置
	BPAMEMDB_EXPORTS	int		BpaDataPtr2LineString(const int nBpaTable, const int nDictIni, const char* lpszDataPtr, char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaFieldArray2LineString(const int nBpaTable, const int nDictIni, const char szField[][MDB_CHARLEN_LONG], char* lpszRetString);
	BPAMEMDB_EXPORTS	int		BpaFieldArray2LineString(const int nBpaTable, const char szField[][MDB_CHARLEN_LONG], char* lpszRetMString, char* lpszRetEString, char* lpszRetAString);

	//	将数据行文本转换为数据库的字段值
	BPAMEMDB_EXPORTS	void	BpaString2FieldArray(const int nBpaTable, const int nDictIni, const char* lpszBpaString, char szField[][MDB_CHARLEN_LONG]);

	//	形成BPA的各个表的主键
	BPAMEMDB_EXPORTS	void	BpaFormTableKeyField(const int nTable, char szField[][MDB_CHARLEN_LONG]);
	BPAMEMDB_EXPORTS	void	BpaFormTableKeyField(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord);
	BPAMEMDB_EXPORTS	void	BpaDictKey2BpaCardKey(char* lpszKey);
	BPAMEMDB_EXPORTS	void	BpaBpaCardKey2DictKey(char* lpszKey, const char* lpszDataLine);
	BPAMEMDB_EXPORTS	void	BpaResolveLineKey(const char* lpszLine, char* lpszRetKey);

	//	BPA字典表操作
	BPAMEMDB_EXPORTS	int		BpaGetTableDictIndex(const char* lpszKey, const int nCategory);
	BPAMEMDB_EXPORTS	int		BpaGetFieldDictIndex(const int nDict, const char* lpszField);

	BPAMEMDB_EXPORTS	const int	BpaGetDictNum();
	BPAMEMDB_EXPORTS	const char*	BpaGetDictTable(const int nDictIndex);
	BPAMEMDB_EXPORTS	const char*	BpaGetDictCardKey(const int nDictIndex);
	BPAMEMDB_EXPORTS	const char*	BpaGetDictFieldName(const int nDictIndex);
	BPAMEMDB_EXPORTS	const unsigned char	BpaGetDictModified(const int nDictIndex);
	BPAMEMDB_EXPORTS	const int	BpaGetDictFieldType(const int nDictIndex);
	BPAMEMDB_EXPORTS	const int	BpaGetDictFieldStart(const int nDictIndex);
	BPAMEMDB_EXPORTS	const int	BpaGetDictFieldEnd(const int nDictIndex);
	BPAMEMDB_EXPORTS	const int	BpaGetDictFieldLen(const int nDictIndex);
	BPAMEMDB_EXPORTS	const int	BpaGetDictFieldDecimal(const int nDictIndex);

	//	BPA文件操作
	BPAMEMDB_EXPORTS	int		BpaFiles2MemDB(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile, const double fZeroImpendance);
	BPAMEMDB_EXPORTS	int		BpaMemDB2Files(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile);
	BPAMEMDB_EXPORTS	int		BpaParsePfoFile(tagBpaBlock* pBpaBlock, const char* lpszBpaPfoFile);
	BPAMEMDB_EXPORTS	int		BpaParseOutFile(tagBpaBlock* pBpaBlock, const char* lpszBpaOutFile);

	BPAMEMDB_EXPORTS	int		BpaSwi2LineString(const int nBpaTable, const char* lpszDataPtr, char* lpszRetLine);

	//	其他一些信息操作
	BPAMEMDB_EXPORTS	int		BpaGetGeneratorTableByCardKey(const char* lpszKey);

	//	由BPA母线搜索BPA发电机模型
	BPAMEMDB_EXPORTS	void	BpaResolveGenModel(tagBpaBlock* pBpaBlock, const char* lpszBusName, const float fBuskV, const char cGenID, int& nGenIndex, int& nDampIndex,
		int& nExcModel, int& nExcIndex, int& nPssModel, int& nPssIndex,
		int& nGovModel, int& nGovIndex, int& nSvoIndex, int& nMovModel, int& nMovIndex);

	//	拓扑遍历
	BPAMEMDB_EXPORTS	void	BpaMergeZILLine(tagBpaBlock* pBpaBlock, const double fZIL);
	BPAMEMDB_EXPORTS	void	BpaTraverseNet(tagBpaBlock* pBpaBlock, const int nStartBus, const float fMinimalVolt, int& nBusNum, int nBusArray[]);
	BPAMEMDB_EXPORTS	void	BpaTraverseSub(tagBpaBlock* pBpaBlock, const int nStartBus, const double fZIL, int& nBusNum, int nBusArray[]);

	BPAMEMDB_EXPORTS	const int	BpaGetFieldCategoryNum();
	BPAMEMDB_EXPORTS	const char*	BpaGetFieldCategoryName(const int nCatrgory);
	BPAMEMDB_EXPORTS	const int	BpaGetFieldCategoryValue(const char* lpszCatrgory);

	//	环网辐射网分解
	//	fOpenRingVolt:	电压等级小于等于该值的电网判断为辐射网
	//	fTinyGenMva:	机容量小于等于该值的发电机不作发电机处理
	BPAMEMDB_EXPORTS	void	BpaRingRadDecompose(tagBpaBlock* pBpaBlock, const double fOpenRingVolt, const double fTinyGenMva);

	BPAMEMDB_EXPORTS	void	BpaGetTieACLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieACLineArray[]);
	BPAMEMDB_EXPORTS	void	BpaGetTieLineHGByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieACLineArray[]);
	BPAMEMDB_EXPORTS	void	BpaGetTieTranByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieTranArray[]);
	BPAMEMDB_EXPORTS	void	BpaGetTieDCLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieDCLineArray[]);
	BPAMEMDB_EXPORTS	int		BpaTailorNetByZone(tagBpaBlock* pBpaBlock, const unsigned char bRetainHG, const unsigned char bDCBoundPV, const char* lpszSlack, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray);
}
