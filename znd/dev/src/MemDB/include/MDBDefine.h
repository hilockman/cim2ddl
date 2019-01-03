#pragma once

#include <vector>
using namespace std;

#if defined(__GNUG__) || defined(__GNUC__)	// GCC������Ԥ����ĺ�
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

// const	unsigned char	MDBFieldCategoryBase	=0;	//	������Ϣ���������޸�
// const	unsigned char	MDBFieldCategoryParam	=1;	//	������Ϣ���������޸�
// const	unsigned char	MDBFieldCategoryTopo	=2;	//	�������ݣ��������޸�
// const	unsigned char	MDBFieldCategoryMInput	=3;	//	��ѡ���룬�����ǲ�����Ҳ�����������������ݣ������޸�
// const	unsigned char	MDBFieldCategorySInput	=4;	//	��ѡ���룬�����ǲ�����Ҳ�����������������ݣ������޸�
// const	unsigned char	MDBFieldCategoryOutput	=5;	//	������ݣ������޸�
// const	unsigned char	MDBFieldCategoryAid		=6;	//	�������ݣ��������˵ȣ��������޸�
// const	unsigned char	MDBFieldCategoryOther	=7;	//	�������ݣ������޸�
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
	"������Ϣ",
	"������Ϣ",
	"��������",
	"�������",
	"��������",
};

const	unsigned char	MDBFieldNone		=0;
const	unsigned char	MDBFieldCrit		=1;	//	�ֶ�������Ҫ�ϸ��������飬�ڱ��ֶζ��������������ֶζ���
const	unsigned char	MDBFieldWarn		=2;	//	�ֶ�������Ҫ���ϸ��������飬�ڱ��ֶζ��������������ֶζ���
const	unsigned char	MDBFieldEnum		=3;	//	���ֶ�������ö��
const	unsigned char	MDBFieldDict		=4;	//	���ֶ��������ֵ�����ؼ��֣���Ҫ���ݱ��ֶ�����ȥ�ֵ���в����ֵ䣬������������ͬԭ����д�����ֶ�

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
//	�������鶨����Ϊ����������ġ�

const	unsigned char	MDB_BIT			=1;	//	8λ����
const	unsigned char	MDB_SHORT		=2;	//	16λ����
const	unsigned char	MDB_INT			=3;	//	32λ����
const	unsigned char	MDB_FLOAT		=4;	//	32λʵ��
const	unsigned char	MDB_DOUBLE		=5;	//	64λʵ��
const	unsigned char	MDB_STRING		=6;	//	�ַ���
const	unsigned char	MDB_CHAR		=8;	//	�ַ�
const	unsigned char	MDB_RESTRICT	=10;

const	unsigned char	RELI_COK	=0;	//	������ȷ������Ľ�����Ա����롣
const	unsigned char	RELI_CL		=1;	//	ϵͳ�ɿ���ƫ�ͣ������û����������û�����豸�Ƿ�������ȷ�������Ƿ��趨���ʣ�������ļ���������������롣
const	unsigned char	RELI_CH		=2;	//	ϵͳ�ɿ���ƫ�ߣ������û����������û��������Ƿ��趨���ʣ�������ļ���������������롣
const	unsigned char	RELI_LNS	=3;	//	���ָ��ɵ�û�����ӵ�Դ��û�пɿ��Խ���������ɵ�ɿ���ָ��������룬ϵͳ�ɿ���ָ�겻������롣
const	unsigned char	RELI_ANS	=4;	//	ѡ�������޵�Դ���������и��ɵ㶼û�����ӵ�Դ�������ɵ�ɿ���ָ���ϵͳ�ɿ���ָ�궼��������롣

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
//	unsigned int	nKeyA[g_nConstMaxPrimaryKey];	//	Լ���ؼ���HASHֵ�����ò�ͬ��HASH�㷨���Ե�һ��Ϊ������������ΪУ��
//	unsigned int	nKeyB[g_nConstMaxPrimaryKey];	//	Լ���ؼ���HASHֵ
//	unsigned int	nKeyC[g_nConstMaxPrimaryKey];	//	Լ���ؼ���HASHֵ
//}	DISALIGN;
//typedef	struct	_MDB_RestrictKey_	tagRestrictKey;
struct	_MemDB_PrimaryKey_	{
	short		nPrimaryKeyNum;							//	Լ���ؼ�����
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
	short		nPrimaryKeyNum;							//	Լ���ؼ�����
	short		nPrimaryKeyId[g_nConstMaxPrimaryKey];
}	DISALIGN;
typedef	struct	_MDBBlock_Restrict_	tagMDBBlockPrimaryKey;

struct	_MDBBlock_Field_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szDesp[MDB_CHARLEN];
	short	nCategory;
	short	nDataType;
	short	nDataLen;

	short	bContainer;	//	=0,��ʾ�����������ã�=1��ʾ�ؼ���Լ����=2��ʾ����ֵö�٣�������Լ����=3��ʾ�ṹö��
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
