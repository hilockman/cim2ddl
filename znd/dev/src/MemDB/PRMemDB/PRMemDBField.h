#pragma once

#include "PRMemDBDefine.h"

#if defined(__GNUG__) || defined(__GNUC__)	// GCC编译器预定义的宏
#	ifndef DISALIGN
#		define DISALIGN __attribute__((packed))
#	endif
#else
#	define DISALIGN
#	if (defined(_AIX) || defined(AIX))
#		pragma align(packed)
#	else
#		if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#			pragma pack(push)
#		endif
#	endif
#	pragma pack(1)
#endif

static	tagMemDBEnumPair	g_PREnumNoYes[]=
{
	{	0,		"否",	},
	{	1,		"是",	},
};

static	tagMemDBEnumPair	g_PREnumSide[]=
{
	{	PREnum_DeviceSide_I,					"I侧",			},
	{	PREnum_DeviceSide_J,					"J侧",			},
};

static	tagMemDBEnumPair	g_PRSystemNetworkTypeEnum[]=
{
	{	PRSystem_NetworkType_1,					"区域性电网",		},
	{	PRSystem_NetworkType_2,					"省、自治区电网",	},
	{	PRSystem_NetworkType_3,					"直辖市电网",		},
	{	PRSystem_NetworkType_4,					"省会城市电网",		},
	{	PRSystem_NetworkType_5,					"一般城市电网",		},
	{	PRSystem_NetworkType_6,					"县级市电网",		},
};

static	tagMemDBEnumPair	g_PRSystemSampleObjectEnum[]=
{
	{	PRSystem_SampleObject_All,				"全部",			},
	{	PRSystem_SampleObject_Bran,				"支路",			},
	{	PRSystem_SampleObject_Gen,				"发电机",		},
};

static	tagMemDBEnumPair	g_PRDeviceRParamTypeEnum[]=
{
	{	PRDevice_RParamType_Common,				"公共参数",		},
	{	PRDevice_RParamType_Device,				"设备参数",		},
};

static	tagMemDBEnumPair	g_PRCommonFaultTypeEnum[]=
{
	{	PRCommonFault_CommonFaultType_Status,		"状态共因",		},
	{	PRCommonFault_CommonFaultType_PValue,		"功率共因",		},
};

static	tagMemDBEnumPair	g_PRCommonDeviceTypeEnum[]=
{
	{	PRCommonFault_DeviceCommonType_Result,		"共因原因设备",		},
	{	PRCommonFault_DeviceCommonType_Resion,		"共因结果设备",		},
};

static	tagMemDBEnumPair	g_PRFModeFaultTypeEnum[]=
{
	{	PRTrip_FaultType_Unknown,				"未知",			},
	{	PRTrip_FaultType_MIsland,				"解列",			},
	{	PRTrip_FaultType_OverLmt,				"越限",			},
	{	PRTrip_FaultType_MiAndOl,				"解列&越限",	},
};

static	tagMemDBEnumPair	g_PRFStateAdResultEnum[]=
{
	{	PRFState_AdResult_Unknown,				"未知",			},
	{	PRFState_AdResult_Normal,				"复限",			},
	{	PRFState_AdResult_OverLmt,				"越限",			},
	{	PRFState_AdResult_Unadjustable,			"不可调节",		},
};

static	tagMemDBEnumPair	g_PRFSecurityResultEnum[]=
{
	{	PRFSecurity_Result_Unknown,				"未知",			},
	{	PRFSecurity_Result_Secure,				"安全",			},
	{	PRFSecurity_Result_InSecure,			"不安全"	,	},
};

static	tagMemDBEnumPair	g_PRFStateSampleMethodEnum[]=
{
	{	PRFState_SamplingMethod_Unknown,		"未知",			},
	{	PRFState_SamplingMethod_MonteCarlo,		"蒙特卡洛",		},
	{	PRFState_SamplingMethod_StateSample,	"状态抽样",		},
	{	PRFState_SamplingMethod_Analytical,		"解析法",		},
	{	PRFState_SamplingMethod_FastSort,		"快速排序",		},
	{	PRFState_SamplingMethod_Manual,			"独立事件",		},
};

static	tagMemDBEnumPair	g_PRFStateStateTypeEnum[]=
{
	{	PRFState_StateType_Fault,				"故障",			},
	{	PRFState_StateType_MState,				"多状态",		},
	{	PRFState_StateType_All,					"故障+多状态",	},
};

static	tagMemDBEnumPair	g_PRFStateFaultGradeEnum[]=
{
	{	PRFState_FaultGrade_0,					"非事故",		},
	{	PRFState_FaultGrade_1,					"一般事故",		},
	{	PRFState_FaultGrade_2,					"较大事故",		},
	{	PRFState_FaultGrade_3,					"重大事故",		},
	{	PRFState_FaultGrade_4,					"特别重大事故",	},
};

static	tagMemDBEnumPair	g_PRFStateFaultTypeEnum[]=
{
	{	PRFState_FaultType_Unknown,				"未知",			},
	{	PRFState_FaultType_Trip,				"停运",			},
	{	PRFState_FaultType_OnePhaseGround,		"单永故障",		},
	{	PRFState_FaultType_TwoPhase,			"相间短路",		},
	{	PRFState_FaultType_ThreePhase,			"三相短路",		},
	{	PRFState_FaultType_TwoPhaseGround,		"两相接地",		},
	{	PRFState_FaultType_CommonFault,			"共因故障",		},
};

static	tagMemDBEnumPair	g_PRBalanceAdAdTypeEnum[]=
{
	{	PRBalanceAd_AdType_Gen,					"升发电出力",	},
	{	PRBalanceAd_AdType_Load,				"切负荷功率",	},
};

static	tagMemDBEnumPair	g_PRConverterTypeEnum[]=
{
	{	PRConverter_Type_Rectifier,				"整流",			},
	{	PRConverter_Type_Inverter,				"逆变",			},
};

static	tagMemDBEnumPair	g_PRConverterFEffectEnum[]=
{
	{	PRConverter_FEffect_Broken,				"开断",			},
	{	PRConverter_FEffect_Connect,			"导通",			},
};

