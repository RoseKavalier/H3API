//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapTreasureChest.hpp"

namespace h3
{
	_H3API_ eArtifact H3MapitemTreasureChest::GetArtifact()
	{
		return eArtifact(artifactID);
	}
	_H3API_ INT32 H3MapitemTreasureChest::GetGold()
	{
		return 500 * bonus;
	}
	_H3API_ INT32 H3MapitemTreasureChest::GetExperience()
	{
		return GetGold() - 500;
	}
} /* namespace h3 */
