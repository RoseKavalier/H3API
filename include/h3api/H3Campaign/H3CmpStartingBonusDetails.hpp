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
#include "h3api/H3Constants/H3CstArtifact.hpp"
#include "h3api/H3Constants/H3CstCampaigns.hpp"
#include "h3api/H3Constants/H3CstCreatures.hpp"
#include "h3api/H3Constants/H3CstHeroes.hpp"
#include "h3api/H3Constants/H3CstResources.hpp"
#include "h3api/H3Constants/H3CstSkills.hpp"
#include "h3api/H3Constants/H3CstSpells.hpp"
#include "h3api/H3Constants/H3CstTowns.hpp"
#include "h3api/H3Skills/H3PrimarySkills.hpp"
#include "h3api/H3Skills/H3SecondarySkill.hpp"

namespace h3
{
	_H3API_DECLARE_(CmpStartingBonusDetails);

#pragma pack(push, 4)
	/** @brief abstract base class */
	struct H3CmpStartingBonusDetails
	{
		struct VTable
		{
			h3func dtor;
			h3func isBuilding; // only one
			h3func imageName;
			h3func spriteFrame;
			h3func description;
			h3func apply;
			h3func read; // +18
			h3func buildingId; // for buildings only, converts to game id
		}*vtable;
	};

	struct H3CmpBonusSpell : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DAA0);

		/** @brief [04] hero id*/
		eHero  hero;
		/** @brief [08]*/
		eSpell spell;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusSpell);

	struct H3CmpBonusCreatures : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x10);
		_H3API_VTABLE_(0x63DA80);

		/** [04] @brief hero id, -3 for most powerful hero*/
		eHero     hero;
		eCreature type;
		INT32     count;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusCreatures);

	struct H3CmpBonusBuilding : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA60);

		eTown town;
		union{
			/** @brief [08] value read from h3m */
			eBuildings building;
			/** @brief [08] value set using TownBuildings_688910[town][building] */
			INT32      index;
		};
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusBuilding);

	struct H3CmpBonusArtifact : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA40);

		eHero     hero;
		eArtifact artifact;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusArtifact);

	struct H3CmpBonusSpellScroll : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA20);

		/** @brief [04] hero id, or -3 for most powerful hero*/
		eHero hero;
		INT32 spell;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusSpellScroll);

	struct H3CmpBonusPrimarySkill : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63DA00);

		eHero           hero;
		H3PrimarySkills skills;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusPrimarySkill);

	struct H3CmpBonusSecondarySkill : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x10);
		_H3API_VTABLE_(0x63D9E0);

		eHero		     hero;
		H3SecondarySkill skill;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusSecondarySkill);

	struct H3CmpBonusResources : H3CmpStartingBonusDetails
	{
		_H3API_SIZE_(0x0C);
		_H3API_VTABLE_(0x63D9C0);

		/** @brief single resource or if <0 multiples (see enum for details) */
		eResource type;
		INT32     count;
	};
	_H3API_ASSERT_SIZE_(H3CmpBonusResources);

	struct H3CmpBonusBuildingsNames
	{
		_H3API_GET_INFO_(0x48415F + 3, H3CmpBonusBuildingsNames);

		LPCSTR names[44];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
