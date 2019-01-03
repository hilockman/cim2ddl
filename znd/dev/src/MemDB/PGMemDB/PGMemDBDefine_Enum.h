#pragma once


//////////////////////////////////////////////////////////////////////////
//	数据库字段相关枚举
enum	_PGEnum_CloseOpenStatus_
{
	PGEnumCloseOpenStatus_Close=0,
	PGEnumCloseOpenStatus_Open,
};
enum	_PGEnum_PlateStatus_
{
	PGEnumPlateStatus_Close=0,
	PGEnumPlateStatus_Open,
};

enum	_PGEnum_HideVisibleStatus_
{
	PGEnumHideVisibleStatus_Hide=0,
	PGEnumHideVisibleStatus_Visible,
};
enum	_PGEnum_SaResult_
{
	PGEnumSaResult_Unknow=0,
	PGEnumSaResult_Ceased,
	PGEnumSaResult_Ringed,
	PGEnumSaResult_Failed,
	PGEnumSaResult_Passed,
};

enum	_PGEnum_Scc_FaultType_
{
	PGEnum_Scc_FaultType1=0,
	PGEnum_Scc_FaultType2,
	PGEnum_Scc_FaultType3,
	PGEnum_Scc_FaultType4,
};

enum	_PGEnum_SccFMove_DataType_
{
	PGEnum_Scc_FMoveDataType_FC_I1Re=0,
	PGEnum_Scc_FMoveDataType_FC_I1Im,
	PGEnum_Scc_FMoveDataType_FC_I2Re,
	PGEnum_Scc_FMoveDataType_FC_I2Im,
	PGEnum_Scc_FMoveDataType_FC_I0Re,
	PGEnum_Scc_FMoveDataType_FC_I0Im,
	PGEnum_Scc_FMoveDataType_FC_Z1Re,
	PGEnum_Scc_FMoveDataType_FC_Z1Im,
	PGEnum_Scc_FMoveDataType_FC_Z2Re,
	PGEnum_Scc_FMoveDataType_FC_Z2Im,
	PGEnum_Scc_FMoveDataType_FC_Z0Re,
	PGEnum_Scc_FMoveDataType_FC_Z0Im,
	PGEnum_Scc_FMoveDataType_MC_I1Re,
	PGEnum_Scc_FMoveDataType_MC_I1Im,
	PGEnum_Scc_FMoveDataType_MC_I2Re,
	PGEnum_Scc_FMoveDataType_MC_I2Im,
	PGEnum_Scc_FMoveDataType_MC_I0Re,
	PGEnum_Scc_FMoveDataType_MC_I0Im,
	PGEnum_Scc_FMoveDataType_MC_Z1Re,
	PGEnum_Scc_FMoveDataType_MC_Z1Im,
	PGEnum_Scc_FMoveDataType_MC_Z2Re,
	PGEnum_Scc_FMoveDataType_MC_Z2Im,
	PGEnum_Scc_FMoveDataType_MC_Z0Re,
	PGEnum_Scc_FMoveDataType_MC_Z0Im,
	PGEnum_Scc_FMoveDataType_MV_1Re,
	PGEnum_Scc_FMoveDataType_MV_1Im,
	PGEnum_Scc_FMoveDataType_MV_2Re,
	PGEnum_Scc_FMoveDataType_MV_2Im,
	PGEnum_Scc_FMoveDataType_MV_0Re,
	PGEnum_Scc_FMoveDataType_MV_0Im,
};

enum	_PGEnum_Substation_st_type
{
	PGEnumst_type_Distribution=0,
	PGEnumst_type_Plant,
	PGEnumst_type_Substation,
	PGEnumst_type_Plant_Thermal,
	PGEnumst_type_Plant_Hydro,
	PGEnumst_type_Plant_Nuclear,
	PGEnumst_type_Plant_PumpedStorage,
	PGEnumst_type_Plant_Renewable,
	PGEnumst_type_Converter_Station,
	PGEnumst_type_Plant_Outnet,
};
enum	_PGEnum_SubstationEntity_Type
{
	PGEnumSubstationEntity_Distribution=0,
	PGEnumSubstationEntity_Plant,
	PGEnumSubstationEntity_Substation,
	PGEnumSubstationEntity_PlantThermal,
	PGEnumSubstationEntity_PlantHydro,
	PGEnumSubstationEntity_PlantNuclear,
	PGEnumSubstationEntity_PlantPumpedStorage,
	PGEnumSubstationEntity_PlantWindTurbine,
	PGEnumSubstationEntity_PlantPhotoVoltaic,
	PGEnumSubstationEntity_PlantGeothermal,
	PGEnumSubstationEntity_ConverterStation,
	PGEnumSubstationEntity_Plant_Outnet,
	PGEnumSubstationEntity_SwitchStation,
	PGEnumSubstationEntity_UserStation,
	PGEnumSubstationEntity_EVChargeStation,
};
enum	_PGEnum_SynchronousMachine_Type
{
	PGEnumSynchronousMachine_Type_Thermal=0,
	PGEnumSynchronousMachine_Type_Hydro,
	PGEnumSynchronousMachine_Type_Gas,
	PGEnumSynchronousMachine_Type_Nuclear,
	PGEnumSynchronousMachine_Type_Pump,
	PGEnumSynchronousMachine_Type_WindTurbine,
	PGEnumSynchronousMachine_Type_PhotoVoltaic,
	PGEnumSynchronousMachine_Type_Equivalent,
};
enum	_PGEnum_Line_Vacant
{
	PGEnumLine_Vacant_None=0,
	PGEnumLine_Vacant_I,
	PGEnumLine_Vacant_J,
};
enum	_PGEnum_Line_LineType
{
	PGEnumLine_LineType_Overhead=0,
	PGEnumLine_LineType_Cable,
};
enum	_PGEnum_BusbarSection_BusbarId
{
	PGEnumBusbarSection_BusbarId_1=0,
	PGEnumBusbarSection_BusbarId_2,
	PGEnumBusbarSection_BusbarId_3,
	PGEnumBusbarSection_BusbarId_4,
	PGEnumBusbarSection_BusbarId_5,
	PGEnumBusbarSection_BusbarId_6,
	PGEnumBusbarSection_BusbarId_7,
	PGEnumBusbarSection_BusbarId_8,
};
enum	_PGEnum_EnergyConsumer_Type
{
	PGEnumEnergyConsumer_Type_Static=0,
	PGEnumEnergyConsumer_Type_Lump,
	//PGEnumEnergyConsumer_Type_Heat,
	//PGEnumEnergyConsumer_Type_Pump,
	//PGEnumEnergyConsumer_Type_Electrolysis,
	//PGEnumEnergyConsumer_Type_Rectifier,
	PGEnumEnergyConsumer_Type_IndMotor,
};

enum	_PGEnum_EnergyConsumer_MotorKLS0
{
	PGEnumEnergyComsumer_MotorKLS0_KL=0,
	PGEnumEnergyComsumer_MotorKLS0_S0,
};

enum	_PGEnum_EnergyConsumer_MotorIM
{
	PGEnumEnergyComsumer_MotorIM_Default=0,
	PGEnumEnergyComsumer_MotorIM_Stop,
	PGEnumEnergyComsumer_MotorIM_Stall,
	PGEnumEnergyComsumer_MotorIM_Trip,
};

enum	_PGEnum_EnergyConsumer_RCCase
{
	PGEnumEnergyConsumer_RCCase_Norm=0,
	PGEnumEnergyConsumer_RCCase_MinPathExceed,
};

enum	_PGEnum_InjectionMCType
{
	PGEnumInjection_MCRType_Line = 0,
	PGEnumInjection_MCRType_Wind,
};

enum	_PGEnum_LineTranMCType
{
	PGEnumBranch_MCRType_Load = 0,
	PGEnumBranch_MCRType_Gen,
};

enum	_PGEnum_Line_BreakingType
{
	PGEnumLine_LineBreakingType_Breaker=0,
	PGEnumLine_LineBreakingType_Disconnector,
	PGEnumLine_LineBreakingType_Direct,
};
enum	_PGEnum_Transformer_TSide
{
	PGEnum_TransformerTSide_Unknow=0,
	PGEnum_TransformerTSide_I,
	PGEnum_TransformerTSide_J,
};

enum	_PGEnum_BranchFlowDirection
{
	PGEnum_BranchFlowDirection_Unknow=0,
	PGEnum_BranchFlowDirection_I2J,
	PGEnum_BranchFlowDirection_J2I,
};
enum	_PGEnum_BreakerInnerType
{
	PGEnum_BreakerInnerType_None = 0,
	PGEnum_BreakerInnerType_BrLnXf,
	PGEnum_BreakerInnerType_BrBus,
	PGEnum_BreakerInnerType_BrBypass,
	PGEnum_BreakerInnerType_BrBusBypass,
	PGEnum_BreakerInnerType_Br32,
};
enum	_PGEnum_DisconnectorInnerType
{
	PGEnum_DisconnectorInnerType_None = 0,
	PGEnum_DisconnectorInnerType_SwLnXf,
	PGEnum_DisconnectorInnerType_SwBusbar,
	PGEnum_DisconnectorInnerType_SwBuslink,
	PGEnum_DisconnectorInnerType_SwLnXfBypass,
	PGEnum_DisconnectorInnerType_SwBusBypass,
	PGEnum_DisconnectorInnerType_Sw32,
	PGEnum_DisconnectorInnerType_BypassCross,
	PGEnum_DisconnectorInnerType_SwGround,
};
enum	_PGEnum_BreakerCTLocation
{
	MCPhy_BreakerCTLoc_None = 0,
	MCPhy_BreakerCTLoc_I,
	MCPhy_BreakerCTLoc_J,
	MCPhy_BreakerCTLoc_IJ,
};
enum	_PGEnum_BreakerFlowDirection
{
	PGEnum_BreakerFlowDirection_Unknow=0,
	PGEnum_BreakerFlowDirection_BusOutP,
	PGEnum_BreakerFlowDirection_BusOutN,
};
enum	_PGEnum_TransformerWinding_WindConn
{
	PGEnum_TransformerWinding_WindConn_YY=0,
	PGEnum_TransformerWinding_WindConn_YD,
};
enum	_PGEnum_TransformerWinding_WindType
{
	PGEnumTransformerWinding_WindConnectio_2WIND=0,
	PGEnumTransformerWinding_WindConnectio_2WYY,
	PGEnumTransformerWinding_WindConnectio_2WYD,
	PGEnumTransformerWinding_WindConnectio_3WY,
	PGEnumTransformerWinding_WindConnectio_3WD,
	PGEnumTransformerWinding_WindConnectio_3WAuto,
};
enum	_PGEnum_BreakerType
{
	PGEnumBreakerType_Breaker=0,
	PGEnumBreakerType_BuslinkBreaker,
	PGEnumBreakerType_HandCartBreaker,
	PGEnumBreakerType_FuseBreaker,
	PGEnumBreakerType_LoadBreakSwitch,
	PGEnumBreakerType_Disconnector,
	PGEnumBreakerType_Recloser,
};
enum	_PGEnum_BreakerFeature
{
	PGEnumBreakerFeature_Normal=0,
	PGEnumBreakerFeature_BusLink,
	PGEnumBreakerFeature_Section,
	PGEnumBreakerFeature_Linker,
	PGEnumBreakerFeature_Pole,
};

enum	_PGEnum_DisconnectorType
{
	PGEnumDisconnectorType_Disconnector=0,
	PGEnumDisconnectorType_HandCart,
};

enum	_PGEnum_GraphAttrLineStyle
{
	PGEnumGraphAttrLineStyle_Continuous=0,
	PGEnumGraphAttrLineStyle_Dashed,
	PGEnumGraphAttrLineStyle_Center,
};

enum	_PGEnum_ProtAutoActmodeType
{
	PGEnumProtAutoActmodeType_None=0,
	PGEnumProtAutoActmodeType_Max,
	PGEnumProtAutoActmodeType_Min,
	PGEnumProtAutoActmodeType_Cascade,
};

