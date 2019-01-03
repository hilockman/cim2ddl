#pragma	once

#include "../include/MDBDefine.h"

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

const	int		BpaDatCategory_Dat=0;	//	BPA����������������
const	int		BpaDatCategory_Con=2;	//	BPA����������������
const	int		BpaSwiCategory_Dat=1;	//	BPA�ȶ�������������
const	int		BpaSwiCategory_Con=3;	//	BPA�ȶ�������������

//	���ݿ����ֶ�ö��ֵ����
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

//	���ݿ��ֶ���ض���
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
	char		szCaseID[MDB_CHARLEN];				//	������ʽ��
	char		szProject[MDB_CHARLEN];				//	������
	float		fMVABase;							//	ָ����ϵͳ��׼����
	char		szControl[MDB_CHARLEN];				//	��ָ���Ŀ�������ļ�
	char		szBranch[MDB_CHARLEN];				//	��ָ����֧·����
	char		szBus[MDB_CHARLEN]; 				//	��ָ����ĸ������
	char		szNetwork[MDB_CHARLEN]; 			//	��ָ���������ļ�
	short		nRXCheck;							//	RX��ֵ���
	char		szNewBase[MDB_CHARLEN]; 			//	��������������ļ���.BSE��
	char		szOldBase[MDB_CHARLEN]; 			//	ָ���Ͽ��ļ�
	char		szMap[MDB_CHARLEN]; 				//	���ɳ���ͼ�����ƽ���ļ�
	unsigned char	nAIControl;						//	���������߹��ʿ���ѡ��
	unsigned char	nLTC;							//	�����ɵ�ѹ��ѹ������ѡ��
	short		nDecoupledNum;						//	PQ���
	short		nCurrentNum;						//	�Ľ���ţ������ѷ�㷨
	short		nNewtonNum;							//	ţ������ѷ�㷨
	short		nOptimNum;							//	���ų�����
	float		fToleranceBusV;						//	BusV������ȱʡֵ��0.005
	float		fToleranceAIPower;					//	AIPower������ȱʡֵ��0.005
	float		fToleranceTX;						//	TX������ȱʡֵ��0.005
	float		fToleranceQ;						//	Q������ȱʡֵ��0.005
	float		fToleranceOpcut;					//	OPCUT������ȱʡֵ��0.0001
// 	short		nInputList;							//	�����ԭʼ�������
 	short		nRptSort;							//	������࣬���˳��������
 	short		nAnalysisRpt;						//	�������������ָ������ȼ�
// 	short		nAIListControl;						//	�����ʽ����������
// 	short		nLineLoss;							//	��·������
// 	short		nTransformerLoss;					//	��ѹ��֧·������
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
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
	char		szName[MDB_CHARLEN_SHORTEST/2];			//	��������
	char		szArea[MDB_CHARLEN_SHORTER];			//	��������
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	float		fKG0;									//	51	55	F5.4	��·����絼���������絼�ı���
	float		fKB0;									//	56	60	F5.4	��·������������������ɵı���
	float		fKGC0;									//	61	65	F5.4	��·�Ե�֧·����絼����ڶԵ�֧·����絼�ı���
	float		fKBC0;									//	66	70	F5.4	��·�Ե�֧·�����������ڶԵ�֧·������ɵı���
	float		fVMIN;									//	71	75	F5.1	��ѹ�ȼ�������Сֵ
	float		fVMAX;									//	76	80	F5.1	��ѹ�ȼ��������ֵ

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
	char	szName[MDB_CHARLEN_SHORTER];		//	��վ����
//	char	szDesp[MDB_CHARLEN];			//	��վ����
//	char	szZone[MDB_CHARLEN_SHORTER];	//	��վ����
	char	szAlias[MDB_CHARLEN_SHORT];		//	������վ
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
	BPA_DAT_ACBUS_INIADDPLOAD,
	BPA_DAT_ACBUS_INIADDQLOAD,
	BPA_DAT_ACBUS_INIADDPSHUNT,
	BPA_DAT_ACBUS_INIADDQSHUNT,
	BPA_DAT_ACBUS_INIADDPGEN,
	BPA_DAT_ACBUS_INIADDQGEN,

	BPA_DAT_ACBUS_TMID,
	BPA_DAT_ACBUS_GENERATOR,
	BPA_DAT_ACBUS_WTGEN,
	BPA_DAT_ACBUS_PVGEN,
	BPA_DAT_ACBUS_DCBOUND,
	BPA_DAT_ACBUS_GENLN,
	BPA_DAT_ACBUS_STATUS,
	BPA_DAT_ACBUS_REDUCTION,
	BPA_DAT_ACBUS_INRING,
	BPA_DAT_ACBUS_RADIATE,

	BPA_DAT_ACBUS_ACISLAND,
	BPA_DAT_ACBUS_PRLINE,
	BPA_DAT_ACBUS_PRTRAN,
	BPA_DAT_ACBUS_PRHG,
	BPA_DAT_ACBUS_PRSUB,
};

struct	_BpaMDBDat_ACBus_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];	//1		2	A1	������
	//char	cChgCode;							//3		3	A1	�޸���
	char	szOwner[MDB_CHARLEN_SHORTEST/2];	//4		6	A3	������
	char	szName[MDB_CHARLEN_BPABUS];			//7		14	A8	ĸ������
	float	fkV;								//15	18	F4.0��׼��ѹ(kV)
	char	szZone[MDB_CHARLEN_SHORTEST/2];		//19	20	A2		Zone��������
	float	fLoadP;								//21	25	F5.0�㶨�й�����(MW)
	float	fLoadQ;								//26	30	F5.0�㶨�޹�����(MVAR)��+��ʾ����
	float	fShuntP;							//31	34	F4.0���������й�����(MW)
	float	fShuntQ;							//35	38	F4.0���������޹�����(MVAR)��+������
	float	fPmax;								//39	42	F4.0����й�����Pmax(MW)
	float	fPGen;								//43	47	F5.0ʵ���й�����PGen(MW)
	float	fQsched_Qmax;						//48	52	F5.0���ŵ��޹�����ֵ��+������
	float	fQmin;								//53	57	F5.0�޹�������Сֵ(MVAR)���˴���0
	float	fVHold_max;							//58	61	F4.3���ŵĵ�ѹֵ��Vmax(��ôֵ)
	float	fVmin;								//62	65	F4.3���ŵ�Vmin(��ôֵ)
	char	szRBusName[MDB_CHARLEN_BPABUS];		//66	73	A8	Զ��Ҫ���Ƶ�ĸ������
	float	fRBusVolt;							//74	77	F4.0Զ��Ҫ���ƵĻ�׼��ѹ(kV)
	float	fVarSppld;							//78	80	F3.0�ṩ���޹����ʰٷ���(%)

	char	szAddCode[MDB_CHARLEN_SHORTEST/2];
	float	fAddLoadP;
	float	fAddLoadQ;
	float	fAddShuntP;
	float	fAddShuntQ;
	float	fAddPGen;
	float	fAddQGen;

	char	szBpaSub[MDB_CHARLEN_SHORTER];
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
	float	fIniAddLoadP;
	float	fIniAddLoadQ;
	float	fIniAddShuntP;
	float	fIniAddShuntQ;
	float	fIniAddPGen;
	float	fIniAddQGen;

	unsigned char	bTMid;
	unsigned char	bGenerator;
	unsigned char	bWTGen;
	unsigned char	bPVGen;
	unsigned char	bDCBound;
	unsigned char	bGenLn;
	unsigned char	nStatus;
	unsigned char	bReduction;
	unsigned char	bInRing;
	short			nRadiate;

	short	nACIsland;
	int		nEdgeACLineRange;
	int		nEdgeWindRange;
	short	nEdgeLineHGRange;
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
	//char			cChgCode;						//	3	3	A1		�޸���
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3		������
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float			fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char			cMeter;							//	19	19	I1		���������߲���־
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float			fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char			cLoop;							//	32	32	A1		������·�Ļ�·��־
	unsigned char	bSection;						//	33	33	I1		�ֶδ������ɵ���·�Ķκ�
	float			fAMP;							//	34	37	F4.0	��·�����(����)
	unsigned char	bLoopNum;						//	38	38	I1		������·��Ŀ
	float			fR;								//	39	44	F6.5	�����ôֵ
	float			fX;								//	45	50	F6.5	�翹��ôֵ
	float			fG1;							//	51	56	F6.5	��·ĸ��1�˶Եص絼��ôֵ(G/2)
	float			fB1;							//	57	62	F6.5	��·ĸ��1�˶Եص��ɱ�ôֵ(B/2)
	float			fG2;							//	63	68	F6.5	��·ĸ��2�˶Եص絼��ôֵ(G/2)
	float			fB2;							//	69	74	F6.5	��·ĸ��2�˶Եص��ɱ�ôֵ(B/2)
	float			fMiles;							//	63	66	F4.1	��·��εĳ���
	//char			szComment[MDB_CHARLEN_SHORTER];	//	67	74	A8		��·��˵������

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
	char	szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float	fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char	szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float	fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char	cLoop;							//	32	32	A1		������·�Ļ�·��־
	float	fShuntI;						//	63	68	F5.0	��·ǰ��߿�����(Mvar������ֵ)
	float	fShuntJ;						//	69	74	F5.0	��·���߿�����(Mvar������ֵ)
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
	BPA_DAT_WIND_TRANPTR,
	BPA_DAT_WIND_INRING,
	BPA_DAT_WIND_RADIATE,
};

