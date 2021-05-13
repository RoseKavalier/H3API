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
	_H3API_DECLARE_(CombatSquare);
	struct H3CombatCreature;

#pragma pack(push, 4)

	/** @brief data for a single battlefield cell */
	struct H3CombatSquare
	{
		_H3API_SIZE_(0x70);
		/** @brief [0] */
		// * pixel position on screen
		INT16 x;
		/** @brief [2] */
		// * pixel position on screen
		INT16 y;
		/** @brief [4] */
		// * pixel position on screen
		INT16 left;
		/** @brief [6] */
		// * pixel position on screen
		INT16 top;
		/** @brief [8] */
		// * pixel position on screen
		INT16 right;
		/** @brief [A] */
		// * pixel position on screen
		INT16 bottom;
	protected: h3unk8 _f_0C[4]; public:
		/** @brief [10] */
		union
		{
			UINT8 obstacleBits;
			struct
			{
				BOOL8 anchor        : 1; // 1
				BOOL8 localObstacle : 1; // 2
				BOOL8 quicksand     : 1; // 4
				BOOL8 landMine      : 1; // 8
				BOOL8 firewall      : 1; // 10
				BOOL8 forcefield    : 1; // 20 (also sets localObstacle -> 22)
				BOOL8 unused        : 2; // 40-80
				// another 24 unused bits
			};
		};
		/** @brief [14] */
		INT32 obstacleIndex;
		/** @brief [18] */
		// * the side of stack on this square
		INT8 stackSide;
		/** @brief [19] */
		// * the index of stack on this square
		INT8 stackIndex;
		/** @brief [1A] */
		// * true if a wide creature is here
		BOOL8 twoHexMonsterSquare;
		/** @brief [1C] */
		INT32 deadStacksNumber;
		/** @brief [20] */
		INT8 deadStackSide[14];
		/** @brief [2E] */
		INT8 deadStackIndex[14];
		/**
		 * @brief [3C]
		 * used to check the second square in the direction faced by the creature
		 * 0..defender is owner, 1..attacker is owner
		 */
		BOOL8 belongsToAttacker[14];
		/** @brief [4A] */
		BOOL8 availableForLeftSquare;
		/** @brief [4B] */
		BOOL8 availableForRightSquare;
	protected:
		h3unk8 _f_4C[32];
		h3unk8 _f_6C[4];
	public:

		_H3API_ H3CombatCreature* GetMonster();
		_H3API_ H3CombatCreature* GetCreature();
	};
	_H3API_ASSERT_SIZE_(H3CombatSquare);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
