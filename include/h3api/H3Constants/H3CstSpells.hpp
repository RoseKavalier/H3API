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
    namespace NH3Spells
    {
        namespace NSchool
        {
            enum eSchool : INT32
            {
                AIR   = 1,
                FIRE  = 2,
                WATER = 4,
                EARTH = 8,
                ALL   = AIR | FIRE | WATER | EARTH,
            };
        }
        typedef NSchool::eSchool eSchool;

        namespace NTargetType
        {
            enum eTargetType : INT32
            {
                ENEMY    = -1,
                AREA     = 0,
                FRIENDLY = 1,
            };
        }
        typedef NTargetType::eTargetType eTargetType;

        namespace NSpells
        {
            enum eSpell : INT8
            {
                NONE                  = -1,
                SUMMON_BOAT           = 0,
                SCUTTLE_BOAT          = 1,
                VISIONS               = 2,
                VIEW_EARTH            = 3,
                DISGUISE              = 4,
                VIEW_AIR              = 5,
                FLY                   = 6,
                WATER_WALK            = 7,
                DIMENSION_DOOR        = 8,
                TOWN_PORTAL           = 9,
                QUICK_SAND            = 10,
                LAND_MINE             = 11,
                FORCE_FIELD           = 12,
                FIRE_WALL             = 13,
                EARTHQUAKE            = 14,
                MAGIC_ARROW           = 15,
                ICE_BOLT              = 16,
                LIGHTNING_BOLT        = 17,
                IMPLOSION             = 18,
                CHAIN_LIGHTNING       = 19,
                FROST_RING            = 20,
                FIREBALL              = 21,
                INFERNO               = 22,
                METEOR_SHOWER         = 23,
                DEATH_RIPPLE          = 24,
                DESTROY_UNDEAD        = 25,
                ARMAGEDDON            = 26,
                SHIELD                = 27,
                AIR_SHIELD            = 28,
                FIRE_SHIELD           = 29,
                PROTECTION_FROM_AIR   = 30,
                PROTECTION_FROM_FIRE  = 31,
                PROTECTION_FROM_WATER = 32,
                PROTECTION_FROM_EARTH = 33,
                ANTI_MAGIC            = 34,
                DISPEL                = 35,
                MAGIC_MIRROR          = 36,
                CURE                  = 37,
                RESURRECTION          = 38,
                ANIMATE_DEAD          = 39,
                SACRIFICE             = 40,
                BLESS                 = 41,
                CURSE                 = 42,
                BLOODLUST             = 43,
                PRECISION             = 44,
                WEAKNESS              = 45,
                STONE_SKIN            = 46,
                DISRUPTING_RAY        = 47,
                PRAYER                = 48,
                MIRTH                 = 49,
                SORROW                = 50,
                FORTUNE               = 51,
                MISFORTUNE            = 52,
                HASTE                 = 53,
                SLOW                  = 54,
                SLAYER                = 55,
                FRENZY                = 56,
                TITANS_LIGHTNING_BOLT = 57,
                COUNTERSTRIKE         = 58,
                BERSERK               = 59,
                HYPNOTIZE             = 60,
                FORGETFULNESS         = 61,
                BLIND                 = 62,
                TELEPORT              = 63,
                REMOVE_OBSTACLE       = 64,
                CLONE                 = 65,
                FIRE_ELEMENTAL        = 66,
                EARTH_ELEMENTAL       = 67,
                WATER_ELEMENTAL       = 68,
                AIR_ELEMENTAL         = 69,
                /* These abilities are not available to heroes */
                STONE                 = 70,
                POISON                = 71,
                BIND                  = 72,
                DISEASE               = 73,
                PARALYZE              = 74,
                AGING                 = 75,
                DEATH_CLOUD           = 76,
                THUNDERBOLT           = 77,
                DRAGONFLY_DISPEL      = 78,
                DEATH_STARE           = 79,
                ACID_BREATH           = 80,
            };
        }
        typedef NSpells::eSpell eSpell;
    } /* namespace NH3Spells */
    typedef NH3Spells::eSchool     eSpellchool;
    typedef NH3Spells::eTargetType eSpellTarget;
    typedef NH3Spells::eSpell     eSpell;
} /* namespace h3 */
