#pragma	once

#include	"BpaMemDBDefine.h"

#if	defined(__GNUG__)	||	defined(__GNUC__)	//	GCC编译器预定义的宏
#	ifndef	DISALIGN
#		define	DISALIGN	__attribute__((packed))
#	endif
#else
#	define	DISALIGN
#	if	(defined(_AIX)	||	defined(AIX))
#		pragma	align(packed)
#	else
#		if	(!defined(sun)	&&	!defined(__sun)	&&	!defined(__sun__))
#			pragma	pack(push)
#		endif
#	endif
#	pragma	pack(1)
#endif

static	tagMemDBEnumPair	g_BpaEnumNoYes[]=
{
	{	0,		"否",	},
	{	1,		"是",	},
};

static	tagMemDBEnumPair	g_BpaEnumYesNo[]=
{
	{	0,		"是",	},
	{	1,		"否",	},
};

static	tagMemDBEnumPair	g_BpaEnumRing[]=
{
	{	0,		"辐射母线",	},
	{	1,		"环网母线",	},
	{	2,		"边界母线",	},
};

static	tagMemDBEnumPair	g_BpaEnumFaultType[]=
{
	{	BpaEnum_Scc_FaultType1,		"单永故障",	},
	{	BpaEnum_Scc_FaultType2,		"两相短路",	},
	{	BpaEnum_Scc_FaultType3,		"三相短路",	},
	{	BpaEnum_Scc_FaultType4,		"两相接地",	},
};

static	tagMemDBEnumPair	g_BpaEnumSccFMoveDataType[]=
{
	{	BpaEnum_Scc_FMoveDataType_FC_I1Re,		"故障线路短路电流I侧正序实部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I1Im,		"故障线路短路电流I侧正序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I2Re,		"故障线路短路电流I侧负序实部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I2Im,		"故障线路短路电流I侧负序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I0Re,		"故障线路短路电流I侧零序实部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I0Im,		"故障线路短路电流I侧零序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z1Re,		"故障线路短路电流J侧正序实部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z1Im,		"故障线路短路电流J侧正序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z2Re,		"故障线路短路电流J侧负序实部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z2Im,		"故障线路短路电流J侧负序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z0Re,		"故障线路短路电流J侧零序实部",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z0Im,		"故障线路短路电流J侧零序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I1Re,		"监视线路短路电流I侧正序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I1Im,		"监视线路短路电流I侧正序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I2Re,		"监视线路短路电流I侧负序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I2Im,		"监视线路短路电流I侧负序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I0Re,		"监视线路短路电流I侧零序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I0Im,		"监视线路短路电流I侧零序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z1Re,		"监视线路短路电流J侧正序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z1Im,		"监视线路短路电流J侧正序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z2Re,		"监视线路短路电流J侧负序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z2Im,		"监视线路短路电流J侧负序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z0Re,		"监视线路短路电流J侧零序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z0Im,		"监视线路短路电流J侧零序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MV_1Re,		"监视母线电压正序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MV_1Im,		"监视母线电压正序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MV_2Re,		"监视母线电压负序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MV_2Im,		"监视母线电压负序虚部",	},
	{	BpaEnum_Scc_FMoveDataType_MV_0Re,		"监视母线电压零序实部",	},
	{	BpaEnum_Scc_FMoveDataType_MV_0Im,		"监视母线电压零序虚部",	},
};

static	tagMemDBEnumPair	g_BpaEnumFaultPhase[]=
{
	{	0,		"A相",	},
	{	1,		"B相",	},
	{	2,		"C相",	},
};

static	tagMemDBEnumPair	g_BpaEnumPssSI_INP[]=
{
	{	PssSI_INPStatus_WPG,	"输入信号为ω或PG",	},	//0或者空格时,取此值
	{	PssSI_INPStatus_W,		"输入信号只有ω",	},
	{	PssSI_INPStatus_PG,		"输入信号只有PG",	},
};

static	tagMemDBEnumPair	g_BpaEnumPssSI_IB[]=
{
	{	PssSI_INPStatus_dV,		"输入信号为发电机速度偏差",			},	//0或者空格时,取此值
	{	PssSI_INPStatus_dF,		"输入信号为母线频率偏差",			},
	{	PssSI_INPStatus_EQ_dF,	"输入信号为虚拟电势EQ的频率偏差",	},
};

static	tagMemDBEnumPair	g_BpaEnumSwicth[]=
{
	{	1,		"投入",	},	//1-投入
	{	2,		"切除",	},	//2-切除
};

static	tagMemDBEnumPair	g_BpaEnumGJ_ControlMode[]=
{
	{	1,		"调节级压力反馈控制",	},//=1－调节级压力反馈控制;
	{	2,		"DEH开环控制",			},//=2－DEH开环控制
	{	3,		"负荷反馈控制",			},//=3－负荷反馈控制
};

static	tagMemDBEnumPair	g_BpaEnumGK_FilterDead[]=
{
	{	GK_FilterDead_Dead,		"采用死区",		},
	{	GK_FilterDead_Filter,	"采用滤波器",	},
};

static	tagMemDBEnumPair	g_BpaEnumGK_ControlMode[]=
{
	{	1,		"CCS自动控制",						},//=1,CCS自动控制;(正常运行为方式1)
	{	2,		"负荷开环控制",						},//=2,负荷开环控制
	{	3,		"带主汽压力修正的负荷反馈控制",		},//=3,带主汽压力修正的负荷反馈控制
};

static	tagMemDBEnumPair	g_BpaEnumGM_OpenMode[]=
{
	{	GM_OpenMode_Y,		"输入信号为开度Y",	},
	{	GM_OpenMode_YPID,	"输入信号为YPID",	},
};

static	tagMemDBEnumPair	g_BpaEnumGM_Mode[]=
{
	{	1,	"功率模式",	},	//=1为功率模式
	{	2,	"开度模式",	},	//=2为开度模式
};

static	tagMemDBEnumPair	g_BpaEnumGZ_ControlMode[]=
{
	{	GZ_ControlMode_Speed,		"速度",				},
	{	GZ_ControlMode_SpeedAndP,	"速度和电磁功率",	},
	{	GZ_ControlMode_SpeedAndMP,	"速度和机械功率",	},
};

static	tagMemDBEnumPair	g_BpaEnumCase_AIControl[]=
{
	{	Case_AIControl_CON,	"CON",	},
	{	Case_AIControl_MON,	"MON",	},
	{	Case_AIControl_OFF,	"OFF",	},
};

static	tagMemDBEnumPair	g_BpaEnumCase_LTC[]=
{
	{	Case_LTC_ON,		"ON",		},
	{	Case_LTC_ON_NV,		"ON_NV",	},
	{	Case_LTC_ON_NPS,	"ON_NPS",	},
	{	Case_LTC_OFF,		"OFF",		},
	{	Case_LTC_ON_DCONLY,	"ON_DCONLY",},
};

static	tagMemDBEnumPair	g_BpaEnumMotor_KlS0[]=
{
	{	Motor_KLS0_KL,		"负载率",	},
	{	Motor_KLS0_S0,		"初始滑差",	},
};

static	tagMemDBEnumPair	g_BpaEnumMotor_Stall[]=
{
	{	Motor_IM_NONE,		"	",		},
	{	Motor_IM_STOP,		"停止计算",	},
	{	Motor_IM_STALL,		"堵转",		},
	{	Motor_IM_TRIP,		"切除",		},
};

static	tagMemDBEnumPair	g_BpaEnumFF_Stall[]=
{
	{	FF_IM_STOP,		"停止计算",	},
	{	FF_IM_STALL,	"堵转",		},
	{	FF_IM_TRIP,		"切除",		},
};

