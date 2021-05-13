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
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3GameData/H3Resources.hpp"

namespace h3
{
	_H3API_DECLARE_(GlobalEvent);

#pragma pack(push, 4)

	/** @brief global events set to occur on a date*/
	struct H3GlobalEvent
	{
		_H3API_SIZE_(0x34);
		/** @brief [0] */
		H3String message;
		/** @brief [10] */
		H3Resources resources;
		/** @brief [2C] */
		UINT8 players;
		/** @brief [2D] */
		BOOL8 humanEnabled;
		/** @brief [2E] */
		BOOL8 computerEnabled;
		/** @brief [30] */
		UINT16 firstDay;
		/** @brief [32] */
		UINT16 repeatEveryXDays;
	};
	_H3API_ASSERT_SIZE_(H3GlobalEvent);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
