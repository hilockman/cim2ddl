#pragma	once

#include "../include/MDBDefine.h"

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

const	int		BpaDatCategory_Dat=0;	//	BPA潮流数据类型数据
const	int		BpaDatCategory_Con=2;	//	BPA潮流控制类型数据
const	int		BpaSwiCategory_Dat=1;	//	BPA稳定数据类型数据
const	int		BpaSwiCategory_Con=3;	//	BPA稳定控制类型数据

//	数据库中字段枚举值定义
enum	_BpaEnum_Scc_FaultType_
{
	BpaEnum_Scc_FaultType1=0,
	BpaEnum_Scc_FaultType2,
	BpaEnum_Scc_FaultType3,
	BpaEnum_Scc_FaultType4,
};

enum	_BpaEnum_Scc_FMoveDataType_
{
	BpaEnum_Scc_FMoveDataType_FC_I1Re=0,
	BpaEnum_Scc_FMoveDataType_FC_I1Im,
	BpaEnum_Scc_FMoveDataType_FC_I2Re,
	BpaEnum_Scc_FMoveDataType_FC_I2Im,
	BpaEnum_Scc_FMoveDataType_FC_I0Re,
	BpaEnum_Scc_FMoveDataType_FC_I0Im,
	BpaEnum_Scc_FMoveDataType_FC_Z1Re,
	BpaEnum_Scc_FMoveDataType_FC_Z1Im,
	BpaEnum_Scc_FMoveDataType_FC_Z2Re,
	BpaEnum_Scc_FMoveDataType_FC_Z2Im,
	BpaEnum_Scc_FMoveDataType_FC_Z0Re,
	BpaEnum_Scc_FMoveDataType_FC_Z0Im,
	BpaEnum_Scc_FMoveDataType_MC_I1Re,
	BpaEnum_Scc_FMoveDataType_MC_I1Im,
	BpaEnum_Scc_FMoveDataType_MC_I2Re,
	BpaEnum_Scc_FMoveDataType_MC_I2Im,
	BpaEnum_Scc_FMoveDataType_MC_I0Re,
	BpaEnum_Scc_FMoveDataType_MC_I0Im,
	BpaEnum_Scc_FMoveDataType_MC_Z1Re,
	BpaEnum_Scc_FMoveDataType_MC_Z1Im,
	BpaEnum_Scc_FMoveDataType_MC_Z2Re,
	BpaEnum_Scc_FMoveDataType_MC_Z2Im,
	BpaEnum_Scc_FMoveDataType_MC_Z0Re,
	BpaEnum_Scc_FMoveDataType_MC_Z0Im,
	BpaEnum_Scc_FMoveDataType_MV_1Re,
	BpaEnum_Scc_FMoveDataType_MV_1Im,
	BpaEnum_Scc_FMoveDataType_MV_2Re,
	BpaEnum_Scc_FMoveDataType_MV_2Im,
	BpaEnum_Scc_FMoveDataType_MV_0Re,
	BpaEnum_Scc_FMoveDataType_MV_0Im,
};

enum	_BpaEnum_PssSI_INPStatus_
{
	PssSI_INPStatus_WPG=0,
	PssSI_INPStatus_W,
	PssSI_INPStatus_PG,
};
enum	_BpaEnumPssSI_IBStatus_
{
	PssSI_INPStatus_dV=0,
	PssSI_INPStatus_dF,
	PssSI_INPStatus_EQ_dF,
};
enum	_BpaEnumGK_FilterDead_
{
	GK_FilterDead_Dead=0,
	GK_FilterDead_Filter,
};
enum	_BpaEnumGM_OpenMode_
{
	GM_OpenMode_Y=0,
	GM_OpenMode_YPID,
};
enum	_BpaEnumGZ_ControlMode_
{
	GZ_ControlMode_Speed=0,
	GZ_ControlMode_SpeedAndP,
	GZ_ControlMode_SpeedAndMP,
};
enum	_BpaEnumCase_AIControl_
{
	Case_AIControl_CON=0,
	Case_AIControl_MON,
	Case_AIControl_OFF,
};
enum	_BpaEnumCase_LTC_
{
	Case_LTC_ON=0,
	Case_LTC_ON_NV,
	Case_LTC_ON_NPS,
	Case_LTC_OFF,
	Case_LTC_ON_DCONLY,
};

enum	_BpaEnumFF_IM_
{
	FF_IM_STOP=0,
	FF_IM_STALL,
	FF_IM_TRIP,
};

enum	_BpaEnumMotor_KlS0_
{
	Motor_KLS0_KL=0,
	Motor_KLS0_S0,
};

enum	_BpaEnumMotor_IM_
{
	Motor_IM_NONE=0,
	Motor_IM_STOP,
	Motor_IM_STALL,
	Motor_IM_TRIP,
};

//	数据库字段相关定义
enum	_BpaMDBEnum_DatField_Case_
{
	BPA_DAT_CASE_CASEID=0,
	BPA_DAT_CASE_PROJECT,
	BPA_DAT_CASE_MVABASE,
	BPA_DAT_CASE_CONTROL,
	BPA_DAT_CASE_BRANCH,
	BPA_DAT_CASE_BUS,
	BPA_DAT_CASE_NETWORK,
	BPA_DAT_CASE_RXCHECK,
	BPA_DAT_CASE_NEWBASE,
	BPA_DAT_CASE_OLDBASE,
	BPA_DAT_CASE_MAP,
	BPA_DAT_CASE_AICONTROL,
	BPA_DAT_CASE_LTC,
	BPA_DAT_CASE_DECOUPLEDNUM,
	BPA_DAT_CASE_CURRENTNUM,
	BPA_DAT_CASE_NEWTONNUM,
	BPA_DAT_CASE_OPTIMNUM,
	BPA_DAT_CASE_TOLERANCEBUSV,
	BPA_DAT_CASE_TOLERANCEAIPOWER,
	BPA_DAT_CASE_TOLERANCETX,
	BPA_DAT_CASE_TOLERANCEQ,
	BPA_DAT_CASE_TOLERANCEOPCUT,
// 	BPA_DAT_CASE_INPUTLIST,
 	BPA_DAT_CASE_RPTSORT,
 	BPA_DAT_CASE_ANALYSISRPT,
// 	BPA_DAT_CASE_AILISTCONTROL,
// 	BPA_DAT_CASE_LINELOSS,
// 	BPA_DAT_CASE_TRANSFORMERLOSS,
	BPA_DAT_ISLANDNUM,
	BPA_DAT_TOTGENP,
	BPA_DAT_TOTGENQ,
	BPA_DAT_TOTLOADP,
	BPA_DAT_TOTLOADQ,
	BPA_DAT_TOTLINECAP,
	BPA_DAT_TOTLOSSP,
	BPA_DAT_TOTLOSSQ,
	BPA_DAT_TOTDCLOSS,
};

struct	_BpaMDBDat_Case_
{
	char		szCaseID[MDB_CHARLEN];				//	潮流方式名
	char		szProject[MDB_CHARLEN];				//	工程名
	float		fMVABase;							//	指定的系统基准容量
	char		szControl[MDB_CHARLEN];				//	所指定的控制语句文件
	char		szBranch[MDB_CHARLEN];				//	所指定的支路数据
	char		szBus[MDB_CHARLEN]; 				//	所指定的母线数据
	char		szNetwork[MDB_CHARLEN]; 			//	所指定的数据文件
	short		nRXCheck;							//	RX比值检查
	char		szNewBase[MDB_CHARLEN]; 			//	潮流结果二进制文件（.BSE）
	char		szOldBase[MDB_CHARLEN]; 			//	指定老库文件
	char		szMap[MDB_CHARLEN]; 				//	生成潮流图二进制结果文件
	unsigned char	nAIControl;						//	区域联络线功率控制选择
	unsigned char	nLTC;							//	带负荷调压变压器控制选择
	short		nDecoupledNum;						//	PQ解耦法
	short		nCurrentNum;						//	改进的牛顿拉夫逊算法
	short		nNewtonNum;							//	牛顿拉夫逊算法
	short		nOptimNum;							//	最优潮流法
	float		fToleranceBusV;						//	BusV允许误差，缺省值：0.005
	float		fToleranceAIPower;					//	AIPower允许误差，缺省值：0.005
	float		fToleranceTX;						//	TX允许误差，缺省值：0.005
	float		fToleranceQ;						//	Q允许误差，缺省值：0.005
	float		fToleranceOpcut;					//	OPCUT允许误差，缺省值：0.0001
// 	short		nInputList;							//	输入的原始数据输出
 	short		nRptSort;							//	输出分类，输出顺序控制语句
 	short		nAnalysisRpt;						//	分析报告输出，指定输出等级
// 	short		nAIListControl;						//	区域功率交换数据输出
// 	short		nLineLoss;							//	线路损耗输出
// 	short		nTransformerLoss;					//	变压器支路损耗输出
	short		nIslandNum;
	float		fTotGenP;
	float		fTotGenQ;
	float		fTotLoadP;
	float		fTotLoadQ;
	float		fTotLineCap;
	float		fTotLossP;
	float		fTotLossQ;
	float		fTotDCLoss;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Case_	tagBpaDat_Case;

enum	_BpaMDBEnum_DatField_Area_
{
	BPA_DAT_AREA_NAME=0,
	BPA_DAT_AREA_CARDKEY,
	BPA_DAT_AREA_SLACKBUSNAME,
	BPA_DAT_AREA_SLACKBUSKV,
	BPA_DAT_AREA_OUTP,

	BPA_DAT_MK_TJ,
	BPA_DAT_MK_PPER,
	BPA_DAT_MK_KL,
	BPA_DAT_MK_PMIN,
	BPA_DAT_MK_RS,
	BPA_DAT_MK_XS,
	BPA_DAT_MK_XM,
	BPA_DAT_MK_RR,
	BPA_DAT_MK_XR,
	BPA_DAT_MK_VI,
	BPA_DAT_MK_TI,
	BPA_DAT_MK_A,
	BPA_DAT_MK_B,
	BPA_DAT_MK_IM,
};

struct	_BpaMDBDat_Area_
{
	char		szName[MDB_CHARLEN_SHORTER];
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szSlackBusName[MDB_CHARLEN_BPABUS];
	float		fSlackBuskV;
	float		fOutP;

	float		fTJ;
	float		fPper;
	float		fKL;
	float		fPmin;
	float		fRS;
	float		fXS;
	float		fXM;
	float		fRR;
	float		fXR;
	float		fVI;
	float		fTI;
	float		fA;
	float		fB;
	unsigned char	bIM;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Area_	tagBpaDat_Area;

enum	_BpaMDBEnum_DatField_I_
{
	BPA_DAT_I_CARDKEY=0,
	BPA_DAT_I_AREA1,
	BPA_DAT_I_AREA2,
	BPA_DAT_I_OUTP,
};

struct	_BpaMDBDat_I_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char		szArea1[MDB_CHARLEN_SHORTER];
	char		szArea2[MDB_CHARLEN_SHORTER];
	float		fOutP;
}	DISALIGN;
typedef	struct	_BpaMDBDat_I_	tagBpaDat_I;

enum	_BpaMDBEnum_DatField_Zone_
{
	BPA_DAT_ZONE_NAME=0,
	BPA_DAT_ZONE_AREA,
	BPA_DAT_ZONE_CARDKEY,

	BPA_DAT_ZONE_KG0,
	BPA_DAT_ZONE_KB0,
	BPA_DAT_ZONE_KGC0,
	BPA_DAT_ZONE_KBC0,
	BPA_DAT_ZONE_VMIN,
	BPA_DAT_ZONE_VMAX,

	BPA_DAT_MJ_TJ,
	BPA_DAT_MJ_PPER,
	BPA_DAT_MJ_KL,
	BPA_DAT_MJ_PMIN,
	BPA_DAT_MJ_RS,
	BPA_DAT_MJ_XS,
	BPA_DAT_MJ_XM,
	BPA_DAT_MJ_RR,
	BPA_DAT_MJ_XR,
	BPA_DAT_MJ_VI,
	BPA_DAT_MJ_TI,
	BPA_DAT_MJ_A,
	BPA_DAT_MJ_B,
	BPA_DAT_MJ_IM,
};

struct	_BpaMDBDat_Zone_
{
	char		szName[MDB_CHARLEN_SHORTEST/2];			//	分区名称
	char		szArea[MDB_CHARLEN_SHORTER];			//	区域名称
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	float		fKG0;									//	51	55	F5.4	线路零序电导相对于正序电导的倍数
	float		fKB0;									//	56	60	F5.4	线路零序电纳相对于正序电纳的倍数
	float		fKGC0;									//	61	65	F5.4	线路对地支路零序电导相对于对地支路正序电导的倍数
	float		fKBC0;									//	66	70	F5.4	线路对地支路零序电纳相对于对地支路正序电纳的倍数
	float		fVMIN;									//	71	75	F5.1	电压等级限制最小值
	float		fVMAX;									//	76	80	F5.1	电压等级限制最大值

	float		fTJ;
	float		fPper;
	float		fKL;
	float		fPmin;
	float		fRS;
	float		fXS;
	float		fXM;
	float		fRR;
	float		fXR;
	float		fVI;
	float		fTI;
	float		fA;
	float		fB;
	unsigned char	bIM;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Zone_	tagBpaDat_Zone;

enum	_BpaMDBEnum_DatField_Sub_
{
	BPA_DAT_SUB_NAME=0,
	BPA_DAT_SUB_ALIAS,
	BPA_DAT_SUB_TYPE,
	BPA_DAT_SUB_GENP,
	BPA_DAT_SUB_GENQ,
	BPA_DAT_SUB_LOADP,
	BPA_DAT_SUB_LOADQ,
	BPA_DAT_SUB_SHUNTQ,
};

struct	_BpaMDBDat_Sub_
{
	char	szName[MDB_CHARLEN_BPABUS];		//	厂站名称
//	char	szDesp[MDB_CHARLEN];			//	厂站描述
//	char	szZone[MDB_CHARLEN_SHORTER];	//	厂站名称
	char	szAlias[MDB_CHARLEN_SHORT];		//	关联厂站
	unsigned char	nSubType;
	float	fGenP;
	float	fGenQ;
	float	fLoadP;
	float	fLoadQ;
	float	fShuntQ;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Sub_	tagBpaDat_Sub;

enum	_BpaMDBEnum_DatField_ACBus_
{
	BPA_DAT_ACBUS_CARDKEY=0,
	//BPA_DAT_ACBUS_CHGCODE,
	BPA_DAT_ACBUS_OWNER,
	BPA_DAT_ACBUS_NAME,
	BPA_DAT_ACBUS_KV,
	BPA_DAT_ACBUS_ZONE,
	BPA_DAT_ACBUS_PLOAD,
	BPA_DAT_ACBUS_QLOAD,
	BPA_DAT_ACBUS_PSHUNT,
	BPA_DAT_ACBUS_QSHUNT,
	BPA_DAT_ACBUS_PMAX,
	BPA_DAT_ACBUS_PGEN,
	BPA_DAT_ACBUS_QSCHED_QMAX,
	BPA_DAT_ACBUS_QMIN,
	BPA_DAT_ACBUS_VHOLD_MAX,
	BPA_DAT_ACBUS_VMIN,
	BPA_DAT_ACBUS_RBUSNAME,
	BPA_DAT_ACBUS_RBUSVOLT,
	BPA_DAT_ACBUS_VARSPPLD,

	BPA_DAT_ACBUS_ADDCODE,	
	BPA_DAT_ACBUS_ADDPLOAD,	
	BPA_DAT_ACBUS_ADDQLOAD,	
	BPA_DAT_ACBUS_ADDPSHUNT,
	BPA_DAT_ACBUS_ADDQSHUNT,
	BPA_DAT_ACBUS_ADDPGEN,	
	BPA_DAT_ACBUS_ADDQGEN,	

	BPA_DAT_ACBUS_SUB,
	BPA_DAT_ACBUS_ALIAS,
	BPA_DAT_ACBUS_V,
	BPA_DAT_ACBUS_D,

	BPA_DAT_ACBUS_PFOPGEN,
	BPA_DAT_ACBUS_PFOQGEN,
	BPA_DAT_ACBUS_PFOPLOAD,
	BPA_DAT_ACBUS_PFOQLOAD,
	BPA_DAT_ACBUS_PFOQSHUNT,
	BPA_DAT_ACBUS_PFOPNET,
	BPA_DAT_ACBUS_PFOQNET,

	BPA_DAT_ACBUS_VD_RERR,
	BPA_DAT_ACBUS_VD_RSCC1,
	BPA_DAT_ACBUS_VD_RSCC2,
	BPA_DAT_ACBUS_VD_RSCC3,
	BPA_DAT_ACBUS_VD_RSCC4,

	BPA_DAT_ACBUS_RTGENP,
	BPA_DAT_ACBUS_RTGENQ,
	BPA_DAT_ACBUS_RTLOADP,
	BPA_DAT_ACBUS_RTLOADQ,
	BPA_DAT_ACBUS_RTSHUNTQ,
	BPA_DAT_ACBUS_RTVHOLD,

	BPA_DAT_ACBUS_SCCA,
	BPA_DAT_ACBUS_SCCV,
	BPA_DAT_ACBUS_SCCR1,
	BPA_DAT_ACBUS_SCCX1,
	BPA_DAT_ACBUS_SCCR2,
	BPA_DAT_ACBUS_SCCX2,
	BPA_DAT_ACBUS_SCCR0,
	BPA_DAT_ACBUS_SCCX0,
	BPA_DAT_ACBUS_SCCA1RE,
	BPA_DAT_ACBUS_SCCA1IM,
	BPA_DAT_ACBUS_SCCA2RE,
	BPA_DAT_ACBUS_SCCA2IM,
	BPA_DAT_ACBUS_SCCA0RE,
	BPA_DAT_ACBUS_SCCA0IM,
	BPA_DAT_ACBUS_SCCV1RE,
	BPA_DAT_ACBUS_SCCV1IM,
	BPA_DAT_ACBUS_SCCV2RE,
	BPA_DAT_ACBUS_SCCV2IM,
	BPA_DAT_ACBUS_SCCV0RE,
	BPA_DAT_ACBUS_SCCV0IM,
	BPA_DAT_ACBUS_VDIPBUS1,
	BPA_DAT_ACBUS_VDIPBUS2,
	BPA_DAT_ACBUS_VDIPBUS3,
	BPA_DAT_ACBUS_VDIPBUS4,

	BPA_DAT_ACBUS_INIPLOAD,
	BPA_DAT_ACBUS_INIQLOAD,
	BPA_DAT_ACBUS_INIPSHUNT,
	BPA_DAT_ACBUS_INIQSHUNT,
	BPA_DAT_ACBUS_INIPGEN,
	BPA_DAT_ACBUS_INIQGEN,

	BPA_DAT_ACBUS_TMID,
	BPA_DAT_ACBUS_GENERATOR,
	BPA_DAT_ACBUS_WTGEN,
	BPA_DAT_ACBUS_PVGEN,
	BPA_DAT_ACBUS_DCBOUND,
	BPA_DAT_ACBUS_GENLN,
	BPA_DAT_ACBUS_STATUS,
	BPA_DAT_ACBUS_REDCUTION,
	BPA_DAT_ACBUS_INRING,
	BPA_DAT_ACBUS_RADIATE,

	BPA_DAT_ACBUS_ACISLAND,
	BPA_DAT_ACBUS_PRLINE,
	BPA_DAT_ACBUS_PRTRAN,
	BPA_DAT_ACBUS_PRHG,
	BPA_DAT_ACBUS_PRSUB,
};

struct	_BpaMDBDat_ACBus_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];	//1		2	A1	子类型
	//char	cChgCode;							//3		3	A1	修改码
	char	szOwner[MDB_CHARLEN_SHORTEST/2];	//4		6	A3	所有者
	char	szName[MDB_CHARLEN_BPABUS];			//7		14	A8	母线名称
	float	fkV;								//15	18	F4.0基准电压(kV)
	char	szZone[MDB_CHARLEN_SHORTEST/2];		//19	20	A2		Zone，分区名
	float	fLoadP;								//21	25	F5.0恒定有功负荷(MW)
	float	fLoadQ;								//26	30	F5.0恒定无功负荷(MVAR)，+表示感性
	float	fShuntP;							//31	34	F4.0并联导纳有功负荷(MW)
	float	fShuntQ;							//35	38	F4.0并联导纳无功负荷(MVAR)，+表容性
	float	fPmax;								//39	42	F4.0最大有功出力Pmax(MW)
	float	fPGen;								//43	47	F5.0实际有功出力PGen(MW)
	float	fQsched_Qmax;						//48	52	F5.0安排的无功出力值，+表容性
	float	fQmin;								//53	57	F5.0无功出力最小值(MVAR)，此处填0
	float	fVHold_max;							//58	61	F4.3安排的电压值或Vmax(标么值)
	float	fVmin;								//62	65	F4.3安排的Vmin(标么值)
	char	szRBusName[MDB_CHARLEN_BPABUS];		//66	73	A8	远方要控制的母线名称
	float	fRBusVolt;							//74	77	F4.0远方要控制的基准电压(kV)
	float	fVarSppld;							//78	80	F3.0提供的无功功率百分数(%)


	char	szAddCode[MDB_CHARLEN_SHORTEST/2];	//19,	20	A2		负荷模型类型子代码
	float	fzAddLoadP;							//21,	25	F5.0	恒定有功负荷(MW)
	float	fzAddLoadQ;							//26,	30	F5.0	恒定无功负荷(MVAR)，+表示感性
	float	fzAddShuntP;						//31,	34	F4.0	并联导纳有功负荷(MW)
	float	fzAddShuntQ;						//35,	38	F4.0	并联导纳无功负荷(MVAR)，+表容性
	float	fzAddPGen;							//43,	47	F5.0	实际有功出力PGen(MW)
	float	fzAddQGen;							//48,	52	F5.0	实际无功出力QGen(MVAR)

	char	szBpaSub[MDB_CHARLEN_BPABUS];
	char	szAlias[MDB_CHARLEN];
	float	fV;
	float	fD;

	float	fPfoPGen;
	float	fPfoQGen;
	float	fPfoPLoad;
	float	fPfoQLoad;
	float	fPfoQShunt;
	float	fPfoPNet;
	float	fPfoQNet;

	double	vd_Rerr;
	float	vd_RScc1;
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;

	float	fRtGenP;
	float	fRtGenQ;
	float	fRtLoadP;
	float	fRtLoadQ;
	float	fRtShuntQ;
	float	fRtVHold;

	float	fSccA;
	float	fSccV;
	float	fSccR1;
	float	fSccX1;
	float	fSccR2;
	float	fSccX2;
	float	fSccR0;
	float	fSccX0;
	float	fSccA1Re;
	float	fSccA1Im;
	float	fSccA2Re;
	float	fSccA2Im;
	float	fSccA0Re;
	float	fSccA0Im;
	float	fSccV1Re;
	float	fSccV1Im;
	float	fSccV2Re;
	float	fSccV2Im;
	float	fSccV0Re;
	float	fSccV0Im;
	int		nVDipBus1;
	int		nVDipBus2;
	int		nVDipBus3;
	int		nVDipBus4;

	float	fIniLoadP;		
	float	fIniLoadQ;		
	float	fIniShuntP;		
	float	fIniShuntQ;		
	float	fIniPGen;		
	float	fIniQGen;		

	unsigned char	bTMid;
	unsigned char	bGenerator;
	unsigned char	bWTGen;
	unsigned char	bPVGen;
	unsigned char	bDCBound;
	unsigned char	bGenLn;
	unsigned char	nStatus;
	unsigned char	bRedcution;
	unsigned char	bInRing;
	short			nRadiate;

	short	nACIsland;
	int		nACLineRange;
	int		nWindRange;
	short	nLineHGRange;
	int		nSubPtr;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACBus_	tagBpaDat_ACBus;

enum _BpaMDBEnum_DatField_ACLine_
{
	BPA_DAT_ACLINE_CARDKEY=0,
	//BPA_DAT_ACLINE_CHGCODE,
	BPA_DAT_ACLINE_OWNER,
	BPA_DAT_ACLINE_BUSI,
	BPA_DAT_ACLINE_KVI,
	BPA_DAT_ACLINE_METER,
	BPA_DAT_ACLINE_BUSJ,
	BPA_DAT_ACLINE_KVJ,
	BPA_DAT_ACLINE_LOOP,
	BPA_DAT_ACLINE_SECTION,
	BPA_DAT_ACLINE_AMP,
	BPA_DAT_ACLINE_LOOPNUM,
	BPA_DAT_ACLINE_R,
	BPA_DAT_ACLINE_X,
	BPA_DAT_ACLINE_G1,
	BPA_DAT_ACLINE_B1,
	BPA_DAT_ACLINE_G2,
	BPA_DAT_ACLINE_B2,
	BPA_DAT_ACLINE_MILES,
	//BPA_DAT_ACLINE_COMMENT,

	BPA_DAT_ACLINE_VD_RERR,
	BPA_DAT_ACLINE_VD_RSCC1,
	BPA_DAT_ACLINE_VD_RSCC2,
	BPA_DAT_ACLINE_VD_RSCC3,
	BPA_DAT_ACLINE_VD_RSCC4,

