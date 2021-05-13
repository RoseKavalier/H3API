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
#include "h3api/H3Constants/H3CstDlg.hpp"
#include "h3api/H3Constants/H3CstDlgControls.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgItem);
	struct H3DlgFrame;
	struct H3DlgDef;
	struct H3DlgDefButton;
	struct H3DlgCaptionButton;
	struct H3DlgCustomButton;
	struct H3DlgPcx;
	struct H3DlgPcx16;
	struct H3DlgEdit;
	struct H3DlgText;
	struct H3DlgTextPcx;
	class  H3DlgHintBar;
	struct H3DlgScrollableText;
	struct H3DlgScrollbar;
	struct H3DlgTextScrollbar;
	struct H3BaseDlg;
	struct H3Font;
	struct H3LoadedDef;
	struct H3LoadedPcx;
	struct H3LoadedPcx16;
	struct H3Msg;
	struct H3RGB565;
	struct H3RGB888;

	typedef UINT16 RGB565;

#pragma pack(push, 4)

	struct H3DlgItem : H3Allocator
	{
		_H3API_SIZE_(0x30);
		_H3API_VTABLE_(0x643CA0);
		enum eVTables
		{
			VT_EDITTEXT_HISCORE_NAME = 0x63EBF4, // see 4E9760
		};

	protected:

		/**< @ brief [v00]*/
		_H3API_ virtual H3DlgItem* vDestroy(BOOL8 deallocate) = 0;
		/**< @ brief [v04]*/
		_H3API_ virtual BOOL       vInitiate(INT16 zorder, H3BaseDlg* parent) = 0;
		/** @ brief [v08]*/
		_H3API_ virtual INT        vProcessMsg(H3Msg& msg) = 0;
		/** @ brief [v0C] no action except H3DlgPcx*/
		_H3API_ virtual VOID       vDrawPcx8(PWORD buffer, RGB565 color) = 0;
		/** @ brief [v10]*/
		_H3API_ virtual VOID       vDrawToWindow() = 0;
		/** @ brief [v14]*/
		_H3API_ virtual INT        vGetHeight() const = 0;
		/** @ brief [v18]*/
		_H3API_ virtual INT        vGetWidth() const = 0;
		/** @ brief [v1C]*/
		_H3API_ virtual VOID       vCallParent() const = 0;
		/** @ brief [v20]*/
		_H3API_ virtual VOID       vDarkenArea() const = 0;
		/** @ brief [v24]*/
		_H3API_ virtual VOID       vEnable(BOOL8 state) = 0;
		/** @ brief [v28]*/
		_H3API_ virtual VOID       vGetFocus() = 0;
		/** @ brief [v2C]*/
		_H3API_ virtual VOID       vLoseFocus() = 0;
		/** @ brief [v30]*/
		_H3API_ virtual VOID       vNullsub(INT unknown) const = 0;

		/** @ brief [04]*/
		H3BaseDlg*    parent;
		/** @ brief [08]*/
		H3DlgItem*    nextDlgItem;
		/** @ brief [0C]*/
		H3DlgItem*    previousDlgItem;
		/** @ brief [10]*/
		UINT16        id;
		/** @ brief [12]*/
		INT16         zOrder;
		/** @ brief [14] eType*/
		eControl      type;
		/** @ brief [16]*/
		eControlState state;
		/** @ brief [18]*/
		INT16         xPos;
		/** @ brief [1A]*/
		INT16         yPos;
		/** @ brief [1C]*/
		UINT16        widthItem;
		/** @ brief [1E]*/
		UINT16        heightItem;
		/** @ brief [20]*/
		LPCSTR        hint;
		/** @ brief [24]*/
		LPCSTR        rightClickHint;
		/** @ brief [28]*/
		BOOL8         hintsAreAllocated;
		/** @ brief [2C]*/
		INT32         deactivatesCount;

		_H3API_ BOOL NotifyParent(H3Msg& msg);
		_H3API_ BOOL TranslateUnprocessedMessage(H3Msg& msg);

	public:
		_H3API_ VOID       EnableItem(BOOL enable);
		_H3API_ VOID       Enable();
		_H3API_ VOID       Disable();
		_H3API_ INT16      GetX() const;
		_H3API_ INT16      GetY() const;
		_H3API_ INT32      GetAbsoluteX() const;
		_H3API_ INT32      GetAbsoluteY() const;
		_H3API_ BOOL       IsEnabled() const;
		_H3API_ BOOL       IsActive() const;
		_H3API_ VOID       SetX(UINT16 x);
		_H3API_ VOID       SetY(UINT16 y);
		_H3API_ INT32      GetHeight() const;
		_H3API_ INT32      GetWidth() const;
		_H3API_ VOID       SetWidth(UINT16 w);
		_H3API_ VOID       SetHeight(UINT16 h);
		_H3API_ VOID       Draw(); // draw new contents through vTable
		_H3API_ VOID       Refresh(); // refresh screen through parent dlg
		_H3API_ H3DlgItem* Hide();
		_H3API_ VOID       HideDeactivate();
		_H3API_ VOID       ShowActivate();
		_H3API_ H3DlgItem* Show();
		_H3API_ VOID       Shade();
		_H3API_ VOID       UnShade();
		_H3API_ H3DlgItem* Activate();   // allows processing of H3Msg
		_H3API_ H3DlgItem* DeActivate(); // prevents processing of H3Msg
		_H3API_ BOOL       IsVisible() const;
		_H3API_ BOOL       IsSet(eControlState state) const;
		_H3API_ VOID       AddState(eControlState state);
		_H3API_ VOID       RemoveState(eControlState state);
		_H3API_ LPCSTR     GetHint() const;
		_H3API_ VOID       SetHint(LPCSTR msg);
		_H3API_ UINT16     GetID() const;
		_H3API_ VOID       ParentRedraw(); // redraw through parent
		_H3API_ VOID       ColorToPlayer(INT8 player);
		_H3API_ VOID       SendCommand(INT32 command, INT32 parameter);
		_H3API_ VOID       SetHints(LPCSTR shortTipText, LPCSTR rightClickHint, BOOL allocateMemory);
		_H3API_ VOID       DrawTempFrame(INT thickness, BYTE r, BYTE g, BYTE b) const;
		_H3API_ VOID       DrawTempFrame(INT thickness, const H3RGB888& color) const;

		_H3API_ H3BaseDlg* GetParent() const;
		_H3API_ H3DlgItem* GetNextItem() const;
		_H3API_ H3DlgItem* GetPreviousItem() const;

		template<typename ItemType>
		ItemType* Cast();
	};
	_H3API_ASSERT_SIZE_(H3DlgItem);

#pragma pack(pop) /* align-4 */

	template<typename ItemType>
	inline typename ItemType* H3DlgItem::Cast()
	{
		return reinterpret_cast<ItemType*>(this);
	}

} /* namespace h3 */
