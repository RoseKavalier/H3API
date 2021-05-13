//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapScroll.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3MapArtifact* H3MapitemScroll::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3MapArtifact* H3MapitemScroll::Get(H3Main* main)
	{
		return hasSetup ? &main->mainSetup.artifactResource[id] : nullptr;
	}
} /* namespace h3 */
