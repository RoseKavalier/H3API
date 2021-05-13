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
	_H3API_DECLARE_(DlgFrame);
	struct H3RGB565;

#pragma pack(push, 4)

	/** @brief 1-pixel wide rectangular frame with the color of your choice*/
	struct H3DlgFrame : public H3DlgItem
	{
		_H3API_SIZE_(0x38);
		_H3API_VTABLE_(0x63BA5C);
	protected:
		_H3API_ virtual BOOL8 vNullSub2(INT unk1, INT unk2) = 0; /**< @ brief [v34]*/

	protected:
		/** @ brief [30] H3RGB565 color*/
		RGB565   color565;
		h3align  _f_32[2];
		/** @ brief [34] modifies hue within frame toward RGB565 color, see 0x44FEB4*/
		BOOL8    changeHue;
	public:
		_H3API_ static H3DlgFrame* Create(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color);
		_H3API_ static H3DlgFrame* Create(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color);
		// * the around parameter will create the frame around the edge
		// * of the dialog item instead of covering some of its pixels
		_H3API_ static H3DlgFrame* Create(H3DlgItem* target, RGB565 color, INT id = 0, BOOL around_edge = false);

		_H3API_ VOID      ChangeColor(RGB565 color);
		_H3API_ VOID      HideHue();
		_H3API_ VOID      ShowHue();
		_H3API_ VOID      ToggleHue();
		_H3API_ H3RGB565& GetColor();
	};
	_H3API_ASSERT_SIZE_(H3DlgFrame);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
