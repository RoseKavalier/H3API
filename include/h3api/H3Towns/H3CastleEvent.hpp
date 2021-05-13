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
#include "h3api/H3GameData/H3GlobalEvent.hpp"

namespace h3
{
	_H3API_DECLARE_(CastleEvent);

#pragma pack(push, 4)

	/** @brief format of events in towns*/
	struct H3CastleEvent : public H3GlobalEvent
	{
		_H3API_SIZE_(0x50);
		/** @brief [34] */
		INT32 castleNumber;
		/** @brief [38] */
		H3BuildingsBitfield buildings;
		/** @brief [40] */
		INT16 creatures[7];
	};
	_H3API_ASSERT_SIZE_(H3CastleEvent);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
