#pragma once

#include "../include/MDBDefine.h"

#if defined(__GNUG__) || defined(__GNUC__)	// GCC编译器预定义的宏
#	ifndef DISALIGN
#		define DISALIGN __attribute__((packed))
#	endif
#else
#	define DISALIGN
#endif

#if !defined(__GNUG__) && !defined(__GNUC__)
#	if (defined(_AIX) || defined(AIX))
#		pragma align(packed)
#	else
#		if (!defined(sun) && !defined(__sun) && !defined(__sun__))
#			pragma pack(push)
#		endif
#	endif
#	pragma pack(1)
#endif

//////////////////////////////////////////////////////////////////////////
//	数据库字段枚举定义

enum	_PREnum_DeviceSide_
{
	PREnum_DeviceSide_I=0,
	PREnum_DeviceSide_J,
};

enum	_PREnum_SystemSampleObject_
{
	PRSystem_SampleObject_All=0,	//	全部
	PRSystem_SampleObject_Bran,	//	支路
	PRSystem_SampleObject_Gen,	//	发电机
};

enum	_PREnum_SystemNetworkType_
{
	PRSystem_NetworkType_1=0,	//	"区域性电网",
	PRSystem_NetworkType_2,		//	"省、自治区电网",
	PRSystem_NetworkType_3,		//	"直辖市电网",
	PRSystem_NetworkType_4,		//	"省会城市电网",
	PRSystem_NetworkType_5,		//	"一般城市电网",
	PRSystem_NetworkType_6,		//	"县级市电网",
};

enum	_PREnum_DeviceRParamType_
{
	PRDevice_RParamType_Common=0,
	PRDevice_RParamType_Device,
};

enum	_PREnum_CommonFaultType_
{
	PRCommonFault_CommonFaultType_Status=0,
	PRCommonFault_CommonFaultType_PValue,
};

enum	_PREnum_CommonDeviceType_
{
	PRCommonFault_DeviceCommonType_Resion=0,
	PRCommonFault_DeviceCommonType_Result,
};

enum	_PREnum_FModeFaultType_
{
	PRTrip_FaultType_Unknown=0,	//	未知
	PRTrip_FaultType_MIsland,	//	解列
	PRTrip_FaultType_OverLmt,	//	支路越限
	PRTrip_FaultType_MiAndOl,	//	解列&支路越限
};

enum	_PREnum_FStateAdResult_
{
	PRFState_AdResult_Unknown=0,	//	未知
	PRFState_AdResult_Normal,		//	复限
	PRFState_AdResult_OverLmt,		//	越限
	PRFState_AdResult_Unadjustable,	//	不可调节
};

enum	_PREnum_FStateSaResult_
{
	PRFSecurity_Result_Unknown=0,	//	未知",
	PRFSecurity_Result_Secure,		//	安全",
	PRFSecurity_Result_InSecure,	//	不安全",
};

enum	_PREnum_FSSamplingMethod
{
	PRFState_SamplingMethod_Unknown=0,		//	未知
	PRFState_SamplingMethod_MonteCarlo,		//	蒙特卡洛
	PRFState_SamplingMethod_StateSample,	//	状态抽样
	PRFState_SamplingMethod_Analytical,		//	解析法
	PRFState_SamplingMethod_FastSort,		//	快速排序
	PRFState_SamplingMethod_Manual,
};

enum	_PREnum_FSStateType_
{
	PRFState_StateType_Fault=0,	//	故障
	PRFState_StateType_MState,	//	多状态
	PRFState_StateType_All,		//	故障+多状态
};

enum	_PREnum_FStateFaultGrade_
{
	PRFState_FaultGrade_0=0,	//
	PRFState_FaultGrade_1,		//	一般事故
	PRFState_FaultGrade_2,		//	较大事故
	PRFState_FaultGrade_3,		//	重大事故
	PRFState_FaultGrade_4,		//	特别重大事故
};


enum	_PREnum_FFaultType_
{
	PRFState_FaultType_Unknown=0,
	PRFState_FaultType_Trip,
	PRFState_FaultType_OnePhaseGround,
	PRFState_FaultType_TwoPhase,
	PRFState_FaultType_ThreePhase,
	PRFState_FaultType_TwoPhaseGround,
	PRFState_FaultType_CommonFault,
};

enum	_PREnum_BalanceAdType_
{
	PRBalanceAd_AdType_Gen=0,
	PRBalanceAd_AdType_Load,
};

enum	_PREnum_ConverterType_
{
	PRConverter_Type_Rectifier=0,
	PRConverter_Type_Inverter,
};

enum	_PREnum_ConverterFEffect_
{
	PRConverter_FEffect_Broken=0,
	PRConverter_FEffect_Connect,
};



//////////////////////////////////////////////////////////////////////////
//	数据库字段相关定义

//	容器表定义
//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_System_	{
	PR_SYSTEM_MVABASE=0,
	PR_SYSTEM_GENP,
	PR_SYSTEM_LOADP,
	PR_SYSTEM_DCP,
	PR_SYSTEM_AVAILGENP,
	PR_SYSTEM_MAXLOADP,

	PR_SYSTEM_SAMPLEMETHOD,
	PR_SYSTEM_SAMPLEOBJECT,
	PR_SYSTEM_MAXBFLT,
	PR_SYSTEM_MAXGFLT,
	PR_SYSTEM_MCSSIMTIME,
	PR_SYSTEM_MCSMINPROB,
	PR_SYSTEM_FSTCUMULATEPROB,
	PR_SYSTEM_FSTMAXSTATE,
	PR_SYSTEM_FSTMINPROB,
	PR_SYSTEM_STSMAXSTATE,
	PR_SYSTEM_ANAMINPROB,
	PR_SYSTEM_BPADATFILE,
	PR_SYSTEM_BPASWIFILE,
	PR_SYSTEM_SECURITYEXECDIR,
	PR_SYSTEM_SECURITYDESTDIR,
	PR_SYSTEM_SECURITYMAXANGLE,
	PR_SYSTEM_SECURITYMAXVOLT,
	PR_SYSTEM_SECURITYMAXVDUR,
	PR_SYSTEM_SECURITYMINVOLT,
	PR_SYSTEM_SECURITYMINVDUR,
	PR_SYSTEM_SECURITYMAXFREQ,
	PR_SYSTEM_SECURITYMAXFDUR,
	PR_SYSTEM_SECURITYMINFREQ,
	PR_SYSTEM_SECURITYMINFDUR,
	PR_SYSTEM_COPSTEP,
	PR_SYSTEM_MAXFLTDEV,
	PR_SYSTEM_CUTLOADSTATENUM,
	PR_SYSTEM_PLC,
	PR_SYSTEM_EFLC,
	PR_SYSTEM_EDLC,
	PR_SYSTEM_ADLC,
	PR_SYSTEM_ELC,
	PR_SYSTEM_EENS,
	PR_SYSTEM_BPII,
	PR_SYSTEM_BPECI,
	PR_SYSTEM_SI,
	PR_SYSTEM_LOLP,
	PR_SYSTEM_LOLF,
	PR_SYSTEM_LOLE,
	PR_SYSTEM_PLOS,
	PR_SYSTEM_FLOS,
	PR_SYSTEM_MTTIS,
	PR_SYSTEM_MIEENS,
	PR_SYSTEM_AGCEENS,
	PR_SYSTEM_ELEENS,
	PR_SYSTEM_NETWORKTYPE,
	PR_SYSTEM_FLTGRADE0PROB,
	PR_SYSTEM_FLTGRADE1PROB,
	PR_SYSTEM_FLTGRADE2PROB,
	PR_SYSTEM_FLTGRADE3PROB,
	PR_SYSTEM_FLTGRADE4PROB,
	PR_SYSTEM_LOADCURVEPACE,
	PR_SYSTEM_MAXMSDEVNUM,
};

struct	_PR_System_	{
	double			fMvaBase;
	double			fSysGenP;
	double			fSysLoadP;
	double			fSysDCP;
	double			fSysAvailGenP;
	double			fSysMaxLoadP;
	unsigned char	nSampleMethod;
	unsigned char	nSampleObject;
	unsigned char	nMaxBranFlt;
	unsigned char	nMaxGenFlt;
	double			fMCSSimTime;
	double			fMCSMinProb;
	double			fFSTCutProb;
	int				nFSTMaxState;
	double			fFSTMinProb;
	int				nSTSMaxState;
	double			fANAMinProb;
	char			szBpaDatFile[MDB_CHARLEN_LONG];
	char			szBpaSwiFile[MDB_CHARLEN_LONG];
	char			szSaRunPath[MDB_CHARLEN_LONG];
	char			szSaDesPath[MDB_CHARLEN_LONG];
	double			fMaxAngle;		//	最大功角差
	double			fMaxVolt;		//	最高电压
	double			fMaxVDur;		//	最高电压持续时间
	double			fMinVolt;		//	最低电压
	double			fMinVDur;		//	最低电压持续时间
	double			fMaxFreq;		//	最高频率
	double			fMaxFDur;		//	最高频率持续时间
	double			fMinFreq;		//	最低频率
	double			fMinFDur;		//	最低频率持续时间

	double			fCopStep;

