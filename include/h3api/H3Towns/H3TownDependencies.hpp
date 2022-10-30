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
#include "h3api/H3Constants/H3Limits.hpp"
#include "h3api/H3Constants/H3CstTowns.hpp"

namespace h3
{
	_H3API_DECLARE_(TownDependencies);

#pragma pack(push, 4)

	struct H3TownDependencies
	{
		_H3API_GET_INFO_(0x6977E8, H3TownDependencies);

		H3BuildingsBitfield m_dependency[h3::limits::BUILDINGS];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
