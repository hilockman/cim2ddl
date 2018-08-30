#ifndef _PGMEMDBBLOCK_H_
#	define	_PGMEMDBBLOCK_H_

#include "PGMemDBDefine.h"

#	if defined(__GNUG__) || defined(__GNUC__)	// GCC±àÒëÆ÷Ô¤¶¨ÒåµÄºê
#		ifndef DISALIGN
#			define DISALIGN __attribute__((packed))
#		endif
#	else
#		define DISALIGN
#		if (defined(_AIX) || defined(AIX))
#			pragma align(packed)
#		else
#			if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#				pragma pack(push)
#			endif
#		endif
#		pragma pack(1)
#	endif

struct	_PowerGridBlock_	{
	tagMDBBlockSummy				m_MDBSummary;

	int	m_nRecordNum[MAXMDBTABLENUM];

	tagPGSystem							m_System							;
	tagPGBaseVoltage					m_BaseVoltageArray					[PG_MaxBaseVoltage					];
	tagPGCompany						m_CompanyArray						[PG_MaxCompany						];
	tagPGSubcontrolArea					m_SubcontrolAreaArray				[PG_MaxSubcontrolArea				];
	tagPGSubstation						m_SubstationArray					[PG_MaxSubstation					];
	tagPGVoltageLevel					m_VoltageLevelArray					[PG_MaxVoltageLevel					];
	tagPGBusbarSection					m_BusbarSectionArray				[PG_MaxBusbarSection				];
	tagPGLine							m_LineArray							[PG_MaxLine							];
	tagPGACLineSegment					m_ACLineSegmentArray				[PG_MaxACLineSegment				];
	tagPGDCLineSegment					m_DCLineSegmentArray				[PG_MaxDCLineSegment				];
	tagPGPowerTransformer				m_PowerTransformerArray				[PG_MaxPowerTransformer				];
	tagPGTransformerWinding				m_TransformerWindingArray			[PG_MaxTransformerWinding			];
	tagPGRectifierInverter				m_RectifierInverterArray			[PG_MaxRectifierInverter			];
	tagPGSynchronousMachine				m_SynchronousMachineArray			[PG_MaxSynchronousMachine			];
	tagPGEnergyConsumer					m_EnergyConsumerArray				[PG_MaxEnergyConsumer				];
	tagPGShuntCompensator				m_ShuntCompensatorArray				[PG_MaxShuntCompensator				];
	tagPGSeriesCompensator				m_SeriesCompensatorArray			[PG_MaxSeriesCompensator			];
	tagPGBreaker						m_BreakerArray						[PG_MaxBreaker						];
	tagPGDisconnector					m_DisconnectorArray					[PG_MaxDisconnector					];
	tagPGGroundDisconnector				m_GroundDisconnectorArray			[PG_MaxGroundDisconnector			];
	tagPGGroundTransformer				m_GroundTransformerArray			[PG_MaxGroundTransformer			];

	tagPGThermalEnergyConsumer			m_ThermalEnergyConsumerArray		[PG_MaxThermalEnergyConsumer		];
	tagPGElectroChemicalEnergyStorage	m_ElectroChemicalEnergyStorageArray	[PG_MaxElectroChemicalEnergyStorage	];

	tagPGLoadModel						m_LoadModelArray					[PG_MaxLoadModel					];
	tagPGTapChanger						m_TapChangerArray					[PG_MaxTapchanger					];

	tagPGTerminal						m_TerminalArray						[PG_MaxTerminal						];
	tagPGConnectivityNode				m_ConnectivityNodeArray				[PG_MaxConnectivityNode				];

	tagPGEdgeACLineSegment				m_EdgeACLineSegmentArray			[PG_MaxEdgeACLineSegment			];
	tagPGEdgeDCLineSegment				m_EdgeDCLineSegmentArray			[PG_MaxEdgeDCLineSegment			];
	tagPGEdgeTransformerWinding			m_EdgeTransformerWindingArray		[PG_MaxEdgeTransformerWinding		];
	tagPGEdgeSeriesCompensator			m_EdgeSeriesCompensatorArray		[PG_MaxEdgeSeriesCompensator		];
	tagPGEdgeBreaker					m_EdgeBreakerArray					[PG_MaxEdgeBreaker					];
	tagPGEdgeDisconnector				m_EdgeDisconnectorArray				[PG_MaxEdgeDisconnector				];
	tagPGTieLine						m_TielineArray						[PG_MaxTieLine						];

