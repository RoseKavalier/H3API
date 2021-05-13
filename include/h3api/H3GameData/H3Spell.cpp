//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GameData/H3Spell.hpp"

namespace h3
{
    _H3API_ INT32 H3Spell::GetBaseEffect(INT32 level, INT32 spellPower)
	{
		return baseValue[level] + spellPower * spEffect;
	}
	_H3API_ BOOL8 H3Spell::SingleTarget(INT32 id, INT32 expertise)
	{
		return FASTCALL_2(BOOL8, 0x59E360, id, expertise);
	}
} /* namespace h3 */
