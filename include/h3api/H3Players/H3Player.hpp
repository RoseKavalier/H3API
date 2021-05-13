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
#include "h3api/H3GameData/H3Resources.hpp"
#include "h3api/H3Constants/H3CstPlayers.hpp"

namespace h3
{
	_H3API_DECLARE_(Player);
	struct H3Hero;

#pragma pack(push, 4)

	/** @brief data about each of the 8 players on the map*/
	struct H3Player
	{
		_H3API_SIZE_(0x168);

		/** @brief [0] */
		// * 0..7 RED~PINK
		INT8 ownerID;
		/** @brief [1] */
		// * number of heroes on map
		INT8 numberHeroes;
		/** @brief [4] */
		// * the id of the active hero
		// * -1 if none
		INT32  currentHero;
		/** @brief [8] */
		// * IDs of the 8 possible heroes on adventure map
		INT32  heroIDs[8];
		/** @brief [28] */
		// * ID of the hero in the left slot of tavern
		INT32  tavernHeroL;
		/** @brief [2C] */
		// * ID of the hero in the right slot of tavern
		INT32  tavernHeroR;
	protected:
		h3unk8 _f_30[4];
	public:
		/** @brief [34] */
		// * adventurer, explorer, builder
		INT32 AI_type;
		/** @brief [38] */
		// * 0~47 visited obelisks
		INT8 visitedObelisks;
	protected:
		h3unk8 _f_39[4];
	public:
		/** @brief [3D] */
		// * the number of days left to live without a town
		// * -1 if at least 1 town is owned
		INT8  daysLeft;
		/** @brief [3E] */
		// * the number of towns owned
		INT8  townsCount;
		/** @brief [3F] */
		// * ID of the selected town
		INT8  currentTown;
		/** @brief [40] */
		// * IDs of the towns owned by player
		INT8  towns[48];
	protected:
		h3unk8 _f_70[4];
		/** @brief [74] */
		INT32 topHeroIndex;
		h3unk8 _f_78[36];
	public:
		/** @brief [9C] */
		// * the current resources owned by player
		H3Resources playerResources;
		/** @brief [B8] */
		H3Bitfield magicalGardens;
		/** @brief [BC] */
		H3Bitfield magicSpring;
		/** @brief [C0] */
		H3Bitfield visitedCorpses;
		/** @brief [C4] */
		H3Bitfield visitedLeanTos;
	protected:
		h3unk8 _f_C8[4];
		/** @brief [CC] name of player, uncertain length*/
		CHAR player_name[21];
	public:
		/** @brief [E1] */
		// * 1 human, 0 computer
		BOOL8 is_human;
		/** @brief [E2] */
		// * 1 human, 0 computer
		BOOL8 is_human2;
	protected:
		h3unk8 _f_E3[3];
		/** @brief [E6] */
		BOOL8 human;
		h3unk8 _f_E7;
		/** @brief [E8] */
		BOOL hasComboArtifacts;
		h3unk8 _f_EC[28];
	public:
		/** @brief [108] */
		// * the amount of resources gained daily
		H3Resources income;
	protected:
		h3unk8 _f_124[4];
		/** @brief [128] */
		// * doubles used by AI
		DOUBLE resourceImportance[7];
		h3unk8 _f_160[8];
	public:
		// * returns structure of active hero if any
		_H3API_ H3Hero* GetActiveHero();
	};
	_H3API_ASSERT_SIZE_(H3Player);

	_H3API_NAMED_STRUCT_(H3Player, ActivePlayer, 0x69CCFC);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
