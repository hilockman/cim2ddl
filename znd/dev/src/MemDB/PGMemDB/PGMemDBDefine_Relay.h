#pragma once

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtSetting_	{
	PG_PROTSETTING_PROTKER	=	0,
	PG_PROTSETTING_PROTLINEKKREL1,
	PG_PROTSETTING_PROTLINEKKREL2,
	PG_PROTSETTING_PROTLINEKKLM2,
	PG_PROTSETTING_PROTLINEKKRELP3,
	PG_PROTSETTING_PROTLINEKKRELL3,

	PG_PROTSETTING_PROTLINEK0REL1,
	PG_PROTSETTING_PROTLINEK0REL2,
	PG_PROTSETTING_PROTLINEK0REL3,
	PG_PROTSETTING_PROTLINEK0REL4,

	PG_PROTSETTING_PROTLINEKZREL1,
	PG_PROTSETTING_PROTLINEKZTREL1,
	PG_PROTSETTING_PROTLINEKZP2,
	PG_PROTSETTING_PROTLINEKZLM2,
	PG_PROTSETTING_PROTLINEKZFH3,

	PG_PROTSETTING_PROTLINEKZ0REL1,
	PG_PROTSETTING_PROTLINEKZT0REL1,
	PG_PROTSETTING_PROTLINEKZ0P2,
	PG_PROTSETTING_PROTLINEKZ0LM2,
	PG_PROTSETTING_PROTLINEKZ0P3,
	PG_PROTSETTING_PROTLINEKZ0LM3,

	PG_PROTSETTING_PROTLINEIKDZ2USINGKLM,
	PG_PROTSETTING_PROTLINEIKDZ3COORD3,
	PG_PROTSETTING_PROTLINEI0PROTINTOTRAN,
	PG_PROTSETTING_PROTLINEI0DZ2COORD2,
	PG_PROTSETTING_PROTLINEI0DZ3COORD3,
	PG_PROTSETTING_PROTLINEI0DZ3UNB,

	PG_PROTSETTING_PROTLINEZPROTINTOTRAN,
	PG_PROTSETTING_PROTLINEZDZ2COORD2,
	PG_PROTSETTING_PROTLINEZDZ2USINGKLM,
	PG_PROTSETTING_PROTLINEZDZ3COORD3,
	PG_PROTSETTING_PROTLINEZDZ3USINGKFH,

	PG_PROTSETTING_PROTLINEZ0PROTINTOTRAN,
	PG_PROTSETTING_PROTLINEZ0DZ2COORD2,
	PG_PROTSETTING_PROTLINEZ0DZ2USINGKLM,
	PG_PROTSETTING_PROTLINEZ0DZ3COORD3,
	PG_PROTSETTING_PROTLINEZ0DZ3USINGKLM,

	PG_PROTSETTING_PROTTRANKKSLM1,
	PG_PROTSETTING_PROTTRANKKLLM1,
	PG_PROTSETTING_PROTTRANKKREL3,
	PG_PROTSETTING_PROTTRANKKRES3,

	PG_PROTSETTING_PROTTRANKUOP,
	PG_PROTSETTING_PROTTRANKUOPREL,
	PG_PROTSETTING_PROTTRANKUOPRES,

	PG_PROTSETTING_PROTTRANK0LM1,
	PG_PROTSETTING_PROTTRANK0REL2,

	PG_PROTSETTING_PROTBUSKUNBREL,
	PG_PROTSETTING_PROTBUSKBRKREL,
	PG_PROTSETTING_PROTBUSFAULTUNB,

	PG_PROTSETTING_PROTGENKDREL,
	PG_PROTSETTING_PROTGENKKREL,
	PG_PROTSETTING_PROTGENKKRES,
	PG_PROTSETTING_PROTGENKAP,
	PG_PROTSETTING_PROTGENKSS,

	PG_PROTSETTING_PROTLOADKST,
	PG_PROTSETTING_PROTLOADKDREL,
	PG_PROTSETTING_PROTLOADKKREL,
	PG_PROTSETTING_PROTLOADKKRES,
	PG_PROTSETTING_PROTLOADKAP,
	PG_PROTSETTING_PROTLOADKSS,

	PG_PROTSETTING_PROTCAPKKREL2,
	PG_PROTSETTING_PROTCAPKKREL3,
	PG_PROTSETTING_PROTCAPKKRES3,

	PG_PROTSETTING_PROTREACKDREL,
	PG_PROTSETTING_PROTREACKKREL1,
	PG_PROTSETTING_PROTREACKKREL3,
	PG_PROTSETTING_PROTREACKKRES3,

	PG_PROTSETTING_PROTBREAKERKKP1,
	PG_PROTSETTING_PROTBREAKERKKLM1,
	PG_PROTSETTING_PROTBREAKERKKP2,
	PG_PROTSETTING_PROTBREAKERKKR,

	PG_PROTSETTING_PROTLINEKKSEN1,
	PG_PROTSETTING_PROTLINEKKSEN2,
	PG_PROTSETTING_PROTLINEKKSEN3,
	PG_PROTSETTING_PROTLINEK0SEN1,
	PG_PROTSETTING_PROTLINEK0SEN2,
	PG_PROTSETTING_PROTLINEK0SEN3,
	PG_PROTSETTING_PROTTRANKKSEN3,
	PG_PROTSETTING_PROTGENKKSEN3NEAR,
	PG_PROTSETTING_PROTGENKKSEN3FAR,
	PG_PROTSETTING_PROTLOADKKSEN3,
	PG_PROTSETTING_PROTCAPKKSEN2,
	PG_PROTSETTING_PROTCAPKKSEN3,
	PG_PROTSETTING_PROTREACKKSEN1,
	PG_PROTSETTING_PROTREACKKSEN3,
	PG_PROTSETTING_PROTBREAKERKKSEN1,
	PG_PROTSETTING_PROTBREAKERKKSEN2,
};

