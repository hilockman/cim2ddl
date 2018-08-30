#include "stdafx.h"
#include "PGMemDB.h"
#include "PGMemDBExtern.h"

namespace	PGMemDB
{
	extern	void	PGFormBusbarSectionType(tagPGBlock* pBlock);
	extern	void	PGFormBreakerDisconnectorInnerType(tagPGBlock* pBlock);
	extern	void	PGFormBreakerDisconnectorJointDeviceType(tagPGBlock* pBlock);
	void	PGMemDBType(tagPGBlock* pBlock)
	{
		PGFormBusbarSectionType(pBlock);
		PGFormBreakerDisconnectorInnerType(pBlock);
		PGFormBreakerDisconnectorJointDeviceType(pBlock);
	}
}