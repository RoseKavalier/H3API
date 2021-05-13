//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3InputManager.hpp"

namespace h3
{
	_H3API_ H3InputManager::InputMessages& H3InputManager::GetCurrentMessage()
	{
		return messages[currentMessage];
	}
	_H3API_ VOID H3InputManager::AddMouseOverMessage()
	{
		return THISCALL_1(VOID, 0x4ECD00, this);
	}

} /* namespace h3 */