	BPA_DAT_ACLINE_PI,
	BPA_DAT_ACLINE_QI,
	BPA_DAT_ACLINE_PZ,
	BPA_DAT_ACLINE_QZ,
	BPA_DAT_ACLINE_LOSSP,
	BPA_DAT_ACLINE_LOSSQ,

	BPA_DAT_ACLINE_SCCA,
	BPA_DAT_ACLINE_VDIPBUS1,
	BPA_DAT_ACLINE_VDIPBUS2,
	BPA_DAT_ACLINE_VDIPBUS3,
	BPA_DAT_ACLINE_VDIPBUS4,

	BPA_DAT_ACLINE_KEYNAME,
	BPA_DAT_ACLINE_INIBUSI,
	BPA_DAT_ACLINE_INIKVI,
	BPA_DAT_ACLINE_INIBUSJ,
	BPA_DAT_ACLINE_INIKVJ,
	BPA_DAT_ACLINE_INILOOP,
	BPA_DAT_ACLINE_BUSIPTR,
	BPA_DAT_ACLINE_BUSJPTR,
	BPA_DAT_ACLINE_ALIAS,
	BPA_DAT_ACLINE_STATUS,
	BPA_DAT_ACLINE_INRING,
	BPA_DAT_ACLINE_RADIATE,
};
struct	_BpaMDBDat_ACLine_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2		CARD TYPE
	//char			cChgCode;						//	3	3	A1		修改码
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3		所有者
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float			fkVI;							//	15	18	F4.0	基准电压1(kV)
	char			cMeter;							//	19	19	I1		区域联络线测点标志
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float			fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char			cLoop;							//	32	32	A1		并联线路的回路标志
	unsigned char	bSection;						//	33	33	I1		分段串连而成的线路的段号
	float			fAMP;							//	34	37	F4.0	线路额定电流(安培)
	unsigned char	bLoopNum;						//	38	38	I1		并联线路数目
	float			fR;								//	39	44	F6.5	电阻标么值
	float			fX;								//	45	50	F6.5	电抗标么值
	float			fG1;							//	51	56	F6.5	线路母线1端对地电导标么值(G/2)
	float			fB1;							//	57	62	F6.5	线路母线1端对地电纳标么值(B/2)
	float			fG2;							//	63	68	F6.5	线路母线2端对地电导标么值(G/2)
	float			fB2;							//	69	74	F6.5	线路母线2端对地电纳标么值(B/2)
	float			fMiles;							//	63	66	F4.1	线路或段的长度
	//char			szComment[MDB_CHARLEN_SHORTER];	//	67	74	A8		线路的说明数据

	double			vd_Rerr;
	float			vd_RScc1;
	float			vd_RScc2;
	float			vd_RScc3;
	float			vd_RScc4;

	float			fPi;
	float			fQi;
	float			fPz;
	float			fQz;
	float			fLossP;
	float			fLossQ;

	float			fSccA;
	int				nVDipBus1;
	int				nVDipBus2;
	int				nVDipBus3;
	int				nVDipBus4;

	char			szKeyName[MDB_CHARLEN_SHORT];
	char			szIniBusI[MDB_CHARLEN_BPABUS];
	float			fInikVI;
	char			szIniBusJ[MDB_CHARLEN_BPABUS];
	float			fInikVJ;
	char			cIniLoop;
	int				nIBus;
	int				nZBus;
	char			szAlias[MDB_CHARLEN];
	unsigned char	nStatus;
	unsigned char	bInRing;
	short			nRadiate;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACLine_	tagBpaDat_ACLine;

enum _BpaMDBEnum_DatField_LineHG_
{
	BPA_DAT_LINEHG_CARDKEY=0,
	BPA_DAT_LINEHG_BUSI,
	BPA_DAT_LINEHG_KVI,
	BPA_DAT_LINEHG_BUSJ,
	BPA_DAT_LINEHG_KVJ,
	BPA_DAT_LINEHG_LOOP,
	BPA_DAT_LINEHG_SHUNTI,
	BPA_DAT_LINEHG_SHUNTJ,
	BPA_DAT_LINEHG_KEYNAME,
	BPA_DAT_LINEHG_INIBUSI,
	BPA_DAT_LINEHG_INIKVI,
	BPA_DAT_LINEHG_INIBUSJ,
	BPA_DAT_LINEHG_INIKVJ,
	BPA_DAT_LINEHG_INILOOP,
	BPA_DAT_LINEHG_BUSPTR,
	BPA_DAT_LINEHG_ZRBUS,
	BPA_DAT_LINEHG_ALIAS,
	BPA_DAT_LINEHG_STATUS,
	BPA_DAT_LINEHG_INRING,
	BPA_DAT_LINEHG_RADIATE,
};

struct	_BpaMDBDat_LineHG_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	CARD TYPE
	char	szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float	fkVI;							//	15	18	F4.0	基准电压1(kV)
	char	szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float	fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char	cLoop;							//	32	32	A1		并联线路的回路标志
	float	fShuntI;						//	63	68	F5.0	线路前侧高抗容量(Mvar，填正值)
	float	fShuntJ;						//	69	74	F5.0	线路后侧高抗容量(Mvar，填正值)
	char	szKeyName[MDB_CHARLEN_SHORT];
	char	szIniBusI[MDB_CHARLEN_BPABUS];
	float	fInikVI;
	char	szIniBusJ[MDB_CHARLEN_BPABUS];
	float	fInikVJ;
	char	cIniLoop;
	int		nIBus;
	int		nZBus;
	char	szAlias[MDB_CHARLEN];
	unsigned char	nStatus;
	unsigned char	bInRing;
	short			nRadiate;
}	DISALIGN;
typedef	struct	_BpaMDBDat_LineHG_	tagBpaDat_LineHG;

enum _BpaMDBEnum_DatField_Wind_
{
	BPA_DAT_WIND_CARDKEY=0,
	//BPA_DAT_WIND_CHGCODE,
	BPA_DAT_WIND_OWNER,
	BPA_DAT_WIND_BUSI,
	BPA_DAT_WIND_KVI,
	BPA_DAT_WIND_METER,
	BPA_DAT_WIND_BUSJ,
	BPA_DAT_WIND_KVJ,
	BPA_DAT_WIND_LOOP,
	BPA_DAT_WIND_SECTION,
	BPA_DAT_WIND_MVA,
	BPA_DAT_WIND_LOOPNUM,
	BPA_DAT_WIND_R,
	BPA_DAT_WIND_X,
	BPA_DAT_WIND_G,
	BPA_DAT_WIND_B,
	BPA_DAT_WIND_TPI,
	BPA_DAT_WIND_TPJ,

	BPA_DAT_WIND_PI,
	BPA_DAT_WIND_QI,
	BPA_DAT_WIND_PZ,
	BPA_DAT_WIND_QZ,
	BPA_DAT_WIND_LOSSP,
	BPA_DAT_WIND_LOSSQ,

	BPA_DAT_WIND_SCCAI,
	BPA_DAT_WIND_SCCAZ,

	BPA_DAT_WIND_VD_RERR,
	BPA_DAT_WIND_VD_RSCC1,
	BPA_DAT_WIND_VD_RSCC2,
	BPA_DAT_WIND_VD_RSCC3,
	BPA_DAT_WIND_VD_RSCC4,

	BPA_DAT_WIND_KEYNAME,
	BPA_DAT_WIND_INIBUSI,
	BPA_DAT_WIND_INIKVI,
	BPA_DAT_WIND_INIBUSJ,
	BPA_DAT_WIND_INIKVJ,
	BPA_DAT_WIND_INILOOP,
	BPA_DAT_WIND_BUSIPTR,
	BPA_DAT_WIND_BUSJPTR,
	BPA_DAT_WIND_RCARD,
	BPA_DAT_WIND_ALIAS,
	BPA_DAT_WIND_RTTPI,
	BPA_DAT_WIND_RTTPJ,
	BPA_DAT_WIND_STATUS,
	BPA_DAT_WIND_INRING,
	BPA_DAT_WIND_RADIATE,
};

struct	_BpaMDBDat_Wind_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2		CARD TYPE
	//char			cChgCode;						//	3	3	A1		修改码
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3		所有者
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float			fkVI;							//	15	18	F4.0	基准电压1(kV)
	char			cMeter;							//	19	19	I1		区域联络线测点标志
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float			fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char			cLoop;							//	32	32	A1		并联线路的回路标志
	unsigned char	bSection;						//	33	33	I1		分段串连而成的线路的段号
	float			fMVA;							//	34	37	F4.0	变压器额定容量(MVA)
	unsigned char	bLoopNum;						//	38	38	I1		并联变压器数目
	float			fR;								//	39	44	F6.5	由铜损引起的等效电阻(标么值)
	float			fX;								//	45	50	F6.5	漏抗(标么值)
	float			fG;								//	51	56	F6.5	由铁损引起的等效电导(标么值)
	float			fB;								//	57	62	F6.5	激磁导纳(标么值)
	float			fTPI;							//	63	67	F5.2	母线1的固定分接头/移相器的固定移相角(度)
	float			fTPJ;							//	68	72	F5.2	母线2的固定分接头

	float			fPi;
	float			fQi;
	float			fPz;
	float			fQz;
	float			fLossP;
	float			fLossQ;

	float			fSccAi;
	float			fSccAz;

	double			vd_Rerr;
	float			vd_RScc1;
	float			vd_RScc2;
	float			vd_RScc3;
	float			vd_RScc4;

	char			szKeyName[MDB_CHARLEN_SHORT];
	char			szIniBusI[MDB_CHARLEN_BPABUS];
	float			fInikVI;
	char			szIniBusJ[MDB_CHARLEN_BPABUS];
	float			fInikVJ;
	char			cIniLoop;
	int				nIBus;
	int				nZBus;
	unsigned char	bRCard;
	char			szAlias[MDB_CHARLEN];
	float			fRtTPI;
	float			fRtTPJ;
	unsigned char	nStatus;
	unsigned char	bInRing;
	short			nRadiate;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Wind_	tagBpaDat_Wind;

enum _BpaMDBEnum_DatField_R_
{
	BPA_DAT_R_CARDKEY=0,
	//BPA_DAT_R_CHGCODE,
	BPA_DAT_R_OWNER,
	BPA_DAT_R_BUSI,
	BPA_DAT_R_KVI,
	BPA_DAT_R_VARTAP,
	BPA_DAT_R_BUSJ,
	BPA_DAT_R_KVJ,
	BPA_DAT_R_BUSC,
	BPA_DAT_R_KVC,
	BPA_DAT_R_TMAX,
	BPA_DAT_R_TMIN,
	BPA_DAT_R_TNUM,
	BPA_DAT_R_VALMAX,
	BPA_DAT_R_VALMIN,
	BPA_DAT_R_P,
	BPA_DAT_R_Q,
	BPA_DAT_R_LOSSP,
	BPA_DAT_R_LOSSQ,
	BPA_DAT_R_KEYNAME,
	BPA_DAT_R_BUSIPTR,
	BPA_DAT_R_BUSJPTR,
	BPA_DAT_R_STATUS,
};

struct	_BpaMDBDat_R_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	2	1	A2		CARD TYPE
	//char			cChgCode;						//	3	3	A1		修改码
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3		所有者
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float			fkVI;							//	15	18	F4.0	基准电压1(kV)
	unsigned char	bVarTap;						//	19	19	I1		可调抽头端标志
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float			fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char			szBusC[MDB_CHARLEN_BPABUS];		//	34	41	A8		被控母线名称
	float			fkVC;							//	42	45	F4.0	被控基准电压(kV)
	float			fTMax;							//	46	50	F5.2	最大抽头位置(kV)
	float			fTMin;							//	51	55	F5.2	最小抽头位置(kV)
	short			nTNum;							//	56	57	I2		LTC抽头总数
	float			fValMax;						//	58	62	F5.0	指定的最大无功功率(Mvar)
	float			fValMin;						//	63	67	F5.0	指定的最小无功功率(Mvar)

	float			fP;
	float			fQ;
	float			fLossP;
	float			fLossQ;

	char			szKeyName[MDB_CHARLEN_SHORT];
	int				nIBus;
	int				nZBus;
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_R_	tagBpaDat_R;

enum _BpaMDBEnum_DatField_DCBus_
{
	BPA_DAT_DCBUS_CARDKEY=0,
	//BPA_DAT_DCBUS_CHGCODE,
	BPA_DAT_DCBUS_OWNER,
	BPA_DAT_DCBUS_NAME,
	BPA_DAT_DCBUS_KV,
	BPA_DAT_DCBUS_ZONE,
	BPA_DAT_DCBUS_BRDGS,
	BPA_DAT_DCBUS_SMTHGREACTOR,
	BPA_DAT_DCBUS_ROPERMIN,
	BPA_DAT_DCBUS_IOPERSTOP,
	BPA_DAT_DCBUS_DROP,
	BPA_DAT_DCBUS_BRDGRATE,
	BPA_DAT_DCBUS_ACNAME,
	BPA_DAT_DCBUS_ACKV,

	BPA_DAT_DCBUS_DCV,
	BPA_DAT_DCBUS_DCD,
	BPA_DAT_DCBUS_DCP,
	BPA_DAT_DCBUS_DCI,
	BPA_DAT_DCBUS_LOSSP,
	BPA_DAT_DCBUS_LOSSQ,
	BPA_DAT_DCBUS_ACV,
	BPA_DAT_DCBUS_ANGLE,

	BPA_DAT_DCBUS_ACBUS,
	BPA_DAT_DCBUS_ACISLAND,
	BPA_DAT_DCBUS_SUB,
	BPA_DAT_DCBUS_ALIAS,
	BPA_DAT_DCBUS_STATUS,
};

struct	_BpaMDBDat_DCBus_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	CARDTYPE
	//char			cChgCode;						//	3	3	A1	修改码
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	4	A3	所有者
	char			szName[MDB_CHARLEN_BPABUS];		//	7	7	A8	Converter母线名称
	float			fkV;							//	15	15	F4.0	Converter基准电压(kV)
	char			szZone[MDB_CHARLEN_SHORTEST/2];		//	19	19	A2	Zone，分区名
	short			nBRDGS;							//	24	24	I2	整流线路的桥数
	float			fSMTHGREACTOR;					//	26	26	F5.1	平波电抗器电感(毫亨)
	float			fROPERMIN;						//	31	31	F5.1	作为整流器运行的最小触发角(度)
	float			fIOPERSTOP;						//	36	36	F5.1	作为逆变器运行的最大触发角(度)
	float			fDROP;							//	41	41	F5.1	每个桥阀的电压降(伏)
	float			fBRDGRATE;						//	46	46	F5.1	桥电流额定值(安培)
	char			szACName[MDB_CHARLEN_BPABUS];		//	51	51	A8	换流变压器一次侧母线名称
	float			fACkV;							//	59	59	F4.0	换流变压器一次侧基准电压(kV)

	float			fDCV;
	float			fDCD;
	float			fDCP;
	float			fDCI;
	float			fLossP;
	float			fLossQ;
	float			fACV;
	float			fAngle;

	int				nACBus;
	short			nACIsland;
	char			szSub[MDB_CHARLEN_SHORTER];
	char			szAlias[MDB_CHARLEN];
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_DCBus_	tagBpaDat_DCBus;

enum _BpaMDBEnum_DatField_DCLine_
{
	BPA_DAT_DCLINE_CARDKEY=0,
	//BPA_DAT_DCLINE_CHGCODE,
	BPA_DAT_DCLINE_OWNER,
	BPA_DAT_DCLINE_BUSR,
	BPA_DAT_DCLINE_KVR,
	BPA_DAT_DCLINE_METER,
	BPA_DAT_DCLINE_BUSI,
	BPA_DAT_DCLINE_KVI,
	BPA_DAT_DCLINE_AMP,
	BPA_DAT_DCLINE_R,
	BPA_DAT_DCLINE_L,
	BPA_DAT_DCLINE_C,
	BPA_DAT_DCLINE_CONTROL,
	BPA_DAT_DCLINE_DCPOWER,
	BPA_DAT_DCLINE_RVOLT,
	BPA_DAT_DCLINE_ROPER,
	BPA_DAT_DCLINE_ISTOP,

	BPA_DAT_DCLINE_PR,
	BPA_DAT_DCLINE_PI,
	BPA_DAT_DCLINE_LOSSP,

	BPA_DAT_DCLINE_KEYNAME,
	BPA_DAT_DCLINE_BUSRPTR,
	BPA_DAT_DCLINE_BUSIPTR,
	BPA_DAT_DCLINE_ALIAS,
	BPA_DAT_DCLINE_STATUS,
};

struct	_BpaMDBDat_DCLine_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	CARD TYPE
	//char			cChgCode;						//	3	3	A1	修改码
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3	所有者
	char			szBusR[MDB_CHARLEN_BPABUS];		//	7	14	A8	整流侧母线名称
	float			fkVR;							//	15	18	F4.0	整流侧基准电压(kV)
	unsigned char	bMeter;							//	19	19	I1	区域联络线测点标志
	char			szBusI[MDB_CHARLEN_BPABUS];		//	20	27	A8	逆变侧母线名称
	float			fkVI;							//	28	31	F4.0	逆变侧基准电压(kV)
	float			fAMP;							//	34	37	F4.0	直流线路额定电流(安培)
	float			fR;								//	38	43	F6.2	直流线路电阻(欧姆)
	float			fL;								//	44	49	F6.2	直流线路电感(毫亨)
	float			fC;								//	50	55	F6.2	直流线路电容(微阀)
	char			cControl;						//	56	56	A1	所安排的直流功率的控制点
	float			fDCPOWER;						//	57	61	F5.1	所安排的直流功率(MW)
	float			fRVOLT;							//	62	66	F5.1	给定直流线路整流侧的直流电压(kV)
	float			fROPER;							//	67	70	F4.1	整流侧的正常触发角(度)
	float			fISTOP;							//	71	74	F4.1	逆变侧的正常关断角(度)
	float			fPr;
	float			fPi;
	float			fLossP;
	char			szKeyName[MDB_CHARLEN_SHORT];
	int				nRBus;
	int				nIBus;
	char			szAlias[MDB_CHARLEN];
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_DCLine_	tagBpaDat_DCLine;

enum _BpaMDBEnum_DatField_RZ_
{
	BPA_DAT_RZ_CARDKEY=0,
	//BPA_DAT_RZ_CHGCODE,
	BPA_DAT_RZ_OWNER,
	BPA_DAT_RZ_BUSI,
	BPA_DAT_RZ_KVI,
	BPA_DAT_RZ_BUSJ,
	BPA_DAT_RZ_KVJ,
	BPA_DAT_RZ_LOOP,
	BPA_DAT_RZ_SECTION,
	BPA_DAT_RZ_MODE,
	BPA_DAT_RZ_PCMAX,
	BPA_DAT_RZ_PCMIN,
	BPA_DAT_RZ_IN,
	BPA_DAT_RZ_XIJMAX,
	BPA_DAT_RZ_XIJMIN,
	BPA_DAT_RZ_KEYNAME,
	BPA_DAT_RZ_BUSIPTR,
	BPA_DAT_RZ_BUSJPTR,
	BPA_DAT_RZ_STATUS,
};

struct	_BpaMDBDat_RZ_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	CARD TYPE
	//char			cChgCode;						//	3	3	A1	修改码
	char			szOwner[MDB_CHARLEN_SHORTEST/2];		//	4	6	A3	所有者
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float			fkVI;							//	15	18	F4.0	基准电压1(kV)
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float			fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char			cLoop;							//	32	32	A1		并联线路的回路标志
	unsigned char	bSection;						//	33	33	I1		分段串连而成的线路的段号
	char			cMode;							//	34	34	A1		控制方式
	float			fPcmax;							//	35	39	F5.0	线路有功潮流最大值(MW)
	float			fPcmin;							//	40	44	F5.0	线路有功潮流最小值(MW)
	float			fIn;							//	45	48	F4.0	线路额定电流值(安培)
	float			fXijmax;						//	49	54	F6.5	线路电抗最大标么值
	float			fXijmin;						//	55	60	F6.5	线路电抗最小标么值
	char			szKeyName[MDB_CHARLEN];
	int				nIBus;
	int				nZBus;
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_RZ_	tagBpaDat_RZ;

enum _BpaMDBEnum_DatField_P_
{
	BPA_DAT_P_CARDKEY=0,
	BPA_DAT_P_ZONE,
	BPA_DAT_P_LOADPFACTOR,
	BPA_DAT_P_LOADQFACTOR,
	BPA_DAT_P_GENPFACTOR,
	BPA_DAT_P_GENQFACTOR,
	BPA_DAT_P_STATUS,
};

struct	_BpaMDBDat_P_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];			//	1	2	A2	CARD TYPE
	char	szZone[MDB_CHARLEN_SHORTEST/2];				//	4	6	A3	所有者代码
	float	fLoadPFactor;							//	10	14	F5.0	负荷有功修改因子
	float	fLoadQFactor;							//	16	20	F5.0	负荷无功修改因子
	float	fGenPFactor;							//	22	26	F5.0	发电出力有功修改因子
	float	fGenQFactor;							//	28	32	F5.0	发电出力无功修改因子
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_P_	tagBpaDat_P;

enum _BpaMDBEnum_DatField_ZIL_
{
	BPA_DAT_ZIL_CARDKEY=0,
	BPA_DAT_ZIL_BUSI,
	BPA_DAT_ZIL_KVI,
	BPA_DAT_ZIL_BUSJ,
	BPA_DAT_ZIL_KVJ,
	BPA_DAT_ZIL_LOOP,
	BPA_SWI_ZIL_R,
	BPA_SWI_ZIL_X,
	BPA_DAT_ZIL_MBUS,
	BPA_DAT_ZIL_MKV,
};

struct	_BpaMDBDat_ZIL_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];			//	1	2	A2	CARD TYPE
	char	szBusI[MDB_CHARLEN_BPABUS];
	float	fkVI;
	char	szBusJ[MDB_CHARLEN_BPABUS];
	float	fkVJ;
	char	cLoop;
	float	fR;
	float	fX;
	char	szMBus[MDB_CHARLEN_BPABUS];
	float	fMkV;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ZIL_	tagBpaDat_ZIL;

enum _BpaMDBEnum_DatField_VDIP_
{
	BPA_DAT_VDIP_FDEVINDEX=0,
	BPA_DAT_VDIP_FTYPE,
	BPA_DAT_VDIP_DIPBUS,
	BPA_DAT_VDIP_DIPV,
	BPA_DAT_VDIP_POLYPHASE,
};
struct	_BpaMDBDat_VDip_	{
	int		nFaultBus;
	unsigned char	nFaultType;
	int		nDipBus;
	float	fDipV;
	unsigned char	nPolyPhase;
}	DISALIGN;
typedef	struct	_BpaMDBDat_VDip_	tagBpaDat_VDip;

