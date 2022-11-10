//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-01              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3CombatManager.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"
#include "h3api/H3Assets/H3LoadedPcx.hpp"

namespace h3
{
	_H3API_ VOID H3CombatManager::SimulateMouseAtHex(INT32 hex_id)
	{
		return THISCALL_2(VOID, 0x477550, this, hex_id);
	}
	_H3API_ BOOL8 H3CombatManager::CanCastSpellAtCoord(INT32 spell_id, INT32 spell_expertise, INT32 coordinates)
	{
		return THISCALL_7(BOOL8, 0x5A3CD0, this, spell_id, spell_expertise, coordinates, currentActiveSide, 1, 0);
	}
	_H3API_ VOID H3CombatManager::WinBattle()
	{
		return THISCALL_2(VOID, 0x468F80, this, 1 - currentActiveSide);
	}
	_H3API_ VOID H3CombatManager::LoadSpell(INT32 spell_id)
	{
		return THISCALL_3(VOID, 0x59EF60, this, spell_id, 0);
	}
	_H3API_ VOID H3CombatManager::CastSpell(INT32 spell_id, INT32 hex_ix, INT32 cast_type_012, INT32 hex2_ix, INT32 skill_level, INT32 spell_power)
	{
		THISCALL_7(VOID, 0x5A0140, this, spell_id, hex_ix, cast_type_012, hex2_ix, skill_level, spell_power);
	}
	_H3API_ INT32 H3CombatManager::SquareAtCoordinates(const H3POINT& p) const
	{
		return SquareAtCoordinates(p.x, p.y);
	}
	_H3API_ INT32 H3CombatManager::SquareAtCoordinates(INT32 x, INT32 y) const
	{
		return THISCALL_3(INT32, 0x464380, this, x, y);
	}
	_H3API_ H3CombatMonster* H3CombatManager::GetResurrectionTarget(INT32 coordinate, INT32 caster_kind)
	{
		return THISCALL_4(H3CombatMonster*, 0x5A3FD0, this, currentActiveSide, coordinate, caster_kind);
	}
	_H3API_ H3CombatMonster* H3CombatManager::GetAnimateDeadTarget(INT32 coordinate)
	{
		return THISCALL_3(H3CombatMonster*, 0x5A4260, this, currentActiveSide, coordinate);
	}
	_H3API_ INT32 H3CombatManager::NextCreatureToMove()
	{
		return THISCALL_2(int, 0x464C60, this, 1);
	}
	_H3API_ BOOL8 H3CombatManager::IsHiddenBattle()
	{
		return THISCALL_1(BOOL8, 0x46A080, this);
	}
	_H3API_ BOOL8 H3CombatManager::IsBattleOver()
	{
		return THISCALL_1(BOOL8, 0x465410, this);
    }
    _H3API_ VOID H3CombatManager::ApplyAnimationToLastHitArmy(INT32 animationIndex, BOOL resetAnimationWhenDone)
    {
        THISCALL_3(BOOL8, 0x468570, this, animationIndex, resetAnimationWhenDone);
    }
	_H3API_ VOID H3CombatManager::AddNecromancyRaisedCreature(INT32 side)
	{
		THISCALL_2(VOID, 0x469B00, this, side);
	}
	_H3API_ VOID H3CombatManager::Refresh()
	{
		Refresh(1, 0, 1);
	}
	_H3API_ VOID H3CombatManager::Refresh(BOOL redrawScreen, INT timeDelay, BOOL redrawBackground)
	{
		THISCALL_7(VOID, 0x493FC0, this, redrawScreen, 0, 0, timeDelay, redrawBackground, 0);
	}
	_H3API_ VOID H3CombatManager::RefreshCreatures()
	{
		THISCALL_1(VOID, 0x495770, this);
	}
	_H3API_ VOID H3CombatManager::ShadeSquare(INT32 index)
	{
		if (index < 0 || index > 187)
			return;
		H3CombatSquare* sq = &squares[index];
		CCellShdPcx->DrawToPcx16(0, 0, 0x2D, 0x34, drawBuffer, sq->left, sq->top, TRUE); // copied from 0x4935B9 and below
	}
	_H3API_ BOOL8 H3CombatManager::IsHumanTurn()
	{
		return isHuman[currentActiveSide];
	}
	_H3API_ VOID H3CombatManager::AddStatusMessage(LPCSTR message, BOOL permanent)
	{
		THISCALL_4(VOID, 0x4729D0, dlg, message, permanent, 0);
	}
	_H3API_ VOID H3CombatManager::PlayMagicAnimation(INT32 id, H3CombatCreature* target, INT32 timeStep, BOOL8 show_hit)
	{
		THISCALL_5(VOID, 0x4963C0, this, id, target, timeStep, show_hit);
	}
    _H3API_ VOID H3CombatManager::ReportDamageDone(LPCSTR attackerName, INT32 numAttackers, INT32 damageDone, H3CombatCreature* target, INT32 killedCount)
	{
        THISCALL_6(VOID, 0x469670, this, attackerName, numAttackers, damageDone, target, killedCount);
	}
	_H3API_ BOOL8 H3CombatManager::ShouldCastSpellAfterHit(INT32 spellId, INT32 side, H3CombatCreature* target)
	{
		return THISCALL_6(BOOL8, 0x5A8950, this, spellId, side, target, 1, 1);
	}
	_H3API_ VOID H3CombatManager::ResurrectTarget(H3CombatCreature* target, INT32 hitPoints, INT32 isTemporary)
	{
		THISCALL_4(VOID, 0x5A7870, this, target, hitPoints, isTemporary);
    }
    _H3API_ INT32 H3CombatManager::CalculateSpellDamageOnTarget(INT32 damage, INT32 spellId, H3Hero* atkHero, H3Hero* defHero, H3CombatCreature* target, BOOL showLog)
    {
        return THISCALL_7(INT32, 0x5A7BF0, this, damage, spellId, atkHero, defHero, target, showLog);
    }
	_H3API_ H3CombatMonster* H3CombatManager::SummonCreature(INT32 side, INT32 creatureId, INT32 amount, INT32 position, INT32 redrawAnimation, BOOL redraw)
	{
		return THISCALL_7(H3CombatMonster*, 0x479A30, this, side, creatureId, amount, position, redrawAnimation, redraw);
	}
	_H3API_ H3CombatMonster* H3CombatManager::GetSummonDemonTarget(INT32 side, INT32 coordinate)
	{
		return THISCALL_3(H3CombatMonster*, 0x5A4150, this, side, coordinate);
	}
	_H3API_ VOID H3CombatManager::RaiseDemon(H3CombatCreature* caster, H3CombatCreature* target)
	{
		THISCALL_3(VOID, 0x5A76A0, this, caster, target);
	}
	_H3API_ BOOL8 H3CombatManager::CanApplyCreatureSpell(INT32 spell_id, INT32 creature_side, H3CombatCreature* target)
	{
		return THISCALL_6(BOOL8, 0x5A8950, this, spell_id, creature_side, target, 1, 1); // the last 2 parameters are always 1 and 1
	}
	_H3API_ VOID H3CombatManager::DrawRay(BOOL redraw, INT startX, INT startY, INT dstX, INT dstY, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay)
	{
		THISCALL_18(VOID, 0x5A5F30, this, redraw, startX, startY, dstX, dstY, allowBranches, randomnessRange, startThickness, endThickness, color565, amplitude, arching, rayStraightness, smoothness, pathRandomness, timeDelay, 0);
	}
	_H3API_ VOID H3CombatManager::DrawRay(BOOL redraw, H3CombatCreature* start, H3CombatCreature* end, INT allowBranches, INT randomnessRange, INT startThickness, INT endThickness, WORD color565, INT amplitude, INT arching, INT rayStraightness, INT smoothness, BOOL pathRandomness, INT timeDelay)
	{
		DrawRay(redraw, start->GetX(), start->GetY(), end->GetX(), end->GetY(), allowBranches, randomnessRange, startThickness, endThickness, color565, amplitude, arching, rayStraightness, smoothness, pathRandomness, timeDelay);
	}
	_H3API_ VOID H3CombatManager::AnimateMassSpell(INT32 animation_id, BOOL8 affects_both_sides)
	{
		THISCALL_4(VOID, 0x5A6AD0, this, massSpellTarget, animation_id, affects_both_sides);
	}
	_H3API_ INT32 H3CombatManager::Close(H3Msg& msg)
	{
		msg.command = eMsgCommand(0x4000);
		msg.subtype = eMsgSubtype(1);
		return 2;
	}

	_H3API_ BOOL H3CombatManager::CanSummonOrClone() const
	{
		INT i = 0;
		const H3CombatMonster* mon = stacks[currentActiveSide];
		while (mon->type != eCreature::UNDEFINED)
		{
			if (!mon->numberAlive && mon->info.cannotMove && mon->IsSummon())
				break;
			++mon;
			if (++i >= 20)
				return FALSE;
		}
		return TRUE;
	}

} /* namespace h3 */
