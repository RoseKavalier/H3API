//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapItems.hpp"
#include "h3api/H3Heroes/H3Hero.hpp"
#include "h3api/H3GameData/H3Main.hpp"


namespace h3
{
	_H3API_ H3ObjectDraw::H3ObjectDraw(UINT16 sprite, UINT8 tile_id, UINT8 layer) :
		sprite(sprite),
		tileID(tile_id),
		layer(layer)
	{
	}
	_H3API_ H3University* H3MapItem::GetUniversity()
	{
		return STDCALL_1(H3University*, 0x405DA0, this);
	}
	_H3API_ H3MapItem* H3MapItem::GetEntrance()
	{
		return THISCALL_1(H3MapItem*, 0x4FD0F0, this);
	}
	_H3API_ BOOL H3MapItem::IsEntrance() const
	{
		return access & 0x10;
	}
	_H3API_ BOOL H3MapItem::IsBlocked() const
	{
		return access & 0x01;
	}
	_H3API_ BOOL H3MapItem::CanDig() const
	{
		return access & 0x40;
	}
	_H3API_ INT H3MapItem::GetRealType() const
	{
		if (objectType != eObject::HERO)
			return objectType;
		H3Hero* hero = H3Main::Get()->GetHero(setup);
		if (!hero || !hero->objectBelow)
			return objectType;
		return hero->objectTypeUnder;
	}
	_H3API_ UINT H3MapItem::GetRealSetup() const
	{
		if (objectType != eObject::HERO)
			return setup;
		H3Hero* hero = H3Main::Get()->GetHero(setup);
		if (!hero || !hero->objectBelow)
			return setup;
		return hero->objectBelowSetup;
	}
	_H3API_ H3Point H3MapItem::GetCoordinates() const
	{
		H3MainSetup& setup = H3Main::Get()->mainSetup;
		return ReverseCoordinates(this, setup.mapitems, static_cast<UINT32>(setup.mapSize));
	}
}

