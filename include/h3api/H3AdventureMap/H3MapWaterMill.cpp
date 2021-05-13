//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapWaterMill.hpp"

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemWaterMill::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemWaterMill::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
	_H3API_ INT32 H3MapitemWaterMill::GetGold()
	{
		return bonus * 500;
	}
} /* namespace h3 */
