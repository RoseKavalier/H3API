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
    _H3API_DECLARE_(Artifact);
    _H3API_DECLARE_(HeldArtifact);
    struct H3ArtifactSetup;

#pragma pack(push, 4)

    /** @brief Artifacts as stored on heroes and passed as arguments*/
    struct H3Artifact
    {
        _H3API_SIZE_(8);

        /** @brief [00] 0..140 eArtifacts*/
        INT32 id;
        /** @brief [04] spell id for spell scrolls, otherwise -1*/
        INT32 subtype;

        _H3API_ H3Artifact();
        _H3API_ H3Artifact(eArtifact id);
        _H3API_ H3Artifact(eSpell spell_id);
        _H3API_ H3Artifact(INT32 id, INT32 subtype);
        _H3API_ H3Artifact(const H3Artifact& other);
        _H3API_ VOID operator=(const H3Artifact& other);
        _H3API_ BOOL operator==(const H3Artifact& other) const;
        _H3API_ BOOL operator!=(const H3Artifact& other) const;
        _H3API_ VOID                   Clear();
        _H3API_ BOOL                   Empty() const;
        _H3API_ LPCSTR                 GetName() const;
        _H3API_ LPCSTR                 GetDescription() const;
        _H3API_ INT32                  GetCost() const;
        _H3API_ eArtifact              GetCombinationArtifact() const;
        _H3API_ eArtifact              GetId() const;
        _H3API_ eCombinationArtifacts  GetCombinationArtifactIndex() const;
        _H3API_ eArtifactSlots         GetSlot() const;
        _H3API_ eArtifactType          GetType() const;
        _H3API_ const H3ArtifactSetup& GetSetup() const;
        _H3API_ eSpell                 GetSpell() const;
        _H3API_ H3Artifact             Remove();
        _H3API_ eSpell                 ScrollSpell() const;
        _H3API_ VOID                   Swap(H3Artifact& other);

    };
    _H3API_ASSERT_SIZE_(H3Artifact)	;

    struct H3HeldArtifact : H3Artifact
    {
        /**
         * @brief The artifact being held in the mouse cursor
         * @return Reference to this artifact (write-access enabled)
         */
        _H3API_ static H3Artifact& Get();
    };

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