static tagMemDBField	g_PRSystemFieldArray[]=
{
	{	PR_SYSTEM_MVABASE,				"MvaBase",				"功率基准",						MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_GENP,					"GenP",					"系统总发电(MW)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOADP,				"LoadP",				"系统总负荷(MW)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_DCP,					"DCP",					"系统直流容量(MW)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_AVAILGENP,			"AvailGenP",			"系统总装机(MW)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MAXLOADP,				"MaxLoadP",				"系统最大负荷(MW)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},

	{	PR_SYSTEM_SAMPLEMETHOD,			"SampleMethod",			"抽样方法",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateSampleMethodEnum)/sizeof(tagMemDBEnumPair),	g_PRFStateSampleMethodEnum,	},
	{	PR_SYSTEM_SAMPLEOBJECT,			"SampleObject",			"抽样对象",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRSystemSampleObjectEnum)/sizeof(tagMemDBEnumPair),	g_PRSystemSampleObjectEnum,	},
	{	PR_SYSTEM_MAXBFLT,				"MaxBranFlt",			"最大支路故障重数",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_SYSTEM_MAXGFLT,				"MaxGenFlt",			"最大发电机故障重数",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PR_SYSTEM_MCSSIMTIME,			"MCSSimulateTime",		"蒙特卡罗法模拟时间(小时)",		MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MCSMINPROB,			"MCSMinProb",			"蒙特卡罗法最小概率值",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FSTCUMULATEPROB,		"FSTCumulateProb",		"快速排序法截止累计概率值",		MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FSTMAXSTATE,			"FSTMaxState",			"快速排序法截止状态数",			MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_SYSTEM_FSTMINPROB,			"FSTMinProb",			"快速排序法最小概率值",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_STSMAXSTATE,			"STSMaxState",			"状态抽样法截止状态数",			MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_SYSTEM_ANAMINPROB,			"ANAMinProb",			"解析法最小概率值",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},

	{	PR_SYSTEM_BPADATFILE,			"BpaDatFile",			"Bpa潮流文件",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_SYSTEM_BPASWIFILE,			"BpaSwiFile",			"Bpa稳定文件",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_SYSTEM_SECURITYEXECDIR,		"SecurityExecDir",		"安全评估运行目录",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_SYSTEM_SECURITYDESTDIR,		"SecurityDestDir",		"安全评估结果目录",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},

	{	PR_SYSTEM_SECURITYMAXANGLE,		"SecurityMaxAngle",		"安全评估最大功角差",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXVOLT,		"SecurityMaxVolt",		"安全评估最高电压",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXVDUR,		"SecurityMaxVDur",		"安全评估最高电压持续时间",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINVOLT,		"SecurityMinVolt",		"安全评估最低电压",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINVDUR,		"SecurityMinVDur",		"安全评估最低电压持续时间",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXFREQ,		"SecurityMaxFreq",		"安全评估最高频率",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXFDUR,		"SecurityMaxFDur",		"安全评估最高频率持续时间",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINFREQ,		"SecurityMinFreq",		"安全评估最低频率",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINFDUR,		"SecurityMinFDur",		"安全评估最低频率持续时间",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_COPSTEP,				"CopStep",				"停运概率表容量步长",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},

	{	PR_SYSTEM_MAXFLTDEV,			"MaxFltDev",			"最大故障设备重数",				MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_SYSTEM_CUTLOADSTATENUM,		"CutLoadStateNum",		"切负荷状态数",					MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_SYSTEM_PLC,					"PLC",					"切负荷概率",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_EFLC,					"EFLC",					"切负荷频率(次/年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_EDLC,					"EDLC",					"切负荷持续时间(小时/年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_ADLC,					"ADLC",					"每次切负荷持续时间(小时/次)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_ELC,					"ELC",					"负荷切除期望值(MW/年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_EENS,					"EENS",					"电量不足期望值(MWh/年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_BPII,					"BPII",					"系统停电指标(MW/MW.yr)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_BPECI,				"BPECI",				"系统削减电量指标(MWh/MW.年)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SI,					"SI",					"严重程度指标(系统分/年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOLP,					"LOLP",					"电力不足时间概率(天/年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOLF,					"LOLF",					"电力不足频率概率(次/年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOLE,					"LOLE",					"电力不足期望值(小时/年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_PLOS,					"PLOS",					"失稳概率",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLOS,					"FLOS",					"失稳频率(次/年)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MTTIS,				"MTTIS",				"平均稳定运行时间(小时)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MIEENS,				"MIslandEENS",			"孤岛电量不足期望值(MWh/年)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_AGCEENS,				"LossGenEENS",			"失电电量不足期望值(MWh/年)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_ELEENS,				"ERlimitEENS",			"消限电量不足期望值(MWh/年)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_NETWORKTYPE,			"NetworkType",			"网络类型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRSystemNetworkTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRSystemNetworkTypeEnum,	},
	{	PR_SYSTEM_FLTGRADE0PROB,		"FltGrade0Prob",		"非事故状态概率",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE1PROB,		"FltGrade1Prob",		"一般事故概率",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE2PROB,		"FltGrade2Prob",		"较大事故概率",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE3PROB,		"FltGrade3Prob",		"重大事故概率",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE4PROB,		"FltGrade4Prob",		"特别重大事故概率",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOADCURVEPACE,		"LoadCurvePace",		"负荷曲线时间间隔",				MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_SYSTEM_MAXMSDEVNUM,			"MaxMSDevNum",			"多状态设备数",					MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static tagMemDBField	g_PRRadFieldArray[]=
{
	{	PR_RADIAL_RINGBUS,				"RingBus",				"环网(环辐边界)母线名称",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_RADIAL_RINGKV,				"RingkV",				"环网(环辐边界)母线电压(kV)",	MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_RADIAL_LOADP,				"LoadP",				"辐射网内负荷(MW)",				MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_RADIAL_RINGBOUNDBUSPTR,		"RingBoundBusPtr",		"环网(环辐边界)母线索引",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRACBusFieldArray[]=
{
	{	PR_ACBUS_NAME,					"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACBUS_KV,					"kV",				"计算平均电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACBUS_ZONE,					"Zone",				"分区",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_ACBUS_GENP,					"GenP",				"母线发电有功(MW)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_GENQ,					"GenQ",				"母线发电无功(MVar)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_LOADP,					"LoadP",			"母线负荷有功(MW)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_LOADQ,					"LoadQ",			"母线负荷无功(MVar)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RADP,					"RadP",				"辐射网等效负荷(MW)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_SHUNTQ,				"ShuntQ",			"母线补偿无功(MVar)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RERR,					"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RREP,					"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_TREP,					"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADGENP,				"AdGenP",			"发电机调节量(MW)",					MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADLOADP,				"AdLoadP",			"负荷调节量(MW)",					MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADRADP,				"AdRadP",			"辐射网等效负荷调节量(MW)",			MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_GOODPROB,				"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_FAILPROB,				"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_IRT,					"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_IMAX,					"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_IMIN,					"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RERRMAX,				"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RERRMIN,				"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RTV,					"RtV",				"电压计算结果(kV)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_PFD,					"PfD",				"功角计算结果(Deg)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_PLC,					"PLC",				"切负荷概率",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_EFLC,					"EFLC",				"切负荷频率(次/年)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_EDLC,					"EDLC",				"切负荷持续时间(小时/年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADLC,					"ADLC",				"每次切负荷持续时间(小时/次)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ELC,					"ELC",				"负荷切除期望值(MW/年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_EENS,					"EENS",				"电量不足期望值(MWh/年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_BPII,					"BPECI",			"系统削减电量指标(MWh/MW.年)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_BPECI,					"BPII",				"系统停电指标(MW/MW.年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_SI,					"SI",				"严重程度指标(系统分/年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ISLAND,				"ACIsland",			"交流电岛",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACBUS_UVOLMTFREQ,			"UVOLmtFreq",		"电压越上限次数(次)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_UFOLMTFREQ,			"UFOLmtFreq",		"频率越上限次数(次)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_DVOLMTFREQ,			"DVOLmtFreq",		"电压越下限次数(次)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_DFOLMTFREQ,			"DFOLmtFreq",		"频率越下限次数(次)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_RADIAL,				"Radial",			"环辐网编号",						MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACBUS_SLACK,					"Slack",			"平衡母线标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_ACBUS_SRCBUS,				"SrcBus",			"电源母线标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_ACBUS_MIDBUS,				"MidBus",			"中性点标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_ACBUS_GENPMAX,				"GenPMax",			"母线所接发电机容量上限(MW)",		MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_GENPMIN,				"GenPMin",			"母线所接发电机容量下限(MW)",		MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_LOADPMIN,				"LoadPMin",			"母线所接负荷功率下限(MW)",			MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_BUS2LINE,				"Bus2Line",			"母线线路指针",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_BUS2TRAN,				"Bus2Tran",			"母线变压器指针",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_ZONESERIALNO,			"ZoneIndex",		"母线分区索引",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_RINGBOUND,				"RingBound",		"环网内环辐边界母线标记",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_LOADMSTATE,			"LoadMState",		"母线负荷多状态",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_DCBUS,					"DCBus",			"直流母线标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_RPARAMTYPE,			"RParamType",		"可靠性参数类型",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
};

static tagMemDBField	g_PRACLineFieldArray[]=
{
	{	PR_ACLINE_NAME,					"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_BUSI,					"BusI",				"起节点名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_BUSJ,					"BusJ",				"终节点名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_KVI,					"kVI",				"I侧电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_KVJ,					"kVJ",				"J侧电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PARID,				"ParlId",			"并联回路号",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_ACLINE_R,					"R",				"电阻(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_X,					"X",				"电抗(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_B,					"B",				"电纳(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RATED,				"Rated",			"额定容量(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_LENGTH,				"Length",			"长度(KM)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_WEIGHTS,				"Weights",			"越限指标权重",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RERR,					"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RREP,					"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_TREP,					"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_GOODPROB,				"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_FAILPROB,				"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_IRT,					"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_IMAX,					"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_IMIN,					"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RERRMAX,				"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RERRMIN,				"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_FAULTFREQ,			"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_OLMTFREQ,				"OLmtFreq",			"越限次数",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_OLMTVALUE,			"OLmtValue",		"越限功率(MW/次)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_ELMTCUTLOAD,			"ELmtCutLoad",		"消限切负荷电量(MW.h/年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RTPI,					"RtPi",				"RT起点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RTQI,					"RtQi",				"RT起点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RTPZ,					"RtPz",				"RT终点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RTQZ,					"RtQz",				"RT终点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_LOSSP,				"LossP",			"损耗(MW)",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFPI,					"PfPi",				"PF起点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFQI,					"PfQi",				"PF起点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFPZ,					"PfPz",				"PF终点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFQZ,					"PfQz",				"PF终点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRPI,					"TrPi",				"TR起点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRQI,					"TrQi",				"TR起点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRPZ,					"TrPz",				"TR终点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRQZ,					"TrQz",				"TR终点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_INIBUSI,				"IniBusI",			"Ini起节点名称",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_INIBUSJ,				"IniBusJ",			"Ini终节点名称",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_INIKVI,				"InikVI",			"Ini起点侧电压(kV)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_INIKVJ,				"InikVJ",			"Ini终点侧电压(kV)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_INILOOP,				"IniLoop",			"Ini并联回路号",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_ACLINE_BUSIPTR,				"BusIPtr",			"起节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_BUSJPTR,				"BusJPtr",			"终节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_RADIPTR,				"RadIPtr",			"起节点辐网编号",					MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_RADJPTR,				"RadJPtr",			"终节点辐网编号",					MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_SERIALNO,				"SerialNo",			"线路索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_ISLAND,				"ACIsland",			"交流电岛",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_OUTAGE,				"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACLINE_RPARAMTYPE,			"RParamType",		"可靠性参数类型",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_ACLINE_TRMISLAND,			"TrMIsland",		"N-1多岛",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACLINE_TRFACTORNUM,			"TrFactorNum",		"一阶相关开断分布因子个数",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PR_ACLINE_TCSCPTR,				"TCSCPtr",			"TCSC索引",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_UPFCPTR,				"UPFCPtr",			"UPFC索引",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static tagMemDBField	g_PRWindFieldArray[]=
{
	{	PR_WIND_NAME,					"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_BUSI,					"BusI",				"起节点名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_BUSJ,					"BusJ",				"终节点名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_KVI,					"kVI",				"I侧电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_KVJ,					"kVJ",				"J侧电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PARID,					"ParlId",			"并联回路号",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_WIND_R,						"R",				"电阻(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_X,						"X",				"电抗(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RATED,					"Rated",			"额定容量(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_WEIGHTS,				"Weights",			"越限指标权重",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RERR,					"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RREP,					"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_TREP,					"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_GOODPROB,				"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_FAILPROB,				"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_IRT,					"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_IMAX,					"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_IMIN,					"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RERRMAX,				"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RERRMIN,				"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_FAULTFREQ,				"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_OLMTFREQ,				"OLmtFreq",			"越限次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_OLMTVALUE,				"OLmtValue",		"越限功率(MW/次)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_ELMTCUTLOAD,			"ELmtCutLoad",		"消限切负荷电量(MW.h/年)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RTPI,					"RtPi",				"RT起点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RTQI,					"RtQi",				"RT起点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RTPZ,					"RtPz",				"RT终点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RTQZ,					"RtQz",				"RT终点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_LOSSP,					"LossP",			"损耗(MW)",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFPI,					"PfPi",				"PF起点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFQI,					"PfQi",				"PF起点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFPZ,					"PfPz",				"PF终点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFQZ,					"PfQz",				"PF终点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRPI,					"TrPi",				"TR起点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRQI,					"TrQi",				"TR起点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRPZ,					"TrPz",				"TR终点有功(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRQZ,					"TrQz",				"TR终点无功(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_INIBUSI,				"IniBusI",			"Ini起节点名称",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_INIBUSJ,				"IniBusJ",			"Ini终节点名称",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_INIKVI,					"InikVI",			"Ini起点侧电压(kV)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_INIKVJ,					"InikVJ",			"Ini终点侧电压(kV)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_INILOOP,				"IniLoop",			"Ini并联回路号",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_WIND_BUSIPTR,				"BusIPtr",			"起节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_BUSJPTR,				"BusJPtr",			"终节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_RADIPTR,				"RadIPtr",			"起节点辐网编号",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_WIND_RADJPTR,				"RadJPtr",			"终节点辐网编号",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_WIND_SERIALNO,				"SerialNo",			"变压器索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_ISLAND,					"ACIsland",			"交流电岛",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_WIND_GENTRAN,				"GenTran",			"发电机升压变标记",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_WIND_OUTAGE,					"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_WIND_RPARAMTYPE,				"RParamType",		"可靠性参数类型",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_WIND_TRMISLAND,				"TrMIsland",		"N-1多岛",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_WIND_TRFACTORNUM,			"TrFactorNum",		"一阶相关开断分布因子个数",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRGeneratorFieldArray[]=
{
	{	PR_GENERATOR_NAME,				"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_GENERATOR_BUSNAME,			"BusName",			"母线",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_GENERATOR_BUSKV,				"BuskV",			"电压(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_GENID,				"GenId",			"编号",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_GENERATOR_ZONE,				"Zone",				"分区",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_GENERATOR_P,					"P",				"有功(MW)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_Q,					"Q",				"无功(MVar)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_PMAX,				"PMax",				"最大有功(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_PMIN,				"PMin",				"最小有功(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_QMAX,				"QMax",				"最大无功(MVar)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_QMIN,				"QMin",				"最小无功(MVar)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_RERR,				"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_RREP,				"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_TREP,				"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_GOODPROB,			"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_FAILPROB,			"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_IRT,				"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_IMAX,				"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_IMIN,				"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_RERRMAX,			"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_RERRMIN,			"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_MSMODEL,			"MSModel",			"多状态模型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_GENERATOR_MSTATENUM,			"MStateNum"	,		"多状态状态数",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_GENERATOR_MSPOUT,			"MSPout",			"多状态状态",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_REFP,				"ReferenceP",		"给定有功(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_REFQ,				"ReferenceQ",		"给定无功(MVar)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_FAULTFREQ,			"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_GENERATOR_EQGEN,				"EQGen",			"等值电源标记",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_GENERATOR_RADIAL,			"Radial",			"环辐网编号",						MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_GENERATOR_BUSPTR,			"BusPtr",			"母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_GENERATOR_RPARAMTYPE,		"RParamType",		"可靠性参数类型",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_GENERATOR_OUTAGE,			"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRPowerLoadFieldArray[]=
{
	{	PR_POWERLOAD_NAME,				"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_POWERLOAD_BUSNAME,			"BusName",			"母线",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_POWERLOAD_BUSKV,				"BuskV",			"电压(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_ZONE,				"Zone",				"分区",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_POWERLOAD_P,					"P",				"有功(MW)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_Q,					"Q",				"无功(MVar)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_PMAX,				"PMax",				"最大有功(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_RERR,				"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_RREP,				"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_TREP,				"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_GOODPROB,			"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_FAILPROB,			"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_IRT,				"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_IMAX,				"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_IMIN,				"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_RERRMAX,			"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_RERRMIN,			"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_FAULTFREQ,			"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_POWERLOAD_MSMODEL,			"MSModel"	,		"多状态模型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_POWERLOAD_MSTATENUM,			"MStateNum"	,		"多状态状态数",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_POWERLOAD_MSPOUT,			"MSPout",			"多状态功率(MW)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_REFP,				"ReferenceP",		"给定有功(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_REFQ,				"ReferenceQ",		"给定无功(MVar)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_RADIAL,			"Radial",			"环辐网编号",						MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_POWERLOAD_BUSPTR,			"BusPtr",			"母线索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_POWERLOAD_AUXLOAD,			"AuxLoad",			"厂用电标记",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_POWERLOAD_EQLOAD,			"EQLoad",			"等值负荷标记",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_POWERLOAD_RPARAMTYPE,		"RParamType",		"可靠性参数类型",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_POWERLOAD_OUTAGE,			"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRHVDCFieldArray[]=
{
	{	PR_HVDC_NAME,					"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_ACBUSR,					"ACBusR",			"整流交流节点名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_ACBUSI,					"ACBusI",			"逆变交流节点名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_KVR,					"kVR",				"整流侧电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_KVI,					"kVI",				"逆变侧电压(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_R,						"R",				"电阻(欧姆)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_L,						"L",				"电感(毫亨)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_C,						"C",				"电容(微法)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_CON,					"Con",				"控制测R/I",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_HVDC_RATEDC,					"RatedC",			"额定电流(A)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_RECTV,					"RectV",			"整流侧直流电压(kV)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_RATEDP,					"RatedP",			"额定功率(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_POWER,					"Power",			"安排的直流功率(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_PWRR,					"PwrR",				"整流侧功率(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_PWRI,					"PwrI",				"逆变侧功率(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_LOSSP,					"LossP",			"损耗(MW)",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_RERR,					"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_RREP,					"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_TREP,					"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_GOODPROB,				"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_FAILPROB,				"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_IRT,					"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_IMAX,					"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_IMIN,					"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_RERRMAX,				"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_RERRMIN,				"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_FAULTFREQ,				"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_MSMODEL,				"MSModel",			"多状态模型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_HVDC_MSTATENUM,				"MStateNum"		,	"多状态状态数",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_HVDC_MSPOUT,					"MSPout",			"多状态功率状态",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_INIBUSR,				"IniBusR",			"Ini整流节点名称",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_INIBUSI,				"IniBusI",			"Ini逆变节点名称",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_INIPWRR,				"IniPwrR",			"Ini整流侧功率(MW)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_INIPWRI,				"IniPwrI",			"Ini逆变侧功率(MW)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_ACBUSRPTR,				"ACBusRPtr",		"整流节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_ACBUSIPTR,				"ACBusIPtr",		"逆变节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_SERIALNO,				"SerialNo",			"直流索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_OUTAGE,					"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRConverterFieldArray[]=
{
	{	PR_CONVERTER_NAME,				"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_CONVERTER_BUSAC,				"BusAC",			"交流节点名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_CONVERTER_BUSDC,				"BusDC",			"直流节点名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_CONVERTER_SCHEDPOWER,		"SchedPower",		"安排的功率(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_CONVERTER_TYPE,				"Type",				"变换器类型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRConverterTypeEnum)/sizeof(tagMemDBEnumPair),		g_PRConverterTypeEnum,		},
	{	PR_CONVERTER_RERR,				"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_RREP,				"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_TREP,				"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_GOODPROB,			"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_FAILPROB,			"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_IRT,				"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_IMAX,				"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_IMIN,				"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_RERRMAX,			"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_RERRMIN,			"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_FAULTFREQ,			"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CONVERTER_ACBUSPTR,			"ACBusPtr",			"交流节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CONVERTER_DCBUSPTR,			"DCBusPtr",			"直流节点索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CONVERTER_OUTAGE,			"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRDCBusFieldArray[]=
{
	{	PR_DCBUS_NAME,					"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static tagMemDBField	g_PRDCLineFieldArray[]=
{
	{	PR_DCLINE_NAME,					"Name",				"名称",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DCLINE_DCBUSI,				"DCBusI",			"I侧直流节点名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DCLINE_DCBUSJ,				"DCBusJ",			"J侧直流节点名称",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DCLINE_LENGTH,				"Length",			"长度(KM)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_DCLINE_RERR,					"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_RREP,					"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_TREP,					"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_GOODPROB,				"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_FAILPROB,				"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_IRT,					"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_IMAX,					"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_IMIN,					"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_RERRMAX,				"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_RERRMIN,				"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_FAULTFREQ,			"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_DCLINE_DCBUSIPTR,			"DCBusIPtr",		"I侧直流节点索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_DCLINE_DCBUSJPTR,			"DCBusJPtr",		"J侧直流节点索引",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_DCLINE_OUTAGE,				"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRTCSCFieldArray[]=
{
	{	PR_TCSC_NAME,					"Name",				"交流线路名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_TCSC_INSTBUS,				"InstallBus",		"安装母线名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_TCSC_X,						"X",				"串联电抗值(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_TCSC_RERR,					"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_RREP,					"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_TREP,					"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_GOODPROB,				"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_FAILPROB,				"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_IRT,					"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_IMAX,					"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_IMIN,					"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_RERRMAX,				"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_RERRMIN,				"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_FAULTFREQ,				"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TCSC_INSTBUSPTR,				"InstBusPtr",		"安装母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TCSC_ACLINEPTR,				"ACLinePtr",		"交流线路索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TCSC_OUTAGE,					"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRUPFCFieldArray[]=
{
	{	PR_UPFC_NAME,					"Name",				"交流线路名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_UPFC_SERIESBUS,				"SeriesBus",		"串联母线名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_UPFC_PARALLELBUS,			"ParallelBus",		"并联母线名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_UPFC_CAPACITY,				"Capacity",			"容量(MVA)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_UPFC_RERR,					"Rerr",				"故障率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_RREP,					"Rrep",				"修复率(次/年)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_TREP,					"Trep",				"修复时间(小时/次)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_GOODPROB,				"GoodProb",			"完好概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_FAILPROB,				"FailProb",			"故障概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_IRT,					"IRt",				"实际值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_IMAX,					"IMax",				"下限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_IMIN,					"IMin",				"上限值",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_RERRMAX,				"RerrMax",			"故障率上限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_RERRMIN,				"RerrMin",			"故障率下限值",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_LINEPSE,				"LinePse",			"串联侧注入功率(MW)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_UPFC_P,						"P",				"串联侧控制功率(MW)",				MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_FAULTFREQ,				"FaultFreq",		"故障次数(次)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_SERIESBUSPTR,			"SeriesBusPtr",		"串联母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_PARALLELBUSPTR,			"ParallelBusPtr",	"并联母线索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_ACLINEPTR,				"ACLinePtr",		"交流线路索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_OUTAGE,					"Outage",			"停运",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

// static tagMemDBField	g_PRDevMStateFieldArray[]=
// {
// 	{	PR_DEVMSTATE_TYPE,				"Type",				"设备类型",							MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),		0,	NULL,	},
// 	{	PR_DEVMSTATE_NAME,				"Name",				"设备名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
// 	{	PR_DEVMSTATE_STATERATE,			"StateRate",		"状态出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEPROB,			"StateProb",		"状态概率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ1,		"StateFreq1",		"ID-1状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ2,		"StateFreq2",		"ID-2状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ3,		"StateFreq3",		"ID-3状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ4,		"StateFreq4",		"ID-4状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ5,		"StateFreq5",		"ID-5状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ6,		"StateFreq6",		"ID-6状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ7,		"StateFreq7",		"ID-7状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ8,		"StateFreq8",		"ID-8状态转移率(次/年)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_SERIALNO,				"SerialNo",			"设备索引",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
// };

static tagMemDBField	g_PRDevMStateFieldArray[]=
{
	{	PR_DEVMSTATE_TYPE,				"Type",				"设备类型",							MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_DEVMSTATE_NAME,				"Name",				"设备名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DEVMSTATE_STATENUM,			"StateNum",			"状态数",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_DEVMSTATE_STATE1RATE,		"State1Rate",		"状态1出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2RATE,		"State2Rate",		"状态2出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3RATE,		"State3Rate",		"状态3出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4RATE,		"State4Rate",		"状态4出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5RATE,		"State5Rate",		"状态5出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6RATE,		"State6Rate",		"状态6出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7RATE,		"State7Rate",		"状态7出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8RATE,		"State8Rate",		"状态8出力(比率)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1PROB,		"State1Prob",		"状态1概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2PROB,		"State2Prob",		"状态2概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3PROB,		"State3Prob",		"状态3概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4PROB,		"State4Prob",		"状态4概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5PROB,		"State5Prob",		"状态5概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6PROB,		"State6Prob",		"状态6概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7PROB,		"State7Prob",		"状态7概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8PROB,		"State8Prob",		"状态8概率",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ1,		"State1Freq1",		"状态1-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ2,		"State1Freq2",		"状态1-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ3,		"State1Freq3",		"状态1-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ4,		"State1Freq4",		"状态1-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ5,		"State1Freq5",		"状态1-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ6,		"State1Freq6",		"状态1-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ7,		"State1Freq7",		"状态1-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ8,		"State1Freq8",		"状态1-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ1,		"State2Freq1",		"状态2-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ2,		"State2Freq2",		"状态2-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ3,		"State2Freq3",		"状态2-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ4,		"State2Freq4",		"状态2-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ5,		"State2Freq5",		"状态2-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ6,		"State2Freq6",		"状态2-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ7,		"State2Freq7",		"状态2-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ8,		"State2Freq8",		"状态2-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ1,		"State3Freq1",		"状态3-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ2,		"State3Freq2",		"状态3-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ3,		"State3Freq3",		"状态3-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ4,		"State3Freq4",		"状态3-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ5,		"State3Freq5",		"状态3-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ6,		"State3Freq6",		"状态3-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ7,		"State3Freq7",		"状态3-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ8,		"State3Freq8",		"状态3-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ1,		"State4Freq1",		"状态4-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ2,		"State4Freq2",		"状态4-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ3,		"State4Freq3",		"状态4-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ4,		"State4Freq4",		"状态4-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ5,		"State4Freq5",		"状态4-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ6,		"State4Freq6",		"状态4-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ7,		"State4Freq7",		"状态4-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ8,		"State4Freq8",		"状态4-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ1,		"State5Freq1",		"状态5-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ2,		"State5Freq2",		"状态5-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ3,		"State5Freq3",		"状态5-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ4,		"State5Freq4",		"状态5-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ5,		"State5Freq5",		"状态5-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ6,		"State5Freq6",		"状态5-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ7,		"State5Freq7",		"状态5-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ8,		"State5Freq8",		"状态5-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ1,		"State6Freq1",		"状态6-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ2,		"State6Freq2",		"状态6-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ3,		"State6Freq3",		"状态6-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ4,		"State6Freq4",		"状态6-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ5,		"State6Freq5",		"状态6-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ6,		"State6Freq6",		"状态6-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ7,		"State6Freq7",		"状态6-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ8,		"State6Freq8",		"状态6-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ1,		"State7Freq1",		"状态7-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ2,		"State7Freq2",		"状态7-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ3,		"State7Freq3",		"状态7-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ4,		"State7Freq4",		"状态7-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ5,		"State7Freq5",		"状态7-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ6,		"State7Freq6",		"状态7-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ7,		"State7Freq7",		"状态7-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ8,		"State7Freq8",		"状态7-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ1,		"State8Freq1",		"状态8-1转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ2,		"State8Freq2",		"状态8-2转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ3,		"State8Freq3",		"状态8-3转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ4,		"State8Freq4",		"状态8-4转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ5,		"State8Freq5",		"状态8-5转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ6,		"State8Freq6",		"状态8-6转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ7,		"State8Freq7",		"状态8-7转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ8,		"State8Freq8",		"状态8-8转移率(次/年)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_SERIALNO,				"SerialNo",			"设备索引",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static tagMemDBField	g_PRLoadCurveFieldArray[]=
{
	{	PR_LOADCURVE_BUS,				"BusName",			"母线名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_LOADCURVE_ID,				"ID",				"曲线点日",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PR_LOADCURVE_VALDAY,			"ValDay",			"曲线点日值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALAVER,			"ValAver",			"曲线点均值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALMAX,			"ValMax",			"曲线点大值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALMIN,			"ValMin",			"曲线点小值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PR_LOADCURVE_VALUE01,			"Value01",			"曲线点01值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE02,			"Value02",			"曲线点02值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE03,			"Value03",			"曲线点03值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE04,			"Value04",			"曲线点04值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE05,			"Value05",			"曲线点05值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE06,			"Value06",			"曲线点06值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE07,			"Value07",			"曲线点07值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE08,			"Value08",			"曲线点08值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE09,			"Value09",			"曲线点09值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE10,			"Value10",			"曲线点10值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE11,			"Value11",			"曲线点11值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE12,			"Value12",			"曲线点12值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE13,			"Value13",			"曲线点13值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE14,			"Value14",			"曲线点14值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE15,			"Value15",			"曲线点15值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE16,			"Value16",			"曲线点16值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE17,			"Value17",			"曲线点17值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE18,			"Value18",			"曲线点18值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE19,			"Value19",			"曲线点19值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE20,			"Value20",			"曲线点20值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE21,			"Value21",			"曲线点21值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE22,			"Value22",			"曲线点22值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE23,			"Value23",			"曲线点23值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE24,			"Value24",			"曲线点24值(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRACIslandFieldArray[]=
{
	{	PR_ACISLAND_GENP,				"GenP",				"岛发电(MW)",						MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACISLAND_LOADP,				"LoadP",			"岛负荷(MW)",						MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACISLAND_BUSNUM,				"BusNum",			"岛内母线数",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACISLAND_SWINGBUS,			"SwingBus",			"平衡节点",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACISLAND_DEAD,				"Dead",				"死岛",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRZoneFieldArray[]=
{
	{	PR_ZONE_NAME,					"Name",				"分区名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PR_ZONE_AREA,					"Area",				"区域名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PR_ZONE_TOTGENP,				"TotalGenP",		"分区发电(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ZONE_TOTLOADP,				"TotalLoadP",		"分区负荷(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ZONE_CUTLOADP,				"FCutLoadP",		"分区事故切负荷(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRACLineEdgeFieldArray[]=
{
	{	PR_ACLINEEDGE_BUS,				"Bus",				"母线名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINEEDGE_KV,				"kV",				"母线电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINEEDGE_NAME,				"Name",				"线路名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINEEDGE_LINEPTR,			"LinePtr",			"线路索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRWindEdgeFieldArray[]=
{
	{	PR_WINDEDGE_BUS,				"Bus",				"母线名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WINDEDGE_KV,					"kV",				"母线电压(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WINDEDGE_NAME,				"Name",				"变压器名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WINDEDGE_TRANPTR,			"TranPtr",			"变压器索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRLDFactorFieldArray[]=
{
	{	PR_LDFACTOR_LINEIDX,			"LineIdx",			"变压器索引",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_LDFACTOR_BUSIDX,				"BusIdx",			"母线索引",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_LDFACTOR_DFACTOR,			"DFactor",			"分布因子",							MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRTDFactorFieldArray[]=
{
	{	PR_TDFACTOR_TRANIDX,			"LineIdx",			"变压器索引",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TDFACTOR_BUSIDX,				"BusIdx",			"母线索引",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TDFACTOR_DFACTOR,			"DFactor",			"分布因子",							MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRCommRParamFieldArray[]=
{
	{	PR_COMMPARAM_DEVTYPE,			"DevType",			"设备类型",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_COMMPARAM_KEYWORD,			"KeyWord",			"关键字",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PR_COMMPARAM_UPCAPLMT,			"UpCapLmt",			"容量上限",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_DNCAPLMT,			"DnCapLmt",			"容量下限",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_UPVLMT,			"UpVLmt",			"电压上限",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_DNVLMT,			"DnVLmt",			"电压下限",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_RERR,				"Rerr",				"故障率",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_TREP,				"Trep",				"修复时间",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRManualFaultFieldArray[]=
{
	{	PR_MANUALFAULT_NAME,			"Name",				"设置事件名称(Id)",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_MANUALFAULT_FDEVTYPE,		"FDevType",			"故障设备类型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_MANUALFAULT_FDEVNAME,		"FDevName",			"故障设备名称",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_MANUALFAULT_FDEVSERNO,		"FDevSerno",		"故障设备索引",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_MANUALFAULT_PROC,			"Proc",				"标记状态",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRCommonFaultFieldArray[]=
{
	{	PR_COMMONFAULT_NAME,			"Name",				"共因故障名称(Id)",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_COMMONFAULT_COMMFAULTTYPE,	"CommonFaultType",	"共因故障类型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRCommonFaultTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRCommonFaultTypeEnum,	},
	{	PR_COMMONFAULT_DEVICECOMMTYPE,	"CommonDeviceType",	"共因设备类型",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRCommonDeviceTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRCommonDeviceTypeEnum,	},
	{	PR_COMMONFAULT_DEVTYPE,			"DevType",			"设备类型",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_COMMONFAULT_DEVNAME,			"DevName",			"设备名称",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_COMMONFAULT_DEVSERNO,		"DevSerNo",			"设备索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_COMMONFAULT_PROC,			"Proc",				"标记状态",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PR2StateCompFieldArray[]=
{
	{	PR_R2STATECOMP_TYPE,			"Type",				"类型",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_R2STATECOMP_SERIALNO,		"SerialNo",			"设备索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRMStateCompFieldArray[]=
{
	{	PR_RMSTATECOMP_TYPE,			"Type",				"类型",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_RMSTATECOMP_SERIALNO,		"SerialNo",			"设备索引",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRTripFieldArray[]=
{
	{	PR_TRIP_DEVNUM,					"TripDevNum",		"开断设备数",						MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_TRIP_TRB1TYP,				"TrB1Type",			"开断设备1类型",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_TRIP_TRB1IDX,				"TrB1Bran",			"开断设备1索引",					MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIP_TRB2TYP,				"TrB2Type",			"开断设备2类型",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_TRIP_TRB2IDX,				"TrB2Bran",			"开断设备2索引",					MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIP_FAULTTYPE,				"FaultType",		"故障类型",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFModeFaultTypeEnum)/sizeof(tagMemDBEnumPair),		g_PRFModeFaultTypeEnum,		},
	{	PR_TRIP_OUTLOADP,				"OutageLoadP",		"失电总负荷",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_TRIP_OVERLMT,				"OverLmt",			"是否越限",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRTripMIslandFieldArray[]=
{
	{	PR_TRIPMISLAND_TRIP,			"Trip",				"开断故障索引",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPMISLAND_OUTAGEBUS,		"OutageBus",		"孤岛母线",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPMISLAND_OUTAGELOADP,		"OutageLoadP",		"孤岛负荷功率(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRTripOvlDevFieldArray[]=
{
	{	PR_TRIPOVLDEV_TRIP,				"Trip",				"开断故障索引",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPOVLDEV_TYPE,				"OvlmtDevTyp",		"越限设备类型",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_TRIPOVLDEV_SERIALNO,			"OvlmtDevIdx",		"越限设备索引",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPOVLDEV_OVLVAL,			"OvLmtValue",		"越限值(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_TRIPOVLDEV_RATED,			"Rated",			"额定值(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

// static tagMemDBField	g_PRMCSampleStateFieldArray[]=
// {
// 	{	PR_MCSAMPLESTATE_FSTATENO,		"FState",			"状态索引",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
// 	{	PR_MCSAMPLESTATE_CUTLOAD,		"OutLoad",			"损失负荷状态",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
// 	{	PR_MCSAMPLESTATE_MSTATE,		"MState",			"多状态场景",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
// };

static tagMemDBField	g_PRFStateFieldArray[]=
{
	{	PR_FSTATE_ID,					"FStateID",			"状态ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATE_SAMPLETYPE,			"SampleType",		"抽样算法",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateSampleMethodEnum)/sizeof(tagMemDBEnumPair),	g_PRFStateSampleMethodEnum,	},
	{	PR_FSTATE_FDEVNUM,				"FDevNum",			"故障设备数",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATE_PROBABILITY,			"Probability",		"状态概率",							MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_FSTATE_DURITION,				"Durition",			"持续时间",							MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_FSTATE_STATENUM,				"StateNum",			"状态出现次数",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATE_FLOSSGEN,				"FLossGen",			"故障损失发电机出力(MW)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_FLOSSGENCAP,			"FLossGenCap",		"故障损失发电机容量(MW)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_FLOSSLOAD,			"FLossLoad",		"故障损失负荷功率(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_MISLAND,				"MIsland",			"形成多岛",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),					g_PREnumNoYes,				},
	{	PR_FSTATE_MIINSGEN,				"MIslandInsGen",	"孤岛增加出力(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_MICUTGEN,				"MIslandCutGen",	"孤岛减少出力(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_MICUTLOAD,			"MIslandOutLoad",	"孤岛损失负荷(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_AGCINSGEN,			"BalanceInsGen",	"功率平衡发电机增出力(MW)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_AGCCUTGEN,			"BalanceCutGen",	"功率平衡发电机减出力(MW)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_AGCCUTLOAD,			"BalanceCutLoad",	"功率平衡损失负荷(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_OVERLIMIT,			"OverLimit",		"设备越限",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),					g_PREnumNoYes,				},
	{	PR_FSTATE_ELIMIT,				"ELimit",			"消限切负荷",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),					g_PREnumNoYes,				},
	{	PR_FSTATE_ELCUTGEN,				"ELimitCutGen",		"消限减少出力(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_ELINSGEN,				"ELimitInsGen",		"消限增加出力(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_ELCUTLOAD,			"ELimitCutLoad",	"消限损失负荷(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_ELRESULT,				"ELimitResult",		"充裕度评估消限结果",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateAdResultEnum)/sizeof(tagMemDBEnumPair),		g_PRFStateAdResultEnum,		},
	{	PR_FSTATE_MAXFAULTZONE,			"MaxFaultZone",		"最大负荷损失分区索引",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATE_MAXFAULTRATIO,		"MaxFaultRatio",	"最大负荷损失分区占比",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_FAULTGRADE,			"FaultGrade",		"事故等级",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateFaultGradeEnum)/sizeof(tagMemDBEnumPair),			g_PRFStateFaultGradeEnum,		},
	{	PR_FSTATE_MSOUTSERIALNO,		"MSoutIndex",		"多状态模型功率状态索引",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_FSTATE_ESTIMATED,			"Estimated",		"评估状态",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATE_ELAPSETIME,			"ElapseTime",		"评估时间",							MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateFDevFieldArray[]=
{
	{	PR_FSTATEFDEV_FSTATEID,			"FStateId",			"状态ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEFDEV_FSTATENO,			"FStateNo",			"状态序号",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEFDEV_FDEVTYP,			"FDevTyp",			"故障设备类型",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEFDEV_FDEVIDX,			"FDevIdx",			"故障设备索引",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEFDEV_DFLTPOS,			"DFltPos",			"设备故障位置",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEFDEV_DFLTTYP,			"DFltTyp",			"设备故障类型",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateFaultTypeEnum)/sizeof(tagMemDBEnumPair),		g_PRFStateFaultTypeEnum,	},
};

static tagMemDBField	g_PRMStateFieldArray[]=
{
	{	PR_FSTATEMSTATE_MSDEVTYPE,		"MSDevType",		"多状态设备类型",					MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEMSTATE_MSDEVIDX,		"MSDevIndex",		"多状态设备索引",					MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMSTATE_MSTATEPOUT,		"MStatePout",		"多状态出力状态",					MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateMIslandFieldArray[]=
{
	{	PR_FSTATEMISLAND_FSTATEID,		"FStateId",			"状态ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMISLAND_FSTATENO,		"FStateNo",			"状态序号",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMISLAND_OUTAGEBUS,		"OutageBus",		"孤岛母线",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMISLAND_OUTAGELOADP,	"OutageLoadP",		"孤岛负荷功率(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateOvlDevFieldArray[]=
{
	{	PR_FSTATEOVLDEV_FSTATEID,		"FStateId",			"状态ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_FSTATENO,		"FStateNo",			"状态序号",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_DEVTYP,			"DevTyp",			"越限设备类型",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEOVLDEV_DEVIDX,			"DevIdx",			"越限设备索引",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_OVLMTP,			"OvLmtP",			"越限值(MW)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_RATED,			"Rated",			"额定值(MW)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_ADLMTP,			"AdLmtP",			"消限值(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateOvlAdFieldArray[]=
{
	{	PR_FSTATEOVLAD_FSTATEID,		"FStateId",			"状态ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_FSTATENO,		"FStateNo",			"状态序号",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_OVLDEVTYP,		"OvlDevTyp",		"越限设备类型",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEOVLAD_OVLDEVICE,		"OvlDevice",		"越限设备索引",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_ADJDEVTYP,		"AdjDevTyp",		"调整设备类型",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEOVLAD_ADJDEVICE,		"AdjDevice",		"调整设备索引",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_ADJVALUE,		"AdjValue",			"功率调整量(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRAdsNodeFieldArray[]=
{
	{	PR_ADSNODE_ID,					"Id",				"节点ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ADSNODE_NAME,				"Name",				"节点名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_ADSNODE_STATUS,				"Status",			"节点状态(0退出，1运行)",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ADSNODE_TASKCOUNT,			"TaskCount",		"累积执行任务次数",					MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcJobTypeFieldArray[]=
{
	{	PR_CALCJOBTYPE_ID,				"Id",				"工作类型ID",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOBTYPE_NAME,			"Name",				"工作类型名称",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOBTYPE_DESP,			"Desp",				"工作类型描述",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOBTYPE_NODEID,			"NodeId",			"发起节点",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcJobFieldArray[]=
{
	{	PR_CALCJOB_ID,					"Id",				"工作ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_TYPEID,				"TypeId",			"工作类型ID",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_NAME,				"Name",				"工作名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOB_DESP,				"Desp",				"工作描述",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOB_CONFIG,				"Config",			"配置信息",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOB_INITIME,				"IniTime",			"开始时间",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_ENDTIME,				"EndTime",			"结束时间",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_ELAPSETIME,			"ElapseTime",		"耗时",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcTaskFieldArray[]=
{
	{	PR_CALCTASK_ID,					"Id",				"任务ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_JOBID,				"JobId",			"所属工作ID",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_CONTENT,			"Content",			"任务内容",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCTASK_INITIME,			"IniTime",			"开始时间",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_ENDTIME,			"EndTime",			"结束时间",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_ELAPSETIME,			"ElapseTime",		"耗时",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcFileFieldArray[]=
{
	{	PR_CALCFILE_JOBID,				"JobId",			"工作ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCFILE_NAME,				"Name",				"文件名称",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCFILE_TYPE,				"Type",				"文件类型",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_CALCFILE_CONTENT,			"Content",			"任务内容",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
};

static tagMemDBField	g_PRFSecurityFieldArray[]=
{
	{	PR_FSECURITY_FSTATEID,			"FStateId",			"状态ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSECURITY_FSTATENO,			"FStateNo",			"状态序号",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSECURITY_LTFAULT,			"LTFault",			"支路故障",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSECURITY_MISLAND,			"MIsland",			"多岛故障",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSECURITY_LOSSGENP,			"LossGenP",			"发电出力损失(MW)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSECURITY_BSEFILE,			"BseFile",			"Bse文件名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_FSECURITY_SWIFILE,			"SwiFile",			"Swi文件名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_FSECURITY_OUTFILE,			"OutFile",			"Out文件名",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_FSECURITY_RESULT,			"Result",			"安全性评估结果",					MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFSecurityResultEnum)/sizeof(tagMemDBEnumPair),	g_PRFSecurityResultEnum,		},
	{	PR_FSECURITY_ESTIMATED,			"Estimated",		"评估标记位",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRCopGenFieldArray[]=
{
	{	PR_COPGEN_SERIALNO,				"SerialNo",			"设备索引",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_COPGEN_CAPACITY,				"Capacity",			"发电机容量(MW)",					MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_ALPHA,				"Alpha",			"折算系数",							MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_S1CAPACITY,			"S1Capacity",		"发电机折算容量1(MW)",				MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_S2CAPACITY,			"S2Capacity",		"发电机折算容量2(MW)",				MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_RERR,					"Rerr",				"故障率(次/天)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_TREP,					"Trep",				"修复时间(天/次)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_RREP,					"Rrep",				"修复率(次/天)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_ROUT,					"Rout",				"停运率(次/天)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_3STATE,				"ThreeState",		"三状态",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRCopTableFieldArray[]=
{
	{	PR_COPTABLE_STATE,				"State",			"状态",								MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_COPTABLE_OUTAGECAPACITY,		"OutageCapacity",	"停运发电容量(MW)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_AVAILCAPACITY,		"AvailCapacity",	"可用发电容量(MW)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_STATEPROB,			"StateProb",		"状态概率",							MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_ACCUMPROB,			"AccumProb",		"状态累计概率",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_STATEFREQ,			"StateFreq",		"状态频率(次)",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_ACCUMFREQ,			"AccumFreq",		"状态累计频率(次)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_DEPRP,				"DepRP",			"递增有效离去率",					MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_DEPRN,				"DepRN",			"递减有效离去率",					MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

#if !defined(__GNUG__) && !defined(__GNUC__)
#	pragma pack()
#	if (defined(_AIX) || defined(AIX))
#		pragma align(fPower)
#	else
#		if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#			pragma pack(pop)
#		endif
#	endif
#endif

