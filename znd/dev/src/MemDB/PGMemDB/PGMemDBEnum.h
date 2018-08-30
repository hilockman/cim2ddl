#pragma once

static	tagMemDBEnumPair	g_PGEnumTrueFalse[]=
{
	{	0,		"false",	},
	{	1,		"true",		},
};

static	tagMemDBEnumPair	g_PGEnumNoYes[]=
{
	{	0,		"否",	},
	{	1,		"是",	},
};

static	tagMemDBEnumPair	g_PGEnumYesNo[]=
{
	{	0,		"是",	},
	{	1,		"否",	},
};

// static	tagMemDBEnumPair	g_PGEnumFaultType[]=
// {
// 	{	0,		"单永故障",	},
// 	{	1,		"两相短路",	},
// 	{	2,		"三相短路",	},
// 	{	3,		"两相接地",	},
// };

static	tagMemDBEnumPair	g_PGEnumFaultType[]=
{
	{	PGEnum_Scc_FaultType1,		"单永故障",	},
	{	PGEnum_Scc_FaultType2,		"两相短路",	},
	{	PGEnum_Scc_FaultType3,		"三相短路",	},
	{	PGEnum_Scc_FaultType4,		"两相接地",	},
};

static	tagMemDBEnumPair	g_PGEnumSccFMoveDataType[]=
{
	{	PGEnum_Scc_FMoveDataType_FC_I1Re,		"故障线路短路电流I侧正序实部",	},
	{	PGEnum_Scc_FMoveDataType_FC_I1Im,		"故障线路短路电流I侧正序虚部",	},
	{	PGEnum_Scc_FMoveDataType_FC_I2Re,		"故障线路短路电流I侧负序实部",	},
	{	PGEnum_Scc_FMoveDataType_FC_I2Im,		"故障线路短路电流I侧负序虚部",	},
	{	PGEnum_Scc_FMoveDataType_FC_I0Re,		"故障线路短路电流I侧零序实部",	},
	{	PGEnum_Scc_FMoveDataType_FC_I0Im,		"故障线路短路电流I侧零序虚部",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z1Re,		"故障线路短路电流J侧正序实部",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z1Im,		"故障线路短路电流J侧正序虚部",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z2Re,		"故障线路短路电流J侧负序实部",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z2Im,		"故障线路短路电流J侧负序虚部",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z0Re,		"故障线路短路电流J侧零序实部",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z0Im,		"故障线路短路电流J侧零序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MC_I1Re,		"监视线路短路电流I侧正序实部",	},
	{	PGEnum_Scc_FMoveDataType_MC_I1Im,		"监视线路短路电流I侧正序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MC_I2Re,		"监视线路短路电流I侧负序实部",	},
	{	PGEnum_Scc_FMoveDataType_MC_I2Im,		"监视线路短路电流I侧负序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MC_I0Re,		"监视线路短路电流I侧零序实部",	},
	{	PGEnum_Scc_FMoveDataType_MC_I0Im,		"监视线路短路电流I侧零序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z1Re,		"监视线路短路电流J侧正序实部",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z1Im,		"监视线路短路电流J侧正序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z2Re,		"监视线路短路电流J侧负序实部",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z2Im,		"监视线路短路电流J侧负序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z0Re,		"监视线路短路电流J侧零序实部",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z0Im,		"监视线路短路电流J侧零序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MV_1Re,		"监视母线电压正序实部",	},
	{	PGEnum_Scc_FMoveDataType_MV_1Im,		"监视母线电压正序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MV_2Re,		"监视母线电压负序实部",	},
	{	PGEnum_Scc_FMoveDataType_MV_2Im,		"监视母线电压负序虚部",	},
	{	PGEnum_Scc_FMoveDataType_MV_0Re,		"监视母线电压零序实部",	},
	{	PGEnum_Scc_FMoveDataType_MV_0Im,		"监视母线电压零序虚部",	},
};

static	tagMemDBEnumPair	g_PGEnumCloseOpenStatus[]=
{
	{	PGEnumCloseOpenStatus_Close,	"合",	},
	{	PGEnumCloseOpenStatus_Open,		"开",	},
};

static	tagMemDBEnumPair	g_PGEnumPlateStatus[]=
{
	{	PGEnumPlateStatus_Close,		"投",	},
	{	PGEnumPlateStatus_Open,			"退",	},
};

static	tagMemDBEnumPair	g_PGEnumMCRDevType[]=
{
	{	PGEnumLineTran_MCType_Load,		"负荷",	},
	{	PGEnumLineTran_MCType_Gen,		"电源",	},
	{	PGEnumLineTran_MCType_Edge,		"联络",	},
};
static	tagMemDBEnumPair	g_PGMCEnumBreakerCTLoc[]=
{
	{	MCPhy_BreakerCTLoc_None,	"无",	},
	{	MCPhy_BreakerCTLoc_I,		"I侧",	},
	{	MCPhy_BreakerCTLoc_J,		"J侧",	},
	{	MCPhy_BreakerCTLoc_IJ,		"两侧",	},
};

static	tagMemDBEnumPair	g_PGEnumBreakerInnerType[]=
{
	{	PGEnum_BreakerInnerType_None,			"无",				},
	{	PGEnum_BreakerInnerType_BrLnXf,			"普通断路器",		},
	{	PGEnum_BreakerInnerType_BrBus,			"母联/分段断路器",	},
	{	PGEnum_BreakerInnerType_BrBypass,		"旁路断路器",		},
	{	PGEnum_BreakerInnerType_BrBusBypass,	"旁母断路器",		},
	{	PGEnum_BreakerInnerType_Br32,			"3/2断路器",		},
};
static	tagMemDBEnumPair	g_PGEnumDisconnectorInnerType[]=
{
	{	PGEnum_DisconnectorInnerType_None,			"无",					},
	{	PGEnum_DisconnectorInnerType_SwLnXf,		"普通隔离开关",			},
	{	PGEnum_DisconnectorInnerType_SwBusbar,		"母线隔离开关",			},
	{	PGEnum_DisconnectorInnerType_SwBuslink,		"母联/分段隔离开关",	},
	{	PGEnum_DisconnectorInnerType_SwLnXfBypass,	"设备旁路隔离开关",		},
	{	PGEnum_DisconnectorInnerType_SwBusBypass,	"旁路隔离开关",			},
	{	PGEnum_DisconnectorInnerType_Sw32,			"3/2隔离开关",			},
	{	PGEnum_DisconnectorInnerType_BypassCross,	"旁路跨条(隔离开关)",	},
	{	PGEnum_DisconnectorInnerType_SwGround,		"接地刀闸(隔离开关)",	},
};

static	tagMemDBEnumPair	g_PGEnumHideVisibleStatus[]=
{
	{	PGEnumHideVisibleStatus_Hide,		"隐藏",	},
	{	PGEnumHideVisibleStatus_Visible,	"显示",	},
};

static	tagMemDBEnumPair	g_PGEnumSaResult[]=
{
	{	PGEnumSaResult_Unknow,	"未知",		},
	{	PGEnumSaResult_Ceased,	"停运",		},
	{	PGEnumSaResult_Ringed,	"合环",		},
	{	PGEnumSaResult_Failed,	"未通过",	},
	{	PGEnumSaResult_Passed,	"通过",		},
};

static	tagMemDBEnumPair	g_PGEnumSubControlArea_Equity[]=
{
	{	0,	"直供直管",	},
	{	1,	"控股",		},
	{	2,	"代管",		},
	{	3,	"其他",		},
};

static	tagMemDBEnumPair	g_PGEnumSubstation_st_type[]=
{
	{	PGEnumst_type_Distribution,			"电源站",		},
	{	PGEnumst_type_Plant,				"电厂",			},
	{	PGEnumst_type_Substation,			"变电站",		},
	{	PGEnumst_type_Plant_Thermal,		"火电厂",		},
	{	PGEnumst_type_Plant_Hydro,			"水电厂",		},
	{	PGEnumst_type_Plant_Nuclear,		"核电厂",		},
	{	PGEnumst_type_Plant_PumpedStorage,	"抽蓄电厂",		},
	{	PGEnumst_type_Plant_Renewable,		"新能源",		},
	{	PGEnumst_type_Converter_Station,	"换流站",		},
	{	PGEnumst_type_Plant_Outnet,			"外网虚拟站",	},
};

static	tagMemDBEnumPair	g_PGEnumSubstationEntity_Type[]=
{
	{	PGEnumSubstationEntity_Distribution,		"电源站",		},
	{	PGEnumSubstationEntity_Plant,				"一般电厂",		},
	{	PGEnumSubstationEntity_Substation,			"变电站",		},
	{	PGEnumSubstationEntity_PlantThermal,		"火电厂",		},
	{	PGEnumSubstationEntity_PlantHydro,			"水电厂",		},
	{	PGEnumSubstationEntity_PlantNuclear,		"核电厂",		},
	{	PGEnumSubstationEntity_PlantPumpedStorage,	"抽蓄电厂",		},
	{	PGEnumSubstationEntity_PlantWindTurbine,	"风电场",		},
	{	PGEnumSubstationEntity_PlantPhotoVoltaic,	"光伏电站",		},
	{	PGEnumSubstationEntity_PlantGeothermal,		"地热电厂",		},
	{	PGEnumSubstationEntity_ConverterStation,	"换流站",		},
	{	PGEnumSubstationEntity_Plant_Outnet,		"外网虚拟站",	},
	{	PGEnumSubstationEntity_SwitchStation,		"开闭站",		},
	{	PGEnumSubstationEntity_UserStation,			"用户站",		},
	{	PGEnumSubstationEntity_EVChargeStation,		"充换电站",		},
};

static	tagMemDBEnumPair	g_PGEnumSynchronousMachine_Type[]=
{
	{	PGEnumSynchronousMachine_Type_Thermal,		"火电机组",	},
	{	PGEnumSynchronousMachine_Type_Hydro,		"水电机组",	},
	{	PGEnumSynchronousMachine_Type_Gas,			"燃气机组",	},
	{	PGEnumSynchronousMachine_Type_Nuclear,		"核电机组",	},
	{	PGEnumSynchronousMachine_Type_Pump,			"抽蓄机组",	},
	{	PGEnumSynchronousMachine_Type_WindTurbine,	"风机",		},
	{	PGEnumSynchronousMachine_Type_PhotoVoltaic,	"光伏",		},
	{	PGEnumSynchronousMachine_Type_Equivalent,	"等值机组",	},
};

static	tagMemDBEnumPair	g_PGEnumLine_Connectmode[]=
{
	{	0,		"未定",				},
	{	1,		"三链",				},
	{	2,		"双链",				},
	{	3,		"单链",				},
	{	4,		"双环网",			},
	{	5,		"单环网",			},
	{	6,		"双辐射",			},
	{	7,		"单辐射",			},
	{	8,		"多分段单联络",		},
	{	9,		"多分段适度联络",	},
	{	10,		"其他",				},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_LineType[]=
{
	{	PGEnumLine_LineType_Overhead,	"架空",	},
	{	PGEnumLine_LineType_Cable,		"电缆",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_LoadSide[]=
{
	{	0,		"自动",		},
	{	1,		"起点侧",	},
	{	2,		"终点侧",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_AutoLength[]=
{
	{	0,		"人工",	},
	{	1,		"自动",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_TrunkLine[]=
{
	{	0,		"主干",	},
	{	1,		"分支",	},
};

static	tagMemDBEnumPair	g_PGEnumBusbarSection_BusbarId[]=
{
	{	PGEnumBusbarSection_BusbarId_1,		"#1母线",	},
	{	PGEnumBusbarSection_BusbarId_2,		"#2母线",	},
	{	PGEnumBusbarSection_BusbarId_3,		"#3母线",	},
	{	PGEnumBusbarSection_BusbarId_4,		"#4母线",	},
	{	PGEnumBusbarSection_BusbarId_5,		"#5母线",	},
	{	PGEnumBusbarSection_BusbarId_6,		"#6母线",	},
	{	PGEnumBusbarSection_BusbarId_7,		"#7母线",	},
	{	PGEnumBusbarSection_BusbarId_8,		"#8母线",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_LineConstruction[]=
{
	{	0,	"架空",		},
	{	1,	"直埋",		},
	{	2,	"排管",		},
	{	3,	"隧道",		},
	{	4,	"电缆沟",	},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_Type[]=
{
	{	PGEnumEnergyConsumer_Type_Static,			"综合负荷(恒功率或综合模型)",	},
	{	PGEnumEnergyConsumer_Type_Lump,				"照明/电热负荷(恒阻抗)",		},
	//{	PGEnumEnergyConsumer_Type_Electrolysis,		"电解负荷(恒电流)",				},
	{	PGEnumEnergyConsumer_Type_IndMotor,			"感应马达",						},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_MotorKLS0[]=
{
	{	PGEnumEnergyComsumer_MotorKLS0_KL,		"负载率",	},
	{	PGEnumEnergyComsumer_MotorKLS0_S0,		"初始滑差",	},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_MotorIM[]=
{
	{	PGEnumEnergyComsumer_MotorIM_Default,	"缺省设置",	},
	{	PGEnumEnergyComsumer_MotorIM_Stop,		"停止计算",	},
	{	PGEnumEnergyComsumer_MotorIM_Stall,		"堵转",		},
	{	PGEnumEnergyComsumer_MotorIM_Trip,		"切除",		},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_RCCase[]=
{
	{	PGEnumEnergyConsumer_RCCase_Norm,			"正常",				},
	{	PGEnumEnergyConsumer_RCCase_MinPathExceed,	"最小路超限",		},
};

static	tagMemDBEnumPair	g_PGEnumLoadPower_Property[]=
{
	{	0,		"公线",	},
	{	1,		"专线",	},
};

static	tagMemDBEnumPair	g_PGEnumLine_BreakingType[]=
{
	{	PGEnumLine_LineBreakingType_Breaker,		"断路器连接",	},
	{	PGEnumLine_LineBreakingType_Disconnector,	"隔离开关连接",	},
	{	PGEnumLine_LineBreakingType_Direct,			"直接连接",		},
};

static	tagMemDBEnumPair	g_PGEnumBranchFlow_Direction[]=
{
	{	PGEnum_BranchFlowDirection_Unknow,	"无向",		},
	{	PGEnum_BranchFlowDirection_I2J,		"I-J方向",	},
	{	PGEnum_BranchFlowDirection_J2I,		"J-I方向",	},
};

static	tagMemDBEnumPair	g_PGEnumBreakerFlow_Direction[]=
{
	{	PGEnum_BreakerFlowDirection_Unknow,		"无向",				},
	{	PGEnum_BreakerFlowDirection_BusOutP,	"出母线为正方向",	},
	{	PGEnum_BreakerFlowDirection_BusOutN,	"入母线为正方向",	},
};

static	tagMemDBEnumPair	g_PGEnumTransformerWinding_WindConn[]=
{
	{	PGEnum_TransformerWinding_WindConn_YY,	"Ｙ/Ｙ",		},
	{	PGEnum_TransformerWinding_WindConn_YD,	"Ｙ/Δ",		},
};

static	tagMemDBEnumPair	g_PGEnumTransformerWinding_WindType[]=
{
	{	PGEnumTransformerWinding_WindConnectio_2WIND,	"两卷变",		},
	{	PGEnumTransformerWinding_WindConnectio_2WYY,	"ＹＹ两卷变",	},
	{	PGEnumTransformerWinding_WindConnectio_2WYD,	"ＹΔ两卷变",	},
	{	PGEnumTransformerWinding_WindConnectio_3WY,	"Ｙ接线绕组",	},
	{	PGEnumTransformerWinding_WindConnectio_3WD,	"Δ接线绕组",	},
	{	PGEnumTransformerWinding_WindConnectio_3WAuto,	"自耦变绕组",	},
};

static	tagMemDBEnumPair	g_PGEnumBreaker_BreakerType[]=
{
	{	PGEnumBreakerType_Breaker,			"断路器",		},
	{	PGEnumBreakerType_BuslinkBreaker,	"母联开关",		},
	{	PGEnumBreakerType_HandCartBreaker,	"手车开关",		},
	{	PGEnumBreakerType_FuseBreaker,		"熔断式开关",	},
	{	PGEnumBreakerType_LoadBreakSwitch,	"负荷开关",		},
	{	PGEnumBreakerType_Disconnector,		"隔离开关",		},
	{	PGEnumBreakerType_Recloser,			"重合器",		},
};

static	tagMemDBEnumPair	g_PGEnumBreaker_BreakerFeature[]=
{
	{	PGEnumBreakerFeature_Normal,		"普通设备",		},
	{	PGEnumBreakerFeature_BusLink,		"母联开关",		},
	{	PGEnumBreakerFeature_Section,		"分段开关",		},
	{	PGEnumBreakerFeature_Linker,		"联络开关",		},
	{	PGEnumBreakerFeature_Pole,			"柱上开关",		},
};

static	tagMemDBEnumPair	g_PGEnumDisconnector_Disconnectortype[]=
{
	{	PGEnumDisconnectorType_Disconnector,	"隔离开关",		},
	{	PGEnumDisconnectorType_HandCart,		"手车刀闸",		},
};

static	tagMemDBEnumPair	g_PGEnumGraphAttr_LineStyle[]=
{
	{	PGEnumGraphAttrLineStyle_Continuous,	("CONTINUOUS"),	},
	{	PGEnumGraphAttrLineStyle_Dashed,		("DASHED"),		},
	{	PGEnumGraphAttrLineStyle_Center,		("CENTER"),		},
};

static	tagMemDBEnumPair	g_PGEnumProtAuto_Actmode[]=
{
	{	PGEnumProtAutoActmodeType_None,		"无",	},
	{	PGEnumProtAutoActmodeType_Max,		"最大",	},
	{	PGEnumProtAutoActmodeType_Min,		"最小",	},
	{	PGEnumProtAutoActmodeType_Cascade,	"相继",	},
};

static	tagMemDBEnumPair	g_PGEnumAreaCategory[]=
{
	{	PGEnumDistributionAreaCategory_APlus,	"A+",	},
	{	PGEnumDistributionAreaCategory_A,		"A",	},
	{	PGEnumDistributionAreaCategory_B,		"B",	},
	{	PGEnumDistributionAreaCategory_C,		"C",	},
	{	PGEnumDistributionAreaCategory_D,		"D",	},
	{	PGEnumDistributionAreaCategory_E,		"E",	},
	{	PGEnumDistributionAreaCategory_F,		"F",	},
};

static	tagMemDBEnumPair	g_PGEnumDEnergyConsumerType[]=
{
	{	PGEnumEnergyConsumerType_Transformer,	"配变",		},
	{	PGEnumEnergyConsumerType_Room,			"配电室",	},
};


static	tagMemDBEnumPair	g_PGEnumDSwitchType[]=
{
	{	PGEnumSwitchType_SwitchStation,			"开闭所",		},
	{	PGEnumSwitchType_SwitchGearCupBoard,	"环网柜",		},
	{	PGEnumSwitchType_CableBranchBox,		"电缆分支箱",	},
};

static	tagMemDBEnumPair	g_PGEnumDOilProperty[]=
{
	{	0,		"油",	},
	{	1,		"非油",	},
};

static	tagMemDBEnumPair	g_PGEnumDSwitch_Busbarmode[]=
{
	{	PGEnumSwitch_BusbarmodeType_OneBus,		"单母线",	},
	{	PGEnumSwitch_BusbarmodeType_TwoBus,		"双母线",	},
};

//	遥点级别
static	tagMemDBEnumPair	g_PGEnumDRTLevelType[]=
{
	{	PGEnumRTLevelType_None,		"无",	},
	{	PGEnumRTLevelType_YX,		"遥信",	},
	{	PGEnumRTLevelType_YC,		"遥测",	},
	{	PGEnumRTLevelType_YK,		"遥控",	},
	{	PGEnumRTLevelType_YT,		"遥调",	},
	{	PGEnumRTLevelType_YS,		"遥视",	},
};


//	通信方式
static	tagMemDBEnumPair	g_PGEnumDCommModeType[]=
{
	{	PGEnumCommModeType_None,	"无",	},
	{	PGEnumCommModeType_Fiber,	"光纤",	},
	{	PGEnumCommModeType_Wave,	"微波",	},
	{	PGEnumCommModeType_Wifi,	"无线",	},
};

//	规划性质
static	tagMemDBEnumPair	g_PGEnumDPlanCharacter[]=
{
	{	PGEnumPlanCharacter_Exist,		"已有",	},
	{	PGEnumPlanCharacter_Build,		"新建",	},
	{	PGEnumPlanCharacter_Expansion,	"扩建",	},
	{	PGEnumPlanCharacter_Change,		"改造",	},
};

//	运行状态
static	tagMemDBEnumPair	g_PGEnumRunStatus[]=
{
	{	PGEnumRunStatus_Run,	"在运",	},
	{	PGEnumRunStatus_Outage,	"停运",	},
};

//	运行状态
static	tagMemDBEnumPair	g_PGEnumDevCharacter[]=
{
	{	PGEnumCharacter_Unknown,	"未知",	},
	{	PGEnumCharacter_Section,	"分段",	},
	{	PGEnumCharacter_Contact,	"联络",	},
};

//	建设类型分类
static	tagMemDBEnumPair	g_PGEnumDConstructType[]=
{
	{	PGEnumConstructType_Indoor,				"户内",		},
	{	PGEnumConstructType_Outdoor,			"户外",		},
	{	PGEnumConstructType_HalfIndoors,		"半户内",	},
	{	PGEnumConstructType_Underground,		"地下",		},
	{	PGEnumConstructType_SemiUnderground,	"半地下",	},
};

//	工程性质
static	tagMemDBEnumPair	g_PGEnumDProjCharacter[]=
{
	{	PGEnumProjCharacter_None,		"",			},
	{	PGEnumProjCharacter_Utility,	"市政",		},
	{	PGEnumProjCharacter_Power,		"电网公司",	},
};

static	tagMemDBEnumPair	g_PGEnumDJunctionPoleType[]=
{
	{	PGEnumJunctionPoleType_Pole,			"电力杆塔",	},
	{	PGEnumJunctionPoleType_Junction,		"电缆终端",	},
	{	PGEnumJunctionPoleType_BusbarSection,	"厂站母线",	},
};

static	tagMemDBEnumPair	g_PGEnumDTransformer_MountType[]=
{
	{	PGEnumTransformer_MountType_Box,	"箱变",		},
	{	PGEnumTransformer_MountType_Pillar,	"柱上变",	},
	{	PGEnumTransformer_MountType_Room,	"配电室",	},
};

static	tagMemDBEnumPair	g_PGEnumDBreaker_MountType[]=
{
	{	PGEnumBreaker_MountType_Normal,	"普通",	},
	{	PGEnumBreaker_MountType_Pillar,	"柱上",	},
};
static	tagMemDBEnumPair	g_PGEnumDInvestMode[]=
{
	{	PGEnumInvestMode_NationInvest,		"中央资本金",			},
	{	PGEnumInvestMode_NationLoan,		"中央资本金配套贷款",	},
	{	PGEnumInvestMode_CompanyInvest,		"公司资本金",			},
	{	PGEnumInvestMode_CompanyLoan,		"公司资本配套贷款",		},
	{	PGEnumInvestMode_UserInvest,		"用户投资",				},
	{	PGEnumInvestMode_CommunityFee,		"小区配套费",			},
	{	PGEnumInvestMode_GovenorLoan,		"政府垫资",				},
	{	PGEnumInvestMode_CountySelf,		"县级供电企业自筹",		},
	{	PGEnumInvestMode_Other,				"其他",					},
};
static	tagMemDBEnumPair	g_PGEnumDProjectCategory[]=
{
	{	PGEnumProjectCategory_Unknown,				"未知",					},
	{	PGEnumProjectCategory_ImproveCapacity,		"提高供电能力",			},
	{	PGEnumProjectCategory_GridStrengthen,		"网架结构加强",			},
	{	PGEnumProjectCategory_PowerConnection,		"电源接入",				},
	{	PGEnumProjectCategory_PowerSupply,			"无电地区供电",			},
	{	PGEnumProjectCategory_SubstationAuxiliary,	"变电站配套送出",		},
	{	PGEnumProjectCategory_DistributionChange,	"配电网切改",			},
	{	PGEnumProjectCategory_LineInGround,			"架空线入地",			},
	{	PGEnumProjectCategory_DGConnection,			"分布电源接入",			},
};

static	tagMemDBEnumPair	g_PGEnumSubRegion_RegionType[]=
{
	{	PGEnumSubRegion_RegionType_L,	"大区",		},
	{	PGEnumSubRegion_RegionType_M,	"中区",		},
	{	PGEnumSubRegion_RegionType_S,	"小区",		},
};

//	配电自动化控制方式
static	tagMemDBEnumPair	g_PGEnumDistributionAutomationMode[]=
{
	{	PGEnumDistributionAutomationMode_None,						"无",				},
	{	PGEnumDistributionAutomationMode_FaultIndicator,			"故障指示器",		},
	{	PGEnumDistributionAutomationMode_FeederAutomation,			"馈线自动化",		},
	{	PGEnumDistributionAutomationMode_Master,					"主站控制",			},
	{	PGEnumDistributionAutomationMode_DistributedIntelligent,	"分布式智能控制",	},
};


//	通讯方式
static	tagMemDBEnumPair	g_PGEnumDCommunicationMode[]=
{
	{	PGEnumCommunicationMode_None,			"无",				},
	{	PGEnumCommunicationMode_Microwave,		"微波通讯网络",		},
	{	PGEnumCommunicationMode_OpticalFiber,	"光纤通讯网络",		},
	{	PGEnumCommunicationMode_GPRS,			"2G-GPRS无线网络",	},
	{	PGEnumCommunicationMode_CDMA,			"3G-CDMA无线网络",	},
	{	PGEnumCommunicationMode_LTE,			"4G-LTE无线网络",	},
	{	PGEnumCommunicationMode_WiMAx,			"城域无线网WiMAx",	},
};

//	配电自动化断路器控制方式
static	tagMemDBEnumPair	g_PGEnumDBreakerDAMode[]=
{
	{	PGEnumBreakerDAMode_None,			"无",			},
	{	PGEnumBreakerDAMode_FaultIndicator,	"故障指示器",	},
	{	PGEnumBreakerDAMode_FTU,			"FTU",			},
};

//	电动汽车充/换电站
static	tagMemDBEnumPair	g_PGEnumEVStationType[]=
{
	{	PGEnumEVStationType_Charge,		"即插即充式充电站",	},
	{	PGEnumEVStationType_Battery,	"电池更换站",		},
};
// static	tagMemDBEnumPair	g_PGEnumEVStationType[]=
// {
// 	{	PGEnumEVStationType_FillStation,	"综合性充换电站",	},
// 	{	PGEnumEVStationType_VECharge,		"整车充电站",		},
// 	{	PGEnumEVStationType_ACCharge,		"交流充电桩",		},
// 	{	PGEnumEVStationType_CVBattery,		"商务车换电站",		},
// 	{	PGEnumEVStationType_NVBattery,		"乘用车换电站",		},
// };
static	tagMemDBEnumPair	g_PGEnumEVLandType[]=
{
	{	PGEnumEVLandType_Resident,	"居民区",		},
	{	PGEnumEVLandType_Office,	"办公写字楼区",	},
	{	PGEnumEVLandType_Merchant,	"商业区",		},
	{	PGEnumEVLandType_Industry,	"工业区",		},
};

static	tagMemDBEnumPair	g_PGEnumEVServiceGroupType[]=
{
	{	PGEnumEVServiceGroupType_Private,	"私家车",	},
	{	PGEnumEVServiceGroupType_Public,	"公务用车",	},
	{	PGEnumEVServiceGroupType_Taxi,		"出租车",	},
};

static	tagMemDBEnumPair	g_PGThermalEnumEnergyConsumer_Type[]=
{
	{	PGEnumThermalEnergyConsumer_Type_None				,	"无",				},
	{	PGEnumThermalEnergyConsumer_Type_Production			,	"生产热负荷",		},
	{	PGEnumThermalEnergyConsumer_Type_Heating			,	"采暖热负荷",		},
	{	PGEnumThermalEnergyConsumer_Type_Ventilation		,	"通风热负荷",		},
	{	PGEnumThermalEnergyConsumer_Type_AirCondition		,	"空调热负荷",		},
	{	PGEnumThermalEnergyConsumer_Type_DomesticHotWater	,	"生活热水热负荷",	},
};
