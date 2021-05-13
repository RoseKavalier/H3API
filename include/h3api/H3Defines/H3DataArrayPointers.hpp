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

#include "h3api/H3AdventureMap.hpp"
#include "h3api/H3Artifacts.hpp"
#include "h3api/H3Assets.hpp"
#include "h3api/H3Base/H3Config.hpp"
#include "h3api/H3Campaign.hpp"
#include "h3api/H3Combat.hpp"
#include "h3api/H3Creatures.hpp"
#include "h3api/H3GameData.hpp"
#include "h3api/H3Heroes.hpp"
#include "h3api/H3Towns.hpp"

namespace h3
{
    namespace H3Internal
    {

        typedef H3DataArrayPointer<H3ArtifactSetup>          H3ArtifactSetup_ptr;
        typedef H3DataArrayPointer<H3CmpBonusBuildingsNames> H3CmpBonusBuildingsNames_ptr;
        typedef H3DataArrayPointer<H3CreatureBankSetup>      H3CreatureBankSetup_ptr;
        typedef H3DataArrayPointer<H3CreatureInformation>    H3CreatureInformation_ptr;
        typedef H3DataArrayPointer<H3DwellingBuildingCosts>  H3DwellingBuildingCosts_ptr;
        typedef H3DataArrayPointer<H3GlobalObjectSettings>   H3GlobalObjectSettings_ptr;
        typedef H3DataArrayPointer<H3HeroInfo>               H3HeroInfo_ptr;
        typedef H3DataArrayPointer<H3HeroSpecialty>          H3HeroSpecialty_ptr;
        typedef H3DataArrayPointer<H3ObstacleInfo>           H3ObstacleInfo_ptr;
        typedef H3DataArrayPointer<H3PuzzleCoordinates>      H3PuzzleCoordinates_ptr;
        typedef H3DataArrayPointer<H3PuzzlePiecesOrder>      H3PuzzlePiecesOrder_ptr;
        typedef H3DataArrayPointer<H3SecondarySkillInfo>     H3SecondarySkillInfo_ptr;
        typedef H3DataArrayPointer<H3SpecialBuildingCosts>   H3SpecialBuildingCosts_ptr;
        typedef H3DataArrayPointer<H3Spell>                  H3Spell_ptr;
        typedef H3DataArrayPointer<H3TownCreatureTypes>      H3TownCreatureTypes_ptr;
        typedef H3DataArrayPointer<H3TownDependencies>       H3TownDependencies_ptr;
        typedef H3DataArrayPointer<H3ValidCatapultTargets>   H3ValidCatapultTargets_ptr;

    } /* namespace H3Internal */

#ifdef _H3API_DONT_USE_MACROS_

    typedef H3Internal::H3ArtifactSetup_ptr          P_ArtifactSetup;
    typedef H3Internal::H3CmpBonusBuildingsNames_ptr P_CmpBonusBuildingsNames;
    typedef H3Internal::H3CreatureBankSetup_ptr      P_CreatureBankSetup;
    typedef H3Internal::H3CreatureInformation_ptr    P_CreatureInformation;
    typedef H3Internal::H3DwellingBuildingCosts_ptr  P_DwellingBuildingCosts;
    typedef H3Internal::H3GlobalObjectSettings_ptr   P_GlobalObjectSettings;
    typedef H3Internal::H3HeroInfo_ptr               P_HeroInfo;
    typedef H3Internal::H3HeroSpecialty_ptr          P_HeroSpecialty;
    typedef H3Internal::H3ObstacleInfo_ptr           P_ObstacleInfo;
    typedef H3Internal::H3PuzzleCoordinates_ptr      P_PuzzleCoordinates;
    typedef H3Internal::H3PuzzlePiecesOrder_ptr      P_PuzzlePiecesOrder;
    typedef H3Internal::H3SecondarySkillInfo_ptr     P_SecondarySkillInfo;
    typedef H3Internal::H3SpecialBuildingCosts_ptr   P_SpecialBuildingCosts;
    typedef H3Internal::H3Spell_ptr                  P_Spell;
    typedef H3Internal::H3TownCreatureTypes_ptr      P_TownCreatureTypes;
    typedef H3Internal::H3TownDependencies_ptr       P_TownDependencies;
    typedef H3Internal::H3ValidCatapultTargets_ptr   P_ValidCatapultTargets;

    typedef P_ArtifactSetup          P_Artifacts;
    typedef P_CreatureBankSetup      P_CreatureBankTable;
    typedef P_CreatureInformation    P_Creatures;
    typedef P_GlobalObjectSettings   P_ObjectSettings;
    typedef P_ObstacleInfo           P_DefObstacleInfo;
    typedef P_TownCreatureTypes      P_TownCreatureTypes;
    typedef P_TownDependencies       P_TownDependencies;

#else

#define P_ArtifactSetup          h3::H3Internal::H3ArtifactSetup_ptr()
#define P_Artifacts              h3::H3Internal::H3ArtifactSetup_ptr()
#define P_CmpBonusBuildingsNames h3::H3Internal::H3CmpBonusBuildingsNames_ptr()
#define P_CreatureBankSetup      h3::H3Internal::H3CreatureBankSetup_ptr()
#define P_CreatureBankTable      h3::H3Internal::H3CreatureBankSetup_ptr()
#define P_CreatureInformation    h3::H3Internal::H3CreatureInformation_ptr()
#define P_Creatures              h3::H3Internal::H3CreatureInformation_ptr()
#define P_DwellingBuildingCosts  h3::H3Internal::H3DwellingBuildingCosts_ptr()
#define P_GlobalObjectSettings   h3::H3Internal::H3GlobalObjectSettings_ptr()
#define P_ObjectSettings         h3::H3Internal::H3GlobalObjectSettings_ptr()
#define P_HeroInfo               h3::H3Internal::H3HeroInfo_ptr()
#define P_HeroSpecialty          h3::H3Internal::H3HeroSpecialty_ptr()
#define P_ObstacleInfo           h3::H3Internal::H3ObstacleInfo_ptr()
#define P_DefObstacleInfo        h3::H3Internal::H3ObstacleInfo_ptr()
#define P_PuzzleCoordinates      h3::H3Internal::H3PuzzleCoordinates_ptr()
#define P_PuzzlePiecesOrder      h3::H3Internal::H3PuzzlePiecesOrder_ptr()
#define P_SecondarySkillInfo     h3::H3Internal::H3SecondarySkillInfo_ptr()
#define P_SpecialBuildingCosts   h3::H3Internal::H3SpecialBuildingCosts_ptr()
#define P_Spell                  h3::H3Internal::H3Spell_ptr()
#define P_TownCreatureTypes      h3::H3Internal::H3TownCreatureTypes_ptr()
#define P_TownCreatureTypes      h3::H3Internal::H3TownCreatureTypes_ptr()
#define P_TownDependencies       h3::H3Internal::H3TownDependencies_ptr()
#define P_TownDependencies       h3::H3Internal::H3TownDependencies_ptr()
#define P_ValidCatapultTargets   h3::H3Internal::H3ValidCatapultTargets_ptr()

#endif /* _H3API_DONT_USE_MACROS_ */

} /* namespace h3 */
