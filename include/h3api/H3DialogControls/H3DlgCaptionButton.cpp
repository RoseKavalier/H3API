//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgCaptionButton.hpp"
#include "h3api/H3Assets/H3LoadedDef.hpp"

namespace h3
{
    _H3API_ H3DlgCaptionButton* H3DlgCaptionButton::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 hotkey, INT32 color)
	{
		H3DlgCaptionButton* b = H3ObjectAllocator<H3DlgCaptionButton>().allocate(1);
		if (b)
			THISCALL_15(H3DlgCaptionButton*, 0x456730, b, x, y, width, height, id, defName, text, font, frame, group, closeDialog, hotkey, 2, color);
		return b;
	}
	_H3API_ H3DlgCaptionButton* H3DlgCaptionButton::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 hotkey, INT32 color)
	{
		H3DlgCaptionButton* b = Create(x, y, 0, 0, id, defName, text, font, frame, group, closeDialog, hotkey, color);
		if (b && b->loadedDef)
		{
			b->widthItem = b->loadedDef->widthDEF;
			b->heightItem = b->loadedDef->heightDEF;
		}
		return b;
	}
} /* namespace h3 */
