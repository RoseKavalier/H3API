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
	_H3API_DECLARE_(MapitemLeanTo);

#pragma pack(push, 4)

	/** @brief data for lean to on adventure map*/
	struct H3MapitemLeanTo
	{
		/** @brief [00] 0..31 individual IDs*/
		unsigned  id : 5;
		/** @brief [05]*/
		unsigned _u1 : 1;
		/** @brief [06] 1..5 resource amount, 0 if taken*/
		unsigned  resValue : 4;
		/** @brief [10] 0..6 resource type, no gold*/
		unsigned  resType : 4;
		/** @brief [14]*/
		unsigned _u2 : 18;

		_H3API_ eResource GetType();
		_H3API_ INT32     GetAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
