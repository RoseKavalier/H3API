//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(SimulatedHero);
	typedef H3SimulatedHero H3AICombatInfo;

#pragma pack(push, 4)

	struct H3SimulatedHero
	{
		_H3API_SIZE_(0x28);
		/** @brief [0] */
		INT heroAttack;
		/** @brief [4] */
		INT heroDefence;
	protected:
		h3unk8 _f_08[4];
	public:
		/** @brief [C] */
		INT damage[4];
		/** @brief [1C] */
		INT moveType;
		/** @brief [20] */
		INT thisSide;
		/** @brief [24] */
		INT enemySide;
	};
	_H3API_ASSERT_SIZE_(H3SimulatedHero);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
