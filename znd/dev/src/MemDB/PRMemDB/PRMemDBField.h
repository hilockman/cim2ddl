#pragma once

#include "PRMemDBDefine.h"

#if defined(__GNUG__) || defined(__GNUC__)	// GCC������Ԥ����ĺ�
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
	{	0,		"��",	},
	{	1,		"��",	},
};

static	tagMemDBEnumPair	g_PREnumSide[]=
{
	{	PREnum_DeviceSide_I,					"I��",			},
	{	PREnum_DeviceSide_J,					"J��",			},
};

static	tagMemDBEnumPair	g_PRSystemNetworkTypeEnum[]=
{
	{	PRSystem_NetworkType_1,					"�����Ե���",		},
	{	PRSystem_NetworkType_2,					"ʡ������������",	},
	{	PRSystem_NetworkType_3,					"ֱϽ�е���",		},
	{	PRSystem_NetworkType_4,					"ʡ����е���",		},
	{	PRSystem_NetworkType_5,					"һ����е���",		},
	{	PRSystem_NetworkType_6,					"�ؼ��е���",		},
};

static	tagMemDBEnumPair	g_PRSystemSampleObjectEnum[]=
{
	{	PRSystem_SampleObject_All,				"ȫ��",			},
	{	PRSystem_SampleObject_Bran,				"֧·",			},
	{	PRSystem_SampleObject_Gen,				"�����",		},
};

static	tagMemDBEnumPair	g_PRDeviceRParamTypeEnum[]=
{
	{	PRDevice_RParamType_Common,				"��������",		},
	{	PRDevice_RParamType_Device,				"�豸����",		},
};

static	tagMemDBEnumPair	g_PRCommonFaultTypeEnum[]=
{
	{	PRCommonFault_CommonFaultType_Status,		"״̬����",		},
	{	PRCommonFault_CommonFaultType_PValue,		"���ʹ���",		},
};

static	tagMemDBEnumPair	g_PRCommonDeviceTypeEnum[]=
{
	{	PRCommonFault_DeviceCommonType_Result,		"����ԭ���豸",		},
	{	PRCommonFault_DeviceCommonType_Resion,		"�������豸",		},
};

static	tagMemDBEnumPair	g_PRFModeFaultTypeEnum[]=
{
	{	PRTrip_FaultType_Unknown,				"δ֪",			},
	{	PRTrip_FaultType_MIsland,				"����",			},
	{	PRTrip_FaultType_OverLmt,				"Խ��",			},
	{	PRTrip_FaultType_MiAndOl,				"����&Խ��",	},
};

static	tagMemDBEnumPair	g_PRFStateAdResultEnum[]=
{
	{	PRFState_AdResult_Unknown,				"δ֪",			},
	{	PRFState_AdResult_Normal,				"����",			},
	{	PRFState_AdResult_OverLmt,				"Խ��",			},
	{	PRFState_AdResult_Unadjustable,			"���ɵ���",		},
};

static	tagMemDBEnumPair	g_PRFSecurityResultEnum[]=
{
	{	PRFSecurity_Result_Unknown,				"δ֪",			},
	{	PRFSecurity_Result_Secure,				"��ȫ",			},
	{	PRFSecurity_Result_InSecure,			"����ȫ"	,	},
};

static	tagMemDBEnumPair	g_PRFStateSampleMethodEnum[]=
{
	{	PRFState_SamplingMethod_Unknown,		"δ֪",			},
	{	PRFState_SamplingMethod_MonteCarlo,		"���ؿ���",		},
	{	PRFState_SamplingMethod_StateSample,	"״̬����",		},
	{	PRFState_SamplingMethod_Analytical,		"������",		},
	{	PRFState_SamplingMethod_FastSort,		"��������",		},
	{	PRFState_SamplingMethod_Manual,			"�����¼�",		},
};

static	tagMemDBEnumPair	g_PRFStateStateTypeEnum[]=
{
	{	PRFState_StateType_Fault,				"����",			},
	{	PRFState_StateType_MState,				"��״̬",		},
	{	PRFState_StateType_All,					"����+��״̬",	},
};

static	tagMemDBEnumPair	g_PRFStateFaultGradeEnum[]=
{
	{	PRFState_FaultGrade_0,					"���¹�",		},
	{	PRFState_FaultGrade_1,					"һ���¹�",		},
	{	PRFState_FaultGrade_2,					"�ϴ��¹�",		},
	{	PRFState_FaultGrade_3,					"�ش��¹�",		},
	{	PRFState_FaultGrade_4,					"�ر��ش��¹�",	},
};

static	tagMemDBEnumPair	g_PRFStateFaultTypeEnum[]=
{
	{	PRFState_FaultType_Unknown,				"δ֪",			},
	{	PRFState_FaultType_Trip,				"ͣ��",			},
	{	PRFState_FaultType_OnePhaseGround,		"��������",		},
	{	PRFState_FaultType_TwoPhase,			"����·",		},
	{	PRFState_FaultType_ThreePhase,			"�����·",		},
	{	PRFState_FaultType_TwoPhaseGround,		"����ӵ�",		},
	{	PRFState_FaultType_CommonFault,			"�������",		},
};

static	tagMemDBEnumPair	g_PRBalanceAdAdTypeEnum[]=
{
	{	PRBalanceAd_AdType_Gen,					"���������",	},
	{	PRBalanceAd_AdType_Load,				"�и��ɹ���",	},
};

static	tagMemDBEnumPair	g_PRConverterTypeEnum[]=
{
	{	PRConverter_Type_Rectifier,				"����",			},
	{	PRConverter_Type_Inverter,				"���",			},
};

static	tagMemDBEnumPair	g_PRConverterFEffectEnum[]=
{
	{	PRConverter_FEffect_Broken,				"����",			},
	{	PRConverter_FEffect_Connect,			"��ͨ",			},
};

