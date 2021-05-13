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
	_H3API_DECLARE_(ObjectDetails);

#pragma pack(push, 4)

	// * the counterpart to H3ObjectAttributes
	struct H3ObjectDetails
	{
		_H3API_SIZE_(0xC);
		/** @brief [0] */
		// * reference to H3ObjectAttributes
		UINT32 setup;
		/** @brief [4] */
		// * x position on map
		UINT8 x;
		/** @brief [5] */
		// * y position on map
		UINT8 y;
		/** @brief [6] */
		// * z position on map
		UINT8 z;
		/** @brief [8] */
		// * reference to object's DEF for drawing purposes
		UINT16 num;
		/** @brief [A] */
		// * Random(0, 255) on map start
		UINT8 frameRandomness;
	};
	_H3API_ASSERT_SIZE_(H3ObjectDetails);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
