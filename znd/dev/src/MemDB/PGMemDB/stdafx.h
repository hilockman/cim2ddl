#pragma once

#define Use_MemDBBase

#ifdef Use_MemDBBase
	#include "../MemDBBase/MemDBBase.h"
	#include "../MemDBBase/MemDBBase_Check.hpp"
	#include "../MemDBBase/MemDBBase_Record.hpp"
	#include "../MemDBBase/MemDBBase_Sort.hpp"
	#include "../../../include/ilog.h"
	using	namespace	MemDBBase;
#endif

