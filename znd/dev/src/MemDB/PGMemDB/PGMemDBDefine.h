#pragma	once

#include	"../include/MDBDefine.h"

#define		GIS701StandardSupport
//#define		PGProtSettingDefine

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

#include "PGMemDBDefine_Enum.h"

//////////////////////////////////////////////////////////////////////////
//	数据库字段相关定义
enum	_PGEnum_Field_BaseVoltage_	{
	PG_BASEVOLTAGE_RESOURCEID=0,
	PG_BASEVOLTAGE_NAME,
	PG_BASEVOLTAGE_NOMINALVOLTAGE,
	PG_BASEVOLTAGE_LOWVLIMIT,
	PG_BASEVOLTAGE_HIGVHLIMIT,
	PG_BASEVOLTAGE_SCALIMIT,
	PG_BASEVOLTAGE_DC,
};
struct	_PG_BaseVoltage_	{
	char	szResID[MDB_CHARLEN];
	char	szName[MDB_CHARLEN_SHORT];
	float	nominalVoltage;
	float	lowVLimit;
	float	highVLimit;
	float	scALimit;
	unsigned char	bDC;
}	DISALIGN;
typedef	struct	_PG_BaseVoltage_	tagPGBaseVoltage;

enum	_PGEnum_Field_TapChanger_	{
	PG_TAPCHANGER_RESOURCEID=0,
	PG_TAPCHANGER_NAME,
	PG_TAPCHANGER_DESC,
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
	PG_SYSTEM_DESC,
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
	PG_COMPANY_DESC,
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
	PG_SUBCONTROLAREA_DESC,
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
	PG_SUBSTATION_DESC,
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
	PG_SUBSTATION_ELECTRONICTRANSFORMERRANGE,
	PG_SUBSTATION_ADCONVERTERRANGE,
	PG_SUBSTATION_DDCONVERTERRANGE,

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

	short	nElectronicTransformerRange;
	short	nADConverterRange;
	short	nDDConverterRange;

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
	PG_VOLTAGELEVEL_DESC,
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

	PG_VOLTAGELEVEL_DCBUSBARSECTIONRANGE,
	PG_VOLTAGELEVEL_DCBREAKERRANGE,
	PG_VOLTAGELEVEL_DCSHORTCIRCUITLIMITRANGE,

	PG_VOLTAGELEVEL_CONNECTIVITYNODERANGE,
	//PG_VOLTAGELEVEL_TERMINALRANGE,
	PG_VOLTAGELEVEL_DC,
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

	short	nDCBusbarSectionRange;
	short	nDCBreakerRange;
	short	nDCShortCircuitLimitRange;

	int		nConnecivityNodeRange;
	//int	nTerminalRange;
	unsigned char	bDC;
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
	PG_BUSBARSECTION_DESC,
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
	PG_BUSBARSECTION_SCI1,
	PG_BUSBARSECTION_SCI2,
	PG_BUSBARSECTION_SCI0,
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
	float	fScI1;
	float	fScI2;
	float	fScI0;
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
	PG_LINE_DESC,
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
	PG_ACLINESEGMENT_DESC,
	PG_ACLINESEGMENT_ISUBSTATION,
	PG_ACLINESEGMENT_JSUBSTATION,
	PG_ACLINESEGMENT_IVOLTAGELEVEL,
	PG_ACLINESEGMENT_JVOLTAGELEVEL,
	PG_ACLINESEGMENT_LINE,
	//PG_ACLINESEGMENT_ITERMINAL,
	//PG_ACLINESEGMENT_JTERMINAL,
	PG_ACLINESEGMENT_CONNECTIVITYNODEI,
	PG_ACLINESEGMENT_CONNECTIVITYNODEJ,
	PG_ACLINESEGMENT_VACANT,
	PG_ACLINESEGMENT_LINETYPE,
	PG_ACLINESEGMENT_LINEMODEL,
	PG_ACLINESEGMENT_AUTOLENGTH,
	PG_ACLINESEGMENT_LENGTH,
	PG_ACLINESEGMENT_RATECUR,
	PG_ACLINESEGMENT_RATEMVA,

	PG_ACLINESEGMENT_UNITR,
	PG_ACLINESEGMENT_UNITX,
	PG_ACLINESEGMENT_UNITG,
	PG_ACLINESEGMENT_UNITB,

	PG_ACLINESEGMENT_R,
	PG_ACLINESEGMENT_X,
	PG_ACLINESEGMENT_G,
	PG_ACLINESEGMENT_B,
	PG_ACLINESEGMENT_R0,
	PG_ACLINESEGMENT_X0,
	PG_ACLINESEGMENT_B0,

	PG_ACLINESEGMENT_ISTATUS,
	PG_ACLINESEGMENT_ZSTATUS,

	PG_ACLINESEGMENT_RI_UNITRERR,
	PG_ACLINESEGMENT_RI_UNITTREP,
	PG_ACLINESEGMENT_RI_UNITRCHK,
	PG_ACLINESEGMENT_RI_UNITTCHK,

	PG_ACLINESEGMENT_RI_RERR,
	PG_ACLINESEGMENT_RI_TREP,
	PG_ACLINESEGMENT_RI_RCHK,
	PG_ACLINESEGMENT_RI_TCHK,
	PG_ACLINESEGMENT_RI_TFLOC,
	PG_ACLINESEGMENT_RI_TSWITCH,
	PG_ACLINESEGMENT_RI_TDELAY,
	PG_ACLINESEGMENT_RI_CUSTOMER,
	PG_ACLINESEGMENT_RI_DIRECTION,

	PG_ACLINESEGMENT_EI_UNITINVEST,
	PG_ACLINESEGMENT_EI_INVEST,
	PG_ACLINESEGMENT_EI_CONSTLOSS,
	PG_ACLINESEGMENT_EI_EVALRATIO,

	PG_ACLINESEGMENT_LOADSIDE,
	PG_ACLINESEGMENT_LINELOADP,
	PG_ACLINESEGMENT_LINELOADFACTOR,
	PG_ACLINESEGMENT_LINECAP,
	PG_ACLINESEGMENT_SERIESCAP,
	PG_ACLINESEGMENT_HEATINGLOAD,
	PG_ACLINESEGMENT_REFRIGERATIONLOAD,

	PG_ACLINESEGMENT_RI_LOAD_RERR,
	PG_ACLINESEGMENT_RI_LOAD_TREP,
	PG_ACLINESEGMENT_RI_LOAD_RCHK,
	PG_ACLINESEGMENT_RI_LOAD_TCHK,

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
	PG_ACLINESEGMENT_TRUNKLINE,
	PG_ACLINESEGMENT_OPEN,
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
	unsigned char	nLineVacant;
	unsigned char	nLineType;
	char	szLineModel[MDB_CHARLEN_SHORT];
	unsigned char	bAutoLength;
	float	fLength;
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

	unsigned char	iStatus;
	unsigned char	zStatus;

