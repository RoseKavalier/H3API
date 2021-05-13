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
#include "h3api/H3Constants/H3CstSkills.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemWitchHut);

#pragma pack(push, 4)

	/** @brief data for witch's hut on adventure map*/
	struct H3MapitemWitchHut
	{
		/** @brief [00]*/
		unsigned _u1      : 5;
		/** @brief [05] which players have come by*/
		signed    visited : 8;
		/** @brief [13] 0..27 secondary skill id*/
		signed    sSkill  : 7;
		/** @brief [20]*/
		unsigned _u2      : 12;

		_H3API_ eSecondary        GetSkill();
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID              SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
