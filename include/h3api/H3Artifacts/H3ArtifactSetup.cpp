//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-29              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Artifacts/H3ArtifactSetup.hpp"

namespace h3
{
	_H3API_ BOOL H3ArtifactSetup::IsPartOfCombo() const
	{
		return combinationArtifactId != eArtifact::NONE;
	}
} /* namespace h3 */
