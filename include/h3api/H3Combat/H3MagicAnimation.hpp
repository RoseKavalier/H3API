//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-02              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
    _H3API_DECLARE_(MagicAnimation);

#pragma pack(push, 4)

    struct H3MagicAnimation
    {
        _H3API_SIZE_(0x0C);
        _H3API_VTABLE_(0x641E18);

        LPCSTR defName;
        LPCSTR name;
        INT32 type;
    };
    _H3API_ASSERT_SIZE_(H3MagicAnimation);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
