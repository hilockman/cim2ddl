#pragma once

#include <vector>
using namespace std;

#if defined(__GNUG__) || defined(__GNUC__)	// GCC编译器预定义的宏
#	ifndef DISALIGN
#		define DISALIGN __attribute__((packed))
#	endif
#else
#	define DISALIGN
#endif

#if !defined(__GNUG__) && !defined(__GNUC__)
#	if (defined(_AIX) || defined(AIX))
#		pragma align(packed)
#	else
#		if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#			pragma pack(push)
#		endif
#	endif
#	pragma pack(1)
#endif

const	unsigned char	MDBFileLoad		=0;
const	unsigned char	MDBFileSave		=1;

const	unsigned char	MDBFormatBrief	=1;
const	unsigned char	MDBFormatText	=2;
const	unsigned char	MDBFormatXml	=3;
const	unsigned char	MDBFormatDict	=4;

// const	unsigned char	MDBFieldCategoryBase	=0;	//	基本信息，不允许修改
// const	unsigned char	MDBFieldCategoryParam	=1;	//	参数信息，不允许修改
// const	unsigned char	MDBFieldCategoryTopo	=2;	//	拓扑数据，不允许修改
// const	unsigned char	MDBFieldCategoryMInput	=3;	//	必选输入，可能是参数，也可能是其他输入数据，允许修改
// const	unsigned char	MDBFieldCategorySInput	=4;	//	可选输入，可能是参数，也可能是其他输入数据，允许修改
// const	unsigned char	MDBFieldCategoryOutput	=5;	//	输出数据，允许修改
// const	unsigned char	MDBFieldCategoryAid		=6;	//	辅助数据，包括拓扑等，不允许修改
// const	unsigned char	MDBFieldCategoryOther	=7;	//	其他数据，允许修改
enum	_MDBEnum_FieldCategory_
{
	MDBFieldCategoryBase=0,
	MDBFieldCategoryParam,
	MDBFieldCategoryTopo,	
	MDBFieldCategoryOutput,	
	MDBFieldCategoryAid,	
};
static	const	char*	MDBFeldCategoryStringArray[]=
{
	"基本信息",
	"参数信息",
	"拓扑数据",
	"输出数据",
	"辅助数据",
};

const	unsigned char	MDBFieldNone		=0;
const	unsigned char	MDBFieldCrit		=1;	//	字段内容需要严格的容器检查，在本字段定义后部有容器表和字段定义
const	unsigned char	MDBFieldWarn		=2;	//	字段内容需要非严格的容器检查，在本字段定义后部有容器表和字段定义
const	unsigned char	MDBFieldEnum		=3;	//	本字段内容是枚举
const	unsigned char	MDBFieldDict		=4;	//	本字段内容是字典的主关键字，需要根据本字段内容去字典表中查找字典，并按照列名相同原则填写其他字段

const unsigned char	MDB_NoCheckNull=0;
const unsigned char	MDB_CheckNull=1;
const unsigned char	MDB_NoCheckExist=0;
const unsigned char	MDB_CheckExist=1;
const unsigned char	MDB_NoCheckContainer=0;
const unsigned char	MDB_CheckContainer=1;

const unsigned char	MDB_NoNeedCheckData=0;
const unsigned char	MDB_NeedCheckData=1;

const	short	MAXMDBTABLENUM=120;
const	short	MAXMDBFIELDNUM=150;

const	short	MDB_CHARLEN_BPABUS=10;

const	short	MDB_CHARLEN=64;
const	short	MDB_CHARLEN_SHORTEST=MDB_CHARLEN/8;
const	short	MDB_CHARLEN_SHORTER=MDB_CHARLEN/4;
const	short	MDB_CHARLEN_SHORT=MDB_CHARLEN/2;
const	short	MDB_CHARLEN_LONG =MDB_CHARLEN*4;

const	unsigned char	N_CheckStatus	=0;
const	unsigned char	Y_CheckStatus	=1;

const	unsigned char	N_BusBound		=0;
const	unsigned char	Y_BusBound		=1;

const	unsigned char	N_BreakerBound	=0;
const	unsigned char	Y_BreakerBound	=1;
//	以上三组定义是为了搜索定义的。

const	unsigned char	MDB_BIT			=1;	//	8位整数
const	unsigned char	MDB_SHORT		=2;	//	16位整数
const	unsigned char	MDB_INT			=3;	//	32位整数
const	unsigned char	MDB_FLOAT		=4;	//	32位实数
const	unsigned char	MDB_DOUBLE		=5;	//	64位实数
const	unsigned char	MDB_STRING		=6;	//	字符串
const	unsigned char	MDB_CHAR		=8;	//	字符
const	unsigned char	MDB_RESTRICT	=10;

