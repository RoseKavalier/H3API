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
#include "h3api/H3Dialogs/H3NetworkDialog.hpp"

namespace h3
{

#pragma pack(push, 4)

	/**
	 * @brief follows HDmod's dlg format
	 * WARNING! this structure should only be used to hook existing dialogs
	 */
	struct HDDlg : H3NetworkDlg
	{
		_H3API_SIZE_(0x74);

		typedef INT32(__stdcall* HDDlg_proc)(HDDlg*, const H3Msg&);
	protected:
		h3unk _f_60[0x10];
		/** @brief [70]*/
		HDDlg_proc hdProc;
	public:
		_H3API_ INT CallHDProc(const H3Msg& msg);
	};
	_H3API_ASSERT_SIZE_(HDDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
