//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base/H3Config.hpp"

namespace h3
{
	_H3API_DECLARE_(Bitfield);
	_H3API_DECLARE_(ObjectMask);
	_H3API_DECLARE_(PlayersBitfield);
	_H3API_DECLARE_(PlayersBitfield32);
	_H3API_DECLARE_(TownsBitfield);
	_H3API_DECLARE_(BuildingsBitfield);
	_H3API_DECLARE_(TerrainBitfield);

#pragma pack(push, 4)

	/**
	 * @brief DWORD used as a bitfield
	 * can be used as an array of bitfields (no bound checking)
	 * for a safer and more developped version with iterators, use H3Bitset
	 */
	struct H3Bitfield
	{
		/**
		 * @brief similar to bitset::reference
		 * holds a pointer to Bitfield start and allows specific operations on indexed bits
		 */
		struct reference
		{
		protected:
			H3Bitfield* m_bitfield;
			UINT32      m_position;
		public:
			_H3API_ reference(H3Bitfield* bitfield);
			_H3API_ reference(H3Bitfield* bitfield, UINT position);
			/**
			 * @brief pre-increment
			 * @return itself, the next reference
			 */
			_H3API_ reference& operator++();
			/**
			 * @brief post-increment
			 * @return a copy of the current reference
			 */
			_H3API_ reference operator++(int);
			/**
			 * @brief flips the current bit
			 * @return itself
			 */
			_H3API_ reference& operator~();
			/**
			 * @brief allows if (reference) condition to be used
			 * @return true if the current bit is set, false otherwise
			 */
			_H3API_ operator BOOL();
			/**
			 * @brief allows if (!reference) condition to be used
			 * @return true if the current bit is not set, false otherwise
			 */
			_H3API_ BOOL operator!();
			/**
			 * @brief set the state of the current bit
			 * @param state true (on) or false (off)
			 */
			_H3API_ VOID operator=(BOOL state);
			/** @brief sets the current bit to true (on)*/
			_H3API_ VOID Set();
			/** @brief sets the current bit to false (off)*/
			_H3API_ VOID Reset();
			/** @brief Flips the current bit*/
			_H3API_ VOID Flip();
		};

	protected:
		UINT m_bf;
	public:
		/**
		 * @brief returns whether bit at position is set or not
		 * @param position can exceed the scope of bitfield, meaning greater than 32 bits
		 * @return true if the specified bit is set
		 */
		_H3API_ BOOL GetState(UINT32 position) const;
		/**
		 * @brief Set the state of the specified bit
		 * @param position can exceed the scope of bitfield, meaning greater than 32 bits
		 * @param state true (on) or false (off)
		 */
		_H3API_ VOID SetState(UINT32 position, BOOL state);
		/**
		 * @brief Sets the underlying DWORD to the specified value*
		 * @param value the new bitfield state
		 */
		_H3API_ VOID Set(UINT32 value);
		/**
		 * @brief Get underlying DWORD value*
		 * @return the current state of the bitfield
		 */
		_H3API_ UINT Get() const;
		/**
		 * @brief flips bit at position*
		 * @param position can exceed the scope of bitfield, meaning greater than 32 bits
		 * @return _H3API_
		 */
		_H3API_ VOID Flip(UINT32 position);
		/**
		 * @brief get reference at position
		 * using reference allows expressions that would otherwise be impossible such as:
		 * Bitfield[33] = true;
		 * @param position can exceed the scope of bitfield, meaning greater than 32 bits
		 * @return a reference to the specified position
		 */
		_H3API_ reference operator[](UINT32 position);
		/**
		 * @brief state of bit at position
		 * @param position can exceed the scope of bitfield, meaning greater than 32 bits
		 * @return true if the bit is set/on, false otherwise
		 */
		_H3API_ BOOL operator()(UINT position);
		/**
		 * @brief the end mask of unusable bits for a bitfield with specified number of bits
		 * @param number_bits the total number of bits in the bitset represented
		 * @return the value of the end mask, that is all bits that are not part of the last 32 bits
		 */
		_H3API_ static UINT Mask(UINT number_bits);
	}; /* H3Bitfield */

