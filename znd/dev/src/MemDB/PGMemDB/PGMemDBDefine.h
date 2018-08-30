#pragma	once

#include	"../include/MDBDefine.h"

#define		GIS701StandardSupport

#if	defined(__GNUG__)	||	defined(__GNUC__)	//	GCC编译器预定义的宏
#	ifndef	DISALIGN
#		define	DISALIGN	__attribute__((packed))
#	endif
#else
#	define	DISALIGN
#endif

#if	!defined(__GNUG__)	&&	!defined(__GNUC__)
#	if	(defined(_AIX)	||	defined(AIX))
#		pragma	align(packed)
#	else
#		if	(!defined(sun)	&&	!defined(__sun)	&&	!defined(__sun__))
#			pragma	pack(push)
#		endif
#	endif
#	pragma	pack(1)
#endif

const	int	PGND_CHARLEN=MDB_CHARLEN;

const		int	g_nMaxPGPipeHVCable=4;
const		int	g_nMaxPGPipeMVCable=8;
const		int	g_nMaxPGPipeLVCable=32;

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

enum	_PGEnum_LineTranMCType
{
	PGEnumLineTran_MCType_Load = 0,
	PGEnumLineTran_MCType_Gen,
	PGEnumLineTran_MCType_Edge,
};

enum	_PGEnum_Line_BreakingType
{
	PGEnumLine_LineBreakingType_Breaker=0,
	PGEnumLine_LineBreakingType_Disconnector,
	PGEnumLine_LineBreakingType_Direct,
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

//////////////////////////////////////////////////////////////////////////
//	数据库字段相关定义
enum	_PGEnum_Field_BaseVoltage_	{
	PG_BASEVOLTAGE_RESOURCEID=0,
	PG_BASEVOLTAGE_NAME,
	PG_BASEVOLTAGE_NOMINALVOLTAGE,
	PG_BASEVOLTAGE_LOWVLIMIT,
	PG_BASEVOLTAGE_HIGVHLIMIT,
	PG_BASEVOLTAGE_SCALIMIT,
};
struct	_PG_BaseVoltage_	{
	char	szResID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN_SHORT];
	float	nominalVoltage;
	float	lowVLimit;
	float	highVLimit;
	float	scALimit;
}	DISALIGN;
typedef	struct	_PG_BaseVoltage_	tagPGBaseVoltage;

enum	_PGEnum_Field_TapChanger_	{
	PG_TAPCHANGER_RESOURCEID=0,
	PG_TAPCHANGER_NAME,
	PG_TAPCHANGER_DESCRIPTION,
	PG_TAPCHANGER_TAPMIN,
	PG_TAPCHANGER_TAPMAX,
	PG_TAPCHANGER_TAPNOM,
	PG_TAPCHANGER_TAPNEUTRAL,
	PG_TAPCHANGER_TAPSTEP,
};
struct	_PG_TapChanger_	{
	char	szResID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN_SHORT];
	char	szDesp[MDB_CHARLEN];
	unsigned char	nTapMin;
	unsigned char	nTapMax;
	unsigned char	nTapNom;
	unsigned char	nTapNeu;
	float	fTapStep;
}	DISALIGN;
typedef	struct	_PG_TapChanger_	tagPGTapChanger;

//	容器表定义
//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_System_	{
	PG_SYSTEM_RESOURCEID=0,
	PG_SYSTEM_NAME,
	PG_SYSTEM_DESCRIPTION,
	PG_SYSTEM_STID,
	PG_SYSTEM_UNID,
	PG_SYSTEM_BASEPOWER,
	PG_SYSTEM_DATE,
	PG_SYSTEM_TIME,

	PG_SYSTEM_SC1RATIO,
	PG_SYSTEM_SC2RATIO,
	PG_SYSTEM_SC3RATIO,
	PG_SYSTEM_SC4RATIO,

	PG_SYSTEM_EI_INVEST,
	PG_SYSTEM_EI_SPRICE,
	PG_SYSTEM_EI_PPRICE,
	PG_SYSTEM_EI_IYRATE,
	PG_SYSTEM_EI_ICYCLE,
	PG_SYSTEM_EI_CREDTIME,
	PG_SYSTEM_EI_CONSTIME,
	PG_SYSTEM_EI_DEPRECTIME,
	PG_SYSTEM_EI_RESIDUAL,
	PG_SYSTEM_EI_TAXRATE,
	PG_SYSTEM_EI_REPAIRFEE,
	PG_SYSTEM_EI_INSURFEE,

	PG_SYSTEM_PROT_KER,
	PG_SYSTEM_G2EFACTOR,
	PG_SYSTEM_E2HFACTOR,
	PG_SYSTEM_E2CFACTOR,
	PG_SYSTEM_ESTOREGEFACTOR,

	PG_SYSTEM_TOTALGENP,
	PG_SYSTEM_TOTALGENQ,
	PG_SYSTEM_TOTALLOADP,
	PG_SYSTEM_TOTALLOADQ,
	PG_SYSTEM_TOTALCAP,
	PG_SYSTEM_TOTALREAC,

	PG_SYSTEM_RUNNINGGENP,
	PG_SYSTEM_RUNNINGGENQ,
	PG_SYSTEM_RUNNINGLOADP,
	PG_SYSTEM_RUNNINGLOADQ,
	PG_SYSTEM_RUNNINGCAP,
	PG_SYSTEM_RUNNINGREAC,

	PG_SYSTEM_LOSSP,
	PG_SYSTEM_LOSSQ,
	PG_SYSTEM_LOSSRATE,

	PG_SYSTEM_BUSOVERLOADIDX,		
	PG_SYSTEM_BUSOVERLOADNUM,		

	PG_SYSTEM_LINEOVERLOADIDX,
	PG_SYSTEM_LINEOVERLOADNUM,
	PG_SYSTEM_LINELOADRATE100,	
	PG_SYSTEM_LINELOADRATE80,	
	PG_SYSTEM_LINELOADRATE60,	
	PG_SYSTEM_LINELOADRATE40,	
	PG_SYSTEM_LINELOADRATE20,
	PG_SYSTEM_LINELOADRATE0,

	PG_SYSTEM_TRANOVERLOADIDX,
	PG_SYSTEM_TRANOVERLOADNUM,
	PG_SYSTEM_TRANLOADRATE100,	
	PG_SYSTEM_TRANLOADRATE80,	
	PG_SYSTEM_TRANLOADRATE60,	
	PG_SYSTEM_TRANLOADRATE40,	
	PG_SYSTEM_TRANLOADRATE20,
	PG_SYSTEM_TRANLOADRATE0,

	PG_SYSTEM_DEADISLANDLOADP,
	PG_SYSTEM_DEADISLANDLOADQ,

	PG_SYSTEM_RO_CUSTOMERNUM,

	PG_SYSTEM_RO_ACI,
	PG_SYSTEM_RO_CID,
	PG_SYSTEM_RO_SAIFI,
	PG_SYSTEM_RO_SAIDI,
	PG_SYSTEM_RO_ASAI,
	PG_SYSTEM_RO_ENS,
	PG_SYSTEM_RO_AENS,
	PG_SYSTEM_RO_MIC,
	PG_SYSTEM_RO_MID,

	PG_SYSTEM_RO_F_ACI,
	PG_SYSTEM_RO_F_CID,
	PG_SYSTEM_RO_F_SAIFI,
	PG_SYSTEM_RO_F_SAIDI,
	PG_SYSTEM_RO_F_ASAI,
	PG_SYSTEM_RO_F_ENS,
	PG_SYSTEM_RO_F_AENS,
	PG_SYSTEM_RO_F_MIC,
	PG_SYSTEM_RO_F_MID,

	PG_SYSTEM_RO_A_ACI,
	PG_SYSTEM_RO_A_CID,
	PG_SYSTEM_RO_A_SAIFI,
	PG_SYSTEM_RO_A_SAIDI,
	PG_SYSTEM_RO_A_ASAI,
	PG_SYSTEM_RO_A_ENS,
	PG_SYSTEM_RO_A_AENS,
	PG_SYSTEM_RO_A_MIC,
	PG_SYSTEM_RO_A_MID,

	PG_SYSTEM_EO_ELESUPPLY,
	PG_SYSTEM_EO_ELECOST,
	PG_SYSTEM_EO_ELEINCOME,
	PG_SYSTEM_EO_RCOEF,
	PG_SYSTEM_EO_LOSSCOST,
	PG_SYSTEM_EO_RELICOST,
	PG_SYSTEM_EO_FUNDCOST,
	PG_SYSTEM_EO_INCOME,
	PG_SYSTEM_EO_EVRELICOST,
	PG_SYSTEM_EO_EVINCOME,

	PG_SYSTEM_SA_LINEPASSRATE,
	PG_SYSTEM_SA_LINELOSSPOWER,
	PG_SYSTEM_SA_UNITPASSRATE,
	PG_SYSTEM_SA_UNITLOSSPOWER,
	PG_SYSTEM_SA_COMBPASSRATE,	
	PG_SYSTEM_SA_COMBLOSSPOWER,

};
struct	_PG_System_	{
	char	szResID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	char	szSlackSub[MDB_CHARLEN];
	char	szSlackGen[MDB_CHARLEN];
	float	fBasePower;
	int		nDate;
	int		nTime;

	float	fSc1Ratio;
	float	fSc2Ratio;
	float	fSc3Ratio;
	float	fSc4Ratio;

	//	经济性计算输入数据
	float	ei_Invest;
	float	ei_sprice;
	float	ei_pprice;
	float	ei_iyrate;
	unsigned char	ei_icycle;
	unsigned char	ei_credtime;
	unsigned char	ei_constime;
	unsigned char	ei_deprectime;
	float	ei_residual;
	float	ei_taxrate;
	float	ei_repairfee;
	float	ei_insurefee;

	float	fProtKer;

	float	fG2EFactor;
	float	fE2HFactor;
	float	fE2CFactor;
	float	fEStorageEfficiency;

	float	fTotalGenP;
	float	fTotalGenQ;
	float	fTotalLoadP;
	float	fTotalLoadQ;
	float	fTotalCap;
	float	fTotalReac;

	float	fRunningGenP;
	float	fRunningGenQ;
	float	fRunningLoadP;
	float	fRunningLoadQ;
	float	fRunningCap;
	float	fRunningReac;

	float	fOLBusIdx;
	short	nOLBusNum;

	float	fLineOverLoadIdx;
	short	nLineOverLoad;
	short	nLineRate100;
	short	nLineRate80;
	short	nLineRate60;
	short	nLineRate40;
	short	nLineRate20;
	short	nLineRate0;

	float	fTranOverLoadIdx;
	short	nTranOverLoad;
	short	nTranRate100;
	short	nTranRate80;
	short	nTranRate60;
	short	nTranRate40;
	short	nTranRate20;
	short	nTranRate0;

	float	fLossP;
	float	fLossQ;
	float	fLossRate;

	float	fDeadIslandLoadP;
	float	fDeadIslandLoadQ;

	//	系统可靠性指标，可靠性计算输出数据
	double	ro_customernum;

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

	//	经济性计算输出数据
	float	eo_elesupply;
	float	eo_elecost;
	float	eo_eleincome;

	float	eo_rcoef;
	float	eo_losscost;
	float	eo_relicost;
	float	eo_fundcost;
	float	eo_income;

	float	eo_evrelicost;
	float	eo_evincome;

	float	sa_LinePassRate;
	float	sa_LineLossPower;
	float	sa_UnitPassRate;
	float	sa_UnitLossPower;
	float	sa_CombPassRate;
	float	sa_CombLossPower;
}	DISALIGN;
typedef	struct	_PG_System_	tagPGSystem;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Company_	{
	PG_COMPANY_RESOURCEID=0,
	PG_COMPANY_OBJECTID,
	PG_COMPANY_NAME,
	PG_COMPANY_DESCRIPTION,
	PG_COMPANY_STID,
	PG_COMPANY_UNID,

	PG_COMPANY_TOTALGENP,
	PG_COMPANY_TOTALGENQ,
	PG_COMPANY_TOTALLOADP,
	PG_COMPANY_TOTALLOADQ,
	PG_COMPANY_TOTALCAP,
	PG_COMPANY_TOTALREAC,

	PG_COMPANY_RUNNINGGENP,		
	PG_COMPANY_RUNNINGGENQ,		
	PG_COMPANY_RUNNINGLOADP,	
	PG_COMPANY_RUNNINGLOADQ,	
	PG_COMPANY_RUNNINGCAP,		
	PG_COMPANY_RUNNINGREAC,

	PG_COMPANY_LOSSP,
	PG_COMPANY_LOSSQ,
	PG_COMPANY_TIEP,
	PG_COMPANY_TIEQ,

	PG_COMPANY_EI_INVEST,
	PG_COMPANY_EI_SPRICE,
	PG_COMPANY_EI_PPRICE,
	PG_COMPANY_EI_IYRATE,
	PG_COMPANY_EI_ICYCLE,
	PG_COMPANY_EI_CREDTIME,
	PG_COMPANY_EI_CONSTIME,
	PG_COMPANY_EI_DEPRECTIME,
	PG_COMPANY_EI_RESIDUAL,
	PG_COMPANY_EI_TAXRATE,
	PG_COMPANY_EI_REPAIRFEE,
	PG_COMPANY_EI_INSURFEE,

	PG_COMPANY_RO_CUSTOMERNUM,

	PG_COMPANY_RO_ACI,
	PG_COMPANY_RO_CID,
	PG_COMPANY_RO_SAIFI,
	PG_COMPANY_RO_SAIDI,
	PG_COMPANY_RO_ASAI,
	PG_COMPANY_RO_ENS,
	PG_COMPANY_RO_AENS,
	PG_COMPANY_RO_MIC,
	PG_COMPANY_RO_MID,

	PG_COMPANY_RO_F_ACI,
	PG_COMPANY_RO_F_CID,
	PG_COMPANY_RO_F_SAIFI,
	PG_COMPANY_RO_F_SAIDI,
	PG_COMPANY_RO_F_ASAI,
	PG_COMPANY_RO_F_ENS,
	PG_COMPANY_RO_F_AENS,
	PG_COMPANY_RO_F_MIC,
	PG_COMPANY_RO_F_MID,

	PG_COMPANY_RO_A_ACI,
	PG_COMPANY_RO_A_CID,
	PG_COMPANY_RO_A_SAIFI,
	PG_COMPANY_RO_A_SAIDI,
	PG_COMPANY_RO_A_ASAI,
	PG_COMPANY_RO_A_ENS,
	PG_COMPANY_RO_A_AENS,
	PG_COMPANY_RO_A_MIC,
	PG_COMPANY_RO_A_MID,

	PG_COMPANY_EO_ELESUPPLY,
	PG_COMPANY_EO_ELECOST,
	PG_COMPANY_EO_ELEINCOME,
	PG_COMPANY_EO_RCOEF,
	PG_COMPANY_EO_LOSSCOST,
	PG_COMPANY_EO_RELICOST,
	PG_COMPANY_EO_FUNDCOST,
	PG_COMPANY_EO_INCOME,
	PG_COMPANY_EO_EVRELICOST,
	PG_COMPANY_EO_EVINCOME,
};

struct	_PG_Company_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN_SHORT];
	char	szDesp[MDB_CHARLEN];
	char	szSlackSub[MDB_CHARLEN];
	char	szSlackGen[MDB_CHARLEN];

	float	fTotalGenP;
	float	fTotalGenQ;
	float	fTotalLoadP;
	float	fTotalLoadQ;
	float	fTotalCap;
	float	fTotalReac;

	float	fRunningGenP;
	float	fRunningGenQ;
	float	fRunningLoadP;
	float	fRunningLoadQ;
	float	fRunningCap;
	float	fRunningReac;

	float	fLossP;
	float	fLossQ;
	float	fTieP;
	float	fTieQ;

	//	经济性计算输入数据
	float	ei_Invest;
	float	ei_sprice;
	float	ei_pprice;
	float	ei_iyrate;
	unsigned char	ei_icycle;
	unsigned char	ei_credtime;
	unsigned char	ei_constime;
	unsigned char	ei_deprectime;
	float	ei_residual;
	float	ei_taxrate;
	float	ei_repairfee;
	float	ei_insurefee;

	//	系统可靠性指标，可靠性计算输出数据
	double	ro_customernum;
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

	//	经济性计算输出数据
	float	eo_elesupply;
	float	eo_elecost;
	float	eo_eleincome;
	float	eo_rcoef;
	float	eo_losscost;
	float	eo_relicost;
	float	eo_fundcost;
	float	eo_income;

	float	eo_evrelicost;
	float	eo_evincome;
}	DISALIGN;
typedef	struct	_PG_Company_	tagPGCompany;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_SubControlArea_	{
	PG_SUBCONTROLAREA_RESOURCEID=0,
	PG_SUBCONTROLAREA_OBJECTID,
	PG_SUBCONTROLAREA_NAME,
	PG_SUBCONTROLAREA_DESCRIPTION,
	PG_SUBCONTROLAREA_COMPANY,
	PG_SUBCONTROLAREA_EQUITY,

	PG_SUBCONTROLAREA_TOTALGENP,
	PG_SUBCONTROLAREA_TOTALGENQ,
	PG_SUBCONTROLAREA_TOTALLOADP,
	PG_SUBCONTROLAREA_TOTALLOADQ,
	PG_SUBCONTROLAREA_TOTALCAP,
	PG_SUBCONTROLAREA_TOTALREAC,

	PG_SUBCONTROLAREA_RUNNINGGENP,
	PG_SUBCONTROLAREA_RUNNINGGENQ,
	PG_SUBCONTROLAREA_RUNNINGLOADP,
	PG_SUBCONTROLAREA_RUNNINGLOADQ,
	PG_SUBCONTROLAREA_RUNNINGCAP,
	PG_SUBCONTROLAREA_RUNNINGREAC,

	PG_SUBCONTROLAREA_LOSSP,
	PG_SUBCONTROLAREA_LOSSQ,

	PG_SUBCONTROLAREA_EI_INVEST,
	PG_SUBCONTROLAREA_EI_SPRICE,
	PG_SUBCONTROLAREA_EI_PPRICE,
	PG_SUBCONTROLAREA_EI_IYRATE,
	PG_SUBCONTROLAREA_EI_ICYCLE,
	PG_SUBCONTROLAREA_EI_CREDTIME,
	PG_SUBCONTROLAREA_EI_CONSTIME,
	PG_SUBCONTROLAREA_EI_DEPRECTIME,
	PG_SUBCONTROLAREA_EI_RESIDUAL,
	PG_SUBCONTROLAREA_EI_TAXRATE,
	PG_SUBCONTROLAREA_EI_REPAIRFEE,
	PG_SUBCONTROLAREA_EI_INSURFEE,

	PG_SUBCONTROLAREA_LOADMODEL,

	PG_SUBCONTROLAREA_RO_CUSTOMERNUM,

	PG_SUBCONTROLAREA_RO_ACI,
	PG_SUBCONTROLAREA_RO_CID,
	PG_SUBCONTROLAREA_RO_SAIFI,
	PG_SUBCONTROLAREA_RO_SAIDI,
	PG_SUBCONTROLAREA_RO_ASAI,
	PG_SUBCONTROLAREA_RO_ENS,
	PG_SUBCONTROLAREA_RO_AENS,
	PG_SUBCONTROLAREA_RO_MIC,
	PG_SUBCONTROLAREA_RO_MID,

	PG_SUBCONTROLAREA_RO_F_ACI,
	PG_SUBCONTROLAREA_RO_F_CID,
	PG_SUBCONTROLAREA_RO_F_SAIFI,
	PG_SUBCONTROLAREA_RO_F_SAIDI,
	PG_SUBCONTROLAREA_RO_F_ASAI,
	PG_SUBCONTROLAREA_RO_F_ENS,
	PG_SUBCONTROLAREA_RO_F_AENS,
	PG_SUBCONTROLAREA_RO_F_MIC,
	PG_SUBCONTROLAREA_RO_F_MID,

	PG_SUBCONTROLAREA_RO_A_ACI,
	PG_SUBCONTROLAREA_RO_A_CID,
	PG_SUBCONTROLAREA_RO_A_SAIFI,
	PG_SUBCONTROLAREA_RO_A_SAIDI,
	PG_SUBCONTROLAREA_RO_A_ASAI,
	PG_SUBCONTROLAREA_RO_A_ENS,
	PG_SUBCONTROLAREA_RO_A_AENS,
	PG_SUBCONTROLAREA_RO_A_MIC,
	PG_SUBCONTROLAREA_RO_A_MID,

	PG_SUBCONTROLAREA_RO_RCONTRIBUTION,
	PG_SUBCONTROLAREA_RO_UCONTRIBUTION,
	PG_SUBCONTROLAREA_RO_ENSCONTRIBUTION,

	PG_SUBCONTROLAREA_EO_ELESUPPLY,
	PG_SUBCONTROLAREA_EO_ELECOST,
	PG_SUBCONTROLAREA_EO_ELEINCOME,
	PG_SUBCONTROLAREA_EO_RCOEF,
	PG_SUBCONTROLAREA_EO_LOSSCOST,
	PG_SUBCONTROLAREA_EO_RELICOST,
	PG_SUBCONTROLAREA_EO_FUNDCOST,
	PG_SUBCONTROLAREA_EO_INCOME,
	PG_SUBCONTROLAREA_EO_EVRELICOST,
	PG_SUBCONTROLAREA_EO_EVINCOME,

	PG_SUBCONTROLAREA_AREACATEGORY,
	PG_SUBCONTROLAREA_AREA,
};

struct	_PG_SubControlArea_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN_SHORT];
	char	szDesp[MDB_CHARLEN];
	char	szCompany[MDB_CHARLEN_SHORT];
	unsigned char	nEquity;

	float	fTotalGenP;
	float	fTotalGenQ;
	float	fTotalLoadP;
	float	fTotalLoadQ;
	float	fTotalCap;
	float	fTotalReac;

	float	fRunningGenP;
	float	fRunningGenQ;
	float	fRunningLoadP;
	float	fRunningLoadQ;
	float	fRunningCap;
	float	fRunningReac;

	float	fLossP;
	float	fLossQ;

	//	经济性计算输入数据
	float	ei_Invest;
	float	ei_sprice;
	float	ei_pprice;
	float	ei_iyrate;
	unsigned char	ei_icycle;
	unsigned char	ei_credtime;
	unsigned char	ei_constime;
	unsigned char	ei_deprectime;
	float	ei_residual;
	float	ei_taxrate;
	float	ei_repairfee;
	float	ei_insurefee;

	char	szLoadModel[MDB_CHARLEN];

	//	系统可靠性指标，可靠性计算输出数据
	double	ro_customernum;
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

	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;

	//	经济性计算输出数据
	float	eo_elesupply;
	float	eo_elecost;
	float	eo_eleincome;

	float	eo_rcoef;
	float	eo_losscost;
	float	eo_relicost;
	float	eo_fundcost;
	float	eo_income;

	float	eo_evrelicost;
	float	eo_evincome;

	//	配网补充数据
	unsigned char	nAreaCategory;
	float	fArea;
}	DISALIGN;
typedef	struct	_PG_SubControlArea_	tagPGSubcontrolArea;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Substation_	{
	PG_SUBSTATION_RESOURCEID=0,
	PG_SUBSTATION_OBJECTID,
	PG_SUBSTATION_NAME,
	PG_SUBSTATION_DESCRIPTION,
	PG_SUBSTATION_COMPANY,
	PG_SUBSTATION_SUBCONTROLAREA,
	PG_SUBSTATION_ST_TYPE,
	PG_SUBSTATION_CAPACITY,

	PG_SUBSTATION_EI_INVEST,

	PG_SUBSTATION_TOTALGENP,
	PG_SUBSTATION_TOTALGENQ,
	PG_SUBSTATION_TOTALLOADP,
	PG_SUBSTATION_TOTALLOADQ,
	PG_SUBSTATION_TOTALCAP,
	PG_SUBSTATION_TOTALREAC,

	PG_SUBSTATION_RUNNINGGENP,
	PG_SUBSTATION_RUNNINGGENQ,
	PG_SUBSTATION_RUNNINGLOADP,
	PG_SUBSTATION_RUNNINGLOADQ,
	PG_SUBSTATION_RUNNINGCAP,
	PG_SUBSTATION_RUNNINGREAC,

	PG_SUBSTATION_GENFATCTOR,
	PG_SUBSTATION_LOADFATCTOR,

	PG_SUBSTATION_SA_RESULT,
	PG_SUBSTATION_SA_ISLAND,
	PG_SUBSTATION_SA_FAILURE,
	PG_SUBSTATION_SA_OUTAGES,

	PG_SUBSTATION_VOLTAGELEVELRANGE,
	PG_SUBSTATION_POWERTRANSFORMERRANGE,
	PG_SUBSTATION_TRANSFORMERWINDINGRANGE,
	PG_SUBSTATION_RECTIFIERINVERTERRANGE,
	PG_SUBSTATION_DISTRIBUTION,
	PG_SUBSTATION_PARENTTYPE,
	PG_SUBSTATION_HUB,
	PG_SUBSTATION_NOPTIMIZE,
	PG_SUBSTATION_OUTAGE,
};

struct	_PG_Substation_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	char	szCompany[MDB_CHARLEN_SHORT];
	char	szSubcontrolArea[MDB_CHARLEN_SHORT];
	unsigned char	st_type;
	float	fCapacity;

	//	经济性计算输入数据
	float	ei_Invest;

	float	fTotalGenP;
	float	fTotalGenQ;
	float	fTotalLoadP;
	float	fTotalLoadQ;
	float	fTotalCap;
	float	fTotalReac;

	float	fRunningGenP;
	float	fRunningGenQ;
	float	fRunningLoadP;
	float	fRunningLoadQ;
	float	fRunningCap;
	float	fRunningReac;

	float	fGenFatctor;
	float	fLoadFatctor;

	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;

	short	nVoltageLevelRange;
	short	nPowerTransformerRange;
	short	nTransformerWindingRange;
	short	nRectifierInverterRange;

	unsigned char	bDistribution;
	unsigned char	nParentType;
	unsigned char	bHub;
	unsigned char	bNOptimize;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_Substation_	tagPGSubstation;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_VoltageLevel_	{
	PG_VOLTAGELEVEL_RESOURCEID=0,
	PG_VOLTAGELEVEL_SUBSTATION,
	PG_VOLTAGELEVEL_NAME,
	PG_VOLTAGELEVEL_DESCRIPTION,
	PG_VOLTAGELEVEL_NOMINALVOLTAGE,
	PG_VOLTAGELEVEL_HIGHVOLTAGELIMIT,
	PG_VOLTAGELEVEL_LOWVOLTAGELIMIT,
	PG_VOLTAGELEVEL_SUBSTATIONPTR,
	PG_VOLTAGELEVEL_BUSBARSECTIONRANGE,
	PG_VOLTAGELEVEL_SYNCHRONOUSMACHINERANGE,
	PG_VOLTAGELEVEL_ENERGYCONSUMERRANGE,
	PG_VOLTAGELEVEL_SHUNTCOMPENSATORRANGE,
	PG_VOLTAGELEVEL_SERIESCOMPENSATORRANGE,
	PG_VOLTAGELEVEL_BREAKERRANGE,
	PG_VOLTAGELEVEL_DISCONNECTORRANGE,
	PG_VOLTAGELEVEL_GROUNDDISCONNECTORRANGE,
	PG_VOLTAGELEVEL_GROUNDTRANSFORMERRANGE,
	PG_VOLTAGELEVEL_CONNECTIVITYNODERANGE,
	//PG_VOLTAGELEVEL_TERMINALRANGE,
	PG_VOLTAGELEVEL_OUTAGE,
};
struct	_PG_VoltageLevel_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szName[MDB_CHARLEN_SHORTER];
	char	szDesp[MDB_CHARLEN];
	float	nominalVoltage;
	float	highVoltageLimit;
	float	lowVoltageLimit;

	short	nSubstationPtr;
	short	nBusbarSectionRange;
	short	nSynchronousMachineRange;
	short	nEnergyConsumerRange;
	short	nShuntCompensatorRange;
	short	nSeriesCompensatorRange;
	int		nBreakerRange;
	int		nDisconnectorRange;
	int		nGroundDisconnectorRange;
	short	nGroundTransformerRange;
	int		nConnecivityNodeRange;
	//int	nTerminalRange;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_VoltageLevel_	tagPGVoltageLevel;

