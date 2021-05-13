//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3Font.hpp"
#include "h3api/H3Assets/H3LoadedPcx16.hpp"

namespace h3
{
    _H3API_ INT32 H3Font::GetLinesCountInText(LPCSTR str, INT32 width)
	{
		return THISCALL_3(INT32, 0x4B5580, this, str, width);
	}
	_H3API_ INT32 H3Font::GetMaxLineWidth(LPCSTR str)
	{
		return THISCALL_2(INT32, 0x4B56F0, this, str);
	}
	_H3API_ INT32 H3Font::GetMaxWordWidth(LPCSTR str)
	{
		return THISCALL_2(INT32, 0x4B5770, this, str);
	}
	_H3API_ VOID H3Font::SplitTextIntoLines(LPCSTR text, INT32 textWidth, H3Vector<H3String>& stringVector)
	{
		THISCALL_4(VOID, 0x4B58F0, this, text, textWidth, &stringVector);
	}
	_H3API_ VOID H3Font::TextDraw(H3LoadedPcx16* pcx, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height, eTextColor colorIndex, eTextAlignment alignment)
	{
		pcx->TextDraw(this, text, x, y, width, height, colorIndex, alignment);
	}
	_H3API_ H3Font* H3Font::Load(LPCSTR name)
	{
		return THISCALL_1(H3Font*, 0x55BD10, name);
	}
	_H3API_ PUINT8 H3Font::GetChar(UINT32 character_id)
	{
		return bitmapBuffer + bufferOffsets[character_id];
	}
} /* namespace h3 */
