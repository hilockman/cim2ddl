#pragma once

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Terminal_	{
	PG_TERMINAL_RESOURCEID=0,
	PG_TERMINAL_SUBSTATION,
	PG_TERMINAL_VOLTAGELEVEL,
	PG_TERMINAL_NAME,
	PG_TERMINAL_CONNECTIVITYNODE,
};
struct	_PG_Terminal_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[PGND_CHARLEN];
	char	szNode[PGND_CHARLEN];
}	DISALIGN;
typedef	struct	_PG_Terminal_	tagPGTerminal;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ConnectivityNode_	{
	PG_CONNECTIVITYNODE_SUBSTATION=0,
	PG_CONNECTIVITYNODE_VOLTAGELEVEL,
	PG_CONNECTIVITYNODE_NAME,
	PG_CONNECTIVITYNODE_ACLINESEGMENTRANGE,
	PG_CONNECTIVITYNODE_DCLINESEGMENTRANGE,
	PG_CONNECTIVITYNODE_TRANSFORMERWINDINGRANGE,
	PG_CONNECTIVITYNODE_SERIESCOMPENSATORRANGE,
	PG_CONNECTIVITYNODE_BREAKERRANGE,
	PG_CONNECTIVITYNODE_DISCONNECTORRANGE,

	PG_CONNECTIVITYNODE_ADCONVERTERRANGE,
	PG_CONNECTIVITYNODE_DDCONVERTERRANGE,
	PG_CONNECTIVITYNODE_DCBREAKERRANGE,
	PG_CONNECTIVITYNODE_DCSHORTCIRCUITLIMITRANGE,

	PG_CONNECTIVITYNODE_VOLTAGELEVELPTR,
	PG_CONNECTIVITYNODE_BUSBARSECTIONPTR,

	PG_CONNECTIVITYNODE_TOPOBUS,
	PG_CONNECTIVITYNODE_ISLAND,
	PG_CONNECTIVITYNODE_SA_ABILITY,
	PG_CONNECTIVITYNODE_INRING,
	PG_CONNECTIVITYNODE_RADIATE,
	PG_CONNECTIVITYNODE_OPEN,
	PG_CONNECTIVITYNODE_TMID,
};
struct	_PG_ConnectivityNode_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[PGND_CHARLEN];
	int		nACLineSegmentRange;
	short	nDCLineSegmentRange;
	int		nTransformerWindingRange;
	short	nSeriesCompensatorRange;
	int		nBreakerRange;
	int		nDisconnectorRange;

	short	nADConverterRange;
	short	nDDConverterRange;
	short	nDCBreakerRange;
	short	nDCShortCircuitLimitRange;

	short	nVoltageLevelPtr;
	short	nBusbarSectionPtr;

	int		nTopoBus;
	short	nIsland;
	float	sa_Ability;
	unsigned char	bInRing;
	short	nRadiate;
	unsigned char	bOpen;
	unsigned char	bTNode;
}	DISALIGN;
typedef	struct	_PG_ConnectivityNode_	tagPGConnectivityNode;

//	派生表定义
enum	_PGEnum_Field_EdgeACLineSegment_	{
	PG_EDGEACLINESEGMENT_SUBSTATION=0,
	PG_EDGEACLINESEGMENT_VOLTAGELEVEL,
	PG_EDGEACLINESEGMENT_CONNECTIVITYNODE,
	PG_EDGEACLINESEGMENT_NAME,
	PG_EDGEACLINESEGMENT_ACLINESEGMENTPTR,
};
struct	_PG_EdgeACLineSegment_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nACLineSegment;
}	DISALIGN;
typedef	struct	_PG_EdgeACLineSegment_	tagPGEdgeACLineSegment;

enum	_PGEnum_Field_EdgeDCLineSegment_	{
	PG_EDGEDCLINESEGMENT_SUBSTATION=0,
	PG_EDGEDCLINESEGMENT_VOLTAGELEVEL,
	PG_EDGEDCLINESEGMENT_CONNECTIVITYNODE,
	PG_EDGEDCLINESEGMENT_NAME,
	PG_EDGEDCLINESEGMENT_DCLINESEGMENTPTR,
};
struct	_PG_EdgeDCLineSegment_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nDCLineSegment;
}	DISALIGN;
typedef	struct	_PG_EdgeDCLineSegment_	tagPGEdgeDCLineSegment;

enum	_PGEnum_Field_EdgeTransformerWinding_	{
	PG_EDGETRANSFORMERWINDING_SUBSTATION=0,
	PG_EDGETRANSFORMERWINDING_VOLTAGELEVEL,
	PG_EDGETRANSFORMERWINDING_CONNECTIVITYNODE,
	PG_EDGETRANSFORMERWINDING_NAME,
	PG_EDGETRANSFORMERWINDING_TRANSFORMERWINGINGPTR,
};
struct	_PG_EdgeTransformerWinding_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nTransformerWinding;
}	DISALIGN;
typedef	struct	_PG_EdgeTransformerWinding_	tagPGEdgeTransformerWinding;

