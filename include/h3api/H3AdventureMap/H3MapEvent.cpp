//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapEvent.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3Event* H3MapitemEvent::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Event* H3MapitemEvent::Get(H3Main* main)
	{
		return reinterpret_cast<H3Event*>(&main->mainSetup.pandoraEvents[id]);
	}
	_H3API_ H3PlayersBitfield H3MapitemEvent::EnabledPlayers()
	{
		return H3PlayersBitfield(enabled);
	}
	_H3API_ VOID H3MapitemEvent::SetEnabled(const H3PlayersBitfield& players)
	{
		enabled = players.bits;
	}
} /* namespace h3 */
