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

    _H3API_DECLARE_(AnimationSpeed);
    _H3API_DECLARE_(CastleName);
    _H3API_DECLARE_(CmpVoiceover);
    _H3API_DECLARE_(DwellingNames1);
    _H3API_DECLARE_(DwellingNames4);
    _H3API_DECLARE_(HeroDefaultBiography);
    _H3API_DECLARE_(MineNames);
    _H3API_DECLARE_(ObjectName);
    _H3API_DECLARE_(PlayerColor);
    _H3API_DECLARE_(PrimarySkillName);
    _H3API_DECLARE_(RandomSignText);
    _H3API_DECLARE_(ResourceName);
    _H3API_DECLARE_(SecondarySkillLevel);
    _H3API_DECLARE_(TentColors);
    _H3API_DECLARE_(TerrainName);
    _H3API_DECLARE_(TownNames);

    struct H3AnimationSpeed
    {
        static constexpr h3::ADDRESS ADDRESS = 0x43F255 + 3;
        static FLOAT* Get() { return ValueAt<FLOAT*>(0x43F255 + 3); }
        typedef FLOAT* VALUE_TYPE;
    };
    struct H3CastleName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40C9A8 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40C9A8 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3CmpVoiceover
    {
        static constexpr h3::ADDRESS ADDRESS = 0x44D5C3 + 2;
        static  LPCSTR* Get() { return ValueAt< LPCSTR*>(0x44D5C3 + 2); }
        typedef  LPCSTR* VALUE_TYPE;
    };
    struct H3DwellingNames1
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B514 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B514 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3DwellingNames4
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B556 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B556 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3HeroDefaultBiography
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4D92B7 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x4D92B7 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3MineNames
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40D60B + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40D60B + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3ObjectName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B184 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B184 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3PlayerColor
    {
        static constexpr h3::ADDRESS ADDRESS = 0x406A7B + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x406A7B + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3PrimarySkillName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x460CED + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x460CED + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3RandomSignText
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4A97E9 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x4A97E9 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3ResourceName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x406A14 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x406A14 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3SecondarySkillLevel
    {
        static constexpr h3::ADDRESS ADDRESS = 0x4847B1 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x4847B1 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3TentColors
    {
        static constexpr h3::ADDRESS ADDRESS = 0x40B268 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x40B268 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3TerrainName
    {
        static constexpr h3::ADDRESS ADDRESS = 0x413963 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x413963 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };
    struct H3TownNames
    {
        static constexpr h3::ADDRESS ADDRESS = 0x5C1854 + 3;
        static LPCSTR* Get() { return ValueAt<LPCSTR*>(0x5C1854 + 3); }
        typedef LPCSTR* VALUE_TYPE;
    };

    namespace H3Internal
    {

        typedef H3PrimitiveArrayPointer<H3AnimationSpeed>       H3AnimationSpeed_ptr;
        typedef H3PrimitiveArrayPointer<H3CastleName>           H3CastleName_ptr;
        typedef H3PrimitiveArrayPointer<H3CmpVoiceover>         H3CmpVoiceover_ptr;
        typedef H3PrimitiveArrayPointer<H3DwellingNames1>       H3DwellingNames1_ptr;
        typedef H3PrimitiveArrayPointer<H3DwellingNames4>       H3DwellingNames4_ptr;
        typedef H3PrimitiveArrayPointer<H3HeroDefaultBiography> H3HeroDefaultBiography_ptr;
        typedef H3PrimitiveArrayPointer<H3MineNames>            H3MineNames_ptr;
        typedef H3PrimitiveArrayPointer<H3ObjectName>           H3ObjectName_ptr;
        typedef H3PrimitiveArrayPointer<H3PlayerColor>          H3PlayerColor_ptr;
        typedef H3PrimitiveArrayPointer<H3PrimarySkillName>     H3PrimarySkillName_ptr;
        typedef H3PrimitiveArrayPointer<H3RandomSignText>       H3RandomSignText_ptr;
        typedef H3PrimitiveArrayPointer<H3ResourceName>         H3ResourceName_ptr;
        typedef H3PrimitiveArrayPointer<H3SecondarySkillLevel>  H3SecondarySkillLevel_ptr;
        typedef H3PrimitiveArrayPointer<H3TentColors>           H3TentColors_ptr;
        typedef H3PrimitiveArrayPointer<H3TerrainName>          H3TerrainName_ptr;
        typedef H3PrimitiveArrayPointer<H3TownNames>            H3TownNames_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3AnimationSpeed_ptr       P_AnimationSpeed;
    typedef H3Internal::H3CastleName_ptr           P_CastleName;
    typedef H3Internal::H3CmpVoiceover_ptr         P_CmpVoiceover;
    typedef H3Internal::H3DwellingNames1_ptr       P_DwellingNames1;
    typedef H3Internal::H3DwellingNames4_ptr       P_DwellingNames4;
    typedef H3Internal::H3HeroDefaultBiography_ptr P_HeroDefaultBiography;
    typedef H3Internal::H3MineNames_ptr            P_MineNames;
    typedef H3Internal::H3ObjectName_ptr           P_ObjectName;
    typedef H3Internal::H3PlayerColor_ptr          P_PlayerColor;
    typedef H3Internal::H3PrimarySkillName_ptr     P_PrimarySkillName;
    typedef H3Internal::H3RandomSignText_ptr       P_RandomSignText;
    typedef H3Internal::H3ResourceName_ptr         P_ResourceName;
    typedef H3Internal::H3SecondarySkillLevel_ptr  P_SecondarySkillLevel;
    typedef H3Internal::H3TentColors_ptr           P_TentColors;
    typedef H3Internal::H3TerrainName_ptr          P_TerrainName;
    typedef H3Internal::H3TownNames_ptr            P_TownNames;

#else

#define P_AnimationSpeed       h3::H3Internal::H3AnimationSpeed_ptr()
#define P_CastleName           h3::H3Internal::H3CastleName_ptr()
#define P_CmpVoiceover         h3::H3Internal::H3CmpVoiceover_ptr()
#define P_DwellingNames1       h3::H3Internal::H3DwellingNames1_ptr()
#define P_DwellingNames4       h3::H3Internal::H3DwellingNames4_ptr()
#define P_HeroDefaultBiography h3::H3Internal::H3HeroDefaultBiography_ptr()
#define P_MineNames            h3::H3Internal::H3MineNames_ptr()
#define P_ObjectName           h3::H3Internal::H3ObjectName_ptr()
#define P_PlayerColor          h3::H3Internal::H3PlayerColor_ptr()
#define P_PrimarySkillName     h3::H3Internal::H3PrimarySkillName_ptr()
#define P_RandomSignText       h3::H3Internal::H3RandomSignText_ptr()
#define P_ResourceName         h3::H3Internal::H3ResourceName_ptr()
#define P_SecondarySkillLevel  h3::H3Internal::H3SecondarySkillLevel_ptr()
#define P_TentColors           h3::H3Internal::H3TentColors_ptr()
#define P_TerrainName          h3::H3Internal::H3TerrainName_ptr()
#define P_TownNames            h3::H3Internal::H3TownNames_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */
