//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-20              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

// This file has no more dependencies and may be included anywhere necessary within H3API
#include "h3api/H3Base/H3Config.hpp"

namespace h3
{

    _H3API_DECLARE_(ActivePlayerBitset);
    _H3API_DECLARE_(ArtifactCount);
    _H3API_DECLARE_(AutoSolo);
    _H3API_DECLARE_(BitMode);
    _H3API_DECLARE_(BlueMask);
    _H3API_DECLARE_(BootsOfSpeedBonus);
    _H3API_DECLARE_(CreatureCount);
    _H3API_DECLARE_(CurrentAnimationSpeed);
    _H3API_DECLARE_(CurrentPlayerID);
    _H3API_DECLARE_(EquestriansGlovesBonus);
    _H3API_DECLARE_(GameEdgeHorizontal);
    _H3API_DECLARE_(GameEdgeVertical);
    _H3API_DECLARE_(GameHeight);
    _H3API_DECLARE_(GameWidth);
    _H3API_DECLARE_(GreenMask);
    _H3API_DECLARE_(HeroCount);
    _H3API_DECLARE_(HeroRetreated);
    _H3API_DECLARE_(HeroSurrendered);
    _H3API_DECLARE_(HumanID);
    _H3API_DECLARE_(Hwnd);
    _H3API_DECLARE_(Instance);
    _H3API_DECLARE_(IsCampaignGame);
    _H3API_DECLARE_(MapSize);
    _H3API_DECLARE_(Module);
    _H3API_DECLARE_(NecklaceOceanGuidanceBonus);
    _H3API_DECLARE_(RedMask);
    _H3API_DECLARE_(SeaCaptainsHatBonus);
    _H3API_DECLARE_(SpellCount);
    _H3API_DECLARE_(StablesBonus);
    _H3API_DECLARE_(TextDlgMaxHeight);
    _H3API_DECLARE_(TextDlgMaxWidth);
    _H3API_DECLARE_(TownCount);

