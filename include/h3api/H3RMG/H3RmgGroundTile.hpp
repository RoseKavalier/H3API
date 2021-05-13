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

	struct H3RmgGroundTile
	{
		_H3API_SIZE_(4);
		unsigned  landType    : 5; /**< @brief [00]*/
		unsigned _b6          : 1; /**< @brief [05]*/
		unsigned  landSprite  : 7; /**< @brief [06]*/
		unsigned _b14         : 1; /**< @brief [13]*/
		unsigned  riverType   : 3; /**< @brief [14]*/
		unsigned _b18         : 1; /**< @brief [17]*/
		unsigned  riverSprite : 7; /**< @brief [18]*/
		unsigned _b26         : 1; /**< @brief [25]*/
		unsigned  roadType    : 3; /**< @brief [26]*/
		unsigned _b30         : 3; /**< @brief [29]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgGroundTile);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
