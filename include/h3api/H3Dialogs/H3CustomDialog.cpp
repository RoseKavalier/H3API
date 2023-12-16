//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3CustomDialog.hpp"
#include "h3api/H3DialogControls.hpp"
#include "h3api/H3Assets.hpp"
#include "h3api/H3Dialogs/H3Message.hpp"
#include "h3api/H3Managers/H3MouseManager.hpp"
#include "h3api/H3Defines/H3PrimitivePointers.hpp"

namespace h3
{
	_H3API_ INT H3Dlg::CheckEnd(H3Msg& msg)
	{
		if (endDialog)
			return msg.CloseDialog();
		return 0;
	}
	_H3API_ H3Dlg::H3Dlg(int width, int height, int x, int y, BOOL statusBar, BOOL makeBackground, INT32 colorIndex) :
		H3NetworkDlg(x, y, width, height),
		enableDoubleClick(FALSE), lastClickTime(), lastClickedItem(nullptr),
		endDialog(FALSE), background(nullptr), hintBar(nullptr)
	{
		STDCALL_0(VOID, 0x597AA0); // stop video animation
		if (x == -1)
			xDlg = (H3GameWidth::Get() - width) >> 1;
		if (y == -1)
			yDlg = (H3GameHeight::Get() - height) >> 1;

		if (makeBackground)
			AddBackground(TRUE, statusBar, colorIndex);
		if (statusBar)
			hintBar = CreateHint();
	}
	_H3API_ H3Dlg::~H3Dlg()
	{
		THISCALL_1(VOID, 0x5FFAD0, this); // destroy all dlg items
		if (background)
			this->background->Destroy(); // destroy background		
		vDestroy();
		STDCALL_0(VOID, 0x597B50); // resume video animation
	}
	_H3API_ VOID H3Dlg::PlaceAtMouse()
	{
		H3POINT p = H3POINT::GetCursorPosition();
		// adjust to make certain the dialog will fit
		xDlg = Clamp(0, p.x, H3GameWidth::Get() - widthDlg - 200);  // 200 is width of adventure bar on right
		yDlg = Clamp(0, p.y, H3GameHeight::Get() - heightDlg - 48); // 48 is height of resource bar on bottom
	}
	_H3API_ VOID H3Dlg::Start()
	{
		if (!OnCreate())
			return;

		H3MouseManager* mmgr   = H3MouseManager::Get();
		const INT32 mouseType  = mmgr->GetType();
		const INT32 mouseFrame = mmgr->GetFrame();
		mmgr->DefaultCursor();
		vShowAndRun(FALSE);
		mmgr->SetCursor(mouseFrame, mouseType); // restore previous cursor
	}
	_H3API_ VOID H3Dlg::Stop()
	{
		endDialog = TRUE;
	}
	_H3API_ VOID H3Dlg::RMB_Show()
	{
		THISCALL_1(VOID, 0x5F4B90, this);
	}
	_H3API_ BOOL H3Dlg::AddBackground(INT32 x, INT32 y, INT32 w, INT32 h, BOOL frame, BOOL statusBar, INT32 colorIndex, BOOL is_blue)
	{
		if (this->background)
			return FALSE;

		if (frame && (w < 64 || h < 64))
			return FALSE;

		H3LoadedPcx16* pcx = H3LoadedPcx16::Create(h3_NullString, widthDlg, heightDlg);
		if (!pcx)
			return FALSE;

		// * the actual dialog background
		// * made with no pcx name as we want to insert our own
		// * otherwise h3 tries to load the named pcx
		H3DlgPcx16* bg = H3DlgPcx16::Create(x, y, w, h, 0, nullptr);
		if (!bg)
		{
			pcx->Destroy();
			return FALSE;
		}

		// * stored for further use
		this->background = pcx;

		BackgroundRegion(x, y, w, h, is_blue);
		if (frame)
			FrameRegion(x, y, w, h, statusBar, colorIndex, is_blue);

		bg->SetPcx(pcx);
		AddItem(bg);
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(BOOL frame, BOOL statusBar, INT32 colorIndex)
	{
		return AddBackground(0, 0, widthDlg, heightDlg, frame, statusBar, colorIndex);
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedPcx* pcx)
	{
		if (!pcx || background)
			return FALSE;
		background = H3LoadedPcx16::Create(h3_NullString, pcx->width, pcx->height);
		if (!background)
			return FALSE;

		pcx->DrawToPcx16(0, 0, pcx->width, pcx->height, background, 0, 0, FALSE);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, pcx->width, pcx->height, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedPcx16* pcx)
	{
		if (!pcx || background)
			return FALSE;
		background = H3LoadedPcx16::Create(h3_NullString, pcx->width, pcx->height);
		if (!background)
			return FALSE;

		pcx->DrawToPcx16(0, 0, FALSE, background);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, pcx->width, pcx->height, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedPcx24* pcx)
	{
		if (!pcx || background)
			return FALSE;

		background = H3LoadedPcx16::Create(h3_NullString, pcx->width, pcx->height);
		if (!background)
			return FALSE;

		pcx->DrawToPcx16(0, 0, background);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, pcx->width, pcx->height, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::AddBackground(H3LoadedDef* def, INT group, INT frame)
	{
		if (background || !def || def->groupsCount < group || !def->activeGroups[group])
			return FALSE;
		H3LoadedDef::DefGroup* grp = def->groups[group];
		if (grp->count < frame)
			return FALSE;

		H3DefFrame* fr = grp->frames[frame];

		background = H3LoadedPcx16::Create(h3_NullString, fr->frameWidth, fr->frameHeight);
		if (!background)
			return FALSE;

		fr->DrawToPcx16(0, 0, fr->frameWidth, fr->frameHeight, background, 0, 0, def->palette565);

		H3DlgPcx16* bg = H3DlgPcx16::Create(0, 0, fr->frameWidth, fr->frameHeight, 0, nullptr);
		if (!bg)
		{
			background->Destroy();
			background = nullptr;
			return FALSE;
		}
		bg->SetPcx(background);
		AddItem(bg);

		return TRUE;
	}
	_H3API_ BOOL H3Dlg::Notify(H3DlgItem* it, H3Msg& msg)
	{
		return OnNotify(it, msg);
	}
	_H3API_ VOID H3Dlg::EnableDoubleClick(BOOL state)
	{
		enableDoubleClick = state;
	}
	_H3API_ H3Dlg* H3Dlg::vDestroy()
	{
		THISCALL_1(VOID, 0x41B080, this);
		return this;
	}
	_H3API_ INT H3Dlg::vShow(INT zorder, BOOL8 draw)
	{
		return THISCALL_3(INT, 0x5FF0A0, this, zorder, draw);
	}
	_H3API_ INT H3Dlg::vHide(BOOL8 redrawScreen)
	{
		return THISCALL_2(INT, 0x5FF220, this, redrawScreen);
	}
	_H3API_ INT H3Dlg::vPreProcess(H3Msg& msg)
	{
		return vDialogProc(msg);
	}
	_H3API_ VOID H3Dlg::vParentActivate_10(H3DlgItem* unknown)
	{
	}
	_H3API_ BOOL8 H3Dlg::vRedraw(BOOL8 redrawScreen, INT32 minItemId, INT32 maxItemId)
	{
		return THISCALL_4(BOOL8, 0x5FF5E0, this, redrawScreen, minItemId, maxItemId);
	}
	_H3API_ INT H3Dlg::vShowAndRun(BOOL8 fadeIn)
	{
		return THISCALL_2(INT, 0x5FFA20, this, fadeIn);
	}
	_H3API_ INT H3Dlg::vInitiateItems()
	{
		return THISCALL_1(INT, 0x5FFB30, this);
	}
	_H3API_ INT H3Dlg::vActivateItems(BOOL8 increase)
	{
		return THISCALL_2(INT, 0x5FFBB0, this, increase);
	}
	_H3API_ BOOL8 H3Dlg::vOnMouseMove(INT32 x, INT32 y)
	{
		return THISCALL_3(BOOL8, 0x5FFCA0, this, x, y);
	}
	_H3API_ BOOL8 H3Dlg::vOnRightClick(INT32 id)
	{
		return THISCALL_2(BOOL8, 0x5FFD50, this, id);
	}
	_H3API_ BOOL8 H3Dlg::vOnLeftClick(INT32 id, BOOL8& closeDialog)
	{
		closeDialog = FALSE;
		return FALSE; // same as original function 0x5FFE90
	}
	_H3API_ H3DlgTextPcx* H3Dlg::vGetStatusBar()
	{
		return nullptr; // same as original 0x4842C0
	}
	_H3API_ INT H3Dlg::vEndDialogOnTimeExpired(H3Msg& msg)
	{
		return THISCALL_2(INT, 0x41B0F0, this, &msg);
	}
	_H3API_ H3LoadedPcx16* H3Dlg::GetBackgroundPcx() const
	{
		return background;
	}
	_H3API_ BOOL H3Dlg::BackgroundRegion(INT32 xStart, INT32 yStart, INT32 w, INT32 h, BOOL is_blue)
	{
		if (!background || w <= 0 || h <= 0)
			return FALSE;
		return background->BackgroundRegion(xStart, yStart, w, h, is_blue);
	}
	_H3API_ BOOL H3Dlg::SimpleFrameRegion(INT32 xStart, INT32 yStart, INT32 _width, INT32 _height, H3LoadedPcx16* destination)
	{
		H3LoadedPcx16* target = destination ? destination : background;
		if (!target)
			return FALSE;
		return target->SimpleFrameRegion(xStart, yStart, _width, _height);
	}
	_H3API_ BOOL H3Dlg::FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar, INT32 colorIndex, BOOL is_blue)
	{
		if (!background)
			return FALSE;
		if (w < 64 || h < 64)
			return FALSE;
		return background->FrameRegion(x, y, w, h, statusBar, colorIndex, is_blue);
	}
	_H3API_ H3DlgHintBar* H3Dlg::GetHintBar()
	{
		return hintBar;
	}
	_H3API_ BOOL H3Dlg::CreateBlackBox(INT32 x, INT32 y, INT32 width, INT32 height)
	{
		if (!background)
			return FALSE;

		background->FillRectangle(x, y, width, height, 0, 0, 0);
		return TRUE;
	}
	_H3API_ H3DlgHintBar* H3Dlg::CreateHint()
	{
		H3DlgHintBar* h = H3DlgHintBar::Create(this);
		if (h)
			AddItem(h);
		return h;
	}
	_H3API_ H3DlgHintBar* H3Dlg::CreateHint(INT32 x, INT32 y, INT32 width, INT32 height)
	{
		H3DlgHintBar* h = H3DlgHintBar::Create(this, x, y, width, height);
		if (h)
			AddItem(h);
		return h;
	}
	_H3API_ INT H3Dlg::vDialogProc(H3Msg& msg)
	{
		H3DlgItem* it = nullptr;

		switch (msg.command)
		{
		case eMsgCommand::KEY_UP:
			if (OnKeyPress(msg.GetKey(), msg.GetFlag()))
				break;
			return CheckEnd(msg);
		case eMsgCommand::MOUSE_OVER:
			if (!OnMouseHover(msg.GetX(), msg.GetY()))
				return CheckEnd(msg);
			it = ItemAtPosition(msg);
			if (!it)
				break;

			if (hintBar && it->GetHint())
				hintBar->ShowMessage(it->GetHint());

			if (OnMouseHover(it))
				break;
			return CheckEnd(msg);
		case eMsgCommand::LCLICK_OUTSIDE:
			if (OnLeftClickOutside())
				break;
			return CheckEnd(msg);
		case eMsgCommand::RCLICK_OUTSIDE:
			if (OnRightClickOutside())
				break;
			return CheckEnd(msg);
		case eMsgCommand::KEY_HELD:
			if (OnKeyHeld(msg.GetKey(), msg.GetFlag()))
				break;
			return CheckEnd(msg);
		case eMsgCommand::MOUSE_BUTTON:
			switch (msg.subtype)
			{
			case eMsgSubtype::END_DIALOG:
				switch (msg.itemId)
				{
				case eControlId::OK:
					OnOK();
					break;
				case eControlId::CANCEL:
					OnCancel();
					break;
				default:
					OnClose(msg.itemId);
					break;
				}
				break;
			case eMsgSubtype::LBUTTON_CLICK:
			{
				it = ItemAtPosition(msg);
				if (enableDoubleClick)
				{
					DWORD curr_time = GetTime();
					if (it == lastClickedItem && (curr_time - lastClickTime < DOUBLE_CLICK_SPEED))
					{
						lastClickTime = curr_time;
						lastClickedItem = it;
						if (OnDoubleClick(msg.itemId, msg))
							break;
						return CheckEnd(msg);
					}
					lastClickTime = curr_time;
					lastClickedItem = it;
				}

				if (OnLeftClick(msg.itemId, msg))
					break;
				return CheckEnd(msg);
			}
			case eMsgSubtype::RBUTTON_DOWN:
				it = ItemAtPosition(msg);
				if (!it)
					break;
				if (OnRightClick(it))
					break;
				return CheckEnd(msg);
			default:
				break;
			}
			break;
		case eMsgCommand::MOUSE_WHEEL:
			if (OnMouseWheel(msg.subtype))
				break;
			return CheckEnd(msg);
		case eMsgCommand::WHEEL_BUTTON:
			if (msg.subtype == eMsgSubtype::MOUSE_WHEEL_BUTTON_DOWN)
			{
				it = ItemAtPosition(msg);
				if (!it)
					break;
				if (OnWheelButton(it))
					break;
				return CheckEnd(msg);
			}
			break;
		default:
			break;
		}

		if (endDialog)
			return msg.CloseDialog();

		if (DialogProc(msg))
			return DefaultProc(msg);

		return CheckEnd(msg);
	}
	_H3API_ VOID H3Dlg::OnOK()
	{
	}
	_H3API_ VOID H3Dlg::OnCancel()
	{
	}
	_H3API_ VOID H3Dlg::OnClose(INT itemId)
	{
	}
	_H3API_ BOOL H3Dlg::OnNotify(H3DlgItem* it, H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::DialogProc(H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnLeftClick(INT itemId, H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnLeftClickOutside()
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnRightClick(H3DlgItem* it)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnRightClickOutside()
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnMouseWheel(INT direction)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnWheelButton(H3DlgItem* it)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnMouseHover(INT32 x, INT32 y)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnMouseHover(H3DlgItem* it)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnKeyPress(eVKey key, eMsgFlag flag)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnKeyHeld(eVKey key, eMsgFlag flag)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnDoubleClick(INT itemId, H3Msg& msg)
	{
		return TRUE;
	}
	_H3API_ BOOL H3Dlg::OnCreate()
	{
		return TRUE;
	}
} /* namespace h3 */
