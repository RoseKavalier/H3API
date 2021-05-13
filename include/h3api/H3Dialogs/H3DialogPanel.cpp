//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-25              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Dialogs/H3DialogPanel.hpp"
#include "h3api/H3Dialogs/H3BaseDialog.hpp"
#include "h3api/H3Containers/H3Vector.hpp"
#include "h3api/H3Managers/H3WindowManager.hpp"
#include "h3api/H3DialogControls/H3DlgItem.hpp"

namespace h3
{
	_H3API_ VOID H3DlgBasePanel::backupScreen()
	{
		THISCALL_1(VOID, 0x5AA870, this);
	}
	_H3API_ VOID H3DlgBasePanel::restoreBackupScreen()
	{
		THISCALL_1(VOID, 0x5AA920, this);
	}

	_H3API_ H3Vector<H3DlgItem*>& H3DlgBasePanel::GetItems()
	{
		return items;
	}
	_H3API_ H3DlgItem* H3DlgBasePanel::AddItem(H3DlgItem* item)
	{
		// H3DlgBasePanel items are hidden by default
		// use Show() when needed.
		item->HideDeactivate();
		items += item;
		return THISCALL_3(H3DlgItem*, 0x5AA7B0, this, item, -1);
	}
	_H3API_ VOID H3DlgBasePanel::Redraw()
	{
		for (H3DlgItem** i = items.begin(); i != items.end(); ++i)
		{
			H3DlgItem* it = *i;
			if (it->IsVisible())
				it->Draw();
		}
		H3WindowManager::Get()->H3Redraw(x + parent->GetX(), y + parent->GetY(), width, height);
	}
	_H3API_ VOID H3DlgBasePanel::Hide()
	{
		for (H3DlgItem** it = items.begin(); it != items.end(); ++it)
			(*it)->HideDeactivate();
		restoreBackupScreen();
	}
	_H3API_ VOID H3DlgBasePanel::Show()
	{
		// if backup pcx exists, panel is already shown
		if (backupPcx)
			return;
		backupScreen();
		for (H3DlgItem** it = items.begin(); it != items.end(); ++it)
			(*it)->ShowActivate();
		Redraw();
	}
	_H3API_ VOID H3DlgBasePanel::Move(INT xDest, INT yDest)
	{
		if (items.IsEmpty())
			return;

		const BOOL shown = backupPcx != nullptr;
		if (shown)
			Hide();

		const int dx = xDest - x;
		const int dy = yDest - y;
		x = xDest;
		y = yDest;

		for (H3DlgItem** i = items.begin(); i != items.end(); ++i)
		{
			H3DlgItem* it = *i;
			it->SetX(it->GetX() + dx);
			it->SetY(it->GetY() + dy);
		}

		if (shown)
			Show();
	}
	_H3API_ VOID H3DlgBasePanel::MoveRelative(INT xDest, INT yDest)
	{
		xDest -= parent->GetX();
		yDest -= parent->GetY();
		Move(xDest, yDest);
	}
	_H3API_ INT32 H3DlgBasePanel::GetWidth() const
	{
		return width;
	}
	_H3API_ INT32 H3DlgBasePanel::GetHeight() const
	{
		return height;
	}
	_H3API_ INT32 H3DlgBasePanel::GetX() const
	{
		return x;
	}
	_H3API_ INT32 H3DlgBasePanel::GetY() const
	{
		return y;
	}
} /* namespace h3 */
