//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapGarrison.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3Garrison* H3MapitemGarrison::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Garrison* H3MapitemGarrison::Get(H3Main* main)
	{
		return &main->garrisons[index];
	}

} /* namespace h3 */
