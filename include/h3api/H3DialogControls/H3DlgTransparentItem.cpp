//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgTransparentItem.hpp"

namespace h3
{
    _H3API_ H3DlgTransparentItem* H3DlgTransparentItem::Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id)
    {
        H3DlgTransparentItem* d = H3ObjectAllocator<H3DlgTransparentItem>().allocate(1);
        if (d)
            THISCALL_7(H3DlgTransparentItem*, 0x44FBE0, d, x, y, width, height, id, 1);
        return d;
    }
} /* namespace h3 */
