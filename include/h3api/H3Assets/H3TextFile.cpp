//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3TextFile.hpp"

namespace h3
{
    _H3API_ LPCSTR H3TextFile::GetText(UINT32 row) const
	{
		return text[row - 1];
	}
	_H3API_ LPCSTR H3TextFile::GetText(UINT32 row)
	{
		return text[row - 1];
	}
	_H3API_ H3TextFile* H3TextFile::Load(LPCSTR name)
	{
		return THISCALL_1(H3TextFile*, 0x55BDA0, name);
	}
	_H3API_ VOID H3TextFile::UnLoad()
	{
		vTable->vEraseFromResourceManager(this);
	}
	_H3API_ LPCSTR& H3TextFile::operator[](UINT row)
	{
		return text[row];
	}
	_H3API_ LPCSTR* H3TextFile::begin()
	{
		return text.begin();
	}
	_H3API_ LPCSTR* H3TextFile::end()
	{
		return text.end();
	}
} /* namespace h3 */
