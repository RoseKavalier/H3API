//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(SimulatedSpell);
	typedef H3SimulatedSpell H3AIBattleSpell;

#pragma pack(push, 4)

	struct H3SimulatedSpell
	{
		_H3API_SIZE_(0x24);
		_H3API_CTOR_DTOR_(0x4365D0, -1);
		/** @brief [0] */
		INT32 spellId;
		/** @brief [4] associated secondary skill level to the spell*/
		INT32 skillLevel;
		/** @brief [8] */
		INT32 spellPower;
		/** @brief [C] */
		INT32 spellDuration;
	protected:
		h3unk8 _f_10;
		INT32 _f_14; // {-1}
		INT32 _f_18; // {-1}
		INT32 _f_1C; // {0}
		UINT8 _f_20; // {0}
	};
	_H3API_ASSERT_SIZE_(H3SimulatedSpell);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
