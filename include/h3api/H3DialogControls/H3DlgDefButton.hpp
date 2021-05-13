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
#include "h3api/H3Containers/H3String.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgDefButton);

#pragma pack(push, 4)

	/**
	 * @brief Created as size 0x6C, but proc is not used
	 * Although there is room for CustomProc, which is the same as H3DlgCustomButton,
	 * it is not passed as an argument to the function
	 */
	struct H3DlgDefButton : public H3DlgItem
	{
		_H3API_SIZE_(0x68);
		_H3API_VTABLE_(0x63BB54);
	protected:
		/** @brief [30]*/
		H3LoadedDef*    loadedDef;
		/** @brief [34]*/
		INT32           defFrame;
		/** @brief [38]*/
		INT32           defFrameOnClick;
		/** @brief [3C]*/
		INT32           mirror;
		/** @brief [40]*/
		h3unk32         _f_40;
		/** @brief [44]*/
		BOOL8           closeDialog;
		/** @brief [48] more than one hotkey can be associated*/
		H3Vector<INT32> hotkeys;
		/** @brief [58]*/
		H3String        caption;

	public:
		_H3API_ static H3DlgDefButton* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey);
		_H3API_ static H3DlgDefButton* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey);
		_H3API_ static H3DlgDefButton* Create(INT32 x, INT32 y, LPCSTR defName, INT32 frame, INT32 clickFrame);

		_H3API_ VOID         AddHotkey(INT32 key);
		_H3API_ VOID         SetFrame(INT32 frame);
		_H3API_ INT          ToggleFrame();
		_H3API_ INT32        GetFrame() const;
		_H3API_ INT32        GetClickFrame() const;
		_H3API_ VOID         ColorDefToPlayer(INT32 id);
		_H3API_ VOID         SetClickFrame(INT32 clickFrame);
		_H3API_ H3LoadedDef* GetDef();
	};
	_H3API_ASSERT_SIZE_(H3DlgDefButton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
