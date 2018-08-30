#include "stdafx.h"

#include <string.h>
#include <iostream>
using namespace std;

std::string DoubleToString( const double fValue )
{
	char szBuffer[32];

#if defined(_MSC_VER) && defined(__STDC_SECURE_LIB__) // Use secure version with visual studio 2005 to avoid warning. 
	sprintf_s(szBuffer, sizeof(szBuffer), "%#.16g", fValue); 
#else	
	sprintf(szBuffer, "%#.16g", fValue); 
#endif
	char* ch = szBuffer + strlen(szBuffer) - 1;
	if (*ch != '0') return szBuffer; // nothing to truncate, so save time
	while (ch > szBuffer && *ch == '0')
	{
		--ch;
	}
	char* last_nonzero = ch;
	while(ch >= szBuffer)
	{
		switch(*ch)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			--ch;
			continue;
		case '.':
			// Truncate zeroes to save bytes in output, but keep one.
			*(last_nonzero+2) = '\0';
			return szBuffer;
		default:
			return szBuffer;
		}
	}
	return szBuffer;
}

float StringToFloat(const char* lpszFloat) 
{ 
	// check
	if (!lpszFloat) 
		return 0.0;
	if (strstr(lpszFloat, "e") != NULL || strstr(lpszFloat, "E") != NULL)
		return (float)atof(lpszFloat);

	unsigned char bNegative = 0; 
	unsigned char bDec = 0; 
	char chByte = '0';
	float fInteger = 0;
	float fDecimal = 0;
	float fDecPower = 0.1f;

	int		nCharPos = 0;
	// 进行首位判断，判断是否是负数 
	if (lpszFloat[0] == '-')
	{
		bNegative = 1;
		nCharPos = 1;
	} 
	else 
	{
		bNegative = 0; 
	} 

	while (*(lpszFloat+nCharPos) != '\0')
	{
		chByte = *(lpszFloat+nCharPos);
		if (bDec)	// 小数 
		{ 
			if (chByte >= '0' && chByte <= '9') 
			{
				fDecimal += (chByte - '0') * fDecPower;
				fDecPower = fDecPower * 0.1f;
			}
			else
			{
				return (bNegative ? -(fInteger+fDecimal) : fInteger+fDecimal);
			}
		}
		else	// 整数 
		{
			if (chByte >= '0' && chByte <= '9')
				fInteger = fInteger * 10 + chByte - '0';
			else if (chByte == '.')
				bDec = 1;
			else
				return (bNegative ? -fInteger : fInteger);
		}
		nCharPos++; 
	} 
	return (bNegative ? -(fInteger+fDecimal) : fInteger+fDecimal); 
}

void	FormatRealData(char* lpszReal)
{
	register int	i;
	unsigned char	bHasPoint=0;
	for (i=0; i<(int)strlen(lpszReal); i++)
	{
		if (lpszReal[i] == '.')
		{
			bHasPoint=1;
			break;
		}
	}
	if (bHasPoint)
	{
		for (i=(int)strlen(lpszReal)-1; i>=0; i--)
		{
			if (lpszReal[i] == '0')
			{
				lpszReal[i]='\0';
			}
			else if (lpszReal[i] == '.')
			{
				lpszReal[i]='\0';
				break;
			}
			else
			{
				break;
			}
		}
	}
}

void FormularBpaDecimalChar(char* lpszValue, const int nDataLen)
{
	register int	i;
	unsigned char	bFlag;
	int		nChar;

	if (strlen(lpszValue) <= 0)
		return;

	char	szChar[260];
	memset(szChar, 0, 260);

	//	清除0和空格
	bFlag=1;
	nChar=0;
	for (i=0; i<(int)strlen(lpszValue); i++)
	{
		if (lpszValue[i] == '-')
		{
			szChar[nChar++]=lpszValue[i];
		}
		else
		{
			if (!bFlag)
			{
				if (lpszValue[i] == ' ' || lpszValue[i] == '\t' || lpszValue[i] == '\n' || lpszValue[i] == '\r' || lpszValue[i] == '\0')	//	数字后为空格和0跳出
					break;
			}
			if (bFlag)
			{
				if (lpszValue[i] == ' ' || lpszValue[i] == '0')			//	数字前为空格和0忽略
					continue;
				else
					bFlag=0;
			}
			szChar[nChar++]=lpszValue[i];
		}
	}
	szChar[nChar++]='\0';

	if (strstr(szChar, ".") != NULL)
	{
		for (i=(int)strlen(szChar)-1; i>=0; i--)
		{
			if (szChar[i] == ' ' || szChar[i] == '0')	//	小数点后的空格和0忽略
				szChar[i]='\0';
			else
				break;
		}
	}

	for (i=nDataLen; i<(int)strlen(szChar); i++)	//	按给定长度截断
		szChar[i]='\0';

	strcpy(lpszValue, szChar);
}

void Trim(char* lpszTrim)
{
	register int	i;
	std::string	strChar;

	strChar.clear();

	for (i=0; i<(int)strlen(lpszTrim); i++)
	{
		if (lpszTrim[i] != ' ' && lpszTrim[i] != '\t')
			strChar += lpszTrim[i];
	}
	strChar += '\0';
	strcpy(lpszTrim, strChar.c_str());
}

void TrimEnd(char* lpszTrim)
{
	register int	i;
	for (i=(int)strlen(lpszTrim); i>=0; i--)
	{
		if (lpszTrim[i] == '\0')
			continue;

		if (lpszTrim[i] == '\n' || lpszTrim[i] == '\r' || lpszTrim[i] == '\r\n' || lpszTrim[i] == '\n\r')
			lpszTrim[i]='\0';
		else
			break;
	}
}

void TrimLeft(char* lpszTrim)
{
	register int	i;
	int		bBlank, nChar;
	std::string	strChar;

	strChar.clear();

	bBlank=1;

	nChar=0;
	for (i=0; i<(int)strlen(lpszTrim); i++)
	{
		if (bBlank)
		{
			if (lpszTrim[i] == ' ')
				continue;
		}

		bBlank=0;

		strChar += lpszTrim[i];
	}
	strChar += '\0';
	strcpy(lpszTrim, strChar.c_str());
}

void TrimRight(char* lpszTrim)
{
	register int	i;
	for (i=(int)strlen(lpszTrim); i>=0; i--)
	{
		if (lpszTrim[i] == '\0')
			continue;

		if (lpszTrim[i] == ' ')
			lpszTrim[i]='\0';
		else
			break;
	}
}
