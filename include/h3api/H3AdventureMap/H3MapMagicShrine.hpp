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
#include "h3api/H3Constants/H3CstSpells.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemMagicShrine);

#pragma pack(push, 4)

	/** @brief data for magic shrine on adventure map*/
	struct H3MapitemMagicShrine
	{
		/** @brief [00]*/
		unsigned _u1    : 13;
		/** @brief [13] 0..1023 spell ID*/
		unsigned  spell : 10;
		/** @brief [23]*/
		unsigned _u2    : 9;

		_H3API_ eSpell GetSpell();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
