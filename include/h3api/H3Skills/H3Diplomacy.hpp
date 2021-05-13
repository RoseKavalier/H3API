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

namespace h3
{
	struct H3Hero;
	struct H3MapitemMonster;

	struct H3Diplomacy
	{
		enum eDiploType
		{
			NO_HERO   = -3,
			FLEE      = -2,
			FIGHT     = -1,
			JOIN_FREE = 0,
		};

		/**
		 * @brief Get factor based on ratio of hero to creature power
		 * http://heroescommunity.com/viewthread.php3?TID=28341
		 * @param k Power ratio between hero and creatures
		 * @return -3..+11
		*/
		_H3API_ static INT32 GetPowerFactor(FLOAT k);
		/**
		 * @brief Checks the gold cost of a would-be diplomacy joining wandering creature stack
		 * @param hero The current hero
		 * @param creature mapitem wandering creature
		 * @return The gold cost to hire creatures, or one of eDiploType options
		 */
		_H3API_ static INT32 DiplomacyJoinCost(H3Hero* hero, const H3MapitemMonster& creature);
	};
} /* namespace h3 */
