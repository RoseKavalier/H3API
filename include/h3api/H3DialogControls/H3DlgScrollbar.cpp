//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgScrollbar.hpp"
#include "h3api/H3Dialogs/H3BaseDialog.hpp"

namespace h3
{
    _H3API_ VOID H3DlgScrollbar::loadButton(LPCSTR buttonName)
    {
        THISCALL_2(VOID, 0x596340, this, buttonName);
    }

    _H3API_ H3DlgScrollbar* H3DlgScrollbar::Create(INT32 x, INT32 y, INT32 width,
        INT32 height, INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc,
        BOOL isBlue, INT32 stepSize, BOOL arrowsEnabled)
    {
        H3DlgScrollbar* s = H3ObjectAllocator<H3DlgScrollbar>().allocate(1);
        if (s)
            THISCALL_11(H3DlgScrollbar*, 0x5963C0, s, x, y, width, height, id, ticksCount,
                scrollbarProc, isBlue, stepSize, arrowsEnabled);
        return s;
    }
    _H3API_ INT32 H3DlgScrollbar::GetTick() const
    {
        return tick;
    }
    _H3API_ VOID H3DlgScrollbar::SetTick(INT32 index)
    {
        tick = index;
    }
    _H3API_ VOID H3DlgScrollbar::SetBigStep(INT32 step)
    {
        bigStepSize = step;
    }
    _H3API_ VOID H3DlgScrollbar::SetButtonPosition()
    {
        btnPosition = sizeFree * tick / (ticksCount - 1) + btnSize2;
    }
    _H3API_ BOOL H3DlgScrollbar::IsHorizontal() const
    {
        return widthItem > heightItem;
    }
    _H3API_ INT32 H3DlgScrollbar::GetRightButtonX() const
    {
        return parent->GetX() + xPos + sizeMax - btnSize2;
    }
    _H3API_ INT32 H3DlgScrollbar::GetHorizontalY() const
    {
        return parent->GetY() + yPos;
    }
    _H3API_ INT32 H3DlgScrollbar::GetBackgroundWidth() const
    {
        return sizeMax - 2 * btnSize2;
    }
    _H3API_ INT32 H3DlgScrollbar::GetBackgroundX() const
    {
        return parent->GetX() + xPos + btnSize2;
    }
    _H3API_ INT32 H3DlgScrollbar::GetSliderX() const
    {
        return parent->GetX() + xPos + btnPosition;
    }
    _H3API_ H3LoadedPcx* H3DlgScrollbar::GetPcx()
    {
        return loadedPcx;
    }
} /* namespace h3 */
