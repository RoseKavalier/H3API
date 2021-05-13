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
	_H3API_DECLARE_(MapitemWindmill);

#pragma pack(push, 4)

	/** @brief data for windmill on adventure map*/
	struct H3MapitemWindmill
	{
		/** @brief [00] 1..5, no wood or gold*/
		unsigned  resType  : 4;
		/** @brief [04]*/
		unsigned _u1       : 9;
		/** @brief [13] 3..6 amount of resource, 0 if empty*/
		unsigned  resValue : 4;
		/** @brief [17]*/
		unsigned _u2       : 15;

		_H3API_ eResource GetType();
		_H3API_ INT32     GetAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
