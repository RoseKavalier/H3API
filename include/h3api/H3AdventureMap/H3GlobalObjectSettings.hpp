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
	_H3API_DECLARE_(GlobalObjectSettings);

#pragma pack(push, 4)

	/** @brief access data about objects on the adventure map*/
	struct H3GlobalObjectSettings
	{
		_H3API_SIZE_(0x10);
		_H3API_GET_INFO_(0x660428, H3GlobalObjectSettings);

		/** @brief [00]*/
		BOOL8  cannotEnter;
		/** @brief [01]*/
		BOOL8  exitTop;
		/** @brief [02] used at 0x548362*/
		BOOL8  canBeRemoved;
		/** @brief [04]*/
		LPCSTR objectName;
		/** @brief [08]*/
		INT32  objectID;
		/** @brief [0C] is it a decorative item?*/
		BOOL32 decor;
	};
	_H3API_ASSERT_SIZE_(H3GlobalObjectSettings);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
