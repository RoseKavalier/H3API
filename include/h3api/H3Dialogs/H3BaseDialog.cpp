//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3BaseDialog.hpp"
#include "h3api/H3DialogControls.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"
#include "h3api/H3Assets/H3Resource.hpp"
#include "h3api/H3Managers/H3WindowManager.hpp"
#include "h3api/H3Assets/H3LoadedDef.hpp"
#include "h3api/H3Assets/H3LoadedPcx.hpp"

namespace h3
{
	_H3API_ H3BaseDlg::H3BaseDlg(INT x, INT y, INT w, INT h) :
		zOrder(-1), nextDialog(), lastDialog(), flags(0x12), state(),
		xDlg(x), yDlg(y), widthDlg(w), heightDlg(h), lastItem(), firstItem(),
		focusedItemId(-1), pcx16(), deactivatesCount()
	{
	}
	_H3API_ VOID H3BaseDlg::Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy)
	{
		H3WindowManager::Get()->H3Redraw(xDlg + x, yDlg + y, dx, dy);
	}
	_H3API_ VOID H3BaseDlg::Redraw()
	{
		vRedraw(TRUE, -65535, 65535);
	}
	_H3API_ INT32 H3BaseDlg::DefaultProc(H3Msg* msg)
	{
		return DefaultProc(*msg);
	}
	_H3API_ INT32 H3BaseDlg::DefaultProc(H3Msg& msg)
	{
		return THISCALL_2(INT32, 0x41B120, this, &msg);
	}
	_H3API_ H3DlgItem* H3BaseDlg::getDlgItem(UINT16 id, h3func vtable) const
	{
		H3DlgItem* it = firstItem;
		if (it == nullptr)
			return it;
		do
		{
			if ((it->GetID() == id) && (*reinterpret_cast<h3func*>(it) == vtable))
				break;
		} while (it = it->GetNextItem());

		return it;
	}
	_H3API_ INT32 H3BaseDlg::GetWidth() const
	{
		return widthDlg;
	}
	_H3API_ INT32 H3BaseDlg::GetHeight() const
	{
		return heightDlg;
	}
	_H3API_ INT32 H3BaseDlg::GetX() const
	{
		return xDlg;
	}
	_H3API_ INT32 H3BaseDlg::GetY() const
	{
		return yDlg;
	}
	_H3API_ BOOL H3BaseDlg::IsTopDialog() const
	{
		return nextDialog == nullptr;
	}
	_H3API_ VOID H3BaseDlg::AddControlState(INT32 id, eControlState state)
	{
		THISCALL_3(VOID, 0x5FF490, this, id, state);
	}
	_H3API_ VOID H3BaseDlg::RemoveControlState(INT32 id, eControlState state)
	{
		THISCALL_3(VOID, 0x5FF520, this, id, state);
	}
	_H3API_ H3DlgItem* H3BaseDlg::AddItem(H3DlgItem* item, BOOL initiate /*= TRUE*/)
	{
		dlgItems += item;
		if (initiate)
			return THISCALL_3(H3DlgItem*, 0x5FF270, this, item, -1); // LoadItem
		else
			return item;
	}
	_H3API_ H3DlgDef* H3BaseDlg::GetDef(UINT16 id) const
	{
		return get<H3DlgDef>(id);
	}
	_H3API_ H3DlgPcx* H3BaseDlg::GetPcx(UINT16 id) const
	{
		return get<H3DlgPcx>(id);
	}
	_H3API_ H3DlgEdit* H3BaseDlg::GetEdit(UINT16 id) const
	{
		return get<H3DlgEdit>(id);
	}
	_H3API_ H3DlgText* H3BaseDlg::GetText(UINT16 id) const
	{
		return get<H3DlgText>(id);
	}
	_H3API_ H3DlgFrame* H3BaseDlg::GetFrame(UINT16 id) const
	{
		return get<H3DlgFrame>(id);
	}
	_H3API_ H3DlgPcx16* H3BaseDlg::GetPcx16(UINT16 id) const
	{
		return get<H3DlgPcx16>(id);
	}
	_H3API_ H3DlgTextPcx* H3BaseDlg::GetTextPcx(UINT16 id) const
	{
		return get<H3DlgTextPcx>(id);
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::GetDefButton(UINT16 id) const
	{
		return get<H3DlgDefButton>(id);
	}
	_H3API_ H3DlgScrollbar* H3BaseDlg::GetScrollbar(UINT16 id) const
	{
		return get<H3DlgScrollbar>(id);
	}
	_H3API_ H3DlgTransparentItem* H3BaseDlg::GetTransparent(UINT16 id) const
	{
		return get<H3DlgTransparentItem>(id);
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::GetCustomButton(UINT16 id) const
	{
		return get<H3DlgCustomButton>(id);
	}
	_H3API_ H3DlgCaptionButton* H3BaseDlg::GetCaptionButton(UINT16 id) const
	{
		return get<H3DlgCaptionButton>(id);
	}
	_H3API_ H3DlgScrollableText* H3BaseDlg::GetScrollableText(UINT16 id) const
	{
		return get<H3DlgScrollableText>(id);
	}
	_H3API_ H3DlgTransparentItem* H3BaseDlg::CreateHidden(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id)
	{
		H3DlgTransparentItem* it = H3DlgTransparentItem::Create(x, y, width, height, id);
		if (it)
			AddItem(it);
		return it;
	}
	_H3API_ H3LoadedPcx16* H3BaseDlg::GetCurrentPcx()
	{
		return pcx16;
	}
	_H3API_ H3DlgItem* H3BaseDlg::ItemAtPosition(H3Msg* msg)
	{
		return ItemAtPosition(*msg);
	}
	_H3API_ H3DlgItem* H3BaseDlg::ItemAtPosition(H3Msg& msg)
	{
		return THISCALL_3(H3DlgItem*, 0x5FF9A0, this, msg.GetX(), msg.GetY());
	}
	_H3API_ H3Vector<H3DlgItem*>& H3BaseDlg::GetList()
	{
		return dlgItems;
	}
	_H3API_ H3DlgItem* H3BaseDlg::GetH3DlgItem(UINT16 id)
	{
		return THISCALL_2(H3DlgItem*, 0x5FF5B0, this, id);
	}
	_H3API_ VOID H3BaseDlg::RedrawItem(UINT16 itemID)
	{
		if (H3DlgItem* it = GetH3DlgItem(itemID))
			it->Refresh();
	}
	_H3API_ VOID H3BaseDlg::EnableItem(UINT16 id, BOOL enable)
	{
		H3DlgItem* it = GetH3DlgItem(id);
		if (it)
			it->EnableItem(enable);
	}
	_H3API_ VOID H3BaseDlg::SendCommandToItem(INT32 command, UINT16 itemID, UINT32 parameter)
	{
		THISCALL_5(VOID, 0x5FF400, this, 0x200, command, itemID, parameter);
	}
	_H3API_ VOID H3BaseDlg::SendCommandToAllItems(INT32 command, INT32 itemID, INT32 parameter)
	{
		H3Msg msg;
		msg.SetCommand(eMsgCommand::ITEM_COMMAND, eMsgSubtype(command), itemID, eMsgFlag::NONE, 0, 0, parameter, 0);
		THISCALL_2(VOID, 0x5FF3A0, this, &msg);
	}
	_H3API_ VOID H3BaseDlg::AdjustToPlayerColor(INT8 player, UINT16 itemId)
	{
		if (H3DlgItem* it = GetH3DlgItem(itemId))
			it->ColorToPlayer(player);
	}
	_H3API_ H3DlgFrame* H3BaseDlg::CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, RGB565 color)
	{
		H3DlgFrame* frame = H3DlgFrame::Create(x, y, width, height, id, color);
		if (frame)
			AddItem(frame);
		return frame;
	}
	_H3API_ H3DlgFrame* H3BaseDlg::CreateFrame(INT32 x, INT32 y, INT32 width, INT32 height, RGB565 color)
	{
		H3DlgFrame* frame = H3DlgFrame::Create(x, y, width, height, 0, color);
		if (frame)
			AddItem(frame);
		return frame;
	}
	_H3API_ H3DlgFrame* H3BaseDlg::CreateFrame(H3DlgItem* target, RGB565 color, INT id, BOOL around_edge)
	{
		H3DlgFrame* frame = H3DlgFrame::Create(target, color, id, around_edge);
		if (frame)
			AddItem(frame);
		return frame;
	}
	_H3API_ H3DlgDef* H3BaseDlg::CreateDef(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 group, INT32 mirror, BOOL closeDialog)
	{
		H3DlgDef* def = H3DlgDef::Create(x, y, width, height, id, defName, frame, group, mirror, closeDialog);
		if (def)
			AddItem(def);
		return def;
	}
	_H3API_ H3DlgDef* H3BaseDlg::CreateDef(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 group, INT32 mirror, BOOL closeDialog)
	{
		H3DlgDef* def = H3DlgDef::Create(x, y, id, defName, frame, group, mirror, closeDialog);
		if (def)
			AddItem(def);
		return def;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
	{
		H3DlgDefButton* but = H3DlgDefButton::Create(x, y, width, height, id, defName, frame, clickFrame, closeDialog, hotkey);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateButton(INT32 x, INT32 y, INT32 id, LPCSTR defName, INT32 frame, INT32 clickFrame, BOOL closeDialog, INT32 hotkey)
	{
		H3DlgDefButton* but = CreateButton(x, y, 0, 0, id, defName, frame, clickFrame, closeDialog, hotkey);
		if (but)
		{
			H3LoadedDef* def = but->GetDef();
			if (def)
			{
				but->SetWidth(def->widthDEF);
				but->SetHeight(def->heightDEF);
			}
		}
		return but;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOKButton(INT32 x, INT32 y)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, int(eControlId::OK), NH3Dlg::Assets::OKAY_DEF, 0, 1, TRUE, NH3VKey::H3VK_ENTER);
		if (button)
		{
			AddItem(H3DlgPcx::Create(x - 1, y - 1, NH3Dlg::Assets::BOX_64_30_PCX));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateSaveButton(INT32 x, INT32 y, LPCSTR button_name)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, int(eControlId::SAVE), button_name, 0, 1, FALSE, NH3VKey::H3VK_S);
		if (button)
		{
			AddItem(H3DlgFrame::Create(button, H3RGB565::Highlight(), 0, TRUE));
			//AddItem(H3DlgPcx::Create(x - 1, y - 1, NH3Dlg::Assets::BOX_64_32_PCX));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOnOffCheckbox(INT32 x, INT32 y, INT32 id, INT32 frame, INT32 clickFrame)
	{
		if (clickFrame == -1)
			clickFrame = 1 - frame;
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, id, NH3Dlg::Assets::ON_OFF_CHECKBOX, frame, clickFrame, 0, 0);
		if (button)
			AddItem(button);
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOKButton()
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(25, heightDlg - 50, int(eControlId::OK), NH3Dlg::Assets::OKAY_DEF, 0, 1, TRUE, NH3VKey::H3VK_ENTER);
		if (button)
		{
			AddItem(H3DlgPcx::Create(25 - 1, heightDlg - 50 - 1, NH3Dlg::Assets::BOX_64_30_PCX));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateOK32Button(INT32 x, INT32 y)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, int(eControlId::OK), NH3Dlg::Assets::OKAY32_DEF, 0, 1, TRUE, NH3VKey::H3VK_ENTER);
		if (button)
		{
			AddItem(H3DlgPcx::Create(x - 1, y - 1, NH3Dlg::Assets::BOX_66_32_PCX));
			AddItem(button);
		}
		return button;
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateCancelButton()
	{
		return CreateCancelButton(widthDlg - 25 - 64, heightDlg - 50);
	}
	_H3API_ H3DlgDefButton* H3BaseDlg::CreateCancelButton(INT32 x, INT32 y)
	{
		H3DlgDefButton* button = H3DlgDefButton::Create(x, y, eControlId::CANCEL, NH3Dlg::Assets::CANCEL_DEF, 0, 1, TRUE, NH3VKey::H3VK_ESCAPE);
		if (button)
		{
			AddItem(H3DlgPcx::Create(x - 1, y - 1, NH3Dlg::Assets::BOX_64_30_PCX));
			AddItem(button);
		}
		return button;
	}

	_H3API_ H3DlgCaptionButton* H3BaseDlg::CreateCaptionButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, LPCSTR text, LPCSTR font, INT32 frame, INT32 group, BOOL closeDialog, INT32 hotkey, INT32 color)
	{
		H3DlgCaptionButton* but = H3DlgCaptionButton::Create(x, y, width, height, id, defName, text, font, frame, group, closeDialog, hotkey, color);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::CreateCustomButton(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
	{
		H3DlgCustomButton* but = H3DlgCustomButton::Create(x, y, width, height, id, defName, customProc, frame, clickFrame);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::CreateCustomButton(INT32 x, INT32 y, INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
	{
		H3DlgCustomButton* but = H3DlgCustomButton::Create(x, y, id, defName, customProc, frame, clickFrame);
		if (but)
			AddItem(but);
		return but;
	}
	_H3API_ H3DlgCustomButton* H3BaseDlg::CreateCustomButton(INT32 x, INT32 y, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame)
	{
		return CreateCustomButton(x, y, 0, defName, customProc, frame, clickFrame);
	}
	_H3API_ H3DlgPcx* H3BaseDlg::CreatePcx(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx* pcx = H3DlgPcx::Create(x, y, width, height, id, pcxName);
		if (pcx)
			AddItem(pcx);
		return pcx;
	}
	_H3API_ H3DlgPcx* H3BaseDlg::CreatePcx(INT32 x, INT32 y, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx* pcx = CreatePcx(x, y, 0, 0, id, pcxName);
		if (pcx && pcx->GetPcx())
		{
			H3LoadedPcx* p = pcx->GetPcx();
			pcx->SetWidth(p->width);
			pcx->SetHeight(p->height);
		}
		return pcx;
	}
	_H3API_ H3DlgPcx* H3BaseDlg::CreateLineSeparator(INT32 x, INT32 y, INT32 width)
	{
		return CreatePcx(x, y, width, 2, 0, NH3Dlg::HDassets::LINE_SEPARATOR);
	}
	_H3API_ H3DlgPcx16* H3BaseDlg::CreatePcx16(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, LPCSTR pcxName)
	{
		H3DlgPcx16* pcx = H3DlgPcx16::Create(x, y, width, height, id, pcxName);
		if (pcx)
			AddItem(pcx);
		return pcx;
	}
	_H3API_ H3DlgEdit* H3BaseDlg::CreateEdit(INT32 x, INT32 y, INT32 width, INT32 height, INT32 maxLength, LPCSTR text, LPCSTR fontName, INT32 color, INT32 align, LPCSTR pcxName, INT32 id, INT32 hasBorder, INT32 borderX, INT32 borderY)
	{
		H3DlgEdit* ed = H3DlgEdit::Create(x, y, width, height, maxLength, text, fontName, color, align, pcxName, id, hasBorder, borderX, borderY);
		if (ed)
			AddItem(ed);
		return ed;
	}
	_H3API_ H3DlgText* H3BaseDlg::CreateText(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName, INT32 color, INT32 id, eTextAlignment align, INT32 bkColor)
	{
		H3DlgText* tx = H3DlgText::Create(x, y, width, height, text, fontName, color, id, align, bkColor);
		if (tx)
			AddItem(tx);
		return tx;
	}
	_H3API_ H3DlgTextPcx* H3BaseDlg::CreateTextPcx(INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR text, LPCSTR fontName, LPCSTR pcxName, INT32 color, INT32 id, INT32 align)
	{
		H3DlgTextPcx* tx = H3DlgTextPcx::Create(x, y, width, height, text, fontName, pcxName, color, id, align);
		if (tx)
			AddItem(tx);
		return tx;
	}
	_H3API_ H3DlgScrollableText* H3BaseDlg::CreateScrollableText(LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height, LPCSTR font, INT32 color, INT32 isBlue)
	{
		H3DlgScrollableText* sc = H3DlgScrollableText::Create(text, x, y, width, height, font, color, isBlue);
		if (sc)
			AddItem(sc);
		return sc;
	}
	_H3API_ H3DlgScrollbar* H3BaseDlg::CreateScrollbar(INT32 x, INT32 y, INT32 width, INT32 height, INT32 id, INT32 ticksCount, H3DlgScrollbar_proc scrollbarProc, BOOL isBlue, INT32 stepSize, BOOL arrowsEnabled)
	{
		H3DlgScrollbar* sc = H3DlgScrollbar::Create(x, y, width, height, id, ticksCount, scrollbarProc, isBlue, stepSize, arrowsEnabled);
		if (sc)
			AddItem(sc);
		return sc;
	}
	_H3API_ H3ExtendedDlg::H3ExtendedDlg(INT x, INT y, INT w, INT h) :
		H3BaseDlg(x, y, w, h)
	{
	}
} /* namespace h3 */
