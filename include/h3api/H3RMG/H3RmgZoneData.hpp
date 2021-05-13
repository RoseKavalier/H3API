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

	struct H3RmgZoneData
	{
		_H3API_SIZE_(4);
		unsigned _b1    : 16;
		unsigned  zone1 : 8;
		unsigned  zone2 : 8;
	};
	_H3API_ASSERT_SIZE_(H3RmgZoneData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
