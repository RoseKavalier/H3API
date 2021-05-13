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

#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Constants/H3Limits.hpp"

namespace h3
{
	template<UINT size>	struct H3Bitset;
#ifdef _H3API_TEMPLATE_DECLARE_
	template<UINT size>
	using Bitset = H3Bitset<size>;
#endif /*_H3API_TEMPLATE_DECLARE_*/

	_H3API_TYPE_DECLARE_(H3Bitset<limits::ARTIFACTS>,    ArtifactBitset);
	_H3API_TYPE_DECLARE_(H3Bitset<limits::CREATURES>,    CreaturesBitset);
	_H3API_TYPE_DECLARE_(H3Bitset<limits::SPELLS>,       SpellsBitset);
	_H3API_TYPE_DECLARE_(H3Bitset<limits::TOWNS_ON_MAP>, VisitedTownsBitset);

#pragma pack(push, 4)
	/**
	 * @brief alternative for std::bitset matching C++98 alignment
	 * @tparam size the number of bits to be used
	 */
	template<UINT size>
	struct H3Bitset
	{
		/**
		 * @brief total bytes used by the bitset
		 * @return constexpr UINT occupied memory, including alignment
		 */
		static constexpr UINT RawSize();
	protected:
		static constexpr UINT m_length = (size - 1) / 32 + 1;
		UINT m_bits[m_length];

		VOID   set(UINT position, BOOL state);
		VOID   flip(UINT position);
		BOOL   get(UINT position) const;
		VOID   clear();
		UINT64 startMask();
		UINT   endMask();

