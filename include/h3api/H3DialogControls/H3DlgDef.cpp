//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgDef.hpp"
#include "h3api/H3Assets/H3LoadedDef.hpp"

namespace h3
{
    _H3API_ H3DlgDef* H3DlgDef::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 secondFrame, INT32 mirror, BOOL closeDialog)
    {
        H3DlgDef* d = H3ObjectAllocator<H3DlgDef>().allocate(1);
        if (d)
            THISCALL_12(H3DlgDef*, 0x4EA800, d, x, y, width, height, id, defName, frame, secondFrame, mirror, closeDialog, 0x10);
        return d;
    }
    _H3API_ H3DlgDef* H3DlgDef::Create(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 secondFrame, INT32 mirror, BOOL closeDialog)
    {
        H3DlgDef* d = Create(x, y, 0, 0, id, defName, frame, secondFrame, mirror, closeDialog);
        if (d && d->loadedDef)
        {
            d->widthItem = d->loadedDef->widthDEF;
            d->heightItem = d->loadedDef->heightDEF;
        }
        return d;
    }
    _H3API_ H3DlgDef* H3DlgDef::Create(INT32 x, INT32 y, LPCSTR defName, INT32 frame, INT32 group)
    {
        H3DlgDef* d = Create(x, y, 0, 0, 0, defName, frame, group, 0, 0);
        if (d && d->loadedDef)
        {
            d->widthItem = d->loadedDef->widthDEF;
            d->heightItem = d->loadedDef->heightDEF;
        }
        return d;
    }
    _H3API_ VOID H3DlgDef::SetFrame(INT32 frame)
    {
        defFrame = frame;
    }
    _H3API_ INT32 H3DlgDef::GetFrame() const
    {
        return defFrame;
    }
    _H3API_ INT32 H3DlgDef::GetGroup() const
    {
        return defGroup;
    }
    _H3API_ VOID H3DlgDef::SetGroup(INT32 group)
    {
        defGroup = group;
    }
    _H3API_ VOID H3DlgDef::ColorDefToPlayer(INT32 id)
    {
        loadedDef->ColorToPlayer(id);
    }
    _H3API_ H3LoadedDef* H3DlgDef::GetDef()
    {
        return loadedDef;
    }
} /* namespace h3 */
