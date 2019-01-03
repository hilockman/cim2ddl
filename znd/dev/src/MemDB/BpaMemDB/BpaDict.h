#pragma	once

#include	"BpaMemDBDefine.h"

typedef	struct	_Bpa_Dict_
{
	const char*	szTable;			//	BPA�����������õı�
	const char*	szCardKey;			//	BPA�����ݿ����
	const char*	szFieldName;		//	BPA���ݷ����ֶ�
	short	nFieldStart;
	short	nFieldEnd;
	//char*	szFieldFormat;
	short	nFieldType;
	short	nFieldLen;
	short	nFieldDecimal;
	double	fFieldNomValue;
	double	fFieldMinValue;
	double	fFieldMaxValue;
	unsigned char	bFieldCategory;				//	���������ȶ����ݣ������Ǵӳ����ļ��ж�ȡ���Ǵ��ȶ��ļ��ж�ȡ
	unsigned char	bFieldModabled;				//	�ֶο��޸ı��
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
