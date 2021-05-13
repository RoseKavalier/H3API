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
#include "h3api/H3GameData/H3MainSetup.hpp"
#include "h3api/H3GameData/H3MapInfo.hpp"
#include "h3api/H3Heroes/H3SetupHero.hpp"
#include "h3api/H3Heroes/H3Hero.hpp"
#include "h3api/H3Campaign/H3CmpInfo.hpp"
#include "h3api/H3AdventureMap/H3MapBlackMarket.hpp"
#include "h3api/H3Players/H3Player.hpp"
#include "h3api/H3Players/H3PlayersInfo.hpp"

namespace h3
{
	_H3API_DECLARE_(Main);
	struct H3MapItem;
	struct H3SetupTown;
	struct H3Town;
	struct H3Signpost;
	struct H3Mine;
	struct H3Generator;
	struct H3Garrison;
	struct H3Boat;
	struct H3University;
	struct H3CreatureBank;

	/* alternate names! */
	_H3API_TYPE_DECLARE_(H3Main, Game);
	_H3API_TYPE_DECLARE_(H3Main, Base);

#pragma pack(push, 4)
	/**
	 * @brief Holds most data relevant to play a map/game
	 * not a manager!
	 */
	struct H3Main
	{
		_H3API_SIZE_(0x4E7D0);
		_H3API_GET_INFO_(0x699538, H3Main);

	protected:
		h3unk8 _f_0000[4];
	public:
		/** @brief [04] */
		INT8 disabledShrines[70];
		/** @brief [4A] */
		INT8 disabledSpells[70];
		/** @brief [90] message to show Grail is not enabled in a town, reset every day*/
		BOOL8 grailDisabledMessage;
		/** @brief [94] to read data from h3m file*/
		H3Vector<H3SetupTown> townSetups;
		/** @brief [A4] to read data from h3m file*/
		H3SetupHero heroSetup[156];
	protected:
		h3unk8 _f_1F454[4];
		/** @brief [1F458]*/
		H3CmpInfo campaignInfo;
		h3unk8 _f_1F4D4[354];
	public:
		/** @brief [1F636]*/
		BOOL8 isDead[8];
		/** @brief [1F63E]*/
		struct Date
		{
			_H3API_SIZE_(6);
			UINT16 day;
			UINT16 week;
			UINT16 month;
			/** @brief converts day, week, month into days from start, first day being 1*/
			_H3API_ UINT32 CurrentDay() const;
		}date;
	protected:
		h3unk8 _f_1F644[32];
	public:
		/** @brief [1F664] */
		H3ArtifactMerchant artifactMerchant;
		/** @brief [1F680] */
		H3Vector<H3BlackMarket> blackMarkets;
		/** @brief [1F690] */
		struct Grail
		{
			_H3API_SIZE_(0x8);
			UINT16 x;		// +0
			UINT16 y;		// +2
			UINT8  z;		// +4
		protected:
			h3unk8 _f_5;
		public:
			INT8 isPresent;	// +6
		}grail;
		/** @brief [1F698] 0 - RoE, 1 - AB, 2 - SoD*/
		INT32 mapKind;
		/** @brief [1F69C] */
		BOOL8 isCheater;
		/** @brief [1F69D] Griffin dwelling doesn't require Blacksmith in this mode*/
		BOOL8 inTutorial;
	protected:
		h3unk8 _f_1F69E[2];
	public:
		/** @brief [1F6A0] */
		H3PlayersInfo playersInfo;
		/** @brief [1F86C] */
		H3MapInfo mapInfo;
		/** @brief [1FB70] */
		H3MainSetup mainSetup;
	protected:
		h3unk8 _f_20ACC[4];
	public:
		/** @brief [20AD0] */
		H3Player players[8];
		/** @brief [21610] */
		H3Vector<H3Town> towns;
		/** @brief [21620] */
		H3Hero heroes[156];
		/** @brief [4DF18] */
		INT8 heroOwner[156];
		/** @brief [4DFB4] */
		H3Bitfield heroMayBeHiredBy[156];
		/** @brief [4E224] */
		INT8 randomArtifacts[144];
		/** @brief [4E2B4] */
		INT8 artifactsAllowed[144];
	protected:
		/**
		 * When visiting one of these objects, whole team gets set as visited
		 * Exists as an array[32] (Shrines are referred as index 19,20,21 ca. 4A9BAF, and save/read uses 32 bytes)
		 */
		/** @brief [4E344] */
		H3PlayersBitfield visitedBuoy;
		H3PlayersBitfield visitedSwanPond;
		H3PlayersBitfield visitedFaerieRing;
		H3PlayersBitfield visitedFountainFortune;
		H3PlayersBitfield visitedGardenRevelation;
		H3PlayersBitfield visitedLearningStones;
		H3PlayersBitfield visitedLibraryEnlightenment;
		H3PlayersBitfield visitedMarlettoTower;
		H3PlayersBitfield visitedMercenaryCamp;
		H3PlayersBitfield visitedSchoolMagic;
		H3PlayersBitfield visitSchoolWar;
		H3PlayersBitfield visitedStarAxis;
		H3PlayersBitfield visitedWitchHut;
		H3PlayersBitfield visitedFountainYouth;
		H3PlayersBitfield visitedHillFort;
		H3PlayersBitfield visitedMagicSprings;
		/** @brief [4E354] */
		H3PlayersBitfield visitedMermaid;
		H3PlayersBitfield visitedRallyFlag;
		H3PlayersBitfield visitedTreeKnowledge;
		H3PlayersBitfield visitedShrines;
		H3PlayersBitfield visitedIdolFortune;
		H3PlayersBitfield visitedTemples;
		H3PlayersBitfield visitedUniversities;
		H3PlayersBitfield visitedMagicWells;
		H3PlayersBitfield visitedOasis;
		H3PlayersBitfield visitedWateringHole;
		H3PlayersBitfield visitedAltarSacrifice;
		h3unk8 field_4E361[3]; // unused
	public:
		/** @brief [4E364] bitfield for players*/
		H3PlayersBitfield keymasterVisited[8];
	protected:
		/**
		 * @brief [4E36C] terrain reveal bitfield for cartographers
		 * 0 .. water cartographer (0x100)
		 * 1 .. land cartographer  (0xBF)
		 * 2 .. subterranean cartographer (0x40)
		 */
		UINT16 cartographersLandReveal[3];
		H3PlayersBitfield visitedCartographers[3];
		h3unk8 _f_4E375[3]; // unused
	public:
		/** @brief [4E378] */
		H3Vector<H3Signpost> signpostsBottles;
		/** @brief [4E388] */
		H3Vector<H3Mine> minesLighthouses;
		/** @brief [0x4E398] */
		H3Vector<H3Generator> dwellings;
		/** @brief [0x4E3A8] */
		H3Vector<H3Garrison> garrisons;
		/** @brief [0x4E3B8] */
		H3Vector<H3Boat> boats;
		/** @brief [0x4E3C8] */
		H3Vector<H3University> universities;
		/** @brief [0x4E3D8] */
		H3Vector<H3CreatureBank> creatureBanks;
		/** @brief [4E3E8] */
		INT8 obeliskCount;
		/** @brief [4E3E9] */
		UINT8 obeliskVisited[48];
	protected:
		h3unk8 _f_4E419[575];
	public:
		/** @brief [4E658] */
		INT8 bannedSkills[28];
	protected:
		h3unk8 _f_4E674[4];
	public:
		/** @brief [4E678] H3Position*/
		H3Vector<UINT32> monolithTwoWay[8];
		/** @brief [4E6F8] H3Position*/
		H3Vector<UINT32> monolithOneWay[8];
	protected:
		h3unk8 _f_4E778[4];
	public:
		/** @brief [4E77C] H3Position*/
		H3Vector<UINT32> whirlPools;
		/** @brief [4E78C] H3Position*/
		H3Vector<UINT32> subterraneanGatesDestination;
		/** @brief [4E79C] H3Position*/
		H3Vector<UINT32> subterraneanGatesID;
	protected:
		H3Vector<h3unk8*> replayActions;
		H3Vector<h3unk8*> _f_4E7BC;
		h3unk8 _f_4E7CC[4];

