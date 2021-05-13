//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Creatures/H3Army.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemMine);
	_H3API_DECLARE_(Mine);
	struct H3Main;

#pragma pack(push, 4)

	// * the data for mines on the adventure map
	struct H3Mine
	{
		_H3API_SIZE_(0x40);
		/** @brief [0] -1 no owner*/
		INT8 owner;
		/** @brief [1] mine type. 0..6 resource, 7 abandonned*/
		INT8 type;
		/** @brief [02] whether the mine is of abandoned type*/
		BOOL8 abandoned;
		/** @brief [4] garrisoned army*/
		H3Army army;
		/** @brief [3C] */
		UINT8 x;
		/** @brief [3D] */
		UINT8 y;
		/** @brief [3E] */
		UINT8 z;

		_H3API_ BOOL IsAbandonned() const;
	};
	_H3API_ASSERT_SIZE_(H3Mine);

	/** @brief data for mine/lighthouse on adventure map*/
	struct H3MapitemMine
	{
		/** @brief [00] index of custom setup*/
		INT32 index;

		_H3API_ H3Mine* Get();
		_H3API_ H3Mine* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
