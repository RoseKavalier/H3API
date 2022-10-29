//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Heroes/H3Hero.hpp"
#include "h3api/H3Managers/H3AdventureManager.hpp"
#include "h3api/H3GameData/H3Main.hpp"
#include "h3api/H3Artifacts/H3ArtifactSetup.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"
#include "h3api/H3Constants/H3CstObjects.hpp"
#include "h3api/H3Dialogs/H3Messagebox.hpp"
#include "h3api/H3GameData/H3Spell.hpp"
#include "h3api/H3Assets/H3SecondarySkillInfo.hpp"
#include "h3api/H3Combat/H3CombatCreature.hpp"
#include "h3api/H3Constants/H3CstHeroes.hpp"

namespace h3
{
	_H3API_ INT32 H3Hero::MaxLandMovement()
	{
		return THISCALL_2(INT32, 0x4E4C00, this, 0);
	}
	_H3API_ INT32 H3Hero::MaxWaterMovement()
	{
		return THISCALL_2(INT32, 0x4E4C00, this, 1);
	}
	_H3API_ INT32 H3Hero::CalcMaxMovement()
	{
		return THISCALL_1(INT32, 0x4E5000, this);
	}
	_H3API_ VOID H3Hero::GiveArtifact(const H3Artifact& art, INT32 slot)
	{
		THISCALL_3(VOID, 0x4E2C70, this, &art, slot);
	}
	_H3API_ VOID H3Hero::GiveArtifact(const H3Artifact& art)
	{
		THISCALL_4(void, 0x4E32E0, this, &art, 0, 0);
	}
	_H3API_ VOID H3Hero::GiveBackpackArtifact(const H3Artifact& art, INT32 index)
	{
		THISCALL_3(void, 0x4E3200, this, &art, index);
	}
	_H3API_ VOID H3Hero::LearnSecondarySkill(INT32 id, INT32 increase)
	{
		return THISCALL_3(VOID, 0x4E2540, this, id, increase);
	}
	_H3API_ INT32 H3Hero::GetSpellExpertise(INT32 spell_id, INT32 special_terrain)
	{
		return THISCALL_3(INT32, 0x4E52F0, this, spell_id, special_terrain);
	}
	_H3API_ BOOL8 H3Hero::HasCreatureType(INT32 type)
	{
		return army.HasCreatureType(type);
	}
	_H3API_ INT32 H3Hero::GetSpellSpecialtyEffect(INT32 spell_id, INT32 creature_level, INT32 base_damage)
	{
		return THISCALL_4(INT32, 0x4E6260, this, spell_id, creature_level, base_damage);
	}
	_H3API_ INT32 H3Hero::GetSorceryEffect(INT32 spell_id, INT32 base_damage, H3CombatCreature* mon)
	{
		return THISCALL_4(INT32, 0x4E59D0, this, spell_id, base_damage, mon);
	}
	_H3API_ INT32 H3Hero::GetRealSpellDamage(INT32 base_damage, H3CombatCreature* mon, INT32 spell_id, H3Hero* enemy)
	{
		INT32 dmg = GetSorceryEffect(spell_id, base_damage, mon);
		dmg = FASTCALL_3(INT32, 0x44B180, dmg, spell_id, mon->type); // golem-style resistance
		return mon->GetProtectiveSpellEffect(dmg, spell_id);
	}
	_H3API_ INT32 H3Hero::GetSpecialTerrain()
	{
		return THISCALL_1(INT32, 0x4E5130, this);
	}
	_H3API_ INT32 H3Hero::GetSpecialSpellTerrain()
	{
		return THISCALL_1(INT32, 0x4E5210, this);
	}
	_H3API_ BOOL H3Hero::HasSpell(INT32 spell)
	{
		return learnedSpells[spell] | availableSpell[spell];
	}
	_H3API_ VOID H3Hero::BuildCombinationArtifact(INT32 combo_id)
	{
		THISCALL_3(VOID, 0x4DC1A0, this, combo_id, -1);
	}
	_H3API_ BOOL H3Hero::UnlearnSkill(INT32 id)
	{
		if (secSkill[id])
		{
			secSkill[id] = 0;
			INT32 pos = secSkillPosition[id];
			secSkillPosition[id] = 0;
			for (INT32 i = 0; i < 28; i++)
			{
				if (secSkillPosition[i] > pos)
					secSkillPosition[i] -= 1;
			}
			secSkillCount -= 1;
			return TRUE;
		}
		return FALSE;
	}
	_H3API_ VOID H3Hero::RecalculateMovement()
	{
		H3AdventureManager* adv = H3AdventureManager::Get();
		adv->movementCalculated = 0;
		adv->movementCalculated1 = 0;
		if (dest_x != -1)
		{
			adv->MovementCalculations(H3Position::Pack(dest_x, dest_y, dest_z));
			adv->MakeHeroPath();
		}
	}
	_H3API_ BOOL8 H3Hero::CanFlyOnTile()
	{
		return THISCALL_1(BOOL8, 0x4E5F50, this);
	}
	_H3API_ INT32 H3Hero::GetMovementCost(INT32 orientation, UINT32 mixedPos)
	{
		return FASTCALL_4(INT32, 0x4B1620, this, orientation, mixedPos, movement);
	}
	_H3API_ INT32 H3Hero::SSkillsLeftToLearn()
	{
		INT32 known_skills = 0;
		for (INT32 i = 0; i < 28; i++)
			known_skills += secSkill[i];

		INT32 maxSkills = 3 * ByteAt(0x4E256A); // usually 3 * 8

		if (known_skills >= maxSkills)
			return 0;

		// hero has not learned all of his available skills
		INT32 skills_can_be_learned = 0;

		INT32 sslevel;
		H3Main* main = H3Main::Get();

		for (INT32 i = 0; i < 28; i++)
		{
			sslevel = secSkill[i];
			if (!main->bannedSkills[i] || sslevel > 0)
				skills_can_be_learned += 3 - sslevel;
		}
		// only necropolis heroes can learn necromancy, unless hero already has it
		if (hero_class != eHeroClass::NECROMANCER && hero_class != eHeroClass::DEATH_KNIGHT && secSkill[eSecondary::NECROMANCY] == 0 && !main->bannedSkills[eSecondary::NECROMANCY])
			skills_can_be_learned -= 3;
		// necropolis heroes cannot learn leadership, unless hero already has it
		if ((hero_class == eHeroClass::NECROMANCER || hero_class == eHeroClass::DEATH_KNIGHT) && secSkill[eSecondary::LEADERSHIP] == 0 && !main->bannedSkills[eSecondary::LEADERSHIP])
			skills_can_be_learned -= 3;
		// dungeon heroes cannot learn water magic, unless hero already has it
		if ((hero_class == eHeroClass::OVERLORD || hero_class == eHeroClass::WARLOCK) && secSkill[eSecondary::WATER_MAGIC] == 0 && !main->bannedSkills[eSecondary::WATER_MAGIC])
			skills_can_be_learned -= 3;
		// rampart heroes cannot learn fire magic, unless hero already has it
		if ((hero_class == eHeroClass::RANGER || hero_class == eHeroClass::DRUID) && secSkill[eSecondary::FIRE_MAGIC] == 0 && !main->bannedSkills[eSecondary::FIRE_MAGIC])
			skills_can_be_learned -= 3;

		skills_can_be_learned = std::min(maxSkills - known_skills, skills_can_be_learned);
		skills_can_be_learned = std::max(skills_can_be_learned, 1);
		return skills_can_be_learned - 1; // -1 because it's already included in formula for level to go to
	}
	_H3API_ BOOL H3Hero::WearsArtifact(INT id)
	{
		return THISCALL_2(BOOL, 0x4D9460, this, id);
	}
	_H3API_ INT32 H3Hero::GetHeroPrimary(INT primary)
	{
		return THISCALL_2(INT32, 0x5BE240, this, primary);
	}
	_H3API_ INT32 H3Hero::HasSimilarCreature(INT id)
	{
		return FASTCALL_2(INT32, 0x4A7230, this, id);
	}
	_H3API_ LPCSTR H3Hero::GetHeroClassName()
	{
		return THISCALL_1(LPCSTR, 0x4D91E0, this);
	}
	_H3API_ VOID H3Hero::ShowDialog() const
	{
		return FASTCALL_4(VOID, 0x4E1A70, id, 0, 1, 1);
	}
	_H3API_ VOID H3Hero::ShowDialog(BOOL32 dismissable, BOOL32 not_in_town, BOOL8 right_click)
	{
		return FASTCALL_4(VOID, 0x4E1A70, id, dismissable, not_in_town, right_click);
	}
	_H3API_ INT H3Hero::GetPower() const
	{
		return THISCALL_1(INT32, 0x427650, this);
	}
	_H3API_ BOOL8 H3Hero::CanReplaceArtifact(INT32 id, INT32 slot) const
	{
		return THISCALL_3(BOOL8, 0x4E2AB0, this, id, slot);
	}
	_H3API_ BOOL8 H3Hero::CanPlaceArtifact(INT32 id, INT32 slot) const
	{
		return THISCALL_3(BOOL8, 0x4E27C0, this, id, slot);
	}
	_H3API_ VOID H3Hero::RemoveArtifact(INT32 slot)
	{
		THISCALL_2(VOID, 0x4E2E40, this, slot);
	}
	_H3API_ VOID H3Hero::RemoveBackpackArtifact(INT32 slot)
	{
		THISCALL_2(VOID, 0x4E2FC0, this, slot);
	}
	_H3API_ VOID H3Hero::ShowCreatureDialog(INT32 slot, BOOL rightClick)
	{
		THISCALL_9(VOID, 0x4C6910, H3Main::Get(), &army, slot, this, 0, 119, 20, 0, rightClick);
	}
	_H3API_ VOID H3Hero::ShowSpellInfo(INT32 spell, BOOL RMB)
	{
		INT32 expertise = GetSpellExpertise(spell, GetSpecialSpellTerrain());
		LPCSTR desc = H3Spell::Get()[spell].description[expertise];
		if (RMB)
			H3Messagebox::RMB(desc, H3PictureCategories::Spell(eSpell(spell)));
		else
			H3Messagebox::Show(desc, H3PictureCategories::Spell(eSpell(spell)));
	}
	_H3API_ VOID H3Hero::ShowSSkillInfo(INT32 skill, BOOL RMB)
	{
		INT32 lvl = secSkill[skill];
		if (lvl == 0)
			lvl = 1;
		LPCSTR desc = H3SecondarySkillInfo::Get()[skill].description[lvl];
		if (RMB)
			H3Messagebox::RMB(desc, H3PictureCategories::SecSkill(eSecondary(skill), eSecSkillLevel(lvl)));
		else
			H3Messagebox::Show(desc, H3PictureCategories::SecSkill(eSecondary(skill), eSecSkillLevel(lvl)));
	}
	_H3API_ VOID H3Hero::ShowPSkillInfo(INT32 skill, BOOL RMB)
	{
		INT32 value = GetHeroPrimary(skill) | 0x100000; // removes the '+' in front of number
		FASTCALL_12(VOID, 0x4F6C00, StrAt(0x6A75A8 + 4 * skill),
			RMB ? 4 : 1, -1, -1, 34, value, -1, 0, -1, 0, -1, 0);
	}
	_H3API_ BOOL H3Hero::HasAllCombinationParts(INT slot)
	{
		// game code uses bitfields to determine this
		// this code is flexible in the sense that it doesn't
		// rely on unknown-at-compile-time bitfield length
		// the downside is that it is less efficient

		INT32 artId = bodyArtifacts[slot].id;
		if (id == -1)
			return FALSE;

		H3ArtifactSetup* art_setups = H3ArtifactSetup::Get();

		INT32 comboId = art_setups[artId].comboID;
		if (comboId != -1) // it's already a combination artifact
			return FALSE;
		comboId = art_setups[artId].combinationArtifactId;
		if (comboId == -1) // not part of a combination
			return FALSE;

		INT32 numArts = H3ArtifactCount::Get();

		for (INT32 i = 0; i < numArts; ++i)
		{
			if (art_setups[i].combinationArtifactId == comboId)
			{
				if (!WearsArtifact(i))
					return FALSE;
			}
		}

		return TRUE;
	}
	_H3API_ VOID H3Hero::DisassembleCombinationArtifact(INT slot)
	{
		INT32 artId = bodyArtifacts[slot].id;
		if (artId == -1)
			return;
		H3ArtifactSetup* art_setups = H3ArtifactSetup::Get();
		INT32 comboId = art_setups[artId].comboID;
		if (comboId == -1) // not a combo artifact
			return;
		RemoveArtifact(slot);
		INT32 numArts = H3ArtifactCount::Get();
		for (INT32 i = 0; i < numArts; ++i)
		{
			if (art_setups[i].combinationArtifactId == comboId)
			{
				H3Artifact art(i, -1);
				GiveArtifact(art);
			}
		}
	}
	_H3API_ INT32 H3Hero::CalculateSpellCost(INT spell, H3Army* opponentArmy, INT specialTerrain)
	{
		return THISCALL_4(INT32, 0x4E54B0, this, spell, opponentArmy, specialTerrain);
	}
	_H3API_ INT32 H3Hero::CalculateAdventureMapSpellCost(INT spell)
	{
		return CalculateSpellCost(spell, nullptr, GetSpecialSpellTerrain());
	}
	_H3API_ VOID H3Hero::RemoveSpellPointsAndRefresh(UINT16 spellPoints)
	{
		THISCALL_2(VOID, 0x4D9540, this, spellPoints);
	}
	_H3API_ VOID H3Hero::UpdateAvailableSpell()
	{
		THISCALL_1(VOID, 0x4D9840, this);
	}
	_H3API_ VOID H3Hero::Hide()
	{
		THISCALL_1(VOID, 0x4D7950, this);
	}
	_H3API_ VOID H3Hero::Show()
	{
		THISCALL_3(VOID, 0x4D7840, this, NH3Objects::eObjectTypes::HERO, id);
	}

