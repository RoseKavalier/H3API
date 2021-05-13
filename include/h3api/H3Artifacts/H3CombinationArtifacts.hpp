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
#include "h3api/H3Containers/H3Bitset.hpp"
#include "h3api/H3Constants/H3CstArtifact.hpp"

namespace h3
{
    _H3API_DECLARE_(ComboArtifactSetup);
    struct H3Artifact;

#pragma pack(push, 4)

    /** @brief combo artifacts are stored in memory using a bitset*/
    struct H3ComboArtifactSetup
    {
        _H3API_SIZE_(0x18);
        _H3API_GET_INFO_(0x4DDFF2 + 2, H3ComboArtifactSetup);

        /** @brief [00] matching artifact id of this combo*/
        eArtifact index;
        /** @brief [04] bitset of required artifacts*/
        H3ArtifactBitset artifacts;

        _H3API_ BOOL IsPartOfCombo(eArtifact id) const;
        _H3API_ BOOL IsPartOfCombo(const H3Artifact& art) const;
    };
    _H3API_ASSERT_SIZE_(H3ComboArtifactSetup);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
