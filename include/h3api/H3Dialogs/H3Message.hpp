//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Constants/H3CstVKey.hpp"
#include "h3api/H3Constants/H3CstMessages.hpp"

namespace h3
{

	_H3API_DECLARE_(Msg);
	struct H3BaseDlg;
	struct H3DlgItem;

#pragma pack(push, 4)

	struct H3Msg
	{
		_H3API_SIZE_(0x20);

		/** @brief [00] eCommand*/
		eMsgCommand command;
		/** @brief [04] eMsgSubtype*/
		eMsgSubtype subtype;
		/** @brief [08]*/
		INT32 itemId;
		/** @brief [0C] eMsgFlag*/
		eMsgFlag    flags;
		/** @brief [10] cursor position*/
		H3POINT     position;
		/** @brief [18] data to be sent to a window control*/
		VOID*       parameter;
		/** @brief [1C] can be multiple things but mostly observed parent dialog*/
		PVOID       parentDlg;

		_H3API_ VOID       SetCommand(eMsgCommand command, eMsgSubtype subtype, INT32 item_id, eMsgFlag flags,
									  INT32 x, INT32 y, INT32 param, INT32 flags2);
		_H3API_ VOID       SetCommand(INT32 cmd, INT32 param);
		_H3API_ H3DlgItem* ItemAtPosition(H3BaseDlg* dlg) const;
		_H3API_ INT32      KeyPressed()     const;
		_H3API_ BOOL       IsKeyPress()     const;
		_H3API_ BOOL       IsKeyDown()      const;
		_H3API_ BOOL       IsKeyHeld()      const;
		_H3API_ BOOL       IsMouseOver()    const;
		_H3API_ BOOL       IsWheelButton()  const;
		_H3API_ BOOL       IsLeftClick()    const;
		_H3API_ BOOL       IsLeftDown()     const;
		_H3API_ BOOL       IsRightClick()   const;
		_H3API_ BOOL       ClickOutside()   const;
		_H3API_ BOOL       IsAltPressed()   const;
		_H3API_ BOOL       IsCtrlPressed()  const;
		_H3API_ BOOL       IsShiftPressed() const;
		_H3API_ INT32      CloseDialog();

		_H3API_ BOOL       AltPressed()    const;
		_H3API_ BOOL       CtrlPressed()   const;
		_H3API_ BOOL       ShiftPressed()  const;

		_H3API_ eMsgFlag   GetFlag()   const;
		_H3API_ eVKey      GetKey()    const;
		_H3API_ INT        GetX()      const;
		_H3API_ INT        GetY()      const;
		_H3API_ H3POINT    GetCoords() const;
		/**
		 * @brief Get the parent dialog for some custom items when calling their custom proc.
		 * @return owning dialog of the current item
		 */
		_H3API_ H3BaseDlg* GetDlg() const;

		_H3API_ INT StopProcessing();
	};
	_H3API_ASSERT_SIZE_(H3Msg);
#pragma pack(pop) /* align-4 */

} /* namespace h3 */