enum _BpaMDBEnum_DatField_Gen_
{
	BPA_DAT_GEN_NAME=0,
	BPA_DAT_GEN_BUS,
	BPA_DAT_GEN_KV,
	BPA_DAT_GEN_ID,
	BPA_DAT_GEN_PGEN,
	BPA_DAT_GEN_QGEN,
	BPA_DAT_GEN_PMAX,
	BPA_DAT_GEN_PMIN,
	BPA_DAT_GEN_QMAX,
	BPA_DAT_GEN_QMIN,
	BPA_DAT_GEN_VHOLD,
	BPA_DAT_GEN_ACBUSPTR,
	BPA_DAT_GEN_WGEN,
	BPA_DAT_GEN_EQ,
	BPA_DAT_GEN_STATUS,
};
struct	_BpaMDBDat_Gen_	{
	char	szName[MDB_CHARLEN_SHORTER];
	char	szBus[MDB_CHARLEN_BPABUS];
	float	fkV;
	char	cID;
	float	fP;
	float	fQ;
	float	fPMax;
	float	fPMin;
	float	fQMax;
	float	fQMin;
	float	fVHold;
	int		nACBusIndex;
	unsigned char	bWGen;
	unsigned char	bEQ;
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Gen_	tagBpaDat_Gen;

enum _BpaMDBEnum_DatField_Load_
{
	BPA_DAT_LOAD_NAME = 0,
	BPA_DAT_LOAD_BUS,
	BPA_DAT_LOAD_KV,
	BPA_DAT_LOAD_PLOAD,
	BPA_DAT_LOAD_QLOAD,
	BPA_DAT_LOAD_ACBUSPTR,
	BPA_DAT_LOAD_AUX,
	BPA_DAT_LOAD_EQ,
	BPA_DAT_LOAD_STATUS,
};
struct	_BpaMDBDat_Load_	{
	char	szName[MDB_CHARLEN_SHORTER];
	char	szBus[MDB_CHARLEN_BPABUS];
	float	fkV;
	float	fP;
	float	fQ;
	int		nACBusIndex;
	unsigned char	bAux;
	unsigned char	bEQ;
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Load_	tagBpaDat_Load;

enum _BpaMDBEnum_DatField_Tran_
{
	BPA_DAT_TRAN_WINDNUM=0,
	BPA_DAT_TRAN_WINDH,
	BPA_DAT_TRAN_WINDM,
	BPA_DAT_TRAN_WINDL,
	BPA_DAT_TRAN_IRWINDH,
	BPA_DAT_TRAN_IRWINDM,
	BPA_DAT_TRAN_IRWINDL,

// 	BPA_DAT_TRAN_WINDLOADP,
// 	BPA_DAT_TRAN_WINDLOADQ,
// 	BPA_DAT_TRAN_MLINENUM,
// 	BPA_DAT_TRAN_LLINENUM,
// 	BPA_DAT_TRAN_PLANTSUB,
// 	BPA_DAT_TRAN_TERMINAL,
};
struct	_BpaMDBDat_Tran_	{
	unsigned char	nWindNum;
	char	szWindH[MDB_CHARLEN_SHORT];
	char	szWindM[MDB_CHARLEN_SHORT];
	char	szWindL[MDB_CHARLEN_SHORT];
	int		iRWindH;
	int		iRWindM;
	int		iRWindL;

// 	float	fWindLoadP;
// 	float	fWindLoadQ;
// 	unsigned char	nWindMLineNum;
// 	unsigned char	nWindLLineNum;
// 	unsigned char	bPlantSub;
// 	unsigned char	bTerminal;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Tran_	tagBpaDat_Tran;

enum _BpaMDBEnum_DatField_ACBus2Line_
{
	BPA_DAT_EDGELINE_BUSNAME=0,
	BPA_DAT_EDGELINE_BUSKV,
	BPA_DAT_EDGELINE_LINENAME,
	BPA_DAT_EDGELINE_IRLINE,
};
struct	_BpaMDBDat_ACBus2Line_	{
	char	szBusName[MDB_CHARLEN_BPABUS];
	float	fBuskV;
	char	szLineName[MDB_CHARLEN_SHORT];
	int		iRLine;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACBus2Line_	tagBpaDat_EdgeLine;

enum _BpaMDBEnum_DatField_ACBus2Wind_
{
	BPA_DAT_EDGEWIND_BUSNAME=0,
	BPA_DAT_EDGEWIND_BUSKV,
	BPA_DAT_EDGEWIND_WINDNAME,
	BPA_DAT_EDGEWIND_IRWIND,
};
struct	_BpaMDBDat_ACBus2Wind_	{
	char	szBusName[MDB_CHARLEN_BPABUS];
	float	fBuskV;
	char	szWindName[MDB_CHARLEN_SHORT];
	int		iRWind;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACBus2Wind_	tagBpaDat_EdgeWind;

enum _BpaMDBEnum_DatField_ACBus2HG_
{
	BPA_DAT_EDGELINEHG_BUSNAME=0,
	BPA_DAT_EDGELINEHG_BUSKV,
	BPA_DAT_EDGELINEHG_HGNAME,
	BPA_DAT_EDGELINEHG_IRHG,
};
struct	_BpaMDBDat_ACBus2HG_	{
	char	szBusName[MDB_CHARLEN_BPABUS];
	float	fBuskV;
	char	szLineHGName[MDB_CHARLEN_SHORT];
	short	nLineHG;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACBus2HG_	tagBpaDat_EdgeLineHG;

enum _BpaMDBEnum_DatField_Radiate_
{
	BPA_DAT_RADIATE_BOUNDBUSNAME=0,
	BPA_DAT_RADIATE_BOUNDBUSKV,
	BPA_DAT_RADIATE_GENP,
	BPA_DAT_RADIATE_LOADP,
	BPA_DAT_RADIATE_LOADQ,
	BPA_DAT_RADIATE_IRBOUNDBUS,
};
struct	_BpaMDBDat_Radiate_	{
	char	szBoundBusName[MDB_CHARLEN_BPABUS];
	float	fBoundBuskV;
	float	fGenP;
	float	fLoadP;
	float	fLoadQ;
	int		nBoundBus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Radiate_	tagBpaDat_Radiate;

enum _BpaMDBEnum_SCCField_FMove_
{
	BPA_SCC_FMOVE_FAULTTYPE=0,
	BPA_SCC_FMOVE_FAULTLINE,
	BPA_SCC_FMOVE_MONLINE,
	BPA_SCC_FMOVE_MONBUS,
	BPA_SCC_FMOVE_DATATYPE,
	BPA_SCC_FMOVE_VALUE000,
	BPA_SCC_FMOVE_VALUE001,
	BPA_SCC_FMOVE_VALUE002,
	BPA_SCC_FMOVE_VALUE003,
	BPA_SCC_FMOVE_VALUE004,
	BPA_SCC_FMOVE_VALUE005,
	BPA_SCC_FMOVE_VALUE006,
	BPA_SCC_FMOVE_VALUE007,
	BPA_SCC_FMOVE_VALUE008,
	BPA_SCC_FMOVE_VALUE009,
	BPA_SCC_FMOVE_VALUE010,
	BPA_SCC_FMOVE_VALUE011,
	BPA_SCC_FMOVE_VALUE012,
	BPA_SCC_FMOVE_VALUE013,
	BPA_SCC_FMOVE_VALUE014,
	BPA_SCC_FMOVE_VALUE015,
	BPA_SCC_FMOVE_VALUE016,
	BPA_SCC_FMOVE_VALUE017,
	BPA_SCC_FMOVE_VALUE018,
	BPA_SCC_FMOVE_VALUE019,
	BPA_SCC_FMOVE_VALUE020,
	BPA_SCC_FMOVE_VALUE021,
	BPA_SCC_FMOVE_VALUE022,
	BPA_SCC_FMOVE_VALUE023,
	BPA_SCC_FMOVE_VALUE024,
	BPA_SCC_FMOVE_VALUE025,
	BPA_SCC_FMOVE_VALUE026,
	BPA_SCC_FMOVE_VALUE027,
	BPA_SCC_FMOVE_VALUE028,
	BPA_SCC_FMOVE_VALUE029,
	BPA_SCC_FMOVE_VALUE030,
	BPA_SCC_FMOVE_VALUE031,
	BPA_SCC_FMOVE_VALUE032,
	BPA_SCC_FMOVE_VALUE033,
	BPA_SCC_FMOVE_VALUE034,
	BPA_SCC_FMOVE_VALUE035,
	BPA_SCC_FMOVE_VALUE036,
	BPA_SCC_FMOVE_VALUE037,
	BPA_SCC_FMOVE_VALUE038,
	BPA_SCC_FMOVE_VALUE039,
	BPA_SCC_FMOVE_VALUE040,
	BPA_SCC_FMOVE_VALUE041,
	BPA_SCC_FMOVE_VALUE042,
	BPA_SCC_FMOVE_VALUE043,
	BPA_SCC_FMOVE_VALUE044,
	BPA_SCC_FMOVE_VALUE045,
	BPA_SCC_FMOVE_VALUE046,
	BPA_SCC_FMOVE_VALUE047,
	BPA_SCC_FMOVE_VALUE048,
	BPA_SCC_FMOVE_VALUE049,
	BPA_SCC_FMOVE_VALUE050,
	BPA_SCC_FMOVE_VALUE051,
	BPA_SCC_FMOVE_VALUE052,
	BPA_SCC_FMOVE_VALUE053,
	BPA_SCC_FMOVE_VALUE054,
	BPA_SCC_FMOVE_VALUE055,
	BPA_SCC_FMOVE_VALUE056,
	BPA_SCC_FMOVE_VALUE057,
	BPA_SCC_FMOVE_VALUE058,
	BPA_SCC_FMOVE_VALUE059,
	BPA_SCC_FMOVE_VALUE060,
	BPA_SCC_FMOVE_VALUE061,
	BPA_SCC_FMOVE_VALUE062,
	BPA_SCC_FMOVE_VALUE063,
	BPA_SCC_FMOVE_VALUE064,
	BPA_SCC_FMOVE_VALUE065,
	BPA_SCC_FMOVE_VALUE066,
	BPA_SCC_FMOVE_VALUE067,
	BPA_SCC_FMOVE_VALUE068,
	BPA_SCC_FMOVE_VALUE069,
	BPA_SCC_FMOVE_VALUE070,
	BPA_SCC_FMOVE_VALUE071,
	BPA_SCC_FMOVE_VALUE072,
	BPA_SCC_FMOVE_VALUE073,
	BPA_SCC_FMOVE_VALUE074,
	BPA_SCC_FMOVE_VALUE075,
	BPA_SCC_FMOVE_VALUE076,
	BPA_SCC_FMOVE_VALUE077,
	BPA_SCC_FMOVE_VALUE078,
	BPA_SCC_FMOVE_VALUE079,
	BPA_SCC_FMOVE_VALUE080,
	BPA_SCC_FMOVE_VALUE081,
	BPA_SCC_FMOVE_VALUE082,
	BPA_SCC_FMOVE_VALUE083,
	BPA_SCC_FMOVE_VALUE084,
	BPA_SCC_FMOVE_VALUE085,
	BPA_SCC_FMOVE_VALUE086,
	BPA_SCC_FMOVE_VALUE087,
	BPA_SCC_FMOVE_VALUE088,
	BPA_SCC_FMOVE_VALUE089,
	BPA_SCC_FMOVE_VALUE090,
	BPA_SCC_FMOVE_VALUE091,
	BPA_SCC_FMOVE_VALUE092,
	BPA_SCC_FMOVE_VALUE093,
	BPA_SCC_FMOVE_VALUE094,
	BPA_SCC_FMOVE_VALUE095,
	BPA_SCC_FMOVE_VALUE096,
	BPA_SCC_FMOVE_VALUE097,
	BPA_SCC_FMOVE_VALUE098,
	BPA_SCC_FMOVE_VALUE099,
	BPA_SCC_FMOVE_VALUE100,
};
struct	_BpaMDBScc_FMove_	{
	unsigned char	nFaultType;
	char			szFaultLine[MDB_CHARLEN_SHORT];
	char			szMonLine[MDB_CHARLEN_SHORT];
	char			szMonBus[MDB_CHARLEN_SHORT];
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
typedef	struct	_BpaMDBScc_FMove_	tagBpaScc_FMove;

enum	_BpaMDBEnum_SwiField_Case_
{
	BPA_SWI_CASE_CARDKEY=0,
	BPA_SWI_CASE_PFCASE,
	BPA_SWI_CASE_ITSKP,
	BPA_SWI_CASE_NOPRNT,
	BPA_SWI_CASE_DSW,
	BPA_SWI_CASE_IWSCC,
	BPA_SWI_CASE_ZSW,
	BPA_SWI_CASE_X2FAC,
	BPA_SWI_CASE_XFACT,
	BPA_SWI_CASE_TDODPS,
	BPA_SWI_CASE_TQODPS,
	BPA_SWI_CASE_TDODPH,
	BPA_SWI_CASE_TQODPH,
	BPA_SWI_CASE_CFACL2,
};
struct	_BpaMDBSwi_Case_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST];	//	1	4	A4	卡类型
	char				szPFCASE[MDB_CHARLEN_SHORTER];		//	6	15	A10	潮流方式名
	unsigned char		bITSKP;								//	17	17	I1	写求解文件的步长
	unsigned char		bNOPRNT;							//	20	20	I1	NOPRNT,为1时打印全部输入数据
	unsigned char		bDSW;								//	22	22	I1	输出文件摇摆曲线显示开关
	unsigned char		bIWSCC;								//	23	23	I1	采用新减负荷卡减负荷标记
	unsigned char		bZSW; 								//	24	24	I1	对零序卡进行检查标志
	float				fX2FAC;								//	45	49	F5.5	不对称故障时发电机X2与Xdp之比
	float				fXFACT; 							//	50	54	F5.5	发电机Xdpp与Xdp之比
	float				fTDODPS;							//	55	59	F5.5	隐级机的Tdopp(秒)
	float				fTQODPS;							//	60	64	F5.5	隐级机的Tdopp(秒)
	float				fTDODPH;							//	65	69	F5.5	凸级水轮机的Tqopp(秒)
	float				fTQODPH;							//	70	74	F5.5	凸级水轮机的Tdopp(秒)
	float				fCFACL2; 							//	75	80	F6.5	负序负荷导纳标么值
}	DISALIGN;
typedef	struct	_BpaMDBSwi_Case_	tagBpaSwi_Case;

enum	_BpaMDBEnum_SwiField_F1_
{
	BPA_SWI_F1_CARDKEY=0,
	BPA_SWI_F1_TBUSF,
	BPA_SWI_F1_TZERO,
	BPA_SWI_F1_IBLOD,
	BPA_SWI_F1_DMPALL,
	BPA_SWI_F1_IAMRTS,
	BPA_SWI_F1_VCHGL,
	BPA_SWI_F1_SPTOSG,
	BPA_SWI_F1_GSIQU,
	BPA_SWI_F1_TITSKP,
	BPA_SWI_F1_ITSKP1,
	BPA_SWI_F1_VRLIM,
};

struct	_BpaMDBSwi_F1_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST];	//	1	4	A4	卡类型
	float				fTBUSF;								//	5	9	F5.4	母线频率滤波器缺省时间常数
	float				fTZERO;								//	12	16	F5.4	测量回路缺省时间常数
	unsigned char		bIBLOD;								//	18	18	I1	母线负荷开关
	float				fDMPALL;							//	20	22	F3.2	缺省发电机阻尼因子
	unsigned char		bIAMRTS;							//	26	26	I1	如果该值不为0，并且 F1卡中的XFACT也不为0，无论发电机的次暂态参数是否已经用M卡指定，都要采用缺省的参数来计算发电机的次暂态参数
	float				fVCHGL;								//	28	31	F4.3	如果负荷母线电压低于该值，则负荷将转换为恒阻抗负荷，缺省值为0.5pu
	unsigned char		bSPTOSG;							//	33	33	I1	SP卡为以加速功率作为输入信号的PSS，而SG卡为以电磁功率为输入信号的PSS；如果该值不为0，则将稳定数据中所有的SP卡改为SG卡
	float				fGSIQU;								//	37	41	F5.5	如果该值不为零，则数据文件中所有GH卡和GS卡的死区的大小都为该值
	float				fTITSKP;							//	43	47	F5.1	从本时间开始，按照本卡中的48-49列填写的步数进行存储
	short				nITSKP1;							//	48	49	I2	从本卡43-47列规定的时间TITSKP开始每隔ITSKP1步存储一次数据
	unsigned char		bVRLIM;								//	51	51	I1	FM\FO\FP\FQ\FR\FS\FT和FG型励磁模型的调压器限幅环节为外限幅，如果VRLIM不为0，则将其改为内限幅
}	DISALIGN;
typedef	struct	_BpaMDBSwi_F1_	tagBpaSwi_F1;

enum	_BpaMDBEnum_SwiField_F0_
{
	BPA_SWI_F0_CARDKEY=0,
	BPA_SWI_F0_IG,
	BPA_SWI_F0_IA,
	BPA_SWI_F0_BUSNAME1,
	BPA_SWI_F0_BUSVOLT1,
	BPA_SWI_F0_ID1,
	BPA_SWI_F0_BUSNAME2,
	BPA_SWI_F0_BUSVOLT2,
	BPA_SWI_F0_ID2,
	BPA_SWI_F0_AMAX,
	BPA_SWI_F0_AMIN,
	BPA_SWI_F0_IV,
	BPA_SWI_F0_VBUSNAME,
	BPA_SWI_F0_VBUSVOLT,
	BPA_SWI_F0_IF,
	BPA_SWI_F0_FBUSNAME,
	BPA_SWI_F0_FBUSVOLT,
};

struct	_BpaMDBSwi_F0_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST];
	unsigned char		bIG;
	unsigned char		bIA;
	char				szGenBusName1[MDB_CHARLEN_SHORTER];
	float				fGenBusBase1;
	char				cGenID1;
	char				szGenBusName2[MDB_CHARLEN_SHORTER];
	float				fGenBusBase2;
	char				cGenID2;
	float				fAMax;
	float				fAMin;
	unsigned char		bIV;
	char				szVBusName[MDB_CHARLEN_SHORTER];
	float				fVBusVolt;
	unsigned char		bIF;
	char				szFBusName[MDB_CHARLEN_SHORTER];
	float				fFBusVolt;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_F0_	tagBpaSwi_F0;

enum	_BpaMDBEnum_SwiField_FF_
{
	BPA_SWI_FF_CARDKEY=0,
	BPA_SWI_FF_T,
	BPA_SWI_FF_DT,
	BPA_SWI_FF_ENDT,
	BPA_SWI_FF_DTC,
	BPA_SWI_FF_ISTP,
	BPA_SWI_FF_TOLI,
	BPA_SWI_FF_ILIM,
	BPA_SWI_FF_DELANG,
	BPA_SWI_FF_DTDV,
	BPA_SWI_FF_DMPMLT,
	BPA_SWI_FF_FRQBSE,
	BPA_SWI_FF_LOVTEX,
	BPA_SWI_FF_IMBLOK,
	BPA_SWI_FF_MFDEP,
	BPA_SWI_FF_IGSLIM,
	BPA_SWI_FF_LSOLQIT,
	BPA_SWI_FF_NOANGLIM,
	BPA_SWI_FF_INFBUS,
	BPA_SWI_FF_NOPP,
	BPA_SWI_FF_NODQ,
	BPA_SWI_FF_NOSAT,
	BPA_SWI_FF_NOGV,
	BPA_SWI_FF_IEQPC,
	BPA_SWI_FF_NOEX,
	BPA_SWI_FF_MFTOMG,
	BPA_SWI_FF_NOSC,
	BPA_SWI_FF_MGTOMF,
	BPA_SWI_FF_NOLOAD,
};

struct	_BpaMDBSwi_FF_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST];
	float				fT;
	float				fDT;
	float				fENDT;
	float				fDTC;
	short				nISTP;
	float				fTOLI;
	short				nILIM;
	float				fDELANG;
	float				fDTDV;
	float				fDMPMLT;
	float				fFRQBSE;
	unsigned char		bLOVTEX;
	unsigned char		bIMBLOK;
	unsigned char		bMFDEP;
	unsigned char		bIGSLIM;
	unsigned char		bLSOLQIT;
	unsigned char		bNOANGLIM;
	unsigned char		bINFBUS;
	unsigned char		bNOPP;
	unsigned char		bNODQ;
	unsigned char		bNOSAT;
	unsigned char		bNOGV;
	unsigned char		bIEQPC;
	unsigned char		bNOEX;
	unsigned char		bMFTOMG;
	unsigned char		bNOSC;
	unsigned char		bMGTOMF;
	unsigned char		bNOLOAD;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_FF_	tagBpaSwi_FF;

enum	_BpaMDBEnum_SwiField_Gen_{
	BPA_SWI_GEN_CARDKEY=0,
	BPA_SWI_GEN_BUS_NAME,
	BPA_SWI_GEN_BUS_KV,
	BPA_SWI_GEN_ID,
	BPA_SWI_GEN_EMWS,
	BPA_SWI_GEN_P,
	BPA_SWI_GEN_Q,
	BPA_SWI_GEN_MVABASE,
	BPA_SWI_GEN_RA,
	BPA_SWI_GEN_XDP,
	BPA_SWI_GEN_XQP,
	BPA_SWI_GEN_XD,
	BPA_SWI_GEN_XQ,
	BPA_SWI_GEN_TD0,
	BPA_SWI_GEN_TQ0,
	BPA_SWI_GEN_XL_XP,
	BPA_SWI_GEN_SG10,
	BPA_SWI_GEN_SG12,
	BPA_SWI_GEN_D,
	BPA_SWI_GEN_A,
	BPA_SWI_GEN_B,
	BPA_SWI_GEN_N,
	BPA_SWI_GEN_MVA,
	BPA_SWI_GEN_KEYNAME,
	BPA_SWI_GEN_BUSPTR,
	BPA_SWI_GEN_APPENDTAG
};

struct	_BpaMDBSwi_Gen_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST];
	char			szBus_Name[MDB_CHARLEN_BPABUS];
	float			fBus_kV;
	char			cID;
	float			fEmws;
	float			fP;
	float			fQ;
	float			fMVABase;
	float			fRa;
	float			fXdp;
	float			fXqp;
	float			fXd;
	float			fXq;
	float			fTd0;
	float			fTq0;
	float			fXL_XP;
	float			fSG10;
	float			fSG12;
	float			fD;
	float			fA;
	float			fB;
	float			fN;
	float			fMVA;
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_Gen_	tagBpaSwi_Gen;

enum	_BpaMDBEnum_SwiField_Damp_{
	BPA_SWI_DAMP_CARDKEY=0,
	BPA_SWI_DAMP_BUS_NAME,
	BPA_SWI_DAMP_BUS_KV,
	BPA_SWI_DAMP_ID,
	BPA_SWI_DAMP_MVA,	
	BPA_SWI_DAMP_PF,	
	BPA_SWI_DAMP_XDPP,
	BPA_SWI_DAMP_XQPP,
	BPA_SWI_DAMP_TD0PP,
	BPA_SWI_DAMP_TQ0PP,
	BPA_SWI_DAMP_KEYNAME,
	BPA_SWI_DAMP_BUSPTR,
	BPA_SWI_DAMP_APPENDTAG
};
struct	_BpaMDBSwi_Damp_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST];
	char			szBus_Name[MDB_CHARLEN_BPABUS];
	float			fBus_kV;
	char			cID;
	float			fMVA;
	float			fPF;
	float			fXdPP;
	float			fXqPP;
	float			fTdPP0;
	float			fTqPP0;
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nDampBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_Damp_	tagBpaSwi_Damp;

enum	_BpaMDBEnum_SwiField_WGEGen_{
	BPA_SWI_WGEGEN_CARDKEY=0,
	BPA_SWI_WGEGEN_BUS_NAME,
	BPA_SWI_WGEGEN_BUS_KV,
	BPA_SWI_WGEGEN_ID,
	BPA_SWI_WGEGEN_GE_TYPE,
	BPA_SWI_WGEGEN_NG,
	BPA_SWI_WGEGEN_NAME_CON,
	BPA_SWI_WGEGEN_BASE_CON,
	BPA_SWI_WGEGEN_PPER,
	BPA_SWI_WGEGEN_QPER,
	BPA_SWI_WGEGEN_V0,
	BPA_SWI_WGEGEN_NMASS_FLG,
	BPA_SWI_WGEGEN_QDROOP_FLG,
	BPA_SWI_WGEGEN_WINDCON_FLG,
	BPA_SWI_WGEGEN_EWVOL_FLG,
	BPA_SWI_WGEGEN_APCFLG,
	BPA_SWI_WGEGEN_FFLG,
	BPA_SWI_WGEGEN_INERTIA,
	BPA_SWI_WGEGEN_PQFLG,
	BPA_SWI_WGEGEN_KEYNAME,
	BPA_SWI_WGEGEN_BUSPTR,
};

struct	_BpaMDBSwi_WGEGen_
{
	char			szCardKey[MDB_CHARLEN_BPABUS];
	char			szBus_Name[MDB_CHARLEN_BPABUS];
	float			fBus_kV;
	char			cID;
	char			szGE_TYPE[MDB_CHARLEN_SHORT];
	short			nNG;
	char			szNAME_CON[MDB_CHARLEN_BPABUS];
	float			fBASE_CON;
	float			fPPER;
	float			fQPER;
	float			fV0;
	unsigned char	bNMASS_FLG;
	unsigned char	bQDROOP_FLG;
	unsigned char	bWINDCON_FLG;
	unsigned char	bEWVOL_FLG;
	unsigned char	bAPCFLG;
	unsigned char	bFFLG;
	unsigned char	bINERTIA;
	unsigned char	bPQFLG;
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_WGEGen_	tagBpaSwi_WGEGen;

enum	_BpaMDBEnum_SwiField_GenLn_
{
	BPA_SWI_GENLN_CARDKEY=0,
	BPA_SWI_GENLN_BUS_NAME,
	BPA_SWI_GENLN_BUS_KV,
	BPA_SWI_GENLN_BUSPTR,
	BPA_SWI_GENLN_DCBUS,
};

struct	_BpaMDBSwi_GenLn_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	int		nBus;
	unsigned char	bDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GenLn_	tagBpaSwi_GenLn;

enum	_BpaMDBEnum_SwiField_Exc68_{
	BPA_SWI_EXCIT68_CARDKEY=0,
	BPA_SWI_EXCIT68_BUS_NAME,
	BPA_SWI_EXCIT68_BUS_KV,
	BPA_SWI_EXCIT68_GEN_ID,
	BPA_SWI_EXCIT68_TR,
	BPA_SWI_EXCIT68_KA_BUSKV,
	BPA_SWI_EXCIT68_TR_TRH,
	BPA_SWI_EXCIT68_TA1,
	BPA_SWI_EXCIT68_VRMINMULT_TRMAX,
	BPA_SWI_EXCIT68_KE,
	BPA_SWI_EXCIT68_TE,
	BPA_SWI_EXCIT68_SE75MAX_KI,
	BPA_SWI_EXCIT68_SEMAX_KP,
	BPA_SWI_EXCIT68_EFDMIN,
	BPA_SWI_EXCIT68_EFDMAX_VBMAX,
	BPA_SWI_EXCIT68_KF,
	BPA_SWI_EXCIT68_TF,
	BPA_SWI_EXCIT68_XL,
	BPA_SWI_EXCIT68_TF1,
	BPA_SWI_EXCIT68_KEYNAME,
	BPA_SWI_EXCIT68_BUSPTR,
	BPA_SWI_EXCIT68_APPENDTAG
};

struct	_BpaMDBSwi_Exc68_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST];
	char			szBus_Name[MDB_CHARLEN_BPABUS];
	float			fBus_kV;
	char			cGen_ID;
	float			fTR;
	float			fKA_BusKV;
	float			fTR_TRH;
	float			fTA1;
	float			fVRminMult_TRmax;
	float			fKE;
	float			fTE;
	float			fSE75Max_KI;
	float			fSEmax_Kp;
	float			fEFDmin;
	float			fEFDmax_VBmax;
	float			fKF;
	float			fTF;
	float			fXL;
	float			fTF1;
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_Exc68_	tagBpaSwi_Exc68;

