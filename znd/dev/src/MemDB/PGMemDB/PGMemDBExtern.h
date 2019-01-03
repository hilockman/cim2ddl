#pragma once

namespace	PGMemDB
{
	static	const char*	m_lpszPGMemDBLogFile="PGMemDB.log";
	static	const char*	m_lpszAbnormalLogFile = "PGMemDBAbnorm.log";
}
extern	void	ClearLog(const char* m_lpszPGMemDBLogFile);
extern	void	Log(const char* m_lpszPGMemDBLogFile, char* pformat, ...);
