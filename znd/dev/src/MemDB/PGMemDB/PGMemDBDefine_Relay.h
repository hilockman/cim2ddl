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
	float			fProtKer;					//	���������ϵ��
	float			fProtLineKkrel1;			//	˲ʱ�����ٶϿɿ�ϵ��
	float			fProtLineKkrel2;			//	��ʱ�����ٶϿɿ�ϵ��
	float			fProtLineKklm2;				//	��ʱ�����ٶϿɿ�ϵ��
	float			fProtLineKkrelP3;			//	��ʱ�޹������ɿ�ϵ��(�������)
	float			fProtLineKkrelL3;			//	��ʱ�޹������ɿ�ϵ��(��󸺺�)

	float			fProtLineK0rel1;			//	�����οɿ�ϵ��
	float			fProtLineK0rel2;			//	��������������ϵ������������·��������ϣ���������·���������
	float			fProtLineK0rel3;			//	�����οɿ�ϵ��
	float			fProtLineK0rel4;			//	������οɿ�ϵ��

	float			fProtLineKZrel1;			//	�������οɿ�ϵ��
	float			fProtLineKZTrel1;			//	�����������ڱ�ѹ���ɿ�ϵ��
	float			fProtLineKZp2;				//	�����������ϵ��
	float			fProtLineKZlm2;				//	������������ϵ��
	float			fProtLineKZfh3;				//	�������θ���ϵ��

	float			fProtLineKZ0rel1;			//	�ӵؾ����οɿ�ϵ��
	float			fProtLineKZT0rel1;			//	�ӵؾ��������ڱ�ѹ���ɿ�ϵ��
	float			fProtLineKZ0p2;				//	�ӵؾ��������ϵ��
	float			fProtLineKZ0lm2;			//	�ӵؾ���������ϵ��
	float			fProtLineKZ0p3;				//	�ӵؾ��������ϵ��
	float			fProtLineKZ0lm3;			//	�ӵؾ���������ϵ��

	unsigned char	bProtLineIkdz2UsingKlm;		//	��ʱ�����ٶϰ�����������
	unsigned char	bProtLineIkdz3Coord3;		//	����������������·���
	unsigned char	bProtLineI0ProtIntoTran;	//	��������������ѹ����
	unsigned char	bProtLineI0dz2Coord2;		//	�����������ߢ�����
	unsigned char	bProtLineI0dz3Coord3;		//	�����������ߢ�����
	unsigned char	bProtLineI0dz3Unb;			//	�ն���·�����ΰ���ѹ����ƽ���������

	unsigned char	bProtLineZProtIntoTran;		//	�������ο���������ѹ����
	unsigned char	bProtLineZdz2Coord2;		//	�����������ڢ�����
	unsigned char	bProtLineZdz2UsingKlm;		//	�������ΰ�����������
	unsigned char	bProtLineZdz3Coord3;		//	�����������ڢ�����
	unsigned char	bProtLineZdz3UsingKfh;		//	�������ΰ���������

	unsigned char	bProtLineZ0ProtIntoTran;	//	�ӵؾ����ο���������ѹ����
	unsigned char	bProtLineZ0dz2Coord2;		//	�ӵؾ��������ڢ�����
	unsigned char	bProtLineZ0dz2UsingKlm;		//	�ӵؾ����ΰ�����������
	unsigned char	bProtLineZ0dz3Coord3;		//	�ӵؾ��������ڢ�����
	unsigned char	bProtLineZ0dz3UsingKlm;		//	�ӵؾ����ΰ�����������
	////////////////////////////////////////////////////////////////////////

	float			fProtTranKkslm1;				//	���ɲ������������ϵ��
	float			fProtTranKkllm1;				//	���ɲ������������ϵ��
	float			fProtTranKkrel3;			//	���������ɿ�ϵ��
	float			fProtTranKkres3;			//	������������ϵ��

	float			fProtTranKuop;				//	��ѹ������ѹֵ
	float			fProtTranKuoprel;			//	��ѹ�����ɿ�ϵ��
	float			fProtTranKuopres;			//	��ѹ��������ϵ��

	float			fProtTranK0lm1;				//	����������ϵ��
	float			fProtTranK0rel2;			//	�����οɿ�ϵ��
	////////////////////////////////////////////////////////////////////////

	float			fProtBusKunbrel;			//	��ƽ������ɿ�ϵ��
	float			fProtBusKbrkrel;			//	���ζ��߿ɿ�ϵ��
	unsigned char	bProtBusFaultUnb;
	////////////////////////////////////////////////////////////////////////

	float			fProtGenKdrel;				//	�ݲ���ɿ�ϵ��
	float			fProtGenKkrel;				//	���������ɿ�ϵ��
	float			fProtGenKkres;				//	������������ϵ��
	float			fProtGenKap;				//	�����ڷ���Ӱ��ϵ��
	float			fProtGenKss;				//	����������ͬ��ϵ��
	////////////////////////////////////////////////////////////////////////

	float			fProtLoadKst;				//	�綯��������������
	float			fProtLoadKdrel;				//	�ݲ���ɿ�ϵ��
	float			fProtLoadKkrel;				//	���������ɿ�ϵ��
	float			fProtLoadKkres;				//	������������ϵ��
	float			fProtLoadKap;				//	�����ڷ���Ӱ��ϵ��
	float			fProtLoadKss;				//	����������ͬ��ϵ��
	////////////////////////////////////////////////////////////////////////

	float			fProtCapKkrel2;				//	��ʱ�����ٶϿɿ�ϵ��
	float			fProtCapKkrel3;				//	���������ɿ�ϵ��
	float			fProtCapKkres3;				//	������������ϵ��
	////////////////////////////////////////////////////////////////////////

	float			fProtReacKdrel;				//	������ɿ�ϵ��
	float			fProtReacKkrel1;			//	�����ٶϿɿ�ϵ��
	float			fProtReacKkrel3;			//	���������ɿ�ϵ��
	float			fProtReacKkres3;			//	������������ϵ��
	////////////////////////////////////////////////////////////////////////

	float			fProtBreakerKkp1;			//	����������ϵ��
	float			fProtBreakerKklm1;			//	�����������ϵ��
	float			fProtBreakerKkp2;			//	����������ϵ��
	float			fProtBreakerKkr;			//	�ϻ������ɿ�ϵ��

	float			fProtLineKksen1;			//	��·˲ʱ�����ٶ�����ϵ��
	float			fProtLineKksen2;			//	��·��ʱ�����ٶ�����ϵ��
	float			fProtLineKksen3;			//	��·��ʱ�޹���������ϵ��
	float			fProtLineK0sen1;			//	��·����������ϵ��
	float			fProtLineK0sen2;			//	��·����������ϵ��
	float			fProtLineK0sen3;			//	��·����������ϵ��
	float			fProtTranKksen3;			//	��ѹ��������������ϵ��
	float			fProtGenKksen3Near;			//	��������󱸹�����������ϵ��
	float			fProtGenKksen3Far;			//	�����Զ�󱸹�����������ϵ��
	float			fProtLoadKksen3;			//	�綯��������������ϵ��
	float			fProtCapKksen2;				//	������������ʱ�����ٶ�����ϵ��
	float			fProtCapKksen3;				//	����������������������ϵ��
	float			fProtReacKksen1;			//	�����翹�������ٶ�����ϵ��
	float			fProtReacKksen3;			//	�����翹��������������ϵ��
	float			fProtBreakerKsen1;			//	ĸ��/�ֶο��ع����������ϵ��
	float			fProtBreakerKsen2;			//	ĸ��/�ֶο��ع����������ϵ��
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
	//	��·���������С��·����
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
	//	��·����һ�����������С��·����������·�򰴱�ѹ���Բ��
	float			fN1IkminI;
	float			fN1I0minI;
	float			fN1IkminJ;
	float			fN1I0minJ;
	char			szN1IkminIBus[MDB_CHARLEN];
	char			szN1I0minIBus[MDB_CHARLEN];
	char			szN1IkminJBus[MDB_CHARLEN];
	char			szN1I0minJBus[MDB_CHARLEN];

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
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
	//	I�ౣ������ֵ
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
	//	J�ౣ������ֵ
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
	//	I�ౣ������ϵ��
	float			fKsen1I;
	float			fKsen2I;
	float			fKsen3I;

	float			fK0sen1I;
	float			fK0sen2I;
	float			fK0sen3I;

	//////////////////////////////////////////////////////////////////////////
	//	J�ౣ������ϵ��
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
	unsigned char	b3Wind;			//	�������
	int				nTopoBusH;		//	��ѹ������ĸ��
	int				nTopoBusM;		//	��ѹ������ĸ��
	int				nTopoBusL;		//	��ѹ������ĸ��

	float			fRateVoltH;
	float			fRateVoltM;
	float			fRateVoltL;
	float			fRateH;
	float			fRateM;
	float			fRateL;

	unsigned char	bLoadTran;		//	���ɱ�ѹ������ֻ��һ�����ӵ�Դ�ı�ѹ��
	unsigned char	bPowerH;		//	��Դ��ǣ�=0��Դ��=1��Դ
	unsigned char	bPowerM;		//	��Դ��ǣ�=0��Դ��=1��Դ
	unsigned char	bPowerL;		//	��Դ��ǣ�=0��Դ��=1��Դ

	unsigned char	nZGStatH;		//	��ѹ�����������=0����ͨ��=1��֧·��=2�ӵ�
	unsigned char	nZGStatM;		//	��ѹ�����������=0����ͨ��=1��֧·��=2�ӵ�
	unsigned char	nZGStatL;		//	��ѹ�����������=0����ͨ��=1��֧·��=2�ӵ�

	//////////////////////////////////////////////////////////////////////////
	//	�������ĸ�߶�·����ѹ���������С��·�������൱�ڱ�ѹ���ڲ���·
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
	//	����Բ�ĸ�߶�·����ѹ���������С��·����
	float			fIobmaxH	;
	float			fIobmaxM	;
	float			fIobmaxL	;

	float			fIobminH	;
	float			fIobminM	;
	float			fIobminL	;

	//////////////////////////////////////////////////////////////////////////
	//	���䱾��ĸ�߶�·����ѹ���������С��·����
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
	//	�������һ��������·�����С��·����
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
	//	����������ƽ����������õ�����������ʾ���ڲ���
	float			fIkunbH;
	float			fIkunbM;
	float			fIkunbL;

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
	float			fKkslm1;		//	��Դ�������α�������ϵ��
	float			fKkllm1;		//	���ɲ������α�������ϵ��
	float			fKkrel3;		//	���������ɿ�ϵ��
	float			fKkres3;		//	������������ϵ��

	float			fKuop;			//	��ѹ������ѹֵ
	float			fKuoprel;		//	��ѹ�����ɿ�ϵ��
	float			fKuopres;		//	��ѹ��������ϵ��

	float			fK0lm1;			//	����������ϵ��
	float			fK0rel2;		//	�����οɿ�ϵ��

	//////////////////////////////////////////////////////////////////////////
	//	�����������
	float			fIkdz1H;		//	����������ζ����������Ǹ��ɲ��������Ե�Դ����Ч
	float			fIkdz1M;		//	����������ζ����������Ǹ��ɲ��������Ե�Դ����Ч
	float			fIkdz1L;		//	����������ζ����������Ǹ��ɲ��������Ե�Դ����Ч

	float			fIkdz3H;		//	����������������
	float			fIkdz3M;		//	����������������
	float			fIkdz3L;		//	����������������

	float			fUopH;			//	��ѹ����������ѹ
	float			fUopM;			//	��ѹ����������ѹ
	float			fUopL;			//	��ѹ����������ѹ

	float			fI0dz1H;		//	�����ζ�������
	float			fI0dz1M;		//	�����ζ�������
	float			fI0dz1L;		//	�����ζ�������

	float			fI0dz2H;		//	�����ζ�������
	float			fI0dz2M;		//	�����ζ�������
	float			fI0dz2L;		//	�����ζ�������

	//////////////////////////////////////////////////////////////////////////
	//	��������ϵ��У��
	float			fKksen3H;		//	������������ϵ��
	float			fKksen3M;		//	������������ϵ��
	float			fKksen3L;		//	������������ϵ��

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
	//	ĸ������·��������󸺺ɵ���
	float			fIbrankmax;			//	֧·����·����
	float			fIbranemax;			//	֧·��󸺺ɵ���
	float			fIkmin;				//	ĸ����С��·����

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
	float			fKunbrel;			//	���򣺲�ƽ������ɿ�ϵ��	һ�����2��3
	float			fKbrkrel;			//	���򣺶��ζ��߿ɿ�ϵ��	һ��ȡ1.1~1.3
	unsigned char	bFaultUnb;			//	�ⲿ��·����������ƽ�����

	//////////////////////////////////////////////////////////////////////////
	//	�����������
	float			fIkop;				//	�ⲿ��·���㲻ƽ���������ܲ�ƽ������������������
	float			fIlop;				//	��󸺺ɼ��㲻ƽ���������ܲ�ƽ������������������
	float			fIoop;				//	��ܶ��ζ��߲������������
	float			fIdz;				//	�������������	Idz

	//////////////////////////////////////////////////////////////////////////
	//	��������ϵ��У��
	float			fKsen;				//	��������ϵ������С��2

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
	//	���������·�������С��·����
	float			fIkmax;
	float			fIkminNear;
	float			fIkminFar;

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
	float			fKdrel;			//	�ݲ���ɿ�ϵ��
	float			fKkrel;			//	���������ɿ�ϵ��
	float			fKkres;			//	������������ϵ��
	float			fKap;			//	�����ڷ���Ӱ��ϵ��
	float			fKss;			//	����������ͬ��ϵ��

	//////////////////////////////////////////////////////////////////////////
	//	�����������
	float			fIunbmax;		//	�ݲ����ƽ�����	Iunbmax
	float			fIddz;			//	�ݲ����������	Iddz
	float			fIkdz;			//	����������������

	//////////////////////////////////////////////////////////////////////////
	//	��������ϵ��У��
	float			fKksenNear;		//	����������������ϵ��
	float			fKksenFar;		//	��������Զ������ϵ��

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
	//	���������·�������С��·����
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
	float			fKkrel2;		//	��ʱ�����ٶϱ����ɿ�ϵ��
	float			fKkrel3;		//	���������ɿ�ϵ��
	float			fKkres3;		//	������������ϵ��

	//////////////////////////////////////////////////////////////////////////
	//	�����������
	float			fIkdz2;			//	��ʱ�����ٶ϶�������	Iddz
	float			fIkdz3;			//	����������������

	//////////////////////////////////////////////////////////////////////////
	//	��������ϵ��У��
	float			fKsen2;			//	����������������ϵ��
	float			fKsen3;			//	��������Զ������ϵ��

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
	//	���������·�������С��·����
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
	float			fKdrel;			//	���������ϵ��
	float			fKkrel1;		//	˲ʱ�����ٶϱ����ɿ�ϵ��
	float			fKkrel3;		//	���������ɿ�ϵ��
	float			fKkres3;		//	������������ϵ��

	//////////////////////////////////////////////////////////////////////////
	//	�����������
	float			fIddz;			//	�������������
	float			fIkdz1;			//	˲ʱ�����ٶ϶�������
	float			fIkdz3;			//	����������������

	//////////////////////////////////////////////////////////////////////////
	//	��������ϵ��У��
	float			fKsen1;			//	˲ʱ�����ٶ�����ϵ��
	float			fKsen3;			//	��������Զ������ϵ��

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
	//	���������·�������С��·����
	float			fIkmax;
	float			fIkmin;

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
	float			fKst;			//	�綯��������������
	float			fKdrel;			//	�ݲ���ɿ�ϵ��
	float			fKkrel;			//	���������ɿ�ϵ��
	float			fKkres;			//	������������ϵ��
	float			fKap;			//	�����ڷ���Ӱ��ϵ��
	float			fKss;			//	����������ͬ��ϵ��

	//////////////////////////////////////////////////////////////////////////
	//	�����������
	float			fIunbmax;		//	�ݲ����ƽ�����
	float			fIddz;			//	�ݲ����������
	float			fIkdz;			//	����������������

	//////////////////////////////////////////////////////////////////////////
	//	��������ϵ��У��
	float			fKdsen;			//	˲ʱ�����ٶ�����ϵ��
	float			fKksen;			//	��������Զ������ϵ��

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

	float			fILineRateMax;		//	��·�������
	float			fITranRateMax;		//	��ѹ���������
	unsigned char	bLowVBreaker;
	//////////////////////////////////////////////////////////////////////////
	//	����·��������󸺺ɵ���
	float			fIkmax;				//	����·����
	float			fIkmin;				//	��С��·����

	//////////////////////////////////////////////////////////////////////////
	//	�����������ϵ��
	float			fKkp1;				//	����������ϵ��
	float			fKklm1;				//	�����������ϵ��
	float			fKkp2;				//	����������ϵ��
	float			fKkr;				//	�ϻ������ɿ�ϵ��

	//////////////////////////////////////////////////////////////////////////
	//	�����������
	float			fIkdz1;				//	������α�����������
	float			fIkdz2;				//	������α�����������
	float			fIrdz;				//	�ϻ�������������

	//////////////////////////////////////////////////////////////////////////
	//	��������ϵ��У��
	float			fKsen1;
	float			fKsen2;

	int				nBreaker;
}	DISALIGN;
typedef	struct	_PG_ProtBreaker_	tagPGProtBreaker;
