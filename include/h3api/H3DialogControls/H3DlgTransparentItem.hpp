//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3DialogControls/H3DlgItem.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgTransparentItem);

#pragma pack(push, 4)

	struct H3DlgTransparentItem : H3DlgItem
	{
		_H3API_SIZE_(0x30);
		_H3API_VTABLE_(0x63BA24);
	protected:
		// +[34]
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0;
	public:
		_H3API_ static H3DlgTransparentItem* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id);
	};
	_H3API_ASSERT_SIZE_(H3DlgTransparentItem);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
