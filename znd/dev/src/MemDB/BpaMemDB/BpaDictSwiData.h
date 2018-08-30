#pragma once

#include	"BpaDict.h"
static	tagBpa_Dict	m_BpaSwiCaseDictArray[]=
{
	{	"BpaSwi_Case",		"CASE",	"CardKey",				1,	4,	/*A4,	*/	MDB_STRING,		4,		0,		0,		0,		0,	BpaSwiCategory_Con,	0,	/*卡类型,	*/	},
	{	"BpaSwi_Case",		"CASE",	"PFCASE",				6,	15,	/*A10,	*/	MDB_STRING,		10,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*潮流方式名,	*/	},
	{	"BpaSwi_Case",		"CASE",	"ITSKP",				17,	17,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*写求解文件的步长,	*/	},
	{	"BpaSwi_Case",		"CASE",	"NOPRNT",				20,	20,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*NOPRNT, 为1时打印全部输入数据,	*/	},
	{	"BpaSwi_Case",		"CASE",	"DSW",					22,	22,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*输出文件摇摆曲线显示开关,	*/	},
	{	"BpaSwi_Case",		"CASE",	"IWSCC",				23,	23,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*采用新减负荷卡减负荷标记,	*/	},
	{	"BpaSwi_Case",		"CASE",	"ZSW",					24,	24,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*对零序卡进行检查标志,	*/	},
	{	"BpaSwi_Case",		"CASE",	"X2FAC",				45,	49,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*不对称故障时发电机X2与Xdp之比,	*/	},
	{	"BpaSwi_Case",		"CASE",	"XFACT",				50,	54,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机Xdpp与Xdp之比,	*/	},
	{	"BpaSwi_Case",		"CASE",	"TDODPS",				55,	59,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*隐级机的Tdopp(秒),	*/	},
	{	"BpaSwi_Case",		"CASE",	"TQODPS",				60,	64,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*隐级机的Tdopp(秒),	*/	},
	{	"BpaSwi_Case",		"CASE",	"TDODPH",				65,	69,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*凸级水轮机的Tqopp(秒),	*/	},
	{	"BpaSwi_Case",		"CASE",	"TQODPH",				70,	74,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*凸级水轮机的Tdopp(秒),	*/	},
	{	"BpaSwi_Case",		"CASE",	"CFACL2",				75,	80,	/*F6.5,	*/	MDB_FLOAT,		6,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*负序负荷导纳标么值,	*/	},
};

