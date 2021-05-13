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
	_H3API_DECLARE_(MapitemGarrison);
	_H3API_DECLARE_(Garrison);
	struct H3Main;

#pragma pack(push, 4)

	/** @brief garrison data on adventure map*/
	struct H3Garrison
	{
		_H3API_SIZE_(0x40);
		/** @brief [0] */
		INT8 owner;
		/** @brief [4] */
		H3Army army;
		/** @brief [3C] */
		BOOL8 canRemoveCreatures;
		/** @brief [3D] */
		UINT8 x;
		/** @brief [3E] */
		UINT8 y;
		/** @brief [3F] */
		UINT8 z;
	};
	_H3API_ASSERT_SIZE_(H3Garrison);

	struct H3MapitemGarrison
	{
		UINT32 index;

		_H3API_ H3Garrison* Get();
		_H3API_ H3Garrison* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
