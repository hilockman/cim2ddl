#pragma once


//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Tieline_	{
	PG_TIELINE_NAME=0,
	PG_TIELINE_ICOMPANY,
	PG_TIELINE_ISUBCONTROLAREA,
	PG_TIELINE_ISUBSTATION,
	PG_TIELINE_IVOLTAGELEVEL,
	PG_TIELINE_ZCOMPANY,
	PG_TIELINE_ZSUBCONTROLAREA,
	PG_TIELINE_JSUBSTATION,
	PG_TIELINE_JVOLTAGELEVEL,
	PG_TIELINE_CONNECTIVITYNODE,
};
struct	_PG_Tieline_	{
	char	szName				[MDB_CHARLEN];
	char	szCompanyI			[MDB_CHARLEN_SHORT];
	char	szSubcontrolAreaI	[MDB_CHARLEN_SHORT];
	char	szSubI				[MDB_CHARLEN];
	char	szVoltI				[MDB_CHARLEN_SHORTER];
	char	szCompanyZ			[MDB_CHARLEN_SHORT];
	char	szSubcontrolAreaZ	[MDB_CHARLEN_SHORT];
	char	szSubJ				[MDB_CHARLEN];
	char	szVoltJ				[MDB_CHARLEN_SHORTER];
	char	szNode				[PGND_CHARLEN];
}	DISALIGN;
typedef	struct	_PG_Tieline_	tagPGTieLine;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_SystemReliable	{
	PG_SYSTEMRELIABLE_STEP=0,
	PG_SYSTEMRELIABLE_RO_ACI,
	PG_SYSTEMRELIABLE_RO_CID,
	PG_SYSTEMRELIABLE_RO_SAIFI,
	PG_SYSTEMRELIABLE_RO_SAIDI,
	PG_SYSTEMRELIABLE_RO_ASAI,
	PG_SYSTEMRELIABLE_RO_ENS,
	PG_SYSTEMRELIABLE_RO_AENS,
	PG_SYSTEMRELIABLE_RO_MIC,
	PG_SYSTEMRELIABLE_RO_MID,
	PG_SYSTEMRELIABLE_RO_F_ACI,
	PG_SYSTEMRELIABLE_RO_F_CID,
	PG_SYSTEMRELIABLE_RO_F_SAIFI,
	PG_SYSTEMRELIABLE_RO_F_SAIDI,
	PG_SYSTEMRELIABLE_RO_F_ASAI,
	PG_SYSTEMRELIABLE_RO_F_ENS,
	PG_SYSTEMRELIABLE_RO_F_AENS,
	PG_SYSTEMRELIABLE_RO_F_MIC,
	PG_SYSTEMRELIABLE_RO_F_MID,
	PG_SYSTEMRELIABLE_RO_A_ACI,
	PG_SYSTEMRELIABLE_RO_A_CID,
	PG_SYSTEMRELIABLE_RO_A_SAIFI,
	PG_SYSTEMRELIABLE_RO_A_SAIDI,
	PG_SYSTEMRELIABLE_RO_A_ASAI,
	PG_SYSTEMRELIABLE_RO_A_ENS,
	PG_SYSTEMRELIABLE_RO_A_AENS,
	PG_SYSTEMRELIABLE_RO_A_MIC,
	PG_SYSTEMRELIABLE_RO_A_MID,
};
struct	_PGO_SystemReliable_	{
	short	nStep;

	double	ro_aci;
	double	ro_cid;
	double	ro_saifi;
	double	ro_saidi;
	double	ro_asai;
	double	ro_ens;
	double	ro_aens;
	double	ro_mic;
	double	ro_mid;
	double	ro_f_aci;
	double	ro_f_cid;
	double	ro_f_saifi;
	double	ro_f_saidi;
	double	ro_f_asai;
	double	ro_f_ens;
	double	ro_f_aens;
	double	ro_f_mic;
	double	ro_f_mid;
	double	ro_a_aci;
	double	ro_a_cid;
	double	ro_a_saifi;
	double	ro_a_saidi;
	double	ro_a_asai;
	double	ro_a_ens;
	double	ro_a_aens;
	double	ro_a_mic;
	double	ro_a_mid;
}	DISALIGN;
typedef	struct	_PGO_SystemReliable_	tagPGSystemReliable;

