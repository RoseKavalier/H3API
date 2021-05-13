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
#include "h3api/H3Constants/H3CstHeroes.hpp"
#include "h3api/H3Skills/H3SecondarySkill.hpp"

namespace h3
{
	_H3API_DECLARE_(HeroInfo);

#pragma pack(push, 4)

	/** @brief Starting Hero default data*/
	struct H3HeroInfo
	{
		_H3API_SIZE_(0x5C);
		_H3API_GET_INFO_(0x67DCE8, H3HeroInfo);

		/** @brief [00]*/
		BOOL32           isFemale;
		/** @brief [04] 0..13 never used*/
		eHeroRace        race;
		/** @brief [08] 0..17 eHeroClass*/
		INT32            heroClass;
		/** @brief [0C] starting secondary skills*/
		H3SecondarySkill sskills[2];
		/** @brief [1C]*/
		BOOL8            hasSpellbook;
		/** @brief [20] -1 if no spell*/
		INT32            startingSpell;
		/** @brief [24] NH3Creatures::eCreatures*/
		INT32            armyType[3];
		/** @brief [30] 48x36 small portrait name*/
		LPCSTR           smallPortrait;
		/** @brief [34] 58x64 large portrait name*/
		LPCSTR           largePortrait;
		/** @brief [38] hero is available in RoE*/
		BOOL8            roeHero;
		/** @brief [39] hero is available in AB and SoD*/
		BOOL8            expansionHero;
		/** @brief [3A] hero is available in specific campaigns, not in regular maps*/
		BOOL8            campaignHero;
	protected:
		UINT             _f_3C; // always 0
	public:
		/** @brief [40] default name of the hero*/
		LPCSTR           name;
		/** @brief [44] up to 3 starting stacks, type is determined by .armyType*/
		struct StartingCreatures
		{
			INT32 lowAmount;
			INT32 highAmount;
		}creatureAmount[3];
	};
	_H3API_ASSERT_SIZE_(H3HeroInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
