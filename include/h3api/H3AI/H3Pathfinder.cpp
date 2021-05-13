//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AI/H3Pathfinder.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
    _H3API_ H3PathNode* H3Pathfinder::GetMovementInfo(UINT32 mixed_position)
	{
        return GetPathNode(mixed_position);
	}
    _H3API_ H3PathNode* H3Pathfinder::GetPathNode(UINT32 mixed_position)
    {
        // last value seems to be z-related and is always 0?
        return THISCALL_3(H3PathNode*, 0x42ECC0, this, mixed_position, 0);
    }
    _H3API_ H3PathNode* H3Pathfinder::GetPathNode(const H3Position& position)
    {
        return GetPathNode(position.Mixed());
    }
    _H3API_ H3PathNode* H3Pathfinder::GetPathNode(const H3Point& pt)
    {
        return GetPathNode(pt.Pack());
    }
	_H3API_ H3Map<H3PathNode> H3Pathfinder::GetMap()
	{
		return H3Map<H3PathNode>(pathNodes, H3MapSize::Get(), H3Main::Get()->HasUnderground());
	}
	_H3API_ H3FastMap<H3PathNode> H3Pathfinder::GetFastMap()
	{
		return H3FastMap<H3PathNode>(pathNodes, H3MapSize::Get(), H3Main::Get()->HasUnderground());
	}
} /* namespace h3 */
