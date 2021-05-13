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
	_H3API_DECLARE_(MapitemRefugeeCamp);

#pragma pack(push, 4)

	/** @brief data for refugee camps on adventure map*/
	struct H3MapitemRefugeeCamp
	{
		INT32 amount;

		INT32 CreatureType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
