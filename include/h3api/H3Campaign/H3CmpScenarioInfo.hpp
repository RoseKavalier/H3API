//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-17              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(CmpScenarioInfo);

#pragma pack(push, 4)

	struct H3CmpScenarioInfo
	{
		_H3API_SIZE_(0x14);
		/** @brief [00]*/
		BOOL8 completed;
		/** @brief [04] total time required*/
		INT32 days;
		/** @brief [08]*/
		INT32 score;
		/** @brief [0C]*/
		INT32 corroverArrayIndex;
		/** @brief [10]*/
		INT32 completionOrder;
	};
	_H3API_ASSERT_SIZE_(H3CmpScenarioInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
