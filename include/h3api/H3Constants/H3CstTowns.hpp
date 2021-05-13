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
    namespace NH3Towns
    {
        namespace NTownType
        {
            enum eTownType
            {
                NEUTRAL    = -1,
                CASTLE     = 0,
                RAMPART    = 1,
                TOWER      = 2,
                INFERNO    = 3,
                NECROPOLIS = 4,
                DUNGEON    = 5,
                STRONGHOLD = 6,
                FORTRESS   = 7,
                CONFLUX    = 8,
            };
        }
        typedef NTownType::eTownType eTownType;

        namespace NBuildings
        {
            enum eBuildings // from ERM help
            {
                MAGE_GUILD1              = 0,
                MAGE_GUILD2              = 1,
                MAGE_GUILD3              = 2,
                MAGE_GUILD4              = 3,
                MAGE_GUILD5              = 4,
                TAVERN                   = 5,
                WHARF                    = 6,
                FORT                     = 7,
                CITADEL                  = 8,
                CASTLE                   = 9,
                VILAGE_HALL              = 10,
                TOWN_HALL                = 11,
                CITY_HALL                = 12,
                CAPITOL                  = 13,
                MARKET                   = 14,
                RESOURCE_SILO            = 15,
                BLACKSMITH               = 16,
                SPEC17                   = 17,
                HORDE1                   = 18,
                HORDE1U                  = 19,
                WHARF2                   = 20,
                SPEC21                   = 21,
                SPEC22                   = 22,
                SPEC23                   = 23,
                HORDE2                   = 24,
                HORDE2U                  = 25,
                GRAIL                    = 26,
                DECOR27                  = 27,
                DECOR28                  = 28,
                DECOR29                  = 29,
                DWELL1                   = 30,
                DWELL2                   = 31,
                DWELL3                   = 32,
                DWELL4                   = 33,
                DWELL5                   = 34,
                DWELL6                   = 35,
                DWELL7                   = 36,
                DWELL1U                  = 37,
                DWELL2U                  = 38,
                DWELL3U                  = 39,
                DWELL4U                  = 40,
                DWELL5U                  = 41,
                DWELL6U                  = 42,
                DWELL7U                  = 43,

                /* CASTLE */
                LIGHTHOUSE               = 17,
                STABLES                  = 21,
                BROTHERHOOD_OF_THE_SWORD = 22,

                /* RAMPART */
                MYSTIC_POND              = 17,
                FOUNTAIN_OF_FORTUNE      = 21,
                DWARVEN_TREASURY         = 22,

                /* TOWER */
                ARTIFACT_MERCHANT        = 17, // same for Dungeon and Conflux
                LOOKOUT_TOWER            = 21,
                LIBRARY                  = 22,
                WALL_OF_KNOWLEDGE        = 23,

                /* INFERNO */
                BRIMSTONECLOUDS          = 21,
                CASTLE_GATE              = 22,
                ORDER_OF_FIRE            = 23,

                /* NECROPOLIS */
                VEIL_OF_DARKNESS         = 17,
                NECROMANCY_AMPLIFIER     = 21,
                SKELETON_TRANSFORMER     = 22,

                /*  DUNGEON */
                MANA_VORTEX              = 21,
                PORTAL_OF_SUMMONING      = 22,
                BATTLE_ACADEMY           = 23,

                /* STRONGHOLD */
                ESCAPE_TUNNEL            = 17,
                FREELANCERS_GUILD        = 21,
                BALLISTA_YARD            = 22,
                HALL_OF_VALHALLA         = 23,

                /* FORTRESS */
                CAGE_OF_WARLORDS         = 17,
                GLYPHS_OF_FEAR           = 21,
                BLOOD_OBELISK            = 22,

                /* CONFLUX */
                MAGIC_UNIVERSITY         = 21
            };
        }
        typedef NBuildings::eBuildings eBuildings;

        namespace NNeutralBuildings
        {
            enum eNeutralBuildings
            {
                MAGE_GUILD1      = 0,
                MAGE_GUILD2      = 1,
                MAGE_GUILD3      = 2,
                MAGE_GUILD4      = 3,
                MAGE_GUILD5      = 4,
                TAVERN           = 5,
                DOCK             = 6,
                FORT             = 7,
                CITADEL          = 8,
                CASTLE           = 9,
                VILLAGE          = 10,
                TOWN             = 11,
                CITY             = 12,
                CAPITOL          = 13,
                MARKETPLACE      = 14,
                RESOURCE_SILO    = 15,
                BLACKSMITH       = 16,
            };
        }
        typedef NNeutralBuildings::eNeutralBuildings eNeutralBuildings;

        namespace NBuildingRequirements
        {
            enum eBuildingRequirements
            {
                MAGE_GUILD1   = 0,
                MAGE_GUILD2   = 1,
                MAGE_GUILD3   = 2,
                MAGE_GUILD4   = 3,
                MAGE_GUILD5   = 4,
                TAVERN        = 5,
                WHARF         = 6,
                FORT          = 7,
                CITADEL       = 8,
                CASTLE        = 9,
                VILLAGE       = 10,
                TOWN          = 11,
                CITY          = 12,
                CAPITOL       = 13,
                MARKET        = 14,
                RESOURCE_SILO = 15,
                BLACKSMITH    = 16,
                SPEC17        = 17,
                HORDE1        = 18,
                HORDE1U       = 19,
                WHARF2        = 20,
                SPEC21        = 21,
                SPEC22        = 22,
                SPEC23        = 23,
                HORDE2        = 24,
                HORDE2U       = 25,
                GRAIL         = 26,
                DECOR27       = 27,
                DECOR28       = 28,
                DECOR29       = 29,
                DWELL1        = 30,
                DWELL2        = 31,
                DWELL3        = 32,
                DWELL4        = 33,
                DWELL5        = 34,
                DWELL6        = 35,
                DWELL7        = 36,
                DWELL1U       = 37,
                DWELL2U       = 38,
                DWELL3U       = 39,
                DWELL4U       = 40,
                DWELL5U       = 41,
                DWELL6U       = 42,
                DWELL7U       = 43,
            };
        }
        typedef NBuildingRequirements::eBuildingRequirements eBuildingRequirements;

        namespace NSpecialBuildings
        {
            enum eSpecialBuildings
            {
                /* Castle */
                LIGHTHOUSE = 0,
                GRIFFIN_HORDE,
                ROYAL_GRIFFIN_HORDE,
                UNUSED_CASTLE1,
                STABLES,
                TAVERN_UPGRADE,
                UNUSED_CASTLE2,
                UNUSED_CASTLE3,
                UNUSED_CASTLE4,

                /* Rampart */
                MYSTIC_GARDEN = 0,
                DWARF_HORDE,
                BATTLE_DWARF_HORDE,
                UNUSED_RAMPART1,
                RAINBOW,
                TREASURY,
                UNUSED_RAMPART2,
                TREEFOLK_HORDE,
                BRIAR_TREEFOLK_HORDE,

                /* Tower */
                ARTIFACT_MERCHANTS_TOWER = 0,
                STONE_GARGOYLE_HORDE,
                OBSIDIAN_GARGOYLE_HORDE,
                UNUSED_TOWER1,
                WATCHTOWER,
                LIBRARY,
                WALL_OF_GLYPHIC_KNOWLEDGE,
                UNUSED_TOWER2,
                UNUSED_TOWER3,

                /* Inferno */
                UNUSED_INFERNO1 = 0,
                IMP_HORDE,
                FAMILIAR_HORDE,
                UNUSED_INFERNO2,
                BRIMSTONE_STORMCLOUDS,
                CASTLE_GATE,
                ORDER_OF_FIRE,
                HELL_HOUND_HORDE,
                CERBERUS_HORDE,

                /* Necropolis */
                COVER_OF_DARKNESS = 0,
                SKELETON_HORDE,
                SKELETON_WARRIOR_HORDE,
                UNUSED_NECROPOLIS1,
                NECROMANCY_AMPLIFIER,
                SKELETON_TRANSFORMER,
                UNUSED_NECROPOLIS2,
                UNUSED_NECROPOLIS3,
                UNUSED_NECROPOLIS4,

                /* Dungeon */
                ARTIFACT_MERCHANTS_DUNGEON = 0,
                TROGLODYTE_HORDE,
                INFERNAL_TROGLODYTE_HORDE,
                UNUSED_DUNGEON1,
                MANA_VORTEX,
                PORTAL_OF_SUMMONING,
                ACADEMY_OF_BATTLE_SCHOLARS,
                UNUSED_DUNGEON2,
                UNUSED_DUNGEON3,

                /* Stronghold */
                ESCAPE_TUNNEL = 0,
                GOBLIN_HORDE,
                HOBGOBLIN_HORDE,
                UNUSED_STRONGHOLD1,
                FREELANCERS_GUILD,
                BALLISTA_WORKS,
                HALL_OF_VALHALLA,
                UNUSED_STRONGHOLD2,
                UNUSED_STRONGHOLD3,

                /* Fortress */
                DEFENSE_CAGE = 0,
                GNOLL_HORDE,
                GNOLL_MARAUDER_HORDE,
                UNUSED_FORTRESS1,
                SIEGE_DEFENSE,
                SIEGE_ATTACK,
                UNUSED_FORTRESS2,
                UNUSED_FORTRESS3,
                UNUSED_FORTRESS4,

                /* Conflux */
                ARTIFACT_MERCHANTS = 0,
                PIXIE_HORDE,
                SPRITE_HORDE,
                UNUSED_CONFLUX1,
                MAGIC_UNIVERSITY,
                UNUSED_CONFLUX2,
                UNUSED_CONFLUX3,
                UNUSED_CONFLUX4,
                UNUSED_CONFLUX5,
            };
        }
        typedef NSpecialBuildings::eSpecialBuildings eSpecialBuildings;
    } /* namespace NH3Towns */
    typedef NH3Towns::eTownType             eTown;
    typedef NH3Towns::eBuildings            eBuildings;
    typedef NH3Towns::eNeutralBuildings     eNeutralBuildings;
    typedef NH3Towns::eBuildingRequirements eBuildingRequirements;
    typedef NH3Towns::eSpecialBuildings     eSpecialBuildings;
} /* namespace h3 */
