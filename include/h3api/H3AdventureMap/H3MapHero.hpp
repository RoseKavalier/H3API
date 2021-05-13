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
	_H3API_DECLARE_(MapitemHero);
	struct H3Main;
	struct H3Hero;

#pragma pack(push, 4)

	/** @brief data for hero on adventure map*/
	struct H3MapitemHero
	{
		/** @brief [00] hero's identity*/
		INT32 index;

		_H3API_ H3Hero* Get();
		_H3API_ H3Hero* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
