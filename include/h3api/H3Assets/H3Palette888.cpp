//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3Palette888.hpp"

namespace h3
{
    _H3API_ VOID H3Palette888::ColorToPlayer(INT id)
	{
		FASTCALL_2(VOID, 0x600400, this, id);
	}
	_H3API_ H3Palette888* H3Palette888::Initiate()
	{
		return THISCALL_1(H3Palette888*, 0x523320, this);
	}
	_H3API_	H3RGB888& H3Palette888::operator[](UINT index)
	{
		return color[index];
	}
	_H3API_ const H3RGB888& H3Palette888::operator[](UINT index) const
	{
		return color[index];
	}
	_H3API_ VOID H3Palette888::Init(const H3BasePalette888& palette)
	{
		THISCALL_2(void, 0x5233F0, this, &palette);
	}
	_H3API_ H3Palette32 H3Palette888::Convert() const
	{
		H3Palette32 p;

		for (UINT i = 0; i < 256; ++i)
			p.colors[i] = color[i];

		return p;
	}
} /* namespace h3 */
