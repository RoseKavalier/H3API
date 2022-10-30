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
#include "h3api/H3Constants/H3CstCombat.hpp"

namespace h3
{
	_H3API_DECLARE_(CreatureAnimation);
	typedef H3CreatureAnimation H3MonsterAnimation;

#pragma pack(push, 4)

	/** @brief data read from cranim.txt*/
	struct H3CreatureAnimation
	{
		_H3API_SIZE_(0x54);
		_H3API_GET_INFO_(0x699930, H3CreatureAnimation);

		struct H3MissileOffets
		{
			INT16 offset_x;
			INT16 offset_y;
		}missiles[3];
		INT32 missileFrameAngles[12]; // from high to low (90 to -90)
		INT32 troopCountLocationOffset;
		INT32 attackClimaxFrame;
		INT32 timeBetweenFidgets;
		INT32 walkAnimationTime;
		INT32 attackAnimationTime;
		INT32 flightAnimationTime;
	};
	_H3API_ASSERT_SIZE_(H3CreatureAnimation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