struct	_BpaMDBDat_Wind_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2		CARD TYPE
	//char			cChgCode;						//	3	3	A1		�޸���
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3		������
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float			fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char			cMeter;							//	19	19	I1		���������߲���־
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float			fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char			cLoop;							//	32	32	A1		������·�Ļ�·��־
	unsigned char	bSection;						//	33	33	I1		�ֶδ������ɵ���·�Ķκ�
	float			fMVA;							//	34	37	F4.0	��ѹ�������(MVA)
	unsigned char	bLoopNum;						//	38	38	I1		������ѹ����Ŀ
	float			fR;								//	39	44	F6.5	��ͭ������ĵ�Ч����(��ôֵ)
	float			fX;								//	45	50	F6.5	©��(��ôֵ)
	float			fG;								//	51	56	F6.5	����������ĵ�Ч�絼(��ôֵ)
	float			fB;								//	57	62	F6.5	���ŵ���(��ôֵ)
	float			fTPI;							//	63	67	F5.2	ĸ��1�Ĺ̶��ֽ�ͷ/�������Ĺ̶������(��)
	float			fTPJ;							//	68	72	F5.2	ĸ��2�Ĺ̶��ֽ�ͷ

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
	int				nTran;
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
	//char			cChgCode;						//	3	3	A1		�޸���
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3		������
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float			fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	unsigned char	bVarTap;						//	19	19	I1		�ɵ���ͷ�˱�־
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float			fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char			szBusC[MDB_CHARLEN_BPABUS];		//	34	41	A8		����ĸ������
	float			fkVC;							//	42	45	F4.0	���ػ�׼��ѹ(kV)
	float			fTMax;							//	46	50	F5.2	����ͷλ��(kV)
	float			fTMin;							//	51	55	F5.2	��С��ͷλ��(kV)
	short			nTNum;							//	56	57	I2		LTC��ͷ����
	float			fValMax;						//	58	62	F5.0	ָ��������޹�����(Mvar)
	float			fValMin;						//	63	67	F5.0	ָ������С�޹�����(Mvar)

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
	BPA_DAT_DCBUS_PRLINE,
	BPA_DAT_DCBUS_PRTRAN,
	BPA_DAT_DCBUS_ACISLAND,
	BPA_DAT_DCBUS_SUB,
	BPA_DAT_DCBUS_ALIAS,
	BPA_DAT_DCBUS_STATUS,
};

struct	_BpaMDBDat_DCBus_	{
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	CARDTYPE
	//char			cChgCode;						//	3	3	A1	�޸���
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	4	A3	������
	char			szName[MDB_CHARLEN_BPABUS];		//	7	7	A8	Converterĸ������
	float			fkV;							//	15	15	F4.0	Converter��׼��ѹ(kV)
	char			szZone[MDB_CHARLEN_SHORTEST/2];		//	19	19	A2	Zone��������
	short			nBRDGS;							//	24	24	I2	������·������
	float			fSMTHGREACTOR;					//	26	26	F5.1	ƽ���翹�����(����)
	float			fROPERMIN;						//	31	31	F5.1	��Ϊ���������е���С������(��)
	float			fIOPERSTOP;						//	36	36	F5.1	��Ϊ��������е���󴥷���(��)
	float			fDROP;							//	41	41	F5.1	ÿ���ŷ��ĵ�ѹ��(��)
	float			fBRDGRATE;						//	46	46	F5.1	�ŵ����ֵ(����)
	char			szACName[MDB_CHARLEN_BPABUS];		//	51	51	A8	������ѹ��һ�β�ĸ������
	float			fACkV;							//	59	59	F4.0	������ѹ��һ�β��׼��ѹ(kV)

	float			fDCV;
	float			fDCD;
	float			fDCP;
	float			fDCI;
	float			fLossP;
	float			fLossQ;
	float			fACV;
	float			fAngle;

	int				nACBus;
	int				nEdgeDCLineRange;
	int				nEdgeRRange;
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
	BPA_DAT_DCLINE_MILES,

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
	//char			cChgCode;						//	3	3	A1	�޸���
	char			szOwner[MDB_CHARLEN_SHORTEST/2];	//	4	6	A3	������
	char			szBusR[MDB_CHARLEN_BPABUS];		//	7	14	A8	������ĸ������
	float			fkVR;							//	15	18	F4.0	�������׼��ѹ(kV)
	unsigned char	bMeter;							//	19	19	I1	���������߲���־
	char			szBusI[MDB_CHARLEN_BPABUS];		//	20	27	A8	����ĸ������
	float			fkVI;							//	28	31	F4.0	�����׼��ѹ(kV)
	float			fAMP;							//	34	37	F4.0	ֱ����·�����(����)
	float			fR;								//	38	43	F6.2	ֱ����·����(ŷķ)
	float			fL;								//	44	49	F6.2	ֱ����·���(����)
	float			fC;								//	50	55	F6.2	ֱ����·����(΢��)
	char			cControl;						//	56	56	A1	�����ŵ�ֱ�����ʵĿ��Ƶ�
	float			fDCPOWER;						//	57	61	F5.1	�����ŵ�ֱ������(MW)
	float			fRVOLT;							//	62	66	F5.1	����ֱ����·�������ֱ����ѹ(kV)
	float			fROPER;							//	67	70	F4.1	�����������������(��)
	float			fISTOP;							//	71	74	F4.1	����������ضϽ�(��)
	float			fLength;						//	75	78	F4.0	��·����

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
	//char			cChgCode;						//	3	3	A1	�޸���
	char			szOwner[MDB_CHARLEN_SHORTEST/2];		//	4	6	A3	������
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float			fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float			fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char			cLoop;							//	32	32	A1		������·�Ļ�·��־
	unsigned char	bSection;						//	33	33	I1		�ֶδ������ɵ���·�Ķκ�
	char			cMode;							//	34	34	A1		���Ʒ�ʽ
	float			fPcmax;							//	35	39	F5.0	��·�й��������ֵ(MW)
	float			fPcmin;							//	40	44	F5.0	��·�й�������Сֵ(MW)
	float			fIn;							//	45	48	F4.0	��·�����ֵ(����)
	float			fXijmax;						//	49	54	F6.5	��·�翹����ôֵ
	float			fXijmin;						//	55	60	F6.5	��·�翹��С��ôֵ
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
	BPA_DAT_P_INILOADPFACTOR,
	BPA_DAT_P_INILOADQFACTOR,
	BPA_DAT_P_INIGENPFACTOR,
	BPA_DAT_P_INIGENQFACTOR,
	BPA_DAT_P_STATUS,
};

struct	_BpaMDBDat_P_	{
	char	szCardKey[MDB_CHARLEN_SHORTEST];			//	1	2	A2	CARD TYPE
	char	szZone[MDB_CHARLEN_SHORTEST/2];				//	4	6	A3	�����ߴ���
	float	fLoadPFactor;							//	10	14	F5.0	�����й��޸�����
	float	fLoadQFactor;							//	16	20	F5.0	�����޹��޸�����
	float	fGenPFactor;							//	22	26	F5.0	��������й��޸�����
	float	fGenQFactor;							//	28	32	F5.0	��������޹��޸�����

	float	fIniLoadPFactor;
	float	fIniLoadQFactor;
	float	fIniGenPFactor;
	float	fIniGenQFactor;

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
	BPA_DAT_ZIL_KEYNAME,
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
	char	szKeyName[MDB_CHARLEN_SHORT];
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
	BPA_DAT_GEN_WTGEN,
	BPA_DAT_GEN_PVGEN,
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
	unsigned char	bWTGen;
	unsigned char	bPVGen;
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
	BPA_DAT_TRAN_STATUS,
};
struct	_BpaMDBDat_Tran_	{
	unsigned char	nWindNum;
	char	szWindH[MDB_CHARLEN_SHORT];
	char	szWindM[MDB_CHARLEN_SHORT];
	char	szWindL[MDB_CHARLEN_SHORT];
	int		iRWindH;
	int		iRWindM;
	int		iRWindL;
	unsigned char	nStatus;
}	DISALIGN;
typedef	struct	_BpaMDBDat_Tran_	tagBpaDat_Tran;

