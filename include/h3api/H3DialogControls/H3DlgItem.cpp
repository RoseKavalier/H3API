//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3DialogControls/H3DlgItem.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"
#include "h3api/H3Dialogs/H3CustomDialog.hpp"
#include "h3api/H3Assets/H3LoadedPcx16.hpp"
#include "h3api/H3Managers/H3WindowManager.hpp"

namespace h3
{
    _H3API_ BOOL H3DlgItem::NotifyParent(H3Msg& msg)
    {
        return reinterpret_cast<H3Dlg*>(parent)->Notify(this, msg);
    }
    _H3API_ BOOL H3DlgItem::TranslateUnprocessedMessage(H3Msg& msg)
    {
        switch (msg.command)
        {
        case eMsgCommand::WHEEL_BUTTON:
            if (msg.subtype != eMsgSubtype::MOUSE_WHEEL_BUTTON_DOWN ||
                msg.subtype != eMsgSubtype::MOUSE_WHEEL_BUTTON_UP)
                break;
            /* fall through */
        case eMsgCommand::MOUSE_WHEEL:
        {
            if (deactivatesCount > 0)
                break;
            if (!IsActive())
                break;
            const int x = msg.GetX() - parent->GetX();
            const int y = msg.GetY() - parent->GetY();
            if ((x < GetX()) || (y < GetY()) || (x >= GetX() + GetWidth()) || (y >= GetY() + GetHeight()))
                break;
            return NotifyParent(msg);
        }
        default:
            break;
        }
        return FALSE;
    }

    _H3API_ VOID H3DlgItem::EnableItem(BOOL enable)
    {
        vEnable(enable);
    }
    _H3API_ VOID H3DlgItem::Enable()
    {
        EnableItem(TRUE);
    }
    _H3API_ VOID H3DlgItem::Disable()
    {
        EnableItem(FALSE);
    }
    _H3API_ INT16 H3DlgItem::GetX() const
    {
        return xPos;
    }
    _H3API_ INT16 H3DlgItem::GetY() const
    {
        return yPos;
    }
    _H3API_ INT32 H3DlgItem::GetAbsoluteX() const
    {
        return xPos + parent->GetX();
    }
    _H3API_ INT32 H3DlgItem::GetAbsoluteY() const
    {
        return yPos + parent->GetY();
    }
    _H3API_ BOOL H3DlgItem::IsEnabled() const
    {
        return !(state & 0x20);
    }
    _H3API_ BOOL H3DlgItem::IsActive() const
    {
        return state & eControlState::ACTIVE;
    }
    _H3API_ VOID H3DlgItem::SetX(UINT16 x)
    {
        xPos = x;
    }
    _H3API_ VOID H3DlgItem::SetY(UINT16 y)
    {
        yPos = y;
    }
    _H3API_ INT32 H3DlgItem::GetHeight() const
    {
        return heightItem;
    }
    _H3API_ INT32 H3DlgItem::GetWidth() const
    {
        return widthItem;
    }
    _H3API_ VOID H3DlgItem::SetWidth(UINT16 w)
    {
        widthItem = w;
    }
    _H3API_ VOID H3DlgItem::SetHeight(UINT16 h)
    {
        heightItem = h;
    }
    _H3API_ VOID H3DlgItem::Draw()
    {
        vDrawToWindow();
    }
    _H3API_ VOID H3DlgItem::Refresh()
    {
        parent->Redraw(xPos, yPos, widthItem, heightItem);
    }
    _H3API_ H3DlgItem* H3DlgItem::Hide()
    {
        RemoveState(eControlState::VISIBLE);
        return this;
    }
    _H3API_ VOID H3DlgItem::HideDeactivate()
    {
        RemoveState(eControlState::ACTIVE | eControlState::VISIBLE);
    }
    _H3API_ VOID H3DlgItem::ShowActivate()
    {
        AddState(eControlState::ACTIVE | eControlState::VISIBLE);
    }
    _H3API_ H3DlgItem* H3DlgItem::Show()
    {
        AddState(eControlState::VISIBLE);
        return this;
    }
    _H3API_ VOID H3DlgItem::Shade()
    {
        AddState(eControlState::SHADED);
    }
    _H3API_ VOID H3DlgItem::UnShade()
    {
        RemoveState(eControlState::SHADED);
    }
    _H3API_ H3DlgItem* H3DlgItem::Activate()
    {
        AddState(eControlState::ACTIVE);
        return this;
    }
    _H3API_ H3DlgItem* H3DlgItem::DeActivate()
    {
        RemoveState(eControlState::ACTIVE);
        return this;
    }
    _H3API_ BOOL H3DlgItem::IsVisible() const
    {
        return IsSet(eControlState::VISIBLE);
    }
    _H3API_ BOOL H3DlgItem::IsSet(eControlState state) const
    {
        return this->state & state;
    }
    _H3API_ VOID H3DlgItem::AddState(eControlState state)
    {
        this->state |= state;
    }
    _H3API_ VOID H3DlgItem::RemoveState(eControlState state)
    {
        this->state &= eControlState(~state);
    }
    _H3API_ LPCSTR H3DlgItem::GetHint() const
    {
        return hint;
    }
    _H3API_ VOID H3DlgItem::SetHint(LPCSTR msg)
    {
        hint = msg;
    }
    _H3API_ UINT16 H3DlgItem::GetID() const
    {
        return id;
    }
    _H3API_ VOID H3DlgItem::ParentRedraw()
    {
        parent->Redraw(xPos, yPos, widthItem, heightItem);
    }
    _H3API_ VOID H3DlgItem::ColorToPlayer(INT8 player)
    {
        THISCALL_2(VOID, 0x4501D0, this, player);
    }
    _H3API_ VOID H3DlgItem::SendCommand(INT32 command, INT32 parameter)
    {
        THISCALL_3(VOID, 0x5FED80, this, command, parameter);
    }
    _H3API_ VOID H3DlgItem::SetHints(LPCSTR shortTipText, LPCSTR rightClickHint, BOOL allocateMemory)
    {
        THISCALL_4(void, 0x5FEE00, this, shortTipText, rightClickHint, allocateMemory);
    }
    _H3API_ VOID H3DlgItem::DrawTempFrame(INT thickness, BYTE r, BYTE g, BYTE b) const
    {
        H3LoadedPcx16* pcx = H3WindowManager::Get()->GetDrawBuffer();
        if (!pcx)
            return;
        pcx->DrawThickFrame(GetAbsoluteX(), GetAbsoluteY(), GetWidth(), GetHeight(), thickness, r, g, b);
    }
    _H3API_ VOID H3DlgItem::DrawTempFrame(INT thickness, const H3RGB888& color) const
    {
        DrawTempFrame(thickness, color.r, color.g, color.b);
    }
    _H3API_ H3BaseDlg* H3DlgItem::GetParent() const
    {
        return parent;
    }
    _H3API_ H3DlgItem* H3DlgItem::GetNextItem() const
    {
        return nextDlgItem;
    }
    _H3API_ H3DlgItem* H3DlgItem::GetPreviousItem() const
    {
        return previousDlgItem;
    }
} /* namespace h3 */
