//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Creatures/H3Army.hpp"
#include "h3api/H3Heroes/H3Hero.hpp"
#include "h3api/H3Utilities/H3Random.hpp"
#include "h3api/H3Creatures/H3CreatureInformation.hpp"
#include "h3api/H3GameData/H3Main.hpp"
#include "h3api/H3Creatures/H3Creature.hpp"

namespace h3
{
	_H3API_ H3Army::iterator::iterator(INT32* type) :
		m_type(type)
	{
	}
	_H3API_ H3Army::iterator& H3Army::iterator::operator*()
	{
		return *this;
	}
	_H3API_ H3Army::iterator& H3Army::iterator::operator++()
	{
		++m_type;
		return *this;
	}
	_H3API_ H3Army::iterator H3Army::iterator::operator++(int)
	{
		iterator it(m_type);
		++m_type;
		return it;
	}
	_H3API_ BOOL H3Army::iterator::operator==(const iterator& other)
	{
		return m_type == other.m_type;
	}
	_H3API_ H3Army::iterator& H3Army::iterator::operator=(const iterator& other)
	{
		Type() = other.Type();
		Count() = other.Count();
		return *this;
	}
	_H3API_ BOOL H3Army::iterator::operator!=(const iterator& other)
	{
		return m_type != other.m_type;
	}
	_H3API_ BOOL H3Army::iterator::operator!() const
	{
		return *m_type == -1;
	}
	_H3API_ INT32& H3Army::iterator::Type()
	{
		return *m_type;
	}
	_H3API_ INT32 H3Army::iterator::Type() const
	{
		return *m_type;
	}
	_H3API_ INT32& H3Army::iterator::Count()
	{
		return m_type[7];
	}
	_H3API_ INT32 H3Army::iterator::Count() const
	{
		return m_type[7];
	}
	_H3API_ H3Army::H3Army()
	{
		THISCALL_1(H3Army&, 0x44A750, this);
	}
	_H3API_ H3Army::H3Army(const H3Army& other)
	{
		(*this) = other;
	}
	_H3API_ BOOL H3Army::AddStack(INT32 type, INT32 amount, INT32 slot)
	{
		return THISCALL_4(BOOL, 0x44A9B0, this, type, amount, slot);
	}
	_H3API_ VOID H3Army::SplitFromStackToStack(INT32 fromStack, INT32 toStack, INT32 fraction)
	{
		INT32 num = count[fromStack] / fraction;
		count[fromStack] -= num;
		AddStack(type[fromStack], num, toStack);
	}
	_H3API_ INT32 H3Army::FirstFreeSlot()
	{
		INT32 r = 0;
		for (INT32 i = 0; i < 7; i++)
		{
			if (type[i] != -1)
				r++;
			else
				return r;
		}
		return -1;
	}
	_H3API_ INT32 H3Army::FindExistingByIndex(INT32 index)
	{
		if (index >= 0 && index < 7)
		{
			INT32 j = 0;
			for (INT32 i = 0; i < 7; i++)
			{
				if (type[i] != -1)
					j++;
				if (j == index)
					return i;
			}
		}
		return -1;
	}
	_H3API_ INT32 H3Army::GetStackCount()
	{
		return THISCALL_1(INT32, 0x44A990, this);
	}
	_H3API_ INT32 H3Army::GetCreaturesCount()
	{
		return THISCALL_1(INT32, 0x44AA70, this);
	}
	_H3API_ BOOL8 H3Army::HasCreatureType(INT32 cre)
	{
		return THISCALL_2(BOOL8, 0x44A850, this, cre);
	}
	_H3API_ BOOL H3Army::HasCreatures()
	{
		return THISCALL_1(BOOL, 0x449370, this);
	}
	_H3API_ VOID H3Army::Clear()
	{
		THISCALL_1(VOID, 0x44A750, this);
	}
	_H3API_ VOID H3Army::Clear(INT stack)
	{
		THISCALL_2(VOID, 0x44A830, this, stack);
	}
	_H3API_ VOID H3Army::ClearAndGive(INT type, INT count)
	{
		THISCALL_3(VOID, 0x44A770, this, type, count);
	}
	_H3API_ BOOL8 H3Army::IsUndeadArmy()
	{
		return THISCALL_1(BOOL8, 0x44A7F0, this);
	}
	_H3API_ INT32 H3Army::NumberAlignments(INT8(&towns)[9])
	{
		return THISCALL_2(INT32, 0x44A880, this, &towns);
	}
	_H3API_ INT32 H3Army::GetArmyValue()
	{
		return THISCALL_1(INT32, 0x44A950, this);
	}
	_H3API_ H3Army::iterator H3Army::begin()
	{
		return iterator(type);
	}
	_H3API_ H3Army::iterator H3Army::end()
	{
		return iterator(type + 7);
	}
	_H3API_ H3Army& H3Army::operator=(const H3Army& other)
	{
		for (INT32 i = 0; i < 7; ++i)
		{
			count[i] = other.count[i];
			type[i]  = other.type[i];
		}
		return *this;
	}
	_H3API_ H3Army::iterator H3Army::operator[](UINT index)
	{
		return iterator(type + index);
	}
	_H3API_ VOID H3Army::Swap(UINT from, UINT to)
	{
		std::swap(type[from], type[to]);
		std::swap(count[from], count[to]);
	}

