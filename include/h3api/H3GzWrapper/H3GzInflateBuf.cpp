//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GzWrapper/H3GzInflateBuf.hpp"

namespace h3
{
	_H3API_ UINT32 H3GzInflateBuf::read(PVOID dst, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->xsgetn, this, dst, size);
	}
	_H3API_ UINT32 H3GzInflateBuf::write(PVOID src, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->xsputn, this, src, size);
	}
	_H3API_ UINT32 H3GzInflateBufFile::read(PVOID dst, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->read, this, dst, size);
	}
	_H3API_ UINT32 H3GzInflateBufFile::write(PVOID src, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->write, this, src, size);
	}
	_H3API_ H3String* H3GzInflateBufFile::Read(H3String& string)
	{
		return FASTCALL_2(H3String*, 0x4858B0, &string, this);
	}

} /* namespace h3 */
