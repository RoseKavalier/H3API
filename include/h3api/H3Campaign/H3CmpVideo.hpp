//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-18              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
	_H3API_DECLARE_(CmpVideo);

#pragma pack(push, 4)

	struct H3CmpVideo
	{
		_H3API_SIZE_(0x14);
		_H3API_GET_INFO_(0x44D5C3 + 2, H3CmpVideo);

		LPCSTR  name;
		LPCSTR  loopName;
		BOOL8   isBink;
		BOOL8   fadein;
		BOOL8   fadeout;
		h3unk32 _f_0C[2];
	};

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
