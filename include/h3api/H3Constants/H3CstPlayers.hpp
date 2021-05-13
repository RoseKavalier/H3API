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
    namespace NH3Players
    {
        namespace NPlayerColors
        {
            enum ePlayerColors : INT32
            {
                RED    = 0,
                BLUE   = 1,
                TAN    = 2,
                GREEN  = 3,
                ORANGE = 4,
                PURPLE = 5,
                TEAL   = 6,
                PINK   = 7,
            };
        }
        typedef NPlayerColors::ePlayerColors ePlayerColors;

        namespace NPlayerBit
        {
            /** @brief Player data is often set in bitfield mode to save space, e.g. visiting players*/
            enum ePlayerBit : UINT8
            {
                BIT_RED    = 0x01,
                BIT_BLUE   = 0x02,
                BIT_TAN    = 0x04,
                BIT_GREEN  = 0x08,
                BIT_ORANGE = 0x10,
                BIT_PURPLE = 0x20,
                BIT_TEAL   = 0x40,
                BIT_PINK   = 0x80,
            };
        }
        typedef NPlayerBit::ePlayerBit ePlayerBit;
    } /* namespace NH3Players */
    typedef NH3Players::ePlayerColors ePlayer;
    typedef NH3Players::ePlayerBit    ePlayerBit;
} /* namespace h3 */
