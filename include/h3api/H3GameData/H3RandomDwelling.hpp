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
	_H3API_DECLARE_(RandomDwelling);
	struct H3ObjectDetails;

#pragma pack(push, 4)

	/** @brief random dwellings as they are read from h3m*/
	struct H3RandomDwelling
	{
		_H3API_SIZE_(0x10);

		/** @brief [00] non-zero if set to match a maped town identifier from H3Main::townSetups */
		UINT32           associatedTown;
		/** @brief [04] bitset of available towns*/
		UINT16           availableTowns;
		/** @brief [06] FF..07 */
		INT8             owner;
		/** @brief [07] 0..7*/
		UINT8            minLevel;
		/** @brief [08] 0..7*/
		UINT8            maxLevel;
		/** @brief [0C]*/
		H3ObjectDetails* objectDetails;
	};
	_H3API_ASSERT_SIZE_(H3RandomDwelling);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
