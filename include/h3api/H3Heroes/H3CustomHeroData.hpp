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
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{
	_H3API_DECLARE_(CustomHeroData);

#pragma pack(push, 4)

	struct H3CustomHeroData
	{
		_H3API_SIZE_(0x14);
		INT32 heroId;
		H3String name;
	};
	_H3API_ASSERT_SIZE_(H3CustomHeroData);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
