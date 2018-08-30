#pragma	once
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <io.h>
#include <float.h>

#include "VoltageLevel.h"

namespace	_VoltageLevel
{
	static	const	tagVoltageLevelDesc	g_VoltageLevelDescArray[]=
	{
		{	VoltageLevel_400V,		"400V",		"V400V",	0.4f,	"grey",			"»ÒÉ«",	128,	128,	128,	}, 
		{	VoltageLevel_6kV,		"6kV",		"V6kV",		6.3f,	"darkbule",		"ÉîÀ¶",	0,		0,		139,	}, 
		{	VoltageLevel_10kV,		"10kV",		"V10kV",	10.5f,	"crimson",		"ç­ºì",	185,	72,		66,		}, 
		{	VoltageLevel_20kV,		"20kV",		"V20kV",	21,		"brown",		"Àæ»Æ",	226,	172,	6,		}, 
		{	VoltageLevel_35kV,		"35kV",		"V35kV",	37,		"yellow",		"ÏÊ»Æ",	255,	255,	0,		}, 
		{	VoltageLevel_66kV,		"66kV",		"V66kV",	70,		"gold",			"³È»Æ",	255,	204,	0,		}, 
		{	VoltageLevel_110kV,		"110kV",	"V110kV",	115,	"vermeil",		"Öìºì",	240,	65,		85,		}, 
		{	VoltageLevel_220kV,		"220kV",	"V220kV",	230,	"purple",		"×ÏÉ«",	128,	0,		128,	}, 
		{	VoltageLevel_330kV,		"330kV",	"V330kV",	345,	"brightblue",	"ÁÁÀ¶",	30,		144,	255,	}, 
		{	VoltageLevel_500kV,		"500kV",	"V500kV",	525,	"red",			"ºìÉ«",	255,	0,		0,		}, 
		{	VoltageLevel_660kV,		"660kV",	"V660kV",	700,	"orange",		"³ÈÉ«",	250,	128,	10,		}, 
		{	VoltageLevel_750kV,		"750kV",	"V750kV",	800,	"orange",		"³ÈÉ«",	250,	128,	10,		}, 
		{	VoltageLevel_800kV,		"800kV",	"V800kV",	840,	"blue",			"ÖÐÀ¶",	0,		0,		255,	}, 
		{	VoltageLevel_1000kV,	"1000kV",	"V1000kV",	1050,	"blue",			"ÖÐÀ¶",	0,		0,		255,	}, 
		{	VoltageLevel_13kV,		"13.8kV",	"V13.8kV",	13.8f,	"lightgreen",	"Ç³ÂÌ",	0,		210,	0,		}, 
		{	VoltageLevel_15kV,		"15.75kV",	"V15.75kV",	15.75f,	"darkgreen",	"ÂÌÉ«",	0,		128,	0,		}, 
		{	VoltageLevel_18kV,		"18kV",		"V18kV",	18,		"brown",		"Àæ»Æ",	226,	172,	6,		}, 
		{	VoltageLevel_24kV,		"24kV",		"V24kV",	24,		"brown",		"Àæ»Æ",	226,	172,	6,		}, 
		{	VoltageLevel_690V,		"0.69kV",	"V0.69kV",	0.69f,	"white",		"°×É«",	255,	255,	255,	}, 
	};

	const	char*	GetVoltageLevelName(const int nVoltIndex)
	{
		if (nVoltIndex >= 0 && nVoltIndex < sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc))
			return g_VoltageLevelDescArray[nVoltIndex].lpszVoltName;

		return "";
	}

	const	char*	GetVoltageLevelTag(const int nVoltIndex)
	{
		if (nVoltIndex >= 0 && nVoltIndex < sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc))
			return g_VoltageLevelDescArray[nVoltIndex].lpszVoltTag;

		return "";
	}

	const	unsigned char	GetVoltageLevelColorR(const int nVoltIndex)
	{
		if (nVoltIndex >= 0 && nVoltIndex < sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc))
			return g_VoltageLevelDescArray[nVoltIndex].nVColorR;

		return 0;
	}

	const	unsigned char	GetVoltageLevelColorG(const int nVoltIndex)
	{
		if (nVoltIndex >= 0 && nVoltIndex < sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc))
			return g_VoltageLevelDescArray[nVoltIndex].nVColorG;

		return 0;
	}

	const	unsigned char	GetVoltageLevelColorB(const int nVoltIndex)
	{
		if (nVoltIndex >= 0 && nVoltIndex < sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc))
			return g_VoltageLevelDescArray[nVoltIndex].nVColorB;

		return 0;
	}

	const	int GetVoltageLevelIndex(const char* lpszVolt)
	{
		register int	i;
		for (i=0; i<sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc); i++)
		{
			if (stricmp(g_VoltageLevelDescArray[i].lpszVoltName, lpszVolt) == 0)
				return i;
		}

		return VoltageLevel_10kV;
	}

	const	double GetVoltageLevelNorminal(const int nVoltIndex)
	{
		if (nVoltIndex >= 0 && nVoltIndex < sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc))
			return g_VoltageLevelDescArray[nVoltIndex].fNorminal;
		return 0;
	}

	const	double GetVoltageLevelNorminal(const char* lpszVolt)
	{
		register int	i;
		double	fNominal=0;
		for (i=0; i<sizeof(g_VoltageLevelDescArray)/sizeof(tagVoltageLevelDesc); i++)
		{
			if (strcmp(g_VoltageLevelDescArray[i].lpszVoltName, lpszVolt) == 0)
			{
				fNominal=g_VoltageLevelDescArray[i].fNorminal;
				break;
			}
		}

		return fNominal;
	}
}
