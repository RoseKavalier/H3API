//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-08              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3RMG/H3RmgMap.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
namespace h3
{
    struct H3RmgObject;

#pragma pack(push, 4)

	struct H3RmgLocalMap : public H3RmgMap
	{
		_H3API_SIZE_(0x38);
		h3unk _f_18[16];
		H3Vector<H3RmgObject*> localObjects; /**< @brief [28]*/
	};
	_H3API_ASSERT_SIZE_(H3RmgLocalMap);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
