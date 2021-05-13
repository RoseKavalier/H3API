//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapPandorasBox.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3PandorasBox* H3MapitemPandorasBox::Get()
	{
		return Get(H3Main::Get());
	}

	_H3API_ H3PandorasBox* H3MapitemPandorasBox::Get(H3Main* main)
	{
		return &main->mainSetup.pandoraEvents[id];
	}
} /* namespace h3 */
