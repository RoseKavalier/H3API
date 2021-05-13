//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-29              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Artifacts/H3Artifact.hpp"
#include "h3api/H3Artifacts/H3ArtifactSetup.hpp"

namespace h3
{
    _H3API_ H3Artifact::H3Artifact() :
        id(-1), subtype(-1)
    {
    }

    _H3API_ H3Artifact::H3Artifact(eArtifact id) :
        id(id), subtype(-1)
    {
    }

    _H3API_ H3Artifact::H3Artifact(eSpell spell_id) :
        id(eArtifact::SPELL_SCROLL), subtype(spell_id)
    {
    }

    _H3API_ H3Artifact::H3Artifact(INT32 id, INT32 subtype) :
        id(id), subtype(subtype)
    {
    }

    _H3API_ H3Artifact::H3Artifact(const H3Artifact& other) :
        id(other.id), subtype(other.subtype)
    {
    }

    _H3API_ VOID H3Artifact::operator=(const H3Artifact& other)
    {
        id = other.id;
        subtype = other.subtype;
    }

    _H3API_ BOOL H3Artifact::operator==(const H3Artifact& other) const
    {
        return id == other.id && subtype == other.subtype;
    }

    _H3API_ BOOL H3Artifact::operator!=(const H3Artifact& other) const
    {
        return id != other.id || subtype != other.subtype;
    }

    _H3API_ VOID H3Artifact::Clear()
    {
        id = eArtifact::NONE;
        subtype = -1;
    }

    _H3API_ H3Artifact H3Artifact::Remove()
    {
        H3Artifact art(*this);
        Clear();
        return art;
    }

    _H3API_ VOID H3Artifact::Swap(H3Artifact& other)
    {
        std::swap(id, other.id);
        std::swap(subtype, other.subtype);
    }

    _H3API_ LPCSTR H3Artifact::GetName() const
    {
        return GetSetup().name;
    }

    _H3API_ LPCSTR H3Artifact::GetDescription() const
    {
        return GetSetup().description;
    }

    _H3API_ INT32 H3Artifact::GetCost() const
    {
        return GetSetup().cost;
    }

    _H3API_ eArtifact H3Artifact::GetCombinationArtifact() const
    {
        return GetSetup().combinationArtifactId;
    }

    _H3API_ eArtifact H3Artifact::GetId() const
    {
        return eArtifact(id);
    }

    _H3API_ eCombinationArtifacts H3Artifact::GetCombinationArtifactIndex() const
    {
        return GetSetup().comboID;
    }

    _H3API_ eArtifactSlots H3Artifact::GetSlot() const
    {
        return GetSetup().position;
    }

    _H3API_ eArtifactType H3Artifact::GetType() const
    {
        return GetSetup().type;
    }

    _H3API_ const H3ArtifactSetup& H3Artifact::GetSetup() const
    {
        return H3ArtifactSetup::Get()[id];
    }

    _H3API_ eSpell H3Artifact::GetSpell() const
    {
        return GetSetup().newSpell;
    }

    _H3API_ eSpell H3Artifact::ScrollSpell() const
    {
        return eSpell(subtype);
    }
    _H3API_ BOOL H3Artifact::Empty() const
    {
        return id == eArtifact::NONE;
    }
    _H3API_ H3Artifact& H3HeldArtifact::Get()
    {
        return ValueAt<H3Artifact>(0x698AD8);
    }

} /* namespace h3 */
