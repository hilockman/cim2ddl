#pragma once

namespace	BpaMemDB
{
	extern	const	char*	g_lpszLogFile;
}
extern	void	Log(const char* lpszLogFile, const char* pformat, ...);
extern	void	ClearLog(const char* lpszLogFile);
