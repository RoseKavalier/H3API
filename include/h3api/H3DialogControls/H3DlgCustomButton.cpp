//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgCustomButton.hpp"
#include "h3api/H3Assets/H3LoadedDef.hpp"

namespace h3
{
    _H3API_ H3DlgCustomButton* H3DlgCustomButton::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
    {
        H3DlgCustomButton* b = H3ObjectAllocator<H3DlgCustomButton>().allocate(1);
        if (b)
            THISCALL_10(H3DlgCustomButton*, 0x456A10, b, x, y, width, height, id, defName, customProc, frame, clickFrame);
        return b;
    }
    _H3API_ H3DlgCustomButton* H3DlgCustomButton::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
    {
        H3DlgCustomButton* b = Create(x, y, 0, 0, id, defName, customProc, frame, clickFrame);
        if (b && b->loadedDef)
        {
            b->widthItem = b->loadedDef->widthDEF;
            b->heightItem = b->loadedDef->heightDEF;
        }
        return b;
    }
    _H3API_ H3DlgCustomButton* H3DlgCustomButton::Create(INT32 x, INT32 y, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
    {
        return Create(x, y, 0, defName, customProc, frame, clickFrame);
    }
    _H3API_ VOID H3DlgCustomButton::ToggleMsgFlag(BOOL& flag)
    {
        defFrame = !defFrame;
        defFrameOnClick = !defFrameOnClick;
        flag = !flag;
        Draw();
        Refresh();
    }
} /* namespace h3 */
