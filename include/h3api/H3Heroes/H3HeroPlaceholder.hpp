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
	_H3API_DECLARE_(HeroPlaceholder);
	struct H3ObjectDetails;

#pragma pack(push, 4)

	/** @brief hero placeholders as they are read from h3m*/
	struct H3HeroPlaceholder
	{
		_H3API_SIZE_(0x10);
		/** @brief [00]*/
		H3ObjectDetails* objectDetails;
		/** @brief [04] FF..07 */
		INT8             owner;
		/** @brief [08]*/
		INT32            type;
		/** @brief [0C]*/
		UINT8            powerRating;
	};
	_H3API_ASSERT_SIZE_(H3HeroPlaceholder);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
