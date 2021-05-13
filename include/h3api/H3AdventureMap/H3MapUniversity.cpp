//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapUniversity.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ H3University* H3MapitemUniversity::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3University* H3MapitemUniversity::Get(H3Main* main)
	{
		return &main->universities[id];
	}
	_H3API_ PINT H3University::begin()
	{
		return &sSkill[0];
	}
	_H3API_ PINT H3University::end()
	{
		return &sSkill[4];
	}
	_H3API_ H3PlayersBitfield H3MapitemUniversity::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemUniversity::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */
