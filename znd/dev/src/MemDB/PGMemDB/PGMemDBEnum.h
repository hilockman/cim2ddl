#pragma once

static	tagMemDBEnumPair	g_PGEnumTrueFalse[]=
{
	{	0,		"false",	},
	{	1,		"true",		},
};

static	tagMemDBEnumPair	g_PGEnumNoYes[]=
{
	{	0,		"��",	},
	{	1,		"��",	},
};

static	tagMemDBEnumPair	g_PGEnumYesNo[]=
{
	{	0,		"��",	},
	{	1,		"��",	},
};

static	tagMemDBEnumPair	g_PGDCPolar[]=
{
	{	0,		"����",	},
	{	1,		"����",	},
};

// static	tagMemDBEnumPair	g_PGEnumFaultType[]=
// {
// 	{	0,		"��������",	},
// 	{	1,		"�����·",	},
// 	{	2,		"�����·",	},
// 	{	3,		"����ӵ�",	},
// };

static	tagMemDBEnumPair	g_PGEnumFaultType[]=
{
	{	PGEnum_Scc_FaultType1,		"��������",	},
	{	PGEnum_Scc_FaultType2,		"�����·",	},
	{	PGEnum_Scc_FaultType3,		"�����·",	},
	{	PGEnum_Scc_FaultType4,		"����ӵ�",	},
};