	short			nMaxFltDev;
	int				nCutLoadState;
	double			fPLC;
	double			fEFLC;
	double			fEDLC;
	double			fADLC;
	double			fELC;
	double			fEENS;
	double			fBPII;
	double			fBPECI;
	double			fSI;
	double			fLOLP;
	double			fLOLF;
	double			fLOLE;
	double			fPLOS;
	double			fFLOS;
	double			fMTTIS;
	double			fMIslandEENS;
	double			fLossGenEENS;
	double			fERLimitEENS;
	unsigned char	nNetworkType;
	double			fFltGrade0Prob;
	double			fFltGrade1Prob;
	double			fFltGrade2Prob;
	double			fFltGrade3Prob;
	double			fFltGrade4Prob;
	short			nLoadCurvePace;
	short			nMStateDevNum;
}	DISALIGN;
typedef	struct	_PR_System_	tagPRSystem;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_Radial_	{
	PR_RADIAL_RINGBUS=0,
	PR_RADIAL_RINGKV,
	PR_RADIAL_LOADP,
	PR_RADIAL_RINGBOUNDBUSPTR,
};
struct	_PR_Radial_	{
	char	szRingBus[MDB_CHARLEN_SHORT];
	double	fRingkV;
	double	fLoadP;
	int		nRingBoundBus;
}	DISALIGN;
typedef	struct	_PR_Radial_	tagPRRadial;

//	设备表定义
//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_ACBus_	{
	PR_ACBUS_NAME=0,
	PR_ACBUS_KV,
	PR_ACBUS_ZONE,
	PR_ACBUS_GENP,
	PR_ACBUS_GENQ,
	PR_ACBUS_LOADP,
	PR_ACBUS_LOADQ,
	PR_ACBUS_RADP,
	PR_ACBUS_SHUNTQ,

	PR_ACBUS_RERR,
	PR_ACBUS_RREP,
	PR_ACBUS_TREP,

	PR_ACBUS_ADGENP,
	PR_ACBUS_ADLOADP,
	PR_ACBUS_ADRADP,

	PR_ACBUS_GOODPROB,
	PR_ACBUS_FAILPROB,
	PR_ACBUS_IRT,
	PR_ACBUS_IMAX,
	PR_ACBUS_IMIN,
	PR_ACBUS_RERRMAX,
	PR_ACBUS_RERRMIN,
	PR_ACBUS_RTV,
	PR_ACBUS_PFD,
	PR_ACBUS_PLC,
	PR_ACBUS_EFLC,
	PR_ACBUS_EDLC,
	PR_ACBUS_ADLC,
	PR_ACBUS_ELC,
	PR_ACBUS_EENS,
	PR_ACBUS_BPII,
	PR_ACBUS_BPECI,
	PR_ACBUS_SI,
	PR_ACBUS_ISLAND,
	PR_ACBUS_UVOLMTFREQ,
	PR_ACBUS_UFOLMTFREQ,
	PR_ACBUS_DVOLMTFREQ,
	PR_ACBUS_DFOLMTFREQ,
	PR_ACBUS_RADIAL,
	PR_ACBUS_SLACK,
	PR_ACBUS_SRCBUS,
	PR_ACBUS_MIDBUS,
	PR_ACBUS_GENPMAX,
	PR_ACBUS_GENPMIN,
	PR_ACBUS_LOADPMIN,
	//PR_ACBUS_BUSLOSSP,
	PR_ACBUS_BUS2LINE,
	PR_ACBUS_BUS2TRAN,
	PR_ACBUS_ZONESERIALNO,
	PR_ACBUS_RINGBOUND,
	PR_ACBUS_LOADMSTATE,
	PR_ACBUS_DCBUS,
	PR_ACBUS_RPARAMTYPE,
};
struct	_PR_ACBus_	{
	char	szName[MDB_CHARLEN_SHORT];
	float	fkV;
	char	szZone[MDB_CHARLEN_SHORTEST];
	double	fGenP;
	double	fGenQ;
	double	fLoadP;
	double	fLoadQ;
	double	fRadP;
	double	fShuntQ;

	double	fRerr;
	double	fRrep;
	double	fTrep;

	double	fAdjGenP;
	double	fAdjLoadP;
	double	fAdjRadP;

	double	fGoodProb;
	double	fFailProb;
	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;

	double	fRtV;
	double	fPfD;
	double	fPLC;
	double	fEFLC;
	double	fEDLC;
	double	fADLC;
	double	fELC;
	double	fEENS;
	double	fBPECI;
	double	fBPII;
	double	fSI;
	short	nIsland;

	int		nUVOLmtFreq;
	int		nUFOLmtFreq;
	int		nDVOLmtFreq;
	int		nDFOLmtFreq;

	short	nRadial;
	unsigned char	bSlack;
	unsigned char	bSrcBus;
	unsigned char	bMidBus;
	double	fMaxGenP;
	double	fMinGenP;
	double	fMinLoadP;
	int		nLineRange;
	int		nTranRange;
	unsigned char	nZone;
	unsigned char	bRingBound;
	unsigned char	bLoadMState;
	unsigned char	bDCBus;
	unsigned char	nRParamType;
}	DISALIGN;
typedef	struct	_PR_ACBus_	tagPRACBus;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_ACLine_	{
	PR_ACLINE_NAME=0,
	PR_ACLINE_BUSI,
	PR_ACLINE_BUSJ,
	PR_ACLINE_KVI,
	PR_ACLINE_KVJ,
	PR_ACLINE_PARID,
	PR_ACLINE_R,
	PR_ACLINE_X,
	PR_ACLINE_B,
	PR_ACLINE_RATED,
	PR_ACLINE_LENGTH,
	PR_ACLINE_WEIGHTS,
	PR_ACLINE_RERR,
	PR_ACLINE_RREP,
	PR_ACLINE_TREP,
	PR_ACLINE_GOODPROB,
	PR_ACLINE_FAILPROB,
	PR_ACLINE_IRT,
	PR_ACLINE_IMAX,
	PR_ACLINE_IMIN,
	PR_ACLINE_RERRMAX,
	PR_ACLINE_RERRMIN,
	PR_ACLINE_FAULTFREQ,
	PR_ACLINE_OLMTFREQ,
	PR_ACLINE_OLMTVALUE,
	PR_ACLINE_ELMTCUTLOAD,
	PR_ACLINE_RTPI,
	PR_ACLINE_RTQI,
	PR_ACLINE_RTPZ,
	PR_ACLINE_RTQZ,
	PR_ACLINE_LOSSP,
	PR_ACLINE_PFPI,
	PR_ACLINE_PFQI,
	PR_ACLINE_PFPZ,
	PR_ACLINE_PFQZ,
	PR_ACLINE_TRPI,
	PR_ACLINE_TRQI,
	PR_ACLINE_TRPZ,
	PR_ACLINE_TRQZ,
	PR_ACLINE_INIBUSI,
	PR_ACLINE_INIBUSJ,
	PR_ACLINE_INIKVI,
	PR_ACLINE_INIKVJ,
	PR_ACLINE_INILOOP,
	PR_ACLINE_BUSIPTR,
	PR_ACLINE_BUSJPTR,
	PR_ACLINE_RADIPTR,
	PR_ACLINE_RADJPTR,
	PR_ACLINE_SERIALNO,
	PR_ACLINE_ISLAND,
	PR_ACLINE_OUTAGE,
	PR_ACLINE_RPARAMTYPE,
	PR_ACLINE_TRMISLAND,
	PR_ACLINE_TRFACTORNUM,

	PR_ACLINE_TCSCPTR,
	PR_ACLINE_UPFCPTR,
};
struct	_PR_ACLine_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szBusI[MDB_CHARLEN_SHORT];
	char	szBusJ[MDB_CHARLEN_SHORT];
	float	fkVI;
	float	fkVJ;
	char	cLoop;
	float	fR;
	float	fX;
	float	fB;
	float	fRated;
	float	fLength;
	float	fWeights;
	double	fRerr;
	double	fRrep;
	double	fTrep;
	double	fGoodProb;
	double	fFailProb;

	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;

	int		nFaultFreq;
	int		nOLmtFreq;

	double	fOLmtValue;		//	越限值总加
	double	fELmtCutEnergy;	//	越限值消减负荷电量总加

	float	fRtPi;
	float	fRtQi;
	float	fRtPz;
	float	fRtQz;
	float	fLossP;

	float	fPfPi;
	float	fPfQi;
	float	fPfPz;
	float	fPfQz;

	float	fTrPi;
	float	fTrQi;
	float	fTrPz;
	float	fTrQz;

	char	szIniBusI[MDB_CHARLEN_SHORT];
	char	szIniBusJ[MDB_CHARLEN_SHORT];
	float	fInikVI;
	float	fInikVJ;
	char	cIniLoop;

	int		nIBus;
	int		nZBus;
	short	nIRadial;
	short	nZRadial;
	int		nIndex;
	short	nIsland;
	unsigned char	bOutage;
	unsigned char	nRParamType;
	unsigned char	bTrMIsland;
	int		nTrFactorNum;

	short	nTCSCIndex;
	short	nUPFCIndex;
}	DISALIGN;
typedef	struct	_PR_ACLine_	tagPRACLine;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_Wind_	{
	PR_WIND_NAME=0,
	PR_WIND_BUSI,
	PR_WIND_BUSJ,
	PR_WIND_KVI,
	PR_WIND_KVJ,
	PR_WIND_PARID,
	PR_WIND_R,
	PR_WIND_X,
	PR_WIND_RATED,
	PR_WIND_WEIGHTS,
	PR_WIND_RERR,
	PR_WIND_RREP,
	PR_WIND_TREP,
	PR_WIND_GOODPROB,
	PR_WIND_FAILPROB,
	PR_WIND_IRT,
	PR_WIND_IMAX,
	PR_WIND_IMIN,
	PR_WIND_RERRMAX,
	PR_WIND_RERRMIN,
	PR_WIND_FAULTFREQ,
	PR_WIND_OLMTFREQ,
	PR_WIND_OLMTVALUE,
	PR_WIND_ELMTCUTLOAD,
	PR_WIND_RTPI,
	PR_WIND_RTQI,
	PR_WIND_RTPZ,
	PR_WIND_RTQZ,
	PR_WIND_LOSSP,
	PR_WIND_PFPI,
	PR_WIND_PFQI,
	PR_WIND_PFPZ,
	PR_WIND_PFQZ,
	PR_WIND_TRPI,
	PR_WIND_TRQI,
	PR_WIND_TRPZ,
	PR_WIND_TRQZ,
	PR_WIND_INIBUSI,
	PR_WIND_INIBUSJ,
	PR_WIND_INIKVI,
	PR_WIND_INIKVJ,
	PR_WIND_INILOOP,
	PR_WIND_BUSIPTR,
	PR_WIND_BUSJPTR,
	PR_WIND_RADIPTR,
	PR_WIND_RADJPTR,
	PR_WIND_SERIALNO,
	PR_WIND_ISLAND,
	PR_WIND_GENTRAN,
	PR_WIND_OUTAGE,
	PR_WIND_RPARAMTYPE,
	PR_WIND_TRMISLAND,
	PR_WIND_TRFACTORNUM,
};
struct	_PR_Wind_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szBusI[MDB_CHARLEN_SHORT];
	char	szBusJ[MDB_CHARLEN_SHORT];
	float	fkVI;
	float	fkVJ;
	char	cLoop;
	float	fR;
	float	fX;
	float	fRated;
	float	fWeights;
	double	fRerr;
	double	fRrep;
	double	fTrep;
	double	fGoodProb;
	double	fFailProb;
	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;

	int		nFaultFreq;
	int		nOLmtFreq;
	double	fOLmtValue;		//	越限值总加
	double	fELmtCutEnergy;	//	越限值消减负荷电量总加

	float	fRtPi;
	float	fRtQi;
	float	fRtPz;
	float	fRtQz;
	float	fLossP;

	float	fPfPi;
	float	fPfQi;
	float	fPfPz;
	float	fPfQz;

	float	fTrPi;
	float	fTrQi;
	float	fTrPz;
	float	fTrQz;

	char	szIniBusI[MDB_CHARLEN_SHORT];
	char	szIniBusJ[MDB_CHARLEN_SHORT];
	float	fInikVI;
	float	fInikVJ;
	char	cIniLoop;

	int		nIBus;
	int		nZBus;
	short	nIRadial;
	short	nZRadial;
	int		nIndex;
	short	nIsland;
	unsigned char	bGenTran;
	unsigned char	bOutage;
	unsigned char	nRParamType;
	unsigned char	bTrMIsland;
	int		nTrFactorNum;
}	DISALIGN;
typedef	struct	_PR_Wind_	tagPRWind;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_Gen_	{
	PR_GENERATOR_NAME=0,
	PR_GENERATOR_BUSNAME,
	PR_GENERATOR_BUSKV,
	PR_GENERATOR_GENID,
	PR_GENERATOR_ZONE,
	PR_GENERATOR_P,
	PR_GENERATOR_Q,
	PR_GENERATOR_PMAX,
	PR_GENERATOR_PMIN,
	PR_GENERATOR_QMAX,
	PR_GENERATOR_QMIN,
	PR_GENERATOR_RERR,
	PR_GENERATOR_RREP,
	PR_GENERATOR_TREP,
	PR_GENERATOR_GOODPROB,
	PR_GENERATOR_FAILPROB,
	PR_GENERATOR_IRT,
	PR_GENERATOR_IMAX,
	PR_GENERATOR_IMIN,
	PR_GENERATOR_RERRMAX,
	PR_GENERATOR_RERRMIN,
	PR_GENERATOR_MSMODEL,
	PR_GENERATOR_MSTATENUM,
	PR_GENERATOR_MSPOUT,
	PR_GENERATOR_REFP,
	PR_GENERATOR_REFQ,
	PR_GENERATOR_FAULTFREQ,
	PR_GENERATOR_EQGEN,
	PR_GENERATOR_RADIAL,
	PR_GENERATOR_BUSPTR,
	PR_GENERATOR_RPARAMTYPE,
	PR_GENERATOR_OUTAGE,
};
struct	_PR_Gen_	{
	char			szName[MDB_CHARLEN_SHORT];
	char			szBus[MDB_CHARLEN_SHORT];
	float			fkV;
	char			cGenId;
	char			szZone[MDB_CHARLEN_SHORTEST];
	float			fP;
	float			fQ;
	float			fPMax;
	float			fPMin;
	float			fQMax;
	float			fQMin;
	double			fRerr;
	double			fRrep;
	double			fTrep;
	double			fGoodProb;
	double			fFailProb;
	double			fIRt;
	double			fIMax;
	double			fIMin;
	double			fRerrMax;
	double			fRerrMin;

