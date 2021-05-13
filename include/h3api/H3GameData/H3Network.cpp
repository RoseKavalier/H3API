//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GameData/H3Network.hpp"
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{
	_H3API_ BOOL8 H3Network::Multiplayer()
	{
		return STDCALL_0(BOOL8, 0x4CE950);
	}

	_H3API_ VOID H3Network::SendMessageToPlayer(LPCSTR text, INT32 player_id)
	{
		FASTCALL_2(VOID, 0x554BB0, text, player_id);
	}

	_H3API_ VOID H3Network::SendMessageToPlayer(const H3String& text, INT32 player_id)
	{
		SendMessageToPlayer(text.String(), player_id);
	}

}
