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
#include "h3api/H3Constants/H3CstVictoryLoss.hpp"

namespace h3
{
	_H3API_DECLARE_(LossCondition);

#pragma pack(push, 4)

	struct H3LossCondition
	{
		_H3API_SIZE_(0x24);

		/** @brief [00]*/
		eLoss  type;
		/** @brief [04]*/
		INT32  loseTownX;
		/** @brief [08]*/
		INT32  loseTownY;
		/** @brief [0C]*/
		INT32  loseTownZ;
		/** @brief [10]*/
		INT32  loseHeroX;
		/** @brief [14]*/
		INT32  loseHeroY;
		/** @brief [18]*/
		INT32  loseHeroZ;
		/** @brief [1C]*/
		INT32  loseHeroId;
		/** @brief [20]*/
		UINT16 timeExpires;
		/** @brief [22]*/
		BOOL8  lossConditionReached;
		/** @brief [23]*/
		INT8   losingPlayerId;
	};
	_H3API_ASSERT_SIZE_(H3LossCondition);



#pragma pack(pop) /* align-4 */

} /* namespace h3 */