	unsigned char	bMSModel;
	unsigned char	nMStateNum;
	double			fMSPout;


	float			fReferenceP;
	float			fReferenceQ;

	int				nFaultFreq;

	unsigned char	bEQGen;
	short			nRadial;
	int				nBusIndex;
	unsigned char	nRParamType;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PR_Gen_	tagPRGenerator;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_PowerLoad_	{
	PR_POWERLOAD_NAME=0,
	PR_POWERLOAD_BUSNAME,
	PR_POWERLOAD_BUSKV,
	PR_POWERLOAD_ZONE,
	PR_POWERLOAD_P,
	PR_POWERLOAD_Q,
	PR_POWERLOAD_PMAX,
	PR_POWERLOAD_RERR,
	PR_POWERLOAD_RREP,
	PR_POWERLOAD_TREP,
	PR_POWERLOAD_GOODPROB,
	PR_POWERLOAD_FAILPROB,
	PR_POWERLOAD_IRT,
	PR_POWERLOAD_IMAX,
	PR_POWERLOAD_IMIN,
	PR_POWERLOAD_RERRMAX,
	PR_POWERLOAD_RERRMIN,
	PR_POWERLOAD_FAULTFREQ,
	PR_POWERLOAD_MSMODEL,
	PR_POWERLOAD_MSTATENUM,
	PR_POWERLOAD_MSPOUT,
	PR_POWERLOAD_REFP,
	PR_POWERLOAD_REFQ,
	PR_POWERLOAD_RADIAL,
	PR_POWERLOAD_BUSPTR,
	PR_POWERLOAD_AUXLOAD,
	PR_POWERLOAD_EQLOAD,
	PR_POWERLOAD_RPARAMTYPE,
	PR_POWERLOAD_OUTAGE,
};
struct	_PR_PowerLoad_	{
	char			szName[MDB_CHARLEN_SHORT];
	char			szBus[MDB_CHARLEN_SHORT];
	float			fkV;
	char			szZone[MDB_CHARLEN_SHORTEST];
	float			fP;
	float			fQ;
	float			fPMax;
	double			fRerr;
	double			fRrep;
	double			fTrep;
	double			fGoodProb;
	double			fFailProb;
	double			fIRt;
	double			fIMax;
	double			fIMin;
	double			fRerrMax;
	double			fRerrMin;
	unsigned char	bMSModel;
	unsigned char	nMStateNum;
	double			fMSPout;

	float			fReferenceP;
	float			fReferenceQ;
	int				nFaultFreq;

	short			nRadial;
	int				nBusIndex;
	unsigned char	bAuxLoad;
	unsigned char	bEQLoad;
	unsigned char	nRParamType;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PR_PowerLoad_	tagPRPowerLoad;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_HVDC_	{
	PR_HVDC_NAME=0,
	PR_HVDC_ACBUSR,
	PR_HVDC_ACBUSI,
	PR_HVDC_KVR,
	PR_HVDC_KVI,
	PR_HVDC_R,
	PR_HVDC_L,
	PR_HVDC_C,
	PR_HVDC_CON,

	PR_HVDC_RATEDC,
	PR_HVDC_RECTV,
	PR_HVDC_RATEDP,

	PR_HVDC_POWER,
	PR_HVDC_PWRR,
	PR_HVDC_PWRI,
	PR_HVDC_LOSSP,
	PR_HVDC_RERR,
	PR_HVDC_RREP,
	PR_HVDC_TREP,

	PR_HVDC_GOODPROB,
	PR_HVDC_FAILPROB,

	PR_HVDC_IRT,
	PR_HVDC_IMAX,
	PR_HVDC_IMIN,
	PR_HVDC_RERRMAX,
	PR_HVDC_RERRMIN,
	PR_HVDC_FAULTFREQ,

	PR_HVDC_MSMODEL,
	PR_HVDC_MSTATENUM,
	PR_HVDC_MSPOUT,
	PR_HVDC_INIBUSR,
	PR_HVDC_INIBUSI,
	PR_HVDC_INIPWRR,
	PR_HVDC_INIPWRI,
	PR_HVDC_ACBUSRPTR,
	PR_HVDC_ACBUSIPTR,
	PR_HVDC_SERIALNO,
	PR_HVDC_OUTAGE,
};
struct	_PR_HVDC_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szACBusR[MDB_CHARLEN_SHORT];
	char	szACBusI[MDB_CHARLEN_SHORT];
	float	fkVR;
	float	fkVI;
	float	fR;
	float	fL;
	float	fC;
	char	cCon;

	float	fRatedC;
	float	fRectV;
	float	fRatedP;

	float	fDCPower;
	float	fPr;
	float	fPi;
	float	fLossP;
	double	fRerr;
	double	fRrep;
	double	fTrep;
	double	fGoodProb;
	double	fFailProb;

	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;

	int		nFaultFreq;

	unsigned char	bMSModel;
	unsigned char	nMStateNum;
	double	fMSPout;