enum _BpaMDBEnum_DatField_ACBus2Line_
{
	BPA_DAT_EDGEACLINE_ACBUSNAME=0,
	BPA_DAT_EDGEACLINE_ACBUSKV,
	BPA_DAT_EDGEACLINE_ACLINENAME,
	BPA_DAT_EDGEACLINE_ACLINEPTR,
};
struct	_BpaMDBDat_ACBus2Line_	{
	char	szACBusName[MDB_CHARLEN_BPABUS];
	float	fACBuskV;
	char	szACLineName[MDB_CHARLEN_SHORT];
	int		nACLinePtr;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACBus2Line_	tagBpaDat_EdgeACLine;

enum _BpaMDBEnum_DatField_ACBus2Wind_
{
	BPA_DAT_EDGEWIND_ACBUSNAME=0,
	BPA_DAT_EDGEWIND_ACBUSKV,
	BPA_DAT_EDGEWIND_WINDNAME,
	BPA_DAT_EDGEWIND_WINDPTR,
};
struct	_BpaMDBDat_ACBus2Wind_	{
	char	szACBusName[MDB_CHARLEN_BPABUS];
	float	fACBuskV;
	char	szWindName[MDB_CHARLEN_SHORT];
	int		nWindPtr;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACBus2Wind_	tagBpaDat_EdgeWind;

enum _BpaMDBEnum_DatField_ACBus2HG_
{
	BPA_DAT_EDGELINEHG_ACBUSNAME=0,
	BPA_DAT_EDGELINEHG_ACBUSKV,
	BPA_DAT_EDGELINEHG_HGNAME,
	BPA_DAT_EDGELINEHG_LINEHGPTR,
};
struct	_BpaMDBDat_ACBus2HG_	{
	char	szACBusName[MDB_CHARLEN_BPABUS];
	float	fACBuskV;
	char	szLineHGName[MDB_CHARLEN_SHORT];
	short	nLineHG;
}	DISALIGN;
typedef	struct	_BpaMDBDat_ACBus2HG_	tagBpaDat_EdgeLineHG;

enum _BpaMDBEnum_DatField_DCBus2Line_
{
	BPA_DAT_EDGEDCLINE_DCBUSNAME=0,
	BPA_DAT_EDGEDCLINE_DCBUSKV,
	BPA_DAT_EDGEDCLINE_DCLINENAME,
	BPA_DAT_EDGEDCLINE_DCLINEPTR,
};
struct	_BpaMDBDat_DCBus2Line_	{
	char	szDCBusName[MDB_CHARLEN_BPABUS];
	float	fDCBuskV;
	char	szDCLineName[MDB_CHARLEN_SHORT];
	int		nDCLinePtr;
}	DISALIGN;
typedef	struct	_BpaMDBDat_DCBus2Line_	tagBpaDat_EdgeDCLine;

enum _BpaMDBEnum_DatField_DCBus2R_
{
	BPA_DAT_EDGER_DCBUSNAME=0,
	BPA_DAT_EDGER_DCBUSKV,
	BPA_DAT_EDGER_RNAME,
	BPA_DAT_EDGER_RPTR,
};
struct	_BpaMDBDat_DCBus2R_	{
	char	szDCBusName[MDB_CHARLEN_BPABUS];
	float	fDCBuskV;
	char	szRName[MDB_CHARLEN_SHORT];
	int		nRPtr;
}	DISALIGN;
typedef	struct	_BpaMDBDat_DCBus2R_	tagBpaDat_EdgeR;

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
	char				szCardKey[MDB_CHARLEN_SHORTEST];	//	1	4	A4	������
	char				szPFCASE[MDB_CHARLEN_SHORTER];		//	6	15	A10	������ʽ��
	unsigned char		bITSKP;								//	17	17	I1	д����ļ��Ĳ���
	unsigned char		bNOPRNT;							//	20	20	I1	NOPRNT,Ϊ1ʱ��ӡȫ����������
	unsigned char		bDSW;								//	22	22	I1	����ļ�ҡ��������ʾ����
	unsigned char		bIWSCC;								//	23	23	I1	�����¼����ɿ������ɱ��
	unsigned char		bZSW; 								//	24	24	I1	�����򿨽��м���־
	float				fX2FAC;								//	45	49	F5.5	���Գƹ���ʱ�����X2��Xdp֮��
	float				fXFACT; 							//	50	54	F5.5	�����Xdpp��Xdp֮��
	float				fTDODPS;							//	55	59	F5.5	��������Tdopp(��)
	float				fTQODPS;							//	60	64	F5.5	��������Tdopp(��)
	float				fTDODPH;							//	65	69	F5.5	͹��ˮ�ֻ���Tqopp(��)
	float				fTQODPH;							//	70	74	F5.5	͹��ˮ�ֻ���Tdopp(��)
	float				fCFACL2; 							//	75	80	F6.5	���򸺺ɵ��ɱ�ôֵ
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
	char				szCardKey[MDB_CHARLEN_SHORTEST];	//	1	4	A4	������
	float				fTBUSF;								//	5	9	F5.4	ĸ��Ƶ���˲���ȱʡʱ�䳣��
	float				fTZERO;								//	12	16	F5.4	������·ȱʡʱ�䳣��
	unsigned char		bIBLOD;								//	18	18	I1	ĸ�߸��ɿ���
	float				fDMPALL;							//	20	22	F3.2	ȱʡ�������������
	unsigned char		bIAMRTS;							//	26	26	I1	�����ֵ��Ϊ0������ F1���е�XFACTҲ��Ϊ0�����۷�����Ĵ���̬�����Ƿ��Ѿ���M��ָ������Ҫ����ȱʡ�Ĳ��������㷢����Ĵ���̬����
	float				fVCHGL;								//	28	31	F4.3	�������ĸ�ߵ�ѹ���ڸ�ֵ���򸺺ɽ�ת��Ϊ���迹���ɣ�ȱʡֵΪ0.5pu
	unsigned char		bSPTOSG;							//	33	33	I1	SP��Ϊ�Լ��ٹ�����Ϊ�����źŵ�PSS����SG��Ϊ�Ե�Ź���Ϊ�����źŵ�PSS�������ֵ��Ϊ0�����ȶ����������е�SP����ΪSG��
	float				fGSIQU;								//	37	41	F5.5	�����ֵ��Ϊ�㣬�������ļ�������GH����GS���������Ĵ�С��Ϊ��ֵ
	float				fTITSKP;							//	43	47	F5.1	�ӱ�ʱ�俪ʼ�����ձ����е�48-49����д�Ĳ������д洢
	short				nITSKP1;							//	48	49	I2	�ӱ���43-47�й涨��ʱ��TITSKP��ʼÿ��ITSKP1���洢һ������
	unsigned char		bVRLIM;								//	51	51	I1	FM\FO\FP\FQ\FR\FS\FT��FG������ģ�͵ĵ�ѹ���޷�����Ϊ���޷������VRLIM��Ϊ0�������Ϊ���޷�
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

enum	_BpaMDBEnum_SwiField_WGWGen_{
	BPA_SWI_WGWGEN_CARDKEY=0,
	BPA_SWI_WGWGEN_BUS_NAME,
	BPA_SWI_WGWGEN_BUS_KV,
	BPA_SWI_WGWGEN_ID,
	BPA_SWI_WGWGEN_GW_TYPE,
	BPA_SWI_WGWGEN_NG,
	BPA_SWI_WGWGEN_PPER,
	BPA_SWI_WGWGEN_QPER,
	BPA_SWI_WGWGEN_IP_CUR,
	BPA_SWI_WGWGEN_IP_RETURN,
	BPA_SWI_WGWGEN_IP_RET_TIME,
	BPA_SWI_WGWGEN_IP_RATE,
	BPA_SWI_WGWGEN_Q_RATE,
	BPA_SWI_WGWGEN_IMAX,
	BPA_SWI_WGWGEN_KEYNAME,
	BPA_SWI_WGWGEN_BUSPTR,
};
struct	_BpaMDBSwi_WGWGen_
{
	char			szCardKey[MDB_CHARLEN_BPABUS];
	char			szBus_Name[MDB_CHARLEN_BPABUS];
	float			fBus_kV;
	char			cID;
	char			szGW_TYPE[MDB_CHARLEN_SHORT];
	short			nNG;
	float			fPPER;
	float			fQPER;
	float			fIP_CUR;
	float			fIP_RETURN;
	float			fIP_RET_TIME;
	float			fIP_RATE;
	float			fQ_RATE;
	float			fIMAX;
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_WGWGen_	tagBpaSwi_WGWGen;

enum	_BpaMDBEnum_SwiField_PV_{
	BPA_SWI_PV_CARDKEY=0,
	BPA_SWI_PV_BUS_NAME,
	BPA_SWI_PV_BUS_KV,
	BPA_SWI_PV_ID,
	BPA_SWI_PV_T,
	BPA_SWI_PV_S,
	BPA_SWI_PV_UOC,
	BPA_SWI_PV_ISC,
	BPA_SWI_PV_UM,
	BPA_SWI_PV_IM,
	BPA_SWI_PV_N1,
	BPA_SWI_PV_N2,
	BPA_SWI_PV_KEYNAME,
	BPA_SWI_PV_BUSPTR,
};
struct	_BpaMDBSwi_PV_
{
	char			szCardKey[MDB_CHARLEN_SHORTEST];
	char			szBus_Name[MDB_CHARLEN_BPABUS];
	float			fBus_kV;
	char			cID;
	float			fT;
	float			fS;
	float			fUoc;
	float			fIsc;
	float			fUm;
	float			fIm;
	short			nN1;
	short			nN2;
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_PV_	tagBpaSwi_PV;

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
	int			nGenBus;
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
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	������
	char			szBus_Name[MDB_CHARLEN_BPABUS];	//	4	11	A8	���������
	float			fBus_kV;						//	12	15	F4.0	�������׼��ѹ(kV)
	char			cGen_ID;						//	16	16	A1	BusIDʶ����ID
	float			fT1;							//	17	21	F5.3	ת�ٲ�������ʱ�䳣��(��)
	float			fE;								//	22	27	F6.4	ת��ƫ������
	float			fK1;							//	28	32	F5.2	ת��ƫ��Ŵ���
	unsigned char	bI;								//	33	33	I1	���Ʒ�ʽѡ��
	float			fKP;							//	34	38	F5.3	PID�������ڱ���
	float			fKD;							//	39	43	F5.3	PID΢�ֻ��ڱ���
	float			fKI;							//	44	48	F5.3	PID���ֻ��ڱ���
	float			fINTG_MAX;						//	49	52	F4.2	PID���ֻ����޷�����
	float			fINTG_MIN;						//	53	56	F4.2	PID���ֻ����޷�����
	float			fPID_MAX;						//	57	60	F4.2	PID����޷����ڵ�����
	float			fPID_MIN;						//	61	64	F4.2	PID����޷����ڵ�����
	float			fK2;							//	65	69	F5.3	���ɿ���ǰ��ϵ��
	float			fW_MAX;							//	70	74	F5.3	һ�ε�Ƶ��������
	float			fW_MIN;							//	75	79	F5.3	һ�ε�Ƶ��������
	float			fTW_DELAY;						//	17	21	F5.0	Ƶ�������źŵĴ��ӳ�ʱ��(��)
	float			fTP_DELAY;						//	22	26	F5.0	���ʷ����źŵĴ��ӳ�ʱ��(��)
	float			fTR;							//	27	31	F5.0	���ʷ����źŶ�Ӧ��һ�׹��Ի���ʱ�䳣��(��)
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
	char				szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char				szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	���������
	float				fBus_kV;							//	12	15	F4.0	�������׼��ѹ(kV)
	char				cGen_ID;							//	16	16	A1	BusIDʶ����ID
	float				fTW;								//	17	21	F5.3	ת��ƫ���˲�����ʱ�䳣��(��)
	float				fE;									//	22	27	F6.4	ת��ƫ������
	unsigned char		bI;									//	28	28	I1	ת�ٲ����˲�����������ʽѡ��
	float				fK1;								//	29	33	F5.2	ת��ƫ��Ŵ���
	float				fK2;								//	34	37	F4.2	����ѹ��ƫ��Ŵ���
	unsigned char		bI_Control;							//	38	38	I1	���Ʒ�ʽѡ��
	float				fKP;								//	39	43	F5.3	PID�������ڱ���
	float				fKD;								//	44	48	F5.3	PID΢�ֻ��ڱ���
	float				fKI;								//	49	53	F5.3	PID���ֻ��ڱ���
	float				fINTG_MAX;							//	54	57	F4.2	PID���ֻ����޷�����
	float				fINTG_MIN;							//	58	61	F4.2	PID���ֻ����޷�����
	float				fPID_MAX;							//	62	65	F4.2	PID����޷����ڵ�����
	float				fPID_MIN;							//	66	69	F4.2	PID����޷����ڵ�����
	float				fW_MAX;								//	70	74	F5.3	һ�ε�Ƶ��������
	float				fW_MIN;								//	75	79	F5.3	һ�ε�Ƶ��������
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
	char			szCardKey[MDB_CHARLEN_SHORTEST];	//	1	2	A2	������
	char			szBus_Name[MDB_CHARLEN_BPABUS];	//	4	11	A8	���������
	float			fBus_kV;						//	12	15	F4.0	�������׼��ѹ(kV)
	char			cGen_ID;						//	16	16	A1	BusIDʶ����ID
	float			fKW;							//	17	21	F5.0	Ƶ��ƫ��Ŵ���
	float			fTR;							//	22	25	F4.4	Ƶ�ʲ�������ʱ�䳣��(��)
	float			fNegative_DB1;					//	26	29	F4.4	ת�ٵ�������(����������ڶƵ�ʵı�ôֵ)
	float			fDB1;							//	30	33	F4.4	ת�ٵ�������(����������ڶƵ�ʵı�ôֵ)
	float			fKP;							//	34	38	F5.0	PID�������ڷŴ���
	float			fKD;							//	39	43	F5.0	PID΢�ֻ��ڷŴ���
	float			fKI;							//	44	48	F5.0	PID���ֻ��ڷŴ���
	float			fTD;							//	49	52	F4.4	PID΢�ֻ���ʱ�䳣��(��)
	float			fINTG_MAX;						//	53	56	F4.4	PID���ֻ����޷�����
	float			fINTG_MIN;						//	57	60	F4.4	PID���ֻ����޷�����
	float			fPID_MAX;						//	61	64	F4.4	PID����޷����ڵ�����
	float			fPID_MIN;						//	65	68	F4.4	PID����޷����ڵ�����
	float			fDELT;							//	69	72	F4.4	DELT��ת�ٲ������ӳ�ʱ��(��)
	float			fDB_MAX;						//	73	76	F4.4	һ�ε�Ƶ����
	float			fDB_MIN;						//	77	80	F4.4	һ�ε�Ƶ����
	float			fDELT2;							//	17	21	F4.4	�����ӳ�ʱ��(��)
	float			fTR2;							//	22	25	F4.4	��������ʱ�䳣��(��)
	float			fEP;							//	26	29	F5.0	ϵ��
	float			fNegative_DB2;					//	30	33	F5.0	����������
	float			fDB2;							//	34	38	F5.0	����������
	float			fDBMAX2;						//	39	43	F5.0	�޷�����
	float			fDBMIN2;						//	44	48	F5.0	�޷�����
	unsigned char	bITYP;							//	49	52	I1	ģʽѡ��
	unsigned char	bITYP2;							//	53	56	I1	����ģʽѡ��
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GM_	tagBpaSwi_GovGM;

//////////////////////////////////////////////////////////////////////////
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
	char	szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char	szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	���������
	float	fBus_kV;							//	12	15	F4.0	�������׼��ѹ(kV)
	char	cGen_ID;							//	16	16	A1	BusIDʶ����ID
	float	fPmax;								//	17	22	F6.1	��������е����
	float	fPmin;								//	23	28	F6.1	��С�����е����
	float	fDB;								//	29	33	F5.3	���ص�����(Hz)
	float	fR;									//	34	38	F5.3	��̬ƫ��(pu)
	float	fKp;								//	39	43	F5.3	������������(pu/pu)
	float	fKi;								//	44	48	F5.3	���ֻ�������(pu/sec)
	float	fKd;								//	49	53	F5.3	΢�ֻ�������(pu��sec)
	float	fGOV_MAX;							//	54	58	F5.3	���ֻ�������(pu)
	float	fGOV_Min;							//	59	63	F5.3	���ֻ�������(pu)
	float	fDEMAND_MAX;						//	64	68	F5.3	�������(pu)
	float	fDEMAND_MIN;						//	69	73	F5.3	�������(pu)
	char	szKeyName[MDB_CHARLEN_SHORTER];
	int		nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GD_	tagBpaSwi_GovGD;

//////////////////////////////////////////////////////////////////////////
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
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	������
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	���������
	float			fBus_kV;								//	12	15	F4.0	�������׼��ѹ(kV)
	char			cGen_ID;								//	16	16	A1	BusIDʶ����ID
	float			fG_Tsm;									//	17	21	F5.3	�ŷ�ϵͳʱ�䳣��(��)
	float			fG_Ropen;								//	22	26	F5.3	����������ٶ�(p.u. gate/sec)
	float			fG_Rclose;								//	27	31	F5.3	�������ر��ٶ�(p.u. gate/sec)
	float			fG_EHC_MAX;								//	32	36	F5.3	EHC���λ������(pu)
	float			fG_EHC_MIN;								//	37	41	F5.3	EHC��Сλ������(pu)
	float			fG_T_Open;								//	42	46	F5.3	���Ʒ�����ʱ�䳣��(sec)
	float			fG_T_Close;								//	47	51	F5.3	���Ʒ��ر�ʱ�䳣��(sec)
	float			fG_DB_Value;							//	52	56	F5.3	��������(pu)
	float			fG_CV_MAX;								//	57	61	F5.3	��������(pu)
	float			fG_CV_MIN;								//	62	66	F5.3	���Ʒ�����(pu)
	float			fG_Kpe;									//	67	71	F5.3	��Ź��ʷ�������(pu/ pu)
	float			fG_Tpe;									//	72	76	F5.3	��Ź��ʷ���ʱ�䳣��(sec)
	unsigned char	bG_Mode;								//	78	78	I1	����ģʽ
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_GZ_	tagBpaSwi_GovGZ;

//////////////////////////////////////////////////////////////////////////
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
	char			szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char			szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	���������
	float			fBus_kV;							//	12	15	F4.0	�������׼��ѹ(kV)
	char			cGen_ID;							//	16	16	A1	BusIDʶ����ID
	float			fTCH;								//	17	21	F5.3	�����ݻ�ʱ�䳣��(��)
	float			fK1;								//	22	26	F5.3	"���ֻ�K1=1.0��ˮ�ֻ�K1=-2.0(����)",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TA_	tagBpaSwi_MovTA;

//////////////////////////////////////////////////////////////////////////
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
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	������
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	���������
	float			fBus_kV;								//	12	15	F4.0	�������׼��ѹ(kV)
	char			cGen_ID;								//	16	16	A1	BusIDʶ����ID
	float			fTCH;									//	17	21	F5.3	"�����ݻ�ʱ�䳣��(��)",
	float			fFHP;									//	22	26	F5.3	"��ѹ�׹��ʱ���",
	float			fTRH;									//	32	36	F5.3	"������ʱ�䳣��",
	float			fFIP;									//	37	41	F5.3	"��ѹ�׹��ʱ���",
	float			fTCO;									//	47	51	F5.3	"�����ʱ�䳣��",
	float			fFLP;									//	52	56	F5.3	"��ѹ�׹��ʱ����������һ��",
	float			fLambda;								//	77	80	F4.2	"��ѹ�׹�����Ȼ����ϵ��",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TB_	tagBpaSwi_MovTB;

//////////////////////////////////////////////////////////////////////////
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
	char		szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	������
	char		szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	���������
	float		fBus_kV;								//	12	15	F4.0	�������׼��ѹ(kV)
	char		cGen_ID;								//	16	16	A1	BusIDʶ����ID
	float		fTCH;									//	17	21	F5.3	"�����ݻ�ʱ�䳣��(��)",
	float		fFVHP;									//	22	26	F5.3	"����ѹ�׹��ʱ���",
	float		fTRH1;									//	32	36	F5.3	"��һ������ʱ�䳣��",
	float		fFHP;									//	37	41	F5.3	"��ѹ�׹��ʱ���",
	float		fTRH2;									//	47	51	F5.3	"�ڶ�������ʱ�䳣��",
	float		fFIP;									//	52	56	F5.3	"��ѹ�׹��ʱ��������һ��",
	float		fTCO;									//	62	66	F5.3	"�����ʱ�䳣��",
	float		fFLP;									//	67	71	F5.3	"��ѹ�׹��ʱ��������һ��",
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TC_	tagBpaSwi_MovTC;

//////////////////////////////////////////////////////////////////////////
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
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;		//	1	2	A2	������
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;		//	4	11	A8	���������
	float			fBus_kV;								//	12	15	F4.0	�������׼��ѹ(kV)
	char			cGen_ID;								//	16	16	A1	BusIDʶ����ID
	float			fTCH;									//	17	21	F5.3	"�����ݻ�ʱ�䳣��(��)",
	float			fFHP;									//	22	26	F5.3	"��ѹ�׹��ʱ���",
	float			fTRH;									//	32	36	F5.3	"������ʱ�䳣��",
	float			fFIP;									//	37	41	F5.3	"��ѹ�׹��ʱ���",
	float			fTCO;									//	47	51	F5.3	"�����ʱ�䳣��",
	float			fFLP_1;									//	52	56	F5.3	"��ѹ�׹��ʱ����������һ��",
	float			fFLP_2;									//	57	61	F5.3	"��ѹ�׹��ʱ����������һ��",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TD_	tagBpaSwi_MovTD;

//////////////////////////////////////////////////////////////////////////
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
	char			szCardKey[MDB_CHARLEN_SHORTEST] ;		//	1	2	A2	������
	char			szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	���������
	float			fBus_kV;								//	12	15	F4.0	�������׼��ѹ(kV)
	char			cGen_ID;								//	16	16	A1	BusIDʶ����ID
	float			fTCH;									//	17	21	F5.3	"�����ݻ�ʱ�䳣��(��)",
	float			fFHP;									//	22	26	F5.3	"��ѹ�׹��ʱ���",
	float			fTRH;									//	32	36	F5.3	"������ʱ�䳣��",
	float			fFIP;									//	37	41	F5.3	"��ѹ�׹��ʱ���",
	float			fTCO;									//	47	51	F5.3	"�����ʱ�䳣��",
	float			fFLP;									//	57	61	F5.3	"��ѹ�׹��ʱ����������һ��",
	char			szKeyName[MDB_CHARLEN_SHORTER];
	int				nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TE_	tagBpaSwi_MovTE;

//////////////////////////////////////////////////////////////////////////
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
	char		szCardKey[MDB_CHARLEN_SHORTEST] ;			//	1	2	A2	������
	char		szBus_Name[MDB_CHARLEN_BPABUS] ;			//	4	11	A8	���������
	float		fBus_kV;								//	12	15	F4.0	�������׼��ѹ(kV)
	char		cGen_ID;								//	16	16	A1	BusIDʶ����ID
	float		fTCH;									//	17	21	F5.3	"�����ݻ�ʱ�䳣��(��)",
	float		fFVHP;									//	22	26	F5.3	"����ѹ�׹��ʱ���",
	float		fTRH1;									//	32	36	F5.3	"��һ������ʱ�䳣��",
	float		fFHP;									//	37	41	F5.3	"��ѹ�׹��ʱ���",
	float		fTRH2;									//	47	51	F5.3	"�ڶ�������ʱ�䳣��",
	float		fFIP_1;									//	52	56	F5.3	"��ѹ�׹��ʱ��������һ��",
	float		fFIP_2;									//	57	61	F5.3	"��ѹ�׹��ʱ��������һ��",
	float		fTCO;									//	62	66	F5.3	"�����ʱ�䳣��",
	float		fFLP_1;									//	67	71	F5.3	"��ѹ�׹��ʱ��������һ��",
	float		fFLP_2;									//	72	76	F5.3	"��ѹ�׹��ʱ��������һ��",
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;
	unsigned char	bAppendTag;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_TF_	tagBpaSwi_MovTF;

//////////////////////////////////////////////////////////////////////////
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char		szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	���������
	float		fBus_kV;							//	12	15	F4.0	�������׼��ѹ(kV)
	char		cGen_ID;							//	16	16	A1	BusIDʶ����ID
	float		fK1;								//	22	26	F5.3	"���ֻ�K1=1.0��ˮ�ֻ�K1=-2.0(����)",
	float		fTw_Half;							//	32	36	F5.3	"ˮ��ЧӦʱ�䳣��(��)",
	float		fK3;								//	37	41	F5.3	"K3=3.0(����)",
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];			//	1	2	A2	������
	char		szBus_Name[MDB_CHARLEN_BPABUS];			//	4	11	A8	���������
	float		fBus_kV;								//	12	15	F4.0	�������׼��ѹ��kV��
	char		cGen_ID;								//	16	16	A1	BusIDʶ����ID
	float		fTSH;									//	17	21	F5.3	�������ݻ�ʱ�䳣��
	float		fTD;									//	22	26	F5.3	���������ݻ�ʱ�䳣��
	float		fTW;									//	27	31	F5.3	��¯ȼ���ͷŵ�ʱ�䳣��
	float		fK;										//	32	36	F5.3	�������������ܵ�����ϵ��
	float		fTdelay;								//	37	41	F5.3	��ʱ
	float		fLimit_MAX;								//	42	46	F5.3	����޷����ڵ����ֵ
	float		fLimit_MIN;								//	47	51	F5.3	����޷�������Сֵ
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	3	A3	������
	char		szBus_Name[MDB_CHARLEN_BPABUS];		//	4	11	A8	���������
	float		fBus_kV;							//	12	15	F4.0	�������׼��ѹ��kV��
	char		cGen_ID;							//	16	16	A1	BusIDʶ����ID
	float		fTstart;							//	19	23	F5.3	Ƶ�ʱ仯����ʼʱ�̣��ܲ���
	float		fT1;								//	29	33	F5.3	��1�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ1;								//	34	38	F5.3	��1�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT2;								//	39	43	F5.3	��2�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ2;								//	44	48	F5.3	��2�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT3;								//	49	53	F5.3	��3�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ3;								//	54	58	F5.3	��3�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT4;								//	59	63	F5.3	��4�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ4;								//	64	68	F5.3	��4�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT5;								//	69	73	F5.3	��5�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ5;								//	74	78	F5.3	��5�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT6;								//	19	23	F5.3	��6�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ6;								//	24	28	F5.3	��6�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT7;								//	29	33	F5.3	��7�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ7;								//	34	38	F5.3	��7�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT8;								//	39	43	F5.3	��8�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ8;								//	44	48	F5.3	��8�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT9;								//	49	53	F5.3	��9�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ9;								//	54	58	F5.3	��9�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT10;								//	59	63	F5.3	��10�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ10;							//	64	68	F5.3	��10�����Ӧ��Ƶ�ʱ仯����Hz��
	float		fT11;								//	69	73	F5.3	��11�����Ӧ��ʱ�̣��ܲ���
	float		fFREQ11;							//	74	78	F5.3	��11�����Ӧ��Ƶ�ʱ仯����Hz��
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;							//
}	DISALIGN;
typedef	struct	_BpaMDBSwi_IGV_	tagBpaSwi_IGV;

//////////////////////////////////////////////////////////////////////////
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	3	A3	������
	char		szBus_Name[MDB_CHARLEN_BPABUS];		//	5	12	A8	���������
	float		fBus_kV;							//	13	16	F4.0	�������׼��ѹ��kV��
	char		cGen_ID;							//	17	17	A1	�����ʶ����ID
	float		fAMP1;								//	19	23	F5.0	��һ�������ķ�ֵ���ٷ���������ֵ
	float		fFREQ1;								//	24	28	F5.2	��һ��������Ƶ�ʣ�����/�룩
	float		fANGL01;							//	29	33	F5.2	��һ�������ĳ�ʼ��λ�����ȣ�
	float		fTBEGIN1;							//	34	38	F5.0	��һ����������ʼʱ�䣨�ܲ���
	float		fTEND1;								//	39	43	F5.0	��һ�������Ľ���ʱ�䣨�ܲ���
	float		fAMP2;								//	45	49	F5.0	�ڶ��������ķ�ֵ���ٷ���������ֵ
	float		fFREQ2;								//	50	54	F5.2	�ڶ���������Ƶ�ʣ�����/�룩
	float		fANGL02;							//	55	59	F5.2	�ڶ��������ĳ�ʼ��λ�����ȣ�
	float		fTBEGIN2;							//	60	64	F5.0	�ڶ�����������ʼʱ�䣨�ܲ���
	float		fTEND2;								//	65	69	F5.0	�ڶ��������Ľ���ʱ�䣨�ܲ���
	char		cCMW;								//	80	80	A1	�ո��ʾǰ���������ķ�ֵ���Ƿ������е���ʳ�ֵ�İٷ�����W��Ϊ����ֵ��
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nGenBus;							//
}	DISALIGN;
typedef	struct	_BpaMDBSwi_FGV_	tagBpaSwi_FGV;

//////////////////////////////////////////////////////////////////////////
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
	char		cMod;
	float		fIMax;
	float		fIMargin;
	float		fAlphaStop;
	float		fTD;
	float		fVLIM;
	char		cDISA;
	char		cMSU;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_D_	tagBpaSwi_D;

//////////////////////////////////////////////////////////////////////////
enum	_BpaMDBEnum_SwiField_DT_
{
	BPA_SWI_DT_CARDKEY = 0,
	BPA_SWI_DT_BUS_NAME,
	BPA_SWI_DT_BUS_KV,
	BPA_SWI_DT_DV,
	BPA_SWI_DT_IMAX,
	BPA_SWI_DT_IMARGIN,
	BPA_SWI_DT_TC,
	BPA_SWI_DT_TV,
	BPA_SWI_DT_ALPHASTOP,
	BPA_SWI_DT_MSU,
	BPA_SWI_DT_KEYNAME,
	BPA_SWI_DT_BUSPTR,
};
struct	_BpaMDBSwi_DT_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	float		fDV;
	float		fIMax;
	float		fIMargin;
	float		fTc;
	float		fTv;
	float		fAlphaStop;
	char		cMSU;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_DT_	tagBpaSwi_DT;

//////////////////////////////////////////////////////////////////////////
enum	_BpaMDBEnum_SwiField_DF_
{
	BPA_SWI_DF_CARDKEY = 0,
	BPA_SWI_DF_BUS_NAME,
	BPA_SWI_DF_BUS_KV,
	BPA_SWI_DF_DVDT,
	BPA_SWI_DF_VF1,
	BPA_SWI_DF_VF2,
	BPA_SWI_DF_DT,
	BPA_SWI_DF_VRS,
	BPA_SWI_DF_C1,
	BPA_SWI_DF_T1,
	BPA_SWI_DF_C2,
	BPA_SWI_DF_T2,
	BPA_SWI_DF_C3,
	BPA_SWI_DF_T3,
	BPA_SWI_DF_KEYNAME,
	BPA_SWI_DF_BUSPTR,
};
struct	_BpaMDBSwi_DF_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	float		fDVDT;
	float		fVf1;
	float		fVf2;
	float		fDT;
	float		fVrs;
	float		fC1;
	float		fT1;
	float		fC2;
	float		fT2;
	float		fC3;
	float		fT3;
	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_DF_	tagBpaSwi_DF;

//////////////////////////////////////////////////////////////////////////
enum	_BpaMDBEnum_SwiField_DM_
{
	BPA_SWI_DM_CARDKEY = 0,
	BPA_SWI_DM_BUS_NAME,
	BPA_SWI_DM_BUS_KV,
	BPA_SWI_DM_MOD,
	BPA_SWI_DM_TVP,
	BPA_SWI_DM_IMAX,
	BPA_SWI_DM_IMIN,
	BPA_SWI_DM_TIDMES,
	BPA_SWI_DM_KP_I,
	BPA_SWI_DM_TI_I,
	BPA_SWI_DM_MAX_I,
	BPA_SWI_DM_MIN_I,
	BPA_SWI_DM_TGAMMES,
	BPA_SWI_DM_KP_GAM,
	BPA_SWI_DM_TI_GAM,
	BPA_SWI_DM_MAX_GAM,
	BPA_SWI_DM_MIN_GAM,
	BPA_SWI_DM_TVPSMPALL,
	BPA_SWI_DM_DISA,

