//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AI/H3PathNode.hpp"
#include "h3api/H3Managers/H3AdventureManager.hpp"
#include "h3api/H3AdventureMap/H3TileVision.hpp"

namespace h3
{
    _H3API_ UINT8 H3PathNode::GetX() const
	{
		return mixedPosition.GetX();
	}
	_H3API_ UINT8 H3PathNode::GetY() const
	{
		return mixedPosition.GetY();
	}
	_H3API_ UINT8 H3PathNode::GetZ() const
	{
		return mixedPosition.GetZ();
	}
	_H3API_ BOOL H3PathNode::ZoneControlled() const
	{
        return H3TileVision::GetTile(mixedPosition).zoneControl;
	}
	_H3API_ H3MapItem* H3PathNode::GetMapItem() const
	{
		return H3AdventureManager::Get()->GetMapItem(mixedPosition);
	}
} /* namespace h3 */