static	tagMemDBEnumPair	g_PGEnumSccFMoveDataType[]=
{
	{	PGEnum_Scc_FMoveDataType_FC_I1Re,		"������·��·����I������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_FC_I1Im,		"������·��·����I�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_FC_I2Re,		"������·��·����I�ฺ��ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_FC_I2Im,		"������·��·����I�ฺ���鲿",	},
	{	PGEnum_Scc_FMoveDataType_FC_I0Re,		"������·��·����I������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_FC_I0Im,		"������·��·����I�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z1Re,		"������·��·����J������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z1Im,		"������·��·����J�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z2Re,		"������·��·����J�ฺ��ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z2Im,		"������·��·����J�ฺ���鲿",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z0Re,		"������·��·����J������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_FC_Z0Im,		"������·��·����J�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_MC_I1Re,		"������·��·����I������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MC_I1Im,		"������·��·����I�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_MC_I2Re,		"������·��·����I�ฺ��ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MC_I2Im,		"������·��·����I�ฺ���鲿",	},
	{	PGEnum_Scc_FMoveDataType_MC_I0Re,		"������·��·����I������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MC_I0Im,		"������·��·����I�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z1Re,		"������·��·����J������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z1Im,		"������·��·����J�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z2Re,		"������·��·����J�ฺ��ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z2Im,		"������·��·����J�ฺ���鲿",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z0Re,		"������·��·����J������ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MC_Z0Im,		"������·��·����J�������鲿",	},
	{	PGEnum_Scc_FMoveDataType_MV_1Re,		"����ĸ�ߵ�ѹ����ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MV_1Im,		"����ĸ�ߵ�ѹ�����鲿",	},
	{	PGEnum_Scc_FMoveDataType_MV_2Re,		"����ĸ�ߵ�ѹ����ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MV_2Im,		"����ĸ�ߵ�ѹ�����鲿",	},
	{	PGEnum_Scc_FMoveDataType_MV_0Re,		"����ĸ�ߵ�ѹ����ʵ��",	},
	{	PGEnum_Scc_FMoveDataType_MV_0Im,		"����ĸ�ߵ�ѹ�����鲿",	},
};

static	tagMemDBEnumPair	g_PGEnumCloseOpenStatus[]=
{
	{	PGEnumCloseOpenStatus_Close,	"��",	},
	{	PGEnumCloseOpenStatus_Open,		"��",	},
};

static	tagMemDBEnumPair	g_PGEnumPlateStatus[]=
{
	{	PGEnumPlateStatus_Close,		"Ͷ",	},
	{	PGEnumPlateStatus_Open,			"��",	},
};

static	tagMemDBEnumPair	g_PGEnumInjectionMCRDevType[]=
{
	{	PGEnumInjection_MCRType_Line,		"��·",		},
	{	PGEnumInjection_MCRType_Wind,		"��ѹ��",	},
};

static	tagMemDBEnumPair	g_PGEnumBranchMCRDevType[]=
{
	{	PGEnumBranch_MCRType_Load,		"����",	},
	{	PGEnumBranch_MCRType_Gen,		"��Դ",	},
};
static	tagMemDBEnumPair	g_PGMCEnumBreakerCTLoc[]=
{
	{	MCPhy_BreakerCTLoc_None,	"��",	},
	{	MCPhy_BreakerCTLoc_I,		"I��",	},
	{	MCPhy_BreakerCTLoc_J,		"J��",	},
	{	MCPhy_BreakerCTLoc_IJ,		"����",	},
};

static	tagMemDBEnumPair	g_PGEnumBreakerInnerType[]=
{
	{	PGEnum_BreakerInnerType_None,			"��",				},
	{	PGEnum_BreakerInnerType_BrLnXf,			"��ͨ��·��",		},
	{	PGEnum_BreakerInnerType_BrBus,			"ĸ��/�ֶζ�·��",	},
	{	PGEnum_BreakerInnerType_BrBypass,		"��·��·��",		},
	{	PGEnum_BreakerInnerType_BrBusBypass,	"��ĸ��·��",		},
	{	PGEnum_BreakerInnerType_Br32,			"3/2��·��",		},
};
static	tagMemDBEnumPair	g_PGEnumDisconnectorInnerType[]=
{
	{	PGEnum_DisconnectorInnerType_None,			"��",					},
	{	PGEnum_DisconnectorInnerType_SwLnXf,		"��ͨ���뿪��",			},
	{	PGEnum_DisconnectorInnerType_SwBusbar,		"ĸ�߸��뿪��",			},
	{	PGEnum_DisconnectorInnerType_SwBuslink,		"ĸ��/�ֶθ��뿪��",	},
	{	PGEnum_DisconnectorInnerType_SwLnXfBypass,	"�豸��·���뿪��",		},
	{	PGEnum_DisconnectorInnerType_SwBusBypass,	"��·���뿪��",			},
	{	PGEnum_DisconnectorInnerType_Sw32,			"3/2���뿪��",			},
	{	PGEnum_DisconnectorInnerType_BypassCross,	"��·����(���뿪��)",	},
	{	PGEnum_DisconnectorInnerType_SwGround,		"�ӵص�բ(���뿪��)",	},
};

static	tagMemDBEnumPair	g_PGEnumHideVisibleStatus[]=
{
	{	PGEnumHideVisibleStatus_Hide,		"����",	},
	{	PGEnumHideVisibleStatus_Visible,	"��ʾ",	},
};

static	tagMemDBEnumPair	g_PGEnumSaResult[]=
{
	{	PGEnumSaResult_Unknow,	"δ֪",		},
	{	PGEnumSaResult_Ceased,	"ͣ��",		},
	{	PGEnumSaResult_Ringed,	"�ϻ�",		},
	{	PGEnumSaResult_Failed,	"δͨ��",	},
	{	PGEnumSaResult_Passed,	"ͨ��",		},
};

static	tagMemDBEnumPair	g_PGEnumSubControlArea_Equity[]=
{
	{	0,	"ֱ��ֱ��",	},
	{	1,	"�ع�",		},
	{	2,	"����",		},
	{	3,	"����",		},
};

static	tagMemDBEnumPair	g_PGEnumSubstation_st_type[]=
{
	{	PGEnumst_type_Distribution,			"��Դվ",		},
	{	PGEnumst_type_Plant,				"�糧",			},
	{	PGEnumst_type_Substation,			"���վ",		},
	{	PGEnumst_type_Plant_Thermal,		"��糧",		},
	{	PGEnumst_type_Plant_Hydro,			"ˮ�糧",		},
	{	PGEnumst_type_Plant_Nuclear,		"�˵糧",		},
	{	PGEnumst_type_Plant_PumpedStorage,	"����糧",		},
	{	PGEnumst_type_Plant_Renewable,		"����Դ",		},
	{	PGEnumst_type_Converter_Station,	"����վ",		},
	{	PGEnumst_type_Plant_Outnet,			"��������վ",	},
};

static	tagMemDBEnumPair	g_PGEnumSubstationEntity_Type[]=
{
	{	PGEnumSubstationEntity_Distribution,		"��Դվ",		},
	{	PGEnumSubstationEntity_Plant,				"һ��糧",		},
	{	PGEnumSubstationEntity_Substation,			"���վ",		},
	{	PGEnumSubstationEntity_PlantThermal,		"��糧",		},
	{	PGEnumSubstationEntity_PlantHydro,			"ˮ�糧",		},
	{	PGEnumSubstationEntity_PlantNuclear,		"�˵糧",		},
	{	PGEnumSubstationEntity_PlantPumpedStorage,	"����糧",		},
	{	PGEnumSubstationEntity_PlantWindTurbine,	"��糡",		},
	{	PGEnumSubstationEntity_PlantPhotoVoltaic,	"�����վ",		},
	{	PGEnumSubstationEntity_PlantGeothermal,		"���ȵ糧",		},
	{	PGEnumSubstationEntity_ConverterStation,	"����վ",		},
	{	PGEnumSubstationEntity_Plant_Outnet,		"��������վ",	},
	{	PGEnumSubstationEntity_SwitchStation,		"����վ",		},
	{	PGEnumSubstationEntity_UserStation,			"�û�վ",		},
	{	PGEnumSubstationEntity_EVChargeStation,		"�任��վ",		},
};

static	tagMemDBEnumPair	g_PGEnumSynchronousMachine_Type[]=
{
	{	PGEnumSynchronousMachine_Type_Thermal,		"������",	},
	{	PGEnumSynchronousMachine_Type_Hydro,		"ˮ�����",	},
	{	PGEnumSynchronousMachine_Type_Gas,			"ȼ������",	},
	{	PGEnumSynchronousMachine_Type_Nuclear,		"�˵����",	},
	{	PGEnumSynchronousMachine_Type_Pump,			"�������",	},
	{	PGEnumSynchronousMachine_Type_WindTurbine,	"���",		},
	{	PGEnumSynchronousMachine_Type_PhotoVoltaic,	"���",		},
	{	PGEnumSynchronousMachine_Type_Equivalent,	"��ֵ����",	},
};

static	tagMemDBEnumPair	g_PGEnumLine_Connectmode[]=
{
	{	0,		"δ��",				},
	{	1,		"����",				},
	{	2,		"˫��",				},
	{	3,		"����",				},
	{	4,		"˫����",			},
	{	5,		"������",			},
	{	6,		"˫����",			},
	{	7,		"������",			},
	{	8,		"��ֶε�����",		},
	{	9,		"��ֶ��ʶ�����",	},
	{	10,		"����",				},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_Vacant[]=
{
	{	PGEnumLine_Vacant_None,		"������",	},
	{	PGEnumLine_Vacant_I,		"I����",	},
	{	PGEnumLine_Vacant_J,		"J����",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_LineType[]=
{
	{	PGEnumLine_LineType_Overhead,	"�ܿ�",	},
	{	PGEnumLine_LineType_Cable,		"����",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_LoadSide[]=
{
	{	0,		"�Զ�",		},
	{	1,		"����",	},
	{	2,		"�յ��",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_AutoLength[]=
{
	{	0,		"�˹�",	},
	{	1,		"�Զ�",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_TrunkLine[]=
{
	{	0,		"����",	},
	{	1,		"��֧",	},
};

static	tagMemDBEnumPair	g_PGEnumBusbarSection_BusbarId[]=
{
	{	PGEnumBusbarSection_BusbarId_1,		"#1ĸ��",	},
	{	PGEnumBusbarSection_BusbarId_2,		"#2ĸ��",	},
	{	PGEnumBusbarSection_BusbarId_3,		"#3ĸ��",	},
	{	PGEnumBusbarSection_BusbarId_4,		"#4ĸ��",	},
	{	PGEnumBusbarSection_BusbarId_5,		"#5ĸ��",	},
	{	PGEnumBusbarSection_BusbarId_6,		"#6ĸ��",	},
	{	PGEnumBusbarSection_BusbarId_7,		"#7ĸ��",	},
	{	PGEnumBusbarSection_BusbarId_8,		"#8ĸ��",	},
};

static	tagMemDBEnumPair	g_PGEnumACLineSegment_LineConstruction[]=
{
	{	0,	"�ܿ�",		},
	{	1,	"ֱ��",		},
	{	2,	"�Ź�",		},
	{	3,	"���",		},
	{	4,	"���¹�",	},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_Type[]=
{
	{	PGEnumEnergyConsumer_Type_Static,			"�ۺϸ���(�㹦�ʻ��ۺ�ģ��)",	},
	{	PGEnumEnergyConsumer_Type_Lump,				"����/���ȸ���(���迹)",		},
	//{	PGEnumEnergyConsumer_Type_Electrolysis,		"��⸺��(�����)",				},
	{	PGEnumEnergyConsumer_Type_IndMotor,			"��Ӧ���",						},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_MotorKLS0[]=
{
	{	PGEnumEnergyComsumer_MotorKLS0_KL,		"������",	},
	{	PGEnumEnergyComsumer_MotorKLS0_S0,		"��ʼ����",	},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_MotorIM[]=
{
	{	PGEnumEnergyComsumer_MotorIM_Default,	"ȱʡ����",	},
	{	PGEnumEnergyComsumer_MotorIM_Stop,		"ֹͣ����",	},
	{	PGEnumEnergyComsumer_MotorIM_Stall,		"��ת",		},
	{	PGEnumEnergyComsumer_MotorIM_Trip,		"�г�",		},
};

static	tagMemDBEnumPair	g_PGEnumEnergyConsumer_RCCase[]=
{
	{	PGEnumEnergyConsumer_RCCase_Norm,			"����",				},
	{	PGEnumEnergyConsumer_RCCase_MinPathExceed,	"��С·����",		},
};

static	tagMemDBEnumPair	g_PGEnumLoadPower_Property[]=
{
	{	0,		"����",	},
	{	1,		"ר��",	},
};

static	tagMemDBEnumPair	g_PGEnumLine_BreakingType[]=
{
	{	PGEnumLine_LineBreakingType_Breaker,		"��·������",	},
	{	PGEnumLine_LineBreakingType_Disconnector,	"���뿪������",	},
	{	PGEnumLine_LineBreakingType_Direct,			"ֱ������",		},
};

static	tagMemDBEnumPair	g_PGEnumTransformer_TSide[]=
{
	{	PGEnum_TransformerTSide_Unknow,	"δ֪",	},
	{	PGEnum_TransformerTSide_I,		"I��",	},
	{	PGEnum_TransformerTSide_J,		"J��",	},
};

static	tagMemDBEnumPair	g_PGEnumBranchFlow_Direction[]=
{
	{	PGEnum_BranchFlowDirection_Unknow,	"����",		},
	{	PGEnum_BranchFlowDirection_I2J,		"I-J����",	},
	{	PGEnum_BranchFlowDirection_J2I,		"J-I����",	},
};

static	tagMemDBEnumPair	g_PGEnumBreakerFlow_Direction[]=
{
	{	PGEnum_BreakerFlowDirection_Unknow,		"����",				},
	{	PGEnum_BreakerFlowDirection_BusOutP,	"��ĸ��Ϊ������",	},
	{	PGEnum_BreakerFlowDirection_BusOutN,	"��ĸ��Ϊ������",	},
};

static	tagMemDBEnumPair	g_PGEnumTransformerWinding_WindConn[]=
{
	{	PGEnum_TransformerWinding_WindConn_YY,	"��/��",		},
	{	PGEnum_TransformerWinding_WindConn_YD,	"��/��",		},
};

static	tagMemDBEnumPair	g_PGEnumTransformerWinding_WindType[]=
{
	{	PGEnumTransformerWinding_WindConnectio_2WIND,	"�����",		},
	{	PGEnumTransformerWinding_WindConnectio_2WYY,	"�٣������",	},
	{	PGEnumTransformerWinding_WindConnectio_2WYD,	"�٦������",	},
	{	PGEnumTransformerWinding_WindConnectio_3WY,	"�ٽ�������",	},
	{	PGEnumTransformerWinding_WindConnectio_3WD,	"����������",	},
	{	PGEnumTransformerWinding_WindConnectio_3WAuto,	"���������",	},
};

static	tagMemDBEnumPair	g_PGEnumBreaker_BreakerType[]=
{
	{	PGEnumBreakerType_Breaker,			"��·��",		},
	{	PGEnumBreakerType_BuslinkBreaker,	"ĸ������",		},
	{	PGEnumBreakerType_HandCartBreaker,	"�ֳ�����",		},
	{	PGEnumBreakerType_FuseBreaker,		"�۶�ʽ����",	},
	{	PGEnumBreakerType_LoadBreakSwitch,	"���ɿ���",		},
	{	PGEnumBreakerType_Disconnector,		"���뿪��",		},
	{	PGEnumBreakerType_Recloser,			"�غ���",		},
};

static	tagMemDBEnumPair	g_PGEnumBreaker_BreakerFeature[]=
{
	{	PGEnumBreakerFeature_Normal,		"��ͨ�豸",		},
	{	PGEnumBreakerFeature_BusLink,		"ĸ������",		},
	{	PGEnumBreakerFeature_Section,		"�ֶο���",		},
	{	PGEnumBreakerFeature_Linker,		"���翪��",		},
	{	PGEnumBreakerFeature_Pole,			"���Ͽ���",		},
};

static	tagMemDBEnumPair	g_PGEnumDisconnector_Disconnectortype[]=
{
	{	PGEnumDisconnectorType_Disconnector,	"���뿪��",		},
	{	PGEnumDisconnectorType_HandCart,		"�ֳ���բ",		},
};

static	tagMemDBEnumPair	g_PGEnumGraphAttr_LineStyle[]=
{
	{	PGEnumGraphAttrLineStyle_Continuous,	("CONTINUOUS"),	},
	{	PGEnumGraphAttrLineStyle_Dashed,		("DASHED"),		},
	{	PGEnumGraphAttrLineStyle_Center,		("CENTER"),		},
};

static	tagMemDBEnumPair	g_PGEnumProtAuto_Actmode[]=
{
	{	PGEnumProtAutoActmodeType_None,		"��",	},
	{	PGEnumProtAutoActmodeType_Max,		"���",	},
	{	PGEnumProtAutoActmodeType_Min,		"��С",	},
	{	PGEnumProtAutoActmodeType_Cascade,	"���",	},
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
	{	PGEnumEnergyConsumerType_Transformer,	"���",		},
	{	PGEnumEnergyConsumerType_Room,			"�����",	},
};


static	tagMemDBEnumPair	g_PGEnumDSwitchType[]=
{
	{	PGEnumSwitchType_SwitchStation,			"������",		},
	{	PGEnumSwitchType_SwitchGearCupBoard,	"������",		},
	{	PGEnumSwitchType_CableBranchBox,		"���·�֧��",	},
};

static	tagMemDBEnumPair	g_PGEnumDOilProperty[]=
{
	{	0,		"��",	},
	{	1,		"����",	},
};

static	tagMemDBEnumPair	g_PGEnumDSwitch_Busbarmode[]=
{
	{	PGEnumSwitch_BusbarmodeType_OneBus,		"��ĸ��",	},
	{	PGEnumSwitch_BusbarmodeType_TwoBus,		"˫ĸ��",	},
};

//	ң�㼶��
static	tagMemDBEnumPair	g_PGEnumDRTLevelType[]=
{
	{	PGEnumRTLevelType_None,		"��",	},
	{	PGEnumRTLevelType_YX,		"ң��",	},
	{	PGEnumRTLevelType_YC,		"ң��",	},
	{	PGEnumRTLevelType_YK,		"ң��",	},
	{	PGEnumRTLevelType_YT,		"ң��",	},
	{	PGEnumRTLevelType_YS,		"ң��",	},
};


//	ͨ�ŷ�ʽ
static	tagMemDBEnumPair	g_PGEnumDCommModeType[]=
{
	{	PGEnumCommModeType_None,	"��",	},
	{	PGEnumCommModeType_Fiber,	"����",	},
	{	PGEnumCommModeType_Wave,	"΢��",	},
	{	PGEnumCommModeType_Wifi,	"����",	},
};

//	�滮����
static	tagMemDBEnumPair	g_PGEnumDPlanCharacter[]=
{
	{	PGEnumPlanCharacter_Exist,		"����",	},
	{	PGEnumPlanCharacter_Build,		"�½�",	},
	{	PGEnumPlanCharacter_Expansion,	"����",	},
	{	PGEnumPlanCharacter_Change,		"����",	},
};

//	����״̬
static	tagMemDBEnumPair	g_PGEnumRunStatus[]=
{
	{	PGEnumRunStatus_Run,	"����",	},
	{	PGEnumRunStatus_Outage,	"ͣ��",	},
};

//	����״̬
static	tagMemDBEnumPair	g_PGEnumDevCharacter[]=
{
	{	PGEnumCharacter_Unknown,	"δ֪",	},
	{	PGEnumCharacter_Section,	"�ֶ�",	},
	{	PGEnumCharacter_Contact,	"����",	},
};

//	�������ͷ���
static	tagMemDBEnumPair	g_PGEnumDConstructType[]=
{
	{	PGEnumConstructType_Indoor,				"����",		},
	{	PGEnumConstructType_Outdoor,			"����",		},
	{	PGEnumConstructType_HalfIndoors,		"�뻧��",	},
	{	PGEnumConstructType_Underground,		"����",		},
	{	PGEnumConstructType_SemiUnderground,	"�����",	},
};

//	��������
static	tagMemDBEnumPair	g_PGEnumDProjCharacter[]=
{
	{	PGEnumProjCharacter_None,		"",			},
	{	PGEnumProjCharacter_Utility,	"����",		},
	{	PGEnumProjCharacter_Power,		"������˾",	},
};

static	tagMemDBEnumPair	g_PGEnumDJunctionPoleType[]=
{
	{	PGEnumJunctionPoleType_Pole,			"��������",	},
	{	PGEnumJunctionPoleType_Junction,		"�����ն�",	},
	{	PGEnumJunctionPoleType_BusbarSection,	"��վĸ��",	},
};

static	tagMemDBEnumPair	g_PGEnumDTransformer_MountType[]=
{
	{	PGEnumTransformer_MountType_Box,	"���",		},
	{	PGEnumTransformer_MountType_Pillar,	"���ϱ�",	},
	{	PGEnumTransformer_MountType_Room,	"�����",	},
};

static	tagMemDBEnumPair	g_PGEnumDBreaker_MountType[]=
{
	{	PGEnumBreaker_MountType_Normal,	"��ͨ",	},
	{	PGEnumBreaker_MountType_Pillar,	"����",	},
};
static	tagMemDBEnumPair	g_PGEnumDInvestMode[]=
{
	{	PGEnumInvestMode_NationInvest,		"�����ʱ���",			},
	{	PGEnumInvestMode_NationLoan,		"�����ʱ������״���",	},
	{	PGEnumInvestMode_CompanyInvest,		"��˾�ʱ���",			},
	{	PGEnumInvestMode_CompanyLoan,		"��˾�ʱ����״���",		},
	{	PGEnumInvestMode_UserInvest,		"�û�Ͷ��",				},
	{	PGEnumInvestMode_CommunityFee,		"С�����׷�",			},
	{	PGEnumInvestMode_GovenorLoan,		"��������",				},
	{	PGEnumInvestMode_CountySelf,		"�ؼ�������ҵ�Գ�",		},
	{	PGEnumInvestMode_Other,				"����",					},
};
static	tagMemDBEnumPair	g_PGEnumDProjectCategory[]=
{
	{	PGEnumProjectCategory_Unknown,				"δ֪",					},
	{	PGEnumProjectCategory_ImproveCapacity,		"��߹�������",			},
	{	PGEnumProjectCategory_GridStrengthen,		"���ܽṹ��ǿ",			},
	{	PGEnumProjectCategory_PowerConnection,		"��Դ����",				},
	{	PGEnumProjectCategory_PowerSupply,			"�޵��������",			},
	{	PGEnumProjectCategory_SubstationAuxiliary,	"���վ�����ͳ�",		},
	{	PGEnumProjectCategory_DistributionChange,	"������и�",			},
	{	PGEnumProjectCategory_LineInGround,			"�ܿ������",			},
	{	PGEnumProjectCategory_DGConnection,			"�ֲ���Դ����",			},
};

static	tagMemDBEnumPair	g_PGEnumSubRegion_RegionType[]=
{
	{	PGEnumSubRegion_RegionType_L,	"����",		},
	{	PGEnumSubRegion_RegionType_M,	"����",		},
	{	PGEnumSubRegion_RegionType_S,	"С��",		},
};

//	����Զ������Ʒ�ʽ
static	tagMemDBEnumPair	g_PGEnumDistributionAutomationMode[]=
{
	{	PGEnumDistributionAutomationMode_None,						"��",				},
	{	PGEnumDistributionAutomationMode_FaultIndicator,			"����ָʾ��",		},
	{	PGEnumDistributionAutomationMode_FeederAutomation,			"�����Զ���",		},
	{	PGEnumDistributionAutomationMode_Master,					"��վ����",			},
	{	PGEnumDistributionAutomationMode_DistributedIntelligent,	"�ֲ�ʽ���ܿ���",	},
};


//	ͨѶ��ʽ
static	tagMemDBEnumPair	g_PGEnumDCommunicationMode[]=
{
	{	PGEnumCommunicationMode_None,			"��",				},
	{	PGEnumCommunicationMode_Microwave,		"΢��ͨѶ����",		},
	{	PGEnumCommunicationMode_OpticalFiber,	"����ͨѶ����",		},
	{	PGEnumCommunicationMode_GPRS,			"2G-GPRS��������",	},
	{	PGEnumCommunicationMode_CDMA,			"3G-CDMA��������",	},
	{	PGEnumCommunicationMode_LTE,			"4G-LTE��������",	},
	{	PGEnumCommunicationMode_WiMAx,			"����������WiMAx",	},
};

//	����Զ�����·�����Ʒ�ʽ
static	tagMemDBEnumPair	g_PGEnumDBreakerDAMode[]=
{
	{	PGEnumBreakerDAMode_None,			"��",			},
	{	PGEnumBreakerDAMode_FaultIndicator,	"����ָʾ��",	},
	{	PGEnumBreakerDAMode_FTU,			"FTU",			},
};

//	�綯������/����վ
static	tagMemDBEnumPair	g_PGEnumEVStationType[]=
{
	{	PGEnumEVStationType_Charge,		"���弴��ʽ���վ",	},
	{	PGEnumEVStationType_Battery,	"��ظ���վ",		},
};
// static	tagMemDBEnumPair	g_PGEnumEVStationType[]=
// {
// 	{	PGEnumEVStationType_FillStation,	"�ۺ��Գ任��վ",	},
// 	{	PGEnumEVStationType_VECharge,		"�������վ",		},
// 	{	PGEnumEVStationType_ACCharge,		"�������׮",		},
// 	{	PGEnumEVStationType_CVBattery,		"���񳵻���վ",		},
// 	{	PGEnumEVStationType_NVBattery,		"���ó�����վ",		},
// };
static	tagMemDBEnumPair	g_PGEnumEVLandType[]=
{
	{	PGEnumEVLandType_Resident,	"������",		},
	{	PGEnumEVLandType_Office,	"�칫д��¥��",	},
	{	PGEnumEVLandType_Merchant,	"��ҵ��",		},
	{	PGEnumEVLandType_Industry,	"��ҵ��",		},
};

static	tagMemDBEnumPair	g_PGEnumEVServiceGroupType[]=
{
	{	PGEnumEVServiceGroupType_Private,	"˽�ҳ�",	},
	{	PGEnumEVServiceGroupType_Public,	"�����ó�",	},
	{	PGEnumEVServiceGroupType_Taxi,		"���⳵",	},
};

static	tagMemDBEnumPair	g_PGThermalEnumEnergyConsumer_Type[]=
{
	{	PGEnumThermalEnergyConsumer_Type_None				,	"��",				},
	{	PGEnumThermalEnergyConsumer_Type_Production			,	"�����ȸ���",		},
	{	PGEnumThermalEnergyConsumer_Type_Heating			,	"��ů�ȸ���",		},
	{	PGEnumThermalEnergyConsumer_Type_Ventilation		,	"ͨ���ȸ���",		},
	{	PGEnumThermalEnergyConsumer_Type_AirCondition		,	"�յ��ȸ���",		},
	{	PGEnumThermalEnergyConsumer_Type_DomesticHotWater	,	"������ˮ�ȸ���",	},
};

static	tagMemDBEnumPair	g_PGEnumConverterDCControlMode[]=
{
	{	PGEnumConverterDCControlMode_None,		"�޿���",	},
	{	PGEnumConverterDCControlMode_PConst,	"������",	},
	{	PGEnumConverterDCControlMode_VConst,	"����ѹ",	},
};

static	tagMemDBEnumPair	g_PGEnumConverterType[]=
{
	{	PGEnumConverterType_None,		"δ֪",			},
	{	PGEnumConverterType_Connect,	"�����任��",	},
	{	PGEnumConverterType_Isolate,	"�µ��任��",	},
	{	PGEnumConverterType_Liaison,	"����任��",	},
};

static	tagMemDBEnumPair	g_PGEnumIslandType[]=
{
	{	PGEnumIslandType_Unknown,	"δ֪",	},
	{	PGEnumIslandType_ACConnect,	"��������",	},
	{	PGEnumIslandType_DCConnect,	"ֱ������",	},
	{	PGEnumIslandType_ACIsolate,	"��������",	},
	{	PGEnumIslandType_DCIsolate,	"ֱ������",	},
	{	PGEnumIslandType_ACGrid,	"��������",	},
	{	PGEnumIslandType_DCGrid,	"ֱ������",	},
};