	public:
		/**
		 * @brief incrementable iterator to inspect bitset's span
		 * modeled after Bitfield::reference but with known end
		 */
		struct iterator
		{
		protected:
			H3Bitset* m_bitset;
			UINT      m_position;
		public:
			/**
			 * @brief Construct a new iterator from start of bitset
			 * @param bitset bitset to use for iteration
			 */
			iterator(H3Bitset* bitset);
			/**
			 * @brief Construct a new iterator from specified position
			 * @param bitset bitset to use for iteration
			 * @param position 0..size-1
			 */
			iterator(H3Bitset* bitset, UINT position);
			/**
			 * @brief pre-increment
			 * @return itself
			 */
			iterator& operator++();
			/**
			 * @brief post-increment
			 * @return copy of itself before increment
			 */
			iterator  operator++(int);
			/**
			 * @brief required for range-based loop
			 * @return itself
			 */
			iterator& operator*();
			/**
			 * @brief Gives access to its methods
			 * @return iterator* Pointer to itself
			 */
			iterator* operator->();
			/**
			 * @brief flips current bit
			 * @return itself
			 */
			iterator& operator~();
			/**
			 * @brief allows if (iterator) condition
			 * @return BOOL whether current bit is set
			 */
			operator BOOL();
			/**
			 * @brief allows if (!iterator) condition
			 * @return BOOL whether current bit is not set
			 */
			BOOL operator!();
			/**
			 * @brief iterator equality check
			 * @param other another iterator
			 * @return BOOL whether both iterators point to the same bit
			 */
			BOOL operator==(const iterator& other);
			/**
			 * @brief iterator inequality check
			 * @param other another iterator
			 * @return BOOL whether both iterators point to a different bit
			 */
			BOOL operator!=(const iterator& other);
			/**
			 * @brief Set the state of the current bit
			 * @param state true or false
			 */
			VOID operator=(BOOL state);
			/** @brief set the current bit as ON/true */
			VOID Set();
			/** @brief set the current bit as OFF/false */
			VOID Reset();
			/** @brief change the state of the current bit to on from off and vice-versa */
			VOID Flip();
		};
		/** @brief Construct with all bits as off */
		H3Bitset();
		/**
		 * @brief Construct with specified first 32 bits
		 * @param value the state of the first 32 bits
		 */
		H3Bitset(UINT value);
		/**
		 * @brief Construct with specified first 64 bits
		 * @param value the state of the first 64 bits
		 */
		H3Bitset(UINT64 value);
		/**
		 * @brief Construct from a string
		 * if the string contains other characters than 0 or 1, they are considered as 1 / true
		 * @param value a string of 0 (false) and 1s (false)
		 */
		H3Bitset(const H3String& value);
		H3Bitset(const H3Bitset<size>& other);
		/**
		 * @brief transform the current state to a readable string
		 * @return H3String string of 0s and 1s (off / on)
		 */
		H3String ToString() const;
		/**
		 * @brief transform the current hexadecimal state to a readable string
		 * @return H3String string of 0..9A..F as it appears in memory
		 */
		H3String ToHexString() const;
		/**
		 * @brief extract first 32 bits
		 * @return UINT state of the first 32 bits
		 */
		UINT     ToUINT() const;
		/**
		 * @brief extract first 64 bits
		 * @return UINT64 state of the first 64 bits
		 */
		UINT64   ToUINT64() const;
		/** @brief set all bits to true */
		VOID Set();
		/** @brief set all bits to false */
		VOID Reset();
		/**
		 * @brief checks if all bits are set
		 * @return BOOL true if all bits are on, false otherwise
		 */
		BOOL All() const;
		/**
		 * @brief checks if at least 1 bit is set
		 * @return BOOL true if at least one bit is on, false otherwise
		 */
		BOOL Any() const;
		/**
		 * @brief checks if there are no bits set
		 * @return BOOL true if all bits are off, false otherwie
		 */
		BOOL None() const;
		/** @brief flip all bits state */
		VOID Flip();
		/**
		 * @brief counts how many bits are set
		 * @return UINT 0..size bits that are on
		 */
		UINT Count() const;
		/**
		 * @brief inspect state of any bit
		 * @param position 0..size-1
		 * @return BOOL the state of specified bit
		 */
		BOOL Test(UINT position) const;
		/**
		 * @brief number of bits in the bitset
		 * @return UINT size
		 */
		UINT Size() const;
		/**
		 * @brief number of DWORD used in memory
		 * @return UINT raw size of the bitset divided by 4
		 */
		UINT Length() const;
		/**
		 * @brief Checks if at least 1 bit matches in between the two bitsets.
		 * @param other The bitset to compare against.
		 * @return Whether at least 1 bit matched.
		 */
		BOOL Intersects(const H3Bitset<size>& other) const;
		/**
		 * @brief Checks if all set bits contained in \p other also set in the current bitset
		 * @param other The bitset to compare against.
		 * @return Whether the current bitset contains all set bits from \p other.
		 */
		BOOL Contains(const H3Bitset<size>& other) const;
		H3Bitset& operator=(const H3Bitset<size>& other);
		BOOL operator!=(const H3Bitset<size>& other);
		BOOL operator==(const H3Bitset<size>& other);
		/**
		 * @brief allows if (!bitset) condition, same as if (bitset.None())
		 * @return BOOL whether all bits are off
		 */
		BOOL operator!() const;
		/**
		 * @brief allows if (bitset()) condition, same as if (bitset.Any())
		 * @return BOOL whether any bool is set
		 */
		BOOL operator()() const;
		/**
		 * @brief checks state of bit at specified index
		 * @param position 0..size-1
		 * @return BOOL true if the bit is set, false otherwise
		 */
		BOOL operator()(UINT position) const;
		/**
		 * @brief iterator at first position of bitset
		 * @return iterator at position 0
		 */
		iterator begin();
		/**
		 * @brief iterator beyond last position of bitset
		 * @return iterator at position size
		 */
		iterator end();
		/**
		 * @brief access bit state at specified index through iterator
		 * @param position 0..size-1
		 * @return iterator for the specified position allowing additional access
		 */
		iterator operator[](UINT position);
	};
#pragma pack(pop) /* align-4 */

