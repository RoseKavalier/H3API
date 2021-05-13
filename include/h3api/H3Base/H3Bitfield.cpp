//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Base/H3Bitfield.hpp"

namespace h3
{
	_H3API_ BOOL H3Bitfield::GetState(UINT32 position) const
	{
		UINT32 index = position >> 5;
		UINT32 pos = position & 0x1F;
		UINT32 value = 1u << pos;
		return ((&m_bf)[index]) & value;
	}
	_H3API_ VOID H3Bitfield::SetState(UINT32 position, BOOL state)
	{
		UINT32 index = position >> 5;
		UINT32 pos = position & 0x1F;
		UINT32 value = 1u << pos;
		if (state)
			((&m_bf)[index]) |= value;
		else
			((&m_bf)[index]) &= ~value;
	}
	_H3API_ VOID h3::H3Bitfield::Set(UINT32 value)
	{
		m_bf = value;
	}
	_H3API_ UINT h3::H3Bitfield::Get() const
	{
		return m_bf;
	}
	_H3API_ VOID H3Bitfield::Flip(UINT32 position)
	{
		UINT32 index = position >> 5;
		UINT32 pos = position & 0x1F;
		UINT32 value = 1u << pos;
		((&m_bf)[index]) ^= value;
	}
	_H3API_ H3Bitfield::reference H3Bitfield::operator[](UINT32 position)
	{
		return reference(this, position);
	}
	_H3API_ BOOL H3Bitfield::operator()(UINT position)
	{
		return GetState(position);
	}
	_H3API_ UINT H3Bitfield::Mask(UINT number_bits)
	{
		return UINT((1ull << (number_bits & 0x1F)) - 1);
	}
	_H3API_ VOID H3ObjectMask::operator=(const H3ObjectMask& other)
	{
		m_bitsPacked = other.m_bitsPacked;
	}
	_H3API_ VOID H3ObjectMask::operator=(UINT64 value)
	{
		m_bitsPacked = value;
	}
	_H3API_ H3Bitfield& H3ObjectMask::operator[](UINT index)
	{
		return m_bits[index];
	}
	_H3API_ const H3Bitfield& H3ObjectMask::operator[](UINT index) const
	{
		return m_bits[index];
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::begin()
	{
		return iterator(this, 0);
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::end()
	{
		return iterator(this, 48);
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::operator()(UINT8 index)
	{
		return iterator(this, index);
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::operator()(UINT8 column, UINT8 row)
	{
		return iterator(this, (row << 3) + column); // row * 8 + column
	}
	_H3API_ H3Bitfield::reference::reference(H3Bitfield* bitfield) :
		m_bitfield(bitfield), m_position()
	{
	}
	_H3API_ H3Bitfield::reference::reference(H3Bitfield* bitfield, UINT position) :
		m_bitfield(bitfield), m_position(position)
	{
	}
	_H3API_ H3Bitfield::reference& H3Bitfield::reference::operator++()
	{
		++m_position;
		return *this;
	}
	_H3API_ H3Bitfield::reference H3Bitfield::reference::operator++(int)
	{
		reference ref(m_bitfield, m_position);
		++m_position;
		return ref;
	}
	_H3API_ H3Bitfield::reference& H3Bitfield::reference::operator~()
	{
		Flip();
		return *this;
	}
	_H3API_ H3Bitfield::reference::operator BOOL()
	{
		return m_bitfield->GetState(m_position);
	}
	_H3API_ BOOL H3Bitfield::reference::operator!()
	{
		return m_bitfield->GetState(m_position) == FALSE;
	}
	_H3API_ VOID H3Bitfield::reference::operator=(BOOL state)
	{
		m_bitfield->SetState(m_position, state);
	}
	_H3API_ VOID H3Bitfield::reference::Set()
	{
		m_bitfield->SetState(m_position, TRUE);
	}
	_H3API_ VOID H3Bitfield::reference::Reset()
	{
		m_bitfield->SetState(m_position, FALSE);
	}
	_H3API_ VOID H3Bitfield::reference::Flip()
	{
		m_bitfield->Flip(m_position);
	}
	_H3API_ H3PlayersBitfield::H3PlayersBitfield() :
		bits()
	{
	}
	_H3API_ H3PlayersBitfield::H3PlayersBitfield(UINT8 player_bits) :
		bits(player_bits)
	{
	}
	_H3API_ H3PlayersBitfield::H3PlayersBitfield(const H3PlayersBitfield& other) :
		bits(other.bits)
	{
	}
	_H3API_ VOID H3PlayersBitfield::operator|=(UINT8 value)
	{
		bits |= value;
	}
	_H3API_ VOID H3PlayersBitfield::operator=(UINT8 value)
	{
		bits = value;
	}
	_H3API_ VOID H3PlayersBitfield::operator=(const H3PlayersBitfield& other)
	{
		bits = other.bits;
	}
	_H3API_ VOID H3PlayersBitfield::Set(UINT32 player, BOOL8 state)
	{
		state ? Reveal(player) : Hide(player);
	}
	_H3API_ BOOL H3PlayersBitfield::Status(UINT32 player) const
	{
		return bits & (1 << player);
	}
	_H3API_ VOID H3PlayersBitfield::Reveal(UINT32 player)
	{
		bits |= (1 << player);
	}
	_H3API_ VOID H3PlayersBitfield::Hide(UINT32 player)
	{
		bits &= ~(1 << player);
	}
	_H3API_ H3PlayersBitfield::operator UINT8() const
	{
		return bits;
	}
	_H3API_ H3ObjectMask::iterator::iterator(const iterator& it) :
		m_mask(it.m_mask), m_position(it.m_position)
	{
	}
	_H3API_ H3ObjectMask::iterator::iterator(H3ObjectMask* mask) :
		m_mask(mask), m_position(0)
	{
	}
	_H3API_ H3ObjectMask::iterator::iterator(H3ObjectMask* mask, UINT32 index) :
		m_mask(mask), m_position(index)
	{
	}
	_H3API_ H3ObjectMask::iterator& H3ObjectMask::iterator::operator++()
	{
		++m_position;
		return *this;
	}
	_H3API_ H3ObjectMask::iterator H3ObjectMask::iterator::operator++(INT32)
	{
		iterator it(*this);
		++(*this);
		return it;
	}
	_H3API_ H3ObjectMask::iterator& H3ObjectMask::iterator::operator~()
	{
		Flip();
		return *this;
	}
	_H3API_ H3ObjectMask::iterator::operator BOOL() const
	{
		return GetState();
	}
	_H3API_ BOOL H3ObjectMask::iterator::operator!() const
	{
		return GetState() == FALSE;
	}
	_H3API_ VOID H3ObjectMask::iterator::operator=(BOOL state)
	{
		SetState(state);
	}
	_H3API_ BOOL H3ObjectMask::iterator::GetState() const
	{
		return m_mask->m_bits->GetState(m_position);
	}
	_H3API_ VOID H3ObjectMask::iterator::SetState(BOOL state)
	{
		m_mask->m_bits->SetState(m_position, state);
	}
	_H3API_ VOID H3ObjectMask::iterator::Set()
	{
		SetState(TRUE);
	}
	_H3API_ VOID H3ObjectMask::iterator::Reset()
	{
		SetState(FALSE);
	}
	_H3API_ VOID H3ObjectMask::iterator::Flip()
	{
		m_mask->m_bits->Flip(m_position);
	}
	_H3API_ BOOL H3ObjectMask::iterator::operator==(const iterator& it)
	{
		return m_position == it.m_position;
	}
	_H3API_ BOOL H3ObjectMask::iterator::operator!=(const iterator& it)
	{
		return m_position != it.m_position;
	}
}