static	tagBpa_Dict	m_BpaSwiFFDictArray[]=
{
	{	"BpaSwi_FF",		"FF",	"CardKey",				1,	2,	/*A2,	*/	MDB_STRING,		2,		0,		0,		0,		0,	BpaSwiCategory_Con,	0,	/*卡类型,	*/	},
	{	"BpaSwi_FF",		"FF",	"T",					5,	7,	/*F3.1,	*/	MDB_STRING,		3,		1,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*计算开始时间(周波),	*/	},
	{	"BpaSwi_FF",		"FF",	"DT",					9,	11,	/*F3.1,	*/	MDB_FLOAT,		3,		1,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*计算步长(周波),	*/	},
	{	"BpaSwi_FF",		"FF",	"ENDT",					13,	17,	/*F5.1,	*/	MDB_FLOAT,		5,		1,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*计算终止时间(周波),	*/	},
	{	"BpaSwi_FF",		"FF",	"DTC",					19,	21,	/*F3.1,	*/	MDB_FLOAT,		3,		1,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*新的步长(周波),	*/	},
	{	"BpaSwi_FF",		"FF",	"ISTP",					23,	25,	/*I3,	*/	MDB_SHORT,		3,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*开始改变步长的时刻(周波),	*/	},
	{	"BpaSwi_FF",		"FF",	"TOLI",					27,	31,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*两次迭代间最大加速功率误差范围,	*/	},
	{	"BpaSwi_FF",		"FF",	"ILIM",					33,	35,	/*I3,	*/	MDB_SHORT,		3,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*一步内网络方程与微分方程最大交替迭代次数,	*/	},
	{	"BpaSwi_FF",		"FF",	"DELANG",				37,	40,	/*F4.4,	*/	MDB_FLOAT,		4,		4,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*两次迭代间最大角度误差范围,	*/	},
	{	"BpaSwi_FF",		"FF",	"DTDV",					42,	43,	/*F2.0,	*/	MDB_FLOAT,		2,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*交流积分步长与直流积分步长之比,	*/	},
	{	"BpaSwi_FF",		"FF",	"DMPMLT",				45,	47,	/*F3.3,	*/	MDB_FLOAT,		3,		3,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机阻尼因子,	*/	},
	{	"BpaSwi_FF",		"FF",	"FRQBSE",				55,	56,	/*F2.0,	*/	MDB_FLOAT,		2,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*系统基准频率,	*/	},
	{	"BpaSwi_FF",		"FF",	"LOVTEX",				58,	58,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：无低电压检查, 否则进行检查,	*/	},
	{	"BpaSwi_FF",		"FF",	"IMBLOK",				60,	60,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*马达滑差达到1时的处理方法,	*/	},
	{	"BpaSwi_FF",		"FF",	"MFDEP",				64,	64,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*摇摆方程与定子方程与频率的关系,	*/	},
	{	"BpaSwi_FF",		"FF",	"IGSLIM",				65,	65,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*非零时, 所有调速器模型GS都采用外限幅,	*/	},
	{	"BpaSwi_FF",		"FF",	"LSOLQIT",				66,	66,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：迭代不收敛, 停止计算,	*/	},
	{	"BpaSwi_FF",		"FF",	"NOANGLIM",				68,	68,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：无最大角度限制, 否则机组间角度超过500度停算,	*/	},
	{	"BpaSwi_FF",		"FF",	"INFBUS",				70,	70,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：所有发电机改为无穷大惯性电机,	*/	},
	{	"BpaSwi_FF",		"FF",	"NOPP",					71,	71,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*非零时, 所有发电机都不考虑次暂态参数,	*/	},
	{	"BpaSwi_FF",		"FF",	"NODQ",					72,	72,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：所有发电机改为经典模型,	*/	},
	{	"BpaSwi_FF",		"FF",	"NOSAT",				73,	73,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*非零时, 所有的发电机不考虑饱和,	*/	},
	{	"BpaSwi_FF",		"FF",	"NOGV",					74,	74,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：所有发电机不计调速器,	*/	},
	{	"BpaSwi_FF",		"FF",	"IEQPC",				75,	75,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*非零时, 所有发电机的磁链恒定,	*/	},
	{	"BpaSwi_FF",		"FF",	"NOEX",					76,	76,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：所有发电机不计调压器,	*/	},
	{	"BpaSwi_FF",		"FF",	"MFTOMG",				77,	77,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*非零时, 所有的发电机卡MF卡都转换为MG卡,	*/	},
	{	"BpaSwi_FF",		"FF",	"NOSC",					78,	78,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：不计所有辅助信号,	*/	},
	{	"BpaSwi_FF",		"FF",	"MGTOMF",				79,	79,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*非零时, 所有的发电机卡MG卡都转换为MF卡,	*/	},
	{	"BpaSwi_FF",		"FF",	"NOLOAD",				80,	80,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*1：所有负荷为恒定阻抗,	*/	},
};

static	tagBpa_Dict	m_BpaSwiF1DictArray[]=
{
	{	"BpaSwi_F1",		"F1",	"CardKey",				1,	2,	/*A2,	*/	MDB_STRING,		2,		0,		0,		0,		0,	BpaSwiCategory_Con,	0,	/*卡类型,	*/	},
	{	"BpaSwi_F1",		"F1",	"TBUSF",				5,	9,	/*F5.4,	*/	MDB_FLOAT,		5,		4,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*母线频率滤波器缺省时间常数,	*/	},
	{	"BpaSwi_F1",		"F1",	"TZERO",				12,	16,	/*F5.4,	*/	MDB_FLOAT,		5,		4,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*测量回路缺省时间常数,	*/	},
	{	"BpaSwi_F1",		"F1",	"IBLOD",				18,	18,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*母线负荷开关,	*/	},
	{	"BpaSwi_F1",		"F1",	"DMPALL",				20,	22,	/*F3.2,	*/	MDB_FLOAT,		3,		2,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*缺省发电机阻尼因子,	*/	},
	{	"BpaSwi_F1",		"F1",	"IAMRTS",				26,	26,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*如果该值不为0, 且CASE卡中的XFACT也不为0, 无论发电机的次暂态参数是否已经用M卡指定, 都要采用缺省的参数来计算发电机的次暂态参数,	*/	},
	{	"BpaSwi_F1",		"F1",	"VCHGL",				28,	31,	/*F4.3,	*/	MDB_FLOAT,		4,		3,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*如果负荷节点电压低于该值, 则负荷将转换为恒阻抗负荷, 缺省值为0.5pu,	*/	},
	{	"BpaSwi_F1",		"F1",	"SPTOSG",				33,	33,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*SP卡为以加速功率作为输入信号的PSS, SG卡为以电磁功率为输入信号的PSS,	*/	},
	{	"BpaSwi_F1",		"F1",	"GSIQU",				37,	41,	/*F5.5,	*/	MDB_FLOAT,		5,		5,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*如果该值不为零, 则数据文件中所有GH卡和GS卡的死区的大小都为该值,	*/	},
	{	"BpaSwi_F1",		"F1",	"TITSKP",				43,	47,	/*F5.1,	*/	MDB_FLOAT,		5,		1,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*从本时间开始, 按照本卡中的48-49列填写的步数进行存储,	*/	},
	{	"BpaSwi_F1",		"F1",	"ITSKP1",				48,	49,	/*I2,	*/	MDB_SHORT,		2,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*从本卡43-47列规定的时间TITSKP开始每隔ITSKP1步存储一次数据,	*/	},
	{	"BpaSwi_F1",		"F1",	"VRLIM",				51,	51,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*FM、FO、FP、FQ、FR、FS、FT和FG型励磁模型的调压器限幅环节为外限幅, 不为0则为内限幅,	*/	},
};

