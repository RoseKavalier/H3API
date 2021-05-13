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
#include "h3api/H3Skills/H3PrimarySkills.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Creatures/H3Army.hpp"
#include "h3api/H3GameData/H3Resources.hpp"

namespace h3
{
	_H3API_DECLARE_(PandorasBox);
	_H3API_DECLARE_(MapitemPandorasBox);
	struct H3Main;
	struct H3SecondarySkill;

#pragma pack(push, 4)

	struct H3PandorasBox
	{
		_H3API_SIZE_(0xE4);
		/** @brief [0] */
		H3String message;
		/** @brief [10] */
		BOOL8 customizedGuards;
		/** @brief [14] */
		H3Army guardians;
		/** @brief [4C] */
		BOOL8 hasMessageOrGuardians;
		/** @brief [50] */
		INT32 experience;
		/** @brief [54] */
		INT32 spellPoints;
		/** @brief [58] */
		INT8 morale;
		/** @brief [59] */
		INT8 luck;
		/** @brief [5C] */
		H3Resources resources;
		/** @brief [78] */
		H3PrimarySkills pSkill;
		/** @brief [7C] */
		H3Vector<H3SecondarySkill> sSkills;
		/** @brief [8C] */
		H3Vector<INT32> artifacts;
		/** @brief [9C] */
		H3Vector<INT32> spells;
		/** @brief [AC] */
		H3Army creatureReward;
	};
	_H3API_ASSERT_SIZE_(H3PandorasBox);

	/** @brief data for pandora's boxes on adventure map*/
	struct H3MapitemPandorasBox
	{
		unsigned id : 10;

		_H3API_ H3PandorasBox* Get();
		_H3API_ H3PandorasBox* Get(H3Main* main);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
