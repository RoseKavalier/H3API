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
    namespace NH3Resources
    {
        enum eResource : INT32
        {
            /* campaign */
            WOOD_AND_ORE = -3,
            ALL_SPECIAL  = -2,

            /* regular */

            WOOD    = 0,
            MERCURY = 1,
            ORE     = 2,
            SULFUR  = 3,
            CRYSTAL = 4,
            GEMS    = 5,
            GOLD    = 6,
        };
    } /* namespace NH3Resources */
    typedef NH3Resources::eResource eResource;
} /* namespace h3 */
