//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Managers/H3WindowManager.hpp"

namespace h3
{
	_H3API_ VOID H3WindowManager::H3Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy)
	{
		THISCALL_5(VOID, 0x603190, this, x, y, dx, dy);
	}
	_H3API_ INT32 H3WindowManager::ClickedItemID() const
	{
		return resultItemID;
	}
	_H3API_ VOID H3WindowManager::SetClickedItemId(INT32 id)
	{
		resultItemID = id;
	}
	_H3API_ BOOL H3WindowManager::ClickedOK() const
	{
		return resultItemID == eControlId::OK;
	}
	_H3API_ BOOL H3WindowManager::ClickedCancel() const
	{
		return resultItemID == eControlId::CANCEL;
	}
	_H3API_ H3LoadedPcx16* H3WindowManager::GetDrawBuffer()
	{
		return screenPcx16;
	}
} /* namespace h3 */
