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
    namespace NH3Dispositions
    {
        /* creature likelihood of joining you */
        enum eDisposition
        {
            COMPLIANT  = 0,
            FRIENDLY   = 1,
            AGGRESSIVE = 2,
            HOSTILE    = 3,
            SAVAGE     = 4,
        };
    }
    typedef NH3Dispositions::eDisposition eDisposition;

    namespace NH3Formats
    {
        /* h3m format for various types */
        enum eFormats
        {
            ROE = 0x0E,
            AB  = 0x15,
            SOD = 0x1C,
            CHR = 0x1D,
            WOG = 0x33,
        };
    }
    typedef NH3Dispositions::eDisposition eCreatureDisposition;
    typedef NH3Formats::eFormats          eMapFormat;
} /* namespace h3 */