	char	szIniBusR[MDB_CHARLEN_SHORT];
	char	szIniBusI[MDB_CHARLEN_SHORT];
	float	fIniPr;
	float	fIniPi;
	int		nRBus;
	int		nIBus;
	int		nIndex;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PR_HVDC_	tagPRHVDC;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_DCBus_	{
	PR_DCBUS_NAME = 0,
};
struct	_PR_DCBus_	{
	char	szName[MDB_CHARLEN_SHORT];
}	DISALIGN;
typedef	struct	_PR_DCBus_	tagPRDCBus;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_Converter_	{
	PR_CONVERTER_NAME=0,
	PR_CONVERTER_BUSAC,
	PR_CONVERTER_BUSDC,
	PR_CONVERTER_SCHEDPOWER,
	PR_CONVERTER_TYPE,
	PR_CONVERTER_RERR,
	PR_CONVERTER_RREP,
	PR_CONVERTER_TREP,
	PR_CONVERTER_GOODPROB,
	PR_CONVERTER_FAILPROB,
	PR_CONVERTER_IRT,		
	PR_CONVERTER_IMAX,		
	PR_CONVERTER_IMIN,		
	PR_CONVERTER_RERRMAX,	
	PR_CONVERTER_RERRMIN,	
	PR_CONVERTER_FAULTFREQ,
	PR_CONVERTER_ACBUSPTR,
	PR_CONVERTER_DCBUSPTR,
	PR_CONVERTER_OUTAGE,
};
struct	_PR_Converter_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szACBus[MDB_CHARLEN_SHORT];
	char	szDCBus[MDB_CHARLEN_SHORT];
	float	fConverterPower;
	unsigned char	nType;
	double	fRerr;
	double	fRrep;
	double	fTrep;
	double	fGoodProb;
	double	fFailProb;

	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;

	int		nFaultFreq;
	int		nACBus;
	int		nDCBus;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PR_Converter_	tagPRConverter;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_DCLine_	{
	PR_DCLINE_NAME=0,
	PR_DCLINE_DCBUSI,
	PR_DCLINE_DCBUSJ,
	PR_DCLINE_LENGTH,
	PR_DCLINE_RERR,
	PR_DCLINE_RREP,
	PR_DCLINE_TREP,
	PR_DCLINE_GOODPROB,
	PR_DCLINE_FAILPROB,
	PR_DCLINE_IRT,
	PR_DCLINE_IMAX,
	PR_DCLINE_IMIN,
	PR_DCLINE_RERRMAX,
	PR_DCLINE_RERRMIN,
	PR_DCLINE_FAULTFREQ,
	PR_DCLINE_DCBUSIPTR,
	PR_DCLINE_DCBUSJPTR,
	PR_DCLINE_OUTAGE,
};
struct	_PR_DCLine_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szDCBusI[MDB_CHARLEN_SHORT];
	char	szDCBusJ[MDB_CHARLEN_SHORT];
	float	fLength;
	double	fRerr;
	double	fRrep;
	double	fTrep;
	double	fGoodProb;
	double	fFailProb;
	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;
	int		nFaultFreq;
	int		nDCBusI;
	int		nDCBusJ;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PR_DCLine_	tagPRDCLine;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_TCSC_	{
	PR_TCSC_NAME=0,
	PR_TCSC_INSTBUS,
	PR_TCSC_X,
	PR_TCSC_RERR,
	PR_TCSC_RREP,
	PR_TCSC_TREP,
	PR_TCSC_GOODPROB,
	PR_TCSC_FAILPROB,

	PR_TCSC_IRT,
	PR_TCSC_IMAX,
	PR_TCSC_IMIN,
	PR_TCSC_RERRMAX,
	PR_TCSC_RERRMIN,
	PR_TCSC_FAULTFREQ,

	PR_TCSC_INSTBUSPTR,
	PR_TCSC_ACLINEPTR,
	PR_TCSC_OUTAGE,
};
struct	_PR_TCSC_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szInstBus[MDB_CHARLEN_SHORT];
	float	fX;
	double	fRerr;
	double	fRrep;
	double	fTrep;
	double	fGoodProb;
	double	fFailProb;

	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;

	int		nFaultFreq;
	int		nInstBus;
	int		nACLine;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PR_TCSC_	tagPRTCSC;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_UPFC_	{
	PR_UPFC_NAME=0,
	PR_UPFC_SERIESBUS,
	PR_UPFC_PARALLELBUS,
	PR_UPFC_CAPACITY,
	PR_UPFC_RERR,
	PR_UPFC_RREP,
	PR_UPFC_TREP,
	PR_UPFC_GOODPROB,
	PR_UPFC_FAILPROB,

	PR_UPFC_IRT,
	PR_UPFC_IMAX,
	PR_UPFC_IMIN,
	PR_UPFC_RERRMAX,
	PR_UPFC_RERRMIN,

	PR_UPFC_LINEPSE,

	PR_UPFC_P,
	PR_UPFC_FAULTFREQ,
	PR_UPFC_SERIESBUSPTR,
	PR_UPFC_PARALLELBUSPTR,
	PR_UPFC_ACLINEPTR,
	PR_UPFC_OUTAGE,
};
struct	_PR_UPFC_	{
	char	szName[MDB_CHARLEN_SHORT];
	char	szSeriesBus[MDB_CHARLEN_SHORT];
	char	szParallelBus[MDB_CHARLEN_SHORT];
	float	fCapacity;
	double	fRerr;
	double	fRrep;
	double	fTrep;
	double	fGoodProb;
	double	fFailProb;

	double	fIRt;
	double	fIMax;
	double	fIMin;
	double	fRerrMax;
	double	fRerrMin;

	float	fLinePse;
	double	fPControl;

