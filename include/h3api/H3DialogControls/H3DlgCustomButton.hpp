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
#include "h3api/H3DialogControls/H3DlgDefButton.hpp"

namespace h3
{
	_H3API_DECLARE_(DlgCustomButton);
	typedef INT32(__fastcall* H3DlgButton_proc)(H3Msg*);
	typedef INT32(__fastcall* H3DlgButtonProc)(H3Msg&);

#pragma pack(push, 4)

	struct H3DlgCustomButton : public H3DlgDefButton
	{
		_H3API_SIZE_(0x6C);
		_H3API_VTABLE_(0x63BBBC);
	protected:
		H3DlgButton_proc customButtonProc; /**< @brief [68]*/
	public:

		_H3API_ static H3DlgCustomButton* Create(INT32 x, INT32 y, INT32 width, INT32 height,
			INT32 id, LPCSTR defName, H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ static H3DlgCustomButton* Create(INT32 x, INT32 y, INT32 id, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ static H3DlgCustomButton* Create(INT32 x, INT32 y, LPCSTR defName,
			H3DlgButton_proc customProc, INT32 frame, INT32 clickFrame);
		_H3API_ VOID ToggleMsgFlag(BOOL& flag);
	};
	_H3API_ASSERT_SIZE_(H3DlgCustomButton);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
