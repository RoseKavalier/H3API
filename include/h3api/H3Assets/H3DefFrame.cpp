//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3DefFrame.hpp"
#include "h3api/H3Assets/H3LoadedPcx16.hpp"

namespace h3
{
    _H3API_ VOID H3DefFrame::DrawToPcx16(INT src_x, INT src_y, INT src_width, INT src_height,
        H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, H3Palette565* palette565, BOOL mirror, BOOL do_not_use_special_colors)
    {
        THISCALL_14(VOID, 0x47BE90, this, src_x, src_y, src_width, src_height, pcx16->buffer,
            dst_x, dst_y, pcx16->width, pcx16->height, pcx16->scanlineSize, palette565, mirror, do_not_use_special_colors);
    }
} /* namespace h3 */
