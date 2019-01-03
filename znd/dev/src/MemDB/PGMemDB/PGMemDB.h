#pragma	once

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include <time.h>
#include <sstream>

#if (!defined(_WIN32) && !defined(__WIN32__) && !defined(WIN32) && !defined(_WIN64) && !defined(__WIN64__) && !defined(WIN64))
#	define PGMEMDB_EXPORTS
#else
#	ifdef _PGMEMDB_EXPORTS_
#		define PGMEMDB_EXPORTS  __declspec(dllexport)
#	else
#		define PGMEMDB_EXPORTS  __declspec(dllimport)
#	endif
#endif

#if (defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64))
#	ifndef	STRICMP
#		define	STRICMP		stricmp
#		define	STRNICMP	strnicmp
#	endif
#else
#	include <sys/types.h>
#	include <sys/ipc.h>
#	include <sys/shm.h>
#	ifndef	STRICMP
#		define	STRICMP		strcasecmp
#		define	STRNICMP	strncasecmp
#	endif
#endif

#include "PGMemDBBlock.h"

namespace	PGMemDB
{
	#ifndef	UNPROCBREAK
	#	define	UNPROCBREAK		20
	#endif

	#ifndef	UNPROCSWITCH
	#	define	UNPROCSWITCH	200
	#endif

	const unsigned int	g_nPGBlockKey=110;
	const static char*	g_lpszPGMemDBEntry="MemDB.PG";
	const static char*	g_lpszCnPGMemDBEntry="电网数据库";

	typedef	struct	_PGRadiate_
	{
		int					nBoundNode;	//	边界节点，该节点是环网和辐射网的边界节点，同时该节点为环网节点
		std::vector<int>	nNodeArray;
		std::vector<int>	nLineArray;
		std::vector<int>	nWindArray;
		float				fGenP;
		float				fLoadP;
		float				fLoadQ;
	}	tagPGRadiate;

	PGMEMDB_EXPORTS	char*	Init_PGBlock(const int nPGBlockKey=0, const int bCreateMem=0, const int bClearBaseLog=0);
	PGMEMDB_EXPORTS	void Exit_PGBlock(char* lpszBlockMap, const int nPGBlockKey=0);

	PGMEMDB_EXPORTS	int PGGetTableNum();
	PGMEMDB_EXPORTS	int PGGetTableMax(const int nTable);
	PGMEMDB_EXPORTS	const char*	PGGetTableName(const int nTable);
	PGMEMDB_EXPORTS	const char*	PGGetTableDesp(const int nTable);
	PGMEMDB_EXPORTS	int PGGetTableCategory(const int nTable);
	PGMEMDB_EXPORTS	int PGGetTableIndex(const char* lpszTableName);
	PGMEMDB_EXPORTS	int PGGetTableFieldNum(const int nTable);

	PGMEMDB_EXPORTS	int PGGetFieldIndex(const int nTable, const char* lpszFieldName);
	PGMEMDB_EXPORTS	const char*	PGGetFieldName(const int nTable, const int nField);
	PGMEMDB_EXPORTS	const char*	PGGetFieldDesp(const int nTable, const int nField);
	PGMEMDB_EXPORTS	int PGGetFieldCategory(const int nTable, const int nField);
	PGMEMDB_EXPORTS	int PGGetFieldType(const int nTable, const int nField);
	PGMEMDB_EXPORTS	int PGGetFieldLen(const int nTable, const int nField);

	PGMEMDB_EXPORTS	int PGGetFieldNameArray(const int nTable, char* lpszRetString);
	PGMEMDB_EXPORTS	int PGGetFieldDespArray(const int nTable, char* lpszRetString);
	PGMEMDB_EXPORTS	int PGGetFieldCategoryArray(const int nTable, char* lpszRetString);
	PGMEMDB_EXPORTS	int PGGetFieldTypeArray(const int nTable, char* lpszRetString);
	PGMEMDB_EXPORTS	int PGGetFieldLenArray(const int nTable, char* lpszRetString);

	PGMEMDB_EXPORTS	int PGGetTablePrimaryKeyNum(const int nTable);
	PGMEMDB_EXPORTS	int PGGetTablePrimaryKey(const int nTable, const int nRest);
	PGMEMDB_EXPORTS	int PGIsFieldPrimaryKey(const int nTable, const int nField);

