//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgTextPcx.hpp"
#include "h3api/H3Assets/H3LoadedPcx.hpp"

namespace h3
{
    _H3API_ H3DlgTextPcx* H3DlgTextPcx::Create(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text,
        LPCSTR fontName, LPCSTR pcxName, INT32 color, INT32 id, INT32 align)
    {
        H3DlgTextPcx* t = H3ObjectAllocator<H3DlgTextPcx>().allocate(1);
        if (t)
            THISCALL_12(H3DlgTextPcx*, 0x5BCB70, t, x, y, width, height, text, fontName,
                pcxName, color, id, align, 8);
        return t;
    }
    _H3API_ H3DlgTextPcx* H3DlgTextPcx::Create(INT32 x, INT32 y, LPCSTR text, LPCSTR fontName,
        LPCSTR pcxName, INT32 color, INT32 align)
    {
        H3DlgTextPcx* t = Create(x, y, 0, 0, text, fontName, pcxName, color, 0, align);
        if (t && t->loadedPcx)
        {
            t->widthItem = t->loadedPcx->width;
            t->heightItem = t->loadedPcx->height;
        }
        return t;
    }
} /* namespace h3 */
