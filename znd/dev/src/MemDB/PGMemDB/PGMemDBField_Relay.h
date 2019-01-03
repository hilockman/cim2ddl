#pragma once
static	tagMemDBField	g_PGProtSettingFieldArray[]=
{
	{	PG_PROTSETTING_PROTKER,						"ProtKer",					"����:���������ϵ��",							MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKREL1,				"ProtLineKkrel1",			"����:��·˲ʱ�����ٶϿɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKREL2,				"ProtLineKkrel2",			"����:��·��ʱ�����ٶϿɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKLM2,				"ProtLineKklm2",			"����:��·��ʱ�����ٶ�����ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKRELP3,				"ProtLineKkrelp3",			"����:��·��ʱ�޹������ɿ�ϵ��(�������)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKRELL3,				"ProtLineKkrell3",			"����:��·��ʱ�޹������ɿ�ϵ��(��󸺺�)",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL1,				"ProtLineK0rel1",			"����:��·�����οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL2,				"ProtLineK0rel2",			"����:��·��������������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL3,				"ProtLineK0rel3",			"����:��·�����οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0REL4,				"ProtLineK0rel4",			"����:��·������οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEKZREL1,				"ProtLineKZrel1",			"����:��·�������οɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZTREL1,				"ProtLineKZTrel1",			"����:��·�����������ڱ�ѹ���ɿ�ϵ��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZP2,				"ProtLineKZp2",				"����:��·�����������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZLM2,				"ProtLineKZlm2",			"����:��·������������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZFH3,				"ProtLineKZfh3",			"����:��·�������θ��ɿɿ�ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEKZ0REL1,				"ProtLineKZ0rel1",			"����:��·�ӵؾ����οɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZT0REL1,			"ProtLineKZT0rel1",			"����:��·�ӵؾ��������ڱ�ѹ���ɿ�ϵ��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0P2,				"ProtLineKZ0p2",			"����:��·�ӵؾ��������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0LM2,				"ProtLineKZ0lm2",			"����:��·�ӵؾ���������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0P3,				"ProtLineKZ0p3",			"����:��·�ӵؾ��������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKZ0LM3,				"ProtLineKZ0lm3",			"����:��·�ӵؾ���������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEIKDZ2USINGKLM,		"ProtLineIkdz2UsingKlm",	"����:��·��ʱ�����ٶϰ�����������",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEIKDZ3COORD3,			"ProtLineIkdz3Coord3",		"����:��·����������������·���",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0PROTINTOTRAN,		"ProtLineI0ProtIntoTran",	"����:��·��������������ѹ����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0DZ2COORD2,			"ProtLineI0dz2Coord2",		"����:��·�����������ߢ�����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0DZ3COORD3,			"ProtLineI0dz3Coord3",		"����:��·�����������ߢ�����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEI0DZ3UNB,			"ProtLineI0dz3Unb",			"����:�ն���·�����ΰ���ѹ����ƽ�����",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEZPROTINTOTRAN,		"ProtLineZProtIntoTran",	"����:��·�������ο���������ѹ����",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ2COORD2,			"ProtLineZdz2Coord2",		"����:��·�������������ߢ�����",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ2USINGKLM,		"ProtLineZdz2UsingKlm",		"����:��·�������ΰ�����������",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ3COORD3,			"ProtLineZdz3Coord3",		"����:��·�������������ߢ�����",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZDZ3USINGKFH,		"ProtLineZdz3UsingKfh",		"����:��·�������ΰ������迹����",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEZ0PROTINTOTRAN,		"ProtLineZ0ProtIntoTran",	"����:��·�ӵؾ����ο���������ѹ����",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ2COORD2,			"ProtLineZ0dz2Coord2",		"����:��·�ӵؾ����������ߢ�����",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ2USINGKLM,		"ProtLineZ0dz2UsingKlm",	"����:��·�ӵؾ����ΰ�����������",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ3COORD3,			"ProtLineZ0dz3Coord3",		"����:��·�ӵؾ����������ߢ�����",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEZ0DZ3USINGKLM,		"ProtLineZ0dz3UsingKlm",	"����:��·�ӵؾ����ΰ�����������",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTTRANKKSLM1,				"ProtTranKkslm1",			"����:��ѹ����Դ���ٶϱ�������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKLLM1,				"ProtTranKkllm1",			"����:��ѹ�����ɲ��ٶϱ�������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKREL3,				"ProtTranKkrel3",			"����:��ѹ�����������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKRES3,				"ProtTranKkres3",			"����:��ѹ��������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKUOP	,				"ProtTranKuop",				"����:��ѹ����ѹ������ѹֵ",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKUOPREL,				"ProtTranKuoprel",			"����:��ѹ����ѹ�����ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKUOPRES,				"ProtTranKuopres",			"����:��ѹ����ѹ��������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANK0LM1	,			"ProtTranK0lm1",			"����:��ѹ������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANK0REL2,				"ProtTranK0rel2",			"����:��ѹ�������οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTBUSKUNBREL,				"ProtBusKunbrel",			"����:ĸ�߲�ƽ������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBUSKBRKREL,				"ProtBusKbrkrel",			"����:ĸ�߶��ζ��߿ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBUSFAULTUNB,				"ProtBusFaultUnb",			"����:ĸ�߲�ƽ�����ʹ�ö�·��������",			MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTSETTING_PROTGENKDREL,				"ProtGenKdrel",				"����:������ݲ���ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKREL,				"ProtGenKkrel",				"����:��������������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKRES,				"ProtGenKkres",				"����:�����������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKAP,					"ProtGenKap",				"����:����������ڷ���Ӱ��ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKSS,					"ProtGenKss",				"����:���������������ͬ��ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLOADKST,					"ProtLoadKst",				"����:�綯��������������",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKDREL,				"ProtLoadKdrel",			"����:�綯���ݲ���ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKKREL,				"ProtLoadKkrel",			"����:�綯�����������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKKRES,				"ProtLoadKkres",			"����:�綯��������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKAP,					"ProtLoadKap",				"����:�綯�������ڷ���Ӱ��ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKSS,					"ProtLoadKss",				"����:�綯������������ͬ��ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTCAPKKREL2,				"ProtCapKkrel2",			"����:������������ʱ�����ٶϿɿ�ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKREL3,				"ProtCapKkrel3",			"����:�������������������ɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKRES3,				"ProtCapKkres3",			"����:����������������������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTREACKDREL,				"ProtReacKdrel",			"����:�����翹��������ɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKREL1,				"ProtReacKkrel1",			"����:�����翹�������ٶϿɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKREL3,				"ProtReacKkrel3",			"����:�����翹�����������ɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKRES3,				"ProtReacKkres3",			"����:�����翹��������������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTBREAKERKKP1,				"ProtBreakerKkp1",			"����:ĸ��/�ֶο��ع���������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKLM1,			"ProtBreakerKklm1",			"����:ĸ��/�ֶο��ع����������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKP2,				"ProtBreakerKkp2",			"����:ĸ��/�ֶο��ع���������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKR,				"ProtBreakerKkr",			"����:ĸ��/�ֶο��غϻ������ɿ�ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTSETTING_PROTLINEKKSEN1,				"ProtLineKksen1",			"У��:��·˲ʱ�����ٶ�����ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKSEN2,				"ProtLineKksen2",			"У��:��·��ʱ�����ٶ�����ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEKKSEN3,				"ProtLineKksen3",			"У��:��·��ʱ�޹���������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0SEN1,				"ProtLineK0sen1",			"У��:��·����������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0SEN2,				"ProtLineK0sen2",			"У��:��·����������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLINEK0SEN3,				"ProtLineK0sen3",			"У��:��·����������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTTRANKKSEN3,				"ProtTranKksen3",			"У��:��ѹ��������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKSEN3NEAR,			"ProtGenKksen3Near",		"У��:��������󱸹�����������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTGENKKSEN3FAR,			"ProtGenKksen3Far",			"У��:�����Զ�󱸹�����������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTLOADKKSEN3,				"ProtLoadKksen3",			"У��:�綯��������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKSEN2,				"ProtCapKksen2",			"У��:������������ʱ�����ٶ�����ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTCAPKKSEN3,				"ProtCapKksen3",			"У��:����������������������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKSEN1,				"ProtReacKksen1",			"У��:�����翹�������ٶ�����ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTREACKKSEN3,				"ProtReacKksen3",			"У��:�����翹��������������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKSEN1,			"ProtBreakerKksen1",		"У��:ĸ��/�ֶο��ع����������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTSETTING_PROTBREAKERKKSEN2,			"ProtBreakerKksen2",		"У��:ĸ��/�ֶο��ع����������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtLineFieldArray[]=
{
	{	PG_PROTLINE_NAME,				"Name",					"��·����",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},

	{	PG_PROTLINE_SUBI,				"SubI",					"��վI",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_SUBJ,				"SubJ",					"��վJ",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_VOLT,				"Volt",					"��ѹ�ȼ�",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTLINE_NORMINALVOLT,		"NorminalVolt",			"���ѹ",									MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_RATE,				"Rate",					"�����(����)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_TOPOBUSI,			"TopoBusI",				"I������ĸ��",								MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTLINE_TOPOBUSJ,			"TopoBusJ",				"J������ĸ��",								MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTLINE_POWERED,			"Powered",				"��Դ���",									MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_SRCGENI,			"SrcGenI",				"I���Դ����",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_PROTLINE_SRCGENJ,			"SrcGenJ",				"J���Դ����",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
	{	PG_PROTLINE_ZGROUND,			"ZGround",				"���ӱ�ѹ���ӵ����Ե���",					MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZGTOPOBUSI,			"ZGTopoBusI",			"I������ӵ�����ĸ��",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTLINE_ZGTOPOBUSJ,			"ZGTopoBusJ",			"J������ӵ�����ĸ��",						MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTLINE_IKMAXI,				"IkmaxI",				"I����·ĩ�˶�·����·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MAXI,				"I0maxI",				"I����·ĩ�˶�·����������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0TRANI,			"I0TranI",				"I����·ĩ�˱�ѹ���Բ��·����������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMININEAR,			"IkminINear",			"I����·���˶�·��С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MININEAR,			"I0minINear",			"I����·���˶�·��С�������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMINIFAR,			"IkminIFar",			"I����·Զ�˶�·��С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MINIFAR,			"I0minIFar",			"I����·Զ�˶�·��С�������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IKMAXJ,				"IkmaxJ",				"J����·ĩ�˶�·����·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MAXJ,				"I0maxJ",				"J����·ĩ�˶�·����������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0TRANJ,			"I0TranJ",				"J����·ĩ�˱�ѹ���Բ��·����������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMINJNEAR,			"IkminJNear",			"J����·���˶�·��С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MINJNEAR,			"I0minJNear",			"J����·���˶�·��С�������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IKMINJFAR,			"IkminJFar",			"J����·Զ�˶�·��С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0MINJFAR,			"I0minJFar",			"J����·Զ�˶�·��С�������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IKINTOTRANI,		"IkIntoTranI",			"I����·ĩ�˶�·����·�������ѹ��",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_IKINTOTRANJ,		"IkIntoTranJ",			"J����·ĩ�˶�·����·�������ѹ��",			MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_N1IKMINI,			"N1IkminI",				"I��һ��������·Զ�˶�·��С��·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINI,			"N1I0minI",				"I��һ��������·Զ�˶�·��С�������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1IKMINJ,			"N1IkminJ",				"J��һ��������·Զ�˶�·��С��·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINJ,			"N1I0minJ",				"J��һ��������·Զ�˶�·��С�������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_N1IKMINIBUS,		"N1IkminIBus",			"I��һ��������·Զ�˶�·ĸ��",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINIBUS,		"N1I0minIBus",			"I��һ��������·Զ������ĸ��",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_N1IKMINJBUS,		"N1IkminJBus",			"J��һ��������·Զ�˶�·ĸ��",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTLINE_N1I0MINJBUS,		"N1I0minJBus",			"J��һ��������·Զ������ĸ��",					MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},

	{	PG_PROTLINE_KREL1,				"Krel1",				"����:˲ʱ�����ٶϿɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KREL2,				"Krel2",				"����:��ʱ�����ٶϿɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KLM2,				"Klm2",					"����:��ʱ�����ٶ�����ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KRELP3,				"KrelP3",				"����:�������ɿ�ϵ��(�������)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KRELL3,				"KrelL3",				"����:�������ɿ�ϵ��(��󸺺�)",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_K0REL1,				"K0rel1",				"����:�����οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0REL2,				"K0rel2",				"����:�����οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0REL3,				"K0rel3",				"����:�����οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0REL4,				"K0rel4",				"����:������οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KZREL1,				"KZrel1",				"����:�������οɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZTREL1,			"KZTrel1",				"����:�����������ڱ�ѹ���ɿ�ϵ��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZP2,				"KZp2",					"����:�����������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZLM2,				"KZlm2",				"����:������������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZFH3,				"KZfh3",				"����:�������θ��ɿɿ�ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KZ0REL1,			"KZ0rel1",				"����:�ӵؾ����οɿ�ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZT0REL1,			"KZT0rel1",				"����:�ӵؾ��������ڱ�ѹ���ɿ�ϵ��",		MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0P2,				"KZ0p2",				"����:�ӵؾ��������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0LM2,				"KZ0lm2",				"����:�ӵؾ���������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0P3,				"KZ0p3",				"����:�ӵؾ��������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KZ0LM3,				"KZ0lm3",				"����:�ӵؾ���������ϵ��",				MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IKDZ2USINGKLM,		"Ikdz2UsingKlm",		"��ʱ�����ٶϰ�����������",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_IKDZ3COORD3,		"Ikdz3Coord3",			"����������������·���",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0PROTINTOTRAN	,	"I0ProtIntoTran",		"��������������ѹ����",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0DZ2COORD2,		"I0dz2Coord2",			"�����������ߢ�����",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0DZ3COORD3,		"I0dz3Coord3",			"�����������ߢ�����",					MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_I0DZ3UNB,			"I0dz3Unb	",			"�ն���·�����ΰ���ѹ����ƽ���������",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_ZPROTINTOTRAN,		"ZProtIntoTran",		"�������ο���������ѹ����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ2COORD2,			"Zdz2Coord2",			"�������������ߢ�����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ2USINGKLM,		"Zdz2UsingKlm",			"�������ΰ�����������(������ȼ�)",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ3COORD3,			"Zdz3Coord3",			"�������������ߢ�����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_ZDZ3USINGKFH,		"Zdz3UsingKfh",			"�������ΰ������迹����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_Z0PROTINTOTRAN,		"Z0ProtIntoTran",		"�ӵؾ����ο���������ѹ����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2COORD2,		"Z0dz2Coord2",			"�ӵؾ����������ߢ�����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2USINGKLM,		"Z0dz2UsingKlm",		"�ӵؾ����ΰ�����������(������ȼ�)",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3COORD3,		"Z0dz3Coord3",			"�ӵؾ����������ߢ�����",				MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3USINGKLM,		"Z0dz3UsingKlm",		"�ӵؾ����ΰ�����������(������ȼ�)",		MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_IDZ1I,				"Idz1I",				"I��˲ʱ�����ٶ�����ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ2I,				"Idz2I",				"I����ʱ�����ٶ�����ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ3I,				"Idz3I",				"I�����������ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_I0DZ1I,				"I0dz1I",				"I�������ζ�ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ2I,				"I0dz2I",				"I�������ζ�ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ3I,				"I0dz3I",				"I�������ζ�ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ1INTOTRANI,		"I0dz1IntoTranI",		"I�������α����������ѹ��",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_ZDZ1I,				"Zdz1I",				"I��������������ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ2I,				"Zdz2I",				"I��������������ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ3I,				"Zdz3I",				"I��������������ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_Z0DZ1I,				"Z0dz1I",				"I��ӵؾ����ζ�ֵ",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2I,				"Z0dz2I",				"I��ӵؾ����ζ�ֵ",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3I,				"Z0dz3I",				"I��ӵؾ����ζ�ֵ",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_IDZ1J,				"Idz1J",				"J��˲ʱ�����ٶ�����ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ2J,				"Idz2J",				"J����ʱ�����ٶ�����ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_IDZ3J,				"Idz3J",				"J�����������ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_I0DZ1J,				"I0dz1J",				"J�������ζ�ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ2J,				"I0dz2J",				"J�������ζ�ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ3J,				"I0dz3J",				"J�������ζ�ֵ",							MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_I0DZ1INTOTRANJ,		"I0dz1IntoTranJ",		"J�������α����������ѹ��",				MDBFieldCategoryOutput,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTLINE_ZDZ1J,				"Zdz1J",				"J��������������ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ2J,				"Zdz2J",				"J��������������ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_ZDZ3J,				"Zdz3J",				"J��������������ֵ",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_Z0DZ1J,				"Z0dz1J",				"J��ӵؾ����ζ�ֵ",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ2J,				"Z0dz2J",				"J��ӵؾ����ζ�ֵ",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_Z0DZ3J,				"Z0dz3J",				"J��ӵؾ����ζ�ֵ",						MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KSEN1I,				"Ksen1I",				"У��:I��˲ʱ�����ٶ�����ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN2I,				"Ksen2I",				"У��:I����ʱ�����ٶ�����ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN3I,				"Ksen3I",				"У��:I�ඨʱ�޹���������ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_K0SEN1I,			"K0sen1I",				"У��:I������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN2I,			"K0sen2I",				"У��:I������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN3I,			"K0sen3I",				"У��:I������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_KSEN1J,				"Ksen1J",				"У��:J��˲ʱ�����ٶ�����ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN2J,				"Ksen2J",				"У��:J����ʱ�����ٶ�����ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_KSEN3J,				"Ksen3J",				"У��:J�ඨʱ�޹���������ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_K0SEN1J,			"K0sen1J",				"У��:J������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN2J,			"K0sen2J",				"У��:J������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTLINE_K0SEN3J,			"K0sen3J",				"У��:J������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTLINE_ACLINESEGMENTPTR,	"ACLineSegmentPtr",		"��·����",									MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtTranFieldArray[]=
{
	{	PG_PROTTRAN_NAME,				"Name",					"��ѹ������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},
	{	PG_PROTTRAN_SUB,				"Sub",					"��վ",										MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN,			0,	NULL,	},

	{	PG_PROTTRAN_VOLTH,				"VoltH",				"��ѹ���ѹ�ȼ�",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTTRAN_VOLTM,				"VoltM",				"��ѹ���ѹ�ȼ�",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTTRAN_VOLTL,				"VoltL",				"��ѹ���ѹ�ȼ�",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_SHORTER,	0,	NULL,	},
	{	PG_PROTTRAN_3WIND,				"ThreeWind",			"�������",								MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_TOPOBUSH,			"TopoBusH",				"��ѹ������ĸ��",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTTRAN_TOPOBUSM,			"TopoBusM",				"��ѹ������ĸ��",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTTRAN_TOPOBUSL,			"TopoBusL",				"��ѹ������ĸ��",							MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTTRAN_RATEVOLTH,			"RateVoltH",			"��ѹ����ѹ(ǧ��)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEVOLTM,			"RateVoltM",			"��ѹ����ѹ(ǧ��)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEVOLTL,			"RateVoltL",			"��ѹ����ѹ(ǧ��)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEH,				"RateH",				"��ѹ������(����)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEM,				"RateM",				"��ѹ������(����)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_RATEL,				"RateL",				"��ѹ������(����)",						MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_LOADTRAN,			"LoadTran",				"���ɱ�ѹ��",								MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_POWERH,				"PowerH",				"��ѹ���Դ���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_POWERM,				"PowerM",				"��ѹ���Դ���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_POWERL,				"PowerL",				"��ѹ���Դ���",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_ZGSTATH,			"ZGStatH",				"��ѹ��������",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_ZGSTATM,			"ZGStatM",				"��ѹ��������",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},
	{	PG_PROTTRAN_ZGSTATL,			"ZGStatL",				"��ѹ��������",							MDBFieldCategoryAid,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTTRAN_ITMAXH,				"ItmaxH",				"��ѹ���ѹ���ڲ�����·����(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMAXM,				"ItmaxM",				"��ѹ���ѹ���ڲ�����·����(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMAXL,				"ItmaxL",				"��ѹ���ѹ���ڲ�����·����(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_ITMINH,				"ItminH",				"��ѹ���ѹ���ڲ���С��·����(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMINM,				"ItminM",				"��ѹ���ѹ���ڲ���С��·����(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_ITMINL,				"ItminL",				"��ѹ���ѹ���ڲ���С��·����(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0TMAXH,			"I0tmaxH",				"��ѹ���ѹ���ڲ�����������(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMAXM,			"I0tmaxM",				"��ѹ���ѹ���ڲ�����������(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMAXL,			"I0tmaxL",				"��ѹ���ѹ���ڲ�����������(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0TMINH,			"I0tminH",				"��ѹ���ѹ���ڲ���С�������(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMINM,			"I0tminM",				"��ѹ���ѹ���ڲ���С�������(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0TMINL,			"I0tminL",				"��ѹ���ѹ���ڲ���С�������(����)",		MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IOBMAXH,			"IobmaxH",				"��ѹ��Բ��������·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMAXM,			"IobmaxM",				"��ѹ��Բ��������·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMAXL,			"IobmaxL",				"��ѹ��Բ��������·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IOBMINH,			"IobminH",				"��ѹ��Բ������С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMINM,			"IobminM",				"��ѹ��Բ������С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IOBMINL,			"IobminL",				"��ѹ��Բ������С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMAXHNEAR,			"IkmaxHNear",			"��ѹ��ĸ�߹�������·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXMNEAR,			"IkmaxMNear",			"��ѹ��ĸ�߹�������·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXLNEAR,			"IkmaxLNear",			"��ѹ��ĸ�߹�������·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMINHNEAR,			"IkminHNear",			"��ѹ��ĸ�߹�����С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINMNEAR,			"IkminMNear",			"��ѹ��ĸ�߹�����С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINLNEAR,			"IkminLNear",			"��ѹ��ĸ�߹�����С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMAXHNEAR,		"I0kmaxHNear",			"��ѹ��ĸ�߹�������������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXMNEAR,		"I0kmaxMNear",			"��ѹ��ĸ�߹�������������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXLNEAR,		"I0kmaxLNear",			"��ѹ��ĸ�߹�������������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMINHNEAR,		"I0kminHNear",			"��ѹ��ĸ�߹�����С�������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINMNEAR,		"I0kminMNear",			"��ѹ��ĸ�߹�����С�������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINLNEAR,		"I0kminLNear",			"��ѹ��ĸ�߹�����С�������(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMAXHFAR,			"IkmaxHFar",			"��ѹ��һ��������·ĩ��������·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXMFAR,			"IkmaxMFar",			"��ѹ��һ��������·ĩ��������·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMAXLFAR,			"IkmaxLFar",			"��ѹ��һ��������·ĩ��������·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKMINHFAR,			"IkminHFar",			"��ѹ��һ��������·ĩ������С��·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINMFAR,			"IkminMFar",			"��ѹ��һ��������·ĩ������С��·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKMINLFAR,			"IkminLFar",			"��ѹ��һ��������·ĩ������С��·����(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMAXHFAR,			"I0kmaxHFar",			"��ѹ��һ��������·ĩ��������������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXMFAR,			"I0kmaxMFar",			"��ѹ��һ��������·ĩ��������������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMAXLFAR,			"I0kmaxLFar",			"��ѹ��һ��������·ĩ��������������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0KMINHFAR,			"I0kminHFar",			"��ѹ��һ��������·ĩ������С�������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINMFAR,			"I0kminMFar",			"��ѹ��һ��������·ĩ������С�������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0KMINLFAR,			"I0kminLFar",			"��ѹ��һ��������·ĩ������С�������(����)",	MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKUNBH,				"IkunbH",				"��ѹ�಻ƽ�����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKUNBM,				"IkunbM",				"��ѹ�಻ƽ�����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKUNBL,				"IkunbL",				"��ѹ�಻ƽ�����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_KKSLM1,				"Kkslm1",				"����:��Դ�������α�������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKLLM1,				"Kkllm1",				"����:���ɲ������α�������ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKREL3,				"Kkrel3",				"����:���������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKRES3,				"Kkres3",				"����:������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_KUOP,				"Kuop",					"����:��ѹ������ѹֵ",						MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KUOPREL,			"Kuoprel",				"����:��ѹ�����ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KUOPRES,			"Kuopres",				"����:��ѹ��������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_K0LM1,				"K0lm1",				"����:����������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_K0REL2,				"K0rel2",				"����:�����οɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKDZ1H,				"Ikdz1H",				"��ѹ�ฺ�ɲ�������������������(����)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ1M,				"Ikdz1M",				"��ѹ�ฺ�ɲ�������������������(����)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ1L,				"Ikdz1L",				"��ѹ�ฺ�ɲ�������������������(����)",	MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_IKDZ3H,				"Ikdz3H",				"��ѹ�����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ3M,				"Ikdz3M",				"��ѹ�����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_IKDZ3L,				"Ikdz3L",				"��ѹ�����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_UOPH,				"UopH",					"��ѹ�ิѹ����������ѹ(ǧ��)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_UOPM,				"UopM",					"��ѹ�ิѹ����������ѹ(ǧ��)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_UOPL,				"UopL",					"��ѹ�ิѹ����������ѹ(ǧ��)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0DZ1H,				"I0dz1H",				"��ѹ����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ1M,				"I0dz1M",				"��ѹ����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ1L,				"I0dz1L",				"��ѹ����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_I0DZ2H,				"I0dz2H",				"��ѹ����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ2M,				"I0dz2M",				"��ѹ����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_I0DZ2L,				"I0dz2L",				"��ѹ����������������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_KKSEN3H,			"Kksen3H",				"У��:��ѹ�������������ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKSEN3M,			"Kksen3M",				"У��:��ѹ�������������ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTTRAN_KKSEN3L,			"Kksen3L",				"У��:��ѹ�������������ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTTRAN_POWERTRANSFORMERPTR, "PowerTransformerPtr",	"��ѹ������",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtBusFieldArray[]=
{
	{	PG_PROTBUS_NAME,				"Name",					"ĸ������",									MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTBUS_TOPOBUS,				"TopoBus",				"����ĸ��",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTBUS_IBRANKMAX,			"IbrankMax",			"֧·����·����(����)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IBRANEMAX,			"IbraneMax",			"֧·��󸺺ɵ���(����)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IKMIN,				"IkMin",				"��С��·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBUS_KUNBREL,				"Kunbrel",				"����:��ƽ������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_KBRKREL,				"Kbrkrel",				"����:���ζ��߿ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_FAULTUNB,			"Faultunb",				"����:�ⲿ��·����������ƽ�����(����)",	MDBFieldCategoryParam,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTBUS_IKOP,				"Ikop",					"�ⲿ��·���㲻ƽ�����(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_ILOP,				"Ilop",					"��󸺺ɼ��㲻ƽ�����(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IOOP,				"Ioop",					"��ܶ��ζ��߲������������(����)",		MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBUS_IKDZ,				"Ikdz",					"����������������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBUS_KSEN,				"Ksen",					"У��:���������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBUS_BUSPTR,				"BusPtr",				"ĸ������",									MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtGenFieldArray[]=
{
	{	PG_PROTGEN_NAME,				"Name",					"���������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTGEN_TOPOBUS,				"TopoBus",				"����ĸ��",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTGEN_RATE,				"Rate",					"�����(����)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_IKMAX,				"IkMax",				"����·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IKMINNEAR,			"IkminNear",			"�豸���˹�����С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IKMINFAR,			"IkminFar",				"�豸Զ�˹�����С��·����(����)",			MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_KDREL,				"Kdrel",				"����:�ݲ���ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KKREL,				"Kkrel",				"����:���������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KKRES,				"Kkres",				"����:������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KAP,					"Kap",					"����:�����ڷ���Ӱ��ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KSS,					"Kss",					"����:����������ͬ��ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_IUNBMAX,				"IunbMax",				"�ݲ����ƽ�����(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IDDZ,				"Iddz",					"�ݲ����������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_IKDZ,				"Ikdz",					"����������������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_KKSENNEAR,			"KksenNear",			"У��:����������������ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTGEN_KKSENFAR,			"KksenFar",				"У��:��������Զ������ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTGEN_GENPTR,				"GenPtr",				"���������",								MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtCapFieldArray[]=
{
	{	PG_PROTCAP_NAME,				"Name",					"��������������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTCAP_TOPOBUS,				"TopoBus",				"����ĸ��",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTCAP_RATE,				"Rate",					"�����(����)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_IKMAX,				"IkMax",				"����·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_IKMIN,				"IkMin",				"��С��·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_KKREL2,				"Kkrel2",				"����:��ʱ�����ٶϱ����ɿ�ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_KKREL3,				"Kkrel3",				"����:���������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_KKRES3,				"Kkres3",				"����:������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_IKDZ2,				"Ikdz2",				"��ʱ�����ٶ���������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_IKDZ3,				"Ikdz3",				"����������������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_KSEN2,				"Ksen2",				"У��:��ʱ�����ٶ�����ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTCAP_KSEN3,				"Ksen3",				"У��:������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTCAP_CAPPTR,				"CapPtr",				"��������������",							MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtReacFieldArray[]=
{
	{	PG_PROTREAC_NAME,				"Name",					"�����翹������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTREAC_TOPOBUS,			"TopoBus",				"����ĸ��",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTREAC_RATE,				"Rate",					"�����(����)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_IKMAX,				"IkMax",				"����·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_IKMIN,				"IkMin",				"��С��·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_KDREL,				"Kdrel",				"����:���������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KKREL1,				"Kkrel1",				"����:˲ʱ�����ٶϱ����ɿ�ϵ��",			MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KKREL3,				"Kkrel3",				"����:���������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KKRES3,				"Kkres3",				"����:������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_IDDZ,				"Iddz",					"�������������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_IKDZ1,				"Ikdz1",				"˲ʱ�����ٶ���������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_IKDZ3,				"Ikdz3",				"����������������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_KSEN1,				"Ksen1",				"У��:˲ʱ�����ٶ�����ϵ��",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTREAC_KSEN3,				"Ksen3",				"У��:������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTREAC_REACPTR,			"ReacPtr",				"�豸����",									MDBFieldCategoryAid,	MDB_SHORT,	sizeof(short),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtMotorFieldArray[]=
{
	{	PG_PROTMOTOR_NAME,				"Name",					"�綯������",								MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTMOTOR_TOPOBUS,			"TopoBus",				"����ĸ��",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},
	{	PG_PROTMOTOR_RATE,				"Rate",					"�����(����)",							MDBFieldCategoryBase,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_IKMAX,				"IkMax",				"����·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_IKMIN,				"IkMin",				"��С��·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_KST,				"Kst",					"����:�綯��������������",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KDREL,				"Kdrel",				"����:�ݲ���ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KKREL,				"Kkrel",				"����:���������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KKRES,				"Kkres",				"����:������������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KAP,				"Kap",					"����:�����ڷ���Ӱ��ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KSS,				"Kss",					"����:����������ͬ��ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_IUNBMAX,			"IunbMax",				"�ݲ����ƽ�����(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_IDDZ,				"Iddz",					"�ݲ����������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_IKDZ,				"Ikdz",					"����������������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_KDSEN,				"Kdsen",				"У��:�ݲ������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTMOTOR_KKSEN,				"Kksen",				"У��:������������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTMOTOR_LOADPTR,			"LoadPtr",				"�豸����",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};

static	tagMemDBField	g_PGProtBreakerFieldArray[]=
{
	{	PG_PROTBREAKER_NAME,			"Name",					"ĸ����·������",							MDBFieldCategoryBase,	MDB_STRING,	MDB_CHARLEN_LONG,		0,	NULL,	},
	{	PG_PROTBREAKER_TOPOBUS,			"TopoBus",				"����ĸ��",									MDBFieldCategoryBase,	MDB_INT,	sizeof(int),			0,	NULL,	},

	{	PG_PROTBREAKER_ILINEMAX,		"ILineMax",				"��·�������(����)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_ITRANMAX,		"ITranMax",				"��ѹ���������(����)",					MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_LOWVBREAKER,		"LowVBreaker",			"��ѹ��·��(�Ա�ѹ����Ϊ�ж�ԭ��)",			MDBFieldCategoryBase,	MDB_BIT,	sizeof(unsigned char),	0,	NULL,	},

	{	PG_PROTBREAKER_IKMAX,			"IkMax",				"����·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_IKMIN,			"IkMin",				"��С��·����(����)",						MDBFieldCategoryAid,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_KKP1,			"Kkp1",					"����:����������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KKLM1,			"Kklm1",				"����:�����������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KKP2,			"Kkp2",					"����:����������ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KKR,				"Kkr",					"����:�ϻ������ɿ�ϵ��",					MDBFieldCategoryParam,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_IKDZ1,			"Ikdz1",				"������α�����������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_IKDZ2,			"Ikdz2",				"������α�����������(����)",				MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_IRDZ,			"Irdz",					"�ϻ�������������(����)",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_KSEN1,			"Ksen1",				"У��:�����������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},
	{	PG_PROTBREAKER_KSEN2,			"Ksen2",				"У��:�����������ϵ��",					MDBFieldCategoryOutput,	MDB_FLOAT,	sizeof(float),			0,	NULL,	},

	{	PG_PROTBREAKER_BREAKERPTR,		"BreakerPtr",			"�豸����",									MDBFieldCategoryAid,	MDB_INT,	sizeof(int),			0,	NULL,	},
};
