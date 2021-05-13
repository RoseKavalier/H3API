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
#include "h3api/H3Dialogs/H3DialogPanel.hpp"

namespace h3
{
	_H3API_DECLARE_(ResourceBarPanel);
	struct H3DlgText;
	struct H3DlgPcx;

#pragma pack(push, 4)

	/** @brief Used to show player's resources at bottom of screen in various dialogs*/
	struct H3ResourceBarPanel : H3DlgBasePanel
	{
		_H3API_SIZE_(0x78);
		_H3API_VTABLE_(0x641034);
		_H3API_CTOR_DTOR_(0x558DF0, -1);
		/** @brief [34]*/
		BOOL8      useKRESBAR;
		/** @brief [38]*/
		H3DlgText* resourceText[7];
		/** @brief [54]*/
		H3DlgItem* resourceOverlay[7];
		/** @brief [70]*/
		H3DlgPcx*  resbarPCX;
		/** @brief [74]*/
		H3DlgText* currentDayText;
	};
	_H3API_ASSERT_SIZE_(H3ResourceBarPanel);

#pragma pack(pop) /* align-4 */

} /* namespace h3 */
