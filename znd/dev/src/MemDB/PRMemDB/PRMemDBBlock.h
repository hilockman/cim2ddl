#pragma once

#include "PRMemDBDefine.h"

#if defined(__GNUG__) || defined(__GNUC__)	// GCC±àÒëÆ÷Ô¤¶¨ÒåµÄºê
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

struct	_PRMemDBBlock_	{
	tagMDBBlockSummy				m_MDBSummary;
	int	m_nRecordNum[MAXMDBTABLENUM];
	tagPRSystem			m_System				;
	tagPRZone			m_ZoneArray				[PR_MaxZone			];
	tagPRRadial			m_RadialArray			[PR_MaxRadial		];
	tagPRACBus			m_ACBusArray			[PR_MaxACBus		];
	tagPRACLine			m_ACLineArray			[PR_MaxACLine		];
	tagPRWind			m_WindArray				[PR_MaxWind			];
	tagPRGenerator		m_GeneratorArray		[PR_MaxGenerator	];
	tagPRPowerLoad		m_PowerLoadArray		[PR_MaxPowerLoad	];
	tagPRHVDC			m_HVDCArray				[PR_MaxHVDC			];
	tagPRConverter		m_ConverterArray		[PR_MaxConverter	];
	tagPRDCBus			m_DCBusArray			[PR_MaxDCBus		];
	tagPRDCLine			m_DCLineArray			[PR_MaxDCLine		];
	tagPRTCSC			m_TCSCArray				[PR_MaxTCSC			];
	tagPRUPFC			m_UPFCArray				[PR_MaxUPFC			];
	tagPRDevMState		m_DevMStateArray		[PR_MaxDevMState	];
	tagPRACIsland		m_ACIslandArray			[PR_MaxACIsland		];
	tagPRACLineEdge		m_ACLineEdgeArray		[PR_MaxACLineEdge	];
	tagPRWindEdge		m_ACWindEdgeArray		[PR_MaxWindEdge		];

	tagPRTrip			m_TripModeArray			[PR_MaxTrip			];
	tagPRTripMIsland	m_TripMIslandArray		[PR_MaxTripMIsland	];
	tagPRTripOvlDev		m_TripOvlDevArray		[PR_MaxTripOvlDev	];

	tagPRCommRParam		m_CommRParamArray		[PR_MaxCommRParam	];
	tagPRManualFault	m_ManualFaultArray		[PR_MaxManualFault	];
	tagPRCommonFault	m_CommonFaultArray		[PR_MaxCommonFault	];
	tagPR2StateComp		m_R2StateCompArray		[PR_MaxR2StateComp	];
	tagPRMStateComp		m_RMStateCompArray		[PR_MaxRMStateComp	];
	//tagPRMCSampleState	m_MCSampleStateArray	[PR_MaxMCSampleState];
	tagPRFState			m_FStateArray			[PR_MaxFState		];
	tagPRFStateFDev		m_FStateFDevArray		[PR_MaxFStateFDev	];
	tagPRFStateMState	m_FStateMStateArray		[PR_MaxFStateMState	];
	tagPRFStateMIsland	m_FStateMIslandArray	[PR_MaxFStateMIsland];
	tagPRFStateOvlDev	m_FStateOvlDevArray		[PR_MaxFStateOvlDev	];
	tagPRFStateOvlAd	m_FStateOvlAdArray		[PR_MaxFStateOvlAd	];

	tagPRAdsNode		m_AdsNodeArray			[PR_MaxAdsNode		];
	tagPRCalcJobType	m_CalcJobTypeArray		[PR_MaxCalcJobType	];
	tagPRCalcJob		m_CalcJobArray			[PR_MaxCalcJob		];
	tagPRCalcTask		m_CalcTaskArray			[PR_MaxCalcTask		];
	tagPRCalcFile		m_CalcFileArray			[PR_MaxCalcFile		];

	tagPRFSecurity		m_FSecurityArray		[PR_MaxFSecurity	];
	tagPRCopGen			m_CopGenArray			[PR_MaxCopGen		];
	tagPRCopTable		m_CopTableArray			[PR_MaxCopTable		];
}	DISALIGN;
typedef	struct	_PRMemDBBlock_	tagPRBlock;

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
