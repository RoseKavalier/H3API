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
    namespace NH3Objects
    {
        namespace NObjectTypes
        {
            enum eObjectTypes : INT32
            {
                NO_OBJ                      = -1,
                ALTAR_OF_SACRIFICE          = 2,
                ANCHOR_POINT                = 3,
                ARENA                       = 4,
                ARTIFACT                    = 5,
                PANDORAS_BOX                = 6,
                BLACK_MARKET                = 7,
                BOAT                        = 8,
                BORDERGUARD                 = 9,
                KEYMASTER                   = 10,
                BUOY                        = 11,
                CAMPFIRE                    = 12,
                CARTOGRAPHER                = 13,
                SWAN_POND                   = 14,
                COVER_OF_DARKNESS           = 15,
                CREATURE_BANK               = 16,
                CREATURE_GENERATOR1         = 17,
                CREATURE_GENERATOR2         = 18,
                CREATURE_GENERATOR3         = 19,
                CREATURE_GENERATOR4         = 20,
                CURSED_GROUND               = 21,
                CORPSE                      = 22,
                MARLETTO_TOWER              = 23,
                DERELICT_SHIP               = 24,
                DRAGON_UTOPIA               = 25,
                EVENT                       = 26,
                EYE_OF_MAGI                 = 27,
                FAERIE_RING                 = 28,
                FLOTSAM                     = 29,
                FOUNTAIN_OF_FORTUNE         = 30,
                FOUNTAIN_OF_YOUTH           = 31,
                GARDEN_OF_REVELATION        = 32,
                GARRISON                    = 33,
                HERO                        = 34,
                HILL_FORT                   = 35,
                GRAIL                       = 36,
                HUT_OF_MAGI                 = 37,
                IDOL_OF_FORTUNE             = 38,
                LEAN_TO                     = 39,
                DECORATIVE                  = 40,
                LIBRARY_OF_ENLIGHTENMENT    = 41,
                LIGHTHOUSE                  = 42,
                MONOLITH_ONE_WAY_ENTRANCE   = 43,
                MONOLITH_ONE_WAY_EXIT       = 44,
                MONOLITH_TWO_WAY            = 45,
                MAGIC_PLAINS1               = 46,
                SCHOOL_OF_MAGIC             = 47,
                MAGIC_SPRING                = 48,
                MAGIC_WELL                  = 49,
                MARKET_OF_TIME              = 50,
                MERCENARY_CAMP              = 51,
                MERMAID                     = 52,
                MINE                        = 53,
                MONSTER                     = 54,
                MYSTICAL_GARDEN             = 55,
                OASIS                       = 56,
                OBELISK                     = 57,
                REDWOOD_OBSERVATORY         = 58,
                OCEAN_BOTTLE                = 59,
                PILLAR_OF_FIRE              = 60,
                STAR_AXIS                   = 61,
                PRISON                      = 62,
                PYRAMID                     = 63,
                RALLY_FLAG                  = 64,
                RANDOM_ART                  = 65,
                RANDOM_TREASURE_ART         = 66,
                RANDOM_MINOR_ART            = 67,
                RANDOM_MAJOR_ART            = 68,
                RANDOM_RELIC_ART            = 69,
                RANDOM_HERO                 = 70,
                RANDOM_MONSTER              = 71,
                RANDOM_MONSTER_L1           = 72,
                RANDOM_MONSTER_L2           = 73,
                RANDOM_MONSTER_L3           = 74,
                RANDOM_MONSTER_L4           = 75,
                RANDOM_RESOURCE             = 76,
                RANDOM_TOWN                 = 77,
                REFUGEE_CAMP                = 78,
                RESOURCE                    = 79,
                SANCTUARY                   = 80,
                SCHOLAR                     = 81,
                SEA_CHEST                   = 82,
                SEER_HUT                    = 83,
                CRYPT                       = 84,
                SHIPWRECK                   = 85,
                SHIPWRECK_SURVIVOR          = 86,
                SHIPYARD                    = 87,
                SHRINE_OF_MAGIC_INCANTATION = 88,
                SHRINE_OF_MAGIC_GESTURE     = 89,
                SHRINE_OF_MAGIC_THOUGHT     = 90,
                SIGN                        = 91,
                SIRENS                      = 92,
                SPELL_SCROLL                = 93,
                STABLES                     = 94,
                TAVERN                      = 95,
                TEMPLE                      = 96,
                DEN_OF_THIEVES              = 97,
                TOWN                        = 98,
                TRADING_POST                = 99,
                LEARNING_STONE              = 100,
                TREASURE_CHEST              = 101,
                TREE_OF_KNOWLEDGE           = 102,
                SUBTERRANEAN_GATE           = 103,
                UNIVERSITY                  = 104,
                WAGON                       = 105,
                WAR_MACHINE_FACTORY         = 106,
                SCHOOL_OF_WAR               = 107,
                WARRIORS_TOMB               = 108,
                WATER_WHEEL                 = 109,
                WATERING_HOLE               = 110,
                WHIRLPOOL                   = 111,
                WINDMILL                    = 112,
                WITCH_HUT                   = 113,
                BRUSH                       = 114,
                BUSH                        = 115,
                CACTUS                      = 116,
                CANYON                      = 117,
                CRATER                      = 118,
                DEAD_VEGETATION             = 119,
                FLOWERS                     = 120,
                FROZEN_LAKE                 = 121,
                HEDGE                       = 122,
                HILL                        = 123,
                HOLE                        = 124,
                KELP                        = 125,
                LAKE                        = 126,
                LAVA_FLOW                   = 127,
                LAVA_LAKE                   = 128,
                MUSHROOMS                   = 129,
                LOG                         = 130,
                MANDRAKE                    = 131,
                MOSS                        = 132,
                MOUND                       = 133,
                MOUNTAIN                    = 134,
                OAK_TREES                   = 135,
                OUTCROPPING                 = 136,
                PINE_TREES                  = 137,
                PLANT                       = 138,
                BLANK1                      = 139,
                BLANK2                      = 140,
                BLANK3                      = 141,
                BLANK4                      = 142,
                RIVER_DELTA                 = 143,
                BLANK5                      = 144,
                BLANK6                      = 145,
                BLANK7                      = 146,
                ROCK                        = 147,
                SAND_DUNE                   = 148,
                SAND_PIT                    = 149,
                SHRUB                       = 150,
                SKULL                       = 151,
                STALAGMITE                  = 152,
                STUMP                       = 153,
                TAR_PIT                     = 154,
                TREES                       = 155,
                VINE                        = 156,
                VOLCANIC_TENT               = 157,
                VOLCANO                     = 158,
                WILLOW_TREES                = 159,
                YUCCA_TREES                 = 160,
                REEF                        = 161,
                RANDOM_MONSTER_L5           = 162,
                RANDOM_MONSTER_L6           = 163,
                RANDOM_MONSTER_L7           = 164,
                BRUSH2                      = 165,
                BUSH2                       = 166,
                CACTUS2                     = 167,
                CANYON2                     = 168,
                CRATER2                     = 169,
                DEAD_VEGETATION2            = 170,
                FLOWERS2                    = 171,
                FROZEN_LAKE2                = 172,
                HEDGE2                      = 173,
                HILL2                       = 174,
                HOLE2                       = 175,
                KELP2                       = 176,
                LAKE2                       = 177,
                LAVA_FLOW2                  = 178,
                LAVA_LAKE2                  = 179,
                MUSHROOMS2                  = 180,
                LOG2                        = 181,
                MANDRAKE2                   = 182,
                MOSS2                       = 183,
                MOUND2                      = 184,
                MOUNTAIN2                   = 185,
                OAK_TREES2                  = 186,
                OUTCROPPING2                = 187,
                PINE_TREES2                 = 188,
                PLANT2                      = 189,
                RIVER_DELTA2                = 190,
                ROCK2                       = 191,
                SAND_DUNE2                  = 192,
                SAND_PIT2                   = 193,
                SHRUB2                      = 194,
                SKULL2                      = 195,
                STALAGMITE2                 = 196,
                STUMP2                      = 197,
                TAR_PIT2                    = 198,
                TREES2                      = 199,
                VINE2                       = 200,
                VOLCANIC_TENT2              = 201,
                VOLCANO2                    = 202,
                WILLOW_TREES2               = 203,
                YUCCA_TREES2                = 204,
                REEF2                       = 205,
                DESERT_HILLS                = 206,
                DIRT_HILLS                  = 207,
                GRASS_HILLS                 = 208,
                ROUGH_HILLS                 = 209,
                SUBTERRANEAN_ROCKS          = 210,
                SWAMP_FOLIAGE               = 211,
                BORDER_GATE                 = 212,
                FREELANCERS_GUILD           = 213,
                HERO_PLACEHOLDER            = 214,
                QUEST_GUARD                 = 215,
                RANDOM_DWELLING             = 216,
                RANDOM_DWELLING_LVL         = 217,
                RANDOM_DWELLING_FACTION     = 218,
                GARRISON2                   = 219,
                ABANDONED_MINE              = 220,
                TRADING_POST_SNOW           = 221,
                CLOVER_FIELD                = 222,
                CURSED_GROUND2              = 223,
                EVIL_FOG                    = 224,
                FAVORABLE_WINDS             = 225,
                FIERY_FIELDS                = 226,
                HOLY_GROUNDS                = 227,
                LUCID_POOLS                 = 228,
                MAGIC_CLOUDS                = 229,
                MAGIC_PLAINS2               = 230,
                ROCKLANDS                   = 231,
            };
        }
        typedef NObjectTypes::eObjectTypes eObjectTypes;

        namespace NCrBank
        {
            enum eCrBank
            {
                CYCLOPS_STOCPILE     = 0,
                DWARVEN_TREASURY     = 1,
                GRIFFIN_CONSERVATORY = 2,
                IMP_CACHE            = 3,
                MEDUA_STORES         = 4,
                NAGA_BANK            = 5,
                DRAGON_FLY_HIVE      = 6,
                SHIPWRECK            = 7,
                DERELICT_SHIP        = 8,
                CRYPT                = 9,
                DRAGON_UTOPIA        = 10,
            };
        }
        typedef NCrBank::eCrBank eCrBank;
    } /* namespace NH3Objects */
    typedef NH3Objects::eObjectTypes eObject;
    typedef NH3Objects::eCrBank      eCrBank;
} /* namespace h3 */
