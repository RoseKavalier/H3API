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
#include "h3api/H3AdventureMap/H3MapSign.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemOceanBottle);

#pragma pack(push, 4)

	struct H3OceanBottle : H3Signpost
	{
	};

	struct H3MapitemOceanBottle : H3MapitemSign
	{
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
