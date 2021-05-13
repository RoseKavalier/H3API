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
#include "h3api/H3Constants/H3CstResources.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemMysticGarden);

#pragma pack(push, 4)

	/** @brief data for mystic garden on adventure map*/
	struct H3MapitemMysticGarden
	{
		/** @brief [00] 0..31 unique ID*/
		unsigned  id      : 5;
		/** @brief [05]*/
		unsigned _u1      : 1;
		/** @brief [06] 5..6 gems or gold*/
		unsigned  resType : 4;
		/** @brief [10] whether the garden contains anything this week*/
		unsigned  hasRes  : 1;
		/** @brief [11]*/
		unsigned _u2      : 21;

		_H3API_ INT32     GetAmount();
		_H3API_ eResource GetType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
