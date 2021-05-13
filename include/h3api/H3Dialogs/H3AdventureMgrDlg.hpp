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
#include "h3api/H3Dialogs/H3BaseDialog.hpp"

namespace h3
{
	_H3API_DECLARE_(AdventureMgrDlg);
	struct H3ResourceBarPanel;
	struct H3DlgBasePanel;

#pragma pack(push, 4)

	struct H3AdventureMgrDlg : H3BaseDlg
	{
		_H3API_SIZE_(0xA0);
		_H3API_VTABLE_(0x63A5E4);

		/** @brief [4C]*/
		H3DlgTransparentItem* minimapTransparentOverlay;
		/** @brief [50]*/
		H3DlgTransparentItem* mapTransparentOverlay;
		/** @brief [54]*/
		H3DlgText*            text;
		/** @brief [58]*/
		H3ScreenlogEdit*      screenlogEdit;
		/** @brief [5C]*/
		H3ResourceBarPanel*   resourceBar;
		/** @brief [60] also the location for the edit control*/
		H3DlgTextPcx*         hintbar;
		/** @brief [64]*/
		INT32                 topHeroSlotIndex;
		/** @brief [68]*/
		h3unk32               _f_68;
		/** @brief [6C]*/
		h3unk8                _f_6C;
		/** @brief [70]*/
		H3DlgPcx*             heroPcx[5];
		/** @brief [84] maybe towns?*/
		H3DlgPcx*             heroPcx2[5];
		/** @brief [98] hero or town panel in bottom right*/
		H3DlgBasePanel*       panel;
		/** @brief [9C]*/
		h3unk32               _f_9C;
	};
	_H3API_ASSERT_SIZE_(H3AdventureMgrDlg);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