//	供电区域分类
enum	_PGEnum_AreaCategory
{
	PGEnumDistributionAreaCategory_APlus=0,
	PGEnumDistributionAreaCategory_A,
	PGEnumDistributionAreaCategory_B,
	PGEnumDistributionAreaCategory_C,
	PGEnumDistributionAreaCategory_D,
	PGEnumDistributionAreaCategory_E,
	PGEnumDistributionAreaCategory_F,
};
enum	_PGEnum_EnergyConsumerType
{
	PGEnumEnergyConsumerType_Transformer=0,
	PGEnumEnergyConsumerType_Room,
};
enum	_PGEnum_SwitchType
{
	PGEnumSwitchType_SwitchStation=0,
	PGEnumSwitchType_SwitchGearCupBoard,
	PGEnumSwitchType_CableBranchBox,
};
enum	_PGEnum_Switch_BusbarmodeType
{
	PGEnumSwitch_BusbarmodeType_OneBus=0,
	PGEnumSwitch_BusbarmodeType_TwoBus,
};
//	遥点级别
enum	_PGEnum_RTLevelType
{
	PGEnumRTLevelType_None=0,
	PGEnumRTLevelType_YX,
	PGEnumRTLevelType_YC,
	PGEnumRTLevelType_YK,
	PGEnumRTLevelType_YT,
	PGEnumRTLevelType_YS,
};
//	通信方式
enum	_PGEnum_CommModeType
{
	PGEnumCommModeType_None=0,
	PGEnumCommModeType_Fiber,
	PGEnumCommModeType_Wave,
	PGEnumCommModeType_Wifi,
};
//	规划性质
enum	_PGEnum_PlanCharacter
{
	PGEnumPlanCharacter_Exist=0,
	PGEnumPlanCharacter_Build,
	PGEnumPlanCharacter_Expansion,
	PGEnumPlanCharacter_Change,
};
//	运行状态
enum	_PGEnum_RunStatus
{
	PGEnumRunStatus_Run=0,
	PGEnumRunStatus_Outage,
};
enum	_PGEnum_Character
{
	PGEnumCharacter_Unknown=0,
	PGEnumCharacter_Section,
	PGEnumCharacter_Contact,
};

//	建设类型分类
enum	_PGEnum_ConstructType
{
	PGEnumConstructType_Indoor=0,
	PGEnumConstructType_Outdoor,
	PGEnumConstructType_HalfIndoors,
	PGEnumConstructType_Underground,
	PGEnumConstructType_SemiUnderground,
};
//	工程性质
enum	_PGEnum_ProjCharacterType
{
	PGEnumProjCharacter_None=0,
	PGEnumProjCharacter_Utility,
	PGEnumProjCharacter_Power,
};
enum	_PGEnum_JunctionPoleType
{
	PGEnumJunctionPoleType_Pole=0,
	PGEnumJunctionPoleType_Junction,
	PGEnumJunctionPoleType_BusbarSection,
};
enum	_PGEnumTransformer_MountType
{
	PGEnumTransformer_MountType_Box=0,
	PGEnumTransformer_MountType_Pillar,
	PGEnumTransformer_MountType_Room,
};
enum	_PGEnumBreaker_MountType
{
	PGEnumBreaker_MountType_Normal=0,
	PGEnumBreaker_MountType_Pillar,
};
enum	_PGEnum_InvestMode
{
	PGEnumInvestMode_NationInvest=0,
	PGEnumInvestMode_NationLoan,
	PGEnumInvestMode_CompanyInvest,
	PGEnumInvestMode_CompanyLoan,
	PGEnumInvestMode_UserInvest,
	PGEnumInvestMode_CommunityFee,
	PGEnumInvestMode_GovenorLoan,
	PGEnumInvestMode_CountySelf,
	PGEnumInvestMode_Other,
};
enum	_PGEnum_ProjectCategory
{
	PGEnumProjectCategory_Unknown=0,
	PGEnumProjectCategory_ImproveCapacity,
	PGEnumProjectCategory_GridStrengthen,
	PGEnumProjectCategory_PowerConnection,
	PGEnumProjectCategory_PowerSupply,
	PGEnumProjectCategory_SubstationAuxiliary,
	PGEnumProjectCategory_DistributionChange,
	PGEnumProjectCategory_LineInGround,
	PGEnumProjectCategory_DGConnection,
};

