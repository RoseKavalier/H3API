//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-04              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"
#include "h3api/H3Dialogs/H3NetworkDialog.hpp"

namespace h3
{
	_H3API_DECLARE_(OracleDlg);
	struct H3ResourceBarPanel;
	struct H3LoadedPcx;

#pragma pack(push, 4)

	struct H3OracleDlg : H3NetworkDlg
	{
		_H3API_SIZE_(0x12C);
		_H3API_VTABLE_(0x640610);
		_H3API_CTOR_DTOR_(0x52C6C0, 0x52CA80);

		h3unk32 _f_60;
		/** @brief [64]*/
		H3ResourceBarPanel* resourcesBar;
		/** @brief [68]*/
		H3LoadedPcx* puzzlePieces[48];
		/** @brief [128]*/
		INT32 townType;
	};
	_H3API_ASSERT_SIZE_(H3OracleDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