//	设备表定义
//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_BusbarSection_	{
	PG_BUSBARSECTION_RESOURCEID=0,
	PG_BUSBARSECTION_OBJECTID,
	PG_BUSBARSECTION_SUBSTATION,
	PG_BUSBARSECTION_VOLTAGELEVEL,
	PG_BUSBARSECTION_NAME,
	PG_BUSBARSECTION_DESCRIPTION,
	//PG_BUSBARSECTION_TERMINAL,
	PG_BUSBARSECTION_CONNECTIVITYNODE,
	//PG_BUSBARSECTION_LINESEGMENT,
	//PG_BUSBARSECTION_BUSBARID,
	PG_BUSBARSECTION_V,
	PG_BUSBARSECTION_D,
	PG_BUSBARSECTION_F,
	PG_BUSBARSECTION_VLIMITL,
	PG_BUSBARSECTION_VLIMITH,
	PG_BUSBARSECTION_LOADP,
	PG_BUSBARSECTION_LOADQ,
	PG_BUSBARSECTION_GENP,
	PG_BUSBARSECTION_GENQ,
	PG_BUSBARSECTION_SHUNTQ,
	PG_BUSBARSECTION_EFERENCEV,
	PG_BUSBARSECTION_RI_RERR,
	PG_BUSBARSECTION_RI_TREP,
	PG_BUSBARSECTION_RI_RCHK,
	PG_BUSBARSECTION_RI_TCHK,
	PG_BUSBARSECTION_RI_TFLOC,
	PG_BUSBARSECTION_RI_LOAD_RERR,
	PG_BUSBARSECTION_RI_LOAD_TREP,
	PG_BUSBARSECTION_RI_LOAD_RCHK,
	PG_BUSBARSECTION_RI_LOAD_TCHK,
	PG_BUSBARSECTION_EI_INVEST,

	PG_BUSBARSECTION_VD_RSCC1,
	PG_BUSBARSECTION_VD_RSCC2,
	PG_BUSBARSECTION_VD_RSCC3,
	PG_BUSBARSECTION_VD_RSCC4,
	PG_BUSBARSECTION_SCIA,
	PG_BUSBARSECTION_SCIB,
	PG_BUSBARSECTION_SCIC,
	PG_BUSBARSECTION_SCVA,
	PG_BUSBARSECTION_SCVB,
	PG_BUSBARSECTION_SCVC,
	PG_BUSBARSECTION_SCV1,
	PG_BUSBARSECTION_SCV2,
	PG_BUSBARSECTION_SCV0,

	PG_BUSBARSECTION_RO_RCONTRIBUTION,
	PG_BUSBARSECTION_RO_UCONTRIBUTION,
	PG_BUSBARSECTION_RO_ENSCONTRIBUTION,

	PG_BUSBARSECTION_ERRP,
	PG_BUSBARSECTION_ERRQ,
	PG_BUSBARSECTION_BYPASS,
	PG_BUSBARSECTION_NODEPTR,
	PG_BUSBARSECTION_TOPOBUS,
	PG_BUSBARSECTION_ISLAND,
	PG_BUSBARSECTION_PSEDO,
	PG_BUSBARSECTION_PARENTTYPE,
	PG_BUSBARSECTION_STATE,
	PG_BUSBARSECTION_INRING,
	PG_BUSBARSECTION_RADIATE,
	PG_BUSBARSECTION_OPEN,
};
struct	_PG_BusbarSection_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	//char	szTerminal[PGND_CHARLEN];
	char	szNode[PGND_CHARLEN];
	//char	szLineSegment[MDB_CHARLEN];
	//unsigned char	nBusbarID;
	float	fV;
	float	fD;
	float	fF;
	float	fVLimitL;
	float	fVLimitH;

	float	fLoadP;
	float	fLoadQ;
	float	fGenP;
	float	fGenQ;
	float	fShuntQ;
	float	fReferenceV;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_Load_Rerr;
	float	ri_Load_Trep;
	float	ri_Load_Rchk;
	float	ri_Load_Tchk;

	//	经济性输入数据
	float	ei_Invest;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	//	输出数据
	float	fScIa;
	float	fScIb;
	float	fScIc;
	float	fScVa;
	float	fScVb;
	float	fScVc;
	float	fScV1;
	float	fScV2;
	float	fScV0;

	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;

	float	fErrP;
	float	fErrQ;

	unsigned char	bBypass;
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bDistribution;
	unsigned char	nParentType;
	unsigned char	nState;
	unsigned char	bInRing;
	short			nRadiate;
	unsigned char	bOpen;
}	DISALIGN;
typedef	struct	_PG_BusbarSection_	tagPGBusbarSection;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Line_	{
	PG_LINE_RESOURCEID=0,
	PG_LINE_OBJECTID,
	PG_LINE_NAME,
	PG_LINE_DESCRIPTION,
	PG_LINE_VOLTAGELEVEL,
	PG_LINE_SUBCONTROLAREA,
	PG_LINE_EI_INVEST,

	PG_LINE_TOTALLENGTH,
	PG_LINE_LOADP,
	PG_LINE_LOADQ,
	PG_LINE_LOSSP,
	PG_LINE_LOSSQ,
	PG_LINE_RO_CUSTOMERNUM,
	PG_LINE_RO_ACI,
	PG_LINE_RO_CID,
	PG_LINE_RO_SAIFI,
	PG_LINE_RO_SAIDI,
	PG_LINE_RO_ASAI,
	PG_LINE_RO_ENS,
	PG_LINE_RO_AENS,
	PG_LINE_RO_MIC,
	PG_LINE_RO_MID,
	PG_LINE_RO_F_ACI,
	PG_LINE_RO_F_CID,
	PG_LINE_RO_F_SAIFI,
	PG_LINE_RO_F_SAIDI,
	PG_LINE_RO_F_ASAI,
	PG_LINE_RO_F_ENS,
	PG_LINE_RO_F_AENS,
	PG_LINE_RO_F_MIC,
	PG_LINE_RO_F_MID,
	PG_LINE_RO_A_ACI,
	PG_LINE_RO_A_CID,
	PG_LINE_RO_A_SAIFI,
	PG_LINE_RO_A_SAIDI,
	PG_LINE_RO_A_ASAI,
	PG_LINE_RO_A_ENS,
	PG_LINE_RO_A_AENS,
	PG_LINE_RO_A_MIC,
	PG_LINE_RO_A_MID,
	PG_LINE_OPEN,
};

struct	_PG_Line_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szSubcontrolArea[MDB_CHARLEN_SHORT];

	float	ei_Invest;

	float	fLineLength;
	float	fLoadP;
	float	fLoadQ;
	float	fLossP;
	float	fLossQ;

	//	可靠性指标
	double	ro_customernum;
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

	unsigned char	bOpen;
}	DISALIGN;
typedef	struct	_PG_Line_	tagPGLine;

enum	_PGEnum_Field_ACLineSegment_	{
	PG_ACLINESEGMENT_RESOURCEID=0,
	PG_ACLINESEGMENT_OBJECTID,
	PG_ACLINESEGMENT_NAME,
	PG_ACLINESEGMENT_DESCRIPTION,
	PG_ACLINESEGMENT_ISUBSTATION,
	PG_ACLINESEGMENT_JSUBSTATION,
	PG_ACLINESEGMENT_IVOLTAGELEVEL,
	PG_ACLINESEGMENT_JVOLTAGELEVEL,
	PG_ACLINESEGMENT_LINE,
	//PG_ACLINESEGMENT_ITERMINAL,
	//PG_ACLINESEGMENT_JTERMINAL,
	PG_ACLINESEGMENT_CONNECTIVITYNODEI,
	PG_ACLINESEGMENT_CONNECTIVITYNODEJ,
	PG_ACLINESEGMENT_LINETYPE,
	PG_ACLINESEGMENT_LINEMODEL,
	PG_ACLINESEGMENT_LENGTH,
	PG_ACLINESEGMENT_RATECUR,
	PG_ACLINESEGMENT_RATEMVA,

	PG_ACLINESEGMENT_R,
	PG_ACLINESEGMENT_X,
	PG_ACLINESEGMENT_G,
	PG_ACLINESEGMENT_B,
	PG_ACLINESEGMENT_R0,
	PG_ACLINESEGMENT_X0,
	PG_ACLINESEGMENT_B0,
	PG_ACLINESEGMENT_RI_RERR,
	PG_ACLINESEGMENT_RI_TREP,
	PG_ACLINESEGMENT_RI_RCHK,
	PG_ACLINESEGMENT_RI_TCHK,
	PG_ACLINESEGMENT_RI_TFLOC,
	PG_ACLINESEGMENT_RI_RSWITCH,
	PG_ACLINESEGMENT_RI_TSWITCH,
	PG_ACLINESEGMENT_RI_TDELAY,
	PG_ACLINESEGMENT_RI_CUSTOMER,
	PG_ACLINESEGMENT_EI_INVEST,

	PG_ACLINESEGMENT_VD_RSCC1,
	PG_ACLINESEGMENT_VD_RSCC2,
	PG_ACLINESEGMENT_VD_RSCC3,
	PG_ACLINESEGMENT_VD_RSCC4,

	PG_ACLINESEGMENT_RATUNING,
	PG_ACLINESEGMENT_RADELAY,
	PG_ACLINESEGMENT_RAPLATE,
	PG_ACLINESEGMENT_RUTUNING,
	PG_ACLINESEGMENT_RUDELAY,
	PG_ACLINESEGMENT_RUPLATE,

	PG_ACLINESEGMENT_MCRTYPE,
	PG_ACLINESEGMENT_MCRPOWER,

	PG_ACLINESEGMENT_PI,
	PG_ACLINESEGMENT_QI,
	PG_ACLINESEGMENT_PJ,
	PG_ACLINESEGMENT_QJ,
	PG_ACLINESEGMENT_A,
	PG_ACLINESEGMENT_LOSSP,
	PG_ACLINESEGMENT_LOSSQ,

	PG_ACLINESEGMENT_SCIA,
	PG_ACLINESEGMENT_SCIB,
	PG_ACLINESEGMENT_SCIC,
	PG_ACLINESEGMENT_SCI1,
	PG_ACLINESEGMENT_SCI2,
	PG_ACLINESEGMENT_SCI0,

	PG_ACLINESEGMENT_RO_RCONTRIBUTION,
	PG_ACLINESEGMENT_RO_UCONTRIBUTION,
	PG_ACLINESEGMENT_RO_ENSCONTRIBUTION,

	PG_ACLINESEGMENT_SA_RESULT,
	PG_ACLINESEGMENT_SA_ISLAND,
	PG_ACLINESEGMENT_SA_FAILURE,
	PG_ACLINESEGMENT_SA_SHIFTNODE,

	PG_ACLINESEGMENT_TOPOBUSI,
	PG_ACLINESEGMENT_TOPOBUSJ,
	PG_ACLINESEGMENT_ISLAND,
	PG_ACLINESEGMENT_LINEPTR,
	PG_ACLINESEGMENT_NODEIPTR,
	PG_ACLINESEGMENT_NODEJPTR,
	PG_ACLINESEGMENT_EDGEI,
	PG_ACLINESEGMENT_EDGEJ,
	PG_ACLINESEGMENT_DISTRIBUTION,
	PG_ACLINESEGMENT_STATE,
	PG_ACLINESEGMENT_INRING,
	PG_ACLINESEGMENT_RADIATE,
	PG_ACLINESEGMENT_OPEN,
	PG_ACLINESEGMENT_DIRECTION,
	PG_ACLINESEGMENT_TRUNKLINE,
	PG_ACLINESEGMENT_OUTAGE,
};

struct	_PG_ACLineSegment_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	char	szSubI[MDB_CHARLEN];
	char	szSubJ[MDB_CHARLEN];
	char	szVoltI[MDB_CHARLEN_SHORTER];
	char	szVoltJ[MDB_CHARLEN_SHORTER];
	char	szLine[MDB_CHARLEN];
	//char	szTerminalI[PGND_CHARLEN];
	//char	szTerminalJ[PGND_CHARLEN];
	char	szNodeI[PGND_CHARLEN];
	char	szNodeJ[PGND_CHARLEN];
	unsigned char	nLineType;
	char	szLineModel[MDB_CHARLEN_SHORT];
	float	fLength;
	float	fRatedCur;
	float	fRatedMva;

	float	fR;
	float	fX;
	float	fG;
	float	fB;
	float	fR0;
	float	fX0;
	float	fB0;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_RSwitch;
	float	ri_TSwitch;
	float	ri_TDelay;
	float	ri_Customer;

	//	经济性输入数据
	float	ei_Invest;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	//	线路低周低压保护
	float	fRATuning;
	float	fRADelay;
	unsigned char	bRAPlate;
	float	fRUTuning;
	float	fRUDelay;
	unsigned char	bRUPlate;

	//	主接线可靠性
	unsigned char	nMCRType;
	float			fMCRPower;

	//	输出数据
	float	fPi;
	float	fQi;
	float	fPz;
	float	fQz;
	float	fA;
	float	fLossP;
	float	fLossQ;

	float	fScIa;
	float	fScIb;
	float	fScIc;
	float	fScI1;
	float	fScI2;
	float	fScI0;

	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;

	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	int		sa_ShiftNode;
	int		nTopoBusI;
	int		nTopoBusJ;
	short	nIsland;
	short	nLine;
	int		nNodeI;
	int		nNodeJ;
	short	nEdgeI;
	short	nEdgeJ;
	unsigned char	bDistribution;
	unsigned char	nState;
	unsigned char	bInRing;
	short			nRadiate;
	unsigned char	bOpen;
	unsigned char	nDirection;
	unsigned char	bTrunkLine;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_ACLineSegment_	tagPGACLineSegment;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_DCLineSegment_	{
	PG_DCLINESEGMENT_RESOURCEID=0,
	PG_DCLINESEGMENT_NAME,
	PG_DCLINESEGMENT_DESCRIPTION,
	PG_DCLINESEGMENT_ISUBSTATION,
	PG_DCLINESEGMENT_JSUBSTATION,
	PG_DCLINESEGMENT_IVOLTAGELEVEL,
	PG_DCLINESEGMENT_JVOLTAGELEVEL,
	PG_DCLINESEGMENT_LINE,
	PG_DCLINESEGMENT_CONNECTIVITYNODEI,
	PG_DCLINESEGMENT_CONNECTIVITYNODEJ,
	PG_DCLINESEGMENT_TYPE,
	PG_DCLINESEGMENT_LENGTH,
	PG_DCLINESEGMENT_ALIMIT,
	PG_DCLINESEGMENT_R,
	PG_DCLINESEGMENT_L,
	PG_DCLINESEGMENT_C,
	PG_DCLINESEGMENT_ALPHA,
	PG_DCLINESEGMENT_GAMMA,
	PG_DCLINESEGMENT_SCHEDP,
	PG_DCLINESEGMENT_LINEPTR,
	PG_DCLINESEGMENT_NODEIPTR,
	PG_DCLINESEGMENT_NODEJPTR,
	PG_DCLINESEGMENT_TOPOBUSI,
	PG_DCLINESEGMENT_TOPOBUSJ,
	PG_DCLINESEGMENT_ISLAND,
	PG_DCLINESEGMENT_EDGEI,
	PG_DCLINESEGMENT_EDGEJ,
	PG_DCLINESEGMENT_STATE,
	PG_DCLINESEGMENT_OPEN,
	PG_DCLINESEGMENT_OUTAGE,
};
struct	_PG_DCLineSegment_	{
	char	szResID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	char	szSubI[MDB_CHARLEN];
	char	szSubJ[MDB_CHARLEN];
	char	szVoltI[MDB_CHARLEN_SHORTER];
	char	szVoltJ[MDB_CHARLEN_SHORTER];
	char	szLine[MDB_CHARLEN];
	char	szNodeI[PGND_CHARLEN];
	char	szNodeJ[PGND_CHARLEN];
	char	szType[MDB_CHARLEN];
	float	fLength;
	float	fALimit;
	float	fR;
	float	fL;
	float	fC;
	float	fAlpha;
	float	fGamma;
	float	fSchedP;

	short	nLine;
	int		nNodeI;
	int		nNodeJ;
	int		nTopoBusI;
	int		nTopoBusJ;
	short	nIsland;
	short	iRln2;
	short	zRln2;
	unsigned char	nState;
	unsigned char	bOpen;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_DCLineSegment_	tagPGDCLineSegment;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_PowerTransformer_	{
	PG_POWERTRANSFORMER_RESOURCEID=0,
	PG_POWERTRANSFORMER_OBJECTID,
	PG_POWERTRANSFORMER_SUBSTATION,
	PG_POWERTRANSFORMER_NAME,
	PG_POWERTRANSFORMER_DESCRIPTION,

	PG_POWERTRANSFORMER_WINDNUM,
	PG_POWERTRANSFORMER_VOLTAGELEVELH,
	PG_POWERTRANSFORMER_VOLTAGELEVELM,
	PG_POWERTRANSFORMER_VOLTAGELEVELL,
	PG_POWERTRANSFORMER_TRANSFORMERWINDINGH,
	PG_POWERTRANSFORMER_TRANSFORMERWINDINGM,
	PG_POWERTRANSFORMER_TRANSFORMERWINDINGL,
	PG_POWERTRANSFORMER_CONNECTIVITYNODEH,
	PG_POWERTRANSFORMER_CONNECTIVITYNODEM,
	PG_POWERTRANSFORMER_CONNECTIVITYNODEL,

	PG_POWERTRANSFORMER_TOPOBUSH,
	PG_POWERTRANSFORMER_TOPOBUSM,
	PG_POWERTRANSFORMER_TOPOBUSL,

	PG_POWERTRANSFORMER_VOLTHPTR,
	PG_POWERTRANSFORMER_VOLTMPTR,
	PG_POWERTRANSFORMER_VOLTLPTR,
	PG_POWERTRANSFORMER_WINDHPTR,
	PG_POWERTRANSFORMER_WINDMPTR,
	PG_POWERTRANSFORMER_WINDLPTR,
	PG_POWERTRANSFORMER_NODEHPTR,
	PG_POWERTRANSFORMER_NODEMPTR,
	PG_POWERTRANSFORMER_NODELPTR,

	PG_POWERTRANSFORMER_STATE,
	PG_POWERTRANSFORMER_OPEN,
};
struct	_PG_PowerTransformer_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];

	unsigned char	nWindNum;
	char	szVoltH[MDB_CHARLEN_SHORTER];
	char	szVoltM[MDB_CHARLEN_SHORTER];
	char	szVoltL[MDB_CHARLEN_SHORTER];
	char	szWindH[MDB_CHARLEN];
	char	szWindM[MDB_CHARLEN];
	char	szWindL[MDB_CHARLEN];
	char	szNodeH[PGND_CHARLEN];
	char	szNodeM[PGND_CHARLEN];
	char	szNodeL[PGND_CHARLEN];

	int		nTopoBusH;
	int		nTopoBusM;
	int		nTopoBusL;

	short	nVoltH;
	short	nVoltM;
	short	nVoltL;
	short	nWindH;
	short	nWindM;
	short	nWindL;
	int		nNodeH;
	int		nNodeM;
	int		nNodeL;
	unsigned char	nState;
	unsigned char	bOpen;
}	DISALIGN;
typedef	struct	_PG_PowerTransformer_	tagPGPowerTransformer;

enum	_PGEnum_Field_TransformerWinding_	{
	PG_TRANSFORMERWINDING_RESOURCEID=0,
	PG_TRANSFORMERWINDING_OBJECTID,
	PG_TRANSFORMERWINDING_SUBSTATION,
	PG_TRANSFORMERWINDING_NAME,
	PG_TRANSFORMERWINDING_DESCRIPTION,
	PG_TRANSFORMERWINDING_VOLTAGELEVELI,
	PG_TRANSFORMERWINDING_VOLTAGELEVELJ,
	PG_TRANSFORMERWINDING_POWERTRANSFORMER,
	PG_TRANSFORMERWINDING_TAPCHANGERI,
	PG_TRANSFORMERWINDING_TAPCHANGERZ,
	//PG_TRANSFORMERWINDING_ITERMINAL,
	//PG_TRANSFORMERWINDING_JTERMINAL,
	PG_TRANSFORMERWINDING_CONNECTIVITYNODEI,
	PG_TRANSFORMERWINDING_CONNECTIVITYNODEJ,
	PG_TRANSFORMERWINDING_RATEMVA,
	PG_TRANSFORMERWINDING_RATEKVI,
	PG_TRANSFORMERWINDING_RATEKVJ,
	PG_TRANSFORMERWINDING_R,
	PG_TRANSFORMERWINDING_X,
	PG_TRANSFORMERWINDING_G,
	PG_TRANSFORMERWINDING_B,
	PG_TRANSFORMERWINDING_R0,
	PG_TRANSFORMERWINDING_X0,
	PG_TRANSFORMERWINDING_ITAP,
	PG_TRANSFORMERWINDING_ZTAP,
	PG_TRANSFORMERWINDING_TRANSTATUS,
	PG_TRANSFORMERWINDING_NEUTRALSTATUS,
	PG_TRANSFORMERWINDING_WINDINGTYPE,
	PG_TRANSFORMERWINDING_WINDINGAVR,
	PG_TRANSFORMERWINDING_COUPLEDTRAN,
	PG_TRANSFORMERWINDING_RI_RERR,
	PG_TRANSFORMERWINDING_RI_TREP,
	PG_TRANSFORMERWINDING_RI_RCHK,
	PG_TRANSFORMERWINDING_RI_TCHK,
	PG_TRANSFORMERWINDING_RI_TFLOC,
	PG_TRANSFORMERWINDING_RI_RSWITCH,
	PG_TRANSFORMERWINDING_RI_TSWITCH,
	PG_TRANSFORMERWINDING_EI_INVEST,
	PG_TRANSFORMERWINDING_VD_RSCC1,
	PG_TRANSFORMERWINDING_VD_RSCC2,
	PG_TRANSFORMERWINDING_VD_RSCC3,
	PG_TRANSFORMERWINDING_VD_RSCC4,
	PG_TRANSFORMERWINDING_RATUNING,
	PG_TRANSFORMERWINDING_RADELAY,
	PG_TRANSFORMERWINDING_RAPLATE,
	PG_TRANSFORMERWINDING_RUTUNING,
	PG_TRANSFORMERWINDING_RUDELAY,
	PG_TRANSFORMERWINDING_RUPLATE,

	PG_TRANSFORMERWINDING_MCRTYPE,
	PG_TRANSFORMERWINDING_MCRPOWER,

	PG_TRANSFORMERWINDING_PI,
	PG_TRANSFORMERWINDING_QI,
	PG_TRANSFORMERWINDING_AI,
	PG_TRANSFORMERWINDING_PZ,
	PG_TRANSFORMERWINDING_QZ,
	PG_TRANSFORMERWINDING_AZ,
	PG_TRANSFORMERWINDING_LOSSP,
	PG_TRANSFORMERWINDING_LOSSQ,

	PG_TRANSFORMERWINDING_SCIAI,
	PG_TRANSFORMERWINDING_SCIBI,
	PG_TRANSFORMERWINDING_SCICI,

	PG_TRANSFORMERWINDING_SCI1I,
	PG_TRANSFORMERWINDING_SCI2I,
	PG_TRANSFORMERWINDING_SCI0I,

	PG_TRANSFORMERWINDING_SCIAJ,
	PG_TRANSFORMERWINDING_SCIBJ,
	PG_TRANSFORMERWINDING_SCICJ,

	PG_TRANSFORMERWINDING_SCI1J,
	PG_TRANSFORMERWINDING_SCI2J,
	PG_TRANSFORMERWINDING_SCI0J,

	PG_TRANSFORMERWINDING_RO_RCONTRIBUTION,
	PG_TRANSFORMERWINDING_RO_UCONTRIBUTION,
	PG_TRANSFORMERWINDING_RO_ENSCONTRIBUTION,
	PG_TRANSFORMERWINDING_SA_RESULT,
	PG_TRANSFORMERWINDING_SA_ISLAND,
	PG_TRANSFORMERWINDING_SA_FAILURE,
	PG_TRANSFORMERWINDING_SA_SHIFTNODE,
	PG_TRANSFORMERWINDING_TRANPTR,
	PG_TRANSFORMERWINDING_VOLTIPTR,
	PG_TRANSFORMERWINDING_VOLTJPTR,
	PG_TRANSFORMERWINDING_TAPCHANGERIPTR,
	PG_TRANSFORMERWINDING_TAPCHANGERJPTR,
	PG_TRANSFORMERWINDING_NODEIPTR,
	PG_TRANSFORMERWINDING_NODEJPTR,
	PG_TRANSFORMERWINDING_TOPOBUSI,
	PG_TRANSFORMERWINDING_TOPOBUSJ,
	PG_TRANSFORMERWINDING_ISLAND,
	PG_TRANSFORMERWINDING_EDGEI,
	PG_TRANSFORMERWINDING_EDGEJ,
	PG_TRANSFORMERWINDING_TRANMIDSIDE,
	PG_TRANSFORMERWINDING_DISTRIBUTION,
	PG_TRANSFORMERWINDING_STATE,
	PG_TRANSFORMERWINDING_INRING,
	PG_TRANSFORMERWINDING_RADIATE,
	PG_TRANSFORMERWINDING_OPEN,
	PG_TRANSFORMERWINDING_DIRECTION,
	PG_TRANSFORMERWINDING_OUTAGE,
};
struct	_PG_TransformerWinding_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	char	szVoltI[MDB_CHARLEN_SHORTER];
	char	szVoltJ[MDB_CHARLEN_SHORTER];
	char	szTran[MDB_CHARLEN];
	char	szTapChangerI[MDB_CHARLEN_SHORT];
	char	szTapChangerJ[MDB_CHARLEN_SHORT];
	//char	szTerminalI[PGND_CHARLEN];
	//char	szTerminalJ[PGND_CHARLEN];
	char	szNodeI[PGND_CHARLEN];
	char	szNodeJ[PGND_CHARLEN];
	float	fRatedMva;
	float	fRatedkVI;
	float	fRatedkVJ;
	float	fR;
	float	fX;
	float	fG;
	float	fB;
	float	fR0;
	float	fX0;
	unsigned char	nTapI;
	unsigned char	nTapJ;
	unsigned char	nTranStatus;
	unsigned char	bNeutralStatus;
	unsigned char	nWindingType;
	unsigned char	nWindingAVR;
	unsigned char	bCoupledTran;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_RSwitch;
	float	ri_TSwitch;

	//	经济性输入数据
	float	ei_Invest;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	//	主变低周低压保护
	float	fRATuning;
	float	fRADelay;
	unsigned char	bRAPlate;
	float	fRUTuning;
	float	fRUDelay;
	unsigned char	bRUPlate;

	//	主接线可靠性
	unsigned char	nMCRType;
	float			fMCRPower;

	//	输出数据
	float	fPi;
	float	fQi;
	float	fAi;
	float	fPz;
	float	fQz;
	float	fAz;
	float	fLossP;
	float	fLossQ;

	float	fScIaI;
	float	fScIbI;
	float	fScIcI;

	float	fScI1I;
	float	fScI2I;
	float	fScI0I;

	float	fScIaJ;
	float	fScIbJ;
	float	fScIcJ;

	float	fScI1J;
	float	fScI2J;
	float	fScI0J;

	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;

	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	int		sa_ShiftNode;

	short	nTran;
	short	nVoltI;
	short	nVoltJ;
	short	nTapChangerI;
	short	nTapChangerJ;
	int		nNodeI;
	int		nNodeJ;
	int		nTopoBusI;
	int		nTopoBusJ;
	short	nIsland;
	short	nEdgeI;
	short	nEdgeJ;
	unsigned char	bTranMidSide;
	unsigned char	bDistribution;
	unsigned char	nState;
	unsigned char	bInRing;
	short			nRadiate;
	unsigned char	bOpen;
	unsigned char	nDirection;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_TransformerWinding_	tagPGTransformerWinding;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_RectifierInverter_	{
	PG_RECTIFIERINVERTER_RESOURCEID=0,
	PG_RECTIFIERINVERTER_SUBSTATION,
	PG_RECTIFIERINVERTER_NAME,
	PG_RECTIFIERINVERTER_DESCRIPTION,
	PG_RECTIFIERINVERTER_VOLTAGELEVEL1,
	PG_RECTIFIERINVERTER_VOLTAGELEVEL2,
	PG_RECTIFIERINVERTER_VOLTAGELEVEL3,
	//PG_RECTIFIERINVERTER_TERMINAL1,
	//PG_RECTIFIERINVERTER_TERMINAL2,
	//PG_RECTIFIERINVERTER_TERMINAL3,
	PG_RECTIFIERINVERTER_CONNECTIVITYNODE1,
	PG_RECTIFIERINVERTER_CONNECTIVITYNODE2,
	PG_RECTIFIERINVERTER_CONNECTIVITYNODE3,
	PG_RECTIFIERINVERTER_BRIDGES,
	PG_RECTIFIERINVERTER_P,
	PG_RECTIFIERINVERTER_Q,
	PG_RECTIFIERINVERTER_VOLT1PTR,
	PG_RECTIFIERINVERTER_VOLT2PTR,
	PG_RECTIFIERINVERTER_VOLT3PTR,
	PG_RECTIFIERINVERTER_NODE1PTR,
	PG_RECTIFIERINVERTER_NODE2PTR,
	PG_RECTIFIERINVERTER_NODE3PTR,
	PG_RECTIFIERINVERTER_TOPOBUSI1,
	PG_RECTIFIERINVERTER_TOPOBUSI2,
	PG_RECTIFIERINVERTER_TOPOBUSI3,
	PG_RECTIFIERINVERTER_ISLAND,
	PG_RECTIFIERINVERTER_OPEN,
	PG_RECTIFIERINVERTER_OUTAGE,
};
struct	_PG_RectifierInverter_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];

	char	szVolt1[MDB_CHARLEN_SHORTER];
	char	szVolt2[MDB_CHARLEN_SHORTER];
	char	szVolt3[MDB_CHARLEN_SHORTER];
	//char	szTerminal1[PGND_CHARLEN];
	//char	szTerminal2[PGND_CHARLEN];
	//char	szTerminal3[PGND_CHARLEN];
	char	szNode1[PGND_CHARLEN];
	char	szNode2[PGND_CHARLEN];
	char	szNode3[PGND_CHARLEN];

	unsigned char	nBridges;

	float	fP;
	float	fQ;

	short	nVolt1;
	short	nVolt2;
	short	nVolt3;
	int		nNode1;
	int		nNode2;
	int		nNode3;
	int		nTopBus1;
	int		nTopBus2;
	int		nTopBus3;
	short	nIsland;
	unsigned char	bOpen;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_RectifierInverter_	tagPGRectifierInverter;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_SynchronousMachine_	{
	PG_SYNCHRONOUSMACHINE_RESOURCEID=0,
	PG_SYNCHRONOUSMACHINE_OBJECTID,
	PG_SYNCHRONOUSMACHINE_SUBSTATION,
	PG_SYNCHRONOUSMACHINE_VOLTAGELEVEL,
	PG_SYNCHRONOUSMACHINE_NAME,
	PG_SYNCHRONOUSMACHINE_DESCRIPTION,
	PG_SYNCHRONOUSMACHINE_PLANP,
	PG_SYNCHRONOUSMACHINE_PLANQ,
	PG_SYNCHRONOUSMACHINE_PVND,
	//PG_SYNCHRONOUSMACHINE_TERMINAL,
	PG_SYNCHRONOUSMACHINE_CONNECTIVITYNODE,
	PG_SYNCHRONOUSMACHINE_TYPE,
	PG_SYNCHRONOUSMACHINE_PMAX,
	PG_SYNCHRONOUSMACHINE_PMIN,
	PG_SYNCHRONOUSMACHINE_QMAX,
	PG_SYNCHRONOUSMACHINE_QMIN,
	PG_SYNCHRONOUSMACHINE_PQMVARATE,
	PG_SYNCHRONOUSMACHINE_AUXPCA,
	PG_SYNCHRONOUSMACHINE_AUXPVA,
	PG_SYNCHRONOUSMACHINE_AUXFACTOR,
	PG_SYNCHRONOUSMACHINE_X0,
	PG_SYNCHRONOUSMACHINE_XDPP,
	PG_SYNCHRONOUSMACHINE_BPA_GENBUS,
	PG_SYNCHRONOUSMACHINE_BPA_GENVOLT,
	PG_SYNCHRONOUSMACHINE_RI_RERR,
	PG_SYNCHRONOUSMACHINE_RI_TREP,
	PG_SYNCHRONOUSMACHINE_RI_RCHK,
	PG_SYNCHRONOUSMACHINE_RI_TCHK,
	PG_SYNCHRONOUSMACHINE_RI_TFLOC,
	PG_SYNCHRONOUSMACHINE_EI_INVEST,

	PG_SYNCHRONOUSMACHINE_RW_TUNING1,
	PG_SYNCHRONOUSMACHINE_RW_TUNING2,
	PG_SYNCHRONOUSMACHINE_RW_DELAY1,
	PG_SYNCHRONOUSMACHINE_RW_DELAY2,
	PG_SYNCHRONOUSMACHINE_RW_PLATE,

	PG_SYNCHRONOUSMACHINE_RE_TUNING1,
	PG_SYNCHRONOUSMACHINE_RE_TUNING2,
	PG_SYNCHRONOUSMACHINE_RE_DELAY1,
	PG_SYNCHRONOUSMACHINE_RE_DELAY2,
	PG_SYNCHRONOUSMACHINE_RE_PLATE,

	PG_SYNCHRONOUSMACHINE_MCRTYPE,
	PG_SYNCHRONOUSMACHINE_MCRPOWER,
	PG_SYNCHRONOUSMACHINE_TDCURVE,

	PG_SYNCHRONOUSMACHINE_P,
	PG_SYNCHRONOUSMACHINE_Q,
	PG_SYNCHRONOUSMACHINE_A,
	PG_SYNCHRONOUSMACHINE_V,
	PG_SYNCHRONOUSMACHINE_D,
	PG_SYNCHRONOUSMACHINE_FACTOR,
	PG_SYNCHRONOUSMACHINE_SCIA,
	PG_SYNCHRONOUSMACHINE_SCIB,
	PG_SYNCHRONOUSMACHINE_SCIC,
	PG_SYNCHRONOUSMACHINE_SCVA,
	PG_SYNCHRONOUSMACHINE_SCVB,
	PG_SYNCHRONOUSMACHINE_SCVC,

	PG_SYNCHRONOUSMACHINE_RO_RCONTRIBUTION,
	PG_SYNCHRONOUSMACHINE_RO_UCONTRIBUTION,
	PG_SYNCHRONOUSMACHINE_RO_ENSCONTRIBUTION,

	PG_SYNCHRONOUSMACHINE_NODEPTR,
	PG_SYNCHRONOUSMACHINE_TOPOBUS,
	PG_SYNCHRONOUSMACHINE_ISLAND,
	PG_SYNCHRONOUSMACHINE_DISTRIBUTION,
	PG_SYNCHRONOUSMACHINE_STATE,
	PG_SYNCHRONOUSMACHINE_OPEN,
	PG_SYNCHRONOUSMACHINE_OUTAGE,
};
struct	_PG_SynchronousMachine_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	float	fPlanP;
	float	fPlanQ;
	float	fPlanV;
	//char	szTerminal[PGND_CHARLEN];
	char	szNode[PGND_CHARLEN];
	unsigned char	nType;
	float	fPMax;
	float	fPMin;
	float	fQMax;
	float	fQMin;
	float	fMvaRate;
	float	fAuxPca;
	float	fAuxPva;
	float	fAuxFactor;

	float	fX0;
	float	fXdpp;

	char	szBpaGenBus[MDB_CHARLEN_SHORTER];
	float	fBpaGenVolt;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;

	//	经济性输入数据
	float	ei_Invest;

	float	fRWTuning1;
	float	fRWTuning2;
	float	fRWDelay1;
	float	fRWDelay2;
	unsigned char	bRWPlate;

	float	fRETuning1;
	float	fRETuning2;
	float	fREDelay1;
	float	fREDelay2;
	unsigned char	bREPlate;

	//	主接线可靠性
	unsigned char	nMCRType;
	float			fMCRPower;
	char			szTDCurve[MDB_CHARLEN];

	float	fP;
	float	fQ;
	float	fA;
	float	fV;
	float	fD;
	float	fFactor;

	float	fScIa;
	float	fScIb;
	float	fScIc;
	float	fScVa;
	float	fScVb;
	float	fScVc;

	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;

	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bDistribution;
	unsigned char	nState;
	unsigned char	bOpen;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_SynchronousMachine_	tagPGSynchronousMachine;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_EnergyConsumer_	{
	PG_ENERGYCONSUMER_RESOURCEID=0,
	PG_ENERGYCONSUMER_OBJECTID,
	PG_ENERGYCONSUMER_SUBSTATION,
	PG_ENERGYCONSUMER_VOLTAGELEVEL,
	PG_ENERGYCONSUMER_NAME,
	PG_ENERGYCONSUMER_DESCRIPTION,
	PG_ENERGYCONSUMER_PLANP,
	PG_ENERGYCONSUMER_PLANQ,
	//PG_ENERGYCONSUMER_TERMINAL,
	PG_ENERGYCONSUMER_CONNECTIVITYNODE,
	PG_ENERGYCONSUMER_X0,
	PG_ENERGYCONSUMER_RI_CUSTOMER,

	PG_ENERGYCONSUMER_TYPE,
	PG_ENERGYCONSUMER_CAPACITY,
	PG_ENERGYCONSUMER_MOTORCAPACITY,

	PG_ENERGYCONSUMER_MODEL,
	PG_ENERGYCONSUMER_MOTORTJ,
	PG_ENERGYCONSUMER_MOTORPPER,
	PG_ENERGYCONSUMER_MOTORKL,
	PG_ENERGYCONSUMER_MOTORRS,
	PG_ENERGYCONSUMER_MOTORXS,
	PG_ENERGYCONSUMER_MOTORXM,
	PG_ENERGYCONSUMER_MOTORRR,
	PG_ENERGYCONSUMER_MOTORXR,
	PG_ENERGYCONSUMER_MOTORA,
	PG_ENERGYCONSUMER_MOTORB,
	PG_ENERGYCONSUMER_MOTORS0,
	PG_ENERGYCONSUMER_MOTORIM,

	PG_ENERGYCONSUMER_AUTOUF_FREQ,
	PG_ENERGYCONSUMER_AUTOUF_DELAY,
	PG_ENERGYCONSUMER_AUTOUF_PLATE,
	PG_ENERGYCONSUMER_AUTOUV_VOLT,
	PG_ENERGYCONSUMER_AUTOUV_DELAY,
	PG_ENERGYCONSUMER_AUTOUV_PLATE,

	PG_ENERGYCONSUMER_LINESEGMENT,
	PG_ENERGYCONSUMER_EI_INVEST,
	PG_ENERGYCONSUMER_EI_CONSTLOSS,
	PG_ENERGYCONSUMER_EI_EVALRATIO,

	PG_ENERGYCONSUMER_MCRTYPE,
	PG_ENERGYCONSUMER_MCRPOWER,
	PG_ENERGYCONSUMER_TWDCURVE,
	PG_ENERGYCONSUMER_THDCURVE,

	PG_ENERGYCONSUMER_P,
	PG_ENERGYCONSUMER_Q,
	PG_ENERGYCONSUMER_A,
	PG_ENERGYCONSUMER_V,
	PG_ENERGYCONSUMER_D,
	PG_ENERGYCONSUMER_FACTOR,
	PG_ENERGYCONSUMER_RO_R,
	PG_ENERGYCONSUMER_RO_T,
	PG_ENERGYCONSUMER_RO_U,
	PG_ENERGYCONSUMER_RO_FR,
	PG_ENERGYCONSUMER_RO_FT,
	PG_ENERGYCONSUMER_RO_FU,
	PG_ENERGYCONSUMER_RO_AR,
	PG_ENERGYCONSUMER_RO_AT,
	PG_ENERGYCONSUMER_RO_AU,
	PG_ENERGYCONSUMER_RO_SWR,
	PG_ENERGYCONSUMER_RO_SWT,
	PG_ENERGYCONSUMER_RO_SWU,
	PG_ENERGYCONSUMER_RO_CMR,
	PG_ENERGYCONSUMER_RO_CMT,
	PG_ENERGYCONSUMER_RO_CMU,
	PG_ENERGYCONSUMER_RO_ENS,
	PG_ENERGYCONSUMER_RO_F_ENS,
	PG_ENERGYCONSUMER_RO_A_ENS,
	PG_ENERGYCONSUMER_EO_LOSS,
	PG_ENERGYCONSUMER_EO_F_LOSS,
	PG_ENERGYCONSUMER_EO_A_LOSS,
	PG_ENERGYCONSUMER_RO_RCONTRIBUTION,
	PG_ENERGYCONSUMER_RO_UCONTRIBUTION,
	PG_ENERGYCONSUMER_RO_ENSCONTRIBUTION,

	PG_ENERGYCONSUMER_RCTIME,
	PG_ENERGYCONSUMER_RCCASE,
	PG_ENERGYCONSUMER_NODEPTR,
	PG_ENERGYCONSUMER_TOPOBUS,
	PG_ENERGYCONSUMER_ISLAND,
	PG_ENERGYCONSUMER_DISTRIBUTION,
	PG_ENERGYCONSUMER_PARENTTYPE,
	PG_ENERGYCONSUMER_STATE,
	PG_ENERGYCONSUMER_OUTAGE,
};
struct	_PG_EnergyConsumer_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	float	fPlanP;
	float	fPlanQ;
	//char	szTerminal[PGND_CHARLEN];
	char	szNode[PGND_CHARLEN];
	float	fX0;
	float	ri_Customer;

	unsigned char	nLoadType;
	float	fLoadCapacity;
	float	fMotorCapacity;

	char	szSModel[MDB_CHARLEN];
	float	fMotorTj;
	float	fMotorPper;
	float	fMotorKl;
	float	fMotorRs;
	float	fMotorXs;
	float	fMotorXm;
	float	fMotorRr;
	float	fMotorXr;
	float	fMotorA;
	float	fMotorB;
	unsigned char	bUseS0;
	unsigned char	nMotorIM;

	float	fAutoUFFreq;
	float	fAutoUFDelay;
	unsigned char	bAutoUFPlate;
	float	fAutoUVVolt;
	float	fAutoUVDelay;
	unsigned char	bAutoUVPlate;

	char	szLineSegment[MDB_CHARLEN];
	//	经济性输入数据
	float	ei_Invest;
	float	ei_ConstLoss;
	float	ei_EvalRatio;

	//	主接线可靠性
	unsigned char	nMCRType;
	float			fMCRPower;

	char			szTWDCurve[MDB_CHARLEN];
	char			szTHDCurve[MDB_CHARLEN];

	float	fP;
	float	fQ;
	float	fA;
	float	fV;
	float	fD;
	float	fFactor;

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
	float	ro_swr;
	float	ro_swt;
	float	ro_swu;
	float	ro_cmr;
	float	ro_cmt;
	float	ro_cmu;
	float	ro_ens;
	float	ro_f_ens;
	float	ro_a_ens;
	float	eo_loss;
	float	eo_f_loss;
	float	eo_a_loss;

	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;

	float	fRCTime;
	unsigned char	nRCCase;

	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bDistribution;
	unsigned char	nParentType;
	unsigned char	nState;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_EnergyConsumer_	tagPGEnergyConsumer;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_LoadModel_	{
	PG_LOADMODEL_NAME=0,
	PG_LOADMODEL_DESP,
	PG_LOADMODEL_PIMP,
	PG_LOADMODEL_PCUR,
	PG_LOADMODEL_PCON,
	PG_LOADMODEL_PV,
	PG_LOADMODEL_NP,
	PG_LOADMODEL_DPF,
	PG_LOADMODEL_QIMP,
	PG_LOADMODEL_QCUR,
	PG_LOADMODEL_QCON,
	PG_LOADMODEL_QV,
	PG_LOADMODEL_NQ,
	PG_LOADMODEL_DQF,
};
struct	_PG_LoadModel_	{
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	float	fPImp;
	float	fPCur;
	float	fPCon;
	float	fPV;
	float	fNp;
	float	fDPf;
	float	fQImp;
	float	fQCur;
	float	fQCon;
	float	fQV;
	float	fNq;
	float	fDQf;
}	DISALIGN;
typedef	struct	_PG_LoadModel_	tagPGLoadModel;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ShuntCompensator_	{
	PG_SHUNTCOMPENSATOR_RESOURCEID=0,
	PG_SHUNTCOMPENSATOR_OBJECTID,
	PG_SHUNTCOMPENSATOR_SUBSTATION,
	PG_SHUNTCOMPENSATOR_VOLTAGELEVEL,
	PG_SHUNTCOMPENSATOR_NAME,
	PG_SHUNTCOMPENSATOR_DESCRIPTION,
	//PG_SHUNTCOMPENSATOR_TERMINAL,
	PG_SHUNTCOMPENSATOR_CONNECTIVITYNODE,
	PG_SHUNTCOMPENSATOR_CAP,
	PG_SHUNTCOMPENSATOR_X0,
	PG_SHUNTCOMPENSATOR_RI_RERR,
	PG_SHUNTCOMPENSATOR_RI_TREP,
	PG_SHUNTCOMPENSATOR_RI_RCHK,
	PG_SHUNTCOMPENSATOR_RI_TCHK,
	PG_SHUNTCOMPENSATOR_RI_TFLOC,
	PG_SHUNTCOMPENSATOR_EI_INVEST,
	PG_SHUNTCOMPENSATOR_Q,
	PG_SHUNTCOMPENSATOR_A,
	PG_SHUNTCOMPENSATOR_NODEPTR,
	PG_SHUNTCOMPENSATOR_TOPOBUS,
	PG_SHUNTCOMPENSATOR_ISLAND,
	PG_SHUNTCOMPENSATOR_DISTRIBUTION,
	PG_SHUNTCOMPENSATOR_STATE,
	PG_SHUNTCOMPENSATOR_OUTAGE,
};
struct	_PG_ShuntCompensator_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	//char	szTerminal[PGND_CHARLEN];
	char	szNode[PGND_CHARLEN];
	float	fCap;
	float	fX0;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;

	//	经济性输入数据
	float	ei_Invest;

	float	fQ;
	float	fA;

	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bDistribution;
	unsigned char	nState;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_ShuntCompensator_	tagPGShuntCompensator;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_SeriesCompensator_	{
	PG_SERIESCOMPENSATOR_RESOURCEID=0,
	PG_SERIESCOMPENSATOR_OBJECTID,
	PG_SERIESCOMPENSATOR_SUBSTATION,
	PG_SERIESCOMPENSATOR_VOLTAGELEVEL,
	PG_SERIESCOMPENSATOR_NAME,
	PG_SERIESCOMPENSATOR_DESCRIPTION,
	//PG_SERIESCOMPENSATOR_ITERMINAL,
	//PG_SERIESCOMPENSATOR_JTERMINAL,
	PG_SERIESCOMPENSATOR_CONNECTIVITYNODEI,
	PG_SERIESCOMPENSATOR_CONNECTIVITYNODEJ,
	PG_SERIESCOMPENSATOR_R,
	PG_SERIESCOMPENSATOR_X,
	PG_SERIESCOMPENSATOR_X0,
	PG_SERIESCOMPENSATOR_RATE,
	PG_SERIESCOMPENSATOR_RI_RERR,
	PG_SERIESCOMPENSATOR_RI_TREP,
	PG_SERIESCOMPENSATOR_RI_RCHK,
	PG_SERIESCOMPENSATOR_RI_TCHK,
	PG_SERIESCOMPENSATOR_RI_TFLOC,
	PG_SERIESCOMPENSATOR_EI_INVEST,

	PG_SERIESCOMPENSATOR_PI,
	PG_SERIESCOMPENSATOR_QI,
	PG_SERIESCOMPENSATOR_PZ,
	PG_SERIESCOMPENSATOR_QZ,
	PG_SERIESCOMPENSATOR_A,
	PG_SERIESCOMPENSATOR_LOSSQ,

	PG_SERIESCOMPENSATOR_SCIA,
	PG_SERIESCOMPENSATOR_SCIB,
	PG_SERIESCOMPENSATOR_SCIC,

	PG_SERIESCOMPENSATOR_SCI1,
	PG_SERIESCOMPENSATOR_SCI2,
	PG_SERIESCOMPENSATOR_SCI0,

	PG_SERIESCOMPENSATOR_NODEIPTR,
	PG_SERIESCOMPENSATOR_NODEJPTR,
	PG_SERIESCOMPENSATOR_TOPOBUSI,
	PG_SERIESCOMPENSATOR_TOPOBUSJ,
	PG_SERIESCOMPENSATOR_ISLAND,
	PG_SERIESCOMPENSATOR_EDGEI,
	PG_SERIESCOMPENSATOR_EDGEJ,
	PG_SERIESCOMPENSATOR_DISTRIBUTION,
	PG_SERIESCOMPENSATOR_STATE,
	PG_SERIESCOMPENSATOR_OPEN,
	PG_SERIESCOMPENSATOR_OUTAGE,
};
struct	_PG_SeriesCompensator_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	//char	szTerminalI[PGND_CHARLEN];
	//char	szTerminalJ[PGND_CHARLEN];
	char	szNodeI[PGND_CHARLEN];
	char	szNodeJ[PGND_CHARLEN];
	float	fR;
	float	fX;
	float	fX0;
	float	fRated;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;

	//	输出数据
	float	fPi;
	float	fQi;
	float	fPz;
	float	fQz;
	float	fA;
	float	fLossQ;

	float	fScIa;
	float	fScIb;
	float	fScIc;

	float	fScI1;
	float	fScI2;
	float	fScI0;

	int		nNodeI;
	int		nNodeJ;
	int		nTopoBusI;
	int		nTopoBusJ;
	short	nIsland;
	short	iRscp2;
	short	zRscp2;
	unsigned char	bDistribution;
	unsigned char	bOpen;
	unsigned char	nState;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_SeriesCompensator_	tagPGSeriesCompensator;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Breaker_	{
	PG_BREAKER_RESOURCEID=0,
	PG_BREAKER_OBJECTID,
	PG_BREAKER_SUBSTATION,
	PG_BREAKER_VOLTAGELEVEL,
	PG_BREAKER_NAME,
	PG_BREAKER_DESCRIPTION,
	//PG_BREAKER_ITERMINAL,
	//PG_BREAKER_JTERMINAL,
	PG_BREAKER_STATUS,
	PG_BREAKER_CONNECTIVITYNODEI,
	PG_BREAKER_CONNECTIVITYNODEJ,
	PG_BREAKER_MODEL,
	PG_BREAKER_CATEGORY,
	PG_BREAKER_RI_RERR,
	PG_BREAKER_RI_TREP,
	PG_BREAKER_RI_RCHK,
	PG_BREAKER_RI_TCHK,
	PG_BREAKER_RI_TFLOC,
	PG_BREAKER_RI_RSWITCH,
	PG_BREAKER_RI_TSWITCH,
	PG_BREAKER_RI_RRSWH,
	PG_BREAKER_RI_RESWH,
	PG_BREAKER_EI_INVEST,
	PG_BREAKER_MCRCHKBUS,
	PG_BREAKER_P,
	PG_BREAKER_Q,
	PG_BREAKER_A,
	PG_BREAKER_SCCAI,
	PG_BREAKER_SCCAZ,
	PG_BREAKER_RO_RCONTRIBUTION,
	PG_BREAKER_RO_UCONTRIBUTION,
	PG_BREAKER_RO_ENSCONTRIBUTION,
	PG_BREAKER_NODEIPTR,
	PG_BREAKER_NODEJPTR,
	PG_BREAKER_ISLAND,
	PG_BREAKER_EDGEI,
	PG_BREAKER_EDGEJ,
	PG_BREAKER_JOINTDEVICETYPE,
	PG_BREAKER_JOINTDEVICEINDEX,
	PG_BREAKER_INNERTYPE,
	PG_BREAKER_MCRCTLOC,
	PG_BREAKER_DISTRIBUTION,
	PG_BREAKER_NONRELIBREAKER,
	PG_BREAKER_RINGBREAKER,
	PG_BREAKER_DIRECTION,
	PG_BREAKER_OUTAGE,
};
struct	_PG_Breaker_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	//char	szTerminalI[PGND_CHARLEN];
	//char	szTerminalJ[PGND_CHARLEN];
	unsigned char	nStatus;
	char	szNodeI[PGND_CHARLEN];
	char	szNodeJ[PGND_CHARLEN];
	char	szModel[MDB_CHARLEN_SHORT];
	unsigned char	nCategory;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_RSwitch;
	float	ri_TSwitch;
	float	ri_Rrswh;
	float	ri_Reswh;

	//	经济性输入数据
	float	ei_Invest;

	//	主接线可靠性，设备检修需要停母线
	unsigned char	bMCRChkBus;

	float	fP;
	float	fQ;
	float	fA;

	float	fSccAi;
	float	fSccAz;

	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;

	int		nNodeI;
	int		nNodeJ;
	short	nIsland;
	int		nEdgeI;
	int		nEdgeJ;
	unsigned char	nJointDevType;
	int				nJointDevIndex;
	unsigned char	nInnerType;
	unsigned char	nCTLocation;
	unsigned char	bDistribution;
	unsigned char	bNonReliBreaker;
	unsigned char	bRingBreaker;
	unsigned char	nDirection;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_Breaker_	tagPGBreaker;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Disconnector_	{
	PG_DISCONNECTOR_RESOURCEID=0,
	PG_DISCONNECTOR_OBJECTID,
	PG_DISCONNECTOR_SUBSTATION,
	PG_DISCONNECTOR_VOLTAGELEVEL,
	PG_DISCONNECTOR_NAME,
	PG_DISCONNECTOR_DESCRIPTION,
	PG_DISCONNECTOR_STATUS,
	//PG_DISCONNECTOR_ITERMINAL,
	//PG_DISCONNECTOR_JTERMINAL,
	PG_DISCONNECTOR_CONNECTIVITYNODEI,
	PG_DISCONNECTOR_CONNECTIVITYNODEJ,
	PG_DISCONNECTOR_CATEGORY,
	PG_DISCONNECTOR_RI_RERR,
	PG_DISCONNECTOR_RI_TREP,
	PG_DISCONNECTOR_RI_RCHK,
	PG_DISCONNECTOR_RI_TCHK,
	PG_DISCONNECTOR_RI_TFLOC,
	PG_DISCONNECTOR_RI_RSWITCH,
	PG_DISCONNECTOR_RI_TSWITCH,
	PG_DISCONNECTOR_EI_INVEST,
	PG_DISCONNECTOR_MCRCHKBUS,
	PG_DISCONNECTOR_NODEIPTR,
	PG_DISCONNECTOR_NODEJPTR,
	PG_DISCONNECTOR_ISLAND,
	PG_DISCONNECTOR_EDGEI,
	PG_DISCONNECTOR_EDGEJ,
	PG_DISCONNECTOR_JOINTDEVICETYPE,
	PG_DISCONNECTOR_JOINTDEVICEINDEX,
	PG_DISCONNECTOR_INNERTYPE,
	PG_DISCONNECTOR_DISTRIBUTION,
	PG_DISCONNECTOR_CONSTOPEN,
	PG_DISCONNECTOR_OUTAGE,
};
struct	_PG_Disconnector_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	unsigned char	nStatus;
	//char	szTerminalI[PGND_CHARLEN];
	//char	szTerminalJ[PGND_CHARLEN];
	char	szNodeI[PGND_CHARLEN];
	char	szNodeJ[PGND_CHARLEN];
	unsigned char	nCategory;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_RSwitch;
	float	ri_TSwitch;

	//	经济性输入数据
	float	ei_Invest;

	//	主接线可靠性，设备检修需要停母线
	unsigned char	bMCRChkBus;

	int		nNodeI;
	int		nNodeJ;
	short	nIsland;
	int		nEdgeI;
	int		nEdgeJ;
	unsigned char	nJointDevType;
	int				nJointDevIndex;
	unsigned char	nInnerType;
	unsigned char	bDistribution;
	unsigned char	bConstOpen;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_Disconnector_	tagPGDisconnector;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_GroundDisconnector_	{
	PG_GROUNDDISCONNECTOR_RESOURCEID=0,
	PG_GROUNDDISCONNECTOR_OBJECTID,
	PG_GROUNDDISCONNECTOR_SUBSTATION,
	PG_GROUNDDISCONNECTOR_VOLTAGELEVEL,
	PG_GROUNDDISCONNECTOR_NAME,
	PG_GROUNDDISCONNECTOR_DESCRIPTION,
	PG_GROUNDDISCONNECTOR_STATUS,
	//PG_GROUNDDISCONNECTOR_TERMINAL,
	PG_GROUNDDISCONNECTOR_CONNECTIVITYNODE,
	PG_GROUNDDISCONNECTOR_EI_INVEST,
	PG_GROUNDDISCONNECTOR_NODEPTR,
	PG_GROUNDDISCONNECTOR_ISLAND,
};
struct	_PG_GroundDisconnector_	{
	char	szResID[MDB_CHARLEN];
	char	szObjID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];
	unsigned char	nStatus;
	//char	szTerminal[PGND_CHARLEN];
	char	szNode[PGND_CHARLEN];

	//	经济性输入数据
	float	ei_Invest;

	int		nNode;
	short	nIsland;
}	DISALIGN;
typedef	struct	_PG_GroundDisconnector_	tagPGGroundDisconnector;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_GroundTransformer_	{
	PG_GROUNDTRANSFORMER_RESOURCEID=0,
	PG_GROUNDTRANSFORMER_SUBSTATION,
	PG_GROUNDTRANSFORMER_VOLTAGELEVEL,
	PG_GROUNDTRANSFORMER_NAME,
	//PG_GROUNDTRANSFORMER_TERMINAL,
	PG_GROUNDTRANSFORMER_CONNECTIVITYNODE,
	PG_GROUNDTRANSFORMER_X0,
	PG_GROUNDTRANSFORMER_CAPACITY,
	PG_GROUNDTRANSFORMER_NODEPTR,
	PG_GROUNDTRANSFORMER_TOPOBUS,
	PG_GROUNDTRANSFORMER_ISLAND,
};
struct	_PG_GroundTransformer_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szNode[PGND_CHARLEN];
	float	fX0;
	float	fCapacity;
	int		nNode;
	int		nTopoBus;
	short	nIsland;
}	DISALIGN;
typedef	struct	_PG_GroundTransformer_	tagPGGroundTransformer;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ThermalEnergyConsumer_	{
	PG_THERMALENERGYCONSUMER_RESOURCEID=0,
	PG_THERMALENERGYCONSUMER_OBJECTID,
	PG_THERMALENERGYCONSUMER_SUBSTATION,
	PG_THERMALENERGYCONSUMER_VOLTAGELEVEL,
	PG_THERMALENERGYCONSUMER_NAME,
	PG_THERMALENERGYCONSUMER_DESCRIPTION,
	PG_THERMALENERGYCONSUMER_CONNECTIVITYNODE,
	PG_THERMALENERGYCONSUMER_TYPE,
	PG_THERMALENERGYCONSUMER_HEATINGLOAD,
	PG_THERMALENERGYCONSUMER_REFRIGERATIONLOAD,
	PG_THERMALENERGYCONSUMER_NODEPTR,
	PG_THERMALENERGYCONSUMER_TOPOBUS,
	PG_THERMALENERGYCONSUMER_ISLAND,
	PG_THERMALENERGYCONSUMER_PARENTTYPE,
	PG_THERMALENERGYCONSUMER_DISTRIBUTION,
};
struct	_PG_ThermalEnergyConsumer_	{
	char	szResID	[MDB_CHARLEN];
	char	szObjID	[MDB_CHARLEN];
	char	szSub	[MDB_CHARLEN];
	char	szVolt	[MDB_CHARLEN_SHORTER];
	char	szName	[MDB_CHARLEN];
	char	szDesp	[MDB_CHARLEN];
	char	szNode	[MDB_CHARLEN];
	unsigned char	nType;
	float	fHeatingLoad;
	float	fRefrigerationLoad;
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	nParentType;
	unsigned char	bDistribution;
}	DISALIGN;
typedef	struct	_PG_ThermalEnergyConsumer_		tagPGThermalEnergyConsumer;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ElectroChemicalEnergyStorage_	{
	PG_ELECTROCHEMICALENERGYSTORAGE_RESOURCEID=0,
	PG_ELECTROCHEMICALENERGYSTORAGE_OBJECTID,
	PG_ELECTROCHEMICALENERGYSTORAGE_SUBSTATION,
	PG_ELECTROCHEMICALENERGYSTORAGE_VOLTAGELEVEL,
	PG_ELECTROCHEMICALENERGYSTORAGE_NAME,
	PG_ELECTROCHEMICALENERGYSTORAGE_DESCRIPTION,
	PG_ELECTROCHEMICALENERGYSTORAGE_CONNECTIVITYNODE,
	PG_ELECTROCHEMICALENERGYSTORAGE_TYPE,
	PG_ELECTROCHEMICALENERGYSTORAGE_RATEDVOC,
	PG_ELECTROCHEMICALENERGYSTORAGE_RATEDCAPACITY,
	PG_ELECTROCHEMICALENERGYSTORAGE_LIFECYCLE,
	PG_ELECTROCHEMICALENERGYSTORAGE_EFFC,
	PG_ELECTROCHEMICALENERGYSTORAGE_EFFD,
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_RERR,	
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_TREP,	
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_RCHK,	
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_TCHK,	
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_TFLOC,	
	PG_ELECTROCHEMICALENERGYSTORAGE_EI_INVEST,	
	PG_ELECTROCHEMICALENERGYSTORAGE_V,
	PG_ELECTROCHEMICALENERGYSTORAGE_A,
	PG_ELECTROCHEMICALENERGYSTORAGE_NODEPTR,
	PG_ELECTROCHEMICALENERGYSTORAGE_TOPOBUS,
	PG_ELECTROCHEMICALENERGYSTORAGE_ISLAND,
	PG_ELECTROCHEMICALENERGYSTORAGE_OUTAGE,
};
struct	_PG_ElectroChemicalEnergyStorage_	{
	char	szResID	[MDB_CHARLEN];
	char	szObjID	[MDB_CHARLEN];
	char	szSub	[MDB_CHARLEN];
	char	szVolt	[MDB_CHARLEN_SHORTER];
	char	szName	[MDB_CHARLEN];
	char	szDesp	[MDB_CHARLEN];
	char	szNode	[MDB_CHARLEN];
	unsigned char	nType;
	float	fRatedVoc;
	float	fRatedCapacity;
	float	fLifeCycle;
	float	fEffc;
	float	fEffd;
	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;

	//	经济性输入数据
	float	ei_Invest;

	float	fV;
	float	fA;
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_ElectroChemicalEnergyStorage_		tagPGElectroChemicalEnergyStorage;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_Terminal_	{
	PG_TERMINAL_RESOURCEID=0,
	PG_TERMINAL_SUBSTATION,
	PG_TERMINAL_VOLTAGELEVEL,
	PG_TERMINAL_NAME,
	PG_TERMINAL_CONNECTIVITYNODE,
};
struct	_PG_Terminal_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[PGND_CHARLEN];
	char	szNode[PGND_CHARLEN];
}	DISALIGN;
typedef	struct	_PG_Terminal_	tagPGTerminal;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ConnectivityNode_	{
	PG_CONNECTIVITYNODE_SUBSTATION=0,
	PG_CONNECTIVITYNODE_VOLTAGELEVEL,
	PG_CONNECTIVITYNODE_NAME,
	PG_CONNECTIVITYNODE_ACLINESEGMENTRANGE,
	PG_CONNECTIVITYNODE_DCLINESEGMENTRANGE,
	PG_CONNECTIVITYNODE_TRANSFORMERWINDINGRANGE,
	PG_CONNECTIVITYNODE_SERIESCOMPENSATORRANGE,
	PG_CONNECTIVITYNODE_BREAKERRANGE,
	PG_CONNECTIVITYNODE_DISCONNECTORRANGE,
	PG_CONNECTIVITYNODE_VOLTAGELEVELPTR,
	PG_CONNECTIVITYNODE_BUSBARSECTIONPTR,
	PG_CONNECTIVITYNODE_TOPOBUS,
	PG_CONNECTIVITYNODE_ISLAND,
	PG_CONNECTIVITYNODE_SA_ABILITY,
	PG_CONNECTIVITYNODE_INRING,
	PG_CONNECTIVITYNODE_RADIATE,
	PG_CONNECTIVITYNODE_OPEN,
	PG_CONNECTIVITYNODE_UNPROC,
};
struct	_PG_ConnectivityNode_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[PGND_CHARLEN];
	int		nACLineSegmentRange;
	short	nDCLineSegmentRange;
	int		nTransformerWindingRange;
	short	nSeriesCompensatorRange;
	int		nBreakerRange;
	int		nDisconnectorRange;
	short	nVoltageLevelPtr;
	short	nBusbarSectionPtr;
	int		nTopoBus;
	short	nIsland;
	float	sa_Ability;
	unsigned char	bInRing;
	short	nRadiate;
	unsigned char	bOpen;
	unsigned char	bUnProc;
}	DISALIGN;
typedef	struct	_PG_ConnectivityNode_	tagPGConnectivityNode;

//	派生表定义
enum	_PGEnum_Field_EdgeACLineSegment_	{
	PG_EDGEACLINESEGMENT_SUBSTATION=0,
	PG_EDGEACLINESEGMENT_VOLTAGELEVEL,
	PG_EDGEACLINESEGMENT_CONNECTIVITYNODE,
	PG_EDGEACLINESEGMENT_NAME,
	PG_EDGEACLINESEGMENT_ACLINESEGMENTPTR,
};
struct	_PG_EdgeACLineSegment_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nACLineSegment;
}	DISALIGN;
typedef	struct	_PG_EdgeACLineSegment_	tagPGEdgeACLineSegment;

enum	_PGEnum_Field_EdgeDCLineSegment_	{
	PG_EDGEDCLINESEGMENT_SUBSTATION=0,
	PG_EDGEDCLINESEGMENT_VOLTAGELEVEL,
	PG_EDGEDCLINESEGMENT_CONNECTIVITYNODE,
	PG_EDGEDCLINESEGMENT_NAME,
	PG_EDGEDCLINESEGMENT_DCLINESEGMENTPTR,
};
struct	_PG_EdgeDCLineSegment_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nDCLineSegment;
}	DISALIGN;
typedef	struct	_PG_EdgeDCLineSegment_	tagPGEdgeDCLineSegment;

enum	_PGEnum_Field_EdgeTransformerWinding_	{
	PG_EDGETRANSFORMERWINDING_SUBSTATION=0,
	PG_EDGETRANSFORMERWINDING_VOLTAGELEVEL,
	PG_EDGETRANSFORMERWINDING_CONNECTIVITYNODE,
	PG_EDGETRANSFORMERWINDING_NAME,
	PG_EDGETRANSFORMERWINDING_TRANSFORMERWINGINGPTR,
};
struct	_PG_EdgeTransformerWinding_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nTransformerWinding;
}	DISALIGN;
typedef	struct	_PG_EdgeTransformerWinding_	tagPGEdgeTransformerWinding;

enum	_PGEnum_Field_EdgeSeriesCompensator_	{
	PG_EDGESERIESCOMPENSATOR_SUBSTATION=0,
	PG_EDGESERIESCOMPENSATOR_VOLTAGELEVEL,
	PG_EDGESERIESCOMPENSATOR_CONNECTIVITYNODE,
	PG_EDGESERIESCOMPENSATOR_NAME,
	PG_EDGESERIESCOMPENSATOR_SERIESCOMPENSATORPTR,
};
struct	_PG_EdgeSeriesCompensator_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	short	nSeriesCompensator;
}	DISALIGN;
typedef	struct	_PG_EdgeSeriesCompensator_	tagPGEdgeSeriesCompensator;

enum	_PGEnum_Field_EdgeBreaker_	{
	PG_EDGEBREAKER_SUBSTATION=0,
	PG_EDGEBREAKER_VOLTAGELEVEL,
	PG_EDGEBREAKER_CONNECTIVITYNODE,
	PG_EDGEBREAKER_NAME,
	PG_EDGEBREAKER_BREAKERPTR,
};
struct	_PG_EdgeBreaker_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	int		nBreaker;
}	DISALIGN;
typedef	struct	_PG_EdgeBreaker_	tagPGEdgeBreaker;

enum	_PGEnum_Field_EdgeDisconnector_	{
	PG_EDGEDISCONNECTOR_SUBSTATION=0,
	PG_EDGEDISCONNECTOR_VOLTAGELEVEL,
	PG_EDGEDISCONNECTOR_CONNECTIVITYNODE,
	PG_EDGEDISCONNECTOR_NAME,
	PG_EDGEDISCONNECTOR_DISCONNECTORPTR,
};
struct	_PG_EdgeDisconnector_	{
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szNode[PGND_CHARLEN];
	char	szName[MDB_CHARLEN];
	int		nDisconnector;
}	DISALIGN;
typedef	struct	_PG_EdgeDisconnector_	tagPGEdgeDisconnector;

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

//	容器表定义
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
	PG_ENERGYCONSUMERRELIABLE_RO_SWR,
	PG_ENERGYCONSUMERRELIABLE_RO_SWT,
	PG_ENERGYCONSUMERRELIABLE_RO_SWU,
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
	float	ro_swr;
	float	ro_swt;
	float	ro_swu;
	float	ro_cmr;
	float	ro_cmt;
	float	ro_cmu;
}	DISALIGN;
typedef	struct	_PG_EnergyConsumerReliable_	tagPGEnergyConsumerReliable;

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

enum	_PGEnum_Field_Island_	{
	PG_ISLAND_SLACKSUB=0,
	PG_ISLAND_SLACKGEN,
	PG_ISLAND_GENPTR,
	PG_ISLAND_UNITP,
	PG_ISLAND_UNITQ,
	PG_ISLAND_LOADP,
	PG_ISLAND_LOADQ,
	PG_ISLAND_SHUNTQ,
	PG_ISLAND_LOSSP,
	PG_ISLAND_LOSSQ,
	PG_ISLAND_NUNITNUM,
	PG_ISLAND_NLOADNUM,
	PG_ISLAND_NCAPNUM,
	PG_ISLAND_NBUSNUM,
	PG_ISLAND_NLINENUM,
	PG_ISLAND_NTRANNUM,
	PG_ISLAND_DEAD,
	PG_ISLAND_PFCONVERGENCY,
};

struct	_PG_Island_	{
	char	szSlackSub[MDB_CHARLEN_SHORT];
	char	szSlackGen[MDB_CHARLEN];
	short	nSlackGen;		//	参考发电机索引
	float	fUnitP;
	float	fUnitQ;
	float	fLoadP;
	float	fLoadQ;
	float	fShuntQ;
	float	fLossP;
	float	fLossQ;
	short	nUnitNum;
	short	nLoadNum;
	short	nCapNum	;
	short	nBusNum	;
	short	nLineNum;
	short	nTranNum;
	unsigned char	bDead;
	unsigned char	bPFConvergency;
}	DISALIGN;
typedef	struct	_PG_Island_	tagPGIsland;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_TopoBus_	{
	PG_TOPOBUS_ISLAND=0,
	PG_TOPOBUS_GENP,
	PG_TOPOBUS_GENQ,
	PG_TOPOBUS_LOADP,
	PG_TOPOBUS_LOADQ,
	PG_TOPOBUS_SHUNTQ,
	PG_TOPOBUS_V,
	PG_TOPOBUS_D,

	PG_TOPOBUS_SCR1,
	PG_TOPOBUS_SCX1,
	PG_TOPOBUS_SCR2,
	PG_TOPOBUS_SCX2,
	PG_TOPOBUS_SCR0,
	PG_TOPOBUS_SCX0,

	PG_TOPOBUS_SCI1RE,
	PG_TOPOBUS_SCI1IM,
	PG_TOPOBUS_SCI2RE,
	PG_TOPOBUS_SCI2IM,
	PG_TOPOBUS_SCI0RE,
	PG_TOPOBUS_SCI0IM,
	PG_TOPOBUS_SCV1RE,
	PG_TOPOBUS_SCV1IM,
	PG_TOPOBUS_SCV2RE,
	PG_TOPOBUS_SCV2IM,
	PG_TOPOBUS_SCV0RE,
	PG_TOPOBUS_SCV0IM,

	PG_TOPOBUS_VDIPNUM,
	PG_TOPOBUS_VOLTPTR,
};

struct	_PG_TopoBus_	{
	short	nIsland;
	float	fGenP;
	float	fGenQ;
	float	fLoadP;
	float	fLoadQ;
	float	fShuntQ;
	double	fV;
	double	fD;

	float	fSccR1;
	float	fSccX1;
	float	fSccR2;
	float	fSccX2;
	float	fSccR0;
	float	fSccX0;

	float	fScI1Re;
	float	fScI1Im;
	float	fScI2Re;
	float	fScI2Im;
	float	fScI0Re;
	float	fScI0Im;

	float	fScV1Re;
	float	fScV1Im;
	float	fScV2Re;
	float	fScV2Im;
	float	fScV0Re;
	float	fScV0Im;

	int		nVDipNum;
	short	nVolt;
}	DISALIGN;
typedef	struct	_PG_TopoBus_	tagPGTopoBus;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_TopoVDip_	{
	PG_TOPOVDIP_FAULTBUS=0,
	PG_TOPOVDIP_FAULTTYPE,
	PG_TOPOVDIP_DIPBUS,
	PG_TOPOVDIP_DIPV,
};

struct	_PG_TopoVDip_	{
	int		nFaultBus;
	unsigned char	nFaultType;
	int		nDipBus;
	float	fDipV;
}	DISALIGN;
typedef	struct	_PG_TopoVDip_	tagPGTopoVDip;

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

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtSetting_	{
	PG_PROTSETTING_PROTKER	=	0,
	PG_PROTSETTING_PROTLINEKKREL1,
	PG_PROTSETTING_PROTLINEKKREL2,
	PG_PROTSETTING_PROTLINEKKLM2,
	PG_PROTSETTING_PROTLINEKKRELP3,
	PG_PROTSETTING_PROTLINEKKRELL3,

	PG_PROTSETTING_PROTLINEK0REL1,
	PG_PROTSETTING_PROTLINEK0REL2,
	PG_PROTSETTING_PROTLINEK0REL3,
	PG_PROTSETTING_PROTLINEK0REL4,

	PG_PROTSETTING_PROTLINEKZREL1,
	PG_PROTSETTING_PROTLINEKZTREL1,
	PG_PROTSETTING_PROTLINEKZP2,
	PG_PROTSETTING_PROTLINEKZLM2,
	PG_PROTSETTING_PROTLINEKZFH3,

	PG_PROTSETTING_PROTLINEKZ0REL1,
	PG_PROTSETTING_PROTLINEKZT0REL1,
	PG_PROTSETTING_PROTLINEKZ0P2,
	PG_PROTSETTING_PROTLINEKZ0LM2,
	PG_PROTSETTING_PROTLINEKZ0P3,
	PG_PROTSETTING_PROTLINEKZ0LM3,

	PG_PROTSETTING_PROTLINEIKDZ2USINGKLM,
	PG_PROTSETTING_PROTLINEIKDZ3COORD3,
	PG_PROTSETTING_PROTLINEI0PROTINTOTRAN,
	PG_PROTSETTING_PROTLINEI0DZ2COORD2,
	PG_PROTSETTING_PROTLINEI0DZ3COORD3,
	PG_PROTSETTING_PROTLINEI0DZ3UNB,

	PG_PROTSETTING_PROTLINEZPROTINTOTRAN,
	PG_PROTSETTING_PROTLINEZDZ2COORD2,
	PG_PROTSETTING_PROTLINEZDZ2USINGKLM,
	PG_PROTSETTING_PROTLINEZDZ3COORD3,
	PG_PROTSETTING_PROTLINEZDZ3USINGKFH,

	PG_PROTSETTING_PROTLINEZ0PROTINTOTRAN,
	PG_PROTSETTING_PROTLINEZ0DZ2COORD2,
	PG_PROTSETTING_PROTLINEZ0DZ2USINGKLM,
	PG_PROTSETTING_PROTLINEZ0DZ3COORD3,
	PG_PROTSETTING_PROTLINEZ0DZ3USINGKLM,

	PG_PROTSETTING_PROTTRANKKSLM1,
	PG_PROTSETTING_PROTTRANKKLLM1,
	PG_PROTSETTING_PROTTRANKKREL3,
	PG_PROTSETTING_PROTTRANKKRES3,

	PG_PROTSETTING_PROTTRANKUOP,
	PG_PROTSETTING_PROTTRANKUOPREL,
	PG_PROTSETTING_PROTTRANKUOPRES,

	PG_PROTSETTING_PROTTRANK0LM1,
	PG_PROTSETTING_PROTTRANK0REL2,

	PG_PROTSETTING_PROTBUSKUNBREL,
	PG_PROTSETTING_PROTBUSKBRKREL,
	PG_PROTSETTING_PROTBUSFAULTUNB,

	PG_PROTSETTING_PROTGENKDREL,
	PG_PROTSETTING_PROTGENKKREL,
	PG_PROTSETTING_PROTGENKKRES,
	PG_PROTSETTING_PROTGENKAP,
	PG_PROTSETTING_PROTGENKSS,

	PG_PROTSETTING_PROTLOADKST,
	PG_PROTSETTING_PROTLOADKDREL,
	PG_PROTSETTING_PROTLOADKKREL,
	PG_PROTSETTING_PROTLOADKKRES,
	PG_PROTSETTING_PROTLOADKAP,
	PG_PROTSETTING_PROTLOADKSS,

	PG_PROTSETTING_PROTCAPKKREL2,
	PG_PROTSETTING_PROTCAPKKREL3,
	PG_PROTSETTING_PROTCAPKKRES3,

	PG_PROTSETTING_PROTREACKDREL,
	PG_PROTSETTING_PROTREACKKREL1,
	PG_PROTSETTING_PROTREACKKREL3,
	PG_PROTSETTING_PROTREACKKRES3,

	PG_PROTSETTING_PROTBREAKERKKP1,
	PG_PROTSETTING_PROTBREAKERKKLM1,
	PG_PROTSETTING_PROTBREAKERKKP2,
	PG_PROTSETTING_PROTBREAKERKKR,

	PG_PROTSETTING_PROTLINEKKSEN1,
	PG_PROTSETTING_PROTLINEKKSEN2,
	PG_PROTSETTING_PROTLINEKKSEN3,
	PG_PROTSETTING_PROTLINEK0SEN1,
	PG_PROTSETTING_PROTLINEK0SEN2,
	PG_PROTSETTING_PROTLINEK0SEN3,
	PG_PROTSETTING_PROTTRANKKSEN3,
	PG_PROTSETTING_PROTGENKKSEN3NEAR,
	PG_PROTSETTING_PROTGENKKSEN3FAR,
	PG_PROTSETTING_PROTLOADKKSEN3,
	PG_PROTSETTING_PROTCAPKKSEN2,
	PG_PROTSETTING_PROTCAPKKSEN3,
	PG_PROTSETTING_PROTREACKKSEN1,
	PG_PROTSETTING_PROTREACKKSEN3,
	PG_PROTSETTING_PROTBREAKERKKSEN1,
	PG_PROTSETTING_PROTBREAKERKKSEN2,
};

struct	_PG_ProtSetting_	{
	float			fProtKer;					//	互感器误差系数
	float			fProtLineKkrel1;			//	瞬时电流速断可靠系数
	float			fProtLineKkrel2;			//	限时电流速断可靠系数
	float			fProtLineKklm2;				//	限时电流速断可靠系数
	float			fProtLineKkrelP3;			//	定时限过电流可靠系数(保护配合)
	float			fProtLineKkrelL3;			//	定时限过电流可靠系数(最大负荷)

	float			fProtLineK0rel1;			//	零序Ⅰ段可靠系数
	float			fProtLineK0rel2;			//	零序Ⅱ段整定灵敏系数，与相邻线路零序Ⅰ段配合，与相邻线路零序Ⅱ段配合
	float			fProtLineK0rel3;			//	零序Ⅲ段可靠系数
	float			fProtLineK0rel4;			//	零序Ⅳ段可靠系数

	float			fProtLineKZrel1;			//	相间距离Ⅰ段可靠系数
	float			fProtLineKZTrel1;			//	相间距离Ⅰ段相邻变压器可靠系数
	float			fProtLineKZp2;				//	相间距离Ⅱ段配合系数
	float			fProtLineKZlm2;				//	相间距离Ⅱ段灵敏系数
	float			fProtLineKZfh3;				//	相间距离Ⅲ段负荷系数

	float			fProtLineKZ0rel1;			//	接地距离Ⅰ段可靠系数
	float			fProtLineKZT0rel1;			//	接地距离Ⅰ段相邻变压器可靠系数
	float			fProtLineKZ0p2;				//	接地距离Ⅱ段配合系数
	float			fProtLineKZ0lm2;			//	接地距离Ⅱ段灵敏系数
	float			fProtLineKZ0p3;				//	接地距离Ⅲ段配合系数
	float			fProtLineKZ0lm3;			//	接地距离Ⅲ段灵敏系数

	unsigned char	bProtLineIkdz2UsingKlm;		//	限时电流速断按灵敏度整定
	unsigned char	bProtLineIkdz3Coord3;		//	过流保护与相邻线路配合
	unsigned char	bProtLineI0ProtIntoTran;	//	零序Ⅰ段整定到变压器内
	unsigned char	bProtLineI0dz2Coord2;		//	零序Ⅱ段与邻线Ⅱ段配合
	unsigned char	bProtLineI0dz3Coord3;		//	零序Ⅲ段与邻线Ⅲ段配合
	unsigned char	bProtLineI0dz3Unb;			//	终端线路零序Ⅲ段按变压器不平衡电流整定

	unsigned char	bProtLineZProtIntoTran;		//	相间距离Ⅰ段可整定到变压器内
	unsigned char	bProtLineZdz2Coord2;		//	相间距离与相邻Ⅱ段配合
	unsigned char	bProtLineZdz2UsingKlm;		//	相间距离Ⅱ段按灵敏度整定
	unsigned char	bProtLineZdz3Coord3;		//	相间距离与相邻Ⅲ段配合
	unsigned char	bProtLineZdz3UsingKfh;		//	相间距离Ⅲ段按负荷整定

	unsigned char	bProtLineZ0ProtIntoTran;	//	接地距离Ⅰ段可整定到变压器内
	unsigned char	bProtLineZ0dz2Coord2;		//	接地距离与相邻Ⅱ段配合
	unsigned char	bProtLineZ0dz2UsingKlm;		//	接地距离Ⅱ段按灵敏度整定
	unsigned char	bProtLineZ0dz3Coord3;		//	接地距离与相邻Ⅲ段配合
	unsigned char	bProtLineZ0dz3UsingKlm;		//	接地距离Ⅲ段按灵敏度整定
	////////////////////////////////////////////////////////////////////////

	float			fProtTranKkslm1;				//	负荷侧过流保护灵敏系数
	float			fProtTranKkllm1;				//	负荷侧过流保护灵敏系数
	float			fProtTranKkrel3;			//	过流保护可靠系数
	float			fProtTranKkres3;			//	过流保护返回系数

	float			fProtTranKuop;				//	复压闭锁电压值
	float			fProtTranKuoprel;			//	复压闭锁可靠系数
	float			fProtTranKuopres;			//	复压闭锁返回系数

	float			fProtTranK0lm1;				//	零序Ⅰ段灵敏系数
	float			fProtTranK0rel2;			//	零序Ⅱ段可靠系数
	////////////////////////////////////////////////////////////////////////

	float			fProtBusKunbrel;			//	不平衡电流可靠系数
	float			fProtBusKbrkrel;			//	二次断线可靠系数
	unsigned char	bProtBusFaultUnb;
	////////////////////////////////////////////////////////////////////////

