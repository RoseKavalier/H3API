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
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Constants/H3CstHeroes.hpp"

namespace h3
{
	_H3API_DECLARE_(CmpStartingBonusOption);
	_H3API_DECLARE_(CmpHeroCrossoverOptions);
	_H3API_DECLARE_(CmpStartingHeroOption);
	struct H3CmpStartingBonusDetails;

#pragma pack(push, 4)

	/** @brief abstract class from which other starting options inherit*/
	struct H3CmpStartingOptionsBase
	{
		struct VTable
		{
			h3func dtor;
			h3func imgIsPcx;
			h3func numberBoni;
			h3func imageName;
			h3func getSpriteFrame;
			h3func getCrossoverObjects;
			h3func getDescription;
			h3func _f_1C; // always returns -1
			h3func getPlayerId;
			h3func read;
			h3func applyBonus;
			h3func updateOptions;
			h3func _f_30; // maybe loading save?
		}*vtable;
	};

	struct H3CmpStartingBonusOption : H3CmpStartingOptionsBase // 1
	{
		_H3API_SIZE_(0x18);
		_H3API_VTABLE_(0x63D98C);

		INT32 playerColor;
		H3Vector<H3CmpStartingBonusDetails*> boni;
	};
	_H3API_ASSERT_SIZE_(H3CmpStartingBonusOption);

	struct H3CmpHeroCrossoverOptions : H3CmpStartingOptionsBase // 2
	{
		_H3API_SIZE_(0x14);
		_H3API_VTABLE_(0x63DAD8);

		struct CrossoverHeroes
		{
			INT8 player;
			INT8 scenario;
		};

		H3Vector<CrossoverHeroes> crossoverHeroes;
	};
	_H3API_ASSERT_SIZE_(H3CmpHeroCrossoverOptions);

	struct H3CmpStartingHeroOption : H3CmpStartingOptionsBase // 3
	{
		_H3API_SIZE_(0x14);
		_H3API_VTABLE_(0x63DB0C);

		struct StartingHeroes
		{
			INT32 player;
			eHero hero; // -1 for random
		};

		H3Vector<StartingHeroes> heroes;
	};
	_H3API_ASSERT_SIZE_(H3CmpStartingHeroOption);

#ifdef _H3API_CPLUSPLUS11_
	union H3CmpStartBoni
	{
		H3CmpStartingBonusOption   bonus;
		H3CmpHeroCrossoverOptions  crossoverOptions;
		H3CmpStartingHeroOption    heroOptions;

		H3CmpStartBoni() {}
		~H3CmpStartBoni() {}
	};
#else
	typedef VOID* H3CmpStartBoni;
#endif

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
