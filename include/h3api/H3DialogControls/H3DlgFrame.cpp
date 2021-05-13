//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgFrame.hpp"

namespace h3
{
    _H3API_ H3DlgFrame* H3DlgFrame::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color)
	{
		H3DlgFrame* f = H3ObjectAllocator<H3DlgFrame>().allocate(1);
		if (f)
			THISCALL_8(H3DlgFrame*, 0x44FE00, f, x, y, width, height, id, color, 0x400);
		return f;
	}
	_H3API_ H3DlgFrame* H3DlgFrame::Create(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color)
	{
		return Create(x, y, width, height, 0, color);
	}
	_H3API_ H3DlgFrame* H3DlgFrame::Create(H3DlgItem* target, RGB565 color, INT id, BOOL around_edge)
	{
		if (!target)
			return nullptr;
		if (around_edge)
			return Create(target->GetX() - 1, target->GetY() - 1, target->GetWidth() + 2, target->GetHeight() + 2, id, color);
		else
			return Create(target->GetX(), target->GetY(), target->GetWidth(), target->GetHeight(), id, color);
	}
	_H3API_ VOID H3DlgFrame::ChangeColor(RGB565 color)
	{
		color565 = color;
	}
	_H3API_ VOID H3DlgFrame::HideHue()
	{
		changeHue = FALSE;
	}
	_H3API_ VOID H3DlgFrame::ShowHue()
	{
		changeHue = TRUE;
	}
	_H3API_ VOID H3DlgFrame::ToggleHue()
	{
		changeHue = !changeHue;
	}
	_H3API_ H3RGB565& H3DlgFrame::GetColor()
	{
		return *reinterpret_cast<H3RGB565*>(&color565);
	}
} /* namespace h3 */
