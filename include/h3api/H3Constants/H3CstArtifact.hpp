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
    namespace NH3Artifacts
    {
        namespace NArtifacts
        {
            enum eArtifacts
            {
                NONE                           = -1,
                SPELLBOOK                      = 0,
                SPELL_SCROLL                   = 1,
                GRAIL                          = 2,
                CATAPULT                       = 3,
                BALLISTA                       = 4,
                AMMO_CART                      = 5,
                FIRST_AID_TENT                 = 6,
                CENTAUR_AXE                    = 7,
                BLACKSHARD_OF_THE_DEAD_KNIGHT  = 8,
                GREATER_GNOLLS_FLAIL           = 9,
                OGRES_CLUB_OF_HAVOC            = 10,
                SWORD_OF_HELLFIRE              = 11,
                TITANS_GLADIUS                 = 12,
                SHIELD_OF_THE_DWARVEN_LORDS    = 13,
                SHIELD_OF_THE_YAWNING_DEAD     = 14,
                BUCKLER_OF_THE_GNOLL_KING      = 15,
                TARG_OF_THE_RAMPAGING_OGRE     = 16,
                SHIELD_OF_THE_DAMNED           = 17,
                SENTINELS_SHIELD               = 18,
                HELM_OF_THE_ALABASTER_UNICORN  = 19,
                SKULL_HELMET                   = 20,
                HELM_OF_CHAOS                  = 21,
                CROWN_OF_THE_SUPREME_MAGI      = 22,
                HELLSTORM_HELMET               = 23,
                THUNDER_HELMET                 = 24,
                BREASTPLATE_OF_PETRIFIED_WOOD  = 25,
                RIB_CAGE                       = 26,
                SCALES_OF_THE_GREATER_BASILISK = 27,
                TUNIC_OF_THE_CYCLOPS_KING      = 28,
                BREASTPLATE_OF_BRIMSTONE       = 29,
                TITANS_CUIRASS                 = 30,
                ARMOR_OF_WONDER                = 31,
                SANDALS_OF_THE_SAINT           = 32,
                CELESTIAL_NECKLACE_OF_BLISS    = 33,
                LIONS_SHIELD_OF_COURAGE        = 34,
                SWORD_OF_JUDGEMENT             = 35,
                HELM_OF_HEAVENLY_ENLIGHTENMENT = 36,
                QUIET_EYE_OF_THE_DRAGON        = 37,
                RED_DRAGON_FLAME_TONGUE        = 38,
                DRAGON_SCALE_SHIELD            = 39,
                DRAGON_SCALE_ARMOR             = 40,
                DRAGONBONE_GREAVES             = 41,
                DRAGON_WING_TABARD             = 42,
                NECKLACE_OF_DRAGONTEETH        = 43,
                CROWN_OF_DRAGONTOOTH           = 44,
                STILL_EYE_OF_THE_DRAGON        = 45,
                CLOVER_OF_FORTUNE              = 46,
                CARDS_OF_PROPHECY              = 47,
                LADYBIRD_OF_LUCK               = 48,
                BADGE_OF_COURAGE               = 49,
                CREST_OF_VALOR                 = 50,
                GLYPH_OF_GALLANTRY             = 51,
                SPECULUM                       = 52,
                SPYGLASS                       = 53,
                AMULET_OF_THE_UNDERTAKER       = 54,
                VAMPIRES_COWL                  = 55,
                DEAD_MANS_BOOTS                = 56,
                GARNITURE_OF_INTERFERENCE      = 57,
                SURCOAT_OF_COUNTERPOISE        = 58,
                BOOTS_OF_POLARITY              = 59,
                BOW_OF_ELVEN_CHERRYWOOD        = 60,
                BOWSTRING_OF_THE_UNICORNS_MANE = 61,
                ANGEL_FEATHER_ARROWS           = 62,
                BIRD_OF_PERCEPTION             = 63,
                STOIC_WATCHMAN                 = 64,
                EMBLEM_OF_COGNIZANCE           = 65,
                STATESMANS_MEDAL               = 66,
                DIPLOMATS_RING                 = 67,
                AMBASSADORS_SASH               = 68,
                RING_OF_THE_WAYFARER           = 69,
                EQUESTRIANS_GLOVES             = 70,
                NECKLACE_OF_OCEAN_GUIDANCE     = 71,
                ANGEL_WINGS                    = 72,
                CHARM_OF_MANA                  = 73,
                TALISMAN_OF_MANA               = 74,
                MYSTIC_ORB_OF_MANA             = 75,
                COLLAR_OF_CONJURING            = 76,
                RING_OF_CONJURING              = 77,
                CAPE_OF_CONJURING              = 78,
                ORB_OF_THE_FIRMAMENT           = 79,
                ORB_OF_SILT                    = 80,
                ORB_OF_TEMPESTUOUS_FIRE        = 81,
                ORB_OF_DRIVING_RAIN            = 82,
                RECANTERS_CLOAK                = 83,
                SPIRIT_OF_OPPRESSION           = 84,
                HOURGLASS_OF_THE_EVIL_HOUR     = 85,
                TOME_OF_FIRE_MAGIC             = 86,
                TOME_OF_AIR_MAGIC              = 87,
                TOME_OF_WATER_MAGIC            = 88,
                TOME_OF_EARTH_MAGIC            = 89,
                BOOTS_OF_LEVITATION            = 90,
                GOLDEN_BOW                     = 91,
                SPHERE_OF_PERMANENCE           = 92,
                ORB_OF_VULNERABILITY           = 93,
                RING_OF_VITALITY               = 94,
                RING_OF_LIFE                   = 95,
                VIAL_OF_LIFEBLOOD              = 96,
                NECKLACE_OF_SWIFTNESS          = 97,
                BOOTS_OF_SPEED                 = 98,
                CAPE_OF_VELOCITY               = 99,
                PENDANT_OF_DISPASSION          = 100,
                PENDANT_OF_SECOND_SIGHT        = 101,
                PENDANT_OF_HOLINESS            = 102,
                PENDANT_OF_LIFE                = 103,
                PENDANT_OF_DEATH               = 104,
                PENDANT_OF_FREE_WILL           = 105,
                PENDANT_OF_NEGATIVITY          = 106,
                PENDANT_OF_TOTAL_RECALL        = 107,
                PENDANT_OF_COURAGE             = 108,
                EVERFLOWING_CRYSTAL_CLOAK      = 109,
                RING_OF_INFINITE_GEMS          = 110,
                EVERPOURING_VIAL_OF_MERCURY    = 111,
                INEXHAUSTIBLE_CART_OF_ORE      = 112,
                EVERSMOKING_RING_OF_SULFUR     = 113,
                INEXHAUSTIBLE_CART_OF_LUMBER   = 114,
                ENDLESS_SACK_OF_GOLD           = 115,
                ENDLESS_BAG_OF_GOLD            = 116,
                ENDLESS_PURSE_OF_GOLD          = 117,
                LEGS_OF_LEGION                 = 118,
                LOINS_OF_LEGION                = 119,
                TORSO_OF_LEGION                = 120,
                ARMS_OF_LEGION                 = 121,
                HEAD_OF_LEGION                 = 122,
                SEA_CAPTAINS_HAT               = 123,
                SPELLBINDERS_HAT               = 124,
                SHACKLES_OF_WAR                = 125,
                ORB_OF_INHIBITION              = 126,
                VIAL_OF_DRAGON_BLOOD           = 127,
                ARMAGEDDONS_BLADE              = 128,
                ANGELIC_ALLIANCE               = 129,
                CLOAK_OF_THE_UNDEAD_KING       = 130,
                ELIXIR_OF_LIFE                 = 131,
                ARMOR_OF_THE_DAMNED            = 132,
                STATUE_OF_LEGION               = 133,
                POWER_OF_THE_DRAGON_FATHER     = 134,
                TITANS_THUNDER                 = 135,
                ADMIRALS_HAT                   = 136,
                BOW_OF_THE_SHARPSHOOTER        = 137,
                WIZARDS_WELL                   = 138,
                RING_OF_THE_MAGI               = 139,
                CORNUCOPIA                     = 140,
            };
        }
        typedef NArtifacts::eArtifacts eArtifacts;

        namespace NSlots
        {
            enum eArtifactSlots
            {
                NONE           = -1,
                HEAD           = 0,
                SHOULDERS      = 1,
                NECK           = 2,
                RIGHT_HAND     = 3,
                LEFT_HAND      = 4,
                TORSO          = 5,
                RIGHT_RING     = 6,
                LEFT_RING      = 7,
                FEET           = 8,
                MISC1          = 9,
                MISC2          = 10,
                MISC3          = 11,
                MISC4          = 12,
                BALLISTA       = 13,
                AMMO_CART      = 14,
                FIRST_AID_TENT = 15,
                CATAPULT       = 16,
                SPELLBOOK      = 17,
                MISC5          = 18,
            };
        }
        typedef NSlots::eArtifactSlots eArtifactSlots;

        namespace NType
        {
            enum eArtifactType
            {
                SPECIAL  = 1,
                TREASURE = 2,
                MINOR    = 4,
                MAJOR    = 8,
                RELIC    = 16,
                ALL      = 30, // never special!
            };
        }
        typedef NType::eArtifactType eArtifactType;

        namespace NCombination
        {
            enum eCombinationArtifacts
            {
                NONE                       = -1,
                ANGELIC_ALLIANCE           = 0,
                CLOAK_OF_THE_UNDEAD_KING   = 1,
                ELIXIR_OF_LIFE             = 2,
                ARMOR_OF_THE_DAMNED        = 3,
                STATUE_OF_LEGION           = 4,
                POWER_OF_THE_DRAGON_FATHER = 5,
                TITANS_THUNDER             = 6,
                ADMIRALS_HAT               = 7,
                BOW_OF_THE_SHARPSHOOTER    = 8,
                WIZARDS_WELL               = 9,
                RING_OF_THE_MAGI           = 10,
                CORNUCOPIA                 = 11,
            };
        }
        typedef NCombination::eCombinationArtifacts eCombinationArtifacts;
    }

    typedef NH3Artifacts::eArtifacts            eArtifact;
    typedef NH3Artifacts::eArtifactSlots        eArtifactSlots;
    typedef NH3Artifacts::eArtifactType         eArtifactType;
    typedef NH3Artifacts::eCombinationArtifacts eCombinationArtifacts;

} /* namespace h3 */