struct	_PG_ProtSetting_	{
	float			fProtKer;					//	互感器误差系数
	float			fProtLineKkrel1;			//	瞬时电流速断可靠系数
	float			fProtLineKkrel2;			//	限时电流速断可靠系数
	float			fProtLineKklm2;				//	限时电流速断可靠系数
	float			fProtLineKkrelP3;			//	定时限过电流可靠系数(保护配合)
	float			fProtLineKkrelL3;			//	定时限过电流可靠系数(最大负荷)

	float			fProtLineK0rel1;			//	零序Ⅰ段可靠系数
	float			fProtLineK0rel2;			//	零序Ⅱ段整定灵敏系数，与相邻线路零序Ⅰ段配合，与相邻线路零序Ⅱ段配合
	float			fProtLineK0rel3;			//	零序Ⅲ段可靠系数
	float			fProtLineK0rel4;			//	零序Ⅳ段可靠系数

	float			fProtLineKZrel1;			//	相间距离Ⅰ段可靠系数
	float			fProtLineKZTrel1;			//	相间距离Ⅰ段相邻变压器可靠系数
	float			fProtLineKZp2;				//	相间距离Ⅱ段配合系数
	float			fProtLineKZlm2;				//	相间距离Ⅱ段灵敏系数
	float			fProtLineKZfh3;				//	相间距离Ⅲ段负荷系数

	float			fProtLineKZ0rel1;			//	接地距离Ⅰ段可靠系数
	float			fProtLineKZT0rel1;			//	接地距离Ⅰ段相邻变压器可靠系数
	float			fProtLineKZ0p2;				//	接地距离Ⅱ段配合系数
	float			fProtLineKZ0lm2;			//	接地距离Ⅱ段灵敏系数
	float			fProtLineKZ0p3;				//	接地距离Ⅲ段配合系数
	float			fProtLineKZ0lm3;			//	接地距离Ⅲ段灵敏系数

	unsigned char	bProtLineIkdz2UsingKlm;		//	限时电流速断按灵敏度整定
	unsigned char	bProtLineIkdz3Coord3;		//	过流保护与相邻线路配合
	unsigned char	bProtLineI0ProtIntoTran;	//	零序Ⅰ段整定到变压器内
	unsigned char	bProtLineI0dz2Coord2;		//	零序Ⅱ段与邻线Ⅱ段配合
	unsigned char	bProtLineI0dz3Coord3;		//	零序Ⅲ段与邻线Ⅲ段配合
	unsigned char	bProtLineI0dz3Unb;			//	终端线路零序Ⅲ段按变压器不平衡电流整定

	unsigned char	bProtLineZProtIntoTran;		//	相间距离Ⅰ段可整定到变压器内
	unsigned char	bProtLineZdz2Coord2;		//	相间距离与相邻Ⅱ段配合
	unsigned char	bProtLineZdz2UsingKlm;		//	相间距离Ⅱ段按灵敏度整定
	unsigned char	bProtLineZdz3Coord3;		//	相间距离与相邻Ⅲ段配合
	unsigned char	bProtLineZdz3UsingKfh;		//	相间距离Ⅲ段按负荷整定

	unsigned char	bProtLineZ0ProtIntoTran;	//	接地距离Ⅰ段可整定到变压器内
	unsigned char	bProtLineZ0dz2Coord2;		//	接地距离与相邻Ⅱ段配合
	unsigned char	bProtLineZ0dz2UsingKlm;		//	接地距离Ⅱ段按灵敏度整定
	unsigned char	bProtLineZ0dz3Coord3;		//	接地距离与相邻Ⅲ段配合
	unsigned char	bProtLineZ0dz3UsingKlm;		//	接地距离Ⅲ段按灵敏度整定
	////////////////////////////////////////////////////////////////////////

	float			fProtTranKkslm1;				//	负荷侧过流保护灵敏系数
	float			fProtTranKkllm1;				//	负荷侧过流保护灵敏系数
	float			fProtTranKkrel3;			//	过流保护可靠系数
	float			fProtTranKkres3;			//	过流保护返回系数

	float			fProtTranKuop;				//	复压闭锁电压值
	float			fProtTranKuoprel;			//	复压闭锁可靠系数
	float			fProtTranKuopres;			//	复压闭锁返回系数

	float			fProtTranK0lm1;				//	零序Ⅰ段灵敏系数
	float			fProtTranK0rel2;			//	零序Ⅱ段可靠系数
	////////////////////////////////////////////////////////////////////////

	float			fProtBusKunbrel;			//	不平衡电流可靠系数
	float			fProtBusKbrkrel;			//	二次断线可靠系数
	unsigned char	bProtBusFaultUnb;
	////////////////////////////////////////////////////////////////////////

	float			fProtGenKdrel;				//	纵差保护可靠系数
	float			fProtGenKkrel;				//	过流保护可靠系数
	float			fProtGenKkres;				//	过流保护返回系数
	float			fProtGenKap;				//	非周期分量影响系数
	float			fProtGenKss;				//	电流互感器同型系数
	////////////////////////////////////////////////////////////////////////