enum	_BpaMDBEnum_SwiField_Exc81_{
	BPA_SWI_EXCIT81_CARDKEY=0,
	BPA_SWI_EXCIT81_BUS_NAME,
	BPA_SWI_EXCIT81_BUS_KV,
	BPA_SWI_EXCIT81_GEN_ID,
	BPA_SWI_EXCIT81_RC,
	BPA_SWI_EXCIT81_XC,
	BPA_SWI_EXCIT81_TR,
	BPA_SWI_EXCIT81_VIAMAX_VAMAX,
	BPA_SWI_EXCIT81_VIMIN_VAMIN,
	BPA_SWI_EXCIT81_TB,
	BPA_SWI_EXCIT81_TC,
	BPA_SWI_EXCIT81_KA_BUSKV,
	BPA_SWI_EXCIT81_TA_TRH,
	BPA_SWI_EXCIT81_VRMAX_VAMAX,
	BPA_SWI_EXCIT81_VRMIN_VAMIN,
	BPA_SWI_EXCIT81_EFDMAX_VBMAX,
	BPA_SWI_EXCIT81_KE_KJ,
	BPA_SWI_EXCIT81_TE,
	BPA_SWI_EXCIT81_KEYNAME,
	BPA_SWI_EXCIT81_BUSPTR,
	BPA_SWI_EXCIT81_APPENDTAG
};
struct	_BpaMDBSwi_Exc81_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fRC;
	float	fXC;
	float	fTR;
	float	fVIAMax_VAMax;
	float	fVIMin_VAMin;
	float	fTB;
	float	fTC;
	float	fKA_BusKV;
	float	fTA_TRH;
	float	fVRMax_VAMax;
	float	fVRMin_VAMin;
	float	fEFDMax_VBMax;
	float	fKE_KJ;
	float	fTE;
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_Exc81_	tagBpaSwi_Exc81;

enum	_BpaMDBEnum_SwiField_FZ_{
	BPA_SWI_FZ_CARDKEY=0,
	BPA_SWI_FZ_BUS_NAME,
	BPA_SWI_FZ_BUS_KV,
	BPA_SWI_FZ_GEN_ID,
	BPA_SWI_FZ_SE1_KI,
	BPA_SWI_FZ_SE2_KP,
	BPA_SWI_FZ_EFDMIN_EFDN_DP,
	BPA_SWI_FZ_EFD1_VE1_EFDMAX,
	BPA_SWI_FZ_KF_KG,
	BPA_SWI_FZ_TF_VGMAX,
	BPA_SWI_FZ_KC,
	BPA_SWI_FZ_KD_XL,
	BPA_SWI_FZ_KB_VLV,
	BPA_SWI_FZ_KL_KLV,
	BPA_SWI_FZ_KH_KN,
	BPA_SWI_FZ_VLR_KR,
	BPA_SWI_FZ_KEYNAME,
	BPA_SWI_FZ_BUSPTR,
	BPA_SWI_FZ_APPENDTAG
};
struct	_BpaMDBSwi_FZ_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fSE1_KI;
	float	fSE2_KP;
	float	fEFDMin_EFDN_DP;
	float	fEFD1_VE1_EFDMax;
	float	fKF_KG;
	float	fTF_VGMax;
	float	fKC;
	float	fKD_XL;
	float	fKB_VLV;
	float	fKL_KLV;
	float	fKH_KN;
	float	fVLR_KR;
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_FZ_	tagBpaSwi_FZ;

enum	_BpaMDBEnum_SwiField_ExcMV_{
	BPA_SWI_EXCITMV_CARDKEY=0,
	BPA_SWI_EXCITMV_BUS_NAME,
	BPA_SWI_EXCITMV_BUS_KV,
	BPA_SWI_EXCITMV_GEN_ID,
	BPA_SWI_EXCITMV_RC,
	BPA_SWI_EXCITMV_XC,
	BPA_SWI_EXCITMV_TR,
	BPA_SWI_EXCITMV_K,
	BPA_SWI_EXCITMV_KV,
	BPA_SWI_EXCITMV_T1,
	BPA_SWI_EXCITMV_T2,
	BPA_SWI_EXCITMV_T3,
	BPA_SWI_EXCITMV_T4,
	BPA_SWI_EXCITMV_KA,
	BPA_SWI_EXCITMV_TA,
	BPA_SWI_EXCITMV_KF,
	BPA_SWI_EXCITMV_TF,
	BPA_SWI_EXCITMV_KH,
	BPA_SWI_EXCITMV_KEYNAME,
	BPA_SWI_EXCITMV_BUSPTR,
	BPA_SWI_EXCITMV_APPENDTAG
};

struct	_BpaMDBSwi_ExcMV_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fRC;
	float	fXC;
	float	fTR;
	float	fK;
	float	fKV;
	float	fT1;
	float	fT2;
	float	fT3;
	float	fT4;
	float	fKA;
	float	fTA;
	float	fKF;
	float	fTF;
	float	fKH;
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_ExcMV_	tagBpaSwi_ExcMV;

enum	_BpaMDBEnum_SwiField_FCA_{
	BPA_SWI_FCA_CARDKEY=0,
	BPA_SWI_FCA_BUS_NAME,
	BPA_SWI_FCA_BUS_KV,
	BPA_SWI_FCA_GEN_ID,

	BPA_SWI_FCA_VAMAX,
	BPA_SWI_FCA_VAMIN,
	BPA_SWI_FCA_KB,
	BPA_SWI_FCA_T5,
	BPA_SWI_FCA_KE,
	BPA_SWI_FCA_TE,
	BPA_SWI_FCA_SE1,
	BPA_SWI_FCA_SE2,
	BPA_SWI_FCA_VRMAX,
	BPA_SWI_FCA_VRMIN,
	BPA_SWI_FCA_KC,
	BPA_SWI_FCA_KD,
	BPA_SWI_FCA_KL1,
	BPA_SWI_FCA_VL1R,
	BPA_SWI_FCA_EFDMAX,

	BPA_SWI_FCA_KEYNAME,
	BPA_SWI_FCA_BUSPTR,
	BPA_SWI_FCA_APPENDTAG
};

struct	_BpaMDBSwi_FCA_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;

	float	fVAMax;
	float	fVAMin;
	float	fKB;
	float	fT5;
	float	fKE;
	float	fTE;
	float	fSE1;
	float	fSE2;
	float	fVRMax;
	float	fVRMin;
	float	fKC;
	float	fKD;
	float	fKL1;
	float	fVL1R;
	float	fEFDMax;

	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_FCA_	tagBpaSwi_FCA;

enum	_BpaMDBEnum_SwiField_FCB_{
	BPA_SWI_FCB_CARDKEY=0,
	BPA_SWI_FCB_BUS_NAME,
	BPA_SWI_FCB_BUS_KV,
	BPA_SWI_FCB_GEN_ID,

	BPA_SWI_FCB_IPID,
	BPA_SWI_FCB_KP,
	BPA_SWI_FCB_KI,
	BPA_SWI_FCB_KD,
	BPA_SWI_FCB_TD,
	BPA_SWI_FCB_INTMAX,
	BPA_SWI_FCB_INTMIN,
	BPA_SWI_FCB_DEVMAX,
	BPA_SWI_FCB_DEVMIN,

	BPA_SWI_FCB_VALMAX,
	BPA_SWI_FCB_VALMIN,
	BPA_SWI_FCB_IFUFV,

	BPA_SWI_FCB_KEYNAME,
	BPA_SWI_FCB_BUSPTR,
	BPA_SWI_FCB_APPENDTAG
};

struct	_BpaMDBSwi_FCB_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;

	unsigned char	nIPID;
	float	fExKP;
	float	fExKI;
	float	fExKD;
	float	fExTD;
	float	fINTMAX;
	float	fINTMIN;
	float	fDEVMAX;
	float	fDEVMIN;

	float	fVAlMax;
	float	fVAlMin;
	unsigned char	bIFUFV;

	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_FCB_	tagBpaSwi_FCB;

enum	_BpaMDBEnum_SwiField_ExcX_{
	BPA_SWI_EXCITX_CARDKEY=0,
	BPA_SWI_EXCITX_BUS_NAME,
	BPA_SWI_EXCITX_BUS_KV,
	BPA_SWI_EXCITX_GEN_ID,
	BPA_SWI_EXCITX_RC,
	BPA_SWI_EXCITX_XC,
	BPA_SWI_EXCITX_TR,
	BPA_SWI_EXCITX_KA,
	BPA_SWI_EXCITX_TA,
	BPA_SWI_EXCITX_KP,
	BPA_SWI_EXCITX_KI,
	BPA_SWI_EXCITX_VRMAX,
	BPA_SWI_EXCITX_VRMIN,
	BPA_SWI_EXCITX_IKP,
	BPA_SWI_EXCITX_IKI,
	BPA_SWI_EXCITX_VFMAX,
	BPA_SWI_EXCITX_VFMIN,
	BPA_SWI_EXCITX_KT,
	BPA_SWI_EXCITX_TT,

	BPA_SWI_EXCITXEX_KIFD,
	BPA_SWI_EXCITXEX_TIFD,
	BPA_SWI_EXCITXEX_EFDMIN,
	BPA_SWI_EXCITXEX_EFDMAX,

	BPA_SWI_EXCITX_KEYNAME,
	BPA_SWI_EXCITX_BUSPTR,
	BPA_SWI_EXCITX_APPENDTAG
};

struct	_BpaMDBSwi_ExcX_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fRC;
	float	fXC;
	float	fTR;
	float	fKA;
	float	fTA;
	float	fKp;
	float	fKI;
	float	fVRMax;
	float	fVRMin;
	float	fIKp;
	float	fIKI;
	float	fVFMax;
	float	fVFMin;
	float	fKT;
	float	fTT;

	float	fKifd;
	float	fTifd;
	float	fEFDMin;
	float	fEFDMax;

	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_ExcX_	tagBpaSwi_ExcX;

enum	_BpaMDBEnum_SwiField_PssS_{
	BPA_SWI_PSSS_CARDKEY=0,
	BPA_SWI_PSSS_BUS_NAME,
	BPA_SWI_PSSS_BUS_KV,
	BPA_SWI_PSSS_GEN_ID,
	BPA_SWI_PSSS_KQV,
	BPA_SWI_PSSS_TQV,
	BPA_SWI_PSSS_KQS,
	BPA_SWI_PSSS_TQS,
	BPA_SWI_PSSS_TQ,
	BPA_SWI_PSSS_TQ1,
	BPA_SWI_PSSS_TQ1P,
	BPA_SWI_PSSS_TQ2,
	BPA_SWI_PSSS_TQ2P,
	BPA_SWI_PSSS_TQ3,
	BPA_SWI_PSSS_TQ3P,
	BPA_SWI_PSSS_VSMAX,
	BPA_SWI_PSSS_VCUTOFF,
	BPA_SWI_PSSS_VSLOW,
	BPA_SWI_PSSS_KQBASE,
	BPA_SWI_PSSS_RBUSNAME,
	BPA_SWI_PSSS_RBUSKV,
	BPA_SWI_PSSS_KEYNAME,
	BPA_SWI_PSSS_BUSPTR,
	BPA_SWI_PSSS_IRRBUS,
	BPA_SWI_PSSS_APPENDTAG,
};

struct	_BpaMDBSwi_PssS_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fKQV;
	float	fTQV;
	float	fKQS;
	float	fTQS;
	float	fTQ;
	float	fTQ1;
	float	fTQ1P;
	float	fTQ2;
	float	fTQ2P;
	float	fTQ3;
	float	fTQ3P;
	float	fVSmax;
	float	fVCutOff;
	float	fVSlow;
	float	fKQBase;
	char	szRBusName[MDB_CHARLEN_BPABUS];
	float	fRBuskV;
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	int		nPssRBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_PssS_	tagBpaSwi_PssS;

enum	_BpaMDBEnum_SwiField_PssST_{
	BPA_SWI_PSSST_CARDKEY=0,
	BPA_SWI_PSSST_BUS_NAME,
	BPA_SWI_PSSST_BUS_KV,
	BPA_SWI_PSSST_GEN_ID,
	BPA_SWI_PSSST_T1,
	BPA_SWI_PSSST_T2,
	BPA_SWI_PSSST_T3,
	BPA_SWI_PSSST_K,
	BPA_SWI_PSSST_DWT1,
	BPA_SWI_PSSST_DWT2,
	BPA_SWI_PSSST_DWPT,
	BPA_SWI_PSSST_TDELAY,
	BPA_SWI_PSSST_T4,
	BPA_SWI_PSSST_KEYNAME,
	BPA_SWI_PSSST_BUSPTR,
	BPA_SWI_PSSST_APPENDTAG,
};

struct	_BpaMDBSwi_PssST_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fT1;
	float	fT2;
	float	fT3;
	float	fK;
	float	fDWt1;
	float	fDWt2;
	float	fDWpt;
	float	fTDelay;
	float	fT4;
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_PssST_	tagBpaSwi_PssST;

enum	_BpaMDBEnum_SwiField_PssSH_{
	BPA_SWI_PSSSH_CARDKEY=0,
	BPA_SWI_PSSSH_BUS_NAME,
	BPA_SWI_PSSSH_BUS_KV,
	BPA_SWI_PSSSH_GEN_ID,
	BPA_SWI_PSSSH_TD,
	BPA_SWI_PSSSH_T1,
	BPA_SWI_PSSSH_T2,
	BPA_SWI_PSSSH_T3,
	BPA_SWI_PSSSH_K0,
	BPA_SWI_PSSSH_K1,
	BPA_SWI_PSSSH_K2,
	BPA_SWI_PSSSH_K3,
	BPA_SWI_PSSSH_K,
	BPA_SWI_PSSSH_VSMAX,
	BPA_SWI_PSSSH_VSMIN,
	BPA_SWI_PSSSH_KP,
	BPA_SWI_PSSSH_KMVA,

	BPA_SWI_PSSSHEX_KPM,
	BPA_SWI_PSSSHEX_TPM,
	BPA_SWI_PSSSHEX_KPE,
	BPA_SWI_PSSSHEX_TPE,
	BPA_SWI_PSSSHEX_KW,
	BPA_SWI_PSSSHEX_TW,
	BPA_SWI_PSSSHEX_TD1,
	BPA_SWI_PSSSHEX_TD2,
	BPA_SWI_PSSSHEX_KD1,
	BPA_SWI_PSSSHEX_T4,
	BPA_SWI_PSSSHEX_K4,
	BPA_SWI_PSSSHEX_KMVA,

	BPA_SWI_PSSSH_KEYNAME,
	BPA_SWI_PSSSH_BUSPTR,
	BPA_SWI_PSSSH_APPENDTAG,
};

struct	_BpaMDBSwi_PssSH_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fTD;
	float	fT1;
	float	fT2;
	float	fT3;
	float	fK0;
	float	fK1;
	float	fK2;
	float	fK3;
	float	fK;
	float	fVSMax;
	float	fVSMin;
	float	fKP;
	float	fKMVA;

	float	fKPMEx;
	float	fTPMEx;
	float	fKPEEx;
	float	fTPEEx;
	float	fKWEx;
	float	fTWEx;
	float	fTD1Ex;
	float	fTD2Ex;
	unsigned char	bKD1Ex;
	float	fT4Ex;
	float	fK4Ex;
	float	fKMVAEx;

	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_PssSH_	tagBpaSwi_PssSH;

enum	_BpaMDBEnum_SwiField_PssSI_{
	BPA_SWI_PSSSI_CARDKEY=0,
	BPA_SWI_PSSSI_BUS_NAME,
	BPA_SWI_PSSSI_BUS_KV,
	BPA_SWI_PSSSI_GEN_ID,
	BPA_SWI_PSSSI_TRW,
	BPA_SWI_PSSSI_T5,
	BPA_SWI_PSSSI_T6,
	BPA_SWI_PSSSI_T7,
	BPA_SWI_PSSSI_KR,
	BPA_SWI_PSSSI_TRP,
	BPA_SWI_PSSSI_TW,
	BPA_SWI_PSSSI_TW1,
	BPA_SWI_PSSSI_TW2,
	BPA_SWI_PSSSI_KS,
	BPA_SWI_PSSSI_T9,
	BPA_SWI_PSSSI_T10,
	BPA_SWI_PSSSI_T12,
	BPA_SWI_PSSSI_INP,
	BPA_SWI_PSSSI_KP,
	BPA_SWI_PSSSI_T1,
	BPA_SWI_PSSSI_T2,
	BPA_SWI_PSSSI_T13,
	BPA_SWI_PSSSI_T14,
	BPA_SWI_PSSSI_T3,
	BPA_SWI_PSSSI_T4,
	BPA_SWI_PSSSI_VSMAX,
	BPA_SWI_PSSSI_VSMIN,
	BPA_SWI_PSSSI_IB,
	BPA_SWI_PSSSI_MEABUSNAME,
	BPA_SWI_PSSSI_MEABUSKV,
	BPA_SWI_PSSSI_KMVA,
	BPA_SWI_PSSSI_KEYNAME,
	BPA_SWI_PSSSI_BUSPTR,
	BPA_SWI_PSSSI_IRMEABUS,
	BPA_SWI_PSSSI_APPENDTAG,
};


struct	_BpaMDBSwi_PssSI_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fTRW;
	float	fT5;
	float	fT6;
	float	fT7;
	float	fKR;
	float	fTRP;
	float	fTW;
	float	fTW1;
	float	fTW2;
	float	fKS;
	float	fT9;
	float	fT10;
	float	fT12;
	unsigned char	cINP;
	float	fKP;
	float	fT1;
	float	fT2;
	float	fT13;
	float	fT14;
	float	fT3;
	float	fT4;
	float	fVSMax;
	float	fVSMin;
	unsigned char	bIB;
	char	szMeaBusName[MDB_CHARLEN_BPABUS];
	float	fMeaBusKV;
	float	fKMVA;
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	int		nMeaBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_PssSI_	tagBpaSwi_PssSI;

enum	_BpaMDBEnum_SwiField_PssSA_{
	BPA_SWI_PSSSA_CARDKEY=0,
	BPA_SWI_PSSSA_BUS_NAME,
	BPA_SWI_PSSSA_BUS_KV,
	BPA_SWI_PSSSA_GEN_ID,
	BPA_SWI_PSSSA_T1,
	BPA_SWI_PSSSA_T2,
	BPA_SWI_PSSSA_T3,
	BPA_SWI_PSSSA_T4,
	BPA_SWI_PSSSA_T5,
	BPA_SWI_PSSSA_T6,
	BPA_SWI_PSSSA_K1,
	BPA_SWI_PSSSA_K2,
	BPA_SWI_PSSSA_K,
	BPA_SWI_PSSSA_A,
	BPA_SWI_PSSSA_P,
	BPA_SWI_PSSSA_LIMITMAX,
	BPA_SWI_PSSSA_LIMITMIN,
	BPA_SWI_PSSSA_KMVA,
	BPA_SWI_PSSSA_KEYNAME,
	BPA_SWI_PSSSA_BUSPTR,
	BPA_SWI_PSSSA_APPENDTAG,
};

struct	_BpaMDBSwi_PssSA_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];
	char	szBus_Name[MDB_CHARLEN_BPABUS];
	float	fBus_kV;
	char	cGen_ID;
	float	fT1;
	float	fT2;
	float	fT3;
	float	fT4;
	float	fT5;
	float	fT6;
	float	fK1;
	float	fK2;
	float	fK;
	float	fA;
	float	fP;
	float	fLimitMax;
	float	fLimitMin;
	float	fKMVA;
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_PssSA_	tagBpaSwi_PssSA;

enum	_BpaMDBEnum_SwiField_PssSB_{
	BPA_SWI_PSSSB_CARDKEY=0,
	BPA_SWI_PSSSB_BUS_NAME,
	BPA_SWI_PSSSB_BUS_KV,
	BPA_SWI_PSSSB_GEN_ID,
	BPA_SWI_PSSSB_ISIG,
	BPA_SWI_PSSSB_TD,
	BPA_SWI_PSSSB_TW1,
	BPA_SWI_PSSSB_TW2,
	BPA_SWI_PSSSB_T6,
	BPA_SWI_PSSSB_TW3,
	BPA_SWI_PSSSB_TW4,
	BPA_SWI_PSSSB_T7,
	BPA_SWI_PSSSB_KS2,
	BPA_SWI_PSSSB_KS3,
	BPA_SWI_PSSSB_KPG,
	BPA_SWI_PSSSB_MVA_BSE,
	BPA_SWI_PSSSB_T8,
	BPA_SWI_PSSSB_T9,
	BPA_SWI_PSSSB_M,
	BPA_SWI_PSSSB_N,
	BPA_SWI_PSSSB_KS1,
	BPA_SWI_PSSSB_T1,
	BPA_SWI_PSSSB_T2,
	BPA_SWI_PSSSB_T3,
	BPA_SWI_PSSSB_T4,
	BPA_SWI_PSSSB_VPMAX,
	BPA_SWI_PSSSB_VPMIN,
	BPA_SWI_PSSSB_KEYNAME,
	BPA_SWI_PSSSB_BUSPTR,
	BPA_SWI_PSSSB_APPENDTAG,
};