	/**
	 * @brief 8x6 mask for properties and drawing of adventure map objects
	 * (0,0) is bottom right corner and corresponds to bit 0
	 * bit increments go left to right and then bottom to top
	 *
	 * 47:(7,5) 46:(6,5) 45:(5,5) 44:(4,5) 43:(3,5) 42:(2,5) 41:(1,5) 40:(0,5)
	 * 39:(7,4) 38:(6,4) 37:(5,4) 36:(4,4) 35:(3,4) 34:(2,4) 33:(1,4) 32:(0,4)
	 * 31:(7,3) 30:(6,3) 29:(5,3) 28:(4,3) 27:(3,3) 26:(2,3) 25:(1,3) 24:(0,3)
	 * 23:(7,2) 22:(6,2) 21:(5,2) 20:(4,2) 19:(3,2) 18:(2,2) 17:(1,2) 16:(0,2)
	 * 15:(7,1) 14:(6,1) 13:(5,1) 12:(4,1) 11:(3,1) 10:(2,1)  9:(1,1)  8:(0,1)
	 *  7:(7,0)  6:(6,0)  5:(5,0)  4:(4,0)  3:(3,0)  2:(2,0)  1:(1,0)  0:(0,0)
	 *
	 */
	struct H3ObjectMask
	{
		union
		{
			H3Bitfield m_bits[2];
			UINT64     m_bitsPacked;
		};

		/** @brief an incrementable structure over the object mask with additional functionality*/
		class iterator
		{
		private:
			H3ObjectMask* m_mask;
			UINT32        m_position;
		public:
			_H3API_ iterator(const iterator& it);
			_H3API_ iterator(H3ObjectMask* mask);
			_H3API_ iterator(H3ObjectMask* mask, UINT32 index);
			/**
			 * @brief pre-increment
			 * @return itself
			 */
			_H3API_ iterator& operator++();
			/**
			 * @brief post-increment
			 * @return a copy of itself before increment
			 */
			_H3API_ iterator operator++(int);
			/**
			 * @brief flips current bit from on to off and vice-versa
			 * @return itself
			 */
			_H3API_ iterator& operator~();
			/**
			 * @brief allows if (iterator) condition to be used
			 * @return BOOL true if the current bit is set, otherwise false
			 */
			_H3API_ operator BOOL() const;
			/**
			 * @brief allows if (!iterator) condition to be used
			 * @return BOOL true if the current bit is not set, otherwise false
			 */
			_H3API_ BOOL operator!() const;
			/**
			 * @brief set the state of the current bit
			 * @param state TRUE/on or FALSE/off
			 */
			_H3API_ VOID operator=(BOOL state);
			/**
			 * @brief Get the state of the current bit
			 * @return BOOL true if the bit is set, false otherwise
			 */
			_H3API_ BOOL GetState() const;
			/**
			 * @brief set the state of the current bit
			 * @param state TRUE/on or FALSE/off
			 */
			_H3API_ VOID SetState(BOOL state);
			/** @brief set the current bit as ON / true*/
			_H3API_ VOID Set();
			/** @brief set the current bit as OFF / false*/
			_H3API_ VOID Reset();
			/** @brief flips current bit from on to off and vice-versa*/
			_H3API_ VOID Flip();
			/**
			 * @brief equality comparison between two iterators
			 * @param it another iterator
			 * @return BOOL whether both iterators are at the same position
			 */
			_H3API_ BOOL operator==(const iterator& it);
			/**
			 * @brief inequality comparison between two iterators
			 * @param it another iterator
			 * @return BOOL whether both iterators are not at the same position
			 */
			_H3API_ BOOL operator!=(const iterator& it);
		};
		/**
		 * @brief copies another object mask state
		 * @param other a second object mask
		 */
		_H3API_ VOID operator=(const H3ObjectMask& other);
		/**
		 * @brief copies 64 bits of data to current state
		 * note that only 48 bits are used, the remaining 16 have no impact whatsoever
		 * @param value the new state of the mask to use
		 */
		_H3API_ VOID operator=(UINT64 value);
		/**
		 * @brief get access to the internal bitfield
		 * Used for Lod-type H3Msk assignment
		 * @param index 0..1
		 * @return H3Bitfield the first or second bitfield of the object
		 */
		_H3API_ H3Bitfield& operator[](UINT index);
		/**
		 * @brief get access to the internal bitfield
		 * @param index 0..1
		 * @return H3Bitfield the first or second bitfield of the object
		 */
		_H3API_ const H3Bitfield& operator[](UINT index) const;
		/**
		 * @brief an incrementable iterator matching H3 access order start
		 * @return iterator for bottom right corner
		 */
		_H3API_ iterator begin();
		/**
		 * @brief an incrementable iterator matching H3 access order end
		 * @return iterator for 6th row (counting from 0)
		 */
		_H3API_ iterator end();
		/**
		 * @brief an iterator to the specified position
		 * allows some extra access e.g.
		 * mask(0) = true;
		 * @param index 0..47 starting from bottom right
		 * @return iterator to specified position
		 */
		_H3API_ iterator operator()(UINT8 index);
		/**
		 * @brief an iterator to the specified coordinates
		 * allows some extra access e.g.
		 * mask(0, 0) = true;
		 * @param column 0..7 counting from right to left
		 * @param row 0..5 counting from bottom to top
		 * @return iterator to specified coordinates
		 */
		_H3API_ iterator operator()(UINT8 column, UINT8 row);
	}; /* H3ObjectMask */

