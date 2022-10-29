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
#include "h3api/H3Constants/H3CstCreatures.hpp"

namespace h3
{
	_H3API_DECLARE_(Army);
	struct H3Hero;
	struct H3MapitemMonster;

#pragma pack(push, 4)
	/** @brief The arrangement of 7 creatures on various H3 structures*/
	struct H3Army
	{
		_H3API_SIZE_(0x38);
		_H3API_CTOR_DTOR_(0x44A750, 0x44A750);

		struct iterator
		{
		protected:
			INT32* m_type;
		public:
			_H3API_ iterator(INT32* type);
			_H3API_ iterator& operator*();
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ BOOL operator==(const iterator& other);
			_H3API_ BOOL operator!=(const iterator& other);
			_H3API_ iterator& operator=(const iterator& other);
			_H3API_ BOOL operator!() const;

			_H3API_ INT32& Type();
			_H3API_ INT32  Type() const;
			_H3API_ INT32& Count();
			_H3API_ INT32  Count() const;
		};
		/** @brief [00] eCreatures*/
		INT32 type[7];
		/** @brief [1C]*/
		INT32 count[7];

		_H3API_ H3Army();
		_H3API_ H3Army(const H3Army& other);
		// * add amount creature of type to slot
		_H3API_ BOOL AddStack(INT32 type, INT32 amount, INT32 slot);
		// * Split fromStack based on fraction denominator to toStack
		// * fraction = 2 cuts in half
		_H3API_ VOID SplitFromStackToStack(INT32 fromStack, INT32 toStack, INT32 fraction);
		// * the first type[] index to hold no creature
		_H3API_ INT32 FirstFreeSlot();
		// * the slot position of the n-th existing stack
		_H3API_ INT32 FindExistingByIndex(INT32 index);
		// * the number of existing stacks
		_H3API_ INT32 GetStackCount();
		// * Total number of creatures
		_H3API_ INT32 GetCreaturesCount();
		// * has at least one creature cre
		_H3API_ BOOL8 HasCreatureType(INT32 cre);
		// * not empty
		_H3API_ BOOL HasCreatures();
		// * remove all contents
		_H3API_ VOID Clear();
		// * clear contents of stack #0-6
		_H3API_ VOID Clear(INT stack);
		// * removes contents and gives creatures
		_H3API_ VOID ClearAndGive(INT type, INT count);
		// * checks if all stacks are flagged as undead
		_H3API_ BOOL8 IsUndeadArmy();
		// * the number of different creature alignments in an army
		// * the creature array can be empty
		_H3API_ INT32 NumberAlignments(INT8(&towns)[9]);
		// * AI value total for army
		_H3API_ INT32 GetArmyValue();
		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ H3Army& operator=(const H3Army& other);
		_H3API_ iterator operator[](UINT index);
		/**
		 * @brief Swaps two stacks positions
		 * @param from first stack to swap
		 * @param to second stack to swap
		 */
		_H3API_ VOID Swap(UINT from, UINT to);
		/**
		 * @brief Returns the army split when facing wandering creatures on the map
		 * @param p The location of the battle to take place
		 * @param hero The current selected hero
		 * @param type0 The main type of creature
		 * @param amount0 The main amount of creature
		 * @param type1 Secondary creature type (Pyramid = DIAMOND_GOLEM)
		 * @param amount1 Secondary creature amount (Pyramid = 20)
		 * @param stacks1 Secondary creature number of stacks (Pyramid = 2)
		 * @param type2 Tertiary creature type (never used)
		 * @param amount2 Tertiary creature amount (never used)
		 * @param stacks2 Tertiary creature stacks (never used)
		 * @return H3Army split according to the fight specifics
		 */
		_H3API_ static H3Army SplitCreatures(const H3Point& p, H3Hero* hero, INT32 type0, INT32 amount0,
			INT32 type1 = -1, INT32 amount1 = 0, INT32 stacks1 = 0,
			INT32 type2 = -1, INT32 amount2 = 0, INT32 stacks2 = 0);
	};
	_H3API_ASSERT_SIZE_(H3Army);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