    struct H3ActivePlayerBitset
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69CD10;
        static UINT8 Get() { return ValueAt<UINT8>(0x69CD10); }
        typedef UINT8 VALUE_TYPE;
    };
    struct H3ArtifactCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x44D1A8 + 2;
        static INT32 Get() { return ValueAt<INT32>(0x44D1A8 + 2); }
        typedef INT32 VALUE_TYPE;
    };
    struct H3AutoSolo
    {
        static constexpr h3::ADDRESS ADDRESS = 0x691259;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x691259); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3BitMode
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5FA228 + 3;
        static UINT8 Get() { return ValueAt<UINT8>(0x5FA228 + 3); }
        typedef UINT8 VALUE_TYPE;
    };
    struct H3BlueMask
    {
        static constexpr h3::ADDRESS ADDRESS = 0x694DB4;
        static UINT32 Get() { return ValueAt<UINT32>(0x694DB4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3BootsOfSpeedBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B50;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B50); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3CreatureCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5C8046 + 1;
        static UINT32 Get() { return ValueAt<UINT32>(0x5C8046 + 1); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3CurrentAnimationSpeed
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69883C;
        static UINT32 Get() { return ValueAt<UINT32>(0x69883C); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3CurrentPlayerID
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69CCF4;
        static UINT32 Get() { return ValueAt<UINT32>(0x69CCF4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3EquestriansGlovesBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B4C;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B4C); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3GameEdgeHorizontal
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A8FBE + 2;
        static INT8 Get() { return ValueAt<INT8>(0x4A8FBE + 2); }
        typedef INT8 VALUE_TYPE;
    };
    struct H3GameEdgeVertical
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A8FC3 + 2;
        static INT8 Get() { return ValueAt<INT8>(0x4A8FC3 + 2); }
        typedef INT8 VALUE_TYPE;
    };
    struct H3GameHeight
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4033FB + 1;
        static INT32 Get() { return ValueAt<INT32>(0x4033FB + 1); }
        typedef INT32 VALUE_TYPE;
    };
    struct H3GameWidth
    {
        static constexpr h3::ADDRESS ADDRESS = 0x403400 + 1;
        static INT32 Get() { return ValueAt<INT32>(0x403400 + 1); }
        typedef INT32 VALUE_TYPE;
    };
    struct H3GreenMask
    {
        static constexpr h3::ADDRESS ADDRESS = 0x694DB0;
        static UINT32 Get() { return ValueAt<UINT32>(0x694DB0); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3HeroCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4BD144 + 1;
        static UINT32 Get() { return ValueAt<UINT32>(0x4BD144 + 1); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3HeroRetreated
    {
        static constexpr h3::ADDRESS ADDRESS = 0x6985F3;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x6985F3); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3HeroSurrendered
    {
        static constexpr h3::ADDRESS ADDRESS = 0x697794;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x697794); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3HumanID
    {
        static constexpr h3::ADDRESS ADDRESS = 0x6995A4;
        static UINT32 Get() { return ValueAt<UINT32>(0x6995A4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3Hwnd
    {
        static constexpr h3::ADDRESS ADDRESS = 0x699650;
        static HWND Get() { return ValueAt<HWND>(0x699650); }
        typedef HWND VALUE_TYPE;
    };
    struct H3Instance
    {
        static constexpr h3::ADDRESS ADDRESS = 0x699604;
        static HINSTANCE Get() { return ValueAt<HINSTANCE>(0x699604); }
        typedef HINSTANCE VALUE_TYPE;
    };
    struct H3IsCampaignGame
    {
        static constexpr h3::ADDRESS ADDRESS = 0x69779C;
        static BOOL8 Get() { return ValueAt<BOOL8>(0x69779C); }
        typedef BOOL8 VALUE_TYPE;
    };
    struct H3MapSize
    {
        static constexpr h3::ADDRESS ADDRESS = 0x6783C8;
        static UINT32 Get() { return ValueAt<UINT32>(0x6783C8); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3Module
    {
        static constexpr h3::ADDRESS ADDRESS = 0x699604;
        static HMODULE Get() { return ValueAt<HMODULE>(0x699604); }
        typedef HMODULE VALUE_TYPE;
    };
    struct H3NecklaceOceanGuidanceBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B54;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B54); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3RedMask
    {
        static constexpr h3::ADDRESS ADDRESS = 0x694DB8;
        static UINT32 Get() { return ValueAt<UINT32>(0x694DB8); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3SeaCaptainsHatBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698B5C;
        static UINT32 Get() { return ValueAt<UINT32>(0x698B5C); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3SpellCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A2741 + 2;
        static INT8 Get() { return ValueAt<INT8>(0x4A2741 + 2); }
        typedef INT8 VALUE_TYPE;
    };
    struct H3StablesBonus
    {
        static constexpr h3::ADDRESS ADDRESS = 0x698AE4;
        static UINT32 Get() { return ValueAt<UINT32>(0x698AE4); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3TextDlgMaxHeight
    {
        static constexpr h3::ADDRESS ADDRESS = 0x415AC1 + 2;
        static UINT32 Get() { return ValueAt<UINT32>(0x415AC1 + 2); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3TextDlgMaxWidth
    {
        static constexpr h3::ADDRESS ADDRESS = 0x415AAB + 2;
        static UINT32 Get() { return ValueAt<UINT32>(0x415AAB + 2); }
        typedef UINT32 VALUE_TYPE;
    };
    struct H3TownCount
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5BE36E + 3;
        static INT32 Get() { return ValueAt<INT32>(0x5BE36E + 3); }
        typedef INT32 VALUE_TYPE;
    };

    namespace H3Internal
    {

        typedef H3PrimitivePointer<H3ActivePlayerBitset>         H3ActivePlayerBitset_ptr;
        typedef H3PrimitivePointer<H3ArtifactCount>              H3ArtifactCount_ptr;
        typedef H3PrimitivePointer<H3AutoSolo>                   H3AutoSolo_ptr;
        typedef H3PrimitivePointer<H3BitMode>                    H3BitMode_ptr;
        typedef H3PrimitivePointer<H3BlueMask>                   H3BlueMask_ptr;
        typedef H3PrimitivePointer<H3BootsOfSpeedBonus>          H3BootsOfSpeedBonus_ptr;
        typedef H3PrimitivePointer<H3CreatureCount>              H3CreatureCount_ptr;
        typedef H3PrimitivePointer<H3CurrentAnimationSpeed>      H3CurrentAnimationSpeed_ptr;
        typedef H3PrimitivePointer<H3CurrentPlayerID>            H3CurrentPlayerID_ptr;
        typedef H3PrimitivePointer<H3EquestriansGlovesBonus>     H3EquestriansGlovesBonus_ptr;
        typedef H3PrimitivePointer<H3GameEdgeHorizontal>         H3GameEdgeHorizontal_ptr;
        typedef H3PrimitivePointer<H3GameEdgeVertical>           H3GameEdgeVertical_ptr;
        typedef H3PrimitivePointer<H3GameHeight>                 H3GameHeight_ptr;
        typedef H3PrimitivePointer<H3GameWidth>                  H3GameWidth_ptr;
        typedef H3PrimitivePointer<H3GreenMask>                  H3GreenMask_ptr;
        typedef H3PrimitivePointer<H3HeroCount>                  H3HeroCount_ptr;
        typedef H3PrimitivePointer<H3HeroRetreated>              H3HeroRetreated_ptr;
        typedef H3PrimitivePointer<H3HeroSurrendered>            H3HeroSurrendered_ptr;
        typedef H3PrimitivePointer<H3HumanID>                    H3HumanID_ptr;
        typedef H3PrimitivePointer<H3Hwnd>                       H3Hwnd_ptr;
        typedef H3PrimitivePointer<H3Instance>                   H3Instance_ptr;
        typedef H3PrimitivePointer<H3IsCampaignGame>             H3IsCampaignGame_ptr;
        typedef H3PrimitivePointer<H3MapSize>                    H3MapSize_ptr;
        typedef H3PrimitivePointer<H3Module>                     H3Module_ptr;
        typedef H3PrimitivePointer<H3NecklaceOceanGuidanceBonus> H3NecklaceOceanGuidanceBonus_ptr;
        typedef H3PrimitivePointer<H3RedMask>                    H3RedMask_ptr;
        typedef H3PrimitivePointer<H3SeaCaptainsHatBonus>        H3SeaCaptainsHatBonus_ptr;
        typedef H3PrimitivePointer<H3SpellCount>                 H3SpellCount_ptr;
        typedef H3PrimitivePointer<H3StablesBonus>               H3StablesBonus_ptr;
        typedef H3PrimitivePointer<H3TextDlgMaxHeight>           H3TextDlgMaxHeight_ptr;
        typedef H3PrimitivePointer<H3TextDlgMaxWidth>            H3TextDlgMaxWidth_ptr;
        typedef H3PrimitivePointer<H3TownCount>                  H3TownCount_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3ActivePlayerBitset_ptr         P_ActivePlayerBitset;
    typedef H3Internal::H3ArtifactCount_ptr              P_ArtifactCount;
    typedef H3Internal::H3AutoSolo_ptr                   P_AutoSolo;
    typedef H3Internal::H3BitMode_ptr                    P_BitMode;
    typedef H3Internal::H3BlueMask_ptr                   P_BlueMask;
    typedef H3Internal::H3BootsOfSpeedBonus_ptr          P_BootsOfSpeedBonus;
    typedef H3Internal::H3CreatureCount_ptr              P_CreatureCount;
    typedef H3Internal::H3CurrentAnimationSpeed_ptr      P_CurrentAnimationSpeed;
    typedef H3Internal::H3CurrentPlayerID_ptr            P_CurrentPlayerID;
    typedef H3Internal::H3EquestriansGlovesBonus_ptr     P_EquestriansGlovesBonus;
    typedef H3Internal::H3GameEdgeHorizontal_ptr         P_GameEdgeHorizontal;
    typedef H3Internal::H3GameEdgeVertical_ptr           P_GameEdgeVertical;
    typedef H3Internal::H3GameHeight_ptr                 P_GameHeight;
    typedef H3Internal::H3GameWidth_ptr                  P_GameWidth;
    typedef H3Internal::H3GreenMask_ptr                  P_GreenMask;
    typedef H3Internal::H3HeroCount_ptr                  P_HeroCount;
    typedef H3Internal::H3HeroRetreated_ptr              P_HeroRetreated;
    typedef H3Internal::H3HeroSurrendered_ptr            P_HeroSurrendered;
    typedef H3Internal::H3HumanID_ptr                    P_HumanID;
    typedef H3Internal::H3Hwnd_ptr                       P_Hwnd;
    typedef H3Internal::H3Instance_ptr                   P_Instance;
    typedef H3Internal::H3IsCampaignGame_ptr             P_IsCampaignGame;
    typedef H3Internal::H3MapSize_ptr                    P_MapSize;
    typedef H3Internal::H3Module_ptr                     P_Module;
    typedef H3Internal::H3NecklaceOceanGuidanceBonus_ptr P_NecklaceOceanGuidanceBonus;
    typedef H3Internal::H3RedMask_ptr                    P_RedMask;
    typedef H3Internal::H3SeaCaptainsHatBonus_ptr        P_SeaCaptainsHatBonus;
    typedef H3Internal::H3SpellCount_ptr                 P_SpellCount;
    typedef H3Internal::H3StablesBonus_ptr               P_StablesBonus;
    typedef H3Internal::H3TextDlgMaxHeight_ptr           P_TextDlgMaxHeight;
    typedef H3Internal::H3TextDlgMaxWidth_ptr            P_TextDlgMaxWidth;
    typedef H3Internal::H3TownCount_ptr                  P_TownCount;

#else

#define P_ActivePlayerBitset         h3::H3Internal::H3ActivePlayerBitset_ptr()
#define P_ArtifactCount              h3::H3Internal::H3ArtifactCount_ptr()
#define P_AutoSolo                   h3::H3Internal::H3AutoSolo_ptr()
#define P_BitMode                    h3::H3Internal::H3BitMode_ptr()
#define P_BlueMask                   h3::H3Internal::H3BlueMask_ptr()
#define P_BootsOfSpeedBonus          h3::H3Internal::H3BootsOfSpeedBonus_ptr()
#define P_CreatureCount              h3::H3Internal::H3CreatureCount_ptr()
#define P_CurrentAnimationSpeed      h3::H3Internal::H3CurrentAnimationSpeed_ptr()
#define P_CurrentPlayerID            h3::H3Internal::H3CurrentPlayerID_ptr()
#define P_EquestriansGlovesBonus     h3::H3Internal::H3EquestriansGlovesBonus_ptr()
#define P_GameEdgeHorizontal         h3::H3Internal::H3GameEdgeHorizontal_ptr()
#define P_GameEdgeVertical           h3::H3Internal::H3GameEdgeVertical_ptr()
#define P_GameHeight                 h3::H3Internal::H3GameHeight_ptr()
#define P_GameWidth                  h3::H3Internal::H3GameWidth_ptr()
#define P_GreenMask                  h3::H3Internal::H3GreenMask_ptr()
#define P_HeroCount                  h3::H3Internal::H3HeroCount_ptr()
#define P_HeroRetreated              h3::H3Internal::H3HeroRetreated_ptr()
#define P_HeroSurrendered            h3::H3Internal::H3HeroSurrendered_ptr()
#define P_HumanID                    h3::H3Internal::H3HumanID_ptr()
#define P_Hwnd                       h3::H3Internal::H3Hwnd_ptr()
#define P_Instance                   h3::H3Internal::H3Instance_ptr()
#define P_IsCampaignGame             h3::H3Internal::H3IsCampaignGame_ptr()
#define P_MapSize                    h3::H3Internal::H3MapSize_ptr()
#define P_Module                     h3::H3Internal::H3Module_ptr()
#define P_NecklaceOceanGuidanceBonus h3::H3Internal::H3NecklaceOceanGuidanceBonus_ptr()
#define P_RedMask                    h3::H3Internal::H3RedMask_ptr()
#define P_SeaCaptainsHatBonus        h3::H3Internal::H3SeaCaptainsHatBonus_ptr()
#define P_SpellCount                 h3::H3Internal::H3SpellCount_ptr()
#define P_StablesBonus               h3::H3Internal::H3StablesBonus_ptr()
#define P_TextDlgMaxHeight           h3::H3Internal::H3TextDlgMaxHeight_ptr()
#define P_TextDlgMaxWidth            h3::H3Internal::H3TextDlgMaxWidth_ptr()
#define P_TownCount                  h3::H3Internal::H3TownCount_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */
