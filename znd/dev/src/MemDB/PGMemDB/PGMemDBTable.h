#pragma once

#include "PGMemDBDefine.h"
#include "PGMemDBField.h"

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
static tagMemDBTable	g_PGTableDictArray[]=
{
	{	PG_SYSTEM,							"System"							,	"", "系统"					, 0	, sizeof(g_PGSystemField)							/sizeof(tagMemDBField)	, sizeof(tagPGSystem)						, 1										, PGSystem_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGSystemField,						},
	{	PG_BASEVOLTAGE,						"BaseVoltage"						,	"", "基准电压"				, 0	, sizeof(g_PGBaseVoltageFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGBaseVoltage)					, PG_MaxBaseVoltage						, PGBaseVoltage_Offset					,	{	1,	PG_BASEVOLTAGE_NAME,						0,												0,											0,								},	g_PGBaseVoltageFieldArray,				},
	{	PG_COMPANY,							"Company"							,	"", "电力公司"				, 0	, sizeof(g_PGCompanyFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGCompany)						, PG_MaxCompany							, PGCompany_Offset						,	{	1,	PG_COMPANY_NAME,							0,												0,											0,								},	g_PGCompanyFieldArray,					},
	{	PG_SUBCONTROLAREA,					"SubControlArea"					,	"", "电力分区"				, 0	, sizeof(g_PGSubControlAreaFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGSubcontrolArea)				, PG_MaxSubcontrolArea					, PGSubcontrolArea_Offset				,	{	1,	PG_SUBCONTROLAREA_NAME,						0,												0,											0,								},	g_PGSubControlAreaFieldArray,			},
	{	PG_SUBSTATION,						"Substation"						,	"", "厂站"					, 0	, sizeof(g_PGSubstationFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGSubstation)					, PG_MaxSubstation						, PGSubstation_Offset					,	{	1,	PG_SUBSTATION_NAME,							0,												0,											0,								},	g_PGSubstationFieldArray,				},
	{	PG_VOLTAGELEVEL,					"VoltageLevel"						,	"", "电压等级"				, 0	, sizeof(g_PGVoltageLevelFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGVoltageLevel)					, PG_MaxVoltageLevel					, PGVoltageLevel_Offset					,	{	2,	PG_VOLTAGELEVEL_SUBSTATION,					PG_VOLTAGELEVEL_NAME,							0,											0,								},	g_PGVoltageLevelFieldArray,				},
	{	PG_BUSBARSECTION,					"BusbarSection"						,	"", "母线"					, 0	, sizeof(g_PGBusbarSectionFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGBusbarSection)				, PG_MaxBusbarSection					, PGBusbarSection_Offset				,	{	3,	PG_BUSBARSECTION_SUBSTATION,				PG_BUSBARSECTION_VOLTAGELEVEL,					PG_BUSBARSECTION_NAME,						0,								},	g_PGBusbarSectionFieldArray,			},
	{	PG_LINE,							"Line"								,	"", "线路"					, 0	, sizeof(g_PGLineFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGLine)							, PG_MaxLine							, PGLine_Offset							,	{	1,	PG_LINE_NAME,								0,												0,											0,								},	g_PGLineFieldArray,						},
	{	PG_ACLINESEGMENT,					"ACLineSegment"						,	"", "交流线路段"			, 0	, sizeof(g_PGACLineSegmentFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGACLineSegment)				, PG_MaxACLineSegment					, PGACLineSegment_Offset				,	{	1,	PG_ACLINESEGMENT_NAME,						0,												0,											0,								},	g_PGACLineSegmentFieldArray,			},
	{	PG_DCLINESEGMENT,					"DCLineSegment"						,	"", "直流线路段"			, 0	, sizeof(g_PGDCLineSegmentFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDCLineSegment)				, PG_MaxDCLineSegment					, PGDCLineSegment_Offset				,	{	1,	PG_DCLINESEGMENT_NAME,						0,												0,											0,								},	g_PGDCLineSegmentFieldArray,			},
	{	PG_POWERTRANSFORMER,				"PowerTransformer"					,	"", "变压器"				, 0	, sizeof(g_PGPowerTransformerFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGPowerTransformer)				, PG_MaxPowerTransformer				, PGPowerTransformer_Offset				,	{	2,	PG_POWERTRANSFORMER_SUBSTATION,				PG_POWERTRANSFORMER_NAME,						0,											0,								},	g_PGPowerTransformerFieldArray,			},
	{	PG_TRANSFORMERWINDING,				"TransformerWinding"				,	"", "变压器绕组"			, 0	, sizeof(g_PGTransformerWindingFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGTransformerWinding)			, PG_MaxTransformerWinding				, PGTransformerWinding_Offset			,	{	2,	PG_TRANSFORMERWINDING_SUBSTATION,			PG_TRANSFORMERWINDING_NAME,						0,											0,								},	g_PGTransformerWindingFieldArray,		},
	{	PG_SYNCHRONOUSMACHINE,				"SynchronousMachine"				,	"", "发电机"				, 0	, sizeof(g_PGSynchronousMachineFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSynchronousMachine)			, PG_MaxSynchronousMachine				, PGSynchronousMachine_Offset			,	{	3,	PG_SYNCHRONOUSMACHINE_SUBSTATION,			PG_SYNCHRONOUSMACHINE_VOLTAGELEVEL,				PG_SYNCHRONOUSMACHINE_NAME,					0,								},	g_PGSynchronousMachineFieldArray,		},
	{	PG_ENERGYCONSUMER,					"EnergyConsumer"					,	"", "负荷"					, 0	, sizeof(g_PGEnergyConsumerFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEnergyConsumer)				, PG_MaxEnergyConsumer					, PGEnergyConsumer_Offset				,	{	3,	PG_ENERGYCONSUMER_SUBSTATION,				PG_ENERGYCONSUMER_VOLTAGELEVEL,					PG_ENERGYCONSUMER_NAME,						0,								},	g_PGEnergyConsumerFieldArray,			},
	{	PG_SHUNTCOMPENSATOR,				"ShuntCompensator"					,	"", "并联补偿"				, 0	, sizeof(g_PGShuntCompensatorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGShuntCompensator)				, PG_MaxShuntCompensator				, PGShuntCompensator_Offset				,	{	3,	PG_SHUNTCOMPENSATOR_SUBSTATION,				PG_SHUNTCOMPENSATOR_VOLTAGELEVEL,				PG_SHUNTCOMPENSATOR_NAME,					0,								},	g_PGShuntCompensatorFieldArray,			},
	{	PG_SERIESCOMPENSATOR,				"SeriesCompensator"					,	"", "串联补偿"				, 0	, sizeof(g_PGSeriesCompensatorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSeriesCompensator)			, PG_MaxSeriesCompensator				, PGSeriesCompensator_Offset			,	{	3,	PG_SERIESCOMPENSATOR_SUBSTATION,			PG_SERIESCOMPENSATOR_VOLTAGELEVEL,				PG_SERIESCOMPENSATOR_NAME,					0,								},	g_PGSeriesCompensatorFieldArray,		},
	{	PG_BREAKER,							"Breaker"							,	"", "断路器"				, 0	, sizeof(g_PGBreakerFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGBreaker)						, PG_MaxBreaker							, PGBreaker_Offset						,	{	3,	PG_BREAKER_SUBSTATION,						PG_BREAKER_VOLTAGELEVEL,						PG_BREAKER_NAME,							0,								},	g_PGBreakerFieldArray,					},
	{	PG_DISCONNECTOR,					"Disconnector"						,	"", "隔离开关"				, 0	, sizeof(g_PGDisconnectorFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDisconnector)					, PG_MaxDisconnector					, PGDisconnector_Offset					,	{	3,	PG_DISCONNECTOR_SUBSTATION,					PG_DISCONNECTOR_VOLTAGELEVEL,					PG_DISCONNECTOR_NAME,						0,								},	g_PGDisconnectorFieldArray,				},
	{	PG_GROUNDDISCONNECTOR,				"GroundDisconnector"				,	"", "接地刀闸"				, 0	, sizeof(g_PGGroundDisconnectorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGGroundDisconnector)			, PG_MaxGroundDisconnector				, PGGroundDisconnector_Offset			,	{	3,	PG_GROUNDDISCONNECTOR_SUBSTATION,			PG_GROUNDDISCONNECTOR_VOLTAGELEVEL,				PG_GROUNDDISCONNECTOR_NAME,					0,								},	g_PGGroundDisconnectorFieldArray,		},
	{	PG_RECTIFIERINVERTER,				"RectifierInverter"					,	"", "整流逆变器"			, 0	, sizeof(g_PGRectifierInverterFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGRectifierInverter)			, PG_MaxRectifierInverter				, PGRectifierInverter_Offset			,	{	2,	PG_RECTIFIERINVERTER_SUBSTATION,			PG_RECTIFIERINVERTER_NAME,						0,											0,								},	g_PGRectifierInverterFieldArray,		},
	{	PG_GROUNDTRANSFORMER,				"GroundTransformer"					,	"", "接地变"				, 0	, sizeof(g_PGGroundTransformerFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGGroundTransformer)			, PG_MaxGroundTransformer				, PGGroundTransformer_Offset			,	{	3,	PG_GROUNDTRANSFORMER_SUBSTATION,			PG_GROUNDTRANSFORMER_VOLTAGELEVEL,				PG_GROUNDTRANSFORMER_NAME,					0,								},	g_PGGroundTransformerFieldArray,		},
	{	PG_WINDTURBINE,						"WindTurbine"						,	"", "风电(场)"				, 0	, sizeof(g_PGWindTurbineFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGWindTurbine)					, PG_MaxWindTurbine						, PGWindTurbine_Offset					,	{	1,	PG_WINDTURBINE_RESOURCEID,					0,												0,											0,								},	g_PGWindTurbineFieldArray,				},
	{	PG_PHOTOVOLTAIC,					"PhotoVoltaic"						,	"", "光伏(站)"				, 0	, sizeof(g_PGPhotoVoltaicFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGPhotoVoltaic)					, PG_MaxPhotoVoltaic					, PGPhotoVoltaic_Offset					,	{	1,	PG_PHOTOVOLTAIC_RESOURCEID,					0,												0,											0,								},	g_PGPhotoVoltaicFieldArray,				},
	{	PG_EVSTATION,						"EVStation"							,	"", "电动汽车充(换)电站"	, 0	, sizeof(g_PGEVStationFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGEVStation)					, PG_MaxEVStation						, PGEVStation_Offset					,	{	1,	PG_EVSTATION_RESOURCEID,					0,												0,											0,								},	g_PGEVStationFieldArray,				},
	{	PG_ELECTROCHEMICALENERGYSTORAGE,	"ElectroChemicalEnergyStorage"		,	"", "电化学储能"			, 0	, sizeof(g_PGElectroChemicalEnergyStorageFieldArray)/sizeof(tagMemDBField)	, sizeof(tagPGElectroChemicalEnergyStorage)	, PG_MaxElectroChemicalEnergyStorage	, PGElectroChemicalEnergyStorage_Offset	,	{	1,	PG_ELECTROCHEMICALENERGYSTORAGE_RESOURCEID,	0,												0,											0,								},	g_PGElectroChemicalEnergyStorageFieldArray,},
	{	PG_SOLARTHERMALMACHINE,				"SolarThermalMachine"				,	"", "光热发电"				, 0	, sizeof(g_PGSolarThermalMachineFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSolarThermalMachine)			, PG_MaxSolarThermalMachine				, PGSolarThermalMachine_Offset			,	{	1,	PG_SOLARTHERMALMACHINE_RESOURCEID,			0,												0,											0,								},	g_PGSolarThermalMachineFieldArray,		},

	{	PG_SUBSTATIONENTITY,				"SubstationEntity"					,	"", "厂站实体"				, 0	, sizeof(g_PGSubstationEntityFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSubstationEntity)				, PG_MaxSubstationEntity				, PGSubstationEntity_Offset				,	{	1,	PG_SUBSTATIONENTITY_NAME,					PG_SUBSTATIONENTITY_RESOURCEID,					0,											0,								},	g_PGSubstationEntityFieldArray,			},
	{	PG_BRANCHSEGMENT,					"BranchSegment"						,	"", "分支线"				, 0	, sizeof(g_PGBranchSegmentFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGBranchSegment)				, PG_MaxBranchSegment					, PGBranchSegment_Offset				,	{	1,	PG_BRANCHSEGMENT_RESOURCEID,				0,												0,											0,								},	g_PGBranchSegmentFieldArray,			},
	{	PG_DISTRIBUTIONSWITCH,				"DistributionSwitch"				,	"", "配电单元"				, 0	, sizeof(g_PGDistributionSwitchFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDistributionSwitch)			, PG_MaxDistributionSwitch				, PGDistributionSwitch_Offset			,	{	1,	PG_DISTRIBUTIONSWITCH_RESOURCEID,			0,												0,											0,								},	g_PGDistributionSwitchFieldArray,		},
	{	PG_DISTRIBUTIONLOAD,				"DistributionLoad"					,	"", "配电负荷"				, 0	, sizeof(g_PGDistributionLoadFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDistributionLoad)				, PG_MaxDistributionLoad				, PGDistributionLoad_Offset				,	{	1,	PG_DISTRIBUTIONLOAD_RESOURCEID,				0,												0,											0,								},	g_PGDistributionLoadFieldArray,			},
	{	PG_DISTRIBUTIONBREAKER,				"DistributionBreaker"				,	"", "配电开关"				, 0	, sizeof(g_PGDistributionBreakerFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDistributionBreaker)			, PG_MaxDistributionBreaker				, PGDistributionBreaker_Offset			,	{	1,	PG_DISTRIBUTIONBREAKER_RESOURCEID,			0,												0,											0,								},	g_PGDistributionBreakerFieldArray,		},
	{	PG_DISTRIBUTIONDOT,					"DistributionJuncPole"				,	"", "配电节点"				, 0	, sizeof(g_PGDistributionDotFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDistributionDot)				, PG_MaxDistributionDot					, PGDistributionDot_Offset				,	{	1,	PG_DISTRIBUTIONDOT_RESOURCEID,				0,												0,											0,								},	g_PGDistributionDotFieldArray,			},

	{	PG_ELECTRONICTRANSFORMER,			"ElectronicTransformer"				,	"", "电力电子变压器"		, 0	, sizeof(g_PGElectronicTransformerFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGElectronicTransformer)		, PG_MaxElectronicTransformer			, PGElectronicTransformer_Offset		,	{	2,	PG_ELECTRONICTRANSFORMER_SUBSTATION,		PG_ELECTRONICTRANSFORMER_NAME,					0,											0,								},	g_PGElectronicTransformerFieldArray,	},
	{	PG_DCBUSBARSECTION,					"DCBusbarSection"					,	"", "直流母线"				, 0	, sizeof(g_PGDCBusbarSectionFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDCBusbarSection)				, PG_MaxDCBusbarSection					, PGDCBusbarSection_Offset				,	{	3,	PG_DCBUSBARSECTION_SUBSTATION,				PG_DCBUSBARSECTION_VOLTAGELEVEL,				PG_DCBUSBARSECTION_NAME,					0,								},	g_PGDCBusbarSectionFieldArray,			},
	{	PG_ACDCCONVERTER,					"ACDCConverter"						,	"", "交流直流变换器"		, 0	, sizeof(g_PGACDCConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGACDCConverter)				, PG_MaxACDCConverter					, PGACDCConverter_Offset				,	{	2,	PG_ACDCCONVERTER_SUBSTATION,				PG_ACDCCONVERTER_NAME,							0,											0,								},	g_PGACDCConverterFieldArray,			},
	{	PG_DCDCCONVERTER,					"DCDCConverter"						,	"", "直流直流变换器"		, 0	, sizeof(g_PGDCDCConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDCDCConverter)				, PG_MaxDCDCConverter					, PGDCDCConverter_Offset				,	{	2,	PG_DCDCCONVERTER_SUBSTATION,				PG_DCDCCONVERTER_NAME,							0,											0,								},	g_PGDCDCConverterFieldArray,			},
	{	PG_DCBREAKER,						"DCBreaker"							,	"", "直流断路器"			, 0	, sizeof(g_PGDCBreakerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGDCBreaker)					, PG_MaxDCBreaker						, PGDCBreaker_Offset					,	{	3,	PG_DCBREAKER_SUBSTATION,					PG_DCBREAKER_VOLTAGELEVEL,						PG_DCBREAKER_NAME,							0,								},	g_PGDCBreakerFieldArray,				},
	{	PG_DCSHORTCIRCUITLIMIT,				"DCShortCircuitLimit"				,	"", "直流短路电流限制器"	, 0	, sizeof(g_PGDCShortCircuitLimitFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDCShortCircuitLimit)			, PG_MaxDCShortCircuitLimit				, PGDCShortCircuitLimit_Offset			,	{	3,	PG_DCSHORTCIRCUITLIMIT_SUBSTATION,			PG_DCSHORTCIRCUITLIMIT_VOLTAGELEVEL,			PG_DCSHORTCIRCUITLIMIT_NAME,				0,								},	g_PGDCShortCircuitLimitFieldArray,		},
	{	PG_THERMALENERGYCONSUMER,			"ThermalEnergyConsumer"				,	"", "冷热负荷"				, 0	, sizeof(g_PGThermalEnergyConsumerFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGThermalEnergyConsumer)		, PG_MaxThermalEnergyConsumer			, PGThermalEnergyConsumer_Offset		,	{	3,	PG_THERMALENERGYCONSUMER_SUBSTATION,		PG_THERMALENERGYCONSUMER_VOLTAGELEVEL,			PG_THERMALENERGYCONSUMER_NAME,				0,								},	g_PGThermalEnergyConsumerFieldArray,	},
	{	PG_LOADMODEL,						"LoadModel"							,	"", "负荷模型"				, 0	, sizeof(g_PGLoadModelFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGLoadModel)					, PG_MaxLoadModel						, PGLoadModel_Offset					,	{	1,	PG_LOADMODEL_NAME,							0,												0,											0,								},	g_PGLoadModelFieldArray,				},
	{	PG_TAPCHANGER,						"TapChanger"						,	"", "分接头"				, 0	, sizeof(g_PGTapChangerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGTapChanger)					, PG_MaxTapchanger						, PGTapChanger_Offset					,	{	1,	PG_TAPCHANGER_NAME,							0,												0,											0,								},	g_PGTapChangerFieldArray,				},
	{	PG_TERMINAL,						"Terminal"							,	"", "端点"					, 0	, sizeof(g_PGTerminalFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGTerminal)						, PG_MaxTerminal						, PGTerminal_Offset						,	{	3,	PG_TERMINAL_SUBSTATION,						PG_TERMINAL_VOLTAGELEVEL,						PG_TERMINAL_NAME,							0,								},	g_PGTerminalFieldArray,					},
	{	PG_CONNECTIVITYNODE,				"ConnectivityNode"					,	"", "节点"					, 0	, sizeof(g_PGConnectivityNodeFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGConnectivityNode)				, PG_MaxConnectivityNode				, PGConnectivityNode_Offset				,	{	3,	PG_CONNECTIVITYNODE_SUBSTATION,				PG_CONNECTIVITYNODE_VOLTAGELEVEL,				PG_CONNECTIVITYNODE_NAME,					0,								},	g_PGConnectivityNodeFieldArray,			},
	{	PG_EDGEACLINESEGMENT,				"EdgeACLineSegment"					,	"", "交流线路边"			, 0	, sizeof(g_PGEdgeACLineSegmentFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGEdgeACLineSegment)			, PG_MaxEdgeACLineSegment				, PGEdgeACLineSegment_Offset			,	{	4,	PG_EDGEACLINESEGMENT_SUBSTATION,			PG_EDGEACLINESEGMENT_VOLTAGELEVEL,				PG_EDGEACLINESEGMENT_CONNECTIVITYNODE,		PG_EDGEACLINESEGMENT_NAME,		},	g_PGEdgeACLineSegmentFieldArray,		},
	{	PG_EDGEDCLINESEGMENT,				"EdgeDCLineSegment"					,	"", "直流线路边"			, 0	, sizeof(g_PGEdgeDCLineSegmentFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDCLineSegment)			, PG_MaxEdgeDCLineSegment				, PGEdgeDCLineSegment_Offset			,	{	4,	PG_EDGEDCLINESEGMENT_SUBSTATION,			PG_EDGEDCLINESEGMENT_VOLTAGELEVEL,				PG_EDGEDCLINESEGMENT_CONNECTIVITYNODE,		PG_EDGEDCLINESEGMENT_NAME,		},	g_PGEdgeDCLineSegmentFieldArray,		},
	{	PG_EDGETRANSFORMERWINDING,			"EdgeTransformerWinding"			,	"", "变压器边"				, 0	, sizeof(g_PGEdgeTransformerWindingFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEdgeTransformerWinding)		, PG_MaxEdgeTransformerWinding			, PGEdgeTransformerWinding_Offset		,	{	4,	PG_EDGETRANSFORMERWINDING_SUBSTATION,		PG_EDGETRANSFORMERWINDING_VOLTAGELEVEL, 		PG_EDGETRANSFORMERWINDING_CONNECTIVITYNODE, PG_EDGETRANSFORMERWINDING_NAME, },	g_PGEdgeTransformerWindingFieldArray,	},
	{	PG_EDGESERIESCOMPENSATOR,			"EdgeSeriesCompensator"				,	"", "串联补偿边"			, 0	, sizeof(g_PGEdgeSeriesCompensatorFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEdgeSeriesCompensator)		, PG_MaxEdgeSeriesCompensator			, PGEdgeSeriesCompensator_Offset		,	{	4,	PG_EDGESERIESCOMPENSATOR_SUBSTATION,		PG_EDGESERIESCOMPENSATOR_VOLTAGELEVEL,			PG_EDGESERIESCOMPENSATOR_CONNECTIVITYNODE,	PG_EDGESERIESCOMPENSATOR_NAME,	},	g_PGEdgeSeriesCompensatorFieldArray,	},
	{	PG_EDGEBREAKER,						"EdgeBreaker"						,	"", "断路器边"				, 0	, sizeof(g_PGEdgeBreakerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGEdgeBreaker)					, PG_MaxEdgeBreaker						, PGEdgeBreaker_Offset					,	{	4,	PG_EDGEBREAKER_SUBSTATION,					PG_EDGEBREAKER_VOLTAGELEVEL,					PG_EDGEBREAKER_CONNECTIVITYNODE,			PG_EDGEBREAKER_NAME,			},	g_PGEdgeBreakerFieldArray,				},
	{	PG_EDGEDISCONNECTOR,				"EdgeDisconnector"					,	"", "隔离开关边"			, 0	, sizeof(g_PGEdgeDisconnectorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDisconnector)				, PG_MaxEdgeDisconnector				, PGEdgeDisconnector_Offset				,	{	4,	PG_EDGEDISCONNECTOR_SUBSTATION,				PG_EDGEDISCONNECTOR_VOLTAGELEVEL,				PG_EDGEDISCONNECTOR_CONNECTIVITYNODE,		PG_EDGEDISCONNECTOR_NAME,		},	g_PGEdgeDisconnectorFieldArray,			},
	{	PG_EDGEADCONVERTER,					"EdgeADConverter"					,	"", "交直变换器边"			, 0	, sizeof(g_PGEdgeADConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEdgeADConverter)				, PG_MaxEdgeADConverter					, PGEdgeADConverter_Offset				,	{	4,	PG_EDGEADCONVERTER_SUBSTATION,				PG_EDGEADCONVERTER_VOLTAGELEVEL,				PG_EDGEADCONVERTER_CONNECTIVITYNODE,		PG_EDGEADCONVERTER_NAME,		},	g_PGEdgeADConverterFieldArray,			},
	{	PG_EDGEDDCONVERTER,					"EdgeDDConverter"					,	"", "直直变换器边"			, 0	, sizeof(g_PGEdgeDDConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDDConverter)				, PG_MaxEdgeDDConverter					, PGEdgeDDConverter_Offset				,	{	4,	PG_EDGEDDCONVERTER_SUBSTATION,				PG_EDGEDDCONVERTER_VOLTAGELEVEL,				PG_EDGEDDCONVERTER_CONNECTIVITYNODE,		PG_EDGEDDCONVERTER_NAME,		},	g_PGEdgeDDConverterFieldArray,			},
	{	PG_EDGEDCBREAKER,					"EdgeDCBreaker"						,	"", "直流断路器边"			, 0	, sizeof(g_PGEdgeDCBreakerFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDCBreaker)				, PG_MaxEdgeDCBreaker					, PGEdgeDCBreaker_Offset				,	{	4,	PG_EDGEDCBREAKER_SUBSTATION,				PG_EDGEDCBREAKER_VOLTAGELEVEL,					PG_EDGEDCBREAKER_CONNECTIVITYNODE,			PG_EDGEDCBREAKER_NAME,			},	g_PGEdgeDCBreakerFieldArray,			},
	{	PG_EDGEDCSHORTCIRCUITLIMIT,			"EdgeDCShortCircuitLimit"			,	"", "直流短路电流限制器边"	, 0	, sizeof(g_PGEdgeDCShortCircuitLimitFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDCShortCircuitLimit)		, PG_MaxEdgeDCShortCircuitLimit			, PGEdgeDCShortCircuitLimit_Offset		,	{	4,	PG_EDGEDCSHORTCIRCUITLIMIT_SUBSTATION,		PG_EDGEDCSHORTCIRCUITLIMIT_VOLTAGELEVEL,		PG_EDGEDCSHORTCIRCUITLIMIT_CONNECTIVITYNODE,PG_EDGEDCSHORTCIRCUITLIMIT_NAME,},	g_PGEdgeDCShortCircuitLimitFieldArray,	},

	{	PG_TIELINE,							"Tieline"							,	"", "联络线"				, 0	, sizeof(g_PGTielineFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGTieLine)						, PG_MaxTieLine							, PGTieLine_Offset						,	{	1,	PG_TIELINE_NAME,							0,												0,											0,								},	g_PGTielineFieldArray,					},

	{	PG_ISLAND,							"Island"							,	"", "岛"					, 0	, sizeof(g_PGIslandFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGIsland)						, PG_MaxIsland							, PGIsland_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGIslandFieldArray,					},
	{	PG_TOPOBUS,							"TopoBus"							,	"", "计算节点"				, 0	, sizeof(g_PGTopoBusFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGTopoBus)						, PG_MaxTopoBus							, PGTopoBus_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGTopoBusFieldArray					},

#ifdef PGProtSettingDefine
	{	PG_PROTSETTING,						"ProtSetting"						,	"", "保护设置"				, 0	, sizeof(g_PGProtSettingFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtSetting)					, PG_MaxProtSetting						, PGProtSetting_Offset					,	{	0,	0,											0,												0,											0,								},	g_PGProtSettingFieldArray				},
	{	PG_PROTLINE,						"ProtLine"							,	"", "线路保护"				, 0	, sizeof(g_PGProtLineFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtLine)						, PG_MaxProtLine						, PGProtLine_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtLineFieldArray					},
	{	PG_PROTTRAN,						"ProtTran"							,	"", "变压器保护"			, 0	, sizeof(g_PGProtTranFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtTran)						, PG_MaxProtTran						, PGProtTran_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtTranFieldArray					},
	{	PG_PROTBUS,							"ProtBus"							,	"", "母线保护"				, 0	, sizeof(g_PGProtBusFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGProtBus)						, PG_MaxProtBus							, PGProtBus_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtBusFieldArray					},
	{	PG_PROTGEN,							"ProtGen"							,	"", "发电机保护"			, 0	, sizeof(g_PGProtGenFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGProtGen)						, PG_MaxProtGen							, PGProtGen_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtGenFieldArray					},
	{	PG_PROTCAP,							"ProtCap"							,	"", "并联电容器保护"		, 0	, sizeof(g_PGProtCapFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGProtCap)						, PG_MaxProtCap							, PGProtCap_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtCapFieldArray					},
	{	PG_PROTREAC,						"ProtReac"							,	"", "并联电抗器保护"		, 0	, sizeof(g_PGProtReacFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtReac)						, PG_MaxProtReac						, PGProtReac_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtReacFieldArray					},
	{	PG_PROTMOTOR,						"ProtMotor"							,	"", "电动机保护"			, 0	, sizeof(g_PGProtMotorFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtMotor)					, PG_MaxProtMotor						, PGProtMotor_Offset					,	{	0,	0,											0,												0,											0,								},	g_PGProtMotorFieldArray					},
	{	PG_PROTBREAKER,						"ProtBreaker"						,	"", "母联(分段)断路器保护"	, 0	, sizeof(g_PGProtBreakerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtBreaker)					, PG_MaxProtBreaker						, PGProtBreaker_Offset					,	{	0,	0,											0,												0,											0,								},	g_PGProtBreakerFieldArray				},
#endif

	{	PG_SYSTEMRELIABLE,					"SystemReliable"					,	"", "系统可靠性结果"		, 0	, sizeof(g_PGSystemReliableField)					/sizeof(tagMemDBField)	, sizeof(tagPGSystemReliable)				, PG_MaxSystemReliable					, PGSystemReliable_Offset				,	{	1,	PG_SYSTEMRELIABLE_STEP,						0,												0,											0,								},	g_PGSystemReliableField,				},
	{	PG_ENERGYCONSUMERRELIABLE,			"EnergyConsumerReliable"			,	"", "负荷可靠性结果"		, 0	, sizeof(g_PGEnergyConsumerReliableFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEnergyConsumerReliable)		, PG_MaxEnergyConsumerReliable			, PGEnergyConsumerReliable_Offset		,	{	2,	PG_ENERGYCONSUMERRELIABLE_LOAD,				PG_ENERGYCONSUMERRELIABLE_STEP,					0,											0,								},	g_PGEnergyConsumerReliableFieldArray,	},
	{	PG_SUBREGION,						"SubRegion"							,	"", "供电分区"				, 0	, sizeof(g_PGSubRegionFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGSubRegion)					, PG_MaxSubRegion						, PGSubRegion_Offset					,	{	2,	PG_SUBREGION_REGIONTYPE,					PG_SUBREGION_NAME,								0,											0,								},	g_PGSubRegionFieldArray,				},
	{	PG_CONNLINE,						"ConnLine"							,	"", "连接线"				, 0	, sizeof(g_PGConnLineFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGConnLine)						, PG_MaxConnLine						, PGConnLine_Offset						,	{	1,	PG_CONNLINE_RESOURCEID,						0,												0,											0,								},	g_PGConnLineFieldArray					},
	{	PG_LANDPLOT,						"LandPlot"							,	"", "地块"					, 0	, sizeof(g_PGLandPlotFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGLandPlot)						, PG_MaxLandPlot						, PGLandPlot_Offset						,	{	1,	PG_LANDPLOT_RESOURCEID,						0,												0,											0,								},	g_PGLandPlotFieldArray					},
	{	PG_PIPE,							"Pipe"								,	"", "电缆管线"				, 0	, sizeof(g_PGPipeFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGPipe)							, PG_MaxPipe							, PGPipe_Offset							,	{	1,	PG_PIPE_RESOURCEID,							0,												0,											0,								},	g_PGPipeFieldArray						},
	{	PG_HYPERLINK,						"HyperLink"							,	"", "图形链接"				, 0	, sizeof(g_PGHyperLinkFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGHyperLinks)					, PG_MaxHyperLinks						, PGHyperLinks_Offset					,	{	1,	PG_HYPERLINKS_RESOURCEID,					0,												0,											0,								},	g_PGHyperLinkFieldArray					},
	{	PG_DRAWING,							"Drawing"							,	"", "图纸信息"				, 0	, sizeof(g_PGDrawingFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGDrawing)						, PG_MaxDrawing							, PGDrawing_Offset						,	{	1,	PG_DRAWING_RESOURCEID,						0,												0,											0,								},	g_PGDrawingFieldArray					},
	{	PG_GRAPHLAYER,						"GraphLayer"						,	"", "图层信息"				, 0	, sizeof(g_PGGraphLayerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGGraphLayer)					, PG_MaxGraphLayer						, PGGraphLayer_Offset					,	{	2,	PG_GRAPHLAYER_DRAWING,						PG_GRAPHLAYER_NAME,								0,											0,								},	g_PGGraphLayerFieldArray				},
	{	PG_GRAPHATTR,						"GraphAttr"							,	"", "图形信息"				, 0	, sizeof(g_PGGraphAttrFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGGraphAttr)					, PG_MaxGraphAttr						, PGGraphAttr_Offset					,	{	4,	PG_GRAPHATTR_DRAWING,						PG_GRAPHATTR_PARENTID,							PG_GRAPHATTR_TABLE,							PG_GRAPHATTR_KEYFIELD,			},	g_PGGraphAttrFieldArray					},
	{	PG_LINEVERTEX,						"LineVertex"						,	"", "点信息"				, 0	, sizeof(g_PGLineVertexFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGLineVertex)					, PG_MaxLineVertex						, PGLineVertex_Offset					,	{	4,	PG_LINEVERTEX_DRAWING,						PG_LINEVERTEX_TABLE,							PG_LINEVERTEX_PARENT,						PG_LINEVERTEX_SERIAL,			},	g_PGLineVertexFieldArray				},
	{	PG_SCCFMOVE,						"SccFMove"							,	"", "线路故障点移动计算结果", 0	, sizeof(g_PGSccFMoveFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGSccFMove)						, PG_MaxSccFMove						, PGSccFMove_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGSccFMoveFieldArray					},
};

