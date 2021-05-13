//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapMonster.hpp"
#include "h3api/H3GameData/H3Main.hpp"
#include "h3api/H3AdventureMap/H3MapItems.hpp"
#include "h3api/H3Skills/H3Diplomacy.hpp"
#include "h3api/H3Creatures/H3CreatureInformation.hpp"
#include "h3api/H3Creatures/H3Creature.hpp"

namespace h3
{
	_H3API_ H3Monster* H3MapitemMonster::Get() const
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Monster* H3MapitemMonster::Get(H3Main* main) const
	{
		return hasSetup ? &main->mainSetup.monsters[setupIndex] : nullptr;
	}
	_H3API_ INT32 H3MapitemMonster::CreatureType() const
	{
		return reinterpret_cast<H3MapItem*>(const_cast<H3MapitemMonster*>(this))->objectSubtype;
	}
	_H3API_ INT32 H3MapitemMonster::DiploJoinCost(H3Hero* hero) const
	{
		return H3Diplomacy::DiplomacyJoinCost(hero, *this);
	}
	_H3API_ H3Monster* SODSP_MapMonster::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3Monster* SODSP_MapMonster::Get(H3Main* main)
	{
		return hasSetup ? &main->mainSetup.monsters[setupIndex] : nullptr;
	}
	_H3API_ INT32 SODSP_MapMonster::CreatureType()
	{
		return reinterpret_cast<H3MapItem*>(this)->objectSubtype;
	}
} /* namespace h3 */