enum	_PGEnum_Field_EdgeSeriesCompensator_	{
	PG_EDGESERIESCOMPENSATOR_SUBSTATION=0,
	PG_EDGESERIESCOMPENSATOR_VOLTAGELEVEL,
	PG_EDGESERIESCOMPENSATOR_CONNECTIVITYNODE,
	PG_EDGESERIESCOMPENSATOR_NAME,
	PG_EDGESERIESCOMPENSATOR_SERIESCOMPENSATORPTR,
};
struct	_PG_EdgeSeriesCompensator_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nSeriesCompensator;
}	DISALIGN;
typedef	struct	_PG_EdgeSeriesCompensator_	tagPGEdgeSeriesCompensator;

enum	_PGEnum_Field_EdgeBreaker_	{
	PG_EDGEBREAKER_SUBSTATION=0,
	PG_EDGEBREAKER_VOLTAGELEVEL,
	PG_EDGEBREAKER_CONNECTIVITYNODE,
	PG_EDGEBREAKER_NAME,
	PG_EDGEBREAKER_BREAKERPTR,
};
struct	_PG_EdgeBreaker_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	int		nBreaker;
}	DISALIGN;
typedef	struct	_PG_EdgeBreaker_	tagPGEdgeBreaker;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_EdgeDisconnector_	{
	PG_EDGEDISCONNECTOR_SUBSTATION=0,
	PG_EDGEDISCONNECTOR_VOLTAGELEVEL,
	PG_EDGEDISCONNECTOR_CONNECTIVITYNODE,
	PG_EDGEDISCONNECTOR_NAME,
	PG_EDGEDISCONNECTOR_DISCONNECTORPTR,
};
struct	_PG_EdgeDisconnector_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	int		nDisconnector;
}	DISALIGN;
typedef	struct	_PG_EdgeDisconnector_	tagPGEdgeDisconnector;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_EdgeACDCConverter_	{
	PG_EDGEADCONVERTER_SUBSTATION=0,
	PG_EDGEADCONVERTER_VOLTAGELEVEL,
	PG_EDGEADCONVERTER_CONNECTIVITYNODE,
	PG_EDGEADCONVERTER_NAME,
	PG_EDGEADCONVERTER_ADCONVERTERPTR,
};
struct	_PG_EdgeACDCConverter_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nConverter;
}	DISALIGN;
typedef	struct	_PG_EdgeACDCConverter_	tagPGEdgeADConverter;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_EdgeDCDCConverter_	{
	PG_EDGEDDCONVERTER_SUBSTATION=0,
	PG_EDGEDDCONVERTER_VOLTAGELEVEL,
	PG_EDGEDDCONVERTER_CONNECTIVITYNODE,
	PG_EDGEDDCONVERTER_NAME,
	PG_EDGEDDCONVERTER_DDCONVERTERPTR,
};
struct	_PG_EdgeDCDCConverter_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nConverter;
}	DISALIGN;
typedef	struct	_PG_EdgeDCDCConverter_	tagPGEdgeDDConverter;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_EdgeDCBreaker_	{
	PG_EDGEDCBREAKER_SUBSTATION=0,
	PG_EDGEDCBREAKER_VOLTAGELEVEL,
	PG_EDGEDCBREAKER_CONNECTIVITYNODE,
	PG_EDGEDCBREAKER_NAME,
	PG_EDGEDCBREAKER_DCBREAKERPTR,
};
struct	_PG_EdgeDCBreaker_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nDCBreaker;
}	DISALIGN;
typedef	struct	_PG_EdgeDCBreaker_	tagPGEdgeDCBreaker;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_EdgeDCShortCircuitLimit_	{
	PG_EDGEDCSHORTCIRCUITLIMIT_SUBSTATION=0,
	PG_EDGEDCSHORTCIRCUITLIMIT_VOLTAGELEVEL,
	PG_EDGEDCSHORTCIRCUITLIMIT_CONNECTIVITYNODE,
	PG_EDGEDCSHORTCIRCUITLIMIT_NAME,
	PG_EDGEDCSHORTCIRCUITLIMIT_DCSHORTCIRCUITLIMITPTR,
};
struct	_PG_EdgeDCShortCircuitLimit_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nDCShortCircuitLimit;
}	DISALIGN;
typedef	struct	_PG_EdgeDCShortCircuitLimit_	tagPGEdgeDCShortCircuitLimit;

