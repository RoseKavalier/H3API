//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	struct H3RmgZone;

#pragma pack(push, 4)

	/** @brief values of RMG.TXT*/
	struct H3RmgZoneConnection
	{
		_H3API_SIZE_(0x1C);
		H3RmgZone* zone;                  /**< @brief [00]*/
		INT32     value;                 /**< @brief [04]*/
		BOOL8     wide;                  /**< @brief [08]*/
		BOOL8     borderGuard;           /**< @brief [09]*/
		BOOL8     created;               /**< @brief [0A]*/
		INT32     minimumHumanPositions; /**< @brief [0C]*/
		INT32     maximumHumanPositions; /**< @brief [10]*/
		INT32     minimumTotalPositions; /**< @brief [14]*/
		INT32     maximumTotalPositions; /**< @brief [18]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgZoneConnection);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
