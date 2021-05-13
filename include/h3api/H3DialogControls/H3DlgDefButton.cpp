//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgDefButton.hpp"
#include "h3api/H3Assets/H3LoadedDef.hpp"

namespace h3
{
    _H3API_ INT H3DlgDefButton::ToggleFrame()
    {
        std::swap(defFrame, defFrameOnClick);
        //defFrame = !defFrame;
        //defFrameOnClick = !defFrameOnClick;
        return defFrame;
    }
    _H3API_ INT32 H3DlgDefButton::GetFrame() const
    {
        return defFrame;
    }
    _H3API_ INT32 H3DlgDefButton::GetClickFrame() const
    {
        return defFrameOnClick;
    }
    _H3API_ VOID H3DlgDefButton::ColorDefToPlayer(INT32 id)
    {
        loadedDef->ColorToPlayer(id);
    }
    _H3API_	VOID H3DlgDefButton::SetFrame(INT32 frame)
    {
        defFrame = frame;
    }
    _H3API_ VOID H3DlgDefButton::SetClickFrame(INT32 clickFrame)
    {
        defFrameOnClick = clickFrame;
    }
    _H3API_ H3LoadedDef* H3DlgDefButton::GetDef()
    {
        return loadedDef;
    }
    _H3API_ VOID H3DlgDefButton::AddHotkey(INT32 key)
    {
        hotkeys.Add(key);
    }
    _H3API_ H3DlgDefButton* H3DlgDefButton::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
    {
        H3DlgDefButton* b = H3ObjectAllocator<H3DlgDefButton>().allocate(1);
        if (b)
            THISCALL_12(H3DlgDefButton*, 0x455BD0, b, x, y, width, height, id, defName, frame, clickFrame, closeDialog, hotkey, 2);
        return b;
    }
    _H3API_ H3DlgDefButton* H3DlgDefButton::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
    {
        H3DlgDefButton* b = Create(x, y, 0, 0, id, defName, frame, clickFrame, closeDialog, hotkey);
        if (b && b->loadedDef)
        {
            b->widthItem  = b->loadedDef->widthDEF;
            b->heightItem = b->loadedDef->heightDEF;
        }
        return b;
    }
    _H3API_ H3DlgDefButton* H3DlgDefButton::Create(INT32 x, INT32 y, LPCSTR defName, INT32 frame, INT32 clickFrame)
    {
        return Create(x, y, 0, defName, frame, clickFrame, 0, 0);
    }
} /* namespace h3 */
