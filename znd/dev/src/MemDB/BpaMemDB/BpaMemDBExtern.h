#pragma once

namespace	BpaMemDB
{
	extern	const	char*	g_lpszLogFile;
	extern	void	BpaMaintDict();

	extern	void	parseDatControl(IN tagBpaBlock* pBpaBlock, IN std::vector<std::string> strLineArray);
	extern	int		BpaIsCardKeyAppend(const int nCategory, const char* lpszKey);

	extern	void	ExtractBpaField(IN const int nColIni, IN const int nColEnd, IN const char* lpszInChar, OUT char* lpszChar);
	extern	void	CheckDecimal(char szFloat[], const int nFloat);

	extern	void	BpaBpaCardKey2DictKey(char* lpszKey, const std::vector<std::string> strPrevCardArray);
}
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
extern	void	ClearLog(const char* lpszLogFile);