	_H3API_ H3Army H3Army::SplitCreatures(const H3Point& p, H3Hero* hero, INT32 type0, INT32 amount0, INT32 type1 /*= -1*/, INT32 amount1 /*= 0*/, INT32 stacks1 /*= 0*/, INT32 type2 /*= -1*/, INT32 amount2 /*= 0*/, INT32 stacks2 /*= 0*/)
	{
		H3Army split;
		DOUBLE hero_power = hero ? DOUBLE(hero->army.GetArmyValue()) : 0.0;
		INT32 ai_value    = H3CreatureInformation::Get()[type0].aiValue * amount0;
		if (type1 != -1)
			ai_value += H3CreatureInformation::Get()[type1].aiValue * amount1;
		if (type2 != -1)
			ai_value += H3CreatureInformation::Get()[type2].aiValue * amount2;
		INT32 stacks_count = 7;
		/* follows logic in 0x4AC270 */
		DOUBLE* thresholds = reinterpret_cast<DOUBLE*>(0x677708);
		DOUBLE* limit      = reinterpret_cast<DOUBLE*>(0x6776E0);
		DOUBLE ratio       = hero_power / DOUBLE(ai_value);
		do
		{
			if (ratio < *thresholds)
				break;
			--stacks_count;
			--thresholds;
		} while (thresholds > limit);

		H3Random::SeedRestore restore;
		UINT seed = 0x3C907 * p.x + 0x4386D * p.y + 0x4BB5F * p.z + 0x25EA7;
		THISCALL_1(VOID, FuncAt(0x4AC2D6), seed); // catches hdmod's custom seed function if it's there
		INT32 extra_stack = H3Random::Rand(1, 100);
		if (extra_stack <= 20)
			--stacks_count;
		if (extra_stack >= 80 && stacks_count < 7)
			++stacks_count;
		if (type1 != -1)
			stacks_count -= stacks1;
		if (type2 != -1)
			stacks_count -= stacks2;
		if (stacks_count > amount0)
			stacks_count = amount0;
		if (stacks_count < 1)
			stacks_count = 1;

		if (stacks_count > 0)
		{
			INT32 mid_point    = amount0 % stacks_count;
			INT32 stack_amount = amount0 / stacks_count;
			for (INT32 i = 0; i < stacks_count; ++i)
			{
				split.count[i] = stack_amount + (mid_point > i);
				split.type[i]  = type0;
			}
		}
		// upgrade one creature
		INT32 upgrade = H3Random::Rand(1, 100);
		if (H3Creature::HasUpgrade(type0) && stacks_count > 1 && upgrade <= 50 && type1 == -1 && type2 == -1)
			split.type[stacks_count >> 1] = H3Creature::GetUpgrade(type0);
		// split group 1
		if (type1 != -1 && stacks1)
		{
			int mid_point = amount1 % stacks1 + stacks_count;
			int count1    = amount1 / stacks1;
			for (INT32 i = stacks_count; i < stacks_count + stacks1; ++i)
			{
				split.count[i] = count1 + (mid_point > i);
				split.type[i]  = type1;
			}
		}
		// split group 2
		if (type2 != -1 && stacks2)
		{
			int mid_point = amount2 % stacks2 + stacks_count + stacks1;
			int count2 = amount2 / stacks2;
			for (INT32 i = stacks_count + stacks1; i < stacks_count + stacks1 + stacks2; ++i)
			{
				split.count[i] = count2 + (mid_point > i);
				split.type[i] = type2;
			}
		}
		// reorder
		if (type1 != -1 || type2 != -1)
		{
			H3Army copy(split);
			/* 7x7 splitting cases based on number of original stacks vs number of type 2 stacks */
			typedef INT SplitOrder[7];
			typedef SplitOrder Type2SplitOrder[7];
			SplitOrder& order = reinterpret_cast<Type2SplitOrder*>(0x63DF94)[stacks_count][stacks2];
			for (INT32 i = 0; i < 7; ++i)
			{
				split.count[i] = copy.count[order[i]];
				split.type[i]  = copy.type[order[i]];
			}
		}
		return split;
	}

} /* namespace h3 */
