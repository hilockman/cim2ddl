#pragma	once

#include "BpaMemDBDefine.h"
#include "BpaMemDBField.h"

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

static	tagMemDBTable	g_BpaTableDictArray[]=
{
	{	BPA_DAT_CASE,		"BpaDat_Case"		,	"", "潮流控制语句"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Case)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Case)		, MaxBpaDatCase			, BpaDatCase_Offset		,	{	1,	BPA_DAT_CASE_CASEID,			0,							0,								0,	},	dicFieldBpaDat_Case,		},
	{	BPA_DAT_AREA,		"BpaDat_Area"		,	"", "区域表(AREA)"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Area)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Area)		, MaxBpaDatArea			, BpaDatArea_Offset		,	{	1,	BPA_DAT_AREA_NAME,				0,							0,								0,	},	dicFieldBpaDat_Area,		},
	{	BPA_DAT_I,			"BpaDat_I"			,	"", "区域交换功率控制表(I)"				, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_I)			/sizeof(tagMemDBField)	, sizeof(tagBpaDat_I)			, MaxBpaDatI			, BpaDatI_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaDat_I,			},
	{	BPA_DAT_ZONE,		"BpaDat_Zone"		,	"", "分区表(ZONE)"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Zone)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Zone)		, MaxBpaDatZone			, BpaDatZone_Offset		,	{	1,	BPA_DAT_ZONE_NAME,				0,							0,								0,	},	dicFieldBpaDat_Zone,		},
	{	BPA_DAT_SUB,		"BpaDat_Sub"		,	"", "BPA厂站表(BPASub)"					, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Sub)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Sub)			, MaxBpaDatSub			, BpaDatSub_Offset		,	{	1,	BPA_DAT_SUB_NAME,				0,							0,								0,	},	dicFieldBpaDat_Sub,			},
	{	BPA_DAT_ACBUS,		"BpaDat_ACBus"		,	"", "节点表(ACBus)"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_ACBus)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_ACBus)		, MaxBpaDatACBus		, BpaDatACBus_Offset	,	{	2,	BPA_DAT_ACBUS_NAME,				BPA_DAT_ACBUS_KV,			0,								0,	},	dicFieldBpaDat_ACBus,		},
	{	BPA_DAT_ACLINE,		"BpaDat_ACLine"		,	"", "交流线路表(ACLine)"				, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_ACLine)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_ACLine)		, MaxBpaDatACLine		, BpaDatACLine_Offset	,	{	1,	BPA_DAT_ACLINE_KEYNAME,			0,							0,								0,	},	dicFieldBpaDat_ACLine,		},
	{	BPA_DAT_LINEHG,		"BpaDat_LineHG"		,	"", "线路高抗表(LineHG)"				, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_LineHG)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_LineHG)		, MaxBpaDatLineHG		, BpaDatLineHG_Offset	,	{	1,	BPA_DAT_LINEHG_KEYNAME,			0,							0,								0,	},	dicFieldBpaDat_LineHG,		},
	{	BPA_DAT_WIND,		"BpaDat_Wind"		,	"", "变压器绕组表(Wind)"				, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Wind)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Wind)		, MaxBpaDatWind			, BpaDatWind_Offset		,	{	1,	BPA_DAT_WIND_KEYNAME,			0,							0,								0,	},	dicFieldBpaDat_Wind,		},
	{	BPA_DAT_DCBUS,		"BpaDat_DCBus"		,	"", "直流母线表(DCBus)"					, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_DCBus)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_DCBus)		, MaxBpaDatDCBus		, BpaDatDCBus_Offset	,	{	2,	BPA_DAT_DCBUS_NAME,				BPA_DAT_DCBUS_KV,			0,								0,	},	dicFieldBpaDat_DCBus,		},
	{	BPA_DAT_DCLINE,		"BpaDat_DCLine"		,	"", "直流线路表(DCLine)"				, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_DCLine)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_DCLine)		, MaxBpaDatDCLine		, BpaDatDCLine_Offset	,	{	1,	BPA_DAT_DCLINE_KEYNAME,			0,							0,								0,	},	dicFieldBpaDat_DCLine,		},
	{	BPA_DAT_R,			"BpaDat_R"			,	"", "带负荷调节变压器控制器表(R)"		, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_R)			/sizeof(tagMemDBField)	, sizeof(tagBpaDat_R)			, MaxBpaDatR			, BpaDatR_Offset		,	{	1,	BPA_DAT_R_KEYNAME,				0,							0,								0,	},	dicFieldBpaDat_R,			},
	{	BPA_DAT_RZ,			"BpaDat_RZ"			,	"", "线路串补表(RZ)"					, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_RZ)			/sizeof(tagMemDBField)	, sizeof(tagBpaDat_RZ)			, MaxBpaDatRZ			, BpaDatRZ_Offset		,	{	1,	BPA_DAT_RZ_KEYNAME,				0,							0,								0,	},	dicFieldBpaDat_RZ,			},
	{	BPA_DAT_P,			"BpaDat_P"			,	"", "发电负荷调整表(P)"					, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_P)			/sizeof(tagMemDBField)	, sizeof(tagBpaDat_P)			, MaxBpaDatP			, BpaDatP_Offset		,	{	1,	BPA_DAT_P_ZONE,					0,							0,								0,	},	dicFieldBpaDat_P,			},
	{	BPA_DAT_ZIL,		"BpaDat_ZIL"		,	"", "小支路清除信息表(ZIL)"				, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_ZIL)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_ZIL)			, MaxBpaDatZIL			, BpaDatZIL_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaDat_ZIL,			},
	{	BPA_DAT_GEN,		"BpaDat_Gen"		,	"", "电网-发电机表"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Gen)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Gen)			, MaxBpaDatGen			, BpaDatGen_Offset		,	{	1,	BPA_DAT_GEN_NAME,				0,							0,								0,	},	dicFieldBpaDat_Gen,			},
	{	BPA_DAT_LOAD,		"BpaDat_Load"		,	"", "电网-负荷表"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Load)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Load)		, MaxBpaDatLoad			, BpaDatLoad_Offset		,	{	1,	BPA_DAT_LOAD_NAME,				0,							0,								0,	},	dicFieldBpaDat_Load,		},
	{	BPA_DAT_TRAN,		"BpaDat_Tran"		,	"", "电网-变压器表"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Tran)		/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Tran)		, MaxBpaDatTran			, BpaDatTran_Offset		,	{	1,	BPA_DAT_TRAN_WINDH,				0,							0,								0,	},	dicFieldBpaDat_Tran,		},
	{	BPA_DAT_EDGELINE,	"BpaDat_EdgeLine"	,	"", "电网边-线路"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_EdgeLine)	/sizeof(tagMemDBField)	, sizeof(tagBpaDat_EdgeLine)	, MaxBpaDatEdgeLine		, BpaDatEdgeLine_Offset	,	{	3,	BPA_DAT_EDGELINE_BUSNAME,		BPA_DAT_EDGELINE_BUSKV,		BPA_DAT_EDGELINE_LINENAME,		0,	},	dicFieldBpaDat_EdgeLine,	},
	{	BPA_DAT_EDGEWIND,	"BpaDat_EdgeWind"	,	"", "电网边-变压器绕组"					, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_EdgeWind)	/sizeof(tagMemDBField)	, sizeof(tagBpaDat_EdgeWind)	, MaxBpaDatEdgeWind		, BpaDatEdgeWind_Offset	,	{	3,	BPA_DAT_EDGEWIND_BUSNAME,		BPA_DAT_EDGEWIND_BUSKV,		BPA_DAT_EDGEWIND_WINDNAME,		0,	},	dicFieldBpaDat_EdgeWind,	},
	{	BPA_DAT_EDGELINEHG,	"BpaDat_EdgeLineHG"	,	"", "电网边-高抗"						, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_EdgeLineHG)	/sizeof(tagMemDBField)	, sizeof(tagBpaDat_EdgeLineHG)	, MaxBpaDatEdgeLineHG	, BpaDatEdgeLineHG_Offset,	{	3,	BPA_DAT_EDGELINEHG_BUSNAME,		BPA_DAT_EDGELINEHG_BUSKV,	BPA_DAT_EDGELINEHG_HGNAME,		0,	},	dicFieldBpaDat_EdgeLineHG,	},
	{	BPA_DAT_RADIATE,	"BpaDat_Radiate"	,	"", "辐射网络"							, BPATableEnum_Dat	, sizeof(dicFieldBpaDat_Radiate)	/sizeof(tagMemDBField)	, sizeof(tagBpaDat_Radiate)		, MaxBpaDatRadiate		, BpaDatRadiate_Offset	,	{	2,	BPA_DAT_RADIATE_BOUNDBUSNAME,	BPA_DAT_RADIATE_BOUNDBUSKV,	0,								0,	},	dicFieldBpaDat_Radiate,		},
	{	BPA_SCC_FMOVE,		"BpaScc_FMove"		,	"", "线路故障点移动计算结果"			, BPATableEnum_Dat	, sizeof(dicFieldBpaScc_FMove)		/sizeof(tagMemDBField)	, sizeof(tagBpaScc_FMove)		, MaxBpaSccFMove		, BpaSccFMove_Offset	,	{	0,	0,								0,							0,								0,	},	dicFieldBpaScc_FMove,		},
	{	BPA_SWI_CASE,		"BpaSwi_Case"		,	"", "稳定计算控制卡(CASE)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_Case)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_Case)		, MaxBpaSwiCase			, BpaSwiCase_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_Case,		},
	{	BPA_SWI_F1,			"BpaSwi_F1"			,	"", "稳定计算控制继续卡(F1)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_F1)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_F1)			, MaxBpaSwiF1			, BpaSwiF1_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_F1,			},
	{	BPA_SWI_F0,			"BpaSwi_F0"			,	"", "监视曲线控制卡(F0)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_F0)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_F0)			, MaxBpaSwiF0			, BpaSwiF0_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_F0,			},
	{	BPA_SWI_FF,			"BpaSwi_FF"			,	"", "稳定计算控制卡(FF)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_FF)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_FF)			, MaxBpaSwiFF			, BpaSwiFF_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_FF,			},
	{	BPA_SWI_GEN,		"BpaSwi_Gen"		,	"", "发电机模型表(MC/MF/MG)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_Gen)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_Gen)			, MaxBpaSwiGen			, BpaSwiGen_Offset		,	{	1,	BPA_SWI_GEN_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_Gen,			},
	{	BPA_SWI_DAMP,		"BpaSwi_Damp"		,	"", "发电机阻尼模型表(M)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_Damp)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_Damp)		, MaxBpaSwiDamp			, BpaSwiDamp_Offset		,	{	1,	BPA_SWI_DAMP_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_Damp,		},
	{	BPA_SWI_WGEGEN,		"BpaSwi_WGEGen"		,	"", "GE风机模型表(WINDG_GE)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_WGEGen)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_WGEGen)		, MaxBpaSwiWGEGen		, BpaSwiWGEGen_Offset	,	{	1,	BPA_SWI_WGEGEN_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_WGEGen,		},
	{	BPA_SWI_GENLN,		"BpaSwi_GenLn"		,	"", "发电机等值负荷(LN)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GenLn)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GenLn)		, MaxBpaSwiGENLN		, BpaSwiGenLN_Offset	,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_GenLn,		},
	{	BPA_SWI_EXCIT68,	"BpaSwi_Exc68"		,	"", "1968年IEEE励磁系统模型表(E)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_Exc68)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_Exc68)		, MaxBpaSwiEXC68		, BpaSwiExc68_Offset	,	{	1,	BPA_SWI_EXCIT68_KEYNAME,		0,							0,								0,	},	dicFieldBpaSwi_Exc68,		},
	{	BPA_SWI_EXCIT81,	"BpaSwi_Exc81"		,	"", "1981年IEEE励磁系统模型表(F)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_Exc81)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_Exc81)		, MaxBpaSwiEXC81		, BpaSwiExc81_Offset	,	{	1,	BPA_SWI_EXCIT81_KEYNAME,		0,							0,								0,	},	dicFieldBpaSwi_Exc81,		},
	{	BPA_SWI_EXCITMV,	"BpaSwi_ExcMV"		,	"", "新励磁系统模型表(FM-FV)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_ExcMV)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_ExcMV)		, MaxBpaSwiEXCMV		, BpaSwiExcMV_Offset	,	{	1,	BPA_SWI_EXCITMV_KEYNAME,		0,							0,								0,	},	dicFieldBpaSwi_ExcMV,		},
	{	BPA_SWI_FZ,			"BpaSwi_FZ"			,	"", "励磁系统继续卡(FZ)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_FZ)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_FZ)			, MaxBpaSwiFZ			, BpaSwiFZ_Offset		,	{	1,	BPA_SWI_FZ_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_FZ,			},
	{	BPA_SWI_FCA,		"BpaSwi_FCA"		,	"", "励磁系统继续卡(F+)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_FCA)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_FCA)			, MaxBpaSwiFCA			, BpaSwiFCA_Offset		,	{	1,	BPA_SWI_FCA_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_FCA,			},
	{	BPA_SWI_FCB,		"BpaSwi_FCB"		,	"", "励磁系统继续卡(F#)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_FCB)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_FCB)			, MaxBpaSwiFCB			, BpaSwiFCB_Offset		,	{	1,	BPA_SWI_FCB_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_FCB,			},
	{	BPA_SWI_EXCITX,		"BpaSwi_ExcX"		,	"", "新励磁系统模型表(FX)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_ExcX)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_ExcX)		, MaxBpaSwiEXCX			, BpaSwiExcTX_Offset	,	{	1,	BPA_SWI_EXCITX_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_ExcX,		},
	{	BPA_SWI_PSSS,		"BpaSwi_PssS"		,	"", "PSS模型表(S)"						, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_PssS)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_PssS)		, MaxBpaSwiPssS			, BpaSwiPssS_Offset		,	{	1,	BPA_SWI_PSSS_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_PssS,		},
	{	BPA_SWI_PSSSH,		"BpaSwi_PssSH"		,	"", "PSS模型SH表(SH)"					, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_PssSH)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_PssSH)		, MaxBpaSwiPssSH		, BpaSwiPssSH_Offset	,	{	1,	BPA_SWI_PSSSH_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_PssSH,		},
	{	BPA_SWI_PSSSI,		"BpaSwi_PssSI"		,	"", "PSS模型SI表(SI)"					, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_PssSI)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_PssSI)		, MaxBpaSwiPssSI		, BpaSwiPssSI_Offset	,	{	1,	BPA_SWI_PSSSI_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_PssSI,		},
	{	BPA_SWI_PSSSA,		"BpaSwi_PssSA"		,	"", "PSS模型SA表(SA)"					, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_PssSA)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_PssSA)		, MaxBpaSwiPssSA		, BpaSwiPssSA_Offset	,	{	1,	BPA_SWI_PSSSA_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_PssSA,		},
	{	BPA_SWI_PSSSB,		"BpaSwi_PssSB"		,	"", "PSS模型SB表(SB)"					, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_PssSB)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_PssSB)		, MaxBpaSwiPssSB		, BpaSwiPssSB_Offset	,	{	1,	BPA_SWI_PSSSB_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_PssSB,		},
	{	BPA_SWI_PSSST,		"BpaSwi_PssST"		,	"", "暂态稳定器表(ST)"					, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_PssST)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_PssST)		, MaxBpaSwiPssST		, BpaSwiPssST_Offset	,	{	1,	BPA_SWI_PSSST_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_PssST,		},
	{	BPA_SWI_GG,			"BpaSwi_GG"			,	"", "调速器和原动机组合模型表(GG)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGG)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGG)		, MaxBpaSwiGG			, BpaSwiGovGG_Offset	,	{	1,	BPA_SWI_GG_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGG,		},
	{	BPA_SWI_GH,			"BpaSwi_GH"			,	"", "水轮机调速器和原动机模型表(GH)"	, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGH)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGH)		, MaxBpaSwiGH			, BpaSwiGovGH_Offset	,	{	1,	BPA_SWI_GH_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGH,		},
	{	BPA_SWI_GC,			"BpaSwi_GC"			,	"", "调速器和原动机组合模型表(GC)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGC)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGC)		, MaxBpaSwiGC			, BpaSwiGovGC_Offset	,	{	1,	BPA_SWI_GC_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGC,		},
	{	BPA_SWI_GS,			"BpaSwi_GS"			,	"", "汽轮机调速模型1表(GS)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGS)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGS)		, MaxBpaSwiGS			, BpaSwiGovGS_Offset	,	{	1,	BPA_SWI_GS_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGS,		},
	{	BPA_SWI_GL,			"BpaSwi_GL"			,	"", "汽轮机调速模型2表(GL)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGL)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGL)		, MaxBpaSwiGL			, BpaSwiGovGL_Offset	,	{	1,	BPA_SWI_GL_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGL,		},
	{	BPA_SWI_GW,			"BpaSwi_GW"			,	"", "水轮机调速模型表(GW)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGW)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGW)		, MaxBpaSwiGW			, BpaSwiGovGW_Offset	,	{	1,	BPA_SWI_GW_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGW,		},
	{	BPA_SWI_GA,			"BpaSwi_GA"			,	"", "电液伺服系统模型表(GA)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGA)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGA)		, MaxBpaSwiGA			, BpaSwiGovGA_Offset	,	{	1,	BPA_SWI_GA_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGA,		},
	{	BPA_SWI_GI,			"BpaSwi_GI"			,	"", "调节系统模型1表(GI)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGI)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGI)		, MaxBpaSwiGI			, BpaSwiGovGI_Offset	,	{	1,	BPA_SWI_GI_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGI,		},
	{	BPA_SWI_GJ,			"BpaSwi_GJ"			,	"", "调节系统模型2表(GJ)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGJ)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGJ)		, MaxBpaSwiGJ			, BpaSwiGovGJ_Offset	,	{	1,	BPA_SWI_GJ_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGJ,		},
	{	BPA_SWI_GK,			"BpaSwi_GK"			,	"", "调节系统模型3表(GK)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGK)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGK)		, MaxBpaSwiGK			, BpaSwiGovGK_Offset	,	{	1,	BPA_SWI_GK_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGK,		},
	{	BPA_SWI_GM,			"BpaSwi_GM"			,	"", "调节系统模型4表(GM)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGM)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGM)		, MaxBpaSwiGM			, BpaSwiGovGM_Offset	,	{	1,	BPA_SWI_GM_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGM,		},
	{	BPA_SWI_GD,			"BpaSwi_GD"			,	"", "电调型(功率反馈)调速器模型表(GD)"	, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGD)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGD)		, MaxBpaSwiGD			, BpaSwiGovGD_Offset	,	{	1,	BPA_SWI_GD_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGD,		},
	{	BPA_SWI_GZ,			"BpaSwi_GZ"			,	"", "电调型(功率反馈)调速器模型表(GZ)"	, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GovGZ)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GovGZ)		, MaxBpaSwiGZ			, BpaSwiGovGZ_Offset	,	{	1,	BPA_SWI_GZ_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GovGZ,		},
	{	BPA_SWI_TA,			"BpaSwi_TA"			,	"", "无再热器汽轮机模型表(TA)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_TA)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MovTA)		, MaxBpaSwiTA			, BpaSwiTA_Offset		,	{	1,	BPA_SWI_TA_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_TA,			},
	{	BPA_SWI_TB,			"BpaSwi_TB"			,	"", "单再热器汽轮机模型表(TB)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_TB)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MovTB)		, MaxBpaSwiTB			, BpaSwiTB_Offset		,	{	1,	BPA_SWI_TB_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_TB,			},
	{	BPA_SWI_TC,			"BpaSwi_TC"			,	"", "双再热器汽轮机模型表(TC)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_TC)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MovTC)		, MaxBpaSwiTC			, BpaSwiTC_Offset		,	{	1,	BPA_SWI_TC_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_TC,			},
	{	BPA_SWI_TD,			"BpaSwi_TD"			,	"", "单再热器汽轮机模型表(TD)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_TD)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MovTD)		, MaxBpaSwiTD			, BpaSwiTD_Offset		,	{	1,	BPA_SWI_TD_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_TD,			},
	{	BPA_SWI_TE,			"BpaSwi_TE"			,	"", "单再热器汽轮机模型表(TE)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_TE)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MovTE)		, MaxBpaSwiTE			, BpaSwiTE_Offset		,	{	1,	BPA_SWI_TE_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_TE,			},
	{	BPA_SWI_TF,			"BpaSwi_TF"			,	"", "双再热器汽轮机模型表(TF)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_TF)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MovTF)		, MaxBpaSwiTF			, BpaSwiTF_Offset		,	{	1,	BPA_SWI_TF_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_TF,			},
	{	BPA_SWI_TW,			"BpaSwi_TW"			,	"", "水轮机模型表(TW)"					, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_TW)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MovTW)		, MaxBpaSwiTW			, BpaSwiTW_Offset		,	{	1,	BPA_SWI_TW_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_TW,			},
	{	BPA_SWI_GX,			"BpaSwi_GX"			,	"", "锅炉的主汽压力变化模型表(GX)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_GX)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_GX)			, MaxBpaSwiGX			, BpaSwiGX_Offset		,	{	1,	BPA_SWI_GX_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_GX,			},
	{	BPA_SWI_IGV,		"BpaSwi_IGV"		,	"", "修改调速器频率参考信息表(IGV)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_IGV)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_IGV)			, MaxBpaSwiIGV			, BpaSwiIGV_Offset		,	{	1,	BPA_SWI_IGV_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_IGV,			},
	{	BPA_SWI_FGV,		"BpaSwi_FGV"		,	"", "发电机机械功率周期波动表(FGV)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_FGV)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_FGV)			, MaxBpaSwiFGV			, BpaSwiFGV_Offset		,	{	1,	BPA_SWI_FGV_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_FGV,			},

	{	BPA_SWI_LO,			"BpaSwi_LO"			,	"", "线路零序参数模型(LO)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_LO)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_LO)			, MaxBpaSwiLO			, BpaSwiLO_Offset		,	{	1,	BPA_SWI_LO_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_LO,			},
	{	BPA_SWI_XO,			"BpaSwi_XO"			,	"", "变压器零序模型(XO)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_XO)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_XO)			, MaxBpaSwiXO			, BpaSwiXO_Offset		,	{	1,	BPA_SWI_XO_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_XO,			},
	{	BPA_SWI_LOHG,		"BpaSwi_LOHG"		,	"", "线路高抗零序参数模型(LOHG)"		, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_LOHG)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_LOHG)		, MaxBpaSwiLOHG			, BpaSwiLOHG_Offset		,	{	1,	BPA_SWI_LOHG_KEYNAME,			0,							0,								0,	},	dicFieldBpaSwi_LOHG,		},
	{	BPA_SWI_XR,			"BpaSwi_XR"			,	"", "对地支路零序模型(XR)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_XR)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_XR)			, MaxBpaSwiXR			, BpaSwiXR_Offset		,	{	2,	BPA_SWI_XR_NAME,				BPA_SWI_XR_KV,				0,								0,	},	dicFieldBpaSwi_XR,		},

	{	BPA_SWI_D,			"BpaSwi_D"			,	"", "直流控制系统模型(D)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_D)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_D)			, MaxBpaSwiD			, BpaSwiD_Offset		,	{	1,	BPA_SWI_D_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_D,			},
	{	BPA_SWI_V,			"BpaSwi_V"			,	"", "静止无功补偿器(SVC)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_V)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_V)			, MaxBpaSwiV			, BpaSwiV_Offset		,	{	1,	BPA_SWI_V_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_V,			},
	{	BPA_SWI_VG,			"BpaSwi_VG"			,	"", "静止无功发生器(STATCOM)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_VG)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_VG)			, MaxBpaSwiVG			, BpaSwiVG_Offset		,	{	1,	BPA_SWI_VG_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_VG,			},
	{	BPA_SWI_LAB,		"BpaSwi_LAB"		,	"", "静态负荷模型表(LA/LB)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_LAB)		/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_LAB)			, MaxBpaSwiLAB			, BpaSwiLAB_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_LAB,			},
	{	BPA_SWI_MI,			"BpaSwi_MI"			,	"", "感应马达模型(MI)"					, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_MI)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MI)			, MaxBpaSwiMI			, BpaSwiMI_Offset		,	{	2,	BPA_SWI_MI_BUS_NAME,			BPA_SWI_MI_BUS_KV,			0,								0,	},	dicFieldBpaSwi_MI,			},
	{	BPA_SWI_ML,			"BpaSwi_ML"			,	"", "新感应马达模型(ML)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_ML)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_ML)			, MaxBpaSwiML			, BpaSwiML_Offset		,	{	2,	BPA_SWI_ML_BUS_NAME,			BPA_SWI_ML_BUS_KV,			0,								0,	},	dicFieldBpaSwi_ML,			},
	{	BPA_SWI_MJ,			"BpaSwi_MJ"			,	"", "新感应马达模型(MJ)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_MJ)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MJ)			, MaxBpaSwiMJ			, BpaSwiMJ_Offset		,	{	1,	BPA_SWI_MJ_ZONE_NAME,			0,							0,								0,	},	dicFieldBpaSwi_MJ,			},
	{	BPA_SWI_MK,			"BpaSwi_MK"			,	"", "新感应马达模型(MK)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_MK)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_MK)			, MaxBpaSwiMK			, BpaSwiMK_Offset		,	{	1,	BPA_SWI_MK_AREA_NAME,			0,							0,								0,	},	dicFieldBpaSwi_MK,			},
	//{	BPA_SWI_LM,			"BpaSwi_LM"			,	"", "线路零序互感参数模型(LM)"			, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_LM)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_LM)			, MaxBpaSwiLM			, BPASWILM_Offset		,	{	1,	BPA_SWI_LM_KEYNAME,				0,							0,								0,	},	dicFieldBpaSwi_LM,			},
	{	BPA_SWI_UF,			"BpaSwi_UF"			,	"", "自动减负荷模型(UF)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_UF)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_UF)			, MaxBpaSwiUF			, BpaSwiUF_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_UF,			},
	{	BPA_SWI_UV,			"BpaSwi_UV"			,	"", "自动减负荷模型(UV)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_UV)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_UV)			, MaxBpaSwiUV			, BpaSwiUV_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_UV,			},
	{	BPA_SWI_RE,			"BpaSwi_RE"			,	"", "发电机电压保护(RE)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_RE)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_RE)			, MaxBpaSwiRE			, BpaSwiRE_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_RE,			},
	{	BPA_SWI_RW,			"BpaSwi_RW"			,	"", "发电机转速保护(RW)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_RW)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_RW)			, MaxBpaSwiRW			, BpaSwiRW_Offset		,	{	0,	0,								0 ,							0,								0,	},	dicFieldBpaSwi_RW,			},
	{	BPA_SWI_RA,			"BpaSwi_RA"			,	"", "低压线路断开保护(RA)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_RA)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_RA)			, MaxBpaSwiRA			, BpaSwiRA_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_RA,			},
	{	BPA_SWI_RU,			"BpaSwi_RU"			,	"", "低频线路断开保护(RU)"				, BPATableEnum_Swi	, sizeof(dicFieldBpaSwi_RU)			/sizeof(tagMemDBField)	, sizeof(tagBpaSwi_RU)			, MaxBpaSwiRU			, BpaSwiRU_Offset		,	{	0,	0,								0,							0,								0,	},	dicFieldBpaSwi_RU,			},
};

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
