//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapFountainFortune.hpp"

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemFountainFortune::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemFountainFortune::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */
