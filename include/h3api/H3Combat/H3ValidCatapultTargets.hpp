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
#include "h3api/H3Constants/H3CstCombat.hpp"

namespace h3
{
	_H3API_DECLARE_(ValidCatapultTargets);

#pragma pack(push, 4)

	// * town wall elements
	struct H3ValidCatapultTargets
	{
		_H3API_SIZE_(0xC);
		_H3API_GET_INFO_(0x4929DD + 3, H3ValidCatapultTargets);

		INT32 fortElementId;
		INT16 hex;
		h3unk16 _f_06;
		INT16 x;
		INT16 y;
	public:
	};
	_H3API_ASSERT_SIZE_(H3ValidCatapultTargets);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
