#pragma once

#include "PGMemDBDefine.h"
#include "PGMemDBField.h"

// ������		Switching station
// ������		Switchgear Cupboard
// �����		Distribution Room
// ��ʽ���վ	Box-type substation
// ���·�֧��	Cable Branch Box

//	�����а���������ȫ���ݵĽṹ���塣
//	�����а���������ȫ���ݵ��ֵ䶨�塣
//	�ڽ������ݽṹ����ʱ��Ҫ���ģ�
//		�ṹ����
//		�ֵ䶨��
//		�궨��
//	��Ҫ���ģ�
//		д����
//		��ӷ���
//		չʾ����

//	�����ݽṹ��������һЩ�м�������������ֵ��б�������ӳ�ڽṹ�����С�

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

//	������Ҫע�����RESTRICT�еĹؼ��ֱ���ΪCHAR���������CHAR��ͨ��CHARҲ�ܱȽ�
static tagMemDBTable	g_PGTableDictArray[]=
{
	{	PG_SYSTEM,							"System"							,	"", "ϵͳ"					, 0	, sizeof(g_PGSystemField)							/sizeof(tagMemDBField)	, sizeof(tagPGSystem)						, 1										, PGSystem_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGSystemField,						},
	{	PG_BASEVOLTAGE,						"BaseVoltage"						,	"", "��׼��ѹ"				, 0	, sizeof(g_PGBaseVoltageFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGBaseVoltage)					, PG_MaxBaseVoltage						, PGBaseVoltage_Offset					,	{	1,	PG_BASEVOLTAGE_NAME,						0,												0,											0,								},	g_PGBaseVoltageFieldArray,				},
	{	PG_COMPANY,							"Company"							,	"", "������˾"				, 0	, sizeof(g_PGCompanyFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGCompany)						, PG_MaxCompany							, PGCompany_Offset						,	{	1,	PG_COMPANY_NAME,							0,												0,											0,								},	g_PGCompanyFieldArray,					},
	{	PG_SUBCONTROLAREA,					"SubControlArea"					,	"", "��������"				, 0	, sizeof(g_PGSubControlAreaFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGSubcontrolArea)				, PG_MaxSubcontrolArea					, PGSubcontrolArea_Offset				,	{	1,	PG_SUBCONTROLAREA_NAME,						0,												0,											0,								},	g_PGSubControlAreaFieldArray,			},
	{	PG_SUBSTATION,						"Substation"						,	"", "��վ"					, 0	, sizeof(g_PGSubstationFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGSubstation)					, PG_MaxSubstation						, PGSubstation_Offset					,	{	1,	PG_SUBSTATION_NAME,							0,												0,											0,								},	g_PGSubstationFieldArray,				},
	{	PG_VOLTAGELEVEL,					"VoltageLevel"						,	"", "��ѹ�ȼ�"				, 0	, sizeof(g_PGVoltageLevelFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGVoltageLevel)					, PG_MaxVoltageLevel					, PGVoltageLevel_Offset					,	{	2,	PG_VOLTAGELEVEL_SUBSTATION,					PG_VOLTAGELEVEL_NAME,							0,											0,								},	g_PGVoltageLevelFieldArray,				},
	{	PG_BUSBARSECTION,					"BusbarSection"						,	"", "ĸ��"					, 0	, sizeof(g_PGBusbarSectionFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGBusbarSection)				, PG_MaxBusbarSection					, PGBusbarSection_Offset				,	{	3,	PG_BUSBARSECTION_SUBSTATION,				PG_BUSBARSECTION_VOLTAGELEVEL,					PG_BUSBARSECTION_NAME,						0,								},	g_PGBusbarSectionFieldArray,			},
	{	PG_LINE,							"Line"								,	"", "��·"					, 0	, sizeof(g_PGLineFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGLine)							, PG_MaxLine							, PGLine_Offset							,	{	1,	PG_LINE_NAME,								0,												0,											0,								},	g_PGLineFieldArray,						},
	{	PG_ACLINESEGMENT,					"ACLineSegment"						,	"", "������·��"			, 0	, sizeof(g_PGACLineSegmentFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGACLineSegment)				, PG_MaxACLineSegment					, PGACLineSegment_Offset				,	{	1,	PG_ACLINESEGMENT_NAME,						0,												0,											0,								},	g_PGACLineSegmentFieldArray,			},
	{	PG_DCLINESEGMENT,					"DCLineSegment"						,	"", "ֱ����·��"			, 0	, sizeof(g_PGDCLineSegmentFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDCLineSegment)				, PG_MaxDCLineSegment					, PGDCLineSegment_Offset				,	{	1,	PG_DCLINESEGMENT_NAME,						0,												0,											0,								},	g_PGDCLineSegmentFieldArray,			},
	{	PG_POWERTRANSFORMER,				"PowerTransformer"					,	"", "��ѹ��"				, 0	, sizeof(g_PGPowerTransformerFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGPowerTransformer)				, PG_MaxPowerTransformer				, PGPowerTransformer_Offset				,	{	2,	PG_POWERTRANSFORMER_SUBSTATION,				PG_POWERTRANSFORMER_NAME,						0,											0,								},	g_PGPowerTransformerFieldArray,			},
	{	PG_TRANSFORMERWINDING,				"TransformerWinding"				,	"", "��ѹ������"			, 0	, sizeof(g_PGTransformerWindingFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGTransformerWinding)			, PG_MaxTransformerWinding				, PGTransformerWinding_Offset			,	{	2,	PG_TRANSFORMERWINDING_SUBSTATION,			PG_TRANSFORMERWINDING_NAME,						0,											0,								},	g_PGTransformerWindingFieldArray,		},
	{	PG_SYNCHRONOUSMACHINE,				"SynchronousMachine"				,	"", "�����"				, 0	, sizeof(g_PGSynchronousMachineFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSynchronousMachine)			, PG_MaxSynchronousMachine				, PGSynchronousMachine_Offset			,	{	3,	PG_SYNCHRONOUSMACHINE_SUBSTATION,			PG_SYNCHRONOUSMACHINE_VOLTAGELEVEL,				PG_SYNCHRONOUSMACHINE_NAME,					0,								},	g_PGSynchronousMachineFieldArray,		},
	{	PG_ENERGYCONSUMER,					"EnergyConsumer"					,	"", "����"					, 0	, sizeof(g_PGEnergyConsumerFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEnergyConsumer)				, PG_MaxEnergyConsumer					, PGEnergyConsumer_Offset				,	{	3,	PG_ENERGYCONSUMER_SUBSTATION,				PG_ENERGYCONSUMER_VOLTAGELEVEL,					PG_ENERGYCONSUMER_NAME,						0,								},	g_PGEnergyConsumerFieldArray,			},
	{	PG_SHUNTCOMPENSATOR,				"ShuntCompensator"					,	"", "��������"				, 0	, sizeof(g_PGShuntCompensatorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGShuntCompensator)				, PG_MaxShuntCompensator				, PGShuntCompensator_Offset				,	{	3,	PG_SHUNTCOMPENSATOR_SUBSTATION,				PG_SHUNTCOMPENSATOR_VOLTAGELEVEL,				PG_SHUNTCOMPENSATOR_NAME,					0,								},	g_PGShuntCompensatorFieldArray,			},
	{	PG_SERIESCOMPENSATOR,				"SeriesCompensator"					,	"", "��������"				, 0	, sizeof(g_PGSeriesCompensatorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSeriesCompensator)			, PG_MaxSeriesCompensator				, PGSeriesCompensator_Offset			,	{	3,	PG_SERIESCOMPENSATOR_SUBSTATION,			PG_SERIESCOMPENSATOR_VOLTAGELEVEL,				PG_SERIESCOMPENSATOR_NAME,					0,								},	g_PGSeriesCompensatorFieldArray,		},
	{	PG_BREAKER,							"Breaker"							,	"", "��·��"				, 0	, sizeof(g_PGBreakerFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGBreaker)						, PG_MaxBreaker							, PGBreaker_Offset						,	{	3,	PG_BREAKER_SUBSTATION,						PG_BREAKER_VOLTAGELEVEL,						PG_BREAKER_NAME,							0,								},	g_PGBreakerFieldArray,					},
	{	PG_DISCONNECTOR,					"Disconnector"						,	"", "���뿪��"				, 0	, sizeof(g_PGDisconnectorFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDisconnector)					, PG_MaxDisconnector					, PGDisconnector_Offset					,	{	3,	PG_DISCONNECTOR_SUBSTATION,					PG_DISCONNECTOR_VOLTAGELEVEL,					PG_DISCONNECTOR_NAME,						0,								},	g_PGDisconnectorFieldArray,				},
	{	PG_GROUNDDISCONNECTOR,				"GroundDisconnector"				,	"", "�ӵص�բ"				, 0	, sizeof(g_PGGroundDisconnectorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGGroundDisconnector)			, PG_MaxGroundDisconnector				, PGGroundDisconnector_Offset			,	{	3,	PG_GROUNDDISCONNECTOR_SUBSTATION,			PG_GROUNDDISCONNECTOR_VOLTAGELEVEL,				PG_GROUNDDISCONNECTOR_NAME,					0,								},	g_PGGroundDisconnectorFieldArray,		},
	{	PG_RECTIFIERINVERTER,				"RectifierInverter"					,	"", "���������"			, 0	, sizeof(g_PGRectifierInverterFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGRectifierInverter)			, PG_MaxRectifierInverter				, PGRectifierInverter_Offset			,	{	2,	PG_RECTIFIERINVERTER_SUBSTATION,			PG_RECTIFIERINVERTER_NAME,						0,											0,								},	g_PGRectifierInverterFieldArray,		},
	{	PG_GROUNDTRANSFORMER,				"GroundTransformer"					,	"", "�ӵر�"				, 0	, sizeof(g_PGGroundTransformerFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGGroundTransformer)			, PG_MaxGroundTransformer				, PGGroundTransformer_Offset			,	{	3,	PG_GROUNDTRANSFORMER_SUBSTATION,			PG_GROUNDTRANSFORMER_VOLTAGELEVEL,				PG_GROUNDTRANSFORMER_NAME,					0,								},	g_PGGroundTransformerFieldArray,		},
	{	PG_WINDTURBINE,						"WindTurbine"						,	"", "���(��)"				, 0	, sizeof(g_PGWindTurbineFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGWindTurbine)					, PG_MaxWindTurbine						, PGWindTurbine_Offset					,	{	1,	PG_WINDTURBINE_RESOURCEID,					0,												0,											0,								},	g_PGWindTurbineFieldArray,				},
	{	PG_PHOTOVOLTAIC,					"PhotoVoltaic"						,	"", "���(վ)"				, 0	, sizeof(g_PGPhotoVoltaicFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGPhotoVoltaic)					, PG_MaxPhotoVoltaic					, PGPhotoVoltaic_Offset					,	{	1,	PG_PHOTOVOLTAIC_RESOURCEID,					0,												0,											0,								},	g_PGPhotoVoltaicFieldArray,				},
	{	PG_EVSTATION,						"EVStation"							,	"", "�綯������(��)��վ"	, 0	, sizeof(g_PGEVStationFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGEVStation)					, PG_MaxEVStation						, PGEVStation_Offset					,	{	1,	PG_EVSTATION_RESOURCEID,					0,												0,											0,								},	g_PGEVStationFieldArray,				},
	{	PG_ELECTROCHEMICALENERGYSTORAGE,	"ElectroChemicalEnergyStorage"		,	"", "�绯ѧ����"			, 0	, sizeof(g_PGElectroChemicalEnergyStorageFieldArray)/sizeof(tagMemDBField)	, sizeof(tagPGElectroChemicalEnergyStorage)	, PG_MaxElectroChemicalEnergyStorage	, PGElectroChemicalEnergyStorage_Offset	,	{	1,	PG_ELECTROCHEMICALENERGYSTORAGE_RESOURCEID,	0,												0,											0,								},	g_PGElectroChemicalEnergyStorageFieldArray,},
	{	PG_SOLARTHERMALMACHINE,				"SolarThermalMachine"				,	"", "���ȷ���"				, 0	, sizeof(g_PGSolarThermalMachineFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSolarThermalMachine)			, PG_MaxSolarThermalMachine				, PGSolarThermalMachine_Offset			,	{	1,	PG_SOLARTHERMALMACHINE_RESOURCEID,			0,												0,											0,								},	g_PGSolarThermalMachineFieldArray,		},

	{	PG_SUBSTATIONENTITY,				"SubstationEntity"					,	"", "��վʵ��"				, 0	, sizeof(g_PGSubstationEntityFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGSubstationEntity)				, PG_MaxSubstationEntity				, PGSubstationEntity_Offset				,	{	1,	PG_SUBSTATIONENTITY_NAME,					PG_SUBSTATIONENTITY_RESOURCEID,					0,											0,								},	g_PGSubstationEntityFieldArray,			},
	{	PG_BRANCHSEGMENT,					"BranchSegment"						,	"", "��֧��"				, 0	, sizeof(g_PGBranchSegmentFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGBranchSegment)				, PG_MaxBranchSegment					, PGBranchSegment_Offset				,	{	1,	PG_BRANCHSEGMENT_RESOURCEID,				0,												0,											0,								},	g_PGBranchSegmentFieldArray,			},
	{	PG_DISTRIBUTIONSWITCH,				"DistributionSwitch"				,	"", "��絥Ԫ"				, 0	, sizeof(g_PGDistributionSwitchFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDistributionSwitch)			, PG_MaxDistributionSwitch				, PGDistributionSwitch_Offset			,	{	1,	PG_DISTRIBUTIONSWITCH_RESOURCEID,			0,												0,											0,								},	g_PGDistributionSwitchFieldArray,		},
	{	PG_DISTRIBUTIONLOAD,				"DistributionLoad"					,	"", "��縺��"				, 0	, sizeof(g_PGDistributionLoadFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDistributionLoad)				, PG_MaxDistributionLoad				, PGDistributionLoad_Offset				,	{	1,	PG_DISTRIBUTIONLOAD_RESOURCEID,				0,												0,											0,								},	g_PGDistributionLoadFieldArray,			},
	{	PG_DISTRIBUTIONBREAKER,				"DistributionBreaker"				,	"", "��翪��"				, 0	, sizeof(g_PGDistributionBreakerFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDistributionBreaker)			, PG_MaxDistributionBreaker				, PGDistributionBreaker_Offset			,	{	1,	PG_DISTRIBUTIONBREAKER_RESOURCEID,			0,												0,											0,								},	g_PGDistributionBreakerFieldArray,		},
	{	PG_DISTRIBUTIONDOT,					"DistributionJuncPole"				,	"", "���ڵ�"				, 0	, sizeof(g_PGDistributionDotFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDistributionDot)				, PG_MaxDistributionDot					, PGDistributionDot_Offset				,	{	1,	PG_DISTRIBUTIONDOT_RESOURCEID,				0,												0,											0,								},	g_PGDistributionDotFieldArray,			},

	{	PG_ELECTRONICTRANSFORMER,			"ElectronicTransformer"				,	"", "�������ӱ�ѹ��"		, 0	, sizeof(g_PGElectronicTransformerFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGElectronicTransformer)		, PG_MaxElectronicTransformer			, PGElectronicTransformer_Offset		,	{	2,	PG_ELECTRONICTRANSFORMER_SUBSTATION,		PG_ELECTRONICTRANSFORMER_NAME,					0,											0,								},	g_PGElectronicTransformerFieldArray,	},
	{	PG_DCBUSBARSECTION,					"DCBusbarSection"					,	"", "ֱ��ĸ��"				, 0	, sizeof(g_PGDCBusbarSectionFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDCBusbarSection)				, PG_MaxDCBusbarSection					, PGDCBusbarSection_Offset				,	{	3,	PG_DCBUSBARSECTION_SUBSTATION,				PG_DCBUSBARSECTION_VOLTAGELEVEL,				PG_DCBUSBARSECTION_NAME,					0,								},	g_PGDCBusbarSectionFieldArray,			},
	{	PG_ACDCCONVERTER,					"ACDCConverter"						,	"", "����ֱ���任��"		, 0	, sizeof(g_PGACDCConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGACDCConverter)				, PG_MaxACDCConverter					, PGACDCConverter_Offset				,	{	2,	PG_ACDCCONVERTER_SUBSTATION,				PG_ACDCCONVERTER_NAME,							0,											0,								},	g_PGACDCConverterFieldArray,			},
	{	PG_DCDCCONVERTER,					"DCDCConverter"						,	"", "ֱ��ֱ���任��"		, 0	, sizeof(g_PGDCDCConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGDCDCConverter)				, PG_MaxDCDCConverter					, PGDCDCConverter_Offset				,	{	2,	PG_DCDCCONVERTER_SUBSTATION,				PG_DCDCCONVERTER_NAME,							0,											0,								},	g_PGDCDCConverterFieldArray,			},
	{	PG_DCBREAKER,						"DCBreaker"							,	"", "ֱ����·��"			, 0	, sizeof(g_PGDCBreakerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGDCBreaker)					, PG_MaxDCBreaker						, PGDCBreaker_Offset					,	{	3,	PG_DCBREAKER_SUBSTATION,					PG_DCBREAKER_VOLTAGELEVEL,						PG_DCBREAKER_NAME,							0,								},	g_PGDCBreakerFieldArray,				},
	{	PG_DCSHORTCIRCUITLIMIT,				"DCShortCircuitLimit"				,	"", "ֱ����·����������"	, 0	, sizeof(g_PGDCShortCircuitLimitFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGDCShortCircuitLimit)			, PG_MaxDCShortCircuitLimit				, PGDCShortCircuitLimit_Offset			,	{	3,	PG_DCSHORTCIRCUITLIMIT_SUBSTATION,			PG_DCSHORTCIRCUITLIMIT_VOLTAGELEVEL,			PG_DCSHORTCIRCUITLIMIT_NAME,				0,								},	g_PGDCShortCircuitLimitFieldArray,		},
	{	PG_THERMALENERGYCONSUMER,			"ThermalEnergyConsumer"				,	"", "���ȸ���"				, 0	, sizeof(g_PGThermalEnergyConsumerFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGThermalEnergyConsumer)		, PG_MaxThermalEnergyConsumer			, PGThermalEnergyConsumer_Offset		,	{	3,	PG_THERMALENERGYCONSUMER_SUBSTATION,		PG_THERMALENERGYCONSUMER_VOLTAGELEVEL,			PG_THERMALENERGYCONSUMER_NAME,				0,								},	g_PGThermalEnergyConsumerFieldArray,	},
	{	PG_LOADMODEL,						"LoadModel"							,	"", "����ģ��"				, 0	, sizeof(g_PGLoadModelFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGLoadModel)					, PG_MaxLoadModel						, PGLoadModel_Offset					,	{	1,	PG_LOADMODEL_NAME,							0,												0,											0,								},	g_PGLoadModelFieldArray,				},
	{	PG_TAPCHANGER,						"TapChanger"						,	"", "�ֽ�ͷ"				, 0	, sizeof(g_PGTapChangerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGTapChanger)					, PG_MaxTapchanger						, PGTapChanger_Offset					,	{	1,	PG_TAPCHANGER_NAME,							0,												0,											0,								},	g_PGTapChangerFieldArray,				},
	{	PG_TERMINAL,						"Terminal"							,	"", "�˵�"					, 0	, sizeof(g_PGTerminalFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGTerminal)						, PG_MaxTerminal						, PGTerminal_Offset						,	{	3,	PG_TERMINAL_SUBSTATION,						PG_TERMINAL_VOLTAGELEVEL,						PG_TERMINAL_NAME,							0,								},	g_PGTerminalFieldArray,					},
	{	PG_CONNECTIVITYNODE,				"ConnectivityNode"					,	"", "�ڵ�"					, 0	, sizeof(g_PGConnectivityNodeFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGConnectivityNode)				, PG_MaxConnectivityNode				, PGConnectivityNode_Offset				,	{	3,	PG_CONNECTIVITYNODE_SUBSTATION,				PG_CONNECTIVITYNODE_VOLTAGELEVEL,				PG_CONNECTIVITYNODE_NAME,					0,								},	g_PGConnectivityNodeFieldArray,			},
	{	PG_EDGEACLINESEGMENT,				"EdgeACLineSegment"					,	"", "������·��"			, 0	, sizeof(g_PGEdgeACLineSegmentFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGEdgeACLineSegment)			, PG_MaxEdgeACLineSegment				, PGEdgeACLineSegment_Offset			,	{	4,	PG_EDGEACLINESEGMENT_SUBSTATION,			PG_EDGEACLINESEGMENT_VOLTAGELEVEL,				PG_EDGEACLINESEGMENT_CONNECTIVITYNODE,		PG_EDGEACLINESEGMENT_NAME,		},	g_PGEdgeACLineSegmentFieldArray,		},
	{	PG_EDGEDCLINESEGMENT,				"EdgeDCLineSegment"					,	"", "ֱ����·��"			, 0	, sizeof(g_PGEdgeDCLineSegmentFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDCLineSegment)			, PG_MaxEdgeDCLineSegment				, PGEdgeDCLineSegment_Offset			,	{	4,	PG_EDGEDCLINESEGMENT_SUBSTATION,			PG_EDGEDCLINESEGMENT_VOLTAGELEVEL,				PG_EDGEDCLINESEGMENT_CONNECTIVITYNODE,		PG_EDGEDCLINESEGMENT_NAME,		},	g_PGEdgeDCLineSegmentFieldArray,		},
	{	PG_EDGETRANSFORMERWINDING,			"EdgeTransformerWinding"			,	"", "��ѹ����"				, 0	, sizeof(g_PGEdgeTransformerWindingFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEdgeTransformerWinding)		, PG_MaxEdgeTransformerWinding			, PGEdgeTransformerWinding_Offset		,	{	4,	PG_EDGETRANSFORMERWINDING_SUBSTATION,		PG_EDGETRANSFORMERWINDING_VOLTAGELEVEL, 		PG_EDGETRANSFORMERWINDING_CONNECTIVITYNODE, PG_EDGETRANSFORMERWINDING_NAME, },	g_PGEdgeTransformerWindingFieldArray,	},
	{	PG_EDGESERIESCOMPENSATOR,			"EdgeSeriesCompensator"				,	"", "����������"			, 0	, sizeof(g_PGEdgeSeriesCompensatorFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEdgeSeriesCompensator)		, PG_MaxEdgeSeriesCompensator			, PGEdgeSeriesCompensator_Offset		,	{	4,	PG_EDGESERIESCOMPENSATOR_SUBSTATION,		PG_EDGESERIESCOMPENSATOR_VOLTAGELEVEL,			PG_EDGESERIESCOMPENSATOR_CONNECTIVITYNODE,	PG_EDGESERIESCOMPENSATOR_NAME,	},	g_PGEdgeSeriesCompensatorFieldArray,	},
	{	PG_EDGEBREAKER,						"EdgeBreaker"						,	"", "��·����"				, 0	, sizeof(g_PGEdgeBreakerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGEdgeBreaker)					, PG_MaxEdgeBreaker						, PGEdgeBreaker_Offset					,	{	4,	PG_EDGEBREAKER_SUBSTATION,					PG_EDGEBREAKER_VOLTAGELEVEL,					PG_EDGEBREAKER_CONNECTIVITYNODE,			PG_EDGEBREAKER_NAME,			},	g_PGEdgeBreakerFieldArray,				},
	{	PG_EDGEDISCONNECTOR,				"EdgeDisconnector"					,	"", "���뿪�ر�"			, 0	, sizeof(g_PGEdgeDisconnectorFieldArray)			/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDisconnector)				, PG_MaxEdgeDisconnector				, PGEdgeDisconnector_Offset				,	{	4,	PG_EDGEDISCONNECTOR_SUBSTATION,				PG_EDGEDISCONNECTOR_VOLTAGELEVEL,				PG_EDGEDISCONNECTOR_CONNECTIVITYNODE,		PG_EDGEDISCONNECTOR_NAME,		},	g_PGEdgeDisconnectorFieldArray,			},
	{	PG_EDGEADCONVERTER,					"EdgeADConverter"					,	"", "��ֱ�任����"			, 0	, sizeof(g_PGEdgeADConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEdgeADConverter)				, PG_MaxEdgeADConverter					, PGEdgeADConverter_Offset				,	{	4,	PG_EDGEADCONVERTER_SUBSTATION,				PG_EDGEADCONVERTER_VOLTAGELEVEL,				PG_EDGEADCONVERTER_CONNECTIVITYNODE,		PG_EDGEADCONVERTER_NAME,		},	g_PGEdgeADConverterFieldArray,			},
	{	PG_EDGEDDCONVERTER,					"EdgeDDConverter"					,	"", "ֱֱ�任����"			, 0	, sizeof(g_PGEdgeDDConverterFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDDConverter)				, PG_MaxEdgeDDConverter					, PGEdgeDDConverter_Offset				,	{	4,	PG_EDGEDDCONVERTER_SUBSTATION,				PG_EDGEDDCONVERTER_VOLTAGELEVEL,				PG_EDGEDDCONVERTER_CONNECTIVITYNODE,		PG_EDGEDDCONVERTER_NAME,		},	g_PGEdgeDDConverterFieldArray,			},
	{	PG_EDGEDCBREAKER,					"EdgeDCBreaker"						,	"", "ֱ����·����"			, 0	, sizeof(g_PGEdgeDCBreakerFieldArray)				/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDCBreaker)				, PG_MaxEdgeDCBreaker					, PGEdgeDCBreaker_Offset				,	{	4,	PG_EDGEDCBREAKER_SUBSTATION,				PG_EDGEDCBREAKER_VOLTAGELEVEL,					PG_EDGEDCBREAKER_CONNECTIVITYNODE,			PG_EDGEDCBREAKER_NAME,			},	g_PGEdgeDCBreakerFieldArray,			},
	{	PG_EDGEDCSHORTCIRCUITLIMIT,			"EdgeDCShortCircuitLimit"			,	"", "ֱ����·������������"	, 0	, sizeof(g_PGEdgeDCShortCircuitLimitFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEdgeDCShortCircuitLimit)		, PG_MaxEdgeDCShortCircuitLimit			, PGEdgeDCShortCircuitLimit_Offset		,	{	4,	PG_EDGEDCSHORTCIRCUITLIMIT_SUBSTATION,		PG_EDGEDCSHORTCIRCUITLIMIT_VOLTAGELEVEL,		PG_EDGEDCSHORTCIRCUITLIMIT_CONNECTIVITYNODE,PG_EDGEDCSHORTCIRCUITLIMIT_NAME,},	g_PGEdgeDCShortCircuitLimitFieldArray,	},

	{	PG_TIELINE,							"Tieline"							,	"", "������"				, 0	, sizeof(g_PGTielineFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGTieLine)						, PG_MaxTieLine							, PGTieLine_Offset						,	{	1,	PG_TIELINE_NAME,							0,												0,											0,								},	g_PGTielineFieldArray,					},

	{	PG_ISLAND,							"Island"							,	"", "��"					, 0	, sizeof(g_PGIslandFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGIsland)						, PG_MaxIsland							, PGIsland_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGIslandFieldArray,					},
	{	PG_TOPOBUS,							"TopoBus"							,	"", "����ڵ�"				, 0	, sizeof(g_PGTopoBusFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGTopoBus)						, PG_MaxTopoBus							, PGTopoBus_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGTopoBusFieldArray					},

