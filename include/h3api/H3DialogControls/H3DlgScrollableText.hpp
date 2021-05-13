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
#include "h3api/H3Containers/H3Vector.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgScrollableText);
	struct H3String;
	struct H3LoadedPcx16;

#pragma pack(push, 4)

	struct H3DlgScrollableText : public H3DlgItem
	{
		_H3API_SIZE_(0x5C);
		_H3API_VTABLE_(0x642D1C);
	protected:
		/** @brief [30]*/
		LPCSTR               font;
		/** @brief [34]*/
		H3Vector<H3String>   textLines;
		/** @brief [44]*/
		H3Vector<H3DlgText*> textItems;
		/** @brief [54]*/
		H3DlgTextScrollbar*  scrollBar;
		/** @brief [58]*/
		H3LoadedPcx16*       canvas;
	public:
		_H3API_ static H3DlgScrollableText* Create(LPCSTR text, INT32 x, INT32 y,
			INT32 width, INT32 height, LPCSTR font, INT32 color, INT32 isBlue);
	};
	_H3API_ASSERT_SIZE_(H3DlgScrollableText);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
