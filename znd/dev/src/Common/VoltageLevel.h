#pragma once

namespace	_VoltageLevel
{
	typedef	struct	_VoltageLevelDesc
	{
		int		nIndex;
		char*	lpszVoltName;
		char*	lpszVoltTag;
		float	fNorminal;
		char*	lpszVoltColor;
		char*	lpszVoltColorDesp;
		unsigned char	nVColorR;
		unsigned char	nVColorG;
		unsigned char	nVColorB;
	}	tagVoltageLevelDesc;

	enum VoltageLevelEnumBase	//电压等级的枚举类型
	{
		VoltageLevel_400V=0, 
		VoltageLevel_6kV, 
		VoltageLevel_10kV, 
		VoltageLevel_20kV, 
		VoltageLevel_35kV, 
		VoltageLevel_66kV, 
		VoltageLevel_110kV, 
		VoltageLevel_220kV, 
		VoltageLevel_330kV, 
		VoltageLevel_500kV, 
		VoltageLevel_660kV, 
		VoltageLevel_750kV, 
		VoltageLevel_800kV, 
		VoltageLevel_1000kV, 
		VoltageLevel_13kV, 
		VoltageLevel_15kV, 
		VoltageLevel_18kV, 
		VoltageLevel_24kV, 
		VoltageLevel_690V, 
	};
	const	static	int	g_nVoltageLevelNum=18;	//_VoltageLevel::g_nVoltageLevelNum;

	extern	const	unsigned char	GetVoltageLevelColorR(const int nVoltIndex);
	extern	const	unsigned char	GetVoltageLevelColorG(const int nVoltIndex);
	extern	const	unsigned char	GetVoltageLevelColorB(const int nVoltIndex);
	extern	const	char*	GetVoltageLevelName(const int nIndex);
	extern	const	char*	GetVoltageLevelTag(const int nIndex);
	extern	const	int		GetVoltageLevelIndex(const char* lpszVolt);
	extern	const	double	GetVoltageLevelNorminal(const char* lpszVolt);
	extern	const	double	GetVoltageLevelNorminal(const int nIndex);
}
