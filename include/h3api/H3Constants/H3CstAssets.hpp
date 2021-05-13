//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-09              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "H3Types.hpp" /* integral typedefs */
#include "h3api/H3Base/H3Config.hpp" /* safe constexpr */

namespace h3
{
    namespace NH3Assets
    {
        namespace NAssets
        {
            enum eType
            {
                TEXTFILE         = 0x02,
                PCX8             = 0x10,
                PCX24            = 0x11,
                PCX16            = 0x12,
                WAV              = 0x20,
                SPELL            = 0x40,
                CREATURE         = 0x42,
                ADVENTURE_OBJECT = 0x43,
                HERO             = 0x44,
                TERRAIN          = 0x45,
                CURSOR           = 0x46,
                INTERFACE        = 0x47,
                COMBAT_HERO      = 0x49,
                FONT             = 0x50,
                PALETTE          = 0x60,
                PALETTE_HDMOD    = 0x61,

                /* based on NWC names, duplicates removed */

                DATA         = 0x01,
                SPREADSHEET  = 0x02,
                BITMAP8      = 0x10,
                BITMAP24     = 0x11,
                BITMAP16     = 0x12,
                BITMAP565    = 0x13,
                BITMAP555    = 0x14,
                BITMAP1555   = 0x21,
                MIDI         = 0x30,
                SPRITE       = 0x40,
                SPRITEDEF    = 0x41,
                ADVOBJ       = 0x43,
                TILESET      = 0x45,
                POINTER      = 0x46,
                SPRITE_FRAME = 0x48,
                X0           = 0x4A, // only "0x" for all 5 of these
                X1           = 0x4B,
                X2           = 0x4C,
                X3           = 0x4D,
                X4           = 0x4E,
                ADVMASK      = 0x4F,
            };
        }
        typedef NAssets::eType eType;

        namespace NCreatureGroups
        {
            enum eCreatureGroups
            {
                MOVING                = 0,
                MOUSE_OVER            = 1,
                STANDING              = 2,
                GETTING_HIT           = 3,
                DEFEND                = 4,
                DEATH                 = 5,
                UNUSED_DEATH          = 6,
                TURN_LEFT             = 7,
                TURN_RIGHT            = 8,
                TURN_LEFT2            = 9,
                TURN_RIGHT2           = 10,
                ATTACK_UP             = 11,
                ATTACK_STRAIGHT       = 12,
                ATTACK_DOWN           = 13,
                SHOOT_UP              = 14,
                SHOOT_STRAIGHT        = 15,
                SHOOT_DOWN            = 16,
                SPELL_ATTACK_UP       = 17,
                SPELL_ATTACK_STRAIGHT = 18,
                SPELL_ATTACK_DOWN     = 19,
                START_MOVING          = 20,
                STOP_MOVING           = 21,
            };
        } /* namespace NCreatureGroups*/
        typedef NCreatureGroups::eCreatureGroups eSpriteCreatureGroups;
    } /* namespace NH3Assets */
    typedef NH3Assets::eType eAsset;
    typedef NH3Assets::eSpriteCreatureGroups eSpriteCreatureGroups;
} /* namespace h3 */
