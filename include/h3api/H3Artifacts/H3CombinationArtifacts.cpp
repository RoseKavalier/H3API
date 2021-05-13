//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-29              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Artifacts/H3CombinationArtifacts.hpp"
#include "h3api/H3Artifacts/H3Artifact.hpp"

namespace h3
{
    _H3API_ BOOL H3ComboArtifactSetup::IsPartOfCombo(eArtifact id) const
    {
        return artifacts.Test(id);
    }
    _H3API_ BOOL H3ComboArtifactSetup::IsPartOfCombo(const H3Artifact& art) const
    {
        return IsPartOfCombo(art.GetId());
    }


} /* namespace h3 */
