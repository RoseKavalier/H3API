//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-06                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants/H3CstTerrain.hpp"
#include "h3api/H3AdventureMap/H3MapArtifact.hpp"
#include "h3api/H3AdventureMap/H3MapBlackMarket.hpp"
#include "h3api/H3AdventureMap/H3MapBoat.hpp"
#include "h3api/H3AdventureMap/H3MapCampfire.hpp"
#include "h3api/H3AdventureMap/H3MapCorpse.hpp"
#include "h3api/H3AdventureMap/H3MapCreatureBank.hpp"
#include "h3api/H3AdventureMap/H3MapEvent.hpp"
#include "h3api/H3AdventureMap/H3MapFlotsam.hpp"
#include "h3api/H3AdventureMap/H3MapFountainFortune.hpp"
#include "h3api/H3AdventureMap/H3MapGarrison.hpp"
#include "h3api/H3AdventureMap/H3MapGenerator.hpp"
#include "h3api/H3AdventureMap/H3MapHero.hpp"
#include "h3api/H3AdventureMap/H3MapLeanTo.hpp"
#include "h3api/H3AdventureMap/H3MapLearningStone.hpp"
#include "h3api/H3AdventureMap/H3MapLighthouse.hpp"
#include "h3api/H3AdventureMap/H3MapMagicShrine.hpp"
#include "h3api/H3AdventureMap/H3MapMagicSpring.hpp"
#include "h3api/H3AdventureMap/H3MapMine.hpp"
#include "h3api/H3AdventureMap/H3MapMonolith.hpp"
#include "h3api/H3AdventureMap/H3MapMonster.hpp"
#include "h3api/H3AdventureMap/H3MapMysticGarden.hpp"
#include "h3api/H3AdventureMap/H3MapObelisk.hpp"
#include "h3api/H3AdventureMap/H3MapOceanBottle.hpp"
#include "h3api/H3AdventureMap/H3MapPandorasBox.hpp"
#include "h3api/H3AdventureMap/H3MapPrison.hpp"
#include "h3api/H3AdventureMap/H3MapPyramid.hpp"
#include "h3api/H3AdventureMap/H3MapQuestGuard.hpp"
#include "h3api/H3AdventureMap/H3MapRefugeeCamp.hpp"
#include "h3api/H3AdventureMap/H3MapResource.hpp"
#include "h3api/H3AdventureMap/H3MapScholar.hpp"
#include "h3api/H3AdventureMap/H3MapScroll.hpp"
#include "h3api/H3AdventureMap/H3MapSeaChest.hpp"
#include "h3api/H3AdventureMap/H3MapSeerHut.hpp"
#include "h3api/H3AdventureMap/H3MapShipwreckSurvivor.hpp"
#include "h3api/H3AdventureMap/H3MapShipyard.hpp"
#include "h3api/H3AdventureMap/H3MapSign.hpp"
#include "h3api/H3AdventureMap/H3MapTown.hpp"
#include "h3api/H3AdventureMap/H3MapTreasureChest.hpp"
#include "h3api/H3AdventureMap/H3MapTreeOfKnowledge.hpp"
#include "h3api/H3AdventureMap/H3MapUniversity.hpp"
#include "h3api/H3AdventureMap/H3MapWagon.hpp"
#include "h3api/H3AdventureMap/H3MapWarriorsTomb.hpp"
#include "h3api/H3AdventureMap/H3MapWaterMill.hpp"
#include "h3api/H3AdventureMap/H3MapWindmill.hpp"
#include "h3api/H3AdventureMap/H3MapWitchHut.hpp"
#include "h3api/H3AdventureMap/H3ObjectAttributes.hpp"

namespace h3
{
	_H3API_DECLARE_(MapItem);
	_H3API_DECLARE_(ObjectDraw);

#pragma pack(push, 4)

	/** @brief data of objects to be drawn at a given map tile*/
	struct H3ObjectDraw
	{
		_H3API_SIZE_(0x4);
		/** @brief [0] index of H3ObjectAttributes*/
		UINT16 sprite;
		/**
		 * @brief [2] which square of the DEF
		 * bottom right = 0, then left to right, down to top. Row 1: 0x10 and so on
		 */
		UINT8 tileID;
		/** @brief [3] 0..6 drawing layer, 6 being top and 0 bottom*/
		UINT8 layer;

		_H3API_ H3ObjectDraw(UINT16 sprite, UINT8 tile_id, UINT8 layer);
	};
	_H3API_ASSERT_SIZE_(H3ObjectDraw);

#pragma pack(pop) /* align-4 */

#pragma pack(push, 1)

	/** @brief data on a given tile on the adventure map*/
	struct H3MapItem
	{
		_H3API_SIZE_(0x26);

