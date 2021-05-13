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
#include "h3api/H3GameData/H3Resources.hpp"
#include "h3api/H3Constants/H3CstTowns.hpp"

namespace h3
{
	_H3API_DECLARE_(SpecialBuildingCosts);
	_H3API_DECLARE_(NeutralBuildingCosts);
	_H3API_DECLARE_(DwellingBuildingCosts);

#pragma pack(push, 4)

	struct H3SpecialBuildingCosts
	{
		_H3API_GET_INFO_(0x5C1539 + 3, H3SpecialBuildingCosts);

		// * each town has its own
		H3Resources cost[9];
	};

	struct H3NeutralBuildingCosts
	{
		_H3API_GET_INFO_(0x5C1509 + 3, H3NeutralBuildingCosts);

		// * same for all towns
		H3Resources cost[17];
	};

	struct H3DwellingBuildingCosts
	{
		_H3API_GET_INFO_(0x5C1566 + 3, H3DwellingBuildingCosts);
		// * each town has its own 2 * 7 levels
		// * unupgraded first, then upgraded
		H3Resources cost[2][7];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