	struct H3PlayersBitfield
	{
		_H3API_SIZE_(1);
		union
		{
			UINT8 bits;
			struct
			{
				BOOL8 red    : 1;
				BOOL8 blue   : 1;
				BOOL8 tan    : 1;
				BOOL8 green  : 1;
				BOOL8 orange : 1;
				BOOL8 purple : 1;
				BOOL8 teal   : 1;
				BOOL8 pink   : 1;
			};
		};

		_H3API_ H3PlayersBitfield();
		_H3API_ H3PlayersBitfield(UINT8 player_bits);
		_H3API_ H3PlayersBitfield(const H3PlayersBitfield& other);
		_H3API_ VOID operator|=(UINT8 value);
		_H3API_ VOID operator=(UINT8 value);
		_H3API_ VOID operator=(const H3PlayersBitfield& other);
		_H3API_ VOID Hide(UINT32 player);
		_H3API_ VOID Reveal(UINT32 player);
		_H3API_ VOID Set(UINT32 player, BOOL8 state);
		_H3API_ BOOL Status(UINT32 player) const;
		_H3API_ operator UINT8() const;
	};
	_H3API_ASSERT_SIZE_(H3PlayersBitfield);

	struct H3PlayersBitfield32 : H3PlayersBitfield
	{
		_H3API_SIZE_(4);
	private:
		h3align _f_01[3];
	};
	_H3API_ASSERT_SIZE_(H3PlayersBitfield32);

	struct H3TownsBitfield
	{
		_H3API_SIZE_(2);

		union
		{
			UINT16 bits;
			struct
			{
				BOOL8 castle     : 1;
				BOOL8 rampart    : 1;
				BOOL8 tower      : 1;
				BOOL8 inferno    : 1;
				BOOL8 necropolis : 1;
				BOOL8 deungeon   : 1;
				BOOL8 stronghold : 1;
				BOOL8 fortess    : 1;
				BOOL8 conflux    : 1;
			};
		};
	};
	_H3API_ASSERT_SIZE_(H3TownsBitfield);

