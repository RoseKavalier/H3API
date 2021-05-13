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
    namespace NH3Dlg
    {
        namespace Text
        {
            LPCSTR const TINY    = (LPCSTR(0x660CB4)); // "tiny.fnt"
            LPCSTR const SMALL   = (LPCSTR(0x65F2F8)); // "smalfont.fnt"
            LPCSTR const MEDIUM  = (LPCSTR(0x65F2EC)); // "MedFont.fnt"
            LPCSTR const BIG     = (LPCSTR(0x660B24)); // "bigfont.fnt"
            LPCSTR const VERDANA = (LPCSTR(0x6700B4)); // "Verd10B.fnt"
        } // namespace Text

        namespace NTextAlignment
        {
            enum eTextAlignment : INT32
            {
                HLEFT         = 0,
                HCENTER       = 1,
                HRIGHT        = 2,
                VTOP          = 0,
                VCENTER       = 4,
                VBOTTOM       = 8,
                BOTTOM_LEFT   = HLEFT   | VBOTTOM,
                BOTTOM_CENTER = HCENTER | VBOTTOM,
                BOTTOM_RIGHT  = HRIGHT  | VBOTTOM,
                MIDDLE_LEFT   = HLEFT   | VCENTER,
                MIDDLE_CENTER = HCENTER | VCENTER,
                MIDDLE_RIGHT  = HRIGHT  | VCENTER,
                TOP_LEFT      = HLEFT   | VTOP,
                TOP_MIDDLE    = HCENTER | VTOP,
                TOP_RIGHT     = HRIGHT  | VTOP,
            };
        } // namespace TextAlignment
        typedef NTextAlignment::eTextAlignment eTextAlignment;

        namespace NTextColor
        {
            enum eTextColor : INT32
            {
                SILVER      = 0x00,
                REGULAR     = 0x01,
                HIGHLIGHT   = 0x02,
                GOLD        = 0x03,
                WHITE       = 0x04,
                GREEN       = 0x0D,
                LIGHT_GREEN = 0x0E,
                DARK_GREEN  = 0x0F,
                BLACK       = 0x17,
                BLUE        = 0x18,
                CYAN        = 0x1A,
                RED         = 0x1B,
                PURPLE      = 0x1C,
                YELLOW      = 0x1D,
                GRAY        = 0x36,
                RED2        = 0x37,
                BLUE2       = 0x38,
                TAN         = 0x39,
                DARK_GREEN2 = 0x3A,
                ORANGE      = 0x3B,
                PURPLE2     = 0x3C,
                DARK_CYAN   = 0x3D,
                PINK        = 0x3E,
                GRAY2       = 0x3F,
                YELLOW2     = 0x57,
                DARK_YELLOW = 0x58,
                TAN2        = 0x59,
                TAN3        = 0x5A,
                TAN4        = 0x5B,
                TAN5        = 0x5C,
                CYAN2       = 0x67,
                CYAN3       = 0x68,
                CYAN4       = 0x69,
                CYAN5       = 0x6A,
            };
        } // namespace TextColor
        typedef NTextColor::eTextColor eTextColor;

        namespace Assets
        {
            LPCSTR const ARTIFACT_DEF     = (LPCSTR(0x660214));  // "artifact.def" 44x44
            LPCSTR const ARTS_ICON        = (LPCSTR(0x683178));  // AltArt.def 64x32
            LPCSTR const CREATURE_SMALL   = (LPCSTR(0x660180));  // "CPRSMALL.def" 32x32
            LPCSTR const DIBOXBACK        = (LPCSTR(0x66025C));  // "diboxback.pcx" 256x256
            LPCSTR const DLGBOX           = (LPCSTR(0x66024C));  // "dialogbox.def" 64x64
            LPCSTR const HERO_CADRE       = (LPCSTR(0x65F3DC));  // hpsyyy.pcx 48x32
            LPCSTR const PSKILL_42        = (LPCSTR(0x679D9C));  // "PSKIL42.def" 42x42
            LPCSTR const RESOURCE_DEF     = (LPCSTR(0x660224));  // "resource.def" 32x32
            LPCSTR const RESOURCE_82      = (LPCSTR(0x660114));  // "resour82.def" 82x93
            LPCSTR const SPELLS_DEF       = (LPCSTR(0x660208));  // "spells.def"78x65
            LPCSTR const SPELL_SMALL      = (LPCSTR(0x6700A4));  // "spellint.def" 48x36
            LPCSTR const SSKILL_44        = (LPCSTR(0x6601D0));  // "Secskill.def" 44x44
            LPCSTR const UN44_DEF         = (LPCSTR(0x679D90));  // "un44.def"44x44
            LPCSTR const OVBUTN3          = (LPCSTR(0x6817C4));  // "OvButn3.def" 108x16
            LPCSTR const LARGE_HERO_CADRE = (LPCSTR(0x68C45C));  // TPTavSel.pcx 62x68 ~decal by -2
            LPCSTR const CREATURE_LARGE   = (LPCSTR(0x6700C0));  // TwCrPort.def 58x64
            LPCSTR const CANCEL_BUTTON    = (LPCSTR(0x660B04));  // iCancel.def 64x30
            LPCSTR const CAST_SPELL       = (LPCSTR(0x66FFD4));  // icm005.def 48x36
            LPCSTR const MORALE_42        = (LPCSTR(0x68C6DC));  // IMRL42.def 42x38
            LPCSTR const LUCK_42          = (LPCSTR(0x68C6D0));  // ILCK42.def 42x38
            LPCSTR const CREST58          = (LPCSTR(0x6601FC));  // CREST58.def 58x64
            LPCSTR const TOWN_SMALL       = (LPCSTR(0x65F318));  // itpa.def 48x32
            LPCSTR const NO_VISION        = (LPCSTR(0x6885A0));  // SYSOPB8.def 46x32
            LPCSTR const ADVENTURE_CURSOR = (LPCSTR(0x68164C));  // cradvntr.def 40x40
            LPCSTR const ON_OFF_CHECKBOX  = (LPCSTR(0x6700F0));  // sysopchk.def 32x24
            LPCSTR const OKAY_DEF         = (LPCSTR(0x670160));  // iOkay.def 64x30
            LPCSTR const OKAY32_DEF       = (LPCSTR(0x682374));  // iOkay32.def 66x32
            LPCSTR const OKAY6432_DEF     = (LPCSTR(0x65F470));  // iOk6432.def 64x32
            LPCSTR const BOX_64_30_PCX    = (LPCSTR(0x67016C));  // Box64x30.pcx
            LPCSTR const BOX_66_32_PCX    = (LPCSTR(0x682380));  // Box66x32.pcx
            LPCSTR const CANCEL_DEF       = (LPCSTR(0x660B04));  // "iCancel.def" 64x30
            LPCSTR const VIEW_CREATURE    = (LPCSTR(0x660134));  // iViewCr.def
            LPCSTR const VIEW_MAGNIFIER   = (LPCSTR(0x68C734));  // VWMag1.def 60x32
            LPCSTR const iSAVE_DEF        = "ISAVE.DEF";         // iSave.def 64x32
            LPCSTR const BOX_64_32_PCX    = (LPCSTR(0x68C640));  // Box64x32.pcx
            LPCSTR const GAME_TYPE_DEF    = (LPCSTR(0x683568));  // 32x24
            LPCSTR const ICM005_DEF       = (LPCSTR(0x66FFD4));  // 48x36
            LPCSTR const ALTART_DEF       = (LPCSTR(0x683178));  // 64x32
            LPCSTR const VWSYMBOL_DEF     = (LPCSTR(0x68C740));  // 32x32
            LPCSTR const SYSLB_DEF        = (LPCSTR(0x670124));  // 18x36
        } // namespace Assets

        namespace HDassets
        {
            LPCSTR const DLGBLUEBOX       = "DlgBluBo.def";  // 64x64
            LPCSTR const DLGBLUEBACK      = "DlgBluBk.PCX";  // 256x256
            LPCSTR const LINE_SEPARATOR   = "stripe3d.bmp";  // 800x2
            LPCSTR const HD_STATUSBAR_PCX = "HD_TStat.pcx";  // 800x19
            LPCSTR const HERO_FRAME       = "48x32bFr.bmp";  // darken an area for 48x32 def
            LPCSTR const BACKPACK_DEF     = "bckpck.def";    // 52x36
            LPCSTR const BIG_BACKPACK     = "BkPack.bmp";    // 369x369
            LPCSTR const SCROLL_SMALL     = "def.SpScrArt";  // 44x44
            LPCSTR const FRAME_LU         = "hd_fr_lu.bmp";  // 4x4
            LPCSTR const FRAME_LD         = "hd_fr_ld.bmp";  // 4x4
            LPCSTR const FRAME_RU         = "hd_fr_ru.bmp";  // 4x4
            LPCSTR const FRAME_RD         = "hd_fr_rd.bmp";  // 4x4
            LPCSTR const FRAME_U          = "hd_fr_u.bmp";   // 4x4
            LPCSTR const FRAME_D          = "hd_fr_d.bmp";   // 4x4
            LPCSTR const FRAME_L          = "hd_fr_l.bmp";   // 4x4
            LPCSTR const FRAME_R          = "hd_fr_r.bmp";   // 4x4
        } // namespace HDassets

        namespace NPictureCategories
        {
            enum ePictureCategories
            {
                NONE                 = -1,
                WOOD                 = 0,    /**< @brief amount (int)*/
                MERCURY              = 1,    /**< @brief amount (int)*/
                ORE                  = 2,    /**< @brief amount (int)*/
                SULFUR               = 3,    /**< @brief amount (int)*/
                CRYSTAL              = 4,    /**< @brief amount (int)*/
                GEMS                 = 5,    /**< @brief amount (int)*/
                GOLD                 = 6,    /**< @brief amount (int)*/
                ARTIFACT             = 8,    /**< @brief artifact id 0..140*/
                SPELL                = 9,    /**< @brief spell id 0..69*/
                CREST                = 10,   /**< @brief player color 0..7 */
                POSITIVE_LUCK        = 11,   /**< @brief 1..3*/
                NEUTRAL_LUCK         = 12,   /**< @brief unused*/
                NEGATIVE_LUCK        = 13,   /**< @brief 1..3*/
                POSITIVE_MORALE      = 14,   /**< @brief 1..3*/
                NEUTRAL_MORALE       = 15,   /**< @brief unused*/
                NEGATIVE_MORALE      = 16,   /**< @brief 1..3*/
                EXPERIENCE           = 17,   /**< @brief amount (int)*/
                SECONDARY_SKILL      = 20,   /**< @brief skill_id * 3 + level + 2*/
                CREATURE             = 21,   /**< @brief id 0..148 (?)*/
                CASTLE_BUILDINGS     = 22,   /**< @brief 0..43*/
                RAMPART_BUILDINGS    = 23,   /**< @brief 0..43*/
                TOWER_BUILDINGS      = 24,   /**< @brief 0..43*/
                INFERNO_BUILDINGS    = 25,   /**< @brief 0..43*/
                NECROPOLIS_BUILDINGS = 26,   /**< @brief 0..43*/
                DUNGEON_BUILDINGS    = 27,   /**< @brief 0..43*/
                STRONGHOLD_BUILDINGS = 28,   /**< @brief 0..43*/
                FORTRESS_BUILDINGS   = 29,   /**< @brief 0..43*/
                CONFLUX_BUILDINGS    = 30,   /**< @brief 0..43*/
                ATTACK               = 31,   /**< @brief 0..255*/
                DEFENSE              = 32,   /**< @brief 0..255*/
                SPELL_POWER          = 33,   /**< @brief 0..255*/
                KNOWLEDGE            = 34,   /**< @brief 0..255*/
                SPELL_POINTS         = 35,   /**< @brief amount (int)*/
                MONEY                = 36,   /**< @brief amount (int)*/
            };
        }
        typedef NPictureCategories::ePictureCategories ePictureCategories;

        //? these might be better suited in H3Dialogs/MatchingDlg.hpp or similar, as the list may grow significantly
        namespace ID
        {
            namespace MainMenu
            {
                constexpr INT32 VTABLE     = 0x63FF60;
                constexpr INT32 NEW_GAME   = 101;
                constexpr INT32 LOAD_GAME  = 102;
                constexpr INT32 HIGH_SCORE = 103;
                constexpr INT32 CREDITS    = 104;
                constexpr INT32 QUIT       = 105;
            } // namespace MainMenu

            namespace HighScore
            {
                constexpr INT32 VTABLE   = 0x63EB98;
                constexpr INT32 EXIT     = 30722;
                constexpr INT32 CAMPAIGN = 1001;
                constexpr INT32 STANDARD = 1002;
                constexpr INT32 RESET    = 1003;
                /* others range from 1004 to 1025 */
            } // namespace HighScore

            namespace LoadGame
            {
                constexpr INT32 VTABLE      = 0x63E6D8;
                constexpr INT32 SINGLE      = 100;
                constexpr INT32 MULTIPLAYER = 102;
                constexpr INT32 CAMPAIGN    = 101;
                constexpr INT32 TUTORIAL    = 103;
                constexpr INT32 QUIT        = 104;
            } // namespace LoadGame

            namespace NewGame
            {
                constexpr INT32 VTABLE      = 0x63E6D8;
                constexpr INT32 SINGLE      = 100;
                constexpr INT32 MULTIPLAYER = 102;
                constexpr INT32 CAMPAIGN    = 101;
                constexpr INT32 TUTORIAL    = 103;
                constexpr INT32 QUIT        = 104;
            } // namespace NewGame

            namespace SelectScenario
            {
                constexpr INT32 SCENARIO_NAME          = 101;
                constexpr INT32 EASY_DIFFICULTY        = 107;
                constexpr INT32 NORMAL_DIFFICULTY      = 108;
                constexpr INT32 HARD_DIFFICULTY        = 109;
                constexpr INT32 EXPERT_DIFFICULTY      = 110;
                constexpr INT32 IMPOSSIBLE_DIFFICULTY  = 111;
                constexpr INT32 RED_ALLY_FLAG          = 112;
                constexpr INT32 BLUE_ALLY_FLAG         = 113;
                constexpr INT32 TAN_ALLY_FLAG          = 114;
                constexpr INT32 GREEN_ALLY_FLAG        = 115;
                constexpr INT32 ORANGE_ALLY_FLAG       = 116;
                constexpr INT32 PURPLE_ALLY_FLAG       = 117;
                constexpr INT32 TEAL_ALLY_FLAG         = 118;
                constexpr INT32 PINK_ALLY_FLAG         = 119;
                constexpr INT32 RED_ENEMY_FLAG         = 120;
                constexpr INT32 BLUE_ENEMY_FLAG        = 121;
                constexpr INT32 TAN_ENEMY_FLAG         = 122;
                constexpr INT32 GREEN_ENEMY_FLAG       = 123;
                constexpr INT32 ORANGE_ENEMY_FLAG      = 124;
                constexpr INT32 PURPLE_ENEMY_FLAG      = 125;
                constexpr INT32 TEAL_ENEMY_FLAG        = 126;
                constexpr INT32 PINK_ENEMY_FLAG        = 127;
                constexpr INT32 SHOW_SCENARIOS         = 128;
                constexpr INT32 ADVANCED_OPTIONS       = 129;
                constexpr INT32 RANDOM_MAP             = 130;
                constexpr INT32 SMALL_SIZE             = 137;
                constexpr INT32 MEDIUM_SIZE            = 138;
                constexpr INT32 LARGE_SIZE             = 139;
                constexpr INT32 XLARGE_SIZE            = 140;
                constexpr INT32 ALL_SIZE               = 141;

                constexpr INT32 MAP_INDEX_0            = 142;
                constexpr INT32 MAP_INDEX_1            = 143;
                constexpr INT32 MAP_INDEX_2            = 144;
                constexpr INT32 MAP_INDEX_3            = 145;
                constexpr INT32 MAP_INDEX_4            = 146;
                constexpr INT32 MAP_INDEX_5            = 147;
                constexpr INT32 MAP_INDEX_6            = 148;
                constexpr INT32 MAP_INDEX_7            = 149;
                constexpr INT32 MAP_INDEX_8            = 150;
                constexpr INT32 MAP_INDEX_9            = 151;
                constexpr INT32 MAP_INDEX_10           = 152;
                constexpr INT32 MAP_INDEX_11           = 153;
                constexpr INT32 MAP_INDEX_12           = 154;
                constexpr INT32 MAP_INDEX_13           = 155;
                constexpr INT32 MAP_INDEX_14           = 156;
                constexpr INT32 MAP_INDEX_15           = 157;
                constexpr INT32 MAP_INDEX_16           = 158;
                constexpr INT32 MAP_INDEX_17           = 159;
                constexpr INT32 BEGIN                  = 186;
                constexpr INT32 BACK                   = 188;
                constexpr INT32 SELECTED_SIZE          = 189;
                constexpr INT32 SORT_PLAYER            = 190;
                constexpr INT32 SORT_SIZE              = 191;
                constexpr INT32 SORT_VERSION           = 192;
                constexpr INT32 SORT_NAME              = 193;
                constexpr INT32 SORT_VICTORY           = 194;
                constexpr INT32 SORT_LOSS              = 195;
                constexpr INT32 RED_TOWN_LEFT          = 215;
                constexpr INT32 BLUE_TOWN_LEFT         = 216;
                constexpr INT32 TAN_TOWN_LEFT          = 217;
                constexpr INT32 GREEN_TOWN_LEFT        = 218;
                constexpr INT32 ORANGE_TOWN_LEFT       = 219;
                constexpr INT32 PURPLE_TOWN_LEFT       = 220;
                constexpr INT32 TEAL_TOWN_LEFT         = 221;
                constexpr INT32 PINK_TOWN_LEFT         = 222;
                constexpr INT32 RED_TOWN_RIGHT         = 223;
                constexpr INT32 BLUE_TOWN_RIGHT        = 224;
                constexpr INT32 TAN_TOWN_RIGHT         = 225;
                constexpr INT32 GREEN_TOWN_RIGHT       = 226;
                constexpr INT32 ORANGE_TOWN_RIGHT      = 227;
                constexpr INT32 PURPLE_TOWN_RIGHT      = 228;
                constexpr INT32 TEAL_TOWN_RIGHT        = 229;
                constexpr INT32 PINK_TOWN_RIGHT        = 230;
                constexpr INT32 RED_HERO_LEFT          = 231;
                constexpr INT32 BLUE_HERO_LEFT         = 232;
                constexpr INT32 TAN_HERO_LEFT          = 233;
                constexpr INT32 GREEN_HERO_LEFT        = 234;
                constexpr INT32 ORANGE_HERO_LEFT       = 235;
                constexpr INT32 PURPLE_HERO_LEFT       = 236;
                constexpr INT32 TEAL_HERO_LEFT         = 237;
                constexpr INT32 PINK_HERO_LEFT         = 238;
                constexpr INT32 RED_HERO_RIGHT         = 239;
                constexpr INT32 BLUE_HERO_RIGHT        = 240;
                constexpr INT32 TAN_HERO_RIGHT         = 241;
                constexpr INT32 GREEN_HERO_RIGHT       = 242;
                constexpr INT32 ORANGE_HERO_RIGHT      = 243;
                constexpr INT32 PURPLE_HERO_RIGHT      = 244;
                constexpr INT32 TEAL_HERO_RIGHT        = 245;
                constexpr INT32 PINK_HERO_RIGHT        = 246;
                constexpr INT32 RED_BONUS_LEFT         = 247;
                constexpr INT32 BLUE_BONUS_LEFT        = 248;
                constexpr INT32 TAN_BONUS_LEFT         = 249;
                constexpr INT32 GREEN_BONUS_LEFT       = 250;
                constexpr INT32 ORANGE_BONUS_LEFT      = 251;
                constexpr INT32 PURPLE_BONUS_LEFT      = 252;
                constexpr INT32 TEAL_BONUS_LEFT        = 253;
                constexpr INT32 PINK_BONUS_LEFT        = 254;
                constexpr INT32 RED_BONUS_RIGHT        = 255;
                constexpr INT32 BLUE_BONUS_RIGHT       = 256;
                constexpr INT32 TAN_BONUS_RIGHT        = 257;
                constexpr INT32 GREEN_BONUS_RIGHT      = 258;
                constexpr INT32 ORANGE_BONUS_RIGHT     = 259;
                constexpr INT32 PURPLE_BONUS_RIGHT     = 260;
                constexpr INT32 TEAL_BONUS_RIGHT       = 261;
                constexpr INT32 PINK_BONUS_RIGHT       = 262;
                constexpr INT32 RED_BANNER             = 263;
                constexpr INT32 BLUE_BANNER            = 264;
                constexpr INT32 TAN_BANNER             = 265;
                constexpr INT32 GREEN_BANNER           = 266;
                constexpr INT32 ORANGE_BANNER          = 267;
                constexpr INT32 PURPLE_BANNER          = 268;
                constexpr INT32 TEAL_BANNER            = 269;
                constexpr INT32 PINK_BANNER            = 270;
                constexpr INT32 RANDOM_SMALL           = 281;
                constexpr INT32 RANDOM_MEDIUM          = 282;
                constexpr INT32 RANDOM_LARGE           = 283;
                constexpr INT32 RANDOM_XLARGE          = 284;
                constexpr INT32 RANDOM_UNDERGROUND     = 285;
                constexpr INT32 RANDOM_HUMAN1          = 287;
                constexpr INT32 RANDOM_HUMAN2          = 288;
                constexpr INT32 RANDOM_HUMAN3          = 289;
                constexpr INT32 RANDOM_HUMAN4          = 290;
                constexpr INT32 RANDOM_HUMAN5          = 291;
                constexpr INT32 RANDOM_HUMAN6          = 292;
                constexpr INT32 RANDOM_HUMAN7          = 293;
                constexpr INT32 RANDOM_HUMAN8          = 294;
                constexpr INT32 RANDOM_HUMAN_RANDOM    = 295;
                constexpr INT32 RANDOM_COMPUTER0       = 307;
                constexpr INT32 RANDOM_COMPUTER1       = 308;
                constexpr INT32 RANDOM_COMPUTER2       = 309;
                constexpr INT32 RANDOM_COMPUTER3       = 310;
                constexpr INT32 RANDOM_COMPUTER4       = 311;
                constexpr INT32 RANDOM_COMPUTER5       = 312;
                constexpr INT32 RANDOM_COMPUTER6       = 313;
                constexpr INT32 RANDOM_COMPUTER7       = 314;
                constexpr INT32 RANDOM_COMPUTER_RANDOM = 315;
                constexpr INT32 RANDOM_WATER_NONE      = 326;
                constexpr INT32 RANDOM_WATER_NORMAL    = 327;
                constexpr INT32 RANDOM_WATER_ISLANDS   = 328;
                constexpr INT32 RANDOM_WATER_RANDOM    = 329;
                constexpr INT32 RANDOM_MONSTER_WEAK    = 331;
                constexpr INT32 RANDOM_MONSTER_NORMAL  = 332;
                constexpr INT32 RANDOM_MONSTER_STRONG  = 333;
                constexpr INT32 RANDOM_MONSTER_RANDOM  = 334;
                constexpr INT32 MAPS_SCROLLBAR         = 337;
                constexpr INT32 TIMER_SCROLLBAR        = 338;
                constexpr INT32 RED_NAME               = 345;
                constexpr INT32 BLUE_NAME              = 346;
                constexpr INT32 TAN_NAME               = 347;
                constexpr INT32 GREEN_NAME             = 348;
                constexpr INT32 ORANGE_NAME            = 349;
                constexpr INT32 PURPLE_NAME            = 350;
                constexpr INT32 TEAL_NAME              = 351;
                constexpr INT32 PINK_NAME              = 352;
                constexpr INT32 RED_HERO               = 362;
                constexpr INT32 BLUE_HERO              = 363;
                constexpr INT32 TAN_HERO               = 364;
                constexpr INT32 GREEN_HERO             = 365;
                constexpr INT32 ORANGE_HERO            = 366;
                constexpr INT32 PURPLE_HERO            = 367;
                constexpr INT32 TEAL_HERO              = 368;
                constexpr INT32 PINK_HERO              = 369;
                constexpr INT32 RED_TOWN               = 370;
                constexpr INT32 BLUE_TOWN              = 371;
                constexpr INT32 TAN_TOWN               = 372;
                constexpr INT32 GREEN_TOWN             = 373;
                constexpr INT32 ORANGE_TOWN            = 374;
                constexpr INT32 PURPLE_TOWN            = 375;
                constexpr INT32 TEAL_TOWN              = 376;
                constexpr INT32 PINK_TOWN              = 377;
                constexpr INT32 RED_BONUS              = 378;
                constexpr INT32 BLUE_BONUS             = 379;
                constexpr INT32 TAN_BONUS              = 380;
                constexpr INT32 GREEN_BONUS            = 381;
                constexpr INT32 ORANGE_BONUS           = 382;
                constexpr INT32 PURPLE_BONUS           = 383;
                constexpr INT32 TEAL_BONUS             = 384;
                constexpr INT32 PINK_BONUS             = 385;
                constexpr INT32 PLAYER_FLAGS           = 387;

                constexpr INT32 TIMER_STYLE     = 3005; // hdmod
                constexpr INT32 MORE_OPTIONS    = 6999;
                constexpr INT32 RANDOM_TEMPLATE = 7002;
                constexpr INT32 TEAM_ALIGNMENT  = 7005;
            }
        } // namespace ID
    } /* namespace NH3Dlg */
    typedef NH3Dlg::eTextColor         eTextColor;
    typedef NH3Dlg::eTextAlignment     eTextAlignment;
    typedef NH3Dlg::ePictureCategories ePictureCategories;
} /* namespace h3 */