	float			fProtLoadKst;				//	电动机启动电流倍数
	float			fProtLoadKdrel;				//	纵差保护可靠系数
	float			fProtLoadKkrel;				//	过流保护可靠系数
	float			fProtLoadKkres;				//	过流保护返回系数
	float			fProtLoadKap;				//	非周期分量影响系数
	float			fProtLoadKss;				//	电流互感器同型系数
	////////////////////////////////////////////////////////////////////////

	float			fProtCapKkrel2;				//	延时电流速断可靠系数
	float			fProtCapKkrel3;				//	过流保护可靠系数
	float			fProtCapKkres3;				//	过流保护返回系数
	////////////////////////////////////////////////////////////////////////

	float			fProtReacKdrel;				//	差动保护可靠系数
	float			fProtReacKkrel1;			//	电流速断可靠系数
	float			fProtReacKkrel3;			//	过流保护可靠系数
	float			fProtReacKkres3;			//	过流保护返回系数
	////////////////////////////////////////////////////////////////////////

	float			fProtBreakerKkp1;			//	过流Ⅰ段配合系数
	float			fProtBreakerKklm1;			//	过流Ⅰ段灵敏系数
	float			fProtBreakerKkp2;			//	过流Ⅱ段配合系数
	float			fProtBreakerKkr;			//	合环保护可靠系数

	float			fProtLineKksen1;			//	线路瞬时电流速断灵敏系数
	float			fProtLineKksen2;			//	线路限时电流速断灵敏系数
	float			fProtLineKksen3;			//	线路定时限过电流灵敏系数
	float			fProtLineK0sen1;			//	线路零序Ⅰ段灵敏系数
	float			fProtLineK0sen2;			//	线路零序Ⅱ段灵敏系数
	float			fProtLineK0sen3;			//	线路零序Ⅲ段灵敏系数
	float			fProtTranKksen3;			//	变压器过流保护灵敏系数
	float			fProtGenKksen3Near;			//	发电机近后备过流保护灵敏系数
	float			fProtGenKksen3Far;			//	发电机远后备过流保护灵敏系数
	float			fProtLoadKksen3;			//	电动机过流保护灵敏系数
	float			fProtCapKksen2;				//	并联电容器延时电流速断灵敏系数
	float			fProtCapKksen3;				//	并联电容器过流保护灵敏系数
	float			fProtReacKksen1;			//	并联电抗器电流速断灵敏系数
	float			fProtReacKksen3;			//	并联电抗器过流保护灵敏系数
	float			fProtBreakerKsen1;			//	母联/分段开关过流Ⅰ段灵敏系数
	float			fProtBreakerKsen2;			//	母联/分段开关过流Ⅱ段灵敏系数
}	DISALIGN;
typedef	struct	_PG_ProtSetting_	tagPGProtSetting;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtLine_	{
	PG_PROTLINE_NAME=0,

	PG_PROTLINE_SUBI,
	PG_PROTLINE_SUBJ,
	PG_PROTLINE_VOLT,
	PG_PROTLINE_NORMINALVOLT,
	PG_PROTLINE_RATE,
	PG_PROTLINE_TOPOBUSI,
	PG_PROTLINE_TOPOBUSJ,

	PG_PROTLINE_POWERED,
	PG_PROTLINE_SRCGENI,
	PG_PROTLINE_SRCGENJ,
	PG_PROTLINE_ZGROUND,
	PG_PROTLINE_ZGTOPOBUSI,
	PG_PROTLINE_ZGTOPOBUSJ,

	PG_PROTLINE_IKMAXI,
	PG_PROTLINE_I0MAXI,
	PG_PROTLINE_I0TRANI,

	PG_PROTLINE_IKMININEAR,
	PG_PROTLINE_I0MININEAR,
	PG_PROTLINE_IKMINIFAR,
	PG_PROTLINE_I0MINIFAR,

	PG_PROTLINE_IKMAXJ,
	PG_PROTLINE_I0MAXJ,
	PG_PROTLINE_I0TRANJ,

	PG_PROTLINE_IKMINJNEAR,
	PG_PROTLINE_I0MINJNEAR,
	PG_PROTLINE_IKMINJFAR,
	PG_PROTLINE_I0MINJFAR,

	PG_PROTLINE_IKINTOTRANI,
	PG_PROTLINE_IKINTOTRANJ,

	PG_PROTLINE_N1IKMINI,
	PG_PROTLINE_N1I0MINI,
	PG_PROTLINE_N1IKMINJ,
	PG_PROTLINE_N1I0MINJ,
	PG_PROTLINE_N1IKMINIBUS,
	PG_PROTLINE_N1I0MINIBUS,
	PG_PROTLINE_N1IKMINJBUS,
	PG_PROTLINE_N1I0MINJBUS,

	PG_PROTLINE_KREL1,
	PG_PROTLINE_KREL2,
	PG_PROTLINE_KLM2,
	PG_PROTLINE_KRELP3,
	PG_PROTLINE_KRELL3,
	PG_PROTLINE_K0REL1,
	PG_PROTLINE_K0REL2,
	PG_PROTLINE_K0REL3,
	PG_PROTLINE_K0REL4,

	PG_PROTLINE_KZREL1,
	PG_PROTLINE_KZTREL1,
	PG_PROTLINE_KZP2,
	PG_PROTLINE_KZLM2,
	PG_PROTLINE_KZFH3,

	PG_PROTLINE_KZ0REL1,
	PG_PROTLINE_KZT0REL1,
	PG_PROTLINE_KZ0P2,
	PG_PROTLINE_KZ0LM2,
	PG_PROTLINE_KZ0P3,
	PG_PROTLINE_KZ0LM3,

	PG_PROTLINE_IKDZ2USINGKLM,
	PG_PROTLINE_IKDZ3COORD3,
	PG_PROTLINE_I0PROTINTOTRAN	,
	PG_PROTLINE_I0DZ2COORD2,
	PG_PROTLINE_I0DZ3COORD3,
	PG_PROTLINE_I0DZ3UNB,

	PG_PROTLINE_ZPROTINTOTRAN,
	PG_PROTLINE_ZDZ2COORD2,
	PG_PROTLINE_ZDZ2USINGKLM,
	PG_PROTLINE_ZDZ3COORD3,
	PG_PROTLINE_ZDZ3USINGKFH,

	PG_PROTLINE_Z0PROTINTOTRAN,
	PG_PROTLINE_Z0DZ2COORD2,
	PG_PROTLINE_Z0DZ2USINGKLM,
	PG_PROTLINE_Z0DZ3COORD3,
	PG_PROTLINE_Z0DZ3USINGKLM,

	PG_PROTLINE_IDZ1I,
	PG_PROTLINE_IDZ2I,
	PG_PROTLINE_IDZ3I,

	PG_PROTLINE_I0DZ1I,
	PG_PROTLINE_I0DZ2I,
	PG_PROTLINE_I0DZ3I,
	PG_PROTLINE_I0DZ1INTOTRANI,

	PG_PROTLINE_ZDZ1I,
	PG_PROTLINE_ZDZ2I,
	PG_PROTLINE_ZDZ3I,

	PG_PROTLINE_Z0DZ1I,
	PG_PROTLINE_Z0DZ2I,
	PG_PROTLINE_Z0DZ3I,

	PG_PROTLINE_IDZ1J,
	PG_PROTLINE_IDZ2J,
	PG_PROTLINE_IDZ3J,

	PG_PROTLINE_I0DZ1J,
	PG_PROTLINE_I0DZ2J,
	PG_PROTLINE_I0DZ3J,
	PG_PROTLINE_I0DZ1INTOTRANJ,

	PG_PROTLINE_ZDZ1J,
	PG_PROTLINE_ZDZ2J,
	PG_PROTLINE_ZDZ3J,

	PG_PROTLINE_Z0DZ1J,
	PG_PROTLINE_Z0DZ2J,
	PG_PROTLINE_Z0DZ3J,

	PG_PROTLINE_KSEN1I,
	PG_PROTLINE_KSEN2I,
	PG_PROTLINE_KSEN3I,

	PG_PROTLINE_K0SEN1I,
	PG_PROTLINE_K0SEN2I,
	PG_PROTLINE_K0SEN3I,

	PG_PROTLINE_KSEN1J,
	PG_PROTLINE_KSEN2J,
	PG_PROTLINE_KSEN3J,

	PG_PROTLINE_K0SEN1J,
	PG_PROTLINE_K0SEN2J,
	PG_PROTLINE_K0SEN3J,

	PG_PROTLINE_ACLINESEGMENTPTR,
};

struct	_PG_ProtLine_	{
	char			szName[MDB_CHARLEN];

	char			szSubI[MDB_CHARLEN];
	char			szSubJ[MDB_CHARLEN];
	char			szVolt[MDB_CHARLEN_SHORTER];
	float			fNorminalVolt;
	float			fRate;
	int				nTopoBusI;
	int				nTopoBusJ;

	unsigned char	bPowered;
	short			nSrcGenI;
	short			nSrcGenJ;
	unsigned char	bZGround;
	int				nZGBusI;
	int				nZGBusJ;

	//////////////////////////////////////////////////////////////////////////
	//	线路两侧最大最小短路电流
	float			fIkmaxI;
	float			fI0maxI;
	float			fI0TranI;

	float			fIkminINear;
	float			fI0minINear;
	float			fIkminIFar;
	float			fI0minIFar;

	float			fIkmaxJ;
	float			fI0maxJ;
	float			fI0TranJ;

	float			fIkminJNear;
	float			fI0minJNear;
	float			fIkminJFar;
	float			fI0minJFar;

	unsigned char	bIkIntoTranI;
	unsigned char	bIkIntoTranJ;

	//////////////////////////////////////////////////////////////////////////
	//	线路两侧一级相邻最大最小短路电流，无线路则按变压器对侧的
	float			fN1IkminI;
	float			fN1I0minI;
	float			fN1IkminJ;
	float			fN1I0minJ;
	char			szN1IkminIBus[MDB_CHARLEN];
	char			szN1I0minIBus[MDB_CHARLEN];
	char			szN1IkminJBus[MDB_CHARLEN];
	char			szN1I0minJBus[MDB_CHARLEN];

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkrel1;
	float			fKkrel2;
	float			fKklm2;
	float			fKkrelP3;
	float			fKkrelL3;
	float			fK0rel1;
	float			fK0rel2;
	float			fK0rel3;
	float			fK0rel4;

	float			fKZrel1;
	float			fKZTrel1;
	float			fKZp2;
	float			fKZlm2;
	float			fKZfh3;

	float			fKZ0rel1;
	float			fKZT0rel1;
	float			fKZ0p2;
	float			fKZ0lm2;
	float			fKZ0p3;
	float			fKZ0lm3;

	unsigned char	bIkdz2UsingKlm;
	unsigned char	bIkdz3Coord3;
	unsigned char	bI0ProtIntoTran;
	unsigned char	bI0dz2Coord2;
	unsigned char	bI0dz3Coord3;
	unsigned char	bI0dz3Unb;

	unsigned char	bZProtIntoTran;
	unsigned char	bZdz2Coord2;
	unsigned char	bZdz2UsingKlm;
	unsigned char	bZdz3Coord3;
	unsigned char	bZdz3UsingKfh;

	unsigned char	bZ0ProtIntoTran;
	unsigned char	bZ0dz2Coord2;
	unsigned char	bZ0dz2UsingKlm;
	unsigned char	bZ0dz3Coord3;
	unsigned char	bZ0dz3UsingKlm;

	//////////////////////////////////////////////////////////////////////////
	//	I侧保护整定值
	float			fIkdz1I;
	float			fIkdz2I;
	float			fIkdz3I;

	float			fI0dz1I;
	float			fI0dz2I;
	float			fI0dz3I;
	unsigned char	bI0dzIntoTranI;

	float			fZkdz1I;
	float			fZkdz2I;
	float			fZkdz3I;

	float			fZ0dz1I;
	float			fZ0dz2I;
	float			fZ0dz3I;

	//////////////////////////////////////////////////////////////////////////
	//	J侧保护整定值
	float			fIdz1J;
	float			fIdz2J;
	float			fIdz3J;

	float			fI0dz1J;
	float			fI0dz2J;
	float			fI0dz3J;
	unsigned char	bI0dzIntoTranJ;

	float			fZdz1J;
	float			fZdz2J;
	float			fZdz3J;

	float			fZ0dz1J;
	float			fZ0dz2J;
	float			fZ0dz3J;

	//////////////////////////////////////////////////////////////////////////
	//	I侧保护灵敏系数
	float			fKsen1I;
	float			fKsen2I;
	float			fKsen3I;

	float			fK0sen1I;
	float			fK0sen2I;
	float			fK0sen3I;

	//////////////////////////////////////////////////////////////////////////
	//	J侧保护灵敏系数
	float			fKsen1J;
	float			fKsen2J;
	float			fKsen3J;

	float			fK0sen1J;
	float			fK0sen2J;
	float			fK0sen3J;

	short			nACLineSegment;
}	DISALIGN;
typedef	struct	_PG_ProtLine_	tagPGProtLine;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtTran_	{
	PG_PROTTRAN_NAME=0,
	PG_PROTTRAN_SUB,

	PG_PROTTRAN_VOLTH,
	PG_PROTTRAN_VOLTM,
	PG_PROTTRAN_VOLTL,
	PG_PROTTRAN_3WIND,
	PG_PROTTRAN_TOPOBUSH,
	PG_PROTTRAN_TOPOBUSM,
	PG_PROTTRAN_TOPOBUSL,

	PG_PROTTRAN_RATEVOLTH,
	PG_PROTTRAN_RATEVOLTM,
	PG_PROTTRAN_RATEVOLTL,
	PG_PROTTRAN_RATEH,
	PG_PROTTRAN_RATEM,
	PG_PROTTRAN_RATEL,

	PG_PROTTRAN_LOADTRAN,
	PG_PROTTRAN_POWERH,
	PG_PROTTRAN_POWERM,
	PG_PROTTRAN_POWERL,
	PG_PROTTRAN_ZGSTATH,
	PG_PROTTRAN_ZGSTATM,
	PG_PROTTRAN_ZGSTATL,

	PG_PROTTRAN_ITMAXH,
	PG_PROTTRAN_ITMAXM,
	PG_PROTTRAN_ITMAXL,

	PG_PROTTRAN_ITMINH,
	PG_PROTTRAN_ITMINM,
	PG_PROTTRAN_ITMINL,

	PG_PROTTRAN_I0TMAXH,
	PG_PROTTRAN_I0TMAXM,
	PG_PROTTRAN_I0TMAXL,

	PG_PROTTRAN_I0TMINH,
	PG_PROTTRAN_I0TMINM,
	PG_PROTTRAN_I0TMINL,

	PG_PROTTRAN_IOBMAXH,
	PG_PROTTRAN_IOBMAXM,
	PG_PROTTRAN_IOBMAXL,

	PG_PROTTRAN_IOBMINH,
	PG_PROTTRAN_IOBMINM,
	PG_PROTTRAN_IOBMINL,

	PG_PROTTRAN_IKMAXHNEAR,
	PG_PROTTRAN_IKMAXMNEAR,
	PG_PROTTRAN_IKMAXLNEAR,

	PG_PROTTRAN_IKMINHNEAR,
	PG_PROTTRAN_IKMINMNEAR,
	PG_PROTTRAN_IKMINLNEAR,

	PG_PROTTRAN_I0KMAXHNEAR,
	PG_PROTTRAN_I0KMAXMNEAR,
	PG_PROTTRAN_I0KMAXLNEAR,

	PG_PROTTRAN_I0KMINHNEAR,
	PG_PROTTRAN_I0KMINMNEAR,
	PG_PROTTRAN_I0KMINLNEAR,

	PG_PROTTRAN_IKMAXHFAR,
	PG_PROTTRAN_IKMAXMFAR,
	PG_PROTTRAN_IKMAXLFAR,

	PG_PROTTRAN_IKMINHFAR,
	PG_PROTTRAN_IKMINMFAR,
	PG_PROTTRAN_IKMINLFAR,

	PG_PROTTRAN_I0KMAXHFAR,
	PG_PROTTRAN_I0KMAXMFAR,
	PG_PROTTRAN_I0KMAXLFAR,

	PG_PROTTRAN_I0KMINHFAR,
	PG_PROTTRAN_I0KMINMFAR,
	PG_PROTTRAN_I0KMINLFAR,

	PG_PROTTRAN_IKUNBH,
	PG_PROTTRAN_IKUNBM,
	PG_PROTTRAN_IKUNBL,

	PG_PROTTRAN_KKSLM1,
	PG_PROTTRAN_KKLLM1,
	PG_PROTTRAN_KKREL3,
	PG_PROTTRAN_KKRES3,

	PG_PROTTRAN_KUOP,
	PG_PROTTRAN_KUOPREL,
	PG_PROTTRAN_KUOPRES,

	PG_PROTTRAN_K0LM1,
	PG_PROTTRAN_K0REL2,

	PG_PROTTRAN_IKDZ1H,
	PG_PROTTRAN_IKDZ1M,
	PG_PROTTRAN_IKDZ1L,

	PG_PROTTRAN_IKDZ3H,
	PG_PROTTRAN_IKDZ3M,
	PG_PROTTRAN_IKDZ3L,

	PG_PROTTRAN_UOPH,
	PG_PROTTRAN_UOPM,
	PG_PROTTRAN_UOPL,

	PG_PROTTRAN_I0DZ1H,
	PG_PROTTRAN_I0DZ1M,
	PG_PROTTRAN_I0DZ1L,

	PG_PROTTRAN_I0DZ2H,
	PG_PROTTRAN_I0DZ2M,
	PG_PROTTRAN_I0DZ2L,

	PG_PROTTRAN_KKSEN3H,
	PG_PROTTRAN_KKSEN3M,
	PG_PROTTRAN_KKSEN3L,

	PG_PROTTRAN_POWERTRANSFORMERPTR,
};

