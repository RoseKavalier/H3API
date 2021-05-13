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
#include "h3api/H3Constants/H3Limits.hpp"

namespace h3
{
	_H3API_DECLARE_(WallSection);

#pragma pack(push, 4)

	// * town wall data
	struct H3WallSection
	{
		_H3API_SIZE_(0x24);

		/** @brief [0]*/
		INT16 x;
		/** @brief [2]*/
		INT16 y;
		/** @brief [4] -1 if not set*/
		INT16 hex_id;
		/** @brief [8]*/
		LPCSTR names[5];
		/** @brief [1C] from walls.txt*/
		INT32 name;
		/** @brief [20] from walls.txt*/
		INT16 hp;
	};
	_H3API_ASSERT_SIZE_(H3WallSection);

	/** @brief Information for each piece of town structure in combat screen, 1 per town*/
	struct H3TownFortifications
	{
		_H3API_SIZE_(0x288);
		_H3API_GET_INFO_(0x4947C0 + 3, H3TownFortifications);

		H3WallSection fortifications[h3::limits::FORT_ELEMENTS];
	};
	_H3API_ASSERT_SIZE_(H3TownFortifications);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