const	unsigned char	RELI_COK	=0;	//	计算正确，下面的结果可以被读入。
const	unsigned char	RELI_CL		=1;	//	系统可靠性偏低，提醒用户，并且请用户检查设备是否连接正确，参数是否设定合适，但下面的计算结果还是允许读入。
const	unsigned char	RELI_CH		=2;	//	系统可靠性偏高，提醒用户，并且请用户检查参数是否设定合适，但下面的计算结果还是允许读入。
const	unsigned char	RELI_LNS	=3;	//	部分负荷点没有连接电源（没有可靠性结果），负荷点可靠性指标允许读入，系统可靠性指标不允许读入。
const	unsigned char	RELI_ANS	=4;	//	选定区域无电源（或者所有负荷点都没有连接电源），负荷点可靠性指标和系统可靠性指标都不允许读入。

struct	_MemDB_EnumPair_	{
	int			nEnumValue;
	const char*	lpszEnumString;
}	DISALIGN;
typedef	struct	_MemDB_EnumPair_	tagMemDBEnumPair;

struct	_MemDB_Field_	{
	short	nField;
	const char*	lpszName;
	const char*	lpszDesp;
	short	nCategory;
	short	nDataType;
	short	nDataLen;

	short	nEnumNum;
	tagMemDBEnumPair*	pEnumArray;
}	DISALIGN;
typedef	struct	_MemDB_Field_	tagMemDBField;

const	short	g_nConstMaxPrimaryKey=4;
const	short	g_nConstMaxTableFieldContainer=250;

//struct	_MDB_RestrictKey_	{
//	char*			lpszKey[g_nConstMaxPrimaryKey];
//	char			szKey[g_nConstMaxPrimaryKey][MDB_CHARLEN];
//	unsigned int	nRestrictDeviate[g_nConstMaxPrimaryKey];
//	unsigned int	nKeyA[g_nConstMaxPrimaryKey];	//	约束关键字HASH值，采用不同的HASH算法，以第一个为主，其他两个为校验
//	unsigned int	nKeyB[g_nConstMaxPrimaryKey];	//	约束关键字HASH值
//	unsigned int	nKeyC[g_nConstMaxPrimaryKey];	//	约束关键字HASH值
//}	DISALIGN;
//typedef	struct	_MDB_RestrictKey_	tagRestrictKey;
struct	_MemDB_PrimaryKey_	{
	short		nPrimaryKeyNum;							//	约束关键字数
	short		nPrimaryKeyId[g_nConstMaxPrimaryKey];
}	DISALIGN;
typedef	struct	_MemDB_PrimaryKey_	tagMemDBPrimaryKey;

struct	_MemDB_Table_	{
	short		nTable;
	const char*		lpszName;
	const char*		lpszAlias;
	const char*		lpszDesp;
	short		nCategory;
	short		nFieldNum;
	short		nFieldLen;
	int			nRecordMax;
	int			nOffSet;
	tagMemDBPrimaryKey	sPrimaryKey;
	tagMemDBField*	sFieldArray;
}	DISALIGN;
typedef	struct	_MemDB_Table_	tagMemDBTable;

struct	_MDB_TableFieldContainer_	{
	unsigned char	bCheckType;
	short		nTable;
	short		nPKFieldArray[g_nConstMaxPrimaryKey];
	short		nPKTable;
}	DISALIGN;
typedef	struct	_MDB_TableFieldContainer_	tagMDBTableFieldContainer;

struct	_MDBBlock_Restrict_	{
	short		nPrimaryKeyNum;							//	约束关键字数
	short		nPrimaryKeyId[g_nConstMaxPrimaryKey];
}	DISALIGN;
typedef	struct	_MDBBlock_Restrict_	tagMDBBlockPrimaryKey;

struct	_MDBBlock_Field_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szDesp[MDB_CHARLEN];
	short	nCategory;
	short	nDataType;
	short	nDataLen;

	short	bContainer;	//	=0,表示后续内容无用，=1表示关键字约束，=2表示表数值枚举，不产生约束，=3表示结构枚举
	short	nContainerTable;
	short	nContainerField;
}	DISALIGN;
typedef	struct	_MDBBlock_Field_	tagMDBBlockField;

struct	_MDBBlock_Table_	{
	char		szName[MDB_CHARLEN_SHORT];
	char		szDesp[MDB_CHARLEN];
	short		nCategory;
	short		nFieldNum;
	short		nFieldLen;
	int			nRecordMax;
	int			nOffSet;
	unsigned char	bCheckContainer;
	tagMDBBlockPrimaryKey	sPrimaryKey;
	tagMDBBlockField	sFieldArray[MAXMDBFIELDNUM];
}	DISALIGN;
typedef	struct	_MDBBlock_Table_	tagMDBBlockTable;

struct	_MDBBlock_Summy_	{
	short						nTableNum;
	tagMDBBlockTable			sMDBTableArray[MAXMDBTABLENUM];
	tagMDBTableFieldContainer	sMDBContainerArray[g_nConstMaxTableFieldContainer];
}	DISALIGN;
typedef	struct	_MDBBlock_Summy_	tagMDBBlockSummy;

#if !defined(__GNUG__) && !defined(__GNUC__)
#	pragma pack()
#	if (defined(_AIX) || defined(AIX))
#		pragma align(power)
#	else
#		if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#			pragma pack(pop)
#		endif
#	endif
#endif

#ifndef OUT
#	define	OUT
#endif

#ifndef IN
#	define	IN
#endif
