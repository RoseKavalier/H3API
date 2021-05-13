//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3Message.hpp"

namespace h3
{
	_H3API_ VOID H3Msg::SetCommand(eMsgCommand command, eMsgSubtype subtype, INT32 item_id, eMsgFlag flags, INT32 x, INT32 y, INT32 param, INT32 flags2)
	{
		this->command    = command;
		this->subtype    = subtype;
		this->itemId    = item_id;
		this->flags      = flags;
		this->position.x = x;
		this->position.y = y;
		this->parameter  = PVOID(param);
		this->parentDlg  = PVOID(flags2);
	}
	_H3API_ VOID H3Msg::SetCommand(INT32 cmd, INT32 param)
	{
		SetCommand(eMsgCommand::ITEM_COMMAND, eMsgSubtype(cmd), 0, eMsgFlag::NONE, 0, 0, param, 0);
	}
	_H3API_ H3DlgItem* H3Msg::ItemAtPosition(H3BaseDlg* dlg) const
	{
		return THISCALL_3(H3DlgItem*, 0x5FF9A0, dlg, position.x, position.y);
	}
	_H3API_ INT32 H3Msg::KeyPressed() const
	{
		return subtype;
	}
	_H3API_ BOOL H3Msg::IsKeyPress() const
	{
		return command == eMsgCommand::KEY_UP;
	}
	_H3API_ BOOL H3Msg::IsKeyDown() const
	{
		return command == eMsgCommand::KEY_DOWN;
	}
	_H3API_ BOOL H3Msg::IsKeyHeld() const
	{
		return command == eMsgCommand::KEY_HELD;
	}
	_H3API_ BOOL H3Msg::IsMouseOver() const
	{
		return command == eMsgCommand::MOUSE_OVER;
	}
	_H3API_ BOOL H3Msg::IsWheelButton() const
	{
		return command == eMsgCommand::WHEEL_BUTTON && subtype == eMsgSubtype::MOUSE_WHEEL_BUTTON_DOWN;
	}
	_H3API_ BOOL H3Msg::IsLeftClick() const
	{
		return command == eMsgCommand::MOUSE_BUTTON && subtype == eMsgSubtype::LBUTTON_CLICK;
	}
	_H3API_ BOOL H3Msg::IsLeftDown() const
	{
		return command == eMsgCommand::MOUSE_BUTTON && subtype == eMsgSubtype::LBUTTON_DOWN;
	}
	_H3API_ BOOL H3Msg::IsRightClick() const
	{
		return command == eMsgCommand::MOUSE_BUTTON && subtype == eMsgSubtype::RBUTTON_DOWN;
	}
	_H3API_ BOOL H3Msg::ClickOutside() const
	{
		return command == eMsgCommand::RCLICK_OUTSIDE || command == eMsgCommand::LCLICK_OUTSIDE;
	}
	_H3API_ BOOL H3Msg::IsAltPressed() const
	{
		return flags == eMsgFlag::ALT;
	}
	_H3API_ BOOL H3Msg::IsCtrlPressed() const
	{
		return flags == eMsgFlag::CTRL;
	}
	_H3API_ BOOL H3Msg::IsShiftPressed() const
	{
		return flags == eMsgFlag::SHIFT;
	}
	_H3API_ INT32 H3Msg::CloseDialog()
	{
		return STDCALL_1(INT32, 0x491640, this);
	}
	_H3API_ BOOL H3Msg::AltPressed() const
	{
		return flags & INT32(eMsgFlag::ALT);
	}
	_H3API_ BOOL H3Msg::CtrlPressed() const
	{
		return flags & INT32(eMsgFlag::CTRL);
	}
	_H3API_ BOOL H3Msg::ShiftPressed() const
	{
		return flags & INT32(eMsgFlag::SHIFT);
	}
	_H3API_ eMsgFlag H3Msg::GetFlag() const
	{
		return eMsgFlag(flags);
	}
	_H3API_ eVKey H3Msg::GetKey() const
	{
		return eVKey(subtype);
	}
	_H3API_ INT H3Msg::GetX() const
	{
		return position.x;
	}
	_H3API_ INT H3Msg::GetY() const
	{
		return position.y;
	}
	_H3API_ H3POINT H3Msg::GetCoords() const
	{
		return position;
	}
	_H3API_ H3BaseDlg* H3Msg::GetDlg() const
	{
		return reinterpret_cast<H3BaseDlg*>(parentDlg);
	}
	_H3API_ INT H3Msg::StopProcessing()
	{
		command = eMsgCommand::NONE;
		subtype = eMsgSubtype::NONE;
		return 2;
	}
} /* namespace h3 */