	float			fProtGenKdrel;				//	纵差保护可靠系数
	float			fProtGenKkrel;				//	过流保护可靠系数
	float			fProtGenKkres;				//	过流保护返回系数
	float			fProtGenKap;				//	非周期分量影响系数
	float			fProtGenKss;				//	电流互感器同型系数
	////////////////////////////////////////////////////////////////////////

	float			fProtLoadKst;				//	电动机启动电流倍数
	float			fProtLoadKdrel;				//	纵差保护可靠系数
	float			fProtLoadKkrel;				//	过流保护可靠系数
	float			fProtLoadKkres;				//	过流保护返回系数
	float			fProtLoadKap;				//	非周期分量影响系数
	float			fProtLoadKss;				//	电流互感器同型系数
	////////////////////////////////////////////////////////////////////////

	float			fProtCapKkrel2;				//	延时电流速断可靠系数
	float			fProtCapKkrel3;				//	过流保护可靠系数
	float			fProtCapKkres3;				//	过流保护返回系数
	////////////////////////////////////////////////////////////////////////

	float			fProtReacKdrel;				//	差动保护可靠系数
	float			fProtReacKkrel1;			//	电流速断可靠系数
	float			fProtReacKkrel3;			//	过流保护可靠系数
	float			fProtReacKkres3;			//	过流保护返回系数
	////////////////////////////////////////////////////////////////////////

	float			fProtBreakerKkp1;			//	过流Ⅰ段配合系数
	float			fProtBreakerKklm1;			//	过流Ⅰ段灵敏系数
	float			fProtBreakerKkp2;			//	过流Ⅱ段配合系数
	float			fProtBreakerKkr;			//	合环保护可靠系数

	float			fProtLineKksen1;			//	线路瞬时电流速断灵敏系数
	float			fProtLineKksen2;			//	线路限时电流速断灵敏系数
	float			fProtLineKksen3;			//	线路定时限过电流灵敏系数
	float			fProtLineK0sen1;			//	线路零序Ⅰ段灵敏系数
	float			fProtLineK0sen2;			//	线路零序Ⅱ段灵敏系数
	float			fProtLineK0sen3;			//	线路零序Ⅲ段灵敏系数
	float			fProtTranKksen3;			//	变压器过流保护灵敏系数
	float			fProtGenKksen3Near;			//	发电机近后备过流保护灵敏系数
	float			fProtGenKksen3Far;			//	发电机远后备过流保护灵敏系数
	float			fProtLoadKksen3;			//	电动机过流保护灵敏系数
	float			fProtCapKksen2;				//	并联电容器延时电流速断灵敏系数
	float			fProtCapKksen3;				//	并联电容器过流保护灵敏系数
	float			fProtReacKksen1;			//	并联电抗器电流速断灵敏系数
	float			fProtReacKksen3;			//	并联电抗器过流保护灵敏系数
	float			fProtBreakerKsen1;			//	母联/分段开关过流Ⅰ段灵敏系数
	float			fProtBreakerKsen2;			//	母联/分段开关过流Ⅱ段灵敏系数
}	DISALIGN;
typedef	struct	_PG_ProtSetting_	tagPGProtSetting;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtLine_	{
	PG_PROTLINE_NAME=0,

	PG_PROTLINE_SUBI,
	PG_PROTLINE_SUBJ,
	PG_PROTLINE_VOLT,
	PG_PROTLINE_NORMINALVOLT,
	PG_PROTLINE_RATE,
	PG_PROTLINE_TOPOBUSI,
	PG_PROTLINE_TOPOBUSJ,

	PG_PROTLINE_POWERED,
	PG_PROTLINE_SRCGENI,
	PG_PROTLINE_SRCGENJ,
	PG_PROTLINE_ZGROUND,
	PG_PROTLINE_ZGTOPOBUSI,
	PG_PROTLINE_ZGTOPOBUSJ,

	PG_PROTLINE_IKMAXI,
	PG_PROTLINE_I0MAXI,
	PG_PROTLINE_I0TRANI,

	PG_PROTLINE_IKMININEAR,
	PG_PROTLINE_I0MININEAR,
	PG_PROTLINE_IKMINIFAR,
	PG_PROTLINE_I0MINIFAR,

	PG_PROTLINE_IKMAXJ,
	PG_PROTLINE_I0MAXJ,
	PG_PROTLINE_I0TRANJ,

	PG_PROTLINE_IKMINJNEAR,
	PG_PROTLINE_I0MINJNEAR,
	PG_PROTLINE_IKMINJFAR,
	PG_PROTLINE_I0MINJFAR,

	PG_PROTLINE_IKINTOTRANI,
	PG_PROTLINE_IKINTOTRANJ,

	PG_PROTLINE_N1IKMINI,
	PG_PROTLINE_N1I0MINI,
	PG_PROTLINE_N1IKMINJ,
	PG_PROTLINE_N1I0MINJ,
	PG_PROTLINE_N1IKMINIBUS,
	PG_PROTLINE_N1I0MINIBUS,
	PG_PROTLINE_N1IKMINJBUS,
	PG_PROTLINE_N1I0MINJBUS,

	PG_PROTLINE_KREL1,
	PG_PROTLINE_KREL2,
	PG_PROTLINE_KLM2,
	PG_PROTLINE_KRELP3,
	PG_PROTLINE_KRELL3,
	PG_PROTLINE_K0REL1,
	PG_PROTLINE_K0REL2,
	PG_PROTLINE_K0REL3,
	PG_PROTLINE_K0REL4,

	PG_PROTLINE_KZREL1,
	PG_PROTLINE_KZTREL1,
	PG_PROTLINE_KZP2,
	PG_PROTLINE_KZLM2,
	PG_PROTLINE_KZFH3,

	PG_PROTLINE_KZ0REL1,
	PG_PROTLINE_KZT0REL1,
	PG_PROTLINE_KZ0P2,
	PG_PROTLINE_KZ0LM2,
	PG_PROTLINE_KZ0P3,
	PG_PROTLINE_KZ0LM3,

	PG_PROTLINE_IKDZ2USINGKLM,
	PG_PROTLINE_IKDZ3COORD3,
	PG_PROTLINE_I0PROTINTOTRAN	,
	PG_PROTLINE_I0DZ2COORD2,
	PG_PROTLINE_I0DZ3COORD3,
	PG_PROTLINE_I0DZ3UNB,

	PG_PROTLINE_ZPROTINTOTRAN,
	PG_PROTLINE_ZDZ2COORD2,
	PG_PROTLINE_ZDZ2USINGKLM,
	PG_PROTLINE_ZDZ3COORD3,
	PG_PROTLINE_ZDZ3USINGKFH,

	PG_PROTLINE_Z0PROTINTOTRAN,
	PG_PROTLINE_Z0DZ2COORD2,
	PG_PROTLINE_Z0DZ2USINGKLM,
	PG_PROTLINE_Z0DZ3COORD3,
	PG_PROTLINE_Z0DZ3USINGKLM,

	PG_PROTLINE_IDZ1I,
	PG_PROTLINE_IDZ2I,
	PG_PROTLINE_IDZ3I,

	PG_PROTLINE_I0DZ1I,
	PG_PROTLINE_I0DZ2I,
	PG_PROTLINE_I0DZ3I,
	PG_PROTLINE_I0DZ1INTOTRANI,

	PG_PROTLINE_ZDZ1I,
	PG_PROTLINE_ZDZ2I,
	PG_PROTLINE_ZDZ3I,

	PG_PROTLINE_Z0DZ1I,
	PG_PROTLINE_Z0DZ2I,
	PG_PROTLINE_Z0DZ3I,

	PG_PROTLINE_IDZ1J,
	PG_PROTLINE_IDZ2J,
	PG_PROTLINE_IDZ3J,

	PG_PROTLINE_I0DZ1J,
	PG_PROTLINE_I0DZ2J,
	PG_PROTLINE_I0DZ3J,
	PG_PROTLINE_I0DZ1INTOTRANJ,

	PG_PROTLINE_ZDZ1J,
	PG_PROTLINE_ZDZ2J,
	PG_PROTLINE_ZDZ3J,

	PG_PROTLINE_Z0DZ1J,
	PG_PROTLINE_Z0DZ2J,
	PG_PROTLINE_Z0DZ3J,

	PG_PROTLINE_KSEN1I,
	PG_PROTLINE_KSEN2I,
	PG_PROTLINE_KSEN3I,

	PG_PROTLINE_K0SEN1I,
	PG_PROTLINE_K0SEN2I,
	PG_PROTLINE_K0SEN3I,

	PG_PROTLINE_KSEN1J,
	PG_PROTLINE_KSEN2J,
	PG_PROTLINE_KSEN3J,

	PG_PROTLINE_K0SEN1J,
	PG_PROTLINE_K0SEN2J,
	PG_PROTLINE_K0SEN3J,

	PG_PROTLINE_ACLINESEGMENTPTR,
};

struct	_PG_ProtLine_	{
	char			szName[MDB_CHARLEN];

	char			szSubI[MDB_CHARLEN];
	char			szSubJ[MDB_CHARLEN];
	char			szVolt[MDB_CHARLEN_SHORTER];
	float			fNorminalVolt;
	float			fRate;
	int				nTopoBusI;
	int				nTopoBusJ;

	unsigned char	bPowered;
	short			nSrcGenI;
	short			nSrcGenJ;
	unsigned char	bZGround;
	int				nZGBusI;
	int				nZGBusJ;

	//////////////////////////////////////////////////////////////////////////
	//	线路两侧最大最小短路电流
	float			fIkmaxI;
	float			fI0maxI;
	float			fI0TranI;

	float			fIkminINear;
	float			fI0minINear;
	float			fIkminIFar;
	float			fI0minIFar;

	float			fIkmaxJ;
	float			fI0maxJ;
	float			fI0TranJ;

	float			fIkminJNear;
	float			fI0minJNear;
	float			fIkminJFar;
	float			fI0minJFar;

	unsigned char	bIkIntoTranI;
	unsigned char	bIkIntoTranJ;

	//////////////////////////////////////////////////////////////////////////
	//	线路两侧一级相邻最大最小短路电流，无线路则按变压器对侧的
	float			fN1IkminI;
	float			fN1I0minI;
	float			fN1IkminJ;
	float			fN1I0minJ;
	char			szN1IkminIBus[MDB_CHARLEN];
	char			szN1I0minIBus[MDB_CHARLEN];
	char			szN1IkminJBus[MDB_CHARLEN];
	char			szN1I0minJBus[MDB_CHARLEN];

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkrel1;
	float			fKkrel2;
	float			fKklm2;
	float			fKkrelP3;
	float			fKkrelL3;
	float			fK0rel1;
	float			fK0rel2;
	float			fK0rel3;
	float			fK0rel4;

	float			fKZrel1;
	float			fKZTrel1;
	float			fKZp2;
	float			fKZlm2;
	float			fKZfh3;

	float			fKZ0rel1;
	float			fKZT0rel1;
	float			fKZ0p2;
	float			fKZ0lm2;
	float			fKZ0p3;
	float			fKZ0lm3;

	unsigned char	bIkdz2UsingKlm;
	unsigned char	bIkdz3Coord3;
	unsigned char	bI0ProtIntoTran;
	unsigned char	bI0dz2Coord2;
	unsigned char	bI0dz3Coord3;
	unsigned char	bI0dz3Unb;

	unsigned char	bZProtIntoTran;
	unsigned char	bZdz2Coord2;
	unsigned char	bZdz2UsingKlm;
	unsigned char	bZdz3Coord3;
	unsigned char	bZdz3UsingKfh;

	unsigned char	bZ0ProtIntoTran;
	unsigned char	bZ0dz2Coord2;
	unsigned char	bZ0dz2UsingKlm;
	unsigned char	bZ0dz3Coord3;
	unsigned char	bZ0dz3UsingKlm;

	//////////////////////////////////////////////////////////////////////////
	//	I侧保护整定值
	float			fIkdz1I;
	float			fIkdz2I;
	float			fIkdz3I;

	float			fI0dz1I;
	float			fI0dz2I;
	float			fI0dz3I;
	unsigned char	bI0dzIntoTranI;

	float			fZkdz1I;
	float			fZkdz2I;
	float			fZkdz3I;

	float			fZ0dz1I;
	float			fZ0dz2I;
	float			fZ0dz3I;

	//////////////////////////////////////////////////////////////////////////
	//	J侧保护整定值
	float			fIdz1J;
	float			fIdz2J;
	float			fIdz3J;

	float			fI0dz1J;
	float			fI0dz2J;
	float			fI0dz3J;
	unsigned char	bI0dzIntoTranJ;

	float			fZdz1J;
	float			fZdz2J;
	float			fZdz3J;

	float			fZ0dz1J;
	float			fZ0dz2J;
	float			fZ0dz3J;

	//////////////////////////////////////////////////////////////////////////
	//	I侧保护灵敏系数
	float			fKsen1I;
	float			fKsen2I;
	float			fKsen3I;

	float			fK0sen1I;
	float			fK0sen2I;
	float			fK0sen3I;

	//////////////////////////////////////////////////////////////////////////
	//	J侧保护灵敏系数
	float			fKsen1J;
	float			fKsen2J;
	float			fKsen3J;

	float			fK0sen1J;
	float			fK0sen2J;
	float			fK0sen3J;

	short			nACLineSegment;
}	DISALIGN;
typedef	struct	_PG_ProtLine_	tagPGProtLine;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtTran_	{
	PG_PROTTRAN_NAME=0,
	PG_PROTTRAN_SUB,

	PG_PROTTRAN_VOLTH,
	PG_PROTTRAN_VOLTM,
	PG_PROTTRAN_VOLTL,
	PG_PROTTRAN_3WIND,
	PG_PROTTRAN_TOPOBUSH,
	PG_PROTTRAN_TOPOBUSM,
	PG_PROTTRAN_TOPOBUSL,

	PG_PROTTRAN_RATEVOLTH,
	PG_PROTTRAN_RATEVOLTM,
	PG_PROTTRAN_RATEVOLTL,
	PG_PROTTRAN_RATEH,
	PG_PROTTRAN_RATEM,
	PG_PROTTRAN_RATEL,

	PG_PROTTRAN_LOADTRAN,
	PG_PROTTRAN_POWERH,
	PG_PROTTRAN_POWERM,
	PG_PROTTRAN_POWERL,
	PG_PROTTRAN_ZGSTATH,
	PG_PROTTRAN_ZGSTATM,
	PG_PROTTRAN_ZGSTATL,

	PG_PROTTRAN_ITMAXH,
	PG_PROTTRAN_ITMAXM,
	PG_PROTTRAN_ITMAXL,

	PG_PROTTRAN_ITMINH,
	PG_PROTTRAN_ITMINM,
	PG_PROTTRAN_ITMINL,

	PG_PROTTRAN_I0TMAXH,
	PG_PROTTRAN_I0TMAXM,
	PG_PROTTRAN_I0TMAXL,

	PG_PROTTRAN_I0TMINH,
	PG_PROTTRAN_I0TMINM,
	PG_PROTTRAN_I0TMINL,

	PG_PROTTRAN_IOBMAXH,
	PG_PROTTRAN_IOBMAXM,
	PG_PROTTRAN_IOBMAXL,

	PG_PROTTRAN_IOBMINH,
	PG_PROTTRAN_IOBMINM,
	PG_PROTTRAN_IOBMINL,

	PG_PROTTRAN_IKMAXHNEAR,
	PG_PROTTRAN_IKMAXMNEAR,
	PG_PROTTRAN_IKMAXLNEAR,

	PG_PROTTRAN_IKMINHNEAR,
	PG_PROTTRAN_IKMINMNEAR,
	PG_PROTTRAN_IKMINLNEAR,

	PG_PROTTRAN_I0KMAXHNEAR,
	PG_PROTTRAN_I0KMAXMNEAR,
	PG_PROTTRAN_I0KMAXLNEAR,

	PG_PROTTRAN_I0KMINHNEAR,
	PG_PROTTRAN_I0KMINMNEAR,
	PG_PROTTRAN_I0KMINLNEAR,

	PG_PROTTRAN_IKMAXHFAR,
	PG_PROTTRAN_IKMAXMFAR,
	PG_PROTTRAN_IKMAXLFAR,

	PG_PROTTRAN_IKMINHFAR,
	PG_PROTTRAN_IKMINMFAR,
	PG_PROTTRAN_IKMINLFAR,

	PG_PROTTRAN_I0KMAXHFAR,
	PG_PROTTRAN_I0KMAXMFAR,
	PG_PROTTRAN_I0KMAXLFAR,

	PG_PROTTRAN_I0KMINHFAR,
	PG_PROTTRAN_I0KMINMFAR,
	PG_PROTTRAN_I0KMINLFAR,

	PG_PROTTRAN_IKUNBH,
	PG_PROTTRAN_IKUNBM,
	PG_PROTTRAN_IKUNBL,

	PG_PROTTRAN_KKSLM1,
	PG_PROTTRAN_KKLLM1,
	PG_PROTTRAN_KKREL3,
	PG_PROTTRAN_KKRES3,

	PG_PROTTRAN_KUOP,
	PG_PROTTRAN_KUOPREL,
	PG_PROTTRAN_KUOPRES,

	PG_PROTTRAN_K0LM1,
	PG_PROTTRAN_K0REL2,

	PG_PROTTRAN_IKDZ1H,
	PG_PROTTRAN_IKDZ1M,
	PG_PROTTRAN_IKDZ1L,

	PG_PROTTRAN_IKDZ3H,
	PG_PROTTRAN_IKDZ3M,
	PG_PROTTRAN_IKDZ3L,

	PG_PROTTRAN_UOPH,
	PG_PROTTRAN_UOPM,
	PG_PROTTRAN_UOPL,

	PG_PROTTRAN_I0DZ1H,
	PG_PROTTRAN_I0DZ1M,
	PG_PROTTRAN_I0DZ1L,

	PG_PROTTRAN_I0DZ2H,
	PG_PROTTRAN_I0DZ2M,
	PG_PROTTRAN_I0DZ2L,

	PG_PROTTRAN_KKSEN3H,
	PG_PROTTRAN_KKSEN3M,
	PG_PROTTRAN_KKSEN3L,

	PG_PROTTRAN_POWERTRANSFORMERPTR,
};

struct	_PG_ProtTran_	{
	char			szName[MDB_CHARLEN];
	char			szSub[MDB_CHARLEN];

	char			szVoltH[MDB_CHARLEN_SHORTER];
	char			szVoltM[MDB_CHARLEN_SHORTER];
	char			szVoltL[MDB_CHARLEN_SHORTER];
	unsigned char	b3Wind;			//	三卷变标记
	int				nTopoBusH;		//	高压卷拓扑母线
	int				nTopoBusM;		//	中压卷拓扑母线
	int				nTopoBusL;		//	低压卷拓扑母线

	float			fRateVoltH;
	float			fRateVoltM;
	float			fRateVoltL;
	float			fRateH;
	float			fRateM;
	float			fRateL;

	unsigned char	bLoadTran;		//	负荷变压器，即只有一侧连接电源的变压器
	unsigned char	bPowerH;		//	电源标记，=0无源，=1电源
	unsigned char	bPowerM;		//	电源标记，=0无源，=1电源
	unsigned char	bPowerL;		//	电源标记，=0无源，=1电源

	unsigned char	nZGStatH;		//	高压卷零序情况，=0，不通；=1，支路；=2接地
	unsigned char	nZGStatM;		//	中压卷零序情况，=0，不通；=1，支路；=2接地
	unsigned char	nZGStatL;		//	中压卷零序情况，=0，不通；=1，支路；=2接地

	//////////////////////////////////////////////////////////////////////////
	//	主变各侧母线短路，变压器的最大最小短路电流，相当于变压器内部短路
	float			fItmaxH	;
	float			fItmaxM	;
	float			fItmaxL	;

	float			fItminH	;
	float			fItminM	;
	float			fItminL	;

	float			fI0tmaxH;
	float			fI0tmaxM;
	float			fI0tmaxL;

	float			fI0tminH;
	float			fI0tminM;
	float			fI0tminL;

	//////////////////////////////////////////////////////////////////////////
	//	主变对侧母线短路，变压器的最大最小短路电流
	float			fIobmaxH	;
	float			fIobmaxM	;
	float			fIobmaxL	;

	float			fIobminH	;
	float			fIobminM	;
	float			fIobminL	;

	//////////////////////////////////////////////////////////////////////////
	//	主变本侧母线短路，变压器的最大最小短路电流
	float			fIkmaxHNear	;
	float			fIkmaxMNear	;
	float			fIkmaxLNear	;

	float			fIkminHNear	;
	float			fIkminMNear	;
	float			fIkminLNear	;

	float			fI0kmaxHNear;
	float			fI0kmaxMNear;
	float			fI0kmaxLNear;

	float			fI0kminHNear;
	float			fI0kminMNear;
	float			fI0kminLNear;

	//////////////////////////////////////////////////////////////////////////
	//	主变各侧一级相邻线路最大最小短路电流
	float			fIkmaxHFar	;
	float			fIkmaxMFar	;
	float			fIkmaxLFar	;

	float			fIkminHFar	;
	float			fIkminMFar	;
	float			fIkminLFar	;

	float			fI0kmaxHFar;
	float			fI0kmaxMFar;
	float			fI0kmaxLFar;

	float			fI0kminHFar;
	float			fI0kminMFar;
	float			fI0kminLFar;

	//////////////////////////////////////////////////////////////////////////
	//	主变各侧最大不平衡电流计算用电流，仅仅显示用于测试
	float			fIkunbH;
	float			fIkunbM;
	float			fIkunbL;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkslm1;		//	电源侧过流Ⅰ段保护灵敏系数
	float			fKkllm1;		//	负荷侧过流Ⅰ段保护灵敏系数
	float			fKkrel3;		//	过流保护可靠系数
	float			fKkres3;		//	过流保护返回系数

	float			fKuop;			//	复压闭锁电压值
	float			fKuoprel;		//	复压闭锁可靠系数
	float			fKuopres;		//	复压闭锁返回系数

	float			fK0lm1;			//	零序Ⅰ段灵敏系数
	float			fK0rel2;		//	零序Ⅱ段可靠系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkdz1H;		//	电流保护Ⅰ段动作电流，是负荷侧整定，对电源侧无效
	float			fIkdz1M;		//	电流保护Ⅰ段动作电流，是负荷侧整定，对电源侧无效
	float			fIkdz1L;		//	电流保护Ⅰ段动作电流，是负荷侧整定，对电源侧无效

	float			fIkdz3H;		//	过流保护动作电流
	float			fIkdz3M;		//	过流保护动作电流
	float			fIkdz3L;		//	过流保护动作电流

	float			fUopH;			//	复压闭锁整定电压
	float			fUopM;			//	复压闭锁整定电压
	float			fUopL;			//	复压闭锁整定电压

	float			fI0dz1H;		//	零序Ⅰ段动作电流
	float			fI0dz1M;		//	零序Ⅰ段动作电流
	float			fI0dz1L;		//	零序Ⅰ段动作电流

	float			fI0dz2H;		//	零序Ⅱ段动作电流
	float			fI0dz2M;		//	零序Ⅱ段动作电流
	float			fI0dz2L;		//	零序Ⅱ段动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKksen3H;		//	过流保护灵敏系数
	float			fKksen3M;		//	过流保护灵敏系数
	float			fKksen3L;		//	过流保护灵敏系数

	short			nPowerTransformer;
}	DISALIGN;
typedef	struct	_PG_ProtTran_	tagPGProtTran;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtBus_	{
	PG_PROTBUS_NAME=0,
	PG_PROTBUS_TOPOBUS,

	PG_PROTBUS_IBRANKMAX,
	PG_PROTBUS_IBRANEMAX,
	PG_PROTBUS_IKMIN,

	PG_PROTBUS_KUNBREL,
	PG_PROTBUS_KBRKREL,
	PG_PROTBUS_FAULTUNB,

	PG_PROTBUS_IKOP,
	PG_PROTBUS_ILOP,
	PG_PROTBUS_IOOP,
	PG_PROTBUS_IKDZ,

	PG_PROTBUS_KSEN,

	PG_PROTBUS_BUSPTR,
};

struct	_PG_ProtBus_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;

	//////////////////////////////////////////////////////////////////////////
	//	母线最大短路电流，最大负荷电流
	float			fIbrankmax;			//	支路最大短路电流
	float			fIbranemax;			//	支路最大负荷电流
	float			fIkmin;				//	母线最小短路电流

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKunbrel;			//	导则：不平衡电流可靠系数	一般大于2或3
	float			fKbrkrel;			//	导则：二次断线可靠系数	一般取1.1~1.3
	unsigned char	bFaultUnb;			//	外部短路故障整定不平衡电流

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkop;				//	外部短路计算不平衡电流，躲避不平衡电流差动保护动作电流
	float			fIlop;				//	最大负荷计算不平衡电流，躲避不平衡电流差动保护动作电流
	float			fIoop;				//	躲避二次断线差动保护动作电流
	float			fIdz;				//	差动保护动作电流	Idz

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen;				//	导则：灵敏系数，不小于2

	short			nBus;
}	DISALIGN;
typedef	struct	_PG_ProtBus_	tagPGProtBus;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtGen_	{
	PG_PROTGEN_NAME=0,
	PG_PROTGEN_TOPOBUS,
	PG_PROTGEN_RATE,

	PG_PROTGEN_IKMAX,
	PG_PROTGEN_IKMINNEAR,
	PG_PROTGEN_IKMINFAR,

	PG_PROTGEN_KDREL,
	PG_PROTGEN_KKREL,
	PG_PROTGEN_KKRES,
	PG_PROTGEN_KAP,
	PG_PROTGEN_KSS,

	PG_PROTGEN_IUNBMAX,
	PG_PROTGEN_IDDZ,
	PG_PROTGEN_IKDZ,

	PG_PROTGEN_KKSENNEAR,
	PG_PROTGEN_KKSENFAR,

	PG_PROTGEN_GENPTR,
};

struct	_PG_ProtGen_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkminNear;
	float			fIkminFar;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKdrel;			//	纵差保护可靠系数
	float			fKkrel;			//	过流保护可靠系数
	float			fKkres;			//	过流保护返回系数
	float			fKap;			//	非周期分量影响系数
	float			fKss;			//	电流互感器同型系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIunbmax;		//	纵差最大不平衡电流	Iunbmax
	float			fIddz;			//	纵差保护动作电流	Iddz
	float			fIkdz;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKksenNear;		//	过流保护近后备灵敏系数
	float			fKksenFar;		//	过流保护远后备灵敏系数

	short			nGen;
}	DISALIGN;
typedef	struct	_PG_ProtGen_	tagPGProtGen;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtCap_	{
	PG_PROTCAP_NAME=0,
	PG_PROTCAP_TOPOBUS,
	PG_PROTCAP_RATE,

	PG_PROTCAP_IKMAX,
	PG_PROTCAP_IKMIN,

	PG_PROTCAP_KKREL2,
	PG_PROTCAP_KKREL3,
	PG_PROTCAP_KKRES3,

	PG_PROTCAP_IKDZ2,
	PG_PROTCAP_IKDZ3,

	PG_PROTCAP_KSEN2,
	PG_PROTCAP_KSEN3,

	PG_PROTCAP_CAPPTR,
};

struct	_PG_ProtCap_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkrel2;		//	延时电流速断保护可靠系数
	float			fKkrel3;		//	过流保护可靠系数
	float			fKkres3;		//	过流保护返回系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkdz2;			//	延时电流速断动作电流	Iddz
	float			fIkdz3;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen2;			//	过流保护近后备灵敏系数
	float			fKsen3;			//	过流保护远后备灵敏系数

	short			nCap;
}	DISALIGN;
typedef	struct	_PG_ProtCap_	tagPGProtCap;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtReac_	{
	PG_PROTREAC_NAME=0,
	PG_PROTREAC_TOPOBUS,
	PG_PROTREAC_RATE,

	PG_PROTREAC_IKMAX,
	PG_PROTREAC_IKMIN,

	PG_PROTREAC_KDREL,
	PG_PROTREAC_KKREL1,
	PG_PROTREAC_KKREL3,
	PG_PROTREAC_KKRES3,

	PG_PROTREAC_IDDZ,
	PG_PROTREAC_IKDZ1,
	PG_PROTREAC_IKDZ3,

	PG_PROTREAC_KSEN1,
	PG_PROTREAC_KSEN3,

	PG_PROTREAC_REACPTR,
};

