//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-19              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3AI.hpp"
#include "h3api/H3AdventureMap.hpp"
#include "h3api/H3Artifacts.hpp"
#include "h3api/H3Assets.hpp"
#include "h3api/H3Campaign.hpp"
#include "h3api/H3Combat.hpp"
#include "h3api/H3Creatures.hpp"
#include "h3api/H3Dialogs.hpp"
#include "h3api/H3GameData.hpp"
#include "h3api/H3Heroes.hpp"
#include "h3api/H3Managers.hpp"
#include "h3api/H3Players/H3Player.hpp"
#include "h3api/H3Towns.hpp"

namespace h3
{
    namespace H3Internal
    {

        typedef H3DataPointer<H3ActivePlayer>         H3ActivePlayer_ptr;
        typedef H3DataPointer<H3AdventureManager>     H3AdventureManager_ptr;
        typedef H3DataPointer<H3AdveventText>         H3AdveventText_ptr;
        typedef H3DataPointer<H3BattleOptionsDlg>     H3BattleOptionsDlg_ptr;
        typedef H3DataPointer<H3BigFont>              H3BigFont_ptr;
        typedef H3DataPointer<H3ButtonWav>            H3ButtonWav_ptr;
        typedef H3DataPointer<H3CalliFont>            H3CalliFont_ptr;
        typedef H3DataPointer<H3CombatManager>        H3CombatManager_ptr;
        typedef H3DataPointer<H3DialogHero>           H3DialogHero_ptr;
        typedef H3DataPointer<H3ExecutiveMgr>         H3ExecutiveMgr_ptr;
        typedef H3DataPointer<H3GamePalette>          H3GamePalette_ptr;
        typedef H3DataPointer<H3GeneralText>          H3GeneralText_ptr;
        typedef H3DataPointer<H3InputManager>         H3InputManager_ptr;
        typedef H3DataPointer<H3Main>                 H3Main_ptr;
        typedef H3DataPointer<H3MediumFont>           H3MediumFont_ptr;
        typedef H3DataPointer<H3MouseManager>         H3MouseManager_ptr;
        typedef H3DataPointer<H3Pathfinder>           H3Pathfinder_ptr;
        typedef H3DataPointer<H3PlayersPalette>       H3PlayersPalette_ptr;
        typedef H3DataPointer<H3QuestsText>           H3QuestsText_ptr;
        typedef H3DataPointer<H3ResourceManager>      H3ResourceManager_ptr;
        typedef H3DataPointer<H3ScreenChat>           H3ScreenChat_ptr;
        typedef H3DataPointer<H3SeersText>            H3SeersText_ptr;
        typedef H3DataPointer<H3SelectScenarioDialog> H3SelectScenarioDialog_ptr;
        typedef H3DataPointer<H3SmallFont>            H3SmallFont_ptr;
        typedef H3DataPointer<H3SoundManager>         H3SoundManager_ptr;
        typedef H3DataPointer<H3SpellbookText>        H3SpellbookText_ptr;
        typedef H3DataPointer<H3TinyFont>             H3TinyFont_ptr;
        typedef H3DataPointer<H3TownManager>          H3TownManager_ptr;
        typedef H3DataPointer<H3TurnTimer>            H3TurnTimer_ptr;
        typedef H3DataPointer<H3WindowManager>        H3WindowManager_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3ActivePlayer_ptr         P_ActivePlayer;
    typedef H3Internal::H3AdventureManager_ptr     P_AdventureManager;
    typedef H3Internal::H3AdveventText_ptr         P_AdveventText;
    typedef H3Internal::H3BattleOptionsDlg_ptr     P_BattleOptionsDlg;
    typedef H3Internal::H3BigFont_ptr              P_BigFont;
    typedef H3Internal::H3ButtonWav_ptr            P_ButtonWav;
    typedef H3Internal::H3CalliFont_ptr            P_CalliFont;
    typedef H3Internal::H3CombatManager_ptr        P_CombatManager;
    typedef H3Internal::H3DialogHero_ptr           P_DialogHero;
    typedef H3Internal::H3ExecutiveMgr_ptr         P_ExecutiveMgr;
    typedef H3Internal::H3GamePalette_ptr          P_GamePalette;
    typedef H3Internal::H3GeneralText_ptr          P_GeneralText;
    typedef H3Internal::H3InputManager_ptr         P_InputManager;
    typedef H3Internal::H3Main_ptr                 P_Main;
    typedef H3Internal::H3MediumFont_ptr           P_MediumFont;
    typedef H3Internal::H3MouseManager_ptr         P_MouseManager;
    typedef H3Internal::H3Pathfinder_ptr           P_Pathfinder;
    typedef H3Internal::H3PlayersPalette_ptr       P_PlayersPalette;
    typedef H3Internal::H3QuestsText_ptr           P_QuestsText;
    typedef H3Internal::H3ResourceManager_ptr      P_ResourceManager;
    typedef H3Internal::H3ScreenChat_ptr           P_ScreenChat;
    typedef H3Internal::H3SeersText_ptr            P_SeersText;
    typedef H3Internal::H3SelectScenarioDialog_ptr P_SelectScenarioDialog;
    typedef H3Internal::H3SmallFont_ptr            P_SmallFont;
    typedef H3Internal::H3SoundManager_ptr         P_SoundManager;
    typedef H3Internal::H3SpellbookText_ptr        P_SpellbookText;
    typedef H3Internal::H3TinyFont_ptr             P_TinyFont;
    typedef H3Internal::H3TownManager_ptr          P_TownManager;
    typedef H3Internal::H3TurnTimer_ptr            P_TurnTimer;
    typedef H3Internal::H3WindowManager_ptr        P_WindowManager;

    typedef P_AdventureManager     P_AdventureMgr;
    typedef P_CombatManager        P_CombatMgr;
    typedef P_Main                 P_Game;
    typedef P_Main                 P_Base;
    typedef P_MouseManager         P_MouseMgr;
    typedef P_Pathfinder           P_MovementMgr;
    typedef P_ResourceManager      P_ResourceMgr;
    typedef P_SoundManager         P_SoundMgr;
    typedef P_TownManager          P_TownMgr;
    typedef P_WindowManager        P_WindowMgr;

#else

#define P_ActivePlayer         h3::H3Internal::H3ActivePlayer_ptr()
#define P_AdventureManager     h3::H3Internal::H3AdventureManager_ptr()
#define P_AdventureMgr         h3::H3Internal::H3AdventureManager_ptr()
#define P_AdveventText         h3::H3Internal::H3AdveventText_ptr()
#define P_BattleOptionsDlg     h3::H3Internal::H3BattleOptionsDlg_ptr()
#define P_BigFont              h3::H3Internal::H3BigFont_ptr()
#define P_ButtonWav            h3::H3Internal::H3ButtonWav_ptr()
#define P_CalliFont            h3::H3Internal::H3CalliFont_ptr()
#define P_CombatManager        h3::H3Internal::H3CombatManager_ptr()
#define P_CombatMgr            h3::H3Internal::H3CombatManager_ptr()
#define P_DialogHero           h3::H3Internal::H3DialogHero_ptr()
#define P_ExecutiveMgr         h3::H3Internal::H3ExecutiveMgr_ptr()
#define P_GamePalette          h3::H3Internal::H3GamePalette_ptr()
#define P_GeneralText          h3::H3Internal::H3GeneralText_ptr()
#define P_InputManager         h3::H3Internal::H3InputManager_ptr()
#define P_Main                 h3::H3Internal::H3Main_ptr()
#define P_Game                 h3::H3Internal::H3Main_ptr()
#define P_Base                 h3::H3Internal::H3Main_ptr()
#define P_MediumFont           h3::H3Internal::H3MediumFont_ptr()
#define P_MouseManager         h3::H3Internal::H3MouseManager_ptr()
#define P_MouseMgr             h3::H3Internal::H3MouseManager_ptr()
#define P_Pathfinder           h3::H3Internal::H3Pathfinder_ptr()
#define P_MovementMgr          h3::H3Internal::H3Pathfinder_ptr()
#define P_PlayersPalette       h3::H3Internal::H3PlayersPalette_ptr()
#define P_QuestsText           h3::H3Internal::H3QuestsText_ptr()
#define P_ResourceManager      h3::H3Internal::H3ResourceManager_ptr()
#define P_ResourceMgr          h3::H3Internal::H3ResourceManager_ptr()
#define P_ScreenChat           h3::H3Internal::H3ScreenChat_ptr()
#define P_SeersText            h3::H3Internal::H3SeersText_ptr()
#define P_SelectScenarioDialog h3::H3Internal::H3SelectScenarioDialog_ptr()
#define P_SmallFont            h3::H3Internal::H3SmallFont_ptr()
#define P_SoundManager         h3::H3Internal::H3SoundManager_ptr()
#define P_SoundMgr             h3::H3Internal::H3SoundManager_ptr()
#define P_SpellbookText        h3::H3Internal::H3SpellbookText_ptr()
#define P_TinyFont             h3::H3Internal::H3TinyFont_ptr()
#define P_TownManager          h3::H3Internal::H3TownManager_ptr()
#define P_TownMgr              h3::H3Internal::H3TownManager_ptr()
#define P_TurnTimer            h3::H3Internal::H3TurnTimer_ptr()
#define P_WindowManager        h3::H3Internal::H3WindowManager_ptr()
#define P_WindowMgr            h3::H3Internal::H3WindowManager_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */
