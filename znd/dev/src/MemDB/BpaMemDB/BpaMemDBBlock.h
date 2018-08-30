#pragma	once

#include "BpaMemDBDefine.h"

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

struct	_BPAMemDBBlock_	{
	tagMDBBlockSummy		m_MDBSummary;

	int	m_nRecordNum[MAXMDBTABLENUM];
	tagBpaDat_Case			m_BpaDat_Case										;
	tagBpaDat_Area			m_BpaDat_AreaArray				[MaxBpaDatArea		];
	tagBpaDat_I				m_BpaDat_IArray					[MaxBpaDatI			];
	tagBpaDat_Zone			m_BpaDat_ZoneArray				[MaxBpaDatZone		];
	tagBpaDat_Sub			m_BpaDat_SubArray				[MaxBpaDatSub		];
	tagBpaDat_ACBus			m_BpaDat_ACBusArray				[MaxBpaDatACBus		];
	tagBpaDat_ACLine		m_BpaDat_ACLineArray			[MaxBpaDatACLine	];
	tagBpaDat_LineHG		m_BpaDat_LineHGArray			[MaxBpaDatLineHG	];
	tagBpaDat_Wind			m_BpaDat_WindArray				[MaxBpaDatWind		];
	tagBpaDat_DCBus			m_BpaDat_DCBusArray				[MaxBpaDatDCBus		];
	tagBpaDat_DCLine		m_BpaDat_DCLineArray			[MaxBpaDatDCLine	];
	tagBpaDat_R				m_BpaDat_RArray					[MaxBpaDatR			];
	tagBpaDat_RZ			m_BpaDat_RZArray				[MaxBpaDatRZ		];
	tagBpaDat_P				m_BpaDat_PArray					[MaxBpaDatP			];
	tagBpaDat_ZIL			m_BpaDat_ZILArray				[MaxBpaDatZIL		];
	tagBpaDat_Gen			m_BpaDat_GenArray				[MaxBpaDatGen		];
	tagBpaDat_Load			m_BpaDat_LoadArray				[MaxBpaDatLoad		];
	tagBpaDat_Tran			m_BpaDat_TranArray				[MaxBpaDatTran		];
	tagBpaDat_EdgeLine		m_BpaDat_EdgeLineArray			[MaxBpaDatEdgeLine	];
	tagBpaDat_EdgeWind		m_BpaDat_EdgeWindArray			[MaxBpaDatEdgeWind	];
	tagBpaDat_EdgeLineHG	m_BpaDat_EdgeLineHGArray		[MaxBpaDatEdgeLineHG];
	tagBpaDat_Radiate		m_BpaDat_RadiateArray			[MaxBpaDatRadiate	];
	tagBpaScc_FMove			m_BpaScc_FMoveArray				[MaxBpaSccFMove		];

	tagBpaSwi_Case			m_BpaSwi_Case										;
	tagBpaSwi_F1			m_BpaSwi_F1Array				[MaxBpaSwiF1		];
	tagBpaSwi_F0			m_BpaSwi_F0Array				[MaxBpaSwiF0		];
	tagBpaSwi_FF			m_BpaSwi_FFArray				[MaxBpaSwiFF		];

	tagBpaSwi_Gen			m_BpaSwi_GenArray				[MaxBpaSwiGen		];
	tagBpaSwi_Damp			m_BpaSwi_DampArray				[MaxBpaSwiDamp		];
	tagBpaSwi_WGEGen		m_BpaSwi_WGEGenArray			[MaxBpaSwiWGEGen	];
	tagBpaSwi_GenLn			m_BpaSwi_GenLnArray				[MaxBpaSwiGENLN		];

	tagBpaSwi_Exc68			m_BpaSwi_Exc68Array				[MaxBpaSwiEXC68		];
	tagBpaSwi_Exc81			m_BpaSwi_Exc81Array				[MaxBpaSwiEXC81		];
	tagBpaSwi_ExcMV			m_BpaSwi_ExcMVArray				[MaxBpaSwiEXCMV		];
	tagBpaSwi_FZ			m_BpaSwi_FZArray				[MaxBpaSwiFZ		];
	tagBpaSwi_FCA			m_BpaSwi_FCAArray				[MaxBpaSwiFCA		];
	tagBpaSwi_FCB			m_BpaSwi_FCBArray				[MaxBpaSwiFCB		];

	tagBpaSwi_ExcX			m_BpaSwi_ExcXArray				[MaxBpaSwiEXCX		];

	tagBpaSwi_PssS			m_BpaSwi_PssSArray				[MaxBpaSwiPssS		];
	tagBpaSwi_PssSH			m_BpaSwi_PssSHArray				[MaxBpaSwiPssSH		];
	tagBpaSwi_PssSI			m_BpaSwi_PssSIArray				[MaxBpaSwiPssSI		];
	tagBpaSwi_PssSA			m_BpaSwi_PssSAArray				[MaxBpaSwiPssSA		];
	tagBpaSwi_PssSB			m_BpaSwi_PssSBArray				[MaxBpaSwiPssSB		];
	tagBpaSwi_PssST			m_BpaSwi_PssSTArray				[MaxBpaSwiPssST		];

	tagBpaSwi_GovGG			m_BpaSwi_GGArray				[MaxBpaSwiGG		];
	tagBpaSwi_GovGH			m_BpaSwi_GHArray				[MaxBpaSwiGH		];
	tagBpaSwi_GovGC			m_BpaSwi_GCArray				[MaxBpaSwiGC		];
	tagBpaSwi_GovGS			m_BpaSwi_GSArray				[MaxBpaSwiGS		];
	tagBpaSwi_GovGL			m_BpaSwi_GLArray				[MaxBpaSwiGL		];
	tagBpaSwi_GovGW			m_BpaSwi_GWArray				[MaxBpaSwiGW		];
	tagBpaSwi_GovGA			m_BpaSwi_GAArray				[MaxBpaSwiGA		];
	tagBpaSwi_GovGI			m_BpaSwi_GIArray				[MaxBpaSwiGI		];
	tagBpaSwi_GovGJ			m_BpaSwi_GJArray				[MaxBpaSwiGJ		];
	tagBpaSwi_GovGK			m_BpaSwi_GKArray				[MaxBpaSwiGK		];
	tagBpaSwi_GovGM			m_BpaSwi_GMArray				[MaxBpaSwiGM		];
	tagBpaSwi_GovGD			m_BpaSwi_GDArray				[MaxBpaSwiGD		];
	tagBpaSwi_GovGZ			m_BpaSwi_GZArray				[MaxBpaSwiGZ		];
	tagBpaSwi_MovTA			m_BpaSwi_TAArray				[MaxBpaSwiTA		];
	tagBpaSwi_MovTB			m_BpaSwi_TBArray				[MaxBpaSwiTB		];
	tagBpaSwi_MovTC			m_BpaSwi_TCArray				[MaxBpaSwiTC		];
	tagBpaSwi_MovTD			m_BpaSwi_TDArray				[MaxBpaSwiTD		];
	tagBpaSwi_MovTE			m_BpaSwi_TEArray				[MaxBpaSwiTE		];
	tagBpaSwi_MovTF			m_BpaSwi_TFArray				[MaxBpaSwiTF		];
	tagBpaSwi_MovTW			m_BpaSwi_TWArray				[MaxBpaSwiTW		];
	tagBpaSwi_GX			m_BpaSwi_GXArray				[MaxBpaSwiGX		];
	tagBpaSwi_IGV			m_BpaSwi_IGVArray				[MaxBpaSwiIGV		];
	tagBpaSwi_FGV			m_BpaSwi_FGVArray				[MaxBpaSwiFGV		];
	tagBpaSwi_LO			m_BpaSwi_LOArray				[MaxBpaSwiLO		];
	tagBpaSwi_XO			m_BpaSwi_XOArray				[MaxBpaSwiXO		];
	tagBpaSwi_LOHG			m_BpaSwi_LOHGArray				[MaxBpaSwiLOHG		];
	tagBpaSwi_XR			m_BpaSwi_XRArray				[MaxBpaSwiXR		];
	tagBpaSwi_D				m_BpaSwi_DArray					[MaxBpaSwiD			];
	tagBpaSwi_V				m_BpaSwi_VArray					[MaxBpaSwiV			];
	tagBpaSwi_VG			m_BpaSwi_VGArray				[MaxBpaSwiVG		];
	tagBpaSwi_LAB			m_BpaSwi_LABArray				[MaxBpaSwiLAB		];
	tagBpaSwi_MI			m_BpaSwi_MIArray				[MaxBpaSwiMI		];
	tagBpaSwi_ML			m_BpaSwi_MLArray				[MaxBpaSwiML		];
	tagBpaSwi_MJ			m_BpaSwi_MJArray				[MaxBpaSwiMJ		];
	tagBpaSwi_MK			m_BpaSwi_MKArray				[MaxBpaSwiMK		];
//	tagBpaSwi_LM			m_BpaSwi_LMArray				[MaxBpaSwiLM		];
// 	tagBpaSwi_LOZ			m_BpaSwi_LOZArray				[MaxBpaSwiLOZ		];
	tagBpaSwi_UF			m_BpaSwi_UFArray				[MaxBpaSwiUF		];
	tagBpaSwi_UV			m_BpaSwi_UVArray				[MaxBpaSwiUV		];
	tagBpaSwi_RE			m_BpaSwi_REArray				[MaxBpaSwiRE		];
	tagBpaSwi_RW			m_BpaSwi_RWArray				[MaxBpaSwiRW		];
	tagBpaSwi_RA			m_BpaSwi_RAArray				[MaxBpaSwiRA		];
	tagBpaSwi_RU			m_BpaSwi_RUArray				[MaxBpaSwiRU		];
}	DISALIGN;
typedef	struct	_BPAMemDBBlock_	tagBpaBlock;

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
