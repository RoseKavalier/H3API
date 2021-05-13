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

#pragma pack(push, 4)

	struct H3RmgParameters
	{
		_H3API_SIZE_(0x50);
		BOOL8  isHuman[8];      /**< @brief [00]*/
		INT32  townId[8];       /**< @brief [08]*/
		INT32  width;           /**< @brief [28]*/
		INT32  height;          /**< @brief [2C]*/
		BOOL32 hasUnderground;  /**< @brief [30]*/
		INT32  humanCount;      /**< @brief [34]*/
		INT32  humanTeams;      /**< @brief [38]*/
		INT32  computerCount;   /**< @brief [3C]*/
		INT32  computerTeams;   /**< @brief [40]*/
		INT32  waterAmount;     /**< @brief [44]*/
		INT32  monsterStrength; /**< @brief [48]*/
		INT32  gameVersion;     /**< @brief [4C]*/

		_H3API_ VOID Validate();
	};
	_H3API_ASSERT_SIZE_(H3RmgParameters);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
