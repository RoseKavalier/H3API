//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3RMG/H3RmgMapItem.hpp"

namespace h3
{
    _H3API_ INT H3RmgMapItem::GetLand() const
	{
		return tile.landType;
	}
	_H3API_ INT H3RmgMapItem::GetLandSprite() const
	{
		return tile.landSprite;
	}
	_H3API_ INT H3RmgMapItem::GetRiver() const
	{
		return tile.riverType;
	}
	_H3API_ INT H3RmgMapItem::GetRiverSprite() const
	{
		return tile.riverSprite;
	}
	_H3API_ INT H3RmgMapItem::GetRoad() const
	{
		return tile.roadType;
	}
	_H3API_ INT H3RmgMapItem::GetRoadSprite() const
	{
		return tileData.roadSprite;
	}
} /* namespace h3 */
