//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3RMG/H3RmgGroundTile.hpp"
#include "h3api/H3RMG/H3RmgGroundTileData.hpp"
#include "h3api/H3RMG/H3RmgMovementCost.hpp"
#include "h3api/H3RMG/H3RmgZoneData.hpp"

namespace h3
{
	struct H3RmgObject;
	typedef H3Point RMG_Coordinates;


#pragma pack(push, 4)

	struct H3RmgMapItem
	{
		_H3API_SIZE_(0x30);
		H3Vector<H3RmgObject*> objects;      /**< @brief [00]*/
		RMG_Coordinates       previousTile;	/**< @brief [10]*/
		H3RmgMovementCost      movement;     /**< @brief [1C]*/
		/**
		 * @brief [20] 1st byte ? neighbor zone ?  ? distance to yellow item?
		 * 2nd byte ?
		 * 3rd byte zone id?
		 * 4th byte 2nd zone id?
		 */
		H3RmgZoneData          zone;
		H3RmgGroundTile        tile;         /**< @brief [24]*/
		H3RmgGroundTileData    tileData;     /**< @brief [28]*/
		h3unk32               _f_2C;        /**< @brief [2C]*/

		_H3API_ INT GetLand() const;
		_H3API_ INT GetLandSprite() const;
		_H3API_ INT GetRiver() const;
		_H3API_ INT GetRiverSprite() const;
		_H3API_ INT GetRoad() const;
		_H3API_ INT GetRoadSprite() const;
	};
	_H3API_ASSERT_SIZE_(H3RmgMapItem);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