#ifdef PGProtSettingDefine
	{	PG_PROTSETTING,						"ProtSetting"						,	"", "��������"				, 0	, sizeof(g_PGProtSettingFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtSetting)					, PG_MaxProtSetting						, PGProtSetting_Offset					,	{	0,	0,											0,												0,											0,								},	g_PGProtSettingFieldArray				},
	{	PG_PROTLINE,						"ProtLine"							,	"", "��·����"				, 0	, sizeof(g_PGProtLineFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtLine)						, PG_MaxProtLine						, PGProtLine_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtLineFieldArray					},
	{	PG_PROTTRAN,						"ProtTran"							,	"", "��ѹ������"			, 0	, sizeof(g_PGProtTranFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtTran)						, PG_MaxProtTran						, PGProtTran_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtTranFieldArray					},
	{	PG_PROTBUS,							"ProtBus"							,	"", "ĸ�߱���"				, 0	, sizeof(g_PGProtBusFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGProtBus)						, PG_MaxProtBus							, PGProtBus_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtBusFieldArray					},
	{	PG_PROTGEN,							"ProtGen"							,	"", "���������"			, 0	, sizeof(g_PGProtGenFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGProtGen)						, PG_MaxProtGen							, PGProtGen_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtGenFieldArray					},
	{	PG_PROTCAP,							"ProtCap"							,	"", "��������������"		, 0	, sizeof(g_PGProtCapFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGProtCap)						, PG_MaxProtCap							, PGProtCap_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtCapFieldArray					},
	{	PG_PROTREAC,						"ProtReac"							,	"", "�����翹������"		, 0	, sizeof(g_PGProtReacFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtReac)						, PG_MaxProtReac						, PGProtReac_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGProtReacFieldArray					},
	{	PG_PROTMOTOR,						"ProtMotor"							,	"", "�綯������"			, 0	, sizeof(g_PGProtMotorFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtMotor)					, PG_MaxProtMotor						, PGProtMotor_Offset					,	{	0,	0,											0,												0,											0,								},	g_PGProtMotorFieldArray					},
	{	PG_PROTBREAKER,						"ProtBreaker"						,	"", "ĸ��(�ֶ�)��·������"	, 0	, sizeof(g_PGProtBreakerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGProtBreaker)					, PG_MaxProtBreaker						, PGProtBreaker_Offset					,	{	0,	0,											0,												0,											0,								},	g_PGProtBreakerFieldArray				},