static	tagMDBTableFieldContainer	g_PGTableFieldContainerArray[]=
{
	{	MDBFieldWarn,	PG_SUBCONTROLAREA,			PG_SUBCONTROLAREA_COMPANY,				-1,										-1,	-1,		PG_COMPANY,				},
	{	MDBFieldWarn,	PG_SUBSTATION,				PG_SUBSTATION_COMPANY,					-1,										-1,	-1,		PG_COMPANY,				},
	{	MDBFieldWarn,	PG_SUBSTATION,				PG_SUBSTATION_SUBCONTROLAREA,			-1,										-1,	-1,		PG_SUBCONTROLAREA,		},
	{	MDBFieldCrit,	PG_VOLTAGELEVEL,			PG_VOLTAGELEVEL_SUBSTATION,				-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_BUSBARSECTION,			PG_BUSBARSECTION_SUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_BUSBARSECTION,			PG_BUSBARSECTION_SUBSTATION,			PG_BUSBARSECTION_VOLTAGELEVEL,			-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_ACLINESEGMENT,			PG_ACLINESEGMENT_ISUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_ACLINESEGMENT,			PG_ACLINESEGMENT_JSUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_ACLINESEGMENT,			PG_ACLINESEGMENT_ISUBSTATION,			PG_ACLINESEGMENT_IVOLTAGELEVEL,			-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_ACLINESEGMENT,			PG_ACLINESEGMENT_JSUBSTATION,			PG_ACLINESEGMENT_JVOLTAGELEVEL,			-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldWarn,	PG_ACLINESEGMENT,			PG_ACLINESEGMENT_LINE,					-1,										-1,	-1,		PG_LINE,				},
	{	MDBFieldCrit,	PG_DCLINESEGMENT,			PG_DCLINESEGMENT_ISUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_DCLINESEGMENT,			PG_DCLINESEGMENT_JSUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_DCLINESEGMENT,			PG_DCLINESEGMENT_ISUBSTATION,			PG_DCLINESEGMENT_IVOLTAGELEVEL,			-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_DCLINESEGMENT,			PG_DCLINESEGMENT_JSUBSTATION,			PG_DCLINESEGMENT_JVOLTAGELEVEL,			-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldWarn,	PG_DCLINESEGMENT,			PG_DCLINESEGMENT_LINE,					-1,										-1,	-1,		PG_LINE,				},
	{	MDBFieldCrit,	PG_POWERTRANSFORMER,		PG_POWERTRANSFORMER_SUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_TRANSFORMERWINDING,		PG_TRANSFORMERWINDING_SUBSTATION,		-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldWarn,	PG_TRANSFORMERWINDING,		PG_TRANSFORMERWINDING_SUBSTATION,		PG_TRANSFORMERWINDING_VOLTAGELEVELI,	-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldWarn,	PG_TRANSFORMERWINDING,		PG_TRANSFORMERWINDING_SUBSTATION,		PG_TRANSFORMERWINDING_VOLTAGELEVELJ,	-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldWarn,	PG_TRANSFORMERWINDING,		PG_TRANSFORMERWINDING_POWERTRANSFORMER,	-1,										-1,	-1,		PG_POWERTRANSFORMER,	},
	{	MDBFieldWarn,	PG_TRANSFORMERWINDING,		PG_TRANSFORMERWINDING_TAPCHANGERI,		-1,										-1,	-1,		PG_TAPCHANGER,			},
	{	MDBFieldWarn,	PG_TRANSFORMERWINDING,		PG_TRANSFORMERWINDING_TAPCHANGERJ,		-1,										-1,	-1,		PG_TAPCHANGER,			},
	{	MDBFieldCrit,	PG_RECTIFIERINVERTER,		PG_RECTIFIERINVERTER_SUBSTATION,		-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_RECTIFIERINVERTER,		PG_RECTIFIERINVERTER_SUBSTATION,		PG_RECTIFIERINVERTER_VOLTAGELEVELAC,	-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_RECTIFIERINVERTER,		PG_RECTIFIERINVERTER_SUBSTATION,		PG_RECTIFIERINVERTER_VOLTAGELEVELDC,	-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_SYNCHRONOUSMACHINE,		PG_SYNCHRONOUSMACHINE_SUBSTATION,		-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_SYNCHRONOUSMACHINE,		PG_SYNCHRONOUSMACHINE_SUBSTATION,		PG_SYNCHRONOUSMACHINE_VOLTAGELEVEL,		-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_ENERGYCONSUMER,			PG_ENERGYCONSUMER_SUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_ENERGYCONSUMER,			PG_ENERGYCONSUMER_SUBSTATION,			PG_ENERGYCONSUMER_VOLTAGELEVEL,			-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_SHUNTCOMPENSATOR,		PG_SHUNTCOMPENSATOR_SUBSTATION,			-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_SHUNTCOMPENSATOR,		PG_SHUNTCOMPENSATOR_SUBSTATION,			PG_SHUNTCOMPENSATOR_VOLTAGELEVEL,		-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_SERIESCOMPENSATOR,		PG_SERIESCOMPENSATOR_SUBSTATION,		-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_SERIESCOMPENSATOR,		PG_SERIESCOMPENSATOR_SUBSTATION,		PG_SERIESCOMPENSATOR_VOLTAGELEVEL,		-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_BREAKER,					PG_BREAKER_SUBSTATION,					-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_BREAKER,					PG_BREAKER_SUBSTATION,					PG_BREAKER_VOLTAGELEVEL,				-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_DISCONNECTOR,			PG_DISCONNECTOR_SUBSTATION,				-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_DISCONNECTOR,			PG_DISCONNECTOR_SUBSTATION,				PG_DISCONNECTOR_VOLTAGELEVEL,			-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldCrit,	PG_GROUNDDISCONNECTOR,		PG_GROUNDDISCONNECTOR_SUBSTATION,		-1,										-1,	-1,		PG_SUBSTATION,			},
	{	MDBFieldCrit,	PG_GROUNDDISCONNECTOR,		PG_GROUNDDISCONNECTOR_SUBSTATION,		PG_GROUNDDISCONNECTOR_VOLTAGELEVEL,		-1,	-1,		PG_VOLTAGELEVEL,		},
	{	MDBFieldWarn,	PG_GRAPHLAYER,				PG_GRAPHLAYER_DRAWING,					-1,										-1,	-1,		PG_DRAWING,				},
	{	MDBFieldWarn,	PG_GRAPHATTR,				PG_GRAPHATTR_DRAWING,					-1,										-1,	-1,		PG_DRAWING,				},
	{	MDBFieldWarn,	PG_LINEVERTEX,				PG_LINEVERTEX_DRAWING,					-1,										-1,	-1,		PG_DRAWING,				},
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
