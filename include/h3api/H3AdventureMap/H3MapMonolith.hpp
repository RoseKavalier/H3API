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
	_H3API_DECLARE_(MapitemMonolith);

#pragma pack(push, 4)

	/** @brief data for monoliths on adventure map*/
	struct H3MapitemMonolith
	{
		/** @brief [00] only really used for 2-way monoliths, such that entrance != exit*/
		INT32 index;

		_H3API_ INT32 GetSubtype();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
