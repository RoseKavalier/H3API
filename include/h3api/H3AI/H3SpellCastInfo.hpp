//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3AI/H3SimulatedHero.hpp"

namespace h3
{
	_H3API_DECLARE_(SpellCastInfo);
	struct H3Hero;
	typedef H3SpellCastInfo H3AiSpellCastInfo;

#pragma pack(push, 4)

	struct H3SpellCastInfo
	{
		_H3API_SIZE_(0x410);
		_H3API_VTABLE_(0x63B7D8);
		_H3API_CTOR_DTOR_(0x436610, 0x436880);
		VOID* vtable;
		H3Hero* hero;
		H3Hero* enemyHero;
		INT32 side;
		INT32 enemySide;
		h3unk8 _f_14[8];
		BOOL8 enemyDefeated;
		BOOL8 _f_1D;
		union
		{
			H3SimulatedHero combatInfo;
			H3SimulatedHero heroInfo;
		};
		h3unk32 _f_48;
		h3unk8 _f_4C;
		h3unk8 _f_50[960];
	};
	_H3API_ASSERT_SIZE_(H3SpellCastInfo);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
