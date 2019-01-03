#pragma	once

#include	"BpaMemDBDefine.h"

typedef	struct	_Bpa_Dict_
{
	const char*	szTable;			//	BPA数据输入后放置的表
	const char*	szCardKey;			//	BPA的数据卡标记
	const char*	szFieldName;		//	BPA数据放置字段
	short	nFieldStart;
	short	nFieldEnd;
	//char*	szFieldFormat;
	short	nFieldType;
	short	nFieldLen;
	short	nFieldDecimal;
	double	fFieldNomValue;
	double	fFieldMinValue;
	double	fFieldMaxValue;
	unsigned char	bFieldCategory;				//	潮流还是稳定数据，表明是从潮流文件中读取还是从稳定文件中读取
	unsigned char	bFieldModabled;				//	字段可修改标记
	//char*	szFieldComment;
}	tagBpa_Dict;

typedef	struct	_BpaDictIndex_
{
	unsigned char	bCategory;
	char			szKey[MDB_CHARLEN_SHORTER];
	char			szTable[MDB_CHARLEN_SHORT];
	std::vector<tagBpa_Dict>	dkFieldArray;
}	tagBpaDictIndex;

typedef	struct	_Bpa_Key2I_
{
	const char*	szKey;
	short	nInteger;
}	tagBpaKey2I;
