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

	struct H3RmgObjectSeer : public H3RmgObject
	{
		_H3API_SIZE_(0x34);
		INT32 artifactId;           /**< @brief [1C]*/
		INT32 experienceAmount;     /**< @brief [20]*/
		INT32 resourceId;           /**< @brief [24]*/
		INT32 resourceAmount;       /**< @brief [28]*/
		INT32 creatureRewardType;   /**< @brief [2C]*/
		INT32 creatureRewardNumber; /**< @brief [30]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgObjectSeer);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
