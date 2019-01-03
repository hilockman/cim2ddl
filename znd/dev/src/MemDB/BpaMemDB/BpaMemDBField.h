#pragma	once

#include	"BpaMemDBDefine.h"

#if	defined(__GNUG__)	||	defined(__GNUC__)	//	GCC������Ԥ����ĺ�
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
	{	0,		"��",	},
	{	1,		"��",	},
};

static	tagMemDBEnumPair	g_BpaEnumYesNo[]=
{
	{	0,		"��",	},
	{	1,		"��",	},
};

static	tagMemDBEnumPair	g_BpaEnumRing[]=
{
	{	0,		"����ĸ��",	},
	{	1,		"����ĸ��",	},
	{	2,		"�߽�ĸ��",	},
};

static	tagMemDBEnumPair	g_BpaEnumFaultType[]=
{
	{	BpaEnum_Scc_FaultType1,		"��������",	},
	{	BpaEnum_Scc_FaultType2,		"�����·",	},
	{	BpaEnum_Scc_FaultType3,		"�����·",	},
	{	BpaEnum_Scc_FaultType4,		"����ӵ�",	},
};

static	tagMemDBEnumPair	g_BpaEnumSccFMoveDataType[]=
{
	{	BpaEnum_Scc_FMoveDataType_FC_I1Re,		"������·��·����I������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I1Im,		"������·��·����I�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I2Re,		"������·��·����I�ฺ��ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I2Im,		"������·��·����I�ฺ���鲿",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I0Re,		"������·��·����I������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_FC_I0Im,		"������·��·����I�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z1Re,		"������·��·����J������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z1Im,		"������·��·����J�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z2Re,		"������·��·����J�ฺ��ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z2Im,		"������·��·����J�ฺ���鲿",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z0Re,		"������·��·����J������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_FC_Z0Im,		"������·��·����J�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I1Re,		"������·��·����I������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I1Im,		"������·��·����I�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I2Re,		"������·��·����I�ฺ��ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I2Im,		"������·��·����I�ฺ���鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I0Re,		"������·��·����I������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MC_I0Im,		"������·��·����I�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z1Re,		"������·��·����J������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z1Im,		"������·��·����J�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z2Re,		"������·��·����J�ฺ��ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z2Im,		"������·��·����J�ฺ���鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z0Re,		"������·��·����J������ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MC_Z0Im,		"������·��·����J�������鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MV_1Re,		"����ĸ�ߵ�ѹ����ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MV_1Im,		"����ĸ�ߵ�ѹ�����鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MV_2Re,		"����ĸ�ߵ�ѹ����ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MV_2Im,		"����ĸ�ߵ�ѹ�����鲿",	},
	{	BpaEnum_Scc_FMoveDataType_MV_0Re,		"����ĸ�ߵ�ѹ����ʵ��",	},
	{	BpaEnum_Scc_FMoveDataType_MV_0Im,		"����ĸ�ߵ�ѹ�����鲿",	},
};

static	tagMemDBEnumPair	g_BpaEnumFaultPhase[]=
{
	{	0,		"A��",	},
	{	1,		"B��",	},
	{	2,		"C��",	},
};

static	tagMemDBEnumPair	g_BpaEnumPssSI_INP[]=
{
	{	PssSI_INPStatus_WPG,	"�����ź�Ϊ�ػ�PG",	},	//0���߿ո�ʱ,ȡ��ֵ
	{	PssSI_INPStatus_W,		"�����ź�ֻ�Ц�",	},
	{	PssSI_INPStatus_PG,		"�����ź�ֻ��PG",	},
};

static	tagMemDBEnumPair	g_BpaEnumPssSI_IB[]=
{
	{	PssSI_INPStatus_dV,		"�����ź�Ϊ������ٶ�ƫ��",			},	//0���߿ո�ʱ,ȡ��ֵ
	{	PssSI_INPStatus_dF,		"�����ź�Ϊĸ��Ƶ��ƫ��",			},
	{	PssSI_INPStatus_EQ_dF,	"�����ź�Ϊ�������EQ��Ƶ��ƫ��",	},
};

static	tagMemDBEnumPair	g_BpaEnumSwicth[]=
{
	{	1,		"Ͷ��",	},	//1-Ͷ��
	{	2,		"�г�",	},	//2-�г�
};

static	tagMemDBEnumPair	g_BpaEnumGJ_ControlMode[]=
{
	{	1,		"���ڼ�ѹ����������",	},//=1�����ڼ�ѹ����������;
	{	2,		"DEH��������",			},//=2��DEH��������
	{	3,		"���ɷ�������",			},//=3�����ɷ�������
};

static	tagMemDBEnumPair	g_BpaEnumGK_FilterDead[]=
{
	{	GK_FilterDead_Dead,		"��������",		},
	{	GK_FilterDead_Filter,	"�����˲���",	},
};

static	tagMemDBEnumPair	g_BpaEnumGK_ControlMode[]=
{
	{	1,		"CCS�Զ�����",						},//=1,CCS�Զ�����;(��������Ϊ��ʽ1)
	{	2,		"���ɿ�������",						},//=2,���ɿ�������
	{	3,		"������ѹ�������ĸ��ɷ�������",		},//=3,������ѹ�������ĸ��ɷ�������
};

static	tagMemDBEnumPair	g_BpaEnumGM_OpenMode[]=
{
	{	GM_OpenMode_Y,		"�����ź�Ϊ����Y",	},
	{	GM_OpenMode_YPID,	"�����ź�ΪYPID",	},
};

static	tagMemDBEnumPair	g_BpaEnumGM_Mode[]=
{
	{	1,	"����ģʽ",	},	//=1Ϊ����ģʽ
	{	2,	"����ģʽ",	},	//=2Ϊ����ģʽ
};

static	tagMemDBEnumPair	g_BpaEnumGZ_ControlMode[]=
{
	{	GZ_ControlMode_Speed,		"�ٶ�",				},
	{	GZ_ControlMode_SpeedAndP,	"�ٶȺ͵�Ź���",	},
	{	GZ_ControlMode_SpeedAndMP,	"�ٶȺͻ�е����",	},
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
	{	Motor_KLS0_KL,		"������",	},
	{	Motor_KLS0_S0,		"��ʼ����",	},
};

static	tagMemDBEnumPair	g_BpaEnumMotor_Stall[]=
{
	{	Motor_IM_NONE,		"	",		},
	{	Motor_IM_STOP,		"ֹͣ����",	},
	{	Motor_IM_STALL,		"��ת",		},
	{	Motor_IM_TRIP,		"�г�",		},
};

static	tagMemDBEnumPair	g_BpaEnumFF_Stall[]=
{
	{	FF_IM_STOP,		"ֹͣ����",	},
	{	FF_IM_STALL,	"��ת",		},
	{	FF_IM_TRIP,		"�г�",		},
};

static	tagMemDBField	dicFieldBpaDat_Case[]=
{
	{	BPA_DAT_CASE_CASEID,						"Case_CaseID",				"������ʽ��",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_PROJECT,						"Case_Project",				"������",								MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_MVABASE,						"Case_MVABase",				"ָ����ϵͳ��׼����",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_CONTROL,						"Case_Control",				"��ָ���Ŀ�������ļ�",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_BRANCH,						"Case_Branch",				"��ָ����֧·����",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_BUS,							"Case_Bus",					"��ָ����ĸ������",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_NETWORK,						"Case_Network",				"��ָ���������ļ�",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_RXCHECK,						"Case_RXCheck",				"RX��ֵ���",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_NEWBASE,						"Case_NewBase",				"��������������ļ�(.BSE)",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_OLDBASE,						"Case_OldBase",				"ָ���Ͽ��ļ�",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_MAP,							"Case_Map",					"���ɳ���ͼ�����ƽ���ļ�",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_CASE_AICONTROL,						"Case_AIControl",			"���������߹��ʿ���ѡ��",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumCase_AIControl)/sizeof(tagMemDBEnumPair),	g_BpaEnumCase_AIControl,	},
	{	BPA_DAT_CASE_LTC,							"Case_LTC",					"�����ɵ�ѹ��ѹ������ѡ��",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumCase_LTC)/sizeof(tagMemDBEnumPair),			g_BpaEnumCase_LTC,			},
	{	BPA_DAT_CASE_DECOUPLEDNUM,					"Case_DecoupledNum",		"PQ���",								MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_CURRENTNUM,					"Case_CurrentNum",			"�Ľ���ţ������ѷ�㷨",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_NEWTONNUM,						"Case_NewtonNum",			"ţ������ѷ�㷨",						MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_OPTIMNUM,						"Case_OptimNum",			"���ų�����",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEBUSV,					"Case_ToleranceBusV",		"BusV�������,ȱʡֵ��0.005",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEAIPOWER,				"Case_ToleranceAIPower",	"AIPower�������,ȱʡֵ��0.005",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCETX,					"Case_ToleranceTX",			"TX�������,ȱʡֵ��0.005",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEQ,					"Case_ToleranceQ",			"Q�������,ȱʡֵ��0.005",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_CASE_TOLERANCEOPCUT,				"Case_ToleranceOpcut",		"OPCUT�������,ȱʡֵ��0.0001",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
//	{	BPA_DAT_CASE_INPUTLIST,						"Case_InputList",			"�����ԭʼ�������",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_RPTSORT,						"Case_RptSort",				"�������,���˳��������",			MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_CASE_ANALYSISRPT,					"Case_AnalysisRpt",			"�����������,ָ������ȼ�",			MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
//	{	BPA_DAT_CASE_AILISTCONTROL,					"Case_AIListControl",		"�����ʽ����������",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
//	{	BPA_DAT_CASE_LINELOSS,						"Case_LineLoss",			"��·������",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
//	{	BPA_DAT_CASE_TRANSFORMERLOSS,				"Case_TransformerLoss",		"��ѹ��֧·������",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ISLANDNUM,							"IslandNum",				"�絺��",								MDBFieldCategoryOutput,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_TOTGENP,							"TotGenP",					"�ܷ����й�",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTGENQ,							"TotGenQ",					"�ܷ����޹�",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOADP,							"TotLoadP",					"�ܸ����й�",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOADQ,							"TotLoadQ",					"�ܸ����޹�",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLINECAP,							"TotLineCap",				"��·����޹�",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOSSP,							"TotLossP",					"������й�",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTLOSSQ,							"TotLossQ",					"������޹�",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_TOTDCLOSS,							"TotDCLoss",				"ֱ�����������",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Area[]=
{
	{	BPA_DAT_AREA_NAME,			"Area_Name",	"��������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_AREA_CARDKEY,		"CardKey",		"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_DAT_AREA_SLACKBUSNAME,	"SlackBusName",	"���򻺳�ڵ�����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_AREA_SLACKBUSKV,	"SlackBuskV",	"���򻺳�ڵ��׼��ѹ",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_AREA_OUTP,			"OutP",			"���ŵ����򽻻�����(MW)ֵ",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_MK_TJ,				"MK_TJ",		"���Ĺ���ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_PPER,			"MK_Pper",		"��﹦��ռĸ���й����ɵı���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_KL,				"MK_KL",		"���ĸ�����",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_PMIN,			"MK_Pmin",		"���Ĺ�������",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_RS,				"MK_RS",		"���ӵ���(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_XS,				"MK_XS",		"���ӵ翹(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_XM,				"MK_XM",		"���ŵ翹(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_RR,				"MK_RR",		"ת�ӵ���(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_XR,				"MK_XR",		"ת�ӵ翹(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_VI,				"MK_VI",		"����ѹ�ͷŵĵ�ѹֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_TI,				"MK_TI",		"����ѹ�ͷ�ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_A,				"MK_A",			"ת�ط��̳���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_B,				"MK_B",			"ת�ط��̳���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_MK_IM,				"MK_IM",		"��ﻬ��ﵽ1ʱ�Ĵ���ʽ",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaDat_I[]=
{
	{	BPA_DAT_I_CARDKEY,			"CardKey",		"������",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_DAT_I_AREA1,			"I_Area1",		"����1����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_DAT_I_AREA2,			"I_Area2",		"����2����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_DAT_I_OUTP,				"I_OutP",		"����1������2���������",								MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Zone[]=
{
	{	BPA_DAT_ZONE_NAME,			"Zone_Name",	"��������",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,		0,	NULL,	},
	{	BPA_DAT_ZONE_AREA,			"Zone_Area",	"��������",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_DAT_ZONE_CARDKEY,		"CardKey",		"������",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},

	{	BPA_DAT_ZONE_KG0,			"LOZ_KG0",		"��·����絼���������絼�ı���	",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_KB0,			"LOZ_KB0",		"��·������������������ɵı���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_KGC0,			"LOZ_KGC0",		"��·�Ե�֧·����絼����ڶԵ�֧·����絼�ı���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_KBC0,			"LOZ_KBC0",		"��·�Ե�֧·�����������ڶԵ�֧·������ɵı���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_VMIN,			"LOZ_VMIN",		"��ѹ�ȼ�������Сֵ	",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_ZONE_VMAX,			"LOZ_VMAX",		"��ѹ�ȼ��������ֵ	",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},

	{	BPA_DAT_MJ_TJ,				"MJ_TJ",		"���Ĺ���ʱ�䳣��(��)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_PPER,			"MJ_Pper",		"��﹦��ռĸ���й����ɵı���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_KL,				"MJ_KL",		"���ĸ�����",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_PMIN,			"MJ_Pmin",		"���Ĺ�������",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_RS,				"MJ_RS",		"���ӵ���(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_XS,				"MJ_XS",		"���ӵ翹(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_XM,				"MJ_XM",		"���ŵ翹(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_RR,				"MJ_RR",		"ת�ӵ���(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_XR,				"MJ_XR",		"ת�ӵ翹(pu)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_VI,				"MJ_VI",		"����ѹ�ͷŵĵ�ѹֵ",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_TI,				"MJ_TI",		"����ѹ�ͷ�ʱ��(��)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_A,				"MJ_A",			"ת�ط��̳���",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_B,				"MJ_B",			"ת�ط��̳���",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_MJ_IM,				"MJ_IM",		"��ﻬ��ﵽ1ʱ�Ĵ���ʽ",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaDat_Sub[]=
{
	{	BPA_DAT_SUB_NAME,	"Sub_Name",		"��վ����",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_SUB_ALIAS,	"Sub_Alias",	"��վ����",			MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_SUB_TYPE,	"Sub_Type",		"��վ����",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	BPA_DAT_SUB_GENP,	"Sub_GenP",		"��վ�����й�",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_GENQ,	"Sub_GenQ",		"��վ�����޹�",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_LOADP,	"Sub_LoadP",	"��վ�����й�",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_LOADQ,	"Sub_LoadQ",	"��վ�����޹�",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_SUB_SHUNTQ,	"Sub_ShuntQ",	"��վ�����޹�",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_ACBus[]=
{
	{	BPA_DAT_ACBUS_CARDKEY,		"CardKey",				"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_ACBUS_CHGCODE,		"ACBus_ChgCode",		"�޸���",								MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACBUS_OWNER,		"ACBus_Owner",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACBUS_NAME,			"ACBus_Name",			"ĸ������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACBUS_KV,			"ACBus_kV",				"��׼��ѹ(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ZONE,			"ACBus_Zone",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACBUS_PLOAD,		"ACBus_PLoad",			"�㶨�й�����(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QLOAD,		"ACBus_QLoad",			"�㶨�޹�����(MVAR),+����",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PSHUNT,		"ACBus_PShunt",			"���������й�����(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QSHUNT,		"ACBus_QShunt",			"���������޹�����(MVAR),+����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PMAX,			"ACBus_Pmax",			"����й�����(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PGEN,			"ACBus_PGen",			"ʵ���й�����(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QSCHED_QMAX,	"ACBus_Qsched_Qmax",	"���ŵ��޹�����ֵ,+����",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_QMIN,			"ACBus_Qmin",			"�޹�������Сֵ(MVAR),�˴���0",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VHOLD_MAX,	"ACBus_VHold_max",		"���ŵ�Vmax(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VMIN,			"ACBus_Vmin",			"���ŵ�Vmin(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RBUSNAME,		"ACBus_RBusName",		"Զ��Ҫ���Ƶ�ĸ������",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACBUS_RBUSVOLT,		"ACBus_RBusVolt",		"Զ��Ҫ���ƵĻ�׼��ѹ(kV)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VARSPPLD,		"ACBus_VarSppld",		"�ṩ���޹����ʰٷ���(%)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_ADDCODE,		"ACBus_AddCode",		"�����ڵ㸺��ģ�������Ӵ���",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDPLOAD,		"ACBus_AddPLoad",		"�����ڵ��й�����(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDQLOAD,		"ACBus_AddQLoad",		"�����ڵ��޹�����(MVAR),+����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDPSHUNT,	"ACBus_AddPShunt",		"�����ڵ㲢���й�����(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDQSHUNT,	"ACBus_AddQShunt",		"�����ڵ㲢���޹�����(MVAR),+����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDPGEN,		"ACBus_AddPGen",		"�����ڵ��й�����(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ADDQGEN,		"ACBus_AddQGen",		"�����ڵ��޹�����(MVAR),+����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_SUB,			"ACBus_BpaSub",			"ĸ������BPA��վ",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_ACBUS_ALIAS,		"ACBus_Alias",			"����ĸ�߱���",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_ACBUS_V,			"ACBus_V",				"ĸ�ߵ�ѹ",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_D,			"ACBus_D",				"ĸ�߹���",								MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_PFOPGEN,		"ACBus_PfoPGen",		"ĸ�߼��㷢���й�",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQGEN,		"ACBus_PfoQGen",		"ĸ�߼��㷢���޹�",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOPLOAD,		"ACBus_PfoPLoad",		"ĸ�߼��㸺���й�",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQLOAD,		"ACBus_PfoQLoad",		"ĸ�߼��㸺���޹�",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQSHUNT,	"ACBus_PfoQShunt",		"ĸ�߼��㲹���޹�",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOPNET,		"ACBus_PfoPNet",		"ĸ�߼���ע���й�",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PFOQNET,		"ACBus_PfoQNet",		"ĸ�߼���ע���޹�",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_VD_RERR,		"vd_Rerr",				"ĸ�߹�����(��/��)",					MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC1,		"vd_RScc1",				"����ӵ�Ƶ��(��/��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC2,		"vd_RScc2",				"����·Ƶ��(��/��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC3,		"vd_RScc3",				"�����·Ƶ��(��/��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VD_RSCC4,		"vd_RScc4",				"����ӵ�Ƶ��(��/��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_RTGENP,		"ACBus_RtGenP",			"RTʵ���й�����(MW)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTGENQ,		"ACBus_RtGenQ",			"RT���ŵ��޹�����ֵ",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTLOADP,		"ACBus_RtLoadP",		"RT�㶨�й�����(MW)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTLOADQ,		"ACBus_RtLoadQ",		"RT�㶨�޹�����(MVAR)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTSHUNTQ,		"ACBus_RtShuntQ",		"RT���������޹�����(MVAR)",				MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_RTVHOLD,		"ACBus_RtVHold",		"RT���ŵ�V(pu)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_SCCA,			"ACBus_SccA",			"ĸ�߹��ϵ���(A)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV,			"ACBus_SccV",			"ĸ�߹��ϵ�ѹ(kV)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCR1,		"ACBus_SccR1",			"ĸ�������ֵ�迹(R1,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCX1,		"ACBus_SccX1",			"ĸ�������ֵ�迹(X1,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCR2,		"ACBus_SccR2",			"ĸ�߸����ֵ�迹(R2,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCX2,		"ACBus_SccX2",			"ĸ�߸����ֵ�迹(X2,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCR0,		"ACBus_SccR0",			"ĸ�������ֵ�迹(R0,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCX0,		"ACBus_SccX0",			"ĸ�������ֵ�迹(X0,pu)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA1RE,		"ACBus_SccA1Re",		"������ϵ���ʵ��(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA1IM,		"ACBus_SccA1Im",		"������ϵ����鲿(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA2RE,		"ACBus_SccA2Re",		"������ϵ���ʵ��(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA2IM,		"ACBus_SccA2Im",		"������ϵ����鲿(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA0RE,		"ACBus_SccA0Re",		"������ϵ���ʵ��(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCA0IM,		"ACBus_SccA0Im",		"������ϵ����鲿(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV1RE,		"ACBus_SccV1Re",		"������ϵ�ѹʵ��(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV1IM,		"ACBus_SccV1Im",		"������ϵ�ѹ�鲿(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV2RE,		"ACBus_SccV2Re",		"������ϵ�ѹʵ��(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV2IM,		"ACBus_SccV2Im",		"������ϵ�ѹ�鲿(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV0RE,		"ACBus_SccV0Re",		"������ϵ�ѹʵ��(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_SCCV0IM,		"ACBus_SccV0Im",		"������ϵ�ѹ�鲿(pu)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS1,		"ACBus_VDipBus1",		"ĸ�ߵ���ӵ��ݽ�ĸ����",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS2,		"ACBus_VDipBus2",		"ĸ������·�ݽ�ĸ����",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS3,		"ACBus_VDipBus3",		"ĸ�������·�ݽ�ĸ����",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_VDIPBUS4,		"ACBus_VDipBus4",		"ĸ������ӵ��ݽ�ĸ����",				MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	BPA_DAT_ACBUS_INIPLOAD,		"ACBus_IniPLoad",		"Ini�㶨�й�����(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIQLOAD,		"ACBus_IniQLoad",		"Ini�㶨�޹�����(MVAR),+����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIPSHUNT,	"ACBus_IniPShunt",		"Ini���������й�����(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIQSHUNT,	"ACBus_IniQShunt",		"Ini���������޹�����(MVAR),+����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIPGEN,		"ACBus_IniPGen",		"Ini�й�����(MW)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIQGEN,		"ACBus_IniQGen",		"Ini�޹�����ֵ,+����",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIADDPLOAD,	"ACBus_IniAddPLoad",	"Ini�����ڵ��й�����(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIADDQLOAD,	"ACBus_IniAddQLoad",	"Ini�����ڵ��޹�����(MVAR),+����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIADDPSHUNT,	"ACBus_IniAddPShunt",	"Ini�����ڵ㲢���й�����(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIADDQSHUNT,	"ACBus_IniAddQShunt",	"Ini�����ڵ㲢���޹�����(MVAR),+����",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIADDPGEN,	"ACBus_IniAddPGen",		"Ini�����ڵ��й�����(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACBUS_INIADDQGEN,	"ACBus_IniAddQGen",		"Ini�����ڵ��޹�����(MVAR),+����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACBUS_TMID,			"TMid",					"��ѹ�����Ե���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_GENERATOR,	"Generator",			"�����ĸ�߱��",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_WTGEN,		"WTGen",				"��������������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_PVGEN,		"PVGen",				"���������������",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_DCBOUND,		"DCBound",				"��ֱ���߽罻��ĸ��",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_GENLN,		"GenLn",				"��ֵ�����ĸ�߱��",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_STATUS,		"Status",				"ĸ��״̬",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_REDUCTION,	"Reduction",			"�����ֵĸ��",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACBUS_INRING,		"InRing",				"�����豸",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_ACBUS_RADIATE,		"Radiate",				"���ڷ�����",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ACBUS_ACISLAND,		"ACIsland",				"������",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRLINE,		"pRLine",				"ĸ����·����",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRTRAN,		"pRTran",				"ĸ�߱�ѹ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRHG,			"pRHG",					"ĸ�߸߿�����",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_ACBUS_PRSUB,		"pRSub",				"ĸ�߳�վ����",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_ACLine[]=
{
	{	BPA_DAT_ACLINE_CARDKEY,		"CardKey",			"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_ACLINE_CHGCODE,		"ACLine_ChgCode",	"�޸���",							MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_OWNER,		"ACLine_Owner",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSI,		"ACLine_BusI",		"ĸ������1",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_KVI,			"ACLine_kVI",		"��׼��ѹ1(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_METER,		"ACLine_Meter",		"���������߲���־",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSJ,		"ACLine_BusJ",		"ĸ������2",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_KVJ,			"ACLine_kVJ",		"��׼��ѹ2(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOOP,		"ACLine_Loop",		"������·�Ļ�·��־",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_SECTION,		"ACLine_Section",	"�ֶδ������ɵ���·�Ķκ�",			MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACLINE_AMP,			"ACLine_AMP",		"��·�����(����)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOOPNUM,		"ACLine_LoopNum",	"������·��Ŀ",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACLINE_R,			"ACLine_R",			"����(R,pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_X,			"ACLine_X",			"�翹(X,pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_G1,			"ACLine_G1",		"��·ĸ��1�˶Եص絼(G/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_B1,			"ACLine_B1",		"��·ĸ��1�˶Եص���(B/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_G2,			"ACLine_G2",		"��·ĸ��2�˶Եص絼(G/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_B2,			"ACLine_B2",		"��·ĸ��2�˶Եص���(B/2,pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_MILES,		"ACLine_Miles",		"��·��γ���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	//{	BPA_DAT_ACLINE_COMMENT,		"ACLine_Comment",	"��·˵������",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},

	{	BPA_DAT_ACLINE_VD_RERR,		"vd_Rerr",			"��·������(��/��)",				MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC1,	"vd_RScc1",			"����ӵ�Ƶ��(��/��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC2,	"vd_RScc2",			"����·Ƶ��(��/��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC3,	"vd_RScc3",			"�����·Ƶ��(��/��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VD_RSCC4,	"vd_RScc4",			"����ӵ�Ƶ��(��/��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACLINE_PI,			"ACLine_Pi",		"��·BUS1���й�(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_QI,			"ACLine_Qi",		"��·BUS1���޹�(MVar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_PZ,			"ACLine_Pz",		"��·BUS2���й�(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_QZ,			"ACLine_Qz",		"��·BUS2���޹�(MVar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOSSP,		"ACLine_LossP",		"��·�й����(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_LOSSQ,		"ACLine_LossQ",		"��·�޹����(MVar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_ACLINE_SCCA,		"ACLine_SccA",		"��·���ϵ���(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS1,	"ACLine_VDipBus1",	"��·�е㵥��ӵ��ݽ�ĸ����",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS2,	"ACLine_VDipBus2",	"��·�е�����·�ݽ�ĸ����",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS3,	"ACLine_VDipBus3",	"��·�е������·�ݽ�ĸ����",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_VDIPBUS4,	"ACLine_VDipBus4",	"��·�е�����ӵ��ݽ�ĸ����",		MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	BPA_DAT_ACLINE_KEYNAME,		"KeyName",			"��·����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_ACLINE_INIBUSI,		"IniBusI",			"Iniĸ������1",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_INIKVI,		"InikVI",			"Ini��׼��ѹ1(kV)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_INIBUSJ,		"IniBusJ",			"Iniĸ������2",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ACLINE_INIKVJ,		"InikVJ",			"Ini��׼��ѹ2(kV)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ACLINE_INILOOP,		"IniLoop",			"Ini������·�Ļ�·��־",			MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSIPTR,		"iRBus",			"��·Iĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_BUSJPTR,		"zRBus",			"��·Zĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_ACLINE_ALIAS,		"Alias",			"������·����",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_ACLINE_STATUS,		"Status",			"״̬",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_ACLINE_INRING,		"InRing",			"�����豸",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_ACLINE_RADIATE,		"Radiate",			"���ڷ�����",						MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_LineHG[]=
{
	{	BPA_DAT_LINEHG_CARDKEY,		"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_DAT_LINEHG_BUSI,		"LineHG_BusI",		"ĸ������1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_KVI,			"LineHG_kVI",		"��׼��ѹ1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_BUSJ,		"LineHG_BusJ",		"ĸ������2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_KVJ,			"LineHG_kVJ",		"��׼��ѹ2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_LOOP,		"LineHG_Loop",		"������·�Ļ�·��־",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_LINEHG_SHUNTI,		"LineHG_ShuntI",	"��·ǰ��߿�����(Mvar,����ֵ)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_SHUNTJ,		"LineHG_ShuntJ",	"��·���߿�����(Mvar,����ֵ)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_KEYNAME,		"KeyName",			"��·�߿�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_LINEHG_INIBUSI,		"IniBusI",			"Iniĸ������1",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_INIKVI,		"InikVI",			"Ini��׼��ѹ1(kV)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_INIBUSJ,		"IniBusJ",			"Iniĸ������2",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LINEHG_INIKVJ,		"InikVJ",			"Ini��׼��ѹ2(kV)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LINEHG_INILOOP,		"IniLoop",			"Ini������·�Ļ�·��־",				MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_LINEHG_BUSPTR,		"iRBus",			"��·�߿�Iĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_LINEHG_ZRBUS,		"zRBus",			"��·�߿�Zĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_LINEHG_ALIAS,		"Alias",			"��·�߿�����",							MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_LINEHG_STATUS,		"Status",			"״̬",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_LINEHG_INRING,		"InRing",			"�����豸",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_LINEHG_RADIATE,		"Radiate",			"���ڷ�����",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Wind[]=
{
	{	BPA_DAT_WIND_CARDKEY,	"CardKey",		"������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_WIND_CHGCODE,	"Wind_ChgCode",	"�޸���",									MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_OWNER,		"Wind_Owner",	"������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_WIND_BUSI,		"Wind_BusI",	"ĸ������1",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_KVI,		"Wind_kVI",		"��׼��ѹ1(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_METER,		"Wind_Meter",	"���������߲���־",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_BUSJ,		"Wind_BusJ",	"ĸ������2",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_KVJ,		"Wind_kVJ",		"��׼��ѹ2(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOOP,		"Wind_Loop",	"������·�Ļ�·��־",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_SECTION,	"Wind_Section",	"�ֶδ������ɵ���·�Ķκ�",					MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_MVA,		"Wind_MVA",		"��ѹ�������(MVA)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOOPNUM,	"Wind_LoopNum",	"������ѹ����Ŀ",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_R,			"Wind_R",		"��ͭ������ĵ�Ч����(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_X,			"Wind_X",		"©��(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_G,			"Wind_G",		"����������ĵ�Ч�絼(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_B,			"Wind_B",		"���ŵ���(pu)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_TPI,		"Wind_TPI",		"ĸ��1�Ĺ̶��ֽ�ͷ/�������Ĺ̶������(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_TPJ,		"Wind_TPJ",		"ĸ��2�Ĺ̶��ֽ�ͷ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_PI,		"Wind_Pi",		"��ѹ��BUS1���й�(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_QI,		"Wind_Qi",		"��ѹ��BUS1���޹�(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_PZ,		"Wind_Pz",		"��ѹ��BUS2���й�(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_QZ,		"Wind_Qz",		"��ѹ��BUS2���޹�(MVar)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOSSP,		"Wind_LossP",	"��ѹ���й����(MW)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_LOSSQ,		"Wind_LossQ",	"��ѹ���޹����(MVar)",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_SCCAI,		"Wind_SccAI",	"��ѹ��BUS1����ϵ���(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_SCCAZ,		"Wind_SccAZ",	"��ѹ��BUS1����ϵ���(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_VD_RERR,	"vd_Rerr",		"��ѹ��������(��/��)",						MDBFieldCategoryParam,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC1,	"vd_RScc1",		"����ӵ�Ƶ��(��/��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC2,	"vd_RScc2",		"����·Ƶ��(��/��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC3,	"vd_RScc3",		"�����·Ƶ��(��/��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_VD_RSCC4,	"vd_RScc4",		"����ӵ�Ƶ��(��/��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_WIND_KEYNAME,	"KeyName",		"��ѹ������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_WIND_INIBUSI,	"IniBusI",		"Iniĸ������1",								MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_INIKVI,	"InikVI",		"Ini��׼��ѹ1(kV)",							MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_INIBUSJ,	"IniBusJ",		"Iniĸ������2",								MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_WIND_INIKVJ,	"InikVJ",		"Ini��׼��ѹ2(kV)",							MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_INILOOP,	"IniLoop",		"Ini������·�Ļ�·��־",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_WIND_BUSIPTR,	"BusIPtr",		"��ѹ��Iĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_WIND_BUSJPTR,	"BusJPtr",		"��ѹ��Jĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_WIND_RCARD,		"RCard",		"�ܿر�ѹ��(ֱ��ĸ�߲�R=1-I,R=2-J)",		MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_ALIAS,		"Alias",		"��ѹ������",								MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_WIND_RTTPI,		"RtTPI",		"RTĸ��1�Ĺ̶��ֽ�ͷ",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_RTTPJ,		"RtTPJ",		"RTĸ��2�Ĺ̶��ֽ�ͷ",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_WIND_STATUS,	"Status",		"״̬",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_WIND_TRANPTR,	"TranPtr",		"��ѹ������",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_WIND_INRING,	"InRing",		"�����豸",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumRing)/sizeof(tagMemDBEnumPair),			g_BpaEnumRing,			},
	{	BPA_DAT_WIND_RADIATE,	"Radiate",		"���ڷ�����",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_R[]=
{
	{	BPA_DAT_R_CARDKEY,	"CardKey",		"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_R_CHGCODE,	"R_ChgCode",	"�޸���",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_R_OWNER,	"R_Owner",		"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_R_BUSI,		"R_BusI",		"ĸ������1",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_R_KVI,		"R_kVI",		"��׼��ѹ1(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_VARTAP,	"R_VARTAP",		"�ɵ���ͷ�˱�־",			MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_R_BUSJ,		"R_BusJ",		"ĸ������2",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_R_KVJ,		"R_kVJ",		"��׼��ѹ2(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_BUSC,		"R_BusC",		"����ĸ������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_R_KVC,		"R_kVC",		"���ػ�׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_TMAX,		"R_TMax",		"����ͷλ��(kV)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_TMIN,		"R_TMin",		"��С��ͷλ��(kV)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_TNUM,		"R_TNum",		"LTC��ͷ����",				MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_R_VALMAX,	"R_ValMax",		"ָ��������޹�����(Mvar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_VALMIN,	"R_ValMin",		"ָ������С�޹�����(Mvar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_P,		"R_P",			"�й�(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_Q,		"R_Q",			"�޹�(Mvar)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_LOSSP,	"R_LossP",		"�й����(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_LOSSQ,	"R_LossQ",		"�޹����(Mvar)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_R_KEYNAME,	"KeyName",		"��ѹ������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_R_BUSIPTR,	"R_iRBus",		"��ѹ��Iĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_R_BUSJPTR,	"R_zRBus",		"��ѹ��Zĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_R_STATUS,	"R_Status",		"״̬",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_DCBus[]=
{
	{	BPA_DAT_DCBUS_CARDKEY,		"CardKey",				"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_DCBUS_CHGCODE,		"DCBus_ChgCode",		"�޸���",							MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_DCBUS_OWNER,		"DCBus_Owner",			"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_DCBUS_NAME,			"DCBus_Name",			"Converterĸ������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCBUS_KV,			"DCBus_kV",				"Converter��׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ZONE,			"DCBus_Zone",			"Zone,������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_DCBUS_BRDGS,		"DCBus_BRDGS",			"������·������",					MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_DCBUS_SMTHGREACTOR,	"DCBus_SMTHGREACTOR",	"ƽ���翹�����(����)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ROPERMIN,		"DCBus_ROPERMIN",		"��Ϊ���������е���С������(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_IOPERSTOP,	"DCBus_IOPERSTOP",		"��Ϊ��������е���󴥷���(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DROP,			"DCBus_DROP",			"ÿ���ŷ��ĵ�ѹ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_BRDGRATE,		"DCBus_BRDGRATE",		"�ŵ����ֵ(����)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ACNAME,		"DCBus_ACName",			"������ѹ��һ�β�ĸ������",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCBUS_ACKV,			"DCBus_ACkV",			"������ѹ��һ�β��׼��ѹ(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCBUS_DCV,			"DCBus_V",				"ֱ��ĸ�ߵ�ѹ(kV)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DCD,			"DCBus_D",				"ֱ��ĸ�߹���(��)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DCP,			"DCBus_P",				"ֱ������й�(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_DCI,			"DCBus_I",				"ֱ��������(A)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_LOSSP,		"DCBus_LossP",			"ֱ������й����(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_LOSSQ,		"DCBus_LossQ",			"ֱ������޹����(MVar)",			MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ACV,			"DCBus_ACV",			"������ĸ�ߵ�ѹ(kV)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ANGLE,		"DCBus_Angle",			"����/�ضϽ�(��)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCBUS_ACBUS,		"ACBus",				"������ѹ��һ�β�ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCBUS_PRLINE,		"pRLine",				"ĸ����·����",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCBUS_PRTRAN,		"pRTran",				"ĸ�߱�ѹ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCBUS_ACISLAND,		"ACIsland",				"������",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_DAT_DCBUS_SUB,			"Sub",					"ĸ������BPA��վ",					MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_DCBUS_ALIAS,		"Alias",				"ֱ��ĸ�߱���",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_DCBUS_STATUS,		"Status",				"״̬",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaDat_DCLine[]=
{
	{	BPA_DAT_DCLINE_CARDKEY,	"CardKey",			"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_DCLINE_CHGCODE,	"DCLine_ChgCode",	"�޸���",							MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_DCLINE_OWNER,	"DCLine_Owner",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSR,	"DCLine_BusR",		"������ĸ������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCLINE_KVR,		"DCLine_kVR",		"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_METER,	"DCLine_Meter",		"���������߲���־",				MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSI,	"DCLine_BusI",		"����ĸ������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_DCLINE_KVI,		"DCLine_kVI",		"�����׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_AMP,		"DCLine_AMP",		"ֱ����·�����(����)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_R,		"DCLine_R",			"ֱ����·����(ŷķ)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_L,		"DCLine_L",			"ֱ����·���(����)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_C,		"DCLine_C",			"ֱ����·����(΢��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_CONTROL,	"DCLine_CONTROL",	"�����ŵ�ֱ�����ʵĿ��Ƶ�",			MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_DCLINE_DCPOWER,	"DCLine_DCPOWER",	"�����ŵ�ֱ������(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_RVOLT,	"DCLine_RVOLT",		"����ֱ����·�������ֱ����ѹ(kV)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_ROPER,	"DCLine_ROPER",		"�����������������(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_ISTOP,	"DCLine_ISTOP",		"����������ضϽ�(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_MILES,	"DCLine_Miles",		"��·����",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCLINE_PR,		"DCLine_Pr",		"��·�����๦��(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_PI,		"DCLine_Pi",		"��·���๦��(MW)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_DCLINE_LOSSP,	"DCLine_Lossp",		"��·�й����(MW)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_DAT_DCLINE_KEYNAME,	"KeyName",			"ֱ����·����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSRPTR,	"iRBus",			"ֱ����·������ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCLINE_BUSIPTR,	"iIBus",			"ֱ����·����ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_DCLINE_ALIAS,	"Alias",			"ֱ����·����",						MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_DCLINE_STATUS,	"Status",			"״̬",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_RZ[]=
{
	{	BPA_DAT_RZ_CARDKEY,	"CardKey",		"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	//{	BPA_DAT_RZ_CHGCODE,	"RZ_ChgCode",	"�޸���",					MDBFieldCategoryAid,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_RZ_OWNER,	"RZ_Owner",		"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_DAT_RZ_BUSI,	"RZ_BusI",		"ĸ������1",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_RZ_KVI,		"RZ_kVI",		"��׼��ѹ1(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_BUSJ,	"RZ_BusJ",		"ĸ������2",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_RZ_KVJ,		"RZ_kVJ",		"��׼��ѹ2(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_LOOP,	"RZ_Loop",		"������·�Ļ�·��־",		MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_RZ_SECTION,	"RZ_Section",	"�ֶδ������ɵ���·�Ķκ�",	MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_RZ_MODE,	"RZ_Mode",		"���Ʒ�ʽ",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_RZ_PCMAX,	"RZ_Pcmax",		"��·�й��������ֵ(MW)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_PCMIN,	"RZ_Pcmin",		"��·�й�������Сֵ(MW)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_IN,		"RZ_In",		"��·�����ֵ(A)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_XIJMAX,	"RZ_Xijmax",	"��·�翹���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_XIJMIN,	"RZ_Xijmin",	"��·�翹��С(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RZ_KEYNAME,	"KeyName",		"��������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_DAT_RZ_BUSIPTR,	"iRBus",		"��·�翹Iĸ������",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_RZ_BUSJPTR,	"zRBus",		"��·�翹Zĸ������",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_RZ_STATUS,	"Status",		"״̬",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_P[]=
{
	{	BPA_DAT_P_CARDKEY,			"CardKey",			"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_DAT_P_ZONE,				"P_Zone",			"�����ߴ���",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,		0,	NULL,	},
	{	BPA_DAT_P_LOADPFACTOR,		"P_LoadPFactor",	"�����й��޸�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_LOADQFACTOR,		"P_LoadQFactor",	"�����޹��޸�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_GENPFACTOR,		"P_GenPFactor",		"��������й��޸�����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_GENQFACTOR,		"P_GenQFactor",		"��������޹��޸�����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},

	{	BPA_DAT_P_INILOADPFACTOR,	"P_IniLoadPFactor",	"Ini�����й��޸�����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_INILOADQFACTOR,	"P_IniLoadQFactor",	"Ini�����޹��޸�����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_INIGENPFACTOR,	"P_IniGenPFactor",	"Ini��������й��޸�����",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_DAT_P_INIGENQFACTOR,	"P_IniGenQFactor",	"Ini��������޹��޸�����",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},

	{	BPA_DAT_P_STATUS,			"P_Status",			"״̬",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_ZIL[]=
{
	{	BPA_DAT_ZIL_CARDKEY,	"CardKey",			"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_DAT_ZIL_BUSI,		"ZIL_BusI",			"ĸ������1",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ZIL_KVI,		"ZIL_kVI",			"��׼��ѹ1(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ZIL_BUSJ,		"ZIL_BusJ",			"ĸ������2",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ZIL_KVJ,		"ZIL_kVJ",			"��׼��ѹ2(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ZIL_LOOP,		"ZIL_Loop",			"������·�Ļ�·��־",		MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_ZIL_R,			"ZIL_R",			"����(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ZIL_X,			"ZIL_X",			"�翹(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ZIL_MBUS,		"ZIL_MBus",			"�ϲ�ĸ������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_ZIL_MKV,		"ZIL_MkV",			"�ϲ���׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_ZIL_KEYNAME,	"KeyName",			"С֧·����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_VDip[]=
{
	{	BPA_DAT_VDIP_FDEVINDEX,	"FDevIndex",	"�����豸����",		MDBFieldCategoryParam,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_VDIP_FTYPE,		"FaultType",	"��������",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumFaultType)/sizeof(tagMemDBEnumPair),	g_BpaEnumFaultType,	},
	{	BPA_DAT_VDIP_DIPBUS,	"DipBus",		"�ݽ�ĸ��",			MDBFieldCategoryOutput,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_VDIP_DIPV,		"DipV",			"�ݽ���ѹ(pu)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_VDIP_POLYPHASE,	"PoluPhase",	"�ݽ���",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Gen[]=
{
	{	BPA_DAT_GEN_NAME,			"Name",				"����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_GEN_BUS,			"Gen_Bus",			"ĸ������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_GEN_KV,				"Gen_kV",			"��׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_ID,				"Gen_ID",			"���ʶ����",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_DAT_GEN_PGEN,			"Gen_PGen",			"�й�����(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_QGEN,			"Gen_QGen",			"�޹�����(MVar)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_PMAX,			"Gen_PMax",			"����й�����(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_PMIN,			"Gen_PMin",			"��С�й�����(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_QMAX,			"Gen_QMax",			"����޹�����(MVar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_QMIN,			"Gen_QMin",			"��С�޹�����(MVar)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_VHOLD,			"Gen_VHold",		"���ŵĵ�ѹ,PVֵ(pu)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_GEN_ACBUSPTR,		"Gen_ACBusPtr",		"ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_GEN_WTGEN,			"Gen_WTGen",		"������",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_GEN_PVGEN,			"Gen_PVGen",		"���ģ��",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_GEN_EQ,				"Gen_EQ",			"��ֵ��Դ",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_GEN_STATUS,			"Gen_Status",		"״̬",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Load[]=
{
	{	BPA_DAT_LOAD_NAME,			"Name",				"����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_DAT_LOAD_BUS,			"Load_Bus",			"ĸ������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_LOAD_KV,			"Load_kV",			"��׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LOAD_PLOAD,			"Load_PLoad",		"�й�����(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LOAD_QLOAD,			"Load_QLoad",		"�޹�����(MVar)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_LOAD_ACBUSPTR,		"Load_ACBusPtr",	"ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_LOAD_AUX,			"Load_Aux",			"���õ�",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_LOAD_EQ,			"Load_EQ",			"��ֵ����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_DAT_LOAD_STATUS,		"Load_Status",		"״̬",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Tran[]=
{
	{	BPA_DAT_TRAN_WINDNUM,		"WindNum",			"������",				MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	BPA_DAT_TRAN_WINDH,			"WindH",			"��ѹ����",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_TRAN_WINDM,			"WindM",			"��ѹ����",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_TRAN_WINDL,			"WindL",			"��ѹ����",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_TRAN_IRWINDH,		"iRWindH",			"��ѹ��������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_TRAN_IRWINDM,		"iRWindM",			"��ѹ��������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_TRAN_IRWINDL,		"iRWindL",			"��ѹ��������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_DAT_TRAN_STATUS,		"Status",			"״̬",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeACLine[]=
{
	{	BPA_DAT_EDGEACLINE_ACBUSNAME,	"ACBusName",	"����ĸ������",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGEACLINE_ACBUSKV,		"ACBuskV",		"����ĸ�ߵ�ѹ(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGEACLINE_ACLINENAME,	"ACLineName",	"������·����",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGEACLINE_ACLINEPTR,	"ACLinePtr",	"������·����",		MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeWind[]=
{
	{	BPA_DAT_EDGEWIND_ACBUSNAME,		"ACBusName",	"����ĸ������",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGEWIND_ACBUSKV,		"ACBuskV",		"����ĸ�ߵ�ѹ(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGEWIND_WINDNAME,		"WindName",		"��ѹ����������",	MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGEWIND_WINDPTR,		"WindPtr",		"��ѹ����������",	MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeLineHG[]=
{
	{	BPA_DAT_EDGELINEHG_ACBUSNAME,	"ACBusName",	"����ĸ������",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGELINEHG_ACBUSKV,		"ACBuskV",		"����ĸ�ߵ�ѹ(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGELINEHG_HGNAME,		"LineHGName",	"��·�߿�����",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGELINEHG_LINEHGPTR,	"LineHGPtr",	"��·�߿�����",		MDBFieldCategoryBase,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeDCLine[]=
{
	{	BPA_DAT_EDGEDCLINE_DCBUSNAME,	"DCBusName",	"ֱ��ĸ������",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGEDCLINE_DCBUSKV,		"DCBuskV",		"ֱ��ĸ�ߵ�ѹ(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGEDCLINE_DCLINENAME,	"DCLineName",	"ֱ����·����",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGEDCLINE_DCLINEPTR,	"DCLinePtr",	"ֱ����·����",		MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_EdgeR[]=
{
	{	BPA_DAT_EDGER_DCBUSNAME,		"DCBusName",	"ֱ��ĸ������",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_EDGER_DCBUSKV,			"DCBuskV",		"ֱ��ĸ�ߵ�ѹ(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_EDGER_RNAME,			"WindName",		"��ѹ������",		MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_DAT_EDGER_RPTR,				"WindPtr",		"��ѹ������",		MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaDat_Radiate[]=
{
	{	BPA_DAT_RADIATE_BOUNDBUSNAME,	"BoundBusName",		"��Դĸ������",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_DAT_RADIATE_BOUNDBUSKV,		"BoundBuskV",		"��Դĸ�ߵ�ѹ(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_GENP,			"GenP",				"���ڷ����й�(MW)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_LOADP,			"LoadP",			"���ڸ����й�(MW)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_LOADQ,			"LoadQ",			"���ڸ����޹�(MVar)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_DAT_RADIATE_IRBOUNDBUS,		"iRBoundBus",		"��Դĸ������",			MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaScc_FMove[]=
{
	{	BPA_SCC_FMOVE_FAULTTYPE,		"FaultType",		"��������",		MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumFaultType)/sizeof(tagMemDBEnumPair),	g_BpaEnumFaultType,	},
	{	BPA_SCC_FMOVE_FAULTLINE,		"FaultLine",		"������·",		MDBFieldCategoryOutput,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SCC_FMOVE_MONLINE,			"MonLine",			"������·",		MDBFieldCategoryOutput,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SCC_FMOVE_MONBUS,			"MonBus",			"����ĸ��",		MDBFieldCategoryOutput,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SCC_FMOVE_DATATYPE,			"DataType",			"��������",		MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSccFMoveDataType)/sizeof(tagMemDBEnumPair),	g_BpaEnumSccFMoveDataType,	},
	{	BPA_SCC_FMOVE_VALUE000,			"Value000",			"ֵ000",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE001,			"Value001",			"ֵ001",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE002,			"Value002",			"ֵ002",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE003,			"Value003",			"ֵ003",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE004,			"Value004",			"ֵ004",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE005,			"Value005",			"ֵ005",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE006,			"Value006",			"ֵ006",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE007,			"Value007",			"ֵ007",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE008,			"Value008",			"ֵ008",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE009,			"Value009",			"ֵ009",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE010,			"Value010",			"ֵ010",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE011,			"Value011",			"ֵ011",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE012,			"Value012",			"ֵ012",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE013,			"Value013",			"ֵ013",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE014,			"Value014",			"ֵ014",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE015,			"Value015",			"ֵ015",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE016,			"Value016",			"ֵ016",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE017,			"Value017",			"ֵ017",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE018,			"Value018",			"ֵ018",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE019,			"Value019",			"ֵ019",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE020,			"Value020",			"ֵ020",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE021,			"Value021",			"ֵ021",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE022,			"Value022",			"ֵ022",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE023,			"Value023",			"ֵ023",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE024,			"Value024",			"ֵ024",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE025,			"Value025",			"ֵ025",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE026,			"Value026",			"ֵ026",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE027,			"Value027",			"ֵ027",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE028,			"Value028",			"ֵ028",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE029,			"Value029",			"ֵ029",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE030,			"Value030",			"ֵ030",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE031,			"Value031",			"ֵ031",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE032,			"Value032",			"ֵ032",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE033,			"Value033",			"ֵ033",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE034,			"Value034",			"ֵ034",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE035,			"Value035",			"ֵ035",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE036,			"Value036",			"ֵ036",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE037,			"Value037",			"ֵ037",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE038,			"Value038",			"ֵ038",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE039,			"Value039",			"ֵ039",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE040,			"Value040",			"ֵ040",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE041,			"Value041",			"ֵ041",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE042,			"Value042",			"ֵ042",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE043,			"Value043",			"ֵ043",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE044,			"Value044",			"ֵ044",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE045,			"Value045",			"ֵ045",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE046,			"Value046",			"ֵ046",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE047,			"Value047",			"ֵ047",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE048,			"Value048",			"ֵ048",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE049,			"Value049",			"ֵ049",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE050,			"Value050",			"ֵ050",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE051,			"Value051",			"ֵ051",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE052,			"Value052",			"ֵ052",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE053,			"Value053",			"ֵ053",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE054,			"Value054",			"ֵ054",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE055,			"Value055",			"ֵ055",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE056,			"Value056",			"ֵ056",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE057,			"Value057",			"ֵ057",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE058,			"Value058",			"ֵ058",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE059,			"Value059",			"ֵ059",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE060,			"Value060",			"ֵ060",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE061,			"Value061",			"ֵ061",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE062,			"Value062",			"ֵ062",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE063,			"Value063",			"ֵ063",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE064,			"Value064",			"ֵ064",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE065,			"Value065",			"ֵ065",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE066,			"Value066",			"ֵ066",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE067,			"Value067",			"ֵ067",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE068,			"Value068",			"ֵ068",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE069,			"Value069",			"ֵ069",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE070,			"Value070",			"ֵ070",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE071,			"Value071",			"ֵ071",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE072,			"Value072",			"ֵ072",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE073,			"Value073",			"ֵ073",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE074,			"Value074",			"ֵ074",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE075,			"Value075",			"ֵ075",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE076,			"Value076",			"ֵ076",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE077,			"Value077",			"ֵ077",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE078,			"Value078",			"ֵ078",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE079,			"Value079",			"ֵ079",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE080,			"Value080",			"ֵ080",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE081,			"Value081",			"ֵ081",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE082,			"Value082",			"ֵ082",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE083,			"Value083",			"ֵ083",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE084,			"Value084",			"ֵ084",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE085,			"Value085",			"ֵ085",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE086,			"Value086",			"ֵ086",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE087,			"Value087",			"ֵ087",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE088,			"Value088",			"ֵ088",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE089,			"Value089",			"ֵ089",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE090,			"Value090",			"ֵ090",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE091,			"Value091",			"ֵ091",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE092,			"Value092",			"ֵ092",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE093,			"Value093",			"ֵ093",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE094,			"Value094",			"ֵ094",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE095,			"Value095",			"ֵ095",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE096,			"Value096",			"ֵ096",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE097,			"Value097",			"ֵ097",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE098,			"Value098",			"ֵ098",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE099,			"Value099",			"ֵ099",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
	{	BPA_SCC_FMOVE_VALUE100,			"Value100",			"ֵ100",		MDBFieldCategoryOutput,	MDB_DOUBLE,	sizeof(double),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_Case[]=
{
	{	BPA_SWI_CASE_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_CASE_PFCASE,		"PFCASE",		"������ʽ��",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_SWI_CASE_ITSKP,			"ITSKP",		"д����ļ��Ĳ���",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_NOPRNT,		"NOPRNT",		"NOPRNT,Ϊ1ʱ��ӡȫ����������",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_DSW,			"DSW",			"����ļ�ҡ��������ʾ����",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_IWSCC,			"IWSCC",		"�����¼����ɿ������ɱ��",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_ZSW,			"ZSW",			"�����򿨽��м���־",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_CASE_X2FAC,			"X2FAC",		"���Գƹ���ʱ�����X2��Xdp֮��",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_XFACT,			"XFACT",		"�����Xdpp��Xdp֮��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TDODPS,		"TDODPS",		"��������Tdopp(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TQODPS,		"TQODPS",		"��������Tdopp(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TDODPH,		"TDODPH",		"͹��ˮ�ֻ���Tqopp(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_TQODPH,		"TQODPH",		"͹��ˮ�ֻ���Tdopp(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_CASE_CFACL2,		"CFACL2",		"���򸺺ɵ���(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_F1[]=
{
	{	BPA_SWI_F1_CARDKEY,		"CardKey",		"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_F1_TBUSF,		"TBUSF",		"ĸ��Ƶ���˲���ȱʡʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_F1_TZERO,		"TZERO",		"������·ȱʡʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_F1_IBLOD,		"IBLOD",		"ĸ�߸��ɿ���",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),		0,	NULL,	},
	{	BPA_SWI_F1_DMPALL,		"DMPALL",		"ȱʡ�������������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_F1_IAMRTS,		"IAMRTS",		"�����ֵ��Ϊ0,��F1���е�XFACTҲ��Ϊ0,���۷�����Ĵ���̬�����Ƿ��Ѿ���M��ָ��,��Ҫ����ȱʡ�Ĳ��������㷢����Ĵ���̬����",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),			0,	NULL,	},
	{	BPA_SWI_F1_VCHGL,		"VCHGL",		"�������ĸ�ߵ�ѹ���ڸ�ֵ,�򸺺ɽ�ת��Ϊ���迹����,ȱʡֵΪ0.5pu",															MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),					0,	NULL,	},
	{	BPA_SWI_F1_SPTOSG,		"SPTOSG",		"SP��Ϊ�Լ��ٹ�����Ϊ�����źŵ�PSS,��SG��Ϊ�Ե�Ź���Ϊ�����źŵ�PSS;�����ֵ��Ϊ0,���ȶ����������е�SP����ΪSG��",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),			0,	NULL,	},
	{	BPA_SWI_F1_GSIQU,		"GSIQU",		"�����ֵ��Ϊ��,�������ļ�������GH����GS���������Ĵ�С��Ϊ��ֵ",															MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),					0,	NULL,	},
	{	BPA_SWI_F1_TITSKP,		"TITSKP",		"�ӱ�ʱ�俪ʼ,���ձ����е�48-49����д�Ĳ������д洢",																		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),					0,	NULL,	},
	{	BPA_SWI_F1_ITSKP1,		"ITSKP1",		"�ӱ���43-47�й涨��ʱ��TITSKP��ʼÿ��ITSKP1���洢һ������",																MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),					0,	NULL,	},
	{	BPA_SWI_F1_VRLIM,		"VRLIM",		"FM��FO��FP��FQ��FR��FS��FT��FG������ģ�͵ĵ�ѹ���޷�����Ϊ���޷�,���VRLIM��Ϊ0,�����Ϊ���޷�",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_F0[]=
{
	{	BPA_SWI_F0_CARDKEY,		"CardKey",			"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_F0_IG,			"IG",				"�ȶ�������ʾѡ��",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_IA,			"IA",				"����������Խ���ʾѡ��",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_BUSNAME1,	"GenBusName1",		"�����1ĸ������",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_BUSVOLT1,	"GenBusBase1",		"�����1ĸ�ߵ�ѹ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_ID1,			"GenID1",			"�����1ʶ����",				MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_F0_BUSNAME2,	"GenBusName2",		"�����2ĸ������",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_BUSVOLT2,	"GenBusBase2",		"�����2ĸ�ߵ�ѹ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_ID2,			"GenID2",			"�����2ʶ����",				MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_F0_AMAX,		"AMAX",				"��Խ�Y����������ֵ",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_AMIN,		"AMIN",				"��Խ�Y���������Сֵ",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_IV,			"IV",				"ĸ�ߵ�ѹ��ʾѡ��",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_VBUSNAME,	"VBUSNAME",			"��ʾ��ѹ�仯���ߵ�ĸ������",	MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_VBUSVOLT,	"VBUSVOLT",			"��ʾ��ѹ�仯���ߵ�ĸ�ߵ�ѹ",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_F0_IF,			"IF",				"ĸ��Ƶ����ʾѡ��",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_F0_FBUSNAME,	"FBUSNAME",			"��ʾƵ�ʱ仯���ߵ�ĸ������",	MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_F0_FBUSVOLT,	"FBUSVOLT",			"��ʾƵ�ʱ仯���ߵ�ĸ�ߵ�ѹ",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_FF[]=
{
	{	BPA_SWI_FF_CARDKEY,		"CardKey",		"������",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FF_T,			"T",			"���㿪ʼʱ��(��)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DT,			"DT",			"���㲽��(��)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_ENDT,		"ENDT",			"������ֹʱ��(��)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DTC,			"DTC",			"�µĲ���(��)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_ISTP,		"ISTP",			"��ʼ�ı䲽����ʱ��(��)",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_FF_TOLI,		"TOLI",			"���ε����������ٹ�����Χ",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_ILIM,		"ILIM",			"һ�������緽����΢�ַ���������������",			MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_FF_DELANG,		"DELANG",		"���ε��������Ƕ���Χ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DTDV,		"DTDV",			"�������ֲ�����ֱ�����ֲ���֮��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_DMPMLT,		"DMPMLT",		"�������������",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_FRQBSE,		"FRQBSE",		"ϵͳ��׼Ƶ��",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FF_LOVTEX,		"LOVTEX",		"=1�޵͵�ѹ���,������м��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_IMBLOK,		"IMBLOK",		"��ﻬ��ﵽ1ʱ�Ĵ�����",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumFF_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumFF_Stall,	},
	{	BPA_SWI_FF_MFDEP,		"MFDEP",		"ҡ�ڷ����붨�ӷ�����Ƶ�ʵĹ�ϵ",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_IGSLIM,		"IGSLIM",		"����ʱ,���е�����ģ��GS���������޷�",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_LSOLQIT,		"LSOLQIT",		"=1������������,ֹͣ����",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOANGLIM,	"NOANGLIM",		"=1�������Ƕ�����,��������Ƕȳ���500��ͣ��",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_INFBUS,		"INFBUS",		"=1�����з������Ϊ�������Ե��",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOPP,		"NOPP",			"����ʱ,���з�����������Ǵ���̬����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NODQ,		"NODQ",			"=1�����з������Ϊ����ģ��",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOSAT,		"NOSAT",		"����ʱ,���еķ���������Ǳ���",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOGV,		"NOGV",			"=1�����з�������Ƶ�����",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_IEQPC,		"IEQPC",		"����ʱ,���з�����Ĵ����㶨",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOEX,		"NOEX",			"=1�����з�������Ƶ�ѹ��",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_MFTOMG,		"MFTOMG",		"����ʱ,���еķ������MF����ת��ΪMG��",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOSC,		"NOSC",			"=1���������и����ź�",								MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_MGTOMF,		"MGTOMF",		"����ʱ,���еķ������MG����ת��ΪMF��",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FF_NOLOAD,		"NOLOAD",		"=1�����и���Ϊ�㶨�迹",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_Gen[]=
{
	{	BPA_SWI_GEN_CARDKEY,		"CardKey",		"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GEN_BUS_NAME,		"ACBus_Name",	"���ĸ����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GEN_BUS_KV,			"ACBus_kV",		"���ĸ�ߵ�ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_ID,				"Gen_ID",		"���ʶ����",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GEN_EMWS,			"Gen_Emws",		"���������(MW.��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_P,				"Gen_P",		"�������ʼ�й�����ռĸ�߳������ʱ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_Q,				"Gen_Q",		"�������ʼ�޹�����ռĸ�߳������ʱ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_MVABASE,		"Gen_MVABase",	"�����ô�����Ļ�׼����",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_RA,				"Gen_Ra",		"���ӵ���(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XDP,			"Gen_Xdp",		"ֱ����̬�翹Xdp(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XQP,			"Gen_Xqp",		"������̬�翹Xqp(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XD,				"Gen_Xd",		"ֱ�᲻����ͬ���翹Xd(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XQ,				"Gen_Xq",		"���᲻����ͬ���翹Xq(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_TD0,			"Gen_Td0",		"ֱ����̬��·ʱ�䳣��Tdop(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_TQ0,			"Gen_Tq0",		"������̬��·ʱ�䳣��Tqop(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_XL_XP,			"Gen_XL_XP",	"����©��(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_SG10,			"Gen_SG10",		"���ѹʱ�������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_SG12,			"Gen_SG12",		"���ѹ1.2��ʱ�������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_D,				"Gen_D",		"�������ת��ϵ���ٷ���",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_A,				"Gen_A",		"����a",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_B,				"Gen_B",		"����b",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_N,				"Gen_N",		"����N",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_MVA,			"Gen_MVA",		"����",									MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GEN_KEYNAME,		"KeyName",		"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GEN_BUSPTR,			"BusPtr",		"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GEN_APPENDTAG,		"AppendTag",	"������¼���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_Damp[]=
{
	{	BPA_SWI_DAMP_CARDKEY,		"CardKey",		"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DAMP_BUS_NAME,		"ACBus_Name",	"���ĸ����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_DAMP_BUS_KV,		"ACBus_kV",		"���ĸ�ߵ�ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_ID,			"Damp_ID",		"���ʶ����",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_DAMP_MVA,			"Damp_MVA",		"��������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_PF,			"Damp_PF",		"�����������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_XDPP,			"Damp_Xdpp",	"ֱ�����̬�翹Xdpp(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_XQPP,			"Damp_Xqpp",	"�������̬�翹Xqpp(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_TD0PP,			"Damp_Td0pp",	"ֱ�����̬ʱ�䳣��Td0pp(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_TQ0PP,			"Damp_Tq0pp",	"�������̬ʱ�䳣��Tq0pp(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DAMP_KEYNAME,		"KeyName",		"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_DAMP_BUSPTR,		"BusPtr",		"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_DAMP_APPENDTAG,		"AppendTag",	"������¼���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_WGEGen[]=
{
	{	BPA_SWI_WGEGEN_CARDKEY,		"CardKey",		"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_BUS_NAME,	"ACBus_Name",	"���ĸ����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_BUS_KV,		"ACBus_kV",		"���ĸ�ߵ�ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_ID,			"Gen_ID",		"���ʶ����",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_GE_TYPE,		"GE_TYPE",		"���������ʹ���",						MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_NG,			"NG",			"������̨��",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_NAME_CON,	"NAME_CON",		"��糡�޹����ƽڵ�����",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGEGEN_BASE_CON,	"BASE_CON",		"��糡�޹����ƽڵ��׼��ѹ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_PPER,		"PPER",			"�й�ռ�����ܳ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_QPER,		"QPER",			"�޹�ռ�����ܳ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_V0,			"V0",			"��ʼ����(m/s)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGEGEN_NMASS_FLG,	"NMASS_FLG",	"=0����˫������,����������",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_QDROOP_FLG,	"QDROOP_FLG",	"=0������QDROOP,������",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_WINDCON_FLG,	"WINDCON_FLG",	"=0��糡�޹���ѹ/�㹦����������ģʽ",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_EWVOL_FLG,	"EWVOL_FLG",	"=0�������Ʋ��õ�ѹ����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_APCFLG,		"APCFLG",		"=0������APC�й����ƹ���,�������",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_FFLG,		"FFLG",			"=0APC�����в������������ƿ��ƹ���",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_INERTIA,		"INERTIA",		"=0������WINDINERTIA����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_PQFLG,		"PQFLG",		"=0�޹����ȱ�־,�����й�����(ֱ��)",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_WGEGEN_KEYNAME,		"KeyName",		"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_WGEGEN_BUSPTR,		"BusPtr",		"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_WGWGen[]=
{
	{	BPA_SWI_WGWGEN_CARDKEY,		"CardKey",		"������",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGWGEN_BUS_NAME,	"ACBus_Name",	"���ĸ����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_WGWGEN_BUS_KV,		"ACBus_kV",		"���ĸ�ߵ�ѹ(kV)",										MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_ID,			"Gen_ID",		"���ʶ����",											MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_GW_TYPE,		"GW_TYPE",		"���������ʹ���",										MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
	{	BPA_SWI_WGWGEN_NG,			"NG",			"������̨��",											MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_PPER,		"PPER",			"�й�ռ�����ܳ�������",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_QPER,		"QPER",			"�޹�ռ�����ܳ�������",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_IP_CUR,		"IP_CUR",		"�͵�ѹ��Խ,�й������趨ֵ(A,ȱʡ200)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_IP_RETURN,	"IP_RETURN",	"�͵�ѹ��Խ�ָ�,�й������趨ֵ(A,ȱʡ400)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_IP_RET_TIME,	"IP_RET_TIME",	"�͵�ѹ��Խ�ָ�,ά����������ʱ��(��,ȱʡ0)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_IP_RATE,		"IP_RATE",		"�͵�ѹ��Խ�ָ�,�й�������������(A/s,ȱʡ1500)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_Q_RATE,		"Q_RATE",		"�޹������仯��(pu,��ѹ���ͱ���,�������׼,ȱʡ0)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_IMAX,		"IMAX",			"����������(A)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_WGWGEN_KEYNAME,		"KeyName",		"���ݿ�����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_WGWGEN_BUSPTR,		"BusPtr",		"�����ĸ������",										MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_PV[]=
{
	{	BPA_SWI_PV_CARDKEY,		"CardKey",		"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PV_BUS_NAME,	"ACBus_Name",	"���ĸ����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PV_BUS_KV,		"ACBus_kV",		"���ĸ�ߵ�ѹ(kV)",								MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PV_ID,			"Gen_ID",		"���ʶ����",									MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PV_T,			"T",			"ʵ���¶�(��)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PV_S,			"S",			"����ǿ��(W/m1)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PV_UOC,			"Uoc",			"�����ر�׼�����µĿ�·��ѹ(V)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PV_ISC,			"Isc",			"�����ر�׼�����µĶ�·����(A)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PV_UM,			"Um",			"�����ر�׼�����µ�����ʵ��ѹ(V)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PV_IM,			"Im",			"�����ر�׼�����µ�����ʵ����(A)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PV_N1,			"N1",			"������в����������",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_PV_N2,			"N2",			"������д����������",							MDBFieldCategoryParam,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	BPA_SWI_PV_KEYNAME,		"KeyName",		"���ݿ�����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PV_BUSPTR,		"BusPtr",		"�����ĸ������",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_GenLn[]=
{
	{	BPA_SWI_GENLN_CARDKEY,		"CardKey",		"������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GENLN_BUS_NAME,		"ACBus_Name",	"��ֵ���������",		MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GENLN_BUS_KV,		"ACBus_kV",		"��ֵ�������ѹ",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GENLN_BUSPTR,		"BusPtr",		"��ֵ�����ĸ������",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GENLN_DCBUS,		"DCBus",		"ֱ��ĸ��",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_Exc68[]=
{
	{	BPA_SWI_EXCIT68_CARDKEY,			"CardKey",				"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCIT68_BUS_NAME,			"ACBus_Name",			"ĸ������,ĸ����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCIT68_BUS_KV,				"ACBus_kV",				"��׼��ѹ(kV),��׼��ѹ",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_GEN_ID,				"Gen_ID",				"�����ʶ����",									MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TR,					"Exc68_TR",				"TR,��ѹ��������˲���ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KA_BUSKV,			"Exc68_KA_BusKV",		"KA,��ѹ������",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TR_TRH,				"Exc68_TR_TRH",			"TA,��ѹ���Ŵ���ʱ�䳣��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TA1,				"Exc68_TA1",			"TA1,��ѹ���Ŵ���ʱ�䳣��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_VRMINMULT_TRMAX,	"Exc68_VRMinMult_TRMax","VRMAXMULT,VRMAX����",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KE,					"Exc68_KE",				"KE,�������йص����ų���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TE,					"Exc68_TE",				"TE,���Ż�ʱ�䳣��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_SE75MAX_KI,			"Exc68_SE75Max_KI",		"SE.75MAX,75��������ŵ�ѹʱ�����Ż�����ϵ��",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_SEMAX_KP,			"Exc68_SEMax_KP",		"SEMAX,������ŵ�ѹʱ�����Ż�����ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_EFDMIN,				"Exc68_EFDMin",			"EFDMIN,��С���ŵ�ѹ",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_EFDMAX_VBMAX,		"Exc68_EFDMax_VBMax",	"EFDMAX,������ŵ�ѹ",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KF,					"Exc68_KF",				"KF,��ѹ���ȶ���·����",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TF,					"Exc68_TF",				"TF,��ѹ���ȶ���·ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_XL,					"Exc68_XL",				"XL,�����翹",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_TF1,				"Exc68_TF1",			"TF1,��ѹ���ȶ���·ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_KEYNAME,			"KeyName",				"���ݿ�����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCIT68_BUSPTR,				"BusPtr",				"�����ĸ������",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCIT68_APPENDTAG,			"AppendTag",			"������¼���",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_Exc81[]=
{
	{	BPA_SWI_EXCIT81_CARDKEY,			"CardKey",				"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCIT81_BUS_NAME,			"ACBus_Name",			"ĸ����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCIT81_BUS_KV,				"ACBus_kV",				"��׼��ѹ",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_GEN_ID,				"Gen_ID",				"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_RC,					"Exc81_RC",				"���ز���֮�й��ط���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_XC,					"Exc81_XC",				"���ز���֮�й��ط���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TR,					"Exc81_TR",				"�����������˲���ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VIAMAX_VAMAX,		"Exc81_VIAMax_VAMax",	"��ѹ�������ͺ�ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VIMIN_VAMIN,		"Exc81_VIMin_VAMin",	"��ѹ��������ǰʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TB,					"Exc81_TB",				"��ѹ����������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TC,					"Exc81_TC",				"��ѹ�������ͺ�ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_KA_BUSKV,			"Exc81_KA_BusKV",		"��ѹ������������(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TA_TRH,				"Exc81_TA_TRH",			"��ѹ��������С���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VRMAX_VAMAX,		"Exc81_VRMax_VAMax",	"���Ż�������ʱ�䳣��(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_VRMIN_VAMIN,		"Exc81_VRMin_VAMin",	"���Ż�ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_EFDMAX_VBMAX,		"Exc81_EFDMax_VBMax",	"��ѹ���ȶ���·����(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_KE_KJ,				"Exc81_KE_KJ",			"��һ������������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_TE,					"Exc81_TE",				"���Ż�ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_KEYNAME,			"KeyName",				"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCIT81_BUSPTR,				"BusPtr",				"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCIT81_APPENDTAG,			"AppendTag",			"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_ExcMV[]=
{
	{	BPA_SWI_EXCITMV_CARDKEY,			"CardKey",			"������",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCITMV_BUS_NAME,			"ACBus_Name",		"ĸ����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCITMV_BUS_KV,				"ACBus_kV",			"��׼��ѹ",											MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_GEN_ID,				"Gen_ID",			"�����ʶ����",										MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_RC,					"ExcMV_RC",			"���ز���֮�й��ط���(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_XC,					"ExcMV_XC",			"���ز���֮�й��ط���(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_TR,					"ExcMV_TR",			"�����������˲���ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_K,					"ExcMV_K",			"����������(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KV,					"ExcMV_kV",			"�������ֻ򴿻��ֵ���ѡ������",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T1,					"ExcMV_T1",			"��ѹ������ʱ�䳣��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T2,					"ExcMV_T2",			"��ѹ������ʱ�䳣��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T3,					"ExcMV_T3",			"��ѹ������ʱ�䳣��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_T4,					"ExcMV_T4",			"��ѹ������ʱ�䳣��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KA,					"ExcMV_KA",			"��ѹ������(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_TA,					"ExcMV_TA",			"��ѹ���Ŵ�����ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KF,					"ExcMV_KF",			"��ѹ���ȶ���·����(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_TF,					"ExcMV_TF",			"��ѹ���ȶ���·ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KH,					"ExcMV_KH",			"���Ż�������������(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_KEYNAME,			"KeyName",			"���ݿ�����",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCITMV_BUSPTR,				"BusPtr",			"�����ĸ������",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCITMV_APPENDTAG,			"AppendTag",		"������¼���",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_FZ[]=
{
	{	BPA_SWI_FZ_CARDKEY,				"CardKey",				"������",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FZ_BUS_NAME,			"ACBus_Name",			"ĸ����",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FZ_BUS_KV,				"ACBus_kV",				"��׼��ѹ",																MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_GEN_ID,				"Gen_ID",				"�����ʶ����",															MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_FZ_SE1_KI,				"FZ_SE1_KI",			"���ŵ�ѹ�������Ż�����ϵ��/������·����ϵ��(D��L)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_SE2_KP,				"FZ_SE2_KP",			"���ŵ�ѹ75���������Ż�����ϵ��/���ƻ�·����ϵ��(D��L)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_EFDMIN_EFDN_DP,		"FZ_EFDMin_EFDN_DP",	"���Ż���С�����ѹ(J)/�ȶ���������ı䴦�����ŵ�ѹ/��ѹ��·��ǲ�(L)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_EFD1_VE1_EFDMAX,		"FZ_EFD1_VE1_EFDMax",	"���ŵ�ѹ(A��B��E)/����翹�����ŵ�ѹ(C��F��H)/������ŵ�ѹ(D��L)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KF_KG,				"FZ_KF_KG",				"���ſ���ϵͳ�ȶ�������/�ڷ�����·����(L)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_TF_VGMAX,			"FZ_TF_VGMax",			"���ſ���ϵͳʱ�䳣��/�ڷ�����·����ѹ(L)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KC,					"FZ_KC",				"����翹����������������",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KD_XL,				"FZ_KD_XL",				"ȥ������(C��F��H)/����Դ�翹(L)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KB_VLV,				"FZ_KB_VLV",			"�ڶ�������������(F)/���Ż��͵�ѹ����(H)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KL_KLV,				"FZ_KL_KLV",			"���Ż����ŵ�����������(F)/���Ż��͵�ѹ�����ź�����(H)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KH_KN,				"FZ_KH_KN",				"���Ż����ŵ�����������(F)/���ſ���ϵͳ�ȶ�������(�϶�)(H)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_VLR_KR,				"FZ_VLR_KR",			"���Ż����ŵ�������(F)/���ӵ������ͱ任�����Ź��ʵĳ���(H)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FZ_KEYNAME,				"KeyName",				"���ݿ�����",															MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FZ_BUSPTR,				"BusPtr",				"�����ĸ������",														MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_FZ_APPENDTAG,			"AppendTag",			"������¼���",															MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_FCA[]=
{
	{	BPA_SWI_FCA_CARDKEY,			"CardKey",			"������",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FCA_BUS_NAME,			"ACBus_Name",		"ĸ����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FCA_BUS_KV,				"ACBus_kV",			"��׼��ѹ",											MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_GEN_ID,				"Gen_ID",			"�����ʶ����",										MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_FCA_VAMAX,				"FCA_VAMax",		"����������ڲ���ѹ(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VAMIN,				"FCA_VAMin",		"��������С�ڲ���ѹ(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KB,					"FCA_KB",			"�ڶ�������������",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_T5,					"FCA_T5",			"�ڶ���������ʱ�䳣��",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KE,					"FCA_KE",			"���Ż�������ϵ��(pu)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_TE,					"FCA_TE",			"���Ż�ʱ�䳣��(��)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_SE1,				"FCA_SE1",			"������ŵ�ѹ�������Ż�����ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_SE2,				"FCA_SE2",			"SE2,75��������ŵ�ѹ�������Ż�����ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VRMAX,				"FCA_VRMax",		"��ѹ������������(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VRMIN,				"FCA_VRMin",		"��ѹ��������С���(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KC,					"FCA_KC",			"����翹����������������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KD,					"FCA_KD",			"ȥ������(pu)",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_KL1,				"FCA_KL1",			"���Ż����ŵ�����������(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_VL1R,				"FCA_VL1R",			"���Ż���������(pu)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCA_EFDMAX,				"FCA_EFDMax",		"������ŵ�ѹ(pu)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_FCA_KEYNAME,			"KeyName",			"���ݿ�����",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FCA_BUSPTR,				"BusPtr",			"�����ĸ������",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_FCA_APPENDTAG,			"AppendTag",		"������¼���",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_FCB[]=
{
	{	BPA_SWI_FCB_CARDKEY,			"CardKey",			"������",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FCB_BUS_NAME,			"ACBus_Name",		"ĸ����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FCB_BUS_KV,				"ACBus_kV",			"��׼��ѹ",											MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_GEN_ID,				"Gen_ID",			"�����ʶ����",										MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_FCB_IPID,				"FCB_IPID",			"IPID",												MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_FCB_KP,					"FCB_KP",			"����PID���ڵı�������ϵ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_KI,					"FCB_KI",			"����PID���ڵĻ��ֻ���ϵ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_KD,					"FCB_KD",			"����PID���ڵ�΢�ֻ���ϵ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_TD,					"FCB_TD",			"����PID���ڵ�΢�ֻ���ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_INTMAX,				"FCB_INTMAX",		"����PID���ڵĻ��ֻ����޷����ֵ",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_INTMIN,				"FCB_INTMIN",		"����PID���ڵĻ��ֻ����޷���Сֵ",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_DEVMAX,				"FCB_DEVMAX",		"����PID���ڵ�΢�ֻ����޷����ֵ",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_DEVMIN,				"FCB_DEVMIN",		"����PID���ڵ�΢�ֻ����޷���Сֵ",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_FCB_VALMAX,				"FCB_VAlMax",		"����PID���ڵ��޷����ֵ",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_VALMIN,				"FCB_VAlMin",		"����PID���ڵ��޷���Сֵ",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FCB_IFUFV,				"FCB_IFUFV",			"FU��FV����ģ���Ƿ��пɿع�������������޶�",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},

	{	BPA_SWI_FCB_KEYNAME,			"KeyName",			"���ݿ�����",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FCB_BUSPTR,				"BusPtr",			"�����ĸ������",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_FCB_APPENDTAG,			"AppendTag",		"������¼���",										MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_ExcX[]=
{
	{	BPA_SWI_EXCITX_CARDKEY,			"CardKey",			"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_EXCITX_BUS_NAME,		"ACBus_Name",		"ĸ����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_EXCITX_BUS_KV,			"ACBus_kV",			"��׼��ѹ",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_GEN_ID,			"Gen_ID",			"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_EXCITX_RC,				"ExcX_RC",			"���ز���֮�й��ط���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_XC,				"ExcX_XC",			"���ز���֮�й��ط���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_TR,				"ExcX_TR",			"�����������˲���ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KA,				"ExcX_KA",			"����������(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_TA,				"ExcX_TA",			"������ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KP,				"ExcX_Kp",			"��������(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KI,				"ExcX_KI",			"����ϵ��(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VRMAX,			"ExcX_VRMax",		"��ѹ������������(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VRMIN,			"ExcX_VRMin",		"��ѹ��������С���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_IKP,				"ExcX_IKp",			"��������������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_IKI,				"ExcX_IKI",			"����������ϵ��(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VFMAX,			"ExcX_VFMax",		"������������޷�(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_VFMIN,			"ExcX_VFMin",		"����������С�޷�(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_KT,				"ExcX_KT",			"�ɿع�����������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITX_TT,				"ExcX_TT",			"�ɿع�������ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_EXCITXEX_KIFD,			"ExcEX_Kifd",		"���ŵ����������ڷŴ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITXEX_TIFD,			"ExcEX_Tifd",		"���ŵ�����������ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITXEX_EFDMIN,		"ExcEX_EFDMin",		"��С���ŵ�ѹ(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_EXCITXEX_EFDMAX,		"ExcEX_EFDMax",		"������ŵ�ѹ(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_EXCITX_KEYNAME,			"KeyName",			"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_EXCITX_BUSPTR,			"BusPtr",			"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_EXCITX_APPENDTAG,		"AppendTag",		"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssS[]=
{
	{	BPA_SWI_PSSS_CARDKEY,		"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSS_BUS_NAME,		"ACBus_Name",		"ĸ����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSS_BUS_KV,		"ACBus_kV",			"��׼��ѹ",								MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_GEN_ID,		"Gen_ID",			"�����ʶ����",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSS_KQV,			"PssS_KQV",			"��ѹ��������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQV,			"PssS_TQV",			"��ѹ������ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_KQS,			"PssS_KQS",			"Ƶ�ʡ����ٹ��ʺ��Ử���������",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQS,			"PssS_TQS",			"Ƶ�ʡ����ٹ��ʺ��Ử�����ʱ�䳣��",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ,			"PssS_TQ",			"PSS����ʱ�䳣��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ1,			"PssS_TQ1",			"��һ���ͺ�ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ1P,			"PssS_TQ1P",		"��һ����ǰʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ2,			"PssS_TQ2",			"�ڶ����ͺ�ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ2P,			"PssS_TQ2P",		"�ڶ�����ǰʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ3,			"PssS_TQ3",			"�������ͺ�ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_TQ3P,			"PssS_TQ3P",		"��������ǰʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_VSMAX,			"PssS_VSmax",		"PSS������(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_VCUTOFF,		"PssS_VCutOff",		"�ο���ѹֵ,���������ͼ˵��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_VSLOW,			"PssS_VSlow",		"����ȷ��VSMINֵ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_KQBASE,		"PssS_KQBase",		"KQ�Ļ�׼����(MVA)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_RBUSNAME,		"PssS_RBusName",	"Զ��ĸ����",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSS_RBUSKV,		"PssS_RBuskV",		"Զ��ĸ�߻�׼��ѹ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSS_KEYNAME,		"KeyName",			"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSS_BUSPTR,		"BusPtr",			"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSS_IRRBUS,		"PssS_iRRBus",		"Զ��ĸ��ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSS_APPENDTAG,		"AppendTag",		"������¼���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssST[]=
{
	{	BPA_SWI_PSSST_CARDKEY,		"CardKey",		"������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSST_BUS_NAME,		"ACBus_Name",	"ĸ����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSST_BUS_KV,		"ACBus_kV",		"��׼��ѹ",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_GEN_ID,		"Gen_ID",		"�����ʶ����",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSST_T1,			"PssST_T1",		"ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_T2,			"PssST_T2",		"ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_T3,			"PssST_T3",		"ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_K,			"PssST_K",		"Ƶ�ʱ�ôֵ����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_DWT1,			"PssST_DWt1",	"Ƶ��ƫ��1",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_DWT2,			"PssST_DWt2",	"Ƶ��ƫ��2",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_DWPT,			"PssST_DWpt",	"Ƶ��ƫ��3",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_TDELAY,		"PssST_TDelay",	"������ʱʱ�䳣��(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_T4,			"PssST_T4",		"ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSST_KEYNAME,		"KeyName",		"���ݿ�����",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSST_BUSPTR,		"BusPtr",		"�����ĸ������",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSST_APPENDTAG,	"AppendTag",	"������¼���",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSH[]=
{
	{	BPA_SWI_PSSSH_CARDKEY,		"CardKey",			"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSH_BUS_NAME,		"ACBus_Name",		"ĸ����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSH_BUS_KV,		"ACBus_kV",			"��׼��ѹ",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_GEN_ID,		"Gen_ID",			"�����ʶ����",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSSH_TD,			"PssSH_TD",			"TD",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_T1,			"PssSH_T1",			"T1",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_T2,			"PssSH_T2",			"T2",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_T3,			"PssSH_T3",			"T3",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K0,			"PssSH_K0",			"K0",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K1,			"PssSH_K1",			"K1",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K2,			"PssSH_K2",			"K2",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K3,			"PssSH_K3",			"K3",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_K,			"PssSH_K",			"K",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_VSMAX,		"PssSH_VSMax",		"PSS������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_VSMIN,		"PssSH_VSMin",		"PSS��С���(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_KP,			"PssSH_KP",			"KP",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSH_KMVA,			"PssSH_KMVA",		"KP�Ļ�׼����(MVA)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_PSSSHEX_KPM,		"PssSHEX_KPM",		"KPM",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TPM,		"PssSHEX_TPM",		"TPM",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KPE,		"PssSHEX_KPE",		"KPE",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TPE,		"PssSHEX_TPE",		"TPE",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KW,			"PssSHEX_KW",		"KW",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TW,			"PssSHEX_TW",		"TW",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TD1,		"PssSHEX_TD1",		"TD1",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_TD2,		"PssSHEX_TD2",		"TD2",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KD1,		"PssSHEX_KD1",		"������Ŀǰ��������д0����1",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSHEX_T4,			"PssSHEX_T4",		"T4",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_K4,			"PssSHEX_K4",		"K4",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSHEX_KMVA,		"PssSHEX_KMVA"	,	"KPM��KPE�Ļ�׼����(MVA)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_PSSSH_KEYNAME,		"KeyName",			"���ݿ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSH_BUSPTR,		"BusPtr",			"�����ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSH_APPENDTAG,	"AppendTag",		"������¼���",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSI[]=
{
	{	BPA_SWI_PSSSI_CARDKEY,			"CardKey",				"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSI_BUS_NAME,			"ACBus_Name",			"�����ĸ����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSI_BUS_KV,			"ACBus_kV",				"�������׼��ѹ(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_GEN_ID,			"Gen_ID",				"�����ʶ����",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
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
	{	BPA_SWI_PSSSI_INP,				"PssSI_INP",			"�����ź�",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumPssSI_INP)/sizeof(tagMemDBEnumPair),	g_BpaEnumPssSI_INP,	},
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
	{	BPA_SWI_PSSSI_KMVA,				"PssSI_KMVA",			"SI���е�KR�Ļ�׼����(MVA)",MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSI_KEYNAME,			"KeyName",				"���ݿ�����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSI_BUSPTR,			"BusPtr",				"�����ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSI_IRMEABUS,			"Gen_iRMeaBus",			"����ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSI_APPENDTAG,		"AppendTag",			"������¼���",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSA[]=
{
	{	BPA_SWI_PSSSA_CARDKEY,		"CardKey",			"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSA_BUS_NAME,		"ACBus_Name",		"���������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSA_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_GEN_ID,		"Gen_ID",			"�����ʶ����",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T1,			"PssSA_T1",			"T1,�˲���ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T2,			"PssSA_T2",			"T2,�˲���ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T3,			"PssSA_T3",			"T3,�˲���ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T4,			"PssSA_T4",			"T4,�˲���ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T5,			"PssSA_T5",			"T5,�˲���ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_T6,			"PssSA_T6",			"T6,�˲���ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_K1,			"PssSA_K1",			"K1,�ٶ��źŷŴ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_K2,			"PssSA_K2",			"K2,���ٶ��źŷŴ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_K,			"PssSA_K",			"K*",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_A,			"PssSA_A",			"A,�Ŵ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_P,			"PssSA_P",			"P,��λ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_LIMITMAX,		"PssSA_LimitMax",	"LIMIT-MAX,���������޷�",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_LIMITMIN,		"PssSA_LimitMin",	"LIMIT-MIN,���������޷�",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_KMVA,			"PssSA_KMVA",		"K�Ļ�׼����",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSA_KEYNAME,		"KeyName",			"���ݿ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSA_BUSPTR,		"BusPtr",			"�����ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSA_APPENDTAG,	"AppendTag",		"������¼���",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_PssSB[]=
{
	{	BPA_SWI_PSSSB_CARDKEY,			"CardKey",				"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_PSSSB_BUS_NAME,			"ACBus_Name",			"���������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_PSSSB_BUS_KV,			"ACBus_KV",				"�������׼��ѹ(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_GEN_ID,			"Gen_ID",				"BusIDʶ����ID",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_PSSSB_ISIG,				"PssSB_ISIG",			"ISIG,�����źű�־",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSB_TD,				"PssSB_TD",				"TD(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW1,				"PssSB_TW1",			"TW1(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW2,				"PssSB_TW2",			"TW2(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T6,				"PssSB_T6",				"T6(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW3,				"PssSB_TW3",			"TW3(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_TW4,				"PssSB_TW4",			"TW4(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T7,				"PssSB_T7",				"T7(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KS2,				"PssSB_KS2",			"KS2",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KS3,				"PssSB_KS3",			"KS3",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KPG,				"PssSB_KPG",			"KPG(PU)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_MVA_BSE,			"PssSB_MVA_BSE",		"MVA_BSE(MVA)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T8,				"PssSB_T8",				"T8(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T9,				"PssSB_T9",				"T9(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_M,				"PssSB_M",				"M",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSB_N,				"PssSB_N",				"N",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_PSSSB_KS1,				"PssSB_KS1",			"KS1",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T1,				"PssSB_T1",				"T1(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T2,				"PssSB_T2",				"T2(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T3,				"PssSB_T3",				"T3(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_T4,				"PssSB_T4",				"T4(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_VPMAX,			"PssSB_VPMax",			"VPMAX",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_VPMIN,			"PssSB_VPMin",			"VPMIN",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_PSSSB_KEYNAME,			"KeyName",				"���ݿ�����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_PSSSB_BUSPTR,			"BusPtr",				"�����ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_PSSSB_APPENDTAG,		"AppendTag",			"������¼���",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGG[]=
{
	{	BPA_SWI_GG_CARDKEY,			"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_GG_BUS_NAME,		"ACBus_Name",	"���������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,			0,	NULL,	},
	{	BPA_SWI_GG_BUS_KV,			"ACBus_kV",		"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_GEN_ID,			"Gen_ID",		"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),				0,	NULL,	},
	{	BPA_SWI_GG_PMAX,			"Gen_Pmax",		"ԭ��������������(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_R,				"GG_R",			"����ϵ��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T1,				"GG_T1",		"����ʱ��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T2,				"GG_T2",		"ˮ�ֻ��ָ�ʱ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T3,				"GG_T3",		"�ŷ���ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T4,				"GG_T4",		"���ֻ���ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GG_T5,				"GG_T5",		"ˮ�ֻ�1/2��ˮ��ЧӦʱ�䳣��/���ֻ�������ʱ�䳣��",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GG_F,				"GG_F",			"ˮ�ֻ�F=��2;�����ֻ�F=������ǰ������/�ܵ�������",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GG_KEYNAME,			"KeyName",		"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_SWI_GG_BUSPTR,			"BusPtr",		"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),				0,	NULL,	},
	{	BPA_SWI_GG_APPENDTAG,		"AppendTag",	"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGH[]=
{
	{	BPA_SWI_GH_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GH_BUS_NAME,	"ACBus_Name",	"���������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GH_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_GEN_ID,		"Gen_ID",		"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GH_PMAX,		"Gen_Pmax",		"ԭ��������������(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_R,			"GH_R",			"����ϵ��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TG,			"GH_TG",		"��������Ӧʱ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TP,			"GH_TP",		"��������ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TD,			"GH_Td",		"����ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_TW_HALF,		"GH_Tw_Half",	"ˮ��ЧӦʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_VELCLOSE,	"GH_VELclose",	"���ˮ�Źر��ٶ�,ÿ���ô",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_VELOPEN,		"GH_VELopen",	"���ˮ�ſ����ٶ�,ÿ���ô",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_DD,			"GH_Dd",		"��������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_E,			"GH_E",			"����,Ϊ�����ϵͳƵ�ʵı�ôֵ",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GH_KEYNAME,		"KeyName",		"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GH_BUSPTR,		"BusPtr",		"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GH_APPENDTAG,	"AppendTag",	"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGC[]=
{
	{	BPA_SWI_GC_CARDKEY,			"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_GC_BUS_NAME,		"ACBus_Name",	"���������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,			0,	NULL,	},
	{	BPA_SWI_GC_BUS_KV,			"ACBus_kV",		"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_GEN_ID,			"Gen_ID",		"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),				0,	NULL,	},
	{	BPA_SWI_GC_PMAX,			"Gen_Pmax",		"ԭ��������������(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_R,				"GC_R",			"����ϵ��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T1,				"GC_T1",		"����ʱ��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T2,				"GC_T2",		"ˮ�ֻ��ָ�ʱ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T3,				"GC_T3",		"�ŷ���ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T4,				"GC_T4",		"���ֻ���ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_T5,				"GC_T5",		"���ֻ�������ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_F,				"GC_F",			"������ǰ������/�ܵ�������",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_DH,				"GC_DH",		"ת������Ľ���ֵ",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),				0,	NULL,	},
	{	BPA_SWI_GC_KEYNAME,			"KeyName",		"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,		0,	NULL,	},
	{	BPA_SWI_GC_BUSPTR,			"BusPtr",		"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),				0,	NULL,	},
	{	BPA_SWI_GC_APPENDTAG,		"AppendTag",	"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),		sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGS[]=
{
	{	BPA_SWI_GS_CARDKEY,		"CardKey",			"������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GS_BUS_NAME,	"ACBus_Name",		"���������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GS_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_GEN_ID,		"Gen_ID",			"�����ʶ����",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GS_PMAX,		"Gen_Pmax",			"ԭ��������������(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_PMIN,		"Gen_Pmin",			"ԭ������С�������(MW)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_R,			"GS_R",				"����ϵ��",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_T1,			"GS_T1",			"����ʱ��",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_T2,			"GS_T2",			"һ��Ϊ��",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_T3,			"GS_T3",			"�ŷ���ʱ�䳣��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_VELOPEN,		"GS_VELopen",		"�������ſ����ٶ�(ÿ���ô),��Ϊ����",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_VELCLOSE,	"GS_VELclose",		"�������Źر��ٶ�(ÿ���ô),��Ϊ����",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_E,			"GS_E",				"����,Ϊ�����ϵͳƵ�ʵı�ôֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GS_KEYNAME,		"KeyName",			"���ݿ�����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GS_BUSPTR,		"BusPtr",			"�����ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GS_APPENDTAG,	"AppendTag",		"������¼���",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGL[]=
{
	{	BPA_SWI_GL_CARDKEY,		"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GL_BUS_NAME,	"ACBus_Name",		"���������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GL_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_GEN_ID,		"Gen_ID",			"�����ʶ����",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GL_PE,			"GL_Pe",			"ԭ������������(MW)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_K,			"GL_K",				"ת�ٷŴ���(ϵͳ�ٶȱ䶯�ʵĵ���)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_E,			"GL_E",				"ϵͳ�ٻ���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TR,			"GL_Tr",			"������������ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TB,			"GL_Tb",			"�м们����ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TO,			"GL_To",			"�Ͷ�������ʱ�䳣��	",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_TC,			"GL_Tc",			"�Ͷ����ر�ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_VELCLOSE,	"GL_VELclose",		"���ر��ٶ�,��ô",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_VELOPEN,		"GL_VELopen",		"������ٶ�,��ô",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_PMAX,		"Gen_Pmax",			"���ԭ�����������,����ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_PMIN,		"Gen_Pmin",			"��Сԭ�����������,����ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GL_KEYNAME,		"KeyName",			"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GL_BUSPTR,		"BusPtr",			"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GL_APPENDTAG,	"AppendTag",		"������¼���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGW[]=
{
	{	BPA_SWI_GW_CARDKEY,		"CardKey",			"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GW_BUS_NAME,	"ACBus_Name",		"���������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GW_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_GEN_ID,		"Gen_ID",			"�����ʶ����",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GW_PMAX,		"Gen_Pmax",			"ԭ��������������(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_PMIN,		"Gen_Pmin",			"ԭ������С�������(MW)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_R,			"GW_R",				"����ϵ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_T1,			"GW_T1",			"����ʱ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_T2,			"GW_T2",			"һ��Ϊ��",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_T3,			"GW_T3",			"�ŷ���ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GW_KEYNAME,		"KeyName",			"���ݿ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GW_BUSPTR,		"BusPtr",			"�����ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GW_APPENDTAG,	"AppendTag",		"������¼���",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGA[]=
{
	{	BPA_SWI_GA_CARDKEY,			"CardKey",			"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GA_BUS_NAME,		"ACBus_Name",		"���������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GA_BUS_KV,			"ACBus_kV",			"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_GEN_ID,			"Gen_ID",			"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GA_PE,				"GA_Pe",			"ԭ������������(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_TC,				"GA_Tc",			"�Ͷ����ر�ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_TO,				"GA_To",			"�Ͷ�������ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_VELCLOSE,		"GA_VELclose",		"���ٹر�ϵ��(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_VELOPEN,			"GA_VELopen",		"���ٿ���ϵ��(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PMAX,			"Gen_Pmax",			"���ԭ�����������(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PMIN,			"Gen_Pmin",			"��Сԭ�����������(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_T1,				"GA_T1",			"�Ͷ����г̷�������(LVDT)ʱ��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KP,				"GA_KP",			"�����Ŵ���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KD,				"GA_KD",			"΢�ֱ���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KI,				"GA_KI",			"���ֱ���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_INTG_MAX,		"GA_INTG_MAX",		"��������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_INTG_MIN,		"GA_INTG_MIN",		"��������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PID_MAX,			"GA_PID_MAX",		"�������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PID_MIN,			"GA_PID_MIN",		"�������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_PGV_DELAY,		"GA_PGV_DELAY",		"��������źŵĴ�ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GA_KEYNAME,			"KeyName",			"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GA_BUSPTR,			"BusPtr",			"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GA_APPENDTAG,		"AppendTag",		"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGI[]=
{
	{	BPA_SWI_GI_CARDKEY,		"CardKey",			"������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GI_BUS_NAME,	"ACBus_Name",		"���������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GI_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_GEN_ID,		"Gen_ID",			"�����ʶ����",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GI_T1,			"GI_T1",			"ת�ٱ任����ʱ�䳣��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_E,			"GI_E",				"������(���ϵͳƵ�ʵı�ôֵ)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_K,			"GI_K",				"ת��ƫ��Ŵ���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_I1,			"GI_I1",			"�����Զ�����",								MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSwicth)/sizeof(tagMemDBEnumPair),	g_BpaEnumSwicth,	},
	{	BPA_SWI_GI_KP1,			"GI_KP1",			"���ɿ�����PID�������ڱ���",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KD1,			"GI_KD1",			"���ɿ�����PID΢�ֻ��ڱ���",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KI1,			"GI_KI1",			"���ɿ�����PID���ֻ��ڱ���",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MAX1,	"GI_INTG_MAX1",		"���ɿ�����PID���ֻ����޷�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MIN1,	"GI_INTG_MIN1",		"���ɿ�����PID���ֻ����޷�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MAX1,	"GI_PID_MAX1",		"���ɿ�����PID����޷����ڵ�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MIN1,	"GI_PID_MIN1",		"���ɿ�����PID����޷����ڵ�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_I_FEED,		"GI_I_Feed",		"����ǰ������λ��",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSwicth)/sizeof(tagMemDBEnumPair),	g_BpaEnumSwicth,	},
	{	BPA_SWI_GI_W_MAX,		"GI_W_MAX",			"һ�ε�Ƶ����",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_W_MIN,		"GI_W_MIN",			"һ�ε�Ƶ����",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_GI_I2,			"GI_I2",			"���ڼ�ѹ���Զ�����",						MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumSwicth)/sizeof(tagMemDBEnumPair),	g_BpaEnumSwicth,	},
	{	BPA_SWI_GI_KP2,			"GI_KP2",			"���ڼ�ѹ��������PID�������ڱ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KD2,			"GI_KD2",			"���ڼ�ѹ��������PID΢�ֻ��ڱ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_KI2,			"GI_KI2",			"���ڼ�ѹ��������PID���ֻ��ڱ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MAX2,	"GI_INTG_MAX2",		"���ڼ�ѹ��������PID���ֻ����޷�����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_INTG_MIN2,	"GI_INTG_MIN2",		"���ڼ�ѹ��������PID���ֻ����޷�����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MAX2,	"GI_PID_MAX2",		"���ڼ�ѹ��������PID����޷����ڵ�����",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_PID_MIN2,	"GI_PID_MIN2",		"���ڼ�ѹ��������PID����޷����ڵ�����",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_CON_MAX,		"GI_CON_MAX",		"�������ƻ�������޷����ڵ�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GI_CON_MIN,		"GI_CON_MIN",		"�������ƻ�������޷����ڵ�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_GI_KEYNAME,		"KeyName",			"���ݿ�����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GI_BUSPTR,		"BusPtr",			"�����ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GI_APPENDTAG,	"AppendTag",		"������¼���",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGJ[]=
{
	{	BPA_SWI_GJ_CARDKEY,		"CardKey",			"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GJ_BUS_NAME,	"ACBus_Name",		"���������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GJ_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_GEN_ID,		"Gen_ID",			"�����ʶ����",									MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GJ_T1,			"GJ_T1",			"ת�ٲ�������ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_E,			"GJ_E",				"ת��ƫ������",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_K1,			"GJ_K1",			"ת��ƫ��Ŵ���",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_I,			"GJ_I",				"���Ʒ�ʽѡ��",									MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGJ_ControlMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGJ_ControlMode,	},
	{	BPA_SWI_GJ_KP,			"GJ_KP",			"PID�������ڱ���",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_KD,			"GJ_KD",			"PID΢�ֻ��ڱ���",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_KI,			"GJ_KI",			"PID���ֻ��ڱ���",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_INTG_MAX,	"GJ_INTG_MAX",		"PID���ֻ����޷�����",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_INTG_MIN,	"GJ_INTG_MIN",		"PID���ֻ����޷�����",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_PID_MAX,		"GJ_PID_MAX",		"PID����޷����ڵ�����",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_PID_MIN,		"GJ_PID_MIN",		"PID����޷����ڵ�����",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_K2,			"GJ_K2",			"���ɿ���ǰ��ϵ��",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_W_MAX,		"GJ_W_MAX",			"һ�ε�Ƶ��������",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_W_MIN,		"GJ_W_MIN",			"һ�ε�Ƶ��������",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_TW_DELAY,	"GJ_TW_DELAY",		"Ƶ�������źŵĴ�ʱ��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_TP_DELAY,	"GJ_TP_DELAY",		"���ʷ����źŵĴ�ʱ��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_TR,			"GJ_TR",			"���ʷ����źŶ�Ӧ��һ�׹��Ի���ʱ�䳣��(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GJ_KEYNAME,		"KeyName",			"���ݿ�����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GJ_BUSPTR,		"BusPtr",			"�����ĸ������",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GJ_APPENDTAG,	"AppendTag",		"������¼���",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGK[]=
{
	{	BPA_SWI_GK_CARDKEY,		"CardKey",			"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GK_BUS_NAME,	"ACBus_Name",		"���������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GK_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_GEN_ID,		"Gen_ID",			"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GK_TW,			"GK_TW",			"ת��ƫ���˲�����ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_E,			"GK_E",				"ת��ƫ������",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_I,			"GK_I",				"ת�ٲ����˲�����������ʽѡ��",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGK_FilterDead)/sizeof(tagMemDBEnumPair),	g_BpaEnumGK_FilterDead,	},
	{	BPA_SWI_GK_K1,			"GK_K1",			"ת��ƫ��Ŵ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_K2,			"GK_K2",			"����ѹ��ƫ��Ŵ���",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_I_CONTROL,	"GK_I_Control",		"���Ʒ�ʽѡ��	",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGK_ControlMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGK_ControlMode,},
	{	BPA_SWI_GK_KP,			"GK_KP",			"PID�������ڱ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_KD,			"GK_KD",			"PID΢�ֻ��ڱ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_KI,			"GK_KI",			"PID���ֻ��ڱ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_INTG_MAX,	"GK_INTG_MAX",		"PID���ֻ����޷�����",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_INTG_MIN,	"GK_INTG_MIN",		"PID���ֻ����޷�����",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_PID_MAX,		"GK_PID_MAX",		"PID����޷����ڵ�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_PID_MIN,		"GK_PID_MIN",		"PID����޷����ڵ�����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_W_MAX,		"GK_W_MAX",			"һ�ε�Ƶ��������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_W_MIN,		"GK_W_MIN",			"һ�ε�Ƶ��������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GK_KEYNAME,		"KeyName",			"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GK_BUSPTR,		"BusPtr",			"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GK_APPENDTAG,	"AppendTag",		"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGM[]=
{
	{	BPA_SWI_GM_CARDKEY,			"CardKey",			"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GM_BUS_NAME,		"ACBus_Name",		"���������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GM_BUS_KV,			"ACBus_kV",			"�������׼��ѹ(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_GEN_ID,			"Gen_ID",			"�����ʶ����",									MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GM_KW,				"GM_KW",			"Ƶ��ƫ��Ŵ���",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_TR,				"GM_TR",			"Ƶ�ʲ�������ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_NEGATIVE_DB1,	"GM_Negative_DB1",	"ת�ٵ�������(������,����ڶƵ�ʵı�ôֵ)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB1,				"GM_DB1",			"ת�ٵ�������(������,����ڶƵ�ʵı�ôֵ)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_KP,				"GM_KP",			"PID�������ڷŴ���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_KD,				"GM_KD",			"PID΢�ֻ��ڷŴ���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_KI,				"GM_KI",			"PID���ֻ��ڷŴ���",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_TD,				"GM_TD",			"PID΢�ֻ���ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_INTG_MAX,		"GM_INTG_MAX",		"PID���ֻ����޷�����",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_INTG_MIN,		"GM_INTG_MIN",		"PID���ֻ����޷�����",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_PID_MAX,			"GM_PID_MAX",		"PID����޷����ڵ�����",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_PID_MIN,			"GM_PID_MIN",		"PID����޷����ڵ�����",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DELT,			"GM_DELT",			"DELT,ת�ٲ�����ʱ��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB_MAX,			"GM_DB_MAX",		"һ�ε�Ƶ����",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB_MIN,			"GM_DB_MIN",		"һ�ε�Ƶ����",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DELT2,			"GM_DELT2",			"����ʱ��(��)",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_TR2,				"GM_TR2",			"��������ʱ�䳣��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_EP,				"GM_EP",			"ϵ��",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_NEGATIVE_DB2,	"GM_Negative_DB2",	"����������",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DB2,				"GM_DB2",			"����������",									MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DBMAX2,			"GM_DBMAX2",		"�޷�����",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_DBMIN2,			"GM_DBMIN2",		"�޷�����",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GM_ITYP,			"GM_ITYP",			"ģʽѡ��",										MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGM_Mode)/sizeof(tagMemDBEnumPair),		g_BpaEnumGM_Mode,		},
	{	BPA_SWI_GM_ITYP2,			"GM_ITYP2",			"����ģʽѡ��",									MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGM_OpenMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGM_OpenMode,	},
	{	BPA_SWI_GM_KEYNAME,			"KeyName",			"���ݿ�����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GM_BUSPTR,			"BusPtr",			"�����ĸ������",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GM_APPENDTAG,		"AppendTag",		"������¼���",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_GovGD[]=
{
	{	BPA_SWI_GD_CARDKEY,		"CardKey",			"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GD_BUS_NAME,	"ACBus_Name",		"���������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GD_BUS_KV,		"ACBus_kV",			"�������׼��ѹ(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_GEN_ID,		"Gen_ID",			"�����ʶ����",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GD_PMAX,		"GD_Pmax",			"��������е����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_PMIN,		"GD_Pmin",			"��С�����е����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_DB,			"GD_DB",			"���ص�����(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_R,			"GD_R",				"��̬ƫ��(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KP,			"GD_Kp",			"������������(pu/pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KI,			"GD_Ki",			"���ֻ�������(pu/sec)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KD,			"GD_Kd",			"΢�ֻ�������(pu��sec)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_GOV_MAX,		"GD_GOV_MAX",		"���ֻ�������(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_GOV_MIN,		"GD_GOV_Min",		"���ֻ�������(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_DEMAND_MAX,	"GD_DEMAND_MAX",	"�������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_DEMAND_MIN,	"GD_DEMAND_MIN",	"�������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GD_KEYNAME,		"KeyName",			"���ݿ�����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GD_BUSPTR,		"BusPtr",			"�����ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GD_APPENDTAG,	"AppendTag",		"������¼���",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GovGZ[]=
{
	{	BPA_SWI_GZ_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GZ_BUS_NAME,	"ACBus_Name",	"���������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GZ_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_GEN_ID,		"Gen_ID",		"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GZ_TSM,			"GZ_Tsm",		"�ŷ�ϵͳʱ�䳣��(��)	",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_ROPEN,		"GZ_Ropen",		"����������ٶ�(p.u.gate/sec)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_RCLOSE,		"GZ_Rclose",	"�������ر��ٶ�(p.u.gate/sec)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_EHC_MAX,		"GZ_EHC_MAX",	"EHC���λ������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_EHC_MIN,		"GZ_EHC_MIN",	"EHC��Сλ������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_T_OPEN,		"GZ_T_Open",	"���Ʒ�����ʱ�䳣��(sec)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_T_CLOSE,		"GZ_T_Close",	"���Ʒ��ر�ʱ�䳣��(sec)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_DB_VALUE,	"GZ_DB_Value",	"��������(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_CV_MAX,		"GZ_CV_MAX",	"��������(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_CV_MIN,		"GZ_CV_MIN",	"���Ʒ�����(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_KPE,			"GZ_Kpe",		"��Ź��ʷ�������(pu/pu)	",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_TPE,			"GZ_Tpe",		"��Ź��ʷ���ʱ�䳣��(sec)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GZ_MODE,		"GZ_Mode",		"����ģʽ",							MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumGZ_ControlMode)/sizeof(tagMemDBEnumPair),	g_BpaEnumGZ_ControlMode,	},
	{	BPA_SWI_GZ_KEYNAME,		"KeyName",		"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GZ_BUSPTR,		"BusPtr",		"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_GZ_APPENDTAG,	"AppendTag",	"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TA[]=
{
	{	BPA_SWI_TA_CARDKEY,		"CardKey",		"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TA_BUS_NAME,	"ACBus_Name",	"���������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TA_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TA_GEN_ID,		"Gen_ID",		"�����ʶ����",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TA_TCH,			"TA_TCH",		"�����ݻ�ʱ�䳣��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TA_K1,			"TA_K1",		"���ֻ�K1=1.0;ˮ�ֻ�K1=-2.0(����)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TA_KEYNAME,		"KeyName",		"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TA_BUSPTR,		"BusPtr",		"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TA_APPENDTAG,	"AppendTag",	"������¼���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TB[]=
{
	{	BPA_SWI_TB_CARDKEY,		"CardKey",		"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TB_BUS_NAME,	"ACBus_Name",	"���������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TB_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_GEN_ID,		"Gen_ID",		"�����ʶ����",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TB_TCH,			"TB_TCH",		"�����ݻ�ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_FHP,			"TB_FHP",		"��ѹ�׹��ʱ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_TRH,			"TB_TRH",		"������ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_FIP,			"TB_FIP",		"��ѹ�׹��ʱ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_TCO,			"TB_TCO",		"�����ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_FLP,			"TB_FLP",		"��ѹ�׹��ʱ��������",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_LAMBDA,		"TB_Lambda",	"��ѹ�׹�����Ȼ����ϵ��",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TB_KEYNAME,		"KeyName",		"���ݿ�����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TB_BUSPTR,		"BusPtr",		"�����ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TB_APPENDTAG,	"AppendTag",	"������¼���",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_TC[]=
{
	{	BPA_SWI_TC_CARDKEY,		"CardKey",		"������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TC_BUS_NAME,	"ACBus_Name",	"���������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TC_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_GEN_ID,		"Gen_ID",		"�����ʶ����",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TC_TCH,			"TC_TCH",		"�����ݻ�ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FVHP,		"TC_FVHP",		"����ѹ�׹��ʱ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_TRH1,		"TC_TRH1",		"��һ������ʱ�䳣��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FHP,			"TC_FHP",		"��ѹ�׹��ʱ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_TRH2,		"TC_TRH2",		"�ڶ�������ʱ�䳣��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FIP,			"TC_FIP",		"��ѹ�׹��ʱ��������",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_TCO,			"TC_TCO",		"�����ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_FLP,			"TC_FLP",		"��ѹ�׹��ʱ��������",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TC_KEYNAME,		"KeyName",		"���ݿ�����",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TC_BUSPTR,		"BusPtr",		"�����ĸ������",			MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TC_APPENDTAG,	"AppendTag",	"������¼���",				MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_TD[]=
{
	{	BPA_SWI_TD_CARDKEY,		"CardKey",		"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TD_BUS_NAME,	"ACBus_Name",	"���������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TD_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_GEN_ID,		"Gen_ID",		"�����ʶ����",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TD_TCH,			"TD_TCH",		"�����ݻ�ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FHP,			"TD_FHP",		"��ѹ�׹��ʱ���",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_TRH,			"TD_TRH",		"������ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FIP,			"TD_FIP",		"��ѹ�׹��ʱ���",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_TCO,			"TD_TCO",		"�����ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FLP_1,		"TD_FLP_1",		"��ѹ�׹��ʱ����������һ��",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_FLP_2,		"TD_FLP_2",		"��ѹ�׹��ʱ����������һ��",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TD_KEYNAME,		"KeyName",		"���ݿ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TD_BUSPTR,		"BusPtr",		"�����ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TD_APPENDTAG,	"AppendTag",	"������¼���",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TE[]=
{
	{	BPA_SWI_TE_CARDKEY,		"CardKey",		"������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TE_BUS_NAME,	"ACBus_Name",	"���������",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TE_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",	MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_GEN_ID,		"Gen_ID",		"�����ʶ����",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TE_TCH,			"TE_TCH",		"�����ݻ�ʱ�䳣��(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_FHP,			"TE_FHP",		"��ѹ�׹��ʱ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_TRH,			"TE_TRH",		"������ʱ�䳣��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_FIP,			"TE_FIP",		"��ѹ�׹��ʱ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_TCO,			"TE_TCO",		"�����ʱ�䳣��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_FLP,			"TE_FLP",		"��ѹ�׹��ʱ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TE_KEYNAME,		"KeyName",		"���ݿ�����",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TE_BUSPTR,		"BusPtr",		"�����ĸ������",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TE_APPENDTAG,	"AppendTag",	"������¼���",			MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_TF[]=
{
	{	BPA_SWI_TF_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TF_BUS_NAME,	"ACBus_Name",	"���������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TF_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_GEN_ID,		"Gen_ID",		"�����ʶ����",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TF_TCH,			"TF_TCH",		"�����ݻ�ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FVHP,		"TF_FVHP",		"����ѹ�׹��ʱ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_TRH1,		"TF_TRH1",		"��һ������ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FHP,			"TF_FHP",		"��ѹ�׹��ʱ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_TRH2,		"TF_TRH2",		"�ڶ�������ʱ�䳣��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FIP_1,		"TF_FIP_1",		"��ѹ�׹��ʱ��������һ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FIP_2,		"TF_FIP_2",		"��ѹ�׹��ʱ��������һ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_TCO,			"TF_TCO",		"�����ʱ�䳣��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FLP_1,		"TF_FLP_1",		"��ѹ�׹��ʱ��������һ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_FLP_2,		"TF_FLP_2",		"��ѹ�׹��ʱ��������һ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TF_KEYNAME,		"KeyName",		"���ݿ�����",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TF_BUSPTR,		"BusPtr",		"�����ĸ������",					MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TF_APPENDTAG,	"AppendTag",	"������¼���",						MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};

static	tagMemDBField	dicFieldBpaSwi_TW[]=
{
	{	BPA_SWI_TW_CARDKEY,		"CardKey",		"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_TW_BUS_NAME,	"ACBus_Name",	"���������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_TW_BUS_KV,		"ACBus_kV",		"�������׼��ѹ(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_GEN_ID,		"Gen_ID",		"�����ʶ����",							MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_TW_K1,			"TW_K1",		"���ֻ�K1=1.0;ˮ�ֻ�K1=-2.0(����)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_HALF,		"TW_Tw_Half",	"ˮ��ЧӦʱ�䳣��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_K3,			"TW_K3",		"K3=3.0(����)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_TW_KEYNAME,		"KeyName",		"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_TW_BUSPTR,		"BusPtr",		"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_TW_APPENDTAG,	"AppendTag",	"������¼���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumNoYes)/sizeof(tagMemDBEnumPair),	g_BpaEnumNoYes,	},
};


static	tagMemDBField	dicFieldBpaSwi_GX[]=
{
	{	BPA_SWI_GX_CARDKEY,				"CardKey",			"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_GX_BUS_NAME,			"ACBus_Name",		"���������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_GX_BUS_KV,				"ACBus_KV",			"�������׼��ѹ(kV)",			MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_GEN_ID,				"Gen_ID",			"�����ʶ����ID",				MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_GX_TSH,					"GX_TSH",			"�������ݻ�ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_TD,					"GX_TD",			"���������ݻ�ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_TW,					"GX_TW",			"��¯ȼ���ͷŵ�ʱ�䳣��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_K,					"GX_K",				"�������������ܵ�����ϵ��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_TDELAY,				"GX_Tdelay",		"��ʱ",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_LIMIT_MAX,			"GX_Limit_MAX",		"����޷����ڵ����ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_LIMIT_MIN,			"GX_Limit_MIN",		"����޷�������Сֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_GX_KEYNAME,				"KeyName",			"���ݿ�����",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_GX_BUSPTR,				"BusPtr",			"�����ĸ������",				MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_IGV[]=
{
	{	BPA_SWI_IGV_CARDKEY,		"CardKey",		"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_IGV_BUS_NAME,		"ACBus_Name",	"���������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_IGV_BUS_KV,			"ACBus_KV",		"�������׼��ѹ(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_GEN_ID,			"Gen_ID",		"�����ʶ����ID",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_IGV_TSTART,			"IGV_Tstart",	"Ƶ�ʱ仯����ʼʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T1,				"IGV_T1",		"��1�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ1,			"IGV_FREQ1",	"��1�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T2,				"IGV_T2",		"��2�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ2,			"IGV_FREQ2",	"��2�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T3,				"IGV_T3",		"��3�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ3,			"IGV_FREQ3",	"��3�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T4,				"IGV_T4",		"��4�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ4,			"IGV_FREQ4",	"��4�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T5,				"IGV_T5",		"��5�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ5,			"IGV_FREQ5",	"��5�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T6,				"IGV_T6",		"��6�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ6,			"IGV_FREQ6",	"��6�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T7,				"IGV_T7",		"��7�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ7,			"IGV_FREQ7",	"��7�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T8,				"IGV_T8",		"��8�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ8,			"IGV_FREQ8",	"��8�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T9,				"IGV_T9",		"��9�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ9,			"IGV_FREQ9",	"��9�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T10,			"IGV_T10",		"��10�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ10,			"IGV_FREQ10",	"��10�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_T11,			"IGV_T11",		"��11�����Ӧ��ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_FREQ11,			"IGV_FREQ11",	"��11�����Ӧ��Ƶ�ʱ仯��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_IGV_KEYNAME,		"KeyName",		"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_IGV_BUSPTR,			"BusPtr",		"�����ĸ������",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_FGV[]=
{
	{	BPA_SWI_FGV_CARDKEY,		"CardKey",			"������",																MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_FGV_BUS_NAME,		"ACBus_Name",		"���������",															MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_FGV_BUS_KV,			"ACBus_KV",			"�������׼��ѹ(kV)",													MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_GEN_ID,			"Gen_ID",			"�����ʶ����ID",														MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_FGV_AMP1,			"FGV_AMP1",			"��һ�������ķ�ֵ,�ٷ���������ֵ",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_FREQ1,			"FGV_FREQ1",		"��һ��������Ƶ��(����/��)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_ANGL01,			"FGV_ANGL01",		"��һ�������ĳ�ʼ��λ(����)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TBEGIN1,		"FGV_TBEGIN1",		"��һ����������ʼʱ��(��)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TEND1,			"FGV_TEND1",		"��һ�������Ľ���ʱ��(��)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_AMP2,			"FGV_AMP2",			"�ڶ��������ķ�ֵ,�ٷ���������ֵ",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_FREQ2,			"FGV_FREQ2",		"�ڶ���������Ƶ��(����/��)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_ANGL02,			"FGV_ANGL02",		"�ڶ��������ĳ�ʼ��λ(����)",											MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TBEGIN2,		"FGV_TBEGIN2",		"�ڶ�����������ʼʱ��(��)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_TEND2,			"FGV_TEND2",		"�ڶ��������Ľ���ʱ��(��)",												MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_FGV_CMW,			"FGV_CMW",			"�ո��ʾǰ���������ķ�ֵ���Ƿ������е���ʳ�ֵ�İٷ���;W,Ϊ����ֵ",	MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_FGV_KEYNAME,		"KeyName",			"���ݿ�����",															MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_FGV_BUSPTR,			"BusPtr",			"�����ĸ������",														MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LO[]=
{
	{	BPA_SWI_LO_CARDKEY,			"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LO_BUSI,			"LO_BusI",			"ĸ������1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LO_KVI,				"LO_kVI",			"��׼��ѹ1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_BUSJ,			"LO_BusJ",			"ĸ������2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LO_KVJ,				"LO_kVJ",			"��׼��ѹ2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_LOOP,			"LO_Loop",			"������·�Ļ�·��־",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LO_R0,				"LO_R0",			"��·�������(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_X0,				"LO_X0",			"��·����翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_GA0,				"LO_Ga0",			"��·BUSA������Եص絼(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_BA0,				"LO_Ba0",			"��·BUSA������Եص���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_GB0,				"LO_Gb0",			"��·BUSB������Եص絼(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_BB0,				"LO_Bb0",			"��·BUSB������Եص���(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LO_KEYNAME,			"KeyName",			"��·����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_XO[]=
{
	{	BPA_SWI_XO_CARDKEY,			"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_XO_BUSI,			"XO_BusI",			"ĸ������1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_XO_KVI,				"XO_kVI",			"��׼��ѹ1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_BUSJ,			"XO_BusJ",			"ĸ������2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_XO_KVJ,				"XO_kVJ",			"��׼��ѹ2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_LOOP,			"XO_Loop",			"������·�Ļ�·��־",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_XO_SID,				"XO_SID",			"��ѹ������翹�Ľ��뷽ʽ",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_XO_R0,				"XO_R0",			"��ѹ���������(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_X0,				"XO_X0",			"��ѹ������翹(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XO_KEYNAME,			"KeyName",			"��ѹ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LOHG[]=
{
	{	BPA_SWI_LOHG_CARDKEY,		"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LOHG_BUSI,			"LOHG_BusI",		"ĸ������1",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LOHG_KVI,			"LOHG_kVI",			"��׼��ѹ1(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_BUSJ,			"LOHG_BusJ",		"ĸ������2",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LOHG_KVJ,			"LOHG_kVJ",			"��׼��ѹ2(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_LOOP,			"LOHG_Loop",		"������·�Ļ�·��־",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LOHG_X0I,			"LOHG_X0I",			"��·ǰ��߿���Ӧ�ĵ�ֵ����翹(pu)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_X0J,			"LOHG_X0J",			"��·���߿���Ӧ�ĵ�ֵ����翹(pu)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LOHG_KEYNAME,		"KeyName",			"��·�߿�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_XR[]=
{
	{	BPA_SWI_XR_CARDKEY,			"CardKey",				"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_XR_NAME,			"ACBus_Name",			"ĸ������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_XR_KV,				"ACBus_kV",				"��׼��ѹ(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XR_R0,				"XR_R0",				"�Ե�֧·�������(PU)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_XR_X0,				"XR_X0",				"�Ե�֧·����翹(PU)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_D[]=
{
	{	BPA_SWI_D_CARDKEY,			"CardKey",			"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_D_BUS_NAME,			"DCBus_Name",		"ֱ��ĸ������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_D_BUS_KV,			"DCBus_KV",			"ֱ��ĸ�߻�׼��ѹ(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_Tc,				"D_Tc",				"������������ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_Tv,				"D_Tv",				"��ѹ��������ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_T1,				"D_T1",				"����������ʱ�䳣��1(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_T2,				"D_T2",				"����������ʱ�䳣��2(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_T3,				"D_T3",				"����������ʱ�䳣��3(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_Ka,				"D_Ka",				"��������������",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_MOD,				"D_MOD",			"���Ʒ�ʽ,P�������ʿ���,I������������",			MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_D_IMAX,				"D_IMAX",			"���Ĺ���������(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_IMARGIN,			"D_IMARGIN",		"������ԣֵ(pu),���������0.05-0.3֮��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_ALPHASTOP,		"D_ALPHASTOP",		"�������ʹ��ʱ����С��ȼ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_TD,				"D_TD",				"�����ѹʱ�䳣��(��),ȱʡ0.01��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_VLIM,				"D_VLIM",			"����������ʼ���Ķ�˵�ѹ(pu),ȱʡ0.25pu",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_D_DISA,				"D_DISA",			"�ǿ�����ȥ��ֱ������ϵͳ",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_D_MSU,				"D_MSU",			"��ԣ���ص�Ԫ�ؼ���",							MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_D_KEYNAME,			"KeyName",			"���ݿ�����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_D_BUSPTR,			"BusPtr",			"ֱ��ĸ������",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_DT[]=
{
	{	BPA_SWI_DT_CARDKEY,			"CardKey",			"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DT_BUS_NAME,		"DCBus_Name",		"ֱ��ĸ������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_DT_BUS_KV,			"DCBus_KV",			"ֱ��ĸ�߻�׼��ѹ(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DT_DV,				"DT_DV",			"���ؽضϵ�ѹֵ(��ôֵ)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DT_IMAX,			"DT_IMAX",			"����������(��ôֵ)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DT_IMARGIN,			"DT_IMARG",			"������ԣֵ(��ôֵ)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DT_TC,				"DT_Tc",			"����������·ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DT_TV,				"DT_Tv",			"��ѹ������·ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DT_ALPHASTOP,		"DT_AlphaStop",		"�������С��ȼ��",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DT_MSU,				"DT_MSU",			"��ԣ���ص�Ԫ�ؼ���",							MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_DT_KEYNAME,			"KeyName",			"���ݿ�����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_DT_BUSPTR,			"BusPtr",			"ֱ��ĸ������",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_DF[]=
{
	{	BPA_SWI_DF_CARDKEY,			"CardKey",			"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DF_BUS_NAME,		"DCBus_Name",		"ֱ��ĸ������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_DF_BUS_KV,			"DCBus_KV",			"ֱ��ĸ�߻�׼��ѹ(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_DVDT,			"DF_DVDT",			"ֱ��ϵͳ���ܷ�������ʧ�ܵĵ�ѹ�仯�ʵ��ż�ֵ",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_VF1,				"DF_Vf1",			"ֱ��ϵͳ���ܷ�������ʧ�ܵĵ�ѹ���ż�ֵ",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_VF2,				"DF_Vf2",			"ֱ��ϵͳ���ܷ�������ʧ�ܵĵ�ѹ���ż�ֵ",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_DT,				"DF_DT",			"����ʧ�ܷ�����ֱ��ϵͳ������ʱ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_VRS,				"DF_Vrs",			"ֱ��ϵͳ�ָ�����ĵ�ѹ���ż�ֵ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_C1,				"DF_C1",			"�ӻָ����ൽT1ʱ��(��)ֱ�����ʻָ��İٷ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_T1,				"DF_T1",			"T1ʱ��",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_C2,				"DF_C2",			"�ӻָ����ൽT2ʱ��(��)ֱ�����ʻָ��İٷ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_T2,				"DF_T2",			"T2ʱ��",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_C3,				"DF_C3",			"�ӻָ����ൽT3ʱ��(��)ֱ�����ʻָ��İٷ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_T3,				"DF_T3",			"T3ʱ��",										MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DF_KEYNAME,			"KeyName",			"���ݿ�����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_DF_BUSPTR,			"BusPtr",			"ֱ��ĸ������",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_DM[]=
{
	{	BPA_SWI_DM_CARDKEY,			"CardKey",			"������",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DM_BUS_NAME,		"DCBus_Name",		"ֱ��ĸ������",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_DM_BUS_KV,			"DCBus_KV",			"ֱ��ĸ�߻�׼��ѹ(kV)",									MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_MOD,				"DM_MOD",			"MOD,P=�㹦�ʿ���,I=���������",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_DM_TVP,				"DM_Tvp",			"�����๦�ʶ�ֵ������ֱ����ѹ��������ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_IMAX,			"DM_IMAX",			"���Ĺ���������(��ôֵ,��������д)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_IMIN,			"DM_IMIN",			"������С����(��ôֵ,��������д)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_TIDMES,			"DM_Tidmes",		"ֱ��������������ʱ�䳣��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_KP_I,			"DM_Kp_I",			"�������������ı�������",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_TI_I,			"DM_Ti_I",			"�������������Ļ���ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_MAX_I,			"DM_Max_I",			"���������������������(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_MIN_I,			"DM_Min_I",			"���������������������(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_TGAMMES,			"DM_TGamMes",		"����ò�������ʱ�䳣��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_KP_GAM,			"DM_Kp_Gam",		"���ඨ�õ������ı�������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_TI_GAM,			"DM_Ti_Gam",		"���ඨ�õ������Ļ���ʱ�䳣��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_MAX_GAM,			"DM_Max_Gam",		"���ඨ�õ��������������(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_MIN_GAM,			"DM_Min_Gam",		"���ඨ�õ��������������(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_TVPSMPALL,		"DM_TvpSmpall",		"�����๦�ʶ�ֵ������ֱ����ѹ��������Сʱ�䳣��(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_DISA,			"DM_DISA",			"�ǿ�����ȥ��ֱ������ϵͳ",								MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_DM_TVDCOL,			"DM_TVDCOL",		"VDCOL���ڵ�ѹ��������ʱ�䳣��(��,������д)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_X1,				"DM_X1",			"VDCOL��x1(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_Y1,				"DM_Y1",			"VDCOL��y1(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_X2,				"DM_X2",			"VDCOL��x2(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_Y2,				"DM_Y2",			"VDCOL��y2(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_K1,				"DM_K1",			"VDCOL��б��1(��ôֵ,������д)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_K2,				"DM_K2",			"VDCOL��б��2(��ôֵ,������д)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_DOWNSL,			"DM_DownSL",		"VDCOL���ֵ���½���������(pu/sec.,������д)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_UPSL,			"DM_UpSL",			"VDCOL���ֵ��������������(ֵ������,pu/sec.,������д)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_GAMMAMIN,		"DM_GammaMin",		"���������ʧ�ܵ��ż�ֵ(��,������д)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_IMARGIN,			"DM_Imargin",		"����ԣ��(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DM_DGAMMIN,			"DM_DGamMin",		"����ýǵ����ƫ������(��,������д)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_DM_KEYNAME,			"KeyName",			"���ݿ�����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_DM_BUSPTR,			"BusPtr",			"ֱ��ĸ������",											MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_DN[]=
{
	{	BPA_SWI_DN_CARDKEY,			"CardKey",			"������",												MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DN_BUS_NAME,		"DCBus_Name",		"ֱ��ĸ������",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_DN_BUS_KV,			"DCBus_KV",			"ֱ��ĸ�߻�׼��ѹ(kV)",									MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_MOD,				"DN_MOD",			"MOD,P=�㹦�ʿ���,I=���������",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_DN_TVP,				"DN_Tvp",			"�����๦�ʶ�ֵ������ֱ����ѹ��������ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_IMAX,			"DN_IMAX",			"ϵͳ����ʱ����������(��ôֵ,��������д)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_IMIN,			"DN_IMIN",			"ϵͳ����С����(��ôֵ,��������д)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_P_I,				"DN_P_I",			"�������������ı�������",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_T_I,				"DN_T_I",			"�������������Ļ���ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_P_U,				"DN_P_U",			"����ѹ�������ı�������",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_T_U,				"DN_T_U",			"����ѹ�������Ļ���ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_P_GAM,			"DN_P_Gam",			"���ඨ�õ������ı�������(������д)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_T_GAM,			"DN_T_Gam",			"���ඨ�õ������Ļ���ʱ�䳣��(��,������д)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_VACLOW,			"DN_VacLow",		"�޷���·�н�����ѹ�ż�ֵ(��ôֵ)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_TVACLOW,			"DN_TVacLow",		"�޷���·�н�����ѹ���ӳ�ʱ��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_IDLOW,			"DN_IdLow",			"�޷���·��ֱ�������ż�ֵ(��ôֵ)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_TIDLOW,			"DN_TIdLow",		"�޷���·��ֱ���������ӳ�ʱ��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_TLIM,			"DN_Tlim",			"�޷���·��ʱ�䳣��(��)",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_TP,				"DN_Tp",			"������������·��ʱ�䳣��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_IOVL,			"DN_Iovl",			"ֱ��ϵͳ���ڹ���������(��ôֵ,��������д)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_TIMAX,			"DN_Timax",			"ֱ��ϵͳ��ʱ������������ʱ��(��,��������д)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_TMAXLIM,			"DN_Tmaxlim",		"������ʱ������������ʱ���,������ֵ��Imax�½���Iovl��ʱ��(��,��������д)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_DISA,			"DN_DISA",			"����ǿ��ҷ��ַ�'F',����ȥ��ֱ������ϵͳ(��Ϊ��������)",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_DN_TVDCOL,			"DN_TVDCOL",		"VDCOL���ڵ�ѹ��������ʱ�䳣��(��,������д)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_X1,				"DN_X1",			"VDCOL��x1(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_Y1,				"DN_Y1",			"VDCOL��y1(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_X2,				"DN_X2",			"VDCOL��x2(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_Y2,				"DN_Y2",			"VDCOL��y2(��ôֵ,������д)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_K1,				"DN_K1",			"VDCOL��б��1(��ôֵ,������д)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_K2,				"DN_K2",			"VDCOL��б��2(��ôֵ,������д)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_DOWNSL,			"DN_DownSL",		"VDCOL���ֵ���½���������(pu/sec.,������д)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_UPSL,			"DN_UpSL",			"VDCOL���ֵ��������������(ֵ������,pu/sec.,������д)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_ALPHASTOP,		"DN_AlphaStop",		"�������ʹ��ʱ����С��ȼ��(��) ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_GAMAAMIN,		"DN_GamaaMin",		"���������ʧ�ܵ��ż�ֵ(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DN_TVPSMALL,		"DN_TvpSmall",		"�����๦�ʶ�ֵ������ֱ����ѹ�������ڵ�Сʱ�䳣��(��,��������д)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	BPA_SWI_DN_KEYNAME,			"KeyName",			"���ݿ�����",											MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_DN_BUSPTR,			"BusPtr",			"ֱ��ĸ������",											MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_DA[]=
{
	{	BPA_SWI_DA_CARDKEY,			"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DA_BUS_NAME,		"DCBus_Name",		"ֱ��ĸ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_DA_BUS_KV,			"DCBus_KV",			"ֱ��ĸ�߻�׼��ѹ(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_G_AMAX,			"DA_G_Amax",		"��󴥷��ǿ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_T_AMAX,			"DA_T_Amax",		"��󴥷��ǿ���ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_GAMMAREF,		"DA_GammaRef",		"Ϩ���ǲο�ֵ",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_GAMMAMIN,		"DA_GammaMin",		"Ϩ������Сֵ",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_KP_VCA,			"DA_Kp_vca",		"����ѹ���Ʊ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_TI_VCA,			"DA_Ti_vca",		"����ѹ���ƻ���ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_K1_RA,			"DA_K1_ra",			"��������С�����ǿ�������1",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_K2_RA,			"DA_K2_ra",			"��������С�����ǿ�������2",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_CDL,				"DA_Cdl",			"��������С�����ǿ��Ƶ�ѹ��ֵ1",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_D1,				"DA_D1",			"��������С�����ǿ��Ƶ�ѹ��ֵ2",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_DECR,			"DA_Decr",			"��������С�����ǿ��ƽǶ��½�����",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_T_GA,			"DA_T_ga",			"����Gamma0������ʱʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_TD_RET,			"DA_Td_ret",		"ֱ������������������ʱʱ��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_TH_RET,			"DA_Th_ret",		"ֱ�������������������ʱ��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_TH_RES,			"DA_Th_res",		"ֱ����������������ָ����ʱʱ��(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_DISA,			"DA_DISA",			"�ǿ�����ȥ��ֱ������ϵͳ",				MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_DA_DBG,				"DA_DBG",			"�����ļ���־,�ǿ�����������ļ�",		MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_DA_MOD,				"DA_MOD",			"���Ʒ�ʽ,1=�㶨����,0=�㶨����",		MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DA_LEAD,			"DA_LEAD",			"����վ,1=����վ,0=�ܿ�վ",				MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DA_OPN,				"DA_OPN",			"���б�־,1=����״̬,0=ͣ��״̬",		MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DA_BC_ON,			"DA_BC_ON",			"Э�����Ʊ�־,1=˫��Э��,0=��������",	MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_DA_UDLOW,			"DA_Udlow",			"VDCOL������ѹ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_UDHIGH,			"DA_Udhigh",		"VDCOL�˳���ѹ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_UDTUP,			"DA_Udtup",			"VDCOL��ѹ�����˲�ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_UDTDN,			"DA_Udtdn",			"VDCOL��ѹ�½��˲�ʱ�䳣��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_IOMIN_VDCL,		"DA_Iomin_vdcl",	"VDCOL��С��ֵ����ָ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_IOMIN,			"DA_Iomin",			"VDCOL��С����ָ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_ID_T,			"DA_Id_t",			"���������Ƶ����˲�ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_GAIN,			"DA_Gain",			"����������������",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_KP,				"DA_Kp",			"���������Ʊ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_TI,				"DA_Ti",			"���������ƻ���ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_G_CF,			"DA_G_cf",			"����ʧ��Ԥ������",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_K_CF,			"DA_K_cf",			"����ʧ��Ԥ��������ѹ��ֵ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_T_DN_CF,			"DA_T_dn_cf",		"����ʧ��Ԥ������Ƕ��½�ʱ�䳣��(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_DA_A,				"DA_A",				"DA��������־",							MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},

	{	BPA_SWI_DA_KEYNAME,			"KeyName",			"���ݿ�����",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_DA_BUSPTR,			"BusPtr",			"ֱ��ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_V[]=
{
	{	BPA_SWI_V_CARDKEY,			"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_V_BUS_NAME,			"ACBus_Name",		"ĸ������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_V_BUS_KV,			"ACBus_KV",			"ĸ�߻�׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_ID,				"ID",				"����֧·ʶ����",						MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_V_TS1,				"TS1",				"�˲���ʱ�䳣��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_VEMAX,			"VEMAX",			"����ѹƫ��(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS2,				"TS2",				"��һ����ǰʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS3,				"TS3",				"��һ���ͺ�ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_A,				"A",				"��ǰʶ����(����Ϊ0)",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_V_B,				"B",				"�ͺ�ʶ����(����Ϊ0)",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	0,	NULL,	},
	{	BPA_SWI_V_TS4,				"TS4",				"�ڶ�����ǰʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS5,				"TS5",				"�ڶ����ͺ�ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_KSVS,				"KSVS",				"������������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_KSD,				"KSD",				"��Ͽ�������",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BMAX,				"BMAX",				"�����(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BPMAX,			"BPMAX",			"�������Ƶ������(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BPMIN,			"BPMIN",			"�������Ƶ���С����(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_BMIN,				"BMIN",				"��С����(pu)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_TS6,				"TS6",				"�ɿع�(Thyristor)����ʱ��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_DV,				"DV",				"��ѹƫ��",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_CON_NAME,			"CON_NAME",			"����ĸ����",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_V_CON_KV,			"CON_KV",			"����ĸ�߻�׼��ѹ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_V_KEYNAME,			"KeyName",			"���ݿ�����",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_V_BUSPTR,			"BusPtr",			"ĸ������",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_VG[]=
{
	{	BPA_SWI_VG_CARDKEY,			"CardKey",			"������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_VG_BUS_NAME,		"ACBus_Name",		"ĸ������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_VG_BUS_KV,			"ACBus_KV",			"ĸ�߻�׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_MVABASE,			"MvaBase",			"�����",								MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T1,				"T1",				"�˲����Ͳ�����·��ʱ�䳣��(��)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T2,				"T2",				"��һ����ǰʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T3,				"T3",				"��һ���ͺ�ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T4,				"T4",				"�ڶ�����ǰʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_T5,				"T5",				"�ڶ����ͺ�ʱ�䳣��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_TP,				"TP",				"��������ʱ�䳣��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_TS,				"TS",				"STATCOM��Ӧ�ӳ�(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KP,				"KP",				"�������ڷŴ���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KI,				"KI",				"���ֻ��ڵķŴ���",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KD,				"KD",				"STATCOM��V-I�������ߵ�б��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_XT,				"XT",				"STATCOM��ϵͳ֮��ĵ�ֵ�翹(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_VMAX,			"VMAX",				"��ѹ�޷����ڵ�����(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_VMIN,			"VMIN",				"��ѹ�޷����ڵ�����(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_ICMAX,			"ICMAX",			"������Ե���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_ILMAX,			"ILMAX",			"�����Ե���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_VSTANDBY,		"VSTANDBY",			"��ϵͳ�����Ľڵ��ѹ���ڴ�ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_CON_NAME,		"CON_NAME",			"����ĸ����",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_VG_CON_KV,			"CON_KV",			"����ĸ�߻�׼��ѹ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_VG_KEYNAME,			"KeyName",			"���ݿ�����",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_VG_BUSPTR,			"BusPtr",			"ĸ������",								MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LAB[]=
{
	{	BPA_SWI_LAB_CARDKEY,	"CardKey",		"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LAB_BUS_NAME,	"ACBus_Name",	"ĸ������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LAB_BUS_KV,		"ACBus_kV",		"��׼��ѹ(kV)",					MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_ZONE,		"LAB_Zone",		"ZONE,������",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST/2,	0,	NULL,	},
	{	BPA_SWI_LAB_AREA,		"LAB_Area",		"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_LAB_P1,			"LAB_P1",		"�㶨�迹�й����ɰٷ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q1,			"LAB_Q1",		"�㶨�迹�޹����ɰٷ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P2,			"LAB_P2",		"�㶨�����й����ɰٷ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q2,			"LAB_Q2",		"�㶨�����޹����ɰٷ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P3,			"LAB_P3",		"�㶨�����й����ɰٷ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q3,			"LAB_Q3",		"�㶨�����޹����ɰٷ���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P4,			"LAB_P4",		"��Ƶ���йص��й����ɰٷ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q4,			"LAB_Q4",		"��Ƶ���йص��޹����ɰٷ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_LDP,		"LAB_LDP",		"Ƶ�ʱ仯1��������й��仯",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_LDQ,		"LAB_LDQ",		"Ƶ�ʱ仯1��������޹��仯",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_P5,			"LAB_P5",		"��ѹָ����ص��й����ɱ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_Q5,			"LAB_Q5",		"��ѹָ����ص��޹����ɱ���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_NP,			"LAB_NP",		"�й���ѹָ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LAB_NQ,			"LAB_NQ",		"�޹���ѹָ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_MI[]=
{
	{	BPA_SWI_MI_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_MI_BUS_NAME,	"ACBus_Name",	"ĸ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_MI_BUS_KV,		"ACBus_kV",		"��׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_BUS_ID,		"Bus_ID",		"BusIDʶ����ID",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_MI_EMWS,		"MI_Emws",		"���Ķ���(������)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_P,			"MI_P",			"��﹦��ռĸ���й����ɵı���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_MVA,			"MI_MVA",		"���Ļ�׼����ֵ(MVA)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_RS,			"MI_RS",		"���ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_XS,			"MI_XS",		"���ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_XM,			"MI_XM",		"���ŵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_RR,			"MI_RR",		"ת�ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_XR,			"MI_XR",		"ת�ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_VI,			"MI_VI",		"����ѹ�ͷŵĵ�ѹֵ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_TI,			"MI_TI",		"����ѹ�ͷ�ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_A,			"MI_A",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_B,			"MI_B",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MI_IM,			"MI_IM",		"��ﻬ��ﵽ1ʱ�Ĵ���ʽ",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
	{	BPA_SWI_MI_BUSPTR,		"BusPtr",		"ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_ML[]=
{
	{	BPA_SWI_ML_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_ML_BUS_NAME,	"ACBus_Name",	"ĸ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_ML_BUS_KV,		"ACBus_kV",		"��׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_BUS_ID,		"Bus_ID",		"BusIDʶ����ID",					MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_ML_TJ,			"ML_TJ",		"���Ĺ���ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_PPER,		"ML_Pper",		"��﹦��ռĸ���й����ɵı���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_KL,			"ML_KL",		"���ĸ����ʻ��ʼ����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_PMIN,		"ML_Pmin",		"���Ĺ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_RS,			"ML_RS",		"���ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_XS,			"ML_XS",		"���ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_XM,			"ML_XM",		"���ŵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_RR,			"ML_RR",		"ת�ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_XR,			"ML_XR",		"ת�ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_VI,			"ML_VI",		"����ѹ�ͷŵĵ�ѹֵ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_TI,			"ML_TI",		"����ѹ�ͷ�ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_A,			"ML_A",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_B,			"ML_B",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_ML_S0,			"ML_S0",		"�����ʻ��ʼ����",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(unsigned	char),	0,	NULL,	},//sizeof(g_BpaEnumMotor_KlS0)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_KlS0,	},
	{	BPA_SWI_ML_IM,			"ML_IM",		"��ﻬ��ﵽ1ʱ�Ĵ���ʽ",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
	{	BPA_SWI_ML_BUSPTR,		"BusPtr",		"ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_MJ[]=
{
	{	BPA_SWI_MJ_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_MJ_ZONE_NAME,	"Zone_Name",	"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_MJ_TJ,			"MJ_TJ",		"���Ĺ���ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_PPER,		"MJ_Pper",		"��﹦��ռĸ���й����ɵı���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_KL,			"MJ_KL",		"���ĸ����ʻ��ʼ����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_PMIN,		"MJ_Pmin",		"���Ĺ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_RS,			"MJ_RS",		"���ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_XS,			"MJ_XS",		"���ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_XM,			"MJ_XM",		"���ŵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_RR,			"MJ_RR",		"ת�ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_XR,			"MJ_XR",		"ת�ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_VI,			"MJ_VI",		"����ѹ�ͷŵĵ�ѹֵ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_TI,			"MJ_TI",		"����ѹ�ͷ�ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_A,			"MJ_A",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_B,			"MJ_B",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MJ_S0,			"MJ_S0",		"�����ʻ��ʼ����",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},//sizeof(g_BpaEnumMotor_KlS0)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_KlS0,	},
	{	BPA_SWI_MJ_IM,			"MJ_IM",		"��ﻬ��ﵽ1ʱ�Ĵ���ʽ",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaSwi_MK[]=
{
	{	BPA_SWI_MK_CARDKEY,		"CardKey",		"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_MK_AREA_NAME,	"Area_Name",	"��������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_MK_TJ,			"MK_TJ",		"���Ĺ���ʱ�䳣��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_PPER,		"MK_Pper",		"��﹦��ռĸ���й����ɵı���",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_KL,			"MK_KL",		"���ĸ����ʻ��ʼ����",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_PMIN,		"MK_Pmin",		"���Ĺ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_RS,			"MK_RS",		"���ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_XS,			"MK_XS",		"���ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_XM,			"MK_XM",		"���ŵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_RR,			"MK_RR",		"ת�ӵ���(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_XR,			"MK_XR",		"ת�ӵ翹(pu)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_VI,			"MK_VI",		"����ѹ�ͷŵĵ�ѹֵ",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_TI,			"MK_TI",		"����ѹ�ͷ�ʱ��(��)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_A,			"MK_A",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_B,			"MK_B",			"ת�ط��̳���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_MK_S0,			"MK_S0",		"�����ʻ��ʼ����",					MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},//sizeof(g_BpaEnumMotor_KlS0)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_KlS0,	},
	{	BPA_SWI_MK_IM,			"MK_IM",		"��ﻬ��ﵽ1ʱ�Ĵ���ʽ",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned	char),	sizeof(g_BpaEnumMotor_Stall)/sizeof(tagMemDBEnumPair),	g_BpaEnumMotor_Stall,	},
};

static	tagMemDBField	dicFieldBpaSwi_LE[]=
{
	{	BPA_SWI_LE_CARDKEY,		"CardKey",		"������",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LE_NAME,		"Name",			"ĸ�ߡ�������������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LE_LINE_ID,		"Line_ID",		"֧·˳���",									MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LE_RD,			"LE_RD",		"�����֧·����",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_XD,			"LE_XD",		"�����֧·�翹",								MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_PPER,		"LE_Pper",		"��֧·�й�����ռ��ĸ���ܸ����й����ʵı���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_QPER,		"LE_Qper",		"��֧·�޹�����ռ��ĸ���ܸ����޹����ʵı���",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_PG,			"LE_PG",		"�뱾֧·���������з�������й��ܳ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_QG,			"LE_QG",		"�뱾֧·���������з�������޹��ܳ���",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LE_PFAC,		"LE_PFAC",		"�����֧·��̬���ɵĹ�������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_LM[]=
{
	{	BPA_SWI_LM_CARDKEY,		"CardKey",		"������",						MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_LM_BUS1_I,		"LM_Bus1_I",	"BusName1_A",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV1_I,		"LM_kV1_I",		"BusBase1_A(kV)	",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_BUS1_J,		"LM_Bus1_J",	"BusName1_B	",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV1_J,		"LM_kV1_J",		"BusBase1_B(kV)	",				MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_PAR_1,		"LM_PAR_1",		"ƽ����",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LM_BUS2_I,		"LM_Bus2_I",	"BusName2_I",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV2_I,		"LM_kV2_I",		"BusBase2_I(kV)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_BUS2_J,		"LM_Bus2_J",	"BusName2_J",					MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_LM_KV2_J,		"LM_kV2_J",		"BusBase2_J(kV)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_PAR_2,		"LM_PAR_2",		"ƽ����",						MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_LM_RM,			"LM_Rm",		"���е���",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_XM,			"LM_Xm",		"���е翹",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_LM_KEYNAME,		"KeyName",		"��·�߿������迹����",			MDBFieldCategoryAid,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	BPA_SWI_LM_BUSPTR,		"BusPtr",		"��·�߿������迹Iĸ������",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	BPA_SWI_LM_ZRBUS,		"zRBus",		"��·�߿������迹Zĸ������",	MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_UF[]=
{
	{	BPA_SWI_UF_CARDKEY,				"CardKey",				"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_UF_BUS_NAME,			"ACBus_Name",			"ĸ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_UF_BUS_KV,				"ACBus_KV",				"��׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ01,				"UF_Freq01",			"��01��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ02,				"UF_Freq02",			"��02��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ03,				"UF_Freq03",			"��03��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ04,				"UF_Freq04",			"��04��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ05,				"UF_Freq05",			"��05��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ06,				"UF_Freq06",			"��06��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ07,				"UF_Freq07",			"��07��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ08,				"UF_Freq08",			"��08��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ09,				"UF_Freq09",			"��09��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_FREQ10,				"UF_Freq10",			"��10��������ʱ��Ƶ��(Hz)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY01,				"UF_Delay01",			"��01��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY02,				"UF_Delay02",			"��02��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY03,				"UF_Delay03",			"��03��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY04,				"UF_Delay04",			"��04��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY05,				"UF_Delay05",			"��05��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY06,				"UF_Delay06",			"��06��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY07,				"UF_Delay07",			"��07��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY08,				"UF_Delay08",			"��08��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY09,				"UF_Delay09",			"��09��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_DELAY10,				"UF_Delay10",			"��10��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED01,				"UF_Shed01",			"��01����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED02,				"UF_Shed02",			"��02����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED03,				"UF_Shed03",			"��03����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED04,				"UF_Shed04",			"��04����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED05,				"UF_Shed05",			"��05����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED06,				"UF_Shed06",			"��06������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED07,				"UF_Shed07",			"��07������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED08,				"UF_Shed08",			"��08������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED09,				"UF_Shed09",			"��09������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_SHED10,				"UF_Shed10",			"��10������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UF_W,					"UF_W",					"�ر���W,��ʾ��MWΪ��λ��ȥ����",	MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_UV[]=
{
	{	BPA_SWI_UV_CARDKEY,				"CardKey",			"������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_UV_BUS_NAME,			"ACBus_Name",		"ĸ������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_UV_BUS_KV,				"ACBus_KV",			"��׼��ѹ(kV)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT01,				"UV_Volt01",		"��01��������ʱ�ĵ�ѹ(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT02,				"UV_Volt02",		"��02��������ʱ�ĵ�ѹ(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT03,				"UV_Volt03",		"��03��������ʱ�ĵ�ѹ(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT04,				"UV_Volt04",		"��04��������ʱ�ĵ�ѹ(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT05,				"UV_Volt05",		"��05��������ʱ�ĵ�ѹ(PU)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT06,				"UV_Volt06",		"��06��������ʱ�ĵ�ѹ(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT07,				"UV_Volt07",		"��07��������ʱ�ĵ�ѹ(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT08,				"UV_Volt08",		"��08��������ʱ�ĵ�ѹ(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT09,				"UV_Volt09",		"��09��������ʱ�ĵ�ѹ(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_VOLT10,				"UV_Volt10",		"��10��������ʱ�ĵ�ѹ(pu)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY01,				"UV_Delay01",		"��01��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY02,				"UV_Delay02",		"��02��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY03,				"UV_Delay03",		"��03��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY04,				"UV_Delay04",		"��04��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY05,				"UV_Delay05",		"��05��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY06,				"UV_Delay06",		"��06��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY07,				"UV_Delay07",		"��07��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY08,				"UV_Delay08",		"��08��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY09,				"UV_Delay09",		"��09��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_DELAY10,				"UV_Delay10",		"��10��������ǰ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED01,				"UV_Shed01",		"��01����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED02,				"UV_Shed02",		"��02����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED03,				"UV_Shed03",		"��03����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED04,				"UV_Shed04",		"��04����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED05,				"UV_Shed05",		"��05����ʼ���ɱ���ȥ��ֵ",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED06,				"UV_Shed06",		"��06������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED07,				"UV_Shed07",		"��07������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED08,				"UV_Shed08",		"��08������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED09,				"UV_Shed09",		"��09������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_SHED10,				"UV_Shed10",		"��10������ȥ�ĸ���ֵ(MW)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_UV_W,					"UV_W",				"�ر���W,��ʾ��MWΪ��λ��ȥ����",	MDBFieldCategoryParam,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
};


static	tagMemDBField	dicFieldBpaSwi_RE[]=
{
	{	BPA_SWI_RE_CARDKEY,			"CardKey",			"������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,		0,	NULL,	},
	{	BPA_SWI_RE_BUS_NAME,		"ACBus_Name",		"ĸ������",				MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RE_BUS_KV,			"ACBus_KV",			"��׼��ѹ(kV)	",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_GEN_ID,			"Gen_ID",			"�����ʶ����",			MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RE_VOL1,			"RE_VOL1",			"��ѹ�趨ֵ1(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL2,			"RE_VOL2",			"��ѹ�趨ֵ2(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL3,			"RE_VOL3",			"��ѹ�趨ֵ3(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL4,			"RE_VOL4",			"��ѹ�趨ֵ4(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL5,			"RE_VOL5",			"��ѹ�趨ֵ5(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL6,			"RE_VOL6",			"��ѹ�趨ֵ6(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL7,			"RE_VOL7",			"��ѹ�趨ֵ7(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL8,			"RE_VOL8",			"��ѹ�趨ֵ8(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL9,			"RE_VOL9",			"��ѹ�趨ֵ9(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_VOL10,			"RE_VOL10",			"��ѹ�趨ֵ10(pu)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME1,			"RE_TIME1",			"ʱ��1(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME2,			"RE_TIME2",			"ʱ��2(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME3,			"RE_TIME3",			"ʱ��3(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME4,			"RE_TIME4",			"ʱ��4(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME5,			"RE_TIME5",			"ʱ��5(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME6,			"RE_TIME6",			"ʱ��6(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME7,			"RE_TIME7",			"ʱ��7(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME8,			"RE_TIME8",			"ʱ��8(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME9,			"RE_TIME9",			"ʱ��9(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TIME10,			"RE_TIME10",		"ʱ��10(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_TBRK,			"RE_TBRK",			"�̵�������ʱ��(��)",	MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_NAME_CON,		"RE_NAME_CON",		"����ĸ������",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RE_KV_CON,			"RE_KV_CON",		"����ĸ�߻�׼��ѹ",		MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RE_KEYNAME,			"KeyName",			"���ݿ�����",			MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_RE_BUSPTR,			"BusPtr",			"�����ĸ������",		MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_RW[]=
{
	{	BPA_SWI_RW_CARDKEY,			"CardKey",			"������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_RW_BUS_NAME,		"ACBus_Name",		"ĸ������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RW_BUS_KV,			"ACBus_KV",			"��׼��ѹ(kV)	",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_GEN_ID,			"Gen_ID",			"�����ʶ����",								MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RW_WMAX,			"RW_Wmax",			"�����������բ�����ת��(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WMIN,			"RW_Wmin",			"�����������բ����Сת��(pu)",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET1,			"RW_Wset1",			"�����ת���趨ֵ1(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET2,			"RW_Wset2",			"�����ת���趨ֵ2(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET3,			"RW_Wset3",			"�����ת���趨ֵ3(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET4,			"RW_Wset4",			"�����ת���趨ֵ4(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET5,			"RW_Wset5",			"�����ת���趨ֵ5(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET6,			"RW_Wset6",			"�����ת���趨ֵ6(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET7,			"RW_Wset7",			"�����ת���趨ֵ7(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET8,			"RW_Wset8",			"�����ת���趨ֵ8(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET9,			"RW_Wset9",			"�����ת���趨ֵ9(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_WSET10,			"RW_Wset10",		"�����ת���趨ֵ10(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY1,			"RW_Delay1",		"�����ת���趨ֵ1��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY2,			"RW_Delay2",		"�����ת���趨ֵ2��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY3,			"RW_Delay3",		"�����ת���趨ֵ3��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY4,			"RW_Delay4",		"�����ת���趨ֵ4��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY5,			"RW_Delay5",		"�����ת���趨ֵ5��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY6,			"RW_Delay6",		"�����ת���趨ֵ6��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY7,			"RW_Delay7",		"�����ת���趨ֵ7��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY8,			"RW_Delay8",		"�����ת���趨ֵ8��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY9,			"RW_Delay9",		"�����ת���趨ֵ9��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_DELAY10,			"RW_Delay10",		"�����ת���趨ֵ10��Ӧ��ʱ��(��)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_TBRK,			"RW_Tbrk",			"�̵�������ʱ��(��)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RW_KEYNAME,			"KeyName",			"���ݿ�����",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	BPA_SWI_RW_BUSPTR,			"BusPtr",			"�����ĸ������",							MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_RA[]=
{
	{	BPA_SWI_RA_CARDKEY,			"CardKey",			"������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_RA_BUSI,			"RA_BusI",			"ĸ������1",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_KVI,				"RA_kVI",			"��׼��ѹ1(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_BUSJ,			"RA_BusJ",			"ĸ������2",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_KVJ,				"RA_kVJ",			"��׼��ѹ2(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_LOOP,			"RA_Loop",			"������·�Ļ�·��־",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RA_CBUS1,			"RA_CBus1",			"����ĸ������1",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_CKV1,			"RA_CkV1",			"����ĸ�߻�׼��ѹ1(kV)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CV1,				"RA_V1",			"ĸ��1�͵�ѹ����ֵ(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CT1,				"RA_T1",			"ĸ��1�͵�ѹʱ���ӳ�(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CBUS2,			"RA_CBus2",			"����ĸ������2",							MDBFieldCategoryParam,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RA_CKV2,			"RA_CkV2",			"����ĸ�߻�׼��ѹ2(kV)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CV2,				"RA_V2",			"ĸ��2�͵�ѹ����ֵ(pu)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_CT2,				"RA_T2",			"ĸ��2�͵�ѹʱ���ӳ�(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RA_KEYNAME,			"KeyName",			"��·����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
};

static	tagMemDBField	dicFieldBpaSwi_RU[]=
{
	{	BPA_SWI_RU_CARDKEY,			"CardKey",			"������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTEST,	0,	NULL,	},
	{	BPA_SWI_RU_BUSI,			"RU_BusI",			"ĸ������1",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RU_KVI,				"RU_kVI",			"��׼��ѹ1(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_BUSJ,			"RU_BusJ",			"ĸ������2",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_BPABUS,		0,	NULL,	},
	{	BPA_SWI_RU_KVJ,				"RU_kVJ",			"��׼��ѹ2(kV)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_LOOP,			"RU_Loop",			"������·�Ļ�·��־",						MDBFieldCategoryBase,	MDB_CHAR,	sizeof(char),			0,	NULL,	},
	{	BPA_SWI_RU_FTRIP,			"RU_FTrip",			"ĸ��Ƶ�ʵ��ż�ֵ(Hz)",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_TRELAY,			"RU_TRelay",		"�̵�����������ʱ��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_TTRIP,			"RU_TTrip",			"ͨѶ�Ϳ��ض���ʱ��(��)",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_TDELAY,			"RU_TDelay",		"���Ͳ���ʱ��(��)",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	BPA_SWI_RU_KEYNAME,			"KeyName",			"��·����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORT,		0,	NULL,	},
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
