#pragma once

static	tagMemDBField	g_PGTerminalFieldArray[]=
{
	{	PG_TERMINAL_RESOURCEID,						"ResourceID",			"��ԴId",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_TERMINAL_SUBSTATION,						"Substation",			"��վ",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_TERMINAL_VOLTAGELEVEL,					"VoltageLevel",			"��ѹ�ȼ�",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_TERMINAL_NAME,							"Name",					"����",			MDBFieldCategoryBase,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_TERMINAL_CONNECTIVITYNODE,				"ConnectivityNode",		"�ڵ�",			MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
};

static	tagMemDBField	g_PGConnectivityNodeFieldArray[]=
{
	{	PG_CONNECTIVITYNODE_SUBSTATION,					"Substation",				"��վ",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_VOLTAGELEVEL,				"VoltageLevel",				"��ѹ�ȼ�",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_CONNECTIVITYNODE_NAME,						"Name",						"����",						MDBFieldCategoryBase,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_ACLINESEGMENTRANGE,			"ACLineSegmentRange",		"������·�η�Χ",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DCLINESEGMENTRANGE,			"DCLineSegmentRange",		"ֱ����·�η�Χ",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_TRANSFORMERWINDINGRANGE,	"TransformerWindingRange",	"��ѹ�����鷶Χ",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_SERIESCOMPENSATORRANGE,		"SeriesCompensatorRange",	"����������Χ",				MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_BREAKERRANGE,				"BreakerRange",				"��·����Χ",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DISCONNECTORRANGE,			"DisconnectorRange",		"���뿪�ط�Χ",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_ADCONVERTERRANGE,			"ADConverterRange",			"��ֱ�任����Χ",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DDCONVERTERRANGE,			"DDConverterRange",			"ֱֱ�任����Χ",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DCBREAKERRANGE,				"DCBreakerRange",			"ֱ����·����Χ",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DCSHORTCIRCUITLIMITRANGE,	"DCShortCircuitLimitRange",	"ֱ����·������������Χ",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_VOLTAGELEVELPTR,			"VoltageLevelPtr",			"��ѹ�ȼ�����",				MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_BUSBARSECTIONPTR,			"BusbarSectionPtr",			"ĸ������",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_TOPOBUS,					"TopoBus",					"���˽ڵ�",					MDBFieldCategoryTopo,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_ISLAND,						"Island",					"��",						MDBFieldCategoryTopo,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_SA_ABILITY,					"sa_Ability",				"�ڵ�ת������(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_INRING,						"InRing",					"�������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_CONNECTIVITYNODE_RADIATE,					"Radiate",					"��������",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_OPEN,						"Open",						"����״̬",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_CONNECTIVITYNODE_TMID,						"TMid"	,					"��ѹ���е�",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeACLineSegmentFieldArray[]=
{
	{	PG_EDGEACLINESEGMENT_SUBSTATION,		"Substation",		"��վ",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_VOLTAGELEVEL,		"VoltageLevel",		"��ѹ�ȼ�",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_CONNECTIVITYNODE,	"ConnectivityNode",	"�ڵ�",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_NAME,				"Name",				"����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_ACLINESEGMENTPTR,	"ACLineSegmentPtr",	"������·������",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDCLineSegmentFieldArray[]=
{
	{	PG_EDGEDCLINESEGMENT_SUBSTATION,		"Substation",		"��վ",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_VOLTAGELEVEL,		"VoltageLevel",		"��ѹ�ȼ�",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_CONNECTIVITYNODE,	"ConnectivityNode",	"�ڵ�",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_NAME,				"Name",				"����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_DCLINESEGMENTPTR,	"DCLineSegmentPtr",	"ֱ����·������",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeTransformerWindingFieldArray[]=
{
	{	PG_EDGETRANSFORMERWINDING_SUBSTATION,				"Substation",				"��վ",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_VOLTAGELEVEL,				"VoltageLevel",				"��ѹ�ȼ�",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_CONNECTIVITYNODE,			"ConnectivityNode",			"�ڵ�",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_NAME,						"Name",						"����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_TRANSFORMERWINGINGPTR,	"TransformerWindingPtr",	"��ѹ����������",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeSeriesCompensatorFieldArray[]=
{
	{	PG_EDGESERIESCOMPENSATOR_SUBSTATION,				"Substation",				"��վ",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_VOLTAGELEVEL,				"VoltageLevel",				"��ѹ�ȼ�",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_CONNECTIVITYNODE,			"ConnectivityNode",			"�ڵ�",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_NAME,						"Name",						"����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_SERIESCOMPENSATORPTR,		"SeriesCompensatorPtr",		"��������",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeBreakerFieldArray[]=
{
	{	PG_EDGEBREAKER_SUBSTATION,							"Substation",				"��վ",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEBREAKER_VOLTAGELEVEL,						"VoltageLevel",				"��ѹ�ȼ�",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEBREAKER_CONNECTIVITYNODE,					"ConnectivityNode",			"�ڵ�",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEBREAKER_NAME,								"Name",						"����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEBREAKER_BREAKERPTR,							"BreakerPtr",				"��������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDisconnectorFieldArray[]=
{
	{	PG_EDGEDISCONNECTOR_SUBSTATION,						"Substation",				"��վ",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_VOLTAGELEVEL,					"VoltageLevel",				"��ѹ�ȼ�",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_CONNECTIVITYNODE,				"ConnectivityNode",			"�ڵ�",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_NAME,							"Name",						"����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_DISCONNECTORPTR,				"DisconnectorPtr",			"���뿪������",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeADConverterFieldArray[]=
{
	{	PG_EDGEADCONVERTER_SUBSTATION,						"Substation",				"��վ",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEADCONVERTER_VOLTAGELEVEL,					"VoltageLevel",				"��ѹ�ȼ�",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEADCONVERTER_CONNECTIVITYNODE,				"ConnectivityNode",			"�ڵ�",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEADCONVERTER_NAME,							"Name",						"����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEADCONVERTER_ADCONVERTERPTR,					"ADConverterPtr",			"��ֱ�任������",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDDConverterFieldArray[]=
{
	{	PG_EDGEDDCONVERTER_SUBSTATION,						"Substation",				"��վ",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDDCONVERTER_VOLTAGELEVEL,					"VoltageLevel",				"��ѹ�ȼ�",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDDCONVERTER_CONNECTIVITYNODE,				"ConnectivityNode",			"�ڵ�",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDDCONVERTER_NAME,							"Name",						"����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDDCONVERTER_DDCONVERTERPTR,					"DDConverterPtr",			"ֱֱ����������",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDCBreakerFieldArray[]=
{
	{	PG_EDGEDCBREAKER_SUBSTATION,						"Substation",				"��վ",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCBREAKER_VOLTAGELEVEL,						"VoltageLevel",				"��ѹ�ȼ�",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDCBREAKER_CONNECTIVITYNODE,					"ConnectivityNode",			"�ڵ�",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCBREAKER_NAME,								"Name",						"����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCBREAKER_DCBREAKERPTR,						"DCBreakerPtr",				"ֱ����·������",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDCShortCircuitLimitFieldArray[]=
{
	{	PG_EDGEDCSHORTCIRCUITLIMIT_SUBSTATION,				"Substation",				"��վ",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_VOLTAGELEVEL,			"VoltageLevel",				"��ѹ�ȼ�",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_CONNECTIVITYNODE,		"ConnectivityNode",			"�ڵ�",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_NAME,					"Name",						"����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_DCSHORTCIRCUITLIMITPTR,	"DCShortCircuitLimitPtr",	"ֱ����·��������������",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGIslandFieldArray[]=
{
	{	PG_ISLAND_SLACKSUB,				"SlackSub",			"��ƽ���豸��վ",	MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PG_ISLAND_SLACKDEVNAME,			"SlackDevName",		"��ƽ���豸����",	MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_ISLAND_SLACKDEVTYPE,			"SlackDevType",		"��ƽ���豸����",	MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_GENP,					"GenP",				"�������й�(����)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_GENQ,					"GenQ",				"�������޹�(�׷�)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOADP,				"LoadP",			"�������й�(����)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOADQ,				"LoadQ",			"�������޹�(�׷�)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_SHUNTQ,				"ShuntQ",			"�������޹�(�׷�)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOSSP,				"LossP",			"������й�(�׷�)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOSSQ,				"LossQ",			"������޹�(�׷�)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_ISLAND_GENNUM,				"GenNum",			"���ڷ������",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_LOADNUM,				"LoadNum",			"���ڸ���",			MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_CAPNUM,				"CapNum",			"���ڲ�����",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_SREACNUM,				"SReacNum",			"���ڴ�����",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ACBUSNUM,				"ACBusNum",			"���ڽ���ĸ����",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ACLINENUM,			"ACLineNum",		"���ڽ�����·��",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_WINDNUM,				"TranNum",			"����������",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PG_ISLAND_WTNUM,				"WTNum",			"���ڷ����",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_PVNUM,				"PVNum",			"���ڹ����",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_EVNUM,				"EVNum",			"���ڵ綯������",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ECSNUM,				"ECSNum",			"���ڵ绯ѧ������",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_STMNUM,				"STMNum",			"���ڹ��ȷ�����",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PG_ISLAND_DCBUSNUM,				"DCBusNum",			"����ֱ��ĸ����",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_DCLINENUM,			"DCLineNum",		"����ֱ����·��",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ADCONVERTERNUM,		"ADConverterNum",	"���ڽ�ֱ�任����",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_DDCONVERTERNUM,		"DDConverterNum",	"����ֱֱ�任����",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_DCFCLNUM,				"DCFCLNum",			"����ֱ��FCL��",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PG_ISLAND_DEAD,					"Dead",				"������־",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_ISLAND_DCISLAND,				"DCIsland",			"ֱ���絺",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_ISLAND_PFCONVERGENCY,		"PFConvergency",	"����������־",		MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_ISLAND_DEVPTR,				"DevPtr",			"�豸����",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_TYPE,					"Type",				"������",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PGEnumIslandType)/sizeof(tagMemDBEnumPair),					g_PGEnumIslandType,	},
};

static	tagMemDBField	g_PGTopoBusFieldArray[]=
{
	{	PG_TOPOBUS_ISLAND,				"Island",			"��",							MDBFieldCategoryTopo,	MDB_SHORT,	sizeof(short),	0,	NULL,	},
	{	PG_TOPOBUS_GENP,				"GenP",				"�й�����(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_GENQ,				"GenQ",				"�޹�����(�׷�)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_LOADP,				"LoadP",			"�й�����(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_LOADQ,				"LoadQ",			"�޹�����(�׷�)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SHUNTQ,				"ShuntQ",			"�����޹�(�׷�)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_V,					"V",				"��ѹ(ǧ��)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),	0,	NULL,	},
	{	PG_TOPOBUS_D,					"D",				"����(��)",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),	0,	NULL,	},
	{	PG_TOPOBUS_SCR1,				"ScR1",				"�����ֵ����(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCX1,				"ScX1",				"�����ֵ�翹(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCR2,				"ScR2",				"�����ֵ����(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCX2,				"ScX2",				"�����ֵ�翹(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCR0,				"ScR0",				"�����ֵ����(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCX0,				"ScX0",				"�����ֵ�翹(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI1RE,				"ScI1Re",			"�����·����ʵ��(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI1IM,				"ScI1Im",			"�����·�����鲿(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI2RE,				"ScI2Re",			"�����·����ʵ��(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI2IM,				"ScI2Im",			"�����·�����鲿(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI0RE,				"ScI0Re",			"�����·����ʵ��(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI0IM,				"ScI0Im",			"�����·�����鲿(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV1RE,				"ScV1Re",			"�����·��ѹʵ��(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV1IM,				"ScV1Im",			"�����·��ѹ�鲿(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV2RE,				"ScV2Re",			"�����·��ѹʵ��(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV2IM,				"ScV2Im",			"�����·��ѹ�鲿(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV0RE,				"ScV0Re",			"�����·��ѹʵ��(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV0IM,				"ScV0Im",			"�����·��ѹ�鲿(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_VDIPNUM,				"VDipNum",			"��ĸ�߹�������ĵ�ѹ�ݽ���",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),	0,	NULL,	},
	{	PG_TOPOBUS_VOLTPTR,				"VoltPtr",			"��ѹ�ȼ�����",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),	0,	NULL,	},
};
