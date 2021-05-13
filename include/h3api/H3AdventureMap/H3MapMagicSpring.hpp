//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemMagicSpring);

#pragma pack(push, 4)

	/** @brief data for magic spring on adventure map*/
	struct H3MapitemMagicSpring
	{
		/** @brief [00] 0..31 Magic Spring index*/
		unsigned  id : 5;
		/** @brief [05]*/
		unsigned _u1 : 1;
		/** @brief [06] did a hero already visit this week*/
		unsigned  used : 1;
		/** @brief [07]*/
		unsigned _u2 : 25;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
