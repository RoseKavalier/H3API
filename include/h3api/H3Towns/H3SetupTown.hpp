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
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Creatures/H3Army.hpp"

namespace h3
{
	_H3API_DECLARE_(SetupTown);

#pragma pack(push, 4)

	// * read data from h3m file
	struct H3SetupTown
	{
		_H3API_SIZE_(0x88);
		/** @brief [00] a unique value created in mapeditor*/
		UINT32     id;
		 /** @brief [04] */
		INT8       owner;
		/** @brief [05] */
		BOOL8      hasCustomBuildings;
		/** @brief [08] */
		H3Bitfield builtBuildings[2];
		/** @brief [10] */
		H3Bitfield disabledBuildings[2];

		/** @brief [18] */
		BOOL8      hasFort;
		/** @brief [19] */
		BOOL8      hasCustomGarrison;
		/** @brief [1C] */
		H3Army     garrison;
		/** @brief [54] */
		BOOL8      hasCustomName;
		/** @brief [58] */
		H3String   name;
		/** @brief [68] */
		INT32      type;
		/** @brief [6C] */
		INT8       creatureFormation;
		/** @brief [70] */
		H3Bitfield possibleSpell[3];
		/** @brief [7C] */
		H3Bitfield forcedSpells[3];
	};
	_H3API_ASSERT_SIZE_(H3SetupTown);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
