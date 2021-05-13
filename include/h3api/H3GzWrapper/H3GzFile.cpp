//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3GzWrapper/H3GzFile.hpp"
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{
	_H3API_ UINT32 H3GzFile::write(VOID* src, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->write, this, src, size);
	}
	_H3API_ UINT32 H3GzFile::read(VOID* dst, UINT32 size)
	{
		return THISCALL_3(UINT32, vtable->read, this, dst, size);
	}
	_H3API_ H3GzFile::H3GzFile(LPCSTR file_name, LPCSTR mode)
	{
		THISCALL_3(H3GzFile&, 0x4D6EB0, this, file_name, mode);
	}
	_H3API_ H3GzFile::~H3GzFile()
	{
		THISCALL_1(VOID, 0x4D6FC0, this);
	}
	_H3API_ BOOL H3GzFile::ReadString16(H3String& string)
	{
		return FASTCALL_2(INT32, 0x4BB650, this, &string) != 0;
	}
	_H3API_ BOOL H3GzFile::Read(H3String& string)
	{
		return FASTCALL_2(INT32, 0x4C5CD0, this, &string) != 0;
	}
	_H3API_ BOOL H3GzFile::Write(const H3String& string)
	{
		if (!Write(string.Length()))
			return FALSE;
		return write(PVOID(string.String()), string.Length()) == string.Length();
	}
	_H3API_ BOOL H3GzFile::WriteString16(const H3String& string)
	{
		return FASTCALL_2(UINT32, 0x4BB820, this, &string) != 0;
	}
} /* namespace h3 */