	int		nFaultFreq;
	int		nSeriesBus;
	int		nParallelBus;
	int		nACLine;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PR_UPFC_	tagPRUPFC;

// //////////////////////////////////////////////////////////////////////////
// enum	_PREnum_Field_DevMState_	{
// 	PR_DEVMSTATE_TYPE=0,
// 	PR_DEVMSTATE_NAME,
// 	PR_DEVMSTATE_STATERATE,
// 	PR_DEVMSTATE_STATEPROB,
// 	PR_DEVMSTATE_STATEFREQ1,
// 	PR_DEVMSTATE_STATEFREQ2,
// 	PR_DEVMSTATE_STATEFREQ3,
// 	PR_DEVMSTATE_STATEFREQ4,
// 	PR_DEVMSTATE_STATEFREQ5,
// 	PR_DEVMSTATE_STATEFREQ6,
// 	PR_DEVMSTATE_STATEFREQ7,
// 	PR_DEVMSTATE_STATEFREQ8,
// 	PR_DEVMSTATE_SERIALNO,
// };
// struct	_PR_DevMState_	{
// 	short			nType;
// 	char			szName[MDB_CHARLEN_SHORT];
// 	double			fStateRate;
// 	double			fStateProb;
// 	double			fStateFreq1;
// 	double			fStateFreq2;
// 	double			fStateFreq3;
// 	double			fStateFreq4;
// 	double			fStateFreq5;
// 	double			fStateFreq6;
// 	double			fStateFreq7;
// 	double			fStateFreq8;
// 	short			nIndex;
// }	DISALIGN;
// typedef	struct	_PR_DevMState_	tagPRDevMState;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_DevMState_	{
	PR_DEVMSTATE_TYPE=0,
	PR_DEVMSTATE_NAME,
	PR_DEVMSTATE_STATENUM,
	PR_DEVMSTATE_STATE1RATE,
	PR_DEVMSTATE_STATE2RATE,
	PR_DEVMSTATE_STATE3RATE,
	PR_DEVMSTATE_STATE4RATE,
	PR_DEVMSTATE_STATE5RATE,
	PR_DEVMSTATE_STATE6RATE,
	PR_DEVMSTATE_STATE7RATE,
	PR_DEVMSTATE_STATE8RATE,
	PR_DEVMSTATE_STATE1PROB,
	PR_DEVMSTATE_STATE2PROB,
	PR_DEVMSTATE_STATE3PROB,
	PR_DEVMSTATE_STATE4PROB,
	PR_DEVMSTATE_STATE5PROB,
	PR_DEVMSTATE_STATE6PROB,
	PR_DEVMSTATE_STATE7PROB,
	PR_DEVMSTATE_STATE8PROB,
	PR_DEVMSTATE_STATE1FREQ1,
	PR_DEVMSTATE_STATE1FREQ2,
	PR_DEVMSTATE_STATE1FREQ3,
	PR_DEVMSTATE_STATE1FREQ4,
	PR_DEVMSTATE_STATE1FREQ5,
	PR_DEVMSTATE_STATE1FREQ6,
	PR_DEVMSTATE_STATE1FREQ7,
	PR_DEVMSTATE_STATE1FREQ8,
	PR_DEVMSTATE_STATE2FREQ1,
	PR_DEVMSTATE_STATE2FREQ2,
	PR_DEVMSTATE_STATE2FREQ3,
	PR_DEVMSTATE_STATE2FREQ4,
	PR_DEVMSTATE_STATE2FREQ5,
	PR_DEVMSTATE_STATE2FREQ6,
	PR_DEVMSTATE_STATE2FREQ7,
	PR_DEVMSTATE_STATE2FREQ8,
	PR_DEVMSTATE_STATE3FREQ1,
	PR_DEVMSTATE_STATE3FREQ2,
	PR_DEVMSTATE_STATE3FREQ3,
	PR_DEVMSTATE_STATE3FREQ4,
	PR_DEVMSTATE_STATE3FREQ5,
	PR_DEVMSTATE_STATE3FREQ6,
	PR_DEVMSTATE_STATE3FREQ7,
	PR_DEVMSTATE_STATE3FREQ8,
	PR_DEVMSTATE_STATE4FREQ1,
	PR_DEVMSTATE_STATE4FREQ2,
	PR_DEVMSTATE_STATE4FREQ3,
	PR_DEVMSTATE_STATE4FREQ4,
	PR_DEVMSTATE_STATE4FREQ5,
	PR_DEVMSTATE_STATE4FREQ6,
	PR_DEVMSTATE_STATE4FREQ7,
	PR_DEVMSTATE_STATE4FREQ8,
	PR_DEVMSTATE_STATE5FREQ1,
	PR_DEVMSTATE_STATE5FREQ2,
	PR_DEVMSTATE_STATE5FREQ3,
	PR_DEVMSTATE_STATE5FREQ4,
	PR_DEVMSTATE_STATE5FREQ5,
	PR_DEVMSTATE_STATE5FREQ6,
	PR_DEVMSTATE_STATE5FREQ7,
	PR_DEVMSTATE_STATE5FREQ8,
	PR_DEVMSTATE_STATE6FREQ1,
	PR_DEVMSTATE_STATE6FREQ2,
	PR_DEVMSTATE_STATE6FREQ3,
	PR_DEVMSTATE_STATE6FREQ4,
	PR_DEVMSTATE_STATE6FREQ5,
	PR_DEVMSTATE_STATE6FREQ6,
	PR_DEVMSTATE_STATE6FREQ7,
	PR_DEVMSTATE_STATE6FREQ8,
	PR_DEVMSTATE_STATE7FREQ1,
	PR_DEVMSTATE_STATE7FREQ2,
	PR_DEVMSTATE_STATE7FREQ3,
	PR_DEVMSTATE_STATE7FREQ4,
	PR_DEVMSTATE_STATE7FREQ5,
	PR_DEVMSTATE_STATE7FREQ6,
	PR_DEVMSTATE_STATE7FREQ7,
	PR_DEVMSTATE_STATE7FREQ8,
	PR_DEVMSTATE_STATE8FREQ1,
	PR_DEVMSTATE_STATE8FREQ2,
	PR_DEVMSTATE_STATE8FREQ3,
	PR_DEVMSTATE_STATE8FREQ4,
	PR_DEVMSTATE_STATE8FREQ5,
	PR_DEVMSTATE_STATE8FREQ6,
	PR_DEVMSTATE_STATE8FREQ7,
	PR_DEVMSTATE_STATE8FREQ8,
	PR_DEVMSTATE_SERIALNO,
};
struct	_PR_DevMState_	{
	short			nType;
	char			szName[MDB_CHARLEN_SHORT];
	unsigned char	nStateNum;
	double			fState1Rate;
	double			fState2Rate;
	double			fState3Rate;
	double			fState4Rate;
	double			fState5Rate;
	double			fState6Rate;
	double			fState7Rate;
	double			fState8Rate;
	double			fState1Prob;
	double			fState2Prob;
	double			fState3Prob;
	double			fState4Prob;
	double			fState5Prob;
	double			fState6Prob;
	double			fState7Prob;
	double			fState8Prob;
	double			fState1Freq1;
	double			fState1Freq2;
	double			fState1Freq3;
	double			fState1Freq4;
	double			fState1Freq5;
	double			fState1Freq6;
	double			fState1Freq7;
	double			fState1Freq8;
	double			fState2Freq1;
	double			fState2Freq2;
	double			fState2Freq3;
	double			fState2Freq4;
	double			fState2Freq5;
	double			fState2Freq6;
	double			fState2Freq7;
	double			fState2Freq8;
	double			fState3Freq1;
	double			fState3Freq2;
	double			fState3Freq3;
	double			fState3Freq4;
	double			fState3Freq5;
	double			fState3Freq6;
	double			fState3Freq7;
	double			fState3Freq8;
	double			fState4Freq1;
	double			fState4Freq2;
	double			fState4Freq3;
	double			fState4Freq4;
	double			fState4Freq5;
	double			fState4Freq6;
	double			fState4Freq7;
	double			fState4Freq8;
	double			fState5Freq1;
	double			fState5Freq2;
	double			fState5Freq3;
	double			fState5Freq4;
	double			fState5Freq5;
	double			fState5Freq6;
	double			fState5Freq7;
	double			fState5Freq8;
	double			fState6Freq1;
	double			fState6Freq2;
	double			fState6Freq3;
	double			fState6Freq4;
	double			fState6Freq5;
	double			fState6Freq6;
	double			fState6Freq7;
	double			fState6Freq8;
	double			fState7Freq1;
	double			fState7Freq2;
	double			fState7Freq3;
	double			fState7Freq4;
	double			fState7Freq5;
	double			fState7Freq6;
	double			fState7Freq7;
	double			fState7Freq8;
	double			fState8Freq1;
	double			fState8Freq2;
	double			fState8Freq3;
	double			fState8Freq4;
	double			fState8Freq5;
	double			fState8Freq6;
	double			fState8Freq7;
	double			fState8Freq8;
	short			nIndex;
}	DISALIGN;
typedef	struct	_PR_DevMState_	tagPRDevMState;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_LoadCurve_	{
	PR_LOADCURVE_BUS=0,
	PR_LOADCURVE_ID,
	PR_LOADCURVE_VALDAY,
	PR_LOADCURVE_VALAVER,
	PR_LOADCURVE_VALMAX,
	PR_LOADCURVE_VALMIN,
	PR_LOADCURVE_VALUE01,
	PR_LOADCURVE_VALUE02,
	PR_LOADCURVE_VALUE03,
	PR_LOADCURVE_VALUE04,
	PR_LOADCURVE_VALUE05,
	PR_LOADCURVE_VALUE06,
	PR_LOADCURVE_VALUE07,
	PR_LOADCURVE_VALUE08,
	PR_LOADCURVE_VALUE09,
	PR_LOADCURVE_VALUE10,
	PR_LOADCURVE_VALUE11,
	PR_LOADCURVE_VALUE12,
	PR_LOADCURVE_VALUE13,
	PR_LOADCURVE_VALUE14,
	PR_LOADCURVE_VALUE15,
	PR_LOADCURVE_VALUE16,
	PR_LOADCURVE_VALUE17,
	PR_LOADCURVE_VALUE18,
	PR_LOADCURVE_VALUE19,
	PR_LOADCURVE_VALUE20,
	PR_LOADCURVE_VALUE21,
	PR_LOADCURVE_VALUE22,
	PR_LOADCURVE_VALUE23,
	PR_LOADCURVE_VALUE24,
};
struct	_PR_LoadCurve_	{
	char			szBusName[MDB_CHARLEN_SHORT];
	short			nID;			//	负荷值所在日
	float			fValDay;		//	日负荷值
	float			fValAver;		//	负荷均值
	float			fValMax;		//	负荷最大值
	float			fValMin;		//	负荷最小值
	float			fValue01;		//	负荷值01
	float			fValue02;		//	负荷值02
	float			fValue03;		//	负荷值03
	float			fValue04;		//	负荷值04
	float			fValue05;		//	负荷值05
	float			fValue06;		//	负荷值06
	float			fValue07;		//	负荷值07
	float			fValue08;		//	负荷值08
	float			fValue09;		//	负荷值09
	float			fValue10;		//	负荷值10
	float			fValue11;		//	负荷值11
	float			fValue12;		//	负荷值12
	float			fValue13;		//	负荷值13
	float			fValue14;		//	负荷值14
	float			fValue15;		//	负荷值15
	float			fValue16;		//	负荷值16
	float			fValue17;		//	负荷值17
	float			fValue18;		//	负荷值18
	float			fValue19;		//	负荷值19
	float			fValue20;		//	负荷值20
	float			fValue21;		//	负荷值21
	float			fValue22;		//	负荷值22
	float			fValue23;		//	负荷值23
	float			fValue24;		//	负荷值24
}	DISALIGN;
typedef	struct	_PR_LoadCurve_	tagPRLoadCurve;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_ACIsland_	{
	PR_ACISLAND_GENP=0,
	PR_ACISLAND_LOADP,
	PR_ACISLAND_BUSNUM,
	PR_ACISLAND_SWINGBUS,
	PR_ACISLAND_DEAD,
};
struct	_PR_ACIsland_	{
	double	fGenP;
	double	fLoadP;
	int		nBusNum;
	int		nSwingBus;
	unsigned char	bDead;
}	DISALIGN;
typedef	struct	_PR_ACIsland_	tagPRACIsland;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_DCIsland_	{
	PR_DCISLAND_BUSNUM=0,
};
struct	_PR_DCIsland_	{
	int		nBusNum;
}	DISALIGN;
typedef	struct	_PR_DCIsland_	tagPRDCIsland;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_Zone_
{
	PR_ZONE_NAME=0,
	PR_ZONE_AREA,
	PR_ZONE_TOTGENP,
	PR_ZONE_TOTLOADP,
	PR_ZONE_CUTLOADP,
};
struct	_PR_Zone_
{
	char		szName[MDB_CHARLEN_SHORTER];			//	分区名称
	char		szArea[MDB_CHARLEN_SHORTER];
	float		fTotGenP;
	float		fTotLoadP;
	float		fCutLoadP;
}	DISALIGN;
typedef	struct	_PR_Zone_	tagPRZone;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_ACLineEdge_	{
	PR_ACLINEEDGE_BUS=0,
	PR_ACLINEEDGE_KV,
	PR_ACLINEEDGE_NAME,
	PR_ACLINEEDGE_LINEPTR,
};
struct	_PR_ACLineEdge_	{
	char	szBus[MDB_CHARLEN_SHORT];
	float	fkV;
	char	szLine[MDB_CHARLEN_SHORT];
	int		nLine;
}	DISALIGN;
typedef	struct	_PR_ACLineEdge_	tagPRACLineEdge;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_WindEdge_	{
	PR_WINDEDGE_BUS=0,
	PR_WINDEDGE_KV,
	PR_WINDEDGE_NAME,
	PR_WINDEDGE_TRANPTR,
};
struct	_PR_WindEdge_	{
	char	szBus[MDB_CHARLEN_SHORT];
	float	fkV;
	char	szTran[MDB_CHARLEN_SHORT];
	int		nTran;
}	DISALIGN;
typedef	struct	_PR_WindEdge_	tagPRWindEdge;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_DCLineEdge_	{
	PR_DCLINEEDGE_BUS=0,
	PR_DCLINEEDGE_KV,
	PR_DCLINEEDGE_NAME,
	PR_DCLINEEDGE_LINEPTR,
};
struct	_PR_DCLineEdge_	{
	char	szBus[MDB_CHARLEN_SHORT];
	float	fkV;
	char	szLine[MDB_CHARLEN_SHORT];
	int		nLine;
}	DISALIGN;
typedef	struct	_PR_DCLineEdge_	tagPRDCLineEdge;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_LDFactor_	{
	PR_LDFACTOR_LINEIDX=0,
	PR_LDFACTOR_BUSIDX,
	PR_LDFACTOR_DFACTOR,
};
struct	_PR_LDFactor_	{
	int		nLineIdx;
	int		nBus;
	double	fDFactor;
}	DISALIGN;
typedef	struct	_PR_LDFactor_	tagPRLDFactor;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_TDFactor_	{
	PR_TDFACTOR_TRANIDX=0,
	PR_TDFACTOR_BUSIDX,
	PR_TDFACTOR_DFACTOR,
};
struct	_PR_TDFactor_	{
	int		nTranIdx;
	int		nBus;
	double	fDFactor;
}	DISALIGN;
typedef	struct	_PR_TDFactor_	tagPRTDFactor;

//	需要根据数据信息计算状态和持续时间，所以需要保存状态概率、

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CommParam_	{
	PR_COMMPARAM_DEVTYPE=0,
	PR_COMMPARAM_KEYWORD,
	PR_COMMPARAM_UPCAPLMT,
	PR_COMMPARAM_DNCAPLMT,
	PR_COMMPARAM_UPVLMT,
	PR_COMMPARAM_DNVLMT,
	PR_COMMPARAM_RERR,
	PR_COMMPARAM_TREP,
};
struct	_PR_CommParam_	{
	unsigned char	nDevType;						//	PR_ACLINE, PR_WIND, PR_GENERATOR...
	char	szKeyWord[MDB_CHARLEN_SHORTER];			//	Type=0,KeyWord=Null Area[Zone]
	double	fUpCapLmt;
	double	fDnCapLmt;
	double	fUpVLmt;
	double	fDnVLmt;
	double	fRerr;
	double	fTrep;
}	DISALIGN;
typedef	struct	_PR_CommParam_	tagPRCommRParam;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_ManualFault_	{
	PR_MANUALFAULT_NAME=0,
	PR_MANUALFAULT_FDEVTYPE,
	PR_MANUALFAULT_FDEVNAME,
	PR_MANUALFAULT_FDEVSERNO,
	PR_MANUALFAULT_PROC,
};
struct	_PR_ManualFault_	{
	char	szName[MDB_CHARLEN];	
	unsigned char	nFDevType;				
	char	szFDevName[MDB_CHARLEN];
	int		nFDevIndex;
	unsigned char	bProc;
}	DISALIGN;
typedef	struct	_PR_ManualFault_	tagPRManualFault;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CommonFault_	{
	PR_COMMONFAULT_NAME=0,
	PR_COMMONFAULT_COMMFAULTTYPE,
	PR_COMMONFAULT_DEVICECOMMTYPE,
	PR_COMMONFAULT_DEVTYPE,
	PR_COMMONFAULT_DEVNAME,
	PR_COMMONFAULT_DEVSERNO,
	PR_COMMONFAULT_PROC,
};
struct	_PR_CommonFault_	{
	char	szName[MDB_CHARLEN];	
	unsigned char	nCommonFaultType;
	unsigned char	nDeviceCommonType;
	unsigned char	nDevType;
	char			szDevName[MDB_CHARLEN];
	int				nDevIndex;
	unsigned char	bProc;
}	DISALIGN;
typedef	struct	_PR_CommonFault_	tagPRCommonFault;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_PR2StateComp_	{
	PR_R2STATECOMP_TYPE=0,
	PR_R2STATECOMP_SERIALNO,
};
struct	_PR_R2StateComp_	{
	unsigned char	nType;
	int				nIndex;
}	DISALIGN;
typedef	struct	_PR_R2StateComp_	tagPR2StateComp;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_PRMStateComp_	{
	PR_RMSTATECOMP_TYPE=0,
	PR_RMSTATECOMP_SERIALNO,
};
struct	_PR_RMStateComp_	{
	unsigned char	nType;
	int				nIndex;
}	DISALIGN;
typedef	struct	_PR_RMStateComp_	tagPRMStateComp;

//////////////////////////////////////////////////////////////////////////
const	int		g_nMaxFModeAdjust=10;
enum	_PREnum_Field_Trip_	{
	PR_TRIP_DEVNUM=0,
	PR_TRIP_TRB1TYP,
	PR_TRIP_TRB1IDX,
	PR_TRIP_TRB2TYP,
	PR_TRIP_TRB2IDX,
	PR_TRIP_FAULTTYPE,
	PR_TRIP_OUTLOADP,
	PR_TRIP_OVERLMT,
};
struct	_PR_Trip_	{
	short			nTripDevNum;
	unsigned char	nTrB1Typ;
	int				nTrB1Idx;
	unsigned char	nTrB2Typ;
	int				nTrB2Idx;
	unsigned char	nFaultType;
	float			fOutageLoadP;
	unsigned char	bOverLimit;
}	DISALIGN;
typedef	struct	_PR_Trip_	tagPRTrip;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_TripMIsland_	{
	PR_TRIPMISLAND_TRIP=0,
	PR_TRIPMISLAND_OUTAGEBUS,
	PR_TRIPMISLAND_OUTAGELOADP,
};
struct	_PR_TripMIsland_	{
	int				nTrip;
	int				nOutageBus;
	float			fOutageLoadP;
}	DISALIGN;
typedef	struct	_PR_TripMIsland_	tagPRTripMIsland;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_TripOvLmtDev_	{
	PR_TRIPOVLDEV_TRIP=0,
	PR_TRIPOVLDEV_TYPE,
	PR_TRIPOVLDEV_SERIALNO,
	PR_TRIPOVLDEV_OVLVAL,
	PR_TRIPOVLDEV_RATED,
};
struct	_PR_TripOvLmtDev_	{
	int				nTrip;
	unsigned char	nDevTyp;
	int				nDevIdx;
	float			fOvLmtP;
	float			fRated;
}	DISALIGN;
typedef	struct	_PR_TripOvLmtDev_	tagPRTripOvlDev;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_MCSampleState_	{
	PR_MCSAMPLESTATE_FSTATENO=0,
	PR_MCSAMPLESTATE_CUTLOAD,
	PR_MCSAMPLESTATE_MSTATE,
};
struct	_PR_MCSampleState_	{
	int				nFStateNo;
	unsigned char	bCutLoad;
	unsigned char	bMState;
}	DISALIGN;
typedef	struct	_PR_MCSampleState_	tagPRMCSampleState;

// //////////////////////////////////////////////////////////////////////////
// enum	_PREnum_Field_MCSampleMSout_	{
// 	PR_MCSAMPLEMSOUT_MCSSTATE=0,
// 	PR_MCSAMPLEMSOUT_DEVTYPE,
// 	PR_MCSAMPLEMSOUT_DEVSERIALNO,
// 	PR_MCSAMPLEMSOUT_MSOUT,
// };
// struct	_PR_MCSampleMSout_	{
// 	int				nMCSampleState;
// 	unsigned char	nDevType;
// 	int				nDevIndex;
// 	double			fMSout;
// }	DISALIGN;
// typedef	struct	_PR_MCSampleMSout_	tagPRMCSampleMSout;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_FState_	{
	PR_FSTATE_ID=0,
	PR_FSTATE_SAMPLETYPE,
	PR_FSTATE_FDEVNUM,
	PR_FSTATE_PROBABILITY,
	PR_FSTATE_DURITION,
	PR_FSTATE_STATENUM,
	PR_FSTATE_FLOSSGEN,
	PR_FSTATE_FLOSSGENCAP,
	PR_FSTATE_FLOSSLOAD,
	PR_FSTATE_MISLAND,
	PR_FSTATE_MIINSGEN,
	PR_FSTATE_MICUTGEN,
	PR_FSTATE_MICUTLOAD,
	PR_FSTATE_AGCINSGEN,
	PR_FSTATE_AGCCUTGEN,
	PR_FSTATE_AGCCUTLOAD,
	PR_FSTATE_OVERLIMIT,
	PR_FSTATE_ELIMIT,
	PR_FSTATE_ELCUTGEN,
	PR_FSTATE_ELINSGEN,
	PR_FSTATE_ELCUTLOAD,
	PR_FSTATE_ELRESULT,
	PR_FSTATE_MAXFAULTZONE,
	PR_FSTATE_MAXFAULTRATIO,
	PR_FSTATE_FAULTGRADE,
	PR_FSTATE_MSOUTSERIALNO,
	PR_FSTATE_ESTIMATED,
	PR_FSTATE_ELAPSETIME,
};
struct	_PR_FState_	{
	int				nFStateId;
	unsigned char	nSampleType;
	unsigned char	nFDevNum;
	double			fStateProb;
	double			fStateDur;
	int				nStateNum;

