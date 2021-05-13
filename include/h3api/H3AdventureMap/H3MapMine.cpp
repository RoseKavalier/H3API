//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapMine.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3Mine* H3MapitemMine::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Mine* H3MapitemMine::Get(H3Main* main)
	{
		return &main->minesLighthouses[index];
	}
	_H3API_ BOOL H3Mine::IsAbandonned() const
	{
		return abandoned;
	}

} /* namespace h3 */
