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
#include "h3api/H3Players/H3PlayerAttributes.hpp"
#include "h3api/H3Containers/H3Set.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3GameData/H3LossCondition.hpp"
#include "h3api/H3GameData/H3VictoryCondition.hpp"

namespace h3
{
	_H3API_DECLARE_(MapInfo);
	struct H3MapHeroInfo;

#pragma pack(push, 4)

	struct H3MapInfo
	{
		_H3API_SIZE_(0x304);
		INT32                mapVersion;                    /** @brief [000]*/
		BOOL8                hasPlayers;                    /** @brief [004]*/
		INT8                 mapDifficulty;                 /** @brief [005]*/
		INT8                 computerPlayableCount;         /** @brief [006]*/
		INT8                 humanOnlyCount;                /** @brief [007]*/
		h3unk8                humanOnly_8;                   /** @brief [008] unsure what distinction is with [007]*/
	protected:
		h3unk8                _f_9;
		h3unk8                _f_A;
	public:
		INT8                 maxHeroLevel;                  /** @brief [00B]*/
		BOOL8                hasTeams;                      /** @brief [00C]*/
		INT8                 playerTeam[8];                 /** @brief [00D]*/
		INT32                mapDimension;                  /** @brief [018]*/
		BOOL8                hasUnderground;                /** @brief [01C]*/
	protected:
		H3Vector<h3unk8>      _f_20; // seems to be an unused feature
	public:
		H3VictoryCondition   victory;                       /** @brief [030]*/
		H3LossCondition      loss;                          /** @brief [07C]*/
		H3PlayerAttributes   playerAttributes[8];           /** @brief [0A0]*/
		H3Set<H3MapHeroInfo> playerHeroes;                  /** @brief [2C0]*/
		H3String             mapName;                       /** @brief [2D0]*/
		H3String             mapDescription;                /** @brief [2E0]*/
		H3Bitfield           expansionHeroes[5];            /** @brief [2F0]*/
	};
	_H3API_ASSERT_SIZE_(H3MapInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
