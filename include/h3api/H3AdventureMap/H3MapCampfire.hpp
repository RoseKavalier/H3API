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
#include "h3api/H3Constants/H3CstResources.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemCampfire);

#pragma pack(push, 4)

	/** @brief data for campfire on adventure map*/
	struct H3MapitemCampfire
	{
		/** @brief [00] 0..5 resource type*/
		unsigned  resType : 4;
		/** @brief [04] 4..6 number of resources. Multiply by 100 for gold value*/
		unsigned  resValue : 28;

		_H3API_ eResource GetType();
		_H3API_ INT32 GetGold();
		_H3API_ INT32 GetResourceAmount();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
