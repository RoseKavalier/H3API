//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapMysticGarden.hpp"

namespace h3
{
	_H3API_ INT32 H3MapitemMysticGarden::GetAmount()
	{
		return GetType() == eResource::GOLD ? 500 : 5;
	}
	_H3API_ eResource H3MapitemMysticGarden::GetType()
	{
		return eResource(resType);
	}
} /* namespace h3 */
