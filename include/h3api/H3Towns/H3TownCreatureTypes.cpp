//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Towns/H3TownCreatureTypes.hpp"

namespace h3
{
    _H3API_ INT32& H3TownCreatureTypes::iterator::Base()
	{
		return *m_base;
	}
	_H3API_ H3TownCreatureTypes::iterator::iterator(INT32* base) :
		m_base(base)
	{
	}
	_H3API_ INT32& H3TownCreatureTypes::iterator::Upgraded()
	{
		return m_base[7];
	}
	_H3API_ H3TownCreatureTypes::iterator& H3TownCreatureTypes::iterator::operator*()
	{
		return *this;
	}
	_H3API_ H3TownCreatureTypes::iterator& H3TownCreatureTypes::iterator::operator++()
	{
		++m_base;
		return *this;
	}
	_H3API_ H3TownCreatureTypes::iterator H3TownCreatureTypes::iterator::operator++(int)
	{
		iterator it(m_base);
		++m_base;
		return it;
	}
	_H3API_ BOOL H3TownCreatureTypes::iterator::operator==(const iterator& other) const
	{
		return m_base == other.m_base;
	}
	_H3API_ BOOL H3TownCreatureTypes::iterator::operator!=(const iterator& other) const
	{
		return m_base != other.m_base;
	}

	_H3API_ H3TownCreatureTypes::iterator H3TownCreatureTypes::begin()
	{
		return iterator(base);
	}
	_H3API_ H3TownCreatureTypes::iterator H3TownCreatureTypes::end()
	{
		return iterator(base + 7);
	}
} /* namespace h3 */
