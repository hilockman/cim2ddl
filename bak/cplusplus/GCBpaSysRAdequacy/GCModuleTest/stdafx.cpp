
// stdafx.cpp : 只包括标准包含文件的源文件
// GCModuleTest.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

#if (!defined(WIN64))
#	pragma comment(lib, "../../../../../lib/BpaMemDB.lib")
#	pragma message("Link LibX86 BpaMemDB.lib")
#else
#	pragma comment(lib, "../../../../../lib_x64/BpaMemDB.lib")
#	pragma message("Link LibX64 BpaMemDB.lib")
#endif

#if (!defined(WIN64))
#	pragma comment(lib, "../../../../../lib/PRMemDB.lib")
#else
#	pragma comment(lib, "../../../../../lib_x64/PRMemDB.lib")
#endif

#if (!defined(WIN64))
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib/libPRAdequacyBaseMDd.lib")
#		pragma message("Link LibX86 PRAdequacyBaseMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib/libPRAdequacyBaseMD.lib")
#		pragma message("Link LibX86 PRAdequacyBaseMD.lib")
#	endif
#else
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib_x64/libPRAdequacyBaseMDd.lib")
#		pragma message("Link LibX64 PRAdequacyBaseMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib_x64/libPRAdequacyBaseMD.lib")
#		pragma message("Link LibX64 PRAdequacyBaseMD.lib")
#	endif
#endif

#if (!defined(WIN64))
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib/libTinyXmlMDd.lib")
#		pragma message("Link LibX86 TinyXmlMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib/libTinyXmlMD.lib")
#		pragma message("Link LibX86 TinyXmlMD.lib")
#	endif
#else
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib_x64/libTinyXmlMDd.lib")
#		pragma message("Link LibX64 TinyXmlMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib_x64/libTinyXmlMD.lib")
#		pragma message("Link LibX64 TinyXmlMD.lib")
#	endif
#endif

#if (!defined(WIN64))
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib/libJsonMDd.lib")
#		pragma message("Link LibX86 JsonMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib/libJsonMD.lib")
#		pragma message("Link LibX86 JsonMD.lib")
#	endif
#else
#	ifdef _DEBUG
#		pragma comment(lib, "../../../../../lib_x64/libJsonMDd.lib")
#		pragma message("Link LibX64 JsonMDd.lib")
#	else
#		pragma comment(lib, "../../../../../lib_x64/libJsonMD.lib")
#		pragma message("Link LibX64 JsonMD.lib")
#	endif
#endif
