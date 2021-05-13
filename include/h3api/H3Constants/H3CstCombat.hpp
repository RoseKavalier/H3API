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
    namespace NH3Combat
    {
        namespace NFortElements
        {
            enum eFortElements
            {
                DRAWBRIDGE      = 0,
                DRAWBRIDGE_ROPE = 1,
                MOAT            = 2,
                MOAT_LIP        = 3,
                BACK_WALL       = 4,
                UPPER_TOWER     = 5,  // valid catapult target 0
                UPPER_WALL      = 6,  // valid catapult target 1
                UPPER_BUTTRESS  = 7,
                MID_UPPER_WALL  = 8,  // valid catapult target 2
                GATE            = 9,  // valid catapult target 3
                MID_LOWER_WALL  = 10, // valid catapult target 4
                LOWER_BUTTRESS  = 11,
                LOWER_WALL      = 12, // valid catapult target 5
                LOWER_TOWER     = 13, // valid catapult target 6
                KEEP            = 14, // valid catapult target 7
                KEEP_CVR        = 15,
                LOWER_TWR_CVR   = 16,
                UPPER_TWR_CVR   = 17,
            };
        }
        typedef NFortElements::eFortElements eFortElements;

        namespace NMissiles
        {
            enum eMissiles
            {
                UPPER_RIGHT = 0,
                RIGHT       = 1,
                LOWER_RIGHT = 2,
            };
        }
        typedef NMissiles::eMissiles eMissiles;

        namespace NBattleAction
        {
            enum eBattleAction : INT32
            {
                /**
                 * @brief Cancel Action; the stack can do a different action now
                 * but it may still be impossible to force it to do most actions through ERM (WOG)
                */
                CANCEL         = 0,
                CAST_SPELL     = 1, // Hero casts a spell
                WALK           = 2,
                DEFEND         = 3,
                RETREAT        = 4,
                SURRENDER      = 5,
                WALK_ATTACK    = 6,
                SHOOT          = 7,
                WAIT           = 8,
                CATAPULT       = 9,
                MONSTER_SPELL  = 10,
                FIRST_AID_TENT = 11,
                NOTHING        = 12, //No action(can be to disable stack for this round)
            };
        }
        typedef NBattleAction::eBattleAction eBattleAction;

        namespace NRelativeOrientation
        {
            enum eRelativeOrientation : INT32
            {
                TOP_RIGHT      = 0,
                RIGHT          = 1,
                BOTTOM_RIGHT   = 2,
                BOTTOM_LEFT    = 3,
                LEFT           = 4,
                TOP_LEFT       = 5,
                REVERSE_TOP    = 6, // equivalent to 5 or 0 [attacker vs defender]
                REVERSE_BOTTOM = 7, // equivalent to 3 or 2 [attacker vs defender]
            };
        }
        typedef NRelativeOrientation::eRelativeOrientation eRelativeOrientation;

        namespace NSquareAccess
        {
            enum eSquareAccess : UINT8
            {
                INACCESSIBLE = 0,
                CAN_ATTACK   = 1,
                CAN_REACH    = 2,
                ACCESSIBLE   = CAN_ATTACK | CAN_REACH,
            };
        }
        typedef NSquareAccess::eSquareAccess eSquareAccess;

        constexpr INT32 COMBATSQUARE_WIDTH  = 44;
        constexpr INT32 COMBATSQUARE_HEIGHT = 42;
    }
    typedef NH3Combat::eFortElements        eCombatFortElements;
    typedef NH3Combat::eMissiles            eCombatMissiles;
    typedef NH3Combat::eBattleAction        eCombatAction;
    typedef NH3Combat::eRelativeOrientation eCombatOrientation;
    typedef NH3Combat::eSquareAccess        eCombatSquareAccess;
} /* namespace h3 */
