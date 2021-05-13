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
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(SimulatedCombat);
	typedef H3SimulatedCombat H3AiFastBattle;
	struct H3SimulatedCreature;
	struct H3Hero;
	struct H3Army;

#pragma pack(push, 4)

	/** @brief Represents 1 side of AI vs AI fast battles */
	struct H3SimulatedCombat
	{
		_H3API_SIZE_(0x34);
		/** @brief [00]*/
		H3Vector<H3SimulatedCreature> creatures;
		/** @brief [10]*/
		INT32 specialTerrain;
		/** @brief [14]*/
		INT32 spellPoints;
		/** @brief [18]*/
		BOOL8 canCastSpells;
		/** @brief [1C]*/
		INT32 armyStrength;
		/** @brief [20]*/
		INT8 tactics;
		/** @brief [24]*/
		H3Hero* hero;
		/** @brief [28]*/
		H3Army* army;
		/** @brief [2C]*/
		H3Hero* opponent;
		/** @brief [30]*/
		BOOL8 turrets;
		/** @brief [32]*/
		INT16 turretsLevel;

		_H3API_ VOID DeleteCreatures();
	};
	_H3API_ASSERT_SIZE_(H3SimulatedCombat);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
