#include "PRSecurity.h"
#include "../../../../MemDB/BpaMemDB/BpaDict.h"
#include "../../../../Common/StringCommon.h"

namespace	PRAdequacyBase
{
	extern	CPRMemDBInterface	g_PRMemDBInterface;

	const	static	float	g_fFltStartTime=1;
	const	static	float	g_fFltEraseTime=5;
	const	static	float	g_fRecloseTime=50;
	const	static	float	g_fAccelerTime=1;

	static	tagBpa_Dict	m_BpaDictFltGenTrip[]=
	{
		{	"",		"LS",	"",		1,	2,	/**/	MDB_STRING,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*模型类型标识*/	}, 
		{	"",		"LS",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*母线名*/	}, 
		{	"",		"LS",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*电压基准（kV）*/	}, 
		{	"",		"LS",	"",		17,	17,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*发电机识别码*/	}, 
		{	"",		"LS",	"",		37,	37,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*MDE=4*/	}, 
		{	"",		"LS",	"",		40,	45,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*CYCLE，操作时间（周波）*/	}, 
		{	"",		"LS",	"",		76,	80,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*PG，发电机有功功率减少量MW*/	}, 
	};

	static	tagBpa_Dict	m_BpaDictFltBranFlt[]=
	{
		{	"",		"LS",	"",		1,	2,	/**/	MDB_STRING,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*模型类型标识*/	}, 
		{	"",		"LS",	"",		4,	4,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*填负值表示线路BUSA侧开关断开*/	}, 
		{	"",		"LS",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*线路A侧母线名*/	}, 
		{	"",		"LS",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*电压基准（kV）*/	}, 
		{	"",		"LS",	"",		18,	18,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*填负值表示线路BUSB侧开关断开*/	}, 
		{	"",		"LS",	"",		19,	26,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*线路B侧母线名*/	}, 
		{	"",		"LS",	"",		27,	30,	/**/	MDB_SHORT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*电压基准（kV）*/	}, 
		{	"",		"LS",	"",		32,	32,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*在有平行支路时的平行支路码*/	}, 
		{	"",		"LS",	"",		36,	37,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障类型代码*/	}, 
		{	"",		"LS",	"",		40,	45,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*发生故障时刻*/	}, 
		{	"",		"LS",	"",		46,	51,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*短路电阻*/	}, 
		{	"",		"LS",	"",		52,	57,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*短路电抗*/	}, 
		{	"",		"LS",	"",		58,	63,	/**/	MDB_FLOAT,	6,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障点到BUSA的距离占线路全长的百分数*/	}, 
		{	"",		"LS",	"",		65,	66,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*NDE，故障形式*/	}, 
		{	"",		"LS",	"",		68,	68,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*PHA ，故障相*/	}, 
		{	"",		"LS",	"",		70,	70,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*SID，短路故障侧*/	}, 
	};

	static	tagBpa_Dict	m_BpaDictFltSc3[]=
	{
		{	"",		"FLT",	"",		1,	3,	/**/	MDB_STRING,	3,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*模型类型标识*/	}, 
		{	"",		"FLT",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*前侧节点名称*/	}, 
		{	"",		"FLT",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*前侧节点基准电压（kV）*/	}, 
		{	"",		"FLT",	"",		18,	25,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*后侧节点名称*/	}, 
		{	"",		"FLT",	"",		26,	29,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*后侧节点基准电压（kV）*/	}, 
		{	"",		"FLT",	"",		30,	30,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*回路号*/	}, 
		{	"",		"FLT",	"",		32,	33,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障类型代码*/	}, 
		{	"",		"FLT",	"",		37,	37,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障侧*/	}, 
		{	"",		"FLT",	"",		39,	42,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障发生时间（周波）*/	}, 
		{	"",		"FLT",	"",		43,	46,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到故障相前侧断开的时间间隔（周波）*/	}, 
		{	"",		"FLT",	"",		47,	50,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到故障相后侧断开的时间间隔（周波）*/	}, 
		{	"",		"FLT",	"",		51,	52,	/**/	MDB_FLOAT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障点距离前侧节点的百分比*/	}, 
		{	"",		"FLT",	"",		53,	57,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*接地电阻（pu）*/	}, 
		{	"",		"FLT",	"",		58,	62,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*接地电抗（pu）*/	}, 
	};

	static	tagBpa_Dict	m_BpaDictFltScP1[]=
	{
		{	"",		"FLT",	"",		1,	3,	/**/	MDB_STRING,	3,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*模型类型标识*/	}, 
		{	"",		"FLT",	"",		5,	12,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*前侧节点名称*/	}, 
		{	"",		"FLT",	"",		13,	16,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*前侧节点基准电压（kV）*/	}, 
		{	"",		"FLT",	"",		18,	25,	/**/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*后侧节点名称*/	}, 
		{	"",		"FLT",	"",		26,	29,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*后侧节点基准电压（kV）*/	}, 
		{	"",		"FLT",	"",		30,	30,	/**/	MDB_CHAR,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*回路号*/	}, 
		{	"",		"FLT",	"",		32,	33,	/**/	MDB_SHORT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障类型代码*/	}, 
		{	"",		"FLT",	"",		35,	35,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障相代码*/	}, 
		{	"",		"FLT",	"",		37,	37,	/**/	MDB_BIT,	1,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障侧*/	}, 
		{	"",		"FLT",	"",		39,	42,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障发生时间（周波）*/	}, 
		{	"",		"FLT",	"",		43,	46,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到故障相前侧断开的时间间隔（周波）*/	}, 
		{	"",		"FLT",	"",		47,	50,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到故障相后侧断开的时间间隔（周波）*/	}, 
		{	"",		"FLT",	"",		51,	52,	/**/	MDB_FLOAT,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*故障点距离前侧节点的百分比*/	}, 
		{	"",		"FLT",	"",		53,	57,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*接地电阻（pu）*/	}, 
		{	"",		"FLT",	"",		58,	62,	/**/	MDB_FLOAT,	5,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*接地电抗（pu）*/	}, 
		{	"",		"FLT",	"",		63,	66,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到故障相前侧重合的时间间隔（周波）*/	}, 
		{	"",		"FLT",	"",		67,	70,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到故障相后侧重合的时间间隔（周波）*/	}, 
		{	"",		"FLT",	"",		71,	74,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到前侧三相断开的时间间隔（周波）*/	}, 
		{	"",		"FLT",	"",		75,	78,	/**/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	1,	/*从故障发生到后侧三相断开的时间间隔（周波）*/	}, 
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
				FormularBpaDecimalChar(lpszValue, nLen);
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
		nField++;	//	因中点短路BPA稳定计算错误所以中点暂停
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
		nField++;	//	因中点短路BPA稳定计算错误所以中点暂停
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
		nField++;	//	因中点短路BPA稳定计算错误所以中点暂停
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
		nField++;	//	因中点短路BPA稳定计算错误所以中点暂停
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
		//	获取故障信息在SWI文件中的插入位置
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

				FormularBpaDecimalChar(szValue, 5);
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

				strLineArray[nLine][67]='1';	//	防止500度计算退出
			}
		}
		if (nFltPos < 0)
			return 0;
		//////////////////////////////////////////////////////////////////////////

		//	形成稳定计算对象
		FormFDeviceFMode(pPRBlock);

		char	drive[260], dir[260], fname[260], ext[260];
		_splitpath(lpszBpaSwiFile, drive, dir, fname, ext);

		int		nFltLine;
		int		nFDev, nBusI, nBusJ;
		std::vector<std::string>	strFltArray;

		//////////////////////////////////////////////////////////////////////////
		//	按故障信息形成故障卡
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
