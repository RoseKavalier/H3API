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

        namespace NMagicAnimation
        {
            enum eMagicAnimation : INT32
            {
                PRAYER                 = 0,
                LIGHTNING_BOLT         = 1,
                AIR_SHIELD             = 2,
                BACKLASH               = 3,
                ANIMATE_DEAD           = 4,
                ANTI_MAGIC             = 5,
                BLIND                  = 6,
                COUNTERSTROKE          = 7,
                DEATH_RIPPLE           = 8,
                FIREBLAST              = 9,
                DECAY                  = 10,
                FIRE_SHIELD            = 11,
                FIRESTORM              = 12,
                DISRUPTIVERAY_RAY      = 13,
                DISRUPTIVERAY_BURST    = 14,
                FEAR                   = 15,
                METEOR_SHOWER          = 16,
                FRENZY                 = 17,
                FORTUNE                = 18,
                MUCK_AND_MIRE          = 19,
                MIRTH                  = 20,
                HYPNOTIZE              = 21,
                PROTECTION_FROM_AIR    = 22,
                PROTECTION_FROM_WATER  = 23,
                PROTECTION_FROM_FIRE   = 24,
                PRECISION              = 25,
                PROTECTION_FROM_EARTH  = 26,
                SHIELD                 = 27,
                SLAYER                 = 28,
                SACRED_BREATH          = 29,
                SORROW                 = 30,
                TAIL_WIND              = 31,
                FORCEFIELD_2           = 32,
                FORCEFIELD_3           = 33,
                REMOVE_OBSTACLE        = 34,
                BERSERK                = 35,
                BLESS                  = 36,
                CHAIN_LIGHTNING_BOLT   = 37,
                CHAIN_LIGHTNING_DUST   = 38,
                CURE                   = 39,
                CURSE                  = 40,
                DISPEL                 = 41,
                FORGETFULNESS          = 42,
                FIREWALL_2             = 43,
                FIREWALL_3             = 44,
                FROSTRING              = 45,
                ICERAY_BURST           = 46,
                LAND_MINE              = 47,
                MISFORTUNE             = 48,
                LIGHTNING_DUST         = 49,
                RESURRECTION           = 50,
                SACRIFICE_SLAY         = 51,
                SACRIFICE_RESURRECT    = 52,
                SPONTANEOUS_COMBUSTION = 53,
                TOUGH_SKIN             = 54,
                QUICKSAND              = 55,
                WEAKNESS               = 56,
                LAND_MINE_EXPLOSION    = 57,
                DISPEL_QUICKSAND       = 58,
                DISPEL_LAND_MINE       = 59,
                DISPEL_FORCEFIELD_2    = 60,
                DISPEL_FORCEFIELD_3    = 61,
                DISPEL_FIREWALL_2      = 62,
                DISPEL_FIREWALL_3      = 63,
                MAGICBOLT_BURST        = 64,
                FIREWALL_1             = 65,
                DISPELFIREWALL_1       = 66,
                POISON                 = 67,
                BIND                   = 68,
                DISEASE                = 69,
                PARALYZE               = 70,
                AGE                    = 71,
                DEATH_CLOUD            = 72,
                DEATH_BLOW             = 73,
                DRAIN_LIFE             = 74,
                MAGICCHANNEL_SUCK      = 75,
                MAGICCHANNEL_SPEW      = 76,
                MAGIC_DRAIN            = 77,
                MAGIC_RESISTANCE       = 78,
                REGENERATE             = 79,
                DEATH_STARE            = 80,
                ACID_BREATH            = 81,
                POOF                   = 82,
            };
        }
        typedef NMagicAnimation::eMagicAnimation eMagicAnimation;
    }
    typedef NH3Combat::eFortElements        eCombatFortElements;
    typedef NH3Combat::eMissiles            eCombatMissiles;
    typedef NH3Combat::eBattleAction        eCombatAction;
    typedef NH3Combat::eRelativeOrientation eCombatOrientation;
    typedef NH3Combat::eSquareAccess        eCombatSquareAccess;
    typedef NH3Combat::eMagicAnimation      eCombatMagicAnimation;
} /* namespace h3 */
