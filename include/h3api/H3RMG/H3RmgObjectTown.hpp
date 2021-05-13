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
#include "h3api/H3RMG/H3RmgObject.hpp"

namespace h3
{

#pragma pack(push, 4)

	struct H3RmgObjectTown : public H3RmgObject
	{
		_H3API_SIZE_(0x28);
		INT32 indexOnMap; /**< @brief [1C]*/
		INT32 owner;      /**< @brief [20]*/
		BOOL8 hasFort;    /**< @brief [24]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectTown);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
