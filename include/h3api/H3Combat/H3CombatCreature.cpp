//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Combat/H3CombatCreature.hpp"
#include "h3api/H3Managers/H3CombatManager.hpp"

namespace h3
{
    _H3API_	LPCSTR H3CombatCreature::GetCreatureName() const
    {
        return info.GetCreatureName(numberAlive);
    }
    _H3API_ INT32 H3CombatCreature::GetSecondSquare() const
    {
        return THISCALL_1(INT32, 0x4463C0, this);
    }
    _H3API_ INT32 H3CombatCreature::GetStackSpeed() const
    {
        return THISCALL_1(INT32, 0x4489F0, this);
    }
    _H3API_ INT32 H3CombatCreature::HexRelativePosition(INT32 considered_hex, INT32 relative_orientation) const
    {
        return THISCALL_3(INT32, 0x524280, this, considered_hex, relative_orientation);
    }
    _H3API_ BOOL H3CombatCreature::IsIncapacitated() const
    {
        return activeSpellDuration[eSpell::BLIND]
            || activeSpellDuration[eSpell::STONE]
            || activeSpellDuration[eSpell::PARALYZE]
            || info.cannotMove;
    }
    _H3API_ BOOL H3CombatCreature::IsDefending() const
    {
        return info.defending;
    }
    _H3API_ BOOL H3CombatCreature::IsDone() const
    {
        return info.done;
    }
    _H3API_ BOOL H3CombatCreature::IsClone() const
    {
        return info.clone;
    }
    _H3API_ BOOL H3CombatCreature::IsSiege() const
    {
        return info.siegeWeapon;
    }
    _H3API_ BOOL H3CombatCreature::IsSummon() const
    {
        return info.summon;
    }
    _H3API_ BOOL H3CombatCreature::HadMorale() const
    {
        return info.morale;
    }
    _H3API_ BOOL H3CombatCreature::IsWaiting() const
    {
        return info.waiting;
    }
    _H3API_ BOOL H3CombatCreature::HasMoved() const
    {
        return info.done;
    }
    _H3API_ INT32 H3CombatCreature::Index() const
    {
        return sideIndex + 21 * side;
    }
    _H3API_ VOID H3CombatCreature::ShowStatsDialog(BOOL right_click) const
    {
        THISCALL_3(VOID, 0x468440, H3CombatManager::Get(), this, right_click);
    }
    _H3API_ INT32 H3CombatCreature::GetSide() const
    {
        return THISCALL_1(INT, 0x43FE60, this);
    }
    _H3API_ H3Hero* H3CombatCreature::GetOwner() const
    {
        return THISCALL_1(H3Hero*, 0x4423B0, this);
    }
    _H3API_ INT32 H3CombatCreature::GetProtectiveSpellEffect(INT32 damage, INT32 spellID) const
    {
        return STDCALL_3(INT32, 0x5A7EC0, damage, spellID, this);
    }
    _H3API_ INT32 H3CombatCreature::MagicMirrorEffect() const
    {
        return THISCALL_1(INT32, 0x448510, this);
    }
    _H3API_ INT32 H3CombatCreature::ApplyPhysicalDamage(INT32 amount)
    {
        return THISCALL_2(INT32, 0x443DB0, this, amount);
    }
    _H3API_ VOID H3CombatCreature::ApplySpell(INT32 spellId, INT32 spellPower, INT32 schoolLevel, H3Hero* hero)
    {
        return THISCALL_5(VOID, 0x444610, this, spellId, spellPower, schoolLevel, hero);
    }
    _H3API_ BOOL8 H3CombatCreature::ApplyAfterHitSpell(H3CombatCreature* defender)
    {
        return THISCALL_2(BOOL8, 0x440220, this, defender);
    }
    _H3API_ VOID H3CombatCreature::ApplyAfterHitAbility(H3CombatCreature* defender, INT32 damage, INT32 killed, INT32 totalDefenderHp)
    {
        THISCALL_5(VOID, 0x4408E0, this, defender, damage, killed, totalDefenderHp);
    }
    _H3API_ BOOL8 H3CombatCreature::CanReceiveSpell(INT32 spellId) const
    {
        return FASTCALL_2(BOOL8, 0x4477A0, spellId, this);
    }
    _H3API_ BOOL H3CombatCreature::CanCastSpellAtEmptyHex(INT32 hexId) const
    {
        return THISCALL_2(BOOL, 0x4470F0, this, hexId);
    }
    _H3API_ BOOL8 H3CombatCreature::MoveToHex(INT32 hexId)
    {
        return THISCALL_3(BOOL8, 0x445A30, this, hexId, 0);
    }
    _H3API_ BOOL8 H3CombatCreature::UseEnchanters()
    {
        return THISCALL_1(BOOL8, 0x447D00, this);
    }
    _H3API_ INT32 H3CombatCreature::GetX() const
    {
        return THISCALL_1(INT32, 0x446380, this);
    }
    _H3API_ INT32 H3CombatCreature::GetY() const
    {
        return THISCALL_1(INT32, 0x446350, this);
    }
	_H3API_ INT32 H3CombatCreature::CurrentHitPoints() const
	{
        return info.hitPoints - healthLost;
	}
	_H3API_ INT32 H3CombatCreature::MaxHitPoints() const
	{
        return info.hitPoints;
	}

} /* namespace h3 */