static	tagBpa_Dict	m_BpaSwiF0DictArray[]=
{
	{	"BpaSwi_F0",		"F0",	"CardKey",				1,	2,	/*A2,	*/	MDB_STRING,		2,		0,		0,		0,		0,	BpaSwiCategory_Con,	0,	/*卡类型,	*/	},
	{	"BpaSwi_F0",		"F0",	"IG",					5,	5,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*稳定曲线显示选择,	*/	},
	{	"BpaSwi_F0",		"F0",	"IA",					8,	8,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机最大相对角显示选择,	*/	},
	{	"BpaSwi_F0",		"F0",	"GenBusName1",			10,	17,	/*A8,	*/	MDB_STRING,		8,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机1母线电压,	*/	},
	{	"BpaSwi_F0",		"F0",	"GenBusBase1",			18,	21,	/*F4.0,	*/	MDB_FLOAT,		4,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机1母线电压(kV),	*/	},
	{	"BpaSwi_F0",		"F0",	"GenID1",				22,	22,	/*A1,	*/	MDB_CHAR,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机1识别码,	*/	},
	{	"BpaSwi_F0",		"F0",	"GenBusName2",			24,	31,	/*A8,	*/	MDB_STRING,		8,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机2母线电压,	*/	},
	{	"BpaSwi_F0",		"F0",	"GenBusBase2",			32,	35,	/*F4.0,	*/	MDB_FLOAT,		4,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机2母线电压(kV),	*/	},
	{	"BpaSwi_F0",		"F0",	"GenID2",				36,	36,	/*A1,	*/	MDB_CHAR,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*发电机2识别码,	*/	},
	{	"BpaSwi_F0",		"F0",	"AMAX",					38,	42,	/*F5.0,	*/	MDB_FLOAT,		5,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*相对角Y轴坐标的最大值,	*/	},
	{	"BpaSwi_F0",		"F0",	"AMIN",					43,	47,	/*F5.0,	*/	MDB_FLOAT,		5,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*相对角Y轴坐标的最小值,	*/	},
	{	"BpaSwi_F0",		"F0",	"IV",					50,	50,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*母线电压显示选择,	*/	},
	{	"BpaSwi_F0",		"F0",	"VBUSNAME",				52,	59,	/*A8,	*/	MDB_STRING,		8,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*显示电压变化曲线的母线,	*/	},
	{	"BpaSwi_F0",		"F0",	"VBUSVOLT",				60,	63,	/*F4.0,	*/	MDB_FLOAT,		4,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*显示电压变化曲线的母线电压(kV),	*/	},
	{	"BpaSwi_F0",		"F0",	"IF",					66,	66,	/*I1,	*/	MDB_BIT,		1,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*母线频率显示选择,	*/	},
	{	"BpaSwi_F0",		"F0",	"FBUSNAME",				68,	75,	/*A8,	*/	MDB_STRING,		8,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*显示频率变化曲线的母线,	*/	},
	{	"BpaSwi_F0",		"F0",	"FBUSVOLT",				76,	79,	/*F4.0,	*/	MDB_FLOAT,		4,		0,		0,		0,		0,	BpaSwiCategory_Con,	1,	/*显示频率变化曲线的母线电压(kV),	*/	},
};

static	tagBpa_Dict	m_BpaSwiLNDictArray[]=
{
	{	"BpaSwi_GenLn",		"LN",	"CardKey",					1,	2,	/*A2,	*/	MDB_STRING,	2,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*卡类型,	*/					},
	{	"BpaSwi_GenLn",		"LN",	"ACBus_Name",				4,	11,	/*A8,	*/	MDB_STRING,	8,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*等值发电机名称,	*/			},
	{	"BpaSwi_GenLn",		"LN",	"ACBus_kV",					12,	15,	/*F4.0,	*/	MDB_FLOAT,	4,	0,	0,		0,		0,		BpaSwiCategory_Dat,	0,	/*等值发电机电压,	*/			},
};