	float			fFLossGen;
	float			fFLossGenCap;
	float			fFLossLoad;

	unsigned char	bMIsland;
	float			fMIInsGen;
	float			fMICutGen;
	float			fMIOutLoad;

	float			fAgcInsGen;
	float			fAgcCutGen;
	float			fEnsCutLoad;

	unsigned char	bOverLimit;
	unsigned char	bELCutLoad;
	float			fELCutGen;
	float			fELInsGen;
	float			fELCutLoad;
	unsigned char	nELResult;

	unsigned char	nMaxFaultZone;
	float			fMaxFaultRatio;
	unsigned char	nFaultGrade;
	short			nMSoutIndex;

	unsigned char	bEstimated;
	float			fElapseTime;
}	DISALIGN;
typedef	struct	_PR_FState_	tagPRFState;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_FDevice_	{
	PR_FSTATEFDEV_FSTATEID=0,
	PR_FSTATEFDEV_FSTATENO,
	PR_FSTATEFDEV_FDEVTYP,
	PR_FSTATEFDEV_FDEVIDX,
	PR_FSTATEFDEV_DFLTPOS,
	PR_FSTATEFDEV_DFLTTYP,
	//PR_FSTATEFDEV_FLAG,
};
struct	_PR_FStateFDev_	{
	int				nFStateId;
	int				nFStateNo;
	unsigned char	nFDevTyp;
	int				nFDevIdx;
	unsigned char	nDFltPos;
	unsigned char	nDFltTyp;
	//unsigned char	bFlag;
}	DISALIGN;
typedef	struct	_PR_FStateFDev_	tagPRFStateFDev;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_FStateMState_	{
	PR_FSTATEMSTATE_MSDEVTYPE=0,
	PR_FSTATEMSTATE_MSDEVIDX,
	PR_FSTATEMSTATE_MSTATEPOUT,
};
struct	_PR_FStateMState_	{
	unsigned char	nMSDevType;
	int				nMSDevIdx;
	double			fStatePout;
}	DISALIGN;
typedef	struct	_PR_FStateMState_	tagPRFStateMState;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_FStateMIsland_	{
	PR_FSTATEMISLAND_FSTATEID=0,
	PR_FSTATEMISLAND_FSTATENO,
	PR_FSTATEMISLAND_OUTAGEBUS,
	PR_FSTATEMISLAND_OUTAGELOADP,
};
struct	_PR_FStateMIsland_	{
	int				nFStateId;
	int				nFStateNo;
	int				nOutageBus;
	float			fOutageLoadP;
}	DISALIGN;
typedef	struct	_PR_FStateMIsland_	tagPRFStateMIsland;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_FStateOvLmtDev_	{
	PR_FSTATEOVLDEV_FSTATEID=0,
	PR_FSTATEOVLDEV_FSTATENO,
	PR_FSTATEOVLDEV_DEVTYP,
	PR_FSTATEOVLDEV_DEVIDX,
	PR_FSTATEOVLDEV_OVLMTP,
	PR_FSTATEOVLDEV_RATED,
	PR_FSTATEOVLDEV_ADLMTP,
};
struct	_PR_FStateOvLmtDev_	{
	int				nFStateId;
	int				nFStateNo;
	unsigned char	nDevTyp;
	int				nDevIdx;
	float			fOvLmtP;
	float			fRated;
	float			fAdLmtP;
}	DISALIGN;
typedef	struct	_PR_FStateOvLmtDev_	tagPRFStateOvlDev;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_FStateOvLmtAd_	{
	PR_FSTATEOVLAD_FSTATEID=0,
	PR_FSTATEOVLAD_FSTATENO,
	PR_FSTATEOVLAD_OVLDEVTYP,
	PR_FSTATEOVLAD_OVLDEVICE,
	PR_FSTATEOVLAD_ADJDEVTYP,
	PR_FSTATEOVLAD_ADJDEVICE,
	PR_FSTATEOVLAD_ADJVALUE,
};

struct	_PR_FStateOvLmtAd_	{
	int				nFStateId;
	int				nFStateNo;
	unsigned char	nOvlDevTyp;
	int				nOvlDevIdx;
	unsigned char	nAdjDevTyp;
	int				nAdjDevIdx;
	float			fAdValue;
}	DISALIGN;
typedef	struct	_PR_FStateOvLmtAd_	tagPRFStateOvlAd;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_AdsNode_	{
	PR_ADSNODE_ID=0,
	PR_ADSNODE_NAME,
	PR_ADSNODE_STATUS,
	PR_ADSNODE_TASKCOUNT,
};

struct	_PR_AdsNode_	{
	int				nId;
	char			szName[MDB_CHARLEN];
	unsigned char	nStatus;
	int				nTaskCount;
}	DISALIGN;
typedef	struct	_PR_AdsNode_	tagPRAdsNode;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CalcJobTypeType_	{
	PR_CALCJOBTYPE_ID=0,
	PR_CALCJOBTYPE_NAME,
	PR_CALCJOBTYPE_DESP,
	PR_CALCJOBTYPE_NODEID,
};

struct	_PR_CalcJobType_	{
	int				nId;
	char			szName[MDB_CHARLEN];
	char			szDesp[MDB_CHARLEN];
	int				nNodeId;
}	DISALIGN;
typedef	struct	_PR_CalcJobType_	tagPRCalcJobType;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CalcJob_	{
	PR_CALCJOB_ID=0,
	PR_CALCJOB_TYPEID,
	PR_CALCJOB_NAME,
	PR_CALCJOB_DESP,
	PR_CALCJOB_CONFIG,
	PR_CALCJOB_INITIME,
	PR_CALCJOB_ENDTIME,
	PR_CALCJOB_ELAPSETIME,
};

struct	_PR_CalcJob_	{
	int				nId;
	int				nTypeId;
	char			szName[MDB_CHARLEN];
	char			szDesp[MDB_CHARLEN];
	char			szConfig[MDB_CHARLEN];
	int				nIniTime;
	int				nEndTime;
	float			fElapseTime;
}	DISALIGN;
typedef	struct	_PR_CalcJob_	tagPRCalcJob;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CalcTask_	{
	PR_CALCTASK_ID=0,
	PR_CALCTASK_JOBID,
	PR_CALCTASK_CONTENT,
	PR_CALCTASK_INITIME,
	PR_CALCTASK_ENDTIME,
	PR_CALCTASK_ELAPSETIME,
};

struct	_PR_CalcTask_	{
	int				nId;
	int				nJobId;
	char			szContent[MDB_CHARLEN];
	int				nIniTime;
	int				nEndTime;
	float			fElapseTime;
}	DISALIGN;
typedef	struct	_PR_CalcTask_	tagPRCalcTask;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CalcFile_	{
	PR_CALCFILE_JOBID=0,
	PR_CALCFILE_NAME,
	PR_CALCFILE_TYPE,
	PR_CALCFILE_CONTENT,
};

struct	_PR_CalcFile_	{
	int				nTypeId;
	char			szName[MDB_CHARLEN];
	char			szType[MDB_CHARLEN_SHORTEST];
	char			szContent[MDB_CHARLEN];
}	DISALIGN;
typedef	struct	_PR_CalcFile_	tagPRCalcFile;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_FSecurity_	{
	PR_FSECURITY_FSTATEID=0,
	PR_FSECURITY_FSTATENO,
	PR_FSECURITY_LTFAULT,
	PR_FSECURITY_MISLAND,
	PR_FSECURITY_LOSSGENP,
	PR_FSECURITY_BSEFILE,
	PR_FSECURITY_SWIFILE,
	PR_FSECURITY_OUTFILE,
	PR_FSECURITY_RESULT,
	PR_FSECURITY_ESTIMATED,
};

struct	_PR_FSecurity_	{
	int				nFStateId;
	int				nFStateNo;
	unsigned char	nLTFault;
	unsigned char	bMIsland;
	float			fLossGenP;
	char			szBseFile[MDB_CHARLEN_LONG];
	char			szSwiFile[MDB_CHARLEN_LONG];
	char			szOutFile[MDB_CHARLEN_LONG];
	unsigned char	nSaResult;
	unsigned char	bEstimated;
}	DISALIGN;
typedef	struct	_PR_FSecurity_	tagPRFSecurity;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CopGen_	{
	PR_COPGEN_SERIALNO=0,
	PR_COPGEN_CAPACITY,
	PR_COPGEN_ALPHA,
	PR_COPGEN_S1CAPACITY,
	PR_COPGEN_S2CAPACITY,
	PR_COPGEN_RERR,
	PR_COPGEN_TREP,
	PR_COPGEN_RREP,
	PR_COPGEN_ROUT,
	PR_COPGEN_3STATE,
};

struct	_PR_CopGen_	{
	int				nGenIndex;
	double			fCapacity;
	double			fAlpha;
	double			fCapL;
	double			fCapH;
	double			fRerr;
	double			fTrep;
	double			fRrep;
	double			fRout;
	unsigned char	b3State;
}	DISALIGN;
typedef	struct	_PR_CopGen_	tagPRCopGen;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Field_CopTable_	{
	PR_COPTABLE_STATE=0,
	PR_COPTABLE_OUTAGECAPACITY,
	PR_COPTABLE_AVAILCAPACITY,
	PR_COPTABLE_STATEPROB,
	PR_COPTABLE_ACCUMPROB,
	PR_COPTABLE_STATEFREQ,
	PR_COPTABLE_ACCUMFREQ,
	PR_COPTABLE_DEPRP,
	PR_COPTABLE_DEPRN,
};
struct	_PR_CopTable_	{
	int				nState;
	double			fOutageCapacity;
	double			fAvailCapacity;
	double			fStateProb;
	double			fAccumProb;
	double			fStateFreq;
	double			fAccumFreq;
	double			fDepRP;
	double			fDepRN;
}	DISALIGN;
typedef	struct	_PR_CopTable_	tagPRCopTable;

//////////////////////////////////////////////////////////////////////////
enum	_PREnum_Table_	{
	PR_SYSTEM=0,
	PR_ZONE,
	PR_RADIAL,
	PR_ACBUS,
	PR_ACLINE,
	PR_WIND,
	PR_GENERATOR,
	PR_POWERLOAD,
	PR_HVDC,
	PR_CONVERTER,
	PR_DCBUS,
	PR_DCLINE,
	PR_TCSC,
	PR_UPFC,
	PR_DEVMSTATE,
	PR_ACISLAND,
	PR_ACLINEEDGE,
	PR_WINDEDGE,
	//PR_LOADCURVE,

