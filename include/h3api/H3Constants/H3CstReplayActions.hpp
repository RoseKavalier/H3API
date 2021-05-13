//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-10              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
    namespace NH3ReplayActions
    {
        namespace NReplayActions
        {
            enum eType
            {
                HERO_MOVE       = 1,
                HERO_TELEPORT   = 2,
                CAPTURE_MINE    = 3,
                CAPTURE_TOWN    = 4,
                BOAT_HIDE       = 5,
                BOAT_ADD        = 6,
                DELETE_OBJECT   = 7,
                HERO_DELETE     = 8,
                HERO_ADD        = 9,
                PLAYER_DEFEATED = 10, // %s has been vanquished!, seems unused except through load game
                MAP_VISION      = 11,
            };
        }
        typedef NReplayActions::eType eType;
    } /* namespace NH3ReplayActions */
    typedef NH3ReplayActions::eType eReplayAction;
} /* namespace h3 */
