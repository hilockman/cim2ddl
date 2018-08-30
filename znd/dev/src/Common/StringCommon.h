#pragma once

extern	void	FormatRealData(char* lpszReal);
extern	void	FormularBpaDecimalChar(char* lpszValue, const int nDataLen);
extern	void	Trim(char* lpszTrim);
extern	void	TrimEnd(char* lpszTrim);
extern	void	TrimLeft(char* lpszTrim);
extern	void	TrimRight(char* lpszTrim);

extern	float	StringToFloat(const char* lpszFloat);
extern	std::string	DoubleToString(const double fValue);
