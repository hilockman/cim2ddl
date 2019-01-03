#pragma once
static	tagMemDBField	g_PGProtSettingFieldArray[]=
{
	{	PG_PROTSETTING_PROTKER,						"ProtKer",					"整定:互感器误差系数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKREL1,				"ProtLineKkrel1",			"整定:线路瞬时电流速断可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKREL2,				"ProtLineKkrel2",			"整定:线路限时电流速断可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKLM2,				"ProtLineKklm2",			"整定:线路限时电流速断灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKRELP3,				"ProtLineKkrelp3",			"整定:线路定时限过电流可靠系数(保护配合)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKRELL3,				"ProtLineKkrell3",			"整定:线路定时限过电流可靠系数(最大负荷)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL1,				"ProtLineK0rel1",			"整定:线路零序Ⅰ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL2,				"ProtLineK0rel2",			"整定:线路零序Ⅱ段整定灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL3,				"ProtLineK0rel3",			"整定:线路零序Ⅲ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL4,				"ProtLineK0rel4",			"整定:线路零序Ⅳ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEKZREL1,				"ProtLineKZrel1",			"整定:线路相间距离Ⅰ段可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZTREL1,				"ProtLineKZTrel1",			"整定:线路相间距离Ⅰ段相邻变压器可靠系数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZP2,				"ProtLineKZp2",				"整定:线路相间距离Ⅱ段配合系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZLM2,				"ProtLineKZlm2",			"整定:线路相间距离Ⅱ段灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZFH3,				"ProtLineKZfh3",			"整定:线路相间距离Ⅲ段负荷可靠系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEKZ0REL1,				"ProtLineKZ0rel1",			"整定:线路接地距离Ⅰ段可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZT0REL1,			"ProtLineKZT0rel1",			"整定:线路接地距离Ⅰ段相邻变压器可靠系数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0P2,				"ProtLineKZ0p2",			"整定:线路接地距离Ⅱ段配合系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0LM2,				"ProtLineKZ0lm2",			"整定:线路接地距离Ⅱ段灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0P3,				"ProtLineKZ0p3",			"整定:线路接地距离Ⅲ段配合系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0LM3,				"ProtLineKZ0lm3",			"整定:线路接地距离Ⅲ段灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEIKDZ2USINGKLM,		"ProtLineIkdz2UsingKlm",	"整定:线路限时电流速断按灵敏度整定",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEIKDZ3COORD3,			"ProtLineIkdz3Coord3",		"整定:线路过流保护与相邻线路配合",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0PROTINTOTRAN,		"ProtLineI0ProtIntoTran",	"整定:线路零序Ⅰ段整定到变压器内",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0DZ2COORD2,			"ProtLineI0dz2Coord2",		"整定:线路零序Ⅱ段与邻线Ⅱ段配合",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0DZ3COORD3,			"ProtLineI0dz3Coord3",		"整定:线路零序Ⅲ段与邻线Ⅲ段配合",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0DZ3UNB,			"ProtLineI0dz3Unb",			"整定:终端线路零序Ⅲ段按变压器不平衡电流",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEZPROTINTOTRAN,		"ProtLineZProtIntoTran",	"整定:线路相间距离Ⅰ段可整定到变压器内",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ2COORD2,			"ProtLineZdz2Coord2",		"整定:线路相间距离Ⅱ段与邻线Ⅱ段配合",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ2USINGKLM,		"ProtLineZdz2UsingKlm",		"整定:线路相间距离Ⅱ段按灵敏度整定",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ3COORD3,			"ProtLineZdz3Coord3",		"整定:线路相间距离Ⅲ段与邻线Ⅲ段配合",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ3USINGKFH,		"ProtLineZdz3UsingKfh",		"整定:线路相间距离Ⅲ段按负荷阻抗整定",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEZ0PROTINTOTRAN,		"ProtLineZ0ProtIntoTran",	"整定:线路接地距离Ⅰ段可整定到变压器内",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ2COORD2,			"ProtLineZ0dz2Coord2",		"整定:线路接地距离Ⅱ段与邻线Ⅱ段配合",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ2USINGKLM,		"ProtLineZ0dz2UsingKlm",	"整定:线路接地距离Ⅱ段按灵敏度整定",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ3COORD3,			"ProtLineZ0dz3Coord3",		"整定:线路接地距离Ⅲ段与邻线Ⅲ段配合",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ3USINGKLM,		"ProtLineZ0dz3UsingKlm",	"整定:线路接地距离Ⅲ段按灵敏度整定",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTTRANKKSLM1,				"ProtTranKkslm1",			"整定:变压器电源侧速断保护灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKLLM1,				"ProtTranKkllm1",			"整定:变压器负荷侧速断保护灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKREL3,				"ProtTranKkrel3",			"整定:变压器过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKRES3,				"ProtTranKkres3",			"整定:变压器过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKUOP	,				"ProtTranKuop",				"整定:变压器复压闭锁电压值",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKUOPREL,				"ProtTranKuoprel",			"整定:变压器复压闭锁可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKUOPRES,				"ProtTranKuopres",			"整定:变压器复压闭锁返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANK0LM1	,			"ProtTranK0lm1",			"整定:变压器零序Ⅰ段灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANK0REL2,				"ProtTranK0rel2",			"整定:变压器零序Ⅱ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTBUSKUNBREL,				"ProtBusKunbrel",			"整定:母线不平衡电流可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBUSKBRKREL,				"ProtBusKbrkrel",			"整定:母线二次断线可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBUSFAULTUNB,				"ProtBusFaultUnb",			"整定:母线不平衡电流使用短路电流计算",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTGENKDREL,				"ProtGenKdrel",				"整定:发电机纵差保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKREL,				"ProtGenKkrel",				"整定:发电机过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKRES,				"ProtGenKkres",				"整定:发电机过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKAP,					"ProtGenKap",				"整定:发电机非周期分量影响系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKSS,					"ProtGenKss",				"整定:发电机电流互感器同型系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLOADKST,					"ProtLoadKst",				"整定:电动机启动电流倍数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKDREL,				"ProtLoadKdrel",			"整定:电动机纵差保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKKREL,				"ProtLoadKkrel",			"整定:电动机过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKKRES,				"ProtLoadKkres",			"整定:电动机过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKAP,					"ProtLoadKap",				"整定:电动机非周期分量影响系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKSS,					"ProtLoadKss",				"整定:电动机电流互感器同型系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTCAPKKREL2,				"ProtCapKkrel2",			"整定:并联电容器延时电流速断可靠系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKREL3,				"ProtCapKkrel3",			"整定:并联电容器过流保护可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKRES3,				"ProtCapKkres3",			"整定:并联电容器过流保护返回系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTREACKDREL,				"ProtReacKdrel",			"整定:并联电抗器差动保护可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKREL1,				"ProtReacKkrel1",			"整定:并联电抗器电流速断可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKREL3,				"ProtReacKkrel3",			"整定:并联电抗器过流保护可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKRES3,				"ProtReacKkres3",			"整定:并联电抗器过流保护返回系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTBREAKERKKP1,				"ProtBreakerKkp1",			"整定:母联/分段开关过流Ⅰ段配合系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKLM1,			"ProtBreakerKklm1",			"整定:母联/分段开关过流Ⅰ段灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKP2,				"ProtBreakerKkp2",			"整定:母联/分段开关过流Ⅱ段配合系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKR,				"ProtBreakerKkr",			"整定:母联/分段开关合环保护可靠系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEKKSEN1,				"ProtLineKksen1",			"校核:线路瞬时电流速断灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKSEN2,				"ProtLineKksen2",			"校核:线路限时电流速断灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKSEN3,				"ProtLineKksen3",			"校核:线路定时限过电流灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0SEN1,				"ProtLineK0sen1",			"校核:线路零序Ⅰ段灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0SEN2,				"ProtLineK0sen2",			"校核:线路零序Ⅱ段灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0SEN3,				"ProtLineK0sen3",			"校核:线路零序Ⅲ段灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKSEN3,				"ProtTranKksen3",			"校核:变压器过流保护灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKSEN3NEAR,			"ProtGenKksen3Near",		"校核:发电机近后备过流保护灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKSEN3FAR,			"ProtGenKksen3Far",			"校核:发电机远后备过流保护灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKKSEN3,				"ProtLoadKksen3",			"校核:电动机过流保护灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKSEN2,				"ProtCapKksen2",			"校核:并联电容器延时电流速断灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKSEN3,				"ProtCapKksen3",			"校核:并联电容器过流保护灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKSEN1,				"ProtReacKksen1",			"校核:并联电抗器电流速断灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKSEN3,				"ProtReacKksen3",			"校核:并联电抗器过流保护灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKSEN1,			"ProtBreakerKksen1",		"校核:母联/分段开关过流Ⅰ段灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKSEN2,			"ProtBreakerKksen2",		"校核:母联/分段开关过流Ⅱ段灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtLineFieldArray[]=
{
	{	PG_PROTLINE_NAME,				"Name",					"线路名称",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},

	{	PG_PROTLINE_SUBI,				"SubI",					"厂站I",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_SUBJ,				"SubJ",					"厂站J",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_VOLT,				"Volt",					"电压等级",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTLINE_NORMINALVOLT,		"NorminalVolt",			"额定电压",									MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_RATE,				"Rate",					"额定电流(安培)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_TOPOBUSI,			"TopoBusI",				"I侧拓扑母线",								MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTLINE_TOPOBUSJ,			"TopoBusJ",				"J侧拓扑母线",								MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTLINE_POWERED,			"Powered",				"电源标记",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_SRCGENI,			"SrcGenI",				"I侧电源索引",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_PROTLINE_SRCGENJ,			"SrcGenJ",				"J侧电源索引",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_PROTLINE_ZGROUND,			"ZGround",				"连接变压器接地中性点标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZGTOPOBUSI,			"ZGTopoBusI",			"I侧零序接地拓扑母线",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTLINE_ZGTOPOBUSJ,			"ZGTopoBusJ",			"J侧零序接地拓扑母线",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTLINE_IKMAXI,				"IkmaxI",				"I侧线路末端短路最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MAXI,				"I0maxI",				"I侧线路末端短路最大零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0TRANI,			"I0TranI",				"I侧线路末端变压器对侧短路最大零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMININEAR,			"IkminINear",			"I侧线路近端短路最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MININEAR,			"I0minINear",			"I侧线路近端短路最小零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMINIFAR,			"IkminIFar",			"I侧线路远端短路最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MINIFAR,			"I0minIFar",			"I侧线路远端短路最小零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IKMAXJ,				"IkmaxJ",				"J侧线路末端短路最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MAXJ,				"I0maxJ",				"J侧线路末端短路最大零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0TRANJ,			"I0TranJ",				"J侧线路末端变压器对侧短路最大零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMINJNEAR,			"IkminJNear",			"J侧线路近端短路最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MINJNEAR,			"I0minJNear",			"J侧线路近端短路最小零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMINJFAR,			"IkminJFar",			"J侧线路远端短路最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MINJFAR,			"I0minJFar",			"J侧线路远端短路最小零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IKINTOTRANI,		"IkIntoTranI",			"I侧线路末端短路最大短路电流入变压器",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_IKINTOTRANJ,		"IkIntoTranJ",			"J侧线路末端短路最大短路电流入变压器",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_N1IKMINI,			"N1IkminI",				"I侧一级相邻线路远端短路最小短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINI,			"N1I0minI",				"I侧一级相邻线路远端短路最小零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1IKMINJ,			"N1IkminJ",				"J侧一级相邻线路远端短路最小短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINJ,			"N1I0minJ",				"J侧一级相邻线路远端短路最小零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1IKMINIBUS,		"N1IkminIBus",			"I侧一级相邻线路远端短路母线",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINIBUS,		"N1I0minIBus",			"I侧一级相邻线路远端零序母线",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_N1IKMINJBUS,		"N1IkminJBus",			"J侧一级相邻线路远端短路母线",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINJBUS,		"N1I0minJBus",			"J侧一级相邻线路远端零序母线",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},

	{	PG_PROTLINE_KREL1,				"Krel1",				"整定:瞬时电流速断可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KREL2,				"Krel2",				"整定:限时电流速断可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KLM2,				"Klm2",					"整定:限时电流速断灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KRELP3,				"KrelP3",				"整定:过电流可靠系数(保护配合)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KRELL3,				"KrelL3",				"整定:过电流可靠系数(最大负荷)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_K0REL1,				"K0rel1",				"整定:零序Ⅰ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0REL2,				"K0rel2",				"整定:零序Ⅱ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0REL3,				"K0rel3",				"整定:零序Ⅲ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0REL4,				"K0rel4",				"整定:零序Ⅳ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KZREL1,				"KZrel1",				"整定:相间距离Ⅰ段可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZTREL1,			"KZTrel1",				"整定:相间距离Ⅰ段相邻变压器可靠系数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZP2,				"KZp2",					"整定:相间距离Ⅱ段配合系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZLM2,				"KZlm2",				"整定:相间距离Ⅱ段灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZFH3,				"KZfh3",				"整定:相间距离Ⅲ段负荷可靠系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KZ0REL1,			"KZ0rel1",				"整定:接地距离Ⅰ段可靠系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZT0REL1,			"KZT0rel1",				"整定:接地距离Ⅰ段相邻变压器可靠系数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0P2,				"KZ0p2",				"整定:接地距离Ⅱ段配合系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0LM2,				"KZ0lm2",				"整定:接地距离Ⅱ段灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0P3,				"KZ0p3",				"整定:接地距离Ⅲ段配合系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0LM3,				"KZ0lm3",				"整定:接地距离Ⅲ段灵敏系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IKDZ2USINGKLM,		"Ikdz2UsingKlm",		"限时电流速断按灵敏度整定",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_IKDZ3COORD3,		"Ikdz3Coord3",			"过流保护与相邻线路配合",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0PROTINTOTRAN	,	"I0ProtIntoTran",		"零序Ⅰ段整定到变压器内",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0DZ2COORD2,		"I0dz2Coord2",			"零序Ⅱ段与邻线Ⅱ段配合",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0DZ3COORD3,		"I0dz3Coord3",			"零序Ⅲ段与邻线Ⅲ段配合",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0DZ3UNB,			"I0dz3Unb	",			"终端线路零序Ⅲ段按变压器不平衡电流整定",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_ZPROTINTOTRAN,		"ZProtIntoTran",		"相间距离Ⅰ段可整定到变压器内",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ2COORD2,			"Zdz2Coord2",			"相间距离Ⅱ段与邻线Ⅱ段配合",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ2USINGKLM,		"Zdz2UsingKlm",			"相间距离Ⅱ段按灵敏度整定(最高优先级)",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ3COORD3,			"Zdz3Coord3",			"相间距离Ⅲ段与邻线Ⅲ段配合",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ3USINGKFH,		"Zdz3UsingKfh",			"相间距离Ⅲ段按负荷阻抗整定",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_Z0PROTINTOTRAN,		"Z0ProtIntoTran",		"接地距离Ⅰ段可整定到变压器内",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2COORD2,		"Z0dz2Coord2",			"接地距离Ⅱ段与邻线Ⅱ段配合",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2USINGKLM,		"Z0dz2UsingKlm",		"接地距离Ⅱ段按灵敏度整定(最高优先级)",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3COORD3,		"Z0dz3Coord3",			"接地距离Ⅲ段与邻线Ⅲ段配合",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3USINGKLM,		"Z0dz3UsingKlm",		"接地距离Ⅲ段按灵敏度整定(最高优先级)",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_IDZ1I,				"Idz1I",				"I侧瞬时电流速断整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ2I,				"Idz2I",				"I侧限时电流速断整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ3I,				"Idz3I",				"I侧过电流整定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_I0DZ1I,				"I0dz1I",				"I侧零序Ⅰ段定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ2I,				"I0dz2I",				"I侧零序Ⅱ段定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ3I,				"I0dz3I",				"I侧零序Ⅲ段定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ1INTOTRANI,		"I0dz1IntoTranI",		"I侧零序Ⅰ段保护整定入变压器",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_ZDZ1I,				"Zdz1I",				"I侧相间距离Ⅰ段整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ2I,				"Zdz2I",				"I侧相间距离Ⅱ段整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ3I,				"Zdz3I",				"I侧相间距离Ⅲ段整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_Z0DZ1I,				"Z0dz1I",				"I侧接地距离Ⅰ段定值",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2I,				"Z0dz2I",				"I侧接地距离Ⅱ段定值",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3I,				"Z0dz3I",				"I侧接地距离Ⅲ段定值",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IDZ1J,				"Idz1J",				"J侧瞬时电流速断整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ2J,				"Idz2J",				"J侧限时电流速断整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ3J,				"Idz3J",				"J侧过电流整定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_I0DZ1J,				"I0dz1J",				"J侧零序Ⅰ段定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ2J,				"I0dz2J",				"J侧零序Ⅱ段定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ3J,				"I0dz3J",				"J侧零序Ⅲ段定值",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ1INTOTRANJ,		"I0dz1IntoTranJ",		"J侧零序Ⅰ段保护整定入变压器",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_ZDZ1J,				"Zdz1J",				"J侧相间距离Ⅰ段整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ2J,				"Zdz2J",				"J侧相间距离Ⅱ段整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ3J,				"Zdz3J",				"J侧相间距离Ⅲ段整定值",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_Z0DZ1J,				"Z0dz1J",				"J侧接地距离Ⅰ段定值",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2J,				"Z0dz2J",				"J侧接地距离Ⅱ段定值",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3J,				"Z0dz3J",				"J侧接地距离Ⅲ段定值",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KSEN1I,				"Ksen1I",				"校核:I侧瞬时电流速断灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN2I,				"Ksen2I",				"校核:I侧限时电流速断灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN3I,				"Ksen3I",				"校核:I侧定时限过电流灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_K0SEN1I,			"K0sen1I",				"校核:I侧零序Ⅰ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN2I,			"K0sen2I",				"校核:I侧零序Ⅱ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN3I,			"K0sen3I",				"校核:I侧零序Ⅲ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KSEN1J,				"Ksen1J",				"校核:J侧瞬时电流速断灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN2J,				"Ksen2J",				"校核:J侧限时电流速断灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN3J,				"Ksen3J",				"校核:J侧定时限过电流灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_K0SEN1J,			"K0sen1J",				"校核:J侧零序Ⅰ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN2J,			"K0sen2J",				"校核:J侧零序Ⅱ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN3J,			"K0sen3J",				"校核:J侧零序Ⅲ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_ACLINESEGMENTPTR,	"ACLineSegmentPtr",		"线路索引",									MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtTranFieldArray[]=
{
	{	PG_PROTTRAN_NAME,				"Name",					"变压器名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTTRAN_SUB,				"Sub",					"厂站",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},

	{	PG_PROTTRAN_VOLTH,				"VoltH",				"高压卷电压等级",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTTRAN_VOLTM,				"VoltM",				"中压卷电压等级",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTTRAN_VOLTL,				"VoltL",				"低压卷电压等级",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTTRAN_3WIND,				"ThreeWind",			"三卷变标记",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_TOPOBUSH,			"TopoBusH",				"高压卷拓扑母线",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTTRAN_TOPOBUSM,			"TopoBusM",				"中压卷拓扑母线",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTTRAN_TOPOBUSL,			"TopoBusL",				"低压卷拓扑母线",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTTRAN_RATEVOLTH,			"RateVoltH",			"高压卷额定电压(千伏)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEVOLTM,			"RateVoltM",			"中压卷额定电压(千伏)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEVOLTL,			"RateVoltL",			"低压卷额定电压(千伏)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEH,				"RateH",				"高压卷额定电流(安培)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEM,				"RateM",				"中压卷额定电流(安培)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEL,				"RateL",				"低压卷额定电流(安培)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_LOADTRAN,			"LoadTran",				"负荷变压器",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_POWERH,				"PowerH",				"高压侧电源标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_POWERM,				"PowerM",				"中压侧电源标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_POWERL,				"PowerL",				"低压侧电源标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_ZGSTATH,			"ZGStatH",				"高压侧零序标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_ZGSTATM,			"ZGStatM",				"中压侧零序标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_ZGSTATL,			"ZGStatL",				"低压侧零序标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTTRAN_ITMAXH,				"ItmaxH",				"高压侧变压器内部最大短路电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMAXM,				"ItmaxM",				"中压侧变压器内部最大短路电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMAXL,				"ItmaxL",				"低压侧变压器内部最大短路电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_ITMINH,				"ItminH",				"高压侧变压器内部最小短路电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMINM,				"ItminM",				"中压侧变压器内部最小短路电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMINL,				"ItminL",				"低压侧变压器内部最小短路电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0TMAXH,			"I0tmaxH",				"高压侧变压器内部最大零序电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMAXM,			"I0tmaxM",				"中压侧变压器内部最大零序电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMAXL,			"I0tmaxL",				"低压侧变压器内部最大零序电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0TMINH,			"I0tminH",				"高压侧变压器内部最小零序电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMINM,			"I0tminM",				"中压侧变压器内部最小零序电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMINL,			"I0tminL",				"低压侧变压器内部最小零序电流(安培)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IOBMAXH,			"IobmaxH",				"高压侧对侧故障最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMAXM,			"IobmaxM",				"中压侧对侧故障最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMAXL,			"IobmaxL",				"低压侧对侧故障最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IOBMINH,			"IobminH",				"高压侧对侧故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMINM,			"IobminM",				"中压侧对侧故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMINL,			"IobminL",				"低压侧对侧故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMAXHNEAR,			"IkmaxHNear",			"高压侧母线故障最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXMNEAR,			"IkmaxMNear",			"中压侧母线故障最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXLNEAR,			"IkmaxLNear",			"低压侧母线故障最大短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMINHNEAR,			"IkminHNear",			"高压侧母线故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINMNEAR,			"IkminMNear",			"中压侧母线故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINLNEAR,			"IkminLNear",			"低压侧母线故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMAXHNEAR,		"I0kmaxHNear",			"高压侧母线故障最大零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXMNEAR,		"I0kmaxMNear",			"中压侧母线故障最大零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXLNEAR,		"I0kmaxLNear",			"低压侧母线故障最大零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMINHNEAR,		"I0kminHNear",			"高压侧母线故障最小零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINMNEAR,		"I0kminMNear",			"中压侧母线故障最小零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINLNEAR,		"I0kminLNear",			"低压侧母线故障最小零序电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMAXHFAR,			"IkmaxHFar",			"高压侧一级相邻线路末故障最大短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXMFAR,			"IkmaxMFar",			"中压侧一级相邻线路末故障最大短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXLFAR,			"IkmaxLFar",			"低压侧一级相邻线路末故障最大短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMINHFAR,			"IkminHFar",			"高压侧一级相邻线路末故障最小短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINMFAR,			"IkminMFar",			"中压侧一级相邻线路末故障最小短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINLFAR,			"IkminLFar",			"低压侧一级相邻线路末故障最小短路电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMAXHFAR,			"I0kmaxHFar",			"高压侧一级相邻线路末故障最大零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXMFAR,			"I0kmaxMFar",			"中压侧一级相邻线路末故障最大零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXLFAR,			"I0kmaxLFar",			"低压侧一级相邻线路末故障最大零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMINHFAR,			"I0kminHFar",			"高压侧一级相邻线路末故障最小零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINMFAR,			"I0kminMFar",			"中压侧一级相邻线路末故障最小零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINLFAR,			"I0kminLFar",			"低压侧一级相邻线路末故障最小零序电流(安培)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKUNBH,				"IkunbH",				"高压侧不平衡电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKUNBM,				"IkunbM",				"中压侧不平衡电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKUNBL,				"IkunbL",				"低压侧不平衡电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_KKSLM1,				"Kkslm1",				"整定:电源侧过流Ⅰ段保护灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKLLM1,				"Kkllm1",				"整定:负荷侧过流Ⅰ段保护灵敏系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKREL3,				"Kkrel3",				"整定:过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKRES3,				"Kkres3",				"整定:过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_KUOP,				"Kuop",					"整定:复压闭锁电压值",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KUOPREL,			"Kuoprel",				"整定:复压闭锁可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KUOPRES,			"Kuopres",				"整定:复压闭锁返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_K0LM1,				"K0lm1",				"整定:零序Ⅰ段灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_K0REL2,				"K0rel2",				"整定:零序Ⅱ段可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKDZ1H,				"Ikdz1H",				"高压侧负荷侧电流保护Ⅰ段整定电流(安培)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ1M,				"Ikdz1M",				"中压侧负荷侧电流保护Ⅰ段整定电流(安培)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ1L,				"Ikdz1L",				"低压侧负荷侧电流保护Ⅰ段整定电流(安培)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKDZ3H,				"Ikdz3H",				"高压侧过流保护整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ3M,				"Ikdz3M",				"中压侧过流保护整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ3L,				"Ikdz3L",				"低压侧过流保护整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_UOPH,				"UopH",					"高压侧复压闭锁整定电压(千伏)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_UOPM,				"UopM",					"中压侧复压闭锁整定电压(千伏)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_UOPL,				"UopL",					"低压侧复压闭锁整定电压(千伏)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0DZ1H,				"I0dz1H",				"高压侧零序Ⅰ段整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ1M,				"I0dz1M",				"中压侧零序Ⅰ段整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ1L,				"I0dz1L",				"低压侧零序Ⅰ段整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0DZ2H,				"I0dz2H",				"高压侧零序Ⅱ段整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ2M,				"I0dz2M",				"中压侧零序Ⅱ段整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ2L,				"I0dz2L",				"低压侧零序Ⅱ段整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_KKSEN3H,			"Kksen3H",				"校核:高压侧过流保护灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKSEN3M,			"Kksen3M",				"校核:中压侧过流保护灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKSEN3L,			"Kksen3L",				"校核:低压侧过流保护灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_POWERTRANSFORMERPTR, "PowerTransformerPtr",	"变压器索引",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtBusFieldArray[]=
{
	{	PG_PROTBUS_NAME,				"Name",					"母线名称",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTBUS_TOPOBUS,				"TopoBus",				"拓扑母线",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTBUS_IBRANKMAX,			"IbrankMax",			"支路最大短路电流(安培)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IBRANEMAX,			"IbraneMax",			"支路最大负荷电流(安培)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IKMIN,				"IkMin",				"最小短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBUS_KUNBREL,				"Kunbrel",				"整定:不平衡电流可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_KBRKREL,				"Kbrkrel",				"整定:二次断线可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_FAULTUNB,			"Faultunb",				"整定:外部短路故障整定不平衡电流(安培)",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTBUS_IKOP,				"Ikop",					"外部短路计算不平衡电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_ILOP,				"Ilop",					"最大负荷计算不平衡电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IOOP,				"Ioop",					"躲避二次断线差动保护整定电流(安培)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IKDZ,				"Ikdz",					"过流保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBUS_KSEN,				"Ksen",					"校核:差动保护灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBUS_BUSPTR,				"BusPtr",				"母线索引",									MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtGenFieldArray[]=
{
	{	PG_PROTGEN_NAME,				"Name",					"发电机名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTGEN_TOPOBUS,				"TopoBus",				"拓扑母线",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTGEN_RATE,				"Rate",					"额定电流(安培)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_IKMAX,				"IkMax",				"最大短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IKMINNEAR,			"IkminNear",			"设备近端故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IKMINFAR,			"IkminFar",				"设备远端故障最小短路电流(安培)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_KDREL,				"Kdrel",				"整定:纵差保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KKREL,				"Kkrel",				"整定:过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KKRES,				"Kkres",				"整定:过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KAP,					"Kap",					"整定:非周期分量影响系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KSS,					"Kss",					"整定:电流互感器同型系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_IUNBMAX,				"IunbMax",				"纵差最大不平衡电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IDDZ,				"Iddz",					"纵差保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IKDZ,				"Ikdz",					"过流保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_KKSENNEAR,			"KksenNear",			"校核:过流保护近后备灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KKSENFAR,			"KksenFar",				"校核:过流保护远后备灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_GENPTR,				"GenPtr",				"发电机索引",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtCapFieldArray[]=
{
	{	PG_PROTCAP_NAME,				"Name",					"并联电容器名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTCAP_TOPOBUS,				"TopoBus",				"拓扑母线",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTCAP_RATE,				"Rate",					"额定电流(安培)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_IKMAX,				"IkMax",				"最大短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_IKMIN,				"IkMin",				"最小短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_KKREL2,				"Kkrel2",				"整定:延时电流速断保护可靠系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_KKREL3,				"Kkrel3",				"整定:过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_KKRES3,				"Kkres3",				"整定:过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_IKDZ2,				"Ikdz2",				"延时电流速断整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_IKDZ3,				"Ikdz3",				"过流保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_KSEN2,				"Ksen2",				"校核:延时电流速断灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_KSEN3,				"Ksen3",				"校核:过流保护灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_CAPPTR,				"CapPtr",				"并联电容器索引",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtReacFieldArray[]=
{
	{	PG_PROTREAC_NAME,				"Name",					"并联电抗器名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTREAC_TOPOBUS,			"TopoBus",				"拓扑母线",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTREAC_RATE,				"Rate",					"额定电流(安培)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_IKMAX,				"IkMax",				"最大短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_IKMIN,				"IkMin",				"最小短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_KDREL,				"Kdrel",				"整定:差动保护整定系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KKREL1,				"Kkrel1",				"整定:瞬时电流速断保护可靠系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KKREL3,				"Kkrel3",				"整定:过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KKRES3,				"Kkres3",				"整定:过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_IDDZ,				"Iddz",					"差动保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_IKDZ1,				"Ikdz1",				"瞬时电流速断整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_IKDZ3,				"Ikdz3",				"过流保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_KSEN1,				"Ksen1",				"校核:瞬时电流速断灵敏系数",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KSEN3,				"Ksen3",				"校核:过流保护灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_REACPTR,			"ReacPtr",				"设备索引",									MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtMotorFieldArray[]=
{
	{	PG_PROTMOTOR_NAME,				"Name",					"电动机名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTMOTOR_TOPOBUS,			"TopoBus",				"拓扑母线",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTMOTOR_RATE,				"Rate",					"额定电流(安培)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_IKMAX,				"IkMax",				"最大短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_IKMIN,				"IkMin",				"最小短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_KST,				"Kst",					"整定:电动机启动电流倍数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KDREL,				"Kdrel",				"整定:纵差保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KKREL,				"Kkrel",				"整定:过流保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KKRES,				"Kkres",				"整定:过流保护返回系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KAP,				"Kap",					"整定:非周期分量影响系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KSS,				"Kss",					"整定:电流互感器同型系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_IUNBMAX,			"IunbMax",				"纵差最大不平衡电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_IDDZ,				"Iddz",					"纵差保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_IKDZ,				"Ikdz",					"过流保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_KDSEN,				"Kdsen",				"校核:纵差保护灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KKSEN,				"Kksen",				"校核:过流保护灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_LOADPTR,			"LoadPtr",				"设备索引",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtBreakerFieldArray[]=
{
	{	PG_PROTBREAKER_NAME,			"Name",					"母联断路器名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTBREAKER_TOPOBUS,			"TopoBus",				"拓扑母线",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTBREAKER_ILINEMAX,		"ILineMax",				"线路最大额定电流(安培)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_ITRANMAX,		"ITranMax",				"变压器最大额定电流(安培)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_LOWVBREAKER,		"LowVBreaker",			"低压断路器(以变压器卷为判断原则)",			MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTBREAKER_IKMAX,			"IkMax",				"最大短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_IKMIN,			"IkMin",				"最小短路电流(安培)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_KKP1,			"Kkp1",					"整定:过流Ⅰ段配合系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KKLM1,			"Kklm1",				"整定:过流Ⅰ段灵敏系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KKP2,			"Kkp2",					"整定:过流Ⅱ段配合系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KKR,				"Kkr",					"整定:合环保护可靠系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_IKDZ1,			"Ikdz1",				"过流Ⅰ段保护整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_IKDZ2,			"Ikdz2",				"过流Ⅱ段保护整定电流(安培)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_IRDZ,			"Irdz",					"合环保护整定电流(安培)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_KSEN1,			"Ksen1",				"校核:过流Ⅰ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KSEN2,			"Ksen2",				"校核:过流Ⅱ段灵敏系数",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_BREAKERPTR,		"BreakerPtr",			"设备索引",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};