struct	_BpaMDBSwi_PssSB_	{
	char					szCardKey[MDB_CHARLEN_SHORTEST];
	char					szBus_Name[MDB_CHARLEN_BPABUS];
	float					fBus_kV;
	char					cGen_ID;
	unsigned char			bISIG;
	float					fTD;
	float					fTW1;
	float					fTW2;
	float					fT6;
	float					fTW3;
	float					fTW4;
	float					fT7;
	float					fKS2;
	float					fKS3;
	float					fKPG;
	float					fMVA_BSE;
	float					fT8;
	float					fT9;
	unsigned char			bM;
	unsigned char			bN;
	float					fKS1;
	float					fT1;
	float					fT2;
	float					fT3;
	float					fT4;
	float					fVPMAX;
	float					fVPMIN;
	char					szKeyName[MDB_CHARLEN_SHORTER];
	int						nGenBus;		//
	unsigned char			bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_PssSB_	tagBpaSwi_PssSB;

enum	_BpaMDBEnum_SwiField_GG_{
	BPA_SWI_GG_CARDKEY=0,
	BPA_SWI_GG_BUS_NAME,
	BPA_SWI_GG_BUS_KV,
	BPA_SWI_GG_GEN_ID,
	BPA_SWI_GG_PMAX,
	BPA_SWI_GG_R,
	BPA_SWI_GG_T1,
	BPA_SWI_GG_T2,
	BPA_SWI_GG_T3,
	BPA_SWI_GG_T4,
	BPA_SWI_GG_T5,
	BPA_SWI_GG_F,
	BPA_SWI_GG_KEYNAME,
	BPA_SWI_GG_BUSPTR,
	BPA_SWI_GG_APPENDTAG,
};

struct	_BpaMDBSwi_GG_	{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fPmax;
	float		fR;
	float		fT1;
	float		fT2;
	float		fT3;
	float		fT4;
	float		fT5;
	float		fF;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GG_	tagBpaSwi_GovGG;

enum	_BpaMDBEnum_SwiField_GH_
{
	BPA_SWI_GH_CARDKEY=0,
	BPA_SWI_GH_BUS_NAME,
	BPA_SWI_GH_BUS_KV,
	BPA_SWI_GH_GEN_ID,
	BPA_SWI_GH_PMAX,
	BPA_SWI_GH_R,
	BPA_SWI_GH_TG,
	BPA_SWI_GH_TP,
	BPA_SWI_GH_TD,
	BPA_SWI_GH_TW_HALF,
	BPA_SWI_GH_VELCLOSE,
	BPA_SWI_GH_VELOPEN,
	BPA_SWI_GH_DD,
	BPA_SWI_GH_E,
	BPA_SWI_GH_KEYNAME,
	BPA_SWI_GH_BUSPTR,
	BPA_SWI_GH_APPENDTAG,
};

struct	_BpaMDBSwi_GH_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fPmax;
	float		fR;
	float		fTG;
	float		fTP;
	float		fTd;
	float		fTw_Half;
	float		fVELclose;
	float		fVELopen ;
	float		fDd;
	float		fE;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GH_	tagBpaSwi_GovGH;

enum	_BpaMDBEnum_SwiField_GC_{
	BPA_SWI_GC_CARDKEY=0,
	BPA_SWI_GC_BUS_NAME,
	BPA_SWI_GC_BUS_KV,
	BPA_SWI_GC_GEN_ID,
	BPA_SWI_GC_PMAX,
	BPA_SWI_GC_R,
	BPA_SWI_GC_T1,
	BPA_SWI_GC_T2,
	BPA_SWI_GC_T3,
	BPA_SWI_GC_T4,
	BPA_SWI_GC_T5,
	BPA_SWI_GC_F,
	BPA_SWI_GC_DH,
	BPA_SWI_GC_KEYNAME,
	BPA_SWI_GC_BUSPTR,
	BPA_SWI_GC_APPENDTAG,
};

struct	_BpaMDBSwi_GC_	{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fPmax;
	float		fR;
	float		fT1;
	float		fT2;
	float		fT3;
	float		fT4;
	float		fT5;
	float		fF;
	float		fDH;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GC_	tagBpaSwi_GovGC;

enum	_BpaMDBEnum_SwiField_GS_
{
	BPA_SWI_GS_CARDKEY=0,
	BPA_SWI_GS_BUS_NAME,
	BPA_SWI_GS_BUS_KV,
	BPA_SWI_GS_GEN_ID,
	BPA_SWI_GS_PMAX,
	BPA_SWI_GS_PMIN,
	BPA_SWI_GS_R,
	BPA_SWI_GS_T1,
	BPA_SWI_GS_T2,
	BPA_SWI_GS_T3,
	BPA_SWI_GS_VELOPEN,
	BPA_SWI_GS_VELCLOSE,
	BPA_SWI_GS_E,
	BPA_SWI_GS_KEYNAME,
	BPA_SWI_GS_BUSPTR,
	BPA_SWI_GS_APPENDTAG,
};


struct	_BpaMDBSwi_GS_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fPmax;
	float		fPmin;
	float		fR;
	float		fT1;
	float		fT2;
	float		fT3;
	float		fVELopen;
	float		fVELclose;
	float		fE;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GS_	tagBpaSwi_GovGS;

enum	_BpaMDBEnum_SwiField_GL_
{
	BPA_SWI_GL_CARDKEY=0,
	BPA_SWI_GL_BUS_NAME,
	BPA_SWI_GL_BUS_KV,
	BPA_SWI_GL_GEN_ID,
	BPA_SWI_GL_PE,
	BPA_SWI_GL_K,
	BPA_SWI_GL_E,
	BPA_SWI_GL_TR,
	BPA_SWI_GL_TB,
	BPA_SWI_GL_TO,
	BPA_SWI_GL_TC,
	BPA_SWI_GL_VELCLOSE,
	BPA_SWI_GL_VELOPEN,
	BPA_SWI_GL_PMAX,
	BPA_SWI_GL_PMIN,
	BPA_SWI_GL_KEYNAME,
	BPA_SWI_GL_BUSPTR,
	BPA_SWI_GL_APPENDTAG,
};

struct	_BpaMDBSwi_GL_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fPe;
	float		fK;
	float		fE;
	float		fTr;
	float		fTb;
	float		fTo;
	float		fTc;
	float		fVELclose;
	float		fVELopen ;
	float		fPmax    ;
	float		fPmin;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GL_	tagBpaSwi_GovGL;

enum	_BpaMDBEnum_SwiField_GW_
{
	BPA_SWI_GW_CARDKEY=0,
	BPA_SWI_GW_BUS_NAME,
	BPA_SWI_GW_BUS_KV,
	BPA_SWI_GW_GEN_ID,
	BPA_SWI_GW_PMAX,
	BPA_SWI_GW_PMIN,
	BPA_SWI_GW_R,
	BPA_SWI_GW_T1,
	BPA_SWI_GW_T2,
	BPA_SWI_GW_T3,
	BPA_SWI_GW_KEYNAME,
	BPA_SWI_GW_BUSPTR,
	BPA_SWI_GW_APPENDTAG,
};

struct	_BpaMDBSwi_GW_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fPmax;
	float		fPmin;
	float		fR;
	float		fT1;
	float		fT2;
	float		fT3;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GW_	tagBpaSwi_GovGW;

enum	_BpaMDBEnum_SwiField_GA_
{
	BPA_SWI_GA_CARDKEY=0,
	BPA_SWI_GA_BUS_NAME,
	BPA_SWI_GA_BUS_KV,
	BPA_SWI_GA_GEN_ID,
	BPA_SWI_GA_PE,
	BPA_SWI_GA_TC,
	BPA_SWI_GA_TO,
	BPA_SWI_GA_VELCLOSE,
	BPA_SWI_GA_VELOPEN,
	BPA_SWI_GA_PMAX,
	BPA_SWI_GA_PMIN,
	BPA_SWI_GA_T1,
	BPA_SWI_GA_KP,
	BPA_SWI_GA_KD,
	BPA_SWI_GA_KI,
	BPA_SWI_GA_INTG_MAX,
	BPA_SWI_GA_INTG_MIN,
	BPA_SWI_GA_PID_MAX,
	BPA_SWI_GA_PID_MIN,
	BPA_SWI_GA_PGV_DELAY,
	BPA_SWI_GA_KEYNAME,
	BPA_SWI_GA_BUSPTR,
	BPA_SWI_GA_APPENDTAG,
};

struct	_BpaMDBSwi_GA_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fPe;
	float		fTc;
	float		fTo;
	float		fVELclose;
	float		fVELopen;
	float		fPmax;
	float		fPmin;
	float		fT1;
	float		fKP;
	float		fKD;
	float		fKI;
	float		fINTG_MAX;
	float		fINTG_MIN;
	float		fPID_MAX;
	float		fPID_MIN;
	float		fPGV_Delay;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GA_	tagBpaSwi_GovGA;

enum	_BpaMDBEnum_SwiField_GI_
{
	BPA_SWI_GI_CARDKEY=0,
	BPA_SWI_GI_BUS_NAME,
	BPA_SWI_GI_BUS_KV,
	BPA_SWI_GI_GEN_ID,
	BPA_SWI_GI_T1,
	BPA_SWI_GI_E,
	BPA_SWI_GI_K,
	BPA_SWI_GI_I1,
	BPA_SWI_GI_KP1,
	BPA_SWI_GI_KD1,
	BPA_SWI_GI_KI1,
	BPA_SWI_GI_INTG_MAX1,
	BPA_SWI_GI_INTG_MIN1,
	BPA_SWI_GI_PID_MAX1,
	BPA_SWI_GI_PID_MIN1,
	BPA_SWI_GI_I_FEED,
	BPA_SWI_GI_W_MAX,
	BPA_SWI_GI_W_MIN,
	BPA_SWI_GI_I2,
	BPA_SWI_GI_KP2,
	BPA_SWI_GI_KD2,
	BPA_SWI_GI_KI2,
	BPA_SWI_GI_INTG_MAX2,
	BPA_SWI_GI_INTG_MIN2,
	BPA_SWI_GI_PID_MAX2,
	BPA_SWI_GI_PID_MIN2,
	BPA_SWI_GI_CON_MAX,
	BPA_SWI_GI_CON_MIN,
	BPA_SWI_GI_KEYNAME,
	BPA_SWI_GI_BUSPTR,
	BPA_SWI_GI_APPENDTAG,
};

struct	_BpaMDBSwi_GI_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;
	float			fBus_kV;
	char			cGen_ID;
	float			fT1;
	float			fE;
	float			fK;
	unsigned char	bI1;
	float			fKP1;
	float			fKD1;
	float			fKI1;
	float			fINTG_MAX1;
	float			fINTG_MIN1;
	float			fPID_MAX1;
	float			fPID_MIN1;
	unsigned char	bI_Feed;
	float			fW_MAX;
	float			fW_MIN;

	unsigned char	bI2;
	float			fKP2;
	float			fKD2;
	float			fKI2;
	float			fINTG_MAX2;
	float			fINTG_MIN2;
	float			fPID_MAX2;
	float			fPID_MIN2;
	float			fCON_MAX;
	float			fCON_MIN;
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GI_	tagBpaSwi_GovGI;

enum	_BpaMDBEnum_SwiField_GJ_
{
	BPA_SWI_GJ_CARDKEY=0,
	BPA_SWI_GJ_BUS_NAME,
	BPA_SWI_GJ_BUS_KV,
	BPA_SWI_GJ_GEN_ID,
	BPA_SWI_GJ_T1,
	BPA_SWI_GJ_E,
	BPA_SWI_GJ_K1,
	BPA_SWI_GJ_I,
	BPA_SWI_GJ_KP,
	BPA_SWI_GJ_KD,
	BPA_SWI_GJ_KI,
	BPA_SWI_GJ_INTG_MAX,
	BPA_SWI_GJ_INTG_MIN,
	BPA_SWI_GJ_PID_MAX,
	BPA_SWI_GJ_PID_MIN,
	BPA_SWI_GJ_K2,
	BPA_SWI_GJ_W_MAX,
	BPA_SWI_GJ_W_MIN,
	BPA_SWI_GJ_TW_DELAY,
	BPA_SWI_GJ_TP_DELAY,
	BPA_SWI_GJ_TR,
	BPA_SWI_GJ_KEYNAME,
	BPA_SWI_GJ_BUSPTR,
	BPA_SWI_GJ_APPENDTAG,
};

struct	_BpaMDBSwi_GJ_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	卡类型
	char			szBus_Name[MDB_CHARLEN_BPABUS];	//	4	11	A8	发电机名称
	float			fBus_kV;						//	12	15	F4.0	发电机基准电压(kV)
	char			cGen_ID;						//	16	16	A1	BusID识别码ID
	float			fT1;							//	17	21	F5.3	转速测量环节时间常数(秒)
	float			fE;								//	22	27	F6.4	转速偏差死区
	float			fK1;							//	28	32	F5.2	转速偏差放大倍数
	unsigned char	bI;								//	33	33	I1	控制方式选择
	float			fKP;							//	34	38	F5.3	PID比例环节倍数
	float			fKD;							//	39	43	F5.3	PID微分环节倍数
	float			fKI;							//	44	48	F5.3	PID积分环节倍数
	float			fINTG_MAX;						//	49	52	F4.2	PID积分环节限幅上限
	float			fINTG_MIN;						//	53	56	F4.2	PID积分环节限幅下限
	float			fPID_MAX;						//	57	60	F4.2	PID输出限幅环节的上限
	float			fPID_MIN;						//	61	64	F4.2	PID输出限幅环节的下限
	float			fK2;							//	65	69	F5.3	负荷控制前馈系数
	float			fW_MAX;							//	70	74	F5.3	一次调频负荷上限
	float			fW_MIN;							//	75	79	F5.3	一次调频负荷下限
	float			fTW_DELAY;						//	17	21	F5.0	频率输入信号的纯延迟时间(秒)
	float			fTP_DELAY;						//	22	26	F5.0	功率反馈信号的纯延迟时间(秒)
	float			fTR;							//	27	31	F5.0	功率反馈信号对应的一阶惯性环节时间常数(秒)
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GJ_	tagBpaSwi_GovGJ;

enum	_BpaMDBEnum_SwiField_GK_
{
	BPA_SWI_GK_CARDKEY=0,
	BPA_SWI_GK_BUS_NAME,
	BPA_SWI_GK_BUS_KV,
	BPA_SWI_GK_GEN_ID,
	BPA_SWI_GK_TW,
	BPA_SWI_GK_E,
	BPA_SWI_GK_I,
	BPA_SWI_GK_K1,
	BPA_SWI_GK_K2,
	BPA_SWI_GK_I_CONTROL,
	BPA_SWI_GK_KP,
	BPA_SWI_GK_KD,
	BPA_SWI_GK_KI,
	BPA_SWI_GK_INTG_MAX,
	BPA_SWI_GK_INTG_MIN,
	BPA_SWI_GK_PID_MAX,
	BPA_SWI_GK_PID_MIN,
	BPA_SWI_GK_W_MAX,
	BPA_SWI_GK_W_MIN,
	BPA_SWI_GK_KEYNAME,
	BPA_SWI_GK_BUSPTR,
	BPA_SWI_GK_APPENDTAG,
};

struct	_BpaMDBSwi_GK_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char				szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	发电机名称
	float				fBus_kV;							//	12	15	F4.0	发电机基准电压(kV)
	char				cGen_ID;							//	16	16	A1	BusID识别码ID
	float				fTW;								//	17	21	F5.3	转速偏差滤波器的时间常数(秒)
	float				fE;									//	22	27	F6.4	转速偏差死区
	unsigned char		bI;									//	28	28	I1	转速采用滤波器或死区方式选择
	float				fK1;								//	29	33	F5.2	转速偏差放大倍数
	float				fK2;								//	34	37	F4.2	主汽压力偏差放大倍数
	unsigned char		bI_Control;							//	38	38	I1	控制方式选择
	float				fKP;								//	39	43	F5.3	PID比例环节倍数
	float				fKD;								//	44	48	F5.3	PID微分环节倍数
	float				fKI;								//	49	53	F5.3	PID积分环节倍数
	float				fINTG_MAX;							//	54	57	F4.2	PID积分环节限幅上限
	float				fINTG_MIN;							//	58	61	F4.2	PID积分环节限幅下限
	float				fPID_MAX;							//	62	65	F4.2	PID输出限幅环节的上限
	float				fPID_MIN;							//	66	69	F4.2	PID输出限幅环节的下限
	float				fW_MAX;								//	70	74	F5.3	一次调频负荷上限
	float				fW_MIN;								//	75	79	F5.3	一次调频负荷下限
	char				szKeyName[MDB_CHARLEN_SHORTER];
	int					nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GK_	tagBpaSwi_GovGK;

enum	_BpaMDBEnum_SwiField_GM_
{
	BPA_SWI_GM_CARDKEY=0,
	BPA_SWI_GM_BUS_NAME,
	BPA_SWI_GM_BUS_KV,
	BPA_SWI_GM_GEN_ID,
	BPA_SWI_GM_KW,
	BPA_SWI_GM_TR,
	BPA_SWI_GM_NEGATIVE_DB1,
	BPA_SWI_GM_DB1,
	BPA_SWI_GM_KP,
	BPA_SWI_GM_KD,
	BPA_SWI_GM_KI,
	BPA_SWI_GM_TD,
	BPA_SWI_GM_INTG_MAX,
	BPA_SWI_GM_INTG_MIN,
	BPA_SWI_GM_PID_MAX,
	BPA_SWI_GM_PID_MIN,
	BPA_SWI_GM_DELT,
	BPA_SWI_GM_DB_MAX,
	BPA_SWI_GM_DB_MIN,
	BPA_SWI_GM_DELT2,
	BPA_SWI_GM_TR2,
	BPA_SWI_GM_EP,
	BPA_SWI_GM_NEGATIVE_DB2,
	BPA_SWI_GM_DB2,
	BPA_SWI_GM_DBMAX2,
	BPA_SWI_GM_DBMIN2,
	BPA_SWI_GM_ITYP,
	BPA_SWI_GM_ITYP2,
	BPA_SWI_GM_KEYNAME,
	BPA_SWI_GM_BUSPTR,
	BPA_SWI_GM_APPENDTAG,
};

struct	_BpaMDBSwi_GM_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	卡类型
	char			szBus_Name[MDB_CHARLEN_BPABUS];	//	4	11	A8	发电机名称
	float			fBus_kV;						//	12	15	F4.0	发电机基准电压(kV)
	char			cGen_ID;						//	16	16	A1	BusID识别码ID
	float			fKW;							//	17	21	F5.0	频率偏差放大倍数
	float			fTR;							//	22	25	F4.4	频率测量环节时间常数(秒)
	float			fNegative_DB1;					//	26	29	F4.4	转速调节死区(负方向，相对于额定频率的标么值)
	float			fDB1;							//	30	33	F4.4	转速调节死区(正方向，相对于额定频率的标么值)
	float			fKP;							//	34	38	F5.0	PID比例环节放大倍数
	float			fKD;							//	39	43	F5.0	PID微分环节放大倍数
	float			fKI;							//	44	48	F5.0	PID积分环节放大倍数
	float			fTD;							//	49	52	F4.4	PID微分环节时间常数(秒)
	float			fINTG_MAX;						//	53	56	F4.4	PID积分环节限幅上限
	float			fINTG_MIN;						//	57	60	F4.4	PID积分环节限幅下限
	float			fPID_MAX;						//	61	64	F4.4	PID输出限幅环节的上限
	float			fPID_MIN;						//	65	68	F4.4	PID输出限幅环节的下限
	float			fDELT;							//	69	72	F4.4	DELT，转速测量的延迟时间(秒)
	float			fDB_MAX;						//	73	76	F4.4	一次调频上限
	float			fDB_MIN;						//	77	80	F4.4	一次调频下限
	float			fDELT2;							//	17	21	F4.4	测量延迟时间(秒)
	float			fTR2;							//	22	25	F4.4	测量环节时间常数(秒)
	float			fEP;							//	26	29	F5.0	系数
	float			fNegative_DB2;					//	30	33	F5.0	负方向死区
	float			fDB2;							//	34	38	F5.0	正方向死区
	float			fDBMAX2;						//	39	43	F5.0	限幅上限
	float			fDBMIN2;						//	44	48	F5.0	限幅下限
	unsigned char	bITYP;							//	49	52	I1	模式选择
	unsigned char	bITYP2;							//	53	56	I1	开度模式选择
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GM_	tagBpaSwi_GovGM;

enum	_BpaMDBEnum_SwiField_GD_
{
	BPA_SWI_GD_CARDKEY=0,
	BPA_SWI_GD_BUS_NAME,
	BPA_SWI_GD_BUS_KV,
	BPA_SWI_GD_GEN_ID,
	BPA_SWI_GD_PMAX,
	BPA_SWI_GD_PMIN,
	BPA_SWI_GD_DB,
	BPA_SWI_GD_R,
	BPA_SWI_GD_KP,
	BPA_SWI_GD_KI,
	BPA_SWI_GD_KD,
	BPA_SWI_GD_GOV_MAX,
	BPA_SWI_GD_GOV_MIN,
	BPA_SWI_GD_DEMAND_MAX,
	BPA_SWI_GD_DEMAND_MIN,
	BPA_SWI_GD_KEYNAME,
	BPA_SWI_GD_BUSPTR,
	BPA_SWI_GD_APPENDTAG,
};


struct	_BpaMDBSwi_GD_
{
	char	szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char	szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	发电机名称
	float	fBus_kV;							//	12	15	F4.0	发电机基准电压(kV)
	char	cGen_ID;							//	16	16	A1	BusID识别码ID
	float	fPmax;								//	17	22	F6.1	最大输出机械功率
	float	fPmin;								//	23	28	F6.1	最小输出机械功率
	float	fDB;								//	29	33	F5.3	Δω的死区(Hz)
	float	fR;									//	34	38	F5.3	稳态偏差(pu)
	float	fKp;								//	39	43	F5.3	比例环节增益(pu/pu)
	float	fKi;								//	44	48	F5.3	积分环节增益(pu/sec)
	float	fKd;								//	49	53	F5.3	微分环节增益(pu·sec)
	float	fGOV_MAX;							//	54	58	F5.3	积分环节上限(pu)
	float	fGOV_Min;							//	59	63	F5.3	积分环节下限(pu)
	float	fDEMAND_MAX;						//	64	68	F5.3	输出上限(pu)
	float	fDEMAND_MIN;						//	69	73	F5.3	输出下限(pu)
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GD_	tagBpaSwi_GovGD;

enum	_BpaMDBEnum_SwiField_GZ_
{
	BPA_SWI_GZ_CARDKEY=0,
	BPA_SWI_GZ_BUS_NAME,
	BPA_SWI_GZ_BUS_KV,
	BPA_SWI_GZ_GEN_ID,
	BPA_SWI_GZ_TSM,
	BPA_SWI_GZ_ROPEN,
	BPA_SWI_GZ_RCLOSE,
	BPA_SWI_GZ_EHC_MAX,
	BPA_SWI_GZ_EHC_MIN,
	BPA_SWI_GZ_T_OPEN,
	BPA_SWI_GZ_T_CLOSE,
	BPA_SWI_GZ_DB_VALUE,
	BPA_SWI_GZ_CV_MAX,
	BPA_SWI_GZ_CV_MIN,
	BPA_SWI_GZ_KPE,
	BPA_SWI_GZ_TPE,
	BPA_SWI_GZ_MODE,
	BPA_SWI_GZ_KEYNAME,
	BPA_SWI_GZ_BUSPTR,
	BPA_SWI_GZ_APPENDTAG,
};


struct	_BpaMDBSwi_GZ_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	卡类型
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	发电机名称
	float			fBus_kV;								//	12	15	F4.0	发电机基准电压(kV)
	char			cGen_ID;								//	16	16	A1	BusID识别码ID
	float			fG_Tsm;									//	17	21	F5.3	伺服系统时间常数(秒)
	float			fG_Ropen;								//	22	26	F5.3	汽门最大开启速度(p.u. gate/sec)
	float			fG_Rclose;								//	27	31	F5.3	汽门最大关闭速度(p.u. gate/sec)
	float			fG_EHC_MAX;								//	32	36	F5.3	EHC最大位置限制(pu)
	float			fG_EHC_MIN;								//	37	41	F5.3	EHC最小位置限制(pu)
	float			fG_T_Open;								//	42	46	F5.3	控制阀开启时间常数(sec)
	float			fG_T_Close;								//	47	51	F5.3	控制阀关闭时间常数(sec)
	float			fG_DB_Value;							//	52	56	F5.3	阀的死区(pu)
	float			fG_CV_MAX;								//	57	61	F5.3	阀的死区(pu)
	float			fG_CV_MIN;								//	62	66	F5.3	控制阀下限(pu)
	float			fG_Kpe;									//	67	71	F5.3	电磁功率反馈增益(pu/ pu)
	float			fG_Tpe;									//	72	76	F5.3	电磁功率反馈时间常数(sec)
	unsigned char	bG_Mode;								//	78	78	I1	控制模式
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GZ_	tagBpaSwi_GovGZ;

enum	_BpaMDBEnum_SwiField_TA_
{
	BPA_SWI_TA_CARDKEY=0,
	BPA_SWI_TA_BUS_NAME,
	BPA_SWI_TA_BUS_KV,
	BPA_SWI_TA_GEN_ID,
	BPA_SWI_TA_TCH,
	BPA_SWI_TA_K1,
	BPA_SWI_TA_KEYNAME,
	BPA_SWI_TA_BUSPTR,
	BPA_SWI_TA_APPENDTAG,
};

struct	_BpaMDBSwi_TA_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char			szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	发电机名称
	float			fBus_kV;							//	12	15	F4.0	发电机基准电压(kV)
	char			cGen_ID;							//	16	16	A1	BusID识别码ID
	float			fTCH;								//	17	21	F5.3	蒸汽容积时间常数(秒)
	float			fK1;								//	22	26	F5.3	"汽轮机K1=1.0；水轮机K1=-2.0(必须)",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TA_	tagBpaSwi_MovTA;

enum	_BpaMDBEnum_SwiField_TB_
{
	BPA_SWI_TB_CARDKEY=0,
	BPA_SWI_TB_BUS_NAME,
	BPA_SWI_TB_BUS_KV,
	BPA_SWI_TB_GEN_ID,
	BPA_SWI_TB_TCH,
	BPA_SWI_TB_FHP,
	BPA_SWI_TB_TRH,
	BPA_SWI_TB_FIP,
	BPA_SWI_TB_TCO,
	BPA_SWI_TB_FLP,
	BPA_SWI_TB_LAMBDA,
	BPA_SWI_TB_KEYNAME,
	BPA_SWI_TB_BUSPTR,
	BPA_SWI_TB_APPENDTAG,
};

struct	_BpaMDBSwi_TB_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	卡类型
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	发电机名称
	float			fBus_kV;								//	12	15	F4.0	发电机基准电压(kV)
	char			cGen_ID;								//	16	16	A1	BusID识别码ID
	float			fTCH;									//	17	21	F5.3	"蒸汽容积时间常数(秒)",
	float			fFHP;									//	22	26	F5.3	"高压缸功率比例",
	float			fTRH;									//	32	36	F5.3	"再热器时间常数",
	float			fFIP;									//	37	41	F5.3	"中压缸功率比例",
	float			fTCO;									//	47	51	F5.3	"交叉管时间常数",
	float			fFLP;									//	52	56	F5.3	"低压缸功率比例或比例的一半",
	float			fLambda;								//	77	80	F4.2	"高压缸功率自然过调系数",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TB_	tagBpaSwi_MovTB;

enum	_BpaMDBEnum_SwiField_TC_
{
	BPA_SWI_TC_CARDKEY=0,
	BPA_SWI_TC_BUS_NAME,
	BPA_SWI_TC_BUS_KV,
	BPA_SWI_TC_GEN_ID,
	BPA_SWI_TC_TCH,
	BPA_SWI_TC_FVHP,
	BPA_SWI_TC_TRH1,
	BPA_SWI_TC_FHP,
	BPA_SWI_TC_TRH2,
	BPA_SWI_TC_FIP,
	BPA_SWI_TC_TCO,
	BPA_SWI_TC_FLP,
	BPA_SWI_TC_KEYNAME,
	BPA_SWI_TC_BUSPTR,
	BPA_SWI_TC_APPENDTAG,
};


struct	_BpaMDBSwi_TC_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	卡类型
	char		szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	发电机名称
	float		fBus_kV;								//	12	15	F4.0	发电机基准电压(kV)
	char		cGen_ID;								//	16	16	A1	BusID识别码ID
	float		fTCH;									//	17	21	F5.3	"蒸汽容积时间常数(秒)",
	float		fFVHP;									//	22	26	F5.3	"超高压缸功率比例",
	float		fTRH1;									//	32	36	F5.3	"第一再热器时间常数",
	float		fFHP;									//	37	41	F5.3	"高压缸功率比例",
	float		fTRH2;									//	47	51	F5.3	"第二再热器时间常数",
	float		fFIP;									//	52	56	F5.3	"中压缸功率比例或比例一半",
	float		fTCO;									//	62	66	F5.3	"交叉管时间常数",
	float		fFLP;									//	67	71	F5.3	"低压缸功率比例或比例一半",
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TC_	tagBpaSwi_MovTC;

enum	_BpaMDBEnum_SwiField_TD_
{
	BPA_SWI_TD_CARDKEY=0,
	BPA_SWI_TD_BUS_NAME,
	BPA_SWI_TD_BUS_KV,
	BPA_SWI_TD_GEN_ID,
	BPA_SWI_TD_TCH,
	BPA_SWI_TD_FHP,
	BPA_SWI_TD_TRH,
	BPA_SWI_TD_FIP,
	BPA_SWI_TD_TCO,
	BPA_SWI_TD_FLP_1,
	BPA_SWI_TD_FLP_2,
	BPA_SWI_TD_KEYNAME,
	BPA_SWI_TD_BUSPTR,
	BPA_SWI_TD_APPENDTAG,
};

struct	_BpaMDBSwi_TD_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	卡类型
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	发电机名称
	float			fBus_kV;								//	12	15	F4.0	发电机基准电压(kV)
	char			cGen_ID;								//	16	16	A1	BusID识别码ID
	float			fTCH;									//	17	21	F5.3	"蒸汽容积时间常数(秒)",
	float			fFHP;									//	22	26	F5.3	"高压缸功率比例",
	float			fTRH;									//	32	36	F5.3	"再热器时间常数",
	float			fFIP;									//	37	41	F5.3	"中压缸功率比例",
	float			fTCO;									//	47	51	F5.3	"交叉管时间常数",
	float			fFLP_1;									//	52	56	F5.3	"低压缸功率比例或比例的一半",
	float			fFLP_2;									//	57	61	F5.3	"低压缸功率比例或比例的一半",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TD_	tagBpaSwi_MovTD;

enum	_BpaMDBEnum_SwiField_TE_
{
	BPA_SWI_TE_CARDKEY=0,
	BPA_SWI_TE_BUS_NAME,
	BPA_SWI_TE_BUS_KV,
	BPA_SWI_TE_GEN_ID,
	BPA_SWI_TE_TCH,
	BPA_SWI_TE_FHP,
	BPA_SWI_TE_TRH,
	BPA_SWI_TE_FIP,
	BPA_SWI_TE_TCO,
	BPA_SWI_TE_FLP,
	BPA_SWI_TE_KEYNAME,
	BPA_SWI_TE_BUSPTR,
	BPA_SWI_TE_APPENDTAG,
};

struct	_BpaMDBSwi_TE_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;		//	1	2	A2	卡类型
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	发电机名称
	float			fBus_kV;								//	12	15	F4.0	发电机基准电压(kV)
	char			cGen_ID;								//	16	16	A1	BusID识别码ID
	float			fTCH;									//	17	21	F5.3	"蒸汽容积时间常数(秒)",
	float			fFHP;									//	22	26	F5.3	"高压缸功率比例",
	float			fTRH;									//	32	36	F5.3	"再热器时间常数",
	float			fFIP;									//	37	41	F5.3	"中压缸功率比例",
	float			fTCO;									//	47	51	F5.3	"交叉管时间常数",
	float			fFLP;									//	57	61	F5.3	"低压缸功率比例或比例的一半",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TE_	tagBpaSwi_MovTE;

enum	_BpaMDBEnum_SwiField_TF_
{
	BPA_SWI_TF_CARDKEY=0,
	BPA_SWI_TF_BUS_NAME,
	BPA_SWI_TF_BUS_KV,
	BPA_SWI_TF_GEN_ID,
	BPA_SWI_TF_TCH,
	BPA_SWI_TF_FVHP,
	BPA_SWI_TF_TRH1,
	BPA_SWI_TF_FHP,
	BPA_SWI_TF_TRH2,
	BPA_SWI_TF_FIP_1,
	BPA_SWI_TF_FIP_2,
	BPA_SWI_TF_TCO,
	BPA_SWI_TF_FLP_1,
	BPA_SWI_TF_FLP_2,
	BPA_SWI_TF_KEYNAME,
	BPA_SWI_TF_BUSPTR,
	BPA_SWI_TF_APPENDTAG,
};

struct	_BpaMDBSwi_TF_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	卡类型
	char		szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	发电机名称
	float		fBus_kV;								//	12	15	F4.0	发电机基准电压(kV)
	char		cGen_ID;								//	16	16	A1	BusID识别码ID
	float		fTCH;									//	17	21	F5.3	"蒸汽容积时间常数(秒)",
	float		fFVHP;									//	22	26	F5.3	"超高压缸功率比例",
	float		fTRH1;									//	32	36	F5.3	"第一再热器时间常数",
	float		fFHP;									//	37	41	F5.3	"高压缸功率比例",
	float		fTRH2;									//	47	51	F5.3	"第二再热器时间常数",
	float		fFIP_1;									//	52	56	F5.3	"中压缸功率比例或比例一半",
	float		fFIP_2;									//	57	61	F5.3	"中压缸功率比例或比例一半",
	float		fTCO;									//	62	66	F5.3	"交叉管时间常数",
	float		fFLP_1;									//	67	71	F5.3	"低压缸功率比例或比例一半",
	float		fFLP_2;									//	72	76	F5.3	"低压缸功率比例或比例一半",
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TF_	tagBpaSwi_MovTF;

enum	_BpaMDBEnum_SwiField_TW_
{
	BPA_SWI_TW_CARDKEY=0,
	BPA_SWI_TW_BUS_NAME,
	BPA_SWI_TW_BUS_KV,
	BPA_SWI_TW_GEN_ID,
	BPA_SWI_TW_K1,
	BPA_SWI_TW_HALF,
	BPA_SWI_TW_K3,
	BPA_SWI_TW_KEYNAME,
	BPA_SWI_TW_BUSPTR,
	BPA_SWI_TW_APPENDTAG,
};

struct	_BpaMDBSwi_TW_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char		szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	发电机名称
	float		fBus_kV;							//	12	15	F4.0	发电机基准电压(kV)
	char		cGen_ID;							//	16	16	A1	BusID识别码ID
	float		fK1;								//	22	26	F5.3	"汽轮机K1=1.0；水轮机K1=-2.0(必须)",
	float		fTw_Half;							//	32	36	F5.3	"水锤效应时间常数(秒)",
	float		fK3;								//	37	41	F5.3	"K3=3.0(必须)",
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TW_	tagBpaSwi_MovTW;

enum	_BpaMDBEnum_SwiField_GX_
{
	BPA_SWI_GX_CARDKEY=0,
	BPA_SWI_GX_BUS_NAME,
	BPA_SWI_GX_BUS_KV,
	BPA_SWI_GX_GEN_ID,
	BPA_SWI_GX_TSH,
	BPA_SWI_GX_TD,
	BPA_SWI_GX_TW,
	BPA_SWI_GX_K,
	BPA_SWI_GX_TDELAY,
	BPA_SWI_GX_LIMIT_MAX,
	BPA_SWI_GX_LIMIT_MIN,
	BPA_SWI_GX_KEYNAME,
	BPA_SWI_GX_BUSPTR,
};

struct	_BpaMDBSwi_GX_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];			//	1	2	A2	卡类型
	char		szBus_Name[MDB_CHARLEN_BPABUS];			//	4	11	A8	发电机名称
	float		fBus_kV;								//	12	15	F4.0	发电机基准电压（kV）
	char		cGen_ID;								//	16	16	A1	BusID识别码ID
	float		fTSH;									//	17	21	F5.3	过热器容积时间常数
	float		fTD;									//	22	26	F5.3	汽包蓄热容积时间常数
	float		fTW;									//	27	31	F5.3	锅炉燃料释放的时间常数
	float		fK;										//	32	36	F5.3	过热器及主汽管道流量系数
	float		fTdelay;								//	37	41	F5.3	延时
	float		fLimit_MAX;								//	42	46	F5.3	输出限幅环节的最大值
	float		fLimit_MIN;								//	47	51	F5.3	输出限幅环节最小值
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;		//
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GX_	tagBpaSwi_GX;

enum	_BpaMDBEnum_SwiField_IGV_
{
	BPA_SWI_IGV_CARDKEY=0,
	BPA_SWI_IGV_BUS_NAME,
	BPA_SWI_IGV_BUS_KV,
	BPA_SWI_IGV_GEN_ID,
	BPA_SWI_IGV_TSTART,
	BPA_SWI_IGV_T1,
	BPA_SWI_IGV_FREQ1,
	BPA_SWI_IGV_T2,
	BPA_SWI_IGV_FREQ2,
	BPA_SWI_IGV_T3,
	BPA_SWI_IGV_FREQ3,
	BPA_SWI_IGV_T4,
	BPA_SWI_IGV_FREQ4,
	BPA_SWI_IGV_T5,
	BPA_SWI_IGV_FREQ5,