struct	_PG_ProtReac_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKdrel;			//	差动保护整定系数
	float			fKkrel1;		//	瞬时电流速断保护可靠系数
	float			fKkrel3;		//	过流保护可靠系数
	float			fKkres3;		//	过流保护返回系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIddz;			//	差动保护动作电流
	float			fIkdz1;			//	瞬时电流速断动作电流
	float			fIkdz3;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen1;			//	瞬时电流速断灵敏系数
	float			fKsen3;			//	过流保护远后备灵敏系数

	short			nReac;
}	DISALIGN;
typedef	struct	_PG_ProtReac_	tagPGProtReac;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtMotor_	{
	PG_PROTMOTOR_NAME=0,
	PG_PROTMOTOR_TOPOBUS,
	PG_PROTMOTOR_RATE,

	PG_PROTMOTOR_IKMAX,
	PG_PROTMOTOR_IKMIN,

	PG_PROTMOTOR_KST,
	PG_PROTMOTOR_KDREL,
	PG_PROTMOTOR_KKREL,
	PG_PROTMOTOR_KKRES,
	PG_PROTMOTOR_KAP,
	PG_PROTMOTOR_KSS,

	PG_PROTMOTOR_IUNBMAX,
	PG_PROTMOTOR_IDDZ,
	PG_PROTMOTOR_IKDZ,

	PG_PROTMOTOR_KDSEN,
	PG_PROTMOTOR_KKSEN,

	PG_PROTMOTOR_LOADPTR,
};

struct	_PG_ProtMotor_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKst;			//	电动机启动电流倍数
	float			fKdrel;			//	纵差保护可靠系数
	float			fKkrel;			//	过流保护可靠系数
	float			fKkres;			//	过流保护返回系数
	float			fKap;			//	非周期分量影响系数
	float			fKss;			//	电流互感器同型系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIunbmax;		//	纵差最大不平衡电流
	float			fIddz;			//	纵差保护动作电流
	float			fIkdz;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKdsen;			//	瞬时电流速断灵敏系数
	float			fKksen;			//	过流保护远后备灵敏系数

	int				nLoad;
}	DISALIGN;
typedef	struct	_PG_ProtMotor_	tagPGProtMotor;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtBreaker_	{
	PG_PROTBREAKER_NAME=0,
	PG_PROTBREAKER_TOPOBUS,

	PG_PROTBREAKER_ILINEMAX,
	PG_PROTBREAKER_ITRANMAX,
	PG_PROTBREAKER_LOWVBREAKER,

	PG_PROTBREAKER_IKMAX,
	PG_PROTBREAKER_IKMIN,

	PG_PROTBREAKER_KKP1,
	PG_PROTBREAKER_KKLM1,
	PG_PROTBREAKER_KKP2,
	PG_PROTBREAKER_KKR,

	PG_PROTBREAKER_IKDZ1,
	PG_PROTBREAKER_IKDZ2,
	PG_PROTBREAKER_IRDZ,

	PG_PROTBREAKER_KSEN1,
	PG_PROTBREAKER_KSEN2,

	PG_PROTBREAKER_BREAKERPTR,
};

struct	_PG_ProtBreaker_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;

	float			fILineRateMax;		//	线路最大额定电流
	float			fITranRateMax;		//	变压器最大额定电流
	unsigned char	bLowVBreaker;
	//////////////////////////////////////////////////////////////////////////
	//	最大短路电流，最大负荷电流
	float			fIkmax;				//	最大短路电流
	float			fIkmin;				//	最小短路电流

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkp1;				//	过流Ⅰ段配合系数
	float			fKklm1;				//	过流Ⅰ段灵敏系数
	float			fKkp2;				//	过流Ⅱ段配合系数
	float			fKkr;				//	合环保护可靠系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkdz1;				//	过流Ⅰ段保护动作电流
	float			fIkdz2;				//	过流Ⅱ段保护动作电流
	float			fIrdz;				//	合环保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen1;
	float			fKsen2;

	int				nBreaker;
}	DISALIGN;
typedef	struct	_PG_ProtBreaker_	tagPGProtBreaker;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_SubRegion_	{
	PG_SUBREGION_RESOURCEID=0,
	PG_SUBREGION_NAME,
	PG_SUBREGION_DESCRIPTION,
	PG_SUBREGION_REGIONTYPE,
	PG_SUBREGION_TOTALGENP,
	PG_SUBREGION_TOTALGENQ,
	PG_SUBREGION_TOTALLOADP,
	PG_SUBREGION_TOTALLOADQ,
	PG_SUBREGION_TOTALCAP,
	PG_SUBREGION_TOTALREAC,
	PG_SUBREGION_TOTALLOSSP,
	PG_SUBREGION_TOTALLOSSQ,
	PG_SUBREGION_GENFATCTOR,
	PG_SUBREGION_LOADFATCTOR,
	PG_SUBREGION_RO_CUSTOMERNUM,
	PG_SUBREGION_RO_ACI,
	PG_SUBREGION_RO_CID,
	PG_SUBREGION_RO_SAIFI,
	PG_SUBREGION_RO_SAIDI,
	PG_SUBREGION_RO_ASAI,
	PG_SUBREGION_RO_ENS,
	PG_SUBREGION_RO_AENS,
	PG_SUBREGION_RO_MIC,
	PG_SUBREGION_RO_MID,
	PG_SUBREGION_RO_F_ACI,
	PG_SUBREGION_RO_F_CID,
	PG_SUBREGION_RO_F_SAIFI,
	PG_SUBREGION_RO_F_SAIDI,
	PG_SUBREGION_RO_F_ASAI,
	PG_SUBREGION_RO_F_ENS,
	PG_SUBREGION_RO_F_AENS,
	PG_SUBREGION_RO_F_MIC,
	PG_SUBREGION_RO_F_MID,
	PG_SUBREGION_RO_C_ACI,
	PG_SUBREGION_RO_C_CID,
	PG_SUBREGION_RO_C_SAIFI,
	PG_SUBREGION_RO_C_SAIDI,
	PG_SUBREGION_RO_C_ASAI,
	PG_SUBREGION_RO_C_ENS,
	PG_SUBREGION_RO_C_AENS,
	PG_SUBREGION_RO_C_MIC,
	PG_SUBREGION_RO_C_MID,
	PG_SUBREGION_RO_A_ACI,
	PG_SUBREGION_RO_A_CID,
	PG_SUBREGION_RO_A_SAIFI,
	PG_SUBREGION_RO_A_SAIDI,
	PG_SUBREGION_RO_A_ASAI,
	PG_SUBREGION_RO_A_ENS,
	PG_SUBREGION_RO_A_AENS,
	PG_SUBREGION_RO_A_MIC,
	PG_SUBREGION_RO_A_MID,
	PG_SUBREGION_EO_RCOEF,
	PG_SUBREGION_EO_LOSSCOST,
	PG_SUBREGION_EO_RELICOST,
	PG_SUBREGION_EO_FUNDCOST,
	PG_SUBREGION_EO_INCOME,
};

struct	_PG_SubRegion_	{
	char	szResID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN_SHORT];
	char	szDesp[MDB_CHARLEN];
	unsigned char	nRegionType;
	float	fTotalGenP;
	float	fTotalGenQ;
	float	fTotalLoadP;
	float	fTotalLoadQ;
	float	fTotalCap;
	float	fTotalReac;
	float	fTotalLossP;
	float	fTotalLossQ;
	float	fGenFactor;
	float	fLoadFatctor;
	double	ro_customernum;
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
	double	ro_c_aci;
	double	ro_c_cid;
	double	ro_c_saifi;
	double	ro_c_saidi;
	double	ro_c_asai;
	double	ro_c_ens;
	double	ro_c_aens;
	double	ro_c_mic;
	double	ro_c_mid;
	double	ro_a_aci;
	double	ro_a_cid;
	double	ro_a_saifi;
	double	ro_a_saidi;
	double	ro_a_asai;
	double	ro_a_ens;
	double	ro_a_aens;
	double	ro_a_mic;
	double	ro_a_mid;
	float	eo_rcoef;
	float	eo_losscost;
	float	eo_relicost;
	float	eo_fundcost;
	float	eo_income;
}	DISALIGN;
typedef	struct	_PG_SubRegion_	tagPGSubRegion;

enum	_PGEnum_Field_SubstationEntity_	{
	PG_SUBSTATIONENTITY_RESOURCEID=0,
	PG_SUBSTATIONENTITY_VOLTAGELEVEL,
	PG_SUBSTATIONENTITY_NAME,
	PG_SUBSTATIONENTITY_HIGHVOLTAGELEVEL,
	PG_SUBSTATIONENTITY_CONNECTIVITYNODE,
	PG_SUBSTATIONENTITY_SUBSTATIONTYPE,
	PG_SUBSTATIONENTITY_COMPONENT,
	PG_SUBSTATIONENTITY_MVACAPACITY,
	PG_SUBSTATIONENTITY_GENP,
	PG_SUBSTATIONENTITY_GENQ,
	PG_SUBSTATIONENTITY_PLANVAMP,
	PG_SUBSTATIONENTITY_LOADP,
	PG_SUBSTATIONENTITY_LOADFACTOR,
	PG_SUBSTATIONENTITY_SHUNTCAP,
	PG_SUBSTATIONENTITY_HEATINGLOAD,
	PG_SUBSTATIONENTITY_REFRIGERATIONLOAD,
	PG_SUBSTATIONENTITY_AUTOFORMTRAN,
	PG_SUBSTATIONENTITY_EQX1,
	PG_SUBSTATIONENTITY_EQX0,
	PG_SUBSTATIONENTITY_BPA_GENBUS,
	PG_SUBSTATIONENTITY_BPA_GENVOLT,
	PG_SUBSTATIONENTITY_TOTALBAY,
	PG_SUBSTATIONENTITY_FREEBAY,
	PG_SUBSTATIONENTITY_TOTALOUTLINE,
	PG_SUBSTATIONENTITY_INUSEOUTLINE,
	PG_SUBSTATIONENTITY_RI_RERR,
	PG_SUBSTATIONENTITY_RI_TREP,
	PG_SUBSTATIONENTITY_RI_RCHK,
	PG_SUBSTATIONENTITY_RI_TCHK,
	PG_SUBSTATIONENTITY_RI_TFLOC,
	PG_SUBSTATIONENTITY_RI_CUSTOMER,
	PG_SUBSTATIONENTITY_RI_LOAD_RERR,
	PG_SUBSTATIONENTITY_RI_LOAD_TREP,
	PG_SUBSTATIONENTITY_RI_LOAD_RCHK,
	PG_SUBSTATIONENTITY_RI_LOAD_TCHK,
	PG_SUBSTATIONENTITY_RI_IDEALFLOCTIME,
	PG_SUBSTATIONENTITY_EI_INVEST,
	PG_SUBSTATIONENTITY_EI_CONSTLOSS,
	PG_SUBSTATIONENTITY_EI_EVALRATIO,

	PG_SUBSTATIONENTITY_RW_TUNING1,
	PG_SUBSTATIONENTITY_RW_TUNING2,
	PG_SUBSTATIONENTITY_RW_DELAY1,
	PG_SUBSTATIONENTITY_RW_DELAY2,
	PG_SUBSTATIONENTITY_RW_PLATE,

	PG_SUBSTATIONENTITY_RE_TUNING1,
	PG_SUBSTATIONENTITY_RE_TUNING2,
	PG_SUBSTATIONENTITY_RE_DELAY1,
	PG_SUBSTATIONENTITY_RE_DELAY2,
	PG_SUBSTATIONENTITY_RE_PLATE,

	PG_SUBSTATIONENTITY_ISLAND,
	PG_SUBSTATIONENTITY_P,
	PG_SUBSTATIONENTITY_Q,
	PG_SUBSTATIONENTITY_V,
	PG_SUBSTATIONENTITY_D,
	PG_SUBSTATIONENTITY_EO_LOSS,
	PG_SUBSTATIONENTITY_SCC,
	PG_SUBSTATIONENTITY_SA_RESULT,
	PG_SUBSTATIONENTITY_SA_ISLAND,
	PG_SUBSTATIONENTITY_SA_FAILURE,
	PG_SUBSTATIONENTITY_SA_OUTAGES,
};

struct	_PG_SubstationEntity_	{
	char	szResID			[MDB_CHARLEN];
	char	szVolt			[MDB_CHARLEN_SHORTER];
	char	szName			[MDB_CHARLEN];
	char	szHighVolt		[MDB_CHARLEN_SHORTER];
	char	szNode			[PGND_CHARLEN];
	unsigned char	nSubstationType;
	char	szComp			[MDB_CHARLEN_SHORT];
	float	fMvaCapacity;
	float	fGenP;
	float	fGenQ;
	float	fPlanV;
	float	fLoadP;
	float	fLoadFactor;
	float	fShuntCap;
	float	fHeatingLoad;
	float	fRefrigerationLoad;
	unsigned char	nAutoFormTran;
	float	fEqX1;
	float	fEqX0;
	char	szBpaGenBus[MDB_CHARLEN_SHORTER];
	float	fBpaGenVolt;
	unsigned char	nTotalBay;
	unsigned char	nFreeBay;
	unsigned char	nTotalOutline;
	unsigned char	nInuseOutline;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_Customer;
	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;
	float	ri_IdealFLocTime;
	float	ei_Invest;
	float	ei_constloss;
	float	ei_evalratio;

	float	fRWTuning1;
	float	fRWTuning2;
	float	fRWDelay1;
	float	fRWDelay2;
	unsigned char	bRWPlate;

	float	fRETuning1;
	float	fRETuning2;
	float	fREDelay1;
	float	fREDelay2;
	unsigned char	bREPlate;

	short	nIsland;
	float	fP;
	float	fQ;
	float	fV;
	float	fD;
	float	eo_loss;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
}	DISALIGN;
typedef	struct	_PG_SubstationEntity_	tagPGSubstationEntity;

enum	_PGEnum_Field_TrunkSegment_	{
	PG_TRUNKSEGMENT_RESOURCEID=0,
	PG_TRUNKSEGMENT_NAME,
	PG_TRUNKSEGMENT_DESCRIPTION,
	PG_TRUNKSEGMENT_ISUBSTATION,
	PG_TRUNKSEGMENT_JSUBSTATION,
	PG_TRUNKSEGMENT_VOLTAGELEVEL,
	PG_TRUNKSEGMENT_CONNECTMODE,
	PG_TRUNKSEGMENT_LINE,
	PG_TRUNKSEGMENT_LINETYPE,
	PG_TRUNKSEGMENT_LINEMODEL,
	PG_TRUNKSEGMENT_AUTOLENGTH,
	PG_TRUNKSEGMENT_LENGTH,
	PG_TRUNKSEGMENT_TOWERNUM,
	PG_TRUNKSEGMENT_ISTATUS,
	PG_TRUNKSEGMENT_ZSTATUS,
	PG_TRUNKSEGMENT_LOADSIDE,
	PG_TRUNKSEGMENT_LINELOADP,
	PG_TRUNKSEGMENT_LINELOADFACTOR,
	PG_TRUNKSEGMENT_LINECAP,
	PG_TRUNKSEGMENT_SERIESCAP,
	PG_TRUNKSEGMENT_HEATINGLOAD,
	PG_TRUNKSEGMENT_REFRIGERATIONLOAD,
	PG_TRUNKSEGMENT_RATECUR,
	PG_TRUNKSEGMENT_RATEMVA,
	PG_TRUNKSEGMENT_UNITR,
	PG_TRUNKSEGMENT_UNITX,
	PG_TRUNKSEGMENT_UNITG,
	PG_TRUNKSEGMENT_UNITB,
	PG_TRUNKSEGMENT_R,
	PG_TRUNKSEGMENT_X,
	PG_TRUNKSEGMENT_G,
	PG_TRUNKSEGMENT_B,
	PG_TRUNKSEGMENT_R0,
	PG_TRUNKSEGMENT_X0,
	PG_TRUNKSEGMENT_B0,
	PG_TRUNKSEGMENT_RI_UNITRERR,
	PG_TRUNKSEGMENT_RI_UNITTREP,
	PG_TRUNKSEGMENT_RI_UNITRCHK,
	PG_TRUNKSEGMENT_RI_UNITTCHK,
	PG_TRUNKSEGMENT_EI_UNITINVEST,
	PG_TRUNKSEGMENT_RI_RERR,
	PG_TRUNKSEGMENT_RI_TREP,
	PG_TRUNKSEGMENT_RI_RCHK,
	PG_TRUNKSEGMENT_RI_TCHK,
	PG_TRUNKSEGMENT_RI_TFLOC,
	PG_TRUNKSEGMENT_RI_RSWITCH,
	PG_TRUNKSEGMENT_RI_TSWITCH,
	PG_TRUNKSEGMENT_RI_TDELAY,
	PG_TRUNKSEGMENT_RI_CUSTOMER,
	PG_TRUNKSEGMENT_RI_LOAD_RERR,
	PG_TRUNKSEGMENT_RI_LOAD_TREP,
	PG_TRUNKSEGMENT_RI_LOAD_RCHK,
	PG_TRUNKSEGMENT_RI_LOAD_TCHK,
	PG_TRUNKSEGMENT_EI_INVEST,
	PG_TRUNKSEGMENT_EI_CONSTLOSS,
	PG_TRUNKSEGMENT_EI_EVALRATIO,
	PG_TRUNKSEGMENT_VD_RSCC1,
	PG_TRUNKSEGMENT_VD_RSCC2,
	PG_TRUNKSEGMENT_VD_RSCC3,
	PG_TRUNKSEGMENT_VD_RSCC4,
	PG_TRUNKSEGMENT_RATUNING,
	PG_TRUNKSEGMENT_RADELAY,
	PG_TRUNKSEGMENT_RAPLATE,
	PG_TRUNKSEGMENT_RUTUNING,
	PG_TRUNKSEGMENT_RUDELAY,
	PG_TRUNKSEGMENT_RUPLATE,

	PG_TRUNKSEGMENT_CONNECTIVITYNODEI,
	PG_TRUNKSEGMENT_CONNECTIVITYNODEJ,
	PG_TRUNKSEGMENT_PI,
	PG_TRUNKSEGMENT_QI,
	PG_TRUNKSEGMENT_AI,
	PG_TRUNKSEGMENT_PZ,
	PG_TRUNKSEGMENT_QZ,
	PG_TRUNKSEGMENT_AZ,
	PG_TRUNKSEGMENT_LOSSP,
	PG_TRUNKSEGMENT_LOSSQ,
	PG_TRUNKSEGMENT_RO_ENS,
	PG_TRUNKSEGMENT_EO_LOSS,
	PG_TRUNKSEGMENT_SA_RESULTI,
	PG_TRUNKSEGMENT_SA_ISLANDI,
	PG_TRUNKSEGMENT_SA_FAILUREI,
	PG_TRUNKSEGMENT_SA_SHIFTNODEI,
	PG_TRUNKSEGMENT_SA_RESULTZ,
	PG_TRUNKSEGMENT_SA_ISLANDZ,
	PG_TRUNKSEGMENT_SA_FAILUREZ,
	PG_TRUNKSEGMENT_SA_SHIFTNODEZ,
	PG_TRUNKSEGMENT_NODEIPTR,
	PG_TRUNKSEGMENT_NODEJPTR,
	PG_TRUNKSEGMENT_DIRECTION,
	PG_TRUNKSEGMENT_OPEN,
};

struct	_PG_TrunkSegment_	{
	char	szResID			[MDB_CHARLEN];
	char	szName			[MDB_CHARLEN];
	char	szDesp			[MDB_CHARLEN];
	char	szSubI			[MDB_CHARLEN];
	char	szSubJ			[MDB_CHARLEN];
	char	szVolt			[MDB_CHARLEN_SHORTER];
	unsigned char	nConMode;
	char	szLine			[MDB_CHARLEN];
	unsigned char	nLineType;
	char	szLineModel		[MDB_CHARLEN_SHORT];
	unsigned char	bAutoLength;
	float	fLength;
	short	nTowerNum;
	unsigned char	iStatus;
	unsigned char	zStatus;
	unsigned char	bLoadSide;
	float	fLoadP;
	float	fLoadFactor;
	float	fLineCap;
	float	fSeriesCap;
	float	fHeatingLoad;
	float	fRefrigerationLoad;
	float	fRatedCur;
	float	fRatedMva;
	float	fUnitR;
	float	fUnitX;
	float	fUnitG;
	float	fUnitB;
	float	fR;
	float	fX;
	float	fG;
	float	fB;
	float	fR0;
	float	fX0;
	float	fB0;

	float	ri_UnitRerr;
	float	ri_UnitTrep;
	float	ri_UnitRchk;
	float	ri_UnitTchk;
	float	ei_UnitInvest;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_RSwitch;
	float	ri_TSwitch;
	float	ri_TDelay;
	float	ri_Customer;
	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;

	//	经济性输入数据
	float	ei_Invest;
	float	ei_constloss;
	float	ei_evalratio;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	//	线路低压低周保护
	float	fRATuning;
	float	fRADelay;
	unsigned char	bRAPlate;
	float	fRUTuning;
	float	fRUDelay;
	unsigned char	bRUPlate;

	char	szNodeI[PGND_CHARLEN];
	char	szNodeJ[PGND_CHARLEN];

	//	输出数据

	float	fPi;
	float	fQi;
	float	fAi;
	float	fPz;
	float	fQz;
	float	fAz;
	float	fLossP;
	float	fLossQ;
	float	ro_ens;
	float	eo_loss;

	unsigned char	sa_ResultI;
	unsigned char	sa_IslandI;
	float	sa_FailureI;
	int		sa_ShiftNodeI;

	unsigned char	sa_ResultZ;
	unsigned char	sa_IslandZ;
	float	sa_FailureZ;
	int		sa_ShiftNodeZ;

	int		nNodeI;
	int		nNodeJ;

	unsigned char	nDirection;
	unsigned char	bOpen;
}	DISALIGN;
typedef	struct	_PG_TrunkSegment_	tagPGTrunkSegment;

enum	_PGEnum_Field_BranchSegment_	{
	PG_BRANCHSEGMENT_RESOURCEID=0,
	PG_BRANCHSEGMENT_NAME,
	PG_BRANCHSEGMENT_TRUNK,
	PG_BRANCHSEGMENT_TOWERID,
	PG_BRANCHSEGMENT_VOLTAGELEVEL,
	PG_BRANCHSEGMENT_LINETYPE,
	PG_BRANCHSEGMENT_LINEMODEL,
	PG_BRANCHSEGMENT_LENGTH,
	PG_BRANCHSEGMENT_STATUS,
	PG_BRANCHSEGMENT_LOADP,
	PG_BRANCHSEGMENT_LOADFACTOR,
	PG_BRANCHSEGMENT_LOADCAP,
	PG_BRANCHSEGMENT_HEATINGLOAD,
	PG_BRANCHSEGMENT_REFRIGERATIONLOAD,
	PG_BRANCHSEGMENT_RATECUR,
	PG_BRANCHSEGMENT_RATEMVA,
	PG_BRANCHSEGMENT_UNITR,
	PG_BRANCHSEGMENT_UNITX,
	PG_BRANCHSEGMENT_UNITG,
	PG_BRANCHSEGMENT_UNITB,
	PG_BRANCHSEGMENT_RI_UNITRERR,
	PG_BRANCHSEGMENT_RI_UNITTREP,
	PG_BRANCHSEGMENT_RI_UNITRCHK,
	PG_BRANCHSEGMENT_RI_UNITTCHK,
	PG_BRANCHSEGMENT_EI_UNITINVEST,
	PG_BRANCHSEGMENT_R,
	PG_BRANCHSEGMENT_X,
	PG_BRANCHSEGMENT_G,
	PG_BRANCHSEGMENT_B,
	PG_BRANCHSEGMENT_R0,
	PG_BRANCHSEGMENT_X0,
	PG_BRANCHSEGMENT_B0,
	PG_BRANCHSEGMENT_RI_RERR,
	PG_BRANCHSEGMENT_RI_TREP,
	PG_BRANCHSEGMENT_RI_RCHK,
	PG_BRANCHSEGMENT_RI_TCHK,
	PG_BRANCHSEGMENT_RI_TFLOC,
	PG_BRANCHSEGMENT_RI_CUSTOMER,
	PG_BRANCHSEGMENT_RI_LOAD_RERR,
	PG_BRANCHSEGMENT_RI_LOAD_TREP,
	PG_BRANCHSEGMENT_RI_LOAD_RCHK,
	PG_BRANCHSEGMENT_RI_LOAD_TCHK,
	PG_BRANCHSEGMENT_EI_INVEST,
	PG_BRANCHSEGMENT_EI_CONSTLOSS,
	PG_BRANCHSEGMENT_EI_EVALRATIO,
	PG_BRANCHSEGMENT_VD_RSCC1,
	PG_BRANCHSEGMENT_VD_RSCC2,
	PG_BRANCHSEGMENT_VD_RSCC3,
	PG_BRANCHSEGMENT_VD_RSCC4,

	PG_BRANCHSEGMENT_BRANCHBREAKING,
	PG_BRANCHSEGMENT_BREAKINGTYPE,
	PG_BRANCHSEGMENT_RI_SW_RERR,
	PG_BRANCHSEGMENT_RI_SW_TREP,
	PG_BRANCHSEGMENT_RI_SW_RCHK,
	PG_BRANCHSEGMENT_RI_SW_TCHK,
	PG_BRANCHSEGMENT_RI_SW_TFLOC,
	PG_BRANCHSEGMENT_P,
	PG_BRANCHSEGMENT_Q,
	PG_BRANCHSEGMENT_A,
	PG_BRANCHSEGMENT_LOSSP,
	PG_BRANCHSEGMENT_LOSSQ,
	PG_BRANCHSEGMENT_RO_ENS,
	PG_BRANCHSEGMENT_EO_LOSS,
	PG_BRANCHSEGMENT_SA_RESULT,
	PG_BRANCHSEGMENT_SA_ISLAND,
	PG_BRANCHSEGMENT_SA_FAILURE,
	PG_BRANCHSEGMENT_SA_SHIFTNODE,
};

struct	_PG_BranchSegment_	{
	char	szResID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szTrunk[MDB_CHARLEN];
	short	nTowerID;
	char	szVolt[MDB_CHARLEN_SHORTER];
	unsigned char	nLineType;
	char	szLineModel[MDB_CHARLEN];
	float	fLength;
	unsigned char	nStatus;
	float	fLoadP;
	float	fLoadFactor;
	float	fLineCap;
	float	fHeatingLoad;
	float	fRefrigerationLoad;
	float	fRatedCur;
	float	fRatedMva;
	float	fUnitR;
	float	fUnitX;
	float	fUnitG;
	float	fUnitB;
	float	ri_UnitRerr;
	float	ri_UnitTrep;
	float	ri_UnitRchk;
	float	ri_UnitTchk;
	float	ei_UnitInvest;
	float	fR;
	float	fX;
	float	fG;
	float	fB;
	float	fR0;
	float	fX0;
	float	fB0;

	//	可靠性输入数据
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_Customer;

	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;

	//	经济性输入数据
	float	ei_Invest;
	float	ei_constloss;
	float	ei_evalratio;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	unsigned char	bBranchBreaking;
	unsigned char	nBreakingType;
	float	ri_sw_rerr;
	float	ri_sw_trep;
	float	ri_sw_rchk;
	float	ri_sw_tchk;
	float	ri_sw_tfloc;

	//	输出数据
	float	fP;
	float	fQ;
	float	fA;
	float	fLossP;
	float	fLossQ;
	float	ro_ens;
	float	eo_loss;

	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	int		sa_ShiftNode;
}	DISALIGN;
typedef	struct	_PG_BranchSegment_	tagPGBranchSegment;