enum	_PGEnum_Field_Island_	{
	PG_ISLAND_SLACKSUB=0,
	PG_ISLAND_SLACKDEVNAME,
	PG_ISLAND_SLACKDEVTYPE,
	PG_ISLAND_GENP,
	PG_ISLAND_GENQ,
	PG_ISLAND_LOADP,
	PG_ISLAND_LOADQ,
	PG_ISLAND_SHUNTQ,
	PG_ISLAND_LOSSP,
	PG_ISLAND_LOSSQ,

	PG_ISLAND_GENNUM,
	PG_ISLAND_LOADNUM,
	PG_ISLAND_CAPNUM,
	PG_ISLAND_SREACNUM,
	PG_ISLAND_ACBUSNUM,
	PG_ISLAND_ACLINENUM,
	PG_ISLAND_WINDNUM,

	PG_ISLAND_WTNUM,
	PG_ISLAND_PVNUM,
	PG_ISLAND_EVNUM,
	PG_ISLAND_ECSNUM,
	PG_ISLAND_STMNUM,

	PG_ISLAND_DCBUSNUM,
	PG_ISLAND_DCLINENUM,
	PG_ISLAND_ADCONVERTERNUM,
	PG_ISLAND_DDCONVERTERNUM,
	PG_ISLAND_DCFCLNUM,

	PG_ISLAND_DEAD,
	PG_ISLAND_DCISLAND,
	PG_ISLAND_PFCONVERGENCY,
	PG_ISLAND_DEVPTR,
	PG_ISLAND_TYPE,
};

struct	_PG_Island_	{
	char	szSlackSub[MDB_CHARLEN_SHORT];
	char	szSlackDevName[MDB_CHARLEN];
	short	nSlackDevType;
	float	fGenP;
	float	fGenQ;
	float	fLoadP;
	float	fLoadQ;
	float	fShuntQ;
	float	fLossP;
	float	fLossQ;
	short	nGenNum;
	short	nLoadNum;
	short	nCapNum;
	short	nSReacNum;
	short	nACBusNum;
	short	nACLineNum;
	short	nWindNum;

	short	nWTNum;
	short	nPVNum;
	short	nEVNum;
	short	nECSNum;
	short	nSTMNum;

	short	nDCBusNum;
	short	nDCLineNum;
	short	nADConverterNum;
	short	nDDConverterNum;
	short	nDCFCLNum;

	unsigned char	bDead;
	unsigned char	bDCIsland;
	unsigned char	bPFConvergency;
	short	nSlackDev;		//	参考发电机索引
	unsigned char	nType;
}	DISALIGN;
typedef	struct	_PG_Island_	tagPGIsland;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_TopoBus_	{
	PG_TOPOBUS_ISLAND=0,
	PG_TOPOBUS_GENP,
	PG_TOPOBUS_GENQ,
	PG_TOPOBUS_LOADP,
	PG_TOPOBUS_LOADQ,
	PG_TOPOBUS_SHUNTQ,
	PG_TOPOBUS_V,
	PG_TOPOBUS_D,

	PG_TOPOBUS_SCR1,
	PG_TOPOBUS_SCX1,
	PG_TOPOBUS_SCR2,
	PG_TOPOBUS_SCX2,
	PG_TOPOBUS_SCR0,
	PG_TOPOBUS_SCX0,

	PG_TOPOBUS_SCI1RE,
	PG_TOPOBUS_SCI1IM,
	PG_TOPOBUS_SCI2RE,
	PG_TOPOBUS_SCI2IM,
	PG_TOPOBUS_SCI0RE,
	PG_TOPOBUS_SCI0IM,
	PG_TOPOBUS_SCV1RE,
	PG_TOPOBUS_SCV1IM,
	PG_TOPOBUS_SCV2RE,
	PG_TOPOBUS_SCV2IM,
	PG_TOPOBUS_SCV0RE,
	PG_TOPOBUS_SCV0IM,

	PG_TOPOBUS_VDIPNUM,
	PG_TOPOBUS_VOLTPTR,
};

struct	_PG_TopoBus_	{
	short	nIsland;
	float	fGenP;
	float	fGenQ;
	float	fLoadP;
	float	fLoadQ;
	float	fShuntQ;
	double	fV;
	double	fD;

	float	fSccR1;
	float	fSccX1;
	float	fSccR2;
	float	fSccX2;
	float	fSccR0;
	float	fSccX0;

	float	fScI1Re;
	float	fScI1Im;
	float	fScI2Re;
	float	fScI2Im;
	float	fScI0Re;
	float	fScI0Im;

	float	fScV1Re;
	float	fScV1Im;
	float	fScV2Re;
	float	fScV2Im;
	float	fScV0Re;
	float	fScV0Im;

	int		nVDipNum;
	short	nVolt;
}	DISALIGN;
typedef	struct	_PG_TopoBus_	tagPGTopoBus;