	struct H3BuildingsBitfield
	{
		_H3API_SIZE_(0x8);
		union
		{
			struct
			{
				/** @brief [00]*/
				unsigned mageGuild1   : 1;
				/** @brief [01]*/
				unsigned mageGuild2   : 1;
				/** @brief [02]*/
				unsigned mageGuild3   : 1;
				/** @brief [03]*/
				unsigned mageGuild4   : 1;
				/** @brief [04]*/
				unsigned mageGuild5   : 1;
				/** @brief [05]*/
				unsigned tavern       : 1;
				/** @brief [06]*/
				unsigned wharf        : 1;
				/** @brief [07]*/
				unsigned fort         : 1;
				/** @brief [08]*/
				unsigned citadel      : 1;
				/** @brief [09]*/
				unsigned castle       : 1;
				/** @brief [10]*/
				unsigned villageHall  : 1;
				/** @brief [11]*/
				unsigned townHall     : 1;
				/** @brief [12]*/
				unsigned cityHall     : 1;
				/** @brief [13]*/
				unsigned capitol      : 1;
				/** @brief [14]*/
				unsigned market       : 1;
				/** @brief [15]*/
				unsigned resourceSilo : 1;
				/** @brief [16]*/
				unsigned blacksmith   : 1;
				/** @brief [17]*/
				unsigned special17    : 1;
				/** @brief [18]*/
				unsigned horde1       : 1;
				/** @brief [19]*/
				unsigned horde1u      : 1;
				/** @brief [20]*/
				unsigned wharf2       : 1;
				/** @brief [21]*/
				unsigned special21    : 1;
				/** @brief [22]*/
				unsigned special22    : 1;
				/** @brief [23]*/
				unsigned special23    : 1;
				/** @brief [24]*/
				unsigned horde2       : 1;
				/** @brief [25]*/
				unsigned horde2u      : 1;
				/** @brief [26]*/
				unsigned grail        : 1;
				/** @brief [27]*/
				unsigned decor27      : 1;
				/** @brief [28]*/
				unsigned decor28      : 1;
				/** @brief [29]*/
				unsigned decor29      : 1;
				/** @brief [30]*/
				unsigned dwelling1    : 1;
				/** @brief [31]*/
				unsigned dwelling2    : 1;
				/** @brief [32]*/
				unsigned dwelling3    : 1;
				/** @brief [33]*/
				unsigned dwelling4    : 1;
				/** @brief [34]*/
				unsigned dwelling5    : 1;
				/** @brief [35]*/
				unsigned dwelling6    : 1;
				/** @brief [36]*/
				unsigned dwelling7    : 1;
				/** @brief [37]*/
				unsigned dwelling1u   : 1;
				/** @brief [38]*/
				unsigned dwelling2u   : 1;
				/** @brief [39]*/
				unsigned dwelling3u   : 1;
				/** @brief [40]*/
				unsigned dwelling4u   : 1;
				/** @brief [41]*/
				unsigned dwelling5u   : 1;
				/** @brief [42]*/
				unsigned dwelling6u   : 1;
				/** @brief [43]*/
				unsigned dwelling7u   : 1;
				/** @brief [44]*/
				unsigned unused       : 20;
			};
			UINT64 value;
			H3Bitfield bitfield[2];
		};

	};

	struct H3TerrainBitfield
	{
		_H3API_SIZE_(4); // not sure if smaller is seen in game, maybe combat obstacles?
		union
		{
			struct
			{
				unsigned dirt         : 1;
				unsigned sand         : 1;
				unsigned grass        : 1;
				unsigned snow         : 1;
				unsigned swamp        : 1;
				unsigned rough        : 1;
				unsigned subterranean : 1;
				unsigned lava         : 1;
				unsigned water        : 1;
				unsigned rock         : 1;
			};
			UINT16 bits;
			H3Bitfield bitfield;
		};
	};
	_H3API_ASSERT_SIZE_(H3TerrainBitfield);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
