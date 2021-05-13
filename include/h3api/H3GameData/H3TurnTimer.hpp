//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(TurnTimer);

#pragma pack(push, 4)

	/** @brief according to WoG*/
	struct H3TurnTimer
	{
		_H3API_SIZE_(0x14);
		_H3API_GET_INFO_(0x4AD194 + 1, H3TurnTimer);

		/** @brief [00]*/
		UINT lastShownTime;
		/** @brief [04]*/
		UINT startTimeMain;
		/** @brief [08]*/
		UINT turnLimit;
		/** @brief [0C]*/
		UINT showNextPeriod;
		/** @brief [10]*/
		UINT battleStartTime;
	};
	_H3API_ASSERT_SIZE_(H3TurnTimer);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