enum	_PGEnum_Field_DistributionSwitch_	{
	PG_DISTRIBUTIONSWITCH_RESOURCEID=0,
	PG_DISTRIBUTIONSWITCH_VOLTAGELEVEL,
	PG_DISTRIBUTIONSWITCH_NAME,
	PG_DISTRIBUTIONSWITCH_CONNECTIVITYNODE,
	PG_DISTRIBUTIONSWITCH_TYPE,
	PG_DISTRIBUTIONSWITCH_MODEL,
	PG_DISTRIBUTIONSWITCH_LOADP,
	PG_DISTRIBUTIONSWITCH_LOADFACTOR,
	PG_DISTRIBUTIONSWITCH_SHUNTCAP,
	PG_DISTRIBUTIONSWITCH_HEATINGLOAD,
	PG_DISTRIBUTIONSWITCH_REFRIGERATIONLOAD,
	PG_DISTRIBUTIONSWITCH_RI_RERR,
	PG_DISTRIBUTIONSWITCH_RI_TREP,
	PG_DISTRIBUTIONSWITCH_RI_RCHK,
	PG_DISTRIBUTIONSWITCH_RI_TCHK,
	PG_DISTRIBUTIONSWITCH_RI_TFLOC,
	PG_DISTRIBUTIONSWITCH_RI_CUSTOMER,
	PG_DISTRIBUTIONSWITCH_RI_LOAD_RERR,
	PG_DISTRIBUTIONSWITCH_RI_LOAD_TREP,
	PG_DISTRIBUTIONSWITCH_RI_LOAD_RCHK,
	PG_DISTRIBUTIONSWITCH_RI_LOAD_TCHK,
	PG_DISTRIBUTIONSWITCH_EI_INVEST,
	PG_DISTRIBUTIONSWITCH_EI_CONSTLOSS,
	PG_DISTRIBUTIONSWITCH_EI_EVALRATIO,
	PG_DISTRIBUTIONSWITCH_VD_RSCC1,
	PG_DISTRIBUTIONSWITCH_VD_RSCC2,
	PG_DISTRIBUTIONSWITCH_VD_RSCC3,
	PG_DISTRIBUTIONSWITCH_VD_RSCC4,

	PG_DISTRIBUTIONSWITCH_ISLAND,
	PG_DISTRIBUTIONSWITCH_V,
	PG_DISTRIBUTIONSWITCH_D,
	PG_DISTRIBUTIONSWITCH_SCC,
	PG_DISTRIBUTIONSWITCH_SA_RESULT,
	PG_DISTRIBUTIONSWITCH_SA_ISLAND,
	PG_DISTRIBUTIONSWITCH_SA_FAILURE,
	PG_DISTRIBUTIONSWITCH_SA_OUTAGES,
	PG_DISTRIBUTIONSWITCH_EO_LOSS,
	PG_DISTRIBUTIONSWITCH_OUTLINENUM,
	PG_DISTRIBUTIONSWITCH_INUSEOUTLINE,
};

struct	_PG_DistributionSwitch_	{
	char	szResID			[MDB_CHARLEN];
	char	szVolt			[MDB_CHARLEN_SHORTER];
	char	szName			[MDB_CHARLEN];
	char	szNode			[PGND_CHARLEN];
	unsigned char	nType;
	char	szModel			[MDB_CHARLEN];
	float	fLoadP;
	float	fLoadFactor;
	float	fShuntCap;
	float	fHeatingLoad;
	float	fRefrigerationLoad;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_Customer;
	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;
	float	ei_Invest;
	float	ei_constloss;
	float	ei_evalratio;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	short	nIsland;
	float	fV;
	float	fD;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
	float	eo_loss;
	unsigned char	nOutLineNum;
	unsigned char	nInuseOutline;
}	DISALIGN;
typedef	struct	_PG_DistributionSwitch_	tagPGDistributionSwitch;

enum	_PGEnum_Field_DistributionLoad_	{
	PG_DISTRIBUTIONLOAD_RESOURCEID=0,
	PG_DISTRIBUTIONLOAD_VOLTAGELEVEL,
	PG_DISTRIBUTIONLOAD_NAME,
	PG_DISTRIBUTIONLOAD_USERID,
	PG_DISTRIBUTIONLOAD_SUBSTATIONENTITY,
	PG_DISTRIBUTIONLOAD_CONNECTIVITYNODE,
	PG_DISTRIBUTIONLOAD_TYPE,
	PG_DISTRIBUTIONLOAD_MODEL,
	PG_DISTRIBUTIONLOAD_RATECAPACITY,
	PG_DISTRIBUTIONLOAD_LOADRATIO,
	PG_DISTRIBUTIONLOAD_LOADP,
	PG_DISTRIBUTIONLOAD_LOADFACTOR,
	PG_DISTRIBUTIONLOAD_SHUNTCAP,
	PG_DISTRIBUTIONLOAD_HEATINGLOAD,
	PG_DISTRIBUTIONLOAD_REFRIGERATIONLOAD,
	PG_DISTRIBUTIONLOAD_RI_RERR,
	PG_DISTRIBUTIONLOAD_RI_TREP,
	PG_DISTRIBUTIONLOAD_RI_RCHK,
	PG_DISTRIBUTIONLOAD_RI_TCHK,
	PG_DISTRIBUTIONLOAD_RI_TFLOC,
	PG_DISTRIBUTIONLOAD_RI_CUSTOMER,
	PG_DISTRIBUTIONLOAD_RI_LOAD_RERR,
	PG_DISTRIBUTIONLOAD_RI_LOAD_TREP,
	PG_DISTRIBUTIONLOAD_RI_LOAD_RCHK,
	PG_DISTRIBUTIONLOAD_RI_LOAD_TCHK,
	PG_DISTRIBUTIONLOAD_EI_INVEST,
	PG_DISTRIBUTIONLOAD_EI_CONSTLOSS,
	PG_DISTRIBUTIONLOAD_EI_EVALRATIO,
	PG_DISTRIBUTIONLOAD_VD_RSCC1,
	PG_DISTRIBUTIONLOAD_VD_RSCC2,
	PG_DISTRIBUTIONLOAD_VD_RSCC3,
	PG_DISTRIBUTIONLOAD_VD_RSCC4,

	PG_DISTRIBUTIONLOAD_ISLAND,
	PG_DISTRIBUTIONLOAD_V,
	PG_DISTRIBUTIONLOAD_D,
	PG_DISTRIBUTIONLOAD_EO_LOSS,
	PG_DISTRIBUTIONLOAD_SCC,
	PG_DISTRIBUTIONLOAD_SA_RESULT,
	PG_DISTRIBUTIONLOAD_SA_ISLAND,
	PG_DISTRIBUTIONLOAD_SA_FAILURE,
	PG_DISTRIBUTIONLOAD_SA_OUTAGES,
};

struct	_PG_DistributionLoad_	{
	char	szResID				[MDB_CHARLEN];
	char	szVolt				[MDB_CHARLEN_SHORTER];
	char	szName				[MDB_CHARLEN];
	char	szUserId			[MDB_CHARLEN];
	char	szSubstationEntity	[MDB_CHARLEN];
	char	szNode				[PGND_CHARLEN];
	unsigned char	nType;
	char	szModel				[MDB_CHARLEN];
	float	fRateCapacity;
	float	fLoadRatio;
	float	fLoadP;
	float	fLoadFactor;
	float	fShuntCap;
	float	fHeatingLoad;
	float	fRefrigerationLoad;

	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_Customer;
	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;
	float	ei_Invest;
	float	ei_constloss;
	float	ei_evalratio;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	short	nIsland;
	float	fV;
	float	fD;
	float	eo_loss;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
}	DISALIGN;
typedef	struct	_PG_DistributionLoad_	tagPGDistributionLoad;

enum	_PGEnum_Field_DistributionBreaker_	{
	PG_DISTRIBUTIONBREAKER_RESOURCEID=0,
	PG_DISTRIBUTIONBREAKER_VOLTAGELEVEL,
	PG_DISTRIBUTIONBREAKER_NAME,
	PG_DISTRIBUTIONBREAKER_SUBSTATIONENTITY,
	PG_DISTRIBUTIONBREAKER_CONNECTIVITYNODEI,
	PG_DISTRIBUTIONBREAKER_CONNECTIVITYNODEZ,
	PG_DISTRIBUTIONBREAKER_MODEL,
	PG_DISTRIBUTIONBREAKER_BREAKERTYPE,
	PG_DISTRIBUTIONBREAKER_CONSTOPEN,
	PG_DISTRIBUTIONBREAKER_STATUS,
	PG_DISTRIBUTIONBREAKER_RI_RERR,
	PG_DISTRIBUTIONBREAKER_RI_TREP,
	PG_DISTRIBUTIONBREAKER_RI_RCHK,
	PG_DISTRIBUTIONBREAKER_RI_TCHK,
	PG_DISTRIBUTIONBREAKER_RI_TFLOC,
	PG_DISTRIBUTIONBREAKER_RI_RSWITCH,
	PG_DISTRIBUTIONBREAKER_RI_TSWITCH,
	PG_DISTRIBUTIONBREAKER_RI_TDELAY,
	PG_DISTRIBUTIONBREAKER_RI_CUSTOMER,
	PG_DISTRIBUTIONBREAKER_RI_LOAD_RERR,
	PG_DISTRIBUTIONBREAKER_RI_LOAD_TREP,
	PG_DISTRIBUTIONBREAKER_RI_LOAD_RCHK,
	PG_DISTRIBUTIONBREAKER_RI_LOAD_TCHK,
	PG_DISTRIBUTIONBREAKER_EI_INVEST,
	PG_DISTRIBUTIONBREAKER_VD_RSCC1,
	PG_DISTRIBUTIONBREAKER_VD_RSCC2,
	PG_DISTRIBUTIONBREAKER_VD_RSCC3,
	PG_DISTRIBUTIONBREAKER_VD_RSCC4,

	PG_DISTRIBUTIONBREAKER_ISLAND,
	PG_DISTRIBUTIONBREAKER_SCC,
	PG_DISTRIBUTIONBREAKER_SA_RESULT,
	PG_DISTRIBUTIONBREAKER_SA_ISLAND,
	PG_DISTRIBUTIONBREAKER_SA_FAILURE,
	PG_DISTRIBUTIONBREAKER_SA_OUTAGES,
	PG_DISTRIBUTIONBREAKER_NODEIPTR,
	PG_DISTRIBUTIONBREAKER_NODEJPTR,
};

struct	_PD_DistributionBreaker_	{
	char	szResID				[MDB_CHARLEN];
	char	szVolt				[MDB_CHARLEN_SHORTER];
	char	szName				[MDB_CHARLEN];
	char	szSubstationEntity	[MDB_CHARLEN];
	char	szNodeI				[PGND_CHARLEN];
	char	szNodeJ				[PGND_CHARLEN];
	char	szModel				[MDB_CHARLEN];
	unsigned char	nBreakerType;
	unsigned char	bNonReliBreaker;
	unsigned char	nStatus;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_RSwitch;
	float	ri_TSwitch;
	float	ri_TDelay;
	float	ri_Customer;
	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;
	float	ei_Invest;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	short	nIsland;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
	int		nNodeI;
	int		nNodeJ;
}	DISALIGN;
typedef	struct	_PD_DistributionBreaker_	tagPGDistributionBreaker;

enum	_PGEnum_Field_DistributionJuncPole_	{
	PG_DISTRIBUTIONDOT_RESOURCEID=0,
	PG_DISTRIBUTIONDOT_VOLTAGELEVEL,
	PG_DISTRIBUTIONDOT_NAME,
	PG_DISTRIBUTIONDOT_SUBSTATIONENTITY,
	PG_DISTRIBUTIONDOT_CONNECTIVITYNODE,
	PG_DISTRIBUTIONDOT_TYPE,
	PG_DISTRIBUTIONDOT_LOADP,
	PG_DISTRIBUTIONDOT_LOADFACTOR,
	PG_DISTRIBUTIONDOT_SHUNTCAP,
	PG_DISTRIBUTIONDOT_HEATINGLOAD,
	PG_DISTRIBUTIONDOT_REFRIGERATIONLOAD,
	PG_DISTRIBUTIONDOT_RI_RERR,
	PG_DISTRIBUTIONDOT_RI_TREP,
	PG_DISTRIBUTIONDOT_RI_RCHK,
	PG_DISTRIBUTIONDOT_RI_TCHK,
	PG_DISTRIBUTIONDOT_RI_TFLOC,
	PG_DISTRIBUTIONDOT_RI_CUSTOMER,
	PG_DISTRIBUTIONDOT_RI_LOAD_RERR,
	PG_DISTRIBUTIONDOT_RI_LOAD_TREP,
	PG_DISTRIBUTIONDOT_RI_LOAD_RCHK,
	PG_DISTRIBUTIONDOT_RI_LOAD_TCHK,
	PG_DISTRIBUTIONDOT_EI_INVEST,
	PG_DISTRIBUTIONDOT_EI_CONSTLOSS,
	PG_DISTRIBUTIONDOT_EI_EVALRATIO,
	PG_DISTRIBUTIONDOT_VD_RSCC1,
	PG_DISTRIBUTIONDOT_VD_RSCC2,
	PG_DISTRIBUTIONDOT_VD_RSCC3,
	PG_DISTRIBUTIONDOT_VD_RSCC4,

	PG_DISTRIBUTIONDOT_ISLAND,
	PG_DISTRIBUTIONDOT_V,
	PG_DISTRIBUTIONDOT_D,
	PG_DISTRIBUTIONDOT_EO_LOSS,
	PG_DISTRIBUTIONDOT_SCC,
	PG_DISTRIBUTIONDOT_SA_RESULT,
	PG_DISTRIBUTIONDOT_SA_ISLAND,
	PG_DISTRIBUTIONDOT_SA_FAILURE,
	PG_DISTRIBUTIONDOT_SA_OUTAGES,
};

struct	_PG_DistributionNode_	{
	char	szResID				[MDB_CHARLEN];
	char	szVolt				[MDB_CHARLEN_SHORTER];
	char	szName				[MDB_CHARLEN];
	char	szSubstationEntity	[MDB_CHARLEN];
	char	szNode				[PGND_CHARLEN];
	unsigned char	nType;
	float	fLoadP;
	float	fLoadFactor;
	float	fShuntCap;
	float	fHeatingLoad;
	float	fRefrigerationLoad;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_Customer;
	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;
	float	ei_Invest;
	float	ei_constloss;
	float	ei_evalratio;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	short	nIsland;
	float	fV;
	float	fD;
	float	eo_loss;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
}	DISALIGN;
typedef	struct	_PG_DistributionNode_	tagPGDistributionDot;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_WindTurbine_	{
	PG_WINDTURBINE_RESOURCEID=0,
	PG_WINDTURBINE_VOLTAGELEVEL,
	PG_WINDTURBINE_NAME,
	PG_WINDTURBINE_SUBSTATIONENTITY,
	PG_WINDTURBINE_CONNECTIVITYNODE,
	PG_WINDTURBINE_RATEDMVA,
	PG_WINDTURBINE_P,
	PG_WINDTURBINE_Q,
	PG_WINDTURBINE_CUTIN_WINDSPEED,
	PG_WINDTURBINE_CUTOUT_WINDSPEED,
	PG_WINDTURBINE_RATE_WINDSPEED,
	PG_WINDTURBINE_RATE_POWER,
	PG_WINDTURBINE_MEAN_WINDSPEED,
	PG_WINDTURBINE_STDDEV_WINDSPEED,
	PG_WINDTURBINE_STATE_NUM,
	PG_WINDTURBINE_VD_RSCC1,
	PG_WINDTURBINE_VD_RSCC2,
	PG_WINDTURBINE_VD_RSCC3,
	PG_WINDTURBINE_VD_RSCC4,
	PG_WINDTURBINE_RI_RERR,	
	PG_WINDTURBINE_RI_TREP,	
	PG_WINDTURBINE_RI_RCHK,	
	PG_WINDTURBINE_RI_TCHK,	
	PG_WINDTURBINE_RI_TFLOC,
	PG_WINDTURBINE_EI_INVEST,

	PG_WINDTURBINE_V,
	PG_WINDTURBINE_D,
	PG_WINDTURBINE_SCC,
	PG_WINDTURBINE_SA_RESULT,
	PG_WINDTURBINE_SA_ISLAND,
	PG_WINDTURBINE_SA_FAILURE,
	PG_WINDTURBINE_SA_OUTAGES,
	PG_WINDTURBINE_OUTPUT_POWER1,
	PG_WINDTURBINE_OUTPUT_POWER2,
	PG_WINDTURBINE_OUTPUT_POWER3,
	PG_WINDTURBINE_OUTPUT_POWER4,
	PG_WINDTURBINE_OUTPUT_POWER5,
	PG_WINDTURBINE_OUTPUT_POWER6,
	PG_WINDTURBINE_OUTPUT_POWER7,
	PG_WINDTURBINE_OUTPUT_POWER8,
	PG_WINDTURBINE_OUTPUT_POWER9,
	PG_WINDTURBINE_OUTPUT_POWER10,
	PG_WINDTURBINE_OUTPUT_POWER11,
	PG_WINDTURBINE_OUTPUT_POWER12,
	PG_WINDTURBINE_STATE_PROB1,
	PG_WINDTURBINE_STATE_PROB2,
	PG_WINDTURBINE_STATE_PROB3,
	PG_WINDTURBINE_STATE_PROB4,
	PG_WINDTURBINE_STATE_PROB5,
	PG_WINDTURBINE_STATE_PROB6,
	PG_WINDTURBINE_STATE_PROB7,
	PG_WINDTURBINE_STATE_PROB8,
	PG_WINDTURBINE_STATE_PROB9,
	PG_WINDTURBINE_STATE_PROB10,
	PG_WINDTURBINE_STATE_PROB11,
	PG_WINDTURBINE_STATE_PROB12,
	PG_WINDTURBINE_ISLAND,
	PG_WINDTURBINE_STATUS,
};

struct	_PG_WindTurbine_	{
	char	szResID				[MDB_CHARLEN];
	char	szVolt				[MDB_CHARLEN_SHORTER];
	char	szName				[MDB_CHARLEN];
	char	szSubstationEntity	[MDB_CHARLEN];
	char	szNode				[PGND_CHARLEN];
	float	fRatedMva;
	float	fP;
	float	fQ;
	float	cutin_windspeed;
	float	cutout_windspeed;
	float	rate_windspeed;
	float	rate_power;
	float	mean_windspeed;
	float	stddev_windspeed;
	unsigned char	state_num;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;

	float	fV;
	float	fD;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
	float	output_power1;
	float	output_power2;
	float	output_power3;
	float	output_power4;
	float	output_power5;
	float	output_power6;
	float	output_power7;
	float	output_power8;
	float	output_power9;
	float	output_power10;
	float	output_power11;
	float	output_power12;
	float	state_prob1;
	float	state_prob2;
	float	state_prob3;
	float	state_prob4;
	float	state_prob5;
	float	state_prob6;
	float	state_prob7;
	float	state_prob8;
	float	state_prob9;
	float	state_prob10;
	float	state_prob11;
	float	state_prob12;
	short	nIsland;
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_PG_WindTurbine_	tagPGWindTurbine;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_PhotoVoltaic_	{
	PG_PHOTOVOLTAIC_RESOURCEID=0,
	PG_PHOTOVOLTAIC_VOLTAGELEVEL,
	PG_PHOTOVOLTAIC_NAME,
	PG_PHOTOVOLTAIC_SUBSTATIONENTITY,
	PG_PHOTOVOLTAIC_CONNECTIVITYNODE,
	PG_PHOTOVOLTAIC_RATEDMVA,
	PG_PHOTOVOLTAIC_P,
	PG_PHOTOVOLTAIC_Q,
	PG_PHOTOVOLTAIC_SOLAR_AREA,
	PG_PHOTOVOLTAIC_LUMI_THRESHOLD,
	PG_PHOTOVOLTAIC_TRANS_RATE,
	PG_PHOTOVOLTAIC_LUMI_MAX1,
	PG_PHOTOVOLTAIC_LUMI_MAX2,
	PG_PHOTOVOLTAIC_LUMI_MAX3,
	PG_PHOTOVOLTAIC_LUMI_MAX4,
	PG_PHOTOVOLTAIC_LUMI_MAX5,
	PG_PHOTOVOLTAIC_LUMI_MAX6,
	PG_PHOTOVOLTAIC_LUMI_MAX7,
	PG_PHOTOVOLTAIC_LUMI_MAX8,
	PG_PHOTOVOLTAIC_LUMI_MAX9,
	PG_PHOTOVOLTAIC_LUMI_MAX10,
	PG_PHOTOVOLTAIC_LUMI_MAX11,
	PG_PHOTOVOLTAIC_LUMI_MAX12,
	PG_PHOTOVOLTAIC_STATE_NUM,
	PG_PHOTOVOLTAIC_VD_RSCC1,
	PG_PHOTOVOLTAIC_VD_RSCC2,
	PG_PHOTOVOLTAIC_VD_RSCC3,
	PG_PHOTOVOLTAIC_VD_RSCC4,
	PG_PHOTOVOLTAIC_RI_RERR,
	PG_PHOTOVOLTAIC_RI_TREP,
	PG_PHOTOVOLTAIC_RI_RCHK,
	PG_PHOTOVOLTAIC_RI_TCHK,
	PG_PHOTOVOLTAIC_RI_TFLOC,
	PG_PHOTOVOLTAIC_EI_INVEST,

	PG_PHOTOVOLTAIC_V,
	PG_PHOTOVOLTAIC_D,
	PG_PHOTOVOLTAIC_SCC,
	PG_PHOTOVOLTAIC_SA_RESULT,
	PG_PHOTOVOLTAIC_SA_ISLAND,
	PG_PHOTOVOLTAIC_SA_FAILURE,
	PG_PHOTOVOLTAIC_SA_OUTAGES,
	PG_PHOTOVOLTAIC_OUTPUT_POWER1,
	PG_PHOTOVOLTAIC_OUTPUT_POWER2,
	PG_PHOTOVOLTAIC_OUTPUT_POWER3,
	PG_PHOTOVOLTAIC_OUTPUT_POWER4,
	PG_PHOTOVOLTAIC_OUTPUT_POWER5,
	PG_PHOTOVOLTAIC_OUTPUT_POWER6,
	PG_PHOTOVOLTAIC_OUTPUT_POWER7,
	PG_PHOTOVOLTAIC_OUTPUT_POWER8,
	PG_PHOTOVOLTAIC_OUTPUT_POWER9,
	PG_PHOTOVOLTAIC_OUTPUT_POWER10,
	PG_PHOTOVOLTAIC_OUTPUT_POWER11,
	PG_PHOTOVOLTAIC_OUTPUT_POWER12,
	PG_PHOTOVOLTAIC_STATE_PROB1,
	PG_PHOTOVOLTAIC_STATE_PROB2,
	PG_PHOTOVOLTAIC_STATE_PROB3,
	PG_PHOTOVOLTAIC_STATE_PROB4,
	PG_PHOTOVOLTAIC_STATE_PROB5,
	PG_PHOTOVOLTAIC_STATE_PROB6,
	PG_PHOTOVOLTAIC_STATE_PROB7,
	PG_PHOTOVOLTAIC_STATE_PROB8,
	PG_PHOTOVOLTAIC_STATE_PROB9,
	PG_PHOTOVOLTAIC_STATE_PROB10,
	PG_PHOTOVOLTAIC_STATE_PROB11,
	PG_PHOTOVOLTAIC_STATE_PROB12,
	PG_PHOTOVOLTAIC_ISLAND,
	PG_PHOTOVOLTAIC_STATUS,
};

struct	_PG_PhotoVoltaic_	{
	char	szResID				[MDB_CHARLEN];
	char	szVolt				[MDB_CHARLEN_SHORTER];
	char	szName				[MDB_CHARLEN];
	char	szSubstationEntity	[MDB_CHARLEN];
	char	szNode				[PGND_CHARLEN];
	float	fRatedMva;
	float	fP;
	float	fQ;
	float	solar_area;
	float	lumi_threshold;
	float	trans_rate;
	float	lumi_max1;
	float	lumi_max2;
	float	lumi_max3;
	float	lumi_max4;
	float	lumi_max5;
	float	lumi_max6;
	float	lumi_max7;
	float	lumi_max8;
	float	lumi_max9;
	float	lumi_max10;
	float	lumi_max11;
	float	lumi_max12;
	unsigned char	state_num;

	//	电压暂降评估输入数据
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;

	float	fV;
	float	fD;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
	float	output_power1;
	float	output_power2;
	float	output_power3;
	float	output_power4;
	float	output_power5;
	float	output_power6;
	float	output_power7;
	float	output_power8;
	float	output_power9;
	float	output_power10;
	float	output_power11;
	float	output_power12;
	float	state_prob1;
	float	state_prob2;
	float	state_prob3;
	float	state_prob4;
	float	state_prob5;
	float	state_prob6;
	float	state_prob7;
	float	state_prob8;
	float	state_prob9;
	float	state_prob10;
	float	state_prob11;
	float	state_prob12;
	short	nIsland;
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_PG_PhotoVoltaic_	tagPGPhotoVoltaic;

enum	_PGEnum_Field_EVStation_	{
	PG_EVSTATION_RESOURCEID=0,
	PG_EVSTATION_VOLTAGELEVEL,
	PG_EVSTATION_NAME,
	PG_EVSTATION_STATIONTYPE,
	PG_EVSTATION_LANDTYPE,
	PG_EVSTATION_SERVICEGROUP,
	PG_EVSTATION_RATEDCAPACITY,
	PG_EVSTATION_RATEDDAILYVISITOR,
	PG_EVSTATION_UNDERCONTROL,
	PG_EVSTATION_CONNECTIVITYNODE,
	PG_EVSTATION_SUBSTATIONENTITY,
	PG_EVSTATION_PILEMODEL,
	PG_EVSTATION_PILENUMBER,
	PG_EVSTATION_BATTERYSTOCK,
	PG_EVSTATION_BATTERYCAPACITY,
	PG_EVSTATION_BATTERYPOWER,
	PG_EVSTATION_CHARGEEFFICIENCY,
	PG_EVSTATION_CHARGEFACTOR,
	PG_EVSTATION_EI_INVEST,
	PG_EVSTATION_EI_AUXINVEST,
	PG_EVSTATION_EI_LANDINVEST,
	PG_EVSTATION_EI_CONSTLOSS,
	PG_EVSTATION_EI_EVALRATIO,
	PG_EVSTATION_LOADP,
	PG_EVSTATION_LOADFACTOR,

	PG_EVSTATION_V,
	PG_EVSTATION_D,
	PG_EVSTATION_EO_LOSS,
	PG_EVSTATION_SCC,
	PG_EVSTATION_SA_RESULT,
	PG_EVSTATION_SA_ISLAND,
	PG_EVSTATION_SA_FAILURE,
	PG_EVSTATION_SA_OUTAGES,
	PG_EVSTATION_MAXCHARGELOAD,
	PG_EVSTATION_AVERAGELOADRATIO,
	PG_EVSTATION_DAILYCHARGENUMVER,
	PG_EVSTATION_DAILYSERVICERATIO,
	PG_EVSTATION_DAILYCHARGEENERGY,
	PG_EVSTATION_DAILYENERGYSUPPLY,
	PG_EVSTATION_RO_ROVERLIMIT,
	PG_EVSTATION_RO_TOVERLIMIT,
	PG_EVSTATION_ISLAND,
};

struct	_PG_EVStation_	{
	char	szResID				[MDB_CHARLEN];
	char	szVolt				[MDB_CHARLEN_SHORTER];
	char	szName				[MDB_CHARLEN];
	unsigned char		nStationType;
	unsigned char		nLandType;
	unsigned char		nServiceGroup;
	float	fRatedCapacity;
	short	nRatedDailyVisitor;
	unsigned char		bUnderControl;
	char	szNode				[PGND_CHARLEN];
	char	szSubstationEntity	[MDB_CHARLEN];
	char	szPileModel			[MDB_CHARLEN];
	short	nPileNumber;
	short	nBatteryStock;
	float	fBatteryCapacity;
	float	fBatteryPower;
	float	fChargeEfficiency;
	float	fChargeFactor;
	float	ei_Invest;
	float	ei_AuxInvest;
	float	ei_LandInvest;
	float	ei_constloss;
	float	ei_evalratio;
	float	fLoadP;
	float	fLoadFactor;

