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
#include "h3api/H3GameData/H3Resources.hpp"
#include "h3api/H3Constants/H3CstCreatures.hpp"

namespace h3
{
	_H3API_DECLARE_(MapitemMonster);
	_H3API_DECLARE_(Monster);
	struct H3Main;
	struct H3Hero;

#pragma pack(push, 4)
	/** @brief if a wandering monster has a custom setup, this is the referenced data*/
	struct H3Monster
	{
		_H3API_SIZE_(0x30);
		/** @brief [0] */
		H3String message;
		/** @brief [10] */
		H3Resources resources;
		/** @brief [2C] */
		INT32 artifact;
	};
	_H3API_ASSERT_SIZE_(H3Monster);

	/** @brief data for wandering monsters on adventure map*/
	struct H3MapitemMonster
	{
		/** @brief [00] max 4095 creatures*/
		unsigned  count : 12;
		/** @brief [12] for diplomacy*/
		signed  aggression : 5;
		/** @brief [17] monsters cannot run option*/
		unsigned  noRun : 1;
		/** @brief [18] monsters cannot grow option*/
		unsigned  noGrowth : 1;
		/** @brief [19] up to 256 individual messages/prizes*/
		unsigned  setupIndex : 8;
		/** @brief [27] remainder of the division by 10 for growth*/
		unsigned  growthRemainder : 4;
		/** @brief [31] monster has a custom setup*/
		unsigned  hasSetup : 1;

		_H3API_ H3Monster* Get() const;
		_H3API_ H3Monster* Get(H3Main* main) const;
		_H3API_ INT32 CreatureType() const;
		_H3API_ INT32 DiploJoinCost(H3Hero* hero) const;
	};
	/** @brief data for wandering monsters on adventure map, as of SoD_SP 1.18*/
	struct SODSP_MapMonster
	{
		/** @brief [00] max 4095 creatures*/
		unsigned  count : 12;
		/** @brief [12] for diplomacy*/
		signed  aggression : 5;
		/** @brief [17] monsters cannot run option*/
		unsigned  noRun : 1;
		/** @brief [18] monsters cannot grow option*/
		unsigned  noGrowth : 1;
		/**
		 * @brief [19] up to 4096 individual messages/prizes
		 * Extra growth is handled using the same game logic, just not stored
		 */
		unsigned  setupIndex : 12;
		/** @brief [31] monster has a custom setup*/
		unsigned  hasSetup : 1;

		_H3API_ H3Monster* Get();
		_H3API_ H3Monster* Get(H3Main* main);
		_H3API_ INT32 CreatureType();
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
