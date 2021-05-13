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
    namespace NH3Terrain
    {
        enum eTerrainType : INT32
        {
            DIRT         = 0,
            SAND         = 1,
            GRASS        = 2,
            SNOW         = 3,
            SWAMP        = 4,
            ROUGH        = 5,
            SUBTERRANEAN = 6,
            LAVA         = 7,
            WATER        = 8,
            ROCK         = 9,
        };
    } /* namespace NH3Terrain */
    typedef NH3Terrain::eTerrainType eTerrain;
} /* namespace h3 */