#endif

	{	PG_SYSTEMRELIABLE,					"SystemReliable"					,	"", "ϵͳ�ɿ��Խ��"		, 0	, sizeof(g_PGSystemReliableField)					/sizeof(tagMemDBField)	, sizeof(tagPGSystemReliable)				, PG_MaxSystemReliable					, PGSystemReliable_Offset				,	{	1,	PG_SYSTEMRELIABLE_STEP,						0,												0,											0,								},	g_PGSystemReliableField,				},
	{	PG_ENERGYCONSUMERRELIABLE,			"EnergyConsumerReliable"			,	"", "���ɿɿ��Խ��"		, 0	, sizeof(g_PGEnergyConsumerReliableFieldArray)		/sizeof(tagMemDBField)	, sizeof(tagPGEnergyConsumerReliable)		, PG_MaxEnergyConsumerReliable			, PGEnergyConsumerReliable_Offset		,	{	2,	PG_ENERGYCONSUMERRELIABLE_LOAD,				PG_ENERGYCONSUMERRELIABLE_STEP,					0,											0,								},	g_PGEnergyConsumerReliableFieldArray,	},
	{	PG_SUBREGION,						"SubRegion"							,	"", "�������"				, 0	, sizeof(g_PGSubRegionFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGSubRegion)					, PG_MaxSubRegion						, PGSubRegion_Offset					,	{	2,	PG_SUBREGION_REGIONTYPE,					PG_SUBREGION_NAME,								0,											0,								},	g_PGSubRegionFieldArray,				},
	{	PG_CONNLINE,						"ConnLine"							,	"", "������"				, 0	, sizeof(g_PGConnLineFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGConnLine)						, PG_MaxConnLine						, PGConnLine_Offset						,	{	1,	PG_CONNLINE_RESOURCEID,						0,												0,											0,								},	g_PGConnLineFieldArray					},
	{	PG_LANDPLOT,						"LandPlot"							,	"", "�ؿ�"					, 0	, sizeof(g_PGLandPlotFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGLandPlot)						, PG_MaxLandPlot						, PGLandPlot_Offset						,	{	1,	PG_LANDPLOT_RESOURCEID,						0,												0,											0,								},	g_PGLandPlotFieldArray					},
	{	PG_PIPE,							"Pipe"								,	"", "���¹���"				, 0	, sizeof(g_PGPipeFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGPipe)							, PG_MaxPipe							, PGPipe_Offset							,	{	1,	PG_PIPE_RESOURCEID,							0,												0,											0,								},	g_PGPipeFieldArray						},
	{	PG_HYPERLINK,						"HyperLink"							,	"", "ͼ������"				, 0	, sizeof(g_PGHyperLinkFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGHyperLinks)					, PG_MaxHyperLinks						, PGHyperLinks_Offset					,	{	1,	PG_HYPERLINKS_RESOURCEID,					0,												0,											0,								},	g_PGHyperLinkFieldArray					},
	{	PG_DRAWING,							"Drawing"							,	"", "ͼֽ��Ϣ"				, 0	, sizeof(g_PGDrawingFieldArray)						/sizeof(tagMemDBField)	, sizeof(tagPGDrawing)						, PG_MaxDrawing							, PGDrawing_Offset						,	{	1,	PG_DRAWING_RESOURCEID,						0,												0,											0,								},	g_PGDrawingFieldArray					},
	{	PG_GRAPHLAYER,						"GraphLayer"						,	"", "ͼ����Ϣ"				, 0	, sizeof(g_PGGraphLayerFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGGraphLayer)					, PG_MaxGraphLayer						, PGGraphLayer_Offset					,	{	2,	PG_GRAPHLAYER_DRAWING,						PG_GRAPHLAYER_NAME,								0,											0,								},	g_PGGraphLayerFieldArray				},
	{	PG_GRAPHATTR,						"GraphAttr"							,	"", "ͼ����Ϣ"				, 0	, sizeof(g_PGGraphAttrFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGGraphAttr)					, PG_MaxGraphAttr						, PGGraphAttr_Offset					,	{	4,	PG_GRAPHATTR_DRAWING,						PG_GRAPHATTR_PARENTID,							PG_GRAPHATTR_TABLE,							PG_GRAPHATTR_KEYFIELD,			},	g_PGGraphAttrFieldArray					},
	{	PG_LINEVERTEX,						"LineVertex"						,	"", "����Ϣ"				, 0	, sizeof(g_PGLineVertexFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGLineVertex)					, PG_MaxLineVertex						, PGLineVertex_Offset					,	{	4,	PG_LINEVERTEX_DRAWING,						PG_LINEVERTEX_TABLE,							PG_LINEVERTEX_PARENT,						PG_LINEVERTEX_SERIAL,			},	g_PGLineVertexFieldArray				},
	{	PG_SCCFMOVE,						"SccFMove"							,	"", "��·���ϵ��ƶ�������", 0	, sizeof(g_PGSccFMoveFieldArray)					/sizeof(tagMemDBField)	, sizeof(tagPGSccFMove)						, PG_MaxSccFMove						, PGSccFMove_Offset						,	{	0,	0,											0,												0,											0,								},	g_PGSccFMoveFieldArray					},
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
