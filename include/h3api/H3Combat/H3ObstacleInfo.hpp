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
	_H3API_DECLARE_(ObstacleInfo);

#pragma pack(push, 4)

	// * information about combat obstacles
	struct H3ObstacleInfo
	{
		_H3API_SIZE_(0x14);
		_H3API_GET_INFO_(0x63C7C8, H3ObstacleInfo);

		/** @brief [00] (bitfield)*/
		UINT16 landTypes;
		/** @brief [02] (bitfield)*/
		UINT16 specialGroundTypes;
		/** @brief [04] */
		INT8 heightInCells;
		/** @brief [05] */
		INT8 widthInCells;
		/** @brief [06] */
		INT8 blockedCount;
		/** @brief [07] */
		h3unk8 _f_7;
		/** @brief [08] */
		INT8 relativeCells[8];
		/** @brief [10] */
		LPCSTR defName;
	};
	_H3API_ASSERT_SIZE_(H3ObstacleInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
