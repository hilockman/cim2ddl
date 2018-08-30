#pragma once

#include "PRMemDBDefine.h"
#include "PRMemDBField.h"

// 开闭所		Switching station
// 环网柜		Switchgear Cupboard
// 配电室		Distribution Room
// 箱式变电站	Box-type substation
// 电缆分支箱	Cable Branch Box

//	本文中包含了整个全数据的结构定义。
//	本文中包含了整个全数据的字典定义。
//	在进行数据结构更改时需要更改：
//		结构定义
//		字典定义
//		宏定义
//	需要更改：
//		写方法
//		添加方法
//		展示方法

//	在数据结构定义中有一些中间变量不在数据字典中表达，仅仅反映在结构定义中。

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

//	这里需要注意的是RESTRICT中的关键字必须为CHAR，如果不是CHAR，通过CHAR也能比较
static tagMemDBTable	g_PRTableDictArray[]=
{
	{	PR_SYSTEM,			"System"		,	"", 		"系统"					, 0	, sizeof(g_PRSystemFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRSystem)		, 1						, PRSystem_Offset			, {	0,	0,							0,					0,						0,	},	g_PRSystemFieldArray,			},
	{	PR_ZONE,			"Zone"			,	"", 		"分区"					, 0	, sizeof(g_PRZoneFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRZone)			, PR_MaxZone			, PRZone_Offset				, {	1,	PR_ZONE_NAME,				0,					0,						0,	},	g_PRZoneFieldArray,				},
	{	PR_RADIAL,			"Radial"		,	"", 		"环辐网"				, 0	, sizeof(g_PRRadFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPRRadial)		, PR_MaxRadial			, PRRadial_Offset			, {	0,	0,							0,					0,						0,	},	g_PRRadFieldArray,				},
	{	PR_ACBUS,			"ACBus"			,	"", 		"交流母线"				, 0	, sizeof(g_PRACBusFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRACBus)		, PR_MaxACBus			, PRACBus_Offset			, {	2,	PR_ACBUS_NAME,				PR_ACBUS_KV,		0,						0,	},	g_PRACBusFieldArray,			},
	{	PR_ACLINE,			"ACLine"		,	"", 		"交流线路"				, 0	, sizeof(g_PRACLineFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRACLine)		, PR_MaxACLine			, PRACLine_Offset			, {	1,	PR_ACLINE_NAME,				0,					0,						0,	},	g_PRACLineFieldArray,			},
	{	PR_WIND,			"Wind"			,	"", 		"变压器绕组"			, 0	, sizeof(g_PRWindFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRWind)			, PR_MaxWind			, PRWind_Offset				, {	1,	PR_WIND_NAME,				0,					0,						0,	},	g_PRWindFieldArray,				},
	{	PR_GENERATOR,		"Generator"		,	"Gen", 		"发电机"				, 0	, sizeof(g_PRGeneratorFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRGenerator)	, PR_MaxGenerator		, PRGenerator_Offset		, {	1,	PR_GENERATOR_NAME,			0,					0,						0,	},	g_PRGeneratorFieldArray,		},
	{	PR_POWERLOAD,		"PowerLoad"		,	"Load", 	"负荷"					, 0	, sizeof(g_PRPowerLoadFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRPowerLoad)	, PR_MaxPowerLoad		, PRPowerLoad_Offset		, {	1,	PR_POWERLOAD_NAME,			0,					0,						0,	},	g_PRPowerLoadFieldArray,		},
	{	PR_HVDC,			"HVDC"			,	"", 		"高压直流系统"			, 0	, sizeof(g_PRHVDCFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRHVDC)			, PR_MaxHVDC			, PRHVDC_Offset				, {	1,	PR_HVDC_NAME,				0,					0,						0,	},	g_PRHVDCFieldArray,				},
	{	PR_CONVERTER,		"Converter"		,	"", 		"变换器"				, 0	, sizeof(g_PRConverterFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRConverter)	, PR_MaxConverter		, PRConverter_Offset		, {	1,	PR_CONVERTER_NAME,			0,					0,						0,	},	g_PRConverterFieldArray,		},
	{	PR_DCBUS,			"DCBus"			,	"", 		"直流母线"				, 0	, sizeof(g_PRDCBusFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRDCBus)		, PR_MaxDCBus			, PRDCBus_Offset			, {	1,	PR_DCBUS_NAME,				0,					0,						0,	},	g_PRDCBusFieldArray,			},
	{	PR_DCLINE,			"DCLine"		,	"", 		"直流线路"				, 0	, sizeof(g_PRDCLineFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRDCLine)		, PR_MaxDCLine			, PRDCLine_Offset			, {	1,	PR_DCLINE_NAME,				0,					0,						0,	},	g_PRDCLineFieldArray,			},
	{	PR_TCSC,			"TCSC"			,	"", 		"可控串联补偿装置"		, 0	, sizeof(g_PRTCSCFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRTCSC)			, PR_MaxTCSC			, PRTCSC_Offset				, {	1,	PR_TCSC_NAME,				0,					0,						0,	},	g_PRTCSCFieldArray,				},
	{	PR_UPFC,			"UPFC"			,	"", 		"统一潮流控制器"		, 0	, sizeof(g_PRUPFCFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRUPFC)			, PR_MaxUPFC			, PRUPFC_Offset				, {	1,	PR_UPFC_NAME,				0,					0,						0,	},	g_PRUPFCFieldArray,				},
	{	PR_DEVMSTATE,		"DevMState"		,	"", 		"设备多状态"			, 0	, sizeof(g_PRDevMStateFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRDevMState)	, PR_MaxDevMState		, PRDevMState_Offset		, {	2,	PR_DEVMSTATE_TYPE,			PR_DEVMSTATE_NAME,	0,						0,	},	g_PRDevMStateFieldArray,		},
	{	PR_ACISLAND,		"ACIsland"		,	"", 		"交流电岛"				, 0	, sizeof(g_PRACIslandFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRACIsland)		, PR_MaxACIsland		, PRACIsland_Offset			, {	0,	0,							0,					0,						0,	},	g_PRACIslandFieldArray,			},
	{	PR_ACLINEEDGE,		"ACLineEdge"	,	"", 		"交流线路边"			, 0	, sizeof(g_PRACLineEdgeFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRACLineEdge)	, PR_MaxACLineEdge		, PRACLineEdge_Offset		, {	3,	PR_ACLINEEDGE_BUS,			PR_ACLINEEDGE_KV,	PR_ACLINEEDGE_NAME,		0,	},	g_PRACLineEdgeFieldArray,		},
	{	PR_WINDEDGE,		"WindEdge"		,	"", 		"变压器绕组边"			, 0	, sizeof(g_PRWindEdgeFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRWindEdge)		, PR_MaxWindEdge		, PRWindEdge_Offset			, {	3,	PR_WINDEDGE_BUS,			PR_WINDEDGE_KV,		PR_WINDEDGE_NAME,		0,	},	g_PRWindEdgeFieldArray,			},
	//{	PR_LOADCURVE,		"LoadCurve"		,	"", 		"负荷曲线"				, 0	, sizeof(g_PRLoadCurveFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRLoadCurve)	, PR_MaxLoadCurve		, PRLoadCurve_Offset		, {	2,	PR_LOADCURVE_BUS,			PR_LOADCURVE_ID,	0,						0,	},	g_PRLoadCurveFieldArray,		},
													
	{	PR_TRIP,			"Trip"			,	"", 		"开断故障信息"			, 0	, sizeof(g_PRTripFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRTrip)			, PR_MaxTrip			, PRTrip_Offset				, {	0,	0,							0,					0,						0,	},	g_PRTripFieldArray,				},
	{	PR_TRIPMISLAND,		"TripMIsland"	,	"", 		"开断故障下孤岛信息"	, 0	, sizeof(g_PRTripMIslandFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRTripMIsland)	, PR_MaxTripMIsland		, PRTripMIsland_Offset		, {	1,	PR_TRIPMISLAND_TRIP,		0,					0,						0,	},	g_PRTripMIslandFieldArray,		},
	{	PR_TRIPOVLDEV,		"TripOvlDev"	,	"", 		"开断故障下越限信息"	, 0	, sizeof(g_PRTripOvlDevFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRTripOvlDev)	, PR_MaxTripOvlDev		, PRTripOvlDev_Offset		, {	1,	PR_TRIPOVLDEV_TRIP,			0,					0,						0,	},	g_PRTripOvlDevFieldArray,		},
													
	{	PR_COMMRPARAM,		"CommRParam"	,	"", 		"可靠性公共参数"		, 0	, sizeof(g_PRCommRParamFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRCommRParam)	, PR_MaxCommRParam		, PRCommRParam_Offset		, {	0,	0,							0,					0,						0,	},	g_PRCommRParamFieldArray,		},
	{	PR_MANUALFAULT,		"ManualFault"	,	"", 		"人工事件"				, 0	, sizeof(g_PRManualFaultFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRManualFault)	, PR_MaxManualFault		, PRManualFault_Offset		, {	0,	0,							0,					0,						0,	},	g_PRManualFaultFieldArray,		},
	{	PR_COMMONFAULT,		"CommonFault"	,	"", 		"共因故障"				, 0	, sizeof(g_PRCommonFaultFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRCommonFault)	, PR_MaxCommonFault		, PRCommonFault_Offset		, {	0,	PR_COMMONFAULT_NAME,		0,					0,						0,	},	g_PRCommonFaultFieldArray,		},
	{	PR_R2STATECOMP,		"R2StateComp"	,	"", 		"两状态可靠性设备"		, 0	, sizeof(g_PR2StateCompFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPR2StateComp)	, PR_MaxR2StateComp		, PR2StateComp_Offset		, {	0,	0,							0,					0,						0,	},	g_PR2StateCompFieldArray,		},
	{	PR_RMSTATECOMP,		"RMStateComp"	,	"", 		"多状态可靠性设备"		, 0	, sizeof(g_PRMStateCompFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRMStateComp)	, PR_MaxRMStateComp		, PRMStateComp_Offset		, {	0,	0,							0,					0,						0,	},	g_PRMStateCompFieldArray,		},
	//{	PR_MCSAMPLESTATE,	"MCSampleState"	,	"", 		"蒙特卡罗抽样状态"		, 0	, sizeof(g_PRMCSampleStateFieldArray)	/sizeof(tagMemDBField)	, sizeof(tagPRMCSampleState), PR_MaxMCSampleState	, PRMCSampleState_Offset	, {	0,	0,							0,					0,						0,	},	g_PRMCSampleStateFieldArray,	},

	{	PR_FSTATE,			"FState"		,	"", 		"抽样状态"				, 0	, sizeof(g_PRFStateFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRFState)		, PR_MaxFState			, PRFState_Offset			, {	1,	PR_FSTATE_ID,				0,					0,						0,	},	g_PRFStateFieldArray,			},
	{	PR_FSTATEFDEV,		"FStateFDev"	,	"", 		"抽样状态下故障设备"	, 0	, sizeof(g_PRFStateFDevFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRFStateFDev)	, PR_MaxFStateFDev		, PRFStateFDev_Offset		, {	1,	PR_FSTATEFDEV_FSTATENO,		0,					0,						0,	},	g_PRFStateFDevFieldArray,		},
	{	PR_FSTATEMSTATE,	"FStateMState"	,	"", 		"抽样状态下多状态"		, 0	, sizeof(g_PRMStateFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRFStateMState)	, PR_MaxFStateMState	, PRFStateMState_Offset		, {	0,	0,							0,					0,						0,	},	g_PRMStateFieldArray,			},
	{	PR_FSTATEMISLAND,	"FStateMIsland"	,	"", 		"抽样状态下孤岛损失"	, 0	, sizeof(g_PRFStateMIslandFieldArray)	/sizeof(tagMemDBField)	, sizeof(tagPRFStateMIsland), PR_MaxFStateMIsland	, PRFStateMIsland_Offset	, {	1,	PR_FSTATEMISLAND_FSTATENO,	0,					0,						0,	},	g_PRFStateMIslandFieldArray,	},
	{	PR_FSTATEOVLDEV,	"FStateOvlDev"	,	"", 		"抽样状态下越限设备"	, 0	, sizeof(g_PRFStateOvlDevFieldArray)	/sizeof(tagMemDBField)	, sizeof(tagPRFStateOvlDev)	, PR_MaxFStateOvlDev	, PRFStateOvlDev_Offset		, {	1,	PR_FSTATEOVLDEV_FSTATENO,	0,					0,						0,	},	g_PRFStateOvlDevFieldArray,		},
	{	PR_FSTATEOVLAD,		"FStateOvlAd"	,	"", 		"抽样状态下越限调整"	, 0	, sizeof(g_PRFStateOvlAdFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRFStateOvlAd)	, PR_MaxFStateOvlAd		, PRFStateOvlAd_Offset		, {	1,	PR_FSTATEOVLAD_FSTATENO,	0,					0,						0,	},	g_PRFStateOvlAdFieldArray,		},

	{	PR_ADSNODE,			"AdsNode"		,	"", 		"计算节点表"			, 0	, sizeof(g_PRAdsNodeFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRAdsNode)		, PR_MaxAdsNode			, PRAdsNode_Offset			, {	1,	PR_ADSNODE_ID,				0,					0,						0,	},	g_PRAdsNodeFieldArray,			},
	{	PR_CALCJOBTYPE,		"CalcJobType"	,	"", 		"工作类型表"			, 0	, sizeof(g_PRCalcJobTypeFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRCalcJobType)	, PR_MaxCalcJobType		, PRCalcJobType_Offset		, {	1,	PR_CALCJOBTYPE_ID,			0,					0,						0,	},	g_PRCalcJobTypeFieldArray,		},
	{	PR_CALCJOB,			"CalcJob"		,	"", 		"计算工作表"			, 0	, sizeof(g_PRCalcJobFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRCalcJob)		, PR_MaxCalcJob			, PRCalcJob_Offset			, {	1,	PR_CALCJOB_ID,				0,					0,						0,	},	g_PRCalcJobFieldArray,			},
	{	PR_CALCTASK,		"CalcTask"		,	"", 		"计算任务表"			, 0	, sizeof(g_PRCalcTaskFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRCalcTask)		, PR_MaxCalcTask		, PRCalcTask_Offset			, {	1,	PR_CALCTASK_ID,				0,					0,						0,	},	g_PRCalcTaskFieldArray,			},
	{	PR_CALCFILE,		"CalcFile"		,	"", 		"计算文件表"			, 0	, sizeof(g_PRCalcFileFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRCalcFile)		, PR_MaxCalcFile		, PRCalcFile_Offset			, {	1,	PR_CALCFILE_JOBID,			0,					0,						0,	},	g_PRCalcFileFieldArray,			},

	{	PR_FSECURITY,		"FSecurity"		,	"", 		"安全评价"				, 0	, sizeof(g_PRFSecurityFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRFSecurity)	, PR_MaxFSecurity		, PRFSecurity_Offset		, {	0,	0,							0,					0,						0,	},	g_PRFSecurityFieldArray,		},
	{	PR_COPGEN,			"CopGen"		,	"", 		"停运发电"				, 0	, sizeof(g_PRCopGenFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPRCopGen)		, PR_MaxCopGen			, PRCopGen_Offset			, {	0,	0,							0,					0,						0,	},	g_PRCopGenFieldArray,			},
	{	PR_COPTABLE,		"CopTable"		,	"", 		"停运概率"				, 0	, sizeof(g_PRCopTableFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPRCopTable)		, PR_MaxCopTable		, PRCopTable_Offset			, {	0,	0,							0,					0,						0,	},	g_PRCopTableFieldArray,			},
};

static	tagMDBTableFieldContainer	g_PRTableFieldContainerArray[]=
{
	{	MDBFieldCrit,	PR_FSTATEMISLAND,		PR_FSTATEMISLAND_FSTATENO,			-1,								-1,							-1,		PR_FSTATE,			},
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
