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
#include "BpaDict.h"

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

	typedef	struct  _BpaZone2Area_
	{
		std::string			strAreaName;
		std::vector<std::string>	strZoneArray;
	}	tagBpaZone2Area;

	class BPAMEMDB_EXPORTS CBpaMemDBInterface
	{
	public:
		//	数据库功能
		char*	Init_BpaBlock(const int nBpaBlockKey=0, const int bCreateMem=0, const int bClearBaseLog=0);
		void Exit_BpaBlock(char* lpszBlockMap, const int nBpaBlockKey=0);

		//	数据库表功能
		const int	BpaGetTableIndex(const char* lpszTableName) const;
		const char*	BpaGetTableName(const int nTable) const;
		const char*	BpaGetTableDesp(const int nTable) const;
		const int	BpaGetTableCategory(const int nTable) const;
		const int	BpaGetTableNum() const;
		const int	BpaGetTableMax(const int nTable) const;
		const int	BpaGetTableFieldNum(const int nTable) const;

		const int	BpaGetTablePrimaryKeyNum(const int nTable) const;
		const int	BpaGetTablePrimaryKey(const int nTable, const int nRest) const;
		const int	BpaIsFieldPrimaryKey(const int nTable, const int nField) const;

		//	数据库字段功能
		const int	BpaGetFieldIndex(const int nTable, const char* lpszFieldName) const;
		const char*	BpaGetFieldName(const int nTable, const int nField) const;
		const char*	BpaGetFieldDesp(const int nTable, const int nField) const;
		const int	BpaGetFieldLen(const int nTable, const int nField) const;
		const int	BpaGetFieldType(const int nTable, const int nField) const;
		const int	BpaGetFieldCategory(const int nTable, const int nField) const;

		const int	BpaGetFieldNameArray(const int nTable, char* lpszRetString) const;
		const int	BpaGetFieldDespArray(const int nTable, char* lpszRetString) const;
		const int	BpaGetFieldCategoryArray(const int nTable, char* lpszRetString) const;
		const int	BpaGetFieldTypeArray(const int nTable, char* lpszRetString) const;
		const int	BpaGetFieldLenArray(const int nTable, char* lpszRetString) const;

		const int	BpaGetFieldEnumNum(const int nTable, const int nField) const;
		const int	BpaGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName) const;
		const char*	BpaGetFieldEnumString(const int nTable, const int nField, const int nEnumValue) const;
		const int	BpaGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char lpszEnumArray[][MDB_CHARLEN]) const;

		//	数据库记录检索功能
		int		BpaFindRecordbyField(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue);
		int		BpaFindRecordbyRow(tagBpaBlock* pBpaBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
		int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char lpszKeyValue[][MDB_CHARLEN_LONG]);
		int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1);
		int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2);
		int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3);
		int		BpaFindRecordbyKey(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3, const char* lpszKeyValue4);
		int		BpaFindRecordFuzzy(tagBpaBlock* pBpaBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
		int		BpaGetFilteredIndexArray(tagBpaBlock* pBpaBlock, const int bAndOr, const int nTable,
			const int nFilterField1, const char* lpszFilterKey1Array,
			const int nFilterField2, const char* lpszFilterKey2Array,
			const int nFilterField3, const char* lpszFilterKey3Array,
			const int nFilterField4, const char* lpszFilterKey4Array,
			const int nIndexCapacity, int nIndexArray[]);
		int		BpaGetZoneFilteredIndexArray(tagBpaBlock* pBpaBlock, const int nTable, const char* lpszFilterZoneArray, const int nIndexCapacity, int nIndexArray[]);

		//	数据库记录值功能
		int		BpaGetRecordValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nRecord, char* lpszRetValue);
		int		BpaSetRecordValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue);
		int		BpaGetRecordRowValue(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, char lpszRetValue[][MDB_CHARLEN_LONG]);
		int		BpaSetRecordRowValue(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG]);
		int		BpaGetRecordRow(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord, char* lpszRetValue);
		int		BpaGetRecordColValue(tagBpaBlock* pBpaBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetValue[][MDB_CHARLEN_LONG]);

		int		BpaInsertRecord(tagBpaBlock* pBpaBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
		int		BpaAppendRecord(tagBpaBlock* pBpaBlock, const int bCheckData, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
		int		BpaRemoveRecord(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord);
		int		BpaUpdateRecord(tagBpaBlock* pBpaBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);

		int		BpaAppendRecordByRow(tagBpaBlock* pBpaBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser);

		//	数据库维护功能
		void BpaMaint(tagBpaBlock* pBpaBlock, const double fZIL=0);		//	形成表中辅助信息，包括指针和派生表
		void BpaIsland(tagBpaBlock* pBpaBlock);							//	BPA电岛分析

		//	Bpa数据结构和数据字段的操作
		void BpaDataPtr2FieldArray(const int nTable, const char* lpszDataPtr, char szField[][MDB_CHARLEN_LONG]);
		void BpaFieldArray2DataPtr(const int nTable, const char szField[][MDB_CHARLEN_LONG], char* lpszDataPtr);

		void BpaGetDataPtrFieldValue(const int nTable, const int nField, const char* lpszDataPtr, char* lpszRetValue);
		void BpaSetDataPtrFieldValue(const int nTable, const int nField, const char* lpszSetValue, char* lpszDataPtr);

		//	以下三个函数比较混乱，主要原因在于BPA与实时数据接口部分暂时不动造成。目前先搁置
		int BpaDataPtr2LineString(const int nBpaTable, const int nDictIni, const char* lpszDataPtr, char* lpszRetString);
		int BpaFieldArray2LineString(const int nBpaTable, const int nDictIni, const char szField[][MDB_CHARLEN_LONG], char* lpszRetString);
		int BpaFieldArray2LineString(const int nBpaTable, const char szField[][MDB_CHARLEN_LONG], char* lpszRetMString, char* lpszRetEString, char* lpszRetAString);

		//	将数据行文本转换为数据库的字段值
		void BpaString2FieldArray(const int nBpaTable, const int nDictIni, const char* lpszBpaString, char szField[][MDB_CHARLEN_LONG]);

		//	形成BPA的各个表的主键
		void BpaFormTableKeyField(const int nTable, char szField[][MDB_CHARLEN_LONG]);
		void BpaFormTableKeyField(tagBpaBlock* pBpaBlock, const int nTable, const int nRecord);
		void BpaDictKey2BpaCardKey(char* lpszKey);
		void BpaBpaCardKey2DictKeyFx(char* lpszKey, const char* lpszDataLine);
		void BpaResolveLineKey(const char* lpszLine, char* lpszRetKey);

		//	BPA文件操作
		int BpaFiles2MemDB(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile, const double fZeroImpendance);
		int BpaMemDB2Files(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const char* lpszBpaSwiFile);
		int BpaParsePfoFile(tagBpaBlock* pBpaBlock, const char* lpszBpaPfoFile);
		int BpaParseOutFile(tagBpaBlock* pBpaBlock, const char* lpszBpaOutFile);

		int BpaSwi2LineString(const int nBpaTable, const char* lpszDataPtr, char* lpszRetLine);

		//	其他一些信息操作
		int BpaGetGeneratorTableByCardKey(const char* lpszKey);

		//	由BPA母线搜索BPA发电机模型
		void BpaResolveGenModel(tagBpaBlock* pBpaBlock, const char* lpszBusName, const float fBuskV, const char cGenID, int& nGenIndex, int& nDampIndex,
			int& nExcModel, int& nExcIndex, int& nPssModel, int& nPssIndex,
			int& nGovModel, int& nGovIndex, int& nSvoIndex, int& nMovModel, int& nMovIndex);

		void BpaFormatDecimalChar(const int nBpaTable, const int nBpaField, char* lpszValue, const int nDataLen, const int nDecimal);

		//	拓扑遍历
		void BpaTraverseNet(tagBpaBlock* pBpaBlock, const int nStartBus, const float fMinimalVolt, int& nACBusNum, int nACBusArray[]);
		void BpaTraverseSub(tagBpaBlock* pBpaBlock, const int nStartBus, const double fZIL, int& nACBusNum, int nACBusArray[]);
		void BpaTraverseVolt(tagBpaBlock* pBpaBlock, const int nStartBus, const float fMinVolt, int& nACBusNum, int nACBusArray[]);

		const int	BpaGetFieldCategoryNum() const;
		const char*	BpaGetFieldCategoryName(const int nCatrgory) const;
		const int	BpaGetFieldCategoryValue(const char* lpszCatrgory) const;

		//	环网辐射网分解
		//	fOpenRingVolt:	电压等级小于等于该值的电网判断为辐射网
		//	fTinyGenMva:	机容量小于等于该值的发电机不作发电机处理
		void BpaRingRadDecompose(tagBpaBlock* pBpaBlock, const double fOpenRingVolt, const double fTinyGenMva);

	public:	//	按母线和分区进行网络裁剪
		void BpaGetTieACLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieACLineArray[]);
		void BpaGetTieLineHGByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, int& nTieNum, int nTieACLineArray[]);
		void BpaGetTieTranByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieTranArray[]);
		void BpaGetTieDCLineByZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeDCBusArray, int& nTieNum, int nTieDCLineArray[]);
		int BpaTailorNetByZone(tagBpaBlock* pBpaBlock, const unsigned char bRetainHG, const unsigned char bDCBoundPV, const char* lpszSlack, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, std::vector<std::string>& strExcludeDCBusArray);

	public:	//	按电压等级进行网络裁剪
		void BpaSearchVoltTailorNet(tagBpaBlock* pBpaBlock, const double fMinVoltage, int& nRangeACBusNum, int& nRangeDCBusNum, int nRangeACBusArray[], int nRangeDCBusArray[]);
		void BpaTailorNetByVolt(tagBpaBlock* pBpaBlock, const double fMinVoltage);

	public:
		void BpaSearchLoadTran(tagBpaBlock* pBpaBlock, int& nLoadTranNum, int nLoadTranArray[]);
		void BpaRemoveLoadTran(tagBpaBlock* pBpaBlock, const int bUsePFlowResult);

	public:
		void BpaMergeZILLine(tagBpaBlock* pBpaBlock, const double fZIL);

	public:
		//	BPA字典表操作
		const int BpaGetTableDictIndex(const char* lpszKey, const int nCategory) const;

	private:
		const int BpaGetFieldDictIndex(const int nDict, const char* lpszField) const;
		const int	BpaGetDictNum() const;
		const char*	BpaGetDictTable(const int nDictIndex) const;
		const char*	BpaGetDictCardKey(const int nDictIndex) const;
		const char*	BpaGetDictFieldName(const int nDictIndex) const;
		const unsigned char	BpaGetDictModified(const int nDictIndex) const;
		const int	BpaGetDictFieldType(const int nDictIndex) const;
		const int	BpaGetDictFieldStart(const int nDictIndex) const;
		const int	BpaGetDictFieldEnd(const int nDictIndex) const;
		const int	BpaGetDictFieldLen(const int nDictIndex) const;
		const int	BpaGetDictFieldDecimal(const int nDictIndex) const;

	private:
		void BpaMaintDict();
		int BpaIsCardKeyAppend(const int nCategory, const char* lpszKey);
		void ExtractBpaField(IN const int nColIni, IN const int nColEnd, IN const char* lpszInChar, OUT char* lpszChar);
		void BpaBpaCardKey2DictKey(char* lpszKey, const char* lpszPrevKey);

	private:
		unsigned char IsExcludeBus(std::vector<std::string>& strExcludeBusArray, const char* lpszBusName, const float fBuskV);
		unsigned char IsACBusInRetainZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeACBusArray, const char* lpszBusName, const float fBuskV);
		unsigned char IsDCBusInRetainZone(tagBpaBlock* pBpaBlock, std::vector<std::string>& strRetainZoneArray, std::vector<std::string>& strExcludeDCBusArray, const char* lpszBusName, const float fBuskV);
		int BpaTailorNetByZone_FormBoundGenLoadByACTieTran(tagBpaBlock* pBpaBlock, const int nTieTranNum, int nTieTranArray[]);
		int BpaTailorNetByZone_FormBoundGenLoadByDCTieLine(tagBpaBlock* pBpaBlock, const unsigned char bDCBoundPV, const int nTieDCLineNum, int nTieDCLineArray[]);
		int BpaTailorNetByZone_FormBoundGenLoadByACTieLine(tagBpaBlock* pBpaBlock, const int nTieACLineNum, int nTieACLineArray[]);

	private:
		int InRadiate(tagBpaBlock* pBpaBlock, const int nCheckBus);
		void FormRadiate(tagBpaBlock* pBpaBlock, const double fOpenRingVolt, const double fTinyGenMva, const int nBoundBus, tagBpaRadiate& bndBuffer);

	private:
		void BpaFormEdge(tagBpaBlock* pBpaBlock);
		void BpaFormSubstation(tagBpaBlock* pBpaBlock, const double fZIL);
		void BpaFormTransformer(tagBpaBlock* pBpaBlock);
		void BpaFormGenerator(tagBpaBlock* pBpaBlock);
		void BpaFormLoad(tagBpaBlock* pBpaBlock);
		std::string	GetSubString(tagBpaBlock* pBpaBlock, const int nJointBusNum, const int nJointBussArray[]);

		unsigned char IsBpaBusGenerator(tagBpaBlock* pBpaBlock, const int nBus);
		unsigned char IsBpaBusWTGen(tagBpaBlock* pBpaBlock, const int nBus);
		unsigned char IsBpaBusPVGen(tagBpaBlock* pBpaBlock, const int nBus);
		unsigned char IsBpaBusGenLn(tagBpaBlock* pBpaBlock, const int nBus);

	private:
		void BpaDictLineString2FieldArray(const int nBpaTable, const int nDictFieldNum, tagBpa_Dict dictArray[], const char* lpszBpaLine, char szField[][MDB_CHARLEN_LONG]);
		int	BpaDictFieldArray2LineString(const int nBpaTable, const int nDictFieldNum, tagBpa_Dict dictFieldArray[], const char szField[][MDB_CHARLEN_LONG], char* lpszRetLine);
		int ParseSwiControl(tagBpaBlock* pBpaBlock, const char* lpszKey, const char* lpszLineString);
		void ParseSwiLn(tagBpaBlock* pBpaBlock, std::vector<std::string> strSwiLineArray);
		void ParseSwiLOZ(tagBpaBlock* pBpaBlock, std::vector<std::string> strSwiLineArray);

	private:
		void SplitStringBySpace(const char* lpszString, std::vector<std::string>& strEleArray);
		void ResolveNumericString(const char* lpszString, char* lpszRetString);
		int	PfoFindACBusIndex(tagBpaBlock* pBpaBlock, const char* lpszBusName, const float fBuskV);
		int	PfoFindDCBusIndex(tagBpaBlock* pBpaBlock, const char* lpszBusName, const float fBuskV);
		int	IsPfoShuntLine(const char* lpszLine);
		int	IsPfoNetLine(const char* lpszLine);
		int	ParseBpaPfoBusLine(tagBpaBlock* pBpaBlock, const char* lpszLine, const char* lpszLineExt, int& nBusIndex, unsigned char& bDCBus);
		int	ParseBpaPfoShunt(tagBpaBlock* pBpaBlock, const int nBus, const char* lpszLine);
		int ParseBpaPfoNet(tagBpaBlock* pBpaBlock, const int nBus, const char* lpszLine);
		void ParseBpaPfoACLine(tagBpaBlock* pBpaBlock, const int nFrBus, const char* lpszLine);
		void ParseBpaPfoDCLine(tagBpaBlock* pBpaBlock, const int nFrDCBus, const char* lpszLine);

	private:
		void ParseDatAI(tagBpaBlock* pBpaBlock, std::vector<std::string> strLineArray, std::vector<tagBpaZone2Area>& z2aArray);
		void ParseDatControl(tagBpaBlock* pBpaBlock, std::vector<std::string> strLineArray);

		int BpaFiles2MemDB_Dat(tagBpaBlock* pBpaBlock, const char* lpszBpaDatFile, const double fZeroImpendance);
		int	BpaFiles2MemDB_Swi(tagBpaBlock* pBpaBlock, const char* lpszBpaSwiFile);
		int BpaMemDB2Files_Dat(tagBpaBlock* pBpaBlock, FILE* fp);
		int BpaMemDB2Files_Swi(tagBpaBlock* pBpaBlock, FILE* fp);

	private:
		void SplitString(const char* lpszString, const char* lpszTokenizer, std::vector<std::string>& strEleArray);
		void CheckDecimal(char szFloat[], const int nFloat);
	};
}
