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
    struct H3RmgRandomMapGenerator;

#pragma pack(push, 4)

	struct H3RmgMapInfo
	{
		_H3API_SIZE_(0x18);
		h3func*      vTable;         /**< @brief [00]*/
		BOOL8        hasMap;         /**< @brief [04] possibly auto_ptr*/
		H3RmgMapItem* undergroundMap; /**< @brief [08]*/
		INT32        width;          /**< @brief [0C]*/
		INT32        height;         /**< @brief [10]*/
		BOOL32       underground;    /**< @brief [14]*/
	public:
		_H3API_ H3RmgMapInfo(H3RmgRandomMapGenerator* main, BOOL underground = TRUE);
		_H3API_ ~H3RmgMapInfo();
	};
	_H3API_ASSERT_SIZE_(H3RmgMapInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