	BPA_SWI_DM_TVDCOL,		
	BPA_SWI_DM_X1,			
	BPA_SWI_DM_Y1,			
	BPA_SWI_DM_X2,			
	BPA_SWI_DM_Y2,			
	BPA_SWI_DM_K1,			
	BPA_SWI_DM_K2,			
	BPA_SWI_DM_DOWNSL,		
	BPA_SWI_DM_UPSL,		
	BPA_SWI_DM_GAMMAMIN,		
	BPA_SWI_DM_IMARGIN,		
	BPA_SWI_DM_DGAMMIN,		

	BPA_SWI_DM_KEYNAME,
	BPA_SWI_DM_BUSPTR,
};
struct	_BpaMDBSwi_DM_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cMOD;
	float		fTvp;
	float		fIMAX;
	float		fIMIN;
	float		fTidmes;
	float		fKp_I;
	float		fTi_I;
	float		fMax_I;
	float		fMin_I;
	float		fTGamMes;
	float		fKp_Gam;
	float		fTi_Gam;
	float		fMax_Gam;
	float		fMin_Gam;
	float		fTvpSmpall;
	char		cDISA;

	float		fTVDCOL;
	float		fX1;
	float		fY1;
	float		fX2;
	float		fY2;
	float		fK1;
	float		fK2;
	float		fDownSL;
	float		fUpSL;
	float		fGammaMin;
	float		fImargin;
	float		fDGamMin;

	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_DM_	tagBpaSwi_DM;

//////////////////////////////////////////////////////////////////////////
enum	_BpaMDBEnum_SwiField_DN_
{
	BPA_SWI_DN_CARDKEY,
	BPA_SWI_DN_BUS_NAME,
	BPA_SWI_DN_BUS_KV,
	BPA_SWI_DN_MOD,
	BPA_SWI_DN_TVP,
	BPA_SWI_DN_IMAX,
	BPA_SWI_DN_IMIN,
	BPA_SWI_DN_P_I,
	BPA_SWI_DN_T_I,
	BPA_SWI_DN_P_U,
	BPA_SWI_DN_T_U,
	BPA_SWI_DN_P_GAM,
	BPA_SWI_DN_T_GAM,
	BPA_SWI_DN_VACLOW,
	BPA_SWI_DN_TVACLOW,
	BPA_SWI_DN_IDLOW,
	BPA_SWI_DN_TIDLOW,
	BPA_SWI_DN_TLIM,
	BPA_SWI_DN_TP,
	BPA_SWI_DN_IOVL,
	BPA_SWI_DN_TIMAX,
	BPA_SWI_DN_TMAXLIM,
	BPA_SWI_DN_DISA,

	BPA_SWI_DN_TVDCOL,		
	BPA_SWI_DN_X1,			
	BPA_SWI_DN_Y1,			
	BPA_SWI_DN_X2,			
	BPA_SWI_DN_Y2,			
	BPA_SWI_DN_K1,			
	BPA_SWI_DN_K2,			
	BPA_SWI_DN_DOWNSL,		
	BPA_SWI_DN_UPSL,		
	BPA_SWI_DN_ALPHASTOP,	
	BPA_SWI_DN_GAMAAMIN,	
	BPA_SWI_DN_TVPSMALL,	

	BPA_SWI_DN_KEYNAME,
	BPA_SWI_DN_BUSPTR,
};
struct	_BpaMDBSwi_DN_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	char		cMOD;
	float		fTvp;
	float		fIMAX;
	float		fIMIN;
	float		fP_I;
	float		fT_I;
	float		fP_U;
	float		fT_U;
	float		fP_Gam;
	float		fT_Gam;
	float		fVacLow;
	float		fTVacLow;
	float		fIdLow;
	float		fTIdLow;
	float		fTlim;
	float		fTp;
	float		fIovl;
	float		fTimax;
	float		fTmaxlim;
	char		cDISA;

	float		fTVDCOL;
	float		fX1;
	float		fY1;
	float		fX2;
	float		fY2;
	float		fK1;
	float		fK2;
	float		fDownSL;
	float		fUpSL;
	float		fAlphaStop;
	float		fGamaaMin;
	float		fTvpSmall;

	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_DN_	tagBpaSwi_DN;

//////////////////////////////////////////////////////////////////////////
enum	_BpaMDBEnum_SwiField_DA_
{
	BPA_SWI_DA_CARDKEY,
	BPA_SWI_DA_BUS_NAME,
	BPA_SWI_DA_BUS_KV,
	BPA_SWI_DA_G_AMAX,
	BPA_SWI_DA_T_AMAX,
	BPA_SWI_DA_GAMMAREF,
	BPA_SWI_DA_GAMMAMIN,
	BPA_SWI_DA_KP_VCA,
	BPA_SWI_DA_TI_VCA,
	BPA_SWI_DA_K1_RA,
	BPA_SWI_DA_K2_RA,
	BPA_SWI_DA_CDL,
	BPA_SWI_DA_D1,
	BPA_SWI_DA_DECR,
	BPA_SWI_DA_T_GA,
	BPA_SWI_DA_TD_RET,
	BPA_SWI_DA_TH_RET,
	BPA_SWI_DA_TH_RES,
	BPA_SWI_DA_DISA,
	BPA_SWI_DA_DBG,

	BPA_SWI_DA_MOD,
	BPA_SWI_DA_LEAD,
	BPA_SWI_DA_OPN,
	BPA_SWI_DA_BC_ON,
	BPA_SWI_DA_UDLOW,
	BPA_SWI_DA_UDHIGH,
	BPA_SWI_DA_UDTUP,
	BPA_SWI_DA_UDTDN,
	BPA_SWI_DA_IOMIN_VDCL,
	BPA_SWI_DA_IOMIN,
	BPA_SWI_DA_ID_T,
	BPA_SWI_DA_GAIN,
	BPA_SWI_DA_KP,
	BPA_SWI_DA_TI,
	BPA_SWI_DA_G_CF,
	BPA_SWI_DA_K_CF,
	BPA_SWI_DA_T_DN_CF,
	BPA_SWI_DA_A,

	BPA_SWI_DA_KEYNAME,
	BPA_SWI_DA_BUSPTR,
};

struct	_BpaMDBSwi_DA_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBus_Name[MDB_CHARLEN_BPABUS];
	float		fBus_kV;
	float		fG_Amax;
	float		fT_Amax;
	float		fGammaRef;
	float		fGammaMin;
	float		fKp_vca;
	float		fTi_vca;
	float		fK1_ra;
	float		fK2_ra;
	float		fCdl;
	float		fD1;
	float		fDecr;
	float		fT_ga;
	float		fTd_ret;
	float		fTh_ret;
	float		fTh_res;
	char		cDISA;
	char		cDBG;

