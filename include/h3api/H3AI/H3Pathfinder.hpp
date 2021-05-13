//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(Pathfinder);
	/* previously called MovementMgr, however not a manager. Renamed Pathfinder */
	typedef H3Pathfinder H3MovementMgr;
	struct H3PathNode;

#pragma pack(push, 4)
	/**
	 * @brief Used by AI to determine where to go on adv map and in combat
	 * Also used to set accessible combat/map tiles for humans
	 */
	struct H3Pathfinder
	{
		_H3API_SIZE_(0x70);
		_H3API_GET_INFO_(0x6992D4, H3Pathfinder);
	protected:
		/** @brief [0] */
		h3unk8 _f_00[8];
	public:
		/** @brief [8] */
		INT32 availableMovement;
		/** @brief [C] */
		INT32 maxLandMovement;
		/** @brief [10] see 0x56B768*/
		INT32 maxWaterMovement;
		h3unk8 _f_14;
		/** @brief [15] can hero cast Dimension Door?*/
		BOOL8 ddAccess;
		/** @brief [16] can hero cast fly?*/
		BOOL8 flyAccess;
		/** @brief [17] can cast waterwalk?*/
		BOOL8 waterwalkAccess;
		/** @brief [18] level of waterwalk if cast*/
		INT32 waterwalkLevel;
		/** @brief [1C] level of fly if cast*/
		INT32 flyLevel;
	protected:
		h3unk8 _f_20[4];
	public:
		/** @brief [24] an array of path nodes*/
		union
		{
			H3PathNode* movementInfo;
			H3PathNode* pathNodes;
		};
	protected:
		h3unk8 _f_28[8];
	public:
		/** @brief [30] map width*/
		INT32 mapX;
		/** @brief [34] map height*/
		INT32 mapY;
	protected:
		H3Vector<h3unk8[30]> _f_38;
	public:
		/** @brief [48] H3Position of path to take*/
		H3Vector<H3Position> arrowPath;
	protected:
		/** @brief [58] vector of size 4 items */
		H3Vector<h3unk32> _f_58;
	public:
		/** @brief [68] */
		struct BattleHexes
		{
			h3unk32 hexes[187];
		}*battleHexes;
		/** @brief [6C] [x][y][z] array*/
		UINT* aiData;

		// * returns reference to H3TileMovement at position
		_H3API_ H3PathNode*           GetMovementInfo(UINT32 mixed_position);
		_H3API_ H3PathNode*           GetPathNode(UINT32 mixed_position);
		_H3API_ H3PathNode*           GetPathNode(const H3Position& position);
		_H3API_ H3PathNode*           GetPathNode(const H3Point& pt);
		_H3API_ H3Map<H3PathNode>     GetMap();
		_H3API_ H3FastMap<H3PathNode> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3Pathfinder);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
