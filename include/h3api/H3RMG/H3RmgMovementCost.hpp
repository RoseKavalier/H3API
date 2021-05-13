//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgMovementCost
	{
		_H3API_SIZE_(4);
		unsigned  cost : 16;
		unsigned _b17  : 16;
	};
	_H3API_ASSERT_SIZE_(H3RmgMovementCost);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