struct	_PG_ProtTran_	{
	char			szName[MDB_CHARLEN];
	char			szSub[MDB_CHARLEN];

	char			szVoltH[MDB_CHARLEN_SHORTER];
	char			szVoltM[MDB_CHARLEN_SHORTER];
	char			szVoltL[MDB_CHARLEN_SHORTER];
	unsigned char	b3Wind;			//	三卷变标记
	int				nTopoBusH;		//	高压卷拓扑母线
	int				nTopoBusM;		//	中压卷拓扑母线
	int				nTopoBusL;		//	低压卷拓扑母线

	float			fRateVoltH;
	float			fRateVoltM;
	float			fRateVoltL;
	float			fRateH;
	float			fRateM;
	float			fRateL;

	unsigned char	bLoadTran;		//	负荷变压器，即只有一侧连接电源的变压器
	unsigned char	bPowerH;		//	电源标记，=0无源，=1电源
	unsigned char	bPowerM;		//	电源标记，=0无源，=1电源
	unsigned char	bPowerL;		//	电源标记，=0无源，=1电源

	unsigned char	nZGStatH;		//	高压卷零序情况，=0，不通；=1，支路；=2接地
	unsigned char	nZGStatM;		//	中压卷零序情况，=0，不通；=1，支路；=2接地
	unsigned char	nZGStatL;		//	中压卷零序情况，=0，不通；=1，支路；=2接地

	//////////////////////////////////////////////////////////////////////////
	//	主变各侧母线短路，变压器的最大最小短路电流，相当于变压器内部短路
	float			fItmaxH	;
	float			fItmaxM	;
	float			fItmaxL	;

	float			fItminH	;
	float			fItminM	;
	float			fItminL	;

	float			fI0tmaxH;
	float			fI0tmaxM;
	float			fI0tmaxL;

	float			fI0tminH;
	float			fI0tminM;
	float			fI0tminL;

	//////////////////////////////////////////////////////////////////////////
	//	主变对侧母线短路，变压器的最大最小短路电流
	float			fIobmaxH	;
	float			fIobmaxM	;
	float			fIobmaxL	;

	float			fIobminH	;
	float			fIobminM	;
	float			fIobminL	;

	//////////////////////////////////////////////////////////////////////////
	//	主变本侧母线短路，变压器的最大最小短路电流
	float			fIkmaxHNear	;
	float			fIkmaxMNear	;
	float			fIkmaxLNear	;

	float			fIkminHNear	;
	float			fIkminMNear	;
	float			fIkminLNear	;

	float			fI0kmaxHNear;
	float			fI0kmaxMNear;
	float			fI0kmaxLNear;

	float			fI0kminHNear;
	float			fI0kminMNear;
	float			fI0kminLNear;

	//////////////////////////////////////////////////////////////////////////
	//	主变各侧一级相邻线路最大最小短路电流
	float			fIkmaxHFar	;
	float			fIkmaxMFar	;
	float			fIkmaxLFar	;

	float			fIkminHFar	;
	float			fIkminMFar	;
	float			fIkminLFar	;

	float			fI0kmaxHFar;
	float			fI0kmaxMFar;
	float			fI0kmaxLFar;

	float			fI0kminHFar;
	float			fI0kminMFar;
	float			fI0kminLFar;

	//////////////////////////////////////////////////////////////////////////
	//	主变各侧最大不平衡电流计算用电流，仅仅显示用于测试
	float			fIkunbH;
	float			fIkunbM;
	float			fIkunbL;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkslm1;		//	电源侧过流Ⅰ段保护灵敏系数
	float			fKkllm1;		//	负荷侧过流Ⅰ段保护灵敏系数
	float			fKkrel3;		//	过流保护可靠系数
	float			fKkres3;		//	过流保护返回系数

	float			fKuop;			//	复压闭锁电压值
	float			fKuoprel;		//	复压闭锁可靠系数
	float			fKuopres;		//	复压闭锁返回系数

	float			fK0lm1;			//	零序Ⅰ段灵敏系数
	float			fK0rel2;		//	零序Ⅱ段可靠系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkdz1H;		//	电流保护Ⅰ段动作电流，是负荷侧整定，对电源侧无效
	float			fIkdz1M;		//	电流保护Ⅰ段动作电流，是负荷侧整定，对电源侧无效
	float			fIkdz1L;		//	电流保护Ⅰ段动作电流，是负荷侧整定，对电源侧无效

	float			fIkdz3H;		//	过流保护动作电流
	float			fIkdz3M;		//	过流保护动作电流
	float			fIkdz3L;		//	过流保护动作电流

	float			fUopH;			//	复压闭锁整定电压
	float			fUopM;			//	复压闭锁整定电压
	float			fUopL;			//	复压闭锁整定电压

	float			fI0dz1H;		//	零序Ⅰ段动作电流
	float			fI0dz1M;		//	零序Ⅰ段动作电流
	float			fI0dz1L;		//	零序Ⅰ段动作电流

	float			fI0dz2H;		//	零序Ⅱ段动作电流
	float			fI0dz2M;		//	零序Ⅱ段动作电流
	float			fI0dz2L;		//	零序Ⅱ段动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKksen3H;		//	过流保护灵敏系数
	float			fKksen3M;		//	过流保护灵敏系数
	float			fKksen3L;		//	过流保护灵敏系数

	short			nPowerTransformer;
}	DISALIGN;
typedef	struct	_PG_ProtTran_	tagPGProtTran;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtBus_	{
	PG_PROTBUS_NAME=0,
	PG_PROTBUS_TOPOBUS,

	PG_PROTBUS_IBRANKMAX,
	PG_PROTBUS_IBRANEMAX,
	PG_PROTBUS_IKMIN,

	PG_PROTBUS_KUNBREL,
	PG_PROTBUS_KBRKREL,
	PG_PROTBUS_FAULTUNB,

	PG_PROTBUS_IKOP,
	PG_PROTBUS_ILOP,
	PG_PROTBUS_IOOP,
	PG_PROTBUS_IKDZ,

	PG_PROTBUS_KSEN,

	PG_PROTBUS_BUSPTR,
};

struct	_PG_ProtBus_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;

	//////////////////////////////////////////////////////////////////////////
	//	母线最大短路电流，最大负荷电流
	float			fIbrankmax;			//	支路最大短路电流
	float			fIbranemax;			//	支路最大负荷电流
	float			fIkmin;				//	母线最小短路电流

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKunbrel;			//	导则：不平衡电流可靠系数	一般大于2或3
	float			fKbrkrel;			//	导则：二次断线可靠系数	一般取1.1~1.3
	unsigned char	bFaultUnb;			//	外部短路故障整定不平衡电流

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkop;				//	外部短路计算不平衡电流，躲避不平衡电流差动保护动作电流
	float			fIlop;				//	最大负荷计算不平衡电流，躲避不平衡电流差动保护动作电流
	float			fIoop;				//	躲避二次断线差动保护动作电流
	float			fIdz;				//	差动保护动作电流	Idz

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen;				//	导则：灵敏系数，不小于2

	short			nBus;
}	DISALIGN;
typedef	struct	_PG_ProtBus_	tagPGProtBus;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtGen_	{
	PG_PROTGEN_NAME=0,
	PG_PROTGEN_TOPOBUS,
	PG_PROTGEN_RATE,

	PG_PROTGEN_IKMAX,
	PG_PROTGEN_IKMINNEAR,
	PG_PROTGEN_IKMINFAR,

	PG_PROTGEN_KDREL,
	PG_PROTGEN_KKREL,
	PG_PROTGEN_KKRES,
	PG_PROTGEN_KAP,
	PG_PROTGEN_KSS,

	PG_PROTGEN_IUNBMAX,
	PG_PROTGEN_IDDZ,
	PG_PROTGEN_IKDZ,

	PG_PROTGEN_KKSENNEAR,
	PG_PROTGEN_KKSENFAR,

	PG_PROTGEN_GENPTR,
};

struct	_PG_ProtGen_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkminNear;
	float			fIkminFar;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKdrel;			//	纵差保护可靠系数
	float			fKkrel;			//	过流保护可靠系数
	float			fKkres;			//	过流保护返回系数
	float			fKap;			//	非周期分量影响系数
	float			fKss;			//	电流互感器同型系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIunbmax;		//	纵差最大不平衡电流	Iunbmax
	float			fIddz;			//	纵差保护动作电流	Iddz
	float			fIkdz;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKksenNear;		//	过流保护近后备灵敏系数
	float			fKksenFar;		//	过流保护远后备灵敏系数

	short			nGen;
}	DISALIGN;
typedef	struct	_PG_ProtGen_	tagPGProtGen;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtCap_	{
	PG_PROTCAP_NAME=0,
	PG_PROTCAP_TOPOBUS,
	PG_PROTCAP_RATE,

	PG_PROTCAP_IKMAX,
	PG_PROTCAP_IKMIN,

	PG_PROTCAP_KKREL2,
	PG_PROTCAP_KKREL3,
	PG_PROTCAP_KKRES3,

	PG_PROTCAP_IKDZ2,
	PG_PROTCAP_IKDZ3,

	PG_PROTCAP_KSEN2,
	PG_PROTCAP_KSEN3,

	PG_PROTCAP_CAPPTR,
};

