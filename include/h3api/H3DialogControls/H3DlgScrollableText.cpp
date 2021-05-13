//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgScrollableText.hpp"

namespace h3
{
     _H3API_ H3DlgScrollableText* H3DlgScrollableText::Create(LPCSTR text, INT32 x, INT32 y,
        INT32 width, INT32 height, LPCSTR font, INT32 color, INT32 isBlue)
    {
        H3DlgScrollableText* s = H3ObjectAllocator<H3DlgScrollableText>().allocate(1);
        if (s)
            THISCALL_9(H3DlgScrollableText*, 0x5BA360, s, text, x, y, width, height, font, color, isBlue);
        return s;
    }
} /* namespace h3 */
