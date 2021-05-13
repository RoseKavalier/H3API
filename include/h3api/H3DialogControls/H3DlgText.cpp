//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgText.hpp"

namespace h3
{
    _H3API_ H3DlgText* H3DlgText::Create(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text,
                        LPCSTR fontName, INT32 color, INT32 id, INT32 align, INT32 bkColor)
    {
        H3DlgText* t = H3ObjectAllocator<H3DlgText>().allocate(1);
        if (t)
            THISCALL_12(H3DlgText*, 0x5BC6A0, t, x, y, width, height, text, fontName,
                        color, id, align, bkColor, 8);
        return t;
    }
    _H3API_ H3String& H3DlgText::GetH3String()
    {
        return text;
    }
    _H3API_ VOID H3DlgText::SetText(LPCSTR text)
    {
        vSetText(text);
    }
    _H3API_ VOID H3DlgText::SetText(const H3String& text)
    {
        vSetText(text.String());
    }
    _H3API_ VOID H3DlgText::SetAlignment(eTextAlignment align)
    {
        alignment = align;
    }
} /* namespace h3 */
