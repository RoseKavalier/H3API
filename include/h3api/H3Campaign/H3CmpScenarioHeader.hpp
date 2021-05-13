//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-11              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Containers/H3Bitset.hpp"

namespace h3
{
	_H3API_DECLARE_(CmpScenarioHeader);
	struct H3CmpPrologue;
	union  H3CmpStartBoni;

#pragma pack(push, 4)

	struct H3CmpScenarioHeader
	{
		_H3API_SIZE_(0xA8);
		/** @brief [00] *.h3m */
		H3String          mapName;
		/** @brief [10] used by Streambuf::seekoff*/
		h3unk32           offset;
		/** @brief [14] packed size of map*/
		INT32             deflatedDataSize;
		/** @brief [18] scenarios that have to be completed first*/
		H3Vector<BOOL8>   requirements;
		/** @brief [28]*/
		H3String          description;
		/** @brief [38]*/
		INT8              color;
		/** @brief [39]*/
		INT8              difficulty;
		/** @brief [3C]*/
		H3CmpPrologue*    prologue;
		/** @brief [40]*/
		H3CmpPrologue*    epilogue;
		/** @brief [44]*/
		BOOL8             keepExperience;
		/** @brief [45]*/
		BOOL8             keepPrimarySkills;
		/** @brief [46]*/
		BOOL8             keepSecondarySkills;
		/** @brief [47]*/
		BOOL8             keepSpells;
		/** @brief [48]*/
		BOOL8             keepArtifacts;
		/** @brief [4C] H3PlayerAttributes::powerPlaceholder*/
		h3unk32           powerPlaceholder[8];
		/** @brief [6C] from H3MapInfo::_f_20 mb crossover hero ids*/
		H3Vector<INT32>   heroIds;
		/** @brief [7C] crossover creatures*/
		H3CreaturesBitset creatures;
		/** @brief [90] crossover artifacts*/
		H3ArtifactBitset  artifacts;
		/** @brief [A4]*/
		H3CmpStartBoni*   startingOptions;
	};
	_H3API_ASSERT_SIZE_(H3CmpScenarioHeader);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