	template<UINT size>
	inline H3Bitset<size>::iterator::iterator(H3Bitset* bitset) :
		m_bitset(bitset), m_position()
	{
	}
	template<UINT size>
	inline H3Bitset<size>::iterator::iterator(H3Bitset* bitset, UINT position) :
		m_bitset(bitset), m_position(position)
	{
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator& H3Bitset<size>::iterator::operator++()
	{
		++m_position;
		return *this;
	}
	template<UINT size>
	inline typename  H3Bitset<size>::iterator H3Bitset<size>::iterator::operator++(int)
	{
		iterator it(m_bitset, m_position);
		++m_position;
		return it;
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator& H3Bitset<size>::iterator::operator*()
	{
		return *this;
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator* H3Bitset<size>::iterator::operator->()
	{
		return this;
	}
	template<UINT size>
	inline typename H3Bitset<size>::iterator& H3Bitset<size>::iterator::operator~()
	{
		Flip();
		return *this;
	}
	template<UINT size>
	inline H3Bitset<size>::iterator::operator BOOL()
	{
		return m_bitset->get(m_position);
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::iterator::operator!()
	{
		return m_bitset->Test(m_position) == FALSE;
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::iterator::operator==(const iterator& other)
	{
		return m_position == other.m_position;
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::iterator::operator!=(const iterator& other)
	{
		return m_position != other.m_position;
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::operator=(BOOL state)
	{
		m_bitset->set(m_position, state);
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::Set()
	{
		m_bitset->set(m_position, TRUE);
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::Reset()
	{
		m_bitset->set(m_position, FALSE);
	}
	template<UINT size>
	inline VOID H3Bitset<size>::iterator::Flip()
	{
		m_bitset->flip(m_position);
	}

	template<UINT size>
	inline constexpr UINT H3Bitset<size>::RawSize()
	{
		return ((size - 1) / 32 + 1) * sizeof(UINT);
	}

	template<UINT size>
	inline VOID H3Bitset<size>::set(UINT position, BOOL state)
	{
		if (position >= size)
			return;
		UINT index = position >> 5;
		UINT bit = position & 0x1F;
		UINT value = 1u << bit;
		if (state)
			m_bits[index] |= value;
		else
			m_bits[index] &= ~value;
	}
	template<UINT size>
	inline VOID H3Bitset<size>::flip(UINT position)
	{
		if (position >= size)
			return;
		UINT index = position >> 5;
		UINT bit = position & 0x1F;
		UINT value = 1u << bit;
		m_bits[index] ^= value;
	}
	template<UINT size>
	inline BOOL H3Bitset<size>::get(UINT position) const
	{
		if (position >= size)
			return -1;
		UINT index = position >> 5;
		UINT bit = position & 0x1F;
		UINT value = 1u << bit;
		return m_bits[index] & value;
	}
	template<UINT size>
	inline VOID H3Bitset<size>::clear()
	{
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = 0;
	}
	template<UINT size>
	inline UINT64 H3Bitset<size>::startMask()
	{
		if (size <= 64)
			return (1ull << size) - 1;
		return UINT64_MAX;
	}
	template<UINT size>
	inline UINT H3Bitset<size>::endMask()
	{
		return UINT((1ull << (size & 0x1F)) - 1);
	}

	template<UINT size>
	inline H3Bitset<size>::H3Bitset() :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(UINT value) :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		if (size < 32)
			value &= UINT(startMask());
		m_bits[0] = value;
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(UINT64 value) :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		switch (m_length)
		{
		case 1:
			m_bits[0] = value & UINT(startMask());
			break;
		case 2:
			*PUINT64(m_bits) = value & startMask();
			break;
		default:
			*PUINT64(m_bits) = value;
		}
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(const H3String& value) :
		m_bits()
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		UINT min_len = std::min(size, value.Length());
		for (UINT i = 0; i < min_len; ++i)
			if (value[i] != '0')
				set(i, TRUE);
	}
	template<UINT size>
	inline H3Bitset<size>::H3Bitset(const H3Bitset<size>& other)
	{
		_H3API_STATIC_ASSERT_(size > 0, "Size 0 not valid for H3Bitset");
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = other.m_bits[i];
	}

	template<UINT size>
	inline H3String H3Bitset<size>::ToString() const
	{
		H3String str;
		str.Reserve(size);
		for (UINT i = 0; i < size; ++i)
			str.Append(get(i) ? '1' : '0');
		return str;
	}

	template<UINT size>
	inline H3String H3Bitset<size>::ToHexString() const
	{
		H3String str;
		str.Reserve(size);
		for (UINT i = 0; i < m_length; ++i)
			str.PrintfAppend("%x", m_bits[i]);
		return str;
	}

	template<UINT size>
	inline UINT H3Bitset<size>::ToUINT() const
	{
		return m_bits[0];
	}

	template<UINT size>
	inline UINT64 H3Bitset<size>::ToUINT64() const
	{
		switch (m_length)
		{
		case 1:
			return m_bits[0];
		default:
			return *PUINT64(m_bits);
		}
	}

	template<UINT size>
	inline VOID H3Bitset<size>::Set()
	{
		for (UINT i = 0; i < m_length - 1; ++i)
			m_bits[i] = 0;
		m_bits[m_length - 1] = endMask();
	}

	template<UINT size>
	inline VOID H3Bitset<size>::Reset()
	{
		clear();
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::All() const
	{
		for (UINT i = 0; i < m_length - 1; ++i)
			if (m_bits[i] != UINT_MAX)
				return FALSE;
		return m_bits[m_length - 1] == UINT(endMask());
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Any() const
	{
		for (UINT i = 0; i < m_length - 1; ++i)
			if (m_bits[i] != 0)
				return TRUE;
		return FALSE;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::None() const
	{
		return !Any();
	}

	template<UINT size>
	inline VOID H3Bitset<size>::Flip()
	{
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = m_bits[i] ^ UINT_MAX;
		m_bits[m_length - 1] &= UINT(endMask());
	}

	template<UINT size>
	inline UINT H3Bitset<size>::Count() const
	{
		PUINT8 const bitset_lookup_table = PUINT8(0x67729C);
		UINT count = 0;

		PUINT current = m_bits + m_length - 1;
		UINT num_iterations = m_length;

		do
		{
			for (UINT i = *current; i; i >>= 4)
				count += bitset_lookup_table[i & 0xF];
			--current;
			--num_iterations;
		} while (num_iterations > 0);

		return count;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Test(UINT position) const
	{
		return get(position);
	}

	template<UINT size>
	inline UINT H3Bitset<size>::Size() const
	{
		return size;
	}

	template<UINT size>
	inline UINT H3Bitset<size>::Length() const
	{
		return m_length;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Intersects(const H3Bitset<size>& other) const
	{
		for (UINT i = 0; i < m_length; ++i)
			if (m_bits[i] & other.m_bits[i] != 0)
				return TRUE;
		return FALSE;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::Contains(const H3Bitset<size>& other) const
	{
		for (UINT i = 0; i < m_length; ++i)
			if ((other.m_bits[i] & ~m_bits[i]) != 0)
				return FALSE;
		return TRUE;
	}

	template<UINT size>
	inline H3Bitset<size>& H3Bitset<size>::operator=(const H3Bitset<size>& other)
	{
		for (UINT i = 0; i < m_length; ++i)
			m_bits[i] = other.m_bits;
		return *this;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator!=(const H3Bitset<size>& other)
	{
		return !operator==(other);
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator==(const H3Bitset<size>& other)
	{
		for (UINT i = 0; i < m_length; ++i)
			if (m_bits[i] != other.m_bits)
				return FALSE;
		return TRUE;
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator()(UINT position) const
	{
		return get(position);
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator()() const
	{
		return Any();
	}

	template<UINT size>
	inline BOOL H3Bitset<size>::operator!() const
	{
		return None();
	}

	template<UINT size>
	inline typename H3Bitset<size>::iterator H3Bitset<size>::begin()
	{
		return iterator(this, 0);
	}

	template<UINT size>
	inline typename H3Bitset<size>::iterator H3Bitset<size>::end()
	{
		return iterator(this, size);
	}

	template<UINT size>
	inline typename H3Bitset<size>::iterator H3Bitset<size>::operator[](UINT position)
	{
		return iterator(this, position);
	}
}
