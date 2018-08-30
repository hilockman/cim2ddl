#pragma	once

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include <time.h>
#include <sstream>

#if (!defined(_WIN32) && !defined(__WIN32__) && !defined(WIN32) && !defined(_WIN64) && !defined(__WIN64__) && !defined(WIN64))
#	define PRMEMDB_EXPORTS
#else
#	ifdef _PRMEMDB_EXPORTS_
#		define PRMEMDB_EXPORTS  __declspec(dllexport)
#	else
#		define PRMEMDB_EXPORTS  __declspec(dllimport)
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

#include "PRMemDBBlock.h"

namespace	PRMemDB
{
	const unsigned int	g_nPRBlockKey=150;
	const static char*	g_lpszPRMemDBEntry="MemDB.PR";
	const static char*	g_lpszCnPRMemDBEntry="主网可靠性计算数据库";

	class PRMEMDB_EXPORTS CPRMemDBInterface
	{
	public:
		char*	Init_PRBlock(const int nReliableBlockKey=0, const int bCreateMem=0, const int bClearBaseLog=0);
		void	Exit_PRBlock(char* lpszBlockMap, const int nReliableBlockKey=0);
		const int	PRGetBlockSize() const;

		const int	PRGetTableNum() const;
		const int	PRGetTableMax(const int nTable) const;
		const char*	PRGetTableName(const int nTable) const;
		const char*	PRGetTableDesp(const int nTable) const;
		const int	PRGetTableCategory(const int nTable) const;
		const int	PRGetTableIndex(const char* lpszTableName) const;
		const int	PRGetTableFieldNum(const int nTable) const;

		const int	PRGetFieldIndex(const int nTable, const char* lpszFieldName) const;
		const char*	PRGetFieldName(const int nTable, const int nField) const;
		const char*	PRGetFieldDesp(const int nTable, const int nField) const;
		const int	PRGetFieldCategory(const int nTable, const int nField) const;
		const int	PRGetFieldType(const int nTable, const int nField) const;
		const int	PRGetFieldLen(const int nTable, const int nField) const;

		const int	PRGetFieldNameArray(const int nTable, char* lpszRetString) const;
		const int	PRGetFieldDespArray(const int nTable, char* lpszRetString) const;
		const int	PRGetFieldCategoryArray(const int nTable, char* lpszRetString) const;
		const int	PRGetFieldTypeArray(const int nTable, char* lpszRetString) const;
		const int	PRGetFieldLenArray(const int nTable, char* lpszRetString) const;

		const int	PRGetFieldEnumNum(const int nTable, const int nField) const;
		const int	PRGetFieldEnumValue(const int nTable, const int nField, const char* lpszEnumName) const;
		const char*	PRGetFieldEnumString(const int nTable, const int nField, const int nEnumValue) const;
		const int	PRGetFieldEnumStringArray(const int nTable, const int nField, int& nEnumNum, char lpszEnumArray[][MDB_CHARLEN]);

		const int	PRGetTablePrimaryKeyNum(const int nTable) const;
		const int	PRGetTablePrimaryKey(const int nTable, const int nRest) const;

		int		PRGetRecordValue(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nRecord, char* lpszRetValue);
		int		PRSetRecordValue(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nRecord, const char* lpszValue);
		int		PRGetRecordRowValue(tagPRBlock* pPRBlock, const int nTable, const int nRecord, char lpszRetValue[][MDB_CHARLEN_LONG]);
		int		PRSetRecordRowValue(tagPRBlock* pPRBlock, const int nTable, const int nRecord, const char lpszValue[][MDB_CHARLEN_LONG]);
		int		PRGetRecordColValue(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nIniRecord, const int nMaxCount, char lpszRetValue[][MDB_CHARLEN_LONG]);

		int		PRGetRecordRow(tagPRBlock* pPRBlock, const int nTable, const int nRecord, char* lpszRetValue);

		//	PowerGrid/PowerGridMisc
		int		PRFindRecordbyField(tagPRBlock* pPRBlock, const int nTable, const int nField, const int nIniRecord, const char* lpszValue);
		int		PRFindRecordbyRow(tagPRBlock* pPRBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);
		int		PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char lpszKeyValue[][MDB_CHARLEN_LONG]);
		int		PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1);
		int		PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2);
		int		PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3);
		int		PRFindRecordbyKey(tagPRBlock* pPRBlock, const int nTable, const char* lpszKeyValue1, const char* lpszKeyValue2, const char* lpszKeyValue3, const char* lpszKeyValue4);
		int		PRFindRecordFuzzy(tagPRBlock* pPRBlock, const int nTable, const char lpszValue[][MDB_CHARLEN_LONG]);

		int	PRGetFilteredIndexArray(tagPRBlock* pPRBlock, const int bAndOr, const int nTable,
			const int nFilterField1, const char* lpszFilterKey1Array, const int nFilterField2, const char* lpszFilterKey2Array,
			const int nFilterField3, const char* lpszFilterKey3Array, const int nFilterField4, const char* lpszFilterKey4Array,
			const int nIndexCapacity, int nIndexArray[]);

		int		PRInsertRecord(tagPRBlock* pPRBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
		int		PRAppendRecord(tagPRBlock* pPRBlock, const int bNeedCheck, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
		int		PRUpdateRecord(tagPRBlock* pPRBlock, const int nTable, const char lpszRecArray[][MDB_CHARLEN_LONG]);
		int		PRRemoveRecord(tagPRBlock* pPRBlock, const int nTable, const int nRecord);
		int		PRAppendRecordByRow(tagPRBlock* pPRBlock, const int bNeedCheck, const int nTable, const int nFieldIndex[], const char* lpszParser);

		//	从数据列数组中提取指定列的值
		int		PRGetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszDataPtr, OUT char* lpszRetValue);
		//	向数据指针中设置指定列的值
		int		PRSetDataPtrFieldValue(IN const int nTable, IN const int nField, IN const char* lpszSetValue, OUT char* lpszDataPtr);

		void	PRMaint(tagPRBlock* pPRBlock);		//	形成表中辅助信息，包括指针和派生表

		//void	PRMemDBTopo(tagPRBlock* pPRBlock, const int bTrip=0);
		void	PRMemDBIsland(tagPRBlock* pPRBlock, const unsigned char bRingIslandOnly=1);
		void	PRTraverseRadial(tagPRBlock* pPRBlock, const int nRadial, int& nBusNum, int* pnBusArray);

		const int	PRGetFieldCategoryNum() const;
		const char*	PRGetFieldCategoryName(const int nCatrgory) const;
		const int	PRGetFieldCategoryValue(const char* lpszCatrgory) const;

	protected:
	private:
		const int	GetBlockSize(void) const;
		void		AssignBlockSummary(tagPRBlock* pPRBlock);
		void		CheckBlockValidate(const int nMemSize);

		void		PRMemDBClearLog();
		void		PRMemDBLog(const char* pformat, ...);

		void		FormDerivedDevice(tagPRBlock* pPRBlock);

		void		PRTraverseACNet(tagPRBlock* pPRBlock, const unsigned char bRingIslandOnly, const int nStartBus, std::vector<int>& nJointBusArray);
	};

}
