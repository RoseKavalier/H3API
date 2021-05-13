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
	_H3API_DECLARE_(MapitemShipwreckSurvivor);

#pragma pack(push, 4)

	/** @brief data for shipwreck survivors on adventure map*/
	struct H3MapitemShipwreckSurvivor
	{
		INT32 artifactId;
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