struct	_PG_ProtCap_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkrel2;		//	延时电流速断保护可靠系数
	float			fKkrel3;		//	过流保护可靠系数
	float			fKkres3;		//	过流保护返回系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkdz2;			//	延时电流速断动作电流	Iddz
	float			fIkdz3;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen2;			//	过流保护近后备灵敏系数
	float			fKsen3;			//	过流保护远后备灵敏系数

	short			nCap;
}	DISALIGN;
typedef	struct	_PG_ProtCap_	tagPGProtCap;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtReac_	{
	PG_PROTREAC_NAME=0,
	PG_PROTREAC_TOPOBUS,
	PG_PROTREAC_RATE,

	PG_PROTREAC_IKMAX,
	PG_PROTREAC_IKMIN,

	PG_PROTREAC_KDREL,
	PG_PROTREAC_KKREL1,
	PG_PROTREAC_KKREL3,
	PG_PROTREAC_KKRES3,

	PG_PROTREAC_IDDZ,
	PG_PROTREAC_IKDZ1,
	PG_PROTREAC_IKDZ3,

	PG_PROTREAC_KSEN1,
	PG_PROTREAC_KSEN3,

	PG_PROTREAC_REACPTR,
};

struct	_PG_ProtReac_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKdrel;			//	差动保护整定系数
	float			fKkrel1;		//	瞬时电流速断保护可靠系数
	float			fKkrel3;		//	过流保护可靠系数
	float			fKkres3;		//	过流保护返回系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIddz;			//	差动保护动作电流
	float			fIkdz1;			//	瞬时电流速断动作电流
	float			fIkdz3;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen1;			//	瞬时电流速断灵敏系数
	float			fKsen3;			//	过流保护远后备灵敏系数

	short			nReac;
}	DISALIGN;
typedef	struct	_PG_ProtReac_	tagPGProtReac;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtMotor_	{
	PG_PROTMOTOR_NAME=0,
	PG_PROTMOTOR_TOPOBUS,
	PG_PROTMOTOR_RATE,

	PG_PROTMOTOR_IKMAX,
	PG_PROTMOTOR_IKMIN,

	PG_PROTMOTOR_KST,
	PG_PROTMOTOR_KDREL,
	PG_PROTMOTOR_KKREL,
	PG_PROTMOTOR_KKRES,
	PG_PROTMOTOR_KAP,
	PG_PROTMOTOR_KSS,

	PG_PROTMOTOR_IUNBMAX,
	PG_PROTMOTOR_IDDZ,
	PG_PROTMOTOR_IKDZ,

	PG_PROTMOTOR_KDSEN,
	PG_PROTMOTOR_KKSEN,

	PG_PROTMOTOR_LOADPTR,
};

struct	_PG_ProtMotor_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;
	float			fRate;

	//////////////////////////////////////////////////////////////////////////
	//	发电机供短路点最大最小短路电流
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKst;			//	电动机启动电流倍数
	float			fKdrel;			//	纵差保护可靠系数
	float			fKkrel;			//	过流保护可靠系数
	float			fKkres;			//	过流保护返回系数
	float			fKap;			//	非周期分量影响系数
	float			fKss;			//	电流互感器同型系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIunbmax;		//	纵差最大不平衡电流
	float			fIddz;			//	纵差保护动作电流
	float			fIkdz;			//	过流保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKdsen;			//	瞬时电流速断灵敏系数
	float			fKksen;			//	过流保护远后备灵敏系数

	int				nLoad;
}	DISALIGN;
typedef	struct	_PG_ProtMotor_	tagPGProtMotor;

//////////////////////////////////////////////////////////////////////////
enum	_PGEnum_Field_ProtBreaker_	{
	PG_PROTBREAKER_NAME=0,
	PG_PROTBREAKER_TOPOBUS,

	PG_PROTBREAKER_ILINEMAX,
	PG_PROTBREAKER_ITRANMAX,
	PG_PROTBREAKER_LOWVBREAKER,

	PG_PROTBREAKER_IKMAX,
	PG_PROTBREAKER_IKMIN,

	PG_PROTBREAKER_KKP1,
	PG_PROTBREAKER_KKLM1,
	PG_PROTBREAKER_KKP2,
	PG_PROTBREAKER_KKR,

	PG_PROTBREAKER_IKDZ1,
	PG_PROTBREAKER_IKDZ2,
	PG_PROTBREAKER_IRDZ,

	PG_PROTBREAKER_KSEN1,
	PG_PROTBREAKER_KSEN2,

	PG_PROTBREAKER_BREAKERPTR,
};

struct	_PG_ProtBreaker_	{
	char			szName[MDB_CHARLEN_LONG];
	int				nTopoBus;

	float			fILineRateMax;		//	线路最大额定电流
	float			fITranRateMax;		//	变压器最大额定电流
	unsigned char	bLowVBreaker;
	//////////////////////////////////////////////////////////////////////////
	//	最大短路电流，最大负荷电流
	float			fIkmax;				//	最大短路电流
	float			fIkmin;				//	最小短路电流

	//////////////////////////////////////////////////////////////////////////
	//	保护整定相关系数
	float			fKkp1;				//	过流Ⅰ段配合系数
	float			fKklm1;				//	过流Ⅰ段灵敏系数
	float			fKkp2;				//	过流Ⅱ段配合系数
	float			fKkr;				//	合环保护可靠系数

	//////////////////////////////////////////////////////////////////////////
	//	保护整定结果
	float			fIkdz1;				//	过流Ⅰ段保护动作电流
	float			fIkdz2;				//	过流Ⅱ段保护动作电流
	float			fIrdz;				//	合环保护动作电流

	//////////////////////////////////////////////////////////////////////////
	//	保护灵敏系数校核
	float			fKsen1;
	float			fKsen2;

	int				nBreaker;
}	DISALIGN;
typedef	struct	_PG_ProtBreaker_	tagPGProtBreaker;
