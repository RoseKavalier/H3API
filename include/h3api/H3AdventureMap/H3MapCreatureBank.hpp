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
#include "h3api/H3Creatures/H3Army.hpp"
#include "h3api/H3GameData/H3Resources.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Constants/H3CstObjects.hpp"

namespace h3
{
	_H3API_DECLARE_(CreatureBank);
	_H3API_DECLARE_(CreatureBankState);
	_H3API_DECLARE_(CreatureBankSetup);
	_H3API_DECLARE_(MapitemCreatureBank);
	struct H3Main;

#pragma pack(push, 4)

	// * data for creature banks
	struct H3CreatureBank
	{
		_H3API_SIZE_(0x6C);
		/** @brief [0] */
		// * creatures guarding this bank
		H3Army guardians;
		/** @brief [38] */
		// * resource rewards for defeating this bank
		H3Resources resources;
		/** @brief [54] */
		// * the type of creature rewarded for defeating this bank
		INT32 creatureRewardType;
		/** @brief [58] */
		// * the number of creatures rewarded for defeating this bank
		INT8 creatureRewardCount;
		/** @brief [5C] */
		// *a list of artifact IDs gained for defeating this bank
		H3Vector<INT32> artifacts;

		_H3API_ BOOL HasUpgradedStack();
		_H3API_ VOID SetupBank(INT32 type, INT32 level);
		_H3API_ VOID UpgradeStack(BOOL upg);
	};
	_H3API_ASSERT_SIZE_(H3CreatureBank);

	// * CRBanks.txt converted in memory, single bank state
	struct H3CreatureBankState
	{
		_H3API_SIZE_(0x60);
		/** @brief [0] */
		// * creatures guarding this bank
		H3Army guardians;
		/** @brief [38] */
		// * resource rewards for defeating this bank
		H3Resources resources;
		/** @brief [54] */
		// * the type of creature rewarded for defeating this bank
		INT32 creatureRewardType;
		/** @brief [58] */
		// * the number of creatures rewarded for defeating this bank
		INT8 creatureRewardCount;
		/** @brief [59] */
		// * the odds (out of 100) for this size to be spawned
		INT8 chance;
		/** @brief [5A] */
		// * the odds (out of 100) to have an upgraded stack
		INT8 upgrade;
		/** @brief [5B] */
		// * the amount of treasure, minor, major, relic artifacts
		INT8 artifactTypeCounts[4];
	};
	_H3API_ASSERT_SIZE_(H3CreatureBankState);

	// * CRBanks.txt converted in memory, overall bank state
	struct H3CreatureBankSetup
	{
		_H3API_GET_INFO_(0x47A3C1 + 1, H3CreatureBankSetup);

		H3String name;
		H3CreatureBankState states[4];
	};

	/** @brief data for creature banks on adventure map*/
	struct H3MapitemCreatureBank
	{
		/** @brief [00]*/
		unsigned _u1      : 5;
		/** @brief [05] which players have come by*/
		unsigned  visited : 8;
		/** @brief [13] 0..4095 Creature Bank setup index*/
		unsigned  id      : 12;
		/** @brief [25] whether the bank was cleared*/
		unsigned  taken   : 1;
		/** @brief [26]*/
		unsigned _u2      : 6;

		_H3API_ H3CreatureBank* Get();
		_H3API_ H3CreatureBank* Get(H3Main* main);
		_H3API_ H3PlayersBitfield GetVisiters();
		_H3API_ VOID SetVisited(const H3PlayersBitfield& players);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