static	tagMemDBField	dicFieldBpaDat_Case[]=
{
	{	BPA_DAT_CASE_CASEID,						"Case_CaseID",				"潮流方式名",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_PROJECT,						"Case_Project",				"工程名",								MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_MVABASE,						"Case_MVABase",				"指定的系统基准容量",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_CONTROL,						"Case_Control",				"所指定的控制语句文件",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_BRANCH,						"Case_Branch",				"所指定的支路数据",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_BUS,							"Case_Bus",					"所指定的母线数据",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_NETWORK,						"Case_Network",				"所指定的数据文件",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_RXCHECK,						"Case_RXCheck",				"RX比值检查",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_NEWBASE,						"Case_NewBase",				"潮流结果二进制文件(.BSE)",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_OLDBASE,						"Case_OldBase",				"指定老库文件",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_MAP,							"Case_Map",					"生成潮流图二进制结果文件",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_AICONTROL,						"Case_AIControl",			"区域联络线功率控制选择",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumCase_AIControl)/sizeof(tagMemDBEnumPair),	g_BpaEnumCase_AIControl,	},
	{	BPA_DAT_CASE_LTC,							"Case_LTC",					"带负荷调压变压器控制选择",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumCase_LTC)/sizeof(tagMemDBEnumPair),			g_BpaEnumCase_LTC,			},
	{	BPA_DAT_CASE_DECOUPLEDNUM,					"Case_DecoupledNum",		"PQ解耦法",								MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_CURRENTNUM,					"Case_CurrentNum",			"改进的牛顿拉夫逊算法",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_NEWTONNUM,						"Case_NewtonNum",			"牛顿拉夫逊算法",						MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_OPTIMNUM,						"Case_OptimNum",			"最优潮流法",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEBUSV,					"Case_ToleranceBusV",		"BusV允许误差,缺省值：0.005",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEAIPOWER,				"Case_ToleranceAIPower",	"AIPower允许误差,缺省值：0.005",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCETX,					"Case_ToleranceTX",			"TX允许误差,缺省值：0.005",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEQ,					"Case_ToleranceQ",			"Q允许误差,缺省值：0.005",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEOPCUT,				"Case_ToleranceOpcut",		"OPCUT允许误差,缺省值：0.0001",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
//	{	BPA_DAT_CASE_INPUTLIST,						"Case_InputList",			"输入的原始数据输出",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_RPTSORT,						"Case_RptSort",				"输出分类,输出顺序控制语句",			MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_ANALYSISRPT,					"Case_AnalysisRpt",			"分析报告输出,指定输出等级",			MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
//	{	BPA_DAT_CASE_AILISTCONTROL,					"Case_AIListControl",		"区域功率交换数据输出",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
//	{	BPA_DAT_CASE_LINELOSS,						"Case_LineLoss",			"线路损耗输出",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
//	{	BPA_DAT_CASE_TRANSFORMERLOSS,				"Case_TransformerLoss",		"变压器支路损耗输出",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ISLANDNUM,							"IslandNum",				"电岛数",								MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_TOTGENP,							"TotGenP",					"总发电有功",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTGENQ,							"TotGenQ",					"总发电无功",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOADP,							"TotLoadP",					"总负荷有功",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOADQ,							"TotLoadQ",					"总负荷无功",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLINECAP,							"TotLineCap",				"线路充电无功",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOSSP,							"TotLossP",					"总损耗有功",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOSSQ,							"TotLossQ",					"总损耗无功",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTDCLOSS,							"TotDCLoss",				"直流换流器损耗",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Area[]=
{
	{	BPA_DAT_AREA_NAME,			"Area_Name",	"区域名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_AREA_CARDKEY,		"CardKey",		"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_DAT_AREA_SLACKBUSNAME,	"SlackBusName",	"区域缓冲节点名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_AREA_SLACKBUSKV,	"SlackBuskV",	"区域缓冲节点基准电压",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_AREA_OUTP,			"OutP",			"安排的区域交换功率(MW)值",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_MK_TJ,				"MK_TJ",		"马达的惯性时间常数(秒)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_PPER,			"MK_Pper",		"马达功率占母线有功负荷的比例",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_KL,				"MK_KL",		"马达的负载率",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_PMIN,			"MK_Pmin",		"马达的功率因数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_RS,				"MK_RS",		"定子电阻(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_XS,				"MK_XS",		"定子电抗(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_XM,				"MK_XM",		"激磁电抗(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_RR,				"MK_RR",		"转子电阻(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_XR,				"MK_XR",		"转子电抗(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_VI,				"MK_VI",		"马达低压释放的电压值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_TI,				"MK_TI",		"马达低压释放时延(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_A,				"MK_A",			"转矩方程常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_B,				"MK_B",			"转矩方程常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_IM,				"MK_IM",		"马达滑差达到1时的处理方式",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaDat_I[]=
{
	{	BPA_DAT_I_CARDKEY,			"CardKey",		"卡类型",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_DAT_I_AREA1,			"I_Area1",		"区域1名称",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_DAT_I_AREA2,			"I_Area2",		"区域2名称",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_DAT_I_OUTP,				"I_OutP",		"区域1向区域2的输出功率",								MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Zone[]=
{
	{	BPA_DAT_ZONE_NAME,			"Zone_Name",	"分区名称",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,		0,	NULL,	},
	{	BPA_DAT_ZONE_AREA,			"Zone_Area",	"区域名称",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_DAT_ZONE_CARDKEY,		"CardKey",		"卡类型",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},

	{	BPA_DAT_ZONE_KG0,			"LOZ_KG0",		"线路零序电导相对于正序电导的倍数	",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_KB0,			"LOZ_KB0",		"线路零序电纳相对于正序电纳的倍数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_KGC0,			"LOZ_KGC0",		"线路对地支路零序电导相对于对地支路正序电导的倍数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_KBC0,			"LOZ_KBC0",		"线路对地支路零序电纳相对于对地支路正序电纳的倍数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_VMIN,			"LOZ_VMIN",		"电压等级限制最小值	",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_VMAX,			"LOZ_VMAX",		"电压等级限制最大值	",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},

	{	BPA_DAT_MJ_TJ,				"MJ_TJ",		"马达的惯性时间常数(秒)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_PPER,			"MJ_Pper",		"马达功率占母线有功负荷的比例",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_KL,				"MJ_KL",		"马达的负载率",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_PMIN,			"MJ_Pmin",		"马达的功率因数",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_RS,				"MJ_RS",		"定子电阻(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_XS,				"MJ_XS",		"定子电抗(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_XM,				"MJ_XM",		"激磁电抗(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_RR,				"MJ_RR",		"转子电阻(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_XR,				"MJ_XR",		"转子电抗(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_VI,				"MJ_VI",		"马达低压释放的电压值",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_TI,				"MJ_TI",		"马达低压释放时延(秒)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_A,				"MJ_A",			"转矩方程常数",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_B,				"MJ_B",			"转矩方程常数",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_IM,				"MJ_IM",		"马达滑差达到1时的处理方式",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaDat_Sub[]=
{
	{	BPA_DAT_SUB_NAME,	"Sub_Name",		"厂站名称",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_SUB_ALIAS,	"Sub_Alias",	"厂站别名",			MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_SUB_TYPE,	"Sub_Type",		"厂站类型",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	BPA_DAT_SUB_GENP,	"Sub_GenP",		"厂站发电有功",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_GENQ,	"Sub_GenQ",		"厂站发电无功",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_LOADP,	"Sub_LoadP",	"厂站负荷有功",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_LOADQ,	"Sub_LoadQ",	"厂站负荷无功",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_SHUNTQ,	"Sub_ShuntQ",	"厂站补偿无功",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_ACBus[]=
{
	{	BPA_DAT_ACBUS_CARDKEY,		"CardKey",				"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_ACBUS_CHGCODE,		"ACBus_ChgCode",		"修改码",								MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACBUS_OWNER,		"ACBus_Owner",			"所有者",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACBUS_NAME,			"ACBus_Name",			"母线名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACBUS_KV,			"ACBus_kV",				"基准电压(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ZONE,			"ACBus_Zone",			"分区名",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACBUS_PLOAD,		"ACBus_PLoad",			"恒定有功负荷(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QLOAD,		"ACBus_QLoad",			"恒定无功负荷(MVAR),+感性",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PSHUNT,		"ACBus_PShunt",			"并联导纳有功负荷(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QSHUNT,		"ACBus_QShunt",			"并联导纳无功负荷(MVAR),+容性",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PMAX,			"ACBus_Pmax",			"最大有功出力(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PGEN,			"ACBus_PGen",			"实际有功出力(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QSCHED_QMAX,	"ACBus_Qsched_Qmax",	"安排的无功出力值,+容性",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QMIN,			"ACBus_Qmin",			"无功出力最小值(MVAR),此处填0",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VHOLD_MAX,	"ACBus_VHold_max",		"安排的Vmax(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VMIN,			"ACBus_Vmin",			"安排的Vmin(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RBUSNAME,		"ACBus_RBusName",		"远方要控制的母线名称",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACBUS_RBUSVOLT,		"ACBus_RBusVolt",		"远方要控制的基准电压(kV)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VARSPPLD,		"ACBus_VarSppld",		"提供的无功功率百分数(%)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_ADDCODE,		"ACBus_AddCode",		"延续节点负荷模型类型子代码",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDPLOAD,		"ACBus_AddPLoad",		"延续节点恒定有功负荷(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDQLOAD,		"ACBus_AddQLoad",		"延续节点恒定无功负荷(MVAR),+感性",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDPSHUNT,	"ACBus_AddPShunt",		"延续节点并联导纳有功负荷(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDQSHUNT,	"ACBus_AddQShunt",		"延续节点并联导纳无功负荷(MVAR),+容性",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDPGEN,		"ACBus_AddPGen",		"延续节点有功出力(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDQGEN,		"ACBus_AddQGen",		"延续节点无功出力(MVAR),+感性",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
																								
	{	BPA_DAT_ACBUS_SUB,			"ACBus_BpaSub",			"母线所属BPA厂站",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACBUS_ALIAS,		"ACBus_Alias",			"交流母线别名",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_ACBUS_V,			"ACBus_V",				"母线电压",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_D,			"ACBus_D",				"母线功角",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
																								
	{	BPA_DAT_ACBUS_PFOPGEN,		"ACBus_PfoPGen",		"母线计算发电有功",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQGEN,		"ACBus_PfoQGen",		"母线计算发电无功",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOPLOAD,		"ACBus_PfoPLoad",		"母线计算负荷有功",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQLOAD,		"ACBus_PfoQLoad",		"母线计算负荷无功",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQSHUNT,	"ACBus_PfoQShunt",		"母线计算补偿无功",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOPNET,		"ACBus_PfoPNet",		"母线计算注入有功",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQNET,		"ACBus_PfoQNet",		"母线计算注入无功",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
																								
	{	BPA_DAT_ACBUS_VD_RERR,		"vd_Rerr",				"母线故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC1,		"vd_RScc1",				"单相接地频率(次/年)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC2,		"vd_RScc2",				"相间短路频率(次/年)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC3,		"vd_RScc3",				"三相短路频率(次/年)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC4,		"vd_RScc4",				"两相接地频率(次/年)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
																								
	{	BPA_DAT_ACBUS_RTGENP,		"ACBus_RtGenP",			"RT实际有功出力(MW)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTGENQ,		"ACBus_RtGenQ",			"RT安排的无功出力值",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTLOADP,		"ACBus_RtLoadP",		"RT恒定有功负荷(MW)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTLOADQ,		"ACBus_RtLoadQ",		"RT恒定无功负荷(MVAR)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTSHUNTQ,		"ACBus_RtShuntQ",		"RT并联导纳无功负荷(MVAR)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTVHOLD,		"ACBus_RtVHold",		"RT安排的V(pu)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_SCCA,			"ACBus_SccA",			"母线故障电流(A)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV,			"ACBus_SccV",			"母线故障电压(kV)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCR1,		"ACBus_SccR1",			"母线正序等值阻抗(R1,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCX1,		"ACBus_SccX1",			"母线正序等值阻抗(X1,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCR2,		"ACBus_SccR2",			"母线负序等值阻抗(R2,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCX2,		"ACBus_SccX2",			"母线负序等值阻抗(X2,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCR0,		"ACBus_SccR0",			"母线零序等值阻抗(R0,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCX0,		"ACBus_SccX0",			"母线零序等值阻抗(X0,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA1RE,		"ACBus_SccA1Re",		"正序故障电流实部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA1IM,		"ACBus_SccA1Im",		"正序故障电流虚部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA2RE,		"ACBus_SccA2Re",		"负序故障电流实部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA2IM,		"ACBus_SccA2Im",		"负序故障电流虚部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA0RE,		"ACBus_SccA0Re",		"零序故障电流实部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA0IM,		"ACBus_SccA0Im",		"零序故障电流虚部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV1RE,		"ACBus_SccV1Re",		"正序故障电压实部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV1IM,		"ACBus_SccV1Im",		"正序故障电压虚部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV2RE,		"ACBus_SccV2Re",		"负序故障电压实部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV2IM,		"ACBus_SccV2Im",		"负序故障电压虚部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV0RE,		"ACBus_SccV0Re",		"零序故障电压实部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV0IM,		"ACBus_SccV0Im",		"零序故障电压虚部(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS1,		"ACBus_VDipBus1",		"母线单相接地暂降母线数",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS2,		"ACBus_VDipBus2",		"母线相间短路暂降母线数",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS3,		"ACBus_VDipBus3",		"母线三相短路暂降母线数",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS4,		"ACBus_VDipBus4",		"母线两相接地暂降母线数",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	BPA_DAT_ACBUS_INIPLOAD,		"ACBus_IniPLoad",		"Ini恒定有功负荷(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIQLOAD,		"ACBus_IniQLoad",		"Ini恒定无功负荷(MVAR),+感性",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIPSHUNT,	"ACBus_IniPShunt",		"Ini并联导纳有功负荷(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIQSHUNT,	"ACBus_IniQShunt",		"Ini并联导纳无功负荷(MVAR),+容性",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIPGEN,		"ACBus_IniPGen",		"Ini有功出力(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIQGEN,		"ACBus_IniQGen",		"Ini无功出力值,+容性",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_TMID,			"TMid",					"变压器中性点标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_GENERATOR,	"Generator",			"发电机母线标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_WTGEN,		"WTGen",				"并网风电机组机标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_PVGEN,		"PVGen",				"并网光伏机组机标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_DCBOUND,		"DCBound",				"交直流边界母线",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_GENLN,		"GenLn",				"等值发电机母线标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_STATUS,		"Status",				"母线状态",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_REDCUTION,	"Redcution",			"化简等值母线",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_INRING,		"InRing",				"环网设备",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_ACBUS_RADIATE,		"Radiate",				"所在辐射网",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ACISLAND,		"ACIsland",				"交流岛",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRLINE,		"pRLine",				"母线线路索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRTRAN,		"pRTran",				"母线变压器索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRHG,			"pRHG",					"母线高抗索引",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRSUB,		"pRSub",				"母线厂站索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_ACLine[]=
{
	{	BPA_DAT_ACLINE_CARDKEY,		"CardKey",			"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_ACLINE_CHGCODE,		"ACLine_ChgCode",	"修改码",							MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_OWNER,		"ACLine_Owner",		"所有者",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSI,		"ACLine_BusI",		"母线名称1",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_KVI,			"ACLine_kVI",		"基准电压1(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_METER,		"ACLine_Meter",		"区域联络线测点标志",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSJ,		"ACLine_BusJ",		"母线名称2",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_KVJ,			"ACLine_kVJ",		"基准电压2(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOOP,		"ACLine_Loop",		"并联线路的回路标志",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_SECTION,		"ACLine_Section",	"分段串连而成的线路的段号",			MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACLINE_AMP,			"ACLine_AMP",		"线路额定电流(安培)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOOPNUM,		"ACLine_LoopNum",	"并联线路数目",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACLINE_R,			"ACLine_R",			"电阻(R,pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_X,			"ACLine_X",			"电抗(X,pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_G1,			"ACLine_G1",		"线路母线1端对地电导(G/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_B1,			"ACLine_B1",		"线路母线1端对地电纳(B/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_G2,			"ACLine_G2",		"线路母线2端对地电导(G/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_B2,			"ACLine_B2",		"线路母线2端对地电纳(B/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_MILES,		"ACLine_Miles",		"线路或段长度",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	//{	BPA_DAT_ACLINE_COMMENT,		"ACLine_Comment",	"线路说明数据",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},

	{	BPA_DAT_ACLINE_VD_RERR,		"vd_Rerr",			"线路故障率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC1,	"vd_RScc1",			"单相接地频率(次/年)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC2,	"vd_RScc2",			"相间短路频率(次/年)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC3,	"vd_RScc3",			"三相短路频率(次/年)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC4,	"vd_RScc4",			"两相接地频率(次/年)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACLINE_PI,			"ACLine_Pi",		"线路BUS1侧有功(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_QI,			"ACLine_Qi",		"线路BUS1侧无功(MVar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_PZ,			"ACLine_Pz",		"线路BUS2侧有功(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_QZ,			"ACLine_Qz",		"线路BUS2侧无功(MVar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOSSP,		"ACLine_LossP",		"线路有功损耗(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOSSQ,		"ACLine_LossQ",		"线路无功损耗(MVar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACLINE_SCCA,		"ACLine_SccA",		"线路故障电流(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS1,	"ACLine_VDipBus1",	"线路中点单相接地暂降母线数",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS2,	"ACLine_VDipBus2",	"线路中点相间短路暂降母线数",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS3,	"ACLine_VDipBus3",	"线路中点三相短路暂降母线数",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS4,	"ACLine_VDipBus4",	"线路中点两相接地暂降母线数",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	BPA_DAT_ACLINE_KEYNAME,		"KeyName",			"线路名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_ACLINE_INIBUSI,		"IniBusI",			"Ini母线名称1",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_INIKVI,		"InikVI",			"Ini基准电压1(kV)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_INIBUSJ,		"IniBusJ",			"Ini母线名称2",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_INIKVJ,		"InikVJ",			"Ini基准电压2(kV)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_INILOOP,		"IniLoop",			"Ini并联线路的回路标志",			MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSIPTR,		"iRBus",			"线路I母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSJPTR,		"zRBus",			"线路Z母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_ALIAS,		"Alias",			"交流线路别名",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_ACLINE_STATUS,		"Status",			"状态",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACLINE_INRING,		"InRing",			"环网设备",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_ACLINE_RADIATE,		"Radiate",			"所在辐射网",						MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_LineHG[]=
{
	{	BPA_DAT_LINEHG_CARDKEY,		"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_DAT_LINEHG_BUSI,		"LineHG_BusI",		"母线名称1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_KVI,			"LineHG_kVI",		"基准电压1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_BUSJ,		"LineHG_BusJ",		"母线名称2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_KVJ,			"LineHG_kVJ",		"基准电压2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_LOOP,		"LineHG_Loop",		"并联线路的回路标志",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_LINEHG_SHUNTI,		"LineHG_ShuntI",	"线路前侧高抗容量(Mvar,填正值)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_SHUNTJ,		"LineHG_ShuntJ",	"线路后侧高抗容量(Mvar,填正值)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_KEYNAME,		"KeyName",			"线路高抗名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_LINEHG_INIBUSI,		"IniBusI",			"Ini母线名称1",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_INIKVI,		"InikVI",			"Ini基准电压1(kV)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_INIBUSJ,		"IniBusJ",			"Ini母线名称2",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_INIKVJ,		"InikVJ",			"Ini基准电压2(kV)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_INILOOP,		"IniLoop",			"Ini并联线路的回路标志",				MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_LINEHG_BUSPTR,		"iRBus",			"线路高抗I母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_LINEHG_ZRBUS,		"zRBus",			"线路高抗Z母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_LINEHG_ALIAS,		"Alias",			"线路高抗别名",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_LINEHG_STATUS,		"Status",			"状态",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_LINEHG_INRING,		"InRing",			"环网设备",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_LINEHG_RADIATE,		"Radiate",			"所在辐射网",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Wind[]=
{
	{	BPA_DAT_WIND_CARDKEY,	"CardKey",		"卡类型",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_WIND_CHGCODE,	"Wind_ChgCode",	"修改码",									MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_OWNER,		"Wind_Owner",	"所有者",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_WIND_BUSI,		"Wind_BusI",	"母线名称1",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_KVI,		"Wind_kVI",		"基准电压1(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_METER,		"Wind_Meter",	"区域联络线测点标志",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_BUSJ,		"Wind_BusJ",	"母线名称2",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_KVJ,		"Wind_kVJ",		"基准电压2(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOOP,		"Wind_Loop",	"并联线路的回路标志",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_SECTION,	"Wind_Section",	"分段串连而成的线路的段号",					MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_MVA,		"Wind_MVA",		"变压器额定容量(MVA)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOOPNUM,	"Wind_LoopNum",	"并联变压器数目",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_R,			"Wind_R",		"由铜损引起的等效电阻(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_X,			"Wind_X",		"漏抗(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_G,			"Wind_G",		"由铁损引起的等效电导(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_B,			"Wind_B",		"激磁导纳(pu)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_TPI,		"Wind_TPI",		"母线1的固定分接头/移相器的固定移相角(度)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_TPJ,		"Wind_TPJ",		"母线2的固定分接头",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_PI,		"Wind_Pi",		"变压器BUS1侧有功(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_QI,		"Wind_Qi",		"变压器BUS1侧无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_PZ,		"Wind_Pz",		"变压器BUS2侧有功(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_QZ,		"Wind_Qz",		"变压器BUS2侧无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOSSP,		"Wind_LossP",	"变压器有功损耗(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOSSQ,		"Wind_LossQ",	"变压器无功损耗(MVar)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_SCCAI,		"Wind_SccAI",	"变压器BUS1侧故障电流(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_SCCAZ,		"Wind_SccAZ",	"变压器BUS1侧故障电流(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_VD_RERR,	"vd_Rerr",		"变压器故障率(次/年)",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC1,	"vd_RScc1",		"单相接地频率(次/年)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC2,	"vd_RScc2",		"相间短路频率(次/年)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC3,	"vd_RScc3",		"三相短路频率(次/年)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC4,	"vd_RScc4",		"两相接地频率(次/年)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_KEYNAME,	"KeyName",		"变压器名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_WIND_INIBUSI,	"IniBusI",		"Ini母线名称1",								MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_INIKVI,	"InikVI",		"Ini基准电压1(kV)",							MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_INIBUSJ,	"IniBusJ",		"Ini母线名称2",								MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_INIKVJ,	"InikVJ",		"Ini基准电压2(kV)",							MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_INILOOP,	"IniLoop",		"Ini并联线路的回路标志",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_BUSIPTR,	"iRBus",		"变压器I母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_WIND_BUSJPTR,	"zRBus",		"变压器Z母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_WIND_RCARD,		"RCard",		"受控变压器(直流母线侧R=1-I,R=2-J)",		MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_ALIAS,		"Alias",		"变压器别名",								MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_WIND_RTTPI,		"RtTPI",		"RT母线1的固定分接头",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_RTTPJ,		"RtTPJ",		"RT母线2的固定分接头",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_STATUS,	"Status",		"状态",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_INRING,	"InRing",		"环网设备",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_WIND_RADIATE,	"Radiate",		"所在辐射网",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_R[]=
{
	{	BPA_DAT_R_CARDKEY,	"CardKey",		"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_R_CHGCODE,	"R_ChgCode",	"修改码",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_R_OWNER,	"R_Owner",		"所有者",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_R_BUSI,		"R_BusI",		"母线名称1",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_R_KVI,		"R_kVI",		"基准电压1(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_VARTAP,	"R_VARTAP",		"可调抽头端标志",			MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_R_BUSJ,		"R_BusJ",		"母线名称2",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_R_KVJ,		"R_kVJ",		"基准电压2(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_BUSC,		"R_BusC",		"被控母线名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_R_KVC,		"R_kVC",		"被控基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_TMAX,		"R_TMax",		"最大抽头位置(kV)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_TMIN,		"R_TMin",		"最小抽头位置(kV)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_TNUM,		"R_TNum",		"LTC抽头总数",				MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_R_VALMAX,	"R_ValMax",		"指定的最大无功功率(Mvar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_VALMIN,	"R_ValMin",		"指定的最小无功功率(Mvar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_P,		"R_P",			"有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_Q,		"R_Q",			"无功(Mvar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_LOSSP,	"R_LossP",		"有功损耗(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_LOSSQ,	"R_LossQ",		"无功损耗(Mvar)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_KEYNAME,	"KeyName",		"调压器名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_R_BUSIPTR,	"R_iRBus",		"变压器I母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_R_BUSJPTR,	"R_zRBus",		"变压器Z母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_R_STATUS,	"R_Status",		"状态",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_DCBus[]=
{
	{	BPA_DAT_DCBUS_CARDKEY,		"CardKey",				"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_DCBUS_CHGCODE,		"DCBus_ChgCode",		"修改码",							MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_DCBUS_OWNER,		"DCBus_Owner",			"所有者",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_DCBUS_NAME,			"DCBus_Name",			"Converter母线名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCBUS_KV,			"DCBus_kV",				"Converter基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ZONE,			"DCBus_Zone",			"Zone,分区名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_DCBUS_BRDGS,		"DCBus_BRDGS",			"整流线路的桥数",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_DCBUS_SMTHGREACTOR,	"DCBus_SMTHGREACTOR",	"平波电抗器电感(毫亨)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ROPERMIN,		"DCBus_ROPERMIN",		"作为整流器运行的最小触发角(度)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_IOPERSTOP,	"DCBus_IOPERSTOP",		"作为逆变器运行的最大触发角(度)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DROP,			"DCBus_DROP",			"每个桥阀的电压降(伏)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_BRDGRATE,		"DCBus_BRDGRATE",		"桥电流额定值(安培)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ACNAME,		"DCBus_ACName",			"换流变压器一次侧母线名称",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCBUS_ACKV,			"DCBus_ACkV",			"换流变压器一次侧基准电压(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCBUS_DCV,			"DCBus_V",				"直流母线电压(kV)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DCD,			"DCBus_D",				"直流母线功角(度)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DCP,			"DCBus_P",				"直流输电有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DCI,			"DCBus_I",				"直流输电电流(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_LOSSP,		"DCBus_LossP",			"直流输电有功损耗(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_LOSSQ,		"DCBus_LossQ",			"直流输电无功损耗(MVar)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ACV,			"DCBus_ACV",			"交流侧母线电压(kV)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ANGLE,		"DCBus_Angle",			"触发/关断角(度)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCBUS_ACBUS,		"ACBus",				"换流变压器一次侧母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ACISLAND,		"ACIsland",				"交流岛",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_DCBUS_SUB,			"Sub",					"母线所属BPA厂站",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_DCBUS_ALIAS,		"Alias",				"直流母线别名",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_DCBUS_STATUS,		"Status",				"状态",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaDat_DCLine[]=
{
	{	BPA_DAT_DCLINE_CARDKEY,	"CardKey",			"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_DCLINE_CHGCODE,	"DCLine_ChgCode",	"修改码",							MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_DCLINE_OWNER,	"DCLine_Owner",		"所有者",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSR,	"DCLine_BusR",		"整流侧母线名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCLINE_KVR,		"DCLine_kVR",		"整流侧基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_METER,	"DCLine_Meter",		"区域联络线测点标志",				MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSI,	"DCLine_BusI",		"逆变侧母线名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCLINE_KVI,		"DCLine_kVI",		"逆变侧基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_AMP,		"DCLine_AMP",		"直流线路额定电流(安培)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_R,		"DCLine_R",			"直流线路电阻(欧姆)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_L,		"DCLine_L",			"直流线路电感(毫亨)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_C,		"DCLine_C",			"直流线路电容(微阀)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_CONTROL,	"DCLine_CONTROL",	"所安排的直流功率的控制点",			MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_DCLINE_DCPOWER,	"DCLine_DCPOWER",	"所安排的直流功率(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_RVOLT,	"DCLine_RVOLT",		"给定直流线路整流侧的直流电压(kV)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_ROPER,	"DCLine_ROPER",		"整流侧的正常触发角(度)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_ISTOP,	"DCLine_ISTOP",		"逆变侧的正常关断角(度)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCLINE_PR,		"DCLine_Pr",		"线路整流侧功率(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_PI,		"DCLine_Pi",		"线路逆变侧功率(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_LOSSP,	"DCLine_Lossp",		"线路有功损耗(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCLINE_KEYNAME,	"KeyName",			"直流线路名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSRPTR,	"iRBus",			"直流线路整流侧母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSIPTR,	"iIBus",			"直流线路逆变侧母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCLINE_ALIAS,	"Alias",			"直流线路别名",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_DCLINE_STATUS,	"Status",			"状态",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_RZ[]=
{
	{	BPA_DAT_RZ_CARDKEY,	"CardKey",		"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_RZ_CHGCODE,	"RZ_ChgCode",	"修改码",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_RZ_OWNER,	"RZ_Owner",		"所有者",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_RZ_BUSI,	"RZ_BusI",		"母线名称1",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_RZ_KVI,		"RZ_kVI",		"基准电压1(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_BUSJ,	"RZ_BusJ",		"母线名称2",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_RZ_KVJ,		"RZ_kVJ",		"基准电压2(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_LOOP,	"RZ_Loop",		"并联线路的回路标志",		MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_RZ_SECTION,	"RZ_Section",	"分段串连而成的线路的段号",	MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_RZ_MODE,	"RZ_Mode",		"控制方式",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_RZ_PCMAX,	"RZ_Pcmax",		"线路有功潮流最大值(MW)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_PCMIN,	"RZ_Pcmin",		"线路有功潮流最小值(MW)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_IN,		"RZ_In",		"线路额定电流值(A)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_XIJMAX,	"RZ_Xijmax",	"线路电抗最大(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_XIJMIN,	"RZ_Xijmin",	"线路电抗最小(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_KEYNAME,	"KeyName",		"串补名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_RZ_BUSIPTR,	"iRBus",		"线路电抗I母线索引",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_RZ_BUSJPTR,	"zRBus",		"线路电抗Z母线索引",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_RZ_STATUS,	"Status",		"状态",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_P[]=
{
	{	BPA_DAT_P_CARDKEY,		"CardKey",			"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_DAT_P_ZONE,			"P_Zone",			"所有者代码",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,		0,	NULL,	},
	{	BPA_DAT_P_LOADPFACTOR,	"P_LoadPFactor",	"负荷有功修改因子",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_LOADQFACTOR,	"P_LoadQFactor",	"负荷无功修改因子",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_GENPFACTOR,	"P_GenPFactor",		"发电出力有功修改因子",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_GENQFACTOR,	"P_GenQFactor",		"发电出力无功修改因子",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_STATUS,		"P_Status",			"状态",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_ZIL[]=
{
	{	BPA_DAT_ZIL_CARDKEY,	"CardKey",			"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_DAT_ZIL_BUSI,		"ZIL_BusI",			"母线名称1",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ZIL_KVI,		"ZIL_kVI",			"基准电压1(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ZIL_BUSJ,		"ZIL_BusJ",			"母线名称2",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ZIL_KVJ,		"ZIL_kVJ",			"基准电压2(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ZIL_LOOP,		"ZIL_Loop",			"并联线路的回路标志",		MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_ZIL_R,			"ZIL_R",			"电阻(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ZIL_X,			"ZIL_X",			"电抗(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ZIL_MBUS,		"ZIL_MBus",			"合并母线名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ZIL_MKV,		"ZIL_MkV",			"合并基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_VDip[]=
{
	{	BPA_DAT_VDIP_FDEVINDEX,	"FDevIndex",	"故障设备索引",		MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_VDIP_FTYPE,		"FaultType",	"故障类型",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumFaultType)/sizeof(tagMemDBEnumPair),	g_BpaEnumFaultType,	},
	{	BPA_DAT_VDIP_DIPBUS,	"DipBus",		"暂降母线",			MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_VDIP_DIPV,		"DipV",			"暂降电压(pu)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_VDIP_POLYPHASE,	"PoluPhase",	"暂降相",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Gen[]=
{
	{	BPA_DAT_GEN_NAME,			"Name",				"名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_GEN_BUS,			"Gen_Bus",			"母线名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_GEN_KV,				"Gen_kV",			"基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_ID,				"Gen_ID",			"电机识别码",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_GEN_PGEN,			"Gen_PGen",			"有功出力(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_QGEN,			"Gen_QGen",			"无功出力(MVar)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_PMAX,			"Gen_PMax",			"最大有功出力(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_PMIN,			"Gen_PMin",			"最小有功出力(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_QMAX,			"Gen_QMax",			"最大无功出力(MVar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_QMIN,			"Gen_QMin",			"最小无功出力(MVar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_VHOLD,			"Gen_VHold",		"安排的电压,PV值(pu)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_ACBUSPTR,		"Gen_ACBusPtr",		"母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_GEN_WGEN,			"Gen_WingGen",		"风电机组",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_GEN_EQ,				"Gen_EQ",			"等值电源",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_GEN_STATUS,			"Gen_Status",		"状态",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Load[]=
{
	{	BPA_DAT_LOAD_NAME,			"Name",				"名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_LOAD_BUS,			"Load_Bus",			"母线名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LOAD_KV,			"Load_kV",			"基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LOAD_PLOAD,			"Load_PLoad",		"有功出力(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LOAD_QLOAD,			"Load_QLoad",		"无功出力(MVar)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LOAD_ACBUSPTR,		"Load_ACBusPtr",	"母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_LOAD_AUX,			"Load_Aux",			"厂用电",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_LOAD_EQ,			"Load_EQ",			"等值负荷",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_LOAD_STATUS,		"Load_Status",		"状态",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Tran[]=
{
	{	BPA_DAT_TRAN_WINDNUM,		"WindNum",			"绕组数",				MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	BPA_DAT_TRAN_WINDH,			"WindH",			"高压绕组",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_TRAN_WINDM,			"WindM",			"中压绕组",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_TRAN_WINDL,			"WindL",			"低压绕组",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_TRAN_IRWINDH,		"iRWindH",			"高压绕组索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_TRAN_IRWINDM,		"iRWindM",			"中压绕组索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_TRAN_IRWINDL,		"iRWindL",			"低压绕组索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeLine[]=
{
	{	BPA_DAT_EDGELINE_BUSNAME,		"BusName",		"母线名称",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGELINE_BUSKV,			"BuskV",		"母线电压(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGELINE_LINENAME,		"LineName",		"线路名称",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGELINE_IRLINE,		"LinePtr",		"线路索引",		MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeWind[]=
{
	{	BPA_DAT_EDGEWIND_BUSNAME,		"BusName",		"母线名称",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGEWIND_BUSKV,			"BuskV",		"母线电压(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGEWIND_WINDNAME,		"WindName",		"绕组名称",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGEWIND_IRWIND,		"WindPtr",		"绕组索引",		MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeLineHG[]=
{
	{	BPA_DAT_EDGELINEHG_BUSNAME,		"BusName",		"母线名称",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGELINEHG_BUSKV,		"BuskV",		"母线电压(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGELINEHG_HGNAME,		"LineHGName",	"高抗名称",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGELINEHG_IRHG,		"LineHGPtr",	"高抗索引",		MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Radiate[]=
{
	{	BPA_DAT_RADIATE_BOUNDBUSNAME,	"BoundBusName",		"电源母线名称",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_RADIATE_BOUNDBUSKV,		"BoundBuskV",		"电源母线电压(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_GENP,			"GenP",				"网内发电有功(MW)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_LOADP,			"LoadP",			"网内负荷有功(MW)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_LOADQ,			"LoadQ",			"网内负荷无功(MVar)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_IRBOUNDBUS,		"iRBoundBus",		"电源母线索引",			MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaScc_FMove[]=
{
	{	BPA_SCC_FMOVE_FAULTTYPE,		"FaultType",		"故障类型",					MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumFaultType)/sizeof(tagMemDBEnumPair),	g_BpaEnumFaultType,	},
	{	BPA_SCC_FMOVE_FAULTLINE,		"FaultLine",		"故障线路",					MDBFieldCategoryOutput,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SCC_FMOVE_MONLINE,			"MonLine",			"监视线路",					MDBFieldCategoryOutput,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SCC_FMOVE_MONBUS,			"MonBus",			"监视母线",					MDBFieldCategoryOutput,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SCC_FMOVE_DATATYPE,			"DataType",			"数据类型",					MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSccFMoveDataType)/sizeof(tagMemDBEnumPair),	g_BpaEnumSccFMoveDataType,	},
	{	BPA_SCC_FMOVE_VALUE000,			"Value000",			"值000",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE001,			"Value001",			"值001",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE002,			"Value002",			"值002",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE003,			"Value003",			"值003",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE004,			"Value004",			"值004",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE005,			"Value005",			"值005",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE006,			"Value006",			"值006",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE007,			"Value007",			"值007",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE008,			"Value008",			"值008",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE009,			"Value009",			"值009",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE010,			"Value010",			"值010",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE011,			"Value011",			"值011",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE012,			"Value012",			"值012",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE013,			"Value013",			"值013",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE014,			"Value014",			"值014",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE015,			"Value015",			"值015",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE016,			"Value016",			"值016",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE017,			"Value017",			"值017",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE018,			"Value018",			"值018",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE019,			"Value019",			"值019",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE020,			"Value020",			"值020",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE021,			"Value021",			"值021",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE022,			"Value022",			"值022",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE023,			"Value023",			"值023",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE024,			"Value024",			"值024",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE025,			"Value025",			"值025",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE026,			"Value026",			"值026",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE027,			"Value027",			"值027",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE028,			"Value028",			"值028",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE029,			"Value029",			"值029",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE030,			"Value030",			"值030",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE031,			"Value031",			"值031",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE032,			"Value032",			"值032",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE033,			"Value033",			"值033",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE034,			"Value034",			"值034",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE035,			"Value035",			"值035",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE036,			"Value036",			"值036",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE037,			"Value037",			"值037",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE038,			"Value038",			"值038",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE039,			"Value039",			"值039",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE040,			"Value040",			"值040",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE041,			"Value041",			"值041",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE042,			"Value042",			"值042",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE043,			"Value043",			"值043",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE044,			"Value044",			"值044",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE045,			"Value045",			"值045",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE046,			"Value046",			"值046",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE047,			"Value047",			"值047",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE048,			"Value048",			"值048",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE049,			"Value049",			"值049",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE050,			"Value050",			"值050",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE051,			"Value051",			"值051",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE052,			"Value052",			"值052",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE053,			"Value053",			"值053",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE054,			"Value054",			"值054",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE055,			"Value055",			"值055",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE056,			"Value056",			"值056",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE057,			"Value057",			"值057",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE058,			"Value058",			"值058",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE059,			"Value059",			"值059",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE060,			"Value060",			"值060",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE061,			"Value061",			"值061",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE062,			"Value062",			"值062",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE063,			"Value063",			"值063",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE064,			"Value064",			"值064",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE065,			"Value065",			"值065",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE066,			"Value066",			"值066",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE067,			"Value067",			"值067",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE068,			"Value068",			"值068",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE069,			"Value069",			"值069",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE070,			"Value070",			"值070",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE071,			"Value071",			"值071",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE072,			"Value072",			"值072",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE073,			"Value073",			"值073",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE074,			"Value074",			"值074",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE075,			"Value075",			"值075",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE076,			"Value076",			"值076",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE077,			"Value077",			"值077",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE078,			"Value078",			"值078",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE079,			"Value079",			"值079",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE080,			"Value080",			"值080",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE081,			"Value081",			"值081",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE082,			"Value082",			"值082",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE083,			"Value083",			"值083",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE084,			"Value084",			"值084",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE085,			"Value085",			"值085",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE086,			"Value086",			"值086",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE087,			"Value087",			"值087",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE088,			"Value088",			"值088",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE089,			"Value089",			"值089",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE090,			"Value090",			"值090",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE091,			"Value091",			"值091",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE092,			"Value092",			"值092",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE093,			"Value093",			"值093",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE094,			"Value094",			"值094",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE095,			"Value095",			"值095",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE096,			"Value096",			"值096",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE097,			"Value097",			"值097",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE098,			"Value098",			"值098",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE099,			"Value099",			"值099",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE100,			"Value100",			"值100",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_Case[]=
{
	{	BPA_SWI_CASE_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_CASE_PFCASE,		"PFCASE",		"潮流方式名",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_SWI_CASE_ITSKP,			"ITSKP",		"写求解文件的步长",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_NOPRNT,		"NOPRNT",		"NOPRNT,为1时打印全部输入数据",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_DSW,			"DSW",			"输出文件摇摆曲线显示开关",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_IWSCC,			"IWSCC",		"采用新减负荷卡减负荷标记",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_ZSW,			"ZSW",			"对零序卡进行检查标志",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_X2FAC,			"X2FAC",		"不对称故障时发电机X2与Xdp之比",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_XFACT,			"XFACT",		"发电机Xdpp与Xdp之比",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TDODPS,		"TDODPS",		"隐级机的Tdopp(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TQODPS,		"TQODPS",		"隐级机的Tdopp(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TDODPH,		"TDODPH",		"凸级水轮机的Tqopp(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TQODPH,		"TQODPH",		"凸级水轮机的Tdopp(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_CFACL2,		"CFACL2",		"负序负荷导纳(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_F1[]=
{
	{	BPA_SWI_F1_CARDKEY,		"CardKey",		"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_F1_TBUSF,		"TBUSF",		"母线频率滤波器缺省时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_F1_TZERO,		"TZERO",		"测量回路缺省时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_F1_IBLOD,		"IBLOD",		"母线负荷开关",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_F1_DMPALL,		"DMPALL",		"缺省发电机阻尼因子",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_F1_IAMRTS,		"IAMRTS",		"如果该值不为0,且F1卡中的XFACT也不为0,无论发电机的次暂态参数是否已经用M卡指定,都要采用缺省的参数来计算发电机的次暂态参数",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),			0,	NULL,	},
	{	BPA_SWI_F1_VCHGL,		"VCHGL",		"如果负荷母线电压低于该值,则负荷将转换为恒阻抗负荷,缺省值为0.5pu",															MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),					0,	NULL,	},
	{	BPA_SWI_F1_SPTOSG,		"SPTOSG",		"SP卡为以加速功率作为输入信号的PSS,而SG卡为以电磁功率为输入信号的PSS;如果该值不为0,则将稳定数据中所有的SP卡改为SG卡",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),			0,	NULL,	},
	{	BPA_SWI_F1_GSIQU,		"GSIQU",		"如果该值不为零,则数据文件中所有GH卡和GS卡的死区的大小都为该值",															MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),					0,	NULL,	},
	{	BPA_SWI_F1_TITSKP,		"TITSKP",		"从本时间开始,按照本卡中的48-49列填写的步数进行存储",																		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),					0,	NULL,	},
	{	BPA_SWI_F1_ITSKP1,		"ITSKP1",		"从本卡43-47列规定的时间TITSKP开始每隔ITSKP1步存储一次数据",																MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),					0,	NULL,	},
	{	BPA_SWI_F1_VRLIM,		"VRLIM",		"FM、FO、FP、FQ、FR、FS、FT和FG型励磁模型的调压器限幅环节为外限幅,如果VRLIM不为0,则将其改为内限幅",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_F0[]=
{
	{	BPA_SWI_F0_CARDKEY,		"CardKey",			"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_F0_IG,			"IG",				"稳定曲线显示选择",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_IA,			"IA",				"发电机最大相对角显示选择",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_BUSNAME1,	"GenBusName1",		"发电机1母线名称",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_BUSVOLT1,	"GenBusBase1",		"发电机1母线电压",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_ID1,			"GenID1",			"发电机1识别码",				MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_F0_BUSNAME2,	"GenBusName2",		"发电机2母线名称",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_BUSVOLT2,	"GenBusBase2",		"发电机2母线电压",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_ID2,			"GenID2",			"发电机2识别码",				MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_F0_AMAX,		"AMAX",				"相对角Y轴坐标的最大值",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_AMIN,		"AMIN",				"相对角Y轴坐标的最小值",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_IV,			"IV",				"母线电压显示选择",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_VBUSNAME,	"VBUSNAME",			"显示电压变化曲线的母线名称",	MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_VBUSVOLT,	"VBUSVOLT",			"显示电压变化曲线的母线电压",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_IF,			"IF",				"母线频率显示选择",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_FBUSNAME,	"FBUSNAME",			"显示频率变化曲线的母线名称",	MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_FBUSVOLT,	"FBUSVOLT",			"显示频率变化曲线的母线电压",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_FF[]=
{
	{	BPA_SWI_FF_CARDKEY,		"CardKey",		"卡类型",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FF_T,			"T",			"计算开始时间(周)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DT,			"DT",			"计算步长(周)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_ENDT,		"ENDT",			"计算终止时间(周)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DTC,			"DTC",			"新的步长(周)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_ISTP,		"ISTP",			"开始改变步长的时刻(周)",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_FF_TOLI,		"TOLI",			"两次迭代间最大加速功率误差范围",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_ILIM,		"ILIM",			"一步内网络方程与微分方程最大交替迭代次数",			MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_FF_DELANG,		"DELANG",		"两次迭代间最大角度误差范围",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DTDV,		"DTDV",			"交流积分步长与直流积分步长之比",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DMPMLT,		"DMPMLT",		"发电机阻尼因子",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_FRQBSE,		"FRQBSE",		"系统基准频率",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_LOVTEX,		"LOVTEX",		"=1无低电压检查,否则进行检查",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_IMBLOK,		"IMBLOK",		"马达滑差达到1时的处理方法",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumFF_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumFF_Stall,	},
	{	BPA_SWI_FF_MFDEP,		"MFDEP",		"摇摆方程与定子方程与频率的关系",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_IGSLIM,		"IGSLIM",		"非零时,所有调速器模型GS都采用外限幅",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_LSOLQIT,		"LSOLQIT",		"=1：迭代不收敛,停止计算",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOANGLIM,	"NOANGLIM",		"=1：无最大角度限制,否则机组间角度超过500度停算",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_INFBUS,		"INFBUS",		"=1：所有发电机改为无穷大惯性电机",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOPP,		"NOPP",			"非零时,所有发电机都不考虑次暂态参数",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NODQ,		"NODQ",			"=1：所有发电机改为经典模型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOSAT,		"NOSAT",		"非零时,所有的发电机不考虑饱和",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOGV,		"NOGV",			"=1：所有发电机不计调速器",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_IEQPC,		"IEQPC",		"非零时,所有发电机的磁链恒定",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOEX,		"NOEX",			"=1：所有发电机不计调压器",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_MFTOMG,		"MFTOMG",		"非零时,所有的发电机卡MF卡都转换为MG卡",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOSC,		"NOSC",			"=1：不计所有辅助信号",								MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_MGTOMF,		"MGTOMF",		"非零时,所有的发电机卡MG卡都转换为MF卡",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOLOAD,		"NOLOAD",		"=1：所有负荷为恒定阻抗",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_Gen[]=
{
	{	BPA_SWI_GEN_CARDKEY,		"CardKey",		"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GEN_BUS_NAME,		"ACBus_Name",	"电机母线名",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GEN_BUS_KV,			"ACBus_kV",		"电机母线电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_ID,				"Gen_ID",		"电机识别码",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GEN_EMWS,			"Gen_Emws",		"发电机动能(MW.秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_P,				"Gen_P",		"发电机初始有功功率占母线潮流功率比例",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_Q,				"Gen_Q",		"发电机初始无功功率占母线潮流功率比例",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_MVABASE,		"Gen_MVABase",	"电机标么参数的基准容量",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_RA,				"Gen_Ra",		"定子电阻(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XDP,			"Gen_Xdp",		"直轴暂态电抗Xdp(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XQP,			"Gen_Xqp",		"交流暂态电抗Xqp(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XD,				"Gen_Xd",		"直轴不饱和同步电抗Xd(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XQ,				"Gen_Xq",		"交轴不饱和同步电抗Xq(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_TD0,			"Gen_Td0",		"直轴暂态开路时间常数Tdop(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_TQ0,			"Gen_Tq0",		"交轴暂态开路时间常数Tqop(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XL_XP,			"Gen_XL_XP",	"定子漏抗(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_SG10,			"Gen_SG10",		"额定电压时电机饱和系数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_SG12,			"Gen_SG12",		"额定电压1.2倍时电机饱和系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_D,				"Gen_D",		"电机阻尼转距系数百分数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_A,				"Gen_A",		"饱和a",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_B,				"Gen_B",		"饱和b",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_N,				"Gen_N",		"饱和N",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_MVA,			"Gen_MVA",		"容量",									MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_KEYNAME,		"KeyName",		"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GEN_BUSPTR,			"BusPtr",		"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GEN_APPENDTAG,		"AppendTag",	"新增记录标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_Damp[]=
{
	{	BPA_SWI_DAMP_CARDKEY,		"CardKey",		"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DAMP_BUS_NAME,		"ACBus_Name",	"电机母线名",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_DAMP_BUS_KV,		"ACBus_kV",		"电机母线电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_ID,			"Damp_ID",		"电机识别码",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_DAMP_MVA,			"Damp_MVA",		"电机额定容量",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_PF,			"Damp_PF",		"电机功率因数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_XDPP,			"Damp_Xdpp",	"直轴次暂态电抗Xdpp(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_XQPP,			"Damp_Xqpp",	"交轴次暂态电抗Xqpp(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_TD0PP,			"Damp_Td0pp",	"直轴次暂态时间常数Td0pp(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_TQ0PP,			"Damp_Tq0pp",	"交轴次暂态时间常数Tq0pp(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_KEYNAME,		"KeyName",		"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_DAMP_BUSPTR,		"BusPtr",		"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_DAMP_APPENDTAG,		"AppendTag",	"新增记录标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_WGEGen[]=
{
	{	BPA_SWI_WGEGEN_CARDKEY,		"CardKey",		"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_BUS_NAME,	"ACBus_Name",	"电机母线名",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_BUS_KV,		"ACBus_kV",		"电机母线电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_ID,			"Gen_ID",		"电机识别码",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_GE_TYPE,		"GE_TYPE",		"风电机组类型代码",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_NG,			"NG",			"风电机组台数",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_NAME_CON,	"NAME_CON",		"风电场无功控制节点名称",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_BASE_CON,	"BASE_CON",		"风电场无功控制节点基准电压",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_PPER,		"PPER",			"有功占潮流总出力比例",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_QPER,		"QPER",			"无功占潮流总出力比例",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_V0,			"V0",			"初始风速(m/s)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_NMASS_FLG,	"NMASS_FLG",	"=0考虑双质量块,否则单质量块",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_QDROOP_FLG,	"QDROOP_FLG",	"=0不考虑QDROOP,否则考虑",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_WINDCON_FLG,	"WINDCON_FLG",	"=0风电场无功电压/恒功率因数控制模式",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_EWVOL_FLG,	"EWVOL_FLG",	"=0电气控制采用电压反馈",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_APCFLG,		"APCFLG",		"=0不采用APC有功控制功能,否则采用",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_FFLG,		"FFLG",			"=0APC功能中采用最大输出限制控制功能",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_INERTIA,		"INERTIA",		"=0不采用WINDINERTIA功能",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_PQFLG,		"PQFLG",		"=0无功优先标志,否则有功优先(直驱)",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_KEYNAME,		"KeyName",		"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_WGEGEN_BUSPTR,		"BusPtr",		"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_GenLn[]=
{
	{	BPA_SWI_GENLN_CARDKEY,		"CardKey",		"卡类型",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GENLN_BUS_NAME,		"ACBus_Name",	"等值发电机名称",		MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GENLN_BUS_KV,		"ACBus_kV",		"等值发电机电压",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GENLN_BUSPTR,		"BusPtr",		"等值发电机母线索引",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GENLN_DCBUS,		"DCBus",		"直流母线",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_Exc68[]=
{
	{	BPA_SWI_EXCIT68_CARDKEY,			"CardKey",				"卡类型",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCIT68_BUS_NAME,			"ACBus_Name",			"母线名称,母线名",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCIT68_BUS_KV,				"ACBus_kV",				"基准电压(kV),基准电压",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_GEN_ID,				"Gen_ID",				"发电机识别码",									MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TR,					"Exc68_TR",				"TR,调压器输入的滤波器时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KA_BUSKV,			"Exc68_KA_BusKV",		"KA,调压器增益",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TR_TRH,				"Exc68_TR_TRH",			"TA,调压器放大器时间常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TA1,				"Exc68_TA1",			"TA1,调压器放大器时间常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_VRMINMULT_TRMAX,	"Exc68_VRMinMult_TRMax","VRMAXMULT,VRMAX乘子",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KE,					"Exc68_KE",				"KE,与自励有关的励磁常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TE,					"Exc68_TE",				"TE,励磁机时间常数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_SE75MAX_KI,			"Exc68_SE75Max_KI",		"SE.75MAX,75％最大励磁电压时的励磁机饱和系数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_SEMAX_KP,			"Exc68_SEMax_KP",		"SEMAX,最大励磁电压时的励磁机饱和系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_EFDMIN,				"Exc68_EFDMin",			"EFDMIN,最小励磁电压",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_EFDMAX_VBMAX,		"Exc68_EFDMax_VBMax",	"EFDMAX,最大励磁电压",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KF,					"Exc68_KF",				"KF,调压器稳定回路增益",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TF,					"Exc68_TF",				"TF,调压器稳定回路时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_XL,					"Exc68_XL",				"XL,整流电抗",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TF1,				"Exc68_TF1",			"TF1,调压器稳定回路时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KEYNAME,			"KeyName",				"数据库主键",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCIT68_BUSPTR,				"BusPtr",				"发电机母线索引",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_APPENDTAG,			"AppendTag",			"新增记录标记",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_Exc81[]=
{
	{	BPA_SWI_EXCIT81_CARDKEY,			"CardKey",				"卡类型",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCIT81_BUS_NAME,			"ACBus_Name",			"母线名",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCIT81_BUS_KV,				"ACBus_kV",				"基准电压",																MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_GEN_ID,				"Gen_ID",				"发电机识别码",															MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_RC,					"Exc81_RC",				"负载补偿之有功关分量(pu)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_XC,					"Exc81_XC",				"负载补偿之有功关分量(pu)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TR,					"Exc81_TR",				"调节器输入滤波器时间常数(秒)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VIAMAX_VAMAX,		"Exc81_VIAMax_VAMax",	"电压调节器滞后时间常数(秒)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VIMIN_VAMIN,		"Exc81_VIMin_VAMin",	"电压调节器超前时间常数(秒)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TB,					"Exc81_TB",				"电压调节器增益(pu)",													MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TC,					"Exc81_TC",				"电压调节器滞后时间常数(秒)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_KA_BUSKV,			"Exc81_KA_BusKV",		"电压调节器最大输出(pu)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TA_TRH,				"Exc81_TA_TRH",			"电压调节器最小输出(pu)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VRMAX_VAMAX,		"Exc81_VRMax_VAMax",	"励磁机自励磁时间常数(pu)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VRMIN_VAMIN,		"Exc81_VRMin_VAMin",	"励磁机时间常数(秒)",													MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_EFDMAX_VBMAX,		"Exc81_EFDMax_VBMax",	"调压器稳定回路增益(pu)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_KE_KJ,				"Exc81_KE_KJ",			"第一级调节器增益(pu)",													MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TE,					"Exc81_TE",				"励磁机时间常数(秒)",													MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_KEYNAME,			"KeyName",				"数据库主键",															MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCIT81_BUSPTR,				"BusPtr",				"发电机母线索引",														MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_APPENDTAG,			"AppendTag",			"新增记录标记",															MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_ExcMV[]=
{
	{	BPA_SWI_EXCITMV_CARDKEY,			"CardKey",			"卡类型",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCITMV_BUS_NAME,			"ACBus_Name",		"母线名",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCITMV_BUS_KV,				"ACBus_kV",			"基准电压",											MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_GEN_ID,				"Gen_ID",			"发电机识别码",										MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_RC,					"ExcMV_RC",			"负载补偿之有功关分量(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_XC,					"ExcMV_XC",			"负载补偿之有功关分量(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_TR,					"ExcMV_TR",			"调节器输入滤波器时间常数(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_K,					"ExcMV_K",			"调节器增益(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KV,					"ExcMV_kV",			"比例积分或纯积分调节选择因子",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T1,					"ExcMV_T1",			"电压调节器时间常数(秒)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T2,					"ExcMV_T2",			"电压调节器时间常数(秒)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T3,					"ExcMV_T3",			"电压调节器时间常数(秒)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T4,					"ExcMV_T4",			"电压调节器时间常数(秒)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KA,					"ExcMV_KA",			"调压器增益(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_TA,					"ExcMV_TA",			"调压器放大器的时间常数(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KF,					"ExcMV_KF",			"调压器稳定回路增益(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_TF,					"ExcMV_TF",			"调压器稳定回路时间常数(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KH,					"ExcMV_KH",			"励磁机电流反馈增益(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KEYNAME,			"KeyName",			"数据库主键",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCITMV_BUSPTR,				"BusPtr",			"发电机母线索引",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_APPENDTAG,			"AppendTag",		"新增记录标记",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_FZ[]=
{
	{	BPA_SWI_FZ_CARDKEY,				"CardKey",				"卡类型",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FZ_BUS_NAME,			"ACBus_Name",			"母线名",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FZ_BUS_KV,				"ACBus_kV",				"基准电压",																MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_GEN_ID,				"Gen_ID",				"发电机识别码",															MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_FZ_SE1_KI,				"FZ_SE1_KI",			"励磁电压处的励磁机饱和系数/电流回路增益系数(D、L)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_SE2_KP,				"FZ_SE2_KP",			"励磁电压75％处的励磁机饱和系数/电势回路增益系数(D、L)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_EFDMIN_EFDN_DP,		"FZ_EFDMin_EFDN_DP",	"励磁机最小输出电压(J)/稳定反馈增益改变处的励磁电压/电压回路像角差(L)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_EFD1_VE1_EFDMAX,		"FZ_EFD1_VE1_EFDMax",	"励磁电压(A、B、E)/换向电抗后励磁电压(C、F、H)/最大励磁电压(D、L)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KF_KG,				"FZ_KF_KG",				"励磁控制系统稳定器增益/内反馈回路常数(L)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_TF_VGMAX,			"FZ_TF_VGMax",			"励磁控制系统时间常数/内反馈回路最大电压(L)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KC,					"FZ_KC",				"换相电抗的整流器负载因子",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KD_XL,				"FZ_KD_XL",				"去磁因子(C、F、H)/电势源电抗(L)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KB_VLV,				"FZ_KB_VLV",			"第二极调节器增益(F)/励磁机低电压限制(H)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KL_KLV,				"FZ_KL_KLV",			"励磁机励磁电流限制增益(F)/励磁机低电压限制信号增益(H)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KH_KN,				"FZ_KH_KN",				"励磁机励磁电流反馈增益(F)/励磁控制系统稳定器增益(上段)(H)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_VLR_KR,				"FZ_VLR_KR",			"励磁机励磁电流限制(F)/联接调节器和变换器励磁功率的常数(H)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KEYNAME,				"KeyName",				"数据库主键",															MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FZ_BUSPTR,				"BusPtr",				"发电机母线索引",														MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_FZ_APPENDTAG,			"AppendTag",			"新增记录标记",															MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_FCA[]=
{
	{	BPA_SWI_FCA_CARDKEY,			"CardKey",			"卡类型",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FCA_BUS_NAME,			"ACBus_Name",		"母线名",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FCA_BUS_KV,				"ACBus_kV",			"基准电压",											MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_GEN_ID,				"Gen_ID",			"发电机识别码",										MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_FCA_VAMAX,				"FCA_VAMax",		"调节器最大内部电压(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VAMIN,				"FCA_VAMin",		"调节器最小内部电压(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KB,					"FCA_KB",			"第二级调节器增益",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_T5,					"FCA_T5",			"第二级调节器时间常数",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KE,					"FCA_KE",			"励磁机自励磁系数(pu)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_TE,					"FCA_TE",			"励磁机时间常数(秒)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_SE1,				"FCA_SE1",			"最大励磁电压处的励磁机饱和系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_SE2,				"FCA_SE2",			"SE2,75％最大励磁电压处的励磁机饱和系数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VRMAX,				"FCA_VRMax",		"电压调节器最大输出(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VRMIN,				"FCA_VRMin",		"电压调节器最小输出(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KC,					"FCA_KC",			"换相电抗的整流器负载因子",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KD,					"FCA_KD",			"去磁因子(pu)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KL1,				"FCA_KL1",			"励磁机励磁电流限制增益(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VL1R,				"FCA_VL1R",			"励磁机电流限制(pu)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_EFDMAX,				"FCA_EFDMax",		"最大励磁电压(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_FCA_KEYNAME,			"KeyName",			"数据库主键",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FCA_BUSPTR,				"BusPtr",			"发电机母线索引",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_FCA_APPENDTAG,			"AppendTag",		"新增记录标记",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_FCB[]=
{
	{	BPA_SWI_FCB_CARDKEY,			"CardKey",			"卡类型",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FCB_BUS_NAME,			"ACBus_Name",		"母线名",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FCB_BUS_KV,				"ACBus_kV",			"基准电压",											MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_GEN_ID,				"Gen_ID",			"发电机识别码",										MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_FCB_IPID,				"FCB_IPID",			"IPID",												MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FCB_KP,					"FCB_KP",			"并联PID环节的比例环节系数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_KI,					"FCB_KI",			"并联PID环节的积分环节系数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_KD,					"FCB_KD",			"并联PID环节的微分环节系数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_TD,					"FCB_TD",			"并联PID环节的微分环节时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_INTMAX,				"FCB_INTMAX",		"并联PID环节的积分环节限幅最大值",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_INTMIN,				"FCB_INTMIN",		"并联PID环节的积分环节限幅最小值",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_DEVMAX,				"FCB_DEVMAX",		"并联PID环节的微分环节限幅最大值",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_DEVMIN,				"FCB_DEVMIN",		"并联PID环节的微分环节限幅最小值",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_FCB_VALMAX,				"FCB_VAlMax",		"串联PID环节的限幅最大值",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_VALMIN,				"FCB_VAlMin",		"串联PID环节的限幅最小值",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_IFUFV,				"FCB_IFUFV",			"FU、FV励磁模型是否含有可控硅整流器输出的修订",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},

	{	BPA_SWI_FCB_KEYNAME,			"KeyName",			"数据库主键",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FCB_BUSPTR,				"BusPtr",			"发电机母线索引",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_FCB_APPENDTAG,			"AppendTag",		"新增记录标记",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_ExcX[]=
{
	{	BPA_SWI_EXCITX_CARDKEY,			"CardKey",			"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCITX_BUS_NAME,		"ACBus_Name",		"母线名",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCITX_BUS_KV,			"ACBus_kV",			"基准电压",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_GEN_ID,			"Gen_ID",			"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCITX_RC,				"ExcX_RC",			"负载补偿之有功关分量(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_XC,				"ExcX_XC",			"负载补偿之有功关分量(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_TR,				"ExcX_TR",			"调节器输入滤波器时间常数(秒)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KA,				"ExcX_KA",			"调节器增益(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_TA,				"ExcX_TA",			"调节器时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KP,				"ExcX_Kp",			"比例增益(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KI,				"ExcX_KI",			"积分系数(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VRMAX,			"ExcX_VRMax",		"电压调节器最大输出(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VRMIN,			"ExcX_VRMin",		"电压调节器最小输出(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_IKP,				"ExcX_IKp",			"电流环比例增益(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_IKI,				"ExcX_IKI",			"电流环积分系数(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VFMAX,			"ExcX_VFMax",		"电流环的最大限幅(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VFMIN,			"ExcX_VFMin",		"电流环的最小限幅(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KT,				"ExcX_KT",			"可控硅整流器增益(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_TT,				"ExcX_TT",			"可控硅整流器时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_EXCITXEX_KIFD,			"ExcEX_Kifd",		"励磁电流反馈环节放大倍数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITXEX_TIFD,			"ExcEX_Tifd",		"励磁电流反馈环节时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITXEX_EFDMIN,		"ExcEX_EFDMin",		"最小励磁电压(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITXEX_EFDMAX,		"ExcEX_EFDMax",		"最大励磁电压(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_EXCITX_KEYNAME,			"KeyName",			"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCITX_BUSPTR,			"BusPtr",			"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCITX_APPENDTAG,		"AppendTag",		"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssS[]=
{
	{	BPA_SWI_PSSS_CARDKEY,		"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSS_BUS_NAME,		"ACBus_Name",		"母线名",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSS_BUS_KV,		"ACBus_kV",			"基准电压",								MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_GEN_ID,		"Gen_ID",			"发电机识别码",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSS_KQV,			"PssS_KQV",			"电压控制增益",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQV,			"PssS_TQV",			"电压变送器时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_KQS,			"PssS_KQS",			"频率、加速功率和轴滑差控制增益",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQS,			"PssS_TQS",			"频率、加速功率和轴滑差控制时间常数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ,			"PssS_TQ",			"PSS控制时间常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ1,			"PssS_TQ1",			"第一个滞后时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ1P,			"PssS_TQ1P",		"第一个超前时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ2,			"PssS_TQ2",			"第二个滞后时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ2P,			"PssS_TQ2P",		"第二个超前时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ3,			"PssS_TQ3",			"第三个滞后时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ3P,			"PssS_TQ3P",		"第三个超前时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_VSMAX,			"PssS_VSmax",		"PSS最大输出(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_VCUTOFF,		"PssS_VCutOff",		"参考电压值,其意义见框图说明",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_VSLOW,			"PssS_VSlow",		"用于确定VSMIN值",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_KQBASE,		"PssS_KQBase",		"KQ的基准容量(MVA)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_RBUSNAME,		"PssS_RBusName",	"远方母线名",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSS_RBUSKV,		"PssS_RBuskV",		"远方母线基准电压",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_KEYNAME,		"KeyName",			"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSS_BUSPTR,		"BusPtr",			"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSS_IRRBUS,		"PssS_iRRBus",		"远方母线母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSS_APPENDTAG,		"AppendTag",		"新增记录标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssST[]=
{
	{	BPA_SWI_PSSST_CARDKEY,		"CardKey",		"卡类型",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSST_BUS_NAME,		"ACBus_Name",	"母线名",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSST_BUS_KV,		"ACBus_kV",		"基准电压",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_GEN_ID,		"Gen_ID",		"发电机识别码",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSST_T1,			"PssST_T1",		"时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_T2,			"PssST_T2",		"时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_T3,			"PssST_T3",		"时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_K,			"PssST_K",		"频率标么值常数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_DWT1,			"PssST_DWt1",	"频率偏差1",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_DWT2,			"PssST_DWt2",	"频率偏差2",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_DWPT,			"PssST_DWpt",	"频率偏差3",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_TDELAY,		"PssST_TDelay",	"触发延时时间常数(周)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_T4,			"PssST_T4",		"时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_KEYNAME,		"KeyName",		"数据库主键",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSST_BUSPTR,		"BusPtr",		"发电机母线索引",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSST_APPENDTAG,	"AppendTag",	"新增记录标记",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSH[]=
{
	{	BPA_SWI_PSSSH_CARDKEY,		"CardKey",			"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSH_BUS_NAME,		"ACBus_Name",		"母线名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSH_BUS_KV,		"ACBus_kV",			"基准电压",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_GEN_ID,		"Gen_ID",			"发电机识别码",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSSH_TD,			"PssSH_TD",			"TD",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_T1,			"PssSH_T1",			"T1",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_T2,			"PssSH_T2",			"T2",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_T3,			"PssSH_T3",			"T3",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K0,			"PssSH_K0",			"K0",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K1,			"PssSH_K1",			"K1",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K2,			"PssSH_K2",			"K2",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K3,			"PssSH_K3",			"K3",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K,			"PssSH_K",			"K",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_VSMAX,		"PssSH_VSMax",		"PSS最大输出(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_VSMIN,		"PssSH_VSMin",		"PSS最小输出(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_KP,			"PssSH_KP",			"KP",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_KMVA,			"PssSH_KMVA",		"KP的基准容量(MVA)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_PSSSHEX_KPM,		"PssSHEX_KPM",		"KPM",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TPM,		"PssSHEX_TPM",		"TPM",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KPE,		"PssSHEX_KPE",		"KPE",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TPE,		"PssSHEX_TPE",		"TPE",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KW,			"PssSHEX_KW",		"KW",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TW,			"PssSHEX_TW",		"TW",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TD1,		"PssSHEX_TD1",		"TD1",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TD2,		"PssSHEX_TD2",		"TD2",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KD1,		"PssSHEX_KD1",		"本参数目前仅限于填写0或者1",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSHEX_T4,			"PssSHEX_T4",		"T4",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_K4,			"PssSHEX_K4",		"K4",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KMVA,		"PssSHEX_KMVA"	,	"KPM和KPE的基准容量(MVA)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_PSSSH_KEYNAME,		"KeyName",			"数据库主键",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSH_BUSPTR,		"BusPtr",			"发电机母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSH_APPENDTAG,	"AppendTag",		"新增记录标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSI[]=
{
	{	BPA_SWI_PSSSI_CARDKEY,			"CardKey",				"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSI_BUS_NAME,			"ACBus_Name",			"发电机母线名",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSI_BUS_KV,			"ACBus_kV",				"发电机基准电压(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_GEN_ID,			"Gen_ID",				"发电机识别码",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSSI_TRW,				"PssSI_TRW",			"TRW",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T5,				"PssSI_T5",				"T5",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T6,				"PssSI_T6",				"T6",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T7,				"PssSI_T7",				"T7",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_KR,				"PssSI_KR",				"KR",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_TRP,				"PssSI_TRP",			"TRP",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_TW,				"PssSI_TW",				"TW",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_TW1,				"PssSI_TW1",			"TW1",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_TW2,				"PssSI_TW2",			"TW2",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_KS,				"PssSI_KS",				"KS",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T9,				"PssSI_T9",				"T9",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T10,				"PssSI_T10",			"T10",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T12,				"PssSI_T12",			"T12",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_INP,				"PssSI_INP",			"输入信号",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumPssSI_INP)/sizeof(tagMemDBEnumPair),	g_BpaEnumPssSI_INP,	},
	{	BPA_SWI_PSSSI_KP,				"PssSI_KP",				"KP",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T1,				"PssSI_T1",				"T1",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T2,				"PssSI_T2",				"T2",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T13,				"PssSI_T13",			"T13",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T14,				"PssSI_T14",			"T14",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T3,				"PssSI_T3",				"T3",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_T4,				"PssSI_T4",				"T4",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_VSMAX,			"PssSI_VSMax",			"VSMAX",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_VSMIN,			"PssSI_VSMin",			"VSMIN",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_IB,				"PssSI_IB",				"IB",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumPssSI_IB)/sizeof(tagMemDBEnumPair),	g_BpaEnumPssSI_IB,	},
	{	BPA_SWI_PSSSI_MEABUSNAME,		"PssSI_MeaBusName",		"MeaName",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSI_MEABUSKV,			"PssSI_MeaBusKV",		"MeaKV",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_KMVA,				"PssSI_KMVA",			"SI卡中的KR的基准容量(MVA)",MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_KEYNAME,			"KeyName",				"数据库主键",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSI_BUSPTR,			"BusPtr",				"发电机母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSI_IRMEABUS,			"Gen_iRMeaBus",			"量测母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSI_APPENDTAG,		"AppendTag",			"新增记录标记",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSA[]=
{
	{	BPA_SWI_PSSSA_CARDKEY,		"CardKey",			"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSA_BUS_NAME,		"ACBus_Name",		"发电机名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSA_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_GEN_ID,		"Gen_ID",			"发电机识别码",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T1,			"PssSA_T1",			"T1,滤波器时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T2,			"PssSA_T2",			"T2,滤波器时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T3,			"PssSA_T3",			"T3,滤波器时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T4,			"PssSA_T4",			"T4,滤波器时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T5,			"PssSA_T5",			"T5,滤波器时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T6,			"PssSA_T6",			"T6,滤波器时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_K1,			"PssSA_K1",			"K1,速度信号放大倍数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_K2,			"PssSA_K2",			"K2,加速度信号放大倍数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_K,			"PssSA_K",			"K*",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_A,			"PssSA_A",			"A,放大倍数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_P,			"PssSA_P",			"P,相位",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_LIMITMAX,		"PssSA_LimitMax",	"LIMIT-MAX,输出的最大限幅",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_LIMITMIN,		"PssSA_LimitMin",	"LIMIT-MIN,输出的最大限幅",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_KMVA,			"PssSA_KMVA",		"K的基准容量",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_KEYNAME,		"KeyName",			"数据库主键",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSA_BUSPTR,		"BusPtr",			"发电机母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSA_APPENDTAG,	"AppendTag",		"新增记录标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSB[]=
{
	{	BPA_SWI_PSSSB_CARDKEY,			"CardKey",				"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSB_BUS_NAME,			"ACBus_Name",			"发电机名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSB_BUS_KV,			"ACBus_KV",				"发电机基准电压(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_GEN_ID,			"Gen_ID",				"BusID识别码ID",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSSB_ISIG,				"PssSB_ISIG",			"ISIG,输入信号标志",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSB_TD,				"PssSB_TD",				"TD(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW1,				"PssSB_TW1",			"TW1(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW2,				"PssSB_TW2",			"TW2(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T6,				"PssSB_T6",				"T6(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW3,				"PssSB_TW3",			"TW3(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW4,				"PssSB_TW4",			"TW4(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T7,				"PssSB_T7",				"T7(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KS2,				"PssSB_KS2",			"KS2",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KS3,				"PssSB_KS3",			"KS3",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KPG,				"PssSB_KPG",			"KPG(PU)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_MVA_BSE,			"PssSB_MVA_BSE",		"MVA_BSE(MVA)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T8,				"PssSB_T8",				"T8(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T9,				"PssSB_T9",				"T9(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_M,				"PssSB_M",				"M",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSB_N,				"PssSB_N",				"N",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSB_KS1,				"PssSB_KS1",			"KS1",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T1,				"PssSB_T1",				"T1(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T2,				"PssSB_T2",				"T2(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T3,				"PssSB_T3",				"T3(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T4,				"PssSB_T4",				"T4(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_VPMAX,			"PssSB_VPMax",			"VPMAX",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_VPMIN,			"PssSB_VPMin",			"VPMIN",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KEYNAME,			"KeyName",				"数据库主键",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSB_BUSPTR,			"BusPtr",				"发电机母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSB_APPENDTAG,		"AppendTag",			"新增记录标记",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGG[]=
{
	{	BPA_SWI_GG_CARDKEY,			"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_GG_BUS_NAME,		"ACBus_Name",	"发电机名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,			0,	NULL,	},
	{	BPA_SWI_GG_BUS_KV,			"ACBus_kV",		"发电机基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_GEN_ID,			"Gen_ID",		"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),				0,	NULL,	},
	{	BPA_SWI_GG_PMAX,			"Gen_Pmax",		"原动机最大输出功率(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_R,				"GG_R",			"调差系数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T1,				"GG_T1",		"控制时间",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T2,				"GG_T2",		"水轮机恢复时间",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T3,				"GG_T3",		"伺服机时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T4,				"GG_T4",		"汽轮机阀时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T5,				"GG_T5",		"水轮机1/2倍水锤效应时间常数/汽轮机再热器时间常数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GG_F,				"GG_F",			"水轮机F=－2;对汽轮机F=再热器前轴容量/总的轴容量",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GG_KEYNAME,			"KeyName",		"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_SWI_GG_BUSPTR,			"BusPtr",		"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),				0,	NULL,	},
	{	BPA_SWI_GG_APPENDTAG,		"AppendTag",	"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGH[]=
{
	{	BPA_SWI_GH_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GH_BUS_NAME,	"ACBus_Name",	"发电机名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GH_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_GEN_ID,		"Gen_ID",		"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GH_PMAX,		"Gen_Pmax",		"原动机最大输出功率(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_R,			"GH_R",			"调差系数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TG,			"GH_TG",		"调速器响应时间",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TP,			"GH_TP",		"引导阀门时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TD,			"GH_Td",		"软反馈时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TW_HALF,		"GH_Tw_Half",	"水锤效应时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_VELCLOSE,	"GH_VELclose",	"最大水门关闭速度,每秒标么",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_VELOPEN,		"GH_VELopen",	"最大水门开启速度,每秒标么",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_DD,			"GH_Dd",		"软反馈环节系数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_E,			"GH_E",			"死区,为相对于系统频率的标么值",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_KEYNAME,		"KeyName",		"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GH_BUSPTR,		"BusPtr",		"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GH_APPENDTAG,	"AppendTag",	"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGC[]=
{
	{	BPA_SWI_GC_CARDKEY,			"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_GC_BUS_NAME,		"ACBus_Name",	"发电机名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,			0,	NULL,	},
	{	BPA_SWI_GC_BUS_KV,			"ACBus_kV",		"发电机基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_GEN_ID,			"Gen_ID",		"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),				0,	NULL,	},
	{	BPA_SWI_GC_PMAX,			"Gen_Pmax",		"原动机最大输出功率(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_R,				"GC_R",			"调差系数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T1,				"GC_T1",		"控制时间",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T2,				"GC_T2",		"水轮机恢复时间",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T3,				"GC_T3",		"伺服机时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T4,				"GC_T4",		"汽轮机阀时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T5,				"GC_T5",		"汽轮机再热器时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_F,				"GC_F",			"再热器前轴容量/总的轴容量",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_DH,				"GC_DH",		"转子阻尼的近似值",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_KEYNAME,			"KeyName",		"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_SWI_GC_BUSPTR,			"BusPtr",		"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),				0,	NULL,	},
	{	BPA_SWI_GC_APPENDTAG,		"AppendTag",	"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),		sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGS[]=
{
	{	BPA_SWI_GS_CARDKEY,		"CardKey",			"卡类型",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GS_BUS_NAME,	"ACBus_Name",		"发电机名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GS_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_GEN_ID,		"Gen_ID",			"发电机识别码",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GS_PMAX,		"Gen_Pmax",			"原动机最大输出功率(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_PMIN,		"Gen_Pmin",			"原动机最小输出功率(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_R,			"GS_R",				"调差系数",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_T1,			"GS_T1",			"控制时间",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_T2,			"GS_T2",			"一般为零",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_T3,			"GS_T3",			"伺服机时间常数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_VELOPEN,		"GS_VELopen",		"最大的汽门开启速度(每秒标么),必为正数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_VELCLOSE,	"GS_VELclose",		"最大的汽门关闭速度(每秒标么),必为正数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_E,			"GS_E",				"死区,为相对于系统频率的标么值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_KEYNAME,		"KeyName",			"数据库主键",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GS_BUSPTR,		"BusPtr",			"发电机母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GS_APPENDTAG,	"AppendTag",		"新增记录标记",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGL[]=
{
	{	BPA_SWI_GL_CARDKEY,		"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GL_BUS_NAME,	"ACBus_Name",		"发电机名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GL_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_GEN_ID,		"Gen_ID",			"发电机识别码",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GL_PE,			"GL_Pe",			"原动机额定输出功率(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_K,			"GL_K",				"转速放大倍数(系统速度变动率的倒数)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_E,			"GL_E",				"系统迟缓率",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TR,			"GL_Tr",			"调速器滑阀组时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TB,			"GL_Tb",			"中间滑阀组时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TO,			"GL_To",			"油动机开启时间常数	",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TC,			"GL_Tc",			"油动机关闭时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_VELCLOSE,	"GL_VELclose",		"最大关闭速度,标么",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_VELOPEN,		"GL_VELopen",		"最大开启速度,标么",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_PMAX,		"Gen_Pmax",			"最大原动机输出功率,标幺值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_PMIN,		"Gen_Pmin",			"最小原动机输出功率,标幺值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_KEYNAME,		"KeyName",			"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GL_BUSPTR,		"BusPtr",			"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GL_APPENDTAG,	"AppendTag",		"新增记录标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGW[]=
{
	{	BPA_SWI_GW_CARDKEY,		"CardKey",			"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GW_BUS_NAME,	"ACBus_Name",		"发电机名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GW_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_GEN_ID,		"Gen_ID",			"发电机识别码",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GW_PMAX,		"Gen_Pmax",			"原动机最大输出功率(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_PMIN,		"Gen_Pmin",			"原动机最小输出功率(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_R,			"GW_R",				"调差系数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_T1,			"GW_T1",			"控制时间",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_T2,			"GW_T2",			"一般为零",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_T3,			"GW_T3",			"伺服机时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_KEYNAME,		"KeyName",			"数据库主键",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GW_BUSPTR,		"BusPtr",			"发电机母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GW_APPENDTAG,	"AppendTag",		"新增记录标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGA[]=
{
	{	BPA_SWI_GA_CARDKEY,			"CardKey",			"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GA_BUS_NAME,		"ACBus_Name",		"发电机名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GA_BUS_KV,			"ACBus_kV",			"发电机基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_GEN_ID,			"Gen_ID",			"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GA_PE,				"GA_Pe",			"原动机额定输出功率(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_TC,				"GA_Tc",			"油动机关闭时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_TO,				"GA_To",			"油动机开启时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_VELCLOSE,		"GA_VELclose",		"过速关闭系数(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_VELOPEN,			"GA_VELopen",		"过速开启系数(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PMAX,			"Gen_Pmax",			"最大原动机输出功率(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PMIN,			"Gen_Pmin",			"最小原动机输出功率(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_T1,				"GA_T1",			"油动机行程反馈环节(LVDT)时间",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KP,				"GA_KP",			"比例放大倍数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KD,				"GA_KD",			"微分倍数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KI,				"GA_KI",			"积分倍数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_INTG_MAX,		"GA_INTG_MAX",		"积分上限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_INTG_MIN,		"GA_INTG_MIN",		"积分下限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PID_MAX,			"GA_PID_MAX",		"输出上限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PID_MIN,			"GA_PID_MIN",		"输出下限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PGV_DELAY,		"GA_PGV_DELAY",		"功率输出信号的纯时迟(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KEYNAME,			"KeyName",			"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GA_BUSPTR,			"BusPtr",			"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GA_APPENDTAG,		"AppendTag",		"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGI[]=
{
	{	BPA_SWI_GI_CARDKEY,		"CardKey",			"卡类型",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GI_BUS_NAME,	"ACBus_Name",		"发电机名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GI_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_GEN_ID,		"Gen_ID",			"发电机识别码",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GI_T1,			"GI_T1",			"转速变换环节时间常数(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_E,			"GI_E",				"死区ε(相对系统频率的标么值)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_K,			"GI_K",				"转速偏差放大倍数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_I1,			"GI_I1",			"负荷自动开关",								MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSwicth)/sizeof(tagMemDBEnumPair),	g_BpaEnumSwicth,	},
	{	BPA_SWI_GI_KP1,			"GI_KP1",			"负荷控制器PID比例环节倍数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KD1,			"GI_KD1",			"负荷控制器PID微分环节倍数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KI1,			"GI_KI1",			"负荷控制器PID积分环节倍数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MAX1,	"GI_INTG_MAX1",		"负荷控制器PID积分环节限幅上限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MIN1,	"GI_INTG_MIN1",		"负荷控制器PID积分环节限幅下限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MAX1,	"GI_PID_MAX1",		"负荷控制器PID输出限幅环节的上限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MIN1,	"GI_PID_MIN1",		"负荷控制器PID输出限幅环节的下限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_I_FEED,		"GI_I_Feed",		"负荷前馈开关位置",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSwicth)/sizeof(tagMemDBEnumPair),	g_BpaEnumSwicth,	},
	{	BPA_SWI_GI_W_MAX,		"GI_W_MAX",			"一次调频负荷",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_W_MIN,		"GI_W_MIN",			"一次调频负荷",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_GI_I2,			"GI_I2",			"调节级压力自动开关",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSwicth)/sizeof(tagMemDBEnumPair),	g_BpaEnumSwicth,	},
	{	BPA_SWI_GI_KP2,			"GI_KP2",			"调节级压力控制器PID比例环节倍数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KD2,			"GI_KD2",			"调节级压力控制器PID微分环节倍数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KI2,			"GI_KI2",			"调节级压力控制器PID积分环节倍数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MAX2,	"GI_INTG_MAX2",		"调节级压力控制器PID积分环节限幅上限",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MIN2,	"GI_INTG_MIN2",		"调节级压力控制器PID积分环节限幅下限",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MAX2,	"GI_PID_MAX2",		"调节级压力控制器PID输出限幅环节的上限",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MIN2,	"GI_PID_MIN2",		"调节级压力控制器PID输出限幅环节的下限",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_CON_MAX,		"GI_CON_MAX",		"整个控制环节输出限幅环节的上限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_CON_MIN,		"GI_CON_MIN",		"整个控制环节输出限幅环节的下限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_GI_KEYNAME,		"KeyName",			"数据库主键",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GI_BUSPTR,		"BusPtr",			"发电机母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GI_APPENDTAG,	"AppendTag",		"新增记录标记",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGJ[]=
{
	{	BPA_SWI_GJ_CARDKEY,		"CardKey",			"卡类型",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GJ_BUS_NAME,	"ACBus_Name",		"发电机名称",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GJ_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_GEN_ID,		"Gen_ID",			"发电机识别码",									MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GJ_T1,			"GJ_T1",			"转速测量环节时间常数(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_E,			"GJ_E",				"转速偏差死区",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_K1,			"GJ_K1",			"转速偏差放大倍数",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_I,			"GJ_I",				"控制方式选择",									MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGJ_ControlMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGJ_ControlMode,	},
	{	BPA_SWI_GJ_KP,			"GJ_KP",			"PID比例环节倍数",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_KD,			"GJ_KD",			"PID微分环节倍数",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_KI,			"GJ_KI",			"PID积分环节倍数",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_INTG_MAX,	"GJ_INTG_MAX",		"PID积分环节限幅上限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_INTG_MIN,	"GJ_INTG_MIN",		"PID积分环节限幅下限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_PID_MAX,		"GJ_PID_MAX",		"PID输出限幅环节的上限",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_PID_MIN,		"GJ_PID_MIN",		"PID输出限幅环节的下限",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_K2,			"GJ_K2",			"负荷控制前馈系数",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_W_MAX,		"GJ_W_MAX",			"一次调频负荷上限",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_W_MIN,		"GJ_W_MIN",			"一次调频负荷下限",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_TW_DELAY,	"GJ_TW_DELAY",		"频率输入信号的纯时迟(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_TP_DELAY,	"GJ_TP_DELAY",		"功率反馈信号的纯时迟(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_TR,			"GJ_TR",			"功率反馈信号对应的一阶惯性环节时间常数(秒)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_KEYNAME,		"KeyName",			"数据库主键",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GJ_BUSPTR,		"BusPtr",			"发电机母线索引",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GJ_APPENDTAG,	"AppendTag",		"新增记录标记",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGK[]=
{
	{	BPA_SWI_GK_CARDKEY,		"CardKey",			"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GK_BUS_NAME,	"ACBus_Name",		"发电机名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GK_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_GEN_ID,		"Gen_ID",			"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GK_TW,			"GK_TW",			"转速偏差滤波器的时间常数(秒)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_E,			"GK_E",				"转速偏差死区",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_I,			"GK_I",				"转速采用滤波器或死区方式选择",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGK_FilterDead)/sizeof(tagMemDBEnumPair),	g_BpaEnumGK_FilterDead,	},
	{	BPA_SWI_GK_K1,			"GK_K1",			"转速偏差放大倍数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_K2,			"GK_K2",			"主汽压力偏差放大倍数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_I_CONTROL,	"GK_I_Control",		"控制方式选择	",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGK_ControlMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGK_ControlMode,},
	{	BPA_SWI_GK_KP,			"GK_KP",			"PID比例环节倍数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_KD,			"GK_KD",			"PID微分环节倍数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_KI,			"GK_KI",			"PID积分环节倍数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_INTG_MAX,	"GK_INTG_MAX",		"PID积分环节限幅上限",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_INTG_MIN,	"GK_INTG_MIN",		"PID积分环节限幅下限",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_PID_MAX,		"GK_PID_MAX",		"PID输出限幅环节的上限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_PID_MIN,		"GK_PID_MIN",		"PID输出限幅环节的下限",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_W_MAX,		"GK_W_MAX",			"一次调频负荷上限",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_W_MIN,		"GK_W_MIN",			"一次调频负荷下限",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_KEYNAME,		"KeyName",			"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GK_BUSPTR,		"BusPtr",			"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GK_APPENDTAG,	"AppendTag",		"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGM[]=
{
	{	BPA_SWI_GM_CARDKEY,			"CardKey",			"卡类型",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GM_BUS_NAME,		"ACBus_Name",		"发电机名称",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GM_BUS_KV,			"ACBus_kV",			"发电机基准电压(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_GEN_ID,			"Gen_ID",			"发电机识别码",									MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GM_KW,				"GM_KW",			"频率偏差放大倍数",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_TR,				"GM_TR",			"频率测量环节时间常数(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_NEGATIVE_DB1,	"GM_Negative_DB1",	"转速调节死区(负方向,相对于额定频率的标么值)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB1,				"GM_DB1",			"转速调节死区(正方向,相对于额定频率的标么值)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_KP,				"GM_KP",			"PID比例环节放大倍数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_KD,				"GM_KD",			"PID微分环节放大倍数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_KI,				"GM_KI",			"PID积分环节放大倍数",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_TD,				"GM_TD",			"PID微分环节时间常数(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_INTG_MAX,		"GM_INTG_MAX",		"PID积分环节限幅上限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_INTG_MIN,		"GM_INTG_MIN",		"PID积分环节限幅下限",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_PID_MAX,			"GM_PID_MAX",		"PID输出限幅环节的上限",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_PID_MIN,			"GM_PID_MIN",		"PID输出限幅环节的下限",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DELT,			"GM_DELT",			"DELT,转速测量的时迟(秒)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB_MAX,			"GM_DB_MAX",		"一次调频上限",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB_MIN,			"GM_DB_MIN",		"一次调频下限",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DELT2,			"GM_DELT2",			"测量时迟(秒)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_TR2,				"GM_TR2",			"测量环节时间常数(秒)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_EP,				"GM_EP",			"系数",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_NEGATIVE_DB2,	"GM_Negative_DB2",	"负方向死区",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB2,				"GM_DB2",			"正方向死区",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DBMAX2,			"GM_DBMAX2",		"限幅上限",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DBMIN2,			"GM_DBMIN2",		"限幅下限",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_ITYP,			"GM_ITYP",			"模式选择",										MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGM_Mode)/sizeof(tagMemDBEnumPair),		g_BpaEnumGM_Mode,		},
	{	BPA_SWI_GM_ITYP2,			"GM_ITYP2",			"开度模式选择",									MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGM_OpenMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGM_OpenMode,	},
	{	BPA_SWI_GM_KEYNAME,			"KeyName",			"数据库主键",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GM_BUSPTR,			"BusPtr",			"发电机母线索引",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GM_APPENDTAG,		"AppendTag",		"新增记录标记",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGD[]=
{
	{	BPA_SWI_GD_CARDKEY,		"CardKey",			"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GD_BUS_NAME,	"ACBus_Name",		"发电机名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GD_BUS_KV,		"ACBus_kV",			"发电机基准电压(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_GEN_ID,		"Gen_ID",			"发电机识别码",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GD_PMAX,		"GD_Pmax",			"最大输出机械功率",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_PMIN,		"GD_Pmin",			"最小输出机械功率",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_DB,			"GD_DB",			"Δω的死区(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_R,			"GD_R",				"稳态偏差(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KP,			"GD_Kp",			"比例环节增益(pu/pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KI,			"GD_Ki",			"积分环节增益(pu/sec)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KD,			"GD_Kd",			"微分环节增益(pu·sec)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_GOV_MAX,		"GD_GOV_MAX",		"积分环节上限(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_GOV_MIN,		"GD_GOV_Min",		"积分环节下限(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_DEMAND_MAX,	"GD_DEMAND_MAX",	"输出上限(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_DEMAND_MIN,	"GD_DEMAND_MIN",	"输出下限(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KEYNAME,		"KeyName",			"数据库主键",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GD_BUSPTR,		"BusPtr",			"发电机母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GD_APPENDTAG,	"AppendTag",		"新增记录标记",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGZ[]=
{
	{	BPA_SWI_GZ_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GZ_BUS_NAME,	"ACBus_Name",	"发电机名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GZ_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_GEN_ID,		"Gen_ID",		"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GZ_TSM,			"GZ_Tsm",		"伺服系统时间常数(秒)	",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_ROPEN,		"GZ_Ropen",		"汽门最大开启速度(p.u.gate/sec)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_RCLOSE,		"GZ_Rclose",	"汽门最大关闭速度(p.u.gate/sec)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_EHC_MAX,		"GZ_EHC_MAX",	"EHC最大位置限制(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_EHC_MIN,		"GZ_EHC_MIN",	"EHC最小位置限制(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_T_OPEN,		"GZ_T_Open",	"控制阀开启时间常数(sec)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_T_CLOSE,		"GZ_T_Close",	"控制阀关闭时间常数(sec)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_DB_VALUE,	"GZ_DB_Value",	"阀的死区(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_CV_MAX,		"GZ_CV_MAX",	"阀的死区(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_CV_MIN,		"GZ_CV_MIN",	"控制阀下限(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_KPE,			"GZ_Kpe",		"电磁功率反馈增益(pu/pu)	",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_TPE,			"GZ_Tpe",		"电磁功率反馈时间常数(sec)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_MODE,		"GZ_Mode",		"控制模式",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGZ_ControlMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGZ_ControlMode,	},
	{	BPA_SWI_GZ_KEYNAME,		"KeyName",		"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GZ_BUSPTR,		"BusPtr",		"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GZ_APPENDTAG,	"AppendTag",	"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TA[]=
{
	{	BPA_SWI_TA_CARDKEY,		"CardKey",		"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TA_BUS_NAME,	"ACBus_Name",	"发电机名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TA_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TA_GEN_ID,		"Gen_ID",		"发电机识别码",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TA_TCH,			"TA_TCH",		"蒸汽容积时间常数(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TA_K1,			"TA_K1",		"汽轮机K1=1.0;水轮机K1=-2.0(必须)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TA_KEYNAME,		"KeyName",		"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TA_BUSPTR,		"BusPtr",		"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TA_APPENDTAG,	"AppendTag",	"新增记录标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TB[]=
{
	{	BPA_SWI_TB_CARDKEY,		"CardKey",		"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TB_BUS_NAME,	"ACBus_Name",	"发电机名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TB_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_GEN_ID,		"Gen_ID",		"发电机识别码",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TB_TCH,			"TB_TCH",		"蒸汽容积时间常数(秒)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_FHP,			"TB_FHP",		"高压缸功率比例",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_TRH,			"TB_TRH",		"再热器时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_FIP,			"TB_FIP",		"中压缸功率比例",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_TCO,			"TB_TCO",		"交叉管时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_FLP,			"TB_FLP",		"低压缸功率比例或比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_LAMBDA,		"TB_Lambda",	"高压缸功率自然过调系数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_KEYNAME,		"KeyName",		"数据库主键",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TB_BUSPTR,		"BusPtr",		"发电机母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TB_APPENDTAG,	"AppendTag",	"新增记录标记",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_TC[]=
{
	{	BPA_SWI_TC_CARDKEY,		"CardKey",		"卡类型",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TC_BUS_NAME,	"ACBus_Name",	"发电机名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TC_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_GEN_ID,		"Gen_ID",		"发电机识别码",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TC_TCH,			"TC_TCH",		"蒸汽容积时间常数(秒)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FVHP,		"TC_FVHP",		"超高压缸功率比例",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_TRH1,		"TC_TRH1",		"第一再热器时间常数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FHP,			"TC_FHP",		"高压缸功率比例",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_TRH2,		"TC_TRH2",		"第二再热器时间常数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FIP,			"TC_FIP",		"中压缸功率比例或比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_TCO,			"TC_TCO",		"交叉管时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FLP,			"TC_FLP",		"低压缸功率比例或比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_KEYNAME,		"KeyName",		"数据库主键",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TC_BUSPTR,		"BusPtr",		"发电机母线索引",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TC_APPENDTAG,	"AppendTag",	"新增记录标记",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_TD[]=
{
	{	BPA_SWI_TD_CARDKEY,		"CardKey",		"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TD_BUS_NAME,	"ACBus_Name",	"发电机名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TD_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_GEN_ID,		"Gen_ID",		"发电机识别码",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TD_TCH,			"TD_TCH",		"蒸汽容积时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FHP,			"TD_FHP",		"高压缸功率比例",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_TRH,			"TD_TRH",		"再热器时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FIP,			"TD_FIP",		"中压缸功率比例",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_TCO,			"TD_TCO",		"交叉管时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FLP_1,		"TD_FLP_1",		"低压缸功率比例或比例的一半",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FLP_2,		"TD_FLP_2",		"低压缸功率比例或比例的一半",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_KEYNAME,		"KeyName",		"数据库主键",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TD_BUSPTR,		"BusPtr",		"发电机母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TD_APPENDTAG,	"AppendTag",	"新增记录标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TE[]=
{
	{	BPA_SWI_TE_CARDKEY,		"CardKey",		"卡类型",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TE_BUS_NAME,	"ACBus_Name",	"发电机名称",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TE_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_GEN_ID,		"Gen_ID",		"发电机识别码",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TE_TCH,			"TE_TCH",		"蒸汽容积时间常数(秒)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_FHP,			"TE_FHP",		"高压缸功率比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_TRH,			"TE_TRH",		"再热器时间常数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_FIP,			"TE_FIP",		"中压缸功率比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_TCO,			"TE_TCO",		"交叉管时间常数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_FLP,			"TE_FLP",		"低压缸功率比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_KEYNAME,		"KeyName",		"数据库主键",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TE_BUSPTR,		"BusPtr",		"发电机母线索引",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TE_APPENDTAG,	"AppendTag",	"新增记录标记",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_TF[]=
{
	{	BPA_SWI_TF_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TF_BUS_NAME,	"ACBus_Name",	"发电机名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TF_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_GEN_ID,		"Gen_ID",		"发电机识别码",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TF_TCH,			"TF_TCH",		"蒸汽容积时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FVHP,		"TF_FVHP",		"超高压缸功率比例",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_TRH1,		"TF_TRH1",		"第一再热器时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FHP,			"TF_FHP",		"高压缸功率比例",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_TRH2,		"TF_TRH2",		"第二再热器时间常数",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FIP_1,		"TF_FIP_1",		"中压缸功率比例或比例一半",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FIP_2,		"TF_FIP_2",		"中压缸功率比例或比例一半",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_TCO,			"TF_TCO",		"交叉管时间常数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FLP_1,		"TF_FLP_1",		"低压缸功率比例或比例一半",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FLP_2,		"TF_FLP_2",		"低压缸功率比例或比例一半",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_KEYNAME,		"KeyName",		"数据库主键",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TF_BUSPTR,		"BusPtr",		"发电机母线索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TF_APPENDTAG,	"AppendTag",	"新增记录标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TW[]=
{
	{	BPA_SWI_TW_CARDKEY,		"CardKey",		"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TW_BUS_NAME,	"ACBus_Name",	"发电机名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TW_BUS_KV,		"ACBus_kV",		"发电机基准电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_GEN_ID,		"Gen_ID",		"发电机识别码",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TW_K1,			"TW_K1",		"汽轮机K1=1.0;水轮机K1=-2.0(必须)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_HALF,		"TW_Tw_Half",	"水锤效应时间常数(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_K3,			"TW_K3",		"K3=3.0(必须)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_KEYNAME,		"KeyName",		"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TW_BUSPTR,		"BusPtr",		"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TW_APPENDTAG,	"AppendTag",	"新增记录标记",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GX[]=
{
	{	BPA_SWI_GX_CARDKEY,				"CardKey",			"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GX_BUS_NAME,			"ACBus_Name",		"发电机名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GX_BUS_KV,				"ACBus_KV",			"发电机基准电压(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_GEN_ID,				"Gen_ID",			"发电机识别码ID",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GX_TSH,					"GX_TSH",			"过热器容积时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_TD,					"GX_TD",			"汽包蓄热容积时间常数",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_TW,					"GX_TW",			"锅炉燃料释放的时间常数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_K,					"GX_K",				"过热器及主汽管道流量系数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_TDELAY,				"GX_Tdelay",		"延时",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_LIMIT_MAX,			"GX_Limit_MAX",		"输出限幅环节的最大值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_LIMIT_MIN,			"GX_Limit_MIN",		"输出限幅环节最小值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_KEYNAME,				"KeyName",			"数据库主键",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GX_BUSPTR,				"BusPtr",			"发电机母线索引",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_IGV[]=
{
	{	BPA_SWI_IGV_CARDKEY,		"CardKey",		"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_IGV_BUS_NAME,		"ACBus_Name",	"发电机名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_IGV_BUS_KV,			"ACBus_KV",		"发电机基准电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_GEN_ID,			"Gen_ID",		"发电机识别码ID",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_IGV_TSTART,			"IGV_Tstart",	"频率变化的起始时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T1,				"IGV_T1",		"第1个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ1,			"IGV_FREQ1",	"第1个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T2,				"IGV_T2",		"第2个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ2,			"IGV_FREQ2",	"第2个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T3,				"IGV_T3",		"第3个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ3,			"IGV_FREQ3",	"第3个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T4,				"IGV_T4",		"第4个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ4,			"IGV_FREQ4",	"第4个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T5,				"IGV_T5",		"第5个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ5,			"IGV_FREQ5",	"第5个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T6,				"IGV_T6",		"第6个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ6,			"IGV_FREQ6",	"第6个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T7,				"IGV_T7",		"第7个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ7,			"IGV_FREQ7",	"第7个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T8,				"IGV_T8",		"第8个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ8,			"IGV_FREQ8",	"第8个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T9,				"IGV_T9",		"第9个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ9,			"IGV_FREQ9",	"第9个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T10,			"IGV_T10",		"第10个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ10,			"IGV_FREQ10",	"第10个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T11,			"IGV_T11",		"第11个点对应的时刻(周)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ11,			"IGV_FREQ11",	"第11个点对应的频率变化量(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_KEYNAME,		"KeyName",		"数据库主键",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_IGV_BUSPTR,			"BusPtr",		"发电机母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_FGV[]=
{
	{	BPA_SWI_FGV_CARDKEY,		"CardKey",			"卡类型",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FGV_BUS_NAME,		"ACBus_Name",		"发电机名称",															MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FGV_BUS_KV,			"ACBus_KV",			"发电机基准电压(kV)",													MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_GEN_ID,			"Gen_ID",			"发电机识别码ID",														MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_FGV_AMP1,			"FGV_AMP1",			"第一个波动的幅值,百分数或有名值",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_FREQ1,			"FGV_FREQ1",		"第一个波动的频率(弧度/秒)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_ANGL01,			"FGV_ANGL01",		"第一个波动的初始相位(弧度)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TBEGIN1,		"FGV_TBEGIN1",		"第一个波动的起始时间(周)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TEND1,			"FGV_TEND1",		"第一个波动的结束时间(周)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_AMP2,			"FGV_AMP2",			"第二个波动的幅值,百分数或有名值",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_FREQ2,			"FGV_FREQ2",		"第二个波动的频率(弧度/秒)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_ANGL02,			"FGV_ANGL02",		"第二个波动的初始相位(弧度)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TBEGIN2,		"FGV_TBEGIN2",		"第二个波动的起始时间(周)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TEND2,			"FGV_TEND2",		"第二个波动的结束时间(周)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_CMW,			"FGV_CMW",			"空格表示前两个波动的幅值都是发电机机械功率初值的百分数;W,为有名值",	MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_FGV_KEYNAME,		"KeyName",			"数据库主键",															MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FGV_BUSPTR,			"BusPtr",			"发电机母线索引",														MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LO[]=
{
	{	BPA_SWI_LO_CARDKEY,			"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LO_BUSI,			"LO_BusI",			"母线名称1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LO_KVI,				"LO_kVI",			"基准电压1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_BUSJ,			"LO_BusJ",			"母线名称2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LO_KVJ,				"LO_kVJ",			"基准电压2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_LOOP,			"LO_Loop",			"并联线路的回路标志",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LO_R0,				"LO_R0",			"线路零序电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_X0,				"LO_X0",			"线路零序电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_GA0,				"LO_Ga0",			"线路BUSA侧零序对地电导(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_BA0,				"LO_Ba0",			"线路BUSA侧零序对地电纳(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_GB0,				"LO_Gb0",			"线路BUSB侧零序对地电导(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_BB0,				"LO_Bb0",			"线路BUSB侧零序对地电纳(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_KEYNAME,			"KeyName",			"线路名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_XO[]=
{
	{	BPA_SWI_XO_CARDKEY,			"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_XO_BUSI,			"XO_BusI",			"母线名称1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_XO_KVI,				"XO_kVI",			"基准电压1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_BUSJ,			"XO_BusJ",			"母线名称2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_XO_KVJ,				"XO_kVJ",			"基准电压2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_LOOP,			"XO_Loop",			"并联线路的回路标志",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_XO_SID,				"XO_SID",			"变压器零序电抗的接入方式",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_XO_R0,				"XO_R0",			"变压器零序电阻(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_X0,				"XO_X0",			"变压器零序电抗(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_KEYNAME,			"KeyName",			"变压器名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LOHG[]=
{
	{	BPA_SWI_LOHG_CARDKEY,		"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LOHG_BUSI,			"LO+_BusI",			"母线名称1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LOHG_KVI,			"LO+_kVI",			"基准电压1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_BUSJ,			"LO+_BusJ",			"母线名称2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LOHG_KVJ,			"LO+_kVJ",			"基准电压2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_LOOP,			"LO+_Loop",			"并联线路的回路标志",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LOHG_X0I,			"LO+_X0I",			"线路前侧高抗对应的等值零序电抗(pu)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_X0J,			"LO+_X0J",			"线路后侧高抗对应的等值零序电抗(pu)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_KEYNAME,		"KeyName",			"线路高抗名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_XR[]=
{
	{	BPA_SWI_XR_CARDKEY,		"CardKey",				"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_XR_NAME,		"ACBus_Name",			"母线名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_XR_KV,			"ACBus_kV",				"基准电压(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XR_R0,			"XR_R0",				"对地支路零序电阻(PU)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XR_X0,			"XR_X0",				"对地支路零序电抗(PU)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_D[]=
{
	{	BPA_SWI_D_CARDKEY,			"CardKey",			"卡类型",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_D_BUS_NAME,			"DCBus_Name",		"直流母线名称",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_D_BUS_KV,			"DCBus_KV",			"直流母线基准电压(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_Tc,				"Tc",				"电流测量环节时间常数（秒）",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_Tv,				"Tv",				"电压测量环节时间常数（秒）",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_T1,				"T1",				"电流调节器时间常数1（秒）",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_T2,				"T2",				"电流调节器时间常数2（秒）",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_T3,				"T3",				"电流调节器时间常数3（秒）",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_Ka,				"Ka",				"电流调节器增益",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_MOD,				"MOD",				"控制方式,P＝定功率控制,I＝定电流控制",		MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_D_IMAX,				"IMAX",				"阀的过电流能力(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_IMARGIN,			"IMARGIN",			"电流余裕值(pu),逆变侧必须在0.05-0.3之间",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_ALPHASTOP,		"ALPHASTOP",		"作逆变器使用时的最小点燃角（度）",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_TD,				"TD",				"换相电压时间常数（秒）,缺省0.01秒",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_VLIM,				"VLIM",				"电流限制起始处的额定端电压(pu),缺省0.25pu",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_DISA,				"DISA",				"非空则消去该直流控制系统",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_D_MSU,				"MSU",				"余裕开关单元关键码",							MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_D_KEYNAME,			"KeyName",			"数据库主键",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_D_BUSPTR,			"BusPtr",			"直流母线索引",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_V[]=
{
	{	BPA_SWI_V_CARDKEY,			"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_V_BUS_NAME,			"ACBus_Name",		"母线名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_V_BUS_KV,			"ACBus_KV",			"母线基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_ID,				"ID",				"并联支路识别码",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_V_TS1,				"TS1",				"滤波器时间常数(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_VEMAX,			"VEMAX",			"最大电压偏差(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS2,				"TS2",				"第一级超前时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS3,				"TS3",				"第一级滞后时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_A,				"A",				"超前识别码(不能为0)",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_V_B,				"B",				"滞后识别码(不能为0)",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_V_TS4,				"TS4",				"第二级超前时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS5,				"TS5",				"第二级滞后时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_KSVS,				"KSVS",				"连续控制增益",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_KSD,				"KSD",				"间断控制增益",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BMAX,				"BMAX",				"最大导纳(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BPMAX,			"BPMAX",			"连续控制的最大导纳(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BPMIN,			"BPMIN",			"连续控制的最小导纳(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BMIN,				"BMIN",				"最小导纳(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS6,				"TS6",				"可控硅(Thyristor)触发时延(秒)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_DV,				"DV",				"电压偏差",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_CON_NAME,			"CON_NAME",			"被控母线名",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_V_CON_KV,			"CON_KV",			"被控母线基准电压",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_KEYNAME,			"KeyName",			"数据库主键",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_V_BUSPTR,			"BusPtr",			"母线索引",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_VG[]=
{
	{	BPA_SWI_VG_CARDKEY,			"CardKey",			"卡类型",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_VG_BUS_NAME,		"ACBus_Name",		"母线名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_VG_BUS_KV,			"ACBus_KV",			"母线基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_MVABASE,			"MvaBase",			"额定容量",								MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T1,				"T1",				"滤波器和测量回路的时间常数(秒)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T2,				"T2",				"第一级超前时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T3,				"T3",				"第一级滞后时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T4,				"T4",				"第二级超前时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T5,				"T5",				"第二级滞后时间常数(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_TP,				"TP",				"比例环节时间常数(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_TS,				"TS",				"STATCOM响应延迟(秒)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KP,				"KP",				"比例环节放大倍数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KI,				"KI",				"积分环节的放大倍数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KD,				"KD",				"STATCOM的V-I特性曲线的斜率",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_XT,				"XT",				"STATCOM与系统之间的等值电抗(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_VMAX,			"VMAX",				"电压限幅环节的上限(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_VMIN,			"VMIN",				"电压限幅环节的下限(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_ICMAX,			"ICMAX",			"最大容性电流(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_ILMAX,			"ILMAX",			"最大感性电流(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_VSTANDBY,		"VSTANDBY",			"与系统相连的节点电压低于此值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_CON_NAME,		"CON_NAME",			"被控母线名",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_VG_CON_KV,			"CON_KV",			"被控母线基准电压",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KEYNAME,			"KeyName",			"数据库主键",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_VG_BUSPTR,			"BusPtr",			"母线索引",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LAB[]=
{
	{	BPA_SWI_LAB_CARDKEY,	"CardKey",		"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LAB_BUS_NAME,	"ACBus_Name",	"母线名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LAB_BUS_KV,		"ACBus_kV",		"基准电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_ZONE,		"LAB_Zone",		"ZONE,分区名",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_SWI_LAB_AREA,		"LAB_Area",		"区域名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_LAB_P1,			"LAB_P1",		"恒定阻抗有功负荷百分数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q1,			"LAB_Q1",		"恒定阻抗无功负荷百分数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P2,			"LAB_P2",		"恒定电流有功负荷百分数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q2,			"LAB_Q2",		"恒定电流无功负荷百分数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P3,			"LAB_P3",		"恒定功率有功负荷百分数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q3,			"LAB_Q3",		"恒定功率无功负荷百分数",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P4,			"LAB_P4",		"与频率有关的有功负荷百分数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q4,			"LAB_Q4",		"与频率有关的无功负荷百分数",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_LDP,		"LAB_LDP",		"频率变化1％引起的有功变化",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_LDQ,		"LAB_LDQ",		"频率变化1％引起的无功变化",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P5,			"LAB_P5",		"电压指数相关的有功负荷比例",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q5,			"LAB_Q5",		"电压指数相关的无功负荷比例",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_NP,			"LAB_NP",		"有功电压指数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_NQ,			"LAB_NQ",		"无功电压指数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_MI[]=
{
	{	BPA_SWI_MI_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_MI_BUS_NAME,	"ACBus_Name",	"母线名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_MI_BUS_KV,		"ACBus_kV",		"基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_BUS_ID,		"Bus_ID",		"BusID识别码ID",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_MI_EMWS,		"MI_Emws",		"马达的动能(兆瓦秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_P,			"MI_P",			"马达功率占母线有功负荷的比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_MVA,			"MI_MVA",		"马达的基准功率值(MVA)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_RS,			"MI_RS",		"定子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_XS,			"MI_XS",		"定子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_XM,			"MI_XM",		"激磁电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_RR,			"MI_RR",		"转子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_XR,			"MI_XR",		"转子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_VI,			"MI_VI",		"马达低压释放的电压值",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_TI,			"MI_TI",		"马达低压释放时延(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_A,			"MI_A",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_B,			"MI_B",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_IM,			"MI_IM",		"马达滑差达到1时的处理方式",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
	{	BPA_SWI_MI_BUSPTR,		"BusPtr",		"母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_ML[]=
{
	{	BPA_SWI_ML_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_ML_BUS_NAME,	"ACBus_Name",	"母线名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_ML_BUS_KV,		"ACBus_kV",		"基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_BUS_ID,		"Bus_ID",		"BusID识别码ID",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_ML_TJ,			"ML_TJ",		"马达的惯性时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_PPER,		"ML_Pper",		"马达功率占母线有功负荷的比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_KL,			"ML_KL",		"马达的负载率或初始滑差",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_PMIN,		"ML_Pmin",		"马达的功率因数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_RS,			"ML_RS",		"定子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_XS,			"ML_XS",		"定子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_XM,			"ML_XM",		"激磁电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_RR,			"ML_RR",		"转子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_XR,			"ML_XR",		"转子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_VI,			"ML_VI",		"马达低压释放的电压值",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_TI,			"ML_TI",		"马达低压释放时延(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_A,			"ML_A",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_B,			"ML_B",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_S0,			"ML_S0",		"负载率或初始滑差",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(unsigned	char),	0,	NULL,	},//sizeof(g_BpaEnumMotor_KlS0)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_KlS0,	},
	{	BPA_SWI_ML_IM,			"ML_IM",		"马达滑差达到1时的处理方式",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
	{	BPA_SWI_ML_BUSPTR,		"BusPtr",		"母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_MJ[]=
{
	{	BPA_SWI_MJ_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_MJ_ZONE_NAME,	"Zone_Name",	"分区名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_MJ_TJ,			"MJ_TJ",		"马达的惯性时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_PPER,		"MJ_Pper",		"马达功率占母线有功负荷的比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_KL,			"MJ_KL",		"马达的负载率或初始滑差",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_PMIN,		"MJ_Pmin",		"马达的功率因数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_RS,			"MJ_RS",		"定子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_XS,			"MJ_XS",		"定子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_XM,			"MJ_XM",		"激磁电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_RR,			"MJ_RR",		"转子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_XR,			"MJ_XR",		"转子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_VI,			"MJ_VI",		"马达低压释放的电压值",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_TI,			"MJ_TI",		"马达低压释放时延(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_A,			"MJ_A",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_B,			"MJ_B",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_S0,			"MJ_S0",		"负载率或初始滑差",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},//sizeof(g_BpaEnumMotor_KlS0)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_KlS0,	},
	{	BPA_SWI_MJ_IM,			"MJ_IM",		"马达滑差达到1时的处理方式",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaSwi_MK[]=
{
	{	BPA_SWI_MK_CARDKEY,		"CardKey",		"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_MK_AREA_NAME,	"Area_Name",	"区域名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_MK_TJ,			"MK_TJ",		"马达的惯性时间常数(秒)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_PPER,		"MK_Pper",		"马达功率占母线有功负荷的比例",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_KL,			"MK_KL",		"马达的负载率或初始滑差",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_PMIN,		"MK_Pmin",		"马达的功率因数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_RS,			"MK_RS",		"定子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_XS,			"MK_XS",		"定子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_XM,			"MK_XM",		"激磁电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_RR,			"MK_RR",		"转子电阻(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_XR,			"MK_XR",		"转子电抗(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_VI,			"MK_VI",		"马达低压释放的电压值",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_TI,			"MK_TI",		"马达低压释放时延(秒)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_A,			"MK_A",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_B,			"MK_B",			"转矩方程常数",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_S0,			"MK_S0",		"负载率或初始滑差",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},//sizeof(g_BpaEnumMotor_KlS0)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_KlS0,	},
	{	BPA_SWI_MK_IM,			"MK_IM",		"马达滑差达到1时的处理方式",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaSwi_LE[]=
{
	{	BPA_SWI_LE_CARDKEY,		"CardKey",		"卡类型",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LE_NAME,		"Name",			"母线、分区、区域名",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LE_LINE_ID,		"Line_ID",		"支路顺序号",									MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LE_RD,			"LE_RD",		"配电网支路电阻",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_XD,			"LE_XD",		"配电网支路电抗",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_PPER,		"LE_Pper",		"本支路有功功率占该母线总负荷有功功率的比例",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_QPER,		"LE_Qper",		"本支路无功功率占该母线总负荷无功功率的比例",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_PG,			"LE_PG",		"与本支路相连的所有发电机的有功总出力",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_QG,			"LE_QG",		"与本支路相连的所有发电机的无功总出力",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_PFAC,		"LE_PFAC",		"配电网支路静态负荷的功率因数",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LM[]=
{
	{	BPA_SWI_LM_CARDKEY,		"CardKey",		"卡类型",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LM_BUS1_I,		"LM_Bus1_I",	"BusName1_A",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV1_I,		"LM_kV1_I",		"BusBase1_A(kV)	",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_BUS1_J,		"LM_Bus1_J",	"BusName1_B	",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV1_J,		"LM_kV1_J",		"BusBase1_B(kV)	",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_PAR_1,		"LM_PAR_1",		"平行码",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LM_BUS2_I,		"LM_Bus2_I",	"BusName2_I",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV2_I,		"LM_kV2_I",		"BusBase2_I(kV)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_BUS2_J,		"LM_Bus2_J",	"BusName2_J",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV2_J,		"LM_kV2_J",		"BusBase2_J(kV)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_PAR_2,		"LM_PAR_2",		"平行码",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LM_RM,			"LM_Rm",		"互感电阻",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_XM,			"LM_Xm",		"互感电抗",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_KEYNAME,		"KeyName",		"线路高抗零序阻抗名称",			MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_SWI_LM_BUSPTR,		"BusPtr",		"线路高抗零序阻抗I母线索引",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_LM_ZRBUS,		"zRBus",		"线路高抗零序阻抗Z母线索引",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_UF[]=
{
	{	BPA_SWI_UF_CARDKEY,				"CardKey",				"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_UF_BUS_NAME,			"ACBus_Name",			"母线名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_UF_BUS_KV,				"ACBus_KV",				"基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ01,				"UF_Freq01",			"第01级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ02,				"UF_Freq02",			"第02级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ03,				"UF_Freq03",			"第03级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ04,				"UF_Freq04",			"第04级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ05,				"UF_Freq05",			"第05级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ06,				"UF_Freq06",			"第06级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ07,				"UF_Freq07",			"第07级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ08,				"UF_Freq08",			"第08级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ09,				"UF_Freq09",			"第09级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ10,				"UF_Freq10",			"第10级减负荷时的频率(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY01,				"UF_Delay01",			"第01级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY02,				"UF_Delay02",			"第02级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY03,				"UF_Delay03",			"第03级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY04,				"UF_Delay04",			"第04级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY05,				"UF_Delay05",			"第05级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY06,				"UF_Delay06",			"第06级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY07,				"UF_Delay07",			"第07级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY08,				"UF_Delay08",			"第08级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY09,				"UF_Delay09",			"第09级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY10,				"UF_Delay10",			"第10级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED01,				"UF_Shed01",			"第01级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED02,				"UF_Shed02",			"第02级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED03,				"UF_Shed03",			"第03级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED04,				"UF_Shed04",			"第04级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED05,				"UF_Shed05",			"第05级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED06,				"UF_Shed06",			"第06级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED07,				"UF_Shed07",			"第07级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED08,				"UF_Shed08",			"第08级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED09,				"UF_Shed09",			"第09级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED10,				"UF_Shed10",			"第10级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_W,					"UF_W",					"特别码W,表示以MW为单位减去负荷",	MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_UV[]=
{
	{	BPA_SWI_UV_CARDKEY,				"CardKey",			"卡类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_UV_BUS_NAME,			"ACBus_Name",		"母线名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_UV_BUS_KV,				"ACBus_KV",			"基准电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT01,				"UV_Volt01",		"第01级减负荷时的电压(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT02,				"UV_Volt02",		"第02级减负荷时的电压(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT03,				"UV_Volt03",		"第03级减负荷时的电压(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT04,				"UV_Volt04",		"第04级减负荷时的电压(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT05,				"UV_Volt05",		"第05级减负荷时的电压(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT06,				"UV_Volt06",		"第06级减负荷时的电压(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT07,				"UV_Volt07",		"第07级减负荷时的电压(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT08,				"UV_Volt08",		"第08级减负荷时的电压(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT09,				"UV_Volt09",		"第09级减负荷时的电压(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT10,				"UV_Volt10",		"第10级减负荷时的电压(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY01,				"UV_Delay01",		"第01级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY02,				"UV_Delay02",		"第02级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY03,				"UV_Delay03",		"第03级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY04,				"UV_Delay04",		"第04级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY05,				"UV_Delay05",		"第05级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY06,				"UV_Delay06",		"第06级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY07,				"UV_Delay07",		"第07级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY08,				"UV_Delay08",		"第08级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY09,				"UV_Delay09",		"第09级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY10,				"UV_Delay10",		"第10级减负荷前的时延(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED01,				"UV_Shed01",		"第01级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED02,				"UV_Shed02",		"第02级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED03,				"UV_Shed03",		"第03级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED04,				"UV_Shed04",		"第04级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED05,				"UV_Shed05",		"第05级初始负荷被减去的值",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED06,				"UV_Shed06",		"第06级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED07,				"UV_Shed07",		"第07级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED08,				"UV_Shed08",		"第08级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED09,				"UV_Shed09",		"第09级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED10,				"UV_Shed10",		"第10级被减去的负荷值(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_W,					"UV_W",				"特别码W,表示以MW为单位减去负荷",	MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_RE[]=
{
	{	BPA_SWI_RE_CARDKEY,			"CardKey",			"卡类型",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_RE_BUS_NAME,		"ACBus_Name",		"母线名称",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RE_BUS_KV,			"ACBus_KV",			"基准电压(kV)	",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_GEN_ID,			"Gen_ID",			"发电机识别码",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RE_VOL1,			"RE_VOL1",			"电压设定值1(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL2,			"RE_VOL2",			"电压设定值2(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL3,			"RE_VOL3",			"电压设定值3(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL4,			"RE_VOL4",			"电压设定值4(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL5,			"RE_VOL5",			"电压设定值5(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL6,			"RE_VOL6",			"电压设定值6(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL7,			"RE_VOL7",			"电压设定值7(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL8,			"RE_VOL8",			"电压设定值8(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL9,			"RE_VOL9",			"电压设定值9(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL10,			"RE_VOL10",			"电压设定值10(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME1,			"RE_TIME1",			"时迟1(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME2,			"RE_TIME2",			"时迟2(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME3,			"RE_TIME3",			"时迟3(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME4,			"RE_TIME4",			"时迟4(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME5,			"RE_TIME5",			"时迟5(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME6,			"RE_TIME6",			"时迟6(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME7,			"RE_TIME7",			"时迟7(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME8,			"RE_TIME8",			"时迟8(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME9,			"RE_TIME9",			"时迟9(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME10,			"RE_TIME10",		"时迟10(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TBRK,			"RE_TBRK",			"继电器动作时间(周)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_NAME_CON,		"RE_NAME_CON",		"控制母线名称",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RE_KV_CON,			"RE_KV_CON",		"控制母线基准电压",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_BUSPTR,			"BusPtr",			"发电机母线索引",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_RW[]=
{
	{	BPA_SWI_RW_CARDKEY,			"CardKey",			"卡类型",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_RW_BUS_NAME,		"ACBus_Name",		"母线名称",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RW_BUS_KV,			"ACBus_KV",			"基准电压(kV)	",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_GEN_ID,			"Gen_ID",			"发电机识别码",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RW_WMAX,			"RW_Wmax",			"发电机立即跳闸的最大转速(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WMIN,			"RW_Wmin",			"发电机立即跳闸的最小转速(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET1,			"RW_Wset1",			"发电机转速设定值1(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET2,			"RW_Wset2",			"发电机转速设定值2(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET3,			"RW_Wset3",			"发电机转速设定值3(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET4,			"RW_Wset4",			"发电机转速设定值4(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET5,			"RW_Wset5",			"发电机转速设定值5(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET6,			"RW_Wset6",			"发电机转速设定值6(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET7,			"RW_Wset7",			"发电机转速设定值7(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET8,			"RW_Wset8",			"发电机转速设定值8(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET9,			"RW_Wset9",			"发电机转速设定值9(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET10,			"RW_Wset10",		"发电机转速设定值10(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY1,			"RW_Delay1",		"发电机转速设定值1对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY2,			"RW_Delay2",		"发电机转速设定值2对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY3,			"RW_Delay3",		"发电机转速设定值3对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY4,			"RW_Delay4",		"发电机转速设定值4对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY5,			"RW_Delay5",		"发电机转速设定值5对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY6,			"RW_Delay6",		"发电机转速设定值6对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY7,			"RW_Delay7",		"发电机转速设定值7对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY8,			"RW_Delay8",		"发电机转速设定值8对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY9,			"RW_Delay9",		"发电机转速设定值9对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY10,			"RW_Delay10",		"发电机转速设定值10对应的时迟(周)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_TBRK,			"RW_Tbrk",			"继电器动作时间(周)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_BUSPTR,			"BusPtr",			"发电机母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_RA[]=
{
	{	BPA_SWI_RA_CARDKEY,			"CardKey",			"卡类型",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_RA_BUSI,			"RA_BusI",			"母线名称1",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_KVI,				"RA_kVI",			"基准电压1(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_BUSJ,			"RA_BusJ",			"母线名称2",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_KVJ,				"RA_kVJ",			"基准电压2(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_LOOP,			"RA_Loop",			"并联线路的回路标志",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RA_CBUS1,			"RA_CBus1",			"控制母线名称1",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_CKV1,			"RA_CkV1",			"控制母线基准电压1(kV)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CV1,				"RA_V1",			"母线1低电压限制值(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CT1,				"RA_T1",			"母线1低电压时间延迟(周)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CBUS2,			"RA_CBus2",			"控制母线名称2",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_CKV2,			"RA_CkV2",			"控制母线基准电压2(kV)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CV2,				"RA_V2",			"母线2低电压限制值(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CT2,				"RA_T2",			"母线2低电压时间延迟(周)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_RU[]=
{
	{	BPA_SWI_RU_CARDKEY,			"CardKey",			"卡类型",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_RU_BUSI,			"RU_BusI",			"母线名称1",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RU_KVI,				"RU_kVI",			"基准电压1(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_BUSJ,			"RU_BusJ",			"母线名称2",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RU_KVJ,				"RU_kVJ",			"基准电压2(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_LOOP,			"RU_Loop",			"并联线路的回路标志",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RU_FTRIP,			"RU_FTrip",			"母线频率的门槛值(Hz)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_TRELAY,			"RU_TRelay",		"继电器动作所需时延(周)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_TTRIP,			"RU_TTrip",			"通讯和开关动作时间(周)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_TDELAY,			"RU_TDelay",		"传送操作时延(周)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

#if	!defined(__GNUG__)	&&	!defined(__GNUC__)
#	pragma	pack()
#	if	(defined(_AIX)	||	defined(AIX))
#		pragma	align(fPower)
#	else
#		if	(!defined(sun)	&&	!defined(__sun)	&&	!defined(__sun__))
#			pragma	pack(pop)
#		endif
#	endif
#endif
