//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Assets/H3Resource.hpp"
#include "h3api/H3Constants/H3CstDlg.hpp"

namespace h3
{
	_H3API_DECLARE_(Font);
	template<typename _Elem> struct H3Vector;
	struct H3String;

#pragma pack(push, 4)
	/** @brief original name may be 'font', unknown */
	struct H3Font : public H3ResourceItem
	{
		_H3API_SIZE_(0x1260);
	protected:
		h3unk _f_1C[5];
	public:
		/** @brief [21]*/
		INT8 height;
	protected:
		h3unk _f_22[26];
	public:
		/** @brief [3C] used to calculate line width*/
		struct FontSpacing
		{
			INT32 leftMargin;
			INT32 span;
			INT32 rightMargin;
		}width[256];
		/** @brief [C3C] referenced at 0x4B4F1C*/
		UINT32 bufferOffsets[256];
		/** @brief [103C]*/
		H3BasePalette565 palette;
		/** @brief [1258] how the characters look*/
		PUINT8 bitmapBuffer;
		/** @brief [125C]*/
		INT32 bufferSize;

		_H3API_ INT32 GetLinesCountInText(LPCSTR str, INT32 width);
		_H3API_ INT32 GetMaxLineWidth(LPCSTR str);
		_H3API_ INT32 GetMaxWordWidth(LPCSTR str);
		_H3API_ VOID  SplitTextIntoLines(LPCSTR text, INT32 textWidth, H3Vector<H3String>& stringVector);

		_H3API_ VOID TextDraw(H3LoadedPcx16* pcx, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			eTextColor colorIndex = eTextColor::REGULAR,
			eTextAlignment alignment = eTextAlignment::MIDDLE_CENTER);

		_H3API_ static H3Font* Load(LPCSTR name);

		/**
		 * @brief Access font buffer at starting position of specified character
		 * @param character_id Index of the ascii character 0..255
		 * @return Buffer to specified location
		 */
		_H3API_ PUINT8 GetChar(UINT32 character_id);
	};
	_H3API_ASSERT_SIZE_(H3Font);

	struct H3TinyFont : H3Font
	{
		_H3API_GET_INFO_(0x698A54, H3TinyFont);
	};
	struct H3SmallFont : H3Font
	{
		_H3API_GET_INFO_(0x698A58, H3SmallFont);
	};
	struct H3MediumFont : H3Font
	{
		_H3API_GET_INFO_(0x698A5C, H3MediumFont);
	};
	struct H3BigFont : H3Font
	{
		_H3API_GET_INFO_(0x698A60, H3BigFont);
	};
	struct H3CalliFont : H3Font
	{
		_H3API_GET_INFO_(0x698A64, H3CalliFont);
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
