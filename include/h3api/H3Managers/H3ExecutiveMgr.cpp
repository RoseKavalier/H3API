//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3ExecutiveMgr.hpp"

namespace h3
{
	_H3API_ VOID H3ExecutiveMgr::RemoveManager(H3Manager* mgr)
	{
		THISCALL_2(VOID, 0x4B0950, this, mgr);
	}
	_H3API_ INT H3ExecutiveMgr::AddManager(H3Manager* mgr, INT32 order)
	{
		return THISCALL_3(INT, 0x4B0880, this, mgr, order);
	}
	_H3API_ VOID H3ExecutiveMgr::StartManager(H3Manager* mgr)
	{
		THISCALL_2(VOID, 0x4B0770, this, mgr);
	}

} /* namespace h3 */