	BPA_SWI_IGV_T6,
	BPA_SWI_IGV_FREQ6,
	BPA_SWI_IGV_T7,
	BPA_SWI_IGV_FREQ7,
	BPA_SWI_IGV_T8,
	BPA_SWI_IGV_FREQ8,
	BPA_SWI_IGV_T9,
	BPA_SWI_IGV_FREQ9,
	BPA_SWI_IGV_T10,
	BPA_SWI_IGV_FREQ10,
	BPA_SWI_IGV_T11,
	BPA_SWI_IGV_FREQ11,

	BPA_SWI_IGV_KEYNAME,
	BPA_SWI_IGV_BUSPTR,
};

struct	_BpaMDBSwi_IGV_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	3	A3	卡类型
	char		szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	发电机名称
	float		fBus_kV;							//	12	15	F4.0	发电机基准电压（kV）
	char		cGen_ID;							//	16	16	A1	BusID识别码ID
	float		fTstart;							//	19	23	F5.3	频率变化的起始时刻（周波）
	float		fT1;								//	29	33	F5.3	第1个点对应的时刻（周波）
	float		fFREQ1;								//	34	38	F5.3	第1个点对应的频率变化量（Hz）
	float		fT2;								//	39	43	F5.3	第2个点对应的时刻（周波）
	float		fFREQ2;								//	44	48	F5.3	第2个点对应的频率变化量（Hz）
	float		fT3;								//	49	53	F5.3	第3个点对应的时刻（周波）
	float		fFREQ3;								//	54	58	F5.3	第3个点对应的频率变化量（Hz）
	float		fT4;								//	59	63	F5.3	第4个点对应的时刻（周波）
	float		fFREQ4;								//	64	68	F5.3	第4个点对应的频率变化量（Hz）
	float		fT5;								//	69	73	F5.3	第5个点对应的时刻（周波）
	float		fFREQ5;								//	74	78	F5.3	第5个点对应的频率变化量（Hz）
	float		fT6;								//	19	23	F5.3	第6个点对应的时刻（周波）
	float		fFREQ6;								//	24	28	F5.3	第6个点对应的频率变化量（Hz）
	float		fT7;								//	29	33	F5.3	第7个点对应的时刻（周波）
	float		fFREQ7;								//	34	38	F5.3	第7个点对应的频率变化量（Hz）
	float		fT8;								//	39	43	F5.3	第8个点对应的时刻（周波）
	float		fFREQ8;								//	44	48	F5.3	第8个点对应的频率变化量（Hz）
	float		fT9;								//	49	53	F5.3	第9个点对应的时刻（周波）
	float		fFREQ9;								//	54	58	F5.3	第9个点对应的频率变化量（Hz）
	float		fT10;								//	59	63	F5.3	第10个点对应的时刻（周波）
	float		fFREQ10;							//	64	68	F5.3	第10个点对应的频率变化量（Hz）
	float		fT11;								//	69	73	F5.3	第11个点对应的时刻（周波）
	float		fFREQ11;							//	74	78	F5.3	第11个点对应的频率变化量（Hz）
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;							//
}	DISALIGN;
typedef	struct	_BpaMDBSwi_IGV_	tagBpaSwi_IGV;

enum	_BpaMDBEnum_SwiField_FGV_
{
	BPA_SWI_FGV_CARDKEY=0,
	BPA_SWI_FGV_BUS_NAME,
	BPA_SWI_FGV_BUS_KV,
	BPA_SWI_FGV_GEN_ID,
	BPA_SWI_FGV_AMP1,
	BPA_SWI_FGV_FREQ1,
	BPA_SWI_FGV_ANGL01,
	BPA_SWI_FGV_TBEGIN1,
	BPA_SWI_FGV_TEND1,
	BPA_SWI_FGV_AMP2,
	BPA_SWI_FGV_FREQ2,
	BPA_SWI_FGV_ANGL02,
	BPA_SWI_FGV_TBEGIN2,
	BPA_SWI_FGV_TEND2,
	BPA_SWI_FGV_CMW,
	BPA_SWI_FGV_KEYNAME,
	BPA_SWI_FGV_BUSPTR,
};

struct	_BpaMDBSwi_FGV_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	3	A3	卡类型
	char		szBus_Name[MDB_CHARLEN_BPABUS];		//	5	12	A8	发电机名称
	float		fBus_kV;							//	13	16	F4.0	发电机基准电压（kV）
	char		cGen_ID;							//	17	17	A1	发电机识别码ID
	float		fAMP1;								//	19	23	F5.0	第一个波动的幅值，百分数或有名值
	float		fFREQ1;								//	24	28	F5.2	第一个波动的频率（弧度/秒）
	float		fANGL01;							//	29	33	F5.2	第一个波动的初始相位（弧度）
	float		fTBEGIN1;							//	34	38	F5.0	第一个波动的起始时间（周波）
	float		fTEND1;								//	39	43	F5.0	第一个波动的结束时间（周波）
	float		fAMP2;								//	45	49	F5.0	第二个波动的幅值，百分数或有名值
	float		fFREQ2;								//	50	54	F5.2	第二个波动的频率（弧度/秒）
	float		fANGL02;							//	55	59	F5.2	第二个波动的初始相位（弧度）
	float		fTBEGIN2;							//	60	64	F5.0	第二个波动的起始时间（周波）
	float		fTEND2;								//	65	69	F5.0	第二个波动的结束时间（周波）
	char		cCMW;								//	80	80	A1	空格表示前两个波动的幅值都是发电机机械功率初值的百分数；W，为有名值。
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;							//
}	DISALIGN;
typedef	struct	_BpaMDBSwi_FGV_	tagBpaSwi_FGV;

enum	_BpaMDBEnum_SwiField_D_
{
	BPA_SWI_D_CARDKEY=0,
	BPA_SWI_D_BUS_NAME,
	BPA_SWI_D_BUS_KV,
	BPA_SWI_D_Tc,
	BPA_SWI_D_Tv,
	BPA_SWI_D_T1,
	BPA_SWI_D_T2,
	BPA_SWI_D_T3,
	BPA_SWI_D_Ka,
	BPA_SWI_D_MOD,
	BPA_SWI_D_IMAX,
	BPA_SWI_D_IMARGIN,
	BPA_SWI_D_ALPHASTOP,
	BPA_SWI_D_TD,
	BPA_SWI_D_VLIM,
	BPA_SWI_D_DISA,
	BPA_SWI_D_MSU,
	BPA_SWI_D_KEYNAME,
	BPA_SWI_D_BUSPTR,
};

struct	_BpaMDBSwi_D_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	float		fTc;
	float		fTv;
	float		fT1;
	float		fT2;
	float		fT3;
	float		fKa;
	char		cMOD;
	float		fIMAX;
	float		fIMARGIN;
	float		fALPHASTOP;
	float		fTD;
	float		fVLIM;
	char		cDISA;
	char		cMSU;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_D_	tagBpaSwi_D;

enum	_BpaMDBEnum_SwiField_V_
{
	BPA_SWI_V_CARDKEY=0,
	BPA_SWI_V_BUS_NAME,
	BPA_SWI_V_BUS_KV,
	BPA_SWI_V_ID,
	BPA_SWI_V_TS1,
	BPA_SWI_V_VEMAX,
	BPA_SWI_V_TS2,
	BPA_SWI_V_TS3,
	BPA_SWI_V_A,
	BPA_SWI_V_B,
	BPA_SWI_V_TS4,
	BPA_SWI_V_TS5,
	BPA_SWI_V_KSVS,
	BPA_SWI_V_KSD,
	BPA_SWI_V_BMAX,
	BPA_SWI_V_BPMAX,
	BPA_SWI_V_BPMIN,
	BPA_SWI_V_BMIN,
	BPA_SWI_V_TS6,
	BPA_SWI_V_DV,
	BPA_SWI_V_CON_NAME,
	BPA_SWI_V_CON_KV,
	BPA_SWI_V_KEYNAME,
	BPA_SWI_V_BUSPTR,
};

struct	_BpaMDBSwi_V_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST] ;
	char		szBus_Name[MDB_CHARLEN_BPABUS] ;
	float		fBus_kV;
	unsigned char	nID;
	float		fTs1;
	float		fVEmax;
	float		fTs2;
	float		fTs3;
	unsigned char	nA;
	unsigned char	nB;
	float		fTs4;
	float		fTs5;
	float		fKSvs;
	float		fKSd;
	float		fBNax;
	float		fBPMax;
	float		fBPMin;
	float		fBMin;
	float		fTs6;
	float		fDv;
	char		szConBus_Name[MDB_CHARLEN_BPABUS] ;
	float		fConBus_kV;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			iRBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_V_	tagBpaSwi_V;

enum	_BpaMDBEnum_SwiField_VG_
{
	BPA_SWI_VG_CARDKEY=0,
	BPA_SWI_VG_BUS_NAME,
	BPA_SWI_VG_BUS_KV,
	BPA_SWI_VG_MVABASE,
	BPA_SWI_VG_T1,
	BPA_SWI_VG_T2,
	BPA_SWI_VG_T3,
	BPA_SWI_VG_T4,
	BPA_SWI_VG_T5,
	BPA_SWI_VG_TP,
	BPA_SWI_VG_TS,
	BPA_SWI_VG_KP,
	BPA_SWI_VG_KI,
	BPA_SWI_VG_KD,
	BPA_SWI_VG_XT,
	BPA_SWI_VG_VMAX,
	BPA_SWI_VG_VMIN,
	BPA_SWI_VG_ICMAX,
	BPA_SWI_VG_ILMAX,
	BPA_SWI_VG_VSTANDBY,
	BPA_SWI_VG_CON_NAME,
	BPA_SWI_VG_CON_KV,
	BPA_SWI_VG_KEYNAME,
	BPA_SWI_VG_BUSPTR,
};

struct	_BpaMDBSwi_VG_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST] ;
	char		szBus_Name[MDB_CHARLEN_BPABUS] ;
	float		fBus_kV;
	float		fMvaBase;
	float		fT1;
	float		fT2;
	float		fT3;
	float		fT4;
	float		fT5;
	float		fTp;
	float		fTs;
	float		fKp;
	float		fKi;
	float		fKd;
	float		fXt;
	float		fVMax;
	float		fVMin;
	float		fICMax;
	float		fILMax;
	float		fVStandBy;
	char		szConBus_Name[MDB_CHARLEN_BPABUS] ;
	float		fConBus_kV;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			iRBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_VG_	tagBpaSwi_VG;

enum	_BpaMDBEnum_SwiField_LAB_
{
	BPA_SWI_LAB_CARDKEY=0,
	BPA_SWI_LAB_BUS_NAME,
	BPA_SWI_LAB_BUS_KV,
	BPA_SWI_LAB_ZONE,
	BPA_SWI_LAB_AREA,
	BPA_SWI_LAB_P1,
	BPA_SWI_LAB_Q1,
	BPA_SWI_LAB_P2,
	BPA_SWI_LAB_Q2,
	BPA_SWI_LAB_P3,
	BPA_SWI_LAB_Q3,
	BPA_SWI_LAB_P4,
	BPA_SWI_LAB_Q4,
	BPA_SWI_LAB_LDP,
	BPA_SWI_LAB_LDQ,
	BPA_SWI_LAB_P5,
	BPA_SWI_LAB_Q5,
	BPA_SWI_LAB_NP,
	BPA_SWI_LAB_NQ,
};

struct	_BpaMDBSwi_LAB_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char		szBus_Name[MDB_CHARLEN_BPABUS];			//	4	11	A8	母线名称
	float		fBus_kV;								//	12	15	F4.0	基准电压(kV)
	char		szZone[MDB_CHARLEN_SHORTEST/2];			//	16	17	A2	ZONE,分区名
	char		szArea[MDB_CHARLEN_SHORTER];			//	18	27	A10	区域名
	float		fP1;									//	28	32	F5.3	恒定阻抗有功负荷百分数
	float		fQ1;									//	33	37	F5.3	恒定阻抗无功负荷百分数
	float		fP2;									//	38	42	F5.3	恒定电流有功负荷百分数
	float		fQ2;									//	43	47	F5.3	恒定电流无功负荷百分数
	float		fP3;									//	48	52	F5.3	恒定功率有功负荷百分数
	float		fQ3;									//	53	57	F5.3	恒定功率无功负荷百分数
	float		fP4;									//	58	62	F5.3	与频率有关的有功负荷百分数
	float		fQ4;									//	63	67	F5.3	与频率有关的无功负荷百分数
	float		fLDP;									//	68	72	F5.3	频率变化1％引起的有功变化
	float		fLDQ;									//	73	77	F5.3	频率变化1％引起的无功变化
	float		fP5;									//	28	32	F5.3	电压指数相关的有功负荷比例
	float		fQ5;									//	33	37	F5.3	电压指数相关的无功负荷比例
	float		fNP;									//	38	42	F5.3	有功电压指数
	float		fNQ;									//	43	47	F5.3	无功电压指数
}	DISALIGN;
typedef	struct	_BpaMDBSwi_LAB_	tagBpaSwi_LAB;

enum	_BpaMDBEnum_SwiField_MI_
{
	BPA_SWI_MI_CARDKEY=0,
	BPA_SWI_MI_BUS_NAME,
	BPA_SWI_MI_BUS_KV,
	BPA_SWI_MI_BUS_ID,
	BPA_SWI_MI_EMWS,
	BPA_SWI_MI_P,
	BPA_SWI_MI_MVA,
	BPA_SWI_MI_RS,
	BPA_SWI_MI_XS,
	BPA_SWI_MI_XM,
	BPA_SWI_MI_RR,
	BPA_SWI_MI_XR,
	BPA_SWI_MI_VI,
	BPA_SWI_MI_TI,
	BPA_SWI_MI_A,
	BPA_SWI_MI_B,
	BPA_SWI_MI_IM,
	BPA_SWI_MI_BUSPTR,
};

struct	_BpaMDBSwi_MI_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST];
	char				szBus_Name[MDB_CHARLEN_BPABUS] ;
	float				fBus_kV;
	char				cID;
	float				fEmws;
	float				fP;
	float				fMVA;
	float				fRS;
	float				fXS;
	float				fXM;
	float				fRR;
	float				fXR;
	float				fVI;
	float				fTI;
	float				fA;
	float				fB;
	unsigned char		bIM;
	int					iRBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_MI_	tagBpaSwi_MI;

enum	_BpaMDBEnum_SwiField_ML_
{
	BPA_SWI_ML_CARDKEY=0,
	BPA_SWI_ML_BUS_NAME,
	BPA_SWI_ML_BUS_KV,
	BPA_SWI_ML_BUS_ID,
	BPA_SWI_ML_TJ,
	BPA_SWI_ML_PPER,
	BPA_SWI_ML_KL,
	BPA_SWI_ML_PMIN,
	BPA_SWI_ML_RS,
	BPA_SWI_ML_XS,
	BPA_SWI_ML_XM,
	BPA_SWI_ML_RR,
	BPA_SWI_ML_XR,
	BPA_SWI_ML_VI,
	BPA_SWI_ML_TI,
	BPA_SWI_ML_A,
	BPA_SWI_ML_B,
	BPA_SWI_ML_S0,
	BPA_SWI_ML_IM,
	BPA_SWI_ML_BUSPTR,
};

struct	_BpaMDBSwi_ML_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST] ;
	char				szBus_Name[MDB_CHARLEN_BPABUS] ;
	float				fBus_kV;
	char				cID;
	float				fTJ;
	float				fPper;
	float				fKL;
	float				fPmin;
	float				fRS;
	float				fXS;
	float				fXM;
	float				fRR;
	float				fXR;
	float				fVI;
	float				fTI;
	float				fA;
	float				fB;
	char				cUseS0;
	unsigned char		bIM;
	int					iRBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_ML_	tagBpaSwi_ML;

