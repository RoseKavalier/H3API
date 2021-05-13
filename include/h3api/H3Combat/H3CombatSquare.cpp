//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Combat/H3CombatSquare.hpp"

namespace h3
{
    _H3API_ H3CombatCreature* H3CombatSquare::GetMonster()
	{
		return GetCreature();
	}
    _H3API_ H3CombatCreature* H3CombatSquare::GetCreature()
    {
        return THISCALL_1(H3CombatCreature*, 0x4E7230, this);
    }
} /* namespace h3 */
