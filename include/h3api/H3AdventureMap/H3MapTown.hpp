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
	_H3API_DECLARE_(MapitemTown);
	struct H3Main;
	struct H3Town;

#pragma pack(push, 4)

	/** @brief data for towns on adventure map*/
	struct H3MapitemTown
	{
		INT32 id;

		_H3API_ H3Town* Get();
		_H3API_ H3Town* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
