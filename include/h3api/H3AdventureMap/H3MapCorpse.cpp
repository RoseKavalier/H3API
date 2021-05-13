//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapCorpse.hpp"

namespace h3
{
	_H3API_ eArtifact H3MapitemCorpse::GetArtifact()
	{
		return eArtifact(artifactID);
	}
} /* namespace h3 */