enum	_BpaMDBEnum_SwiField_MJ_
{
	BPA_SWI_MJ_CARDKEY=0,
	BPA_SWI_MJ_ZONE_NAME,
	BPA_SWI_MJ_TJ,
	BPA_SWI_MJ_PPER,
	BPA_SWI_MJ_KL,
	BPA_SWI_MJ_PMIN,
	BPA_SWI_MJ_RS,
	BPA_SWI_MJ_XS,
	BPA_SWI_MJ_XM,
	BPA_SWI_MJ_RR,
	BPA_SWI_MJ_XR,
	BPA_SWI_MJ_VI,
	BPA_SWI_MJ_TI,
	BPA_SWI_MJ_A,
	BPA_SWI_MJ_B,
	BPA_SWI_MJ_S0,
	BPA_SWI_MJ_IM,
};

struct	_BpaMDBSwi_MJ_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST] ;
	char				szZone_Name[MDB_CHARLEN_BPABUS] ;
	float				fTJ;
	float				fPper;
	float				fKL;
	float				fPmin;
	float				fRS;
	float				fXS;
	float				fXM;
	float				fRR;
	float				fXR;
	float				fVI;
	float				fTI;
	float				fA;
	float				fB;
	char				cUseS0;
	unsigned char		bIM;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_MJ_	tagBpaSwi_MJ;

enum	_BpaMDBEnum_SwiField_MK_
{
	BPA_SWI_MK_CARDKEY=0,
	BPA_SWI_MK_AREA_NAME,
	BPA_SWI_MK_TJ,
	BPA_SWI_MK_PPER,
	BPA_SWI_MK_KL,
	BPA_SWI_MK_PMIN,
	BPA_SWI_MK_RS,
	BPA_SWI_MK_XS,
	BPA_SWI_MK_XM,
	BPA_SWI_MK_RR,
	BPA_SWI_MK_XR,
	BPA_SWI_MK_VI,
	BPA_SWI_MK_TI,
	BPA_SWI_MK_A,
	BPA_SWI_MK_B,
	BPA_SWI_MK_S0,
	BPA_SWI_MK_IM,
};

struct	_BpaMDBSwi_MK_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST] ;
	char				szArea_Name[MDB_CHARLEN_BPABUS] ;
	float				fTJ;
	float				fPper;
	float				fKL;
	float				fPmin;
	float				fRS;
	float				fXS;
	float				fXM;
	float				fRR;
	float				fXR;
	float				fVI;
	float				fTI;
	float				fA;
	float				fB;
	char				cUseS0;
	unsigned char		bIM;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_MK_	tagBpaSwi_MK;

enum _BpaMDBEnum_SwiField_LO_
{
	BPA_SWI_LO_CARDKEY=0,
	BPA_SWI_LO_BUSI,
	BPA_SWI_LO_KVI,
	BPA_SWI_LO_BUSJ,
	BPA_SWI_LO_KVJ,
	BPA_SWI_LO_LOOP,
	BPA_SWI_LO_R0,
	BPA_SWI_LO_X0,
	BPA_SWI_LO_GA0,
	BPA_SWI_LO_BA0,
	BPA_SWI_LO_GB0,
	BPA_SWI_LO_BB0,
	BPA_SWI_LO_KEYNAME,
};
struct	_BpaMDBSwi_LO_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2		CARD TYPE
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float			fkVI;							//	15	18	F4.0	基准电压1(kV)
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float			fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char			cLoop;							//	32	32	A1		并联线路的回路标志
	float			fR0;							//	36	42	F7.4	线路零序电阻(标么值)
	float			fX0;							//	43	49	F7.4	线路零序电抗(标么值)
	float			fGa0;							//	50	56	F7.4	线路BUS A 侧零序对地电导
	float			fBa0;							//	57	63	F7.4	线路BUS A 侧零序对地电纳
	float			fGb0;							//	64	70	F7.4	线路BUS B 侧零序对地电导
	float			fBb0;							//	71	77	F7.4	线路BUS B 侧零序对地电纳
	char			szKeyName[MDB_CHARLEN_SHORT];
}	DISALIGN;
typedef	struct	_BpaMDBSwi_LO_	tagBpaSwi_LO;

enum _BpaMDBEnum_SwiField_XO_
{
	BPA_SWI_XO_CARDKEY=0,
	BPA_SWI_XO_BUSI,
	BPA_SWI_XO_KVI,
	BPA_SWI_XO_BUSJ,
	BPA_SWI_XO_KVJ,
	BPA_SWI_XO_LOOP,
	BPA_SWI_XO_SID,
	BPA_SWI_XO_R0,
	BPA_SWI_XO_X0,
	BPA_SWI_XO_KEYNAME,
};
struct	_BpaMDBSwi_XO_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2		CARD TYPE
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float			fkVI;							//	15	18	F4.0	基准电压1(kV)
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float			fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char			cLoop;							//	32	32	A1		并联线路的回路标志
	unsigned char	bSID;							//	32	32	I1	变压器零序电抗的接入方式
	float			fR0;							//	45	51	F7.4	变压器零序电阻标么值
	float			fX0;							//	38	44	F7.4	变压器零序电抗标么值
	char			szKeyName[MDB_CHARLEN_SHORT];
}	DISALIGN;
typedef	struct	_BpaMDBSwi_XO_	tagBpaSwi_XO;

enum _BpaMDBEnum_SwiField_LOHG_
{
	BPA_SWI_LOHG_CARDKEY=0,
	BPA_SWI_LOHG_BUSI,
	BPA_SWI_LOHG_KVI,
	BPA_SWI_LOHG_BUSJ,
	BPA_SWI_LOHG_KVJ,
	BPA_SWI_LOHG_LOOP,
	BPA_SWI_LOHG_X0I,
	BPA_SWI_LOHG_X0J,
	BPA_SWI_LOHG_KEYNAME,
};
struct	_BpaMDBSwi_LOHG_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	CARD TYPE
	char	szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float	fkVI;							//	15	18	F4.0	基准电压1(kV)
	char	szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float	fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char	cLoop;							//	32	32	A1		并联线路的回路标志
	float	fX0I;							//	36	42	F7.0	线路前侧高抗对应的等值零序电抗(pu)
	float	fX0J;							//	43	49	F7.0	线路后侧高抗对应的等值零序电抗(pu)
	char	szKeyName[MDB_CHARLEN_SHORT];
}	DISALIGN;
typedef	struct	_BpaMDBSwi_LOHG_	tagBpaSwi_LOHG;

enum	_BpaMDBEnum_SwiField_XR_
{
	BPA_SWI_XR_CARDKEY=0,
	BPA_SWI_XR_NAME,
	BPA_SWI_XR_KV,
	BPA_SWI_XR_R0,
	BPA_SWI_XR_X0,
};
struct	_BpaMDBSwi_XR_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];	//1		2	A1	子类型
	char	szName[MDB_CHARLEN_BPABUS];			//7		14	A8	母线名称
	float	fkV;								//15	18	F4.0基准电压(kV)
	float	fR0;								//	22	28	F7.4	对地支路零序电阻(PU)
	float	fX0;								//	29	35	F7.4	对地支路零序电抗(PU)
}	DISALIGN;
typedef	struct	_BpaMDBSwi_XR_	tagBpaSwi_XR;

enum	_BpaMDBEnum_SwiField_LE_
{
	BPA_SWI_LE_CARDKEY=0,
	BPA_SWI_LE_NAME,
	BPA_SWI_LE_LINE_ID,
	BPA_SWI_LE_RD,
	BPA_SWI_LE_XD,
	BPA_SWI_LE_PPER,
	BPA_SWI_LE_QPER,
	BPA_SWI_LE_PG,
	BPA_SWI_LE_QG,
	BPA_SWI_LE_PFAC,
};

enum	_BpaMDBEnum_SwiField_LM_
{
	BPA_SWI_LM_CARDKEY=0,
	BPA_SWI_LM_BUS1_I,
	BPA_SWI_LM_KV1_I,
	BPA_SWI_LM_BUS1_J,
	BPA_SWI_LM_KV1_J,
	BPA_SWI_LM_PAR_1,
	BPA_SWI_LM_BUS2_I,
	BPA_SWI_LM_KV2_I,
	BPA_SWI_LM_BUS2_J,
	BPA_SWI_LM_KV2_J,
	BPA_SWI_LM_PAR_2,
	BPA_SWI_LM_RM,
	BPA_SWI_LM_XM,
	BPA_SWI_LM_KEYNAME,
	BPA_SWI_LM_BUSPTR,
	BPA_SWI_LM_ZRBUS,
};

struct	_BpaMDBSwi_LM_
{
	char				szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char				szBus1_I[MDB_CHARLEN_BPABUS];			//	5	12	A8	Bus Name1_A
	float				fKV1_I;								//	13	16	F4.0	Bus Base1_A(kV)
	char				szBus1_J[MDB_CHARLEN_BPABUS];			//	19	26	A8	Bus Name1_B
	float				fKV1_J;								//	27	30	F4.0	Bus Base1_B(kV)
	char				cPAR_1;								//	33	33	A1	平行码
	char				szBus2_I[MDB_CHARLEN_BPABUS];			//	36	43	A8	Bus Name2_I
	float				fKV2_I;								//	44	47	F4.0	Bus Base2_I(kV)
	char				szBus2_J[MDB_CHARLEN_BPABUS];			//	50	57	A8	Bus Name2_J
	float				fKV2_J;								//	58	61	F4.0	Bus Base2_J(kV)
	char				cPAR_2;								//	64	64	A1	平行码
	float				fRm;								//	67	73	F7.4	互感电阻
	float				fXm;								//	74	80	F7.4	互感电抗
	char				szKeyName[MDB_CHARLEN];
	int					nIBus;
	int					nZBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_LM_	tagBpaSwi_LM;

enum	_BpaMDBEnum_SwiField_UF_
{
	BPA_SWI_UF_CARDKEY=0,
	BPA_SWI_UF_BUS_NAME,
	BPA_SWI_UF_BUS_KV,
	BPA_SWI_UF_FREQ01,
	BPA_SWI_UF_FREQ02,
	BPA_SWI_UF_FREQ03,
	BPA_SWI_UF_FREQ04,
	BPA_SWI_UF_FREQ05,
	BPA_SWI_UF_FREQ06,
	BPA_SWI_UF_FREQ07,
	BPA_SWI_UF_FREQ08,
	BPA_SWI_UF_FREQ09,
	BPA_SWI_UF_FREQ10,
	BPA_SWI_UF_DELAY01,
	BPA_SWI_UF_DELAY02,
	BPA_SWI_UF_DELAY03,
	BPA_SWI_UF_DELAY04,
	BPA_SWI_UF_DELAY05,
	BPA_SWI_UF_DELAY06,
	BPA_SWI_UF_DELAY07,
	BPA_SWI_UF_DELAY08,
	BPA_SWI_UF_DELAY09,
	BPA_SWI_UF_DELAY10,
	BPA_SWI_UF_SHED01,
	BPA_SWI_UF_SHED02,
	BPA_SWI_UF_SHED03,
	BPA_SWI_UF_SHED04,
	BPA_SWI_UF_SHED05,
	BPA_SWI_UF_SHED06,
	BPA_SWI_UF_SHED07,
	BPA_SWI_UF_SHED08,
	BPA_SWI_UF_SHED09,
	BPA_SWI_UF_SHED10,
	BPA_SWI_UF_W,
};

struct	_BpaMDBSwi_UF_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char		szBus[MDB_CHARLEN_BPABUS];				//	4	11	A8	母线名称
	float		fKV;									//	12	15	F4.0	基准电压(kV)
	float		fFreq01;								//	16	20	F5.3	第1级减负荷时的电压(PU)或频率(Hz)
	float		fFreq02;								//	27	31	F5.3	第2级减负荷时的电压(PU)或频率(Hz)
	float		fFreq03;								//	38	42	F5.3	第3级减负荷时的电压(PU)或频率(Hz)
	float		fFreq04;								//	49	53	F5.3	第4级减负荷时的电压(PU)或频率(Hz)
	float		fFreq05;								//	60	64	F5.3	第5级减负荷时的电压(PU)或频率(Hz)
	float		fFreq06;								//	16	20	F5.3	第6级减负荷时的电压(pu)或频率(Hz)
	float		fFreq07;								//	27	31	F5.3	第7级减负荷时的电压(pu)或频率(Hz)
	float		fFreq08;								//	38	42	F5.3	第8级减负荷时的电压(pu)或频率(Hz)
	float		fFreq09;								//	49	53	F5.3	第9级减负荷时的电压(pu)或频率(Hz)
	float		fFreq10;								//	60	64	F5.3	第10级减负荷时的电压(pu)或频率(Hz)
	float		fDelay01;								//	21	23	F3.2	第1级减负荷前的时延(周)
	float		fDelay02;								//	32	34	F3.2	第2级减负荷前的时延(周)
	float		fDelay03;								//	43	45	F3.2	第3级减负荷前的时延(周)
	float		fDelay04;								//	54	56	F3.2	第4级减负荷前的时延(周)
	float		fDelay05;								//	65	67	F3.2	第5级减负荷前的时延(周)
	float		fDelay06;								//	21	23	F3.0	第6级减负荷前的时延(周)
	float		fDelay07;								//	32	34	F3.0	第7级减负荷前的时延(周)
	float		fDelay08;								//	43	45	F3.0	第8级减负荷前的时延(周)
	float		fDelay09;								//	54	56	F3.0	第9级减负荷前的时延(周)
	float		fDelay10;								//	65	67	F3.0	第10级减负荷前的时延(周)
	float		fShed01;								//	24	26	F3.2	第1级初始负荷被减去的值
	float		fShed02;								//	35	37	F3.2	第2级初始负荷被减去的值
	float		fShed03;								//	46	48	F3.2	第3级初始负荷被减去的值
	float		fShed04;								//	57	59	F3.2	第4级初始负荷被减去的值
	float		fShed05;								//	68	70	F3.2	第5级初始负荷被减去的值
	float		fShed06;								//	24	26	F3.3	第6级被减去的负荷值（MW）
	float		fShed07;								//	35	37	F3.3	第7级被减去的负荷值（MW）
	float		fShed08;								//	46	48	F3.3	第8级被减去的负荷值（MW）
	float		fShed09;								//	57	59	F3.3	第9级被减去的负荷值（MW）
	float		fShed10;								//	68	70	F3.3	第10级被减去的负荷值（MW）
	char		cW;										//	80	80	A1	特别码W，表示以MW为单位减去负荷
}	DISALIGN;
typedef	struct	_BpaMDBSwi_UF_	tagBpaSwi_UF;

enum	_BpaMDBEnum_SwiField_UV_
{
	BPA_SWI_UV_CARDKEY=0,
	BPA_SWI_UV_BUS_NAME,
	BPA_SWI_UV_BUS_KV,
	BPA_SWI_UV_VOLT01,
	BPA_SWI_UV_VOLT02,
	BPA_SWI_UV_VOLT03,
	BPA_SWI_UV_VOLT04,
	BPA_SWI_UV_VOLT05,
	BPA_SWI_UV_VOLT06,
	BPA_SWI_UV_VOLT07,
	BPA_SWI_UV_VOLT08,
	BPA_SWI_UV_VOLT09,
	BPA_SWI_UV_VOLT10,
	BPA_SWI_UV_DELAY01,
	BPA_SWI_UV_DELAY02,
	BPA_SWI_UV_DELAY03,
	BPA_SWI_UV_DELAY04,
	BPA_SWI_UV_DELAY05,
	BPA_SWI_UV_DELAY06,
	BPA_SWI_UV_DELAY07,
	BPA_SWI_UV_DELAY08,
	BPA_SWI_UV_DELAY09,
	BPA_SWI_UV_DELAY10,
	BPA_SWI_UV_SHED01,
	BPA_SWI_UV_SHED02,
	BPA_SWI_UV_SHED03,
	BPA_SWI_UV_SHED04,
	BPA_SWI_UV_SHED05,
	BPA_SWI_UV_SHED06,
	BPA_SWI_UV_SHED07,
	BPA_SWI_UV_SHED08,
	BPA_SWI_UV_SHED09,
	BPA_SWI_UV_SHED10,
	BPA_SWI_UV_W,
};

struct	_BpaMDBSwi_UV_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	卡类型
	char		szBus[MDB_CHARLEN_BPABUS];				//	4	11	A8	母线名称
	float		fKV;									//	12	15	F4.0	基准电压(kV)
	float		fVolt01;								//	16	20	F5.3	第1级减负荷时的电压(PU)或频率(Hz)
	float		fVolt02;								//	27	31	F5.3	第2级减负荷时的电压(PU)或频率(Hz)
	float		fVolt03;								//	38	42	F5.3	第3级减负荷时的电压(PU)或频率(Hz)
	float		fVolt04;								//	49	53	F5.3	第4级减负荷时的电压(PU)或频率(Hz)
	float		fVolt05;								//	60	64	F5.3	第5级减负荷时的电压(PU)或频率(Hz)
	float		fVolt06;								//	16	20	F5.3	第6级减负荷时的电压(pu)或频率(Hz)
	float		fVolt07;								//	27	31	F5.3	第7级减负荷时的电压(pu)或频率(Hz)
	float		fVolt08;								//	38	42	F5.3	第8级减负荷时的电压(pu)或频率(Hz)
	float		fVolt09;								//	49	53	F5.3	第9级减负荷时的电压(pu)或频率(Hz)
	float		fVolt10;								//	60	64	F5.3	第10级减负荷时的电压(pu)或频率(Hz)
	float		fDelay01;								//	21	23	F3.2	第1级减负荷前的时延(周)
	float		fDelay02;								//	32	34	F3.2	第2级减负荷前的时延(周)
	float		fDelay03;								//	43	45	F3.2	第3级减负荷前的时延(周)
	float		fDelay04;								//	54	56	F3.2	第4级减负荷前的时延(周)
	float		fDelay05;								//	65	67	F3.2	第5级减负荷前的时延(周)
	float		fDelay06;								//	21	23	F3.0	第6级减负荷前的时延(周)
	float		fDelay07;								//	32	34	F3.0	第7级减负荷前的时延(周)
	float		fDelay08;								//	43	45	F3.0	第8级减负荷前的时延(周)
	float		fDelay09;								//	54	56	F3.0	第9级减负荷前的时延(周)
	float		fDelay10;								//	65	67	F3.0	第10级减负荷前的时延(周)
	float		fShed01;								//	24	26	F3.2	第1级初始负荷被减去的值
	float		fShed02;								//	35	37	F3.2	第2级初始负荷被减去的值
	float		fShed03;								//	46	48	F3.2	第3级初始负荷被减去的值
	float		fShed04;								//	57	59	F3.2	第4级初始负荷被减去的值
	float		fShed05;								//	68	70	F3.2	第5级初始负荷被减去的值
	float		fShed06;								//	24	26	F3.3	第6级被减去的负荷值（MW）
	float		fShed07;								//	35	37	F3.3	第7级被减去的负荷值（MW）
	float		fShed08;								//	46	48	F3.3	第8级被减去的负荷值（MW）
	float		fShed09;								//	57	59	F3.3	第9级被减去的负荷值（MW）
	float		fShed10;								//	68	70	F3.3	第10级被减去的负荷值（MW）
	char		cW;										//	80	80	A1	特别码W，表示以MW为单位减去负荷
}	DISALIGN;
typedef	struct	_BpaMDBSwi_UV_	tagBpaSwi_UV;

enum	_BpaMDBEnum_SwiField_RE_
{
	BPA_SWI_RE_CARDKEY=0,
	BPA_SWI_RE_BUS_NAME,
	BPA_SWI_RE_BUS_KV,
	BPA_SWI_RE_GEN_ID,
	BPA_SWI_RE_VOL1,
	BPA_SWI_RE_VOL2,
	BPA_SWI_RE_VOL3,
	BPA_SWI_RE_VOL4,
	BPA_SWI_RE_VOL5,
	BPA_SWI_RE_VOL6,
	BPA_SWI_RE_VOL7,
	BPA_SWI_RE_VOL8,
	BPA_SWI_RE_VOL9,
	BPA_SWI_RE_VOL10,
	BPA_SWI_RE_TIME1,
	BPA_SWI_RE_TIME2,
	BPA_SWI_RE_TIME3,
	BPA_SWI_RE_TIME4,
	BPA_SWI_RE_TIME5,
	BPA_SWI_RE_TIME6,
	BPA_SWI_RE_TIME7,
	BPA_SWI_RE_TIME8,
	BPA_SWI_RE_TIME9,
	BPA_SWI_RE_TIME10,
	BPA_SWI_RE_TBRK,
	BPA_SWI_RE_NAME_CON,
	BPA_SWI_RE_KV_CON,
	BPA_SWI_RE_BUSPTR,
};

struct	_BpaMDBSwi_RE_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fVOL1;
	float		fVOL2;
	float		fVOL3;
	float		fVOL4;
	float		fVOL5;
	float		fVOL6;
	float		fVOL7;
	float		fVOL8;
	float		fVOL9;
	float		fVOL10;
	float		fTIME1;
	float		fTIME2;
	float		fTIME3;
	float		fTIME4;
	float		fTIME5;
	float		fTIME6;
	float		fTIME7;
	float		fTIME8;
	float		fTIME9;
	float		fTIME10;
	float		fTBRK;
	char		szNAME_CON[MDB_CHARLEN_BPABUS];
	float		fKV_CON;
	int			iRBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_RE_	tagBpaSwi_RE;

enum	_BpaMDBEnum_SwiField_RW_
{
	BPA_SWI_RW_CARDKEY=0,
	BPA_SWI_RW_BUS_NAME,
	BPA_SWI_RW_BUS_KV,
	BPA_SWI_RW_GEN_ID,
	BPA_SWI_RW_WMAX,
	BPA_SWI_RW_WMIN,
	BPA_SWI_RW_WSET1,
	BPA_SWI_RW_WSET2,
	BPA_SWI_RW_WSET3,
	BPA_SWI_RW_WSET4,
	BPA_SWI_RW_WSET5,
	BPA_SWI_RW_WSET6,
	BPA_SWI_RW_WSET7,
	BPA_SWI_RW_WSET8,
	BPA_SWI_RW_WSET9,
	BPA_SWI_RW_WSET10,
	BPA_SWI_RW_DELAY1,
	BPA_SWI_RW_DELAY2,
	BPA_SWI_RW_DELAY3,
	BPA_SWI_RW_DELAY4,
	BPA_SWI_RW_DELAY5,
	BPA_SWI_RW_DELAY6,
	BPA_SWI_RW_DELAY7,
	BPA_SWI_RW_DELAY8,
	BPA_SWI_RW_DELAY9,
	BPA_SWI_RW_DELAY10,
	BPA_SWI_RW_TBRK,
	BPA_SWI_RW_BUSPTR,
};

struct	_BpaMDBSwi_RW_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cGen_ID;
	float		fWmax;
	float		fWmin;
	float		fWset1;
	float		fWset2;
	float		fWset3;
	float		fWset4;
	float		fWset5;
	float		fWset6;
	float		fWset7;
	float		fWset8;
	float		fWset9;
	float		fWset10;
	float		fDelay1;
	float		fDelay2;
	float		fDelay3;
	float		fDelay4;
	float		fDelay5;
	float		fDelay6;
	float		fDelay7;
	float		fDelay8;
	float		fDelay9;
	float		fDelay10;
	float		fTbrk;
	int			iRBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_RW_	tagBpaSwi_RW;

enum	_BpaMDBEnum_SwiField_RA_
{
	BPA_SWI_RA_CARDKEY=0,
	BPA_SWI_RA_BUSI,
	BPA_SWI_RA_KVI,
	BPA_SWI_RA_BUSJ,
	BPA_SWI_RA_KVJ,
	BPA_SWI_RA_LOOP,
	BPA_SWI_RA_CBUS1,
	BPA_SWI_RA_CKV1,
	BPA_SWI_RA_CV1,
	BPA_SWI_RA_CT1,
	BPA_SWI_RA_CBUS2,
	BPA_SWI_RA_CKV2,
	BPA_SWI_RA_CV2,
	BPA_SWI_RA_CT2,
};

struct	_BpaMDBSwi_RA_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBusI[MDB_CHARLEN_BPABUS];
	float		fkVI;
	char		szBusJ[MDB_CHARLEN_BPABUS];
	float		fkVJ;
	char		cLoop;
	char		szCBus1[MDB_CHARLEN_BPABUS];
	float		fCkV1;
	float		fCV1;
	float		fCT1;
	char		szCBus2[MDB_CHARLEN_BPABUS];
	float		fCkV2;
	float		fCV2;
	float		fCT2;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_RA_	tagBpaSwi_RA;

enum	_BpaMDBEnum_SwiField_RU_
{
	BPA_SWI_RU_CARDKEY=0,
	BPA_SWI_RU_BUSI,
	BPA_SWI_RU_KVI,
	BPA_SWI_RU_BUSJ,
	BPA_SWI_RU_KVJ,
	BPA_SWI_RU_LOOP,
	BPA_SWI_RU_FTRIP,
	BPA_SWI_RU_TRELAY,
	BPA_SWI_RU_TTRIP,
	BPA_SWI_RU_TDELAY,
};

struct	_BpaMDBSwi_RU_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		母线名称1
	float		fkVI;							//	15	18	F4.0	基准电压1(kV)
	char		szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		母线名称2
	float		fkVJ;							//	28	31	F4.0	基准电压2(kV)
	char		cLoop;							//	32	32	A1		并联线路的回路标志
	float		fFTrip;
	float		fTRelay;
	float		fTTrip;
	float		fTDelay;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_RU_	tagBpaSwi_RU;


