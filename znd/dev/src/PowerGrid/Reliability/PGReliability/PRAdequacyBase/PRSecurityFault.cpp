#include "PRSecurity.h"
#include "../../../../MemDB/BpaMemDB/BpaDict.h"
#include "../../../../Common/StringCommon.h"

namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;
	extern	CBpaMemDBInterface	g_BpaMemDBInterface;

	const	static	float	g_fFltStartTime=1;
	const	static	float	g_fFltEraseTime=5;
	const	static	float	g_fRecloseTime=50;
	const	static	float	g_fAccelerTime=1;

	static	tagBpa_Dict	m_BpaDictFltGenTrip[]=
	{
		{	"",		"LS",	"",		1,	2,	/**/	MDB_STRING,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ģ�����ͱ�ʶ*/	}, 
		{	"",		"LS",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ĸ����*/	}, 
		{	"",		"LS",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*��ѹ��׼��kV��*/	}, 
		{	"",		"LS",	"",		17,	17,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*�����ʶ����*/	}, 
		{	"",		"LS",	"",		37,	37,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*MDE=4*/	}, 
		{	"",		"LS",	"",		40,	45,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*CYCLE������ʱ�䣨�ܲ���*/	}, 
		{	"",		"LS",	"",		76,	80,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*PG��������й����ʼ�����MW*/	}, 
	};

	static	tagBpa_Dict	m_BpaDictFltBranFlt[]=
	{
		{	"",		"LS",	"",		1,	2,	/**/	MDB_STRING,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ģ�����ͱ�ʶ*/	}, 
		{	"",		"LS",	"",		4,	4,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*�ֵ��ʾ��·BUSA�࿪�ضϿ�*/	}, 
		{	"",		"LS",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*��·A��ĸ����*/	}, 
		{	"",		"LS",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*��ѹ��׼��kV��*/	}, 
		{	"",		"LS",	"",		18,	18,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*�ֵ��ʾ��·BUSB�࿪�ضϿ�*/	}, 
		{	"",		"LS",	"",		19,	26,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*��·B��ĸ����*/	}, 
		{	"",		"LS",	"",		27,	30,	/**/	MDB_SHORT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*��ѹ��׼��kV��*/	}, 
		{	"",		"LS",	"",		32,	32,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*����ƽ��֧·ʱ��ƽ��֧·��*/	}, 
		{	"",		"LS",	"",		36,	37,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�������ʹ���*/	}, 
		{	"",		"LS",	"",		40,	45,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*��������ʱ��*/	}, 
		{	"",		"LS",	"",		46,	51,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*��·����*/	}, 
		{	"",		"LS",	"",		52,	57,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*��·�翹*/	}, 
		{	"",		"LS",	"",		58,	63,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���ϵ㵽BUSA�ľ���ռ��·ȫ���İٷ���*/	}, 
		{	"",		"LS",	"",		65,	66,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*NDE��������ʽ*/	}, 
		{	"",		"LS",	"",		68,	68,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*PHA ��������*/	}, 
		{	"",		"LS",	"",		70,	70,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*SID����·���ϲ�*/	}, 
	};

	static	tagBpa_Dict	m_BpaDictFltSc3[]=
	{
		{	"",		"FLT",	"",		1,	3,	/**/	MDB_STRING,	3,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ģ�����ͱ�ʶ*/	}, 
		{	"",		"FLT",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ǰ��ڵ�����*/	}, 
		{	"",		"FLT",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ǰ��ڵ��׼��ѹ��kV��*/	}, 
		{	"",		"FLT",	"",		18,	25,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*���ڵ�����*/	}, 
		{	"",		"FLT",	"",		26,	29,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*���ڵ��׼��ѹ��kV��*/	}, 
		{	"",		"FLT",	"",		30,	30,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*��·��*/	}, 
		{	"",		"FLT",	"",		32,	33,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�������ʹ���*/	}, 
		{	"",		"FLT",	"",		37,	37,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���ϲ�*/	}, 
		{	"",		"FLT",	"",		39,	42,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���Ϸ���ʱ�䣨�ܲ���*/	}, 
		{	"",		"FLT",	"",		43,	46,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ�����������ǰ��Ͽ���ʱ�������ܲ���*/	}, 
		{	"",		"FLT",	"",		47,	50,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ�������������Ͽ���ʱ�������ܲ���*/	}, 
		{	"",		"FLT",	"",		51,	52,	/**/	MDB_FLOAT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���ϵ����ǰ��ڵ�İٷֱ�*/	}, 
		{	"",		"FLT",	"",		53,	57,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӵص��裨pu��*/	}, 
		{	"",		"FLT",	"",		58,	62,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӵص翹��pu��*/	}, 
	};

	static	tagBpa_Dict	m_BpaDictFltScP1[]=
	{
		{	"",		"FLT",	"",		1,	3,	/**/	MDB_STRING,	3,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ģ�����ͱ�ʶ*/	}, 
		{	"",		"FLT",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ǰ��ڵ�����*/	}, 
		{	"",		"FLT",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*ǰ��ڵ��׼��ѹ��kV��*/	}, 
		{	"",		"FLT",	"",		18,	25,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*���ڵ�����*/	}, 
		{	"",		"FLT",	"",		26,	29,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*���ڵ��׼��ѹ��kV��*/	}, 
		{	"",		"FLT",	"",		30,	30,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*��·��*/	}, 
		{	"",		"FLT",	"",		32,	33,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�������ʹ���*/	}, 
		{	"",		"FLT",	"",		35,	35,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���������*/	}, 
		{	"",		"FLT",	"",		37,	37,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���ϲ�*/	}, 
		{	"",		"FLT",	"",		39,	42,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���Ϸ���ʱ�䣨�ܲ���*/	}, 
		{	"",		"FLT",	"",		43,	46,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ�����������ǰ��Ͽ���ʱ�������ܲ���*/	}, 
		{	"",		"FLT",	"",		47,	50,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ�������������Ͽ���ʱ�������ܲ���*/	}, 
		{	"",		"FLT",	"",		51,	52,	/**/	MDB_FLOAT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*���ϵ����ǰ��ڵ�İٷֱ�*/	}, 
		{	"",		"FLT",	"",		53,	57,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӵص��裨pu��*/	}, 
		{	"",		"FLT",	"",		58,	62,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӵص翹��pu��*/	}, 
		{	"",		"FLT",	"",		63,	66,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ�����������ǰ���غϵ�ʱ�������ܲ���*/	}, 
		{	"",		"FLT",	"",		67,	70,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ��������������غϵ�ʱ�������ܲ���*/	}, 
		{	"",		"FLT",	"",		71,	74,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ�����ǰ������Ͽ���ʱ�������ܲ���*/	}, 
		{	"",		"FLT",	"",		75,	78,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*�ӹ��Ϸ������������Ͽ���ʱ�������ܲ���*/	}, 
	};

	const	unsigned char	nPhaseA=1;
	const	unsigned char	nPhaseB=2;
	const	unsigned char	nPhaseC=3;

	const	unsigned char	nSidI=1;
	const	unsigned char	nSidJ=2;
	const	unsigned char	nSidIJ=3;

	void	CPRSecurity::FillFltString(const int nType, const int nIni, const int nEnd, const int nLen, char* lpszValue, char* lpszString)
	{
		register int	i;
		int		nDeviate;

		//Log(g_lpszLogFile, "    FillFltString Type=%d Col=(%d %d %d), Value=%s\n", nType, nIni, nEnd, nLen, lpszValue);

		switch (nType)
		{
		case MDB_FLOAT:
			if (fabs(atof(lpszValue)) > 0.00000001)
			{
				g_BpaMemDBInterface.BpaFormatDecimalChar(-1, -1, lpszValue, nLen, 0);
				for (i=0; i<nLen; i++)
				{
					if (lpszValue[i] == ' ' || lpszValue[i] == '\t' || lpszValue[i] == '\n' || lpszValue[i] == '\r' || lpszValue[i] == '\0')
						break;
					lpszString[i+nIni-1]=lpszValue[i];
				}
			}
			break;
		case MDB_STRING:
			for (i=0; i<nLen; i++)
			{
				if (lpszValue[i] == ' ' || lpszValue[i] == '\t' || lpszValue[i] == '\n' || lpszValue[i] == '\r' || lpszValue[i] == '\0')
					break;
				lpszString[i+nIni-1]=lpszValue[i];
			}
			break;
		case MDB_INT:
		case MDB_BIT:
		case MDB_SHORT:
			nDeviate=0;
			if (nLen > (int)strlen(lpszValue))
				nDeviate=nLen-(int)strlen(lpszValue);

			for (i=0; i<nLen; i++)
			{
				if (lpszValue[i] == ' ' || lpszValue[i] == '\t' || lpszValue[i] == '\n' || lpszValue[i] == '\r' || lpszValue[i] == '\0')
					break;
				lpszString[nDeviate+i+nIni-1]=lpszValue[i];
			}
			break;
		case MDB_CHAR:
			if (lpszValue[0] != ' ' && lpszValue[0] != '\t' && lpszValue[0] != '\n' && lpszValue[0] != '\r' && lpszValue[0] != '\0')
				lpszString[nIni-1]=lpszValue[0];
			break;
		}
	}

	int	CPRSecurity::FormFltGenTrip(const char* lpszBus, const float fkV, const char cId, std::vector<std::string>& strFltArray)
	{
		const short	MDE_TYPE=4;

		register int	i;
		char	szValue[MDB_CHARLEN_LONG];
		int		nField;

		char	szFltLine[256];
		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		//Log(g_lpszLogFile, "Add GenTrip : Bus=%s kV=%f Id=%c\n", lpszBus, fkV, cId);

		nField=0;
		strcpy(szValue, "LS");				FillFltString(m_BpaDictFltGenTrip[nField].nFieldType, m_BpaDictFltGenTrip[nField].nFieldStart, m_BpaDictFltGenTrip[nField].nFieldEnd, m_BpaDictFltGenTrip[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBus);			FillFltString(m_BpaDictFltGenTrip[nField].nFieldType, m_BpaDictFltGenTrip[nField].nFieldStart, m_BpaDictFltGenTrip[nField].nFieldEnd, m_BpaDictFltGenTrip[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkV);		FillFltString(m_BpaDictFltGenTrip[nField].nFieldType, m_BpaDictFltGenTrip[nField].nFieldStart, m_BpaDictFltGenTrip[nField].nFieldEnd, m_BpaDictFltGenTrip[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cId;	szValue[1]='\0';	FillFltString(m_BpaDictFltGenTrip[nField].nFieldType, m_BpaDictFltGenTrip[nField].nFieldStart, m_BpaDictFltGenTrip[nField].nFieldEnd, m_BpaDictFltGenTrip[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", MDE_TYPE);	FillFltString(m_BpaDictFltGenTrip[nField].nFieldType, m_BpaDictFltGenTrip[nField].nFieldStart, m_BpaDictFltGenTrip[nField].nFieldEnd, m_BpaDictFltGenTrip[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "1");				FillFltString(m_BpaDictFltGenTrip[nField].nFieldType, m_BpaDictFltGenTrip[nField].nFieldStart, m_BpaDictFltGenTrip[nField].nFieldEnd, m_BpaDictFltGenTrip[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "9999");			FillFltString(m_BpaDictFltGenTrip[nField].nFieldType, m_BpaDictFltGenTrip[nField].nFieldStart, m_BpaDictFltGenTrip[nField].nFieldEnd, m_BpaDictFltGenTrip[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);

		//Log(g_lpszLogFile, "        FltLine=%s\n", szFltLine);

		strFltArray.push_back(szFltLine);

		return 1;
	}

	int	CPRSecurity::FormFltBranTrip(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, std::vector<std::string>& strFltArray)
	{
		register int	i;
		char	szValue[MDB_CHARLEN_LONG];
		int		nField;

		char	szFltLine[256];
		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "LS");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "0");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTFlt);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "0");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "0");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "0");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);				

		//Log(g_lpszLogFile, "Add BranTrip : %s\n", szFltLine);

		strFltArray.push_back(szFltLine);

		return 1;
	}

	int	CPRSecurity::FormFltBranSC3(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fTTripI, const float fTTripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray)
	{
		const short	FLT_TYPE=1;

		register int	i;
		char	szValue[MDB_CHARLEN_LONG];
		int		nField;

		char	szFltLine[256];
		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "FLT");					FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);				FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);			FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);				FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);			FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';	FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", FLT_TYPE);		FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);			FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTFlt);			FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTTripI);		FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTTripJ);		FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		//sprintf(szValue, "%d", nFltPos);			FillFltString(m_BpaDictFltSc3[nField].nFieldType, m_BpaDictFltSc3[nField].nFieldStart, m_BpaDictFltSc3[nField].nFieldEnd, m_BpaDictFltSc3[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;	//	���е��·BPA�ȶ�������������е���ͣ
		TrimRight(szFltLine);

		//Log(g_lpszLogFile, "Add BranSC3 : %s\n", szFltLine);

		strFltArray.push_back(szFltLine);

		return 1;
	}

	int	CPRSecurity::FormFltLineSC1(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, 
		const float fTFlt, const float fT1TripI, const float fT1TripJ, const float fT1CloseI, const float fT1CloseJ, const float fT3TripI, const float fT3TripJ, 
		const unsigned char nFltPos, std::vector<std::string>& strFltArray)
	{
		const short	FLT_TYPE=3;

		register int	i;
		char	szValue[MDB_CHARLEN_LONG];
		int		nField;

		char	szFltLine[256];
		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "FLT");					FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);				FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);			FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);				FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);			FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';	FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", FLT_TYPE);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nPhaseA);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);			FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTFlt);			FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fT1TripI);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fT1TripJ);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		//sprintf(szValue, "%d", nFltPos);			FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;	//	���е��·BPA�ȶ�������������е���ͣ
		nField++;
		nField++;
		sprintf(szValue, "%f", fT1CloseI);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fT1CloseJ);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fT3TripI);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fT3TripJ);		FillFltString(m_BpaDictFltScP1[nField].nFieldType, m_BpaDictFltScP1[nField].nFieldStart, m_BpaDictFltScP1[nField].nFieldEnd, m_BpaDictFltScP1[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);

		strFltArray.push_back(szFltLine);

		return 1;
	}

	int	CPRSecurity::FormFltTranSC1(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fT3TripI, const float fT3TripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray)
	{
		const short	FLT_TYPE=9;
		const short	nNDE=1;

		register int	i;
		char	szValue[MDB_CHARLEN_LONG];
		int		nField;

		char	szFltLine[256];

		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "LS");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", FLT_TYPE);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTFlt);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		nField++;
		nField++;
		sprintf(szValue, "%d", nNDE);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nPhaseA);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);
		strFltArray.push_back(szFltLine);

		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "LS");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", -FLT_TYPE);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTFlt);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		nField++;
		nField++;
		sprintf(szValue, "%d", nNDE);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nPhaseA);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);
		strFltArray.push_back(szFltLine);

		return 1;
	}

	int	CPRSecurity::FormFltBranSC2(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fT3TripI, const float fT3TripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray)
	{
		const short	FLT_TYPE=9;
		const short	nNDE=2;

		register int	i;
		char	szValue[MDB_CHARLEN_LONG];
		int		nField;

		char	szFltLine[256];

		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "LS");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		strcpy(szValue, lpszBusI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		strcpy(szValue, lpszBusJ);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", FLT_TYPE);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTFlt);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		nField++;
		nField++;	//	���е��·BPA�ȶ�������������е���ͣ
		//sprintf(szValue, "%d", nFltPos);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nNDE);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nPhaseA);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);
		strFltArray.push_back(szFltLine);

		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "LS");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", -FLT_TYPE);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fT3TripI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		nField++;
		nField++;	//	���е��·BPA�ȶ�������������е���ͣ
		//sprintf(szValue, "%d", nFltPos);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nNDE);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nPhaseA);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);
		strFltArray.push_back(szFltLine);

		return 1;
	}

	int	CPRSecurity::FormFltBranSC4(const char* lpszBusI, const float fkVI, const char* lpszBusJ, const float fkVJ, const char cLoop, const float fTFlt, const float fT3TripI, const float fT3TripJ, const unsigned char nFltPos, std::vector<std::string>& strFltArray)
	{
		const short	FLT_TYPE=9;
		const short	nNDE=4;

		register int	i;
		char	szValue[MDB_CHARLEN_LONG];
		int		nField;

		char	szFltLine[256];

		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "LS");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", FLT_TYPE);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fTFlt);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		nField++;
		nField++;
		sprintf(szValue, "%d", nNDE);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nPhaseA);	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);
		strFltArray.push_back(szFltLine);

		for (i=0; i<255; i++)
			szFltLine[i]=' ';
		szFltLine[255]='\0';

		nField=0;
		strcpy(szValue, "LS");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusI);				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, "-");					FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		strcpy(szValue, lpszBusJ);				FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fkVJ);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		szValue[0]=cLoop;	szValue[1]='\0';	FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", -FLT_TYPE);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%f", fT3TripI);		FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		nField++;
		nField++;
		nField++;
		sprintf(szValue, "%d", nNDE);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nPhaseA);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		sprintf(szValue, "%d", nSidI);			FillFltString(m_BpaDictFltBranFlt[nField].nFieldType, m_BpaDictFltBranFlt[nField].nFieldStart, m_BpaDictFltBranFlt[nField].nFieldEnd, m_BpaDictFltBranFlt[nField].nFieldLen, szValue, szFltLine);	nField++;
		TrimRight(szFltLine);
		strFltArray.push_back(szFltLine);

		return 1;
	}

	int	CPRSecurity::FormSwiFiles(tagPRBlock* pPRBlock, IN const char* lpszWorkDir, IN const char* lpszBaseFile, IN const char* lpszBpaSwiFile, const double fEndDT)
	{
		register int	i;
		char	szSwiFileName[260];
		char	szLine[512];
		FILE*	fp;

		int		nLine, nState, nFltPos;
		std::vector<std::string>	strLineArray;
		fp=fopen(lpszBpaSwiFile, "r");
		if (fp == NULL)
			return 0;

		strLineArray.clear();
		while (!feof(fp))
		{
			memset(szLine, 0, 512);
			fgets(szLine, 1024, fp);

			TrimEnd(szLine);
			TrimRight(szLine);
			strLineArray.push_back(szLine);
		}
		fclose(fp);
		//////////////////////////////////////////////////////////////////////////
		//	��ȡ������Ϣ��SWI�ļ��еĲ���λ��
		nFltPos=-1;
		for (nLine=0; nLine<(int)strLineArray.size(); nLine++)
		{
			if ((strLineArray[nLine][0] == 'F' || strLineArray[nLine][0] == 'f') && (strLineArray[nLine][1] == 'L' || strLineArray[nLine][1] == 'l') && (strLineArray[nLine][2] == 'T' || strLineArray[nLine][2] == 't'))
				strLineArray[nLine].insert(0, ".");
			else if ((strLineArray[nLine][0] == 'L' || strLineArray[nLine][0] == 'l') && (strLineArray[nLine][1] == 'S' || strLineArray[nLine][1] == 's'))
				strLineArray[nLine].insert(0, ".");

			if ((strLineArray[nLine][0] == 'C' || strLineArray[nLine][0] == 'c') &&
				(strLineArray[nLine][1] == 'A' || strLineArray[nLine][1] == 'a') &&
				(strLineArray[nLine][2] == 'S' || strLineArray[nLine][2] == 's') &&
				(strLineArray[nLine][3] == 'E' || strLineArray[nLine][3] == 'e') &&
				(strLineArray[nLine][4] == ' '))
			{
				nFltPos=nLine;

				while (strLineArray[nLine].length() < 80)
					strLineArray[nLine] += ' ';

				if (strLineArray[nLine].length() > 16)	strLineArray[nLine][16]='1';
				if (strLineArray[nLine].length() > 21)	strLineArray[nLine][21]='0';
			}

			if ((strLineArray[nLine][0] == 'F' || strLineArray[nLine][0] == 'f') && (strLineArray[nLine][1] == 'F' || strLineArray[nLine][1] == 'f') && (strLineArray[nLine][2] == ' ') && (strLineArray[nLine][3] == ' '))
			{
				while (strLineArray[nLine].length() < 80)
					strLineArray[nLine] += ' ';

				char	szValue[260];
				if (fEndDT <= FLT_MIN || fEndDT > 10000)
					sprintf(szValue, "%f", 300.0);
				else
					sprintf(szValue, "%f", fEndDT);

				g_BpaMemDBInterface.BpaFormatDecimalChar(-1, -1, szValue, 5, 0);
				strLineArray[nLine][12]=' ';
				strLineArray[nLine][13]=' ';
				strLineArray[nLine][14]=' ';
				strLineArray[nLine][15]=' ';
				strLineArray[nLine][16]=' ';
				for (i=0; i<5; i++)
				{
					if (szValue[i] == ' ' || szValue[i] == '\t' || szValue[i] == '\n' || szValue[i] == '\r' || szValue[i] == '\0')
						break;
					strLineArray[nLine][12+i]=szValue[i];
				}

				strLineArray[nLine][67]='1';	//	��ֹ500�ȼ����˳�
			}
		}
		if (nFltPos < 0)
			return 0;
		//////////////////////////////////////////////////////////////////////////

		//	�γ��ȶ��������
		FormFDeviceFMode(pPRBlock);

		char	drive[260], dir[260], fname[260], ext[260];
		_splitpath(lpszBpaSwiFile, drive, dir, fname, ext);

		int		nFltLine;
		int		nFDev, nBusI, nBusJ;
		std::vector<std::string>	strFltArray;

		//////////////////////////////////////////////////////////////////////////
		//	��������Ϣ�γɹ��Ͽ�
		for (nState=0; nState<pPRBlock->m_nRecordNum[PR_FSECURITY]; nState++)
		{
			strFltArray.clear();
			for (nLine=0; nLine<pPRBlock->m_nRecordNum[PR_FSTATEFDEV]; nLine++)
			{
				if (pPRBlock->m_FStateFDevArray[nLine].nFStateNo != pPRBlock->m_FSecurityArray[nState].nFStateNo)
					continue;

				nFDev=pPRBlock->m_FStateFDevArray[nLine].nFDevIdx;
				switch (pPRBlock->m_FStateFDevArray[nLine].nFDevTyp)
				{
				case	PR_GENERATOR:
					FormFltGenTrip(pPRBlock->m_GeneratorArray[nFDev].szBus, pPRBlock->m_GeneratorArray[nFDev].fkV, pPRBlock->m_GeneratorArray[nFDev].cGenId, strFltArray);
					break;
				case	PR_ACLINE:
					nBusI=pPRBlock->m_ACLineArray[nFDev].nIBus;
					nBusJ=pPRBlock->m_ACLineArray[nFDev].nZBus;
					switch (pPRBlock->m_FStateFDevArray[nLine].nDFltTyp)
					{
					case	PRFState_FaultType_OnePhaseGround:
						FormFltLineSC1(pPRBlock->m_ACLineArray[nFDev].szIniBusI, pPRBlock->m_ACLineArray[nFDev].fInikVI, pPRBlock->m_ACLineArray[nFDev].szIniBusJ, pPRBlock->m_ACLineArray[nFDev].fInikVJ, pPRBlock->m_ACLineArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, g_fRecloseTime, g_fRecloseTime, g_fRecloseTime+g_fAccelerTime, g_fRecloseTime+g_fAccelerTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					case	PRFState_FaultType_TwoPhase:
						FormFltBranSC2(pPRBlock->m_ACLineArray[nFDev].szIniBusI, pPRBlock->m_ACLineArray[nFDev].fInikVI, pPRBlock->m_ACLineArray[nFDev].szIniBusJ, pPRBlock->m_ACLineArray[nFDev].fInikVJ, pPRBlock->m_ACLineArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					case	PRFState_FaultType_ThreePhase:
						FormFltBranSC3(pPRBlock->m_ACLineArray[nFDev].szIniBusI, pPRBlock->m_ACLineArray[nFDev].fInikVI, pPRBlock->m_ACLineArray[nFDev].szIniBusJ, pPRBlock->m_ACLineArray[nFDev].fInikVJ, pPRBlock->m_ACLineArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					case	PRFState_FaultType_TwoPhaseGround:
						FormFltBranSC4(pPRBlock->m_ACLineArray[nFDev].szIniBusI, pPRBlock->m_ACLineArray[nFDev].fInikVI, pPRBlock->m_ACLineArray[nFDev].szIniBusJ, pPRBlock->m_ACLineArray[nFDev].fInikVJ, pPRBlock->m_ACLineArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					default:
						FormFltBranTrip(pPRBlock->m_ACLineArray[nFDev].szIniBusI, pPRBlock->m_ACLineArray[nFDev].fInikVI, pPRBlock->m_ACLineArray[nFDev].szIniBusJ, pPRBlock->m_ACLineArray[nFDev].fInikVJ, pPRBlock->m_ACLineArray[nFDev].cIniLoop, g_fFltStartTime, strFltArray);
						break;
					}
					break;
				case	PR_WIND:
					nBusI=pPRBlock->m_WindArray[nFDev].nIBus;
					nBusJ=pPRBlock->m_WindArray[nFDev].nZBus;
					switch (pPRBlock->m_FStateFDevArray[nLine].nDFltTyp)
					{
					case	PRFState_FaultType_OnePhaseGround:
						FormFltTranSC1(pPRBlock->m_WindArray[nFDev].szIniBusI, pPRBlock->m_WindArray[nFDev].fInikVI, pPRBlock->m_WindArray[nFDev].szIniBusJ, pPRBlock->m_WindArray[nFDev].fInikVJ, pPRBlock->m_WindArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					case	PRFState_FaultType_TwoPhase:
						FormFltBranSC2(pPRBlock->m_WindArray[nFDev].szIniBusI, pPRBlock->m_WindArray[nFDev].fInikVI, pPRBlock->m_WindArray[nFDev].szIniBusJ, pPRBlock->m_WindArray[nFDev].fInikVJ, pPRBlock->m_WindArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					case	PRFState_FaultType_ThreePhase:
						FormFltBranSC3(pPRBlock->m_WindArray[nFDev].szIniBusI, pPRBlock->m_WindArray[nFDev].fInikVI, pPRBlock->m_WindArray[nFDev].szIniBusJ, pPRBlock->m_WindArray[nFDev].fInikVJ, pPRBlock->m_WindArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					case	PRFState_FaultType_TwoPhaseGround:
						FormFltBranSC4(pPRBlock->m_WindArray[nFDev].szIniBusI, pPRBlock->m_WindArray[nFDev].fInikVI, pPRBlock->m_WindArray[nFDev].szIniBusJ, pPRBlock->m_WindArray[nFDev].fInikVJ, pPRBlock->m_WindArray[nFDev].cIniLoop, g_fFltStartTime, g_fFltEraseTime, g_fFltEraseTime, pPRBlock->m_FStateFDevArray[nLine].nDFltPos, strFltArray);
						break;
					default:
						FormFltBranTrip(pPRBlock->m_WindArray[nFDev].szIniBusI, pPRBlock->m_WindArray[nFDev].fInikVI, pPRBlock->m_WindArray[nFDev].szIniBusJ, pPRBlock->m_WindArray[nFDev].fInikVJ, pPRBlock->m_WindArray[nFDev].cIniLoop, g_fFltStartTime, strFltArray);
						break;
					}
					break;
				}
			}

			sprintf(szSwiFileName, "%s/%s-%d%s", lpszWorkDir, fname, pPRBlock->m_FSecurityArray[nState].nFStateNo, ext);
			fp=fopen(szSwiFileName, "w");
			if (fp != NULL)
			{
				for (nLine=0; nLine<(int)strLineArray.size(); nLine++)
				{
					fprintf(fp, "%s\n", strLineArray[nLine].c_str());
					if (nLine == nFltPos)
					{
						for (nFltLine=0; nFltLine<(int)strFltArray.size(); nFltLine++)
							fprintf(fp, "%s\n", strFltArray[nFltLine].c_str());
					}
				}

				fflush(fp);
				fclose(fp);

				strcpy(pPRBlock->m_FSecurityArray[nState].szSwiFile, szSwiFileName);
				sprintf(pPRBlock->m_FSecurityArray[nState].szBseFile, "%s/%s-%d.bse", lpszWorkDir, fname, pPRBlock->m_FSecurityArray[nState].nFStateNo);
				sprintf(pPRBlock->m_FSecurityArray[nState].szOutFile, "%s/%s-%d.out", lpszWorkDir, fname, pPRBlock->m_FSecurityArray[nState].nFStateNo);

				CopyFile(lpszBaseFile, pPRBlock->m_FSecurityArray[nState].szBseFile, FALSE);
			}
		}

		return 1;
	}
}
