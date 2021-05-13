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
#include "h3api/H3DialogControls/H3DlgText.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgTextPcx);

#pragma pack(push, 4)

	struct H3DlgTextPcx : public H3DlgText
	{
		_H3API_SIZE_(0x54);
		_H3API_VTABLE_(0x642DF8);
	protected:
		// * +50
		H3LoadedPcx* loadedPcx;
	public:

		_H3API_ static H3DlgTextPcx* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			LPCSTR text, LPCSTR fontName, LPCSTR pcxName, INT32 color, INT32 id = 0,
			INT32 align = eTextAlignment::MIDDLE_CENTER);
		_H3API_ static H3DlgTextPcx* Create(INT32 x, INT32 y, LPCSTR text, LPCSTR fontName,
			LPCSTR pcxName, INT32 color, INT32 align);
	};
	_H3API_ASSERT_SIZE_(H3DlgTextPcx);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
