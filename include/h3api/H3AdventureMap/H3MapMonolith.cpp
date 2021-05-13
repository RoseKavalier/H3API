//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapMonolith.hpp"
#include "h3api/H3AdventureMap/H3MapItems.hpp"

namespace h3
{
	_H3API_ INT32 H3MapitemMonolith::GetSubtype()
	{
		return reinterpret_cast<H3MapItem*>(this)->objectSubtype;
	}
} /* namespace h3 */
