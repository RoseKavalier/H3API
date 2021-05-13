//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-29              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants/H3CstArtifact.hpp"
#include "h3api/H3Constants/H3CstSpells.hpp"

namespace h3
{
    _H3API_DECLARE_(ArtifactSetup);

#pragma pack(push, 4)

    /** @brief information about artifacts*/
    struct H3ArtifactSetup
    {
        _H3API_SIZE_(0x20);
        _H3API_GET_INFO_(0x660B68, H3ArtifactSetup);

        /** @brief [0] */
        LPCSTR name;
        /** @brief [4] gold cost*/
        INT32 cost;
        /** @brief [8]*/
        eArtifactSlots position;
        /** @brief [C]*/
        eArtifactType type;
        /** @brief [10]*/
        LPCSTR description;
        /** @brief [14] index of the combo 0..11*/
        eCombinationArtifacts comboID;
        /** @brief [18] index of the artifact 0..143*/
        eArtifact  combinationArtifactId;
        /** @brief [1C] artifact is not available*/
        BOOL8 disabled;
        /** @brief [1D] spell added to spellbook*/
        eSpell  newSpell;

        _H3API_ BOOL IsPartOfCombo() const;
    };
    _H3API_ASSERT_SIZE_(H3ArtifactSetup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
