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
    namespace NH3Heroes
    {
        namespace NHeroClasses
        {
            enum eHeroClasses : INT32
            {
                KNIGHT       = 0,
                CLERIC       = 1,
                RANGER       = 2,
                DRUID        = 3,
                ALCHEMIST    = 4,
                WIZARD       = 5,
                DEMONIAC     = 6,
                HERETIC      = 7,
                DEATH_KNIGHT = 8,
                NECROMANCER  = 9,
                OVERLORD     = 10,
                WARLOCK      = 11,
                BARBARIAN    = 12,
                BATTLE_MAGE  = 13,
                BEASTMASTER  = 14,
                WITCH        = 15,
                PLANESWALKER = 16,
                ELEMENTALIST = 17,
            };
        }
        typedef NHeroClasses::eHeroClasses eHeroClasses;

        namespace NHeroSpecialty
        {
            enum eHeroSpecialty : UINT32
            {
                SKILL           = 0,
                CREATURE_LEVEL  = 1,
                RESOURCE        = 2,
                SPELL           = 3,
                STATIC_CREATURE = 4,
                SPEED           = 5,
                CONVERSION      = 6,
                DRAGON          = 7,
            };
        }
        typedef NHeroSpecialty::eHeroSpecialty eHeroSpecialty;

        namespace NHeroIdentity
        {
            enum eHeroIdentity : INT32
            {
                /* campaign */
                MOST_POWERFUL = -3,
                RANDOM        = -1,

                /* Knight (Castle) */
                ORRIN        = 0,
                VALESKA      = 1,
                EDRIC        = 2,
                SYLVIA       = 3,
                LORD_HAART   = 4,
                SORSHA       = 5,
                CHRISTIAN    = 6,
                TYRIS        = 7,

                /* Cleric (Castle) */
                RION         = 8,
                ADELA        = 9,
                CUTHBERT     = 10,
                ADELAIDE     = 11,
                INGHAM       = 12,
                SANYA        = 13,
                LOYNIS       = 14,
                CAITLIN      = 15,

                /* Ranger (Rampart) */
                MEPHALA      = 16,
                UFRETIN      = 17,
                JENOVA       = 18,
                RYLAND       = 19,
                THORGRIM     = 20,
                IVOR         = 21,
                CLANCY       = 22,
                KYRRE        = 23,

                /* Druid (Rampart) */
                CORONIUS     = 24,
                ULAND        = 25,
                ELLESHAR     = 26,
                GEM          = 27,
                MALCOM       = 28,
                MELODIA      = 29,
                ALAGAR       = 30,
                AERIS        = 31,

                /* Alchemist (Tower) */
                PIQUEDRAM    = 32,
                THANE        = 33,
                JOSEPHINE    = 34,
                NEELA        = 35,
                TOROSAR      = 36,
                FAFNER       = 37,
                RISSA        = 38,
                IONA         = 39,

                /* Wizard (Tower) */
                ASTRAL       = 40,
                HALON        = 41,
                SERENA       = 42,
                DAREMYTH     = 43,
                THEODORUS    = 44,
                SOLMYR       = 45,
                CYRA         = 46,
                AINE         = 47,

                /* Demoniac (Inferno) */
                FIONA        = 48,
                RASHKA       = 49,
                MARIUS       = 50,
                IGNATIUS     = 51,
                OCTAVIA      = 52,
                CALH         = 53,
                PYRE         = 54,
                NYMUS        = 55,

                /* Heretic (Inferno) */
                AYDEN        = 56,
                XYRON        = 57,
                AXSIS        = 58,
                OLEMA        = 59,
                CALID        = 60,
                ASH          = 61,
                ZYDAR        = 62,
                XARFAX       = 63,

                /* Death Knight (Necropolis) */
                STRAKER      = 64,
                VOKIAL       = 65,
                MOANDOR      = 66,
                CHARNA       = 67,
                TAMIKA       = 68,
                ISRA         = 69,
                CLAVIUS      = 70,
                GALTHRAN     = 71,

                /* Necromancer (Necropolis) */
                SEPTIENNA    = 72,
                AISLINN      = 73,
                SANDRO       = 74,
                NIMBUS       = 75,
                THANT        = 76,
                XSI          = 77,
                VIDOMINA     = 78,
                NAGASH       = 79,

                /* Overlord (Dungeon) */
                LORELEI      = 80,
                ARLACH       = 81,
                DACE         = 82,
                AJIT         = 83,
                DAMACON      = 84,
                GUNNAR       = 85,
                SYNCA        = 86,
                SHAKTI       = 87,

                /* Warlock (Dungeon) */
                ALAMAR       = 88,
                JAEGAR       = 89,
                MALEKITH     = 90,
                JEDDITE      = 91,
                GEON         = 92,
                DEEMER       = 93,
                SEPHINROTH   = 94,
                DARKSTORN    = 95,

                /* Barbarian (Stronghold) */
                YOG          = 96,
                GURNISSON    = 97,
                JABARKAS     = 98,
                SHIVA        = 99,
                GRETCHIN     = 100,
                KRELLION     = 101,
                CRAG_HACK    = 102,
                TYRAXOR      = 103,

                /* Battle Mage (Stronghold) */
                GIRD         = 104,
                VEY          = 105,
                DESSA        = 106,
                TEREK        = 107,
                ZUBIN        = 108,
                GUNDULA      = 109,
                ORIS         = 100,
                SAURUG       = 111,

                /* Beastmaster (Fortress) */
                BRON         = 112,
                DRAKON       = 113,
                WYSTAN       = 114,
                TAZAR        = 115,
                ALKIN        = 116,
                KORBAC       = 117,
                GERWULF      = 118,
                BROGHILD     = 119,

                /* Witch (Fortress) */
                MIRLANDA     = 120,
                ROSIC        = 121,
                VOY          = 122,
                VERDISH      = 123,
                MERIST       = 124,
                STYG         = 125,
                ANDRA        = 126,
                TIVA         = 127,

                /* Planeswalker (Conflux) */
                PASIS        = 128,
                THUNAR       = 129,
                IGNISSA      = 130,
                LACUS        = 131,
                MONERE       = 132,
                ERDAMON      = 133,
                FIUR         = 134,
                KALT         = 135,

                /* Elementalist (Conflux) */
                LUNA         = 136,
                BRISSA       = 137,
                CIELE        = 138,
                LABETHA      = 139,
                INTEUS       = 140,
                AENAIN       = 141,
                GELARE       = 142,
                GRINDAN      = 143,

                /* Special */
                SIR_MULLICH  = 144,
                ADRIENNE     = 145,
                CATHERINE    = 146,
                DRACON       = 147,
                GELU         = 148,
                KILGOR       = 149,
                LORD_HAART2  = 150,
                MUTARE       = 151,
                ROLAND       = 152,
                MUTARE_DRAKE = 153,
                BORAGUS      = 154,
                XERON        = 155,

                /* 7 hidden campaign heroes for starting info */
                GENERAL_KENDAL     = 156,
                CAMPAIGN_CHRISTIAN = 157,
                CAMPAIGN_GEM       = 158,
                FINNEAS_VILMAR     = 159,
                ORDWALD            = 160,
                CAMPAIGN_SANDRO    = 161,
                CAMPAIGN_YOG       = 162,
            };
        }
        typedef NHeroIdentity::eHeroIdentity eHeroIdentity;

        namespace NHeroRace
        {
            enum eHeroRace : INT32
            {
                DEMON      = 0,
                DWARF      = 1,
                EFREET     = 2,
                ELF        = 3,
                GENIE      = 4,
                GNOLL      = 5,
                GOBLIN     = 6,
                HUMAN      = 7,
                LICH       = 8,
                LIZARDMAN  = 9,
                MINOTAUR   = 10,
                OGRE       = 11,
                TROGLODYTE = 12,
                VAMPIRE    = 13,
            };
        }
        typedef NHeroRace::eHeroRace eHeroRace;
    } /* namespace NH3Heroes */
    typedef NH3Heroes::eHeroClasses   eHeroClass;
    typedef NH3Heroes::eHeroSpecialty eHeroSpecialty;
    typedef NH3Heroes::eHeroIdentity  eHero;
    typedef NH3Heroes::eHeroRace      eHeroRace;
} /* namespace h3 */
