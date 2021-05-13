//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapSeerHut.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ WORD H3SeerHut::CreatureCount() const
	{
		return rewardValue2;
	}
	_H3API_ INT8 H3SeerHut::Luck() const
	{
		return INT8(rewardValue);
	}
	_H3API_ INT8 H3SeerHut::Morale() const
	{
		return INT8(rewardValue);
	}
	_H3API_ INT32 H3SeerHut::Primary() const
	{
		return rewardValue;
	}
	_H3API_ INT8 H3SeerHut::PrimaryCount() const
	{
		return INT8(rewardValue2);
	}
	_H3API_ H3SeerHut* H3MapitemSeerHut::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3SeerHut* H3MapitemSeerHut::Get(H3Main* main)
	{
		return &main->mainSetup.seerHuts[id];
	}
} /* namespace h3 */
