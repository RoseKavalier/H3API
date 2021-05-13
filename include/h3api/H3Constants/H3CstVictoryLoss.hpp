//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
    namespace NH3Loss
    {
        enum eType : INT8
        {
            NONE         = -1,
            LOSE_TOWN    = 0,
            LOSE_HERO    = 1,
            TIME_EXPIRES = 2,
        };
    } /* namespace NH3Loss */


    namespace NH3Victory
    {
        enum eType : INT8
        {
            NONE                  = -1,
            ACQUIRE_ARTIFACT      = 0,
            ACCUMULATE_CREATURE   = 1,
            ACCUMULATE_RESOURCE   = 2,
            UPGRADE_TOWN          = 3,
            BUILD_HOLY_GRAIL      = 4,
            DEFEAT_HERO           = 5,
            CAPTURE_TOWN          = 6,
            DEFEAT_MONSTER        = 7,
            FLAG_GENERATORS       = 8,
            FLAG_MINES            = 9,
            TRANSPORT_ARTIFACT    = 10,
            FESTIVAL_OF_LIFE      = 11, // You have defeated all of the monsters plaguing this land!
            FOOLHARDY_WAYWARDNESS = 12, // You have managed to survive!
        };
    } /* namespace NH3Victory */
    typedef NH3Loss::eType    eLoss;
    typedef NH3Victory::eType eVictory;
} /* namespace h3 */