//////////////////////////////////////////////////////////////////////////
enum	_PGOEnum_Field_EnergyConsumerReliable_	{
	PG_ENERGYCONSUMERRELIABLE_LOAD=0,
	PG_ENERGYCONSUMERRELIABLE_STEP,
	PG_ENERGYCONSUMERRELIABLE_RO_R,
	PG_ENERGYCONSUMERRELIABLE_RO_T,
	PG_ENERGYCONSUMERRELIABLE_RO_U,
	PG_ENERGYCONSUMERRELIABLE_RO_FR,
	PG_ENERGYCONSUMERRELIABLE_RO_FT,
	PG_ENERGYCONSUMERRELIABLE_RO_FU,
	PG_ENERGYCONSUMERRELIABLE_RO_AR,
	PG_ENERGYCONSUMERRELIABLE_RO_AT,
	PG_ENERGYCONSUMERRELIABLE_RO_AU,
	PG_ENERGYCONSUMERRELIABLE_RO_CMR,
	PG_ENERGYCONSUMERRELIABLE_RO_CMT,
	PG_ENERGYCONSUMERRELIABLE_RO_CMU,
};
struct	_PG_EnergyConsumerReliable_	{
	int		nLoad;
	unsigned char	nStep;

	//	可靠性指标
	float	ro_r;
	float	ro_t;
	float	ro_u;
	float	ro_fr;
	float	ro_ft;
	float	ro_fu;
	float	ro_ar;
	float	ro_at;
	float	ro_au;
	float	ro_cmr;
	float	ro_cmt;
	float	ro_cmu;
}	DISALIGN;
typedef	struct	_PG_EnergyConsumerReliable_	tagPGEnergyConsumerReliable;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ConnLine_	{
	PG_CONNLINE_RESOURCEID=0,
	PG_CONNLINE_SUBSTATION,
	PG_CONNLINE_VOLTAGELEVEL,
	PG_CONNLINE_CONNECTIVITYNODE,
};
struct	_PG_ConnLine_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN_SHORT];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
}	DISALIGN;
typedef	struct	_PG_ConnLine_	tagPGConnLine;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_HyperLinks_	{
	PG_HYPERLINKS_RESOURCEID=0,
	PG_HYPERLINKS_LINKNAM,
	PG_HYPERLINKS_LINKGRAPH,
	PG_HYPERLINKS_SHOWBOUND,
};
struct	_PG_HyperLinks_	{
	char	szResID[MDB_CHARLEN];
	char	szLinkName[MDB_CHARLEN_SHORT];
	char	szLinkGraph[MDB_CHARLEN_LONG];
	unsigned char	bShowBound;
}	DISALIGN;
typedef	struct	_PG_HyperLinks_	tagPGHyperLinks;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Drawing_	{
	PG_DRAWING_RESOURCEID=0,
	PG_DRAWING_NAME,
	PG_DRAWING_PATH,
	PG_DRAWING_CREATEDATE,
	PG_DRAWING_CREATETIME,
	PG_DRAWING_MODIFYDATE,
	PG_DRAWING_MODIFYTIME,
	PG_DRAWING_CREATOR,
	PG_DRAWING_MODIFIER,
	PG_DRAWING_REVIEWER,
	PG_DRAWING_APPROVER,
	PG_DRAWING_PROJECT,
	PG_DRAWING_SCHEME,
	PG_DRAWING_VERSION,
};
struct	_PG_Drawing_	{
	char	szResID			[MDB_CHARLEN];
	char	szName			[MDB_CHARLEN];
	char	szPath			[MDB_CHARLEN_LONG];