	_H3API_ eCreature H3Hero::GetNecromancyCreatureId() const
	{
		return THISCALL_1(eCreature, 0x4E3ED0, this);
	}

	_H3API_ FLOAT H3Hero::GetNecromancyPower(BOOL8 clamp_value) const
	{
		return THISCALL_2(FLOAT, 0x4E3F40, this, clamp_value);
	}

	_H3API_ INT32 H3Hero::GetSpellPointsRestored() const
	{
		return THISCALL_1(INT32, 0x4E41B0, this);
	}

	_H3API_ INT32 H3Hero::GetLuckBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const
	{
		return THISCALL_4(INT32, 0x4E3930, this, enemy_hero, is_cursed_ground, clamp_value);
	}

	_H3API_ INT32 H3Hero::GetMoraleBonus(H3Hero* enemy_hero, BOOL8 is_cursed_ground, BOOL8 clamp_value) const
	{
		return THISCALL_4(INT32, 0x4E3C20, this, enemy_hero, is_cursed_ground, clamp_value);
	}

	_H3API_ INT32 H3Hero::GetScoutingRadius() const
	{
		return THISCALL_1(INT32, 0x4E42E0, this);
	}

	_H3API_ FLOAT H3Hero::GetArcheryPower() const
	{
		return THISCALL_1(FLOAT, 0x4E43D0, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetOffensePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4520, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetArmorerPower() const
	{
		return THISCALL_1(FLOAT, 0x4E4580, this); // loads to FPU
	}

	_H3API_ INT32 H3Hero::GetGeneratedGold() const
	{
		return THISCALL_1(INT32, 0x4E4600, this);
	}

	_H3API_ FLOAT H3Hero::GetEagleEyePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4690, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetDiplomacyPower() const
	{
		return THISCALL_1(FLOAT, 0x4E47F0, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetResistancePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4950, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetLearningPower() const
	{
		return THISCALL_1(FLOAT, 0x4E4AB0, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetIntelligencePower() const
	{
		return THISCALL_1(FLOAT, 0x4E4B20, this); // loads to FPU
	}

	_H3API_ FLOAT H3Hero::GetFirstAidPower() const
	{
		return THISCALL_1(FLOAT, 0x4E4B90, this); // loads to FPU
	}
} /* namespace h3 */
