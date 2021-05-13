//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Creatures/H3Creature.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
    _H3API_ INT32 H3Creature::GetUpgrade(INT32 id)
    {
        return THISCALL_1(INT32, 0x47AAD0, id);
    }
    _H3API_ BOOL8 H3Creature::HasUpgrade(INT32 id)
    {
        if (!H3Main::Get()->mapKind) /* roe */
        {
            if (
                id == eCreature::AIR_ELEMENTAL  ||
                id == eCreature::EARTH_ELEMENTAL||
                id == eCreature::FIRE_ELEMENTAL ||
                id == eCreature::WATER_ELEMENTAL
               )
                return FALSE;
        }
        return THISCALL_1(BOOL8, 0x47AA50, id);
    }
    _H3API_ LPCSTR H3Creature::GroupName(INT32 amount, INT32 text_variant)
    {
        return FASTCALL_2(LPCSTR, 0x44AAB0, amount, text_variant);
    }
} /* namespace h3 */
