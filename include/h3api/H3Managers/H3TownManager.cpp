//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3TownManager.hpp"

namespace h3
{
	_H3API_ VOID H3TownManager::Draw()
	{
		THISCALL_1(VOID, 0x5D5930, this);
	}
	_H3API_ VOID H3TownManager::RefreshScreen()
	{
		THISCALL_1(VOID, 0x5D5810, this);
	}
	_H3API_ BOOL8 H3TownManager::ViewTavern()
	{
		return THISCALL_1(BOOL8, 0x5D82C0, this);
	}
} /* namespace h3 */
