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
	_H3API_DECLARE_(VictoryCondition);

#pragma pack(push, 4)


	struct H3VictoryCondition
	{
		_H3API_SIZE_(0x4C);

		/** @brief [00]*/
		eVictory type;
		/** @brief [01]*/
		BOOL8 allowDefeatAll;
		/** @brief [02]*/
		BOOL8 appliesToComputer;
		/** @brief [04]*/
		INT32 artifactId;
		/** @brief [08]*/
		INT32 accumulateCreaturesType;
		/** @brief [0C]*/
		INT32 accumulateCreaturesAmount;
		/** @brief [010]*/
		INT32 accumulateResource;
		/** @brief [014]*/
		INT32 accumulateResourceAmount;
		/** @brief [018]*/
		INT32 townX;
		/** @brief [01C]*/
		INT32 townY;
		/** @brief [020]*/
		INT32 townZ;
		/** @brief [024]*/
		INT8  villageHallLevel;
		/** @brief [025]*/
		INT8  buildFortLevel;
		/** @brief [028]*/
		INT32 defeatHeroX;
		/** @brief [02C]*/
		INT32 defeatHeroY;
		/** @brief [030]*/
		INT32 defeatHeroZ;
		/** @brief [034]*/
		INT32 defeatHeroId;
		/** @brief [038]*/
		INT32 defeatMonsterX;
		/** @brief [03C]*/
		INT32 defeatMonsterY;
		/** @brief [040]*/
		INT32 defeatMonsterZ;
		/** @brief [044] harcoded for Foolhardy Waywardness*/
		INT32 daysToSurvive;
		/** @brief [048]*/
		BOOL8 winConditionReached;
		/** @brief [049]*/
		INT8  winningPlayerId;
	};
	_H3API_ASSERT_SIZE_(H3VictoryCondition);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