	char		szMOD[MDB_CHARLEN_SHORTEST];
	char		szLEAD[MDB_CHARLEN_SHORTEST];
	char		szOPN[MDB_CHARLEN_SHORTEST];
	char		szBC_ON[MDB_CHARLEN_SHORTEST];
	float		fUdlow;
	float		fUdhigh;
	float		fUdtup;
	float		fUdtdn;
	float		fIomin_vdcl;
	float		fIomin;
	float		fId_t;
	float		fGain;
	float		fKp;
	float		fTi;
	float		fG_cf;
	float		fK_cf;
	float		fT_dn_cf;
	char		cA;

	char		szKeyName[MDB_CHARLEN_SHORTER];
	int			nDCBus;
}	DISALIGN;
typedef	struct	_BpaMDBSwi_DA_	tagBpaSwi_DA;

//////////////////////////////////////////////////////////////////////////
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char		szBus_Name[MDB_CHARLEN_BPABUS];			//	4	11	A8	ĸ������
	float		fBus_kV;								//	12	15	F4.0	��׼��ѹ(kV)
	char		szZone[MDB_CHARLEN_SHORTEST/2];			//	16	17	A2	ZONE,������
	char		szArea[MDB_CHARLEN_SHORTER];			//	18	27	A10	������
	float		fP1;									//	28	32	F5.3	�㶨�迹�й����ɰٷ���
	float		fQ1;									//	33	37	F5.3	�㶨�迹�޹����ɰٷ���
	float		fP2;									//	38	42	F5.3	�㶨�����й����ɰٷ���
	float		fQ2;									//	43	47	F5.3	�㶨�����޹����ɰٷ���
	float		fP3;									//	48	52	F5.3	�㶨�����й����ɰٷ���
	float		fQ3;									//	53	57	F5.3	�㶨�����޹����ɰٷ���
	float		fP4;									//	58	62	F5.3	��Ƶ���йص��й����ɰٷ���
	float		fQ4;									//	63	67	F5.3	��Ƶ���йص��޹����ɰٷ���
	float		fLDP;									//	68	72	F5.3	Ƶ�ʱ仯1��������й��仯
	float		fLDQ;									//	73	77	F5.3	Ƶ�ʱ仯1��������޹��仯
	float		fP5;									//	28	32	F5.3	��ѹָ����ص��й����ɱ���
	float		fQ5;									//	33	37	F5.3	��ѹָ����ص��޹����ɱ���
	float		fNP;									//	38	42	F5.3	�й���ѹָ��
	float		fNQ;									//	43	47	F5.3	�޹���ѹָ��
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
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float			fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float			fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char			cLoop;							//	32	32	A1		������·�Ļ�·��־
	float			fR0;							//	36	42	F7.4	��·�������(��ôֵ)
	float			fX0;							//	43	49	F7.4	��·����翹(��ôֵ)
	float			fGa0;							//	50	56	F7.4	��·BUS A ������Եص絼
	float			fBa0;							//	57	63	F7.4	��·BUS A ������Եص���
	float			fGb0;							//	64	70	F7.4	��·BUS B ������Եص絼
	float			fBb0;							//	71	77	F7.4	��·BUS B ������Եص���
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
	char			szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float			fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char			szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float			fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char			cLoop;							//	32	32	A1		������·�Ļ�·��־
	unsigned char	bSID;							//	32	32	I1	��ѹ������翹�Ľ��뷽ʽ
	float			fR0;							//	45	51	F7.4	��ѹ����������ôֵ
	float			fX0;							//	38	44	F7.4	��ѹ������翹��ôֵ
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
	char	szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float	fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char	szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float	fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char	cLoop;							//	32	32	A1		������·�Ļ�·��־
	float	fX0I;							//	36	42	F7.0	��·ǰ��߿���Ӧ�ĵ�ֵ����翹(pu)
	float	fX0J;							//	43	49	F7.0	��·���߿���Ӧ�ĵ�ֵ����翹(pu)
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
	char	szCardKey[MDB_CHARLEN_SHORTEST];	//1		2	A1	������
	char	szName[MDB_CHARLEN_BPABUS];			//7		14	A8	ĸ������
	float	fkV;								//15	18	F4.0��׼��ѹ(kV)
	float	fR0;								//	22	28	F7.4	�Ե�֧·�������(PU)
	float	fX0;								//	29	35	F7.4	�Ե�֧·����翹(PU)
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
	char				szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char				szBus1_I[MDB_CHARLEN_BPABUS];			//	5	12	A8	Bus Name1_A
	float				fKV1_I;								//	13	16	F4.0	Bus Base1_A(kV)
	char				szBus1_J[MDB_CHARLEN_BPABUS];			//	19	26	A8	Bus Name1_B
	float				fKV1_J;								//	27	30	F4.0	Bus Base1_B(kV)
	char				cPAR_1;								//	33	33	A1	ƽ����
	char				szBus2_I[MDB_CHARLEN_BPABUS];			//	36	43	A8	Bus Name2_I
	float				fKV2_I;								//	44	47	F4.0	Bus Base2_I(kV)
	char				szBus2_J[MDB_CHARLEN_BPABUS];			//	50	57	A8	Bus Name2_J
	float				fKV2_J;								//	58	61	F4.0	Bus Base2_J(kV)
	char				cPAR_2;								//	64	64	A1	ƽ����
	float				fRm;								//	67	73	F7.4	���е���
	float				fXm;								//	74	80	F7.4	���е翹
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char		szBus[MDB_CHARLEN_BPABUS];				//	4	11	A8	ĸ������
	float		fKV;									//	12	15	F4.0	��׼��ѹ(kV)
	float		fFreq01;								//	16	20	F5.3	��1��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fFreq02;								//	27	31	F5.3	��2��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fFreq03;								//	38	42	F5.3	��3��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fFreq04;								//	49	53	F5.3	��4��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fFreq05;								//	60	64	F5.3	��5��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fFreq06;								//	16	20	F5.3	��6��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fFreq07;								//	27	31	F5.3	��7��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fFreq08;								//	38	42	F5.3	��8��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fFreq09;								//	49	53	F5.3	��9��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fFreq10;								//	60	64	F5.3	��10��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fDelay01;								//	21	23	F3.2	��1��������ǰ��ʱ��(��)
	float		fDelay02;								//	32	34	F3.2	��2��������ǰ��ʱ��(��)
	float		fDelay03;								//	43	45	F3.2	��3��������ǰ��ʱ��(��)
	float		fDelay04;								//	54	56	F3.2	��4��������ǰ��ʱ��(��)
	float		fDelay05;								//	65	67	F3.2	��5��������ǰ��ʱ��(��)
	float		fDelay06;								//	21	23	F3.0	��6��������ǰ��ʱ��(��)
	float		fDelay07;								//	32	34	F3.0	��7��������ǰ��ʱ��(��)
	float		fDelay08;								//	43	45	F3.0	��8��������ǰ��ʱ��(��)
	float		fDelay09;								//	54	56	F3.0	��9��������ǰ��ʱ��(��)
	float		fDelay10;								//	65	67	F3.0	��10��������ǰ��ʱ��(��)
	float		fShed01;								//	24	26	F3.2	��1����ʼ���ɱ���ȥ��ֵ
	float		fShed02;								//	35	37	F3.2	��2����ʼ���ɱ���ȥ��ֵ
	float		fShed03;								//	46	48	F3.2	��3����ʼ���ɱ���ȥ��ֵ
	float		fShed04;								//	57	59	F3.2	��4����ʼ���ɱ���ȥ��ֵ
	float		fShed05;								//	68	70	F3.2	��5����ʼ���ɱ���ȥ��ֵ
	float		fShed06;								//	24	26	F3.3	��6������ȥ�ĸ���ֵ��MW��
	float		fShed07;								//	35	37	F3.3	��7������ȥ�ĸ���ֵ��MW��
	float		fShed08;								//	46	48	F3.3	��8������ȥ�ĸ���ֵ��MW��
	float		fShed09;								//	57	59	F3.3	��9������ȥ�ĸ���ֵ��MW��
	float		fShed10;								//	68	70	F3.3	��10������ȥ�ĸ���ֵ��MW��
	char		cW;										//	80	80	A1	�ر���W����ʾ��MWΪ��λ��ȥ����
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
	char		szCardKey[MDB_CHARLEN_SHORTEST];		//	1	2	A2	������
	char		szBus[MDB_CHARLEN_BPABUS];				//	4	11	A8	ĸ������
	float		fKV;									//	12	15	F4.0	��׼��ѹ(kV)
	float		fVolt01;								//	16	20	F5.3	��1��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fVolt02;								//	27	31	F5.3	��2��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fVolt03;								//	38	42	F5.3	��3��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fVolt04;								//	49	53	F5.3	��4��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fVolt05;								//	60	64	F5.3	��5��������ʱ�ĵ�ѹ(PU)��Ƶ��(Hz)
	float		fVolt06;								//	16	20	F5.3	��6��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fVolt07;								//	27	31	F5.3	��7��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fVolt08;								//	38	42	F5.3	��8��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fVolt09;								//	49	53	F5.3	��9��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fVolt10;								//	60	64	F5.3	��10��������ʱ�ĵ�ѹ(pu)��Ƶ��(Hz)
	float		fDelay01;								//	21	23	F3.2	��1��������ǰ��ʱ��(��)
	float		fDelay02;								//	32	34	F3.2	��2��������ǰ��ʱ��(��)
	float		fDelay03;								//	43	45	F3.2	��3��������ǰ��ʱ��(��)
	float		fDelay04;								//	54	56	F3.2	��4��������ǰ��ʱ��(��)
	float		fDelay05;								//	65	67	F3.2	��5��������ǰ��ʱ��(��)
	float		fDelay06;								//	21	23	F3.0	��6��������ǰ��ʱ��(��)
	float		fDelay07;								//	32	34	F3.0	��7��������ǰ��ʱ��(��)
	float		fDelay08;								//	43	45	F3.0	��8��������ǰ��ʱ��(��)
	float		fDelay09;								//	54	56	F3.0	��9��������ǰ��ʱ��(��)
	float		fDelay10;								//	65	67	F3.0	��10��������ǰ��ʱ��(��)
	float		fShed01;								//	24	26	F3.2	��1����ʼ���ɱ���ȥ��ֵ
	float		fShed02;								//	35	37	F3.2	��2����ʼ���ɱ���ȥ��ֵ
	float		fShed03;								//	46	48	F3.2	��3����ʼ���ɱ���ȥ��ֵ
	float		fShed04;								//	57	59	F3.2	��4����ʼ���ɱ���ȥ��ֵ
	float		fShed05;								//	68	70	F3.2	��5����ʼ���ɱ���ȥ��ֵ
	float		fShed06;								//	24	26	F3.3	��6������ȥ�ĸ���ֵ��MW��
	float		fShed07;								//	35	37	F3.3	��7������ȥ�ĸ���ֵ��MW��
	float		fShed08;								//	46	48	F3.3	��8������ȥ�ĸ���ֵ��MW��
	float		fShed09;								//	57	59	F3.3	��9������ȥ�ĸ���ֵ��MW��
	float		fShed10;								//	68	70	F3.3	��10������ȥ�ĸ���ֵ��MW��
	char		cW;										//	80	80	A1	�ر���W����ʾ��MWΪ��λ��ȥ����
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
	BPA_SWI_RE_KEYNAME,
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
	char		szKeyName[MDB_CHARLEN_SHORTER];
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
	BPA_SWI_RW_KEYNAME,
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
	char		szKeyName[MDB_CHARLEN_SHORTER];
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
	BPA_SWI_RA_KEYNAME,
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
	char		szKeyName[MDB_CHARLEN_SHORT];
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
	BPA_SWI_RU_KEYNAME,
};

