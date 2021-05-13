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
#include "h3api/H3Constants/H3CstTowns.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Containers/H3Bitset.hpp"
#include "h3api/H3Creatures/H3Army.hpp"
#include "h3api/H3Creatures/H3Creature.hpp"
#include "h3api/H3GameData/H3Resources.hpp"

namespace h3
{
	_H3API_DECLARE_(Town);
	struct H3Hero;
	struct H3TownCreatureTypes;

#pragma pack(push, 4)

	// * how towns are represented in memory
	struct H3Town
	{
		_H3API_SIZE_(0x168);

		/** @brief [0] 0..48*/
		UINT8	number;
		/** @brief [1] -1..7 who owns this town*/
		INT8	owner;
		/** @brief [2] structure built here this turn*/
		BOOL8	builtThisTurn; // +2
	protected:
		h3unk8	_f_03;
	public:
		/** @brief [4] eTown 0..8*/
		UINT8	type;
		/** @brief [5] */
		UINT8	x;
		/** @brief [6] */
		UINT8	y;
		/** @brief [7] */
		UINT8	z;
		/** @brief [8] X destination of shipyard boat (+/- 2)*/
		UINT8	pos2PlaceBoatX;
		/** @brief [9] Y destination of shipyard boat*/
		UINT8	pos2PlaceBoatY;
		/** @brief [0C] ID of the hero inside the city's garrison*/
		INT32	garrisonHero;
		/** @brief [10] ID of the visiting hero in the bottom bar*/
		INT32	visitingHero;
		/** @brief [14] */
		INT8	mageLevel;
	protected:
		h3unk8	_f_15;
	public:
		/** @brief [16] number of recruitable non-upgraded then upgraded creatures*/
		INT16	recruits[2][7];
	protected:
		h3unk8	_f_32;
	public:
		/** @brief [33] if mana vortex was not used this week*/
		BOOL8	manaVortexAvailable;
		/** @brief [34] */
		INT8	mysticPondResourceCount;
		/** @brief [38] */
		INT32	mysticPondResourceType;
		/** @brief [3C] */
		H3CreatureSlot16 summoningPortalCreature;
		/** @brief [44] which spells are available in mage guild*/
		INT32	spells[5][6];
		/** @brief [BC] is it built?*/
		BOOL8	magicGuild[5];
		/** @brief [C4] the town's name, can be lengthened*/
		H3String name;
	protected:
		/** @brief [D4] available/banned spells or something of this nature*/
		H3SpellsBitset spellsRelated;
	public:
		/** @brief [E0] the creatures in the town's garrison not belonging to a hero*/
		H3Army guards;
	protected:
		/** @brief [118] ?for unused combat creatures?*/
		H3Army guards0;
	public:
		/** @brief [150] for the first 32 buildings*/
		H3BuildingsBitfield built;
		/** @brief [158] for the remaining buildings*/
		H3BuildingsBitfield built2;
		/** @brief [160] will this structure be buildable in this town?*/
		H3BuildingsBitfield buildableMask;

		_H3API_ BOOL                 CanBeBuilt(eBuildings id) const;
		_H3API_ H3Hero*              GetGarrisonHero() const;
		_H3API_ H3String             GetNameAndType() const;
		_H3API_ LPCSTR               GetTownTypeName() const;
		_H3API_ H3Hero*              GetVisitingHero() const;
		_H3API_ INT32                GoldIncome(BOOL count_silo = FALSE) const;
		_H3API_ H3Resources&         GetResourceSiloIncome() const;
		_H3API_ H3TownCreatureTypes& GetCreatureTypes() const;
		_H3API_ BOOL                 IsBuildingBuilt(INT32 id) const;
		_H3API_ BOOL8                IsMageGuildBuilt(INT level) const;
		_H3API_ H3Resources          TotalIncome() const;
	};
	_H3API_ASSERT_SIZE_(H3Town);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
