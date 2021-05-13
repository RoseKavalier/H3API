//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GameData/H3MainSetup.hpp"
#include "h3api/H3AdventureMap/H3Mapitems.hpp"
#include "h3api/H3AdventureMap/H3ObjectAttributes.hpp"

namespace h3
{
	_H3API_ H3MapItem* H3MainSetup::GetMapItem(INT32 x, INT32 y, INT32 z)
	{
		return THISCALL_4(H3MapItem*, 0x4086D0, this, x, y, z);
	}

	_H3API_ VOID H3MainSetup::DrawItem(H3MapItem* mitem, H3ObjectDraw* draw)
	{
		THISCALL_3(VOID, 0x505880, this, mitem, draw);
	}

	_H3API_ VOID H3MainSetup::AddObjectAttribute(H3ObjectAttributes* oa)
	{
		H3Vector<H3ObjectAttributes>* list = &objectLists[oa->type];
		THISCALL_4(VOID, 0x4D15F0, list, list->end(), 1, oa);
	}

	_H3API_ H3Point H3MainSetup::GetCoordinates(H3MapItem* item)
	{
		H3Point coordinates;
		UINT delta    = item - mapitems;
		coordinates.x = delta % mapSize;
		delta        /= mapSize;
		coordinates.y = delta % mapSize;
		coordinates.z = delta / mapSize;
		return coordinates;
	}

	_H3API_ H3Map<H3MapItem> H3MainSetup::GetMap()
	{
		return H3Map<H3MapItem>(mapitems, static_cast<UINT>(mapSize), hasUnderground);
	}

	_H3API_ H3FastMap<H3MapItem> H3MainSetup::GetFastMap()
	{
		return H3FastMap<H3MapItem>(mapitems, static_cast<UINT>(mapSize), hasUnderground);
	}
} /* namespace h3 */
