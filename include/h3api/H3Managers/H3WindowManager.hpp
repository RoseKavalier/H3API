//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-31              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Managers/H3BaseManager.hpp"
#include "h3api/H3Constants/H3CstMessages.hpp"

namespace h3
{
	_H3API_DECLARE_(WindowManager);
	struct H3LoadedPcx16;
	struct H3BaseDlg;

#pragma pack(push, 4)

	// * named heroWindowManager in H3, abbreviated
	// * in charge of drawing and dialogs
	struct H3WindowManager : public H3Manager
	{
		_H3API_SIZE_(0x60);
		_H3API_VTABLE_(0x643D5C);
		_H3API_GET_INFO_(0x6992D0, H3WindowManager);

		/** @brief [38] clicked item*/
		INT32 resultItemID;
		/** @brief [3C] last item with mouse over event*/
		INT32 mouseoverItemId;
		/** @brief [40] main drawing surface*/
		H3LoadedPcx16* screenPcx16;
	protected:
		h3unk32 _f_44;
		/** @brief [48] */
		BOOL8 mouseTurnedOff;
	public:
		/** @brief [4C]*/
		H3LoadedPcx16* backupScreen;
		/** @brief [50]*/
		H3BaseDlg* firstDlg;
		/** @brief [54]*/
		H3BaseDlg* lastDlg;
	protected:
		h3unk32 _f_58;
		h3unk32 _f_5C;
	public:
		VOID H3Redraw(INT32 x, INT32 y, INT32 dx, INT32 dy);
		INT32 ClickedItemID() const;
		VOID SetClickedItemId(INT32 id);
		BOOL ClickedOK() const;
		BOOL ClickedCancel() const;
		H3LoadedPcx16* GetDrawBuffer();
	};
	_H3API_ASSERT_SIZE_(H3WindowManager);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
