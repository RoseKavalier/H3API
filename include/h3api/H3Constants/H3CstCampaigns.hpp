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
    namespace NH3Campaign
    {
        namespace NCampaignId
        {
            enum eCampaignId
            {
                LONG_LIVE_THE_QUEEN     = 0,
                LIBERATION              = 1,
                SPOILS_OF_WAR           = 2,
                SONG_FOR_THE_FATHER     = 3,
                DUNGEONS_AND_DEVILS     = 4,
                LONG_LIVE_THE_KING      = 5,
                SEEDS_OF_DISCONTENT     = 6,
                ARMAGEDDONS_BLADE       = 7,
                DRAGONS_BLOOD           = 8,
                DRAGON_SLAYER           = 9,
                FESTIVAL_OF_LIFE        = 10,
                FOOLHARDY_WAYWARDNESS   = 11,
                PLAYING_WITH_FIRE       = 12,
                HACK_AND_SLASH          = 13,
                BIRTH_OF_A_BARBARIAN    = 14,
                NEW_BEGINNING           = 15,
                ELIXIR_OF_LIFE          = 16,
                RISE_OF_THE_NECROMANCER = 17,
                UNHOLY_ALLIANCE         = 18,
                SPECTER_OF_POWER        = 19,
            };
        }
        typedef NCampaignId::eCampaignId eCampaignId;

        namespace NCampaignType
        {
            enum eCampaignType : INT32
            {
                /* old versions : 3 or less not supported */
                ROE = 5,
                AB  = 5,
                SOD = 6,
            };
        }
        typedef NCampaignType::eCampaignType eCampaignType;

        namespace NCampaignMusic
        {
            enum eCampaignMusic : INT32
            {
                CAMPAINMUSIC01  = 0,
                CAMPAINMUSIC02  = 1,
                CAMPAINMUSIC03  = 2,
                CAMPAINMUSIC04  = 3,
                CAMPAINMUSIC05  = 4,
                CAMPAINMUSIC06  = 5,
                CAMPAINMUSIC07  = 6,
                CAMPAINMUSIC08  = 7,
                CAMPAINMUSIC09  = 8,
                AITHEME0        = 9,
                AITHEME1        = 10,
                AITHEME2        = 11,
                COMBAT01        = 12,
                COMBAT02        = 13,
                COMBAT03        = 14,
                COMBAT04        = 15,
                CSTLETOWN       = 16,
                TOWERTOWN       = 17,
                RAMPART         = 18,
                INFERNOTOWN     = 19,
                NECROTOWN       = 20,
                DUNGEON         = 21,
                STRONGHOLD      = 22,
                FORTRESSTOWN    = 23,
                ELEMTOWN        = 24,
                DIRT            = 25,
                SAND            = 26,
                GRASS           = 27,
                SNOW            = 28,
                SWAMP           = 29,
                ROUGH           = 30,
                UNDERGROUND     = 31,
                LAVA            = 32,
                WATER           = 33,
                GOODTHEME       = 34,
                NEUTRALTHEME    = 35,
                EVILTHEME       = 36,
                SECRETTHEME     = 37,
                LOOPLEPR        = 38,
                MAINMENU        = 39,
                WIN_SCENARIO    = 40,
                CAMPAINMUSIC10  = 41,
                BLADEABCAMPAIGN = 42,
                BLADEDBCAMPAIGN = 43,
                BLADEDSCAMPAIGN = 44,
                BLADEFLCAMPAIGN = 45,
                BLADEFWCAMPAIGN = 46,
                BLADEPFCAMPAIGN = 47,
                CAMPAINMUSIC11  = 48,
            };
        }
        typedef NCampaignMusic::eCampaignMusic eCampaignMusic;

        namespace NCampaignMovie
        {
            enum eCampaignMovie : INT32
            {
                GOOD1_A                  = 0,
                GOOD1_B                  = 1,
                GOOD1_C                  = 2,
                EVIL1_A                  = 3,
                EVIL1_B                  = 4,
                EVIL1_C                  = 5,
                NEUTRAL1_A               = 6,
                NEUTRAL1_B               = 7,
                NEUTRAL1_C               = 8,
                GOOD2_A                  = 9,
                GOOD2_B                  = 10,
                GOOD2_C                  = 11,
                GOOD2_D                  = 12,
                EVIL2_A                  = 13,
                EVIL2AP1                 = 14,
                EVIL2_B                  = 15,
                EVIL2_C                  = 16,
                EVIL2_D                  = 17,
                GOOD3_A                  = 18,
                GOOD3_B                  = 19,
                GOOD3_C                  = 20,
                SECRET_A                 = 21,
                SECRET_B                 = 22,
                SECRET_C                 = 23,
                ARMAGEDDONSBLADE_A       = 24,
                ARMAGEDDONSBLADE_B       = 25,
                ARMAGEDDONSBLADE_C       = 26,
                ARMAGEDDONSBLADE_D       = 27,
                ARMAGEDDONSBLADE_E       = 28,
                ARMAGEDDONSBLADE_F       = 29,
                ARMAGEDDONSBLADE_G       = 30,
                ARMAGEDDONSBLADE_H       = 31,
                ARMAGEDDONSBLADE_END     = 32,
                DRAGONSBLOOD_A           = 33,
                DRAGONSBLOOD_B           = 34,
                DRAGONSBLOOD_C           = 35,
                DRAGONSBLOOD_D           = 36,
                DRAGONSBLOOD_END         = 37,
                DRAGONSLAYER_A           = 38,
                DRAGONSLAYER_B           = 39,
                DRAGONSLAYER_C           = 40,
                DRAGONSLAYER_D           = 41,
                DRAGONSLAYER_END         = 42,
                FESTIVALOFLIFE_A         = 43,
                FESTIVALOFLIFE_B         = 44,
                FESTIVALOFLIFE_C         = 45,
                FESTIVALOFLIFE_D         = 46,
                FESTIVALOFLIFE_END       = 47,
                FOOLHARDYWAYWARDNESS_A   = 48,
                FOOLHARDYWAYWARDNESS_B   = 49,
                FOOLHARDYWAYWARDNESS_C   = 50,
                FOOLHARDYWAYWARDNESS_D   = 51,
                FOOLHARDYWAYWARDNESS_END = 52,
                PLAYINGWITHFIRE_A        = 53,
                PLAYINGWITHFIRE_B        = 54,
                PLAYINGWITHFIRE_C        = 55,
                PLAYINGWITHFIRE_END      = 56,
                BIRTHOFABARBARIAN_A      = 57,
                BIRTHOFABARBARIAN_B      = 58,
                BIRTHOFABARBARIAN_C      = 59,
                BIRTHOFABARBARIAN_D      = 60,
                BIRTHOFABARBARIAN_E      = 61,
                BIRTHOFABARBARIAN_END    = 62,
                ELIXIROFLIFE_A           = 63,
                ELIXIROFLIFE_B           = 64,
                ELIXIROFLIFE_C           = 65,
                ELIXIROFLIFE_D           = 66,
                ELIXIROFLIFE_END         = 67,
                HACKANDSLASH_A           = 68,
                HACKANDSLASH_B           = 69,
                HACKANDSLASH_C           = 70,
                HACKANDSLASH_D           = 71,
                HACKANDSLASH_END         = 72,
                NEWBEGINNING_A           = 73,
                NEWBEGINNING_B           = 74,
                NEWBEGINNING_C           = 75,
                NEWBEGINNING_D           = 76,
                NEWBEGINNING_END         = 77,
                RISEOFTHENECROMANCER_A   = 78,
                RISEOFTHENECROMANCER_B   = 79,
                RISEOFTHENECROMANCER_C   = 70,
                RISEOFTHENECROMANCER_D   = 71,
                RISEOFTHENECROMANCER_END = 72,
                SPECTREOFPOWER_A         = 73,
                SPECTREOFPOWER_B         = 74,
                SPECTREOFPOWER_C         = 75,
                SPECTREOFPOWER_D         = 76,
                SPECTREOFPOWER_END       = 77,
                UNHOLYALLIANCE_A         = 78,
                UNHOLYALLIANCE_B         = 79,
                UNHOLYALLIANCE_C         = 80,
                UNHOLYALLIANCE_D         = 81,
                UNHOLYALLIANCE_E         = 82,
                UNHOLYALLIANCE_F         = 83,
                UNHOLYALLIANCE_G         = 84,
                UNHOLYALLIANCE_H         = 85,
                UNHOLYALLIANCE_I         = 86,
                UNHOLYALLIANCE_J         = 87,
                UNHOLYALLIANCE_K         = 88,
                UNHOLYALLIANCE_L         = 89,
                UNHOLYALLIANCE_END       = 90,
            };
        }
        typedef NCampaignMovie::eCampaignMovie eCampaignMovie;

        namespace NCampaignStartingBonusType
        {
            enum eCampaignStartingBonusType
            {
                SPELL            = 0x0,
                CREATURE         = 0x1,
                BUILDING         = 0x2,
                ARTIFACT         = 0x3,
                SPELL_SCROLL     = 0x4,
                PRIMARY_SKILLS   = 0x5,
                SECONDARY_SKILLS = 0x6,
                RESOURCES        = 0x7,
            };
        }
        typedef NCampaignStartingBonusType::eCampaignStartingBonusType eCampaignStartingBonusType;
    }
    typedef NH3Campaign::eCampaignId                eCampaign;
    typedef NH3Campaign::eCampaignType              eCampaignType;
    typedef NH3Campaign::eCampaignMusic             eCampaignMusic;
    typedef NH3Campaign::eCampaignMovie             eCampaignMovie;
    typedef NH3Campaign::eCampaignStartingBonusType eCampaignStartingBonusType;
} /* namespace h3 */
