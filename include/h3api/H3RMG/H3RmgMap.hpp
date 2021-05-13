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

namespace h3
{
    struct H3RmgMapItem;

#pragma pack(push, 4)

	/** @brief original name: type_random_map*/
	struct H3RmgMap
	{
		_H3API_SIZE_(0x18);
		h3func*      mapitemsVTable; /**< @brief [00]*/
		UINT8        mapItemsRef;    /**< @brief [04] probably auto_ptr<RMG_MapItem>*/
		H3RmgMapItem* mapItems;       /**< @brief [08]*/
		INT32        mapWidth;       /**< @brief [0C]*/
		INT32        mapHeight;      /**< @brief [10]*/
		INT32        numberLevels;   /**< @brief [14] 1..2*/

		_H3API_ H3RmgMapItem* GetMapItem(INT x, INT y, INT z);
		_H3API_ H3RmgMapItem* GetMapItem(const H3Point& coordinates);
		_H3API_ H3RmgMapItem* begin();
		_H3API_ H3RmgMapItem* end();
		_H3API_ H3Point GetCoordinates(H3RmgMapItem* item);
		_H3API_ H3Map<H3RmgMapItem>     GetMap();
		_H3API_ H3FastMap<H3RmgMapItem> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3RmgMap);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