struct	_BpaMDBSwi_RU_
{
	char		szCardKey[MDB_CHARLEN_SHORTEST];
	char		szBusI[MDB_CHARLEN_BPABUS];		//	7	14	A8		ĸ������1
	float		fkVI;							//	15	18	F4.0	��׼��ѹ1(kV)
	char		szBusJ[MDB_CHARLEN_BPABUS];		//	20	27	A8		ĸ������2
	float		fkVJ;							//	28	31	F4.0	��׼��ѹ2(kV)
	char		cLoop;							//	32	32	A1		������·�Ļ�·��־
	float		fFTrip;
	float		fTRelay;
	float		fTTrip;
	float		fTDelay;
	char		szKeyName[MDB_CHARLEN_SHORT];
}	DISALIGN;
typedef	struct	_BpaMDBSwi_RU_	tagBpaSwi_RU;


//	���ݿ����ض���
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
	BPA_DAT_EDGEACLINE,
	BPA_DAT_EDGEWIND,
	BPA_DAT_EDGELINEHG,
	BPA_DAT_EDGEDCLINE,
	BPA_DAT_EDGER,
	BPA_DAT_RADIATE,
	BPA_SCC_FMOVE,
	BPA_SWI_CASE,
	BPA_SWI_F1,
	BPA_SWI_F0,
	BPA_SWI_FF,
	BPA_SWI_GEN,
	BPA_SWI_DAMP,
	BPA_SWI_WGEGEN,
	BPA_SWI_WGWGEN,
	BPA_SWI_PV,
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
	BPA_SWI_DT,
	BPA_SWI_DF,
	BPA_SWI_DM,
	BPA_SWI_DN,
	BPA_SWI_DA,
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
const	int	MaxBpaDatEdgeACLine			=MaxBpaDatACLine*2;
const	int	MaxBpaDatEdgeWind			=MaxBpaDatWind*2;
const	int	MaxBpaDatEdgeLineHG			=MaxBpaDatLineHG*2;
const	int	MaxBpaDatEdgeDCLine			=MaxBpaDatDCLine*2;
const	int	MaxBpaDatEdgeR				=MaxBpaDatR*2;
const	int	MaxBpaDatRadiate			=8000;
const	int	MaxBpaSccFMove				=100;

const	int	MaxBpaSwiGen				=6400;
const	int	MaxBpaSwiDamp				=MaxBpaSwiGen;
const	int	MaxBpaSwiWGEGen				=2000;
const	int	MaxBpaSwiWGWGen				=1000;
const	int	MaxBpaSwiPV					=1000;
const	int	MaxBpaSwiGENLN				=500;
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
const	int MaxBpaSwiDT					=MaxBpaDatDCBus;
const	int MaxBpaSwiDF					=MaxBpaDatDCBus;
const	int MaxBpaSwiDM					=MaxBpaDatDCBus;
const	int MaxBpaSwiDN					=MaxBpaDatDCBus;
const	int MaxBpaSwiDA					=MaxBpaDatDCBus;

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

const	int	BpaDatEdgeACLine_Offset		=(BpaDatTran_Offset			+MaxBpaDatTran		*sizeof(tagBpaDat_Tran));
const	int	BpaDatEdgeWind_Offset		=(BpaDatEdgeACLine_Offset	+MaxBpaDatEdgeACLine*sizeof(tagBpaDat_EdgeACLine));
const	int BpaDatEdgeLineHG_Offset		=(BpaDatEdgeWind_Offset		+MaxBpaDatEdgeWind	*sizeof(tagBpaDat_EdgeWind));
const	int	BpaDatEdgeDCLine_Offset		=(BpaDatEdgeLineHG_Offset	+MaxBpaDatEdgeLineHG*sizeof(tagBpaDat_EdgeLineHG));
const	int	BpaDatEdgeR_Offset			=(BpaDatEdgeDCLine_Offset	+MaxBpaDatEdgeDCLine*sizeof(tagBpaDat_EdgeDCLine));
const	int BpaDatRadiate_Offset		=(BpaDatEdgeR_Offset		+MaxBpaDatEdgeR		*sizeof(tagBpaDat_EdgeR));

const	int BpaSccFMove_Offset			=(BpaDatRadiate_Offset		+MaxBpaDatRadiate	*sizeof(tagBpaDat_Radiate));

const	int BpaSwiCase_Offset			=(BpaSccFMove_Offset		+MaxBpaSccFMove		*sizeof(tagBpaScc_FMove));
const	int	BpaSwiF1_Offset				=(BpaSwiCase_Offset			+MaxBpaSwiCase		*sizeof(tagBpaSwi_Case));
const	int	BpaSwiF0_Offset				=(BpaSwiF1_Offset			+MaxBpaSwiF1		*sizeof(tagBpaSwi_F1));
const	int	BpaSwiFF_Offset				=(BpaSwiF0_Offset			+MaxBpaSwiF0		*sizeof(tagBpaSwi_F0));

const	int	BpaSwiGen_Offset			=(BpaSwiFF_Offset			+MaxBpaSwiFF		*sizeof(tagBpaSwi_FF));
const	int	BpaSwiDamp_Offset			=(BpaSwiGen_Offset			+MaxBpaSwiGen		*sizeof(tagBpaSwi_Gen));
const	int	BpaSwiWGEGen_Offset			=(BpaSwiDamp_Offset			+MaxBpaSwiDamp		*sizeof(tagBpaSwi_Damp));
const	int	BpaSwiWGWGen_Offset			=(BpaSwiWGEGen_Offset		+MaxBpaSwiWGEGen	*sizeof(tagBpaSwi_WGEGen));
const	int	BpaSwiPV_Offset				=(BpaSwiWGWGen_Offset		+MaxBpaSwiWGWGen	*sizeof(tagBpaSwi_WGWGen));
const	int	BpaSwiGenLN_Offset			=(BpaSwiPV_Offset			+MaxBpaSwiPV		*sizeof(tagBpaSwi_PV));

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
const	int BpaSwiDT_Offset				=(BpaSwiD_Offset			+MaxBpaSwiD			*sizeof(tagBpaSwi_D));
const	int BpaSwiDF_Offset				=(BpaSwiDT_Offset			+MaxBpaSwiDT		*sizeof(tagBpaSwi_DT));
const	int BpaSwiDM_Offset				=(BpaSwiDF_Offset			+MaxBpaSwiDF		*sizeof(tagBpaSwi_DF));
const	int BpaSwiDN_Offset				=(BpaSwiDM_Offset			+MaxBpaSwiDM		*sizeof(tagBpaSwi_DM));
const	int BpaSwiDA_Offset				=(BpaSwiDN_Offset			+MaxBpaSwiDN		*sizeof(tagBpaSwi_DN));

const	int BpaSwiV_Offset				=(BpaSwiDA_Offset			+MaxBpaSwiDA		*sizeof(tagBpaSwi_DA));
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

//	������Ҫע�����RESTRICT�еĹؼ��ֱ���ΪCHAR���������CHAR��ͨ��CHARҲ�ܱȽ�
//	�ֵ������


//	BPA�����
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
	{	"B",	"+",	"",		BpaDatCategory_Dat, BpaDatCategory_Dat, BpaSwiCategory_Dat, },
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
	{	"DM",	"DMZ",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"DN",	"DNZ",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
	{	"DA",	"DAZ",	"",		BpaSwiCategory_Dat, BpaSwiCategory_Dat, BpaSwiCategory_Dat, },
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