	PGMEMDB_EXPORTS	int PGGetFieldEnumNum(const int nTable, const int nField);
	PGMEMDB_EXPORTS	int PGGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName);
	PGMEMDB_EXPORTS	const char*	PGGetFieldEnumString(const int nTable, const int nField, const int nEnumValue);
	PGMEMDB_EXPORTS	int PGGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char lpszEnumArray[][MDB_CHARLEN]);

	PGMEMDB_EXPORTS	int PGGetRecordRow(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char* lpszRetValue);
	PGMEMDB_EXPORTS	int PGGetRecordValue(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nRecord, char* lpszRetValue);
	PGMEMDB_EXPORTS	int PGSetRecordValue(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue);
	PGMEMDB_EXPORTS	int PGGetRecordRowValue(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char lpszRetValue[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGSetRecordRowValue(tagPGBlock* pPGBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGGetRecordColValue(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetValue[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGGetRecordKeyString(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char* lpszRetValue);

	PGMEMDB_EXPORTS	int PGCheckRecordPrimarykey(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGCheckRecordContainer(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGCheckRecordExist(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);

	//	PowerGrid/PowerGridMisc
	PGMEMDB_EXPORTS	void PGGetTranCoil(tagPGBlock* pPGBlock, const int nTran, int& nTranNum, int nTranCoil[], int nTranNode[]);
	PGMEMDB_EXPORTS	int PGGetVoltID(const float fVolt, char* lpszRetString);
	PGMEMDB_EXPORTS	int PGIsTConnection(tagPGBlock* pPGBlock, const int nJudgeNode);
	PGMEMDB_EXPORTS	int PGGetTranRatio(tagPGBlock* pPGBlock, const int nTran, float& fTapRatio);
	PGMEMDB_EXPORTS	void PGGetParallelACLine(tagPGBlock* pPGBlock, const int nLine, const unsigned char bCheckStatus, int& nParaLineNum, int nParaLineArray[]);
	PGMEMDB_EXPORTS	void PGGetParallelDCLine(tagPGBlock* pPGBlock, const int nLine, const unsigned char bCheckStatus, int& nParaLineNum, int nParaLineArray[]);
	PGMEMDB_EXPORTS	void PGGetParallelTran(tagPGBlock* pPGBlock, const int nTran, const unsigned char bCheckStatus, int& nParaWindNum, int nParaWindArray[]);

	PGMEMDB_EXPORTS	int PGIsVolt32(tagPGBlock* pPGBlock, const int nVolt);

	//MAINT
	PGMEMDB_EXPORTS	int PGFindRecordbyField(tagPGBlock* pPGBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue);
	PGMEMDB_EXPORTS	int PGFindRecordbyRow(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char lpszKeyValue[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1);
	PGMEMDB_EXPORTS	int PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2);
	PGMEMDB_EXPORTS	int PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3);
	PGMEMDB_EXPORTS	int PGFindRecordbyKey(tagPGBlock* pPGBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3, const char* lpszKeyValue4);
	PGMEMDB_EXPORTS	int PGFindRecordFuzzy(tagPGBlock* pPGBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);

	PGMEMDB_EXPORTS	int PGGetFilteredIndexArray(tagPGBlock* pPGBlock, const int bAndOr, const int nTable,
		const int nFilterField1, const char* lpszFilterKey1Array, const int nFilterField2, const char* lpszFilterKey2Array,
		const int nFilterField3, const char* lpszFilterKey3Array, const int nFilterField4, const char* lpszFilterKey4Array,
		const int nIndexCapacity, int nIndexArray[]);

	PGMEMDB_EXPORTS	int PGInsertRecord(tagPGBlock* pPGBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGAppendRecord(tagPGBlock* pPGBlock, const int bNeedCheck, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGUpdateRecord(tagPGBlock* pPGBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
	PGMEMDB_EXPORTS	int PGRemoveRecord(tagPGBlock* pPGBlock, const int nTable, const int nRecord);
	PGMEMDB_EXPORTS	int PGAppendRecordByRow(tagPGBlock* pPGBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser);

	//	将数据指针转换为数据列数组
	PGMEMDB_EXPORTS	void PGDataPtr2FieldArray(IN const int nTable, IN const char* lpszDataPtr, OUT char szField[][MDB_CHARLEN_LONG]);
	//	将数据列数组转换为数据指针
	PGMEMDB_EXPORTS	void PGFieldArray2DataPtr(IN const int nTable, IN const char szField[][MDB_CHARLEN_LONG], OUT char* lpszDataPtr);
	//	从数据列数组中提取指定列的值
	PGMEMDB_EXPORTS	int PGGetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszDataPtr, OUT char* lpszRetValue);
	//	向数据指针中设置指定列的值
	PGMEMDB_EXPORTS	int PGSetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszSetValue, OUT char* lpszDataPtr);
	//	从数据列数组中提取指定列的值
	PGMEMDB_EXPORTS	int PGGetDataPtrFieldString(IN const int nTable, IN const int nField, IN const char* lpszDataPtr, OUT char* lpszRetValue);
	PGMEMDB_EXPORTS	int PGGetDataPtrFieldString(IN const int nTable, IN const int nField, IN const char* lpszDataPtr, IN const unsigned char nFloatPoint, OUT char* lpszRetValue);
	//	向数据指针中设置指定列的值
	PGMEMDB_EXPORTS	int PGSetDataPtrFieldString(IN const int nTable, IN const int nField, IN const char* lpszSetValue, OUT char* lpszDataPtr);

	PGMEMDB_EXPORTS	void PGMaint(tagPGBlock* pPGBlock, const int bFormDerived=1);		//	形成表中辅助信息，包括指针和派生表

	//////////////////////////////////////////////////////////////////////////
	//	PGTraverseNet网络遍历不包含变压器中性点
	PGMEMDB_EXPORTS	void PGTraverseNet(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, const float fMinimalVolt, int& nNodeNum, int nNodeArray[]);
	PGMEMDB_EXPORTS	void PGTraverseSub(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, int& nNodeNum, int nNodeArray[]);
	PGMEMDB_EXPORTS	void PGTraverseVolt(tagPGBlock* pPGBlock, const int nStartNode, const int bChkBreakerOpen, const int bChkSwitchOpen, const int bInBus, const int bChkBreak,  int& nNodeNum, int nNodeArray[]);
	PGMEMDB_EXPORTS	void PGTraverseTopo(tagPGBlock* pPGBlock, const int nStartNode, const int bChkBreakerOpen, const int bChkSwitchOpen, int& nNodeNum, int nNodeArray[]);
	PGMEMDB_EXPORTS	void PGTraverseLine(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, int& nNodeNum, int nNodeArray[]);
	//////////////////////////////////////////////////////////////////////////
	//	PGTraverseZeroNet零序网络遍历不包含变压器中性点
	PGMEMDB_EXPORTS	void PGTraverseZeroNet(tagPGBlock* pPGBlock, const int nStartNode, const int bChkOpen, int& nNodeNum, int nNodeArray[]);

	PGMEMDB_EXPORTS	void PGMemDBType(tagPGBlock* pPGBlock);
	PGMEMDB_EXPORTS	void PGMemDBTopo(tagPGBlock* pPGBlock, const int bCheckOpen=1);
	PGMEMDB_EXPORTS	void PGMemDBIsland(tagPGBlock* pPGBlock, const int bCheckOpen=1);
	PGMEMDB_EXPORTS	void PGMemDBIslandStatistic(tagPGBlock* pPGBlock);
	PGMEMDB_EXPORTS	int PGMemDBIslandRadiant(tagPGBlock* pPGBlock, const int nIsland);

	PGMEMDB_EXPORTS	void PGMemDBStatus(tagPGBlock* pPGBlock, const int bOneIsland=1);
	PGMEMDB_EXPORTS	int PGMemDBPFAmend(tagPGBlock* pPGBlock);
	PGMEMDB_EXPORTS	void PGMemDBStatistic(tagPGBlock* pPGBlock, const int nLossFlag=0);
	PGMEMDB_EXPORTS	void PGMemDBAbnorm(tagPGBlock* pPGBlock, const int nLossFlag=0);

	PGMEMDB_EXPORTS	void PGFillResourceId(tagPGBlock* pPGBlock);
	PGMEMDB_EXPORTS	void PGFormResourceId(tagPGBlock* pPGBlock, const int nTable, const int nRecord, char* lpszRetResID);
	PGMEMDB_EXPORTS	void PGCalcResourceId(const char* lpszInString, char* lpszRetResID);
	PGMEMDB_EXPORTS	int PGGetFieldCategoryNum();
	PGMEMDB_EXPORTS	const char*	PGGetFieldCategoryName(const int nCatrgory);
	PGMEMDB_EXPORTS	int PGGetFieldCategoryValue(const char* lpszCatrgory);

	PGMEMDB_EXPORTS	int PGGetTableFieldContainerNum();
	PGMEMDB_EXPORTS	tagMDBTableFieldContainer*	PGGetTableFieldContainerPtr(const int nContainer);

	//	环网辐射网分解
	//	fOpenRingVolt:	电压等级小于等于该值的电网判断为辐射网
	//	fTinyGenMva:	机容量小于等于该值的发电机不作发电机处理
	PGMEMDB_EXPORTS	void PGRingRadDecompose(tagPGBlock* pPGBlock, const double fOpenRingVolt, const double fTinyGenMva);
}
