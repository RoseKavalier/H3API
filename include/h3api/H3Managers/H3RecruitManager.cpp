//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3RecruitManager.hpp"
#include "h3api/H3Managers/H3ExecutiveMgr.hpp"
#include "h3api/H3Creatures/H3Creature.hpp"
#include "h3api/H3AdventureMap/H3MapGenerator.hpp"

namespace h3
{
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0)
	{
		initialize(army, is_summoning_portal, type0, &amount0, -1, 0, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0,
		INT32 type1, INT16& amount1)
	{
		initialize(army, is_summoning_portal, type0, &amount0, type1, &amount1, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0,
		INT32 type1, INT16& amount1, INT32 type2, INT16& amount2)
	{
		initialize(army, is_summoning_portal, type0, &amount0, type1, &amount1, type2, &amount2, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, INT32 type0, INT16& amount0,
		INT32 type1, INT16& amount1, INT32 type2, INT16& amount2, INT32 type3, INT16& amount3)
	{
		initialize(army, is_summoning_portal, type0, &amount0, type1, &amount1, type2, &amount2, type3, &amount3);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0)
	{
		initialize(hero, type0, &amount0, -1, 0, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1)
	{
		initialize(hero, type0, &amount0, type1, &amount1, -1, 0, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
		INT32 type2, INT16& amount2)
	{
		initialize(hero, type0, &amount0, type1, &amount1, type2, &amount2, -1, 0);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Hero* hero, INT32 type0, INT16& amount0, INT32 type1, INT16& amount1,
		INT32 type2, INT16& amount2, INT32 type3, INT16& amount3)
	{
		initialize(hero, type0, &amount0, type1, &amount1, type2, &amount2, type3, &amount3);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, BOOL8 is_summoning_portal, H3CreatureSlot16& slot0,
		H3CreatureSlot16& slot1, H3CreatureSlot16& slot2, H3CreatureSlot16& slot3)
	{
		initialize(army, is_summoning_portal, slot0.type, &slot0.amount, slot1.type, &slot1.amount,
			slot2.type, &slot2.amount, slot3.type, &slot3.amount);
	}
	_H3API_ H3RecruitMgr::H3RecruitMgr(H3Army& army, H3Generator& g)
	{
		initialize(army, FALSE, g.creatureTypes[0], &g.creatureCounts[0], g.creatureTypes[1], &g.creatureCounts[1],
			g.creatureTypes[2], &g.creatureCounts[2], g.creatureTypes[3], &g.creatureCounts[3]);
	}
	_H3API_ VOID H3RecruitMgr::Run()
	{
		H3ExecutiveMgr::Get()->StartManager(this);
	}
	_H3API_ H3RecruitMgr& H3RecruitMgr::initialize(H3Army& army, BOOL8 is_summoning_portal,
		INT32 type0, INT16* amount0, INT32 type1, INT16* amount1,
		INT32 type2, INT16* amount2, INT32 type3, INT16* amount3)
	{
		return THISCALL_11(H3RecruitMgr&, 0x551750, this, &army, is_summoning_portal, type0, amount0,
			type1, amount1, type2, amount2, type3, amount3);
	}
	_H3API_ H3RecruitMgr& H3RecruitMgr::initialize(H3Hero* hero, INT32 type0, INT16* amount0, INT32 type1,
		INT16* amount1, INT32 type2, INT16* amount2, INT32 type3, INT16* amount3)
	{
		return THISCALL_10(H3RecruitMgr&, 0x551860, this, hero, type0, amount0,
			type1, amount1, type2, amount2, type3, amount3);
	}

} /* namespace h3 */
