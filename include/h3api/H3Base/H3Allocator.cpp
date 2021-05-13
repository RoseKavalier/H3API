//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-15                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Base/H3Allocator.hpp"

namespace h3
{
	_H3API_ PVOID H3Realloc(PVOID obj, UINT new_size)
	{
		return CDECL_2(PVOID, 0x619890, obj, new_size);
	}
	_H3API_ PVOID H3Calloc(UINT count, UINT size)
	{
		return CDECL_2(PVOID, 0x61AA61, count, size);
	}
	_H3API_ PVOID H3Malloc(UINT size)
	{
		return CDECL_1(PVOID, 0x617492, size);
	}
	_H3API_ VOID H3Free(PVOID obj)
	{
		if (obj)
			CDECL_1(VOID, 0x60B0F0, obj);
	}
	_H3API_ PVOID H3Allocator::operator new(const size_t sz)
	{
		return H3Malloc(sz);
	}
	_H3API_ VOID H3Allocator::operator delete(PVOID block)
	{
		H3Free(block);
	}
	_H3API_ PVOID H3Allocator::operator new[](const size_t sz)
	{
		return H3Malloc(sz);
	}
	_H3API_ VOID H3Allocator::operator delete[](PVOID block)
	{
		H3Free(block);
	}
}
