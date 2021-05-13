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
	_H3API_DECLARE_(MapitemPyramid);

#pragma pack(push, 4)

	/** @brief data for pyramid on adventure map*/
	struct H3MapitemPyramid
	{
		/** @brief [00] whether the Pyramid is still up for grabs*/
		unsigned  available : 1;
		/** @brief [01] 0..15*/
		unsigned  id        : 4;
		/** @brief [05] which players have come by*/
		unsigned  visited   : 8;
		/** @brief [13] 0..69 spell id, reserved for level 5 spells*/
		unsigned  spell     : 8;
		/** @brief [21]*/
		unsigned _u1        : 11;

		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
		_H3API_ eSpell GetSpell();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