	PR_TRIP,
	PR_TRIPMISLAND,
	PR_TRIPOVLDEV,

	PR_COMMRPARAM,
	PR_MANUALFAULT,
	PR_COMMONFAULT,
	PR_R2STATECOMP,
	PR_RMSTATECOMP,
	//PR_MCSAMPLESTATE,
	PR_FSTATE,
	PR_FSTATEFDEV,
	PR_FSTATEMSTATE,
	PR_FSTATEMISLAND,
	PR_FSTATEOVLDEV,
	PR_FSTATEOVLAD,
	PR_ADSNODE,
	PR_CALCJOBTYPE,
	PR_CALCJOB,
	PR_CALCTASK,
	PR_CALCFILE,
	PR_FSECURITY,
	PR_COPGEN,
	PR_COPTABLE,
};

//////////////////////////////////////////////////////////////////////////
//	数据库表相关定义

const int	PR_MaxSystem		=1;
const int	PR_MaxZone			=200;
const int	PR_MaxRadial		=5000;
const int	PR_MaxACBus			=50000;
const int	PR_MaxACLine		=32000;
const int	PR_MaxWind			=48000;
const int	PR_MaxDCBus			=200;
const int	PR_MaxDCLine		=PR_MaxDCBus/2;
const int	PR_MaxConverter		=PR_MaxDCBus;
const int	PR_MaxHVDC			=200;
const int	PR_MaxTCSC			=20;
const int	PR_MaxUPFC			=20;
const int	PR_MaxGenerator		=4800;
const int	PR_MaxPowerLoad		=10000;
const int	PR_MaxDevMState		=8*(PR_MaxHVDC+PR_MaxGenerator/20+PR_MaxPowerLoad/100);
const int	PR_MaxACIsland		=2500;
const int	PR_MaxACLineEdge	=2*PR_MaxACLine;
const int	PR_MaxWindEdge		=2*PR_MaxWind;

const int	PR_MaxLoadCurve		=PR_MaxPowerLoad*365/10;

//	因为下面三个表暂时无用，所以不设置容量
//const int	PR_MaxTrip			=64000;
const int	PR_MaxTrip			=2;

const int	PR_MaxTripMIsland	=10*PR_MaxTrip;
const int	PR_MaxTripOvlDev	=10*PR_MaxTrip;

const int	PR_MaxCommRParam	=200;
const int	PR_MaxManualFault	=1000;
const int	PR_MaxCommonFault	=1000;
const int	PR_MaxR2StateComp	=(PR_MaxGenerator+PR_MaxACLine+PR_MaxWind+PR_MaxConverter);
const int	PR_MaxRMStateComp	=(PR_MaxHVDC+PR_MaxGenerator/20+PR_MaxPowerLoad/100);

const int	PR_MaxFState		=800000;
const int	PR_MaxFStateFDev	=5*PR_MaxFState;
const int	PR_MaxFStateMState	=10*PR_MaxRMStateComp;
const int	PR_MaxFStateMIsland	=PR_MaxFState/50;
const int	PR_MaxFStateOvlDev	=PR_MaxFState/2;
const int	PR_MaxFStateOvlAd	=PR_MaxFState;

const int	PR_MaxAdsNode		=200;
const int	PR_MaxCalcJobType	=20;
const int	PR_MaxCalcJob		=10*PR_MaxAdsNode;
const int	PR_MaxCalcTask		=PR_MaxFState/2;
const int	PR_MaxCalcFile		=3*PR_MaxCalcJobType;

const int	PR_MaxFSecurity		=10000;
const int	PR_MaxCopGen		=PR_MaxGenerator;
const int	PR_MaxCopTable		=10*PR_MaxGenerator;

const int	PRSystem_Offset			=(sizeof(tagMDBBlockSummy)+sizeof(int)*MAXMDBTABLENUM);
const int	PRZone_Offset			=(PRSystem_Offset		+PR_MaxSystem		*sizeof(tagPRSystem));
const int	PRRadial_Offset			=(PRZone_Offset			+PR_MaxZone			*sizeof(tagPRZone));
const int	PRACBus_Offset			=(PRRadial_Offset		+PR_MaxRadial		*sizeof(tagPRRadial));
const int	PRACLine_Offset			=(PRACBus_Offset		+PR_MaxACBus		*sizeof(tagPRACBus));
const int	PRWind_Offset			=(PRACLine_Offset		+PR_MaxACLine		*sizeof(tagPRACLine));
const int	PRGenerator_Offset		=(PRWind_Offset			+PR_MaxWind			*sizeof(tagPRWind));
const int	PRPowerLoad_Offset		=(PRGenerator_Offset	+PR_MaxGenerator	*sizeof(tagPRGenerator));
const int	PRHVDC_Offset			=(PRPowerLoad_Offset	+PR_MaxPowerLoad	*sizeof(tagPRPowerLoad));
const int	PRConverter_Offset		=(PRHVDC_Offset			+PR_MaxHVDC			*sizeof(tagPRHVDC));
const int	PRDCBus_Offset			=(PRConverter_Offset	+PR_MaxConverter	*sizeof(tagPRConverter));
const int	PRDCLine_Offset			=(PRDCBus_Offset		+PR_MaxDCBus		*sizeof(tagPRDCBus));
const int	PRTCSC_Offset			=(PRDCLine_Offset		+PR_MaxDCLine		*sizeof(tagPRDCLine));
const int	PRUPFC_Offset			=(PRTCSC_Offset			+PR_MaxTCSC			*sizeof(tagPRTCSC));
const int	PRDevMState_Offset		=(PRUPFC_Offset			+PR_MaxUPFC			*sizeof(tagPRUPFC));
const int	PRACIsland_Offset		=(PRDevMState_Offset	+PR_MaxDevMState	*sizeof(tagPRDevMState));
const int	PRACLineEdge_Offset		=(PRACIsland_Offset		+PR_MaxACIsland		*sizeof(tagPRACIsland));
const int	PRWindEdge_Offset		=(PRACLineEdge_Offset	+PR_MaxACLineEdge	*sizeof(tagPRACLineEdge));

const int	PRTrip_Offset			=(PRWindEdge_Offset		+PR_MaxWindEdge		*sizeof(tagPRWindEdge));
const int	PRTripMIsland_Offset	=(PRTrip_Offset			+PR_MaxTrip			*sizeof(tagPRTrip));
const int	PRTripOvlDev_Offset		=(PRTripMIsland_Offset	+PR_MaxTripMIsland	*sizeof(tagPRTripMIsland));

const int	PRCommRParam_Offset		=(PRTripOvlDev_Offset	+PR_MaxTripOvlDev	*sizeof(tagPRTripOvlDev));
const int	PRManualFault_Offset	=(PRCommRParam_Offset	+PR_MaxCommRParam	*sizeof(tagPRCommRParam));
const int	PRCommonFault_Offset	=(PRManualFault_Offset	+PR_MaxManualFault	*sizeof(tagPRManualFault));
const int	PR2StateComp_Offset		=(PRCommonFault_Offset	+PR_MaxCommonFault	*sizeof(tagPRCommonFault));
const int	PRMStateComp_Offset		=(PR2StateComp_Offset	+PR_MaxR2StateComp	*sizeof(tagPR2StateComp));

const int	PRFState_Offset			=(PRMStateComp_Offset	+PR_MaxRMStateComp	*sizeof(tagPRMStateComp));
const int	PRFStateFDev_Offset		=(PRFState_Offset		+PR_MaxFState		*sizeof(tagPRFState));
const int	PRFStateMState_Offset	=(PRFStateFDev_Offset	+PR_MaxFStateFDev	*sizeof(tagPRFStateFDev));
const int	PRFStateMIsland_Offset	=(PRFStateMState_Offset	+PR_MaxFStateMState	*sizeof(tagPRFStateMState));
const int	PRFStateOvlDev_Offset	=(PRFStateMIsland_Offset+PR_MaxFStateMIsland*sizeof(tagPRFStateMIsland));
const int	PRFStateOvlAd_Offset	=(PRFStateOvlDev_Offset	+PR_MaxFStateOvlDev	*sizeof(tagPRFStateOvlDev));

const int	PRAdsNode_Offset		=(PRFStateOvlAd_Offset	+PR_MaxFStateOvlAd	*sizeof(tagPRFStateOvlAd));
const int	PRCalcJobType_Offset	=(PRAdsNode_Offset		+PR_MaxAdsNode		*sizeof(tagPRAdsNode));
const int	PRCalcJob_Offset		=(PRCalcJobType_Offset	+PR_MaxCalcJobType	*sizeof(tagPRCalcJobType));
const int	PRCalcTask_Offset		=(PRCalcJob_Offset		+PR_MaxCalcJob		*sizeof(tagPRCalcJob));
const int	PRCalcFile_Offset		=(PRCalcTask_Offset		+PR_MaxCalcTask		*sizeof(tagPRCalcTask));

const int	PRFSecurity_Offset		=(PRCalcFile_Offset		+PR_MaxCalcFile		*sizeof(tagPRCalcFile));
const int	PRCopGen_Offset			=(PRFSecurity_Offset	+PR_MaxFSecurity	*sizeof(tagPRFSecurity));
const int	PRCopTable_Offset		=(PRCopGen_Offset		+PR_MaxCopGen		*sizeof(tagPRCopGen));

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
