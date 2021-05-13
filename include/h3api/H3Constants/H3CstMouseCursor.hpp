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
    namespace NH3Mouse
    {
        namespace NMouseCursorType
        {
            enum eMouseCursorType : INT32
            {
                DEFAULT   = 0,
                ADVENTURE = 1,
                COMBAT    = 2,
                SPELL     = 3,
                ARTIFACT  = 4,
            };
        }
        typedef NMouseCursorType::eMouseCursorType eMouseCursorType;

        namespace NAdventureMapCursorType
        {
            enum eAdventureMapCursorType
            {
                ARROWPOINTER         = 0,
                BUSY_WAIT            = 1,
                HERO                 = 2,
                TOWN                 = 3,
                HORSE                = 4,
                ATTACK               = 5,
                BOAT                 = 6,
                ANCHOR               = 7,
                HERO_MEETING         = 8,
                REARING_HORSE        = 9,
                HORSE2               = 10,
                ATTACK2              = 11,
                BOAT2                = 12,
                ANCHOR2              = 13,
                HERO_MEETING2        = 14,
                REARING_HORSE2       = 15,
                HORSE3               = 16,
                ATTACK3              = 17,
                BOAT3                = 18,
                ANCHOR3              = 19,
                HERO_MEETING3        = 20,
                REARING_HORSE3       = 21,
                HORSE4               = 22,
                ATTACK4              = 23,
                BOAT4                = 24,
                ANCHOR4              = 25,
                HERO_MEETING4        = 26,
                REARING_HORSE4       = 27,
                BOAT_1               = 28,
                BOAT_2               = 29,
                BOAT_3               = 30,
                BOAT_4               = 31,
                MAP_SCROLL_NORTH     = 32,
                MAP_SCROLL_NORTHEAST = 33,
                MAP_SCROLL_EAST      = 34,
                MAP_SCROLL_SOUTHEAST = 35,
                MAP_SCROLL_SOUTH     = 36,
                MAP_SCROLL_SOUTHWEST = 37,
                MAP_SCROLL_WEST      = 38,
                MAP_SCROLL_NORTHWEST = 39,
                ARROW_POINTER        = 40,
                DIMENSION_DOOR       = 41,
                SCUTTLE_BOAT         = 42,
            };
        }
        typedef NAdventureMapCursorType::eAdventureMapCursorType eAdventureMapCursorType;

        namespace NBattleFieldCursorType
        {
            enum eBattleFieldCursorType
            {
                NONE             = 0,
                MOVE             = 1,
                FLY              = 2,
                SHOOTING         = 3,
                HERO             = 4,
                QUESTION_MARK    = 5,
                ARROW_POINTER    = 6,
                ATTACK_NORTHEAST = 7,
                ATTACK_EAST      = 8,
                ATTACK_SOUTHEAST = 9,
                ATTACK_SOUTHWEST = 10,
                ATTACK_WEST      = 11,
                ATTACK_NORTHWEST = 12,
                ATTACK_NORTH     = 13,
                ATTACK_SOUTH     = 14,
                HALF_DAMAGE      = 15,
                ATTACK_WALL      = 16,
                HEAL             = 17,
                SACRIFICE        = 18,
                TELEPORT         = 19,
            };
        }
        typedef NBattleFieldCursorType::eBattleFieldCursorType eBattleFieldCursorType;
    }
    typedef NH3Mouse::eMouseCursorType        eCursor;
    typedef NH3Mouse::eAdventureMapCursorType eAdvCursor;
    typedef NH3Mouse::eBattleFieldCursorType  eCmbCursor;
} /* namespace h3 */
