//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3AdventureMap/H3MapCreatureBank.hpp"
#include "h3api/H3GameData/H3Main.hpp"

namespace h3
{
	_H3API_ BOOL H3CreatureBank::HasUpgradedStack()
	{
		return guardians.type[0] != guardians.type[2];
	}
	_H3API_ VOID H3CreatureBank::SetupBank(INT32 type, INT32 level)
	{
		H3CreatureBankState* cbs = &H3CreatureBankSetup::Get()[type].states[level];
		guardians = cbs->guardians;
		resources = cbs->resources;
		creatureRewardType = cbs->creatureRewardType;
		creatureRewardCount = cbs->creatureRewardCount;

		const INT32 stacks = guardians.GetStackCount();
		INT32 stack_to_split;
		INT32 first_free_slot;
		INT32 fractions;
		switch (stacks)
		{
		case 1:
			fractions = 5;
			stack_to_split = 0;
			while (fractions > 1)
			{
				first_free_slot = guardians.FirstFreeSlot();
				if (first_free_slot != -1)
					guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);
				fractions--;
			}
			break;
		case 2:
			stack_to_split = 1;
			fractions = 2;
			first_free_slot = guardians.FirstFreeSlot();
			if (first_free_slot != -1)
				guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);

			fractions = 3;
			stack_to_split = 0;
			while (fractions > 1)
			{
				first_free_slot = guardians.FirstFreeSlot();
				if (first_free_slot != -1)
					guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);
				fractions--;
			}
			break;
		case 3:
			fractions = 2; // split in 2
			stack_to_split = 1; // stack 1 is first split
			first_free_slot = guardians.FirstFreeSlot();
			if (first_free_slot != -1)
				guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);

			stack_to_split = 0; // then stack 0 is split
			first_free_slot = guardians.FirstFreeSlot();
			if (first_free_slot != -1)
				guardians.SplitFromStackToStack(stack_to_split, first_free_slot, fractions);
			break;
		default:
			break;
		}
	}
	_H3API_ VOID H3CreatureBank::UpgradeStack(BOOL upg)
	{
		if (upg) // in code there are additional checks for game type (RoE) and creature (4 Elementals)
		{
			if (THISCALL_1(char, 0x47AA50, guardians.type[0])) // creature has upgrade?
				guardians.type[2] = THISCALL_1(INT32, 0x47AAD0, guardians.type[0]);
		}
		else
			guardians.type[2] = guardians.type[0];
	}
	_H3API_ H3CreatureBank* H3MapitemCreatureBank::Get()
	{
		return Get(H3Main::Get());
	}
	_H3API_ H3CreatureBank* H3MapitemCreatureBank::Get(H3Main* main)
	{
		return &main->creatureBanks[id];
	}
	_H3API_ H3PlayersBitfield H3MapitemCreatureBank::GetVisiters()
	{
		return H3PlayersBitfield(visited);
	}
	_H3API_ VOID H3MapitemCreatureBank::SetVisited(const H3PlayersBitfield& players)
	{
		visited = players.bits;
	}
} /* namespace h3 */
