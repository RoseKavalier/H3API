//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3RMG/H3RmgParameters.hpp"

namespace h3
{
    _H3API_ VOID H3RmgParameters::Validate()
    {
        monsterStrength += 3;
        if (monsterStrength < 1)
            monsterStrength = 1;
        else if (monsterStrength > 5)
            monsterStrength = 5;

        if (computerCount + humanCount < 2)
        {
            computerCount = 1;
            humanCount = 1;
        }
    }
} /* namespace h3 */
