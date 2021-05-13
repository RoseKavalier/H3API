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
	_H3API_DECLARE_(MapitemWaterMill);

#pragma pack(push, 4)

	/** @brief data for water mill on adventure map*/
	struct H3MapitemWaterMill
	{
		/** @brief [00] 0..2 multiply by 500 to get gold amount*/
		unsigned  bonus   : 5;
		/** @brief [05] which players have come by*/
		unsigned  visited : 8;
		/** @brief [13]*/
		unsigned _u1      : 19;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
		_H3API_ INT32 GetGold();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
