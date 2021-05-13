//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Creatures/H3CreatureInformation.hpp"

namespace h3
{
    _H3API_ LPCSTR H3CreatureInformation::GetCreatureName(INT32 count) const
    {
        return count > 1 ? namePlural : nameSingular;
    }
    _H3API_ H3Resources H3CreatureInformation::UpgradeCost(H3CreatureInformation* upg, INT32 count) const
    {
        H3Resources res = upg->cost;
        res.RemoveResources(cost);
        for (INT32* it = res.begin(); it != res.end(); ++it)
            *it *= count;
        return res;
    }
} /* namespace h3 */
