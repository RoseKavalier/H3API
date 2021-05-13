//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapWagon.hpp"

namespace h3
{
	_H3API_ H3PlayersBitfield H3MapitemWagon::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemWagon::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
	_H3API_ eArtifact H3MapitemWagon::GetArtifact()
	{
		return eArtifact(artifactID);
	}
	_H3API_ eResource H3MapitemWagon::GetResourceType()
	{
		return eResource(resType);
	}
	_H3API_ INT32 H3MapitemWagon::GetResourceAmount()
	{
		return resValue;
	}
} /* namespace h3 */