	int		nCreateDate;
	int		nCreateTime;	//	图形建立时间
	int		nModifyDate;
	int		nModifyTime;	//	图形修改时间
	char	szCreator		[MDB_CHARLEN_SHORT];	//	图形创建人
	char	szModifier		[MDB_CHARLEN_SHORT];	//	图形修改人
	char	szReviewer		[MDB_CHARLEN_SHORT];	//	图形审核人
	char	szApprover		[MDB_CHARLEN_SHORT];	//	图形批准人
	char	szProject		[MDB_CHARLEN_SHORT];	//	图形所属项目
	char	szScheme		[MDB_CHARLEN_SHORT];	//	图形所属项目
	char	szVersion		[MDB_CHARLEN_SHORT];	//	图形版本号
}	DISALIGN;
typedef	struct	_PG_Drawing_	tagPGDrawing;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_GraphLayer_	{
	PG_GRAPHLAYER_DRAWING=0,
	PG_GRAPHLAYER_NAME,
	PG_GRAPHLAYER_COLOR,
	PG_GRAPHLAYER_LINESTYLE,
	PG_GRAPHLAYER_LINEWIDTH,
};
struct	_PG_GraphLayer_	{
	char	szDrawing	[MDB_CHARLEN];
	char	szName		[MDB_CHARLEN];
	int		nColor;
	char	szLineStyle	[MDB_CHARLEN_SHORT];
	float	fLineWidth;
}	DISALIGN;
typedef	struct	_PG_GraphLayer_	tagPGGraphLayer;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_GraphAttr_	{
	PG_GRAPHATTR_DRAWING=0,
	PG_GRAPHATTR_TABLE,
	PG_GRAPHATTR_KEYFIELD,
	PG_GRAPHATTR_PARENTID,
	PG_GRAPHATTR_VISIBLE,
	PG_GRAPHATTR_LAYER,
	PG_GRAPHATTR_FONT,
	PG_GRAPHATTR_COLOR,
	PG_GRAPHATTR_LINESTYLE,
	PG_GRAPHATTR_LINEWIDTH,
	PG_GRAPHATTR_SIZE,
	PG_GRAPHATTR_FLOATPOINT,
	PG_GRAPHATTR_LOCATIONX,
	PG_GRAPHATTR_LOCATIONY,
	PG_GRAPHATTR_HAXISX,
	PG_GRAPHATTR_HAXISY,
	PG_GRAPHATTR_LAXISX,
	PG_GRAPHATTR_LAXISY,
	PG_GRAPHATTR_COLORR,
	PG_GRAPHATTR_COLORG,
	PG_GRAPHATTR_COLORB,
};
struct	_PG_GraphAttr_	{
	char	szDrawing	[MDB_CHARLEN];
	char	szTable		[MDB_CHARLEN_SHORT];
	char	szKeyField	[MDB_CHARLEN_SHORT];
	char	szParentID	[MDB_CHARLEN];
	unsigned char	bVisible;
	char	szLayer		[MDB_CHARLEN_SHORT];
	char	szFont		[MDB_CHARLEN_SHORT];
	int		nColor;
	unsigned char	nLineStyle;
	double	fLineWidth;
	double	fSize;
	unsigned char	nFloatPoint;
	double	fLocationX;
	double	fLocationY;
	double	fHAxisX;
	double	fHAxisY;
	double	fLAxisX;
	double	fLAxisY;
	unsigned char	nColorR;
	unsigned char	nColorG;
	unsigned char	nColorB;
}	DISALIGN;
typedef	struct	_PG_GraphAttr_	tagPGGraphAttr;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_LineVertex_	{
	PG_LINEVERTEX_DRAWING=0,
	PG_LINEVERTEX_TABLE,
	PG_LINEVERTEX_PARENT,
	PG_LINEVERTEX_SERIAL,
	PG_LINEVERTEX_VERTEX_X,
	PG_LINEVERTEX_VERTEX_Y,
};
struct	_PG_LineVertex_	{
	char	szDrawing[MDB_CHARLEN];
	char	szTable[MDB_CHARLEN_SHORT];
	char	szParent[MDB_CHARLEN];
	int		nSerial;
	double	fVertexX;
	double	fVertexY;
}	DISALIGN;
typedef	struct	_PG_LineVertex_	tagPGLineVertex;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_SCCField_FMove_	{
	PG_SCC_FMOVE_FAULTTYPE=0,
	PG_SCC_FMOVE_FAULTLINE,
	PG_SCC_FMOVE_MONLINE,
	PG_SCC_FMOVE_MONBUS,
	PG_SCC_FMOVE_DATATYPE,
	PG_SCC_FMOVE_VALUE000,
	PG_SCC_FMOVE_VALUE001,
	PG_SCC_FMOVE_VALUE002,
	PG_SCC_FMOVE_VALUE003,
	PG_SCC_FMOVE_VALUE004,
	PG_SCC_FMOVE_VALUE005,
	PG_SCC_FMOVE_VALUE006,
	PG_SCC_FMOVE_VALUE007,
	PG_SCC_FMOVE_VALUE008,
	PG_SCC_FMOVE_VALUE009,
	PG_SCC_FMOVE_VALUE010,
	PG_SCC_FMOVE_VALUE011,
	PG_SCC_FMOVE_VALUE012,
	PG_SCC_FMOVE_VALUE013,
	PG_SCC_FMOVE_VALUE014,
	PG_SCC_FMOVE_VALUE015,
	PG_SCC_FMOVE_VALUE016,
	PG_SCC_FMOVE_VALUE017,
	PG_SCC_FMOVE_VALUE018,
	PG_SCC_FMOVE_VALUE019,
	PG_SCC_FMOVE_VALUE020,
	PG_SCC_FMOVE_VALUE021,
	PG_SCC_FMOVE_VALUE022,
	PG_SCC_FMOVE_VALUE023,
	PG_SCC_FMOVE_VALUE024,
	PG_SCC_FMOVE_VALUE025,
	PG_SCC_FMOVE_VALUE026,
	PG_SCC_FMOVE_VALUE027,
	PG_SCC_FMOVE_VALUE028,
	PG_SCC_FMOVE_VALUE029,
	PG_SCC_FMOVE_VALUE030,
	PG_SCC_FMOVE_VALUE031,
	PG_SCC_FMOVE_VALUE032,
	PG_SCC_FMOVE_VALUE033,
	PG_SCC_FMOVE_VALUE034,
	PG_SCC_FMOVE_VALUE035,
	PG_SCC_FMOVE_VALUE036,
	PG_SCC_FMOVE_VALUE037,
	PG_SCC_FMOVE_VALUE038,
	PG_SCC_FMOVE_VALUE039,
	PG_SCC_FMOVE_VALUE040,
	PG_SCC_FMOVE_VALUE041,
	PG_SCC_FMOVE_VALUE042,
	PG_SCC_FMOVE_VALUE043,
	PG_SCC_FMOVE_VALUE044,
	PG_SCC_FMOVE_VALUE045,
	PG_SCC_FMOVE_VALUE046,
	PG_SCC_FMOVE_VALUE047,
	PG_SCC_FMOVE_VALUE048,
	PG_SCC_FMOVE_VALUE049,
	PG_SCC_FMOVE_VALUE050,
	PG_SCC_FMOVE_VALUE051,
	PG_SCC_FMOVE_VALUE052,
	PG_SCC_FMOVE_VALUE053,
	PG_SCC_FMOVE_VALUE054,
	PG_SCC_FMOVE_VALUE055,
	PG_SCC_FMOVE_VALUE056,
	PG_SCC_FMOVE_VALUE057,
	PG_SCC_FMOVE_VALUE058,
	PG_SCC_FMOVE_VALUE059,
	PG_SCC_FMOVE_VALUE060,
	PG_SCC_FMOVE_VALUE061,
	PG_SCC_FMOVE_VALUE062,
	PG_SCC_FMOVE_VALUE063,
	PG_SCC_FMOVE_VALUE064,
	PG_SCC_FMOVE_VALUE065,
	PG_SCC_FMOVE_VALUE066,
	PG_SCC_FMOVE_VALUE067,
	PG_SCC_FMOVE_VALUE068,
	PG_SCC_FMOVE_VALUE069,
	PG_SCC_FMOVE_VALUE070,
	PG_SCC_FMOVE_VALUE071,
	PG_SCC_FMOVE_VALUE072,
	PG_SCC_FMOVE_VALUE073,
	PG_SCC_FMOVE_VALUE074,
	PG_SCC_FMOVE_VALUE075,
	PG_SCC_FMOVE_VALUE076,
	PG_SCC_FMOVE_VALUE077,
	PG_SCC_FMOVE_VALUE078,
	PG_SCC_FMOVE_VALUE079,
	PG_SCC_FMOVE_VALUE080,
	PG_SCC_FMOVE_VALUE081,
	PG_SCC_FMOVE_VALUE082,
	PG_SCC_FMOVE_VALUE083,
	PG_SCC_FMOVE_VALUE084,
	PG_SCC_FMOVE_VALUE085,
	PG_SCC_FMOVE_VALUE086,
	PG_SCC_FMOVE_VALUE087,
	PG_SCC_FMOVE_VALUE088,
	PG_SCC_FMOVE_VALUE089,
	PG_SCC_FMOVE_VALUE090,
	PG_SCC_FMOVE_VALUE091,
	PG_SCC_FMOVE_VALUE092,
	PG_SCC_FMOVE_VALUE093,
	PG_SCC_FMOVE_VALUE094,
	PG_SCC_FMOVE_VALUE095,
	PG_SCC_FMOVE_VALUE096,
	PG_SCC_FMOVE_VALUE097,
	PG_SCC_FMOVE_VALUE098,
	PG_SCC_FMOVE_VALUE099,
	PG_SCC_FMOVE_VALUE100,
};
struct	_PG_Scc_FMove_	{
	unsigned char	nFaultType;
	char			szFaultLine[MDB_CHARLEN_LONG];
	char			szMonLine[MDB_CHARLEN_LONG];
	char			szMonBus[MDB_CHARLEN_LONG];
	unsigned char	nDataType;
	double			fValue000;
	double			fValue001;
	double			fValue002;
	double			fValue003;
	double			fValue004;
	double			fValue005;
	double			fValue006;
	double			fValue007;
	double			fValue008;
	double			fValue009;
	double			fValue010;
	double			fValue011;
	double			fValue012;
	double			fValue013;
	double			fValue014;
	double			fValue015;
	double			fValue016;
	double			fValue017;
	double			fValue018;
	double			fValue019;
	double			fValue020;
	double			fValue021;
	double			fValue022;
	double			fValue023;
	double			fValue024;
	double			fValue025;
	double			fValue026;
	double			fValue027;
	double			fValue028;
	double			fValue029;
	double			fValue030;
	double			fValue031;
	double			fValue032;
	double			fValue033;
	double			fValue034;
	double			fValue035;
	double			fValue036;
	double			fValue037;
	double			fValue038;
	double			fValue039;
	double			fValue040;
	double			fValue041;
	double			fValue042;
	double			fValue043;
	double			fValue044;
	double			fValue045;
	double			fValue046;
	double			fValue047;
	double			fValue048;
	double			fValue049;
	double			fValue050;
	double			fValue051;
	double			fValue052;
	double			fValue053;
	double			fValue054;
	double			fValue055;
	double			fValue056;
	double			fValue057;
	double			fValue058;
	double			fValue059;
	double			fValue060;
	double			fValue061;
	double			fValue062;
	double			fValue063;
	double			fValue064;
	double			fValue065;
	double			fValue066;
	double			fValue067;
	double			fValue068;
	double			fValue069;
	double			fValue070;
	double			fValue071;
	double			fValue072;
	double			fValue073;
	double			fValue074;
	double			fValue075;
	double			fValue076;
	double			fValue077;
	double			fValue078;
	double			fValue079;
	double			fValue080;
	double			fValue081;
	double			fValue082;
	double			fValue083;
	double			fValue084;
	double			fValue085;
	double			fValue086;
	double			fValue087;
	double			fValue088;
	double			fValue089;
	double			fValue090;
	double			fValue091;
	double			fValue092;
	double			fValue093;
	double			fValue094;
	double			fValue095;
	double			fValue096;
	double			fValue097;
	double			fValue098;
	double			fValue099;
	double			fValue100;
}	DISALIGN;
typedef	struct	_PG_Scc_FMove_	tagPGSccFMove;
