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
#include "h3api/H3DialogControls/H3DlgText.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgEdit);
	_H3API_DECLARE_(ScreenchatEdit);
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3Msg;

#pragma pack(push, 4)

	struct H3DlgEdit : public H3DlgText
	{
		_H3API_SIZE_(0x70);
		_H3API_VTABLE_(0x642D50);
		_H3API_CTOR_DTOR_(0x5BACD0, -1);
	protected:
		/** @brief [v38]*/
		_H3API_ virtual VOID  vSetFocus(BOOL8 focused) const = 0;
		/** @brief [v3C]*/
		_H3API_ virtual INT   vProcessKey(H3Msg &msg) = 0;
		/** @brief [v40]*/
		_H3API_ virtual BOOL8 vIsTabEscEnter(H3Msg &msg) const = 0;
		/** @brief [v44]*/
		_H3API_ virtual VOID  vLoadPcx16Special(BOOL8 redraw) const = 0;
		/** @brief [v48]*/
		_H3API_ virtual VOID  vPcx16FromBuffer() const = 0;

	protected:
		/** @brief [50]*/
		H3LoadedPcx*   loadedPcx;
		/** @brief [54]*/
		H3LoadedPcx16* loadedPcx16;
		/** @brief [58]*/
		UINT16         caretPos;
		/** @brief [5A]*/
		UINT16         maxLength;
		/** @brief [5C]*/
		UINT16         fieldSizeX;
		/** @brief [5E]*/
		UINT16         fieldSizeY;
		/** @brief [60]*/
		UINT16         fieldX;
		/** @brief [62]*/
		UINT16         fieldY;
		/** @brief [64]*/
		INT16          _f_64;
		/** @brief [66]*/
		INT16          hasBorder;
		/** @brief [68]*/
		INT16          _f_68;
		/** @brief [6A]*/
		INT16          _f_6A;
		/** @brief [6C]*/
		h3unk          _f_6C;
		/** @brief [6D]*/
		BOOL8          focused;
		/** @brief [6E]*/
		BOOL8          autoRedraw;
	public:
		_H3API_ static H3DlgEdit* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 maxLength, LPCSTR text, LPCSTR fontName, INT32 color, INT32 align,
			LPCSTR pcxName, INT32 id, INT32 hasBorder, INT32 borderX, INT32 borderY);
		_H3API_ LPCSTR    GetText() const;
		_H3API_ H3String* GetString();
		_H3API_ VOID      SetText(LPCSTR text);
		_H3API_ VOID      DecreaseCaret();
		_H3API_ VOID      IncreaseCaret();
		_H3API_ UINT      GetCaret() const;
		_H3API_ BOOL      SetCaret(UINT pos);
		_H3API_ VOID      SetAutoredraw(BOOL on);
		_H3API_ VOID      SetFocus(BOOL on = TRUE);
	};
	_H3API_ASSERT_SIZE_(H3DlgEdit);

	struct H3ScreenchatEdit : H3DlgEdit
	{
		_H3API_SIZE_(0x74);
		/** @brief [70]*/
		BOOL8 enteringText;
	};
	_H3API_ASSERT_SIZE_(H3ScreenchatEdit);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