	tagPGIsland							m_IslandArray						[PG_MaxIsland						];
	tagPGTopoBus						m_TopoBusArray						[PG_MaxTopoBus						];
	tagPGSccFMove						m_SccFMoveArray						[PG_MaxSccFMove						];
	//tagPGTopoVDip						m_TopoVDipArray						[PG_MaxTopoVDip						];

	tagPGProtSetting					m_ProtSetting						;
	tagPGProtLine						m_ProtLineArray						[PG_MaxProtLine						];
	tagPGProtTran						m_ProtTranArray						[PG_MaxProtTran						];
	tagPGProtBus						m_ProtBusArray						[PG_MaxProtBus						];
	tagPGProtGen						m_ProtGenArray						[PG_MaxProtGen						];
	tagPGProtCap						m_ProtCapArray						[PG_MaxProtCap						];
	tagPGProtReac						m_ProtReacArray						[PG_MaxProtReac						];
	tagPGProtMotor						m_ProtMotorArray					[PG_MaxProtMotor					];
	tagPGProtBreaker					m_ProtBreakerArray					[PG_MaxProtBreaker					];

	tagPGSystemReliable					m_SystemReliableArray				[PG_MaxSystemReliable				];
	tagPGEnergyConsumerReliable			m_EnergyConsumerReliableArray		[PG_MaxEnergyConsumerReliable		];

	tagPGSubRegion						m_SubRegionArray					[PG_MaxSubRegion					];
	tagPGSubstationEntity				m_SubstationEntityArray				[PG_MaxSubstationEntity				];
	tagPGTrunkSegment					m_TrunkArray						[PG_MaxTrunkSegment					];
	tagPGBranchSegment					m_BranchArray						[PG_MaxBranchSegment				];
	tagPGDistributionSwitch				m_DistributionSwitchArray			[PG_MaxDistributionSwitch			];
	tagPGDistributionLoad				m_DistributionLoadArray				[PG_MaxDistributionLoad				];
	tagPGDistributionBreaker			m_DistributionBreakerArray			[PG_MaxDistributionBreaker			];
	tagPGDistributionDot				m_DistributionDotArray				[PG_MaxDistributionDot				];
	tagPGWindTurbine					m_WindTurbineArray					[PG_MaxWindTurbine					];
	tagPGPhotoVoltaic					m_PhotoVoltaicArray					[PG_MaxPhotoVoltaic					];
	tagPGEVStation						m_EVStationArray					[PG_MaxEVStation					];

	tagPGConnLine						m_ConnLineArray						[PG_MaxConnLine						];
	tagPGLandPlot						m_LandPlotArray						[PG_MaxLandPlot						];
	tagPGPipe							m_PipeArray							[PG_MaxPipe							];
	tagPGHyperLinks						m_HyperLinksArray					[PG_MaxHyperLinks					];

	tagPGDrawing						m_DrawingArray						[PG_MaxDrawing						];
	tagPGGraphLayer						m_GraphLayerArray					[PG_MaxGraphLayer					];
	tagPGGraphAttr						m_GraphAttrArray					[PG_MaxGraphAttr					];
	tagPGLineVertex						m_LineVertexArray					[PG_MaxLineVertex					];
}	DISALIGN;
typedef	struct	_PowerGridBlock_	tagPGBlock;

#	if !defined(__GNUG__) && !defined(__GNUC__)
#		pragma pack()
#		if (defined(_AIX) || defined(AIX))
#			pragma align(fPower)
#		else
#			if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#				pragma pack(pop)
#			endif
#		endif
#	endif

#endif	//_PGMEMDBBLOCK_H_