static tagMemDBField	g_PRSystemFieldArray[]=
{
	{	PR_SYSTEM_MVABASE,				"MvaBase",				"���ʻ�׼",							MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_GENP,					"GenP",					"ϵͳ�ܷ���(����)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOADP,				"LoadP",				"ϵͳ�ܸ���(����)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_DCP,					"DCP",					"ϵͳֱ������(����)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_AVAILGENP,			"AvailGenP",			"ϵͳ��װ��(����)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MAXLOADP,				"MaxLoadP",				"ϵͳ��󸺺�(����)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},

	{	PR_SYSTEM_SAMPLEMETHOD,			"SampleMethod",			"��������",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateSampleMethodEnum)/sizeof(tagMemDBEnumPair),	g_PRFStateSampleMethodEnum,	},
	{	PR_SYSTEM_SAMPLEOBJECT,			"SampleObject",			"��������",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRSystemSampleObjectEnum)/sizeof(tagMemDBEnumPair),	g_PRSystemSampleObjectEnum,	},
	{	PR_SYSTEM_MAXBFLT,				"MaxBranFlt",			"���֧·��������",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_SYSTEM_MAXGFLT,				"MaxGenFlt",			"��󷢵����������",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PR_SYSTEM_MCSSIMTIME,			"MCSSimulateTime",		"���ؿ��޷�ģ��ʱ��(Сʱ)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MCSMINPROB,			"MCSMinProb",			"���ؿ��޷���С����ֵ",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FSTCUMULATEPROB,		"FSTCumulateProb",		"�������򷨽�ֹ�ۼƸ���ֵ",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FSTMAXSTATE,			"FSTMaxState",			"�������򷨽�ֹ״̬��",				MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_SYSTEM_FSTMINPROB,			"FSTMinProb",			"����������С����ֵ",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_STSMAXSTATE,			"STSMaxState",			"״̬��������ֹ״̬��",				MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_SYSTEM_ANAMINPROB,			"ANAMinProb",			"��������С����ֵ",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},

	{	PR_SYSTEM_BPADATFILE,			"BpaDatFile",			"Bpa�����ļ�",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_SYSTEM_BPASWIFILE,			"BpaSwiFile",			"Bpa�ȶ��ļ�",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_SYSTEM_SECURITYEXECDIR,		"SecurityExecDir",		"��ȫ��������Ŀ¼",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_SYSTEM_SECURITYDESTDIR,		"SecurityDestDir",		"��ȫ�������Ŀ¼",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},

	{	PR_SYSTEM_SECURITYMAXANGLE,		"SecurityMaxAngle",		"��ȫ������󹦽ǲ�",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXVOLT,		"SecurityMaxVolt",		"��ȫ������ߵ�ѹ",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXVDUR,		"SecurityMaxVDur",		"��ȫ������ߵ�ѹ����ʱ��",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINVOLT,		"SecurityMinVolt",		"��ȫ������͵�ѹ",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINVDUR,		"SecurityMinVDur",		"��ȫ������͵�ѹ����ʱ��",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXFREQ,		"SecurityMaxFreq",		"��ȫ�������Ƶ��",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMAXFDUR,		"SecurityMaxFDur",		"��ȫ�������Ƶ�ʳ���ʱ��",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINFREQ,		"SecurityMinFreq",		"��ȫ�������Ƶ��",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SECURITYMINFDUR,		"SecurityMinFDur",		"��ȫ�������Ƶ�ʳ���ʱ��",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_COPSTEP,				"CopStep",				"ͣ�˸��ʱ���������",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},

	{	PR_SYSTEM_MAXFLTDEV,			"MaxFltDev",			"�������豸����",					MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_SYSTEM_CUTLOADSTATENUM,		"CutLoadStateNum",		"�и���״̬��",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_SYSTEM_PLC,					"PLC",					"�и��ɸ���",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_EFLC,					"EFLC",					"�и���Ƶ��(��/��)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_EDLC,					"EDLC",					"�и��ɳ���ʱ��(Сʱ/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_ADLC,					"ADLC",					"ÿ���и��ɳ���ʱ��(Сʱ/��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_ELC,					"ELC",					"�����г�����ֵ(����/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_EENS,					"EENS",					"������������ֵ(����ʱ/��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_BPII,					"BPII",					"ϵͳͣ��ָ��(����/����.��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_BPECI,				"BPECI",				"ϵͳ��������ָ��(����ʱ/����.��)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_SI,					"SI",					"���س̶�ָ��(ϵͳ��/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOLP,					"LOLP",					"��������ʱ�����(��/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOLF,					"LOLF",					"��������Ƶ�ʸ���(��/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOLE,					"LOLE",					"������������ֵ(Сʱ/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_PLOS,					"PLOS",					"ʧ�ȸ���",							MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLOS,					"FLOS",					"ʧ��Ƶ��(��/��)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MTTIS,				"MTTIS",				"ƽ���ȶ�����ʱ��(Сʱ)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_MIEENS,				"MIslandEENS",			"�µ�������������ֵ(����ʱ/��)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_AGCEENS,				"LossGenEENS",			"ʧ�������������ֵ(����ʱ/��)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_ELEENS,				"ERlimitEENS",			"���޵�����������ֵ(����ʱ/��)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_NETWORKTYPE,			"NetworkType",			"��������",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRSystemNetworkTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRSystemNetworkTypeEnum,	},
	{	PR_SYSTEM_FLTGRADE0PROB,		"FltGrade0Prob",		"���¹�״̬����",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE1PROB,		"FltGrade1Prob",		"һ���¹ʸ���",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE2PROB,		"FltGrade2Prob",		"�ϴ��¹ʸ���",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE3PROB,		"FltGrade3Prob",		"�ش��¹ʸ���",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_FLTGRADE4PROB,		"FltGrade4Prob",		"�ر��ش��¹ʸ���",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_SYSTEM_LOADCURVEPACE,		"LoadCurvePace",		"��������ʱ����",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_SYSTEM_MAXMSDEVNUM,			"MaxMSDevNum",			"��״̬�豸��",						MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static tagMemDBField	g_PRRadFieldArray[]=
{
	{	PR_RADIAL_RINGBUS,				"RingBus",				"����(�����߽�)ĸ������",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_RADIAL_RINGKV,				"RingkV",				"����(�����߽�)ĸ�ߵ�ѹ(ǧ��)",	MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_RADIAL_LOADP,				"LoadP",				"�������ڸ���(����)",			MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_RADIAL_RINGBOUNDBUSPTR,		"RingBoundBusPtr",		"����(�����߽�)ĸ������",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRACBusFieldArray[]=
{
	{	PR_ACBUS_NAME,					"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACBUS_KV,					"kV",				"����ƽ����ѹ(ǧ��)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACBUS_ZONE,					"Zone",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_ACBUS_GENP,					"GenP",				"ĸ�߷����й�(����)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_GENQ,					"GenQ",				"ĸ�߷����޹�(�׷�)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_LOADP,					"LoadP",			"ĸ�߸����й�(����)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_LOADQ,					"LoadQ",			"ĸ�߸����޹�(�׷�)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RADP,					"RadP",				"��������Ч����(����)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_SHUNTQ,				"ShuntQ",			"ĸ�߲����޹�(�׷�)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RERR,					"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RREP,					"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_TREP,					"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADGENP,				"AdGenP",			"�����������(����)",				MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADLOADP,				"AdLoadP",			"���ɵ�����(����)",					MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADRADP,				"AdRadP",			"��������Ч���ɵ�����(����)",		MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_GOODPROB,				"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_FAILPROB,				"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_IRT,					"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_IMAX,					"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_IMIN,					"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RERRMAX,				"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_RERRMIN,				"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_FAULTFREQ,				"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_RTV,					"RtV",				"��ѹ������(ǧ��)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_PFD,					"PfD",				"���Ǽ�����(��)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_PLC,					"PLC",				"�и��ɸ���",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_EFLC,					"EFLC",				"�и���Ƶ��(��/��)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_EDLC,					"EDLC",				"�и��ɳ���ʱ��(Сʱ/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ADLC,					"ADLC",				"ÿ���и��ɳ���ʱ��(Сʱ/��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ELC,					"ELC",				"�����г�����ֵ(����/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_EENS,					"EENS",				"������������ֵ(����ʱ/��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_BPII,					"BPECI",			"ϵͳ��������ָ��(����ʱ/����.��)",	MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_BPECI,					"BPII",				"ϵͳͣ��ָ��(����/����.��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_SI,					"SI",				"���س̶�ָ��(ϵͳ��/��)",			MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_ISLAND,				"ACIsland",			"�����絺",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACBUS_UVOLMTFREQ,			"UVOLmtFreq",		"��ѹԽ���޴���(��)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_UFOLMTFREQ,			"UFOLmtFreq",		"Ƶ��Խ���޴���(��)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_DVOLMTFREQ,			"DVOLmtFreq",		"��ѹԽ���޴���(��)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_DFOLMTFREQ,			"DFOLmtFreq",		"Ƶ��Խ���޴���(��)",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_RADIAL,				"Radial",			"���������",						MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACBUS_SLACK,					"Slack",			"ƽ��ĸ�߱��",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_ACBUS_SRCBUS,				"SrcBus",			"��Դĸ�߱��",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_ACBUS_MIDBUS,				"MidBus",			"���Ե���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_ACBUS_GENPMAX,				"GenPMax",			"ĸ�����ӷ������������(����)",		MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_GENPMIN,				"GenPMin",			"ĸ�����ӷ������������(����)",		MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_LOADPMIN,				"LoadPMin",			"ĸ�����Ӹ��ɹ�������(����)",		MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACBUS_BUS2LINE,				"Bus2Line",			"ĸ����·ָ��",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_BUS2TRAN,				"Bus2Tran",			"ĸ�߱�ѹ��ָ��",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACBUS_ZONESERIALNO,			"ZoneIndex",		"ĸ�߷�������",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_RINGBOUND,				"RingBound",		"�����ڻ����߽�ĸ�߱��",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_LOADMSTATE,			"LoadMState",		"ĸ�߸��ɶ�״̬",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_DCBUS,					"DCBus",			"ֱ��ĸ�߱��",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACBUS_RPARAMTYPE,			"RParamType",		"�ɿ��Բ�������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},

	{	PR_ACBUS_OUTAGE,				"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRACLineFieldArray[]=
{
	{	PR_ACLINE_NAME,					"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_BUSI,					"BusI",				"��ڵ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_BUSJ,					"BusJ",				"�սڵ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_KVI,					"kVI",				"I���ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_KVJ,					"kVJ",				"J���ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PARID,				"ParlId",			"������·��",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_ACLINE_R,					"R",				"����(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_X,					"X",				"�翹(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_B,					"B",				"����(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RATED,				"Rated",			"�����(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_LENGTH,				"Length",			"����(ǧ��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_WEIGHTS,				"Weights",			"Խ��ָ��Ȩ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RERR,					"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RREP,					"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_TREP,					"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_GOODPROB,				"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_FAILPROB,				"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_IRT,					"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_IMAX,					"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_IMIN,					"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RERRMAX,				"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RERRMIN,				"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_FAULTFREQ,			"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_OLMTFREQ,				"OLmtFreq",			"Խ�޴���",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_OLMTVALUE,			"OLmtValue",		"Խ�޹���(����/��)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_ELMTCUTLOAD,			"ELmtCutLoad",		"�����и��ɵ���(����ʱ/��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACLINE_RTPI,					"RtPi",				"RT����й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RTQI,					"RtQi",				"RT����޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RTPZ,					"RtPz",				"RT�յ��й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_RTQZ,					"RtQz",				"RT�յ��޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_LOSSP,				"LossP",			"���(����)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFPI,					"PfPi",				"PF����й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFQI,					"PfQi",				"PF����޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFPZ,					"PfPz",				"PF�յ��й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_PFQZ,					"PfQz",				"PF�յ��޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRPI,					"TrPi",				"TR����й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRQI,					"TrQi",				"TR����޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRPZ,					"TrPz",				"TR�յ��й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_TRQZ,					"TrQz",				"TR�յ��޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_INIBUSI,				"IniBusI",			"Ini��ڵ�����",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_INIBUSJ,				"IniBusJ",			"Ini�սڵ�����",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINE_INIKVI,				"InikVI",			"Ini�����ѹ(ǧ��)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_INIKVJ,				"InikVJ",			"Ini�յ���ѹ(ǧ��)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINE_INILOOP,				"IniLoop",			"Ini������·��",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_ACLINE_BUSIPTR,				"BusIPtr",			"��ڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_BUSJPTR,				"BusJPtr",			"�սڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_RADIPTR,				"RadIPtr",			"��ڵ�������",					MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_RADJPTR,				"RadJPtr",			"�սڵ�������",					MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_SERIALNO,				"SerialNo",			"��·����",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACLINE_ISLAND,				"ACIsland",			"�����絺",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_RPARAMTYPE,			"RParamType",		"�ɿ��Բ�������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_ACLINE_OUTAGE,				"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACLINE_TRMISLAND,			"TrMIsland",		"N-1�ൺ",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ACLINE_TRFACTORNUM,			"TrFactorNum",		"һ����ؿ��Ϸֲ����Ӹ���",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PR_ACLINE_TCSCPTR,				"TCSCPtr",			"TCSC����",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_ACLINE_UPFCPTR,				"UPFCPtr",			"UPFC����",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static tagMemDBField	g_PRWindFieldArray[]=
{
	{	PR_WIND_NAME,				"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_BUSI,				"BusI",				"��ڵ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_BUSJ,				"BusJ",				"�սڵ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_KVI,				"kVI",				"I���ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_KVJ,				"kVJ",				"J���ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PARID,				"ParlId",			"������·��",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_WIND_R,					"R",				"����(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_X,					"X",				"�翹(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RATED,				"Rated",			"�����(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_WEIGHTS,			"Weights",			"Խ��ָ��Ȩ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RERR,				"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RREP,				"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_TREP,				"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_GOODPROB,			"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_FAILPROB,			"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_IRT,				"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_IMAX,				"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_IMIN,				"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RERRMAX,			"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RERRMIN,			"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_FAULTFREQ,			"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_OLMTFREQ,			"OLmtFreq",			"Խ�޴���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_OLMTVALUE,			"OLmtValue",		"Խ�޹���(����/��)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_ELMTCUTLOAD,		"ELmtCutLoad",		"�����и��ɵ���(����ʱ/��)",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_WIND_RTPI,				"RtPi",				"RT����й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RTQI,				"RtQi",				"RT����޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RTPZ,				"RtPz",				"RT�յ��й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_RTQZ,				"RtQz",				"RT�յ��޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_LOSSP,				"LossP",			"���(����)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFPI,				"PfPi",				"PF����й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFQI,				"PfQi",				"PF����޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFPZ,				"PfPz",				"PF�յ��й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_PFQZ,				"PfQz",				"PF�յ��޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRPI,				"TrPi",				"TR����й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRQI,				"TrQi",				"TR����޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRPZ,				"TrPz",				"TR�յ��й�(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_TRQZ,				"TrQz",				"TR�յ��޹�(�׷�)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_INIBUSI,			"IniBusI",			"Ini��ڵ�����",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_INIBUSJ,			"IniBusJ",			"Ini�սڵ�����",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WIND_INIKVI,				"InikVI",			"Ini�����ѹ(ǧ��)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_INIKVJ,				"InikVJ",			"Ini�յ���ѹ(ǧ��)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WIND_INILOOP,			"IniLoop",			"Ini������·��",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_WIND_BUSIPTR,			"BusIPtr",			"��ڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_BUSJPTR,			"BusJPtr",			"�սڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_RADIPTR,			"RadIPtr",			"��ڵ�������",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_WIND_RADJPTR,			"RadJPtr",			"�սڵ�������",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_WIND_SERIALNO,			"SerialNo",			"��ѹ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_WIND_ISLAND,				"ACIsland",			"�����絺",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_WIND_GENTRAN,			"GenTran",			"�������ѹ����",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_WIND_RPARAMTYPE,			"RParamType",		"�ɿ��Բ�������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_WIND_OUTAGE,				"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_WIND_TRMISLAND,			"TrMIsland",		"N-1�ൺ",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_WIND_TRFACTORNUM,		"TrFactorNum",		"һ����ؿ��Ϸֲ����Ӹ���",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRGeneratorFieldArray[]=
{
	{	PR_GENERATOR_NAME,			"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_GENERATOR_BUSNAME,		"BusName",			"ĸ��",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_GENERATOR_BUSKV,			"BuskV",			"��ѹ(ǧ��)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_GENID,			"GenId",			"���",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_GENERATOR_ZONE,			"Zone",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_GENERATOR_P,				"P",				"�й�(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_Q,				"Q",				"�޹�(�׷�)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_PMAX,			"PMax",				"����й�(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_PMIN,			"PMin",				"��С�й�(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_QMAX,			"QMax",				"����޹�(�׷�)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_QMIN,			"QMin",				"��С�޹�(�׷�)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_RERR,			"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_RREP,			"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_TREP,			"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_GOODPROB,		"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_FAILPROB,		"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_IRT,			"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_IMAX,			"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_IMIN,			"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_RERRMAX,		"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_RERRMIN,		"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_MSMODEL,		"MSModel",			"��״̬ģ��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_GENERATOR_MSTATENUM,		"MStateNum"	,		"��״̬״̬��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_GENERATOR_MSPOUT,		"MSPout",			"��״̬״̬",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_GENERATOR_REFP,			"ReferenceP",		"�����й�(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_REFQ,			"ReferenceQ",		"�����޹�(�׷�)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_GENERATOR_FAULTFREQ,		"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_GENERATOR_EQGEN,			"EQGen",			"��ֵ��Դ���",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_GENERATOR_RADIAL,		"Radial",			"���������",						MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_GENERATOR_BUSPTR,		"BusPtr",			"ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_GENERATOR_RPARAMTYPE,	"RParamType",		"�ɿ��Բ�������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_GENERATOR_OUTAGE,		"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRPowerLoadFieldArray[]=
{
	{	PR_POWERLOAD_NAME,			"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_POWERLOAD_BUSNAME,		"BusName",			"ĸ��",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_POWERLOAD_BUSKV,			"BuskV",			"��ѹ(ǧ��)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_ZONE,			"Zone",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_POWERLOAD_P,				"P",				"�й�(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_Q,				"Q",				"�޹�(�׷�)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_PMAX,			"PMax",				"����й�(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_RERR,			"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_RREP,			"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_TREP,			"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_GOODPROB,		"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_FAILPROB,		"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_IRT,			"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_IMAX,			"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_IMIN,			"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_RERRMAX,		"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_RERRMIN,		"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_FAULTFREQ,		"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_POWERLOAD_MSMODEL,		"MSModel"	,		"��״̬ģ��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_POWERLOAD_MSTATENUM,		"MStateNum"	,		"��״̬״̬��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_POWERLOAD_MSPOUT,		"MSPout",			"��״̬����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_POWERLOAD_REFP,			"ReferenceP",		"�����й�(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_REFQ,			"ReferenceQ",		"�����޹�(�׷�)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_POWERLOAD_RADIAL,		"Radial",			"���������",						MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_POWERLOAD_BUSPTR,		"BusPtr",			"ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_POWERLOAD_AUXLOAD,		"AuxLoad",			"���õ���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_POWERLOAD_EQLOAD,		"EQLoad",			"��ֵ���ɱ��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_POWERLOAD_RPARAMTYPE,	"RParamType",		"�ɿ��Բ�������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_POWERLOAD_OUTAGE,		"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRHVDCFieldArray[]=
{
	{	PR_HVDC_NAME,			"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_ACBUSR,			"ACBusR",			"���������ڵ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_ACBUSI,			"ACBusI",			"��佻���ڵ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_KVR,			"kVR",				"�������ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_KVI,			"kVI",				"�����ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_R,				"R",				"����(ŷķ)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_L,				"L",				"���(����)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_C,				"C",				"����(΢��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_CON,			"Con",				"���Ʋ�R/I",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	PR_HVDC_RATEDC,			"RatedC",			"�����(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_RECTV,			"RectV",			"������ֱ����ѹ(ǧ��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_RATEDP,			"RatedP",			"�����(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_LENGTH,			"Length",			"����(ǧ��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_POWER,			"Power",			"���ŵ�ֱ������(����)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_PWRR,			"PwrR",				"�����๦��(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_PWRI,			"PwrI",				"���๦��(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_LOSSP,			"LossP",			"���(����)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_RERR,			"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_RREP,			"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_TREP,			"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_GOODPROB,		"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_FAILPROB,		"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_IRT,			"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_IMAX,			"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_IMIN,			"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_RERRMAX,		"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_RERRMIN,		"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_FAULTFREQ,		"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_MSMODEL,		"MSModel",			"��״̬ģ��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),				g_PREnumNoYes,				},
	{	PR_HVDC_MSTATENUM,		"MStateNum"		,	"��״̬״̬��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_HVDC_MSPOUT,			"MSPout",			"��״̬����״̬",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_HVDC_INIBUSR,		"IniBusR",			"Ini�����ڵ�����",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_INIBUSI,		"IniBusI",			"Ini���ڵ�����",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_HVDC_INIPWRR,		"IniPwrR",			"Ini�����๦��(����)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_INIPWRI,		"IniPwrI",			"Ini���๦��(����)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_HVDC_ACBUSRPTR,		"ACBusRPtr",		"�����ڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_ACBUSIPTR,		"ACBusIPtr",		"���ڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_ISLANDR,		"ACIslandR",		"�����ཻ���絺",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_HVDC_ISLANDI,		"ACIslandI",		"���ཻ���絺",					MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_HVDC_SERIALNO,		"SerialNo",			"ֱ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_HVDC_RPARAMTYPE,		"RParamType",		"�ɿ��Բ�������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRDeviceRParamTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRDeviceRParamTypeEnum,	},
	{	PR_HVDC_OUTAGE,			"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRConverterFieldArray[]=
{
	{	PR_CONVERTER_NAME,				"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_CONVERTER_BUSAC,				"BusAC",			"�����ڵ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_CONVERTER_BUSDC,				"BusDC",			"ֱ���ڵ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_CONVERTER_SCHEDPOWER,		"SchedPower",		"���ŵĹ���(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_CONVERTER_TYPE,				"Type",				"�任������",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRConverterTypeEnum)/sizeof(tagMemDBEnumPair),		g_PRConverterTypeEnum,		},
	{	PR_CONVERTER_RERR,				"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_RREP,				"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_TREP,				"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_GOODPROB,			"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_FAILPROB,			"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_IRT,				"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_IMAX,				"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_IMIN,				"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_RERRMAX,			"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_RERRMIN,			"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_CONVERTER_FAULTFREQ,			"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CONVERTER_ACBUSPTR,			"ACBusPtr",			"�����ڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CONVERTER_DCBUSPTR,			"DCBusPtr",			"ֱ���ڵ�����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CONVERTER_OUTAGE,			"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRDCBusFieldArray[]=
{
	{	PR_DCBUS_NAME,					"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static tagMemDBField	g_PRDCLineFieldArray[]=
{
	{	PR_DCLINE_NAME,					"Name",				"����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DCLINE_DCBUSI,				"DCBusI",			"I��ֱ���ڵ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DCLINE_DCBUSJ,				"DCBusJ",			"J��ֱ���ڵ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DCLINE_LENGTH,				"Length",			"����(ǧ��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_DCLINE_RERR,					"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_RREP,					"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_TREP,					"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_GOODPROB,				"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_FAILPROB,				"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_IRT,					"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_IMAX,					"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_IMIN,					"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_RERRMAX,				"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_RERRMIN,				"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DCLINE_FAULTFREQ,			"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_DCLINE_DCBUSIPTR,			"DCBusIPtr",		"I��ֱ���ڵ�����",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_DCLINE_DCBUSJPTR,			"DCBusJPtr",		"J��ֱ���ڵ�����",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_DCLINE_OUTAGE,				"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRTCSCFieldArray[]=
{
	{	PR_TCSC_NAME,					"Name",				"������·����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_TCSC_INSTBUS,				"InstallBus",		"��װĸ����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_TCSC_X,						"X",				"�����翹ֵ(����)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_TCSC_RERR,					"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_RREP,					"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_TREP,					"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_GOODPROB,				"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_FAILPROB,				"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_IRT,					"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_IMAX,					"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_IMIN,					"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_RERRMAX,				"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_RERRMIN,				"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_TCSC_FAULTFREQ,				"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TCSC_INSTBUSPTR,				"InstBusPtr",		"��װĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TCSC_ACLINEPTR,				"ACLinePtr",		"������·����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TCSC_OUTAGE,					"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRUPFCFieldArray[]=
{
	{	PR_UPFC_NAME,					"Name",				"������·����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_UPFC_SERIESBUS,				"SeriesBus",		"����ĸ����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_UPFC_PARALLELBUS,			"ParallelBus",		"����ĸ����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_UPFC_CAPACITY,				"Capacity",			"����(�׷���)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_UPFC_RERR,					"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_RREP,					"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_TREP,					"Trep",				"�޸�ʱ��(Сʱ/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_GOODPROB,				"GoodProb",			"��ø���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_FAILPROB,				"FailProb",			"���ϸ���",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_IRT,					"IRt",				"ʵ��ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_IMAX,					"IMax",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_IMIN,					"IMin",				"����ֵ",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_RERRMAX,				"RerrMax",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_RERRMIN,				"RerrMin",			"����������ֵ",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_LINEPSE,				"LinePse",			"������ע�빦��(����)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_UPFC_P,						"P",				"��������ƹ���(����)",				MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_UPFC_FAULTFREQ,				"FaultFreq",		"���ϴ���(��)",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_SERIESBUSPTR,			"SeriesBusPtr",		"����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_PARALLELBUSPTR,			"ParallelBusPtr",	"����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_ACLINEPTR,				"ACLinePtr",		"������·����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_UPFC_OUTAGE,					"Outage",			"ͣ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

// static tagMemDBField	g_PRDevMStateFieldArray[]=
// {
// 	{	PR_DEVMSTATE_TYPE,				"Type",				"�豸����",							MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),		0,	NULL,	},
// 	{	PR_DEVMSTATE_NAME,				"Name",				"�豸����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
// 	{	PR_DEVMSTATE_STATERATE,			"StateRate",		"״̬����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEPROB,			"StateProb",		"״̬����",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ1,		"StateFreq1",		"ID-1״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ2,		"StateFreq2",		"ID-2״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ3,		"StateFreq3",		"ID-3״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ4,		"StateFreq4",		"ID-4״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ5,		"StateFreq5",		"ID-5״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ6,		"StateFreq6",		"ID-6״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ7,		"StateFreq7",		"ID-7״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_STATEFREQ8,		"StateFreq8",		"ID-8״̬ת����(��/��)",			MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
// 	{	PR_DEVMSTATE_SERIALNO,				"SerialNo",			"�豸����",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
// };

static tagMemDBField	g_PRDevMStateFieldArray[]=
{
	{	PR_DEVMSTATE_TYPE,				"Type",				"�豸����",							MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_DEVMSTATE_NAME,				"Name",				"�豸����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_DEVMSTATE_STATENUM,			"StateNum",			"״̬��",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_DEVMSTATE_STATE1RATE,		"State1Rate",		"״̬1����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2RATE,		"State2Rate",		"״̬2����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3RATE,		"State3Rate",		"״̬3����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4RATE,		"State4Rate",		"״̬4����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5RATE,		"State5Rate",		"״̬5����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6RATE,		"State6Rate",		"״̬6����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7RATE,		"State7Rate",		"״̬7����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8RATE,		"State8Rate",		"״̬8����(����)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1PROB,		"State1Prob",		"״̬1����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2PROB,		"State2Prob",		"״̬2����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3PROB,		"State3Prob",		"״̬3����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4PROB,		"State4Prob",		"״̬4����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5PROB,		"State5Prob",		"״̬5����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6PROB,		"State6Prob",		"״̬6����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7PROB,		"State7Prob",		"״̬7����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8PROB,		"State8Prob",		"״̬8����",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ1,		"State1Freq1",		"״̬1-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ2,		"State1Freq2",		"״̬1-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ3,		"State1Freq3",		"״̬1-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ4,		"State1Freq4",		"״̬1-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ5,		"State1Freq5",		"״̬1-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ6,		"State1Freq6",		"״̬1-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ7,		"State1Freq7",		"״̬1-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE1FREQ8,		"State1Freq8",		"״̬1-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ1,		"State2Freq1",		"״̬2-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ2,		"State2Freq2",		"״̬2-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ3,		"State2Freq3",		"״̬2-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ4,		"State2Freq4",		"״̬2-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ5,		"State2Freq5",		"״̬2-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ6,		"State2Freq6",		"״̬2-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ7,		"State2Freq7",		"״̬2-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE2FREQ8,		"State2Freq8",		"״̬2-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ1,		"State3Freq1",		"״̬3-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ2,		"State3Freq2",		"״̬3-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ3,		"State3Freq3",		"״̬3-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ4,		"State3Freq4",		"״̬3-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ5,		"State3Freq5",		"״̬3-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ6,		"State3Freq6",		"״̬3-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ7,		"State3Freq7",		"״̬3-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE3FREQ8,		"State3Freq8",		"״̬3-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ1,		"State4Freq1",		"״̬4-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ2,		"State4Freq2",		"״̬4-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ3,		"State4Freq3",		"״̬4-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ4,		"State4Freq4",		"״̬4-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ5,		"State4Freq5",		"״̬4-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ6,		"State4Freq6",		"״̬4-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ7,		"State4Freq7",		"״̬4-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE4FREQ8,		"State4Freq8",		"״̬4-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ1,		"State5Freq1",		"״̬5-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ2,		"State5Freq2",		"״̬5-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ3,		"State5Freq3",		"״̬5-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ4,		"State5Freq4",		"״̬5-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ5,		"State5Freq5",		"״̬5-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ6,		"State5Freq6",		"״̬5-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ7,		"State5Freq7",		"״̬5-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE5FREQ8,		"State5Freq8",		"״̬5-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ1,		"State6Freq1",		"״̬6-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ2,		"State6Freq2",		"״̬6-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ3,		"State6Freq3",		"״̬6-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ4,		"State6Freq4",		"״̬6-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ5,		"State6Freq5",		"״̬6-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ6,		"State6Freq6",		"״̬6-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ7,		"State6Freq7",		"״̬6-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE6FREQ8,		"State6Freq8",		"״̬6-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ1,		"State7Freq1",		"״̬7-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ2,		"State7Freq2",		"״̬7-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ3,		"State7Freq3",		"״̬7-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ4,		"State7Freq4",		"״̬7-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ5,		"State7Freq5",		"״̬7-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ6,		"State7Freq6",		"״̬7-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ7,		"State7Freq7",		"״̬7-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE7FREQ8,		"State7Freq8",		"״̬7-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ1,		"State8Freq1",		"״̬8-1ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ2,		"State8Freq2",		"״̬8-2ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ3,		"State8Freq3",		"״̬8-3ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ4,		"State8Freq4",		"״̬8-4ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ5,		"State8Freq5",		"״̬8-5ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ6,		"State8Freq6",		"״̬8-6ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ7,		"State8Freq7",		"״̬8-7ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_STATE8FREQ8,		"State8Freq8",		"״̬8-8ת����(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_DEVMSTATE_SERIALNO,			"SerialNo",			"�豸����",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static tagMemDBField	g_PRLoadCurveFieldArray[]=
{
	{	PR_LOADCURVE_BUS,				"BusName",			"ĸ������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_LOADCURVE_ID,				"ID",				"���ߵ���",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},

	{	PR_LOADCURVE_VALDAY,			"ValDay",			"���ߵ���ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALAVER,			"ValAver",			"���ߵ��ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALMAX,			"ValMax",			"���ߵ��ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALMIN,			"ValMin",			"���ߵ�Сֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PR_LOADCURVE_VALUE01,			"Value01",			"���ߵ�01ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE02,			"Value02",			"���ߵ�02ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE03,			"Value03",			"���ߵ�03ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE04,			"Value04",			"���ߵ�04ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE05,			"Value05",			"���ߵ�05ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE06,			"Value06",			"���ߵ�06ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE07,			"Value07",			"���ߵ�07ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE08,			"Value08",			"���ߵ�08ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE09,			"Value09",			"���ߵ�09ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE10,			"Value10",			"���ߵ�10ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE11,			"Value11",			"���ߵ�11ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE12,			"Value12",			"���ߵ�12ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE13,			"Value13",			"���ߵ�13ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE14,			"Value14",			"���ߵ�14ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE15,			"Value15",			"���ߵ�15ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE16,			"Value16",			"���ߵ�16ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE17,			"Value17",			"���ߵ�17ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE18,			"Value18",			"���ߵ�18ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE19,			"Value19",			"���ߵ�19ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE20,			"Value20",			"���ߵ�20ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE21,			"Value21",			"���ߵ�21ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE22,			"Value22",			"���ߵ�22ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE23,			"Value23",			"���ߵ�23ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_LOADCURVE_VALUE24,			"Value24",			"���ߵ�24ֵ(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRACIslandFieldArray[]=
{
	{	PR_ACISLAND_GENP,				"GenP",				"������(����)",						MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACISLAND_LOADP,				"LoadP",			"������(����)",						MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACISLAND_HVDCP,				"HVDCP",			"ֱ������(����)",					MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_ACISLAND_BUSNUM,				"BusNum",			"����ĸ����",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACISLAND_SWINGBUS,			"SwingBus",			"ƽ��ڵ�",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ACISLAND_DEAD,				"Dead",				"����",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRZoneFieldArray[]=
{
	{	PR_ZONE_NAME,					"Name",				"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PR_ZONE_AREA,					"Area",				"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PR_ZONE_TOTGENP,				"TotalGenP",		"��������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ZONE_TOTLOADP,				"TotalLoadP",		"��������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ZONE_CUTLOADP,				"FCutLoadP",		"�����¹��и���(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRACLineEdgeFieldArray[]=
{
	{	PR_ACLINEEDGE_BUS,				"Bus",				"ĸ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINEEDGE_KV,				"kV",				"ĸ�ߵ�ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_ACLINEEDGE_NAME,				"Name",				"��·����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_ACLINEEDGE_LINEPTR,			"LinePtr",			"��·����",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRWindEdgeFieldArray[]=
{
	{	PR_WINDEDGE_BUS,				"Bus",				"ĸ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WINDEDGE_KV,					"kV",				"ĸ�ߵ�ѹ(ǧ��)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_WINDEDGE_NAME,				"Name",				"��ѹ������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	PR_WINDEDGE_TRANPTR,			"TranPtr",			"��ѹ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRLDFactorFieldArray[]=
{
	{	PR_LDFACTOR_LINEIDX,			"LineIdx",			"��ѹ������",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_LDFACTOR_BUSIDX,				"BusIdx",			"ĸ������",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_LDFACTOR_DFACTOR,			"DFactor",			"�ֲ�����",							MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRTDFactorFieldArray[]=
{
	{	PR_TDFACTOR_TRANIDX,			"LineIdx",			"��ѹ������",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TDFACTOR_BUSIDX,				"BusIdx",			"ĸ������",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TDFACTOR_DFACTOR,			"DFactor",			"�ֲ�����",							MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRCommRParamFieldArray[]=
{
	{	PR_COMMPARAM_DEVTYPE,			"DevType",			"�豸����",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_COMMPARAM_KEYWORD,			"KeyWord",			"�ؼ���",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PR_COMMPARAM_UPCAPLMT,			"UpCapLmt",			"��������",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_DNCAPLMT,			"DnCapLmt",			"��������",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_UPVLMT,			"UpVLmt",			"��ѹ����",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_DNVLMT,			"DnVLmt",			"��ѹ����",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_RERR,				"Rerr",				"������",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COMMPARAM_TREP,				"Trep",				"�޸�ʱ��",							MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRManualFaultFieldArray[]=
{
	{	PR_MANUALFAULT_NAME,			"Name",				"�����¼�����(Id)",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_MANUALFAULT_FDEVTYPE,		"FDevType",			"�����豸����",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_MANUALFAULT_FDEVNAME,		"FDevName",			"�����豸����",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_MANUALFAULT_FDEVSERNO,		"FDevSerno",		"�����豸����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_MANUALFAULT_PROC,			"Proc",				"���״̬",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRCommonFaultFieldArray[]=
{
	{	PR_COMMONFAULT_NAME,			"Name",				"�����������(Id)",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_COMMONFAULT_COMMFAULTTYPE,	"CommonFaultType",	"�����������",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRCommonFaultTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRCommonFaultTypeEnum,	},
	{	PR_COMMONFAULT_DEVICECOMMTYPE,	"CommonDeviceType",	"�����豸����",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRCommonDeviceTypeEnum)/sizeof(tagMemDBEnumPair),	g_PRCommonDeviceTypeEnum,	},
	{	PR_COMMONFAULT_DEVTYPE,			"DevType",			"�豸����",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_COMMONFAULT_DEVNAME,			"DevName",			"�豸����",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_COMMONFAULT_DEVSERNO,		"DevSerNo",			"�豸����",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_COMMONFAULT_PROC,			"Proc",				"���״̬",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PR2StateCompFieldArray[]=
{
	{	PR_R2STATECOMP_TYPE,			"Type",				"����",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_R2STATECOMP_SERIALNO,		"SerialNo",			"�豸����",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRMStateCompFieldArray[]=
{
	{	PR_RMSTATECOMP_TYPE,			"Type",				"����",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_RMSTATECOMP_SERIALNO,		"SerialNo",			"�豸����",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRTripFieldArray[]=
{
	{	PR_TRIP_DEVNUM,					"TripDevNum",		"�����豸��",						MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_TRIP_TRB1TYP,				"TrB1Type",			"�����豸1����",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_TRIP_TRB1IDX,				"TrB1Bran",			"�����豸1����",					MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIP_TRB2TYP,				"TrB2Type",			"�����豸2����",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_TRIP_TRB2IDX,				"TrB2Bran",			"�����豸2����",					MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIP_FAULTTYPE,				"FaultType",		"��������",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFModeFaultTypeEnum)/sizeof(tagMemDBEnumPair),		g_PRFModeFaultTypeEnum,		},
	{	PR_TRIP_OUTLOADP,				"OutageLoadP",		"ʧ���ܸ���",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_TRIP_OVERLMT,				"OverLmt",			"�Ƿ�Խ��",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRTripMIslandFieldArray[]=
{
	{	PR_TRIPMISLAND_TRIP,			"Trip",				"���Ϲ�������",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPMISLAND_OUTAGEBUS,		"OutageBus",		"�µ�ĸ��",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPMISLAND_OUTAGELOADP,		"OutageLoadP",		"�µ����ɹ���(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRTripOvlDevFieldArray[]=
{
	{	PR_TRIPOVLDEV_TRIP,				"Trip",				"���Ϲ�������",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPOVLDEV_TYPE,				"OvlmtDevTyp",		"Խ���豸����",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_TRIPOVLDEV_SERIALNO,			"OvlmtDevIdx",		"Խ���豸����",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_TRIPOVLDEV_OVLVAL,			"OvLmtValue",		"Խ��ֵ(����)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_TRIPOVLDEV_RATED,			"Rated",			"�ֵ(����)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

// static tagMemDBField	g_PRMCSampleStateFieldArray[]=
// {
// 	{	PR_MCSAMPLESTATE_FSTATENO,		"FState",			"״̬����",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
// 	{	PR_MCSAMPLESTATE_CUTLOAD,		"OutLoad",			"��ʧ����״̬",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
// 	{	PR_MCSAMPLESTATE_MSTATE,		"MState",			"��״̬����",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
// };

static tagMemDBField	g_PRFStateFieldArray[]=
{
	{	PR_FSTATE_ID,					"FStateID",			"״̬ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATE_SAMPLETYPE,			"SampleType",		"�����㷨",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateSampleMethodEnum)/sizeof(tagMemDBEnumPair),	g_PRFStateSampleMethodEnum,	},
	{	PR_FSTATE_FDEVNUM,				"FDevNum",			"�����豸��",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATE_PROBABILITY,			"Probability",		"״̬����",							MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_FSTATE_DURITION,				"Durition",			"����ʱ��",							MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_FSTATE_STATENUM,				"StateNum",			"״̬���ִ���",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATE_FLOSSGEN,				"FLossGen",			"������ʧ���������(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_FLOSSGENCAP,			"FLossGenCap",		"������ʧ���������(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_FLOSSLOAD,			"FLossLoad",		"������ʧ���ɹ���(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_MISLAND,				"MIsland",			"�γɶൺ",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),					g_PREnumNoYes,				},
	{	PR_FSTATE_MIINSGEN,				"MIslandInsGen",	"�µ����ӳ���(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_MICUTGEN,				"MIslandCutGen",	"�µ����ٳ���(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_MICUTLOAD,			"MIslandOutLoad",	"�µ���ʧ����(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_AGCINSGEN,			"BalanceInsGen",	"����ƽ�ⷢ���������(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_AGCCUTGEN,			"BalanceCutGen",	"����ƽ�ⷢ���������(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_AGCCUTLOAD,			"BalanceCutLoad",	"����ƽ����ʧ����(����)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_OVERLIMIT,			"OverLimit",		"�豸Խ��",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),					g_PREnumNoYes,				},
	{	PR_FSTATE_ELIMIT,				"ELimit",			"�����и���",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PREnumNoYes)/sizeof(tagMemDBEnumPair),					g_PREnumNoYes,				},
	{	PR_FSTATE_ELCUTGEN,				"ELimitCutGen",		"���޼��ٳ���(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_ELINSGEN,				"ELimitInsGen",		"�������ӳ���(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_ELCUTLOAD,			"ELimitCutLoad",	"������ʧ����(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_ELRESULT,				"ELimitResult",		"��ԣ���������޽��",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateAdResultEnum)/sizeof(tagMemDBEnumPair),		g_PRFStateAdResultEnum,		},
	{	PR_FSTATE_MAXFAULTZONE,			"MaxFaultZone",		"��󸺺���ʧ��������",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATE_MAXFAULTRATIO,		"MaxFaultRatio",	"��󸺺���ʧ����ռ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATE_FAULTGRADE,			"FaultGrade",		"�¹ʵȼ�",							MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateFaultGradeEnum)/sizeof(tagMemDBEnumPair),			g_PRFStateFaultGradeEnum,		},
	{	PR_FSTATE_MSOUTSERIALNO,		"MSoutIndex",		"��״̬ģ�͹���״̬����",			MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PR_FSTATE_ESTIMATED,			"Estimated",		"����״̬",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATE_ELAPSETIME,			"ElapseTime",		"����ʱ��",							MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateFDevFieldArray[]=
{
	{	PR_FSTATEFDEV_FSTATEID,			"FStateId",			"״̬ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEFDEV_FSTATENO,			"FStateNo",			"״̬���",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEFDEV_FDEVTYP,			"FDevTyp",			"�����豸����",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEFDEV_FDEVIDX,			"FDevIdx",			"�����豸����",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEFDEV_DFLTPOS,			"DFltPos",			"�豸����λ��",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEFDEV_DFLTTYP,			"DFltTyp",			"�豸��������",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFStateFaultTypeEnum)/sizeof(tagMemDBEnumPair),		g_PRFStateFaultTypeEnum,	},
};

static tagMemDBField	g_PRMStateFieldArray[]=
{
	{	PR_FSTATEMSTATE_MSDEVTYPE,		"MSDevType",		"��״̬�豸����",					MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEMSTATE_MSDEVIDX,		"MSDevIndex",		"��״̬�豸����",					MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMSTATE_MSTATEPOUT,		"MStatePout",		"��״̬����״̬",					MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateMIslandFieldArray[]=
{
	{	PR_FSTATEMISLAND_FSTATEID,		"FStateId",			"״̬ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMISLAND_FSTATENO,		"FStateNo",			"״̬���",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMISLAND_OUTAGEBUS,		"OutageBus",		"�µ�ĸ��",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEMISLAND_OUTAGELOADP,	"OutageLoadP",		"�µ����ɹ���(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateOvlDevFieldArray[]=
{
	{	PR_FSTATEOVLDEV_FSTATEID,		"FStateId",			"״̬ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_FSTATENO,		"FStateNo",			"״̬���",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_DEVTYP,			"DevTyp",			"Խ���豸����",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEOVLDEV_DEVIDX,			"DevIdx",			"Խ���豸����",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_OVLMTP,			"OvLmtP",			"Խ��ֵ(����)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_RATED,			"Rated",			"�ֵ(����)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSTATEOVLDEV_ADLMTP,			"AdLmtP",			"����ֵ(����)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRFStateOvlAdFieldArray[]=
{
	{	PR_FSTATEOVLAD_FSTATEID,		"FStateId",			"״̬ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_FSTATENO,		"FStateNo",			"״̬���",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_OVLDEVTYP,		"OvlDevTyp",		"Խ���豸����",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEOVLAD_OVLDEVICE,		"OvlDevice",		"Խ���豸����",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_ADJDEVTYP,		"AdjDevTyp",		"�����豸����",						MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSTATEOVLAD_ADJDEVICE,		"AdjDevice",		"�����豸����",						MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSTATEOVLAD_ADJVALUE,		"AdjValue",			"���ʵ�����(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRAdsNodeFieldArray[]=
{
	{	PR_ADSNODE_ID,					"Id",				"�ڵ�ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_ADSNODE_NAME,				"Name",				"�ڵ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_ADSNODE_STATUS,				"Status",			"�ڵ�״̬(0�˳���1����)",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_ADSNODE_TASKCOUNT,			"TaskCount",		"�ۻ�ִ���������",					MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcJobTypeFieldArray[]=
{
	{	PR_CALCJOBTYPE_ID,				"Id",				"��������ID",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOBTYPE_NAME,			"Name",				"������������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOBTYPE_DESP,			"Desp",				"������������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOBTYPE_NODEID,			"NodeId",			"����ڵ�",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcJobFieldArray[]=
{
	{	PR_CALCJOB_ID,					"Id",				"����ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_TYPEID,				"TypeId",			"��������ID",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_NAME,				"Name",				"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOB_DESP,				"Desp",				"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOB_CONFIG,				"Config",			"������Ϣ",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCJOB_INITIME,				"IniTime",			"��ʼʱ��",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_ENDTIME,				"EndTime",			"����ʱ��",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCJOB_ELAPSETIME,			"ElapseTime",		"��ʱ",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcTaskFieldArray[]=
{
	{	PR_CALCTASK_ID,					"Id",				"����ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_JOBID,				"JobId",			"��������ID",						MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_CONTENT,			"Content",			"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCTASK_INITIME,			"IniTime",			"��ʼʱ��",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_ENDTIME,			"EndTime",			"����ʱ��",							MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCTASK_ELAPSETIME,			"ElapseTime",		"��ʱ",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static tagMemDBField	g_PRCalcFileFieldArray[]=
{
	{	PR_CALCFILE_JOBID,				"JobId",			"����ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_CALCFILE_NAME,				"Name",				"�ļ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PR_CALCFILE_TYPE,				"Type",				"�ļ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	PR_CALCFILE_CONTENT,			"Content",			"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
};

static tagMemDBField	g_PRFSecurityFieldArray[]=
{
	{	PR_FSECURITY_FSTATEID,			"FStateId",			"״̬ID",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSECURITY_FSTATENO,			"FStateNo",			"״̬���",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_FSECURITY_LTFAULT,			"LTFault",			"֧·����",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSECURITY_MISLAND,			"MIsland",			"�ൺ����",							MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PR_FSECURITY_LOSSGENP,			"LossGenP",			"���������ʧ(����)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PR_FSECURITY_BSEFILE,			"BseFile",			"Bse�ļ���",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_FSECURITY_SWIFILE,			"SwiFile",			"Swi�ļ���",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_FSECURITY_OUTFILE,			"OutFile",			"Out�ļ���",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PR_FSECURITY_RESULT,			"Result",			"��ȫ���������",					MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	sizeof(g_PRFSecurityResultEnum)/sizeof(tagMemDBEnumPair),	g_PRFSecurityResultEnum,		},
	{	PR_FSECURITY_ESTIMATED,			"Estimated",		"�������λ",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRCopGenFieldArray[]=
{
	{	PR_COPGEN_SERIALNO,				"SerialNo",			"�豸����",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_COPGEN_CAPACITY,				"Capacity",			"���������(����)",					MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_ALPHA,				"Alpha",			"����ϵ��",							MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_S1CAPACITY,			"S1Capacity",		"�������������1(����)",			MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_S2CAPACITY,			"S2Capacity",		"�������������2(����)",			MDBFieldCategoryBase,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_RERR,					"Rerr",				"������(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_TREP,					"Trep",				"�޸�ʱ��(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_RREP,					"Rrep",				"�޸���(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_ROUT,					"Rout",				"ͣ����(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPGEN_3STATE,				"ThreeState",		"��״̬",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
};

static tagMemDBField	g_PRCopTableFieldArray[]=
{
	{	PR_COPTABLE_STATE,				"State",			"״̬",								MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PR_COPTABLE_OUTAGECAPACITY,		"OutageCapacity",	"ͣ�˷�������(����)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_AVAILCAPACITY,		"AvailCapacity",	"���÷�������(����)",				MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_STATEPROB,			"StateProb",		"״̬����",							MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_ACCUMPROB,			"AccumProb",		"״̬�ۼƸ���",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_STATEFREQ,			"StateFreq",		"״̬Ƶ��(��)",						MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_ACCUMFREQ,			"AccumFreq",		"״̬�ۼ�Ƶ��(��)",					MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_DEPRP,				"DepRP",			"������Ч��ȥ��",					MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	PR_COPTABLE_DEPRN,				"DepRN",			"�ݼ���Ч��ȥ��",					MDBFieldCategoryAid,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
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