	//	可靠性输入数据
	float	ri_UnitRerr;
	float	ri_UnitTrep;
	float	ri_UnitRchk;
	float	ri_UnitTchk;

	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ri_TSwitch;
	float	ri_TDelay;
	float	ri_Customer;
	unsigned char	ri_Direction;

	//	经济性输入数据
	float	ei_UnitInvest;
	float	ei_Invest;
	float	ei_constloss;
	float	ei_evalratio;

	//	线路所挂接负荷
	unsigned char	bLoadSide;
	float	fLoadP;
	float	fLoadFactor;
	float	fLineCap;
	float	fSeriesCap;
	float	fHeatingLoad;
	float	fRefrigerationLoad;

	float	ri_load_rerr;
	float	ri_load_trep;
	float	ri_load_rchk;
	float	ri_load_tchk;

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
	float	fPj;
	float	fQj;
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
	unsigned char	bTrunkLine;
	unsigned char	bOpen;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_ACLineSegment_	tagPGACLineSegment;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_DCLineSegment_	{
	PG_DCLINESEGMENT_RESOURCEID=0,
	PG_DCLINESEGMENT_NAME,
	PG_DCLINESEGMENT_DESC,
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
	PG_DCLINESEGMENT_RI_RERR,
	PG_DCLINESEGMENT_RI_TREP,
	PG_DCLINESEGMENT_RI_RCHK,
	PG_DCLINESEGMENT_RI_TCHK,
	PG_DCLINESEGMENT_RI_TFLOC,
	PG_DCLINESEGMENT_EI_INVEST,

	PG_DCLINESEGMENT_MCRTYPE,
	PG_DCLINESEGMENT_MCRPOWER,

	PG_DCLINESEGMENT_PI,
	PG_DCLINESEGMENT_PJ,
	PG_DCLINESEGMENT_A,
	PG_DCLINESEGMENT_LOSSP,
	PG_DCLINESEGMENT_RO_RCONTRIBUTION,
	PG_DCLINESEGMENT_RO_UCONTRIBUTION,
	PG_DCLINESEGMENT_RO_ENSCONTRIBUTION,
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
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;

	//	主接线可靠性
	unsigned char	nMCRType;
	float			fMCRPower;

	//	输出数据
	float	fPi;
	float	fPj;
	float	fA;
	float	fLossP;
	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;
	//	辅助数据
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
	PG_POWERTRANSFORMER_DESC,
	PG_POWERTRANSFORMER_WINDNUM,
	PG_POWERTRANSFORMER_VOLTAGELEVELH,
	PG_POWERTRANSFORMER_VOLTAGELEVELM,
	PG_POWERTRANSFORMER_VOLTAGELEVELL,
	PG_POWERTRANSFORMER_VOLTAGELEVELT,
	PG_POWERTRANSFORMER_TRANSFORMERWINDINGH,
	PG_POWERTRANSFORMER_TRANSFORMERWINDINGM,
	PG_POWERTRANSFORMER_TRANSFORMERWINDINGL,
	PG_POWERTRANSFORMER_CONNECTIVITYNODEH,
	PG_POWERTRANSFORMER_CONNECTIVITYNODEM,
	PG_POWERTRANSFORMER_CONNECTIVITYNODEL,
	PG_POWERTRANSFORMER_CONNECTIVITYNODET,
	PG_POWERTRANSFORMER_RI_RERR,
	PG_POWERTRANSFORMER_RI_TREP,
	PG_POWERTRANSFORMER_RI_RCHK,
	PG_POWERTRANSFORMER_RI_TCHK,
	PG_POWERTRANSFORMER_RI_TFLOC,
	PG_POWERTRANSFORMER_EI_INVEST,
	PG_POWERTRANSFORMER_RO_RCONTRIBUTION,	
	PG_POWERTRANSFORMER_RO_UCONTRIBUTION,	
	PG_POWERTRANSFORMER_RO_ENSCONTRIBUTION,	
	PG_POWERTRANSFORMER_TOPOBUSH,
	PG_POWERTRANSFORMER_TOPOBUSM,
	PG_POWERTRANSFORMER_TOPOBUSL,
	PG_POWERTRANSFORMER_TOPOBUST,
	PG_POWERTRANSFORMER_VOLTHPTR,
	PG_POWERTRANSFORMER_VOLTMPTR,
	PG_POWERTRANSFORMER_VOLTLPTR,
	PG_POWERTRANSFORMER_VOLTTPTR,
	PG_POWERTRANSFORMER_WINDHPTR,
	PG_POWERTRANSFORMER_WINDMPTR,
	PG_POWERTRANSFORMER_WINDLPTR,
	PG_POWERTRANSFORMER_NODEHPTR,
	PG_POWERTRANSFORMER_NODEMPTR,
	PG_POWERTRANSFORMER_NODELPTR,
	PG_POWERTRANSFORMER_NODETPTR,
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
	char	szVoltT[MDB_CHARLEN_SHORTER];
	char	szWindH[MDB_CHARLEN];
	char	szWindM[MDB_CHARLEN];
	char	szWindL[MDB_CHARLEN];
	char	szNodeH[PGND_CHARLEN];
	char	szNodeM[PGND_CHARLEN];
	char	szNodeL[PGND_CHARLEN];
	char	szNodeT[PGND_CHARLEN];
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;
	float	ro_RContribution;
	float	ro_UContribution;
	float	ro_ENSContribution;
	int		nTopoBusH;
	int		nTopoBusM;
	int		nTopoBusL;
	int		nTopoBusT;
	short	nVoltH;
	short	nVoltM;
	short	nVoltL;
	short	nVoltT;
	short	nWindH;
	short	nWindM;
	short	nWindL;
	int		nNodeH;
	int		nNodeM;
	int		nNodeL;
	int		nNodeT;
	unsigned char	nState;
	unsigned char	bOpen;
}	DISALIGN;
typedef	struct	_PG_PowerTransformer_	tagPGPowerTransformer;

enum	_PGEnum_Field_TransformerWinding_	{
	PG_TRANSFORMERWINDING_RESOURCEID=0,
	PG_TRANSFORMERWINDING_OBJECTID,
	PG_TRANSFORMERWINDING_SUBSTATION,
	PG_TRANSFORMERWINDING_NAME,
	PG_TRANSFORMERWINDING_DESC,
	PG_TRANSFORMERWINDING_VOLTAGELEVELI,
	PG_TRANSFORMERWINDING_VOLTAGELEVELJ,
	PG_TRANSFORMERWINDING_POWERTRANSFORMER,
	PG_TRANSFORMERWINDING_TAPCHANGERI,
	PG_TRANSFORMERWINDING_TAPCHANGERJ,
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
	PG_TRANSFORMERWINDING_TAPI,
	PG_TRANSFORMERWINDING_TAPJ,
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
	PG_TRANSFORMERWINDING_RI_DIRECTION,

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

	PG_TRANSFORMERWINDING_MCRTYPEI,
	PG_TRANSFORMERWINDING_MCRTYPEJ,
	PG_TRANSFORMERWINDING_MCRPOWER,

	PG_TRANSFORMERWINDING_PI,
	PG_TRANSFORMERWINDING_QI,
	PG_TRANSFORMERWINDING_AI,
	PG_TRANSFORMERWINDING_PJ,
	PG_TRANSFORMERWINDING_QJ,
	PG_TRANSFORMERWINDING_AJ,
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
	char	szPowerTransformer[MDB_CHARLEN];
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
	unsigned char	ri_Direction;

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
	unsigned char	nMCRTypeI;
	unsigned char	nMCRTypeJ;
	float			fMCRPower;

	//	输出数据
	float	fPi;
	float	fQi;
	float	fAi;
	float	fPj;
	float	fQj;
	float	fAj;
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
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_TransformerWinding_	tagPGTransformerWinding;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_RectifierInverter_	{
	PG_RECTIFIERINVERTER_RESOURCEID=0,
	PG_RECTIFIERINVERTER_SUBSTATION,
	PG_RECTIFIERINVERTER_NAME,
	PG_RECTIFIERINVERTER_DESC,
	PG_RECTIFIERINVERTER_VOLTAGELEVELAC,
	PG_RECTIFIERINVERTER_VOLTAGELEVELDC,
	//PG_RECTIFIERINVERTER_TERMINALAC,
	//PG_RECTIFIERINVERTER_TERMINALDCP,
	//PG_RECTIFIERINVERTER_TERMINALDCN,
	PG_RECTIFIERINVERTER_CONNECTIVITYNODEAC,
	PG_RECTIFIERINVERTER_CONNECTIVITYNODEDCP,
	PG_RECTIFIERINVERTER_CONNECTIVITYNODEDCN,
	PG_RECTIFIERINVERTER_BRIDGES,
	PG_RECTIFIERINVERTER_P,
	PG_RECTIFIERINVERTER_Q,
	PG_RECTIFIERINVERTER_VOLTACPTR,
	PG_RECTIFIERINVERTER_VOLTDCPTR,
	PG_RECTIFIERINVERTER_NODEACPTR,
	PG_RECTIFIERINVERTER_NODEDCPPTR,
	PG_RECTIFIERINVERTER_NODEDCNPTR,
	PG_RECTIFIERINVERTER_TOPOBUSAC,
	PG_RECTIFIERINVERTER_TOPOBUSDCP,
	PG_RECTIFIERINVERTER_TOPOBUSDCN,
	PG_RECTIFIERINVERTER_ISLAND,
	PG_RECTIFIERINVERTER_OPEN,
	PG_RECTIFIERINVERTER_OUTAGE,
};
struct	_PG_RectifierInverter_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szName[MDB_CHARLEN];
	char	szDesp[MDB_CHARLEN];

	char	szVoltAC[MDB_CHARLEN_SHORTER];
	char	szVoltDC[MDB_CHARLEN_SHORTER];
	//char	szTerminalAC[PGND_CHARLEN];
	//char	szTerminalDCP[PGND_CHARLEN];
	//char	szTerminalDCN[PGND_CHARLEN];
	char	szNodeAC[PGND_CHARLEN];
	char	szNodeDCP[PGND_CHARLEN];
	char	szNodeDCN[PGND_CHARLEN];

	unsigned char	nBridges;

	float	fP;
	float	fQ;

	short	nVoltAC;
	short	nVoltDC;
	int		nNodeAC;
	int		nNodeDCP;
	int		nNodeDCN;
	int		nTopBusAC;
	int		nTopBusDCP;
	int		nTopBusDCN;
	short	nIslandAC;
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
	PG_SYNCHRONOUSMACHINE_DESC,
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
	PG_SYNCHRONOUSMACHINE_SCI1,
	PG_SYNCHRONOUSMACHINE_SCI2,
	PG_SYNCHRONOUSMACHINE_SCI0,

	PG_SYNCHRONOUSMACHINE_SCVA,
	PG_SYNCHRONOUSMACHINE_SCVB,
	PG_SYNCHRONOUSMACHINE_SCVC,
	PG_SYNCHRONOUSMACHINE_SCV1,
	PG_SYNCHRONOUSMACHINE_SCV2,
	PG_SYNCHRONOUSMACHINE_SCV0,

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
	char			szTDCurve[MDB_CHARLEN_SHORT];

	float	fP;
	float	fQ;
	float	fA;
	float	fV;
	float	fD;
	float	fFactor;

	float	fScIa;
	float	fScIb;
	float	fScIc;
	float	fScI1;
	float	fScI2;
	float	fScI0;
	float	fScVa;
	float	fScVb;
	float	fScVc;
	float	fScV1;
	float	fScV2;
	float	fScV0;

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
	PG_ENERGYCONSUMER_DESC,
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

	char	szSModel[MDB_CHARLEN_SHORT];
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

	unsigned char	nMCRType;
	char			szTWDCurve[MDB_CHARLEN_SHORT];
	char			szTHDCurve[MDB_CHARLEN_SHORT];

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
	PG_LOADMODEL_DESC,
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
	PG_SHUNTCOMPENSATOR_DESC,
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
	PG_SERIESCOMPENSATOR_DESC,
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
	PG_SERIESCOMPENSATOR_PJ,
	PG_SERIESCOMPENSATOR_QJ,
	PG_SERIESCOMPENSATOR_A,
	PG_SERIESCOMPENSATOR_LOSSP,
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
	float	fPj;
	float	fQj;
	float	fA;
	float	fLossP;
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
	short	nEdgeI;
	short	nEdgeJ;
	unsigned char	bDistribution;
	unsigned char	nState;
	unsigned char	bOpen;
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
	PG_BREAKER_DESC,
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
	PG_BREAKER_RI_TSWITCH,
	PG_BREAKER_RI_RRSWH,
	PG_BREAKER_RI_RESWH,
	PG_BREAKER_RI_DIRECTION,
	PG_BREAKER_EI_INVEST,
	PG_BREAKER_MCRCHKBUS,
	PG_BREAKER_P,
	PG_BREAKER_Q,
	PG_BREAKER_A,
	PG_BREAKER_SCCAI,
	PG_BREAKER_SCCAJ,
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
	float	ri_TSwitch;
	float	ri_Rrswh;
	float	ri_Reswh;
	unsigned char	ri_Direction;

	//	经济性输入数据
	float	ei_Invest;

	//	主接线可靠性，设备检修需要停母线
	unsigned char	bMCRChkBus;

	float	fP;
	float	fQ;
	float	fA;

	float	fSccAi;
	float	fSccAj;

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
	PG_DISCONNECTOR_DESC,
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
	PG_GROUNDDISCONNECTOR_DESC,
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
	PG_THERMALENERGYCONSUMER_DESC,
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
enum	_PGEnum_Field_WindTurbine_	{
	PG_WINDTURBINE_RESOURCEID=0,
	PG_WINDTURBINE_SUBSTATION,
	PG_WINDTURBINE_VOLTAGELEVEL,
	PG_WINDTURBINE_NAME,
	PG_WINDTURBINE_CONNECTIVITYNODE,
	PG_WINDTURBINE_RATEDMVA,
	PG_WINDTURBINE_PLANP,
	PG_WINDTURBINE_PLANQ,
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
	PG_WINDTURBINE_TDCURVE,
	PG_WINDTURBINE_P,
	PG_WINDTURBINE_Q,
	PG_WINDTURBINE_A,
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
	PG_WINDTURBINE_NODEPTR,
	PG_WINDTURBINE_TOPOBUS,
	PG_WINDTURBINE_ISLAND,
	PG_WINDTURBINE_OUTAGE,
};

struct	_PG_WindTurbine_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szNode[PGND_CHARLEN];
	float	fRatedMva;
	float	fPlanP;
	float	fPlanQ;
	float	cutin_windspeed;
	float	cutout_windspeed;
	float	rate_windspeed;
	float	rate_power;
	float	mean_windspeed;
	float	stddev_windspeed;
	unsigned char	state_num;
	float	vd_RScc1;	//	电压暂降评估输入数据
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;
	char	szTDCurve[MDB_CHARLEN_SHORT];
	float	fP;
	float	fQ;
	float	fA;
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
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_WindTurbine_	tagPGWindTurbine;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_PhotoVoltaic_	{
	PG_PHOTOVOLTAIC_RESOURCEID=0,
	PG_PHOTOVOLTAIC_SUBSTATION,
	PG_PHOTOVOLTAIC_VOLTAGELEVEL,
	PG_PHOTOVOLTAIC_NAME,
	PG_PHOTOVOLTAIC_CONNECTIVITYNODE,
	PG_PHOTOVOLTAIC_RATEDMVA,
	PG_PHOTOVOLTAIC_PLANP,
	PG_PHOTOVOLTAIC_PLANQ,
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
	PG_PHOTOVOLTAIC_TDCURVE,
	PG_PHOTOVOLTAIC_P,
	PG_PHOTOVOLTAIC_Q,
	PG_PHOTOVOLTAIC_A,
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
	PG_PHOTOVOLTAIC_NODEPTR,
	PG_PHOTOVOLTAIC_TOPOBUS,
	PG_PHOTOVOLTAIC_ISLAND,
	PG_PHOTOVOLTAIC_OUTAGE,
};

struct	_PG_PhotoVoltaic_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	char	szNode[PGND_CHARLEN];
	float	fRatedMva;
	float	fPlanP;
	float	fPlanQ;
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
	float	vd_RScc1;	//	电压暂降评估输入数据
	float	vd_RScc2;
	float	vd_RScc3;
	float	vd_RScc4;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;
	char	szTDCurve[MDB_CHARLEN_SHORT];
	float	fP;
	float	fQ;
	float	fA;
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
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_PhotoVoltaic_	tagPGPhotoVoltaic;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_EVStation_	{
	PG_EVSTATION_RESOURCEID=0,
	PG_EVSTATION_SUBSTATION,
	PG_EVSTATION_VOLTAGELEVEL,
	PG_EVSTATION_NAME,
	PG_EVSTATION_STATIONTYPE,
	PG_EVSTATION_LANDTYPE,
	PG_EVSTATION_SERVICEGROUP,
	PG_EVSTATION_RATEDCAPACITY,
	PG_EVSTATION_RATEDDAILYVISITOR,
	PG_EVSTATION_UNDERCONTROL,
	PG_EVSTATION_CONNECTIVITYNODE,
	PG_EVSTATION_PILEMODEL,
	PG_EVSTATION_PILENUMBER,
	PG_EVSTATION_BATTERYSTOCK,
	PG_EVSTATION_BATTERYCAPACITY,
	PG_EVSTATION_BATTERYPOWER,
	PG_EVSTATION_CHARGEEFFICIENCY,
	PG_EVSTATION_CHARGEFACTOR,
	PG_EVSTATION_PLANP,
	PG_EVSTATION_PLANQ,
	PG_EVSTATION_EI_INVEST,
	PG_EVSTATION_EI_AUXINVEST,
	PG_EVSTATION_EI_LANDINVEST,
	PG_EVSTATION_EI_CONSTLOSS,
	PG_EVSTATION_EI_EVALRATIO,
	PG_EVSTATION_TWDCURVE,
	PG_EVSTATION_THDCURVE,
	PG_EVSTATION_P,
	PG_EVSTATION_Q,
	PG_EVSTATION_A,
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
	PG_EVSTATION_NODEPTR,
	PG_EVSTATION_TOPOBUS,
	PG_EVSTATION_ISLAND,
	PG_EVSTATION_OUTAGE,
};

struct	_PG_EVStation_	{
	char	szResID[MDB_CHARLEN];
	char	szSub[MDB_CHARLEN];
	char	szVolt[MDB_CHARLEN_SHORTER];
	char	szName[MDB_CHARLEN];
	unsigned char	nStationType;
	unsigned char	nLandType;
	unsigned char	nServiceGroup;
	float	fRatedCapacity;
	short	nRatedDailyVisitor;
	unsigned char	bUnderControl;
	char	szNode[PGND_CHARLEN];
	char	szPileModel[MDB_CHARLEN];
	short	nPileNumber;
	short	nBatteryStock;
	float	fBatteryCapacity;
	float	fBatteryPower;
	float	fChargeEfficiency;
	float	fChargeFactor;
	float	fPlanP;
	float	fPlanQ;
	float	ei_Invest;
	float	ei_AuxInvest;
	float	ei_LandInvest;
	float	ei_constloss;
	float	ei_evalratio;
	char	szTWDCurve[MDB_CHARLEN_SHORT];
	char	szTHDCurve[MDB_CHARLEN_SHORT];
	float	fP;
	float	fQ;
	float	fA;
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
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_EVStation_	tagPGEVStation;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ElectroChemicalEnergyStorage_	{
	PG_ELECTROCHEMICALENERGYSTORAGE_RESOURCEID=0,
	PG_ELECTROCHEMICALENERGYSTORAGE_OBJECTID,
	PG_ELECTROCHEMICALENERGYSTORAGE_SUBSTATION,
	PG_ELECTROCHEMICALENERGYSTORAGE_VOLTAGELEVEL,
	PG_ELECTROCHEMICALENERGYSTORAGE_NAME,
	PG_ELECTROCHEMICALENERGYSTORAGE_DESC,
	PG_ELECTROCHEMICALENERGYSTORAGE_CONNECTIVITYNODE,
	PG_ELECTROCHEMICALENERGYSTORAGE_TYPE,
	PG_ELECTROCHEMICALENERGYSTORAGE_RATEDCAPACITY,
	PG_ELECTROCHEMICALENERGYSTORAGE_RATEDPOWER,
	PG_ELECTROCHEMICALENERGYSTORAGE_PLANP,
	PG_ELECTROCHEMICALENERGYSTORAGE_PLANQ,
	PG_ELECTROCHEMICALENERGYSTORAGE_RATEDVOC,
	PG_ELECTROCHEMICALENERGYSTORAGE_LIFECYCLE,
	PG_ELECTROCHEMICALENERGYSTORAGE_EFFC,
	PG_ELECTROCHEMICALENERGYSTORAGE_EFFD,
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_RERR,
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_TREP,
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_RCHK,
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_TCHK,
	PG_ELECTROCHEMICALENERGYSTORAGE_RI_TFLOC,
	PG_ELECTROCHEMICALENERGYSTORAGE_EI_INVEST,
	PG_ELECTROCHEMICALENERGYSTORAGE_WORKMODECURVE,
	PG_ELECTROCHEMICALENERGYSTORAGE_CAPACITYCURVE,
	PG_ELECTROCHEMICALENERGYSTORAGE_P,
	PG_ELECTROCHEMICALENERGYSTORAGE_Q,
	PG_ELECTROCHEMICALENERGYSTORAGE_A,
	PG_ELECTROCHEMICALENERGYSTORAGE_V,
	PG_ELECTROCHEMICALENERGYSTORAGE_SCC,
	PG_ELECTROCHEMICALENERGYSTORAGE_SA_RESULT,
	PG_ELECTROCHEMICALENERGYSTORAGE_SA_ISLAND,
	PG_ELECTROCHEMICALENERGYSTORAGE_SA_FAILURE,
	PG_ELECTROCHEMICALENERGYSTORAGE_SA_OUTAGES,
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
	float	fRatedCapacity;
	float	fRatedPower;
	float	fPlanP;
	float	fPlanQ;
	float	fRatedVoc;
	float	fLifeCycle;
	float	fEffc;
	float	fEffd;
	float	ri_Rerr;
	float	ri_Trep;
	float	ri_Rchk;
	float	ri_Tchk;
	float	ri_Tfloc;
	float	ei_Invest;
	char	szWorkModeCurve[MDB_CHARLEN_SHORT];
	char	szCapacityCurve[MDB_CHARLEN_SHORT];
	float	fP;
	float	fQ;
	float	fA;
	float	fV;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_ElectroChemicalEnergyStorage_		tagPGElectroChemicalEnergyStorage;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_SolarThermalMachine_	{
	PG_SOLARTHERMALMACHINE_RESOURCEID=0,
	PG_SOLARTHERMALMACHINE_OBJECTID,
	PG_SOLARTHERMALMACHINE_SUBSTATION,
	PG_SOLARTHERMALMACHINE_VOLTAGELEVEL,
	PG_SOLARTHERMALMACHINE_NAME,
	PG_SOLARTHERMALMACHINE_DESC,
	PG_SOLARTHERMALMACHINE_CONNECTIVITYNODE,
	PG_SOLARTHERMALMACHINE_RATEDPOWER,
	PG_SOLARTHERMALMACHINE_RATEDCAPACITY,
	PG_SOLARTHERMALMACHINE_PLANP,
	PG_SOLARTHERMALMACHINE_PLANQ,
	PG_SOLARTHERMALMACHINE_EI_INVEST,
	PG_SOLARTHERMALMACHINE_RATEDVOC,
	PG_SOLARTHERMALMACHINE_LIFECYCLE,
	PG_SOLARTHERMALMACHINE_EFFC,
	PG_SOLARTHERMALMACHINE_EFFD,
	PG_SOLARTHERMALMACHINE_SOLAR_AREA,
	PG_SOLARTHERMALMACHINE_LUMI_THRESHOLD,
	PG_SOLARTHERMALMACHINE_TRANS_RATE,
	PG_SOLARTHERMALMACHINE_LUMI_MAX1,
	PG_SOLARTHERMALMACHINE_LUMI_MAX2,
	PG_SOLARTHERMALMACHINE_LUMI_MAX3,
	PG_SOLARTHERMALMACHINE_LUMI_MAX4,
	PG_SOLARTHERMALMACHINE_LUMI_MAX5,
	PG_SOLARTHERMALMACHINE_LUMI_MAX6,
	PG_SOLARTHERMALMACHINE_LUMI_MAX7,
	PG_SOLARTHERMALMACHINE_LUMI_MAX8,
	PG_SOLARTHERMALMACHINE_LUMI_MAX9,
	PG_SOLARTHERMALMACHINE_LUMI_MAX10,
	PG_SOLARTHERMALMACHINE_LUMI_MAX11,
	PG_SOLARTHERMALMACHINE_LUMI_MAX12,
	PG_SOLARTHERMALMACHINE_P,
	PG_SOLARTHERMALMACHINE_Q,
	PG_SOLARTHERMALMACHINE_A,
	PG_SOLARTHERMALMACHINE_V,
	PG_SOLARTHERMALMACHINE_D,
	PG_SOLARTHERMALMACHINE_SCC,
	PG_SOLARTHERMALMACHINE_SA_RESULT,
	PG_SOLARTHERMALMACHINE_SA_ISLAND,
	PG_SOLARTHERMALMACHINE_SA_FAILURE,
	PG_SOLARTHERMALMACHINE_SA_OUTAGES,
	PG_SOLARTHERMALMACHINE_STATE_NUM,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER1,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER2,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER3,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER4,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER5,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER6,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER7,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER8,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER9,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER10,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER11,
	PG_SOLARTHERMALMACHINE_OUTPUT_POWER12,
	PG_SOLARTHERMALMACHINE_STATE_PROB1,
	PG_SOLARTHERMALMACHINE_STATE_PROB2,
	PG_SOLARTHERMALMACHINE_STATE_PROB3,
	PG_SOLARTHERMALMACHINE_STATE_PROB4,
	PG_SOLARTHERMALMACHINE_STATE_PROB5,
	PG_SOLARTHERMALMACHINE_STATE_PROB6,
	PG_SOLARTHERMALMACHINE_STATE_PROB7,
	PG_SOLARTHERMALMACHINE_STATE_PROB8,
	PG_SOLARTHERMALMACHINE_STATE_PROB9,
	PG_SOLARTHERMALMACHINE_STATE_PROB10,
	PG_SOLARTHERMALMACHINE_STATE_PROB11,
	PG_SOLARTHERMALMACHINE_STATE_PROB12,
	PG_SOLARTHERMALMACHINE_NODEPTR,
	PG_SOLARTHERMALMACHINE_TOPOBUS,
	PG_SOLARTHERMALMACHINE_ISLAND,
	PG_SOLARTHERMALMACHINE_OUTAGE,
};
struct	_PG_SolarThermalMachine_	{
	char	szResID	[MDB_CHARLEN];
	char	szObjID	[MDB_CHARLEN];
	char	szSub	[MDB_CHARLEN];
	char	szVolt	[MDB_CHARLEN_SHORTER];
	char	szName	[MDB_CHARLEN];
	char	szDesp	[MDB_CHARLEN];
	char	szNode	[MDB_CHARLEN];
	float	fRatedChargeDischargePower;
	float	fRatedCapacity;
	float	fPlanP;
	float	fPlanQ;
	float	ei_Invest;
	float	fRatedVoc;
	float	fLifeCycle;
	float	fEffc;
	float	fEffd;
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
	float	fP;
	float	fQ;
	float	fA;
	float	fV;
	float	fD;
	float	fSccA;
	unsigned char	sa_Result;
	unsigned char	sa_Island;
	float	sa_Failure;
	float	sa_Outages;
	unsigned char	state_num;
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
	int		nNode;
	int		nTopoBus;
	short	nIsland;
	unsigned char	bOutage;
}	DISALIGN;
typedef	struct	_PG_SolarThermalMachine_		tagPGSolarThermalMachine;

#include "PGMemDBDefine_Distribution.h"

#include "PGMemDBDefine_DCGrid.h"

#include "PGMemDBDefine_Graph.h"

#ifdef PGProtSettingDefine
#	include "PGMemDBDefine_Relay.h"
#endif

#include "PGMemDBDefine_Misc.h"

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
	PG_SYNCHRONOUSMACHINE,
	PG_ENERGYCONSUMER,
	PG_SHUNTCOMPENSATOR,
	PG_SERIESCOMPENSATOR,
	PG_BREAKER,
	PG_DISCONNECTOR,
	PG_GROUNDDISCONNECTOR,
	PG_RECTIFIERINVERTER,
	PG_GROUNDTRANSFORMER,
	PG_WINDTURBINE,
	PG_PHOTOVOLTAIC,
	PG_EVSTATION,
	PG_ELECTROCHEMICALENERGYSTORAGE,
	PG_SOLARTHERMALMACHINE,
	PG_SUBSTATIONENTITY,
	PG_BRANCHSEGMENT,
	PG_DISTRIBUTIONSWITCH,
	PG_DISTRIBUTIONLOAD,
	PG_DISTRIBUTIONBREAKER,
	PG_DISTRIBUTIONDOT,
	PG_ELECTRONICTRANSFORMER,
	PG_DCBUSBARSECTION,
	PG_ACDCCONVERTER,
	PG_DCDCCONVERTER,
	PG_DCBREAKER,
	PG_DCSHORTCIRCUITLIMIT,
	PG_THERMALENERGYCONSUMER,
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
	PG_EDGEADCONVERTER,
	PG_EDGEDDCONVERTER,
	PG_EDGEDCBREAKER,
	PG_EDGEDCSHORTCIRCUITLIMIT,
	PG_TIELINE,
	PG_ISLAND,
	PG_TOPOBUS,

#ifdef PGProtSettingDefine
	PG_PROTSETTING,
	PG_PROTLINE,
	PG_PROTTRAN,
	PG_PROTBUS,
	PG_PROTGEN,
	PG_PROTCAP,
	PG_PROTREAC,
	PG_PROTMOTOR,
	PG_PROTBREAKER,
#endif

	PG_SYSTEMRELIABLE,
	PG_ENERGYCONSUMERRELIABLE,
	PG_SUBREGION,
	PG_CONNLINE,
	PG_LANDPLOT,
	PG_PIPE,
	PG_HYPERLINK,
	PG_DRAWING,
	PG_GRAPHLAYER,
	PG_GRAPHATTR,
	PG_LINEVERTEX,
	PG_SCCFMOVE,
};

//////////////////////////////////////////////////////////////////////////
//	数据库表相关定义
const	int	g_MDBSizeFactor						=1;

const	int	PG_MaxSystem						=1;
const	int	PG_MaxBaseVoltage					=100;
const	int	PG_MaxCompany						=25;
const	int	PG_MaxSubcontrolArea				=250;
const	int	PG_MaxSubstation					=3600					/g_MDBSizeFactor;
const	int	PG_MaxVoltageLevel					=2*PG_MaxSubstation;
const	int	PG_MaxACLineSegment					=6000					/g_MDBSizeFactor;
const	int	PG_MaxLine							=PG_MaxACLineSegment;
const	int	PG_MaxSynchronousMachine			=2400					/g_MDBSizeFactor;
const	int	PG_MaxEnergyConsumer				=24000					/g_MDBSizeFactor;
const	int	PG_MaxLoadModel						=200					/g_MDBSizeFactor;
const	int	PG_MaxShuntCompensator				=PG_MaxEnergyConsumer/4;
const	int	PG_MaxBreaker						=32000					/g_MDBSizeFactor;
const	int	PG_MaxDisconnector					=48000					/g_MDBSizeFactor;
const	int	PG_MaxGroundDisconnector			=28000					/g_MDBSizeFactor;
const	int	PG_MaxBusbarSection					=PG_MaxVoltageLevel;
const	int	PG_MaxTransformerWinding			=PG_MaxVoltageLevel;;
const	int	PG_MaxPowerTransformer				=3*PG_MaxTransformerWinding/5;
const	int	PG_MaxDCLineSegment					=400;
const	int	PG_MaxRectifierInverter				=2*PG_MaxDCLineSegment;
const	int	PG_MaxSeriesCompensator				=1500;
const	int	PG_MaxGroundTransformer				=200;
const	int	PG_MaxWindTurbine					=500;
const	int	PG_MaxPhotoVoltaic					=500;
const	int	PG_MaxEVStation						=200;
const	int	PG_MaxElectroChemicalEnergyStorage	=120;
const	int	PG_MaxSolarThermalMachine			=10;

const	int	PG_MaxSubstationEntity				=PG_MaxSubstation/20;
const	int	PG_MaxBranchSegment					=PG_MaxACLineSegment/10;
const	int	PG_MaxDistributionSwitch			=1200					/g_MDBSizeFactor;
const	int	PG_MaxDistributionLoad				=2500					/g_MDBSizeFactor;
const	int	PG_MaxDistributionBreaker			=1600					/g_MDBSizeFactor;
const	int	PG_MaxDistributionDot				=1600					/g_MDBSizeFactor;

const	int	PG_MaxElectronicTransformer			=10;
const	int	PG_MaxDCBusbarSection				=400;
const	int	PG_MaxACDCConverter					=200;
const	int	PG_MaxDCDCConverter					=200;
const	int	PG_MaxDCBreaker						=50;
const	int	PG_MaxDCShortCircuitLimit			=20;
const	int	PG_MaxThermalEnergyConsumer			=PG_MaxEnergyConsumer/30;

//const	int	PG_MaxTerminal					=((PG_MaxBusbarSection+2*PG_MaxACLineSegment+2*PG_MaxTransformerWinding+2*PG_MaxBreaker+2*PG_MaxDisconnector+PG_MaxSynchronousMachine+PG_MaxEnergyConsumer+PG_MaxShuntCompensator+2*PG_MaxDCLineSegment+2*PG_MaxRectifierInverter+2*PG_MaxSeriesCompensator)/2);;
//const	int	PG_MaxConnectivityNode			=(3*PG_MaxTerminal/5);
const	int	PG_MaxTerminal					=1;
const	int	PG_MaxConnectivityNode			=(2*(PG_MaxBusbarSection+2*PG_MaxACLineSegment+2*PG_MaxTransformerWinding+2*PG_MaxBreaker+2*PG_MaxDisconnector+2*PG_MaxDCLineSegment+2*PG_MaxRectifierInverter+2*PG_MaxSeriesCompensator)/5);
const	int	PG_MaxTapchanger				=250;
const	int	PG_MaxEdgeACLineSegment			=(2*PG_MaxACLineSegment);
const	int	PG_MaxEdgeDCLineSegment			=(2*PG_MaxDCLineSegment);
const	int	PG_MaxEdgeTransformerWinding	=(2*PG_MaxTransformerWinding);
const	int	PG_MaxEdgeSeriesCompensator		=2*PG_MaxSeriesCompensator;
const	int	PG_MaxEdgeBreaker				=(2*PG_MaxBreaker);
const	int	PG_MaxEdgeDisconnector			=(2*PG_MaxDisconnector);

const	int	PG_MaxEdgeADConverter			=(2*PG_MaxACDCConverter);
const	int	PG_MaxEdgeDDConverter			=(2*PG_MaxDCDCConverter);
const	int	PG_MaxEdgeDCBreaker				=(2*PG_MaxDCBreaker);
const	int	PG_MaxEdgeDCShortCircuitLimit	=(2*PG_MaxDCShortCircuitLimit);

const	int	PG_MaxTieLine					=2500						/g_MDBSizeFactor;

const	int	PG_MaxIsland					=2000						/g_MDBSizeFactor;
const	int	PG_MaxTopoBus					=20000						/g_MDBSizeFactor;

#ifdef PGProtSettingDefine
const	int	PG_MaxProtSetting				=1;
const	int	PG_MaxProtLine					=PG_MaxACLineSegment;
const	int	PG_MaxProtTran					=PG_MaxPowerTransformer;
const	int	PG_MaxProtBus					=PG_MaxBusbarSection/2;
const	int	PG_MaxProtGen					=PG_MaxSynchronousMachine;
const	int	PG_MaxProtCap					=PG_MaxShuntCompensator;
const	int	PG_MaxProtReac					=PG_MaxShuntCompensator/2;
const	int	PG_MaxProtMotor					=PG_MaxEnergyConsumer/10;
const	int	PG_MaxProtBreaker				=PG_MaxSubstation*2;
#endif

const	int	PG_MaxSystemReliable			=15*PG_MaxSystem;
const	int	PG_MaxEnergyConsumerReliable	=2*PG_MaxEnergyConsumer;

const	int	PG_MaxSubRegion					=PG_MaxSubcontrolArea;
const	int	PG_MaxConnLine					=25000						/g_MDBSizeFactor;
const	int	PG_MaxPipe						=250						/g_MDBSizeFactor;
const	int	PG_MaxLandPlot					=10000						/g_MDBSizeFactor;

const	int	PG_MaxDrawing					=100						/g_MDBSizeFactor;
const	int	PG_MaxGraphLayer				=10*PG_MaxDrawing;
const	int	PG_MaxHyperLinks				=5*PG_MaxDrawing;
const	int	PG_MaxGraphAttr					=160*PG_MaxDrawing;
const	int	PG_MaxLineVertex				=100*PG_MaxDrawing;
const	int	PG_MaxSccFMove					=100;

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
const	int	PGSynchronousMachine_Offset				=(PGTransformerWinding_Offset			+PG_MaxTransformerWinding			*sizeof(tagPGTransformerWinding));
const	int	PGEnergyConsumer_Offset					=(PGSynchronousMachine_Offset			+PG_MaxSynchronousMachine			*sizeof(tagPGSynchronousMachine));
const	int	PGShuntCompensator_Offset				=(PGEnergyConsumer_Offset				+PG_MaxEnergyConsumer				*sizeof(tagPGEnergyConsumer));
const	int	PGSeriesCompensator_Offset				=(PGShuntCompensator_Offset				+PG_MaxShuntCompensator				*sizeof(tagPGShuntCompensator));
const	int	PGBreaker_Offset						=(PGSeriesCompensator_Offset			+PG_MaxSeriesCompensator			*sizeof(tagPGSeriesCompensator));
const	int	PGDisconnector_Offset					=(PGBreaker_Offset						+PG_MaxBreaker						*sizeof(tagPGBreaker));
const	int	PGGroundDisconnector_Offset				=(PGDisconnector_Offset					+PG_MaxDisconnector					*sizeof(tagPGDisconnector));
const	int	PGRectifierInverter_Offset				=(PGGroundDisconnector_Offset			+PG_MaxGroundDisconnector			*sizeof(tagPGGroundDisconnector));
const	int	PGGroundTransformer_Offset				=(PGRectifierInverter_Offset			+PG_MaxRectifierInverter			*sizeof(tagPGRectifierInverter));
const	int	PGWindTurbine_Offset					=(PGGroundTransformer_Offset			+PG_MaxGroundTransformer			*sizeof(tagPGGroundTransformer));
const	int	PGPhotoVoltaic_Offset					=(PGWindTurbine_Offset					+PG_MaxWindTurbine					*sizeof(tagPGWindTurbine));
const	int	PGEVStation_Offset						=(PGPhotoVoltaic_Offset					+PG_MaxPhotoVoltaic					*sizeof(tagPGPhotoVoltaic));
const	int	PGElectroChemicalEnergyStorage_Offset	=(PGEVStation_Offset					+PG_MaxEVStation					*sizeof(tagPGEVStation));
const	int	PGSolarThermalMachine_Offset			=(PGElectroChemicalEnergyStorage_Offset	+PG_MaxElectroChemicalEnergyStorage	*sizeof(tagPGElectroChemicalEnergyStorage));

const	int	PGSubstationEntity_Offset				=(PGSolarThermalMachine_Offset			+PG_MaxSolarThermalMachine			*sizeof(tagPGSolarThermalMachine));
const	int	PGBranchSegment_Offset					=(PGSubstationEntity_Offset				+PG_MaxSubstationEntity				*sizeof(tagPGSubstationEntity));
const	int	PGDistributionSwitch_Offset				=(PGBranchSegment_Offset				+PG_MaxBranchSegment				*sizeof(tagPGBranchSegment));
const	int	PGDistributionLoad_Offset				=(PGDistributionSwitch_Offset			+PG_MaxDistributionSwitch			*sizeof(tagPGDistributionSwitch));
const	int	PGDistributionBreaker_Offset			=(PGDistributionLoad_Offset				+PG_MaxDistributionLoad				*sizeof(tagPGDistributionLoad));
const	int	PGDistributionDot_Offset				=(PGDistributionBreaker_Offset			+PG_MaxDistributionBreaker			*sizeof(tagPGDistributionBreaker));

const	int	PGElectronicTransformer_Offset			=(PGDistributionDot_Offset				+PG_MaxDistributionDot				*sizeof(tagPGDistributionDot));
const	int	PGDCBusbarSection_Offset				=(PGElectronicTransformer_Offset			+PG_MaxElectronicTransformer			*sizeof(tagPGElectronicTransformer));
const	int	PGACDCConverter_Offset					=(PGDCBusbarSection_Offset				+PG_MaxDCBusbarSection				*sizeof(tagPGDCBusbarSection));
const	int	PGDCDCConverter_Offset					=(PGACDCConverter_Offset				+PG_MaxACDCConverter				*sizeof(tagPGACDCConverter));
const	int	PGDCBreaker_Offset						=(PGDCDCConverter_Offset					+PG_MaxDCDCConverter					*sizeof(tagPGDCDCConverter));
const	int	PGDCShortCircuitLimit_Offset			=(PGDCBreaker_Offset					+PG_MaxDCBreaker					*sizeof(tagPGDCBreaker));
const	int	PGThermalEnergyConsumer_Offset			=(PGDCShortCircuitLimit_Offset			+PG_MaxDCShortCircuitLimit			*sizeof(tagPGDCShortCircuitLimit));

const	int	PGLoadModel_Offset						=(PGThermalEnergyConsumer_Offset		+PG_MaxThermalEnergyConsumer		*sizeof(tagPGThermalEnergyConsumer));
const	int	PGTapChanger_Offset						=(PGLoadModel_Offset					+PG_MaxLoadModel					*sizeof(tagPGLoadModel));

const	int	PGTerminal_Offset						=(PGTapChanger_Offset					+PG_MaxTapchanger					*sizeof(tagPGTapChanger));
const	int	PGConnectivityNode_Offset				=(PGTerminal_Offset						+PG_MaxTerminal						*sizeof(tagPGTerminal));

const	int	PGEdgeACLineSegment_Offset				=(PGConnectivityNode_Offset				+PG_MaxConnectivityNode				*sizeof(tagPGConnectivityNode));
const	int	PGEdgeDCLineSegment_Offset				=(PGEdgeACLineSegment_Offset			+PG_MaxEdgeACLineSegment			*sizeof(tagPGEdgeACLineSegment));
const	int	PGEdgeTransformerWinding_Offset			=(PGEdgeDCLineSegment_Offset			+PG_MaxEdgeDCLineSegment			*sizeof(tagPGEdgeDCLineSegment));
const	int	PGEdgeSeriesCompensator_Offset			=(PGEdgeTransformerWinding_Offset		+PG_MaxEdgeTransformerWinding		*sizeof(tagPGEdgeTransformerWinding));
const	int	PGEdgeBreaker_Offset					=(PGEdgeSeriesCompensator_Offset		+PG_MaxEdgeSeriesCompensator		*sizeof(tagPGEdgeSeriesCompensator));
const	int	PGEdgeDisconnector_Offset				=(PGEdgeBreaker_Offset					+PG_MaxEdgeBreaker					*sizeof(tagPGEdgeBreaker));

const	int	PGEdgeADConverter_Offset				=(PGEdgeDisconnector_Offset				+PG_MaxEdgeDisconnector				*sizeof(tagPGEdgeDisconnector));
const	int	PGEdgeDDConverter_Offset					=(PGEdgeADConverter_Offset				+PG_MaxEdgeADConverter				*sizeof(tagPGEdgeADConverter));
const	int	PGEdgeDCBreaker_Offset					=(PGEdgeDDConverter_Offset				+PG_MaxEdgeDDConverter				*sizeof(tagPGEdgeDDConverter));
const	int	PGEdgeDCShortCircuitLimit_Offset		=(PGEdgeDCBreaker_Offset				+PG_MaxEdgeDCBreaker				*sizeof(tagPGEdgeDCBreaker));

const	int	PGTieLine_Offset						=(PGEdgeDCShortCircuitLimit_Offset		+PG_MaxEdgeDCShortCircuitLimit		*sizeof(tagPGEdgeDCShortCircuitLimit));

const	int	PGIsland_Offset							=(PGTieLine_Offset						+PG_MaxTieLine						*sizeof(tagPGTieLine));
const	int	PGTopoBus_Offset						=(PGIsland_Offset						+PG_MaxIsland						*sizeof(tagPGIsland));

#ifdef PGProtSettingDefine
const	int	PGProtSetting_Offset					=(PGTopoBus_Offset						+PG_MaxTopoBus						*sizeof(tagPGTopoBus));
const	int	PGProtLine_Offset						=(PGProtSetting_Offset					+PG_MaxProtSetting					*sizeof(tagPGProtSetting));
const	int	PGProtTran_Offset						=(PGProtLine_Offset						+PG_MaxProtLine						*sizeof(tagPGProtLine));
const	int	PGProtBus_Offset						=(PGProtTran_Offset						+PG_MaxProtTran						*sizeof(tagPGProtTran));
const	int	PGProtGen_Offset						=(PGProtBus_Offset						+PG_MaxProtBus						*sizeof(tagPGProtBus));
const	int	PGProtCap_Offset						=(PGProtGen_Offset						+PG_MaxProtGen						*sizeof(tagPGProtGen));
const	int	PGProtReac_Offset						=(PGProtCap_Offset						+PG_MaxProtCap						*sizeof(tagPGProtCap));
const	int	PGProtMotor_Offset						=(PGProtReac_Offset						+PG_MaxProtReac						*sizeof(tagPGProtReac));
const	int	PGProtBreaker_Offset					=(PGProtMotor_Offset					+PG_MaxProtMotor					*sizeof(tagPGProtMotor));
const	int	PGSystemReliable_Offset					=(PGProtBreaker_Offset					+PG_MaxProtBreaker					*sizeof(tagPGProtBreaker));
#else
const	int	PGSystemReliable_Offset					=(PGTopoBus_Offset						+PG_MaxTopoBus						*sizeof(tagPGTopoBus));
#endif
const	int	PGEnergyConsumerReliable_Offset			=(PGSystemReliable_Offset				+PG_MaxSystemReliable				*sizeof(tagPGSystemReliable));

const	int	PGSubRegion_Offset						=(PGEnergyConsumerReliable_Offset		+PG_MaxEnergyConsumerReliable		*sizeof(tagPGEnergyConsumerReliable));
const	int	PGConnLine_Offset						=(PGSubRegion_Offset					+PG_MaxSubRegion					*sizeof(tagPGSubRegion));
const	int	PGLandPlot_Offset						=(PGConnLine_Offset						+PG_MaxConnLine						*sizeof(tagPGConnLine));
const	int	PGPipe_Offset							=(PGLandPlot_Offset						+PG_MaxLandPlot						*sizeof(tagPGLandPlot));
const	int	PGHyperLinks_Offset						=(PGPipe_Offset							+PG_MaxPipe							*sizeof(tagPGPipe));

const	int	PGDrawing_Offset						=(PGHyperLinks_Offset					+PG_MaxHyperLinks					*sizeof(tagPGHyperLinks));
const	int	PGGraphLayer_Offset						=(PGDrawing_Offset						+PG_MaxDrawing						*sizeof(tagPGDrawing));
const	int	PGGraphAttr_Offset						=(PGGraphLayer_Offset					+PG_MaxGraphLayer					*sizeof(tagPGGraphLayer));
const	int	PGLineVertex_Offset						=(PGGraphAttr_Offset					+PG_MaxGraphAttr					*sizeof(tagPGGraphAttr));
const	int	PGSccFMove_Offset						=(PGLineVertex_Offset					+PG_MaxLineVertex					*sizeof(tagPGLineVertex));

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
