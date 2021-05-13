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
#include "h3api/H3DialogControls/H3DlgDefButton.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgCaptionButton);
	struct H3Font;

#pragma pack(push, 4)

		struct H3DlgCaptionButton : public H3DlgDefButton
	{
		_H3API_SIZE_(0x70);
		_H3API_VTABLE_(0x63BB88);
	protected:
		/** @brief [68]*/
		H3Font* loadedFont;
		/** @brief [6C]*/
		INT32   color;
	public:

		_H3API_ static H3DlgCaptionButton* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group,
			BOOL closeDialog, INT32 a13, INT32 color);
		_H3API_ static H3DlgCaptionButton* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 a13, INT32 color);
	};
	_H3API_ASSERT_SIZE_(H3DlgCaptionButton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
