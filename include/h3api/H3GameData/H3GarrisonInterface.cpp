//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GameData/H3GarrisonInterface.hpp"

namespace h3
{
    _H3API_ VOID H3GarrisonInterface::DrawHero(INT32 hero_picture)
    {
        THISCALL_2(VOID, 0x5AA370, this, hero_picture);
    }
    _H3API_ VOID H3GarrisonInterface::DrawCreature(INT32 index, INT32 creature_portrait_index)
    {
        THISCALL_3(VOID, 0x5AA540, this, index, creature_portrait_index);
    }
    _H3API_ VOID H3GarrisonInterface::Redraw(INT32 selected_slot)
    {
        THISCALL_2(VOID, 0x5AA090, this, selected_slot);
    }


} /* namespace h3 */
