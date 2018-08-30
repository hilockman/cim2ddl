#pragma once
#if _MSC_VER >= 1400 // VC++ 8.0
#pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
#endif

#include "../../../../MemDB/PRMemDB/PRMemDB.h"
using namespace PRMemDB;

namespace	PRAdequacyBase
{
	class CBpaPRParam
	{
	public:
		CBpaPRParam(void);
		~CBpaPRParam(void);

	public:
		int		ReadBpaPRParam(const char* lpszFileName, tagPRBlock* pPRBlock);
		void	SaveBpaPRParam(const char* lpszFileName, tagPRBlock* pPRBlock);
		int		SetBpaPRComParam(tagPRBlock* pPRBlock, const int nTable, const char* lpszKey);

	private:
		int		FindPRACBus(tagPRBlock* pPRBlock, const char* lpszName);
		int		FindPRTCSC(tagPRBlock* pPRBlock, const char* lpszName);
		int		FindPRUPFC(tagPRBlock* pPRBlock, const char* lpszName);
		int		FindPRConverter(tagPRBlock* pPRBlock, const char* lpszName);
		int		FindPRDCLine(tagPRBlock* pPRBlock, const char* lpszName);

		void	SetPRParam_Comm(tagPRBlock* pPRBlock, const unsigned char nDevType, const char* lpszKeyWord, const double fDnP, const double fUpP, const double fDnV, const double fUpV, const double fRerr, const double fTrep);
		void	SetPRParam_Dev(tagPRBlock* pPRBlock, const unsigned char nDevType, const char* lpszName, const double fRerr, const double fTrep, const double fAux=0);
		void	SetPRParam_Dev(tagPRBlock* pPRBlock, const unsigned char nDevType, const char* lpszName, const char* lpszSeriesBusName, const char* lpszParallelBusName, const double fRerr, const double fTrep, const double fAux, const int nAuxType);
	};
}