	float	fV;
	float	fD;
	float	eo_loss;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
	float	fMaxChargeLoad;
	float	fAverageLoadRatio;
	short	nDailyChargeNumber;
	float	fDailyServiceRatio;
	float	fDailyChargeEnergy;
	float	fDailyEnergySupply;
	float	ro_rOverLimit;
	float	ro_tOverLimit;
	short	nIsland;
}	DISALIGN;
typedef	struct	_PG_EVStation_	tagPGEVStation;

enum	_PGEnum_Field_LandPlot_	{
	PG_LANDPLOT_RESOURCEID=0,
	PG_LANDPLOT_NAME,
	PG_LANDPLOT_LOCATEX,
	PG_LANDPLOT_LOCATEY,
	PG_LANDPLOT_LANDAREA,
	PG_LANDPLOT_BUILDINGAREA,
	PG_LANDPLOT_LANDINDEX,
	PG_LANDPLOT_LANDTYPE,
	PG_LANDPLOT_SAMERATE,
	PG_LANDPLOT_DENSITY,
	PG_LANDPLOT_DEMAND,
	PG_LANDPLOT_VOLUME,
	PG_LANDPLOT_METATYPE,
	PG_LANDPLOT_LAYER,
	PG_LANDPLOT_COLOR,
	PG_LANDPLOT_DENSITYLOAD,
	PG_LANDPLOT_DISTRIBLOAD,
	PG_LANDPLOT_INCALCULATE,
};
struct	_PG_LandPlot_	{
	char			szResID		[MDB_CHARLEN];
	char			szName		[MDB_CHARLEN];
	double			fLocX;
	double			fLocY;
	double			fLandArea;
	double			fBuildingArea;
	char			szLandIndex	[MDB_CHARLEN_SHORT];
	char			szLandType	[MDB_CHARLEN_SHORT];
	double			fSamerate;
	double			fDensity;
	double			fDemand;
	double			fVolume;
	int				nMetaType;				//	地块的图元类型
	char			szLayer		[MDB_CHARLEN_SHORT];
	int				nColor;				//	地块的图元颜色，这是为了记录图元原有颜色，防止因刷新造成错误
	double			fDensityLoad;
	double			fDistribLoad;
	unsigned char	bInCalculate;
}	DISALIGN;
typedef	struct	_PG_LandPlot_	tagPGLandPlot;

enum	_PGEnum_Field_Pipe_	{
	PG_PIPE_RESOURCEID=0,
	PG_PIPE_NAME,
	PG_PIPE_MODEL,
	PG_PIPE_LENGTH,
	PG_PIPE_EI_UNITINVEST,
	PG_PIPE_BUILDDATE,
	PG_PIPE_REBUILDDATE,
	PG_PIPE_OUTAGEDATE,
	PG_PIPE_RUNTIMESPAN,
	PG_PIPE_PLANCHARACTER,
	PG_PIPE_PROJCHARACTER,
	PG_PIPE_VOLTAGELEVELH,
	PG_PIPE_VOLTAGELEVELM,
	PG_PIPE_VOLTAGELEVELL,
	PG_PIPE_HV2MV,
	PG_PIPE_HV2LV,
	PG_PIPE_MV2LV,
	PG_PIPE_MAXHVCABLENUM,
	PG_PIPE_MAXMVCABLENUM,
	PG_PIPE_MAXLVCABLENUM,
	PG_PIPE_HVCABLE1,
	PG_PIPE_HVCABLE2,
	PG_PIPE_HVCABLE3,
	PG_PIPE_HVCABLE4,
	PG_PIPE_MVCABLE1,
	PG_PIPE_MVCABLE2,
	PG_PIPE_MVCABLE3,
	PG_PIPE_MVCABLE4,
	PG_PIPE_MVCABLE5,
	PG_PIPE_MVCABLE6,
	PG_PIPE_MVCABLE7,
	PG_PIPE_MVCABLE8,
	PG_PIPE_LVCABLE1,
	PG_PIPE_LVCABLE2,
	PG_PIPE_LVCABLE3,
	PG_PIPE_LVCABLE4,
	PG_PIPE_LVCABLE5,
	PG_PIPE_LVCABLE6,
	PG_PIPE_LVCABLE7,
	PG_PIPE_LVCABLE8,
	PG_PIPE_LVCABLE9,
	PG_PIPE_LVCABLE10,
	PG_PIPE_LVCABLE11,
	PG_PIPE_LVCABLE12,
	PG_PIPE_LVCABLE13,
	PG_PIPE_LVCABLE14,
	PG_PIPE_LVCABLE15,
	PG_PIPE_LVCABLE16,
	PG_PIPE_LVCABLE17,
	PG_PIPE_LVCABLE18,
	PG_PIPE_LVCABLE19,
	PG_PIPE_LVCABLE20,
	PG_PIPE_LVCABLE21,
	PG_PIPE_LVCABLE22,
	PG_PIPE_LVCABLE23,
	PG_PIPE_LVCABLE24,
	PG_PIPE_LVCABLE25,
	PG_PIPE_LVCABLE26,
	PG_PIPE_LVCABLE27,
	PG_PIPE_LVCABLE28,
	PG_PIPE_LVCABLE29,
	PG_PIPE_LVCABLE30,
	PG_PIPE_LVCABLE31,
	PG_PIPE_LVCABLE32,
};
struct	_PG_Pipe_	{
	char	szResID				[MDB_CHARLEN];
	char	szName				[MDB_CHARLEN];
	char	szModel				[MDB_CHARLEN];
	float	fLength;
	float	ei_UnitInvest;
	int		nBuildDate;
	int		nRebuildDate;
	int		nOutageDate;
	short	nRunTimeSpan;
	unsigned char	nPlanCharacter;
	unsigned char	nProjCharacter;
	char	szVoltH				[MDB_CHARLEN_SHORTER];
	char	szVoltM				[MDB_CHARLEN_SHORTER];
	char	szVoltL				[MDB_CHARLEN_SHORTER];
	unsigned char	nHV2MV;
	unsigned char	nHV2LV;
	unsigned char	nMV2LV;
	short	nMaxHVCableNum;
	short	nMaxMVCableNum;
	short	nMaxLVCableNum;
	char	szHVCable1			[MDB_CHARLEN];
	char	szHVCable2			[MDB_CHARLEN];
	char	szHVCable3			[MDB_CHARLEN];
	char	szHVCable4			[MDB_CHARLEN];
	char	szMVCable1			[MDB_CHARLEN];
	char	szMVCable2			[MDB_CHARLEN];
	char	szMVCable3			[MDB_CHARLEN];
	char	szMVCable4			[MDB_CHARLEN];
	char	szMVCable5			[MDB_CHARLEN];
	char	szMVCable6			[MDB_CHARLEN];
	char	szMVCable7			[MDB_CHARLEN];
	char	szMVCable8			[MDB_CHARLEN];
	char	szLVCable1			[MDB_CHARLEN];
	char	szLVCable2			[MDB_CHARLEN];
	char	szLVCable3			[MDB_CHARLEN];
	char	szLVCable4			[MDB_CHARLEN];
	char	szLVCable5			[MDB_CHARLEN];
	char	szLVCable6			[MDB_CHARLEN];
	char	szLVCable7			[MDB_CHARLEN];
	char	szLVCable8			[MDB_CHARLEN];
	char	szLVCable9			[MDB_CHARLEN];
	char	szLVCable10			[MDB_CHARLEN];
	char	szLVCable11			[MDB_CHARLEN];
	char	szLVCable12			[MDB_CHARLEN];
	char	szLVCable13			[MDB_CHARLEN];
	char	szLVCable14			[MDB_CHARLEN];
	char	szLVCable15			[MDB_CHARLEN];
	char	szLVCable16			[MDB_CHARLEN];
	char	szLVCable17			[MDB_CHARLEN];
	char	szLVCable18			[MDB_CHARLEN];
	char	szLVCable19			[MDB_CHARLEN];
	char	szLVCable20			[MDB_CHARLEN];
	char	szLVCable21			[MDB_CHARLEN];
	char	szLVCable22			[MDB_CHARLEN];
	char	szLVCable23			[MDB_CHARLEN];
	char	szLVCable24			[MDB_CHARLEN];
	char	szLVCable25			[MDB_CHARLEN];
	char	szLVCable26			[MDB_CHARLEN];
	char	szLVCable27			[MDB_CHARLEN];
	char	szLVCable28			[MDB_CHARLEN];
	char	szLVCable29			[MDB_CHARLEN];
	char	szLVCable30			[MDB_CHARLEN];
	char	szLVCable31			[MDB_CHARLEN];
	char	szLVCable32			[MDB_CHARLEN];
}	DISALIGN;
typedef	struct	_PG_Pipe_	tagPGPipe;

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

enum	_PGEnum_Table_	{
	PG_SYSTEM=0,
	PG_BASEVOLTAGE,
	PG_COMPANY,
	PG_SUBCONTROLAREA,
	PG_SUBSTATION,
	PG_VOLTAGELEVEL,
	PG_BUSBARSECTION,
	PG_LINE,
	PG_ACLINESEGMENT,
	PG_DCLINESEGMENT,
	PG_POWERTRANSFORMER,
	PG_TRANSFORMERWINDING,
	PG_RECTIFIERINVERTER,
	PG_SYNCHRONOUSMACHINE,
	PG_ENERGYCONSUMER,
	PG_SHUNTCOMPENSATOR,
	PG_SERIESCOMPENSATOR,
	PG_BREAKER,
	PG_DISCONNECTOR,
	PG_GROUNDDISCONNECTOR,
	PG_GROUNDTRANSFORMER,

	PG_THERMALENERGYCONSUMER,
	PG_ELECTROCHEMICALENERGYSTORAGE,

	PG_LOADMODEL,
	PG_TAPCHANGER,

	PG_TERMINAL,
	PG_CONNECTIVITYNODE,

	PG_EDGEACLINESEGMENT,
	PG_EDGEDCLINESEGMENT,
	PG_EDGETRANSFORMERWINDING,
	PG_EDGESERIESCOMPENSATOR,
	PG_EDGEBREAKER,
	PG_EDGEDISCONNECTOR,
	PG_TIELINE,

	PG_ISLAND,
	PG_TOPOBUS,
	PG_SCCFMOVE,
	//PG_TOPOVDIP,

	//PG_TOPOGRAPHEDGE,
	//PG_TOPOGRAPHDOT,
	//PG_TOPOGRAPHNEIGHBOR,

	PG_PROTSETTING,
	PG_PROTLINE,
	PG_PROTTRAN,
	PG_PROTBUS,
	PG_PROTGEN,
	PG_PROTCAP,
	PG_PROTREAC,
	PG_PROTMOTOR,
	PG_PROTBREAKER,

	PG_SYSTEMRELIABLE,
	PG_ENERGYCONSUMERRELIABLE,

	PG_SUBREGION,
	PG_SUBSTATIONENTITY,
	PG_TRUNKSEGMENT,
	PG_BRANCHSEGMENT,

	PG_DISTRIBUTIONSWITCH,
	PG_DISTRIBUTIONLOAD,
	PG_DISTRIBUTIONBREAKER,
	PG_DISTRIBUTIONDOT,
	PG_WINDTURBINE,
	PG_PHOTOVOLTAIC,
	PG_EVSTATION,

	PG_CONNLINE,

	PG_LANDPLOT,
	PG_PIPE,
	PG_HYPERLINK,

	PG_DRAWING,
	PG_GRAPHLAYER,
	PG_GRAPHATTR,
	PG_LINEVERTEX,
};

//////////////////////////////////////////////////////////////////////////
//	数据库表相关定义
const	int	g_MDBSizeFactor					=1;

const	int	PG_MaxSystem					=1;
const	int	PG_MaxBaseVoltage				=100;
const	int	PG_MaxCompany					=25;
const	int	PG_MaxSubcontrolArea			=250;
const	int	PG_MaxSubstation				=3600						/g_MDBSizeFactor;
const	int	PG_MaxVoltageLevel				=2*PG_MaxSubstation;
const	int	PG_MaxACLineSegment				=6000						/g_MDBSizeFactor;
const	int	PG_MaxLine						=PG_MaxACLineSegment;
const	int	PG_MaxSynchronousMachine		=2400						/g_MDBSizeFactor;
const	int	PG_MaxEnergyConsumer			=24000						/g_MDBSizeFactor;
const	int	PG_MaxLoadModel					=200						/g_MDBSizeFactor;
const	int	PG_MaxShuntCompensator			=PG_MaxEnergyConsumer/4;
const	int	PG_MaxBreaker					=32000						/g_MDBSizeFactor;
const	int	PG_MaxDisconnector				=48000						/g_MDBSizeFactor;
const	int	PG_MaxGroundDisconnector		=28000						/g_MDBSizeFactor;
const	int	PG_MaxBusbarSection				=PG_MaxVoltageLevel;
const	int	PG_MaxTransformerWinding		=PG_MaxVoltageLevel;;
const	int	PG_MaxPowerTransformer			=3*PG_MaxTransformerWinding/5;
const	int	PG_MaxDCLineSegment				=100;
const	int	PG_MaxRectifierInverter			=2*PG_MaxDCLineSegment;
const	int	PG_MaxSeriesCompensator			=1500;

const	int	PG_MaxGroundTransformer				=1000;
const	int	PG_MaxThermalEnergyConsumer			=PG_MaxEnergyConsumer/10;
const	int	PG_MaxElectroChemicalEnergyStorage	=500;

//const	int	PG_MaxTerminal					=((PG_MaxBusbarSection+2*PG_MaxACLineSegment+2*PG_MaxTransformerWinding+2*PG_MaxBreaker+2*PG_MaxDisconnector+PG_MaxSynchronousMachine+PG_MaxEnergyConsumer+PG_MaxShuntCompensator+2*PG_MaxDCLineSegment+2*PG_MaxRectifierInverter+2*PG_MaxSeriesCompensator)/2);;
//const	int	PG_MaxConnectivityNode			=(3*PG_MaxTerminal/5);
const	int	PG_MaxTerminal					=1;
const	int	PG_MaxConnectivityNode			=(2*(PG_MaxBusbarSection+2*PG_MaxACLineSegment+2*PG_MaxTransformerWinding+2*PG_MaxBreaker+2*PG_MaxDisconnector+PG_MaxSynchronousMachine+PG_MaxEnergyConsumer+PG_MaxShuntCompensator+2*PG_MaxDCLineSegment+2*PG_MaxRectifierInverter+2*PG_MaxSeriesCompensator)/5);
const	int	PG_MaxTapchanger				=250;
const	int	PG_MaxEdgeACLineSegment			=(2*PG_MaxACLineSegment);
const	int	PG_MaxEdgeDCLineSegment			=(2*PG_MaxDCLineSegment);
const	int	PG_MaxEdgeTransformerWinding	=(2*PG_MaxTransformerWinding);
const	int	PG_MaxEdgeSeriesCompensator		=2*PG_MaxSeriesCompensator;
const	int	PG_MaxEdgeBreaker				=(2*PG_MaxBreaker);
const	int	PG_MaxEdgeDisconnector			=(2*PG_MaxDisconnector);
const	int	PG_MaxTieLine					=2500						/g_MDBSizeFactor;

const	int	PG_MaxIsland					=2000						/g_MDBSizeFactor;
const	int	PG_MaxTopoBus					=20000						/g_MDBSizeFactor;

const	int	PG_MaxSccFMove					=100;

const	int	PG_MaxProtSetting				=1;
const	int	PG_MaxProtLine					=PG_MaxACLineSegment;
const	int	PG_MaxProtTran					=PG_MaxPowerTransformer;
const	int	PG_MaxProtBus					=PG_MaxBusbarSection/2;
const	int	PG_MaxProtGen					=PG_MaxSynchronousMachine;
const	int	PG_MaxProtCap					=PG_MaxShuntCompensator;
const	int	PG_MaxProtReac					=PG_MaxShuntCompensator/2;
const	int	PG_MaxProtMotor					=PG_MaxEnergyConsumer/10;
const	int	PG_MaxProtBreaker				=PG_MaxSubstation*2;

const	int	PG_MaxSystemReliable			=15*PG_MaxSystem;
const	int	PG_MaxEnergyConsumerReliable	=2*PG_MaxEnergyConsumer;

const	int	PG_MaxSubRegion					=PG_MaxSubcontrolArea;
const	int	PG_MaxSubstationEntity			=PG_MaxSubstation/20;
const	int	PG_MaxTrunkSegment				=2*PG_MaxACLineSegment/3;
const	int	PG_MaxBranchSegment				=PG_MaxACLineSegment/10;

const	int	PG_MaxDistributionSwitch		=1200						/g_MDBSizeFactor;
const	int	PG_MaxDistributionLoad			=2500						/g_MDBSizeFactor;
const	int	PG_MaxDistributionBreaker		=1600						/g_MDBSizeFactor;
const	int	PG_MaxDistributionDot			=1600						/g_MDBSizeFactor;

const	int	PG_MaxWindTurbine				=500						/g_MDBSizeFactor;
const	int	PG_MaxPhotoVoltaic				=200						/g_MDBSizeFactor;
const	int	PG_MaxEVStation					=200						/g_MDBSizeFactor;
const	int	PG_MaxConnLine					=25000						/g_MDBSizeFactor;
const	int	PG_MaxPipe						=250						/g_MDBSizeFactor;
const	int	PG_MaxLandPlot					=10000						/g_MDBSizeFactor;

const	int	PG_MaxDrawing					=100						/g_MDBSizeFactor;
const	int	PG_MaxGraphLayer				=10*PG_MaxDrawing;
const	int	PG_MaxHyperLinks				=5*PG_MaxDrawing;
const	int	PG_MaxGraphAttr					=250*PG_MaxDrawing;
const	int	PG_MaxLineVertex				=100*PG_MaxDrawing;

//const	int	PGSystem_Offset						=sizeof(int)*MAXMDBTABLENUM;
const	int	PGSystem_Offset							=(sizeof(tagMDBBlockSummy)+sizeof(int)*MAXMDBTABLENUM);
const	int	PGBaseVoltage_Offset					=(PGSystem_Offset						+sizeof(tagPGSystem));
const	int	PGCompany_Offset						=(PGBaseVoltage_Offset					+PG_MaxBaseVoltage					*sizeof(tagPGBaseVoltage));
const	int	PGSubcontrolArea_Offset					=(PGCompany_Offset						+PG_MaxCompany						*sizeof(tagPGCompany));
const	int	PGSubstation_Offset						=(PGSubcontrolArea_Offset				+PG_MaxSubcontrolArea				*sizeof(tagPGSubcontrolArea));
const	int	PGVoltageLevel_Offset					=(PGSubstation_Offset					+PG_MaxSubstation					*sizeof(tagPGSubstation));

const	int	PGBusbarSection_Offset					=(PGVoltageLevel_Offset					+PG_MaxVoltageLevel					*sizeof(tagPGVoltageLevel));
const	int	PGLine_Offset							=(PGBusbarSection_Offset				+PG_MaxBusbarSection				*sizeof(tagPGBusbarSection));
const	int	PGACLineSegment_Offset					=(PGLine_Offset							+PG_MaxLine							*sizeof(tagPGLine));
const	int	PGDCLineSegment_Offset					=(PGACLineSegment_Offset				+PG_MaxACLineSegment				*sizeof(tagPGACLineSegment));
const	int	PGPowerTransformer_Offset				=(PGDCLineSegment_Offset				+PG_MaxDCLineSegment				*sizeof(tagPGDCLineSegment));
const	int	PGTransformerWinding_Offset				=(PGPowerTransformer_Offset				+PG_MaxPowerTransformer				*sizeof(tagPGPowerTransformer));
const	int	PGRectifierInverter_Offset				=(PGTransformerWinding_Offset			+PG_MaxTransformerWinding			*sizeof(tagPGTransformerWinding));
const	int	PGSynchronousMachine_Offset				=(PGRectifierInverter_Offset			+PG_MaxRectifierInverter			*sizeof(tagPGRectifierInverter));
const	int	PGEnergyConsumer_Offset					=(PGSynchronousMachine_Offset			+PG_MaxSynchronousMachine			*sizeof(tagPGSynchronousMachine));
const	int	PGShuntCompensator_Offset				=(PGEnergyConsumer_Offset				+PG_MaxEnergyConsumer				*sizeof(tagPGEnergyConsumer));
const	int	PGSeriesCompensator_Offset				=(PGShuntCompensator_Offset				+PG_MaxShuntCompensator				*sizeof(tagPGShuntCompensator));
const	int	PGBreaker_Offset						=(PGSeriesCompensator_Offset			+PG_MaxSeriesCompensator			*sizeof(tagPGSeriesCompensator));
const	int	PGDisconnector_Offset					=(PGBreaker_Offset						+PG_MaxBreaker						*sizeof(tagPGBreaker));
const	int	PGGroundDisconnector_Offset				=(PGDisconnector_Offset					+PG_MaxDisconnector					*sizeof(tagPGDisconnector));
const	int	PGGroundTransformer_Offset				=(PGGroundDisconnector_Offset			+PG_MaxGroundDisconnector			*sizeof(tagPGGroundDisconnector));

const	int	PGThermalEnergyConsumer_Offset			=(PGGroundTransformer_Offset			+PG_MaxGroundTransformer			*sizeof(tagPGGroundTransformer));
const	int	PGElectroChemicalEnergyStorage_Offset	=(PGThermalEnergyConsumer_Offset		+PG_MaxThermalEnergyConsumer		*sizeof(tagPGThermalEnergyConsumer));
const	int	PGLoadModel_Offset						=(PGElectroChemicalEnergyStorage_Offset	+PG_MaxElectroChemicalEnergyStorage	*sizeof(tagPGElectroChemicalEnergyStorage));
const	int	PGTapChanger_Offset						=(PGLoadModel_Offset					+PG_MaxLoadModel					*sizeof(tagPGLoadModel));

const	int	PGTerminal_Offset						=(PGTapChanger_Offset					+PG_MaxTapchanger					*sizeof(tagPGTapChanger));
const	int	PGConnectivityNode_Offset				=(PGTerminal_Offset						+PG_MaxTerminal						*sizeof(tagPGTerminal));

const	int	PGEdgeACLineSegment_Offset				=(PGConnectivityNode_Offset				+PG_MaxConnectivityNode				*sizeof(tagPGConnectivityNode));
const	int	PGEdgeDCLineSegment_Offset				=(PGEdgeACLineSegment_Offset			+PG_MaxEdgeACLineSegment			*sizeof(tagPGEdgeACLineSegment));
const	int	PGEdgeTransformerWinding_Offset			=(PGEdgeDCLineSegment_Offset			+PG_MaxEdgeDCLineSegment			*sizeof(tagPGEdgeDCLineSegment));
const	int	PGEdgeSeriesCompensator_Offset			=(PGEdgeTransformerWinding_Offset		+PG_MaxEdgeTransformerWinding		*sizeof(tagPGEdgeTransformerWinding));
const	int	PGEdgeBreaker_Offset					=(PGEdgeSeriesCompensator_Offset		+PG_MaxEdgeSeriesCompensator		*sizeof(tagPGEdgeSeriesCompensator));
const	int	PGEdgeDisconnector_Offset				=(PGEdgeBreaker_Offset					+PG_MaxEdgeBreaker					*sizeof(tagPGEdgeBreaker));
const	int	PGTieLine_Offset						=(PGEdgeDisconnector_Offset				+PG_MaxEdgeDisconnector				*sizeof(tagPGEdgeDisconnector));

const	int	PGIsland_Offset							=(PGTieLine_Offset						+PG_MaxTieLine						*sizeof(tagPGTieLine));
const	int	PGTopoBus_Offset						=(PGIsland_Offset						+PG_MaxIsland						*sizeof(tagPGIsland));

const	int	PGSccFMove_Offset						=(PGTopoBus_Offset						+PG_MaxTopoBus						*sizeof(tagPGTopoBus));
const	int	PGProtSetting_Offset					=(PGSccFMove_Offset						+PG_MaxSccFMove						*sizeof(tagPGSccFMove));
const	int	PGProtLine_Offset						=(PGProtSetting_Offset					+PG_MaxProtSetting					*sizeof(tagPGProtSetting));
const	int	PGProtTran_Offset						=(PGProtLine_Offset						+PG_MaxProtLine						*sizeof(tagPGProtLine));
const	int	PGProtBus_Offset						=(PGProtTran_Offset						+PG_MaxProtTran						*sizeof(tagPGProtTran));
const	int	PGProtGen_Offset						=(PGProtBus_Offset						+PG_MaxProtBus						*sizeof(tagPGProtBus));
const	int	PGProtCap_Offset						=(PGProtGen_Offset						+PG_MaxProtGen						*sizeof(tagPGProtGen));
const	int	PGProtReac_Offset						=(PGProtCap_Offset						+PG_MaxProtCap						*sizeof(tagPGProtCap));
const	int	PGProtMotor_Offset						=(PGProtReac_Offset						+PG_MaxProtReac						*sizeof(tagPGProtReac));
const	int	PGProtBreaker_Offset					=(PGProtMotor_Offset					+PG_MaxProtMotor					*sizeof(tagPGProtMotor));

const	int	PGSystemReliable_Offset					=(PGProtBreaker_Offset					+PG_MaxProtBreaker					*sizeof(tagPGProtBreaker));
const	int	PGEnergyConsumerReliable_Offset			=(PGSystemReliable_Offset				+PG_MaxSystemReliable				*sizeof(tagPGSystemReliable));

const	int	PGSubRegion_Offset						=(PGEnergyConsumerReliable_Offset		+PG_MaxEnergyConsumerReliable		*sizeof(tagPGEnergyConsumerReliable));
const	int	PGSubstationEntity_Offset				=(PGSubRegion_Offset					+PG_MaxSubRegion					*sizeof(tagPGSubRegion));
const	int	PGTrunkSegment_Offset					=(PGSubstationEntity_Offset				+PG_MaxSubstationEntity				*sizeof(tagPGSubstationEntity));
const	int	PGBranchSegment_Offset					=(PGTrunkSegment_Offset					+PG_MaxTrunkSegment					*sizeof(tagPGTrunkSegment));
const	int	PGDistributionSwitch_Offset				=(PGBranchSegment_Offset				+PG_MaxBranchSegment				*sizeof(tagPGBranchSegment));
const	int	PGDistributionLoad_Offset				=(PGDistributionSwitch_Offset			+PG_MaxDistributionSwitch			*sizeof(tagPGDistributionSwitch));
const	int	PGDistributionBreaker_Offset			=(PGDistributionLoad_Offset				+PG_MaxDistributionLoad				*sizeof(tagPGDistributionLoad));
const	int	PGDistributionDot_Offset				=(PGDistributionBreaker_Offset			+PG_MaxDistributionBreaker			*sizeof(tagPGDistributionBreaker));
const	int	PGWindTurbine_Offset					=(PGDistributionDot_Offset				+PG_MaxDistributionDot				*sizeof(tagPGDistributionDot));
const	int	PGPhotoVoltaic_Offset					=(PGWindTurbine_Offset					+PG_MaxWindTurbine					*sizeof(tagPGWindTurbine));
const	int	PGEVStation_Offset						=(PGPhotoVoltaic_Offset					+PG_MaxPhotoVoltaic					*sizeof(tagPGPhotoVoltaic));
const	int	PGConnLine_Offset						=(PGEVStation_Offset					+PG_MaxEVStation					*sizeof(tagPGEVStation));
const	int	PGLandPlot_Offset						=(PGConnLine_Offset						+PG_MaxConnLine						*sizeof(tagPGConnLine));
const	int	PGPipe_Offset							=(PGLandPlot_Offset						+PG_MaxLandPlot						*sizeof(tagPGLandPlot));
const	int	PGHyperLinks_Offset						=(PGPipe_Offset							+PG_MaxPipe							*sizeof(tagPGPipe));

const	int	PGDrawing_Offset						=(PGHyperLinks_Offset					+PG_MaxHyperLinks					*sizeof(tagPGHyperLinks));
const	int	PGGraphLayer_Offset						=(PGDrawing_Offset						+PG_MaxDrawing						*sizeof(tagPGDrawing));
const	int	PGGraphAttr_Offset						=(PGGraphLayer_Offset					+PG_MaxGraphLayer					*sizeof(tagPGGraphLayer));
const	int	PGLineVertex_Offset						=(PGGraphAttr_Offset					+PG_MaxGraphAttr					*sizeof(tagPGGraphAttr));

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
