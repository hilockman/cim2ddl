#pragma once

static	tagMemDBField	g_PGTerminalFieldArray[]=
{
	{	PG_TERMINAL_RESOURCEID,						"ResourceID",			"资源Id",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_TERMINAL_SUBSTATION,						"Substation",			"厂站",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_TERMINAL_VOLTAGELEVEL,					"VoltageLevel",			"电压等级",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_TERMINAL_NAME,							"Name",					"名称",			MDBFieldCategoryBase,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_TERMINAL_CONNECTIVITYNODE,				"ConnectivityNode",		"节点",			MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
};

static	tagMemDBField	g_PGConnectivityNodeFieldArray[]=
{
	{	PG_CONNECTIVITYNODE_SUBSTATION,					"Substation",				"厂站",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_VOLTAGELEVEL,				"VoltageLevel",				"电压等级",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_CONNECTIVITYNODE_NAME,						"Name",						"名称",						MDBFieldCategoryBase,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_ACLINESEGMENTRANGE,			"ACLineSegmentRange",		"交流线路段范围",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DCLINESEGMENTRANGE,			"DCLineSegmentRange",		"直流线路段范围",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_TRANSFORMERWINDINGRANGE,	"TransformerWindingRange",	"变压器绕组范围",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_SERIESCOMPENSATORRANGE,		"SeriesCompensatorRange",	"串联补偿范围",				MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_BREAKERRANGE,				"BreakerRange",				"断路器范围",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DISCONNECTORRANGE,			"DisconnectorRange",		"隔离开关范围",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_ADCONVERTERRANGE,			"ADConverterRange",			"交直变换器范围",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DDCONVERTERRANGE,			"DDConverterRange",			"直直变换器范围",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DCBREAKERRANGE,				"DCBreakerRange",			"直流断路器范围",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_DCSHORTCIRCUITLIMITRANGE,	"DCShortCircuitLimitRange",	"直流短路电流限制器范围",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_VOLTAGELEVELPTR,			"VoltageLevelPtr",			"电压等级索引",				MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_BUSBARSECTIONPTR,			"BusbarSectionPtr",			"母线索引",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_TOPOBUS,					"TopoBus",					"拓扑节点",					MDBFieldCategoryTopo,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_ISLAND,						"Island",					"岛",						MDBFieldCategoryTopo,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_SA_ABILITY,					"sa_Ability",				"节点转电能力(兆瓦)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_INRING,						"InRing",					"环网标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_CONNECTIVITYNODE_RADIATE,					"Radiate",					"辐射网号",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_CONNECTIVITYNODE_OPEN,						"Open",						"拓扑状态",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_CONNECTIVITYNODE_TMID,						"TMid"	,					"变压器中点",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeACLineSegmentFieldArray[]=
{
	{	PG_EDGEACLINESEGMENT_SUBSTATION,		"Substation",		"厂站",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_VOLTAGELEVEL,		"VoltageLevel",		"电压等级",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_CONNECTIVITYNODE,	"ConnectivityNode",	"节点",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_NAME,				"Name",				"名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEACLINESEGMENT_ACLINESEGMENTPTR,	"ACLineSegmentPtr",	"交流线路段索引",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDCLineSegmentFieldArray[]=
{
	{	PG_EDGEDCLINESEGMENT_SUBSTATION,		"Substation",		"厂站",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_VOLTAGELEVEL,		"VoltageLevel",		"电压等级",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_CONNECTIVITYNODE,	"ConnectivityNode",	"节点",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_NAME,				"Name",				"名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCLINESEGMENT_DCLINESEGMENTPTR,	"DCLineSegmentPtr",	"直流线路段索引",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeTransformerWindingFieldArray[]=
{
	{	PG_EDGETRANSFORMERWINDING_SUBSTATION,				"Substation",				"厂站",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_VOLTAGELEVEL,				"VoltageLevel",				"电压等级",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_CONNECTIVITYNODE,			"ConnectivityNode",			"节点",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_NAME,						"Name",						"名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGETRANSFORMERWINDING_TRANSFORMERWINGINGPTR,	"TransformerWindingPtr",	"变压器绕组索引",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeSeriesCompensatorFieldArray[]=
{
	{	PG_EDGESERIESCOMPENSATOR_SUBSTATION,				"Substation",				"厂站",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_VOLTAGELEVEL,				"VoltageLevel",				"电压等级",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_CONNECTIVITYNODE,			"ConnectivityNode",			"节点",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_NAME,						"Name",						"名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGESERIESCOMPENSATOR_SERIESCOMPENSATORPTR,		"SeriesCompensatorPtr",		"补偿索引",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeBreakerFieldArray[]=
{
	{	PG_EDGEBREAKER_SUBSTATION,							"Substation",				"厂站",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEBREAKER_VOLTAGELEVEL,						"VoltageLevel",				"电压等级",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEBREAKER_CONNECTIVITYNODE,					"ConnectivityNode",			"节点",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEBREAKER_NAME,								"Name",						"名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEBREAKER_BREAKERPTR,							"BreakerPtr",				"开关索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDisconnectorFieldArray[]=
{
	{	PG_EDGEDISCONNECTOR_SUBSTATION,						"Substation",				"厂站",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_VOLTAGELEVEL,					"VoltageLevel",				"电压等级",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_CONNECTIVITYNODE,				"ConnectivityNode",			"节点",				MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_NAME,							"Name",						"名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDISCONNECTOR_DISCONNECTORPTR,				"DisconnectorPtr",			"隔离开关索引",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeADConverterFieldArray[]=
{
	{	PG_EDGEADCONVERTER_SUBSTATION,						"Substation",				"厂站",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEADCONVERTER_VOLTAGELEVEL,					"VoltageLevel",				"电压等级",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEADCONVERTER_CONNECTIVITYNODE,				"ConnectivityNode",			"节点",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEADCONVERTER_NAME,							"Name",						"名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEADCONVERTER_ADCONVERTERPTR,					"ADConverterPtr",			"交直变换器索引",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDDConverterFieldArray[]=
{
	{	PG_EDGEDDCONVERTER_SUBSTATION,						"Substation",				"厂站",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDDCONVERTER_VOLTAGELEVEL,					"VoltageLevel",				"电压等级",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDDCONVERTER_CONNECTIVITYNODE,				"ConnectivityNode",			"节点",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDDCONVERTER_NAME,							"Name",						"名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDDCONVERTER_DDCONVERTERPTR,					"DDConverterPtr",			"直直隔离器索引",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDCBreakerFieldArray[]=
{
	{	PG_EDGEDCBREAKER_SUBSTATION,						"Substation",				"厂站",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCBREAKER_VOLTAGELEVEL,						"VoltageLevel",				"电压等级",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDCBREAKER_CONNECTIVITYNODE,					"ConnectivityNode",			"节点",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCBREAKER_NAME,								"Name",						"名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCBREAKER_DCBREAKERPTR,						"DCBreakerPtr",				"直流断路器索引",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGEdgeDCShortCircuitLimitFieldArray[]=
{
	{	PG_EDGEDCSHORTCIRCUITLIMIT_SUBSTATION,				"Substation",				"厂站",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_VOLTAGELEVEL,			"VoltageLevel",				"电压等级",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_CONNECTIVITYNODE,		"ConnectivityNode",			"节点",						MDBFieldCategoryTopo,	MDB_STRING,	PGND_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_NAME,					"Name",						"名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_EDGEDCSHORTCIRCUITLIMIT_DCSHORTCIRCUITLIMITPTR,	"DCShortCircuitLimitPtr",	"直流短路电流限制器索引",	MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGIslandFieldArray[]=
{
	{	PG_ISLAND_SLACKSUB,				"SlackSub",			"岛平衡设备厂站",	MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PG_ISLAND_SLACKDEVNAME,			"SlackDevName",		"岛平衡设备名称",	MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_ISLAND_SLACKDEVTYPE,			"SlackDevType",		"岛平衡设备类型",	MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_GENP,					"GenP",				"岛发电有功(兆瓦)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_GENQ,					"GenQ",				"岛发电无功(兆乏)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOADP,				"LoadP",			"岛负荷有功(兆瓦)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOADQ,				"LoadQ",			"岛负荷无功(兆乏)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_SHUNTQ,				"ShuntQ",			"岛并联无功(兆乏)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOSSP,				"LossP",			"岛损耗有功(兆乏)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_ISLAND_LOSSQ,				"LossQ",			"岛损耗无功(兆乏)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_ISLAND_GENNUM,				"GenNum",			"岛内发电机数",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_LOADNUM,				"LoadNum",			"岛内负荷",			MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_CAPNUM,				"CapNum",			"岛内并补数",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_SREACNUM,				"SReacNum",			"岛内串补数",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ACBUSNUM,				"ACBusNum",			"岛内交流母线数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ACLINENUM,			"ACLineNum",		"岛内交流线路数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_WINDNUM,				"TranNum",			"岛内主变数",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PG_ISLAND_WTNUM,				"WTNum",			"岛内风机数",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_PVNUM,				"PVNum",			"岛内光伏数",		MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_EVNUM,				"EVNum",			"岛内电动汽车数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ECSNUM,				"ECSNum",			"岛内电化学储能数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_STMNUM,				"STMNum",			"岛内光热发电数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PG_ISLAND_DCBUSNUM,				"DCBusNum",			"岛内直流母线数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_DCLINENUM,			"DCLineNum",		"岛内直流线路数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_ADCONVERTERNUM,		"ADConverterNum",	"岛内交直变换器数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_DDCONVERTERNUM,		"DDConverterNum",	"岛内直直变换器数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_DCFCLNUM,				"DCFCLNum",			"岛内直流FCL数",	MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PG_ISLAND_DEAD,					"Dead",				"死岛标志",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_ISLAND_DCISLAND,				"DCIsland",			"直流电岛",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_ISLAND_PFCONVERGENCY,		"PFConvergency",	"潮流收敛标志",		MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_ISLAND_DEVPTR,				"DevPtr",			"设备索引",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_ISLAND_TYPE,					"Type",				"岛类型",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PGEnumIslandType)/sizeof(tagMemDBEnumPair),					g_PGEnumIslandType,	},
};

static	tagMemDBField	g_PGTopoBusFieldArray[]=
{
	{	PG_TOPOBUS_ISLAND,				"Island",			"岛",							MDBFieldCategoryTopo,	MDB_SHORT,	sizeof(short),	0,	NULL,	},
	{	PG_TOPOBUS_GENP,				"GenP",				"有功发电(兆瓦)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_GENQ,				"GenQ",				"无功发电(兆乏)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_LOADP,				"LoadP",			"有功负荷(兆瓦)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_LOADQ,				"LoadQ",			"无功负荷(兆乏)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SHUNTQ,				"ShuntQ",			"并联无功(兆乏)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_V,					"V",				"电压(千伏)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),	0,	NULL,	},
	{	PG_TOPOBUS_D,					"D",				"功角(度)",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),	0,	NULL,	},
	{	PG_TOPOBUS_SCR1,				"ScR1",				"正序等值电阻(标幺)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCX1,				"ScX1",				"正序等值电抗(标幺)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCR2,				"ScR2",				"负序等值电阻(标幺)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCX2,				"ScX2",				"负序等值电抗(标幺)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCR0,				"ScR0",				"零序等值电阻(标幺)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCX0,				"ScX0",				"零序等值电抗(标幺)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI1RE,				"ScI1Re",			"正序短路电流实部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI1IM,				"ScI1Im",			"正序短路电流虚部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI2RE,				"ScI2Re",			"负序短路电流实部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI2IM,				"ScI2Im",			"负序短路电流虚部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI0RE,				"ScI0Re",			"零序短路电流实部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCI0IM,				"ScI0Im",			"零序短路电流虚部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV1RE,				"ScV1Re",			"正序短路电压实部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV1IM,				"ScV1Im",			"正序短路电压虚部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV2RE,				"ScV2Re",			"负序短路电压实部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV2IM,				"ScV2Im",			"负序短路电压虚部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV0RE,				"ScV0Re",			"零序短路电压实部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_SCV0IM,				"ScV0Im",			"零序短路电压虚部(标幺)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),	0,	NULL,	},
	{	PG_TOPOBUS_VDIPNUM,				"VDipNum",			"因母线故障引起的电压暂降数",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),	0,	NULL,	},
	{	PG_TOPOBUS_VOLTPTR,				"VoltPtr",			"电压等级索引",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),	0,	NULL,	},
};
