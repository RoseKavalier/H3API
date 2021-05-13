//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3Palette565.hpp"

namespace h3
{
    _H3API_ VOID H3Palette565::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x6003E0, color, id);
	}
	_H3API_ VOID H3Palette565::RotateColors(INT min_index, INT max_index, INT count)
	{
		THISCALL_4(VOID, 0x522E40, this, min_index, max_index, count);
	}
	_H3API_ H3Palette565* H3Palette565::Initiate()
	{
		return THISCALL_1(H3Palette565*, 0x522B40, this);
	}
	_H3API_ H3Palette32* H3Palette565::Get32bitColors()
	{
		if (type == 0x61)
			return palette32;
		return nullptr;
	}
	_H3API_ VOID H3Palette565::CopyPalette(const H3Palette565& source)
	{
		THISCALL_2(VOID, 0x522DD0, this, &source);
	}
	_H3API_ VOID H3Palette565::CopyPalette(const H3BasePalette565& source)
	{
		THISCALL_2(VOID, 0x522DD0, this, &source);
	}
	_H3API_ H3RGB565& H3Palette565::operator[](UINT index)
	{
		return color[index];
	}
	_H3API_ H3RGB565 H3Palette565::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ H3Palette32 H3Palette565::Convert() const
	{
		H3Palette32 p;

		for (UINT i = 0; i < 256; ++i)
			p.colors[i] = color[i];

		return p;
	}
	_H3API_ VOID H3Palette565::Init(const H3BasePalette565& palette)
	{
		THISCALL_2(VOID, 0x522DD0, this, &palette);
	}
	_H3API_ H3Palette565* H3Palette565::Load(LPCSTR name)
	{
		return THISCALL_1(H3Palette565*, 0x55B5F0, name); // adds to resource manager directly, alt. 55B270
	}
} /* namespace h3 */