//	数据库表相关定义
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

enum	_BPATableEnum_TableCategory_	{
	BPATableEnum_Unknow=0,
	BPATableEnum_Dict,
	BPATableEnum_Dat,
	BPATableEnum_Swi,
};

enum	_SWIEnum_Table_	{
	BPA_DAT_CASE=0,
	BPA_DAT_AREA,
	BPA_DAT_I,
	BPA_DAT_ZONE,
	BPA_DAT_SUB,
	BPA_DAT_ACBUS,
	BPA_DAT_ACLINE,
	BPA_DAT_LINEHG,
	BPA_DAT_WIND,
	BPA_DAT_DCBUS,
	BPA_DAT_DCLINE,
	BPA_DAT_R,
	BPA_DAT_RZ,
	BPA_DAT_P,
	BPA_DAT_ZIL,
	BPA_DAT_GEN,
	BPA_DAT_LOAD,
	BPA_DAT_TRAN,
	BPA_DAT_EDGELINE,
	BPA_DAT_EDGEWIND,
	BPA_DAT_EDGELINEHG,
	BPA_DAT_RADIATE,
	BPA_SCC_FMOVE,
	BPA_SWI_CASE,
	BPA_SWI_F1,
	BPA_SWI_F0,
	BPA_SWI_FF,
	BPA_SWI_GEN,
	BPA_SWI_DAMP,
	BPA_SWI_WGEGEN,
	BPA_SWI_GENLN,
	BPA_SWI_EXCIT68,
	BPA_SWI_EXCIT81,
	BPA_SWI_EXCITMV,
	BPA_SWI_FZ,
	BPA_SWI_FCA,
	BPA_SWI_FCB,
	BPA_SWI_EXCITX,
	BPA_SWI_PSSS,
	BPA_SWI_PSSSH,
	BPA_SWI_PSSSI,
	BPA_SWI_PSSSA,
	BPA_SWI_PSSSB,
	BPA_SWI_PSSST,
	BPA_SWI_GG,
	BPA_SWI_GH,
	BPA_SWI_GC,
	BPA_SWI_GS,
	BPA_SWI_GL,
	BPA_SWI_GW,
	BPA_SWI_GA,
	BPA_SWI_GI,
	BPA_SWI_GJ,
	BPA_SWI_GK,
	BPA_SWI_GM,
	BPA_SWI_GD,
	BPA_SWI_GZ,
	BPA_SWI_TA,
	BPA_SWI_TB,
	BPA_SWI_TC,
	BPA_SWI_TD,
	BPA_SWI_TE,
	BPA_SWI_TF,
	BPA_SWI_TW,
	BPA_SWI_GX,
	BPA_SWI_IGV,
	BPA_SWI_FGV,
	BPA_SWI_LO,
	BPA_SWI_XO,
	BPA_SWI_LOHG,
	BPA_SWI_XR,
	BPA_SWI_D,
	BPA_SWI_V,
	BPA_SWI_VG,
	BPA_SWI_LAB,
	BPA_SWI_MI,
	BPA_SWI_ML,
	BPA_SWI_MJ,
	BPA_SWI_MK,
//	BPA_SWI_LM,
	BPA_SWI_UF,
	BPA_SWI_UV,
	BPA_SWI_RE,
	BPA_SWI_RW,
	BPA_SWI_RA,
	BPA_SWI_RU,
};

static	int		g_nBpaExcTables[]=
{
	BPA_SWI_EXCIT68,
	BPA_SWI_EXCIT81,
	BPA_SWI_EXCITMV,
	BPA_SWI_FZ,
	BPA_SWI_FCA,
	BPA_SWI_FCB,
	BPA_SWI_EXCITX,
};

static	int		g_nBpaPssTables[]=
{
	BPA_SWI_PSSS,
	BPA_SWI_PSSSH,
	BPA_SWI_PSSSI,
	BPA_SWI_PSSSA,
	BPA_SWI_PSSSB,
	BPA_SWI_PSSST,
};

static	int		g_nBpaGovTables[]=
{
	BPA_SWI_GG,
	BPA_SWI_GH,
	BPA_SWI_GC,
	BPA_SWI_GS,
	BPA_SWI_GL,
	BPA_SWI_GW,
	BPA_SWI_GI,
	BPA_SWI_GJ,
	BPA_SWI_GK,
	BPA_SWI_GM,
	BPA_SWI_GD,
	BPA_SWI_GZ,
};

static	int		g_nBpaMovTables[]=
{
	BPA_SWI_TA,
	BPA_SWI_TB,
	BPA_SWI_TC,
	BPA_SWI_TD,
	BPA_SWI_TE,
	BPA_SWI_TF,
	BPA_SWI_TW,
};

const	int	MAXBPADICT					=3200;
const	int	MaxBpaDatArea				=200;
const	int	MaxBpaDatI					=MaxBpaDatArea/2;
const	int	MaxBpaDatZone				=1000;
const	int	MaxBpaDatSub				=50000;
const	int	MaxBpaDatACBus				=64000;
const	int	MaxBpaDatACLine				=28000;
const	int	MaxBpaDatWind				=42000;
const	int	MaxBpaDatLineHG				=MaxBpaDatACLine/20;
const	int	MaxBpaDatDCBus				=240;
const	int	MaxBpaDatDCLine				=MaxBpaDatDCBus/2;
const	int	MaxBpaDatR					=MaxBpaDatDCBus;
const	int	MaxBpaDatRZ					=100;
const	int	MaxBpaDatP					=MaxBpaDatZone/2;
const	int	MaxBpaDatZIL				=1000;
const	int	MaxBpaDatVDip				=100*MaxBpaDatACBus;
const	int	MaxBpaDatGen				=MaxBpaDatACBus/10;
const	int	MaxBpaDatLoad				=MaxBpaDatACBus/4;
const	int	MaxBpaDatTran				=3*MaxBpaDatWind/2;
const	int	MaxBpaDatEdgeLine			=MaxBpaDatACLine*2;
const	int	MaxBpaDatEdgeWind			=MaxBpaDatWind*2;
const	int	MaxBpaDatEdgeLineHG			=MaxBpaDatLineHG*2;
const	int	MaxBpaDatRadiate			=8000;
const	int	MaxBpaSccFMove				=100;

const	int	MaxBpaSwiGen				=6400;
const	int	MaxBpaSwiDamp				=MaxBpaSwiGen;
const	int	MaxBpaSwiWGEGen				=2000;
const	int	MaxBpaSwiGENLN				=1000;
const	int	MaxBpaSwiEXC68				=MaxBpaSwiGen;
const	int	MaxBpaSwiEXC81				=MaxBpaSwiGen;
const	int	MaxBpaSwiEXCMV				=MaxBpaSwiGen;
const	int	MaxBpaSwiFZ					=MaxBpaSwiGen;
const	int	MaxBpaSwiFCA				=MaxBpaSwiGen;
const	int	MaxBpaSwiFCB				=MaxBpaSwiGen;
const	int	MaxBpaSwiFCC				=MaxBpaSwiGen;
const	int	MaxBpaSwiEXCX				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssS				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssSH				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssSH1				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssSH2				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssSI				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssSA				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssSB				=MaxBpaSwiGen;
const	int	MaxBpaSwiPssST				=MaxBpaSwiGen;

const   int MaxBpaSwiGG					=MaxBpaSwiGen;
const	int MaxBpaSwiGH					=MaxBpaSwiGen;
const   int MaxBpaSwiGC					=MaxBpaSwiGen;
const	int	MaxBpaSwiGS					=MaxBpaSwiGen;
const	int	MaxBpaSwiGL					=MaxBpaSwiGen;
const	int	MaxBpaSwiGW					=MaxBpaSwiGen;
const	int MaxBpaSwiGA					=MaxBpaSwiGen;
const	int	MaxBpaSwiGI					=MaxBpaSwiGen;
const	int MaxBpaSwiGJ					=MaxBpaSwiGen;
const	int MaxBpaSwiGK					=MaxBpaSwiGen;
const	int MaxBpaSwiGM					=MaxBpaSwiGen;
const	int MaxBpaSwiGD					=MaxBpaSwiGen;
const	int MaxBpaSwiGZ					=MaxBpaSwiGen;

const	int MaxBpaSwiTA					=MaxBpaSwiGen;
const	int MaxBpaSwiTB					=MaxBpaSwiGen;
const	int MaxBpaSwiTC					=MaxBpaSwiGen;
const	int MaxBpaSwiTD					=MaxBpaSwiGen;
const	int MaxBpaSwiTE					=MaxBpaSwiGen;
const	int MaxBpaSwiTF					=MaxBpaSwiGen;
const	int MaxBpaSwiTW					=MaxBpaSwiGen;

const	int MaxBpaSwiGX					=MaxBpaSwiGen;
const	int MaxBpaSwiIGV				=MaxBpaSwiGen;
const	int MaxBpaSwiFGV				=MaxBpaSwiGen;

const	int MaxBpaSwiLO					=MaxBpaDatACLine;
const	int MaxBpaSwiXO					=MaxBpaDatWind;
const	int MaxBpaSwiLOHG				=MaxBpaDatLineHG;
const	int MaxBpaSwiXR					=MaxBpaDatACBus;

const	int MaxBpaSwiD					=MaxBpaDatDCBus;

const	int MaxBpaSwiV					=1000;
const	int MaxBpaSwiVG					=500;

const	int	MaxBpaSwiLAB				=MaxBpaDatZone;
const	int	MaxBpaSwiMI					=MaxBpaDatZone;
const	int	MaxBpaSwiML					=MaxBpaDatACBus;
const	int	MaxBpaSwiMJ					=MaxBpaDatZone;
const	int	MaxBpaSwiMK					=MaxBpaDatArea;

const	int	MaxBpaSwiLM					=2;

const	int MaxBpaSwiUF					=MaxBpaDatACBus;
const	int MaxBpaSwiUV					=MaxBpaDatACBus;
const	int MaxBpaSwiRE					=MaxBpaSwiGen;
const	int MaxBpaSwiRW					=MaxBpaSwiGen;
const	int MaxBpaSwiRA					=200;
const	int MaxBpaSwiRU					=200;

const	int	MaxBpaSwiCase				=1;
const	int	MaxBpaSwiF1					=2;
const	int	MaxBpaSwiFF					=2;
const	int	MaxBpaSwiF0					=2;
const	int	MaxBpaDatCase				=1;

const	int	BpaDict_Offset				=(sizeof(tagMDBBlockSummy)+sizeof(int)*MAXMDBTABLENUM);
const	int BpaDatCase_Offset			=(sizeof(tagMDBBlockSummy)+sizeof(int)*MAXMDBTABLENUM);
//const	int BpaDatCase_Offset			=(BpaDict_Offset			+MAXBPADICT			*sizeof(tagBpa_Dict));
const	int	BpaDatArea_Offset			=(BpaDatCase_Offset			+MaxBpaDatCase		*sizeof(tagBpaDat_Case));
const	int	BpaDatI_Offset				=(BpaDatArea_Offset			+MaxBpaDatArea		*sizeof(tagBpaDat_Area));
const	int	BpaDatZone_Offset			=(BpaDatI_Offset			+MaxBpaDatI			*sizeof(tagBpaDat_I));
const	int	BpaDatSub_Offset			=(BpaDatZone_Offset			+MaxBpaDatZone		*sizeof(tagBpaDat_Zone));
const	int	BpaDatACBus_Offset			=(BpaDatSub_Offset			+MaxBpaDatSub		*sizeof(tagBpaDat_Sub));
const	int	BpaDatACLine_Offset			=(BpaDatACBus_Offset		+MaxBpaDatACBus		*sizeof(tagBpaDat_ACBus));
const	int	BpaDatLineHG_Offset			=(BpaDatACLine_Offset		+MaxBpaDatACLine	*sizeof(tagBpaDat_ACLine));
const	int	BpaDatWind_Offset			=(BpaDatLineHG_Offset		+MaxBpaDatLineHG	*sizeof(tagBpaDat_LineHG));
const	int	BpaDatDCBus_Offset			=(BpaDatWind_Offset			+MaxBpaDatWind		*sizeof(tagBpaDat_Wind));
const	int	BpaDatDCLine_Offset			=(BpaDatDCBus_Offset		+MaxBpaDatDCBus		*sizeof(tagBpaDat_DCBus));
const	int	BpaDatR_Offset				=(BpaDatDCLine_Offset		+MaxBpaDatDCLine	*sizeof(tagBpaDat_DCLine));
const	int	BpaDatRZ_Offset				=(BpaDatR_Offset			+MaxBpaDatR			*sizeof(tagBpaDat_R));
const	int	BpaDatP_Offset				=(BpaDatRZ_Offset			+MaxBpaDatRZ		*sizeof(tagBpaDat_RZ));
const	int	BpaDatZIL_Offset			=(BpaDatP_Offset			+MaxBpaDatP			*sizeof(tagBpaDat_P));
const	int	BpaDatGen_Offset			=(BpaDatZIL_Offset			+MaxBpaDatZIL		*sizeof(tagBpaDat_ZIL));
const	int	BpaDatLoad_Offset			=(BpaDatGen_Offset			+MaxBpaDatGen		*sizeof(tagBpaDat_Gen));
const	int	BpaDatTran_Offset			=(BpaDatLoad_Offset			+MaxBpaDatLoad		*sizeof(tagBpaDat_Load));

const	int	BpaDatEdgeLine_Offset		=(BpaDatTran_Offset			+MaxBpaDatTran		*sizeof(tagBpaDat_Tran));
const	int	BpaDatEdgeWind_Offset		=(BpaDatEdgeLine_Offset		+MaxBpaDatEdgeLine	*sizeof(tagBpaDat_EdgeLine));
const	int BpaDatEdgeLineHG_Offset		=(BpaDatEdgeWind_Offset		+MaxBpaDatEdgeWind	*sizeof(tagBpaDat_EdgeWind));
const	int BpaDatRadiate_Offset		=(BpaDatEdgeLineHG_Offset	+MaxBpaDatEdgeLineHG*sizeof(tagBpaDat_EdgeLineHG));

const	int BpaSccFMove_Offset			=(BpaDatRadiate_Offset		+MaxBpaDatRadiate	*sizeof(tagBpaDat_Radiate));

const	int BpaSwiCase_Offset			=(BpaSccFMove_Offset		+MaxBpaSccFMove		*sizeof(tagBpaScc_FMove));
const	int	BpaSwiF1_Offset				=(BpaSwiCase_Offset			+MaxBpaSwiCase		*sizeof(tagBpaSwi_Case));
const	int	BpaSwiF0_Offset				=(BpaSwiF1_Offset			+MaxBpaSwiF1		*sizeof(tagBpaSwi_F1));
const	int	BpaSwiFF_Offset				=(BpaSwiF0_Offset			+MaxBpaSwiF0		*sizeof(tagBpaSwi_F0));

const	int	BpaSwiGen_Offset			=(BpaSwiFF_Offset			+MaxBpaSwiFF		*sizeof(tagBpaSwi_FF));
const	int	BpaSwiDamp_Offset			=(BpaSwiGen_Offset			+MaxBpaSwiGen		*sizeof(tagBpaSwi_Gen));
const	int	BpaSwiWGEGen_Offset			=(BpaSwiDamp_Offset			+MaxBpaSwiDamp		*sizeof(tagBpaSwi_Damp));
const	int	BpaSwiGenLN_Offset			=(BpaSwiWGEGen_Offset		+MaxBpaSwiWGEGen	*sizeof(tagBpaSwi_WGEGen));

const	int	BpaSwiExc68_Offset			=(BpaSwiGenLN_Offset		+MaxBpaSwiGENLN		*sizeof(tagBpaSwi_GenLn));
const	int	BpaSwiExc81_Offset			=(BpaSwiExc68_Offset		+MaxBpaSwiEXC68		*sizeof(tagBpaSwi_Exc68));
const	int	BpaSwiExcMV_Offset			=(BpaSwiExc81_Offset		+MaxBpaSwiEXC81		*sizeof(tagBpaSwi_Exc81));
const	int	BpaSwiFZ_Offset				=(BpaSwiExcMV_Offset		+MaxBpaSwiEXCMV		*sizeof(tagBpaSwi_ExcMV));
const	int	BpaSwiFCA_Offset			=(BpaSwiFZ_Offset			+MaxBpaSwiEXCMV		*sizeof(tagBpaSwi_FZ));
const	int	BpaSwiFCB_Offset			=(BpaSwiFCA_Offset			+MaxBpaSwiEXCMV		*sizeof(tagBpaSwi_FCA));

const	int	BpaSwiExcTX_Offset			=(BpaSwiFCB_Offset			+MaxBpaSwiEXCMV		*sizeof(tagBpaSwi_FCB));

const	int	BpaSwiPssS_Offset			=(BpaSwiExcTX_Offset		+MaxBpaSwiEXCX		*sizeof(tagBpaSwi_ExcX));
const	int	BpaSwiPssSH_Offset			=(BpaSwiPssS_Offset			+MaxBpaSwiPssS		*sizeof(tagBpaSwi_PssS));
const	int	BpaSwiPssSI_Offset			=(BpaSwiPssSH_Offset		+MaxBpaSwiPssSH		*sizeof(tagBpaSwi_PssSH));
const	int	BpaSwiPssSA_Offset			=(BpaSwiPssSI_Offset		+MaxBpaSwiPssSI		*sizeof(tagBpaSwi_PssSI));
const	int	BpaSwiPssSB_Offset			=(BpaSwiPssSA_Offset		+MaxBpaSwiPssSA		*sizeof(tagBpaSwi_PssSA));
const	int	BpaSwiPssST_Offset			=(BpaSwiPssSB_Offset		+MaxBpaSwiPssSB		*sizeof(tagBpaSwi_PssSB));

const	int	BpaSwiGovGG_Offset			=(BpaSwiPssST_Offset		+MaxBpaSwiPssST		*sizeof(tagBpaSwi_PssST));
const	int	BpaSwiGovGH_Offset			=(BpaSwiGovGG_Offset		+MaxBpaSwiGG		*sizeof(tagBpaSwi_GovGG));
const	int	BpaSwiGovGC_Offset			=(BpaSwiGovGH_Offset		+MaxBpaSwiGH		*sizeof(tagBpaSwi_GovGH));
const	int BpaSwiGovGS_Offset			=(BpaSwiGovGC_Offset		+MaxBpaSwiGC		*sizeof(tagBpaSwi_GovGC));
const	int BpaSwiGovGL_Offset			=(BpaSwiGovGS_Offset		+MaxBpaSwiGS		*sizeof(tagBpaSwi_GovGS));
const	int BpaSwiGovGW_Offset			=(BpaSwiGovGL_Offset		+MaxBpaSwiGL		*sizeof(tagBpaSwi_GovGL));
const	int BpaSwiGovGA_Offset			=(BpaSwiGovGW_Offset		+MaxBpaSwiGW		*sizeof(tagBpaSwi_GovGW));
const	int BpaSwiGovGI_Offset			=(BpaSwiGovGA_Offset		+MaxBpaSwiGA		*sizeof(tagBpaSwi_GovGA));
const	int BpaSwiGovGJ_Offset			=(BpaSwiGovGI_Offset		+MaxBpaSwiGI		*sizeof(tagBpaSwi_GovGI));
const	int BpaSwiGovGK_Offset			=(BpaSwiGovGJ_Offset		+MaxBpaSwiGJ		*sizeof(tagBpaSwi_GovGJ));
const	int BpaSwiGovGM_Offset			=(BpaSwiGovGK_Offset		+MaxBpaSwiGK		*sizeof(tagBpaSwi_GovGK));
const	int BpaSwiGovGD_Offset			=(BpaSwiGovGM_Offset		+MaxBpaSwiGM		*sizeof(tagBpaSwi_GovGM));
const	int BpaSwiGovGZ_Offset			=(BpaSwiGovGD_Offset		+MaxBpaSwiGD		*sizeof(tagBpaSwi_GovGD));

const	int BpaSwiTA_Offset				=(BpaSwiGovGZ_Offset		+MaxBpaSwiGZ		*sizeof(tagBpaSwi_GovGZ));
const	int BpaSwiTB_Offset				=(BpaSwiTA_Offset			+MaxBpaSwiTA		*sizeof(tagBpaSwi_MovTA));
const	int BpaSwiTC_Offset				=(BpaSwiTB_Offset			+MaxBpaSwiTB		*sizeof(tagBpaSwi_MovTB));
const	int BpaSwiTD_Offset				=(BpaSwiTC_Offset			+MaxBpaSwiTC		*sizeof(tagBpaSwi_MovTC));
const	int BpaSwiTE_Offset				=(BpaSwiTD_Offset			+MaxBpaSwiTD		*sizeof(tagBpaSwi_MovTD));
const	int BpaSwiTF_Offset				=(BpaSwiTE_Offset			+MaxBpaSwiTE		*sizeof(tagBpaSwi_MovTE));
const	int BpaSwiTW_Offset				=(BpaSwiTF_Offset			+MaxBpaSwiTF		*sizeof(tagBpaSwi_MovTF));
const	int BpaSwiGX_Offset				=(BpaSwiTW_Offset			+MaxBpaSwiTW		*sizeof(tagBpaSwi_MovTW));
const	int BpaSwiIGV_Offset			=(BpaSwiGX_Offset			+MaxBpaSwiGX		*sizeof(tagBpaSwi_GX));
const	int BpaSwiFGV_Offset			=(BpaSwiIGV_Offset			+MaxBpaSwiIGV		*sizeof(tagBpaSwi_IGV));

const	int BpaSwiLO_Offset				=(BpaSwiFGV_Offset			+MaxBpaSwiFGV		*sizeof(tagBpaSwi_FGV));
const	int BpaSwiXO_Offset				=(BpaSwiLO_Offset			+MaxBpaSwiLO		*sizeof(tagBpaSwi_LO));
const	int BpaSwiLOHG_Offset			=(BpaSwiXO_Offset			+MaxBpaSwiXO		*sizeof(tagBpaSwi_XO));
const	int BpaSwiXR_Offset				=(BpaSwiLOHG_Offset			+MaxBpaSwiLOHG		*sizeof(tagBpaSwi_LOHG));

const	int BpaSwiD_Offset				=(BpaSwiXR_Offset			+MaxBpaSwiXR		*sizeof(tagBpaSwi_XR));

const	int BpaSwiV_Offset				=(BpaSwiD_Offset			+MaxBpaSwiD			*sizeof(tagBpaSwi_D));
const	int BpaSwiVG_Offset				=(BpaSwiV_Offset			+MaxBpaSwiV			*sizeof(tagBpaSwi_V));

const	int BpaSwiLAB_Offset			=(BpaSwiVG_Offset			+MaxBpaSwiVG		*sizeof(tagBpaSwi_VG));
const	int BpaSwiMI_Offset				=(BpaSwiLAB_Offset			+MaxBpaSwiLAB		*sizeof(tagBpaSwi_LAB));
const	int BpaSwiML_Offset				=(BpaSwiMI_Offset			+MaxBpaSwiMI		*sizeof(tagBpaSwi_MI));
const	int BpaSwiMJ_Offset				=(BpaSwiML_Offset			+MaxBpaSwiML		*sizeof(tagBpaSwi_ML));
const	int BpaSwiMK_Offset				=(BpaSwiMJ_Offset			+MaxBpaSwiMJ		*sizeof(tagBpaSwi_MJ));
const	int BpaSwiUF_Offset				=(BpaSwiMK_Offset			+MaxBpaSwiMK		*sizeof(tagBpaSwi_MK));
const	int BpaSwiUV_Offset				=(BpaSwiUF_Offset			+MaxBpaSwiUF		*sizeof(tagBpaSwi_UF));
const	int BpaSwiRE_Offset				=(BpaSwiUV_Offset			+MaxBpaSwiUV		*sizeof(tagBpaSwi_UV));
const	int BpaSwiRW_Offset				=(BpaSwiRE_Offset			+MaxBpaSwiRE		*sizeof(tagBpaSwi_RE));
const	int BpaSwiRA_Offset				=(BpaSwiRW_Offset			+MaxBpaSwiRW		*sizeof(tagBpaSwi_RW));
const	int BpaSwiRU_Offset				=(BpaSwiRA_Offset			+MaxBpaSwiRA		*sizeof(tagBpaSwi_RA));

//	这里需要注意的是RESTRICT中的关键字必须为CHAR，如果不是CHAR，通过CHAR也能比较
//	字典表不排序


//	BPA卡组合
struct	_Bpa_CardComb_
{
	const char*	szMainCard;
	const char*	szExCard;
	const char*	szAugCard;
	int		nMainCate;
	int		nExCate;
	int		nAugCate;
}	DISALIGN;
typedef	struct	_Bpa_CardComb_	tagBpaCardComb;

static	tagBpaCardComb	g_BpaCardCombArray[]={
	{	"FX",	"FX+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"SB",	"SB+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"SH",	"SH+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"SI",	"SI+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"GA",	"GA+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"GI",	"GI+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"GJ",	"GJ+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"GM",	"GM+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"VG",	"VG+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"RE",	"RE+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"RW",	"RW+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"UF",	"UF+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"UV",	"UV+",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"B",	"+",	"",		BpaDatCategory_Dat, BpaDatCategory_Dat, BpaSwiCategory_Dat, },
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
