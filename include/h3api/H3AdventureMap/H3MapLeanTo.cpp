//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapLeanTo.hpp"

namespace h3
{
	_H3API_ eResource H3MapitemLeanTo::GetType()
	{
		return eResource(resType);
	}
	_H3API_ INT32 H3MapitemLeanTo::GetAmount()
	{
		return resValue;
	}
} /* namespace h3 */
