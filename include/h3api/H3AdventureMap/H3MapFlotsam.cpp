//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapFlotsam.hpp"

namespace h3
{

	_H3API_ INT32 H3MapitemFlotsam::GetWood() const
	{
		switch (type)
		{
		case WOOD5:
		case WOOD5_GOLD200:
			return 5;
		case WOOD10_GOLD500:
			return 10;
		default:
			return 0;
		}
	}
	_H3API_ INT32 H3MapitemFlotsam::GetGold() const
	{
		switch (type)
		{
		case WOOD5_GOLD200:
			return 200;
		case WOOD10_GOLD500:
			return 500;
		default:
			return 0;
		}
	}

} /* namespace h3 */
