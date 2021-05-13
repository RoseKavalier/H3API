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
	_H3API_DECLARE_(MapitemFlotsam);

#pragma pack(push, 4)

	/** @brief data for Flotsam on adventure map*/
	struct H3MapitemFlotsam
	{
		enum eType : INT32
		{
			EMPTY,
			WOOD5,
			WOOD5_GOLD200,
			WOOD10_GOLD500,
		};
		eType type;

		_H3API_ INT32 GetWood() const;
		_H3API_ INT32 GetGold() const;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
