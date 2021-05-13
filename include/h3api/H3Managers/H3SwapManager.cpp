//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3SwapManager.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"

namespace h3
{
	_H3API_ INT32 H3SwapManager::Close(H3Msg& msg)
	{
		msg.command = eMsgCommand(0x4000);
		msg.subtype = eMsgSubtype(4);
		return 2;
	}
	_H3API_ VOID H3SwapManager::UpdateLuckMorale()
	{
		THISCALL_1(VOID, 0x5AE900, this);
	}
	_H3API_ VOID H3SwapManager::RefreshDialog()
	{
		THISCALL_1(VOID, 0x5B1200, this);
	}

} /* namespace h3 */