enum	_PGEnumSubRegion_RegionType
{
	PGEnumSubRegion_RegionType_L=0,
	PGEnumSubRegion_RegionType_M,
	PGEnumSubRegion_RegionType_S,
};

//	配电自动化控制方式
enum	_PGEnum_DistributionAutomationMode
{
	PGEnumDistributionAutomationMode_None=0,
	PGEnumDistributionAutomationMode_FaultIndicator,
	PGEnumDistributionAutomationMode_FeederAutomation,
	PGEnumDistributionAutomationMode_Master,
	PGEnumDistributionAutomationMode_DistributedIntelligent,
};

//	通讯方式
enum	_PGEnum_CommunicationMode
{
	PGEnumCommunicationMode_None=0,
	PGEnumCommunicationMode_Microwave,
	PGEnumCommunicationMode_OpticalFiber,
	PGEnumCommunicationMode_GPRS,
	PGEnumCommunicationMode_CDMA,
	PGEnumCommunicationMode_LTE,
	PGEnumCommunicationMode_WiMAx,
};

//	配电自动化断路器控制方式
enum	_PGEnum_BreakerDAMode
{
	PGEnumBreakerDAMode_None=0,
	PGEnumBreakerDAMode_FaultIndicator,
	PGEnumBreakerDAMode_FTU,
};

//	电动汽车充/换电站
enum	_PGEnum_EVStationType
{
	PGEnumEVStationType_Charge=0,
	PGEnumEVStationType_Battery,
};
//	enum	_PGEnum_EleVehicleStationType
//	{
//		PGEnumEVStationType_FillStation=0,
//		PGEnumEVStationType_VECharge,
//		PGEnumEVStationType_ACCharge,
//		PGEnumEVStationType_CVBattery,
//		PGEnumEVStationType_NVBattery,
//	};

enum	_PGEnum_EVLandType
{
	PGEnumEVLandType_Resident=0,
	PGEnumEVLandType_Office,
	PGEnumEVLandType_Merchant,
	PGEnumEVLandType_Industry,
};
enum	_PGEnum_EVServiceGroupType
{
	PGEnumEVServiceGroupType_Private=0,
	PGEnumEVServiceGroupType_Public,
	PGEnumEVServiceGroupType_Taxi,
};

enum	_PGEnum_ThermalEnergyConsumer_Type
{
	PGEnumThermalEnergyConsumer_Type_None			=0	,
	PGEnumThermalEnergyConsumer_Type_Production			,
	PGEnumThermalEnergyConsumer_Type_Heating			,
	PGEnumThermalEnergyConsumer_Type_Ventilation		,
	PGEnumThermalEnergyConsumer_Type_AirCondition		,
	PGEnumThermalEnergyConsumer_Type_DomesticHotWater	,
};

enum	_PGEnum_ConverterDCControl_Mode
{
	PGEnumConverterDCControlMode_None	=0	,
	PGEnumConverterDCControlMode_PConst	,
	PGEnumConverterDCControlMode_VConst	,
};

enum	_PGEnum_Converter_Type
{
	PGEnumConverterType_None	=0	,
	PGEnumConverterType_Connect	,
	PGEnumConverterType_Isolate	,
	PGEnumConverterType_Liaison	,
};

enum	_PGEnum_PGEnumIsland_Type
{
	PGEnumIslandType_Unknown	=0	,
	PGEnumIslandType_ACConnect	,
	PGEnumIslandType_DCConnect	,
	PGEnumIslandType_ACIsolate	,
	PGEnumIslandType_DCIsolate	,
	PGEnumIslandType_ACGrid	,
	PGEnumIslandType_DCGrid	,
};
