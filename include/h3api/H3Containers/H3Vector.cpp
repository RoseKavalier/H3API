//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_ H3IndexVector::H3IndexVector(INT min_num, INT max_num)
	{
		THISCALL_3(H3IndexVector*, 0x50C8D0, this, min_num, max_num);
	}
	_H3API_ H3IndexVector::~H3IndexVector()
	{
		H3ObjectAllocator<BOOL8>().deallocate(m_begin);
	}
	_H3API_ INT H3IndexVector::ChooseRandom()
	{
		return THISCALL_1(INT, 0x50C930, this);
	}
	_H3API_ INT H3IndexVector::InvalidIndex()
	{
		return m_minimum - 1;
	}
} /* namespace h3 */