	public:

		_H3API_ BOOL HasUnderground() const;

		_H3API_ H3Point GetCoordinates(H3MapItem* item);
		/**
		 * @brief Get H3Hero structure safely.
		 * @param id Identifier for the hero to get.
		 * @return H3Hero* for specified id, nullptr if invalid.
		*/
		_H3API_ H3Hero*    GetHero(INT32 id);
		_H3API_ H3MapItem* GetMapItem(UINT32 mixedPosition);
		_H3API_ H3Player*  GetPlayer();
		_H3API_ INT32      GetPlayerID();
		_H3API_ INT32      GetRandomArtifactOfLevel(INT32 level);
		_H3API_ BOOL8      IsHuman(INT32 player_id);
		_H3API_ VOID       PlaceObjectOnMap(INT32 x, INT32 y, INT32 z, INT32 type, INT32 subtype, INT32 setup = -1);
		_H3API_ VOID       RefreshMapItemAppearrance(H3MapItem* mi);
		_H3API_ VOID       ResetRandomArtifacts();
		_H3API_ VOID       SaveGame(LPCSTR save_name);
		/**
		 * @brief Used to update the H3LoadedDef on the adventure map.
		 * For example, to modify town's appearance after building Fort.
		 * @param item Position on the map that should be updated.
		*/
		_H3API_ VOID UpdateMapItemAppearance(H3MapItem* item);

		_H3API_ H3Map<H3MapItem>     GetMap();
		_H3API_ H3FastMap<H3MapItem> GetFastMap();
	};
	_H3API_ASSERT_SIZE_(H3Main);
	_H3API_ASSERT_SIZE_(H3Main::Date);
	_H3API_ASSERT_SIZE_(H3Main::Grail);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
