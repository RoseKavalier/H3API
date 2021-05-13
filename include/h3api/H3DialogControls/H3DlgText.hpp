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
#include "h3api/H3DialogControls/H3DlgItem.hpp"
#include "h3api/H3Containers/H3String.hpp"
#include "h3api/H3Constants/H3CstDlg.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgText);
	struct H3Font;

#pragma pack(push, 4)

	struct H3DlgText : public H3DlgItem
	{
		_H3API_SIZE_(0x50);
		_H3API_VTABLE_(0x642DC0);

	protected:
		/** @brief [v34]*/
		_H3API_ virtual VOID vSetText(LPCSTR text) const = 0;

	protected:
		/** @brief [30]*/
		H3String text;
		/** @brief [40]*/
		H3Font*  font;
		/** @brief [44]*/
		INT32    color;
		/** @brief [48]*/
		INT32    bkColor;
		/** @brief [4C]*/
		eTextAlignment alignment;
	public:
		_H3API_ static H3DlgText* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			LPCSTR text, LPCSTR fontName = NH3Dlg::Text::SMALL,	INT32 color = eTextColor::REGULAR,
			INT32 id = 0, INT32 align = eTextAlignment::MIDDLE_CENTER, INT32 bkColor = 0);
		_H3API_ H3String& GetH3String();
		_H3API_ VOID SetText(LPCSTR text);
		_H3API_ VOID SetText(const H3String& text);
		_H3API_ VOID SetAlignment(eTextAlignment align);
	};
	_H3API_ASSERT_SIZE_(H3DlgText);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