		/** @brief [0] union of all data types*/
		union
		{
			UINT32                     setup;
			H3MapitemArtifact          artifact;
			H3MapitemBlackMarket       blackMarket;
			H3MapitemBoat              boat;
			H3MapitemCampfire          campfire;
			H3MapitemCorpse            corpse;
			H3MapitemCreatureBank      creatureBank;
			H3MapitemEvent             event;
			H3MapitemFlotsam           flotsam;
			H3MapitemFountainFortune   fountainFortune;
			H3MapitemGarrison          garrison;
			H3MapitemGenerator         generator;
			H3MapitemHero              hero;
			H3MapitemLeanTo            leanTo;
			H3MapitemLearningStone     learningStone;
			H3MapitemLighthouse        lighthouse;
			H3MapitemMagicShrine       magicShrine;
			H3MapitemMagicSpring       magicSpring;
			H3MapitemMine              mine;
			H3MapitemMonolith          monolith;
			H3MapitemMonster           wanderingCreature;
			H3MapitemMysticGarden      mysticGarden;
			H3MapitemObelisk           obelisk;
			H3MapitemOceanBottle       oceanBottle;
			H3MapitemPandorasBox       pandorasBox;
			H3MapitemPrison            prison;
			H3MapitemPyramid           pyramid;
			H3MapitemQuestGuard        questGuard;
			H3MapitemRefugeeCamp       refugeeCamp;
			H3MapitemResource          resource;
			H3MapitemScholar           scholar;
			H3MapitemScroll            spellScroll;
			H3MapitemSeaChest          seaChest;
			H3MapitemSeerHut           seerHut;
			H3MapitemShipwreckSurvivor shipwreckSurvivor;
			H3MapitemShipyard          shipyard;
			H3MapitemSign              signPost;
			H3MapitemTown              town;
			H3MapitemTreasureChest     treasureChest;
			H3MapitemTreeOfKnowledge   treeKnowledge;
			H3MapitemUniversity        university;
			H3MapitemWagon             wagon;
			H3MapitemWarriorsTomb      warriorsTomb;
			H3MapitemWaterMill         watermill;
			H3MapitemWindmill          windmill;
			H3MapitemWitchHut          witchHut;
			SODSP_MapMonster           sodspWanderingCreature;
		};
		/** @brief [4] */
		// *dirt, grass, snow ...
		INT8 land;
		/** @brief [5] */
		// * the id of land DEF sprite
		INT8 landSprite;
		/** @brief [6] */
		// * none, clear, icy, ...
		INT8 river;
		/** @brief [7] the id of river DEF sprite*/
		INT8 riverSprite;
		/** @brief [8] none, dirt, gravel, ...*/
		INT8 road;
		/** @brief [the id of road DEF sprite] */
		INT8 roadSprite;
	protected:
		h3unk16 _f_0A;
	public:
		/** @brief [0C] mirror effect of terrain defs*/
		union {
			struct {
				BOOL8 tileMirrorH  : 1; /** @brief [01]*/
				BOOL8 tileMirrorV  : 1; /** @brief [02]*/
				BOOL8 riverMirrorH : 1; /** @brief [04]*/
				BOOL8 riverMirrorV : 1; /** @brief [08]*/
				BOOL8 roadMirrorH  : 1; /** @brief [10]*/
				BOOL8 roadMirrorV  : 1; /** @brief [20]*/
				BOOL8 canDig       : 1; /** @brief [40]*/
				BOOL8 animated     : 1; /** @brief [80] (river, water or lava terrain)*/
			};
			UINT8 mirror;
		};
		/** @brief [0D] accessibility of tiles*/
		union {
			struct {
				BOOL8 cannotAccess   : 1; /** @brief [01]*/
				BOOL8 waterEdge      : 1; /** @brief [02] see 0x4FEA32*/
				BOOL8 unknownAccess1 : 2;
				BOOL8 entranceTile   : 1; /** @brief [10] yellow tile in mapeditor*/
				BOOL8 unknownAccess2 : 3;
			};
			UINT8 access;
		};
		/** @brief [E] vector of DEFs to draw on this tile*/
		H3Vector<H3ObjectDraw> objectDrawing;
		/** @brief [1E] object type on this tile*/
		INT16 objectType;
	protected:
		h3unk16 _f_20;
	public:
		/** @brief [22] subtype of object on this tile*/
		INT16 objectSubtype;
		/** @brief [24] H3ObjectDetails index of top drawn object (-1 if nothing)*/
		UINT16 drawnObjectIndex;

		_H3API_ BOOL          CanDig() const;
		// * Get university on this tile
		_H3API_ H3University* GetUniversity();
		// * get real entrance (if any) of object on this tile
		_H3API_ H3MapItem*    GetEntrance();
		// if there's a hero on a tile, returns object underneath the hero
		_H3API_ INT           GetRealType() const;
		// if there's a hero on a tile, returns the setup of the object underneath the hero
		_H3API_ UINT          GetRealSetup() const;
		_H3API_ H3Point       GetCoordinates() const;
		_H3API_ BOOL          IsBlocked() const;
		_H3API_ BOOL          IsEntrance() const;
	};
	_H3API_ASSERT_SIZE_(H3MapItem);

#pragma pack(pop) /* align-1 */

} /* namespace h3 */
